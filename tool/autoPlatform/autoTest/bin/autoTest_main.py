#!/usr/bin/python

from report import report_result
from report_excel import report_excel,vmin_report
import argparse
import signal
import commands
import copy,os,sys,time,datetime,re,shutil
from auto_test_uart import *
import ConfigParser
from autotest import *
from create_autoTest_cmm import *

import getpass

if os.name == 'nt': #sys.platform == 'win32':
	import winpexpect as myexpect
	from winpexpect import winspawn as myspawn
elif os.name == 'posix':
	import pexpect as myexpect
	from pexpect import spawn as myspawn

sys.path.append(os.sep.join([os.curdir,"tool","autoPlatform","autobuild"]))
from autobuild import do_autoBuild

sys.path.append(os.sep.join([os.curdir,"tool","autoPlatform","jtag_api"]))
from jtag_api import *

class MyException(Exception): pass
class TestEndException(Exception): pass

def signal_handler(signum, frame):
    print '\n'
    raise TestEndException('ctrl_c exit!')

def get_timeout(timeout):
	reboot_time_l = [0,1,2,4,8,16,128,512]
	for  reboot_time in reboot_time_l:
		if int(timeout) <= reboot_time:
			return reboot_time
	return 0

def create_file_name(dir_string, line_num,suffix_name):
	fname = os.path.basename(dir_string)
	(fname,_suffix) = os.path.splitext(fname)
	this_log_name = str(line_num)+ '_' + fname  + suffix_name
	return this_log_name

class AutoTest(object):
	"""docstring for ClassName"""
	def __init__(self):
		self.ID = None
		self.module_name = None
		self.binary = None
		self.test_cmd_list = []
		self.test_timeout_list = []
		self.build_result = None
		self.test_log_dir = None
		self.test_result = []
		self.cmm_fn = ''
		self.t32_test_log_dir = ''
		self.queue_flag = False

	def to_object(self, id = None, module_name = '', binary = '',cmd_list = [],timeout_list = [], log_dir = '',t32_log_dir = '',build_result = 'Success'):
		self.ID = id
		self.module_name = module_name
		self.binary = binary
		self.test_cmd_list = cmd_list[:]
		self.test_timeout_list = timeout_list[:]
		self.build_result = build_result
		self.test_log_dir = log_dir
		self.t32_test_log_dir = t32_log_dir

	def set_cmm_fn(self, _file_name):
		self.cmm_fn = _file_name

	def clear(self):
		self.__init__()

	def set_test_result(self, _test_result):
		self.test_result = _test_result[:]


