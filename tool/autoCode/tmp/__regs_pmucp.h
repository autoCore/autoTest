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


#ifndef __H_REGS_CP_PMU_HEADFILE_H__
#define __H_REGS_CP_PMU_HEADFILE_H__ __FILE__

#define	REGS_CP_PMU

/* registers definitions for CP_PMU */
#define REG_CP_PMU_STIKY_CLR0                             ASR_ADDR(REGS_CP_PMU_BASE, 0X0)/*AIRQ Interrupt Clear 0 Register*/
#define REG_CP_PMU_STIKY_CLR1                             ASR_ADDR(REGS_CP_PMU_BASE, 0X4)/*AIRQ Interrupt Clear 1 Register*/
#define REG_CP_PMU_EDGE_OR_LEVEL0                         ASR_ADDR(REGS_CP_PMU_BASE, 0X08)/*AIRQ Interrupt Sensitivity 0 Register*/
#define REG_CP_PMU_EDGE_OR_LEVEL1                         ASR_ADDR(REGS_CP_PMU_BASE, 0X0C)/*AIRQ Interrupt Sensitivity 1 Register*/
#define REG_CP_PMU_EDGE_OR_LEVEL2                         ASR_ADDR(REGS_CP_PMU_BASE, 0X10)/*AIRQ Interrupt Sensitivity 1 Register*/
#define REG_CP_PMU_STIKY_CLR2                             ASR_ADDR(REGS_CP_PMU_BASE, 0X18)/*AIRQ Interrupt Clear 2 Register*/
#define REG_CP_PMU_DDR_REQ_CTRL_SG                        ASR_ADDR(REGS_CP_PMU_BASE, 0X0020)/*DDR Request Control Register for <var Processor: Comm>*/
#define REG_CP_PMU_SG_SLEEP_CTRL                          ASR_ADDR(REGS_CP_PMU_BASE, 0X0024)/*<var Processor: Comm> Sleep Control Register*/
#define REG_CP_PMU_MSA_RST                                ASR_ADDR(REGS_CP_PMU_BASE, 0X0028)/*MSA Reset Register*/
#define REG_CP_PMU_SG_INT_REG                             ASR_ADDR(REGS_CP_PMU_BASE, 0X002C)/*<var Processor: Comm> interrupt selection register*/
#define REG_CP_PMU_CPSS_HW_GATE_CTRL_SG                   ASR_ADDR(REGS_CP_PMU_BASE, 0X0034)/*CPSS Hardware Clock Gating Control for <var Processor: Comm>*/
#define REG_CP_PMU_AP_status_reg                          ASR_ADDR(REGS_CP_PMU_BASE, 0X0038)/*AP FSM Status Register*/
#define REG_CP_PMU_SG__TIMER                              ASR_ADDR(REGS_CP_PMU_BASE, 0X048)/*<var Processor: Comm>  Timer Register*/
#define REG_CP_PMU_SG_IDLE_CFG                            ASR_ADDR(REGS_CP_PMU_BASE, 0X04C)/*<var Processor: Comm> Idle  Configuration Register*/
#define REG_CP_PMU_AXISD_HW_SG                            ASR_ADDR(REGS_CP_PMU_BASE, 0X070)/*AXISD HW Control Register*/
#define REG_CP_PMU_CP_ACLKDIV_HW_CTRL                     ASR_ADDR(REGS_CP_PMU_BASE, 0X074)/*CPSS Fabric ACLK Clock Divider HW Control*/
#define REG_CP_PMU_DVC_CP                                 ASR_ADDR(REGS_CP_PMU_BASE, 0X080)/*<var Processor: Comm> Dynamic Voltage Change Register*/
#define REG_CP_PMU_DVC_DP                                 ASR_ADDR(REGS_CP_PMU_BASE, 0X084)
#define REG_CP_PMU_DVC_STATUS                             ASR_ADDR(REGS_CP_PMU_BASE, 0X088)/*Dynamic Voltage Change Status Register*/
#define REG_CP_PMU_DFC_CP                                 ASR_ADDR(REGS_CP_PMU_BASE, 0X90)/*<var Processor: Comm> DCLK Dynamic Freq Change Control Register*/
#define REG_CP_PMU_DFC_DP                                 ASR_ADDR(REGS_CP_PMU_BASE, 0X94)/*<var Processor: MSA> DCLK Dynamic Freq Change Control Register*/
#define REG_CP_PMU_DFC_STATUS                             ASR_ADDR(REGS_CP_PMU_BASE, 0X098)/*DCLK Hardware Freq Change Status Register*/
#define REG_CP_PMU__DEBUG                                 ASR_ADDR(REGS_CP_PMU_BASE, 0X09C)/* Debug Register*/
#define REG_CP_PMU_CP_S_GATE_CTRL                         ASR_ADDR(REGS_CP_PMU_BASE, 0X00A0)/*cp source clock gating*/
#define REG_CP_PMU_CR7_INIT_CFG                           ASR_ADDR(REGS_CP_PMU_BASE, 0X00A4)/*CR7 init configuration*/
#define REG_CP_PMU_CSWER                                  ASR_ADDR(REGS_CP_PMU_BASE, 0X00A8)/*Communication Subsystem general purpose wakeup enable*/
#define REG_CP_PMU_CSWCR                                  ASR_ADDR(REGS_CP_PMU_BASE, 0X00AC)/*Communication Subsystem general wakeup global enable*/
#define REG_CP_PMU_SPH_USB_WK                             ASR_ADDR(REGS_CP_PMU_BASE, 0X00B0)/*ICUSB wakeup source control register */
#define REG_CP_PMU_CPSR                                   ASR_ADDR(REGS_CP_PMU_BASE, 0X00BC)/*Marvell <var Processor: Comm> Power Status Register*/
#define REG_CP_PMU_CPRR                                   ASR_ADDR(REGS_CP_PMU_BASE, 0X00C0)/*Marvell <var Processor: Comm> Programmable Reset Register*/
#define REG_CP_PMU_CPCR                                   ASR_ADDR(REGS_CP_PMU_BASE, 0X00C4)/*Marvell <var Processor: Comm> Power Control Register*/
#define REG_CP_PMU_CCGR                                   ASR_ADDR(REGS_CP_PMU_BASE, 0X00C8)/*Marvell <var Processor: Comm> Clock Gating Register*/
#define REG_CP_PMU_CWUCRM                                 ASR_ADDR(REGS_CP_PMU_BASE, 0X00CC)/*Wakeup and Clock Resume Lines Mask Register*/
#define REG_CP_PMU_CWUCRS                                 ASR_ADDR(REGS_CP_PMU_BASE, 0X00D0)/*Wakeup and Clock Resume Lines Status Register*/
#define REG_CP_PMU_CRSR                                   ASR_ADDR(REGS_CP_PMU_BASE, 0X00D4)/*Marvell <var Processor: Comm>/Mohawk Reset Status Register*/
#define REG_CP_PMU_CUCCR                                  ASR_ADDR(REGS_CP_PMU_BASE, 0X00DC)/*CP UART Clock and  reset Control Register*/
#define REG_CP_PMU_DMA_INT_MSK                            ASR_ADDR(REGS_CP_PMU_BASE, 0XE0)/*DMA Interrupt Mask Register*/
#define REG_CP_PMU_DMA_INT_STATUS                         ASR_ADDR(REGS_CP_PMU_BASE, 0XE4)/*DMA Interrupt Status Register*/
#define REG_CP_PMU_DMA_XTC_CTRL                           ASR_ADDR(REGS_CP_PMU_BASE, 0XE8)/*DMA WTC RTC Control Register*/
#define REG_CP_PMU_DYN_CLK_GATE_CTRL                      ASR_ADDR(REGS_CP_PMU_BASE, 0XF0)/*Dynamic Clock Gating Control*/
#define REG_CP_PMU_FABRIC_QoS_CTRL                        ASR_ADDR(REGS_CP_PMU_BASE, 0XF4)/*Fabric QoS  Control*/
#define REG_CP_PMU_DDR_REQ_CTRL_GB                        ASR_ADDR(REGS_CP_PMU_BASE, 0X0100)/*DDR Request Control Register for GB*/
#define REG_CP_PMU_AXISD_HW_GB                            ASR_ADDR(REGS_CP_PMU_BASE, 0X104)/*AXISD HW Control Register*/
#define REG_CP_PMU_CP_Timer_CTRL                          ASR_ADDR(REGS_CP_PMU_BASE, 0X00124)/*CP Timer Control Register*/
#define REG_CP_PMU_CP_I2SCCRx                             ASR_ADDR(REGS_CP_PMU_BASE, 0X0128)/*CP I2S Clock Generation Control Register*/



