#! /usr/bin/env python
import sys,os
import argparse
from util import *
import random

class PerfCapInfo(CapInfo):
	"""docstring for PerfCapInfo"""
	def __init__(self):
		self.error_cnt = 0
		self.underrun_cnt = 0
		self.error_time = []
		self.underrun_time = []

	def capUsefulInfo(self,name,match):
		if match:
			self.assignAttr(name,match.group(2).strip())
		else:
			self.assignAttr(name,None)

	def cnt_error(self,match):
		self.error_time.extend(match)
		self.error_cnt = len(self.error_time)

	def cnt_underrun(self,match):
		self.underrun_time.extend(match)
		self.underrun_cnt = len(self.underrun_time)

	def do_total_time(self,block):
		block_bak = block[:]
		while block_bak:
			match = re.search(r'c0:([0-9]+) ms:',block_bak.pop())
			if match:
				if int(match.group(1)) < 1000:
					pass
				else:
					self.assignAttr('total_time', match.group(1)+'ms')
					break

	def clear(self):
		self.__init__()

class PerfCapInfoParse(Parse):
	def __init__(self, handler):
		super(PerfCapInfoParse, self).__init__(handler)

		self.addStatistic(r'c0:([0-9]+ ms):[#]+ddr-wr-error:[*]+','error')
		self.addStatistic(r'c0:([0-9]+ ms):Warning: DP650 underrun','underrun')

		self.addCapture(r'(echo) :(perf[ 0-9]+)','cmd_name')
		self.addCapture(r'(DDR port 0 read bytes)[ ]+is[ ]+([0-9]+)','DDR_port_0_read_bytes') # c0:124868 ms:DDR port 0 read bytes   is 2874432
		self.addCapture(r'(DDR port 0 write bytes)[ ]+is[ ]+([0-9]+)','DDR_port_0_write_bytes')
		self.addCapture(r'(DDR port 3 read bytes)[ ]+is[ ]+([0-9]+)','DDR_port_3_read_bytes')
		self.addCapture(r'(DDR port 3 write bytes)[ ]+is[ ]+([0-9]+)','DDR_port_3_write_bytes')
		self.addCapture(r'(DDR port bandwidth)[ ]+is[ ]+([\.0-9]+)[ ]+(MBps)','DDR_port_bandwidth')
		self.addCapture(r'(DDR port bandwidth ratio)[ ]+is[ ]+([\.0-9]+)','DDR_port_bandwidth_ratio')
		self.addCapture(r'(ts for delay)[ ]+is[ ]+([0-9]+)','ts_for_delay')
		self.addCapture(r'(axi port3 max read latency)[ ]+is[ ]+([0-9]+)','axi_port3_max_read_latency')
		self.addCapture(r'(axi port3 max write latency)[ ]+is[ ]+([0-9]+)','axi_port3_max_write_latency')

	def parse(self, file, separator):
		for log_block in separator.log_blocks(file):
			if self.captures: self.captures[0](log_block[0],self.handler)
			self.handler.do('total_time',log_block)
			for block in separator.data_blocks(log_block):
				for statistic in self.statistics:
					statistic(block,self.handler)
				for capture in self.captures[1:]:
					capture(block, self.handler)
				self.info_list.append(copy.deepcopy(self.handler))
				self.handler.clear()

