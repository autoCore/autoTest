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
from  util import myLogger, ProcBase, ThreadBase, make_log_file, get_sudo_password, timing, config
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
        self.input_fifo = mp.Queue(1)

        self.open_flag = False
        self.open_wachdog_flag = False
        self.sodo_password = get_sudo_password()
        self.is_print.set()

    def isOpen(self):
        return self.comport.isOpen()

    def input(self, msg, pattern_str='', timeout=1, simulate_key=None):
        self.input_fifo.put((msg, pattern_str, simulate_key))
        if pattern_str:
            return self.expect(pattern_str, timeout, input_flag=True)
        return True

    def clear_input_fifo(self):
        while not self.input_fifo.empty():
            self.input_fifo.get()
        self.comport.flushOutput()

    def expect(self, pattern_str, timeout, input_flag=False):
        if not input_flag:
            self.input_fifo.put(('', pattern_str, None))
        # wait uart input cmd and begin to search the pattern
        self.busy_flag.wait(timeout)
        time_ = time.time()
        # wait uart match the pattern until timeout
        self.expect_match.wait(timeout)
        self.busy_flag.clear()
        res = self.expect_match.is_set()  # if match the pattern res is True else False
        self.expect_match.clear()
        # self.logger.debug('< %.3fs >'%(time.time()-time_))
        return res

    def reset_system(self, timeout=3):
        self.open_flag = False
        self.open_wachdog_flag = False
        while not self.input_fifo.empty():
            self.input_fifo.get()
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
        self.input("KEY#**\n", 'Input command', timeout)

    def close_key_test(self,timeout=3):
        self.open_flag = False
        self.input("KEY###\n", 'Input command', timeout)

    def simulate_key_input(self, key_value):
        if not self.open_flag:
            self.open_key_test()
        self.input(key_value, simulate_key=True)
        self.logger.debug('*** input fifo: %s ***'%key_value)
        time.sleep(float(cfg.SIMULATE_KEY_INPUT_INTERVAL))

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
            logger.info('port: %r'%port_list)
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
        logger.info('current port name:'+port)
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


class UartMonitor(ProcBase):
    def __init__(self):
        super(UartMonitor, self).__init__()
        self._simulate_key_Interval = cfg.KEY_DOWN_UP_INTERVAL
        self.pattern = None

    def run(self, uart, stop_flag):
        try:
            while self._running.is_set():
                time_ = time.time()
                if not uart.input_fifo.empty() and not uart.busy_flag.is_set():
                    msg, pattern_str, simulate_key = uart.input_fifo.get()
                    if simulate_key:
                        uart.comport.write('KEY#'+msg+'0\n')  # key down
                        time.sleep(self._simulate_key_Interval)
                        uart.comport.write('KEY#'+msg+'1\n')  # key up
                    else:
                        time.sleep(self._simulate_key_Interval)
                        uart.comport.write(msg)
                        time.sleep(self._simulate_key_Interval)
                    uart.logger.debug('*** intput: [%s] ***' % msg.strip())
                    if pattern_str:
                        self.pattern = re.compile(pattern_str)
                        uart.busy_flag.set()
                    else:
                        self.pattern = None
                line = uart.comport.readline().strip()
                if not line:
                    continue
                if uart.busy_flag.is_set() and self.pattern:
                    if self.pattern.search(line):
                        uart.busy_flag.clear()
                        uart.expect_match.set()
                        self.pattern = None
                if "CHIP_ID: 0x6731, REV_ID: 0xA0" in line:
                    uart.logger.debug("*** MONKEY TEST CHIP RESET ***")
                    stop_flag.set()
                    system_reset_flag.set()
                uart.logger.info(line)
                # if debug.is_set(): uart.logger.debug('[ %.6fs ]'%(time.time()-time_))
        except (KeyboardInterrupt, TestEndException):
            pass
        except Exception, e:
            uart.logger.error('*** Error! ***')
            uart.logger.error(e)
        finally:
            uart.expect_match.set()
            stop_flag.set()
            uart.logger.info('UartMonitor done')


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
            uart.logger.info('UartInput done')
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
        uart.logger.info('MyTimer done')


