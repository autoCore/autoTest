#!usr/bin/env python

import os
import datetime
import re
import git
from util import MyLogger, zipTool, load_json


manifest_xml = \
    """
<?xml version="1.0" encoding="UTF-8"?>
<manifest>
  <remote fetch=".." name="origin" review="https://source.asrmicro.com/"/>
  
  <default remote="origin" revision="master" sync-j="4"/>
  <project name="crane/crane-dev" path="crane" revision="{0[0]}" upstream="master"/>
  <project name="crane/cp" path="crane/cp" revision="{0[1]}" upstream="master"/>
  <project name="crane/gui" path="crane/gui" revision="{0[2]}" upstream="master"/>
  <project name="crane/tool" path="crane/tool" revision="{0[3]}" upstream="master"/>
</manifest>
"""

class ManagerVersionBase(object):
    def __init__(self):
        self.root_dir = os.getcwd()
        self.version_log = ""
        self.log = MyLogger(self.__class__.__name__)
        self.verion_name = ''
        self.cur_version = ''
        self.chip_ID = None
        self.OS_type = None
        self.ps_mode = None
        self.decompress_tool = zipTool()

        self.dsp_version_pattern = re.compile(r"(CRANE_.*?,.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9]|CRANEG_.*?,.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])")
        self.version_pattern = None

        self.cp_version = None
        self.dsp_version = None


    def _get_verion_name(self):
        assert os.path.exists(self.version_log),"%s no exists" % self.version_log
        with open(self.version_log) as flog:
            text = flog.read()
        text = text.replace('\n', '')
        text_list = self.version_pattern.findall(text)
        self.log.debug(text_list)
        if text_list:
            # assert text_list,"can not find version info"
            self.verion_name, _ = text_list[-1]
        else:
            self.verion_name = self.branch_name
        self.log.debug(self.verion_name)

    def get_nearest_version(self):
        assert os.path.exists(self.version_log),"%s no exists" % self.version_log
        with open(self.version_log) as flog:
            text = flog.read()
        text = text.replace('\n', '')
        # text_list = re.findall(r'crane_git_r([0-9]+)',text)
        text_list = self.version_pattern.findall(text)
        self.log.debug(text_list)
        if text_list:
            # assert text_list,"can not find version info"
            self.verion_name, cnt = text_list[-1]
            cnt = int(cnt)
            version = "%s%04d" % (self.verion_name, cnt + 1)
            # self.log.info(version)
        else:
            version = self.branch_name
        return version

    def record_version(self, version='', info=''):
        flog = open(self.version_log, 'a')
        if not version:
            version = self.get_nearest_version()
        if not info:
            info = self.get_revion_info()
        text = "\n".join([version + ":", info])
        flog.write(text + "\n\n")
        flog.flush()
        flog.close()
        return version

    def get_cp_version(self, cp_version_file):
        """
        #define CRANE_CUST_VER_INFO
        ["##SYSTEM_VERSION##"]
        ["##DISTRIBUTION_VERSION##"]
        ["##SYSTEM_TARGET_OS##"]
        ["##SYSTEM_PS_MODE##"]
        ["##APPEND_REVERSION##"]
        """
        assert os.path.exists(cp_version_file), "%s not exists" % cp_version_file
        SYSTEM_CUST_SKU = "MINIGUI"
        SYSTEM_SKU_REVERSION = "SDK"
        if self.ps_mode:
            SYSTEM_PS_MODE = self.ps_mode
        else:
            SYSTEM_PS_MODE = "LTEGSM"
        if self.OS_type:
            SYSTEM_TARGET_OS = self.OS_type
        else:
            SYSTEM_TARGET_OS = "TX"
        APPEND_REVERSION = "_".join([SYSTEM_CUST_SKU, SYSTEM_SKU_REVERSION])
        file_obj = open(cp_version_file)
        SYSTEM_VERSION = ''
        DISTRIBUTION_VERSION = ''
        for _line in file_obj:
            _format = '#define[ ]+SYSTEM_VERSION[ ]+"(.*?)"'
            match = re.findall(_format, _line)
            if match:
                SYSTEM_VERSION = match[0]
            _format = '#define[ ]+DISTRIBUTION_VERSION[ ]+"(.*?)"'
            match = re.findall(_format, _line)
            if match:
                DISTRIBUTION_VERSION = match[0]
        CRANE_CUST_VER_INFO = "[%s][%s][%s][%s][%s]" % (SYSTEM_VERSION, \
                                                        DISTRIBUTION_VERSION, SYSTEM_TARGET_OS, SYSTEM_PS_MODE,
                                                        APPEND_REVERSION)
        # self.log.debug(CRANE_CUST_VER_INFO)
        self.cp_version = CRANE_CUST_VER_INFO
        return CRANE_CUST_VER_INFO

    def update_cp_version(self, cp_version_file, cp_version_log_file):
        self.cp_version = self.get_cp_version(cp_version_file)
        with open(cp_version_log_file, "w") as obj:
            obj.write(self.cp_version)
        return self.cp_version

    @staticmethod
    def get_old_cp_version(cp_version_log_file):
        if not os.path.exists(cp_version_log_file):
            return None
        else:
            with open(cp_version_log_file) as obj:
                return obj.read()

    def record_cp_version(self, cp_version_log_file):
        with open(cp_version_log_file, "w") as obj:
            obj.write(self.cp_version)

    def get_dsp_version(self, dsp_bin, dsp_version_log_file):
        """!CRANE_CAT1GSM_L1_1.043.000 , Dec 13 2019 03:30:56"""
        dsp_version_file = os.path.join(self.root_dir, "tmp","dsp_version.bin")
        self.decompress_tool.decompress_bin(dsp_bin, dsp_version_file)
        assert os.path.exists(dsp_version_file), "can not find {}".format(dsp_version_file)
        with open(dsp_version_file, "rb") as fob:
            text = fob.read()
        match = self.dsp_version_pattern.findall(text)
        if match:
            version_info = match[0]
            # self.log.debug(version_info)
            self.dsp_version = version_info
        else:
            version_info = "can not match dsp version".upper()
        with open(dsp_version_log_file, "w") as obj:
            obj.write(version_info)
        return version_info

    def print_info(self):
        print "-"*80
        for k, v in self.__dict__.items():
            print("{: <20}: {}".format(k,v))


