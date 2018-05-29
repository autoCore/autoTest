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


#ifndef __H_REGS_GPBMODEM_HEADFILE_H__
#define __H_REGS_GPBMODEM_HEADFILE_H__ __FILE__

#define	REGS_GPBMODEM

/* registers definitions for GPBMODEM */
#define REG_GPBMODEM_GPB_MON_CTRL                         ASR_ADDR(REGS_GPBMODEM_BASE, 0X0)/*GPB Peripherals Monitor Control Register*/
#define REG_GPBMODEM_VIT_CLK_SELECT                       ASR_ADDR(REGS_GPBMODEM_BASE, 0X04)/*Viterbi Clock Control Register*/
#define REG_GPBMODEM_EQU_CLK_SELECT                       ASR_ADDR(REGS_GPBMODEM_BASE, 0X08)/*Equalizer Clock Control Register*/
#define REG_GPBMODEM_E_CIP_CLK_SELECT                     ASR_ADDR(REGS_GPBMODEM_BASE, 0X0C)/*E-Cipher Clock Control Register*/
#define REG_GPBMODEM_DSSP0_CLK_SELECT                     ASR_ADDR(REGS_GPBMODEM_BASE, 0X10)/*DSSP 0 Clock Control Register*/
#define REG_GPBMODEM_DSSP1_CLK_SELECT                     ASR_ADDR(REGS_GPBMODEM_BASE, 0X14)/*DSSP 1 Clock Control Register*/
#define REG_GPBMODEM_DSSP2_CLK_SELECT                     ASR_ADDR(REGS_GPBMODEM_BASE, 0X18)/*DSSP 2 Clock Control Register*/
#define REG_GPBMODEM_DSSP3_CLK_SELECT                     ASR_ADDR(REGS_GPBMODEM_BASE, 0X1C)/*DSSP 3 Clock Control Register*/
#define REG_GPBMODEM_GSSP_CLK_CTRL                        ASR_ADDR(REGS_GPBMODEM_BASE, 0X20)/*GSSP Clock Control Register*/
#define REG_GPBMODEM_TIMERS_CLK_CTRL                      ASR_ADDR(REGS_GPBMODEM_BASE, 0X24)/*GPB Timers Clock Control Register*/
#define REG_GPBMODEM_MIRQ_CLK_CTRL                        ASR_ADDR(REGS_GPBMODEM_BASE, 0X28)/*MIRQ Clock Control Register*/
#define REG_GPBMODEM_HSL_CLK_CTRL                         ASR_ADDR(REGS_GPBMODEM_BASE, 0X2C)/*HSL Clock Control Register*/
#define REG_GPBMODEM_WB_WAKE_UP_TCU_CTL                   ASR_ADDR(REGS_GPBMODEM_BASE, 0X34)/*WCDMA Wakeup TCU Control Register*/
#define REG_GPBMODEM_GMCGC                                ASR_ADDR(REGS_GPBMODEM_BASE, 0X50)/*GMCGC*/
#define REG_GPBMODEM_GMCGC_II                             ASR_ADDR(REGS_GPBMODEM_BASE, 0X54)/*GMCGC_II*/
#define REG_GPBMODEM_BACKWARD_COMP_MODE                   ASR_ADDR(REGS_GPBMODEM_BASE, 0X70)/*GPB Peripherals Backward Compatibility Select Control Register*/



/* bits definitions for register REG_GPBMODEM_GPB_MON_CTRL */
#define BITS_SEL(_X_)                                     ( (_X_) << 29 & (BIT(29)|BIT(30)|BIT(31)) )
#define BIT_MEN                                           ( BIT(16) )
#define BITS_PMS3(_X_)                                    ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_PMS2(_X_)                                    ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_PMS1(_X_)                                    ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_PMS0(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_GPBMODEM_VIT_CLK_SELECT */
#define BIT_GPBMO_SW_RESET32                              ( BIT(4) )
#define BITS_CLOCK_SELECT33(_X_)                          ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_GPBMO_CLOCK_ENABLE34                          ( BIT(1) )

