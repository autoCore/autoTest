#! /usr/bin/env python

class Rule:
	def action(self,block,handler):
		handler.do(self.type)
		return True

class BaseRule(Rule):
	type = 'capbase'
	def condition(self,block):
		for row in block:
			try: row[0] + ''
			except: continue
			if 'BASE:' in row[0].upper() or 'BASE :' in row[0].upper():
				return True
		return False

	def action(self,block,handler,register,regfield):
		handler.do(self.type,block,register,regfield)
		return True


class RegisterRule(Rule):
	type = 'capregister'
	def condition(self,block):
		for row in block:
			try: row[0] + ''
			except: continue
			if 'Offset:' in row[0]:
				return True
		return False

	def action(self,block,handler,register,regfield):
		handler.do(self.type,block,register,regfield)
		return False


class RegfieldRule(Rule):
	type = 'capregfield'
	def condition(self,block):
		if "Bits" in block[0][0] and 'Field (Code)' in block[0][2]:
			return True
		return False

	def action(self,block,handler,register,regfield):
		for i, line in enumerate(block):
			if "Bits" in line[0] and 'Field (Code)' in line[2]:
				keys = [_str.strip() for _str in line]
				break
		# print keys
		for line in block[i+1:]:
			handler.do(self.type,block,register,regfield)
			return False







