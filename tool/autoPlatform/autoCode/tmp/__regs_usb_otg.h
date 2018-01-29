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


#ifndef __H_REGS_USB_HEADFILE_H__
#define __H_REGS_USB_HEADFILE_H__ __FILE__

#define	REGS_USB

/* registers definitions for USB */
#define REG_USB_USB_ID                                    ASR_ADDR(REGS_USB_BASE, 0X000)/*Identification Register*/
#define REG_USB_USB_HWGENERAL                             ASR_ADDR(REGS_USB_BASE, 0X004)/*General Hardware Parameters Register*/
#define REG_USB_USB_HWHOST                                ASR_ADDR(REGS_USB_BASE, 0X008)/*Host Hardware Parameters Register*/
#define REG_USB_USB_HWDEVICE                              ASR_ADDR(REGS_USB_BASE, 0X00C)/*Device Hardware Parameters Register*/
#define REG_USB_USB_HWTXBUF                               ASR_ADDR(REGS_USB_BASE, 0X010)/*TX Buffer Hardware Parameters Register*/
#define REG_USB_USB_HWRXBUF                               ASR_ADDR(REGS_USB_BASE, 0X014)/*RX Buffer Hardware Parameters Register*/
#define REG_USB_USB_HWRXBUF                               ASR_ADDR(REGS_USB_BASE, 0X018)/*RX Buffer Hardware Parameters Register*/
#define REG_USB_USB_HWRXBUF                               ASR_ADDR(REGS_USB_BASE, 0X01C)/*RX Buffer Hardware Parameters Register*/
#define REG_USB_GPTIMER0LD                                ASR_ADDR(REGS_USB_BASE, 0X080)/*Device/Host Timer Registers*/
#define REG_USB_GPTIMER0CTRL                              ASR_ADDR(REGS_USB_BASE, 0X084)
#define REG_USB_GPTIMER1LD                                ASR_ADDR(REGS_USB_BASE, 0X088)
#define REG_USB_USB_HCIVERSION                            ASR_ADDR(REGS_USB_BASE, 0X102)/*Host Interface Version Number - EHCI Compliant Register*/
#define REG_USB_USB_HCSPARAMS                             ASR_ADDR(REGS_USB_BASE, 0X104)/*Host Ctrl. Structural Parameters EHCI Compliant with*/
#define REG_USB_USB_HCCPARAMS                             ASR_ADDR(REGS_USB_BASE, 0X108)/*Host Ctrl. Capability Parameters EHCI Compliant*/
#define REG_USB_USB_DCIVERSION                            ASR_ADDR(REGS_USB_BASE, 0X120)/*Dev. Interface Version Number Register*/
#define REG_USB_USB_DCCPARAMS                             ASR_ADDR(REGS_USB_BASE, 0X124)/*Device Ctrl. Capability Parameters Register*/
#define REG_USB_USB_CMD                                   ASR_ADDR(REGS_USB_BASE, 0X140)/*USB Command Register*/
#define REG_USB_USB_STS                                   ASR_ADDR(REGS_USB_BASE, 0X144)/*USB Status Register*/
#define REG_USB_USB_INTR                                  ASR_ADDR(REGS_USB_BASE, 0X148)/*USB Interrupt Enable Register*/
#define REG_USB_USB_FRINDEX                               ASR_ADDR(REGS_USB_BASE, 0X14C)/*USB Frame Index Register*/
#define REG_USB_USB_PERIODICLISTBASE                      ASR_ADDR(REGS_USB_BASE, 0X154)/*Host Controller Frame List Base Address Register (Host Mode)*/
#define REG_USB_USB_DEVICEADDR                            ASR_ADDR(REGS_USB_BASE, 0X154)/*Device Controller USB Device Address Register (Device Mode)*/
#define REG_USB_USB_ASYNCLISTADDR                         ASR_ADDR(REGS_USB_BASE, 0X158)/*Host Controller Next Asynchronous List Address Register*/
#define REG_USB_USB_ENDPOINTLISTADDR                      ASR_ADDR(REGS_USB_BASE, 0X158)/*Address at Endpoint List in Memory Register*/
#define REG_USB_USB_BURSTSIZE                             ASR_ADDR(REGS_USB_BASE, 0X160)/*Programmable Burst Size Register - Host Controller*/
#define REG_USB_USB_ENDPTNAK                              ASR_ADDR(REGS_USB_BASE, 0X178)/*Endpoint NAK Register*/
#define REG_USB_USB_ENDPTNAKEN                            ASR_ADDR(REGS_USB_BASE, 0X17C)/*Endpoint NAK Enable Register*/
#define REG_USB_USB_PORTSC                                ASR_ADDR(REGS_USB_BASE, 0X184)/*Port Status/Control Register*/
#define REG_USB_USB_OTGSC                                 ASR_ADDR(REGS_USB_BASE, 0X1A4)/*OTG Status and Control Register*/
#define REG_USB_USB_MODE                                  ASR_ADDR(REGS_USB_BASE, 0X1A8)/*USB Device Mode Register*/
#define REG_USB_USB_ENDPTSETUPSTAT                        ASR_ADDR(REGS_USB_BASE, 0X1AC)/*Endpoint Setup Status Register*/
#define REG_USB_USB_ENDPTPRIME                            ASR_ADDR(REGS_USB_BASE, 0X1B0)/*Endpoint Initialization Register*/
#define REG_USB_USB_ENDPTFLUSH                            ASR_ADDR(REGS_USB_BASE, 0X1B4)/*Endpoint De-Initialize Register*/
#define REG_USB_USB_ENDPTSTAT                             ASR_ADDR(REGS_USB_BASE, 0X1B8)/*Endpoint STAT Register*/
#define REG_USB_USB_ENDPTCOMPLETE                         ASR_ADDR(REGS_USB_BASE, 0X1BC)/*Endpoint Complete Register*/
#define REG_USB_USB_ENDPTCTRL0                            ASR_ADDR(REGS_USB_BASE, 0X1C0)/*Endpoint Control 0 Register*/
#define REG_USB_USB_ENDPTCTRL1-ENDPTCTRL15                ASR_ADDR(REGS_USB_BASE, 0X1C4)/*Endpoint Control 1 to Endpoint Control 15 Registers*/



