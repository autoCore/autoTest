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


#ifndef __H_REGS_ASPAUX_HEADFILE_H__
#define __H_REGS_ASPAUX_HEADFILE_H__ __FILE__

#define	REGS_ASPAUX

/* registers definitions for ASPAUX */
#define REG_ASPAUX_MCTL                                   ASR_ADDR(REGS_ASPAUX_BASE, 0X0000)/*MCTL Control Register*/
#define REG_ASPAUX_SIHS0_1                                ASR_ADDR(REGS_ASPAUX_BASE, 0X0004)/*Second Interrupt High Select Mux 0/1 Register*/
#define REG_ASPAUX_SILS0_1                                ASR_ADDR(REGS_ASPAUX_BASE, 0X000C)/*Second Interrup Low Select Mux 0/1 Register*/
#define REG_ASPAUX_C1DM                                   ASR_ADDR(REGS_ASPAUX_BASE, 0X0014)/*DMA C1 Mux Control Register*/
#define REG_ASPAUX_DMAC1_EOCINH_WR                        ASR_ADDR(REGS_ASPAUX_BASE, 0X0018)/*GB DMAC 1 EOC Inhibit Register*/
#define REG_ASPAUX_COEL_ASP_CONTROL                       ASR_ADDR(REGS_ASPAUX_BASE, 0X001C)/*COEL ASP Control Register*/
#define REG_ASPAUX_COEL_ASP_DIGRF_GP1                     ASR_ADDR(REGS_ASPAUX_BASE, 0X0020)/*ASP_DIGRF_GP1 Register*/
#define REG_ASPAUX_COEL_ASP_DIGRF_GP2                     ASR_ADDR(REGS_ASPAUX_BASE, 0X0024)/*ASP_DIGRF_GP2 Register*/
#define REG_ASPAUX_COEL_ASP_DIGRF_GP3                     ASR_ADDR(REGS_ASPAUX_BASE, 0X0028)/*ASP_DIGRF_GP3 Register*/
#define REG_ASPAUX_COEL_ASP_DIGRF_GP4                     ASR_ADDR(REGS_ASPAUX_BASE, 0X002C)/*ASP_DIGRF_GP4 Register*/
#define REG_ASPAUX_COEL_ASP_DIGRF_CLKEN                   ASR_ADDR(REGS_ASPAUX_BASE, 0X0030)/*ASP_DIGRF Clock Enable Register*/
#define REG_ASPAUX_COEL_ASP_SPARE1                        ASR_ADDR(REGS_ASPAUX_BASE, 0X0034)/*ASP_SPARE1 Register*/
#define REG_ASPAUX_COEL_ASP_SPARE2                        ASR_ADDR(REGS_ASPAUX_BASE, 0X0038)/*ASP_SPARE2 Register*/



/* bits definitions for register REG_ASPAUX_MCTL */
#define BITS_IVG_14_CNTL(_X_)                             ( (_X_) << 5 & (BIT(5)|BIT(6)) )
#define BITS_IVG_7_CNTL(_X_)                              ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_ASPAUX_SIHS0_1 */
#define BITS_MUX22(_X_)                                   (_X_)

/* bits definitions for register REG_ASPAUX_SILS0_1 */
#define BITS_MUX29(_X_)                                   (_X_)

/* bits definitions for register REG_ASPAUX_C1DM */
#define BITS_C1DM_MUX(_X_)                                (_X_)

/* bits definitions for register REG_ASPAUX_DMAC1_EOCINH_WR */
#define BITS_DMAC1_EOCINH(_X_)                            (_X_)

/* bits definitions for register REG_ASPAUX_COEL_ASP_CONTROL */
#define BITS_COEL_APB_EXT_IF1:0(_X_)                      ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_ASPAUX_COEL_ASP_DIGRF_GP1 */
#define BIT_M1_TX_WB_LCT                                  ( BIT(0) )

/* bits definitions for register REG_ASPAUX_COEL_ASP_DIGRF_GP2 */
#define BIT_M1_TX_WB_WR_EN                                ( BIT(0) )

/* bits definitions for register REG_ASPAUX_COEL_ASP_DIGRF_GP3 */
#define BIT_M1_RX_HW_DATA_C_RDEN                          ( BIT(0) )

/* bits definitions for register REG_ASPAUX_COEL_ASP_DIGRF_GP4 */
#define BIT_TX_WB_SM_RE                                   ( BIT(0) )

/* bits definitions for register REG_ASPAUX_COEL_ASP_DIGRF_CLKEN */
#define BIT_COEL_ASP_DIGRF_CLKEN                          ( BIT(0) )

/* bits definitions for register REG_ASPAUX_COEL_ASP_SPARE1 */
#define BITS_DIGRF4_WB_TX_LCT(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_ASPAUX_COEL_ASP_SPARE2 */
#define BITS_TCU_TIME_SIG_SEL_15_14(_X_)                  ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_TCU_TIME_SIG_SEL_13_12(_X_)                  ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BITS_TCU_TIME_SIG_SEL_11_10(_X_)                  ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BITS_TCU_TIME_SIG_SEL_9_8(_X_)                    ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_TCU_TIME_SIG_SEL_7_6(_X_)                    ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_TCU_TIME_SIG_SEL_5_4(_X_)                    ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_TCU_TIME_SIG_SEL_3_2(_X_)                    ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_TCU_TIME_SIG_SEL_1_0(_X_)                    ( (_X_) & (BIT(0)|BIT(1)) )

#endif
