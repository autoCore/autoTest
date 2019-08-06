#!/usr/bin/env python
import platform
import argparse
import signal
import random
import re
import traceback
import time
import os
import sys
import pexpect
import threading
import serial
import ConfigParser
import multiprocessing as mp
from serial import Serial
from serial.tools.list_ports import comports
# from  util import myLogger, ProcBase, ThreadBase, make_log_file, get_sudo_password, timing, config
from  util import *
# import pysnooper

def signal_handler(signum, frame):
    raise TestEndException


class TestEndException(Exception):
    pass

class Uart(object):
    def __init__(self, logger = None, is_print = True):
        super(Uart, self).__init__()
        self.logger = logger
        self.comport = None
        self.is_print = mp.Event()

        self.expect_match = mp.Event()
        self.busy_flag = mp.Event()
        self.pattern_fifo = mp.Queue(1)

        self.open_flag = False
        self.open_wachdog_flag = False
        self.sodo_password = get_sudo_password()
        self.is_print.set()

    def isOpen(self):
        return self.comport.isOpen()

    def input(self, msg, pattern_str='', timeout = 1):
        self.comport.write(msg)
        if pattern_str:
            return self.expect(pattern_str, timeout)
        return True

    def clear_input_fifo(self):
        # while not self.input_fifo.empty():
        #     self.input_fifo.get()
        self.comport.flushOutput()

    def expect(self, pattern_str, timeout):
        # wait uart input cmd and begin to search the pattern
        self.pattern_fifo.put(pattern_str)
        self.busy_flag.wait(timeout)
        time_ = time.time()
        # wait uart match the pattern until timeout
        self.expect_match.wait(timeout)
        self.busy_flag.clear()
        res = self.expect_match.is_set()  # if match the pattern res is True else False
        self.expect_match.clear()
        self.logger.debug('expect %s < %.3fs >'%(pattern_str,(time.time()-time_)))
        return res

    def reset_system(self, timeout=3):
        self.open_flag = False
        self.open_wachdog_flag = False
        return self.input("CMD+RST\n")

    def back_destop(self):
        self.simulate_key_input('0')
        self.simulate_key_input('P')

    def check_status(self, timeout=5):
        return self.input("CMD+STATUS\n", 'STATUS', timeout)

    def open_wachdog(self, timeout=3):
        for __ in range(3):
            self.open_wachdog_flag = self.input(
                "CMD+WDGE\n", 'WDGE', timeout)
            if self.open_wachdog_flag:
                break
        return self.open_wachdog_flag

    def close_wachdog(self, timeout=3):
        for __ in range(3):
            if self.open_wachdog_flag:
                self.open_wachdog_flag = not self.input(
                    "CMD+WDGD\n", 'WDGD', timeout)
            else:
                break
        return self.open_wachdog_flag

    def unlock(self):
        self.simulate_key_input('[')

    def open_key_test(self,timeout=3):
        self.open_flag = True
        self.input("KEY#**\n")
        time.sleep(1)

    def close_key_test(self,timeout=3):
        self.open_flag = False
        self.input("KEY###\n")
        time.sleep(1)

    def simulate_key_input(self, key_value, LongPress = 0):
        if not self.open_flag:
            self.open_key_test()
        self.comport.write('KEY#'+key_value.upper()+'0\n')  # key down
        if LongPress:
            time.sleep(cfg.KEY_DOWN_UP_LONG_INTERVAL)
        else:
            time.sleep(cfg.KEY_DOWN_UP_INTERVAL)
        self.comport.write('KEY#'+key_value.upper()+'1\n')  # key up
        self.logger.debug('*** input: %s ***'%key_value.upper())

    def open_usk(self,timeout = 3):
        usk_flag = False
        for __ in range(3):
            usk_flag = self.input("usk enable\n","usk enable OK",timeout)
            if usk_flag:
                break
        return usk_flag

    def reset_log_file(self, file_name):
        self.logger.resetLogFile(file_name)


    def createPort(self, port=None, baud=115200, time_out=0.1):
        if not port:
            platform_type = platform.platform()
            port_list = comports()
            if "Linux" in platform_type:
                port_list = [port[0] for port in port_list]
                port_list = [
                    port for port in port_list if "ttyUSB" in port or "ttyACM" in port]
            elif "Windows" in platform_type:
                port_list = [list(port) for port in port_list]
                port_list = [
                    port for port in port_list if "USB to UART Bridge" in port[1]]
            logger.debug('port: %r'%port_list)
            for p in port_list:
                proc = pexpect.spawn('sudo chmod 777 %s' % p)
                index = proc.expect(
                    [r'\[sudo\] password for', pexpect.EOF, pexpect.TIMEOUT], timeout=1)
                if index == 0:
                    proc.sendline(self.sodo_password)
            if port_list:
                if len(port_list) == 1:
                    port = port_list[0]
                else:
                    while 1:
                        port = raw_input('Pls input port:')
                        if port in port_list:
                            break
                        else:
                            logger.error('*** No device ***')
            else:
                logger.error("****No port****")
                sys.exit(0)
        logger.debug('current port name:'+port)
        self.comport = Serial(port, baud, timeout=time_out)
        self.timeout = time_out
        if self.comport.isOpen():
            self.comport.flushInput()
            self.comport.flushOutput()
            return 0
        else:
            logger.error("*** create port fail ***")
            return 1
            # sys.exit(1)

    def close(self):
        self.log.flush()
        self.log.close()
        self.comport.close()


