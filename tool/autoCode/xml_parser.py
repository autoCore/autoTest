#!/usr/bin/env python

import xml.dom
import xml.dom.minidom
import xml.parsers.expat
from xml.dom.minidom import parse, Node, Document, parseString
from xml_file import xml_file

print xml_file

def get_field(reg_e):
        reg_t=[]
        reg_field=[]
       	for node in reg_e:
                if(node.nodeName == "#text"):
                        continue
                else:
                        if('spirit:name'== node._get_tagName()):
                                reg_name = node._get_childNodes()[0]._get_wholeText()
                                reg_t.append(reg_name)
                        elif('spirit:addressOffset'== node._get_tagName()):
                                reg_offset = node._get_childNodes()[0]._get_wholeText().lower()
                                reg_t.append(reg_offset)
                        elif('spirit:reset'== node._get_tagName()):
                                reg_reset = node._get_childNodes()
                                reg_reset_value = reg_reset[1]._get_childNodes()[0]._get_wholeText()
                                reg_reset_mask = reg_reset[3]._get_childNodes()[0]._get_wholeText()
                                reg_t.append(reg_reset_value)
                                reg_t.append(reg_reset_mask)
                        elif('spirit:field'== node._get_tagName()):
                                reg_field_t=[]
                                reg_field_e = node._get_childNodes()
                                field_name = reg_field_e[1]._get_childNodes()[0]._get_wholeText()
                                field_offset = reg_field_e[5]._get_childNodes()[0]._get_wholeText()
                                field_width = reg_field_e[7]._get_childNodes()[0]._get_wholeText()
                                field_access = reg_field_e[9]._get_childNodes()
				if([] == field_access):
					field_access = ' '
				else:
					field_access = field_access[0]._get_wholeText()
				field_init_value = reg_field_e[11]._get_childNodes()[1]._get_childNodes()
				if ([] == field_init_value):
					field_init_value = ' '
				else:
					field_init_value = field_init_value[0]._get_wholeText()
                                reg_field_t.append(field_name)
                                reg_field_t.append(field_offset)
                                reg_field_t.append(field_width)
                                reg_field_t.append(field_access)
				reg_field_t.append(field_init_value)
                                reg_field.append(reg_field_t)
        reg_t.append(reg_field)
        return reg_t

def get_regs(doc):
        regs=[]
        reg_base_e = doc.getElementsByTagName('spirit:baseAddress')[0]
        reg_base_t = reg_base_e._get_childNodes()[0]._get_wholeText().lower()
        regs.append(reg_base_t)
        regs_e = doc.getElementsByTagName('spirit:register')
        for reg_e in regs_e:
                reg=[]
                reg_e_child = reg_e._get_childNodes()
                reg=get_field(reg_e_child)
                regs.append(reg)
        return regs

def dump_regs(regs):
        print "module name:" + regs[0]
        print "reg_base:" + regs[1]
        for reg in regs[2:]:
                print "reg_name:" + reg[0]
                print "reg_offset:" + reg[1]
                print "reg_reset_value:" + reg[2]
                print "reg_reset_mask:" + reg[3]
                for reg_field in reg[4]:
                        print "field_name:" + reg_field[0]
                        print "field_offset:" + reg_field[1]
                        print "field_width:" + reg_field[2]
                        print "field_access:" + reg_field[3]
			print "field_init_value:" + reg_field[4]

database=[]

for file_name in xml_file:
        doc = xml.dom.minidom.parse(file_name)
        database.append(doc)


def get_regs_info(doc):        
	regs_info=[]
	comp = doc._get_documentElement()
	module_name = comp._get_childNodes()[5]._get_childNodes()[0]._get_wholeText().lower()
	regs_info.append(module_name)
	regs_info.extend(get_regs(doc))
	return regs_info

'''
'just test for xml parser.'
if __name__ == '__main__':
	for doc in database:
		regs = get_regs_info(doc)
		dump_regs(regs)

'''
