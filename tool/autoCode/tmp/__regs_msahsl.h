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


#ifndef __H_REGS_HSL_HEADFILE_H__
#define __H_REGS_HSL_HEADFILE_H__ __FILE__

#define	REGS_HSL

/* registers definitions for HSL */
#define REG_HSL_HSL_LASTDATA                              ASR_ADDR(REGS_HSL_BASE, 0X00)/*Software Message Last Word Register*/
#define REG_HSL_HSL_DATA                                  ASR_ADDR(REGS_HSL_BASE, 0X04)/*Software Message Body Register*/
#define REG_HSL_HSL_HEADER                                ASR_ADDR(REGS_HSL_BASE, 0X08)/*Software Message Header Register*/
#define REG_HSL_HSL_SINGLE                                ASR_ADDR(REGS_HSL_BASE, 0X0C)/*Single Software Message Register*/
#define REG_HSL_HSL_CFG                                   ASR_ADDR(REGS_HSL_BASE, 0X10)/*HSL Configuration Register*/
#define REG_HSL_HSL_SWENABLE0                             ASR_ADDR(REGS_HSL_BASE, 0X20)/*Software Enable 0 Register*/
#define REG_HSL_HSL_SWENABLE1                             ASR_ADDR(REGS_HSL_BASE, 0X24)/*Software Enable 1 Register*/
#define REG_HSL_HSL_SWENABLE2                             ASR_ADDR(REGS_HSL_BASE, 0X28)/*Software Enable 2 Register*/
#define REG_HSL_HSL_SWENABLE3                             ASR_ADDR(REGS_HSL_BASE, 0X2C)/*Software Enable 3 Register*/
#define REG_HSL_HSL_TCUENABLE                             ASR_ADDR(REGS_HSL_BASE, 0X30)/*Timing Control Unit Register*/
#define REG_HSL_HSL_STACK                                 ASR_ADDR(REGS_HSL_BASE, 0X34)/*Nesting Stack Register*/



/* bits definitions for register REG_HSL_HSL_LASTDATA */
#define BITS_LAST_DATA(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_HSL_HSL_DATA */
#define BITS_HS_DATA26(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_HSL_HSL_HEADER */
#define BITS_HEADER(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_HSL_HSL_SINGLE */
#define BITS_SINGLE(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_HSL_HSL_CFG */
#define BIT_DISABLE_NESTING                               ( BIT(5) )
#define BIT_SWLOG_ON                                      ( BIT(4) )
#define BIT_TCULOG_ON                                     ( BIT(3) )
#define BITS_HSL_DIVR(_X_)                                ( (_X_) << 1 & (BIT(1)|BIT(2)) )
#define BIT_HSL_PORT_EN                                   ( BIT(0) )

/* bits definitions for register REG_HSL_HSL_SWENABLE0 */
#define BITS_SW_ENABLE0(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_HSL_HSL_SWENABLE1 */
#define BITS_SW_ENABLE1(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_HSL_HSL_SWENABLE2 */
#define BITS_SW_ENABLE2(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_HSL_HSL_SWENABLE3 */
#define BITS_SW_ENABLE3(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_HSL_HSL_TCUENABLE */
#define BITS_TCU_ENABLE(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_HSL_HSL_STACK */
#define BITS_STACK(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

#endif
