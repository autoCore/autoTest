#!/usr/bin/env python

owner_list = {\
	"ddr_benchmark":"binwu@asrmicro.com",\
	"stress_temp":"binwu@asrmicro.com",\
	"clock":"yujunzhao@asrmicro.com,junlongdi@asrmicro.com",\
	"dma":"taojiang@asrmicro.com,yudeshi@asrmicro.com",\
	"usim":"yikeqi@asrmicro.com",\
	"emmc":"yudeshi@asrmicro.com",\
	"ddr":"miantianyu@asrmicro.com",\
	"slt":"yikeqi@asrmicro.com",\
	"hwspinlock":"zhenbozhan@asrmicro.com",\
	"ddr_monitor":"miantianyu@asrmicro.com,taojiang@asrmicro.com",\
	"dp650":"taojiang@asrmicro.com,zhenbozhan@asrmicro.com",\
	"armv8core":"zhenbozhan@asrmicro.com",\
	"uart":"yudeshi@asrmicro.com",\
	"dvc":"junlongdi@asrmicro.com",\
	"perf":"miantianyu@asrmicro.com,taojiang@asrmicro.com",\
	"rtc":"zhenbozhan@asrmicro.com",\
	"aximonitor":"yikeqi@asrmicro.com",\
	"pwm":"zhenbozhan@asrmicro.com",\
	"ipc":"yikeqi@asrmicro.com",\
	"cci":"zhenbozhan@asrmicro.com",\
	"jtagsw":"zhenbozhan@asrmicro.com",\
	"keypad":"guoqiqin@asrmicro.com",\
	"i2c":"guoqiqin@asrmicro.com",\
	"usb":"guoqiqin@asrmicro.com",\
	"watchdog":"guoqiqin@asrmicro.com",\
	"example":"zhenbozhan@asrmicro.com",\
	"ad":"jessicalu@asrmicro.com",\
	"archtimer":"zhenbozhan@asrmicro.com",\
	"benchmark":"jinyuanguo@asrmicro.com",\
	"cp":"yikeqi@asrmicro.com",\
	"gpio":"guoqiqin@asrmicro.com",\
	"iram":"miantianyu@asrmicro.com",\
	"mfpr":"guoqiqin@asrmicro.com",\
	"power":"junlongdi@asrmicro.com",\
	"ssp":"junlongdi@asrmicro.com",\
	"ripc":"yikeqi@asrmicro.com"\
}


def get_owner(module_name):
	if module_name in owner_list:
		return owner_list[module_name]
	else:
		return 0