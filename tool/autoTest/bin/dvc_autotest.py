#!/usr/bin/python

from basic_api import *
from jtag_t32 import *
from report_excel import report_excel
from report import report_result
from create_test_report import do_create_test_report

# from create_dvc_cmd import create_dvc_cmd
from create_autotest_cmd import *
from create_autotest_cmd import voltage_grade as jump_cnt
from create_autoTest_cmm import *
from autotest import *
sys.path.append("./tool")
sys.path.append("../")
from autobuild_all import do_autoBuild

def create_cmd_set():
	cmd_file_dir = create_cpu_vmin_cmd()
	# cmd_file_dir = create_ddr_vmin_cmd()
	if os.path.exists(cfg.autocmd_file_dir):
		pass
	else:
		print 'Pls create autotest cmd'
		return -1
	test_cmd_set = []
	with open(cfg.autocmd_file_dir) as cmd_obj:
		for line_no,eachline in enumerate(cmd_obj):
			cmd_str,timeout_str,repeat_cnt = eachline.strip().split('#')
			cmd_list = cmd_str.strip().split('@')
			timeout_list = timeout_str.strip().split('@')
			repeat_cnt = find_text_between('[',']',repeat_cnt)
			for i in range(int(repeat_cnt)):
				test_cmd_set.append([cmd_list,timeout_list])
	return test_cmd_set

def dvc_get_autotest(use_uart = False,fname = cfg.build_result_file):
	if os.path.exists(fname):
		pass
	else:
		print 'file %s is not exist! Plaese rebuild c code!'%fname
		return None

	if os.path.exists(cfg.cmm_file_dir):
		os.system(r'rm -rf ' + cfg.cmm_file_dir)

	os.mkdir(cfg.cmm_file_dir)
	os.system(r'chmod +w ' + cfg.cmm_file_dir)

	if os.path.exists(cfg.log_file_dir):
		os.system(r'rm -rf ' + cfg.log_file_dir)

	os.mkdir(cfg.log_file_dir)
	os.system(r'chmod 777 ' + cfg.log_file_dir)

	dvc_cmm_dir = os.path.join(cfg.cmm_file_dir,'dvc/')
	if os.path.exists(dvc_cmm_dir):
		os.system(r'rm -rf ' + dvc_cmm_dir)
		os.mkdir(dvc_cmm_dir)
	else:
		os.mkdir(dvc_cmm_dir)
	os.system(r'chmod +w ' + dvc_cmm_dir)

	# module_name = 'dvc'
	module_name = 'clock'
	with open(fname, 'r') as build_result_obj:
		for each_line in build_result_obj:
			each_line = each_line.strip()
			if module_name in each_line.split(':')[0]:
				dvc_build_string = each_line
		if dvc_build_string :
			pass
		else:
			print 'find no module dvc'
			return 0

	if 'Fail' in dvc_build_string:
		print 'module dvc build fail'
		return 0
# clock:./make.sh aquilac_evb example  >/dev/null 2>&1:./build/project/aquilac_evb/clock_case0.elf   :[Success]:AUTOTEST@example 3:7
	build_result = 'Success'
	axf_dir = dvc_build_string.split(':')[2].strip()
	for line_no,test_cmd_set_list in enumerate(create_cmd_set()):
		test_cmd_list,timeout_list = test_cmd_set_list
		# print "dvc_autoTest_list:", "axf:", axf_dir, "build result:", build_result,"cmd:", test_cmd_list, "timeout:", timeout_list
		dev_obj = autoTest_object()
		# clock_case0.elf
		log_name = create_file_name(axf_dir, line_no,'.log')
		_linux_log_dir = os.path.join(cfg.log_file_dir,log_name)
		_win_log_dir = os.path.join(cfg.t32_log_file_dir,create_file_name(axf_dir, line_no,'.log'))
		axf_dir = os.path.join(cfg.share_ctest_root_dir,axf_dir)
		dev_obj.to_object(line_no,module_name,axf_dir, test_cmd_list, timeout_list, _linux_log_dir, _win_log_dir)
		if use_uart:
			dev_obj.set_cmm_fn(create_autoTest_cmm_uart(dev_obj, line_no,dvc_cmm_dir))
		else:
			dev_obj.set_cmm_fn(create_autoTest_cmm(dev_obj, line_no,dvc_cmm_dir))
		autoTest_object_list.append(dev_obj)
		# if line_no == 2:
			# return autoTest_object_list
	return autoTest_object_list