class UartPrint(ProcBase):
    def __init__(self):
        super(UartPrint, self).__init__()
        self._pattern = None

    def run(self, uart, stop_flag, system_reset_flag):
        try:
            while self._running.is_set():
                time_ = time.time()
                if not uart.pattern_fifo.empty() and not uart.busy_flag.is_set():
                    pattern_str = uart.pattern_fifo.get()
                    if pattern_str:
                        self._pattern = re.compile(pattern_str)
                        uart.busy_flag.set()
                    else:
                        self._pattern = None
                line = uart.comport.readline().strip()
                if not line:
                    continue
                if uart.busy_flag.is_set() and self._pattern:
                    if self._pattern.search(line):
                        uart.busy_flag.clear()
                        uart.expect_match.set()
                        self._pattern = None
                if "CHIP_ID: 0x6731, REV_ID: 0xA0" in line:
                    uart.logger.debug("*** MONKEY TEST CHIP RESET ***")
                    stop_flag.set()
                    system_reset_flag.set()
                uart.logger.info(line)
                # if debug.is_set(): uart.logger.debug('[ %.6fs ]'%(time.time()-time_))
        except (KeyboardInterrupt, TestEndException):
            pass
        except Exception, e:
            uart.logger.error('*** UartPrint Error! ***')
            uart.logger.error(e)
        finally:
            uart.expect_match.set()
            stop_flag.set()
            uart.logger.debug('UartPrint done')

class UartInput(ThreadBase):
    def __init__(self):
        super(UartInput, self).__init__()

    def run(self, uart, stop_flag):
        try:
            while self._running:
                msg = raw_input('')
                if 'exit' in msg:
                    break
                elif 'print' in msg:
                    value_l = msg.split('=')
                    if len(value_l) == 2:
                        value = value_l[1]
                    else:
                        uart.logger.debug('*** Pls check your input ***')
                        continue
                    uart.is_print.set() if eval(value) else uart.is_print.clear()
                elif 'debug' in msg:
                    value_l = msg.split('=')
                    if len(value_l) == 2:
                        value = value_l[1]
                    else:
                        uart.logger.debug('*** Pls checkl your input ***')
                        continue
                    debug.set() if eval(value) else debug.clear()
                else:
                    uart.input(msg+'\n')
        except Exception:
            traceback.print_exc()
            uart.logger.error('*** Error:[UartInput],Pls check serial port ***')
        finally:
            self._running = False
            uart.logger.debug('UartInput done')
            stop_flag.set()


class MyTimer(ThreadBase):
    """docstring for MyTimer"""

    def __init__(self, delay_time):
        super(MyTimer, self).__init__()
        self.__delay_time = delay_time
        self.block = threading.Event()

    def run(self, uart, stop_flag):
        try:
            while self._running:
                self.block.wait(self.__delay_time)
                if not self._running:
                    break
                if stop_flag.is_set():
                    break
                uart.logger.debug('*** check status ***')
                if uart.check_status(self.__delay_time):
                    uart.logger.debug('*** check status pass ***')
                else:
                    uart.logger.debug('*** check status fail ***')
                    stop_flag.set()
                    break
        except Exception:
            traceback.print_exc()
            uart.logger.error('*** Error:[UartController],Pls check serial port ***')
        finally:
            self._running = False

    def terminate(self):
        if not self._proc:
            return
        self._running = False
        self._proc = None
        uart.logger.debug('MyTimer done')


