#!/usr/bin/env python
# -*- coding:utf-8 -*-

import logging
import os
import sys
import pexpect
import getpass
import threading
import subprocess
import shutil
import multiprocessing as mp
import psutil
import Queue


def kill_win_process(*process_name):
    for _process in psutil.process_iter():
        try:
            if _process.name() in process_name:
                print "%r, %s" % (_process.pid, _process.name())
                if _process.is_running():
                    _process.terminate()
        except Exception, e:
            print e


class MyLogger(object):
    def __init__(self, _name=''):
        logging.root.setLevel(logging.NOTSET)
        self._logger = logging.getLogger(_name)
        self._file_name = None
        self._file_handler = None
        self._stream_handler = None
        self._formate = logging.Formatter('[%(asctime)s][%(name)-13s][%(levelname)s]: %(message)s')

    def add_handler(self, handler):
        if self._logger:
            self._logger.addHandler(handler)

    def set_level(self, level):
        if self._logger:
            self._logger.setLevel(level)
        if self._stream_handler:
            self._stream_handler.setLevel(level)
        if self._file_handler:
            self._file_handler.setLevel(level)

    def reset_log_file(self, file_name, level=logging.INFO, fmt=''):
        if self._file_handler:
            self._logger.removeHandler(self._file_handler)
        self._file_name = file_name
        self._file_handler = logging.FileHandler(file_name, mode='w')
        if fmt:
            _fmt = logging.Formatter(fmt)
            self._file_handler.setFormatter(_fmt)
        else:
            self._file_handler.setFormatter(self._formate)
        self._file_handler.setLevel(level)
        self._logger.addHandler(self._file_handler)

    def info(self, *message):
        self._logger.info("%s " * len(message) % (message))

    def debug(self, *message):
        self._logger.debug("%s " * len(message) % (message))

    def warning(self, *message):
        self._logger.warning("%s " * len(message) % (message))

    def error(self, *message):
        self._logger.error("%s " * len(message) % (message))

    def critical(self, *message):
        self._logger.critical("%s " * len(message) % (message))

    def enable_print(self, level=logging.INFO):
        if not self._stream_handler:
            self._stream_handler = logging.StreamHandler()
            self._stream_handler.setLevel(level)
            self._stream_handler.setFormatter(self._formate)
            self._logger.addHandler(self._stream_handler)

    def disable_print(self):
        if self._stream_handler:
            self._logger.removeHandler(self._stream_handler)
            self._stream_handler = None

    def get_log_file(self):
        return self._file_name

    def write(self, *message):
        self._logger.info("%s " * len(message) % (message))


def get_sudo_password():
    password = None
    prc = pexpect.spawn("sudo ls")
    while 1:
        index = prc.expect([r'\[sudo\] password for', r'Sorry, try again', "sudo: 3 incorrect password attempts",
                             pexpect.EOF, pexpect.TIMEOUT], timeout=2)
        if index == 0:
            password = getpass.getpass("[sudo] password input: ")
            prc.sendline(password)
        if index == 1:
            print "Sorry, try again."
        if index == 2:
            print 'sudo: 3 incorrect password attempts'
            prc.close(force=True)
            sys.exit(1)
        if index == 3:
            prc.close(force=True)
            return password


class PrcBase(object):
    """docstring for ProcBase"""

    def __init__(self):
        self._running = mp.Event()
        self._prc = None

    def terminate(self):
        if self._prc:
            self._running.clear()
            self._prc.terminate()

    def run(self, *args):
        while self._running.is_set():
            pass

    def start(self, *args):
        self._running.set()
        self._prc = mp.Process(target=self.run, args=args)
        self._prc.daemon = True
        self._prc.start()

    def restart(self, *args):
        self.terminate()
        self.start(*args)

    def set_daemon(self, BOOL):
        if self._prc:
            self._prc.daemon = BOOL

    def is_open(self):
        if self._prc:
            return self._prc.is_alive()
        return False


class ThreadBase(object):
    """docstring for ProcBase"""

    def __init__(self, name=None):
        self._running = False
        self._prc = None
        self._name = name
        self._queue = Queue.Queue()

    def get_massage(self):
        return self._queue.get()

    def put_massage(self, msg):
        self._queue.put(msg)

    def terminate(self):
        if self._prc:
            self._running = False

    def run(self, *arg):
        while self._running:
            pass

    def start(self, *args):
        self._running = True
        self._prc = threading.Thread(target=self.run, name=self._name, args=args)
        self._prc.daemon = True
        self._prc.start()

    def restart(self, *args):
        self.terminate()
        self._prc = None
        self.start(*args)

    def set_daemon(self, BOOL):
        if self._prc:
            self._prc.daemon = BOOL

    def is_open(self):
        if self._prc:
            return self._prc.is_alive()
        return False


