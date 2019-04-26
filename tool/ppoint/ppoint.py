#!/usr/bin/env python

import os
import wx
import sys
import time
import datetime
import copy
import subprocess
import threading
import thread
import argparse
import pexpect
import re
import traceback
from util import *


def get_log(fname):
    with open(fname) as log_obj:
        pattern = re.compile(r'\$\^.*?5a..')
        text = log_obj.readlines()
        text = ''.join(text)
        text = text.replace('\n', '')
        tgt = pattern.findall(text)
    return tgt


START_FLAG = '$^'
LOG_TYPE1_END_FLAG = 0x5a
LOG_TYPE2_END_FLAG = 0xa5


class LogData1:
    def __init__(self):
        self._namedtuple = namedtuple('log_data1', [
                                      'log_type', 'magic', 'timestamp', 'un_log_data', 'end_flag1', 'crc8'])
        self.info = None
        self.detail_info = None

    def GetInfo(self, line):
        timestamp = line[2]+line[3].replace('0x', '')
        log_data = line[:2]
        log_data.append(timestamp)
        log_data.append(line[4:12])
        log_data += line[-2:]
        self.info = self._namedtuple(*log_data)

        if 0x10 <= eval(self.info.log_type) <= 0x15:
            log = AppLogData1()
            log.GetInfo(self.info.un_log_data)
            self.detail_info = copy.deepcopy(log.info)
        if 0x20 == eval(self.info.log_type):
            log = EvtS1LogData1()
            log.GetInfo(self.info.un_log_data)
            self.detail_info = copy.deepcopy(log.info)
        if 0x21 == eval(self.info.log_type):
            try:
                log = EvtS2LogData1()
                log.GetInfo(self.info.un_log_data)
                self.detail_info = copy.deepcopy(log.info)
            except:
                print line
                print self.info.un_log_data

        if 0x22 == eval(self.info.log_type):
            log = EvtS3LogData1()
            log.GetInfo(self.info.un_log_data)
            self.detail_info = copy.deepcopy(log.info)
        if 0x23 == eval(self.info.log_type):
            log = EvtR1LogData1()
            log.GetInfo(self.info.un_log_data)
            self.detail_info = copy.deepcopy(log.info)
        if 0x24 == eval(self.info.log_type):
            log = EvtR2LogData1()
            log.GetInfo(self.info.un_log_data)
            self.detail_info = copy.deepcopy(log.info)
        if 0x30 == eval(self.info.log_type):
            log = RunStageLogData1()
            log.GetInfo(self.info.un_log_data)
            self.detail_info = copy.deepcopy(log.info)
        if 0x40 == eval(self.info.log_type):
            log = KeypadLogData1()
            log.GetInfo(self.info.un_log_data)
            self.detail_info = copy.deepcopy(log.info)
        if 0x50 == eval(self.info.log_type):
            log = TaskLogData1()
            log.GetInfo(self.info.un_log_data)
            self.detail_info = copy.deepcopy(log.info)
        if 0x60 == eval(self.info.log_type):
            log = TimerLogData1()
            log.GetInfo(self.info.un_log_data)
            self.detail_info = copy.deepcopy(log.info)
        if 0x70 == eval(self.info.log_type):
            log = InterruptLogData1()
            log.GetInfo(self.info.un_log_data)
            self.detail_info = copy.deepcopy(log.info)


class LogData2:
    def __init__(self):
        self._namedtuple = namedtuple('log_data2', [
                                      'log_type', 'magic', 'buff_size', 'timestamp', 'log_buff', 'end_flag1', 'crc8'])
        self.info = None

    def GetInfo(self, line):
        timestamp = line[3]+line[4].replace('0x', '')
        log_data = line[:3]
        log_data.append(timestamp)
        log_data.append(line[5:13])
        log_data += line[-2:]
        self.info = self._namedtuple(*log_data)


class logParser:
    def _check_line(self, line):
        try:
            if line.startswith(START_FLAG) and START_FLAG not in line[2:]:
                line_l = ['0x' + str_ for str_ in line.split()[1:]]
                if eval(line_l[0])+eval(line_l[1]) == 0xff and len(line_l) >= 10:
                    return line_l
            return False
        except:
            print 'Error', line
            return False
            # raw_input()

    def _process_line(self, line):
        line = self._check_line(line)
        # print line
        if line:
            log_type = line[0]
            log_end_flag = line[-2]
            if eval(log_end_flag) == LOG_TYPE1_END_FLAG:
                log_data = LogData1()
                log_data.GetInfo(line)
            elif eval(log_end_flag) == LOG_TYPE2_END_FLAG:
                log_data = LogData2()
                log_data.GetInfo(line)
            return log_data
        return False
        # print log_data.info
        # print log_data.detail_info
        # raw_input()

    def parse(self, log, data_file):
        dest = open(data_file, 'w')
        for line in tgt:
            data = self._process_line(line)
            if data:
                printf(data.info, dest, False)
                printf(data.detail_info, dest, False)
        dest.close()


if __name__ == '__main__':
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument('log_file', default='',
                            help='if you test single module, input module name')
    arg_parser.add_argument('-f', '--file_name', default='data_file.log',
                            help='if you test single module, input module name')
    argv = arg_parser.parse_args()

    parser = logParser()
    try:
        tgt = get_log(argv.log_file)
        parser.parse(tgt, argv.file_name)
    except:
        traceback.print_exc()
