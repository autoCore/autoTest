#!/usr/bin/python
from pyExcelerator import *
from xlrd import *
from xlutils.copy import *
import datetime

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


ddr_fc = {'0':'312','1':'400','2':'533','3':'600','4':'800','5':'1200','6':'1600','7':'2400'}
core_fc = {'0':{'0':'624','1':'832','2':'1248','3':'1600'},'1':{'0':'624','1':'832','2':'1248','3':'2100'}}
def vmin_report(vmin_list, fname):
	workbook = open_workbook(fname,formatting_info = True)
	append_data = copy(workbook)
	sheet_name = 'Vmin'
	nu = 0
	while sheet_name in workbook.sheet_names():
		nu = nu + 1
		sheet_name =sheet_name[:4] + str(nu)
	else:
		print 'add sheet:',sheet_name
	append_data.add_sheet(sheet_name)
	worksheet = append_data.get_sheet(-1)
	worksheet.write(0,0,'clock:')
	worksheet.write(0,1,'vmin:')
	for i, case in enumerate(vmin_list):
		if "ddr_vmin" in case.test_cmd_list[0]:
			cmd,vol,level = case.test_cmd_list[0].split()
			worksheet.write(i+1,0,ddr_fc[level])
			worksheet.write(i+1,1,vol)
		elif "core_vmin" in case.test_cmd_list[0]:
			cmd,vol,level,clst = case.test_cmd_list[0].split()
			worksheet.write(i+1,0,core_fc[clst][level]+'/'+clst)
			worksheet.write(i+1,1,vol)
	append_data.save(fname)


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
	if 'vmin' == module_name:
		dvc_parse_test_report(fname)
if __name__ == '__main__':
	if 2 == len(sys.argv):
		fname = sys.argv[1]
	else:
		fname = './tool/tmp/test_report.xls'
	dvc_parse_test_report(fname)

