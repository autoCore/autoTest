#!usr/bin/env python

import os
import time
import subprocess
import shutil
import threading
import re
import fileinput

from util import MyLogger, copy, kill_win_process, zipTool, load_json, create_cp_framework,ziptool_mutex
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

        self.gui_build_log = os.path.join(".", 'build', 'crane_evb', r'gui_build.log')
        self.hal_build_log = os.path.join(".", 'build', 'crane_evb', r'hal_build.log')
        self.cp_build_log = os.path.join(".", 'build', 'crane_evb', r'cp_build.log')
        self.link_log = os.path.join(".", 'build', 'crane_evb', r'fp_link_build.log')
        self.release_log = os.path.join(".", 'build', 'crane_evb', r'arelease.log')
        self.compile_log_dir = os.path.join(self.root_dir, 'tmp', 'compile_log')
        self.zip_tool = zipTool()
        self.build_dirname = ""
        self.release_zip_file = ''

    def check_build_result(self,cur_dir, build_dir):
        if "rel" in cur_dir:
            if os.path.exists(os.path.join(cur_dir,self.release_zip_file)) or os.path.exists(os.path.join(cur_dir,self.build_dirname,"libhal.a")):
                self.log.info("%s build done" % cur_dir)
                self.build_res = "SUCCESS"
            else:
                self.log.warning("%s build fail" % cur_dir)
                self.build_res = "FAIL"
        else:
            if os.path.exists(os.path.join(cur_dir,self.build_dirname,"crane_evb.elf")) and os.path.exists(
                    os.path.join(cur_dir,self.release_zip_file)):
                self.log.info("%s build done" % cur_dir)
                self.build_res = "SUCCESS"
            else:
                self.log.warning("%s build fail" % cur_dir)
                self.build_res = "FAIL"

    def build(self, cur_dir, compile_log='', cmd='', build_dir='crane_evb'):
        os.chdir(cur_dir)
        self.build_dirname = os.path.dirname(self.release_zip_file)
        self.gui_build_log = os.path.join(cur_dir, self.build_dirname, r'gui_build.log')
        self.hal_build_log = os.path.join(cur_dir, self.build_dirname, r'hal_build.log')
        self.cp_build_log = os.path.join(cur_dir, self.build_dirname, r'cp_build.log')
        self.link_log = os.path.join(cur_dir, self.build_dirname, r'fp_link_build.log')
        self.release_log = os.path.join(cur_dir, self.build_dirname, r'arelease.log')
        self.log.info("%s build start..." % cur_dir)
        # cmd = "autobuild.bat %s> %s"%(build_dir,compile_log)
        if not cmd:
            cmd = "autobuild.bat"
        if compile_log:
            self.compile_log = compile_log
        else:
            self.compile_log = os.path.join(self.compile_log_dir, os.path.basename(self.git_version_dir) + "_compile_"+build_dir+".txt")
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
            kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')
            return
        time.sleep(5)
        if "autobuild.bat -f crane_evb_z2_gen_rel.conf -t gen_rel" in cmd:
            self.log.info("%s build done" % cur_dir)
            self.build_res = "SUCCESS"
        else:
            self.check_build_result(cur_dir, build_dir)
        kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')

    def send_email(self, cur_dir, owner, external_dir, board="crane_evb", subject_str = None):
        os.chdir(cur_dir)
        if self.build_res in "FAIL":
            att_file_list = [self.hal_build_log, self.gui_build_log, self.cp_build_log, self.link_log,self.release_log]
            att_file_list = [os.path.join(cur_dir,_file) for _file in att_file_list]
            # att_file_list.append(self.compile_log)
            att_file = '@'.join(att_file_list)
            if subject_str:
                subject = subject_str
            else:
                subject = r"%s %s build result: fail" % (self.__class__.__name__, board)
            # msg = r"Hi %s, your patch build fail! Pls check attachment log" % (owner.split("@")[0])
            msg = r"Hi All, %s build fail! Pls check attachment log" % (board)
            to_address = "SW_CV@asrmicro.com"
        else:
            att_file = None
            if subject_str:
                subject = subject_str
            else:
                subject = r"%s %s build result: pass" % (self.__class__.__name__, board)
            msg = r"Hi %s, your patch build pass! Binary dir: %s" % (owner.split("@")[0], external_dir)
            to_address = ",".join([owner])
            # to_address = ",".join([owner, 'yuanzhizheng@asrmicro.com'])
        self.log.info(att_file)
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
        self.compile_log_dir = os.path.normpath(os.path.join(self.root_dir, self.config_d["compile_log_dir"]))

        # self._repo.update(self.release_branch)

        self.build_root_dir = self._repo.build_root_dir
        self.git_root_dir = self._repo.git_root_dir
        self.local_storage_dir = self._repo.local_storage_dir
        self.release_dist_dir = self._repo.release_dist_dir
        self.manisest_xml_dir = self._repo.manisest_xml_dir

        self.ap_version_log = self._repo.ap_version_log
        self.cp_version_log = self._repo.cp_version_log
        self.dsp_version_log = self._repo.dsp_version_log

        self.cp_version_file = self._repo.sdk_version_file
        self.dsp_bin = self._repo.dsp_version_file

        # self.release_branch = self._repo.branch_name
        if os.path.exists(self.cp_version_file):
            self._repo.update_cp_version(self.cp_version_file, self.cp_version_log)
        else:
            self.log.error("%s not exists"%self.cp_version_file)


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

        for board in self.board_list:
            dsp_bin = ""
            dsp_version_file = os.path.join(self.version_info_dir, board+"_dsp_version.txt")
            src_bin_l = self.board_info.get(board, {}).get("release_bin",[])
            if not src_bin_l:
                self.log.error("%s not define"%board)
                continue
            for _file in src_bin_l:
                if "dsp.bin" in _file:
                    dsp_bin = os.path.normpath(os.path.join(self.build_root_dir, _file))
                    break
            if os.path.exists(dsp_bin):
                self.get_dsp_version_from_bin_to_file(dsp_bin,dsp_version_file)
            else:
                self.log.error("%s not exists"%dsp_bin)


    def copy_build_file_to_release_dir(self, dist_dir, src_dir=None, board = "crane_evb"):
        src_dir = self.build_root_dir
        self.build_images = self.board_info.get(board, {}).get("build_images",[])
        for _file in self.build_images:
            src = os.path.normpath(os.path.join(src_dir, _file))
            dist = os.path.normpath(os.path.join(dist_dir, os.path.basename(_file)))
            if os.path.exists(src):
                copy(src, dist)
            else:
                self.log.error("%s not exists")

        _zip_file = self.board_info.get(board, {}).get("build_zip_file","")
        self.build_zip_file = os.path.normpath(os.path.join(self.build_root_dir, _zip_file))
        if os.path.exists(self.build_zip_file):
            copy(self.build_zip_file, os.path.join(dist_dir, os.path.basename(_zip_file)))

        _mdb_file_dir = self.board_info.get(board, {}).get("mdb_file_dir","")
        self.mdb_file_dir = os.path.normpath(os.path.join(self.build_root_dir, _mdb_file_dir))
        if os.path.exists(self.mdb_file_dir):
            for _file in os.listdir(self.mdb_file_dir):
                if "MDB.TXT" in _file.upper():
                    copy(os.path.join(self.mdb_file_dir, _file), os.path.join(dist_dir, _file))
                    break

    def copy_sdk_files_to_release_dir(self, dist_dir, board="crane_evb", src_dir=None):
        if not src_dir:
            src_dir = self.build_root_dir
        self.images = self.board_info.get(board, {}).get("images",[])

        # src_bin_l = self.board_info.get(board, {}).get("release_bin",[])
        # src_bin_l = [os.path.join(src_dir, _file) for _file in src_bin_l]
        # dist_bin_l = [os.path.join(dist_dir, _file) for _file in self.images]

        for _tool in self.download_tool_l:
            if _tool.endswith("x64"):
                self.log.info(_tool)
                download_tool = _tool
                break
        download_tool_images_dir = os.path.join(download_tool,"images")
        src_bin_l = [os.path.join(download_tool_images_dir, _file) for _file in self.images]
        dist_bin_l = [os.path.join(dist_dir, _file) for _file in self.images]
        for src_bin, dist_bin in zip(src_bin_l, dist_bin_l):
            if os.path.exists(src_bin):
                copy(src_bin, dist_bin)

        #copy ReliableData.bin
        src_rbd_bin = ""
        for _bin in self.board_info.get(board, {}).get("release_bin",[]):
            if "ReliableData.bin" in _bin:
                src_rbd_bin = os.path.normpath(os.path.join(src_dir, _bin))
                break
        if os.path.exists(src_rbd_bin):
            copy(src_rbd_bin, dist_dir)

    def update_download_tool(self, root_dir = None):
        # self.download_controller.update_download_tool()
        if not root_dir:
            root_dir = self.build_root_dir
        download_tool_dir = os.path.join(root_dir, "tool", "downloadtool")
        self.download_tool_l = [os.path.join(download_tool_dir, _tool) for _tool in os.listdir(download_tool_dir) if re.match("aboot-tools-.*?-win-x[0-9][0-9]",_tool)]
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

    def trigger_auto_test(self, dist_dir, test_type, board="crane_evb"):
        try:
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
            assert sdk_tool_abs_path, "sdk donwload tool is None"
            assert mdb_txt_file_abs_path, "mdb file is None"
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

    def get_dsp_version_from_bin_to_file(self, dsp_bin, version_file):
        self._repo.get_dsp_version(dsp_bin, version_file)

    def record_ap_version(self, version):
        with open(self.ap_version_log, 'w') as _obj:
            _obj.write(version.upper())


    @property
    def condition(self):
        self.update()
        info_d = self._repo.sync()
        # self.log.info(info_d)
        for storage, info in info_d.items():
            if "Already up to date." not in info:
                return True
        return False

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

        self.old_cp_version = self.get_old_cp_version()
        self.cp_version = self.update_cp_version()

        date = time.strftime("%Y%m%d_%H%M%S")
        file_name = "%s_%s" % (self.ap_version, date)

        self.loacal_dist_dir = os.path.join(os.path.dirname(self.git_root_dir), file_name)
        self.release_dist = os.path.join(self.release_dist_dir, file_name)
        self.loacal_dist_dir = os.path.join(self.local_storage_dir,file_name)
        self.prepare_release_dir(self.loacal_dist_dir)

        self.xml_file = self.ap_version + ".xml"
        self.xml_file = os.path.join(self.manisest_xml_dir, self.xml_file)
        self.get_manifest_xml()


    def close_build(self):
        pass

    def start(self):
        self.prepare_build()
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
            if board in ["crane_evb_dcxo", "craneg_evb_z2_dcxo","craneg_evb_z2_from_crane_dcxo","sdk009_crane_evb_dcxo"]:
                continue
            self.git_clean()
            self.release_zip_file = self.board_info.get(board, {}).get("build_zip_file","")
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
                if board in ["mHAL"]:
                    _rel_dir = os.path.join(_root_dir,"build","rel")
                    if os.path.exists(_rel_dir):
                        os.chmod(_rel_dir,0o777)
                        _root_dir = _rel_dir
                compile_log_file = os.path.join(self.compile_log_dir, os.path.basename(self.git_version_dir) + "_compile_"+board+".txt")
                self.build(_root_dir, compile_log=compile_log_file, cmd=build_cmd)
                if self.build_res in "FAIL":
                    self.send_email(_root_dir, owner, self.release_dist, board)
                    break

            kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')

            if self.build_res in "FAIL" and board in ["crane_evb", "craneg_evb_a0", "cranec_evb",
                                                                   "cranem_evb_a0", "cranem_dm_evb_a0","visenk_phone"]:
                self.log.error(self.loacal_dist_dir, "build fail")
                return self.loacal_dist_dir
            elif self.build_res in "FAIL":
                continue

            try:
                self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir, board = board)
            except Exception,e:
                self.log.error(e)
                self.build_res = "FAIL"
                self.send_email(_root_dir, owner, self.release_dist, board)
                return self.loacal_dist_dir
            try:
                self.copy_sdk_files_to_release_dir(self.download_tool_images_dir_d[board], board, self.build_root_dir)
            except Exception,e:
                self.log.error(e)

            # create cp framework
            # if board in ["mHAL"]:
                # hallib_dir = os.path.join(self.build_root_dir, self.release_zip_file)
                # create_cp_framework(self.build_root_dir, hallib_dir, os.path.join(self.loacal_dist_dir, board))

            if self.build_res == "SUCCESS":
                _root_dir = self.download_tool_images_dir_d[board]
                _images = [os.path.join(_root_dir,_file) for _file in os.listdir(_root_dir)]
                try:
                    self.prepare_download_tool(_images)
                    self.download_controller.release_download_tool(os.path.basename(self.loacal_dist_dir), board,
                                                          dist_dir=self.download_tool_dir_d[board], download_tool_l = self.download_tool_l)
                except Exception,e:
                    self.log.error(e)
                if board in ["crane_evb", "craneg_evb_z2","craneg_evb_z2_from_crane","sdk009_crane_evb"]:
                    board = board+"_dcxo"
                    if board not in self.board_list:
                        continue
                    self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir, board = board)
                    self.copy_sdk_files_to_release_dir(self.download_tool_images_dir_d[board], board, self.build_root_dir)
                    _root_dir = self.download_tool_images_dir_d[board]
                    _images = [os.path.join(_root_dir,_file) for _file in os.listdir(_root_dir)]
                    self.prepare_download_tool(_images)
                    self.download_controller.release_download_tool(os.path.basename(self.loacal_dist_dir), board,
                                                          dist_dir=self.download_tool_dir_d[board], download_tool_l = self.download_tool_l)

        copy(self.loacal_dist_dir, self.release_dist)
        self.record_version()
        self.build_res = "SUCCESS"
        self.send_email(self.build_root_dir, owner, self.release_dist, subject_str = r"%s %s build done" % (self.__class__.__name__, self.ap_version.upper()))
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
        self.git_clean()
        self.trigger_auto_test(self.release_dist, None, "crane_evb")
        self.trigger_auto_test(self.release_dist, "crane_evb_z2_fwp",  board="crane_evb_fwp")
        self.trigger_auto_test(self.release_dist, "crane_evb_z2_dcxo",  board="crane_evb_dcxo")
        if self.cp_version not in self.old_cp_version:
            self.sdk_update_flag.set()

    @property
    def condition(self):
        self.update()
        info_d = self._repo.sync()
        for storage, info in info_d.items():
            if "Already up to date." in info:
                continue
            if storage == ".":
                info_bak = info.replace("\n","##")
                _match = re.findall("Fast-forward(.*?) file.*?changed,", info_bak)
                if _match:
                    info_bak = _match[0]
                else:
                    continue
                # self.log.info(info_bak.split("##"))
                for _info in info_bak.split("##")[:-1]:
                    _info = _info.strip()
                    if not _info:
                        continue
                    if _info.startswith("cus/evb") or _info.startswith(".../"):
                        continue
                    else:
                        return True
                continue
            if "Already up to date." not in info:
                return True
        return False


