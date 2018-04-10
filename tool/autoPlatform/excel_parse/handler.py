#! /usr/bin/env python
import re
import copy

class Handler:
	def callback(self, prefix, name, *args):
		method = getattr(self, prefix+name, None)
		if callable(method): return method(*args)
	def do(self,name,*args):
		self.callback('do_',name,*args)

register_list = []
class RegisterRenderer(Handler):
	"""docstring for RegisterRenderer"""
	def do_capbase(self,block,register,regfield):
		block = [row[0].upper() for row in block]
		for _string in block:
			match =  re.search('BASE[ ]?:(.*?)0X([a-fA-F0-9\_]+)',_string)
			if match:
				module_name = match.group(1).strip()
				module_name = module_name.split()[0]
				module_name = module_name if 'BASE' in module_name else module_name + '_BASE'
				base_addr = '0x' + match.group(2).strip().replace('_','')
				register.addBase(module_name, base_addr)

	def do_capregister(self,block,register,regfield):
		try:
			block = [ value for value in block if value[0]]
			if len(block) == 3:
				short_desc = block[0][0].strip()
				reg_name = block[1][0].strip()
				off_set_str = block[2][0].upper()
			elif len(block) == 4:
				short_desc = block[0][0].strip()
				reg_name = block[1][0].strip()
				off_set_str = block[3][0].upper()
			elif len(block) == 2:
				short_desc = ''
				reg_name = block[0][0].strip()
				off_set_str = block[1][0].upper()
			else:
				reg_name = block[1][0].strip()
				off_set_str = block[-1][0].upper()
			off_set = off_set_str.split('T:')#Offset:0x0 OR Offset:0x0-0x4 OR Offset:0x0 - 0x4
			off_set = off_set[1].strip()
			off_set_l = off_set.split('-')
			off_set_l = [eval(_str.strip()) for _str in off_set_l]
			if '-' in off_set:
				off_set_l = range(off_set_l[0],off_set_l[1]+1,4)
			off_set_l = [str(hex(l)) for l in off_set_l]
			# print llll
			register.fillInfo(reg_name, short_desc, short_desc)
			for offset in off_set_l:
				register.addOffset(offset)
		except Exception,e:
			pass

	def do_capregfield(self,block,register,regfield):
		keys = [_str.strip() for _str in block[0]]
		for row in block[1:]:
			field_d = {key.replace(" ",""):value for key,value in zip(keys,row)}
			try:
				regfield.update(field_d)
			except:
				print field_d
				raw_input()
			register.addRegField(copy.deepcopy(regfield))
		register_list.append(copy.deepcopy(register))
		register.clear()


