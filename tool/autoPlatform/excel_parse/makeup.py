#! /usr/bin/env python

import sys,re,os
from handler import *
from util import *
from rules import *
import xlrd

from xml.dom.minidom import Document
from create_xml import output_xml_filed
from create_xml import output_xml_register
from create_xml import output_xml_registers
from create_xml import xml_create_basic_struct

reload(sys)
sys.setdefaultencoding('utf-8')

class Table:
	def __init__(self, table_name):
		self.table_name = table_name
		self.project_name = ''
		self.module_base_d = {}

	def addBase(self,module_name,base):
		self.module_base_d[module_name] = base

class RegField:
	def __init__(self):
		self.field_name = ''
		self.bit_field = ''
		self.rw = ''
		self.reset_value = ''
		self.init_value = ''
		self.desc = ''
		self.bits_row = ''

	def update(self,field_dict):
		self.field_name = field_dict.get('Field(Code)')
		self.bit_field = field_dict['Bits']
		self.rw = field_dict.get('Type')
		self.reset_value = field_dict.get('Reset',None)
		self.init_value = field_dict['Init']
		self.desc = field_dict['Description']
		self.bits_row = field_dict['Type']

class Register(Table):
	def __init__(self,table_name):
		Table.__init__(self,table_name)
		self.reg_name = ''
		self.reg_offsets = []

		self.short_desc = ''
		self.detail = ''
		self.reg_fields = []

	def fillInfo(self, reg_name,short_desc, detail_desc):
		self.reg_name = reg_name
		self.short_desc = short_desc
		self.detail = detail_desc
	def addOffset(self,offset):
		self.reg_offsets.append(offset)

	def addRegField(self, reg_field):
		self.reg_fields.append(reg_field)

	def is_NoBits(self):
		return bool(len(self.reg_fields))

	def is_MultiOffset(self):
		return bool(len(self.reg_offsets))

	def clear(self):
		self.reg_offsets = []
		self.reg_fields = []

class Parse:
	def __init__(self, handler):
		self.handler = handler
		self.rules = []
	def addRule(self,rule):
		self.rules.append(rule)

	def parse(self, file):
		s_list = [s for s in file if s.name not in ['Overview','DocHistory','Readme','AIBmfpr_list', 'Sheet1','Sheet2'] ]
		for s in s_list:
			register = Register(s.name)
			regfield = RegField()
			for block in blocks(s):
				for rule in self.rules:
					if rule.condition(block):
						if rule.action(block,handler,register,regfield): break
		return register_list

class BasicTextParse(Parse):
	def __init__(self, handler):
		Parse.__init__(self,handler)
		self.addRule(BaseRule())
		self.addRule(RegisterRule())
		self.addRule(RegfieldRule())

