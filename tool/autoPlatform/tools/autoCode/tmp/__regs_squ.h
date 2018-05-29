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


#ifndef __H_REGS_SQU_HEADFILE_H__
#define __H_REGS_SQU_HEADFILE_H__ __FILE__

#define	REGS_SQU

/* registers definitions for SQU */
#define REG_SQU_SQU_CTRL_0                                ASR_ADDR(REGS_SQU_BASE, 0X000)/*SQU Control 0 Register*/
#define REG_SQU_SQU_CTRL_1                                ASR_ADDR(REGS_SQU_BASE, 0X008)/*SQU Control 1 Register*/
#define REG_SQU_SQU_FMBIST_CTRL_0                         ASR_ADDR(REGS_SQU_BASE, 0X010)/*SQU FMBIST Control 0 Register*/
#define REG_SQU_SQU_FMBIST_CTRL_1                         ASR_ADDR(REGS_SQU_BASE, 0X018)/*SQU FMBIST Control 1 Register*/
#define REG_SQU_SQU_FMBIST_STATUS_0                       ASR_ADDR(REGS_SQU_BASE, 0X020)/*SQU FMBIST Status 0 Register*/
#define REG_SQU_SQU_RSVD                                  ASR_ADDR(REGS_SQU_BASE, 0X028)/*Reserved Register*/
#define REG_SQU_SQU_CTRL_2                                ASR_ADDR(REGS_SQU_BASE, 0X030)/*SQU Control 2 Register*/
#define REG_SQU_SQU_FMBIST_CTRL_2                         ASR_ADDR(REGS_SQU_BASE, 0X38)/*SQU fmbist wport contl2 Registerr*/
#define REG_SQU_PERF_COUNT_CNTRL                          ASR_ADDR(REGS_SQU_BASE, 0X40)/*Performance Counter Control Register*/
#define REG_SQU_PERF_COUNT_S1                             ASR_ADDR(REGS_SQU_BASE, 0X48)/*Performance Count S1 Registers*/
#define REG_SQU_PERF_COUNT_S4                             ASR_ADDR(REGS_SQU_BASE, 0X50)/*Performance Count S4 Registers*/
#define REG_SQU_PERF_COUNT_S8                             ASR_ADDR(REGS_SQU_BASE, 0X58)/*Performance Count S8 Registers*/
#define REG_SQU_FAB_TIMEOUT_CTRL                          ASR_ADDR(REGS_SQU_BASE, 0X60)/*AXI Fabric Timeout Control Register*/
#define REG_SQU_STATE_HOLD_CTRL                           ASR_ADDR(REGS_SQU_BASE, 0X68)/*State Hold Ctrl Register*/
#define REG_SQU_FAB_TIMEOUT_ID_RT                         ASR_ADDR(REGS_SQU_BASE, 0X70)/*Real Time AXI Fabric Timeout Transaction ID Register*/
#define REG_SQU_FAB_TIMEOUT_STATUS0_RT                    ASR_ADDR(REGS_SQU_BASE, 0X78)/*Real Time AXI Fabric Timeout Status0 Register*/
#define REG_SQU_FAB_TIMEOUT_STATUS1_RT                    ASR_ADDR(REGS_SQU_BASE, 0X80)/*Real Time AXI Fabric Timeout Status1 Register*/
#define REG_SQU_DVC_STATUS_RT                             ASR_ADDR(REGS_SQU_BASE, 0X88)/*Real Time DVC Status Register*/
#define REG_SQU_DFC_STATUS_RT                             ASR_ADDR(REGS_SQU_BASE, 0X90)/*Real Time DCLK Hardware FC Status Register*/
#define REG_SQU_FC_DONE_STATUS_RT                         ASR_ADDR(REGS_SQU_BASE, 0X98)/*Real Time FC Done Status Register*/
#define REG_SQU_SPAPDPCP_PM_STATE_REG_RT                  ASR_ADDR(REGS_SQU_BASE, 0XA0)/*Real Time SPAPDPCP PM State Register*/
#define REG_SQU_PLL_STATUS_REG_RT                         ASR_ADDR(REGS_SQU_BASE, 0XA8)/*Real Time PLL Status Register*/
#define REG_SQU_APC0_PM_STATE_REG_RT                      ASR_ADDR(REGS_SQU_BASE, 0XB0)/*Real Time APC0 PM State Register*/
#define REG_SQU_APC1_PM_STATE_REG_RT                      ASR_ADDR(REGS_SQU_BASE, 0XB8)/*Real Time APC1 PM State Register*/
#define REG_SQU_FAB_TIMEOUT_ID_TO                         ASR_ADDR(REGS_SQU_BASE, 0XC0)/*AXI Fabric Timeout Transaction ID Register*/
#define REG_SQU_FAB_TIMEOUT_STATUS0_TO                    ASR_ADDR(REGS_SQU_BASE, 0XC8)/*AXI Fabric Timeout Status0 Register*/
#define REG_SQU_FAB_TIMEOUT_STATUS1_TO                    ASR_ADDR(REGS_SQU_BASE, 0XD0)/*AXI Fabric Timeout Status1 Register*/
#define REG_SQU_DVC_STATUS_TO                             ASR_ADDR(REGS_SQU_BASE, 0XD8)/*DVC Status Register*/
#define REG_SQU_DFC_STATUS_TO                             ASR_ADDR(REGS_SQU_BASE, 0XE0)/*DCLK Hardware FC Status Register*/
#define REG_SQU_FC_DONE_STATUS_TO                         ASR_ADDR(REGS_SQU_BASE, 0XE8)/*FC Done Status Register*/
#define REG_SQU_SPAPDPCP_PM_STATE_REG_TO                  ASR_ADDR(REGS_SQU_BASE, 0XF0)/*SPAPDPCP PM State Register*/
#define REG_SQU_PLL_STATUS_REG_TO                         ASR_ADDR(REGS_SQU_BASE, 0XF8)/*PLL Status Register*/
#define REG_SQU_APC0_PM_STATE_REG_TO                      ASR_ADDR(REGS_SQU_BASE, 0X100)/*APC0 PM State Register*/
#define REG_SQU_APC1_PM_STATE_REG_TO                      ASR_ADDR(REGS_SQU_BASE, 0X108)/*APC1 PM State Register*/
#define REG_SQU_FAB_TIMEOUT_ID_HD                         ASR_ADDR(REGS_SQU_BASE, 0X110)/*Real Time AXI Fabric Timeout Transaction ID Register*/
#define REG_SQU_FAB_TIMEOUT_STATUS0_HD                    ASR_ADDR(REGS_SQU_BASE, 0X118)/*Real Time AXI Fabric Timeout Status0 Register*/
#define REG_SQU_FAB_TIMEOUT_STATUS1_HD                    ASR_ADDR(REGS_SQU_BASE, 0X120)/*Real Time AXI Fabric Timeout Status1 Register*/
#define REG_SQU_DVC_STATUS_HD                             ASR_ADDR(REGS_SQU_BASE, 0X128)/*Real Time DVC Status Register*/
#define REG_SQU_DFC_STATUS_HD                             ASR_ADDR(REGS_SQU_BASE, 0X130)/*Real Time DCLK Hardware FC Status Register*/
#define REG_SQU_FC_DONE_STATUS_HD                         ASR_ADDR(REGS_SQU_BASE, 0X138)/*Real Time FC Done Status Register*/
#define REG_SQU_SPAPDPCP_PM_STATE_REG_HD                  ASR_ADDR(REGS_SQU_BASE, 0X140)/*Real Time SPAPDPCP PM State Register*/
#define REG_SQU_PLL_STATUS_REG_HD                         ASR_ADDR(REGS_SQU_BASE, 0X148)/*Real Time PLL Status Register*/
#define REG_SQU_APC0_PM_STATE_REG_HD                      ASR_ADDR(REGS_SQU_BASE, 0X150)/*Real Time APC0 PM State Register*/
#define REG_SQU_APC1_PM_STATE_REG_HD                      ASR_ADDR(REGS_SQU_BASE, 0X158)/*Real Time APC1 PM State Register*/
#define REG_SQU_APC2_PM_STATE_REG_RT                      ASR_ADDR(REGS_SQU_BASE, 0X160)/*Real Time APC2 PM State Register*/
#define REG_SQU_APC2_PM_STATE_REG_TO                      ASR_ADDR(REGS_SQU_BASE, 0X168)/*APC2 PM State Register*/
#define REG_SQU_APC2_PM_STATE_REG_HD                      ASR_ADDR(REGS_SQU_BASE, 0X170)/*Real Time APC2 PM State Register*/
#define REG_SQU_PLL_STATUS2_REG_RT                        ASR_ADDR(REGS_SQU_BASE, 0X178)/*Real Time PLL Status2 Register*/
#define REG_SQU_PLL_STATUS2_REG_TO                        ASR_ADDR(REGS_SQU_BASE, 0X180)/*PLL Status2 Register*/
#define REG_SQU_PLL_STATUS2_REG_HD                        ASR_ADDR(REGS_SQU_BASE, 0X188)/*Real Time PLL Status2 Register*/
#define REG_SQU_SQU_CAM_ENT_BANK0                         ASR_ADDR(REGS_SQU_BASE, 0X200)/*CAM Entries Bank 0 Register*/
#define REG_SQU_SQU_CAM_ENT_BANK1                         ASR_ADDR(REGS_SQU_BASE, 0X280)/*CAM Entries Bank 1 Register*/
#define REG_SQU_SQU_CAM_ENT_BANK2                         ASR_ADDR(REGS_SQU_BASE, 0X300)/*CAM Entries Bank 2 Register*/
#define REG_SQU_SQU_CAM_ENT_BANK3                         ASR_ADDR(REGS_SQU_BASE, 0X380)/*CAM Entries Bank 3 Register*/
#define REG_SQU_SQU_CAM_ENT_BANK4                         ASR_ADDR(REGS_SQU_BASE, 0X400)/*CAM Entries Bank 4 Register*/
#define REG_SQU_SQU_CAM_ENT_BANK5                         ASR_ADDR(REGS_SQU_BASE, 0X480)/*CAM Entries Bank 5 Register*/
#define REG_SQU_SQU_LOGGER_ENT                            ASR_ADDR(REGS_SQU_BASE, 0X780)/*Logger Entries Register*/
#define REG_SQU_SQU_CHAN_0_BYTE_CNT                       ASR_ADDR(REGS_SQU_BASE, 0X800)/*Channel 0 Byte Count Register*/
#define REG_SQU_SQU_CHAN_1_BYTE_CNT                       ASR_ADDR(REGS_SQU_BASE, 0X804)/*Channel 1 Byte Count Register*/
#define REG_SQU_SQU_CHAN_0_SRC_ADDR                       ASR_ADDR(REGS_SQU_BASE, 0X810)/*Channel 0 Source Address Register*/
#define REG_SQU_SQU_CHAN_1_SRC_ADDR                       ASR_ADDR(REGS_SQU_BASE, 0X814)/*Channel 1 Source Address Register*/
#define REG_SQU_SQU_CHAN_0_DEST_ADDR                      ASR_ADDR(REGS_SQU_BASE, 0X820)/*Channel 0 Destination Address Register*/
#define REG_SQU_SQU_CHAN_1_DEST_ADDR                      ASR_ADDR(REGS_SQU_BASE, 0X824)/*Channel 1 Destination Address Register*/
#define REG_SQU_SQU_CHAN_0_NEXT_DESC_PTR                  ASR_ADDR(REGS_SQU_BASE, 0X830)/*Channel 0 Next Descriptor Pointer Register*/
#define REG_SQU_SQU_CHAN_1_NEXT_DESC_PTR                  ASR_ADDR(REGS_SQU_BASE, 0X834)/*Channel 1 Next Descriptor Pointer Register*/
#define REG_SQU_SQU_CHAN_0_CTRL                           ASR_ADDR(REGS_SQU_BASE, 0X840)/*Channel 0 Control Register*/
#define REG_SQU_SQU_CHAN_1_CTRL                           ASR_ADDR(REGS_SQU_BASE, 0X844)/*Channel 1 Control Register*/
#define REG_SQU_SQU_CHAN_PRI                              ASR_ADDR(REGS_SQU_BASE, 0X860)/*Channel Priority Register*/
#define REG_SQU_Channel_ID_FILTER                         ASR_ADDR(REGS_SQU_BASE, 0X864)/*Channel ID FILTER*/
#define REG_SQU_CHAN_0_CURR_DESC_PTR                      ASR_ADDR(REGS_SQU_BASE, 0X870)/*Channel 0 Current Descriptor Pointer Register*/
#define REG_SQU_CHAN_1_CURR_DESC_PTR                      ASR_ADDR(REGS_SQU_BASE, 0X874)/*Channel 1 Current Descriptor Pointer Register*/
#define REG_SQU_CHAN_0_RSR                                ASR_ADDR(REGS_SQU_BASE, 0X890)/*Channel 0 Reset Select Register*/
#define REG_SQU_SQU_CHAN_1_RSR                            ASR_ADDR(REGS_SQU_BASE, 0X894)/*Channel 1 Reset Select Register*/
#define REG_SQU_SQU_CHAN_0_INT_MASK                       ASR_ADDR(REGS_SQU_BASE, 0X880)/*Channel 0 Interrupt Mask Register*/
#define REG_SQU_SQU_CHAN_1_INT_MASK                       ASR_ADDR(REGS_SQU_BASE, 0X884)/*Channel 1 Interrupt Mask Register*/
#define REG_SQU_SQU_CHAN_0_INT_STATUS                     ASR_ADDR(REGS_SQU_BASE, 0X8A0)/*Channel 0 Interrupt Status Register*/
#define REG_SQU_SQU_CHAN_1_INT_STATUS                     ASR_ADDR(REGS_SQU_BASE, 0X8A4)/*Channel 1 Interrupt Status Register*/



