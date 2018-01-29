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


#ifndef __H_REGS_MAIN_HEADFILE_H__
#define __H_REGS_MAIN_HEADFILE_H__ __FILE__

#define	REGS_MAIN

/* registers definitions for MAIN */
#define REG_MAIN_CPSR                                     ASR_ADDR(REGS_MAIN_BASE, 0X0004)/*Marvell Seagull/Mohawk Power Status Register*/
#define REG_MAIN_FCCR                                     ASR_ADDR(REGS_MAIN_BASE, 0X0008)/*Frequency Change Control Register*/
#define REG_MAIN_POCR                                     ASR_ADDR(REGS_MAIN_BASE, 0X000C)/*PLL and Oscillator Control Register*/
#define REG_MAIN_POSR                                     ASR_ADDR(REGS_MAIN_BASE, 0X0010)/*PLL and Oscillator Status Register*/
#define REG_MAIN_SUCCR                                    ASR_ADDR(REGS_MAIN_BASE, 0X0014)/*Slow UART (UART 1) Clock Generation Control Register*/
#define REG_MAIN_VRCR                                     ASR_ADDR(REGS_MAIN_BASE, 0X0018)/*VCTCXO SW request Control Register*/
#define REG_MAIN_PLL3CR                                   ASR_ADDR(REGS_MAIN_BASE, 0X001C)/*PLL3 Control Register*/
#define REG_MAIN_CRSR                                     ASR_ADDR(REGS_MAIN_BASE, 0X0028)/*Marvell Seagull/Mohawk Reset Status Register*/
#define REG_MAIN_XDCR                                     ASR_ADDR(REGS_MAIN_BASE, 0X002C)/*Delay control register for WFSTATE*/
#define REG_MAIN_GPCR                                     ASR_ADDR(REGS_MAIN_BASE, 0X0030)/*General Purpose Clock Generation Control Register*/
#define REG_MAIN_PLL2CR                                   ASR_ADDR(REGS_MAIN_BASE, 0X0034)/*PLL2 Control Register*/
#define REG_MAIN_SCCR                                     ASR_ADDR(REGS_MAIN_BASE, 0X0038)/*Slow Clock Control Register*/
#define REG_MAIN_ISCCRx                                   ASR_ADDR(REGS_MAIN_BASE, 0X0040)/*I2S Clock Generation Control Register*/
#define REG_MAIN_PLL5CR                                   ASR_ADDR(REGS_MAIN_BASE, 0X004C)/*PLL5 Control Register*/
#define REG_MAIN_PLL4CR                                   ASR_ADDR(REGS_MAIN_BASE, 0X0050)/*PLL4 Control Register*/
#define REG_MAIN_FCAP                                     ASR_ADDR(REGS_MAIN_BASE, 0X0054)/*<var Processor: Application> Core Frequency Change Control Register*/
#define REG_MAIN_FCDCLK                                   ASR_ADDR(REGS_MAIN_BASE, 0X005C)/*DCLK Frequency Change Control Register*/
#define REG_MAIN_FCACLK                                   ASR_ADDR(REGS_MAIN_BASE, 0X0060)/*ACLK Frequency Change Control Register*/
#define REG_MAIN_DSOC                                     ASR_ADDR(REGS_MAIN_BASE, 0X0100)/*Debug Signals Output Control Register*/
#define REG_MAIN_WDTPCR                                   ASR_ADDR(REGS_MAIN_BASE, 0X0200)/*WDT (CP Timers) Control Register*/
#define REG_MAIN_RIPCCR                                   ASR_ADDR(REGS_MAIN_BASE, 0X0210)/*RIPC Control Register*/
#define REG_MAIN_DBG                                      ASR_ADDR(REGS_MAIN_BASE, 0X0214)/*DBG Register*/
#define REG_MAIN_APSLPW                                   ASR_ADDR(REGS_MAIN_BASE, 0X1000)/*Marvell Seagull/Mohawk Power Control Register*/
#define REG_MAIN_APSR                                     ASR_ADDR(REGS_MAIN_BASE, 0X1004)/*Marvell Seagull/Mohawk Power Status Register*/
#define REG_MAIN_APRR                                     ASR_ADDR(REGS_MAIN_BASE, 0X1020)/*Marvell Seagull/Mohawk Programmable Reset Register*/
#define REG_MAIN_ACGR                                     ASR_ADDR(REGS_MAIN_BASE, 0X1024)/*Marvell Seagull/Mohawk Clock Gating Register*/
#define REG_MAIN_ARSR                                     ASR_ADDR(REGS_MAIN_BASE, 0X1028)/*Marvell Seagull/Mohawk Reset Status Register*/
#define REG_MAIN_PWRMODE_STAUTS                           ASR_ADDR(REGS_MAIN_BASE, 0X1030)/*Power Mode Status Register*/
#define REG_MAIN_AWUCRS                                   ASR_ADDR(REGS_MAIN_BASE, 0X1048)/*Wakeup and Clock Resume Lines Status Register*/
#define REG_MAIN_AWUCRM                                   ASR_ADDR(REGS_MAIN_BASE, 0X104C)/*Wakeup and Clock Resume Lines Mask Register*/
#define REG_MAIN_APBCSCR                                  ASR_ADDR(REGS_MAIN_BASE, 0X1050)/*APB Clock Source Control Register*/
#define REG_MAIN_AWUCRS1                                  ASR_ADDR(REGS_MAIN_BASE, 0X1064)/*Wakeup and Clock Resume Lines Status Register1*/
#define REG_MAIN_SHGPIOCTRL                               ASR_ADDR(REGS_MAIN_BASE, 0X1080)/*Sensor hub GPIO control */
#define REG_MAIN_SGADDRMAP                                ASR_ADDR(REGS_MAIN_BASE, 0X1084)/*Marvell Seagull  Address Map*/
#define REG_MAIN_MSAADDRMAP                               ASR_ADDR(REGS_MAIN_BASE, 0X1088)/*MSA  Address Map*/
#define REG_MAIN_MSAMEMCTRL                               ASR_ADDR(REGS_MAIN_BASE, 0X1080)/*MSA Memory Control*/
#define REG_MAIN_APCR_CLUSTER0                            ASR_ADDR(REGS_MAIN_BASE, 0X1090)/*Marvell <var Processor: Application MP> Cluster 0 Power Control Register*/
#define REG_MAIN_APCR_CLUSTER1                            ASR_ADDR(REGS_MAIN_BASE, 0X1094)/*Marvell <var Processor: Application MP> Cluster 1 Power Control Register*/
#define REG_MAIN_APCR_CLUSTER2                            ASR_ADDR(REGS_MAIN_BASE, 0X109C)/*Marvell <var Processor: Application MP> Cluster 2 Power Control Register*/
#define REG_MAIN_APCR_PER                                 ASR_ADDR(REGS_MAIN_BASE, 0X1098)/*Marvell Peripheral 1 Power Control Register*/
#define REG_MAIN_SPRR                                     ASR_ADDR(REGS_MAIN_BASE, 0X3000)/*Marvell Secure Core Programmable Reset Register*/
#define REG_MAIN_CRMR                                     ASR_ADDR(REGS_MAIN_BASE, 0X1084)/*CR7 DDR address remap*/



