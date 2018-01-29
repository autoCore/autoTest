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


#ifndef __H_REGS_APB_TIMERS0_HEADFILE_H__
#define __H_REGS_APB_TIMERS0_HEADFILE_H__ __FILE__

#define	REGS_APB_TIMERS0

/* registers definitions for APB_TIMERS0 */
#define REG_APB_TIMERS0_TMR_CER                           ASR_ADDR(REGS_APB_TIMERS0_BASE, 0X00)/*Timers Count Enable Register*/
#define REG_APB_TIMERS0_TMR_CMR                           ASR_ADDR(REGS_APB_TIMERS0_BASE, 0X04)/*Timers Count Mode Register*/
#define REG_APB_TIMERS0_TMR_CRSR                          ASR_ADDR(REGS_APB_TIMERS0_BASE, 0X08)/*Timer Count Restart register*/
#define REG_APB_TIMERS0_TMR_CCR                           ASR_ADDR(REGS_APB_TIMERS0_BASE, 0X0C)/*Timer Clock Control Register*/
#define REG_APB_TIMERS0_TMR_Tn_Mm0                        ASR_ADDR(REGS_APB_TIMERS0_BASE, 0x10)/*Timer Match Registers*/
#define REG_APB_TIMERS0_TMR_Tn_Mm1                        ASR_ADDR(REGS_APB_TIMERS0_BASE, 0x20)/*Timer Match Registers*/
#define REG_APB_TIMERS0_TMR_Tn_Mm2                        ASR_ADDR(REGS_APB_TIMERS0_BASE, 0x30)/*Timer Match Registers*/
#define REG_APB_TIMERS0_TMR_PLVRn                         ASR_ADDR(REGS_APB_TIMERS0_BASE, 0X40)/*Timer Preload Value Registers*/
#define REG_APB_TIMERS0_TMR_PLCRn                         ASR_ADDR(REGS_APB_TIMERS0_BASE, 0X50)/*Timer Preload Control Registers*/
#define REG_APB_TIMERS0_TMR_IERn                          ASR_ADDR(REGS_APB_TIMERS0_BASE, 0X60)/*Timer Interrupt Enable Registers*/
#define REG_APB_TIMERS0_TMR_ICRn                          ASR_ADDR(REGS_APB_TIMERS0_BASE, 0X70)/*Timer Interrupt Clear Registers*/
#define REG_APB_TIMERS0_TMR_SRn                           ASR_ADDR(REGS_APB_TIMERS0_BASE, 0X80)/*Timer Status Registers*/
#define REG_APB_TIMERS0_TMR_CRn                           ASR_ADDR(REGS_APB_TIMERS0_BASE, 0X90)/*Timer Count Registers*/
#define REG_APB_TIMERS0_TMR_WFAR                          ASR_ADDR(REGS_APB_TIMERS0_BASE, 0XB0)/*Timers Watchdog First Access Register*/
#define REG_APB_TIMERS0_TMR_WSAR                          ASR_ADDR(REGS_APB_TIMERS0_BASE, 0XB4)/*Timers Watchdog Second Access Register*/
#define REG_APB_TIMERS0_TMR_WMER                          ASR_ADDR(REGS_APB_TIMERS0_BASE, 0XB8)/*Timers Watchdog Match Enable Register*/
#define REG_APB_TIMERS0_TMR_WMR                           ASR_ADDR(REGS_APB_TIMERS0_BASE, 0XBC)/*Timers Watchdog Match Register*/
#define REG_APB_TIMERS0_TMR_WSR                           ASR_ADDR(REGS_APB_TIMERS0_BASE, 0XC0)/*Timers Watchdog Status Register*/
#define REG_APB_TIMERS0_TMR_WICR                          ASR_ADDR(REGS_APB_TIMERS0_BASE, 0XC4)/*Timers Watchdog Interrupt Clear Register*/
#define REG_APB_TIMERS0_TMR_WCR                           ASR_ADDR(REGS_APB_TIMERS0_BASE, 0XC8)/*Timers Watchdog Counter Reset Register*/
#define REG_APB_TIMERS0_TMR_WVR                           ASR_ADDR(REGS_APB_TIMERS0_BASE, 0XCC)/*Timers Watchdog Value Register*/



