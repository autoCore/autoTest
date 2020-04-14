import psutil
import os


def kill_winproc(*proc_name):
    for _proc in psutil.process_iter():
        # print "%r, %s"%(_proc.pid, _proc.name())
        try:
            if _proc.name() in proc_name:
                print "target: %r, %s"%(_proc.pid, _proc.name())
                if _proc.is_running():
                    _proc.terminate()
        except Exception,e:
            print e

# kill_winproc("Insight3.exe","chrome.exe")