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


#ifndef __H_REGS_AP_UART1AP_UART2AP_UART3CP_UART_HEADFILE_H__
#define __H_REGS_AP_UART1AP_UART2AP_UART3CP_UART_HEADFILE_H__ __FILE__

#define	REGS_AP_UART1,AP_UART2,AP_UART3,CP_UART

/* registers definitions for AP_UART1AP_UART2AP_UART3CP_UART */
#define REG_AP_UART1_UART_RBR                             ASR_ADDR(REGS_AP_UART1_BASE, 0X00)/*Receive Buffer Register*/
#define REG_AP_UART2_UART_RBR                             ASR_ADDR(REGS_AP_UART2_BASE, 0X00)/*Receive Buffer Register*/
#define REG_AP_UART3_UART_RBR                             ASR_ADDR(REGS_AP_UART3_BASE, 0X00)/*Receive Buffer Register*/
#define REG_CP_UART_UART_RBR                              ASR_ADDR(REGS_CP_UART_BASE, 0X00)/*Receive Buffer Register*/
#define REG_AP_UART1_UART_THR                             ASR_ADDR(REGS_AP_UART1_BASE, 0X00)/*Transmit Holding Register*/
#define REG_AP_UART2_UART_THR                             ASR_ADDR(REGS_AP_UART2_BASE, 0X00)/*Transmit Holding Register*/
#define REG_AP_UART3_UART_THR                             ASR_ADDR(REGS_AP_UART3_BASE, 0X00)/*Transmit Holding Register*/
#define REG_CP_UART_UART_THR                              ASR_ADDR(REGS_CP_UART_BASE, 0X00)/*Transmit Holding Register*/
#define REG_AP_UART1_UART_DLL                             ASR_ADDR(REGS_AP_UART1_BASE, 0X00)/*Divisor Latch Low Byte Register*/
#define REG_AP_UART2_UART_DLL                             ASR_ADDR(REGS_AP_UART2_BASE, 0X00)/*Divisor Latch Low Byte Register*/
#define REG_AP_UART3_UART_DLL                             ASR_ADDR(REGS_AP_UART3_BASE, 0X00)/*Divisor Latch Low Byte Register*/
#define REG_CP_UART_UART_DLL                              ASR_ADDR(REGS_CP_UART_BASE, 0X00)/*Divisor Latch Low Byte Register*/
#define REG_AP_UART1_UART_DLH                             ASR_ADDR(REGS_AP_UART1_BASE, 0X04)/*Divisor Latch High Byte Register*/
#define REG_AP_UART2_UART_DLH                             ASR_ADDR(REGS_AP_UART2_BASE, 0X04)/*Divisor Latch High Byte Register*/
#define REG_AP_UART3_UART_DLH                             ASR_ADDR(REGS_AP_UART3_BASE, 0X04)/*Divisor Latch High Byte Register*/
#define REG_CP_UART_UART_DLH                              ASR_ADDR(REGS_CP_UART_BASE, 0X04)/*Divisor Latch High Byte Register*/
#define REG_AP_UART1_UART_IER                             ASR_ADDR(REGS_AP_UART1_BASE, 0X04)/*Interrupt Enable Register*/
#define REG_AP_UART2_UART_IER                             ASR_ADDR(REGS_AP_UART2_BASE, 0X04)/*Interrupt Enable Register*/
#define REG_AP_UART3_UART_IER                             ASR_ADDR(REGS_AP_UART3_BASE, 0X04)/*Interrupt Enable Register*/
#define REG_CP_UART_UART_IER                              ASR_ADDR(REGS_CP_UART_BASE, 0X04)/*Interrupt Enable Register*/
#define REG_AP_UART1_UART_IIR                             ASR_ADDR(REGS_AP_UART1_BASE, 0X08)/*Interrupt Identification Register*/
#define REG_AP_UART2_UART_IIR                             ASR_ADDR(REGS_AP_UART2_BASE, 0X08)/*Interrupt Identification Register*/
#define REG_AP_UART3_UART_IIR                             ASR_ADDR(REGS_AP_UART3_BASE, 0X08)/*Interrupt Identification Register*/
#define REG_CP_UART_UART_IIR                              ASR_ADDR(REGS_CP_UART_BASE, 0X08)/*Interrupt Identification Register*/
#define REG_AP_UART1_UART_FCR                             ASR_ADDR(REGS_AP_UART1_BASE, 0X08)/*FIFO Control Register*/
#define REG_AP_UART2_UART_FCR                             ASR_ADDR(REGS_AP_UART2_BASE, 0X08)/*FIFO Control Register*/
#define REG_AP_UART3_UART_FCR                             ASR_ADDR(REGS_AP_UART3_BASE, 0X08)/*FIFO Control Register*/
#define REG_CP_UART_UART_FCR                              ASR_ADDR(REGS_CP_UART_BASE, 0X08)/*FIFO Control Register*/
#define REG_AP_UART1_UART_LCR                             ASR_ADDR(REGS_AP_UART1_BASE, 0X0C)/*Line Control Register*/
#define REG_AP_UART2_UART_LCR                             ASR_ADDR(REGS_AP_UART2_BASE, 0X0C)/*Line Control Register*/
#define REG_AP_UART3_UART_LCR                             ASR_ADDR(REGS_AP_UART3_BASE, 0X0C)/*Line Control Register*/
#define REG_CP_UART_UART_LCR                              ASR_ADDR(REGS_CP_UART_BASE, 0X0C)/*Line Control Register*/
#define REG_AP_UART1_UART_MCR                             ASR_ADDR(REGS_AP_UART1_BASE, 0X10)/*Modem Control Register*/
#define REG_AP_UART2_UART_MCR                             ASR_ADDR(REGS_AP_UART2_BASE, 0X10)/*Modem Control Register*/
#define REG_AP_UART3_UART_MCR                             ASR_ADDR(REGS_AP_UART3_BASE, 0X10)/*Modem Control Register*/
#define REG_CP_UART_UART_MCR                              ASR_ADDR(REGS_CP_UART_BASE, 0X10)/*Modem Control Register*/
#define REG_AP_UART1_UART_LSR                             ASR_ADDR(REGS_AP_UART1_BASE, 0X14)/*Line Status Register*/
#define REG_AP_UART2_UART_LSR                             ASR_ADDR(REGS_AP_UART2_BASE, 0X14)/*Line Status Register*/
#define REG_AP_UART3_UART_LSR                             ASR_ADDR(REGS_AP_UART3_BASE, 0X14)/*Line Status Register*/
#define REG_CP_UART_UART_LSR                              ASR_ADDR(REGS_CP_UART_BASE, 0X14)/*Line Status Register*/
#define REG_AP_UART1_UART_MSR                             ASR_ADDR(REGS_AP_UART1_BASE, 0X18)/*Modem Status Register*/
#define REG_AP_UART2_UART_MSR                             ASR_ADDR(REGS_AP_UART2_BASE, 0X18)/*Modem Status Register*/
#define REG_AP_UART3_UART_MSR                             ASR_ADDR(REGS_AP_UART3_BASE, 0X18)/*Modem Status Register*/
#define REG_CP_UART_UART_MSR                              ASR_ADDR(REGS_CP_UART_BASE, 0X18)/*Modem Status Register*/
#define REG_AP_UART1_UART_SCR                             ASR_ADDR(REGS_AP_UART1_BASE, 0X1C)/*Scratchpad Register*/
#define REG_AP_UART2_UART_SCR                             ASR_ADDR(REGS_AP_UART2_BASE, 0X1C)/*Scratchpad Register*/
#define REG_AP_UART3_UART_SCR                             ASR_ADDR(REGS_AP_UART3_BASE, 0X1C)/*Scratchpad Register*/
#define REG_CP_UART_UART_SCR                              ASR_ADDR(REGS_CP_UART_BASE, 0X1C)/*Scratchpad Register*/
#define REG_AP_UART1_UART_ISR                             ASR_ADDR(REGS_AP_UART1_BASE, 0X20)/*Infrared Selection Register*/
#define REG_AP_UART2_UART_ISR                             ASR_ADDR(REGS_AP_UART2_BASE, 0X20)/*Infrared Selection Register*/
#define REG_AP_UART3_UART_ISR                             ASR_ADDR(REGS_AP_UART3_BASE, 0X20)/*Infrared Selection Register*/
#define REG_CP_UART_UART_ISR                              ASR_ADDR(REGS_CP_UART_BASE, 0X20)/*Infrared Selection Register*/
#define REG_AP_UART1_UART_FOR                             ASR_ADDR(REGS_AP_UART1_BASE, 0X24)/*Receive FIFO Occupancy Register*/
#define REG_AP_UART2_UART_FOR                             ASR_ADDR(REGS_AP_UART2_BASE, 0X24)/*Receive FIFO Occupancy Register*/
#define REG_AP_UART3_UART_FOR                             ASR_ADDR(REGS_AP_UART3_BASE, 0X24)/*Receive FIFO Occupancy Register*/
#define REG_CP_UART_UART_FOR                              ASR_ADDR(REGS_CP_UART_BASE, 0X24)/*Receive FIFO Occupancy Register*/
#define REG_AP_UART1_UART_ABR                             ASR_ADDR(REGS_AP_UART1_BASE, 0X28)/*Auto-Baud Control Register*/
#define REG_AP_UART2_UART_ABR                             ASR_ADDR(REGS_AP_UART2_BASE, 0X28)/*Auto-Baud Control Register*/
#define REG_AP_UART3_UART_ABR                             ASR_ADDR(REGS_AP_UART3_BASE, 0X28)/*Auto-Baud Control Register*/
#define REG_CP_UART_UART_ABR                              ASR_ADDR(REGS_CP_UART_BASE, 0X28)/*Auto-Baud Control Register*/
#define REG_AP_UART1_UART_ACR                             ASR_ADDR(REGS_AP_UART1_BASE, 0X2C)/*Auto-Baud Count Register*/
#define REG_AP_UART2_UART_ACR                             ASR_ADDR(REGS_AP_UART2_BASE, 0X2C)/*Auto-Baud Count Register*/
#define REG_AP_UART3_UART_ACR                             ASR_ADDR(REGS_AP_UART3_BASE, 0X2C)/*Auto-Baud Count Register*/
#define REG_CP_UART_UART_ACR                              ASR_ADDR(REGS_CP_UART_BASE, 0X2C)/*Auto-Baud Count Register*/