/* bits definitions for register REG_CP_PMU_STIKY_CLR0 */
#define BITS_CP_PM_AIRQ_INT_CLR_013(_X_)                  (_X_)

/* bits definitions for register REG_CP_PMU_STIKY_CLR1 */
#define BITS_CP_PM_AIRQ_INT_CLR_121(_X_)                  (_X_)

/* bits definitions for register REG_CP_PMU_EDGE_OR_LEVEL0 */
#define BITS_CP_PM_AIRQ_EDGE_LEVEL_029(_X_)               (_X_)

/* bits definitions for register REG_CP_PMU_EDGE_OR_LEVEL1 */
#define BITS_CP_PM_AIRQ_EDGE_LEVEL_137(_X_)               (_X_)

/* bits definitions for register REG_CP_PMU_EDGE_OR_LEVEL2 */
#define BITS_AIRQ_EDGE_LEVEL_2(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_CP_PMU_STIKY_CLR2 */
#define BITS_AIRQ_INT_CLR_2(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_CP_PMU_DDR_REQ_CTRL_SG */
#define BIT_DDRC_RDY_EN61                                 ( BIT(31) )
#define BITS_CP_PM_62(_X_)                                ( (_X_) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_FBDMA_DDRC_REQ_EN63                           ( BIT(20) )
#define BIT_DTC_DDRC_REQ_EN64                             ( BIT(19) )
#define BIT_CPDMA_DDRC_REQ_EN65                           ( BIT(18) )
#define BIT_MSA_DDRC_REQ_EN66                             ( BIT(17) )
#define BIT_SG_DDRC_REQ_EN67                              ( BIT(16) )
#define BIT_GSM_DDRC_REQ_EN68                             ( BIT(15) )
#define BIT_CP_PM_69                                      ( BIT(14) )
#define BIT_FB_MODEM_DDRC_REQ_EN70                        ( BIT(13) )
#define BIT_PWR_MODE_DDRC_REQ_EN71                        ( BIT(12) )
#define BITS_CP_PM_72(_X_)                                ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DTCMSD73                                      ( BIT(3) )
#define BITS_CP_PM_74(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_CP_PMU_SG_SLEEP_CTRL */
#define BIT_WAKEUP_GLOBAL_MASK                            ( BIT(31) )
#define BIT_WAKEUP_GLOBAL_MASK2                           ( BIT(30) )
#define BITS_CP_PM_84(_X_)                                ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BITS_CP_PM_85(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_CP_PMU_MSA_RST */
#define BIT_MSA_IDLE                                      ( BIT(31) )
#define BITS_MSA_LPM_VOTE(_X_)                            ( (_X_) << 29 & (BIT(29)|BIT(30)) )
#define BIT_FB_DMA_BUSY                                   ( BIT(28) )
#define BIT_MSA_RST_STATUS                                ( BIT(3) )
#define BIT_MSA_SILENT_RST_MODE                           ( BIT(2) )
#define BIT_MSA_SW_RST                                    ( BIT(1) )
#define BIT_MSA_RST_HOLD                                  ( BIT(0) )

