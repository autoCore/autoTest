#!usr/bin/env python

import sys
import os
import time

from util import *
from git_push_cp import *
from release_zip import *
from send_email import *
from ftp import ftp_upload_file
from TriggerTest import trigger_test
from myrepo import *
from util import config

reload(sys)
sys.setdefaultencoding("utf-8")

email_subject = "CRANE PHONE: AUTO RELEASE %s"
email_msg = r"""
GUI VERSION: {0}
CP VERSION: {1}
DSP VERSION: {2}

NORMAL VERSION(SINGLE and DUAL SIM):
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\crane_evb_z2
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\download_tool\crane_evb_z2

BIRD PHONE VERSION:
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\{3}\bird_phone
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\download_tool\bird_phone

"""
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

CUSTOMER RELEASE:
CP VERSION: {4}
DSP VERSION: {5}

RELEASE VERSION: {6}
"""


def copy(src, dist):
    assert os.path.exists(src), "%s not exists" % src
    logger.info("copy %s start..." % src)
    if os.path.isfile(src):
        shutil.copy2(src, dist)
    elif os.path.isdir(src):
        shutil.copytree(src, dist)
    logger.info("copy done.")


class BuildController(object):
    def __init__(self, _cfg):
        self.build_res = None
        self.log = MyLogger(self.__class__.__name__)
        self.compile_log_dir = _cfg.compile_log_dir

        self.git_version_dir = None

        self.gui_build_log = os.path.join(".", 'build', 'crane_evb_z2', r'gui_build.log')
        self.hal_build_log = os.path.join(".", 'build', 'crane_evb_z2', r'hal_build.log')
        self.cp_build_log = os.path.join(".", 'build', 'crane_evb_z2', r'cp_build.log')
        self.link_log = os.path.join(".", 'build', 'crane_evb_z2', r'fp_link_build.log')
        self.compile_log = "compile.log"

    def build(self, cur_dir, build_dir='crane_evb_z2', compile_log='', cmd=''):
        os.chdir(cur_dir)
        self.log.info("%s build start..." % cur_dir)
        # cmd = "autobuild.bat %s> %s"%(build_dir,compile_log)
        if not cmd:
            cmd = "autobuild.bat"
        if compile_log:
            self.compile_log = os.path.join(self.compile_log_dir, compile_log)
        else:
            self.compile_log = os.path.join(self.compile_log_dir, os.path.basename(self.git_version_dir) + ".log")
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
    def __init__(self, _cfg, _repo):
        self._repo = _repo
        self.log = MyLogger(self.__class__.__name__)
        self.build_root_dir = _repo.build_root_dir
        self.git_root_dir = _repo.root_path

        self.release_dist_dir = _repo.release_dist_dir

        self.board_list = []
        self.board_info = _cfg.BOARD_INFO
        self.build_images = _cfg.BUILD_IMAGES[1:-1]

        self.mdb_file_dir = os.path.join(self.build_root_dir, _cfg.mdb_file_dir)


        self.sdk_files_dict = _cfg.BOARD_CP_RELEASE_BIN_DICT
        self.sdk_images = _cfg.IMAGES[:]
 
        self.cp_version_file = os.path.join(self.build_root_dir, _cfg.cp_version_file)
        self.dsp_bin = os.path.join(self.build_root_dir, "cus", "evb", "images", "dsp.bin")

        self.ap_version_log = _repo.ap_version_log
        self.cp_version_log = _repo.cp_version_log
        self.dsp_version_log = _repo.dsp_version_log


        self.tmp_dir = _cfg.tmp_dir
        self.decompress_tool = _cfg.decompress_tool

        self.manisest_xml_dir = _cfg.manisest_xml_dir

        self.xml_file = ''
        self.massage_file = ''
        self.cp_version = ''
        self.dsp_version = ''

        self.loacal_dist_dir = ''
        self.loacal_build_dir_d = {}
        self.download_tool_dir_d = {}
        self.download_tool_images_dir_d = {}
        self.version_info_dir = ''


    def get_dsp_version(self, dsp_bin):
        "!CRANE_CAT1GSM_L1_1.043.000 , Dec 13 2019 03:30:56"
        dsp_version_file = os.path.join(self.tmp_dir, "dsp_version.bin")
        decompress_cmd = "{0} -d -f {1} -o{2}".format(self.decompress_tool, dsp_bin, dsp_version_file)
        os.system(decompress_cmd)
        assert os.path.exists(dsp_version_file), "can not find {}".format(dsp_version_file)
        with open(dsp_version_file, "rb") as fob:
            text = fob.read()
        # match = re.findall("!(CRANE_.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])",text)
        fob.close()
        match = re.findall("(CRANE_.{47})", text)
        if match:
            version_info = match[0]
            self.log.debug(version_info)
            self.dsp_version = version_info
        else:
            version_info = "can not match dsp version".upper()
        with open(self.dsp_version_log, "w") as obj:
            obj.write(version_info)
        return version_info

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
        # src_bin_l = self.sdk_files_dict.get(board, [])
        src_bin_l = self.board_info.get(board, {}).get("release_bin",[])
        src_bin_l = [os.path.join(src_dir, _file) for _file in src_bin_l]
        dist_bin_l = [os.path.join(dist_dir, _file) for _file in self.sdk_files_dict.get("IMAGES", [])]
        for src_bin, dist_bin in zip(src_bin_l, dist_bin_l):
            copy(src_bin, dist_bin)

    def create_download_tool(self):
        download_controller.update_download_tool()
        for board in self.board_list:
            try:
                _root_dir = self.download_tool_images_dir_d[board]
                _images = [os.path.join(_root_dir,_file) for _file in os.listdir(_root_dir)]
                download_controller.prepare_download_tool(_images)
                download_controller.release_zip(os.path.dirname(_root_dir))
                download_controller.release_download_tool(os.path.basename(self.loacal_dist_dir), board,
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


    def record_ap_version(self, version):
        with open(self.ap_version_log, 'w') as _obj:
            _obj.write(version.upper())


    @property
    def condition(self):
        return self._repo.sync()

    def build(self):
        pass


class DailyBuild(BuildBase):
    def __init__(self, _cfg, _repo):
        super(DailyBuild, self).__init__(_cfg, _repo)
        self.board_list = _cfg.BOARD_LIST[:]
        self.log = MyLogger(self.__class__.__name__)

    def build(self):
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

        build_controller.git_version_dir = self.loacal_dist_dir

        self.prepare_release_dir(self.loacal_dist_dir)
        self.copy_version_file_to_release_dir()

        download_controller.update_download_tool()

        for board in self.board_list:
            self.git_clean()
            build_cmd = self.board_info.get(board, {}).get("build_cmd",'')
            assert build_cmd,"%s no build cmd" % board
            build_controller.build(self.build_root_dir, cmd=build_cmd)
            build_controller.send_email(self.build_root_dir, owner, os.path.join(self.release_dist_dir, file_name), board)

            kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')

            if board in self.board_list[0] and build_controller.build_res in "FAIL":
                self.log.info(self.loacal_dist_dir, "build fail")
                return self.loacal_dist_dir

            self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir)
            self.copy_sdk_files_to_release_dir(self.download_tool_images_dir_d[board], board, self.build_root_dir)

            if build_controller.build_res == "SUCCESS":
                _root_dir = self.download_tool_images_dir_d[board]
                _images = [os.path.join(_root_dir,_file) for _file in os.listdir(_root_dir)]
                download_controller.prepare_download_tool(_images)
                download_controller.release_zip(os.path.dirname(_root_dir))
                download_controller.release_download_tool(os.path.basename(self.loacal_dist_dir), board,
                                                          dist_dir=self.download_tool_dir_d[board])


        # self.create_download_tool()

        dist = os.path.join(self.release_dist_dir, file_name)
        copy(self.loacal_dist_dir, dist)

        self.log.info("old_cp_version: %s" % old_cp_version)
        self.log.info("new_cp_version: %s" % self.cp_version)
        if self.cp_version not in old_cp_version:
            RELEASE_EVENT.set()
        return self.loacal_dist_dir



class CusBuild(BuildBase):
    def __init__(self, _cfg, _repo_cus):
        super(CusBuild, self).__init__(_cfg, _repo_cus)
        self.log = MyLogger(self.__class__.__name__)
        self.sdk_release_notes_file = _cfg.cus_sdk_release_notes_file
        self.release_branch = _repo_cus.release_branch

        if self.release_branch == "master":
            self.board_list = _cfg.BOARD_LIST[:3]
        else: # ["r1", "r1_plus_j", "r1_1.006.027"]
            self.board_list = _cfg.BOARD_LIST[:1]


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

 
    def build(self):
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
        build_controller.git_version_dir = version_file

        self.prepare_release_dir(version_file)
        self.copy_version_file_to_release_dir()

        release_note = self.find_newest_notes()
        if release_note:
            copy(release_note, os.path.join(self.version_info_dir, os.path.basename(release_note)))

        for board in self.board_list:
            self.git_clean()
            build_cmd = self.board_info.get(board, {}).get("build_cmd",'')
            assert build_cmd,"%s no build cmd" % board
            build_controller.build(self.build_root_dir, cmd=build_cmd)
            build_controller.send_email(self.build_root_dir, owner, os.path.join(self.release_dist_dir, file_name),
                                        board)

            kill_win_process("mingw32-make.exe", 'cmake.exe', "make.exe", 'armcc.exe', 'wtee.exe')

            if board in self.board_list[0] and build_controller.build_res in "FAIL":
                self.log.info(self.loacal_dist_dir, "build fail")
                return self.loacal_dist_dir

            self.copy_build_file_to_release_dir(self.loacal_build_dir_d[board], self.build_root_dir)
            try:
                self.copy_sdk_files_to_release_dir(self.download_tool_images_dir_d[board], board, self.build_root_dir)
            except Exception,e:
                self.log.error(e)
            archive_file = os.path.join(self.build_root_dir,"build", "crane_evb_z2", "ASR_CRANE_EVB_A0_16MB.zip")
            dist_dir = self.download_tool_images_dir_d[board]
            time.sleep(5)
            zip_tool.unpack_files_from_archive(archive_file, dist_dir, "dsp.bin", "rf.bin", "ReliableData.bin", "logo.bin", "updater.bin")

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

    @staticmethod
    def get_release_version(_root_dir, dist_dir, target="crane_d"):
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
        listdir = [d for d in listdir if os.path.isdir(d) and target_dir in d] if isdir else [f for f in listdir if
                                                                                              os.path.isfile(
                                                                                                  f) and target_dir in f]
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
                self.clean_overdue_dir(cfg.download_tool_dir, 5, target_dir='MINIGUI_SDK_')
                self.clean_overdue_dir(cfg.download_tool_dir, 5, target_dir='CRANE_RELEASE_')
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
                        build_obj.build()
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


RELEASE_EVENT = threading.Event()

if __name__ == "__main__":
    root_dir = os.getcwd()

    cfg = config()
    cfg.update('config.ini')

    rootlogger = MyLogger()
    log_file = os.path.join(cfg.log_dir, "log_%s.txt" % time.strftime("%Y%m%d_%H%M%S"))
    rootlogger.reset_log_file(log_file)
    rootlogger.enable_print()
    rootlogger.set_level(logging.INFO)

    logger = MyLogger("build_release")
    prepare_system_start()

    zip_tool = zipTool()

    logger.debug(cfg)
    repo = DailyRepo(cfg)
    repo.update_cp_version(os.path.join(cfg.cur_crane, cfg.cp_version_file), cfg.cp_version_log)
    repo_cus = CusRepo(cfg)
    repo_cus.update_cp_version(os.path.join(cfg.cur_crane_cus, "evb", "src", cfg.cp_version_file),
                               cfg.release_cp_version_log)

    # noinspection PyTypeChecker
    build_controller = BuildController(cfg)
    download_controller = DownloadToolController(cfg)
    # download_controller.update_download_tool()

    # noinspection PyTypeChecker
    auto_daily_build_cls = DailyBuild(cfg, repo)
    # noinspection PyTypeChecker
    auto_cus_build_cls = CusBuild(cfg, repo_cus)


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
