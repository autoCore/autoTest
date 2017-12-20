#!/usr/bin/python
import sys,os
import commands
import xlrd,xlwt
import re
import argparse
sys.path.append("./tool/autoTest/bin")
from jtag_t32 import *
from config import *
from ddr_perf_report_excel import excel_cell_config


def BIT(M):
	M = int(M)
	return 1<<M

def MASK_(M,N):
	M = int(M)
	N = int(N)
	return ((1<<(N))-1)<<(M)

def GET_OFFSET(M,N):
	return M

def VALUE_(M,V):
	V = int(V)
	M = int(M)
	return (V)<<(M)

clk_trees_dict = {}
class clk_tree:
	def __init__(self,arg_d):
		self.src_reg = arg_d['src_reg']
		self.src_sel = arg_d['src_sel']
		self.src_mask = arg_d['src_mask']
		self.gate_reg = arg_d['gate_reg']
		self.gate_val = arg_d['gate_val']
		self.gate_mask = arg_d['gate_mask']
		self.fact_reg = arg_d['fact_reg']
		self.mult = arg_d['mult']
		self.fact_mult_mask = arg_d['fact_mult_mask']
		self.div = arg_d['div']
		self.fact_div_mask = arg_d['fact_div_mask']
		self.fc_req = arg_d['fc_req']
		self.fc_req_bit = arg_d['fc_req_bit']
		self.clk_name = arg_d['clk_name']
		self.div_offset = arg_d['div_offset']
		self.id = arg_d['id']
		self.freq_val = arg_d.get('freq_val',0)
		
		self.gate_reg_val = 0
		self.parents = {}
		self.fact_reg_val = 0
		self.src_reg_val = 0

	def update_parent(self,_src_sel,_parent):
		self.parents[_src_sel] = _parent
	def update_reg_val(self, _src_reg_val, _gate_reg_val, _fact_reg_val):
		self.src_reg_val = _src_reg_val
		self.gate_reg_val = _gate_reg_val
		self.fact_reg_val = _fact_reg_val
	def get_parent(self):
		sel_val = self.src_reg_val & self.src_mask
		return self.parents.get(sel_val,"NULL")
	def get_gate_enable(self):
		if self.gate_reg and self.gate_reg != '0':
			enable = self.gate_reg_val & self.gate_val
		else:
			if 'NULL' == self.get_parent():
				enable = 1
			else:
				enable = self.get_parent().get_gate_enable()
		return enable
	def get_clk_freq(self):
		if self.freq_val:
			return self.freq_val
		elif self.fact_reg:
			div_val = self.fact_reg_val & self.fact_div_mask
			div_val = div_val >> self.div_offset
			self.div = div_val
		if 'NULL' == self.get_parent():
			return 0
		freq_val = self.get_parent().freq_val[:-1]
		suffix = self.get_parent().freq_val[-1]
		freq_val = float(freq_val)/(self.div + 1)
		freq_val = str(freq_val) + suffix
		self.freq_val = freq_val
		return self.freq_val


def get_clk_trees(fname_excel):
	workbook = xlrd.open_workbook(fname_excel)
	work_sheet = workbook.sheet_by_name('AP_CLOCK')
	tilebar = work_sheet.row_values(2)
	parent_list = tilebar[:]
	for i, _str in enumerate(parent_list):
		match = re.match(r'([A-Z0-9MK_\.]+)',_str.strip().upper())
		if match: parent_list[i] = match.group(1)
		# print parent_list[i]
	nrows = work_sheet.nrows
	ncols = work_sheet.ncols - 2
	for i in range(nrows):
		if i < 3:
			continue
		if work_sheet.cell(i,0).value in ['audio_axi_clk','audio ssp_clk','audio_apb_clk']:
			continue

		if 'domain' in work_sheet.cell(i,0).value:
			continue

