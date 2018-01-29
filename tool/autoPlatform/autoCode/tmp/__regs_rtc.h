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


#ifndef __H_REGS_RTCSECURE_RTC_HEADFILE_H__
#define __H_REGS_RTCSECURE_RTC_HEADFILE_H__ __FILE__

#define	REGS_RTC,SECURE_RTC

/* registers definitions for RTCSECURE_RTC */
#define REG_RTC_RTC_CNR                                   ASR_ADDR(REGS_RTC_BASE, 0X00)/*RTC Counter Register*/
#define REG_SECURE_RTC_RTC_CNR                            ASR_ADDR(REGS_SECURE_RTC_BASE, 0X00)/*RTC Counter Register*/
#define REG_RTC_RTC_AR                                    ASR_ADDR(REGS_RTC_BASE, 0X04)/*RTC Alarm Register*/
#define REG_SECURE_RTC_RTC_AR                             ASR_ADDR(REGS_SECURE_RTC_BASE, 0X04)/*RTC Alarm Register*/
#define REG_RTC_RTC_SR                                    ASR_ADDR(REGS_RTC_BASE, 0X08)/*RTC Status Register*/
#define REG_SECURE_RTC_RTC_SR                             ASR_ADDR(REGS_SECURE_RTC_BASE, 0X08)/*RTC Status Register*/
#define REG_RTC_RTC_TR                                    ASR_ADDR(REGS_RTC_BASE, 0X0C)/*RTC Trim Register*/
#define REG_SECURE_RTC_RTC_TR                             ASR_ADDR(REGS_SECURE_RTC_BASE, 0X0C)/*RTC Trim Register*/
#define REG_RTC_RTC_PR                                    ASR_ADDR(REGS_RTC_BASE, 0X10)/*RTC Control Register*/
#define REG_SECURE_RTC_RTC_PR                             ASR_ADDR(REGS_SECURE_RTC_BASE, 0X10)/*RTC Control Register*/
#define REG_RTC_RTC_BRn                                   ASR_ADDR(REGS_RTC_BASE, 0X14)/*RTC Backup Registers*/
#define REG_SECURE_RTC_RTC_BRn                            ASR_ADDR(REGS_SECURE_RTC_BASE, 0X14)/*RTC Backup Registers*/



/* bits definitions for register REG_SECURE_RTC_RTC_CNR */
#define BITS_TC(_X_)                                      (_X_)

/* bits definitions for register REG_SECURE_RTC_RTC_AR */
#define BITS_AT(_X_)                                      (_X_)

/* bits definitions for register REG_SECURE_RTC_RTC_SR */
#define BIT_HZE                                           ( BIT(3) )
#define BIT_ALE                                           ( BIT(2) )
#define BIT_HZ                                            ( BIT(1) )
#define BIT_AL                                            ( BIT(0) )

/* bits definitions for register REG_SECURE_RTC_RTC_TR */
#define BIT_LCK                                           ( BIT(31) )
#define BITS_D9_D0(_X_)                                   ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BITS_C150_C0(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SECURE_RTC_RTC_PR */
#define BIT_SW_ALARM                                      ( BIT(0) )

/* bits definitions for register REG_SECURE_RTC_RTC_BRn */
#define BITS_RTCS_DATA77(_X_)                             (_X_)

#endif