/* bits definitions for register REG_USB_USB_ID */
#define BITS_CIVERSION(_X_)                               ( (_X_) << 29 & (BIT(29)|BIT(30)|BIT(31)) )
#define BITS_VERSION(_X_)                                 ( (_X_) << 25 & (BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BITS_US_REVISION26(_X_)                           ( (_X_) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BITS_TAG(_X_)                                     ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BITS_NID(_X_)                                     ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_US_ID30(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_USB_USB_HWGENERAL */
#define BITS_US_SM38(_X_)                                 ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BITS_US_PHYM39(_X_)                               ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BITS_US_PHYW40(_X_)                               ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BIT_US_BWT41                                      ( BIT(3) )
#define BITS_US_CLKC42(_X_)                               ( (_X_) << 1 & (BIT(1)|BIT(2)) )
#define BIT_US_RT43                                       ( BIT(0) )

/* bits definitions for register REG_USB_USB_HWHOST */
#define BITS_US_TTPER50(_X_)                              ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_US_TTASY51(_X_)                              ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_US_NPORT53(_X_)                              ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)) )
#define BIT_US_HC54                                       ( BIT(0) )

/* bits definitions for register REG_USB_USB_HWDEVICE */
#define BITS_US_DEVEP62(_X_)                              ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )
#define BIT_US_DC63                                       ( BIT(0) )

