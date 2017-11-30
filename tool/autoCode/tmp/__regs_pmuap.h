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


#ifndef __H_REGS_PMU_HEADFILE_H__
#define __H_REGS_PMU_HEADFILE_H__ __FILE__

#define	REGS_PMU

/* registers definitions for PMU */
#define REG_PMU_PMU_CC_AP                                 ASR_ADDR(REGS_PMU_BASE, 0X004)/*AP Clock Control Register*/
#define REG_PMU_PMU_DM_CC_AP                              ASR_ADDR(REGS_PMU_BASE, 0X00C)/*Dummy AP Clock Control Register*/
#define REG_PMU_PMU_FC_TIMER                              ASR_ADDR(REGS_PMU_BASE, 0X010)/*Frequency Change Timer Register*/
#define REG_PMU_PMU_CP_IDLE_CFG                           ASR_ADDR(REGS_PMU_BASE, 0X014)/*CP Idle Configuration Register*/
#define REG_PMU_PMU_SQU_CLK_GATE_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X01C)/*SQU Dynamic Clock Gate Control Register*/
#define REG_PMU_PMU_JPG_CLK_RES_CTRL                      ASR_ADDR(REGS_PMU_BASE, 0X020)/*JPG Clock/Reset Control Register*/
#define REG_PMU_PMU_CSI_CCIC2_CLK_RES_CTRL                ASR_ADDR(REGS_PMU_BASE, 0X024)/*CSI CCIC2 Clock/Reset Control Register*/
#define REG_PMU_PMU_CCIC1_CLK_GATE_CTRL                   ASR_ADDR(REGS_PMU_BASE, 0X028)/*CMOS Camera Interface Controller 1 Dynamic Clock Gate Control Register*/
#define REG_PMU_PMU_FBRC0_CLK_GATE_CTRL                   ASR_ADDR(REGS_PMU_BASE, 0X02C)/*Fabric0 Dynamic Clock Gate Control Register*/
#define REG_PMU_PMU_FBRC1_CLK_GATE_CTRL                   ASR_ADDR(REGS_PMU_BASE, 0X030)/*Fabric1 Dynamic Clock Gate Control Register*/
#define REG_PMU_PMU_ISP_CLK_RES_CTRL                      ASR_ADDR(REGS_PMU_BASE, 0X038)/*ISP Clock/Reset Control Register*/
#define REG_PMU_PMU_PMU_CLK_GATE_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X040)/*PMU Dynamic Clock Gate Control Register*/
#define REG_PMU_PMU_LCD_CLK_RES_CTRL1                     ASR_ADDR(REGS_PMU_BASE, 0X044)/*LCD Clock/Reset Control Register1*/
#define REG_PMU_PMU_LCD_CLK_RES_CTRL2                     ASR_ADDR(REGS_PMU_BASE, 0X04C)/*LCD Clock/Reset Control Register2*/
#define REG_PMU_PMU_CCIC_CLK_RES_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X050)/*CCIC Clock/Reset Control Register*/
#define REG_PMU_PMU_SDH0_CLK_RES_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X054)/*SDH0 Clock/Reset Control Register*/
#define REG_PMU_PMU_SDH1_CLK_RES_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X058)/*SDH1 Clock/Reset Control Register*/
#define REG_PMU_PMU_USB_CLK_RES_CTRL                      ASR_ADDR(REGS_PMU_BASE, 0X05C)/*USB Clock/Reset Control Register*/
#define REG_PMU_PMU_NF_CLK_RES_CTRL                       ASR_ADDR(REGS_PMU_BASE, 0X060)/*NAND Flash Clock/Reset Control Register*/
#define REG_PMU_PMU_DMA_CLK_RES_CTRL                      ASR_ADDR(REGS_PMU_BASE, 0X064)/*DMA Clock/Reset Control Register*/
#define REG_PMU_PMU_AES_CLK_RES_CTRL                      ASR_ADDR(REGS_PMU_BASE, 0X068)/*AES Clock/Reset Control Register*/
#define REG_PMU_PMU_MCB_CLK_RES_CTRL                      ASR_ADDR(REGS_PMU_BASE, 0X06C)/*MCB Clock/Reset Control Register*/
#define REG_PMU_PMU_CP_IMR                                ASR_ADDR(REGS_PMU_BASE, 0X070)/*PMU CP Interrupt Mask Register*/
#define REG_PMU_PMU_CP_IRWC                               ASR_ADDR(REGS_PMU_BASE, 0X074)/*PMU CP Interrupt READ/WRITE Clear Register*/
#define REG_PMU_PMU_CP_ISR                                ASR_ADDR(REGS_PMU_BASE, 0X078)/*PMU CP Interrupt Status Register*/
#define REG_PMU_PMU_SD_ROT_WAKE_CLR                       ASR_ADDR(REGS_PMU_BASE, 0X07C)/*SDIO/Rotary Wake Clear Register*/
#define REG_PMU_PMU_PWR_STBL_TIMER                        ASR_ADDR(REGS_PMU_BASE, 0X084)/*Power Stable Timer Register*/
#define REG_PMU_PMU_DEBUG_REG                             ASR_ADDR(REGS_PMU_BASE, 0X088)
#define REG_PMU_PMU_SRAM_PWR_DWN                          ASR_ADDR(REGS_PMU_BASE, 0X08C)/*Core SRAM Power Down Register*/
#define REG_PMU_PMU_CORE_STATUS                           ASR_ADDR(REGS_PMU_BASE, 0X090)/*Core Status Register*/
#define REG_PMU_PMU_RES_FRM_SLP_CLR                       ASR_ADDR(REGS_PMU_BASE, 0X094)/*Resume from Sleep Clear Register*/
#define REG_PMU_PMU_AP_IMR                                ASR_ADDR(REGS_PMU_BASE, 0X098)/*PMU AP Interrupt Mask Register*/
#define REG_PMU_PMU_AP_IRWC                               ASR_ADDR(REGS_PMU_BASE, 0X09C)/*PMU AP Interrupt READ/WRITE Clear Register*/
#define REG_PMU_PMU_AP_ISR                                ASR_ADDR(REGS_PMU_BASE, 0X0A0)/*PMU AP Interrupt Status Register*/
#define REG_PMU_PMU_VPU_CLK_RES_CTRL                      ASR_ADDR(REGS_PMU_BASE, 0X0A4)/*VPU Clock/Reset Control Register*/
#define REG_PMU_PMU_DTC_CLK_RES_CTRL                      ASR_ADDR(REGS_PMU_BASE, 0X0AC)/*DTC Clock/Reset Control Register*/
#define REG_PMU_PMU_MC_HW_SLP_TYPE                        ASR_ADDR(REGS_PMU_BASE, 0X0B0)/*Memory Controller Hardware Sleep Type Register*/
#define REG_PMU_PMU_MC_SLP_REQ_AP                         ASR_ADDR(REGS_PMU_BASE, 0X0B4)/*Memory Controller AP Sleep Request Register*/
#define REG_PMU_PMU_MC_SLP_REQ_CP                         ASR_ADDR(REGS_PMU_BASE, 0X0B8)/*Memory Controller <var Processor: Comm> Sleep Request Register*/
#define REG_PMU_PMU_MC_SLP_REQ_MSA                        ASR_ADDR(REGS_PMU_BASE, 0X0BC)/*Memory Controller MSA Sleep Request Register*/
#define REG_PMU_PMU_MC_SW_SLP_TYPE                        ASR_ADDR(REGS_PMU_BASE, 0X0C0)/*Memory Controller Software Sleep Type Register*/
#define REG_PMU_PMU_PLL_SEL_STATUS                        ASR_ADDR(REGS_PMU_BASE, 0X0C4)/*PLL Clock Select Status Register*/
#define REG_PMU_PMU_GPU_CLK_RES_CTRL                      ASR_ADDR(REGS_PMU_BASE, 0X0CC)/*GPU Clock/Reset Control Register*/
#define REG_PMU_PMUA_SMC_CLK_RES_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X0D4)/*SMC Clock/Reset Control Register*/
#define REG_PMU_PMUA_PWR_CTRL_REG                         ASR_ADDR(REGS_PMU_BASE, 0X0D8)/*Power Control Register*/
#define REG_PMU_PMUA_PWR_BLK_TMR_REG                      ASR_ADDR(REGS_PMU_BASE, 0X0DC)/*Block Power Timer Register*/
#define REG_PMU_PMUA_SDH2_CLK_RES_CTRL                    ASR_ADDR(REGS_PMU_BASE, 0X0E0)/*SDH2 Clock/Reset Control Register*/
#define REG_PMU_PMU_C0_CAPMP_IDLE_CFGx0                   ASR_ADDR(REGS_PMU_BASE, 0x120)/*Cluster0 <var Processor: Application MP> Idle Configuration Register for Core x*/
#define REG_PMU_PMU_C0_CAPMP_IDLE_CFGx1                   ASR_ADDR(REGS_PMU_BASE, 0xE4)/*Cluster0 <var Processor: Application MP> Idle Configuration Register for Core x*/
#define REG_PMU_PMU_C0_CAPMP_IDLE_CFGx2                   ASR_ADDR(REGS_PMU_BASE, 0x150)/*Cluster0 <var Processor: Application MP> Idle Configuration Register for Core x*/
#define REG_PMU_PMU_C0_CAPMP_IDLE_CFGx3                   ASR_ADDR(REGS_PMU_BASE, 0x154)/*Cluster0 <var Processor: Application MP> Idle Configuration Register for Core x*/
#define REG_PMU_PMUA_MC_CTRL                              ASR_ADDR(REGS_PMU_BASE, 0X0E8)/*Memory Controller AHB Register*/
#define REG_PMU_PMUA_PWR_STATUS_REG                       ASR_ADDR(REGS_PMU_BASE, 0X0F0)/*Power Status Register*/
#define REG_PMU_PMU_SP_IDLE_CFG                           ASR_ADDR(REGS_PMU_BASE, 0X0F8)/*SP Idle Configuration Register*/
#define REG_PMU_PMU_GNSS_PWR_CTRL                         ASR_ADDR(REGS_PMU_BASE, 0X0FC)/*GNSS Power Control Register*/
#define REG_PMU_PMU_CC2_AP                                ASR_ADDR(REGS_PMU_BASE, 0X100)/*AP Clock Control Register2*/
#define REG_PMU_PMUA_EM_CLK_RES_CTRL                      ASR_ADDR(REGS_PMU_BASE, 0X0104)/*EMMC5.0 Clock/Reset Control Register*/
#define REG_PMU_TRACE_CONFIG                              ASR_ADDR(REGS_PMU_BASE, 0X108)/*Trace Clock Control Register*/
#define REG_PMU_PMUA_USB_PHY_CTRL0                        ASR_ADDR(REGS_PMU_BASE, 0X110)/*USB PHY Control Register0*/
#define REG_PMU_PMUA_USB_PHY_CTRL1                        ASR_ADDR(REGS_PMU_BASE, 0X114)/*USB PHY Control Register1*/
#define REG_PMU_PMUA_USB_PHY_READ                         ASR_ADDR(REGS_PMU_BASE, 0X118)/*USB PHY read Register*/
#define REG_PMU_PMUA_USB_PHY_TEST                         ASR_ADDR(REGS_PMU_BASE, 0X11C)/*USB PHY Test Register*/
#define REG_PMU_PMU_CAP_COREx_IDLE_CFG0                   ASR_ADDR(REGS_PMU_BASE, 0x124)/*<var Processor: Application> Core x  Idle Configuration Register*/
#define REG_PMU_PMU_CAP_COREx_IDLE_CFG1                   ASR_ADDR(REGS_PMU_BASE, 0x128)/*<var Processor: Application> Core x  Idle Configuration Register*/
#define REG_PMU_PMU_CAP_COREx_IDLE_CFG2                   ASR_ADDR(REGS_PMU_BASE, 0x160)/*<var Processor: Application> Core x  Idle Configuration Register*/
#define REG_PMU_PMU_CAP_COREx_IDLE_CFG3                   ASR_ADDR(REGS_PMU_BASE, 0x164)/*<var Processor: Application> Core x  Idle Configuration Register*/
#define REG_PMU_PMU_CAP_COREx_IDLE_CFG4                   ASR_ADDR(REGS_PMU_BASE, 0x304)/*<var Processor: Application> Core x  Idle Configuration Register*/
#define REG_PMU_PMU_CAP_COREx_IDLE_CFG5                   ASR_ADDR(REGS_PMU_BASE, 0x308)/*<var Processor: Application> Core x  Idle Configuration Register*/
#define REG_PMU_PMU_CAP_COREx_IDLE_CFG6                   ASR_ADDR(REGS_PMU_BASE, 0x30C)/*<var Processor: Application> Core x  Idle Configuration Register*/
#define REG_PMU_PMU_CAP_COREx_IDLE_CFG7                   ASR_ADDR(REGS_PMU_BASE, 0x310)/*<var Processor: Application> Core x  Idle Configuration Register*/
#define REG_PMU_PMU_CAP_COREx_IDLE_CFG8                   ASR_ADDR(REGS_PMU_BASE, 0x340)/*<var Processor: Application> Core x  Idle Configuration Register*/
#define REG_PMU_PMU_CAP_COREx_IDLE_CFG9                   ASR_ADDR(REGS_PMU_BASE, 0x344)/*<var Processor: Application> Core x  Idle Configuration Register*/
#define REG_PMU_PMU_CAP_COREx_WAKEUP0                     ASR_ADDR(REGS_PMU_BASE, 0x12C)/*<var Processor: Application> Core x Wakeup Register*/
#define REG_PMU_PMU_CAP_COREx_WAKEUP1                     ASR_ADDR(REGS_PMU_BASE, 0x130)/*<var Processor: Application> Core x Wakeup Register*/
#define REG_PMU_PMU_CAP_COREx_WAKEUP2                     ASR_ADDR(REGS_PMU_BASE, 0x134)/*<var Processor: Application> Core x Wakeup Register*/
#define REG_PMU_PMU_CAP_COREx_WAKEUP3                     ASR_ADDR(REGS_PMU_BASE, 0x138)/*<var Processor: Application> Core x Wakeup Register*/
#define REG_PMU_PMU_CAP_COREx_WAKEUP4                     ASR_ADDR(REGS_PMU_BASE, 0x324)/*<var Processor: Application> Core x Wakeup Register*/
#define REG_PMU_PMU_CAP_COREx_WAKEUP5                     ASR_ADDR(REGS_PMU_BASE, 0x328)/*<var Processor: Application> Core x Wakeup Register*/
#define REG_PMU_PMU_CAP_COREx_WAKEUP6                     ASR_ADDR(REGS_PMU_BASE, 0x32C)/*<var Processor: Application> Core x Wakeup Register*/
#define REG_PMU_PMU_CAP_COREx_WAKEUP7                     ASR_ADDR(REGS_PMU_BASE, 0x330)/*<var Processor: Application> Core x Wakeup Register*/
#define REG_PMU_PMU_CAP_COREx_WAKEUP8                     ASR_ADDR(REGS_PMU_BASE, 0x360)/*<var Processor: Application> Core x Wakeup Register*/
#define REG_PMU_PMU_CAP_COREx_WAKEUP9                     ASR_ADDR(REGS_PMU_BASE, 0x364)/*<var Processor: Application> Core x Wakeup Register*/
#define REG_PMU_PMU_DVC_DFC_DEBUG                         ASR_ADDR(REGS_PMU_BASE, 0X140)/*PMU DVC and DFC Debug Register*/
#define REG_PMU_PMU_AUDIO_CLK_RES_CTRL                    ASR_ADDR(REGS_PMU_BASE, 0X14C)/*Audio Clock Reset Enable Register*/
#define REG_PMU_DFC_AP                                    ASR_ADDR(REGS_PMU_BASE, 0X180)/*<var Processor: Application MP> DCLK Dynamic Freq Change Control Register*/
#define REG_PMU_DFC_STATUS                                ASR_ADDR(REGS_PMU_BASE, 0X188)/*DCLK Hardware Freq Change Status Register*/
#define REG_PMU_DFC_LEVEL0~DFC_LEVEL70                    ASR_ADDR(REGS_PMU_BASE, 0x190~0X1AC)/*DCLK Freq Level 0 Control Register*/
#define REG_PMU_DFC_LEVEL0~DFC_LEVEL71                    ASR_ADDR(REGS_PMU_BASE, 0x1AC)/*DCLK Freq Level 0 Control Register*/
#define REG_PMU_PMU_DEBUG2_REG                            ASR_ADDR(REGS_PMU_BASE, 0X1B0)/*PMU Debug2 Register*/
#define REG_PMU_GNSS_WAKEUP_CTRL                          ASR_ADDR(REGS_PMU_BASE, 0X1B8)/*GNSS Wakeup Control Register*/
#define REG_PMU_PMU_CCIC2_CLK_GATE_CTRL                   ASR_ADDR(REGS_PMU_BASE, 0X1BC)/*CMOS Camera Interface Controller 2 Dynamic Clock Gate Control Register*/
#define REG_PMU_PMU_GT_WAKEUP_C0_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X1C0)/*Generic Timer Wakeup Core0 Control Register*/
#define REG_PMU_PMU_GT_WAKEUP_C1_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X1C4)/*Generic Timer Wakeup Core1 Control Register*/
#define REG_PMU_PMU_GT_WAKEUP_C2_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X1C8)/*Generic Timer Wakeup Core2 Control Register*/
#define REG_PMU_PMU_GT_WAKEUP_C3_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X1CC)/*Generic Timer Wakeup Core3 Control Register*/
#define REG_PMU_PMU_GT_WAKEUP_C0_ML                       ASR_ADDR(REGS_PMU_BASE, 0X1D0)/*Generic Timer Wakeup Core0 Match Low Register*/
#define REG_PMU_PMU_GT_WAKEUP_C0_MH                       ASR_ADDR(REGS_PMU_BASE, 0X1D4)/*Generic Timer Wakeup Core0 Match High Register*/
#define REG_PMU_PMU_GT_WAKEUP_C1_ML                       ASR_ADDR(REGS_PMU_BASE, 0X1D8)/*Generic Timer Wakeup Core1 Match Low Register*/
#define REG_PMU_PMU_GT_WAKEUP_C1_MH                       ASR_ADDR(REGS_PMU_BASE, 0X1DC)/*Generic Timer Wakeup Core1 Match High Register*/
#define REG_PMU_PMU_GT_WAKEUP_C2_ML                       ASR_ADDR(REGS_PMU_BASE, 0X1E0)/*Generic Timer Wakeup Core2 Match Low Register*/
#define REG_PMU_PMU_GT_WAKEUP_C2_MH                       ASR_ADDR(REGS_PMU_BASE, 0X1E4)/*Generic Timer Wakeup Core2 Match High Register*/
#define REG_PMU_PMU_GT_WAKEUP_C3_ML                       ASR_ADDR(REGS_PMU_BASE, 0X1E8)/*Generic Timer Wakeup Core3 Match Low Register*/
#define REG_PMU_PMU_GT_WAKEUP_C3_MH                       ASR_ADDR(REGS_PMU_BASE, 0X1EC)/*Generic Timer Wakeup Core3 Match High Register*/
#define REG_PMU_FC_LOCK_STATUS                            ASR_ADDR(REGS_PMU_BASE, 0X334)/*Frequency change Lock Status Register*/
#define REG_PMU_PMU_GT_WAKEUP_C4_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X208)/*Generic Timer Wakeup Core4 Control Register*/
#define REG_PMU_PMU_GT_WAKEUP_C5_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X20C)/*Generic Timer Wakeup Core5 Control Register*/
#define REG_PMU_PMU_GT_WAKEUP_C6_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X210)/*Generic Timer Wakeup Core6 Control Register*/
#define REG_PMU_PMU_GT_WAKEUP_C7_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X214)/*Generic Timer Wakeup Core7 Control Register*/
#define REG_PMU_PMU_GT_WAKEUP_C4_ML                       ASR_ADDR(REGS_PMU_BASE, 0X218)/*Generic Timer Wakeup Core4 Match Low Register*/
#define REG_PMU_PMU_GT_WAKEUP_C4_MH                       ASR_ADDR(REGS_PMU_BASE, 0X21C)/*Generic Timer Wakeup Core4 Match High Register*/
#define REG_PMU_PMU_GT_WAKEUP_C5_ML                       ASR_ADDR(REGS_PMU_BASE, 0X220)/*Generic Timer Wakeup Core5 Match Low Register*/
#define REG_PMU_PMU_GT_WAKEUP_C5_MH                       ASR_ADDR(REGS_PMU_BASE, 0X224)/*Generic Timer Wakeup Core5 Match High Register*/
#define REG_PMU_PMU_GT_WAKEUP_C6_ML                       ASR_ADDR(REGS_PMU_BASE, 0X228)/*Generic Timer Wakeup Core6 Match Low Register*/
#define REG_PMU_PMU_GT_WAKEUP_C6_MH                       ASR_ADDR(REGS_PMU_BASE, 0X22C)/*Generic Timer Wakeup Core6 Match High Register*/
#define REG_PMU_PMU_GT_WAKEUP_C7_ML                       ASR_ADDR(REGS_PMU_BASE, 0X230)/*Generic Timer Wakeup Core7 Match Low Register*/
#define REG_PMU_PMU_GT_WAKEUP_C7_MH                       ASR_ADDR(REGS_PMU_BASE, 0X234)/*Generic Timer Wakeup Core7 Match High Register*/
#define REG_PMU_PMU_GT_WAKEUP_C8_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X238)/*Generic Timer Wakeup Core8 Control Register*/
#define REG_PMU_PMU_GT_WAKEUP_C9_CTRL                     ASR_ADDR(REGS_PMU_BASE, 0X23C)/*Generic Timer Wakeup Core9 Control Register*/
#define REG_PMU_PMU_GT_WAKEUP_C8_ML                       ASR_ADDR(REGS_PMU_BASE, 0X248)/*Generic Timer Wakeup Core8 Match Low Register*/
#define REG_PMU_PMU_GT_WAKEUP_C8_MH                       ASR_ADDR(REGS_PMU_BASE, 0X24C)/*Generic Timer Wakeup Core8 Match High Register*/
#define REG_PMU_PMU_GT_WAKEUP_C9_ML                       ASR_ADDR(REGS_PMU_BASE, 0X250)/*Generic Timer Wakeup Core9 Match Low Register*/
#define REG_PMU_PMU_GT_WAKEUP_C9_MH                       ASR_ADDR(REGS_PMU_BASE, 0X254)/*Generic Timer Wakeup Core9 Match High Register*/
#define REG_PMU_PMU_C1_CAPMP_IDLE_CFGx0                   ASR_ADDR(REGS_PMU_BASE, 0x314)/*Cluster1 <var Processor: Application MP> Idle Configuration Register for Core x*/
#define REG_PMU_PMU_C1_CAPMP_IDLE_CFGx1                   ASR_ADDR(REGS_PMU_BASE, 0x318)/*Cluster1 <var Processor: Application MP> Idle Configuration Register for Core x*/
#define REG_PMU_PMU_C1_CAPMP_IDLE_CFGx2                   ASR_ADDR(REGS_PMU_BASE, 0x31C)/*Cluster1 <var Processor: Application MP> Idle Configuration Register for Core x*/
#define REG_PMU_PMU_C1_CAPMP_IDLE_CFGx3                   ASR_ADDR(REGS_PMU_BASE, 0x320)/*Cluster1 <var Processor: Application MP> Idle Configuration Register for Core x*/
#define REG_PMU_PMU_CCI_CLK_CTRL                          ASR_ADDR(REGS_PMU_BASE, 0X300)/*CCI550 Clock Control Register*/
#define REG_PMU_PMU_CC3_AP                                ASR_ADDR(REGS_PMU_BASE, 0X338)/*AP Clock Control Register*/
#define REG_PMU_PMU_DM_CC2_AP                             ASR_ADDR(REGS_PMU_BASE, 0X33C)/*Dummy AP Clock Control2 Register*/
#define REG_PMU_PMU_C2_CAPMP_IDLE_CFGx0                   ASR_ADDR(REGS_PMU_BASE, 0x350)/*Cluster2 <var Processor: Application MP> Idle Configuration Register for Core x*/
#define REG_PMU_PMU_C2_CAPMP_IDLE_CFGx1                   ASR_ADDR(REGS_PMU_BASE, 0x354)/*Cluster2 <var Processor: Application MP> Idle Configuration Register for Core x*/
#define REG_PMU_PMU_CORE2_STATUS2                         ASR_ADDR(REGS_PMU_BASE, 0X370)/*Core Status2 Register*/
#define REG_PMU_PMUA_PWR_CTRL_VPU                         ASR_ADDR(REGS_PMU_BASE, 0X374)/*Power Control Register*/
#define REG_PMU_PMUA_PWR_CTRL_GPU                         ASR_ADDR(REGS_PMU_BASE, 0X378)/*Power Control Register*/
#define REG_PMU_PMUA_PWR_CTRL_ISP                         ASR_ADDR(REGS_PMU_BASE, 0X37C)/*Power Control Register*/
#define REG_PMU_PMUA_PWR_CTRL_LCD                         ASR_ADDR(REGS_PMU_BASE, 0X380)/*Power Control Register*/
#define REG_PMU_PMUA_ACLK_CTRL                            ASR_ADDR(REGS_PMU_BASE, 0X388)/*AP ACLK Control Register*/
#define REG_PMU_PMUA_CPU_C0_CLK_CTRL                      ASR_ADDR(REGS_PMU_BASE, 0X38C)/*AP CPU CLUSTER0 CLK Control Register*/
#define REG_PMU_PMUA_CPU_C1_CLK_CTRL                      ASR_ADDR(REGS_PMU_BASE, 0X390)/*AP CPU CLUSTER1 CLK Control Register*/
#define REG_PMU_DDR_CKPHY_PLL1_CTRL1                      ASR_ADDR(REGS_PMU_BASE, 0X398)/*DDR CKPHY Control Register*/
#define REG_PMU_DDR_CKPHY_PLL1_CTRL2                      ASR_ADDR(REGS_PMU_BASE, 0X39C)/*DDR CKPHY Control Register*/
#define REG_PMU_DDR_CKPHY_PLL2_CTRL1                      ASR_ADDR(REGS_PMU_BASE, 0X3A0)/*DDR CKPHY Control Register*/
#define REG_PMU_DDR_CKPHY_PLL2_CTRL2                      ASR_ADDR(REGS_PMU_BASE, 0X3A4)/*DDR CKPHY Control Register*/
#define REG_PMU_CKPHY_MISC_CTRL                           ASR_ADDR(REGS_PMU_BASE, 0X3A8)/*DDR CKPHY Control Register*/
#define REG_PMU_CKPHY_FC_CTRL                             ASR_ADDR(REGS_PMU_BASE, 0X3AC)/*DDR CKPHY Control Register*/



