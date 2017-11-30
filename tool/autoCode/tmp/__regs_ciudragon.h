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


#ifndef __H_REGS_DCIU_HEADFILE_H__
#define __H_REGS_DCIU_HEADFILE_H__ __FILE__

#define	REGS_DCIU

/* registers definitions for DCIU */
#define REG_DCIU_CLUSTER0_CPUx_CFG0                       ASR_ADDR(REGS_DCIU_BASE, 0x0)/*Cluster 0 Core x Config Registers*/
#define REG_DCIU_CLUSTER0_CPUx_CFG1                       ASR_ADDR(REGS_DCIU_BASE, 0x4)/*Cluster 0 Core x Config Registers*/
#define REG_DCIU_CLUSTER0_CPUx_CFG2                       ASR_ADDR(REGS_DCIU_BASE, 0x8)/*Cluster 0 Core x Config Registers*/
#define REG_DCIU_CLUSTER0_CPUx_CFG3                       ASR_ADDR(REGS_DCIU_BASE, 0xC)/*Cluster 0 Core x Config Registers*/
#define REG_DCIU_CLUSTERx_CTRL0                           ASR_ADDR(REGS_DCIU_BASE, 0x10)/*Cluster x Control Registers*/
#define REG_DCIU_CLUSTERx_CTRL1                           ASR_ADDR(REGS_DCIU_BASE, 0x50)/*Cluster x Control Registers*/
#define REG_DCIU_CLUSTERx_CTRL2                           ASR_ADDR(REGS_DCIU_BASE, 0xD8)/*Cluster x Control Registers*/
#define REG_DCIU_CLUSTERx_CPU_SRAM_CTRL0                  ASR_ADDR(REGS_DCIU_BASE, 0x14)/*Cluster x CPU SRAM Control Registers*/
#define REG_DCIU_CLUSTERx_CPU_SRAM_CTRL1                  ASR_ADDR(REGS_DCIU_BASE, 0x54)/*Cluster x CPU SRAM Control Registers*/
#define REG_DCIU_CLUSTERx_CPU_SRAM_CTRL2                  ASR_ADDR(REGS_DCIU_BASE, 0xDC)/*Cluster x CPU SRAM Control Registers*/
#define REG_DCIU_CLUSTERx_MP_SRAM_CTRL0                   ASR_ADDR(REGS_DCIU_BASE, 0x18)/*Cluster x MP SRAM Control Registers*/
#define REG_DCIU_CLUSTERx_MP_SRAM_CTRL1                   ASR_ADDR(REGS_DCIU_BASE, 0x58)/*Cluster x MP SRAM Control Registers*/
#define REG_DCIU_CLUSTERx_MP_SRAM_CTRL2                   ASR_ADDR(REGS_DCIU_BASE, 0xE0)/*Cluster x MP SRAM Control Registers*/
#define REG_DCIU_CLUSTERx_STATUS0                         ASR_ADDR(REGS_DCIU_BASE, 0x30)/*Cluster x Status Register*/
#define REG_DCIU_CLUSTERx_STATUS1                         ASR_ADDR(REGS_DCIU_BASE, 0x70)/*Cluster x Status Register*/
#define REG_DCIU_CLUSTERx_STATUS2                         ASR_ADDR(REGS_DCIU_BASE, 0xE4)/*Cluster x Status Register*/
#define REG_DCIU_CLUSTER1_CPUx_CFG0                       ASR_ADDR(REGS_DCIU_BASE, 0x40)/*Cluster 1 Core x Config Register*/
#define REG_DCIU_CLUSTER1_CPUx_CFG1                       ASR_ADDR(REGS_DCIU_BASE, 0x44)/*Cluster 1 Core x Config Register*/
#define REG_DCIU_CLUSTER1_CPUx_CFG2                       ASR_ADDR(REGS_DCIU_BASE, 0x48)/*Cluster 1 Core x Config Register*/
#define REG_DCIU_CLUSTER1_CPUx_CFG3                       ASR_ADDR(REGS_DCIU_BASE, 0x4C)/*Cluster 1 Core x Config Register*/
#define REG_DCIU_CS_SRAM_CTRL                             ASR_ADDR(REGS_DCIU_BASE, 0X80)/*CoreSight SRAM Control Register*/
#define REG_DCIU_GIC_CTRL                                 ASR_ADDR(REGS_DCIU_BASE, 0X84)/*GIC Control Register*/
#define REG_DCIU_CKG_CTRL                                 ASR_ADDR(REGS_DCIU_BASE, 0X88)/*Clock Gate Control Register*/
#define REG_DCIU_CPU_GIC_CTRL                             ASR_ADDR(REGS_DCIU_BASE, 0X8C)/*CPU GIC Control Register*/
#define REG_DCIU_CCI_DBG_CTRL                             ASR_ADDR(REGS_DCIU_BASE, 0X90)/*CCI Debug Control Register*/
#define REG_DCIU_PW_STR_CTRL                              ASR_ADDR(REGS_DCIU_BASE, 0X94)/*Pulse Latch Width Control register*/
#define REG_DCIU_CCI_INF_QOS_CTRL                         ASR_ADDR(REGS_DCIU_BASE, 0X98)/*CCI Interface QoS control*/
#define REG_DCIU_CLUSTER2_CPUx_CFG0                       ASR_ADDR(REGS_DCIU_BASE, 0xC8)/*Cluster 2 Core x Config Register*/
#define REG_DCIU_CLUSTER2_CPUx_CFG1                       ASR_ADDR(REGS_DCIU_BASE, 0xCC)/*Cluster 2 Core x Config Register*/
#define REG_DCIU_CPU_L2_LIGHT_SLEEP_CTRL                  ASR_ADDR(REGS_DCIU_BASE, 0XE8)/*CPU L2 LIGHT SLEEP CONTROL Register*/
#define REG_DCIU_CPU_ACLKM0_ACLKM1_CTRL                   ASR_ADDR(REGS_DCIU_BASE, 0XEC)/*CPU ACLKM0_ACLKM1 Control Register*/
#define REG_DCIU_CLUSTER0_ROM_READ_ADDR_REMAP             ASR_ADDR(REGS_DCIU_BASE, 0X104)/*Cluster 0 ROM READ ADDR REMAP Register*/
#define REG_DCIU_CCI_M1_CTRL                              ASR_ADDR(REGS_DCIU_BASE, 0XF0)/*CCI_m1 Monitor Ctrl Register  */
#define REG_DCIU_CCI_M1_X                                 ASR_ADDR(REGS_DCIU_BASE, 0XF4)/*CCI_m1 Monitor Threshold X Register*/
#define REG_DCIU_CCI_M1_Y                                 ASR_ADDR(REGS_DCIU_BASE, 0XF8)/*CCI_m1 Monitor Threshold Y Register*/
#define REG_DCIU_CCI_M1_DATA                              ASR_ADDR(REGS_DCIU_BASE, 0XFC)/*CCI_m1 Monitor Read Data Register  */



