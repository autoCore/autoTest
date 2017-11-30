#!/usr/bin/env python

'create c/header file automatic @zhenbo.zhan'

import os
import dict
import xlrd
import sys
from string import Template
import copy
import readTextFile
import readExcel
from readExcel import interrupt_contents

'ipxact: import this lib'
from xml.dom.minidom import Document
from create_xml import output_xml_filed
from create_xml import output_xml_register
from create_xml import output_xml_registers
from create_xml import xml_create_basic_struct

debug = True

reload(sys)
sys.setdefaultencoding('utf8')

if(len(sys.argv) < 2):
	print ('Error: Pls enter/Pass the correct command.', len(sys.argv))
fname_excel = str(sys.argv[1])

isExists = os.path.exists('./tmp')
if not isExists:
	os.mkdir(r'./tmp')
os.system(r'chmod +w tmp')

'read all infos from excel to class-object'
workbook = xlrd.open_workbook(fname_excel)

os.chdir(r'./tmp')

'ipxact: write ipxact headers draft code '


'end of ipxact draft code'

def is_bits_name_exist(name, skip_table_index, skip_m_list, skip_j_sublist):
	for _table_index in range(len(database)):
		excel_list = database[_table_index]
		for i in range(len(excel_list)):
			if excel_list[i].has_bits == 0:
				continue
			else:
				for j in range(len(excel_list[i].sub_list)):
					if (skip_table_index == _table_index and skip_m_list == i and skip_j_sublist == j):
						continue
					if excel_list[i].sub_list[j].field_name.rstrip().lower() == name.rstrip().lower():
						if (skip_table_index == _table_index and skip_m_list == i):
#							print "Same table and same register have the same bits " + name.rstrip().lower()
							return 2
						if (skip_table_index == _table_index):
#							print "Same table has the same bits " + name.rstrip().lower()
							return 3
						else:
#							print "different table has the same bits " + name.rstrip().lower()
							return 1
	return 0#cannot find the same definition

def write_int(excel_list):
	llll = fname_excel.split('/')
	if len(llll[-1]) > 15:
		fname = llll[-1][0:15]
	else:
		fname = llll[-1]
	print fname
	file_int = open(fname + '.h', 'w')
	for x in range(len(excel_list)):
		name = excel_list[x].interrupt_name
		num = excel_list[x].interrupt_num
		tmp = dict.return_dict('define') + dict.return_dict('irq') + name
		dsc = excel_list[x].description
		'add tab Or space in the line'
		num_tab = 50
		num_tab = num_tab - len(tmp)
		if (num_tab <=0):
			num_tab = 8

		if (len(dsc) > 1):
			dsc = "//" + dsc
		else:
			dsc = ""
		reg_base_string = tmp + num_tab *" " + num + dsc

		file_int.write(reg_base_string + "\n")
	print "write" + fname + ".h over"
	file_int.close()

fobj_base_reg = open("./~tmp", 'w')
fobj_base_reg.close()
open_ref = 0

database = []
for s in workbook.sheets():
	if "Overview" == s.name or "DocHistory" == s.name or "Readme" == s.name or "blank4" == s.name:
		continue
	ll = readExcel.read_excel_file(s)
	if -1 == ll or ll == []:
		continue
	database.append(copy.deepcopy(ll))

#exit(0)
print "Collect all the data info to database\n\r"
for _table_index in range(len(database)):
	excel_list = database[_table_index]
	if (isinstance(excel_list[0], interrupt_contents)):
		print "Do an interrupt object begin"
		write_int(excel_list)
		continue

	all = readTextFile.read_code_file("../c_header_file_head")

	fname = dict.return_dict('file_name_begin') + excel_list[0].project_name.rstrip().lower()
	fname += excel_list[0].table_name.lower() + dict.return_dict('file_name_end')
	print "Create head file:" + fname

	fobj = open(fname, 'w')
	fobj.write(''.join(all))

	fobj.write('\n');
	astring = dict.return_dict('header_macro_begin1')
	tmp0 = excel_list[0].module_name.rstrip().upper()
	tmp = "REGS_" + tmp0
	astring += tmp
	astring += dict.return_dict('header_macro_end1')
	astring += "\n"
	astring = astring.replace(',','')
	fobj.write(''.join(astring))

#handle the base adress to one file "__regs_base_addr.h", need to scan every register file.
	if (open_ref == 0):
		fobj_base_reg = open("__regs_base_addr.h", 'w')
		open_ref = 1

	count = tmp0.count(',')#maybe module_name = ssp0,ssp1, base_addr=0x2a000000,0x2d000000
	i = 0
