#! /usr/bin/env python
from nvram_cfg import *
from nvram_util import *


class PhoneBookNumberStruct(InfoObject):
    _fields_ = [('type', c_ubyte), ('number', c_ubyte*(40*2))]

    def print_info(self):
        # print 'size:',self.size
        print("number type: "+hex(self.type))
        print('number: '+c_ubyte_Array_To_string(self.number).split('\x00')[0])


class PhoneBookInfo(InfoObject):
    """docstring for PhoneBookInfo"""
    _fields_ = [('nAppIndex', c_ushort), ('alpha_id', NameStruct), ('tel', NumBcdStruct)]

    def __init__(self):
        self.next_nFieldID = NVRAM_EF_PHB_SOMEFIELDS_LID


class PhoneBookOptionalField(InfoObject):
    """docstring for PhoneBookOptionalField"""
    _fields_ = [('defNum', c_ubyte), ('shareContact', c_ubyte)] + \
               [('phoneNNum_%d' % i, PhoneBookNumberStruct) for i in range(MAX_PB_NUMBER_CNT)] + \
               [('picId', c_ushort), ('ringId', c_ushort), ('groupId', c_ushort)]


def NVRAM_PhoneInfoAppIndex_Is_VALID(aAppIndex):
    if aAppIndex and aAppIndex != 65535:
        return True
    else:
        return False


def PrintPhoneBookInfo(nvram, n=1):
    '''print PhoneBookInfo'''
    print("*"*18)
    print('PhoneBookInfo:')
    nFieldID, nRecordID = NVRAM_UNIT[0]  # 0 - PhoneBookInfo
    for i, data in enumerate(nvram.DatabaseFormat[nFieldID]):
        print("*"*18)
        data.print_info()
        if NVRAM_PhoneInfoAppIndex_Is_VALID(data.nAppIndex):
            data = nvram.DatabaseFormat[data.next_nFieldID][data.nAppIndex - 1]
            print("*"*18)
            data.print_info()
        if i == n - 1:
            break
