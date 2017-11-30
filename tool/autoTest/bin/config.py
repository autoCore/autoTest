# config info
import ConfigParser
import os,sys
import platform

class config:
	def __init__(self):
		self.t32_platform = ''
		self.config_string1 = ''
		self.share_ctest_root_dir = ''
		self.autoTest_template = ''
		self.cmm_file_dir = "./tool/tmp/cmm/"
		self.config_string0 = b"NODE="
		self.config_string2 = b"PORT="
		self.config_string3 = b"20002"
		self.t32_bin_dir = "~/t32/bin/pc_linux64/"
		self.config_string4 = b"PACKLEN="
		self.config_string5 = b"1024"
		self.linux_32_so_fn = "./tool/autoTest/bin/t32api.so"
		self.linux_64_so_fn = "./tool/autoTest/bin/t32api64.so"
		self.build_result_file = './tool/tmp/~build.result'
		self.autocmd_file_dir = './tool/tmp/~autotest_cmd_list'
		self.res_tmp_dir = './tool/tmp/~res_tmp.log'
		self.t32_log_file_dir = "./tool/tmp/log/"
		self.log_file_dir = "./tool/tmp/log/"
		self.autoTest_script = './tool/autoTest/script/aquilac'
	def update(self,t32_platform,_test_platform,root_dir,template):
		self.t32_platform = t32_platform
		self.config_string1 = _test_platform
		if self.t32_platform == "windows":
			self.share_ctest_root_dir = root_dir
		else:
			self.share_ctest_root_dir = os.getcwd()
		self.autoTest_script = self.share_ctest_root_dir + '/tool/autoTest/script/aquilac'
		self.t32_log_file_dir = self.share_ctest_root_dir + "/tool/tmp/log"
		if platform.system() == "windows":
			self.log_file_dir = "\\tool\\tmp\\log"
		self.autoTest_template = template

cfg = config()
test_platform = {
	"aquila_evb":b"10.1.50.99",\
	"aquilac_fpga":b"10.1.50.76",\
	"aquilac_evb":b"10.1.50.99"
}

t32_platform_d = {
	"aquila_evb":'linux',\
	"aquilac_fpga":'windows',\
	"aquilac_evb":'linux'
}

autoTest_template_dt = {
	"aquila_evb":"./tool/autoTest/bin/autoTest_evb_template.cmm",\
	"aquilac_fpga":"./tool/autoTest/bin/autoTest_fpga_template.cmm",\
	"simulator":"./tool/autoTest/bin/autoTest_t32_template.cmm",\
	"aquilac_evb":"./tool/autoTest/bin/autoTest_aquilac_evb_template.cmm"
}
def config_init():
	global cfg
	conf = ConfigParser.ConfigParser()
	cfgfile = './tool/autoTest/autotest.cfg'
	if os.path.exists(cfgfile):
		conf.read(cfgfile)
	else:
		print "No autotest.cfg.Pls check!"
	try:
		share_ctest_root_dir = conf.get('config','share_ctest_root_dir')
		autotest_platform = conf.get('config','autotest_platform')
		t32_IP = conf.get('config','t32_IP')
		if 'default' == t32_IP:
			t32_IP = test_platform[autotest_platform.lower()]
		autoTest_template = autoTest_template_dt[autotest_platform.lower()]
	except:
		print "EEROR:Pls check autotest.cfg."
		sys.exit(1)
	cfg.update(t32_platform_d[autotest_platform],t32_IP,share_ctest_root_dir,autoTest_template)

if __name__ == "__main__":
	config_init()
	print  cfg.config_string1
	print  cfg.share_ctest_root_dir
	print  cfg.autoTest_template
	print  cfg.log_file_dir
	print  cfg.t32_log_file_dir
	print  cfg.cmm_file_dir
	print  cfg.config_string0
	print  cfg.config_string2
	print  cfg.config_string3
	print  cfg.t32_bin_dir
	print  cfg.config_string4
	print  cfg.config_string5
	print  cfg.linux_32_so_fn
	print  cfg.linux_64_so_fn
	print  cfg.build_result_file
	print  cfg.autocmd_file_dir
	print  cfg.res_tmp_dir
	print  cfg.autoTest_script

