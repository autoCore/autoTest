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


#ifndef __H_REGS_UTMI_HEADFILE_H__
#define __H_REGS_UTMI_HEADFILE_H__ __FILE__

#define	REGS_UTMI

/* registers definitions for UTMI */
#define REG_UTMI_PLL_CTRL0                                ASR_ADDR(REGS_UTMI_BASE, 0X0)/*USB2 PHY PLL Register*/
#define REG_UTMI_PLL_CTRL1                                ASR_ADDR(REGS_UTMI_BASE, 0X4)/*PLL Control Register 1*/
#define REG_UTMI_CALIBRATION_CTRL1                        ASR_ADDR(REGS_UTMI_BASE, 0X8)/*Calibration Control Register*/
#define REG_UTMI_USB2_TX_0                                ASR_ADDR(REGS_UTMI_BASE, 0X0C)/*Tx Channel Control Register 0*/
#define REG_UTMI_USB2_TX_1                                ASR_ADDR(REGS_UTMI_BASE, 0X10)/*Tx Channel Control Register 1*/
#define REG_UTMI_USB2_RX_0                                ASR_ADDR(REGS_UTMI_BASE, 0X14)/*Rx Channel Control Register 0*/
#define REG_UTMI_USB2_RX_1                                ASR_ADDR(REGS_UTMI_BASE, 0X18)/*Rx Channel Control Register 1*/
#define REG_UTMI_USB_DIG_0                                ASR_ADDR(REGS_UTMI_BASE, 0X1C)/*Digital Control Register 0*/
#define REG_UTMI_USB2_DIG_1                               ASR_ADDR(REGS_UTMI_BASE, 0X20)/*Digital Control Register 1*/
#define REG_UTMI_USB2_TEST_0                              ASR_ADDR(REGS_UTMI_BASE, 0X24)/*USB2 Test Control Register 0*/
#define REG_UTMI_USB2_TEST_1                              ASR_ADDR(REGS_UTMI_BASE, 0X28)/*USB2 Test Control Register 1*/
#define REG_UTMI_RSVD1                                    ASR_ADDR(REGS_UTMI_BASE, 0X2C)/*Reserved*/
#define REG_UTMI_RSVD2                                    ASR_ADDR(REGS_UTMI_BASE, 0X30)/*Reserved*/
#define REG_UTMI_USB2_OTG                                 ASR_ADDR(REGS_UTMI_BASE, 0X34)/*USB2OTG Control Register*/
#define REG_UTMI_USB2_CHGDTC                              ASR_ADDR(REGS_UTMI_BASE, 0X38)/*USB2Charger Detector Control Register*/
#define REG_UTMI_RSVD3                                    ASR_ADDR(REGS_UTMI_BASE, 0X3C)/*Reserved*/
#define REG_UTMI_IP_REVISION                              ASR_ADDR(REGS_UTMI_BASE, 0XC0)/*IP Revision Register*/
#define REG_UTMI_USB_CTL                                  ASR_ADDR(REGS_UTMI_BASE, 0XC4)/*USB Control Register*/
#define REG_UTMI_USB_INT_MISC                             ASR_ADDR(REGS_UTMI_BASE, 0XC8)/*USB Int Misc Register*/
#define REG_UTMI_DBG_CTL                                  ASR_ADDR(REGS_UTMI_BASE, 0XCC)/*Debug Control Register*/
#define REG_UTMI_A_PHY1                                   ASR_ADDR(REGS_UTMI_BASE, 0XD0)/*A PHY 1 Register*/
#define REG_UTMI_A_PHY2                                   ASR_ADDR(REGS_UTMI_BASE, 0XD4)/*A PHY 2 Register*/



