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


#ifndef __H_REGS_GEU_HEADFILE_H__
#define __H_REGS_GEU_HEADFILE_H__ __FILE__

#define	REGS_GEU

/* registers definitions for GEU */
#define REG_GEU_GEU_STATUS                                ASR_ADDR(REGS_GEU_BASE, 0X000)/*GEU Status Register*/
#define REG_GEU_GEU_CONFIG                                ASR_ADDR(REGS_GEU_BASE, 0X004)/*GEU Configuration Register*/
#define REG_GEU_BCM_CONFIG_0                              ASR_ADDR(REGS_GEU_BASE, 0X020)/*BCM Config 0 Register*/
#define REG_GEU_BCM_CONFIG_1                              ASR_ADDR(REGS_GEU_BASE, 0X024)/*BCM Config 1 Register*/
#define REG_GEU_GEU_FUSE_PROG_VAL1                        ASR_ADDR(REGS_GEU_BASE, 0X038)/*Fuse Programming Value[127:0] in Software Fuse Programming Mode Register*/
#define REG_GEU_GEU_FUSE_PROG_VAL2                        ASR_ADDR(REGS_GEU_BASE, 0X048)/*Fuse Programming Value[255:128] in Software Fuse Programming Mode Register*/
#define REG_GEU_GEU_FUSE_VAL_APCFG1                       ASR_ADDR(REGS_GEU_BASE, 0X104)/*Fuse Value for Application Subsystem Config Register 1*/
#define REG_GEU_GEU_FUSE_VAL_APCFG2                       ASR_ADDR(REGS_GEU_BASE, 0X108)/*Fuse Value for Application Subsystem Config Register 2*/
#define REG_GEU_GEU_FUSE_VAL_APCFG3                       ASR_ADDR(REGS_GEU_BASE, 0X10C)/*Fuse Value for Application Subsystem Config Register 3*/
#define REG_GEU_GEU_FUSE_MANU_PARA_1                      ASR_ADDR(REGS_GEU_BASE, 0X110)/*Manufacturing Parameters [31:0] Register*/
#define REG_GEU_GEU_FUSE_MANU_PARA_2                      ASR_ADDR(REGS_GEU_BASE, 0X114)/*Manufacturing Parameters [63:32] Register*/
#define REG_GEU_GEU_FUSE_MANU_PARA_3                      ASR_ADDR(REGS_GEU_BASE, 0X118)/*Manufacturing Parameters [95:64] Register*/
#define REG_GEU_GEU_FUSE_MANU_PARA_4                      ASR_ADDR(REGS_GEU_BASE, 0X11C)/*Manufacturing Parameters [127:96] Register*/
#define REG_GEU_GEU_FUSE_MANU_PARA_5                      ASR_ADDR(REGS_GEU_BASE, 0X120)/*Manufacturing Parameters [159:128] Register*/
#define REG_GEU_GEU_FUSE_VAL_ROOT_KEY1                    ASR_ADDR(REGS_GEU_BASE, 0X124)/*Fuse Value for Root Key Register 1*/
#define REG_GEU_GEU_FUSE_VAL_ROOT_KEY2                    ASR_ADDR(REGS_GEU_BASE, 0X128)/*Fuse Value for Root Key Register 2*/
#define REG_GEU_GEU_FUSE_VAL_ROOT_KEY3                    ASR_ADDR(REGS_GEU_BASE, 0X12C)/*Fuse Value for Root Key Register 3*/
#define REG_GEU_GEU_FUSE_VAL_ROOT_KEY4                    ASR_ADDR(REGS_GEU_BASE, 0X130)/*Fuse Value for Root Key Register 4*/
#define REG_GEU_GEU_FUSE_VAL_ROOT_KEY5                    ASR_ADDR(REGS_GEU_BASE, 0X134)/*Fuse Value for Root Key Register 5*/
#define REG_GEU_GEU_FUSE_VAL_ROOT_KEY6                    ASR_ADDR(REGS_GEU_BASE, 0X138)/*Fuse Value for Root Key Register 6*/
#define REG_GEU_GEU_FUSE_VAL_ROOT_KEY7                    ASR_ADDR(REGS_GEU_BASE, 0X13C)/*Fuse Value for Root Key Register 7*/
#define REG_GEU_GEU_FUSE_VAL_ROOT_KEY8                    ASR_ADDR(REGS_GEU_BASE, 0X140)/*Fuse Value for Root Key Register 8*/
#define REG_GEU_GEU_FUSE_VAL_SSK_1_8                      ASR_ADDR(REGS_GEU_BASE, 0X144)/*Fuse Value for Secret Symmetric Key SSK 1- 8*/
#define REG_GEU_GEU_FUSE_VAL_OEM_BANK6_1_8                ASR_ADDR(REGS_GEU_BASE, 0X164)/*Fuse Value for BANK6 1- 8*/
#define REG_GEU_GEU_FUSE_STATUS                           ASR_ADDR(REGS_GEU_BASE, 0X184)/*Fuse Operation Status Register*/
#define REG_GEU_DRNG_DATA                                 ASR_ADDR(REGS_GEU_BASE, 0X188)/*Digital Random Data Register*/
#define REG_GEU_GEU_FUSE_VAL_BANK7_1_8                    ASR_ADDR(REGS_GEU_BASE, 0X190)/*Fuse Value for BANK7 1- 8*/
#define REG_GEU_GEU_FUSE_VAL_BANK8_1_8                    ASR_ADDR(REGS_GEU_BASE, 0X200)/*Fuse Value for BANK8 1- 8*/
#define REG_GEU_GEU_FUSE_VAL_BANK9_1_8                    ASR_ADDR(REGS_GEU_BASE, 0X220)/*Fuse Value for BANK9 1- 8*/
#define REG_GEU_GEU_FUSE_VAL_BANK10_1_8                   ASR_ADDR(REGS_GEU_BASE, 0X240)/*Fuse Value for BANK10 1- 8*/
#define REG_GEU_GEU_FUSE_VAL_BANK11_1_8                   ASR_ADDR(REGS_GEU_BASE, 0X260)/*Fuse Value for BANK11 1- 8*/
#define REG_GEU_GEU_FUSE_VAL_CDPKH_1_8                    ASR_ADDR(REGS_GEU_BASE, 0X280)/*Fuse Value for BANK3 Chip Debug Public Key Hash CDPKH1- 8*/
#define REG_GEU_GEU_FUSE_VAL_ROTPKH_1_8                   ASR_ADDR(REGS_GEU_BASE, 0X2A0)/*Fuse Value for BANK4  Root of Trust Public Key Hash ROTPKH1- 8*/
#define REG_GEU_GEU_FUSE_VAL_ARCN_1_8                     ASR_ADDR(REGS_GEU_BASE, 0X2C0)/*Fuse Value for BANK5 ARCN 1- 8*/
#define REG_GEU_FUSE_SCLK_DIV_CNTR                        ASR_ADDR(REGS_GEU_BASE, 0X3FC)/*Fuse Slow Clock Divider Counter Register*/



