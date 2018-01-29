#!/usr/bin/python

from basic_api import *
from auto_test_uart import *

sys.path.append("./tool/autoPlatform/t32_api")
from jtag_t32 import *

def autoTest_uart(t32api,autoTest_obj,uart):
	fname = os.path.join(cfg.share_ctest_root_dir, autoTest_obj.cmm_fn)
	uart.reset_log_file(autoTest_obj.test_log_dir)
	jtag_stop_it(t32api)
	wait_time = do_t32command_do_cmm(t32api, fname)
	wait_time = 20
	print "wait script stop running"
	case_timeout = eval('+'.join(autoTest_obj.test_timeout_list))
	print "wait time: %.1fs"%(wait_time+float(case_timeout))
	msgtype=c_ulonglong(0)
	timming = 0
	test_result = []
	while timming < wait_time:
		t32api.T32_GetPracticeState(byref(msgtype))
		if msgtype.value == 0:
			break
		else:
			timming += 1
			sys.stdout.write("timing: %ds\r" %int(timming))
			sys.stdout.flush()
			time.sleep(1)
	print 'script has stoped'
	for cmd_string,timeout in zip(autoTest_obj.test_cmd_list,autoTest_obj.test_timeout_list):
		uart.input(cmd_string)
		while 1:
			if uart.case_end_flag:
				test_result.extend(uart.result_log) if uart.result_log else None
				break
			timming += 1
			sys.stdout.write("timing: %ds\r" %int(timming))
			sys.stdout.flush()
			time.sleep(1)
			if int(timeout) + wait_time< timming:
				test_result.extend(uart.result_log) if uart.result_log else None
				break
		test_result.append('No_result_log') if not test_result else None
	autoTest_obj.set_test_result(test_result)
	uart.save_log_file()
	print 'wait total time: %ds'%timming
	print 'input cmd:',autoTest_obj.test_cmd_list
	print 'test result:',test_result
	print 'case test done!\n'

def autoTest(t32api,autoTest_obj):
	docmm_timeout = 10
	fname = os.path.join(cfg.share_ctest_root_dir, autoTest_obj.cmm_fn)
	jtag_stop_it(t32api)
	wait_time = do_t32command_do_cmm(t32api, fname)
	wait_time += docmm_timeout
	print "wait script stop running"
	print "wait time: %.1fs"%wait_time
	msgtype=c_ulonglong(0)
	timming = 0
	while timming < wait_time:
		t32api.T32_GetPracticeState(byref(msgtype))
		if msgtype.value == 0:
			break
		else:
			timming += 1
			sys.stdout.write("timing: %ds\r" %int(timming))
			sys.stdout.flush()
			time.sleep(1)
	print 'wait total time: %ds'%timming
	print 'script has stoped'