class AutoTestParse(object):
	"""docstring for ClassName"""
	def __init__(self,project_name,report_name = 'all_modules'):
		self.project_name = project_name
		self.report_name = report_name if report_name else 'all_modules'
		self.case_list = []
		self.case_cnt = 0
		self.uart = None
		self.config_options = {}
		self.log_dir = None
		self.build_res_fname = None
		self.sudo_password = SUDO_PASSWORD
		self.use_queue = True
		self.autotest_tmp = os.sep.join([os.curdir,"tool","tmp"])

	def prepare_test(self,is_build = False):
		self.uart = Uart()
		self.uart.createPort()
		self.uart.start()

		# do_autoBuild(argv.project_name,argv.module_name) if is_build else None
		# ch = raw_input('Pls make sure reset your board,if reset ener y else n:')
		# if ch == 'n': raise MyException('exit')

		conf = ConfigParser.ConfigParser()
		conf.read(os.sep.join([os.curdir,"tool","autoPlatform","autoPlatform.cfg"]))
		for sec in conf.sections():
			self.config_options[sec] = {k:v for k,v in conf.items(sec)}
		# print self.config_options

		autotest_tmp = self.config_options.get('basic_config',{}).get('autotest_tmp')
		self.autotest_tmp =  autotest_tmp if autotest_tmp else os.sep.join([os.curdir,"tool","tmp"])
		os.mkdir(self.autotest_tmp) if not os.path.exists(self.autotest_tmp) else None

		log_dir = self.config_options.get('basic_config',{}).get('log_dir')
		self.log_dir =  log_dir if log_dir else os.sep.join([self.autotest_tmp,"log"])
		shutil.rmtree(self.log_dir) if os.path.exists(self.log_dir) else None
		os.mkdir(self.log_dir)
		os.chmod(self.log_dir,0o777)
		if argv.current:
			build_res_fname = os.sep.join([os.curdir,"tool","autoPlatform","modules","aquilac_ddr_current","~build.result"])
		else:
			build_res_fname = self.config_options.get('basic_config',{}).get('build_res_fname')
		self.build_res_fname =  build_res_fname if build_res_fname else os.sep.join([self.autotest_tmp,"~build.result"])

	def get_case(self):
		obj = AutoTest()
		assert os.path.exists(self.build_res_fname),'No file:%s'%self.build_res_fname
		with open(self.build_res_fname) as file_obj:
			all_modules = '##'.join(file_obj.readlines())
		all_modules = re.sub(r'\n| {3,}','',all_modules)
		all_modules = re.sub(r'TIMEOUT_DEFAULT','30',all_modules)
		all_modules = '#' + all_modules + '#'
		auto_case_modules = re.findall(r'#([a-zA-Z_0-9]+):([^:]+):([^:]+):\[(Success)\]:AUTOTEST@([^:]+):(.*?)#',all_modules)
		fail_modules = re.findall(r'#([a-zA-Z_0-9]+):[^:]+:[^:]+:\[Fail\]#',all_modules)
		no_auto_list = re.findall(r'#([a-zA-Z_0-9]+):[^:]+:[^:]+:\[Success\]#',all_modules)
		no_auto_list = list(set(no_auto_list))
		no_auto_list.sort()
		no_auto_modules = []
		for module in no_auto_list:
			for case_info in auto_case_modules:
				if module in case_info: break
			else:
				no_auto_modules.append(module)
		# print all_modules
		line_num = 0
		for line_num, _str in enumerate(fail_modules):
			obj.to_object(id = line_num, module_name = _str,build_result = 'Fail')
			obj.set_test_result(['Build_Fail'])
			self.case_list.append(copy.deepcopy(obj))
			obj.clear()
		for line_num, _str in enumerate(no_auto_modules,line_num+1):
			obj.to_object(id = line_num, module_name = _str,build_result = 'Success')
			obj.set_test_result(['No_Auto_Case'])
			self.case_list.append(copy.deepcopy(obj))
			obj.clear()
		for line_num, case_info in enumerate(auto_case_modules,line_num+1):
			case_info = (_str.strip() for _str in case_info)
			module_name,build_cmd,axf_dir,build_result,test_cmd,time_out = case_info
			test_cmd_list = test_cmd.split('@')
			timeout_list = time_out.split('@')
			for i,timeout in enumerate(timeout_list):
				timeout = eval(timeout)
				timeout_list[i] = str(timeout)
			for i,value in enumerate(timeout_list):
				if value == '':
					timeout_list[i] = 30
			log_file = os.path.join(self.log_dir,create_file_name(axf_dir, line_num,'.log'))
			binary =  os.path.splitext(axf_dir)[0]+'.bin'
			obj.to_object(line_num, module_name, binary, test_cmd_list, timeout_list,log_file)
			self.case_list.append(copy.deepcopy(obj))
			obj.clear()
		self.case_cnt = len(self.case_list)
		assert self.case_cnt, 'get case list fail'
		# for case in self.case_list:
		# 	print '\n'.join(['{}:{}'.format(item[0],item[1]) for item in case.__dict__.items()])
		# 	raw_input()
		if self.use_queue:
			case_bak = None
			case_list = []
			for case in self.case_list:
				if not case_bak:
					case_list.append(case)
					case_bak = case
					continue
				if case_bak.binary and case_bak.binary in case.binary:
					case_list[-1].test_cmd_list += case.test_cmd_list
					case_list[-1].test_timeout_list += case.test_timeout_list
				else:
					case_list.append(case)
				case_bak = case
			self.case_list = case_list[:]
		# for case in case_list:
		# 	print '\n'.join(['{}:{}'.format(item[0],item[1]) for item in case.__dict__.items()])
		# 	raw_input()
	def __myspawn(self, fout, command):
		proc = myspawn(command)
		proc.logfile_read = fout
		# proc.logfile_read = sys.stdout
		return proc

	def __close_proc(self, proc):
		if proc != None:
			proc.close(force=True)
			proc = None

	def download_binary(self,binary,expected_ptn, timeout = 10):
		print 'download binary...'
		download_bin_cmd = 'sudo ./tool/evb/aquilac/download.sh %s'%binary
		proc = self.__myspawn(open('./tool/tmp/~download_res.log','w'), download_bin_cmd)
		index = proc.expect([r'\[sudo\] password', myexpect.EOF, myexpect.TIMEOUT], timeout=5)
		if index == 0:
			self.sudo_password = self.sudo_password if self.sudo_password else getpass.getpass("input sudo password:")
			proc.sendline(self.sudo_password)
		index = proc.expect([expected_ptn, myexpect.EOF, myexpect.TIMEOUT], timeout=timeout)
		if index == 0:
			print "download successfully %s"%binary
			self.__close_proc(proc)
		else:
			self.__close_proc(proc)
			raise MyException("Error: failed to download %s"%binary)

	def __wait_case_done(self,timeout):
		return self.uart.expect(['ctest#','BOOTROM: SPL0'],timeout)

	def run_test(self,case):
		print 'start ctest ...'
		print 'module_name: %s'%case.module_name
		index,spend_time = self.uart.expect(['ctest#'],2)
		if not spend_time:
			print 'system error not into ctest'
		test_result = []

		if self.use_queue:
				timeout = max(case.test_timeout_list)
				timeout = get_timeout(timeout)
				self.uart.input('reboot %d'%timeout)
				self.__wait_case_done(1)
				if timeout:
					print "wait time:%d"%timeout
				else:
					print 'timeout overrange reboot max time\n'
					self.set_test_result(['timeout overrange reboot max time'])
					return
				self.uart.input("queue on")
				index,timming = self.uart.expect(['queue on ok'],1)
				print 'input cmd:',case.test_cmd_list
				for cmd_string,time_out in zip(case.test_cmd_list,case.test_timeout_list):
					self.uart.input(cmd_string)
				index,timming = self.uart.expect(['BOOTROM: SPL0'],timeout+2)
				test_result.extend(self.uart.result_log) if self.uart.result_log else test_result.append('No_result_log')
				if not timming:
					case.set_test_result(test_result)
					raise MyException('No reboot after timeout')
				print 'wait total time: %ds'%timming
				print 'test result:',test_result
		else:
			self.uart.input("queue off")
			index,timming = self.uart.expect(['queue off ok'],1)
			timeout = eval("+".join(case.test_timeout_list))
			timeout = get_timeout(timeout)
			self.uart.input('reboot %d'%timeout)
			self.__wait_case_done(1)
			if timeout:
				print "wait time:%d"%timeout
			else:
				print 'timeout overrange reboot max time\n'
				self.set_test_result(['timeout overrange reboot max time'])
				return
			for cmd_string,time_out in zip(case.test_cmd_list,case.test_timeout_list):
				print 'input cmd:',cmd_string
				self.uart.input(cmd_string)
				if case.module_name in ['ipc','tl4',"ddr_vmin","core_vmin","ddr_current"]:
					index,timming = self.uart.expect(['BOOTROM: SPL0'],timeout+2)
				else:
					index,timming = self.uart.expect(['ctest#','BOOTROM: SPL0'],timeout+2)
				test_result.extend(self.uart.result_log) if self.uart.result_log else test_result.append('No_result_log')
				if not timming:
					case.set_test_result(test_result)
					raise MyException('No reboot after timeout')
				print 'wait total time: %ds'%timming
				print 'test result:',test_result
			else:
				self.uart.input('reboot 0')
				self.__wait_case_done(1)

		case.set_test_result(test_result)
		print 'case test done!\n'

	def start_test(self):
		for doing_num,case in enumerate(self.case_list):
			print 'doing_num:%d total_cnt:%d'%(doing_num,self.case_cnt)
			if case.test_result:
				print 'module name:',case.module_name
				print 'test result:',case.test_result
				print 'case test done!\n' 
				continue
			self.uart.reset_log_file(case.test_log_dir)
			self.download_binary(case.binary,r'image %s downloaded!'%case.binary)
			self.run_test(case)
			self.uart.save_log_file()

	def create_report(self):
		report_result(self.case_list, './tool/tmp/' + self.report_name + '.pdf')
		report_excel(self.case_list, './tool/tmp/' + self.report_name + '.xls')
		print "AutoTest completed!\n\r"

	def clear_result(self,test_module = ''):
		now = datetime.datetime.today()
		date = now.strftime("%d_%h_%H-%M-%S")
		test_module_dir = '%s_log_%s'%(test_module,date)
		test_module_dir = os.sep.join([self.autotest_tmp,test_module_dir])
		shutil.copytree(self.log_dir,test_module_dir)
		find_name = [self.report_name+'*','test_report*']
		for _name in find_name:
			cmd = 'find ./tool/tmp -maxdepth 1 -name %s -type f -exec mv {} %s \;'%(_name,test_module_dir)
			os.system(cmd)
		cmd = 'find ./tool/tmp -maxdepth 1 -name ~* -exec cp {} %s \;'%(test_module_dir)
		os.system(cmd)
		axf_dir = os.sep.join([os.curdir,"build",self.project_name,"img",test_module])
		cmd = 'find %s -name *.axf -exec cp {} %s \;'%(axf_dir,test_module_dir)
		os.system(cmd) if test_module else None
		os.system('find ./tool -name *.pyc -exec rm {} \;')
		print 'output:'+test_module_dir
		print 'clear done'

