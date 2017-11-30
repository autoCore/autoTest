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


#ifndef __H_REGS_ASPEQUALIZER_HEADFILE_H__
#define __H_REGS_ASPEQUALIZER_HEADFILE_H__ __FILE__

#define	REGS_ASPEQUALIZER

/* registers definitions for ASPEQUALIZER */
#define REG_ASPEQUALIZER_EQU_Hx_SLOT1_REG                 ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0X00)/*Causal Half-slot Channel Tap Register*/
#define REG_ASPEQUALIZER_EQU_Hx_SQR_REG_S1                ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0X1C)/*Causal Half-slot Channel Tap Square Root Register*/
#define REG_ASPEQUALIZER_EQU_Hx_SLOT2_REG                 ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0X38)/*Anti-causal Half-slot Channel Tap Register*/
#define REG_ASPEQUALIZER_EQU_Hx_SQR_REG_S2                ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0X54)/*Anti-causal Half-slot Channel Tap Square Root Register*/
#define REG_ASPEQUALIZER_EQU_MU0_REG                      ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0X70)/*<mu>0 Register*/
#define REG_ASPEQUALIZER_EQU_MU6_REG                      ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0X74)/*<mu>1 Register*/
#define REG_ASPEQUALIZER_EQU_HD_S1_REGx                   ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0X78)/*Causal Half-slot Hard Decision Register*/
#define REG_ASPEQUALIZER_EQU_HD_S2_REGx                   ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0X90)/*Anti-causal Half-slot Hard Decision Register*/
#define REG_ASPEQUALIZER_EQU_SWRES_REG                    ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XA8)/*Software Reset Register*/
#define REG_ASPEQUALIZER_EQU_CONT_REG                     ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XAC)/*Equalizer Control Register*/
#define REG_ASPEQUALIZER_EQU_STATUS_REG                   ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XB0)/*Equalizer Status Register*/
#define REG_ASPEQUALIZER_EQU_MODE0_REG                    ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XB4)/*Equalizer Mode 0 Register*/
#define REG_ASPEQUALIZER_EQU_MODE1_SLOT1_REG              ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XB8)/*Equalizer Mode 1 S1 Register*/
#define REG_ASPEQUALIZER_EQU_MODE1_SLOT2_REG              ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XBC)/*Equalizer Mode 1 S2 Register*/
#define REG_ASPEQUALIZER_EQU_DBG_DATA_REG                 ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XC0)/*Equalizer Debug Data Read Register*/
#define REG_ASPEQUALIZER_EQU_RESUME_REG                   ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XC4)/*Equalizer Debug Standby Resume Register*/
#define REG_ASPEQUALIZER_EQU_REQ_REG                      ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XC8)/*Equalizer Debug Data Request Register*/
#define REG_ASPEQUALIZER_EQU_CURR_SYM_REG                 ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XCC)/*Current Symbol Register*/
#define REG_ASPEQUALIZER_EQU_NV_SLOT1_REG0                ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XD0)/*Causal Half-slot Noise Variance 0 Register*/
#define REG_ASPEQUALIZER_EQU_NV_SLOT1_REG1                ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XD4)/*Causal Half-slot Noise Variance 1 Register*/
#define REG_ASPEQUALIZER_EQU_NV_SLOT2_REG0                ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XD8)/*Anti-causal Half-slot Noise Variance 0 Register*/
#define REG_ASPEQUALIZER_EQU_NV_SLOT2_REG1                ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XDC)/*Anti-causal Half-slot Noise Variance 1 Register*/
#define REG_ASPEQUALIZER_EQU_LLR_REG_S1                   ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0X100)/*Causal Half-slot 44 Soft Metrics Registers*/
#define REG_ASPEQUALIZER_EQU_LLR_REG_S2                   ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0X200)/*Anti-causal Half-slot 44 Soft Metrics Register*/
#define REG_ASPEQUALIZER_DUMMY_REGISTER                   ASR_ADDR(REGS_ASPEQUALIZER_BASE, 0XX)/*This is a Dummy Register*/



