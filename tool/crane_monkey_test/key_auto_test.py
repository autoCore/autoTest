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
import random
import traceback

stop_flag = threading.Event()
metux = threading.Lock()

def signal_handler(signum, frame):
	stop_flag.set()
	print('ctrl_c exit.') 
	sys.exit(0)

class TestEndException(Exception): pass

class Uart(threading.Thread):
	def __init__(self, log_file = None, is_print = True):
		super(Uart,self).__init__()
		self.log = open(log_file,'w') if log_file else open('test_log.log','w')
		self.comport = None
		self.is_print = is_print
		self.timeout = 0.01
		self.fifo = Queue.Queue(100)
		self.metux = metux
		self.stop_flag = stop_flag
		self.open_flag = False

	def input(self,msg):
		if self.comport:
			self.metux.acquire()
			self.fifo.queue.clear()
			self.comport.write(msg)
			self.metux.release()
			return 1
		else:
			print('Pls create port')
			return 0

	def open_key_test(self):
		self.comport.write("**\n")
		self.open_flag = True
		time.sleep(0.5)

	def close_key_test(self):
		self.comport.write("##\n")
		self.open_flag = False
		time.sleep(0.5)

	def simulate_key_input(self,key_value,key_down_time = 0.3):
		self.open_key_test() if not self.open_flag else None
		self.metux.acquire()
		self.comport.write(key_value + '0')
		time.sleep(key_down_time)
		self.comport.write(key_value + '1')
		self.metux.release()
		self.log.write('[pylog]:'+key_value+'\n')
		self.log.flush()

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
			print('No log file')

	def expect(self,pattern_list,timeout):
		uart_timeout = 0.1
		cnt = int((timeout+uart_timeout)/uart_timeout)
		timing = 0                                      
		try:
			pattern_list + []
		except:
			print("Error: expect need a list in arg pattern")
			return (None,False)
		pattern = re.compile("|".join(pattern_list))
		self.metux.acquire()
		for i in xrange(cnt):
			if stop_flag.is_set(): break
			while 1:
				if self.fifo.empty(): break
				data = self.fifo.get()
				tgt = pattern.search(data)
				if data and tgt:
					for j, ptn in enumerate(pattern_list):
						if ptn in tgt.group(0):
							self.fifo.queue.clear()
							self.metux.release()
							return j,uart_timeout*i
			time.sleep(uart_timeout)
			if int(uart_timeout*i) != timing:
				sys.stdout.write("timing: %ds\r" %(int(uart_timeout*i)))
				sys.stdout.flush()
				timing = int(uart_timeout*i)
		self.metux.release()
		self.fifo.queue.clear()
		return (None,False)

	def createPort(self, port = None, baud = 115200, time_out = 0.1):
		if not port:
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
						else:  print('No device')
			else:
				print("No port")
				sys.exit(0)
		print 'current port name:',port
		self.comport = Serial(port, baud, timeout=time_out)
		self.timeout = time_out
		if self.comport.isOpen():
			return 1
		else:
			print("create port fail")
			sys.exit(1)

	def run(self):
		try:
			while 1:
				if self.stop_flag.is_set(): raise TestEndException
				line = self.comport.readline().strip()
				self.fifo.get() if self.fifo.full() else None
				if line:
					self.fifo.put(line)
					if self.log:
						print >>self.log,line
						self.log.flush()
					if self.is_print: print(line)
		except TestEndException:
			self.__cancel()
		except Exception,e:
			print e,'Serial Exception.Pls check serial'
			self.__cancel()

	def __cancel(self):
		self.metux.acquire()
		if self.log:
			self.log.flush()
			self.log.close()
		self.comport.close()
		self.stop_flag.set()
		self.metux.release()


class UartController(threading.Thread):
	def __init__(self,uart):
		super(UartController,self).__init__()
		self.uart = uart

	def exit_serial(self):
		stop_flag.set()
		sys.exit(0)

	def __parse_input(self,text):
		if 'exit' in text: 
			self.exit_serial()
		elif 'is_print' in text:
			value = text.split('=')[1].strip()
			if eval(value):
				self.uart.is_print = True
			else:
				self.uart.is_print = False
		elif text:
			self.uart.input(text+'\n')

	def run(self):
		try:
			self.uart.start() if not self.uart.is_alive() else None
			while 1:
				if stop_flag.is_set(): break
				msg = raw_input('')
				self.__parse_input(msg)
		except Exception,e:
			print e,'Pls check serial port'
			self.exit_serial()

