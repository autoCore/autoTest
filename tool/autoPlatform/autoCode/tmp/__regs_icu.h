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


#ifndef __H_REGS_ICU_HEADFILE_H__
#define __H_REGS_ICU_HEADFILE_H__ __FILE__

#define	REGS_ICU

/* registers definitions for ICU */
#define REG_ICU_ICU_CFG_x_0                               ASR_ADDR(REGS_ICU_BASE, 0X000)/*Interrupt 0 to 63 Configuration Registers*/
#define REG_ICU_ICU_CFG_x_1                               ASR_ADDR(REGS_ICU_BASE, 0X100)/*Interrupt 64 to 127 Configuration Registers*/
#define REG_ICU_ICU_INT_STATUS_0                          ASR_ADDR(REGS_ICU_BASE, 0X200)/*Interrupt Status Register 0*/
#define REG_ICU_ICU_INT_STATUS_1                          ASR_ADDR(REGS_ICU_BASE, 0X204)/*Interrupt Status Register 1*/
#define REG_ICU_ICU_INT_STATUS_2                          ASR_ADDR(REGS_ICU_BASE, 0X208)/*Interrupt Status Register 2*/
#define REG_ICU_ICU_INT_STATUS_3                          ASR_ADDR(REGS_ICU_BASE, 0X20C)/*Interrupt Status Register 3*/
#define REG_ICU_ICU_APc0_FIQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X220)/*APc0 FIQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc0_IRQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X224)/*APc0 IRQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc0_GBL_INT_MSK                      ASR_ADDR(REGS_ICU_BASE, 0X228)/*APc0 Global Interrupt Mask Register*/
#define REG_ICU_ICU_APc1_FIQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X230)/*APc1 FIQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc1_IRQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X234)/*APc1 IRQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc1_GBL_INT_MSK                      ASR_ADDR(REGS_ICU_BASE, 0X238)/*APc1 Global Interrupt Mask Register*/
#define REG_ICU_ICU_APc2_FIQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X240)/*APc2 FIQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc2_IRQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X244)/*APc2 IRQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc2_GBL_INT_MSK                      ASR_ADDR(REGS_ICU_BASE, 0X248)/*APc2 Global Interrupt Mask Register*/
#define REG_ICU_ICU_APc3_FIQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X250)/*APc3 FIQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc3_IRQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X254)/*APc3 IRQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc3_GBL_INT_MSK                      ASR_ADDR(REGS_ICU_BASE, 0X258)/*APc3 Global Interrupt Mask Register*/
#define REG_ICU_ICU_APc4_FIQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X270)/*APc4 FIQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc4_IRQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X274)/*APc4 IRQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc4_GBL_INT_MSK                      ASR_ADDR(REGS_ICU_BASE, 0X278)/*APc4 Global Interrupt Mask Register*/
#define REG_ICU_ICU_APc5_FIQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X280)/*APc5 FIQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc5_IRQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X284)/*APc5 IRQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc5_GBL_INT_MSK                      ASR_ADDR(REGS_ICU_BASE, 0X288)/*APc5 Global Interrupt Mask Register*/
#define REG_ICU_ICU_APc6_FIQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X290)/*APc6 FIQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc6_IRQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X294)/*APc6 IRQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc6_GBL_INT_MSK                      ASR_ADDR(REGS_ICU_BASE, 0X298)/*APc6 Global Interrupt Mask Register*/
#define REG_ICU_ICU_APc7_FIQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X2A0)/*APc7 FIQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc7_IRQ_NUM                          ASR_ADDR(REGS_ICU_BASE, 0X2A4)/*APc7 IRQ Selected Interrupt Number Register*/
#define REG_ICU_ICU_APc7_GBL_INT_MSK                      ASR_ADDR(REGS_ICU_BASE, 0X2A8)/*APc7 Global Interrupt Mask Register*/
#define REG_ICU_ICU_ARM_INT_STATUS                        ASR_ADDR(REGS_ICU_BASE, 0X300)
#define REG_ICU_ICU_ARM_INT_MSK                           ASR_ADDR(REGS_ICU_BASE, 0X304)/*ARM Interrupt Mask Register*/
#define REG_ICU_CP_WDT_INT_CLR                            ASR_ADDR(REGS_ICU_BASE, 0X308)/*CP WDT interrupt clear*/
#define REG_ICU_ICU_INT_WAKEUP_MASK                       ASR_ADDR(REGS_ICU_BASE, 0X30C)/*ICU Interrupt Wakeup Mask*/
#define REG_ICU_ICU_DMA_NON_SEC_AP_CORES_INT_ST           ASR_ADDR(REGS_ICU_BASE, 0X318)/*DMA Non-secure Interrupt to AP Cores Status Register*/
#define REG_ICU_ICU_DMA_NON_SEC_AP_INT_MSK                ASR_ADDR(REGS_ICU_BASE, 0X31C)/*DMA Non-secure Interrupt to AP Cores Mask Register*/
#define REG_ICU_ICU_DMA_SEC_AP_CORES_INT_ST               ASR_ADDR(REGS_ICU_BASE, 0X320)/*DMA Secure Interrupt to AP Cores Status Register*/
#define REG_ICU_ICU_DMA_SEC_AP_INT_MSK                    ASR_ADDR(REGS_ICU_BASE, 0X324)/*DMA Secure Interrupt to AP Cores Mask Register*/



