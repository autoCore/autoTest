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


#ifndef __H_REGS_AP2CPIPC_HEADFILE_H__
#define __H_REGS_AP2CPIPC_HEADFILE_H__ __FILE__

#define	REGS_AP2CPIPC

/* registers definitions for AP2CPIPC */
#define REG_AP2CPIPC_IPC_DW                               ASR_ADDR(REGS_AP2CPIPC_BASE, 0X0)/*Dummy Write Register*/
#define REG_AP2CPIPC_IPC_WDR                              ASR_ADDR(REGS_AP2CPIPC_BASE, 0X4)/*Write Data Register*/
#define REG_AP2CPIPC_IPC_ISRW                             ASR_ADDR(REGS_AP2CPIPC_BASE, 0X8)/*Interrupt Set Register Write*/
#define REG_AP2CPIPC_IPC_ICR                              ASR_ADDR(REGS_AP2CPIPC_BASE, 0XC)/*Interrupt Clear Register*/
#define REG_AP2CPIPC_IPC_IIR                              ASR_ADDR(REGS_AP2CPIPC_BASE, 0X10)/*Interrupt Identification Register*/
#define REG_AP2CPIPC_IPC_RDR                              ASR_ADDR(REGS_AP2CPIPC_BASE, 0X14)/*Read Data Register*/



/* bits definitions for register REG_AP2CPIPC_IPC_DW */
#define BITS_APB_IPC_DW(_X_)                              (_X_)

/* bits definitions for register REG_AP2CPIPC_IPC_WDR */
#define BITS_APB_IPC_WDR(_X_)                             (_X_)

/* bits definitions for register REG_AP2CPIPC_IPC_ISRW */
#define BITS_APB_IPC_ISRW(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_AP2CPIPC_IPC_ICR */
#define BITS_APB_IPC_ICR(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_AP2CPIPC_IPC_IIR */
#define BITS_APB_IPC_IIR(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_AP2CPIPC_IPC_RDR */
#define BITS_APB_IPC_RDR(_X_)                             (_X_)

#endif
