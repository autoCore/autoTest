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
                        self.clean_overdue_dir(os.path.dirname(_repo.git_root_dir), 14, target_dir=_repo.verion_name)
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

    # auto build task
    auto_build_task = autoBuild()

    # auto clean task
    auto_clean_overdue_dir_task = autoCleanOverdueDir()
    # =====================================================

    # crane external build
    external_repo = CraneExternalSRepo()
    external_daily_build_cls = ExternalBuild(external_repo)
    auto_build_task.add_build(external_daily_build_cls)
    auto_clean_overdue_dir_task.add_repo(external_repo)

    # crane ft
    ft_repo = cusFTRepo()
    auto_ft_cls = CusFTBuild(ft_repo)
    auto_build_task.add_build(auto_ft_cls)
    auto_clean_overdue_dir_task.add_repo(ft_repo)

    # task start
    task_list = []
    # task_list.append(auto_clean_overdue_dir_task)
    task_list.append(auto_build_task)
    for _task in task_list:
        _task.start()

    logger.info("**********************start**********************")
    while 1:
        try:
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
