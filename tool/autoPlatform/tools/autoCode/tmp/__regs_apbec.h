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


#ifndef __H_REGS_APBECIPH_HEADFILE_H__
#define __H_REGS_APBECIPH_HEADFILE_H__ __FILE__

#define	REGS_APBECIPH

/* registers definitions for APBECIPH */
#define REG_APBECIPH_AR_CIP_OB                            ASR_ADDR(REGS_APBECIPH_BASE, 0X00)/*E-Cipher Output Buffer Register*/
#define REG_APBECIPH_AR_CIP_SW_RESET                      ASR_ADDR(REGS_APBECIPH_BASE, 0X1004)/*Software Reset Register*/
#define REG_APBECIPH_AR_CIP_ALG_THR                       ASR_ADDR(REGS_APBECIPH_BASE, 0X1008)/*Algorithm Threshold Register*/
#define REG_APBECIPH_AR_CIP_ASPEC                         ASR_ADDR(REGS_APBECIPH_BASE, 0X100C)/*E-Cipher ASPEC Enable Register*/
#define REG_APBECIPH_AR_CIP_DIRECTION                     ASR_ADDR(REGS_APBECIPH_BASE, 0X1010)/*E-Cipher Length Direction Register*/
#define REG_APBECIPH_AR_CIP_COUNT                         ASR_ADDR(REGS_APBECIPH_BASE, 0X1014)/*E-Cipher Count Register*/
#define REG_APBECIPH_AR_CIP_INPUT                         ASR_ADDR(REGS_APBECIPH_BASE, 0X1018)/*E-Cipher Input Register*/
#define REG_APBECIPH_AR_CIP_KC_XX                         ASR_ADDR(REGS_APBECIPH_BASE, 0X101C)/*E-Cipher Key Register*/
#define REG_APBECIPH_AR_CIP_RUNUP_CYCLES                  ASR_ADDR(REGS_APBECIPH_BASE, 0X102C)/*E-Cipher Runup Register*/
#define REG_APBECIPH_AR_CIP_STIR_CYCLES                   ASR_ADDR(REGS_APBECIPH_BASE, 0X1030)/*E-Cipher Stirring Register*/
#define REG_APBECIPH_AR_CIP_INIT                          ASR_ADDR(REGS_APBECIPH_BASE, 0X1034)/*E-Cipher Init Register*/
#define REG_APBECIPH_AR_CIP_START                         ASR_ADDR(REGS_APBECIPH_BASE, 0X1038)/*E-Cipher Start Cipher Register*/
#define REG_APBECIPH_AR_CIP_DSP_DONE                      ASR_ADDR(REGS_APBECIPH_BASE, 0X103C)/*E-Cipher ARM Done Register*/
#define REG_APBECIPH_AR_CIP_DMA_ACK_BYP_CTRL              ASR_ADDR(REGS_APBECIPH_BASE, 0X1050)/*E-Cipher DMA_ACK, Bypass Control Register*/
#define REG_APBECIPH_AR_CIP_OB_FOR_DMA                    ASR_ADDR(REGS_APBECIPH_BASE, 0X100)/*E-Cipher Output Buffer DMA Register*/



/* bits definitions for register REG_APBECIPH_AR_CIP_OB */
#define BITS_APBEC_OUTPUT_BUFFER16(_X_)                   (_X_)

/* bits definitions for register REG_APBECIPH_AR_CIP_SW_RESET */
#define BIT_APBEC_SW_RESET25                              ( BIT(0) )

/* bits definitions for register REG_APBECIPH_AR_CIP_ALG_THR */
#define BITS_APBEC_THRESHOLD37(_X_)                       ( (_X_) << 7 & (BIT(7)|BIT(8)|BIT(9)) )
#define BITS_APBEC_ALGORITHM38(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_APBECIPH_AR_CIP_ASPEC */
#define BIT_APBEC_INVERT_ON47                             ( BIT(1) )
#define BIT_APBEC_ASPEC_EN48                              ( BIT(0) )

/* bits definitions for register REG_APBECIPH_AR_CIP_DIRECTION */
#define BIT_APBEC_DIRECTION61                             ( BIT(20) )
#define BITS_APBEC_LENGTH62(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for register REG_APBECIPH_AR_CIP_COUNT */
#define BITS_APBEC_COUNT71(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )

/* bits definitions for register REG_APBECIPH_AR_CIP_INPUT */
#define BITS_APBEC_INPUT79(_X_)                           (_X_)

/* bits definitions for register REG_APBECIPH_AR_CIP_KC_XX */
#define BITS_APBEC_KC_L87(_X_)                            (_X_)

/* bits definitions for register REG_APBECIPH_AR_CIP_RUNUP_CYCLES */
#define BITS_APBEC_RUNUP104(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_APBECIPH_AR_CIP_STIR_CYCLES */
#define BITS_APBEC_STIRRING113(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_APBECIPH_AR_CIP_INIT */
#define BITS_APBEC_INIT122(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_APBECIPH_AR_CIP_START */
#define BIT_APBEC_START_CIPHER131                         ( BIT(0) )

/* bits definitions for register REG_APBECIPH_AR_CIP_DSP_DONE */
#define BIT_ARM_DONE                                      ( BIT(0) )

/* bits definitions for register REG_APBECIPH_AR_CIP_DMA_ACK_BYP_CTRL */
#define BIT_DMA_ACK_BYPASS                                ( BIT(8) )
#define BITS_DMA_READ_ACCESSES(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_APBECIPH_AR_CIP_OB_FOR_DMA */
#define BITS_OUTPUT_BUFFER_DMA(_X_)                       (_X_)

#endif
