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


#ifndef __H_REGS_EIC_HEADFILE_H__
#define __H_REGS_EIC_HEADFILE_H__ __FILE__

#define	REGS_EIC

/* registers definitions for EIC */
#define REG_EIC_PISMR                                     ASR_ADDR(REGS_EIC_BASE, 0X00)/*Primary Interrupt Service Mask Register*/
#define REG_EIC_PICER                                     ASR_ADDR(REGS_EIC_BASE, 0X04)/*Primary Interrupt Capture Enable Register*/
#define REG_EIC_SISMR_H0                                  ASR_ADDR(REGS_EIC_BASE, 0x08)/*Secondary Interrupt Service Mask Registers*/
#define REG_EIC_SISMR_H1                                  ASR_ADDR(REGS_EIC_BASE, 0x0C)/*Secondary Interrupt Service Mask Registers*/
#define REG_EIC_SICER_H0                                  ASR_ADDR(REGS_EIC_BASE, 0x10)/*Secondary Interrupt Capture Enable Registers*/
#define REG_EIC_SICER_H1                                  ASR_ADDR(REGS_EIC_BASE, 0x14)/*Secondary Interrupt Capture Enable Registers*/
#define REG_EIC_SICR_H0                                   ASR_ADDR(REGS_EIC_BASE, 0x18)/*Secondary Interrupt Clear Register*/
#define REG_EIC_SICR_H1                                   ASR_ADDR(REGS_EIC_BASE, 0x1C)/*Secondary Interrupt Clear Register*/
#define REG_EIC_SIGR_H0                                   ASR_ADDR(REGS_EIC_BASE, 0x20)/*Secondary Interrupt Generate Register*/
#define REG_EIC_SIGR_H1                                   ASR_ADDR(REGS_EIC_BASE, 0x24)/*Secondary Interrupt Generate Register*/
#define REG_EIC_SIOR_H0                                   ASR_ADDR(REGS_EIC_BASE, 0x28)/*Secondary Interrupt Overflow Registers*/
#define REG_EIC_SIOR_H1                                   ASR_ADDR(REGS_EIC_BASE, 0x2C)/*Secondary Interrupt Overflow Registers*/
#define REG_EIC_SIOCR_H0                                  ASR_ADDR(REGS_EIC_BASE, 0x30)/*Secondary Interrupt Overflow Clear Registers*/
#define REG_EIC_SIOCR_H1                                  ASR_ADDR(REGS_EIC_BASE, 0x34)/*Secondary Interrupt Overflow Clear Registers*/
#define REG_EIC_SISRR_H0                                  ASR_ADDR(REGS_EIC_BASE, 0x38)/*Secondary Interrupt Service Request Register*/
#define REG_EIC_SISRR_H1                                  ASR_ADDR(REGS_EIC_BASE, 0x3C)/*Secondary Interrupt Service Request Register*/
#define REG_EIC_DWR_H0                                    ASR_ADDR(REGS_EIC_BASE, 0x40)/*Dummy Write Registers*/
#define REG_EIC_DWR_H1                                    ASR_ADDR(REGS_EIC_BASE, 0x44)/*Dummy Write Registers*/
#define REG_EIC_IBR                                       ASR_ADDR(REGS_EIC_BASE, 0X50)/*Interrupt Block Register*/



/* bits definitions for register REG_EIC_PISMR */
#define BIT_SVC_MASK_15                                   ( BIT(31) )
#define BIT_SVC_MASK_14                                   ( BIT(30) )
#define BIT_SVC_MASK_13                                   ( BIT(29) )
#define BIT_SVC_MASK_10                                   ( BIT(28) )
#define BIT_SVC_MASK_9                                    ( BIT(27) )
#define BIT_SVC_MASK_8                                    ( BIT(26) )
#define BIT_SVC_MASK_7                                    ( BIT(25) )

/* bits definitions for register REG_EIC_PICER */
#define BIT_CAPTURE_EN_15                                 ( BIT(31) )
#define BIT_CAPTURE_EN_14                                 ( BIT(30) )
#define BIT_CAPTURE_EN_13                                 ( BIT(29) )
#define BIT_CAPTURE_EN_10                                 ( BIT(28) )
#define BIT_CAPTURE_EN_9                                  ( BIT(27) )
#define BIT_CAPTURE_EN_8                                  ( BIT(26) )
#define BIT_CAPTURE_EN_7                                  ( BIT(25) )

/* bits definitions for register REG_EIC_SISMR_H1 */
#define BITS_SISMR(_X_)                                   (_X_)

/* bits definitions for register REG_EIC_SICER_H1 */
#define BITS_SICER(_X_)                                   (_X_)

/* bits definitions for register REG_EIC_SICR_H1 */
#define BITS_SICR(_X_)                                    (_X_)

/* bits definitions for register REG_EIC_SIGR_H1 */
#define BITS_SIGR(_X_)                                    (_X_)

/* bits definitions for register REG_EIC_SIOR_H1 */
#define BITS_SIOR(_X_)                                    (_X_)

/* bits definitions for register REG_EIC_SIOCR_H1 */
#define BITS_SIOCR(_X_)                                   (_X_)

/* bits definitions for register REG_EIC_SISRR_H1 */
#define BITS_SISRR(_X_)                                   (_X_)

/* bits definitions for register REG_EIC_DWR_H1 */
#define BITS_DWR(_X_)                                     (_X_)

/* bits definitions for register REG_EIC_IBR */
#define BIT_IBR                                           ( BIT(0) )

#endif
