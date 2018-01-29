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


#ifndef __H_REGS_CIU_HEADFILE_H__
#define __H_REGS_CIU_HEADFILE_H__ __FILE__

#define	REGS_CIU

/* registers definitions for CIU */
#define REG_CIU_CHIP_ID                                   ASR_ADDR(REGS_CIU_BASE, 0X00)/*Chip ID Register*/
#define REG_CIU_CP_CPU_CONF                               ASR_ADDR(REGS_CIU_BASE, 0X04)/*<var Processor: Comm> CPU Configuration Register*/
#define REG_CIU_SW_CONFIG                                 ASR_ADDR(REGS_CIU_BASE, 0X08)/*Software Configuration Register*/
#define REG_CIU_CP_CPU_SRAM_SPD                           ASR_ADDR(REGS_CIU_BASE, 0X0C)/*<var Processor: Comm> CPU SRAM Speed Config Register*/
#define REG_CIU_CR5_PPX_CONF                              ASR_ADDR(REGS_CIU_BASE, 0X10)/*<var Processor: Comm> AXI Peripheral Interface Configuration Register*/
#define REG_CIU_CR5_PPV_CONF                              ASR_ADDR(REGS_CIU_BASE, 0X14)/*<var Processor: Comm> Virtual AXI Peripheral Interface Configuration Register*/
#define REG_CIU_CP_L2C_ADDR_FILTER_CONF                   ASR_ADDR(REGS_CIU_BASE, 0X18)/*<var Processor: Comm> L2 Cache Address Filter Config Register*/
#define REG_CIU_MC_QOS_CTRL                               ASR_ADDR(REGS_CIU_BASE, 0X1C)/*Memory Controller QoS Configuration Register*/
#define REG_CIU_SYS_BOOT_CNTRL                            ASR_ADDR(REGS_CIU_BASE, 0X20)/*System Boot Control Register*/
#define REG_CIU_SW_BRANCH_ADDR                            ASR_ADDR(REGS_CIU_BASE, 0X24)/*Software Branch Address Register*/
#define REG_CIU_CP_L2C_CONF                               ASR_ADDR(REGS_CIU_BASE, 0X28)/*<var Processor: Comm>  L2C Config Register*/
#define REG_CIU_CP_L2C_SRAM_CONF                          ASR_ADDR(REGS_CIU_BASE, 0X2C)/*<var Processor: Comm>  L2C SRAM Timing Configuration Register*/
#define REG_CIU_BROM_IPCx0                                ASR_ADDR(REGS_CIU_BASE, 0x34)/*Boot ROM IPC x Register*/
#define REG_CIU_BROM_IPCx1                                ASR_ADDR(REGS_CIU_BASE, 0x38)/*Boot ROM IPC x Register*/
#define REG_CIU_BROM_IPCx2                                ASR_ADDR(REGS_CIU_BASE, 0x3C)/*Boot ROM IPC x Register*/
#define REG_CIU_MC_CONF                                   ASR_ADDR(REGS_CIU_BASE, 0X40)/*Memory Controller Configuration Register*/
#define REG_CIU_TOP_MEM_RTC_WTC_SPD                       ASR_ADDR(REGS_CIU_BASE, 0X44)/*App Top Memory RTC/WTC Speed Register*/
#define REG_CIU_CS_CONF                                   ASR_ADDR(REGS_CIU_BASE, 0X4C)/*CoreSight Configuration Register*/
#define REG_CIU_CS_DEBUG_CONF                             ASR_ADDR(REGS_CIU_BASE, 0X50)/*CoreSight Debug Configuration Register*/
#define REG_CIU_MC_AXI_URGENT                             ASR_ADDR(REGS_CIU_BASE, 0X58)
#define REG_CIU_SYSSEC_CTRL_1                             ASR_ADDR(REGS_CIU_BASE, 0X5C)/*System Security Control Register 1*/
#define REG_CIU_SYSSEC_CTRL_2                             ASR_ADDR(REGS_CIU_BASE, 0X6C)/*System Security Control Register 2*/
#define REG_CIU_MCB_CONFIG2                               ASR_ADDR(REGS_CIU_BASE, 0X8C)/*MCB Configuration 2 Register*/
#define REG_CIU_GPU_COHERENCY_FEATURE                     ASR_ADDR(REGS_CIU_BASE, 0XA0)/*GPU Coherency Feature Control Register*/
#define REG_CIU_GPU_MEM_XTC                               ASR_ADDR(REGS_CIU_BASE, 0XA4)/*GPU Memory Timing Control Register*/
#define REG_CIU_VPU_XTC                                   ASR_ADDR(REGS_CIU_BASE, 0XA8)/*VPU Memory Timing Control Register*/
#define REG_CIU_AUDIO_XTC                                 ASR_ADDR(REGS_CIU_BASE, 0XAC)/*Audio Memory Timing Control Register*/
#define REG_CIU_CAP_CPU_CONF_ADDR_FILTER                  ASR_ADDR(REGS_CIU_BASE, 0XB0)/*<var Processor: App> CPU Address Filter Config Register*/
#define REG_CIU_CLUSTER0_COREx_CONF0                      ASR_ADDR(REGS_CIU_BASE, 0xD0)/*<var Processor: App (single)> Cluster 0 Core x Configuration Register*/
#define REG_CIU_CLUSTER0_COREx_CONF1                      ASR_ADDR(REGS_CIU_BASE, 0xE0)/*<var Processor: App (single)> Cluster 0 Core x Configuration Register*/
#define REG_CIU_CLUSTER0_COREx_CONF2                      ASR_ADDR(REGS_CIU_BASE, 0xF0)/*<var Processor: App (single)> Cluster 0 Core x Configuration Register*/
#define REG_CIU_CLUSTER0_COREx_CONF3                      ASR_ADDR(REGS_CIU_BASE, 0xF8)/*<var Processor: App (single)> Cluster 0 Core x Configuration Register*/
#define REG_CIU_CLUSTER1_COREx_CONF0                      ASR_ADDR(REGS_CIU_BASE, 0xD4)/*<var Processor: App (single)> Cluster 1 Core x Configuration Register*/
#define REG_CIU_CLUSTER1_COREx_CONF1                      ASR_ADDR(REGS_CIU_BASE, 0xE4)/*<var Processor: App (single)> Cluster 1 Core x Configuration Register*/
#define REG_CIU_CLUSTER1_COREx_CONF2                      ASR_ADDR(REGS_CIU_BASE, 0xF4)/*<var Processor: App (single)> Cluster 1 Core x Configuration Register*/
#define REG_CIU_CLUSTER1_COREx_CONF3                      ASR_ADDR(REGS_CIU_BASE, 0xFC)/*<var Processor: App (single)> Cluster 1 Core x Configuration Register*/
#define REG_CIU_CAP_WARM_RESET_VECTOR                     ASR_ADDR(REGS_CIU_BASE, 0XD8)/*<var Processor: App> Warm Reset Vector Register*/
#define REG_CIU_SW_SCRATCH                                ASR_ADDR(REGS_CIU_BASE, 0XE8)/*Software Scratch Register*/
#define REG_CIU_VPU_MMU_CKG_CTRL                          ASR_ADDR(REGS_CIU_BASE, 0X100)/*VPU MMU Clock Gate Control Register*/
#define REG_CIU_VPU_MMU_SEC_CTRL                          ASR_ADDR(REGS_CIU_BASE, 0X104)/*VPU MMU Security Control Register*/
#define REG_CIU_VPU_MMU_SEC_RSA                           ASR_ADDR(REGS_CIU_BASE, 0X108)/*VPU MMU Security Read Start Address Register*/
#define REG_CIU_VPU_MMU_SEC_REA                           ASR_ADDR(REGS_CIU_BASE, 0X10C)/*VPU MMU Security Read End Address Register*/
#define REG_CIU_VPU_MMU_SEC_WSA                           ASR_ADDR(REGS_CIU_BASE, 0X110)/*VPU MMU Security Write Start Address Register*/
#define REG_CIU_VPU_MMU_SEC_WEA                           ASR_ADDR(REGS_CIU_BASE, 0X114)/*VPU MMU Security Write End Address Register*/
#define REG_CIU_FBRC_QOS_CTRL1                            ASR_ADDR(REGS_CIU_BASE, 0X118)/*AXI Fabric QoS Control 1 Register*/
#define REG_CIU_FBRC_QOS_CTRL2                            ASR_ADDR(REGS_CIU_BASE, 0X11C)/*AXI Fabric QoS Control 2 Register*/
#define REG_CIU_FBRC_QOS_CTRL3                            ASR_ADDR(REGS_CIU_BASE, 0X120)/*AXI Fabric QoS Control 3 Register*/
#define REG_CIU_FBRC_QOS_CTRL4                            ASR_ADDR(REGS_CIU_BASE, 0X124)/*AXI Fabric QoS Control4 Register*/
#define REG_CIU_APDMA_XTC                                 ASR_ADDR(REGS_CIU_BASE, 0X128)/*AP DMA Memory Timing Control Register*/
#define REG_CIU_LCD_CFG                                   ASR_ADDR(REGS_CIU_BASE, 0X12C)/*LCD Config*/
#define REG_CIU_LCD_MEM_EMA                               ASR_ADDR(REGS_CIU_BASE, 0X130)/*LCD Memory Extra Margin Adjustment*/
#define REG_CIU_USB_OTG_MEM_EMA                           ASR_ADDR(REGS_CIU_BASE, 0X134)/*USB OTG Memory Extra Margin Adjustment*/
#define REG_CIU_SEC_ONETIME_PROG                          ASR_ADDR(REGS_CIU_BASE, 0X140)/*Secure OneTime Program Register*/
#define REG_CIU_DDRC_MEM_EMA                              ASR_ADDR(REGS_CIU_BASE, 0X144)/*DDRC MEM EMA CFG Register*/
#define REG_CIU_BCM_MEM_EMA                               ASR_ADDR(REGS_CIU_BASE, 0X148)/*BCM MEM EMA CFG Register*/
#define REG_CIU_DMA_MEM_EMA                               ASR_ADDR(REGS_CIU_BASE, 0X14C)/*DMA MEM EMA CFG Register*/
#define REG_CIU_NSAID_SETTING                             ASR_ADDR(REGS_CIU_BASE, 0X150)/*NSAID Setting Register*/
#define REG_CIU_GPIO_SEC_0                                ASR_ADDR(REGS_CIU_BASE, 0X154)/*GPIO Secure Register 0*/
#define REG_CIU_GPIO_SEC_1                                ASR_ADDR(REGS_CIU_BASE, 0X158)/*GPIO Secure Register 1*/
#define REG_CIU_GPIO_SEC_2                                ASR_ADDR(REGS_CIU_BASE, 0X15C)/*GPIO Secure Register 2*/
#define REG_CIU_GPIO_SEC_3                                ASR_ADDR(REGS_CIU_BASE, 0X160)/*GPIO Secure Register 3*/
#define REG_CIU_CPU_ETB_SET                               ASR_ADDR(REGS_CIU_BASE, 0X164)/*CPU ETB Memory Setup Register*/
#define REG_CIU_GNSS_CODE_INIT                            ASR_ADDR(REGS_CIU_BASE, 0X168)/*GNSS Code Initialization Register*/
#define REG_CIU_GNSS_SQU_START_ADDR                       ASR_ADDR(REGS_CIU_BASE, 0X16C)/*GNSS SQU Start Address Register*/
#define REG_CIU_GNSS_SQU_END_ADDR                         ASR_ADDR(REGS_CIU_BASE, 0X170)/*GNSS SQU End Address Register*/
#define REG_CIU_GNSS_DDR_START_ADDR                       ASR_ADDR(REGS_CIU_BASE, 0X174)/*GNSS DDR Start Address Register*/
#define REG_CIU_GNSS_DDR_END_ADDR                         ASR_ADDR(REGS_CIU_BASE, 0X178)/*GNSS DDR End Address Register*/
#define REG_CIU_GNSS_DMA_DDR_START_ADDR                   ASR_ADDR(REGS_CIU_BASE, 0X17C)/*GNSS DMA DDR Start Address Register*/
#define REG_CIU_GNSS_DMA_DDR_END_ADDR                     ASR_ADDR(REGS_CIU_BASE, 0X180)/*GNSS DDR End Address Register*/
#define REG_CIU_GNSS_IRQ                                  ASR_ADDR(REGS_CIU_BASE, 0X184)/*GNSS IRQ Register*/
#define REG_CIU_GNSS_WAKEUP                               ASR_ADDR(REGS_CIU_BASE, 0X188)/*GNSS Wakeup Register*/
#define REG_CIU_MC_ADDR_HASH_EN                           ASR_ADDR(REGS_CIU_BASE, 0X198)/*Address hash for DDR channel enable Register*/
#define REG_CIU_RST_VEC_BASE_ADDRESS                      ASR_ADDR(REGS_CIU_BASE, 0X1B0)/*<var Processor: App> AARCH64 Reset Vector Base Address*/
#define REG_CIU_RST_VEC_BASE_ADDRESS_HIGH                 ASR_ADDR(REGS_CIU_BASE, 0X1B4)/*<var Processor: App> AARCH64 Reset Vector Base Address High*/
#define REG_CIU_CLUSTERxBOOT_STATE0                       ASR_ADDR(REGS_CIU_BASE, 0x1B8)/*<var Processor: App (single)> Cluster x Boot State Register*/
#define REG_CIU_CLUSTERxBOOT_STATE1                       ASR_ADDR(REGS_CIU_BASE, 0x1BC)/*<var Processor: App (single)> Cluster x Boot State Register*/
#define REG_CIU_CLUSTERxBOOT_STATE2                       ASR_ADDR(REGS_CIU_BASE, 0x1CC)/*<var Processor: App (single)> Cluster x Boot State Register*/
#define REG_CIU_CLUSTER2_COREx_CONF0                      ASR_ADDR(REGS_CIU_BASE, 0x1D0)/*<var Processor: App (single)> Cluster 2 Core x Configuration Register*/
#define REG_CIU_CLUSTER2_COREx_CONF1                      ASR_ADDR(REGS_CIU_BASE, 0x1D4)/*<var Processor: App (single)> Cluster 2 Core x Configuration Register*/
#define REG_CIU_CLUSTER2_COREx_CONF2                      ASR_ADDR(REGS_CIU_BASE, 0x1D8)/*<var Processor: App (single)> Cluster 2 Core x Configuration Register*/
#define REG_CIU_CLUSTER2_COREx_CONF3                      ASR_ADDR(REGS_CIU_BASE, 0x1DC)/*<var Processor: App (single)> Cluster 2 Core x Configuration Register*/
#define REG_CIU_CLUSTER2_COREx_CONF                       ASR_ADDR(REGS_CIU_BASE, 0X1E0)/*<var Processor: App (single)> Cluster 2 Core x Configuration Register*/
#define REG_CIU_Offset:0x1e0                              ASR_ADDR(REGS_CIU_BASE, 0X1E4)/*ISP_NSAID_CTRL0*/
#define REG_CIU_Offset:0x1e4                              ASR_ADDR(REGS_CIU_BASE, 0X1E8)/*ISP_NSAID_CTRL1*/
#define REG_CIU_Offset:0x1e8                              ASR_ADDR(REGS_CIU_BASE, 0X1F8)/*ISP_NSAID_CTRL2*/
#define REG_CIU_FAB_TIMEOUT_CTRL                          ASR_ADDR(REGS_CIU_BASE, 0X230)/*AXI Fabric Timeout Control Register*/
#define REG_CIU_STATE_HOLD_CTRL                           ASR_ADDR(REGS_CIU_BASE, 0X234)/*State Hold Ctrl Register*/
#define REG_CIU_FAB_TIMEOUT_ID_RT                         ASR_ADDR(REGS_CIU_BASE, 0X238)/*Real Time AXI Fabric Timeout Transaction ID Register*/
#define REG_CIU_FAB_TIMEOUT_STATUS0_RT                    ASR_ADDR(REGS_CIU_BASE, 0X23C)/*Real Time AXI Fabric Timeout Status0 Register*/
#define REG_CIU_FAB_TIMEOUT_STATUS1_RT                    ASR_ADDR(REGS_CIU_BASE, 0X240)/*Real Time AXI Fabric Timeout Status1 Register*/
#define REG_CIU_DVC_STATUS_RT                             ASR_ADDR(REGS_CIU_BASE, 0X244)/*Real Time DVC Status Register*/
#define REG_CIU_DFC_STATUS_RT                             ASR_ADDR(REGS_CIU_BASE, 0X248)/*Real Time DCLK Hardware FC Status Register*/
#define REG_CIU_FC_DONE_STATUS_RT                         ASR_ADDR(REGS_CIU_BASE, 0X24C)/*Real Time FC Done Status Register*/
#define REG_CIU_SPAPDPCP_PM_STATE_REG_RT                  ASR_ADDR(REGS_CIU_BASE, 0X250)/*Real Time SPAPDPCP PM State Register*/
#define REG_CIU_PLL_STATUS_REG_RT                         ASR_ADDR(REGS_CIU_BASE, 0X254)/*Real Time PLL Status Register*/
#define REG_CIU_APC0_PM_STATE_REG_RT                      ASR_ADDR(REGS_CIU_BASE, 0X258)/*Real Time APC0 PM State Register*/
#define REG_CIU_APC1_PM_STATE_REG_RT                      ASR_ADDR(REGS_CIU_BASE, 0X25C)/*Real Time APC1 PM State Register*/
#define REG_CIU_FAB_TIMEOUT_ID_TO                         ASR_ADDR(REGS_CIU_BASE, 0X260)/*AXI Fabric Timeout Transaction ID Register*/
#define REG_CIU_FAB_TIMEOUT_STATUS0_TO                    ASR_ADDR(REGS_CIU_BASE, 0X264)/*AXI Fabric Timeout Status0 Register*/
#define REG_CIU_FAB_TIMEOUT_STATUS1_TO                    ASR_ADDR(REGS_CIU_BASE, 0X268)/*AXI Fabric Timeout Status1 Register*/
#define REG_CIU_DVC_STATUS_TO                             ASR_ADDR(REGS_CIU_BASE, 0X26C)/*DVC Status Register*/
#define REG_CIU_DFC_STATUS_TO                             ASR_ADDR(REGS_CIU_BASE, 0X270)/*DCLK Hardware FC Status Register*/
#define REG_CIU_FC_DONE_STATUS_TO                         ASR_ADDR(REGS_CIU_BASE, 0X274)/*FC Done Status Register*/
#define REG_CIU_SPAPDPCP_PM_STATE_REG_TO                  ASR_ADDR(REGS_CIU_BASE, 0X278)/*SPAPDPCP PM State Register*/
#define REG_CIU_PLL_STATUS_REG_TO                         ASR_ADDR(REGS_CIU_BASE, 0X27C)/*PLL Status Register*/
#define REG_CIU_APC0_PM_STATE_REG_TO                      ASR_ADDR(REGS_CIU_BASE, 0X280)/*APC0 PM State Register*/
#define REG_CIU_APC1_PM_STATE_REG_TO                      ASR_ADDR(REGS_CIU_BASE, 0X284)/*APC1 PM State Register*/
#define REG_CIU_FAB_TIMEOUT_ID_HD                         ASR_ADDR(REGS_CIU_BASE, 0X288)/*Real Time AXI Fabric Timeout Transaction ID Register*/
#define REG_CIU_FAB_TIMEOUT_STATUS0_HD                    ASR_ADDR(REGS_CIU_BASE, 0X28C)/*Real Time AXI Fabric Timeout Status0 Register*/
#define REG_CIU_FAB_TIMEOUT_STATUS1_HD                    ASR_ADDR(REGS_CIU_BASE, 0X290)/*Real Time AXI Fabric Timeout Status1 Register*/
#define REG_CIU_DVC_STATUS_HD                             ASR_ADDR(REGS_CIU_BASE, 0X294)/*Real Time DVC Status Register*/
#define REG_CIU_DFC_STATUS_HD                             ASR_ADDR(REGS_CIU_BASE, 0X298)/*Real Time DCLK Hardware FC Status Register*/
#define REG_CIU_FC_DONE_STATUS_HD                         ASR_ADDR(REGS_CIU_BASE, 0X29C)/*Real Time FC Done Status Register*/
#define REG_CIU_SPAPDPCP_PM_STATE_REG_HD                  ASR_ADDR(REGS_CIU_BASE, 0X2A0)/*Real Time SPAPDPCP PM State Register*/
#define REG_CIU_PLL_STATUS_REG_HD                         ASR_ADDR(REGS_CIU_BASE, 0X2A4)/*Real Time PLL Status Register*/
#define REG_CIU_APC0_PM_STATE_REG_HD                      ASR_ADDR(REGS_CIU_BASE, 0X2A8)/*Real Time APC0 PM State Register*/
#define REG_CIU_APC1_PM_STATE_REG_HD                      ASR_ADDR(REGS_CIU_BASE, 0X2AC)/*Real Time APC1 PM State Register*/
#define REG_CIU_APC2_PM_STATE_REG_RT                      ASR_ADDR(REGS_CIU_BASE, 0X2B0)/*Real Time APC2 PM State Register*/
#define REG_CIU_APC2_PM_STATE_REG_TO                      ASR_ADDR(REGS_CIU_BASE, 0X2B4)/*APC2 PM State Register*/
#define REG_CIU_APC2_PM_STATE_REG_HD                      ASR_ADDR(REGS_CIU_BASE, 0X2B8)/*Real Time APC2 PM State Register*/
#define REG_CIU_PLL_STATUS2_REG_RT                        ASR_ADDR(REGS_CIU_BASE, 0X2BC)/*Real Time PLL Status2 Register*/
#define REG_CIU_PLL_STATUS2_REG_TO                        ASR_ADDR(REGS_CIU_BASE, 0X2C0)/*PLL Status2 Register*/
#define REG_CIU_PLL_STATUS2_REG_HD                        ASR_ADDR(REGS_CIU_BASE, 0X2C4)/*Real Time PLL Status2 Register*/
#define REG_CIU_SW_SPINLOCK_REG                           ASR_ADDR(REGS_CIU_BASE, 0X2C8)
#define REG_CIU_SW_SPINLOCKREG_CLEAR                      ASR_ADDR(REGS_CIU_BASE, 0X2CC)
#define REG_CIU_MFPR_Disable_0                            ASR_ADDR(REGS_CIU_BASE, 0X2D0)/*MFPR Disable Register 0*/
#define REG_CIU_MFPR_Disable_1                            ASR_ADDR(REGS_CIU_BASE, 0X2D4)/*MFPR Disable Register 1*/
#define REG_CIU_MFPR_Disable_2                            ASR_ADDR(REGS_CIU_BASE, 0X2D8)/*MFPR Disable Register 2*/
#define REG_CIU_MFPR_Disable_3                            ASR_ADDR(REGS_CIU_BASE, 0X2DC)/*MFPR Disable Register 3*/
#define REG_CIU_MFPR_Disable_4                            ASR_ADDR(REGS_CIU_BASE, 0X2E0)/*MFPR Disable Register 4*/
#define REG_CIU_MFPR_Disable_5                            ASR_ADDR(REGS_CIU_BASE, 0X2E4)/*MFPR Disable Register 5*/
#define REG_CIU_MFPR_Disable_6                            ASR_ADDR(REGS_CIU_BASE, 0X2E8)/*MFPR Disable Register 6*/
#define REG_CIU_MFPR_Disable_7                            ASR_ADDR(REGS_CIU_BASE, 0X2EC)/*MFPR Disable Register 7*/



