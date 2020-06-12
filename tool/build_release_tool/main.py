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
from myrepo import *
from util import config, copy
from build import *
from download_tool import DownloadToolController


reload(sys)
sys.setdefaultencoding("utf-8")

email_subject = "CRANE PHONE: AUTO RELEASE %s"
email_msg_with_cus = r"""
GUI VERSION: {0}
SDK VERSION: {1}
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


CUSTOMER VERSION RELEASE:
SDK VERSION: {4}
DSP VERSION: {5}
RELEASE VERSION: {6}


CRANEG VERSION RELEASE:
SDK VERSION: {7}
DSP VERSION: {8}
RELEASE VERSION: {9}

"""


class autoRelease(ThreadBase):
    def __init__(self, _cfg, release_event):
        super(autoRelease, self).__init__()
        self.log = MyLogger(self.__class__.__name__)
        self.cur_crane = repo.git_root_dir#_cfg.cur_crane
        self.dist_dir = repo.release_dist_dir#_cfg.dist_dir

        self.tmp = _cfg.tmp_dir

        self.cur_crane_cus = repo_cus.git_root_dir#_cfg.cur_crane_cus
        self.release_dist_dir = repo_cus.release_dist_dir#_cfg.release_dist_dir

        # self.craneg_build_dir = r"D:\craneg_dailybuild\crane"
        # self.craneg_release_dir = r"\\sh2-filer02\Data\FP_RLS\craneG_dailybuild"
        self.craneg_build_dir = craneg_repo.git_root_dir #r"D:\craneg_dailybuild\crane"
        self.craneg_release_dir = craneg_repo.release_dist_dir #r"\\sh2-filer02\Data\FP_RLS\craneG_dailybuild"

        self.zip_tool = zipTool()
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
        match = re.findall("(CRANE.*? ,.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])", dsp_version)
        if match and "\00" not in match[0]:
            return match[0]
        else:
            return "can not match dsp version".upper()

    @staticmethod
    def get_version(file_name):
        with open(file_name) as obj:
            _version = obj.read()
        return _version

    def send_release_email(self, version_file, customer_file, craneg_file):
        to_address = "GR-Modem-SV-Report@asrmicro.com,SW_QA@asrmicro.com,SW_Managers@asrmicro.com,SW_CV@asrmicro.com," \
                     "crane_sw_mmi_group@asrmicro.com "
        version_fname = os.path.basename(version_file)
        subject = email_subject % version_fname.upper()
        _match = re.findall(repo.verion_name + "[0-9]+", version_fname)
        assert _match, "file name can not match"
        version = _match[0]

        sdk_version_file = os.path.join(version_file, "version_info", "cp_version.txt")
        crane_sdk_version = self.get_version(sdk_version_file)

        dsp_version_file = os.path.join(version_file, "version_info", "dsp_version.txt")
        crane_dsp_version = self.CHECK_DSP_VERSION(self.get_version(dsp_version_file))

        sdk_version_file = os.path.join(customer_file, "version_info", "release_cp_version.txt")
        cus_crane_sdk_version = self.get_version(sdk_version_file)

        dsp_version_file = os.path.join(customer_file, "version_info", "release_dsp_version.txt")
        cus_crane_dsp_version = self.CHECK_DSP_VERSION(self.get_version(dsp_version_file))

        sdk_version_file = os.path.join(craneg_file, "version_info", "crang_cp_version.txt")
        craneg_sdk_version = self.get_version(sdk_version_file)

        dsp_version_file = os.path.join(craneg_file, "version_info", "crang_dsp_version.txt")
        craneg_dsp_version = self.CHECK_DSP_VERSION(self.get_version(dsp_version_file))


        msg = email_msg_with_cus.format(version.upper(), crane_sdk_version, crane_dsp_version, version_fname,\
                                        cus_crane_sdk_version, cus_crane_dsp_version, customer_file,\
                                        craneg_sdk_version, craneg_dsp_version, craneg_file)

        self.log.info(subject)
        self.log.info(msg)
        send_email_tool(to_address, subject, msg)

    def trigger_auto_test(self, _version_file, project_name=None, board="crane_evb_z2"):
        try:
            sdk_tool_abs_path_dir = os.path.join(_version_file, board, "download_tool")
            for _file in os.listdir(sdk_tool_abs_path_dir):
                if _file.endswith(".zip") and "DOWNLOAD_TOOL" in _file.upper() and "DCXO" not in _file:
                    sdk_tool_abs_path = os.path.join(sdk_tool_abs_path_dir, _file)
                    break
            else:
                sdk_tool_abs_path = None

            mdb_txt_file_dir = os.path.join(_version_file, board)
            for _file in os.listdir(mdb_txt_file_dir):
                if "MDB.TXT" in _file.upper():
                    mdb_txt_file_abs_path = os.path.join(mdb_txt_file_dir, _file)
                    break
            else:
                mdb_txt_file_abs_path = None

            self.log.info(sdk_tool_abs_path)
            self.log.info(mdb_txt_file_abs_path)
            trigger_test(sdk_tool_abs_path, mdb_txt_file_abs_path,project_name)
        except Exception, e:
            self.log.info(e)

    def ftp_upload(self, _version_file):
        try:
            lib_src = os.path.join(_version_file, "crane_evb_z2", "rel_lib")
            self.log.info(lib_src, os.path.basename(_version_file))
            dist_dir = os.path.join(self.tmp, "rel_lib")
            self.zip_tool.make_archive_e(dist_dir, "zip", lib_src)
            ftp_upload_file(dist_dir + ".zip", os.path.basename(_version_file))
        except Exception, e:
            self.log.info(e)

    def run(self):
        self.log.info(self.__class__.__name__, "start...")
        while self._running:
            self.release_event.wait()
            self.release_event.clear()
            version_file = self.get_release_version(self.cur_crane, self.dist_dir, "crane_d_")
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
            # download_controller.update_download_tool()
            self.today_release_flag.set()

            cus_version_file = self.get_release_version(self.cur_crane_cus, self.release_dist_dir, "crane_rc_")
            self.log.info(cus_version_file)
            cus_version_file = os.path.join(self.release_dist_dir, os.path.basename(cus_version_file))

            craneg_version_file = self.get_release_version(self.craneg_build_dir, self.craneg_release_dir, "craneg_d_")
            self.log.info(craneg_version_file)
            craneg_version_file = os.path.join(self.craneg_release_dir, os.path.basename(craneg_version_file))


            self.send_release_email(version_file, cus_version_file, craneg_version_file)

            # trigger dailybuild test
            self.trigger_auto_test(version_file)
            self.trigger_auto_test(craneg_version_file, "craneg_evb", "craneg_evb")

            # self.trigger_auto_test(cus_version_file, "evb_customer")


            # self.ftp_upload(version_file)