/* bits definitions for register REG_ASPEQUALIZER_EQU_Hx_SLOT1_REG */
#define BITS_HX_S1_Q(_X_)                                 ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_HX_S1_I(_X_)                                 ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_Hx_SQR_REG_S1 */
#define BITS_HX_SQR_S1_Q(_X_)                             ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_HX_SQR_S1_I(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_Hx_SLOT2_REG */
#define BITS_HX_S2_Q(_X_)                                 ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_HX_S2_I(_X_)                                 ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_Hx_SQR_REG_S2 */
#define BITS_HX_SQR_S2_Q(_X_)                             ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_HX_SQR_S2_I(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_MU0_REG */
#define BITS_<MU>5(_X_)                                   ( (_X_) << 25 & (BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BITS_<MU>4(_X_)                                   ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BITS_<MU>3(_X_)                                   ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_<MU>2(_X_)                                   ( (_X_) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_<MU>1(_X_)                                   ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BITS_<MU>0(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_MU6_REG */
#define BITS_<MU>6(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_HD_S1_REGx */
#define BITS_HD_X_S1(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_HD_S2_REGx */
#define BITS_HD_X_S2(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_SWRES_REG */
#define BIT_ASPEQ_SW_RESET132                             ( BIT(0) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_CONT_REG */
#define BIT_EQUALIZER_GO                                  ( BIT(3) )
#define BIT_DEBUG_MODE_ON                                 ( BIT(2) )
#define BIT_CHANNEL_TRACKING_ON                           ( BIT(1) )
#define BIT_SOFT_METRIC_ON                                ( BIT(0) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_STATUS_REG */
#define BIT_NEW_OLD_MEMORY                                ( BIT(7) )
#define BIT_SEQUENCER_ERROR                               ( BIT(6) )
#define BIT_DEBUG_STANDBY                                 ( BIT(5) )
#define BIT_DEBUG_DATA_READY                              ( BIT(4) )
#define BIT_MIDDLE_OF_EQU2                                ( BIT(3) )
#define BIT_MIDDLE_OF_EQU1                                ( BIT(2) )
#define BIT_DATA_VALID                                    ( BIT(1) )
#define BIT_END_OF_EQUALIZATION                           ( BIT(0) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_MODE0_REG */
#define BIT_INDEPENDENT_TAPS                              ( BIT(30) )
#define BIT_DEBUG_THRESHOLD                               ( BIT(29) )
#define BIT_EQUALIZATION_TYPE                             ( BIT(28) )
#define BITS_GMSK_CTU_RATE(_X_)                           ( (_X_) << 26 & (BIT(26)|BIT(27)) )
#define BITS_SM_LAST_STATE_S2(_X_)                        ( (_X_) << 23 & (BIT(23)|BIT(24)|BIT(25)) )
#define BITS_LAST_STATE_S2(_X_)                           ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_CLOSE_EQU_MODE_S2                             ( BIT(19) )
#define BITS_SM_LAST_STATE_S1(_X_)                        ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BITS_LAST_STATE_S1(_X_)                           ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)) )
#define BIT_CLOSE_EQU_MODE_S1                             ( BIT(12) )
#define BITS_NUM_OF_SYMB_2_1ST_INT(_X_)                   ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_NUM_OF_SYMB_2_EQU(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_MODE1_SLOT1_REG */
#define BITS_INIT_STATE_S1(_X_)                           ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BITS_CHANNEL_LENGTH(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_MODE1_SLOT2_REG */
#define BITS_INIT_STATE(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_DBG_DATA_REG */
#define BITS_DBG_DATA(_X_)                                (_X_)

/* bits definitions for register REG_ASPEQUALIZER_EQU_RESUME_REG */
#define BIT_ASPEQ_RESUME218                               ( BIT(0) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_REQ_REG */
#define BITS_DBG_MEM(_X_)                                 ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BITS_DBG_ADDR(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_CURR_SYM_REG */
#define BITS_CURRENT_SYMBOL236(_X_)                       ( (_X_) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CURRENT_SYMBOL238(_X_)                       ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_NV_SLOT1_REG0 */
#define BITS_NV_0_S1(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_NV_SLOT1_REG1 */
#define BITS_5-BIT_COUNTER257(_X_)                        ( (_X_) << 14 & (BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BITS_ZERO_STATE_PM258(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_NV_SLOT2_REG0 */
#define BITS_NV0_S2(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_NV_SLOT2_REG1 */
#define BITS_5-BIT_COUNTER276(_X_)                        ( (_X_) << 14 & (BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BITS_ZERO_STATE_PM277(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_LLR_REG_S1 */
#define BITS_LLR3287(_X_)                                 ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_LLR2288(_X_)                                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_LLR1289(_X_)                                 ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_LLR00(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_ASPEQUALIZER_EQU_LLR_REG_S2 */
#define BITS_LLR3305(_X_)                                 ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_LLR2306(_X_)                                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_LLR1307(_X_)                                 ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_LLR0(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_ASPEQUALIZER_DUMMY_REGISTER */
#define BITS_ASPEQ_DUMMY320(_X_)                          (_X_)

#endif
