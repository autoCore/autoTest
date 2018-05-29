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


#ifndef __H_REGS_DIGRFTXASPEC_HEADFILE_H__
#define __H_REGS_DIGRFTXASPEC_HEADFILE_H__ __FILE__

#define	REGS_DIGRFTXASPEC

/* registers definitions for DIGRFTXASPEC */
#define REG_DIGRFTXASPEC_DIGRF_TX_SW_RESET                ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0000)/*General Software Reset Register*/
#define REG_DIGRFTXASPEC_DIGRF_TX_DATA_SW_RESET           ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0004)/*Data FIFO Software Reset Register*/
#define REG_DIGRFTXASPEC_DIGRF_TX_CLOCK_RATE              ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0008)/*Clock Rate Selection Register*/
#define REG_DIGRFTXASPEC_DIGRF_TX_GSM_LCT                 ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X000C)/*Data FIFO GSM LCT Value Configuration Register*/
#define REG_DIGRFTXASPEC_DIGRF_TX_LATCH_STATUS            ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0010)/*Status Latch Command Register*/
#define REG_DIGRFTXASPEC_DIGRF_TX_RD_STATUS               ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0014)/*Read Latched Status Register*/
#define REG_DIGRFTXASPEC_DIGRF_TX_PADS_CONFIG             ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0018)/*Line-Driver Configuration Register*/
#define REG_DIGRFTXASPEC_DIGRF_TX_SHUTDOWN                ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X001C)/*Line-Driver Shutdown Command Register*/
#define REG_DIGRFTXASPEC_DIGRF_TX_CLR_STICKY              ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0020)/*Clear Sticky Bits Register*/
#define REG_DIGRFTXASPEC_DIGRF_TX_PLL_SEL                 ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0024)/*Enable Output of the PLL Test Clock in the Serial Interface Register*/
#define REG_DIGRFTXASPEC_DATA_FIFO_DMA_IF                 ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0040)/*Configure DATA FIFO DMA Parameters Register*/
#define REG_DIGRFTXASPEC_DATA_FIFO_SW_CFG                 ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0044)/*Configure DATA FIFO Mode Register*/
#define REG_DIGRFTXASPEC_DATA_FIFO_SW_ACK                 ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0048)/*DATA FIFO Acknowledge Signal (Debug Mode) Register*/
#define REG_DIGRFTXASPEC_RFICC1_PRI_FIFO_PxW0_10          ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x0080)/*Primary RFICC1 FIFO Payload (not last Word) Register*/
#define REG_DIGRFTXASPEC_RFICC1_PRI_FIFO_PxW0_11          ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x009D)/*Primary RFICC1 FIFO Payload (not last Word) Register*/
#define REG_DIGRFTXASPEC_RFICC1_DIV_FIFO_PxW0_10          ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x00C0)/*Diversity RFICC1 FIFO Payload (not last Word) Register*/
#define REG_DIGRFTXASPEC_RFICC1_DIV_FIFO_PxW0_11          ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x00DD)/*Diversity RFICC1 FIFO Payload (not last Word) Register*/
#define REG_DIGRFTXASPEC_PRI_RFICC2_PRI_FIFO_PxW0_10      ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x0100)/*Primary RFICC2 FIFO Payload (not last Word) Register*/
#define REG_DIGRFTXASPEC_PRI_RFICC2_PRI_FIFO_PxW0_11      ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x011D)/*Primary RFICC2 FIFO Payload (not last Word) Register*/
#define REG_DIGRFTXASPEC_DIV_RFICC2_PRI_FIFO_PxW0_10      ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x0140)/*Diversity RFICC2 FIFO Payload (not last Word) Register*/
#define REG_DIGRFTXASPEC_DIV_RFICC2_PRI_FIFO_PxW0_11      ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x015D)/*Diversity RFICC2 FIFO Payload (not last Word) Register*/
#define REG_DIGRFTXASPEC_RFICCx_PRI_LCT0                  ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x009C)/*Primary RFICCx LCT Register*/
#define REG_DIGRFTXASPEC_RFICCx_PRI_LCT1                  ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x011C)/*Primary RFICCx LCT Register*/
#define REG_DIGRFTXASPEC_RFICCx_DIV_LCT0                  ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x00DC)/*Diversity RFICCx LCT Register*/
#define REG_DIGRFTXASPEC_RFICCx_DIV_LCT1                  ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x015C)/*Diversity RFICCx LCT Register*/
#define REG_DIGRFTXASPEC_RFICCx_PRI_THD0                  ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x00BC)/*Primary RFICCx FIFO Threshold for SR Generation Register*/
#define REG_DIGRFTXASPEC_RFICCx_PRI_THD1                  ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x013C)/*Primary RFICCx FIFO Threshold for SR Generation Register*/
#define REG_DIGRFTXASPEC_RFICCx_DIV_THD0                  ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x00FC)/*Diversity RFICCx FIFO Threshold for SR Generation Register*/
#define REG_DIGRFTXASPEC_RFICCx_DIV_THD1                  ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0x017C)/*Diversity RFICCx FIFO Threshold for SR Generation Register*/
#define REG_DIGRFTXASPEC_IFC_PRI_LCT                      ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0184)/*Primary IFC FIFO LCT Register*/
#define REG_DIGRFTXASPEC_IFC_PRI_THD                      ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0188)/*Primary IFC FIFO Threshold for SR Generation Register*/
#define REG_DIGRFTXASPEC_IFC_DIV_FIFO                     ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X01C0)/*Diversity IFC FIFO Payload Register*/
#define REG_DIGRFTXASPEC_IFC_DIV_LCT                      ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X01C4)/*Diversity IFC LCT Register*/
#define REG_DIGRFTXASPEC_IFC_DIV_THD                      ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X01C8)/*Diversity IFC FIFO Threshold for SR Generation Register*/
#define REG_DIGRFTXASPEC_SPH_CFG_TAS_SR                   ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0200)/*Assert SR From a TAS FIFO Register*/
#define REG_DIGRFTXASPEC_SPH_CFG_TAS_WAIT                 ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0204)/*Assert WAIT From a TAS FIFO Register*/
#define REG_DIGRFTXASPEC_SPH_CFG_FIFOS                    ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0208)/*SPH Debug, SR Assert from RFICC and IFC FIFOs, Sleep Mode, SPH SW Reset Register*/
#define REG_DIGRFTXASPEC_FC_CONFIG_REQ                    ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0240)/*Configure FC in Debug Mode Register*/
#define REG_DIGRFTXASPEC_FC_FORCE_STATE                   ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0244)/*Configure FC State Machine Register*/
#define REG_DIGRFTXASPEC_FC_FORCE_SHFT_REG                ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0248)/*Configure FC Shift Register Value Register*/
#define REG_DIGRFTXASPEC_FC_FORCE_STATUS                  ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X024C)/*Configure FC Input Signals from SPH Register*/
#define REG_DIGRFTXASPEC_FC_PRI_DIV_PAD                   ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0250)/*Enable Switching of FC Primary / Diversity Outputs Register*/
#define REG_DIGRFTXASPEC_TAS_Px_PAYLOAD_SW_TCU_RTU_TIMER_TRIG    ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0400)/*Primary TASx FIFO Payload for SW/TCU/RTU/TIMER_TRIG PS32 Register*/
#define REG_DIGRFTXASPEC_TAS_Px_PAYLOAD8_SW_TCU_RTU_TIMER_TRIG    ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0500)/*Primary TASx FIFO Payload for SW/TCU/RTU/TIMER_TRIG PS8 Register*/
#define REG_DIGRFTXASPEC_TAS_PRI_LCT                      ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0600)/*Primary TAS FIFO LCT Register*/
#define REG_DIGRFTXASPEC_TAS_PRI_ENTRY_CFG                ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0604)/*Primary TAS FIFOs Mode Configuration Register*/
#define REG_DIGRFTXASPEC_TAS_Dx_PAYLOAD_SW_TCU_RTU_TIMER_TRIG    ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0800)/*Diversity TASx FIFO Payload for SW/TCU/RTU/TIMER_TRIG PS32 Register*/
#define REG_DIGRFTXASPEC_TAS_Dx_PAYLOAD8_SW_TCU_RTU_TIMER_TRIG    ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0900)/*Diversity TASx FIFO Payload for SW/TCU/RTU/TIMER_TRIG PS8 Register*/
#define REG_DIGRFTXASPEC_TAS_DIV_LCT                      ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0A00)/*Diversity TAS FIFO LCT Register*/
#define REG_DIGRFTXASPEC_TAS_DIV_ENTRY_CFG                ASR_ADDR(REGS_DIGRFTXASPEC_BASE, 0X0A04)/*Diversity TAS FIFOs Mode Configuration Register*/