/* bits definitions for register REG_CP_UART_UART_RBR */
#define BITS_BYTE_324(_X_)                                ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_BYTE_225(_X_)                                ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BITS_BYTE_126(_X_)                                ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_BYTE_027(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_CP_UART_UART_THR */
#define BITS_BYTE_335(_X_)                                ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_BYTE_236(_X_)                                ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BITS_BYTE_137(_X_)                                ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_BYTE_038(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_CP_UART_UART_DLL */
#define BITS_DLL(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_CP_UART_UART_DLH */
#define BITS_DLH(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_CP_UART_UART_IER */
#define BIT_HSE                                           ( BIT(8) )
#define BIT_DMAE                                          ( BIT(7) )
#define BIT_UUE                                           ( BIT(6) )
#define BIT_NRZE                                          ( BIT(5) )
#define BIT_RTOIE                                         ( BIT(4) )
#define BIT_AP_UA_MIE80                                   ( BIT(3) )
#define BIT_RLSE                                          ( BIT(2) )
#define BIT_AP_UA_TIE82                                   ( BIT(1) )
#define BIT_RAVIE                                         ( BIT(0) )

/* bits definitions for register REG_CP_UART_UART_IIR */
#define BITS_FIFOES10(_X_)                                ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_AP_UA_EOC92                                   ( BIT(5) )
#define BIT_ABL                                           ( BIT(4) )
#define BIT_TOD                                           ( BIT(3) )
#define BITS_IID10(_X_)                                   ( (_X_) << 1 & (BIT(1)|BIT(2)) )
#define BIT_NIP                                           ( BIT(0) )

