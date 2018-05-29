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


#ifndef __H_REGS_DMA_HEADFILE_H__
#define __H_REGS_DMA_HEADFILE_H__ __FILE__

#define	REGS_DMA

/* registers definitions for DMA */
#define REG_DMA_DMA_CSR015                                ASR_ADDR(REGS_DMA_BASE, 0X00)/*DMA Channel Control/Status Registers 0-15*/
#define REG_DMA_DMA_ALGN                                  ASR_ADDR(REGS_DMA_BASE, 0XA0)/*DMA Alignment Register*/
#define REG_DMA_DMA_PCSR                                  ASR_ADDR(REGS_DMA_BASE, 0XA4)/*DMA Programmed I/O Control Status Register*/
#define REG_DMA_DMA_RQSR0                                 ASR_ADDR(REGS_DMA_BASE, 0XE0)/*DREQ Status Register 0*/
#define REG_DMA_DMA_INT                                   ASR_ADDR(REGS_DMA_BASE, 0XF0)/*DMA Interrupt Register*/
#define REG_DMA_DMA_RCMRx                                 ASR_ADDR(REGS_DMA_BASE, 0X0100)/*DMA Request to Channel Map Registers 0-51*/
#define REG_DMA_DMA_DADRx                                 ASR_ADDR(REGS_DMA_BASE, 0X200)/*DMA Descriptor Address Registers 0-15*/
#define REG_DMA_DMA_SADRx                                 ASR_ADDR(REGS_DMA_BASE, 0X204)/*DMA Source Address Registers 0-15*/
#define REG_DMA_DMA_TADRx                                 ASR_ADDR(REGS_DMA_BASE, 0X208)/*DMA Target Address Registers 0-15*/
#define REG_DMA_DMA_CMDx                                  ASR_ADDR(REGS_DMA_BASE, 0X20C)/*DMA Command Registers 0-15*/
#define REG_DMA_DMA_DADR_Hx                               ASR_ADDR(REGS_DMA_BASE, 0X300)/*DMA Descriptor Address Higher Bits Registers 0-15*/
#define REG_DMA_DMA_SADR_Hx                               ASR_ADDR(REGS_DMA_BASE, 0X304)/*DMA Source Address Higher Bits Registers 0-15*/
#define REG_DMA_DMA_TADR_Hx                               ASR_ADDR(REGS_DMA_BASE, 0X308)/*DMA Target Address Higher Bits Registers 0-15*/
#define REG_DMA_DUMMY_REGISTER                            ASR_ADDR(REGS_DMA_BASE, 0X0)/*This is a Dummy Register*/



/* bits definitions for register REG_DMA_DMA_CSR015 */
#define BIT_DM_RUN15                                      ( BIT(31) )
#define BIT_DM_NODESCFETCH16                              ( BIT(30) )
#define BIT_DM_STOPIRQEN17                                ( BIT(29) )
#define BIT_DM_EORIRQEN18                                 ( BIT(28) )
#define BIT_DM_EORJMPEN19                                 ( BIT(27) )
#define BIT_DM_EORSTOPEN20                                ( BIT(26) )
#define BIT_DM_SETCMPST21                                 ( BIT(25) )
#define BIT_DM_CLRCMPST22                                 ( BIT(24) )
#define BIT_DM_RASIRQEN23                                 ( BIT(23) )
#define BIT_DM_MASKRUN24                                  ( BIT(22) )
#define BIT_LPAE_EN                                       ( BIT(21) )
#define BIT_DM_CMPST27                                    ( BIT(10) )
#define BIT_DM_EORINT28                                   ( BIT(9) )
#define BIT_DM_REQPEND30                                  ( BIT(8) )
#define BIT_DM_RASINTR32                                  ( BIT(4) )
#define BIT_DM_STOPINTR33                                 ( BIT(3) )
#define BIT_DM_ENDINTR34                                  ( BIT(2) )
#define BIT_DM_STARTINTR35                                ( BIT(1) )
#define BIT_DM_BUSERRINTR36                               ( BIT(0) )

/* bits definitions for register REG_DMA_DMA_ALGN */
#define BITS_DM_DALGNX53(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DMA_DMA_PCSR */
#define BIT_DM_BRGSPLIT71                                 ( BIT(31) )
#define BIT_DM_BRGBUSY74                                  ( BIT(0) )

/* bits definitions for register REG_DMA_DMA_RQSR0 */
#define BIT_DM_CLR88                                      ( BIT(8) )
#define BITS_DM_REQPEND90(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_DMA_DMA_INT */
#define BITS_DM_CHLINTRX105(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DMA_DMA_RCMRx */
#define BIT_DM_MAPVLD115                                  ( BIT(7) )
#define BITS_DM_CHLNUM117(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_DMA_DMA_DADRx */
#define BITS_DM_DESCRIPTOR_ADDRESS132(_X_)                ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DM_BREN134                                    ( BIT(1) )
#define BIT_DM_STOP135                                    ( BIT(0) )

/* bits definitions for register REG_DMA_DMA_SADRx */
#define BITS_DM_SRCADDR152(_X_)                           ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DM_SRCADDR2153                                ( BIT(2) )
#define BITS_DM_SRCADDR0154(_X_)                          ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_DMA_DMA_TADRx */
#define BITS_DM_TRGADDR171(_X_)                           ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DM_TRGADDR2172                                ( BIT(2) )
#define BITS_DM_TRGADDR0173(_X_)                          ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_DMA_DMA_CMDx */
#define BIT_DM_INCSRCADDR187                              ( BIT(31) )
#define BIT_DM_INCTRGADDR188                              ( BIT(30) )
#define BIT_DM_FLOWSRC189                                 ( BIT(29) )
#define BIT_DM_FLOWTRG190                                 ( BIT(28) )
#define BIT_DM_CMPEN192                                   ( BIT(25) )
#define BIT_DM_ADDRMODE194                                ( BIT(23) )
#define BIT_DM_STARTIRQEN195                              ( BIT(22) )
#define BIT_DM_ENDIRQEN196                                ( BIT(21) )
#define BITS_DM_SIZE198(_X_)                              ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BITS_DM_WIDTH199(_X_)                             ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_DM_LEN201(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )

/* bits definitions for register REG_DMA_DMA_DADR_Hx */
#define BITS_DESCRIPTOR_ADDRESS_H(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DMA_DMA_SADR_Hx */
#define BITS_SOURCE_ADDRESS_H(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DMA_DMA_TADR_Hx */
#define BITS_TARGET_ADDRESS_H(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DMA_DUMMY_REGISTER */
#define BITS_DM_DUMMY250(_X_)                             (_X_)

#endif