/* bits definitions for register REG_ICU_ICU_CFG_x_0 */
#define BIT_CPU7_INT16                                    ( BIT(14) )
#define BIT_CPU6_INT17                                    ( BIT(13) )
#define BIT_CPU5_INT18                                    ( BIT(12) )
#define BIT_CPU4_INT19                                    ( BIT(11) )
#define BIT_CPU3_INT21                                    ( BIT(9) )
#define BIT_CPU2_INT22                                    ( BIT(8) )
#define BIT_CPU1_INT23                                    ( BIT(7) )
#define BIT_CPU0_INT24                                    ( BIT(6) )
#define BIT_IRQ_FIQ26                                     ( BIT(4) )
#define BITS_PRIORITY_MASKING27(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_ICU_ICU_CFG_x_1 */
#define BIT_CPU7_INT36                                    ( BIT(14) )
#define BIT_CPU6_INT37                                    ( BIT(13) )
#define BIT_CPU5_INT38                                    ( BIT(12) )
#define BIT_CPU4_INT39                                    ( BIT(11) )
#define BIT_CPU3_INT41                                    ( BIT(9) )
#define BIT_CPU2_INT42                                    ( BIT(8) )
#define BIT_CPU1_INT43                                    ( BIT(7) )
#define BIT_CPU0_INT44                                    ( BIT(6) )
#define BIT_IRQ_FIQ46                                     ( BIT(4) )
#define BITS_PRIORITY_MASKING47(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_ICU_ICU_INT_STATUS_0 */
#define BITS_INT_STATUS_0(_X_)                            (_X_)

/* bits definitions for register REG_ICU_ICU_INT_STATUS_1 */
#define BITS_INT_STATUS_1(_X_)                            (_X_)

/* bits definitions for register REG_ICU_ICU_INT_STATUS_2 */
#define BITS_INT_STATUS_2(_X_)                            (_X_)

/* bits definitions for register REG_ICU_ICU_INT_STATUS_3 */
#define BITS_INT_STATUS_3(_X_)                            (_X_)

/* bits definitions for register REG_ICU_ICU_APc0_FIQ_NUM */
#define BIT_INT_PENDING83                                 ( BIT(7) )
#define BITS_SEL_INT_NUM84(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc0_IRQ_NUM */
#define BIT_INT_PENDING92                                 ( BIT(7) )
#define BITS_SEL_INT_NUM93(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc0_GBL_INT_MSK */
#define BIT_IRQ_MSK101                                    ( BIT(1) )
#define BIT_FIQ_MSK102                                    ( BIT(0) )