/* bits definitions for register REG_GPBMODEM_EQU_CLK_SELECT */
#define BIT_GPBMO_SW_RESET43                              ( BIT(4) )
#define BITS_CLOCK_SELECT44(_X_)                          ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_GPBMO_CLOCK_ENABLE45                          ( BIT(1) )

/* bits definitions for register REG_GPBMODEM_E_CIP_CLK_SELECT */
#define BIT_GPBMO_SW_RESET54                              ( BIT(4) )
#define BITS_CLOCK_SELECT55(_X_)                          ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_GPBMO_CLOCK_ENABLE56                          ( BIT(1) )
#define BIT_26-MHZ_CLOCK_ENABLE                           ( BIT(0) )

/* bits definitions for register REG_GPBMODEM_DSSP0_CLK_SELECT */
#define BIT_GPBMO_SW_RESET65                              ( BIT(4) )
#define BITS_CLOCK_SELECT66(_X_)                          ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_FUNCTIONAL_CLOCK_ENABLE67                     ( BIT(1) )
#define BIT_GPBMO_BUS_CLOCK_ENABLE68                      ( BIT(0) )

/* bits definitions for register REG_GPBMODEM_DSSP1_CLK_SELECT */
#define BIT_GPBMO_SW_RESET76                              ( BIT(4) )
#define BITS_CLOCK_SELECT77(_X_)                          ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_FUNCTIONAL_CLOCK_ENABLE78                     ( BIT(1) )
#define BIT_GPBMO_BUS_CLOCK_ENABLE79                      ( BIT(0) )

/* bits definitions for register REG_GPBMODEM_DSSP2_CLK_SELECT */
#define BIT_GPBMO_SW_RESET87                              ( BIT(4) )
#define BITS_CLOCK_SELECT88(_X_)                          ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_FUNCTIONAL_CLOCK_ENABLE89                     ( BIT(1) )
#define BIT_GPBMO_BUS_CLOCK_ENABLE90                      ( BIT(0) )

/* bits definitions for register REG_GPBMODEM_DSSP3_CLK_SELECT */
#define BIT_GPBMO_SW_RESET98                              ( BIT(4) )
#define BITS_CLOCK_SELECT99(_X_)                          ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_FUNCTIONAL_CLOCK_ENABLE100                    ( BIT(1) )
#define BIT_GPBMO_BUS_CLOCK_ENABLE101                     ( BIT(0) )

/* bits definitions for register REG_GPBMODEM_GSSP_CLK_CTRL */
#define BIT_GPBMO_GSSP2_SW_RESET109                       ( BIT(9) )
#define BITS_GSSP2_CLOCK_SELECT(_X_)                      ( (_X_) << 7 & (BIT(7)|BIT(8)) )
#define BIT_GSSP2_FUNCTIONAL_CLOCK_ENABLE                 ( BIT(6) )
#define BIT_GPBMO_GSSP2_BUS_CLOCK_ENABLE112               ( BIT(5) )
#define BIT_GPBMO_GSSP1_SW_RESET113                       ( BIT(4) )
#define BITS_GSSP1_CLOCK_SELECT(_X_)                      ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_GSSP1_FUNCTIONAL_CLOCK_ENABLE                 ( BIT(1) )
#define BIT_GSSP1_BUS_CLOCK_ENABLE116                     ( BIT(0) )

/* bits definitions for register REG_GPBMODEM_TIMERS_CLK_CTRL */
#define BIT_GPBMO_SW_RESET124                             ( BIT(4) )
#define BIT_FUNCTIONAL_CLOCK_ENABLE126                    ( BIT(1) )
#define BIT_GPBMO_BUS_CLOCK_ENABLE127                     ( BIT(0) )

/* bits definitions for register REG_GPBMODEM_MIRQ_CLK_CTRL */
#define BIT_GPBMO_SW_RESET135                             ( BIT(4) )
#define BIT_FUNCTIONAL_CLOCK_ENABLE137                    ( BIT(0) )

/* bits definitions for register REG_GPBMODEM_HSL_CLK_CTRL */
#define BIT_GPBMO_SW_RESET145                             ( BIT(4) )
#define BIT_FUNCTIONAL_CLOCK_ENABLE147                    ( BIT(0) )

