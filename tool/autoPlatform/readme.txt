usage: python ./tool/autoPlatform/main.py {aquila_evb,aquila_fpga,aquilac_evb,aquilac_fpga} [-h] [-m MODULE_NAME] [-c COMMAND]
               
for example: python ./tool/autoPlatform/main.py aquilac_evb -c autotest
positional arguments:
  {aquila_evb,aquila_fpga,aquilac_evb,aquilac_fpga}
                        input project name

optional arguments:
  -h, --help            show this help message and exit
  -m MODULE_NAME, --module_name MODULE_NAME
                        if you test single module, input module name
  -c COMMAND, --command COMMAND
                        please input command, example,build, autotest,autotest_j,autotest_v,ddr_current,uart,benchmark

build: autobuild all the modules
autotest:autotest with uart to print log
autotest_j: autotest with jtag to print log
autotest_v: autotest core and ddr Vmin
ddr_current:autotest ddr current
benchmark: autotest benchmark
uart: connect board uart like minicom


Notes:

share_ctest_root_dir: is your shared ctest director. example: \\10.1.51.34\share\work\baremetal-test\ctest
you must start the autoTest_main.py in this root director.

autotest_platform: you want to use evb or fpga. example: aquilac_FPGA, aquila_evb
if you select FPGA ,you must make sure labPC04 FPGA ok and start trace32

T32_IP: is trace32's PC IP

if you want remote connect trace32, you must make sure trace32 is available.

linux trace32: add the following in config.t32 

RCL=NETASSIST
PACKLEN=1024
PORT=20002

