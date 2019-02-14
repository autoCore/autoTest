#! /usr/bin/env python
from nvram_cfg import *
from nvram_util import *

class AlarmInfo(InfoObject):
	def __init__(self):
		super(AlarmInfo, self).__init__('<14B5sBB36s')
		self.addAttr('ONTIME')
		self.addAttr('before_alarm')
		self.addAttr('ACTIVATION')
		self.addAttr('REPEATS')
		self.addAttr('ALM_TIME_H')
		self.addAttr('ALM_TIME_MIN')
		self.addAttr('WEEKLY')
		self.addAttr('TYPE')
		self.addAttr('TONE_ID')
		self.addAttr('VOL')
		self.addAttr('SNOOZE_DUR')
		self.addAttr('SNOOZE_REP')
		self.addAttr('AUTO_POWERRUP')
		self.addAttr('REG_ALARM')
		self.addAttr('REMINDER_PREQUENCY')
		self.addAttr('TYPE_REPEAT')
		self.addAttr('SNOOZE_MAX')
		self.addAttr('ALARM_NAME')


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