class myRepo(object):
    def __init__(self, version_log="", root_path=""):
        self.root_dir = os.getcwd()
        self.release_dist_dir = ''
        self.build_root_dir = ''
        self.git_root_dir = root_path
        self._storage_list = []
        self.CUR_DATE = 0
        self.version_log = version_log
        self.menifest_xml = ''
        self.cp_version = None
        self.dsp_version = None
        self.log = MyLogger(self.__class__.__name__)

        self.verion_name = None

    def git_init(self):
        for storage in self._storage_list:
            _path = os.path.join(self.git_root_dir, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            try:
                # _git.config("--global", "user.name", "binwu")
                # _git.config("--global", "user.email", "binwu@asrmicro.com")
                _git.status()
            except Exception,e:
                self.log.error(e)
                # _git.read_tree("--empty")
                # _git.reset()

    def clone(self, clone_path):
        for storage in self._storage_list:
            _path = os.path.join(self.git_root_dir, storage)
            _repo = git.Repo(_path)
            _path = os.path.join(clone_path, storage)
            _repo.clone(_path)

    def sync(self):
        info_d = {}
        self.git_clean()
        for storage in self._storage_list:
            _path = os.path.join(self.git_root_dir, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            _git.config("--global", "core.autocrlf", "false")
            try:
                info = _git.pull()
                # self.log.info("%-4s %s"%(storage,info.split))
                # if "Already up to date." not in info:
                    # info_list.append(info)
                info_d[storage] = info
            except Exception, e:
                self.log.error(e)
                return {}
        return info_d

    def git_clean(self):
        for storage in self._storage_list:
            _path = os.path.join(self.git_root_dir, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            try:
                _git.clean("-xdf")
                _git.reset("--hard", "HEAD")
            except Exception, e:
                self.log.error(storage)
                self.log.error(e)

    def get_revion_owner(self):
        info_list = []
        for storage in self._storage_list:
            _path = os.path.join(self.git_root_dir, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            info = _git.log("-1", "--date=raw", '--pretty=format:"<%H> <%ae> <%cd> <%s>"')
            info = info.replace('\n', '')
            text_list = re.findall(r'<(.*?)> <(.*?)> <([0-9]+).*?> <(.*?)>', info)[0]
            self.log.debug(storage, text_list)
            info_list.append(text_list)
        # CUR_DATE_bak = self.CUR_DATE
        for index, text_list in enumerate(info_list):
            self.log.debug(text_list)
            commit_id, Author_email, date, commit_info = text_list
            if int(date) >= self.CUR_DATE:
                self.CUR_DATE = int(date)
        # if CUR_DATE_bak == self.CUR_DATE:
        # return None
        for index, text_list in enumerate(info_list):
            commit_id, Author_email, date, commit_info = text_list
            if self.CUR_DATE == int(date):
                return commit_id, Author_email, date, commit_info

    def get_commit_massages(self, delta_time=7):
        now = datetime.datetime.today()
        offset = datetime.timedelta(days=delta_time)
        date = (now - offset).strftime("%Y-%m-%d")
        massage_file = "release_notes.txt"
        massage_file = os.path.join(self.git_root_dir, massage_file)
        info_list = []
        for storage in self._storage_list:
            if storage is 'tool':
                continue
            _path = os.path.join(self.git_root_dir, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            info = _git.log("--after=%s" % date,
                            "--pretty=format:commit ID: %H\nAuthor: %an <%ae>\nDate: %cd\ncommit msg: %s\n-----------------------------------------------")
            info_list.append("*" * 50)
            if not storage:
                storage = 'hal'
            header = "%s commit info" % storage
            info_list.append(header)
            info_list.append("*" * 50)
            info_list.append(info)
        with open(massage_file, 'w') as obj:
            obj.write('\n'.join(info_list))
        return massage_file

    def get_revion_info(self):
        info_list = []
        for storage in self._storage_list:
            _path = os.path.join(self.git_root_dir, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            info = _git.log("-1",
                            "--pretty=format:commit: %H\nAuthor: %cn <%ce>\nDate:  %cd\n------------------------------------------------")
            info_list.append(info)
        return "\n".join(info_list)

    def get_manifest_xml(self, xml_file):
        info_list = []
        for storage in self._storage_list:
            _path = os.path.join(self.git_root_dir, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            info = _git.log("-1", "--pretty=format:%H")
            # self.log.debug(storage,info)
            info_list.append(info)
        manifest_text = manifest_xml.format(info_list)
        self.log.debug(manifest_text)
        _obj = open(xml_file, 'w')
        _obj.write(manifest_text.lstrip())
        _obj.close()

class RepoBase(myRepo, ManagerVersionBase):
    def __init__(self):
        super(RepoBase, self).__init__()
        super(myRepo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.update()
        self.git_init()
        # self.print_info()

    def checkout_branch(self):
        pass

    def get_config(self):
        self.config_d = {}

    def update(self, _branch_name="master"):
        self.get_config()
        # self.branch_name = _branch_name
        self._storage_list = self.config_d["storage_list"]

        self.dsp_version_pattern = re.compile(self.config_d["dsp_version_pattern"])
        self.version_pattern = re.compile(self.config_d["version_pattern"])
        self.manisest_xml_dir = os.path.join(self.root_dir, self.config_d["manisest_xml_dir"])

        self.version_log = os.path.join(self.root_dir, self.config_d["branch_info"][self.branch_name]["version_file"])
        self.release_dist_dir = self.config_d["branch_info"][self.branch_name]["release_dist_dir"]

        self.build_root_dir = self.config_d["branch_info"][self.branch_name]["build"]
        self.git_root_dir = self.config_d["branch_info"][self.branch_name]["git"]



        self.ap_version_log = os.path.join(self.root_dir, self.config_d["version_info_log"]["ap_version_log"])
        self.cp_version_log = os.path.join(self.root_dir, self.config_d["version_info_log"]["cp_version_log"])
        self.dsp_version_log = os.path.join(self.root_dir, self.config_d["version_info_log"]["dsp_version_log"])

        self.sdk_version_file = os.path.join(self.build_root_dir, self.config_d["branch_info"][self.branch_name]["sdk_version_file"])
        self.dsp_version_file = os.path.join(self.build_root_dir, self.config_d["branch_info"][self.branch_name]["dsp_version_file"])

        # self.checkout_branch()
        self._get_verion_name()


class CraneRepo(RepoBase):
    def __init__(self):
        super(CraneRepo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.log.info("create repo done")

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane_info"]
        self.branch_name = "master"

class CraneAliOSRepo(RepoBase):
    def __init__(self):
        super(CraneAliOSRepo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)
        self.OS_type = "ALIOS"
        self.log.info("create repo done")

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane_AliOS_info"]
        self.branch_name = "master"



class craneGRepo(RepoBase):
    def __init__(self):
        super(craneGRepo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)
        self.chip_ID = "craneG"
        self.ps_mode = "LWG"
        self.log.info("create repo done")


    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.config_d = json_str["craneg_info"]
        self.branch_name = "master"


class craneMRepo(RepoBase):
    def __init__(self):
        super(craneMRepo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)
        self.chip_ID = "craneM"
        self.log.info("create repo done")


    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cranem_info"]
        self.branch_name = "master"

class craneMDMRepo(RepoBase):
    def __init__(self):
        super(craneMDMRepo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)
        self.chip_ID = "craneM_DM"
        self.log.info("create repo done")


    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cranem_dm_info"]
        self.branch_name = "master"


class CusRepo(RepoBase):
    def __init__(self):
        super(CusRepo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.git_clean()
        self.checkout_branch()
        self.log.info("create repo done")

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_crane_info"]
        self.branch_name = "master"


class CusMasterRepo(CusRepo):
    def __init__(self):
        super(CusMasterRepo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)


class CusMasterSDK009Repo(CusRepo):
    def __init__(self):
        super(CusMasterSDK009Repo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_crane_info"]
        self.branch_name = "master_sdk009"

class cusR1RCRepo(CusRepo):
    def __init__(self):
        super(cusR1RCRepo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)


    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_crane_info"]
        self.branch_name = "r1_rc"


class cusR2RCRepo(CusRepo):
    def __init__(self):
        super(cusR2RCRepo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_crane_info"]
        self.branch_name = "r2_rc"

class cusR2RCSDK008Repo(CusRepo):
    def __init__(self):
        super(cusR2RCSDK008Repo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_crane_info"]
        self.branch_name = "r2_rc_sdk008"

class cusR2RCSDK009Repo(CusRepo):
    def __init__(self):
        super(cusR2RCSDK009Repo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_crane_info"]
        self.branch_name = "r2_rc_sdk009"


class cusCraneGRepo(CusRepo):
    def __init__(self):
        super(cusCraneGRepo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)
        self.chip_ID = "craneG"
        self.ps_mode = "LWG"

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_craneg_info"]
        self.branch_name = "r2_rc"


class cusR1Repo(CusRepo):
    def __init__(self):
        super(cusR1Repo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)


    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_crane_info"]
        self.branch_name = "r1"

class cusR1PlusJRepo(CusRepo):
    def __init__(self):
        super(cusR1PlusJRepo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)


    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_crane_info"]
        self.branch_name = "r1_plus_j"