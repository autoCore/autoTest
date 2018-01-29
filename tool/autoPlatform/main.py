#!/usr/bin/env python
import os
import argparse



if __name__ == '__main__':
	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('project_name',choices = ["aquila_evb","aquila_fpga","aquilac_evb","aquilac_fpga"],help = 'input project name ')
	arg_parser.add_argument('-m','--module_name',default = '',help = 'if you test single module, input module name')
	argv = arg_parser.parse_args()

	cmd = raw_input('Pls input your cmd:')
	if cmd.lower() in 'build':
		os.system('python ./tool/autoPlatform/autobuild/autobuild.py %s'%argv.project_name)
	if cmd.lower() in 'autotest':
		os.system('python ./tool/autoPlatform/autoTest/bin/autoTest_main.py %s -j -b'%argv.project_name)
