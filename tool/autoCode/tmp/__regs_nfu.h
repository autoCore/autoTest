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


#ifndef __H_REGS_NFU_HEADFILE_H__
#define __H_REGS_NFU_HEADFILE_H__ __FILE__

#define	REGS_NFU

/* registers definitions for NFU */
#define REG_NFU_NFU_DCR                                   ASR_ADDR(REGS_NFU_BASE, 0X00)/*Data Flash Control Register*/
#define REG_NFU_NFU_DTR0CS0                               ASR_ADDR(REGS_NFU_BASE, 0X04)/*Data Controller Timing Parameter 0 Register for ND_CS0n*/
#define REG_NFU_NFU_DTR1CS0                               ASR_ADDR(REGS_NFU_BASE, 0X0C)/*Data Controller Timing Parameter 1 Register for ND_CS0n*/
#define REG_NFU_NFU_DSR                                   ASR_ADDR(REGS_NFU_BASE, 0X14)/*Data Controller Status Register*/
#define REG_NFU_NFU_DPCR                                  ASR_ADDR(REGS_NFU_BASE, 0X18)/*Data Controller Page Count Register*/
#define REG_NFU_NFU_DBBRx                                 ASR_ADDR(REGS_NFU_BASE, 0X1C)/*Data Controller Bad Block Registers 0 and 1*/
#define REG_NFU_NFU_DREDEL                                ASR_ADDR(REGS_NFU_BASE, 0X24)/*Read Enable Return Delay Register*/
#define REG_NFU_NFU_DECCCTRL                              ASR_ADDR(REGS_NFU_BASE, 0X28)/*ECC Control Register*/
#define REG_NFU_NFU_DBZCNT                                ASR_ADDR(REGS_NFU_BASE, 0X2C)/*Timer for ND_RnB0 and ND_RnB1*/
#define REG_NFU_NFU_DMUTEX                                ASR_ADDR(REGS_NFU_BASE, 0X30)/*NAND Controller MUTEX Lock Register*/
#define REG_NFU_NFU_DCMDMAT                               ASR_ADDR(REGS_NFU_BASE, 0X34)/*Partition Command Match Registers*/
#define REG_NFU_NFU_DDB                                   ASR_ADDR(REGS_NFU_BASE, 0X40)/*Data Controller Data Buffer Register*/
#define REG_NFU_NFU_DCB0                                  ASR_ADDR(REGS_NFU_BASE, 0X48)/*Data Controller Command Buffer 0*/
#define REG_NFU_NDCB1                                     ASR_ADDR(REGS_NFU_BASE, 0X4C)/*Data Controller Command Buffer 1*/
#define REG_NFU_NDCB2                                     ASR_ADDR(REGS_NFU_BASE, 0X50)/*Data Controller Command Buffer 2*/
#define REG_NFU_NDCB3                                     ASR_ADDR(REGS_NFU_BASE, 0X54)/*Data Controller Command Buffer 3*/
#define REG_NFU_NSACR                                     ASR_ADDR(REGS_NFU_BASE, 0X58)/*SRAM Attributes Control Register*/
#define REG_NFU_NDARBCR                                   ASR_ADDR(REGS_NFU_BASE, 0X5C)/*NAND DFI Arbitration Control Register*/
#define REG_NFU_NDPTXCSX                                  ASR_ADDR(REGS_NFU_BASE, 0X60)/*Partition Region Control Registers for CS0 and CS1*/



/* bits definitions for register REG_NFU_NFU_DCR */
#define BIT_SPARE_EN                                      ( BIT(31) )
#define BIT_ECC_EN                                        ( BIT(30) )
#define BIT_NF_DMA_EN22                                   ( BIT(29) )
#define BIT_ND_RUN                                        ( BIT(28) )
#define BIT_DWIDTH_C                                      ( BIT(27) )
#define BIT_DWIDTH_M                                      ( BIT(26) )
#define BITS_PAGE_SZ(_X_)                                 ( (_X_) << 24 & (BIT(24)|BIT(25)) )
#define BIT_SEQ_DIS                                       ( BIT(23) )
#define BIT_ND_STOP                                       ( BIT(22) )
#define BIT_FORCE_CSX                                     ( BIT(21) )
#define BIT_CLR_PG_CNT                                    ( BIT(20) )
#define BIT_STOP_ON_UNCOR                                 ( BIT(19) )
#define BITS_RD_ID_CNT(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_RA_START                                      ( BIT(15) )
#define BITS_PG_PER_BLK(_X_)                              ( (_X_) << 13 & (BIT(13)|BIT(14)) )
#define BIT_ND_ARB_EN                                     ( BIT(12) )
#define BIT_RDYM                                          ( BIT(11) )
#define BIT_CS0_PAGEDM                                    ( BIT(10) )
#define BIT_CS1_PAGEDM                                    ( BIT(9) )
#define BIT_CS0_CMDDM                                     ( BIT(8) )
#define BIT_CS1_CMDDM                                     ( BIT(7) )
#define BIT_CS0_BBDM                                      ( BIT(6) )
#define BIT_CS1_BBDM                                      ( BIT(5) )
#define BIT_UNCERRM                                       ( BIT(4) )
#define BIT_CORERRM                                       ( BIT(3) )
#define BIT_WRDREQM                                       ( BIT(2) )
#define BIT_RDDREQM                                       ( BIT(1) )
#define BIT_WRCMDREQM                                     ( BIT(0) )