class CraneAliOSDailyBuild(CraneDailyBuild):
    def __init__(self, _repo):
        super(CraneAliOSDailyBuild, self).__init__(_repo)
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "master"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane_alios"]
        self.board_list = self.config_d["boards"]

    def close_build(self):
        if self.cp_version not in self.old_cp_version:
            self.sdk_update_flag.set()
        self.git_clean()
        self.trigger_auto_test(self.release_dist, None, "crane_evb")
        self.trigger_auto_test(self.release_dist, "crane_evb_z2_dcxo",  board="crane_evb_dcxo")


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
        self.trigger_auto_test(self.release_dist, "craneg_a0_evb", board="craneg_evb_a0")

    @property
    def condition(self):
        self.update()
        info_d = self._repo.sync()
        for storage, info in info_d.items():
            if "Already up to date." in info:
                continue
            # if storage == "cp":
                # continue
            if storage == ".":
                info_bak = info.replace("\n","##")
                _match = re.findall("Fast-forward(.*?) file.*?changed,", info_bak)
                if _match:
                    info_bak = _match[0]
                else:
                    continue
                # self.log.info(info_bak.split("##"))
                for _info in info_bak.split("##")[:-1]:
                    _info = _info.strip()
                    if not _info:
                        continue
                    if _info.startswith("cus/evb") or _info.startswith(".../"):
                        continue
                    else:
                        self.log.info(_info)
                        return True
                continue
            if "Already up to date." not in info:
                return True
        return False

