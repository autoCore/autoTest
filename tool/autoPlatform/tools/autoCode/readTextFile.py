#!/usr/bin/env python

'readTextFile.py -- read and display text file zhenbo.zhan'
all = []

def read_code_file(fname_string):
	# attempt to open file for reading
        try:
			__fobj = open(fname_string, 'r')
        except IOError as e:
			print ("*** file open error:")
			print (e)
        else:
			# display contents to the screen
			all = []
			for eachLine in __fobj:
				all.append(eachLine);
			__fobj.close()
        return all
