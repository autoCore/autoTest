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


#ifndef __H_REGS_DVC_HEADFILE_H__
#define __H_REGS_DVC_HEADFILE_H__ __FILE__

#define	REGS_DVC

/* registers definitions for DVC */
#define REG_DVC_DVCR                                      ASR_ADDR(REGS_DVC_BASE, 0X2000)/*Dynamic Voltage Change Control Register*/
#define REG_DVC_DVC_AP                                    ASR_ADDR(REGS_DVC_BASE, 0X2020)/*<var Processor: Application MP>  Dynamic Voltage Change Register*/
#define REG_DVC_DVC_APSUB                                 ASR_ADDR(REGS_DVC_BASE, 0X202C)/*AP Subsystem Dynamic Voltage Change Register*/
#define REG_DVC_DVC_CHIP                                  ASR_ADDR(REGS_DVC_BASE, 0X2030)/*Chip Top Dynamic Voltage Change Register*/
#define REG_DVC_DVC_STATUS                                ASR_ADDR(REGS_DVC_BASE, 0X2040)/*Dynamic Voltage Change Status Register*/
#define REG_DVC_DVC_IMR                                   ASR_ADDR(REGS_DVC_BASE, 0X2050)/* DVC Interrupt Mask Register*/
#define REG_DVC_DVC_ISR                                   ASR_ADDR(REGS_DVC_BASE, 0X2054)/* DVC Interrupt Status Register*/
#define REG_DVC_DVC_DEBUG                                 ASR_ADDR(REGS_DVC_BASE, 0X2058)/* DVC Debug Register*/
#define REG_DVC_DVC_EXTRA_STR                             ASR_ADDR(REGS_DVC_BASE, 0X205C)/*DVC Extra Stable Time Register*/
#define REG_DVC_VL01STR                                   ASR_ADDR(REGS_DVC_BASE, 0X2060)/*Voltage Level 0 to Level 1 Stable Time Register*/
#define REG_DVC_VL12STR                                   ASR_ADDR(REGS_DVC_BASE, 0X2064)/*Voltage Level 1 to Level 2 Stable Time Register*/
#define REG_DVC_VL23STR                                   ASR_ADDR(REGS_DVC_BASE, 0X2068)/*Voltage Level 2 to Level 3 Stable Time Register*/
#define REG_DVC_VL34STR                                   ASR_ADDR(REGS_DVC_BASE, 0X206C)/*Voltage Level 3 to Level 4 Stable Time Register*/
#define REG_DVC_VL45STR                                   ASR_ADDR(REGS_DVC_BASE, 0X2070)/*Voltage Level 4 to Level  5 Stable Time Register*/
#define REG_DVC_VL56STR                                   ASR_ADDR(REGS_DVC_BASE, 0X2074)/*Voltage Level 5 to Level  6 Stable Time Register*/
#define REG_DVC_VL67STR                                   ASR_ADDR(REGS_DVC_BASE, 0X2078)/*Voltage Level 6 to Level  7 Stable Time Register*/
#define REG_DVC_VL78STR                                   ASR_ADDR(REGS_DVC_BASE, 0X207C)/*Voltage Level 7 to Level  8 Stable Time Register*/
#define REG_DVC_VL89STR                                   ASR_ADDR(REGS_DVC_BASE, 0X2080)/*Voltage Level 8 to Level 9 Stable Time Register*/
#define REG_DVC_VL910STR                                  ASR_ADDR(REGS_DVC_BASE, 0X2084)/*Voltage Level 9 to Level  10 Stable Time Register*/
#define REG_DVC_VL1011STR                                 ASR_ADDR(REGS_DVC_BASE, 0X2088)/*Voltage Level 10 to Level 11 Stable Time Register*/
#define REG_DVC_VL1112STR                                 ASR_ADDR(REGS_DVC_BASE, 0X208C)/*Voltage Level 11 to Level  12 Stable Time Register*/
#define REG_DVC_VL1213STR                                 ASR_ADDR(REGS_DVC_BASE, 0X2090)/*Voltage Level 12 to Level  13 Stable Time Register*/
#define REG_DVC_VL1314STR                                 ASR_ADDR(REGS_DVC_BASE, 0X2094)/*Voltage Level 13 to Level  14 Stable Time Register*/
#define REG_DVC_VL1415STR                                 ASR_ADDR(REGS_DVC_BASE, 0X2098)/*Voltage Level 14 to Level  15 Stable Time Register*/



