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


#ifndef __H_REGS_MSACORE_HEADFILE_H__
#define __H_REGS_MSACORE_HEADFILE_H__ __FILE__

#define	REGS_MSACORE

/* registers definitions for MSACORE */
#define REG_MSACORE_DMEM_CONTROL                          ASR_ADDR(REGS_MSACORE_BASE, 0X0004)/*Data Memory Control Register*/
#define REG_MSACORE_DATA_FAULT_STATUS                     ASR_ADDR(REGS_MSACORE_BASE, 0X0008)/*Data Fault Status Register*/
#define REG_MSACORE_DATA_FAULT_ADDR                       ASR_ADDR(REGS_MSACORE_BASE, 0X000C)/*Data Fault Addr Register*/
#define REG_MSACORE_DCPLB_ADDR                            ASR_ADDR(REGS_MSACORE_BASE, 0X0100)/*Data CPLB Address Register*/
#define REG_MSACORE_DCPLB_DATA                            ASR_ADDR(REGS_MSACORE_BASE, 0X0200)/*Data CPLB Data Register*/
#define REG_MSACORE_DTEST_COMMAND_SRAM                    ASR_ADDR(REGS_MSACORE_BASE, 0X0300)/*DTEST Command Register (when accessing SRAM)*/
#define REG_MSACORE_DTEST_COMMAND_CACHE                   ASR_ADDR(REGS_MSACORE_BASE, 0X0300)/*DTEST Command Register (when accessing cache data array or cache tag array)*/
#define REG_MSACORE_DTESTDATA1_SRAM                       ASR_ADDR(REGS_MSACORE_BASE, 0X0404)/*DTEST DATA1 Register (when accessing SRAM or cache data array)*/
#define REG_MSACORE_DTESTDATA1_CACHE                      ASR_ADDR(REGS_MSACORE_BASE, 0X0404)/*DTEST DATA1 Register (when accessing cache tag array)*/
#define REG_MSACORE_DTESTDATA0_SRAM_CACHE_DATA            ASR_ADDR(REGS_MSACORE_BASE, 0X0400)/*DTEST DATA0 Register (when accessing SRAM or cache data array)*/
#define REG_MSACORE_DTESTDATA0_CACHE_TAG                  ASR_ADDR(REGS_MSACORE_BASE, 0X0400)/*DTEST DATA0 Register (when accessing cache tag array)*/
#define REG_MSACORE_DMEM_TESTMODE                         ASR_ADDR(REGS_MSACORE_BASE, 0X0500)/*DMEM Test Mode Register*/
#define REG_MSACORE_IMEM_CONTROL                          ASR_ADDR(REGS_MSACORE_BASE, 0X1004)/*Instruction Memory Control Register*/
#define REG_MSACORE_ICPLB_ADDR                            ASR_ADDR(REGS_MSACORE_BASE, 0X1100)/*Instruction CPLB Address Register*/
#define REG_MSACORE_ICPLB_DATA                            ASR_ADDR(REGS_MSACORE_BASE, 0X1200)/*Instruction CPLB Data Register*/
#define REG_MSACORE_ITEST_COMMAND_SRAM                    ASR_ADDR(REGS_MSACORE_BASE, 0X1300)/*ITEST Command Register (when accessing SRAM)*/
#define REG_MSACORE_ITEST_COMMAND_CACHE                   ASR_ADDR(REGS_MSACORE_BASE, 0X1300)/*ITEST Command Register (when accessing cache data array or cache tag array)*/
#define REG_MSACORE_ITEST_DATA0_SRAM_CACHE_DATA           ASR_ADDR(REGS_MSACORE_BASE, 0X1400)/*ITEST DATA0 Register (when accessing SRAM or cache data array)*/
#define REG_MSACORE_ITEST_DATA0_CACHE_TAG                 ASR_ADDR(REGS_MSACORE_BASE, 0X1400)/*ITEST DATA0 Register (when accessing cache tag array)*/
#define REG_MSACORE_ITEST_DATA1_SRAM_CACHE_DATA           ASR_ADDR(REGS_MSACORE_BASE, 0X1404)/*ITEST DATA1 Register (when accessing SRAM or cache data array)*/
#define REG_MSACORE_ITEST_DATA1_CACHE_TAG                 ASR_ADDR(REGS_MSACORE_BASE, 0X1404)/*ITEST DATA1 Register (when accessing cache tag array)*/
#define REG_MSACORE_IMEM_TESTMODE                         ASR_ADDR(REGS_MSACORE_BASE, 0X1500)/*IMEM Test Mode Register*/



/* bits definitions for register REG_MSACORE_DMEM_CONTROL */
#define BIT_WB_ORDER                                      ( BIT(2) )
#define BIT_ENDCPLB                                       ( BIT(1) )
#define BIT_ENDCACHE                                      ( BIT(0) )

/* bits definitions for register REG_MSACORE_DATA_FAULT_STATUS */
#define BIT_FAULT_WB                                      ( BIT(21) )
#define BIT_FAULT_TESTSET                                 ( BIT(20) )
#define BIT_FAULT_ILLADDR                                 ( BIT(19) )
#define BIT_FAULT_DAG                                     ( BIT(18) )
#define BIT_FAULT_USERSUPV                                ( BIT(17) )
#define BIT_FAULT_READWRITE                               ( BIT(16) )
#define BITS_FAULT15:0(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_MSACORE_DATA_FAULT_ADDR */
#define BITS_FAULT_ADDR(_X_)                              (_X_)

