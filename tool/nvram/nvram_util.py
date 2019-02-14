#! /usr/bin/env python
import struct,copy,re,traceback
from nvram_cfg import *

class InfoObject(object):
	"""basic info class"""
	def __init__(self,struct_fmt = '<I'):
		self.struct_fmt = struct_fmt
		self.attr_list = []

	def addAttr(self,attr,value = None):
		self.attr_list.append(attr)
		setattr(self,attr,value)

	@property
	def size(self):
		return struct.calcsize(self.struct_fmt)

	def GetInfo(self,data):
		attr_value = struct.unpack(self.struct_fmt,data)
		for attr,value in zip(self.attr_list,attr_value):
			attr_obj = getattr(self, attr, None)
			if isinstance(attr_obj,InfoObject):
				attr_obj.GetInfo(value)
			else:
				setattr(self,attr,value)

	def print_info(self):
		print('size: '+str(self.size))
		for attr in self.attr_list:
			attr_obj = getattr(self, attr, None)
			if isinstance(attr_obj,InfoObject):
				attr_obj.print_info()
			else:
				try:
					print(attr+": "+hex(attr_obj))
				except:
					print(attr+": "+attr_obj)


class ResultStruct(InfoObject):
	def __init__(self):
		super(ResultStruct, self).__init__('@BH')#'BH' 1+2 bytes c code 2 Bytes alignment,total 4 Bytes
		self.addAttr('flag')
		self.addAttr('cause')


class LocalParaHDR(InfoObject):
	def __init__(self):
		super(LocalParaHDR, self).__init__('@BH')#'BH' 1+2 bytes c code 2 Bytes alignment,total 4 Bytes
		self.addAttr('ref_count')
		self.addAttr('msg_len')


class NumberStruct(InfoObject):
	def __init__(self):
		super(NumberStruct, self).__init__('<2B41s')
		self.addAttr('type')
		self.addAttr('length')
		self.addAttr('number')

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
		print("tel_type: "+hex(self.tel_type))
		print("tel_length: "+hex(self.tel_length))
		print('tel: '+self.tel_str)

class NameStruct(InfoObject):
	def __init__(self):
		super(NameStruct, self).__init__('<BB32s')
		self.addAttr('name_length')
		self.addAttr('name_dcs')
		self.addAttr('name')


	def print_info(self):
		# print 'size:',self.size
		print("name_length: "+str(self.name_length))
		print("name_dcs: "+hex(self.name_dcs))
		# print('name: '+self.name[:self.name_length].decode("utf8","ignore"))
		print('name: '+str(self.name[:self.name_length]))

class RtcTimeStruct(InfoObject):
	def __init__(self):
		super(RtcTimeStruct, self).__init__('<7B')
		self.addAttr('rtc_sec')
		self.addAttr('rtc_min')
		self.addAttr('rtc_hour')
		self.addAttr('rtc_day')
		self.addAttr('rtc_mon')
		self.addAttr('rtc_wday')
		self.addAttr('rtc_year')

	@staticmethod
	def GetWeekday(wday):
		return ['SUN','MON','TUS','WED','THU','FRI','SAT','Error'][wday if wday < 7 else 7]

	def print_info(self):
		# print 'size:',self.size
		wday = int(self.rtc_wday)
		print("time: %d-%d-%d %d:%d:%d [%s]"\
		%(self.rtc_year,self.rtc_mon,self.rtc_day,self.rtc_hour,self.rtc_min,self.rtc_sec,self.GetWeekday(wday)))

class NvramRecordCtr(InfoObject):
	def __init__(self):
		super(NvramRecordCtr, self).__init__('<4I')
		self.addAttr('iStatus',NVRAM_STATUS_FREE)
		self.addAttr('iId',NVRAM_FREE_ID)
		self.addAttr('iInd',NVRAM_INVALID_IND)
		self.addAttr('iCrc',NVRAM_INVALID_CRC)


class NvramRecordInfo(InfoObject):
	"""docstring for NvramRecordInfo"""
	def __init__(self):
		super(NvramRecordInfo, self).__init__('<%ds%ds'%(NvramRecordCtr().size,NVRAM_DATA_SIZE))
		self.addAttr('sCtr',NvramRecordCtr())
		self.addAttr('pData')

	def print_info(self):
		self.sCtr.print_info()
		print("pData: "+' '.join([hex(ord(_str)) for _str in self.pData]))


class NvramNodeInfo(InfoObject):
	"""docstring for NvramNodeInfo"""
	def __init__(self):
		super(NvramNodeInfo, self).__init__('<2I')
		self.addAttr('iId')
		self.addAttr('iSize')


class NvramHeaderInfo(InfoObject):
	"""docstring for NvramHeaderInfo"""
	def __init__(self):
		super(NvramHeaderInfo, self).__init__('<11I20s')
		self.addAttr('iMagic',NVRAM_MAGIC)
		self.addAttr('iVer',NVRAM_VERSION)
		self.addAttr('iDevSize')
		self.addAttr('iHOffs',NVRAM_H_BASE_ADDR)
		self.addAttr('iHSize')
		self.addAttr('iNDOffs',NVRAM_NDT_BASE_ADDR)
		self.addAttr('iNDSize',NVRAM_NDT_SIZE)
		self.addAttr('iROffs',NVRAM_R_BASE_ADDR)
		self.addAttr('iRSize',NVRAM_R_SIZE)
		self.addAttr('iRCount')
		self.addAttr('iCrc')
		self.addAttr('szServed')



class StructParse(object):
	def ReadInfo(self,file_name,struct_fmt,offset):
		try:
			file_obj = open(file_name,'rb')
			file_obj.seek(offset,0)
			data_buffer = file_obj.read(struct.calcsize(struct_fmt))
			file_obj.close()
			return struct.unpack(struct_fmt,data_buffer)
		except:
			traceback.print_exc()

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
		except:
			traceback.print_exc()
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