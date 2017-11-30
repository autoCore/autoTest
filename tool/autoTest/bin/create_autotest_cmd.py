#!/usr/bin/python
import sys
import os
from config import *

voltage_max = 1050000
voltage_min = 700000
delta = 12500

voltage_grade = (voltage_max - voltage_min)/delta + 1
voltage_list = range(voltage_max,voltage_min - 1,-12500)

clst_list = (['%03d'%i for i in range(5,-1,-1)],['%03d'%i for i in range(70,-1,-10)],['%03d'%i for i in range(800,-1,-100)])
clst_all_value_list = [clst_value for clst in clst_list for clst_value in clst]

clst_all_multi = [(str(i)+str(j)+str(k))for i in range(8,-1,-1) for j in range(7,-1,-1) for k in range(5,-1,-1)]

autotest_cmd_dir = cfg.autocmd_file_dir
def creat_autotest_cmd(_input_cmd,_input_timeout,repeat_cnt = 1):
	input_cmd_string = '@'.join(_input_cmd)
	input_timeout_string = '@'.join(_input_timeout)
	repeat_cnt = '[' + str(repeat_cnt) + ']'
	input_string = '#'.join([input_cmd_string,input_timeout_string,str(repeat_cnt)])
	return input_string

'''
table_vmin = {'0005':950000,'0004':850000,'0003':775000,'0002':762500,'0001':762500,'0000':762500,\
			  '1070':962500,'1060':912500,'1050':812500,'1040':762500,'1030':762500,'1020':762500,'1010':762500,'1000':762500,\
			  '2800':1012500,'2700':900000,'2600':862500,'2500':775000,'2400':762500,'2300':762500,'2200':762500,'2100':762500,'2000':762500}
'''
table_vmin = {'0005':950000,'0004':850000,'0003':775000,'0002':775000,'0001':775000,'0000':775000,\
			  '1070':987500,'1060':937500,'1050':837500,'1040':775000,'1030':775000,'1020':775000,'1010':775000,'1000':775000,\
			  '2800':1012500,'2700':912500,'2600':862500,'2500':775000,'2400':762500,'2300':762500,'2200':762500,'2100':762500,'2000':762500}
def cci_boot_core(clst):
	clst = clst[0]
	boot_core = ["boot 00f","boot 0f0","boot 300"]
	if clst[:2] == '00':
		boo_cmd = "boot 00f"
	elif clst[1:] == '00':
		boo_cmd = "boot 300"
	else:
		boo_cmd = "boot 0f0"
	return boo_cmd

def create_cci_test_cmd():
	cmd_list = []
	cci_list = range(13)
	boot_core = ["boot 00f","boot 0f0","boot 300"]
	clst_list = table_vmin.keys()
	clst_list.sort(reverse = True)
	for clst in clst_list:
		set_col_freq = ' '.join(['set',str(table_vmin[clst]),clst[1:]])
		for cci_freq in cci_list:
			input_cmd = [set_col_freq,'set_cci '+str(cci_freq),cci_boot_core(clst)]
			timeout_list = ['2','2','15']
			cmd_list.append(creat_autotest_cmd(input_cmd,timeout_list))
			# print creat_autotest_cmd(input_cmd,timeout_list)
	with open(cfg.autocmd_file_dir,'w') as cmd_obj:
		for cmd_str in cmd_list:
			cmd_obj.write(cmd_str + '\n')

	return cfg.autocmd_file_dir

ddr_voltage_list = range(950000,700000,-12500)
def create_ddr_vmin_cmd():
	cmd_list = []
	for voltage_value in ddr_voltage_list:
		cmd_string = ['set',str(voltage_value),'0x000']
		cmd_string = ' '.join(cmd_string)
		input_cmd = [cmd_string,'ddr_fc 0','boot 2','ddr_fc 1','boot 2','ddr_fc 2','boot 2','ddr_fc 3','boot 2']
		timeout_list = ['1','1','15','1','15','1','15','1','15'] #ctest running cmd timeout

		cmd_list.append(creat_autotest_cmd(input_cmd,timeout_list))
		# print cmd_string
	with open(cfg.autocmd_file_dir,'w') as cmd_obj:
		for cmd_str in cmd_list:
			cmd_obj.write(cmd_str + '\n')

	return cfg.autocmd_file_dir

