#!/usr/bin/env python
from serial.tools.list_ports import comports
import serial
from serial import Serial
import platform
import argparse
import signal
import random
import re
import traceback
import util
import pexpect
import threading
import time
import crane_cfg as cfg
import multiprocessing as mp
import pysnooper

def signal_handler(signum, frame):
    raise TestEndException


class TestEndException(Exception):
    pass


class Uart(object):
    def __init__(self, log_file=None, is_print=True):
        super(Uart, self).__init__()
        self.log = open(log_file, 'a') if log_file else open(
            'test_log.log', 'a')
        self.comport = None
        self.is_print = mp.Event()

        self.expect_match = mp.Event()
        self.busy_flag = mp.Event()
        self.input_fifo = mp.Queue(1)

        self.log_lock = mp.Lock()
        self.log_flag = mp.Event()

        self.open_flag = False
        self.open_wachdog_flag = False
        self.sodo_password = util.get_sudo_password()
        self.log_flag.set()
        self.is_print.set()

    def isOpen(self):
        return self.comport.isOpen()

    def input(self, msg, pattern_str='', timeout=1, simulate_key=None):
        self.input_fifo.put((msg, pattern_str, simulate_key))
        if pattern_str:
            return self.expect(pattern_str, timeout, input_flag=True)
        return True

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
        # print_log(' '*cfg.SPACES_CNT + '< %.3fs >'%(time.time()-time_))
        return res

    def reset_system(self, timeout=3):
        self.open_flag = False
        self.open_wachdog_flag = False
        return self.input("CMD+RST\n", 'RST', timeout)

    def back_destop(self):
        self.simulate_key_input('0')
        self.simulate_key_input('P')

    def check_status(self, timeout=3):
        if self.input("KEY#\n", 'Unknown command', 1):
            self.open_key_test()
        return self.input("CMD+STATUS\n", 'STATUS', timeout)

    def open_wachdog(self, timeout=3):
        for __ in range(3):
            if self.open_wachdog_flag:
                break
            else:
                self.open_wachdog_flag = self.input(
                    "CMD+WDGE\n", 'WDGE', timeout)
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

    def open_key_test(self):
        self.input("KEY#**\n")
        self.open_flag = True
        time.sleep(float(cfg.SIMULATE_KEY_INPUT_INTERVAL))

    def close_key_test(self):
        self.input("KEY###\n")
        self.open_flag = False
        time.sleep(float(cfg.SIMULATE_KEY_INPUT_INTERVAL))

    def simulate_key_input(self, key_value):
        if not self.open_flag:
            self.open_key_test()
        self.input(key_value, simulate_key=True)
        self.write_log('[pylog]:'+key_value)
        time.sleep(float(cfg.SIMULATE_KEY_INPUT_INTERVAL))

    def open_usk(self):
        self.input("usk enable\n")
        time.sleep(float(cfg.SIMULATE_KEY_INPUT_INTERVAL))

    def write_log(self, msg):
        with self.log_lock:
            self.log.write(msg+'\n')
            self.log.flush()

    def reset_log_file(self, file_name):
        with self.log_lock:
            self.log.flush()
            self.log.close()
            self.log = open(file_name, 'a')

    def save_log_file(self):
        with self.log_lock:
            self.log.flush()
            self.log.close()
            self.log = None

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
            print 'port:', port_list
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
                            print('No device')
            else:
                print("No port")
                sys.exit(0)
        print_log('current port name:'+port)
        self.comport = Serial(port, baud, timeout=time_out)
        self.timeout = time_out
        if self.comport.isOpen():
            return 1
        else:
            print("create port fail")
            sys.exit(1)

    def close(self):
        self.log.flush()
        self.log.close()
        self.comport.close()


class UartMonitor(util.ProcBase):
    def __init__(self):
        super(UartMonitor, self).__init__()
        self._simulate_key_Interval = 0.2
        self.pattern = None

    def run(self, uart):
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
                    print_log(' '*cfg.SPACES_CNT +
                              '*** intput: [%s] ***' % msg.strip())
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
                if uart.log_flag.is_set():
                    uart.write_log(line)
                if uart.is_print.is_set():
                    print(line)
                # if debug.is_set(): print ' '*cfg.SPACES_CNT+'[ %.6fs ]'%(time.time()-time_)
        except (KeyboardInterrupt, TestEndException):
            pass
        except Exception, e:
            print_log('Error!')
            print e
        finally:
            uart.expect_match.set()
            stop_flag.set()
            print_log('UartMonitor done')


