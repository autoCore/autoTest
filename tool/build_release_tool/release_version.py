#!usr/bin/env python

import sys,os,datetime,copy,time,re
import multiprocessing as mp
import shutil
import fileinput
import traceback
import subprocess
import git
from util import *
from git_push_cp import *
from release_zip import *
from send_email import *
from ftp import ftp_upload_file
from TriggerTest import trigger_test

reload(sys)
sys.setdefaultencoding( "utf-8" )

email_subject = "CRANE PHONE: AUTO RELEASE %s"
email_msg = r"""
GUI VERSION: %s
CP VERSION: %s
DSP VERSION: %s

NORMAL VERSION(SINGLE and DUAL SIM):
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\%s\crane_evb_z2
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\%s\crane_evb_z2\download_tool

BIRD PHONE VERSION:
binary + debug object: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\%s\bird_phone
download tool: \\sh2-filer02\Data\FP_RLS\crane_dailybuild\%s\bird_phone\download_tool

"""

def send_release_email(version_file, cp_version, dsp_version):
    to_address = "GR-Modem-SV-Report@asrmicro.com,SW_QA@asrmicro.com,SW_Managers@asrmicro.com,SW_CV@asrmicro.com,crane_sw_mmi_group@asrmicro.com"
    version_fname = os.path.basename(version_file)
    subject = email_subject%version_fname.upper()
    _match = re.findall("crane_git_r[0-9]+",version_fname)
    assert _match,"file name can not match"
    version = _match[0]
    # msg = email_msg%((version.upper(),cp_version,dsp_version,str(time.asctime()))+(version_fname,)*6)
    msg = email_msg%((version.upper(), cp_version, dsp_version)+(version_fname,)*4)
    logger.debug(subject)
    logger.debug(msg)
    send_email_tool(to_address,subject,msg)


def release_cus():
    version_file = get_release_version(os.path.dirname(cfg.cur_crane_cus),cfg.release_dist_dir, "crane_release")
    dist = os.path.join(cfg.release_dist_dir,os.path.basename(version_file))
    try:
        board = "crane_evb_z2"
        sdk_tool_abs_path = os.listdir(os.path.join(dist,"download_tool"))
        if sdk_tool_abs_path:
            sdk_tool_abs_path = os.path.join(dist,"download_tool",sdk_tool_abs_path[0])
        else:
            sdk_tool_abs_path = None
        mdb_txt_file_dir = os.path.join(dist,board)
        logger.info(mdb_txt_file_dir)
        for _file in os.listdir(mdb_txt_file_dir):
            if "MDB.TXT" in _file.upper():
                mdb_txt_file_abs_path = os.path.join(mdb_txt_file_dir,_file)
                break
        else:
            mdb_txt_file_abs_path = None
        logger.info(sdk_tool_abs_path,mdb_txt_file_abs_path,"evb_customer")
        trigger_test(sdk_tool_abs_path,mdb_txt_file_abs_path,"evb_customer")
    except Exception,e:
        logger.info(e)


def get_release_version(root_dir,dist_dir,target = "crane_git_r"):
    dailybuild_list = [_file for _file in os.listdir(root_dir) if _file.startswith(target)]
    dailybuild_list.sort(key=lambda fn:os.path.getmtime(os.path.join(root_dir,fn)))
    for file_name in dailybuild_list[::-1]:
        logger.debug(file_name)
        dist = os.path.join(dist_dir,file_name)
        if os.path.exists(dist):
            logger.debug(dist)
            return os.path.join(root_dir,file_name)
    else:
        return None

def release_version():
    version_file = get_release_version(os.path.dirname(cfg.cur_crane),cfg.dist_dir)
    if not version_file:
        return
    file_name = os.path.basename(version_file)
    logger.info(version_file)
    cp_version_file = os.path.join(version_file,"version_info", "cp_version.txt")
    with open(cp_version_file) as obj:
        cp_version = obj.read()
    dsp_version_file = os.path.join(version_file,"version_info", "dsp_version.txt")
    with open(dsp_version_file) as obj:
        dsp_version_file = obj.read()
    cp_sdk_cls.update_download_tool()
    for board in cfg.BOARD_LIST:
        root_dir = os.path.join(version_file, board, "cp_images")
        images = [os.path.join(root_dir, _file) for _file in os.listdir(root_dir)]
        cp_sdk_cls.prepare_download_tool(images,board)
        version_fname = os.path.basename(version_file)
        _match = re.findall("crane_git_r[0-9]+",version_fname)
        assert _match,"file name can not match"
        version = _match[0]
        _match = re.findall("MINIGUI_SDK_[0-9]+",cp_version)
        assert _match,"cp_version can not match"
        cp_version_sdk = _match[0]

        dist_dir = os.path.join(cfg.dist_dir, file_name, board, "download_tool")
        cp_sdk_cls.release_download_tool(cp_version_sdk, version, board, dist_dir)

    input("done......")
    # send_release_email(file_name, cp_version, dsp_version_file)

    try:
        board = "crane_evb_z2"
        sdk_tool_abs_path = cp_sdk_cls.download_tool_dict.get(board)
        mdb_txt_file_dir = os.path.join(cfg.dist_dir,os.path.basename(version_file),board)
        for _file in os.listdir(mdb_txt_file_dir):
            if "MDB.TXT" in _file.upper():
                mdb_txt_file_abs_path = os.path.join(mdb_txt_file_dir,_file)
                break
        else:
            mdb_txt_file_abs_path = None
        logger.info(sdk_tool_abs_path,mdb_txt_file_abs_path)
        # trigger_test(sdk_tool_abs_path,mdb_txt_file_abs_path)
    except Exception,e:
        logger.info(e)
    time.sleep(1)

if __name__ == "__main__":
    cfg = config()
    cfg.update('config.ini')
    logger = myLogger("build_release")
    logger.enablePrint()

    cp_sdk_cls = gitPushCpDailyBuild(cfg,logger)

    release_version()
    # version_file = get_release_version(os.path.dirname(cfg.cur_crane),cfg.dist_dir)
    # logger.info(version_file)
    # version_file = get_release_version(os.path.dirname(cfg.cur_crane_cus),cfg.release_dist_dir, "crane_release")
    # logger.info(version_file)