/* bits definitions for register REG_GEU_GEU_STATUS */

/* bits definitions for register REG_GEU_GEU_CONFIG */
#define BIT_STICKY_CONTROL_BIT                            ( BIT(30) )
#define BIT_FUSE_POWER_BYPASS                             ( BIT(28) )
#define BITS_FUSE_CLOCK_DIVIDER(_X_)                      ( (_X_) << 25 & (BIT(25)|BIT(26)|BIT(27)) )
#define BIT_FUSE_CLOCK_DISABLE                            ( BIT(23) )
#define BIT_FUSE_SOFTWARE_RESET                           ( BIT(22) )
#define BITS_FUSE_BLOCK_NUMBER(_X_)                       ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_HIGH_VOLT_ENABLE                              ( BIT(17) )
#define BIT_BURN_FUSE_ENABLE                              ( BIT(16) )
#define BIT_FUSE_LOCK                                     ( BIT(15) )
#define BIT_ENABLE_SOFT_FUSE_PROG                         ( BIT(14) )
#define BIT_SEL_FUSE_B                                    ( BIT(13) )

/* bits definitions for register REG_GEU_BCM_CONFIG_0 */
#define BITS_BROM_RTC(_X_)                                ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for register REG_GEU_BCM_CONFIG_1 */
#define BIT_ROM_SECURE_EN                                 ( BIT(31) )
#define BIT_ROM_CLK_GATING_CTRL                           ( BIT(8) )
#define BITS_ROM_WAIT_STATE(_X_)                          ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_GEU_GEU_FUSE_PROG_VAL1 */
#define BITS_FUSE_3_0_31_0(_X_)                           (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_PROG_VAL2 */
#define BITS_FUSE_7_4_31_0(_X_)                           (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_APCFG1 */
#define BITS_OTP_APP_TOP_CONFIG_15_0(_X_)                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_OTP_CP_TOP_CONFIG_15_0(_X_)                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_APCFG2 */
#define BITS_OTP_APP_TOP_CONFIG_47_16(_X_)                (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_APCFG3 */
#define BITS_OTP_APP_TOP_CONFIG_79_48(_X_)                (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_MANU_PARA_1 */
#define BITS_MANU_PARA_31_0(_X_)                          (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_MANU_PARA_2 */
#define BITS_MANU_PARA_63_32(_X_)                         (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_MANU_PARA_3 */
#define BITS_MANU_PARA_95_64(_X_)                         (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_MANU_PARA_4 */
#define BITS_MANU_PARA_127_96(_X_)                        (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_MANU_PARA_5 */
#define BITS_MANU_PARA_159_128(_X_)                       (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_ROOT_KEY1 */
#define BITS_RKEY_31_0(_X_)                               (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_ROOT_KEY2 */
#define BITS_RKEY_63_32(_X_)                              (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_ROOT_KEY3 */
#define BITS_RKEY_95_64(_X_)                              (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_ROOT_KEY4 */
#define BITS_REKY_127_96(_X_)                             (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_ROOT_KEY5 */
#define BITS_RKEY_159_128(_X_)                            (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_ROOT_KEY6 */
#define BITS_RKEY_191_160(_X_)                            (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_ROOT_KEY7 */
#define BITS_RKEY_223_192(_X_)                            (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_ROOT_KEY8 */
#define BITS_RKEY_255_224(_X_)                            (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_SSK_1_8 */
#define BITS_OTP_SSK_31_0(_X_)                            (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_OEM_BANK6_1_8 */
#define BITS_FUSE_BANK6(_X_)                              (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_STATUS */
#define BITS_LOCK_BIT(_X_)                                ( (_X_) << 14 & (BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BITS_LIFE_CYCLE(_X_)                              ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_GE_FUSE_READY205                              ( BIT(1) )
#define BIT_FUSE_BURN_DONE                                ( BIT(0) )

/* bits definitions for register REG_GEU_DRNG_DATA */
#define BITS_DRNG_DATA(_X_)                               (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_BANK7_1_8 */
#define BITS_FUSE_BANK7(_X_)                              (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_BANK8_1_8 */
#define BITS_FUSE_BANK8(_X_)                              (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_BANK9_1_8 */
#define BITS_FUSE_BANK9(_X_)                              (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_BANK10_1_8 */
#define BITS_FUSE_BANK10(_X_)                             (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_BANK11_1_8 */
#define BITS_FUSE_BANK11(_X_)                             (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_CDPKH_1_8 */
#define BITS_FUSE_BANK3_CDPKH(_X_)                        (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_ROTPKH_1_8 */
#define BITS_FUSE_BANK4_ROTPKH(_X_)                       (_X_)

/* bits definitions for register REG_GEU_GEU_FUSE_VAL_ARCN_1_8 */
#define BITS_FUSE_BANK5_ARCN(_X_)                         (_X_)

/* bits definitions for register REG_GEU_FUSE_SCLK_DIV_CNTR */
#define BITS_FUSE_SCLK_DIV_CNTR(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )

#endif
