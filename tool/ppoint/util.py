#!/usr/bin/env python
import sys,os
import time
import pexpect,getpass
import threading 
import multiprocessing as mp
from collections import namedtuple

def get_sudo_password():
    proc = pexpect.spawn("sudo ls")
    while 1:
        index = proc.expect([r'\[sudo\] password for',r'Sorry, try again',"sudo: 3 incorrect password attempts", \
                                pexpect.EOF, pexpect.TIMEOUT], timeout=2)
        if index == 0:
            password = getpass.getpass("[sudo] password input: ")
            proc.sendline(password)
        if index == 1:
            print "Sorry, try again."
        if index == 2:
            print 'sudo: 3 incorrect password attempts'
            proc.close(force=True)
            sys.exit(1)
        if index == 3:
            proc.close(force=True)
            return password

def timing(timeout):
    for i in range(timeout):
        sys.stdout.write("timing: %ds\r" %i)
        sys.stdout.flush()
        time.sleep(1)

class ProcBase(object):
    """docstring for ProcBase"""
    def __init__(self):
        self._running = mp.Event()
        self._proc = None

    def terminate(self):
        self._running.clear()
        self._proc.terminate()
        self._proc = None

    def run(self,*args):
        while self._running.is_set():
            pass

    def start(self,*args):
        self._running.set()
        self._proc = mp.Process(target = self.run,args = args)
        self._proc.daemon = True
        self._proc.start()

    def restart(self,*args):
        self.terminate()
        self.start(*args)

    def setDaemon(self,BOOL):
        if self._proc:
            self._proc.daemon = BOOL


class ThreadBase(object):
    """docstring for ProcBase"""
    def __init__(self):
        self._running = False
        self._proc = None

    def terminate(self):
        self._running = False
        self._proc = None

    def run(self,*arg):
        while self._running:
            pass

    def start(self,*args):
        self._running = True
        self._proc = threading.Thread(target = self.run,args = args)
        self._proc.daemon = True
        self._proc.start()

    def restart(self,*args):
        self.terminate()
        self._proc = None
        self.start(*args)

    def setDaemon(self,BOOL):
        if self._proc:
            self._proc.daemon = BOOL

def mkdir_if_no_exists(path):
    if not os.path.exists(path):
        os.mkdir(path)

def get_abs_dir():
    return os.path.dirname(os.path.abspath(__file__))

def make_log_file(file_name):
    abs_dir = get_abs_dir()
    log_dir = os.path.join(abs_dir,'log')
    mkdir_if_no_exists(log_dir)

    date = time.strftime("%d_%h_%H-%M-%S")
    return os.path.join(log_dir,'%s_%s.log'%(file_name,date))


def printf(log,fname = '',BOOL = True):
    if fname:
        if BOOL:
            print log
        print >>fname,log
    else:
        print log

LOG_DATA1 = {
    0x10:{'app_name':0}

}


LOG_TYPE = {
    0x10:'LOG_TYPE_APP_START',
    0x11:'LOG_TYPE_APP_EXIT',
    0x12:'LOG_TYPE_APP_SLEEP',
    0x13:'LOG_TYPE_APP_SUSPEND',
    0x14:'LOG_TYPE_APP_RESTORE',
    0x15:'LOG_TYPE_APP_RELEASE_MEN',

    0x20:'LOG_TYPE_EVT_SEND_MSG',
    0x21:'LOG_TYPE_EVT_SEND_COS_EVENT',
    0x22:'LOG_TYPE_EVT_SEND_EXTMSG_EVENT',

    0x23:'LOG_TYPE_EVT_R1_RECV_MSG',
    0x24:'LOG_TYPE_EVT_R2_RECV_EVENT',

    0x25:'LOG_TYPE_EVT_DO_CALLBACK',
    0x26:'LOG_TYPE_EVT_REGI_CALLBACK',
    0x27:'LOG_TYPE_EVT_DISPATCH',

    0x30:'LOG_TYPE_BOOTFLOW_STAGE',

    0x40:'LOG_TYPE_KEY_0',
    0x41:'LOG_TYPE_KEY_1_SIMU',

    0x50:'LOG_TYPE_TASK_0',

    0x60:'LOG_TYPE_TIMER_0',

    0x70:'LOG_TYPE_INT_0',

    0x80:'LOG_TYPE2_PERF_0',

    0x90:'LOG_TYPE2_MEMINFO_0'
}

