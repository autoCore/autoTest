#! /usr/bin/env python

import sys,os,re,time
import copy
import xlrd
import pexpect

from xlutils.copy import copy as excel_copy
from pyExcelerator import *
from xlutils.copy import *

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

import pexpect,getpass

sys.path.append("./tool/autoPlatform/autobuild")
from autobuild import do_autoBuild

sys.path.append("./tool/autoPlatform/t32_api")
from jtag_t32 import *


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

class Case1(object):
	"""docstring for ClassName"""
	def __init__(self,module_name):
		self.module_name = module_name
		self.case_list = []
		self.timeout_list = []
		self.test_bin = ""
		self.test_log_dir = ""
		self.test_result = []

	def to_object(self,cmd,timeout):
		self.case_list.append(cmd)
		self.timeout_list.append(timeout)

	def set_test_bin(self,binary,log_dir):
		self.test_bin = binary
		self.test_log_dir = log_dir
	def set_test_result(self,test_result):
		self.test_result.append(test_result)


class Case(object):
	"""docstring for ClassName"""
	def __init__(self,module_name):
		self.ID = ""
		self.is_auto = ""
		self.module_name = module_name
		self.case_cmd = ""
		self.timeout = ""
		self.test_bin = ""
		self.test_log_dir = ""
		self.test_result = []
		self.test_owner = "autoTest"
		self.test_time = ""
		self.test_case_file = ""

	def to_object(self,ID,is_auto,cmd,timeout,case_file):
		self.ID = int(ID) if ID else None
		self.is_auto = is_auto
		self.case_cmd = cmd
		self.timeout = int(timeout) if timeout else None
		self.test_case_file = case_file

	def set_test_bin(self,binary,log_dir):
		self.test_bin = binary
		self.test_log_dir = log_dir
	def set_test_result(self,test_result):
		self.test_result = test_result[:]

