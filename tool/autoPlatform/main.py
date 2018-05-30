#!/usr/bin/env python

import os,sys
import argparse
import pexpect

def command_parse(cmd):
	if "build" in cmd:
		if argv.module_name:
			return "python ./tool/autoPlatform/autobuild/autobuild.py %s -m %s"%(argv.project_name,argv.module_name)
		else:
			return "python ./tool/autoPlatform/autobuild/autobuild.py %s"%(argv.project_name)

	if 'uart' in cmd:
		return "python ./tool/autoPlatform/tools/auto_uart/uart_auto_input.py"

	if cmd in 'autotest':
		return "python ./tool/autoPlatform/autoTest/bin/autoTest_main.py %s -b"%(argv.project_name)

	if 'autotest_' in cmd:
		cmd_str, arg = cmd.split("_")
		return "python ./tool/autoPlatform/autoTest/bin/autoTest_main.py %s -%s -b"%(argv.project_name,arg)

	if 'ddr_current' in cmd:
		return "python ./tool/autoPlatform/autoTest/bin/autoTest_main.py %s -c"%(argv.project_name)

	if 'benchmark' in cmd:
		return "python ./tool/autoPlatform/modules/benchmark_test/test_main.py %s"%(argv.project_name)

	if "gui" in cmd:
		return "python ./tool/autoPlatform/autoPlatform_gui.py %s"%(argv.project_name)


if __name__ == '__main__':
	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('project_name',choices = ["aquila_evb","aquila_fpga","aquilac_evb","aquilac_fpga"],help = 'input project name ')
	arg_parser.add_argument('-m','--module_name',default = '',help = 'if you test single module, input module name')
	arg_parser.add_argument('-c','--command',default = '',help = 'please input command, example,build autotest_j,autotest_v,ddr_current,uart,benchmark')
	argv = arg_parser.parse_args()
	if argv.command:
		cmd = command_parse(argv.command)
		if cmd:
			print cmd
			# proc = pexpect.spawn(command_parse(argv.command))
			# index = proc.expect([r'over', myexpect.EOF, myexpect.TIMEOUT],timeout = 600)
			os.system(command_parse(argv.command))
		else:
			print "please check your input"
	else:
		print "please input command, example,build autotest"

