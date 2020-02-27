#!/usr/bin/env python
import os
from  util import *
import shutil


class TestEndException(Exception):
    pass


def mkdir_if_no_exists(path):
    if not os.path.exists(path):
        os.mkdir(path)


def get_abs_dir():
    return os.path.dirname(os.path.abspath(__file__))


def timing(timeout):
    for i in range(int(timeout)):
        sys.stdout.write("timing: %ds\r" % i)
        sys.stdout.flush()
        time.sleep(1)

class releaseZip(object):
    def __init__(self,cfg):
        self.cfg = cfg
        self.download_tool = None

    def check_dsp_rf_rbd(self):
        release_bin_l = [self.cfg.dsp_release_bin,self.cfg.rf_release_bin,self.cfg.rbd_release_bin]
        local_bin_l = [self.cfg.dsp_bin,self.cfg.rf_bin,self.cfg.rbd_bin]
        for release_bin,local_bin in zip(release_bin_l,local_bin_l):
            if os.path.exists(release_bin):
                if os.path.exists(local_bin) and os.path.getmtime(release_bin) > os.path.getmtime(local_bin) or not os.path.exists(local_bin):
                    shutil.copyfile(release_bin,local_bin)

    def prepare_release(self):
        tools_list = [_file for _file in os.listdir(self.cfg.download_tool_release_dir) if self.cfg.win_type in _file]
        tools_list.sort(key=lambda fn:os.path.getmtime(self.cfg.download_tool_release_dir+'\\'+fn))
        # print(tools_list)
        file_name = tools_list[-1]
        zip_file = os.path.join(self.cfg.download_tool_dir,file_name)
        if not os.path.exists(zip_file):
            shutil.copy(os.path.join(self.cfg.download_tool_release_dir,file_name),self.cfg.download_tool_dir)
            os.chdir(self.cfg.download_tool_dir)
            unzip_cmd = "%s x %s -y"%(self.cfg.unzip_tool, zip_file)
            os.system(unzip_cmd)
        self.download_tool = zip_file.replace(".exe","")
        print self.download_tool
        self.check_dsp_rf_rbd()

        print "copy dsp.bin rf.bin rbd.bin..."
        shutil.copyfile(self.cfg.dsp_bin,os.path.join(self.download_tool,"images","dsp.bin"))
        shutil.copyfile(self.cfg.rf_bin,os.path.join(self.download_tool,"images","rf.bin"))
        shutil.copyfile(self.cfg.rbd_bin,os.path.join(self.download_tool,"images","ReliableData.bin"))

        print "copy config file to download_tool..."
        shutil.copyfile(self.cfg.partition_config,os.path.join(self.download_tool,"config","partition","CRANE_EVB_GENERIC_LAYOUT.json"))
        shutil.copyfile(self.cfg.template_config,os.path.join(self.download_tool,"config","template","CRANE_EVB.json"))

        print "copy log.bin updater.bin boot33.bin apn.bin cp.bin..."
        # shutil.copyfile(self.cfg.apn_bin,os.path.join(self.download_tool,"images","apn.bin"))
        # shutil.copyfile(self.cfg.boot33_bin,os.path.join(self.download_tool,"images","boot33.bin"))
        # shutil.copyfile(self.cfg.cp_bin,os.path.join(self.download_tool,"images","cp.bin"))
        # shutil.copyfile(self.cfg.logo_bin,os.path.join(self.download_tool,"images","logo.bin"))
        # shutil.copyfile(self.cfg.updater_bin,os.path.join(self.download_tool,"images","updater.bin"))


    def release_zip(self,file_name = None):
        os.chdir(self.download_tool)
        if file_name is None:
            file_name = "ASR_CRANE_EVB_A0_16MB.zip"
        cmd = "arelease -c .\ -g --erase-all -p ASR_CRANE_EVB -v A0_16MB %s"%file_name
        os.system(cmd)
        return file_name

if __name__ == "__main__":
    '''
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument('-f', '--log_file', default='test_log',
                            help='log path or log_file -- example: ./test_log')
    arg_parser.add_argument('-c', '--cmd_file', default='',
                            help='if need autocmd.cfg ,input -c ./tool/auto_uart/autocmd.cfg')
    argv = arg_parser.parse_args()
    '''
    global cfg
    cfg = config()
    cfg.update('config.ini')
    print(cfg)
    release_tool = releaseZip(cfg)
    release_tool.prepare_release()
    try:
        zip_file = "ASR_CRANE_EVB_A0_16MB.zip"
        release_tool.release_zip(zip_file)
    except TestEndException:
        pass
    except Exception, e:
        pass
    finally:
        pass



