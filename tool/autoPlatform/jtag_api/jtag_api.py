#!/usr/bin/python

import platform,os,sys,time,shutil
from ctypes import *
import ctypes

def get_config():
	import ConfigParser
	abs_dir = os.path.dirname(os.path.abspath(__file__))
	parent_dir = os.path.dirname(abs_dir)
	conf = ConfigParser.ConfigParser()
	cfgfile = os.path.join(parent_dir,'autoPlatform.cfg')
	assert os.path.exists(cfgfile),cfgfile+' no exists!'
	conf.read(cfgfile)
	config = {}
	for sec in conf.sections():
		for k,v in conf.items(sec):
			config[k.lower()] = v
	if (platform.system()=='Windows') or (platform.system()[0:6]=='CYGWIN'):
		if ctypes.sizeof(ctypes.c_voidp)==4:
			# WINDOWS 32bit
			if "T32" == config["jtag_type"]:
				config['api_obj'] = os.path.join(abs_dir,"t32api.dll")
			else:
				config['api_obj'] = os.path.join(abs_dir,"CVDAPI.dll")
				# print "CVD no 32bit version! Pls check config file"
				# sys.exit(1)
		else:
			# WINDOWS 64bit
			if "T32" == config["jtag_type"]:
				config['api_obj'] = os.path.join(abs_dir,"t32api.dll")
			else:
				config['api_obj'] = os.path.join(abs_dir,"CVDAPI.dll")
	else :
		if ctypes.sizeof(ctypes.c_voidp)==4:
			# Linux 32bit
			if "T32" == config["jtag_type"]:
				config['api_obj'] = os.path.join(abs_dir,"t32api.so")
			else:
				print "CVD no linux version! Pls check config file"
				sys.exit(1)
		else:
			# Linux 64bit
			if "T32" == config["jtag_type"]:
				config['api_obj'] = os.path.join(abs_dir,"t32api64.so")
			else:
				print "CVD no linux version! Pls check config file"
				sys.exit(1)
	return config

def jtat_connect():
	conf = get_config()
	if "T32" == conf["jtag_type"]:
		t32api = ctypes.CDLL(conf['api_obj'])
		t32api.T32_Config(b"NODE=",conf.get('jtag_ip'))
		t32api.T32_Config(b"PORT=",conf.get('jtag_port'))
		t32api.T32_Config(b"PACKLEN=",conf.get('jtag_packlen'))

		if not t32api.T32_Init():
			print "T32_Init() return err\n\r"
			return False
		if not t32api.T32_Attach(1):
			print "attach return err"
			return False

		if not t32api.T32_Ping():
			print "please check the connection\n\r"
			return False

		return t32api
	else:
		cvdapi = ctypes.CDLL(conf['api_obj'])
		if not cvdapi.CVD_Init():
			print "CVD_Init() return err\n\r"
			cvdapi.CVD_Quit()
			return False

		if not cvdapi.CVD_Connect(8888,conf.get('jtag_ip')):
			print "CVD_Connect() return err\n\r"
			cvdapi.CVD_Quit()
			return False

		if not cvdapi.CVD_Config(20000):
			print "CVD_Config() return err\n\r"
			cvdapi.CVD_Quit()
			return False
		return cvdapi

def connect_jtag():
	print "\n\rDo jtag command..."
	jtat_connect_cnt = 0
	while 1:
		jtagapi = jtat_connect()
		jtat_connect_cnt += 1
		if jtagapi:
			break
		if jtat_connect_cnt == 5:
			print "Pls check your jtag\n\r"
			sys.exit(1)
	print 'jtat_connect success!'
	return jtagapi

def cvd_do_cmm(cvdapi,cmm_file,timeout = 10):
	cvdapi = connect_jtag()
	msgtype=c_ulonglong(0)
	local_cmm = os.path.join(os.getcwd(),"main.cmm")
	shutil.copyfile(cmm_file,local_cmm)
	cmd = "do %s"%local_cmm
	res = 0
	if not cvdapi.CVD_Cmd(cmd):
		print cmd,"fail"
		res = -1
	else:
		for timming in xrange(int(timeout)):
			cvdapi.CVD_GetPracticeState(byref(msgtype))
			if msgtype.value == 0:
				break
			sys.stdout.write("timing: %ds\r" %int(timming))
			sys.stdout.flush()
			time.sleep(1)
		else:
			print "Do cmm timeout!"
			res = -1
	os.remove(local_cmm)
	return res
