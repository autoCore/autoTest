#!/usr/bin/env python
from serial.tools.list_ports import comports
import serial
from serial import Serial
import threading 
import platform
import sys,re

stop_flag = threading.Event()
class Uart(threading.Thread):
	def __init__(self, log_file = None, send = None):
		super(Uart,self).__init__()
		self.log = open(log_file,'w') if log_file else None
		self.comport = None
		self.send_obj = send
		self.last_log = None
		self.case_end_flag = False
		self.result_log = []

	def input(self,msg):
		if self.comport:
			self.case_end_flag = False
			self.last_log = None
			self.result_log = []
			self.comport.write(msg+'\n')
			return 1
		else:
			print 'Pls create port'
			return 0

	def reset_log_file(self,file):
		if self.log:
			self.log.flush()
			self.log.close()
			self.log = None
		self.log = open(file,'w')

	def save_log_file(self):
		if self.log:
			self.log.flush()
			self.log.close()
			self.log = None
		else:
			print 'No log file'

	def createPort(self, port = None, baud = 115200, time_out = 0.1):
		if port:
			pass
		else:
			platform_type = platform.platform()
			port_list = comports()
			if "Linux" in platform_type:
				port_list = [port[0] for port in port_list]
				port_list = [port for port in port_list if "ttyUSB" in port]
			elif "Windows" in platform_type:
				port_list = [list(port) for port in port_list]
				port_list = [port for port in port_list if "USB to UART Bridge" in port[1]]
			if port_list:
				port = port_list[0]
				print port
			else:
				print "No port"
				sys.exit(0)
		self.comport = Serial(port, baud, timeout=time_out)
		if self.comport.isOpen():
			return 1
		else:
			print "create port fail"
			sys.exit(1)
# AUTOTEST@:Module[RTC]:Case[Full function test]:Result[OK]:RetCode[0x0]
# Unknown command 'keypad_ns' - try 'help'
	def run(self):
		while 1:
			if stop_flag.is_set(): break
			try:
				line = self.comport.readline().strip()
				if line and self.send_obj: self.send_obj.send_msg(line)
				# if line.strip(): print line
				if self.log and line:
					self.last_log = line.strip()
					if 'AUTOTEST@' in self.last_log:
						match = re.search(r'AUTOTEST@.*?Result\[(.*?)\]:RetCode(\[.*?\])',self.last_log)
						if match:
							if match.group(1) == 'OK':
								self.result_log.append(match.group(1))
							else:
								self.result_log.append(match.group(1)+match.group(2))
					if 'Unknown command' in self.last_log:
						self.result_log.append(self.last_log.split('-')[0].strip())
					if 'ctest#' == line.strip():
						self.case_end_flag = True if self.result_log else False
					print >>self.log,line
					self.log.flush()
			except Exception,e:
				print e,'Serial Exception.Pls check serial'
				stop_flag.set()
				break
		self.comport.close()
		if self.log:
			self.log.flush()
			self.log.close()

