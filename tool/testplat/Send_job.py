#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import pika
import sys
import copy

import send_file

class Send_job(object):
	def __init__(self, addr, queue_key):
		self.addr = addr
		self.queue_key = queue_key
		self.connection = pika.BlockingConnection(pika.ConnectionParameters(host=self.addr))
		self.channel = self.connection.channel()
		self.channel.queue_declare(queue=self.queue_key, durable=True)

	def send_msg(self, msg_string):
		self.channel.basic_publish(exchange='',
								  routing_key=self.queue_key,
								  body=msg_string,
								  properties=pika.BasicProperties(
									 delivery_mode = 2, # make message persistent
								  ))
	#	print(" [x] Sent %r" % msg_string)

	def send_binary(self, binary_name):
		send_file.cmd_transfer(self.addr, 18861, binary_name, "cmd_name", "30s")

	def send_end(self):
		self.connection.close()

