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


#ifndef __H_REGS_GPIOE_HEADFILE_H__
#define __H_REGS_GPIOE_HEADFILE_H__ __FILE__

#define	REGS_GPIOE

/* registers definitions for GPIOE */
#define REG_GPIOE_GPIOE_RER0                              ASR_ADDR(REGS_GPIOE_BASE, 0X0)/*GPIO Edge Read Register 0*/
#define REG_GPIOE_GPIOE_RER1                              ASR_ADDR(REGS_GPIOE_BASE, 0X4)/*GPIO Edge Read Register 1*/
#define REG_GPIOE_GPIOE_RER2                              ASR_ADDR(REGS_GPIOE_BASE, 0X8)/*GPIO Edge Read Register 2*/
#define REG_GPIOE_GPIOE_RER3                              ASR_ADDR(REGS_GPIOE_BASE, 0XC)/*GPIO Edge Read Register 3*/



/* bits definitions for register REG_GPIOE_GPIOE_RER0 */
#define BITS_EDGE_DET16(_X_)                              (_X_)

/* bits definitions for register REG_GPIOE_GPIOE_RER1 */
#define BITS_EDGE_DET23(_X_)                              (_X_)

/* bits definitions for register REG_GPIOE_GPIOE_RER2 */
#define BITS_EDGE_DET30(_X_)                              (_X_)

/* bits definitions for register REG_GPIOE_GPIOE_RER3 */
#define BITS_EDGE_DET37(_X_)                              (_X_)

#endif
