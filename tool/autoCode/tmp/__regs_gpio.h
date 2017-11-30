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


#ifndef __H_REGS_GPIO0GPIO1GPIO2GPIO3_HEADFILE_H__
#define __H_REGS_GPIO0GPIO1GPIO2GPIO3_HEADFILE_H__ __FILE__

#define	REGS_GPIO0,GPIO1,GPIO2,GPIO3

/* registers definitions for GPIO0GPIO1GPIO2GPIO3 */
#define REG_GPIO0_GPIO_PLR                                ASR_ADDR(REGS_GPIO0_BASE, 0X00)/*GPIO Pin-Level Register*/
#define REG_GPIO1_GPIO_PLR                                ASR_ADDR(REGS_GPIO1_BASE, 0X00)/*GPIO Pin-Level Register*/
#define REG_GPIO2_GPIO_PLR                                ASR_ADDR(REGS_GPIO2_BASE, 0X00)/*GPIO Pin-Level Register*/
#define REG_GPIO3_GPIO_PLR                                ASR_ADDR(REGS_GPIO3_BASE, 0X00)/*GPIO Pin-Level Register*/
#define REG_GPIO0_GPIO_PDR                                ASR_ADDR(REGS_GPIO0_BASE, 0X0C)/*GPIO Pin Direction Register*/
#define REG_GPIO1_GPIO_PDR                                ASR_ADDR(REGS_GPIO1_BASE, 0X0C)/*GPIO Pin Direction Register*/
#define REG_GPIO2_GPIO_PDR                                ASR_ADDR(REGS_GPIO2_BASE, 0X0C)/*GPIO Pin Direction Register*/
#define REG_GPIO3_GPIO_PDR                                ASR_ADDR(REGS_GPIO3_BASE, 0X0C)/*GPIO Pin Direction Register*/
#define REG_GPIO0_GPIO_PSR                                ASR_ADDR(REGS_GPIO0_BASE, 0X18)/*GPIO Pin Output Set Register*/
#define REG_GPIO1_GPIO_PSR                                ASR_ADDR(REGS_GPIO1_BASE, 0X18)/*GPIO Pin Output Set Register*/
#define REG_GPIO2_GPIO_PSR                                ASR_ADDR(REGS_GPIO2_BASE, 0X18)/*GPIO Pin Output Set Register*/
#define REG_GPIO3_GPIO_PSR                                ASR_ADDR(REGS_GPIO3_BASE, 0X18)/*GPIO Pin Output Set Register*/
#define REG_GPIO0_GPIO_PCR                                ASR_ADDR(REGS_GPIO0_BASE, 0X24)/*GPIO Pin Output Clear Register*/
#define REG_GPIO1_GPIO_PCR                                ASR_ADDR(REGS_GPIO1_BASE, 0X24)/*GPIO Pin Output Clear Register*/
#define REG_GPIO2_GPIO_PCR                                ASR_ADDR(REGS_GPIO2_BASE, 0X24)/*GPIO Pin Output Clear Register*/
#define REG_GPIO3_GPIO_PCR                                ASR_ADDR(REGS_GPIO3_BASE, 0X24)/*GPIO Pin Output Clear Register*/
#define REG_GPIO0_GPIO_RER                                ASR_ADDR(REGS_GPIO0_BASE, 0X30)/*GPIO Rising-Edge Detect Enable Register*/
#define REG_GPIO1_GPIO_RER                                ASR_ADDR(REGS_GPIO1_BASE, 0X30)/*GPIO Rising-Edge Detect Enable Register*/
#define REG_GPIO2_GPIO_RER                                ASR_ADDR(REGS_GPIO2_BASE, 0X30)/*GPIO Rising-Edge Detect Enable Register*/
#define REG_GPIO3_GPIO_RER                                ASR_ADDR(REGS_GPIO3_BASE, 0X30)/*GPIO Rising-Edge Detect Enable Register*/
#define REG_GPIO0_GPIO_FERx                               ASR_ADDR(REGS_GPIO0_BASE, 0X3C)/*GPIO Falling-Edge Detect Enable Register*/
#define REG_GPIO1_GPIO_FERx                               ASR_ADDR(REGS_GPIO1_BASE, 0X3C)/*GPIO Falling-Edge Detect Enable Register*/
#define REG_GPIO2_GPIO_FERx                               ASR_ADDR(REGS_GPIO2_BASE, 0X3C)/*GPIO Falling-Edge Detect Enable Register*/
#define REG_GPIO3_GPIO_FERx                               ASR_ADDR(REGS_GPIO3_BASE, 0X3C)/*GPIO Falling-Edge Detect Enable Register*/
#define REG_GPIO0_GPIO_EDR                                ASR_ADDR(REGS_GPIO0_BASE, 0X48)/*GPIO Edge Detect Status Register*/
#define REG_GPIO1_GPIO_EDR                                ASR_ADDR(REGS_GPIO1_BASE, 0X48)/*GPIO Edge Detect Status Register*/
#define REG_GPIO2_GPIO_EDR                                ASR_ADDR(REGS_GPIO2_BASE, 0X48)/*GPIO Edge Detect Status Register*/
#define REG_GPIO3_GPIO_EDR                                ASR_ADDR(REGS_GPIO3_BASE, 0X48)/*GPIO Edge Detect Status Register*/
#define REG_GPIO0_GPIO_SDR                                ASR_ADDR(REGS_GPIO0_BASE, 0X54)/*Bit-wise Set of GPIO Direction Register*/
#define REG_GPIO1_GPIO_SDR                                ASR_ADDR(REGS_GPIO1_BASE, 0X54)/*Bit-wise Set of GPIO Direction Register*/
#define REG_GPIO2_GPIO_SDR                                ASR_ADDR(REGS_GPIO2_BASE, 0X54)/*Bit-wise Set of GPIO Direction Register*/
#define REG_GPIO3_GPIO_SDR                                ASR_ADDR(REGS_GPIO3_BASE, 0X54)/*Bit-wise Set of GPIO Direction Register*/
#define REG_GPIO0_GPIO_CDR                                ASR_ADDR(REGS_GPIO0_BASE, 0X60)/*Bit-wise Clear of GPIO Direction Register*/
#define REG_GPIO1_GPIO_CDR                                ASR_ADDR(REGS_GPIO1_BASE, 0X60)/*Bit-wise Clear of GPIO Direction Register*/
#define REG_GPIO2_GPIO_CDR                                ASR_ADDR(REGS_GPIO2_BASE, 0X60)/*Bit-wise Clear of GPIO Direction Register*/
#define REG_GPIO3_GPIO_CDR                                ASR_ADDR(REGS_GPIO3_BASE, 0X60)/*Bit-wise Clear of GPIO Direction Register*/
#define REG_GPIO0_GPIO_SRERx                              ASR_ADDR(REGS_GPIO0_BASE, 0X6C)/*Bit-wise Set of GPIO Rising Edge Detect Enable Register*/
#define REG_GPIO1_GPIO_SRERx                              ASR_ADDR(REGS_GPIO1_BASE, 0X6C)/*Bit-wise Set of GPIO Rising Edge Detect Enable Register*/
#define REG_GPIO2_GPIO_SRERx                              ASR_ADDR(REGS_GPIO2_BASE, 0X6C)/*Bit-wise Set of GPIO Rising Edge Detect Enable Register*/
#define REG_GPIO3_GPIO_SRERx                              ASR_ADDR(REGS_GPIO3_BASE, 0X6C)/*Bit-wise Set of GPIO Rising Edge Detect Enable Register*/
#define REG_GPIO0_GPIO_CRERx                              ASR_ADDR(REGS_GPIO0_BASE, 0X78)/*Bit-wise Clear of GPIO Rising Edge Detect Enable Register*/
#define REG_GPIO1_GPIO_CRERx                              ASR_ADDR(REGS_GPIO1_BASE, 0X78)/*Bit-wise Clear of GPIO Rising Edge Detect Enable Register*/
#define REG_GPIO2_GPIO_CRERx                              ASR_ADDR(REGS_GPIO2_BASE, 0X78)/*Bit-wise Clear of GPIO Rising Edge Detect Enable Register*/
#define REG_GPIO3_GPIO_CRERx                              ASR_ADDR(REGS_GPIO3_BASE, 0X78)/*Bit-wise Clear of GPIO Rising Edge Detect Enable Register*/
#define REG_GPIO0_GPIO_SFER                               ASR_ADDR(REGS_GPIO0_BASE, 0X84)/*Bit-wise Set of GPIO Falling Edge Detect Enable Register*/
#define REG_GPIO1_GPIO_SFER                               ASR_ADDR(REGS_GPIO1_BASE, 0X84)/*Bit-wise Set of GPIO Falling Edge Detect Enable Register*/
#define REG_GPIO2_GPIO_SFER                               ASR_ADDR(REGS_GPIO2_BASE, 0X84)/*Bit-wise Set of GPIO Falling Edge Detect Enable Register*/
#define REG_GPIO3_GPIO_SFER                               ASR_ADDR(REGS_GPIO3_BASE, 0X84)/*Bit-wise Set of GPIO Falling Edge Detect Enable Register*/
#define REG_GPIO0_GPIO_CFER                               ASR_ADDR(REGS_GPIO0_BASE, 0X90)/*Bit-wise Clear of GPIO Falling Edge Detect Enable Register*/
#define REG_GPIO1_GPIO_CFER                               ASR_ADDR(REGS_GPIO1_BASE, 0X90)/*Bit-wise Clear of GPIO Falling Edge Detect Enable Register*/
#define REG_GPIO2_GPIO_CFER                               ASR_ADDR(REGS_GPIO2_BASE, 0X90)/*Bit-wise Clear of GPIO Falling Edge Detect Enable Register*/
#define REG_GPIO3_GPIO_CFER                               ASR_ADDR(REGS_GPIO3_BASE, 0X90)/*Bit-wise Clear of GPIO Falling Edge Detect Enable Register*/
#define REG_GPIO0_APMASK_REG                              ASR_ADDR(REGS_GPIO0_BASE, 0X9C)/*<var Processor: Mohawk> Bit-wise Mask of GPIO Edge Detect Register*/
#define REG_GPIO1_APMASK_REG                              ASR_ADDR(REGS_GPIO1_BASE, 0X9C)/*<var Processor: Mohawk> Bit-wise Mask of GPIO Edge Detect Register*/
#define REG_GPIO2_APMASK_REG                              ASR_ADDR(REGS_GPIO2_BASE, 0X9C)/*<var Processor: Mohawk> Bit-wise Mask of GPIO Edge Detect Register*/
#define REG_GPIO3_APMASK_REG                              ASR_ADDR(REGS_GPIO3_BASE, 0X9C)/*<var Processor: Mohawk> Bit-wise Mask of GPIO Edge Detect Register*/
#define REG_GPIO0_CPMASK_REG                              ASR_ADDR(REGS_GPIO0_BASE, 0XA8)/*<var Processor: Comm> Bit-wise Mask of GPIO Edge Detect Register*/
#define REG_GPIO1_CPMASK_REG                              ASR_ADDR(REGS_GPIO1_BASE, 0XA8)/*<var Processor: Comm> Bit-wise Mask of GPIO Edge Detect Register*/
#define REG_GPIO2_CPMASK_REG                              ASR_ADDR(REGS_GPIO2_BASE, 0XA8)/*<var Processor: Comm> Bit-wise Mask of GPIO Edge Detect Register*/
#define REG_GPIO3_CPMASK_REG                              ASR_ADDR(REGS_GPIO3_BASE, 0XA8)/*<var Processor: Comm> Bit-wise Mask of GPIO Edge Detect Register*/



