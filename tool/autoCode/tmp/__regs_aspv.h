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


#ifndef __H_REGS_ASPVITERBI_HEADFILE_H__
#define __H_REGS_ASPVITERBI_HEADFILE_H__ __FILE__

#define	REGS_ASPVITERBI

/* registers definitions for ASPVITERBI */
#define REG_ASPVITERBI_VD_SW_RST                          ASR_ADDR(REGS_ASPVITERBI_BASE, 0X00)/*Viterbi Decoder SW Reset Register*/
#define REG_ASPVITERBI_VD_CTL                             ASR_ADDR(REGS_ASPVITERBI_BASE, 0X04)/*Viterbi Decoder Control Register*/
#define REG_ASPVITERBI_VD_BSZ                             ASR_ADDR(REGS_ASPVITERBI_BASE, 0X08)/*Viterbi Decoder Block Size and Last Word Register*/
#define REG_ASPVITERBI_VD_MPE01                           ASR_ADDR(REGS_ASPVITERBI_BASE, 0X0C)/*Viterbi Decoder Mask Polynomial (C0/C1) Register*/
#define REG_ASPVITERBI_VD_MPE23                           ASR_ADDR(REGS_ASPVITERBI_BASE, 0X10)/*Viterbi Decoder Mask Polynomial (C2/C3) Register*/
#define REG_ASPVITERBI_VD_RSCM                            ASR_ADDR(REGS_ASPVITERBI_BASE, 0X14)/*Viterbi Decoder RSC Mask Polynomial Register*/
#define REG_ASPVITERBI_VD_CFL                             ASR_ADDR(REGS_ASPVITERBI_BASE, 0X18)/*Viterbi Decoder CRC First and Last Bits Register*/
#define REG_ASPVITERBI_VD_CRCI                            ASR_ADDR(REGS_ASPVITERBI_BASE, 0X1C)/*Viterbi Decoder CRC Initial Value Register*/
#define REG_ASPVITERBI_VD_CRCM                            ASR_ADDR(REGS_ASPVITERBI_BASE, 0X20)/*Viterbi Decoder CRC Mask Polynomial Register*/
#define REG_ASPVITERBI_VD_TBST                            ASR_ADDR(REGS_ASPVITERBI_BASE, 0X24)/*Viterbi Decoder TraceBack Start and Index Register*/
#define REG_ASPVITERBI_VD_OBRA                            ASR_ADDR(REGS_ASPVITERBI_BASE, 0X28)/*Viterbi Decoder Random Access Load Address Register*/
#define REG_ASPVITERBI_VD_RSM                             ASR_ADDR(REGS_ASPVITERBI_BASE, 0X2C)/*Viterbi Decoder Resume Register*/
#define REG_ASPVITERBI_VD_IBR                             ASR_ADDR(REGS_ASPVITERBI_BASE, 0X30)/*Viterbi Decoder Input Buffer Read Register*/
#define REG_ASPVITERBI_VD_MRLR                            ASR_ADDR(REGS_ASPVITERBI_BASE, 0X34)/*Viterbi Decoder Most/Least Reliable State Metric Register*/
#define REG_ASPVITERBI_VD_MRIDZSM                         ASR_ADDR(REGS_ASPVITERBI_BASE, 0X38)/*Viterbi Decoder Most Reliable State Metric Index and State Zero Register*/
#define REG_ASPVITERBI_VD_MDL                             ASR_ADDR(REGS_ASPVITERBI_BASE, 0X3C)/*Viterbi Decoder Modulo Wrap-Around Results Register*/
#define REG_ASPVITERBI_VD_CRCR                            ASR_ADDR(REGS_ASPVITERBI_BASE, 0X40)/*Viterbi Decoder CRC Result Register*/
#define REG_ASPVITERBI_VD_STATUS                          ASR_ADDR(REGS_ASPVITERBI_BASE, 0X44)/*Viterbi Decoder Status Register*/
#define REG_ASPVITERBI_VD_ASPEC_OB_START                  ASR_ADDR(REGS_ASPVITERBI_BASE, 0X80)/*Viterbi Decoder Output Buffer on ASPEC Register*/



