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


#ifndef __H_REGS_USBSPH_REG_HEADFILE_H__
#define __H_REGS_USBSPH_REG_HEADFILE_H__ __FILE__

#define	REGS_USBSPH_REG

/* registers definitions for USBSPH_REG */
#define REG_USBSPH_REG_USBSPH_MISC                        ASR_ADDR(REGS_USBSPH_REG_BASE, 0X04)/*USB SPH Miscellaneous Control Register*/
#define REG_USBSPH_REG_USBSPH_INT                         ASR_ADDR(REGS_USBSPH_REG_BASE, 0X28)/*USB SPH Interrupt Register*/
#define REG_USBSPH_REG_USBSPH_MISC_CTRL                   ASR_ADDR(REGS_USBSPH_REG_BASE, 0X34)/*USB SPH Misc Control Register*/



/* bits definitions for register REG_USBSPH_REG_USBSPH_MISC */

/* bits definitions for register REG_USBSPH_REG_USBSPH_INT */
#define BIT_USB_RESUME_INT                                ( BIT(11) )
#define BIT_HSIC_READY_INT_EN                             ( BIT(10) )
#define BIT_HSIC_CONNECT_INT_EN                           ( BIT(9) )
#define BIT_USBSP_RESUME_INT28                            ( BIT(6) )
#define BIT_USBSP_31                                      ( BIT(2) )
#define BIT_HSIC_CONNECT_INT                              ( BIT(1) )
#define BIT_INTERRUPT                                     ( BIT(0) )

/* bits definitions for register REG_USBSPH_REG_USBSPH_MISC_CTRL */
#define BIT_OTG_CLK480_READY                              ( BIT(31) )
#define BIT_USBSP_PLL_LOCK_BYPASS45                       ( BIT(15) )
#define BIT_USBSP_PLL_LOCK46                              ( BIT(14) )
#define BIT_USBSP_XCVR_UDRDIS47                           ( BIT(13) )
#define BIT_XCVR_SWDIS                                    ( BIT(12) )
#define BIT_SER_SEL_D2                                    ( BIT(9) )
#define BIT_ICUSB_SUSPENDM_EN                             ( BIT(8) )
#define BIT_ICUSB_IN_USE_CP                               ( BIT(7) )
#define BIT_CLKSEL                                        ( BIT(6) )
#define BIT_PDWN_EN                                       ( BIT(5) )
#define BITS_USBSP_RTC55(_X_)                             ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BITS_USBSP_WTC56(_X_)                             ( (_X_) << 1 & (BIT(1)|BIT(2)) )
#define BIT_USBSP_PDWN57                                  ( BIT(0) )

#endif
