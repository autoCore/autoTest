#!/usr/bin/env python
import sys,os,re
import time,datetime
import pexpect,getpass
import threading 
import multiprocessing as mp

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

    now = datetime.datetime.today()
    date = now.strftime("%d_%h_%H-%M-%S")
    return os.path.join(log_dir,'%s_%s.log'%(file_name,date))

key_value_d = {
    '[':'F_LEFT',
    '^':'UP',
    ']':'F_RIGHT',
    '<':'LEFT',
    'M':'OK',
    '>':'RIGHT',
    'S':'CALL',
    'V':'DOWN',
    'P':'RING_OFF',
    '1':'1',
    '2':'2',
    '3':'3',
    '4':'4',
    '5':'5',
    '6':'6',
    '7':'7',
    '8':'8',
    '9':'9',
    '*':'*',
    '0':'0',
    '#':'#'
}


#   [   ^   ]
#    <  M  >
#   S   V   P
#   1   2   3
#   4   5   6
#   7   8   9
#   *   0   #