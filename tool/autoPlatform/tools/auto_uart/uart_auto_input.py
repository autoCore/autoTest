#!/usr/bin/env python
from serial.tools.list_ports import comports
import serial
from serial import Serial
import threading 
import platform
import sys,os,re
import time,datetime
import argparse
import signal
import Queue
import multiprocessing as mp

def signal_handler(signum, frame):
    sys.exit(0)

class Uart(mp.Process):
	def __init__(self, log_file = None, is_print = True):
		super(Uart,self).__init__()
		if log_file:
			self.log = open(log_file,'w')
		else:
			self.log = open('test_log.log','w')
		self.comport = None
		self.last_log = None
		self.case_end_flag = False
		self.result_log = []
		self.is_print = is_print
		self.last_log_bak = ''
		self.timeout = 0.01
		self.fifo = mp.Queue(100)
		self.metux = mp.Lock()
		self.fifo_event = mp.Event()

	def input(self,msg):
		try:
			self.metux.acquire()
			self.case_end_flag = False
			self.result_log = []
			self.comport.write(msg+'\n')
		except Exception,e:
			print e
		finally:
			self.metux.release()

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

	def expect(self,pattern_list,timeout):
		self.fifo_event.set()
		uart_timeout = 0.1
		cnt = int((timeout+uart_timeout)/uart_timeout)
		timing = 0
		try:
			pattern_list + []
		except:
			print("Error: expect need a list in arg pattern")
			return (None,False)
		pattern = re.compile("|".join(pattern_list))
		try:
			for i in xrange(cnt):
				while not self.fifo.empty():
					data = self.fifo.get()
					if not data.strip(): continue
					tgt = pattern.search(data)
					if tgt:
						for j, ptn in enumerate(pattern_list):
							if ptn in tgt.group(0):
								return j,uart_timeout*i
				time.sleep(uart_timeout)
				if int(uart_timeout*i) != timing:
					sys.stdout.write("timing: %ds\r" %(int(uart_timeout*i)))
					sys.stdout.flush()
					timing = int(uart_timeout*i)
			return (None,False)
		except Exception,e:
			print e
		finally:
			self.fifo_event.clear()
			while not self.fifo.empty(): self.fifo.get()

	def createPort(self, port = None, baud = 115200, time_out = 0.1):
		if port:
			pass
		else:
			platform_type = platform.platform()
			port_list = comports()
			if "Linux" in platform_type:
				port_list = [port[0] for port in port_list]
				port_list = [port for port in port_list if "ttyUSB" in port or "ttyACM" in port]
			elif "Windows" in platform_type:
				port_list = [list(port) for port in port_list]
				port_list = [port for port in port_list if "USB to UART Bridge" in port[1]]
			print 'port:',port_list
			map(os.system,['sudo chmod 777 %s'%p for p in port_list])
			if port_list:
				if len(port_list) == 1:
					port = port_list[0]
				else:
					while 1:
						port = raw_input('Pls input port:')
						if port in port_list: break
						else:  print 'No device'
			else:
				print "No port"
				sys.exit(0)
		print 'current port name:',port
		self.comport = Serial(port, baud, timeout=time_out)
		self.timeout = time_out
		if self.comport.isOpen():
			return 1
		else:
			print "create port fail"
			sys.exit(1)

	def run(self):
		try:
			while 1:
				line = self.comport.readline().strip()
				if not line: continue
				self.last_log = line
				self.metux.acquire()
				if self.fifo_event.is_set():
					self.fifo.put(line)
				self.metux.release()
				if line == 'ctest#':
					if line == self.last_log_bak:
						sys.stdout.write('\n\r')
						sys.stdout.write(line)
						sys.stdout.flush()
					else:
						sys.stdout.write('          \r')
						sys.stdout.write(line+' ')
						sys.stdout.flush()
				if self.is_print: print line
				self.last_log_bak = line
				if self.log:
					self.log.write(line)
					self.log.flush()
				if 'AUTOTEST@' in line:
					match = re.search(r'AUTOTEST@.*?Result\[(.*?)\]:RetCode(\[.*?\])',line)
					if match:
						if match.group(1) == 'OK':
							self.result_log.append(match.group(1))
						else:
							self.result_log.append(match.group(1)+match.group(2))
				if 'Unknown command' in line:
					self.result_log.append(line.split('-')[0].strip())
				if 'ctest#' == line:
					self.case_end_flag = True if self.result_log else False
		except Exception,e:
			print e,'Serial Exception.Pls check serial'
		finally:
			self.cancel()

	def cancel(self):
		self.comport.close()
		if self.log:
			self.log.flush()
			self.log.close()

	def setDaemon(self,BOOL = False):
		self.daemon = BOOL

class UartController(threading.Thread):
	def __init__(self,uart):
		super(UartController,self).__init__()
		self.uart = uart

	def run(self):
		try:
			self.uart.start() if not self.uart.is_alive() else None
			while 1:
				msg = raw_input('')
				if 'exit' in msg:
					break
				elif 'is_print' in msg:
					value = msg.split('=')[1].strip()
					self.uart.is_print = True if eval(value) else False
				else : self.uart.input(msg)
		except Exception,e:
			print e,'Error:[UartController],Pls check serial port'
		finally:
			print 'UartController done'

def mkdir_if_no_exists(path):
	import os
	if not os.path.exists(path):
		os.mkdir(path)

def get_abs_dir():
	import os
	return os.path.dirname(os.path.abspath(__file__))

def make_log_file(file_name):
	abs_dir = get_abs_dir()
	log_dir = os.path.join(abs_dir,'log')
	mkdir_if_no_exists(log_dir)

	now = datetime.datetime.today()
	date = now.strftime("%d_%h_%H-%M-%S")
	return os.path.join(log_dir,'%s_%s.log'%(file_name,date))


def processing_cmd_file(cmd_file,uart):
	assert os.path.exists(cmd_file)
	with open(cmd_file) as file_obj:
		file_text = '|'.join(file_obj.readlines())
		file_text = '|' + re.sub('\n','',file_text)
	cmd_set = re.findall('\|AUTOTEST@\((.*?),(.*?)\)',file_text)
	cnt = re.findall('\|CNT@\((.*?)\)',file_text)
	for i in range(int(cnt[0])):
		print "\n**********************************"
		print "running cnt: %s"%i
		print "**********************************"
		time.sleep(2)
		uart.log.write("running cnt: %s\n"%i)
		for cmd,timeout in cmd_set:
			uart.input(cmd.strip())
			time.sleep(eval(timeout))

if __name__ == "__main__":
	signal.signal(signal.SIGINT, signal_handler)

	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('-f','--log_file',default = 'test_log',help='log path or log_file -- example: ./test_log')
	arg_parser.add_argument('-c','--cmd_file',default = '',help = 'if need autocmd.cfg ,input -c ./tool/auto_uart/autocmd.cfg')
	argv = arg_parser.parse_args()

	log_file = make_log_file(argv.log_file)
	uart = Uart(log_file)
	uart.createPort()
	uart.setDaemon(True)
	uart.start()
	uart_manager = UartController(uart)
	uart_manager.setDaemon(True)
	uart_manager.start()

	try:
		processing_cmd_file(argv.cmd_file,uart) if argv.cmd_file else None
		uart.join()
	except Exception,e:
		print e
	finally:
		uart.cancel()
		print 'exit'