/* bits definitions for register REG_CIU_CHIP_ID */
#define BITS_REV_ID(_X_)                                  ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_CHIP_ID(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_CIU_CP_CPU_CONF */
#define BIT_REMAP_EN                                      ( BIT(31) )
#define BIT_SLBTCMSB0                                     ( BIT(14) )
#define BIT_NCPUHALT0                                     ( BIT(13) )
#define BIT_CFGNMFI0                                      ( BIT(12) )
#define BIT_LOCZRAMA0                                     ( BIT(11) )
#define BIT_INITRAMB0                                     ( BIT(10) )
#define BIT_INITRAMA0                                     ( BIT(9) )
#define BIT_VINITHI0                                      ( BIT(8) )
#define BIT_TEINIT                                        ( BIT(6) )
#define BIT_CFGIE                                         ( BIT(5) )
#define BIT_CFGEE                                         ( BIT(4) )

/* bits definitions for register REG_CIU_SW_CONFIG */
#define BITS_SW_USE44(_X_)                                ( (_X_) << 19 & (BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_SP_BRANCH                                     ( BIT(18) )
#define BIT_SW_USE46                                      ( BIT(17) )

/* bits definitions for register REG_CIU_CP_CPU_SRAM_SPD */
#define BITS_ITAG_RTC(_X_)                                ( (_X_) << 30 & (BIT(30)|BIT(31)) )
#define BITS_ITAG_WTC(_X_)                                ( (_X_) << 28 & (BIT(28)|BIT(29)) )
#define BITS_IDATA_RTC(_X_)                               ( (_X_) << 26 & (BIT(26)|BIT(27)) )
#define BITS_IDATA_WTC(_X_)                               ( (_X_) << 24 & (BIT(24)|BIT(25)) )
#define BITS_DDIRTY_RTC(_X_)                              ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BITS_DDIRTY_WTC(_X_)                              ( (_X_) << 20 & (BIT(20)|BIT(21)) )
#define BITS_DTAG_RTC(_X_)                                ( (_X_) << 18 & (BIT(18)|BIT(19)) )
#define BITS_DTAG_WTC(_X_)                                ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_DDATA_RTC(_X_)                               ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_DDATA_WTC(_X_)                               ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BITS_BTCM_RTC(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_BTCM_WTC(_X_)                                ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_ATCM_RTC(_X_)                                ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_ATCM_WTC(_X_)                                ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_BTCM_DLY(_X_)                                ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_ATCM_DLY(_X_)                                ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_CIU_CR5_PPX_CONF */
#define BITS_PPXBASE0(_X_)                                ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_INITPPX0                                      ( BIT(5) )
#define BITS_PPXSIZE079(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_CIU_CR5_PPV_CONF */
#define BITS_PPVBASE031:12(_X_)                           ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_PPXSIZE088(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_CIU_CP_L2C_ADDR_FILTER_CONF */
#define BIT_CP_L2C_FILTER_EN                              ( BIT(31) )
#define BITS_CP_L2C_FILTER_END31:20(_X_)                  ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_CP_L2C_FILTER_START31:20(_X_)                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )

/* bits definitions for register REG_CIU_MC_QOS_CTRL */
#define BIT_SC2_QOS_SEL                                   ( BIT(31) )
#define BIT_DC4_QOS_SEL                                   ( BIT(30) )
#define BITS_VPU_AXI_QOS(_X_)                             ( (_X_) << 26 & (BIT(26)|BIT(27)) )
#define BITS_LCD_AXI_QOS(_X_)                             ( (_X_) << 24 & (BIT(24)|BIT(25)) )
#define BITS_DRAGON_AXI_QOS(_X_)                          ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BITS_CP_AXI_QOS(_X_)                              ( (_X_) << 20 & (BIT(20)|BIT(21)) )
#define BITS_GC_AXI_QOS(_X_)                              ( (_X_) << 18 & (BIT(18)|BIT(19)) )
#define BITS_ISP_AXI_QOS(_X_)                             ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_LTEDMA_AXI_QOS(_X_)                          ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_GNSS_AXI_QOS(_X_)                            ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BITS_WTM_AXI_QOS(_X_)                             ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BITS_USB_DEV_AXI_QOS(_X_)                         ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_DTC_AXI_QOS(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_DMA_AXI_QOS_S5(_X_)                          ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_MSA_AXI_QOS(_X_)                             ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_CIU_SYS_BOOT_CNTRL */
#define BIT_RPMB                                          ( BIT(31) )
#define BIT_DOWN_KEY_DIS                                  ( BIT(30) )
#define BITS_EMMC_CLK_SRC(_X_)                            ( (_X_) << 28 & (BIT(28)|BIT(29)) )
#define BIT_EMMC_PHY                                      ( BIT(21) )
#define BITS_EMMC_DIV(_X_)                                ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)) )
#define BITS_TIMER_FREQ(_X_)                              ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)) )
#define BIT_TIMER_MODE                                    ( BIT(14) )
#define BIT_ENCRYPT_BOOT                                  ( BIT(13) )
#define BIT_ANTI_ROLLBACK                                 ( BIT(12) )
#define BITS_BOOTROM_OPER_MODE(_X_)                       ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BITS_DISABLE_DFT_SCAN(_X_)                        ( (_X_) << 7 & (BIT(7)|BIT(8)) )
#define BITS_DISABLE_AP_JTAG(_X_)                         ( (_X_) << 5 & (BIT(5)|BIT(6)) )

