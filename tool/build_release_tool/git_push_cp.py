#!usr/bin/env python

import git
import os
import shutil
import time
import re
from send_email import *
from util import *

class downloadToolController(object):
    def __init__(self,cfg, logger):
        super(downloadToolController,self).__init__()
        self.download_tool = None
        self.tmp = cfg.tmp_dir
        self.download_tool_dir = cfg.download_tool_dir
        self.download_tool_release_dir = cfg.download_tool_release_dir
        self.download_tool_file_name = cfg.download_tool_file_name
        self.partition_config = cfg.partition_config
        self.template_config = cfg.template_config
        self.default_dist_dir = cfg.dist_dir
        self.win_type = cfg.win_type

        self.log = logger
        self.download_tool_dict = {}
        self.release_download_tool_name = None
        self.download_tool_release_zip_dir = ""
        self.zip_tool = zipTool()

    def unzip_download_tool(self, zip_file, extract_dir = None):
        self.zip_tool.unpack_archive(os.path.join(self.download_tool_dir, zip_file), extract_dir)

    def update_download_tool(self):
        tools_list = [_file for _file in os.listdir(self.download_tool_release_dir) if self.win_type in _file and "aboot-tools" in _file and _file.endswith(".exe")]
        tools_list.sort(key=lambda fn:os.path.getmtime(self.download_tool_release_dir+'\\'+fn))
        self.log.debug(tools_list)
        if not self.download_tool_file_name:
            self.download_tool_file_name = tools_list[-1]
        file_name = self.download_tool_file_name
        self.download_tool_release_zip_dir = os.path.join(self.download_tool_dir,self.download_tool_file_name.replace(".exe",""))
        self.log.info(file_name)
        file_name_l = [file_name,file_name.replace("x64","x86")]
        self.download_tool = []
        for file_name in file_name_l:
            zip_file = os.path.join(self.download_tool_dir,file_name)
            self.log.info(zip_file)
            download_tool_fname = zip_file.replace(".exe","")
            if not os.path.exists(zip_file):
                shutil.copy2(os.path.join(self.download_tool_release_dir,file_name),self.download_tool_dir)
                time.sleep(3)
                self.unzip_download_tool(zip_file)
            elif not os.path.exists(download_tool_fname):
                time.sleep(3)
                self.unzip_download_tool(zip_file)
            self.download_tool.append(download_tool_fname)
        self.log.info("\n".join(self.download_tool))


    def prepare_download_tool(self, images, borad = "crane_evb_z2"):
        "borad : crane_evb_z2, bird_phone, crane_evb_dual_sim"
        self.log.debug("\n".join(images))
        self.log.debug("\n".join(self.download_tool))
        for download_tool_dir in self.download_tool:
            if not os.path.exists(download_tool_dir):
                self.log.warning("%s not exists"%download_tool_dir)
                continue
            dist_dir = os.path.join(download_tool_dir,"images")
            dist_bin_l = [os.path.join(dist_dir, os.path.basename(_file)) for _file in images]
            for src_bin,dist_bin in zip(images,dist_bin_l):
                if os.path.exists(src_bin):
                    if os.path.exists(dist_bin):
                        os.remove(dist_bin)
                    shutil.copy2(src_bin,dist_bin)
                else:
                    self.log.warning("%s not exists"%src_bin)
            if os.path.isdir(self.partition_config):
                for _file in os.listdir(self.partition_config):
                    shutil.copy2(os.path.join(self.partition_config, _file),os.path.join(download_tool_dir,"config","partition",_file))
            elif os.path.isfile(self.partition_config):
                shutil.copy2(self.partition_config,os.path.join(download_tool_dir,"config","partition",os.path.basename(self.partition_config)))
            else:
                self.log.error("self.partition_config:%s error"%self.partition_config)

            if os.path.isdir(self.template_config):
                for _file in os.listdir(self.template_config):
                    shutil.copy2(os.path.join(self.template_config, _file),os.path.join(download_tool_dir,"config","template",_file))
            elif os.path.isfile(self.template_config):
                shutil.copy2(self.template_config,os.path.join(download_tool_dir,"config","template",os.path.basename(self.template_config)))
            else:
                self.log.error("self.template_config:%s error"%self.template_config)

    def release_zip(self, dist_dir):
        assert os.path.exists(self.download_tool_release_zip_dir)," can not find download tool %s "%self.download_tool_release_zip_dir
        os.chdir(self.download_tool_release_zip_dir)
        zip_file = "ASR_CRANE_EVB_A0_16MB.zip"
        zip_file = os.path.join(dist_dir, zip_file)
        release_log = os.path.join(self.tmp,"release_log.txt")
        release_cmd = "arelease.exe -c . -g --erase-all -p ASR_CRANE_EVB -v CRANE_A0_16MB %s > %s"%(zip_file,release_log)
        os.system(release_cmd)


    def release_download_tool(self, release_name, borad = "crane_evb_z2", dist_dir = None):
        import time
        "borad : crane_evb_z2, bird_phone, crane_evb_dual_sim"
        date = time.strftime("%Y%m%d_%H%M%S")
        release_file_name = "%s_%s_DOWNLOAD_TOOL_%s"%(release_name.upper(),borad.upper(),date)
        release_dir = os.path.join(self.download_tool_dir,release_file_name)
        os.mkdir(release_dir) if not os.path.exists(release_dir) else None
        self.log.info(release_file_name)
        self.log.info(release_dir)
        for _tool in self.download_tool:
            dist_file = os.path.join(release_dir,os.path.basename(_tool))
            self.log.info(dist_file)
            if not os.path.exists(dist_file):
                shutil.copytree(_tool,dist_file)

        if dist_dir:
            dist = os.path.join(dist_dir,release_file_name)
        else:
            dist = os.path.join(self.default_dist_dir,"download_tool", borad, release_file_name)
        self.zip_tool.make_archive_e(dist,"zip",release_dir)
        self.release_download_tool_name = dist+".zip"
        self.download_tool_dict[borad] = self.release_download_tool_name
        self.log.info(self.download_tool_dict)
        return self.release_download_tool_name


