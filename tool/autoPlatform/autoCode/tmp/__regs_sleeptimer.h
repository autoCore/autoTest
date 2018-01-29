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


#ifndef __H_REGS_SLEEPTIMER_TDSLEEPTIMER_LTE_HEADFILE_H__
#define __H_REGS_SLEEPTIMER_TDSLEEPTIMER_LTE_HEADFILE_H__ __FILE__

#define	REGS_SLEEPTIMER_TD,SLEEPTIMER_LTE

/* registers definitions for SLEEPTIMER_TDSLEEPTIMER_LTE */
#define REG_SLEEPTIMER_TD_SCTR                            ASR_ADDR(REGS_SLEEPTIMER_TD_BASE, 0X0000)/*Sleep Timer Slow Clock count_to Register*/
#define REG_SLEEPTIMER_LTE_SCTR                           ASR_ADDR(REGS_SLEEPTIMER_LTE_BASE, 0X0000)/*Sleep Timer Slow Clock count_to Register*/
#define REG_SLEEPTIMER_TD_FCTR                            ASR_ADDR(REGS_SLEEPTIMER_TD_BASE, 0X0004)/*Sleep Timer Fast Clock count_to Register*/
#define REG_SLEEPTIMER_LTE_FCTR                           ASR_ADDR(REGS_SLEEPTIMER_LTE_BASE, 0X0004)/*Sleep Timer Fast Clock count_to Register*/
#define REG_SLEEPTIMER_TD_VSTR                            ASR_ADDR(REGS_SLEEPTIMER_TD_BASE, 0X0008)/*VCXO Stable Time Register*/
#define REG_SLEEPTIMER_LTE_VSTR                           ASR_ADDR(REGS_SLEEPTIMER_LTE_BASE, 0X0008)/*VCXO Stable Time Register*/
#define REG_SLEEPTIMER_TD_PSTR                            ASR_ADDR(REGS_SLEEPTIMER_TD_BASE, 0X000C)/*PLL Stable Time Register*/
#define REG_SLEEPTIMER_LTE_PSTR                           ASR_ADDR(REGS_SLEEPTIMER_LTE_BASE, 0X000C)/*PLL Stable Time Register*/
#define REG_SLEEPTIMER_TD_ESLR                            ASR_ADDR(REGS_SLEEPTIMER_TD_BASE, 0X0010)/*Endless Sleep Mode Register */
#define REG_SLEEPTIMER_LTE_ESLR                           ASR_ADDR(REGS_SLEEPTIMER_LTE_BASE, 0X0010)/*Endless Sleep Mode Register */
#define REG_SLEEPTIMER_TD_VSCR                            ASR_ADDR(REGS_SLEEPTIMER_TD_BASE, 0X0014)/*VCTCXO Sleep Control Register*/
#define REG_SLEEPTIMER_LTE_VSCR                           ASR_ADDR(REGS_SLEEPTIMER_LTE_BASE, 0X0014)/*VCTCXO Sleep Control Register*/
#define REG_SLEEPTIMER_TD_SLCR                            ASR_ADDR(REGS_SLEEPTIMER_TD_BASE, 0X0018)/*Slow Counter Value Register*/
#define REG_SLEEPTIMER_LTE_SLCR                           ASR_ADDR(REGS_SLEEPTIMER_LTE_BASE, 0X0018)/*Slow Counter Value Register*/



/* bits definitions for register REG_SLEEPTIMER_LTE_SCTR */
#define BITS_SL_SLOW_COUNT_TO(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )

/* bits definitions for register REG_SLEEPTIMER_LTE_FCTR */
#define BITS_SL_FAST_COUNT_TO(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )

/* bits definitions for register REG_SLEEPTIMER_LTE_VSTR */
#define BITS_SL_VCXO_ST_TIME38(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SLEEPTIMER_LTE_PSTR */
#define BITS_SL_VCXO_ST_TIME46(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SLEEPTIMER_LTE_ESLR */
#define BIT_ENDLESS_SLEEP                                 ( BIT(0) )

/* bits definitions for register REG_SLEEPTIMER_LTE_VSCR */
#define BIT_DROWSY_EN                                     ( BIT(1) )
#define BIT_RTU_SLP_EN                                    ( BIT(0) )

/* bits definitions for register REG_SLEEPTIMER_LTE_SLCR */
#define BITS_SL_SLOW_COUNTER(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )

#endif
