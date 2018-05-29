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


#ifndef __H_REGS_SSP0SSP2_HEADFILE_H__
#define __H_REGS_SSP0SSP2_HEADFILE_H__ __FILE__

#define	REGS_SSP0,SSP2

/* registers definitions for SSP0SSP2 */
#define REG_SSP0_SSP_TOP_CTRL                             ASR_ADDR(REGS_SSP0_BASE, 0X00)/*SSP Top Control Register*/
#define REG_SSP2_SSP_TOP_CTRL                             ASR_ADDR(REGS_SSP2_BASE, 0X00)/*SSP Top Control Register*/
#define REG_SSP0_SSP_FIFO_CTRL                            ASR_ADDR(REGS_SSP0_BASE, 0X04)/*SSP FIFO Control Register*/
#define REG_SSP2_SSP_FIFO_CTRL                            ASR_ADDR(REGS_SSP2_BASE, 0X04)/*SSP FIFO Control Register*/
#define REG_SSP0_SSP_INT_EN                               ASR_ADDR(REGS_SSP0_BASE, 0X08)/*SSP Interrupt Enable Register*/
#define REG_SSP2_SSP_INT_EN                               ASR_ADDR(REGS_SSP2_BASE, 0X08)/*SSP Interrupt Enable Register*/
#define REG_SSP0_SSP_TO                                   ASR_ADDR(REGS_SSP0_BASE, 0X0C)/*SSP Time Out Register*/
#define REG_SSP2_SSP_TO                                   ASR_ADDR(REGS_SSP2_BASE, 0X0C)/*SSP Time Out Register*/
#define REG_SSP0_SSP_DATAR                                ASR_ADDR(REGS_SSP0_BASE, 0X10)/*SSP Data Register*/
#define REG_SSP2_SSP_DATAR                                ASR_ADDR(REGS_SSP2_BASE, 0X10)/*SSP Data Register*/
#define REG_SSP0_SSP_STATUS                               ASR_ADDR(REGS_SSP0_BASE, 0X14)/*SSP Status Register*/
#define REG_SSP2_SSP_STATUS                               ASR_ADDR(REGS_SSP2_BASE, 0X14)/*SSP Status Register*/
#define REG_SSP0_SSP_PSP_CTRL                             ASR_ADDR(REGS_SSP0_BASE, 0X18)/*SSP Programmable Serial Protocol Control Register*/
#define REG_SSP2_SSP_PSP_CTRL                             ASR_ADDR(REGS_SSP2_BASE, 0X18)/*SSP Programmable Serial Protocol Control Register*/
#define REG_SSP0_SSP_NET_WORK_CTRL                        ASR_ADDR(REGS_SSP0_BASE, 0X1C)/*SSP Net Work Control Register*/
#define REG_SSP2_SSP_NET_WORK_CTRL                        ASR_ADDR(REGS_SSP2_BASE, 0X1C)/*SSP Net Work Control Register*/
#define REG_SSP0_SSP_NET_WORK_STATUS                      ASR_ADDR(REGS_SSP0_BASE, 0X20)/*SSP Net Work Status Register*/
#define REG_SSP2_SSP_NET_WORK_STATUS                      ASR_ADDR(REGS_SSP2_BASE, 0X20)/*SSP Net Work Status Register*/
#define REG_SSP0_SSP_RWOT_CTRL                            ASR_ADDR(REGS_SSP0_BASE, 0X24)/*SSP RWOT Control Register*/
#define REG_SSP2_SSP_RWOT_CTRL                            ASR_ADDR(REGS_SSP2_BASE, 0X24)/*SSP RWOT Control Register*/
#define REG_SSP0_SSP_RWOT_CCM                             ASR_ADDR(REGS_SSP0_BASE, 0X28)/*SSP RWOT Counter Cycles Match Register*/
#define REG_SSP2_SSP_RWOT_CCM                             ASR_ADDR(REGS_SSP2_BASE, 0X28)/*SSP RWOT Counter Cycles Match Register*/
#define REG_SSP0_SSP_RWOT_CVWRn                           ASR_ADDR(REGS_SSP0_BASE, 0X2C)/*SSP RWOT Counter Value Write for Read Request Register*/
#define REG_SSP2_SSP_RWOT_CVWRn                           ASR_ADDR(REGS_SSP2_BASE, 0X2C)/*SSP RWOT Counter Value Write for Read Request Register*/



/* bits definitions for register REG_SSP2_SSP_TOP_CTRL */
#define BIT_TTELP                                         ( BIT(18) )
#define BIT_TTE                                           ( BIT(17) )
#define BIT_SCFR                                          ( BIT(16) )
#define BIT_IFS                                           ( BIT(15) )
#define BIT_HOLD_FRAME_LOW                                ( BIT(14) )
#define BIT_SSP0_TRAIL25                                  ( BIT(13) )
#define BIT_LBM                                           ( BIT(12) )
#define BIT_SPH                                           ( BIT(11) )
#define BIT_SPO                                           ( BIT(10) )
#define BITS_DSS(_X_)                                     ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_SFRMDIR                                       ( BIT(4) )
#define BIT_SCLKDIR                                       ( BIT(3) )
#define BITS_FRF(_X_)                                     ( (_X_) << 1 & (BIT(1)|BIT(2)) )
#define BIT_SSE                                           ( BIT(0) )

