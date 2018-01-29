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


#ifndef __H_REGS_MSADMAC1MSADMAC2_HEADFILE_H__
#define __H_REGS_MSADMAC1MSADMAC2_HEADFILE_H__ __FILE__

#define	REGS_MSADMAC1,MSADMAC2

/* registers definitions for MSADMAC1MSADMAC2 */
#define REG_MSADMAC1_DCR                                  ASR_ADDR(REGS_MSADMAC1_BASE, 0X00)/*DMA Control Register*/
#define REG_MSADMAC2_DCR                                  ASR_ADDR(REGS_MSADMAC2_BASE, 0X00)/*DMA Control Register*/
#define REG_MSADMAC1_DESR                                 ASR_ADDR(REGS_MSADMAC1_BASE, 0X08)/*DMA Error Source Register*/
#define REG_MSADMAC2_DESR                                 ASR_ADDR(REGS_MSADMAC2_BASE, 0X08)/*DMA Error Source Register*/
#define REG_MSADMAC1_CSAR0..7:Primary0                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x10)/*Channel Source Address Registers*/
#define REG_MSADMAC2_CSAR0..7:Primary0                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x10)/*Channel Source Address Registers*/
#define REG_MSADMAC1_CSAR0..7:Primary1                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x20)/*Channel Source Address Registers*/
#define REG_MSADMAC2_CSAR0..7:Primary1                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x20)/*Channel Source Address Registers*/
#define REG_MSADMAC1_CSAR0..7:Primary2                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x30)/*Channel Source Address Registers*/
#define REG_MSADMAC2_CSAR0..7:Primary2                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x30)/*Channel Source Address Registers*/
#define REG_MSADMAC1_CSAR0..7:Primary3                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x40)/*Channel Source Address Registers*/
#define REG_MSADMAC2_CSAR0..7:Primary3                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x40)/*Channel Source Address Registers*/
#define REG_MSADMAC1_CSAR0..7:Primary4                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x50)/*Channel Source Address Registers*/
#define REG_MSADMAC2_CSAR0..7:Primary4                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x50)/*Channel Source Address Registers*/
#define REG_MSADMAC1_CSAR0..7:Primary5                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x60)/*Channel Source Address Registers*/
#define REG_MSADMAC2_CSAR0..7:Primary5                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x60)/*Channel Source Address Registers*/
#define REG_MSADMAC1_CSAR0..7:Primary6                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x70)/*Channel Source Address Registers*/
#define REG_MSADMAC2_CSAR0..7:Primary6                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x70)/*Channel Source Address Registers*/
#define REG_MSADMAC1_CSAR0..7:Primary7                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x80)/*Channel Source Address Registers*/
#define REG_MSADMAC2_CSAR0..7:Primary7                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x80)/*Channel Source Address Registers*/
#define REG_MSADMAC1_CSAR0..7:Primary8                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x90)/*Channel Source Address Registers*/
#define REG_MSADMAC2_CSAR0..7:Primary8                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x90)/*Channel Source Address Registers*/
#define REG_MSADMAC1_CSAR0..7:Primary9                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x94)/*Channel Source Address Registers*/
#define REG_MSADMAC2_CSAR0..7:Primary9                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x94)/*Channel Source Address Registers*/
#define REG_MSADMAC1_CSAR0..7:Primary10                   ASR_ADDR(REGS_MSADMAC1_BASE, 0x98)/*Channel Source Address Registers*/
#define REG_MSADMAC2_CSAR0..7:Primary10                   ASR_ADDR(REGS_MSADMAC2_BASE, 0x98)/*Channel Source Address Registers*/
#define REG_MSADMAC1_CSAR0..7:Primary11                   ASR_ADDR(REGS_MSADMAC1_BASE, 0x9C)/*Channel Source Address Registers*/
#define REG_MSADMAC2_CSAR0..7:Primary11                   ASR_ADDR(REGS_MSADMAC2_BASE, 0x9C)/*Channel Source Address Registers*/
#define REG_MSADMAC1_CDAR0..7:Primary0                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x14)/*Channel Destination Address Registers*/
#define REG_MSADMAC2_CDAR0..7:Primary0                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x14)/*Channel Destination Address Registers*/
#define REG_MSADMAC1_CDAR0..7:Primary1                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x24)/*Channel Destination Address Registers*/
#define REG_MSADMAC2_CDAR0..7:Primary1                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x24)/*Channel Destination Address Registers*/
#define REG_MSADMAC1_CDAR0..7:Primary2                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x34)/*Channel Destination Address Registers*/
#define REG_MSADMAC2_CDAR0..7:Primary2                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x34)/*Channel Destination Address Registers*/
#define REG_MSADMAC1_CDAR0..7:Primary3                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x44)/*Channel Destination Address Registers*/
#define REG_MSADMAC2_CDAR0..7:Primary3                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x44)/*Channel Destination Address Registers*/
#define REG_MSADMAC1_CDAR0..7:Primary4                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x54)/*Channel Destination Address Registers*/
#define REG_MSADMAC2_CDAR0..7:Primary4                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x54)/*Channel Destination Address Registers*/
#define REG_MSADMAC1_CDAR0..7:Primary5                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x64)/*Channel Destination Address Registers*/
#define REG_MSADMAC2_CDAR0..7:Primary5                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x64)/*Channel Destination Address Registers*/
#define REG_MSADMAC1_CDAR0..7:Primary6                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x74)/*Channel Destination Address Registers*/
#define REG_MSADMAC2_CDAR0..7:Primary6                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x74)/*Channel Destination Address Registers*/
#define REG_MSADMAC1_CDAR0..7:Primary7                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x84)/*Channel Destination Address Registers*/
#define REG_MSADMAC2_CDAR0..7:Primary7                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x84)/*Channel Destination Address Registers*/
#define REG_MSADMAC1_CDAR0..7:Primary8                    ASR_ADDR(REGS_MSADMAC1_BASE, 0xA0)/*Channel Destination Address Registers*/
#define REG_MSADMAC2_CDAR0..7:Primary8                    ASR_ADDR(REGS_MSADMAC2_BASE, 0xA0)/*Channel Destination Address Registers*/
#define REG_MSADMAC1_CDAR0..7:Primary9                    ASR_ADDR(REGS_MSADMAC1_BASE, 0xA4)/*Channel Destination Address Registers*/
#define REG_MSADMAC2_CDAR0..7:Primary9                    ASR_ADDR(REGS_MSADMAC2_BASE, 0xA4)/*Channel Destination Address Registers*/
#define REG_MSADMAC1_CDAR0..7:Primary10                   ASR_ADDR(REGS_MSADMAC1_BASE, 0xA8)/*Channel Destination Address Registers*/
#define REG_MSADMAC2_CDAR0..7:Primary10                   ASR_ADDR(REGS_MSADMAC2_BASE, 0xA8)/*Channel Destination Address Registers*/
#define REG_MSADMAC1_CDAR0..7:Primary11                   ASR_ADDR(REGS_MSADMAC1_BASE, 0xAC)/*Channel Destination Address Registers*/
#define REG_MSADMAC2_CDAR0..7:Primary11                   ASR_ADDR(REGS_MSADMAC2_BASE, 0xAC)/*Channel Destination Address Registers*/
#define REG_MSADMAC1_CBCR0..7:Primary0                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x18)/*Channel Byte Count Registers*/
#define REG_MSADMAC2_CBCR0..7:Primary0                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x18)/*Channel Byte Count Registers*/
#define REG_MSADMAC1_CBCR0..7:Primary1                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x28)/*Channel Byte Count Registers*/
#define REG_MSADMAC2_CBCR0..7:Primary1                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x28)/*Channel Byte Count Registers*/
#define REG_MSADMAC1_CBCR0..7:Primary2                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x38)/*Channel Byte Count Registers*/
#define REG_MSADMAC2_CBCR0..7:Primary2                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x38)/*Channel Byte Count Registers*/
#define REG_MSADMAC1_CBCR0..7:Primary3                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x48)/*Channel Byte Count Registers*/
#define REG_MSADMAC2_CBCR0..7:Primary3                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x48)/*Channel Byte Count Registers*/
#define REG_MSADMAC1_CBCR0..7:Primary4                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x58)/*Channel Byte Count Registers*/
#define REG_MSADMAC2_CBCR0..7:Primary4                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x58)/*Channel Byte Count Registers*/
#define REG_MSADMAC1_CBCR0..7:Primary5                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x68)/*Channel Byte Count Registers*/
#define REG_MSADMAC2_CBCR0..7:Primary5                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x68)/*Channel Byte Count Registers*/
#define REG_MSADMAC1_CBCR0..7:Primary6                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x78)/*Channel Byte Count Registers*/
#define REG_MSADMAC2_CBCR0..7:Primary6                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x78)/*Channel Byte Count Registers*/
#define REG_MSADMAC1_CBCR0..7:Primary7                    ASR_ADDR(REGS_MSADMAC1_BASE, 0x88)/*Channel Byte Count Registers*/
#define REG_MSADMAC2_CBCR0..7:Primary7                    ASR_ADDR(REGS_MSADMAC2_BASE, 0x88)/*Channel Byte Count Registers*/
#define REG_MSADMAC1_CBCR0..7:Primary8                    ASR_ADDR(REGS_MSADMAC1_BASE, 0xB0)/*Channel Byte Count Registers*/
#define REG_MSADMAC2_CBCR0..7:Primary8                    ASR_ADDR(REGS_MSADMAC2_BASE, 0xB0)/*Channel Byte Count Registers*/
#define REG_MSADMAC1_CBCR0..7:Primary9                    ASR_ADDR(REGS_MSADMAC1_BASE, 0xB4)/*Channel Byte Count Registers*/
#define REG_MSADMAC2_CBCR0..7:Primary9                    ASR_ADDR(REGS_MSADMAC2_BASE, 0xB4)/*Channel Byte Count Registers*/
#define REG_MSADMAC1_CBCR0..7:Primary10                   ASR_ADDR(REGS_MSADMAC1_BASE, 0xB8)/*Channel Byte Count Registers*/
#define REG_MSADMAC2_CBCR0..7:Primary10                   ASR_ADDR(REGS_MSADMAC2_BASE, 0xB8)/*Channel Byte Count Registers*/
#define REG_MSADMAC1_CBCR0..7:Primary11                   ASR_ADDR(REGS_MSADMAC1_BASE, 0xBC)/*Channel Byte Count Registers*/
#define REG_MSADMAC2_CBCR0..7:Primary11                   ASR_ADDR(REGS_MSADMAC2_BASE, 0xBC)/*Channel Byte Count Registers*/
#define REG_MSADMAC1_CCR0..7:Primary0                     ASR_ADDR(REGS_MSADMAC1_BASE, 0x1C)/*Channel Control Registers*/
#define REG_MSADMAC2_CCR0..7:Primary0                     ASR_ADDR(REGS_MSADMAC2_BASE, 0x1C)/*Channel Control Registers*/
#define REG_MSADMAC1_CCR0..7:Primary1                     ASR_ADDR(REGS_MSADMAC1_BASE, 0x2C)/*Channel Control Registers*/
#define REG_MSADMAC2_CCR0..7:Primary1                     ASR_ADDR(REGS_MSADMAC2_BASE, 0x2C)/*Channel Control Registers*/
#define REG_MSADMAC1_CCR0..7:Primary2                     ASR_ADDR(REGS_MSADMAC1_BASE, 0x3C)/*Channel Control Registers*/
#define REG_MSADMAC2_CCR0..7:Primary2                     ASR_ADDR(REGS_MSADMAC2_BASE, 0x3C)/*Channel Control Registers*/
#define REG_MSADMAC1_CCR0..7:Primary3                     ASR_ADDR(REGS_MSADMAC1_BASE, 0x4C)/*Channel Control Registers*/
#define REG_MSADMAC2_CCR0..7:Primary3                     ASR_ADDR(REGS_MSADMAC2_BASE, 0x4C)/*Channel Control Registers*/
#define REG_MSADMAC1_CCR0..7:Primary4                     ASR_ADDR(REGS_MSADMAC1_BASE, 0x5C)/*Channel Control Registers*/
#define REG_MSADMAC2_CCR0..7:Primary4                     ASR_ADDR(REGS_MSADMAC2_BASE, 0x5C)/*Channel Control Registers*/
#define REG_MSADMAC1_CCR0..7:Primary5                     ASR_ADDR(REGS_MSADMAC1_BASE, 0x6C)/*Channel Control Registers*/
#define REG_MSADMAC2_CCR0..7:Primary5                     ASR_ADDR(REGS_MSADMAC2_BASE, 0x6C)/*Channel Control Registers*/
#define REG_MSADMAC1_CCR0..7:Primary6                     ASR_ADDR(REGS_MSADMAC1_BASE, 0x7C)/*Channel Control Registers*/
#define REG_MSADMAC2_CCR0..7:Primary6                     ASR_ADDR(REGS_MSADMAC2_BASE, 0x7C)/*Channel Control Registers*/
#define REG_MSADMAC1_CCR0..7:Primary7                     ASR_ADDR(REGS_MSADMAC1_BASE, 0x8C)/*Channel Control Registers*/
#define REG_MSADMAC2_CCR0..7:Primary7                     ASR_ADDR(REGS_MSADMAC2_BASE, 0x8C)/*Channel Control Registers*/
#define REG_MSADMAC1_CCR0..3:Secondary0                   ASR_ADDR(REGS_MSADMAC1_BASE, 0xC0)/*Channel Control Registers*/
#define REG_MSADMAC2_CCR0..3:Secondary0                   ASR_ADDR(REGS_MSADMAC2_BASE, 0xC0)/*Channel Control Registers*/
#define REG_MSADMAC1_CCR0..3:Secondary1                   ASR_ADDR(REGS_MSADMAC1_BASE, 0xC4)/*Channel Control Registers*/
#define REG_MSADMAC2_CCR0..3:Secondary1                   ASR_ADDR(REGS_MSADMAC2_BASE, 0xC4)/*Channel Control Registers*/
#define REG_MSADMAC1_CCR0..3:Secondary2                   ASR_ADDR(REGS_MSADMAC1_BASE, 0xC8)/*Channel Control Registers*/
#define REG_MSADMAC2_CCR0..3:Secondary2                   ASR_ADDR(REGS_MSADMAC2_BASE, 0xC8)/*Channel Control Registers*/
#define REG_MSADMAC1_CCR0..3:Secondary3                   ASR_ADDR(REGS_MSADMAC1_BASE, 0xCC)/*Channel Control Registers*/
#define REG_MSADMAC2_CCR0..3:Secondary3                   ASR_ADDR(REGS_MSADMAC2_BASE, 0xCC)/*Channel Control Registers*/



