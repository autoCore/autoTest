#!/usr/bin/env python
"""
@author: binwu
"""

import re
import os

sucess = 'sucess'
fail = 'fail'

#usages
#Output: ./modules/ddr/drivers/ddr_init/cmm/   "lpddr4_init_3200.cmm","lpddr4_init_2667.cmm","lpddr4_init_2133.cmm","lpddr4_init_1600.cmm","lpddr4_init_1066.cmm"
#1:You must run this script in ctest base directory
#2:You can run this script directly, $ python ./tool/c_translate_cmm.py

								
def make_command(addr,value,_type):
	if len(addr.strip()) == 10:
		addr = '(' + addr.strip() + ')'
	else:
		addr = '(' + '&' + addr.replace(' ','') + ')'
	_type = '%' + _type
	command_list = ['data.set',addr,_type,value]	
	command = ' '.join(command_list)
	
	return command
def make_command_or(addr,value,_type):
	addr = addr.strip()
	command_list = []
	if len(addr) == 10:
		addr = '(' + addr + ')'
	else:
		addr = '(' + '&' + addr.replace(' ','') + ')'
	
	_type = '%' + _type
	if _type == '%long':	
		base_value = '&RegVal_32'
	else:
		base_value = '&RegVal_16'	
	
	if '0x' not in value:
		value_list = value.split('|')
		value = '|&'.join(value_list)
		value = '&' + value
		# print value
		
	command = base_value + '=' + 'Data.Long' + '(' + 'c:' + addr + ')' 
	command_list.append(command)
	value = base_value + '|' + value
	command_tmp = ['data.set',addr,_type,value]
	command = ' '.join(command_tmp)
	command_list.append(command)
	
	return command_list
def make_command_read(code_text):
	command_list = []
	code_text = code_text.replace(' ','')
	local_var = '&RegVal'
	if 'while' in code_text:
		command = local_var + '=0'
		command_list.append(command)
		pattern = re.compile('.*?while\((.*?)\){(.*?)=.*?\((.*?)\).*')
		try:
			search_tuple = re.search(pattern,code_text).groups()
		except:
			print 'No matched! Please check source file !'
			return None
		# print code_text
		# print search_tuple
		_command = search_tuple[0]
		read_var = search_tuple[1]

		_command = _command.replace(read_var,local_var)
		command = 'while ' + _command.replace(' ', '')
		command_list.append(command)
		
		addr = search_tuple[2].replace(' ','')
		if len(addr) == 10:
			addr = '(' + addr + ')'
		else:
			addr = '(' + '&' + addr + ')'
		
		command = '	' + local_var + '=' + 'Data.Long' + '(' + 'c:' + addr + ')' 
		command_list.append(command)	
		
	return command_list

	
def translate(source,target):
	read_code_flag = 0
	code_text = ''
	with open(source,'r') as sfile,open(target,'w') as tfile:
		for line_no,each_line in enumerate(sfile):
			each_line = each_line.strip()
			if '//' in each_line[:2]: #except commented
				continue
				
			if each_line:
				pass
			else:					  #except blank line
				print 'line_no: %d'%(line_no+1),'is blank line'
				tfile.write('\n')
				continue
				
			if '=' in each_line[:each_line.find('REG')+1]:
				read_code_flag = 1
				
			if read_code_flag and '}' not in each_line :
				code_text += each_line
				continue
			elif read_code_flag:
				code_text += each_line
				command_list = make_command_read(code_text)
				if command_list:
					pass
				else:
					print 'read type search fail'
				for command in command_list:
					tfile.write(command + '\n')
				tfile.write('\n')
				read_code_flag = 0
				code_text = ''
				continue
			
			addr = value = _type = ''		
			try:
				pattern = re.compile('.*?REG(?:16|32)\((.*?)\).*?=.*?0x(.*?);.*')
				addr = re.search(pattern,each_line).group(1)
				value = re.search(pattern,each_line).group(2)
			except:	
				if '0x' not in each_line and '|=' in each_line:
					_each_line = each_line.replace(' ','')
					pattern = re.compile('.*?REG(?:16|32)\((.*?)\)\|=(.*?);.*')
					search_res = re.search(pattern,_each_line).groups()
					# print search_res
					addr = search_res[0]
					value = search_res[1]
				elif each_line:
					print 'line_no: %d'%(line_no+1),'No matched!   ','Please translate manually!!!'
					tfile.write('\n' + str(line_no+1) + ':' + '< ' + each_line + ' >' + ' Please translate manually!!! \n\n')
					continue	
			if all([addr,value]):
				if len(value) > 8:
					pass
				else:	
					value = '0x' + value.strip()
				# print 'line_no: %d  addr: %s  value: %s  '%(line_no+1,addr,value)
				if 'REG32' in each_line:
					_type = 'long'
				elif 'REG16' in each_line:
					_type = 'short'
				
				if '|=' in each_line: 
					command_list = make_command_or(addr,value,_type)
					for command in command_list:
						tfile.write(command + '\n')
					continue
				
				command = make_command(addr,value,_type)
				# print command
				tfile.write(command + '\n')				
	return sucess

dir_s = r'./modules/ddr/drivers/ddr_init/'
dir_t = r'./modules/ddr/drivers/ddr_init/cmm/'

file_data_s = [dir_s + "lpddr4_init_3200.c",dir_s + "lpddr4_init_2667.c",dir_s + "lpddr4_init_2133.c", dir_s + "lpddr4_init_1600.c", dir_s + "lpddr4_init_1066.c"]
file_data_t = [dir_t + "lpddr4_init_3200.cmm",dir_t + "lpddr4_init_2667.cmm",dir_t + "lpddr4_init_2133.cmm",dir_t +"lpddr4_init_1600.cmm",dir_t + "lpddr4_init_1066.cmm"]

# file_data_s = [dir_s + "lpddr4_init_1066.c"]
# file_data_t = [dir_t + "lpddr4_init_1066.cmm"]
	
if __name__ == '__main__':	
	for file_data_dir_s in file_data_s:
		if os.path.isfile(file_data_dir_s):
			pass
		else:
			print file_data_dir_s,'not exist'
			print 'Please run this script in ctest base directory!'
			exit(0)
	isExists = os.path.exists(dir_t)
	if isExists:
		pass
	else:
		os.mkdir(dir_t)
	os.system(r'chmod +w ' + dir_t)
	
	
	for file_data_dir_s,file_data_dir_t in zip(file_data_s,file_data_t):
		print 'file:',file_data_dir_s[-18:]
		if sucess == translate(file_data_dir_s,file_data_dir_t):
			print "translate done!\n"
		else:
			print "translate fail!!!\n"

	print "End!\n"

