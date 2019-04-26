#! /usr/bin/env python

import sys
import re
import os
import copy
import argparse
from collections import defaultdict, namedtuple, OrderedDict
from handler import *
from util import *
from rules import *
import xlrd

reload(sys)
sys.setdefaultencoding('utf-8')


class Table:
    def __init__(self, table_name):
        self.table_name = table_name
        self.project_name = ''
        self.module_base_d = {}

    def addBase(self, module_name, base):
        self.module_base_d[module_name] = base

# RegInfo = namedtuple('info',['short_desc','detail','reg_name','number','incr_offset'])
# RegInfo = namedtuple('info',['short_desc','detail','reg_name','number','incr_offset'])


class Register(Table):
    def __init__(self, table_name):
        Table.__init__(self, table_name)
        self.reg_name = ''
        self.reg_offsets = []

        self.short_desc = ''
        self.detail = ''
        self.number = 1
        self.incr_offset = ''
        self.reg_fields = []
        self.FMPragraphFormat = None
        self.endflag = False

    def fillInfo(self, reg_name, short_desc, detail_desc, number):
        self.reg_name = reg_name
        self.short_desc = short_desc
        self.detail = detail_desc
        self.number = number

    def addOffset(self, offset):
        self.reg_offsets.append(offset)

    def addRegField(self, reg_field):
        self.reg_fields.append(reg_field)

    def isBits(self):
        return bool(len(self.reg_fields))

    def is_MultiOffset(self):
        return bool(len(self.reg_offsets))

    def clear(self):
        self.reg_offsets = []
        self.reg_fields = []
        self.FMPragraphFormat = None


class Parse:
    def __init__(self, handler):
        self.handler = handler
        self.rules = []

    def addRule(self, rule):
        self.rules.append(rule)

    def parse(self, file):
        s_list = [s for s in file if s.name not in ['Overview',
                                                    'DocHistory', 'Readme', 'AIBmfpr_list', 'Sheet1', 'Sheet2']]
        for s in s_list:
            register = Register(s.name)
            RegField = namedtuple('RegField', ['bit_field', 'field_name', 'FieldCode',
                                               'rw', 'reset_value', 'Secure', 'IndividualField', 'WRCondition', 'desc', 'FMCondition'])
            for block in blocks(s):
                for rule in self.rules:
                    if rule.condition(block):
                        if rule.action(block, handler, register, RegField):
                            break
                register_list.append(copy.deepcopy(register))
                register.clear()
        return register_list


class BasicTextParse(Parse):
    def __init__(self, handler):
        Parse.__init__(self, handler)
        self.addRule(BaseRule())
        self.addRule(RegisterRule())
        self.addRule(RegfieldRule())


