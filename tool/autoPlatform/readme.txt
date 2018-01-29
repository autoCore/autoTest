Notes:

share_ctest_root_dir: is your shared ctest director. example: \\10.1.51.34\share\work\baremetal-test\ctest
you must start the autoTest_main.py in this root director.

autotest_platform: is you want to use evb or fpga. example: aquilac_FPGA, aquila_evb
if you select FPGA ,you must make sure labPC04 FPGA ok and start trace32

T32_IP: is trace32's PC IP

if you want remote connect trace32, you must make sure trace32 is available.

linux trace32: add the following in config.t32 

RCL=NETASSIST
PACKLEN=1024
PORT=20002