/* bits definitions for register REG_SQU_SQU_CTRL_0 */
#define BITS_RTC_BK0(_X_)                                 ( (_X_) << 30 & (BIT(30)|BIT(31)) )
#define BITS_WTC_BK0(_X_)                                 ( (_X_) << 28 & (BIT(28)|BIT(29)) )
#define BIT_PDWN_BK0                                      ( BIT(27) )
#define BIT_CLKEN_BK0                                     ( BIT(26) )
#define BIT_CAMENABLE                                     ( BIT(24) )
#define BIT_FIXPRIORITY                                   ( BIT(23) )
#define BIT_CAMOVE                                        ( BIT(16) )
#define BITS_RTC_BROM(_X_)                                ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_RTC_REF_BROM(_X_)                            ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PDWN_BROM                                     ( BIT(11) )
#define BITS_APB_CLK_DIV(_X_)                             ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)) )
#define BITS_ROM_WAIT_CYCLE(_X_)                          ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SQU_SQU_CTRL_1 */
#define BITS_RTC_BK2(_X_)                                 ( (_X_) << 30 & (BIT(30)|BIT(31)) )
#define BITS_WTC_BK2(_X_)                                 ( (_X_) << 28 & (BIT(28)|BIT(29)) )
#define BIT_PDWN_BK2                                      ( BIT(27) )
#define BIT_CLKEN_BK2                                     ( BIT(26) )
#define BIT_FASTACCESS                                    ( BIT(25) )
#define BIT_CAMENABLE148                                  ( BIT(24) )
#define BIT_FIXPRIORITY149                                ( BIT(23) )
#define BIT_EN_BK2                                        ( BIT(16) )
#define BITS_RTC_BK1(_X_)                                 ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_WTC_BK1(_X_)                                 ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PDWN_BK1                                      ( BIT(11) )
#define BIT_CLKEN_BK1                                     ( BIT(10) )
#define BIT_FASTACCESSBK1                                 ( BIT(9) )
#define BIT_CAMENABLE257                                  ( BIT(8) )
#define BIT_FIXPRIORITY258                                ( BIT(7) )

