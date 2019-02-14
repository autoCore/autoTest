#! /usr/bin/env python
from nvram_cfg import *
from nvram_util import *

class SmsInfo(InfoObject):
	"""docstring for SmsInfo"""
	def __init__(self):
		super(SmsInfo, self).__init__('<10B12s5Bi')
		self.addAttr(vp)
		self.addAttr(pid)
		self.addAttr(dcs)
		self.addAttr(mti)
		self.addAttr(ssr)
		self.addAttr(bearer)
		self.addAttr(bSimChange)
		self.addAttr(bReserverd)
		self.addAttr(mr)
		self.addAttr(rp)
		self.addAttr(nNumber)
		self.addAttr(udhi)
		self.addAttr(rd)
		self.addAttr(vpf)
		self.addAttr(nSaveToSimFlag)
		self.addAttr(nIndex)
		self.addAttr(bDefault)


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