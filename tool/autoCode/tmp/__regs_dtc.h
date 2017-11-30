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


#ifndef __H_REGS_DTC_HEADFILE_H__
#define __H_REGS_DTC_HEADFILE_H__ __FILE__

#define	REGS_DTC

/* registers definitions for DTC */
#define REG_DTC_DTC_DOCR_CSA0_10                          ASR_ADDR(REGS_DTC_BASE, 0x00)/*DTC Chain Start Address Register 0/1*/
#define REG_DTC_DTC_DOCR_CSA0_11                          ASR_ADDR(REGS_DTC_BASE, 0x8)/*DTC Chain Start Address Register 0/1*/
#define REG_DTC_DTC_DOCR_CTRL0_10                         ASR_ADDR(REGS_DTC_BASE, 0x4)/*DTC Control Register 0/1*/
#define REG_DTC_DTC_DOCR_CTRL0_11                         ASR_ADDR(REGS_DTC_BASE, 0xC)/*DTC Control Register 0/1*/
#define REG_DTC_DTC_DOCR_SW_BYPASS                        ASR_ADDR(REGS_DTC_BASE, 0X10)/*DTC Software Bypass Register*/
#define REG_DTC_DTC_F8_DTCCR_NDP                          ASR_ADDR(REGS_DTC_BASE, 0X20)/*F8 Next Descriptor Pointer Register*/
#define REG_DTC_DTC_F8_DTCCR_SA                           ASR_ADDR(REGS_DTC_BASE, 0X24)/*F8 Source Address Register*/
#define REG_DTC_DTC_F8_DTCCR_DA                           ASR_ADDR(REGS_DTC_BASE, 0X28)/*F8 Destination Address Register*/
#define REG_DTC_DTC_F8_DTCCR_CONTROL                      ASR_ADDR(REGS_DTC_BASE, 0X2C)/*F8 Control Register*/
#define REG_DTC_DTC_F8_DTCCR_HEADER_DATA                  ASR_ADDR(REGS_DTC_BASE, 0X30)/*F8 Header Register*/
#define REG_DTC_DTC_F8_DTCCR_BIT_OFFSET                   ASR_ADDR(REGS_DTC_BASE, 0X34)/*F8 Bit Offset Register*/
#define REG_DTC_DTC_F8_DTCCR_COUNT_C                      ASR_ADDR(REGS_DTC_BASE, 0X38)/*F8 Count C Register*/
#define REG_DTC_DTC_F8_DTCCR_CK_ADDR                      ASR_ADDR(REGS_DTC_BASE, 0X3C)/*F8 CK Address Register*/
#define REG_DTC_DTC_F9_DTCCR_NDP                          ASR_ADDR(REGS_DTC_BASE, 0X20)/*F9 Next Descriptor Pointer Register*/
#define REG_DTC_DTC_F9_DTCCR_SA                           ASR_ADDR(REGS_DTC_BASE, 0X24)/*F9 Source Address Register*/
#define REG_DTC_DTC_F9_DTCCR_DA                           ASR_ADDR(REGS_DTC_BASE, 0X28)/*F9 Destination Address Register*/
#define REG_DTC_DTC_F9_DTCCR_Control                      ASR_ADDR(REGS_DTC_BASE, 0X2C)/*F9 Control Register*/
#define REG_DTC_DTC_F9_DTCCR_HEADER_DATA                  ASR_ADDR(REGS_DTC_BASE, 0X30)/*F9 Header Data Register*/
#define REG_DTC_DTC_F9_DTCCR_BIT_OFFSET                   ASR_ADDR(REGS_DTC_BASE, 0X34)/*F9 Bit Offset Register*/
#define REG_DTC_DTC_F9_DTCCR_COUNT_C                      ASR_ADDR(REGS_DTC_BASE, 0X38)/*F9 Count C Register*/
#define REG_DTC_DTC_CKIK_1                                ASR_ADDR(REGS_DTC_BASE, 0X50)/*Ciphering Key Register 1*/
#define REG_DTC_DTC_CKIK_2                                ASR_ADDR(REGS_DTC_BASE, 0X54)/*Ciphering Key Register 2*/
#define REG_DTC_DTC_CKIK_3                                ASR_ADDR(REGS_DTC_BASE, 0X58)/*Ciphering Key Register 3*/
#define REG_DTC_DTC_CKIK_4                                ASR_ADDR(REGS_DTC_BASE, 0X5C)/*Ciphering Key Register 4*/
#define REG_DTC_DTC_DISR_REG                              ASR_ADDR(REGS_DTC_BASE, 0X60)/*DTC Interrupt Status Register*/
#define REG_DTC_DTC_MAC_I0_REG0                           ASR_ADDR(REGS_DTC_BASE, 0x70)/*DTC_MACI_Ch0/1 Register*/
#define REG_DTC_DTC_MAC_I0_REG1                           ASR_ADDR(REGS_DTC_BASE, 0x74)/*DTC_MACI_Ch0/1 Register*/
#define REG_DTC_DTC_MPR_HIGHn_ADDR0                       ASR_ADDR(REGS_DTC_BASE, 0x80)/*High Address Range Registers*/
#define REG_DTC_DTC_MPR_HIGHn_ADDR1                       ASR_ADDR(REGS_DTC_BASE, 0x88)/*High Address Range Registers*/
#define REG_DTC_DTC_MPR_HIGHn_ADDR2                       ASR_ADDR(REGS_DTC_BASE, 0x90)/*High Address Range Registers*/
#define REG_DTC_DTC_MPR_LOWn_ADDR0                        ASR_ADDR(REGS_DTC_BASE, 0x84)/*Low Address Range Registers*/
#define REG_DTC_DTC_MPR_LOWn_ADDR1                        ASR_ADDR(REGS_DTC_BASE, 0x8C)/*Low Address Range Registers*/
#define REG_DTC_DTC_MPR_LOWn_ADDR2                        ASR_ADDR(REGS_DTC_BASE, 0x94)/*Low Address Range Registers*/
#define REG_DTC_DTC_READ                                  ASR_ADDR(REGS_DTC_BASE, 0XA0)/*DTC Read Register*/
#define REG_DTC_DTC_WRITE                                 ASR_ADDR(REGS_DTC_BASE, 0XA4)/*DTC Write Register*/
#define REG_DTC_DTC_FIFO_READ                             ASR_ADDR(REGS_DTC_BASE, 0XC0)/*DTC FIFO Read Address Register*/
#define REG_DTC_DTC_FIFO_WRITE                            ASR_ADDR(REGS_DTC_BASE, 0XC0)/*DTC FIFO Write Address Register*/