/* bits definitions for register REG_SQU_SQU_FMBIST_CTRL_0 */
#define BIT_SQU_FMBIST_SW_CAM_ACC_EN                      ( BIT(31) )
#define BITS_OTP_SQU_MUX_SEL(_X_)                         ( (_X_) << 28 & (BIT(28)|BIT(29)) )
#define BIT_FUSEW_CLEAR                                   ( BIT(27) )
#define BITS_CLK_DIV_VAL(_X_)                             ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_READ_FUSE5                                    ( BIT(21) )
#define BIT_READ_FUSE4                                    ( BIT(20) )
#define BIT_READ_FUSE3                                    ( BIT(19) )
#define BIT_READ_FUSE2                                    ( BIT(18) )
#define BIT_READ_FUSE1                                    ( BIT(17) )
#define BIT_READ_FUSE0                                    ( BIT(16) )
#define BITS_CAM_MBIST_EN_REG(_X_)                        ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BITS_SW_CAM_BANK_REG(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_SQU_SQU_FMBIST_CTRL_1 */
#define BIT_SQU_FMBIST_SW_CONTROL                         ( BIT(31) )
#define BIT_FUSEW_START                                   ( BIT(30) )
#define BIT_ATE_SQU_MODE                                  ( BIT(29) )
#define BIT_PIPE_MODE                                     ( BIT(28) )
#define BIT_ACK_HI_PWR                                    ( BIT(27) )
#define BIT_ACK_LO_PWR                                    ( BIT(26) )
#define BIT_SQU_FMBIST_REG__EN                            ( BIT(22) )
#define BIT_SQU_FMBIST_RETENTION                          ( BIT(21) )
#define BIT_SQU_FMBIST_14N                                ( BIT(20) )
#define BIT_SQU_FMBIST_FORCE_ERROR                        ( BIT(19) )
#define BIT_SQU_FMBIST_CLEAR_LOGGER                       ( BIT(18) )
#define BIT_SQU_FMBIST_CLEAR                              ( BIT(17) )
#define BIT_SQU_FMBIST_START                              ( BIT(16) )
#define BITS_MEMTOP_M1_IN_BITS(_X_)                       ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BITS_COL_SIZE_IN(_X_)                             ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BITS_SQU_FMBIST_BLOCK_EN(_X_)                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_SQU_SQU_FMBIST_STATUS_0 */
#define BIT_SQ_FUSE_READY115                              ( BIT(28) )
#define BIT_SQU_FMBIST_REG_HI_PWR                         ( BIT(27) )
#define BIT_SQU_FMBIST_REG_LO_PWR                         ( BIT(26) )
#define BIT_FUSEW_DONE                                    ( BIT(25) )
#define BIT_BURN_ERROR                                    ( BIT(24) )
#define BIT_CAM_MBIST_FAIL5                               ( BIT(19) )
#define BIT_CAM_MBIST_DONE5                               ( BIT(18) )
#define BIT_CAM_MBIST_FAIL4                               ( BIT(17) )
#define BIT_CAM_MBIST_DONE4                               ( BIT(16) )
#define BIT_CAM_MBIST_FAIL3                               ( BIT(15) )
#define BIT_CAM_MBIST_DONE3                               ( BIT(14) )
#define BIT_CAM_MBIST_FAIL2                               ( BIT(13) )
#define BIT_CAM_MBIST_DONE2                               ( BIT(12) )
#define BIT_CAM_MBIST_FAIL1                               ( BIT(11) )
#define BIT_CAM_MBIST_DONE1                               ( BIT(10) )
#define BIT_CAM_MBIST_FAIL0                               ( BIT(9) )
#define BIT_CAM_MBIST_DONE0                               ( BIT(8) )
#define BITS_SQU_FMBIST_PTR(_X_)                          ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_SQU_FMBIST_READY                              ( BIT(2) )
#define BIT_SQU_FMBIST_LOGGER_ERROR                       ( BIT(1) )
#define BIT_SQU_FMBIST_LOGGER_FATAL                       ( BIT(0) )