/* bits definitions for register REG_UTMI_PLL_CTRL0 */
#define BIT_PLL_READY                                     ( BIT(31) )
#define BIT_R_ROTATE                                      ( BIT(30) )
#define BITS_SEL_LPFR(_X_)                                ( (_X_) << 28 & (BIT(28)|BIT(29)) )
#define BITS_FBDIV(_X_)                                   ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BITS_VDDL(_X_)                                    ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_VDDM(_X_)                                    ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BITS_ICP(_X_)                                     ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_REFDIV(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for register REG_UTMI_PLL_CTRL1 */
#define BIT_PLL_STRESS_TEST                               ( BIT(14) )
#define BIT_CLK_BLK_EN                                    ( BIT(13) )
#define BIT_REFCLK_SEL                                    ( BIT(12) )
#define BIT_CLK160M_EN                                    ( BIT(11) )
#define BIT_TXCLK_EN                                      ( BIT(10) )
#define BITS_TESTMON_PLL(_X_)                             ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PLL_SUSPEND_EN                                ( BIT(3) )
#define BIT_PLL_RESET                                     ( BIT(2) )
#define BIT_PU_PLL_BY_REG                                 ( BIT(1) )
#define BIT_PU_PLL42                                      ( BIT(0) )

/* bits definitions for register REG_UTMI_CALIBRATION_CTRL1 */
#define BIT_PLLCAL_DONE                                   ( BIT(31) )
#define BITS_CURRENT_KVCO(_X_)                            ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)) )
#define BITS_CURRENT_IMP(_X_)                             ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_IMPCAL_DONE                                   ( BIT(23) )
#define BIT_PLLCAL_START                                  ( BIT(22) )
#define BITS_PLLCAL(_X_)                                  ( (_X_) << 20 & (BIT(20)|BIT(21)) )
#define BIT_KVCO_EXT                                      ( BIT(19) )
#define BITS_UTM_KVCO56(_X_)                              ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_VCOCAL_POL                                    ( BIT(15) )
#define BIT_IMPCAL_POL                                    ( BIT(14) )
#define BIT_IMPCAL_START                                  ( BIT(13) )
#define BIT_EXT_RCAL_EN                                   ( BIT(12) )
#define BIT_EXT_FS_IMP_EN                                 ( BIT(11) )
#define BITS_IMPCAL_VTH(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BITS_EXT_RCAL(_X_)                                ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_EXT_FS_IMP(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_UTMI_USB2_TX_0 */
#define BIT_PU_BY_REG                                     ( BIT(25) )
#define BIT_PU_ANA                                        ( BIT(24) )
#define BIT_PU_VDDR18                                     ( BIT(23) )
#define BITS_AMP(_X_)                                     ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BITS_IMP_SEL_LS(_X_)                              ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_DRV_EN_LS(_X_)                               ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_FSDRV_EN(_X_)                                ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_LOWVDD_EN                                     ( BIT(6) )
#define BITS_HS_SR_SEL(_X_)                               ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_HSDRV_EN(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_UTMI_USB2_TX_1 */

