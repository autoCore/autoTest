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


#ifndef __H_REGS_SMC_HEADFILE_H__
#define __H_REGS_SMC_HEADFILE_H__ __FILE__

#define	REGS_SMC

/* registers definitions for SMC */
#define REG_SMC_SMC_MSCx                                  ASR_ADDR(REGS_SMC_BASE, 0X20)/*Static Memory Control Registers*/
#define REG_SMC_SMC_SXCNFGx                               ASR_ADDR(REGS_SMC_BASE, 0X30)/*Synchronous Static Memory Control Registers*/
#define REG_SMC_SMC_MEMCLKCFG                             ASR_ADDR(REGS_SMC_BASE, 0X68)/*Clock Configuration Control Register*/
#define REG_SMC_SMC_CSDFICFGx                             ASR_ADDR(REGS_SMC_BASE, 0X90)/*DFI Configuration Control Register for Chip Selects*/
#define REG_SMC_SMC_CLK_RET_DEL                           ASR_ADDR(REGS_SMC_BASE, 0XB0)/*Synchronous NOR Flash Clock Return Delay Register*/
#define REG_SMC_SMC_ADV_RET_DEL                           ASR_ADDR(REGS_SMC_BASE, 0XB4)/*Synchronous NOR Flash ADVn Return Delay Register*/
#define REG_SMC_SMC_CSADRMAPx                             ASR_ADDR(REGS_SMC_BASE, 0XC0)/*Address Mapping Control Registers*/
#define REG_SMC_SMC_TCVCFGREG                             ASR_ADDR(REGS_SMC_BASE, 0XD0)/*Transceiver Configuration Control Register 0*/
#define REG_SMC_SMC_WE_Apx                                ASR_ADDR(REGS_SMC_BASE, 0XE0)/*DF_WEn Address Phase Control Registers*/
#define REG_SMC_SMC_OE_Apx                                ASR_ADDR(REGS_SMC_BASE, 0XF0)/*DF_OEn Address Phase Control Registers*/
#define REG_SMC_SMC_ADV_Apx                               ASR_ADDR(REGS_SMC_BASE, 0X100)/*DF_ADVn Address Phase Control Registers*/
#define REG_SMC_SMC_WE_DPx                                ASR_ADDR(REGS_SMC_BASE, 0X110)/*DF_WEn Data Phase Value Control Registers*/
#define REG_SMC_SMC_OE_Apx                                ASR_ADDR(REGS_SMC_BASE, 0X120)/*DF_OEn Data Phase Value Control Registers*/
#define REG_SMC_SMC_TCVENx                                ASR_ADDR(REGS_SMC_BASE, 0X130)/*Transceiver Enable Value Registers*/
#define REG_SMC_SMC_TCVENx                                ASR_ADDR(REGS_SMC_BASE, 0X40)/*Address Valid (ADV) Value Registers*/



/* bits definitions for register REG_SMC_SMC_MSCx */
#define BITS_WE_GEN(_X_)                                  ( (_X_) << 30 & (BIT(30)|BIT(31)) )
#define BITS_WE_D_HO(_X_)                                 ( (_X_) << 25 & (BIT(25)|BIT(26)|BIT(27)) )
#define BITS_WE_D_SU(_X_)                                 ( (_X_) << 22 & (BIT(22)|BIT(23)|BIT(24)) )
#define BITS_WE_LEN(_X_)                                  ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BITS_OE_GEN(_X_)                                  ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_OE_HO(_X_)                                   ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BITS_OE_SU(_X_)                                   ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BITS_OE_D_HO(_X_)                                 ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)) )
#define BITS_OE_D_SU(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_SMC_SMC_SXCNFGx */
#define BITS_SXWA(_X_)                                    ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BITS_SXRA(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_SMC_SMC_MEMCLKCFG */
#define BITS_CKEN(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SMC_SMC_CSDFICFGx */
#define BITS_ALTS(_X_)                                    ( (_X_) << 30 & (BIT(30)|BIT(31)) )
#define BITS_ALTH(_X_)                                    ( (_X_) << 28 & (BIT(28)|BIT(29)) )
#define BITS_ALW(_X_)                                     ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_RDY_SPEC4                                     ( BIT(23) )
#define BIT_RDY_SPEC3                                     ( BIT(22) )
#define BIT_RDY_SPEC2_1                                   ( BIT(20) )
#define BIT_RDY_SPEC0                                     ( BIT(19) )
#define BITS_ADDRBASE(_X_)                                ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_WRSYNC(_X_)                                  ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BITS_RDSYNC(_X_)                                  ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BITS_LOWADD(_X_)                                  ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_RBW                                           ( BIT(3) )
#define BITS_ADDMODE(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_SMC_SMC_CLK_RET_DEL */
#define BIT_FLOP_SEL                                      ( BIT(25) )
#define BITS_RDY_DLY_VAL(_X_)                             ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_DIN_DLY_VAL(_X_)                             ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_LLA_DLY_VAL(_X_)                             ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_ADV_DLY_VAL(_X_)                             ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_SCLK_DLY_VAL(_X_)                            ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_FLOP_CLK_DLY_VAL(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )
#define BITS_SCLK_DELAY_1(_X_)                            ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_SMC_SMC_ADV_RET_DEL */
#define BITS_ADVN_SEL(_X_)                                ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_ADVN_DEL_1(_X_)                              ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)) )
#define BITS_ADVN_DEL_0(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_SMC_SMC_CSADRMAPx */
#define BIT_MEMUSED                                       ( BIT(28) )
#define BITS_STADD(_X_)                                   ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BITS_MEMSIZE(_X_)                                 ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_WR_START                                      ( BIT(1) )
#define BIT_RD_START                                      ( BIT(0) )

/* bits definitions for register REG_SMC_SMC_TCVCFGREG */
#define BIT_TCVCS3EN                                      ( BIT(3) )
#define BIT_TCVCS2EN                                      ( BIT(2) )
#define BIT_TCVCS1EN                                      ( BIT(1) )
#define BIT_TCVCS0EN                                      ( BIT(0) )

/* bits definitions for register REG_SMC_SMC_WE_Apx */
#define BITS_WE_AP_VAL(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )

/* bits definitions for register REG_SMC_SMC_OE_Apx */
#define BITS_OE_AP_VAL(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )

/* bits definitions for register REG_SMC_SMC_ADV_Apx */
#define BITS_ADV_AP_VAL(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )

/* bits definitions for register REG_SMC_SMC_WE_DPx */
#define BITS_WE_DP_VAL(_X_)                               ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_EN_WE_CON                                     ( BIT(0) )

/* bits definitions for register REG_SMC_SMC_OE_Apx */
#define BITS_OE_DP_VAL(_X_)                               ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_EN_OE_CON                                     ( BIT(0) )

/* bits definitions for register REG_SMC_SMC_TCVENx */
#define BITS_TCVEN_VAL(_X_)                               ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_EN_TCVEN_CON                                  ( BIT(0) )

/* bits definitions for register REG_SMC_SMC_TCVENx */
#define BITS_ADV_VAL(_X_)                                 ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_EN_ADV_CON                                    ( BIT(0) )

#endif