/* bits definitions for register REG_CIU_SW_BRANCH_ADDR */
#define BITS_BRANCH_ADDR(_X_)                             (_X_)

/* bits definitions for register REG_CIU_CP_L2C_CONF */
#define BITS_CP_L2C_REGFILEBASE31:12(_X_)                 ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CP_L2C_BEARLYEN                               ( BIT(1) )
#define BIT_CP_L2C_CFGBIGEND                              ( BIT(0) )

/* bits definitions for register REG_CIU_CP_L2C_SRAM_CONF */
#define BITS_CP_L2C_TAG_RTC(_X_)                          ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_CP_L2C_TAG_WTC(_X_)                          ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_CP_L2C_DATA_RTC(_X_)                         ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_CP_L2C_DATA_WTC(_X_)                         ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_CIU_BROM_IPCx2 */
#define BITS_BROM_IPC0(_X_)                               (_X_)

/* bits definitions for register REG_CIU_MC_CONF */
#define BIT_MC_WDB_STATUS                                 ( BIT(31) )
#define BIT_CAP_FAB_ACLKM0_GATE_EN                        ( BIT(30) )
#define BIT_CAP_FAB_ACLK_GATE_EN                          ( BIT(29) )
#define BIT_FBRC2_ACLK_GATE_EN                            ( BIT(27) )
#define BIT_FBRC1_ACLK_GATE_EN                            ( BIT(26) )
#define BIT_CSAP_ACLK_GATE_EN                             ( BIT(21) )
#define BIT_SP_ACLK_GATE_EN                               ( BIT(20) )
#define BIT_MC_DCLK_GATE_EN                               ( BIT(19) )
#define BIT_FBRC1_CP_ACLK_GATE_EN                         ( BIT(18) )
#define BIT_FBRC1_AP_ACLK_GATE_EN                         ( BIT(17) )
#define BIT_CP_FAB_ACLK_GATE_EN                           ( BIT(16) )
#define BIT_MC_P7_ACLK_GATE_EN                            ( BIT(15) )
#define BIT_MC_P6_ACLK_GATE_EN                            ( BIT(14) )
#define BIT_MC_P5_ACLK_GATE_EN                            ( BIT(13) )
#define BIT_MC_P4_ACLK_GATE_EN                            ( BIT(12) )
#define BIT_MC_P3_ACLK_GATE_EN                            ( BIT(11) )
#define BIT_MC_P2_ACLK_GATE_EN                            ( BIT(10) )
#define BIT_MC_P1_ACLK_GATE_EN                            ( BIT(9) )
#define BIT_MC_P0_ACLK_GATE_EN                            ( BIT(8) )
#define BIT_MC_PHY_RST_MASK                               ( BIT(6) )
#define BIT_MC_PHY_DLL_DIS                                ( BIT(5) )
#define BIT_MC_WDB_DRAIN_REQ                              ( BIT(4) )
#define BIT_MC_PDFVSSM                                    ( BIT(2) )
#define BIT_MC_PDLVMC                                     ( BIT(1) )
#define BIT_MC_PDWN                                       ( BIT(0) )

/* bits definitions for register REG_CIU_TOP_MEM_RTC_WTC_SPD */
#define BITS_DMA_AXI_MEM_WTC(_X_)                         ( (_X_) << 20 & (BIT(20)|BIT(21)) )
#define BITS_DMA_AXI_MEM_RTC(_X_)                         ( (_X_) << 16 & (BIT(16)|BIT(17)) )

