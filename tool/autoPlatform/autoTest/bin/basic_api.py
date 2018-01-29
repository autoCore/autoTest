#!/usr/bin/python

import os,sys
import datetime
import time
from config import *

class autoTest_object:
	def __init__(self):
		self.ID = None
		self.fileList = []
		self.axf_dir = ''
		self.build_result = 'Success'
		self.test_cmd_list = []
		self.test_timeout_list = [10]
#result: log file and the result of testing
		self.test_log_dir = ''
		self.t32_test_log_dir = ''
		self.test_result = []
		self.cmm_fn = ''
		self.module_name = ''
		pass
	def to_object(self, id, _module_name, axf_dir, test_cmd_list, test_timeout_list, _log_dir, _t32_log_dir, build_result = 'Success'):
		self.ID = id
		self.axf_dir = axf_dir
		self.build_result = build_result
		self.test_cmd_list = test_cmd_list[:]
		self.test_timeout_list = test_timeout_list[:]
		self.test_log_dir = _log_dir
		self.t32_test_log_dir = _t32_log_dir
		self.module_name = _module_name
	def set_cmm_fn(self, _file_name):
		self.cmm_fn = _file_name
	def set_test_result(self, _test_result):
		self.test_result = _test_result[:]

def find_text_between(_start,_end,_source_text):
	if _start in _source_text:
		target_text = _source_text.split(_start)[1]
	else:
		print _source_text,"don't include %s"%_start

	if _end in target_text:
		target_text = target_text.split(_end)[0]
	else:
		print _source_text,"don't include %s"%_end

	return target_text

def clear_result(project_name,test_module):
	now = datetime.datetime.today()
	date = now.strftime("%d_%h_%H-%M-%S")
	test_module_dir = './tool/tmp/%s_log_%s'%(test_module,date)
	os.mkdir(test_module_dir)
	os.system('chmod 777 ' + test_module_dir)
	os.system('cp ./tool/tmp/log %s -rf'%test_module_dir)
	find_name = ['report_all*','test_report*']
	for _name in find_name:
		cmd = 'find ./tool/tmp -maxdepth 1 -name %s -exec mv {} %s \;'%(_name,test_module_dir)
		os.system(cmd)
	cmd = 'find ./tool/tmp -maxdepth 1 -name ~* -exec cp {} %s \;'%(test_module_dir)
	os.system(cmd)
	axf_dir = './build/%s/img/%s'%(project_name,test_module)
	cmd = 'find %s -name *.axf -exec cp {} %s \;'%(axf_dir,test_module_dir)
	os.system(cmd)
	print 'output:'+test_module_dir
	print 'clear done'

def show_timing(deadline):
	timming = 0
	while timming < deadline:
		timming += 1
		sys.stdout.write("timing: %ds\r" %int(timming))
		sys.stdout.flush()
		time.sleep(1)
	return timming

def get_test_result(_autoTest_obj):
	test_log_dir = _autoTest_obj.test_log_dir
	test_cmd_list = _autoTest_obj.test_cmd_list
	print "get_test_result begin: log_DIR = ", test_log_dir

	result_list = []
	if os.path.exists(test_log_dir):
		pass
	else:
		print 'log_DIR:',test_log_dir,'does not exist'
		result_list.append('Cannot find result_log file')
		return result_list

	input_cmd_list = []
	input_cmd_count = 0
	output_log_count = 0

	with open(test_log_dir) as test_result_obj:
		for line_no,eachline in enumerate(test_result_obj):
			if 'ctest#' in eachline[:7]:
				input_cmd = eachline.split('#')[1].strip()
				if input_cmd in test_cmd_list:
					input_cmd_list.append(input_cmd)
					input_cmd_count += 1
				continue
			if "Unknown command" in eachline and input_cmd_count:
				output_log_count += 1
				res = eachline.split('-')[0]
				result_list.append(res.strip())
				continue
			if 'AUTOTEST@' in eachline and 'Result[' in eachline:
				output_log_count += 1
				if output_log_count == input_cmd_count:
					pass
				elif output_log_count < input_cmd_count:
					for i in range(input_cmd_count - output_log_count):
						result_list.append('No_result_log')
						output_log_count += 1
				ll = eachline.split('Result[')[1]
				res = ll.split(']')[0]
				if res == 'ERR':
					retcode = ll.split('RetCode')[-1].strip()
					res += retcode
				result_list.append(res)

	test_cmd_count = len(test_cmd_list)
	if output_log_count < test_cmd_count:
		for i in range(test_cmd_count - output_log_count):
			result_list.append('No_result_log')
	_autoTest_obj.set_test_result(result_list)
	print 'input cmd:',input_cmd_list
	print 'test cmd:',test_cmd_list
	print 'test result:',result_list
	print "get_test_result end\n\r"
	return result_list

