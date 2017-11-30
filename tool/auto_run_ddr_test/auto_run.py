#!/usr/bin/env python

import os,sys,re
import time
import commands
import fileinput

if __name__ == '__main__':
	cmd_dir = '/mnt/share/sw_cv/aquilac_ddr_benchmark/'
	cmd_file = cmd_dir + 'cmd.txt'
	test_list = []
	ddr_init_fname = './tool/autoTest/script/aquilac/ddr_init.elf'
	cmd_status = 1
	test_flag = 0
	test_result = {}
	while 1:
		test_list = []
		try:
			for eachline in fileinput.input(cmd_file):
				if ':' not in eachline and eachline.strip():
					test_list.append(eachline.strip())
			fileinput.close()
		except:
			pass
		for fname in test_list:
			try:
				test_binary = os.path.join(cmd_dir,fname)
				print '\n',test_binary
				if os.path.exists(test_binary):
					cmd = 'cp %s %s'%(test_binary,ddr_init_fname)
					os.system(cmd)
					test_flag = 1
				else:
					test_flag = 0
					log = "test result: [No exist file]"
			except:
				print 'Error!Pls check file name'

			while test_flag:
				cmd_status, log = commands.getstatusoutput('python ./tool/autoTest/bin/autoTest_main.py aquilac_evb -b -u')
				print 'test done!'
				# print log
				if not cmd_status: break
			match = re.search(r'test result: \[(.*?)\]',log)
			if match: 
				test_result[fname] = match.group(1)
				print test_result[fname]
			else:
				if test_flag:
					test_result[fname] = 'fail'
				else:
					test_result[fname] = 'No exist file'
			try:
				for eachline in fileinput.input(cmd_file,inplace = 1):
					if eachline.strip() == fname and test_result:
						eachline = "% -15s:% -15s --%s"%(fname,test_result.pop(fname),time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())))
					print eachline.strip()
			except:
				print 'Error!Pls check file name'
			fileinput.close()
			print 'push result done!'