/* bits definitions for register REG_DIGRFTXASPEC_DIGRF_TX_SW_RESET */
#define BIT_DIGRF_RESET14                                 ( BIT(0) )

/* bits definitions for register REG_DIGRFTXASPEC_DIGRF_TX_DATA_SW_RESET */
#define BIT_DIGRF_RESET22                                 ( BIT(0) )

/* bits definitions for register REG_DIGRFTXASPEC_DIGRF_TX_CLOCK_RATE */
#define BIT_DIGRF_RATE30                                  ( BIT(0) )

/* bits definitions for register REG_DIGRFTXASPEC_DIGRF_TX_GSM_LCT */
#define BITS_LCT38(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DIGRFTXASPEC_DIGRF_TX_LATCH_STATUS */
#define BITS_DIGRF_CMD46(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_DIGRFTXASPEC_DIGRF_TX_RD_STATUS */
#define BITS_DIGRF_STATUS58(_X_)                          (_X_)

/* bits definitions for register REG_DIGRFTXASPEC_DIGRF_TX_PADS_CONFIG */
#define BITS_SWNG(_X_)                                    ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)) )
#define BITS_VCM(_X_)                                     ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_DIGRFTXASPEC_DIGRF_TX_SHUTDOWN */
#define BIT_DIGRF_SHTDN75                                 ( BIT(0) )

