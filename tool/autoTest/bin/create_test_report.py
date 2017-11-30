#!/usr/bin/python
import re
from basic_api import *
from report import *
from report_excel import *

#*******************#
cmd_cnt = 1
log_dir = './tool/tmp/log'
#*******************#

def Find_all_files(dirr,target_file = '.log'):
		if os.path.isdir(dirr):
			pass
		else:
			print "<Find_File>:Directory %s is not exist!\n\r"%dirr
			return 0

		if target_file:
			fileList =[os.path.join(dirr,s) for s in os.listdir(dirr) if os.path.isfile(os.path.join(dirr,s)) and target_file in s]
		else:
			fileList =[os.path.join(dirr,s) for s in os.listdir(dirr) if os.path.isdir(os.path.join(dirr,s))]

		return fileList

class test_result_object:
	def _init_(self):
		self.ID = None
		self.module_name = ''
		self.log_file = ''
		self.test_cmd_list = []
		self.test_result = []
		self.build_result = ''
	def fill_object(self,id,log_file,module_name,test_cmd_list,test_result_list):
		self.ID = id
		self.log_file = log_file
		self.module_name = module_name
		self.test_cmd_list = test_cmd_list[:]
		self.test_result = test_result_list[:]

def get_log_test_result(log_file):
	if os.path.exists(log_file):
		pass
	else:
		print 'log_file:',log_file,'is not exist'
		return 0
	input_cmd_list = []
	input_cmd_count = 0
	first_input_flag = 0
	output_log_count = 0
	result_list = []

#	module_name = os.path.basename(log_file).split('evb_')[1]
#	module_name = module_name.split('_test')[0]
	module_name = re.sub('[0-9]+_|_case.?|_test|aquilac_evb_','',os.path.basename(log_file).split(r'.log')[0])
	log_file_ID = os.path.basename(log_file).split('_')[0]
	obj = test_result_object()
	with open(log_file) as log_file_obj:
		for eachline in log_file_obj:
			if 'ctest#' in eachline[:7]:
				if 'ctest#' == eachline.strip():
					continue
				if 'ctest# ls' in eachline[:7]:
					continue
				if input_cmd_count == cmd_cnt:
					continue
				input_cmd = eachline.split('#')[1].strip()

				if first_input_flag:
					if input_cmd:
						input_cmd_list.append(input_cmd)
					input_cmd_count += 1
				else:
					first_input_flag = 1
					continue
			if 'AUTOTEST@' in eachline and 'Result[' in eachline:
				output_log_count += 1
				if output_log_count == input_cmd_count:
					pass
				elif output_log_count < input_cmd_count:
					for i in range(input_cmd_count - output_log_count):
						result_list.append('No_result_logs')
						output_log_count += 1
				ll = eachline.split('Result[')[1]
				ll = ll.split(']')[0]
				if 'ERR' == ll:
					ll = ll + eachline.split('RetCode')[-1]
				result_list.append(ll.strip())
		if output_log_count < cmd_cnt:
			for i in range(cmd_cnt - output_log_count):
				result_list.append('No_result_logs')
		if len(input_cmd_list) < cmd_cnt:
			for i in range(cmd_cnt - len(input_cmd_list)):
				input_cmd_list.append('No_input_cmd')
		obj.fill_object(log_file_ID,log_file,module_name,input_cmd_list,result_list)
	return obj

test_result_obj_list = []
def get_test_result_obj(files_list):
	for log_dir in files_list:
		obj = get_log_test_result(log_dir)
		if obj:
			test_result_obj_list.append(obj)
	return 1
def sort_files(files_list):
	file_d = {}
	new_files_list = []
	while files_list:
		file = files_list.pop()
		key = int(os.path.basename(file).split('_')[0])
		file_d[key] = file
	keys_list = file_d.keys()
	keys_list.sort()
	for key in keys_list:
		new_files_list.append(file_d[key])
	return new_files_list

def do_create_test_report():
	files_list = []
	if os.path.isdir('./tool/tmp/log'):
		pass
	else:
		print "log_DIR don't exist!"
		return 0
	files_list = Find_all_files(log_dir)
	files_list = sort_files(files_list)
	print 'find %d files'%len(files_list)
	if get_test_result_obj(files_list):
		pass
	else:
		return 0
	report_result(test_result_obj_list,'./tool/tmp/test_report.pdf')
	report_excel(test_result_obj_list,'./tool/tmp/test_report.xls')
	clear_result('aquilac_evb','test_result')
	return 1

if __name__ == '__main__':

	if do_create_test_report():
		print 'create done'
	else:
		exit(0)
	print 'End'


