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


#ifndef __H_REGS_DSSP0DSSP1DSSP2DSSP3_HEADFILE_H__
#define __H_REGS_DSSP0DSSP1DSSP2DSSP3_HEADFILE_H__ __FILE__

#define	REGS_DSSP0,DSSP1,DSSP2,DSSP3

/* registers definitions for DSSP0DSSP1DSSP2DSSP3 */
#define REG_DSSP0_DSSP_DSSPRR                             ASR_ADDR(REGS_DSSP0_BASE, 0X100)/*DSSP Reset Register*/
#define REG_DSSP1_DSSP_DSSPRR                             ASR_ADDR(REGS_DSSP1_BASE, 0X100)/*DSSP Reset Register*/
#define REG_DSSP2_DSSP_DSSPRR                             ASR_ADDR(REGS_DSSP2_BASE, 0X100)/*DSSP Reset Register*/
#define REG_DSSP3_DSSP_DSSPRR                             ASR_ADDR(REGS_DSSP3_BASE, 0X100)/*DSSP Reset Register*/
#define REG_DSSP0_DSSP_DSSPTIR                            ASR_ADDR(REGS_DSSP0_BASE, 0X104)/*DSSP Tx Interface Register*/
#define REG_DSSP1_DSSP_DSSPTIR                            ASR_ADDR(REGS_DSSP1_BASE, 0X104)/*DSSP Tx Interface Register*/
#define REG_DSSP2_DSSP_DSSPTIR                            ASR_ADDR(REGS_DSSP2_BASE, 0X104)/*DSSP Tx Interface Register*/
#define REG_DSSP3_DSSP_DSSPTIR                            ASR_ADDR(REGS_DSSP3_BASE, 0X104)/*DSSP Tx Interface Register*/
#define REG_DSSP0_DSSP_DSSPRIR                            ASR_ADDR(REGS_DSSP0_BASE, 0X108)/*DSSP Rx Interface Register*/
#define REG_DSSP1_DSSP_DSSPRIR                            ASR_ADDR(REGS_DSSP1_BASE, 0X108)/*DSSP Rx Interface Register*/
#define REG_DSSP2_DSSP_DSSPRIR                            ASR_ADDR(REGS_DSSP2_BASE, 0X108)/*DSSP Rx Interface Register*/
#define REG_DSSP3_DSSP_DSSPRIR                            ASR_ADDR(REGS_DSSP3_BASE, 0X108)/*DSSP Rx Interface Register*/
#define REG_DSSP0_DSSP_DSSPCFG                            ASR_ADDR(REGS_DSSP0_BASE, 0X10C)/*DSSP Configuration Registers*/
#define REG_DSSP1_DSSP_DSSPCFG                            ASR_ADDR(REGS_DSSP1_BASE, 0X10C)/*DSSP Configuration Registers*/
#define REG_DSSP2_DSSP_DSSPCFG                            ASR_ADDR(REGS_DSSP2_BASE, 0X10C)/*DSSP Configuration Registers*/
#define REG_DSSP3_DSSP_DSSPCFG                            ASR_ADDR(REGS_DSSP3_BASE, 0X10C)/*DSSP Configuration Registers*/



/* bits definitions for register REG_DSSP3_DSSP_DSSPRR */
#define BIT_HW_OP                                         ( BIT(2) )
#define BIT_RSSP                                          ( BIT(1) )
#define BIT_RSSPA                                         ( BIT(0) )

/* bits definitions for register REG_DSSP3_DSSP_DSSPTIR */
#define BIT_TXFRM_INV                                     ( BIT(3) )
#define BIT_DMATXREQCLR                                   ( BIT(2) )
#define BIT_TXSWOEC                                       ( BIT(1) )
#define BIT_TXSWOE                                        ( BIT(0) )

/* bits definitions for register REG_DSSP3_DSSP_DSSPRIR */
#define BIT_DMARXREQCLR                                   ( BIT(7) )
#define BITS_SCLKINSEL(_X_)                               ( (_X_) << 5 & (BIT(5)|BIT(6)) )
#define BIT_SCLKOUTSEL                                    ( BIT(4) )
#define BIT_RXCLKSEL                                      ( BIT(3) )
#define BITS_RXTXSWOEC(_X_)                               ( (_X_) << 1 & (BIT(1)|BIT(2)) )
#define BIT_RXTXSWOE                                      ( BIT(0) )

/* bits definitions for register REG_DSSP3_DSSP_DSSPCFG */
#define BIT_RDBACK_32BITS_ENABLE                          ( BIT(19) )
#define BIT_GPIO_SSPSCLK_PATH_SEL                         ( BIT(18) )
#define BITS_FRFLT_SMP_LEN(_X_)                           ( (_X_) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_FRFLT_NO_PASS__LEN_MSB                        ( BIT(10) )
#define BITS_FRFLT_NO_PASS_LEN(_X_)                       ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_FRFLT_CK_POL                                  ( BIT(3) )
#define BIT_FRFLT_FRM_OUT_POL                             ( BIT(2) )
#define BIT_FRFLT_FRM_IN_POL                              ( BIT(1) )
#define BIT_FSTRP_EN                                      ( BIT(0) )

#endif
