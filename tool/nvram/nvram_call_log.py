#! /usr/bin/env python
from nvram_cfg import *
from nvram_util import *


class CallLogEntryInfo(InfoObject):
    """docstring for PhoneBookInfo"""
    _fields_ = [('tel', NumberStruct), ('alpha_id', NameStruct), ('time', RtcTimeStruct),
                ('count', c_ubyte), ('call_duration', c_uint)]


class CallLogInfo(InfoObject):
    """docstring for PhoneBookInfo"""
    _fields_ = [('local_para', LocalParaHDR), ('result', ResultStruct), ('no_list', c_ubyte),
                ('type', c_ubyte), ('more_data', c_ubyte)] + \
               [('CallLogEntryInfo_%s' % i, CallLogEntryInfo) for i in range(CALL_LOG_MAX_RECORD*SIM_NUMBER)]

    def print_info(self):
        print('size:' + str(self.size))
        self.local_para.print_info()
        self.result.print_info()
        print('no_list: '+str(self.no_list))
        print('type:'+str(self.type))
        print('more_data:'+str(self.more_data))
        entry_cnt = self.no_list
        for entry, __ in self._fields_[5:entry_cnt+5]:
            getattr(self, entry).print_info()


def PrintCallLogInfo(nvram, n=1):
    '''print CallLogInfo'''
    print("*"*18)
    print("CallLogInfo size:"+str(CallLogInfo().size))
    print("*"*18)
    print('call log:')
    nFieldID, nRecordID = NVRAM_UNIT[1]  # 0 - call log
    for i, data in enumerate(nvram.DatabaseFormat[nFieldID]):
        print("*"*18)
        data.print_info()
        if i == n - 1:
            break
