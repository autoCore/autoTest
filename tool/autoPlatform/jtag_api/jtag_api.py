#!/usr/bin/python

import platform,os,sys,time,shutil
from ctypes import *
import ctypes


T32_OK = 0
EXIT_SUCCESS=0
EXIT_FAILURE=1


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

		if t32api.T32_Init():
			print "T32_Init() return err\n\r"
			return False
		if t32api.T32_Attach(1):
			print "attach return err"
			return False

		if t32api.T32_Ping():
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

def jtag_stop_it(t32api):
	error = t32api.T32_Stop()
	error = t32api.T32_Break()
	return 0

def jtag_cmd(t32api, line):
	msgstring=create_string_buffer(50)
	msgtype=c_ulonglong(0)

	t32api.T32_Stop()
	time.sleep(0.2)
	if ';' in line:
		M = line.split(';')
		line = M[0]

	error = t32api.T32_Cmd(line.encode('latin-1'))
	if t32api.T32_Cmd(line.encode('latin-1'))== T32_OK:
		if 0:
			if t32api.T32_GetMessage(byref(msgstring), byref(msgtype))==T32_OK:
				if msgtype.value < (WIN_MESSAGEMODETEMPINFO << 1):
					if msgtype.value != WIN_MESSAGEMODENONE and not((len(msgstring.value) == 0) and (msgtype.value & (WIN_MESSAGEMODETEMPINFO | WIN_MESSAGEMODETEMP))):
						if msgtype.value & WIN_MESSAGEMODEINFO:
							print('info message:', msgstring.value)
						if msgtype.value & WIN_MESSAGEMODESTATE:
							print('status message:', msgstring.value)
						if msgtype.value & WIN_MESSAGEMODEWARNINFO:
							print('warning message:', msgstring.value)
						if (msgtype.value & WIN_MESSAGEMODEERRORINFO) or (msgtype.value & WIN_MESSAGEMODEERROR):
							print('error message:', msgstring.value)
						if (msgtype.value & WIN_MESSAGEMODETEMPINFO) or (msgtype.value & WIN_MESSAGEMODETEMP):
							print('miscellaneous message: %s' %msgstring.value)
					else:
						print('Successfully executed user command %s' %line)
				else:
					print('Failed to determine the type of the return message.')
	else:
		print('Failed to query return message.')

def do_t32command_do_cmm(t32api, fname):
	# s = 0.1
	# with open(fname, 'r') as file:
	# 	for line in file:
	# 		line=line.rstrip()
	# 		if 'wait' in line[:5]:
	# 			ll = line.split('wait')
	# 			ll = ll[1].lstrip().split('s')
	# 			s += float(ll[0])
	cmd = 'do ' + fname
	print 'cmd: ', cmd
	# print 'cmd: ', "END"
	jtag_cmd(t32api, "END")
	jtag_cmd(t32api, cmd)