if __name__ == '__main__':
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument('file_name', help='Pls input file name ')
    argv = arg_parser.parse_args()
    handler = RegisterRenderer()
    parser = BasicTextParse(handler)

    os.system('rm ./tmp -rf')
    os.mkdir("./tmp")
    register_list = []

    fname_excel = argv.file_name
    workbook = xlrd.open_workbook(fname_excel)
    register_list = parser.parse(workbook.sheets())
    reg_base_string_list = []
    for register in register_list:
        for module_name, base in sorted(register.module_base_d.items(), key=lambda item: item[0]):
            reg_base_name = 'REGS_' + module_name.strip().upper()
            reg_base_micro = "#define   % -60s %s" % (
                reg_base_name, base.strip().upper())
            reg_base_string_list.append(reg_base_micro)
    reg_base_string_list = sorted(
        set(reg_base_string_list), key=reg_base_string_list.index)
    base_file = open("./tmp/__regs_base_addr.h", 'w')
    base_file.write('\n'.join(reg_base_string_list))
    base_file.flush()
    base_file.close()
    register_define_list = []
    bits_field_list = []
    reset_value_list = []

    file_d = defaultdict(list)
    for register in register_list:
        file_d[register.table_name.lower()].append(register)

    for key in file_d:
        fname = "./tmp/__regs_%s.h" % key
        print fname
        fobj = open(fname, 'w')
        c_head_file = open('c_header_file_head')
        fobj.write(c_head_file.read())
        fobj.write("\n")

        micro_base_str = '_'.join(sorted(file_d[key][0].module_base_d.keys()))
        micro_base_str = "REGS_" + micro_base_str.replace('_BASE', '')
        header_macro = '#ifndef __H_%s_HEADFILE_H__' % micro_base_str
        header_macro1 = header_macro.replace(
            '#ifndef', '#define') + ' __FILE__'
        header_macro2 = '\n#define %s' % micro_base_str
        # print '\n'.join([header_macro,header_macro1,header_macro2])
        fobj.write('\n'.join([header_macro, header_macro1, header_macro2]))
        registers_define_comment_string = '/* registers definitions for %s */' % micro_base_str
        register_define_list.append('\n\n'+registers_define_comment_string)
        register_d = OrderedDict()
        for register in file_d[key]:
            if register.reg_name in register_d:
                if register.reg_offsets:
                    register_d[register.reg_name].reg_offsets = register.reg_offsets[:]
                if register.reg_fields:
                    register_d[register.reg_name].reg_fields = register.reg_fields[:]
                if register.FMPragraphFormat:
                    register_d[register.reg_name].FMPragraphFormat = register.FMPragraphFormat
            else:
                register_d[register.reg_name] = register

        for register in register_d.values():
            for module_name in sorted(register.module_base_d.keys()):
                reg_base_name = 'REGS_' + module_name.strip().upper()
                reg_name_micro = '_'.join(
                    ['REGS', module_name.replace('_BASE', ''), register.reg_name.upper()])
                if register.FMPragraphFormat and register.FMPragraphFormat not in reg_base_name:
                    continue
                if int(register.number) == 1 and register.reg_offsets:
                    register_define_list.append('\n#define % -60sASR_ADDR(%s, %s)/*%s*/'
                                                % (reg_name_micro, reg_base_name, register.reg_offsets[0].upper(), register.detail))
                else:
                    for i, offset in enumerate(register.reg_offsets):
                        if 'RESERVED' in register.reg_name.upper():
                            reg_name_micro_tmp = reg_name_micro+'_%s' % i
                        else:
                            reg_name_micro_tmp = reg_name_micro+'_%s_MEMREG' % i
                        register_define_list.append('\n#define % -60sASR_ADDR(%s, %s)/*%s*/'
                                                    % (reg_name_micro_tmp, reg_base_name, offset.upper(), register.detail))
                if not register.isBits():
                    continue

                bits_define_comment_str = "\n/* bits definitions for register %s */\n" % reg_name_micro
                rest_define_comment_str = "\n/* reset value definitions for register %s */\n" % reg_name_micro
                reset_value_list.append(rest_define_comment_str)
                bits_field_list.append(bits_define_comment_str)
                reset_value = 0
                for sub_bits in register.reg_fields:
                    if sub_bits.field_name.strip():
                        if ":" in str(sub_bits.bit_field):
                            bit_end, bit_start = sub_bits.bit_field.replace(
                                ' ', '').split(":")
                            if bit_end.isdigit() and bit_start.isdigit():
                                filed_bitWidth = eval(
                                    bit_end) - eval(bit_start) + 1
                                if sub_bits.reset_value:
                                    reset_value += (int(eval(str(sub_bits.reset_value)))
                                                    ) << (int(bit_start))
                            else:
                                print 'TYPE error', 'bit_field:', sub_bits.bit_field
                                continue
                            _bit_list = ["BIT(%s)" % _bit for _bit in range(
                                eval(bit_start), eval(bit_end)+1)]
                            micro1_str = "BITS_%s(_X_)" % sub_bits.field_name.upper().replace(
                                ' ', '')
                            if eval(bit_start):
                                micro2_str = '( (_X_) << %s & ( %s ) )' % (
                                    bit_start, "|".join(_bit_list))
                            else:
                                micro2_str = '( (_X_) & ( %s ) )' % (
                                    "|".join(_bit_list))
                            _str = "#define % -60s %s\n" % (
                                micro1_str, micro2_str)
                            # print _bit_list,bit_end,bit_start
                            bits_field_list.append(_str)
                            bits_desc = sub_bits.desc.rstrip().lower()
                            rw = sub_bits.rw.rstrip().lower()
                            init_value = sub_bits.reset_value
                            astring = sub_bits.field_name
                        else:
                            if sub_bits.reset_value:
                                reset_value += int(eval(str(sub_bits.reset_value))
                                                   ) << int(eval(str(sub_bits.bit_field)))
                            micro1_str = "BIT_%s" % sub_bits.field_name.upper().replace(' ', '')
                            _str = "#define % -60s ( BIT(%s) )\n" % (
                                micro1_str, sub_bits.bit_field)
                            bits_field_list.append(_str)
                if int(register.number) > 1:
                    for i in range(int(register.number)):
                        if 'RESERVED' in register.reg_name.upper():
                            reg_name_micro_tmp = 'RST_VAL_' + \
                                reg_name_micro.replace('REGS_', '')+'_%s' % i
                        else:
                            reg_name_micro_tmp = 'RST_VAL_' + \
                                reg_name_micro.replace(
                                    'REGS_', '')+'_%s_MEMREG' % i
                        str_ = "#define % -60s 0x%x\n" % (
                            reg_name_micro_tmp, reset_value)
                        reset_value_list.append(str_)
                elif int(register.number) == 1:
                    str_ = "#define % -60s 0x%x\n" % (
                        'RST_VAL_'+reg_name_micro.replace('REGS_', ''), reset_value)
                    reset_value_list.append(str_)
                reset_value = 0
        if register_define_list:
            register_define_list.append("\n\n\n")
            fobj.write(''.join(register_define_list))
            register_define_list = []

        if reset_value_list:
            reset_value_list.append("\n\n\n")
            fobj.write(''.join(reset_value_list))
            reset_value_list = []

        if bits_field_list:
            fobj.write(''.join(bits_field_list))
            bits_field_list = []
        fobj.write("\n#endif\n")
        fobj.flush()
        fobj.close()
