#!/usr/bin/env python
#coding:utf-8
import sys,os
import smtplib
import traceback
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText
from email.MIMEBase import MIMEBase
# from email.mime.text import MIMEText
from email.header import Header
from email.utils import formataddr
from module_owner import *

def send_mail(to_addr,subjct = "aquilac_evb autobuild",message_text = "	Your module build fail,please check!",att_file = ""):
	ret = 0
	from_addr = "srv-sw_cv_test@asrmicro.com"
	password = "AAbbcc123"
	MAIL_SERVER = '10.1.24.123' #"smtp.163.com"
	MAIL_PORT = 25

	Cc_list = ["zhenbozhan@asrmicro.com"]
	Cc_str = ','.join(Cc_list)

	try:
		msg = MIMEMultipart()
		message_text = "Hi %s, \n"%to_addr.split("@")[0] + message_text
		msg.attach(MIMEText(message_text,'plain','utf-8'))
		msg['From'] = formataddr([from_addr.split("@")[0],from_addr])
		msg['To'] = to_addr
		msg['Cc'] = Cc_str
		msg['Subject'] = subjct

		if att_file:
			with open(att_file, 'rb') as f:
				mime = MIMEBase('txt', 'log', filename = os.path.basename(att_file))
				mime.add_header('Content-Disposition', 'attachment', filename = os.path.basename(att_file))
				mime.add_header('Content-ID', '<0>')
				mime.add_header('X-Attachment-Id', '0')
				mime.set_payload(f.read())
				msg.attach(mime)
		server = smtplib.SMTP(MAIL_SERVER, MAIL_PORT)
		# server.set_debuglevel(1)
		server.starttls()
		server.login(from_addr,password)

		server.sendmail(from_addr,Cc_list + to_addr.split(","),msg.as_string())
		server.quit()
	except Exception,e:
		traceback.print_exc()
		ret = 1
	return ret

if __name__ == '__main__':
	if len(sys.argv) < 3:
		print "please input address or module_name and massage"
		sys.exit(1)
	_str = sys.argv[1]
	msg = sys.argv[2]
	if 'fixed' in msg:
		msg = "	Your module has fixed.Thank you!"
	else:
		msg = "	Your module build fail.Please check!"
	if "@" in _str:
		address = _str
		module_name = "module"
	else:
		module_name = _str
		address = get_owner(module_name)
	# address = "binwu@asrmicro.com"
	ret = 0
	log_dir = './tool/tmp/build_log/'
	log_file = [os.path.join(log_dir,file) for file in os.listdir(log_dir) if module_name in file]
	log_file = log_file[0] if log_file else None
	if address:
		ret = send_mail(address,subjct = "aquilac_evb %s autobuild result"%module_name,message_text = msg,att_file = log_file)
	else:
		print module_name,"not in owner_list"
		sys.exit(1)

	if ret:
		print("%s send_mail %s failed"%(address,module_name))
		sys.exit(1)
	else:
		sys.exit(0)
