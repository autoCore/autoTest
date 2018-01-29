#!/usr/bin/env python

import os
import shutil
import xlrd
import sys
from xml_parser import *

reload(sys)
sys.setdefaultencoding('utf8')
sys.path.append('../tool/autoPlatform/t32_api')
from jtag_t32 import *

isExists = os.path.exists('./tmp/regverify')
if isExists:
	shutil.rmtree(r'./tmp/regverify')
os.mkdir(r'./tmp/regverify')
os.system(r'chmod +w tmp')

def verify_df(reg_field, fobj):
	if(str(reg_field[3]) == 'rsvd'):
		return 0
		
	string = 'REG' + '(' + hex(reg_field[-1][1]) + ')' + ':'
	string = string + 'Field:' + str(reg_field[0]) + ':InitValErr(readout:'
	field_mask = 0
	for i in range(int(str(reg_field[2]))):
		field_mask = field_mask | (0x1 <<((int(str(reg_field[1]))) + i))
	value = read_reg_bit(reg_field[-1][1])
        value = (value & field_mask) >> (int(str(reg_field[1])))   
	if(reg_field[4] == ' '):
		string = string + (hex(value)).replace("L","") + ', spec:None)\n\n' 
                fobj.write(string)
                return 1
	elif(reg_field[4].find("0x",0,3) < 0):
		string = string + (hex(value)).replace("L","") + ', spec:' + str(reg_field[4]) + ')\n\n'
       		fobj.write(string)
             	return 1
	else:
		if ( value == int(str(reg_field[4].replace("0x","")),16)):
                	return 0
        	else:
			string = string + (hex(value)).replace("L","") + ', spec:' + str(reg_field[4]) + ')\n\n'
			fobj.write(string)
			return 1

def verify_ro(reg_addr, field_offset, fobj):
	value1 = read_reg_bit(reg_addr)
        value2 = value1 ^ (0x1 << field_offset)
        write_reg_bit(reg_addr, value2)
	value3 = read_reg_bit(reg_addr)
	if ( value3 == value1):
                return 0
        else:
		print hex(value1)
		print hex(value2)
		print hex(value3)
		string = 'REG' + '(' + hex(reg_addr) + ')' + ':' + 'Field_offset: ' + str(field_offset) + ' RO type but writable.\n\n'
		fobj.write(string)
		return 1


def verify_rw(reg_addr, field_offset, fobj):
	value1 = read_reg_bit(reg_addr)
	value2 = value1 ^ (0x1 << field_offset)
        write_reg_bit(reg_addr, value2)
        value3 = read_reg_bit(reg_addr)
        if ( value3 == value2):
        	return 0 
        else:
               	string = 'read-write bit ' + str(field_offset) + ' in address '+ hex(reg_addr) + ' test error...'
                fobj.write(string)
                fobj.write("\n")
		return 1

def get_reg_glb(reg):
	reg_glb=[]
	reg_name = reg[0]
	reg_glb.append(reg_name)
	reg_addr = str(reg[-1].replace("0x",""))
	reg_addr = int(reg_addr, 16)
	if(reg[1].find("~",0, 6) > 0):
		reg_offset = int(str(reg[1].split("~")[0].replace("0x","")),16)
	else:
		reg_offset = int(str(reg[1].replace("0x","")),16)
        reg_addr = reg_addr+reg_offset
	reg_glb.append(reg_addr)
	reg_reset_value = int(str(reg[2].replace("0x","")),16)
	reg_glb.append(reg_reset_value)
        reg_reset_mask = int(str(reg[3].replace("0x","")),16)
	reg_glb.append(reg_reset_mask)
	return reg_glb


def verify_field(reg_field, fobj):
	cnt_df = 0
	cnt_ro = 0
	cnt_rw = 0
	cnt_df = verify_df(reg_field, fobj)

	reg_addr = reg_field[-1][1]
        field_name = reg_field[0]
        field_offset = int(str(reg_field[1]))
        field_width = int(str(reg_field[2]))
	field_width = field_width + field_offset
        while (field_offset < field_width):
		if("ro" == reg_field[3]):
			cnt_ro = cnt_ro + verify_ro(reg_addr, field_offset, fobj)
		'''
		elif("rw" == reg_field[3]):
			cnt_rw = cnt_rw + verify_rw(reg_addr, field_offset, fobj)
		'''
		field_offset = field_offset + 1

	return (cnt_df + cnt_ro + cnt_rw)


def verify_reg(reg, fobj):
	cnt = 0
	reg_glb = get_reg_glb(reg)
	for reg_field in reg[4]:
		reg_field.append(reg_glb)
        	cnt = cnt + verify_field(reg_field, fobj)


def verify_begin(regs):
	string = 'Table:' + regs[0]
	fname = './tmp/regverify/' + regs[0].lower() + '_check.txt'
	print fname
	fobj = open(fname, 'w')
	fobj.write(string)
        fobj.write("\n\n")
	reg_base = regs[1]
        for reg in regs[2:]:
		reg.append(reg_base)
		verify_reg(reg, fobj)
	fobj.close()

if __name__ == '__main__':
	for doc in database:
		regs_info = get_regs_info(doc)
                verify_begin(regs_info)
