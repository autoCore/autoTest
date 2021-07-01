#!/usr/bin/env python
#coding:utf-8
import sys
import os
import argparse
import smtplib
import traceback
from email.MIMEMultipart import MIMEMultipart
from email.mime.application import MIMEApplication
from email.MIMEText import MIMEText
from email.MIMEBase import MIMEBase
# from email.mime.text import MIMETextMIMETextMIMETextMIMEText
from email.header import Header
from email.utils import formataddr

class my_email:
    def __init__(self,MAIL_SERVER,MAIL_PORT):
        self._usr = None
        self._mail_server = MAIL_SERVER
        self._mail_port = MAIL_PORT
        self._server = None
        self._msg = MIMEMultipart()

    def addAtt(self,att_list):
        for att_file in att_list:
            if os.path.exists(att_file):
                att = MIMEApplication(open(att_file,'rb').read())
                att.add_header('Content-Disposition', 'attachment', filename = os.path.basename(att_file))
                self._msg.attach(att)

    def addMsg(self, subjct, msg):
        self._msg.attach(MIMEText(msg,'plain','utf-8'))
        self._msg['Subject'] = subjct

    def connect(self, usr, password):
        self._usr = usr
        self._server = smtplib.SMTP(self._mail_server, self._mail_port)
        # self._server.login(usr, password)

    def send_email(self,to_addr, cc_list):
        self._msg['From'] = formataddr([self._usr.split("@")[0],self._usr])
        self._msg['To'] = to_addr
        self._msg['Cc'] = ','.join(cc_list)
        self._server.sendmail(self._usr, cc_list + to_addr.split(","), self._msg.as_string())

def send_email_tool(to_address,subject,msg,att_file = None):
    from_addr = "srv-sw_cv_test@asrmicro.com"
    # from_addr = "binwu@asrmicro.com"
    password = "AAbbcc123"
    # MAIL_SERVER = '10.38.122.27' #external net
    MAIL_SERVER = '10.1.24.123'
    MAIL_PORT = 25

    cc_list = ["taojiang@asrmicro.com",'binwu@asrmicro.com']
    # cc_list = ['binwu@asrmicro.com']

    server = my_email(MAIL_SERVER, MAIL_PORT)
    server.addMsg(subject, msg)
    if att_file:
        att_list = att_file.split('@')
        server.addAtt(att_list)
    server.connect(from_addr, password)
    server.send_email(to_address,cc_list)


if __name__ == '__main__':
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument('address',help = 'Pls input address')
    arg_parser.add_argument('subject',help = 'Pls input subject')
    arg_parser.add_argument('msg',help = 'Pls input massage')
    arg_parser.add_argument('-f','--log_file',default = '', help = 'Pls input log file')
    argv = arg_parser.parse_args()

    from_addr = "srv-sw_cv_test@asrmicro.com"
    password = "AAbbcc123"
    MAIL_SERVER = '10.38.122.27' #external net
    # MAIL_SERVER = '10.1.24.123'
    MAIL_PORT = 25

    cc_list = ["zhenbozhan@asrmicro.com",'binwu@asrmicro.com']
    # cc_list = ['binwu@asrmicro.com']
    server = my_email(MAIL_SERVER, MAIL_PORT)
    server.addMsg(argv.subject, argv.msg)
    if argv.log_file:
        att_list = argv.log_file.split('@')
        server.addAtt(att_list)
    server.connect(from_addr, password)
    server.send_email(argv.address,cc_list)

