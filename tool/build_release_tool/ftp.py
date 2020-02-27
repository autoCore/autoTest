#!/usr/bin/python
# -*- coding: utf-8 -*-
 
from ftplib import FTP
from ftplib import error_perm
import os
import time
import socket
# from concurrent.futures import ThreadPoolExecutor


def ftpconnect(host, port, username, password):
    ftp = FTP()
    # ftp.set_debuglevel(2)
    ftp.encoding = 'utf-8'
    ftp.set_pasv(0)
    try:
        ftp.connect(host, port)
        ftp.login(username, password)
        print(ftp.getwelcome())
    except(socket.error, socket.gaierror):
        print("ERROR: cannot connect [{}:{}]" .format(host, port))
        return None
    except error_perm:
        print("ERROR: user Authentication failed ")
        return None
    return ftp
 
 
def is_ftp_file(ftp_conn, ftp_path):
    try:
        if ftp_path in ftp_conn.nlst(os.path.dirname(ftp_path)):
            return True
        else:
            return False
    except error_perm:
        return False
 
 
def downloadfile(ftp, remotepath, localpath):
    """
    :param ftp:
    :param remotepath:
    :param localpath:
    :return:
    """
    bufsize = 1024  # 设置缓冲块大小
    fp = open(localpath, 'wb')  # 以写模式在本地打开文件
 
    res = ftp.retrbinary(
        'RETR ' + remotepath,
        fp.write,
        bufsize)  # 接收服务器上文件并写入本地文件
    if res.find('226') != -1:
        print('download file complete', localpath)
    ftp.set_debuglevel(0)  # 关闭调试
    fp.close()  # 关闭文件
 
 
def uploadfile(ftp, remotepath, localpath):
    """
    :param ftp:
    :param remotepath:
    :param localpath:
    :return:
    """
    bufsize = 1024
    fp = open(localpath, 'rb')
    res = ftp.storbinary('STOR ' + remotepath, fp, bufsize)
    if res.find('226') != -1:
        print('upload file complete', remotepath)
    ftp.set_debuglevel(0)
    fp.close()

# REMOTE_FTP_IP = '10.1.24.15'
# REMOTE_FTP_PORT = 21
# REMOTE_FTP_USER = 'binwu'
# REMOTE_FTP_PASSWD = 'AAbbcc123'

REMOTE_FTP_IP = '10.38.152.26'
REMOTE_FTP_PORT = 21
REMOTE_FTP_USER = 'common'
REMOTE_FTP_PASSWD = 'common'

def ftp_upload_file(src_dir, dist):
    ftp = ftpconnect(REMOTE_FTP_IP, REMOTE_FTP_PORT, REMOTE_FTP_USER, REMOTE_FTP_PASSWD)
    ftp.voidcmd('TYPE I')
    root_dir = "/MINIGUI_MMILIBS"
    ftp.cwd(root_dir)
    print "FTP dir:", ftp.pwd()
    ftp.dir()
    try:
        ftp.mkd(dist)
    except:
        pass
    ftp.cwd(dist)
    print "FTP dir:", ftp.pwd()

    if os.path.isdir(src_dir):
        for _file in os.listdir(src_dir):
            fname = os.path.join(src_dir, _file) 
            print fname
            uploadfile(ftp, _file, fname)
    elif os.path.isfile(src_dir):
        uploadfile(ftp, os.path.basename(src_dir), src_dir)
    ftp.dir()
    ftp.quit()



if __name__ == "__main__":
    lib_src = r"F:\crane_dailybuild\crane_git_r307_20191217_060339\crane_evb_dual_sim\rel_lib"
    ftp_upload_file(lib_src,"crane_git_r307_20191217_060339")