/* bits definitions for register REG_MAIN_CPSR */
#define BIT_MAI_DSPIDL24                                  ( BIT(31) )
#define BIT_AP_IDLE25                                     ( BIT(30) )
#define BIT_MAI_SG_IDLE26                                 ( BIT(29) )
#define BIT_MAI_DSPAVL27                                  ( BIT(28) )
#define BIT_AP_WFI28                                      ( BIT(27) )
#define BIT_SG_WFI29                                      ( BIT(26) )
#define BIT_APOFF30                                       ( BIT(25) )
#define BIT_MAI_COMM_TOP_D231                             ( BIT(24) )
#define BITS_MAI_COMM_TOP_STATE33(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_MAIN_FCCR */
#define BIT_I2SCLKSEL                                     ( BIT(28) )
#define BITS_PLL1FBD44(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for register REG_MAIN_POCR */
#define BIT_FORCE                                         ( BIT(31) )
#define BITS_VCXOST(_X_)                                  ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_WAITPLLLOCKTIMEVALUE(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )

/* bits definitions for register REG_MAIN_POSR */
#define BIT_MAI_PLL1_LOCK63                               ( BIT(27) )
#define BITS_PLL2REFD(_X_)                                ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BITS_PLL2FBD(_X_)                                 ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BITS_PLL1FBD67(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for register REG_MAIN_SUCCR */
#define BITS_UARTDIVN(_X_)                                ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BITS_UARTDIVD(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )

/* bits definitions for register REG_MAIN_VRCR */
#define BITS_MAI_83(_X_)                                  ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_SW_REQ                                        ( BIT(8) )
#define BIT_MAI_85                                        ( BIT(7) )
#define BIT_REQ_POL2                                      ( BIT(6) )
#define BIT_REQ_POL1                                      ( BIT(5) )
#define BIT_REQ_POL0                                      ( BIT(4) )
#define BIT_MAI_89                                        ( BIT(3) )
#define BIT_REQ_EN2                                       ( BIT(2) )
#define BIT_REQ_EN1                                       ( BIT(1) )
#define BIT_REQ_EN0                                       ( BIT(0) )

/* bits definitions for register REG_MAIN_PLL3CR */
#define BITS_PLL3SSC_MODE(_X_)                            ( (_X_) << 30 & (BIT(30)|BIT(31)) )
#define BIT_MAI_SSC_FORCE_LOCK100                         ( BIT(29) )
#define BIT_MAI_SPRD_DEP_STEP101                          ( BIT(28) )
#define BITS_MAI_SPRD_DEP102(_X_)                         ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PLL3_PU                                       ( BIT(19) )
#define BITS_PLL3_FBDIV(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_PLL3_FRCDIV(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_MAIN_CRSR */
#define BITS_MAI_SWR116(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_MAI_WDTR118                                   ( BIT(2) )
#define BIT_MAI_EMR119                                    ( BIT(1) )
#define BIT_MAI_POR120                                    ( BIT(0) )

/* bits definitions for register REG_MAIN_XDCR */
#define BITS_XDCR_TIE4(_X_)                               ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_XDCR_TO2(_X_)                                ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_XDCR_TO1(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_MAIN_GPCR */
#define BITS_GPCDIVN(_X_)                                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_GPCDIVD(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_MAIN_PLL2CR */
#define BITS_PLL2SSC_MODE(_X_)                            ( (_X_) << 30 & (BIT(30)|BIT(31)) )
#define BIT_MAI_SSC_FORCE_LOCK145                         ( BIT(29) )
#define BIT_MAI_SPRD_DEP_STEP146                          ( BIT(28) )
#define BITS_MAI_SPRD_DEP147(_X_)                         ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PLL2_PU                                       ( BIT(19) )
#define BITS_PLL2_FBDIV(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_PLL2_FRCDIV(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_MAIN_SCCR */
#define BIT_BB_F_SLP_EN                                   ( BIT(2) )
#define BIT_AFE_CLK_EN                                    ( BIT(1) )
#define BIT_SCS                                           ( BIT(0) )

/* bits definitions for register REG_MAIN_ISCCRx */
#define BIT_MAI_SYSCLK_EN169                              ( BIT(31) )
#define BIT_MAI_SYSCLK_BASE170                            ( BIT(30) )
#define BIT_MAI_BITCLK_EN171                              ( BIT(29) )
#define BITS_MAI_BITCLK_DIV_468172(_X_)                   ( (_X_) << 27 & (BIT(27)|BIT(28)) )
#define BITS_MAI_DENOM173(_X_)                            ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )
#define BITS_MAI_NOM174(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for register REG_MAIN_PLL5CR */
#define BITS_PLL5SSC_MODE181(_X_)                         ( (_X_) << 30 & (BIT(30)|BIT(31)) )
#define BIT_MAI_SSC_FORCE_LOCK182                         ( BIT(29) )
#define BIT_MAI_SPRD_DEP_STEP183                          ( BIT(28) )
#define BITS_MAI_SPRD_DEP184(_X_)                         ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PLL5_PU                                       ( BIT(19) )
#define BITS_PLL5_FBDIV(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_PLL5_FRCDIV(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_MAIN_PLL4CR */
#define BITS_PLL5SSC_MODE196(_X_)                         ( (_X_) << 30 & (BIT(30)|BIT(31)) )
#define BIT_MAI_SSC_FORCE_LOCK197                         ( BIT(29) )
#define BIT_MAI_SPRD_DEP_STEP198                          ( BIT(28) )
#define BITS_MAI_SPRD_DEP199(_X_)                         ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PLL4_PU                                       ( BIT(19) )
#define BITS_PLL4_FBDIV(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_PLL4_FRCDIV(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_MAIN_FCAP */
#define BITS_C2_PLLSEL(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BITS_C1_PLLSEL(_X_)                               ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BITS_C0_PLLSEL(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_MAIN_FCDCLK */
#define BITS_MAI_DCLKSEL225(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_MAIN_FCACLK */
#define BIT_ACLKSEL                                       ( BIT(0) )