/* bits definitions for register REG_UTMI_USB2_RX_0 */
#define BIT_CHIRPMODE_SEL                                 ( BIT(29) )
#define BIT_SQ_ANA_DTC_SEL                                ( BIT(28) )
#define BITS_SQ_ANA_VREF(_X_)                             ( (_X_) << 26 & (BIT(26)|BIT(27)) )
#define BIT_RESET_EXT                                     ( BIT(25) )
#define BIT_RESET_EXT_EN                                  ( BIT(24) )
#define BITS_TESTMON(_X_)                                 ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_STRESS_TEST_MODE                              ( BIT(19) )
#define BIT_SQ_VHL_SEL                                    ( BIT(16) )
#define BIT_SQ_DET_EN                                     ( BIT(15) )
#define BIT_SQ_CM_SEL                                     ( BIT(14) )
#define BITS_SQ_DLY_SEL(_X_)                              ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BIT_LINESTATE_EN                                  ( BIT(10) )
#define BITS_DISCON_THRESH(_X_)                           ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_RXVDDL(_X_)                                  ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_RXVDD18(_X_)                                 ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_SQ_THRESH(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_UTMI_USB2_RX_1 */
#define BIT_REG_SQCAL_DONE                                ( BIT(31) )
#define BITS_SQ_DPDM_AMP_SEL(_X_)                         ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_REG_SQ_UD_SWAP                                ( BIT(5) )
#define BIT_REG_SQCAL_START                               ( BIT(4) )
#define BIT_EXT_SQ_AMP_CAL_EN                             ( BIT(3) )
#define BITS_EXT_SQ_AMP_CAL(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_UTMI_USB_DIG_0 */
#define BIT_BITSTAFFING_ERROR                             ( BIT(31) )
#define BIT_LOSS_OF_SYNC_ERROR                            ( BIT(30) )
#define BIT_FIFO_OVF_ERROR                                ( BIT(29) )
#define BIT_CORE_UTMI_SEL                                 ( BIT(26) )
#define BIT_SE1_FILT_SEL                                  ( BIT(25) )
#define BIT_SE0_FILT_SEL                                  ( BIT(24) )
#define BIT_EDGE_OPT_EN                                   ( BIT(23) )
#define BIT_STOP_AT_RXERR                                 ( BIT(22) )
#define BIT_RX_RUNAWAY_EN                                 ( BIT(21) )
#define BIT_LOSSOFSYNC_EN                                 ( BIT(20) )
#define BIT_FIFOOVF_EN                                    ( BIT(19) )
#define BITS_SQ_FILT(_X_)                                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BITS_SQ_BLK(_X_)                                  ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_EARLY_TX_ENABLE                               ( BIT(11) )
#define BIT_RXFILT2_EN                                    ( BIT(10) )
#define BIT_RXFILT1_EN                                    ( BIT(9) )
#define BIT_LONG_EOP                                      ( BIT(8) )
#define BIT_UTM_PLL_LOCK_BYPASS155                        ( BIT(7) )
#define BIT_CLK_SUSPEND_EN                                ( BIT(6) )
#define BIT_HOST_DISCON_SEL1                              ( BIT(5) )
#define BIT_HOST_DISCON_SEL0                              ( BIT(4) )
#define BIT_SYNCDET_WINDOW_EN                             ( BIT(3) )
#define BIT_SYNCDET_WIN32                                 ( BIT(2) )
#define BITS_SYNC_NUM(_X_)                                ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_UTMI_USB2_DIG_1 */
#define BIT_REG_LSIDLE_PRE                                ( BIT(30) )
#define BITS_REG_CLK_OUT_DLY(_X_)                         ( (_X_) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_REG_SAMPLER_PREOFF                            ( BIT(21) )
#define BIT_REG_SAMPLER_ON                                ( BIT(20) )
#define BITS_REG_SAMPLEROFF_DLY(_X_)                      ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_REG_SWAP_DPDM                                 ( BIT(15) )
#define BIT_REG_LAT_UTMI                                  ( BIT(14) )
#define BIT_REG_OPMODE_SEL                                ( BIT(13) )
#define BIT_REG_FLSMODELP_EN                              ( BIT(12) )
#define BIT_REG_FREERUNCLK_EN                             ( BIT(11) )
#define BIT_REG_NOVBUS_DPDM00                             ( BIT(10) )
#define BIT_REG_FS_EOP_MODE                               ( BIT(7) )
#define BIT_REG_DP_PULLDOWN                               ( BIT(6) )
#define BIT_REG_DM_PULLDOWN                               ( BIT(5) )
#define BIT_REG_ARC_DPDM_MODE                             ( BIT(4) )
#define BIT_REG_FS_RX_ERROR_MODE2                         ( BIT(3) )
#define BIT_REG_FS_RX_ERROR_MODE1                         ( BIT(2) )
#define BIT_REG_FS_RX_ERROR_MODE                          ( BIT(1) )
#define BIT_REG_FORCE_END_EN                              ( BIT(0) )

/* bits definitions for register REG_UTMI_USB2_TEST_0 */
#define BIT_TEST_FAIL                                     ( BIT(31) )
#define BIT_TEST_DONE                                     ( BIT(30) )
#define BIT_REG_TEST_EN                                   ( BIT(29) )
#define BIT_REG_TEST_DIG_LPBK                             ( BIT(28) )
#define BIT_REG_TEST_ANA_LPBK                             ( BIT(27) )
#define BIT_REG_TEST_BYPASS                               ( BIT(26) )
#define BIT_REG_TEST_UTMI_SEL                             ( BIT(25) )
#define BIT_REG_TEST_TX_BITSTUFF_EN                       ( BIT(23) )
#define BIT_REG_TEST_SUSPENDM                             ( BIT(22) )
#define BIT_REG_TEST_RESET                                ( BIT(21) )
#define BIT_REG_TEST_TERM_SELECT                          ( BIT(20) )
#define BITS_REG_TEST_XVCR_SELECT(_X_)                    ( (_X_) << 18 & (BIT(18)|BIT(19)) )
#define BITS_REG_TEST_OP_MODE(_X_)                        ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_REG_TEST_SKIP(_X_)                           ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BITS_REG_TEST_MODE(_X_)                           ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_REG_TEST_TX_PATTERN(_X_)                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_UTMI_USB2_TEST_1 */
#define BITS_TEST_LEN(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for register REG_UTMI_RSVD1 */
#define BITS_USB_MON(_X_)                                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_UTM_231(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_REG_MON_SEL(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_UTMI_RSVD2 */