/* bits definitions for register REG_PMU_PMU_CC_AP */
#define BIT_DDR_FREQ_CHG_REQ                              ( BIT(22) )
#define BIT_AP_ALLOW_SPD_CHG                              ( BIT(18) )

/* bits definitions for register REG_PMU_PMU_DM_CC_AP */
#define BIT_PM_AP_C2_FC_DONE27                            ( BIT(31) )
#define BIT_PM_AP_C1_FC_DONE28                            ( BIT(30) )
#define BIT_PM_ACLK_FC_DONE29                             ( BIT(29) )
#define BIT_PM_DCLK_FC_DONE30                             ( BIT(28) )
#define BIT_PM_AP_C0_FC_DONE31                            ( BIT(27) )
#define BIT_PM_CP_FC_DONE32                               ( BIT(26) )
#define BIT_AP_RD_STATUS33                                ( BIT(25) )
#define BIT_CP_RD_STATUS34                                ( BIT(24) )
#define BIT_ASYNC5                                        ( BIT(23) )
#define BIT_ASYNC4                                        ( BIT(22) )
#define BIT_ASYNC3_1                                      ( BIT(21) )
#define BIT_ASYNC3                                        ( BIT(20) )
#define BIT_ASYNC2                                        ( BIT(19) )
#define BIT_ASYNC1                                        ( BIT(18) )
#define BITS_BUS_CLK_DIV(_X_)                             ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)) )
#define BITS_DDR_CLK_DIV(_X_)                             ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BITS_C1_ACLK_DIV43(_X_)                           ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BITS_C1_CLK_DIV(_X_)                              ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)) )
#define BITS_C0_ACLK_DIV45(_X_)                           ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)) )
#define BITS_C0_CLK_DIV(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_PMU_PMU_FC_TIMER */
#define BITS_TIMER(_X_)                                   ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_TIMER_SEL(_X_)                               ( (_X_) << 1 & (BIT(1)|BIT(2)) )
#define BIT_TIMER_EN                                      ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_CP_IDLE_CFG */
#define BITS_SEA_SRAM_WAIT(_X_)                           ( (_X_) << 27 & (BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_SEA_SRAM_VMCVSSM(_X_)                        ( (_X_) << 23 & (BIT(23)|BIT(24)|BIT(25)|BIT(26)) )
#define BIT_SEA_DIS_MC_SW_REQ                             ( BIT(21) )
#define BIT_PM_SEA_MC_WAKE_EN66                           ( BIT(20) )
#define BIT_CP_L2_PWR_SW                                  ( BIT(19) )
#define BIT_CP_L1_PWR_SW                                  ( BIT(18) )
#define BITS_CP_CORE_PWR_SW(_X_)                          ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BIT_CP_DIS_L2_SLP2                                ( BIT(15) )
#define BIT_CP_DIS_L2_SLP1                                ( BIT(14) )
#define BIT_CP_DIS_SLP2                                   ( BIT(13) )
#define BIT_CP_DIS_SLP1                                   ( BIT(12) )
#define BIT_SEA_MASK_JTAG_IDLE                            ( BIT(11) )
#define BIT_SEA_L2_CLK_DIS                                ( BIT(10) )
#define BIT_SEA_L2_RESETN                                 ( BIT(9) )
#define BIT_CP_L2_ISOB                                    ( BIT(8) )
#define BIT_CP_L2_PWR_OFF                                 ( BIT(7) )
#define BIT_CP_SRAM_PWRDWN                                ( BIT(6) )
#define BIT_CP_PWRDWN                                     ( BIT(5) )
#define BIT_CP_DTCM_PDWN_DIS                              ( BIT(2) )
#define BIT_MASK_WFI_CHECK84                              ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_SQU_CLK_GATE_CTRL */
#define BIT_MP3_MODE_EN                                   ( BIT(30) )
#define BIT_SQU_REFCLK_GATE_DIS                           ( BIT(29) )
#define BIT_SQU_REFCLK_SW_EN                              ( BIT(28) )
#define BIT_SQU_BANK4CLK_GATE_DIS                         ( BIT(21) )
#define BIT_SQU_BANK4CLK_SW_EN                            ( BIT(20) )
#define BIT_SQU_BANK3CLK_GATE_DIS                         ( BIT(19) )
#define BIT_SQU_BANK3CLK_SW_EN                            ( BIT(18) )
#define BIT_SQU_BANK2CLK_GATE_DIS                         ( BIT(17) )
#define BIT_SQU_BANK2CLK_SW_EN                            ( BIT(16) )
#define BIT_SQU_BANK1CLK_GATE_DIS                         ( BIT(15) )
#define BIT_SQU_BANK1CLK_SW_EN                            ( BIT(14) )
#define BIT_SQU_BANK0CLK_GATE_DIS                         ( BIT(13) )
#define BIT_SQU_BANK0CLK_SW_EN                            ( BIT(12) )
#define BIT_SQU_S8CLK_GATE_DIS                            ( BIT(11) )
#define BIT_SQU_S8CLK_SW_EN                               ( BIT(10) )
#define BIT_SQU_S4CLK_GATE_DIS                            ( BIT(9) )
#define BIT_SQU_S4CLK_SW_EN                               ( BIT(8) )
#define BIT_SQU_S1CLK_GATE_DIS                            ( BIT(7) )
#define BIT_SQU_S1CLK_SW_EN                               ( BIT(6) )
#define BIT_SQU_FMBISTCLK_GATE_DIS                        ( BIT(5) )
#define BIT_SQU_FMBISTCLK_SW_EN                           ( BIT(4) )
#define BIT_SQU_ROMCLK_GATE_DIS                           ( BIT(3) )
#define BIT_SQU_ROMCLK_SW_EN                              ( BIT(2) )
#define BIT_SQU_CLK_GATE_DIS                              ( BIT(1) )
#define BIT_SQU_CLK_SW_EN                                 ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_JPG_CLK_RES_CTRL */