class UartInput(util.ThreadBase):
    def __init__(self):
        super(UartInput, self).__init__()

    def run(self, uart):
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
                        print_log(' '*cfg.SPACES_CNT+'Pls check your input')
                        continue
                    uart.is_print.set() if eval(value) else uart.is_print.clear()
                elif 'debug' in msg:
                    value_l = msg.split('=')
                    if len(value_l) == 2:
                        value = value_l[1]
                    else:
                        print_log(' '*cfg.SPACES_CNT+'Pls checkl your input')
                        continue
                    debug.set() if eval(value) else debug.clear()
                else:
                    uart.input(msg+'\n')
        except Exception:
            traceback.print_exc()
            print_log('Error:[UartInput],Pls check serial port')
        finally:
            self._running = False
            print_log('UartInput done')
            stop_flag.set()


class MyTimer(util.ThreadBase):
    """docstring for MyTimer"""

    def __init__(self, delay_time):
        super(MyTimer, self).__init__()
        self.__delay_time = delay_time
        self.block = threading.Event()

    def run(self, uart):
        try:
            while self._running:
                self.block.wait(self.__delay_time)
                if not self._running:
                    break
                print_log(' '*cfg.SPACES_CNT+'check status   ')
                uart.write_log('[pylog]:check status')
                if uart.check_status(self.__delay_time):
                    print_log(' '*cfg.SPACES_CNT+'check status pass')
                    uart.write_log('[pylog]:check status pass')
                else:
                    print_log(' '*cfg.SPACES_CNT+'check status fail')
                    uart.write_log('[pylog]:check status fail')
                    stop_flag.set()
                    break
        except Exception:
            traceback.print_exc()
            print_log('Error:[UartController],Pls check serial port')
        finally:
            self._running = False

    def terminate(self):
        if not self._proc:
            return
        self._running = False
        self._proc = None
        print_log('MyTimer done')


class monkeyTestTask(util.ThreadBase):
    """docstring for ClassName"""

    def __init__(self, monkey_log, cfg_file=None):
        super(monkeyTestTask, self).__init__()
        self.monkey_log_fname = monkey_log
        self.monkey_log = open(monkey_log, 'a')
        self.cfg_file = cfg_file
        self.count = 1
        self.cmd_set = None

    def reset_log_file(self, file_name):
        try:
            self.monkey_log.flush()
            self.monkey_log.close()
        except:
            pass
        finally:
            self.monkey_log_fname = file_name
            self.monkey_log = open(file_name, 'a')

    def save_log_file(self):
        try:
            self.monkey_log.flush()
            self.monkey_log.close()
            self.monkey_log = None
        except Exception:
            traceback.print_exc()

    def cfg_test(self, uart):
        with open(self.cfg_file) as file_obj:
            file_text = [
                line_ for line_ in file_obj if not line_.strip().startswith('#')]
            file_text = '|'.join(file_text)
            file_text = '|' + re.sub('\n', '', file_text)
        cmd_set = re.findall('\|AUTOTEST_KEY@\((.*?),(.*?)\)', file_text)
        cnt = re.findall('\|CNT@\((.*?)\)', file_text)
        cnt = int(cnt[0]) if cnt else 1
        for i in range(cnt):
            print_log('\n'.join(
                [' '*cfg.SPACES_CNT+'*'*20, ' '*cfg.SPACES_CNT+"running cnt: %s" % i, ' '*cfg.SPACES_CNT+'*'*20]))
            uart.log.write("running cnt: %s\n" % i)
            for cmd, timeout in cmd_set:
                if not self._running:
                    return
                if stop_flag.is_set():
                    raise TestEndException
                if 'CMD-' in cmd:
                    print_log(' '*cfg.SPACES_CNT+'*** intput: %s ***' %
                              cmd.replace('CMD-', ''))
                    uart.input(cmd.replace('CMD-', '')+'\n')
                    time.sleep(float(timeout))
                    continue
                for send_c in cmd.replace(' ', ''):
                    if not self._running:
                        return
                    print_log(' '*cfg.SPACES_CNT+'*** intput: %s ***' %
                              cfg.key_value_d[send_c])
                    uart.simulate_key_input(send_c)
                    self.monkey_log.write(cfg.key_value_d[send_c]+' ')
                    self.monkey_log.flush()
                    time.sleep(float(timeout))
            else:
                time.sleep(10)
                uart.back_destop()
        else:
            # uart.close_wachdog()
            uart.close_key_test()

    # @pysnooper.snoop('./debug.log')
    def monkey_test(self, uart):
        key_value_item = cfg.key_value_d.items()
        i = 0
        while self._running:
            send_c, send_c_name = random.choice(key_value_item)
            if send_c.isdigit():
                i += 1
                if i < 10:
                    continue
                else:
                    i = 0
            timeout = cfg.SIMULATE_KEY_INPUT_INTERVAL
            print_log(' '*cfg.SPACES_CNT+'*** intput: %s ***' % send_c_name)
            uart.simulate_key_input(send_c)
            self.monkey_log.write(send_c)
            self.monkey_log.flush()
            time.sleep(float(timeout))

    def run(self, uart):
        try:
            uart.open_usk()
            uart.open_key_test()
            uart.unlock()  # ui unlock
            uart.open_wachdog()
            if self.cfg_file:
                self.cfg_test(uart)
            else:
                self.monkey_test(uart)
                # self.contact_test(uart)
        except Exception:
            traceback.print_exc()
            print_log('< monkeyTestTask >')
        finally:
            self.monkey_log.flush()
            self.monkey_log.close()
            self.report(self.monkey_log_fname)

    def terminate(self):
        if not self._proc:
            return
        self._running = False
        self._proc = None
        print_log('monkeyTestTask done')

    def report(self, file_name):
        with open('./autocmd.cfg', 'a') as cfg_file:
            monkey_log = open(file_name).read()
            cfg_log = '# AUTOTEST_KEY@(%s,%s)' % (
                monkey_log, cfg.SIMULATE_KEY_INPUT_INTERVAL)
            cfg_file.write(cfg_log+'\n')

    def alarm_test(self, uart):
        for key_ in ['M', 'V', 'V', 'M', 'M']:
            uart.simulate_key_input(key_)
        key_value_item = cfg.alarm_key_value_d.items()
        cnt = 0
        while self._running:
            send_c, send_c_name = random.choice(key_value_item)
            if send_c_name is 'F_RIGHT':
                cnt += 1
                if cnt < 100:
                    continue
                else:
                    cnt = 0
            timeout = cfg.SIMULATE_KEY_INPUT_INTERVAL
            print_log(' '*cfg.SPACES_CNT+'*** intput: %s ***' % send_c_name)
            uart.simulate_key_input(send_c)
            self.monkey_log.write(send_c)
            self.monkey_log.flush()
            time.sleep(float(timeout))

    # @pysnooper.snoop('./debug1.log')
    def contact_test(self, uart):
        uart.simulate_key_input('V')
        key_value_item = cfg.contact_key_value_d.items()
        cnt = 0
        while self._running:
            send_c, send_c_name = random.choice(key_value_item)
            if send_c_name is 'F_RIGHT':
                cnt += 1
                if cnt < 100:
                    continue
                else:
                    cnt = 0
            timeout = cfg.SIMULATE_KEY_INPUT_INTERVAL
            print_log(' '*cfg.SPACES_CNT+'*** intput: %s ***' % send_c_name)
            uart.simulate_key_input(send_c)
            self.monkey_log.write(send_c)
            self.monkey_log.flush()
            time.sleep(float(timeout))


