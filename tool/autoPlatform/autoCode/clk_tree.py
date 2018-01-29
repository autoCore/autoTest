#!/usr/bin/env python
'dump the clock tree form the excel'

import os
import sys
import xlrd
import copy

from ete2 import Tree

print "Create clock tree\n\r"
if (len(sys.argv) < 2):
	print "Using the default file, you also can pass the fileName to argc1", + len(sys.argv)
	if os.path.isfile("./excel/clock.xls") == True:
		fname_excel = "./excel/clock.xls"
	else:
		exit(-1)
else:
	fname_excel = str(sys.argv[1])

isExists = os.path.exists("./tmp")
if not isExists:
    os.mkdir("./tmp")

os.system('chmod +w tmp')

workbook = xlrd.open_workbook(fname_excel)
os.chdir(r"./tmp")

regs_cols = 2
nrow = 0
ncol = 0

def add_child_to_node(s, tree, name):
	curr_cols = regs_cols + 1
	curr_row = 2

	name = name.lower()
	while curr_cols < ncol:
		_string = s.cell_value(2, curr_cols).lower()
#		print curr_cols, name, _string

		if "note" ==  _string:
			break
		_string_name = ''
		if '(' in _string:
			_string_name = _string.split('(')[0].lower()
		if name == _string_name:
			while curr_row < nrow:
				num = s.cell_value(curr_row, curr_cols)

				if num == '' or type(num) != float:
					curr_row = curr_row + 1
					continue
#				print "cols:", curr_cols, "rows:", curr_row, _string
				_t = tree.add_child(name = s.cell_value(curr_row, 0))
				add_child_to_node(s, _t, s.cell_value(curr_row, 0))
				curr_row = curr_row + 1
			break
		curr_cols = curr_cols + 1

clock_tree_array = []
for s in workbook.sheets():
	if s.name != "AP_CLOCK":
		continue

	nrow = s.nrows
	ncol = s.ncols - 1  #last line is note

#find the root clock: find all the clock that dont have parent in the rows.
	curr_row = 0
	while curr_row < nrow:
		if "src_reg" not in s.cell_value(curr_row, regs_cols):
			curr_row = curr_row + 1
			continue
		clock_name = s.cell_value(curr_row, 0)
		t = Tree()

		parent_name = ''
		curr_cols = regs_cols + 1
		while curr_cols < ncol:
			_string = s.cell_value(2, curr_cols)
			if _string == '':
				curr_cols = curr_cols + 1
				continue
			if "note" ==  _string:
				break

			num = s.cell_value(curr_row, curr_cols)
			if num == '' or type(num) != float:
				curr_cols = curr_cols + 1
				continue

			parent_name = parent_name + '@' +  _string

			curr_cols = curr_cols + 1

		if parent_name == '':
			t.add_child(name = clock_name)
			clock_tree_array.append(copy.deepcopy(t))

#		print clock_name + ':'+ parent_name
		curr_row = curr_row + 1

#find the tree that belongs to this root
	for _table_index in range(len(clock_tree_array)):
		t = clock_tree_array[_table_index]
#		print "doing root name = " + t.children[0].name
		add_child_to_node(s, t.children[0], t.children[0].name)

#find the leaf's all parent, using '@' to split.
	for _table_index in range(len(clock_tree_array)):
		t = clock_tree_array[_table_index]

		for leaf in t.children[0]:
			_tmp_string = ''
			#find the all trees.
			for _i in range(len(clock_tree_array)):
				_t = clock_tree_array[_i]
				for _leaf in _t.children[0]:
					_tmp = _leaf.name
					if '@' in _tmp:
						_tmp = _tmp_string.split('@')[0]
					if _tmp == leaf.name and _leaf.get_ancestors()[0].name != '':
						_tmp_string = _tmp_string + '@' + _leaf.get_ancestors()[0].name
			if _tmp_string != '':
				leaf.name = leaf.name + _tmp_string
#OK.Got the tree.
	for _table_index in range(len(clock_tree_array)):
		t = clock_tree_array[_table_index]
		print t.get_ascii(show_internal=True)