/* bits definitions for register REG_CP_PMU_SG_INT_REG */
#define BITS_CP_PM_106(_X_)                               ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CP_PM_107                                     ( BIT(1) )
#define BIT_CP_PM_108                                     ( BIT(0) )

/* bits definitions for register REG_CP_PMU_CPSS_HW_GATE_CTRL_SG */
#define BITS_CP_PM_116(_X_)                               ( (_X_) << 23 & (BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CP_PM_117                                     ( BIT(22) )
#define BIT_CP_PM_118                                     ( BIT(21) )
#define BIT_CP_PM_119                                     ( BIT(20) )
#define BIT_CP_PM_120                                     ( BIT(19) )
#define BIT_CP_PM_121                                     ( BIT(18) )
#define BIT_CP_PM_122                                     ( BIT(17) )
#define BIT_CP_PM_123                                     ( BIT(16) )
#define BIT_CP_PM_124                                     ( BIT(15) )
#define BIT_CP_PM_125                                     ( BIT(14) )
#define BIT_CP_PM_126                                     ( BIT(13) )
#define BIT_CP_PM_127                                     ( BIT(12) )
#define BIT_CP_PM_128                                     ( BIT(11) )
#define BIT_CP_PM_129                                     ( BIT(10) )
#define BIT_CP_PM_130                                     ( BIT(9) )
#define BIT_CP_PM_131                                     ( BIT(8) )
#define BIT_CP_PM_132                                     ( BIT(7) )
#define BIT_CP_PM_133                                     ( BIT(6) )
#define BIT_CP_PM_134                                     ( BIT(5) )
#define BIT_CP_PM_135                                     ( BIT(4) )
#define BIT_CP_PM_136                                     ( BIT(3) )
#define BIT_CP_PM_137                                     ( BIT(2) )
#define BIT_CP_PM_138                                     ( BIT(1) )
#define BIT_CP_PM_139                                     ( BIT(0) )