/* bits definitions for register REG_DCIU_CLUSTER0_CPUx_CFG3 */
#define BIT_CRYPTODISABLE13                               ( BIT(29) )
#define BIT_CFGEND15                                      ( BIT(27) )
#define BIT_CFGTE17                                       ( BIT(25) )
#define BIT_CP15SDISABLE19                                ( BIT(18) )

/* bits definitions for register REG_DCIU_CLUSTERx_CTRL2 */
#define BITS_EVENTO_PENDDING_COUNT(_X_)                   ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DBGL1RSTDISABLE                               ( BIT(6) )
#define BIT_EVENTO_PENDDING_COUNT_CLR                     ( BIT(5) )
#define BIT_EVENTI_MASK_1                                 ( BIT(4) )
#define BIT_EVENTI_MASK_0                                 ( BIT(3) )
#define BIT_EVENT_OUT_EN                                  ( BIT(2) )
#define BIT_ACINACTM                                      ( BIT(0) )

/* bits definitions for register REG_DCIU_CLUSTERx_CPU_SRAM_CTRL2 */
#define BIT_L1_SRDP_EMASB                                 ( BIT(30) )
#define BITS_L1_SRDP_EMAWB(_X_)                           ( (_X_) << 28 & (BIT(28)|BIT(29)) )
#define BITS_L1_SRDP_EMAB(_X_)                            ( (_X_) << 25 & (BIT(25)|BIT(26)|BIT(27)) )
#define BIT_L1_SRDP_EMASA                                 ( BIT(24) )
#define BITS_L1_SRDP_EMAWA(_X_)                           ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BITS_L1_SRDP_EMAA(_X_)                            ( (_X_) << 19 & (BIT(19)|BIT(20)|BIT(21)) )
#define BIT_L1_SR1P_EMAS                                  ( BIT(18) )
#define BITS_L1_SR1P_EMAW(_X_)                            ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_L1_SR1P_EMA(_X_)                             ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)) )
#define BIT_L1_RF2P_EMASA                                 ( BIT(12) )
#define BITS_L1_RF2P_EMAB(_X_)                            ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BITS_L1_RF2P_EMAA(_X_)                            ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_L1_RF1P_EMAS                                  ( BIT(5) )
#define BITS_L1_RF1P_EMAW(_X_)                            ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BITS_L1_RF1P_EMA(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_DCIU_CLUSTERx_MP_SRAM_CTRL2 */
#define BIT_L2_SRDP_EMASB                                 ( BIT(30) )
#define BITS_L2_SRDP_EMAWB(_X_)                           ( (_X_) << 28 & (BIT(28)|BIT(29)) )
#define BITS_L2_SRDP_EMAB(_X_)                            ( (_X_) << 25 & (BIT(25)|BIT(26)|BIT(27)) )
#define BIT_L2_SRDP_EMASA                                 ( BIT(24) )
#define BITS_L2_SRDP_EMAWA(_X_)                           ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BITS_L2_SRDP_EMAA(_X_)                            ( (_X_) << 19 & (BIT(19)|BIT(20)|BIT(21)) )
#define BIT_L2_SR1P_EMAS                                  ( BIT(18) )
#define BITS_L2_SR1P_EMAW(_X_)                            ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_L2_SR1P_EMA(_X_)                             ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)) )
#define BIT_L2_RF2P_EMASA                                 ( BIT(12) )
#define BITS_L2_RF2P_EMAB(_X_)                            ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BITS_L2_RF2P_EMAA(_X_)                            ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_L2_RF1P_EMAS                                  ( BIT(5) )
#define BITS_L2_RF1P_EMAW(_X_)                            ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BITS_L2_RF1P_EMA(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_DCIU_CLUSTERx_STATUS2 */
#define BIT_L2FLUSHDONE                                   ( BIT(8) )
#define BITS_STANDBY_WFE(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_SMPEN(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DCIU_CLUSTER1_CPUx_CFG3 */
#define BIT_CRYPTODISABLE97                               ( BIT(29) )
#define BIT_CFGEND99                                      ( BIT(27) )
#define BIT_CFGTE101                                      ( BIT(25) )
#define BIT_CP15SDISABLE103                               ( BIT(18) )

