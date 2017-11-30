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


#ifndef __H_REGS_MIRQASP_HEADFILE_H__
#define __H_REGS_MIRQASP_HEADFILE_H__ __FILE__

#define	REGS_MIRQASP

/* registers definitions for MIRQASP */
#define REG_MIRQASP_MIRQ_INT_CLRnn                        ASR_ADDR(REGS_MIRQASP_BASE, 0X0000)/*MIRQ Interrupt Clear n Register*/
#define REG_MIRQASP_MIRQ_EDGE_LEVEL_LO24                  ASR_ADDR(REGS_MIRQASP_BASE, 0X00F8)/*MIRQ Low-24 Interrupt Sensitivity Register*/
#define REG_MIRQASP_MIRQ_EDGE_LEVEL_HI24                  ASR_ADDR(REGS_MIRQASP_BASE, 0X00FC)/*MIRQ Hi-24 Interrupt Sensitivity Register*/



/* bits definitions for register REG_MIRQASP_MIRQ_INT_CLRnn */
#define BIT_MIRQ_INT_CLR                                  ( BIT(0) )

/* bits definitions for register REG_MIRQASP_MIRQ_EDGE_LEVEL_LO24 */
#define BITS_MIRQ_EDGE_LEVEL_LO24(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )

/* bits definitions for register REG_MIRQASP_MIRQ_EDGE_LEVEL_HI24 */
#define BITS_MIRQ_EDGE_LEVEL_HI24(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )

#endif