/* bits definitions for register REG_CP_PMU_AP_status_reg */
#define BIT_CP_PM_146                                     ( BIT(31) )
#define BITS_CP_PM_147(_X_)                               ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BITS_CP_PM_148(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_CP_PMU_SG__TIMER */
#define BITS_CP_PM_PWR_CLK_PRE156(_X_)                    ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_CP_PM_PWR_UP_STBL_TIMER157(_X_)              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_CP_PM_PWR_DWN_STBL_TIMER158(_X_)             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_CP_PMU_SG_IDLE_CFG */
#define BITS_CP_PM_PSW_MODE166(_X_)                       ( (_X_) << 20 & (BIT(20)|BIT(21)) )
#define BIT_DIS_CORE_L2_SLP                               ( BIT(19) )
#define BIT_CP_PM_DIS_CORE_L1_SLP168                      ( BIT(18) )
#define BIT_CP_PM_DIS_CORE_SLP169                         ( BIT(17) )
#define BIT_CP_PM_MASK_CLK_OFF_CHECK171                   ( BIT(11) )
#define BIT_CP_PM_MASK_CLK_STBL_CHECK172                  ( BIT(10) )
#define BIT_CP_PM_MASK_JTAG_IDLE_CHECK173                 ( BIT(9) )
#define BIT_CP_PM_MASK_CORE_WFI_IDLE_CHECK174             ( BIT(8) )
#define BIT_CP_PM_DIS_MC_SW_REQ176                        ( BIT(5) )
#define BIT_CP_PM_SEA_MC_WAKE_EN177                       ( BIT(4) )
#define BIT_CORE_L2_SRAM_PWRDWN                           ( BIT(3) )
#define BIT_CP_PM_CORE_L1_SRAM_PWRDWN179                  ( BIT(2) )
#define BIT_CP_PM_CORE_PWRDWN180                          ( BIT(1) )
#define BIT_CP_PM_CORE_IDLE181                            ( BIT(0) )

/* bits definitions for register REG_CP_PMU_AXISD_HW_SG */
#define BITS_CP_PM_279(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_SG_AXISD_CTRL280                              ( BIT(7) )
#define BIT_MSA_AXISD_CTRL281                             ( BIT(6) )
#define BIT_CP_DMAC_AXISD_CTRL282                         ( BIT(5) )
#define BIT_DTC_AXISD_CTRL283                             ( BIT(4) )
#define BIT_PWR_MODE_AXISD_CTRL284                        ( BIT(3) )
#define BIT_FB_DMAC_AXISD_CTRL285                         ( BIT(2) )
#define BIT_FB_AXISD_CTRL286                              ( BIT(1) )
#define BIT_GSM_AXISD_CTRL287                             ( BIT(0) )

/* bits definitions for register REG_CP_PMU_CP_ACLKDIV_HW_CTRL */
#define BITS_CP_PM_294(_X_)                               ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_SW_ACLKDIV_DIS_VOTE                           ( BIT(3) )
#define BIT_CPDMA_ACLKDIV_DIS_VOTE                        ( BIT(2) )
#define BIT_MSA_ACLKDIV_DIS_VOTE                          ( BIT(1) )
#define BIT_SG_ACLKDIV_DIS_VOTE                           ( BIT(0) )

/* bits definitions for register REG_CP_PMU_DVC_CP */
#define BIT_VC_INT305                                     ( BIT(31) )
#define BIT_VC_INT_EN306                                  ( BIT(30) )
#define BIT_VC_INT_CLR307                                 ( BIT(29) )
#define BIT_LPM_D2_AVC_EN                                 ( BIT(23) )
#define BITS_LPM_D2_VL3:0(_X_)                            ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_VC_REQ312                                     ( BIT(15) )
#define BITS_VL3:0314(_X_)                                ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_LPM_C2_AVC_EN                                 ( BIT(7) )
#define BITS_LPM_C2_VL3:0(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CP_PMU_DVC_DP */
#define BIT_VC_INT323                                     ( BIT(31) )
#define BIT_VC_INT_EN324                                  ( BIT(30) )
#define BIT_VC_INT_CLR325                                 ( BIT(29) )
#define BIT_VC_REQ327                                     ( BIT(15) )
#define BITS_VL3:0329(_X_)                                ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_CP_PM_LPM_AVC_EN330                           ( BIT(7) )
#define BITS_CP_PM_LPM_VL3:0332(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CP_PMU_DVC_STATUS */
#define BITS_CP_PM_CAUSE340(_X_)                          ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_CP_PM_TVL3:0342(_X_)                         ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_CP_PM_CVL3:0344(_X_)                         ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_CP_PM_DVC_STATUS346                           ( BIT(0) )

/* bits definitions for register REG_CP_PMU_DFC_CP */
#define BIT_DFC_INT353                                    ( BIT(31) )
#define BIT_DFC_INT_EN354                                 ( BIT(30) )
#define BIT_DFC_INT_CLR355                                ( BIT(29) )
#define BIT_DCLK_FC_VOTE357                               ( BIT(15) )
#define BITS_LPM_D2_FL(_X_)                               ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BITS_LPM_C2_FL(_X_)                               ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_LPM_C2_DFC_EN                                 ( BIT(8) )
#define BIT_LPM_D2_DFC_EN                                 ( BIT(7) )
#define BITS_CP_PM_FL363(_X_)                             ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)) )
#define BIT_CP_PM_DFC_REQ364                              ( BIT(0) )

/* bits definitions for register REG_CP_PMU_DFC_DP */
#define BIT_DFC_INT371                                    ( BIT(31) )
#define BIT_DFC_INT_EN372                                 ( BIT(30) )
#define BIT_DFC_INT_CLR373                                ( BIT(29) )
#define BIT_DCLK_FC_VOTE375                               ( BIT(15) )
#define BITS_LPM_FL(_X_)                                  ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_LPM_DFC_EN                                    ( BIT(8) )
#define BITS_CP_PM_FL380(_X_)                             ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)) )
#define BIT_CP_PM_DFC_REQ381                              ( BIT(0) )