/* bits definitions for register REG_MAIN_DSOC */
#define BIT_TPCTL                                         ( BIT(8) )
#define BITS_TPSEL(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_MAIN_WDTPCR */
#define BITS_MAI_FNCLKSEL253(_X_)                         ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_MAI_RST255                                    ( BIT(2) )
#define BIT_MAI_FNCLK256                                  ( BIT(1) )
#define BIT_ABCLK                                         ( BIT(0) )

/* bits definitions for register REG_MAIN_RIPCCR */
#define BIT_MAI_RST265                                    ( BIT(2) )
#define BIT_MAI_APBCLK267                                 ( BIT(0) )

/* bits definitions for register REG_MAIN_DBG */
#define BIT_DBG_CP_AXI_ACCESS_MSK                         ( BIT(1) )
#define BIT_DBG_CP_DDR_ACCESS_MSK                         ( BIT(0) )

/* bits definitions for register REG_MAIN_APSLPW */
#define BIT_MAI_INTCLR285                                 ( BIT(24) )
#define BIT_MAI_SLPWP0286                                 ( BIT(23) )
#define BIT_MAI_SLPWP1287                                 ( BIT(22) )
#define BIT_MAI_SLPWP2288                                 ( BIT(21) )
#define BIT_MAI_SLPWP3289                                 ( BIT(20) )
#define BIT_MAI_SLPWP4291                                 ( BIT(18) )
#define BIT_MAI_SLPWP5292                                 ( BIT(17) )
#define BIT_MAI_SLPWP6293                                 ( BIT(16) )
#define BIT_MAI_SLPWP7294                                 ( BIT(15) )

/* bits definitions for register REG_MAIN_APSR */
#define BIT_MAI_DSPIDL303                                 ( BIT(31) )
#define BIT_AP_IDLE304                                    ( BIT(30) )
#define BIT_MAI_SG_IDLE305                                ( BIT(29) )
#define BIT_MAI_DSPAVL306                                 ( BIT(28) )
#define BIT_AP_WFI307                                     ( BIT(27) )
#define BIT_SG_WFI308                                     ( BIT(26) )
#define BIT_APOFF309                                      ( BIT(25) )
#define BIT_MAI_COMM_TOP_D2310                            ( BIT(24) )
#define BITS_MAI_COMM_TOP_STATE312(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_MAIN_APRR */
#define BIT_SGR_SEL                                       ( BIT(31) )
#define BIT_SGR_RST                                       ( BIT(30) )
#define BITS_SIRST_CNT(_X_)                               ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_RST_DONE                                      ( BIT(8) )
#define BIT_MAI_SLAVE_R324                                ( BIT(6) )
#define BIT_MAI_DSRAMINT325                               ( BIT(5) )
#define BIT_MAI_WDTR326                                   ( BIT(4) )
#define BIT_MAI_BBR327                                    ( BIT(3) )
#define BIT_MAI_DSPR328                                   ( BIT(2) )
#define BIT_MAI_APR329                                    ( BIT(1) )
#define BIT_MAI_CPR330                                    ( BIT(0) )

/* bits definitions for register REG_MAIN_ACGR */
#define BIT_MAI_WDT_13M339                                ( BIT(19) )
#define BIT_MAI_CLK_1248M341                              ( BIT(16) )
#define BIT_MAI_CLK_624M342                               ( BIT(15) )
#define BIT_MAI_CLK_832M343                               ( BIT(14) )
#define BIT_MAI_CLK_312M344                               ( BIT(13) )
#define BIT_MAI_CLK_104M345                               ( BIT(12) )
#define BIT_MAI_CLK_52M346                                ( BIT(11) )
#define BIT_MAI_CLK_48M347                                ( BIT(10) )
#define BIT_MAI_GPC348                                    ( BIT(9) )
#define BIT_MAI_AP_FUART349                               ( BIT(8) )
#define BIT_MAI_CLK_52M350                                ( BIT(7) )
#define BIT_MAI_AP_TWSI351                                ( BIT(6) )
#define BIT_MAI_CLK_208M352                               ( BIT(5) )
#define BIT_MAI_CLK_26M353                                ( BIT(4) )
#define BIT_MAI_CLK_13M354                                ( BIT(3) )
#define BIT_MAI_CLK_6.5M355                               ( BIT(2) )
#define BIT_MAI_AP_SUART356                               ( BIT(1) )
#define BIT_MAI_CLK_416M357                               ( BIT(0) )

