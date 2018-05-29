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


#ifndef __H_REGS_AIRQMIRQ_HEADFILE_H__
#define __H_REGS_AIRQMIRQ_HEADFILE_H__ __FILE__

#define	REGS_AIRQ,MIRQ

/* registers definitions for AIRQMIRQ */
#define REG_AIRQ_SWIENABLE                                ASR_ADDR(REGS_AIRQ_BASE, 0X0000)/*Software Interrupt xIRQ Enable Set Register*/
#define REG_MIRQ_SWIENABLE                                ASR_ADDR(REGS_MIRQ_BASE, 0X0000)/*Software Interrupt xIRQ Enable Set Register*/
#define REG_AIRQ_RIENABLE                                 ASR_ADDR(REGS_AIRQ_BASE, 0X0004)/*Register Interrupt xIRQ Enable Set Register*/
#define REG_MIRQ_RIENABLE                                 ASR_ADDR(REGS_MIRQ_BASE, 0X0004)/*Register Interrupt xIRQ Enable Set Register*/
#define REG_AIRQ_XSWIENABLE                               ASR_ADDR(REGS_AIRQ_BASE, 0X0008)/*Cross-Assert Interrupt xIRQ Enable Set Register*/
#define REG_MIRQ_XSWIENABLE                               ASR_ADDR(REGS_MIRQ_BASE, 0X0008)/*Cross-Assert Interrupt xIRQ Enable Set Register*/
#define REG_AIRQ_EIRQENABLE                               ASR_ADDR(REGS_AIRQ_BASE, 0X000C)/*Error Interrupt xIRQ Enable Set Register*/
#define REG_MIRQ_EIRQENABLE                               ASR_ADDR(REGS_MIRQ_BASE, 0X000C)/*Error Interrupt xIRQ Enable Set Register*/
#define REG_AIRQ_HWIENABLEn0                              ASR_ADDR(REGS_AIRQ_BASE, 0x0020)/*Hardware Interrupt Bank n xIRQ Enable Set Register*/
#define REG_MIRQ_HWIENABLEn0                              ASR_ADDR(REGS_MIRQ_BASE, 0x0020)/*Hardware Interrupt Bank n xIRQ Enable Set Register*/
#define REG_AIRQ_HWIENABLEn1                              ASR_ADDR(REGS_AIRQ_BASE, 0x002C)/*Hardware Interrupt Bank n xIRQ Enable Set Register*/
#define REG_MIRQ_HWIENABLEn1                              ASR_ADDR(REGS_MIRQ_BASE, 0x002C)/*Hardware Interrupt Bank n xIRQ Enable Set Register*/
#define REG_AIRQ_SWIENABLECLR                             ASR_ADDR(REGS_AIRQ_BASE, 0X0040)/*Software Interrupt xIRQ Enable Clr Register*/
#define REG_MIRQ_SWIENABLECLR                             ASR_ADDR(REGS_MIRQ_BASE, 0X0040)/*Software Interrupt xIRQ Enable Clr Register*/
#define REG_AIRQ_RIENABLECLR                              ASR_ADDR(REGS_AIRQ_BASE, 0X0044)/*Register Interrupt xIRQ Enable Clr Register*/
#define REG_MIRQ_RIENABLECLR                              ASR_ADDR(REGS_MIRQ_BASE, 0X0044)/*Register Interrupt xIRQ Enable Clr Register*/
#define REG_AIRQ_EIRQENABLECLR                            ASR_ADDR(REGS_AIRQ_BASE, 0X0048)/*Error Interrupt xIRQ Enable Clr Register*/
#define REG_MIRQ_EIRQENABLECLR                            ASR_ADDR(REGS_MIRQ_BASE, 0X0048)/*Error Interrupt xIRQ Enable Clr Register*/
#define REG_AIRQ_HWIENABLECLRn0                           ASR_ADDR(REGS_AIRQ_BASE, 0x0060)/*Hardware Interrupt Bank n xIRQ Enable Clr Register*/
#define REG_MIRQ_HWIENABLECLRn0                           ASR_ADDR(REGS_MIRQ_BASE, 0x0060)/*Hardware Interrupt Bank n xIRQ Enable Clr Register*/
#define REG_AIRQ_HWIENABLECLRn1                           ASR_ADDR(REGS_AIRQ_BASE, 0x0064)/*Hardware Interrupt Bank n xIRQ Enable Clr Register*/
#define REG_MIRQ_HWIENABLECLRn1                           ASR_ADDR(REGS_MIRQ_BASE, 0x0064)/*Hardware Interrupt Bank n xIRQ Enable Clr Register*/
#define REG_AIRQ_CIP                                      ASR_ADDR(REGS_AIRQ_BASE, 0X0080)/*Current Interrupt Priority Register*/
#define REG_MIRQ_CIP                                      ASR_ADDR(REGS_MIRQ_BASE, 0X0080)/*Current Interrupt Priority Register*/
#define REG_AIRQ_CIN                                      ASR_ADDR(REGS_AIRQ_BASE, 0X0084)/*Current Interrupt Number Register*/
#define REG_MIRQ_CIN                                      ASR_ADDR(REGS_MIRQ_BASE, 0X0084)/*Current Interrupt Number Register*/
#define REG_AIRQ_AIM                                      ASR_ADDR(REGS_AIRQ_BASE, 0X0088)/*Active Interrupt Mask Register*/
#define REG_MIRQ_AIM                                      ASR_ADDR(REGS_MIRQ_BASE, 0X0088)/*Active Interrupt Mask Register*/
#define REG_AIRQ_SYSREG                                   ASR_ADDR(REGS_AIRQ_BASE, 0X008C)/*System Register*/
#define REG_MIRQ_SYSREG                                   ASR_ADDR(REGS_MIRQ_BASE, 0X008C)/*System Register*/
#define REG_AIRQ_SWICARRYSTATUS                           ASR_ADDR(REGS_AIRQ_BASE, 0X0090)/*Software Interrupt Carry Status Register*/
#define REG_MIRQ_SWICARRYSTATUS                           ASR_ADDR(REGS_MIRQ_BASE, 0X0090)/*Software Interrupt Carry Status Register*/
#define REG_AIRQ_RICARRYSTATUS                            ASR_ADDR(REGS_AIRQ_BASE, 0X0094)/*Register Interrupt Carry Status Register*/
#define REG_MIRQ_RICARRYSTATUS                            ASR_ADDR(REGS_MIRQ_BASE, 0X0094)/*Register Interrupt Carry Status Register*/
#define REG_AIRQ_XSWICARRYSTATUS                          ASR_ADDR(REGS_AIRQ_BASE, 0X0098)/*Cross-Assertion Interrupt Carry Status Register*/
#define REG_MIRQ_XSWICARRYSTATUS                          ASR_ADDR(REGS_MIRQ_BASE, 0X0098)/*Cross-Assertion Interrupt Carry Status Register*/
#define REG_AIRQ_CINVALUE                                 ASR_ADDR(REGS_AIRQ_BASE, 0X009C)/*Current Interrupt Number Value Register*/
#define REG_MIRQ_CINVALUE                                 ASR_ADDR(REGS_MIRQ_BASE, 0X009C)/*Current Interrupt Number Value Register*/
#define REG_AIRQ_SWIPRIORITYn0                            ASR_ADDR(REGS_AIRQ_BASE, 0x00A0)/*Software Interrupt n Priority Register*/
#define REG_MIRQ_SWIPRIORITYn0                            ASR_ADDR(REGS_MIRQ_BASE, 0x00A0)/*Software Interrupt n Priority Register*/
#define REG_AIRQ_SWIPRIORITYn1                            ASR_ADDR(REGS_AIRQ_BASE, 0x00DC)/*Software Interrupt n Priority Register*/
#define REG_MIRQ_SWIPRIORITYn1                            ASR_ADDR(REGS_MIRQ_BASE, 0x00DC)/*Software Interrupt n Priority Register*/
#define REG_AIRQ_RIPRIORITYn0                             ASR_ADDR(REGS_AIRQ_BASE, 0x00E0)/*Register Interrupt n Priority Register*/
#define REG_MIRQ_RIPRIORITYn0                             ASR_ADDR(REGS_MIRQ_BASE, 0x00E0)/*Register Interrupt n Priority Register*/
#define REG_AIRQ_RIPRIORITYn1                             ASR_ADDR(REGS_AIRQ_BASE, 0x00FC)/*Register Interrupt n Priority Register*/
#define REG_MIRQ_RIPRIORITYn1                             ASR_ADDR(REGS_MIRQ_BASE, 0x00FC)/*Register Interrupt n Priority Register*/
#define REG_AIRQ_XSWIPRIORITY                             ASR_ADDR(REGS_AIRQ_BASE, 0X0120)/*Cross-Assert Interrupt Priority Register*/
#define REG_MIRQ_XSWIPRIORITY                             ASR_ADDR(REGS_MIRQ_BASE, 0X0120)/*Cross-Assert Interrupt Priority Register*/
#define REG_AIRQ_EXSWIPRIORITY                            ASR_ADDR(REGS_AIRQ_BASE, 0X0140)/*Cross-Assert Error Interrupt Priority Register*/
#define REG_MIRQ_EXSWIPRIORITY                            ASR_ADDR(REGS_MIRQ_BASE, 0X0140)/*Cross-Assert Error Interrupt Priority Register*/
#define REG_AIRQ_ERIPRIORITY                              ASR_ADDR(REGS_AIRQ_BASE, 0X0144)/*Register Error Interrupt Priority Register*/
#define REG_MIRQ_ERIPRIORITY                              ASR_ADDR(REGS_MIRQ_BASE, 0X0144)/*Register Error Interrupt Priority Register*/
#define REG_AIRQ_ESWPRIORITY                              ASR_ADDR(REGS_AIRQ_BASE, 0X0148)/*Software Error Interrupt Priority Register*/
#define REG_MIRQ_ESWPRIORITY                              ASR_ADDR(REGS_MIRQ_BASE, 0X0148)/*Software Error Interrupt Priority Register*/
#define REG_AIRQ_HWPRIORITYn0                             ASR_ADDR(REGS_AIRQ_BASE, 0x0200)/*Hardware Interrupt n Priority Register*/
#define REG_MIRQ_HWPRIORITYn0                             ASR_ADDR(REGS_MIRQ_BASE, 0x0200)/*Hardware Interrupt n Priority Register*/
#define REG_AIRQ_HWPRIORITYn1                             ASR_ADDR(REGS_AIRQ_BASE, 0x02C0)/*Hardware Interrupt n Priority Register*/
#define REG_MIRQ_HWPRIORITYn1                             ASR_ADDR(REGS_MIRQ_BASE, 0x02C0)/*Hardware Interrupt n Priority Register*/
#define REG_AIRQ_MIRQ_DUMMY_READ                          ASR_ADDR(REGS_AIRQ_BASE, 0X0300)/*MIRQ Dummy Read Register*/
#define REG_MIRQ_MIRQ_DUMMY_READ                          ASR_ADDR(REGS_MIRQ_BASE, 0X0300)/*MIRQ Dummy Read Register*/
#define REG_AIRQ_SWICOUNTn                                ASR_ADDR(REGS_AIRQ_BASE, 0X0400)/*Software Interrupt n Count Register*/
#define REG_MIRQ_SWICOUNTn                                ASR_ADDR(REGS_MIRQ_BASE, 0X0400)/*Software Interrupt n Count Register*/
#define REG_AIRQ_RIREGISTER                               ASR_ADDR(REGS_AIRQ_BASE, 0X0440)/*RI Register*/
#define REG_MIRQ_RIREGISTER                               ASR_ADDR(REGS_MIRQ_BASE, 0X0440)/*RI Register*/
#define REG_AIRQ_XSWICOUNT                                ASR_ADDR(REGS_AIRQ_BASE, 0X0460)/*Cross-Assert Interrupt Count Register*/
#define REG_MIRQ_XSWICOUNT                                ASR_ADDR(REGS_MIRQ_BASE, 0X0460)/*Cross-Assert Interrupt Count Register*/
#define REG_AIRQ_XSWIASSERT                               ASR_ADDR(REGS_AIRQ_BASE, 0X0464)/*Cross-Assert Interrupt Assert Register*/
#define REG_MIRQ_XSWIASSERT                               ASR_ADDR(REGS_MIRQ_BASE, 0X0464)/*Cross-Assert Interrupt Assert Register*/
#define REG_AIRQ_IRQSTATCTL                               ASR_ADDR(REGS_AIRQ_BASE, 0X0468)/*IRQ Status Control Register*/
#define REG_MIRQ_IRQSTATCTL                               ASR_ADDR(REGS_MIRQ_BASE, 0X0468)/*IRQ Status Control Register*/
#define REG_AIRQ_STIKY_CLR0                               ASR_ADDR(REGS_AIRQ_BASE, 0X08F8)/*AIRQ Interrupt Clear 0 Register*/
#define REG_MIRQ_STIKY_CLR0                               ASR_ADDR(REGS_MIRQ_BASE, 0X08F8)/*AIRQ Interrupt Clear 0 Register*/
#define REG_AIRQ_STIKY_CLR1                               ASR_ADDR(REGS_AIRQ_BASE, 0X08FC)/*AIRQ Interrupt Clear 1 Register*/
#define REG_MIRQ_STIKY_CLR1                               ASR_ADDR(REGS_MIRQ_BASE, 0X08FC)/*AIRQ Interrupt Clear 1 Register*/
#define REG_AIRQ_EDGE_OR_LEVEL0                           ASR_ADDR(REGS_AIRQ_BASE, 0X08F0)/*AIRQ Interrupt Sensitivity 0 Register*/
#define REG_MIRQ_EDGE_OR_LEVEL0                           ASR_ADDR(REGS_MIRQ_BASE, 0X08F0)/*AIRQ Interrupt Sensitivity 0 Register*/
#define REG_AIRQ_EDGE_OR_LEVEL1                           ASR_ADDR(REGS_AIRQ_BASE, 0X08F4)/*AIRQ Interrupt Sensitivity 1 Register*/
#define REG_MIRQ_EDGE_OR_LEVEL1                           ASR_ADDR(REGS_MIRQ_BASE, 0X08F4)/*AIRQ Interrupt Sensitivity 1 Register*/