/* bits definitions for register REG_DTC_DTC_DOCR_CSA0_11 */
#define BITS_CHAIN0_START_ADDR(_X_)                       (_X_)

/* bits definitions for register REG_DTC_DTC_DOCR_CTRL0_11 */
#define BITS_FIFO_OUT_AF_SIZE(_X_)                        ( (_X_) << 25 & (BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BITS_FIFO_OUT_AE_SIZE(_X_)                        ( (_X_) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BITS_FIFO_IN_AF_SIZE(_X_)                         ( (_X_) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BITS_FIFO_IN_AE_SIZE(_X_)                         ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_CHN_START                                     ( BIT(5) )
#define BIT_DONEINDICATION                                ( BIT(4) )
#define BITS_CHN_CEE(_X_)                                 ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_CHN_F8_F9                                     ( BIT(1) )
#define BIT_CHN_DIR                                       ( BIT(0) )

/* bits definitions for register REG_DTC_DTC_DOCR_SW_BYPASS */
#define BIT_BNDRY_EN                                      ( BIT(12) )
#define BIT_CK_BE_LE_SEL                                  ( BIT(11) )
#define BIT_SW_OVR                                        ( BIT(10) )
#define BIT_HW_EN                                         ( BIT(9) )
#define BIT_TEST_EN                                       ( BIT(8) )
#define BITS_TEST_MUX_SEL(_X_)                            ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_EHT                                           ( BIT(4) )
#define BIT_EHT_EN                                        ( BIT(3) )
#define BIT_SWM                                           ( BIT(2) )
#define BIT_SSC                                           ( BIT(1) )
#define BIT_SSM                                           ( BIT(0) )

/* bits definitions for register REG_DTC_DTC_F8_DTCCR_NDP */
#define BITS_DTCCR_NDP(_X_)                               (_X_)

/* bits definitions for register REG_DTC_DTC_F8_DTCCR_SA */
#define BITS_DTTCR_SA80(_X_)                              (_X_)