/* bits definitions for register REG_CP_PMU_DFC_STATUS */
#define BITS_CP_PM_DFC_CAUSE389(_X_)                      ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)) )
#define BITS_CP_PM_TFL390(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_CP_PM_CFL391(_X_)                            ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_CP_PM_DFC_STATUS392                           ( BIT(0) )

/* bits definitions for register REG_CP_PMU__DEBUG */
#define BIT_MASK_DVC_CHECK                                ( BIT(1) )
#define BIT_MASK_SG_IDLE_CHECK                            ( BIT(0) )

/* bits definitions for register REG_CP_PMU_CP_S_GATE_CTRL */
#define BITS_CP_PM_408(_X_)                               ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CP_PM_409                                     ( BIT(4) )
#define BIT_CP_PM_410                                     ( BIT(3) )
#define BIT_CP_PM_411                                     ( BIT(2) )
#define BIT_CP_PM_412                                     ( BIT(1) )
#define BIT_CP_PM_413                                     ( BIT(0) )

/* bits definitions for register REG_CP_PMU_CR7_INIT_CFG */
#define BITS_CP_PM_420(_X_)                               ( (_X_) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CPUCLKOFF_MASK                                ( BIT(21) )
#define BIT_DBGCLKOFF_MASK                                ( BIT(20) )
#define BIT_CP_PM_CFGEND423                               ( BIT(19) )
#define BIT_CP_PM_CFGEND424                               ( BIT(18) )
#define BIT_CP_PM_VINITHI425                              ( BIT(17) )
#define BIT_INITRAM0                                      ( BIT(16) )
#define BIT_CP_PM_TEINIT427                               ( BIT(15) )
#define BIT_CP_PM_DBGEN428                                ( BIT(14) )
#define BIT_CP_PM_NIDEN429                                ( BIT(13) )
#define BIT_L2C_S1_CLKEN                                  ( BIT(12) )
#define BIT_CP_PM_SPNIDEN431                              ( BIT(11) )
#define BITS_CP_PM_432(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for register REG_CP_PMU_CSWER */
#define BIT_CP_PM_441                                     ( BIT(15) )
#define BIT_CP_PM_442                                     ( BIT(14) )
#define BIT_CP_PM_443                                     ( BIT(13) )
#define BIT_CP_PM_444                                     ( BIT(12) )
#define BIT_CP_PM_445                                     ( BIT(11) )
#define BIT_CP_PM_446                                     ( BIT(10) )
#define BIT_CP_PM_448                                     ( BIT(8) )
#define BIT_CP_PM_449                                     ( BIT(7) )
#define BIT_CP_PM_450                                     ( BIT(6) )
#define BIT_CP_PM_451                                     ( BIT(5) )
#define BIT_CP_PM_452                                     ( BIT(4) )
#define BIT_CP_PM_454                                     ( BIT(0) )

/* bits definitions for register REG_CP_PMU_CSWCR */
#define BIT_RESET_WAKEUP_EVENT                            ( BIT(31) )
#define BIT_CWESR_WAKE_EN                                 ( BIT(30) )
#define BIT_D2_EXIT_STICKY_CLR                            ( BIT(29) )
#define BIT_D2_EXIT_STICKY                                ( BIT(28) )
#define BIT_CAPTURED_UWU                                  ( BIT(20) )
#define BIT_CP_PM_469                                     ( BIT(15) )
#define BIT_C_TIMER_3_IRQ                                 ( BIT(14) )
#define BIT_C_TIMER_2_IRQ                                 ( BIT(13) )
#define BIT_CP_PM_472                                     ( BIT(12) )
#define BIT_M1_GPIO_INT_CP                                ( BIT(11) )
#define BIT_SPH_USB_WAKEUP                                ( BIT(10) )
#define BIT_IPC1_S2A_INT_0                                ( BIT(9) )
#define BIT_AIRQ                                          ( BIT(8) )
#define BIT_IPC0_S2A_INT_0                                ( BIT(7) )
#define BIT_C_TIMER_1_IRQ                                 ( BIT(6) )
#define BIT_M1_WUCR_PMIC_WAKEUP_INT                       ( BIT(5) )
#define BIT_M1_WDT_IRQ                                    ( BIT(4) )
#define BIT_M1_CRXD_WAKEUP_INT                            ( BIT(3) )
#define BIT_M1_GSSP1_WAKEUP                               ( BIT(2) )
#define BIT_M1_I2C_WAKEUP_INT                             ( BIT(1) )
#define BIT_M1_CGPIO_WAKEUP_MASK_OR                       ( BIT(0) )

