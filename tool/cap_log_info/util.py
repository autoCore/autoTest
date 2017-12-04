#! /usr/bin/env python

import xlrd,xlwt
import re,copy
from xlutils.copy import copy as excel_copy

background_dict = {'black':0, 'white':1, 'red':2, 'green':3, 'blue':4, 'yellow':5, 'pink':6, 'wathet':7}
class excelCellConfig():
	def __init__(self, _sheet_obj, _row, _col, _text, width = 5000):
		self.sheet_obj = _sheet_obj
		self.pos_row = _row
		self.pos_col = _col
		self.report_text = _text
		self.width = width

		self.borders = xlwt.Borders()

		self.al = xlwt.Alignment()
		self.fnt = xlwt.Font()
		self.style = None

	def create_style(self, fnt_name = 'Arial', bold = False, height = 180, background = 'white'):
		self.style = xlwt.XFStyle()
		self.fnt.bold = bold
		self.fnt.height = height
		self.style.font = self.fnt
		self.style.borders = self.borders
		self.style.alignment = self.al
		self.style.pattern.pattern_fore_colour = background_dict[background]  #1 white 2 red 3 green 4 blue 5 yellow 6 pink 7
		self.fnt.name = fnt_name
		self.fnt.colour_index = 0

		self.borders.left = 1
		self.borders.right = 1
		self.borders.top = 1
		self.borders.bottom = 1

		self.al.horz = self.al.HORZ_CENTER
		self.al.vert = self.al.VERT_CENTER
		self.style.pattern.pattern = 1
		self.sheet_obj.col(self.pos_col).width = self.width

	def get_style(self):
		return self.style


def create_excel_style():
	borders = xlwt.Borders()
	borders.left = 1
	borders.right = 1
	borders.top = 1
	borders.bottom = 1
	style = xlwt.XFStyle()
	style.borders = borders
	return style


class Separator(object):
	def __init__(self,log_sprtr = 'SPECIAL_TEXT',data_sprtr = 'SPECIAL_TEXT'):
		self.log_sprtr = log_sprtr
		self.data_sprtr = data_sprtr

	def log_lines(self,file):
		yield self.log_sprtr
		for line in file:
			if line.strip(): yield line.strip()
		yield self.log_sprtr

	def log_blocks(self, file):
		def log_blocks(source):
			block = []
			for line in self.log_lines(source):
				block.append(line)
				if self.log_sprtr in line:
					if block[:-1]: yield block[:-1]
					block = block[-1:]
		blocks = log_blocks(file)
		return blocks

	def data_blocks(self, source):
		def data_blocks(log_block):
			block = []
			first = 1
			block.append(self.data_sprtr)
			for line in log_block:
				block.append(line)
				if self.data_sprtr in line:
					if block[:-1]: yield ''.join(block[:-1])
					block = block[-1:]
			if block: yield ''.join(block)
		data_blocks = data_blocks(source)
		return data_blocks


class CapInfo(object):
	def assignAttr(self, name, value):
		setattr(self,name,value)

	def callback(self, prefix, name, *args):
		method = getattr(self, prefix+name, None)
		if callable(method): return method(*args)

	def getAttr(self,name):
		return getattr(self, name, None)

	def do(self,name,*args):
		self.callback('do_',name,*args)

	def clear(self):
		pass


class Parse(object):
	def __init__(self, handler):
		self.handler = handler
		self.info_list = []
		self.captures = []
		self.statistics = []

	def addCapture(self, pattern, name):
		pattern = re.compile(pattern)
		def cap(block, handler):
			match =  pattern.search(block)
			handler.capUsefulInfo(name,match)
		self.captures.append(cap)

	def addStatistic(self, pattern, name):
		pattern = re.compile(pattern)
		def statistic(block, handler):
			handler.callback('cnt_',name,pattern.findall(block))
		self.statistics.append(statistic)
	def parse(self, file, separator):
		for log_block in separator.log_blocks(file):
			for block in separator.data_blocks(log_block):
				for statistic in self.statistics:
					statistic(block,self.handler)
				for capture in self.captures:
					capture(block, self.handler)
				self.info_list.append(copy.deepcopy(self.handler))
				self.handler.clear()
