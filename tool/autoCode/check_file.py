#!/usr/bin/env python
# encoding=utf8

import os
import xlrd
import sys

reload(sys)
sys.setdefaultencoding('utf8')

error_list = []
class error():
	' create error object'
	def __init__(self):
		self.sheet_name = ''
		self.pos = ''   #line No.
		self.error_log = ''
		self.log = ''
	def create_error(self,_sheet_name,_line_no,_error_log):
		self.sheet_name = _sheet_name
		self.pos = _line_no
		self.error_log = _error_log
		self.log =  "sheet name:" + self.sheet_name + ' ' * (15 - len(self.sheet_name)) + "line:" + self.pos + ' ' * (10 - len(self.pos)) + "Error: " + self.error_log
	def get_error(self):
		print self.log

def check_excel_file(s):
	print ("Sheets name: " + s.name)
	nrows = s.nrows
	curr_row = 0
#Get the module name from spec. 
	module_name = []
	base_addr = []
	while curr_row < nrows:
		rowdata = s.row_values(curr_row)
		if type(rowdata[0]) != float:
			tmp_string = rowdata[0].upper()
			if 'BASE:' in tmp_string or 'BASE :' in tmp_string:
				# print "module name is:" + tmp_string
				tmp_string = tmp_string.replace('_BASE','')
				tmp_string = tmp_string.replace('BASE:','')
				tmp_string = tmp_string.replace('BASE :','')
				tmp_string = tmp_string.replace(' ','')
				tmp_string = tmp_string.replace(':','')

				lisss = tmp_string.split('0X')

				module_name.append(lisss[0])
				base_addr.append('0x' + lisss[1].replace('_',''))
				if curr_row + 1 < nrows:
					if s.row_values(curr_row + 1)[0].find("BASE") == -1:
						break
		curr_row += 1
	if module_name and base_addr:
		# print module_name,base_addr
		pass
	else:
		if not module_name:
			error_obj = error()
			error_obj.create_error(str(s.name),"0","Module's name is irregular")
			error_list.append(error_obj)
		if not base_addr:
			error_obj = error()
			error_obj.create_error(str(s.name),"0","Base's address is irregular")
			error_list.append(error_obj)

#Get this module's registers and bits.
	reg_name_tmp = ''
	reg_offset_bak = ''
	while curr_row < nrows:
		rowdata = s.row_values(curr_row)
		# print curr_row
		if type(rowdata[0]) == float:
			rowdata[0] = str(rowdata[0])
		if rowdata[0].find('Offset:',0,20) == 0:#let using the Offset for the center
			find_reg_name = curr_row -1
			while (s.row_values(find_reg_name - 2)[0]):#maybe we have some lines comments.Need to Skip.
				if s.row_values(find_reg_name)[0] == '':
					break
				if s.row_values(find_reg_name - 1)[0] == '':
					break
				find_reg_name = find_reg_name -1

			reg_name = s.row_values(find_reg_name)[0];
			reg_name = reg_name.replace('/','_')
			reg_name = "".join(reg_name.split())
			llll = reg_name.split('(')#Maybe some special comments/regs name/.... at the reg name behind.
			llll = llll[0].split('/')
			llll = llll[0].split(',')
			llll = llll[0].split(' ')
			if (len(llll[0]) > 40):
				error_obj = error()
				error_obj.create_error(str(s.name),str(curr_row+1),"Wrong length of register's name ")
				error_list.append(error_obj)
				# raise "Error length for this register"
			reg_name = llll[0]
			if reg_name == reg_name_tmp:
				error_obj = error()
				error_obj.create_error(str(s.name),str(find_reg_name+1),"Register's name is the same as the previous")
				error_list.append(error_obj)
			if reg_name:
				reg_name_tmp = reg_name
				pass
				# print reg_name
			else:
				error_obj = error()
				error_obj.create_error(str(s.name),str(find_reg_name+1),"Register's name is irregular")
				error_list.append(error_obj)

			short_desc = s.row_values(find_reg_name - 1)[0]

