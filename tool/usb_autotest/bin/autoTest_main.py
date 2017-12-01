#!/usr/bin/python

from report import report_result
from report_excel import report_excel
import argparse
import signal
import commands
import copy,os,sys,time
from auto_test_uart import *
import ConfigParser

def signal_handler(signum, frame):
    print '\nctrl_c exit.'
    stop_flag.set()
    sys.exit(0)

def get_timeout(timeout):
	reboot_time_l = [0,1,2,4,8,16,128,512]
	for  reboot_time in reboot_time_l:
		if int(timeout) < reboot_time:
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

	def to_object(self, id = None, module_name = '', binary = '',cmd_list = [],timeout_list = [], log_dir = '',build_result = 'Success'):
		self.ID = id
		self.module_name = module_name
		self.binary = binary
		self.test_cmd_list = cmd_list[:]
		self.test_timeout_list = timeout_list[:]
		self.build_result = build_result
		self.test_log_dir = log_dir

	def clear(self):
		self.__init__()

	def set_test_result(self, _test_result):
		self.test_result = _test_result[:]

	def download_binary(self):
		print 'download binary...'
		(system_run_ret,_log) = commands.getstatusoutput('sudo ./tool/evb/aquilac/download.sh %s'%self.binary)
		if system_run_ret:
			print 'download fail'
			stop_flag.set()
			sys.exit()
		print 'download end'

	def run_test(self,uart):
		uart.reset_log_file(self.test_log_dir)
		print 'start ctest ...'
		if not uart.expect('ctest#',3):
			print 'system error not into ctest'
		test_result = []
		for cmd_string,timeout in zip(self.test_cmd_list,self.test_timeout_list):
			timeout = get_timeout(timeout)
			print "wait time:%d"%timeout
			uart.input('reboot %d'%timeout) if timeout else None
			uart.input(cmd_string)
			for timming in range(1,timeout+1):
				if uart.case_end_flag:
					test_result.extend(uart.result_log) if uart.result_log else None
					uart.input('reboot 0')
					break
				sys.stdout.write("timing: %ds\r" %(int(timming)))
				sys.stdout.flush()
				time.sleep(1)
			else:
				test_result.extend(uart.result_log) if uart.result_log else None
				uart.input('reboot 0')
				time.sleep(1)
			test_result.append('No_result_log') if not test_result else None
		self.set_test_result(test_result)
		uart.save_log_file()
		print 'wait total time: %ds'%timming
		print 'input cmd:',self.test_cmd_list
		print 'test result:',test_result
		print 'case test done!\n'

class AutoTestParse(object):
	"""docstring for ClassName"""
	def __init__(self,project_name,report_name = 'all_module'):
		self.project_name = project_name
		self.report_name = report_name
		self.case_list = []
		self.case_cnt = 0

	def get_case(self,fname = './tool/tmp/~build.result',log_dir = './tool/tmp/log'):
		if os.path.exists(fname):
			pass
		else:
			print 'file %s is not exist! Plaese rebuild c code!'%fname
			return None

		os.system(r'rm -rf %s'%log_dir) if os.path.exists(log_dir) else None
		os.mkdir(log_dir)
		os.system(r'chmod 777 %s'%log_dir)

		with open(fname, 'r') as build_result_obj:
			for line_num,eachline in enumerate(build_result_obj):
				test_cmd_list = []
				timeout_list  = []
				obj = AutoTest()
				if '[Fail]' in eachline:
					module_name = eachline.split(':')[0]
					obj.to_object(id = line_num, module_name = module_name.strip(),build_result = 'Fail')
					obj.set_test_result(['Build_Fail'])
					self.case_list.append(copy.deepcopy(obj))
					obj.clear()
					continue

				if 'AUTOTEST' in eachline:
					pass
				elif ':' in eachline:
					module_name = eachline.split(':')[0]
					obj.to_object(id = line_num, module_name = module_name.strip())
					obj.set_test_result(['No_Auto_Case'])
					self.case_list.append(copy.deepcopy(obj))
					obj.clear()
					continue
				else:
					continue

				(module_name,build_cmd,axf_dir,build_result,test_cmd,time_out) = eachline.strip().split(':')
				module_name = module_name.strip()
				axf_dir = axf_dir.strip()
				build_result = build_result.strip()
				test_cmd_list = test_cmd.strip().split('@')[1:]
				timeout_list = time_out.strip().split('@')
				for i,timeout in enumerate(timeout_list):
					timeout = eval(timeout)
					timeout_list[i] = str(timeout)
				for i,value in enumerate(timeout_list):
					if value == '':
						timeout_list[i] = 10
				log_file = os.path.join(log_dir,create_file_name(axf_dir, line_num,'.log'))
				binary =  os.path.splitext(axf_dir)[0]+'.bin'
				obj.to_object(line_num, module_name, binary, test_cmd_list, timeout_list,log_file)
				self.case_list.append(copy.deepcopy(obj))
				obj.clear()
		self.case_cnt = len(self.case_list)
		if self.case_cnt:
			for case in self.case_list:
				# print "case_list:", "module_name:", case.module_name,"  cmd:", case.test_cmd_list, "  timeout_list:", case.test_timeout_list
				# raw_input()
				pass
		else:
			print 'get case list fail'
			sys.exit(1)

	def auto_test(self,uart):
		ch = raw_input('Pls make sure reset your board,if reset ener y else n:')
		for doing_num,case in enumerate(self.case_list):
			print 'doing_num:%d total_cnt:%d'%(doing_num,self.case_cnt)
			if case.test_result:
				print 'module name:',case.module_name
				print 'test result:',case.test_result
				print 'case test done!\n' 
				continue
			case.download_binary()
			case.run_test(uart)

	def create_report(self):
		report_result(self.case_list, './tool/tmp/' + 'report_all.pdf')
		report_excel(self.case_list, './tool/tmp/' + 'report_all.xls')
		print "AutoTest completed!\n\r"

	def clear_result(self,test_module = ''):
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
		axf_dir = './build/%s/img/%s'%(self.project_name,test_module)
		cmd = 'find %s -name *.axf -exec cp {} %s \;'%(axf_dir,test_module_dir)
		os.system(cmd) if test_module else None
		print 'output:'+test_module_dir
		print 'clear done'

