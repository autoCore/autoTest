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
#define REG_DMA_DMA_CSR031                                ASR_ADDR(REGS_DMA_BASE, 0X00)/*DMA Channel Control/Status Registers 0-31*/
#define REG_DMA_DMA_ALGN                                  ASR_ADDR(REGS_DMA_BASE, 0XA0)/*DMA Alignment Register*/
#define REG_DMA_DMA_PCSR                                  ASR_ADDR(REGS_DMA_BASE, 0XA4)/*DMA Programmed I/O Control Status Register*/
#define REG_DMA_DMA_RQSR0                                 ASR_ADDR(REGS_DMA_BASE, 0XE0)/*DREQ Status Register 0*/
#define REG_DMA_DMA_RQSR1                                 ASR_ADDR(REGS_DMA_BASE, 0XE4)/*DREQ Status Register 1*/
#define REG_DMA_DMA_RQSR2                                 ASR_ADDR(REGS_DMA_BASE, 0XE8)/*DREQ Status Register 2*/
#define REG_DMA_DMA_INT                                   ASR_ADDR(REGS_DMA_BASE, 0XF0)/*DMA Interrupt Register*/
#define REG_DMA_DMA_RCMRx0                                ASR_ADDR(REGS_DMA_BASE, 0x0100)/*DMA Request to Channel Map Registers 0-63 and 64-99*/
#define REG_DMA_DMA_RCMRx1                                ASR_ADDR(REGS_DMA_BASE, 0x1100)/*DMA Request to Channel Map Registers 0-63 and 64-99*/
#define REG_DMA_DMA_DADRx                                 ASR_ADDR(REGS_DMA_BASE, 0X200)/*DMA Descriptor Address Registers*/
#define REG_DMA_DMA_SADRx                                 ASR_ADDR(REGS_DMA_BASE, 0X204)/*DMA Source Address Registers 0-31*/
#define REG_DMA_DMA_TADRx                                 ASR_ADDR(REGS_DMA_BASE, 0X208)/*DMA Target Address Registers 0-31*/
#define REG_DMA_DMA_CMDx                                  ASR_ADDR(REGS_DMA_BASE, 0X20C)/*DMA Command Registers 0-31*/
#define REG_DMA_DUMMY_REGISTER                            ASR_ADDR(REGS_DMA_BASE, 0X0)/*This is a Dummy Register*/



/* bits definitions for register REG_DMA_DMA_CSR031 */
#define BIT_DM_RUN16                                      ( BIT(31) )
#define BIT_DM_NODESCFETCH17                              ( BIT(30) )
#define BIT_DM_STOPIRQEN18                                ( BIT(29) )
#define BIT_DM_EORIRQEN19                                 ( BIT(28) )
#define BIT_DM_EORJMPEN20                                 ( BIT(27) )
#define BIT_DM_EORSTOPEN21                                ( BIT(26) )
#define BIT_DM_SETCMPST22                                 ( BIT(25) )
#define BIT_DM_CLRCMPST23                                 ( BIT(24) )
#define BIT_DM_RASIRQEN24                                 ( BIT(23) )
#define BIT_DM_MASKRUN25                                  ( BIT(22) )
#define BIT_DM_CMPST27                                    ( BIT(10) )
#define BIT_DM_EORINT28                                   ( BIT(9) )
#define BIT_REQPEND30                                     ( BIT(8) )
#define BIT_DM_RASINTR32                                  ( BIT(4) )
#define BIT_DM_STOPINTR33                                 ( BIT(3) )
#define BIT_DM_ENDINTR34                                  ( BIT(2) )
#define BIT_DM_STARTINTR35                                ( BIT(1) )
#define BIT_DM_BUSERRINTR36                               ( BIT(0) )

/* bits definitions for register REG_DMA_DMA_ALGN */
#define BITS_DM_DALGNX52(_X_)                             (_X_)

/* bits definitions for register REG_DMA_DMA_PCSR */
#define BIT_DM_BRGSPLIT70                                 ( BIT(31) )
#define BIT_DPCSR_2_R                                     ( BIT(2) )
#define BIT_DPCSR_1_R                                     ( BIT(1) )
#define BIT_DM_BRGBUSY74                                  ( BIT(0) )

/* bits definitions for register REG_DMA_DMA_RQSR0 */
#define BIT_CLR88                                         ( BIT(8) )
#define BITS_REQPEND90(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_DMA_DMA_RQSR1 */
#define BIT_CLR98                                         ( BIT(8) )
#define BITS_REQPEND100(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_DMA_DMA_RQSR2 */
#define BIT_CLR107                                        ( BIT(8) )
#define BITS_REQPEND109(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_DMA_DMA_INT */
#define BITS_DM_CHLINTRX123(_X_)                          (_X_)

/* bits definitions for register REG_DMA_DMA_RCMRx1 */
#define BIT_DM_MAPVLD133                                  ( BIT(7) )
#define BITS_DM_CHLNUM135(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_DMA_DMA_DADRx */
#define BITS_DM_DESCRIPTOR_ADDRESS150(_X_)                ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DM_BREN152                                    ( BIT(1) )
#define BIT_DM_STOP153                                    ( BIT(0) )

/* bits definitions for register REG_DMA_DMA_SADRx */
#define BITS_DM_SRCADDR170(_X_)                           ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DM_SRCADDR2171                                ( BIT(2) )
#define BITS_DM_SRCADDR0172(_X_)                          ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_DMA_DMA_TADRx */
#define BITS_DM_TRGADDR189(_X_)                           ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DM_TRGADDR2190                                ( BIT(2) )
#define BITS_DM_TRGADDR0191(_X_)                          ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_DMA_DMA_CMDx */
#define BIT_DM_INCSRCADDR205                              ( BIT(31) )
#define BIT_DM_INCTRGADDR206                              ( BIT(30) )
#define BIT_DM_FLOWSRC207                                 ( BIT(29) )
#define BIT_DM_FLOWTRG208                                 ( BIT(28) )
#define BIT_DM_CMPEN210                                   ( BIT(25) )
#define BIT_DM_ADDRMODE212                                ( BIT(23) )
#define BIT_DM_STARTIRQEN213                              ( BIT(22) )
#define BIT_DM_ENDIRQEN214                                ( BIT(21) )
#define BITS_DM_SIZE216(_X_)                              ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_DM_WIDTH217(_X_)                             ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_DM_LEN219(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )

/* bits definitions for register REG_DMA_DUMMY_REGISTER */
#define BITS_DM_DUMMY234(_X_)                             (_X_)

#endif
