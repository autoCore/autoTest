'This is dict for auto create file. @zhenbo.zhan'

#!/usr/bin/env python

'define dict for this program'

dict = { \
	'define':'#define ', \
	'file_name_begin':'__regs_', \
	'file_name_end':'.h', \
	'header_macro_begin1':'#ifndef __H_', \
	'header_macro_end1':'_HEADFILE_H__', \
	'header_macro_begin2':'#define __H_', \
	'header_macro_end2':'_HEADFILE_H__ __FILE__', \
	'end_macro':'#endif', \
	'registers_define_comment_string_begin':'/* registers definitions for ', \
	'registers_define_comment_string_end':' */', \
	'registers_addr_begin':'ASR_ADDR(REGS_',\
	'registers_addr_middle':'_BASE, ',\
	'registers_addr_end':')',\
	'reg_begin':'REG_', \
	'bit_begin':'BIT_', \
	'bits_begin':'BITS_', \
	'adie_reg_begin':'REG_', \
	'adie_bit_begin':'BIT_ANA_', \
	'adie_bits_begin':'BITS_ANA_', \
	'bits_define_comment_string_begin':'/* bits definitions for register ', \
	'bits_define_comment_string_end':' */\n', \
	'0':'BIT(0)', \
	'1':'BIT(1)', \
	'2':'BIT(2)', \
	'3':'BIT(3)', \
	'4':'BIT(4)', \
	'5':'BIT(5)', \
	'6':'BIT(6)', \
	'7':'BIT(7)', \
	'8':'BIT(8)', \
	'9':'BIT(9)', \
	'10':'BIT(10)', \
	'11':'BIT(11)', \
	'12':'BIT(12)', \
	'13':'BIT(13)', \
	'14':'BIT(14)', \
	'15':'BIT(15)', \
	'16':'BIT(16)', \
	'17':'BIT(17)', \
	'18':'BIT(18)', \
	'19':'BIT(19)', \
	'20':'BIT(20)', \
	'21':'BIT(21)', \
	'22':'BIT(22)', \
	'23':'BIT(23)', \
	'24':'BIT(24)', \
	'25':'BIT(25)', \
	'26':'BIT(26)', \
	'27':'BIT(27)', \
	'28':'BIT(28)', \
	'29':'BIT(29)', \
	'30':'BIT(30)', \
	'31':'BIT(31)', \
	'32':'BIT(32)', \
	'33':'BIT(33)', \
	'34':'BIT(34)', \
	'35':'BIT(35)', \
	'36':'BIT(36)', \
	'37':'BIT(37)', \
	'38':'BIT(38)', \
	'39':'BIT(39)', \
	'irq':'INT_', \
	}
def return_dict(key):
	return dict[key]