/* bits definitions for register REG_DIGRFTXASPEC_DIGRF_TX_CLR_STICKY */
#define BIT_DIGRF_D_IFC_FIFO_OVF83                        ( BIT(12) )
#define BIT_D_IFC_FIFO_FUL                                ( BIT(11) )
#define BIT_D_RFIFCC2_FIFO_FUL                            ( BIT(10) )
#define BIT_D_RFIFCC2_FIFO_OVF                            ( BIT(9) )
#define BIT_D_RFIFCC1_FIFO_FUL                            ( BIT(8) )
#define BIT_D_RFIFCC1_FIFO_OVF                            ( BIT(7) )
#define BIT_DIGRF_P_IFC_FIFO_OVF89                        ( BIT(6) )
#define BIT_P_IFC_FIFO_FUL                                ( BIT(5) )
#define BIT_P_RFIFCC2_FIFO_FUL                            ( BIT(4) )
#define BIT_P_RFIFCC2_FIFO_OVF                            ( BIT(3) )
#define BIT_P_RFIFCC1_FIFO_FUL                            ( BIT(2) )
#define BIT_P_RFIFCC1_FIFO_OVF                            ( BIT(1) )
#define BIT_DATA_FIFO_OVF                                 ( BIT(0) )

/* bits definitions for register REG_DIGRFTXASPEC_DIGRF_TX_PLL_SEL */
#define BITS_DIGRF_SELECT103(_X_)                         ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_DIGRFTXASPEC_DATA_FIFO_DMA_IF */
#define BIT_DMA_RQEN                                      ( BIT(6) )
#define BITS_THRSH112(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_DIGRFTXASPEC_DATA_FIFO_SW_CFG */
#define BIT_ACK_SEL                                       ( BIT(5) )
#define BITS_WB_SWAP(_X_)                                 ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BIT_CTS_SEL                                       ( BIT(2) )
#define BIT_GSM_WB                                        ( BIT(1) )
#define BIT_SW_CTS                                        ( BIT(0) )

/* bits definitions for register REG_DIGRFTXASPEC_DATA_FIFO_SW_ACK */
#define BIT_ACK                                           ( BIT(0) )

/* bits definitions for register REG_DIGRFTXASPEC_RFICC1_PRI_FIFO_PxW0_11 */
#define BITS_DATA139(_X_)                                 (_X_)

/* bits definitions for register REG_DIGRFTXASPEC_RFICC1_DIV_FIFO_PxW0_11 */
#define BITS_DATA146(_X_)                                 (_X_)

/* bits definitions for register REG_DIGRFTXASPEC_PRI_RFICC2_PRI_FIFO_PxW0_11 */
#define BITS_DATA153(_X_)                                 (_X_)

/* bits definitions for register REG_DIGRFTXASPEC_DIV_RFICC2_PRI_FIFO_PxW0_11 */
#define BITS_DATA160(_X_)                                 (_X_)

/* bits definitions for register REG_DIGRFTXASPEC_RFICCx_PRI_LCT1 */
#define BITS_LCT168(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DIGRFTXASPEC_RFICCx_DIV_LCT1 */
#define BITS_LCT176(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DIGRFTXASPEC_RFICCx_PRI_THD1 */
#define BITS_THRSH184(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_DIGRFTXASPEC_RFICCx_DIV_THD1 */
#define BITS_THRSH192(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_DIGRFTXASPEC_IFC_PRI_LCT */
#define BITS_LCT200(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DIGRFTXASPEC_IFC_PRI_THD */
#define BITS_THRSH208(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_DIGRFTXASPEC_IFC_DIV_FIFO */
#define BITS_DATA216(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DIGRFTXASPEC_IFC_DIV_LCT */
#define BITS_LCT224(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DIGRFTXASPEC_IFC_DIV_THD */
#define BITS_THRSH232(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_DIGRFTXASPEC_SPH_CFG_TAS_SR */
#define BITS_TAS_PX_DX239(_X_)                            (_X_)

