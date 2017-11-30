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


#ifndef __H_REGS_ONEW_HEADFILE_H__
#define __H_REGS_ONEW_HEADFILE_H__ __FILE__

#define	REGS_ONEW

/* registers definitions for ONEW */
#define REG_ONEW_ONEW_W1CMDR                              ASR_ADDR(REGS_ONEW_BASE, 0X00)/*One-Wire Command Register*/
#define REG_ONEW_ONEW_W1TRR                               ASR_ADDR(REGS_ONEW_BASE, 0X04)/*One-Wire Transmit/Receive Buffer*/
#define REG_ONEW_ONEW_W1INTR                              ASR_ADDR(REGS_ONEW_BASE, 0X08)/*One-Wire Interrupt Register*/
#define REG_ONEW_ONEW_W1IER                               ASR_ADDR(REGS_ONEW_BASE, 0X0C)/*One-Wire Interrupt Enable Register*/
#define REG_ONEW_ONEW_W1CDR                               ASR_ADDR(REGS_ONEW_BASE, 0X10)/*One-Wire Clock Divisor Register*/



/* bits definitions for register REG_ONEW_ONEW_W1CMDR */
#define BIT_DQI                                           ( BIT(3) )
#define BIT_DQO28                                         ( BIT(2) )
#define BIT_DQO29                                         ( BIT(2) )
#define BIT_SRA                                           ( BIT(1) )
#define BIT_1WR31                                         ( BIT(0) )
#define BIT_1WR32                                         ( BIT(0) )

/* bits definitions for register REG_ONEW_ONEW_W1TRR */
#define BITS_ONE_DATA42(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_ONEW_ONEW_W1INTR */
#define BIT_RSRF                                          ( BIT(5) )
#define BIT_RBF                                           ( BIT(4) )
#define BIT_ONE_TEMT55                                    ( BIT(3) )
#define BIT_TBE                                           ( BIT(2) )
#define BIT_PDR                                           ( BIT(1) )
#define BIT_PD                                            ( BIT(0) )

/* bits definitions for register REG_ONEW_ONEW_W1IER */
#define BIT_DQOE                                          ( BIT(7) )
#define BIT_ERSF                                          ( BIT(5) )
#define BIT_ERBF                                          ( BIT(4) )
#define BIT_ETMT                                          ( BIT(3) )
#define BIT_ETBE                                          ( BIT(2) )
#define BIT_IAS                                           ( BIT(1) )
#define BIT_EPD                                           ( BIT(0) )

/* bits definitions for register REG_ONEW_ONEW_W1CDR */
#define BITS_DIV(_X_)                                     ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)) )
#define BITS_PRE(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)) )

#endif
