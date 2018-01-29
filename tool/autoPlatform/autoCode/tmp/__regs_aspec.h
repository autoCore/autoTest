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


#ifndef __H_REGS_ASPECIPH_HEADFILE_H__
#define __H_REGS_ASPECIPH_HEADFILE_H__ __FILE__

#define	REGS_ASPECIPH

/* registers definitions for ASPECIPH */
#define REG_ASPECIPH_CIP_SW_RESET                         ASR_ADDR(REGS_ASPECIPH_BASE, 0X04)/*E-Cipher Software Reset Register*/
#define REG_ASPECIPH_CIP_ALG_THR                          ASR_ADDR(REGS_ASPECIPH_BASE, 0X08)/*E-Cipher Algorithm Threshold Register*/
#define REG_ASPECIPH_CIP_ASPEC                            ASR_ADDR(REGS_ASPECIPH_BASE, 0X0C)/*E-Cipher ASPEC Enable Register*/
#define REG_ASPECIPH_CIP_DIRECTION                        ASR_ADDR(REGS_ASPECIPH_BASE, 0X10)/*E-Cipher Length Direction Register*/
#define REG_ASPECIPH_CIP_COUNT                            ASR_ADDR(REGS_ASPECIPH_BASE, 0X14)/*E-Cipher Count Register*/
#define REG_ASPECIPH_CIP_INPUT                            ASR_ADDR(REGS_ASPECIPH_BASE, 0X18)/*E-Cipher Input Register*/
#define REG_ASPECIPH_CIP_KC_XX                            ASR_ADDR(REGS_ASPECIPH_BASE, 0X1C)/*E-Cipher KC_xx Register*/
#define REG_ASPECIPH_CIP_RUNUP_CYCLES                     ASR_ADDR(REGS_ASPECIPH_BASE, 0X2C)/*E-Cipher Runup Register*/
#define REG_ASPECIPH_CIP_STIR_CYCLES                      ASR_ADDR(REGS_ASPECIPH_BASE, 0X30)/*E-Cipher Stirring Register*/
#define REG_ASPECIPH_CIP_INIT                             ASR_ADDR(REGS_ASPECIPH_BASE, 0X34)/*E-Cipher Init Register*/
#define REG_ASPECIPH_CIP_START                            ASR_ADDR(REGS_ASPECIPH_BASE, 0X38)/*E-Cipher Start Cipher Register*/
#define REG_ASPECIPH_CIP_DSP_DONE                         ASR_ADDR(REGS_ASPECIPH_BASE, 0X3C)/*E-Cipher DSP Done Register*/



/* bits definitions for register REG_ASPECIPH_CIP_SW_RESET */
#define BIT_ASPEC_SW_RESET17                              ( BIT(0) )

/* bits definitions for register REG_ASPECIPH_CIP_ALG_THR */
#define BITS_ASPEC_THRESHOLD29(_X_)                       ( (_X_) << 7 & (BIT(7)|BIT(8)|BIT(9)) )
#define BITS_ASPEC_ALGORITHM30(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_ASPECIPH_CIP_ASPEC */
#define BIT_ASPEC_INVERT_ON39                             ( BIT(1) )
#define BIT_ASPEC_ASPEC_EN40                              ( BIT(0) )

/* bits definitions for register REG_ASPECIPH_CIP_DIRECTION */
#define BIT_ASPEC_DIRECTION53                             ( BIT(20) )
#define BITS_ASPEC_LENGTH54(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for register REG_ASPECIPH_CIP_COUNT */
#define BITS_ASPEC_COUNT63(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )

/* bits definitions for register REG_ASPECIPH_CIP_INPUT */
#define BITS_ASPEC_INPUT71(_X_)                           (_X_)

/* bits definitions for register REG_ASPECIPH_CIP_KC_XX */
#define BITS_ASPEC_KC_L79(_X_)                            (_X_)

/* bits definitions for register REG_ASPECIPH_CIP_RUNUP_CYCLES */
#define BITS_ASPEC_RUNUP96(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_ASPECIPH_CIP_STIR_CYCLES */
#define BITS_ASPEC_STIRRING105(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_ASPECIPH_CIP_INIT */
#define BITS_ASPEC_INIT114(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_ASPECIPH_CIP_START */
#define BIT_ASPEC_START_CIPHER123                         ( BIT(0) )

/* bits definitions for register REG_ASPECIPH_CIP_DSP_DONE */
#define BIT_DSP_DONE                                      ( BIT(0) )

#endif