/* bits definitions for register REG_SQU_SQU_RSVD */

/* bits definitions for register REG_SQU_SQU_CTRL_2 */
#define BITS_RTC_BK4(_X_)                                 ( (_X_) << 30 & (BIT(30)|BIT(31)) )
#define BITS_WTC_BK4(_X_)                                 ( (_X_) << 28 & (BIT(28)|BIT(29)) )
#define BIT_PDWN_BK4                                      ( BIT(27) )
#define BIT_CLKEN_BK4                                     ( BIT(26) )
#define BIT_FASTACCESS1                                   ( BIT(25) )
#define BIT_CAMENABLE1160                                 ( BIT(24) )
#define BIT_FIXPRIORITY1161                               ( BIT(23) )
#define BIT_EN_BK4                                        ( BIT(16) )
#define BITS_RTC_BK3(_X_)                                 ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_WTC_BK3(_X_)                                 ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PDWN_BK3                                      ( BIT(11) )
#define BIT_CLKEN_BK3                                     ( BIT(10) )
#define BIT_FASTACCESS2                                   ( BIT(9) )
#define BIT_CAMENABLE2169                                 ( BIT(8) )
#define BIT_FIXPRIORITY2170                               ( BIT(7) )
#define BIT_EN_BK3                                        ( BIT(0) )