/* bits definitions for register REG_CIU_CS_CONF */
#define BIT_AUDIO_SW_ATRESETN                             ( BIT(17) )
#define BIT_AUDIO_SW_PRESETDBGN                           ( BIT(16) )
#define BIT_ETF_PDWN                                      ( BIT(14) )
#define BITS_ETF_EMAW(_X_)                                ( (_X_) << 11 & (BIT(11)|BIT(12)) )
#define BITS_ETF_EMA(_X_)                                 ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BITS_TPIUPMAX(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_CIU_CS_DEBUG_CONF */
#define BIT_DBGEN254                                      ( BIT(20) )
#define BIT_SPIDEN255                                     ( BIT(19) )
#define BIT_SPNIDEN256                                    ( BIT(18) )
#define BIT_NIDEN257                                      ( BIT(17) )
#define BIT_DBGSWENANBLE                                  ( BIT(16) )
#define BIT_DAP_APB_SECURE_EN                             ( BIT(0) )

/* bits definitions for register REG_CIU_MC_AXI_URGENT */
#define BITS_DMC_AWURGENT(_X_)                            ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_DMC_ARURGENT(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CIU_SYSSEC_CTRL_1 */
#define BIT_PMU_SEC_EN                                    ( BIT(31) )
#define BIT_I2C8_SEC                                      ( BIT(28) )
#define BIT_I2C7_SEC                                      ( BIT(27) )
#define BIT_I2C5_SEC                                      ( BIT(26) )
#define BIT_SSP2_SEC                                      ( BIT(25) )
#define BIT_DIS_PREADY_SEL                                ( BIT(24) )
#define BIT_GEC_SEC                                       ( BIT(23) )
#define BIT_SEL_SSK_AES_KEY                               ( BIT(22) )
#define BIT_XM4_SQU_SEC                                   ( BIT(21) )
#define BIT_KEYPAD_SEC                                    ( BIT(16) )
#define BIT_I2C3_SEC                                      ( BIT(15) )
#define BIT_SEC_RTC_SEC                                   ( BIT(14) )
#define BIT_SSP0_SEC                                      ( BIT(13) )
#define BIT_NDR_TIMER_SEC                                 ( BIT(12) )
#define BIT_TIMER1_SEC                                    ( BIT(11) )
#define BIT_UART1_SEC                                     ( BIT(10) )
#define BIT_DMA_SEC                                       ( BIT(8) )
#define BIT_NONSEC_AP_2_XM4_DIS                           ( BIT(5) )
#define BIT_XM4_2_ISP_DIS                                 ( BIT(4) )
#define BIT_ISP_2_XM4_DIS                                 ( BIT(3) )
#define BIT_AUDIO_SLAVE_SEC                               ( BIT(2) )
#define BIT_AUDIO_MASTER_SEC                              ( BIT(1) )
#define BIT_CP_SEC                                        ( BIT(0) )

/* bits definitions for register REG_CIU_SYSSEC_CTRL_2 */
#define BITS_DMA_SEC_CH(_X_)                              ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_FPID_EN(_X_)                                 ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_FUSE_READ_CLK_EN                              ( BIT(7) )
#define BITS_FUSE_READ_CLK_DIV_VAL(_X_)                   ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_UP_4G                                         ( BIT(0) )

/* bits definitions for register REG_CIU_MCB_CONFIG2 */
#define BIT_GPU_POSTED_WRSP_EN                            ( BIT(11) )
#define BIT_FABRIC2_S7_POSTED_WRSP_EN                     ( BIT(10) )
#define BIT_FABRIC1_S5_POSTED_WRSP_EN                     ( BIT(9) )
#define BIT_FABRIC1_S0_POSTED_WRSP_EN                     ( BIT(8) )
#define BIT_GC_FAST_EN                                    ( BIT(7) )
#define BIT_FABRIC1_S5_FAST_EN                            ( BIT(6) )
#define BIT_FABRIC1_S0_FAST_EN                            ( BIT(5) )
#define BIT_FABRIC2_VPU_FAST_EN                           ( BIT(4) )
#define BIT_FABRIC2_USB1_FAST_EN339                       ( BIT(3) )
#define BIT_FABRIC2_SD_FAST_EN                            ( BIT(2) )
#define BIT_FABRIC2_USB1_FAST_EN341                       ( BIT(1) )
#define BIT_FABRIC2_IRE_FAST_EN                           ( BIT(0) )

/* bits definitions for register REG_CIU_GPU_COHERENCY_FEATURE */
#define BITS_GPU_COHERENCY_FEATURE(_X_)                   ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_CIU_GPU_MEM_XTC */
#define BIT_GPU_MEM_PDWN                                  ( BIT(20) )
#define BITS_GPU_RF2P_FAST_WTC(_X_)                       ( (_X_) << 18 & (BIT(18)|BIT(19)) )
#define BITS_GPU_RF2P_FAST_RTC(_X_)                       ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_GPU_RF2P_GRP2_WTC(_X_)                       ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_GPU_RF2P_GRP2_RTC(_X_)                       ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BITS_GPU_RF2P_GRP1_WTC(_X_)                       ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BITS_GPU_RF2P_GRP1_RTC(_X_)                       ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_GPU_RF1P_GRP2_WTC(_X_)                       ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_GPU_RF1P_GRP2_RTC(_X_)                       ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_GPU_RF1P_GRP1_WTC(_X_)                       ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_GPU_RF1P_GRP1_RTC(_X_)                       ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_CIU_VPU_XTC */
#define BIT_VPU_ROM_PDWN                                  ( BIT(24) )
#define BITS_VPU_ROM_RTC_REF(_X_)                         ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BITS_VPU_ROM_RTC(_X_)                             ( (_X_) << 19 & (BIT(19)|BIT(20)|BIT(21)) )
#define BIT_VPU_RAM_PDFVSSM                               ( BIT(18) )
#define BIT_VPU_RAM_PDFVMC                                ( BIT(17) )
#define BIT_VPU_RAM_PDWN                                  ( BIT(16) )
#define BITS_VPU_SR2P_WTC(_X_)                            ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_VPU_SR2P_RTC(_X_)                            ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BITS_VPU_SR1P_WTC(_X_)                            ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BITS_VPU_SR1P_RTC(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_VPU_RF2P_WTC(_X_)                            ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_VPU_RF2P_RTC(_X_)                            ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_VPU_RF1P_WTC(_X_)                            ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_VPU_RF1P_RTC(_X_)                            ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_CIU_AUDIO_XTC */
#define BIT_AUDIO_DUMMY_CLOCK_SELECT                      ( BIT(30) )
#define BITS_AUDIO_RTC_ROM(_X_)                           ( (_X_) << 27 & (BIT(27)|BIT(28)|BIT(29)) )
#define BITS_AUDIO_RTC_REF(_X_)                           ( (_X_) << 25 & (BIT(25)|BIT(26)) )
#define BIT_AUDIO_MEM_CLKGATE_BYPASS                      ( BIT(22) )
#define BITS_AUDIO_MEM_DUMMY_CLK(_X_)                     ( (_X_) << 20 & (BIT(20)|BIT(21)) )
#define BIT_AUDIO_MEM_PDWM                                ( BIT(19) )
#define BIT_AUDIO_MEM_PDLVMC                              ( BIT(18) )
#define BIT_AUDIO_MEM_PDFVSSM                             ( BIT(17) )
#define BIT_AUDIO_MEM_FWALLBAR                            ( BIT(16) )
#define BITS_AUDIO_MEM_RTC_RF1P(_X_)                      ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_AUDIO_MEM_WTC_RF1P(_X_)                      ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BITS_AUDIO_MEM_RTC_RF2P(_X_)                      ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BITS_AUDIO_MEM_WTC_RF2P(_X_)                      ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_AUDIO_MEM_RTC_SR1P(_X_)                      ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_AUDIO_MEM_WTC_SR1P(_X_)                      ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_AUDIO_MEM_RTC_SR1PR(_X_)                     ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_AUDIO_MEM_WTC_SR1PR(_X_)                     ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_CIU_CAP_CPU_CONF_ADDR_FILTER */

