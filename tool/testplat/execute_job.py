#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import pika
import time
import pickle
import sys
import os


from job_desc import Job_desc
from Send_job import Send_job
from handle_job import Handle_job

server_queue_name = 'test_msg_main_queue'
log_queue_name = 'log_queue'

def __do_job(job):
	if (job.download_method == 'jtag'):
		print ("Will test binary: %s by Jtag\n\r" %os.path.basename(job.file_binary_name))
	elif (job.download_method == 'uart'):
		print ("Will test binary: %s by Uart\n\r" %os.path.basename(job.file_binary_name))

def handle_job_callback(ch, method, properties, body):
#	print(" [x] Received %r" % body)
#	print(" [x] Done")
	job = Job_desc()
	job = pickle.loads(body)
	job.dump()
	job.receive_binary()
#	print ("received binary: %s\n\r" %job.file_binary_name)
	__do_job(job)

#send message
	s = Send_job(server_addr, log_queue_name)
	i = 10
	while (i > 1):
		print ("send begin\n\r")
		s.send_msg("hello, Iam Server: send log to u\n\r")
		print ("send end\n\r")
		time.sleep(1)
		i = i -1
	s.send_end()

	ch.basic_ack(delivery_tag = method.delivery_tag)

def handle_msg(server_addr):
#handle message
	h = Handle_job(server_addr, server_queue_name, handle_job_callback)
	h.handle()


if __name__ == "__main__":
	len = len(sys.argv)

	server_addr = "localhost"
	if (len > 1):
		server_addr = sys.argv[1]

	handle_msg(server_addr)