/* bits definitions for register REG_CP_PMU_SPH_USB_WK */
#define BIT_SPH_DM_WK_CLR                                 ( BIT(3) )
#define BIT_SPH_DP_WK_CLR                                 ( BIT(2) )
#define BIT_SPH_DM_WK_EN                                  ( BIT(1) )
#define BIT_SPH_DP_WK_EN                                  ( BIT(0) )

/* bits definitions for register REG_CP_PMU_CPSR */
#define BIT_CP_PM_DSPIDL504                               ( BIT(31) )
#define BIT_CP_PM_DSPAVL506                               ( BIT(28) )
#define BIT_CP_PM_COMM_TOP_D2508                          ( BIT(24) )
#define BIT_SG_WFI_FLAG                                   ( BIT(5) )
#define BIT_CP_PM_SG_IDLE511                              ( BIT(4) )
#define BITS_CP_PM_COMM_TOP_STATE512(_X_)                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CP_PMU_CPRR */
#define BIT_CP_PM_SLAVE_R521                              ( BIT(6) )
#define BIT_CP_PM_DSRAMINT522                             ( BIT(5) )
#define BIT_WDTR523                                       ( BIT(4) )
#define BIT_CP_PM_BBR524                                  ( BIT(3) )
#define BIT_CP_PM_DSPR525                                 ( BIT(2) )
#define BIT_CP_PM_APR526                                  ( BIT(1) )
#define BIT_CP_PM_CPR527                                  ( BIT(0) )

/* bits definitions for register REG_CP_PMU_CPCR */
#define BIT_CP_PM_AXISDD535                               ( BIT(31) )
#define BIT_CP_PM_DSPSD536                                ( BIT(30) )
#define BIT_CP_PM_SLPEN537                                ( BIT(29) )
#define BIT_DTCMSD538                                     ( BIT(28) )
#define BIT_CP_PM_DDRCORSD539                             ( BIT(27) )
#define BIT_CP_PM_APBSD540                                ( BIT(26) )
#define BIT_CP_PM_BBSD541                                 ( BIT(25) )
#define BIT_CP_PM_INTCLR542                               ( BIT(24) )
#define BIT_CP_PM_SLPWP0543                               ( BIT(23) )
#define BIT_CP_PM_SLPWP1544                               ( BIT(22) )
#define BIT_CP_PM_SLPWP2545                               ( BIT(21) )
#define BIT_CP_PM_SLPWP3546                               ( BIT(20) )
#define BIT_CP_PM_VCTCXOSD547                             ( BIT(19) )
#define BIT_CP_PM_SLPWP4548                               ( BIT(18) )
#define BIT_CP_PM_SLPWP5549                               ( BIT(17) )
#define BIT_CP_PM_SLPWP6550                               ( BIT(16) )
#define BIT_CP_PM_SLPWP7551                               ( BIT(15) )
#define BIT_CP_PM_MSASLPEN552                             ( BIT(14) )
#define BIT_CP_PM_STBYEN553                               ( BIT(13) )
#define BIT_CP_VOTE_AP_SLPEN                              ( BIT(3) )

/* bits definitions for register REG_CP_PMU_CCGR */
#define BIT_CP_PM_WDT_13M565                              ( BIT(19) )
#define BIT_CP_PM_CLK_1248M567                            ( BIT(16) )
#define BIT_CP_PM_CLK_624M568                             ( BIT(15) )
#define BIT_CP_PM_CLK_832M569                             ( BIT(14) )
#define BIT_CP_PM_CLK_312M570                             ( BIT(13) )
#define BIT_CP_PM_CLK_104M571                             ( BIT(12) )
#define BIT_CLK_52M572                                    ( BIT(11) )
#define BIT_CP_PM_CLK_48M573                              ( BIT(10) )
#define BIT_CP_PM_GPC574                                  ( BIT(9) )
#define BIT_CP_PM_AP_FUART575                             ( BIT(8) )
#define BIT_CLK_52M576                                    ( BIT(7) )
#define BIT_CP_PM_AP_TWSI577                              ( BIT(6) )
#define BIT_CP_PM_CLK_208M578                             ( BIT(5) )
#define BIT_CP_PM_CLK_26M579                              ( BIT(4) )
#define BIT_CP_PM_CLK_13M580                              ( BIT(3) )
#define BIT_CP_PM_CLK_6.5M581                             ( BIT(2) )
#define BIT_CP_PM_AP_SUART582                             ( BIT(1) )
#define BIT_CP_PM_CLK_416M583                             ( BIT(0) )

