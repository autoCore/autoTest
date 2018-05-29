#! /usr/bin/env python
import sys,os
import argparse
from util import *
import random

class perfAutoCapInfo(CapInfo):
	def __init__(self):
		self.cap_log_list = []
		self.auto_log = []
	def cnt_match(self,match):
		self.cap_log_list.extend(match)
	def cnt_auto_log(self,match):
		self.auto_log.extend(match)
	def do_log(self):
		for i in range(len(self.cap_log_list)):
			self.cap_log_list[i] = self.cap_log_list[i].replace('RX> ','').replace(r'\009 ','')
	def clear(self):
		self.__init__()

class perfAutoLogPrse(Parse):
	def __init__(self, handler):
		super(perfAutoLogPrse, self).__init__(handler)
		self.addStatistic(r'(echo :.*?)c[0-9]:','match')
		self.addStatistic(r'(perf@\(.*?\))','match')
		self.addStatistic(r'(benchmark@\(.*?\))','match')
		self.addStatistic(r'(c[0-9]:[0-9 ]+ ms:Log@.*?)c[0-9]:','auto_log')

def get_title_log(file_log):
	log_list = []
	log_value_list = []
	try:
		for eachline in file_log:
			flag = 0
			if 'echo :' in eachline:
				cmd = eachline.strip().split('echo :')[1]
			if "perf@" in eachline or "benchmark@" in eachline:
				log_type, _str = eachline.split('@')
				_str = _str.replace('(','').replace(')','').strip()
				_list = _str.split('|')
				_list = [_str.strip() for _str in _list if _str.strip()]
				# print _list
				for i,log in enumerate(log_list):
					if _list[0] in log[0]:
						log_list[i].extend(_list[1:])
						flag = 1
				if not flag:
					log_list.append(_list)
		titleBar = [_str.split(':')[0].strip() for _str in log_list[0]]
	except:
		print "Your log is irregular"
		return 0
	for _list in log_list:
		try:
			log_dict = {_str.split(':')[0].strip():_str.split(':')[1].strip() for _str in _list if ':' in _str}
			log_dict['case'] +='(%s)'%cmd
			log_value_list.append(log_dict)
		except:
			print _list,"Your log is irregular"
	return titleBar,log_value_list,log_type

def report_excel(file_log):
	title_text = 'ASR Ctest benchmark report'
	excel_obj = xlwt.Workbook()
	sheet_obj = excel_obj.add_sheet('test_report')
	log_value_list = []
	auto_log_list = []
	for data in file_log:
		data.do('log')
		log = get_title_log(data.cap_log_list)
		if log:
			titleBar,log_value,log_type = log
		else:
			continue
		log_value_list.extend(log_value)
		auto_log_list.extend(data.auto_log)
	print titleBar
	excel_cell_obj = excelCellConfig(sheet_obj, 0, 0, title_text)
	excel_cell_obj.create_style(bold = True, height = 300, background = 'green')
	sheet_obj.write_merge(0, 0, 0, len(titleBar) - 1,excel_cell_obj.report_text, excel_cell_obj.get_style())
	cell_list = []
	for col_num in range(len(titleBar)):
		excel_cell_obj = excelCellConfig(sheet_obj, 1, col_num, titleBar[col_num])
		excel_cell_obj.create_style(bold = True, height = 200, background = 'wathet')
		cell_list.append(excel_cell_obj)

	first = 1
	for i,report_dict in enumerate(log_value_list,2):
		for col_num,title_str in enumerate(titleBar):
			excel_cell_obj = excelCellConfig(sheet_obj, i, col_num, report_dict.get(title_str, '--'))
			if first:
				excel_cell_obj.create_style(bold = False, height = 180, background = 'yellow')
				style = excel_cell_obj.get_style()
				first = 0
			else:
				excel_cell_obj.style = style
			cell_list.append(excel_cell_obj)
	for cell in cell_list:
		sheet_obj.write(cell.pos_row, cell.pos_col, cell.report_text, cell.get_style())
	sheet_name = 'Log'
	for i,log in enumerate(auto_log_list):
		page = i/65535
		if 'Log%d'%page != sheet_name:
			sheet_name = 'Log%d'%page
			sheet_obj = excel_obj.add_sheet(sheet_name)
		sheet_obj.col(0).width = 30000
		style.alignment.horz = style.alignment.HORZ_LEFT
		sheet_obj.write(i -page*65535, 0, log, style)
	file_name = log_type + '_report.xls'
	output_file = os.path.join(argv.output_dir,file_name)
	excel_obj.save(output_file)
	print 'output: %s'%output_file

if __name__ == '__main__':
	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('log_dir',help='log path or log_file -- example: ./log or ./perf.log')
	arg_parser.add_argument('-d','--output_dir',default = './tool/cap_log_info',help='output file dir -- example: ./')
	argv = arg_parser.parse_args()

	if os.path.isfile(argv.log_dir):
		file_list = [argv.log_dir]
	elif  os.path.isdir(argv.log_dir):
		file_list = [os.path.join(argv.log_dir,s) for s in os.listdir(argv.log_dir) if os.path.isfile(os.path.join(argv.log_dir,s))]
	else:
		print '"%s" not exists! Pls check.'%argv.log_dir
		sys.exit(0)

	sp = Separator(log_sprtr = 'echo :')
	handler = perfAutoCapInfo()
	perf_cap_info = perfAutoLogPrse(handler)

	for fname in file_list:
		handler.assignAttr('file_name',os.path.basename(fname))
		with open(fname) as file:
			perf_cap_info.parse(file,sp)

	# for data in perf_cap_info.info_list:
	# 	data.do('log')
	# 	report_excel(data.perf_auto_log)
	report_excel(perf_cap_info.info_list)
		# print '\n'.join(['{}:{}'.format(item[0],item[1]) for item in data.__dict__.items()])
		# raw_input()
