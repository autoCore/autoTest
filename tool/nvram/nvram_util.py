#! /usr/bin/env python
import struct,copy
from nvram_cfg import *


class InfoObject(object):
	"""basic info class"""
	def __init__(self,struct_fmt):
		self.struct_fmt = struct_fmt

	@property
	def size(self):
		return struct.calcsize(self.struct_fmt)

class ResultStruct(InfoObject):
	def __init__(self):
		super(ResultStruct, self).__init__('@BH')#'BH' 1+2 bytes c code 2 Bytes alignment,total 4 Bytes
		self.flag = None
		self.cause = None

	def GetInfo(self,data):
		(self.flag,self.cause) = struct.unpack(self.struct_fmt,data)

	def print_info(self):
		# print 'size:',self.size
		print "result flag:",hex(self.flag)
		print "result cause:",hex(self.cause)

class LocalParaHDR(InfoObject):
	def __init__(self):
		super(LocalParaHDR, self).__init__('@BH')#'BH' 1+2 bytes c code 2 Bytes alignment,total 4 Bytes
		self.ref_count = None
		self.msg_len = None

	def GetInfo(self,data):
		(self.ref_count,self.msg_len) = struct.unpack(self.struct_fmt,data)

	def print_info(self):
		# print 'size:',self.size
		print "ref_count:",hex(self.ref_count)
		print "msg_len:",hex(self.msg_len)

class NumberStruct(InfoObject):
	def __init__(self):
		super(NumberStruct, self).__init__('<2B41s')
		self.type = None
		self.length = None
		self.number = None

	def GetInfo(self,data):
		(self.type,self.length,self.number) = struct.unpack(self.struct_fmt,data)

	def print_info(self):
		# print 'size:',self.size
		print "number type:",hex(self.type)
		print "number length:",self.length
		print "number:",self.number

class NumBcdStruct(InfoObject):
	def __init__(self):
		super(NumBcdStruct, self).__init__('<B41s')
		self.addr_length = None
		self.addr_bcd = None
		self.tel_length = None
		self.tel_type = None
		self.tel_str = None

	def __BCDToStr(self,data):
		tmp = ''
		for x in data:
			if int(x & 0xff) == 0xff:
				break
			tmp += str(int(x & 0xf))
			if int((x>>4) & 0xf) == 0xf:
				break
			else:
				tmp += str(int((x>>4) & 0xf))
		return tmp

	def GetInfo(self,data):
		(self.addr_length,self.addr_bcd) = struct.unpack(self.struct_fmt,data)
		self.tel_type = ord(self.addr_bcd[0])
		data = [ord(_str) for _str in self.addr_bcd[1:self.addr_length+1]]
		self.tel_str = self.__BCDToStr(data)
		self.tel_length = len(self.tel_str)

	def print_info(self):
		# print 'size:',self.size
		print "tel_type:",hex(self.tel_type)
		print "tel_length:",hex(self.tel_length)
		print 'tel:',self.tel_str

class NameStruct(InfoObject):
	def __init__(self):
		super(NameStruct, self).__init__('<BB32s')
		self.name_length = None
		self.name_dcs = None
		self.name = None

	def GetInfo(self,data):
		(self.name_length,self.name_dcs,self.name) = struct.unpack(self.struct_fmt,data)

	def print_info(self):
		# print 'size:',self.size
		print "name_length:",self.name_length
		print "name_dcs:",hex(self.name_dcs)
		# print 'name:',self.name[:self.name_length].decode("utf8","ignore")
		print 'name:',self.name[:self.name_length]

class RtcTimeStruct(InfoObject):
	def __init__(self):
		super(RtcTimeStruct, self).__init__('<BBBBBBB')
		self.rtc_sec = None
		self.rtc_min = None
		self.rtc_hour = None
		self.rtc_day = None
		self.rtc_mon = None
		self.rtc_wday = None
		self.rtc_year = None

	def GetInfo(self,data):
		(self.rtc_sec,self.rtc_min,self.rtc_hour,self.rtc_day,self.rtc_mon,self.rtc_wday,self.rtc_year) = struct.unpack(self.struct_fmt,data)

	@staticmethod
	def GetWeekday(wday):
		return ['SUN','MON','TUS','WED','THU','FRI','SAT','Error'][wday if wday < 7 else 7]

	def print_info(self):
		# print 'size:',self.size
		wday = int(self.rtc_wday)
		print "time: %d-%d-%d %d:%d:%d [%s]"\
		%(self.rtc_year,self.rtc_mon,self.rtc_day,self.rtc_hour,self.rtc_min,self.rtc_sec,self.GetWeekday(wday))

