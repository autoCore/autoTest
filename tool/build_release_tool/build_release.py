#!usr/bin/env python

import sys,os,datetime,copy,time,re
import multiprocessing as mp
import shutil
import fileinput
import traceback
import subprocess
import git
from util import *
from git_push_cp import *
from release_zip import *
from send_email import *
from ftp import ftp_upload_file
from TriggerTest import trigger_test

reload(sys)
sys.setdefaultencoding( "utf-8" )

manifest_xml = \
"""
<?xml version="1.0" encoding="UTF-8"?>
<manifest>
  <remote fetch=".." name="origin" review="https://source.asrmicro.com/"/>
  
  <default remote="origin" revision="master" sync-j="4"/>
  <project name="crane/crane-dev" path="crane" revision="%s" upstream="master"/>
  <project name="crane/cp" path="crane/cp" revision="%s" upstream="master"/>
  <project name="crane/gui" path="crane/gui" revision="%s" upstream="master"/>
  <project name="crane/tool" path="crane/tool" revision="%s" upstream="master"/>
</manifest>
"""

email_subject = "CRANE PHONE: AUTO RELEASE %s"
email_msg = r"""
GUI VERSION: %s
CP VERSION: %s
DSP VERSION: %s

NORMAL VERSION(SINGLE and DUAL SIM):
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\%s\crane_evb_z2
hal lib: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\%s\crane_evb_z2\rel_lib
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\download_tool\crane_evb_z2

BIRD PHONE VERSION:
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\%s\bird_phone
hal lib: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\%s\bird_phone\rel_lib
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\download_tool\bird_phone

"""
email_msg_with_cus = r"""
GUI VERSION: %s
CP VERSION: %s
DSP VERSION: %s

NORMAL VERSION(SINGLE and DUAL SIM):
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\%s\crane_evb_z2
hal lib: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\%s\crane_evb_z2\rel_lib
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\download_tool\crane_evb_z2

BIRD PHONE VERSION:
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\%s\bird_phone
hal lib: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\%s\bird_phone\rel_lib
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\download_tool\bird_phone

CUSTOMER RELEASE:
release version: %s
"""

class buildController(object):
    def __init__(self,cfg):
        self.build_res = None
        self.cfg = cfg
        self.version_file = None

        self.gui_build_log = os.path.join(".",'build','crane_evb_z2',r'gui_build.log')
        self.hal_build_log = os.path.join(".",'build','crane_evb_z2',r'hal_build.log')
        self.cp_build_log = os.path.join(".",'build','crane_evb_z2',r'cp_build.log')
        self.link_log = os.path.join(".",'build','crane_evb_z2',r'fp_link_build.log')
        self.compile_log = "compile.log"

    def build(self,curdir, build_dir = 'crane_evb_z2',compile_log = '',cmd = ''):
        os.chdir(curdir)
        logger.info("%s build start..."%curdir)
        # cmd = "autobuild.bat %s> %s"%(build_dir,compile_log)
        if not cmd:
            cmd = "autobuild.bat"
        if compile_log:
            self.compile_log = os.path.join(self.cfg.compile_log_dir,compile_log)
        else:
            self.compile_log = os.path.join(self.cfg.compile_log_dir,os.path.basename(self.version_file)+".log")
        if not os.path.exists(self.compile_log):
            fobj = open(self.compile_log,'w')
            fobj.close()
        try:
            with open(self.compile_log,'a') as fobj:
                proc = subprocess.Popen(cmd, shell = True,stdout = fobj)
                ret = proc.wait()
        except Exception,e:
            logger.error(e)
            self.build_res = "FAIL"
            return
        time.sleep(5)
        if os.path.exists(r"%s\build\%s\crane_evb.elf"%(curdir,build_dir)):
            logger.info("%s build done"%curdir)
            self.build_res = "SUCCESS"
        else:
            logger.warning("%s build fail"%curdir)
            self.build_res = "FAIL"

    def send_email(self, curdir, owner, external_dir, borad = "crane_evb_z2"):
        os.chdir(curdir)
        if self.build_res in "FAIL":
            att_file = '@'.join([self.hal_build_log,self.gui_build_log,self.cp_build_log,self.link_log,self.compile_log])
            subject = r"%s build result: fail"%borad
            msg = r"Hi %s, your patch build fail! Pls check attachment log"%(owner.split("@")[0])
        else:
            att_file = None
            subject = r"%s build result: pass"%borad
            msg = r"Hi %s, your patch build pass! Binary dir: %s"%(owner.split("@")[0],external_dir)
        send_email_tool(owner, subject, msg, att_file)
        logger.info("send email done")

    def copy(self, src, dist):
        assert os.path.exists(src),"%s not exists"%src
        if os.path.isfile(src):
            shutil.copy2(src,dist)
        elif os.path.isdir(src):
            shutil.copytree(src,dist)
        logger.info("copy done.")

    def copy_file(self, src, dist,massage_file = None,manifest_xml_file = None):
        if massage_file:
            file_name = os.path.basename(massage_file)
            shutil.copy2(massage_file,os.path.join("build","crane_evb_z2",file_name))
        if manifest_xml_file:
            xml_file = os.path.basename(manifest_xml_file)
            shutil.copy2(manifest_xml_file,os.path.join("build","crane_evb_z2",xml_file))
        # shutil.copytree(src,dist)
        logger.info("%s copy build done"%src)