/* bits definitions for register REG_PMU_PMU_CSI_CCIC2_CLK_RES_CTRL */
#define BIT_CCIC3_PHY_CLK_SEL                             ( BIT(31) )
#define BIT_CCIC3_PHY_CLK_EN                              ( BIT(30) )
#define BIT_CCIC3_PHY_CLK_RST                             ( BIT(29) )
#define BIT_CAM_MCLK0_EN                                  ( BIT(28) )
#define BIT_CAM_MCLK_EN                                   ( BIT(27) )
#define BITS_ISIM_VCLK_OUT_DIV(_X_)                       ( (_X_) << 23 & (BIT(23)|BIT(24)|BIT(25)|BIT(26)) )
#define BITS_CSI_FNC_CLK_DIV(_X_)                         ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BITS_CSI_CLK_SEL(_X_)                             ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_CSI_CLK_FC_REQ                                ( BIT(15) )
#define BITS_CAM_MCLK_SEL(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BIT_CCIC2_PHYCLK_SEL                              ( BIT(7) )
#define BIT_CAM_MCLK1_EN                                  ( BIT(6) )
#define BIT_CCIC2_PHYCLK_EN                               ( BIT(5) )
#define BIT_CSI_CLK_EN                                    ( BIT(4) )
#define BIT_CCIC2_PHYCLK_RST                              ( BIT(2) )
#define BIT_CSI_CLK_RST                                   ( BIT(1) )