/* bits definitions for register REG_DCIU_CS_SRAM_CTRL */
#define BIT_DCI_SRDP_EMASB112                             ( BIT(30) )
#define BITS_DCI_SRDP_EMAWB113(_X_)                       ( (_X_) << 28 & (BIT(28)|BIT(29)) )
#define BITS_DCI_SRDP_EMAB114(_X_)                        ( (_X_) << 25 & (BIT(25)|BIT(26)|BIT(27)) )
#define BIT_DCI_SRDP_EMASA115                             ( BIT(24) )
#define BITS_DCI_SRDP_EMAWA116(_X_)                       ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BITS_DCI_SRDP_EMAA117(_X_)                        ( (_X_) << 19 & (BIT(19)|BIT(20)|BIT(21)) )
#define BIT_DCI_SR1P_EMAS118                              ( BIT(18) )
#define BITS_DCI_SR1P_EMAW119(_X_)                        ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_DCI_SR1P_EMA120(_X_)                         ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)) )
#define BIT_DCI_RF2P_EMASA121                             ( BIT(12) )
#define BITS_DCI_RF2P_EMAB122(_X_)                        ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BITS_DCI_RF2P_EMAA123(_X_)                        ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_DCI_RF1P_EMAS124                              ( BIT(5) )
#define BITS_DCI_RF1P_EMAW125(_X_)                        ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BITS_DCI_RF1P_EMA126(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_DCIU_GIC_CTRL */
#define BIT_GIC500_SW_RSTN                                ( BIT(22) )
#define BITS_NSEI_TO_CPU_CORE_MASK(_X_)                   ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_GIC500_ECC_FATAL_INT_STATUS                   ( BIT(11) )
#define BIT_GIC500_ECC_FATAL_INT_CLR                      ( BIT(10) )
#define BIT_GIC500_ECC_FATAL_INT_EN                       ( BIT(9) )

/* bits definitions for register REG_DCIU_CKG_CTRL */
#define BITS_CCI_CLKOFF_TIMER(_X_)                        ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_ATCLKEN_MASK                                  ( BIT(4) )
#define BIT_CIU_CKG_EN                                    ( BIT(3) )
#define BIT_CCI_CKG_EN                                    ( BIT(2) )
#define BIT_MAIN_CKG_EN                                   ( BIT(1) )
#define BIT_ACLKM0_CKG_EN                                 ( BIT(0) )