if __name__ == '__main__':
	handler = RegisterRenderer()
	parser = BasicTextParse(handler)

	os.system('rm ./tmp -rf')
	os.mkdir("./tmp")
	fname_excel = "./excel/AquilaC_Registers.xls"
	workbook = xlrd.open_workbook(fname_excel)
	register_list = parser.parse(workbook.sheets())
	reg_base_string = ["#define	REGS_% -50s %s"%(module_name,base) for register in register_list \
						if register.module_base_d for module_name,base in sorted(register.module_base_d.items(),key=lambda item:item[0])]
	reg_base_string = sorted(set(reg_base_string),key=reg_base_string.index)
	base_file = open("./tmp/__regs_base_addr.h",'w')
	base_file.write('\n'.join(reg_base_string))
	base_file.flush()
	base_file.close()
	fname = ''
	register_define_list = []
	bits_field_list = []

	file_d = {register.table_name.lower():[] for register in register_list}
	for register in register_list:
		file_d[register.table_name.lower()].append(register)

	doc = Document()
	spirit_addressBlock = xml_create_basic_struct(doc)
	for key in file_d:
		fname = "./tmp/__regs_%s.h"%key
		print fname
		fobj = open(fname,'w')
		c_head_file = open('c_header_file_head')
		fobj.write(''.join(c_head_file.readlines()))
		fobj.write("\n")

		micro_base_str = ''.join(sorted(file_d[key][0].module_base_d.keys()))
		micro_base_str = "REGS_" + micro_base_str.replace('_BASE','')
		header_macro = '#ifndef __H_%s_HEADFILE_H__'%micro_base_str
		header_macro1 = header_macro.replace('#ifndef','#define') + ' __FILE__'
		header_macro2 = '\n#define %s'%micro_base_str
		# print '\n'.join([header_macro,header_macro1,header_macro2])
		fobj.write('\n'.join([header_macro,header_macro1,header_macro2]))
		registers_define_comment_string = '/* registers definitions for %s */'%micro_base_str
		register_define_list.append('\n\n'+registers_define_comment_string)

		for register in file_d[key]:
			register_body = output_xml_register(doc, spirit_addressBlock, register.reg_name, \
				register.short_desc, "".join(register.reg_offsets), "32", "true", "read-write","0", "0xffffffff")
			reg_name_micro = '_'.join([micro_base_str,register.reg_name])
			for module in sorted(register.module_base_d.keys()):
				for offset in register.reg_offsets:
					register_define_list.append('\n#define % -50sASR_ADDR(REGS_%s, %s)/*%s*/'\
												%(reg_name_micro,module,offset.upper(),register.detail))

			if  register.is_NoBits():
				bits_define_comment_str = "\n/* bits definitions for register %s */\n"%reg_name_micro
				bits_field_list.append(bits_define_comment_str)
				for sub_bits in register.reg_fields:
					if sub_bits.field_name:
						if ":" in str(sub_bits.bit_field):
							bit_end,bit_start = sub_bits.bit_field.split(":")
							filed_bitWidth = eval(bit_end) - eval(bit_start) + 1
							_bit_list = ["BIT(%s)"%_bit for _bit in range(eval(bit_start),eval(bit_end)+1)]
							micro1_str = "BITS_%s(_X_)"%sub_bits.field_name.upper().replace(' ','')
							if eval(bit_start):
								micro2_str ='( (_X_) << %s & ( %s ) )'%(bit_start,"|".join(_bit_list))
							else:
								micro2_str ='( (_X_) & ( %s ) )'%("|".join(_bit_list))
							_str = "#define % -50s %s\n"%(micro1_str,micro2_str)
							# print _bit_list,bit_end,bit_start
							bits_field_list.append(_str)
							bits_desc = sub_bits.desc.rstrip().lower()
							rw = sub_bits.rw.rstrip().lower()
							init_value = sub_bits.reset_value
							astring = sub_bits.field_name
							output_xml_filed(doc, register_body, astring.rstrip().upper(), bits_desc,\
												bit_start, str(filed_bitWidth), rw, init_value , " ")
						else:
							micro1_str = "BIT_%s"%sub_bits.field_name.upper().replace(' ','')
							_str = "#define % -50s ( BIT(%s) )\n"%(micro1_str,sub_bits.bit_field)
							bits_field_list.append(_str)

		if register_define_list:
			register_define_list.append("\n\n\n")
			fobj.write(''.join(register_define_list))
			register_define_list = []
		if bits_field_list:
			fobj.write(''.join(bits_field_list))
			bits_field_list = []
		fobj.write("\n#endif\n")
		fobj.flush()
		fobj.close()

		xml_fname = "./tmp/%s.xml"%key
		print xml_fname
		xml_obj = open(xml_fname,'w')
		_string = '''<?xml version="1.0" encoding="UTF-8"?>
		<spirit:component xmlns:kactus2="http://funbase.cs.tut.fi/" xmlns:spirit="http://www.spiritconsortium.org/XMLSchema/SPIRIT/1.5" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://www.spiritconsortium.org/XMLSchema/SPIRIT/1.5 http://www.spiritconsortium.org/XMLSchema/SPIRIT/1.5/index.xsd">
			<spirit:vendor>org.example</spirit:vendor>
			<spirit:library>example_lib</spirit:library>
			<spirit:name>'''
		_string = _string + key
		_string = _string + '''</spirit:name>
			<spirit:version>example_version</spirit:version>'''

		xml_obj.write(_string)

		xml_obj.write(doc.toprettyxml(indent = ''))

		xml_obj.write('''</spirit:component>''')
		xml_obj.close()

		lines = [l for l in open(xml_fname, "r")]
		lines[5] = lines[5].replace('<?xml version="1.0" ?>','')
		xml_obj = open(xml_fname,'w')
		xml_obj.writelines(lines)
		xml_obj.close()
