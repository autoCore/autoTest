#! /usr/bin/env python
# encoding:utf-8

import wx,sys,os
import time

import struct
import ctypes
from nvram_util import *
import copy


class autoframe(wx.Frame):
	def __init__(self,leight,high):
		wx.Frame.__init__(self, None, -1, title="NVRAM TOOL", size=(leight,high))
		self.file_name = None
		self.UI_init()

	def UI_init(self):
		self.bkg = wx.Panel(self,-1)
		hbox0 = wx.BoxSizer(wx.HORIZONTAL)
		hbox1 = wx.BoxSizer(wx.HORIZONTAL)
		vbox = wx.BoxSizer(wx.VERTICAL)
		self.menuBar = wx.MenuBar()

		fileMenu = wx.Menu()
		newItem = wx.MenuItem(fileMenu, id = wx.ID_NEW, text = 'New', kind = wx.ITEM_NORMAL)
		fileMenu.Append(newItem)

		fileMenu.AppendSeparator()

		fileOpenItem = wx.MenuItem(fileMenu, id = wx.ID_OPEN, text = 'Open', kind = wx.ITEM_NORMAL)
		fileMenu.Append(fileOpenItem)


		quit = wx.MenuItem(fileMenu, id = wx.ID_EXIT, text = "Quit\tCtrl+Q", kind = wx.ITEM_NORMAL)
		fileMenu.Append(quit)

		self.menuBar.Append(fileMenu, title = 'File')
		self.SetMenuBar(self.menuBar)

		self.Bind(wx.EVT_MENU, self.menuHandler)


		self.parse_btn = wx.Button(self.bkg,label='Parse')
		self.parse_btn.Bind(wx.EVT_BUTTON,self.__parse)

		StaticText = wx.StaticText(self.bkg, -1, "iMagic:")

		hbox0.Add(self.parse_btn,proportion=0,flag=wx.LEFT,border=5)
		hbox1.Add(StaticText,proportion=0,flag=wx.LEFT,border=5)
		vbox.Add(hbox0,flag=wx.LEFT|wx.RIGHT|wx.TOP,border=10)
		vbox.Add(hbox1,flag=wx.LEFT|wx.RIGHT|wx.TOP,border=10)
		self.bkg.SetSizer(vbox)

	def __showHeaderInfo(self):
		hbox = wx.BoxSizer()
		vbox = wx.BoxSizer(wx.VERTICAL)
		StaticText = wx.StaticText(self.bkg, -1, "iMagic:")
		hbox.Add(self.parse_btn,proportion=0,flag=wx.LEFT,border=5)
		hbox.Add(StaticText,proportion=0,flag=wx.RIGHT,border=5)
		vbox.Add(hbox,proportion=0,flag=wx.EXPAND|wx.ALL,border=5)
		self.bkg.SetSizer(vbox)

	def menuHandler(self, event):
		id = event.GetId()
		if id == wx.ID_NEW:
			print "NEW"
		if id == wx.ID_EXIT:
			sys.exit(0)
		if id == wx.ID_OPEN:
			filesFilter = "All files (*.*)|*.*"
			fileDialog = wx.FileDialog(self, message ="选择单个文件", wildcard = filesFilter, style = wx.FD_OPEN)

			if fileDialog.ShowModal() == wx.ID_OK:
				self.file_name = fileDialog.GetPaths()[0]
			fileDialog.Destroy()
			# print self.file_name

	def __parse(self,event):
		if self.file_name:
			file_bin = open(self.file_name,'rb')
		else:
			print "Pls select a file"
			return
		nvram = NvramGlobalVal()
		nvram.GetHeaderInfo(file_bin)
		nvram.GetNodeInfo(file_bin)
		nvram.GetRecordInfo(file_bin)
		# self.__showHeaderInfo()
		for item in nvram.__dict__.items():
			if item[0] in ['struct','Record','Node']:
				continue
			if item[0] in 'szServed':
				print item[0],':',
				print ' '.join([hex(ord(_str)) for _str in item[1]])
				continue
			print item[0],':',hex(item[1])
		print "****************"
		for i in range(2):
			print "<<<<<<<<<iNDCount:%i>>>>>>>>>>"%i
			for item in nvram.Node[i].__dict__.items():
				if item[0] in 'struct':
					continue
				if item[0] in 'pData':
					print item[0],':',
					print ' '.join([hex(ord(_str)) for _str in item[1]])
					continue
				print item[0],':',hex(item[1])

		print "****************"
		# for i in range(nvram.iRCount):
		for i in range(2):
			print "<<<<<<<<<iRCount:%i>>>>>>>>>>"%i
			for item in nvram.Record[i].__dict__.items():
				if item[0] in 'struct':
					continue
				if item[0] in 'pData':
					print item[0],':',
					print ' '.join([hex(ord(_str)) for _str in item[1]])
					continue
				print item[0],':',hex(item[1])

	def __load(self,event):
		file = open(self.filename.GetValue())
		self.contents.SetValue(file.read())
		file.close()

	def __append(self,event):
		for i in range(10):
			self.contents.AppendText('append text\n')
			time.sleep(1)

	def __save(self,event):
		file = open(self.filename.GetValue(),'w')
		file.write(self.contents.GetValue())
		file.close()

	def __clear(self,event):
		self.contents.Clear()

def gui_main():
	app = wx.App()
	frm = autoframe(1200,800)
	frm.Show()

	app.MainLoop()