/* bits definitions for register REG_CIU_CLUSTER0_COREx_CONF3 */
#define BIT_AARCH64432                                    ( BIT(28) )
#define BIT_DBGEN434                                      ( BIT(24) )
#define BIT_NIDEN435                                      ( BIT(23) )
#define BIT_SPIDEN436                                     ( BIT(22) )
#define BIT_SPNIDEN437                                    ( BIT(21) )
#define BIT_VINITHI439                                    ( BIT(19) )

/* bits definitions for register REG_CIU_CLUSTER1_COREx_CONF3 */
#define BIT_AARCH64448                                    ( BIT(28) )
#define BIT_DBGEN450                                      ( BIT(24) )
#define BIT_NIDEN451                                      ( BIT(23) )
#define BIT_SPIDEN452                                     ( BIT(22) )
#define BIT_SPNIDEN453                                    ( BIT(21) )
#define BIT_VINITHI455                                    ( BIT(19) )

/* bits definitions for register REG_CIU_CAP_WARM_RESET_VECTOR */
#define BITS_CAP_WARM_RESET_VECTOR(_X_)                   (_X_)

/* bits definitions for register REG_CIU_SW_SCRATCH */
#define BITS_SW_SCRATCH(_X_)                              (_X_)

/* bits definitions for register REG_CIU_VPU_MMU_CKG_CTRL */
#define BITS_CI_477(_X_)                                  ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_BBLK_GATE_DISABLE                             ( BIT(1) )
#define BIT_CCLK_GATE_DISABLE                             ( BIT(0) )

/* bits definitions for register REG_CIU_VPU_MMU_SEC_CTRL */
#define BITS_CI_486(_X_)                                  ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_VPU_AXI_SEC_SEL                               ( BIT(4) )
#define BIT_CI_488                                        ( BIT(3) )
#define BIT_SPNIDEN489                                    ( BIT(2) )
#define BIT_RSB_NS_S                                      ( BIT(1) )
#define BIT_WSB_NS_S                                      ( BIT(0) )

/* bits definitions for register REG_CIU_VPU_MMU_SEC_RSA */
#define BITS_RSB_ST_ADDR(_X_)                             ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_CIU_VPU_MMU_SEC_REA */
#define BITS_RSB_END_ADDR(_X_)                            ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_CIU_VPU_MMU_SEC_WSA */
#define BITS_WSB_ST_ADDR(_X_)                             ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_CIU_VPU_MMU_SEC_WEA */
#define BITS_WSB_END_ADDR(_X_)                            ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_CIU_FBRC_QOS_CTRL1 */
#define BITS_F1_M3_AR_QOS(_X_)                            ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_F1_M3_AW_QOS(_X_)                            ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_F1_M2_AR_QOS(_X_)                            ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_F1_M2_AW_QOS(_X_)                            ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_F1_M1_AR_QOS(_X_)                            ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_F1_M1_AW_QOS(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_F1_M0_AR_QOS(_X_)                            ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_F1_M0_AW_QOS(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CIU_FBRC_QOS_CTRL2 */
#define BITS_F1_M6_AR_QOS(_X_)                            ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_F1_M6_AW_QOS(_X_)                            ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_F1_M5_AR_QOS(_X_)                            ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_F1_M5_AW_QOS(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_F1_M4_AR_QOS(_X_)                            ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_F1_M4_AW_QOS(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CIU_FBRC_QOS_CTRL3 */
#define BITS_F2_M3_AR_QOS(_X_)                            ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_F2_M3_AW_QOS(_X_)                            ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_LTE_AW_QOS(_X_)                              ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_LTE_AR_QOS(_X_)                              ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_AUDIO_AW_QOS(_X_)                            ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_AUDIO_AR_QOS(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_CP_AW_QOS(_X_)                               ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_CP_AR_QOS(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CIU_FBRC_QOS_CTRL4 */
#define BITS_VPU_AW_QOS(_X_)                              ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_VPU_AR_QOS(_X_)                              ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_GNSS_AW_QOS(_X_)                             ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_GNSS_AR_QOS(_X_)                             ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_FABRIC1_AW_QOS(_X_)                          ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_FABRIC1_AR_QOS(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CIU_APDMA_XTC */
#define BIT_APDMA_DUMMY_CLOCK_SELECT                      ( BIT(11) )
#define BIT_APDMA_MEM_CLKGATE_BYPASS                      ( BIT(10) )
#define BITS_APDMA_MEM_DUMMY_CLK(_X_)                     ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BIT_APDMA_MEM_PDWM                                ( BIT(7) )
#define BIT_APDMA_MEM_PDLVMC                              ( BIT(6) )
#define BIT_APDMA_MEM_PDFVSSM                             ( BIT(5) )
#define BIT_APDMA_MEM_FWALLBAR                            ( BIT(4) )
#define BITS_APDMA_MEM_RTC_RF2P(_X_)                      ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_APDMA_MEM_WTC_RF2P(_X_)                      ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_CIU_LCD_CFG */
#define BIT_LCD_PARALLEL_IF_EN                            ( BIT(4) )
#define BIT_LCD_BYPASS_AD                                 ( BIT(0) )

/* bits definitions for register REG_CIU_LCD_MEM_EMA */
#define BIT_RET1N_DISABLE                                 ( BIT(31) )
#define BIT_SRDP_EMASB619                                 ( BIT(30) )
#define BITS_SRDP_EMAWB620(_X_)                           ( (_X_) << 28 & (BIT(28)|BIT(29)) )
#define BITS_SRDP_EMAB621(_X_)                            ( (_X_) << 25 & (BIT(25)|BIT(26)|BIT(27)) )
#define BIT_SRDP_EMASA622                                 ( BIT(24) )
#define BITS_SRDP_EMAWA623(_X_)                           ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BITS_SRDP_EMAA624(_X_)                            ( (_X_) << 19 & (BIT(19)|BIT(20)|BIT(21)) )
#define BIT_SR1P_EMAS625                                  ( BIT(18) )
#define BITS_SR1P_EMAW626(_X_)                            ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_SR1P_EMA627(_X_)                             ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)) )
#define BIT_RF2P_EMASA628                                 ( BIT(12) )
#define BITS_RF2P_EMAB629(_X_)                            ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BITS_RF2P_EMAA630(_X_)                            ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_RF1P_EMAS631                                  ( BIT(5) )
#define BITS_RF1P_EMAW632(_X_)                            ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BITS_RF1P_EMA633(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_CIU_USB_OTG_MEM_EMA */
#define BIT_SRDP_EMASB641                                 ( BIT(30) )
#define BITS_SRDP_EMAWB642(_X_)                           ( (_X_) << 28 & (BIT(28)|BIT(29)) )
#define BITS_SRDP_EMAB643(_X_)                            ( (_X_) << 25 & (BIT(25)|BIT(26)|BIT(27)) )
#define BIT_SRDP_EMASA644                                 ( BIT(24) )
#define BITS_SRDP_EMAWA645(_X_)                           ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BITS_SRDP_EMAA646(_X_)                            ( (_X_) << 19 & (BIT(19)|BIT(20)|BIT(21)) )
#define BIT_SR1P_EMAS647                                  ( BIT(18) )
#define BITS_SR1P_EMAW648(_X_)                            ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_SR1P_EMA649(_X_)                             ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)) )
#define BIT_RF2P_EMASA650                                 ( BIT(12) )
#define BITS_RF2P_EMAB651(_X_)                            ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BITS_RF2P_EMAA652(_X_)                            ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_RF1P_EMAS653                                  ( BIT(5) )
#define BITS_RF1P_EMAW654(_X_)                            ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BITS_RF1P_EMA655(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_CIU_SEC_ONETIME_PROG */
#define BIT_ONE_PROG                                      ( BIT(31) )
#define BIT_DFT_JTAG_EN                                   ( BIT(4) )
#define BIT_NORMAL_JTAG_EN                                ( BIT(2) )
#define BIT_SEC_JTAG_EN                                   ( BIT(1) )
#define BIT_JTAG_EN                                       ( BIT(0) )

/* bits definitions for register REG_CIU_DDRC_MEM_EMA */
#define BITS_DDRC_MEM_EMA(_X_)                            (_X_)

