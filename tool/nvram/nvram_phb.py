#! /usr/bin/env python
from nvram_cfg import *
from nvram_util import *

class PhoneBookNumberStruct(InfoObject):
	def __init__(self):
		super(PhoneBookNumberStruct, self).__init__('<B%ds'%(40*2))
		self.addAttr('type')
		self.addAttr('number')

	def print_info(self):
		# print 'size:',self.size
		print("number type: "+hex(self.type))
		print('number: '+self.number.split('\x00')[0])

class PhoneBookInfo(InfoObject):
	"""docstring for PhoneBookInfo"""
	def __init__(self):
		super(PhoneBookInfo, self).__init__('<H%ds%ds'%(NameStruct().size,NumBcdStruct().size))
		self.addAttr('nAppIndex')
		self.addAttr('alpha_id',NameStruct())
		self.addAttr('tel',NumBcdStruct())
		self.next_nFieldID = NVRAM_EF_PHB_SOMEFIELDS_LID


class PhoneBookOptionalField(InfoObject):
	"""docstring for PhoneBookOptionalField"""
	def __init__(self):
		super(PhoneBookOptionalField, self).__init__('<BB'+('%ds'%PhoneBookNumberStruct().size)*MAX_PB_NUMBER_CNT+'1sHHH')
		self.addAttr('defNum')
		self.addAttr('shareContact')
		for i in range(MAX_PB_NUMBER_CNT):
			self.addAttr('phoneNum_%d'%i, PhoneBookNumberStruct())
		self.addAttr('reserved')
		self.addAttr('picId')
		self.addAttr('ringId')
		self.addAttr('groupId')



def NVRAM_PhoneInfoAppIndex_Is_VALID(aAppIndex):
	if aAppIndex and aAppIndex != 65535:
		return True
	else:
		return False

def PrintPhoneBookInfo(nvram,n = 1):
	'''print PhoneBookInfo'''
	print('PhoneBookInfo:')
	nFieldID,nRecordID = NVRAM_UNIT[0] ## 0 - PhoneBookInfo
	for i, data in enumerate(nvram.DatabaseFormat[nFieldID]):
		print("*"*18)
		data.print_info()
		if NVRAM_PhoneInfoAppIndex_Is_VALID(data.nAppIndex):
			data = nvram.DatabaseFormat[data.next_nFieldID][data.nAppIndex - 1]
			print("*"*18)
			data.print_info()
		if i == n - 1: break

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