/* bits definitions for register REG_MSACORE_DCPLB_ADDR */
#define BITS_PAGE_BASE44(_X_)                             ( (_X_) << 14 & (BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_MSACORE_DCPLB_DATA */
#define BITS_PAGE_SIZE53(_X_)                             ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_CPLB_WT                                       ( BIT(14) )
#define BIT_CPLB_L1_CHBL57                                ( BIT(12) )
#define BIT_CPLB_NSPEC_LD                                 ( BIT(8) )
#define BIT_CPLB_DIRTY                                    ( BIT(7) )
#define BIT_CPLB_SUPV_WR                                  ( BIT(4) )
#define BIT_CPLB_USER_WR                                  ( BIT(3) )
#define BIT_CPLB_USER_RD63                                ( BIT(2) )
#define BIT_CPLB_LOCK64                                   ( BIT(1) )
#define BIT_CPLB_VALID65                                  ( BIT(0) )

/* bits definitions for register REG_MSACORE_DTEST_COMMAND_SRAM */
#define BITS_ISRAM_ADDR73(_X_)                            ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BIT_SRAM_SEL                                      ( BIT(2) )
#define BIT_RW_CMD75                                      ( BIT(1) )
#define BIT_SC_SEL76                                      ( BIT(0) )

/* bits definitions for register REG_MSACORE_DTEST_COMMAND_CACHE */
#define BITS_WAY_IDX84(_X_)                               ( (_X_) << 26 & (BIT(26)|BIT(27)) )
#define BITS_BANK_IDX86(_X_)                              ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_SET_IDX88(_X_)                               ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BITS_DW_IDX89(_X_)                                ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BIT_DT_SEL91                                      ( BIT(2) )
#define BIT_RW_CMD92                                      ( BIT(1) )
#define BIT_SC_SEL93                                      ( BIT(0) )

/* bits definitions for register REG_MSACORE_DTESTDATA1_SRAM */
#define BITS_DATA63:32100(_X_)                            (_X_)

/* bits definitions for register REG_MSACORE_DTESTDATA1_CACHE */

/* bits definitions for register REG_MSACORE_DTESTDATA0_SRAM_CACHE_DATA */
#define BITS_DATA31:0114(_X_)                             (_X_)

/* bits definitions for register REG_MSACORE_DTESTDATA0_CACHE_TAG */
#define BITS_TAG13:2122(_X_)                              ( (_X_) << 14 & (BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BITS_TAG1:0124(_X_)                               ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BIT_WB                                            ( BIT(8) )
#define BITS_LRU5:0127(_X_)                               ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DIRTY                                         ( BIT(1) )
#define BIT_VALID129                                      ( BIT(0) )

/* bits definitions for register REG_MSACORE_DMEM_TESTMODE */
#define BITS_MSACO_138(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_MSACORE_IMEM_CONTROL */
#define BIT_ENICPLB                                       ( BIT(1) )
#define BIT_ENICACHE                                      ( BIT(0) )

/* bits definitions for register REG_MSACORE_ICPLB_ADDR */
#define BITS_PAGE_BASE154(_X_)                            ( (_X_) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_MSACORE_ICPLB_DATA */
#define BITS_PAGE_SIZE163(_X_)                            ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_CPLB_L1_CHBL165                               ( BIT(12) )
#define BIT_CPLB_USER_RD167                               ( BIT(2) )
#define BIT_CPLB_LOCK168                                  ( BIT(1) )
#define BIT_CPLB_VALID169                                 ( BIT(0) )

/* bits definitions for register REG_MSACORE_ITEST_COMMAND_SRAM */
#define BITS_ISRAM_ADDR177(_X_)                           ( (_X_) << 3 & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_RW_CMD179                                     ( BIT(1) )
#define BIT_SC_SEL180                                     ( BIT(0) )

/* bits definitions for register REG_MSACORE_ITEST_COMMAND_CACHE */
#define BITS_WAY_IDX188(_X_)                              ( (_X_) << 26 & (BIT(26)|BIT(27)) )
#define BITS_BANK_IDX190(_X_)                             ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_SET_IDX192(_X_)                              ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BITS_DW_IDX193(_X_)                               ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BIT_DT_SEL195                                     ( BIT(2) )
#define BIT_RW_CMD196                                     ( BIT(1) )
#define BIT_SC_SEL197                                     ( BIT(0) )

/* bits definitions for register REG_MSACORE_ITEST_DATA0_SRAM_CACHE_DATA */
#define BITS_DATA31:0204(_X_)                             (_X_)

/* bits definitions for register REG_MSACORE_ITEST_DATA0_CACHE_TAG */
#define BITS_TAG13:2212(_X_)                              ( (_X_) << 14 & (BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BITS_TAG1:0214(_X_)                               ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BITS_LRU5:0216(_X_)                               ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_VALID219                                      ( BIT(0) )

/* bits definitions for register REG_MSACORE_ITEST_DATA1_SRAM_CACHE_DATA */
#define BITS_DATA63:32226(_X_)                            (_X_)

/* bits definitions for register REG_MSACORE_ITEST_DATA1_CACHE_TAG */

/* bits definitions for register REG_MSACORE_IMEM_TESTMODE */
#define BITS_MSACO_242(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

#endif