class Jtag_AutoTestParse(AutoTestParse):
	def __init__(self, project_name,report_name = 'all_modules'):
		super(Jtag_AutoTestParse, self).__init__(project_name,report_name)
		self.t32api = None
		self.reset_cmm = None
		self.use_uart = 0
		self.cmm_dir = ""

	def prepare_test(self,is_build = False):
		config_init()
		self.t32api = connect_jtag()
		assert self.t32api,'connect_jtag fail!'
		self.reset_cmm = os.sep.join([os.curdir,"tool","autoPlatform","libs"])

		if self.use_uart:
			self.uart = Uart()
			self.uart.createPort()
			self.uart.start()

		do_autoBuild(argv.project_name,argv.module_name) if is_build else None
		conf = ConfigParser.ConfigParser()
		conf.read(os.sep.join([os.curdir,"tool","autoPlatform","autoPlatform.cfg"]))
		for sec in conf.sections():
			self.config_options[sec] = {k:v for k,v in conf.items(sec)}
		# print self.config_options

		autotest_tmp = self.config_options.get('basic_config',{}).get('autotest_tmp')
		self.autotest_tmp =  autotest_tmp if autotest_tmp else os.sep.join([os.curdir,"tool","tmp"])
		os.mkdir(self.autotest_tmp) if not os.path.exists(self.autotest_tmp) else None

		log_dir = self.config_options.get('basic_config',{}).get('log_dir')
		self.log_dir =  log_dir if log_dir else os.sep.join([self.autotest_tmp,"log"])
		shutil.rmtree(self.log_dir) if os.path.exists(self.log_dir) else None
		os.mkdir(self.log_dir)
		os.chmod(self.log_dir,0o777)

		self.cmm_dir = os.sep.join([self.autotest_tmp,"cmm"])
		shutil.rmtree(self.cmm_dir) if os.path.exists(self.cmm_dir) else None
		os.mkdir(self.cmm_dir)
		os.chmod(self.cmm_dir,0o777)

		build_res_fname = self.config_options.get('basic_config',{}).get('build_res_fname')
		self.build_res_fname =  build_res_fname if build_res_fname else os.sep.join([self.autotest_tmp,"~build.result"])

	def get_case(self):
		obj = AutoTest()
		assert os.path.exists(self.build_res_fname),'No file:%s'%self.build_res_fname
		with open(self.build_res_fname) as file_obj:
			all_modules = '##'.join(file_obj.readlines())
		all_modules = re.sub(r'\n| {3,}','',all_modules)
		all_modules = re.sub(r'TIMEOUT_DEFAULT','30',all_modules)
		all_modules = '#' + all_modules + '#'
		auto_case_modules = re.findall(r'#([a-zA-Z_0-9]+):([^:]+):([^:]+):\[(Success)\]:AUTOTEST@([^:]+):(.*?)#',all_modules)
		fail_modules = re.findall(r'#([a-zA-Z_0-9]+):[^:]+:[^:]+:\[Fail\]#',all_modules)
		no_auto_list = re.findall(r'#([a-zA-Z_0-9]+):[^:]+:[^:]+:\[Success\]#',all_modules)
		no_auto_list = list(set(no_auto_list))
		no_auto_list.sort()
		no_auto_modules = []
		for module in no_auto_list:
			for case_info in auto_case_modules:
				if module in case_info: break
			else:
				no_auto_modules.append(module)
		# print all_modules
		line_num = 0
		for line_num, _str in enumerate(fail_modules):
			obj.to_object(id = line_num, module_name = _str,build_result = 'Fail')
			obj.set_test_result(['Build_Fail'])
			self.case_list.append(copy.deepcopy(obj))
			obj.clear()
		for line_num, _str in enumerate(no_auto_modules,line_num+1):
			obj.to_object(id = line_num, module_name = _str,build_result = 'Success')
			obj.set_test_result(['No_Auto_Case'])
			self.case_list.append(copy.deepcopy(obj))
			obj.clear()
		for line_num, case_info in enumerate(auto_case_modules,line_num+1):
			case_info = (_str.strip() for _str in case_info)
			module_name,build_cmd,axf_dir,build_result,test_cmd,time_out = case_info
			test_cmd_list = test_cmd.split('@')
			timeout_list = time_out.split('@')
			for i,timeout in enumerate(timeout_list):
				timeout = eval(timeout)
				timeout_list[i] = str(timeout)
			for i,value in enumerate(timeout_list):
				if value == '':
					timeout_list[i] = 30
			log_file = os.path.join(self.log_dir,create_file_name(axf_dir, line_num,'.log'))
			_t32_log_dir = os.path.join(cfg.t32_log_file_dir,create_file_name(axf_dir, line_num,'.log'))
			axf_dir = os.path.join(cfg.share_ctest_root_dir,axf_dir)
			obj.to_object(line_num, module_name, axf_dir, test_cmd_list, timeout_list, log_file, _t32_log_dir)
			if argv.current:
				cfg.autoTest_template = os.sep.join([os.curdir,"tool","autoPlatform","autoTest","libs","aquilac_evb_current_template.cmm"])
				obj.set_cmm_fn(os.path.join(cfg.share_ctest_root_dir, create_autoTest_current_cmm(obj, line_num,cfg.cmm_file_dir)))
			else:
				if self.use_uart:
					obj.set_cmm_fn(os.path.join(cfg.share_ctest_root_dir, create_autoTest_cmm_uart(obj, line_num,cfg.cmm_file_dir)))
				else:
					obj.set_cmm_fn(os.path.join(cfg.share_ctest_root_dir,create_autoTest_cmm(obj, line_num,cfg.cmm_file_dir)))
			self.case_list.append(copy.deepcopy(obj))
			obj.clear()
		self.case_cnt = len(self.case_list)
		assert self.case_cnt, 'get case list fail'
		# for case in self.case_list:
		# 	print '\n'.join(['{}:{}'.format(item[0],item[1]) for item in case.__dict__.items()])
		# 	raw_input()
	def get_test_result(self,autoTest_obj):
		test_log_dir = autoTest_obj.test_log_dir
		test_cmd_list = autoTest_obj.test_cmd_list
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
		autoTest_obj.set_test_result(result_list)

	def start_test(self):
		for doing_num,case in enumerate(self.case_list):
			print 'doing_num:%d total_cnt:%d'%(doing_num,self.case_cnt)
			if case.test_result:
				print 'module name:',case.module_name
				print 'test result:',case.test_result
				print 'case test done!\n' 
				continue
			if self.use_uart:
				autoTest_uart(self.t32api,case,self.uart)
			else:
				autoTest(self.t32api,case)
				self.get_test_result(case)
				print 'input cmd:',case.test_cmd_list
				print 'test result:',case.test_result
				print 'case test done!\n'