class MyTimer(object):
	"""docstring for MyTimer"""
	def __init__(self, delay_time,callback,*args,**kwargs):
		super(MyTimer, self).__init__()
		self.__timer = None
		self.__delay_time = delay_time
		self.__callback = callback
		self.__args = args
		self.__kwargs = kwargs

	def exce_callback(self):
		if stop_flag.is_set(): 
			self.cancel()
			return
		self.__callback(*self.__args,**self.__kwargs)
		self.__timer = threading.Timer(self.__delay_time,self.exce_callback)
		self.__timer.start()

	def start(self,start_time = 0):
		self.__timer = 	threading.Timer(start_time,self.exce_callback)
		self.__timer.start()

	def cancel(self):
		self.__timer.cancel()
		self.__timer = None


def check_crane_status(uart):
	print('\n++++++ check crane status      +++++\n')
	if uart:
		uart.input('\n')
		uart.input('check_status\n')
		res,timeout = uart.expect(['check_status'],2)
		if not timeout:
			print('\n++++++ check crane status fail +++++\n')
			stop_flag.set()
		else:
			print ('\n++++++ check crane status pass +++++\n')


def WAIT_ALL_THREAD_END():
	while 1:
		alive = False
		for th in threading.enumerate():
			if th.getName() is 'MainThread': continue
			alive = alive or th.isAlive()
		if not alive: return

if __name__ == "__main__":

	signal.signal(signal.SIGINT, signal_handler)
	signal.signal(signal.SIGTERM, signal_handler)
	abs_dir = os.path.dirname(os.path.abspath(__file__))
	logfile_dir = os.path.join(abs_dir,'log')
	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('-f','--log_file',default = 'test_log',help='log path or log_file -- example: ./test_log')
	arg_parser.add_argument('-c','--cmd_file',default = '',help = 'if need autocmd.cfg ,input -c ./tool/auto_uart/autocmd.cfg')
	argv = arg_parser.parse_args()

	os.mkdir(logfile_dir) if not os.path.exists(logfile_dir) else None
	now = datetime.datetime.today()
	date = now.strftime("%d_%h_%H-%M-%S")
	log_file = os.path.join(logfile_dir,argv.log_file+"-"+date+'.log')
	uart = Uart(log_file)
	uart.createPort()
	uart_manager = UartController(uart)
	uart_manager.start()

	timer = MyTimer(3,check_crane_status,uart)

	key_value = ['P','^','V','<','>','M','S','1','2','3','4','5','6','7','8','9','0','*','#','[',']']
	try:
		timer.start(1)
		uart.open_key_test()
		if argv.cmd_file:
			assert os.path.exists(argv.cmd_file)
			with open(argv.cmd_file) as file_obj:
				file_text = '|'.join(file_obj.readlines())
				file_text = '|' + re.sub('\n','',file_text)
			cmd_set = re.findall('\|AUTOTEST_KEY@\((.*?),(.*?)\)',file_text)
			cnt = re.findall('\|CNT@\((.*?)\)',file_text)
			count = int(cnt[0]) if cnt else 1
			for i in range(count):
				print "\n","*"*50 
				print "running cnt: %s"%i
				print "*"*50
				uart.log.write("running cnt: %s\n"%i)
				for cmd,timeout in cmd_set:
					if stop_flag.is_set(): raise TestEndException
					if 'CMD-' in cmd:
						uart.input(cmd.replace('CMD-','')+'\n')
						time.sleep(eval(timeout))
						print '\n***intput cmd:',cmd.replace('CMD-','')
						continue
					for send_c in cmd.replace(' ',''):
						uart.simulate_key_input(send_c)
						print '\n***intput key: %s\n'%send_c
						time.sleep(eval(timeout))
			else:
				uart.close_key_test()
		else:
			monkey_cmd_log = os.path.join(logfile_dir,'monkey_cmd-%s.log'%(date))
			monkey_cmd_log = open(monkey_cmd_log,'w')
			while 1:
				if stop_flag.is_set(): raise TestEndException
				send_c = random.choice(key_value)
				uart.simulate_key_input(send_c)
				print '\n***intput key: %s\n'%send_c
				monkey_cmd_log.write(send_c)
				monkey_cmd_log.flush()
				time.sleep(0.5)
		WAIT_ALL_THREAD_END()
	except TestEndException,e:
		stop_flag.set()
		print e
		sys.exit(1)
	except Exception,e:
		stop_flag.set()
		print e
		sys.exit(1)
 
