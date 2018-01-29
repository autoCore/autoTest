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


#ifndef __H_REGS_DIGRFRXASPEC_HEADFILE_H__
#define __H_REGS_DIGRFRXASPEC_HEADFILE_H__ __FILE__

#define	REGS_DIGRFRXASPEC

/* registers definitions for DIGRFRXASPEC */
#define REG_DIGRFRXASPEC_DIGRF_RX_SW_RST                  ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0000)/*RX Sampler Software Reset Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_DATA_A_SW_RST           ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0004)/*RX DATA A FIFO Software Reset Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_DATA_BD_SW_RST          ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0008)/*DATA BD FIFO Software Reset Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_DATA_C_SW_RST           ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X000C)/*DATA C FIFO Software Reset Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_IFC_PRI_SW_RST          ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0010)/*Primary IFC FIFO Software Reset Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_RFICUS_PRI_SW_RST       ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0014)/*Primary RFICUS FIFO Software Reset Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_RFICR_PRI_SW_RST        ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0018)/*Primary RFICR FIFO Software Reset Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_IFC_DIV_SW_RST          ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X001C)/*Diversity IFC FIFO Software Reset Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_RFICUS_DIV_SW_RST       ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0020)/*Diversity RFICUS FIFO Software Reset Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_RFICR_DIV_SW_RST        ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0024)/*Diversity RFICR FIFO Software Reset Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_LCT_TBL_PRI             ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0028)/*LCT Table Configuration for Primary FIFOS Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_LCT_TBL_DIV             ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X002C)/*LCT Table Configuration for Diversity FIFOS Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_DATA_A_THD              ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0030)/*Threshold Configuration for DATA A FIFO flags Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_DATA_BD_THD             ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0034)/*Threshold Configuration for DATA BD FIFO Flags Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_DATA_C_THD              ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0038)/*Threshold Configuration for DATA C FIFO Flags Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_DATA_BD_SEL             ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X003C)/*DATA BD FIFO in WB or GSM Mode Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_DATA_DMA_SKIP           ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0040)/*Configure the DATA A & BD FIFOs Interface to DMA Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_MODES                   ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0044)/*Operational Modes Configuration Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_2_RFIC_SEL              ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0048)/*Support of 2 RFICs Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_FORCE_PHASE             ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X004C)/*Sampling Phase Configuration (debug mode) Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_IQ_SWAP                 ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0050)/*Swap I & Q Bits Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_LATCH_STATUS            ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0054)/*Status Latch Command Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_RD_STATUS               ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0058)/*Read Latched Status Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_CLR_STICKY              ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X005C)/*Clear Sticky Bits Register*/
#define REG_DIGRFRXASPEC_DIGRF_RX_SHUTDOWN                ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0060)/*Line-Receiver Shutdown Register*/
#define REG_DIGRFRXASPEC_RFICUS_RFICR_PRI_PSx             ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0200)/*Primary RFICUS FIFO PS Value Register*/
#define REG_DIGRFRXASPEC_IFC_PRI_RD__LAST                 ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0300)/*Read Payload Data From Primary IFC FIFO/Last Register*/
#define REG_DIGRFRXASPEC_RFICUS_RFICR_PRI_RD_LAST         ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0308)/*Read Payload Data From Primary RFICUS/RFICR FIFO/Last Register*/
#define REG_DIGRFRXASPEC_RX_PRI_FIFOS_INT_HANDLE_W        ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0318)/*Select Primary FIFO To Which to Write Payload (write access) Register*/
#define REG_DIGRFRXASPEC_RX_PRI_FIFOS_INT_HANDLE_R        ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0318)/*Select Primary FIFO From Which to Read Payload (read access) Register*/
#define REG_DIGRFRXASPEC_RFICUS_RFICR_DIV_PSx             ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0400)/*Payload Size of Diversity RFICUS/RFICR FIFO/Last Register*/
#define REG_DIGRFRXASPEC_IFC_DIV_RD__LAST                 ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0500)/*Read Payload From Diversity IFC FIFO/Last Register*/
#define REG_DIGRFRXASPEC_RFICUS_RFICR_PRI_RD_LAST         ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0508)/*Read Payload From Diversity RFICUS/RFICR FIFO/Last Register*/
#define REG_DIGRFRXASPEC_RX_DIV_FIFOS_INT_HANDLE_W        ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0518)/*Select Diversity FIFO To Which to Write Payload (write access) Register*/
#define REG_DIGRFRXASPEC_RX_DIV_FIFOS_INT_HANDLE_R        ASR_ADDR(REGS_DIGRFRXASPEC_BASE, 0X0518)/*Select Diversity FIFO From Which to Read Payload (read access) Register*/



