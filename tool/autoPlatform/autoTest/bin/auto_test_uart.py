#!/usr/bin/env python
from serial.tools.list_ports import comports
import serial
from serial import Serial
import threading 
import platform
import sys,re,time,os
import Queue
import pexpect,getpass

def get_sudo_password():
	proc = pexpect.spawn("sudo ls")
	while 1:
		index = proc.expect([r'\[sudo\] password for',r'Sorry, try again',"sudo: 3 incorrect password attempts", \
								pexpect.EOF, pexpect.TIMEOUT], timeout=1)
		if index == 0:
			password = getpass.getpass("input sudo password:")
			proc.sendline(password)
		if index == 1:
			print "Sorry, try again."
		if index == 2:
			print 'sudo: 3 incorrect password attempts'
			proc.close(force=True)
			sys.exit(1)
		if index == 3:
			proc.close(force=True)
			return password

SUDO_PASSWORD = get_sudo_password()
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
		self.timeout = 0.01
		self.fifo = Queue.Queue(100)
		self.metux = threading.Lock()

	def input(self,msg):
		self.metux.acquire()
		if self.comport:
			self.fifo.queue.clear()
			self.case_end_flag = False
			self.last_log = None
			self.result_log = []
			self.comport.write(msg+'\n')
		else:
			print 'Pls create port'
		self.metux.release()


	def expect(self,pattern_list,timeout):
		uart_timeout = 0.1
		cnt = int((timeout+uart_timeout)/uart_timeout)
		timing = 0
		try:
			pattern_list + []
		except:
			print "Error: expect need a list in arg pattern"
			return
		pattern = re.compile("|".join(pattern_list))
		for i in xrange(cnt):
			self.metux.acquire()
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
			self.metux.release()
			time.sleep(uart_timeout)
			if int(uart_timeout*i) != timing:
				sys.stdout.write("timing: %ds\r" %(int(uart_timeout*i)))
				sys.stdout.flush()
				timing = int(uart_timeout*i)
		return (None,False)

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
				port_list = [port for port in port_list if "ttyUSB" in port or "ttyACM" in port]
			elif "Windows" in platform_type:
				port_list = [list(port) for port in port_list]
				port_list = [port for port in port_list if "USB to UART Bridge" in port[1]]
			if port_list:
				port = port_list[0]
				proc = pexpect.spawn('sudo chmod 777 %s'%port)
				index = proc.expect([r'\[sudo\] password for',pexpect.EOF, pexpect.TIMEOUT], timeout=1)
				if index == 0:
					password = SUDO_PASSWORD if SUDO_PASSWORD else get_sudo_password()
					proc.sendline(password)
				# os.system('sudo chmod 777 %s'%port)
				print port
			else:
				print "No port"
				sys.exit(0)
		self.comport = Serial(port, baud, timeout=time_out)
		self.timeout = time_out
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
				self.metux.acquire()
				self.fifo.get() if self.fifo.full() else None
				self.fifo.put(line.lstrip()) if line.lstrip() else None
				if self.log and line:
					print >>self.log,line
					self.log.flush()
				self.metux.release()
				if line:
					self.last_log = line
					if 'AUTOTEST@' in self.last_log:
						match = re.search(r'AUTOTEST@.*?Result\[(.*?)\]:RetCode(\[.*?\])',self.last_log)
						if match:
							if match.group(1) == 'OK':
								self.result_log.append(match.group(1))
							else:
								self.result_log.append(match.group(1)+match.group(2))
					if 'Unknown command' in self.last_log:
						self.result_log.append(self.last_log.split('-')[0].strip())
					if 'ctest#' == line:
						self.case_end_flag = True if self.result_log else False
			except Exception,e:
				print e,'Serial Exception.Pls check serial'
				stop_flag.set()
				break
		self.comport.close()
		if self.log:
			self.log.flush()
			self.log.close()

