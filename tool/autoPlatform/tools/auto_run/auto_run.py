#!/usr/bin/env python

import os
import sys
import time
import commands
import pexpect

if __name__ == '__main__':
	ret = 0
	fail_build_module_buf = set()
	while 1:
		fail_build_module_set = set()
		print "date:",time.ctime()
		print "git pull"
		time_out = 20
		proc = pexpect.spawn("git pull",timeout = time_out)
		index = proc.expect(["Already up-to-date", "files changed", pexpect.EOF, pexpect.TIMEOUT], timeout=time_out)
		# cmd_status, get_pull_log = commands.getstatusoutput("git pull")
		if index == 0:
			print 'No update'
		elif index == 3:
			print 'git pull timeout'
		elif index == 1:
			print "build module......"
			build_res_log = commands.getoutput("python ./tool/autobuild_all.py aquilac_evb")
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

