#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import sys
import pickle
import copy
import os

from job_desc import Job_desc
from handle_job import Handle_job, JobThread

server_queue_name = 'test_msg_main_queue'
log_queue_name = 'log_queue'

def handle_log_callback(ch, method, properties, body):
	print(" [x] %r" % body)
	ch.basic_ack(delivery_tag = method.delivery_tag)

if __name__ == "__main__":
	len = len(sys.argv)

	server_addr = "localhost"
	file_dir = "./1/test.binary"

	if (len > 2):
		server_addr = sys.argv[1]
		file_dir = sys.argv[2]
	else:
		print ("please input: xx.py server_addr file_name_and_dir\n\r")
		exit(-1)

	job = Job_desc()
	job.set_global_env("fpga", "uart", server_addr)
	job.set_info("example", "help", "help", "30", "case_desc", file_dir)
	job.send_job(job, server_queue_name)

	#receive the test log
	thread = JobThread(server_addr, log_queue_name, handle_log_callback)
	thread.start()
	# some main thread activity ...
	i = 0
	while 1:#(i < 100000000):
		i = i + 1
	#end of thread activities
	thread.stop()
	thread.join()
	#single thread mode
#	h = Handle_job(server_addr, log_queue_name, handle_log_callback)
#	h.handle()




