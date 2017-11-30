#!/usr/bin/python
import os,sys
import struct
import argparse

arg_parser = argparse.ArgumentParser()
arg_parser.add_argument('fname',help='--file name, example: ./aquilac_fpga_mini_test.bin')
arg_parser.add_argument('-p', '--printf', action="store_true",help='if -p print data else not')
argv = arg_parser.parse_args()
if not os.path.isfile(argv.fname):
	print 'file not exist'
	sys.exit(0)
dfname,suffix = os.path.splitext(argv.fname)
dfname += '.hex'
count=0
sfile=open(argv.fname, "rb")
dfile=open(dfname, "wb")
d = sfile.read(4)
while d!= "":
    if len(d)!= 4:
        d=d+chr(0)*(4-len(d))
    data = format (struct.unpack("<I",d)[0], "008X")
    if argv.printf: print "%s" % (data)
    print >> dfile, "%s" % (data)
    count += 1
    d = sfile.read(4)

sfile.close()
dfile.close()