class VminAutoTestParse(AutoTestParse):
	def __init__(self, project_name,report_name = 'vmin'):
		super(VminAutoTestParse, self).__init__(project_name,report_name)
		self.jump_cnt = 0
		self.sdl_binary = ''
		self.vmin_list = []
		self.use_queue = False

	def create_report(self):
		report_result(self.case_list, './tool/tmp/' + self.report_name + '.pdf')
		report_excel(self.case_list, './tool/tmp/' + self.report_name + '.xls')
		vmin_report(self.vmin_list, './tool/tmp/' + self.report_name + '.xls')
		print "AutoTest completed!\n\r"

	def prepare_test(self,is_build = False):
		self.uart = Uart()
		self.uart.createPort()
		self.uart.start()

		# ch = raw_input('Pls make sure reset your board,if reset ener y else n:')
		# if ch == 'n': raise MyException('exit')

		conf = ConfigParser.ConfigParser()
		conf.read(os.sep.join([os.curdir,"tool","autoPlatform","autoPlatform.cfg"]))
		for sec in conf.sections():
			self.config_options[sec] = {k:v for k,v in conf.items(sec)}
		# print self.config_options

		autotest_tmp = self.config_options.get('basic_config',{}).get('autotest_tmp')
		autotest_tmp =  autotest_tmp if autotest_tmp else os.sep.join([os.curdir,"tool","tmp"])
		os.mkdir(autotest_tmp) if not os.path.exists(autotest_tmp) else None

		log_dir = self.config_options.get('basic_config',{}).get('log_dir')
		self.log_dir =  log_dir if log_dir else os.sep.join([os.curdir,"tool","tmp","log"])
		shutil.rmtree(self.log_dir) if os.path.exists(self.log_dir) else None
		os.mkdir(self.log_dir)
		os.chmod(self.log_dir,0o777)

		build_res_fname = self.config_options.get('basic_config',{}).get('build_res_fname')
		self.build_res_fname =  build_res_fname if build_res_fname else os.sep.join([os.curdir,"tool","tmp","~build.result"])

		module_name = self.config_options.get('vmin_config',{}).get('module_name')
		test_binary = self.config_options.get('vmin_config',{}).get('test_binary')
		sdl_binary = self.config_options.get('vmin_config',{}).get('sdl_binary')
		vol_high = self.config_options.get('vmin_config',{}).get('vol_high')
		voltage_grade = int(self.config_options.get('vmin_config',{}).get('voltage_grade'))
		level = self.config_options.get('vmin_config',{}).get('level')
		cmd = self.config_options.get('vmin_config',{}).get('cmd')
		timeout = self.config_options.get('vmin_config',{}).get('timeout')
		self.jump_cnt = voltage_grade
		self.sdl_binary = sdl_binary
		test_binary = os.sep.join([os.curdir,"tool","autoPlatform","autoTest","vmin",test_binary])
		sdl_binary = os.sep.join([os.curdir,"tool","autoPlatform","autoTest","vmin",sdl_binary])
		dst_file = os.sep.join([os.curdir,"tool","evb","aquilac","sdl.pak"])
		shutil.copyfile(sdl_binary,dst_file)

		vol_list = [(float(vol_high)-0.0125*i) for i in range(int(voltage_grade))]
		vol_list = ['%.4f'%vol for vol in vol_list]
		cmd = cmd.split()
		aute_case_list = []
		if module_name == 'ddr_vmin':
			for value in range(int(level)):
				for vol in vol_list:
					cmd_str = ' '.join([cmd[0],vol,str(value)])
					aute_case_list.append('AUTOTEST@' + cmd_str.strip() + ':' + timeout.strip())
		elif module_name == 'core_vmin':
			for clst in eval(cmd[3]):
				for value in range(int(level)):
					for vol in vol_list:
						cmd_str = ' '.join([cmd[0],vol,str(value),str(clst)])
						aute_case_list.append('AUTOTEST@' + cmd_str.strip() + ':' + timeout.strip())
		line_string = ':'.join([module_name,'vmin_test',test_binary])
		line_string = '%-150s:[Success]'%(line_string)
		with open(self.build_res_fname,'w') as file_obj:
			line_list = [':'.join([line_string,auto_case]) for auto_case in aute_case_list]
			line_string = '\n'.join(line_list)
			file_obj.write(line_string+'\n')

	def start_test(self):
		for doing_num,case in enumerate(self.case_list):
			if doing_num%self.jump_cnt == 0:
				fail_cnt = jump_flag = 0
			if jump_flag and (doing_num%self.jump_cnt):
				continue
			print 'sdl:%s doing_num:%d total_cnt:%d'%(self.sdl_binary ,doing_num,self.case_cnt)
			self.uart.reset_log_file(case.test_log_dir)
			self.download_binary(case.binary,r'image %s downloaded!'%case.binary)
			self.run_test(case)
			self.uart.save_log_file()
			if re.findall('No_result_log|Cannot find result_log file|ERR',''.join(case.test_result)):
				fail_cnt += 1
				if fail_cnt == 2:
					jump_flag = 1
					fail_cnt = 0
					self.vmin_list.append(self.case_list[doing_num-2]) if doing_num > 2 else None
			else:
				fail_cnt = 0


