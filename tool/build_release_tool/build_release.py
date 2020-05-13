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
from myrepo import *

reload(sys)
sys.setdefaultencoding( "utf-8" )


email_subject = "CRANE PHONE: AUTO RELEASE %s"
email_msg = r"""
GUI VERSION: {0}
CP VERSION: {1}
DSP VERSION: {2}

NORMAL VERSION(SINGLE and DUAL SIM):
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\crane_evb_z2
hal lib: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\crane_evb_z2\rel_lib
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\download_tool\crane_evb_z2

BIRD PHONE VERSION:
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\bird_phone
hal lib: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\bird_phone\rel_lib
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\download_tool\bird_phone

"""
email_msg_with_cus = r"""
GUI VERSION: {0}
CP VERSION: {1}
DSP VERSION: {2}

NORMAL VERSION(SINGLE and DUAL SIM):
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\crane_evb_z2
hal lib: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\crane_evb_z2\rel_lib
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\download_tool\crane_evb_z2

BIRD PHONE VERSION:
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\bird_phone
hal lib: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\bird_phone\rel_lib
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\download_tool\bird_phone

CUSTOMER RELEASE:
CP VERSION: {4}
DSP VERSION: {5}

RELEASE VERSION: {6}
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
        if os.path.exists(r"%s\build\%s\crane_evb.elf"%(curdir,build_dir)) and os.path.exists(r"%s\build\%s\crane_evb.bin"%(curdir,build_dir)):
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
        to_address = ",".join([owner,'yuanzhizheng@asrmicro.com'])
        send_email_tool(to_address, subject, msg, att_file)
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
        self.sdk_images = cfg.IMAGES[:]

        self.dsp_bin = os.path.join(cfg.cur_crane,"cus","evb","images","dsp.bin")
        self.dsp_version_log = cfg.dsp_version_log
        self.decompress_tool = cfg.decompress_tool

        self.cp_version_file = os.path.join(cfg.cur_crane,cfg.cp_version_file)
        self.cp_version_log = cfg.cp_version_log

        self.ap_version_log = cfg.ap_version_log

        self.dist_dir = cfg.dist_dir

        self.tmp_dir = cfg.tmp_dir

        self.manisest_xml_dir = cfg.manisest_xml_dir

        self.sdk_release_notes_file = os.path.join(cfg.cur_crane, cfg.sdk_release_notes_file)

        self.xml_file = ''
        self.git_version_dir = ''
        self.massage_file = ''
        self.cp_version = ''
        self.dsp_version = ''

    def get_dsp_version(self,dsp_bin):
        "!CRANE_CAT1GSM_L1_1.043.000 , Dec 13 2019 03:30:56"
        dsp_version_file = os.path.join(self.tmp_dir,"dsp_version.bin")
        decompress_cmd = "{0} -d -f {1} -o{2}".format(self.decompress_tool,dsp_bin, dsp_version_file)
        os.system(decompress_cmd)
        assert os.path.exists(dsp_version_file),"canot find {}".format(dsp_version_file)
        with open(dsp_version_file,"rb") as fobj:
            text = fobj.read()
        # match = re.findall("!(CRANE_.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])",text)
        fobj.close()
        match = re.findall("(CRANE_.{47})",text)
        if match:
            version_info = match[0]
            logger.debug(version_info)
            self.dsp_version = version_info
        else:
            version_info = "can not match dsp version".upper()
        with open(self.dsp_version_log,"w") as obj:
            obj.write(version_info)
        return version_info

    def prepare_release_dir(self):
        assert self.git_version_dir,"version_file: %s is None"
        os.mkdir(self.git_version_dir)
        os.mkdir(os.path.join(self.git_version_dir,"version_info"))

        for board in self.board_list:
            os.mkdir(os.path.join(self.git_version_dir, board))
            os.mkdir(os.path.join(self.git_version_dir, board, "cp_images"))

    def record_ap_version(self, version):
        with open(self.ap_version_log,'w') as _obj:
            _obj.write(version.upper())

    def copy_version_file_to_release_dir(self):
        for _file in [self.xml_file, self.ap_version_log, self.cp_version_log, self.dsp_version_log, self.massage_file]:
            if os.path.exists(_file):
                shutil.copy2(_file,os.path.join(self.git_version_dir,"version_info",os.path.basename(_file)))

    def copy_build_file_to_release_dir(self, dist_dir, src_dir = None):
        if not src_dir:
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

        if os.path.exists(self.mdb_file_dir):
            for _file in os.listdir(self.mdb_file_dir):
                if "MDB.TXT" in _file.upper():
                    shutil.copy2(os.path.join(self.mdb_file_dir, _file),os.path.join(dist_dir, _file))
                    break

    def copy_sdk_files_to_release_dir(self, dist_dir, board = "crane_evb_z2", src_dir = None):
        if not src_dir:
            src_dir = self.cur_crane
        src_bin_l = self.sdk_files_dict.get(board,[])
        src_bin_l = [os.path.join(src_dir,_file) for _file in src_bin_l]
        dist_bin_l = [os.path.join(dist_dir,_file) for _file in self.sdk_images]
        for src_bin,dist_bin in zip(src_bin_l,dist_bin_l):
            if os.path.exists(src_bin):
                shutil.copy2(src_bin,dist_bin)
            else:
                logger.warning("%s not exists"%src_bin)

        if os.path.exists(self.mdb_file_dir):
            for _file in os.listdir(self.mdb_file_dir):
                if "MDB.TXT" in _file.upper():
                    shutil.copy2(os.path.join(self.mdb_file_dir, _file),os.path.join(dist_dir, _file))
                    break


    def condition(self):
        return self.repo.sync()

    def build(self):
        self.get_dsp_version(self.dsp_bin)
        old_cp_version = self.repo.get_old_cp_version(self.cp_version_log)
        self.cp_version = self.repo.update_cp_version(self.cp_version_file, self.cp_version_log)
        commit_id, owner,date, commit_info = self.repo.get_revion_owner()
        logger.info("="*50)
        logger.debug(commit_id, owner,date, commit_info,time.asctime(time.localtime(int(date))))
        _r = self.repo.record_version()
        self.record_ap_version(_r)
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
            try:
                build_controller.build(self.cur_crane, cmd = build_cmd)
                build_controller.send_email(self.cur_crane, owner,os.path.join(self.external_dir,file_name),board)

                kill_winproc("mingw32-make.exe",'cmake.exe',"make.exe", 'armcc.exe',  'wtee.exe')

                if board in self.board_list[0] and build_controller.build_res in "FAIL":
                    logger.info(self.git_version_dir,"build fail")
                    return self.git_version_dir

                self.copy_build_file_to_release_dir(os.path.join(self.git_version_dir,board))
                self.copy_sdk_files_to_release_dir(os.path.join(self.git_version_dir,board,"cp_images"), board)

                archive_file = os.path.join(self.git_version_dir,board, "ASR_CRANE_EVB_A0_16MB.zip")
                dist_dir = os.path.join(self.git_version_dir,board,"cp_images")
                zip_tool.unpack_files_from_archive(archive_file, dist_dir, "dsp.bin","rf.bin","ReliableData.bin")
            except Exception, e:
                logger.error(e)

        dist = os.path.join(self.dist_dir,file_name)
        build_controller.copy(self.git_version_dir, dist)

        logger.info("old_cp_version: %s"%(old_cp_version))
        logger.info("new_cp_version: %s"%(self.cp_version))
        if self.cp_version not in old_cp_version:
            RELEASE_EVENT.set()
        return self.git_version_dir



class cusbuild(dailyBuild):
    def __init__(self,cfg, repo_cus):
        super(cusbuild,self).__init__(cfg, repo_cus)
        self.cfg = cfg
        self.cur_crane = cfg.cur_crane_cus
        self.build_root_dir = cfg.cus_build_root_dir

        self.relase_download_tool = None
        self.release_mdb_dir = None

        self.board_list = cfg.BOARD_LIST[:]
        self.borad_build_cmd = cfg.BOARD_BUILD_CMD[:]

        self.release_dist_dir = repo_cus.release_dist_dir

        self.dsp_bin = os.path.join(self.build_root_dir,"cus","evb","images","dsp.bin")
        self.dsp_version_log = cfg.release_dsp_version_log

        self.cp_version_file = os.path.join(self.build_root_dir, cfg.cp_version_file)
        self.cp_version_log = cfg.release_cp_version_log

        self.ap_version_log = cfg.release_ap_version_log

        self.sdk_release_notes_file = cfg.cus_sdk_release_notes_file

        self.loacal_dist_dir = ''
        self.loacal_build_dir_d = {}
        self.download_tool_dir_d = {}
        self.download_tool_images_dir_d = {}
        self.version_info_dir = ''

        self.dist_dir = repo_cus.release_dist_dir

    def prepare_release_dir(self, version_file):
        self.loacal_dist_dir = version_file
        self.git_version_dir = version_file
        os.mkdir(self.loacal_dist_dir)
        self.version_info_dir = os.path.join(version_file,"version_info")
        os.mkdir(self.version_info_dir)
        for board in self.board_list:
            self.loacal_build_dir_d[board] = os.path.join(version_file, board)
            os.mkdir(self.loacal_build_dir_d[board])
            self.download_tool_dir_d[board] = os.path.join(version_file,board, "download_tool")
            os.mkdir(self.download_tool_dir_d[board])
            self.download_tool_images_dir_d[board] = os.path.join(version_file, board, "cp_images")
            os.mkdir(self.download_tool_images_dir_d[board])


    def find_newest_notes(self):
        root_dir = os.path.join(self.cur_crane,"note")
        release_note_list = [_file for _file in os.listdir(root_dir) if _file.startswith("ReleaseNotes")]
        release_note_list.sort(key=lambda fn:os.path.getmtime(os.path.join(root_dir,fn)))
        if release_note_list:
            file_name = release_note_list[-1]
            logger.debug(file_name)
            return os.path.join(root_dir, file_name)
        else:
            return None

    def build(self):
        if self.repo.release_branch in ["r1","r1_plus_j"]:
            self.board_list = self.cfg.BOARD_LIST[:1]
            self.borad_build_cmd = self.cfg.BOARD_BUILD_CMD[:1]
        else:
            self.board_list = self.cfg.BOARD_LIST[:]
            self.borad_build_cmd = self.cfg.BOARD_BUILD_CMD[:]
        old_cp_version = self.repo.get_old_cp_version(self.cp_version_log)
        self.cp_version = self.repo.update_cp_version(self.cp_version_file, self.cp_version_log)
        self.get_dsp_version(self.dsp_bin)
        commit_id, owner, date, commit_info = self.repo.get_revion_owner()
        logger.info("="*50)
        logger.debug(commit_id, owner,date, commit_info,time.asctime(time.localtime(int(date))))
        _r = self.repo.record_version()
        self.record_ap_version(_r)
        date = time.strftime("%Y%m%d_%H%M%S")
        file_name = "%s_%s"%(_r,date)
        logger.info("version: "+file_name)
        release_dist = os.path.join(self.release_dist_dir,file_name)
        self.massage_file = self.repo.get_commit_massages()

        version_file = os.path.join(os.path.dirname(self.cur_crane),file_name)
        build_controller.git_version_dir = version_file

        self.prepare_release_dir(version_file)
        self.copy_version_file_to_release_dir()

        release_note = self.find_newest_notes()
        if release_note:
            shutil.copy2(release_note,os.path.join(self.version_info_dir, os.path.basename(release_note)))

        # if os.path.exists(self.ap_version_log):
            # shutil.copy2(self.ap_version_log, os.path.join(self.version_info_dir, os.path.basename(self.ap_version_log)))

        # shutil.copy2(self.massage_file,os.path.join(self.version_info_dir, os.path.basename(massage_file)))
        # self.repo.update_cp_version(self.cp_version_file, os.path.join(self.version_info_dir, os.path.basename(self.cp_version_log)))

        for board, build_cmd in zip(self.board_list, self.borad_build_cmd):
            self.repo.git_clean()
            try:
                build_controller.build(self.build_root_dir, cmd = build_cmd)
                build_controller.send_email(self.build_root_dir, owner,os.path.join(self.release_dist_dir,file_name),board)

                kill_winproc("mingw32-make.exe",'cmake.exe',"make.exe", 'armcc.exe',  'wtee.exe')

                if board in self.board_list[0] and build_controller.build_res in "FAIL":
                    logger.info(self.loacal_dist_dir,"build fail")
                    return self.loacal_dist_dir

                self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir)
                self.copy_sdk_files_to_release_dir(self.download_tool_images_dir_d[board], "cus_evb", self.build_root_dir)
                archive_file = os.path.join(self.loacal_build_dir_d[board], "ASR_CRANE_EVB_A0_16MB.zip")
                dist_dir = self.download_tool_images_dir_d[board]
                zip_tool.unpack_files_from_archive(archive_file, dist_dir, "dsp.bin","rf.bin","ReliableData.bin")
            except Exception, e:
                logger.error(e)

        if os.path.exists(self.sdk_release_notes_file) and self.repo.release_branch == "master":
            shutil.copy2(self.sdk_release_notes_file, os.path.join(self.version_info_dir, os.path.basename(self.sdk_release_notes_file)))

        download_controller.update_download_tool()
        for board in self.board_list:
            try:
                root_dir = self.download_tool_images_dir_d[board]
                images = [os.path.join(root_dir, _file) for _file in os.listdir(root_dir)]
                download_controller.prepare_download_tool(images)
                download_controller.release_download_tool(os.path.basename(self.loacal_dist_dir), board, dist_dir = self.download_tool_dir_d[board])
            except Exception, e:
                logger.error(e)
        build_controller.copy(self.loacal_dist_dir, release_dist)

        logger.info("old_cp_version: %s"%(old_cp_version))
        logger.info("new_cp_version: %s"%(self.cp_version))
        if self.cp_version not in old_cp_version:
            to_address = 'yuanzhizheng@asrmicro.com'
            subject = "%s RELEASE"%self.cp_version
            msg = r"Hi %s, %s build done! Binary dir: %s"%(to_address.split("@")[0],self.cp_version,release_dist)
            send_email_tool(to_address, subject.upper(), msg)
        self.trigger_auto_test(release_dist)
        self.repo.git_clean()
        return self.loacal_dist_dir

    def trigger_auto_test(self, dist_dir, board = "crane_evb_z2"):
        try:
            sdk_tool_abs_dir = os.path.join(dist_dir,board,"download_tool")
            sdk_tool_abs_path = os.listdir(sdk_tool_abs_dir)
            if sdk_tool_abs_path:
                sdk_tool_abs_path = os.path.join(sdk_tool_abs_dir,sdk_tool_abs_path[0])
            else:
                sdk_tool_abs_path = None
            mdb_txt_file_dir = os.path.join(dist_dir,board)
            logger.info(mdb_txt_file_dir)
            for _file in os.listdir(mdb_txt_file_dir):
                if "MDB.TXT" in _file.upper():
                    mdb_txt_file_abs_path = os.path.join(mdb_txt_file_dir,_file)
                    break
            else:
                mdb_txt_file_abs_path = None
            logger.info("sdk_tool:", sdk_tool_abs_path)
            logger.info("mdb path:", mdb_txt_file_abs_path)
            logger.info("test type: ", "evb_customer")
            trigger_test(sdk_tool_abs_path,mdb_txt_file_abs_path,"evb_customer")
        except Exception,e:
            logger.info(e)



class autoRelease(ThreadBase):
    def __init__(self,cfg, release_event):
        super(autoRelease,self).__init__()
        self.cur_crane = cfg.cur_crane
        self.dist_dir = cfg.dist_dir

        self.cur_crane_cus = cfg.cur_crane_cus
        self.release_dist_dir = cfg.release_dist_dir

        self.board_list = cfg.BOARD_LIST[:]

        self.today_release_flag = threading.Event()
        self.release_event = release_event

    def get_release_version(self, root_dir, dist_dir, target = "crane_d"):
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

    def CHECK_DSP_VERSION(self, dsp_version):
        '''CRANE_CAT1GSM_L1_1.053.001 , Feb 29 2020 03:40:50'''
        match = re.findall("(CRANE_.*? ,.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])",dsp_version)
        if match and "\00" not in match[0]:
            return match[0]
        else:
            return "can not match dsp version".upper()


    def send_release_email(self, version_file, customer_file = None):
        to_address = "GR-Modem-SV-Report@asrmicro.com,SW_QA@asrmicro.com,SW_Managers@asrmicro.com,SW_CV@asrmicro.com,crane_sw_mmi_group@asrmicro.com"
        version_fname = os.path.basename(version_file)
        subject = email_subject%version_fname.upper()
        _match = re.findall(repo.verion_name+"[0-9]+",version_fname)
        assert _match,"file name can not match"
        version = _match[0]

        cp_version_file = os.path.join(version_file,"version_info","cp_version.txt")
        with open(cp_version_file) as obj:
            cp_version = obj.read()
        dsp_version_file = os.path.join(version_file,"version_info","dsp_version.txt")
        with open(dsp_version_file) as obj:
            dsp_version = obj.read()
        logger.info(dsp_version)
        dsp_version = self.CHECK_DSP_VERSION(dsp_version)

        cp_version_file = os.path.join(customer_file,"version_info","release_cp_version.txt")
        with open(cp_version_file) as obj:
            cp_version_cus = obj.read()

        dsp_version_file = os.path.join(customer_file,"version_info","release_dsp_version.txt")
        with open(dsp_version_file) as obj:
            dsp_version_cus = obj.read()
        logger.info(dsp_version_cus)
        dsp_version_cus = self.CHECK_DSP_VERSION(dsp_version_cus)
        if customer_file:
            msg = email_msg_with_cus.format(version.upper(), cp_version, dsp_version, version_fname, cp_version_cus, dsp_version_cus, customer_file)
        else:
            msg = email_msg.format(version.upper(), cp_version, dsp_version, version_fname)
        logger.info(subject)
        logger.info(msg)
        send_email_tool(to_address,subject,msg)



    def run(self):
        while self._running:
            self.release_event.wait()
            self.release_event.clear()
            version_file = self.get_release_version(self.cur_crane, self.dist_dir, repo.verion_name)
            if not version_file:
                continue
            logger.info(version_file)
            cp_version_file = os.path.join(version_file,"version_info", "cp_version.txt")
            with open(cp_version_file) as obj:
                cp_version = obj.read()
            ap_version_file = os.path.join(version_file,"version_info", "ap_version.txt")
            with open(ap_version_file) as obj:
                ap_version = obj.read()
            _match = re.findall("MINIGUI_SDK_[0-9]+",cp_version)
            assert _match,"cp_version can not match"
            cp_version_sdk = _match[0]
            release_name = "_".join([cp_version_sdk, ap_version])
            download_controller.update_download_tool()
            self.today_release_flag.set()
            for board in self.board_list:
                root_dir = os.path.join(version_file, board, "cp_images")
                images = [os.path.join(root_dir, _file) for _file in os.listdir(root_dir)]
                download_controller.prepare_download_tool(images,board)
                download_controller.release_download_tool(release_name, board, dist_dir = os.path.join(self.dist_dir,"download_tool", board))

            cus_version_file = self.get_release_version(self.cur_crane_cus, self.release_dist_dir, repo_cus.verion_name)
            cus_version_file = os.path.join(self.release_dist_dir,os.path.basename(cus_version_file))

            self.send_release_email(version_file, cus_version_file)

            # trigger dailybuild test
            try:
                board = "crane_evb_z2"
                sdk_tool_abs_path = download_controller.download_tool_dict.get(board)
                mdb_txt_file_dir = os.path.join(self.dist_dir,os.path.basename(version_file),board)
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

            '''
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
            '''

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
        self.git_list = []

    def add_git_push(self,git_obj):
        self.git_list.append(git_obj)

    def run(self):
        while self._running:
            for git_obj in self.git_list:
                try:
                    git_obj.git_push()
                except Exception,e:
                    logger.error(e)
            time.sleep(10)


class autoCleanOverdueDir(ThreadBase):
    def __init__(self, logger):
        self.log = logger
        super(autoCleanOverdueDir,self).__init__()

    def clean_overdue_dir(self, dir,del_time,target_dir = '',isdir = True):
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

    def run(self):
        while self._running:
            try:
                now = datetime.datetime.today()
                if now.minute > 1 or now.hour != 2:
                    continue
                self.clean_overdue_dir(r"E:\crane_dailybuild",5,target_dir = 'crane_git_')
                self.clean_overdue_dir(cfg.download_tool_dir,5,target_dir = 'MINIGUI_SDK_')
                self.clean_overdue_dir(cfg.download_tool_dir,5,target_dir = 'CRANE_RELEASE_')
                self.clean_overdue_dir(cfg.cp_sdk_dir,5,target_dir = 'ASR3601_MINIGUI_')
                self.clean_overdue_dir("D:\crane_cus",5,target_dir = 'crane_release_')
                time.sleep(10)
            except KeyboardInterrupt:
                self.log.info('clean_overdue_dir exit')
                self._running = False
            except:
                pass

class autoBuild(ThreadBase):
    def __init__(self,logger):
        super(autoBuild,self).__init__()
        self.log = logger
        self.build_list = []

    def add_build(self, build_obj):
        self.build_list.append(build_obj)

    def run(self):
        while self._running:
            try:
                for build_obj in self.build_list:
                    if build_obj.condition():
                        build_obj.build()
                time.sleep(10)
            except KeyboardInterrupt:
                self.log.info('autoBuild exit')
                self.terminate()
            except Exception,e:
                self.log.error(e)

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
cfg = config()

if __name__ == "__main__":
    root_dir = os.getcwd()
    logger = myLogger("build_release")
    prepare_system_start()
    log_file = os.path.join(cfg.log_dir,"log_%s.txt"%time.strftime("%Y%m%d_%H%M%S"))
    zip_tool = zipTool()

    logger.resetLogFile(log_file)
    logger.debug(cfg)
    repo = myRepo(logger, cfg.version_log, cfg.cur_crane)
    repo.update_cp_version(os.path.join(cfg.cur_crane,cfg.cp_version_file),cfg.cp_version_log)
    repo_cus = cusRepo(logger, cfg)
    repo_cus.update_cp_version(os.path.join(cfg.cur_crane_cus,"evb","src",cfg.cp_version_file),cfg.release_cp_version_log)


    build_controller = buildController(cfg)
    download_controller = downloadToolController(cfg, logger)
    # download_controller.update_download_tool()

    auto_daily_build_cls = dailyBuild(cfg, repo)
    auto_cus_build_cls = cusbuild(cfg, repo_cus)

    cp_sdk_cls = gitPushCpDailyBuild(cfg,logger)
    dsp_cls = gitPushDspDailyBuild(cfg,logger)
    cus_sdk_cls = gitPushCusSDK(cfg,logger)

    # release tast
    auto_release_task = autoRelease(cfg, RELEASE_EVENT)

    # auto push task
    auto_push_cp_task = autoPush()
    auto_push_cp_task.add_git_push(dsp_cls)
    auto_push_cp_task.add_git_push(cp_sdk_cls)
    auto_push_cp_task.add_git_push(cus_sdk_cls)

    # auto build task
    auto_build_task = autoBuild(logger)
    auto_build_task.add_build(auto_daily_build_cls)
    auto_build_task.add_build(auto_cus_build_cls)

    # auto clean task
    auto_clean_overdue_dir_task = autoCleanOverdueDir(logger)

    cp_sdk_cls.git_push()

    # task start
    for _task in [auto_clean_overdue_dir_task, auto_release_task, auto_push_cp_task, auto_build_task]:
        _task.start()

    logger.info("**********************start**********************")
    while 1:
        try:
            now = datetime.datetime.today()
            if now.hour == 0 and now.minute == 0 and now.second == 0:
                auto_release_task.today_release_flag.clear()
                time.sleep(1)

            if now.hour == 7 and now.minute == 45 and now.second == 0:
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