def print_log(msg):
    if debug.is_set():
        print msg


stop_flag = mp.Event()
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

    try:
        uart = Uart(util.make_log_file(argv.log_file))
        uart.createPort()
        uart_input = UartInput()
        uart_input.start(uart)
        uart_monitor = UartMonitor()
        uart_monitor.start(uart)
        test_task = monkeyTestTask(util.make_log_file(
            argv.log_file+'_monkey_key'), argv.cmd_file)
        timer = MyTimer(cfg.CHECK_INTERVAL)
        print_log(' '*cfg.SPACES_CNT+'***monkey test start***')
        test_task.start(uart)
        timer.start(uart)
        while 1:
            stop_flag.wait()
            test_task.terminate()
            timer.terminate()
            # while 1: pass
            uart.close_wachdog()
            uart.reset_system()  # reset system
            uart.reset_log_file(util.make_log_file(argv.log_file))
            test_task.reset_log_file(
                util.make_log_file(argv.log_file+'_monkey_key'))
            uart_monitor.restart(uart)
            util.timing(cfg.RESET_SYSTEM_WAIT_TIME)  # wait for system into desktop
            if not uart.isOpen():
                uart.createPort()
                print '======================='
            if not uart_monitor.isOpen():
                uart_monitor.restart(uart)
            if not uart.check_status():  # timeout not into desktop
                print_log(' '*cfg.SPACES_CNT +
                          '***wait for system PMIC WDG timeout***')
                util.timing(cfg.PMIC_WGD_TIMEOUT)  # wait for system PMIC WDG timeout
                print '+++++++++++++++++++++++++'
            while not uart.check_status():  # timeout not into desktop
                time.sleep(10)
                print '+++++++++++++++++++++++++===================='
                # raise Exception('not reset after PMIC WDG timeout')
            test_task.restart(uart)
            timer.restart(uart)
            stop_flag.clear()
    except Exception, e:
        print e
    finally:
        test_task.terminate()
        timer.terminate()
        uart_input.terminate()
        uart_monitor.terminate()
        print_log('test done')
