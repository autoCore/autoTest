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


#ifndef __H_REGS_DIGGPBAUX_HEADFILE_H__
#define __H_REGS_DIGGPBAUX_HEADFILE_H__ __FILE__

#define	REGS_DIGGPBAUX

/* registers definitions for DIGGPBAUX */
#define REG_DIGGPBAUX_COEL_GPB_MON_MUX                    ASR_ADDR(REGS_DIGGPBAUX_BASE, 0X0000)/*Monitor Mux Register*/
#define REG_DIGGPBAUX_C2DM                                ASR_ADDR(REGS_DIGGPBAUX_BASE, 0X0004)/*C2 DMA Muxing Register*/
#define REG_DIGGPBAUX_DMAC2_EOCINH_WR                     ASR_ADDR(REGS_DIGGPBAUX_BASE, 0X0008)/*DMAC 2 EOC Inhibit Register*/
#define REG_DIGGPBAUX_COEL_GPB_CONTROL                    ASR_ADDR(REGS_DIGGPBAUX_BASE, 0X000C)/*GPB Control Register*/
#define REG_DIGGPBAUX_COEL_GPB_AFE_CONTROL                ASR_ADDR(REGS_DIGGPBAUX_BASE, 0X0010)/*GPB AFE Control Register*/
#define REG_DIGGPBAUX_WB_AFE_SMP_CLK_CFG                  ASR_ADDR(REGS_DIGGPBAUX_BASE, 0X0014)/*WB AFE Sample Clock Configuration Register*/
#define REG_DIGGPBAUX_GPB_COEL_SPARE1                     ASR_ADDR(REGS_DIGGPBAUX_BASE, 0X0018)/*GPB Coel Spare1 Register*/
#define REG_DIGGPBAUX_GPB_COEL_SPARE2                     ASR_ADDR(REGS_DIGGPBAUX_BASE, 0X001C)/*GPB Coel Spare2 Register*/



/* bits definitions for register REG_DIGGPBAUX_COEL_GPB_MON_MUX */
#define BITS_SPARE1_TP_SEL(_X_)                           ( (_X_) << 13 & (BIT(13)|BIT(14)) )
#define BIT_SW_JTAG                                       ( BIT(12) )
#define BITS_SW_MON_MUX3(_X_)                             ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BITS_SW_MON_MUX2(_X_)                             ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)) )
#define BITS_SW_MON_MUX1(_X_)                             ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)) )
#define BITS_SW_MON_MUX0(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_DIGGPBAUX_C2DM */
#define BITS_C2DM(_X_)                                    (_X_)

/* bits definitions for register REG_DIGGPBAUX_DMAC2_EOCINH_WR */
#define BITS_DMAC2_EOCINH_WR(_X_)                         (_X_)

/* bits definitions for register REG_DIGGPBAUX_COEL_GPB_CONTROL */
#define BITS_EXT_GPB_CYCLE(_X_)                           ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_EXT_GPB_CLK                                   ( BIT(2) )
#define BITS_EXT_GPB_MODE(_X_)                            ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_DIGGPBAUX_COEL_GPB_AFE_CONTROL */
#define BIT_WB_PAD_CONTROL_OUT_SEL                        ( BIT(13) )
#define BIT_WB_PAD_CONTROL_IN_SEL                         ( BIT(12) )
#define BIT_WB_PAD_IQ_RX_SEL                              ( BIT(11) )
#define BIT_WB_PAD_IQ_TX_SEL                              ( BIT(10) )
#define BIT_LEGACY_DIGRF_GILINT_SELECT                    ( BIT(0) )
#define BIT_AFE_CONTROL_SPARE                             ( BIT(0) )
#define BIT_DIG_ANA_INT                                   ( BIT(3) )
#define BIT_AFE_TEST_MODE                                 ( BIT(0) )
#define BIT_SW_RESET_AFE                                  ( BIT(0) )

/* bits definitions for register REG_DIGGPBAUX_WB_AFE_SMP_CLK_CFG */
#define BITS_DIGGP_GSRAM_WTC67(_X_)                       ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BITS_DIGGP_GSRAM_RTC68(_X_)                       ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_DIGGP_GSRAM_ROM_RTC_REF70(_X_)               ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BITS_DIGGP_GSRAM_ROM_RTC71(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_DIGGPBAUX_GPB_COEL_SPARE1 */
#define BIT_SEL_LSM_UART_TXMSG1_TRIG                      ( BIT(5) )
#define BIT_SEL_LSM_UART_TXMSG2_TRIG                      ( BIT(4) )
#define BIT_MASK_FB_TX_TIME_SIG_SCC                       ( BIT(3) )
#define BIT_MASK_FB_TX_TIME_SIG_PCC                       ( BIT(2) )
#define BIT_MASK_FB_RX_TIME_SIG_SCC                       ( BIT(1) )
#define BIT_MASK_FB_RX_TIME_SIG_PCC                       ( BIT(0) )

/* bits definitions for register REG_DIGGPBAUX_GPB_COEL_SPARE2 */
#define BIT_FB_ENABLE_30P72M                              ( BIT(15) )
#define BITS_WTCRTC_DIGRF4(_X_)                           ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_GSM_SW_RSTN_GPB                               ( BIT(1) )
#define BIT_FB_SLEEP_EN                                   ( BIT(0) )

#endif
