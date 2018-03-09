#!/usr/bin/env python
# -*-encoding: utf-8 -*-

import os,wx,sys,time,datetime
import subprocess
import threading,thread
import argparse
import pexpect

sys.path.append("./tool/autoPlatform/autoTest/bin")
# from autoTest_main import do_autotest

sys.path.append("./tool/autoPlatform/autobuild")
from autobuild import do_autoBuild

reload(sys)
sys.setdefaultencoding('utf-8')

class PrintRes(threading.Thread):
	"""docstring for ClassName"""
	def __init__(self,autoframe):
		super(PrintRes, self).__init__()
		self.autoframe = autoframe
		self.log = autoframe.contents

	def run(self):
		while 1:
			while not self.autoframe.p:
				pass
			while self.autoframe.p.poll() is None:
				line = self.autoframe.p.stdout.readline()
				if line: print line

class RedirectText(object):
	def __init__(self,aWxTextCtrl):
		self.out = aWxTextCtrl

	def write(self, string):
		wx.CallAfter(self.out.WriteText, string)
	def flush(self):
		pass

class autoframe(wx.Frame):
	def __init__(self,leight,high):
		wx.Frame.__init__(self, None, -1, title="autoPlatform", size=(leight,high))
		bkg = wx.Panel(self,-1)
		self.filename = wx.TextCtrl(bkg,-1)
		# self.contents = wx.TextCtrl(bkg,style=wx.TE_MULTILINE | wx.HSCROLL | wx.TE_READONLY | wx.TE_LINEWRAP)
		self.contents = wx.TextCtrl(bkg,style=wx.TE_MULTILINE | wx.TE_READONLY | wx.TE_LINEWRAP)
		self.project_name = wx.StaticText(bkg, -1, "project name:")

		self.show_module = wx.TextCtrl(bkg,-1)
		self.module_name = wx.StaticText(bkg, -1, "module name:")

		self.contents.SetInsertionPoint(0)

		build_btn = wx.Button(bkg,label='autobuild')
		build_btn.Bind(wx.EVT_BUTTON,self.__build)

		autotest_btn = wx.Button(bkg,label='autotest')
		autotest_btn.Bind(wx.EVT_BUTTON,self.__autotest)

		clear_btn = wx.Button(bkg,label='clear')
		clear_btn.Bind(wx.EVT_BUTTON,self.__clear)
		save_btn = wx.Button(bkg,label='save')
		save_btn.Bind(wx.EVT_BUTTON,self.__save)

		self.gauge = wx.Gauge(bkg, -1, pos=wx.DefaultPosition,size=wx.DefaultSize, style=wx.GA_HORIZONTAL,validator=wx.DefaultValidator)
		self.gauge.SetBezelFace(3)
		self.gauge.SetShadowWidth(3)
		# wx.Gauge(bkg, -1, 100,(100,60), pos=wx.DefaultPosition,
		# size=wx.DefaultSize, style=wx.GA_HORIZONTAL,
		# validator=wx.DefaultValidator, name="gauge")

		hbox = wx.BoxSizer(wx.HORIZONTAL)
		hbox.Add(self.project_name,proportion=0,flag=wx.LEFT,border=5)
		hbox.Add(self.filename,proportion=1,flag=wx.EXPAND)
		hbox.Add(self.module_name,proportion=0,flag=wx.LEFT,border=5)
		hbox.Add(self.show_module,proportion=1,flag=wx.EXPAND)

		hbox.Add(build_btn,proportion=0,flag=wx.LEFT,border=5)
		# hbox.Add(autotest_btn,proportion=0,flag=wx.LEFT,border=5)
		hbox.Add(save_btn,proportion=0,flag=wx.LEFT,border=5)
		hbox.Add(clear_btn,proportion=0,flag=wx.LEFT,border=5)


		# radioJtag = wx.RadioButton(bkg, -1, 'Jtag', pos=(80, 162))
		# radioUSB = wx.RadioButton(bkg, -1, 'USB', pos=(80, 162))
		self.radioDownload = wx.RadioBox(bkg, -1, 'download', choices=['USB','Jtag'],pos=wx.DefaultPosition,style=wx.RA_SPECIFY_ROWS)
		self.radioLog = wx.RadioBox(bkg, -1, 'log', choices=['Uart_log','Jtag_log'],pos=wx.DefaultPosition,style=wx.RA_SPECIFY_ROWS)
		# checkBox_j = wx.CheckBox(bkg, -1, 'Jtag_log')
		# checkBox_u = wx.CheckBox(bkg, -1, 'Uart_log')
		# choice = wx.Choice(bkg, -1, choices = ['Jtag_log','Uart_log'], style=wx.RA_SPECIFY_COLS)

		autotest_hbox = wx.BoxSizer(wx.HORIZONTAL)
		autotest_hbox.Add(autotest_btn,proportion=0,flag=wx.LEFT,border=5)
		# autotest_hbox.Add(radioJtag,proportion=0,flag=wx.LEFT,border=5)
		# autotest_hbox.Add(radioUSB,proportion=0,flag=wx.LEFT,border=5)
		# autotest_hbox.Add(checkBox_j,proportion=0,flag=wx.LEFT,border=5)
		# autotest_hbox.Add(checkBox_u,proportion=0,flag=wx.LEFT,border=5)

		autotest_hbox.Add(self.radioDownload,proportion=2,flag=wx.LEFT,border=5)
		autotest_hbox.Add(self.radioLog,proportion=2,flag=wx.RIGHT,border=5)
		# autotest_hbox.Add(choice,proportion=1,flag=wx.RIGHT,border=5)

		gauge_hbox = wx.BoxSizer(wx.HORIZONTAL)
		gauge_hbox.Add(self.gauge, proportion = 1, flag = wx.ALIGN_CENTRE)

		vbox = wx.BoxSizer(wx.VERTICAL)
		vbox.Add(hbox,proportion=0,flag=wx.EXPAND|wx.ALL,border=5)
		vbox.Add(autotest_hbox,proportion=0,flag=wx.EXPAND|wx.ALL,border=5)
		vbox.Add(self.contents,proportion=1,flag=wx.EXPAND|wx.LEFT|wx.BOTTOM|wx.RIGHT,border=5)
		vbox.Add(gauge_hbox,proportion=0,flag=wx.EXPAND|wx.LEFT|wx.BOTTOM|wx.RIGHT,border=5)

		bkg.SetSizer(vbox)
		self.filename.SetValue(argv.project_name.encode())
		self.show_module.SetValue(argv.module_name.encode())
		self.p = None

		# redirect text here
		redir = RedirectText(self.contents)
		sys.stdout = redir

		self.sudo_password = None

	def __build(self,event):
		def do_autoBuild():
			project_name = self.filename.GetValue().decode("utf-8","ignore")
			module_name = self.show_module.GetValue().decode("utf-8","ignore")
			cmd = ['python','./tool/autoPlatform/autobuild/autobuild.py',project_name]
			if module_name not in  "all_modules":
				cmd.append("-m"+module_name)
			proc = pexpect.spawn(' '.join(cmd),timeout = 6000,maxread=10)
			proc.logfile_read = sys.stdout
			proc.expect(pexpect.EOF)
			proc.close(force=True)
			proc = None
		thread.start_new_thread (do_autoBuild,())

	def __save(self,event):
		now = datetime.datetime.today()
		date = now.strftime("%d_%h_%H-%M-%S")
		fname = './tool/tmp/~build_res_%s.log'%date
		file = open(fname,'w')
		file.write(self.contents.GetValue().decode("utf-8","ignore"))
		file.close()

	def __autotest(self,event):
		project_name = self.filename.GetValue().decode("utf-8","ignore")
		cmd = ['python','./tool/autoPlatform/autoTest/bin/autoTest_main.py',project_name,"-b"]

		if self.radioDownload.GetStringSelection() == 'Jtag':
			cmd.append('-j')
		if self.radioLog.GetStringSelection() == 'Jtag_log':
			pass
		msgDialog  = wx.MessageDialog(None, 'reset your board,if reset click Yes or click No', 'warning', wx.YES_NO | wx.ICON_QUESTION)
		if msgDialog.ShowModal() == wx.ID_YES:
			pass
		else:
			return 0
		dialog = wx.TextEntryDialog(None, "Plaese input your suod password:",'Text Entry',style=wx.OK|wx.TE_PASSWORD)
		if not self.sudo_password and dialog.ShowModal() == wx.ID_OK:
			self.sudo_password = dialog.GetValue().decode("utf-8","ignore")
		def do_autotest():
			proc = pexpect.spawn(' '.join(cmd),timeout = 36000,maxread=10)
			proc.logfile_read = sys.stdout
			while 1:
				index = proc.expect([r"\[sudo\] password|input sudo password",pexpect.EOF,pexpect.TIMEOUT],timeout = 36000)
				if index == 0:
					proc.sendline(self.sudo_password) if self.sudo_password else None
				if index == 1:
					proc.close(force=True)
					break
				if index == 2:
					print "ERROR: proc timeout"
					proc.close(force=True)
					break
			proc = None
		thread.start_new_thread(do_autotest, ())
	def __clear(self,event):
		self.contents.Clear()


if __name__ == '__main__':
	arg_parser = argparse.ArgumentParser()
	arg_parser.add_argument('project_name',choices = ["aquila_evb","aquila_fpga","aquilac_evb","aquilac_fpga"],help = 'input project name ')
	arg_parser.add_argument('-m','--module_name',default = 'all_modules',help = 'if you test single module, input module name')
	argv = arg_parser.parse_args()
	try:
		app = wx.App()
		frm = autoframe(700,900)

		# print_res = PrintRes(frm)
		# print_res.start()

		frm.Show()
		app.MainLoop()
		wx.GetApp().ExitMainLoop()
	except Exception,e:
		print e
		wx.GetApp().ExitMainLoop()

