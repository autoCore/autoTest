#!/usr/bin/python
from pyExcelerator import *
from xlrd import *
from xlutils.copy import *
import datetime
import os

background_dict = {'black':0, 'white':1, 'red':2, 'green':3, 'blue':4, 'yellow':5, 'pink':6, 'wathet':7}

class excel_cell_config():
	def __init__(self, _sheet_obj, _row, _col, _text, bold = False, height = 200, width = 5000, background = 'white'):
		self.sheet_obj = _sheet_obj
		self.pos_row = _row
		self.pos_col = _col
		self.bold = bold
		self.height = height
		self.width = width
		self.background = background_dict[background]
		self.report_text = _text
	def get_style(self):
		fnt = Font()
		fnt.name = 'Arial'
		fnt.colour_index = 0
		fnt.bold = self.bold
		fnt.height = self.height

		borders = Borders()
		borders.left = 1
		borders.right = 1
		borders.top = 1
		borders.bottom = 1

		al = Alignment()
		al.horz = Alignment.HORZ_CENTER
		al.vert = Alignment.VERT_CENTER

		style = XFStyle()
		style.font = fnt
		style.borders = borders
		style.alignment = al

		style.pattern.pattern = 1
		style.pattern.pattern_fore_colour = self.background #1 white 2 red 3 green 4 blue 5 yellow 6 pink 7

		self.sheet_obj.col(self.pos_col).width = self.width
		return style

def report_excel(fname):
	if os.path.exists(fname):
		pass
	else:
		print '%s not exists'%fname
		return 0

	title_text = 'ASR Ctest benchmark report'
	excel_obj = Workbook()
	sheet_obj = excel_obj.add_sheet('test_report')

	log_list = []
	log_value_list = []
	try:
		with open(fname) as file_obj:
			for eachline in file_obj:
				flag = 0
				if "benchmark@" in eachline:
					_str = eachline.split('@')[1]
					_str = _str.replace('(','').replace(')','').strip()
					_list = _str.split('|')
					_list = [_str.strip() for _str in _list]
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
	excel_cell_obj = excel_cell_config(sheet_obj, 0, 0, title_text, bold = True, height = 300, background = 'green')
	sheet_obj.write_merge(0, 0, 0, len(titleBar) - 1,excel_cell_obj.report_text, excel_cell_obj.get_style())
	cell_list = []
	for col_num in range(len(titleBar)):
		excel_cell_obj = excel_cell_config(sheet_obj, 1, col_num, titleBar[col_num], bold = True, height = 200, background = 'wathet')
		cell_list.append(excel_cell_obj)

	for _list in log_list:
		try:
			log_dict = {_str.split(':')[0].strip():_str.split(':')[1].strip() for _str in _list if ':' in _str}
			log_value_list.append(log_dict)
		except:
			print _list,"Your log is irregular"
	for i,report_dict in enumerate(log_value_list,2):
		for col_num,title_str in enumerate(titleBar):
			excel_cell_obj = excel_cell_config(sheet_obj, i, col_num, report_dict.get(title_str, '--'), bold = False, height = 180, background = 'yellow')
			cell_list.append(excel_cell_obj)
	for cell in cell_list:
		sheet_obj.write(cell.pos_row, cell.pos_col, cell.report_text, cell.get_style())
	file_name = os.path.splitext(fname)[0] + '.xls'
	excel_obj.save(file_name)

if __name__ == '__main__':
	if 2 == len(sys.argv):
		fname = sys.argv[1]
	else:
		fname = ''
	report_excel(fname)

