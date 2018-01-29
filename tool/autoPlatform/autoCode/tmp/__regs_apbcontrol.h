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


#ifndef __H_REGS_APBCONTROL_HEADFILE_H__
#define __H_REGS_APBCONTROL_HEADFILE_H__ __FILE__

#define	REGS_APBCONTROL

/* registers definitions for APBCONTROL */
#define REG_APBCONTROL_TCTS                               ASR_ADDR(REGS_APBCONTROL_BASE, 0X00)/*TCU Clock Trigger Control Register*/
#define REG_APBCONTROL_THALT                              ASR_ADDR(REGS_APBCONTROL_BASE, 0X04)/*TCU HALT Mode Control Register*/
#define REG_APBCONTROL_GBS                                ASR_ADDR(REGS_APBCONTROL_BASE, 0X0C)/*GSSP Bus Interface Select Register*/
#define REG_APBCONTROL_APB_GAMPMCR                        ASR_ADDR(REGS_APBCONTROL_BASE, 0X10)/*APB CP Peripherals Monitor Control Register*/
#define REG_APBCONTROL_TCER                               ASR_ADDR(REGS_APBCONTROL_BASE, 0X14)/*TCU Clock Control Register*/
#define REG_APBCONTROL_ACER                               ASR_ADDR(REGS_APBCONTROL_BASE, 0X18)/*AIRQ Clock Control Register*/
#define REG_APBCONTROL_UCER                               ASR_ADDR(REGS_APBCONTROL_BASE, 0X1C)/*UART Clock Control Register*/
#define REG_APBCONTROL_USCER1                             ASR_ADDR(REGS_APBCONTROL_BASE, 0X20)/*USIM 1 Clock Control Register*/
#define REG_APBCONTROL_USCER2                             ASR_ADDR(REGS_APBCONTROL_BASE, 0X24)/*USIM 2 Clock Control Register*/
#define REG_APBCONTROL_ICER                               ASR_ADDR(REGS_APBCONTROL_BASE, 0X28)/*TWSI Clock Control Register*/
#define REG_APBCONTROL_ECCER                              ASR_ADDR(REGS_APBCONTROL_BASE, 0X2C)/*APB E-Cipher Clock Control Register*/
#define REG_APBCONTROL_TICER                              ASR_ADDR(REGS_APBCONTROL_BASE, 0X30)/*APB Timers Clock Control Register*/
#define REG_APBCONTROL_GCER                               ASR_ADDR(REGS_APBCONTROL_BASE, 0X34)/*GSSP Clock Control Register*/
#define REG_APBCONTROL_AICER                              ASR_ADDR(REGS_APBCONTROL_BASE, 0X38)/*IPC/RIPC Clock Control Register*/
#define REG_APBCONTROL_SCCR                               ASR_ADDR(REGS_APBCONTROL_BASE, 0X3C)/*Slow Clock Clock Control Register*/



/* bits definitions for register REG_APBCONTROL_TCTS */
#define BIT_TCU_CLOCK_TRIGGER_SELECT                      ( BIT(0) )

/* bits definitions for register REG_APBCONTROL_THALT */
#define BIT_TCU_HALT_MODE_SELECT                          ( BIT(0) )

/* bits definitions for register REG_APBCONTROL_GBS */
#define BIT_GSSP_BUS_SELECT                               ( BIT(0) )

/* bits definitions for register REG_APBCONTROL_APB_GAMPMCR */
#define BITS_TEST_POINT_OUTPUT_SELECT(_X_)                ( (_X_) << 29 & (BIT(29)|BIT(30)|BIT(31)) )
#define BIT_38                                            ( BIT(16) )
#define BITS_39(_X_)                                      ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_40(_X_)                                      ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_41(_X_)                                      ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_42(_X_)                                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_APBCONTROL_TCER */
#define BIT_SW_RESET50                                    ( BIT(2) )
#define BIT_CLOCK_ENABLE51                                ( BIT(1) )

/* bits definitions for register REG_APBCONTROL_ACER */
#define BIT_SW_RESET60                                    ( BIT(2) )
#define BIT_CLOCK_ENABLE61                                ( BIT(1) )

/* bits definitions for register REG_APBCONTROL_UCER */
#define BIT_SW_RESET70                                    ( BIT(2) )
#define BIT_CLOCK_ENABLE71                                ( BIT(1) )
#define BIT_BUS_CLOCK_ENABLE72                            ( BIT(0) )

/* bits definitions for register REG_APBCONTROL_USCER1 */
#define BIT_SW_RESET80                                    ( BIT(2) )
#define BIT_CLOCK_ENABLE81                                ( BIT(1) )
#define BIT_BUS_CLOCK_ENABLE82                            ( BIT(0) )

/* bits definitions for register REG_APBCONTROL_USCER2 */
#define BIT_SW_RESET90                                    ( BIT(2) )
#define BIT_CLOCK_ENABLE91                                ( BIT(1) )
#define BIT_BUS_CLOCK_ENABLE92                            ( BIT(0) )

/* bits definitions for register REG_APBCONTROL_ICER */
#define BITS_FN_SEL(_X_)                                  ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BIT_SW_RESET101                                   ( BIT(2) )
#define BIT_CLOCK_ENABLE102                               ( BIT(1) )
#define BIT_BUS_CLOCK_ENABLE103                           ( BIT(0) )

/* bits definitions for register REG_APBCONTROL_ECCER */
#define BIT_SW_RESET111                                   ( BIT(2) )
#define BIT_CLOCK_ENABLE112                               ( BIT(1) )

/* bits definitions for register REG_APBCONTROL_TICER */
#define BIT_SW_RESET121                                   ( BIT(2) )
#define BIT_CLOCK_ENABLE122                               ( BIT(1) )
#define BIT_BUS_CLOCK_ENABLE123                           ( BIT(0) )

/* bits definitions for register REG_APBCONTROL_GCER */
#define BITS_GSSP1_CLOCK_SEL(_X_)                         ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_GSSP2_CLOCK_SEL(_X_)                         ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_APBCO_GSSP2_SW_RESET133                       ( BIT(5) )
#define BIT_GSSP2_CLOCK_ENABLE                            ( BIT(4) )
#define BIT_APBCO_GSSP2_BUS_CLOCK_ENABLE135               ( BIT(3) )
#define BIT_APBCO_GSSP1_SW_RESET136                       ( BIT(2) )
#define BIT_GSSP1_CLOCK_ENABLE                            ( BIT(1) )
#define BIT_GSSP1BUS_CLOCK_ENABLE                         ( BIT(0) )

/* bits definitions for register REG_APBCONTROL_AICER */
#define BIT_SW_RESET146                                   ( BIT(2) )
#define BIT_CLOCK_ENABLE147                               ( BIT(1) )

/* bits definitions for register REG_APBCONTROL_SCCR */
#define BIT_156                                           ( BIT(4) )
#define BIT_SW_RESET158                                   ( BIT(2) )
#define BIT_CLOCK_ENABLE160                               ( BIT(1) )

#endif
