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


#ifndef __H_REGS_APB_SPARE_HEADFILE_H__
#define __H_REGS_APB_SPARE_HEADFILE_H__ __FILE__

#define	REGS_APB_SPARE

/* registers definitions for APB_SPARE */
#define REG_APB_SPARE_APB_spare0_reg                      ASR_ADDR(REGS_APB_SPARE_BASE, 0X0)/*APB spare0 Register*/
#define REG_APB_SPARE_Sensor_v18_reg                      ASR_ADDR(REGS_APB_SPARE_BASE, 0XC)/*Sensor_v18_out Register*/
#define REG_APB_SPARE_APB_spare1_reg                      ASR_ADDR(REGS_APB_SPARE_BASE, 0X100)/*PLL1 SW control Register*/
#define REG_APB_SPARE_APB_spare2_reg                      ASR_ADDR(REGS_APB_SPARE_BASE, 0X104)/*PLL2 SW control Register*/
#define REG_APB_SPARE_APB_spare3_reg                      ASR_ADDR(REGS_APB_SPARE_BASE, 0X108)/*PLL3 SW control Register*/
#define REG_APB_SPARE_APB_SPARE4                          ASR_ADDR(REGS_APB_SPARE_BASE, 0X10C)/*APB Spare 4 Register*/
#define REG_APB_SPARE_APB_spare5_reg                      ASR_ADDR(REGS_APB_SPARE_BASE, 0X110)/*APB spare5 register*/
#define REG_APB_SPARE_APB_spare6_reg                      ASR_ADDR(REGS_APB_SPARE_BASE, 0X114)/*PLL5 SW control Register*/
#define REG_APB_SPARE_APB_spare7_reg                      ASR_ADDR(REGS_APB_SPARE_BASE, 0X118)/*APB spare7 register*/
#define REG_APB_SPARE_APB_spare8_reg                      ASR_ADDR(REGS_APB_SPARE_BASE, 0X11C)/*APB spare8 register*/
#define REG_APB_SPARE_APB_spare9_reg                      ASR_ADDR(REGS_APB_SPARE_BASE, 0X120)/*APB spare9 register*/
#define REG_APB_SPARE_APB_spare10_reg                     ASR_ADDR(REGS_APB_SPARE_BASE, 0X124)/*PLL4 SW control Register*/
#define REG_APB_SPARE_PLLx_SSC_CTRL0                      ASR_ADDR(REGS_APB_SPARE_BASE, 0x130)/*PLLx SSC Control Register*/
#define REG_APB_SPARE_PLLx_SSC_CTRL1                      ASR_ADDR(REGS_APB_SPARE_BASE, 0x13C)/*PLLx SSC Control Register*/
#define REG_APB_SPARE_PLLx_SSC_CTRL2                      ASR_ADDR(REGS_APB_SPARE_BASE, 0x148)/*PLLx SSC Control Register*/
#define REG_APB_SPARE_PLLx_SSC_CONF0                      ASR_ADDR(REGS_APB_SPARE_BASE, 0x134)/*PLLx SSC Configuration Register*/
#define REG_APB_SPARE_PLLx_SSC_CONF1                      ASR_ADDR(REGS_APB_SPARE_BASE, 0x140)/*PLLx SSC Configuration Register*/
#define REG_APB_SPARE_PLLx_SSC_CONF2                      ASR_ADDR(REGS_APB_SPARE_BASE, 0x14C)/*PLLx SSC Configuration Register*/
#define REG_APB_SPARE_APB_spare16_reg                     ASR_ADDR(REGS_APB_SPARE_BASE, 0X13C)/*PLL6 SW control Register_1*/
#define REG_APB_SPARE_APB_spare17_reg                     ASR_ADDR(REGS_APB_SPARE_BASE, 0X140)/*PLL6 SW control Register_2*/
#define REG_APB_SPARE_APB_spare20_reg                     ASR_ADDR(REGS_APB_SPARE_BASE, 0X148)/*PLL7 SW control Register_1*/
#define REG_APB_SPARE_APB_spare21_reg                     ASR_ADDR(REGS_APB_SPARE_BASE, 0X14C)/*PLL7 SW control Register_2*/



/* bits definitions for register REG_APB_SPARE_APB_spare0_reg */
#define BIT_CP_PWRSW_DLY                                  ( BIT(1) )
#define BIT_CP_AP_SEL                                     ( BIT(0) )

/* bits definitions for register REG_APB_SPARE_Sensor_v18_reg */
#define BIT_NAND_SENSOR_V18                               ( BIT(0) )