/* bits definitions for register REG_CP_PMU_CWUCRM */
#define BIT_CP_PM_AUDIO_WAKEUP590                         ( BIT(31) )
#define BIT_CP_PM_AP_GT_WAKEUP591                         ( BIT(30) )
#define BIT_CP_PM_GSM_WAKEUPWMX592                        ( BIT(29) )
#define BIT_CP_PM_FB_WAKEUPX593                           ( BIT(28) )
#define BIT_CP_PM_GSM_WAKEUPWM594                         ( BIT(27) )
#define BIT_CP_PM_FB_WAKEUPWM595                          ( BIT(26) )
#define BIT_AP_ASYNC_INT596                               ( BIT(25) )
#define BIT_AP_FULL_IDLE597                               ( BIT(24) )
#define BIT_SDH1_AUDIO598                                 ( BIT(23) )
#define BIT_SDH2599                                       ( BIT(22) )
#define BIT_KEYPRESS600                                   ( BIT(21) )
#define BIT_TRACKBALL601                                  ( BIT(20) )
#define BIT_NEWROTARY602                                  ( BIT(19) )
#define BIT_WDT603                                        ( BIT(18) )
#define BIT_RTC_ALARM604                                  ( BIT(17) )
#define BIT_CP_TIMER_3605                                 ( BIT(16) )
#define BIT_CP_TIMER_2606                                 ( BIT(15) )
#define BIT_CP_TIMER_1607                                 ( BIT(14) )
#define BIT_AP1_TIMER_3608                                ( BIT(13) )
#define BIT_AP1_TIMER_2609                                ( BIT(12) )
#define BIT_AP1_TIMER_1610                                ( BIT(11) )
#define BIT_AP0_2_TIMER_3611                              ( BIT(10) )
#define BIT_AP0_2_TIMER_2612                              ( BIT(9) )
#define BIT_AP0_2_TIMER_1613                              ( BIT(8) )
#define BIT_WAKEUP7614                                    ( BIT(7) )
#define BIT_WAKEUP6615                                    ( BIT(6) )
#define BIT_WAKEUP5616                                    ( BIT(5) )
#define BIT_WAKEUP4617                                    ( BIT(4) )
#define BIT_WAKEUP3618                                    ( BIT(3) )
#define BIT_WAKEUP2619                                    ( BIT(2) )
#define BIT_WAKEUP1620                                    ( BIT(1) )
#define BIT_WAKEUP0621                                    ( BIT(0) )

/* bits definitions for register REG_CP_PMU_CWUCRS */
#define BIT_CP_PM_BB_DROWSY_EN628                         ( BIT(31) )
#define BIT_CP_PM_BB_VCTCXO_REQ629                        ( BIT(30) )
#define BIT_CP_PM_MSA_WAKE_PM_BB_CLKRES630                ( BIT(29) )
#define BIT_CP_PM_PM_CLKRES631                            ( BIT(28) )
#define BIT_CP_PM_GSM_WAKEUP632                           ( BIT(27) )
#define BIT_CP_PM_FB_WAKEUP633                            ( BIT(26) )
#define BIT_AP_ASYNC_INT634                               ( BIT(25) )
#define BIT_AP_FULL_IDLE635                               ( BIT(24) )
#define BIT_SDH1_AUDIO636                                 ( BIT(23) )
#define BIT_SDH2637                                       ( BIT(22) )
#define BIT_KEYPRESS638                                   ( BIT(21) )
#define BIT_TRACKBALL639                                  ( BIT(20) )
#define BIT_NEWROTARY640                                  ( BIT(19) )
#define BIT_WDT641                                        ( BIT(18) )
#define BIT_RTC_ALARM642                                  ( BIT(17) )
#define BIT_CP_TIMER_3643                                 ( BIT(16) )
#define BIT_CP_TIMER_2644                                 ( BIT(15) )
#define BIT_CP_TIMER_1645                                 ( BIT(14) )
#define BIT_AP1_TIMER_3646                                ( BIT(13) )
#define BIT_AP1_TIMER_2647                                ( BIT(12) )
#define BIT_AP1_TIMER_1648                                ( BIT(11) )
#define BIT_AP0_2_TIMER_3649                              ( BIT(10) )
#define BIT_AP0_2_TIMER_2650                              ( BIT(9) )
#define BIT_AP0_2_TIMER_1651                              ( BIT(8) )
#define BIT_WAKEUP7652                                    ( BIT(8) )
#define BIT_WAKEUP6653                                    ( BIT(6) )
#define BIT_WAKEUP5654                                    ( BIT(5) )
#define BIT_WAKEUP4655                                    ( BIT(4) )
#define BIT_WAKEUP3656                                    ( BIT(3) )
#define BIT_WAKEUP2657                                    ( BIT(2) )
#define BIT_WAKEUP1658                                    ( BIT(1) )
#define BIT_WAKEUP0659                                    ( BIT(0) )

/* bits definitions for register REG_CP_PMU_CRSR */
#define BITS_CP_PM_SWR668(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_WDTR670                                       ( BIT(2) )
#define BIT_CP_PM_EMR671                                  ( BIT(1) )
#define BIT_CP_PM_POR672                                  ( BIT(0) )

