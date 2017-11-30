#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import pika
import sys
import copy
import threading

class JobThread(threading.Thread):
	def __init__(self, addr, queue_key, callback):
		super(JobThread, self).__init__()
		self._is_interrupted = False

		self.addr = addr
		self.queue_key = queue_key
		self.callback = callback

	def stop(self):
		self._is_interrupted = True

	def run(self):
		connection = pika.BlockingConnection(pika.ConnectionParameters(host=self.addr))
		channel = connection.channel()
		channel.queue_declare(queue=self.queue_key, durable=True)
		print("thread running\n\r")
		for message in channel.consume(queue=self.queue_key, inactivity_timeout=100):
			if self._is_interrupted:
				break
			if not message:
				continue
			method, properties, body = message
			print(body)

class Handle_job(object):
	def __init__(self, addr, queue_key, callback):
		self.addr = addr
		self.queue_key = queue_key
		self.callback = callback
		connection = pika.BlockingConnection(pika.ConnectionParameters(host=self.addr))
		self.channel = connection.channel()
		self.channel.queue_declare(queue=self.queue_key, durable=True)

	def handle(self):
		self.channel.basic_qos(prefetch_count=1)
		self.channel.basic_consume(self.callback, queue=self.queue_key)
		self.channel.start_consuming()

	def register_func(self, func):
		self.callback = func