class config:
    def __init__(self):
        self.release_cp_version_log = None
        self.cur_crane_cus = None
        self.cp_version_log = None
        self.cp_version_file = None
        self.cur_crane = None
        self.version_log = None
        self.log_dir = None
        self.cur_work_dir = None

    def update(self, cfg_file):
        self.cur_work_dir = os.getcwd()
        import ConfigParser
        conf = ConfigParser.ConfigParser()
        if os.path.exists(cfg_file):
            conf.read(cfg_file)
        else:
            assert 'No config file'
        conf.set("basic_config", "root_dir", self.cur_work_dir)
        for sec in conf.sections():
            if 'basic_config' in str(sec):
                for attr, value in conf.items(sec):
                    setattr(self, attr, value)
            # elif "cp_release_bin_config" in str(sec):
            # for attr,value in conf.items(sec):
            # value = os.path.join(self.cur_crane,value)
            # setattr(self,attr,value)
            elif "data_config" in str(sec):
                for attr, value in conf.items(sec):
                    setattr(self, attr.upper(), eval(value))
            else:
                for attr, value in conf.items(sec):
                    setattr(self, attr, value)

    def __repr__(self):
        _list = []
        for item in self.__dict__.items():
            _list.append("%s=%s" % item)
        return "\n".join(_list)


class zipTool(object):
    _mutex = threading.Lock()

    def __init__(self):
        work_dir = os.path.dirname(os.path.abspath(__file__))
        self._external_tool = os.path.join(work_dir, "unzip_tool", "7z.exe")
        self._decompress_tool = os.path.join(work_dir, "unzip_tool", "asr_lzop.exe")

    def decompress_bin(self, src_bin, out_bin):
        assert os.path.exists(src_bin),"%s no exists" % src_bin
        decompress_cmd = "{0} -d -f {1} -o{2}".format(self._decompress_tool, src_bin, out_bin)
        subprocess.call(decompress_cmd, shell=True)
        return out_bin


    @staticmethod
    def make_archive(base_name, _format, root_dir):
        shutil.make_archive(base_name, _format, root_dir)

    def make_archive_e(self, base_name, _format, root_dir):
        file_name = ".".join([base_name, _format])
        pack_cmd = "%s a %s %s -y" % (self._external_tool, file_name, root_dir)
        with self._mutex:
            subprocess.call(pack_cmd, shell=True)
            kill_win_process("7z.exe")

    def unpack_archive(self, filename, extract_dir=None):
        assert os.path.exists(filename), "can not find %r" % filename
        if extract_dir:
            unpack_cmd = "%s x %s -o%s -y" % (self._external_tool, filename, extract_dir)
        elif os.path.dirname(filename):
            unpack_cmd = "%s x %s -o%s -y" % (self._external_tool, filename, os.path.dirname(filename))
        else:
            unpack_cmd = "%s x %s -o. -y" % (self._external_tool, filename)
        # print unpack_cmd
        with self._mutex:
            subprocess.call(unpack_cmd, shell=True)
            kill_win_process("7z.exe")

    def unpack_files_from_archive(self, archive_file, dist_dir, *fname):
        archive_file = os.path.realpath(archive_file)
        assert os.path.exists(archive_file), "can not find %r" % archive_file
        unpack_cmd = "{} e {} {} -o{} -y".format(self._external_tool, archive_file, " ".join(fname), dist_dir)
        # print unpack_cmd
        with self._mutex:
            subprocess.call(unpack_cmd, shell=True)
            kill_win_process("7z.exe")

    def pack_files_to_archive(self, base_name, _format, *file_name):
        root_dir, _ = os.path.splitext(base_name)
        os.mkdir(root_dir)
        for _obj in file_name:
            if os.path.exists(_obj):
                if os.path.isfile(_obj):
                    shutil.copy2(_obj, root_dir)
                elif os.path.isdir(_obj):
                    shutil.copytree(_obj, root_dir)
                else:
                    print _obj, "Error!"
            else:
                print "%r not exists" % _obj
        self.make_archive(base_name, _format, root_dir)
        # self.make_archive_e(base_name, format, root_dir)
        shutil.rmtree(root_dir)