/* bits definitions for register REG_CP_PMU_CUCCR */
#define BITS_CP_PM_RESERVED679(_X_)                       ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CP_UART_RESET_EN                              ( BIT(5) )
#define BIT_CP_UART_APB_EN                                ( BIT(4) )
#define BIT_CP_UART_FCLK_EN                               ( BIT(3) )
#define BITS_CP_UART_CLK_SEL(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_CP_PMU_DMA_INT_MSK */
#define BITS_DMA_INT_MSK(_X_)                             (_X_)

/* bits definitions for register REG_CP_PMU_DMA_INT_STATUS */
#define BITS_CP_DMA_INT_STATUS(_X_)                       (_X_)

/* bits definitions for register REG_CP_PMU_DMA_XTC_CTRL */
#define BITS_CP_DMA_WTCB(_X_)                             ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_CP_DMA_RTCB(_X_)                             ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_CP_DMA_WTC(_X_)                              ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_CP_DMA_RTC(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CP_PMU_DYN_CLK_GATE_CTRL */
#define BIT_DTC_DYN_CG_EN                                 ( BIT(16) )
#define BIT_CR5FAB_DYN_CG_EN                              ( BIT(5) )
#define BIT_FBFAB_DYN_CG_EN                               ( BIT(4) )
#define BIT_GBDEC_DYN_CG_EN                               ( BIT(3) )
#define BIT_GBPRT_DYN_CG_EN                               ( BIT(2) )
#define BIT_CR5PRT_DYN_CG_EN                              ( BIT(1) )
#define BIT_CPFAB_DYN_CG_EN                               ( BIT(0) )

/* bits definitions for register REG_CP_PMU_FABRIC_QoS_CTRL */
#define BITS_DTC_MST_AR_QOS(_X_)                          ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_DTC_MST_AW_QOS(_X_)                          ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_CR5_MST_AR_QOS(_X_)                          ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_CR5_MST_AW_QOS(_X_)                          ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_GB_MST_AR_QOS(_X_)                           ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_GB_MST_AW_QOS(_X_)                           ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_FB_MST_AR_QOS(_X_)                           ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_FB_MST_AW_QOS(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_CP_PMU_DDR_REQ_CTRL_GB */
#define BITS_CP_PM_745(_X_)                               ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DDRC_RDY_EN746                                ( BIT(31) )
#define BITS_CP_PM_747(_X_)                               ( (_X_) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_FBDMA_DDRC_REQ_EN748                          ( BIT(20) )
#define BIT_DTC_DDRC_REQ_EN749                            ( BIT(19) )
#define BIT_CPDMA_DDRC_REQ_EN750                          ( BIT(18) )
#define BIT_MSA_DDRC_REQ_EN751                            ( BIT(17) )
#define BIT_SG_DDRC_REQ_EN752                             ( BIT(16) )
#define BIT_GSM_DDRC_REQ_EN753                            ( BIT(15) )
#define BIT_CP_PM_754                                     ( BIT(14) )
#define BIT_FB_MODEM_DDRC_REQ_EN755                       ( BIT(13) )
#define BIT_PWR_MODE_DDRC_REQ_EN756                       ( BIT(12) )
#define BITS_CP_PM_757(_X_)                               ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DTCMSD758                                     ( BIT(3) )
#define BITS_CP_PM_759(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_CP_PMU_AXISD_HW_GB */
#define BITS_CP_PM_766(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_SG_AXISD_CTRL767                              ( BIT(7) )
#define BIT_MSA_AXISD_CTRL768                             ( BIT(6) )
#define BIT_CP_DMAC_AXISD_CTRL769                         ( BIT(5) )
#define BIT_DTC_AXISD_CTRL770                             ( BIT(4) )
#define BIT_PWR_MODE_AXISD_CTRL771                        ( BIT(3) )
#define BIT_FB_DMAC_AXISD_CTRL772                         ( BIT(2) )
#define BIT_FB_AXISD_CTRL773                              ( BIT(1) )
#define BIT_GSM_AXISD_CTRL774                             ( BIT(0) )

/* bits definitions for register REG_CP_PMU_CP_Timer_CTRL */
#define BITS_CP_PM_819(_X_)                               ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CP_TIMER_RESET_EN                             ( BIT(5) )
#define BIT_CP_TIMER_APB_CLKEN                            ( BIT(4) )
#define BIT_CP_TIMER_FUNC_CLKEN                           ( BIT(3) )
#define BITS_CP_TIMER_FAST_CLK_SEL(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_CP_PMU_CP_I2SCCRx */
#define BIT_CP_PM_SYSCLK_EN830                            ( BIT(31) )
#define BIT_CP_PM_SYSCLK_BASE831                          ( BIT(30) )
#define BIT_CP_PM_BITCLK_EN832                            ( BIT(29) )
#define BITS_CP_PM_BITCLK_DIV_468833(_X_)                 ( (_X_) << 27 & (BIT(27)|BIT(28)) )
#define BITS_CP_PM_DENOM834(_X_)                          ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )
#define BITS_CP_PM_NOM835(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

#endif
