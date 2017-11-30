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


#ifndef __H_REGS_USIM1USIM2_HEADFILE_H__
#define __H_REGS_USIM1USIM2_HEADFILE_H__ __FILE__

#define	REGS_USIM1,USIM2

/* registers definitions for USIM1USIM2 */
#define REG_USIM1_USIM_RBR                                ASR_ADDR(REGS_USIM1_BASE, 0X00)/*USIM Receive Buffer Register*/
#define REG_USIM2_USIM_RBR                                ASR_ADDR(REGS_USIM2_BASE, 0X00)/*USIM Receive Buffer Register*/
#define REG_USIM1_USIM_THR                                ASR_ADDR(REGS_USIM1_BASE, 0X04)/*USIM Transmit Holding Register*/
#define REG_USIM2_USIM_THR                                ASR_ADDR(REGS_USIM2_BASE, 0X04)/*USIM Transmit Holding Register*/
#define REG_USIM1_USIM_IER                                ASR_ADDR(REGS_USIM1_BASE, 0X08)/*USIM Interrupt Enable Register*/
#define REG_USIM2_USIM_IER                                ASR_ADDR(REGS_USIM2_BASE, 0X08)/*USIM Interrupt Enable Register*/
#define REG_USIM1_USIM_IIR                                ASR_ADDR(REGS_USIM1_BASE, 0X0C)/*USIM Interrupt Identification Register*/
#define REG_USIM2_USIM_IIR                                ASR_ADDR(REGS_USIM2_BASE, 0X0C)/*USIM Interrupt Identification Register*/
#define REG_USIM1_USIM_FCR                                ASR_ADDR(REGS_USIM1_BASE, 0X10)/*USIM FIFO Control Register*/
#define REG_USIM2_USIM_FCR                                ASR_ADDR(REGS_USIM2_BASE, 0X10)/*USIM FIFO Control Register*/
#define REG_USIM1_USIM_FSR                                ASR_ADDR(REGS_USIM1_BASE, 0X14)/*USIM FIFO Status Register*/
#define REG_USIM2_USIM_FSR                                ASR_ADDR(REGS_USIM2_BASE, 0X14)/*USIM FIFO Status Register*/
#define REG_USIM1_USIM_ECR                                ASR_ADDR(REGS_USIM1_BASE, 0X18)/*USIM Error Control Register*/
#define REG_USIM2_USIM_ECR                                ASR_ADDR(REGS_USIM2_BASE, 0X18)/*USIM Error Control Register*/
#define REG_USIM1_USIM_LCR                                ASR_ADDR(REGS_USIM1_BASE, 0X1C)/*USIM Line Control Register*/
#define REG_USIM2_USIM_LCR                                ASR_ADDR(REGS_USIM2_BASE, 0X1C)/*USIM Line Control Register*/
#define REG_USIM1_USIM_USCCR                              ASR_ADDR(REGS_USIM1_BASE, 0X20)/*USIM SmartCard Control Register*/
#define REG_USIM2_USIM_USCCR                              ASR_ADDR(REGS_USIM2_BASE, 0X20)/*USIM SmartCard Control Register*/
#define REG_USIM1_USIM_LSR                                ASR_ADDR(REGS_USIM1_BASE, 0X24)/*USIM Line Status Register*/
#define REG_USIM2_USIM_LSR                                ASR_ADDR(REGS_USIM2_BASE, 0X24)/*USIM Line Status Register*/
#define REG_USIM1_USIM_EGTR                               ASR_ADDR(REGS_USIM1_BASE, 0X28)/*USIM Extra Guard Time Register*/
#define REG_USIM2_USIM_EGTR                               ASR_ADDR(REGS_USIM2_BASE, 0X28)/*USIM Extra Guard Time Register*/
#define REG_USIM1_USIM_BGTR                               ASR_ADDR(REGS_USIM1_BASE, 0X2C)/*USIM Block Guard Time Register*/
#define REG_USIM2_USIM_BGTR                               ASR_ADDR(REGS_USIM2_BASE, 0X2C)/*USIM Block Guard Time Register*/
#define REG_USIM1_USIM_TOR                                ASR_ADDR(REGS_USIM1_BASE, 0X30)/*USIM Time-Out Register*/
#define REG_USIM2_USIM_TOR                                ASR_ADDR(REGS_USIM2_BASE, 0X30)/*USIM Time-Out Register*/
#define REG_USIM1_USIM_CLKR                               ASR_ADDR(REGS_USIM1_BASE, 0X34)/*USIM Clock Register*/
#define REG_USIM2_USIM_CLKR                               ASR_ADDR(REGS_USIM2_BASE, 0X34)/*USIM Clock Register*/
#define REG_USIM1_USIM_DLR                                ASR_ADDR(REGS_USIM1_BASE, 0X38)/*USIM Divisor Latch Register*/
#define REG_USIM2_USIM_DLR                                ASR_ADDR(REGS_USIM2_BASE, 0X38)/*USIM Divisor Latch Register*/
#define REG_USIM1_USIM_FLR                                ASR_ADDR(REGS_USIM1_BASE, 0X3C)/*USIM Factor Latch Register*/
#define REG_USIM2_USIM_FLR                                ASR_ADDR(REGS_USIM2_BASE, 0X3C)/*USIM Factor Latch Register*/
#define REG_USIM1_USIM_CWTR                               ASR_ADDR(REGS_USIM1_BASE, 0X40)/*USIM Character Waiting Time Register*/
#define REG_USIM2_USIM_CWTR                               ASR_ADDR(REGS_USIM2_BASE, 0X40)/*USIM Character Waiting Time Register*/
#define REG_USIM1_USIM_BWTR                               ASR_ADDR(REGS_USIM1_BASE, 0X44)/*USIM Block Waiting Time Register*/
#define REG_USIM2_USIM_BWTR                               ASR_ADDR(REGS_USIM2_BASE, 0X44)/*USIM Block Waiting Time Register*/



