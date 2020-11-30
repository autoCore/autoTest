#!usr/bin/env python

import sys
import os
import time
import datetime
import shutil

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

email_subject = "CRANE PHONE AUTO RELEASE"

class autoRelease(ThreadBase):
    def __init__(self, _cfg, release_event):
        super(autoRelease, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.root_dir = os.getcwd()
        self.email_massage_file = os.path.join(self.root_dir,"email_massage.txt")
        self.tmp = _cfg.tmp_dir

        self.repo_list = [repo, craneg_repo, repo_cus, repo_cus_sdk009, r2_rc_repo, cranem_repo, cranem_dm_repo]

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
                return os.path.join(dist_dir,file_name)
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

    @staticmethod
    def get_ap_version(file_name):
        _match = re.findall("(.*_[0-9][0-9][0-9][0-9])_", file_name)
        assert _match, "file name can not match"
        return _match[0]

    def send_release_email(self, *release_files):
        to_address = "GR-Modem-SV-Report@asrmicro.com,SW_QA@asrmicro.com,SW_Managers@asrmicro.com,SW_CV@asrmicro.com," \
                     "crane_sw_mmi_group@asrmicro.com "
        # to_address = "binwu@asrmicro.com"
        massage_format_list = []
        subject = email_subject

        for version_file in release_files:
            ap_version_file = os.path.join(version_file, "version_info", "ap_version.txt")
            massage_format_list.append(self.get_version(ap_version_file)) #{0}

            sdk_version_file = os.path.join(version_file, "version_info", "cp_version.txt")
            crane_sdk_version = self.get_version(sdk_version_file)
            massage_format_list.append(self.get_version(sdk_version_file)) #{1}

            dsp_version_file = os.path.join(version_file, "version_info", "dsp_version.txt")
            massage_format_list.append(self.CHECK_DSP_VERSION(self.get_version(dsp_version_file))) #{2}

            massage_format_list.append(version_file) #{3}

        with open(self.email_massage_file) as obj:
            email_msg_with_cus_1 = obj.read()
        msg = email_msg_with_cus_1.format(*massage_format_list)
        self.log.info(subject)
        self.log.info(msg)
        send_email_tool(to_address, subject, msg)


    def trigger_auto_test(self, _version_file, project_name=None, board="crane_evb_z2"):
        try:
            sdk_tool_abs_path_dir = os.path.join(_version_file, board, "download_tool")
            for _file in os.listdir(sdk_tool_abs_path_dir):
                if _file.endswith(".zip") and "DOWNLOAD_TOOL" in _file.upper():
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
            with ziptool_mutex:
                self.zip_tool.make_archive_e(dist_dir, "zip", lib_src)
            ftp_upload_file(dist_dir + ".zip", os.path.basename(_version_file))
        except Exception, e:
            self.log.info(e)

    def run(self):
        self.log.info(self.__class__.__name__, "start...")
        while self._running:
            self.release_event.wait()
            self.release_event.clear()

            self.today_release_flag.set()

            release_files = []
            for _repo in self.repo_list:
                _version_file = self.get_release_version(_repo.git_root_dir, _repo.release_dist_dir,_repo.verion_name)
                self.log.info(_version_file)
                release_files.append(_version_file)

            self.send_release_email(*release_files)

            version_file = release_files[0]
            craneg_version_file = release_files[1]
            # trigger dailybuild test
            self.trigger_auto_test(version_file)

            # self.trigger_auto_test(craneg_version_file, project_name="craneg_evb", board="craneg_evb_z2")
            self.trigger_auto_test(craneg_version_file, project_name="craneg_evb", board="craneg_evb_z2_from_crane")

            # self.trigger_auto_test(craneg_version_file, project_name="craneg_a0_evb", board="craneg_evb_a0")
            self.trigger_auto_test(craneg_version_file, project_name="craneg_a0_evb", board="craneg_evb_a0_from_crane")

            self.trigger_auto_test(version_file, project_name="crane_evb_z2_fwp",  board="crane_evb_z2_fwp")

            self.trigger_auto_test(version_file, project_name="crane_evb_z2_dcxo",  board="crane_evb_z2_dcxo")

            # self.trigger_auto_test(cus_version_file, project_name="crane_evb_z2_fwp_rc",  board="crane_evb_z2_fwp")

            # self.ftp_upload(version_file)


class autoPush(ThreadBase):
    def __init__(self):
        super(autoPush, self).__init__()
        self.git_list = []
        self.log = MyLogger(self.__class__.__name__)
    def add_git_push(self, git_obj):
        self.git_list.append(git_obj)

    def get_git_push_list(self):
        return self.git_list

    def clean_git_push_list(self):
        self.git_lis = []

    def run(self):
        self.log.info(self.__class__.__name__)
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
        self._repo_list = []
    
    def add_repo(self, _repo):
        self._repo_list.append(_repo)

    def clear_repo(self):
        self._repo_list = []

    def clean_overdue_dir(self, _dir, del_time, target_dir='', isdir=True):
        listdir = os.listdir(_dir)
        if isdir:
            listdir = [os.path.join(_dir,d) for d in listdir if os.path.isdir(os.path.join(_dir,d)) and target_dir in d]
        else:
            listdir = [os.path.join(_dir,f) for f in listdir if os.path.isfile(os.path.join(_dir,f)) and target_dir in f]
        # self.log.info(listdir)
        listdir.sort(key=lambda fn: os.path.getmtime(fn))
        # self.log.info(listdir)
        del_t = datetime.timedelta(days=del_time)
        _now = datetime.datetime.now()
        for d in listdir[:-2]:
            create_time = datetime.datetime.fromtimestamp(os.path.getctime(d))
            if (_now - create_time) > del_t:
                self.log.info("delete %s start..." % d)
                if os.path.isdir(d):
                    shutil.rmtree(d)
                else:
                    os.remove(d)
                # os.system(r"rd /s /q %s" % d)
                self.log.info("delete %s done" % d)

    def run(self):
        self.log.info(self.__class__.__name__, "start...")
        while self._running:
            try:
                # self.clean_overdue_dir("Y:\craneG_dailybuild", 32, target_dir='craneg_d_')
                # self.clean_overdue_dir("Y:\crane_dailybuild", 32, target_dir='crane_d_')
                _now = datetime.datetime.today()
                if _now.hour == 1 and _now.minute == 0 and _now.second <= 10:
                    self.clean_overdue_dir(cfg.cp_sdk_dir, 0, target_dir='ASR3601_MINIGUI_1.006', isdir=False)
                    self.clean_overdue_dir(cfg.cp_sdk_dir, 0, target_dir='ASR3601_MINIGUI_1.006')

                    self.clean_overdue_dir(cfg.cp_sdk_dir, 0, target_dir='ASR3601_MINIGUI_1.008', isdir=False)
                    self.clean_overdue_dir(cfg.cp_sdk_dir, 0, target_dir='ASR3601_MINIGUI_1.008')

                    self.clean_overdue_dir(cfg.cp_sdk_dir, 0, target_dir='ASR3601_MINIGUI_1.009', isdir=False)
                    self.clean_overdue_dir(cfg.cp_sdk_dir, 0, target_dir='ASR3601_MINIGUI_1.009')

                    self.clean_overdue_dir(cfg.cp_sdk_dir, 0, target_dir='ASR3601_MINIGUI_20')
                    self.clean_overdue_dir(cfg.cp_sdk_dir, 0, target_dir='ASR3601_MINIGUI_20', isdir=False)

                    self.clean_overdue_dir(cfg.cp_sdk_dir, 0, target_dir='ASR3603_MINIGUI_20')
                    self.clean_overdue_dir(cfg.cp_sdk_dir, 0, target_dir='ASR3603_MINIGUI_20', isdir=False)

                    for _repo in self._repo_list:
                        self.clean_overdue_dir(os.path.dirname(_repo.git_root_dir), 16, target_dir=_repo.verion_name)
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
                time.sleep(30)
            except KeyboardInterrupt:
                self.log.info('autoBuild exit')
                self.terminate()
            except Exception, e:
                self.log.error(e)
            finally:
                kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')
        kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')

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

    download_controller = DownloadToolController()

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

    # =====================================================
    # auto push task
    auto_push_task = autoPush()

    # auto build task
    auto_build_task = autoBuild()

    # auto clean task
    auto_clean_overdue_dir_task = autoCleanOverdueDir()
    # =====================================================


    # crane r1_rc
    r1_rc_repo = cusR1RCRepo()
    auto_r1_rc_build_cls = CusR1RCBuild(r1_rc_repo)
    auto_build_task.add_build(auto_r1_rc_build_cls)
    auto_clean_overdue_dir_task.add_repo(r1_rc_repo)

    # crane r2_rc
    r2_rc_repo = cusR2RCRepo()
    auto_r2_rc_cls = CusR2RCSDKBuild(r2_rc_repo)
    auto_build_task.add_build(auto_r2_rc_cls)
    auto_clean_overdue_dir_task.add_repo(r2_rc_repo)

    # crane rc sdk009
    repo_cus_sdk009 = CusMasterSDK009Repo()
    auto_cus_sdk009_build_cls = CusSDK009Build(repo_cus_sdk009)
    auto_build_task.add_build(auto_cus_sdk009_build_cls)
    auto_clean_overdue_dir_task.add_repo(repo_cus_sdk009)

    # crane rc
    repo_cus = CusMasterRepo()
    auto_cus_build_cls = CusBuild(repo_cus)
    auto_build_task.add_build(auto_cus_build_cls)
    auto_clean_overdue_dir_task.add_repo(repo_cus)

    # craneg dailay
    craneg_repo = craneGRepo()
    craneg_build_cls = CraneGDailyBuild(craneg_repo)
    auto_build_task.add_build(craneg_build_cls)
    auto_clean_overdue_dir_task.add_repo(craneg_repo)

    # cranem dailay
    cranem_repo = craneMRepo()
    cranem_build_cls = CraneMDailyBuild(cranem_repo)
    auto_build_task.add_build(cranem_build_cls)
    auto_clean_overdue_dir_task.add_repo(cranem_repo)
 
    # cranem dailay
    cranem_dm_repo = craneMDMRepo()
    cranem_dm_build_cls = CraneMDMDailyBuild(cranem_dm_repo)
    auto_build_task.add_build(cranem_dm_build_cls)
    auto_clean_overdue_dir_task.add_repo(cranem_dm_repo)

    # crane dailay
    repo = CraneRepo()
    auto_daily_build_cls = CraneDailyBuild(repo)
    auto_build_task.add_build(auto_daily_build_cls)
    auto_clean_overdue_dir_task.add_repo(repo)


    # crane dailay sdk auto push
    cp_sdk_cls = gitPushCraneSDK()
    auto_push_task.add_git_push(cp_sdk_cls)

    # craneg dailay sdk auto push
    # craneg_sdk_cls = gitPushCraneGSDK()
    # auto_push_task.add_git_push(craneg_sdk_cls)

    # crane rc sdk auto push
    cus_sdk_cls = gitPushCusSDK()
    auto_push_task.add_git_push(cus_sdk_cls)

    # crane rc sdk009 auto push
    cus_sdk009_cls = gitPushCusSDK009()
    auto_push_task.add_git_push(cus_sdk009_cls)

    # crane r2_rc sdk009 auto push
    cus_r2_rc_sdk009_cls = gitPushR2RCSDK009()
    auto_push_task.add_git_push(cus_r2_rc_sdk009_cls)

    # crane rc sdk auto push
    cus_R2_RC_SDK_cls = gitPushR2RCSDK()
    auto_push_task.add_git_push(cus_R2_RC_SDK_cls)

    # crane r1_rc sdk auto push
    cus_r1_rc_sdk_cls = gitPushR1RCSDK()
    auto_push_task.add_git_push(cus_r1_rc_sdk_cls)

    # crane dailay dsp auto push
    crane_dsp_cls = gitPushCraneDsp()
    auto_push_task.add_git_push(crane_dsp_cls)

    # crane dailay dsp_dcxo auto push
    # crane_dsp_dcxo_cls = gitPushCraneDCXODsp()
    # auto_push_task.add_git_push(crane_dsp_dcxo_cls)

    # craneg dailay dsp auto push
    craneg_dsp_cls = gitPushCraneGDsp()
    auto_push_task.add_git_push(craneg_dsp_cls)

    # cranem dailay dsp auto push
    cranem_dsp_cls = gitPushCraneMDsp()
    auto_push_task.add_git_push(cranem_dsp_cls)

    # download tool auto push
    download_tool = gitPushDownloadTool()
    auto_push_task.add_git_push(download_tool)

    # =====================================================
    # release task
    auto_release_task = autoRelease(cfg, RELEASE_EVENT)
    # =====================================================

    for _git_push_obj in auto_push_task.get_git_push_list():
        _git_push_obj.git_push_start()

    # task start
    task_list = []
    task_list.append(auto_clean_overdue_dir_task)
    task_list.append(auto_release_task)
    task_list.append(auto_push_task)
    task_list.append(auto_build_task)
    for _task in task_list:
        _task.start()

    logger.info("**********************start**********************")
    while 1:
        try:
            now = datetime.datetime.today()
            if now.hour == 0 and now.minute == 0 and now.second == 0:
                auto_daily_build_cls.sdk_update_flag.clear()
                craneg_build_cls.sdk_update_flag.clear()
                cranem_build_cls.sdk_update_flag.clear()
                auto_release_task.today_release_flag.clear()
                time.sleep(1)

            if auto_daily_build_cls.sdk_update_flag.is_set() and craneg_build_cls.sdk_update_flag.is_set() and cranem_build_cls.sdk_update_flag.is_set():
                auto_daily_build_cls.sdk_update_flag.clear()
                craneg_build_cls.sdk_update_flag.clear()
                cranem_build_cls.sdk_update_flag.clear()
                RELEASE_EVENT.set()

            if now.hour == 9 and now.minute == 15 and now.second == 0:
                if not auto_release_task.today_release_flag.is_set():
                    RELEASE_EVENT.set()
                    time.sleep(1)

        except KeyboardInterrupt:
            logger.info("exit: KeyboardInterrupt")
            for _task in task_list:
                _task.terminate()
            os.chdir(root_dir)
            os.system("del *.pyc")
            kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')
            sys.exit()
        except Exception, e:
            logger.error(e)
            kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')
            for _task in task_list:
                _task.terminate()