/* bits definitions for register REG_CP_UART_UART_FCR */
#define BITS_ITL(_X_)                                     ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_BUS                                           ( BIT(5) )
#define BIT_AP_UA_TRAIL124                                ( BIT(4) )
#define BIT_TIL                                           ( BIT(3) )
#define BIT_AP_UA_RESETTF126                              ( BIT(2) )
#define BIT_AP_UA_RESETRF127                              ( BIT(1) )
#define BIT_TRFIFOE                                       ( BIT(0) )

/* bits definitions for register REG_CP_UART_UART_LCR */
#define BIT_DLAB                                          ( BIT(7) )
#define BIT_SB                                            ( BIT(6) )
#define BIT_STKYP                                         ( BIT(5) )
#define BIT_AP_UA_EPS141                                  ( BIT(4) )
#define BIT_PEN                                           ( BIT(3) )
#define BIT_STB                                           ( BIT(2) )
#define BITS_WLS10(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_CP_UART_UART_MCR */
#define BIT_AFE                                           ( BIT(5) )
#define BIT_LOOP                                          ( BIT(4) )
#define BIT_OUT2                                          ( BIT(3) )
#define BIT_OUT1                                          ( BIT(2) )
#define BIT_RTS                                           ( BIT(1) )
#define BIT_DTR                                           ( BIT(0) )