/* bits definitions for register REG_SQU_SQU_FMBIST_CTRL_2 */
#define BITS_PWRDONE(_X_)                                 ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BITS_DEBUG_SEL_DATABYTE(_X_)                      ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BITS_DEBUG_SELB(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SQU_PERF_COUNT_CNTRL */
#define BIT_S8_RD_BYTE_COUNT_EN                           ( BIT(10) )
#define BIT_S8_WR_BYTE_COUNT_EN                           ( BIT(9) )
#define BIT_CLR_COUNT_S8                                  ( BIT(8) )
#define BIT_S4_RD_BYTE_COUNT_EN                           ( BIT(6) )
#define BIT_S4_WR_BYTE_COUNT_EN                           ( BIT(5) )
#define BIT_CLR_COUNT_S4                                  ( BIT(4) )
#define BIT_S1_RD_BYTE_COUNT_EN                           ( BIT(2) )
#define BIT_S1_WR_BYTE_COUNT_EN                           ( BIT(1) )
#define BIT_CLR_COUNT_S1                                  ( BIT(0) )

/* bits definitions for register REG_SQU_PERF_COUNT_S1 */
#define BITS_COUNT_VALUE207(_X_)                          (_X_)

/* bits definitions for register REG_SQU_PERF_COUNT_S4 */
#define BITS_COUNT_VALUE214(_X_)                          (_X_)

/* bits definitions for register REG_SQU_PERF_COUNT_S8 */
#define BITS_COUNT_VALUE221(_X_)                          (_X_)

/* bits definitions for register REG_SQU_FAB_TIMEOUT_CTRL */
#define BIT_SQ_AUTORESP_TYPE230                           ( BIT(31) )
#define BIT_SQ_AUTORESP_EN231                             ( BIT(30) )
#define BIT_SQ_TIMEOUT_INT_MSK233                         ( BIT(29) )
#define BIT_SQ_FAB_MON_RST236                             ( BIT(28) )
#define BIT_SQ_FAB_MON_CLR237                             ( BIT(27) )
#define BITS_SQ_TIMEOUT_VAL239(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SQU_STATE_HOLD_CTRL */
#define BIT_SQ_STATE_HOLD_CTRL249                         ( BIT(0) )

/* bits definitions for register REG_SQU_FAB_TIMEOUT_ID_RT */
#define BIT_SQ_WR_TIMEOUT_IND257                          ( BIT(31) )
#define BITS_SQ_TIMEOUT_TX_WID259(_X_)                    ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_SQ_RD_TIMEOUT_IND260                          ( BIT(15) )
#define BITS_SQ_TIMEOUT_TX_RID262(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_SQU_FAB_TIMEOUT_STATUS0_RT */
#define BITS_SQ_TIMEOUT_WADDR270(_X_)                     ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_SQ_WR_TIMEOUT_IND272                          ( BIT(0) )

/* bits definitions for register REG_SQU_FAB_TIMEOUT_STATUS1_RT */
#define BITS_SQ_TIMEOUT_RADDR280(_X_)                     ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_SQ_RD_TIMEOUT_IND282                          ( BIT(0) )

/* bits definitions for register REG_SQU_DVC_STATUS_RT */
#define BITS_SQ_CAUSE291(_X_)                             ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_SQ_TVL293(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_SQ_CVL295(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_SQ_DVC_STATUS297                              ( BIT(0) )

/* bits definitions for register REG_SQU_DFC_STATUS_RT */
#define BITS_SQ_DFC_CAUSE306(_X_)                         ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BITS_SQ_TFL307(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_SQ_CFL308(_X_)                               ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_SQ_DFC_STATUS309                              ( BIT(0) )