table_dict ={'005':1012500,'004':912500,'003':825000,'002':825000,'001':825000,'000':825000,\
			 '070':1025000,'060':975000,'050':875000,'040':825000,'030':825000,'020':825000,'010':825000,'000':825000,\
			 '800':1050000,'700':1000000,'600':925000,'500':825000,'400':825000,'300':825000,'200':825000,'100':825000,'000':825000}

def create_voltage_list(clst_value):
	global voltage_grade
	voltage_grade = 11
	voltage_list = range(table_dict[clst_value],table_dict[clst_value] - voltage_grade * 12500, -12500)
	return voltage_list


def create_cpu_vmin_cmd(clst = 'all',mult = 's'):
	cmd_list = []
	clst_value_list = []
	if mult == 's':
		if clst in (range(3) + map(str,range(3))):
			clst_value_list = clst_list[int(clst)]
			# print clst_value_list
		elif clst != 'all':
			print 'Pls check your input cmd,agrv in (0-2) or ignore'
			return None
	elif mult == 'm':
		clst_value_list = clst_all_multi
	else:
		print 'Pls check your input cmd,agrv in (0-2) or ignore'
		return None

	cmd_boot_list = ['boot f','boot f0','boot 300']
	if clst == 'all' and mult == 's':
		for i in range(3):
			for clst_value in clst_list[i]:
				# for voltage_value in create_voltage_list(clst_value):
				for voltage_value in voltage_list:
					cmd_string = ['set',str(voltage_value),'0x'+str(clst_value)]
					cmd_string = ' '.join(cmd_string)
					input_cmd = [cmd_string,cmd_boot_list[i]]
					timeout_list = ['1','15']
					cmd_list.append(creat_autotest_cmd(input_cmd,timeout_list))
	elif clst in (range(3) + map(str,range(3))) and mult == 's':
		cmd_boot = cmd_boot_list[int(clst)]
		for clst_value in clst_value_list:
			for voltage_value in voltage_list:
				cmd_string = ['set',str(voltage_value),'0x'+str(clst_value)]
				cmd_string = ' '.join(cmd_string)
				input_cmd = [cmd_string,cmd_boot_list[i]]
				timeout_list = ['1','10']
				cmd_list.append(creat_autotest_cmd(input_cmd,timeout_list))
	else:
		cmd_boot = 'boot 3ff'
		for clst_value in clst_all_multi:
			for voltage_value in voltage_list:
				cmd_string = ['set',str(voltage_value),'0x'+str(clst_value)]
				cmd_string = ' '.join(cmd_string)
				input_cmd = [cmd_string,cmd_boot]
				timeout_list = ['1','18']
				cmd_list.append(creat_autotest_cmd(input_cmd,timeout_list))
	with open(cfg.autocmd_file_dir,'w') as cmd_obj:
		for cmd_str in cmd_list:
				cmd_obj.write(cmd_str + '\n')
	return cfg.autocmd_file_dir


if __name__ == '__main__':
	if 3 == len(sys.argv):
		create_cpu_vmin_cmd(sys.argv[1],sys.argv[2])
	elif 2 == len(sys.argv):
		create_cpu_vmin_cmd(sys.argv[1])
	else:
		create_cpu_vmin_cmd()
	if os.path.exists(cfg.autocmd_file_dir):
		with open(cfg.autocmd_file_dir) as cmd_obj:
			for cmd_str in cmd_obj:
				# print cmd_str.strip()
				pass
	else:
		print "Create no cmd"
		exit(0)

	# create_cci_test_cmd()