/* bits definitions for register REG_DVC_DVCR */
#define BIT_VC_EN                                         ( BIT(1) )
#define BIT_DV_LPM_AVC_EN16                               ( BIT(0) )

/* bits definitions for register REG_DVC_DVC_AP */
#define BITS_C2_VL3:0(_X_)                                ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_PERI_VL3:0(_X_)                              ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_C1_VL3:0(_X_)                                ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_DV_VC_REQ27                                   ( BIT(15) )
#define BITS_C0_VL3:0(_X_)                                ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_C2_LPM_AVC_EN                                 ( BIT(7) )
#define BIT_C1_LPM_AVC_EN                                 ( BIT(6) )
#define BIT_C0_LPM_AVC_EN                                 ( BIT(5) )
#define BITS_DV_LPM_VL3:034(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DVC_DVC_APSUB */
#define BIT_UDR_AP_SLP_AVC_EN                             ( BIT(31) )
#define BITS_UDR_AP_SLP_VL(_X_)                           ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_NUDR_AP_SLP_AVC_EN                            ( BIT(23) )
#define BITS_NUDR_AP_SLP_VL(_X_)                          ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_IDLE_DDROFF_AVC_EN                         ( BIT(15) )
#define BITS_AP_IDLE_DDROFF_VL(_X_)                       ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_IDLE_DDRON_AVC_EN                          ( BIT(7) )
#define BITS_AP_IDLE_DDRON_VL(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DVC_DVC_CHIP */
#define BIT_UDR_SLP_AVC_EN                                ( BIT(15) )
#define BITS_UDR_SLP_VL(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_NUDR_SLP_AVC_EN                               ( BIT(7) )
#define BITS_NUDR_SLP_VL(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DVC_DVC_STATUS */
#define BITS_DV_CAUSE73(_X_)                              ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_DV_TVL3:075(_X_)                             ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_DV_CVL3:077(_X_)                             ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DV_DVC_STATUS79                               ( BIT(0) )

/* bits definitions for register REG_DVC_DVC_IMR */
#define BIT_AP_VC_DONE_INTR_MASK                          ( BIT(0) )

/* bits definitions for register REG_DVC_DVC_ISR */
#define BIT_AP_VC_DONE_INTR_ISR                           ( BIT(0) )

/* bits definitions for register REG_DVC_DVC_DEBUG */
#define BIT_TOP_REDUN_FUSE_LOAD_DONE_MASK                 ( BIT(2) )
#define BIT_CNT_DIS_FOR_VL_DWN                            ( BIT(1) )
#define BIT_M_DVC_CHECK_MASK                              ( BIT(0) )

/* bits definitions for register REG_DVC_DVC_EXTRA_STR */
#define BITS_DVC_EXTRA_STR(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL01STR */
#define BITS_VL56_ST121(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL12STR */
#define BITS_VL56_ST130(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL23STR */
#define BITS_VL56_ST138(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL34STR */
#define BITS_VL56_ST147(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL45STR */
#define BITS_VL78_ST155(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL56STR */
#define BITS_VL78_ST163(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL67STR */
#define BITS_VL78_ST171(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL78STR */
#define BITS_VL78_ST179(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL89STR */
#define BITS_VL89_ST(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL910STR */
#define BITS_VL910_ST(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL1011STR */
#define BITS_VL1011_ST(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL1112STR */
#define BITS_VL1112_ST(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL1213STR */
#define BITS_VL1213_ST(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL1314STR */
#define BITS_VL1314_ST(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DVC_VL1415STR */
#define BITS_VL1415_ST(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

#endif
