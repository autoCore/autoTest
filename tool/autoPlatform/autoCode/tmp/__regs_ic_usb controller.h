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
#define REG_USB_USB_CAPLENGTH                             ASR_ADDR(REGS_USB_BASE, 0X100)/*Capability Register Length - EHCI Compliant Register*/
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
#define REG_USB_USB_ASYNCLISTADDR                         ASR_ADDR(REGS_USB_BASE, 0X158)/*Host Controller Next Asynchronous List Address Register*/
#define REG_USB_USB_BURSTSIZE                             ASR_ADDR(REGS_USB_BASE, 0X160)/*Programmable Burst Size Register - Host Controller*/
#define REG_USB_IC_USB                                    ASR_ADDR(REGS_USB_BASE, 0X16C)/*IC_USB enable and voltage negotiation*/
#define REG_USB_ULPIVIEWPORT                              ASR_ADDR(REGS_USB_BASE, 0X170)/*ULPI Viewport Register*/
#define REG_USB_USB_ENDPTNAK                              ASR_ADDR(REGS_USB_BASE, 0X178)/*Endpoint NAK Register*/
#define REG_USB_USB_ENDPTNAKEN                            ASR_ADDR(REGS_USB_BASE, 0X17C)/*Endpoint NAK Enable Register*/
#define REG_USB_USB_PORTSC                                ASR_ADDR(REGS_USB_BASE, 0X184)/*Port Status/Control Register*/
#define REG_USB_USB_MODE                                  ASR_ADDR(REGS_USB_BASE, 0X1A8)/*USB Device Mode Register*/



/* bits definitions for register REG_USB_USB_ID */
#define BITS_US_REVISION25(_X_)                           ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_NID5_0(_X_)                                  ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BITS_US_ID29(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_USB_USB_HWGENERAL */
#define BIT_US_SM37                                       ( BIT(9) )
#define BITS_US_PHYM38(_X_)                               ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)) )
#define BITS_US_PHYW39(_X_)                               ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BIT_US_BWT40                                      ( BIT(3) )
#define BITS_US_CLKC41(_X_)                               ( (_X_) << 1 & (BIT(1)|BIT(2)) )
#define BIT_US_RT42                                       ( BIT(0) )

/* bits definitions for register REG_USB_USB_HWHOST */
#define BITS_US_TTPER49(_X_)                              ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_US_TTASY50(_X_)                              ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_US_NPORT52(_X_)                              ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)) )
#define BIT_HC53                                          ( BIT(0) )

/* bits definitions for register REG_USB_USB_HWDEVICE */
#define BITS_US_DEVEP61(_X_)                              ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )
#define BIT_DC62                                          ( BIT(0) )

/* bits definitions for register REG_USB_USB_HWTXBUF */
#define BIT_US_TXLCR69                                    ( BIT(31) )
#define BITS_US_TXCHANADD71(_X_)                          ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_US_TXADD72(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_US_TCBURST73(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USB_USB_HWRXBUF */
#define BITS_US_RXADD81(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_US_RXBURST82(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USB_USB_CAPLENGTH */
#define BITS_US_CAPLENGTH93(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USB_USB_HCIVERSION */
#define BITS_US_HCIVERSION100(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USB_USB_HCSPARAMS */
#define BITS_US_N_TT108(_X_)                              ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_US_N_PTT109(_X_)                             ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_US_PI111                                      ( BIT(16) )
#define BITS_US_N_CC112(_X_)                              ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_US_N_PCC113(_X_)                             ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_US_PPC115                                     ( BIT(4) )
#define BITS_US_N_PORTS116(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_USB_USB_HCCPARAMS */
#define BITS_US_EECP124(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_US_IST125(_X_)                               ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_ASP127                                        ( BIT(2) )
#define BIT_US_PFL128                                     ( BIT(1) )
#define BIT_US_ADC129                                     ( BIT(0) )

/* bits definitions for register REG_USB_USB_DCIVERSION */
#define BITS_US_DCIVERSION137(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USB_USB_DCCPARAMS */
#define BIT_HC145                                         ( BIT(8) )
#define BIT_DC146                                         ( BIT(7) )
#define BITS_US_DEN148(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for register REG_USB_USB_CMD */
#define BITS_US_ITC159(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_FS2                                           ( BIT(15) )
#define BIT_ATDTW                                         ( BIT(14) )
#define BIT_SUTW                                          ( BIT(13) )
#define BIT_ASPE                                          ( BIT(11) )
#define BITS_ASP166(_X_)                                  ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BIT_IAA                                           ( BIT(6) )
#define BIT_ASE                                           ( BIT(5) )
#define BIT_PSE                                           ( BIT(4) )
#define BITS_FS(_X_)                                      ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_US_RST172                                     ( BIT(1) )
#define BIT_US_RS173                                      ( BIT(0) )

/* bits definitions for register REG_USB_USB_STS */
#define BIT_US_TI1181                                     ( BIT(25) )
#define BIT_TI0                                           ( BIT(24) )
#define BIT_US_UPI184                                     ( BIT(19) )
#define BIT_US_UAI185                                     ( BIT(18) )
#define BIT_US_NAKI187                                    ( BIT(16) )
#define BIT_US_AS189                                      ( BIT(15) )
#define BIT_US_PS190                                      ( BIT(14) )
#define BIT_RCL                                           ( BIT(13) )
#define BIT_HCH                                           ( BIT(12) )
#define BIT_US_ULPII194                                   ( BIT(10) )
#define BIT_US_SLI196                                     ( BIT(8) )
#define BIT_US_SRI197                                     ( BIT(7) )
#define BIT_US_URI198                                     ( BIT(6) )
#define BIT_AAI                                           ( BIT(5) )
#define BIT_US_SEI200                                     ( BIT(4) )
#define BIT_US_FRI201                                     ( BIT(3) )
#define BIT_US_PCI202                                     ( BIT(2) )
#define BIT_US_UEI203                                     ( BIT(1) )
#define BIT_US_UI204                                      ( BIT(0) )