/* bits definitions for register REG_MIRQ_SWIENABLE */
#define BITS_SWI_ENB_SET(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_MIRQ_RIENABLE */
#define BITS_RI_ENB_SET(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_MIRQ_XSWIENABLE */
#define BIT_XSWI_ENB                                      ( BIT(0) )

/* bits definitions for register REG_MIRQ_EIRQENABLE */
#define BITS_EI_ENB_SET(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_MIRQ_HWIENABLEn1 */
#define BITS_HWI_N_ENB_SET(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_MIRQ_SWIENABLECLR */
#define BITS_SWI_ENB_CLR(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_MIRQ_RIENABLECLR */
#define BITS_RI_ENB_CLR(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_MIRQ_EIRQENABLECLR */
#define BITS_EI_ENB_CLR(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_MIRQ_HWIENABLECLRn1 */
#define BITS_HWI_N_ENB_CLR(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_MIRQ_CIP */
#define BITS_CIP(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_MIRQ_CIN */
#define BITS_CIN(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_MIRQ_AIM */
#define BITS_AIM(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_MIRQ_SYSREG */
#define BIT_IRQCTRL_RST                                   ( BIT(0) )

/* bits definitions for register REG_MIRQ_SWICARRYSTATUS */
#define BITS_SWI_CS(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_MIRQ_RICARRYSTATUS */
#define BITS_RI_CS(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_MIRQ_XSWICARRYSTATUS */
#define BIT_XSWI_CS                                       ( BIT(0) )