/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_SW_RST */
#define BIT_DIV_RESET                                     ( BIT(1) )
#define BIT_PRI_RESET                                     ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_DATA_A_SW_RST */
#define BIT_RESET22                                       ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_DATA_BD_SW_RST */
#define BIT_RESET30                                       ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_DATA_C_SW_RST */
#define BIT_RESET38                                       ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_IFC_PRI_SW_RST */
#define BIT_RESET46                                       ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_RFICUS_PRI_SW_RST */
#define BIT_RESET54                                       ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_RFICR_PRI_SW_RST */
#define BIT_RESET62                                       ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_IFC_DIV_SW_RST */
#define BIT_RESET70                                       ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_RFICUS_DIV_SW_RST */
#define BIT_RESET78                                       ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_RFICR_DIV_SW_RST */
#define BIT_RESET86                                       ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_LCT_TBL_PRI */
#define BITS_DATA_C94(_X_)                                ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_DATA_BD95(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_DATA_A96(_X_)                                ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_RFICR97(_X_)                                 ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_RFICUS98(_X_)                                ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_IFC99(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_LCT_TBL_DIV */
#define BITS_DATA_C107(_X_)                               ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_DATA_BD108(_X_)                              ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_DATA_A109(_X_)                               ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_RFICR110(_X_)                                ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_RFICUS111(_X_)                               ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_IFC112(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_DATA_A_THD */
#define BITS_O_A_THRSH(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BITS_D_A_THRSH(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_DATA_BD_THD */
#define BITS_O_BD_THRSH(_X_)                              ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BITS_D_BD_THRSH(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_DATA_C_THD */
#define BITS_O_C_THRSH(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BITS_D_C_THRSH(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_DATA_BD_SEL */
#define BIT_DATA_BD_MODE                                  ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_DATA_DMA_SKIP */
#define BIT_SKIP                                          ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_MODES */
#define BIT_DIGRF_SWTCH165                                ( BIT(31) )
#define BIT_TT_DIS                                        ( BIT(20) )
#define BITS_CLK_RATE(_X_)                                ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_FILTER_CFG(_X_)                              ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BITS_TT_INTEG(_X_)                                ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BITS_TT_CFG(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_2_RFIC_SEL */
#define BIT_SLCT                                          ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_FORCE_PHASE */
#define BIT_DIV_FORCE                                     ( BIT(20) )
#define BITS_DIV_PHASE(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PRI_FORCE                                     ( BIT(4) )
#define BITS_PRI_PHASE(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_IQ_SWAP */
#define BITS_SWAP(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_LATCH_STATUS */
#define BITS_DIGRF_CMD213(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_RD_STATUS */
#define BITS_DIGRF_STATUS225(_X_)                         (_X_)

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_CLR_STICKY */
#define BIT_D_RFICR_FIFO_INT                              ( BIT(13) )
#define BIT_D_RFICR_FIFO_OVF                              ( BIT(12) )
#define BIT_D_RFICUS_FIFO_INT                             ( BIT(11) )
#define BIT_D_RFICUS_FIFO_OVF                             ( BIT(10) )
#define BIT_D_IFC_FIFO_INT                                ( BIT(9) )
#define BIT_DIGRF_D_IFC_FIFO_OVF238                       ( BIT(8) )
#define BIT_P_RFIFCR_FIFO_INT                             ( BIT(7) )
#define BIT_P_RFICR_FIFO_OVF                              ( BIT(6) )
#define BIT_P_RFICUS_FIFO_INT                             ( BIT(5) )
#define BIT_P_RFICUS_FIFO_OVF                             ( BIT(4) )
#define BIT_P_IFC_FIFO_INT                                ( BIT(3) )
#define BIT_DIGRF_P_IFC_FIFO_OVF244                       ( BIT(2) )
#define BIT_P_SMPL_SYNC_ERR                               ( BIT(1) )
#define BIT_D_SMPL_SYNC_ERR                               ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_DIGRF_RX_SHUTDOWN */
#define BIT_DIGRF_SHTDN254                                ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_RFICUS_RFICR_PRI_PSx */
#define BITS_PS262(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_DIGRFRXASPEC_IFC_PRI_RD__LAST */
#define BITS_PYLD270(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DIGRFRXASPEC_RFICUS_RFICR_PRI_RD_LAST */
#define BITS_PYLD277(_X_)                                 (_X_)

/* bits definitions for register REG_DIGRFRXASPEC_RX_PRI_FIFOS_INT_HANDLE_W */
#define BIT_RFICR285                                      ( BIT(2) )
#define BIT_RFICUS286                                     ( BIT(1) )
#define BIT_IFC287                                        ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_RX_PRI_FIFOS_INT_HANDLE_R */
#define BITS_NUM_WRDS295(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_DIGRFRXASPEC_RFICUS_RFICR_DIV_PSx */
#define BITS_PS303(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_DIGRFRXASPEC_IFC_DIV_RD__LAST */
#define BITS_PYLD311(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DIGRFRXASPEC_RFICUS_RFICR_PRI_RD_LAST */
#define BITS_PYLD318(_X_)                                 (_X_)

/* bits definitions for register REG_DIGRFRXASPEC_RX_DIV_FIFOS_INT_HANDLE_W */
#define BIT_RFICR326                                      ( BIT(2) )
#define BIT_RFICUS327                                     ( BIT(1) )
#define BIT_IFC328                                        ( BIT(0) )

/* bits definitions for register REG_DIGRFRXASPEC_RX_DIV_FIFOS_INT_HANDLE_R */
#define BITS_NUM_WRDS336(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

#endif
