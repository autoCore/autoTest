#!usr/bin/env python

import os
import time
import subprocess
import shutil
import threading

from util import MyLogger, copy, kill_win_process, zipTool, load_json
from send_email import send_email_tool
from ftp import ftp_upload_file
from TriggerTest import trigger_test
from download_tool import DownloadToolController

class BuildController(object):
    def __init__(self):
        self.root_dir = os.getcwd()
        self.build_res = None
        self.log = MyLogger(self.__class__.__name__)

        self.git_version_dir = ''

        self.gui_build_log = os.path.join(".", 'build', 'crane_evb_z2', r'gui_build.log')
        self.hal_build_log = os.path.join(".", 'build', 'crane_evb_z2', r'hal_build.log')
        self.cp_build_log = os.path.join(".", 'build', 'crane_evb_z2', r'cp_build.log')
        self.link_log = os.path.join(".", 'build', 'crane_evb_z2', r'fp_link_build.log')
        self.compile_log_dir = os.path.join(self.root_dir, 'tmp', 'compile_log')
        self.zip_tool = zipTool()

    def build(self, cur_dir, build_dir='crane_evb_z2', compile_log='', cmd=''):
        os.chdir(cur_dir)
        self.log.info("%s build start..." % cur_dir)
        # cmd = "autobuild.bat %s> %s"%(build_dir,compile_log)
        if not cmd:
            cmd = "autobuild.bat"
        if compile_log:
            self.compile_log = compile_log
        else:
            self.compile_log = os.path.join(self.compile_log_dir, os.path.basename(self.git_version_dir) + "_compile.txt")
        if not os.path.exists(self.compile_log):
            fob = open(self.compile_log, 'w')
            fob.close()
        try:
            with open(self.compile_log, 'a') as fob:
                prc = subprocess.Popen(cmd, shell=True, stdout=fob)
                ret = prc.wait()
        except Exception, e:
            self.log.error(e)
            self.build_res = "FAIL"
            return
        time.sleep(5)
        if os.path.exists(r"%s\build\%s\crane_evb.elf" % (cur_dir, build_dir)) and os.path.exists(
                r"%s\build\%s\crane_evb.bin" % (cur_dir, build_dir)):
            self.log.info("%s build done" % cur_dir)
            self.build_res = "SUCCESS"
        else:
            self.log.warning("%s build fail" % cur_dir)
            self.build_res = "FAIL"

    def send_email(self, cur_dir, owner, external_dir, board="crane_evb_z2"):
        os.chdir(cur_dir)
        if self.build_res in "FAIL":
            att_file = '@'.join(
                [self.hal_build_log, self.gui_build_log, self.cp_build_log, self.link_log, self.compile_log])
            subject = r"%s %s build result: fail" % (self.__class__.__name__, board)
            msg = r"Hi %s, your patch build fail! Pls check attachment log" % (owner.split("@")[0])
        else:
            att_file = None
            subject = r"%s %s build result: pass" % (self.__class__.__name__, board)
            msg = r"Hi %s, your patch build pass! Binary dir: %s" % (owner.split("@")[0], external_dir)
        to_address = ",".join([owner, 'yuanzhizheng@asrmicro.com'])
        send_email_tool(to_address, subject, msg, att_file)
        self.log.info("send email done")


