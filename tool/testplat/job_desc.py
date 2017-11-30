#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import sys
import os
import json
import pickle
import rpyc

from rpyc.utils.server import ThreadedServer
from Send_job import Send_job

'''
SINGLE_TEST:aquilac_fpga_mimir_adv9_MIMIR_test.axf:AUTOTEST@mimir_test:30:ready/ongoing/done:log_name
'''
'''
A fileserver class
This stores data for all the clients connected
The self.callbacks private variable is used to store the check object of each client.
The self.call private variable to call an object which writes the file for the client which initated file transfer.
'''
class FileServer:
	#constructor method
	def __init__(self):
		self.callbacks = []
		self.buffer = []
		self.filelist =[]
		self.dlist=[]
		self.fname = ''

	#Append the check function call to the list of clients
	def setCallback(self, check):
		self.callbacks = self.callbacks + [check]

	#Send the requested full_dir_file_name to everyone's check method
	def seek(self, ip,full_dir_file_name):
		for fn in self.callbacks:
			try:
				ret = fn(full_dir_file_name,ip)
				if (ret != None):
					return ret
			except:
				pass

	#method that calls the function to write to the particular client using the buffer self.call
	def save_file(self, ip, full_dir_file_name):
		print ("save_file: begin %s, %s\n\r", ip, full_dir_file_name)
		bytes = self.seek(ip, full_dir_file_name)
		self.fname = os.path.basename(full_dir_file_name)
		foo=open(self.fname,"wb")
		foo.write(bytes)
		foo.close()
		print ("save_file:end\n\r")

	def pass_cmd(self, cmd_name, timeout_s):
#		print ("pass_cmd:%s, %s\n\r",cmd_name, timeout_s)
		line = 'SINGLE_TEST:' + self.fname + ':' + 'AUTOTEST@' + cmd_name + ':' + timeout_s + ':' + 'ready' + ':log_name'
		fname = 'single_' + self.fname + '.cmd'
		foo = open(fname, "wb")
		foo.write(line)
		foo.close()

def wait_rpyc_msg(server_addr):
		t = rpyc.utils.server.OneShotServer(Service, hostname = server_addr, port = 18861)
		t.start()

#Class to store all external function calls
class Service(rpyc.Service):
	f = FileServer()

	def __init__(self, port):
		self.newlist = []

	def on_connect(self):
		print ("on_connect\n\r")
		pass

	def on_disconnect(self):
		t.close()
		print "Someone left!"

	def exposed_setCallback(self,check):
		self.f.setCallback(check)

	def exposed_save_file(self, uid, full_dir_file_name):
		self.f.save_file(uid, full_dir_file_name)

	def exposed_pass_cmd(self, cmd_name, timeout_s):
		self.f.pass_cmd(cmd_name, timeout_s)

	def exposed_retlist(self):
		return self.newlist

	def exposed_newfiles_add(self,ava):
		self.newlist.append(ava)

	def exposed_files_remove(self,ava):
		self.newlist.remove(ava)

	def sendandwrite(byte1,full_dir_file_name):
		print ("sendandwrite, write end\n\r")

class Job_desc(object):
	hardware_env = 'fpga'
	download_method = 'uart'
	server_addr = 'localhost'
	module_name = 'default_module_name'

	case_name = 'default'
	case_cmd = 'default'
	case_timeout = '30s'
	case_desc = 'default'

	file_binary_name = 'remote'

	def __init__(self):
		pass
	def set_global_env(self, hardware_env, download_method, server_addr):
		self.hardware_env = hardware_env
		self.download_method = download_method
		self.server_addr = server_addr

	def set_info(self, module_name, case_name, case_cmd, case_timeout, case_desc, file_binary_name):
		self.module_name = module_name
		self.case_name = case_name
		self.case_cmd = case_cmd
		self.case_timeout = case_timeout
		self.case_desc = case_desc
		self.file_binary_name = file_binary_name

	def send_job(self, job_object, queue_name):
		job_str = pickle.dumps(job_object)
#		job = pickle.loads(job_str)
#		job.dump()
		s = Send_job(self.server_addr, queue_name)
		s.send_msg(job_str)
		s.send_binary(self.file_binary_name)
		s.send_end()
		pass

	def receive_binary(self):
		wait_rpyc_msg(self.server_addr)
		pass

	def dump(self):
		print("hardware_env:%s, download_method:%s, server_addr:%s"%(self.hardware_env,self.download_method,self.server_addr))
		print("module_name:%s, case_name:%s, case_cmd:%s, case_timeout:%s, case_desc:%s, filename:%s" %(self.module_name,self.case_name,self.case_cmd,self.case_timeout,self.case_desc, self.file_binary_name))
