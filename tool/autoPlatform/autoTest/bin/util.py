#! /usr/bin/env python
import os
import logging
import time

def lines(file):
	for line in file: yield line
	yield '\n'

def blocks(file):
	block = []
	for line in lines(file):
		if line.strip():
			block.append(line)
		elif block:
			yield ''.join(block).strip()
			block = []


class Logger(object):
    def __init__(self, logdir, proc):
        os.makedirs(path) if not os.path.isdir(path) else None
        self.ct = time.strftime("%Y%m%d%H%M%S")
        self.logname = os.path.join(logdir, "%s_%s.log" % (self.ct, proc))
        logging.basicConfig( level = logging.DEBUG,
                             format = '%(asctime)s %(filename)13s:%(lineno)4d %(levelname)7s: %(message)s',
                             datefmt = '%a, %d %b %Y %H:%M:%S',
                             filename = self.logname,
                             filemode = 'a')
        self.console = logging.StreamHandler()
        self.console.setLevel(logging.INFO)
        formatter = logging.Formatter('%(asctime)s %(levelname)7s: %(message)s')
        self.console.setFormatter(formatter)
        logging.getLogger('').addHandler(self.console)

    def set_debug(self):
        self.console.setLevel(logging.DEBUG)

    def rename(self, proc):
        # shutdown logging system
        logging.shutdown()
        (path, fn) = os.path.split(self.logname)
        newlog = os.path.join(path, "%s_%s.log" % (self.ct, proc))
        try:
            os.rename(self.logname, newlog)
        except Exception, e:
            if os.path.isfile(self.logname):
                print "Error: still exist"

    def remove(self):
        logging.shutdown()
        os.remove(self.logname)