def dvc_autotest(autoTest_object_list,t32api,uart = None):
	# jump_cnt = 2
	fail_flag = jump_flag = 0
	res_tmp_obj = open(cfg.res_tmp_dir,'w')
	do_cmm = 20
	for doing_num,autoTest_obj in enumerate(autoTest_object_list):
		if jump_flag and (doing_num%jump_cnt):
			continue

		if doing_num%jump_cnt == 0:
			fail_flag = jump_flag = 0
		else:
			# if "No_result_log" in ''.join(autoTest_obj_bkp.test_result) or "Cannot find result_log file" in ''.join(autoTest_obj_bkp.test_result) or 'ERR' in ''.join(autoTest_obj_bkp.test_result):
			if re.findall('No_result_log|Cannot find result_log file|ERR',''.join(autoTest_obj_bkp.test_result)):
				if fail_flag:
					jump_flag = 1
					fail_flag = 0
					continue
				else:
					fail_flag = 1
			else:
				fail_flag = 0

		autoTest_obj_bkp = autoTest_obj
		t32api = jtag_stop_it(t32api)
		while not t32api:
			time.sleep(1)
			t32api = jtat_connect()

		print "doing pos: %d  total cmm num: %d"%(doing_num,len(autoTest_object_list))
		if uart:
			autoTest_uart(t32api,autoTest_obj,uart)
		else:
			autoTest(t32api,autoTest_obj)
			get_test_result(autoTest_obj)
		eachline_list = [str(doing_num),'@'.join(autoTest_obj.test_cmd_list),'@'.join(autoTest_obj.test_result)]
		eachline = '#'.join(eachline_list)
		res_tmp_obj.write(eachline + '\n')
		res_tmp_obj.flush()
	res_tmp_obj.close()
	return autoTest_object_list

def do_dvc_autotest(uart = None):
	global use_uart
	use_uart = True if uart else False
	dvc_autoTest_obj_list = dvc_get_autotest(uart)
	if dvc_autoTest_obj_list:
		# for autoTest_obj in autoTest_object_list:
		# 	print "autoTest_list:", "module name:", autoTest_obj.module_name,"  cmd:", autoTest_obj.test_cmd_list, "  timeout:", autoTest_obj.test_timeout_list
		pass
	else:
		print 'get autotest list fail'
		return -1

	total_cmm_count = len(dvc_autoTest_obj_list)
	print 'total count of cmm: %d'%total_cmm_count
	print "\n\rDo jtag command\n\r"
	t32api = connect_jtag()
	if t32api:
		for i in range(1):
			dvc_autotest(dvc_autoTest_obj_list,t32api,uart)
			report_result(dvc_autoTest_obj_list,'./tool/tmp/' + 'report_all.pdf')
			report_excel(dvc_autoTest_obj_list,'./tool/tmp/' + 'report_all.xls')
			clear_result('aquilac_evb',dvc_autoTest_obj_list[0].module_name)
		jtat_disconnect(t32api)
		print "AutoTest completed!\n\r"
		return 0
	else:
		print "Pls check your jtag t32\n\r"
		return -1

if __name__ == '__main__':
	if 0:
		if 0 != do_autoBuild():
			print "autoBuild have some failed results, but try to test continue\n\r"
	if do_dvc_autotest():
		print 'test done'
		exit(0)
	else:
		print 'err'
		exit(1)

