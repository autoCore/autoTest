#! /usr/bin/env python
import sys,os
import argparse
from util import *
import random

class perfAutoCapInfo(CapInfo):
	def __init__(self):
		self.perf_auto_log = []
		self.perf_log_list = []

	def cnt_perf(self,match):
		self.perf_auto_log.extend(match)

	def do_log(self):
		for i in range(len(self.perf_auto_log)):
			self.perf_auto_log[i] = self.perf_auto_log[i].replace('RX> ','').replace(r'\009 ','')

class perfAutoLogPrse(Parse):
	"""docstring for ClassName"""
	def __init__(self, handler):
		super(perfAutoLogPrse, self).__init__(handler)
		self.addStatistic(r'(perf@\(.*?\))','perf')
		self.addStatistic(r'(benchmark@\(.*?\))','perf')

def report_excel(file_log):
	title_text = 'ASR Ctest benchmark report'
	excel_obj = xlwt.Workbook()
	sheet_obj = excel_obj.add_sheet('test_report')
	log_list = []
	log_value_list = []
	try:
		for eachline in file_log:
			flag = 0
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
		return 1
	# print titleBar
	excel_cell_obj = excelCellConfig(sheet_obj, 0, 0, title_text, bold = True, height = 300, background = 'green')
	sheet_obj.write_merge(0, 0, 0, len(titleBar) - 1,excel_cell_obj.report_text, excel_cell_obj.get_style())
	cell_list = []
	for col_num in range(len(titleBar)):
		excel_cell_obj = excelCellConfig(sheet_obj, 1, col_num, titleBar[col_num], bold = True, height = 200, background = 'wathet')
		cell_list.append(excel_cell_obj)

	for _list in log_list:
		try:
			log_dict = {_str.split(':')[0].strip():_str.split(':')[1].strip() for _str in _list if ':' in _str}
			log_value_list.append(log_dict)
		except:
			print _list,"Your log is irregular"
	for i,report_dict in enumerate(log_value_list,2):
		for col_num,title_str in enumerate(titleBar):
			excel_cell_obj = excelCellConfig(sheet_obj, i, col_num, report_dict.get(title_str, '--'), bold = False, height = 180, background = 'yellow')
			cell_list.append(excel_cell_obj)
	for cell in cell_list:
		sheet_obj.write(cell.pos_row, cell.pos_col, cell.report_text, cell.get_style())
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

	sp = Separator()
	handler = perfAutoCapInfo()
	perf_cap_info = perfAutoLogPrse(handler)

	for fname in file_list:
		handler.assignAttr('file_name',os.path.basename(fname))
		with open(fname) as file:
			perf_cap_info.parse(file,sp)

	for data in perf_cap_info.info_list:
		data.do('log')
		report_excel(data.perf_auto_log)
		# print '\n'.join(['{}:{}'.format(item[0],item[1]) for item in data.__dict__.items()])
		# raw_input()