class AutoTestParse(object):
	def __init__(self,project_name,report_name = 'all_modules'):
		self.project_name = project_name
		self.report_name = report_name if report_name else 'all_modules'
		self.case_list = []
		self.case_cnt = 0
		self.uart = None
		self.config_options = {}
		self.log_dir = None
		self.build_res_fname = None
		self.sudo_password = None

	def prepare_test(self,is_build = False,module_name = ""):
		self.uart = Uart()
		self.uart.createPort()
		self.uart.start()

		self.sudo_password = SUDO_PASSWORD
		do_autoBuild(argv.project_name,module_name) if is_build else None
		self.build_res_fname = os.sep.join([os.curdir,"tool","tmp","~build.result"])
		self.log_dir = os.sep.join([os.curdir,"tool","tmp","log"])
		shutil.rmtree(self.log_dir) if os.path.exists(self.log_dir) else None
		os.mkdir(self.log_dir)
		os.chmod(self.log_dir,0o777)

	def get_case(self,case_list):
		assert os.path.exists(self.build_res_fname),'No file:%s'%self.build_res_fname
		self.case_list = []
		with open(self.build_res_fname) as file_obj:
			all_modules = '##'.join(file_obj.readlines())
		all_modules = re.sub(r'\n| {3,}','',all_modules)
		all_modules = re.sub(r'TIMEOUT_DEFAULT','30',all_modules)
		all_modules = '#' + all_modules + '#'
		
		auto_case_modules = re.findall(r'#([a-zA-Z_0-9]+):([^:]+):([^:]+):\[(Success)\]:AUTOTEST@([^:]+):(.*?)#',all_modules)
		fail_modules = re.findall(r'#([a-zA-Z_0-9]+):[^:]+:[^:]+:\[Fail\]#',all_modules)
		no_auto_list = re.findall(r'#([a-zA-Z_0-9]+):[^:]+:[^:]+:\[Success\]#',all_modules)
		for case in case_list:
			# print case.module_name
			pattern = re.compile(r'#%s:[^:]+:[^:]+:\[Success\]'%case.module_name)
			match = pattern.search(all_modules)
			if match: 
				test_bin = match.group(0).split(":")[2]
				if test_bin.endswith('.elf'):
					test_bin = test_bin.replace(".elf",".bin")
				# print test_bin
				file_name = "%02d_%s.log"%(case.ID,case.module_name)
				log_file = os.path.join(self.log_dir,file_name)
				case.set_test_bin(test_bin,log_file)
				self.case_list.append(case)
		self.case_cnt = len(self.case_list)
		assert self.case_cnt, 'get case list fail'
		# for case in self.case_list:
		# 	print '\n'.join(['{}:{}'.format(item[0],item[1]) for item in case.__dict__.items()])
		# 	raw_input()

	def __myspawn(self, fout, command):
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
		proc = self.__myspawn(open('./tool/tmp/~download_res.log','w'), download_bin_cmd)
		index = proc.expect([r'\[sudo\] password', pexpect.EOF, pexpect.TIMEOUT], timeout=2)
		if index == 0:
			self.sudo_password = self.sudo_password if self.sudo_password else getpass.getpass("input sudo password:")
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
		index,spend_time = self.uart.expect(['ctest#'],2)
		if not spend_time:
			print 'system error not into ctest'
		test_result = []
		# for cmd_string,timeout in zip(case.case_list,case.timeout_list):

		# for cmd_string,timeout in (case.case_cmd,case.timeout):
		cmd_string,timeout = case.case_cmd,case.timeout
		timeout = get_timeout(timeout)
		self.uart.input('reboot %d'%timeout)
		self.__wait_case_done(1)
		if timeout:
			print "wait time:%d"%timeout
		else:
			print 'timeout overrange reboot max time\n'
			self.set_test_result(['timeout overrange reboot max time'])
			return
		print 'input cmd:',cmd_string
		self.uart.input(cmd_string)
		if case.module_name in ['ipc','tl4',"ddr_vmin","core_vmin"]:
			index,timming = self.uart.expect(['BOOTROM: SPL0'],timeout+2)
		else:
			index,timming = self.uart.expect(['ctest#','BOOTROM: SPL0'],timeout+2)
		test_result.extend(self.uart.result_log) if self.uart.result_log else test_result.append('No_result_log')
		if timming:
			self.uart.input('reboot 0')
			self.__wait_case_done(1)
		else:
			case.set_test_result(test_result)
			raise MyException('No reboot after timeout')
		print 'wait total time: %ds'%timming
		print 'test result:',test_result
		case.set_test_result(test_result)
		print 'case test done!\n'

	def start_test(self):
		for doing_num,case in enumerate(self.case_list):
			print 'doing_num:%d total_cnt:%d'%(doing_num,self.case_cnt)
			if not case.is_auto:
				print 'cmd:%s not autotest'%case.case_cmd
				continue
			self.uart.reset_log_file(case.test_log_dir)
			self.download_binary(case.test_bin,r'image %s downloaded!'%case.test_bin)
			self.run_test(case)
			self.uart.save_log_file()

	def create_report(self):
		report_result(self.case_list, './tool/tmp/' + self.report_name + '.pdf')
		report_excel(self.case_list, './tool/tmp/' + self.report_name + '.xls')
		print "AutoTest completed!\n\r"

	def clear_result(self,test_module = ''):
		now = datetime.datetime.today()
		date = now.strftime("%d_%h_%H-%M-%S")
		test_module_dir = './tool/tmp/%s_log_%s'%(test_module,date)
		os.mkdir(test_module_dir)
		os.system('chmod 777 ' + test_module_dir)
		os.system('cp ./tool/tmp/log %s -rf'%test_module_dir)
		find_name = [self.report_name+'*','test_report*']
		for _name in find_name:
			cmd = 'find ./tool/tmp -maxdepth 1 -name %s -type f -exec mv {} %s \;'%(_name,test_module_dir)
			os.system(cmd)
		cmd = 'find ./tool/tmp -maxdepth 1 -name ~* -exec cp {} %s \;'%(test_module_dir)
		os.system(cmd)
		axf_dir = './build/%s/img/%s'%(self.project_name,test_module)
		cmd = 'find %s -name *.axf -exec cp {} %s \;'%(axf_dir,test_module_dir)
		os.system(cmd) if test_module else None
		os.system('find ./tool -name *.pyc -exec rm {} \;')
		print 'output:'+test_module_dir
		print 'clear done'