/* bits definitions for register REG_UTMI_USB2_OTG */
#define BIT_OTG_CONTROL_BY_PIN                            ( BIT(5) )
#define BIT_PU_OTG                                        ( BIT(4) )
#define BITS_TESTMON_OTG(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_UTMI_USB2_CHGDTC */
#define BIT_ENABLE_SWITCH_DM                              ( BIT(13) )
#define BIT_ENABLE_SWITCH_DP                              ( BIT(12) )
#define BITS_VSRC_CHARGE(_X_)                             ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BITS_VDAT_CHARGE(_X_)                             ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BIT_CDP_DM_AUTO_SWITCH                            ( BIT(7) )
#define BIT_DP_DM_SWAP_CTRL                               ( BIT(6) )
#define BIT_PU_CHRG_DTC                                   ( BIT(5) )
#define BIT_PD_EN                                         ( BIT(4) )
#define BIT_DCP_EN                                        ( BIT(3) )
#define BIT_CDP_EN                                        ( BIT(2) )
#define BITS_TESTMON_CHRGDTC(_X_)                         ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_UTMI_RSVD3 */

/* bits definitions for register REG_UTMI_IP_REVISION */
#define BITS_PHY_IP_REVISION(_X_)                         ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_IP_REVISION(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_UTMI_USB_CTL */
#define BIT_M_VBUSVALID_M_BVALID_M_AVALID                 ( BIT(30) )
#define BIT_M_VBUSVALID                                   ( BIT(29) )
#define BIT_M_BVALID                                      ( BIT(28) )
#define BIT_M_AVALID                                      ( BIT(27) )
#define BIT_VBUSVALID295                                  ( BIT(26) )
#define BIT_VBUSVALID296                                  ( BIT(25) )
#define BIT_VBUSVALID297                                  ( BIT(24) )
#define BITS_VBUS_ON(_X_)                                 ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BIT_OTG_SUSPENDM_EN                               ( BIT(11) )
#define BIT_REG_XCVR_SELECT_1                             ( BIT(10) )
#define BIT_REG_SEL                                       ( BIT(8) )
#define BITS_REG_OPMODE(_X_)                              ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_REG_TERM_SELECT                               ( BIT(5) )
#define BIT_REG_XCVR_SELECT_0                             ( BIT(4) )
#define BITS_TEST_USB_MODE(_X_)                           ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_PU_PLL308                                     ( BIT(1) )
#define BIT_UTM_PU309                                     ( BIT(0) )

/* bits definitions for register REG_UTMI_USB_INT_MISC */
#define BIT_CHRG_INT_CLR                                  ( BIT(6) )
#define BIT_CHRG_INT_EN                                   ( BIT(5) )
#define BIT_CHRG_DTC_OUT                                  ( BIT(4) )
#define BIT_UTM_RESUME_INT320                             ( BIT(3) )
#define BIT_VBUSDTC_OUT                                   ( BIT(2) )
#define BIT_USB_RESUME_INT_EN                             ( BIT(1) )
#define BIT_CORE_INTERRUPT                                ( BIT(0) )

/* bits definitions for register REG_UTMI_DBG_CTL */
#define BITS_DBG_SEL(_X_)                                 (_X_)

/* bits definitions for register REG_UTMI_A_PHY1 */
#define BIT_CLK_SEL                                       ( BIT(10) )
#define BIT_UTM_XCVR_UDRDIS341                            ( BIT(8) )
#define BITS_SRAM_RTC(_X_)                                ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_SRAM_WTC(_X_)                                ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BIT_PU_SRAM_CTL                                   ( BIT(3) )
#define BIT_INT_MASK_SEL                                  ( BIT(2) )
#define BIT_SRAM_PDWN                                     ( BIT(1) )

/* bits definitions for register REG_UTMI_A_PHY2 */
#define BIT_TX_BITSTUFF_EN                                ( BIT(0) )

#endif
