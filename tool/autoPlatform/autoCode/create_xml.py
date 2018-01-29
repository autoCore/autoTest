#encoding:utf-8
from xml.dom.minidom import Document

def xml_create_basic_struct(_doc):
	_doc.createElement('spirit:memoryMaps')
	memoryMaps = _doc.createElement('spirit:memoryMaps')
	_doc.appendChild(memoryMaps)

	memoryMap = _doc.createElement('spirit:memoryMap')
	memoryMaps.appendChild(memoryMap)

	name = _doc.createElement('spirit:name')
	string = _doc.createTextNode('some_register_map')
	name.appendChild(string)
	memoryMap.appendChild(name)

	name = _doc.createElement('spirit:displayName')
	string = _doc.createTextNode('RDL Example Registers')
	name.appendChild(string)
	memoryMap.appendChild(name)

	spirit_addressBlock = _doc.createElement('spirit:addressBlock')
	memoryMap.appendChild(spirit_addressBlock)

	name = _doc.createElement('spirit:name')
	string = _doc.createTextNode('some_register_map')
	name.appendChild(string)
	spirit_addressBlock.appendChild(name)

	name = _doc.createElement('spirit:displayName')
	string = _doc.createTextNode('ASR Module Registers')
	name.appendChild(string)
	spirit_addressBlock.appendChild(name)

	name = _doc.createElement('spirit:description')
	string = _doc.createTextNode('This address map contains some example registers to show how RDL can be utilized in various situations.')
	name.appendChild(string)
	spirit_addressBlock.appendChild(name)
	return spirit_addressBlock

def output_xml_filed(doc, parent, filed_name, filed_des, filed_bitOffset, filed_bitWidth,filed_access, bits_value, bits_name):
	_field_name = doc.createElement('spirit:field')
	parent.appendChild(_field_name)

	name = doc.createElement('spirit:name')
	string = doc.createTextNode(filed_name)
	name.appendChild(string)
	_field_name.appendChild(name)

	name = doc.createElement('spirit:description')
	string = doc.createTextNode(filed_des)
	name.appendChild(string)
	_field_name.appendChild(name)

	name = doc.createElement('spirit:bitOffset')
	if '.' in filed_bitOffset:
		ddd = filed_bitOffset.split('.')
		filed_bitOffset = ddd[0]
	string = doc.createTextNode(filed_bitOffset)
	name.appendChild(string)
	_field_name.appendChild(name)

	name = doc.createElement('spirit:bitWidth')
	string = doc.createTextNode(filed_bitWidth)
	name.appendChild(string)
	_field_name.appendChild(name)

	name = doc.createElement('spirit:access')
	string = doc.createTextNode(filed_access)
	name.appendChild(string)
	_field_name.appendChild(name)


	#...filed value enum
	_field_value = doc.createElement('spirit:values')
	_field_name.appendChild(_field_value)

	#value 0
	name = doc.createElement('spirit:bits_value')
	string = doc.createTextNode(str(bits_value))
	name.appendChild(string)
	_field_value.appendChild(name)

#	name = doc.createElement('spirit:name')
#	string = doc.createTextNode(bits_name)
#	name.appendChild(string)
#	_field_value.appendChild(name)

	#value 1
#	name = doc.createElement('spirit:value')
#	string = doc.createTextNode('0x1')
#	name.appendChild(string)
#	_field_value.appendChild(name)

#	name = doc.createElement('spirit:name')
#	string = doc.createTextNode('xxxx')
#	name.appendChild(string)
#	_field_value.appendChild(name)

def output_xml_register(doc, spirit_addressBlock, register_name, register_description, register_offset, register_size,register_volatile, register_access,
	register_reset_value, register_reset_mask):

	parent = doc.createElement('spirit:register')
	spirit_addressBlock.appendChild(parent)

	name = doc.createElement('spirit:name')
	string = doc.createTextNode(register_name)
	name.appendChild(string)
	parent.appendChild(name)

	name = doc.createElement('spirit:description')
	string = doc.createTextNode(register_description)
	name.appendChild(string)
	parent.appendChild(name)

	name = doc.createElement('spirit:addressOffset')
	string = doc.createTextNode(register_offset)
	name.appendChild(string)
	parent.appendChild(name)

	name = doc.createElement('spirit:size')
	string = doc.createTextNode(register_size)
	name.appendChild(string)
	parent.appendChild(name)

	name = doc.createElement('spirit:volatile')
	string = doc.createTextNode(register_volatile)
	name.appendChild(string)
	parent.appendChild(name)

	name = doc.createElement('spirit:access')
	string = doc.createTextNode(register_access)
	name.appendChild(string)
	parent.appendChild(name)

	reset_name = doc.createElement('spirit:reset')
	parent.appendChild(reset_name)

	name = doc.createElement('spirit:value')
	string = doc.createTextNode(register_reset_value)
	name.appendChild(string)
	reset_name.appendChild(name)

	name = doc.createElement('spirit:mask')
	string = doc.createTextNode(register_reset_mask)
	name.appendChild(string)
	reset_name.appendChild(name)
	return parent

def output_xml_registers(doc, parent, baseAddress, range, register_width,
	register_usage, register_volatile_true):
	#base address
	name = doc.createElement('spirit:baseAddress')
	string = doc.createTextNode(baseAddress)
	name.appendChild(string)
	parent.appendChild(name)
	#range
	name = doc.createElement('spirit:range')
	string = doc.createTextNode(range)
	name.appendChild(string)
	parent.appendChild(name)
	#registers witdh
	name = doc.createElement('spirit:width')
	string = doc.createTextNode(register_width)
	name.appendChild(string)
	parent.appendChild(name)
	#usages
	name = doc.createElement('spirit:usage')
	string = doc.createTextNode(register_usage)
	name.appendChild(string)
	parent.appendChild(name)

	#volatile true?
	name = doc.createElement('spirit:volatile')
	string = doc.createTextNode('true')
	name.appendChild(string)
	parent.appendChild(name)