/* bits definitions for register REG_CP_UART_UART_LSR */
#define BIT_FIFOE                                         ( BIT(7) )
#define BIT_AP_UA_TEMT178                                 ( BIT(6) )
#define BIT_TDRQ                                          ( BIT(5) )
#define BIT_BI                                            ( BIT(4) )
#define BIT_FE                                            ( BIT(3) )
#define BIT_AP_UA_PE182                                   ( BIT(2) )
#define BIT_OE                                            ( BIT(1) )
#define BIT_DR                                            ( BIT(0) )

/* bits definitions for register REG_CP_UART_UART_MSR */
#define BIT_DCD                                           ( BIT(7) )
#define BIT_RI                                            ( BIT(6) )
#define BIT_DSR                                           ( BIT(5) )
#define BIT_CTS                                           ( BIT(4) )
#define BIT_DDCD                                          ( BIT(3) )
#define BIT_TERI                                          ( BIT(2) )
#define BIT_DDSR                                          ( BIT(1) )
#define BIT_DCTS                                          ( BIT(0) )

/* bits definitions for register REG_CP_UART_UART_SCR */
#define BITS_SCRATCHPAD(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_CP_UART_UART_ISR */
#define BIT_RXPL                                          ( BIT(4) )
#define BIT_TXPL                                          ( BIT(3) )
#define BIT_XMODE                                         ( BIT(2) )
#define BIT_RCVEIR                                        ( BIT(1) )
#define BIT_XMITIR                                        ( BIT(0) )

/* bits definitions for register REG_CP_UART_UART_FOR */
#define BITS_BYTE_COUNT(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_CP_UART_UART_ABR */
#define BIT_ABT                                           ( BIT(3) )
#define BIT_ABUP                                          ( BIT(2) )
#define BIT_ABLIE                                         ( BIT(1) )
#define BIT_ABE                                           ( BIT(0) )

/* bits definitions for register REG_CP_UART_UART_ACR */
#define BITS_AP_UA_COUNT_VALUE265(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

#endif