class BuildBase(object):
    def __init__(self, _repo):
        self._repo = _repo
        self.root_dir = os.getcwd()
        self.log = MyLogger(self.__class__.__name__)
        self.download_controller = DownloadToolController()

        self.xml_file = ''
        self.massage_file = ''
        self.cp_version = ''
        self.dsp_version = ''

        self.loacal_dist_dir = ''
        self.loacal_build_dir_d = {}
        self.download_tool_dir_d = {}
        self.download_tool_images_dir_d = {}

        # self.release_branch = "master"

        self.update()
        self.config()

        # self.print_info()

    def get_config(self):
        pass

    def config(self):
        pass

    def update(self):
        self.get_config()
        self.board_info = self.config_d["boards_info"]
        self.compile_log_dir = os.path.join(self.root_dir, self.config_d["compile_log_dir"])

        # self._repo.update(self.release_branch)

        self.build_root_dir = self._repo.build_root_dir
        self.git_root_dir = self._repo.git_root_dir
        self.release_dist_dir = self._repo.release_dist_dir
        self.manisest_xml_dir = self._repo.manisest_xml_dir

        self.ap_version_log = self._repo.ap_version_log
        self.cp_version_log = self._repo.cp_version_log
        self.dsp_version_log = self._repo.dsp_version_log

        self.cp_version_file = self._repo.sdk_version_file
        self.dsp_bin = self._repo.dsp_version_file

        # self.release_branch = self._repo.branch_name

        self._repo.update_cp_version(self.cp_version_file, self.cp_version_log)


    def prepare_release_dir(self, version_dir):
        self.loacal_dist_dir = version_dir
        os.mkdir(version_dir)
        self.version_info_dir = os.path.join(version_dir, "version_info")
        os.mkdir(self.version_info_dir)
        for board in self.board_list:
            self.loacal_build_dir_d[board] = os.path.join(version_dir, board)
            os.mkdir(self.loacal_build_dir_d[board])
            if board == "no_ui_crane_lib":
                continue
            self.download_tool_dir_d[board] = os.path.join(version_dir, board, "download_tool")
            os.mkdir(self.download_tool_dir_d[board])
            self.download_tool_images_dir_d[board] = os.path.join(version_dir, board, "cp_images")
            os.mkdir(self.download_tool_images_dir_d[board])

    def copy_version_file_to_release_dir(self):
        for _file in [self.xml_file, self.ap_version_log, self.cp_version_log, self.dsp_version_log, self.massage_file]:
            if os.path.exists(_file):
                copy(_file, os.path.join(self.loacal_dist_dir, "version_info", os.path.basename(_file)))

    def copy_build_file_to_release_dir(self, dist_dir, src_dir=None, board = "crane_evb_z2"):
        src_dir = self.build_root_dir
        self.build_images = self.board_info.get(board, {}).get("build_images",[])
        for _file in self.build_images:
            src = os.path.join(src_dir, _file)
            dist = os.path.join(dist_dir, os.path.basename(_file))
            copy(src, dist)

        _zip_file = self.board_info.get(board, {}).get("build_zip_file","")
        self.build_zip_file = os.path.join(self.build_root_dir, _zip_file)
        if os.path.exists(self.build_zip_file):
            copy(self.build_zip_file, os.path.join(dist_dir, os.path.basename(_zip_file)))

        _mdb_file_dir = self.board_info.get(board, {}).get("mdb_file_dir","")
        self.mdb_file_dir = os.path.join(self.build_root_dir, _mdb_file_dir)
        if os.path.exists(self.mdb_file_dir):
            for _file in os.listdir(self.mdb_file_dir):
                if "MDB.TXT" in _file.upper():
                    copy(os.path.join(self.mdb_file_dir, _file), os.path.join(dist_dir, _file))
                    break

    def copy_sdk_files_to_release_dir(self, dist_dir, board="crane_evb_z2", src_dir=None):
        src_dir = self.build_root_dir
        self.images = self.board_info.get(board, {}).get("images",[])
        src_bin_l = self.board_info.get(board, {}).get("release_bin",[])
        src_bin_l = [os.path.join(src_dir, _file) for _file in src_bin_l]
        dist_bin_l = [os.path.join(dist_dir, _file) for _file in self.images]
        for src_bin, dist_bin in zip(src_bin_l, dist_bin_l):
            copy(src_bin, dist_bin)

    def update_download_tool(self):
        # self.download_controller.update_download_tool()
        download_tool_dir = os.path.join(self.build_root_dir, "tool", "downloadtool")
        self.download_tool_l = [os.path.join(download_tool_dir, _tool) for _tool in os.listdir(download_tool_dir)]
        for _tool in self.download_tool_l:
            self.log.info(_tool)

    def prepare_download_tool(self, images):
        for download_tool_dir in self.download_tool_l:
            if not os.path.exists(download_tool_dir):
                self.log.warning("%s not exists" % download_tool_dir)
                continue
            dist_dir = os.path.join(download_tool_dir,"images")
            dist_bin_l = [os.path.join(dist_dir,os.path.basename(_file)) for _file in images]
            for _file in dist_bin_l:
                if os.path.exists(_file):
                    os.remove(_file)
            for src_bin, dist_bin in zip(images, dist_bin_l):
                if os.path.exists(dist_bin):
                    os.remove(dist_bin)
                copy(src_bin,dist_bin)

    def create_download_tool(self, board):
        try:
            self.download_controller.release_download_tool(os.path.basename(self.loacal_dist_dir), board,
                                                      dist_dir=self.download_tool_dir_d[board], download_tool_l = self.download_tool_l)
        except Exception, e:
            self.log.error(e)

    def trigger_auto_test(self, dist_dir, test_type, board="crane_evb_z2"):
        try:
            sdk_tool_abs_path_dir = os.path.join(dist_dir, board, "download_tool")
            self.log.info(sdk_tool_abs_path_dir)
            for _file in os.listdir(sdk_tool_abs_path_dir):
                if _file.endswith(".zip") and "DOWNLOAD_TOOL" in _file.upper() and "DCXO" not in _file:
                    sdk_tool_abs_path = os.path.join(sdk_tool_abs_path_dir, _file)
                    break
            else:
                sdk_tool_abs_path = None

            mdb_txt_file_dir = os.path.join(dist_dir, board)
            self.log.info(mdb_txt_file_dir)
            for _file in os.listdir(mdb_txt_file_dir):
                if "MDB.TXT" in _file.upper():
                    mdb_txt_file_abs_path = os.path.join(mdb_txt_file_dir, _file)
                    break
            else:
                mdb_txt_file_abs_path = None
            self.log.info("sdk_tool:", sdk_tool_abs_path)
            self.log.info("mdb path:", mdb_txt_file_abs_path)
            self.log.info("test type: ", test_type)
            trigger_test(sdk_tool_abs_path, mdb_txt_file_abs_path, test_type)
        except Exception, e:
            self.log.info(e)

    def git_clean(self):
        self._repo.git_clean()

    def get_commit_massages(self):
        self.massage_file = self._repo.get_commit_massages()

    def get_old_cp_version(self):
        return self._repo.get_old_cp_version(self.cp_version_log)

    def update_cp_version(self):
        self.cp_version = self._repo.update_cp_version(self.cp_version_file, self.cp_version_log)
        return self.cp_version

    def get_ap_version(self):
        return self._repo.get_nearest_version()

    def get_revion_owner(self):
        commit_id, owner, date, commit_info = self._repo.get_revion_owner()
        self.log.debug(commit_id, owner, date, commit_info, time.asctime(time.localtime(int(date))))
        return owner, time.asctime(time.localtime(int(date)))

    def record_version(self):
        return self._repo.record_version()

    def get_manifest_xml(self):
        self._repo.get_manifest_xml(self.xml_file)

    def get_dsp_version(self, dsp_bin):
        self.dsp_version = self._repo.get_dsp_version(dsp_bin, self.dsp_version_log)
        return self.dsp_version

    def record_ap_version(self, version):
        with open(self.ap_version_log, 'w') as _obj:
            _obj.write(version.upper())


    @property
    def condition(self):
        self.update()
        return self._repo.sync()

    def start(self):
        pass

    def print_info(self):
        print "-"*80
        for k, v in self.__dict__.items():
            print("{: <20}: {}".format(k,v))