/* bits definitions for register REG_NFU_NFU_DTR0CS0 */
#define BITS_TADL_X_ND(_X_)                               ( (_X_) << 27 & (BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_SELCNTR                                       ( BIT(26) )
#define BITS_RD_CNT_DEL(_X_)                              ( (_X_) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BITS_TCH(_X_)                                     ( (_X_) << 19 & (BIT(19)|BIT(20)|BIT(21)) )
#define BITS_TCS(_X_)                                     ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BITS_TWH(_X_)                                     ( (_X_) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BITS_TWP(_X_)                                     ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_SEL_NRE_EDGE                                  ( BIT(7) )
#define BIT_ETRP                                          ( BIT(6) )
#define BITS_TRH(_X_)                                     ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)) )
#define BITS_TRP(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_NFU_NFU_DTR1CS0 */
#define BITS_TR(_X_)                                      ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_WAIT_MODE                                     ( BIT(15) )
#define BIT_TR_PRESCALE                                   ( BIT(14) )
#define BITS_TRHW_X(_X_)                                  ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_TWHR(_X_)                                    ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_TAR(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_NFU_NFU_DSR */
#define BITS_ERR_CNT(_X_)                                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BIT_TRUSTVIO                                      ( BIT(15) )
#define BIT_RDY109                                        ( BIT(12) )
#define BIT_RDY111                                        ( BIT(11) )
#define BIT_CS0_PAGED                                     ( BIT(10) )
#define BIT_CS1_PAGED                                     ( BIT(9) )
#define BIT_CS0_CMDD                                      ( BIT(8) )
#define BIT_CS1_CMDD                                      ( BIT(7) )
#define BIT_CS0_BBD                                       ( BIT(6) )
#define BIT_CS1_BBD                                       ( BIT(5) )
#define BIT_UNCERR                                        ( BIT(4) )
#define BIT_CORERR                                        ( BIT(3) )
#define BIT_WRDREQ                                        ( BIT(2) )
#define BIT_RDDREQ                                        ( BIT(1) )
#define BIT_WRCMDREQ                                      ( BIT(0) )

/* bits definitions for register REG_NFU_NFU_DPCR */
#define BITS_PG_CNT_1(_X_)                                ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_PG_CNT_0(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_NFU_NFU_DBBRx */
#define BITS_BAD_BLOCK_INFORMATION(_X_)                   (_X_)

/* bits definitions for register REG_NFU_NFU_DREDEL */
#define BIT_ND_DIN_SEL                                    ( BIT(25) )
#define BITS_ND_DATA_DLY(_X_)                             ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_ND_RECLK_DLY(_X_)                            ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_ND_RE_DLY(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_NFU_NFU_DECCCTRL */
#define BITS_ECC_SPARE(_X_)                               ( (_X_) << 7 & (BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_ECC_THRESH(_X_)                              ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_BCH_EN                                        ( BIT(0) )

/* bits definitions for register REG_NFU_NFU_DBZCNT */
#define BITS_ND_RNBCNT1(_X_)                              ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_ND_RNBCNT0(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_NFU_NFU_DMUTEX */
#define BIT_MUTEX                                         ( BIT(0) )

/* bits definitions for register REG_NFU_NFU_DCMDMAT */
#define BITS_VALIDCNT(_X_)                                ( (_X_) << 30 & (BIT(30)|BIT(31)) )
#define BIT_NAKEDDIS217                                   ( BIT(29) )
#define BIT_ROWADD218                                     ( BIT(28) )
#define BITS_NF_CMD219(_X_)                               ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_NAKEDDIS220                                   ( BIT(19) )
#define BIT_ROWADD221                                     ( BIT(18) )
#define BITS_NF_CMD222(_X_)                               ( (_X_) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_NAKEDDIS223                                   ( BIT(9) )
#define BIT_ROWADD224                                     ( BIT(8) )
#define BITS_NF_CMD225(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_NFU_NFU_DDB */
#define BITS_NAND_FLASH_DATA(_X_)                         (_X_)

/* bits definitions for register REG_NFU_NFU_DCB0 */
#define BITS_CMD_XTYPE(_X_)                               ( (_X_) << 29 & (BIT(29)|BIT(30)|BIT(31)) )
#define BIT_LEN_OVRD                                      ( BIT(28) )
#define BIT_RDY_BYP                                       ( BIT(27) )
#define BIT_ST_ROW_EN                                     ( BIT(26) )
#define BIT_AUTO_RS                                       ( BIT(25) )
#define BIT_CSEL                                          ( BIT(24) )
#define BITS_NF_CMD_TYPE255(_X_)                          ( (_X_) << 21 & (BIT(21)|BIT(22)|BIT(23)) )
#define BIT_NC                                            ( BIT(20) )
#define BIT_DBC                                           ( BIT(19) )
#define BITS_ADDR_CYC(_X_)                                ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BITS_CMD2(_X_)                                    ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_CMD1(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_NFU_NDCB1 */
#define BITS_ADDR4(_X_)                                   ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_ADDR3(_X_)                                   ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_ADDR2(_X_)                                   ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_ADDR1(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_NFU_NDCB2 */
#define BITS_ST_MASK(_X_)                                 ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_ST_CMD(_X_)                                  ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_PAGE_COUNT(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_ADDR5(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_NFU_NDCB3 */
#define BITS_ADDR7(_X_)                                   ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_ADDR6(_X_)                                   ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_NDLENCNT(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_NFU_NSACR */
#define BIT_PWDN                                          ( BIT(4) )
#define BITS_NF_WTC309(_X_)                               ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_NF_RTC310(_X_)                               ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_NFU_NDARBCR */
#define BITS_ARB_CNT(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_NFU_NDPTXCSX */
#define BIT_VALID                                         ( BIT(31) )
#define BIT_LOCK                                          ( BIT(30) )
#define BIT_TRUSTED                                       ( BIT(29) )
#define BITS_BLOCKADD(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )

#endif