class autoPush(ThreadBase):
    def __init__(self):
        super(autoPush, self).__init__()
        self.git_list = []
        self.log = MyLogger(self.__class__.__name__)
    def add_git_push(self, git_obj):
        self.git_list.append(git_obj)

    def run(self):
        self.log.info(self.__class__.__name__, "start...")
        while self._running:
            for git_obj in self.git_list:
                try:
                    git_obj.git_push_start()
                except Exception,e:
                    self.log.error(e)
            time.sleep(10)


class autoCleanOverdueDir(ThreadBase):
    def __init__(self):
        super(autoCleanOverdueDir, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

    def clean_overdue_dir(self, _dir, del_time, target_dir='', isdir=True):
        listdir = os.listdir(_dir)
        if isdir:
            listdir = [os.path.join(_dir,d) for d in listdir if os.path.isdir(os.path.join(_dir,d)) and target_dir in d]
        else:
            listdir = [os.path.join(_dir,f) for f in listdir if os.path.isfile(os.path.join(_dir,f)) and target_dir in f]
        # self.log.info(listdir)
        del_t = datetime.timedelta(days=del_time)
        _now = datetime.datetime.now()
        for d in listdir:
            create_time = datetime.datetime.fromtimestamp(os.path.getctime(d))
            if (_now - create_time) > del_t:
                self.log.info("delete %s start..." % d)
                os.system(r"rd /s /q %s" % d)
                self.log.info("delete %s done" % d)

    def run(self):
        self.log.info(self.__class__.__name__, "start...")
        while self._running:
            try:
                _now = datetime.datetime.today()
                if _now.hour == 1 and _now.minute == 0 and _now.second <= 10:
                    self.clean_overdue_dir(cfg.download_tool_dir, 1, target_dir='_DOWNLOAD_TOOL_')
                    self.clean_overdue_dir(cfg.cp_sdk_dir, 7, target_dir='ASR3601_MINIGUI_')
                    self.clean_overdue_dir(cfg.cp_sdk_dir, 7, target_dir='ASR3603_MINIGUI_')
                    for _repo in [repo, craneg_repo]:
                        self.clean_overdue_dir(os.path.dirname(_repo.git_root_dir), 10, target_dir=_repo.verion_name)
                time.sleep(10)
            except KeyboardInterrupt:
                self.log.info('clean_overdue_dir exit')
                self._running = False
            except Exception,e:
                self.log.error(e)


class autoBuild(ThreadBase):
    def __init__(self):
        super(autoBuild, self).__init__()
        self.log = MyLogger(self.__class__.__name__)
        self.build_list = []

    def add_build(self, build_obj):
        self.build_list.append(build_obj)

    def run(self):
        self.log.info(self.__class__.__name__, "start...")
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

    if not os.path.exists(cfg.version_file_dir):
        os.mkdir(cfg.version_file_dir)

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
    version_dir = "D:\crane_cus\crane_r1_rc_0001_20200529_142934"
    dist_dir = r'\\sh2-filer02\Data\FP_RLS\crane_r1_rc'
    board = "crane_evb_z2"

    download_tool_dir = os.path.join(version_dir, board, "download_tool")
    download_controller.update_download_tool()
    _root_dir = os.path.join(version_dir, board, "cp_images")
    _images = [os.path.join(_root_dir,_file) for _file in os.listdir(_root_dir)]
    download_controller.prepare_download_tool(_images)
    download_controller.release_zip(os.path.dirname(_root_dir))
    download_controller.release_download_tool(os.path.basename(version_dir),
                                            board, download_tool_dir)
    release_dist = os.path.join(dist_dir, os.path.basename(version_dir))
    copy(version_dir, release_dist)
    auto_cus_build_cls.trigger_auto_test(release_dist, "evb_customer")


RELEASE_EVENT = threading.Event()

if __name__ == "__main__":
    root_dir = os.getcwd()

    cfg = config()
    cfg.update('config.ini')

    rootlogger = MyLogger()

    rootlogger.enable_print()
    rootlogger.set_level(logging.INFO)

    logger = MyLogger("main")
    prepare_system_start()

    log_file = os.path.join(cfg.log_dir, "log_%s.txt" % time.strftime("%Y%m%d_%H%M%S"))
    rootlogger.reset_log_file(log_file)

    logger.debug(cfg)
    repo = CraneRepo()
    craneg_repo = craneGRepo()
    repo_cus = CusRepo()
    r1_rc_repo = cusR1RCRepo()

    download_controller = DownloadToolController()
    # download_controller.update_download_tool()


    auto_daily_build_cls = CraneDailyBuild(repo, RELEASE_EVENT)
    craneg_build_cls = CraneGDailyBuild(craneg_repo, RELEASE_EVENT)
    auto_cus_build_cls = CusBuild(repo_cus)
    auto_r1_rc_build_cls = CusR1RCBuild(r1_rc_repo)

    cp_sdk_cls = gitPushCraneSDK()
    craneg_sdk_cls = gitPushCraneGSDK()
    cus_sdk_cls = gitPushCusSDK()
    cus_r1_rc_sdk_cls = gitPushR1RCSDK()

    crane_dsp_cls = gitPushCraneDsp()
    crane_dsp_dcxo_cls = gitPushCraneDCXODsp()
    craneg_dsp_cls = gitPushCraneGDsp()
    # release task
    auto_release_task = autoRelease(cfg, RELEASE_EVENT)

    # auto push task
    auto_push_cp_task = autoPush()
    auto_push_cp_task.add_git_push(crane_dsp_cls)
    auto_push_cp_task.add_git_push(craneg_dsp_cls)
    auto_push_cp_task.add_git_push(crane_dsp_dcxo_cls)
    auto_push_cp_task.add_git_push(craneg_sdk_cls)
    auto_push_cp_task.add_git_push(cp_sdk_cls)
    auto_push_cp_task.add_git_push(cus_sdk_cls)
    auto_push_cp_task.add_git_push(cus_r1_rc_sdk_cls)

    # auto build task
    auto_build_task = autoBuild()
    auto_build_task.add_build(auto_r1_rc_build_cls)
    auto_build_task.add_build(auto_cus_build_cls)
    auto_build_task.add_build(craneg_build_cls)
    auto_build_task.add_build(auto_daily_build_cls)

    # auto clean task
    auto_clean_overdue_dir_task = autoCleanOverdueDir()

    cp_sdk_cls.git_push_start()
    craneg_sdk_cls.git_push_start()
    cus_r1_rc_sdk_cls.git_push_start()
    cus_sdk_cls.git_push_start()
    crane_dsp_dcxo_cls.git_push_start()
    craneg_dsp_cls.git_push_start()
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