class MyDailyBuildBase(BuildBase, BuildController):
    def __init__(self, _repo):
        super(MyDailyBuildBase, self).__init__(_repo)
        super(BuildBase, self).__init__()
        self.log = MyLogger(self.__class__.__name__)
        self.release_event = None
        self.release_branch = "master"

        self.ap_version = None

        self.sdk_update_flag = threading.Event()

    def prepare_build(self):
        self.ap_version = self.get_ap_version()
        self.record_ap_version(self.ap_version)

        date = time.strftime("%Y%m%d_%H%M%S")
        file_name = "%s_%s" % (self.ap_version, date)

        self.loacal_dist_dir = os.path.join(os.path.dirname(self.git_root_dir), file_name)
        self.release_dist = os.path.join(self.release_dist_dir, file_name)

        self.prepare_release_dir(self.loacal_dist_dir)

        self.xml_file = self.ap_version + ".xml"
        self.xml_file = os.path.join(self.manisest_xml_dir, self.xml_file)
        self.get_manifest_xml()


    def close_build(self):
        pass

    def start(self):
        self.prepare_build()
        self.old_cp_version = self.get_old_cp_version()
        self.cp_version = self.update_cp_version()
        self.get_dsp_version(self.dsp_bin)

        owner, date = self.get_revion_owner()

        self.log.info("=" * 80)
        self.log.info("mUI version:", self.ap_version.upper())
        self.log.info("sdk version:", self.cp_version)
        self.log.info("dsp version:", self.dsp_version)
        self.log.info("patch owner:", owner)
        self.log.info("patch time :", date)
        self.log.info("=" * 80)

        self.get_commit_massages()

        self.git_version_dir = self.loacal_dist_dir

        self.copy_version_file_to_release_dir()

        self.update_download_tool()

        for board in self.board_list:
            if board == "crane_evb_z2_dcxo":
                continue
            self.git_clean()
            build_cmd_str = self.board_info.get(board, {}).get("build_cmd",'')
            for build_cmd in build_cmd_str.split("@"):
                assert build_cmd,"%s no build cmd" % board
                self.log.info("-" * 80)
                self.log.info("patch owner:", owner)
                self.log.info("patch time :", date)
                self.log.info("board name :", board)
                self.log.info("build cmd  :", build_cmd)
                self.log.info("-" * 80)
                _root_dir = self.build_root_dir
                if board == "no_ui_crane_lib":
                    _rel_dir = os.path.join(self.build_root_dir,"build","rel")
                    if os.path.exists(_rel_dir):
                        _root_dir = _rel_dir
                self.build(_root_dir, cmd=build_cmd)
            self.send_email(self.build_root_dir, owner, self.release_dist, board)

            kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')

            if board in self.board_list[0] and self.build_res in "FAIL":
                self.log.info(self.loacal_dist_dir, "build fail")
                return self.loacal_dist_dir

            if board == "no_ui_crane_lib":
                try:
                    self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir, board = board)
                except Exception,e:
                    self.log.error(e)
                continue
            else:
                self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir, board = board)

            try:
                self.copy_sdk_files_to_release_dir(self.download_tool_images_dir_d[board], board, self.build_root_dir)
            except Exception,e:
                self.log.error(e)
            # if self.release_branch not in  "master":
                # archive_file = os.path.join(self.build_root_dir,"build", "crane_evb_z2", "ASR_CRANE_EVB_A0_16MB.zip")
                # dist_dir = self.download_tool_images_dir_d[board]
                # self.zip_tool.unpack_files_from_archive(archive_file, dist_dir, "dsp.bin", "rf.bin", "ReliableData.bin", "logo.bin", "updater.bin")

            if self.build_res == "SUCCESS":
                _root_dir = self.download_tool_images_dir_d[board]
                _images = [os.path.join(_root_dir,_file) for _file in os.listdir(_root_dir)]
                self.prepare_download_tool(_images)
                self.download_controller.release_download_tool(os.path.basename(self.loacal_dist_dir), board,
                                                      dist_dir=self.download_tool_dir_d[board], download_tool_l = self.download_tool_l)
                if board == "crane_evb_z2":
                    board = "crane_evb_z2_dcxo"
                    self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir, board = board)
                    self.copy_sdk_files_to_release_dir(self.download_tool_images_dir_d[board], board, self.build_root_dir)
                    _root_dir = self.download_tool_images_dir_d[board]
                    _images = [os.path.join(_root_dir,_file) for _file in os.listdir(_root_dir)]
                    self.prepare_download_tool(_images)
                    self.download_controller.release_download_tool(os.path.basename(self.loacal_dist_dir), board,
                                                          dist_dir=self.download_tool_dir_d[board], download_tool_l = self.download_tool_l)

        copy(self.loacal_dist_dir, self.release_dist)
        self.record_version()

        self.close_build()


