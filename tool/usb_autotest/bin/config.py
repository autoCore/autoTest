# config info
import ConfigParser
import os,sys
import platform

class config:
	def __init__(self):
		self.t32_platform = ''
		self.share_ctest_root_dir = ''
		self.autoTest_template = ''
		self.cmm_file_dir = "./tool/tmp/cmm/"
		self.t32_IP = ''
		self.t32_PORT = b"20002"
		self.t32_bin_dir = "~/t32/bin/pc_linux64/"
		self.t32_PACKLEN = b"1024"
		self.build_result_file = './tool/tmp/~build.result'
		self.autocmd_file_dir = './tool/tmp/~autotest_cmd_list'
		self.res_tmp_dir = './tool/tmp/~res_tmp.log'
		self.t32_log_file_dir = "./tool/tmp/log/"
		self.log_file_dir = "./tool/tmp/log/"
		self.autoTest_script = './tool/autoTest/script/aquilac'

	def update(self,t32_platform,t32_ip,root_dir,template):
		self.t32_platform = t32_platform
		self.t32_IP = t32_ip
		if self.t32_platform == "windows":
			self.share_ctest_root_dir = root_dir
		else:
			self.share_ctest_root_dir = os.getcwd()
		self.autoTest_script = os.path.join(self.share_ctest_root_dir,'tool/usb_autotest/script/aquilac')
		self.t32_log_file_dir = os.path.join(self.share_ctest_root_dir,"tool/tmp/log")
		if platform.system() == "windows":
			self.log_file_dir = ".\\tool\\tmp\\log"
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
	"aquila_evb":"./tool/usb_autotest/libs/autoTest_evb_template.cmm",\
	"aquilac_fpga":"./tool/usb_autotest/libs/autoTest_fpga_template.cmm",\
	"simulator":"./tool/usb_autotest/libs/autoTest_t32_template.cmm",\
	"aquilac_evb":"./tool/usb_autotest/libs/autoTest_aquilac_evb_template.cmm"
}
def config_init():
	global cfg
	conf = ConfigParser.ConfigParser()
	cfgfile = './tool/usb_autotest/autotest.cfg'
	if os.path.exists(cfgfile):
		conf.read(cfgfile)
	else:
		print "No autotest.cfg.Pls check!"
	try:
		share_ctest_root_dir = './'
		autotest_platform = conf.get('t32_config','project')
		t32_IP = conf.get('t32_config','t32_IP')
		if 'default' == t32_IP:
			t32_IP = '10.1.50.99'
		autoTest_template = autoTest_template_dt[autotest_platform.lower()]
	except:
		print "EEROR:Pls check autotest.cfg."
		sys.exit(1)
	cfg.update(t32_platform_d[autotest_platform],t32_IP,share_ctest_root_dir,autoTest_template)

if __name__ == "__main__":
	config_init()
	print '\n'.join(['{}:{}'.format(item[0],item[1]) for item in cfg.__dict__.items()])

