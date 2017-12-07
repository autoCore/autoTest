#!/usr/bin/python

#coding=gbk
import datetime
import subprocess
import codecs
import reportlab.pdfbase.ttfonts
reportlab.pdfbase.pdfmetrics.registerFont(reportlab.pdfbase.ttfonts.TTFont('song', '/usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-B.ttf'))
import reportlab.lib.fonts

from reportlab.pdfgen import canvas
from reportlab.lib.units import inch


x = 'x'
y = 'y'
HeadText_pos = {x:3.5*inch,y:11.3*inch}
DateText_pos = {x:0.7*inch,y:11.22*inch}

# TileBar_pos = [{x:0.7*inch,y:11*inch},{x:1.8*inch,y:11*inch},{x:4.1*inch,y:11*inch},{x:5.2*inch,y:11*inch}]
# TileBar_pos = [{x:0.7*inch,y:11*inch},{x:3*inch,y:11*inch},{x:5.5*inch,y:11*inch}]
TileBar_pos = [{x:0.7*inch,y:11*inch},{x:1*inch,y:11*inch},{x:3*inch,y:11*inch},{x:5.5*inch,y:11*inch}]

lineH1_pos = [{x:0.7*inch,y:11.2*inch},{x:7.6*inch, y:11.2*inch}]
lineV1_pos = [{x:0.5*inch,y:11.5*inch},{x:0.5*inch,y:0.5*inch}]
lineV2_pos = [{x:7.8*inch,y:11.5*inch},{x:7.8*inch,y:0.5*inch}]

PageNum_pos = {x:4*inch,y:0.5*inch}

def create_report_page(c_obj,headText,titleBar,page_num):
	if 1 == page_num:
		now = datetime.datetime.today()
		date = now.strftime("%h %d %Y %H:%M:%S")

		c_obj.setFont('song',12)
		c_obj.drawString(HeadText_pos[x],HeadText_pos[y],headText)
		c_obj.setFont('song',7)
		c_obj.drawString(DateText_pos[x],DateText_pos[y],date)

	c_obj.line(lineH1_pos[0][x],lineH1_pos[0][y],lineH1_pos[1][x],lineH1_pos[1][y])  #row
	c_obj.line(lineV1_pos[0][x],lineV1_pos[0][y],lineV1_pos[1][x],lineV1_pos[1][y])  #col
	c_obj.line(lineV2_pos[0][x],lineV2_pos[0][y],lineV2_pos[1][x],lineV2_pos[1][y])  #col

	c_obj.setFont('song',10)
	for i in range(len(titleBar)):
		c_obj.drawString(TileBar_pos[i][x],TileBar_pos[i][y],titleBar[i])

	c_obj.setFont('song',7)
	c_obj.drawString(PageNum_pos[x],PageNum_pos[y],'Page '+str(page_num))

def report_result(autoTest_object_list, file_name):
	assert autoTest_object_list, 'autoTest_object_list is blank'
	c = canvas.Canvas(file_name)
	headtext = "ASR Ctest report"
	# titleBar = ["Module Name","Command Name","Build Result","Test Result"]
	titleBar = ["ID","Module Name","Command Name","Test Result"]
	create_report_page(c,headtext,titleBar,1)
	count = 68
	page = 1

	c.setFont('song',7)
	for i,autoTest_obj in enumerate(autoTest_object_list):
		if i >= page * count:
			c.showPage()
			page += 1
			create_report_page(c,headtext,titleBar,page)
		obj_ID = autoTest_obj.ID
		module_name = autoTest_obj.module_name
		cmd_name = '@'.join(autoTest_obj.test_cmd_list)
		# build_result = autoTest_obj.build_result
		test_result = '@'.join(autoTest_obj.test_result)
		# report_text = [module_name,cmd_name,build_result,test_result]
		report_text = [str(obj_ID),module_name,cmd_name,test_result]

		line_num = i - (page - 1) * count
		for col_num in range(len(titleBar)):
			c.drawString(TileBar_pos[col_num][x],TileBar_pos[col_num][y] - (0.15*line_num + 0.2)*inch,report_text[col_num])
	c.save()