class myRepo(object):
    def __init__(self, version_log, root_path = '',storage_list = ['','cp','gui','tool']):
        self.root_path = root_path
        self._storage_list = storage_list
        self.CUR_DATE = 0
        self.version_log = version_log
        self.menifest_xml = ''
        self.cp_version = None
        self.dsp_version = None

    def clone(self,clone_path):
        for storage in self._storage_list:
            _path = os.path.join(self.root_path, storage)
            _repo = git.Repo(_path)
            _path = os.path.join(clone_path, storage)
            _repo.clone(_path)

    def sync(self):
        ret = None
        self.git_clean()
        for storage in self._storage_list:
            _path = os.path.join(self.root_path, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            _git.config("--global","core.autocrlf","false")
            try:
                info = _git.pull()
                if not storage:
                    storage = 'hal'
                logger.debug("%-4s %s"%(storage,info))
                if "Already up to date." not in info:
                    ret = 1
            except Exception,e:
                logger.error(e)
                ret = None
        return ret

    def git_clean(self):
        for storage in self._storage_list:
            _path = os.path.join(self.root_path, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            try:
                _git.clean("-xdf")
                _git.reset("--hard","HEAD")
            except Exception,e:
                logger.error(e)


    def get_revion_owner(self):
        info_list = []
        for storage in self._storage_list:
            _path = os.path.join(self.root_path, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            info = _git.log("-1","--date=raw",'--pretty=format:"<%H> <%ae> <%cd> <%s>"')
            info = info.replace('\n','')
            text_list = re.findall(r'<(.*?)> <(.*?)> <([0-9]+).*?> <(.*?)>',info)[0]
            logger.debug(storage,text_list)
            info_list.append(text_list)
        # CUR_DATE_bak = self.CUR_DATE
        for index, text_list in enumerate(info_list):
            logger.debug(text_list)
            commit_id, Author_email,date, commit_info = text_list
            if int(date) >= self.CUR_DATE:
                self.CUR_DATE = int(date)
        # if CUR_DATE_bak == self.CUR_DATE:
            # return None
        for index, text_list in enumerate(info_list):
            commit_id, Author_email, date, commit_info= text_list
            if self.CUR_DATE == int(date):
                return commit_id, Author_email,date, commit_info

    def get_commit_massages(self,delta_time = 7):
        now = datetime.datetime.today()
        offset = datetime.timedelta(days = delta_time)
        date = (now - offset).strftime("%Y-%m-%d")
        massage_file = "release_notes.txt"
        massage_file = os.path.join(self.root_path,massage_file)
        info_list = []
        for storage in self._storage_list:
            if storage is 'tool':
                continue
            _path = os.path.join(self.root_path, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            info = _git.log("--after=%s"%date,"--pretty=format:commit ID: %H\nAuthor: %an <%ae>\nDate:  %cd\ncommit msg: %s\n\
------------------------------------------------------------")
            info_list.append("*"*50)
            if not storage:
                storage = 'hal'
            header = "%s commit info"%storage 
            info_list.append(header)
            info_list.append("*"*50)
            info_list.append(info)
        with open(massage_file,'w') as obj:
            obj.write('\n'.join(info_list))
        return massage_file

    def get_revion_info(self):
        info_list = []
        for storage in self._storage_list:
            _path = os.path.join(self.root_path, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            info = _git.log("-1","--pretty=format:commit: %H\nAuthor: %cn <%ce>\nDate:  %cd\n------------------------------------------------")
            info_list.append(info)
        return "\n".join(info_list)

    def get_manifest_xml(self,xml_file):
        info_list = []
        for storage in self._storage_list:
            _path = os.path.join(self.root_path, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            info = _git.log("-1","--pretty=format:%H")
            logger.debug(storage,info)
            info_list.append(info)
        manifest_text = manifest_xml%tuple(info_list)
        logger.debug(manifest_text)
        _obj = open(xml_file,'w')
        _obj.write(manifest_text.lstrip())
        _obj.close()

    def get_nearest_version(self):
        flog = open(self.version_log)
        text = flog.read()
        text = text.replace('\n','')
        text_list = re.findall(r'crane_git_r([0-9]+)',text)
        logger.debug(text_list)
        if text_list:
            cnt = int(text_list[-1])
        else:
            cnt = 0
        return "crane_git_r%d"%(cnt+1)

    def record_version(self,version = '',info = ''):
        flog = open(self.version_log,'a')
        if not version:
            version = self.get_nearest_version()
        if not info:
            info = self.get_revion_info()
        text = "\n".join([version+":",info])
        flog.write(text+"\n\n")
        flog.flush()
        flog.close()
        return version

    def get_cp_version(self,cp_version_file):
        '''#define CRANE_CUST_VER_INFO 
        "["##SYSTEM_VERSION##"]
        ["##DISTRIBUTION_VERSION##"]
        ["##SYSTEM_TARGET_OS##"]
        ["##SYSTEM_PS_MODE##"]
        ["##APPEND_REVERSION##"]"'''
        assert os.path.exists(cp_version_file),"%s not exists"%cp_version_file
        SYSTEM_CUST_SKU = "MINIGUI"
        SYSTEM_SKU_REVERSION = "SDK"
        SYSTEM_PS_MODE = "LTEGSM"
        SYSTEM_TARGET_OS = "TX"
        APPEND_REVERSION = "_".join([SYSTEM_CUST_SKU,SYSTEM_SKU_REVERSION])
        file_obj = open(cp_version_file)
        for _line in file_obj:
            format = '#define[ ]+SYSTEM_VERSION[ ]+"(.*?)"'
            match = re.findall(format,_line)
            if match:
                SYSTEM_VERSION = match[0]
            format = '#define[ ]+DISTRIBUTION_VERSION[ ]+"(.*?)"'
            match = re.findall(format,_line)
            if match:
                DISTRIBUTION_VERSION = match[0]
        CRANE_CUST_VER_INFO = "[%s][%s][%s][%s][%s]"%(SYSTEM_VERSION,\
        DISTRIBUTION_VERSION,SYSTEM_TARGET_OS,SYSTEM_PS_MODE,APPEND_REVERSION)
        logger.debug(CRANE_CUST_VER_INFO)
        self.cp_version = CRANE_CUST_VER_INFO
        return CRANE_CUST_VER_INFO

    def update_cp_version(self):
        self.cp_version = self.get_cp_version(os.path.join(cfg.cur_crane,cfg.cp_version_file))
        with open(cfg.cp_version_log,"w") as obj:
            obj.write(self.cp_version)

    def get_old_cp_version(self):
        if not os.path.exists(cfg.cp_version_log):
            return None
        else:
            with open(cfg.cp_version_log) as obj:
                return obj.read()

    def record_cp_version(self):
        with open(cfg.cp_version_log,"w") as obj:
            obj.write(self.cp_version)

    def get_dsp_version(self):
        "!CRANE_CAT1GSM_L1_1.043.000 , Dec 13 2019 03:30:56"
        fobj = open(cfg.dsp_bin,"rb")
        text = fobj.read()
        # match = re.findall("!(CRANE_.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])",text)
        match = re.findall("(CRANE_.{43})",text)
        if match:
            version_info = match[0]
            if "\x00" in version_info:
                # logger.info(version_info.split(",")[-1])
                # version_info = version_info.replace("\x00","")
                version_info = version_info.split(",")[-1].strip()
            logger.debug(version_info)
            self.dsp_version = version_info
            with open(cfg.dsp_version_log,"w") as obj:
                obj.write(self.dsp_version)

def prepare_release_dir(version_file,release_version = False):
    os.mkdir(version_file)
    os.mkdir(os.path.join(version_file,"version_info"))
    if release_version:
        board_list = ["crane_evb_z2"]
        os.mkdir(os.path.join(version_file,"download_tool"))
    else:
        board_list = cfg.BOARD_LIST
    for board in board_list:
        os.mkdir(os.path.join(version_file, board))
        if not release_version:
            os.mkdir(os.path.join(version_file, board, "download_tool"))
        os.mkdir(os.path.join(version_file, board, "cp_images")) if not release_version else None


def copy_build_file_to_release_dir(dist_dir, src_dir = None):
    if not src_dir:
        src_dir = cfg.cur_crane
        BUILD_IMAGES = cfg.BUILD_IMAGES[:]
    else:
        BUILD_IMAGES = cfg.BUILD_IMAGES[1:]
    for _file in BUILD_IMAGES:
        src = os.path.join(src_dir,_file)
        dist = os.path.join(dist_dir, os.path.basename(_file))
        if os.path.exists(src):
            if os.path.isfile(src):
                shutil.copy2(src, dist)
            elif os.path.isdir(src):
                shutil.copytree(src, dist)
        else:
            logger.warning("%s file not exists"%src)

    if os.path.exists(cfg.mdb_file_dir):
        for _file in os.listdir(cfg.mdb_file_dir):
            if "MDB.TXT" in _file.upper():
                shutil.copy2(os.path.join(cfg.mdb_file_dir, _file),os.path.join(dist_dir, _file))
                break


def copy_cp_file_to_release_dir(dist_dir, board = "crane_evb_z2",src_dir = None):
    if not src_dir:
        src_dir = cfg.cur_crane
    src_bin_l = cfg.BOARD_CP_RELEASE_BIN_DICT.get(board,[])
    src_bin_l = [os.path.join(src_dir,_file) for _file in src_bin_l]
    dist_bin_l = [os.path.join(dist_dir,_file) for _file in cfg.IMAGES]
    for src_bin,dist_bin in zip(src_bin_l,dist_bin_l):
        if os.path.exists(src_bin):
            shutil.copy2(src_bin,dist_bin)
        else:
            logger.warning("%s not exists"%src_bin)

    if os.path.exists(cfg.mdb_file_dir):
        for _file in os.listdir(cfg.mdb_file_dir):
            if "MDB.TXT" in _file.upper():
                shutil.copy2(os.path.join(cfg.mdb_file_dir, _file),os.path.join(dist_dir, _file))
                break

def send_release_email(version_file, cp_version, dsp_version,customer_file = None):
    to_address = "GR-Modem-SV-Report@asrmicro.com,SW_QA@asrmicro.com,SW_Managers@asrmicro.com,SW_CV@asrmicro.com,crane_sw_mmi_group@asrmicro.com"
    version_fname = os.path.basename(version_file)
    subject = email_subject%version_fname.upper()
    _match = re.findall("crane_git_r[0-9]+",version_fname)
    assert _match,"file name can not match"
    version = _match[0]
    # msg = email_msg%((version.upper(),cp_version,dsp_version,str(time.asctime()))+(version_fname,)*6)
    if customer_file:
        # msg = email_msg_with_cus%((version.upper(), cp_version, dsp_version)+(version_fname,)*4+(customer_file,))
        msg = email_msg_with_cus%((version.upper(), cp_version, " ")+(version_fname,)*4+(customer_file,))
    else:
        # msg = email_msg%((version.upper(), cp_version, dsp_version)+(version_fname,)*4)
        msg = email_msg%((version.upper(), cp_version, " ")+(version_fname,)*4)
    logger.info(subject)
    logger.info(msg)
    send_email_tool(to_address,subject,msg)

def check_dsp_rf_rbd():
    dsp_release_bin_l = []
    release_dir_list = [os.path.join(cfg.dsp_release_bin,_dir) for _dir in os.listdir(cfg.dsp_release_bin)\
                            if os.path.isdir(os.path.join(cfg.dsp_release_bin,_dir))]
    release_dir_list.sort(key=lambda fn:os.path.getmtime(fn))
    # logger.debug(len(release_dir_list))
    # logger.debug(release_dir_list[-30:])
    for release_dir in release_dir_list[-30:]:
        # logger.debug(release_dir)
        for root, dirs, files in os.walk(release_dir, topdown=False):
            tgt_file = "crane_compress_a0.bin"
            if "crane_compress_a0.bin" in files:
                rf = os.path.join(root,"PM813","rf.bin")
                if os.path.exists(rf):
                    dsp_release_bin_l.append(os.path.join(root,tgt_file))
    dsp_release_bin_l.sort(key=lambda fn:os.path.getmtime(fn))
    # logger.debug("\n".join(dsp_release_bin_l))
    dsp_release_bin = dsp_release_bin_l[-1]
    logger.debug(dsp_release_bin)
    root_dir = os.path.dirname(dsp_release_bin)
    rf_release_bin = os.path.join(root_dir,"PM813","rf.bin")
    release_bin_l = [dsp_release_bin, rf_release_bin, cfg.rbd_release_bin]
    # release_bin_l = [self.cfg.dsp_release_bin,self.cfg.rf_release_bin,self.cfg.rbd_release_bin]
    local_bin_l = [cfg.dsp_bin,cfg.rf_bin,cfg.rbd_bin]
    for release_bin,local_bin in zip(release_bin_l,local_bin_l):
        if os.path.exists(release_bin):
            if os.path.exists(local_bin):
                os.remove(local_bin)
            shutil.copy2(release_bin,local_bin)

    # bird_phone rf.bin, rbd.bin
    release_bin_l = [cfg.bird_rbd_release_bin, cfg.bird_rf_release_bin,cfg.bird_logo_release_bin,cfg.bird_updater_release_bin]
    local_bin_l = [cfg.bird_rbd_bin, cfg.bird_rf_bin,cfg.bird_logo_bin,cfg.bird_updater_bin]
    for release_bin,local_bin in zip(release_bin_l,local_bin_l):
        if os.path.exists(release_bin):
            if os.path.exists(local_bin):
                os.remove(local_bin)
            shutil.copy2(release_bin,local_bin)


def auto_dailybuild():
    if not repo.sync():
        time.sleep(10)
        return None
    repo.update_cp_version()
    commit_id, owner,date, commit_info = repo.get_revion_owner()
    logger.info("="*50)
    logger.debug(commit_id, owner,date, commit_info,time.asctime(time.localtime(int(date))))
    _r = repo.record_version()
    date = time.strftime("%Y%m%d_%H%M%S")
    file_name = "%s_%s"%(_r,date)
    logger.info("version: "+file_name)
    dist = os.path.join(cfg.dist_dir,file_name)
    massage_file = repo.get_commit_massages()
    curdir = cfg.cur_crane
    xml_file = _r + ".xml"
    xml_file = os.path.join(cfg.manisest_xml_dir,xml_file)
    repo.get_manifest_xml(xml_file)

    version_file = os.path.join(os.path.dirname(cfg.cur_crane),file_name)
    build_controller.version_file = version_file
    prepare_release_dir(version_file)
    shutil.copy2(repo.version_log,os.path.join(version_file,"version_info",os.path.basename(repo.version_log)))
    shutil.copy2(xml_file,os.path.join(version_file,"version_info",os.path.basename(xml_file)))
    shutil.copy2(cfg.cp_version_log,os.path.join(version_file,"version_info",os.path.basename(cfg.cp_version_log)))
    shutil.copy2(cfg.dsp_version_log,os.path.join(version_file,"version_info",os.path.basename(cfg.dsp_version_log)))
    shutil.copy2(massage_file,os.path.join(version_file,"crane_evb_z2",os.path.basename(massage_file)))
    for board, build_cmd in zip(cfg.BOARD_LIST, cfg.BOARD_BUILD_CMD):
        repo.git_clean()
        build_controller.build(curdir, cmd = build_cmd)
        build_controller.send_email(curdir, owner,os.path.join(cfg.external_dir,file_name),board)

        copy_build_file_to_release_dir(os.path.join(version_file,board))
        copy_cp_file_to_release_dir(os.path.join(version_file,board,"cp_images"), board)

        if board in cfg.BOARD_LIST[0] and build_controller.build_res in "FAIL":
            return version_file
    build_controller.copy(version_file, dist)
    if PUSH_CP_DONE.is_set() and (cp_sdk_cls.cp_sdk_version and repo.cp_version in cp_sdk_cls.cp_sdk_version):
        RELEASE_EVENT.set()
        PUSH_CP_DONE.clear()
    return version_file


def find_newest_notes():
    root_dir = os.path.join(cfg.cur_crane_cus,"note")
    release_note_list = [_file for _file in os.listdir(root_dir) if _file.startswith("ReleaseNotes")]
    release_note_list.sort(key=lambda fn:os.path.getmtime(os.path.join(root_dir,fn)))
    if release_note_list:
        file_name = release_note_list[-1]
        logger.debug(file_name)
        return os.path.join(root_dir, file_name)
    else:
        return None


def auto_build_cus():
    if not repo_cus.sync():
        time.sleep(10)
        return None
    curdir = cfg.cur_crane_cus
    build_root_dir = os.path.join(curdir,"evb","src")
    repo_cus.get_cp_version(os.path.join(build_root_dir,cfg.cp_version_file))
    commit_id, owner,date, commit_info = repo_cus.get_revion_owner()
    logger.info("="*50)
    logger.debug(commit_id, owner,date, commit_info,time.asctime(time.localtime(int(date))))
    _r = repo_cus.record_version()
    date = time.strftime("%Y%m%d_%H%M%S")
    file_name = "crane_release_%s"%date
    logger.info("version: "+file_name)
    dist = os.path.join(cfg.release_dist_dir,file_name)
    massage_file = repo_cus.get_commit_massages()

    version_file = os.path.join(os.path.dirname(curdir),file_name)
    build_controller.version_file = version_file
    prepare_release_dir(version_file,True)
    release_note = find_newest_notes()
    if release_note:
        shutil.copy2(release_note,os.path.join(version_file,"crane_evb_z2",os.path.basename(release_note)))
    shutil.copy2(repo_cus.version_log,os.path.join(version_file,"version_info",os.path.basename(repo_cus.version_log)))
    # shutil.copy2(xml_file,os.path.join(version_file,"version_info",os.path.basename(xml_file)))
    # shutil.copy2(cfg.cp_version_log,os.path.join(version_file,"version_info",os.path.basename(cfg.cp_version_log)))
    shutil.copy2(massage_file,os.path.join(version_file,"crane_evb_z2",os.path.basename(massage_file)))


    for board, build_cmd in [("crane_evb_z2","autobuild.bat")]:
        repo_cus.git_clean()
        build_controller.build(build_root_dir, cmd = build_cmd)
        build_controller.send_email(build_root_dir, owner,os.path.join(cfg.release_dist_dir,file_name),board)

        copy_build_file_to_release_dir(os.path.join(version_file,board),build_root_dir)
        # copy_cp_file_to_release_dir(os.path.join(version_file,board,"cp_images"), board, build_root_dir)

        if board in cfg.BOARD_LIST[0] and build_controller.build_res in "FAIL":
            return version_file
    release_cus_download_tool(version_file)
    build_controller.copy(version_file, dist)
    # '''
    try:
        board = "crane_evb_z2"
        sdk_tool_abs_path = os.listdir(os.path.join(dist,"download_tool"))
        if sdk_tool_abs_path:
            sdk_tool_abs_path = os.path.join(dist,"download_tool",sdk_tool_abs_path[0])
        else:
            sdk_tool_abs_path = None
        mdb_txt_file_dir = os.path.join(dist,board)
        logger.info(mdb_txt_file_dir)
        for _file in os.listdir(mdb_txt_file_dir):
            if "MDB.TXT" in _file.upper():
                mdb_txt_file_abs_path = os.path.join(mdb_txt_file_dir,_file)
                break
        else:
            mdb_txt_file_abs_path = None
        logger.info(sdk_tool_abs_path,mdb_txt_file_abs_path,"evb_customer")
        trigger_test(sdk_tool_abs_path,mdb_txt_file_abs_path,"evb_customer")
    except Exception,e:
        logger.info(e)
    # '''
    return version_file

def release_cus_download_tool(version_file):
    download_tool_dir = os.path.join(cfg.cur_crane_cus,'evb','tool')
    download_tool_list = [_file for _file in os.listdir(download_tool_dir) if _file.startswith("ABOOT")]
    download_tool_list.sort(key=lambda fn:os.path.getmtime(os.path.join(download_tool_dir,fn)))
    download_tool_zip = download_tool_list[-1]

    os.chdir(download_tool_dir)
    cmd = "%s x %s -y"%(cfg.unzip_tool, download_tool_zip)
    proc = subprocess.call(cmd, shell = True)
    download_tool = os.path.splitext(download_tool_zip)[0]
    download_tool_name = download_tool + "_" + time.strftime("%Y%m%d_%H%M%S")
    os.rename(download_tool,download_tool_name)
    cp_bin_list = []
    for root, dirs, files in os.walk(download_tool_name):
        if "cp.bin" in files:
            cp_bin_list.append(os.path.join(root,"cp.bin"))
    logger.debug(cp_bin_list)
    crane_evb_bin = os.path.join(version_file,"crane_evb_z2","crane_evb.bin")
    for cp_bin_dist in cp_bin_list:
        logger.debug(cp_bin_dist)
        shutil.copy2(crane_evb_bin,cp_bin_dist)
    download_tool_fname = download_tool_name+".zip"
    download_tool_dist = os.path.join(version_file,"download_tool",download_tool_fname)
    logger.debug(download_tool_dist)
    cmd = "%s a %s %s -y"%(cfg.unzip_tool,download_tool_dist,download_tool_name)
    proc = subprocess.call(cmd, shell = True)


def get_release_version(root_dir,dist_dir,target = "crane_git_r"):
    root_dir = os.path.dirname(root_dir)
    dailybuild_list = [_file for _file in os.listdir(root_dir) if _file.startswith(target)]
    dailybuild_list.sort(key=lambda fn:os.path.getmtime(os.path.join(root_dir,fn)))
    for file_name in dailybuild_list[::-1]:
        logger.debug(file_name)
        dist = os.path.join(dist_dir,file_name)
        if os.path.exists(dist):
            logger.debug(dist)
            return os.path.join(root_dir,file_name)
    else:
        return None

class autoRelease(ThreadBase):
    def __init__(self):
        super(autoRelease,self).__init__()
        self.today_release_flag = threading.Event()

    def run(self, cfg, cp_sdk_class,release_event):
        while self._running:
            release_event.wait()
            release_event.clear()
            version_file = get_release_version(cfg.cur_crane,cfg.dist_dir)
            if not version_file:
                continue
            file_name = os.path.basename(version_file)
            logger.info(version_file)
            cp_version_file = os.path.join(version_file,"version_info", "cp_version.txt")
            with open(cp_version_file) as obj:
                cp_version = obj.read()
            dsp_version_file = os.path.join(version_file,"version_info", "dsp_version.txt")
            with open(dsp_version_file) as obj:
                dsp_version_file = obj.read()
            cp_sdk_class.update_download_tool()
            self.today_release_flag.set()
            for board in cfg.BOARD_LIST:
                root_dir = os.path.join(version_file, board, "cp_images")
                images = [os.path.join(root_dir, _file) for _file in os.listdir(root_dir)]
                cp_sdk_class.prepare_download_tool(images,board)
                version_fname = os.path.basename(version_file)
                _match = re.findall("crane_git_r[0-9]+",version_fname)
                assert _match,"file name can not match"
                version = _match[0]
                _match = re.findall("MINIGUI_SDK_[0-9]+",cp_version)
                assert _match,"cp_version can not match"
                cp_version_sdk = _match[0]
                cp_sdk_class.release_download_tool(cp_version_sdk, version, board)

            cus_version_file = get_release_version(cfg.cur_crane_cus,cfg.release_dist_dir,"crane_release_")
            cus_version_file = os.path.join(cfg.release_dist_dir,os.path.basename(cus_version_file))
            send_release_email(file_name, cp_version, dsp_version_file,cus_version_file)

            # customer trigger test
            # try:
                # board = "crane_evb_z2"
                # dist = cus_version_file
                # sdk_tool_abs_path = os.listdir(os.path.join(dist,"download_tool"))
                # if sdk_tool_abs_path:
                    # sdk_tool_abs_path = os.path.join(dist,"download_tool",sdk_tool_abs_path[0])
                # else:
                    # sdk_tool_abs_path = None
                # mdb_txt_file_dir = os.path.join(dist,board)
                # logger.info(mdb_txt_file_dir)
                # for _file in os.listdir(mdb_txt_file_dir):
                    # if "MDB.TXT" in _file.upper():
                        # mdb_txt_file_abs_path = os.path.join(mdb_txt_file_dir,_file)
                        # break
                # else:
                    # mdb_txt_file_abs_path = None
                # logger.info(sdk_tool_abs_path,mdb_txt_file_abs_path,"evb_customer")
                # trigger_test(sdk_tool_abs_path,mdb_txt_file_abs_path,"evb_customer")
            # except Exception,e:
                # logger.info(e)

            try:
                board = "crane_evb_z2"
                sdk_tool_abs_path = cp_sdk_class.download_tool_dict.get(board)
                mdb_txt_file_dir = os.path.join(cfg.dist_dir,os.path.basename(version_file),board)
                for _file in os.listdir(mdb_txt_file_dir):
                    if "MDB.TXT" in _file.upper():
                        mdb_txt_file_abs_path = os.path.join(mdb_txt_file_dir,_file)
                        break
                else:
                    mdb_txt_file_abs_path = None
                logger.info(sdk_tool_abs_path,mdb_txt_file_abs_path)
                trigger_test(sdk_tool_abs_path,mdb_txt_file_abs_path)
            except Exception,e:
                logger.info(e)

            try:
                lib_src = os.path.join(version_file,"crane_evb_z2","rel_lib")
                logger.info(lib_src,os.path.basename(version_file))
                cp_sdk_class.zip_tool(lib_src,"zip",lib_src)
                ftp_upload_file(lib_src+".zip",os.path.basename(version_file))
            except Exception,e:
                logger.info(e)

            time.sleep(1)

class autoPush(ThreadBase):
    def __init__(self):
        super(autoPush,self).__init__()

    def run(self, cp_sdk_class,dsp_class,push_done):
        while self._running:
            dsp_class.git_push_dsp_dailybuild()
            if cp_sdk_class.git_push_cp_dailybuild():
                push_done.set()


def clean_overdue_dir(dir,del_time,target_dir = '',isdir = True):
    os.chdir(dir)
    listdir = os.listdir(dir)
    listdir = [d for d in listdir if os.path.isdir(d) and target_dir in d] if isdir else [f for f in listdir if os.path.isfile(f) and target_dir in f]
    del_t = datetime.timedelta(days=del_time)
    now = datetime.datetime.now()
    for d in listdir:
        ctime = datetime.datetime.fromtimestamp(os.path.getctime(d))
        if (now - ctime) > del_t:
            # os.chmod(d,0o777)
            # shutil.rmtree(d)
            logger.info("delete %s start..."%d)
            os.system(r"rd /s /q %s"%d)
            logger.info("delete %s done"%d)

class autoCleanOverdueDir(ThreadBase):
    def __init__(self):
        super(autoCleanOverdueDir,self).__init__()

    def run(self,logger):
        while self._running:
            try:
                now = datetime.datetime.today()
                if now.minute > 1 or now.hour != 2:
                    continue
                clean_overdue_dir(r"E:\crane_dailybuild",5,target_dir = 'crane_git_')
                clean_overdue_dir(cfg.external_dir,55,target_dir = 'crane_git_')
                clean_overdue_dir(cfg.download_tool_dir,55,target_dir = 'MINIGUI_SDK_')
                clean_overdue_dir("D:\crane_cus",30,target_dir = 'crane_release_')
                clean_overdue_dir(cfg.release_dist_dir,55,target_dir = 'crane_release_')
                time.sleep(10)
            except KeyboardInterrupt:
                logger.info('clean_overdue_dir exit')
                self._running = False
            except:
                pass

class autoBuild(ThreadBase):
    def __init__(self):
        super(autoBuild,self).__init__()

    def run(self,repo, logger):
        while self._running:
            try:
                check_dsp_rf_rbd()
                repo.get_dsp_version()
                auto_dailybuild()
                auto_build_cus()
            except KeyboardInterrupt:
                logger.info('autoBuild exit')
                self.terminate()
            except Exception,e:
                logger.error(e)

def prepare_system_start():
    cfg.update('config.ini')

    if not os.path.exists(cfg.tmp_dir):
        os.mkdir(cfg.tmp_dir)

    if not os.path.exists(cfg.log_dir):
        os.mkdir(cfg.log_dir)

    if not os.path.exists(cfg.manisest_xml_dir):
        os.mkdir(cfg.manisest_xml_dir)

    if not os.path.exists(cfg.compile_log_dir):
        os.mkdir(cfg.compile_log_dir)

    if not os.path.exists(cfg.cp_sdk_dir):
        os.mkdir(cfg.cp_sdk_dir)

    if not os.path.exists(cfg.download_tool_dir):
        os.mkdir(cfg.download_tool_dir)

    if not os.path.exists(cfg.dsp_rf_rbd_dir):
        os.mkdir(cfg.dsp_rf_rbd_dir)
    logger.info("prepare system done")

RELEASE_EVENT = threading.Event()
PUSH_CP_DONE = threading.Event()
cfg = config()

if __name__ == "__main__":
    logger = myLogger("build_release")
    logger.enablePrint()

    prepare_system_start()
    now = datetime.datetime.today()
    log_file = os.path.join(cfg.log_dir,"log_%s.txt"%time.strftime("%Y%m%d_%H%M%S"))

    logger.resetLogFile(log_file)
    logger.setLevel(logging.INFO)
    # logger.setLevel(logging.DEBUG)
    logger.debug(cfg)

    repo = myRepo(cfg.version_log, cfg.cur_crane)
    repo.update_cp_version()

    repo_cus = myRepo(cfg.version_cus_log,cfg.cur_crane_cus,["."])
    build_controller = buildController(cfg)
    cp_sdk_cls = gitPushCpDailyBuild(cfg,logger)
    dsp_cls = gitPushDspDailyBuild(cfg,logger)
    release_tool = releaseZip(cfg)

    auto_release_task = autoRelease()
    auto_push_cp_task = autoPush()
    auto_build_task = autoBuild()
    auto_clean_overdue_dir_task = autoCleanOverdueDir()

    cp_sdk_cls.git_push_cp_dailybuild()

    auto_clean_overdue_dir_task.start(logger)
    auto_release_task.start(cfg, cp_sdk_cls,RELEASE_EVENT)
    auto_push_cp_task.start(cp_sdk_cls, dsp_cls, PUSH_CP_DONE)
    auto_build_task.start(repo, logger)
    logger.info("**********************start**********************")
    while 1:
        try:
            now = datetime.datetime.today()
            cfg.update('config.ini')
            if now.hour == 0 and now.minute == 0 and now.second == 0:
                auto_release_task.today_release_flag.clear()
                time.sleep(1)

            if now.hour == 7 and now.minute == 20 and now.second == 0:
                if not auto_release_task.today_release_flag.is_set():
                    RELEASE_EVENT.set()
                    time.sleep(1)

        except KeyboardInterrupt:
            logger.info("exit: KeyboardInterrupt")
            auto_clean_overdue_dir_task.terminate()
            auto_release_task.terminate()
            auto_push_cp_task.terminate()
            auto_build_task.terminate()
            sys.exit()
        except Exception,e:
            logger.error(e)
            auto_clean_overdue_dir_task.terminate()
            auto_release_task.terminate()
            auto_push_cp_task.terminate()
            auto_build_task.terminate()











