#!/usr/bin/env python

import os
import sys
import time
import commands

if __name__ == '__main__':
	ret = 0
	fail_build_module_buf = set()
	while 1:
		fail_build_module_set = set()
		print "date:",time.ctime()
		print "git pull"
		cmd_status, get_pull_log = commands.getstatusoutput("git pull")
		if "Already up-to-date" in get_pull_log:
			print 'No update'
			pass
		elif cmd_status:
			print 'git pull issue'
			pass
		else:
			print "build module......"
			build_res_log = commands.getoutput("python ./tool/autobuild_all.py aquilac_fpga")
			print "build module end"
			build_res = build_res_log.split("\n")
			for eachline in build_res:
				if "fail!" in eachline:
					_str = eachline.split(" ")[1]
					fail_build_module_set.add(_str.lstrip())
			print "send build fail email:",list(fail_build_module_set)
			for module_name in fail_build_module_set:
				os.system("python ./tool/auto_run/send_email.py %s fail"%module_name)

			fail_build_module_buf |= fail_build_module_set

			_set = fail_build_module_buf - fail_build_module_set
			if _set:
				print "send fixed fail email:",list(_set)
				for module_name in _set:
					os.system("python ./tool/auto_run/send_email.py %s fixed"%(module_name))
			fail_build_module_buf -= _set
		os.system('find ./tool -name *.pyc -exec rm {} \;')
		time.sleep(600)

	if ret == 0:
		exit(0)
	else:
		exit(1)