class monkeyTestTask(ThreadBase):
    """docstring for ClassName"""

    def __init__(self, monkey_logger, cfg_file=None):
        super(monkeyTestTask, self).__init__()
        self.monkey_log_fname = None
        self.monkey_logger = monkey_logger
        self.cfg_file = cfg_file
        self.count = 1
        self.cmd_set = None

    def reset_log_file(self, file_name, fmt = ''):
        if not fmt:
            fmt = '%(message)s'
        self.monkey_logger.resetLogFile(file_name,fmt)
        self.monkey_log_fname = file_name

    def cfg_test(self, uart, stop_flag):
        with open(self.cfg_file) as file_obj:
            file_text_l = [
                line_ for line_ in file_obj if line_.strip() and not line_.strip().startswith('#')]
            file_text = '|'.join(file_text_l)
            file_text = '|' + re.sub('\n', '', file_text)
            cnt = re.findall('\|CNT@\((.*?)\)', file_text)
            cnt = int(cnt[0]) if cnt else 1
        for i in xrange(cnt):
            uart.logger.debug('*' * 20 + " running cnt: %s " % i + '*' * 20)
            for line in file_text_l:
                if not self._running:
                    return
                if stop_flag.is_set():
                    raise TestEndException
                if 'AUTOTEST_KEY' in line.lstrip():
                    cmd_set = re.findall('AUTOTEST_KEY@\((.*?),(.*?)\)', line.lstrip())
                    for cmd, timeout in cmd_set:
                        if 'CMD-' in cmd:
                            uart.input(cmd.replace('CMD-', '')+'\n')
                            uart.logger.debug('*** intput: %s ***' %
                                      cmd.replace('CMD-', ''))
                            time.sleep(float(timeout))
                            continue
                        for send_c in cmd.replace(' ', ''):
                            if not self._running:
                                return
                            if send_c is not '-':
                                uart.simulate_key_input(send_c)
                                self.monkey_logger.write(send_c)
                            time.sleep(float(timeout))
                if 'AUTOTEST_LONGKEY' in line.lstrip():
                    cmd_set = re.findall('AUTOTEST_LONGKEY@\((.*?),(.*?)\)', line.lstrip())
                    for cmd, timeout in cmd_set:
                        if 'CMD-' in cmd:
                            uart.input(cmd.replace('CMD-', '')+'\n')
                            uart.logger.debug('*** intput: %s ***' %
                                      cmd.replace('CMD-', ''))
                            time.sleep(float(timeout))
                            continue
                        for send_c in cmd.replace(' ', ''):
                            if not self._running:
                                return
                            # uart.logger.debug('*** intput: %s ***'%cfg.key_value_d.get(send_c,''))
                            if send_c is not '-':
                                uart.simulate_key_input(send_c,1)
                                self.monkey_logger.write(send_c)
                            time.sleep(float(timeout))

        '''
        with open(self.cfg_file) as file_obj:
            file_text = [
                line_ for line_ in file_obj if not line_.strip().startswith('#')]
            file_text = '|'.join(file_text)
            file_text = '|' + re.sub('\n', '', file_text)
        cmd_set = re.findall('\|AUTOTEST_KEY@\((.*?),(.*?)\)', file_text)
        cnt = re.findall('\|CNT@\((.*?)\)', file_text)
        cnt = int(cnt[0]) if cnt else 1
        for i in xrange(cnt):
            uart.logger.debug('*' * 20 + " running cnt: %s " % i + '*' * 20)
            for cmd, timeout in cmd_set:
                if not self._running:
                    return
                if stop_flag.is_set():
                    raise TestEndException
                if 'CMD-' in cmd:
                    uart.input(cmd.replace('CMD-', '')+'\n')
                    uart.logger.debug('*** intput: %s ***' %
                              cmd.replace('CMD-', ''))
                    time.sleep(float(timeout))
                    continue
                for send_c in cmd.replace(' ', ''):
                    if not self._running:
                        return
                    # uart.logger.debug('*** intput: %s ***'%cfg.key_value_d.get(send_c,''))
                    if send_c is not '-':
                        uart.simulate_key_input(send_c)
                        self.monkey_logger.write(send_c)
                    time.sleep(float(timeout))
            else:
                time.sleep(1)
                # uart.back_destop()
        else:
            # uart.close_wachdog()
            uart.close_key_test()
        '''
    # @pysnooper.snoop('./debug.log')
    def monkey_test(self, uart, stop_flag):
        key_value_item = cfg.key_value_map
        i = 0
        while self._running:
            send_c, send_c_name = random.choice(key_value_item)
            if send_c.isdigit():
                i += 1
                if i < 10:
                    continue
                else:
                    i = 0
            if stop_flag.is_set():
                return
            timeout = cfg.SIMULATE_KEY_INPUT_INTERVAL
            # uart.logger.debug('*** intput: %s ***' % send_c_name)
            uart.simulate_key_input(send_c)
            self.monkey_logger.write(send_c)
            time.sleep(float(timeout))

    def run(self, uart, stop_flag):
        try:
            if not uart.open_usk():
                uart.logger.error('not open usk')
                assert('not open usk')
            # uart.open_wachdog()
            uart.open_key_test()
            # uart.unlock()  # ui unlock
            if self.cfg_file:
                self.cfg_test(uart, stop_flag)
            else:
                self.monkey_test(uart, stop_flag)
                # self.contact_test(uart)
        except TestEndException, e:
            uart.logger.debug(repr(e))
            sys.exit(0)
        except Exception, e:
            uart.logger.error(repr(e))
            stop_flag.set()

        finally:
            # uart.close_wachdog()
            uart.logger.debug('*** deal with monkey key log file ***')
            self.report(self.monkey_log_fname)

    def terminate(self):
        if not self._proc:
            return
        self._running = False
        self._proc = None
        uart.logger.debug('monkeyTestTask done')

    def report(self, file_name):
        if file_name:
            file_name = os.path.join('log',file_name)
        else:
            uart.logger.debug('%s no exits'%file_name)
            return
        if not os.path.exists(file_name):
            uart.logger.debug('%s no exits'%file_name)
            return
        with open('./autocmd.cfg', 'a') as cfg_file,open(file_name) as monkey_log:
            monkey_text = monkey_log.read()
            monkey_text = monkey_text.replace('\n','')
            cfg_log = '# AUTOTEST_KEY@(%s,%s)' % (
                monkey_text, cfg.SIMULATE_KEY_INPUT_INTERVAL)
            cfg_file.write(cfg_log+'\n')

    def alarm_test(self, uart, stop_flag):
        for key_ in ['M', 'V', 'V', 'M', 'M']:
            uart.simulate_key_input(key_)
        key_value_item = cfg.alarm_key_value_map
        cnt = 0
        while self._running:
            send_c, send_c_name = random.choice(key_value_item)
            if send_c_name is 'F_RIGHT':
                cnt += 1
                if cnt < 100:
                    continue
                else:
                    cnt = 0
            if stop_flag.is_set():
                return
            timeout = cfg.SIMULATE_KEY_INPUT_INTERVAL
            # uart.logger.debug('*** intput: %s ***' % send_c_name)
            uart.simulate_key_input(send_c)
            self.monkey_logger.write(send_c)
            time.sleep(float(timeout))

    # @pysnooper.snoop('./debug1.log')
    def contact_test(self, uart, stop_flag):
        uart.simulate_key_input('V')
        key_value_item = cfg.contact_key_value_map
        i = 0
        while self._running:
            send_c, send_c_name = random.choice(key_value_item)
            if send_c.isdigit():
                i += 1
                if i < 10:
                    continue
                else:
                    i = 0
            if stop_flag.is_set():
                return
            timeout = cfg.SIMULATE_KEY_INPUT_INTERVAL
            # uart.logger.debug('*** intput: %s ***' % send_c_name)
            uart.simulate_key_input(send_c)
            self.monkey_logger.write(send_c)
            time.sleep(float(timeout))

