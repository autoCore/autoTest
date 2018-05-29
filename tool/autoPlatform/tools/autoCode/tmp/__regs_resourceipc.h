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


#ifndef __H_REGS_RIPC0RIPC1RIPC2RIPC3CP_RIPC_HEADFILE_H__
#define __H_REGS_RIPC0RIPC1RIPC2RIPC3CP_RIPC_HEADFILE_H__ __FILE__

#define	REGS_RIPC0,RIPC1,RIPC2,RIPC3,CP_RIPC

/* registers definitions for RIPC0RIPC1RIPC2RIPC3CP_RIPC */
#define REG_RIPC0_RIPCx_STATUS                            ASR_ADDR(REGS_RIPC0_BASE, 0X00)/*RIPCx Status Register*/
#define REG_RIPC1_RIPCx_STATUS                            ASR_ADDR(REGS_RIPC1_BASE, 0X00)/*RIPCx Status Register*/
#define REG_RIPC2_RIPCx_STATUS                            ASR_ADDR(REGS_RIPC2_BASE, 0X00)/*RIPCx Status Register*/
#define REG_RIPC3_RIPCx_STATUS                            ASR_ADDR(REGS_RIPC3_BASE, 0X00)/*RIPCx Status Register*/
#define REG_CP_RIPC_RIPCx_STATUS                          ASR_ADDR(REGS_CP_RIPC_BASE, 0X00)/*RIPCx Status Register*/
#define REG_RIPC0_RIPCx_APPS_INT                          ASR_ADDR(REGS_RIPC0_BASE, 0X04)/*RIPCx <var Processor: App> Core Interrupt Request Register*/
#define REG_RIPC1_RIPCx_APPS_INT                          ASR_ADDR(REGS_RIPC1_BASE, 0X04)/*RIPCx <var Processor: App> Core Interrupt Request Register*/
#define REG_RIPC2_RIPCx_APPS_INT                          ASR_ADDR(REGS_RIPC2_BASE, 0X04)/*RIPCx <var Processor: App> Core Interrupt Request Register*/
#define REG_RIPC3_RIPCx_APPS_INT                          ASR_ADDR(REGS_RIPC3_BASE, 0X04)/*RIPCx <var Processor: App> Core Interrupt Request Register*/
#define REG_CP_RIPC_RIPCx_APPS_INT                        ASR_ADDR(REGS_CP_RIPC_BASE, 0X04)/*RIPCx <var Processor: App> Core Interrupt Request Register*/
#define REG_RIPC0_RIPCx_COMM_INT                          ASR_ADDR(REGS_RIPC0_BASE, 0X08)/*RIPCx <var Processor: Comm> Core Interrupt Request Register*/
#define REG_RIPC1_RIPCx_COMM_INT                          ASR_ADDR(REGS_RIPC1_BASE, 0X08)/*RIPCx <var Processor: Comm> Core Interrupt Request Register*/
#define REG_RIPC2_RIPCx_COMM_INT                          ASR_ADDR(REGS_RIPC2_BASE, 0X08)/*RIPCx <var Processor: Comm> Core Interrupt Request Register*/
#define REG_RIPC3_RIPCx_COMM_INT                          ASR_ADDR(REGS_RIPC3_BASE, 0X08)/*RIPCx <var Processor: Comm> Core Interrupt Request Register*/
#define REG_CP_RIPC_RIPCx_COMM_INT                        ASR_ADDR(REGS_CP_RIPC_BASE, 0X08)/*RIPCx <var Processor: Comm> Core Interrupt Request Register*/
#define REG_RIPC0_RIPCx_MSA_INT                           ASR_ADDR(REGS_RIPC0_BASE, 0X0C)/*RIPCx <var Processor: MSA> Core Interrupt Request Register*/
#define REG_RIPC1_RIPCx_MSA_INT                           ASR_ADDR(REGS_RIPC1_BASE, 0X0C)/*RIPCx <var Processor: MSA> Core Interrupt Request Register*/
#define REG_RIPC2_RIPCx_MSA_INT                           ASR_ADDR(REGS_RIPC2_BASE, 0X0C)/*RIPCx <var Processor: MSA> Core Interrupt Request Register*/
#define REG_RIPC3_RIPCx_MSA_INT                           ASR_ADDR(REGS_RIPC3_BASE, 0X0C)/*RIPCx <var Processor: MSA> Core Interrupt Request Register*/
#define REG_CP_RIPC_RIPCx_MSA_INT                         ASR_ADDR(REGS_CP_RIPC_BASE, 0X0C)/*RIPCx <var Processor: MSA> Core Interrupt Request Register*/
#define REG_RIPC0_RIPCx_APPS_INFO                         ASR_ADDR(REGS_RIPC0_BASE, 0X014)/*RIPCx <var Processor: App> Core Info Register*/
#define REG_RIPC1_RIPCx_APPS_INFO                         ASR_ADDR(REGS_RIPC1_BASE, 0X014)/*RIPCx <var Processor: App> Core Info Register*/
#define REG_RIPC2_RIPCx_APPS_INFO                         ASR_ADDR(REGS_RIPC2_BASE, 0X014)/*RIPCx <var Processor: App> Core Info Register*/
#define REG_RIPC3_RIPCx_APPS_INFO                         ASR_ADDR(REGS_RIPC3_BASE, 0X014)/*RIPCx <var Processor: App> Core Info Register*/
#define REG_CP_RIPC_RIPCx_APPS_INFO                       ASR_ADDR(REGS_CP_RIPC_BASE, 0X014)/*RIPCx <var Processor: App> Core Info Register*/
#define REG_RIPC0_RIPCx_COMM_INFO                         ASR_ADDR(REGS_RIPC0_BASE, 0X18)/*RIPCx <var Processor: Comm> Core Info Register*/
#define REG_RIPC1_RIPCx_COMM_INFO                         ASR_ADDR(REGS_RIPC1_BASE, 0X18)/*RIPCx <var Processor: Comm> Core Info Register*/
#define REG_RIPC2_RIPCx_COMM_INFO                         ASR_ADDR(REGS_RIPC2_BASE, 0X18)/*RIPCx <var Processor: Comm> Core Info Register*/
#define REG_RIPC3_RIPCx_COMM_INFO                         ASR_ADDR(REGS_RIPC3_BASE, 0X18)/*RIPCx <var Processor: Comm> Core Info Register*/
#define REG_CP_RIPC_RIPCx_COMM_INFO                       ASR_ADDR(REGS_CP_RIPC_BASE, 0X18)/*RIPCx <var Processor: Comm> Core Info Register*/
#define REG_RIPC0_RIPCx_MSA_INFO                          ASR_ADDR(REGS_RIPC0_BASE, 0X1C)/*RIPCx <var Processor: MSA> Core Info Register*/
#define REG_RIPC1_RIPCx_MSA_INFO                          ASR_ADDR(REGS_RIPC1_BASE, 0X1C)/*RIPCx <var Processor: MSA> Core Info Register*/
#define REG_RIPC2_RIPCx_MSA_INFO                          ASR_ADDR(REGS_RIPC2_BASE, 0X1C)/*RIPCx <var Processor: MSA> Core Info Register*/
#define REG_RIPC3_RIPCx_MSA_INFO                          ASR_ADDR(REGS_RIPC3_BASE, 0X1C)/*RIPCx <var Processor: MSA> Core Info Register*/
#define REG_CP_RIPC_RIPCx_MSA_INFO                        ASR_ADDR(REGS_CP_RIPC_BASE, 0X1C)/*RIPCx <var Processor: MSA> Core Info Register*/



/* bits definitions for register REG_CP_RIPC_RIPCx_STATUS */
#define BIT_RIPC0_STATUS24                                ( BIT(0) )

/* bits definitions for register REG_CP_RIPC_RIPCx_APPS_INT */
#define BITS_MSG32(_X_)                                   ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_INT_REQ33                                     ( BIT(0) )

/* bits definitions for register REG_CP_RIPC_RIPCx_COMM_INT */
#define BITS_MSG40(_X_)                                   ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_INT_REQ41                                     ( BIT(0) )

/* bits definitions for register REG_CP_RIPC_RIPCx_MSA_INT */
#define BITS_MSG48(_X_)                                   ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_INT_REQ49                                     ( BIT(0) )

/* bits definitions for register REG_CP_RIPC_RIPCx_APPS_INFO */
#define BITS_MSG56(_X_)                                   (_X_)

/* bits definitions for register REG_CP_RIPC_RIPCx_COMM_INFO */
#define BITS_MSG63(_X_)                                   (_X_)

/* bits definitions for register REG_CP_RIPC_RIPCx_MSA_INFO */
#define BITS_MSG70(_X_)                                   (_X_)

#endif
