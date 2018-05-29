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


#ifndef __H_REGS_IOPWRDOM_HEADFILE_H__
#define __H_REGS_IOPWRDOM_HEADFILE_H__ __FILE__

#define	REGS_IOPWRDOM

/* registers definitions for IOPWRDOM */
#define REG_IOPWRDOM_AIB_NAND_IO_REG                      ASR_ADDR(REGS_IOPWRDOM_BASE, 0X0)/*AIB NAND I/O Domain Control Register*/
#define REG_IOPWRDOM_AIB_ANT_IO_REG                       ASR_ADDR(REGS_IOPWRDOM_BASE, 0X4)/*AIB ANT I/O Domain Control Register*/
#define REG_IOPWRDOM_AIB_GPIO1_IO_REG                     ASR_ADDR(REGS_IOPWRDOM_BASE, 0X8)/*AIB GPIO 1 I/O Domain Control Register*/
#define REG_IOPWRDOM_AIB_GPIO2_IO_REG                     ASR_ADDR(REGS_IOPWRDOM_BASE, 0XC)/*AIB GPIO 2 I/O Domain Control Register*/
#define REG_IOPWRDOM_AIB_GPIO4_IO_REG                     ASR_ADDR(REGS_IOPWRDOM_BASE, 0X14)/*AIB GPIO4 I/O Domain Control Register*/
#define REG_IOPWRDOM_AIB_MEM_IO_REG                       ASR_ADDR(REGS_IOPWRDOM_BASE, 0X18)/*AIB MEM I/O Domain Control Register*/
#define REG_IOPWRDOM_AIB_MMC1_IO_REG                      ASR_ADDR(REGS_IOPWRDOM_BASE, 0X1C)/*AIB MMC 1 I/O Domain Control Register*/
#define REG_IOPWRDOM_AIB_PMIC1_IO_REG                     ASR_ADDR(REGS_IOPWRDOM_BASE, 0X24)/*AIB PMIC 1 I/O Domain Control Register*/
#define REG_IOPWRDOM_AIB_PMIC2_IO_REG                     ASR_ADDR(REGS_IOPWRDOM_BASE, 0X28)/*AIB PMIC 2 I/O Domain Control Register*/
#define REG_IOPWRDOM_AIB_USIM_IO_REG                      ASR_ADDR(REGS_IOPWRDOM_BASE, 0X2C)/*AIB USIM I/O Domain Control Register*/
#define REG_IOPWRDOM_AIB_GPIO3_IO_REG                     ASR_ADDR(REGS_IOPWRDOM_BASE, 0X30)/*AIB GPIO3 I/O Domain Control Register*/
#define REG_IOPWRDOM_AIB_AP_CFG_15_0                      ASR_ADDR(REGS_IOPWRDOM_BASE, 0X400)/*AIB AP config [15:0]*/
#define REG_IOPWRDOM_AIB_AP_CFG_31_16                     ASR_ADDR(REGS_IOPWRDOM_BASE, 0X404)/*AIB AP config [31:16]*/
#define REG_IOPWRDOM_AIB_AP_CFG_47_32                     ASR_ADDR(REGS_IOPWRDOM_BASE, 0X408)/*AIB AP config [47:32]*/
#define REG_IOPWRDOM_AIB_AP_CFG_63_48                     ASR_ADDR(REGS_IOPWRDOM_BASE, 0X40C)/*AIB AP config [63:48]*/
#define REG_IOPWRDOM_AIB_AP_CFG_79_64                     ASR_ADDR(REGS_IOPWRDOM_BASE, 0X410)/*AIB AP config [79:64]*/
#define REG_IOPWRDOM_AIB_CP_CFG_15_0                      ASR_ADDR(REGS_IOPWRDOM_BASE, 0X414)/*AIB CP config [15:0]*/



/* bits definitions for register REG_IOPWRDOM_AIB_NAND_IO_REG */
#define BITS_AIB_NAND_IO_DCS(_X_)                         ( (_X_) << 6 & (BIT(6)|BIT(7)) )

/* bits definitions for register REG_IOPWRDOM_AIB_ANT_IO_REG */
#define BIT_SL28                                          ( BIT(3) )
#define BIT_V18EN29                                       ( BIT(2) )
#define BIT_SL31                                          ( BIT(0) )

/* bits definitions for register REG_IOPWRDOM_AIB_GPIO1_IO_REG */
#define BITS_AIB_GPIO_IO_DCS(_X_)                         ( (_X_) << 6 & (BIT(6)|BIT(7)) )

/* bits definitions for register REG_IOPWRDOM_AIB_GPIO2_IO_REG */
#define BIT_V18EN47                                       ( BIT(2) )
#define BIT_PDB                                           ( BIT(0) )

/* bits definitions for register REG_IOPWRDOM_AIB_GPIO4_IO_REG */
#define BITS_AIB_GPIO4_IO_DCS(_X_)                        ( (_X_) << 6 & (BIT(6)|BIT(7)) )

/* bits definitions for register REG_IOPWRDOM_AIB_MEM_IO_REG */

/* bits definitions for register REG_IOPWRDOM_AIB_MMC1_IO_REG */
#define BIT_SL72                                          ( BIT(3) )
#define BIT_V18EN73                                       ( BIT(2) )
#define BIT_SL75                                          ( BIT(0) )

/* bits definitions for register REG_IOPWRDOM_AIB_PMIC1_IO_REG */
#define BITS_AIB_PMIC1_IO_DCS(_X_)                        ( (_X_) << 6 & (BIT(6)|BIT(7)) )

/* bits definitions for register REG_IOPWRDOM_AIB_PMIC2_IO_REG */
#define BITS_AIB_PMIC2_IO_DCS(_X_)                        ( (_X_) << 6 & (BIT(6)|BIT(7)) )

/* bits definitions for register REG_IOPWRDOM_AIB_USIM_IO_REG */
#define BIT_SL99                                          ( BIT(3) )
#define BIT_V18EN100                                      ( BIT(2) )
#define BIT_SL102                                         ( BIT(0) )

/* bits definitions for register REG_IOPWRDOM_AIB_GPIO3_IO_REG */
#define BITS_AIB_GPIO3_IO_DCS(_X_)                        ( (_X_) << 6 & (BIT(6)|BIT(7)) )

/* bits definitions for register REG_IOPWRDOM_AIB_AP_CFG_15_0 */
#define BITS_AIB_AP_CFG_15_0(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_IOPWRDOM_AIB_AP_CFG_31_16 */
#define BITS_AIB_AP_CFG_31_16(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_IOPWRDOM_AIB_AP_CFG_47_32 */
#define BITS_AIB_AP_CFG_47_32(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_IOPWRDOM_AIB_AP_CFG_63_48 */
#define BITS_AIB_AP_CFG_63_48(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_IOPWRDOM_AIB_AP_CFG_79_64 */
#define BITS_AIB_AP_CFG_79_64(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_IOPWRDOM_AIB_CP_CFG_15_0 */
#define BITS_AIB_CP_CFG_15_0(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

#endif
