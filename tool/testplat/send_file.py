import rpyc
import sys
import socket
import os

newlist = []
availfiles = []
local_ip = ''
#method to read and store bytes of files from clients
def check_and_read(full_dir_file_name, _ip):
#	print("check_and_read", local_ip, _ip)
#	if ip != _ip:
#		return None
	for a in availfiles:
		if a == full_dir_file_name:
			koo = open(full_dir_file_name,"rb")
			with koo:
				bytes = koo.read()
				print ("check_and_read: read some thing\n\r")
				return bytes
			break
	return None

def cmd_transfer(addr, port, full_dir_file_name, cmd_name, timeout_s):
	print("connect server")
	while (1):
		try:
			f = rpyc.connect(addr, port)
			f.root.setCallback(check_and_read)

			bgsrv = rpyc.BgServingThread(f)

			availfiles.append(full_dir_file_name)
			f.root.newfiles_add(full_dir_file_name)

			f.root.save_file(addr,full_dir_file_name)
			f.root.pass_cmd(cmd_name, timeout_s)

			f.root.files_remove(full_dir_file_name)

			bgsrv.stop()
			f.close()
			break
		except Exception, e:
#			print e
			print "."
			import time
			time.sleep(1)



if __name__ == "__main__":
	timeout_s = '40s'
	'''python c.py full_dir_file_name cmd_name, timeout_s, [localhost]'''
	'''SINGLE_TEST:aquilac_fpga_mimir_adv9_MIMIR_test.axf:AUTOTEST@mimir_test:30:ready/ongoing/done:log_name'''
	length = len(sys.argv)

	if length < 4 or length > 5:
		print ("python c.py full_dir_file_name cmd_name, timeout_s, [localhost]")
		exit(-1)

	full_dir_file_name = sys.argv[1]

	if os.path.exists(full_dir_file_name) != True:
		print ("Err file name, please input full filename that contail dir\n\r")
		exit(-1)

	if os.path.isfile(full_dir_file_name) != True:
		print ("Err file name, please input full filename that contail dir\n\r")
		exit(-1)

	cmd_name = sys.argv[2]
	timeout_s = sys.argv[3]

	if length == 5:
		addr = sys.argv[4]
	else:
		addr = "localhost"
	print (addr, full_dir_file_name, cmd_name, timeout_s)
	cmd_transfer(addr, 18861, full_dir_file_name, cmd_name, timeout_s)