class CraneDailyBuild(MyDailyBuildBase):
    def __init__(self, _repo):
        super(CraneDailyBuild, self).__init__(_repo)
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "master"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane"]
        self.board_list = self.config_d["boards"]

    def close_build(self):
        if self.cp_version not in self.old_cp_version:
            self.sdk_update_flag.set()
        self.git_clean()


class CraneGDailyBuild(MyDailyBuildBase):
    def __init__(self, _repo):
        super(CraneGDailyBuild, self).__init__(_repo)
        super(BuildBase, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "master"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["craneg"]
        self.board_list = self.config_d["boards"]

    def close_build(self):
        if self.cp_version not in self.old_cp_version:
            self.sdk_update_flag.set()
        self.git_clean()



class CusBuild(MyDailyBuildBase):
    def __init__(self, _repo_cus):
        super(CusBuild, self).__init__(_repo_cus)
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "master"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane"]
        self.board_list = self.config_d["boards"][:6]

    def config(self):
        self.sdk_release_notes_file = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200803_SDK\ReleaseNotes.xlsx"
        self.sdk_release_notes_dir = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200803_SDK"

    def find_newest_notes(self):
        _root_dir = os.path.join(self.git_root_dir, "note")
        release_note_list = [_file for _file in os.listdir(_root_dir) if _file.startswith("ReleaseNotes") and not _file.endswith(".xlsx")]
        release_note_list.sort(key=lambda fn: os.path.getmtime(os.path.join(_root_dir, fn)))
        if release_note_list:
            file_name = release_note_list[-1]
            self.log.debug(file_name)
            return os.path.join(_root_dir, file_name)
        else:
            return None

    def prepare_build(self):
        self.ap_version = self.get_ap_version()
        self.record_ap_version(self.ap_version)

        date = time.strftime("%Y%m%d_%H%M%S")
        file_name = "%s_%s" % (self.ap_version, date)

        self.loacal_dist_dir = os.path.join(os.path.dirname(self.git_root_dir), file_name)
        self.release_dist = os.path.join(self.release_dist_dir, file_name)

        self.prepare_release_dir(self.loacal_dist_dir)

        self.log.info("release_branch", self.release_branch)

        self.ap_version = self.get_ap_version()

        release_note = self.find_newest_notes()
        if release_note:
            copy(release_note, os.path.join(self.version_info_dir, os.path.basename(release_note)))

        if os.path.exists(self.sdk_release_notes_file):
            copy(self.sdk_release_notes_file,
                         os.path.join(self.version_info_dir, os.path.basename(self.sdk_release_notes_file)))
        if os.path.exists(self.sdk_release_notes_dir):
            for _file in os.listdir(self.sdk_release_notes_dir):
                if _file.endswith(".xls") or _file.endswith(".xlsx"):
                    src_file = os.path.join(self.sdk_release_notes_dir, _file)
                    copy(src_file, os.path.join(self.version_info_dir, _file))


    def close_build(self):
        if self.cp_version not in self.old_cp_version:
            # to_address = 'yuanzhizheng@asrmicro.com'
            to_address = ",".join(['yuanzhizheng@asrmicro.com','miantianyu@asrmicro.com'])
            subject = "%s RELEASE" % self.cp_version
            msg = r"Hi %s, %s build done! Binary dir: %s" % (to_address.split("@")[0], self.cp_version, self.release_dist)
            send_email_tool(to_address, subject.upper(), msg)
        self.trigger_auto_test(self.release_dist, "evb_customer", "crane_evb_z2")
        self.git_clean()


class CusR1RC_SDK_1_008_Build(CusBuild):
    def __init__(self, _repo_cus):
        super(CusR1RC_SDK_1_008_Build, self).__init__(_repo_cus)
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "r1_rc_sdk_1.008"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane"]
        self.board_list = ["crane_evb_z2", "bird_phone", "visenk_phone","crane_evb_z2_128x160", "crane_evb_z2_fwp"]

    def config(self):
        self.release_branch = "r1_rc_sdk_1.008"
        self.sdk_release_notes_file = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200425_SDK\ReleaseNotes.xlsx"
        self.sdk_release_notes_dir = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200425_SDK"

    def close_build(self):
        if self.cp_version not in self.old_cp_version:
            # to_address = 'yuanzhizheng@asrmicro.com'
            to_address = ",".join(['yuanzhizheng@asrmicro.com','miantianyu@asrmicro.com'])
            subject = "%s RELEASE" % self.cp_version
            msg = r"Hi %s, %s build done! Binary dir: %s" % (to_address.split("@")[0], self.cp_version, self.release_dist)
            send_email_tool(to_address, subject.upper(), msg)
        self.trigger_auto_test(self.release_dist, "evb_customer", "crane_evb_z2")
        self.git_clean()

    def start(self):
        self.prepare_build()
        self.old_cp_version = self.get_old_cp_version()
        self.cp_version = self.update_cp_version()
        self.get_dsp_version(self.dsp_bin)

        owner, date = self.get_revion_owner()

        self.log.info("=" * 80)
        self.log.info("mUI version:", self.ap_version.upper())
        self.log.info("sdk version:", self.cp_version)
        self.log.info("dsp version:", self.dsp_version)
        self.log.info("patch owner:", owner)
        self.log.info("patch time :", date)
        self.log.info("=" * 80)

        self.get_commit_massages()

        self.git_version_dir = self.loacal_dist_dir

        self.copy_version_file_to_release_dir()

        self.update_download_tool()

        for board in self.board_list:
            self.git_clean()
            build_cmd_str = self.board_info.get(board, {}).get("build_cmd",'')
            for build_cmd in build_cmd_str.split("@"):
                assert build_cmd,"%s no build cmd" % board
                self.log.info("-" * 80)
                self.log.info("patch owner:", owner)
                self.log.info("patch time :", date)
                self.log.info("board name :", board)
                self.log.info("build cmd  :", build_cmd)
                self.log.info("-" * 80)
                _root_dir = self.build_root_dir
                if board == "no_ui_crane_lib":
                    _rel_dir = os.path.join(self.build_root_dir,"build","rel")
                    if os.path.exists(_rel_dir):
                        _root_dir = _rel_dir
                self.build(_root_dir, cmd=build_cmd)
            self.send_email(self.build_root_dir, owner, self.release_dist, board)

            kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')

            if board in self.board_list[0] and self.build_res in "FAIL":
                self.log.info(self.loacal_dist_dir, "build fail")
                return self.loacal_dist_dir

            if board == "no_ui_crane_lib":
                try:
                    self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir, board = board)
                except Exception,e:
                    self.log.error(e)
                continue
            else:
                self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir, board = board)

            try:
                self.copy_sdk_files_to_release_dir(self.download_tool_images_dir_d[board], board, self.build_root_dir)
            except Exception,e:
                self.log.error(e)

            if self.build_res == "SUCCESS":
                _root_dir = self.download_tool_images_dir_d[board]
                _images = [os.path.join(_root_dir,_file) for _file in os.listdir(_root_dir)]
                self.prepare_download_tool(_images)
                self.download_controller.release_download_tool(os.path.basename(self.loacal_dist_dir), board,
                                                      dist_dir=self.download_tool_dir_d[board], download_tool_l = self.download_tool_l)

        copy(self.loacal_dist_dir, self.release_dist)
        self.record_version()

        self.close_build()