/* bits definitions for register REG_DIGRFTXASPEC_SPH_CFG_TAS_WAIT */
#define BITS_TAS_PX_DX246(_X_)                            (_X_)

/* bits definitions for register REG_DIGRFTXASPEC_SPH_CFG_FIFOS */
#define BIT_TAS_WAIT_DBG                                  ( BIT(10) )
#define BIT_SR_DBG                                        ( BIT(9) )
#define BIT_SLP                                           ( BIT(8) )
#define BIT_SM_RESET                                      ( BIT(7) )
#define BIT_DATA_FIFO_SR                                  ( BIT(6) )
#define BIT_P_IFC_SR                                      ( BIT(5) )
#define BIT_D_IFC_SR                                      ( BIT(4) )
#define BIT_D_RFICC2_SR                                   ( BIT(3) )
#define BIT_D_RFICC1_SR                                   ( BIT(2) )
#define BIT_P_RFICC2_SR263                                ( BIT(1) )
#define BIT_P_RFICC2_SR264                                ( BIT(0) )

/* bits definitions for register REG_DIGRFTXASPEC_FC_CONFIG_REQ */
#define BIT_MSKWK                                         ( BIT(5) )
#define BIT_FRC_FIFO-SEL                                  ( BIT(4) )
#define BIT_FRC_SOF                                       ( BIT(3) )
#define BIT_FRC_S-R                                       ( BIT(2) )
#define BIT_FRC_ST                                        ( BIT(1) )
#define BIT_RQ                                            ( BIT(0) )

/* bits definitions for register REG_DIGRFTXASPEC_FC_FORCE_STATE */
#define BIT_FRC_IFG                                       ( BIT(1) )
#define BIT_FRC_IDLE                                      ( BIT(0) )

/* bits definitions for register REG_DIGRFTXASPEC_FC_FORCE_SHFT_REG */
#define BITS_VALUE(_X_)                                   (_X_)

/* bits definitions for register REG_DIGRFTXASPEC_FC_FORCE_STATUS */
#define BITS_FIFO_ID(_X_)                                 ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_ENTER_SLP                                     ( BIT(1) )
#define BIT_SOF                                           ( BIT(0) )

/* bits definitions for register REG_DIGRFTXASPEC_FC_PRI_DIV_PAD */
#define BIT_1-2_PADS                                      ( BIT(5) )
#define BIT_DIGRF_SWTCH312                                ( BIT(4) )
#define BIT_LCT_DATA_D                                    ( BIT(3) )
#define BIT_LCT_DATA_C                                    ( BIT(2) )
#define BIT_LCT_DATA_B                                    ( BIT(1) )
#define BIT_LCT_DATA_A                                    ( BIT(0) )

/* bits definitions for register REG_DIGRFTXASPEC_TAS_Px_PAYLOAD_SW_TCU_RTU_TIMER_TRIG */
#define BITS_DATA327(_X_)                                 (_X_)

/* bits definitions for register REG_DIGRFTXASPEC_TAS_Px_PAYLOAD8_SW_TCU_RTU_TIMER_TRIG */
#define BITS_DATA339(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DIGRFTXASPEC_TAS_PRI_LCT */
#define BITS_LCT347(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DIGRFTXASPEC_TAS_PRI_ENTRY_CFG */
#define BITS_ZERO355(_X_)                                 ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BITS_WAIT356(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_DIGRFTXASPEC_TAS_Dx_PAYLOAD_SW_TCU_RTU_TIMER_TRIG */
#define BITS_DATA367(_X_)                                 (_X_)

/* bits definitions for register REG_DIGRFTXASPEC_TAS_Dx_PAYLOAD8_SW_TCU_RTU_TIMER_TRIG */
#define BITS_DATA379(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DIGRFTXASPEC_TAS_DIV_LCT */
#define BITS_LCT387(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DIGRFTXASPEC_TAS_DIV_ENTRY_CFG */
#define BITS_ZERO395(_X_)                                 ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BITS_WAIT396(_X_)                                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

#endif
