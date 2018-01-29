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


#ifndef __H_REGS_APBAUX_HEADFILE_H__
#define __H_REGS_APBAUX_HEADFILE_H__ __FILE__

#define	REGS_APBAUX

/* registers definitions for APBAUX */
#define REG_APBAUX_COEL_APB_MSA_BOOT                      ASR_ADDR(REGS_APBAUX_BASE, 0X00000)/*MSA Boot Address Register*/
#define REG_APBAUX_APB_RF_CONT_MUX                        ASR_ADDR(REGS_APBAUX_BASE, 0X00008)/*Continuity Multiplexer Register*/
#define REG_APBAUX_COEL_APB_CLK_GATE                      ASR_ADDR(REGS_APBAUX_BASE, 0X0000C)/*Clock Gate Register*/
#define REG_APBAUX_COEL_APB_GSM_WB_CHOOSE                 ASR_ADDR(REGS_APBAUX_BASE, 0X00010)/*Select Active Sleep Timer Register*/
#define REG_APBAUX_COEL_APB_RTU_CLKEN                     ASR_ADDR(REGS_APBAUX_BASE, 0X00014)/*RTU Clock Enable Register*/
#define REG_APBAUX_COEL_APB_SPARE1                        ASR_ADDR(REGS_APBAUX_BASE, 0X00018)/*APB Spare Register 1*/
#define REG_APBAUX_COEL_APB_SPARE2                        ASR_ADDR(REGS_APBAUX_BASE, 0X0001C)/*APB Spare Register 2*/
#define REG_APBAUX_COEL_APB_CONTROL                       ASR_ADDR(REGS_APBAUX_BASE, 0X00020)/*APB Control Register*/
#define REG_APBAUX_GSRAM_CP_AP_SEL                        ASR_ADDR(REGS_APBAUX_BASE, 0X20000)/*GSRAM Shared Memory Control Register*/
#define REG_APBAUX_SENSOR_V18_OUT_REG                     ASR_ADDR(REGS_APBAUX_BASE, 0X2000C)/*V18 Sensor Output Register*/



/* bits definitions for register REG_APBAUX_COEL_APB_MSA_BOOT */
#define BITS_MSA_BOOT(_X_)                                (_X_)

/* bits definitions for register REG_APBAUX_APB_RF_CONT_MUX */
#define BIT_RF_CONT_MUX_9                                 ( BIT(9) )
#define BIT_RF_CONT_MUX_8                                 ( BIT(8) )
#define BIT_RF_CONT_MUX_7                                 ( BIT(7) )
#define BIT_RF_CONT_MUX_6                                 ( BIT(6) )
#define BIT_RF_CONT_MUX_5                                 ( BIT(5) )
#define BIT_RF_CONT_MUX_4                                 ( BIT(4) )
#define BIT_RF_CONT_MUX_3                                 ( BIT(3) )
#define BIT_RF_CONT_MUX_2                                 ( BIT(2) )
#define BIT_RF_CONT_MUX_1                                 ( BIT(1) )
#define BIT_RF_CONT_MUX_0                                 ( BIT(0) )

/* bits definitions for register REG_APBAUX_COEL_APB_CLK_GATE */
#define BIT_DTC_SW_RESET                                  ( BIT(1) )
#define BIT_DTC_GATE                                      ( BIT(0) )

/* bits definitions for register REG_APBAUX_COEL_APB_GSM_WB_CHOOSE */
#define BIT_GSM_WB_CHOOSE                                 ( BIT(0) )

/* bits definitions for register REG_APBAUX_COEL_APB_RTU_CLKEN */
#define BIT_RTU_CLK_EN                                    ( BIT(0) )

/* bits definitions for register REG_APBAUX_COEL_APB_SPARE1 */
#define BIT_CG_SW_EN                                      ( BIT(10) )
#define BITS_SHUTDOWN_CLK_AROUND_RST_PARAM(_X_)           ( (_X_) << 7 & (BIT(7)|BIT(8)|BIT(9)) )
#define BIT_SHUTDOWN_CLK_AROUND_RST_BYPASS_CTRL           ( BIT(6) )
#define BIT_APB_GB_L2_CTRL_SEL                            ( BIT(5) )
#define BIT_APB_GB_L2_RATIO                               ( BIT(4) )
#define BITS_APB_GB_L2_LATENCY(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_APBAUX_COEL_APB_SPARE2 */
#define BIT_FB_WAKEUP_STICKY_CLR                          ( BIT(13) )
#define BIT_FB_WAKEUP_MASK                                ( BIT(11) )
#define BIT_D2_WAKEUP_MASK                                ( BIT(10) )
#define BITS_GB_GATER_DELAY(_X_)                          ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BITS_GB_GATER_SW_CTRL(_X_)                        ( (_X_) << 1 & (BIT(1)|BIT(2)) )
#define BIT_GBM_GATER_SW_CTRL                             ( BIT(0) )

/* bits definitions for register REG_APBAUX_COEL_APB_CONTROL */
#define BITS_APB_EXT_CYCLE_NUM(_X_)                       ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_COEL_APB_EXT_IF2                              ( BIT(2) )
#define BITS_COEL_APB_EXT_IF1(_X_)                        ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_APBAUX_GSRAM_CP_AP_SEL */
#define BIT_GSRAM_CNTL                                    ( BIT(0) )

/* bits definitions for register REG_APBAUX_SENSOR_V18_OUT_REG */
#define BIT_V18_OUT_SENSOR_CNT                            ( BIT(0) )

#endif