class gitPushCpDailyBuild(object):
    def __init__(self,cfg, logger):
        self.cp_sdk_version = None
        self.cp_sdk = None

        self.cp_sdk_root_dir = None
        self.dsp_rf_root_dir = ''

        self.download_tool = None
        self.log = logger
        self.cp_sdk_release_dir = cfg.cp_sdk_release_dir

        self.git_push_cp_dir = cfg.git_push_cp_dir
        self.git_push_dsp_dir = ''

        self.cp_sdk_dir = cfg.cp_sdk_dir

        self.cp_version_file = os.path.join(cfg.cur_crane, cfg.cp_version_file)

        _repo = git.Repo(self.git_push_cp_dir)
        self.git = _repo.git
        self.git.config("--global","core.autocrlf","false")
        self.git.config("--global","user.name","binwu")
        self.git.config("--global","user.email","binwu@asrmicro.com")

        self.zip_tool = zipTool()

        # self.push_cmd = ("ssh://binwu@source.asrmicro.com:29418/crane/cp","HEAD:refs/for/master")
        self.push_cmd = ("ssh://binwu@source.asrmicro.com:29418/crane/cp","HEAD:refs/heads/master")

    def git_add(self,*file_name_l):
        self.log.info("git add...")
        if file_name_l:
            self.git.add(*file_name_l)
        else:
            self.git.add("--all")
        self.log.info("git add done")

    def git_commit(self,commit_info):
        self.log.info("git commit...")
        self.log.info("conmmit info:", commit_info)
        self.git.commit("-m %s"%commit_info)
        self.log.info("git commit done")

    def git_push(self):
        self.log.info("git push...")
        self.git.push(*self.push_cmd)
        self.log.info("git push done")

    def git_clean(self):
        # self.log.info("git clean...")
        try:
            self.git.clean("-xdf")
            self.git.reset("--hard","HEAD")
            self.git.pull()
        except Exception,e:
            self.log.error(e)
            assert("git_clean error")
        # self.log.info("git clean done")


    def find_new_cp_sdk(self):
        "ASR3601_MINIGUI_20191206_SDK.zip"
        cp_sdk_list = [_file for _file in os.listdir(self.cp_sdk_release_dir) if (_file.endswith(".zip") or _file.endswith(".7z")) and _file.startswith("ASR3601_MINIGUI_")]
        cp_sdk_list.sort(key=lambda fn:os.path.getmtime(os.path.join(self.cp_sdk_release_dir,fn)))
        assert cp_sdk_list,"can not find sdk"
        self.cp_sdk = cp_sdk_list[-1]
        self.log.debug("newest adk: %s"%self.cp_sdk)


    def clean_git_push_cp(self):
        self.git_clean()
        for _file in os.listdir(self.git_push_cp_dir):
            if _file  in [".git", "X.bat"]:
                continue
            _file = os.path.join(self.git_push_cp_dir,_file)
            if os.path.isfile(_file):
                os.remove(_file)
            else:
                shutil.rmtree(_file)
        self.log.info("clean cp done")

    def copy_sdk(self):
        self.log.info("copy %s..."%self.cp_sdk)
        shutil.copy2(os.path.join(self.cp_sdk_release_dir,self.cp_sdk),self.cp_sdk_dir)
        time.sleep(3)
        self.log.info("copy done.")

    def copy_sdk_to_git_push_cp(self,cp_sdk):
        try:
            root_dir = os.path.join(self.cp_sdk_dir,cp_sdk)
            for _file in os.listdir(root_dir):
                fname = os.path.join(root_dir,_file)
                if os.path.isfile(fname):
                    shutil.copy2(fname,os.path.join(self.git_push_cp_dir,_file))
                elif os.path.isdir(fname):
                    shutil.copytree(fname,os.path.join(self.git_push_cp_dir,_file))
                else:
                    self.log.warning("%s"%fname)

            self.log.info("%s"%self.dsp_rf_root_dir)
            if os.path.exists(self.dsp_rf_root_dir):
                dir_path= os.path.dirname(self.dsp_rf_root_dir)
                self.log.info("%s"%dir_path)
                dist_dir = os.path.join(self.git_push_cp_dir, os.path.basename(dir_path))
                self.log.info("%s"%dist_dir)
                if os.path.exists(dist_dir):
                    shutil.rmtree(dist_dir)
                shutil.copytree(dir_path, dist_dir)
                for _file in ["dsp.bin","rf.bin"]:
                    fname = os.path.join(self.dsp_rf_root_dir,_file)
                    dist_file = os.path.join(self.git_push_dsp_dir,_file)
                    if os.path.exists(self.git_push_dsp_dir):
                        if os.path.isfile(fname):
                            shutil.copy2(fname, dist_file)
                        else:
                            self.log.warning("%s"%fname)
            self.log.info("copy_sdk_to_git_push_cp done.")
        except Exception,e:
            self.log.error(e)
            self.log.error("copy_sdk_to_git_push_cp error")
            raise Exception,"copy_sdk_to_git_push_cp error"

    def unzip_sdk(self):
        fname, _ = os.path.splitext(self.cp_sdk)
        root_dir = os.path.join(self.cp_sdk_dir, fname)
        self.zip_tool.unpack_archive(os.path.join(self.cp_sdk_dir,self.cp_sdk), root_dir)
        assert os.path.exists(root_dir),"can not find %s"%root_dir
        for root, dirs, files in os.walk(root_dir, topdown=False):
            if "3g_ps" in dirs:
                self.cp_sdk_root_dir = root
                break
        assert os.path.exists(self.cp_sdk_root_dir),"can not find %s"%self.cp_sdk_root_dir

        for root, dirs, files in os.walk(root_dir, topdown=False):
            if "DSP" in dirs:
                self.dsp_rf_root_dir = os.path.join(root,"DSP")
                self.git_push_dsp_dir = os.path.dirname(self.git_push_cp_dir)
                self.git_push_dsp_dir = os.path.join(self.git_push_dsp_dir,"cus","evb","images")
                break


    def delete_gui_lib(self,path_dir):
        if not os.path.exists(path_dir):
            assert("%r not exists"%path_dir)
        for _file in os.listdir(path_dir):
            self.log.info(os.path.join(path_dir,_file))
            if _file in ["libmgapollo.a","libmgngux.a","libmgminigui.a","libtarget.a","libthirdparty.a","libmgmgeff.a","libhal.a","hal_init.o"]:
                os.remove(os.path.join(path_dir,_file))
        self.log.info("delete_gui_lib done.")

    def get_sdk_version(self,cp_version_file):
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
        return CRANE_CUST_VER_INFO

    def git_push_start(self):
        self.find_new_cp_sdk()
        if os.path.exists(os.path.join(self.cp_sdk_dir,self.cp_sdk)):
            release_sdk_time = os.path.getmtime(os.path.join(self.cp_sdk_release_dir,self.cp_sdk))
            local_sdk_time = os.path.getmtime(os.path.join(self.cp_sdk_dir,self.cp_sdk))
            # self.log.info("release_sdk_time: %r"%(release_sdk_time))
            # self.log.info("local_sdk_time: %r"%(local_sdk_time))
            if long(release_sdk_time) <= long(local_sdk_time):
                self.log.debug("%s already exists"%self.cp_sdk)
                return None
            else:
                self.log.info("release_sdk_time: %s"%time.asctime(time.localtime(release_sdk_time)))
                self.log.info("local_sdk_time: %s"%time.asctime(time.localtime(local_sdk_time)))
                os.remove(os.path.join(self.cp_sdk_dir,self.cp_sdk))
        self.log.info("wait for sdk copy...")
        time.sleep(60)
        self.copy_sdk()
        self.unzip_sdk()
        cp_sdk = self.cp_sdk_root_dir
        self.log.info(cp_sdk)
        cnt = 0
        while not os.path.exists(cp_sdk):
            self.log.error("%s not exists"%cp_sdk)
            time.sleep(10)
            self.unzip_sdk()
            cnt += 1
            if cnt == 10:
                return None

        sdk_verion_file = [os.path.join(cp_sdk,"tavor","env","inc","sys_version.h"),self.cp_version_file]
        for version_file in sdk_verion_file:
            if not os.path.exists(version_file):
                self.log.error("can not file: %s"%version_file)
                return None

        local_sdk_version = self.get_sdk_version(sdk_verion_file[1])
        release_sdk_version = self.get_sdk_version(sdk_verion_file[0])
        self.log.info("local_sdk_version:",local_sdk_version)
        self.log.info("release_sdk_version:",release_sdk_version)
        self.cp_sdk_version = release_sdk_version
        if release_sdk_version == local_sdk_version:
            self.log.info("%s already sync"%self.cp_sdk)
            return None

        self.log.info("="*50)
        self.log.info("git push cp...")
        self.clean_git_push_cp()
        gui_lib = os.path.join(cp_sdk,"tavor","Arbel","lib")
        self.delete_gui_lib(gui_lib)
        self.copy_sdk_to_git_push_cp(cp_sdk)
        try:
            self.git_add()
            commit_info = "%s"%self.cp_sdk
            self.git_commit(commit_info)
            self.git_push()
            return True
        except Exception,e:
            self.log.error(e)
            self.log.error("git push error")
            return None


