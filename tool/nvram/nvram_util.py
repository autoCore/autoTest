#! /usr/bin/env python
import struct
from nvram_cfg import *

from ctypes import *


def c_ubyte_Array_To_string(Array):
    cnt = sizeof(Array)
    strings, = struct.unpack('<%ss' % cnt, memoryview(Array))
    return strings


class InfoObject(Structure):
    """basic info class"""

    def GetInfo(self, buf):
        memmove(addressof(self), buf, sizeof(self))

    @property
    def size(self):
        return sizeof(self)

    def print_info(self):
        # print('size: '+str(self.size))
        for attr, __ in self._fields_:
            attr_obj = getattr(self, attr, None)
            if isinstance(attr_obj, InfoObject):
                attr_obj.print_info()
            else:
                try:
                    print(attr+": "+hex(attr_obj))
                except:
                    print(attr+": %r" % str(attr_obj))


class NvramHeaderInfo(InfoObject):
    """docstring for NvramHeaderInfo"""
    _fields_ = [('iMagic', c_uint), ('iVer', c_uint), ('iDevSize', c_uint), ('iHOffs', c_uint), ('iHSize', c_uint), ('iNDOffs', c_uint),
                ('iNDSize', c_uint), ('iROffs', c_uint), ('iRSize', c_uint), ('iRCount', c_uint), ('iCrc', c_uint), ('szServed', c_ubyte * 20)]

    def print_info(self):
        print('size: '+str(self.size))
        for attr, __ in self._fields_[:-1]:
            attr_obj = getattr(self, attr, None)
            print(attr+": "+hex(attr_obj))
        # print "szServed: ", c_ubyte_Array_To_string(self.szServed)


class NvramNodeInfo(InfoObject):
    """docstring for NvramNodeInfo"""
    _fields_ = [('iId', c_uint), ('iSize', c_uint)]


class NvramRecordCtr(InfoObject):
    _fields_ = [('iStatus', c_uint), ('iId', c_uint),
                ('iInd', c_uint), ('iCrc', c_uint)]


class NvramRecordInfo(InfoObject):
    """docstring for NvramRecordInfo"""
    _fields_ = [('sCtr', NvramRecordCtr), ('pData', c_ubyte*NVRAM_DATA_SIZE)]

    def print_info(self):
        self.sCtr.print_info()
        # print("pData: %r" % c_ubyte_Array_To_string(self.pData))


class ResultStruct(InfoObject):
    _fields_ = [('flag', c_ubyte), ('cause', c_ushort)]


class LocalParaHDR(InfoObject):
    _fields_ = [('ref_count', c_ubyte), ('msg_len', c_ushort)]


class NumberStruct(InfoObject):
    _fields_ = [('type', c_ubyte), ('length', c_ubyte), ('number', c_ubyte*41)]

    def print_info(self):
        print("type: %r" % self.type)
        print("length: %r" % self.length)
        print("number: "+c_ubyte_Array_To_string(self.number))


class NumBcdStruct(InfoObject):
    _fields_ = [('addr_length', c_ubyte), ('addr_bcd', c_ubyte*41)]

    def __BCDToStr(self, data):
        tmp = ''
        for x in data:
            if int(x & 0xff) == 0xff:
                break
            tmp += str(int(x & 0xf))
            if int((x >> 4) & 0xf) == 0xf:
                break
            else:
                tmp += str(int((x >> 4) & 0xf))
        return tmp

    def print_info(self):
        # print 'size:',self.size
        data = [_str for _str in self.addr_bcd[1:self.addr_length+1]]
        tel_str = self.__BCDToStr(data)
        print("tel_type: 0x%x" % self.addr_bcd[0])
        print("tel_length: "+hex(len(tel_str)))
        print('tel: '+tel_str)


class NameStruct(InfoObject):
    _fields_ = [('name_length', c_ubyte),
                ('name_dcs', c_ubyte), ('name', c_ubyte*32)]

    def print_info(self):
        # print 'size:',self.size
        print("name_length: "+str(self.name_length))
        print("name_dcs: "+hex(self.name_dcs))
        # print('name: '+c_ubyte_Array_To_string(self.name).decode("utf8","ignore"))
        print('name: ' + c_ubyte_Array_To_string(self.name))


class RtcTimeStruct(InfoObject):
    _fields_ = [('rtc_sec', c_ubyte), ('rtc_min', c_ubyte), ('rtc_hour', c_ubyte), ('rtc_day', c_ubyte),
                ('rtc_mon', c_ubyte), ('rtc_wday', c_ubyte), ('rtc_year', c_ubyte)]

    @staticmethod
    def GetWeekday(wday):
        return ['SUN', 'MON', 'TUS', 'WED', 'THU', 'FRI', 'SAT', 'Error'][wday if wday < 7 else 7]

    def print_info(self):
        # print 'size:',self.size
        wday = int(self.rtc_wday)
        print("time: %d-%d-%d %d:%d:%d [%s]"
              % (self.rtc_year, self.rtc_mon, self.rtc_day, self.rtc_hour, self.rtc_min, self.rtc_sec, self.GetWeekday(wday)))


class StructParse(object):
    def ReadInfo(self, file_name, struct_fmt, offset):
        try:
            file_obj = open(file_name, 'rb')
            file_obj.seek(offset, 0)
            data_buffer = file_obj.read(struct.calcsize(struct_fmt))
            file_obj.close()
            return struct.unpack(struct_fmt, data_buffer)
        except:
            traceback.print_exc()

    def WriteInfo(self, file_name, struct_fmt, offset, *value):
        try:
            file_obj = open(file_name, 'rb')
            data_buffer = file_obj.read()
            data_buffer = data_buffer[:offset]+struct.pack(
                struct_fmt, *value) + data_buffer[(offset+struct.calcsize(struct_fmt)):]
            file_obj.close()
            file_obj = open(file_name, 'wb')
            file_obj.write(data_buffer)
            file_obj.flush()
            file_obj.close()
        except:
            traceback.print_exc()


'''
Format  C Type              Python type         Standard size
x       pad byte            no value         
c       char                string of length 1  1 
b       signed char         integer             1 
B       unsigned char       integer             1 
?       _Bool               bool                1 
h       short               integer             2 
H       unsigned short      integer             2 
i       int                 integer             4   
I       unsigned int        integer             4 
l       long                integer             4
L       unsigned long       integer             4 
q       long long           integer             8 
Q       unsigned long long  integer             8
f       float               float               4
d       double              float               8
s       char[]              string       
p       char[]              string       
P       void *              integer             

Character   Byte order              Size        Alignment
@           native                  native      native
=           native                  standard    none
<           little-endian           standard    none
>           big-endian              standard    none
!           network (= big-endian)  standard    none
'''
'''

ctypes          type C type                     Python type
c_bool          _Bool                           bool (1)
c_char          char                            1-character string
c_wchar         wchar_t                         1-character unicode string
c_byte          char                            int/long
c_ubyte         unsigned char                   int/long
c_short         short                           int/long
c_ushort        unsigned short                  int/long
c_int           int                             int/long
c_uint          unsigned int                    int/long
c_long          long                            int/long
c_ulong         unsigned long                   int/long
c_longlong      __int64 or long long            int/long
c_ulonglong     (unsigned __int64 or unsigned long long)  int/long
c_float         float                           float
c_double        double                          float
c_longdouble    long double                     float
c_char_p        char * (NUL terminated)         string or None
c_wchar_p       wchar_t * (NUL terminated)      unicode or None
c_void_p        void *                          int/long or None
'''