/* bits definitions for register REG_SSP2_SSP_FIFO_CTRL */
#define BIT_STRF                                          ( BIT(19) )
#define BIT_EFWR                                          ( BIT(18) )
#define BIT_RXFIFO_AUTO_FULL_CTRL                         ( BIT(17) )
#define BIT_FPCKE                                         ( BIT(16) )
#define BITS_TXFIFO_WR_ENDIAN(_X_)                        ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_RXFIFO_RD_ENDIAN(_X_)                        ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BIT_RSRE                                          ( BIT(11) )
#define BIT_TSRE                                          ( BIT(10) )
#define BITS_RFT(_X_)                                     ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BITS_TFT(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_SSP2_SSP_INT_EN */
#define BIT_EBCEI                                         ( BIT(6) )
#define BIT_TIM                                           ( BIT(5) )
#define BIT_RIM                                           ( BIT(4) )
#define BIT_SSP0_TIE61                                    ( BIT(3) )
#define BIT_RIE                                           ( BIT(2) )
#define BIT_TINTE                                         ( BIT(1) )
#define BIT_PINTE                                         ( BIT(0) )

/* bits definitions for register REG_SSP2_SSP_TO */
#define BITS_TIMEOUT(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )

/* bits definitions for register REG_SSP2_SSP_DATAR */
#define BITS_SSP0_DATA88(_X_)                             (_X_)

/* bits definitions for register REG_SSP2_SSP_STATUS */
#define BIT_OSS                                           ( BIT(23) )
#define BIT_TX_OSS                                        ( BIT(22) )
#define BIT_BCE                                           ( BIT(21) )
#define BIT_ROR                                           ( BIT(20) )
#define BITS_RFL(_X_)                                     ( (_X_) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_RNE                                           ( BIT(14) )
#define BIT_RFS                                           ( BIT(13) )
#define BIT_TUR                                           ( BIT(12) )
#define BITS_SSP0_TFL106(_X_)                             ( (_X_) << 7 & (BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_TNF                                           ( BIT(6) )
#define BIT_TFS                                           ( BIT(5) )
#define BIT_SSP0_EOC109                                   ( BIT(4) )
#define BIT_TINT                                          ( BIT(3) )
#define BIT_PINT                                          ( BIT(2) )
#define BIT_CSS                                           ( BIT(1) )
#define BIT_BSY                                           ( BIT(0) )

/* bits definitions for register REG_SSP2_SSP_PSP_CTRL */
#define BITS_EDMYSTOP(_X_)                                ( (_X_) << 27 & (BIT(27)|BIT(28)|BIT(29)) )
#define BITS_DMYSTOP(_X_)                                 ( (_X_) << 25 & (BIT(25)|BIT(26)) )
#define BITS_EDMYSTRT(_X_)                                ( (_X_) << 23 & (BIT(23)|BIT(24)) )
#define BITS_DMYSTRT(_X_)                                 ( (_X_) << 21 & (BIT(21)|BIT(22)) )
#define BITS_STRTDLY(_X_)                                 ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)) )
#define BITS_SFRMWDTH(_X_)                                ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BITS_SFRMDLY(_X_)                                 ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_SFRMP                                         ( BIT(4) )
#define BIT_FSRT                                          ( BIT(3) )
#define BIT_ETDS                                          ( BIT(2) )
#define BITS_SCMODE(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SSP2_SSP_NET_WORK_CTRL */
#define BITS_RTSA(_X_)                                    ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_TTSA(_X_)                                    ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_FRDC(_X_)                                    ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)) )
#define BIT_NET_WORK_MOD                                  ( BIT(0) )

/* bits definitions for register REG_SSP2_SSP_NET_WORK_STATUS */
#define BIT_NMBSY                                         ( BIT(3) )
#define BITS_TSS(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_SSP2_SSP_RWOT_CTRL */
#define BIT_MASK_RWOT_LAST_SAMPLE                         ( BIT(4) )
#define BIT_CLR_RWOT_CYCLE                                ( BIT(3) )
#define BIT_SET_RWOT_CYCLE                                ( BIT(2) )
#define BIT_CYCLE_RWOT_EN                                 ( BIT(1) )
#define BIT_RWOT                                          ( BIT(0) )

/* bits definitions for register REG_SSP2_SSP_RWOT_CCM */
#define BITS_SSPRWOTCCM(_X_)                              (_X_)

/* bits definitions for register REG_SSP2_SSP_RWOT_CVWRn */
#define BITS_SSPRWOTCVWR(_X_)                             (_X_)

#endif
