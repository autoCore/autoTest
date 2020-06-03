#!usr/bin/env python

import os
import time
import subprocess

from util import MyLogger, copy, kill_win_process, zipTool, load_json
from send_email import send_email_tool
from ftp import ftp_upload_file
from TriggerTest import trigger_test
from download_tool import DownloadToolController

class BuildController(object):
    def __init__(self):
        self.build_res = None
        self.log = MyLogger(self.__class__.__name__)

        self.git_version_dir = ''

        self.gui_build_log = os.path.join(".", 'build', 'crane_evb_z2', r'gui_build.log')
        self.hal_build_log = os.path.join(".", 'build', 'crane_evb_z2', r'hal_build.log')
        self.cp_build_log = os.path.join(".", 'build', 'crane_evb_z2', r'cp_build.log')
        self.link_log = os.path.join(".", 'build', 'crane_evb_z2', r'fp_link_build.log')
        self.compile_log = "compile.log"
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
            self.compile_log = os.path.basename(self.git_version_dir) + "_compile.log"
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
            subject = r"%s build result: fail" % board
            msg = r"Hi %s, your patch build fail! Pls check attachment log" % (owner.split("@")[0])
        else:
            att_file = None
            subject = r"%s build result: pass" % board
            msg = r"Hi %s, your patch build pass! Binary dir: %s" % (owner.split("@")[0], external_dir)
        to_address = ",".join([owner, 'yuanzhizheng@asrmicro.com'])
        send_email_tool(to_address, subject, msg, att_file)
        self.log.info("send email done")


class BuildBase(object):
    def __init__(self, _repo):
        self._repo = _repo
        self.log = MyLogger(self.__class__.__name__)
        self.root_dir = _repo.root_dir
        self.build_root_dir = _repo.build_root_dir
        self.git_root_dir = _repo.git_root_dir
        self.release_dist_dir = _repo.release_dist_dir
        self.manisest_xml_dir = _repo.manisest_xml_dir

        self.ap_version_log = _repo.ap_version_log
        self.cp_version_log = _repo.cp_version_log
        self.dsp_version_log = _repo.dsp_version_log

        self.download_controller = DownloadToolController()
        self.dsp_bin = os.path.join(self.build_root_dir, "cus", "evb", "images", "dsp.bin")

        self.xml_file = ''
        self.massage_file = ''
        self.cp_version = ''
        self.dsp_version = ''

        self.loacal_dist_dir = ''
        self.loacal_build_dir_d = {}
        self.download_tool_dir_d = {}
        self.download_tool_images_dir_d = {}
        self.version_info_dir = ''

        self.update()


    def update(self):
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.board_list = json_str["boards"]
        self.board_info = json_str["boards_info"]
        self.build_images = json_str["build_images"][1:-1]
        self.mdb_file_dir = os.path.join(self.build_root_dir, json_str["mdb_file_dir"])
        self.images = json_str["images"]
        self.cp_version_file = os.path.join(self.build_root_dir, json_str["cp_version_file"])

        self._repo.update_cp_version(self.cp_version_file, self.cp_version_log)


    def prepare_release_dir(self, version_dir):
        self.loacal_dist_dir = version_dir
        os.mkdir(version_dir)
        self.version_info_dir = os.path.join(version_dir, "version_info")
        os.mkdir(self.version_info_dir)
        for board in self.board_list:
            self.loacal_build_dir_d[board] = os.path.join(version_dir, board)
            os.mkdir(self.loacal_build_dir_d[board])
            self.download_tool_dir_d[board] = os.path.join(version_dir, board, "download_tool")
            os.mkdir(self.download_tool_dir_d[board])
            self.download_tool_images_dir_d[board] = os.path.join(version_dir, board, "cp_images")
            os.mkdir(self.download_tool_images_dir_d[board])

    def copy_version_file_to_release_dir(self):
        for _file in [self.xml_file, self.ap_version_log, self.cp_version_log, self.dsp_version_log, self.massage_file]:
            if os.path.exists(_file):
                copy(_file, os.path.join(self.loacal_dist_dir, "version_info", os.path.basename(_file)))

    def copy_build_file_to_release_dir(self, dist_dir, src_dir=None):
        src_dir = self.build_root_dir
        for _file in self.build_images:
            if "crane_evb_z2" not in dist_dir and "rel_lib" in _file:
                continue
            src = os.path.join(src_dir, _file)
            dist = os.path.join(dist_dir, os.path.basename(_file))
            copy(src, dist)

        if os.path.exists(self.mdb_file_dir):
            for _file in os.listdir(self.mdb_file_dir):
                if "MDB.TXT" in _file.upper():
                    copy(os.path.join(self.mdb_file_dir, _file), os.path.join(dist_dir, _file))
                    break

    def copy_sdk_files_to_release_dir(self, dist_dir, board="crane_evb_z2", src_dir=None):
        src_dir = self.build_root_dir
        src_bin_l = self.board_info.get(board, {}).get("release_bin",[])
        src_bin_l = [os.path.join(src_dir, _file) for _file in src_bin_l]
        dist_bin_l = [os.path.join(dist_dir, _file) for _file in self.images]
        for src_bin, dist_bin in zip(src_bin_l, dist_bin_l):
            copy(src_bin, dist_bin)

    def create_download_tool(self):
        self.download_controller.update_download_tool()
        for board in self.board_list:
            try:
                _root_dir = self.download_tool_images_dir_d[board]
                _images = [os.path.join(_root_dir,_file) for _file in os.listdir(_root_dir)]
                self.download_controller.prepare_download_tool(_images)
                self.download_controller.release_zip(os.path.dirname(_root_dir))
                self.download_controller.release_download_tool(os.path.basename(self.loacal_dist_dir), board,
                                                          dist_dir=self.download_tool_dir_d[board])
            except Exception, e:
                self.log.error(e)

    def trigger_auto_test(self, dist_dir, test_type, board="crane_evb_z2"):
        try:
            board = "crane_evb_z2"
            sdk_tool_abs_path_dir = os.path.join(dist_dir, board, "download_tool")
            self.log.info(sdk_tool_abs_path_dir)
            for _file in os.listdir(sdk_tool_abs_path_dir):
                if _file.endswith(".zip") and "DOWNLOAD_TOOL" in _file.upper():
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

    def get_revion_owner(self):
        commit_id, owner, date, commit_info = self._repo.get_revion_owner()
        self.log.debug(commit_id, owner, date, commit_info, time.asctime(time.localtime(int(date))))
        return owner

    def record_version(self):
        return self._repo.record_version()

    def get_manifest_xml(self):
        self._repo.get_manifest_xml(self.xml_file)

    def get_dsp_version(self, dsp_bin):
        return self._repo.get_dsp_version(dsp_bin, self.dsp_version_log)

    def record_ap_version(self, version):
        with open(self.ap_version_log, 'w') as _obj:
            _obj.write(version.upper())


    @property
    def condition(self):
        self._repo.update()
        return self._repo.sync()

    def start(self):
        pass


