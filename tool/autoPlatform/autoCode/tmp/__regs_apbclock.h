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


#ifndef __H_REGS_APBC_HEADFILE_H__
#define __H_REGS_APBC_HEADFILE_H__ __FILE__

#define	REGS_APBC

/* registers definitions for APBC */
#define REG_APBC_APBC_UART1_CLK_RST                       ASR_ADDR(REGS_APBC_BASE, 0X0)/*Clock/Reset Control Register for UART 1*/
#define REG_APBC_APBC_UART2_CLK_RST                       ASR_ADDR(REGS_APBC_BASE, 0X4)/*Clock/Reset Control Register for UART 2*/
#define REG_APBC_APBC_GPIO_CLK_RST                        ASR_ADDR(REGS_APBC_BASE, 0X8)/*Clock/Reset Control Register for GPIO*/
#define REG_APBC_APBC_PWM0_CLK_RST                        ASR_ADDR(REGS_APBC_BASE, 0XC)/*Clock/Reset Control Register for PWM 0*/
#define REG_APBC_APBC_PWM1_CLK_RST                        ASR_ADDR(REGS_APBC_BASE, 0X10)/*Clock/Reset Control Register for PWM 1*/
#define REG_APBC_APBC_PWM2_CLK_RST                        ASR_ADDR(REGS_APBC_BASE, 0X14)/*Clock/Reset Control Register for PWM 2*/
#define REG_APBC_APBC_PWM3_CLK_RST                        ASR_ADDR(REGS_APBC_BASE, 0X18)/*Clock/Reset Control Register for PWM 3*/
#define REG_APBC_APBC_SSP0_CLK_RST                        ASR_ADDR(REGS_APBC_BASE, 0X1C)/*Clock/Reset Control Register for SSP 0*/
#define REG_APBC_APBC_IPC_CLK_RST                         ASR_ADDR(REGS_APBC_BASE, 0X24)/*Clock/Reset Control Register for Inter-Processor Communication*/
#define REG_APBC_APBC_RTC_CLK_RST                         ASR_ADDR(REGS_APBC_BASE, 0X28)/*Clock/Reset Control Register for RTC*/
#define REG_APBC_APBC_TWSI0_CLK_RST                       ASR_ADDR(REGS_APBC_BASE, 0X2C)/*Clock/Reset Control Register for TWSI0*/
#define REG_APBC_APBC_KPC_CLK_RST                         ASR_ADDR(REGS_APBC_BASE, 0X30)/*Clock/Reset Control Register for Keypad Controller*/
#define REG_APBC_APBC_TIMERS_CLK_RST                      ASR_ADDR(REGS_APBC_BASE, 0X34)/*Clock/Reset Control Register for Timer 0*/
#define REG_APBC_APBC_AIB_CLK_RST                         ASR_ADDR(REGS_APBC_BASE, 0X3C)/*Clock/Reset Control Register for AIB*/
#define REG_APBC_APBC_SW_JTAG_CLK_RST                     ASR_ADDR(REGS_APBC_BASE, 0X40)/*Clock/Reset Control Register for JTAG Software Emulation*/
#define REG_APBC_APBC_TIMERS1_CLK_RST                     ASR_ADDR(REGS_APBC_BASE, 0X44)/*Clock/Reset Control Register for Timers 1*/
#define REG_APBC_APBC_ONEWIRE_CLK_RST                     ASR_ADDR(REGS_APBC_BASE, 0X48)/*Clock/Reset Control Register for One-Wire*/
#define REG_APBC_APBC_SSP2_CLK_RST                        ASR_ADDR(REGS_APBC_BASE, 0X4C)/*Clock/Reset Control Register for SSP 2*/
#define REG_APBC_APBC_ASFAR                               ASR_ADDR(REGS_APBC_BASE, 0X50)/*AIB Secure First Access Register*/
#define REG_APBC_APBC_ASSAR                               ASR_ADDR(REGS_APBC_BASE, 0X54)/*AIB Secure Second Access Register*/
#define REG_APBC_APBC_DRO_CLK_RST                         ASR_ADDR(REGS_APBC_BASE, 0X58)/*Clock/Reset Control Register forDRO*/
#define REG_APBC_APBC_TWSI1_CLK_RST                       ASR_ADDR(REGS_APBC_BASE, 0X60)/*Clock/Reset Control Register for TWSI1*/
#define REG_APBC_APBC_COUNTER_CLK_SEL                     ASR_ADDR(REGS_APBC_BASE, 0X64)/*Clock Control Register for Generic Counter*/
#define REG_APBC_APBC_TIMERS2_CLK_RST                     ASR_ADDR(REGS_APBC_BASE, 0X68)/*Clock/Reset Control Register for Timers 2*/
#define REG_APBC_APBC_TSEN_CLK_RST                        ASR_ADDR(REGS_APBC_BASE, 0X6C)/*Clock/Reset Control Register for Temperature Sensor*/
#define REG_APBC_APBC_TWSI2_CLK_RST                       ASR_ADDR(REGS_APBC_BASE, 0X70)/*Clock/Reset Control Register for TWSI2*/
#define REG_APBC_APBC_TWSI3_CLK_RST                       ASR_ADDR(REGS_APBC_BASE, 0X74)/*Clock/Reset Control Register for TWSI3*/
#define REG_APBC_APBC_UART3_CLK_RST                       ASR_ADDR(REGS_APBC_BASE, 0X78)/*Clock/Reset Control Register for UART 3*/
#define REG_APBC_APBC_TWSI4_CLK_RST                       ASR_ADDR(REGS_APBC_BASE, 0X7C)/*Clock/Reset Control Register for TWSI4*/
#define REG_APBC_APBC_TWSI5_CLK_RST                       ASR_ADDR(REGS_APBC_BASE, 0X80)/*Clock/Reset Control Register for TWSI5*/
#define REG_APBC_APBC_TWSI6_CLK_RST                       ASR_ADDR(REGS_APBC_BASE, 0X84)/*Clock/Reset Control Register for TWSI6*/
#define REG_APBC_APBC_TWSI7_CLK_RST                       ASR_ADDR(REGS_APBC_BASE, 0X88)/*Clock/Reset Control Register for TWSI7*/
#define REG_APBC_APBC_TWSI8_CLK_RST                       ASR_ADDR(REGS_APBC_BASE, 0X8C)/*Clock/Reset Control Register for TWSI8*/
#define REG_APBC_APBC_IPC_AP2AUD_CLK_RST                  ASR_ADDR(REGS_APBC_BASE, 0X90)/*Clock/Reset Control Register for Inter-Processor Communication（AP to Audio）*/
#define REG_APBC_APBC_I3C_CLK_RST                         ASR_ADDR(REGS_APBC_BASE, 0X98)/*Clock/Reset Control Register for I3C*/



