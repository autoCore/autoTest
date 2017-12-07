#!/usr/bin/python
from pyExcelerator import *
from xlrd import *
from xlutils.copy import *
import datetime


# clst_clk_all = [499,624,832,1050,1200,1248,1540,1600,1750,2100]
clst_clk_all = [312,416,624,832,1050,1248,1600,1750,2100]
clusters = ['cluster0','cluster1','cluster2','cluster_multi']
def check_res(_str):
	if 'OK' in _str:
		return True
	else:
		return False

def dvc_parse_test_report(fname):
	workbook = open_workbook(fname)
	table = workbook.sheet_by_name('test_report',formatting_info = True)
	titleBar = table.row_values(1)

	title_text = table.row_values(0)[0]
	dvc_test_res_dict = {}
	_freq_bak = 0
	# res_tmp = open(cfg.res_tmp_dir,'a')
	for i in range(table.nrows):
		if i == 0 or i == 1:
			continue
		try:
			(_No, _module_name, _cmd, _result) = table.row_values(i)
			(_dvc_cmd, _boot_core) = _cmd.split('@')
			(_module, _vol, _freq) = _dvc_cmd.split(' ')
			(_boot, _core) = _boot_core.split(' ')
		except:
			# print 'line:'+str(i),table.row_values(i)
			# res_tmp.write()
			continue
		_vol = int(_vol)
		_freq = _freq[-3:]
		_core = '00%s'%_core
		_core = _core[-3:]
		if _core[:2] == '00':
			_freq = '0' + _freq
		elif _core[1:] == '00':
			_freq = '2' + _freq
		elif _core == '3ff':
			_freq = '3' + _freq
		else:
			_freq = '1' + _freq

		res_list = _result.split('@')
		if all(map(check_res,res_list)):
			_res = 'OK'
		else:
			_res = 'ERR'

		if _freq_bak == _freq:
			dvc_test_res_dict[_freq].append([_vol,_res])
		else:
			dvc_test_res_dict[_freq]=[[_vol,_res]]
		_freq_bak = _freq

	_res_bak = ''
	keys = dvc_test_res_dict.keys()
	keys.sort()
	# for _freq in keys:
		# print _freq+':',dvc_test_res_dict[_freq]
	for _freq in keys:
		Vmin = {}
		if len(dvc_test_res_dict[_freq]) <= 2:
			Vmin['Vmin'] = 'None'
			dvc_test_res_dict[_freq].insert(0,Vmin)
			continue
		for i,_res in enumerate(dvc_test_res_dict[_freq]):
			if 'ERR' == _res[1]:
				if _res == dvc_test_res_dict[_freq][-1]:
					Vmin['Vmin'] = dvc_test_res_dict[_freq][i-1][0]
					dvc_test_res_dict[_freq].insert(0,Vmin)
					break
				if 'ERR' == dvc_test_res_dict[_freq][i+1][1]:
					Vmin['Vmin'] = dvc_test_res_dict[_freq][i-1][0]
					dvc_test_res_dict[_freq].insert(0,Vmin)
					break
			elif _res == dvc_test_res_dict[_freq][-1]:
				Vmin['Vmin'] = _res[0]
				dvc_test_res_dict[_freq].insert(0,Vmin)
				break

		if 'Vmin' in dvc_test_res_dict[_freq][0]:
			pass
		else:
			Vmin['Vmin'] = _res[0]
			dvc_test_res_dict[_freq].insert(0,Vmin)
	# for _freq in keys:
		# print _freq+':',dvc_test_res_dict[_freq]
	append_data = copy(workbook)
	sheet_name = 'Vmin'
	nu = 0
	while sheet_name in workbook.sheet_names():
		nu = nu + 1
		sheet_name =sheet_name[:4] + str(nu)
	else:
		print 'add sheet:',sheet_name
	append_data.add_sheet(sheet_name,formatting_info=True)
	worksheet = append_data.get_sheet(-1)
	worksheet.write(0,0,'clock:')
	clst_cnt = int(keys[0][0])
	# for i,_freq in enumerate(keys,1):
		# print _freq + ':',dvc_test_res_dict[_freq][0]
	if 3 == clst_cnt:
		worksheet.write(1,0,'Vol:')
		for i,_freq in enumerate(keys):
			worksheet.write(2*(i/5),i%5+1,_freq[-3:])
			worksheet.write(2*(i/5)+1,i%5+1,str(dvc_test_res_dict[_freq][0]['Vmin']))
	else:
		for i, _freq in enumerate(clst_clk_all,1):
			worksheet.write(0,i,_freq)
		for i,_freq in enumerate(keys,1):
			# print _freq + ':',dvc_test_res_dict[_freq][0]
			clst_cnt = int(_freq[0])
			_row = clst_cnt + 1
			_col = int(_freq[-_row]) + 1

			worksheet.write(_row,0,clusters[clst_cnt]+':')
			worksheet.write(_row,_col,dvc_test_res_dict[_freq][0]['Vmin'])

	append_data.save(fname)

def excel_style_config(sheet_obj,row_n,col_n,bold,height):

	col_width_list = [1500,6000,20000,16000]
	fnt = Font()
	fnt.name = 'Arial'
	fnt.colour_index = 0
	fnt.bold = bold
	fnt.height = height

	borders = Borders()
	borders.left = 1
	borders.right = 1
	borders.top = 1
	borders.bottom = 1

	al = Alignment()
	al.horz = Alignment.HORZ_CENTER
	al.vert = Alignment.VERT_CENTER

	style = XFStyle()
	style.font = fnt
	style.borders = borders
	style.alignment = al

	sheet_obj.col(col_n).width = col_width_list[col_n]
	return style

def report_excel(autoTest_object_list,fname):
	assert autoTest_object_list, 'autoTest_object_list is blank'
	title_text = 'ASR Ctest report'
	excel_obj = Workbook()
	sheet_obj = excel_obj.add_sheet('test_report')
	sheet_obj.write_merge(0, 0, 0, 3,title_text, excel_style_config(sheet_obj,0,0,True,300))
	titleBar = ["ID","Module Name","Command Name","Test Result"]
	for col_num in range(len(titleBar)):
		sheet_obj.write(1,col_num,titleBar[col_num],excel_style_config(sheet_obj,1,col_num,True,200))

	for i,autoTest_obj in enumerate(autoTest_object_list,2):
		obj_ID = autoTest_obj.ID
		module_name = autoTest_obj.module_name
		cmd_name = '@'.join(autoTest_obj.test_cmd_list)
		test_result = '@'.join(autoTest_obj.test_result)
		if test_result:
			pass
		else:
			continue
		report_text = [str(obj_ID),module_name,cmd_name,test_result]
		for col_num in range(len(titleBar)):
			sheet_obj.write(i,col_num,report_text[col_num],excel_style_config(sheet_obj,i,col_num,False,180))

	excel_obj.save(fname)
	if 'ddr_benchmark' == module_name:
		dvc_parse_test_report(fname)
if __name__ == '__main__':
	if 2 == len(sys.argv):
		fname = sys.argv[1]
	else:
		fname = './tool/tmp/test_report.xls'
	dvc_parse_test_report(fname)

