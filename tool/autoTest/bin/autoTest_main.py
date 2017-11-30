#!/usr/bin/python

from autotest import *
from create_autoTest_cmm import get_autoTest_list
from report import report_result
from report_excel import report_excel
from dvc_autotest import do_dvc_autotest
import argparse
import signal


sys.path.append("./tool/")
from autobuild_all import do_autoBuild

def signal_handler(signum, frame):
    print '\nctrl_c exit.'
    stop_flag.set()
    sys.exit(0)

#pls change to ctest root directory , #./tool/autoTest/autoTest_main.py
if __name__ == '__main__':
	config_init()
	signal.signal(signal.SIGINT, signal_handler)
	signal.signal(signal.SIGTERM, signal_handler)
	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('project_name',choices = ["aquila_evb","aquila_fpga","aquilac_evb","aquilac_fpga"],help = 'input project name ')
	arg_parser.add_argument('-m','--module_name',default = None,help = 'if you test single module, input module name')
	arg_parser.add_argument('-b','--build',action = 'store_false',help = 'if donot build modules,input -b')
	arg_parser.add_argument('-u','--use_uart',action = 'store_true',help = 'if use uart input -u')
	argv = arg_parser.parse_args()
	if argv.build:
		try:
			cnt = do_autoBuild(argv.project_name,argv.module_name)
		except Exception,e:
			print e
			stop_flag.set()
			sys.exit(1)
		# if os.system("python ./tool/autobuild_all.py %s %s"%(argv.project_name,argv.module_name)):
			print 'Error, buid fail'
			sys.exit(1)
	try:
		if argv.use_uart:
			uart = Uart()
			uart.createPort()
			uart.start()

		if 'dvc' == argv.module_name:
			if argv.use_uart:
				do_dvc_autotest(uart)
			else:
				do_dvc_autotest()
			print 'dvc test done'
			stop_flag.set()
			sys.exit(0)

		autoTest_object_list = get_autoTest_list(argv.use_uart)
		if autoTest_object_list:
			# for autoTest_obj in autoTest_object_list:
				# print "autoTest_list:", "module_name:", autoTest_obj.module_name,"  cmd:", autoTest_obj.test_cmd_list, "  timeout:", autoTest_obj.test_timeout_list
			pass
		else:
			print 'get autotest list fail'
			sys.exit(1)

		total_cmm_count = len(autoTest_object_list)
		print 'total count of cmm: %d'%total_cmm_count
		t32api = connect_jtag()

		for doing_num,autoTest_obj in enumerate(autoTest_object_list):
			print 'doing_num:%d total_cnt:%d'%(doing_num,total_cmm_count)
			if argv.use_uart:
				autoTest_uart(t32api,autoTest_obj,uart)
			else:
				autoTest(t32api,autoTest_obj)
				get_test_result(autoTest_obj)
		report_result(autoTest_object_list, './tool/tmp/' + 'report_all.pdf')
		report_excel(autoTest_object_list, './tool/tmp/' + 'report_all.xls')
		if argv.module_name:
			clear_result(argv.project_name, argv.module_name)
		else:
			clear_result(argv.project_name, 'all_module')
		jtat_disconnect(t32api)
		print "AutoTest completed!\n\r"
		stop_flag.set()
	except Exception,e:
		print 'ERROR:',e
		stop_flag.set()