#ipxact: modules
	doc = Document()
	spirit_addressBlock = xml_create_basic_struct(doc)
#end
	while i <= count:
		llll = tmp0.split(',')
		nnnn = excel_list[0].base_addr.split(',')
		'add tab Or space in the line'
		num_tab = 50
		num_tab = num_tab - len(llll[i])
		if (num_tab <=0):
			num_tab = 8
		reg_base_string = "#define	"  + "REGS_" + llll[i] + "_BASE" + num_tab *" " + nnnn[i]
		fobj_base_reg.write(reg_base_string + "\n")
#ipxact: modules
		if (i == 0):#only output one....sad...
			output_xml_registers(doc, spirit_addressBlock, nnnn[0], '0x2000','32',' ', 'true')
#end ipxact
		i = i + 1
#end

#ipxact: register mail body

#end ipxact
	astring = dict.return_dict('header_macro_begin2')
	astring += tmp
	astring += dict.return_dict('header_macro_end2')
	astring += "\n\n"
	astring = astring.replace(',','')#when write to file, we delte the some char, TODO for optimization
	fobj.write(''.join(astring))

	'For summary the file conntens, we can write this MACRO at the file upper line: #define REGS_MM_AHB'
	tmp = "#define	" + tmp + "\n\n"
	fobj.write(tmp)

	bits_prefix_string = dict.return_dict('bits_begin') #for multi bits
	bit_prefix_string = dict.return_dict('bit_begin') #for only sigle bit

	'/* registers definitions for controller REGS_MM_AHB */'
	astring = dict.return_dict('registers_define_comment_string_begin')
	astring += excel_list[0].module_name.rstrip().upper()
	astring += dict.return_dict('registers_define_comment_string_end')
	astring += '\n'
	astring = astring.replace(',','')
	fobj.write(''.join(astring))

	if 1:
		'write register list'
		for x in range(len(excel_list)):
			#print ('klist[%d]:'%x, excel_list[x].reg_name)
			'Using Template to create headerfile MACRO defined'

			i = 0#handle multi-modules in one table
			while i <= count:
				llll = tmp0.split(',')
				reg_prefix_string = dict.return_dict('reg_begin') + llll[i] + "_"
				tmp_prefix = dict.return_dict('define') + reg_prefix_string
				s = Template(tmp_prefix + '$regname$TAB_NUM$value''$desc')

				detail = ''
				if ('' != excel_list[x].detail):
					detail = '/*' + excel_list[x].detail + '*/'

				'add tab Or space in the line'
				num_tab = 58 #for tab is 7, for sapce is
				num_tab = num_tab - len(tmp_prefix + excel_list[x].reg_name) #/8
				if (num_tab <= 0):
					num_tab = 4 #for tab is 1, for sapce is ..

				if type(excel_list[x].reg_offset) != 'str':
					excel_list[x].reg_offset = str(excel_list[x].reg_offset)

				tmp = dict.return_dict('registers_addr_begin') + llll[i] + dict.return_dict('registers_addr_middle') + excel_list[x].reg_offset + dict.return_dict('registers_addr_end')
				astring = s.substitute(regname= excel_list[x].reg_name, TAB_NUM=int(num_tab)*''' ''',value=  tmp, desc=detail)
				astring += "\n"
				#print(astring)
				fobj.write(''.join(astring))
				i = i + 1

		'we need to handle sub rows(multi rows) that belong one register'
		astring = "\n\n"
		fobj.write(''.join(astring))

		for i in range(len(excel_list)):
#ipxact:
			register_body = output_xml_register(doc, spirit_addressBlock, excel_list[i].reg_name, excel_list[i].short_desc, excel_list[i].reg_offset, "32", "true", "read-write","0", "0xffffffff")
#end ipxact

			if excel_list[i].has_bits == 0:
				continue
			'write comment for define bits'
			astring = '\n' + dict.return_dict('bits_define_comment_string_begin') + reg_prefix_string
			astring += excel_list[i].reg_name + dict.return_dict('bits_define_comment_string_end')
			fobj.write(''.join(astring))

			for j in range(len(excel_list[i].sub_list)):
				bit = str(excel_list[i].sub_list[j].bit)
