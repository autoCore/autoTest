#!/usr/bin/env python
import os
import sys
import string
import re,copy
import threading
import commands
import argparse
import fileinput

class BuildModule(threading.Thread):
	"""docstring for ClassName"""
	def __init__(self, _project_name, _module_name, _axf_dir, _cases,_build_type):
		super(BuildModule, self).__init__()
		self.project_name = _project_name
		self.module_name = _module_name
		self.build_type = _build_type
		self.axf_dir = _axf_dir
		self.cases = copy.deepcopy(_cases)
		self.build_cmd = ''
		self.binary_list = []
		self.result = None
		self.auto_cases = {}

	def get_result(self):
		return self.result

	def __get_target_binary(self,res_log):
		res_log = re.sub('\n','',res_log)
		binary_list = re.findall(r'Linking C executable (.*?\.elf)',res_log)
		binary_list = list(set(binary_list))
		if not binary_list:
			self.binary_list = ['No_target_binary']
			return
		file_list = [s for s in os.listdir(self.axf_dir) if os.path.isfile(os.path.join(self.axf_dir,s)) and '.elf' in os.path.join(self.axf_dir,s)]
		self.binary_list = [b for b in binary_list if b in file_list]

	def run(self):
		global mutex
		if self.build_type == "make":
			cmd = "make p=%s m=%s i=64"%(self.project_name,self.module_name)
		elif self.build_type == "cmake":
			cmd = "./make.sh %s %s"%(self.project_name, self.module_name)
		#exceptions modules, Woooooo
		if 'aquila_evb' in self.project_name:
			mkall_list = ['v550','mimir','dp650','ddr_init']
			if self.module_name in mkall_list:
				cmd = "./make/%s/mkall.sh %s"%(self.module_name,self.project_name)
		#end of exceptions
		(system_run_ret,res_log) = commands.getstatusoutput(cmd) #if success ,return 0  Linking C executable example_case0.elf
		biuld_log_dir = os.sep.join([os.curdir,"tool","tmp","build_log"])
		os.mkdir(biuld_log_dir) if not os.path.exists(biuld_log_dir) else None
		res_file = "_".join([self.project_name,self.module_name,"build_res.log"])
		res_file = os.sep.join([biuld_log_dir,res_file])
		res_file = open(res_file,"w")
		res_file.write(res_log)
		res_file.flush()
		res_file.close()
		self.build_cmd = cmd
		#after this, check the binary file
		m = FileFilt()
		if not system_run_ret:
			if self.build_type == "make":
				m.FindFile(dirr = self.axf_dir, find_file = '.axf')
				self.binary_list = m.fileList[:]
			elif self.build_type == "cmake":
				self.__get_target_binary(res_log)

		self.result = 1 if any([system_run_ret,not self.binary_list]) else 0  # if fail 1 else 0
		mutex.acquire()
		if self.result:
			print "module: %-30s fail!"%self.module_name
		else:
			print "module: %-30s success!"%self.module_name
			for k in self.binary_list:
				_module_name = re.sub(r'%s_|_test|_case.?'%self.project_name,'',os.path.splitext(k)[0]).lower()
				self.auto_cases[k] = self.cases.get(_module_name,[])
				# self.auto_cases.extend(self.cases.get(_module_name,[]))
		mutex.release()

class BuildModuleParser(object):
	"""docstring for ClassName"""
	def __init__(self, project,module = ''):
		self.project_name = project
		self.module_name  = module
		self.build_list = []
		self.auto_cases = {}
		self.build_result_fn = os.sep.join([os.curdir,"tool","tmp","~build.result"])
		self.auto_test_fn = os.sep.join([os.curdir,"tool","tmp","~autotest_list"])
		self.res_dir = os.sep.join([os.curdir,"tool","tmp"])

	def __get_auto_cases(self):
		assert os.path.exists(self.auto_test_fn),'file:%s not exists'%self.auto_test_fn
		with open(self.auto_test_fn) as file_obj:
			all_cases = ''.join(file_obj.readlines())
		all_cases = re.sub(r'\n|"|\(|\)','',all_cases)
		all_cases = re.sub(r'TIMEOUT_DEFAULT','30',all_cases)
		all_cases = all_cases.lower()
		assert all_cases,'No autoTest cases'