# [u'0', u'0', u'0', u'REG_MAIN_ACGR', u'BIT(4)', u'MASK_(4, 1)', u'0', u'0', u'0', u'0', u'0', u'0', u'0']
		row_values = work_sheet.row_values(i)
		clk_name = str(row_values[0].upper())
		_str = row_values[2]
		_list = _str.split('\n')
		_list = [_str.strip()[1:-1].replace(' ','') for _str in _list]
		_list = [_str.split('=') for _str in _list]
		_dict = {str(_v[0]):str(_v[1]) for _v in _list}
		src_sel = _dict['src_mask']
		if 'MASK_' in src_sel:
			src_sel = src_sel.replace('MASK_','VALUE_')
			src_sel = src_sel.split(',')[0] + ', %s)'
		else:
			src_sel = "VALUE_(0, %s)"
		# print src_sel
		div_offset = _dict['fact_div_mask']
		if 'MASK_' in div_offset:
			div_offset = div_offset.replace('MASK_','GET_OFFSET')
		else:
			div_offset = '0'
		div_offset = eval(div_offset)

		for key, value in _dict.items():
			try:
				_dict[key] = eval(value)
			except:
				_dict[key] = str(value)
		_dict['clk_name'] = clk_name
		_dict['id'] = int(row_values[1])
		_dict['div_offset'] = div_offset

		if clk_name in parent_list:
			i = parent_list.index(clk_name)
			if '(' in tilebar[i]:
				match = re.search(r'\(([0-9MK\.]+)\)',tilebar[i].strip().upper())
				if match: _dict['freq_val'] = match.group(1)
			else:
				match = re.search(r'([0-9MK\.]+)',tilebar[i].strip().upper())
				if match: _dict['freq_val'] = match.group(1)
		# print clk_name,_rate
		clk_obj = clk_tree(_dict)
		for i in range(ncols):
			if i < 3:
				continue
			if row_values[i] or row_values[i] == 0:
				# print eval(src_sel%row_values[i])
				clk_obj.update_parent(eval(src_sel%row_values[i]),parent_list[i])
		clk_trees_dict[str(clk_name)] = clk_obj

	for key,clk_obj in clk_trees_dict.items():
		for _sel,_parent in clk_obj.parents.items():
			clk_obj.update_parent(_sel,clk_trees_dict.get(_parent,'NULL'))

def find_reg_in_h(reg_name):
	dirr = './inc/project_chip_reg/aquila'
	base_h = dirr + '/__regs_base_addr.h'
	file_list = [os.path.join(dirr,s) for s in os.listdir(dirr) if os.path.isfile(os.path.join(dirr,s))]
	reg_name_list = []
	# print reg_name
	if isinstance(reg_name,int):
		return reg_name
	# if str(reg_name) == '0':
		# return "NULL"
	for fname in file_list:
		# print fname
		with open(fname) as file_obj:
			eacheline_list = [eachline for eachline in file_obj if (reg_name in eachline) and (("ASR_ADDR" in eachline) or ("BIT" in eachline))]
			if eacheline_list:
				reg_name_list += eacheline_list
	# print reg_name_list
	if reg_name_list:
		pass
	else:
		print 'find no %s'%reg_name
		return 'NULL'
	for reg_line in reg_name_list:
		# print reg_line
		if 'BIT' in reg_line:
			_a = reg_line.split('BIT(')[-1]
			_a = int(_a.split(')')[0])
			reg_name_addr = BIT(_a)
			# print hex(reg_name_addr)
			return reg_name_addr
		_str = reg_line.split('ASR_ADDR(')[1]
		_str = _str.split(')')[0]
		addr_base,offset = _str.split(',')
		with open(base_h) as file_obj:
			base_list = [eachline for eachline in file_obj if addr_base in eachline]
			for base_line in base_list:
				_base = base_line.split()[-1]
				addr_base = hex(int(_base,16))
		reg_name_addr = int(_base,16)+int(offset.strip(),16)
		# print reg_name_addr
	return reg_name_addr