/* bits definitions for register REG_DCIU_CPU_GIC_CTRL */
#define BIT_NFIQ_NIRQ_MASK_C2                             ( BIT(5) )
#define BIT_NFIQ_NIRQ_MASK_C1                             ( BIT(4) )
#define BIT_NFIQ_NIRQ_MASK_C0                             ( BIT(3) )
#define BIT_GICCDISABLE_C2                                ( BIT(2) )
#define BIT_GICCDISABLE_C1                                ( BIT(1) )
#define BIT_GICCDISABLE_C0                                ( BIT(0) )

/* bits definitions for register REG_DCIU_CCI_DBG_CTRL */
#define BIT_CCI_GPU_FORCE_AWQOS                           ( BIT(5) )
#define BIT_CCI_GPU_FORCE_ARQOS                           ( BIT(4) )
#define BIT_DCI_DBGEN176                                  ( BIT(3) )
#define BIT_DCI_SPIDEN177                                 ( BIT(2) )
#define BIT_DCI_NIDEN178                                  ( BIT(1) )
#define BIT_DCI_SPNIDEN179                                ( BIT(0) )

/* bits definitions for register REG_DCIU_PW_STR_CTRL */
#define BIT_PW_STR_2                                      ( BIT(2) )
#define BIT_PW_STR_1                                      ( BIT(1) )
#define BIT_PW_STR_0                                      ( BIT(0) )

/* bits definitions for register REG_DCIU_CCI_INF_QOS_CTRL */
#define BITS_C2_ARQOS_CFG(_X_)                            ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_C2_AWQOS_CFG(_X_)                            ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_C1_ARQOS_CFG(_X_)                            ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_C1_AWQOS_CFG(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_C0_ARQOS_CFG(_X_)                            ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_C0_AWQOS_CFG(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DCIU_CLUSTER2_CPUx_CFG1 */
#define BIT_CRYPTODISABLE230                              ( BIT(29) )
#define BIT_CFGEND232                                     ( BIT(27) )
#define BIT_CFGTE234                                      ( BIT(25) )
#define BIT_CP15SDISABLE236                               ( BIT(18) )

/* bits definitions for register REG_DCIU_CPU_L2_LIGHT_SLEEP_CTRL */
#define BIT_C2_L2_REPLRAM_LIGHT_SLEEP_DIS                 ( BIT(6) )
#define BIT_C2_L2_TAGRAM_LIGHT_SLEEP_DIS                  ( BIT(5) )
#define BIT_C2_L2_DATARAM_LIGHT_SLEEP_DIS                 ( BIT(4) )
#define BIT_C1_L2_VICTIMRAM_LIGHT_SLEEP_DIS               ( BIT(3) )
#define BIT_C1_L2_DATARAM_LIGHT_SLEEP_DIS                 ( BIT(2) )
#define BIT_C0_L2_VICTIMRAM_LIGHT_SLEEP_DIS               ( BIT(1) )
#define BIT_C0_L2_DATARAM_LIGHT_SLEEP_DIS                 ( BIT(0) )

/* bits definitions for register REG_DCIU_CPU_ACLKM0_ACLKM1_CTRL */
#define BIT_DIS_SLOW_CLK_DURING_CLUSTER2_PWRUP            ( BIT(2) )
#define BIT_DIS_SLOW_CLK_DURING_CLUSTER1_PWRUP            ( BIT(1) )
#define BIT_DIS_SLOW_CLK_DURING_CLUSTER0_PWRUP            ( BIT(0) )

/* bits definitions for register REG_DCIU_CLUSTER0_ROM_READ_ADDR_REMAP */
#define BITS_ROM_REMAP_ADDR(_X_)                          ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_ROM_REMAP_ENABLE                              ( BIT(0) )

/* bits definitions for register REG_DCIU_CCI_M1_CTRL */
#define BIT_CCI_M1_EN                                     ( BIT(31) )
#define BIT_CCI_M1_CLKDIV                                 ( BIT(0) )
#define BIT_CCI_M1_READ                                   ( BIT(6) )
#define BIT_CCI_M1_LATCH                                  ( BIT(5) )
#define BIT_CCI_M1_HB_SEL                                 ( BIT(4) )
#define BIT_CCI_M1_CTRL_SEL                               ( BIT(0) )

/* bits definitions for register REG_DCIU_CCI_M1_X */
#define BIT_CCI_M1_X                                      ( BIT(31) )

/* bits definitions for register REG_DCIU_CCI_M1_Y */
#define BIT_CCI_M1_Y                                      ( BIT(31) )

/* bits definitions for register REG_DCIU_CCI_M1_DATA */
#define BITS_CCI_M1_DATA(_X_)                             (_X_)

#endif