/* bits definitions for register REG_ICU_ICU_APc1_FIQ_NUM */
#define BIT_INT_PENDING110                                ( BIT(7) )
#define BITS_SEL_INT_NUM111(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc1_IRQ_NUM */
#define BIT_INT_PENDING119                                ( BIT(7) )
#define BITS_SEL_INT_NUM120(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc1_GBL_INT_MSK */
#define BIT_IRQ_MSK128                                    ( BIT(1) )
#define BIT_FIQ_MSK129                                    ( BIT(0) )

/* bits definitions for register REG_ICU_ICU_APc2_FIQ_NUM */
#define BIT_INT_PENDING137                                ( BIT(7) )
#define BITS_SEL_INT_NUM138(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc2_IRQ_NUM */
#define BIT_INT_PENDING146                                ( BIT(7) )
#define BITS_SEL_INT_NUM147(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc2_GBL_INT_MSK */
#define BIT_IRQ_MSK155                                    ( BIT(1) )
#define BIT_FIQ_MSK156                                    ( BIT(0) )

/* bits definitions for register REG_ICU_ICU_APc3_FIQ_NUM */
#define BIT_INT_PENDING164                                ( BIT(7) )
#define BITS_SEL_INT_NUM165(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc3_IRQ_NUM */
#define BIT_INT_PENDING173                                ( BIT(7) )
#define BITS_SEL_INT_NUM174(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc3_GBL_INT_MSK */
#define BIT_IRQ_MSK182                                    ( BIT(1) )
#define BIT_FIQ_MSK183                                    ( BIT(0) )

/* bits definitions for register REG_ICU_ICU_APc4_FIQ_NUM */
#define BIT_INT_PENDING191                                ( BIT(7) )
#define BITS_SEL_INT_NUM192(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc4_IRQ_NUM */
#define BIT_INT_PENDING200                                ( BIT(7) )
#define BITS_SEL_INT_NUM201(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc4_GBL_INT_MSK */
#define BIT_IRQ_MSK209                                    ( BIT(1) )
#define BIT_FIQ_MSK210                                    ( BIT(0) )

/* bits definitions for register REG_ICU_ICU_APc5_FIQ_NUM */
#define BIT_INT_PENDING218                                ( BIT(7) )
#define BITS_SEL_INT_NUM219(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc5_IRQ_NUM */
#define BIT_INT_PENDING227                                ( BIT(7) )
#define BITS_SEL_INT_NUM228(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc5_GBL_INT_MSK */
#define BIT_IRQ_MSK236                                    ( BIT(1) )
#define BIT_FIQ_MSK237                                    ( BIT(0) )

/* bits definitions for register REG_ICU_ICU_APc6_FIQ_NUM */
#define BIT_INT_PENDING245                                ( BIT(7) )
#define BITS_SEL_INT_NUM246(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc6_IRQ_NUM */
#define BIT_INT_PENDING254                                ( BIT(7) )
#define BITS_SEL_INT_NUM255(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc6_GBL_INT_MSK */
#define BIT_IRQ_MSK263                                    ( BIT(1) )
#define BIT_FIQ_MSK264                                    ( BIT(0) )

/* bits definitions for register REG_ICU_ICU_APc7_FIQ_NUM */
#define BIT_INT_PENDING272                                ( BIT(7) )
#define BITS_SEL_INT_NUM273(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc7_IRQ_NUM */
#define BIT_INT_PENDING281                                ( BIT(7) )
#define BITS_SEL_INT_NUM282(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ICU_ICU_APc7_GBL_INT_MSK */
#define BIT_IRQ_MSK290                                    ( BIT(1) )
#define BIT_FIQ_MSK291                                    ( BIT(0) )

