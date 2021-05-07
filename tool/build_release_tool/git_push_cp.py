#!usr/bin/env python

import git
import os
import shutil
import time
import re
from send_email import *
from util import *
from util import MyLogger
from util import ziptool_mutex


class GitPushBase(object):
    def __init__(self):
        self.root_dir = os.getcwd()
        self.log = MyLogger(self.__class__.__name__)
        self.git_push_root_dir = None
        self.branch_name = "master"

    def create_git(self):
        self.git = git.Repo(self.git_push_root_dir).git
        # self.git.config("--global","core.autocrlf","false")
        # self.git.config("--global","user.name","binwu")
        # self.git.config("--global","user.email","binwu@asrmicro.com")

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
            self.git.reset("--hard","origin/%s"%self.branch_name)
            self.git.pull()
        except Exception,e:
            self.log.error(e)
            self.git.reset("--hard","origin/%s"%self.branch_name)
            raise Exception("git_clean error")

    def print_info(self):
        print "-"*80
        for k, v in self.__dict__.items():
            print("{: <20}: {}".format(k,v))

    def close_push(self):
        pass


class gitPushSDKBase(GitPushBase):
    def __init__(self):
        super(gitPushSDKBase, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.zip_tool = zipTool()

        self.cp_sdk_version = None
        self.cp_sdk = None
        self.cp_sdk_root_dir = None
        self.dsp_rf_root_dir = ''
        self.git_push_dsp_dir = ''

        self.git_push_dsp_rf_list = []

        self.dsp_bin = None
        self.rf_bin = None

        self.update()
        self.create_git()

        # self.print_info()

    def get_config(self):
        self.config_d = {}

    def update(self):
        self.get_config()
        self.cp_sdk_release_dir = os.path.normpath(self.config_d["release_dir"])
        self.git_push_cp_dir = os.path.normpath(self.config_d["git_push_root_dir"])
        self.git_push_root_dir = self.git_push_cp_dir
        self.target_dist_dir = os.path.normpath(self.config_d["target_dir"])
        self.cp_sdk_dir = os.path.normpath(os.path.join(self.root_dir, self.config_d["local_dir"]))
        self.cp_version_file = self.config_d["verson_file"]
        self.release_target = self.config_d["release_target"]

        self.push_cmd = self.config_d["git_push_cmd"]

    def get_dsp_rf_dir(self, root_dir):
        for root,dirs,files in os.walk(root_dir,topdown=False):
            if "DSP" in dirs:
                self.dsp_rf_root_dir = os.path.join(root,"DSP")
                self.dsp_bin = os.path.join(self.dsp_rf_root_dir,"dsp.bin")
                self.rf_bin = os.path.join(self.dsp_rf_root_dir,"rf.bin")
                self.git_push_dsp_dir = os.path.dirname(self.target_dist_dir)
                self.git_push_dsp_dir = os.path.join(self.git_push_dsp_dir,"cus","evb","images")
                self.git_push_dsp_rf_list.append((self.dsp_bin, self.git_push_dsp_dir))
                self.git_push_dsp_rf_list.append((self.rf_bin, self.git_push_dsp_dir))
                break

    def find_new_cp_sdk(self):
        "ASR3603_MINIGUI_20200603_SDK.zip"
        cp_sdk_list = [_file for _file in os.listdir(self.cp_sdk_release_dir) if
                       (_file.endswith(".zip") or _file.endswith(".7z")) and _file.startswith(self.release_target)]
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
                while self.git_push_dsp_rf_list:
                    src_file, dist = self.git_push_dsp_rf_list.pop()
                    self.log.info(src_file)
                    self.log.info(dist)
                    if os.path.exists(dist):
                        if os.path.isfile(src_file):
                            shutil.copy2(src_file, dist)
                        else:
                            self.log.warning("%s" % src_file)

            self.log.info("copy_sdk_to_git_push_cp done.")
        except Exception,e:
            self.log.error(e)
            self.log.error("copy_sdk_to_git_push_cp error")
            raise Exception,"copy_sdk_to_git_push_cp error"

    def unzip_sdk(self):
        fname,_ = os.path.splitext(self.cp_sdk)
        root_dir = os.path.join(self.cp_sdk_dir,fname)
        while True:
            try:
                with ziptool_mutex:
                    self.zip_tool.unpack_archive(os.path.join(self.cp_sdk_dir,self.cp_sdk),root_dir)
                assert os.path.exists(root_dir),"can not find %s" % root_dir
                for root,dirs,files in os.walk(root_dir,topdown=False):
                    if "3g_ps" in dirs:
                        self.cp_sdk_root_dir = root
                        break
                assert os.path.exists(self.cp_sdk_root_dir),"can not find %s" % self.cp_sdk_root_dir
                self.get_dsp_rf_dir(root_dir)
                return
            except Exception,e:
                time.sleep(10)
                self.log.error(e)


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

    def condition(self):
        self.update()
        self.find_new_cp_sdk()
        self.git_clean()
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
        try:
            self.unzip_sdk()
        except Exception,e:
            self.log.error(e)
            os.remove(os.path.join(self.cp_sdk_dir,self.cp_sdk))
            return None
        self.log.info(self.cp_sdk_root_dir)


        sdk_verion_file = [os.path.join(self.cp_sdk_root_dir,"tavor","env","inc","sys_version.h"),self.cp_version_file]
        for version_file in sdk_verion_file:
            if not os.path.exists(version_file):
                self.log.error("can not file: %s" % version_file)
                return None
        return True

    def close_push(self):
        to_address = ",".join(["binwu@asrmicro.com"])
        subject = "%s auto push" % self.cp_sdk_version
        msg = r"Hi %s, %s auto push done!" % (to_address.split("@")[0], self.cp_sdk_version)
        send_email_tool(to_address, subject.upper(), msg)


    def git_push_start(self):
        if not self.condition():
            time.sleep(10)
            return

        local_sdk_version = self.get_sdk_version(self.cp_version_file)
        release_sdk_version = self.get_sdk_version(os.path.join(self.cp_sdk_root_dir,"tavor","env","inc","sys_version.h"))
        self.log.info("local_sdk_version:",local_sdk_version)
        self.log.info("release_sdk_version:",release_sdk_version)
        self.cp_sdk_version = release_sdk_version
        if release_sdk_version == local_sdk_version:
            self.log.info("%s already sync" % self.cp_sdk)
            return None

        self.log.info("=" * 50)
        self.log.info("git push sdk...")
        try:
            self.clean_git_push_cp()
            gui_lib = os.path.join(self.cp_sdk_root_dir,"tavor","Arbel","lib")
            self.delete_gui_lib(gui_lib)
            self.copy_sdk_to_git_push_cp(self.cp_sdk_root_dir)
            self.git_add()
            commit_version_info = re.findall("\[(.*?\..*?\..*?)\]",release_sdk_version)
            if commit_version_info:
                commit_version_info = commit_version_info[0]
            else:
                commit_version_info = " "
            commit_info = "%s version info: %s" % (self.cp_sdk, commit_version_info)
            self.git_commit(commit_info)
            self.git_push()
            self.close_push()
            return True
        except Exception,e:
            self.log.error(e)
            self.log.error("git push error")
            self.git_clean()
            os.remove(os.path.join(self.cp_sdk_dir,self.cp_sdk))
            return None


class gitPushCraneSDK(gitPushSDKBase):
    def __init__(self):
        super(gitPushCraneSDK, self).__init__()
        self.log = MyLogger(self.__class__.__name__)


    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane_sdk"]



class gitPushCraneGSDK(gitPushSDKBase):
    def __init__(self):
        super(gitPushCraneGSDK, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["craneg_sdk"]


class gitPushCusSDK(gitPushSDKBase):
    def __init__(self):
        super(gitPushCusSDK, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.branch_name = "master"
        # self.git.checkout("master")

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_master_sdk"]

    def get_dsp_rf_dir(self, root_dir):
        for root,dirs,files in os.walk(root_dir,topdown=False):
            if "DSP" in dirs:
                self.dsp_rf_root_dir = os.path.join(root,"DSP")
                self.dsp_bin = os.path.join(self.dsp_rf_root_dir,"CRANE","dsp.bin")
                self.rf_bin = os.path.join(self.dsp_rf_root_dir,"CRANE","PM813","rf.bin")
                self.git_push_dsp_dir = os.path.dirname(self.target_dist_dir)
                self.git_push_dsp_dir = os.path.join(self.git_push_dsp_dir,"cus","evb","images")
                self.git_push_dsp_rf_list.append((self.dsp_bin, self.git_push_dsp_dir))
                self.git_push_dsp_rf_list.append((self.rf_bin, self.git_push_dsp_dir))
                break


class gitPushCusSDK009(gitPushCusSDK):
    def __init__(self):
        super(gitPushCusSDK009, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.branch_name = "master"
        # self.git.checkout(self.branch_name)

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_master_sdk009"]

    def get_dsp_rf_dir(self, root_dir):
        for root,dirs,files in os.walk(root_dir,topdown=False):
            if "DSP" in dirs:
                self.dsp_rf_root_dir = os.path.join(root,"DSP")
                self.dsp_bin = os.path.join(self.dsp_rf_root_dir,"dsp.bin")
                self.rf_bin = os.path.join(self.dsp_rf_root_dir,"rf.bin")
                self.git_push_dsp_dir = os.path.dirname(self.target_dist_dir)
                self.git_push_dsp_dir = os.path.join(self.git_push_dsp_dir,"cus","evb_sdk009","images")
                self.git_push_dsp_rf_list.append((self.dsp_bin, self.git_push_dsp_dir))
                self.git_push_dsp_rf_list.append((self.rf_bin, self.git_push_dsp_dir))
                break


class gitPushR2RCSDK009(gitPushCusSDK):
    def __init__(self):
        super(gitPushR2RCSDK009, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.branch_name = "r2_rc_sdk_1.009"
        # self.git.checkout(self.branch_name)

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_r2_rc_sdk009"]

    def get_dsp_rf_dir(self, root_dir):
        for root,dirs,files in os.walk(root_dir,topdown=False):
            if "DSP" in dirs:
                self.dsp_rf_root_dir = os.path.join(root,"DSP")
                self.dsp_bin = os.path.join(self.dsp_rf_root_dir,"dsp.bin")
                self.rf_bin = os.path.join(self.dsp_rf_root_dir,"rf.bin")
                self.git_push_dsp_dir = os.path.dirname(self.target_dist_dir)
                self.git_push_dsp_dir = os.path.join(self.git_push_dsp_dir,"cus","evb","images")
                self.git_push_dsp_rf_list.append((self.dsp_bin, self.git_push_dsp_dir))
                self.git_push_dsp_rf_list.append((self.rf_bin, self.git_push_dsp_dir))
                break

class gitPushR2RCSDK008(gitPushCusSDK):
    def __init__(self):
        super(gitPushR2RCSDK008, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.branch_name = "r2_rc_sdk_1.008"
        # self.git.checkout(self.branch_name)

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_r2_rc_sdk008"]

    def get_dsp_rf_dir(self, root_dir):
        for root,dirs,files in os.walk(root_dir,topdown=False):
            if "DSP" in dirs:
                self.dsp_rf_root_dir = os.path.join(root,"DSP")
                self.dsp_bin = os.path.join(self.dsp_rf_root_dir,"dsp.bin")
                self.rf_bin = os.path.join(self.dsp_rf_root_dir,"rf.bin")
                self.git_push_dsp_dir = os.path.dirname(self.target_dist_dir)
                self.git_push_dsp_dir = os.path.join(self.git_push_dsp_dir,"cus","evb","images")
                self.git_push_dsp_rf_list.append((self.dsp_bin, self.git_push_dsp_dir))
                self.git_push_dsp_rf_list.append((self.rf_bin, self.git_push_dsp_dir))
                break


class gitPushR1RCSDK(gitPushSDKBase):
    def __init__(self):
        super(gitPushR1RCSDK, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.branch_name = "r1_rc"
        # self.git.checkout(self.branch_name)

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_r1_rc_sdk"]

class gitPushR2RCSDK(gitPushSDKBase):
    def __init__(self):
        super(gitPushR2RCSDK, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.branch_name = "r2_rc"
        # self.git.checkout(self.branch_name)

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cus_r2_rc_sdk"]

    def get_dsp_rf_dir(self, root_dir):
        for root,dirs,files in os.walk(root_dir,topdown=False):
            if "DSP" in dirs:
                self.dsp_rf_root_dir = os.path.join(root,"DSP")
                self.git_push_dsp_dir = os.path.dirname(self.target_dist_dir)

                dsp_bin = os.path.join(self.dsp_rf_root_dir,"CRANE","CAT1GSM","dsp.bin")
                rf_bin = os.path.join(self.dsp_rf_root_dir,"CRANE","CAT1GSM","rf.bin")

                crane_dsp_rf_dir = os.path.join(self.git_push_dsp_dir,"cus","evb","images")
                self.git_push_dsp_rf_list.append((dsp_bin, crane_dsp_rf_dir))
                self.git_push_dsp_rf_list.append((rf_bin, crane_dsp_rf_dir))

                dsp_bin = os.path.join(self.dsp_rf_root_dir,"CRANEG","CAT1WCDMAGSM","dsp.bin")
                rf_bin = os.path.join(self.dsp_rf_root_dir,"CRANEG","CAT1WCDMAGSM","rf.bin")

                craneg_a0_dir = os.path.join(self.git_push_dsp_dir,"cus","evb_g_a0","images")
                self.git_push_dsp_rf_list.append((dsp_bin, craneg_a0_dir))
                self.git_push_dsp_rf_list.append((rf_bin, craneg_a0_dir))

                dsp_bin = os.path.join(self.dsp_rf_root_dir,"CRANEG","CAT1GSM","dsp.bin")
                rf_bin = os.path.join(self.dsp_rf_root_dir,"CRANEG","CAT1GSM","rf.bin")

                cranec_dir = os.path.join(self.git_push_dsp_dir,"cus","evb_c","images")
                self.git_push_dsp_rf_list.append((dsp_bin, cranec_dir))
                self.git_push_dsp_rf_list.append((rf_bin, cranec_dir))

                self.log.info(self.git_push_dsp_rf_list)
                break


class GitPushDspBase(GitPushBase):
    def __init__(self):
        super(GitPushDspBase, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.decompress_tool = zipTool()

        self.release_dsp_bin = ''
        self.release_rf_bin = ''
        self.release_rf_verson_file = ''
        self.dsp_version = ''

        self.update()
        self.create_git()

        # self.print_info()

    def get_config(self):
        self.config_d = {}

    def update(self):
        self.get_config()
        self.release_dir = os.path.normpath(self.config_d["release_dir"])
        self.target_dist_dir = os.path.normpath(self.config_d["target_dir"])
        self.git_push_root_dir = os.path.normpath(self.config_d["git_push_root_dir"])
        self.local_dsp_bin = os.path.normpath(self.config_d["verson_file"])
        self.local_rf_bin = os.path.normpath(os.path.join(os.path.dirname(self.local_dsp_bin), "rf.bin"))
        self.local_rf_verson_file = os.path.normpath(os.path.join(os.path.dirname(self.local_dsp_bin), "RF_Version.txt"))
        self.local_rf_excel_file = os.path.normpath(os.path.join(os.path.dirname(self.local_dsp_bin), "rf.xlsm"))
        self.push_cmd = self.config_d["git_push_cmd"]

        self.dsp_version_pattern = re.compile(self.config_d["version_pattern"])
        self.release_target_file = self.config_d["release_target"]


    def get_dsp_version(self, dsp_bin = None):
        """CRANE_CAT1GSM_L1_1.043.000 , Dec 13 2019 03:30:56"""
        if not dsp_bin:
            dsp_bin = self.local_dsp_bin
        dsp_version_file = os.path.join(self.root_dir, "tmp", "dsp_version_tmp.bin")
        self.decompress_tool.decompress_bin(dsp_bin, dsp_version_file)
        assert os.path.exists(dsp_version_file), "can not find {}".format(dsp_version_file)
        with open(dsp_version_file, "rb") as fob:
            text = fob.read()
        match = self.dsp_version_pattern.findall(text)
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
                if self.release_target_file in files:
                    rf = os.path.join(root,"PM813","rf.bin")
                    if os.path.exists(rf):
                        dsp_release_bin_l.append(os.path.join(root,self.release_target_file))
        dsp_release_bin_l.sort(key=lambda fn: os.path.getmtime(fn))
        self.log.debug("\n".join(dsp_release_bin_l))
        self.release_dsp_bin = dsp_release_bin_l[-1]
        root_dir = os.path.dirname(self.release_dsp_bin)
        self.release_rf_bin = os.path.join(root_dir,"PM813","rf.bin")
        self.release_rf_verson_file = os.path.join(root_dir,"PM813","RF_Version.txt")
        self.release_rf_excel_file = os.path.join(root_dir,"PM813","rf.xlsm")

    def condition(self):
        self.update()
        self.git_clean()
        local_dsp_version = self.get_dsp_version()
        self.get_release_dsp_rf()
        release_dsp_version = self.get_dsp_version(self.release_dsp_bin)
        if local_dsp_version == release_dsp_version:
            return False
        else:
            self.log.info("local_dsp_version  :", local_dsp_version)
            self.log.info("release_dsp_version:", release_dsp_version)
            self.dsp_version = release_dsp_version
            return True

    def close_push(self):
        to_address = ",".join(["binwu@asrmicro.com"])
        subject = "%s auto push" % self.dsp_version
        msg = r"Hi %s, %s auto push done!" % (to_address.split("@")[0], self.dsp_version)
        send_email_tool(to_address, subject.upper(), msg)


    def git_push_start(self):
        if not self.condition():
            time.sleep(10)
            return

        self.log.info("wait for dsp copy...")
        time.sleep(30)

        local_bin_l = [self.local_dsp_bin, self.local_rf_bin, self.local_rf_verson_file, self.local_rf_excel_file]
        release_bin_l = [self.release_dsp_bin, self.release_rf_bin, self.release_rf_verson_file, self.release_rf_excel_file]
        for release_bin,local_bin in zip(release_bin_l,local_bin_l):
            if os.path.exists(release_bin):
                if os.path.exists(local_bin):
                    os.remove(local_bin)
                shutil.copy2(release_bin,local_bin)

        self.log.info("=" * 50)
        self.log.info("git push dsp...")
        try:
            self.git_add(*local_bin_l)
            match = re.findall(self.dsp_version_pattern, self.dsp_version)
            if match:
                dsp_version = match[0]
            else:
                dsp_version = str(time.asctime())
            commit_info = "update dsp dailybuild %s" % dsp_version
            self.git_commit(commit_info)
            self.git_push()
            self.close_push()
            return True
        except Exception,e:
            self.log.error(e)
            self.log.error("git push error")
            self.git_clean()
            return None


class gitPushCraneDsp(GitPushDspBase):
    def __init__(self):
        super(gitPushCraneDsp, self).__init__()
        self.log = MyLogger(self.__class__.__name__)


    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane_dsp"]

    def get_dsp_version(self, dsp_bin = None):
        """CRANE_CAT1GSM_L1_1.043.000 , Dec 13 2019 03:30:56"""
        if not dsp_bin:
            dsp_bin = self.local_dsp_bin
        dsp_version_file = os.path.join(self.root_dir, "tmp", "dsp_version_tmp.bin")
        self.decompress_tool.decompress_bin(dsp_bin, dsp_version_file, "lzma")
        assert os.path.exists(dsp_version_file), "can not find {}".format(dsp_version_file)
        with open(dsp_version_file, "rb") as fob:
            text = fob.read()
        match = self.dsp_version_pattern.findall(text)
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
        # self.log.info("release_dir_list len:",len(release_dir_list))
        # self.log.info(release_dir_list)
        release_dir_list = [os.path.join(root_dir,"CAT1_L1","CRANE","CAT1GSM") for root_dir in release_dir_list]
        for release_dir in release_dir_list:
            for root,dirs,files in os.walk(release_dir,topdown=False):
                if self.release_target_file in files:
                    rf = os.path.join(root,"PM813","rf.bin")
                    if os.path.exists(rf):
                        dsp_release_bin_l.append(os.path.join(root,self.release_target_file))
        dsp_release_bin_l.sort(key=lambda fn: os.path.getmtime(fn))
        self.log.debug("\n".join(dsp_release_bin_l))
        self.release_dsp_bin = dsp_release_bin_l[-1]
        root_dir = os.path.dirname(self.release_dsp_bin)
        self.release_rf_bin = os.path.join(root_dir,"PM813","rf.bin")
        self.release_rf_verson_file = os.path.join(root_dir,"PM813","RF_Version.txt")
        self.release_rf_excel_file = os.path.join(root_dir,"PM813","rf.xlsm")

class gitPushCraneGDsp(GitPushDspBase):
    def __init__(self):
        super(gitPushCraneGDsp, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["craneg_dsp"]

    def get_dsp_version(self, dsp_bin = None):
        """CRANE_CAT1GSM_L1_1.043.000 , Dec 13 2019 03:30:56"""
        if not dsp_bin:
            dsp_bin = self.local_dsp_bin
        dsp_version_file = os.path.join(self.root_dir, "tmp", "dsp_version_tmp.bin")
        self.decompress_tool.decompress_bin(dsp_bin, dsp_version_file, "lzma")
        assert os.path.exists(dsp_version_file), "can not find {}".format(dsp_version_file)
        with open(dsp_version_file, "rb") as fob:
            text = fob.read()
        match = self.dsp_version_pattern.findall(text)
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
        # self.log.info("release_dir_list len:",len(release_dir_list))
        # self.log.info(release_dir_list)
        release_dir_list = [os.path.join(root_dir,"CAT1_L1","CRANEG","CAT1WCDMAGSM") for root_dir in release_dir_list]
        for release_dir in release_dir_list:
            self.log.debug(release_dir)
            for root,dirs,files in os.walk(release_dir,topdown=False):
                if self.release_target_file in files:
                    rf = os.path.join(root,"A0_PM813S","rf.bin")
                    if os.path.exists(rf):
                        dsp_release_bin_l.append(os.path.join(root,self.release_target_file))
        dsp_release_bin_l.sort(key=lambda fn: os.path.getmtime(fn))
        self.log.debug("\n".join(dsp_release_bin_l))
        self.release_dsp_bin = dsp_release_bin_l[-1]
        root_dir = os.path.dirname(self.release_dsp_bin)
        self.release_rf_bin = os.path.join(root_dir,"Z2_PM813","rf.bin")
        self.release_rf_verson_file = os.path.join(root_dir,"Z2_PM813","RF_Version.txt")
        self.release_a0_rf_bin = os.path.join(root_dir,"A0_PM813S","rf.bin")
        self.release_a0_rf_verson_file = os.path.join(root_dir,"A0_PM813S","RF_Version.txt")
        self.release_a0_rf_excel_file = os.path.join(root_dir,"A0_PM813S","rf.xlsm")


    def git_push_start(self):
        if not self.condition():
            time.sleep(10)
            return

        self.log.info("wait for dsp copy...")
        time.sleep(30)
        a0_rf_bin = os.path.join(self.config_d["a0_rf_dir"], "rf.bin")
        a0_rf_verson_file = os.path.join(self.config_d["a0_rf_dir"], "RF_Version.txt")
        a0_rf_excel_file = os.path.join(self.config_d["a0_rf_dir"], "rf.xlsm")
        local_bin_l = [self.local_dsp_bin, self.local_rf_bin, self.local_rf_verson_file, a0_rf_bin, a0_rf_verson_file, a0_rf_excel_file]
        release_bin_l = [self.release_dsp_bin, self.release_rf_bin, self.release_rf_verson_file, self.release_a0_rf_bin, self.release_a0_rf_verson_file,self.release_a0_rf_excel_file]
        for release_bin,local_bin in zip(release_bin_l,local_bin_l):
            if os.path.exists(release_bin):
                if os.path.exists(local_bin):
                    os.remove(local_bin)
                shutil.copy2(release_bin,local_bin)

        self.log.info("=" * 50)
        self.log.info("git push dsp...")
        try:
            self.git_add(*local_bin_l)
            match = re.findall(self.dsp_version_pattern, self.dsp_version)
            if match:
                dsp_version = match[0]
            else:
                dsp_version = str(time.asctime())
            commit_info = "update dsp dailybuild %s" % dsp_version
            self.git_commit(commit_info)
            self.git_push()
            self.close_push()
            return True
        except Exception,e:
            self.log.error(e)
            self.log.error("git push error")
            self.git_clean()
            return None

class gitPushCraneCDsp(gitPushCraneDsp):
    def __init__(self):
        super(gitPushCraneCDsp, self).__init__()
        self.log = MyLogger(self.__class__.__name__)


    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cranec_dsp"]

    def get_release_dsp_rf(self):
        dsp_release_bin_l = []
        release_dir_list = [os.path.join(self.release_dir,_dir) for _dir in os.listdir(self.release_dir) \
                            if os.path.isdir(os.path.join(self.release_dir,_dir))]
        release_dir_list.sort(key=lambda fn: os.path.getmtime(fn))
        release_dir_list = [os.path.join(root_dir,"CAT1_L1","CRANEG","CAT1GSM") for root_dir in release_dir_list]
        for release_dir in release_dir_list:
            for root,dirs,files in os.walk(release_dir,topdown=False):
                if self.release_target_file in files:
                    rf = os.path.join(root,"A0_PM813S","rf.bin")
                    if os.path.exists(rf):
                        dsp_release_bin_l.append(os.path.join(root,self.release_target_file))
        dsp_release_bin_l.sort(key=lambda fn: os.path.getmtime(fn))
        self.log.debug("\n".join(dsp_release_bin_l))
        self.release_dsp_bin = dsp_release_bin_l[-1]
        root_dir = os.path.dirname(self.release_dsp_bin)
        self.release_rf_bin = os.path.join(root_dir,"A0_PM813S","rf.bin")
        self.release_rf_verson_file = os.path.join(root_dir,"A0_PM813S","RF_Version.txt")
        self.release_rf_excel_file = os.path.join(root_dir,"A0_PM813S","rf.xlsm")


class gitPushCraneMDsp(GitPushDspBase):
    def __init__(self):
        super(gitPushCraneMDsp, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["cranem_dsp"]

    def get_dsp_version(self, dsp_bin = None):
        """CRANE_CAT1GSM_L1_1.043.000 , Dec 13 2019 03:30:56"""
        if not dsp_bin:
            dsp_bin = self.local_dsp_bin
        dsp_version_file = os.path.join(self.root_dir, "tmp", "dsp_version_tmp.bin")
        self.decompress_tool.decompress_bin(dsp_bin, dsp_version_file, "lzma")
        assert os.path.exists(dsp_version_file), "can not find {}".format(dsp_version_file)
        with open(dsp_version_file, "rb") as fob:
            text = fob.read()
        match = self.dsp_version_pattern.findall(text)
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
        # self.log.info("release_dir_list len:",len(release_dir_list))
        # self.log.info(release_dir_list)
        release_dir_list = [os.path.join(root_dir,"CAT1_L1","CRANEM","CAT1GSM") for root_dir in release_dir_list]
        for release_dir in release_dir_list:
            self.log.debug(release_dir)
            for root,dirs,files in os.walk(release_dir,topdown=False):
                if self.release_target_file in files:
                    rf = os.path.join(root,"PM803","rf.bin")
                    if os.path.exists(rf):
                        dsp_release_bin_l.append(os.path.join(root,self.release_target_file))
        dsp_release_bin_l.sort(key=lambda fn: os.path.getmtime(fn))
        self.log.debug("\n".join(dsp_release_bin_l))
        self.release_dsp_bin = dsp_release_bin_l[-1]
        root_dir = os.path.dirname(self.release_dsp_bin)
        self.release_rf_bin = os.path.join(root_dir,"PM803","rf.bin")
        self.release_rf_verson_file = os.path.join(root_dir,"PM803","RF_Version.txt")
        self.release_rf_excel_file = os.path.join(root_dir,"PM803","rf.xlsm")


class gitPushCraneDCXODsp(GitPushDspBase):
    def __init__(self):
        super(gitPushCraneDCXODsp, self).__init__()
        self.log = MyLogger(self.__class__.__name__)


    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["crane_dsp_dcxo"]

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
                if self.release_target_file in files:
                    rf = os.path.join(os.path.dirname(root),"PM813","rf.bin")
                    if os.path.exists(rf):
                        dsp_release_bin_l.append(os.path.join(root,self.release_target_file))
        dsp_release_bin_l.sort(key=lambda fn: os.path.getmtime(fn))
        self.log.debug("\n".join(dsp_release_bin_l))
        self.release_dsp_bin = dsp_release_bin_l[-1]
        root_dir = os.path.dirname(os.path.dirname(self.release_dsp_bin))
        self.release_rf_bin = os.path.join(root_dir,"PM813","rf.bin")
        self.release_rf_verson_file = os.path.join(root_dir,"PM813","RF_Version.txt")

class gitPushDownloadTool(GitPushBase):
    def __init__(self):
        super(gitPushDownloadTool, self).__init__()
        self.zip_tool = zipTool()

        self.downloadtool_name = None
        self.downloadtool_list = []
        self.update()
        self.create_git()

        # self.print_info()

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["downloadtool"]

    def update(self):
        self.get_config()
        self.downloadtool_release_dir = os.path.normpath(self.config_d["release_dir"])
        self.git_push_root_dir = os.path.normpath(self.config_d["git_push_root_dir"])
        self.target_dist_dir = os.path.normpath(self.config_d["target_dir"])
        self.downloadtool_dir = os.path.normpath(os.path.join(self.root_dir, self.config_d["local_dir"]))
        self.version_file = self.config_d["verson_file"]
        self.release_target = self.config_d["release_target"]
        self.release_tool_pattern = self.config_d["release_tool_pattern"]
        self.clean_bin_list = self.config_d["clean_bin_list"]

        self.partition_config = os.path.normpath(os.path.join(self.root_dir, self.config_d["partition_config"]))
        self.template_config = os.path.normpath(os.path.join(self.root_dir, self.config_d["template_config"]))
        self.product_config = os.path.normpath(os.path.join(self.root_dir, self.config_d["product_config"]))

        self.push_cmd = self.config_d["git_push_cmd"]
        self.win_type = self.config_d["win_type"]

    def find_new_tool(self):
        tool_list = [_file for _file in os.listdir(self.downloadtool_release_dir) if re.match(self.release_tool_pattern, _file)]
        tool_list.sort(key=lambda fn: os.path.getmtime(os.path.join(self.downloadtool_release_dir,fn)))
        assert tool_list,"can not find downloadtool"
        self.downloadtool_name = tool_list[-1]
        self.log.debug("newest downloadtool: %s" % self.downloadtool_name)

    def copy_tool(self):
        file_name_l = [self.downloadtool_name, self.downloadtool_name.replace("x64","x86")]
        self.downloadtool_list = []
        for file_name in file_name_l:
            zip_file = os.path.join(self.downloadtool_dir, file_name)
            # self.log.info(zip_file)
            download_tool_fname = zip_file.replace(".exe","")
            if not os.path.exists(zip_file):
                shutil.copy2(os.path.join(self.downloadtool_release_dir, file_name), self.downloadtool_dir)
                time.sleep(3)
                with ziptool_mutex:
                    self.zip_tool.unpack_archive(zip_file)
            elif not os.path.exists(download_tool_fname):
                time.sleep(3)
                with ziptool_mutex:
                    self.zip_tool.unpack_archive(zip_file)
            self.downloadtool_list.append(download_tool_fname)
        for _tool in self.downloadtool_list:
            self.log.info(_tool)

    def prepare_download_tool(self):
        self.log.debug("\n".join(self.downloadtool_list))
        for download_tool_dir in self.downloadtool_list:
            if not os.path.exists(download_tool_dir):
                self.log.warning("%s not exists" % download_tool_dir)
                continue
            dist_dir = os.path.join(self.target_dist_dir, download_tool_dir,"images")
            # dist_bin_l = [os.path.join(dist_dir, _file) for _file in os.listdir(dist_dir) if os.path.isfile(os.path.join(dist_dir, _file))]
            clean_bin_l = [os.path.join(dist_dir, _file) for _file in self.clean_bin_list]
            for _file in clean_bin_l:
                if os.path.exists(_file):
                    os.remove(_file)
            if os.path.isdir(self.partition_config):
                for _file in os.listdir(self.partition_config):
                    shutil.copy2(os.path.join(self.partition_config,_file),
                                 os.path.join(download_tool_dir,"config","partition",_file))
            elif os.path.isfile(self.partition_config):
                shutil.copy2(self.partition_config,os.path.join(download_tool_dir,"config","partition",
                                                                os.path.basename(self.partition_config)))
            else:
                self.log.error("self.partition_config:%s error" % self.partition_config)

            if os.path.isdir(self.product_config):
                for _file in os.listdir(self.product_config):
                    shutil.copy2(os.path.join(self.product_config,_file),
                                 os.path.join(download_tool_dir,"config","partition",_file))
            elif os.path.isfile(self.product_config):
                shutil.copy2(self.product_config,os.path.join(download_tool_dir,"config","partition",
                                                                os.path.basename(self.product_config)))
            else:
                self.log.error("self.product_config:%s error" % self.product_config)

            if os.path.isdir(self.template_config):
                for _file in os.listdir(self.template_config):
                    shutil.copy2(os.path.join(self.template_config,_file),
                                 os.path.join(download_tool_dir,"config","template",_file))
            elif os.path.isfile(self.template_config):
                shutil.copy2(self.template_config,
                             os.path.join(download_tool_dir,"config","template",os.path.basename(self.template_config)))
            else:
                self.log.error("self.template_config:%s error" % self.template_config)

    def prepare_git_push(self):
        self.prepare_download_tool()
        for _tool in os.listdir(self.target_dist_dir):
            if re.match("aboot-tools-.*?-win-x[0-9][0-9]",_tool):
                shutil.rmtree(os.path.join(self.target_dist_dir, _tool))
        for _tool in self.downloadtool_list:
            shutil.copytree(_tool, os.path.join(self.target_dist_dir,os.path.basename(_tool)))

    def close_push(self):
        to_address = ",".join(["binwu@asrmicro.com"])
        subject = "%s auto push" % self.downloadtool_name
        msg = r"Hi %s, %s auto push done!" % (to_address.split("@")[0], self.downloadtool_name)
        send_email_tool(to_address, subject.upper(), msg)

    def git_push_start(self):
        self.find_new_tool()
        self.git_clean()
        if os.path.exists(os.path.join(self.downloadtool_dir,self.downloadtool_name)):
            self.log.debug("%s already exists" % self.downloadtool_name)
            return None
        self.log.info("wait for copy...")
        time.sleep(60)
        self.copy_tool()
        downloadtool = os.path.join(self.downloadtool_dir, self.downloadtool_name)
        # self.log.info(downloadtool)

        self.log.info("=" * 50)
        self.log.info("git push ...")
        try:
            self.prepare_git_push()
            self.git_add()
            commit_info = "%s" % self.downloadtool_name
            self.git_commit(commit_info)
            self.git_push()
            self.close_push()
            return True
        except Exception,e:
            self.log.error(e)
            self.log.error("git push error")
            self.git_clean()
            os.remove(os.path.join(self.downloadtool_dir,self.downloadtool_name))
            return None

class GitPushDMSDK(gitPushR2RCSDK):
    def __init__(self):
        super(gitPushR2RCSDK, self).__init__()
        self.log = MyLogger(self.__class__.__name__)

        self.branch_name = "master"
        # self.git.checkout(self.branch_name)

    def get_config(self):
        json_file = os.path.join(self.root_dir,"json","git_push.json")
        json_str = load_json(json_file)
        self.config_d = json_str["dm_sdk"]

    def get_dsp_rf_dir(self, root_dir):
        self.git_push_dsp_dir = os.path.dirname(self.target_dist_dir)
        for root,dirs,files in os.walk(root_dir,topdown=False):
            if "DSP" in dirs:
                self.dsp_rf_root_dir = os.path.join(root,"DSP")

                dsp_bin = os.path.join(self.dsp_rf_root_dir,"CRANEM","CAT1GSM","dsp.bin")
                rf_bin = os.path.join(self.dsp_rf_root_dir,"CRANEM","CAT1GSM","PM803","rf.bin")

                cranem_dm_dir = os.path.join(self.git_push_dsp_dir,"cus","evb_dm","images")
                self.git_push_dsp_rf_list.append((dsp_bin, cranem_dm_dir))
                self.git_push_dsp_rf_list.append((rf_bin, cranem_dm_dir))

            if "CP" in dirs:
                cp_root_dir = os.path.join(root,"CP")

                boot33_bin = os.path.join(cp_root_dir,"CAT1GSM","boot33.bin")
                apn_bin = os.path.join(cp_root_dir,"CAT1GSM","apn.bin")

                cranem_dm_dir = os.path.join(self.git_push_dsp_dir,"cus","evb_dm","images")
                self.git_push_dsp_rf_list.append((boot33_bin, cranem_dm_dir))
                self.git_push_dsp_rf_list.append((apn_bin, cranem_dm_dir))

                break
        cranem_dm_dir = os.path.join(self.git_push_dsp_dir,"cus","evb_dm","build")
        Crane_DS_miniPhone_h = os.path.join(cranem_dm_dir,"Crane_DS_miniPhone_16M_Ram_8M_Flash_XIP_CIPSRAM.h")
        Crane_DS_miniPhone_sct = os.path.join(cranem_dm_dir,"Crane_DS_miniPhone_16M_Ram_8M_Flash_XIP_CIPSRAM.sct")
        dist_dir = os.path.join(self.target_dist_dir,"csw","platform","dev_plat","build")
        self.git_push_dsp_rf_list.append((Crane_DS_miniPhone_h, dist_dir))
        self.git_push_dsp_rf_list.append((Crane_DS_miniPhone_sct, dist_dir))
        for _item in self.git_push_dsp_rf_list:
            self.log.info(_item)

    def find_new_cp_sdk(self):
        cp_sdk_list = [_file for _file in os.listdir(self.cp_sdk_release_dir) if _file.startswith(self.release_target)]
        cp_sdk_list.sort(key=lambda fn: os.path.getmtime(os.path.join(self.cp_sdk_release_dir,fn)))
        assert cp_sdk_list,"can not find sdk"
        self.cp_sdk = cp_sdk_list[-1]
        self.log.debug("newest adk: %s" % self.cp_sdk)

    def copy_sdk(self):
        copy(os.path.join(self.cp_sdk_release_dir,self.cp_sdk),os.path.join(self.cp_sdk_dir,self.cp_sdk))
        time.sleep(3)


    def unzip_sdk(self):
        fname,_ = os.path.splitext(self.cp_sdk)
        root_dir = os.path.join(self.cp_sdk_dir,self.cp_sdk,"SDK")
        sdk_zip = [ os.path.join(root_dir, _file) for _file in os.listdir(root_dir) if _file.startswith(self.release_target)]
        assert sdk_zip,"can not find %s" % root_dir
        sdk_zip = sdk_zip[-1]
        while True:
            try:
                with ziptool_mutex:
                    self.zip_tool.unpack_archive(sdk_zip, root_dir)
                assert os.path.exists(root_dir),"can not find %s" % root_dir
                for root,dirs,files in os.walk(root_dir,topdown=False):
                    if "3g_ps" in dirs:
                        self.cp_sdk_root_dir = root
                        break
                assert os.path.exists(self.cp_sdk_root_dir),"can not find %s" % self.cp_sdk_root_dir
                self.get_dsp_rf_dir(os.path.join(self.cp_sdk_dir,self.cp_sdk))
                return
            except Exception,e:
                time.sleep(10)
                self.log.error(e)


    def delete_gui_lib(self,path_dir):
        pass

    def get_sdk_version(self,cp_version_file):
        '''#define SYSTEM_VERSION "SDK_1.011.009"'''
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
        CRANE_CUST_VER_INFO = "[%s]" % (SYSTEM_VERSION)
        self.log.debug(CRANE_CUST_VER_INFO)
        return CRANE_CUST_VER_INFO

    def condition(self):
        self.update()
        self.find_new_cp_sdk()
        self.git_clean()
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
        try:
            self.unzip_sdk()
        except Exception,e:
            self.log.error(e)
            os.remove(os.path.join(self.cp_sdk_dir,self.cp_sdk))
            return None
        self.log.info(self.cp_sdk_root_dir)


        sdk_verion_file = [os.path.join(self.cp_sdk_root_dir,"tavor","env","inc","sys_version.h"),self.cp_version_file]
        for version_file in sdk_verion_file:
            if not os.path.exists(version_file):
                self.log.error("can not file: %s" % version_file)
                return None
        return True
