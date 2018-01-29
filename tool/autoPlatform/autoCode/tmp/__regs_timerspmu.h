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


#ifndef __H_REGS_TMR_HEADFILE_H__
#define __H_REGS_TMR_HEADFILE_H__ __FILE__

#define	REGS_TMR

/* registers definitions for TMR */
#define REG_TMR_TMR_CCR                                   ASR_ADDR(REGS_TMR_BASE, 0X00)/*Timer Clock Control Register*/
#define REG_TMR_TMR_Tn_Mm                                 ASR_ADDR(REGS_TMR_BASE, 0X04)/*Timer Match Registers*/
#define REG_TMR_TMR_CRn                                   ASR_ADDR(REGS_TMR_BASE, 0X28)/*Timer Count Registers*/
#define REG_TMR_TMR_SRn                                   ASR_ADDR(REGS_TMR_BASE, 0X34)/*Timer Status Registers*/
#define REG_TMR_TMR_IERn                                  ASR_ADDR(REGS_TMR_BASE, 0X40)/*Timer Interrupt Enable Registers*/
#define REG_TMR_TMR_PLVRn                                 ASR_ADDR(REGS_TMR_BASE, 0X4C)/*Timer Preload Value Registers*/
#define REG_TMR_TMR_PLCRn                                 ASR_ADDR(REGS_TMR_BASE, 0X58)/*Timer Preload Control Registers*/
#define REG_TMR_TMR_WMER                                  ASR_ADDR(REGS_TMR_BASE, 0X64)/*Timers Watchdog Match Enable Register*/
#define REG_TMR_TMR_WMR                                   ASR_ADDR(REGS_TMR_BASE, 0X68)/*Timers Watchdog Match Register*/
#define REG_TMR_TMR_WVR                                   ASR_ADDR(REGS_TMR_BASE, 0X6C)/*Timers Watchdog Value Register*/
#define REG_TMR_TMR_WSR                                   ASR_ADDR(REGS_TMR_BASE, 0X70)/*Timers Watchdog Status Register*/
#define REG_TMR_TMR_ICRn                                  ASR_ADDR(REGS_TMR_BASE, 0X74)/*Timer Interrupt Clear Registers*/
#define REG_TMR_TMR_WICR                                  ASR_ADDR(REGS_TMR_BASE, 0X80)/*Timers Watchdog Interrupt Clear Register*/
#define REG_TMR_TMR_CER                                   ASR_ADDR(REGS_TMR_BASE, 0X84)/*Timers Count Enable Register*/
#define REG_TMR_TMR_CMR                                   ASR_ADDR(REGS_TMR_BASE, 0X88)/*Timers Count Mode Register*/
#define REG_TMR_TMR_ILRn                                  ASR_ADDR(REGS_TMR_BASE, 0X8C)/*Timer Interrupt Length Registers*/
#define REG_TMR_TMR_WCR                                   ASR_ADDR(REGS_TMR_BASE, 0X98)/*Timers Watchdog Counter Reset Register*/
#define REG_TMR_TMR_WFAR                                  ASR_ADDR(REGS_TMR_BASE, 0X9C)/*Timers Watchdog First Access Register*/
#define REG_TMR_TMR_WSAR                                  ASR_ADDR(REGS_TMR_BASE, 0XA0)/*Timers Watchdog Second Access Register*/
#define REG_TMR_TMR_CVWRn                                 ASR_ADDR(REGS_TMR_BASE, 0XA4)/*Timer Counters Value Write for Read Request Register*/



/* bits definitions for register REG_TMR_TMR_CCR */
#define BITS_TM_CS_226(_X_)                               ( (_X_) << 5 & (BIT(5)|BIT(6)) )
#define BITS_TM_CS_128(_X_)                               ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_TM_CS_029(_X_)                               ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_TMR_TMR_Tn_Mm */
#define BITS_TM_TMR_TN_MM36(_X_)                          (_X_)

/* bits definitions for register REG_TMR_TMR_CRn */
#define BITS_TM_TCRN57(_X_)                               (_X_)

/* bits definitions for register REG_TMR_TMR_SRn */
#define BIT_TM_M266                                       ( BIT(2) )
#define BIT_TM_M167                                       ( BIT(1) )
#define BIT_TM_M068                                       ( BIT(0) )

/* bits definitions for register REG_TMR_TMR_IERn */
#define BIT_TM_IE277                                      ( BIT(2) )
#define BIT_TM_IE178                                      ( BIT(1) )
#define BIT_TM_IE079                                      ( BIT(0) )

/* bits definitions for register REG_TMR_TMR_PLVRn */
#define BITS_TM_TPLVRN87(_X_)                             (_X_)

/* bits definitions for register REG_TMR_TMR_PLCRn */
#define BITS_TM_MCS96(_X_)                                ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_TMR_TMR_WMER */
#define BIT_TM_WRIE105                                    ( BIT(1) )
#define BIT_TM_WE106                                      ( BIT(0) )

/* bits definitions for register REG_TMR_TMR_WMR */
#define BITS_TM_WTM115(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_TMR_TMR_WVR */
#define BITS_TM_WTV123(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_TMR_TMR_WSR */
#define BIT_TM_WTS132                                     ( BIT(0) )

/* bits definitions for register REG_TMR_TMR_ICRn */
#define BIT_TM_TCLR2141                                   ( BIT(2) )
#define BIT_TM_TCLR1142                                   ( BIT(1) )
#define BIT_TM_TCLR0143                                   ( BIT(0) )

/* bits definitions for register REG_TMR_TMR_WICR */
#define BIT_TM_WICLR152                                   ( BIT(0) )

/* bits definitions for register REG_TMR_TMR_CER */
#define BIT_TM_T2EN161                                    ( BIT(2) )
#define BIT_TM_T1EN162                                    ( BIT(1) )
#define BIT_TM_T0EN163                                    ( BIT(0) )

/* bits definitions for register REG_TMR_TMR_CMR */
#define BIT_TM_T2MODE172                                  ( BIT(2) )
#define BIT_TM_T1MODE173                                  ( BIT(1) )
#define BIT_TM_T0MODE174                                  ( BIT(0) )

/* bits definitions for register REG_TMR_TMR_ILRn */
#define BIT_TNIL2                                         ( BIT(2) )
#define BIT_TNIL1                                         ( BIT(1) )
#define BIT_TNIL0                                         ( BIT(0) )

/* bits definitions for register REG_TMR_TMR_WCR */
#define BIT_TM_WCR195                                     ( BIT(0) )

/* bits definitions for register REG_TMR_TMR_WFAR */
#define BITS_TM_KEY209(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_TMR_TMR_WSAR */
#define BITS_TM_KEY217(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_TMR_TMR_CVWRn */
#define BITS_TCVWR(_X_)                                   (_X_)

#endif
