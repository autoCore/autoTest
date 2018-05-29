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


#ifndef __H_REGS_GPBVITERBI_HEADFILE_H__
#define __H_REGS_GPBVITERBI_HEADFILE_H__ __FILE__

#define	REGS_GPBVITERBI

/* registers definitions for GPBVITERBI */
#define REG_GPBVITERBI_VD_OB                              ASR_ADDR(REGS_GPBVITERBI_BASE, 0X0)/*Viterbi Output Buffer on GPB Register*/
#define REG_GPBVITERBI_VD_IB_RD                           ASR_ADDR(REGS_GPBVITERBI_BASE, 0X04)/*Viterbi Decoder Input Buffer on GPB Register*/
#define REG_GPBVITERBI_VD_IB                              ASR_ADDR(REGS_GPBVITERBI_BASE, 0X40)/*Viterbi Decoder Input Buffer Write Register*/



/* bits definitions for register REG_GPBVITERBI_VD_OB */
#define BITS_OUTPUT_BUFFER_ON_GPB(_X_)                    (_X_)

/* bits definitions for register REG_GPBVITERBI_VD_IB_RD */
#define BITS_INPUT_BUFFER_READ(_X_)                       (_X_)

/* bits definitions for register REG_GPBVITERBI_VD_IB */
#define BITS_VD_IB(_X_)                                   (_X_)

#endif
