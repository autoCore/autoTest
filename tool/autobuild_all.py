#!/usr/bin/env python
'build all the make\\x.mk modules, and find its autoTest command'
import os
import sys
import string
import re
import threading
import commands
import argparse
import fileinput

sys.path.append("./tool/autoTest/bin")
from config import *

silent_string = " >/dev/null 2>&1"
log_file_name = "./tool/tmp/~build.result"
auto_test_fn = "./tool/tmp/~autotest_list"
res_dir = './tool/tmp/'

'find and build all target module in the ctest\make'
counter = 0

'#define TEST_AUTO_CASE_DEFINE(module_name,cmd_string,timeout)'
'TEST_AUTO_CASE_DEFINE("example","example",TIMEOUT_DEFAULT);'
'AUTOTEST@module_name_xxxx OHTERS CMD STRING:30'
def make_test_cmd(cmd_string, timeout):
	'define excel all contents data and some methods'
	cmd_string = 'AUTOTEST@' + cmd_string + ':' + timeout
	return cmd_string

_str_array = []
def parse_autolist(parse_module_name):
	'parse auto test command'
	if os.path.getsize(auto_test_fn):
		pass
	else:
		print '%s is blank'%auto_test_fn
		return 0
	with open(auto_test_fn) as file_obj:
		find_str_array = [eachline for eachline in file_obj if parse_module_name in eachline.lower()]
	# print find_str_array

	if find_str_array:
		pass
	else:
		# print 'Module %s has no autoTest case '%parse_module_name
		return 0
# TEST_AUTO_CASE_DEFINE("dvc", "dvc_auto", TIMEOUT_DEFAULT);
	pattern = re.compile('TEST_AUTO_CASE_DEFINE.*?\((.*?)\)')
	for _str in find_str_array:
		search_str = re.search(pattern,_str).group(1) #find out in () and erase ", strip,split
		search_str = search_str.replace('"','').strip()
		_module_name,_cmd_string,_timeout = search_str.split(',')
		_module_name = re.sub(r'_test|_case.?','',_module_name).lower().strip()
		# print _str_lists,_module_name
		if _module_name == parse_module_name:#for example, "timer with wdt_timer two different module"
			_cmd_string = _cmd_string.strip()
			_timeout = _timeout.strip()
		# print _cmd_string,_timeout
			if 'TIMEOUT_DEFAULT' in _timeout:
				_timeout = _timeout.replace('TIMEOUT_DEFAULT',"30").replace(' ','').replace('(','').replace(')','')
			_str_array.append(make_test_cmd(_cmd_string, _timeout))

	return 1

def __get_blank(string,num_blank):
	num_blank = num_blank - len(string)
	if num_blank <= 0:
		num_blank = 8
	return num_blank


def build_module(project_name, axf_dir, _module_name,build_type = "make"):
	global mutex,file_log
	ret = 0
	line_string = ''
	counter = 0
	if build_type == "make":
		cmd = "make p=%s m=%s i=64 %s"%(project_name,_module_name,silent_string)
	elif build_type == "cmake":
		cmd = "./make.sh %s %s %s"%(project_name, _module_name, silent_string)
	#exceptions modules, Woooooo
	if 'aquila_evb' in project_name:
		mkall_list = ['v550','mimir','dp650','ddr_init']
		if _module_name in mkall_list:
			cmd = "./make/%s/mkall.sh %s %s"%(_module_name,project_name,silent_string)
	#end of exceptions
	(system_run_ret,_log) = commands.getstatusoutput(cmd) #if success ,return 0

	#after this, check the binary file
	m = FileFilt()
	if build_type == "make":
		counter = m.FindFile(dirr = axf_dir, find_file = '.axf') if not system_run_ret else None
	elif build_type == "cmake":
		counter = m.FindFile(dirr = axf_dir, find_file = _module_name) if not system_run_ret else None
		m.fileList = [_file for _file in m.fileList if '.elf' in _file]
		counter = len(m.fileList)
	if _module_name in ['tl4_core','sched','jpeg','camafbc','ddrtester','bhmkpwr']:
		counter = 1
	if any([system_run_ret,not counter]): #build fail
		line_string = ':'.join([_module_name,cmd,axf_dir])
		line_string += __get_blank(line_string,170)*' ' + ':' + '[Fail]'
		try:
			mutex.acquire()
			print "module: " + _module_name+ __get_blank(_module_name,20)*' ' + 'fail!'
			file_log.write(line_string + '\n')
			file_log.flush()
			# print line_string
		finally:
			mutex.release()
			ret = 1
	else:								# build success
		mutex.acquire()
		print "module: " + _module_name+ __get_blank(_module_name,20)*' ' + 'success!'
		mutex.release()
		for k in m.fileList:
			_module_name = re.sub(r'%s_|_test|_case.?'%project_name,'',os.path.splitext(k)[0]).lower()
			# print _module_name
			parse_autolist(_module_name)
			# print _str_array
			line_string = ':'.join([_module_name,cmd,(axf_dir + k)])
			line_string += __get_blank(line_string,170)*' ' +  ':' + '[Success]'
			# print line_string
			if _str_array:
				while _str_array:
					_str = _str_array.pop()
					finally_line = line_string + ':' + _str + "\n"
					try:
						mutex.acquire()
						file_log.write(finally_line)
						file_log.flush()
					finally:
						mutex.release()
					# print finally_line
			else:
				mutex.acquire()
				file_log.write(line_string + '\n')
				mutex.release()
	return ret

def __show_progress(current_index, counter):
	v = current_index* 100/counter
	sys.stdout.write("Progress: %d%%   \r" % (v))
	sys.stdout.flush()