class DailyBuild(BuildBase, BuildController):
    def __init__(self, _repo, _release_event):
        super(DailyBuild, self).__init__(_repo)
        super(BuildBase, self).__init__()
        self.board_list = self.board_list[:]
        self.log = MyLogger(self.__class__.__name__)
        self.release_event = _release_event

    def start(self):
        self.get_dsp_version(self.dsp_bin)
        old_cp_version = self.get_old_cp_version()
        self.cp_version = self.update_cp_version()
        owner = self.get_revion_owner()
        self.log.info("=" * 50)

        _r = self.record_version()
        self.record_ap_version(_r)
        date = time.strftime("%Y%m%d_%H%M%S")
        file_name = "%s_%s" % (_r, date)
        self.log.info("version: " + file_name)
        self.xml_file = _r + ".xml"
        self.xml_file = os.path.join(self.manisest_xml_dir, self.xml_file)
        self.get_manifest_xml()
        self.get_commit_massages()

        self.loacal_dist_dir = os.path.join(os.path.dirname(self.git_root_dir), file_name)

        self.git_version_dir = self.loacal_dist_dir

        self.prepare_release_dir(self.loacal_dist_dir)
        self.copy_version_file_to_release_dir()

        self.download_controller.update_download_tool()

        for board in self.board_list:
            self.git_clean()
            build_cmd = self.board_info.get(board, {}).get("build_cmd",'')
            assert build_cmd,"%s no build cmd" % board
            self.build(self.build_root_dir, cmd=build_cmd)
            self.send_email(self.build_root_dir, owner, os.path.join(self.release_dist_dir, file_name), board)

            kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')

            if board in self.board_list[0] and self.build_res in "FAIL":
                self.log.info(self.loacal_dist_dir, "build fail")
                return self.loacal_dist_dir

            self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir)
            self.copy_sdk_files_to_release_dir(self.download_tool_images_dir_d[board], board, self.build_root_dir)

            if self.build_res == "SUCCESS":
                _root_dir = self.download_tool_images_dir_d[board]
                _images = [os.path.join(_root_dir,_file) for _file in os.listdir(_root_dir)]
                self.download_controller.prepare_download_tool(_images)
                self.download_controller.release_zip(os.path.dirname(_root_dir))
                self.download_controller.release_download_tool(os.path.basename(self.loacal_dist_dir), board,
                                                          dist_dir=self.download_tool_dir_d[board])
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
        # self.create_download_tool()

        dist = os.path.join(self.release_dist_dir, file_name)
        copy(self.loacal_dist_dir, dist)

        self.log.info("old_cp_version: %s" % old_cp_version)
        self.log.info("new_cp_version: %s" % self.cp_version)
        if self.cp_version not in old_cp_version:
            self.release_event.set()
        return self.loacal_dist_dir