#do {Offset: 'IPC 0' L1 0x34. 'IPC 1' L2 0x38. 'IPC 2' L3 0x3C."}  OR  {Offset: ' ' L1 0x00. ' ' L2 0x8.}
			rowdata[0] = rowdata[0].upper()

			# print rowdata[0]

			llll = rowdata[0].split('T:')#Offset:0x0 OR Offset:0x0-0x4 OR Offset:0x0 - 0x4
			llll = llll[1].strip()

			# print llll

			llll = llll.replace('-0X','.')
			llll = llll.replace('- 0X','.')
			llll = llll.replace(' ','.')
			reg_offset = llll.strip()
			count = reg_offset.count("0X")
			# print count, reg_offset

			if count == 1:
				llll = reg_offset.split('.')#delete".xxx"
				reg_offset = llll[0]
				if  reg_offset == reg_offset_bak:
					error_obj = error()
					error_obj.create_error(str(s.name),str(curr_row+1),"Offset is the same as the previous")
					error_list.append(error_obj)
				reg_offset_bak = reg_offset
				if any([reg > 'F' for reg in reg_offset[2:]]):
					# print reg_offset
					error_obj = error()
					error_obj.create_error(str(s.name),str(curr_row+1),"Offset is irregular")
					error_list.append(error_obj)
			else:
				i = 0
				while 1:
					ret = reg_offset.find("0X")
					if ret != -1:
						_name = reg_name + str(int(i))
						lll = reg_offset.split('0X', 1)
						reg_offset = lll[1]#for the next loop
						if reg_offset.find('.') != -1:
							lll = reg_offset.split('.',1)
							offset_tmp = lll[0].strip()
						else:
							offset_tmp = reg_offset
						offset_tmp = '0x' + offset_tmp
						if  offset_tmp == reg_offset_bak:
							error_obj = error()
							error_obj.create_error(str(s.name),str(curr_row+1),"Offset is the same as the previous")
							error_list.append(error_obj)
						reg_offset_bak = offset_tmp
						# print i , count, offset_tmp, _name, reg_offset

						if i >= count - 1:
							break
					else:
						break

#find the Bits line
			curr_row = curr_row + 1
			while (curr_row < s.nrows):
				# print s.row_values(curr_row)[0]
				if s.row_values(curr_row)[0] == float:
					s.row_values(curr_row)[0] = str(s.row_values(curr_row)[0])
				if (s.row_values(curr_row)[0].strip() == "Bits"):
					break
				curr_row = curr_row + 1
#end
			if (s.row_values(curr_row)[0].strip() != "Bits"):
				raise "Error: \n"
			else:
				bits_row = curr_row + 1 #to the bits number line
				while (bits_row < s.nrows):
					bits_row_data = [str(value) for value in s.row_values(bits_row)]

					if (bits_row_data[0].isdigit() != True and ':' not in bits_row_data[0] and bits_row_data[0] != ""):
						break

					if (bits_row_data[0] == "" and bits_row_data[6] == ""):
						break

					if (bits_row_data[0] != "" and (bits_row_data[1].rstrip().lstrip().upper() != "RESERVED")):
						bit = bits_row_data[0]

						bit_list = bit.split(":")
						# print bit_list
						if bit:
							try:
								if any([int(float(bit_s)) > 31 for bit_s in bit_list]):
									error_obj = error()
									error_obj.create_error(str(s.name),str(bits_row+1),"Wrong bit's length")
									error_list.append(error_obj)
							except:
								print bit_list,"sheet_name:%s nrows:%d Error bits len !\n"%(s.name,bits_row)
						if s.name in["sc2_csi","sc2_mmu"]:
							if bits_row_data[4].rstrip().lstrip().upper() != "RESERVED":
								field_name = bits_row_data[1]
								field_name = "".join(field_name.split())
								rw = bits_row_data[2]
								desc = bits_row_data[5]
								int_value = str(bits_row_data[3])
						else:
							field_name = bits_row_data[2]
							field_name = "".join(field_name.split())
							rw = bits_row_data[3]
							desc = bits_row_data[6]
							int_value = str(bits_row_data[4])
						if rw.upper() in ["RO","R","W","WO","RW","RW_IO","RO_FV","RO_WT","RW1C","RWAC"]:
						# if all([ch in "RWO" for ch in rw.upper()]):
							pass
						else:
							if rw.upper():
								error_obj = error()
								error_obj.create_error(str(s.name),str(bits_row+1),"field's RW is irregular")
								error_list.append(error_obj)
							else:
								error_obj = error()
								error_obj.create_error(str(s.name),str(bits_row+1),"field's has no RW")
								error_list.append(error_obj)
						if int_value:
							pass
						elif rw.upper() != "RSVD" and 'R' in rw.upper():
							# print int_value
							error_obj = error()
							error_obj.create_error(str(s.name),str(bits_row+1),"field has no init value")
							error_list.append(error_obj)
						# print "bit:[%s],field_name:[%s],rw:[%s],desc:[%s],int_value:[%s]"%(bit,field_name,rw,desc,int_value)
					curr_row = bits_row
					bits_row = bits_row + 1

		curr_row = curr_row + 1
	return 0



if __name__ == "__main__":
	workbook = xlrd.open_workbook("./excel/AquilaC_Registers.xls")
	for index,s in enumerate(workbook.sheets()):
		if s.name in ["Overview", "DocHistory", "Readme", "blank4"]:
			continue
		check_excel_file(s)
		# if sys.argv[1] == '0':
			# check_excel_file(s)
		# elif int(index) == int(sys.argv[1]) + 2:
			# check_excel_file(s)
			# while 1: pass
	print "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	fail_log = open("fail_log.log","w")
	for error_obj in error_list:
		fail_log.write(error_obj.log + "\n")
		error_obj.get_error()
	fail_log.close()
	print "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"