if __name__ == '__main__':
	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('log_dir',help='log path or log_file -- example: ./log or ./perf.log')
	arg_parser.add_argument('-d','--output_dir',default = './tool/cap_log_info/',help='output file dir -- example: ./')
	argv = arg_parser.parse_args()

	if os.path.isfile(argv.log_dir):
		file_list = [argv.log_dir]
	elif  os.path.isdir(argv.log_dir):
		file_list = [os.path.join(argv.log_dir,s) for s in os.listdir(argv.log_dir) if os.path.isfile(os.path.join(argv.log_dir,s))]
	else:
		print '"%s" not exists! Pls check.'%argv.log_dir
		sys.exit(0)

	sp = Separator(log_sprtr = 'echo :perf',data_sprtr = 'axi and ddr monitor data start')
	handler = PerfCapInfo()
	perf_cap_info = PerfCapInfoParse(handler)

	for fname in file_list:
		handler.assignAttr('file_name',os.path.basename(fname))
		with open(fname) as file:
			perf_cap_info.parse(file,sp)
	# for data in perf_cap_info.info_list:
	# 	print '\n'.join(['{}:{}'.format(item[0],item[1]) for item in data.__dict__.items()])
	# 	raw_input()
	sbook = xlrd.open_workbook('./tool/cap_log_info/perfinfo_templet.xls', formatting_info=True)
	ssheet = sbook.sheet_by_index(0)
	append_data = excel_copy(sbook)
	worksheet = append_data.get_sheet(0)
	_list = ssheet.col_values(1)
	_list = [str(_str) for _str in _list]
	_list = [_str.lower().strip() for _str in _list]
	# print _list
	for i,cmd in enumerate(_list[3:]):
		data_list = [data for data in perf_cap_info.info_list if data.cmd_name == cmd]
		if data_list:
			error_list = [data for data in data_list if data.error_cnt]
			underrun_list = [data for data in data_list if data.underrun_cnt]
			last_info = []
			if error_list:
				index = perf_cap_info.info_list.index(error_list[0]) + 1
				if index < len(perf_cap_info.info_list):
					data = perf_cap_info.info_list[index]
				else:
					data = error_list[0]
				last_info.append(data.getAttr('file_name'))
				last_info.append(' '.join(['Error:1st',error_list[0].error_time[0], 'last',error_list[-1].error_time[-1]]))
			elif underrun_list:
				index = perf_cap_info.info_list.index(underrun_list[0]) + 1
				if index < len(perf_cap_info.info_list):
					data = perf_cap_info.info_list[index]
				else:
					data = underrun_list[0]
				last_info.append(data.getAttr('file_name'))
				last_info.append(' '.join(['Under_run:1st',underrun_list[0].underrun_time[0], 'last',underrun_list[-1].underrun_time[-1]]))
			else:
				while 1:
					data = random.choice(data_list)
					if all([data.getAttr('DDR_port_0_read_bytes'),data.getAttr('DDR_port_0_write_bytes'),data.getAttr('DDR_port_3_read_bytes'),
							data.getAttr('DDR_port_3_write_bytes'),data.getAttr('ts_for_delay'),data.getAttr('DDR_port_bandwidth_ratio'),
							data.getAttr('DDR_port_bandwidth'),data.getAttr('axi_port3_max_read_latency'),data.getAttr('axi_port3_max_write_latency')]):
						break
				last_info.append(data.getAttr('file_name'))
			last_info.append('total_time:' + data.getAttr('total_time'))
			target_info = [data.getAttr('DDR_port_0_read_bytes'),data.getAttr('DDR_port_0_write_bytes'),data.getAttr('DDR_port_3_read_bytes'),
						data.getAttr('DDR_port_3_write_bytes'),data.getAttr('ts_for_delay'),data.getAttr('DDR_port_bandwidth_ratio'),
						data.getAttr('DDR_port_bandwidth'),data.getAttr('axi_port3_max_read_latency'),data.getAttr('axi_port3_max_write_latency'),
						'| '.join(last_info)]
			# print '\n'.join(['{}:{}'.format(item[0],item[1]) for item in data.__dict__.items()]) 
			# print target_info
			# raw_input()
			for j, info in enumerate(target_info):
				worksheet.write(i+3,j+4,info,create_excel_style())
	if not os.path.exists(argv.output_dir):
		os.makedirs(argv.output_dir)
	output_file = os.path.join(argv.output_dir,'perfinfo.xls')
	append_data.save(output_file)
	print 'output file:',output_file
	print 'capture log done!'