/* bits definitions for register REG_ASPVITERBI_VD_SW_RST */
#define BIT_VD_SW_RST                                     ( BIT(0) )

/* bits definitions for register REG_ASPVITERBI_VD_CTL */
#define BIT_GPB_BIT_ORDER                                 ( BIT(14) )
#define BIT_DEBUG_MODE                                    ( BIT(13) )
#define BITS_TRACEBACK_EMPTY_(_X_)                        ( (_X_) << 11 & (BIT(11)|BIT(12)) )
#define BIT_GPB_CLOCK_ENABLE                              ( BIT(10) )
#define BIT_CRC_BIT_ORDER                                 ( BIT(9) )
#define BIT_TRACEBACK_START_INDEX35                       ( BIT(8) )
#define BIT_ASPVI_HW_MODE36                               ( BIT(7) )
#define BIT_CONTINUOUS_MODE                               ( BIT(6) )
#define BIT_FORCE_ZERO_STATE                              ( BIT(5) )
#define BIT_CRC_EN                                        ( BIT(4) )
#define BITS_CONSTRAINT(_X_)                              ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_ASPVI_RATE41(_X_)                            ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_ASPVITERBI_VD_BSZ */
#define BITS_LAST_WORD_INDEX(_X_)                         ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )
#define BITS_ASPVI_BLOCK_SIZE53(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_ASPVITERBI_VD_MPE01 */
#define BITS_C1_MASK_POLYNOMIAL(_X_)                      ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BITS_C0_MASK_POLYNOMIAL(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for register REG_ASPVITERBI_VD_MPE23 */
#define BITS_C3_MASK_POLYNOMIAL(_X_)                      ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BITS_C2_MASK_POLYNOMIAL(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for register REG_ASPVITERBI_VD_RSCM */
#define BITS_RSC_MASK(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for register REG_ASPVITERBI_VD_CFL */
#define BITS_LAST_BIT_INDEX(_X_)                          ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BITS_FIRST_BIT_INDEX(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_ASPVITERBI_VD_CRCI */
#define BITS_CRC_INITIAL_VALUE(_X_)                       (_X_)

/* bits definitions for register REG_ASPVITERBI_VD_CRCM */
#define BITS_CRC_MASK_POLYNOMIAL(_X_)                     (_X_)

/* bits definitions for register REG_ASPVITERBI_VD_TBST */
#define BITS_TRACEBACK_START_INDEX120(_X_)                ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_TRACEBACK_START_SYMBOL(_X_)                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_ASPVITERBI_VD_OBRA */
#define BITS_INPUT_BUFFER_READ_ADDRESS(_X_)               ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BITS_OUTPUT_BUFFER_READ_ADDRESS(_X_)              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_ASPVITERBI_VD_RSM */
#define BIT_CRC_RESTART                                   ( BIT(2) )
#define BIT_RECALCULATE                                   ( BIT(1) )
#define BIT_ASPVI_RESUME147                               ( BIT(0) )

/* bits definitions for register REG_ASPVITERBI_VD_IBR */
#define BITS_INPUT_BUFFER_READ_DATA(_X_)                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for register REG_ASPVITERBI_VD_MRLR */
#define BITS_LEAST_RELIABLE(_X_)                          ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BITS_MOST_RELIABLE(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_ASPVITERBI_VD_MRIDZSM */
#define BITS_ZERO_STATE_METRIC(_X_)                       ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BITS_MOST_RELIABLE_INDEX(_X_)                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_ASPVITERBI_VD_MDL */
#define BITS_MODULO(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ASPVITERBI_VD_CRCR */
#define BITS_CRC_RESULT(_X_)                              (_X_)

/* bits definitions for register REG_ASPVITERBI_VD_STATUS */
#define BIT_ASPVI_STATUS210                               ( BIT(0) )

/* bits definitions for register REG_ASPVITERBI_VD_ASPEC_OB_START */
#define BITS_OUTPUT_BUFFER_ON_ASPEC(_X_)                  (_X_)

#endif
