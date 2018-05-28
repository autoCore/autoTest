#!/usr/bin/python

import argparse
import signal
import commands
import shutil
import copy,os,sys,time,datetime,re
from auto_test_uart import *
import ConfigParser
from cmd_manager import *

import pexpect,getpass


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

class Benchmark(object):
	"""docstring for ClassName"""
	def __init__(self):
		self.module_name = "benchmark"
		self.binary = None
		self.test_cmd_list = []
		self.test_timeout_list = []
		self.test_log_dir = None
		self.test_result = []

	def to_object(self, binary = '',cmd_list = [],timeout_list = [], log_dir = ''):
		self.binary = binary
		self.test_cmd_list = cmd_list[:]
		self.test_timeout_list = timeout_list[:]
		self.test_log_dir = log_dir

	def set_test_result(self,test_result):
		self.test_result = test_result[:]
	def clear(self):
		self.__init__()

class BenchmarkParse(object):
	"""docstring for ClassName"""
	def __init__(self,project_name,report_name = 'benchmark'):
		self.project_name = project_name
		self.report_name = report_name
		self.case_list = {}
		self.uart = None
		self.config_options = {}
		self.cmd_list = {}
		self.log_dir = None
		self.sudo_password = None
		self.autotest_tmp = os.sep.join([os.curdir,"tool","tmp"])
		self.cmd_create = None

	def prepare_test(self,is_build = False):
		self.uart = Uart()
		self.uart.createPort()
		self.uart.start()

		cfgfile = os.sep.join([os.curdir,"tool","autoPlatform","benchmark_test","autocmd.cfg"])
		self.cmd_create = CreateCmd()
		self.cmd_create.get_config(cfgfile)

		for group in self.cmd_create.config_options:
			self.cmd_create.create_cmd_list(group)

		self.autotest_tmp =  os.sep.join([os.curdir,"tool","tmp"])
		os.mkdir(self.autotest_tmp) if not os.path.exists(self.autotest_tmp) else None
		os.chmod(self.autotest_tmp,0o777)

		self.log_dir =  os.sep.join([self.autotest_tmp,"log"])
		shutil.rmtree(self.log_dir) if os.path.exists(self.log_dir) else None
		os.mkdir(self.log_dir)
		os.chmod(self.log_dir,0o777)

	def get_case(self):
		obj = Benchmark()
		self.case_list = { key:[] for key in self.cmd_create.cmd_dict}
		for group in self.cmd_create.cmd_dict:
			binary = self.cmd_create.config_options.get(group,{}).get('binary')
			timeout = self.cmd_create.config_options.get(group,{}).get('timeout')
			# print "binary:",binary
			binary = os.sep.join([os.curdir,"tool","autoPlatform","benchmark_test","test_bin",binary])
			assert binary and os.path.exists(binary), "Error:Test Binary No Exists!"
			test_cmd_list = self.cmd_create.cmd_dict[group]
			# print test_cmd_list
			timeout_list = [timeout for _str in test_cmd_list]
			for i, cmd_set in enumerate(zip(test_cmd_list,timeout_list)):
				test_cmd,test_timeout = cmd_set
				log_file = os.path.join(self.log_dir,create_file_name(binary, i,'.log'))
				obj.to_object(binary, [test_cmd], [test_timeout],log_file)
				self.case_list[group].append(copy.deepcopy(obj))
				obj.clear()

		self.case_cnt = len(self.case_list)
		assert self.case_cnt, 'get case list fail'

	def __myspawn(self, command,fout = None):
		proc = pexpect.spawn(command)
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
		proc = self.__myspawn(download_bin_cmd,open('./tool/tmp/~download_res.log','w'))
		index = proc.expect([r'\[sudo\] password', pexpect.EOF, pexpect.TIMEOUT], timeout=2)
		if index == 0:
			self.sudo_password = SUDO_PASSWORD if SUDO_PASSWORD else getpass.getpass("input sudo password:")
			proc.sendline(self.sudo_password)
		index = proc.expect([expected_ptn, pexpect.EOF, pexpect.TIMEOUT], timeout=timeout)
		if index == 0:
			print "download successfully %s"%binary
			self.__close_proc(proc)
		else:
			print "Error: failed to download %s"%binary
			self.__close_proc(proc)
			raise MyException("Error: failed to download %s"%binary)

	def __wait_case_done(self,timeout):
		return self.uart.expect(['ctest#','BOOTROM: SPL0'],timeout)

	def run_test(self,case):
		print 'start ctest ...'
		print 'module_name: %s'%case.module_name
		index,spend_time = self.uart.expect(['ctest#'],3)
		if not spend_time:
			print 'system error not into ctest'
		test_result = []

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

		for cmd_string,_timeout in zip(case.test_cmd_list,case.test_timeout_list):
			print 'input cmd:',cmd_string
			self.uart.input(cmd_string)
			if case.module_name in ['ipc','tl4',"ddr_vmin","core_vmin"]:
				index,timming = self.uart.expect(['BOOTROM: SPL0'],int(timeout)+2)
			else:
				index,timming = self.uart.expect(['ctest#','BOOTROM: SPL0'],int(timeout)+2)
			test_result.extend(self.uart.result_log) if self.uart.result_log else test_result.append('No_result_log')
			if not timming:
				case.set_test_result(test_result)
				raise MyException('No reboot after timeout')
			print 'wait total time: %ds'%timming
			# print 'test result:',test_result
		else:
			self.uart.input('reboot 0')
			self.__wait_case_done(1)

		case.set_test_result(test_result)
		print 'case test done!\n'

	def start_test(self):
		for case_group in self.case_list:
			for doing_num,case in enumerate(self.case_list[case_group]):
				print 'doing_num:%d total_cnt:%d'%(doing_num,len(self.case_list[case_group]))
				print 'module name:',case.module_name
				self.uart.reset_log_file(case.test_log_dir)
				self.download_binary(case.binary,r'image %s downloaded!'%case.binary)
				self.run_test(case)
				self.uart.save_log_file()
			self.create_report()
			self.clear_result(case_group)
	def create_report(self):
		cmd = "python ./tool/cap_log_info/capture_log.py ./tool/tmp/log"
		proc = self.__myspawn(cmd)
		index = proc.expect([r'capture log done', pexpect.EOF, pexpect.TIMEOUT], timeout=2)

	def clear_result(self,test_module = ''):
		now = datetime.datetime.today()
		date = now.strftime("%d_%h_%H-%M-%S")
		test_module_dir = './tool/tmp/%s_log_%s'%(test_module,date)
		os.mkdir(test_module_dir)
		os.chmod(test_module_dir,0o777)
		shutil.move(self.log_dir,test_module_dir)
		os.mkdir(self.log_dir)
		os.chmod(self.log_dir,0o777)
		find_name = [self.report_name+'*','test_report*']
		for _name in find_name:
			cmd = 'find ./tool/tmp -maxdepth 1 -name %s -type f -exec mv {} %s \;'%(_name,test_module_dir)
			os.system(cmd)
		cmd = 'mv ./tool/cap_log_info/perfinfo.xls %s'%(test_module_dir)
		os.system(cmd)
		cmd = 'find ./tool/tmp -maxdepth 1 -name ~* -exec cp {} %s \;'%(test_module_dir)
		os.system(cmd)
		os.system('find ./tool -name *.pyc -exec rm {} \;')

		print 'output:'+test_module_dir
		print 'clear done'

#pls change to ctest root directory , #./tool/autoTest/autoTest_main.py

if __name__ == '__main__':
	signal.signal(signal.SIGINT, signal_handler)
	signal.signal(signal.SIGTERM, signal_handler)

	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('project_name',choices = ["aquila_evb","aquila_fpga","aquilac_evb","aquilac_fpga"],help = 'input project name ')
	argv = arg_parser.parse_args()

	try:
		autotest = BenchmarkParse(argv.project_name)
		autotest.prepare_test()
		autotest.get_case()
		autotest.start_test()
		raise TestEndException
	except (MyException,AssertionError),e:
		stop_flag.set()
		print 'ERROR:',e
	except TestEndException:
		stop_flag.set()
		autotest.create_report()
		# autotest.clear_result(autotest.report_name)
	except Exception,e:
		stop_flag.set()
		print 'ERROR:',e
		autotest.create_report()
		# autotest.clear_result(autotest.report_name)

