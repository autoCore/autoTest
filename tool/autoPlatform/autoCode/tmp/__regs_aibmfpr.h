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


#ifndef __H_REGS_MFPR_HEADFILE_H__
#define __H_REGS_MFPR_HEADFILE_H__ __FILE__

#define	REGS_MFPR

/* registers definitions for MFPR */
#define REG_MFPR_MFPRx                                    ASR_ADDR(REGS_MFPR_BASE, 0XXXX)/*Multi-Function Pin Control Register x*/



/* bits definitions for register REG_MFPR_MFPRx */
#define BIT_PULL_SEL                                      ( BIT(15) )
#define BIT_PULLUP_EN                                     ( BIT(14) )
#define BIT_PULLDN_EN                                     ( BIT(13) )
#define BITS_DRIVE(_X_)                                   ( (_X_) << 11 & (BIT(11)|BIT(12)) )
#define BIT_SLEEP_SEL0                                    ( BIT(9) )
#define BIT_SLEEP_DATA                                    ( BIT(8) )
#define BIT_SLEEPDIR                                      ( BIT(7) )
#define BIT_EDGE_CLEAR                                    ( BIT(6) )
#define BIT_EDGE_FALL_EN                                  ( BIT(5) )
#define BIT_EDGE_RISE_EN                                  ( BIT(4) )
#define BIT_SLEEPSEL1                                     ( BIT(3) )
#define BITS_AF_SEL(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

#endif