# TEST_AUTO_CASE_DEFINE("dvc", "dvc_auto", (TIMEOUT_DEFAULT));
		pattern = re.compile('test_auto_case_define(.*?),(.*?),(.*?);')
		all_cases = re.findall(pattern,all_cases)
		for _module_name,_cmd_string,_timeout in all_cases:
			_module_name = re.sub(r'_test|_case.?','',_module_name).strip()
			if self.auto_cases.get(_module_name):
				self.auto_cases[_module_name].append('AUTOTEST@' + _cmd_string.strip() + ':' + _timeout.strip())
			else:
				self.auto_cases[_module_name] = ['AUTOTEST@' + _cmd_string.strip() + ':' + _timeout.strip()]

	def prepare_build(self):
		if os.path.exists(self.res_dir):
			os.system(r'rm ' + self.auto_test_fn)
			os.system(r'rm ' + self.build_result_fn)
		else:
			os.mkdir(self.res_dir)
			os.system(r'chmod +w %s'%self.res_dir)
		os.system("rm build/ -rf")
		os.system("rm ./tool/tmp/build_log -rf") if os.path.exists('./tool/tmp/build_log') else None
		print "Collecting autoTestlist ..."
		find_all_file_text(self.auto_test_fn, "./modules","TEST_AUTO_CASE_DEFINE")
		print "Collected!"
		self.__get_auto_cases()

	def get_build_list(self):
		# cmake_list = []
		module_list = [self.module_name] if self.module_name else None
		if 'aquilac' in self.project_name and not self.module_name:
			with open("./project/aquilac/CMakeLists.txt") as cmake_file:
				cmake_file_text = ''.join(cmake_file.readlines())
				cmake_file_text = re.sub('\n','',cmake_file_text)
			module_list = re.findall(r'include_modules\((.*?)\)',cmake_file_text)
			module_list = [module.split(r'/')[-1] for module in module_list]

		if self.project_name.lower() in ['aquila_evb','aquila_fpga'] and not self.module_name:
			b = FileFilt()
			b.FindFile(dirr = "./modules")
			module_list = b.fileList

		# print module_list
		# raw_input()
		assert module_list,'No module\nPlease check your directory, make sure in ctest root directory\n'
		print 'module total:%d\nmodule list:%s'%(len(module_list),module_list)
		if 'aquilac' in self.project_name:
			elf_dir = "./build/project/%s/"%(self.project_name)
			self.build_list = [BuildModule(self.project_name, k, elf_dir, self.auto_cases,"cmake") for k in module_list]
		elif self.project_name.lower() in ['aquila_evb','aquila_fpga']:
			self.build_list = [BuildModule(self.project_name, k, "./build/%s/img/%s/"%(self.project_name, k), self.auto_cases,"make") for k in module_list]

	def start_build(self):
		print '\nbuild module begain......'
		global mutex
		mutex = threading.Lock()
		string = "%s's testCode building result!\n"%self.project_name
		print string
		for th in self.build_list:
			th.start()
			th.join()

	def clear_result(self):
		with open(self.build_result_fn, 'w+') as file_log:
			file_log.write("%s's testCode building result!\n"%self.project_name)
			for th in self.build_list:
				if th.get_result():
					line_string = ':'.join([th.module_name,th.build_cmd,th.axf_dir])
					line_string = '%-150s:[Fail]'%(line_string)
					file_log.write(line_string+'\n')
				else:
					for k in th.auto_cases:
						line_string = ':'.join([th.module_name,th.build_cmd,(th.axf_dir + k)])
						line_string = '%-150s:[Success]'%(line_string)
						if th.auto_cases[k]:
							line_list = [':'.join([line_string,auto_case]) for auto_case in th.auto_cases[k]]
							line_string = '\n'.join(line_list)
						file_log.write(line_string+'\n')

		with open(self.build_result_fn, 'a+') as file_log:
			res_log = ''.join(file_log.readlines())
			fail_cnt = len(re.findall(r'\[Fail\]',res_log))
			auto_cnt = len(re.findall(r'AUTOTEST',res_log))
			string = "\nTotal Failed number = " + str(fail_cnt) + "!\n"
			file_log.write(string)
			string = "Total autoTest number = " + str(auto_cnt) + "!\n"
			file_log.write(string)
		print "\nfail cnt:%d!"%(fail_cnt)
		print "Over!\n"

class FileFilt:
	def __init__(self):
		self.fileList = []
		self.counter = 0
		pass
	def FindFile(self,dirr,filtrate = 1, find_file = ''):
		assert os.path.isdir(dirr),"<FileFilt>:Directory %s is not exist!\n\r"%dirr
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
	all_files_list = [os.path.join(root,file) for root,dirs,files in os.walk(root_dir) for file in files if file.endswith(suffix)]
	with open(fname, 'a') as tfile:
		for line in fileinput.input(files = all_files_list):
			tfile.write(line) if target_text in line and not line.strip().startswith('//') else None
		fileinput.close()

def do_autoBuild(project,module = ''):
	try:
		buildmodules = BuildModuleParser(project,module)
		buildmodules.prepare_build()
		buildmodules.get_build_list()
		buildmodules.start_build()
		buildmodules.clear_result()
	except Exception,e:
		buildmodules.clear_result()
		print e

if __name__ == '__main__':
	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('project_name',choices = ["aquila_evb","aquila_fpga","aquilac_evb","aquilac_fpga"],help = 'input project name ')
	arg_parser.add_argument('-m','--module_name',default = '',help = 'if you test single module, input module name')
	argv = arg_parser.parse_args()
	do_autoBuild(argv.project_name,argv.module_name)

