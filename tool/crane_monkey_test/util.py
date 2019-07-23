#!/usr/bin/env python
# -*- coding:utf-8 -*-
import logging
import os
import sys
import time
import pexpect
import getpass
import threading
import multiprocessing as mp


class myLogger(object):
    def __init__(self, name = '', level = logging.DEBUG):
        self._logger = logging.getLogger(name)
        self._file_name = None
        self._file_handler = None
        self._formate = logging.Formatter('%(name)s: [%(asctime)s] [%(levelname)-5s] %(message)s')
        self._stream_handler = logging.StreamHandler()
        self._stream_handler.setFormatter(self._formate)
        self._logger.setLevel(level)

    def addHandler(self,handler):
        if self._logger:
            self._logger.addHandler(handler)

    def setLevel(self,level):
        if self._logger:
            self._logger.setLevel(level)

    def resetLogFile(self, file_name, fmt = ''):
        if self._file_handler:
            self._logger.removeHandler(self._file_handler)
        self._file_name = file_name
        self._file_handler = logging.FileHandler(file_name, mode='w')
        if fmt:
            _fmt = logging.Formatter(fmt)
            self._file_handler.setFormatter(_fmt)
        else:
            self._file_handler.setFormatter(self._formate)
        self._logger.addHandler(self._file_handler)

    def debug(self,message):
        self._logger.debug('*** %s ***'%message)

    def info(self,message):
        self._logger.info(message)

    def warning(self,message):
        self._logger.warning(message)

    def error(self,message):
        self._logger.error('### %s ###'%message)

    def critical(self,message):
        self._logger.critical(message)

    def enablePrint(self):
        self._logger.addHandler(self._stream_handler)

    def getLogFile(self):
        return self._file_name

    def write(self,message):
        self._logger.info(message)


def timing(timeout):
    for i in range(int(float(timeout))):
        sys.stdout.write("timing: %ds\r" % i)
        sys.stdout.flush()
        time.sleep(1)

def get_sudo_password():
    proc = pexpect.spawn("sudo ls")
    while 1:
        index = proc.expect([r'\[sudo\] password for', r'Sorry, try again', "sudo: 3 incorrect password attempts",
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
        if self._proc:
            self._running.clear()
            self._proc.terminate()
            self._proc = None

    def run(self, *args):
        while self._running.is_set():
            pass

    def start(self, *args):
        self._running.set()
        self._proc = mp.Process(target=self.run, args=args)
        self._proc.daemon = True
        self._proc.start()

    def restart(self, *args):
        self.terminate()
        self.start(*args)

    def setDaemon(self, BOOL):
        if self._proc:
            self._proc.daemon = BOOL

    def isOpen(self):
        return self._proc is not None


class ThreadBase(object):
    """docstring for ProcBase"""

    def __init__(self):
        self._running = False
        self._proc = None

    def terminate(self):
        if self._proc:
            self._running = False
            self._proc = None

    def run(self, *arg):
        while self._running:
            pass

    def start(self, *args):
        self._running = True
        self._proc = threading.Thread(target=self.run, args=args)
        self._proc.daemon = True
        self._proc.start()

    def restart(self, *args):
        self.terminate()
        self._proc = None
        self.start(*args)

    def setDaemon(self, BOOL):
        if self._proc:
            self._proc.daemon = BOOL

    def isOpen(self):
        return self._proc is not None


def mkdir_if_no_exists(path):
    if not os.path.exists(path):
        os.mkdir(path)


def get_abs_dir():
    return os.path.dirname(os.path.abspath(__file__))


def make_log_file(file_name):
    abs_dir = get_abs_dir()
    log_dir = os.path.join(abs_dir, 'log')
    mkdir_if_no_exists(log_dir)

    date = time.strftime("%d_%h_%H-%M-%S")
    return os.path.join(log_dir, '%s_%s.txt' % (file_name, date))

class config:
    def __init__(self):
        self.SIMULATE_KEY_INPUT_INTERVAL = None
        self.CHECK_INTERVAL = None
        self.RESET_SYSTEM_WAIT_TIME = None
        self.KEY_DOWN_UP_INTERVAL = None

    def update(self,cfg_file):
        import ConfigParser
        conf = ConfigParser.ConfigParser()
        if os.path.exists(cfg_file):
            conf.read(cfg_file)
        else:
            assert('No config file')
        for sec in conf.sections():
            if str(sec) in 'config':
                value = conf.getfloat('config','SIMULATE_KEY_INPUT_INTERVAL')
                self.SIMULATE_KEY_INPUT_INTERVAL = value if value else 1
                value = conf.getint('config','CHECK_INTERVAL')
                self.CHECK_INTERVAL = value if value else 3
                value = conf.getint('config','RESET_SYSTEM_WAIT_TIME')
                self.RESET_SYSTEM_WAIT_TIME = value if value else 30
                value = conf.getfloat('config','KEY_DOWN_UP_INTERVAL')
                self.KEY_DOWN_UP_INTERVAL = value if value else 30
            else:
                setattr(self,sec,conf.items(sec))
    def __repr__(self):
        return "config(SIMULATE_KEY_INPUT_INTERVAL=%r,CHECK_INTERVAL=%r,RESET_SYSTEM_WAIT_TIME=%r,KEY_DOWN_UP_INTERVAL=%r)"\
                %(self.SIMULATE_KEY_INPUT_INTERVAL,\
                self.CHECK_INTERVAL,\
                self.RESET_SYSTEM_WAIT_TIME,\
                self.KEY_DOWN_UP_INTERVAL)