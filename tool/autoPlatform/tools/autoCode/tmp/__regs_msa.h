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


#ifndef __H_REGS_MSA_HEADFILE_H__
#define __H_REGS_MSA_HEADFILE_H__ __FILE__

#define	REGS_MSA

/* registers definitions for MSA */
#define REG_MSA_SMMLR                                     ASR_ADDR(REGS_MSA_BASE, 0X0)/*System MMR Maximum Latency Register*/
#define REG_MSA_SDTESR                                    ASR_ADDR(REGS_MSA_BASE, 0X4)/*System Data Transaction Error Status Register*/
#define REG_MSA_SDTEAR                                    ASR_ADDR(REGS_MSA_BASE, 0X8)/*System Data Transaction Error Address Register*/
#define REG_MSA_PBRCR                                     ASR_ADDR(REGS_MSA_BASE, 0X1000)/*Peripheral Bus Retry Control Register*/
#define REG_MSA_PBDESR                                    ASR_ADDR(REGS_MSA_BASE, 0X1004)/*Peripheral Bus DMA Error Status Register*/
#define REG_MSA_AWCR                                      ASR_ADDR(REGS_MSA_BASE, 0X2000)/*ASPEC Wait Count Register*/
#define REG_MSA_AWTCR                                     ASR_ADDR(REGS_MSA_BASE, 0X2004)/*ASPEC Wait Timeout Control Register*/
#define REG_MSA_AAHCR                                     ASR_ADDR(REGS_MSA_BASE, 0X2008)/*ASPEC Access Hold Control Register*/



/* bits definitions for register REG_MSA_SMMLR */
#define BITS_SMMAX(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_MSA_SDTESR */
#define BIT_MS_RW32                                       ( BIT(3) )
#define BITS_SDET(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_MSA_SDTEAR */
#define BITS_SDTEAR(_X_)                                  (_X_)

/* bits definitions for register REG_MSA_PBRCR */
#define BIT_RTODIS                                        ( BIT(31) )
#define BITS_RC(_X_)                                      ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_MS_RP64(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_MSA_PBDESR */
#define BITS_PBTP(_X_)                                    ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_PBDET(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_MSA_AWCR */
#define BITS_IWC(_X_)                                     ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_EWC(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_MSA_AWTCR */
#define BITS_EWTO(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_MSA_AAHCR */
#define BITS_AH(_X_)                                      ( (_X_) & (BIT(0)|BIT(1)) )

#endif