class CusBuild(BuildBase, BuildController):
    def __init__(self, _repo_cus):
        super(CusBuild, self).__init__(_repo_cus)
        super(BuildBase, self).__init__()
        self.log = MyLogger(self.__class__.__name__)
        self.release_branch = _repo_cus.release_branch

    def find_newest_notes(self):
        _root_dir = os.path.join(self.git_root_dir, "note")
        release_note_list = [_file for _file in os.listdir(_root_dir) if _file.startswith("ReleaseNotes")]
        release_note_list.sort(key=lambda fn: os.path.getmtime(os.path.join(_root_dir, fn)))
        if release_note_list:
            file_name = release_note_list[-1]
            self.log.debug(file_name)
            return os.path.join(_root_dir, file_name)
        else:
            return None

    def start(self):
        self.log.info("release_branch", self.release_branch)
        if self.release_branch == "master":
            self.board_list = self.board_list[:3]
            self.sdk_release_notes_file = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200415_SDK\ReleaseNotes.xls"
        else: # ["r1", "r1_plus_j", "r1_1.006.027"]
            self.board_list = self.board_list[:1]
            self.sdk_release_notes_file = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200225_SDK\ReleaseNotes.xls"
        self.get_dsp_version(self.dsp_bin)
        old_cp_version = self.get_old_cp_version()
        self.cp_version = self.update_cp_version()
        owner = self.get_revion_owner()
        self.log.info("=" * 50)

        _r = self.record_version()
        self.record_ap_version(_r)
        date = time.strftime("%Y%m%d_%H%M%S")
        file_name = "%s_%s" % (_r, date)
        self.log.info("version: " + file_name)
        release_dist = os.path.join(self.release_dist_dir, file_name)
        self.get_commit_massages()

        version_file = os.path.join(os.path.dirname(self.git_root_dir), file_name)
        self.git_version_dir = version_file

        self.prepare_release_dir(version_file)
        self.copy_version_file_to_release_dir()

        release_note = self.find_newest_notes()
        if release_note:
            copy(release_note, os.path.join(self.version_info_dir, os.path.basename(release_note)))

        for board in self.board_list:
            self.git_clean()
            build_cmd = self.board_info.get(board, {}).get("build_cmd",'')
            assert build_cmd,"%s no build cmd" % board
            self.build(self.build_root_dir, cmd=build_cmd)
            self.send_email(self.build_root_dir, owner, os.path.join(self.release_dist_dir, file_name),
                                        board)

            kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')

            if board in self.board_list[0] and self.build_res in "FAIL":
                self.log.info(self.loacal_dist_dir, "build fail")
                return self.loacal_dist_dir

            self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir)
            try:
                self.copy_sdk_files_to_release_dir(self.download_tool_images_dir_d[board], board, self.build_root_dir)
            except Exception,e:
                self.log.error(e)
            if self.release_branch not in  "master":
                archive_file = os.path.join(self.build_root_dir,"build", "crane_evb_z2", "ASR_CRANE_EVB_A0_16MB.zip")
                dist_dir = self.download_tool_images_dir_d[board]
                self.zip_tool.unpack_files_from_archive(archive_file, dist_dir, "dsp.bin", "rf.bin", "ReliableData.bin", "logo.bin", "updater.bin")

        if os.path.exists(self.sdk_release_notes_file) and self.release_branch == "master":
            copy(self.sdk_release_notes_file,
                         os.path.join(self.version_info_dir, os.path.basename(self.sdk_release_notes_file)))

        self.create_download_tool()

        copy(self.loacal_dist_dir, release_dist)

        self.log.info("old_cp_version: %s" % old_cp_version)
        self.log.info("new_cp_version: %s" % self.cp_version)
        if self.cp_version not in old_cp_version:
            to_address = 'yuanzhizheng@asrmicro.com'
            subject = "%s RELEASE" % self.cp_version
            msg = r"Hi %s, %s build done! Binary dir: %s" % (to_address.split("@")[0], self.cp_version, release_dist)
            send_email_tool(to_address, subject.upper(), msg)
        self.trigger_auto_test(release_dist, "evb_customer")
        self.git_clean()
        return self.loacal_dist_dir