class VminAutoTestParse(AutoTestParse):
	def __init__(self, project_name):
		super(VminAutoTestParse, self).__init__(project_name)
		self.jump_cnt = 0
		self.sdl_binary = ''

	def get_case(self,fname = './tool/usb_autotest/vmin/autotest.cfg',log_dir = './tool/tmp/log'):
		conf = ConfigParser.ConfigParser()
		if os.path.exists(fname):
			conf.read(fname)
		else:
			print "No autotest.cfg.Pls check!"
			sys.exit()

		os.system(r'rm -rf %s'%log_dir) if os.path.exists(log_dir) else None
		os.mkdir(log_dir)
		os.system(r'chmod 777 %s'%log_dir)

		try:
			module_name = conf.get('config','module_name')
			binary = conf.get('config','test_binary')
			sdl_binary = conf.get('config','sdl_binary')
			vol_high = conf.get('config','vol_high')
			voltage_grade = int(conf.get('config','voltage_grade'))
			level = conf.get('config','level')

			cmd = conf.get('command','cmd')
			timeout_list = [conf.get('command','timeout')]
		except:
			print "EEROR:Pls check autotest.cfg."
			sys.exit(1)

		self.jump_cnt = voltage_grade
		self.sdl_binary = sdl_binary
		binary = os.path.join('./tool/usb_autotest/vmin',binary)
		sdl_binary = os.path.join('./tool/usb_autotest/vmin',sdl_binary)
		os.system('cp %s ./tool/evb/aquilac/sdl.pak'%sdl_binary)

		vol_list = [(float(vol_high)-0.0125*i) for i in range(int(voltage_grade))]
		vol_list = ['%.4f'%vol for vol in vol_list]
		cmd = cmd.split()[0]
		test_cmd_set = []
		for level in range(int(level)):
			for vol in vol_list:
				cmd_str = ' '.join([cmd,vol,str(level)])
				cmd_list = [cmd_str]
				test_cmd_set.append([cmd_list,timeout_list])

		for line_num,test_cmd_set_list in enumerate(test_cmd_set):
			test_cmd_list,timeout_list = test_cmd_set_list
			obj = AutoTest()
			log_file = os.path.join(log_dir,create_file_name(binary, line_num,'.log'))
			obj.to_object(line_num, module_name, binary, test_cmd_list, timeout_list,log_file)
			self.case_list.append(copy.deepcopy(obj))
			obj.clear()
		self.case_cnt = len(self.case_list)
		if self.case_cnt:
			for case in self.case_list:
				# print "case_list:", "module_name:", case.module_name,"  cmd:", case.test_cmd_list, "  timeout_list:", case.test_timeout_list
				# raw_input()
				pass
		else:
			print 'get case list fail'
			sys.exit(1)
 
	def auto_test(self,uart):
		ch = raw_input('Pls make sure reset your board,if reset ener y else n:')
		fail_flag = jump_flag = 0
		for doing_num,case in enumerate(self.case_list):
			if jump_flag and (doing_num%self.jump_cnt):
				continue
			if doing_num%self.jump_cnt == 0:
				fail_flag = jump_flag = 0
			else:
				if re.findall('No_result_log|Cannot find result_log file|ERR',''.join(case_bkp.test_result)):
					if fail_flag:
						jump_flag = 1
						fail_flag = 0
						continue
					else:
						fail_flag = 1
				else:
					fail_flag = 0
			case_bkp = case
			print 'sdl:%s doing_num:%d total_cnt:%d'%(self.sdl_binary ,doing_num,self.case_cnt)
			case.download_binary()
			case.run_test(uart)
		
#pls change to ctest root directory , #./tool/autoTest/autoTest_main.py
if __name__ == '__main__':
	signal.signal(signal.SIGINT, signal_handler)
	signal.signal(signal.SIGTERM, signal_handler)
	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('project_name',choices = ["aquila_evb","aquila_fpga","aquilac_evb","aquilac_fpga"],help = 'input project name ')
	arg_parser.add_argument('-m','--module_name',default = '',help = 'if you test single module, input module name')
	arg_parser.add_argument('-b','--build',action = 'store_false',help = 'if donot build modules,input -b')
	arg_parser.add_argument('-v','--vmin',action = 'store_true',help = 'if vmin test,input -v')
	argv = arg_parser.parse_args()
	try:
		cnt = do_autoBuild(argv.project_name,argv.module_name) if argv.build else None
		uart = Uart()
		uart.createPort()
		uart.start()
		if argv.vmin:
			autotest = VminAutoTestParse(argv.project_name)
		else:
			autotest = AutoTestParse(argv.project_name)
		autotest.get_case()
		autotest.auto_test(uart)
	except Exception,e:
		print 'ERROR:',e
	finally:
		stop_flag.set()
		autotest.create_report()
		autotest.clear_result('clock')

