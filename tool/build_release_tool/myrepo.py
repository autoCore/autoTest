#!usr/bin/env python

import os
import datetime
import re
import git


manifest_xml = \
"""
<?xml version="1.0" encoding="UTF-8"?>
<manifest>
  <remote fetch=".." name="origin" review="https://source.asrmicro.com/"/>
  
  <default remote="origin" revision="master" sync-j="4"/>
  <project name="crane/crane-dev" path="crane" revision="%s" upstream="master"/>
  <project name="crane/cp" path="crane/cp" revision="%s" upstream="master"/>
  <project name="crane/gui" path="crane/gui" revision="%s" upstream="master"/>
  <project name="crane/tool" path="crane/tool" revision="%s" upstream="master"/>
</manifest>
"""


class myRepo(object):
    def __init__(self, logger, version_log, root_path = '',storage_list = ['','cp','gui','tool']):
        self.root_path = root_path
        self._storage_list = storage_list
        self.CUR_DATE = 0
        self.version_log = version_log
        self.menifest_xml = ''
        self.cp_version = None
        self.dsp_version = None
        self.log = logger
        self.version_pattern = r'(crane_.*?)([0-9][0-9][0-9][0-9])'
        self.verion_name = None

        self.get_verion_name()


    def clone(self,clone_path):
        for storage in self._storage_list:
            _path = os.path.join(self.root_path, storage)
            _repo = git.Repo(_path)
            _path = os.path.join(clone_path, storage)
            _repo.clone(_path)

    def sync(self):
        ret = None
        self.git_clean()
        for storage in self._storage_list:
            _path = os.path.join(self.root_path, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            _git.config("--global","core.autocrlf","false")
            try:
                info = _git.pull()
                if not storage:
                    storage = 'hal'
                self.log.debug("%-4s %s"%(storage,info))
                if "Already up to date." not in info:
                    ret = 1
            except Exception,e:
                self.log.error(e)
                ret = None
        return ret

    def git_clean(self):
        for storage in self._storage_list:
            _path = os.path.join(self.root_path, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            try:
                _git.clean("-xdf")
                _git.reset("--hard","HEAD")
            except Exception,e:
                self.log.error(e)


    def get_revion_owner(self):
        info_list = []
        for storage in self._storage_list:
            _path = os.path.join(self.root_path, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            info = _git.log("-1","--date=raw",'--pretty=format:"<%H> <%ae> <%cd> <%s>"')
            info = info.replace('\n','')
            text_list = re.findall(r'<(.*?)> <(.*?)> <([0-9]+).*?> <(.*?)>',info)[0]
            self.log.debug(storage,text_list)
            info_list.append(text_list)
        # CUR_DATE_bak = self.CUR_DATE
        for index, text_list in enumerate(info_list):
            self.log.debug(text_list)
            commit_id, Author_email,date, commit_info = text_list
            if int(date) >= self.CUR_DATE:
                self.CUR_DATE = int(date)
        # if CUR_DATE_bak == self.CUR_DATE:
            # return None
        for index, text_list in enumerate(info_list):
            commit_id, Author_email, date, commit_info= text_list
            if self.CUR_DATE == int(date):
                return commit_id, Author_email,date, commit_info

    def get_commit_massages(self,delta_time = 7):
        now = datetime.datetime.today()
        offset = datetime.timedelta(days = delta_time)
        date = (now - offset).strftime("%Y-%m-%d")
        massage_file = "release_notes.txt"
        massage_file = os.path.join(self.root_path,massage_file)
        info_list = []
        for storage in self._storage_list:
            if storage is 'tool':
                continue
            _path = os.path.join(self.root_path, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            info = _git.log("--after=%s"%date,"--pretty=format:commit ID: %H\nAuthor: %an <%ae>\nDate:  %cd\ncommit msg: %s\n\
------------------------------------------------------------")
            info_list.append("*"*50)
            if not storage:
                storage = 'hal'
            header = "%s commit info"%storage 
            info_list.append(header)
            info_list.append("*"*50)
            info_list.append(info)
        with open(massage_file,'w') as obj:
            obj.write('\n'.join(info_list))
        return massage_file

    def get_revion_info(self):
        info_list = []
        for storage in self._storage_list:
            _path = os.path.join(self.root_path, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            info = _git.log("-1","--pretty=format:commit: %H\nAuthor: %cn <%ce>\nDate:  %cd\n------------------------------------------------")
            info_list.append(info)
        return "\n".join(info_list)

    def get_manifest_xml(self,xml_file):
        info_list = []
        for storage in self._storage_list:
            _path = os.path.join(self.root_path, storage)
            _repo = git.Repo(_path)
            _git = _repo.git
            info = _git.log("-1","--pretty=format:%H")
            self.log.debug(storage,info)
            info_list.append(info)
        manifest_text = manifest_xml%tuple(info_list)
        self.log.debug(manifest_text)
        _obj = open(xml_file,'w')
        _obj.write(manifest_text.lstrip())
        _obj.close()

    def get_verion_name(self):
        flog = open(self.version_log)
        text = flog.read()
        text = text.replace('\n','')
        text_list = re.findall(self.version_pattern, text)
        self.log.debug(text_list)
        assert text_list,"can not find version info"
        self.verion_name, _ = text_list[-1]

    def get_nearest_version(self):
        flog = open(self.version_log)
        text = flog.read()
        text = text.replace('\n','')
        # text_list = re.findall(r'crane_git_r([0-9]+)',text)
        text_list = re.findall(self.version_pattern, text)
        self.log.debug(text_list)
        assert text_list,"can not find version info"
        self.verion_name, cnt = text_list[-1]
        cnt = int(cnt)
        return "%s%04d"%(self.verion_name,cnt+1)

    def record_version(self,version = '',info = ''):
        flog = open(self.version_log,'a')
        if not version:
            version = self.get_nearest_version()
        if not info:
            info = self.get_revion_info()
        text = "\n".join([version+":",info])
        flog.write(text+"\n\n")
        flog.flush()
        flog.close()
        return version

    def get_cp_version(self,cp_version_file):
        '''#define CRANE_CUST_VER_INFO 
        "["##SYSTEM_VERSION##"]
        ["##DISTRIBUTION_VERSION##"]
        ["##SYSTEM_TARGET_OS##"]
        ["##SYSTEM_PS_MODE##"]
        ["##APPEND_REVERSION##"]"'''
        assert os.path.exists(cp_version_file),"%s not exists"%cp_version_file
        SYSTEM_CUST_SKU = "MINIGUI"
        SYSTEM_SKU_REVERSION = "SDK"
        SYSTEM_PS_MODE = "LTEGSM"
        SYSTEM_TARGET_OS = "TX"
        APPEND_REVERSION = "_".join([SYSTEM_CUST_SKU,SYSTEM_SKU_REVERSION])
        file_obj = open(cp_version_file)
        for _line in file_obj:
            format = '#define[ ]+SYSTEM_VERSION[ ]+"(.*?)"'
            match = re.findall(format,_line)
            if match:
                SYSTEM_VERSION = match[0]
            format = '#define[ ]+DISTRIBUTION_VERSION[ ]+"(.*?)"'
            match = re.findall(format,_line)
            if match:
                DISTRIBUTION_VERSION = match[0]
        CRANE_CUST_VER_INFO = "[%s][%s][%s][%s][%s]"%(SYSTEM_VERSION,\
        DISTRIBUTION_VERSION,SYSTEM_TARGET_OS,SYSTEM_PS_MODE,APPEND_REVERSION)
        self.log.debug(CRANE_CUST_VER_INFO)
        self.cp_version = CRANE_CUST_VER_INFO
        return CRANE_CUST_VER_INFO

    def update_cp_version(self,cp_version_file,cp_version_log_file):
        self.cp_version = self.get_cp_version(cp_version_file)
        with open(cp_version_log_file,"w") as obj:
            obj.write(self.cp_version)
        return self.cp_version

    def get_old_cp_version(self,cp_version_log_file):
        if not os.path.exists(cp_version_log_file):
            return None
        else:
            with open(cp_version_log_file) as obj:
                return obj.read()

    def record_cp_version(self,cp_version_log_file):
        with open(cp_version_log_file,"w") as obj:
            obj.write(self.cp_version)

    def get_dsp_version(self,dsp_bin,dsp_version_log_file):
        "!CRANE_CAT1GSM_L1_1.043.000 , Dec 13 2019 03:30:56"
        fobj = open(dsp_bin,"rb")
        text = fobj.read()
        # match = re.findall("!(CRANE_.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])",text)
        match = re.findall("(CRANE_.{47})",text)
        if match:
            version_info = match[0]
            self.log.debug(version_info)
            self.dsp_version = version_info
        else:
            version_info = "can not match dsp version".upper()
        with open(dsp_version_log_file,"w") as obj:
            obj.write(version_info)

class cusRepo(myRepo):
    def __init__(self, logger, cfg):
        super(cusRepo,self).__init__(logger, cfg.version_cus_log, cfg.cur_crane_cus, ['.'])
        self.release_branch = cfg.release_branch
        _path = os.path.join(self.root_path, '.')
        self.git = git.Repo(_path).git
        if self.release_branch in "r1":
            self.git.checkout("r1")
            self.version_log = cfg.version_r_log
            self.release_dist_dir = cfg.release_r1_dist_dir
        elif self.release_branch in "r1_plus_j":
            self.git.checkout("r1_plus_j")
            self.version_log = cfg.version_r1_plus_j_log
            self.release_dist_dir = cfg.release_r1_plus_j_dist_dir
        else:
            self.git.checkout("master")
            self.version_log = cfg.version_cus_log
            self.release_dist_dir = cfg.release_dist_dir

        self.get_verion_name()