/* bits definitions for register REG_APBC_APBC_UART1_CLK_RST */
#define BITS_FNCLKSEL15(_X_)                              ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST17                                         ( BIT(2) )
#define BIT_FNCLK18                                       ( BIT(1) )
#define BIT_APBCLK19                                      ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_UART2_CLK_RST */
#define BITS_FNCLKSEL27(_X_)                              ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST29                                         ( BIT(2) )
#define BIT_FNCLK30                                       ( BIT(1) )
#define BIT_APBCLK31                                      ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_GPIO_CLK_RST */
#define BITS_FNCLKSEL39(_X_)                              ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST41                                         ( BIT(2) )
#define BIT_FNCLK42                                       ( BIT(1) )
#define BIT_APBCLK43                                      ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_PWM0_CLK_RST */
#define BITS_FNCLKSEL52(_X_)                              ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST54                                         ( BIT(2) )
#define BIT_FNCLK55                                       ( BIT(1) )
#define BIT_APBCLK56                                      ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_PWM1_CLK_RST */
#define BITS_FNCLKSEL65(_X_)                              ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST67                                         ( BIT(2) )
#define BIT_FNCLK68                                       ( BIT(1) )

/* bits definitions for register REG_APBC_APBC_PWM2_CLK_RST */
#define BITS_FNCLKSEL78(_X_)                              ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST80                                         ( BIT(2) )
#define BIT_FNCLK81                                       ( BIT(1) )
#define BIT_APBCLK82                                      ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_PWM3_CLK_RST */
#define BITS_FNCLKSEL91(_X_)                              ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST93                                         ( BIT(2) )
#define BIT_FNCLK94                                       ( BIT(1) )

