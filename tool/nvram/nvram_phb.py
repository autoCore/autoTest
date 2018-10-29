#! /usr/bin/env python
from nvram_cfg import *
from nvram_util import *

class PhoneBookNumberStruct(InfoObject):
	def __init__(self):
		super(PhoneBookNumberStruct, self).__init__('<B%ds'%(40*2))
		self.type = 0
		self.number = None

	def GetInfo(self,data):
		(self.type,self.number) = struct.unpack(self.struct_fmt,data)

	def print_info(self):
		# print 'size:',self.size
		print "number type:",hex(self.type)
		print 'number:',self.number.split('\x00')[0]

class PhoneBookInfo(InfoObject):
	"""docstring for PhoneBookInfo"""
	def __init__(self):
		super(PhoneBookInfo, self).__init__('<H%ds%ds'%(NameStruct().size,NumBcdStruct().size))
		self.nAppIndex = 0
		self.alpha_id = NameStruct()
		self.alpha_id_data = None
		self.tel = NumBcdStruct()
		self.tel_data = None
		self.next_nFieldID = NVRAM_EF_PHB_SOMEFIELDS_LID

	def GetInfo(self,data):
		(self.nAppIndex,self.alpha_id_data,self.tel_data ) = struct.unpack(self.struct_fmt,data)
		self.alpha_id.GetInfo(self.alpha_id_data)
		self.tel.GetInfo(self.tel_data)

	def print_info(self):
		print "nAppIndex:",self.nAppIndex
		self.alpha_id.print_info()
		self.tel.print_info()

class PhoneBookOptionalField(InfoObject):
	"""docstring for PhoneBookOptionalField"""
	def __init__(self):
		super(PhoneBookOptionalField, self).__init__('<BB%ds1sHHH'%(PhoneBookNumberStruct().size*MAX_PB_NUMBER_CNT))
		self.defNum = None
		self.shareContact = None
		self.phoneNum_list = [PhoneBookNumberStruct() for i in range(MAX_PB_NUMBER_CNT)]
		self.phoneNum_data = None
		self.reserved = None # c code 2 Bytes alignment,total 252 Bytes
		self.picId = None
		self.ringId = None
		self.groupId = None

	def GetInfo(self,data):
		(self.defNum,self.shareContact,self.phoneNum_data,self.reserved,self.picId,self.ringId,self.groupId) = struct.unpack(self.struct_fmt,data)
		for i,phone_num in enumerate(self.phoneNum_list):
			phone_num.GetInfo(self.phoneNum_data[i*phone_num.size:(i+1)*phone_num.size])

	def print_info(self):
		print "defNum:",self.defNum
		print 'shareContact:',self.shareContact
		for i,phone_num in enumerate(self.phoneNum_list):
			phone_num.print_info()
		print 'picId:',hex(self.picId)
		print 'ringId:',hex(self.ringId)
		print 'groupId:',hex(self.groupId)


def NVRAM_PhoneInfoAppIndex_Is_VALID(aAppIndex):
	if aAppIndex and aAppIndex != 65535:
		return True
	else:
		return False

def PrintPhoneBookInfo(nvram,n = 1):
	'''print PhoneBookInfo'''
	print 'PhoneBookInfo:'
	nFieldID,nRecordID = NVRAM_UNIT[0] ## 0 - PhoneBookInfo
	for i, data in enumerate(nvram.DatabaseFormat[nFieldID]):
		print "****************" 
		data.print_info()
		if NVRAM_PhoneInfoAppIndex_Is_VALID(data.nAppIndex):
			data = nvram.DatabaseFormat[data.next_nFieldID][data.nAppIndex - 1]
			print "****************" 
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