/* bits definitions for register REG_MSADMAC2_DCR */
#define BIT_START_STATUS_0                                ( BIT(31) )
#define BIT_START_STATUS_1                                ( BIT(30) )
#define BIT_START_STATUS_2                                ( BIT(29) )
#define BIT_START_STATUS_3                                ( BIT(28) )
#define BIT_START_STATUS_4                                ( BIT(27) )
#define BIT_START_STATUS_5                                ( BIT(26) )
#define BIT_START_STATUS_6                                ( BIT(25) )
#define BIT_START_STATUS_7                                ( BIT(24) )
#define BIT_TERM_CHANNEL_0                                ( BIT(23) )
#define BIT_TERM_CHANNEL_1                                ( BIT(22) )
#define BIT_TERM_CHANNEL_2                                ( BIT(21) )
#define BIT_TERM_CHANNEL_3                                ( BIT(20) )
#define BIT_TERM_CHANNEL_4                                ( BIT(19) )
#define BIT_TERM_CHANNEL_5                                ( BIT(18) )
#define BIT_TERM_CHANNEL_6                                ( BIT(17) )
#define BIT_TERM_CHANNEL_7                                ( BIT(16) )

/* bits definitions for register REG_MSADMAC2_DESR */
#define BIT_MV0                                           ( BIT(31) )
#define BIT_MV1                                           ( BIT(30) )
#define BIT_MV2                                           ( BIT(29) )
#define BIT_MV3                                           ( BIT(28) )
#define BIT_MV4                                           ( BIT(27) )
#define BIT_MV5                                           ( BIT(26) )
#define BIT_MV6                                           ( BIT(25) )
#define BIT_MV7                                           ( BIT(24) )
#define BIT_DE0                                           ( BIT(23) )
#define BIT_DE1                                           ( BIT(22) )
#define BIT_DE2                                           ( BIT(21) )
#define BIT_DE3                                           ( BIT(20) )
#define BIT_DE4                                           ( BIT(19) )
#define BIT_DE5                                           ( BIT(18) )
#define BIT_DE6                                           ( BIT(17) )
#define BIT_DE7                                           ( BIT(16) )
#define BIT_OV0                                           ( BIT(7) )
#define BIT_OV1                                           ( BIT(6) )
#define BIT_OV2                                           ( BIT(5) )
#define BIT_OV3                                           ( BIT(4) )
#define BIT_OV4                                           ( BIT(3) )
#define BIT_OV5                                           ( BIT(2) )
#define BIT_OV6                                           ( BIT(1) )
#define BIT_OV7                                           ( BIT(0) )

