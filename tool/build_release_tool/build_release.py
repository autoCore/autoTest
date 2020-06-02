#!usr/bin/env python

import sys
import os
import time
import datetime

from util import *
from git_push_cp import *

from send_email import send_email_tool
from ftp import ftp_upload_file
from TriggerTest import trigger_test
from myrepo import DailyRepo, CusRepo
from util import config, copy
from build import DailyBuild, CusBuild
from download_tool import DownloadToolController


reload(sys)
sys.setdefaultencoding("utf-8")

email_subject = "CRANE PHONE: AUTO RELEASE %s"
email_msg_with_cus = r"""
GUI VERSION: {0}
CP VERSION: {1}
DSP VERSION: {2}

NORMAL VERSION(SINGLE and DUAL SIM):
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\crane_evb_z2
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\crane_evb_z2\download_tool

BIRD PHONE VERSION:
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\bird_phone
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\bird_phone\download_tool

VISENK PHONE VERSION:
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\visenk_phone
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\visenk_phone\download_tool

CRANEG VERSION:
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\crane_lwg
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\crane_lwg\download_tool


CUSTOMER RELEASE:
CP VERSION: {4}
DSP VERSION: {5}

RELEASE VERSION: {6}
"""


class autoRelease(ThreadBase):
    def __init__(self, _cfg, release_event):
        super(autoRelease, self).__init__()
        self.log = MyLogger(self.__class__.__name__)
        self.cur_crane = _cfg.cur_crane
        self.dist_dir = _cfg.dist_dir

        self.cur_crane_cus = _cfg.cur_crane_cus
        self.release_dist_dir = _cfg.release_dist_dir


        self.today_release_flag = threading.Event()
        self.release_event = release_event


    def get_release_version(self, _root_dir, dist_dir, target="crane_d"):
        _root_dir = os.path.dirname(_root_dir)
        dailybuild_list = [_file for _file in os.listdir(_root_dir) if _file.startswith(target)]
        dailybuild_list.sort(key=lambda fn: os.path.getmtime(os.path.join(_root_dir,fn)))
        for file_name in dailybuild_list[::-1]:
            self.log.info(file_name)
            dist = os.path.join(dist_dir, file_name)
            if os.path.exists(dist):
                self.log.info(dist)
                return os.path.join(_root_dir,file_name)
        else:
            return None

    @staticmethod
    def CHECK_DSP_VERSION(dsp_version):
        """CRANE_CAT1GSM_L1_1.053.001 , Feb 29 2020 03:40:50"""
        match = re.findall("(CRANE_.*? ,.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])", dsp_version)
        if match and "\00" not in match[0]:
            return match[0]
        else:
            return "can not match dsp version".upper()

    def send_release_email(self, version_file, customer_file=None):
        to_address = "GR-Modem-SV-Report@asrmicro.com,SW_QA@asrmicro.com,SW_Managers@asrmicro.com,SW_CV@asrmicro.com," \
                     "crane_sw_mmi_group@asrmicro.com "
        version_fname = os.path.basename(version_file)
        subject = email_subject % version_fname.upper()
        _match = re.findall(repo.verion_name + "[0-9]+", version_fname)
        assert _match, "file name can not match"
        version = _match[0]

        cp_version_file = os.path.join(version_file, "version_info", "cp_version.txt")
        with open(cp_version_file) as obj:
            cp_version = obj.read()
        dsp_version_file = os.path.join(version_file, "version_info", "dsp_version.txt")
        with open(dsp_version_file) as obj:
            dsp_version = obj.read()
        self.log.info(dsp_version)
        dsp_version = self.CHECK_DSP_VERSION(dsp_version)

        cp_version_file = os.path.join(customer_file, "version_info", "release_cp_version.txt")
        with open(cp_version_file) as obj:
            cp_version_cus = obj.read()

        dsp_version_file = os.path.join(customer_file, "version_info", "release_dsp_version.txt")
        with open(dsp_version_file) as obj:
            dsp_version_cus = obj.read()
        self.log.info(dsp_version_cus)
        dsp_version_cus = self.CHECK_DSP_VERSION(dsp_version_cus)
        if customer_file:
            msg = email_msg_with_cus.format(version.upper(), cp_version, dsp_version, version_fname, cp_version_cus,
                                            dsp_version_cus, customer_file)
        else:
            msg = email_msg.format(version.upper(), cp_version, dsp_version, version_fname)
        self.log.info(subject)
        self.log.info(msg)
        send_email_tool(to_address, subject, msg)

    def run(self):
        while self._running:
            self.release_event.wait()
            self.release_event.clear()
            version_file = self.get_release_version(self.cur_crane, self.dist_dir, repo.verion_name)
            if not version_file:
                continue
            self.log.info(version_file)
            cp_version_file = os.path.join(version_file, "version_info", "cp_version.txt")
            with open(cp_version_file) as obj:
                cp_version = obj.read()
            ap_version_file = os.path.join(version_file, "version_info", "ap_version.txt")
            with open(ap_version_file) as obj:
                ap_version = obj.read()
            _match = re.findall("MINIGUI_SDK_[0-9]+", cp_version)
            assert _match, "cp_version can not match"
            cp_version_sdk = _match[0]
            release_name = "_".join([cp_version_sdk, ap_version])
            download_controller.update_download_tool()
            self.today_release_flag.set()

            cus_version_file = self.get_release_version(self.cur_crane_cus, self.release_dist_dir, repo_cus.verion_name)
            cus_version_file = os.path.join(self.release_dist_dir, os.path.basename(cus_version_file))

            self.send_release_email(version_file, cus_version_file)

            # trigger dailybuild test
            try:
                board = "crane_evb_z2"
                sdk_tool_abs_path_dir = os.path.join(self.dist_dir, os.path.basename(version_file),
                                                                                      board, "download_tool")
                for _file in os.listdir(sdk_tool_abs_path_dir):
                    if _file.endswith(".zip") and "DOWNLOAD_TOOL" in _file.upper():
                        sdk_tool_abs_path = os.path.join(sdk_tool_abs_path_dir, _file)
                        break
                else:
                    sdk_tool_abs_path = None

                mdb_txt_file_dir = os.path.join(self.dist_dir, os.path.basename(version_file), board)
                for _file in os.listdir(mdb_txt_file_dir):
                    if "MDB.TXT" in _file.upper():
                        mdb_txt_file_abs_path = os.path.join(mdb_txt_file_dir, _file)
                        break
                else:
                    mdb_txt_file_abs_path = None
                self.log.info(sdk_tool_abs_path)
                self.log.info(mdb_txt_file_abs_path)
                trigger_test(sdk_tool_abs_path, mdb_txt_file_abs_path)
            except Exception, e:
                self.log.info(e)

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
                self.log.info(mdb_txt_file_dir)
                for _file in os.listdir(mdb_txt_file_dir):
                    if "MDB.TXT" in _file.upper():
                        mdb_txt_file_abs_path = os.path.join(mdb_txt_file_dir,_file)
                        break
                else:
                    mdb_txt_file_abs_path = None
                self.log.info(sdk_tool_abs_path,mdb_txt_file_abs_path,"evb_customer")
                trigger_test(sdk_tool_abs_path,mdb_txt_file_abs_path,"evb_customer")
            except Exception,e:
                self.log.info(e)


            try:
                lib_src = os.path.join(version_file, "crane_evb_z2", "rel_lib")
                self.log.info(lib_src, os.path.basename(version_file))
                zip_tool.make_archive_e(lib_src, "zip", lib_src)
                time.sleep(5)
                ftp_upload_file(lib_src + ".zip", os.path.basename(version_file))
            except Exception, e:
                self.log.info(e)
            '''


class autoPush(ThreadBase):
    def __init__(self):
        super(autoPush, self).__init__()
        self.git_list = []
        self.log = MyLogger(self.__class__.__name__)
    def add_git_push(self, git_obj):
        self.git_list.append(git_obj)

    def run(self):
        while self._running:
            for git_obj in self.git_list:
                try:
                    git_obj.git_push_start()
                except Exception,e:
                    self.log.error(e)
            time.sleep(10)


class autoCleanOverdueDir(ThreadBase):
    def __init__(self):
        self.log = MyLogger(self.__class__.__name__)
        super(autoCleanOverdueDir, self).__init__()

    @staticmethod
    def clean_overdue_dir(_dir, del_time, target_dir='', isdir=True):
        os.chdir(_dir)
        listdir = os.listdir(_dir)
        listdir = [d for d in listdir if os.path.isdir(d) and target_dir in d] if isdir else\
                  [f for f in listdir if os.path.isfile(f) and target_dir in f]
        del_t = datetime.timedelta(days=del_time)
        _now = datetime.datetime.now()
        for d in listdir:
            create_time = datetime.datetime.fromtimestamp(os.path.getctime(d))
            if (_now - create_time) > del_t:
                self.log.info("delete %s start..." % d)
                os.system(r"rd /s /q %s" % d)
                self.log.info("delete %s done" % d)

    def run(self):
        while self._running:
            try:
                _now = datetime.datetime.today()
                if _now.minute > 1 or _now.hour != 2:
                    continue
                self.clean_overdue_dir(r"E:\crane_dailybuild", 5, target_dir='crane_d_')
                self.clean_overdue_dir(cfg.download_tool_dir, 5, target_dir='_DOWNLOAD_TOOL_')
                self.clean_overdue_dir(cfg.cp_sdk_dir, 5, target_dir='ASR3601_MINIGUI_')
                self.clean_overdue_dir("D:\crane_cus", 5, target_dir='crane_rc_')
                time.sleep(10)
            except KeyboardInterrupt:
                self.log.info('clean_overdue_dir exit')
                self._running = False
            except:
                pass


class autoBuild(ThreadBase):
    def __init__(self):
        super(autoBuild, self).__init__()
        self.log = MyLogger(self.__class__.__name__)
        self.build_list = []

    def add_build(self, build_obj):
        self.build_list.append(build_obj)

    def run(self):
        while self._running:
            try:
                for build_obj in self.build_list:
                    if build_obj.condition:
                        build_obj.start()
                time.sleep(10)
            except KeyboardInterrupt:
                self.log.info('autoBuild exit')
                self.terminate()
            except Exception, e:
                self.log.error(e)


def prepare_system_start():

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


def create_download_tool_trigger_test():
    version_dir = ''
    dist_dir = r'\\sh2-filer02\Data\FP_RLS\crane_r1_rc'
    board = "crane_evb_z2"
    download_controller.update_download_tool()
    _root_dir = os.path.join(version_dir, board, "cp_images")
    _images = [os.path.join(_root_dir,_file) for _file in os.listdir(_root_dir)]
    download_controller.prepare_download_tool(_images)
    download_controller.release_zip(os.path.dirname(_root_dir))
    download_controller.release_download_tool(os.path.basename(version_dir),
                                            board, "D:\crane_cus\crane_r1_rc_0001_20200529_142934\crane_evb_z2\download_tool")
    release_dist = os.path.join(dist_dir, os.path.basename(version_dir))
    copy(version_dir, release_dist)
    auto_cus_build_cls.trigger_auto_test(release_dist, "evb_customer")


RELEASE_EVENT = threading.Event()

if __name__ == "__main__":
    root_dir = os.getcwd()

    cfg = config()
    cfg.update('config.ini')

    log_file = os.path.join(cfg.log_dir, "log_%s.txt" % time.strftime("%Y%m%d_%H%M%S"))
    rootlogger = MyLogger()
    rootlogger.reset_log_file(log_file)
    rootlogger.enable_print()
    rootlogger.set_level(logging.INFO)

    logger = MyLogger("main")
    prepare_system_start()

    zip_tool = zipTool()

    logger.debug(cfg)
    repo = DailyRepo()
    repo_cus = CusRepo()

    download_controller = DownloadToolController()
    # download_controller.update_download_tool()


    auto_daily_build_cls = DailyBuild(repo)
    auto_cus_build_cls = CusBuild(repo_cus)

    cp_sdk_cls = gitPushCpDailyBuild(cfg)
    dsp_cls = gitPushDspDailyBuild(cfg)
    cus_sdk_cls = gitPushCusSDK(cfg)

    # release task
    auto_release_task = autoRelease(cfg, RELEASE_EVENT)

    # auto push task
    auto_push_cp_task = autoPush()
    auto_push_cp_task.add_git_push(dsp_cls)
    auto_push_cp_task.add_git_push(cp_sdk_cls)
    auto_push_cp_task.add_git_push(cus_sdk_cls)

    # auto build task
    auto_build_task = autoBuild()
    auto_build_task.add_build(auto_cus_build_cls)
    auto_build_task.add_build(auto_daily_build_cls)

    # auto clean task
    auto_clean_overdue_dir_task = autoCleanOverdueDir()

    cp_sdk_cls.git_push_start()

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

            if now.hour == 9 and now.minute == 0 and now.second == 0:
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
            kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')
            sys.exit()
        except Exception, e:
            logger.error(e)
            kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')
            auto_clean_overdue_dir_task.terminate()
            auto_release_task.terminate()
            auto_push_cp_task.terminate()
            auto_build_task.terminate()
