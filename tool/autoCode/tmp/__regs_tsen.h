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


#ifndef __H_REGS_TSEN_HEADFILE_H__
#define __H_REGS_TSEN_HEADFILE_H__ __FILE__

#define	REGS_TSEN

/* registers definitions for TSEN */
#define REG_TSEN_TSEN_PCTRL                               ASR_ADDR(REGS_TSEN_BASE, 0X0)/*TSEN PIN Control Register*/
#define REG_TSEN_TSEN_INT_CLR                             ASR_ADDR(REGS_TSEN_BASE, 0X4)/*TSEN INTERRUPT CLEAR Register*/
#define REG_TSEN_TSEN_INT_MASK                            ASR_ADDR(REGS_TSEN_BASE, 0X8)/*TSEN INTERRUPT MASK Register*/
#define REG_TSEN_TSEN_READ_DATA                           ASR_ADDR(REGS_TSEN_BASE, 0X14)/*TSEN READ DATA Register*/
#define REG_TSEN_TSEN_TIME_CTRL                           ASR_ADDR(REGS_TSEN_BASE, 0X18)/*TSEN TIME CONTROL Register*/



/* bits definitions for register REG_TSEN_TSEN_PCTRL */
#define BIT_TEMP_DATA_OUTPUT_MODE                         ( BIT(22) )
#define BITS_VTEST_SEL2(_X_)                              ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)) )
#define BITS_VTEST_SEL1(_X_)                              ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_TSEN_RAW_SEL                                  ( BIT(7) )
#define BITS_BJT_SEL(_X_)                                 ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_TSEN_ISO_EN                                   ( BIT(3) )
#define BIT_TEMP_MODE                                     ( BIT(3) )
#define BITS_INPUT_SEL(_X_)                               ( (_X_) << 1 & (BIT(1)|BIT(2)) )
#define BIT_EN_SENSOR                                     ( BIT(0) )

/* bits definitions for register REG_TSEN_TSEN_INT_CLR */
#define BIT_TSEN_INT_CLR                                  ( BIT(0) )

/* bits definitions for register REG_TSEN_TSEN_INT_MASK */
#define BIT_TSEN_INT_MASK                                 ( BIT(0) )

/* bits definitions for register REG_TSEN_TSEN_READ_DATA */
#define BITS_TSE_46(_X_)                                  ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_TSEN_READ_DATA(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_TSEN_TSEN_TIME_CTRL */
#define BITS_TSE_54(_X_)                                  ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_FILTER_PERIOD(_X_)                           ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_RST_ADC_CNT(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_WAIT_REF_CNT(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

#endif