class monkeyTestTask(ThreadBase):
    """docstring for ClassName"""

    def __init__(self, monkey_log, cfg_file=None):
        super(monkeyTestTask, self).__init__()
        self.monkey_log_fname = monkey_logger.getLogFile()
        self.monkey_logger = monkey_logger
        self.cfg_file = cfg_file
        self.count = 1
        self.cmd_set = None

    def reset_log_file(self, file_name, fmt = ''):
        if not fmt:
            fmt = '%(message)s'
        self.monkey_logger.resetLogFile(file_name,fmt)

    def cfg_test(self, uart, stop_flag):
        with open(self.cfg_file) as file_obj:
            file_text = [
                line_ for line_ in file_obj if not line_.strip().startswith('#')]
            file_text = '|'.join(file_text)
            file_text = '|' + re.sub('\n', '', file_text)
        cmd_set = re.findall('\|AUTOTEST_KEY@\((.*?),(.*?)\)', file_text)
        cnt = re.findall('\|CNT@\((.*?)\)', file_text)
        cnt = int(cnt[0]) if cnt else 1
        for i in range(cnt):
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
                        self.monkey_logger.write(cfg.key_value_d.get(send_c,'')+' ')
                    time.sleep(float(timeout))
            else:
                time.sleep(1)
                # uart.back_destop()
        else:
            # uart.close_wachdog()
            uart.close_key_test()

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
            uart.open_wachdog()
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
        uart.logger.info('monkeyTestTask done')

    def report(self, file_name):
        with open('./autocmd.cfg', 'a'),open(file_name) as cfg_file,monkey_log:
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

system_reset_flag = mp.Event()
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
    uart = None
    uart_input = None
    test_task = None
    timer = None
    uart_monitor = None
    stop_flag = mp.Event()
    logger = myLogger("monkey_test")
    logger.enablePrint()
    try:
        logger.resetLogFile(make_log_file(argv.log_file))
        uart = Uart(logger)
        uart.createPort()
        uart_input = UartInput()
        logger.info(cfg)
        uart_input.start(uart, stop_flag)
        uart_monitor = UartMonitor()
        uart_monitor.start(uart, stop_flag)
        monkey_logger = myLogger("monkey_log")
        test_task = monkeyTestTask(monkey_logger, argv.cmd_file)
        test_task.reset_log_file(make_log_file(
            argv.log_file+'_monkey_key'))
        timer = MyTimer(cfg.CHECK_INTERVAL)
        uart.logger.debug('*** monkey test start ***')
        test_task.start(uart, stop_flag)
        timer.start(uart, stop_flag)
        while 1:
            # uart.logger.debug(stop_flag.is_set())
            stop_flag.wait()
            # uart.logger.debug(stop_flag.is_set())
            test_task.terminate()
            timer.terminate()
            while test_task.isOpen() or timer.isOpen():
                pass
            stop_flag = mp.Event()
            uart.logger.debug('*** monkey test terminate ***')
            uart.logger.debug('========================================')
            if not system_reset_flag.is_set():
                uart.reset_system()  # reset system
            system_reset_flag.wait()
            while system_reset_flag.is_set():
                system_reset_flag.clear()
            uart.clear_input_fifo()
            uart.reset_log_file(make_log_file(argv.log_file))
            test_task.reset_log_file(
                make_log_file(argv.log_file+'_monkey_key'))
            uart_monitor.restart(uart, stop_flag)
            uart.logger.debug('========================================')
            uart.logger.debug('*** ready for next test ***')
            timing(cfg.RESET_SYSTEM_WAIT_TIME)  # wait for system into desktop
            if not uart.isOpen():
                while uart.createPort():
                    uart.logger.debug('*** rebuild uart port ***')
                    time.sleep(5)
            if not uart_monitor.isOpen():
                uart.logger.debug('*** restart uart_monitor ***')
                uart_monitor.restart(uart, stop_flag)
            while 1:
                uart.clear_input_fifo()
                if uart.check_status():  # timeout not into desktop
                    break
                else:
                    uart.logger.debug('*** wait for system into desktop ***')
                # raise Exception('not reset after PMIC WDG timeout')
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
        timer.terminate() if timer else None
        uart_input.terminate() if uart_input else None
        uart_monitor.terminate() if uart_monitor else None
        logger.info('test done')