/* bits definitions for register REG_PMU_PMU_CCIC1_CLK_GATE_CTRL */
#define BITS_CCIC1_GATE_CSI_CLK_STATIC(_X_)               ( (_X_) << 30 & (BIT(30)|BIT(31)) )
#define BITS_CCIC1_GATE_CLK4X_STATIC(_X_)                 ( (_X_) << 28 & (BIT(28)|BIT(29)) )
#define BITS_CCIC1_GATE_CLK1X_STATIC(_X_)                 ( (_X_) << 26 & (BIT(26)|BIT(27)) )
#define BITS_CCIC1_GATE_HCLK_STATIC(_X_)                  ( (_X_) << 24 & (BIT(24)|BIT(25)) )
#define BITS_CCIC1_GATE_ACLK_STATIC172(_X_)               ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BITS_CCIC1_GATE_ISP_PIP1_CLK1X_STATIC(_X_)        ( (_X_) << 20 & (BIT(20)|BIT(21)) )
#define BITS_CCIC1_GATE_ACLK_STATIC174(_X_)               ( (_X_) << 18 & (BIT(18)|BIT(19)) )
#define BITS_CCIC1_GATE_AXI_BRIDGE_CLK_STATIC(_X_)        ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_CCIC1_GATE_LANE3_CLK_DYNAMIC(_X_)            ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_CCIC1_GATE_LANE2_CLK_DYNAMIC(_X_)            ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BITS_CCIC1_GATE_LANE1_CLK_DYNAMIC(_X_)            ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BITS_CCIC1_GATE_LANE0_CLK_DYNAMIC(_X_)            ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_CCIC1_GATE_CSI_CLK_DYNAMIC(_X_)              ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_CCIC1_GATE_AHB_CLK_DYNAMIC(_X_)              ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_CCIC1_GATE_PIP_CLK_DYNAMIC(_X_)              ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_CCIC1_GATE__AXI_CLK_DYNAMIC(_X_)             ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_PMU_PMU_FBRC0_CLK_GATE_CTRL */
#define BITS_PM_190(_X_)                                  ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_FBCR0_DTCCLK_SW_EN                            ( BIT(27) )
#define BIT_FBCR0_DTCCLK_GATE_DIS                         ( BIT(26) )
#define BIT_FBCR0_S6CLK_SW_EN                             ( BIT(25) )
#define BIT_FBCR0_S6CLK_GATE_DIS                          ( BIT(24) )
#define BIT_FBCR0_S5CLK_SW_EN                             ( BIT(23) )
#define BIT_FBCR0_S5CLK_GATE_DIS                          ( BIT(22) )
#define BIT_FBCR0_S4CLK_SW_EN                             ( BIT(21) )
#define BIT_FBCR0_S4CLK_GATE_DIS                          ( BIT(20) )
#define BIT_FBCR0_S3CLK_SW_EN                             ( BIT(19) )
#define BIT_FBCR0_S3CLK_GATE_DIS                          ( BIT(18) )
#define BIT_FBCR0_S2CLK_SW_EN                             ( BIT(17) )
#define BIT_FBCR0_S2CLK_GATE_DIS                          ( BIT(16) )
#define BIT_FBCR0_S1CLK_SW_EN                             ( BIT(15) )
#define BIT_FBCR0_S1CLK_GATE_DIS                          ( BIT(14) )
#define BIT_FBCR0_S0CLK_SW_EN                             ( BIT(13) )
#define BIT_FBCR0_S0CLK_GATE_DIS                          ( BIT(12) )
#define BIT_FBCR0_M4CLK_SW_EN                             ( BIT(11) )
#define BIT_FBCR0_M4CLK_GATE_DIS                          ( BIT(10) )
#define BIT_FBCR0_M3CLK_SW_EN                             ( BIT(9) )
#define BIT_FBCR0_M3CLK_GATE_DIS                          ( BIT(8) )
#define BIT_FBCR0_M2CLK_SW_EN                             ( BIT(7) )
#define BIT_FBCR0_M2CLK_GATE_DIS                          ( BIT(6) )
#define BIT_FBCR0_M1CLK_SW_EN                             ( BIT(5) )
#define BIT_FBCR0_M1CLK_GATE_DIS                          ( BIT(4) )
#define BIT_FBCR0_M0CLK_SW_EN                             ( BIT(3) )
#define BIT_FBCR0_M0CLK_GATE_DIS                          ( BIT(2) )
#define BIT_FBCR0_CLK_SW_EN                               ( BIT(1) )
#define BIT_FBCR0_CLK_GATE_DIS                            ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_FBRC1_CLK_GATE_CTRL */
#define BITS_PM_225(_X_)                                  ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_FBCR1_S12CLK_SW_EN                            ( BIT(19) )
#define BIT_FBCR1_S12CLK_GATE_DIS                         ( BIT(18) )
#define BIT_FBCR1_S11CLK_SW_EN                            ( BIT(17) )
#define BIT_FBCR1_S11CLK_GATE_DIS                         ( BIT(16) )
#define BIT_FBCR1_S10CLK_SW_EN                            ( BIT(15) )
#define BIT_FBCR1_S10CLK_GATE_DIS                         ( BIT(14) )
#define BIT_FBCR1_M15CLK_SW_EN                            ( BIT(13) )
#define BIT_FBCR1_M15CLK_GATE_DIS                         ( BIT(12) )
#define BIT_FBCR1_M14CLK_SW_EN                            ( BIT(11) )
#define BIT_FBCR1_M14CLK_GATE_DIS                         ( BIT(10) )
#define BIT_FBCR1_M13CLK_SW_EN                            ( BIT(9) )
#define BIT_FBCR1_M13CLK_GATE_DIS                         ( BIT(8) )
#define BIT_FBCR1_M12CLK_SW_EN                            ( BIT(7) )
#define BIT_FBCR1_M12CLK_GATE_DIS                         ( BIT(6) )
#define BIT_FBCR1_M11CLK_SW_EN                            ( BIT(5) )
#define BIT_FBCR1_M11CLK_GATE_DIS                         ( BIT(4) )
#define BIT_FBCR1_M10CLK_SW_EN                            ( BIT(3) )
#define BIT_FBCR1_M10CLK_GATE_DIS                         ( BIT(2) )
#define BIT_FBCR1_CLK_SW_EN                               ( BIT(1) )
#define BIT_FBCR1_CLK_GATE_DIS                            ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_ISP_CLK_RES_CTRL */
#define BIT_ISP_PDWN                                      ( BIT(31) )
#define BIT_ISP_REPAIR_MEM_CTRL_TRIG                      ( BIT(30) )
#define BIT_ISP_REPAIR_MEM_CTRL_DONE_BYPASS               ( BIT(29) )
#define BIT_ISP_MCU_CLK_EN                                ( BIT(28) )
#define BIT_ISP_MCU_CLK_RSTN                              ( BIT(27) )
#define BIT_ISP_MCU_CLK_SEL                               ( BIT(26) )
#define BITS_ISP_MCU_CLK_DIV(_X_)                         ( (_X_) << 24 & (BIT(24)|BIT(25)) )
#define BIT_ISP_CI_BUS_CLK_FC_REQ                         ( BIT(23) )
#define BITS_ISP_CI_BUS_CLK_SEL(_X_)                      ( (_X_) << 21 & (BIT(21)|BIT(22)) )
#define BITS_ISP_CI_BUS_CLK_DIV(_X_)                      ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)) )
#define BIT_ISP_CI_BUS_CLK_EN                             ( BIT(17) )
#define BIT_ISP_CI_BUS_CLK_RST                            ( BIT(16) )
#define BIT_ISP_HW_MODE                                   ( BIT(15) )
#define BIT_ISP_SLEEP2                                    ( BIT(14) )
#define BIT_ISP_SLEEP1                                    ( BIT(13) )
#define BIT_ISP_ISOB                                      ( BIT(12) )
#define BITS_ISP_CLK_SEL(_X_)                             ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BIT_ISP_CLK_FC_REQ                                ( BIT(7) )
#define BITS_ISP_CLK_DIV(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_ISP_AXI_RESETN                                ( BIT(3) )
#define BIT_ISP_CLK_EN                                    ( BIT(1) )
#define BIT_ISP_CLK_RSTN                                  ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_PMU_CLK_GATE_CTRL */
#define BIT_1248M_D1P_EN                                  ( BIT(31) )
#define BIT_832M_D1P_EN                                   ( BIT(30) )
#define BIT_624M_D1P_EN                                   ( BIT(29) )
#define BIT_499M_D1P_EN                                   ( BIT(28) )
#define BIT_416M_D1P_EN                                   ( BIT(27) )
#define BIT_312M_D1P_EN                                   ( BIT(26) )
#define BIT_ULPI_CLK_SW_EN                                ( BIT(25) )
#define BIT_AP_32K_CLK_SW_EN                              ( BIT(24) )
#define BIT_249M_D1P_EN                                   ( BIT(22) )
#define BIT_SYS_1M_CLK_SW_EN                              ( BIT(21) )
#define BIT_SYS_62P4M_CLK_SW_EN                           ( BIT(20) )
#define BIT_62P4M_CLOCK_GEN_INPUT_312M_CLK_SW_EN          ( BIT(19) )
#define BIT_AUDIO_13M_3P25M_INPUT_CLK_EN                  ( BIT(18) )
#define BIT_ICU_ACLK_SW_EN                                ( BIT(17) )
#define BIT_ICU_ACLK_EN_CTRL_MODE                         ( BIT(16) )
#define BIT_AP_PMU_CLK_SW_EN                              ( BIT(15) )
#define BIT_AP_PMU_CLK_EN_CTRL_MODE                       ( BIT(14) )
#define BIT_MP_PMU_CLK_SW_EN                              ( BIT(13) )
#define BIT_MP_PMU_CLK_EN_CTRL_MODE                       ( BIT(12) )
#define BITS_PM_302(_X_)                                  ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BIT_SYS_ACLK_SW_EN                                ( BIT(9) )
#define BIT_SYS_ACLK_EN_CTRL_MODE                         ( BIT(8) )
#define BITS_PM_305(_X_)                                  ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_FC_SM_REF_CLK_SW_EN                           ( BIT(1) )
#define BIT_FC_SM_REF_CLK_EN_CTL_MODE                     ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_LCD_CLK_RES_CTRL1 */
#define BIT_MIPI_BIT_CLK_FC_REQ                           ( BIT(31) )
#define BIT_LCD_PXCLK_FC_REQ                              ( BIT(30) )
#define BIT_LCD_MCLK_FC_REQ                               ( BIT(29) )
#define BIT_LCD_ACLK_FC_REQ                               ( BIT(28) )
#define BIT_PM_HW_MODE318                                 ( BIT(27) )
#define BIT_LCD_SLEEP2                                    ( BIT(26) )
#define BIT_LCD_SLEEP1                                    ( BIT(25) )
#define BIT_LCD_ISOB                                      ( BIT(24) )
#define BIT_MIPI_BIT_BLANK_MSK                            ( BIT(23) )
#define BITS_MIPI_BIT_CLK_SEL(_X_)                        ( (_X_) << 20 & (BIT(20)|BIT(21)) )
#define BITS_MIPI_BIT_CLK_DIV(_X_)                        ( (_X_) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_MIPI_BIT_CLK_EN                               ( BIT(16) )
#define BIT_MIPI_BIT_CLK_RST                              ( BIT(15) )
#define BIT_LCD_ACLK_BLANK_MSK                            ( BIT(14) )
#define BITS_LCD_ACLK_SEL(_X_)                            ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BITS_LCD_ACLK_DIV(_X_)                            ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_LCD_ACLK_EN                                   ( BIT(8) )
#define BIT_LCD_ACLK_QCHAN_MASK                           ( BIT(7) )
#define BIT_LCD_HCLK_SWAP_CTRL                            ( BIT(6) )
#define BIT_LCD_HCLK_EN                                   ( BIT(5) )
#define BIT_LCD_SW_RST                                    ( BIT(4) )
#define BIT_DSI_ESCCLK_RESET                              ( BIT(3) )
#define BIT_DSI_ESC_EN                                    ( BIT(2) )
#define BITS_DSI_ESC_SEL(_X_)                             ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_PMU_PMU_LCD_CLK_RES_CTRL2 */
#define BIT_LCD_PXCLK_BLANK_MSK                           ( BIT(24) )
#define BIT_LCD_PXCLK_SEL                                 ( BIT(1) )
#define BIT_LCD_PXCLK_DIV                                 ( BIT(1) )
#define BIT_LCD_PXCLK_EN                                  ( BIT(16) )
#define BIT_LCD_MCLK_BLANK_MSK                            ( BIT(8) )
#define BITS_LCD_MCLK_SEL(_X_)                            ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)) )
#define BITS_LCD_MCLK_DIV(_X_)                            ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)) )
#define BIT_LCD_MCLK_EN                                   ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_CCIC_CLK_RES_CTRL */
#define BIT_CCIC_ISP_HCLK_SWAP_CTRL                       ( BIT(31) )
#define BIT_MASK_ISP_BLANK_CHECK362                       ( BIT(30) )
#define BIT_ISP_BLANK_CHECK_MODE                          ( BIT(29) )
#define BITS_CCICI_CLK4X_SEL(_X_)                         ( (_X_) << 23 & (BIT(23)|BIT(24)|BIT(25)) )
#define BIT_ISP_CCIC_AHB_RST                              ( BIT(22) )
#define BIT_ISP_CCIC_AHBCLK_EN                            ( BIT(21) )
#define BITS_CICIC_CLK4X_DIV(_X_)                         ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)) )
#define BIT_CCIC_CLK4X_FC_REQ                             ( BIT(15) )
#define BIT_CCIC1_PHYCLK_SEL                              ( BIT(7) )
#define BIT_CCIC1_PHYCLK_EN                               ( BIT(5) )
#define BIT_CCIC_CLK4X_EN                                 ( BIT(4) )
#define BIT_CCIC1_PHYCLK_RST                              ( BIT(2) )
#define BIT_CCIC_CLK4X_RST                                ( BIT(1) )

