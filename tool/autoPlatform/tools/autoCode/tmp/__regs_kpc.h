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


#ifndef __H_REGS_KPC_HEADFILE_H__
#define __H_REGS_KPC_HEADFILE_H__ __FILE__

#define	REGS_KPC

/* registers definitions for KPC */
#define REG_KPC_KPC_PC                                    ASR_ADDR(REGS_KPC_BASE, 0X0)/*Keypad Control Register*/
#define REG_KPC_KPC_DK                                    ASR_ADDR(REGS_KPC_BASE, 0X08)/*Keypad Direct Key Register*/
#define REG_KPC_KPC_REC                                   ASR_ADDR(REGS_KPC_BASE, 0X10)/*Keypad Rotary Encoder Count Register*/
#define REG_KPC_KPC_MK                                    ASR_ADDR(REGS_KPC_BASE, 0X18)/*Keypad Matrix Key Register*/
#define REG_KPC_KPC_AS                                    ASR_ADDR(REGS_KPC_BASE, 0X20)/*Keypad Automatic Scan Register*/
#define REG_KPC_KPC_ASMKP0                                ASR_ADDR(REGS_KPC_BASE, 0X28)/*Keypad Automatic Scan Multiple Keypress Register 0*/
#define REG_KPC_KPC_ASMKP1                                ASR_ADDR(REGS_KPC_BASE, 0X30)/*Keypad Automatic Scan Multiple Keypress Register 1*/
#define REG_KPC_KPC_ASMKP2                                ASR_ADDR(REGS_KPC_BASE, 0X38)/*Keypad Automatic Scan Multiple Keypress Register 2*/
#define REG_KPC_KPC_ASMKP3                                ASR_ADDR(REGS_KPC_BASE, 0X40)/*Keypad Automatic Scan Multiple Keypress Register 3*/
#define REG_KPC_KPC_KDI                                   ASR_ADDR(REGS_KPC_BASE, 0X48)/*Keypad Key Debounce Interval Register*/



/* bits definitions for register REG_KPC_KPC_PC */
#define BIT_AS                                            ( BIT(30) )
#define BIT_ASACT                                         ( BIT(29) )
#define BITS_MKRN(_X_)                                    ( (_X_) << 26 & (BIT(26)|BIT(27)|BIT(28)) )
#define BITS_MKCN(_X_)                                    ( (_X_) << 23 & (BIT(23)|BIT(24)|BIT(25)) )
#define BIT_MI                                            ( BIT(22) )
#define BIT_IMKP                                          ( BIT(21) )
#define BIT_MS7                                           ( BIT(20) )
#define BIT_MS6                                           ( BIT(19) )
#define BIT_MS5                                           ( BIT(18) )
#define BIT_MS4                                           ( BIT(17) )
#define BIT_MS3                                           ( BIT(16) )
#define BIT_MS2                                           ( BIT(15) )
#define BIT_MS1                                           ( BIT(14) )
#define BIT_MS0                                           ( BIT(13) )
#define BIT_ME                                            ( BIT(12) )
#define BIT_KP_MIE47                                      ( BIT(11) )
#define BIT_DK_DEB_SEL                                    ( BIT(9) )
#define BITS_DN(_X_)                                      ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_DI                                            ( BIT(5) )
#define BIT_RE_ZERO_DEB                                   ( BIT(4) )
#define BIT_REE1                                          ( BIT(3) )
#define BIT_REE0                                          ( BIT(2) )
#define BIT_DE                                            ( BIT(1) )
#define BIT_DIE                                           ( BIT(0) )

/* bits definitions for register REG_KPC_KPC_DK */
#define BIT_DKP                                           ( BIT(31) )
#define BIT_DK7                                           ( BIT(7) )
#define BIT_DK6                                           ( BIT(6) )
#define BIT_DK5                                           ( BIT(5) )
#define BIT_DK4                                           ( BIT(4) )
#define BIT_RB1_DK3                                       ( BIT(3) )
#define BIT_RA1_DK2                                       ( BIT(2) )
#define BIT_RB0_DK1                                       ( BIT(1) )
#define BIT_RA0_DK0                                       ( BIT(0) )

/* bits definitions for register REG_KPC_KPC_REC */
#define BIT_OF1                                           ( BIT(31) )
#define BIT_UF1                                           ( BIT(30) )
#define BITS_RE_COUNT1(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_OF0                                           ( BIT(15) )
#define BIT_UF0                                           ( BIT(14) )
#define BITS_RE_COUNT0(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_KPC_KPC_MK */
#define BIT_MKP                                           ( BIT(31) )
#define BIT_MR7                                           ( BIT(7) )
#define BIT_MR6                                           ( BIT(6) )
#define BIT_MR5                                           ( BIT(5) )
#define BIT_MR4                                           ( BIT(4) )
#define BIT_MR3                                           ( BIT(3) )
#define BIT_MR2                                           ( BIT(2) )
#define BIT_MR1                                           ( BIT(1) )
#define BIT_MR0                                           ( BIT(0) )

/* bits definitions for register REG_KPC_KPC_AS */
#define BIT_SO123                                         ( BIT(31) )
#define BITS_MUKP(_X_)                                    ( (_X_) << 26 & (BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BITS_KP_RP126(_X_)                                ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_CP(_X_)                                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_KPC_KPC_ASMKP0 */
#define BIT_SO152                                         ( BIT(31) )
#define BITS_MKC1(_X_)                                    ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_MKC0(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_KPC_KPC_ASMKP1 */
#define BIT_SO163                                         ( BIT(31) )
#define BITS_MKC3(_X_)                                    ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_MKC2(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_KPC_KPC_ASMKP2 */
#define BIT_SO174                                         ( BIT(31) )
#define BITS_MKC5(_X_)                                    ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_MKC4(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_KPC_KPC_ASMKP3 */
#define BIT_SO185                                         ( BIT(31) )
#define BITS_MKC7(_X_)                                    ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_MKC6(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_KPC_KPC_KDI */
#define BITS_DIRECT_KEY_DEBOUNCE_INTERVAL(_X_)            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_MATRIX_KEY_DEBOUNCE_INTERVAL(_X_)            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

#endif
