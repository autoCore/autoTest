#!usr/bin/env python

import git
import os
import shutil
import time
import re
from send_email import *
from util import *
from util import MyLogger


class GitPushBase(object):
    def __init__(self, _git_push_root_dir):
        self.log = MyLogger(self.__class__.__name__)
        self.git = git.Repo(_git_push_root_dir).git
        self.git.config("--global","core.autocrlf","false")
        self.git.config("--global","user.name","binwu")
        self.git.config("--global","user.email","binwu@asrmicro.com")

    def git_add(self,*file_name_l):
        self.log.info("git add...")
        if file_name_l:
            self.git.add(*file_name_l)
        else:
            self.git.add("--all")
        self.log.info("git add done")

    def git_commit(self,commit_info):
        self.log.info("git commit...")
        self.log.info("conmmit info:",commit_info)
        self.git.commit("-m %s" % commit_info)
        self.log.info("git commit done")

    def git_push(self):
        self.log.info("git push...")
        self.git.push(*self.push_cmd)
        self.log.info("git push done")

    def git_clean(self):
        try:
            self.git.clean("-xdf")
            self.git.reset("--hard","HEAD^")
            self.git.pull()
        except Exception,e:
            self.log.error(e)
            raise Exception("git_clean error")

class gitPushCpDailyBuild(GitPushBase):
    def __init__(self,cfg):
        self.root_dir = os.getcwd()
        self.log = MyLogger(self.__class__.__name__)

        self.update()

        super(gitPushCpDailyBuild,self).__init__(self.git_push_cp_dir)
        self.cp_sdk_version = None
        self.cp_sdk = None

        self.cp_sdk_root_dir = None
        self.dsp_rf_root_dir = ''

        self.git_push_dsp_dir = ''
        self.zip_tool = zipTool()


    def update(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        config_d = json_str["crane_sdk"]
        self.cp_sdk_release_dir = config_d["release_dir"]
        self.git_push_cp_dir = config_d["git_push_root_dir"]
        self.target_dist_dir = config_d["target_dir"]
        self.cp_sdk_dir = os.path.join(self.root_dir, config_d["local_dir"])
        self.cp_version_file = config_d["verson_file"]

        self.push_cmd = config_d["git_push_cmd"]

    def find_new_cp_sdk(self):
        "ASR3601_MINIGUI_20191206_SDK.zip"
        cp_sdk_list = [_file for _file in os.listdir(self.cp_sdk_release_dir) if
                       (_file.endswith(".zip") or _file.endswith(".7z")) and _file.startswith("ASR3601_MINIGUI_")]
        cp_sdk_list.sort(key=lambda fn: os.path.getmtime(os.path.join(self.cp_sdk_release_dir,fn)))
        assert cp_sdk_list,"can not find sdk"
        self.cp_sdk = cp_sdk_list[-1]
        self.log.debug("newest adk: %s" % self.cp_sdk)

    def clean_git_push_cp(self):
        self.git_clean()
        for _file in os.listdir(self.target_dist_dir):
            if _file in [".git","X.bat"]:
                continue
            _file = os.path.join(self.target_dist_dir,_file)
            if os.path.isfile(_file):
                os.remove(_file)
            else:
                shutil.rmtree(_file)
        self.log.info("clean cp done")

    def copy_sdk(self):
        self.log.info("copy %s..." % self.cp_sdk)
        shutil.copy2(os.path.join(self.cp_sdk_release_dir,self.cp_sdk),self.cp_sdk_dir)
        time.sleep(3)
        self.log.info("copy done.")

    def copy_sdk_to_git_push_cp(self,cp_sdk):
        try:
            root_dir = os.path.join(self.cp_sdk_dir,cp_sdk)
            for _file in os.listdir(root_dir):
                fname = os.path.join(root_dir,_file)
                if os.path.isfile(fname):
                    shutil.copy2(fname,os.path.join(self.target_dist_dir,_file))
                elif os.path.isdir(fname):
                    shutil.copytree(fname,os.path.join(self.target_dist_dir,_file))
                else:
                    self.log.warning("%s" % fname)

            self.log.info("%s" % self.dsp_rf_root_dir)
            if os.path.exists(self.dsp_rf_root_dir):
                dir_path = os.path.dirname(self.dsp_rf_root_dir)
                self.log.info("%s" % dir_path)
                dist_dir = os.path.join(self.target_dist_dir,os.path.basename(dir_path))
                self.log.info("%s" % dist_dir)
                if os.path.exists(dist_dir):
                    shutil.rmtree(dist_dir)
                shutil.copytree(dir_path,dist_dir)
                for _file in ["dsp.bin","rf.bin"]:
                    fname = os.path.join(self.dsp_rf_root_dir,_file)
                    dist_file = os.path.join(self.git_push_dsp_dir,_file)
                    if os.path.exists(self.git_push_dsp_dir):
                        if os.path.isfile(fname):
                            shutil.copy2(fname,dist_file)
                        else:
                            self.log.warning("%s" % fname)
            self.log.info("copy_sdk_to_git_push_cp done.")
        except Exception,e:
            self.log.error(e)
            self.log.error("copy_sdk_to_git_push_cp error")
            raise Exception,"copy_sdk_to_git_push_cp error"

    def unzip_sdk(self):
        fname,_ = os.path.splitext(self.cp_sdk)
        root_dir = os.path.join(self.cp_sdk_dir,fname)
        self.zip_tool.unpack_archive(os.path.join(self.cp_sdk_dir,self.cp_sdk),root_dir)
        assert os.path.exists(root_dir),"can not find %s" % root_dir
        for root,dirs,files in os.walk(root_dir,topdown=False):
            if "3g_ps" in dirs:
                self.cp_sdk_root_dir = root
                break
        assert os.path.exists(self.cp_sdk_root_dir),"can not find %s" % self.cp_sdk_root_dir

        for root,dirs,files in os.walk(root_dir,topdown=False):
            if "DSP" in dirs:
                self.dsp_rf_root_dir = os.path.join(root,"DSP")
                self.git_push_dsp_dir = os.path.dirname(self.target_dist_dir)
                self.git_push_dsp_dir = os.path.join(self.git_push_dsp_dir,"cus","evb","images")
                break

    def delete_gui_lib(self,path_dir):
        if not os.path.exists(path_dir):
            assert ("%r not exists" % path_dir)
        for _file in os.listdir(path_dir):
            self.log.info(os.path.join(path_dir,_file))
            if _file in ["libmgapollo.a","libmgngux.a","libmgminigui.a","libtarget.a","libthirdparty.a","libmgmgeff.a",
                         "libhal.a","hal_init.o"]:
                os.remove(os.path.join(path_dir,_file))
        self.log.info("delete_gui_lib done.")

    def get_sdk_version(self,cp_version_file):
        assert os.path.exists(cp_version_file),"%s not exists" % cp_version_file
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
        CRANE_CUST_VER_INFO = "[%s][%s][%s][%s][%s]" % (SYSTEM_VERSION, \
                                                        DISTRIBUTION_VERSION,SYSTEM_TARGET_OS,SYSTEM_PS_MODE,
                                                        APPEND_REVERSION)
        self.log.debug(CRANE_CUST_VER_INFO)
        return CRANE_CUST_VER_INFO

    def git_push_start(self):
        self.find_new_cp_sdk()
        if os.path.exists(os.path.join(self.cp_sdk_dir,self.cp_sdk)):
            release_sdk_time = os.path.getmtime(os.path.join(self.cp_sdk_release_dir,self.cp_sdk))
            local_sdk_time = os.path.getmtime(os.path.join(self.cp_sdk_dir,self.cp_sdk))
            # self.log.info("release_sdk_time: %r"%(release_sdk_time))
            # self.log.info("local_sdk_time: %r"%(local_sdk_time))
            if long(release_sdk_time) <= long(local_sdk_time):
                self.log.debug("%s already exists" % self.cp_sdk)
                return None
            else:
                self.log.info("release_sdk_time: %s" % time.asctime(time.localtime(release_sdk_time)))
                self.log.info("local_sdk_time: %s" % time.asctime(time.localtime(local_sdk_time)))
                os.remove(os.path.join(self.cp_sdk_dir,self.cp_sdk))
        self.log.info("wait for sdk copy...")
        time.sleep(60)
        self.copy_sdk()
        self.unzip_sdk()
        cp_sdk = self.cp_sdk_root_dir
        self.log.info(cp_sdk)


        sdk_verion_file = [os.path.join(cp_sdk,"tavor","env","inc","sys_version.h"),self.cp_version_file]
        for version_file in sdk_verion_file:
            if not os.path.exists(version_file):
                self.log.error("can not file: %s" % version_file)
                return None

        local_sdk_version = self.get_sdk_version(sdk_verion_file[1])
        release_sdk_version = self.get_sdk_version(sdk_verion_file[0])
        self.log.info("local_sdk_version:",local_sdk_version)
        self.log.info("release_sdk_version:",release_sdk_version)
        self.cp_sdk_version = release_sdk_version
        if release_sdk_version == local_sdk_version:
            self.log.info("%s already sync" % self.cp_sdk)
            return None

        self.log.info("=" * 50)
        self.log.info("git push cp...")
        self.clean_git_push_cp()
        gui_lib = os.path.join(cp_sdk,"tavor","Arbel","lib")
        self.delete_gui_lib(gui_lib)
        self.copy_sdk_to_git_push_cp(cp_sdk)
        try:
            self.git_add()
            commit_info = "%s" % self.cp_sdk
            self.git_commit(commit_info)
            self.git_push()
            return True
        except Exception,e:
            self.log.error(e)
            self.log.error("git push error")
            return None




class gitPushCraneGSDK(GitPushBase):
    def __init__(self):
        self.root_dir = os.getcwd()
        self.log = MyLogger(self.__class__.__name__)

        self.update()

        super(gitPushCraneGSDK,self).__init__(self.git_push_cp_dir)
        self.cp_sdk_version = None
        self.cp_sdk = None

        self.cp_sdk_root_dir = None
        self.dsp_rf_root_dir = ''

        self.git_push_dsp_dir = ''
        self.zip_tool = zipTool()


    def update(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        config_d = json_str["craneg_sdk"]
        self.cp_sdk_release_dir = config_d["release_dir"]
        self.git_push_cp_dir = config_d["git_push_root_dir"]
        self.target_dist_dir = config_d["target_dir"]
        self.cp_sdk_dir = os.path.join(self.root_dir, config_d["local_dir"])
        self.cp_version_file = config_d["verson_file"]

        self.push_cmd = config_d["git_push_cmd"]


    def find_new_cp_sdk(self):
        "ASR3603_MINIGUI_20200603_SDK.zip"
        cp_sdk_list = [_file for _file in os.listdir(self.cp_sdk_release_dir) if
                       (_file.endswith(".zip") or _file.endswith(".7z")) and _file.startswith("ASR3603_MINIGUI_")]
        cp_sdk_list.sort(key=lambda fn: os.path.getmtime(os.path.join(self.cp_sdk_release_dir,fn)))
        assert cp_sdk_list,"can not find sdk"
        self.cp_sdk = cp_sdk_list[-1]
        self.log.debug("newest adk: %s" % self.cp_sdk)

    def clean_git_push_cp(self):
        self.git_clean()
        for _file in os.listdir(self.target_dist_dir):
            if _file in [".git","X.bat"]:
                continue
            _file = os.path.join(self.target_dist_dir,_file)
            if os.path.isfile(_file):
                os.remove(_file)
            else:
                shutil.rmtree(_file)
        self.log.info("clean cp done")

    def copy_sdk(self):
        self.log.info("copy %s..." % self.cp_sdk)
        shutil.copy2(os.path.join(self.cp_sdk_release_dir,self.cp_sdk),self.cp_sdk_dir)
        time.sleep(3)
        self.log.info("copy done.")

    def copy_sdk_to_git_push_cp(self,cp_sdk):
        try:
            root_dir = os.path.join(self.cp_sdk_dir,cp_sdk)
            for _file in os.listdir(root_dir):
                fname = os.path.join(root_dir,_file)
                if os.path.isfile(fname):
                    shutil.copy2(fname,os.path.join(self.target_dist_dir,_file))
                elif os.path.isdir(fname):
                    shutil.copytree(fname,os.path.join(self.target_dist_dir,_file))
                else:
                    self.log.warning("%s" % fname)

            self.log.info("%s" % self.dsp_rf_root_dir)
            if os.path.exists(self.dsp_rf_root_dir):
                dir_path = os.path.dirname(self.dsp_rf_root_dir)
                self.log.info("%s" % dir_path)
                dist_dir = os.path.join(self.target_dist_dir,os.path.basename(dir_path))
                self.log.info("%s" % dist_dir)
                if os.path.exists(dist_dir):
                    shutil.rmtree(dist_dir)
                shutil.copytree(dir_path,dist_dir)
                for _file in ["dsp.bin","rf.bin"]:
                    fname = os.path.join(self.dsp_rf_root_dir,_file)
                    dist_file = os.path.join(self.git_push_dsp_dir,_file)
                    if os.path.exists(self.git_push_dsp_dir):
                        if os.path.isfile(fname):
                            shutil.copy2(fname,dist_file)
                        else:
                            self.log.warning("%s" % fname)
            self.log.info("copy_sdk_to_git_push_cp done.")
        except Exception,e:
            self.log.error(e)
            self.log.error("copy_sdk_to_git_push_cp error")
            raise Exception,"copy_sdk_to_git_push_cp error"

    def unzip_sdk(self):
        fname,_ = os.path.splitext(self.cp_sdk)
        root_dir = os.path.join(self.cp_sdk_dir,fname)
        self.zip_tool.unpack_archive(os.path.join(self.cp_sdk_dir,self.cp_sdk),root_dir)
        assert os.path.exists(root_dir),"can not find %s" % root_dir
        for root,dirs,files in os.walk(root_dir,topdown=False):
            if "3g_ps" in dirs:
                self.cp_sdk_root_dir = root
                break
        assert os.path.exists(self.cp_sdk_root_dir),"can not find %s" % self.cp_sdk_root_dir

        for root,dirs,files in os.walk(root_dir,topdown=False):
            if "DSP" in dirs:
                self.dsp_rf_root_dir = os.path.join(root,"DSP")
                self.git_push_dsp_dir = os.path.dirname(self.target_dist_dir)
                self.git_push_dsp_dir = os.path.join(self.git_push_dsp_dir,"cus","evb","images")
                break

    def delete_gui_lib(self,path_dir):
        if not os.path.exists(path_dir):
            assert ("%r not exists" % path_dir)
        for _file in os.listdir(path_dir):
            self.log.info(os.path.join(path_dir,_file))
            if _file in ["libmgapollo.a","libmgngux.a","libmgminigui.a","libtarget.a","libthirdparty.a","libmgmgeff.a",
                         "libhal.a","hal_init.o"]:
                os.remove(os.path.join(path_dir,_file))
        self.log.info("delete_gui_lib done.")

    def get_sdk_version(self,cp_version_file):
        assert os.path.exists(cp_version_file),"%s not exists" % cp_version_file
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
        CRANE_CUST_VER_INFO = "[%s][%s][%s][%s][%s]" % (SYSTEM_VERSION, \
                                                        DISTRIBUTION_VERSION,SYSTEM_TARGET_OS,SYSTEM_PS_MODE,
                                                        APPEND_REVERSION)
        self.log.debug(CRANE_CUST_VER_INFO)
        return CRANE_CUST_VER_INFO

    def git_push_start(self):
        self.find_new_cp_sdk()
        if os.path.exists(os.path.join(self.cp_sdk_dir,self.cp_sdk)):
            release_sdk_time = os.path.getmtime(os.path.join(self.cp_sdk_release_dir,self.cp_sdk))
            local_sdk_time = os.path.getmtime(os.path.join(self.cp_sdk_dir,self.cp_sdk))
            # self.log.info("release_sdk_time: %r"%(release_sdk_time))
            # self.log.info("local_sdk_time: %r"%(local_sdk_time))
            if long(release_sdk_time) <= long(local_sdk_time):
                self.log.debug("%s already exists" % self.cp_sdk)
                return None
            else:
                self.log.info("release_sdk_time: %s" % time.asctime(time.localtime(release_sdk_time)))
                self.log.info("local_sdk_time: %s" % time.asctime(time.localtime(local_sdk_time)))
                os.remove(os.path.join(self.cp_sdk_dir,self.cp_sdk))
        self.log.info("wait for sdk copy...")
        time.sleep(60)
        self.copy_sdk()
        self.unzip_sdk()
        cp_sdk = self.cp_sdk_root_dir
        self.log.info(cp_sdk)


        sdk_verion_file = [os.path.join(cp_sdk,"tavor","env","inc","sys_version.h"),self.cp_version_file]
        for version_file in sdk_verion_file:
            if not os.path.exists(version_file):
                self.log.error("can not file: %s" % version_file)
                return None

        local_sdk_version = self.get_sdk_version(sdk_verion_file[1])
        release_sdk_version = self.get_sdk_version(sdk_verion_file[0])
        self.log.info("local_sdk_version:",local_sdk_version)
        self.log.info("release_sdk_version:",release_sdk_version)
        self.cp_sdk_version = release_sdk_version
        if release_sdk_version == local_sdk_version:
            self.log.info("%s already sync" % self.cp_sdk)
            return None

        self.log.info("=" * 50)
        self.log.info("git push cp...")
        self.clean_git_push_cp()
        gui_lib = os.path.join(cp_sdk,"tavor","Arbel","lib")
        self.delete_gui_lib(gui_lib)
        self.copy_sdk_to_git_push_cp(cp_sdk)
        try:
            self.git_add()
            commit_info = "%s" % self.cp_sdk
            self.git_commit(commit_info)
            self.git_push()
            return True
        except Exception,e:
            self.log.error(e)
            self.log.error("git push error")
            return None



class gitPushCusSDK(gitPushCpDailyBuild):
    def __init__(self,cfg):
        super(gitPushCusSDK,self).__init__(cfg)
        self.cp_sdk_version = None
        self.cp_sdk = None

        self.log = MyLogger(self.__class__.__name__)
        self.git_push_cp_dir = cfg.git_push_cus_dir
        self.cp_sdk_dir = cfg.cp_sdk_dir

        self.cp_version_file = os.path.join(cfg.cur_crane_cus,"evb","src",cfg.cp_version_file)

        _repo = git.Repo(cfg.git_push_cus_root_dir)
        self.git = _repo.git
        self.git.config("--global","core.autocrlf","false")
        self.git.config("--global","user.name","binwu")
        self.git.config("--global","user.email","binwu@asrmicro.com")
        self.cfg = cfg

        self.init()

    def init(self):
        if self.cfg.release_branch == "master":
            self.git.checkout("master")
            self.cp_sdk_release_dir = self.cfg.cus_cp_sdk_release_dir
            self.push_cmd = ("ssh://binwu@customsupport.asrmicro.com:29418/fp/crane-phone-rls","master")
        else:
            self.git.checkout(str(self.cfg.release_branch))
            self.push_cmd = ("origin",str(self.cfg.release_branch))
            self.cp_sdk_release_dir = self.cfg.cus_r1_cp_sdk_release_dir


class gitPushCraneDsp(GitPushBase):
    def __init__(self):
        self.root_dir = os.getcwd()
        self.log = MyLogger(self.__class__.__name__)
        self.update()

        super(gitPushCraneDsp, self).__init__(self.git_push_root_dir)

        self.decompress_tool = zipTool()

        self.dsp_version_pattern = "(CRANE_.*? ,.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])"

        self.release_dsp_bin = ''
        self.release_rf_bin = ''
        self.release_rf_verson_file = ''
        self.dsp_version = ''

    def update(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        config_d = json_str["crane_dsp"]
        self.release_dir = config_d["release_dir"]
        self.git_push_root_dir = config_d["git_push_root_dir"]
        self.local_dsp_bin = config_d["verson_file"]
        self.local_rf_bin = os.path.join(os.path.dirname(self.local_dsp_bin), "rf.bin")
        self.local_rf_verson_file = os.path.join(os.path.dirname(self.local_dsp_bin), "RF_Version.txt")
        self.push_cmd = config_d["git_push_cmd"]


    def get_dsp_version(self, dsp_bin = None):
        """CRANE_CAT1GSM_L1_1.043.000 , Dec 13 2019 03:30:56"""
        if not dsp_bin:
            dsp_bin = self.local_dsp_bin
        dsp_version_file = os.path.join(self.root_dir, "tmp", "dsp_version_tmp.bin")
        self.decompress_tool.decompress_bin(dsp_bin, dsp_version_file)
        assert os.path.exists(dsp_version_file), "can not find {}".format(dsp_version_file)
        with open(dsp_version_file, "rb") as fob:
            text = fob.read()
        # match = re.findall("!(CRANE_.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])",text)
        match = re.findall("(CRANE_.{47})",text)
        if match:
            self.log.debug(match[0])
            version_info = match[0]
        else:
            self.log.error("can not find dsp version infomation")
            version_info = None
        # os.remove(dsp_version_file)
        return version_info


    def get_release_dsp_rf(self):
        dsp_release_bin_l = []
        release_dir_list = [os.path.join(self.release_dir,_dir) for _dir in os.listdir(self.release_dir) \
                            if os.path.isdir(os.path.join(self.release_dir,_dir))]
        release_dir_list.sort(key=lambda fn: os.path.getmtime(fn))
        self.log.debug("release_dir_list len:",len(release_dir_list))
        self.log.debug(release_dir_list[-10:])
        for release_dir in release_dir_list[-10:]:
            self.log.debug(release_dir)
            for root,dirs,files in os.walk(release_dir,topdown=False):
                tgt_file = "crane_compress_a0.bin"
                if "crane_compress_a0.bin" in files:
                    rf = os.path.join(root,"PM813","rf.bin")
                    if os.path.exists(rf):
                        dsp_release_bin_l.append(os.path.join(root,tgt_file))
        dsp_release_bin_l.sort(key=lambda fn: os.path.getmtime(fn))
        self.log.debug("\n".join(dsp_release_bin_l))
        self.release_dsp_bin = dsp_release_bin_l[-1]
        root_dir = os.path.dirname(self.release_dsp_bin)
        self.release_rf_bin = os.path.join(root_dir,"PM813","rf.bin")
        self.release_rf_verson_file = os.path.join(root_dir,"PM813","RF_Version.txt")

    def condition(self):
        self.git_clean()
        local_dsp_version = self.get_dsp_version()
        self.get_release_dsp_rf()
        release_dsp_version = self.get_dsp_version(self.release_dsp_bin)
        # self.log.info("local_dsp_version  :", local_dsp_version)
        # self.log.info("release_dsp_version:", release_dsp_version)
        # self.log.info("release_dsp_bin  :", self.release_dsp_bin)
        # self.log.info("release_rf_bin:", self.release_rf_bin)
        if local_dsp_version == release_dsp_version:
            return False
        else:
            self.log.info("local_dsp_version  :", local_dsp_version)
            self.log.info("release_dsp_version:", release_dsp_version)
            self.dsp_version = release_dsp_version
            return True

    def git_push_start(self):
        if not self.condition():
            time.sleep(10)
            return

        self.log.info("wait for dsp copy...")
        time.sleep(30)

        local_bin_l = [self.local_dsp_bin, self.local_rf_bin, self.local_rf_verson_file]
        release_bin_l = [self.release_dsp_bin, self.release_rf_bin, self.release_rf_verson_file]
        for release_bin,local_bin in zip(release_bin_l,local_bin_l):
            if os.path.exists(release_bin):
                if os.path.exists(local_bin):
                    os.remove(local_bin)
                shutil.copy2(release_bin,local_bin)

        self.log.info("=" * 50)
        self.log.info("git push dsp...")
        try:
            self.git_add(self.local_dsp_bin, self.local_rf_bin, self.local_rf_verson_file)
            match = re.findall(self.dsp_version_pattern, self.dsp_version)
            if match and "\00" not in match[0]:
                dsp_version = match[0]
            else:
                dsp_version = str(time.asctime())
            commit_info = "update dsp dailybuild %s" % dsp_version
            self.git_commit(commit_info)
            self.git_push()
            return True
        except Exception,e:
            self.log.error(e)
            self.log.error("git push error")
            return None


class gitPushCraneGDsp(gitPushCraneDsp):
    def __init__(self):
        self.root_dir = os.getcwd()
        self.log = MyLogger(self.__class__.__name__)
        self.update()
        super(gitPushCraneGDsp, self).__init__()
        self.dsp_version_pattern = "(CRANEG_.*? ,.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])"

    def update(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        config_d = json_str["craneg_dsp"]
        self.release_dir = config_d["release_dir"]
        self.git_push_root_dir = config_d["git_push_root_dir"]
        self.local_dsp_bin = config_d["verson_file"]
        self.local_rf_bin = os.path.join(os.path.dirname(self.local_dsp_bin), "rf.bin")
        self.local_rf_verson_file = os.path.join(os.path.dirname(self.local_dsp_bin), "RF_Version.txt")
        self.push_cmd = config_d["git_push_cmd"]


    def get_dsp_version(self, dsp_bin = None):
        """ CRANEG_L1_1.004.002 , Jun 03 2020 03:10:40"""
        if not dsp_bin:
            dsp_bin = self.local_dsp_bin
        dsp_version_file = os.path.join(self.root_dir, "tmp", "craneg_dsp_version.bin")
        self.decompress_tool.decompress_bin(dsp_bin, dsp_version_file)
        assert os.path.exists(dsp_version_file), "can not find {}".format(dsp_version_file)
        with open(dsp_version_file, "rb") as fob:
            text = fob.read()
        # match = re.findall("!(CRANE_.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])",text)
        match = re.findall("(CRANEG_.{47})",text)
        if match:
            self.log.debug(match[0])
            version_info = match[0]
        else:
            self.log.error("can not find dsp version infomation")
            version_info = None
        # os.remove(dsp_version_file)
        return version_info


    def get_release_dsp_rf(self):
        dsp_release_bin_l = []
        release_dir_list = [os.path.join(self.release_dir,_dir) for _dir in os.listdir(self.release_dir) \
                            if os.path.isdir(os.path.join(self.release_dir,_dir))]
        release_dir_list.sort(key=lambda fn: os.path.getmtime(fn))
        self.log.debug("release_dir_list len:",len(release_dir_list))
        self.log.debug(release_dir_list[-10:])
        for release_dir in release_dir_list[-10:]:
            self.log.debug(release_dir)
            for root,dirs,files in os.walk(release_dir,topdown=False):
                tgt_file = "craneg_dsp.bin"
                if "craneg_dsp.bin" in files:
                    rf = os.path.join(root,"PM813","rf.bin")
                    if os.path.exists(rf):
                        dsp_release_bin_l.append(os.path.join(root,tgt_file))
        dsp_release_bin_l.sort(key=lambda fn: os.path.getmtime(fn))
        self.log.debug("\n".join(dsp_release_bin_l))
        self.release_dsp_bin = dsp_release_bin_l[-1]
        root_dir = os.path.dirname(self.release_dsp_bin)
        self.release_rf_bin = os.path.join(root_dir,"PM813","rf.bin")
        self.release_rf_verson_file = os.path.join(root_dir,"PM813","RF_Version.txt")



