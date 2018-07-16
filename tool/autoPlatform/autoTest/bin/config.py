# config info
import ConfigParser
import os,sys
import platform

class config:
	def __init__(self):
		self.t32_platform = ''
		self.share_ctest_root_dir = ''
		self.autoTest_template = ''
		self.cmm_file_dir = os.sep.join([os.curdir,"tool","tmp","cmm"])
		self.build_result_file = os.sep.join([os.curdir,"tool","tmp","~build.result"])
		self.autocmd_file_dir = os.sep.join([os.curdir,"tool","tmp","~autotest_cmd_list"])
		self.res_tmp_dir = os.sep.join([os.curdir,"tool","tmp","~res_tmp.log"])
		self.t32_log_file_dir = os.sep.join([os.curdir,"tool","tmp","log"])
		self.log_file_dir = os.sep.join([os.curdir,"tool","tmp","log"])
		self.autoTest_script = os.sep.join([os.curdir,"tool","autoPlatform","autoTest","script","aquilac"])

	def update(self,t32_platform,root_dir,template):
		self.t32_platform = t32_platform
		if self.t32_platform == "windows":
			self.share_ctest_root_dir = root_dir
		else:
			self.share_ctest_root_dir = os.getcwd()
		self.autoTest_script = os.path.join(self.share_ctest_root_dir,self.autoTest_script)
		self.t32_log_file_dir = os.path.join(self.share_ctest_root_dir,self.t32_log_file_dir)
		self.autoTest_template = template

cfg = config()

t32_platform_d = {
	"aquila_evb":'linux',\
	"aquilac_fpga":'windows',\
	"aquilac_evb":'linux',\
	"aquilac_z1":'windows',
}

autoTest_template_dt = {
	"aquila_evb":os.sep.join([os.curdir,"tool","autoPlatform","autoTest","libs","autoTest_evb_template.cmm"]),\
	"aquilac_fpga":os.sep.join([os.curdir,"tool","autoPlatform","autoTest","libs","autoTest_fpga_template.cmm"]),\
	"simulator":os.sep.join([os.curdir,"tool","autoPlatform","autoTest","libs","autoTest_t32_template.cmm"]),\
	"aquilac_evb":os.sep.join([os.curdir,"tool","autoPlatform","autoTest","libs","autoTest_aquilac_evb_template.cmm"]),\
	"aquilac_z1":os.sep.join([os.curdir,"tool","autoPlatform","autoTest","libs","autoTest_z1_template.cmm"])
}
def config_init():
	global cfg
	conf = ConfigParser.ConfigParser()
	cfgfile = os.sep.join([os.curdir,"tool","autoPlatform","autoPlatform.cfg"])
	if os.path.exists(cfgfile):
		conf.read(cfgfile)
	else:
		print "No autotest.cfg.Pls check!"
	try:
		share_ctest_root_dir = conf.get('basic_config','share_ctest_root_dir')
		project_name = conf.get('basic_config','project')
		autotest_platform = t32_platform_d[project_name.lower()]
		autoTest_template = autoTest_template_dt[project_name.lower()]
	except Exception,e:
		print e,"EEROR:Pls check autoPlatform.cfg."
		sys.exit(1)
	cfg.update(autotest_platform,share_ctest_root_dir,autoTest_template)

if __name__ == "__main__":
	config_init()
	print '\n'.join(['{}:{}'.format(item[0],item[1]) for item in cfg.__dict__.items()])