def fill_all_reg_val():
	jtat_connect_cnt = 0
	while 1:
		t32api = jtat_connect()
		jtat_connect_cnt += 1
		if t32api:
			break
		if jtat_connect_cnt == 10:
			print "Pls check your jtag t32\n\r"
			sys.exit(1)
	# print "jtat connect done\n"

	for key, clk_obj in clk_trees_dict.items():
		reg_name_list = [clk_obj.src_reg, clk_obj.gate_reg, clk_obj.fact_reg]
		reg_addr_list = [find_reg_in_h(reg_name) for reg_name in reg_name_list]
		reg_val_list = []
		for reg_name,reg_addr in zip(reg_name_list,reg_addr_list):
			if 'NULL' == reg_addr:
				reg_val_list.append(0)
				continue
			retval = t32api.T32_ReadMemory(reg_addr, 0x0, rdbuffer, 4)
			if retval:
				reg_val_list.append(0)
				print "Error:",
				print "clk_name:%s, reg_name: %s address:%s"%(clk_name,reg_name, str(hex(reg_addr)))
			else:
				reg_val_list.append(rdbuffer[0])
		clk_trees_dict[key].update_reg_val(*reg_val_list)
		for i in range(3):
			try:
				reg_addr_list[i] = str(hex(reg_addr_list[i]))
			except:
				reg_addr_list[i] = str(reg_addr_list[i])
			# print "clk_name:%s, reg_name: %s address:%s = %s"%(key,reg_name_list[i], str(reg_addr_list[i]),str(hex(reg_val_list[i])))
	jtat_disconnect(t32api)


if __name__ == "__main__":
	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('file_name',help = 'input file name')
	argv = arg_parser.parse_args()

	if os.path.exists(argv.file_name):
		pass
	else:
		print '%s not exists'%argv.file_name
		sys.exit(1)
	print 'Pls first read readme. Make sure your t32 is permitted to remote connect and t32_ip is valid.'
	get_char = raw_input("If you continue,input y else n:")
	if get_char.upper() == 'Y':
		pass
	else:
		sys.exit(0)

	config_init()
	get_clk_trees(argv.file_name)
	fill_all_reg_val()

	excel_obj = xlwt.Workbook()
	sheet_obj = excel_obj.add_sheet('clock')
	tilebar = ['clock name','parent 1','parent 2','parent 3','parent 4','clock rate']
	current_row = 0
	cell_list = []
	for i, text in enumerate(tilebar):
		# sheet_obj.write(current_row, i, text)
		cell_list.append(excel_cell_config(sheet_obj, current_row, i, text, bold = True, height = 200, width = 6000, background = 'wathet'))
	for key, clk_obj in sorted(clk_trees_dict.items(),key=lambda item:item[1].id):
		# print clk_obj.id
		text_list = []
		current_row += 1
		clk_freq = str(clk_obj.get_clk_freq())
		if clk_obj.get_gate_enable():
			text_list.append(clk_obj.clk_name + '(enable)')
		else:
			text_list.append(clk_obj.clk_name + '(disable)')
		while 1:
			clk_obj = clk_obj.get_parent()
			if "NULL" == clk_obj:
				break
			if clk_obj.get_gate_enable():
				text_list.append(clk_obj.clk_name + '(enable)')
			else:
				text_list.append(clk_obj.clk_name + '(disable)')
		for i in range(5-len(text_list)):
			text_list.append("NULL")
		text_list.append(clk_freq)
		# print text_list
		for j, text in enumerate(text_list):
			if 'disable' in text:
				cell_list.append(excel_cell_config(sheet_obj, current_row, j, text, width = 6000, background = 'red'))
			else:
				cell_list.append(excel_cell_config(sheet_obj, current_row, j, text, width = 6000, background = 'green'))
			# sheet_obj.write(current_row, j, text) 
	for cell in cell_list:
		sheet_obj.write(cell.pos_row, cell.pos_col, cell.report_text, cell.get_style())
	output_file = './tool/clock_tree/clock_info.xls'
	print 'output file:',output_file
	excel_obj.save(output_file)