#				print "Pppp:" + excel_list[i].reg_name
#bits_row
				flag = is_bits_name_exist(excel_list[i].sub_list[j].field_name, _table_index, i, j)
				bits_desc = excel_list[i].sub_list[j].desc.rstrip().lower()
				rw = excel_list[i].sub_list[j].rw.rstrip().lower()
				init_value = excel_list[i].sub_list[j].reset_value
				if (flag == 0):#same
					astring = excel_list[i].sub_list[j].field_name.rstrip().lower()
				else:
					magic_string = str(excel_list[i].sub_list[j].bits_row)
					if (flag == 1):
						_len = len(excel_list[i].module_name)
						_prefix_len = 0
						if (_len < 6):
							_prefix_len = _len
						else:
							_prefix_len = 6
						astring = excel_list[i].module_name[0:_prefix_len - 1] + "_" + excel_list[i].sub_list[j].field_name.rstrip().lower() + magic_string
					else:#same table
						astring = excel_list[i].sub_list[j].field_name.rstrip().lower() + magic_string

				astring = astring.replace(',','')
				if (astring != "reserved"):
					filed_bitWidth = 1
					bit_start = 0
					list = bit.partition(':')
					bit_start = list[0]
					tmp = ''
					tmp_x = ''
					tmp_mult_bit_0 = ''
					tmp_mult_bit_1 = ''
					bit_string = ''
					if (list[1] == ':'):# and (int(list[0]) - int(list[2]) < 31)): #for example 31:28
						tmp_x = "(_X_)"
						if ((int)(list[2]) != 0):
							tmp_mult_bit_0 = tmp_x + " << " + list[2] + " & (" #(_x_) << 0 &
						else:
							tmp_mult_bit_0 = tmp_x + " & ("
						tmp_mult_bit_1 = ")"
						tmp = int(list[2])
						bit_start = list[2]
						filed_bitWidth = int(list[0]) - tmp + 1
						while (tmp <= int(list[0])):
							#print ('j:', dict.return_dict(str(tmp)))
							if (bit_string == ''):
								bit_string = dict.return_dict(str(tmp))
							else:
								bit_string += ('|' + dict.return_dict(str(tmp)))
							tmp = tmp + 1
					else:
						try:
							tmp = int(round(float(list[0])))
						except:
							print list
							continue
						bit_string = dict.return_dict(str(tmp))

					'bit define'
					if (list[1] == ':'):
						astring2 = dict.return_dict('define') + bits_prefix_string
					else:
						astring2 = dict.return_dict('define') + bit_prefix_string

					astring2 += astring.rstrip().upper()
					astring2 += tmp_x
#ipxact:
					output_xml_filed(doc, register_body, astring.rstrip().upper(), bits_desc, 
					bit_start, str(filed_bitWidth), rw, init_value , " ")
#end ipxact:
					'add tab in the line'
					num_tab = 58 #for tab is 7, for sapce is 118
					num_tab = num_tab - len(astring2) #/8
					if (num_tab <= 0):
						num_tab = 4
					astring2 = astring2 + int(num_tab) * ' '

					if (list[1] == ':' and (int(list[0]) - int(list[2]) == 31)): #for example 31:0, we don't use | bit, because
						bit_string = ''#a lot of bits need add, so don't need this value.(mask 0xffffffff)
						tmp_mult_bit_0 = tmp_x
						tmp_mult_bit_1 = ""
						astring2 += (tmp_mult_bit_0 + bit_string + tmp_mult_bit_1)
					else:
						astring2 += "( " + (tmp_mult_bit_0 + bit_string + tmp_mult_bit_1) + " )"
					astring2 = astring2 + '\n'
					fobj.write(''.join(astring2))


	astring = "\n" + dict.return_dict('end_macro') + "\n"
	fobj.write(''.join(astring))

	fobj.close()

	print ('completed this file Done!')

	'ipxact:output to xml file'
	#output
	filename = excel_list[0].table_name.lower() + '.xml'
	print filename
	f = open(filename,'w')
	_string = '''<?xml version="1.0" encoding="UTF-8"?>
	<spirit:component xmlns:kactus2="http://funbase.cs.tut.fi/" xmlns:spirit="http://www.spiritconsortium.org/XMLSchema/SPIRIT/1.5" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://www.spiritconsortium.org/XMLSchema/SPIRIT/1.5 http://www.spiritconsortium.org/XMLSchema/SPIRIT/1.5/index.xsd">
		<spirit:vendor>org.example</spirit:vendor>
		<spirit:library>example_lib</spirit:library>
		<spirit:name>'''
	_string = _string + excel_list[0].table_name.lower()
	_string = _string + '''</spirit:name>
		<spirit:version>example_version</spirit:version>'''

	f.write(_string)

	f.write(doc.toprettyxml(indent = ''))

	f.write('''</spirit:component>''')
	f.close()

	lines = [l for l in open(filename, "r")]
	lines[5] = lines[5].replace('<?xml version="1.0" ?>','')
	f = open(filename,'w')
	f.writelines(lines)
	f.close()
	'end of ipxact:output to xml file'

print "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
fobj_base_reg.close()