/* bits definitions for register REG_APB_TIMERS0_TMR_CER */
#define BIT_APB_T_T2EN18                                  ( BIT(2) )
#define BIT_APB_T_T1EN19                                  ( BIT(1) )
#define BIT_APB_T_T0EN20                                  ( BIT(0) )

/* bits definitions for register REG_APB_TIMERS0_TMR_CMR */
#define BIT_APB_T_T2MODE29                                ( BIT(2) )
#define BIT_APB_T_T1MODE30                                ( BIT(1) )
#define BIT_APB_T_T0MODE31                                ( BIT(0) )

/* bits definitions for register REG_APB_TIMERS0_TMR_CRSR */
#define BIT_T2RS                                          ( BIT(2) )
#define BIT_T1RS                                          ( BIT(1) )
#define BIT_T0RS                                          ( BIT(0) )

/* bits definitions for register REG_APB_TIMERS0_TMR_CCR */
#define BITS_APB_T_CS_252(_X_)                            ( (_X_) << 5 & (BIT(5)|BIT(6)) )
#define BITS_APB_T_CS_154(_X_)                            ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_APB_T_CS_055(_X_)                            ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_APB_TIMERS0_TMR_Tn_Mm2 */
#define BITS_APB_T_TMR_TN_MM62(_X_)                       (_X_)

/* bits definitions for register REG_APB_TIMERS0_TMR_PLVRn */
#define BITS_APB_T_TPLVRN78(_X_)                          (_X_)

/* bits definitions for register REG_APB_TIMERS0_TMR_PLCRn */
#define BIT_CRPD                                          ( BIT(2) )
#define BITS_APB_T_MCS88(_X_)                             ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_APB_TIMERS0_TMR_IERn */
#define BIT_APB_T_IE298                                   ( BIT(2) )
#define BIT_APB_T_IE199                                   ( BIT(1) )
#define BIT_APB_T_IE0100                                  ( BIT(0) )

/* bits definitions for register REG_APB_TIMERS0_TMR_ICRn */
#define BIT_APB_T_TCLR2110                                ( BIT(2) )
#define BIT_APB_T_TCLR1111                                ( BIT(1) )
#define BIT_APB_T_TCLR0112                                ( BIT(0) )

/* bits definitions for register REG_APB_TIMERS0_TMR_SRn */
#define BIT_APB_T_M2122                                   ( BIT(2) )
#define BIT_APB_T_M1123                                   ( BIT(1) )
#define BIT_APB_T_M0124                                   ( BIT(0) )

/* bits definitions for register REG_APB_TIMERS0_TMR_CRn */
#define BITS_APB_T_TCRN137(_X_)                           (_X_)

/* bits definitions for register REG_APB_TIMERS0_TMR_WFAR */
#define BITS_KEY151(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_APB_TIMERS0_TMR_WSAR */
#define BITS_KEY159(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_APB_TIMERS0_TMR_WMER */
#define BIT_APB_T_WRIE167                                 ( BIT(1) )
#define BIT_APB_T_WE168                                   ( BIT(0) )

/* bits definitions for register REG_APB_TIMERS0_TMR_WMR */
#define BITS_APB_T_WTM177(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_APB_TIMERS0_TMR_WSR */
#define BIT_APB_T_WTS186                                  ( BIT(0) )

/* bits definitions for register REG_APB_TIMERS0_TMR_WICR */
#define BIT_APB_T_WICLR195                                ( BIT(0) )

/* bits definitions for register REG_APB_TIMERS0_TMR_WCR */
#define BIT_APB_T_WCR204                                  ( BIT(0) )

/* bits definitions for register REG_APB_TIMERS0_TMR_WVR */
#define BITS_APB_T_WTV213(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

#endif