/* bits definitions for register REG_ICU_ICU_ARM_INT_STATUS */
#define BIT_AP_L2_INT_STATUS                              ( BIT(25) )
#define BITS_AP_C2_COMMIRQ_STATUS(_X_)                    ( (_X_) << 23 & (BIT(23)|BIT(24)) )
#define BIT_AP_C2_AXIERR_STATUS                           ( BIT(22) )
#define BITS_CCI_EVNTCNTOVERFLOW_STATUS(_X_)              ( (_X_) << 14 & (BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_CCI_ERRORIRQ_STATUS                           ( BIT(13) )
#define BITS_AP_C1_COMMIRQ_STATUS(_X_)                    ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_AP_C1_AXIERR_STATUS                           ( BIT(8) )
#define BITS_AP_C0_COMMIRQ_STATUS(_X_)                    ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_C0_AXIERR_STATUS                           ( BIT(3) )
#define BIT_CP_L2_UECC_INT_STATUS                         ( BIT(2) )
#define BIT_CP_L2_ECC_INT_STATUS                          ( BIT(1) )
#define BIT_CP_L2_PA_ECC_INT_STATUS                       ( BIT(0) )

/* bits definitions for register REG_ICU_ICU_ARM_INT_MSK */
#define BIT_AP_L2_INT_MASK                                ( BIT(25) )
#define BITS_AP_C2_COMMIRQ_MASK(_X_)                      ( (_X_) << 23 & (BIT(23)|BIT(24)) )
#define BIT_AP_C2_AXIERR_MASK                             ( BIT(22) )
#define BITS_CCI_EVNTCNTOVERFLOW_MASK(_X_)                ( (_X_) << 14 & (BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_CCI_ERRORIRQ_MASK                             ( BIT(13) )
#define BITS_AP_C1_COMMIRQ_MASK(_X_)                      ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_AP_C1_AXIERR_MASK                             ( BIT(8) )
#define BITS_AP_C0_COMMIRQ_MASK(_X_)                      ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_C0_AXIERR_MASK                             ( BIT(3) )
#define BIT_CP_L2_UECC_INT_MSK                            ( BIT(2) )
#define BIT_CP_L2_ECC_INT_MSK                             ( BIT(1) )
#define BIT_CP_L2_PA_ECC_INT_MSK                          ( BIT(0) )

/* bits definitions for register REG_ICU_CP_WDT_INT_CLR */
#define BIT_CP_WDT_INT_AP_CLR                             ( BIT(1) )
#define BIT_CP_WDT_INT_SENSE                              ( BIT(0) )

/* bits definitions for register REG_ICU_ICU_INT_WAKEUP_MASK */
#define BIT_ICU_INT_WAKEUP_TO_AP_CORE9_MSK                ( BIT(11) )
#define BIT_ICU_INT_WAKEUP_TO_AP_CORE8_MSK                ( BIT(10) )
#define BIT_ICU_INT_WAKEUP_TO_AP_CORE7_MSK                ( BIT(9) )
#define BIT_ICU_INT_WAKEUP_TO_AP_CORE6_MSK                ( BIT(8) )
#define BIT_ICU_INT_WAKEUP_TO_AP_CORE5_MSK                ( BIT(7) )
#define BIT_ICU_INT_WAKEUP_TO_AP_CORE4_MSK                ( BIT(6) )
#define BIT_ICU_INT_WAKEUP_TO_AP_CORE3_MSK                ( BIT(4) )
#define BIT_ICU_INT_WAKEUP_TO_AP_CORE2_MSK                ( BIT(3) )
#define BIT_ICU_INT_WAKEUP_TO_AP_CORE1_MSK                ( BIT(2) )
#define BIT_ICU_INT_WAKEUP_TO_AP_CORE0_MSK                ( BIT(1) )

/* bits definitions for register REG_ICU_ICU_DMA_NON_SEC_AP_CORES_INT_ST */
#define BITS_DMA_NON_SEC_AP_CORES_INT_STATUS(_X_)         (_X_)

/* bits definitions for register REG_ICU_ICU_DMA_NON_SEC_AP_INT_MSK */
#define BITS_DMA_NON_SEC_AP_CORES_INT_MASK(_X_)           (_X_)

/* bits definitions for register REG_ICU_ICU_DMA_SEC_AP_CORES_INT_ST */
#define BITS_DMA_SEC_AP_CORES_INT_STATUS(_X_)             (_X_)

/* bits definitions for register REG_ICU_ICU_DMA_SEC_AP_INT_MSK */
#define BITS_DMA_SEC_AP_CORES_INT_MASK(_X_)               (_X_)

#endif
