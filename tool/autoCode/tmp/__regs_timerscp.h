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


#ifndef __H_REGS_TMRTMRCPTMRGPB_HEADFILE_H__
#define __H_REGS_TMRTMRCPTMRGPB_HEADFILE_H__ __FILE__

#define	REGS_TMR,TMRCP,TMRGPB

/* registers definitions for TMRTMRCPTMRGPB */
#define REG_TMR_TMR_CCR                                   ASR_ADDR(REGS_TMR_BASE, 0X00)/*Timer Clock Control Register*/
#define REG_TMRCP_TMR_CCR                                 ASR_ADDR(REGS_TMRCP_BASE, 0X00)/*Timer Clock Control Register*/
#define REG_TMRGPB_TMR_CCR                                ASR_ADDR(REGS_TMRGPB_BASE, 0X00)/*Timer Clock Control Register*/
#define REG_TMR_TMR_Tn_Mm                                 ASR_ADDR(REGS_TMR_BASE, 0X04)/*Timer Match Registers*/
#define REG_TMRCP_TMR_Tn_Mm                               ASR_ADDR(REGS_TMRCP_BASE, 0X04)/*Timer Match Registers*/
#define REG_TMRGPB_TMR_Tn_Mm                              ASR_ADDR(REGS_TMRGPB_BASE, 0X04)/*Timer Match Registers*/
#define REG_TMR_TMR_CRn                                   ASR_ADDR(REGS_TMR_BASE, 0X28)/*Timer Count Registers*/
#define REG_TMRCP_TMR_CRn                                 ASR_ADDR(REGS_TMRCP_BASE, 0X28)/*Timer Count Registers*/
#define REG_TMRGPB_TMR_CRn                                ASR_ADDR(REGS_TMRGPB_BASE, 0X28)/*Timer Count Registers*/
#define REG_TMR_TMR_SRn                                   ASR_ADDR(REGS_TMR_BASE, 0X34)/*Timer Status Registers*/
#define REG_TMRCP_TMR_SRn                                 ASR_ADDR(REGS_TMRCP_BASE, 0X34)/*Timer Status Registers*/
#define REG_TMRGPB_TMR_SRn                                ASR_ADDR(REGS_TMRGPB_BASE, 0X34)/*Timer Status Registers*/
#define REG_TMR_TMR_IERn                                  ASR_ADDR(REGS_TMR_BASE, 0X40)/*Timer Interrupt Enable Registers*/
#define REG_TMRCP_TMR_IERn                                ASR_ADDR(REGS_TMRCP_BASE, 0X40)/*Timer Interrupt Enable Registers*/
#define REG_TMRGPB_TMR_IERn                               ASR_ADDR(REGS_TMRGPB_BASE, 0X40)/*Timer Interrupt Enable Registers*/
#define REG_TMR_TMR_PLVRn                                 ASR_ADDR(REGS_TMR_BASE, 0X4C)/*Timer Preload Value Registers*/
#define REG_TMRCP_TMR_PLVRn                               ASR_ADDR(REGS_TMRCP_BASE, 0X4C)/*Timer Preload Value Registers*/
#define REG_TMRGPB_TMR_PLVRn                              ASR_ADDR(REGS_TMRGPB_BASE, 0X4C)/*Timer Preload Value Registers*/
#define REG_TMR_TMR_PLCRn                                 ASR_ADDR(REGS_TMR_BASE, 0X58)/*Timer Preload Control Registers*/
#define REG_TMRCP_TMR_PLCRn                               ASR_ADDR(REGS_TMRCP_BASE, 0X58)/*Timer Preload Control Registers*/
#define REG_TMRGPB_TMR_PLCRn                              ASR_ADDR(REGS_TMRGPB_BASE, 0X58)/*Timer Preload Control Registers*/
#define REG_TMR_TMR_WMER                                  ASR_ADDR(REGS_TMR_BASE, 0X64)/*Timers Watchdog Match Enable Register*/
#define REG_TMRCP_TMR_WMER                                ASR_ADDR(REGS_TMRCP_BASE, 0X64)/*Timers Watchdog Match Enable Register*/
#define REG_TMRGPB_TMR_WMER                               ASR_ADDR(REGS_TMRGPB_BASE, 0X64)/*Timers Watchdog Match Enable Register*/
#define REG_TMR_TMR_WMR                                   ASR_ADDR(REGS_TMR_BASE, 0X68)/*Timers Watchdog Match Register*/
#define REG_TMRCP_TMR_WMR                                 ASR_ADDR(REGS_TMRCP_BASE, 0X68)/*Timers Watchdog Match Register*/
#define REG_TMRGPB_TMR_WMR                                ASR_ADDR(REGS_TMRGPB_BASE, 0X68)/*Timers Watchdog Match Register*/
#define REG_TMR_TMR_WVR                                   ASR_ADDR(REGS_TMR_BASE, 0X6C)/*Timers Watchdog Value Register*/
#define REG_TMRCP_TMR_WVR                                 ASR_ADDR(REGS_TMRCP_BASE, 0X6C)/*Timers Watchdog Value Register*/
#define REG_TMRGPB_TMR_WVR                                ASR_ADDR(REGS_TMRGPB_BASE, 0X6C)/*Timers Watchdog Value Register*/
#define REG_TMR_TMR_WSR                                   ASR_ADDR(REGS_TMR_BASE, 0X70)/*Timers Watchdog Status Register*/
#define REG_TMRCP_TMR_WSR                                 ASR_ADDR(REGS_TMRCP_BASE, 0X70)/*Timers Watchdog Status Register*/
#define REG_TMRGPB_TMR_WSR                                ASR_ADDR(REGS_TMRGPB_BASE, 0X70)/*Timers Watchdog Status Register*/
#define REG_TMR_TMR_ICRn                                  ASR_ADDR(REGS_TMR_BASE, 0X74)/*Timer Interrupt Clear Registers*/
#define REG_TMRCP_TMR_ICRn                                ASR_ADDR(REGS_TMRCP_BASE, 0X74)/*Timer Interrupt Clear Registers*/
#define REG_TMRGPB_TMR_ICRn                               ASR_ADDR(REGS_TMRGPB_BASE, 0X74)/*Timer Interrupt Clear Registers*/
#define REG_TMR_TMR_WICR                                  ASR_ADDR(REGS_TMR_BASE, 0X80)/*Timers Watchdog Interrupt Clear Register*/
#define REG_TMRCP_TMR_WICR                                ASR_ADDR(REGS_TMRCP_BASE, 0X80)/*Timers Watchdog Interrupt Clear Register*/
#define REG_TMRGPB_TMR_WICR                               ASR_ADDR(REGS_TMRGPB_BASE, 0X80)/*Timers Watchdog Interrupt Clear Register*/
#define REG_TMR_TMR_CER                                   ASR_ADDR(REGS_TMR_BASE, 0X84)/*Timers Count Enable Register*/
#define REG_TMRCP_TMR_CER                                 ASR_ADDR(REGS_TMRCP_BASE, 0X84)/*Timers Count Enable Register*/
#define REG_TMRGPB_TMR_CER                                ASR_ADDR(REGS_TMRGPB_BASE, 0X84)/*Timers Count Enable Register*/
#define REG_TMR_TMR_CMR                                   ASR_ADDR(REGS_TMR_BASE, 0X88)/*Timers Count Mode Register*/
#define REG_TMRCP_TMR_CMR                                 ASR_ADDR(REGS_TMRCP_BASE, 0X88)/*Timers Count Mode Register*/
#define REG_TMRGPB_TMR_CMR                                ASR_ADDR(REGS_TMRGPB_BASE, 0X88)/*Timers Count Mode Register*/
#define REG_TMR_TMR_ILRn                                  ASR_ADDR(REGS_TMR_BASE, 0X8C)/*Timer Interrupt Length Registers*/
#define REG_TMRCP_TMR_ILRn                                ASR_ADDR(REGS_TMRCP_BASE, 0X8C)/*Timer Interrupt Length Registers*/
#define REG_TMRGPB_TMR_ILRn                               ASR_ADDR(REGS_TMRGPB_BASE, 0X8C)/*Timer Interrupt Length Registers*/
#define REG_TMR_TMR_WCR                                   ASR_ADDR(REGS_TMR_BASE, 0X98)/*Timers Watchdog Counter Reset Register*/
#define REG_TMRCP_TMR_WCR                                 ASR_ADDR(REGS_TMRCP_BASE, 0X98)/*Timers Watchdog Counter Reset Register*/
#define REG_TMRGPB_TMR_WCR                                ASR_ADDR(REGS_TMRGPB_BASE, 0X98)/*Timers Watchdog Counter Reset Register*/
#define REG_TMR_TMR_WFAR                                  ASR_ADDR(REGS_TMR_BASE, 0X9C)/*Timers Watchdog First Access Register*/
#define REG_TMRCP_TMR_WFAR                                ASR_ADDR(REGS_TMRCP_BASE, 0X9C)/*Timers Watchdog First Access Register*/
#define REG_TMRGPB_TMR_WFAR                               ASR_ADDR(REGS_TMRGPB_BASE, 0X9C)/*Timers Watchdog First Access Register*/
#define REG_TMR_TMR_WSAR                                  ASR_ADDR(REGS_TMR_BASE, 0XA0)/*Timers Watchdog Second Access Register*/
#define REG_TMRCP_TMR_WSAR                                ASR_ADDR(REGS_TMRCP_BASE, 0XA0)/*Timers Watchdog Second Access Register*/
#define REG_TMRGPB_TMR_WSAR                               ASR_ADDR(REGS_TMRGPB_BASE, 0XA0)/*Timers Watchdog Second Access Register*/
#define REG_TMR_TMR_CVWRn                                 ASR_ADDR(REGS_TMR_BASE, 0XA4)/*Timer Counters Value Write for Read Request Register*/
#define REG_TMRCP_TMR_CVWRn                               ASR_ADDR(REGS_TMRCP_BASE, 0XA4)/*Timer Counters Value Write for Read Request Register*/
#define REG_TMRGPB_TMR_CVWRn                              ASR_ADDR(REGS_TMRGPB_BASE, 0XA4)/*Timer Counters Value Write for Read Request Register*/



