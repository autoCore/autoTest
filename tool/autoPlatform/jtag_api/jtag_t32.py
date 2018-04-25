#!/usr/bin/python

T32_OK = 0
EXIT_SUCCESS=0
EXIT_FAILURE=1

WIN_MESSAGEMODENONE       = 0x00
WIN_MESSAGEMODEINFO       = 0x01
WIN_MESSAGEMODEERROR      = 0x02
WIN_MESSAGEMODESTATE      = 0x04
WIN_MESSAGEMODEWARNINFO   = 0x08
WIN_MESSAGEMODEERRORINFO  = 0x10
WIN_MESSAGEMODETEMP       = 0x20
WIN_MESSAGEMODETEMPINFO   = 0x40

import platform
import sys, getopt, ctypes, array, atexit, signal, os
from ctypes import *
from signal import SIGINT
import time


T32_MEMORY_ACCESS_DATA=0
rw = array.array('i', list(range(4)))
rdbuffer = (c_uint * 2).from_buffer(rw)
wtbuffer = (c_uint * 2).from_buffer(rw)


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
			config[k] = v
	return config

def jtat_connect():
	abs_dir = os.path.dirname(os.path.abspath(__file__))
	conf = get_config()
	# auto-detect the correct library
	if (platform.system()=='Windows') or (platform.system()[0:6]=='CYGWIN') :
		if ctypes.sizeof(ctypes.c_voidp)==4:
			# WINDOWS 32bit
			t32api  = ctypes.cdll.t32api
		else:
			# WINDOWS 64bit
			t32api = ctypes.cdll.t32api64
	else :
	  if ctypes.sizeof(ctypes.c_voidp)==4:
		# Linux 32bit
		t32api = ctypes.CDLL(os.path.join(abs_dir,'t32api.so'))
		print ("Load 32bits so")
	  else:
		# Linux 64bit
		t32api = ctypes.CDLL(os.path.join(abs_dir,'t32api64.so'))

	t32api.T32_Config(b"NODE=",conf.get('t32_IP'))
	t32api.T32_Config(b"PORT=",conf.get('t32_PORT'))
	t32api.T32_Config(b"PACKLEN=",conf.get('t32_PACKLEN'))

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

def connect_jtag():
	print "\n\rDo jtag command\n\r"
	jtat_connect_cnt = 0
	while 1:
		t32api = jtat_connect()
		jtat_connect_cnt += 1
		if t32api:
			break
		if jtat_connect_cnt == 5:
			print "Pls check your jtag t32\n\r"
			sys.exit(1)
	print 'jtat_connect success!'
	print "jtat_connect_cnt: %d"%jtat_connect_cnt
	return t32api

def jtag_stop_it(t32api):
	error = t32api.T32_Stop()
	error = t32api.T32_Break()
	return 0

def jtat_disconnect(t32api):
	#t32api.T32_Cmd("system.up")
	#cmd = r'data.load.elf \\fileserver\public-share\sw_cv\tmp\aquila_fpga_pwm_test.axf'
	#t32api.T32_Cmd(cmd)
	#t32api.T32_Cmd(b"go")

	#'If a PRACTICE script is currently running, it is stopped. If an application is running in the ICE, it will not be
	#affected by this command. For stopping the target program use T32_Break()'
	error = t32api.T32_Stop()

	error = t32api.T32_Break()
	#_message = []
	#status = []
	#error = t32api.T32_GetMessage(_message, status)
	#print _message, status
	t32api.T32_Exit()
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

def do_t32rem(t32api, t32_cmd):
	jtat_disconnect(t32api)
	# cmd = cfg.t32_bin_dir + 't32rem'
	cmd = 't32rem'
	cmd = ' '.join([cmd, conf.get('jtag_config','t32_IP'), conf.get('jtag_config','t32_PORT'), conf.get('jtag_config','t32_PACKLEN'), ' "%s"'%t32_cmd])
	print 'cmd: ', cmd
	if 0 != os.system(cmd):
		print "execute cmd error, cmd is :", cmd
	t32api = jtat_connect()

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

def send_commands(file, t32api, verbose):
	line = create_string_buffer(800)
	for line in file:
		line=line.rstrip()
		if '' == line or ';' == line[0]:
			continue
		if (verbose=='1'):
			print 'cmd: ', (line)

		if 1 :#and ('jtag_chain.cmm' not in line):
			if 'do ' == line[0:3] or 'Do ' == line[0:3] or 'DO ' == line[0:3]:
				fname2 = line.replace('\\\\','\\\\\\')
				do_t32rem(t32api, fname2)
			else:
				if line != '':
					jtag_cmd(t32api, line)


def read_reg_bit(reg_addr):
	t32api = jtat_connect()
	retval = t32api.T32_ReadMemory(reg_addr, T32_MEMORY_ACCESS_DATA, rdbuffer, 4)
	jtat_disconnect(t32api)
	if(0 == retval):
       		return rdbuffer[0]
	else:
       		print ('trace32 read address:0x%s error....' %(format(reg_addr,'0x')))

def write_reg_bit(reg_addr, val):
       wtbuffer[0] = val
       t32api = jtat_connect()
       retval = t32api.T32_WriteMemory(reg_addr, T32_MEMORY_ACCESS_DATA,wtbuffer, 4)
       jtat_disconnect(t32api)
       if(retval != 0):
                print ('trace32 write address:0x%s error....' %(format(reg_addr,'0x')))


'''
;configure u-boot through serial terminal
TERM.METHOD COM COM1 115200. 8 NONE 1STOP NONE
TERM.view
TERM.Out 10. ;send a single line feed
TERM.Out "setenv bootcmd bootm 0xfe000000 0xfe800000 0xffe00000" 10.
TERM.Out "setenv bootargs root=/dev/ram console=ttyS0,115200" 10.
TERM.Out "saveenv" 10.
'''
