#!/usr/bin/python

from basic_api import *

#internal get the file name part from axf name
def create_file_name(dir_string, line_num,suffix_name):
	fname = os.path.basename(dir_string)
	(fname,_suffix) = os.path.splitext(fname)
	this_log_name = str(line_num)+ '_' + fname  + suffix_name
	return this_log_name

def create_autoTest_cmm(obj, line_num,cmm_dir):
	cmm_fn = create_file_name(obj.axf_dir,line_num,".cmm")
	cmm_fn = os.path.join(cmm_dir,cmm_fn)
	# print cmm_fn
	with open(cfg.autoTest_template,'rU') as autoTest_template_obj,open(cmm_fn, 'w') as autoTest_obj:
		for eachline in autoTest_template_obj:
			if '&scriptpath=' in eachline[:12]:
				eachline = "&scriptpath=" + '"' + cfg.autoTest_script + '"' + '\n'
			if 'autoTest.log' in  eachline:
				eachline = eachline.replace(r'c:\autoTest.log',obj.t32_test_log_dir)

			if 'data.load.elf test.axf' in eachline:
				eachline = "data.load.elf " + obj.axf_dir + '\n'

			if 'fault_cmd' in eachline:
				for cmd_string,timeout in zip(obj.test_cmd_list,obj.test_timeout_list):
					eachline_tmp = eachline.replace('fault_cmd', cmd_string)
					autoTest_obj.write(eachline_tmp)
					eachline_tmp = 'wait ' + timeout + 's\n'
					autoTest_obj.write(eachline_tmp)
				eachline = '\n'
			autoTest_obj.write(eachline)
	return cmm_fn

def create_autoTest_cmm_uart(obj, line_num,cmm_dir):
	cmm_fn = create_file_name(obj.axf_dir,line_num,".cmm")
	cmm_fn = os.path.join(cmm_dir,cmm_fn)
	# print cmm_fn
	with open(cfg.autoTest_template,'rU') as autoTest_template_obj,open(cmm_fn, 'w') as autoTest_obj:
		for eachline in autoTest_template_obj:
			if '&scriptpath=' in eachline[:12]:
				eachline = "&scriptpath=" + '"' + cfg.autoTest_script + '"' + '\n'

			if 'data.load.elf test.axf' in eachline:
				eachline = '\n'.join(["data.load.elf " + obj.axf_dir,'go','stop','enddo'])

			autoTest_obj.write(eachline)
	return cmm_fn

autoTest_object_list = []
#rtc:make p=aquila_model m=rtc i=64 >/dev/null 2>&1:./build/aquila_model/img/rtc/aquila_model_rtc_test.axf   :[Success]:AUTOTEST@rtc:40
def get_autoTest_list(use_uart = None,fname = cfg.build_result_file):
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

	with open(fname, 'r') as build_result_obj:
		for line_num,eachline in enumerate(build_result_obj):
			test_cmd_list = []
			timeout_list  = []

			if 'Fail' in eachline:
				continue

			if 'AUTOTEST' in eachline:
				pass
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
			obj = autoTest_object()
			for i,value in enumerate(timeout_list):
				if value == '':
					timeout_list[i] = 10
			_log_dir = os.path.join(cfg.log_file_dir,create_file_name(axf_dir, line_num,'.log'))
			_t32_log_dir = os.path.join(cfg.t32_log_file_dir,create_file_name(axf_dir, line_num,'.log'))
			axf_dir = os.path.join(cfg.share_ctest_root_dir,axf_dir)
			obj.to_object(line_num, module_name, axf_dir, test_cmd_list, timeout_list, _log_dir, _t32_log_dir)
			if use_uart:
				obj.set_cmm_fn(create_autoTest_cmm_uart(obj, line_num,cfg.cmm_file_dir))
			else:
				obj.set_cmm_fn(create_autoTest_cmm(obj, line_num,cfg.cmm_file_dir))
			autoTest_object_list.append(obj)
	return autoTest_object_list
