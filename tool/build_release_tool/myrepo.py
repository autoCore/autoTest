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
        self.version_log = ""
        self.log = MyLogger(self.__class__.__name__)
        self.verion_name = ''
        self.cur_version = ''

        self.decompress_tool = zipTool()

        self.dsp_version_pattern = None
        self.version_pattern = None

        self.cp_version = None
        self.dsp_version = None


    def _get_verion_name(self):
        assert os.path.exists(self.version_log),"%s no exists" % self.version_log
        with open(self.version_log) as flog:
            text = flog.read()
        text = text.replace('\n', '')
        text_list = re.findall(self.version_pattern, text)
        self.log.debug(text_list)
        if text_list:
            # assert text_list,"can not find version info"
            self.verion_name, _ = text_list[-1]
        else:
            self.verion_name = self.release_branch
        self.log.debug(self.verion_name)

    def get_nearest_version(self):
        assert os.path.exists(self.version_log),"%s no exists" % self.version_log
        with open(self.version_log) as flog:
            text = flog.read()
        text = text.replace('\n', '')
        # text_list = re.findall(r'crane_git_r([0-9]+)',text)
        text_list = re.findall(self.version_pattern, text)
        self.log.debug(text_list)
        if text_list:
            # assert text_list,"can not find version info"
            self.verion_name, cnt = text_list[-1]
            cnt = int(cnt)
            version = "%s%04d" % (self.verion_name, cnt + 1)
            self.log.info(version)
        else:
            version = self.release_branch
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
        SYSTEM_PS_MODE = "LTEGSM"
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
        dsp_version_file = "dsp_version.bin"
        self.decompress_tool.decompress_bin(dsp_bin, dsp_version_file)
        assert os.path.exists(dsp_version_file), "can not find {}".format(dsp_version_file)
        with open(dsp_version_file, "rb") as fob:
            text = fob.read()
        match = re.findall(self.dsp_version_pattern, text)
        if match:
            version_info = match[0]
            # self.log.debug(version_info)
            self.dsp_version = version_info
        else:
            version_info = "can not match dsp version".upper()
        with open(dsp_version_log_file, "w") as obj:
            obj.write(version_info)
        return version_info


