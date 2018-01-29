'readExcel to datastruct @zhenbo.zhan'
import string
import copy

def GetMiddleStr(content,startStr,endStr):
	startIndex = content.index(startStr)
	if startIndex >= 0:
		startIndex += len(startStr)
	endIndex = content.index(endStr)
	return content[startIndex:endIndex]

class excel_contents_sub_multi_rows(object):
	'define excel all contents data and some methods'
	def __init__(self):
		pass
	def update(self, bit, field_name, rw, reset_value, setclear, misc, desc, bits_row):
		self.bit = bit.replace('[','').replace(']','').replace('/','_').replace('\\','_')
		self.field_name = field_name.replace('[','').replace(']','').replace('/','_').replace('\\','_')
		self.rw = rw
		self.reset_value = reset_value
		self.setclear = setclear
		self.misc = misc
		self.desc = desc.replace('<p>' , '  ')
		self.bits_row = bits_row

class excel_contents(object):
	'define excel all contents data and some methods'
	def __init__(self):
		self.table_name = ''
		self.project_name = ''
		self.sub_system_name = ''
		self.module_name = ''
		self.reg_name = ''
		self.reg_offset = 0
		self.has_bits = 1	#1:For example: Offset: 'IPC 0' L1 0x34. 'IPC 1' L2 0x38. 'IPC 2' L3 0x3C.
							#These 3 registers have the same definition of bits, so reg_num = 3
		self.only_module_name_and_base = 0	#2:for sone tables have defined multi-instance of module,
											#Some informathion can refer to the previous-defined(regs/bits)
		self.short_desc = ''
		self.detail = ''
		self.sub_list = []
		self.base_addr = 0
	def update(self, reg_name, reg_offset, short_desc, detail_desc, width, has_bits, only_moduleN_base):
		self.reg_name = reg_name.replace('[','').replace(']','').replace('/','_').replace('\\','_')
		self.reg_offset = reg_offset
		self.short_desc = short_desc
		self.detail = detail_desc
		self.has_bits = has_bits
		self.only_module_name_and_base = only_moduleN_base
	def update_global(self, project_name, sub_system_name, module_name, base_addr, table_name):
		self.table_name = table_name
		self.project_name = project_name
		self.sub_system_name = sub_system_name
		self.module_name = module_name
		self.base_addr = base_addr
	def update_sub_list(self, tmp_list):
		self.sub_list.append(tmp_list)
	def clean_sub_list(self):
		self.sub_list = []

class interrupt_contents(object):
	'Get all contents data of interrupt from define excel'
	def __init__(self):
		self.table_name = ''
		self.interrupt_name = ''
		self.interrupt_num = ''
		self.description = ''

	def update(self,interrupt_name, num, des, table_name):
		self.interrupt_name = interrupt_name
		self.interrupt_num = num
		self.description = des
		self.table_name = table_name

excel_list = []

#local function for interrupt
def parse_int(s):
	excel_list = []
	content = interrupt_contents()
	nrows = s.nrows
	ncols = s.ncols
	curr_row = 0

	while curr_row < nrows:
		row = curr_row
		curr_row = curr_row + 1

		num = str(s.cell_value(row, 0))
		name = str(s.cell_value(row, 1))
		des = str(s.cell_value(row, 3)).rstrip().lstrip()

		if (num != "" and name != ""):
			if name.find('RSVD') != -1:
				continue
			name = name.split(" ")[0]
			name = name.upper().rstrip().lstrip()
			name = name.replace('[','').replace(']','').replace('/','_').replace('\\','_').replace(' ','')
			if "[" not in num :
				continue

			num = GetMiddleStr(num,"[","]")

			content.update(name,num,des,s.name)
			excel_list.append(copy.deepcopy(content))
	return excel_list


#api
def read_excel_file(s):
	excel_list = []
	content = excel_contents()
	tmp_sub_rows = excel_contents_sub_multi_rows()

	print ("Sheets name: " + s.name)
	nrows = s.nrows
	ncols = s.ncols

	curr_row = 0

#Is this interrupt file?
	if (nrows>0):
		romdata = s.row_values(0)
		tmp_string = str(romdata[0]).upper()
		if (tmp_string.find('INT NUMBER') != -1):
			print "Parse interrupt definitions file"
			return parse_int(s)

	if (nrows>1):
		romdata = s.row_values(1)
		tmp_string = str(romdata[0])
		if (tmp_string.find('AQUILA Clock Scheme') != -1):
			print "this is clock related excel, skiping"
			return -1

#Get the module name from spec.
	module_name = ''
	base_addr = ''
	while curr_row < nrows:
		rowdata = s.row_values(curr_row)
		if type(rowdata[0]) != float:
			tmp_string = rowdata[0].upper()
#			print tmp_string
			if tmp_string.find('BASE:') == 0 or tmp_string.find('BASE :') == 0:
#				print "module name is 1:" + tmp_string
				tmp_string = tmp_string.replace('_BASE','')
				tmp_string = tmp_string.replace('BASE:','')
				tmp_string = tmp_string.replace('BASE :','')
				tmp_string = tmp_string.replace(' ','')
				tmp_string = tmp_string.replace(':','')

				lisss = tmp_string.split('0X')

				module_name = module_name + lisss[0]
				base_addr = base_addr + '0x' + lisss[1].replace('_','')
				if curr_row + 1 < nrows:
					if s.row_values(curr_row + 1)[0].find("BASE") == -1:
						break
					else:
						module_name = module_name + ','#multi-module-name, share the same definitions of registers and bits.
						base_addr = base_addr + ','
