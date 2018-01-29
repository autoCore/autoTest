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


#ifndef __H_REGS_SLOWCLOCK_HEADFILE_H__
#define __H_REGS_SLOWCLOCK_HEADFILE_H__ __FILE__

#define	REGS_SLOWCLOCK

/* registers definitions for SLOWCLOCK */
#define REG_SLOWCLOCK_STAT_CTRL                           ASR_ADDR(REGS_SLOWCLOCK_BASE, 0X00)/*Status Control Register*/
#define REG_SLOWCLOCK_WAKEUP_REL                          ASR_ADDR(REGS_SLOWCLOCK_BASE, 0X04)/*Wakeup Event Relative Register*/
#define REG_SLOWCLOCK_WAKEUP_ABS                          ASR_ADDR(REGS_SLOWCLOCK_BASE, 0X08)/*Wakeup Event Absolute Register*/
#define REG_SLOWCLOCK_TCU_WAKEUP_REL                      ASR_ADDR(REGS_SLOWCLOCK_BASE, 0X0C)/*Timing Control Unit Wakeup Event Relative Register*/
#define REG_SLOWCLOCK_TCU_WAKEUP_ABS                      ASR_ADDR(REGS_SLOWCLOCK_BASE, 0X10)/*Timing Control Unit Wakeup Event Absolute Register*/
#define REG_SLOWCLOCK_SCNT                                ASR_ADDR(REGS_SLOWCLOCK_BASE, 0X14)/*Slow Clock Count Register*/
#define REG_SLOWCLOCK_SSNAP                               ASR_ADDR(REGS_SLOWCLOCK_BASE, 0X18)/*Snapshot Command Slow Count Register*/
#define REG_SLOWCLOCK_FSNAP                               ASR_ADDR(REGS_SLOWCLOCK_BASE, 0X1C)/*Snapshot Command Offset Register*/
#define REG_SLOWCLOCK_SCNT_INT                            ASR_ADDR(REGS_SLOWCLOCK_BASE, 0X20)/*Slow Clock Interrupt Register*/
#define REG_SLOWCLOCK_SCNT_LOAD                           ASR_ADDR(REGS_SLOWCLOCK_BASE, 0X24)/*Slow Clock Load Register*/
#define REG_SLOWCLOCK_D2_LEFT                             ASR_ADDR(REGS_SLOWCLOCK_BASE, 0X28)/*D2 Time Remaining Register*/
#define REG_SLOWCLOCK_M_GSM_MVT_CTL                       ASR_ADDR(REGS_SLOWCLOCK_BASE, 0X2C)/*M_GSM_MVT_CTL Register*/



/* bits definitions for register REG_SLOWCLOCK_STAT_CTRL */
#define BIT_D2_STAT                                       ( BIT(4) )
#define BIT_EARLY_WAKEUP                                  ( BIT(3) )
#define BIT_ABSOLUTE_RELATIVE_SELECT                      ( BIT(2) )
#define BIT_D2_EN                                         ( BIT(1) )
#define BIT_SCK_SW_RST                                    ( BIT(0) )

/* bits definitions for register REG_SLOWCLOCK_WAKEUP_REL */
#define BITS_WAKEUP_REL(_X_)                              (_X_)

/* bits definitions for register REG_SLOWCLOCK_WAKEUP_ABS */
#define BITS_WAKEUP_ABS(_X_)                              (_X_)

/* bits definitions for register REG_SLOWCLOCK_TCU_WAKEUP_REL */
#define BITS_TCU_WAKEUP_REL(_X_)                          (_X_)

/* bits definitions for register REG_SLOWCLOCK_TCU_WAKEUP_ABS */
#define BITS_TCU_WAKEUP_ABS(_X_)                          (_X_)

/* bits definitions for register REG_SLOWCLOCK_SCNT */
#define BITS_SCNT(_X_)                                    (_X_)

/* bits definitions for register REG_SLOWCLOCK_SSNAP */
#define BITS_SSNAP(_X_)                                   (_X_)

/* bits definitions for register REG_SLOWCLOCK_FSNAP */
#define BITS_FSNAP(_X_)                                   (_X_)

/* bits definitions for register REG_SLOWCLOCK_SCNT_INT */
#define BITS_SCNT_INT(_X_)                                (_X_)

/* bits definitions for register REG_SLOWCLOCK_SCNT_LOAD */
#define BITS_SCNT_LOAD(_X_)                               (_X_)

/* bits definitions for register REG_SLOWCLOCK_D2_LEFT */
#define BITS_D2_LEFT(_X_)                                 (_X_)

/* bits definitions for register REG_SLOWCLOCK_M_GSM_MVT_CTL */
#define BIT_SLOWC_SELECT98                                ( BIT(2) )
#define BIT_SLOWC_RESET99                                 ( BIT(1) )
#define BIT_SLOWC_100                                     ( BIT(0) )

#endif