/* bits definitions for register REG_APBC_APBC_SSP0_CLK_RST */
#define BIT_SEL_SSP_FUNC_CLK104                           ( BIT(7) )
#define BITS_FNCLKSEL105(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST107                                        ( BIT(2) )
#define BIT_FNCLK108                                      ( BIT(1) )
#define BIT_APBCLK109                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_IPC_CLK_RST */
#define BITS_FNCLKSEL119(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST121                                        ( BIT(2) )
#define BIT_FNCLK122                                      ( BIT(1) )
#define BIT_APBCLK123                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_RTC_CLK_RST */
#define BIT_PM_POWER_SENSOR                               ( BIT(7) )
#define BITS_FNCLKSEL132(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST134                                        ( BIT(2) )
#define BIT_FNCLK135                                      ( BIT(1) )
#define BIT_APBCLK136                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_TWSI0_CLK_RST */
#define BITS_FNCLKSEL144(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST146                                        ( BIT(2) )
#define BIT_FNCLK147                                      ( BIT(1) )
#define BIT_APBCLK148                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_KPC_CLK_RST */
#define BITS_FNCLKSEL156(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST158                                        ( BIT(2) )
#define BIT_FNCLK159                                      ( BIT(1) )
#define BIT_APBCLK160                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_TIMERS_CLK_RST */
#define BITS_FNCLKSEL168(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST170                                        ( BIT(2) )
#define BIT_FNCLK171                                      ( BIT(1) )
#define BIT_APBCLK172                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_AIB_CLK_RST */
#define BITS_FNCLKSEL180(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST182                                        ( BIT(2) )
#define BIT_FNCLK183                                      ( BIT(1) )
#define BIT_APBCLK184                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_SW_JTAG_CLK_RST */
#define BITS_FNCLKSEL192(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST194                                        ( BIT(2) )
#define BIT_FNCLK195                                      ( BIT(1) )
#define BIT_APBCLK196                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_TIMERS1_CLK_RST */
#define BITS_FNCLKSEL204(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST206                                        ( BIT(2) )
#define BIT_FNCLK207                                      ( BIT(1) )
#define BIT_APBCLK208                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_ONEWIRE_CLK_RST */
#define BITS_FNCLKSEL216(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST218                                        ( BIT(2) )
#define BIT_FNCLK219                                      ( BIT(1) )
#define BIT_APBCLK220                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_SSP2_CLK_RST */
#define BIT_SEL_SSP_FUNC_CLK229                           ( BIT(7) )
#define BITS_FNCLKSEL230(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST232                                        ( BIT(2) )
#define BIT_FNCLK233                                      ( BIT(1) )
#define BIT_APBCLK234                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_ASFAR */
#define BITS_ASFAR(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_APBC_APBC_ASSAR */
#define BITS_ASSAR(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_APBC_APBC_DRO_CLK_RST */
#define BIT_RST259                                        ( BIT(2) )
#define BIT_APBCLK261                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_TWSI1_CLK_RST */
#define BITS_FNCLKSEL269(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST271                                        ( BIT(2) )
#define BIT_FNCLK272                                      ( BIT(1) )
#define BIT_APBCLK273                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_COUNTER_CLK_SEL */
#define BITS_LOW_FREQ_STEP(_X_)                           ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_FREQ_SW_SEL                                   ( BIT(1) )
#define BIT_FREQ_HW_CTRL                                  ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_TIMERS2_CLK_RST */
#define BITS_FNCLKSEL292(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST294                                        ( BIT(2) )
#define BIT_FNCLK295                                      ( BIT(1) )
#define BIT_APBCLK296                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_TSEN_CLK_RST */
#define BIT_TSEN_RST_EN                                   ( BIT(2) )
#define BIT_TSEN_FCLK_EN                                  ( BIT(1) )
#define BIT_TSEN_PCLK_EN                                  ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_TWSI2_CLK_RST */
#define BITS_FNCLKSEL314(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST316                                        ( BIT(2) )
#define BIT_FNCLK317                                      ( BIT(1) )
#define BIT_APBCLK318                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_TWSI3_CLK_RST */
#define BITS_FNCLKSEL326(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST328                                        ( BIT(2) )
#define BIT_FNCLK329                                      ( BIT(1) )
#define BIT_APBCLK330                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_UART3_CLK_RST */
#define BITS_FNCLKSEL338(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST340                                        ( BIT(2) )
#define BIT_FNCLK341                                      ( BIT(1) )
#define BIT_APBCLK342                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_TWSI4_CLK_RST */
#define BITS_FNCLKSEL350(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST352                                        ( BIT(2) )
#define BIT_FNCLK353                                      ( BIT(1) )
#define BIT_APBCLK354                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_TWSI5_CLK_RST */
#define BITS_FNCLKSEL362(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST364                                        ( BIT(2) )
#define BIT_FNCLK365                                      ( BIT(1) )
#define BIT_APBCLK366                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_TWSI6_CLK_RST */
#define BITS_FNCLKSEL374(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST376                                        ( BIT(2) )
#define BIT_FNCLK377                                      ( BIT(1) )
#define BIT_APBCLK378                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_TWSI7_CLK_RST */
#define BITS_FNCLKSEL386(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST388                                        ( BIT(2) )
#define BIT_FNCLK389                                      ( BIT(1) )
#define BIT_APBCLK390                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_TWSI8_CLK_RST */
#define BITS_FNCLKSEL398(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST400                                        ( BIT(2) )
#define BIT_FNCLK401                                      ( BIT(1) )
#define BIT_APBCLK402                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_IPC_AP2AUD_CLK_RST */
#define BITS_FNCLKSEL410(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST412                                        ( BIT(2) )
#define BIT_FNCLK413                                      ( BIT(1) )
#define BIT_APBCLK414                                     ( BIT(0) )

/* bits definitions for register REG_APBC_APBC_I3C_CLK_RST */
#define BITS_FNCLKSEL422(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RST424                                        ( BIT(2) )
#define BIT_FNCLK425                                      ( BIT(1) )
#define BIT_APBCLK426                                     ( BIT(0) )

#endif