/* bits definitions for register REG_USB_USB_INTR */
#define BIT_US_TIE1212                                    ( BIT(25) )
#define BIT_US_TIE0213                                    ( BIT(24) )
#define BIT_US_UPEI215                                    ( BIT(19) )
#define BIT_US_UAEI216                                    ( BIT(18) )
#define BIT_US_NAKE218                                    ( BIT(16) )
#define BIT_US_ULPIE220                                   ( BIT(10) )
#define BIT_US_SLE222                                     ( BIT(8) )
#define BIT_US_SRE223                                     ( BIT(7) )
#define BIT_US_URE224                                     ( BIT(6) )
#define BIT_US_AAE225                                     ( BIT(5) )
#define BIT_US_SEE226                                     ( BIT(4) )
#define BIT_US_FRE227                                     ( BIT(3) )
#define BIT_US_PCE228                                     ( BIT(2) )
#define BIT_US_UEE229                                     ( BIT(1) )
#define BIT_US_UE230                                      ( BIT(0) )

/* bits definitions for register REG_USB_USB_FRINDEX */
#define BITS_US_FRINDEX238(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for register REG_USB_USB_PERIODICLISTBASE */
#define BITS_US_BASEADR245(_X_)                           ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_USB_USB_ASYNCLISTADDR */
#define BITS_US_ASYBASE253(_X_)                           ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )

/* bits definitions for register REG_USB_USB_BURSTSIZE */
#define BITS_US_TXPBURST262(_X_)                          ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_US_RXPBURST263(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USB_IC_USB */
#define BIT_IC8                                           ( BIT(31) )
#define BITS_IC_VDD8(_X_)                                 ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)) )
#define BIT_IC7                                           ( BIT(27) )
#define BITS_IC_VDD7(_X_)                                 ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_IC6                                           ( BIT(23) )
#define BITS_IC_VDD6(_X_)                                 ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_IC5                                           ( BIT(19) )
#define BITS_IC_VDD5(_X_)                                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_IC4                                           ( BIT(15) )
#define BITS_IC_VDD4(_X_)                                 ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_IC3                                           ( BIT(11) )
#define BITS_IC_VDD3(_X_)                                 ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_IC2                                           ( BIT(7) )
#define BITS_IC_VDD2(_X_)                                 ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_IC1                                           ( BIT(3) )
#define BITS_IC_VDD1(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_USB_ULPIVIEWPORT */
#define BIT_ULPIWU                                        ( BIT(30) )
#define BIT_ULPIRW                                        ( BIT(29) )
#define BIT_ULPISS                                        ( BIT(27) )
#define BITS_ULPIPORT(_X_)                                ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BITS_ULPIADDR(_X_)                                ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_ULPIDATRD(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_ULPIDATWR(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_USB_USB_ENDPTNAK */
#define BITS_US_EPTN309(_X_)                              ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_US_EPRN311(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USB_USB_ENDPTNAKEN */
#define BITS_US_EPTNE319(_X_)                             ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_US_EPRNE321(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_USB_USB_PORTSC */
#define BITS_US_PTS329(_X_)                               ( (_X_) << 30 & (BIT(30)|BIT(31)) )
#define BIT_US_STS330                                     ( BIT(29) )
#define BIT_US_PTW331                                     ( BIT(28) )
#define BITS_US_PSPD332(_X_)                              ( (_X_) << 26 & (BIT(26)|BIT(27)) )
#define BIT_US_PTS2333                                    ( BIT(25) )
#define BIT_US_PFSC334                                    ( BIT(24) )
#define BIT_US_PHCD335                                    ( BIT(23) )
#define BIT_US_WKOC336                                    ( BIT(22) )
#define BIT_WKDS                                          ( BIT(21) )
#define BIT_US_WKCN338                                    ( BIT(20) )
#define BITS_US_PTC339(_X_)                               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_US_PIC340(_X_)                               ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_US_PO341                                      ( BIT(13) )
#define BIT_US_PP342                                      ( BIT(12) )
#define BITS_US_LS343(_X_)                                ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BIT_US_HSP344                                     ( BIT(9) )
#define BIT_US_PR347                                      ( BIT(8) )
#define BIT_US_SUSP348                                    ( BIT(7) )
#define BIT_US_FPR349                                     ( BIT(6) )
#define BIT_US_OCC351                                     ( BIT(5) )
#define BIT_US_OCA352                                     ( BIT(4) )
#define BIT_US_PEC353                                     ( BIT(3) )
#define BIT_US_PE354                                      ( BIT(2) )
#define BIT_US_CSC355                                     ( BIT(1) )
#define BIT_US_CCS356                                     ( BIT(0) )

/* bits definitions for register REG_USB_USB_MODE */
#define BIT_US_SDIS364                                    ( BIT(4) )
#define BIT_US_SLOM367                                    ( BIT(3) )
#define BIT_US_ES369                                      ( BIT(2) )
#define BITS_US_CM370(_X_)                                ( (_X_) & (BIT(0)|BIT(1)) )

#endif
