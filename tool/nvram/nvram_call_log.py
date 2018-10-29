#! /usr/bin/env python
from nvram_cfg import *
from nvram_util import *

class CallLogEntryInfo(InfoObject):
	"""docstring for PhoneBookInfo"""
	def __init__(self):
		super(CallLogEntryInfo, self).__init__('%ds%ds%dsBI'%(NumberStruct().size,NameStruct().size,RtcTimeStruct().size)) #BI,5 bytes c code  alignment,total 8 Bytes
		self.tel = NumberStruct()
		self.tel_data = None
		self.alpha_id = NameStruct()
		self.alpha_id_data = None
		self.time = RtcTimeStruct()
		self.time_data = None
		self.count = None
		self.call_duration = None
	def GetInfo(self,data):
		(self.tel_data,self.alpha_id_data,self.time_data,self.count,self.call_duration) = struct.unpack(self.struct_fmt,data)
		self.tel.GetInfo(self.tel_data)
		self.alpha_id.GetInfo(self.alpha_id_data)
		self.time.GetInfo(self.time_data)

	def print_info(self):
		# print 'size:',self.size
		self.tel.print_info()
		self.alpha_id.print_info()
		self.time.print_info()
		print "count:",hex(self.count)
		print "call_duration:",hex(self.call_duration)
		# raw_input()


class CallLogInfo(InfoObject):
	"""docstring for PhoneBookInfo"""
	def __init__(self):
		super(CallLogInfo, self).__init__('<%ds%ds3BB%ds'%(LocalParaHDR().size,ResultStruct().size,CallLogEntryInfo().size*CALL_LOG_MAX_RECORD*SIM_NUMBER))
		self.local_para = LocalParaHDR()
		self.local_para_data = None
		self.result = ResultStruct()
		self.result_data = None
		self.no_list = None
		self.type = None
		self.more_data = None
		self.reserved = None #3B,3 bytes c code  alignment 4 Bytes,total 4 Bytes,plus 1 byte
		self.list = [CallLogEntryInfo() for i in range(CALL_LOG_MAX_RECORD*SIM_NUMBER)]
		self.list_data = None

	def GetInfo(self,data):
		(self.local_para_data,self.result_data,self.no_list,\
		self.type,self.more_data,self.reserved,self.list_data) = struct.unpack(self.struct_fmt,data)
		self.result.GetInfo(self.result_data)
		self.local_para.GetInfo(self.local_para_data)
		for i,entry in enumerate(self.list):
			entry.GetInfo(self.list_data[i*entry.size:(i+1)*entry.size])

	def print_info(self):
		# print 'size:',self.size
		self.local_para.print_info()
		self.result.print_info()
		print 'no_list:',self.no_list
		print 'type:',self.type
		print 'more_data:',self.more_data
		entry_cnt = self.no_list if self.no_list < len(self.list) else len(self.list)
		for entry in self.list[:entry_cnt]:
			entry.print_info()


def PrintCallLogInfo(nvram,n = 1):
	'''print CallLogInfo'''
	print "****************"
	print 'call log:'
	nFieldID,nRecordID = NVRAM_UNIT[1] ## 0 - call log
	for i, data in enumerate(nvram.DatabaseFormat[nFieldID]):
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