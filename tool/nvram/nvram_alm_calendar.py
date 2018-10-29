#! /usr/bin/env python
from nvram_cfg import *
from nvram_util import *

class AlarmInfo(InfoObject):
	"""docstring for SmsInfo"""
	def __init__(self):
		super(SmsInfo, self).__init__('<8BHB')
		self.Hour = None
		self.Min = None
		self.State = None
		self.Freq = None
		self.Snooze = None
		self.Days = None
		self.Volume = None
		self.AudioOption = None
		self.AudioOptionValue = None
		self.SnoozeInterval = None

	def GetInfo(self,data):
		(self.Hour, self.Min, self.State, self.Freq, self.Snooze, \
		self.Days, self.Volume, self.AudioOption, \
		self.AudioOptionValue, self.SnoozeInterval) = struct.unpack(self.struct_fmt,data)

	def print_info(self):
		# print 'size:',self.size
		print "Hour:",self.Hour
		print 'Min:',self.Min
		print 'State:',self.State
		print 'Freq:',self.Freq
		print 'Snooze:',self.Snooze
		print 'Days:',self.Days
		print 'Volume:',self.Volume
		print 'AudioOption:',self.AudioOption
		print 'AudioOptionValue:',self.AudioOptionValue
		print 'SnoozeInterval:',self.SnoozeInterval

'''
Format 	C Type 				Python type 		Standard size
x 		pad byte 			no value 	  	 
c 		char 				string of length 1 	1 
b 		signed char 		integer 			1 
B 		unsigned char 		integer 			1 
? 		_Bool 				bool 				1 
h 		short		 		integer 			2 
H 		unsigned short 		integer 			2 
i 		int 				integer 			4 	
I 		unsigned int 		integer 			4 
l 		long 				integer 			4
L 		unsigned long 		integer 			4 
q 		long long 			integer 			8 
Q 		unsigned long long 	integer 			8
f 		float 				float 				4
d 		double 				float 				8
s 		char[] 				string 	  	 
p 		char[] 				string 	  	 
P 		void * 				integer 	  		

Character 	Byte order 				Size 		Alignment
@ 			native 					native 		native
= 			native 					standard 	none
< 			little-endian 			standard 	none
> 			big-endian 				standard 	none
! 			network (= big-endian) 	standard 	none
'''