/* bits definitions for register REG_MIRQ_CINVALUE */
#define BITS_CINV(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_MIRQ_SWIPRIORITYn1 */
#define BITS_SWIPN(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_MIRQ_RIPRIORITYn1 */
#define BITS_RIPN(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_MIRQ_XSWIPRIORITY */
#define BITS_XSWIP(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_MIRQ_EXSWIPRIORITY */
#define BITS_XSWI_EIRQP(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_MIRQ_ERIPRIORITY */
#define BITS_RI_EIRQP(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_MIRQ_ESWPRIORITY */
#define BITS_SWI_EIRQP(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_MIRQ_HWPRIORITYn1 */
#define BITS_HWIPN(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_MIRQ_MIRQ_DUMMY_READ */

/* bits definitions for register REG_MIRQ_SWICOUNTn */
#define BITS_SWICN(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_MIRQ_RIREGISTER */
#define BITS_RIR(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_MIRQ_XSWICOUNT */
#define BITS_XSWIC(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_MIRQ_XSWIASSERT */
#define BIT_XSWIA                                         ( BIT(0) )

/* bits definitions for register REG_MIRQ_IRQSTATCTL */
#define BITS_IRQSTATCTRL(_X_)                             ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_MIRQ_STIKY_CLR0 */
#define BITS_AIRQ_AIRQ_INT_CLR_0308(_X_)                  (_X_)

/* bits definitions for register REG_MIRQ_STIKY_CLR1 */
#define BITS_AIRQ_AIRQ_INT_CLR_1316(_X_)                  (_X_)

/* bits definitions for register REG_MIRQ_EDGE_OR_LEVEL0 */
#define BITS_AIRQ_AIRQ_EDGE_LEVEL_0324(_X_)               (_X_)

/* bits definitions for register REG_MIRQ_EDGE_OR_LEVEL1 */
#define BITS_AIRQ_AIRQ_EDGE_LEVEL_1332(_X_)               (_X_)

#endif