/* bits definitions for register REG_APB_SPARE_APB_spare1_reg */
#define BIT_PU_CTRL_BY_CLKOUT_EN31                        ( BIT(31) )
#define BIT_CLKOUT_DIV5_EN32                              ( BIT(30) )
#define BIT_CLKOUT_DIV4_EN33                              ( BIT(29) )
#define BIT_CLKOUT_DIV3_EN34                              ( BIT(28) )
#define BIT_CLKOUT_DIV2_EN35                              ( BIT(27) )
#define BIT_CLKOUT_DIV1_EN36                              ( BIT(26) )
#define BIT_DIG_TEST_OEN37                                ( BIT(25) )
#define BIT_ANA_TEST_OEN38                                ( BIT(24) )
#define BITS_TE_SEL39(_X_)                                ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BIT_PLL_LOCK_SEL40                                ( BIT(21) )
#define BIT_PLL__FORCE_LOCK41                             ( BIT(20) )
#define BITS_PLL_LOCK_DELAY42(_X_)                        ( (_X_) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_BYPASS43                                      ( BIT(16) )
#define BITS_REG_VOLT44(_X_)                              ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_KVCO45(_X_)                                  ( (_X_) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_FAST_LOCK46                                   ( BIT(10) )
#define BITS_CHARGE_PUMP47(_X_)                           ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BIT_BAND_SEL48                                    ( BIT(7) )
#define BITS_APB_S_49(_X_)                                ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BITS_PLL1_REG0(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_APB_SPARE_APB_spare2_reg */
#define BIT_PU_CTRL_BY_CLKOUT_EN57                        ( BIT(31) )
#define BIT_CLKOUT_DIV5_EN58                              ( BIT(30) )
#define BIT_CLKOUT_DIV4_EN59                              ( BIT(29) )
#define BIT_CLKOUT_DIV3_EN60                              ( BIT(28) )
#define BIT_CLKOUT_DIV2_EN61                              ( BIT(27) )
#define BIT_CLKOUT_DIV1_EN62                              ( BIT(26) )
#define BIT_DIG_TEST_OEN63                                ( BIT(25) )
#define BIT_ANA_TEST_OEN64                                ( BIT(24) )
#define BITS_TE_SEL65(_X_)                                ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BIT_PLL_LOCK_SEL66                                ( BIT(21) )
#define BIT_PLL__FORCE_LOCK67                             ( BIT(20) )
#define BITS_PLL_LOCK_DELAY68(_X_)                        ( (_X_) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_BYPASS69                                      ( BIT(16) )
#define BITS_REG_VOLT70(_X_)                              ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_KVCO71(_X_)                                  ( (_X_) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_FAST_LOCK72                                   ( BIT(10) )
#define BITS_CHARGE_PUMP73(_X_)                           ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BIT_BAND_SEL74                                    ( BIT(7) )
#define BITS_APB_S_75(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_APB_SPARE_APB_spare3_reg */
#define BIT_PU_CTRL_BY_CLKOUT_EN82                        ( BIT(31) )
#define BIT_CLKOUT_DIV5_EN83                              ( BIT(30) )
#define BIT_CLKOUT_DIV4_EN84                              ( BIT(29) )
#define BIT_CLKOUT_DIV3_EN85                              ( BIT(28) )
#define BIT_CLKOUT_DIV2_EN86                              ( BIT(27) )
#define BIT_CLKOUT_DIV1_EN87                              ( BIT(26) )
#define BIT_DIG_TEST_OEN88                                ( BIT(25) )
#define BIT_ANA_TEST_OEN89                                ( BIT(24) )
#define BITS_TE_SEL90(_X_)                                ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BIT_PLL_LOCK_SEL91                                ( BIT(21) )
#define BIT_PLL__FORCE_LOCK92                             ( BIT(20) )
#define BITS_PLL_LOCK_DELAY93(_X_)                        ( (_X_) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_BYPASS94                                      ( BIT(16) )
#define BITS_REG_VOLT95(_X_)                              ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_KVCO96(_X_)                                  ( (_X_) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_FAST_LOCK97                                   ( BIT(10) )
#define BITS_CHARGE_PUMP98(_X_)                           ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BIT_BAND_SEL99                                    ( BIT(7) )
#define BITS_APB_S_100(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_APB_SPARE_APB_SPARE4 */
#define BIT_PU_AUXADC                                     ( BIT(31) )
#define BIT_AUXADC_MODE                                   ( BIT(30) )
#define BIT_AUXADC_SOC                                    ( BIT(29) )
#define BITS_AUXADC_SELIN(_X_)                            ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_DIG_TEST_OEN111                               ( BIT(25) )
#define BIT_ANA_TEST_OEN112                               ( BIT(24) )
#define BIT_PU_BG                                         ( BIT(20) )
#define BITS_CK_TEST(_X_)                                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_INT_PLL_SEL(_X_)                             ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)) )
#define BITS_OUT_CTRL2(_X_)                               ( (_X_) << 10 & (BIT(10)|BIT(11)|BIT(12)) )
#define BITS_OUT_CTRL1(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_INT_VOLT_SEL(_X_)                            ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_BIAS_CURRENT(_X_)                            ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_CLK_DIV_SEL(_X_)                             ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_APB_SPARE_APB_spare5_reg */
#define BITS_APB_S_128(_X_)                               ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_APB_S_129                                     ( BIT(12) )
#define BIT_APB_S_130                                     ( BIT(11) )
#define BIT_APB_S_131                                     ( BIT(10) )
#define BITS_APB_S_132(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_APB_S_133(_X_)                               ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_APB_S_134                                     ( BIT(4) )
#define BIT_APB_S_135                                     ( BIT(3) )
#define BIT_APB_S_136                                     ( BIT(2) )
#define BITS_APB_S_137(_X_)                               ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_APB_SPARE_APB_spare6_reg */
#define BIT_PU_CTRL_BY_CLKOUT_EN144                       ( BIT(31) )
#define BIT_CLKOUT_DIV5_EN145                             ( BIT(30) )
#define BIT_CLKOUT_DIV4_EN146                             ( BIT(29) )
#define BIT_CLKOUT_DIV3_EN147                             ( BIT(28) )
#define BIT_CLKOUT_DIV2_EN148                             ( BIT(27) )
#define BIT_CLKOUT_DIV1_EN149                             ( BIT(26) )
#define BIT_DIG_TEST_OEN150                               ( BIT(25) )
#define BIT_ANA_TEST_OEN151                               ( BIT(24) )
#define BITS_TE_SEL152(_X_)                               ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BIT_PLL_LOCK_SEL153                               ( BIT(21) )
#define BIT_PLL__FORCE_LOCK154                            ( BIT(20) )
#define BITS_PLL_LOCK_DELAY155(_X_)                       ( (_X_) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_BYPASS156                                     ( BIT(16) )
#define BITS_REG_VOLT157(_X_)                             ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_KVCO158(_X_)                                 ( (_X_) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_FAST_LOCK159                                  ( BIT(10) )
#define BITS_CHARGE_PUMP160(_X_)                          ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BIT_BAND_SEL161                                   ( BIT(7) )
#define BITS_APB_S_162(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_APB_SPARE_APB_spare7_reg */
#define BITS_APB_S_169(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_APB_S_170(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_APB_SPARE_APB_spare8_reg */
#define BITS_APB_S_177(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_APB_S_178(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_APB_S_179(_X_)                               ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_APB_S_180                                     ( BIT(2) )
#define BIT_APB_S_181                                     ( BIT(1) )
#define BIT_APB_S_182                                     ( BIT(0) )