/* bits definitions for register REG_USIM2_USIM_RBR */
#define BIT_PERR21                                        ( BIT(8) )
#define BITS_RB(_X_)                                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USIM2_USIM_THR */
#define BITS_USIM1_TB31(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USIM2_USIM_IER */
#define BIT_DMA_TX                                        ( BIT(15) )
#define BIT_DMA_RX                                        ( BIT(14) )
#define BIT_DMA_TIME                                      ( BIT(13) )
#define BIT_SMARTCARD_DET46                               ( BIT(10) )
#define BIT_TDR47                                         ( BIT(9) )
#define BIT_RDR48                                         ( BIT(8) )
#define BIT_USIM1_BWT50                                   ( BIT(6) )
#define BIT_CWT51                                         ( BIT(5) )
#define BIT_TIMEO52                                       ( BIT(4) )
#define BIT_FRAMERR53                                     ( BIT(3) )
#define BIT_TOERR54                                       ( BIT(2) )
#define BIT_PERR55                                        ( BIT(1) )
#define BIT_OVRN56                                        ( BIT(0) )

/* bits definitions for register REG_USIM2_USIM_IIR */
#define BIT_SMARTCARD_DET69                               ( BIT(10) )
#define BIT_TDR70                                         ( BIT(9) )
#define BIT_RDR71                                         ( BIT(8) )
#define BIT_USIM1_BWT73                                   ( BIT(6) )
#define BIT_CWT74                                         ( BIT(5) )
#define BIT_TIMEO75                                       ( BIT(4) )
#define BIT_FRAMERR76                                     ( BIT(3) )
#define BIT_TOERR77                                       ( BIT(2) )
#define BIT_PERR78                                        ( BIT(1) )
#define BIT_OVRN79                                        ( BIT(0) )

/* bits definitions for register REG_USIM2_USIM_FCR */
#define BIT_TX_TL                                         ( BIT(8) )
#define BITS_RX_TL(_X_)                                   ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_PEM                                           ( BIT(3) )
#define BIT_TX_HOLD                                       ( BIT(2) )
#define BIT_USIM1_RESETTF101                              ( BIT(1) )
#define BIT_USIM1_RESETRF102                              ( BIT(0) )

/* bits definitions for register REG_USIM2_USIM_FSR */
#define BITS_PERR_NUM(_X_)                                ( (_X_) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_TX_LENGTH(_X_)                               ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BITS_RX_LENGTH(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_USIM2_USIM_ECR */
#define BIT_T0_REPEAT                                     ( BIT(7) )
#define BIT_T0_CLR                                        ( BIT(6) )
#define BITS_PE_TL(_X_)                                   ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BITS_T0ERR_TL(_X_)                                ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_USIM2_USIM_LCR */
#define BIT_TX_T1                                         ( BIT(4) )
#define BIT_RX_T1                                         ( BIT(3) )
#define BIT_USIM1_EPS148                                  ( BIT(2) )
#define BIT_ORDER                                         ( BIT(1) )
#define BIT_INVERSE                                       ( BIT(0) )

/* bits definitions for register REG_USIM2_USIM_USCCR */
#define BIT_TXD_FORCE                                     ( BIT(4) )
#define BITS_VCC(_X_)                                     ( (_X_) << 1 & (BIT(1)|BIT(2)) )
#define BIT_RST_SMARTCARD_N                               ( BIT(0) )

/* bits definitions for register REG_USIM2_USIM_LSR */
#define BIT_USIM1_RXD174                                  ( BIT(15) )
#define BIT_RX_WORKING                                    ( BIT(14) )
#define BIT_TX_WORKING                                    ( BIT(13) )
#define BIT_RX_EMPTY_N                                    ( BIT(12) )
#define BIT_TDR178                                        ( BIT(11) )
#define BIT_USIM1_BWT180                                  ( BIT(6) )
#define BIT_CWT181                                        ( BIT(5) )
#define BIT_TIMEO182                                      ( BIT(4) )
#define BIT_FRAMERR183                                    ( BIT(3) )
#define BIT_TOERR184                                      ( BIT(2) )
#define BIT_PERR185                                       ( BIT(1) )
#define BIT_OVRN186                                       ( BIT(0) )

/* bits definitions for register REG_USIM2_USIM_EGTR */
#define BITS_EGTM(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USIM2_USIM_BGTR */
#define BITS_BGT(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USIM2_USIM_TOR */
#define BITS_TO(_X_)                                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USIM2_USIM_CLKR */
#define BIT_STOP_CLK_USIM                                 ( BIT(15) )
#define BIT_STOP_LEVEL                                    ( BIT(14) )
#define BIT_STOP_UCLK                                     ( BIT(13) )
#define BIT_RQST                                          ( BIT(12) )
#define BITS_DIVISOR246(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USIM2_USIM_DLR */
#define BITS_DIVISOR257(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USIM2_USIM_FLR */
#define BITS_FACTOR(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USIM2_USIM_CWTR */
#define BITS_CWT277(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USIM2_USIM_BWTR */
#define BITS_USIM1_BWT287(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

#endif