/* bits definitions for register REG_MSADMAC2_CSAR0..7:Primary11 */
#define BITS_SA(_X_)                                      (_X_)

/* bits definitions for register REG_MSADMAC2_CDAR0..7:Primary11 */
#define BITS_DA(_X_)                                      (_X_)

/* bits definitions for register REG_MSADMAC2_CBCR0..7:Primary11 */
#define BITS_PLEN(_X_)                                    ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_EWD                                           ( BIT(15) )
#define BIT_EWOD                                          ( BIT(14) )
#define BITS_PCNT(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_MSADMAC2_CCR0..7:Primary7 */
#define BIT_GE                                            ( BIT(31) )
#define BIT_IE                                            ( BIT(29) )
#define BITS_TSZ130(_X_)                                  ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BITS_SAPM132(_X_)                                 ( (_X_) << 20 & (BIT(20)|BIT(21)) )
#define BITS_DAPM133(_X_)                                 ( (_X_) << 18 & (BIT(18)|BIT(19)) )
#define BIT_TD135                                         ( BIT(16) )
#define BITS_RTCM137(_X_)                                 ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for register REG_MSADMAC2_CCR0..3:Secondary3 */
#define BIT_TE                                            ( BIT(26) )
#define BIT_TI                                            ( BIT(25) )
#define BIT_TS                                            ( BIT(24) )
#define BITS_TSZ149(_X_)                                  ( (_X_) << 22 & (BIT(22)|BIT(23)) )
#define BITS_SAPM151(_X_)                                 ( (_X_) << 20 & (BIT(20)|BIT(21)) )
#define BITS_DAPM152(_X_)                                 ( (_X_) << 18 & (BIT(18)|BIT(19)) )
#define BIT_TD154                                         ( BIT(16) )
#define BITS_RTCM156(_X_)                                 ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)) )

#endif
