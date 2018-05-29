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


#ifndef __H_REGS_APBTCU_HEADFILE_H__
#define __H_REGS_APBTCU_HEADFILE_H__ __FILE__

#define	REGS_APBTCU

/* registers definitions for APBTCU */
#define REG_APBTCU_TCU_FIFO_INSTR                         ASR_ADDR(REGS_APBTCU_BASE, 0X00)/*TCU FIFO Register*/
#define REG_APBTCU_TCU_NUM_INST                           ASR_ADDR(REGS_APBTCU_BASE, 0X04)/*TCU Number Of Instructions Register*/
#define REG_APBTCU_TCU_STATUS                             ASR_ADDR(REGS_APBTCU_BASE, 0X08)/*TCU Status Register*/
#define REG_APBTCU_TCU_EXCEPTION_ENABLE                   ASR_ADDR(REGS_APBTCU_BASE, 0X0C)/*TCU Exception Enable Register*/
#define REG_APBTCU_TCU_CONTROL                            ASR_ADDR(REGS_APBTCU_BASE, 0X10)/*TCU Control Register*/
#define REG_APBTCU_TCU_NEARLY_FULL_LEVEL                  ASR_ADDR(REGS_APBTCU_BASE, 0X14)/*TCU Nearly Full Level Register*/
#define REG_APBTCU_TCU_NEARLY_EMPTY_LEVEL                 ASR_ADDR(REGS_APBTCU_BASE, 0X18)/*TCU Nearly Empty Level Register*/
#define REG_APBTCU_TCU_WRITE_IDX                          ASR_ADDR(REGS_APBTCU_BASE, 0X1C)/*TCU Write ID Register*/
#define REG_APBTCU_TCU_READ_IDX                           ASR_ADDR(REGS_APBTCU_BASE, 0X20)/*TCU Read ID Register*/
#define REG_APBTCU_TCU_PRESCALE                           ASR_ADDR(REGS_APBTCU_BASE, 0X24)/*TCU PreScale Register*/
#define REG_APBTCU_TCU_DELTA_TIMER                        ASR_ADDR(REGS_APBTCU_BASE, 0X28)/*TCU DeltaTimer Register*/
#define REG_APBTCU_TCU_EVENT_LOG                          ASR_ADDR(REGS_APBTCU_BASE, 0X30)/*TCU EventLog Register*/
#define REG_APBTCU_TCU_CLEAR_GPOA                         ASR_ADDR(REGS_APBTCU_BASE, 0X40)/*TCU GPOAClr Register*/
#define REG_APBTCU_TCU_SET_GPOA                           ASR_ADDR(REGS_APBTCU_BASE, 0X44)/*TCU GPOASet Register*/
#define REG_APBTCU_TCU_CLEAR_GPOA                         ASR_ADDR(REGS_APBTCU_BASE, 0X48)/*TCU GPOBClr Register*/
#define REG_APBTCU_TCU_SET_GPOB                           ASR_ADDR(REGS_APBTCU_BASE, 0X4C)/*TCU GPOBSet Register*/
#define REG_APBTCU_INSTRUCTIONRAM                         ASR_ADDR(REGS_APBTCU_BASE, 0X400)/*TCU Instruction RAM Register*/



/* bits definitions for register REG_APBTCU_TCU_FIFO_INSTR */
#define BITS_FIFO(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_APBTCU_TCU_NUM_INST */
#define BITS_NUM_OF_INSTR(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_APBTCU_TCU_STATUS */
#define BIT_SHORTWAIT_FAIL                                ( BIT(6) )
#define BIT_CONCURRENCY_LIMIT                             ( BIT(5) )
#define BIT_UNDERFLOW                                     ( BIT(4) )
#define BIT_UNDERFLOW_WARN                                ( BIT(3) )
#define BIT_OVERFLOW                                      ( BIT(2) )
#define BIT_NEARLY_EMPTY                                  ( BIT(1) )
#define BIT_NEARLYFULL                                    ( BIT(0) )

/* bits definitions for register REG_APBTCU_TCU_EXCEPTION_ENABLE */
#define BITS_EXCEPTIONENABLE(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_APBTCU_TCU_CONTROL */
#define BIT_LOGENABLE                                     ( BIT(3) )
#define BIT_FASTSTEP                                      ( BIT(2) )
#define BIT_FLUSH                                         ( BIT(1) )
#define BIT_APBTC_RESET65                                 ( BIT(0) )

/* bits definitions for register REG_APBTCU_TCU_NEARLY_FULL_LEVEL */
#define BITS_NEARLYFULL_LEVEL(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_APBTCU_TCU_NEARLY_EMPTY_LEVEL */
#define BITS_NEARLYEMPTY_LEVEL(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_APBTCU_TCU_WRITE_IDX */
#define BITS_WRITEIDX(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_APBTCU_TCU_READ_IDX */
#define BITS_READIDX(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_APBTCU_TCU_PRESCALE */
#define BITS_APBTC_PRESCALE110(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_APBTCU_TCU_DELTA_TIMER */
#define BITS_DELTATIMER(_X_)                              (_X_)

/* bits definitions for register REG_APBTCU_TCU_EVENT_LOG */
#define BITS_EVENTLOG(_X_)                                (_X_)

/* bits definitions for register REG_APBTCU_TCU_CLEAR_GPOA */
#define BITS_GPOACLR(_X_)                                 (_X_)

/* bits definitions for register REG_APBTCU_TCU_SET_GPOA */
#define BITS_GPOASET(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_APBTCU_TCU_CLEAR_GPOA */
#define BITS_GPOBCLR(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_APBTCU_TCU_SET_GPOB */
#define BITS_GPOBSET(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_APBTCU_INSTRUCTIONRAM */
#define BITS_INSTRUCTION_RAM(_X_)                         (_X_)

#endif
