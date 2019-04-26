#! /usr/bin/env python
import re
import copy


class Handler:
    def callback(self, prefix, name, *args):
        method = getattr(self, prefix+name, None)
        if callable(method):
            return method(*args)

    def do(self, name, *args):
        self.callback('do_', name, *args)


class RegisterRenderer(Handler):
    """docstring for RegisterRenderer"""

    def do_capbase(self, block, register, regfield):
        block = [row[0].upper() for row in block]
        for _string in block:
            match = re.search('BASE[ ]?:(.*?)0X([a-fA-F0-9\_]+)', _string)
            if match:
                module_name = match.group(1).strip()
                module_name = module_name.split()[0]
                module_name = module_name if 'BASE' in module_name else module_name + '_BASE'
                base_addr = '0x' + match.group(2).strip().replace('_', '')
                register.addBase(module_name, base_addr)
                # print module_name,base_addr

    def do_capregister(self, block, register, regfield):
        try:
            value_l = []
            for row in block:
                value_l.append(row[0]) if row[0] else None
                if 'Offset:' in row[0] and 'Incr_Offset' not in row[0]:
                    break
            FMPragraphFormat_l = [
                value for value in block if value[10].strip()]
            if FMPragraphFormat_l:
                register.FMPragraphFormat = FMPragraphFormat_l[0][10].upper().replace(
                    'ONLY', '').strip()
            if len(value_l) == 4:
                short_desc = ''
                reg_name = value_l[0].strip()
                detail = value_l[1].strip()
                number = value_l[2].replace('Number:', '').strip()
                incr_offset = 0
            elif len(value_l) == 5:
                if 'Incr_Offset:' in value_l[3]:
                    short_desc = ''
                    reg_name = value_l[0].strip()
                    detail = value_l[1].strip()
                    number = value_l[2].replace('Number:', '').strip()
                    incr_offset = value_l[3].replace('Incr_Offset:', '')
                    incr_offset = eval(incr_offset.strip())
                else:
                    short_desc = value_l[0].strip()
                    reg_name = value_l[1].strip()
                    detail = value_l[2].strip()
                    number = value_l[3].replace('Number:', '').strip()
                    incr_offset = 0
            elif len(value_l) == 6:
                short_desc = value_l[0].strip()
                reg_name = value_l[1].strip()
                detail = value_l[2].strip()
                number = value_l[3].replace('Number:', '').strip()
                incr_offset = value_l[4].replace('Incr_Offset:', '')
                incr_offset = eval(incr_offset.strip())
            else:
                raise Exception, "File type Error"
            off_set_str = value_l[-1].strip().upper()
            # Offset:0x0 OR Offset:0x0-0x4 OR Offset:0x0 - 0x4
            off_set = off_set_str.split('T:')
            off_set = off_set[1].strip()
            off_set_l = [eval(off_set) + i *
                         incr_offset for i in range(eval(number))]
            off_set_l = [str(hex(l)) for l in off_set_l]
            register.fillInfo(reg_name, short_desc, detail, number)
            for offset in off_set_l:
                register.addOffset(offset)
        except Exception, e:
            pass
            print "Error:", e
            print value_l

    def do_capregfield(self, block, register, regfield):
        value_l = []
        start = False
        for row in block:
            if 'Bits:' in row[0]:
                start = True
                continue
            if start:
                value_l.append(row[0])
            if not row[0]:
                break
        print value_l
        raw_input()
        for row in value_l:
            reg_field = regfield(*row[:10])
            # print reg_field
            # raw_input('=====================================')
            register.addRegField(reg_field)