/* bits definitions for register REG_USB_USB_HWTXBUF */
#define BIT_US_TXLCR70                                    ( BIT(31) )
#define BITS_US_TXCHANADD72(_X_)                          ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_US_TXADD73(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_US_TCBURST74(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USB_USB_HWRXBUF */
#define BITS_US_RXADD82(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_US_RXBURST83(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USB_USB_HWRXBUF */
#define BITS_EP7_TXFIFO_SIZE(_X_)                         ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_EP6_TXFIFO_SIZE(_X_)                         ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_EP5_TXFIFO_SIZE(_X_)                         ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_EP4_TXFIFO_SIZE(_X_)                         ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_EP3_TXFIFO_SIZE(_X_)                         ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_EP2_TXFIFO_SIZE(_X_)                         ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_EP1_TXFIFO_SIZE(_X_)                         ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_EP0_TXFIFO_SIZE(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_USB_USB_HWRXBUF */
#define BITS_EP15_TXFIFO_SIZE(_X_)                        ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_EP14_TXFIFO_SIZE(_X_)                        ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_EP13_TXFIFO_SIZE(_X_)                        ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_EP12_TXFIFO_SIZE(_X_)                        ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_EP11_TXFIFO_SIZE(_X_)                        ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_EP10_TXFIFO_SIZE(_X_)                        ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_EP9_TXFIFO_SIZE(_X_)                         ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_EP8_TXFIFO_SIZE(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_USB_GPTIMER0LD */
#define BITS_GPTLD(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )

/* bits definitions for register REG_USB_GPTIMER0CTRL */
#define BIT_GTPRUN                                        ( BIT(31) )
#define BIT_GPTRST                                        ( BIT(30) )
#define BIT_GPTMODE                                       ( BIT(24) )
#define BITS_GPTCNT(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )

/* bits definitions for register REG_USB_GPTIMER1LD */
#define BITS_US_CAPLENGTH150(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USB_USB_HCIVERSION */
#define BITS_US_HCIVERSION157(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USB_USB_HCSPARAMS */
#define BITS_US_N_TT165(_X_)                              ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_US_N_PTT166(_X_)                             ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_US_PI168                                      ( BIT(16) )
#define BITS_US_N_CC169(_X_)                              ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_US_N_PCC170(_X_)                             ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_US_PPC172                                     ( BIT(4) )
#define BITS_US_N_PORTS173(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_USB_USB_HCCPARAMS */
#define BITS_US_EECP181(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_US_IST182(_X_)                               ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_US_ASP184                                     ( BIT(2) )
#define BIT_US_PFL185                                     ( BIT(1) )
#define BIT_US_ADC186                                     ( BIT(0) )

/* bits definitions for register REG_USB_USB_DCIVERSION */
#define BITS_US_DCIVERSION194(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USB_USB_DCCPARAMS */
#define BIT_US_HC202                                      ( BIT(8) )
#define BIT_US_DC203                                      ( BIT(7) )
#define BITS_US_DEN205(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_USB_USB_CMD */
#define BITS_US_ITC217(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_US_RST219                                     ( BIT(1) )
#define BIT_US_RS220                                      ( BIT(0) )

/* bits definitions for register REG_USB_USB_STS */
#define BIT_US_TI1228                                     ( BIT(25) )
#define BIT_TI2                                           ( BIT(24) )
#define BIT_US_UPI231                                     ( BIT(19) )
#define BIT_US_UAI232                                     ( BIT(18) )
#define BIT_US_NAKI234                                    ( BIT(16) )
#define BIT_US_ULPII236                                   ( BIT(10) )
#define BIT_US_SLI238                                     ( BIT(8) )
#define BIT_US_SRI239                                     ( BIT(7) )
#define BIT_US_URI240                                     ( BIT(6) )
#define BIT_AAI_0B_08H                                    ( BIT(5) )
#define BIT_US_SEI242                                     ( BIT(4) )
#define BIT_US_FRI243                                     ( BIT(3) )
#define BIT_US_PCI244                                     ( BIT(2) )
#define BIT_US_UEI245                                     ( BIT(1) )
#define BIT_US_UI246                                      ( BIT(0) )

