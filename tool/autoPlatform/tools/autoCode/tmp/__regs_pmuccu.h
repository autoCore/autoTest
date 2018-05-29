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


#ifndef __H_REGS_CCU_HEADFILE_H__
#define __H_REGS_CCU_HEADFILE_H__ __FILE__

#define	REGS_CCU

/* registers definitions for CCU */
#define REG_CCU_CCCR                                      ASR_ADDR(REGS_CCU_BASE, 0X0000)/*Communication Subsystem Clock Configuration Register*/
#define REG_CCU_CCSR                                      ASR_ADDR(REGS_CCU_BASE, 0X0004)/*Communication Subsystem Clock Status Register (not used any longer)*/
#define REG_CCU_GCCCR                                     ASR_ADDR(REGS_CCU_BASE, 0X0008)/*Grayback Core Clock Control Register (not used any longer)*/
#define REG_CCU_MPCR                                      ASR_ADDR(REGS_CCU_BASE, 0X0100)/*Communication Subsystem Power Control Register*/
#define REG_CCU_CMCR                                      ASR_ADDR(REGS_CCU_BASE, 0X0114)/*Communication Subsystem Miscellaneous Counters Register */
#define REG_CCU_MPSR                                      ASR_ADDR(REGS_CCU_BASE, 0X0118)/*Communication Subsystem Power Status Register*/
#define REG_CCU_CWER                                      ASR_ADDR(REGS_CCU_BASE, 0X0120)/*Communication Subsystem general purpose wakeup enable*/
#define REG_CCU_Cwesr_wakeup_en                           ASR_ADDR(REGS_CCU_BASE, 0X0128)/*Communication Subsystem general wakeup global enable*/
#define REG_CCU_CIER                                      ASR_ADDR(REGS_CCU_BASE, 0X0130)/*Communication Subsystem Interrupt Enable Register*/
#define REG_CCU_CGDES                                     ASR_ADDR(REGS_CCU_BASE, 0X0140)/*MSA Deep Sleep Entry Status Register*/
#define REG_CCU_CSSR                                      ASR_ADDR(REGS_CCU_BASE, 0X0200)/*Communication Subsystem Spare Register*/



/* bits definitions for register REG_CCU_CCCR */
#define BIT_L2CF                                          ( BIT(16) )
#define BITS_CSCD(_X_)                                    ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CCU_CCSR */
#define BITS_CSCD_S(_X_)                                  ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CCU_GCCCR */
#define BIT_F                                             ( BIT(0) )

/* bits definitions for register REG_CCU_MPCR */
#define BIT_LMP_REQ50                                     ( BIT(24) )
#define BIT_LMP_REQ51                                     ( BIT(23) )
#define BIT_WMP_REQ                                       ( BIT(22) )
#define BITS_PM(_X_)                                      ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_CCU_CMCR */

/* bits definitions for register REG_CCU_MPSR */
#define BITS_CC_SWR70(_X_)                                ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_TMS                                           ( BIT(7) )
#define BIT_LMS                                           ( BIT(6) )
#define BIT_WMS                                           ( BIT(5) )
#define BIT_LPM                                           ( BIT(1) )

/* bits definitions for register REG_CCU_CWER */
#define BITS_CC_85(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )

/* bits definitions for register REG_CCU_Cwesr_wakeup_en */
#define BIT_CC_93                                         ( BIT(31) )
#define BIT_WAKEUP_EN                                     ( BIT(30) )

/* bits definitions for register REG_CCU_CIER */
#define BIT_FC_IE                                         ( BIT(0) )

/* bits definitions for register REG_CCU_CGDES */
#define BITS_GDES(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_CCU_CSSR */

#endif