#pls change to ctest root directory , #./tool/autoTest/autoTest_main.py
if __name__ == '__main__':
	signal.signal(signal.SIGINT, signal_handler)
	signal.signal(signal.SIGTERM, signal_handler)
	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('project_name',choices = ["aquila_evb","aquila_fpga","aquilac_evb","aquilac_fpga"],help = 'input project name ')
	arg_parser.add_argument('-m','--module_name',default = '',help = 'if you test single module, input module name')
	arg_parser.add_argument('-b','--build',action = 'store_false',help = 'if donot build modules,input -b')
	arg_parser.add_argument('-v','--vmin',action = 'store_true',help = 'if vmin test,input -v')
	arg_parser.add_argument('-j','--jtag',action = 'store_true',help = 'if use jtag,input -j')
	arg_parser.add_argument('-c','--current',action = 'store_true',help = 'if test current,input -c')
	argv = arg_parser.parse_args()

	if argv.current:
		argv.build = False
	try:
		if argv.vmin:
			argv.build = False
			report_file = argv.module_name if argv.module_name else 'vmin'
			autotest = VminAutoTestParse(argv.project_name,report_file)
		elif argv.jtag:
			autotest = Jtag_AutoTestParse(argv.project_name,argv.module_name)
		else:
			autotest = AutoTestParse(argv.project_name,argv.module_name)
		autotest.prepare_test(argv.build)
		autotest.get_case()
		autotest.start_test()
		raise TestEndException
	except (MyException,AssertionError),e:
		stop_flag.set()
		print 'ERROR:',e
	except TestEndException:
		stop_flag.set()
		autotest.create_report()
		autotest.clear_result(autotest.report_name)
	except Exception,e:
		stop_flag.set()
		print 'ERROR:',e
		autotest.create_report()
		autotest.clear_result(autotest.report_name)

