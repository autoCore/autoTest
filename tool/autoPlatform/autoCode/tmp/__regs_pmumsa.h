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
#define REG_MSA_DPCR                                      ASR_ADDR(REGS_MSA_BASE, 0X2000)/*MSA Power Control Register*/
#define REG_MSA_DPSR                                      ASR_ADDR(REGS_MSA_BASE, 0X2008)/*MSA Power Status Register*/
#define REG_MSA_DCGR                                      ASR_ADDR(REGS_MSA_BASE, 0X200C)/*MSA Clock Gating Register*/
#define REG_MSA_DPRR                                      ASR_ADDR(REGS_MSA_BASE, 0X2018)/*MSA Programmable Reset Register*/
#define REG_MSA_DRSR                                      ASR_ADDR(REGS_MSA_BASE, 0X201C)/*MSA Reset Status Register*/
#define REG_MSA_DMPRx                                     ASR_ADDR(REGS_MSA_BASE, 0X2100)/*MSA Module Power Register*/



/* bits definitions for register REG_MSA_DPCR */
#define BIT_MS_AXISDD14                                   ( BIT(31) )
#define BIT_MS_SLPEN16                                    ( BIT(29) )
#define BIT_MS_DTCMSD17                                   ( BIT(28) )
#define BIT_MS_DDRCORSD18                                 ( BIT(27) )
#define BIT_MS_APBSD19                                    ( BIT(26) )
#define BIT_MS_BBSD20                                     ( BIT(25) )
#define BIT_MS_VCTCXOSD22                                 ( BIT(19) )
#define BIT_MS_MSASLPEN24                                 ( BIT(14) )
#define BIT_MS_LDMA_MASK26                                ( BIT(3) )
#define BITS_DSPSD2:0(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_MSA_DPSR */
#define BIT_AXIAVL                                        ( BIT(31) )
#define BIT_APIDL                                         ( BIT(30) )
#define BIT_CPIDL                                         ( BIT(29) )

/* bits definitions for register REG_MSA_DCGR */
#define BIT_W_208M                                        ( BIT(31) )
#define BIT_W_312M                                        ( BIT(30) )
#define BIT_W_416M                                        ( BIT(29) )
#define BIT_G_LP52M                                       ( BIT(28) )
#define BIT_G_LP26M                                       ( BIT(27) )
#define BIT_G_104M                                        ( BIT(26) )
#define BIT_G_78M                                         ( BIT(25) )
#define BIT_G_52M                                         ( BIT(24) )
#define BIT_G_48MHZ                                       ( BIT(23) )
#define BIT_G_TWSI                                        ( BIT(22) )
#define BIT_G_HFI2S                                       ( BIT(21) )
#define BIT_G_26M                                         ( BIT(20) )
#define BIT_G_13M                                         ( BIT(19) )
#define BIT_G_6.5M                                        ( BIT(18) )
#define BIT_G_SUART                                       ( BIT(17) )
#define BIT_A_624M                                        ( BIT(15) )
#define BIT_A_PLL2                                        ( BIT(14) )
#define BIT_A_312M                                        ( BIT(13) )
#define BIT_A_104M                                        ( BIT(12) )
#define BIT_A_52M                                         ( BIT(11) )
#define BIT_A_48M                                         ( BIT(10) )
#define BIT_MS_AP_FUART67                                 ( BIT(8) )
#define BIT_AP_52M                                        ( BIT(7) )
#define BIT_MS_AP_TWSI69                                  ( BIT(6) )
#define BIT_AP_HFI2S                                      ( BIT(5) )
#define BIT_AP_26M                                        ( BIT(4) )
#define BIT_AP_13M                                        ( BIT(3) )
#define BIT_AP_6.5M                                       ( BIT(2) )
#define BIT_MS_AP_SUART74                                 ( BIT(1) )

/* bits definitions for register REG_MSA_DPRR */
#define BIT_MS_BBR83                                      ( BIT(3) )

/* bits definitions for register REG_MSA_DRSR */
#define BITS_MS_SWR92(_X_)                                ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_MOHR                                          ( BIT(3) )
#define BIT_MS_WDTR95                                     ( BIT(2) )
#define BIT_MS_EMR96                                      ( BIT(1) )
#define BIT_MS_POR97                                      ( BIT(0) )

/* bits definitions for register REG_MSA_DMPRx */
#define BIT_MSR                                           ( BIT(2) )
#define BIT_AG                                            ( BIT(1) )
#define BIT_MCE                                           ( BIT(0) )

#endif
