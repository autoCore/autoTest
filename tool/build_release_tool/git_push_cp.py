#!usr/bin/env python

import git
import os
import shutil
import time
import re
from send_email import *

class gitPushCpDailyBuild():
    def __init__(self,cfg, logger):
        self.cp_sdk_version = None
        self.cfg = cfg
        self.cp_sdk = None
        self.download_tool = None
        self.release_download_tool_name = None
        self.log = logger
        self.download_tool_dict = {}
        _repo = git.Repo(self.cfg.git_push_cp_dir)
        self.git = _repo.git

    def find_new_cp_sdk(self):
        "ASR3601_MINIGUI_20191206_SDK.zip"
        cp_sdk_list = [_file for _file in os.listdir(self.cfg.cp_sdk_release_dir) if _file.endswith("SDK.zip") and "ASR3601_MINIGUI_" in _file]
        cp_sdk_list.sort(key=lambda fn:os.path.getmtime(os.path.join(self.cfg.cp_sdk_release_dir,fn)))
        assert cp_sdk_list,"can not find sdk"
        self.cp_sdk = cp_sdk_list[-1]
        self.log.debug("newest adk: %s"%self.cp_sdk)


    def clean_git_push_cp(self):
        self.git.pull()
        for _file in os.listdir(self.cfg.git_push_cp_dir):
            if "X.bat" in _file or ".git" in _file:
                continue
            _file = os.path.join(self.cfg.git_push_cp_dir,_file)
            if os.path.isfile(_file):
                os.remove(_file)
            else:
                shutil.rmtree(_file)
        self.log.info("clean cp done")

    def copy_sdk(self):
        self.log.info("copy %s..."%self.cp_sdk)
        shutil.copy2(os.path.join(self.cfg.cp_sdk_release_dir,self.cp_sdk),self.cfg.cp_sdk_dir)
        self.log.info("copy done.")

    def copy_sdk_to_git_push_cp(self,cp_sdk):
        try:
            root_dir = os.path.join(self.cfg.cp_sdk_dir,cp_sdk)
            for _file in os.listdir(root_dir):
                fname = os.path.join(root_dir,_file)
                if os.path.isfile(fname):
                    shutil.copyfile(fname,os.path.join(self.cfg.git_push_cp_dir,_file))
                elif os.path.isdir(fname):
                    shutil.copytree(fname,os.path.join(self.cfg.git_push_cp_dir,_file))
                else:
                    self.log.warning("%s"%fname)
            self.log.info("copy_sdk_to_git_push_cp done.")
        except Exception,e:
            self.log.error(e)
            self.log.error("copy_sdk_to_git_push_cp error")
            raise Exception,"copy_sdk_to_git_push_cp error"


    def zip_tool(self, zip_file, format, in_file):
        assert os.path.exists(in_file)
        zip_file = ".".join([zip_file,format])
        zip_cmd = "%s a %s %s -y"%(self.cfg.unzip_tool, zip_file, in_file)
        self.log.debug(zip_cmd)
        os.system(zip_cmd)

    def unzip_tool(self,work_dir, zip_file,out_file = None):
        os.chdir(work_dir)
        if out_file:
            unzip_cmd = "%s x %s -o%s -y"%(self.cfg.unzip_tool, zip_file,out_file)
        else:
            unzip_cmd = "%s x %s -y"%(self.cfg.unzip_tool, zip_file)
        os.system(unzip_cmd)

    def unzip_sdk(self):
        self.unzip_tool(self.cfg.cp_sdk_dir, self.cp_sdk)

    def unzip_download_tool(self, zip_file):
        self.unzip_tool(self.cfg.download_tool_dir, zip_file)

    def delete_gui_lib(self,path_dir):
        if not os.path.exists(path_dir):
            assert("%r not exists"%path_dir)
        for _file in os.listdir(path_dir):
            self.log.debug(os.path.join(path_dir,_file))
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

    def git_push_cp_dailybuild(self):
        self.find_new_cp_sdk()
        if os.path.exists(os.path.join(self.cfg.cp_sdk_dir,self.cp_sdk)):
            release_sdk_time = os.path.getmtime(os.path.join(self.cfg.cp_sdk_release_dir,self.cp_sdk))
            local_sdk_time = os.path.getmtime(os.path.join(self.cfg.cp_sdk_dir,self.cp_sdk))
            # self.log.info("release_sdk_time: %r"%(release_sdk_time))
            # self.log.info("local_sdk_time: %r"%(local_sdk_time))
            if long(release_sdk_time) <= long(local_sdk_time):
                # self.log.info("%s already exists"%self.cp_sdk)
                time.sleep(10)
                return None
            else:
                self.log.info("release_sdk_time: %s"%time.asctime(time.localtime(release_sdk_time)))
                self.log.info("local_sdk_time: %s"%time.asctime(time.localtime(local_sdk_time)))
                os.remove(os.path.join(self.cfg.cp_sdk_dir,self.cp_sdk))
        self.log.info("wait for sdk copy...")
        time.sleep(60)
        self.copy_sdk()
        self.unzip_sdk()
        cp_sdk = os.path.join(self.cfg.cp_sdk_dir,self.cp_sdk.replace(".zip",""))
        self.log.info(cp_sdk)
        cnt = 0
        while not os.path.exists(cp_sdk):
            self.log.error("%s not exists"%cp_sdk)
            time.sleep(10)
            self.unzip_sdk()
            cnt += 1
            if cnt == 10:
                return None

        sdk_verion_file = [os.path.join(cp_sdk,"tavor","env","inc","sys_version.h"),os.path.join(self.cfg.cur_crane,self.cfg.cp_version_file)]
        for version_file in sdk_verion_file:
            if not os.path.exists(version_file):
                self.log.error("can not file: %s"%version_file)
                return None
        try:
            local_sdk_version = self.get_sdk_version(sdk_verion_file[1])
            release_sdk_version = self.get_sdk_version(sdk_verion_file[0])
            self.log.info("local_sdk_version:",local_sdk_version)
            self.log.info("release_sdk_version:",release_sdk_version)
            self.cp_sdk_version = release_sdk_version
            if release_sdk_version in local_sdk_version:
                self.log.info("%s already sync"%self.cp_sdk)
                time.sleep(10)
                return None

            self.log.info("="*50)
            self.log.info("git push cp...")
            self.clean_git_push_cp()
            self.log.info(self.cfg.cur_work_dir)
            os.chdir(self.cfg.cur_work_dir)
            gui_lib = os.path.join(self.cfg.cp_sdk_dir,cp_sdk,"tavor","Arbel","lib")
            self.delete_gui_lib(gui_lib)
            self.copy_sdk_to_git_push_cp(cp_sdk)
            self.log.info("git add...")
            self.git.add("--all")
            self.log.info("git add done")
            self.log.info("git commit...")
            commit_info = "%s"%self.cp_sdk
            self.git.commit("-m %s"%commit_info)
            self.log.info("git commit done")
            self.log.info("git push...")
            # self.git.push("ssh://binwu@source.asrmicro.com:29418/crane/cp","HEAD:refs/for/master")
            self.git.push("ssh://binwu@source.asrmicro.com:29418/crane/cp","HEAD:refs/heads/master")
            self.log.info("git push done")
            return True
        except Exception,e:
            self.log.error(e)
            self.log.error("git push error")
            return None

    def update_download_tool(self):
        tools_list = [_file for _file in os.listdir(self.cfg.download_tool_release_dir) if self.cfg.win_type in _file and "aboot-tools" in _file and _file.endswith(".exe")]
        tools_list.sort(key=lambda fn:os.path.getmtime(self.cfg.download_tool_release_dir+'\\'+fn))
        self.log.debug(tools_list)
        if self.cfg.download_tool_file_name:
            file_name = self.cfg.download_tool_file_name
        else:
            file_name = tools_list[-1]
        self.log.info(file_name)
        file_name_l = [file_name,file_name.replace("x64","x86")]
        self.download_tool = []
        for file_name in file_name_l:
            zip_file = os.path.join(self.cfg.download_tool_dir,file_name)
            download_tool_fname = zip_file.replace(".exe","")
            if not os.path.exists(zip_file):
                shutil.copy2(os.path.join(self.cfg.download_tool_release_dir,file_name),self.cfg.download_tool_dir)
                self.unzip_download_tool(zip_file)
            elif not os.path.exists(download_tool_fname):
                self.unzip_download_tool(zip_file)
            self.download_tool.append(download_tool_fname)
        self._check_dsp_rf_rbd()
        self.log.info(self.download_tool)
        # self.download_tool_name = os.path.basename(self.download_tool)

    def _check_dsp_rf_rbd(self):
        dsp_release_bin_l = []
        release_dir_list = [os.path.join(self.cfg.dsp_release_bin,_dir) for _dir in os.listdir(self.cfg.dsp_release_bin)\
                                if os.path.isdir(os.path.join(self.cfg.dsp_release_bin,_dir))]
        release_dir_list.sort(key=lambda fn:os.path.getmtime(fn))
        # self.log.debug(len(release_dir_list))
        # self.log.debug(release_dir_list[-30:])
        for release_dir in release_dir_list[-30:]:
            self.log.debug(release_dir)
            for root, dirs, files in os.walk(release_dir, topdown=False):
                tgt_file = "crane_compress_a0.bin"
                if "crane_compress_a0.bin" in files:
                    rf = os.path.join(root,"PM813","rf.bin")
                    if os.path.exists(rf):
                        dsp_release_bin_l.append(os.path.join(root,tgt_file))
        dsp_release_bin_l.sort(key=lambda fn:os.path.getmtime(fn))
        # self.log.debug("\n".join(dsp_release_bin_l))
        dsp_release_bin = dsp_release_bin_l[-1]
        self.log.info(dsp_release_bin)
        root_dir = os.path.dirname(dsp_release_bin)
        rf_release_bin = os.path.join(root_dir,"PM813","rf.bin")
        release_bin_l = [dsp_release_bin, rf_release_bin, self.cfg.rbd_release_bin]
        # release_bin_l = [self.cfg.dsp_release_bin,self.cfg.rf_release_bin,self.cfg.rbd_release_bin]
        local_bin_l = [self.cfg.dsp_bin,self.cfg.rf_bin,self.cfg.rbd_bin]
        for release_bin,local_bin in zip(release_bin_l,local_bin_l):
            if os.path.exists(release_bin):
                if os.path.exists(local_bin):
                    os.remove(local_bin)
                shutil.copy2(release_bin,local_bin)

    # def prepare_download_tool(self, borad = "crane_evb_z2"):
        # "borad : crane_evb_z2, bird_phone, crane_evb_dual_sim"
        # src_bin_l = [self.cfg.apn_bin, self.cfg.boot33_bin, self.cfg.cp_bin, self.cfg.logo_bin, self.cfg.updater_bin]
        # print "\n".join(src_bin_l)
        # print "\n".join(self.download_tool)
        # for download_tool_dir in self.download_tool:
            # if not os.path.exists(download_tool_dir):
                # print "not exists"
                # continue
            # dist_dir = os.path.join(download_tool_dir,"images")
            # dist_bin_l = [os.path.join(dist_dir,_file) for _file in ["apn.bin","boot33.bin","cp.bin","logo.bin","updater.bin"]]
            # for src_bin,dist_bin in zip(src_bin_l,dist_bin_l):
                # if os.path.exists(src_bin):
                    # shutil.copy2(src_bin,dist_bin)
                # else:
                    # print "%s not exists"%src_bin
            # shutil.copy2(self.cfg.dsp_bin,os.path.join(dist_dir,"dsp.bin"))
            # shutil.copy2(self.cfg.rf_bin,os.path.join(dist_dir,"rf.bin"))
            # shutil.copy2(self.cfg.rbd_bin,os.path.join(dist_dir,"ReliableData.bin"))

            # shutil.copy2(self.cfg.partition_config,os.path.join(download_tool_dir,"config","partition","CRANE_EVB_GENERIC_LAYOUT.json"))
            # shutil.copy2(self.cfg.template_config,os.path.join(download_tool_dir,"config","template","CRANE_EVB.json"))

    def prepare_download_tool(self, images, borad = "crane_evb_z2"):
        "borad : crane_evb_z2, bird_phone, crane_evb_dual_sim"
        self.log.info("\n".join(images))
        self.log.info("\n".join(self.download_tool))
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
            if os.path.isdir(self.cfg.partition_config):
                for _file in os.listdir(self.cfg.partition_config):
                    shutil.copy2(os.path.join(self.cfg.partition_config, _file),os.path.join(download_tool_dir,"config","partition",_file))
            elif os.path.isfile(self.cfg.partition_config):
                shutil.copy2(self.cfg.partition_config,os.path.join(download_tool_dir,"config","partition",os.path.basename(self.cfg.partition_config)))
            else:
                self.log.error("self.cfg.partition_config:%s error"%self.cfg.partition_config)

            if os.path.isdir(self.cfg.template_config):
                for _file in os.listdir(self.cfg.template_config):
                    shutil.copy2(os.path.join(self.cfg.template_config, _file),os.path.join(download_tool_dir,"config","template",_file))
            elif os.path.isfile(self.cfg.template_config):
                shutil.copy2(self.cfg.template_config,os.path.join(download_tool_dir,"config","template",os.path.basename(self.cfg.template_config)))
            else:
                self.log.error("self.cfg.template_config:%s error"%self.cfg.template_config)


    def release_download_tool(self, sdk_version, gui_version, borad = "crane_evb_z2", dist_dir = None):
        import time
        "borad : crane_evb_z2, bird_phone, crane_evb_dual_sim"
        date = time.strftime("%Y%m%d_%H%M%S")
        release_file_name = "%s_%s_%s_DOWNLOAD_TOOL_%s"%(sdk_version.upper(),gui_version.upper(),borad.upper(),date)
        release_dir = os.path.join(self.cfg.download_tool_dir,release_file_name)
        os.mkdir(release_dir) if not os.path.exists(release_dir) else None
        self.log.info(release_file_name)
        self.log.info(release_dir)
        for _tool in self.download_tool:
            dist_file = os.path.join(release_dir,os.path.basename(_tool))
            self.log.info(dist_file)
            if not os.path.exists(dist_file):
                shutil.copytree(_tool,dist_file)
        self.release_download_tool_name = release_file_name+".zip"
        if dist_dir:
            dist = os.path.join(dist_dir,release_file_name)
        else:
            dist = os.path.join(self.cfg.dist_dir,"download_tool", borad, release_file_name)
        self.zip_tool(dist,"zip",release_dir)
        self.download_tool_dict[borad] = dist+".zip"
        self.log.info(self.download_tool_dict)

    def send_release_download_tool_email(self,borad = "crane_evb_z2"):
        to_address = "SW_CV@asrmicro.com"
        subject = "New SDK and Download Tool Release"
        external_file = os.path.join(self.cfg.external_dir,"download_tool",borad,self.release_download_tool_name)
        msg = r"""
CP VERSION: %s
DOWNLOAD_TOOL: %s"""%(self.cp_sdk_version,external_file)
        self.log.info(subject)
        self.log.info(msg)
        send_email_tool(to_address,subject,msg)