/* bits definitions for register REG_USB_USB_INTR */
#define BIT_US_TIE1254                                    ( BIT(25) )
#define BIT_US_TIE0255                                    ( BIT(24) )
#define BIT_US_UPEI257                                    ( BIT(19) )
#define BIT_US_UAEI258                                    ( BIT(18) )
#define BIT_US_NAKE260                                    ( BIT(16) )
#define BIT_US_ULPIE262                                   ( BIT(10) )
#define BIT_US_SLE264                                     ( BIT(8) )
#define BIT_US_SRE265                                     ( BIT(7) )
#define BIT_US_URE266                                     ( BIT(6) )
#define BIT_US_AAE267                                     ( BIT(5) )
#define BIT_US_SEE268                                     ( BIT(4) )
#define BIT_US_FRE269                                     ( BIT(3) )
#define BIT_US_PCE270                                     ( BIT(2) )
#define BIT_US_UEE271                                     ( BIT(1) )
#define BIT_US_UE272                                      ( BIT(0) )

/* bits definitions for register REG_USB_USB_FRINDEX */
#define BITS_US_FRINDEX280(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for register REG_USB_USB_PERIODICLISTBASE */
#define BITS_US_BASEADR287(_X_)                           ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_USB_USB_DEVICEADDR */
#define BITS_USBADR(_X_)                                  ( (_X_) << 25 & (BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_USBADRA                                       ( BIT(24) )

/* bits definitions for register REG_USB_USB_ASYNCLISTADDR */
#define BITS_US_ASYBASE308(_X_)                           ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_USB_USB_ENDPOINTLISTADDR */
#define BITS_EPBASE(_X_)                                  ( (_X_) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_USB_USB_BURSTSIZE */
#define BITS_US_TXPBURST325(_X_)                          ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BITS_US_RXPBURST326(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USB_USB_ENDPTNAK */
#define BITS_US_EPTN334(_X_)                              ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_US_EPRN335(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USB_USB_ENDPTNAKEN */
#define BITS_US_EPTNE342(_X_)                             ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_US_EPRNE343(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USB_USB_PORTSC */
#define BITS_US_PTS350(_X_)                               ( (_X_) << 30 & (BIT(30)|BIT(31)) )
#define BIT_US_STS351                                     ( BIT(29) )
#define BIT_US_PTW352                                     ( BIT(28) )
#define BITS_US_PSPD353(_X_)                              ( (_X_) << 26 & (BIT(26)|BIT(27)) )
#define BIT_US_PTS2354                                    ( BIT(25) )
#define BIT_US_PFSC355                                    ( BIT(24) )
#define BIT_US_PHCD356                                    ( BIT(23) )
#define BIT_US_WKOC357                                    ( BIT(22) )
#define BIT_WKDC                                          ( BIT(21) )
#define BIT_US_WKCN359                                    ( BIT(20) )
#define BITS_US_PTC360(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_US_PIC361(_X_)                               ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_US_PO362                                      ( BIT(13) )
#define BIT_US_PP363                                      ( BIT(12) )
#define BITS_US_LS364(_X_)                                ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BIT_US_HSP365                                     ( BIT(9) )
#define BIT_US_PR368                                      ( BIT(8) )
#define BIT_US_SUSP369                                    ( BIT(7) )
#define BIT_US_FPR370                                     ( BIT(6) )
#define BIT_US_OCC373                                     ( BIT(5) )
#define BIT_US_OCA374                                     ( BIT(4) )
#define BIT_US_PEC375                                     ( BIT(3) )
#define BIT_US_PE376                                      ( BIT(2) )
#define BIT_US_CSC377                                     ( BIT(1) )
#define BIT_US_CCS378                                     ( BIT(0) )