/* bits definitions for register REG_SQU_FC_DONE_STATUS_RT */
#define BIT_SQ_AP_C2_FC_DONE318                           ( BIT(9) )
#define BIT_SQ_AP_C1_FC_DONE319                           ( BIT(8) )
#define BIT_SQ_CP_FC_DONE320                              ( BIT(7) )
#define BIT_SQ_AP_C0_FC_DONE321                           ( BIT(6) )
#define BIT_SQ_DCLK_FC_DONE322                            ( BIT(5) )
#define BIT_SQ_ACLK_FC_DONE323                            ( BIT(4) )
#define BITS_SQ_DVC_STATUS324(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_SQU_SPAPDPCP_PM_STATE_REG_RT */
#define BITS_SQ_SP_STATE333(_X_)                          ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BITS_SQ_AP_STATE334(_X_)                          ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BITS_SG_STATE335(_X_)                             ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BITS_SQ_CP_STATE336(_X_)                          ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_SQ_WFSTATE337(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_SQU_PLL_STATUS_REG_RT */
#define BIT_SQ_PLL4_LOCK345                               ( BIT(31) )
#define BIT_SQ_PLL3_LOCK346                               ( BIT(30) )
#define BIT_SQ_PLL2_LOCK347                               ( BIT(29) )
#define BIT_SQ_PLL1_LOCK348                               ( BIT(28) )
#define BITS_SQ_CLK_DIV_INFO349(_X_)                      ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_SQ_PLL_SEL_INFO350(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )

/* bits definitions for register REG_SQU_APC0_PM_STATE_REG_RT */
#define BITS_SQ_C0_PM_STATE359(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )

/* bits definitions for register REG_SQU_APC1_PM_STATE_REG_RT */
#define BITS_SQ_C0_PM_STATE368(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )

/* bits definitions for register REG_SQU_FAB_TIMEOUT_ID_TO */
#define BIT_SQ_WR_TIMEOUT_IND376                          ( BIT(31) )
#define BITS_SQ_TIMEOUT_TX_WID378(_X_)                    ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_SQ_RD_TIMEOUT_IND379                          ( BIT(15) )
#define BITS_SQ_TIMEOUT_TX_RID381(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_SQU_FAB_TIMEOUT_STATUS0_TO */
#define BITS_SQ_TIMEOUT_WADDR389(_X_)                     ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_SQ_WR_TIMEOUT_IND391                          ( BIT(0) )

/* bits definitions for register REG_SQU_FAB_TIMEOUT_STATUS1_TO */
#define BITS_SQ_TIMEOUT_RADDR399(_X_)                     ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_SQ_RD_TIMEOUT_IND401                          ( BIT(0) )

/* bits definitions for register REG_SQU_DVC_STATUS_TO */
#define BITS_SQ_CAUSE410(_X_)                             ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_SQ_TVL412(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_SQ_CVL414(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_SQ_DVC_STATUS416                              ( BIT(0) )

/* bits definitions for register REG_SQU_DFC_STATUS_TO */
#define BITS_SQ_DFC_CAUSE425(_X_)                         ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BITS_SQ_TFL426(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_SQ_CFL427(_X_)                               ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_SQ_DFC_STATUS428                              ( BIT(0) )

/* bits definitions for register REG_SQU_FC_DONE_STATUS_TO */
#define BIT_SQ_AP_C2_FC_DONE437                           ( BIT(9) )
#define BIT_SQ_AP_C1_FC_DONE438                           ( BIT(8) )
#define BIT_CP_FC_DONE_MSK439                             ( BIT(7) )
#define BIT_SQ_AP_C0_FC_DONE440                           ( BIT(6) )
#define BIT_SQ_DCLK_FC_DONE441                            ( BIT(5) )
#define BIT_SQ_ACLK_FC_DONE442                            ( BIT(4) )
#define BITS_SQ_DVC_STATUS443(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_SQU_SPAPDPCP_PM_STATE_REG_TO */
#define BITS_SQ_SP_STATE452(_X_)                          ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BITS_SQ_AP_STATE453(_X_)                          ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BITS_SG_STATE454(_X_)                             ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BITS_SQ_CP_STATE455(_X_)                          ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_SQ_WFSTATE456(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_SQU_PLL_STATUS_REG_TO */
#define BIT_SQ_PLL4_LOCK464                               ( BIT(31) )
#define BIT_SQ_PLL3_LOCK465                               ( BIT(30) )
#define BIT_SQ_PLL2_LOCK466                               ( BIT(29) )
#define BIT_SQ_PLL1_LOCK467                               ( BIT(28) )
#define BITS_SQ_CLK_DIV_INFO468(_X_)                      ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_SQ_PLL_SEL_INFO469(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )

/* bits definitions for register REG_SQU_APC0_PM_STATE_REG_TO */
#define BITS_SQ_C0_PM_STATE478(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )

/* bits definitions for register REG_SQU_APC1_PM_STATE_REG_TO */
#define BITS_SQ_C0_PM_STATE487(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )

/* bits definitions for register REG_SQU_FAB_TIMEOUT_ID_HD */
#define BIT_SQ_WR_TIMEOUT_IND495                          ( BIT(31) )
#define BITS_SQ_TIMEOUT_TX_WID497(_X_)                    ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_SQ_RD_TIMEOUT_IND498                          ( BIT(15) )
#define BITS_SQ_TIMEOUT_TX_RID500(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_SQU_FAB_TIMEOUT_STATUS0_HD */
#define BITS_SQ_TIMEOUT_WADDR508(_X_)                     ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_SQ_WR_TIMEOUT_IND510                          ( BIT(0) )

/* bits definitions for register REG_SQU_FAB_TIMEOUT_STATUS1_HD */
#define BITS_SQ_TIMEOUT_RADDR518(_X_)                     ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_SQ_RD_TIMEOUT_IND520                          ( BIT(0) )

/* bits definitions for register REG_SQU_DVC_STATUS_HD */
#define BITS_SQ_CAUSE529(_X_)                             ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_SQ_TVL531(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_SQ_CVL533(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_SQ_DVC_STATUS535                              ( BIT(0) )

/* bits definitions for register REG_SQU_DFC_STATUS_HD */
#define BITS_SQ_DFC_CAUSE544(_X_)                         ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BITS_SQ_TFL545(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_SQ_CFL546(_X_)                               ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_SQ_DFC_STATUS547                              ( BIT(0) )

/* bits definitions for register REG_SQU_FC_DONE_STATUS_HD */
#define BIT_SQ_AP_C2_FC_DONE556                           ( BIT(9) )
#define BIT_SQ_AP_C1_FC_DONE557                           ( BIT(8) )
#define BIT_CP_FC_DONE_MSK558                             ( BIT(7) )
#define BIT_SQ_AP_C0_FC_DONE559                           ( BIT(6) )
#define BIT_SQ_DCLK_FC_DONE560                            ( BIT(5) )
#define BIT_SQ_ACLK_FC_DONE561                            ( BIT(4) )
#define BITS_SQ_DVC_STATUS562(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_SQU_SPAPDPCP_PM_STATE_REG_HD */
#define BITS_SQ_SP_STATE571(_X_)                          ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BITS_SQ_AP_STATE572(_X_)                          ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BITS_SG_STATE573(_X_)                             ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BITS_SQ_CP_STATE574(_X_)                          ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_SQ_WFSTATE575(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_SQU_PLL_STATUS_REG_HD */
#define BIT_SQ_PLL4_LOCK583                               ( BIT(31) )
#define BIT_SQ_PLL3_LOCK584                               ( BIT(30) )
#define BIT_SQ_PLL2_LOCK585                               ( BIT(29) )
#define BIT_SQ_PLL1_LOCK586                               ( BIT(28) )
#define BITS_SQ_CLK_DIV_INFO587(_X_)                      ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_SQ_PLL_SEL_INFO588(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )

/* bits definitions for register REG_SQU_APC0_PM_STATE_REG_HD */
#define BITS_SQ_C0_PM_STATE597(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )

/* bits definitions for register REG_SQU_APC1_PM_STATE_REG_HD */
#define BITS_SQ_C0_PM_STATE606(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )

/* bits definitions for register REG_SQU_APC2_PM_STATE_REG_RT */
#define BITS_SQ_C0_PM_STATE614(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )

/* bits definitions for register REG_SQU_APC2_PM_STATE_REG_TO */
#define BITS_SQ_C0_PM_STATE622(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )

/* bits definitions for register REG_SQU_APC2_PM_STATE_REG_HD */
#define BITS_SQ_C0_PM_STATE630(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )

/* bits definitions for register REG_SQU_PLL_STATUS2_REG_RT */
#define BITS_SQ_C2_CLK_DIV_INFO639(_X_)                   ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)) )
#define BITS_C2_PLL_SEL_INFO640(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_SQU_PLL_STATUS2_REG_TO */
#define BITS_SQ_C2_CLK_DIV_INFO649(_X_)                   ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)) )
#define BITS_C2_PLL_SEL_INFO650(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_SQU_PLL_STATUS2_REG_HD */
#define BITS_SQ_C2_CLK_DIV_INFO659(_X_)                   ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)) )
#define BITS_C2_PLL_SEL_INFO660(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_SQU_SQU_CAM_ENT_BANK0 */
#define BIT_VAL_BIT668                                    ( BIT(15) )
#define BITS_CAM_ENTRY_DATA670(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for register REG_SQU_SQU_CAM_ENT_BANK1 */
#define BIT_VAL_BIT678                                    ( BIT(15) )
#define BITS_CAM_ENTRY_DATA680(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for register REG_SQU_SQU_CAM_ENT_BANK2 */
#define BIT_VAL_BIT688                                    ( BIT(15) )
#define BITS_CAM_ENTRY_DATA690(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for register REG_SQU_SQU_CAM_ENT_BANK3 */
#define BIT_VAL_BIT698                                    ( BIT(15) )
#define BITS_CAM_ENTRY_DATA700(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for register REG_SQU_SQU_CAM_ENT_BANK4 */
#define BIT_VAL_BIT708                                    ( BIT(15) )
#define BITS_CAM_ENTRY_DATA710(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for register REG_SQU_SQU_CAM_ENT_BANK5 */
#define BIT_VAL_BIT718                                    ( BIT(15) )
#define BITS_CAM_ENTRY_DATA720(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for register REG_SQU_SQU_LOGGER_ENT */
#define BIT_VAL_BIT728                                    ( BIT(15) )
#define BITS_CAM_ENTRY_DATA730(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for register REG_SQU_SQU_CHAN_0_BYTE_CNT */
#define BITS_BYTECNT0(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SQU_SQU_CHAN_1_BYTE_CNT */
#define BITS_BYTECNT1(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SQU_SQU_CHAN_0_SRC_ADDR */
#define BITS_SRCADD0(_X_)                                 (_X_)