class FileFilt:
	def __init__(self):
		self.fileList = []
		self.counter = 0
		pass
	def FindFile(self,dirr,filtrate = 1, find_file = ''):
		if os.path.isdir(dirr):
			pass
		else:
			print "<FileFilt>:Directory %s is not exist!\n\r"%dirr
			return 0

		if find_file:
			self.fileList =[s for s in os.listdir(dirr) if os.path.isfile(os.path.join(dirr,s)) and find_file in os.path.join(dirr,s)]
		else:
			except_list = ['xm4','dp650','isp','interrupt','armv8core','mmu','hwspinlock','jpeg','camafbc']
			# self.fileList =[s for s in os.listdir(dirr) if os.path.isdir(os.path.join(dirr,s)) and s in ['example']]
			self.fileList =[s for s in os.listdir(dirr) if os.path.isdir(os.path.join(dirr,s)) and s not in except_list]

		self.counter = len(self.fileList)
		return self.counter

def find_all_file_text(fname, root_dir,target_text):
	suffix='.c'
	os.system(r'rm ' + fname) if os.path.exists(fname) else None
	all_files_list = [os.path.join(root,file) for root,dirs,files in os.walk(root_dir) for file in files if suffix in file]
	with open(fname, 'a') as tfile:
		for line in fileinput.input(files = all_files_list):
			tfile.write(line) if target_text in line and '//' not in line.strip()[:2] else None
		fileinput.close()


class autobuild_thread(threading.Thread):
	def __init__(self, _project_name, _axf_dir, _module_name, _build_type = "make"):
		super(autobuild_thread, self).__init__()
		self.project_name = _project_name
		self.axf_dir = _axf_dir
		self.module_name = _module_name
		self.build_type = _build_type
		self.result = None
	def run(self):
		self.result = build_module(self.project_name, self.axf_dir, self.module_name, self.build_type)
	def get_result(self):
		return self.result

def do_autoBuild(project_name,module_name = None):
	# print auto_test_fn,log_file_name
	isExists = os.path.exists(res_dir)
	if isExists:
		os.system(r'rm ' + auto_test_fn)
		os.system(r'rm ' + log_file_name)
	else:
		os.mkdir(res_dir)
		os.system(r'chmod +w %s'%res_dir)
	os.system("rm build/ -rf")

	print "Collecting autoTestlist ..."
	find_all_file_text(auto_test_fn, "./","TEST_AUTO_CASE_DEFINE")
	if os.path.getsize(auto_test_fn):
		print "Collected!"
	else:
		print 'find no TEST_AUTO_CASE_DEFINE \n',"Collected!"
		sys.exit(1)
	cmake_list = []
	if module_name:
		module_list = [module_name]
	else:
		b = FileFilt()
		b.FindFile(dirr = "./modules")
		module_list = b.fileList
	counter = len(module_list)
	for eachline in fileinput.input("./project/aquilac/CMakeLists.txt"):
		match = re.search(r'include_modules\((.*?)\)',eachline)
		cmake_list.append(match.group(1).strip()) if match else None
	fileinput.close()
	cmake_list = [module.split(r'/')[-1] for module in cmake_list]
	if 'aquilac' in project_name and not module_name:
		module_list = cmake_list[:]
		# print module_list
		# raw_input()
	if counter:
		print 'module total:%d\nmodule list:%s'%(counter,module_list)
	else:
		print "No module\n\r"
		print "Please check your directory, make sure in ctest root directory\n\r"
		sys.exit(1)
	global mutex,file_log
	result = 0
	mutex = threading.Lock()
	print '\nbuild module begain......'
	threads = []

	for k in module_list:
		#if k in ['ddr','benchmark','coremark','dhrystone','memtester','efuse']:
		#	continue
		if k in cmake_list:
			elf_dir = "./build/project/%s/"%(project_name)
			thread = autobuild_thread(project_name, elf_dir, k, "cmake")
		else:
			axf_dir = "./build/%s/img/%s/"%(project_name, k)
			thread = autobuild_thread(project_name, axf_dir , k)
		threads.append(thread)
	with open(log_file_name, 'w') as file_log:
		string = "%s's testCode building result!\n"%project_name
		print string
		file_log.write(string)
		for th in threads:
			th.start()
			th.join()
		for th in threads:
			th.join()
	for th in threads:
		result += th.get_result()

	with open(log_file_name, 'a+') as file_log:
		cnt = 0
		for eachline in file_log:
			if 'AUTOTEST' in eachline:
				cnt += 1

		string = "\nTotal Failed number = " + str(result) + "!\n"
		file_log.write(string)
		string = "Total autoTest number = " + str(cnt) + "!\n"
		file_log.write(string)
	print "\nfail cnt:%d!"%(result)
	print "Over!\n"
	return result


if __name__ == '__main__':
	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('project_name',choices = ["aquila_evb","aquila_fpga","aquilac_evb","aquilac_fpga"],help = 'input project name ')
	arg_parser.add_argument('-m','--module_name',default = '',help = 'if you test single module, input module name')
	argv = arg_parser.parse_args()
	global project_name
	project_name = argv.project_name
	try:
		do_autoBuild(project_name,argv.module_name)
	except Exception,e:
		print e
		sys.exit(1)


#usages
#Output will in file:"~build.result"
#1:You can run this script directly, $python ./tool/autobuild_all.py
#2:OR, call this by shell. Do it in bash to get the return value, return 0 is successful,
#python autobuild_all.py
#if [[ $? != 0 ]] ; then
#   echo "Not return 0"
#fi
