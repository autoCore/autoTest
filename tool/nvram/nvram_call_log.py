#! /usr/bin/env python
from nvram_cfg import *
from nvram_util import *

class CallLogEntryInfo(InfoObject):
	"""docstring for PhoneBookInfo"""
	def __init__(self):
		super(CallLogEntryInfo, self).__init__('%ds%ds%dsBI'%(NumberStruct().size,NameStruct().size,RtcTimeStruct().size)) #BI,5 bytes c code  alignment,total 8 Bytes
		self.addAttr('tel',NumberStruct())
		self.addAttr('alpha_id',NameStruct())
		self.addAttr('time',RtcTimeStruct())
		self.addAttr('count')
		self.addAttr('call_duration')


class CallLogInfo(InfoObject):
	"""docstring for PhoneBookInfo"""
	def __init__(self):
		super(CallLogInfo, self).__init__('<%ds%ds3BB'%(LocalParaHDR().size,ResultStruct().size)+('%ds'%CallLogEntryInfo().size)*CALL_LOG_MAX_RECORD*SIM_NUMBER)
		self.addAttr('local_para',LocalParaHDR())
		self.addAttr('result',ResultStruct())
		self.addAttr('no_list')
		self.addAttr('type')
		self.addAttr('more_data')
		self.addAttr('reserved')
		self.list = []
		for i in range(CALL_LOG_MAX_RECORD*SIM_NUMBER):
			attr = 'CallLogEntryInfo_%s'%i
			self.addAttr(attr,CallLogEntryInfo())
			self.list.append(getattr(self, attr, None))

	def print_info(self):
		print('size:'+ str(self.size))
		self.local_para.print_info()
		self.result.print_info()
		print('no_list: '+str(self.no_list))
		print('type:'+str(self.type))
		print('more_data:'+str(self.more_data))
		entry_cnt = self.no_list if self.no_list < len(self.list) else len(self.list)
		for entry in self.list[:entry_cnt]:
			entry.print_info()


def PrintCallLogInfo(nvram,n = 1):
	'''print CallLogInfo'''
	print("CallLogInfo size:"+str(CallLogInfo().size))
	print("*"*18)
	print('call log:')
	nFieldID,nRecordID = NVRAM_UNIT[1] ## 0 - call log
	for i, data in enumerate(nvram.DatabaseFormat[nFieldID]):
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