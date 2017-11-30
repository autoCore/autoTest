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


#ifndef __H_REGS_SFO_HEADFILE_H__
#define __H_REGS_SFO_HEADFILE_H__ __FILE__

#define	REGS_SFO

/* registers definitions for SFO */
#define REG_SFO_SFO_FUSE_OVR_REG0                         ASR_ADDR(REGS_SFO_BASE, 0X0)/*Fuse Override Register 0*/
#define REG_SFO_SFO_FUSE_OVR_REG1                         ASR_ADDR(REGS_SFO_BASE, 0X4)/*Fuse Override Register 1*/
#define REG_SFO_SFO_FUSE_OVR_REG2                         ASR_ADDR(REGS_SFO_BASE, 0X8)/*Fuse Override Register 2*/
#define REG_SFO_SFO_FUSE_OVR_REG3                         ASR_ADDR(REGS_SFO_BASE, 0XC)/*Fuse Override Register 3*/
#define REG_SFO_SFO_FUSE_OVR_REG4                         ASR_ADDR(REGS_SFO_BASE, 0X10)/*Fuse Override Register 4*/
#define REG_SFO_SFO_FUSE_OVR_REG5                         ASR_ADDR(REGS_SFO_BASE, 0X14)/*Fuse Override Register 5*/



/* bits definitions for register REG_SFO_SFO_FUSE_OVR_REG0 */
#define BITS_APP_FUSE_OVR0(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SFO_SFO_FUSE_OVR_REG1 */
#define BITS_APP_FUSE_OVR1(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SFO_SFO_FUSE_OVR_REG2 */
#define BITS_APP_FUSE_OVR2(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SFO_SFO_FUSE_OVR_REG3 */
#define BITS_APP_FUSE_OVR3(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SFO_SFO_FUSE_OVR_REG4 */
#define BIT_AIB_FUSE_OVR                                  ( BIT(15) )
#define BITS_APP_FUSE_OVR4(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for register REG_SFO_SFO_FUSE_OVR_REG5 */
#define BITS_TOP_FUSE_OVR(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

#endif