ID_ROL = 0
IS_AUTO_ROL = 6
CMD_ROL = 7
TMEOUT_ROL = 8
RESULT_ROL = 9
if __name__ == '__main__':


	signal.signal(signal.SIGINT, signal_handler)
	signal.signal(signal.SIGTERM, signal_handler)
	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('project_name',choices = ["aquila_evb","aquila_fpga","aquilac_evb","aquilac_fpga"],help = 'input project name ')
	arg_parser.add_argument('-m','--module_name',default = '',help = 'if you test single module, input module name')
	arg_parser.add_argument('-b','--build',action = 'store_false',help = 'if donot build modules,input -b')
	argv = arg_parser.parse_args()
	autotest = AutoTestParse(argv.project_name)
	autotest.prepare_test(argv.build)
	bak_row = []
	try:
		while 1:
			case_list = []
			root_dir = "./testcase"
			suffix = ".xls"
			all_files_list = [os.path.join(root,file) for root,dirs,files in os.walk(root_dir) for file in files if file.endswith(suffix)]
			# print all_files_list
			for file in all_files_list:
				if "dma_testCase.xls" in file:
					fname_excel = file
			module_name = os.path.basename(fname_excel)
			module_name = module_name.split("_")[0]
			workbook = xlrd.open_workbook(fname_excel)
			worksheet = workbook.sheets()[1]
			case = Case(module_name)
			for i in range(worksheet.nrows):
				if i < 2: continue
				data = worksheet.row_values(i)
				ID = data[ID_ROL]
				is_auto =  True if "Yes" in data[IS_AUTO_ROL] else False
				cmd = data[CMD_ROL]
				timeout = data[TMEOUT_ROL]
				test_result = data[RESULT_ROL]
				if test_result or not is_auto:
					pass
				else:
					case.to_object(ID,is_auto,cmd,timeout,fname_excel)
					case_list.append(copy.deepcopy(case))

			# for case in case_list:
			# 	print '\n'.join(['{}:{}'.format(item[0],item[1]) for item in case.__dict__.items()])
			# 	raw_input()

			if case_list:
				autotest.get_case(case_list)
				autotest.start_test()

			for case in case_list:
				workbook = xlrd.open_workbook(case.test_case_file,formatting_info = True)
				append_data = excel_copy(workbook)
				worksheet = append_data.get_sheet(1)
				if case.test_result and re.findall('No_result_log|Cannot find result_log file|ERR',''.join(case.test_result)):
					test_result = "Fail"
				elif re.findall('Unknown command',''.join(case.test_result)):
					test_result = "Unknown command"
				elif case.test_result:
					test_result = "Pass"
				else:
					continue
				worksheet.write(case.ID+1,RESULT_ROL,test_result)
				append_data.save(case.test_case_file)
			time.sleep(1)
		raise TestEndException
	except (MyException,AssertionError),e:
		stop_flag.set()
		print 'ERROR:',e
	except TestEndException:
		stop_flag.set()
		# autotest.create_report()
		# autotest.clear_result(autotest.report_name)
	except Exception,e:
		stop_flag.set()
		print 'ERROR:',e
		# autotest.create_report()
		# autotest.clear_result(autotest.report_name)
		# 

'''
			for i in range(worksheet.nrows):
				data = worksheet.row_values(i)
				if "onging" not in data[6] and i in bak_row:
					bak_row.remove(i)
					continue

				if "onging" in data[6] and i not in bak_row:
					bak_row.append(i)
					test_case = data[2]
					test_case = re.findall(r"AUTOTEST\((.*?),(.*?)\)",test_case)
					if test_case:
						cmd,timeout = test_case[0]
						print cmd,timeout
						case.to_object(cmd,timeout)
						# case_list.append(copy.deepcopy(case))
					else:
						print "No case"
			case_list.append(copy.deepcopy(case))
'''