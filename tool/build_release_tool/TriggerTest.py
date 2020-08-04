#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os
import json
import requests
import shutil
import argparse
from datetime import datetime


def upload_version(sdk_tool_abs_path, mdb_txt_file_abs_path, kid_project_name):
    '''
        上传sdk工具(例: ASR3601_MINIGUI_20191213_SDK_DOWNLOAD_TOOL_20191213_142047.zip)
        上传mdb文件(例: Arbel_PMD2NONE_MDB.txt)
        sdk_tool_abs_path: sdk工具的绝对路径
        mdb_txt_file_abs_path: mdb文件的绝对路径
        return version路径
    '''
    if kid_project_name is None:
        version_dir = os.path.join(r'\\10.1.166.208\craneversion\crane-evb-ver', os.path.split(sdk_tool_abs_path)[1].rstrip('.zip'))
    elif kid_project_name == 'evb_dual_sim':
        version_dir = os.path.join(r'\\10.1.166.208\craneversion\crane-evb-dual-sim-ver', os.path.split(sdk_tool_abs_path)[1].rstrip('.zip'))
    elif kid_project_name == 'evb_customer':
        version_dir = os.path.join(r'\\10.1.166.208\craneversion\crane-evb-customer-branch', os.path.split(sdk_tool_abs_path)[1].rstrip('.zip'))
    elif kid_project_name == 'evb_customer_r1':
        version_dir = os.path.join(r'\\10.1.166.208\craneversion\crane-evb-customer-r1', os.path.split(sdk_tool_abs_path)[1].rstrip('.zip'))
    elif kid_project_name == 'craneg_evb':
        version_dir = os.path.join(r'\\10.1.166.208\craneversion\craneg-evb-ver', os.path.split(sdk_tool_abs_path)[1].rstrip('.zip'))
    elif kid_project_name == 'crane_evb_z2_fwp':
        version_dir = os.path.join(r'\\10.1.166.208\craneversion\crane_evb_z2_fwp', os.path.split(sdk_tool_abs_path)[1].rstrip('.zip'))
    elif kid_project_name == 'craneg_evb_release':
        version_dir = os.path.join(r'\\10.1.166.208\craneversion\craneg_evb_release', os.path.split(sdk_tool_abs_path)[1].rstrip('.zip'))
    os.mkdir(version_dir)
    shutil.copyfile(sdk_tool_abs_path, os.path.join(version_dir, os.path.split(sdk_tool_abs_path)[1]))
    shutil.copyfile(mdb_txt_file_abs_path, os.path.join(version_dir, os.path.split(mdb_txt_file_abs_path)[1]))
    return version_dir

def trigger(version_dir_name, kid_project_name):
    '''
        触发daily测试
    '''
    if kid_project_name:
        data = {'host_path':  '', 'kid_project': kid_project_name, 'project': 'crane', 'project_num': version_dir_name}
    else:
        data = {'host_path':  '', 'kid_project': '', 'project': 'crane', 'project_num': version_dir_name}
    response = requests.post('http://10.1.164.99:8005/api/auto_submit_job/', data=json.dumps(data))
    print(response) 

def check_param(sdk_tool_abs_path, mdb_txt_file_abs_path, kid_project_name):
    '''
        检测sdk工具和mdb文件是否存在以及文件格式
    '''
    if not os.path.isfile(sdk_tool_abs_path):
        raise Exception('{0} not exist'.format(sdk_tool_abs_path))
    if not os.path.isfile(mdb_txt_file_abs_path):
        raise Exception('{0} not exist'.format(mdb_txt_file_abs_path))
    if not sdk_tool_abs_path.endswith('.zip'):
        raise Exception('{0} not a zip file'.format(sdk_tool_abs_path))
    if not mdb_txt_file_abs_path.endswith('MDB.txt'):
        raise Exception('{0} not MDB txt file'.format(mdb_txt_file_abs_path))
    if kid_project_name is not None and kid_project_name not in ['evb_dual_sim', 'evb_customer', 'craneg_evb', 'evb_customer_r1', 'crane_evb_z2_fwp', 'craneg_evb_release']:
        raise Exception('{0} not support'.format(kid_project_name))

def trigger_test(sdk_tool_abs_path, mdb_txt_file_abs_path, project_name = None):
    check_param(sdk_tool_abs_path, mdb_txt_file_abs_path, project_name)
    version_dir = upload_version(sdk_tool_abs_path, mdb_txt_file_abs_path, project_name)
    trigger(version_dir, project_name)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(prog='crane daily trigger', 
                                    usage='python TriggerTest.py -s sdk_tool_abs_path -m mdb_txt_file_abs_path -p kid_project_name',
                                    description='ASRCAT runner tool')
    parser.add_argument('-s', '--sdk_tool_abs_path', type=str, required=True)
    parser.add_argument('-m', '--mdb_txt_file_abs_path', type=str, required=True)
    parser.add_argument('-p', '--kid_project_name', type=str, required=False, default=None)
    args = parser.parse_args()
    check_param(args.sdk_tool_abs_path, args.mdb_txt_file_abs_path, args.kid_project_name)
    version_dir = upload_version(args.sdk_tool_abs_path, args.mdb_txt_file_abs_path, args.kid_project_name)
    trigger(version_dir, args.kid_project_name)