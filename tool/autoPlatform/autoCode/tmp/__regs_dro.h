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


#ifndef __H_REGS_DRO_CONTROLIS_HEADFILE_H__
#define __H_REGS_DRO_CONTROLIS_HEADFILE_H__ __FILE__

#define	REGS_DRO_CONTROLIS

/* registers definitions for DRO_CONTROLIS */
#define REG_DRO_CONTROLIS_DRO_CTRL                        ASR_ADDR(REGS_DRO_CONTROLIS_BASE, 0X00)/*DRO control register*/
#define REG_DRO_CONTROLIS_DRO_CNT_TIME                    ASR_ADDR(REGS_DRO_CONTROLIS_BASE, 0X4)/*DRO runtime length register*/
#define REG_DRO_CONTROLIS_DRO_LVT                         ASR_ADDR(REGS_DRO_CONTROLIS_BASE, 0X8)/*DRO LVT Value  Register*/
#define REG_DRO_CONTROLIS_DRO_HVT                         ASR_ADDR(REGS_DRO_CONTROLIS_BASE, 0XC)/*DRO HVT Value  Register*/
#define REG_DRO_CONTROLIS_DRO_SVT                         ASR_ADDR(REGS_DRO_CONTROLIS_BASE, 0X10)/*DRO SVT Value  Register*/



/* bits definitions for register REG_DRO_CONTROLIS_DRO_CTRL */
#define BIT_DRO_INT_MASK                                  ( BIT(1) )
#define BIT_DRO_SW_EN                                     ( BIT(0) )

/* bits definitions for register REG_DRO_CONTROLIS_DRO_CNT_TIME */
#define BIT_DRO_DONE                                      ( BIT(31) )
#define BITS_DRO_CNT_TIME(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DRO_CONTROLIS_DRO_LVT */
#define BITS_DRO_LVT_TOP_1(_X_)                           ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_DRO_LVT_TOP_0(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DRO_CONTROLIS_DRO_HVT */
#define BITS_DRO_HVT_TOP_1(_X_)                           ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_DRO_HVT_TOP_0(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DRO_CONTROLIS_DRO_SVT */
#define BITS_DRO_SVT_TOP_1(_X_)                           ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_DRO_SVT_TOP_0(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

#endif