/* bits definitions for register REG_DTC_DTC_F8_DTCCR_DA */
#define BITS_DTTCR_DA(_X_)                                (_X_)

/* bits definitions for register REG_DTC_DTC_F8_DTCCR_CONTROL */
#define BIT_F8_RCS                                        ( BIT(30) )
#define BIT_F8_CB                                         ( BIT(29) )
#define BIT_F8_CONT                                       ( BIT(28) )
#define BITS_F8_CO(_X_)                                   ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BITS_F8_BEARER(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BITS_F8_LEN(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DTC_DTC_F8_DTCCR_HEADER_DATA */
#define BITS_F8_HDR_SIZE(_X_)                             ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_F8_HDR_DATA(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for register REG_DTC_DTC_F8_DTCCR_BIT_OFFSET */
#define BITS_F8_IBO(_X_)                                  ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_F8_OBO(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DTC_DTC_F8_DTCCR_COUNT_C */
#define BITS_F8_COUNTC(_X_)                               (_X_)

/* bits definitions for register REG_DTC_DTC_F8_DTCCR_CK_ADDR */
#define BITS_F8_CK_ADDR(_X_)                              (_X_)

/* bits definitions for register REG_DTC_DTC_F9_DTCCR_NDP */

/* bits definitions for register REG_DTC_DTC_F9_DTCCR_SA */
#define BITS_DTTCR_SA159(_X_)                             (_X_)

/* bits definitions for register REG_DTC_DTC_F9_DTCCR_DA */
#define BITS_F9_LEN(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )

/* bits definitions for register REG_DTC_DTC_F9_DTCCR_Control */
#define BITS_F9_FRESH(_X_)                                (_X_)

/* bits definitions for register REG_DTC_DTC_F9_DTCCR_HEADER_DATA */
#define BITS_F9_COUNTI(_X_)                               (_X_)

/* bits definitions for register REG_DTC_DTC_F9_DTCCR_BIT_OFFSET */
#define BITS_F9_IK_ADDR(_X_)                              (_X_)

/* bits definitions for register REG_DTC_DTC_F9_DTCCR_COUNT_C */
#define BITS_F9_IBO(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DTC_DTC_CKIK_1 */
#define BITS_DTC_CKIK_1(_X_)                              (_X_)

/* bits definitions for register REG_DTC_DTC_CKIK_2 */
#define BITS_DTC_CKIK_2(_X_)                              (_X_)

/* bits definitions for register REG_DTC_DTC_CKIK_3 */
#define BITS_DTC_CKIK_3(_X_)                              (_X_)

/* bits definitions for register REG_DTC_DTC_CKIK_4 */
#define BITS_DTC_CKIK_4(_X_)                              (_X_)

/* bits definitions for register REG_DTC_DTC_DISR_REG */
#define BIT_FOFFIFOOUTFULL                                ( BIT(5) )
#define BIT_MP_ERR1                                       ( BIT(4) )
#define BIT_MP_ERR0                                       ( BIT(3) )
#define BIT_MERR1                                         ( BIT(2) )
#define BIT_MERR0                                         ( BIT(1) )
#define BIT_SERR                                          ( BIT(0) )

/* bits definitions for register REG_DTC_DTC_MAC_I0_REG1 */
#define BITS_DTC_MAC_I0_1_REG(_X_)                        (_X_)

/* bits definitions for register REG_DTC_DTC_MPR_HIGHn_ADDR2 */
#define BITS_DTC_MPR0_HIGH(_X_)                           (_X_)

/* bits definitions for register REG_DTC_DTC_MPR_LOWn_ADDR2 */
#define BITS_DTC_MPR0_LOW(_X_)                            (_X_)

/* bits definitions for register REG_DTC_DTC_READ */
#define BITS_DRAR(_X_)                                    (_X_)

/* bits definitions for register REG_DTC_DTC_WRITE */
#define BITS_DWAR(_X_)                                    (_X_)

/* bits definitions for register REG_DTC_DTC_FIFO_READ */
#define BITS_DTC_FIFO_READ(_X_)                           (_X_)

/* bits definitions for register REG_DTC_DTC_FIFO_WRITE */
#define BITS_DTC_FIFO_WRITE(_X_)                          (_X_)

#endif
