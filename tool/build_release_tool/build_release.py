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
from kill_winproc import kill_winproc
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
CP VERSION: %s
DSP VERSION: %s
RELEASE VERSION: %s
"""

class buildController(object):
    def __init__(self,cfg):
        self.build_res = None

        self.compile_log_dir = cfg.compile_log_dir

        self.git_version_dir = None

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
            self.compile_log = os.path.join(self.compile_log_dir,compile_log)
        else:
            self.compile_log = os.path.join(self.compile_log_dir,os.path.basename(self.git_version_dir)+".log")
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

    def update_cp_version(self,cp_version_file,cp_version_log_file):
        self.cp_version = self.get_cp_version(cp_version_file)
        with open(cp_version_log_file,"w") as obj:
            obj.write(self.cp_version)

    def get_old_cp_version(self,cp_version_log_file):
        if not os.path.exists(cp_version_log_file):
            return None
        else:
            with open(cp_version_log_file) as obj:
                return obj.read()

    def record_cp_version(self,cp_version_log_file):
        with open(cp_version_log_file,"w") as obj:
            obj.write(self.cp_version)

    def get_dsp_version(self,dsp_bin,dsp_version_log_file):
        "!CRANE_CAT1GSM_L1_1.043.000 , Dec 13 2019 03:30:56"
        fobj = open(dsp_bin,"rb")
        text = fobj.read()
        # match = re.findall("!(CRANE_.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])",text)
        match = re.findall("(CRANE_.{43})",text)
        if match:
            version_info = match[0]
            logger.debug(version_info)
            self.dsp_version = version_info
            with open(dsp_version_log_file,"w") as obj:
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
        os.mkdir(os.path.join(version_file, board, "cp_images"))


def copy_build_file_to_release_dir(dist_dir, src_dir = None):
    if not src_dir:
        src_dir = cfg.cur_crane
    BUILD_IMAGES = cfg.BUILD_IMAGES[:]
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


def CHECK_DSP_VERSION(dsp_version):
    '''CRANE_CAT1GSM_L1_1.053.001 , Feb 29 2020 03:40:50'''
    match = re.findall("(CRANE_.*? ,.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])",dsp_version)
    if not match:
        return "can not match dsp version".upper()
    return match[0]

def send_release_email(version_file, customer_file = None):
    to_address = "GR-Modem-SV-Report@asrmicro.com,SW_QA@asrmicro.com,SW_Managers@asrmicro.com,SW_CV@asrmicro.com,crane_sw_mmi_group@asrmicro.com"
    version_fname = os.path.basename(version_file)
    subject = email_subject%version_fname.upper()
    _match = re.findall("crane_git_r[0-9]+",version_fname)
    assert _match,"file name can not match"
    version = _match[0]

    cp_version_file = os.path.join(version_file,"version_info","cp_version.txt")
    with open(cp_version_file) as obj:
        cp_version = obj.read()
    dsp_version_file = os.path.join(version_file,"version_info","dsp_version.txt")
    with open(dsp_version_file) as obj:
        dsp_version = obj.read()
    logger.info(dsp_version)
    dsp_version = CHECK_DSP_VERSION(dsp_version)

    cp_version_file = os.path.join(customer_file,"version_info","release_cp_version.txt")
    with open(cp_version_file) as obj:
        cp_version_cus = obj.read()

    dsp_version_file = os.path.join(customer_file,"version_info","release_dsp_version.txt")
    with open(dsp_version_file) as obj:
        dsp_version_cus = obj.read()
    logger.info(dsp_version_cus)
    dsp_version_cus = CHECK_DSP_VERSION(dsp_version_cus)
    if customer_file:
        msg = email_msg_with_cus%((version.upper(), cp_version, dsp_version)+(version_fname,)*4+(cp_version_cus,dsp_version_cus, customer_file))
    else:
        msg = email_msg%((version.upper(), cp_version, dsp_version)+(version_fname,)*4)
    logger.info(subject)
    logger.info(msg)
    send_email_tool(to_address,subject,msg)

class dailyBuild(object):
    def __init__(self, cfg, repo):
        self.repo = repo
        self.cur_crane = cfg.cur_crane
        self.external_dir = cfg.external_dir

        self.board_list = cfg.BOARD_LIST[:]
        self.borad_build_cmd = cfg.BOARD_BUILD_CMD[:]

        self.build_images = cfg.BUILD_IMAGES[:]

        self.version_log = cfg.version_log

        self.mdb_file_dir = cfg.mdb_file_dir
        self.sdk_files_dict = cfg.BOARD_CP_RELEASE_BIN_DICT

        self.dsp_bin = os.path.join(cfg.cur_crane,"cus","evb","images","dsp.bin")
        self.dsp_version_log = cfg.dsp_version_log

        self.cp_version_file = os.path.join(cfg.cur_crane,cfg.cp_version_file)
        self.cp_version_log = cfg.cp_version_log

        self.dist_dir = cfg.dist_dir

        self.manisest_xml_dir = cfg.manisest_xml_dir

        self.xml_file = None
        self.git_version_dir = None
        self.massage_file = None

    def prepare_release_dir(self):
        assert self.git_version_dir,"version_file: %s is None"
        os.mkdir(self.git_version_dir)
        os.mkdir(os.path.join(self.git_version_dir,"version_info"))

        for board in self.board_list:
            os.mkdir(os.path.join(self.git_version_dir, board))
            os.mkdir(os.path.join(self.git_version_dir, board, "cp_images"))

    def copy_version_file_to_release_dir(self):
        for _file in [self.xml_file, self.cp_version_log, self.dsp_version_log, self.massage_file]:
            if os.path.exists(_file):
                shutil.copy2(_file,os.path.join(self.git_version_dir,"version_info",os.path.basename(_file)))

    def copy_build_file_to_release_dir(self, dist_dir):
        src_dir = self.cur_crane
        for _file in self.build_images:
            src = os.path.join(src_dir,_file)
            dist = os.path.join(dist_dir, os.path.basename(_file))
            if os.path.exists(src):
                if os.path.isfile(src):
                    shutil.copy2(src, dist)
                elif os.path.isdir(src):
                    shutil.copytree(src, dist)
            else:
                logger.warning("%s file not exists"%src)


    def copy_sdk_files_to_release_dir(self, dist_dir, board = "crane_evb_z2"):
        src_dir = self.cur_crane
        src_bin_l = self.sdk_files_dict.get(board,[])
        src_bin_l = [os.path.join(src_dir,_file) for _file in src_bin_l]
        for src_bin in src_bin_l:
            if os.path.exists(src_bin):
                shutil.copy2(src_bin,dist_dir)
            else:
                logger.warning("%s not exists"%src_bin)

        if os.path.exists(self.mdb_file_dir):
            for _file in os.listdir(self.mdb_file_dir):
                if "MDB.TXT" in _file.upper():
                    shutil.copy2(os.path.join(self.mdb_file_dir, _file),os.path.join(dist_dir, _file))
                    break


    def condition(self):
        time.sleep(3)
        return self.repo.sync()

    def build(self):
        if not self.condition():
            return
        self.repo.get_dsp_version(self.dsp_bin, self.dsp_version_log)
        old_cp_version = self.repo.get_old_cp_version(self.cp_version_log)
        self.repo.update_cp_version(self.cp_version_file, self.cp_version_log)
        commit_id, owner,date, commit_info = self.repo.get_revion_owner()
        logger.info("="*50)
        logger.debug(commit_id, owner,date, commit_info,time.asctime(time.localtime(int(date))))
        _r = self.repo.record_version()
        date = time.strftime("%Y%m%d_%H%M%S")
        file_name = "%s_%s"%(_r,date)
        logger.info("version: "+file_name)
        self.xml_file = _r + ".xml"
        self.xml_file = os.path.join(self.manisest_xml_dir,self.xml_file)
        self.repo.get_manifest_xml(self.xml_file)
        self.massage_file = self.repo.get_commit_massages()

        self.git_version_dir = os.path.join(os.path.dirname(self.cur_crane),file_name)

        build_controller.git_version_dir = self.git_version_dir

        self.prepare_release_dir()
        self.copy_version_file_to_release_dir()

        for board, build_cmd in zip(self.board_list, self.borad_build_cmd):
            self.repo.git_clean()
            build_controller.build(self.cur_crane, cmd = build_cmd)
            build_controller.send_email(self.cur_crane, owner,os.path.join(self.external_dir,file_name),board)

            self.copy_build_file_to_release_dir(os.path.join(self.git_version_dir,board))
            self.copy_sdk_files_to_release_dir(os.path.join(self.git_version_dir,board,"cp_images"), board)

            archive_file = os.path.join(self.git_version_dir,board, "ASR_CRANE_EVB_A0_16MB.zip")
            dist_dir = os.path.join(self.git_version_dir,board,"cp_images")
            zip_tool.unpack_files_from_archive(archive_file, dist_dir, "dsp.bin","rf.bin","ReliableData.bin")

            kill_winproc("mingw32-make.exe",'cmake.exe',"make.exe", 'armcc.exe',  'wtee.exe')

            if board in self.board_list[0] and build_controller.build_res in "FAIL":
                return self.git_version_dir

        dist = os.path.join(self.dist_dir,file_name)
        build_controller.copy(self.git_version_dir, dist)

        logger.info("old_cp_version: %s, new_cp_version: %s"%(old_cp_version,self.repo.cp_version))
        if self.repo.cp_version not in old_cp_version:
            RELEASE_EVENT.set()
            PUSH_CP_DONE.clear()
        return self.git_version_dir


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
    commit_id, owner,date, commit_info = repo_cus.get_revion_owner()
    logger.info("="*50)
    logger.debug(commit_id, owner,date, commit_info,time.asctime(time.localtime(int(date))))
    date = time.strftime("%Y%m%d_%H%M%S")
    file_name = "crane_release_%s"%date
    logger.info("version: "+file_name)
    dist = os.path.join(cfg.release_dist_dir,file_name)
    massage_file = repo_cus.get_commit_massages()

    version_file = os.path.join(os.path.dirname(curdir),file_name)
    build_controller.git_version_dir = version_file
    prepare_release_dir(version_file,True)
    release_note = find_newest_notes()
    if release_note:
        shutil.copy2(release_note,os.path.join(version_file,"crane_evb_z2",os.path.basename(release_note)))
    shutil.copy2(massage_file,os.path.join(version_file,"crane_evb_z2",os.path.basename(massage_file)))
    dsp_bin = os.path.join(build_root_dir,"cus","evb","images","dsp.bin")
    repo_cus.get_dsp_version(dsp_bin, os.path.join(version_file,"version_info",os.path.basename(cfg.release_dsp_version_log)))
    repo_cus.update_cp_version(os.path.join(build_root_dir,cfg.cp_version_file),os.path.join(version_file,"version_info",os.path.basename(cfg.release_cp_version_log)))

    for board, build_cmd in [("crane_evb_z2","autobuild.bat")]:
        repo_cus.git_clean()
        build_controller.build(build_root_dir, cmd = build_cmd)
        build_controller.send_email(build_root_dir, owner,os.path.join(cfg.release_dist_dir,file_name),board)

        copy_build_file_to_release_dir(os.path.join(version_file,board),build_root_dir)
        copy_cp_file_to_release_dir(os.path.join(version_file,board,"cp_images"), "cus_evb", build_root_dir)
        archive_file = os.path.join(version_file,board, "ASR_CRANE_EVB_A0_16MB.zip")
        dist_dir = os.path.join(version_file,board,"cp_images")
        zip_tool.unpack_files_from_archive(archive_file, dist_dir, "dsp.bin","rf.bin","ReliableData.bin")
        kill_winproc("mingw32-make.exe",'cmake.exe',"make.exe", 'armcc.exe',  'wtee.exe')

        if board in cfg.BOARD_LIST[0] and build_controller.build_res in "FAIL":
            return version_file
    root_dir = os.path.join(version_file, "crane_evb_z2", "cp_images")
    images = [os.path.join(root_dir, _file) for _file in os.listdir(root_dir)]
    download_controller.update_download_tool()
    download_controller.prepare_download_tool(images)
    download_controller.release_download_tool(os.path.basename(version_file), "crane_evb_z2", dist_dir = os.path.join(version_file,"download_tool"))
    build_controller.copy(version_file, dist)

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
    return version_file


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
            logger.info(version_file)
            cp_version_file = os.path.join(version_file,"version_info", "cp_version.txt")
            with open(cp_version_file) as obj:
                cp_version = obj.read()
            download_controller.update_download_tool()
            self.today_release_flag.set()
            for board in cfg.BOARD_LIST:
                root_dir = os.path.join(version_file, board, "cp_images")
                images = [os.path.join(root_dir, _file) for _file in os.listdir(root_dir)]
                version_fname = os.path.basename(version_file)
                _match = re.findall("crane_git_r[0-9]+",version_fname)
                assert _match,"file name can not match"
                version = _match[0]
                _match = re.findall("MINIGUI_SDK_[0-9]+",cp_version)
                assert _match,"cp_version can not match"
                cp_version_sdk = _match[0]
                download_controller.prepare_download_tool(images,board)
                release_name = "_".join([cp_version_sdk, version])
                download_controller.release_download_tool(release_name, board, dist_dir = os.path.join(cfg.dist_dir,"download_tool", board))

            cus_version_file = get_release_version(cfg.cur_crane_cus,cfg.release_dist_dir,"crane_release_")
            cus_version_file = os.path.join(cfg.release_dist_dir,os.path.basename(cus_version_file))

            send_release_email(version_file, cus_version_file)

            # customer trigger dailybuild test
            try:
                board = "crane_evb_z2"
                sdk_tool_abs_path = download_controller.download_tool_dict.get(board)
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

            root_dir = os.path.join(cus_version_file, "crane_evb_z2", "cp_images")
            images = [os.path.join(root_dir, _file) for _file in os.listdir(root_dir)]
            download_controller.prepare_download_tool(images)
            download_controller.release_download_tool(os.path.basename(cus_version_file), "crane_evb_z2", dist_dir = os.path.join(cus_version_file,"download_tool"))

            #trigger customer test
            try:
                board = "crane_evb_z2"
                dist = cus_version_file
                sdk_tool_abs_path = download_controller.download_tool_dict.get(board)
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

            try:
                lib_src = os.path.join(version_file,"crane_evb_z2","rel_lib")
                logger.info(lib_src,os.path.basename(version_file))
                zip_tool.make_archive_e(lib_src,"zip",lib_src)
                ftp_upload_file(lib_src+".zip",os.path.basename(version_file))
            except Exception,e:
                logger.info(e)



class autoPush(ThreadBase):
    def __init__(self):
        super(autoPush,self).__init__()

    def run(self, cp_sdk_class,dsp_class,push_done):
        while self._running:
            dsp_class.git_push()
            if cp_sdk_class.git_push():
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
                clean_overdue_dir(cfg.download_tool_dir,10,target_dir = 'MINIGUI_SDK_')
                clean_overdue_dir(cfg.cp_sdk_dir,10,target_dir = 'ASR3601_MINIGUI_')
                clean_overdue_dir("D:\crane_cus",10,target_dir = 'crane_release_')
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
                # auto_dailybuild()
                auto_daily_build_cls.build()
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
    root_dir = os.getcwd()
    logger = myLogger("build_release")
    prepare_system_start()
    now = datetime.datetime.today()
    log_file = os.path.join(cfg.log_dir,"log_%s.txt"%time.strftime("%Y%m%d_%H%M%S"))
    zip_tool = zipTool()

    logger.resetLogFile(log_file)
    logger.debug(cfg)
    repo = myRepo(cfg.version_log, cfg.cur_crane)
    repo.update_cp_version(os.path.join(cfg.cur_crane,cfg.cp_version_file),cfg.cp_version_log)
    repo_cus = myRepo(cfg.version_cus_log,cfg.cur_crane_cus,["."])

    build_controller = buildController(cfg)
    download_controller = downloadToolController(cfg, logger)
    # download_controller.update_download_tool()

    auto_daily_build_cls = dailyBuild(cfg, repo)

    cp_sdk_cls = gitPushCpDailyBuild(cfg,logger)
    dsp_cls = gitPushDspDailyBuild(cfg,logger)
    release_tool = releaseZip(cfg)
    auto_release_task = autoRelease()
    auto_push_cp_task = autoPush()
    auto_build_task = autoBuild()
    auto_clean_overdue_dir_task = autoCleanOverdueDir()

    cp_sdk_cls.git_push()

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

            if now.hour == 7 and now.minute == 30 and now.second == 0:
                if not auto_release_task.today_release_flag.is_set():
                    RELEASE_EVENT.set()
                    time.sleep(1)

        except KeyboardInterrupt:
            logger.info("exit: KeyboardInterrupt")
            auto_clean_overdue_dir_task.terminate()
            auto_release_task.terminate()
            auto_push_cp_task.terminate()
            auto_build_task.terminate()
            os.chdir(root_dir)
            os.system("del *.pyc")
            kill_winproc("mingw32-make.exe",'cmake.exe',"make.exe", 'armcc.exe',  'wtee.exe')
            sys.exit()
        except Exception,e:
            logger.error(e)
            kill_winproc("mingw32-make.exe",'cmake.exe',"make.exe", 'armcc.exe',  'wtee.exe')
            auto_clean_overdue_dir_task.terminate()
            auto_release_task.terminate()
            auto_push_cp_task.terminate()
            auto_build_task.terminate()