class gitPushCusSDK(gitPushCpDailyBuild):
    def __init__(self,cfg, logger):
        super(gitPushCusSDK,self).__init__(cfg, logger)
        self.cp_sdk_version = None
        self.cp_sdk = None
        self.download_tool = None
        self.log = logger
        self.git_push_cp_dir = cfg.git_push_cus_dir
        self.cp_sdk_dir = cfg.cp_sdk_dir

        self.cp_version_file = os.path.join(cfg.cur_crane_cus, "evb", "src", cfg.cp_version_file)

        _repo = git.Repo(cfg.git_push_cus_root_dir)
        self.git = _repo.git
        self.git.config("--global","core.autocrlf","false")
        self.git.config("--global","user.name","binwu")
        self.git.config("--global","user.email","binwu@asrmicro.com")
        self.cfg = cfg

        self.init()

    def init(self):
        if self.cfg.release_branch == "r1":
            self.git.checkout("r1")
            self.push_cmd = ("origin","r1")
            self.cp_sdk_release_dir = self.cfg.cus_r1_cp_sdk_release_dir
        elif self.cfg.release_branch == "r1_plus_j":
            self.git.checkout("r1_plus_j")
            self.push_cmd = ("origin","r1_plus_j")
            self.cp_sdk_release_dir = self.cfg.cus_r1_cp_sdk_release_dir
        elif self.cfg.release_branch == "master":
            self.git.checkout("master")
            self.cp_sdk_release_dir = self.cfg.cus_cp_sdk_release_dir
            self.push_cmd = ("ssh://binwu@customsupport.asrmicro.com:29418/fp/crane-phone-rls","master")