def mkdir_if_no_exists(path):
    if not os.path.exists(path):
        os.mkdir(path)


def get_abs_dir():
    return os.path.dirname(os.path.abspath(__file__))


def make_log_file(file_name):
    abs_dir = get_abs_dir()
    log_dir = os.path.join(abs_dir, 'log')
    mkdir_if_no_exists(log_dir)

    date = time.strftime("%d_%h_%H-%M-%S")
    return os.path.join(log_dir, '%s_%s.txt' % (file_name, date))

def timing(timeout):
    for i in range(int(timeout)):
        sys.stdout.write("timing: %ds\r" % i)
        sys.stdout.flush()
        time.sleep(1)


debug = mp.Event()
debug.set()


if __name__ == "__main__":
    signal.signal(signal.SIGINT, signal_handler)
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument('-f', '--log_file', default='test_log',
                            help='log path or log_file -- example: ./test_log')
    arg_parser.add_argument('-c', '--cmd_file', default='',
                            help='if need autocmd.cfg ,input -c ./tool/auto_uart/autocmd.cfg')
    argv = arg_parser.parse_args()

    global cfg
    cfg = config()
    cfg.update('crane_cfg.conf')
    mkdir_if_no_exists("log")
    uart = None
    uart_input = None
    test_task = None
    timer = None
    uart_print = None
    stop_flag = mp.Event()
    system_reset_flag = mp.Event()
    logger = myLogger("monkey_test")
    logger.enablePrint()
    try:
        logger.resetLogFile(make_log_file(argv.log_file))
        uart = Uart(logger)
        uart.createPort()
        uart_input = UartInput()
        logger.debug(cfg)
        uart_input.start(uart, stop_flag)
        uart_print = UartPrint()
        uart_print.start(uart, stop_flag, system_reset_flag)
        monkey_logger = myLogger("monkey_log")
        test_task = monkeyTestTask(monkey_logger, argv.cmd_file)
        test_task.reset_log_file(make_log_file(
            argv.log_file+'_monkey_key'))
        timer = MyTimer(cfg.CHECK_INTERVAL)
        uart.logger.debug('*** monkey test start ***')
        test_task.start(uart, stop_flag)
        # timer.start(uart, stop_flag)
        while 1:
            stop_flag.wait()
            test_task.terminate()
            raise TestEndException
            timer.terminate()
            while test_task.isOpen() or timer.isOpen():
                uart.logger.debug('*** wait for task terminate ***')
            stop_flag = mp.Event()
            uart.logger.debug('*** monkey test terminate ***')
            uart.logger.debug('========================================')
            if not system_reset_flag.is_set():
                uart.reset_system()  # reset system
            system_reset_flag.wait()
            uart.clear_input_fifo()
            uart.reset_log_file(make_log_file(argv.log_file))
            test_task.reset_log_file(
                make_log_file(argv.log_file+'_monkey_key'))
            system_reset_flag = mp.Event()
            uart_print.restart(uart, stop_flag, system_reset_flag)
            uart.logger.debug('========================================')
            uart.logger.debug('*** ready for next test ***')
            timing(cfg.RESET_SYSTEM_WAIT_TIME)  # wait for system into desktop
            if not uart.isOpen():
                uart.logger.debug('*** uart port is not open***')
                while uart.createPort():
                    uart.logger.debug('*** rebuild uart port ***')
                    time.sleep(5)
            if not uart_print.isOpen():
                uart.logger.debug('*** restart uart_print ***')
                uart_print.restart(uart, stop_flag, system_reset_flag)
            while 1:
                uart.clear_input_fifo()
                if uart.check_status():  # timeout not into desktop
                    break
                else:
                    uart.logger.debug('*** wait for system into desktop ***')
                raise Exception('not reset after PMIC WDG timeout')
            time.sleep(1)
            uart.logger.debug('*** ready for next test done ***')
            uart.logger.debug('========================================')
            uart.logger.debug("*** monkey test restart ***")
            uart.clear_input_fifo()
            uart.input("CMD+WDGD\n") #close wdg
            test_task.restart(uart, stop_flag)
            timer.restart(uart, stop_flag)
    except TestEndException:
        pass
    except Exception, e:
        logger.error(repr(e))
    finally:
        test_task.terminate() if test_task else None
        # timer.terminate() if timer else None
        uart_input.terminate() if uart_input else None
        uart_print.terminate() if uart_print else None
        logger.debug('test done')