/* bits definitions for register REG_APB_SPARE_APB_spare9_reg */
#define BIT_VCXO_DIG_GATE_EN                              ( BIT(31) )
#define BIT_GNSS_HW_CTRL_PU_EN                            ( BIT(30) )
#define BITS_APB_S_191(_X_)                               ( (_X_) << 25 & (BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BITS_TEST_ANA(_X_)                                ( (_X_) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BITS_RESERVE_IN(_X_)                              ( (_X_) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BITS_VREG_1P05V_SEL_PECL(_X_)                     ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BITS_VREG_1P2V_SEL(_X_)                           ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_ICC_ADJ(_X_)                                 ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_IPP_ADJ(_X_)                                 ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_PU_LIMITER                                    ( BIT(1) )
#define BIT_PU                                            ( BIT(0) )

/* bits definitions for register REG_APB_SPARE_APB_spare10_reg */
#define BIT_PU_CTRL_BY_CLKOUT_EN206                       ( BIT(31) )
#define BIT_CLKOUT_DIV5_EN207                             ( BIT(30) )
#define BIT_CLKOUT_DIV4_EN208                             ( BIT(29) )
#define BIT_CLKOUT_DIV3_EN209                             ( BIT(28) )
#define BIT_CLKOUT_DIV2_EN210                             ( BIT(27) )
#define BIT_CLKOUT_DIV1_EN211                             ( BIT(26) )
#define BIT_DIG_TEST_OEN212                               ( BIT(25) )
#define BIT_ANA_TEST_OEN213                               ( BIT(24) )
#define BITS_TE_SEL214(_X_)                               ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BIT_PLL_LOCK_SEL215                               ( BIT(21) )
#define BIT_PLL__FORCE_LOCK216                            ( BIT(20) )
#define BITS_PLL_LOCK_DELAY217(_X_)                       ( (_X_) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_BYPASS218                                     ( BIT(16) )
#define BITS_REG_VOLT219(_X_)                             ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_KVCO220(_X_)                                 ( (_X_) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_FAST_LOCK221                                  ( BIT(10) )
#define BITS_CHARGE_PUMP222(_X_)                          ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BIT_BAND_SEL223                                   ( BIT(7) )
#define BITS_APB_S_224(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_APB_SPARE_PLLx_SSC_CTRL2 */
#define BITS_APB_S_231(_X_)                               ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_INTPR(_X_)                                   ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BITS_INTPI(_X_)                                   ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_CLK_DET_EN                                    ( BIT(6) )
#define BIT_PI_LOOP_MODE                                  ( BIT(5) )
#define BIT_RESET_SSC                                     ( BIT(4) )
#define BIT_SSC_CLK_EN                                    ( BIT(3) )
#define BIT_SSC_MODE                                      ( BIT(2) )
#define BIT_RESET_PI                                      ( BIT(1) )
#define BIT_PI_EN                                         ( BIT(0) )