class NvramRecordCtr(InfoObject):
	def __init__(self):
		super(NvramRecordCtr, self).__init__('<4I')
		self.iStatus = NVRAM_STATUS_FREE
		self.iId = NVRAM_FREE_ID   
		self.iInd = NVRAM_INVALID_IND
		self.iCrc = NVRAM_INVALID_CRC

	def GetInfo(self,data):
		(self.iStatus,self.iId,self.iInd,self.iCrc) = struct.unpack(self.struct_fmt,data)

	def print_info(self):
		print "iStatus:",hex(self.iStatus)
		print 'iId:',hex(self.iId)
		print 'iInd:',hex(self.iInd)
		print 'iCrc:',hex(self.iCrc)


class NvramRecordInfo(InfoObject):
	"""docstring for NvramRecordInfo"""
	def __init__(self):
		super(NvramRecordInfo, self).__init__('<%ds%ds'%(NvramRecordCtr().size,NVRAM_DATA_SIZE))
		self.sCtr = NvramRecordCtr()
		self.sCtr_data = None
		self.pData = None

	def GetInfo(self,data):
		(self.sCtr_data,self.pData) = struct.unpack(self.struct_fmt, data)
		self.sCtr.GetInfo(self.sCtr_data)

	def print_info(self):
		print "iStatus:",hex(self.iStatus)
		print 'iId:',hex(self.iId)
		print 'iInd:',hex(self.iInd)
		print 'iCrc:',hex(self.iCrc)
		print "pData:", ' '.join([hex(ord(_str)) for _str in self.pData])

class NvramNodeInfo(InfoObject):
	"""docstring for NvramNodeInfo"""
	def __init__(self):
		super(NvramNodeInfo, self).__init__('<2I')
		self.iId = None
		self.iSize = None

	def GetInfo(self,data):
		(self.iId,self.iSize) = struct.unpack(self.struct_fmt, data)

	def print_info(self):
		print "iId:",hex(self.iId)
		print 'iSize:',hex(self.iSize)

class NvramHeaderInfo(InfoObject):
	"""docstring for NvramHeaderInfo"""
	def __init__(self):
		super(NvramHeaderInfo, self).__init__('<11I20s')
		self.iMagic = NVRAM_MAGIC
		self.iVer = NVRAM_VERSION   
		self.iDevSize = None
		self.iHOffs = NVRAM_H_BASE_ADDR
		self.iHSize = None
		self.iNDOffs = NVRAM_NDT_BASE_ADDR
		self.iNDSize = NVRAM_NDT_SIZE
		self.iROffs = NVRAM_R_BASE_ADDR
		self.iRSize = NVRAM_R_SIZE
		self.iRCount = None
		self.iCrc = None
		self.szServed = None

	def GetInfo(self,data):
		(self.iMagic,self.iVer, self.iDevSize,self.iHOffs,self.iHSize,\
		self.iNDOffs,self.iNDSize,self.iROffs,self.iRSize,self.iRCount,\
		self.iCrc,self.szServed) = struct.unpack(self.struct_fmt, data)

	def print_info(self):
		print "iMagic:",hex(self.iMagic)
		print 'iVer:',hex(self.iVer)
		print 'iDevSize:',hex(self.iDevSize)
		print 'iHOffs:',hex(self.iHOffs)
		print 'iHSize:',hex(self.iHSize)
		print 'iNDOffs:',hex(self.iNDOffs)
		print 'iNDSize:',hex(self.iNDSize)
		print 'iROffs:',hex(self.iROffs)
		print 'iRSize:',hex(self.iRSize)
		print 'iRCount:',self.iRCount
		print 'iCrc:',hex(self.iCrc)
		# print "szServed:", ' '.join([hex(ord(_str)) for _str in self.szServed])



class StructParse(InfoObject):
	"""docstring for StructParse"""
	def __init__(self):
		super(StructParse, self).__init__()

	def ReadInfo(self,struct_fmt,file_name,offset):
		try:
			file_obj = open(file_name,'rb')
			file_obj.seek(offset,0)
			data_buffer = file_obj.read(struct.calcsize(struct_fmt))
			file_obj.close()
			return struct.unpack(struct_fmt,data_buffer)
		except Exception,e:
			print e

	def WriteInfo(self,file_name,struct_fmt,offset,*value):
		try:
			file_obj = open(file_name,'rb')
			data_buffer = file_obj.read()
			data_buffer = data_buffer[:offset]+struct.pack(struct_fmt,*value) + data_buffer[(offset+struct.calcsize(struct_fmt)):]
			file_obj.close()
			file_obj = open(file_name,'wb')
			file_obj.write(data_buffer)
			file_obj.flush()
			file_obj.close()
		except Exception,e:
			print e

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