class CusCraneGBuild(CusBuild):
    def __init__(self, _repo_cus):
        super(CusCraneGBuild, self).__init__(_repo_cus)
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "master"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["craneg"]
        self.board_list = self.config_d["boards"][:1]

    def config(self):
        self.release_branch = "master"
        self.sdk_release_notes_file = "NO_FILE"
        self.sdk_release_notes_dir = "NO_DIR"

    def close_build(self):
        if self.cp_version not in self.old_cp_version:
            # to_address = 'yuanzhizheng@asrmicro.com'
            to_address = ",".join(['yuanzhizheng@asrmicro.com','miantianyu@asrmicro.com'])
            subject = "%s RELEASE" % self.cp_version
            msg = r"Hi %s, %s build done! Binary dir: %s" % (to_address.split("@")[0], self.cp_version, self.release_dist)
            send_email_tool(to_address, subject.upper(), msg)
        self.trigger_auto_test(self.release_dist, "craneg_evb_release", "craneg_evb")
        self.git_clean()


class CusR1RCBuild(CusBuild):
    def __init__(self, _repo_cus):
        super(CusR1RCBuild, self).__init__(_repo_cus)
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "r1_rc"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane"]
        self.board_list = ["crane_evb_z2","crane_evb_z2_128x160"]
        # for board in self.board_list:
            # self.config_d["boards_info"][board]["build_zip_file"] = os.path.join("build", "crane_evb_z2", "ASR_CRANE_EVB_A0_16MB.zip")


    def config(self):
        self.release_branch = "r1_rc"
        self.sdk_release_notes_file = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200225_SDK\ReleaseNotes.xlsx"
        self.sdk_release_notes_dir = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200225_SDK"

    def close_build(self):
        if self.cp_version not in self.old_cp_version:
            # to_address = 'yuanzhizheng@asrmicro.com'
            to_address = ",".join(['yuanzhizheng@asrmicro.com','miantianyu@asrmicro.com'])
            subject = "%s RELEASE" % self.cp_version
            msg = r"Hi %s, %s build done! Binary dir: %s" % (to_address.split("@")[0], self.cp_version, self.release_dist)
            send_email_tool(to_address, subject.upper(), msg)
        self.trigger_auto_test(self.release_dist, "evb_customer_r1", "crane_evb_z2")
        self.git_clean()

    def create_download_tool(self, release_name, borad="crane_evb_z2", dist_dir=None):
        date = time.strftime("%Y%m%d_%H%M%S")
        release_file_name = "%s_%s_DOWNLOAD_TOOL_%s" % (release_name.upper(),borad.upper(),date)
        download_tool_dir = os.path.join(self.root_dir, "download_tool_dir")
        release_dir = os.path.join(download_tool_dir, release_file_name)
        os.mkdir(release_dir) if not os.path.exists(release_dir) else None
        self.log.info(release_file_name)
        # self.log.info(release_dir)
        download_tool_l = []
        local_download_tool_dir = os.path.join(self.build_root_dir,"tool","downloadtool")
        # self.log.info(local_download_tool_dir)
        for _tool in os.listdir(local_download_tool_dir):
            download_tool_l.append(os.path.join(local_download_tool_dir, _tool))
        # self.log.info(download_tool_l)
        release_downlaod_tool_l = []
        for _tool in download_tool_l:
            dist_file = os.path.join(release_dir, os.path.basename(_tool))
            # self.log.info(dist_file)
            release_downlaod_tool_l.append(dist_file)
            copy(_tool, dist_file)
        for _dir in release_downlaod_tool_l:
            copy(self.build_zip_file, _dir)
        dist = os.path.join(dist_dir,release_file_name)
        self.zip_tool.make_archive_e(dist,"zip",release_dir)
        shutil.rmtree(release_dir)

    def start(self):
        self.prepare_build()
        self.old_cp_version = self.get_old_cp_version()
        self.cp_version = self.update_cp_version()
        self.get_dsp_version(self.dsp_bin)

        owner, date = self.get_revion_owner()

        self.log.info("=" * 80)
        self.log.info("mUI version:", self.ap_version.upper())
        self.log.info("sdk version:", self.cp_version)
        self.log.info("dsp version:", self.dsp_version)
        self.log.info("patch owner:", owner)
        self.log.info("patch time :", date)
        self.log.info("=" * 80)

        self.get_commit_massages()
        self.git_version_dir = self.loacal_dist_dir
        self.copy_version_file_to_release_dir()

        for board in self.board_list:
            self.git_clean()
            build_cmd = self.board_info.get(board, {}).get("build_cmd",'')
            assert build_cmd,"%s no build cmd" % board
            self.build(self.build_root_dir, cmd=build_cmd)
            self.send_email(self.build_root_dir, owner, self.release_dist, board)

            kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')

            if board in self.board_list[0] and self.build_res in "FAIL":
                self.log.info(self.loacal_dist_dir, "build fail")
                return self.loacal_dist_dir

            self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir, board = board)

            try:
                self.copy_sdk_files_to_release_dir(self.download_tool_images_dir_d[board], board, self.build_root_dir)
            except Exception,e:
                self.log.error(e)
                dist_dir = self.download_tool_images_dir_d[board]
                self.zip_tool.unpack_files_from_archive(self.build_zip_file, dist_dir, "dsp.bin", "rf.bin", "ReliableData.bin", "logo.bin", "updater.bin")

            if self.build_res == "SUCCESS":
                self.create_download_tool(os.path.basename(self.loacal_dist_dir), board, dist_dir=self.download_tool_dir_d[board])
                """
                if board == "crane_evb_z2":
                    dcxo_zip = os.path.join(self.build_root_dir,"build","crane_evb_z2","ASR_CRANE_EVB_CRANE_A0_16MB_DCXO.zip")
                    if os.path.exists(dcxo_zip):
                        dist_dir = os.path.join(self.loacal_build_dir_d[board],"dcxo_images")
                        copy(self.download_tool_images_dir_d[board], dist_dir)
                        self.zip_tool.unpack_files_from_archive(dcxo_zip, dist_dir, "dsp.bin", "rf.bin", "ReliableData.bin")
                        _images = [os.path.join(dist_dir,_file) for _file in os.listdir(dist_dir)]
                        self.download_controller.prepare_download_tool(_images)
                        self.download_controller.release_zip(os.path.dirname(dist_dir), zip_name = "ASR_CRANE_EVB_CRANE_A0_16MB_DCXO.zip")
                        self.download_controller.release_download_tool(os.path.basename(self.loacal_dist_dir), board+"_DCXO",
                                                          dist_dir=self.download_tool_dir_d[board])
                """

        self.record_version()
        copy(self.loacal_dist_dir, self.release_dist)

        self.close_build()