/* bits definitions for register REG_MAIN_ARSR */
#define BITS_MAI_SWR366(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_MAI_WDTR368                                   ( BIT(2) )
#define BIT_MAI_EMR369                                    ( BIT(1) )
#define BIT_MAI_POR370                                    ( BIT(0) )

/* bits definitions for register REG_MAIN_PWRMODE_STAUTS */
#define BITS_PWRMODE_STATUS377(_X_)                       ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_PWRMODE_STATUS378(_X_)                       ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CLR_PWRMODE_STATUS(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_MAIN_AWUCRS */
#define BIT_MAI_BB_DROWSY_EN386                           ( BIT(31) )
#define BIT_MAI_BB_VCTCXO_REQ387                          ( BIT(30) )
#define BIT_MAI_MSA_WAKE_PM_BB_CLKRES388                  ( BIT(29) )
#define BIT_MAI_PM_CLKRES389                              ( BIT(28) )
#define BIT_MAI_GSM_WAKEUP390                             ( BIT(27) )
#define BIT_MAI_FB_WAKEUP391                              ( BIT(26) )
#define BIT_MAI_AP_ASYNC_INT392                           ( BIT(25) )
#define BIT_MAI_AP_FULL_IDLE393                           ( BIT(24) )
#define BIT_MAI_SDH1_AUDIO394                             ( BIT(23) )
#define BIT_MAI_SDH2395                                   ( BIT(22) )
#define BIT_MAI_KEYPRESS396                               ( BIT(21) )
#define BIT_MAI_TRACKBALL397                              ( BIT(20) )
#define BIT_MAI_NEWROTARY398                              ( BIT(19) )
#define BIT_MAI_WDT399                                    ( BIT(18) )
#define BIT_MAI_RTC_ALARM400                              ( BIT(17) )
#define BIT_MAI_CP_TIMER_3401                             ( BIT(16) )
#define BIT_MAI_CP_TIMER_2402                             ( BIT(15) )
#define BIT_MAI_CP_TIMER_1403                             ( BIT(14) )
#define BIT_MAI_AP1_TIMER_3404                            ( BIT(13) )
#define BIT_MAI_AP1_TIMER_2405                            ( BIT(12) )
#define BIT_MAI_AP1_TIMER_1406                            ( BIT(11) )
#define BIT_MAI_AP0_2_TIMER_3407                          ( BIT(10) )
#define BIT_MAI_AP0_2_TIMER_2408                          ( BIT(9) )
#define BIT_MAI_AP0_2_TIMER_1409                          ( BIT(8) )
#define BIT_MAI_WAKEUP7410                                ( BIT(7) )
#define BIT_MAI_WAKEUP6411                                ( BIT(6) )
#define BIT_MAI_WAKEUP5412                                ( BIT(5) )
#define BIT_MAI_WAKEUP4413                                ( BIT(4) )
#define BIT_MAI_WAKEUP3414                                ( BIT(3) )
#define BIT_MAI_WAKEUP2415                                ( BIT(2) )
#define BIT_MAI_WAKEUP1416                                ( BIT(1) )
#define BIT_MAI_WAKEUP0417                                ( BIT(0) )

