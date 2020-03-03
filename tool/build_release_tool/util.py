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
    def __init__(self, name = '', level = logging.INFO):
        logging.root.setLevel(logging.NOTSET)
        self._logger = logging.getLogger(name)
        self._file_name = None
        self._file_handler = None
        self._stream_handler = None
        self._formate = logging.Formatter('[%(asctime)s] %(message)s')
        self.enablePrint(level)


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
        self._file_handler.setLevel(logging.DEBUG)
        self._logger.addHandler(self._file_handler)

    def info(self,*message):
        self._logger.info("%s "*len(message)%(message))

    def debug(self,*message):
        self._logger.debug("%s "*len(message)%(message))

    def warning(self,*message):
        _str = "%s "*len(message)%(message)
        self._logger.warning('*** %s ***'%_str)

    def error(self,*message):
        _str = "%s "*len(message)%(message)
        self._logger.error('### %s ###'%_str)

    def critical(self,*message):
        self._logger.critical("%s "*len(message)%(message))

    def enablePrint(self,level = logging.INFO):
        if not self._stream_handler:
            self._stream_handler = logging.StreamHandler()
            self._stream_handler.setLevel(level)
            self._stream_handler.setFormatter(self._formate)
            self._logger.addHandler(self._stream_handler)

    def disablePrint(self):
        if self._stream_handler:
            self._stream_handler = None
            self._logger.removeHandler(self._stream_handler)

    def getLogFile(self):
        return self._file_name

    def write(self,*message):
        self._logger.info("%s "*len(message)%(message))


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
        if self._proc:
            return self._proc.is_alive()
        return False


class ThreadBase(object):
    """docstring for ProcBase"""

    def __init__(self):
        self._running = False
        self._proc = None

    def terminate(self):
        if self._proc:
            self._running = False

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
        if self._proc:
            return self._proc.is_alive()
        return False


class config:
    def __init__(self):
        self.cur_work_dir = None

    def update(self,cfg_file):
        self.cur_work_dir = os.getcwd()
        import ConfigParser
        conf = ConfigParser.ConfigParser()
        if os.path.exists(cfg_file):
            conf.read(cfg_file)
        else:
            assert('No config file')
        for sec in conf.sections():
            if 'basic_config' in str(sec):
                for attr,value in conf.items(sec):
                    value = os.path.join(self.cur_work_dir,value)
                    setattr(self,attr,value)
            # elif "cp_release_bin_config" in str(sec):
                # for attr,value in conf.items(sec):
                    # value = os.path.join(self.cur_crane,value)
                    # setattr(self,attr,value)
            elif "data_config" in str(sec):
                for attr,value in conf.items(sec):
                    setattr(self,attr.upper(),eval(value))
            else:
                for attr,value in conf.items(sec):
                    setattr(self,attr,value)
    def __repr__(self):
        _list = []
        for item in self.__dict__.items():
            _list.append("%s=%s"%item)
        return "\n".join(_list)




