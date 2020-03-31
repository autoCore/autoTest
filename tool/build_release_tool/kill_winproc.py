import psutil
import os

def kill_winproc(*proc_name):
    for _proc in psutil.process_iter():
        try:
            pinfo = _proc.as_dict(attrs=['pid', 'name'])
        except psutil.NoSuchProcess:
            pass
        else:
            if  pinfo['name'] in proc_name:
                cmd = "taskkill /F /IM %s"%pinfo['name']
                print "target: ", pinfo
                os.system(cmd)
            print pinfo