/* bits definitions for register REG_MAIN_AWUCRM */
#define BIT_MAI_AUDIO_WAKEUP424                           ( BIT(31) )
#define BIT_MAI_AP_GT_WAKEUP425                           ( BIT(30) )
#define BIT_MAI_GSM_WAKEUPWMX426                          ( BIT(29) )
#define BIT_MAI_FB_WAKEUPX427                             ( BIT(28) )
#define BIT_MAI_GSM_WAKEUPWM428                           ( BIT(27) )
#define BIT_MAI_FB_WAKEUPWM429                            ( BIT(26) )
#define BIT_MAI_AP_ASYNC_INT430                           ( BIT(25) )
#define BIT_MAI_AP_FULL_IDLE431                           ( BIT(24) )
#define BIT_MAI_SDH1_AUDIO432                             ( BIT(23) )
#define BIT_MAI_SDH2433                                   ( BIT(22) )
#define BIT_MAI_KEYPRESS434                               ( BIT(21) )
#define BIT_MAI_TRACKBALL435                              ( BIT(20) )
#define BIT_MAI_NEWROTARY436                              ( BIT(19) )
#define BIT_MAI_WDT437                                    ( BIT(18) )
#define BIT_MAI_RTC_ALARM438                              ( BIT(17) )
#define BIT_MAI_CP_TIMER_3439                             ( BIT(16) )
#define BIT_MAI_CP_TIMER_2440                             ( BIT(15) )
#define BIT_MAI_CP_TIMER_1441                             ( BIT(14) )
#define BIT_MAI_AP1_TIMER_3442                            ( BIT(13) )
#define BIT_MAI_AP1_TIMER_2443                            ( BIT(12) )
#define BIT_MAI_AP1_TIMER_1444                            ( BIT(11) )
#define BIT_MAI_AP0_2_TIMER_3445                          ( BIT(10) )
#define BIT_MAI_AP0_2_TIMER_2446                          ( BIT(9) )
#define BIT_MAI_AP0_2_TIMER_1447                          ( BIT(8) )
#define BIT_MAI_WAKEUP7448                                ( BIT(7) )
#define BIT_MAI_WAKEUP6449                                ( BIT(6) )
#define BIT_MAI_WAKEUP5450                                ( BIT(5) )
#define BIT_MAI_WAKEUP4451                                ( BIT(4) )
#define BIT_MAI_WAKEUP3452                                ( BIT(3) )
#define BIT_MAI_WAKEUP2453                                ( BIT(2) )
#define BIT_MAI_WAKEUP1454                                ( BIT(1) )
#define BIT_MAI_WAKEUP0455                                ( BIT(0) )

/* bits definitions for register REG_MAIN_APBCSCR */
#define BIT_APB_52M                                       ( BIT(0) )

/* bits definitions for register REG_MAIN_AWUCRS1 */
#define BIT_MAI_AP_GT_WAKEUP472                           ( BIT(0) )

/* bits definitions for register REG_MAIN_SHGPIOCTRL */
#define BIT_BYPASS_SH_INT0                                ( BIT(31) )
#define BIT_SGADDRMAPEN481                                ( BIT(25) )
#define BIT_EN_PMIC_INT                                   ( BIT(24) )
#define BITS_GPIO_OUT_SEL(_X_)                            ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_INT_EN(_X_)                                  ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_INT_TYPE(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_MAIN_SGADDRMAP */
#define BIT_SGADDRMAPEN493                                ( BIT(16) )
#define BITS_SGADDRMAPTG(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_MAIN_MSAADDRMAP */
#define BIT_MSAADDRMAPEN                                  ( BIT(7) )
#define BITS_MSAADDRMAPTG(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_MAIN_MSAMEMCTRL */
#define BIT_SRAM_FUSE_REPAIR_CTRL                         ( BIT(31) )
#define BITS_MAI_GSRAM_WTC511(_X_)                        ( (_X_) << 29 & (BIT(29)|BIT(30)) )
#define BITS_MAI_GSRAM_RTC512(_X_)                        ( (_X_) << 27 & (BIT(27)|BIT(28)) )
#define BITS_MAI_GSRAM_ROM_RTC_REF513(_X_)                ( (_X_) << 25 & (BIT(25)|BIT(26)) )
#define BITS_MAI_GSRAM_ROM_RTC514(_X_)                    ( (_X_) << 22 & (BIT(22)|BIT(23)|BIT(24)) )
#define BITS_MAI_RESERVED515(_X_)                         ( (_X_) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PMU2GB_WAKEUP_EN                              ( BIT(21) )
#define BIT_MSA_L1_PDLVMC                                 ( BIT(20) )
#define BIT_MSA_L1_PDFVSSM                                ( BIT(19) )
#define BITS_MSA_L1_RTC_SACMEM(_X_)                       ( (_X_) << 17 & (BIT(17)|BIT(18)) )
#define BITS_MSA_L1_WTC_SACMEM(_X_)                       ( (_X_) << 15 & (BIT(15)|BIT(16)) )
#define BIT_MSA_TRANSACTION_FIX                           ( BIT(14) )
#define BIT_MSA_AIB_GB_L2_RATIO                           ( BIT(13) )
#define BITS_MSA_AIB_GB_L2_LATENCY(_X_)                   ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_CPSRAM_PDFVSSM                                ( BIT(8) )
#define BIT_CPSRAM_PDLVMC                                 ( BIT(7) )
#define BITS_CP_SRAM_WTC(_X_)                             ( (_X_) << 5 & (BIT(5)|BIT(6)) )
#define BITS_CP_SRAM_RTC(_X_)                             ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BIT_CP_SRAM_FIX_PRIOR0                            ( BIT(2) )
#define BIT_CP_SRAM_PIPE_MEM                              ( BIT(1) )
#define BIT_CP_SRAM_CLOCK_GATING                          ( BIT(0) )