class AppLogData1:
    def __init__(self):
        self._namedtuple = namedtuple('app_log_data1',['app_name'])
        self.info = None

    def GetInfo(self,line):
        log_data = ''
        for str_ in line:
            log_data += chr(eval(str_))
        self.info = self._namedtuple(log_data)

class EvtS1LogData1(object):
    def __init__(self):
        self._namedtuple = namedtuple('evt_s1_log_data1',['task_id','p_msg','reserved'])
        self.info = None
    def GetInfo(self,line):
        task_id = hex(eval(line[0]))
        p_msg = ''
        for str_ in line[1:5]:
            p_msg += chr(eval(str_))
        reserved = line[-3:]
        self.info = self._namedtuple(task_id,p_msg,reserved)

class EvtS2LogData1(object):
    def __init__(self):
        self._namedtuple = namedtuple('evt_s2_log_data1',['task_id','evt_id','reserved'])
        self.info = None
    def GetInfo(self,line):
        task_id = hex(eval(line[0]))
        evt_id = '0x'
        for str_ in line[1:5]:
            evt_id += str_.replace('0x','')
        reserved = line[-3:]
        self.info = self._namedtuple(task_id,evt_id,reserved)

class EvtS3LogData1:
    def __init__(self):
        self._namedtuple = namedtuple('evt_s3_log_data1',['task_id','evt_id','src_mod','tgt_mod','reserved'])
        self.info = None

    def GetInfo(self,line):
        task_id = hex(eval(line[0]))
        evt_id = '0x'
        for str_ in line[1:5]:
            evt_id += str_.replace('0x','')
        src_mod = line[5]
        tgt_mod = line[6]
        reserved = line[7]
        self.info = self._namedtuple(task_id,evt_id,src_mod,tgt_mod,reserved)

class EvtR1LogData1(EvtS1LogData1):
    def __init__(self):
        super(EvtR1LogData1, self).__init__()
        self._namedtuple = namedtuple('evt_r1_log_data1',['task_id','p_msg','reserved'])

class EvtR2LogData1(EvtS2LogData1):
    def __init__(self):
        super(EvtR2LogData1, self).__init__()
        self._namedtuple = namedtuple('evt_r2_log_data1',['task_id','evt_id','reserved'])

class RunStageLogData1:
    def __init__(self):
        self._namedtuple = namedtuple('runstage_log_data1',['run_stage','param','reserved'])
        self.info = None

    def GetInfo(self,line):
        run_stage = ''
        for str_ in line[:2]:
            run_stage += chr(eval(str_))
        param = '0x'
        for str_ in line[2:6]:
            param += str_.replace('0x','')
        reserved = line[-2:]
        self.info = self._namedtuple(run_stage,param,reserved)

class KeypadLogData1:
    def __init__(self):
        self._namedtuple = namedtuple('keypad_log_data1',['scan_code','status','param','reserved'])
        self.info = None

    def GetInfo(self,line):
        scan_code = line[0]
        status = line[1]
        param = '0x'
        for str_ in line[2:6]:
            param += str_.replace('0x','')
        reserved = line[-2:]
        self.info = self._namedtuple(scan_code,status,param,reserved)

class TaskLogData1:
    def __init__(self):
        self._namedtuple = namedtuple('task_log_data1',['task_id','task_name'])
        self.info = None

    def GetInfo(self,line):
        task_id = hex(eval(line[0]))
        task_name = ''
        for str_ in line[1:]:
            task_name += chr(eval(str_))
        self.info = self._namedtuple(task_id,task_name)

class TimerLogData1:
    def __init__(self):
        self._namedtuple = namedtuple('timer_log_data1',['timer_data'])
        self.info = None

    def GetInfo(self,line):
        timer_data = ''
        for str_ in line[1:]:
            timer_data += chr(eval(str_))
        self.info = self._namedtuple(timer_data)

class InterruptLogData1:
    def __init__(self):
        self._namedtuple = namedtuple('interrupt_log_data1',['interrupt_data'])
        self.info = None

    def GetInfo(self,line):
        interrupt_data = ''
        for str_ in line[1:]:
            interrupt_data += chr(eval(str_))
        self.info = self._namedtuple(interrupt_data)