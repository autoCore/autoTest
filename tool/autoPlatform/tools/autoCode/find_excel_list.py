#!/usr/bin/env python
import os

'find and open all excel file @zhenbo.zhan'

Const_Image_Format = [".xls",".xlsx"]

class FileFilt:
    fileList = [""]
    counter = 0
    def __init__(self):
        pass
    def FindFile(self,dirr,filtrate = 1):
        global Const_Image_Format
        for s in os.listdir(dirr):
            newDir = os.path.join(dirr,s)
            if os.path.isfile(newDir):
                if filtrate:
                        if newDir and(os.path.splitext(newDir)[1] in Const_Image_Format):
                            self.fileList.append(newDir)
                            self.counter+=1
                else:
                    self.fileList.append(newDir)
                    self.counter+=1


if __name__ == '__main__':
	b = FileFilt()
	b.FindFile(dirr = "./excel")
	print "total excel file: " + str(b.counter)
	for k in b.fileList:
		file_list ='"'+k +'"'
		if (file_list != '""'):
			os.system(r'python main.py ' + file_list)