/* bits definitions for register REG_MAIN_APCR_CLUSTER0 */
#define BIT_MAI_AXISDD538                                 ( BIT(31) )
#define BIT_MAI_DSPSD539                                  ( BIT(30) )
#define BIT_MAI_SLPEN540                                  ( BIT(29) )
#define BIT_MAI_DDRCORSD542                               ( BIT(27) )
#define BIT_MAI_APBSD543                                  ( BIT(26) )
#define BIT_MAI_BBSD544                                   ( BIT(25) )
#define BIT_MAI_VCTCXOSD546                               ( BIT(19) )
#define BIT_MAI_MSASLPEN548                               ( BIT(14) )
#define BIT_MAI_STBYEN549                                 ( BIT(13) )
#define BIT_LDMA_MASK551                                  ( BIT(3) )

/* bits definitions for register REG_MAIN_APCR_CLUSTER1 */
#define BIT_MAI_AXISDD560                                 ( BIT(31) )
#define BIT_MAI_DSPSD561                                  ( BIT(30) )
#define BIT_MAI_SLPEN562                                  ( BIT(29) )
#define BIT_MAI_DDRCORSD564                               ( BIT(27) )
#define BIT_MAI_APBSD565                                  ( BIT(26) )
#define BIT_MAI_BBSD566                                   ( BIT(25) )
#define BIT_MAI_VCTCXOSD568                               ( BIT(19) )
#define BIT_MAI_MSASLPEN570                               ( BIT(14) )
#define BIT_MAI_STBYEN571                                 ( BIT(13) )
#define BIT_LDMA_MASK573                                  ( BIT(3) )

/* bits definitions for register REG_MAIN_APCR_CLUSTER2 */
#define BIT_MAI_AXISDD583                                 ( BIT(31) )
#define BIT_MAI_DSPSD584                                  ( BIT(30) )
#define BIT_MAI_SLPEN585                                  ( BIT(29) )
#define BIT_MAI_DDRCORSD587                               ( BIT(27) )
#define BIT_MAI_APBSD588                                  ( BIT(26) )
#define BIT_MAI_BBSD589                                   ( BIT(25) )
#define BIT_MAI_VCTCXOSD591                               ( BIT(19) )
#define BIT_MAI_MSASLPEN593                               ( BIT(14) )
#define BIT_MAI_STBYEN594                                 ( BIT(13) )
#define BIT_LDMA_MASK596                                  ( BIT(3) )

/* bits definitions for register REG_MAIN_APCR_PER */
#define BIT_MAI_AXISDD606                                 ( BIT(31) )
#define BIT_MAI_DSPSD607                                  ( BIT(30) )
#define BIT_MAI_SLPEN608                                  ( BIT(29) )
#define BIT_MAI_DDRCORSD610                               ( BIT(27) )
#define BIT_MAI_APBSD611                                  ( BIT(26) )
#define BIT_MAI_BBSD612                                   ( BIT(25) )
#define BIT_MAI_VCTCXOSD614                               ( BIT(19) )
#define BIT_MAI_MSASLPEN616                               ( BIT(14) )
#define BIT_MAI_STBYEN617                                 ( BIT(13) )
#define BIT_LDMA_MASK619                                  ( BIT(3) )

/* bits definitions for register REG_MAIN_SPRR */
#define BIT_WDTRST                                        ( BIT(7) )
#define BIT_MAI_WDTR631                                   ( BIT(4) )
#define BIT_SPR                                           ( BIT(1) )
#define BIT_MAI_APR635                                    ( BIT(0) )

/* bits definitions for register REG_MAIN_CRMR */
#define BIT_LRME                                          ( BIT(24) )
#define BITS_LRMADDR(_X_)                                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BIT_CRME                                          ( BIT(8) )
#define BITS_CRMADDR(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

#endif