/* bits definitions for register REG_GPIO3_GPIO_PLR */
#define BITS_PLX(_X_)                                     (_X_)

/* bits definitions for register REG_GPIO3_GPIO_PDR */
#define BITS_PDX65(_X_)                                   (_X_)

/* bits definitions for register REG_GPIO3_GPIO_PSR */
#define BITS_PSX(_X_)                                     (_X_)

/* bits definitions for register REG_GPIO3_GPIO_PCR */
#define BITS_PCX(_X_)                                     (_X_)

/* bits definitions for register REG_GPIO3_GPIO_RER */
#define BITS_REX(_X_)                                     (_X_)

/* bits definitions for register REG_GPIO3_GPIO_FERx */
#define BITS_FEX(_X_)                                     (_X_)

/* bits definitions for register REG_GPIO3_GPIO_EDR */
#define BITS_EDX(_X_)                                     (_X_)

/* bits definitions for register REG_GPIO3_GPIO_SDR */
#define BITS_PDX150(_X_)                                  (_X_)

/* bits definitions for register REG_GPIO3_GPIO_CDR */
#define BITS_PDX165(_X_)                                  (_X_)

/* bits definitions for register REG_GPIO3_GPIO_SRERx */
#define BITS_PDX183(_X_)                                  (_X_)

/* bits definitions for register REG_GPIO3_GPIO_CRERx */
#define BITS_PDX190(_X_)                                  (_X_)

/* bits definitions for register REG_GPIO3_GPIO_SFER */
#define BITS_PDX208(_X_)                                  (_X_)

/* bits definitions for register REG_GPIO3_GPIO_CFER */
#define BITS_PDX215(_X_)                                  (_X_)

/* bits definitions for register REG_GPIO3_APMASK_REG */
#define BITS_PDX222(_X_)                                  (_X_)

/* bits definitions for register REG_GPIO3_CPMASK_REG */
#define BITS_PDX229(_X_)                                  (_X_)

#endif
