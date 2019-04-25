#! /usr/bin/env python
# encoding:utf-8

import sys
import os
import argparse
import copy
from gui_main import gui_main

from nvram_util import *
from nvram_phb import *
from nvram_call_log import *
from nvram_sms import *
from nvram_alm_calendar import *


NVRAM_FORMAT = {
    NVRAM_PHB_NVRAM_LID: PhoneBookInfo(),
    NVRAM_EF_PHB_SOMEFIELDS_LID: PhoneBookOptionalField(),
    NVRAM_SMSPROFNE_NVRAM_LID: SmsInfo(),
    NVRAM_DIALEDCALL_NVRAM_LID: CallLogInfo(),
    NVRAM_CFGALM_ALARM_DATA: AlarmInfo()
}


class NvramGlobalVal(object):
    """docstring for NvramGlobalVal"""

    def __init__(self, nvram_file):
        self.Head = NvramHeaderInfo()
        self.HeadUpdateFlag = False
        self.NvramFile = nvram_file
        self.Node = []
        self.Record = []
        self.Database = {}
        self.DatabaseFormat = {}

    def UpdateHeaderInfo(self):
        with open(self.NvramFile, 'rb') as Nvram_file:
            Nvram_file.seek(self.Head.iHOffs, 0)
            data = Nvram_file.read(self.Head.size)
        self.Head.GetInfo(data)
        self.HeadUpdateFlag = True

    def UpdateNodeInfo(self):
        self.UpdateHeaderInfo() if not self.HeadUpdateFlag else None
        with open(self.NvramFile, 'rb') as Nvram_file:
            Nvram_file.seek(self.Head.iNDOffs, 0)
            data_buffer = Nvram_file.read(NVRAM_NDT_SIZE)
        for i in range(NVRAM_ENTRIES_COUNT):
            node = NvramNodeInfo()
            data = data_buffer[i*node.size:(i+1)*node.size]
            node.GetInfo(data)
            self.Node.append(copy.deepcopy(node))

    def UpdateRecordInfo(self):
        self.UpdateHeaderInfo() if not self.HeadUpdateFlag else None
        with open(self.NvramFile, 'rb') as Nvram_file:
            Nvram_file.seek(self.Head.iROffs, 0)
            data_buffer = Nvram_file.read(self.Head.iRCount*NVRAM_R_SIZE)
            data_len = len(data_buffer)
            if data_len < self.Head.iRCount*NVRAM_R_SIZE:
                print('ERROR:NVRAM_R_TOTAL_SIZE < Head.iRCount*NVRAM_R_SIZE')
                print('NVRAM_R_TOTAL_SIZE:', len(data_buffer))
                print('Head.iRCount*NVRAM_R_SIZE:',
                      self.Head.iRCount*NVRAM_R_SIZE)
        for i in range(self.Head.iRCount):
            record = NvramRecordInfo()
            data = data_buffer[i*record.size:(i+1)*record.size]
            try:
                record.GetInfo(data)
            except:
                traceback.print_exc()
            self.Record.append(copy.deepcopy(record))

    def GetNodeInfo(self, nFieldID, nRecordID):
        iID = nFieldID*100 + nRecordID
        for piNDN, node in enumerate(self.Node):
            if iID == node.iId:
                return piNDN, node
        else:
            return None, None

    def GetRecordInfo(self, iID):
        tgtRecord_l = [
            Record for Record in self.Record if Record.sCtr.iId == iID]
        tgtRecord_l = sorted(tgtRecord_l, key=lambda record: record.sCtr.iInd)
        return tgtRecord_l[:]

    def UpdateDatabase(self):
        for nFieldID, nRecordID in NVRAM_UNIT:
            piNDN, node = self.GetNodeInfo(nFieldID, nRecordID)
            if None == node:
                continue
            R_list = self.GetRecordInfo(node.iId)
            Rcnt = NVRAM_NR_COUNT(node.iSize)
            self.Database[nFieldID] = ''.join(
                [c_ubyte_Array_To_string(Record.pData) for Record in R_list[:Rcnt]])
            # self.Database[nFieldID] = [memoryview(Record.pData) for Record in R_list[:Rcnt]]

    def UpdateDatabaseFormat(self):
        self.UpdateDatabase() if not self.Database else None
        for key, value in NVRAM_FORMAT.items():
            try:
                self.DatabaseFormat[key] = []
                data = self.Database.get(key)
                if not data:
                    continue
                for i in range(len(data)/value.size):
                    block = data[value.size*i:value.size*(1+i)]
                    value.GetInfo(block)
                    self.DatabaseFormat[key].append(copy.deepcopy(value))
            except:
                print len(data), value.size
                raise


def test_write():
    file_name = r"Z:\work\nvram\112233.bin"
    struct_parse = StructParse()
    struct_fmt = '<I'
    offset = 0x14
    value = (0x200,)
    struct_parse.WriteInfo(file_name, struct_fmt, offset, *value)


if __name__ == '__main__':
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument('file_name', help='Pls input file name ')
    argv = arg_parser.parse_args()
    # test_write()

    nvram = NvramGlobalVal(argv.file_name)
    nvram.UpdateHeaderInfo()
    nvram.UpdateNodeInfo()
    nvram.UpdateRecordInfo()
    print("*"*18)
    nvram.Head.print_info()
    print("*"*18)
    for r in nvram.Record[:1]:
        r.print_info()

    nvram.UpdateDatabaseFormat()

    PrintPhoneBookInfo(nvram,10)
    PrintCallLogInfo(nvram, 10)