class CraneMDailyBuild(MyDailyBuildBase):
    def __init__(self, _repo):
        super(CraneMDailyBuild, self).__init__(_repo)
        super(BuildBase, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "master"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cranem"]
        self.board_list = self.config_d["boards"]

    @property
    def condition(self):
        self.update()
        info_d = self._repo.sync()
        for storage, info in info_d.items():
            if "Already up to date." in info:
                continue

            if storage == ".":
                info_bak = info.replace("\n","##")
                _match = re.findall("Fast-forward(.*?) file.*?changed,", info_bak)
                if _match:
                    info_bak = _match[0]
                else:
                    continue
                # self.log.info(info_bak.split("##"))
                for _info in info_bak.split("##")[:-1]:
                    _info = _info.strip()
                    if not _info:
                        continue
                    if _info.startswith("cus/evb") or _info.startswith(".../"):
                        continue
                    else:
                        return True
                continue
            if "Already up to date." not in info:
                return True
        return False

    def close_build(self):
        if self.cp_version not in self.old_cp_version:
            self.sdk_update_flag.set()
        self.git_clean()
        self.trigger_auto_test(self.release_dist, "cranem_evb", board="cranem_evb_a0")

class CraneCDailyBuild(MyDailyBuildBase):
    def __init__(self, _repo):
        super(CraneCDailyBuild, self).__init__(_repo)
        super(BuildBase, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "master"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cranec"]
        self.board_list = self.config_d["boards"]

    @property
    def condition(self):
        self.update()
        info_d = self._repo.sync()
        for storage, info in info_d.items():
            if "Already up to date." in info:
                continue

            if storage == ".":
                info_bak = info.replace("\n","##")
                _match = re.findall("Fast-forward(.*?) file.*?changed,", info_bak)
                if _match:
                    info_bak = _match[0]
                else:
                    continue
                # self.log.info(info_bak.split("##"))
                for _info in info_bak.split("##")[:-1]:
                    _info = _info.strip()
                    if not _info:
                        continue
                    if _info.startswith("cus/evb") or _info.startswith(".../"):
                        continue
                    else:
                        return True
                continue
            if "Already up to date." not in info:
                return True
        return False

    def close_build(self):
        self.trigger_auto_test(self.release_dist, "cranec_evb", "cranec_evb")
        self.git_clean()


class CraneMDMDailyBuild(MyDailyBuildBase):
    def __init__(self, _repo):
        super(CraneMDMDailyBuild, self).__init__(_repo)
        super(BuildBase, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "master"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cranem_dm"]
        self.board_list = self.config_d["boards"]

    def update_download_tool(self, root_dir=None):
        # self.download_controller.update_download_tool()
        if not root_dir:
            root_dir = self.build_root_dir
        download_tool_dir = os.path.join(root_dir, "tool", "downloadtool")
        self.download_tool_l = [os.path.join(download_tool_dir, _tool) for _tool in os.listdir(download_tool_dir) if re.match("aboot-[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]-x[0-9][0-9]",_tool)]
        for _tool in self.download_tool_l:
            self.log.info(_tool)

    @property
    def condition(self):
        self.update()
        info_d = self._repo.sync()
        for storage, info in info_d.items():
            if "Already up to date." in info:
                continue
            if storage == "cp":
                continue
            if storage == ".":
                info_bak = info.replace("\n","##")
                _match = re.findall("Fast-forward(.*?) file.*?changed,", info_bak)
                if _match:
                    info_bak = _match[0]
                else:
                    continue
                # self.log.info(info_bak.split("##"))
                for _info in info_bak.split("##")[:-1]:
                    _info = _info.strip()
                    if not _info:
                        continue
                    if _info.startswith("cus/evb") or _info.startswith(".../"):
                        continue
                    else:
                        return True
                continue
            if "Already up to date." not in info:
                return True
        return False

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
        self.sdk_release_notes_file = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20201006_SDK\ReleaseNotes.xlsx"
        self.sdk_release_notes_dir = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20201006_SDK"

    def find_newest_notes(self):
        _root_dir = os.path.join(self.git_root_dir, "note")
        release_note_list = [_file for _file in os.listdir(_root_dir) if _file.startswith("ReleaseNotes") and _file.endswith(".xlsx")]
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

        self.old_cp_version = self.get_old_cp_version()
        self.cp_version = self.update_cp_version()

        date = time.strftime("%Y%m%d_%H%M%S")
        _match = re.findall("\[(SDK_[0-9]\.[0-9][0-9][0-9]\.[0-9][0-9][0-9])\]", self.cp_version)
        sdk_version = _match[0] if _match else ""
        file_name = "%s_%s_%s" % (self.ap_version, sdk_version, date)
        self.loacal_dist_dir = os.path.join(os.path.dirname(self.git_root_dir), file_name)
        self.release_dist = os.path.join(self.release_dist_dir, file_name)
        self.loacal_dist_dir = os.path.join(self.local_storage_dir,file_name)
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
        self.trigger_auto_test(self.release_dist, "evb_customer", "crane_evb")
        self.trigger_auto_test(self.release_dist, "crane_evb_z2_dcxo_rc", "crane_evb_dcxo")
        self.trigger_auto_test(self.release_dist, "crane_evb_z2_fwp_rc", "crane_evb_fwp")
        self.git_clean()


class CusSDK009Build(CusBuild):
    def __init__(self, _repo_cus):
        super(CusSDK009Build, self).__init__(_repo_cus)
        self.log = MyLogger(self.__class__.__name__)

    def config(self):
        self.sdk_release_notes_file = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200803_SDK\ReleaseNotes.xlsx"
        self.sdk_release_notes_dir = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200803_SDK"

    def get_config(self):
        self.release_branch = "master"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane_sdk009"]
        self.board_list = self.config_d["boards"][:]
        for board in self.board_list:
            self.config_d["boards_info"][board]["images"].remove("uirespkg.bin") if "uirespkg.bin" in self.config_d["boards_info"][board]["images"] else None


class CusR2RCSDKBuild(CusBuild):
    def __init__(self, _repo_cus):
        super(CusR2RCSDKBuild, self).__init__(_repo_cus)
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "r2_rc"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane"]
        self.board_list = ["crane_evb","crane_evb_dcxo", "visenk_phone","crane_evb_128x160", "crane_evb_176x220","crane_evb_fwp","crane_evb_fwp_128x64"]

    def config(self):
        self.release_branch = "r2_rc"
        self.sdk_release_notes_file = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200425_SDK\ReleaseNotes.xlsx"
        self.sdk_release_notes_dir = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200425_SDK"

    def close_build(self):
        if self.cp_version not in self.old_cp_version:
            # to_address = 'yuanzhizheng@asrmicro.com'
            to_address = ",".join(['yuanzhizheng@asrmicro.com','miantianyu@asrmicro.com'])
            subject = "%s RELEASE" % self.cp_version
            msg = r"Hi %s, %s build done! Binary dir: %s" % (to_address.split("@")[0], self.cp_version, self.release_dist)
            send_email_tool(to_address, subject.upper(), msg)
        self.trigger_auto_test(self.release_dist, "evb_customer", "crane_evb")
        # self.trigger_auto_test(self.release_dist, "evb_customer", "sdk009_crane_evb")
        self.trigger_auto_test(self.release_dist, "crane_evb_z2_dcxo_rc", "crane_evb_dcxo")
        self.trigger_auto_test(self.release_dist, "crane_evb_z2_fwp_rc", "crane_evb_fwp")
        self.git_clean()

class CusR2RCSDK008Build(CusBuild):
    def __init__(self, _repo_cus):
        super(CusR2RCSDK008Build, self).__init__(_repo_cus)
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "r2_rc"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane_sdk008"]
        self.board_list = self.config_d["boards"]

    def config(self):
        self.release_branch = "r2_rc"
        self.sdk_release_notes_file = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200425_SDK\ReleaseNotes.xlsx"
        self.sdk_release_notes_dir = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200425_SDK"

    def close_build(self):
        if self.cp_version not in self.old_cp_version:
            # to_address = 'yuanzhizheng@asrmicro.com'
            to_address = ",".join(['yuanzhizheng@asrmicro.com','miantianyu@asrmicro.com'])
            subject = "%s RELEASE" % self.cp_version
            msg = r"Hi %s, %s build done! Binary dir: %s" % (to_address.split("@")[0], self.cp_version, self.release_dist)
            send_email_tool(to_address, subject.upper(), msg)
        self.trigger_auto_test(self.release_dist, "evb_customer", "crane_evb")
        self.trigger_auto_test(self.release_dist, "crane_evb_z2_fwp_rc", "crane_evb_fwp")
        self.git_clean()

class CusR2RCSDK009Build(CusBuild):
    def __init__(self, _repo_cus):
        super(CusR2RCSDK009Build, self).__init__(_repo_cus)
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "r2_rc"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane_sdk009"]
        self.board_list = self.config_d["boards"]

    def config(self):
        self.release_branch = "r2_rc"
        self.sdk_release_notes_file = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200803_SDK\ReleaseNotes.xlsx"
        self.sdk_release_notes_dir = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200803_SDK"

    def close_build(self):
        if self.cp_version not in self.old_cp_version:
            # to_address = 'yuanzhizheng@asrmicro.com'
            to_address = ",".join(['yuanzhizheng@asrmicro.com','miantianyu@asrmicro.com'])
            subject = "%s RELEASE" % self.cp_version
            msg = r"Hi %s, %s build done! Binary dir: %s" % (to_address.split("@")[0], self.cp_version, self.release_dist)
            send_email_tool(to_address, subject.upper(), msg)
        self.trigger_auto_test(self.release_dist, "evb_customer", "crane_evb")
        self.trigger_auto_test(self.release_dist, "crane_evb_z2_dcxo_rc", "crane_evb_dcxo")
        self.trigger_auto_test(self.release_dist, "crane_evb_z2_fwp_rc", "crane_evb_fwp")
        self.git_clean()

class CraneCR2RCBuild(CusBuild):
    def __init__(self, _repo_cus):
        super(CraneCR2RCBuild, self).__init__(_repo_cus)
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "r2_rc"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cranec_r2_rc"]
        self.board_list = self.config_d["boards"]

    def config(self):
        self.release_branch = "r2_rc"
        self.sdk_release_notes_file = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200803_SDK\ReleaseNotes.xlsx"
        self.sdk_release_notes_dir = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20200803_SDK"

    def close_build(self):
        self.trigger_auto_test(self.release_dist, "cranec_evb", "cranec_evb")
        self.git_clean()


class CusFTBuild(CusBuild):
    def __init__(self, _repo_cus):
        super(CusFTBuild, self).__init__(_repo_cus)
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "crane_ft"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane_ft"]
        self.board_list = self.config_d["boards"][:]

    def close_build(self):
        self.trigger_auto_test(self.release_dist, "crane_ft_d_visenk", "visenk_phone")
        self.trigger_auto_test(self.release_dist, "crane_ft_d_xinxiang", "xinxiang_phone")
        self.git_clean()


class CusCraneGBuild(CusBuild):
    def __init__(self, _repo_cus):
        super(CusCraneGBuild, self).__init__(_repo_cus)
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "r2_rc"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["craneg"]
        self.board_list = self.config_d["boards"]

    def config(self):
        self.release_branch = "r2_rc"
        self.sdk_release_notes_file = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20201127_SDK\ReleaseNotes.xlsx"
        self.sdk_release_notes_dir = r"\\sh2-filer02\Release\LTE\SDK\Crane\FeaturePhone\Mixture\ASR3601_MINIGUI_20201127_SDK"

    def close_build(self):
        if self.cp_version not in self.old_cp_version:
            # to_address = 'yuanzhizheng@asrmicro.com'
            to_address = ",".join(['yuanzhizheng@asrmicro.com','miantianyu@asrmicro.com'])
            subject = "%s RELEASE" % self.cp_version
            msg = r"Hi %s, %s build done! Binary dir: %s" % (to_address.split("@")[0], self.cp_version, self.release_dist)
            send_email_tool(to_address, subject.upper(), msg)
        self.trigger_auto_test(self.release_dist, "craneg_a0_evb", board="craneg_evb_a0")
        self.git_clean()


class CusR1RCBuild(CusBuild):
    def __init__(self, _repo_cus):
        super(CusR1RCBuild, self).__init__(_repo_cus)
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        self.release_branch = "r1_rc"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane_r1_rc"]
        self.board_list = self.config_d["boards"]

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
        self.trigger_auto_test(self.release_dist, "evb_customer_r1", "crane_evb")
        self.git_clean()

    def create_download_tool(self, release_name, borad="crane_evb", dist_dir=None):
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
        with ziptool_mutex:
            self.zip_tool.make_archive_e(dist,"zip",release_dir)
        shutil.rmtree(release_dir)

    def copy_sdk_files_to_release_dir(self, dist_dir, board="crane_evb", src_dir=None):
        if not src_dir:
            src_dir = self.build_root_dir
        self.images = self.board_info.get(board, {}).get("images",[])

        src_bin_l = self.board_info.get(board, {}).get("release_bin",[])
        src_bin_l = [os.path.join(src_dir, _file) for _file in src_bin_l]
        dist_bin_l = [os.path.join(dist_dir, _file) for _file in self.images]

        for src_bin, dist_bin in zip(src_bin_l, dist_bin_l):
            if os.path.exists(src_bin):
                copy(src_bin, dist_bin)

    def start(self):
        self.prepare_build()
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
            self.release_zip_file = self.board_info.get(board, {}).get("build_zip_file","")
            build_cmd = self.board_info.get(board, {}).get("build_cmd",'')
            assert build_cmd,"%s no build cmd" % board
            self.log.info("-" * 80)
            self.log.info("patch owner:", owner)
            self.log.info("patch time :", date)
            self.log.info("board name :", board)
            self.log.info("build cmd  :", build_cmd)
            self.log.info("-" * 80)
            compile_log_file = os.path.join(self.compile_log_dir, os.path.basename(self.git_version_dir) + "_compile_"+board+".txt")
            self.build(self.build_root_dir, compile_log=compile_log_file, cmd=build_cmd)
            if self.build_res in "FAIL":
                self.send_email(self.build_root_dir, owner, self.release_dist, board)

            kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')

            if board in self.board_list[0] and self.build_res in "FAIL":
                self.log.info(self.loacal_dist_dir, "build fail")
                return self.loacal_dist_dir

            self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir, board = board)

            if "ASR_CRANE_EVB_CRANE_A0_16MB_DCXO" in self.build_zip_file:
                self.build_zip_file = self.build_zip_file.replace("ASR_CRANE_EVB_CRANE_A0_16MB_DCXO","ASR_CRANE_EVB_CRANE_A0_16MB")

            try:
                self.copy_sdk_files_to_release_dir(self.download_tool_images_dir_d[board], board, self.build_root_dir)
            except Exception,e:
                self.log.error(e)
                dist_dir = self.download_tool_images_dir_d[board]
                with ziptool_mutex:
                    self.zip_tool.unpack_files_from_archive(self.build_zip_file, dist_dir, "dsp.bin", "rf.bin", "ReliableData.bin", "logo.bin", "updater.bin")

            if self.build_res == "SUCCESS":
                self.create_download_tool(os.path.basename(self.loacal_dist_dir), board, dist_dir=self.download_tool_dir_d[board])

        self.record_version()
        copy(self.loacal_dist_dir, self.release_dist)
        self.send_email(self.build_root_dir, owner, self.release_dist, board)
        self.close_build()

class ExternalBuild(CraneDailyBuild):
    def __init__(self, _repo_cus):
        super(ExternalBuild, self).__init__(_repo_cus)
        self.log = MyLogger(self.__class__.__name__)
        self.trigger_config = ""

    def get_config(self):
        self.release_branch = "master"
        json_file = os.path.join(self.root_dir,"json","build.json")
        json_str = load_json(json_file)
        self.config_d = json_str["external_build"]
        self.board_list = self.config_d["boards"]

    def record_config(self):
        for _line in fileinput.input(self.trigger_config,inplace=1):
            if "build_version" in _line:
                print _line.replace("default",os.path.basename(self.release_dist)).rstrip()
            elif "build_status" in _line:
                print _line.replace("ongoing","done").rstrip()
            else:
                print _line.rstrip()

    def prepare_build(self):
        for _line in fileinput.input(self.trigger_config,inplace=1):
            if "build_status" in _line and "start" in _line:
                print _line.replace("start","ongoing").rstrip()
            else:
                print _line.rstrip()

        self.clean_sdk()
        self.copy_sdk()

        self.ap_version = self.get_ap_version()
        self.record_ap_version(self.ap_version)

        self.old_cp_version = self.get_old_cp_version()
        self.cp_version = self.update_cp_version()

        date = time.strftime("%Y%m%d_%H%M%S")
        _match = re.findall("\[(SDK_[0-9]\.[0-9][0-9][0-9]\.[0-9][0-9][0-9])\]", self.cp_version)
        sdk_version = _match[0] if _match else ""
        file_name = "%s_%s_%s" % (self.ap_version, sdk_version, date)

        self.loacal_dist_dir = os.path.join(os.path.dirname(self.git_root_dir), file_name)
        self.release_dist = os.path.join(self.release_dist_dir, file_name)
        self.loacal_dist_dir = os.path.join(self.local_storage_dir,file_name)
        self.prepare_release_dir(self.loacal_dist_dir)
        try:
            self.xml_file = self.ap_version + ".xml"
            self.xml_file = os.path.join(self.manisest_xml_dir, self.xml_file)
            self.get_manifest_xml()
        except:
            self.log.info("get_manifest_xml fail")
        self.log.info("prepare_build done")

    def clean_sdk(self):
        cp_dir = os.path.join(self.build_root_dir,"cp")
        for _file in os.listdir(cp_dir):
            if _file in [".git","X.bat"]:
                continue
            _file = os.path.join(cp_dir,_file)
            if os.path.isfile(_file):
                os.remove(_file)
            else:
                shutil.rmtree(_file)
        self.log.info("clean cp done")

    def delete_gui_lib(self,path_dir):
        if not os.path.exists(path_dir):
            assert ("%r not exists" % path_dir)
        for _file in os.listdir(path_dir):
            self.log.info(os.path.join(path_dir,_file))
            if _file in ["libmgapollo.a","libmgngux.a","libmgminigui.a","libtarget.a","libthirdparty.a","libmgmgeff.a",
                         "libhal.a","hal_init.o"]:
                os.remove(os.path.join(path_dir,_file))
        self.log.info("delete_gui_lib done.")

    def copy_sdk(self):
        root_dir = os.path.normpath(self.external_config_dict["sdk_src"])
        target_dist_dir = os.path.normpath(os.path.join(self.build_root_dir,"cp"))
        for root,dirs,files in os.walk(root_dir,topdown=False):
            if "3g_ps" in dirs:
                self.cp_sdk_root_dir = root
                break
        gui_lib = os.path.join(self.cp_sdk_root_dir,"tavor","Arbel","lib")
        self.delete_gui_lib(gui_lib)
        self.log.info("copy %s..." % self.cp_sdk_root_dir)
        for _file in os.listdir(self.cp_sdk_root_dir):
            fname = os.path.join(self.cp_sdk_root_dir,_file)
            copy(fname, os.path.join(target_dist_dir,_file))
        time.sleep(3)
        self.log.info("copy done.")

    def get_external_config(self):
        external_config_dir = r"\\sh2-filer02\Data\FP_RLS\external_build\trigger_config"
        self.release_dist_dir = r"\\sh2-filer02\Data\FP_RLS\external_build\release_dir"
        config_list = [os.path.join(external_config_dir, _file) for _file in os.listdir(external_config_dir) if _file.endswith(".json")]
        config_list.sort(key=lambda fn: os.path.getmtime(fn))
        for _file in config_list:
            json_config = load_json(_file)
            if "start" in json_config["build_status"]:
                self.trigger_config = _file
                self.board_list = []
                self.external_config_dict = json_config
                if self.external_config_dict["board_type"]:
                    self.board_list = [board for board in self.external_config_dict["board_type"] if board in self.config_d["boards"]]
                else:
                    self.board_list = ["crane_evb", "craneg_evb"]
                self.log.info(self.trigger_config)
                return True
        return False

    @property
    def condition(self):
        # self.update()
        # info_d = self._repo.sync()
        return self.get_external_config()

    def send_email_start_trigger(self):
        to_address = self.external_config_dict["owner"]
        subject = "EXTERNAL BUILD START"
        msg = r"Hi %s, your trigger build start!" % (to_address.split("@")[0])
        send_email_tool(to_address, subject.upper(), msg)

    def close_build(self):
        to_address = self.external_config_dict["owner"]
        subject = "EXTERNAL BUILD RELEASE"
        msg = r"Hi %s, your trigger build done! Binary dir: %s" % (to_address.split("@")[0], self.release_dist)
        send_email_tool(to_address, subject.upper(), msg)
        self.record_config()
        # self.trigger_auto_test(self.release_dist, None, "crane_evb")
        # self.trigger_auto_test(self.release_dist, "crane_evb_dcxo", "crane_evb_dcxo")
        self.git_clean()

    def send_email(self, cur_dir, owner, external_dir, board="crane_evb", subject_str = None):
        os.chdir(cur_dir)
        owner = self.external_config_dict["owner"]
        if self.build_res in "FAIL":
            att_file_list = [self.hal_build_log, self.gui_build_log, self.cp_build_log, self.link_log,self.release_log]
            att_file_list = [os.path.join(cur_dir,_file) for _file in att_file_list]
            # att_file_list.append(self.compile_log)
            att_file = '@'.join(att_file_list)
            if subject_str:
                subject = subject_str
            else:
                subject = r"%s %s build result: fail" % (self.__class__.__name__, board)
            msg = r"Hi %s, your patch build fail! Pls check attachment log" % (owner.split("@")[0])
            to_address = owner

        self.log.info(att_file)
        send_email_tool(to_address, subject, msg, att_file)
        self.log.info("send email done")


    def start(self):
        self.prepare_build()
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

        self.send_email_start_trigger()

        for board in self.board_list:
            if board in ["crane_evb_dcxo", "craneg_evb_z2_dcxo","craneg_evb_z2_from_crane_dcxo","sdk009_crane_evb_dcxo"]:
                continue
            # self.git_clean()
            self.release_zip_file = self.board_info.get(board, {}).get("build_zip_file","")
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
                if board in ["mHAL"]:
                    _rel_dir = os.path.join(_root_dir,"build","rel")
                    if os.path.exists(_rel_dir):
                        os.chmod(_rel_dir,0o777)
                        _root_dir = _rel_dir
                compile_log_file = os.path.join(self.compile_log_dir, os.path.basename(self.git_version_dir) + "_compile_"+board+".txt")
                self.build(_root_dir, compile_log=compile_log_file, cmd=build_cmd)
                if self.build_res in "FAIL":
                    self.send_email(_root_dir, owner, self.release_dist, board)
                    break

            # kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')

            if board in ["crane_evb", "crane_evb_dcxo", "visenk_phone","craneg_evb_a0",\
                         "cranem_evb_a0","cranem_dm_evb_a0","crane_evb_fwp","craneg_evb_z2",\
                            '''"bird_phone", "crane_evb_128x160" ''',\
                             '''"craneg_evb_z2_dcxo","craneg_evb_a0","xinxiang_phone"'''] and self.build_res in "FAIL":
                self.log.error(self.loacal_dist_dir, "build fail")
                return self.loacal_dist_dir
            elif self.build_res in "FAIL":
                continue

            try:
                self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir, board = board)
            except Exception,e:
                self.log.error(e)
                self.build_res = "FAIL"
                self.send_email(_root_dir, owner, self.release_dist, board)
                return self.loacal_dist_dir
            try:
                self.copy_sdk_files_to_release_dir(self.download_tool_images_dir_d[board], board, self.build_root_dir)
            except Exception,e:
                self.log.error(e)

            if self.build_res == "SUCCESS":
                _root_dir = self.download_tool_images_dir_d[board]
                _images = [os.path.join(_root_dir,_file) for _file in os.listdir(_root_dir)]
                try:
                    self.prepare_download_tool(_images)
                    self.download_controller.release_download_tool(os.path.basename(self.loacal_dist_dir), board,
                                                          dist_dir=self.download_tool_dir_d[board], download_tool_l = self.download_tool_l)
                except Exception,e:
                    self.log.error(e)
                if board in ["crane_evb", "craneg_evb_z2","craneg_evb_z2_from_crane","sdk009_crane_evb"]:
                    board = board+"_dcxo"
                    if board not in self.board_list:
                        continue
                    self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir, board = board)
                    self.copy_sdk_files_to_release_dir(self.download_tool_images_dir_d[board], board, self.build_root_dir)
                    _root_dir = self.download_tool_images_dir_d[board]
                    _images = [os.path.join(_root_dir,_file) for _file in os.listdir(_root_dir)]
                    self.prepare_download_tool(_images)
                    self.download_controller.release_download_tool(os.path.basename(self.loacal_dist_dir), board,
                                                          dist_dir=self.download_tool_dir_d[board], download_tool_l = self.download_tool_l)

        copy(self.loacal_dist_dir, self.release_dist)
        self.record_version()
        self.build_res = "SUCCESS"
        self.close_build()