/* bits definitions for register REG_PMU_PMU_SDH0_CLK_RES_CTRL */
#define BIT_SDH0_CLK_FC_REQ                               ( BIT(11) )
#define BITS_SDH0_CLK_DIV(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BITS_SDH0_CLK_SEL(_X_)                            ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_SDH0_CLK_EN                                   ( BIT(4) )
#define BIT_SDH_AXICLK_EN                                 ( BIT(3) )
#define BIT_SDH0_RST                                      ( BIT(1) )
#define BIT_SDH_AXI_RST                                   ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_SDH1_CLK_RES_CTRL */
#define BIT_SDH1_CLK_FC_REQ                               ( BIT(11) )
#define BITS_SDH1_CLK_DIV(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BITS_SDH1_CLK_SEL(_X_)                            ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_SDH1_CLK_EN                                   ( BIT(4) )
#define BIT_SDH1_RST                                      ( BIT(1) )

/* bits definitions for register REG_PMU_PMU_USB_CLK_RES_CTRL */
#define BITS_USB_SS_SCALEDOWN_MODE(_X_)                   ( (_X_) << 9 & (BIT(9)|BIT(10)) )
#define BIT_USB_BYPASS_DEB_FILTER                         ( BIT(8) )
#define BIT_USB_AXICLK_EN                                 ( BIT(1) )
#define BIT_USB_AXI_RST                                   ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_NF_CLK_RES_CTRL */
#define BIT_NF_ECC_RES                                    ( BIT(8) )
#define BIT_NF_ECC_CLK_EN                                 ( BIT(7) )
#define BIT_NF_CLK_SEL                                    ( BIT(6) )
#define BIT_NF_CLK_EN                                     ( BIT(4) )
#define BIT_NF_AXICLK_EN                                  ( BIT(3) )
#define BIT_NF_RST                                        ( BIT(1) )
#define BIT_NF_AXI_RST                                    ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_DMA_CLK_RES_CTRL */
#define BIT_DMA_AXICLK_EN                                 ( BIT(3) )
#define BIT_DMA_AXI_RST                                   ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_AES_CLK_RES_CTRL */
#define BIT_WTM_CLK_SEL                                   ( BIT(6) )
#define BIT_WTM_CLK_EN                                    ( BIT(5) )
#define BIT_WTM_RST                                       ( BIT(4) )

/* bits definitions for register REG_PMU_PMU_MCB_CLK_RES_CTRL */
#define BIT_ACLK_SW_RST                                   ( BIT(1) )
#define BIT_DCLK_SW_RST                                   ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_CP_IMR */
#define BIT_AP_C2_FC_INTR_MASK                            ( BIT(25) )
#define BIT_AP_CORE9_IDLE_WAKE_INTR_MASK478               ( BIT(22) )
#define BIT_AP_CORE8_IDLE_WAKE_INTR_MASK479               ( BIT(21) )
#define BIT_AP_C1_FC_INTR_MASK                            ( BIT(20) )
#define BIT_AP_CORE7_IDLE_WAKE_INTR_MASK481               ( BIT(19) )
#define BIT_AP_CORE6_IDLE_WAKE_INTR_MASK482               ( BIT(18) )
#define BIT_AP_CORE5_IDLE_WAKE_INTR_MASK483               ( BIT(17) )
#define BIT_AP_CORE4_IDLE_WAKE_INTR_MASK484               ( BIT(16) )
#define BIT_SP_CORE_IDLE_WAKE_INTR_MASK486                ( BIT(11) )
#define BIT_AP_CORE3_IDLE_WAKE_INTR_MASK487               ( BIT(10) )
#define BIT_AP_CORE2_IDLE_WAKE_INTR_MASK488               ( BIT(9) )
#define BIT_AP_CORE1_IDLE_WAKE_INTR_MASK489               ( BIT(8) )
#define BIT_AP_CORE0_IDLE_WAKE_INTR_MASK490               ( BIT(7) )
#define BIT_CP_IDLE_WAKE_INTR_MASK491                     ( BIT(6) )
#define BIT_ACLK_FC_DONE_INTR_MASK492                     ( BIT(5) )
#define BIT_DCLK_FC_DONE_INTR_MASK493                     ( BIT(4) )
#define BIT_AP_FC_DONE_INTR_MASK                          ( BIT(3) )
#define BIT_CP_FC_DONE_INTR_MASK495                       ( BIT(2) )
#define BIT_AP_C0_FC_INTR_MASK                            ( BIT(1) )
#define BIT_CP_FC_INTR_MASK497                            ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_CP_IRWC */
#define BIT_AP_C2_FC_DONE_INTR_IRST505                    ( BIT(25) )
#define BIT_AP_CORE9_IDLE_WAKE_INTR_IRST507               ( BIT(22) )
#define BIT_AP_CORE8_IDLE_WAKE_INTR_IRST508               ( BIT(21) )
#define BIT_AP_C1_FC_DONE_INTR_IRST509                    ( BIT(20) )
#define BIT_AP_CORE7_IDLE_WAKE_INTR_IRST510               ( BIT(19) )
#define BIT_AP_CORE6_IDLE_WAKE_INTR_IRST511               ( BIT(18) )
#define BIT_AP_CORE5_IDLE_WAKE_INTR_IRST512               ( BIT(17) )
#define BIT_AP_CORE4_IDLE_WAKE_INTR_IRST513               ( BIT(16) )
#define BIT_SP_CORE_IDLE_WAKE_INTR_IRST515                ( BIT(11) )
#define BIT_AP_CORE3_IDLE_WAKE_INTR_IRST516               ( BIT(10) )
#define BIT_AP_CORE2_IDLE_WAKE_INTR_IRST517               ( BIT(9) )
#define BIT_AP_CORE1_IDLE_WAKE_INTR_IRST518               ( BIT(8) )
#define BIT_AP_CORE0_IDLE_WAKE_INTR_IRST519               ( BIT(7) )
#define BIT_CP_IDLE_WAKE_INTR_IRST520                     ( BIT(6) )
#define BIT_ACLK_FC_DONE_INTR_IRST521                     ( BIT(5) )
#define BIT_DCLK_FC_DONE_INTR_IRST522                     ( BIT(4) )
#define BIT_AP_C0_FC_DONE_INTR_IRST523                    ( BIT(3) )
#define BIT_CP_FC_DONE_INTR_IRST524                       ( BIT(2) )
#define BIT_AP_FC_INTR_IRST525                            ( BIT(1) )
#define BIT_CP_FC_INTR_IRST526                            ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_CP_ISR */
#define BIT_AP_C2_FC_DONE_INTR_ISR534                     ( BIT(25) )
#define BIT_AP_CORE9_IDLE_WAKE_INTR_ISR536                ( BIT(22) )
#define BIT_AP_CORE8_IDLE_WAKE_INTR_ISR537                ( BIT(21) )
#define BIT_AP_C1_FC_DONE_INTR_ISR538                     ( BIT(20) )
#define BIT_AP_CORE7_IDLE_WAKE_INTR_ISR539                ( BIT(19) )
#define BIT_AP_CORE6_IDLE_WAKE_INTR_ISR540                ( BIT(18) )
#define BIT_AP_CORE5_IDLE_WAKE_INTR_ISR541                ( BIT(17) )
#define BIT_AP_CORE4_IDLE_WAKE_INTR_ISR542                ( BIT(16) )
#define BIT_SP_CORE_IDLE_WAKE_INTR_ISR544                 ( BIT(11) )
#define BIT_AP_CORE3_IDLE_WAKE_INTR_ISR545                ( BIT(10) )
#define BIT_AP_CORE2_IDLE_WAKE_INTR_ISR546                ( BIT(9) )
#define BIT_AP_CORE1_IDLE_WAKE_INTR_ISR547                ( BIT(8) )
#define BIT_AP_CORE0_IDLE_WAKE_INTR_ISR548                ( BIT(7) )
#define BIT_CP_IDLE_WAKE_INTR_ISR549                      ( BIT(6) )
#define BIT_ACLK_FC_DONE_INTR_ISR550                      ( BIT(5) )
#define BIT_DCLK_FC_DONE_INTR_ISR551                      ( BIT(4) )
#define BIT_AP_C0_FC_DONE_INTR_ISR552                     ( BIT(3) )
#define BIT_CP_FC_DONE_INTR_ISR553                        ( BIT(2) )
#define BIT_AP_FC_ISR554                                  ( BIT(1) )
#define BIT_CP_FC_ISR555                                  ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_SD_ROT_WAKE_CLR */
#define BITS_RSVD562(_X_)                                 ( (_X_) << 29 & (BIT(29)|BIT(30)|BIT(31)) )
#define BIT_USB_CHGDET_WK_STATUS                          ( BIT(28) )
#define BIT_USB_ID_WK_STATUS                              ( BIT(27) )
#define BIT_USB_VBUS_WK_STATUS                            ( BIT(26) )
#define BIT_USB_LINE1_WK_STATUS                           ( BIT(25) )
#define BIT_USB_LINE0_WK_STATUS                           ( BIT(24) )
#define BITS_RSVD568(_X_)                                 ( (_X_) << 21 & (BIT(21)|BIT(22)|BIT(23)) )
#define BIT_USB_CHGDET_WK_CLR                             ( BIT(20) )
#define BIT_USB_ID_WK_CLR                                 ( BIT(19) )
#define BIT_USB_VBUS_WK_CLR                               ( BIT(18) )
#define BIT_USB_LINE1_WK_CLR                              ( BIT(17) )
#define BIT_USB_LINE0_WK_CLR                              ( BIT(16) )
#define BITS_RSVD574(_X_)                                 ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_USB_CHGDET_WK_MASK                            ( BIT(12) )
#define BIT_USB_ID_WK_MASK                                ( BIT(11) )
#define BIT_USB_VBUS_WK_MASK                              ( BIT(10) )
#define BIT_USB_LINE1_WK_MASK                             ( BIT(9) )
#define BIT_USB_LINE0_WK_MASK                             ( BIT(8) )
#define BIT_CS_WK_STATUS                                  ( BIT(7) )
#define BIT_SDH2_WK_CLR                                   ( BIT(6) )
#define BIT_CS_WK_CLR                                     ( BIT(5) )
#define BIT_CS_WK_MASK                                    ( BIT(4) )
#define BIT_KB_WK_CLR                                     ( BIT(3) )
#define BIT_ROT_WK_CLR                                    ( BIT(2) )
#define BIT_SDH1_WK_CLR                                   ( BIT(1) )
#define BIT_SDH0_WK_CLR                                   ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_PWR_STBL_TIMER */
#define BITS_PM_PWR_CLK_PRE597(_X_)                       ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_PM_PWR_UP_STBL_TIMER598(_X_)                 ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_PM_PWR_DWN_STBL_TIMER599(_X_)                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_PMU_PMU_DEBUG_REG */
#define BIT_MIPI_DSI_DPHY_VDD_DVM_VALID                   ( BIT(31) )
#define BIT_AP_CORE_GBL_IRQ_MASK_CLR_DIS                  ( BIT(30) )
#define BIT_CP_GBL_IRQ_MASK_CLR_DIS                       ( BIT(29) )
#define BIT_MASK_ISP_BLANK_CHECK609                       ( BIT(28) )
#define BIT_MASK_LCD_BLANK_CHECK                          ( BIT(27) )
#define BIT_MIPI_CSI_DPHY_4LN_VDD_DVM_VALID               ( BIT(26) )
#define BIT_MIPI_CSI_DPHY_2LN_VDD_DVM_VALID               ( BIT(25) )
#define BIT_FUNC_PLL_BYPASS                               ( BIT(24) )
#define BIT_MASK_MC_SW_IDLE_INDICATION                    ( BIT(23) )
#define BIT_DFC_D1P_DISABLE                               ( BIT(21) )
#define BIT_MASK_MC_CLK_ON_CHECK                          ( BIT(20) )
#define BIT_MASK_MC_CLK_OFF_CHECK                         ( BIT(19) )
#define BIT_MIPI_CSI2_DPHY_4LN_VDD_DVM_VALID              ( BIT(18) )
#define BIT_MASK_CP_JTAG_IDLE_INDICATION                  ( BIT(17) )
#define BIT_MASK_MAIN_CLK_ON_CHECK                        ( BIT(16) )
#define BIT_MASK_MAIN_CLK_OFF_CHECK                       ( BIT(15) )
#define BIT_MASK_MC_IDLE_INDICATION                       ( BIT(14) )
#define BIT_MASK_DMA_IDLE_INDICATION                      ( BIT(13) )
#define BIT_MASK_AP_IDLE_IND                              ( BIT(12) )
#define BIT_MASK_CP_IDLE_IND                              ( BIT(11) )
#define BIT_MASK_AP_CLK_ON_ACK_FOR_IDLE                   ( BIT(10) )
#define BIT_MASK_AP_CLK_OFF_ACK_FOR_IDLE                  ( BIT(9) )
#define BIT_MASK_CP_CLK_ON_ACK_FOR_IDLE                   ( BIT(8) )
#define BIT_MASK_CP_CLK_OFF_ACK_FOR_IDLE                  ( BIT(7) )
#define BIT_MASK_ACLK_CLK_OFF_ACK                         ( BIT(6) )
#define BIT_MASK_DCLK_CLK_OFF_ACK                         ( BIT(5) )
#define BIT_MASK_AP_CLK_OFF_ACK                           ( BIT(4) )
#define BIT_MASK_CP_CLK_OFF_ACK                           ( BIT(3) )
#define BIT_MASK_MC_HALT                                  ( BIT(2) )
#define BIT_MASK_AP_HALT                                  ( BIT(1) )
#define BIT_MASK_CP_HALT                                  ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_SRAM_PWR_DWN */
#define BIT_CP_L2_LOW_LEAKAGE_EN                          ( BIT(21) )
#define BIT_CP_L2_LOW_LEAKAGE_DIS                         ( BIT(20) )
#define BIT_AP_L2_LOW_LEAKAGE_EN                          ( BIT(19) )
#define BIT_AP_L2_LOW_LEAKAGE_DIS                         ( BIT(18) )
#define BIT_SQU_SRAM_PDWN_CP                              ( BIT(17) )
#define BIT_SQU_SRAM_PDWN_AP                              ( BIT(16) )
#define BIT_AP_L1_LOW_LEAKAGE_EN                          ( BIT(9) )
#define BIT_AP_L1_LOW_LEAKAGE_DIS                         ( BIT(8) )
#define BIT_CP_L1_LOW_LEAKAGE_EN                          ( BIT(1) )
#define BIT_CP_L1_LOW_LEAKAGE_DIS                         ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_CORE_STATUS */
#define BIT_AP_CORE7_C2                                   ( BIT(31) )
#define BIT_AP_CORE7_C1                                   ( BIT(30) )
#define BIT_AP_CORE7_WFI_FLAG                             ( BIT(29) )
#define BIT_AP_CORE6_C2                                   ( BIT(28) )
#define BIT_AP_CORE6_C1                                   ( BIT(27) )
#define BIT_AP_CORE6_WFI_FLAG                             ( BIT(26) )
#define BIT_AP_CORE5_C2                                   ( BIT(25) )
#define BIT_AP_CORE5_C1                                   ( BIT(24) )
#define BIT_AP_CORE5_WFI_FLAG                             ( BIT(23) )
#define BIT_AP_CORE4_C2                                   ( BIT(22) )
#define BIT_AP_CORE4_C1                                   ( BIT(21) )
#define BIT_AP_CORE4_WFI_FLAG                             ( BIT(20) )
#define BIT_AP_C1_MPSUB_M2                                ( BIT(19) )
#define BIT_AP_C1_MPSUB_M1                                ( BIT(18) )
#define BIT_AP_C1_MPSUB_IDLE_FLAG                         ( BIT(17) )
#define BIT_SP_IDLE                                       ( BIT(16) )
#define BIT_AP_CORE3_C2                                   ( BIT(15) )
#define BIT_AP_CORE3_C1                                   ( BIT(14) )
#define BIT_AP_CORE3_WFI_FLAG                             ( BIT(13) )
#define BIT_AP_CORE2_C2                                   ( BIT(12) )
#define BIT_AP_CORE2_C1                                   ( BIT(11) )
#define BIT_AP_CORE2_WFI_FLAG                             ( BIT(10) )
#define BIT_AP_CORE1_C2                                   ( BIT(9) )
#define BIT_AP_CORE1_C1                                   ( BIT(8) )
#define BIT_AP_CORE1_WFI_FLAG                             ( BIT(7) )
#define BIT_AP_CORE0_C2                                   ( BIT(6) )
#define BIT_AP_CORE0_C1                                   ( BIT(5) )
#define BIT_AP_CORE0_WFI_FLAG                             ( BIT(4) )
#define BIT_AP_C0_MPSUB_M2                                ( BIT(3) )
#define BIT_AP_C0_MPSUB_M1                                ( BIT(2) )
#define BIT_AP_C0_MPSUB_IDLE_FLAG                         ( BIT(1) )

