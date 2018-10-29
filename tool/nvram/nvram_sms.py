#! /usr/bin/env python
from nvram_cfg import *
from nvram_util import *

class SmsInfo(InfoObject):
	"""docstring for SmsInfo"""
	def __init__(self):
		super(SmsInfo, self).__init__('<10B12s5Bi')
		self.vp = None
		self.pid = None
		self.dcs = None
		self.mti = None
		self.ssr = None
		self.bearer = None
		self.bSimChange = None
		self.bReserverd = ' '*12
		self.mr = None
		self.rp = None
		self.nNumber = None
		self.udhi = None
		self.rd = None
		self.vpf = None
		self.nSaveToSimFlag = None
		self.nIndex = None
		self.bDefault = None

	def GetInfo(self,data):
		(self.vp, self.pid, self.dcs, self.mti, self.ssr, \
		self.bearer, self.bSimChange, self.bReserverd, \
		self.mr, self.rp, self.nNumber, self.udhi, self.rd, \
		self.vpf, self.nSaveToSimFlag, self.nIndex, \
		self.bDefault) = struct.unpack(self.struct_fmt,data)

	def print_info(self):
		# print 'size:',self.size
		print "vp:",self.vp
		print 'pid:',self.pid
		print 'dcs:',self.dcs
		print 'mti:',self.mti
		print 'ssr:',self.ssr
		print 'bearer:',self.bearer
		print 'bSimChange:',self.bSimChange
		print 'bReserverd:',self.bReserverd
		print 'mr:',self.mr
		print 'nNumber:',self.nNumber
		print 'udhi:',self.udhi
		print 'rd:',self.rd
		print 'vpf:',self.vpf
		print 'nSaveToSimFlag:',self.nSaveToSimFlag
		print 'nIndex:',self.nIndex
		print 'bDefault:',self.bDefault

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