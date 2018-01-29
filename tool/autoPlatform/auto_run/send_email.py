#!/usr/bin/env python
#coding:utf-8
import sys
import smtplib
import traceback
from email.mime.text import MIMEText
from email.header import Header
from email.utils import formataddr
from module_owner import *

def send_mail(to_addr,subjct = "aquilac_fpga autobuild failed",message_text = "	Your module build fail,please check!"):
	ret = 0
	from_addr = "asr_autotest@163.com"
	Cc_list = ["zhenbozhan@asrmicro.com"]
	Cc_str = ','.join(Cc_list)

	try:
		message_text = "Hi %s, \n"%to_addr.split("@")[0] + message_text
		msg = MIMEText(message_text,'plain','utf-8')
		msg['From'] = formataddr([from_addr.split("@")[0],from_addr])
		msg['To'] = to_addr
		msg['Cc'] = Cc_str
		msg['Subject'] = subjct
		server = smtplib.SMTP("smtp.163.com", 25)
		# server.set_debuglevel(1)
		server.login(from_addr,"aabbcc123")

		server.sendmail(from_addr,Cc_list + to_addr.split(","),msg.as_string())
		server.quit()
	except Exception,e:
		traceback.print_exc()
		ret = 1
	return ret

if __name__ == '__main__':
	if len(sys.argv) < 3:
		print "please input address or module_name and massage"
		exit(1)
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
	if address:
		ret = send_mail(address,subjct = "aquilac_fpga %s autobuild failed"%module_name,message_text = msg)
	else:
		print module_name,"not in owner_list"
		exit(1)

	if ret:
		print("%s send_mail %s failed"%(address,module_name))
		exit(1)
	else:
		exit(0)