#Get the base address, Only support one base address in one sheet
		curr_row = curr_row + 1

	llll = module_name.replace(',',' ')
	if llll == "":
		print "Maybe this table is not corretly code:2 "
		return -1

	print "Upate base_addr", base_addr
	content.update_global("", "", module_name, base_addr, s.name)

#Get this module's registers and bits.
	while curr_row < nrows:
		rowdata = s.row_values(curr_row)
#		print curr_row
		if type(rowdata[0]) == float:
			rowdata[0] = str(rowdata[0])
		if rowdata[0].find('Offset:',0,20) == 0:#let using the Offset for the center
			find_reg_name = curr_row -1
			while (s.row_values(find_reg_name - 2)[0] != ""):#maybe we have some lines comments.Need to Skip.
				find_reg_name = find_reg_name -1

			reg_name = s.row_values(find_reg_name)[0];
			reg_name = reg_name.replace('/','_')
			reg_name = "".join(reg_name.split())
			llll = reg_name.split('(')#Maybe some special comments/regs name/.... at the reg name behind.
			llll = llll[0].split('/')
			llll = llll[0].split(',')
			llll = llll[0].split(' ')
			if (len(llll[0]) > 40):
				print llll[0]
				raise "Error length for this register"
			reg_name = llll[0]

			short_desc = s.row_values(find_reg_name - 1)[0];

#do {Offset: 'IPC 0' L1 0x34. 'IPC 1' L2 0x38. 'IPC 2' L3 0x3C."}  OR  {Offset: ' ' L1 0x00. ' ' L2 0x8.}
			rowdata[0] = rowdata[0].upper()
			llll = rowdata[0].split('T:')#Offset:0x0 OR Offset:0x0-0x4 OR Offset:0x0 - 0x4
			llll = llll[1].strip()
			llll = llll.replace('-0X','.')
			llll = llll.replace('- 0X','.')
			llll = llll.replace(' ','.')
			reg_offset = llll.strip()
			count = reg_offset.count("0X")
#			print count, reg_offset
			if count == 1:
				llll = reg_offset.split('.')#delete".xxx"
				reg_offset = llll[0]
				content.update(reg_name, reg_offset, short_desc, short_desc, 32, 1, 0)
			else:
				i = 0
				while 1:
					ret = reg_offset.find("0X")
					if ret != -1:
						_name = reg_name + str(int(i))
						lll = reg_offset.split('0X', 1)
						reg_offset = lll[1]#for the next loop
						if reg_offset.find('.') != -1:
							lll = reg_offset.split('.',1)
							offset_tmp = lll[0].strip()
						else:
							offset_tmp = reg_offset
						offset_tmp = '0x' + offset_tmp
#						print i , count, offset_tmp, _name, reg_offset
						if i >= count - 1:
							content.update(_name, offset_tmp, short_desc, short_desc, 32, 1, 0)
							break
						else:
							content.update(_name, offset_tmp, short_desc, short_desc, 32, 0, 0)
							excel_list.append(copy.deepcopy(content))#update immediately, because we have not bits, next loop will override content.
						i = i + 1
					else:
						break
#
#find the Bits line
			curr_row = curr_row + 1
			while (curr_row < s.nrows):
#				print s.row_values(curr_row)[0]
				if s.row_values(curr_row)[0] == float:
					s.row_values(curr_row)[0] = str(s.row_values(curr_row)[0])
				if (s.row_values(curr_row)[0].strip() == "Bits"):
					break
				curr_row = curr_row + 1
#end
			if (s.row_values(curr_row)[0].strip() != "Bits"):
				raise "Error: \n"
			else:
				content.clean_sub_list()
				bits_row = curr_row + 1 #to the bits number line
				while (bits_row < s.nrows):
					if (str(s.cell_value(bits_row, 0)).isdigit() != True and False == ':' in str(s.cell_value(bits_row, 0))):
						continue

					if (str(s.cell_value(bits_row, 0)) == "" and str(s.cell_value(bits_row, 6)) == ""):
						break

					if (str(s.cell_value(bits_row, 0)) != "" and s.cell_value(bits_row, 1).rstrip().lstrip() != "Reserved"):
						bit = str(s.cell_value(bits_row, 0))
#						print "bit source = " + bit
						field_name = s.cell_value(bits_row, 2)
						field_name = "".join(field_name.split())
						rw = s.cell_value(bits_row, 3)
						init_value = s.cell_value(bits_row, 4)
						desc = s.cell_value(bits_row, 6)
						tmp_sub_rows.update(bit, field_name, rw, init_value, 0, 0, desc, bits_row)
						# print rw,":",init_value
						content.update_sub_list(copy.deepcopy(tmp_sub_rows))
					curr_row = bits_row
					bits_row = bits_row + 1

#			print "Add one entry to the excel_list struct\n"
			excel_list.append(copy.deepcopy(content))
		curr_row = curr_row + 1

	return excel_list