class gitPushDspDailyBuild():
    def __init__(self,cfg, logger):
        self.dsp_version = None
        self.cfg = cfg
        self.git = git.Repo(cfg.git_push_dsp_dir).git
        self.log = logger

    def get_local_dsp_version(self):
        "CRANE_CAT1GSM_L1_1.043.000 , Dec 13 2019 03:30:56"
        with open(self.cfg.local_dsp_bin,"rb") as obj:
            text = obj.read()
        # match = re.findall("!(CRANE_.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])",text)
        match = re.findall("(CRANE_.{48})",text)
        if match:
            self.log.debug(match[0])
            return match[0]
        else:
            self.log.error("can not find dsp version infomation")
            return None

    def update_dsp_version(self):
        dsp_version = self.get_local_dsp_version()
        if not dsp_version:
            return None
        self.log.debug(dsp_version)
        self.dsp_version = dsp_version
        with open(self.cfg.dsp_version_log,"w") as obj:
            obj.write(self.dsp_version)
        return self.dsp_version


    def git_push_dsp_dailybuild(self):
        try:
            self.git.clean("-xdf")
            self.git.reset("--hard","HEAD")
            self.git.pull()
        except Exception,e:
            self.log.error(e)
            return None
        local_dsp_version = self.get_local_dsp_version()
        self.check_dsp_rf()
        if not self.update_dsp_version():
            self.log.info("dsp_version is None")
            return None
        if self.dsp_version in local_dsp_version:
            self.log.debug("%s already sync"%self.dsp_version)
            time.sleep(10)
            return None
        self.log.info(local_dsp_version)
        self.log.info(self.dsp_version)
        self.log.info("wait for dsp copy...")
        time.sleep(30)
        self.log.info("="*50)
        self.log.info("git push dsp...")
        try:
            self.log.info("git add...")
            self.git.add(self.cfg.local_dsp_bin,self.cfg.local_rf_bin)
            self.log.info("git add done")
            self.log.info("git commit...")
            # self.dsp_version = " ".join(self.dsp_version.split())
            # self.dsp_version = self.dsp_version.split(",")[-1]
            match = re.findall("(CRANE_.*? ,.*?[0-9][0-9]:[0-9][0-9]:[0-9][0-9])",self.dsp_version)
            if match:
                dsp_version = match[0]
            else:
                dsp_version =  str(time.asctime())
            commit_info = "update dsp dailybuild %s"%dsp_version
            self.log.info("-m %s"%str(commit_info))
            self.git.commit("-m %s"%str(commit_info))
            self.log.info("git commit done")
            self.log.info("git push...")
            self.git.push("ssh://binwu@source.asrmicro.com:29418/crane/crane-dev","HEAD:refs/heads/master")
            self.log.info("git push done")
            return True
        except Exception,e:
            self.log.error(e)
            self.log.error("git push error")
            return None

    def check_dsp_rf(self):
        dsp_release_bin_l = []
        release_dir_list = [os.path.join(self.cfg.dsp_release_bin,_dir) for _dir in os.listdir(self.cfg.dsp_release_bin)\
                                if os.path.isdir(os.path.join(self.cfg.dsp_release_bin,_dir))]
        release_dir_list.sort(key=lambda fn:os.path.getmtime(fn))
        # self.log.debug(len(release_dir_list))
        # self.log.debug(release_dir_list[-30:])
        for release_dir in release_dir_list[-30:]:
            # self.log.debug(release_dir)
            for root, dirs, files in os.walk(release_dir, topdown=False):
                tgt_file = "crane_compress_a0.bin"
                if "crane_compress_a0.bin" in files:
                    rf = os.path.join(root,"PM813","rf.bin")
                    if os.path.exists(rf):
                        dsp_release_bin_l.append(os.path.join(root,tgt_file))
        dsp_release_bin_l.sort(key=lambda fn:os.path.getmtime(fn))
        # self.log.debug("\n".join(dsp_release_bin_l))
        dsp_release_bin = dsp_release_bin_l[-1]
        self.log.debug(dsp_release_bin)
        root_dir = os.path.dirname(dsp_release_bin)
        rf_release_bin = os.path.join(root_dir,"PM813","rf.bin")
        release_bin_l = [dsp_release_bin, rf_release_bin]
        local_bin_l = [self.cfg.local_dsp_bin,self.cfg.local_rf_bin]
        for release_bin,local_bin in zip(release_bin_l,local_bin_l):
            if os.path.exists(release_bin):
                if os.path.exists(local_bin):
                    os.remove(local_bin)
                shutil.copy2(release_bin,local_bin)