/* bits definitions for register REG_PMU_PMU_RES_FRM_SLP_CLR */
#define BIT_CLR_RSM_FRM_SLP                               ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_AP_IMR */
#define BIT_AP_C2_FC_DONE_INTR_MASK                       ( BIT(25) )
#define BIT_AP_CORE9_IDLE_WAKE_INTR_MASK712               ( BIT(22) )
#define BIT_AP_CORE8_IDLE_WAKE_INTR_MASK713               ( BIT(21) )
#define BIT_AP_C1_FC_DONE_INTR_MASK                       ( BIT(20) )
#define BIT_AP_CORE7_IDLE_WAKE_INTR_MASK715               ( BIT(19) )
#define BIT_AP_CORE6_IDLE_WAKE_INTR_MASK716               ( BIT(18) )
#define BIT_AP_CORE5_IDLE_WAKE_INTR_MASK717               ( BIT(17) )
#define BIT_AP_CORE4_IDLE_WAKE_INTR_MASK718               ( BIT(16) )
#define BIT_SP_CORE_IDLE_WAKE_INTR_MASK720                ( BIT(11) )
#define BIT_AP_CORE3_IDLE_WAKE_INTR_MASK721               ( BIT(10) )
#define BIT_AP_CORE2_IDLE_WAKE_INTR_MASK722               ( BIT(9) )
#define BIT_AP_CORE1_IDLE_WAKE_INTR_MASK723               ( BIT(8) )
#define BIT_AP_CORE0_IDLE_WAKE_INTR_MASK724               ( BIT(7) )
#define BIT_CP_IDLE_WAKE_INTR_MASK725                     ( BIT(6) )
#define BIT_ACLK_FC_DONE_INTR_MASK726                     ( BIT(5) )
#define BIT_DCLK_FC_DONE_INTR_MASK727                     ( BIT(4) )
#define BIT_AP_C0_FC_DONE_INTR_MASK                       ( BIT(3) )
#define BIT_CP_FC_DONE_INTR_MASK729                       ( BIT(2) )
#define BIT_AP_FC_INTR_MASK                               ( BIT(1) )
#define BIT_CP_FC_INTR_MASK731                            ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_AP_IRWC */
#define BIT_AP_C2_FC_DONE_INTR_IRST739                    ( BIT(25) )
#define BIT_AP_CORE9_IDLE_WAKE_INTR_IRST741               ( BIT(22) )
#define BIT_AP_CORE8_IDLE_WAKE_INTR_IRST742               ( BIT(21) )
#define BIT_AP_C1_FC_DONE_INTR_IRST743                    ( BIT(20) )
#define BIT_AP_CORE7_IDLE_WAKE_INTR_IRST744               ( BIT(19) )
#define BIT_AP_CORE6_IDLE_WAKE_INTR_IRST745               ( BIT(18) )
#define BIT_AP_CORE5_IDLE_WAKE_INTR_IRST746               ( BIT(17) )
#define BIT_AP_CORE4_IDLE_WAKE_INTR_IRST747               ( BIT(16) )
#define BIT_SP_CORE_IDLE_WAKE_INTR_IRST749                ( BIT(11) )
#define BIT_AP_CORE3_IDLE_WAKE_INTR_IRST750               ( BIT(10) )
#define BIT_AP_CORE2_IDLE_WAKE_INTR_IRST751               ( BIT(9) )
#define BIT_AP_CORE1_IDLE_WAKE_INTR_IRST752               ( BIT(8) )
#define BIT_AP_CORE0_IDLE_WAKE_INTR_IRST753               ( BIT(7) )
#define BIT_CP_IDLE_WAKE_INTR_IRST754                     ( BIT(6) )
#define BIT_ACLK_FC_DONE_INTR_IRST755                     ( BIT(5) )
#define BIT_DCLK_FC_DONE_INTR_IRST756                     ( BIT(4) )
#define BIT_AP_C0_FC_DONE_INTR_IRST757                    ( BIT(3) )
#define BIT_CP_FC_DONE_INTR_IRST758                       ( BIT(2) )
#define BIT_AP_FC_INTR_IRST759                            ( BIT(1) )
#define BIT_CP_FC_INTR_IRST760                            ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_AP_ISR */
#define BIT_AP_C2_FC_DONE_INTR_ISR768                     ( BIT(25) )
#define BIT_AP_CORE9_IDLE_WAKE_INTR_ISR770                ( BIT(22) )
#define BIT_AP_CORE8_IDLE_WAKE_INTR_ISR771                ( BIT(21) )
#define BIT_AP_C1_FC_DONE_INTR_ISR772                     ( BIT(20) )
#define BIT_AP_CORE7_IDLE_WAKE_INTR_ISR773                ( BIT(19) )
#define BIT_AP_CORE6_IDLE_WAKE_INTR_ISR774                ( BIT(18) )
#define BIT_AP_CORE5_IDLE_WAKE_INTR_ISR775                ( BIT(17) )
#define BIT_AP_CORE4_IDLE_WAKE_INTR_ISR776                ( BIT(16) )
#define BIT_SP_CORE_IDLE_WAKE_INTR_ISR778                 ( BIT(11) )
#define BIT_AP_CORE3_IDLE_WAKE_INTR_ISR779                ( BIT(10) )
#define BIT_AP_CORE2_IDLE_WAKE_INTR_ISR780                ( BIT(9) )
#define BIT_AP_CORE1_IDLE_WAKE_INTR_ISR781                ( BIT(8) )
#define BIT_AP_CORE0_IDLE_WAKE_INTR_ISR782                ( BIT(7) )
#define BIT_CP_IDLE_WAKE_INTR_ISR783                      ( BIT(6) )
#define BIT_ACLK_FC_DONE_INTR_ISR784                      ( BIT(5) )
#define BIT_DCLK_FC_DONE_INTR_ISR785                      ( BIT(4) )
#define BIT_AP_C0_FC_DONE_INTR_ISR786                     ( BIT(3) )
#define BIT_CP_FC_DONE_INTR_ISR787                        ( BIT(2) )
#define BIT_AP_FC_ISR788                                  ( BIT(1) )
#define BIT_CP_FC_ISR789                                  ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_VPU_CLK_RES_CTRL */
#define BIT_VPU_CLK_FC_REQ                                ( BIT(21) )
#define BIT_VPU_FUSE_LOAD_MASK                            ( BIT(20) )
#define BIT_VPU_HW_MODE                                   ( BIT(19) )
#define BIT_VPU_SLEEP2                                    ( BIT(18) )
#define BIT_VPU_SLEEP1                                    ( BIT(17) )
#define BIT_VPU_ISOB                                      ( BIT(16) )
#define BITS_VPU_CLK_DIV(_X_)                             ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)) )
#define BITS_VPU_CLK_SEL(_X_)                             ( (_X_) << 10 & (BIT(10)|BIT(11)|BIT(12)) )
#define BIT_VPU_CLK_EN                                    ( BIT(3) )
#define BIT_VPU_RST                                       ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_DTC_CLK_RES_CTRL */
#define BIT_DTC_AXICLK_EN                                 ( BIT(3) )
#define BIT_DTC_AXI_RST                                   ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_MC_HW_SLP_TYPE */
#define BIT_DCLK_BYPASS_FC_REQ                            ( BIT(23) )
#define BIT_DCLK_BYPASS_CLK_EN                            ( BIT(22) )
#define BIT_DCLK_BYPASS_RST                               ( BIT(21) )
#define BITS_DCLK_BYPASS_SEL(_X_)                         ( (_X_) << 19 & (BIT(19)|BIT(20)) )
#define BITS_DCLK_BYPASS_DIV(_X_)                         ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_MC_REG_TABLE_EN                               ( BIT(10) )
#define BIT_FREQ_PLL_CHG_MODE                             ( BIT(9) )
#define BITS_MC_REG_TABLE_NUM(_X_)                        ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_PMU_PMU_MC_SLP_REQ_AP */
#define BIT_MC_SLP_ACK845                                 ( BIT(1) )
#define BIT_MC_SLP_REQ_AP                                 ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_MC_SLP_REQ_CP */
#define BIT_MC_SLP_ACK854                                 ( BIT(1) )
#define BIT_MC_SLP_REQ_CP                                 ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_MC_SLP_REQ_MSA */
#define BIT_MC_SLP_ACK863                                 ( BIT(1) )
#define BIT_MC_SLP_REQ_MSA                                ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_MC_SW_SLP_TYPE */
#define BITS_MC_SW_SLP_TYPE(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_PMU_PMU_PLL_SEL_STATUS */
#define BITS_AP_C2_PLL_SEL(_X_)                           ( (_X_) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BITS_AP_C1_PLL_SEL(_X_)                           ( (_X_) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BITS_AP_C0_PLL_SEL(_X_)                           ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BITS_ACLK_PLL_SEL(_X_)                            ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_DCLK_PLL_SEL(_X_)                            ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)) )
#define BITS_CP_PLL_SEL(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_PMU_PMU_GPU_CLK_RES_CTRL */
#define BITS_GPU_CLK_SEL(_X_)                             ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)) )
#define BIT_GPU_CLKMODE                                   ( BIT(16) )
#define BIT_GPU_FNC_FC_REQ                                ( BIT(15) )
#define BITS_GPU_CLK_DIV(_X_)                             ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PM_HW_MODE898                                 ( BIT(11) )
#define BIT_GPU_SLEEP2                                    ( BIT(10) )
#define BIT_GPU_SLEEP1                                    ( BIT(9) )
#define BIT_GPU_ISOB                                      ( BIT(8) )
#define BIT_GPU_CLK_EN                                    ( BIT(4) )
#define BIT_GPU_RST1                                      ( BIT(1) )