/* bits definitions for register REG_GPBMODEM_WB_WAKE_UP_TCU_CTL */
#define BIT_GWBWAKESEL155                                 ( BIT(1) )
#define BIT_GWBSLPEQEN156                                 ( BIT(0) )

/* bits definitions for register REG_GPBMODEM_GMCGC */
#define BIT_GWBWAKESEL163                                 ( BIT(31) )
#define BIT_GWBSLPEQEN164                                 ( BIT(30) )
#define BITS_VITERBI_FUNC_CLOCK_SELECT(_X_)               ( (_X_) << 21 & (BIT(21)|BIT(22)) )
#define BITS_EQUALIZER_FUNC_CLOCK_SELECT(_X_)             ( (_X_) << 19 & (BIT(19)|BIT(20)) )
#define BITS_E-CIPHER_FUNC_CLOCK_SELECT(_X_)              ( (_X_) << 17 & (BIT(17)|BIT(18)) )
#define BIT_DSSP0_FUNC_CLOCK_SELECT170                    ( BIT(15) )
#define BIT_DSSP1_FUNC_CLOCK_SELECT171                    ( BIT(14) )
#define BIT_DSSP2_FUNC_CLOCK_SELECT172                    ( BIT(13) )
#define BIT_DSSP3_FUNC_CLOCK_SELECT173                    ( BIT(12) )
#define BIT_E-CIPHER_26-MHZ_CLOCK_ENABLE                  ( BIT(10) )
#define BIT_E-CIPHER_FUNC_CLOCK_ENABLE                    ( BIT(9) )
#define BIT_VITERBI_FUNC_CLOCK_ENABLE                     ( BIT(8) )
#define BIT_EQUALIZER_FUNC_CLOCK_ENABLE                   ( BIT(7) )
#define BIT_DSSP3_FUNC_CLOCK_ENABLE                       ( BIT(6) )
#define BIT_DSSP2_FUNC_CLOCK_ENABLE                       ( BIT(5) )
#define BIT_DSSP1_FUNC_CLOCK_ENABLE                       ( BIT(4) )
#define BIT_DSSP0_FUNC_CLOCK_ENABLE                       ( BIT(3) )
#define BIT_MIRQ_FUNC_CLOCK_ENABLE                        ( BIT(2) )
#define BIT_TCU_FUNC_CLOCK_ENABLE                         ( BIT(1) )

/* bits definitions for register REG_GPBMODEM_GMCGC_II */
#define BITS_GSSP2_FUNC_CLOCK_SELECT(_X_)                 ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BIT_GSSP2_FUNC_CLOCK_ENABLE                       ( BIT(15) )
#define BIT_GPBMO_GSSP2_BUS_CLOCK_ENABLE195               ( BIT(14) )
#define BIT_DSSP3_BUS_CLOCK_ENABLE                        ( BIT(13) )
#define BIT_DSSP2_BUS_CLOCK_ENABLE                        ( BIT(12) )
#define BIT_DSSP1_BUS_CLOCK_ENABLE                        ( BIT(11) )
#define BIT_DSSP0_BUS_CLOCK_ENABLE                        ( BIT(10) )
#define BIT_TIMERS_BUS_CLOCK_ENABLE                       ( BIT(9) )
#define BIT_TIMERS_FUNC_CLOCK_ENABLE                      ( BIT(8) )
#define BIT_GSSP1_BUS_CLOCK_ENABLE202                     ( BIT(7) )
#define BIT_GSSP1_FUNC_CLOCK_ENABLE                       ( BIT(6) )
#define BIT_DSSP0_FUNC_CLOCK_SELECT204                    ( BIT(5) )
#define BIT_DSSP1_FUNC_CLOCK_SELECT205                    ( BIT(4) )
#define BIT_DSSP2_FUNC_CLOCK_SELECT206                    ( BIT(3) )
#define BIT_DSSP3_FUNC_CLOCK_SELECT207                    ( BIT(2) )
#define BITS_GSSP1_FUNC_CLOCK_SELECT(_X_)                 ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_GPBMODEM_BACKWARD_COMP_MODE */
#define BIT_BACKWARD_COMPATIBILITY_SELECT                 ( BIT(0) )

#endif
