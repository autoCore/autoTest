#!/usr/bin/python

import ConfigParser

class Handler(object):
	def callback(self, prefix, name, *args):
		method = getattr(self, prefix+name, None)
		if callable(method): return method(*args)
	def create_cmd_list(self, name,*args):
		self.callback('do_', name,*args)

class CreateCmd(Handler):
	def __init__(self):
		super(CreateCmd,self).__init__()
		self.module_name = ""
		self.cmd_dict = {}
		self.config_options = {}

	def get_config(self,cfgfile):
		conf = ConfigParser.ConfigParser()
		conf.read(cfgfile)
		for sec in conf.sections():
			self.config_options[sec] = {k:v for k,v in conf.items(sec)}

	def do_bhmkstab(self):
		CMD = 'benchmark'
		SubCMD = range(21)
		CoreID = [255]#[0,1,2,3,4,5,6,7,255]
		CPU_CLK = [624,832,1248,2100]
		DDR_CLK = [312,400,800,1200,1600,2667]
		CCI_CLK = [0] #[0,1,2,3] #?????
		DDR_LOOP = 1
		BENCH_LOOP = 1
		Parallel = 1
		cmd_list = []
		cmd_line = "%s %s %s %s %s %s %s %s %s"%(CMD,SubCMD[0],CoreID[0],CPU_CLK[0],DDR_CLK[0],CCI_CLK[0],DDR_LOOP,BENCH_LOOP,Parallel)
		# cmd_line = " ".join([CMD,SubCMD[0],CoreID[0],CPU_CLK[0],DDR_CLK[0],CCI_CLK[0],DDR_LOOP,BENCH_LOOP,Parallel])
		for subcmd in SubCMD:
			for core in CoreID:
				for cpu in CPU_CLK:
					for ddr in DDR_CLK:
						for cci in CCI_CLK:
							cmd_line = "%s %s %s %s %s %s %s %s %s"%(CMD,subcmd,core,cpu,ddr,cci,DDR_LOOP,BENCH_LOOP,Parallel)
							cmd_list.append(cmd_line)
		# self.cmd_dict["bhmkstab"] = cmd_list
		self.cmd_dict["bhmkstab"] = ["benchmark 14","benchmark 14 0", "benchmark 14 1", "benchmark 14 2", "benchmark 14 3", \
									"benchmark 14 4", "benchmark 14 5", "benchmark 14 6", "benchmark 14 7", "benchmark 25",\
									"benchmark 25 0", "benchmark 25 1", "benchmark 25 2", "benchmark 25 3", "benchmark 25 4", \
									"benchmark 25 5", "benchmark 25 6", "benchmark 25 7", "benchmark 30","benchmark 30 0", \
									"benchmark 30 1", "benchmark 30 2", "benchmark 30 3", "benchmark 30 4", "benchmark 30 5",\
									"benchmark 30 6", "benchmark 30 7", "benchmark 30 0 1248 2400 832 10 10", "benchmark 30 4 1248 2400 832 10 10", \
									"benchmark 30 0 1248 2400 832 1 1", "benchmark 30 4 1248 2400 832 1 1", "benchmark 30 0 1248 2400 832 1 1 1",\
									"benchmark 30 4 1248 2400 832 1 1 1", "benchmark 35","benchmark 35 0", "benchmark 35 1", "benchmark 35 2", \
									"benchmark 35 3", "benchmark 35 4", "benchmark 35 5", "benchmark 35 6", "benchmark 35 7", \
									"benchmark 35 0 1248 2400 832 1 1", "benchmark 35 4 1248 2400 832 1 1"]


	def do_memtester(self):
		CMD = "memtseter"
		SubCMD = range(22+1) + [255,"all"]
		CoreID = [0,1,2,3,4,5,6,7,255]
		CPU_CLK = [624,832,1248,2100]
		DDR_CLK = [312,400,800,1200,1600,2667]
		LOOP = 1 #default 1
		Parallel = 1 #default 1
		AddressTableIndex = [0,1,2]
		Size = range(0x200,0x100000*16+1) #Default is 512K, max is 16M
		SrcAddress = 0x100000000
		DesAddress = 0x400000000
		cmd_line = "%s %s %s %s %s %s %s %s %s"%(CMD,LOOP,CoreID[0],Parallel,AddressTableIndex[0],SrcAddress,DesAddress,Size[0],SubCMD[-1])
		cmd_list = [cmd_line]
		self.cmd_dict[CMD] = cmd_list

	def do_bhmkperf(self):
		CMD = "perf"
		SubCMD = range(1,20+1)
		DDR_CLK = range(7+1)#[312, 533, 666, 800, 889, 1333, 1600, 2667]
		DPQoS = 3
		WB = 0
		cmd_list = []
		for subcmd in SubCMD:
			for ddr in DDR_CLK:
				cmd_line = "%s %s %s %s %s"%(CMD,subcmd,ddr,DPQoS,WB)
				cmd_list.append(cmd_line)
		self.cmd_dict["bhmkperf"] = cmd_list
		self.cmd_dict["bhmkperf"] = ['perf 11 5 2','perf 11 7 2','perf 14 5 2','perf 14 5 167','perf 14 5 295','perf 14 5 1063',\
									'perf 14 7 2','perf 14 7 167','perf 14 7 295','perf 14 7 1063','perf 16 5 2','perf 16 5 167',\
									'perf 16 5 295','perf 16 5 1063','perf 16 7 2','perf 16 7 167','perf 16 7 295','perf 16 7 1063',\
									'perf 15 5 2','perf 15 5 167','perf 15 5 295','perf 15 5 1063','perf 15 7 2','perf 15 7 167',\
									'perf 15 7 295','perf 15 7 1063','perf 25 5 2','perf 25 5 295','perf 25 7 2','perf 25 7 295',\
									'perf 24 5 2','perf 24 5 295','perf 24 7 2','perf 24 7 295 ']

	def do_sceneisp(self):
		CMD = 'sceneisp'
		SubCMD = range(33+1) #0-33
		CPU_CLK = [624,832,1248,2100]
		DDR_CLK = range(7+1)#[312, 533, 666, 800, 889, 1333, 1600, 2667]
		DPQoS = 3
		WB = 0 #0-auto_wcp_drain_en_ch0 2:1-wb_drain_level_ch0 4:3-wb_drain_threshold_ch0
		cmd_line = "%s %s %s %s %s"%(CMD,SubCMD[0],DDR_CLK[0],DPQoS,WB)
		cmd_list = [cmd_line]
		self.cmd_dict[CMD] = cmd_list


	def do_lmbench(self):
		CMD = 'lmbench'
		SubCMD = ['bw_smprd', 'bw_smpwr', 'bw_smprdwr', 'bw_smpmcp', 'bw_smpfwr', 'bw_smpfrd', 'bw_smpfcp', 'bw_smpbzero',\
			 'bw_smpbcopy', 'bw_rd', 'bw_wr', 'bw_rdwr', 'bw_mcp', 'bw_fwr', 'bw_frd', 'bw_fcp', 'bw_bzero', 'bw_bcopy',]
		Size = range(0x200,0x100000*10+1) #larger 512,smaller than 10M
		Loop = 10 #default 10
		cmd_line = "%s %s %s %s"%(CMD,SubCMD[0],Size[0],Loop)
		cmd_list = [cmd_line]
		self.cmd_dict[CMD] = cmd_list

	def do_bhmkmntr(self):
		CMD = "bhmkmntr"
		SubCMD = ['DMA', 'CPU', 'ISP', 'DPU', 'DMA&CPU', 'DMA&DPU', 'DMA&CPU&DPU', 'DMA&CPU&ISP', 'DMA&CPU&ISP&DPU']
		cmd_line = "%s %s"%(CMD,SubCMD[0])
		cmd_list = [cmd_line]
		self.cmd_dict[CMD] = cmd_list

	def do_ddrtester(self):
		CMD = "ddrtester"
		SubCMD = range(9+1)
		SubCMD.append("all")
		cmd_line = "%s %s"%(CMD,SubCMD[0])
		cmd_list = [cmd_line]
		self.cmd_dict[CMD] = cmd_list

	def do_cachescan(self):
		CMD = 'cachescan'
		CoreID = [0,1,2,3,4,5,6,7,127,255]
		cmd_line = "%s %s"%(CMD,CoreID[0])
		cmd_list = [cmd_line]
		self.cmd_dict[CMD] = cmd_list

	def __do_handler(self,cmd,subcmd,coreId,loop):
		SubCMD = [0,1,2,3,'all']
		CoreID = [0,1,2,3,4,5,6,7,255]
		Loop = 1 #default 1
		cmd_line = "%s %s %s %s"%(cmd,SubCMD[0],CoreID[0],Loop)
		cmd_list = [cmd_line]
		self.cmd_dict[cmd] = cmd_list

	def do_bhmkpwr(self):
		CMD = "bhmkpwr"
		SubCMD = [0,1,2,3,'all']
		CoreID = [0,1,2,3,4,5,6,7,255]
		Loop = 1 #default 1
		cmd_line = "%s %s %s %s"%(CMD,SubCMD[0],CoreID[0],Loop)
		cmd_list = [cmd_line]
		self.cmd_dict[CMD] = cmd_list

	def do_coremark(self):
		CMD = "coremark"
		SubCMD = [0,1,2,3,'all']
		CoreID = [0,1,2,3,4,5,6,7,255]
		Loop = 1 #default 1
		cmd_line = "%s %s %s %s"%(CMD,SubCMD[0],CoreID[0],Loop)
		cmd_list = [cmd_line]
		self.cmd_dict[CMD] = cmd_list

	def do_dhrystone(self):
		CMD = "dhrystone"
		SubCMD = [0,1,2,3,'all']
		CoreID = [0,1,2,3,4,5,6,7,255]
		Loop = 1 #default 1
		cmd_line = "%s %s %s %s"%(CMD,SubCMD[0],CoreID[0],Loop)
		cmd_list = [cmd_line]
		self.cmd_dict[CMD] = cmd_list

	def do_mountain(self):
		CMD = "mountain"
		cmd_list = [CMD]
		self.cmd_dict[CMD] = cmd_list

	def do_superpi(self):
		CMD = "superpi"
		CoreID = [0,1,2,3,4,5,6,7]
		Loop = 1 #default 1
		cmd_line = "%s %s %s"%(CMD,Loop,CoreID[0])
		cmd_list = [cmd_line]
		self.cmd_dict[CMD] = cmd_list

	def do_whetstone(self):
		CMD = "whetstone"
		CoreID = [0,1,2,3,4,5,6,7]
		Loop = 1 #default 1
		cmd_line = "%s %s %s"%(CMD,Loop,CoreID[0])
		cmd_list = [cmd_line]
		self.cmd_dict[CMD] = cmd_list

	def do_linpack(self):
		CMD = "linpack"
		CoreID = [0,1,2,3,4,5,6,7]
		Loop = 1 #default 1
		cmd_line = "%s %s %s"%(CMD,Loop,CoreID[0])
		cmd_list = [cmd_line]
		self.cmd_dict[CMD] = cmd_list

	def do_llcbench(self):
		CMD = "llcbench"
		CoreID = [0,1,2,3,4,5,6,7]
		Loop = 1 #default 1
		cmd_line = "%s %s %s"%(CMD,Loop,CoreID[0])
		cmd_list = [cmd_line]
		self.cmd_dict[CMD] = cmd_list