class myRepo(object):
    def __init__(self, version_log="", root_path="", storage_list=None):
        self.root_dir = os.getcwd()
        self.release_branch = None
        self.release_dist_dir = ''
        self.build_root_dir = ''
        if storage_list is None:
            storage_list = ['', 'cp', 'gui', 'tool']
        self.git_root_dir = root_path
        self._storage_list = storage_list
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
                _git.status()
            except:
                _git.read_tree("--empty")
                _git.reset()

    def clone(self, clone_path):
        for storage in self._storage_list:
            _path = os.path.join(self.git_root_dir, storage)
            _repo = git.Repo(_path)
            _path = os.path.join(clone_path, storage)
            _repo.clone(_path)

    def sync(self):
        ret = None
        self.git_clean()
        for storage in self._storage_list:
            _path = os.path.join(self.git_root_dir, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            _git.config("--global", "core.autocrlf", "false")
            try:
                info = _git.pull()
                if not storage:
                    storage = 'hal'
                # self.log.debug("%-4s %s"%(storage,info))
                if "Already up to date." not in info:
                    ret = 1
            except Exception, e:
                self.log.error(e)
                ret = None
        return ret

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



class CraneRepo(myRepo, ManagerVersionBase):
    def __init__(self):
        super(CraneRepo, self).__init__()
        super(myRepo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.dsp_version_pattern = r"(CRANE_.{47})"
        self.version_pattern = r'(crane_.*?)([0-9][0-9][0-9][0-9])'

        self.update()
        self.log.info("create repo done")
        # self.git_init()

    def update(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        config_d = json_str["crane_info"]

        self.branch_name = config_d["branch_name"]
        self.build_root_dir = config_d["build"]
        self.git_root_dir = config_d["git"]
        self.version_log = os.path.join(self.root_dir, config_d["branch_info"][self.branch_name]["version_file"])
        self.release_dist_dir = config_d["branch_info"][self.branch_name]["release_dist_dir"]

        self.manisest_xml_dir = os.path.join(self.root_dir, config_d["manisest_xml_dir"])

        self.ap_version_log = os.path.join(self.root_dir, config_d["version_info_log"]["ap_version_log"])
        self.cp_version_log = os.path.join(self.root_dir, config_d["version_info_log"]["cp_version_log"])
        self.dsp_version_log = os.path.join(self.root_dir, config_d["version_info_log"]["dsp_version_log"])

        self.sdk_version_file = os.path.join(self.build_root_dir, config_d["branch_info"][self.branch_name]["sdk_version_file"])
        self.dsp_version_file = os.path.join(self.build_root_dir, config_d["branch_info"][self.branch_name]["dsp_version_file"])

        self._get_verion_name()


class craneGRepo(myRepo, ManagerVersionBase):
    def __init__(self):
        super(craneGRepo, self).__init__()
        super(myRepo, self).__init__()
        self.version_pattern = r'(craneg_.*?)([0-9][0-9][0-9][0-9])'
        self.dsp_version_pattern = r"(CRANEG_.{47})"
        self.log = MyLogger(self.__class__.__name__)

        self.update()
        self.log.info("create repo done")
        # self.git_init()


    def update(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        config_d = json_str["craneg_info"]

        self.branch_name = config_d["branch_name"]
        self.build_root_dir = config_d["build"]
        self.git_root_dir = config_d["git"]
        self.version_log = os.path.join(self.root_dir, config_d["branch_info"][self.branch_name]["version_file"])
        self.release_dist_dir = config_d["branch_info"][self.branch_name]["release_dist_dir"]

        self.manisest_xml_dir = os.path.join(self.root_dir, config_d["manisest_xml_dir"])

        self.ap_version_log = os.path.join(self.root_dir, config_d["version_info_log"]["ap_version_log"])
        self.cp_version_log = os.path.join(self.root_dir, config_d["version_info_log"]["cp_version_log"])
        self.dsp_version_log = os.path.join(self.root_dir, config_d["version_info_log"]["dsp_version_log"])

        self.sdk_version_file = os.path.join(self.build_root_dir, config_d["branch_info"][self.branch_name]["sdk_version_file"])
        self.dsp_version_file = os.path.join(self.build_root_dir, config_d["branch_info"][self.branch_name]["dsp_version_file"])

        self._get_verion_name()



class CusRepo(myRepo, ManagerVersionBase):
    def __init__(self):
        super(CusRepo, self).__init__(storage_list=['.'])
        super(myRepo, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.version_pattern = r'(craneg_.*?)([0-9][0-9][0-9][0-9])'
        self.dsp_version_pattern = r"(CRANEG_.{47})"

        self.update()
        self.log.info(self.branch_name)
        self.log.info("create repo done")

        # self.git_init()

    def update(self):
        json_file = os.path.join(self.root_dir,"json","repo.json")
        json_str = load_json(json_file)
        self.branch_name = json_str["cus_branch"]
        self.release_branch = self.branch_name
        self.version_log = os.path.join(self.root_dir,json_str["cus_branch_info"][self.branch_name]["version_file"])
        self.release_dist_dir = json_str["cus_branch_info"][self.branch_name]["release_dist_dir"]

        self.manisest_xml_dir = os.path.join(self.root_dir,json_str["manisest_xml_dir"])

        self.build_root_dir = json_str["cus_dir_info"]["build"]
        self.git_root_dir = json_str["cus_dir_info"]["git"]
        self.ap_version_log = os.path.join(self.root_dir,json_str["cus_dir_info"]["ap_version_log"])
        self.cp_version_log = os.path.join(self.root_dir,json_str["cus_dir_info"]["cp_version_log"])
        self.dsp_version_log = os.path.join(self.root_dir,json_str["cus_dir_info"]["dsp_version_log"])

        self.sdk_version_file = os.path.join(self.build_root_dir, json_str["cus_branch_info"]["master"]["sdk_version_file"])
        self.dsp_version_file = os.path.join(self.build_root_dir, json_str["cus_branch_info"]["master"]["dsp_version_file"])

        _path = os.path.join(self.git_root_dir, '.')
        _git = git.Repo(_path).git

        _git.config("--global","core.autocrlf","false")
        _git.config("--global","user.name","binwu")
        _git.config("--global","user.email","binwu@asrmicro.com")

        _git.checkout(self.branch_name)

        self._get_verion_name()