/* bits definitions for register REG_USB_USB_OTGSC */
#define BIT_DPIE                                          ( BIT(30) )
#define BIT_1MSE                                          ( BIT(29) )
#define BIT_BSEIE                                         ( BIT(28) )
#define BIT_BSVIE                                         ( BIT(27) )
#define BIT_ASVIE                                         ( BIT(26) )
#define BIT_AVVIE                                         ( BIT(25) )
#define BIT_IDIE                                          ( BIT(24) )
#define BIT_DPIS                                          ( BIT(22) )
#define BIT_1MSS                                          ( BIT(21) )
#define BIT_BSEIS                                         ( BIT(20) )
#define BIT_BSVIS                                         ( BIT(19) )
#define BIT_ASVIS                                         ( BIT(18) )
#define BIT_AVVIS                                         ( BIT(17) )
#define BIT_IDIS                                          ( BIT(16) )
#define BIT_DPS                                           ( BIT(14) )
#define BIT_1MST                                          ( BIT(13) )
#define BIT_BSE                                           ( BIT(12) )
#define BIT_BSV                                           ( BIT(11) )
#define BIT_ASV                                           ( BIT(10) )
#define BIT_AVV                                           ( BIT(9) )
#define BIT_US_ID408                                      ( BIT(8) )
#define BIT_HABA                                          ( BIT(7) )
#define BIT_HADP                                          ( BIT(6) )
#define BIT_IDPU                                          ( BIT(5) )
#define BIT_DP                                            ( BIT(4) )
#define BIT_OT                                            ( BIT(3) )
#define BIT_HAAR                                          ( BIT(2) )
#define BIT_VC                                            ( BIT(1) )
#define BIT_VD                                            ( BIT(0) )

/* bits definitions for register REG_USB_USB_MODE */
#define BIT_SRT                                           ( BIT(15) )
#define BIT_VBPS                                          ( BIT(5) )
#define BIT_US_SDIS427                                    ( BIT(4) )
#define BIT_US_SLOM432                                    ( BIT(3) )
#define BIT_US_ES433                                      ( BIT(2) )
#define BITS_US_CM434(_X_)                                ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_USB_USB_ENDPTSETUPSTAT */
#define BITS_ENDPTSETUPSTAT150(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USB_USB_ENDPTPRIME */
#define BITS_PETB(_X_)                                    ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_PERB(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USB_USB_ENDPTFLUSH */
#define BITS_FETB(_X_)                                    ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_FERB(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USB_USB_ENDPTSTAT */
#define BITS_ETBR(_X_)                                    ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_ERBR(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USB_USB_ENDPTCOMPLETE */
#define BITS_ETCE(_X_)                                    ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_ERCE(_X_)                                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USB_USB_ENDPTCTRL0 */
#define BIT_US_TXE486                                     ( BIT(23) )
#define BITS_TXT488(_X_)                                  ( (_X_) << 18 & (BIT(18)|BIT(19)) )
#define BIT_TXS490                                        ( BIT(16) )
#define BIT_RXE492                                        ( BIT(7) )
#define BITS_RXT494(_X_)                                  ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_RXS496                                        ( BIT(0) )

/* bits definitions for register REG_USB_USB_ENDPTCTRL1-ENDPTCTRL15 */
#define BIT_US_TXE504                                     ( BIT(23) )
#define BIT_TXR                                           ( BIT(22) )
#define BIT_TXI                                           ( BIT(21) )
#define BITS_TXT508(_X_)                                  ( (_X_) << 18 & (BIT(18)|BIT(19)) )
#define BIT_TXD                                           ( BIT(17) )
#define BIT_TXS510                                        ( BIT(16) )
#define BIT_RXE512                                        ( BIT(7) )
#define BIT_RXR                                           ( BIT(6) )
#define BIT_RXI                                           ( BIT(5) )
#define BITS_RXT516(_X_)                                  ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_US_RXD517                                     ( BIT(1) )
#define BIT_RXS518                                        ( BIT(0) )

#endif