/* bits definitions for register REG_APB_SPARE_PLLx_SSC_CONF2 */
#define BITS_SSC_FREQ_DIV(_X_)                            ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_SSC_RNGE(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for register REG_APB_SPARE_APB_spare16_reg */
#define BIT_PLL6_PU                                       ( BIT(31) )
#define BIT_CLKOUT_DIV5_EN260                             ( BIT(30) )
#define BIT_CLKOUT_DIV4_EN261                             ( BIT(29) )
#define BIT_CLKOUT_DIV3_EN262                             ( BIT(28) )
#define BIT_CLKOUT_DIV2_EN263                             ( BIT(27) )
#define BIT_CLKOUT_DIV1_EN264                             ( BIT(26) )
#define BIT_DIG_TEST_OEN265                               ( BIT(25) )
#define BIT_ANA_TEST_OEN266                               ( BIT(24) )
#define BITS_TE_SEL267(_X_)                               ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BIT_PLL_LOCK_SEL268                               ( BIT(21) )
#define BIT_PLL__FORCE_LOCK269                            ( BIT(20) )
#define BITS_PLL_LOCK_DELAY270(_X_)                       ( (_X_) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_BYPASS271                                     ( BIT(16) )
#define BITS_REG_VOLT272(_X_)                             ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_KVCO273(_X_)                                 ( (_X_) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_FAST_LOCK274                                  ( BIT(10) )
#define BITS_CHARGE_PUMP275(_X_)                          ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BIT_BAND_SEL276                                   ( BIT(7) )
#define BITS_PLL6_FBDIV(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_APB_SPARE_APB_spare17_reg */
#define BIT_PLL_LOCK                                      ( BIT(31) )
#define BITS_APB_S_285(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BITS_PLL6SSC_MODE(_X_)                            ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_APB_S_SSC_FORCE_LOCK287                       ( BIT(13) )
#define BIT_APB_S_SPRD_DEP_STEP288                        ( BIT(12) )
#define BITS_APB_S_SPRD_DEP289(_X_)                       ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_PLL6_FRCDIV(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_APB_SPARE_APB_spare20_reg */
#define BIT_PLL7_PU                                       ( BIT(31) )
#define BIT_CLKOUT_DIV5_EN298                             ( BIT(30) )
#define BIT_CLKOUT_DIV4_EN299                             ( BIT(29) )
#define BIT_CLKOUT_DIV3_EN300                             ( BIT(28) )
#define BIT_CLKOUT_DIV2_EN301                             ( BIT(27) )
#define BIT_CLKOUT_DIV1_EN302                             ( BIT(26) )
#define BIT_DIG_TEST_OEN303                               ( BIT(25) )
#define BIT_ANA_TEST_OEN304                               ( BIT(24) )
#define BITS_TE_SEL305(_X_)                               ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BIT_PLL_LOCK_SEL306                               ( BIT(21) )
#define BIT_PLL__FORCE_LOCK307                            ( BIT(20) )
#define BITS_PLL_LOCK_DELAY308(_X_)                       ( (_X_) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_BYPASS309                                     ( BIT(16) )
#define BITS_REG_VOLT310(_X_)                             ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_KVCO311(_X_)                                 ( (_X_) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_FAST_LOCK312                                  ( BIT(10) )
#define BITS_CHARGE_PUMP313(_X_)                          ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BIT_BAND_SEL314                                   ( BIT(7) )
#define BITS_PLL7_FBDIV(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_APB_SPARE_APB_spare21_reg */
#define BIT_APB_S_322                                     ( BIT(31) )
#define BITS_APB_S_323(_X_)                               ( (_X_) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BITS_PLL7_FRCDIV(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )

#endif