/* bits definitions for register REG_TMRGPB_TMR_CCR */
#define BITS_TMRT_CS_224(_X_)                             ( (_X_) << 5 & (BIT(5)|BIT(6)) )
#define BITS_TMRT_CS_126(_X_)                             ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_TMRT_CS_027(_X_)                             ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_TMRGPB_TMR_Tn_Mm */
#define BITS_TMRT_TMR_TN_MM34(_X_)                        (_X_)

/* bits definitions for register REG_TMRGPB_TMR_CRn */
#define BITS_TMRT_TCRN55(_X_)                             (_X_)

/* bits definitions for register REG_TMRGPB_TMR_SRn */
#define BIT_TMRT_M264                                     ( BIT(2) )
#define BIT_TMRT_M165                                     ( BIT(1) )
#define BIT_TMRT_M066                                     ( BIT(0) )

/* bits definitions for register REG_TMRGPB_TMR_IERn */
#define BIT_TMRT_IE275                                    ( BIT(2) )
#define BIT_TMRT_IE176                                    ( BIT(1) )
#define BIT_TMRT_IE077                                    ( BIT(0) )

/* bits definitions for register REG_TMRGPB_TMR_PLVRn */
#define BITS_TMRT_TPLVRN85(_X_)                           (_X_)

/* bits definitions for register REG_TMRGPB_TMR_PLCRn */
#define BITS_TMRT_MCS94(_X_)                              ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_TMRGPB_TMR_WMER */
#define BIT_WRIE                                          ( BIT(1) )
#define BIT_WE                                            ( BIT(0) )

