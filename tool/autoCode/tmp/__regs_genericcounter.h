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


#ifndef __H_REGS_G_COUNTERG_COUNTER_RO_HEADFILE_H__
#define __H_REGS_G_COUNTERG_COUNTER_RO_HEADFILE_H__ __FILE__

#define	REGS_G_COUNTER,G_COUNTER_RO

/* registers definitions for G_COUNTERG_COUNTER_RO */
#define REG_G_COUNTER_CNTCR                               ASR_ADDR(REGS_G_COUNTER_BASE, 0X0)/*Counter Control Register,*/
#define REG_G_COUNTER_RO_CNTCR                            ASR_ADDR(REGS_G_COUNTER_RO_BASE, 0X0)/*Counter Control Register,*/
#define REG_G_COUNTER_CNTSR                               ASR_ADDR(REGS_G_COUNTER_BASE, 0X04)/*Counter Status Register,*/
#define REG_G_COUNTER_RO_CNTSR                            ASR_ADDR(REGS_G_COUNTER_RO_BASE, 0X04)/*Counter Status Register,*/
#define REG_G_COUNTER_CNTCVLW                             ASR_ADDR(REGS_G_COUNTER_BASE, 0X08)/*Current value of counter[31:0]*/
#define REG_G_COUNTER_RO_CNTCVLW                          ASR_ADDR(REGS_G_COUNTER_RO_BASE, 0X08)/*Current value of counter[31:0]*/
#define REG_G_COUNTER_CNTCVUP                             ASR_ADDR(REGS_G_COUNTER_BASE, 0X0C)/*Current value of counter[63:32]*/
#define REG_G_COUNTER_RO_CNTCVUP                          ASR_ADDR(REGS_G_COUNTER_RO_BASE, 0X0C)/*Current value of counter[63:32]*/
#define REG_G_COUNTER_CNTFID0                             ASR_ADDR(REGS_G_COUNTER_BASE, 0X20)/*Base frequency ID*/
#define REG_G_COUNTER_RO_CNTFID0                          ASR_ADDR(REGS_G_COUNTER_RO_BASE, 0X20)/*Base frequency ID*/



/* bits definitions for register REG_G_COUNTER_RO_CNTCR */
#define BIT_HDBG14                                        ( BIT(1) )
#define BIT_EN                                            ( BIT(0) )

/* bits definitions for register REG_G_COUNTER_RO_CNTSR */
#define BIT_HDBG24                                        ( BIT(1) )

/* bits definitions for register REG_G_COUNTER_RO_CNTCVLW */
#define BITS_CNTCVLW(_X_)                                 (_X_)

/* bits definitions for register REG_G_COUNTER_RO_CNTCVUP */
#define BITS_CNTCVUP(_X_)                                 (_X_)

/* bits definitions for register REG_G_COUNTER_RO_CNTFID0 */
#define BITS_FREQ(_X_)                                    (_X_)

#endif