/* bits definitions for register REG_CIU_BCM_MEM_EMA */
#define BITS_BCM_MEM_EMA(_X_)                             (_X_)

/* bits definitions for register REG_CIU_DMA_MEM_EMA */
#define BITS_DMA_MEM_EMA(_X_)                             (_X_)

/* bits definitions for register REG_CIU_NSAID_SETTING */

/* bits definitions for register REG_CIU_GPIO_SEC_0 */
#define BITS_GPIO_SEC_0(_X_)                              (_X_)

/* bits definitions for register REG_CIU_GPIO_SEC_1 */
#define BITS_GPIO_SEC_1(_X_)                              (_X_)

/* bits definitions for register REG_CIU_GPIO_SEC_2 */
#define BITS_GPIO_SEC_2(_X_)                              (_X_)

/* bits definitions for register REG_CIU_GPIO_SEC_3 */
#define BITS_GPIO_SEC_3(_X_)                              (_X_)

/* bits definitions for register REG_CIU_CPU_ETB_SET */
#define BITS_CI_739(_X_)                                  (_X_)

/* bits definitions for register REG_CIU_GNSS_CODE_INIT */
#define BIT_GNSS_CODE_INIT_RDY                            ( BIT(1) )
#define BIT_GNSS_CODE_INIT_DONE                           ( BIT(0) )

/* bits definitions for register REG_CIU_GNSS_SQU_START_ADDR */
#define BITS_GNSS_SQU_SA(_X_)                             ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_CIU_GNSS_SQU_END_ADDR */
#define BITS_GNSS_SQU_EA(_X_)                             ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_CIU_GNSS_DDR_START_ADDR */
#define BITS_GNSS_DDR_SA(_X_)                             ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_CIU_GNSS_DDR_END_ADDR */
#define BITS_GNSS_DDR_EA(_X_)                             ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_CIU_GNSS_DMA_DDR_START_ADDR */
#define BITS_GNSS_DMA_DDR_SA(_X_)                         ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_CIU_GNSS_DMA_DDR_END_ADDR */
#define BITS_GNSS_DMA_DDR_EA(_X_)                         ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_CIU_GNSS_IRQ */
#define BIT_GNSS_IRQ_OUT_ST                               ( BIT(1) )
#define BIT_GNSS_IRQ_CLR                                  ( BIT(0) )

/* bits definitions for register REG_CIU_GNSS_WAKEUP */
#define BIT_AP_GNSS_WAKEUP                                ( BIT(0) )

/* bits definitions for register REG_CIU_MC_ADDR_HASH_EN */
#define BITS_ADDR_HASH_EN(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_HASH_EN(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_CIU_RST_VEC_BASE_ADDRESS */
#define BITS_RVBARADDR(_X_)                               ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_CIU_RST_VEC_BASE_ADDRESS_HIGH */
#define BITS_RVBARADDRH0(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_CIU_CLUSTERxBOOT_STATE2 */
#define BIT_DVMENABLE                                     ( BIT(6) )
#define BIT_QOSOVERRIDE                                   ( BIT(5) )
#define BIT_ACCHANNELEN                                   ( BIT(4) )
#define BIT_SYSBARDISABLE                                 ( BIT(3) )
#define BIT_BROADCASTOUTER                                ( BIT(2) )
#define BIT_BROADCASTINNER                                ( BIT(1) )
#define BIT_BROADCASTCACHEMAINT                           ( BIT(0) )

/* bits definitions for register REG_CIU_CLUSTER2_COREx_CONF3 */
#define BIT_AARCH64887                                    ( BIT(28) )
#define BIT_DBGEN889                                      ( BIT(24) )
#define BIT_NIDEN890                                      ( BIT(23) )
#define BIT_SPIDEN891                                     ( BIT(22) )
#define BIT_SPNIDEN892                                    ( BIT(21) )
#define BIT_VINITHI894                                    ( BIT(19) )

/* bits definitions for register REG_CIU_CLUSTER2_COREx_CONF */
#define BITS_CI_900(_X_)                                  ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CI_901(_X_)                                  ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_CI_902(_X_)                                  ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_CI_903(_X_)                                  ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_CI_904(_X_)                                  ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_CI_905(_X_)                                  ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_CI_906(_X_)                                  ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_CI_907(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CIU_Offset:0x1e0 */
#define BITS_CI_912(_X_)                                  ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CI_913(_X_)                                  ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_CI_914(_X_)                                  ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_CI_915(_X_)                                  ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_CI_916(_X_)                                  ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_CI_917(_X_)                                  ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_CI_918(_X_)                                  ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_CI_919(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CIU_Offset:0x1e4 */
#define BITS_CI_925(_X_)                                  ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_CI_926(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CIU_Offset:0x1e8 */
#define BIT_ISP_AP_HARDMUX_CTRL                           ( BIT(0) )

/* bits definitions for register REG_CIU_FAB_TIMEOUT_CTRL */
#define BIT_CI_AUTORESP_TYPE941                           ( BIT(31) )
#define BIT_CI_AUTORESP_EN942                             ( BIT(30) )
#define BIT_CI_TIMEOUT_INT_MSK944                         ( BIT(29) )
#define BIT_CI_FAB_MON_RST947                             ( BIT(28) )
#define BIT_CI_FAB_MON_CLR948                             ( BIT(27) )
#define BITS_CI_TIMEOUT_VAL950(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_CIU_STATE_HOLD_CTRL */
#define BIT_CI_STATE_HOLD_CTRL960                         ( BIT(0) )

/* bits definitions for register REG_CIU_FAB_TIMEOUT_ID_RT */
#define BIT_WR_TIMEOUT_IND968                             ( BIT(31) )
#define BITS_TIMEOUT_TX_WID970(_X_)                       ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_RD_TIMEOUT_IND971                             ( BIT(15) )
#define BITS_TIMEOUT_TX_RID973(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_CIU_FAB_TIMEOUT_STATUS0_RT */
#define BITS_TIMEOUT_WADDR981(_X_)                        ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_WR_TIMEOUT_IND983                             ( BIT(0) )

/* bits definitions for register REG_CIU_FAB_TIMEOUT_STATUS1_RT */
#define BITS_TIMEOUT_RADDR991(_X_)                        ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_RD_TIMEOUT_IND993                             ( BIT(0) )

/* bits definitions for register REG_CIU_DVC_STATUS_RT */
#define BITS_CAUSE1002(_X_)                               ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_TVL1004(_X_)                                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_CVL1006(_X_)                                 ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DVC_STATUS1008                                ( BIT(0) )

/* bits definitions for register REG_CIU_DFC_STATUS_RT */
#define BITS_DFC_CAUSE1017(_X_)                           ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BITS_TFL1018(_X_)                                 ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_CFL1019(_X_)                                 ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DFC_STATUS1020                                ( BIT(0) )

/* bits definitions for register REG_CIU_FC_DONE_STATUS_RT */
#define BIT_GIC500_ECC_FATAL_ERROR1029                    ( BIT(10) )
#define BIT_AP_C2_FC_DONE1030                             ( BIT(9) )
#define BIT_AP_C1_FC_DONE1031                             ( BIT(8) )
#define BIT_AP_C0_FC_DONE1033                             ( BIT(6) )
#define BIT_DCLK_FC_DONE1034                              ( BIT(5) )
#define BIT_ACLK_FC_DONE1035                              ( BIT(4) )
#define BITS_DFC_STATE1036(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CIU_SPAPDPCP_PM_STATE_REG_RT */
#define BITS_SP_STATE1045(_X_)                            ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BITS_AP_STATE1046(_X_)                            ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BITS_CP_STATE1047(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BITS_WFSTATE1049(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CIU_PLL_STATUS_REG_RT */
#define BIT_PLL4_LOCK1057                                 ( BIT(31) )
#define BIT_PLL3_LOCK1058                                 ( BIT(30) )
#define BIT_PLL2_LOCK1059                                 ( BIT(29) )
#define BIT_PLL1_LOCK1060                                 ( BIT(28) )
#define BITS_CLK_DIV_INFO1061(_X_)                        ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_PLL_SEL_INFO1062(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for register REG_CIU_APC0_PM_STATE_REG_RT */
#define BITS_C0_PM_STATE1071(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )

/* bits definitions for register REG_CIU_APC1_PM_STATE_REG_RT */
#define BITS_C1_PM_STATE1080(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )

/* bits definitions for register REG_CIU_FAB_TIMEOUT_ID_TO */
#define BIT_WR_TIMEOUT_IND1088                            ( BIT(31) )
#define BITS_TIMEOUT_TX_WID1090(_X_)                      ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_RD_TIMEOUT_IND1091                            ( BIT(15) )
#define BITS_TIMEOUT_TX_RID1093(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_CIU_FAB_TIMEOUT_STATUS0_TO */
#define BITS_TIMEOUT_WADDR1101(_X_)                       ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_WR_TIMEOUT_IND1103                            ( BIT(0) )

/* bits definitions for register REG_CIU_FAB_TIMEOUT_STATUS1_TO */
#define BITS_TIMEOUT_RADDR1111(_X_)                       ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_RD_TIMEOUT_IND1113                            ( BIT(0) )

/* bits definitions for register REG_CIU_DVC_STATUS_TO */
#define BITS_CAUSE1122(_X_)                               ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_TVL1124(_X_)                                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_CVL1126(_X_)                                 ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DVC_STATUS1128                                ( BIT(0) )

/* bits definitions for register REG_CIU_DFC_STATUS_TO */
#define BITS_DFC_CAUSE1137(_X_)                           ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BITS_TFL1138(_X_)                                 ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_CFL1139(_X_)                                 ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DFC_STATUS1140                                ( BIT(0) )

/* bits definitions for register REG_CIU_FC_DONE_STATUS_TO */
#define BIT_GIC500_ECC_FATAL_ERROR1149                    ( BIT(10) )
#define BIT_AP_C2_FC_DONE1150                             ( BIT(9) )
#define BIT_AP_C1_FC_DONE1151                             ( BIT(8) )
#define BIT_AP_C0_FC_DONE1153                             ( BIT(6) )
#define BIT_DCLK_FC_DONE1154                              ( BIT(5) )
#define BIT_ACLK_FC_DONE1155                              ( BIT(4) )
#define BITS_DFC_STATE1156(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CIU_SPAPDPCP_PM_STATE_REG_TO */
#define BITS_SP_STATE1165(_X_)                            ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BITS_AP_STATE1166(_X_)                            ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BITS_CP_STATE1167(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BITS_WFSTATE1169(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CIU_PLL_STATUS_REG_TO */
#define BIT_PLL4_LOCK1177                                 ( BIT(31) )
#define BIT_PLL3_LOCK1178                                 ( BIT(30) )
#define BIT_PLL2_LOCK1179                                 ( BIT(29) )
#define BIT_PLL1_LOCK1180                                 ( BIT(28) )
#define BITS_CLK_DIV_INFO1181(_X_)                        ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_PLL_SEL_INFO1182(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for register REG_CIU_APC0_PM_STATE_REG_TO */
#define BITS_C0_PM_STATE1191(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )

/* bits definitions for register REG_CIU_APC1_PM_STATE_REG_TO */
#define BITS_C1_PM_STATE1200(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )

/* bits definitions for register REG_CIU_FAB_TIMEOUT_ID_HD */
#define BIT_WR_TIMEOUT_IND1208                            ( BIT(31) )
#define BITS_TIMEOUT_TX_WID1210(_X_)                      ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_RD_TIMEOUT_IND1211                            ( BIT(15) )
#define BITS_TIMEOUT_TX_RID1213(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_CIU_FAB_TIMEOUT_STATUS0_HD */
#define BITS_TIMEOUT_WADDR1221(_X_)                       ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_WR_TIMEOUT_IND1223                            ( BIT(0) )

/* bits definitions for register REG_CIU_FAB_TIMEOUT_STATUS1_HD */
#define BITS_TIMEOUT_RADDR1231(_X_)                       ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_RD_TIMEOUT_IND1233                            ( BIT(0) )

/* bits definitions for register REG_CIU_DVC_STATUS_HD */
#define BITS_CAUSE1242(_X_)                               ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_TVL1244(_X_)                                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_CVL1246(_X_)                                 ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DVC_STATUS1248                                ( BIT(0) )

/* bits definitions for register REG_CIU_DFC_STATUS_HD */
#define BITS_DFC_CAUSE1257(_X_)                           ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BITS_TFL1258(_X_)                                 ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_CFL1259(_X_)                                 ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DFC_STATUS1260                                ( BIT(0) )

/* bits definitions for register REG_CIU_FC_DONE_STATUS_HD */
#define BIT_GIC500_ECC_FATAL_ERROR1269                    ( BIT(10) )
#define BIT_AP_C2_FC_DONE1270                             ( BIT(9) )
#define BIT_AP_C1_FC_DONE1271                             ( BIT(8) )
#define BIT_AP_C0_FC_DONE1273                             ( BIT(6) )
#define BIT_DCLK_FC_DONE1274                              ( BIT(5) )
#define BIT_ACLK_FC_DONE1275                              ( BIT(4) )
#define BITS_DFC_STATE1276(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CIU_SPAPDPCP_PM_STATE_REG_HD */
#define BITS_SP_STATE1285(_X_)                            ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BITS_AP_STATE1286(_X_)                            ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BITS_CP_STATE1287(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BITS_WFSTATE1289(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CIU_PLL_STATUS_REG_HD */
#define BIT_PLL4_LOCK1297                                 ( BIT(31) )
#define BIT_PLL3_LOCK1298                                 ( BIT(30) )
#define BIT_PLL2_LOCK1299                                 ( BIT(29) )
#define BIT_PLL1_LOCK1300                                 ( BIT(28) )
#define BITS_CLK_DIV_INFO1301(_X_)                        ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_PLL_SEL_INFO1302(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for register REG_CIU_APC0_PM_STATE_REG_HD */
#define BITS_C0_PM_STATE1311(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )

/* bits definitions for register REG_CIU_APC1_PM_STATE_REG_HD */
#define BITS_C1_PM_STATE1320(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )

/* bits definitions for register REG_CIU_APC2_PM_STATE_REG_RT */
#define BITS_C2_PM_STATE1329(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )

/* bits definitions for register REG_CIU_APC2_PM_STATE_REG_TO */
#define BITS_C2_PM_STATE1337(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )

/* bits definitions for register REG_CIU_APC2_PM_STATE_REG_HD */
#define BITS_C2_PM_STATE1345(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )

/* bits definitions for register REG_CIU_PLL_STATUS2_REG_RT */
#define BITS_C2_CLK_DIV_INFO1354(_X_)                     ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_CIU_PLL_STATUS2_REG_TO */
#define BITS_C2_CLK_DIV_INFO1364(_X_)                     ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_CIU_PLL_STATUS2_REG_HD */
#define BITS_C2_CLK_DIV_INFO1374(_X_)                     ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_CIU_SW_SPINLOCK_REG */
#define BITS_SW_SPINLOCK(_X_)                             (_X_)

/* bits definitions for register REG_CIU_SW_SPINLOCKREG_CLEAR */
#define BIT_SW_SPINLOCK_CLEAR                             ( BIT(0) )

/* bits definitions for register REG_CIU_MFPR_Disable_0 */
#define BITS_MFPR_DIS_0(_X_)                              (_X_)

/* bits definitions for register REG_CIU_MFPR_Disable_1 */
#define BITS_MFPR_DIS_1(_X_)                              (_X_)

/* bits definitions for register REG_CIU_MFPR_Disable_2 */
#define BITS_MFPR_DIS_2(_X_)                              (_X_)

/* bits definitions for register REG_CIU_MFPR_Disable_3 */
#define BITS_MFPR_DIS_3(_X_)                              (_X_)

/* bits definitions for register REG_CIU_MFPR_Disable_4 */
#define BITS_MFPR_DIS_4(_X_)                              (_X_)

/* bits definitions for register REG_CIU_MFPR_Disable_5 */
#define BITS_MFPR_DIS_5(_X_)                              (_X_)

/* bits definitions for register REG_CIU_MFPR_Disable_6 */
#define BITS_MFPR_DIS_6(_X_)                              (_X_)

/* bits definitions for register REG_CIU_MFPR_Disable_7 */
#define BITS_MFPR_DIS_7(_X_)                              (_X_)

#endif
