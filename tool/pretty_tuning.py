#!/usr/bin/env python

import os
import shutil
import xlrd
import sys

import string
import copy

import time

reload(sys)
sys.setdefaultencoding('utf8')
sys.path.append('./tool/autoTest')
from jtag_t32 import *

reload(sys)
sys.setdefaultencoding('utf8')

if(len(sys.argv) < 2):
	print ('Error: Pls enter/Pass the correct command.', len(sys.argv))
fname_excel = str(sys.argv[1])

class excel_contents(object):
	'define excel all contents data and some methods'
	def __init__(self):
		self.line_num = ''
		self.type = 0
		self.reg_addr = 0
		self.reg_value = 0
		self.delay_time = 0
	def update(self, line_num, type, reg_addr, reg_value, delay_time):
		self.line_num = line_num 
		self.type = type#1:read for dump, 2: write 3:delay 4:delay wile `v = v ,5 delay while `v !=v, 6 read for the next write 
		self.reg_addr = int(reg_addr, 16)
		self.reg_value = int(reg_value, 16)
		self.delay_time = int(delay_time, 16)
	@staticmethod
	def dump_value(x):
		print (('type is : '), x.type)
		print (('reg_addr is : '), x.reg_addr)
		print (('reg_value is : '), x.reg_value)
		print (('delay_time is : '), x.delay_time)

def read_excel_file(s):
	excel_list = []
	content = excel_contents()
	print ("Sheets name: " + s.name)
	nrows = s.nrows
	ncols = s.ncols

	curr_row = 0
	while curr_row < nrows:
		rowdata = s.row_values(curr_row)
		if type(rowdata[0]) != float:
			tmp_string = rowdata[0].lower()
			if (tmp_string == "register addr"):
				curr_row = curr_row + 1
				continue

			content.line_num = curr_row

			if (tmp_string.find('delay(') == 0):
				tmp_string = tmp_string.replace('delay(','')
				if (tmp_string.find(')') == -1):
					print ("err1 this line"),(tmp_string)
				else:
					tmp_string = tmp_string.replace(')','')
					content.type = 3
					content.delay_time = tmp_string
			elif (tmp_string.find('while(') == 0):
				tmp_string = tmp_string.replace('while(','')
				tmp_string = tmp_string[0:-1]
				
				if (tmp_string.find('==') != -1):
					content.type = 4
					lisss = tmp_string.split('==')
					content.reg_addr = lisss[0].rstrip().lstrip()
					content.reg_value = lisss[1].rstrip().lstrip()					
				else:
					print ("find != ?")
					content.type = 5
					lisss = tmp_string.split('!=')
					print (lisss)
					content.reg_addr = lisss[0].rstrip().lstrip()
					content.reg_value = lisss[1].rstrip().lstrip()

			elif (tmp_string.find('read(') == 0):
				tmp_string = tmp_string.replace('read(','')
				if (tmp_string.find(')') == -1):
					print ("err2 this line"),(tmp_string)
				else:
					tmp_string = tmp_string.replace(')','')
					content.reg_addr = tmp_string
					if (rowdata[1].lower().find('dump') != -1):
						content.type = 1
					else:
						content.type = 6
			elif (tmp_string.find('write(') == 0):
				tmp_string = tmp_string.replace('write(','')
				if (tmp_string.find(')') == -1):
					print ("err3 this line"), (tmp_string)
				else:
					tmp_string = tmp_string.replace(')','')
					content.type = 2
					content.reg_addr = tmp_string
					content.reg_value = rowdata[1].lower()

		excel_list.append(copy.deepcopy(content))
		print ("Line is:"), (curr_row)
		curr_row = curr_row + 1
	return excel_list

def read_ddr_excel():
	workbook = xlrd.open_workbook(fname_excel)
	database = []
	for s in workbook.sheets():
		if "ddr_template" != s.name:
			continue
		else:
			ll = read_excel_file(s)
			if -1 == ll or ll == []:
				print ("Error Excel file2\n\r")
				exit(-1)
			database.append(copy.deepcopy(ll))

	last_read_v = 0
	for _table_index in range(len(database)):
		excel_list = database[_table_index]
		for x in range(len(excel_list)):
#			excel_contents.dump_value(excel_list[x])
			print "Will do line:", excel_list[x].line_num
			
			if (excel_list[x].type == 2):
				write_reg_bit(int(excel_list[x].reg_addr, 16), last_read_v | int(excel_list[x].reg_value, 16))
				last_read_v = 0
			elif (excel_list[x].type == 1):
				v = read_reg_bit(int(excel_list[x].reg_addr, 16))
				print('Read value"', excel_list[x].reg_addr, '==', v)
			elif (excel_list[x].type == 6):
				last_read_v = read_reg_bit(int(excel_list[x].reg_addr, 16))
			elif (excel_list[x].type == 3):
				time.sleep(float(excel_list[x].delay_time))
			elif (excel_list[x].type == 4):
				while (1):
					v = read_reg_bit(long(excel_list[x].reg_addr, 16))
					if (v & (long(excel_list[x].reg_value, 16))):
						continue
					else:
						break
			elif (excel_list[x].type == 5):
				while (1):
					v = read_reg_bit(long(excel_list[x].reg_addr, 16))
					if (0 == (v & (long(excel_list[x].reg_value, 16)))):
						continue
					else:
						break

if __name__ == '__main__':
	t32api = jtat_connect()
	jtag_do_cmd(t32api, "sys.up")
#	jtat_disconnect(t32api)
#	read_ddr_excel()
