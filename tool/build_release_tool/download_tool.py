#!usr/bin/env python

import git
import os
import shutil
import time
import re
from send_email import *
from util import *
from util import MyLogger

class DownloadToolController(object):
    def __init__(self):
        super(DownloadToolController, self).__init__()
        self.root_dir = os.getcwd()
        self.download_tool = None

        self.log = MyLogger(self.__class__.__name__)
        self.download_tool_dict = {}
        self.release_download_tool_name = None
        self.download_tool_release_zip_dir = ""
        self.zip_tool = zipTool()

        self.update()

    def update(self):
        json_file = os.path.join(self.root_dir,"json","download_tool.json")
        json_str = load_json(json_file)

        self.tmp = os.path.join(self.root_dir, json_str["tmp"])
        self.download_tool_dir = os.path.join(self.root_dir, json_str["download_tool_dir"])
        self.partition_config = os.path.join(self.root_dir, json_str["partition_config"])
        self.template_config = os.path.join(self.root_dir, json_str["template_config"])

        self.download_tool_release_dir = json_str["download_tool_release_dir"]
        self.download_tool_file_name = json_str["download_tool_file_name"]
        self.win_type = json_str["win_type"]



    def unzip_download_tool(self,zip_file,extract_dir=None):
        self.zip_tool.unpack_archive(os.path.join(self.download_tool_dir,zip_file),extract_dir)

    def update_download_tool(self):
        tools_list = [_file for _file in os.listdir(self.download_tool_release_dir) if
                      self.win_type in _file and "aboot-tools" in _file and _file.endswith(".exe")]
        tools_list.sort(key=lambda fn: os.path.getmtime(self.download_tool_release_dir + '\\' + fn))
        self.log.debug(tools_list)
        if not self.download_tool_file_name:
            self.download_tool_file_name = tools_list[-1]
        file_name = self.download_tool_file_name
        self.download_tool_release_zip_dir = os.path.join(self.download_tool_dir,
                                                          self.download_tool_file_name.replace(".exe",""))
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
        for _tool in self.download_tool:
            self.log.info(_tool)

    def prepare_download_tool(self,images,borad="crane_evb_z2"):
        """borad : crane_evb_z2, bird_phone, crane_evb_dual_sim"""
        self.log.debug("\n".join(images))
        self.log.debug("\n".join(self.download_tool))
        for download_tool_dir in self.download_tool:
            if not os.path.exists(download_tool_dir):
                self.log.warning("%s not exists" % download_tool_dir)
                continue
            dist_dir = os.path.join(download_tool_dir,"images")
            dist_bin_l = [os.path.join(dist_dir,os.path.basename(_file)) for _file in images]
            for _file in dist_bin_l:
                if os.path.exists(_file):
                    os.remove(_file)
            for src_bin,dist_bin in zip(images,dist_bin_l):
                if os.path.exists(src_bin):
                    if os.path.exists(dist_bin):
                        os.remove(dist_bin)
                    shutil.copy2(src_bin,dist_bin)
                else:
                    self.log.warning("%s not exists" % src_bin)
            if os.path.isdir(self.partition_config):
                for _file in os.listdir(self.partition_config):
                    shutil.copy2(os.path.join(self.partition_config,_file),
                                 os.path.join(download_tool_dir,"config","partition",_file))
            elif os.path.isfile(self.partition_config):
                shutil.copy2(self.partition_config,os.path.join(download_tool_dir,"config","partition",
                                                                os.path.basename(self.partition_config)))
            else:
                self.log.error("self.partition_config:%s error" % self.partition_config)

            if os.path.isdir(self.template_config):
                for _file in os.listdir(self.template_config):
                    shutil.copy2(os.path.join(self.template_config,_file),
                                 os.path.join(download_tool_dir,"config","template",_file))
            elif os.path.isfile(self.template_config):
                shutil.copy2(self.template_config,
                             os.path.join(download_tool_dir,"config","template",os.path.basename(self.template_config)))
            else:
                self.log.error("self.template_config:%s error" % self.template_config)

    def release_zip(self, dist_dir, project_type = "CRANE_A0_16MB", zip_name = None):
        assert os.path.exists(
            self.download_tool_release_zip_dir)," can not find download tool %s " % self.download_tool_release_zip_dir
        os.chdir(self.download_tool_release_zip_dir)
        if "crane_lwg" in dist_dir:
            project_type = "CRANEG_Z1_32+8MB"
        if zip_name:
            zip_file = zip_name
        else:
            zip_file = "ASR_CRANE_EVB_%s.zip" % project_type
        zip_file = os.path.join(dist_dir,zip_file)
        release_log = os.path.join(self.tmp,"release_log.txt")
        self.log.info("create zip %s" % zip_file)
        release_cmd = "arelease.exe -c . -g --erase-all -p ASR_CRANE_EVB -v %s %s > %s" % (
            project_type, zip_file, release_log)
        os.system(release_cmd)

    def release_download_tool(self,release_name,borad="crane_evb_z2",dist_dir=None):
        import time
        "borad : crane_evb_z2, bird_phone, crane_evb_dual_sim"
        date = time.strftime("%Y%m%d_%H%M%S")
        release_file_name = "%s_%s_DOWNLOAD_TOOL_%s" % (release_name.upper(),borad.upper(),date)
        release_dir = os.path.join(self.download_tool_dir,release_file_name)
        os.mkdir(release_dir) if not os.path.exists(release_dir) else None
        self.log.info(release_file_name)
        self.log.info(release_dir)
        for _tool in self.download_tool:
            dist_file = os.path.join(release_dir,os.path.basename(_tool))
            self.log.info(dist_file)
            if not os.path.exists(dist_file):
                shutil.copytree(_tool,dist_file)

        dist = os.path.join(dist_dir,release_file_name)
        self.zip_tool.make_archive_e(dist,"zip",release_dir)
        self.release_download_tool_name = dist + ".zip"
        self.download_tool_dict[borad] = self.release_download_tool_name
        self.log.info(self.download_tool_dict)
        return self.release_download_tool_name






