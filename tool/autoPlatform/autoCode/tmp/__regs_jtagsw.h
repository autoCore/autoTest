/*
 * Copyright (C) 2016 ASR MICROELECTRONICS Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 *************************************************
 * Automatically generated C header: do not edit *
 *************************************************
 */

#ifndef __ASR_CHIP_REGS_H__
#error  "Don't include this file directly, Pls include asr_chip_regs.h"
#endif


#ifndef __H_REGS_JTAGSW_HEADFILE_H__
#define __H_REGS_JTAGSW_HEADFILE_H__ __FILE__

#define	REGS_JTAGSW

/* registers definitions for JTAGSW */
#define REG_JTAGSW_JTAGSW_EN                              ASR_ADDR(REGS_JTAGSW_BASE, 0X0)/*Enable Software JTAG Register*/
#define REG_JTAGSW_JTAGSW_CTRL                            ASR_ADDR(REGS_JTAGSW_BASE, 0X4)/*Software JTAG Control Register*/
#define REG_JTAGSW_JTAGSW_DATA                            ASR_ADDR(REGS_JTAGSW_BASE, 0X8)/*Software JTAG Serial Data Register*/
#define REG_JTAGSW_JTAGSW_READ_BOOTROM_BRANCH2SRAM        ASR_ADDR(REGS_JTAGSW_BASE, 0XC)/*Software JTAG Read Access to bootrom_branch2sram*/



/* bits definitions for register REG_JTAGSW_JTAGSW_EN */
#define BIT_EN_MUX_JTG_SOFT                               ( BIT(0) )

/* bits definitions for register REG_JTAGSW_JTAGSW_CTRL */
#define BIT_JTAG_SOFT_OUT_TCK                             ( BIT(3) )
#define BIT_JTAG_SOFT_OUT_TMS                             ( BIT(2) )
#define BIT_JTAG_SOFT_OUT_TRST                            ( BIT(1) )
#define BIT_JTAG_SOFT_OUT_TDI                             ( BIT(0) )

/* bits definitions for register REG_JTAGSW_JTAGSW_DATA */
#define BIT_JTAG_SOFT_PREAD_DATA34                        ( BIT(0) )

/* bits definitions for register REG_JTAGSW_JTAGSW_READ_BOOTROM_BRANCH2SRAM */
#define BIT_JTAG_SOFT_PREAD_DATA_GPS                      ( BIT(1) )
#define BIT_JTAG_SOFT_PREAD_DATA44                        ( BIT(0) )

#endif