/* bits definitions for register REG_TMRGPB_TMR_WMR */
#define BITS_WTM(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_TMRGPB_TMR_WVR */
#define BITS_WTV(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_TMRGPB_TMR_WSR */
#define BIT_WTS                                           ( BIT(0) )

/* bits definitions for register REG_TMRGPB_TMR_ICRn */
#define BIT_TMRT_TCLR2139                                 ( BIT(2) )
#define BIT_TMRT_TCLR1140                                 ( BIT(1) )
#define BIT_TMRT_TCLR0141                                 ( BIT(0) )

/* bits definitions for register REG_TMRGPB_TMR_WICR */
#define BIT_WICLR                                         ( BIT(0) )

/* bits definitions for register REG_TMRGPB_TMR_CER */
#define BIT_TMRT_T2EN159                                  ( BIT(2) )
#define BIT_TMRT_T1EN160                                  ( BIT(1) )
#define BIT_TMRT_T0EN161                                  ( BIT(0) )

/* bits definitions for register REG_TMRGPB_TMR_CMR */
#define BIT_TMRT_T2MODE170                                ( BIT(2) )
#define BIT_TMRT_T1MODE171                                ( BIT(1) )
#define BIT_TMRT_T0MODE172                                ( BIT(0) )

/* bits definitions for register REG_TMRGPB_TMR_ILRn */
#define BIT_TNIL2                                         ( BIT(2) )
#define BIT_TNIL1                                         ( BIT(1) )
#define BIT_TNIL0                                         ( BIT(0) )

/* bits definitions for register REG_TMRGPB_TMR_WCR */
#define BIT_WCR                                           ( BIT(0) )

/* bits definitions for register REG_TMRGPB_TMR_WFAR */
#define BITS_KEY207(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_TMRGPB_TMR_WSAR */
#define BITS_KEY215(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_TMRGPB_TMR_CVWRn */
#define BITS_TCVWR(_X_)                                   (_X_)

#endif