/* bits definitions for register REG_PMU_PMUA_SMC_CLK_RES_CTRL */
#define BITS_SMC_CLK_SEL(_X_)                             ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_SMC_CLK_EN                                    ( BIT(4) )
#define BIT_SMC_AXICLK_EN                                 ( BIT(3) )
#define BIT_SMC_RST                                       ( BIT(1) )
#define BIT_SMC_AXI_RST                                   ( BIT(0) )

/* bits definitions for register REG_PMU_PMUA_PWR_CTRL_REG */

/* bits definitions for register REG_PMU_PMUA_PWR_BLK_TMR_REG */
#define BITS_PWR_ON1_TIMER(_X_)                           ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_PWR_ON2_TIMER(_X_)                           ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_PWR_OFF_TIMER(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_PMU_PMUA_SDH2_CLK_RES_CTRL */
#define BIT_SDH2_CLK_FC_REQ                               ( BIT(11) )
#define BITS_SDH2_CLK_DIV(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BITS_SDH2_CLK_SEL(_X_)                            ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_SDH2_CLK_EN                                   ( BIT(4) )
#define BIT_SDH2_RST                                      ( BIT(1) )

/* bits definitions for register REG_PMU_PMU_C0_CAPMP_IDLE_CFGx3 */
#define BIT_DIS_MP_L2_SLP960                              ( BIT(19) )
#define BIT_DIS_MP_SLP961                                 ( BIT(18) )
#define BIT_MP_L2_PWR_OFF963                              ( BIT(16) )
#define BIT_L2_HW_CACHE_FLUSH_EN965                       ( BIT(13) )
#define BIT_MASK_SRAM_REPAIR_DONE_CHECK966                ( BIT(12) )
#define BIT_MASK_CLK_OFF_CHECK967                         ( BIT(11) )
#define BIT_MASK_CLK_STBL_CHECK968                        ( BIT(10) )
#define BIT_MASK_JTAG_IDLE_CHECK969                       ( BIT(9) )
#define BIT_MASK_IDLE_CHECK970                            ( BIT(8) )
#define BIT_ACINACTM_HW_CTRL971                           ( BIT(7) )
#define BIT_DIS_MC_SW_REQ973                              ( BIT(5) )
#define BIT_MP_WAKE_MC_EN974                              ( BIT(4) )
#define BIT_MP_SCU_SRAM_PWRDWN975                         ( BIT(3) )
#define BIT_PM_976                                        ( BIT(3) )
#define BIT_L2_SRAM_PWRDWN977                             ( BIT(2) )
#define BIT_MP_PWRDWN978                                  ( BIT(1) )
#define BIT_MP_IDLE979                                    ( BIT(0) )

/* bits definitions for register REG_PMU_PMUA_MC_CTRL */
#define BIT_DFC_D1P_BLOCK                                 ( BIT(31) )
#define BIT_DDR_DPHY_PU                                   ( BIT(30) )
#define BIT_BYPS_DFI_INIT_HW                              ( BIT(29) )
#define BIT_BYPS_FREQ_HW                                  ( BIT(28) )
#define BIT_MC_SEL_AUD_APB                                ( BIT(27) )
#define BIT_BYPS_PHY_ARC_HW                               ( BIT(26) )
#define BIT_BYPS_DEASS_PWROK                              ( BIT(25) )
#define BIT_MC_INIT_BYPASS                                ( BIT(24) )
#define BIT_MC_DEASS_PWROK                                ( BIT(17) )
#define BIT_MC_ASS_PWROK                                  ( BIT(16) )
#define BIT_MC_PHY_RSTN                                   ( BIT(9) )
#define BIT_MC_CORE_RSTN                                  ( BIT(8) )
#define BIT_HW_DRAIN_CAM                                  ( BIT(4) )
#define BIT_DTE_AHBCLK_EN                                 ( BIT(3) )
#define BIT_DTE_HCLK_RST                                  ( BIT(2) )
#define BIT_MC_AHBCLK_EN                                  ( BIT(1) )
#define BIT_MC_HCLK_RST                                   ( BIT(0) )

/* bits definitions for register REG_PMU_PMUA_PWR_STATUS_REG */
#define BIT_LCD_HW_PWR_STAT                               ( BIT(12) )
#define BIT_AUDIO_HW_PWR_STAT                             ( BIT(11) )
#define BIT_ISP_HW_PWR_STAT                               ( BIT(10) )
#define BIT_VPU_HW_PWR_STAT                               ( BIT(9) )
#define BIT_GPU_HW_PWR_STAT                               ( BIT(8) )
#define BIT_LCD_PWR_STATUS                                ( BIT(4) )
#define BIT_AUDIO_PWR_STATUS1021                          ( BIT(3) )
#define BIT_ISP_PWR_STATUS                                ( BIT(2) )
#define BIT_VPU_PWR_STATUS                                ( BIT(1) )
#define BIT_GPU_PWR_STATUS                                ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_SP_IDLE_CFG */
#define BIT_MASK_SP_IDLE_IND                              ( BIT(4) )
#define BIT_SP_GBL_IRQ_MASK_CLR_DIS                       ( BIT(3) )
#define BIT_MASK_SP_CLK_ON_CHECK                          ( BIT(2) )
#define BIT_MASK_SP_CLK_OFF_ACK                           ( BIT(1) )
#define BIT_MASK_WFI_CHECK1036                            ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_GNSS_PWR_CTRL */
#define BIT_GNSS_RST_STATUS                               ( BIT(9) )
#define BIT_GNSS_SILENT_RST_MODE                          ( BIT(8) )
#define BIT_GNSS_ACLK_EN                                  ( BIT(7) )
#define BIT_GNSS_FUSE_LOAD_MASK                           ( BIT(6) )
#define BIT_GNSS_FUSE_LOAD_START                          ( BIT(5) )
#define BIT_GNSS_SLEEP2                                   ( BIT(4) )
#define BIT_GNSS_SLEEP1                                   ( BIT(3) )
#define BIT_GNSS_ISOB                                     ( BIT(2) )
#define BIT_GNSS_RSTN                                     ( BIT(1) )
#define BIT_GNSS_HW_MODE1054                              ( BIT(0) )
#define BIT_GNSS_HW_MODE1055                              ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_CC2_AP */
#define BIT_MPSUB_DBG_RST                                 ( BIT(29) )
#define BIT_C1_MPSUB_SW_RST                               ( BIT(28) )
#define BIT_CPU7_SW_RST                                   ( BIT(26) )
#define BIT_CPU7_POR_RST                                  ( BIT(25) )
#define BIT_CPU6_SW_RST                                   ( BIT(23) )
#define BIT_CPU6_POR_RST                                  ( BIT(22) )
#define BIT_CPU5_SW_RST                                   ( BIT(20) )
#define BIT_CPU5_POR_RST                                  ( BIT(19) )
#define BIT_CPU4_SW_RST                                   ( BIT(17) )
#define BIT_CPU4_POR_RST                                  ( BIT(16) )
#define BIT_C0_MPSUB_SW_RST                               ( BIT(12) )
#define BIT_CPU3_SW_RST                                   ( BIT(10) )
#define BIT_CPU3_POR_RST                                  ( BIT(9) )
#define BIT_CPU2_SW_RST                                   ( BIT(7) )
#define BIT_CPU2_POR_RST                                  ( BIT(6) )
#define BIT_CPU1_SW_RST                                   ( BIT(4) )
#define BIT_CPU1_POR_RST                                  ( BIT(3) )
#define BIT_CPU0_SW_RST                                   ( BIT(1) )
#define BIT_CPU0_POR_RST                                  ( BIT(0) )