class gitPushDspDailyBuild():
    def __init__(self,cfg, logger):
        self.dsp_version = None

        self.dsp_version_log = cfg.dsp_version_log
        self.dsp_release_bin = cfg.dsp_release_bin

        self.local_dsp_bin = cfg.local_dsp_bin
        self.local_rf_bin = cfg.local_rf_bin

        self.git = git.Repo(cfg.git_push_dsp_dir).git
        self.log = logger

        self.tmp_dir = cfg.tmp_dir
        self.decompress_tool = cfg.decompress_tool

        self.push_cmd = ("ssh://binwu@source.asrmicro.com:29418/crane/crane-dev","HEAD:refs/heads/master")

    def git_add(self,*file_name_l):
        self.log.info("git add...")
        if file_name_l:
            self.git.add(*file_name_l)
        else:
            self.git.add("--all")
        self.log.info("git add done")

    def git_commit(self,commit_info):
        self.log.info("git commit...")
        self.log.info("conmmit info:", commit_info)
        self.git.commit("-m %s"%commit_info)
        self.log.info("git commit done")

    def git_push(self):
        self.log.info("git push...")
        self.git.push(*self.push_cmd)
        self.log.info("git push done")

    def git_clean(self):
        # self.log.info("git clean...")
        try:
            self.git.clean("-xdf")
            self.git.reset("--hard","HEAD")
            self.git.pull()
        except Exception,e:
            self.log.error(e)
            assert("git_clean error")
        # self.log.info("git clean done")


    def get_local_dsp_version(self):
        "CRANE_CAT1GSM_L1_1.043.000 , Dec 13 2019 03:30:56"
        dsp_version_file = os.path.join(self.tmp_dir,"dsp_version_tmp.bin")
        decompress_cmd = "{0} -d -f {1} -o{2}".format(self.decompress_tool,self.local_dsp_bin, dsp_version_file)
        os.system(decompress_cmd)
        assert os.path.exists(dsp_version_file),"canot find {}".format(dsp_version_file)
        with open(dsp_version_file,"rb") as fobj:
            text = fobj.read()
        fobj.close()
        # match = re.findall("!(CRANE_.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])",text)
        match = re.findall("(CRANE_.{47})",text)
        if match:
            self.log.debug(match[0])
            version_info =  match[0]
        else:
            self.log.error("can not find dsp version infomation")
            version_info = None
        # os.remove(dsp_version_file)
        return version_info

    def update_dsp_version(self):
        dsp_version = self.get_local_dsp_version()
        if not dsp_version:
            return None
        self.log.debug(dsp_version)
        self.dsp_version = dsp_version
        with open(self.dsp_version_log,"w") as obj:
            obj.write(self.dsp_version)
        return self.dsp_version


    def git_push_start(self):
        self.git_clean()
        local_dsp_version = self.get_local_dsp_version()
        self.check_dsp_rf()
        if not self.update_dsp_version():
            self.log.info("dsp_version is None")
            return None
        if self.dsp_version == local_dsp_version:
            self.log.debug("%s already sync"%self.dsp_version)
            return None
        self.log.info(local_dsp_version)
        self.log.info(self.dsp_version)
        self.log.info("wait for dsp copy...")
        time.sleep(30)
        self.log.info("="*50)
        self.log.info("git push dsp...")
        try:
            self.git_add(self.local_dsp_bin, self.local_rf_bin)
            match = re.findall("(CRANE_.*? ,.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])",self.dsp_version)
            if match and "\00" not in match[0]:
                dsp_version = match[0]
            else:
                dsp_version =  str(time.asctime())
            commit_info = "update dsp dailybuild %s"%dsp_version
            self.git_commit(commit_info)
            self.git_push()
            return True
        except Exception,e:
            self.log.error(e)
            self.log.error("git push error")
            return None

    def check_dsp_rf(self):
        dsp_release_bin_l = []
        release_dir_list = [os.path.join(self.dsp_release_bin,_dir) for _dir in os.listdir(self.dsp_release_bin)\
                                if os.path.isdir(os.path.join(self.dsp_release_bin,_dir))]
        release_dir_list.sort(key=lambda fn:os.path.getmtime(fn))
        self.log.debug("release_dir_list len:",len(release_dir_list))
        self.log.debug(release_dir_list[-10:])
        for release_dir in release_dir_list[-10:]:
            self.log.debug(release_dir)
            for root, dirs, files in os.walk(release_dir, topdown=False):
                tgt_file = "crane_compress_a0.bin"
                if "crane_compress_a0.bin" in files:
                    rf = os.path.join(root,"PM813","rf.bin")
                    if os.path.exists(rf):
                        dsp_release_bin_l.append(os.path.join(root,tgt_file))
        dsp_release_bin_l.sort(key=lambda fn:os.path.getmtime(fn))
        self.log.debug("\n".join(dsp_release_bin_l))
        dsp_release_bin = dsp_release_bin_l[-1]
        self.log.debug(dsp_release_bin)
        root_dir = os.path.dirname(dsp_release_bin)
        rf_release_bin = os.path.join(root_dir,"PM813","rf.bin")
        release_bin_l = [dsp_release_bin, rf_release_bin]
        local_bin_l = [self.local_dsp_bin, self.local_rf_bin]
        for release_bin,local_bin in zip(release_bin_l,local_bin_l):
            if os.path.exists(release_bin):
                if os.path.exists(local_bin):
                    os.remove(local_bin)
                shutil.copy2(release_bin,local_bin)





