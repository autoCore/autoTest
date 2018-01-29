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


#ifndef __H_REGS_GPBEQUALIZER_HEADFILE_H__
#define __H_REGS_GPBEQUALIZER_HEADFILE_H__ __FILE__

#define	REGS_GPBEQUALIZER

/* registers definitions for GPBEQUALIZER */
#define REG_GPBEQUALIZER_EQU_DEST_IBU                     ASR_ADDR(REGS_GPBEQUALIZER_BASE, 0X0)/*Equalizer Input Buffer Register*/



/* bits definitions for register REG_GPBEQUALIZER_EQU_DEST_IBU */
#define BITS_Q_SYMBOL(_X_)                                ( (_X_) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_I_SYMBOL(_X_)                                ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

#endif