/* bits definitions for register REG_PMU_PMUA_EM_CLK_RES_CTRL */
#define BIT_EM_PHY_TMS_SW                                 ( BIT(31) )
#define BIT_EM_PHY_TOE_SW                                 ( BIT(30) )
#define BIT_EM_PHY_VREF                                   ( BIT(29) )
#define BIT_EM_PHY_V18EN                                  ( BIT(28) )
#define BIT_EM_PHY_LP_SEL                                 ( BIT(27) )
#define BIT_EM_1248M_CLK_EN                               ( BIT(15) )
#define BITS_EM_1248M_CLK_DIV(_X_)                        ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_EM_CLK_FC_REQ                                 ( BIT(11) )
#define BITS_EM_CLK_DIV(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BITS_EM_CLK_SEL(_X_)                              ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_EM_CLK_EN                                     ( BIT(4) )
#define BIT_EM_AXICLK_EN                                  ( BIT(3) )
#define BIT_EM_RST                                        ( BIT(1) )
#define BIT_EM_AXI_RST                                    ( BIT(0) )

/* bits definitions for register REG_PMU_TRACE_CONFIG */
#define BITS_PCLKDBG_DIV(_X_)                             ( (_X_) << 19 & (BIT(19)|BIT(20)|BIT(21)) )
#define BIT_DBG_CLK_SEL                                   ( BIT(17) )
#define BIT_SWRST                                         ( BIT(16) )
#define BIT_TRACE_CLK_FC_REQ                              ( BIT(15) )
#define BIT_TPIU_CLK_SEL                                  ( BIT(11) )
#define BITS_TRACE_CLK_DIV(_X_)                           ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_TRACE_CLK_SEL                                 ( BIT(6) )
#define BIT_DBG_CLK_FC_REQ                                ( BIT(5) )
#define BIT_TRACE_CLK_EN                                  ( BIT(4) )
#define BIT_DBGCLK_EN                                     ( BIT(3) )
#define BITS_ATCLK_DIV(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_PMU_PMUA_USB_PHY_CTRL0 */
#define BITS_USB_PHY_PLLPTUNE(_X_)                        ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BITS_USB_PHY_PLLITUNE(_X_)                        ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BIT_USB_PHY_DCDENB                                ( BIT(11) )
#define BIT_USB_PHY_VDATSRCENB                            ( BIT(10) )
#define BIT_USB_PHY_VDATDETENB                            ( BIT(9) )
#define BIT_USB_PHY_CHGSEL                                ( BIT(8) )
#define BIT_USB_PHY_TXBITSTUFFENH                         ( BIT(7) )
#define BIT_USB_PHY_TXBITSTUFFEN                          ( BIT(6) )
#define BIT_USB_PHY_SIDDQ                                 ( BIT(5) )
#define BIT_USB_PHY_SLEEPM                                ( BIT(4) )
#define BIT_USB_PHY_OTGDIS                                ( BIT(3) )
#define BIT_USB_PHY_COMMONONN                             ( BIT(2) )
#define BIT_USB_PHY_PORTRST                               ( BIT(1) )
#define BIT_USB_PHY_POR                                   ( BIT(0) )

/* bits definitions for register REG_PMU_PMUA_USB_PHY_CTRL1 */
#define BIT_USB_PHY_TXPREEMPPULSETUNE                     ( BIT(27) )
#define BITS_USB_PHY_TXPREEMPAMPTUNE(_X_)                 ( (_X_) << 25 & (BIT(25)|BIT(26)) )
#define BITS_USB_PHY_TXRESTUNE(_X_)                       ( (_X_) << 23 & (BIT(23)|BIT(24)) )
#define BITS_USB_PHY_TXRISETUNE(_X_)                      ( (_X_) << 21 & (BIT(21)|BIT(22)) )
#define BITS_USB_PHY_TXVREFTUNE(_X_)                      ( (_X_) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BITS_USB_PHY_TXFSLSTUNE(_X_)                      ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BITS_USB_PHY_TXHSXVTUNE(_X_)                      ( (_X_) << 11 & (BIT(11)|BIT(12)) )
#define BITS_USB_PHY_OTGTUNE(_X_)                         ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BITS_USB_PHY_VDATREFTUNE(_X_)                     ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_USB_PHY_SQRXTUNE(_X_)                        ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)) )
#define BITS_USB_PHY_COMPDISTUNE(_X_)                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_PMU_PMUA_USB_PHY_READ */
#define BIT_USB_PHY_FSVMINUS                              ( BIT(7) )
#define BIT_USB_PHY_FSVPLUS                               ( BIT(6) )
#define BIT_USB_PHY_FSLSRCV                               ( BIT(5) )
#define BITS_USB_PHY_LINESTATE(_X_)                       ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BIT_USB_PHY_VBUSVALID                             ( BIT(2) )
#define BIT_USB_PHY_IDDIG                                 ( BIT(1) )
#define BIT_USB_PHY_CHGDECT                               ( BIT(0) )

/* bits definitions for register REG_PMU_PMUA_USB_PHY_TEST */
#define BITS_USB_PHY_TESTDATAIN(_X_)                      ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_USB_PHY_TESTADDR(_X_)                        ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_USB_PHY_TESTBURNIN                            ( BIT(19) )
#define BIT_USB_PHY_TESTDATAOUTSEL                        ( BIT(18) )
#define BIT_USB_PHY_TESTEN                                ( BIT(17) )
#define BIT_USB_PHY_TESTCLK                               ( BIT(16) )
#define BITS_USB_PHY_SCANPSI(_X_)                         ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_USB_PHY_LOOPBACKENB                           ( BIT(6) )
#define BIT_USB_PHY_SCANNSI                               ( BIT(5) )
#define BIT_USB_PHY_SCANEN                                ( BIT(4) )
#define BIT_USB_PHY_SCANCLK                               ( BIT(3) )
#define BITS_USB_PHY_VATESTENB(_X_)                       ( (_X_) << 1 & (BIT(1)|BIT(2)) )
#define BIT_USB_PHY_ATERESET                              ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_CAP_COREx_IDLE_CFG9 */
#define BITS_PM_PSW_MODE1217(_X_)                         ( (_X_) << 20 & (BIT(20)|BIT(21)) )
#define BIT_PM_DIS_CORE_L1_SLP1218                        ( BIT(19) )
#define BIT_PM_DIS_CORE_SLP1219                           ( BIT(18) )
#define BIT_MASK_CLK_OFF_CHECK1221                        ( BIT(11) )
#define BIT_MASK_CLK_STBL_CHECK1222                       ( BIT(10) )
#define BIT_MASK_JTAG_IDLE_CHECK1223                      ( BIT(9) )
#define BIT_PM_MASK_CORE_WFI_IDLE_CHECK1224               ( BIT(8) )
#define BIT_MASK_GIC_NFIQ_TO_CORE                         ( BIT(4) )
#define BIT_MASK_GIC_NIRQ_TO_CORE                         ( BIT(3) )
#define BIT_PM_CORE_L1_SRAM_PWRDWN1228                    ( BIT(2) )
#define BIT_PM_CORE_PWRDWN1229                            ( BIT(1) )
#define BIT_PM_CORE_IDLE1230                              ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_CAP_COREx_WAKEUP9 */
#define BIT_WAKEUP_CORE9                                  ( BIT(9) )
#define BIT_WAKEUP_CORE8                                  ( BIT(8) )
#define BIT_WAKEUP_CORE7                                  ( BIT(7) )
#define BIT_WAKEUP_CORE6                                  ( BIT(6) )
#define BIT_WAKEUP_CORE5                                  ( BIT(5) )
#define BIT_WAKEUP_CORE4                                  ( BIT(4) )
#define BIT_WAKEUP_CORE3                                  ( BIT(3) )
#define BIT_WAKEUP_CORE2                                  ( BIT(2) )
#define BIT_WAKEUP_CORE1                                  ( BIT(1) )
#define BIT_WAKEUP_CORE0                                  ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_DVC_DFC_DEBUG */
#define BIT_GLB_INT_MASK_USE_OLD_LOGIC                    ( BIT(5) )
#define BIT_AP_HW_DVC_EN_FOR_FAST_WAKEUP                  ( BIT(4) )
#define BIT_APSUB_DFC_CHECK_MASK                          ( BIT(3) )
#define BIT_APSUB_DVC_CHECK_MASK                          ( BIT(2) )
#define BIT_CP_DVC_CHECK_MASK                             ( BIT(1) )
#define BIT_MP_DVC_CHECK_MASK                             ( BIT(0) )

/* bits definitions for register REG_PMU_PMU_AUDIO_CLK_RES_CTRL */
#define BIT_AUDIO_PWR_STATUS1272                          ( BIT(31) )
#define BIT_USE_SOFT_RST                                  ( BIT(30) )
#define BIT_PM_1274                                       ( BIT(29) )
#define BIT_AP_POWER_CTL_AUDIO_AUTHO                      ( BIT(28) )
#define BIT_AUDIO_HW_MODE                                 ( BIT(27) )
#define BIT_AUDIO_SLEEP2                                  ( BIT(26) )
#define BIT_AUDIO_SLEEP1                                  ( BIT(25) )
#define BIT_AUDIO_ISOB                                    ( BIT(24) )
#define BIT_AUDIO_PWR_STATUS1280                          ( BIT(23) )
#define BIT_LOG_EN                                        ( BIT(19) )
#define BIT_ADSP_EN                                       ( BIT(18) )
#define BIT_AUDIO_FC_REQ                                  ( BIT(15) )
#define BIT_FORCE_AUD_PWR_OFF                             ( BIT(14) )
#define BIT_FORCE_AUD_PWR_ON                              ( BIT(13) )
#define BIT_AUDIO_CLK_EN                                  ( BIT(12) )
#define BIT_CUR_PWR_MST                                   ( BIT(11) )
#define BIT_AUDIO_HW_CKG_BYPASS                           ( BIT(10) )
#define BITS_AUDIO_CLK_SEL(_X_)                           ( (_X_) << 7 & (BIT(7)|BIT(8)|BIT(9)) )
#define BITS_AUDIO_CLK_DIV(_X_)                           ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_AUDIO_APMU_RESET                              ( BIT(3) )
#define BIT_TL421_EXT_CORE_RESET                          ( BIT(2) )
#define BIT_TL421_ORESET                                  ( BIT(1) )
#define BIT_AUDIO_SYS_RESET                               ( BIT(0) )