/* bits definitions for register REG_SQU_SQU_CHAN_1_SRC_ADDR */
#define BITS_SRCADD1(_X_)                                 (_X_)

/* bits definitions for register REG_SQU_SQU_CHAN_0_DEST_ADDR */
#define BITS_DESTADD0(_X_)                                (_X_)

/* bits definitions for register REG_SQU_SQU_CHAN_1_DEST_ADDR */
#define BITS_DESTADD1(_X_)                                (_X_)

/* bits definitions for register REG_SQU_SQU_CHAN_0_NEXT_DESC_PTR */
#define BITS_NDPTR0(_X_)                                  (_X_)

/* bits definitions for register REG_SQU_SQU_CHAN_1_NEXT_DESC_PTR */
#define BITS_NDPTR1(_X_)                                  (_X_)

/* bits definitions for register REG_SQU_SQU_CHAN_0_CTRL */
#define BIT_SSPMOD818                                     ( BIT(21) )
#define BIT_ABR819                                        ( BIT(20) )
#define BIT_CDE821                                        ( BIT(17) )
#define BIT_SQ_SDA823                                     ( BIT(15) )
#define BIT_CHANACT824                                    ( BIT(14) )
#define BIT_FETCHND825                                    ( BIT(13) )
#define BIT_CHANEN826                                     ( BIT(12) )
#define BIT_TRANSMOD828                                   ( BIT(11) )
#define BIT_INTMODE829                                    ( BIT(10) )
#define BIT_CHAINMOD830                                   ( BIT(9) )
#define BITS_BURSTLIMIT831(_X_)                           ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)) )
#define BITS_DESTDIR832(_X_)                              ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_SRCDIR833(_X_)                               ( (_X_) << 2 & (BIT(2)|BIT(3)) )

/* bits definitions for register REG_SQU_SQU_CHAN_1_CTRL */
#define BIT_SSPMOD842                                     ( BIT(21) )
#define BIT_ABR843                                        ( BIT(20) )
#define BIT_CDE845                                        ( BIT(17) )
#define BIT_CHANACT847                                    ( BIT(14) )
#define BIT_FETCHND848                                    ( BIT(13) )
#define BIT_CHANEN849                                     ( BIT(12) )
#define BIT_TRANSMOD851                                   ( BIT(11) )
#define BIT_INTMODE852                                    ( BIT(10) )
#define BIT_CHAINMOD853                                   ( BIT(9) )
#define BITS_BURSTLIMIT854(_X_)                           ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)) )
#define BITS_DESTDIR855(_X_)                              ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_SRCDIR856(_X_)                               ( (_X_) << 2 & (BIT(2)|BIT(3)) )

/* bits definitions for register REG_SQU_SQU_CHAN_PRI */
#define BIT_REVERSE_MEMORY_COPY                           ( BIT(31) )
#define BITS_PRIOCHAN10(_X_)                              ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SQU_Channel_ID_FILTER */
#define BITS_EN_ACCESS(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SQU_CHAN_0_CURR_DESC_PTR */
#define BITS_CDPTR0(_X_)                                  (_X_)

/* bits definitions for register REG_SQU_CHAN_1_CURR_DESC_PTR */
#define BITS_CDPTR1(_X_)                                  (_X_)

/* bits definitions for register REG_SQU_CHAN_0_RSR */
#define BITS_RSR0(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SQU_SQU_CHAN_1_RSR */
#define BITS_RSR1(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SQU_SQU_CHAN_0_INT_MASK */
#define BIT_DMA_ABORT_INT927                              ( BIT(1) )
#define BIT_COMP928                                       ( BIT(0) )

/* bits definitions for register REG_SQU_SQU_CHAN_1_INT_MASK */
#define BIT_DMA_ABORT_INT936                              ( BIT(1) )
#define BIT_COMP937                                       ( BIT(0) )

/* bits definitions for register REG_SQU_SQU_CHAN_0_INT_STATUS */
#define BIT_DMA_ABORT945                                  ( BIT(1) )
#define BIT_INT_DONE946                                   ( BIT(0) )

/* bits definitions for register REG_SQU_SQU_CHAN_1_INT_STATUS */
#define BIT_DMA_ABORT954                                  ( BIT(1) )
#define BIT_INT_DONE955                                   ( BIT(0) )

#endif
