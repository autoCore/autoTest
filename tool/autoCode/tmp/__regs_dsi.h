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


#ifndef __H_REGS_DSIADSIB_HEADFILE_H__
#define __H_REGS_DSIADSIB_HEADFILE_H__ __FILE__

#define	REGS_DSIA,DSIB

/* registers definitions for DSIADSIB */
#define REG_DSIA_DSI_CTRL_0                               ASR_ADDR(REGS_DSIA_BASE, 0X0)/*DSI Control Register 0*/
#define REG_DSIB_DSI_CTRL_0                               ASR_ADDR(REGS_DSIB_BASE, 0X0)/*DSI Control Register 0*/
#define REG_DSIA_DSI_CTRL_1                               ASR_ADDR(REGS_DSIA_BASE, 0X4)/*DSI Control Register 1*/
#define REG_DSIB_DSI_CTRL_1                               ASR_ADDR(REGS_DSIB_BASE, 0X4)/*DSI Control Register 1*/
#define REG_DSIA_DSI_IRQ_ST1                              ASR_ADDR(REGS_DSIA_BASE, 0X8)/*DSI Interrupt Status Register1*/
#define REG_DSIB_DSI_IRQ_ST1                              ASR_ADDR(REGS_DSIB_BASE, 0X8)/*DSI Interrupt Status Register1*/
#define REG_DSIA_DSI_IRQ_MASK1                            ASR_ADDR(REGS_DSIA_BASE, 0XC)/*DSI Interrupt Mask Register1*/
#define REG_DSIB_DSI_IRQ_MASK1                            ASR_ADDR(REGS_DSIB_BASE, 0XC)/*DSI Interrupt Mask Register1*/
#define REG_DSIA_DSI_IRQ_ST                               ASR_ADDR(REGS_DSIA_BASE, 0X10)/*DSI Interrupt Status Register*/
#define REG_DSIB_DSI_IRQ_ST                               ASR_ADDR(REGS_DSIB_BASE, 0X10)/*DSI Interrupt Status Register*/
#define REG_DSIA_DSI_IRQ_MASK                             ASR_ADDR(REGS_DSIA_BASE, 0X14)/*DSI Interrupt Mask Register*/
#define REG_DSIB_DSI_IRQ_MASK                             ASR_ADDR(REGS_DSIB_BASE, 0X14)/*DSI Interrupt Mask Register*/
#define REG_DSIA_DSI_FPGA_PHY_CTRL_0                      ASR_ADDR(REGS_DSIA_BASE, 0X18)/*DSI FPGA PHY Control Register 0*/
#define REG_DSIB_DSI_FPGA_PHY_CTRL_0                      ASR_ADDR(REGS_DSIB_BASE, 0X18)/*DSI FPGA PHY Control Register 0*/
#define REG_DSIA_DSI_FPGA_PHY_CTRL_1                      ASR_ADDR(REGS_DSIA_BASE, 0X1C)/*DSI FPGA PHY Control Register 1*/
#define REG_DSIB_DSI_FPGA_PHY_CTRL_1                      ASR_ADDR(REGS_DSIB_BASE, 0X1C)/*DSI FPGA PHY Control Register 1*/
#define REG_DSIA_DSI_CPU_CMD_0                            ASR_ADDR(REGS_DSIA_BASE, 0X20)/*DSI CPU Packet Command Register 0*/
#define REG_DSIB_DSI_CPU_CMD_0                            ASR_ADDR(REGS_DSIB_BASE, 0X20)/*DSI CPU Packet Command Register 0*/
#define REG_DSIA_DSI_CPU_CMD_1                            ASR_ADDR(REGS_DSIA_BASE, 0X24)/*DSI CPU Packet Command Register 1*/
#define REG_DSIB_DSI_CPU_CMD_1                            ASR_ADDR(REGS_DSIB_BASE, 0X24)/*DSI CPU Packet Command Register 1*/
#define REG_DSIA_DSI_CPU_CMD_3                            ASR_ADDR(REGS_DSIA_BASE, 0X2C)/*DSI CPU Packet Command Register 3*/
#define REG_DSIB_DSI_CPU_CMD_3                            ASR_ADDR(REGS_DSIB_BASE, 0X2C)/*DSI CPU Packet Command Register 3*/
#define REG_DSIA_DSI_CPU_WDAT                             ASR_ADDR(REGS_DSIA_BASE, 0X30)/*DSI CPU Packet Data Register*/
#define REG_DSIB_DSI_CPU_WDAT                             ASR_ADDR(REGS_DSIB_BASE, 0X30)/*DSI CPU Packet Data Register*/
#define REG_DSIA_DSI_CPU_STATUS_0                         ASR_ADDR(REGS_DSIA_BASE, 0X34)/*DSI CPU Command Status 0*/
#define REG_DSIB_DSI_CPU_STATUS_0                         ASR_ADDR(REGS_DSIB_BASE, 0X34)/*DSI CPU Command Status 0*/
#define REG_DSIA_DSI_CPU_STATUS_1                         ASR_ADDR(REGS_DSIA_BASE, 0X38)/*DSI CPU Command Status 1*/
#define REG_DSIB_DSI_CPU_STATUS_1                         ASR_ADDR(REGS_DSIB_BASE, 0X38)/*DSI CPU Command Status 1*/
#define REG_DSIA_DSI_CPU_STATUS_2                         ASR_ADDR(REGS_DSIA_BASE, 0X3C)/*DSI CPU Command Status 2*/
#define REG_DSIB_DSI_CPU_STATUS_2                         ASR_ADDR(REGS_DSIB_BASE, 0X3C)/*DSI CPU Command Status 2*/
#define REG_DSIA_DSI_CPU_STATUS_3                         ASR_ADDR(REGS_DSIA_BASE, 0X40)/*DSI CPU Command Status 3*/
#define REG_DSIB_DSI_CPU_STATUS_3                         ASR_ADDR(REGS_DSIB_BASE, 0X40)/*DSI CPU Command Status 3*/
#define REG_DSIA_DSI_CPU_STATUS_4                         ASR_ADDR(REGS_DSIA_BASE, 0X44)/*DSI CPU Command Status 4*/
#define REG_DSIB_DSI_CPU_STATUS_4                         ASR_ADDR(REGS_DSIB_BASE, 0X44)/*DSI CPU Command Status 4*/
#define REG_DSIA_DSI_CPN_STATUS_1                         ASR_ADDR(REGS_DSIA_BASE, 0X4C)/*DSI Command Panel Path Status 1*/
#define REG_DSIB_DSI_CPN_STATUS_1                         ASR_ADDR(REGS_DSIB_BASE, 0X4C)/*DSI Command Panel Path Status 1*/
#define REG_DSIA_DSI_CPN_CMD                              ASR_ADDR(REGS_DSIA_BASE, 0X50)/*DSI Command Panel Command Register*/
#define REG_DSIB_DSI_CPN_CMD                              ASR_ADDR(REGS_DSIB_BASE, 0X50)/*DSI Command Panel Command Register*/
#define REG_DSIA_DSI_CPN_CTRL_0                           ASR_ADDR(REGS_DSIA_BASE, 0X54)/*DSI Command Panel Control 0 Register*/
#define REG_DSIB_DSI_CPN_CTRL_0                           ASR_ADDR(REGS_DSIB_BASE, 0X54)/*DSI Command Panel Control 0 Register*/
#define REG_DSIA_DSI_CPN_CTRL_1                           ASR_ADDR(REGS_DSIA_BASE, 0X58)/*DSI Command Panel Control 1 Register*/
#define REG_DSIB_DSI_CPN_CTRL_1                           ASR_ADDR(REGS_DSIB_BASE, 0X58)/*DSI Command Panel Control 1 Register*/
#define REG_DSIA_DSI_CPN_STATUS_0                         ASR_ADDR(REGS_DSIA_BASE, 0X5C)/*DSI Command Panel Control Status 0*/
#define REG_DSIB_DSI_CPN_STATUS_0                         ASR_ADDR(REGS_DSIB_BASE, 0X5C)/*DSI Command Panel Control Status 0*/
#define REG_DSIA_DSI_RX_PKT_ST_0                          ASR_ADDR(REGS_DSIA_BASE, 0X60)/*DSI RX Packet 0 Status Register*/
#define REG_DSIB_DSI_RX_PKT_ST_0                          ASR_ADDR(REGS_DSIB_BASE, 0X60)/*DSI RX Packet 0 Status Register*/
#define REG_DSIA_DSI_RX_PKT_HDR_0                         ASR_ADDR(REGS_DSIA_BASE, 0X64)/*DSI RX Packet 0 Header Register*/
#define REG_DSIB_DSI_RX_PKT_HDR_0                         ASR_ADDR(REGS_DSIB_BASE, 0X64)/*DSI RX Packet 0 Header Register*/
#define REG_DSIA_DSI_RX_PKT_ST_1                          ASR_ADDR(REGS_DSIA_BASE, 0X68)/*DSI RX Packet 1 Status Register*/
#define REG_DSIB_DSI_RX_PKT_ST_1                          ASR_ADDR(REGS_DSIB_BASE, 0X68)/*DSI RX Packet 1 Status Register*/
#define REG_DSIA_DSI_RX_PKT_HDR_1                         ASR_ADDR(REGS_DSIA_BASE, 0X6C)/*DSI RX Packet 1 Header Register*/
#define REG_DSIB_DSI_RX_PKT_HDR_1                         ASR_ADDR(REGS_DSIB_BASE, 0X6C)/*DSI RX Packet 1 Header Register*/
#define REG_DSIA_DSI_RX_PKT_CTRL                          ASR_ADDR(REGS_DSIA_BASE, 0X70)/*DSI RX Packet Read Control Register*/
#define REG_DSIB_DSI_RX_PKT_CTRL                          ASR_ADDR(REGS_DSIB_BASE, 0X70)/*DSI RX Packet Read Control Register*/
#define REG_DSIA_DSI_RX_PKT_CTRL_1                        ASR_ADDR(REGS_DSIA_BASE, 0X74)/*DSI RX Packet Read Control 1 Register*/
#define REG_DSIB_DSI_RX_PKT_CTRL_1                        ASR_ADDR(REGS_DSIB_BASE, 0X74)/*DSI RX Packet Read Control 1 Register*/
#define REG_DSIA_DSI_RX_PKT_ST_2                          ASR_ADDR(REGS_DSIA_BASE, 0X78)/*DSI RX Packet 2 Status Register*/
#define REG_DSIB_DSI_RX_PKT_ST_2                          ASR_ADDR(REGS_DSIB_BASE, 0X78)/*DSI RX Packet 2 Status Register*/
#define REG_DSIA_DSI_RX_PKT_HDR_2                         ASR_ADDR(REGS_DSIA_BASE, 0X7C)/*DSI RX Packet 2 Header Register*/
#define REG_DSIB_DSI_RX_PKT_HDR_2                         ASR_ADDR(REGS_DSIB_BASE, 0X7C)/*DSI RX Packet 2 Header Register*/
#define REG_DSIA_DSI_LCD_BDG_CTRL0                        ASR_ADDR(REGS_DSIA_BASE, 0X84)/*DSI LCD Bridge Control Register 0*/
#define REG_DSIB_DSI_LCD_BDG_CTRL0                        ASR_ADDR(REGS_DSIB_BASE, 0X84)/*DSI LCD Bridge Control Register 0*/
#define REG_DSIA_DSI_LCD_BDG_CTRL1                        ASR_ADDR(REGS_DSIA_BASE, 0X88)/*DSI LCD Bridge Control Register 1*/
#define REG_DSIB_DSI_LCD_BDG_CTRL1                        ASR_ADDR(REGS_DSIB_BASE, 0X88)/*DSI LCD Bridge Control Register 1*/
#define REG_DSIA_DSI_TX_TIMER                             ASR_ADDR(REGS_DSIA_BASE, 0XE4)/*DSI TX Timer Register*/
#define REG_DSIB_DSI_TX_TIMER                             ASR_ADDR(REGS_DSIB_BASE, 0XE4)/*DSI TX Timer Register*/
#define REG_DSIA_DSI_RX_TIMER                             ASR_ADDR(REGS_DSIA_BASE, 0XE8)/*DSI RX Timer Register*/
#define REG_DSIB_DSI_RX_TIMER                             ASR_ADDR(REGS_DSIB_BASE, 0XE8)/*DSI RX Timer Register*/
#define REG_DSIA_DSI_TURN_TIMER                           ASR_ADDR(REGS_DSIA_BASE, 0XEC)/*DSI Turn Around Timer Register*/
#define REG_DSIB_DSI_TURN_TIMER                           ASR_ADDR(REGS_DSIB_BASE, 0XEC)/*DSI Turn Around Timer Register*/
#define REG_DSIA_DSI_VPN_CTRL_0                           ASR_ADDR(REGS_DSIA_BASE, 0X100)/*DSI Video Panel  Control Register 0*/
#define REG_DSIB_DSI_VPN_CTRL_0                           ASR_ADDR(REGS_DSIB_BASE, 0X100)/*DSI Video Panel  Control Register 0*/
#define REG_DSIA_DSI_VPN_CTRL_1                           ASR_ADDR(REGS_DSIA_BASE, 0X104)/*DSI Video Panel Control Register 1*/
#define REG_DSIB_DSI_VPN_CTRL_1                           ASR_ADDR(REGS_DSIB_BASE, 0X104)/*DSI Video Panel Control Register 1*/
#define REG_DSIA_DSI_VPN_TIMING_0                         ASR_ADDR(REGS_DSIA_BASE, 0X110)/*DSI Video Panel Timing Register 0*/
#define REG_DSIB_DSI_VPN_TIMING_0                         ASR_ADDR(REGS_DSIB_BASE, 0X110)/*DSI Video Panel Timing Register 0*/
#define REG_DSIA_DSI_VPN_TIMING_1                         ASR_ADDR(REGS_DSIA_BASE, 0X114)/*DSI Video Panel Timing Register 1*/
#define REG_DSIB_DSI_VPN_TIMING_1                         ASR_ADDR(REGS_DSIB_BASE, 0X114)/*DSI Video Panel Timing Register 1*/
#define REG_DSIA_DSI_VPN_TIMING_2                         ASR_ADDR(REGS_DSIA_BASE, 0X118)/*DSI Video Panel Timing Register 2*/
#define REG_DSIB_DSI_VPN_TIMING_2                         ASR_ADDR(REGS_DSIB_BASE, 0X118)/*DSI Video Panel Timing Register 2*/
#define REG_DSIA_DSI_VPN_TIMING_3                         ASR_ADDR(REGS_DSIA_BASE, 0X11C)/*DSI Video Panel Timing Register 3*/
#define REG_DSIB_DSI_VPN_TIMING_3                         ASR_ADDR(REGS_DSIB_BASE, 0X11C)/*DSI Video Panel Timing Register 3*/
#define REG_DSIA_DSI_VPN_WC_0                             ASR_ADDR(REGS_DSIA_BASE, 0X120)/*DSI Video Panel Word Count Register 0*/
#define REG_DSIB_DSI_VPN_WC_0                             ASR_ADDR(REGS_DSIB_BASE, 0X120)/*DSI Video Panel Word Count Register 0*/
#define REG_DSIA_DSI_VPN_WC_1                             ASR_ADDR(REGS_DSIA_BASE, 0X124)/*DSI Video Panel Word Count Register 1*/
#define REG_DSIB_DSI_VPN_WC_1                             ASR_ADDR(REGS_DSIB_BASE, 0X124)/*DSI Video Panel Word Count Register 1*/
#define REG_DSIA_DSI_VPN_WC_2                             ASR_ADDR(REGS_DSIA_BASE, 0X128)/*DSI Video Panel Word Count Register 2*/
#define REG_DSIB_DSI_VPN_WC_2                             ASR_ADDR(REGS_DSIB_BASE, 0X128)/*DSI Video Panel Word Count Register 2*/
#define REG_DSIA_DSI_VPN_SLOT_CNT_0                       ASR_ADDR(REGS_DSIA_BASE, 0X130)/*DSI Video Panel Time Slot Count 0 Register*/
#define REG_DSIB_DSI_VPN_SLOT_CNT_0                       ASR_ADDR(REGS_DSIB_BASE, 0X130)/*DSI Video Panel Time Slot Count 0 Register*/
#define REG_DSIA_DSI_VPN_SLOT_CNT_1                       ASR_ADDR(REGS_DSIA_BASE, 0X134)/*DSI Video Panel Time Slot Count 1*/
#define REG_DSIB_DSI_VPN_SLOT_CNT_1                       ASR_ADDR(REGS_DSIB_BASE, 0X134)/*DSI Video Panel Time Slot Count 1*/
#define REG_DSIA_DSI_VPN_SYNC_CODE                        ASR_ADDR(REGS_DSIA_BASE, 0X138)/*DSI Video Panel Sync Code*/
#define REG_DSIB_DSI_VPN_SYNC_CODE                        ASR_ADDR(REGS_DSIB_BASE, 0X138)/*DSI Video Panel Sync Code*/
#define REG_DSIA_DSI_VPN_STATUS_0                         ASR_ADDR(REGS_DSIA_BASE, 0X140)/*DSI VPN Status Register 0*/
#define REG_DSIB_DSI_VPN_STATUS_0                         ASR_ADDR(REGS_DSIB_BASE, 0X140)/*DSI VPN Status Register 0*/
#define REG_DSIA_DSI_VPN_STATUS_1                         ASR_ADDR(REGS_DSIA_BASE, 0X144)/*DSI VPN Status Register 1*/
#define REG_DSIB_DSI_VPN_STATUS_1                         ASR_ADDR(REGS_DSIB_BASE, 0X144)/*DSI VPN Status Register 1*/
#define REG_DSIA_DSI_VPN_STATUS_2                         ASR_ADDR(REGS_DSIA_BASE, 0X148)/*DSI VPN Status Register 2*/
#define REG_DSIB_DSI_VPN_STATUS_2                         ASR_ADDR(REGS_DSIB_BASE, 0X148)/*DSI VPN Status Register 2*/
#define REG_DSIA_DSI_VPN_STATUS_3                         ASR_ADDR(REGS_DSIA_BASE, 0X14C)/*DSI VPN Status Register 3*/
#define REG_DSIB_DSI_VPN_STATUS_3                         ASR_ADDR(REGS_DSIB_BASE, 0X14C)/*DSI VPN Status Register 3*/
#define REG_DSIA_DSI_VPN_STATUS_4                         ASR_ADDR(REGS_DSIA_BASE, 0X150)/*DSI VPN Status Register 4*/
#define REG_DSIB_DSI_VPN_STATUS_4                         ASR_ADDR(REGS_DSIB_BASE, 0X150)/*DSI VPN Status Register 4*/
#define REG_DSIA_DSI_PHY_CTRL_0                           ASR_ADDR(REGS_DSIA_BASE, 0X180)/*DPHY Control Register 0*/
#define REG_DSIB_DSI_PHY_CTRL_0                           ASR_ADDR(REGS_DSIB_BASE, 0X180)/*DPHY Control Register 0*/
#define REG_DSIA_DSI_PHY_CTRL_1                           ASR_ADDR(REGS_DSIA_BASE, 0X184)/*DPHY Control Register 1*/
#define REG_DSIB_DSI_PHY_CTRL_1                           ASR_ADDR(REGS_DSIB_BASE, 0X184)/*DPHY Control Register 1*/
#define REG_DSIA_DSI_PHY_CTRL_2                           ASR_ADDR(REGS_DSIA_BASE, 0X188)/*DPHY Control Register 2*/
#define REG_DSIB_DSI_PHY_CTRL_2                           ASR_ADDR(REGS_DSIB_BASE, 0X188)/*DPHY Control Register 2*/
#define REG_DSIA_DSI_PHY_CTRL_3                           ASR_ADDR(REGS_DSIA_BASE, 0X18C)/*DPHY Control Register 3*/
#define REG_DSIB_DSI_PHY_CTRL_3                           ASR_ADDR(REGS_DSIB_BASE, 0X18C)/*DPHY Control Register 3*/
#define REG_DSIA_DSI_PHY_STATUS_0                         ASR_ADDR(REGS_DSIA_BASE, 0X190)/*DPHY Status Register 0*/
#define REG_DSIB_DSI_PHY_STATUS_0                         ASR_ADDR(REGS_DSIB_BASE, 0X190)/*DPHY Status Register 0*/
#define REG_DSIA_DSI_PHY_STATUS_1                         ASR_ADDR(REGS_DSIA_BASE, 0X194)/*DPHY Status Register 1*/
#define REG_DSIB_DSI_PHY_STATUS_1                         ASR_ADDR(REGS_DSIB_BASE, 0X194)/*DPHY Status Register 1*/
#define REG_DSIA_DSI_PHY_LPRX_0                           ASR_ADDR(REGS_DSIA_BASE, 0X198)/*DPHY LP RX Register 0*/
#define REG_DSIB_DSI_PHY_LPRX_0                           ASR_ADDR(REGS_DSIB_BASE, 0X198)/*DPHY LP RX Register 0*/
#define REG_DSIA_DSI_PHY_LPRX_1                           ASR_ADDR(REGS_DSIA_BASE, 0X19C)/*DPHY LP RX Register 1*/
#define REG_DSIB_DSI_PHY_LPRX_1                           ASR_ADDR(REGS_DSIB_BASE, 0X19C)/*DPHY LP RX Register 1*/
#define REG_DSIA_DSI_PHY_LPTX_0                           ASR_ADDR(REGS_DSIA_BASE, 0X1A0)/*DPHY LP TX Register 0*/
#define REG_DSIB_DSI_PHY_LPTX_0                           ASR_ADDR(REGS_DSIB_BASE, 0X1A0)/*DPHY LP TX Register 0*/
#define REG_DSIA_DSI_PHY_LPTX_1                           ASR_ADDR(REGS_DSIA_BASE, 0X1A4)/*DPHY LP TX Register 1*/
#define REG_DSIB_DSI_PHY_LPTX_1                           ASR_ADDR(REGS_DSIB_BASE, 0X1A4)/*DPHY LP TX Register 1*/
#define REG_DSIA_DSI_PHY_LPTX_2                           ASR_ADDR(REGS_DSIA_BASE, 0X1A8)/*DPHY LP TX Register 2*/
#define REG_DSIB_DSI_PHY_LPTX_2                           ASR_ADDR(REGS_DSIB_BASE, 0X1A8)/*DPHY LP TX Register 2*/
#define REG_DSIA_DSI_PHY_STATUS_2                         ASR_ADDR(REGS_DSIA_BASE, 0X1AC)/*DPHY Status Register 2*/
#define REG_DSIB_DSI_PHY_STATUS_2                         ASR_ADDR(REGS_DSIB_BASE, 0X1AC)/*DPHY Status Register 2*/
#define REG_DSIA_DSI_PHY_TIME_0                           ASR_ADDR(REGS_DSIA_BASE, 0X1C0)/*DPHY Timing Control Register 0*/
#define REG_DSIB_DSI_PHY_TIME_0                           ASR_ADDR(REGS_DSIB_BASE, 0X1C0)/*DPHY Timing Control Register 0*/
#define REG_DSIA_DSI_PHY_TIME_1                           ASR_ADDR(REGS_DSIA_BASE, 0X1C4)/*DPHY Timing Control Register 1*/
#define REG_DSIB_DSI_PHY_TIME_1                           ASR_ADDR(REGS_DSIB_BASE, 0X1C4)/*DPHY Timing Control Register 1*/
#define REG_DSIA_DSI_PHY_TIME_2                           ASR_ADDR(REGS_DSIA_BASE, 0X1C8)/*DPHY Timing Control Register 2*/
#define REG_DSIB_DSI_PHY_TIME_2                           ASR_ADDR(REGS_DSIB_BASE, 0X1C8)/*DPHY Timing Control Register 2*/
#define REG_DSIA_DSI_PHY_TIME_3                           ASR_ADDR(REGS_DSIA_BASE, 0X1CC)/*DPHY Timing Control Register 3*/
#define REG_DSIB_DSI_PHY_TIME_3                           ASR_ADDR(REGS_DSIB_BASE, 0X1CC)/*DPHY Timing Control Register 3*/
#define REG_DSIA_DSI_PHY_CODE_0                           ASR_ADDR(REGS_DSIA_BASE, 0X1D0)/*DPHY CODE Register 0*/
#define REG_DSIB_DSI_PHY_CODE_0                           ASR_ADDR(REGS_DSIB_BASE, 0X1D0)/*DPHY CODE Register 0*/
#define REG_DSIA_DSI_PHY_CODE_1                           ASR_ADDR(REGS_DSIA_BASE, 0X1D4)/*DPHY CODE Register 1*/
#define REG_DSIB_DSI_PHY_CODE_1                           ASR_ADDR(REGS_DSIB_BASE, 0X1D4)/*DPHY CODE Register 1*/
#define REG_DSIA_DSI_PHY_ANA_PWR_CTRL                     ASR_ADDR(REGS_DSIA_BASE, 0X1E0)/*DPHY ANALOG POWER Controller Register*/
#define REG_DSIB_DSI_PHY_ANA_PWR_CTRL                     ASR_ADDR(REGS_DSIB_BASE, 0X1E0)/*DPHY ANALOG POWER Controller Register*/
#define REG_DSIA_DSI_PHY_ANA_CTRL0                        ASR_ADDR(REGS_DSIA_BASE, 0X1E4)/*DPHY ANALOG Controller Register 0*/
#define REG_DSIB_DSI_PHY_ANA_CTRL0                        ASR_ADDR(REGS_DSIB_BASE, 0X1E4)/*DPHY ANALOG Controller Register 0*/
#define REG_DSIA_DSI_PHY_ANA_CTRL1                        ASR_ADDR(REGS_DSIA_BASE, 0X1E8)/*DPHY ANALOG Controller Register 1*/
#define REG_DSIB_DSI_PHY_ANA_CTRL1                        ASR_ADDR(REGS_DSIB_BASE, 0X1E8)/*DPHY ANALOG Controller Register 1*/



/* bits definitions for register REG_DSIB_DSI_CTRL_0 */
#define BIT_CFG_SOFT_RST                                  ( BIT(31) )
#define BIT_CFG_SOFT_RST_REG                              ( BIT(30) )
#define BIT_CFG_CLR_PHY_FIFO                              ( BIT(29) )
#define BIT_CFG_RST_TXLP                                  ( BIT(28) )
#define BIT_CFG_RST_CPU                                   ( BIT(27) )
#define BIT_CFG_RST_CPN                                   ( BIT(26) )
#define BIT_CFG_RST_VPN                                   ( BIT(24) )
#define BIT_CFG_DSI_PHY_RST                               ( BIT(23) )
#define BIT_CFG_DSI_HCLK_DIS                              ( BIT(17) )
#define BIT_CFG_DSI_CLK_DIS                               ( BIT(16) )
#define BIT_CFG_VPN_TX_EN                                 ( BIT(8) )
#define BIT_CFG_VPN_SLV                                   ( BIT(4) )
#define BIT_CFG_CPN_EN                                    ( BIT(2) )
#define BIT_CFG_VPN_EN                                    ( BIT(0) )

/* bits definitions for register REG_DSIB_DSI_CTRL_1 */
#define BIT_CFG_EOTP_EN                                   ( BIT(8) )
#define BITS_CFG_CPN_VCH_NO(_X_)                          ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_CFG_VPN_VCH_NO(_X_)                          ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_DSIB_DSI_IRQ_ST1 */
#define BIT_IRQ_DPHY_ERR_HS_RXP                           ( BIT(3) )
#define BIT_IRQ_DPHY_ERR_HS_RXN                           ( BIT(2) )
#define BIT_IRQ_DPHY_ERR_HS_CONTP                         ( BIT(1) )
#define BIT_IRQ_DPHY_ERR_HS_CONTN                         ( BIT(0) )

/* bits definitions for register REG_DSIB_DSI_IRQ_MASK1 */
#define BITS_CFG_IRQ_MASK1(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DSIB_DSI_IRQ_ST */
#define BIT_IRQ_LAST_LINE                                 ( BIT(31) )
#define BIT_IRQ_CPN_TE                                    ( BIT(30) )
#define BIT_IRQ_TA_TIMEOUT                                ( BIT(29) )
#define BIT_IRQ_RX_TIMEOUT                                ( BIT(28) )
#define BIT_IRQ_TX_TIMEOUT                                ( BIT(27) )
#define BIT_IRQ_RX_STATE_ERR                              ( BIT(26) )
#define BIT_IRQ_RX_ERR                                    ( BIT(25) )
#define BIT_IRQ_RX_FIFO_FULL_ERR                          ( BIT(24) )
#define BIT_IRQ_PHY_FIFO_UNDERRUN                         ( BIT(23) )
#define BIT_IRQ_REQ_CNT_ERR                               ( BIT(22) )
#define BIT_IRQ_RXPSR_FIFO_FULL_ERR                       ( BIT(21) )
#define BIT_IRQ_VPN_REQ_PHY_DLY_ERR                       ( BIT(20) )
#define BIT_IRQ_VPN_BF_UNDERRUN_ERR                       ( BIT(19) )
#define BIT_IRQ_VPN_REQ_ARB_DLY_ERR                       ( BIT(18) )
#define BIT_IRQ_VPN_BF_OVERRUN_ERR                        ( BIT(17) )
#define BIT_IRQ_VPN_TIMING_ERR                            ( BIT(16) )
#define BIT_IRQ_VPN_VACT_DONE                             ( BIT(15) )
#define BIT_IRQ_VPN_BF_FULL                               ( BIT(14) )
#define BIT_IRQ_CPN_BF_FULL                               ( BIT(13) )
#define BIT_IRQ_DPHY_ERR_CONT_LP1                         ( BIT(12) )
#define BIT_IRQ_DPHY_ERR_CONT_LP0                         ( BIT(11) )
#define BIT_IRQ_DPHY_ERR_SYNC_ESC                         ( BIT(10) )
#define BIT_IRQ_DPHY_ERR_ESC                              ( BIT(9) )
#define BIT_IRQ_DPHY_RX_LINE_ERR                          ( BIT(8) )
#define BIT_IRQ_RX_TRG3                                   ( BIT(7) )
#define BIT_IRQ_RX_TRG2                                   ( BIT(6) )
#define BIT_IRQ_RX_TRG1                                   ( BIT(5) )
#define BIT_IRQ_RX_TRG0                                   ( BIT(4) )
#define BIT_IRQ_RX_ULPS                                   ( BIT(3) )
#define BIT_IRQ_RX_PKT                                    ( BIT(2) )
#define BIT_IRQ_CPN_TX_DONE                               ( BIT(1) )
#define BIT_IRQ_CPU_TX_DONE                               ( BIT(0) )

/* bits definitions for register REG_DSIB_DSI_IRQ_MASK */
#define BITS_CFG_IRQ_MASK(_X_)                            (_X_)

/* bits definitions for register REG_DSIB_DSI_FPGA_PHY_CTRL_0 */
#define BIT_CFG_DPHY_FCLK_REV                             ( BIT(14) )
#define BIT_CFG_DPHY_TXRX_BYTECLK_REV                     ( BIT(13) )
#define BIT_CFG_DPHY_HSREQ_LANE3                          ( BIT(12) )
#define BIT_CFG_DPHY_HSREQ_LANE2                          ( BIT(11) )
#define BIT_CFG_DPHY_HSREQ_LANE1                          ( BIT(10) )
#define BIT_CFG_DPHY_HSREQ_LANE0                          ( BIT(9) )
#define BIT_CFG_DPHY_HSREQ_LANECLK                        ( BIT(8) )
#define BIT_CFG_DPHY_ENABLECLK                            ( BIT(7) )
#define BIT_CFG_DPHY_ENABLE1125                           ( BIT(6) )
#define BIT_CFG_DPHY_ENABLE0126                           ( BIT(5) )
#define BIT_CFG_DPHY_MASSLVZ127                           ( BIT(4) )
#define BIT_CFG_DPHY_TXRXZ                                ( BIT(3) )
#define BIT_CFG_DPHY_RSTZCAL129                           ( BIT(2) )
#define BIT_CFG_DPHY_SHUTDOWN130                          ( BIT(1) )
#define BIT_CFG_DPHY_RESETZ131                            ( BIT(0) )

/* bits definitions for register REG_DSIB_DSI_FPGA_PHY_CTRL_1 */
#define BIT_CFG_DPHY_ENABLE1139                           ( BIT(24) )
#define BITS_CFG_DPHY_ENABLE0140(_X_)                     ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_CFG_DPHY_MASSLVZ141(_X_)                     ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_CFG_DPHY_RSTZCAL143                           ( BIT(2) )
#define BIT_CFG_DPHY_SHUTDOWN144                          ( BIT(1) )
#define BIT_CFG_DPHY_RESETZ145                            ( BIT(0) )

/* bits definitions for register REG_DSIB_DSI_CPU_CMD_0 */
#define BIT_CFG_CPU_CMD_REQ                               ( BIT(31) )
#define BIT_CFG_CPU_SP                                    ( BIT(30) )
#define BIT_CFG_CPU_TURN                                  ( BIT(29) )
#define BIT_CFG_CPU_TXLP                                  ( BIT(27) )
#define BITS_CFG_CPU_WC(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_CPU_CMD_1 */
#define BITS_CFG_TXLP_LPDT(_X_)                           ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_CFG_TXLP_ULPS(_X_)                           ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_CFG_TXLP_TRIGGER_CODE(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_CPU_CMD_3 */
#define BIT_CFG_CPU_DAT_REQ                               ( BIT(31) )
#define BIT_CFG_CPU_DAT_RW                                ( BIT(30) )
#define BITS_CFG_CPU_DAT_ADDR(_X_)                        ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )

/* bits definitions for register REG_DSIB_DSI_CPU_WDAT */
#define BITS_CFG_CPU_WDAT(_X_)                            (_X_)

/* bits definitions for register REG_DSIB_DSI_CPU_STATUS_0 */
#define BITS_CFG_CPU_PKT_CNT(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_CPU_STATUS_1 */
#define BITS_CFG_CPU_CMD_TX_CNT(_X_)                      (_X_)

/* bits definitions for register REG_DSIB_DSI_CPU_STATUS_2 */
#define BITS_CFG_CPU_CMD_CNT(_X_)                         (_X_)

/* bits definitions for register REG_DSIB_DSI_CPU_STATUS_3 */
#define BITS_CFG_TXLP_CNT(_X_)                            (_X_)

/* bits definitions for register REG_DSIB_DSI_CPU_STATUS_4 */
#define BITS_CFG_BTA_CNT(_X_)                             (_X_)

/* bits definitions for register REG_DSIB_DSI_CPN_STATUS_1 */
#define BITS_CFG_CPN_STATUS_1(_X_)                        (_X_)

/* bits definitions for register REG_DSIB_DSI_CPN_CMD */
#define BITS_CFG_CPN_TE_EN(_X_)                           ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_CPN_RGB_TYPE(_X_)                        ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_CFG_CPN_BURST_MODE                            ( BIT(3) )
#define BIT_CFG_CPN_FIRSTP_SEL                            ( BIT(2) )
#define BIT_CFG_CPN_DMA_DIS                               ( BIT(1) )
#define BIT_CFG_CPN_ADDR0_EN                              ( BIT(0) )

/* bits definitions for register REG_DSIB_DSI_CPN_CTRL_0 */
#define BITS_CFG_DCS_LONGWR_CODE(_X_)                     ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BITS_CFG_DCS_WR_CON_CODE(_X_)                     ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_CFG_DCS_WR_STR_CODE(_X_)                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DSIB_DSI_CPN_CTRL_1 */
#define BITS_CFG_CPN_PKT_CNT(_X_)                         ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BITS_CFG_CPN_FIFO_FULL_LEVEL(_X_)                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_DSIB_DSI_CPN_STATUS_0 */
#define BITS_CFG_CPN_FRM_CNT(_X_)                         (_X_)

/* bits definitions for register REG_DSIB_DSI_RX_PKT_ST_0 */
#define BIT_RX_PKT0_ST_VLD                                ( BIT(31) )
#define BIT_RX_PKT0_ST_EOTP                               ( BIT(26) )
#define BIT_RX_PKT0_ST_ACK                                ( BIT(25) )
#define BIT_RX_PKT0_ST_SP                                 ( BIT(24) )
#define BITS_RX_PKT0_PKT_PTR(_X_)                         ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BITS_RX_PKT0_VCH(_X_)                             ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_RX_PKT0_ECC_FLAGS(_X_)                       ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_RX_PKT0_NO_CRC                                ( BIT(4) )
#define BIT_RX_PKT0_UNKNOWN_ERR                           ( BIT(3) )
#define BIT_RX_PKT0_ST_ERR                                ( BIT(2) )
#define BIT_RX_PKT0_ECC_ERR                               ( BIT(1) )
#define BIT_RX_PKT0_CRC_ERR                               ( BIT(0) )

/* bits definitions for register REG_DSIB_DSI_RX_PKT_HDR_0 */
#define BITS_RX_PKT0_HDR(_X_)                             (_X_)

/* bits definitions for register REG_DSIB_DSI_RX_PKT_ST_1 */
#define BIT_RX_PKT1_ST_VLD                                ( BIT(31) )
#define BIT_RX_PKT1_ST_EOTP                               ( BIT(26) )
#define BIT_RX_PKT1_ST_ACK                                ( BIT(25) )
#define BIT_RX_PKT1_ST_SP                                 ( BIT(24) )
#define BITS_RX_PKT1_PKT_PTR(_X_)                         ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BITS_RX_PKT1_VCH(_X_)                             ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_RX_PKT1_ECC_FLAGS(_X_)                       ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_RX_PKT1_NO_CRC                                ( BIT(4) )
#define BIT_RX_PKT1_UNKNOWN_ERR                           ( BIT(3) )
#define BIT_RX_PKT1_ST_ERR                                ( BIT(2) )
#define BIT_RX_PKT1_ECC_ERR                               ( BIT(1) )
#define BIT_RX_PKT1_CRC_ERR                               ( BIT(0) )

/* bits definitions for register REG_DSIB_DSI_RX_PKT_HDR_1 */
#define BITS_RX_PKT1_HDR(_X_)                             (_X_)

/* bits definitions for register REG_DSIB_DSI_RX_PKT_CTRL */
#define BIT_RX_PKT_RD_REQ                                 ( BIT(31) )
#define BITS_RX_PKT_RD_PTR(_X_)                           ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BITS_RX_PKT_RD_DATA(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DSIB_DSI_RX_PKT_CTRL_1 */
#define BITS_RX_PKT_CNT(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_RX_PKT_BCNT(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DSIB_DSI_RX_PKT_ST_2 */
#define BIT_RX_PKT2_ST_VLD                                ( BIT(31) )
#define BIT_RX_PKT2_ST_EOTP                               ( BIT(26) )
#define BIT_RX_PKT2_ST_ACK                                ( BIT(25) )
#define BIT_RX_PKT2_ST_SP                                 ( BIT(24) )
#define BITS_RX_PKT2_PKT_PTR(_X_)                         ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BITS_RX_PKT2_VCH(_X_)                             ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BITS_RX_PKT2_ECC_FLAGS(_X_)                       ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_RX_PKT2_NO_CRC                                ( BIT(4) )
#define BIT_RX_PKT2_UNKNOWN_ERR                           ( BIT(3) )
#define BIT_RX_PKT2_ST_ERR                                ( BIT(2) )
#define BIT_RX_PKT2_ECC_ERR                               ( BIT(1) )
#define BIT_RX_PKT2_CRC_ERR                               ( BIT(0) )

/* bits definitions for register REG_DSIB_DSI_RX_PKT_HDR_2 */
#define BITS_RX_PKT2_HDR(_X_)                             (_X_)

/* bits definitions for register REG_DSIB_DSI_LCD_BDG_CTRL0 */
#define BITS_CFG_VPN_FIFO_AFULL_CNT(_X_)                  ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_CFG_HSYNC_MISSING_FIX                         ( BIT(9) )
#define BIT_CFG_TXLP_LANE_TURN_FIX                        ( BIT(8) )
#define BIT_CFG_VPN_FIFO_AFULL_BYPASS                     ( BIT(6) )
#define BIT_CFG_CPN_VSYNC_EDGE                            ( BIT(5) )
#define BIT_CFG_CPN_TE_EDGE                               ( BIT(4) )
#define BITS_CFG_CPN_TE_MODE(_X_)                         ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_CFG_PIXEL_SWAP                                ( BIT(1) )
#define BIT_CFG_SPLIT_EN                                  ( BIT(0) )

/* bits definitions for register REG_DSIB_DSI_LCD_BDG_CTRL1 */
#define BITS_CFG_CPN_TE_DLY_CNT(_X_)                      ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_CPN_TE_LINE_CNT(_X_)                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_TX_TIMER */
#define BITS_CFG_TX_TIMER_CNT(_X_)                        (_X_)

/* bits definitions for register REG_DSIB_DSI_RX_TIMER */
#define BITS_CFG_RX_TIMER_CNT(_X_)                        (_X_)

/* bits definitions for register REG_DSIB_DSI_TURN_TIMER */
#define BITS_CFG_TURN_TIMER_CNT(_X_)                      (_X_)

/* bits definitions for register REG_DSIB_DSI_VPN_CTRL_0 */
#define BITS_CFG_VPN_DLY_CNT(_X_)                         ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_VPN_TX_DLY_CNT(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DSIB_DSI_VPN_CTRL_1 */
#define BIT_CFG_VPN_VSYNC_RST_EN                          ( BIT(31) )
#define BIT_CFG_VPN_AUTO_WC_DIS                           ( BIT(27) )
#define BIT_CFG_VPN_HACT_WC_EN                            ( BIT(26) )
#define BIT_CFG_VPN_TIMING_CHECK_DIS                      ( BIT(25) )
#define BIT_CFG_VPN_AUTO_DLY_DIS                          ( BIT(24) )
#define BIT_CFG_VPN_HLP_PKT_EN                            ( BIT(22) )
#define BIT_CFG_VPN_HEX_PKT_EN                            ( BIT(21) )
#define BIT_CFG_VPN_HFP_PKT_EN                            ( BIT(20) )
#define BIT_CFG_VPN_HBP_PKT_EN                            ( BIT(18) )
#define BIT_CFG_VPN_HSE_PKT_EN                            ( BIT(17) )
#define BIT_CFG_VPN_HSA_PKT_EN                            ( BIT(16) )
#define BIT_CFG_VPN_HEX_SLOT_EN                           ( BIT(14) )
#define BIT_CFG_VPN_LAST_LINE_TURN                        ( BIT(10) )
#define BIT_CFG_VPN_LPM_FRAME_EN                          ( BIT(9) )
#define BITS_CFG_VPN_BURST_MODE(_X_)                      ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_CFG_VPN_RGB_TYPE(_X_)                        ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_DSIB_DSI_VPN_TIMING_0 */
#define BITS_CFG_VPN_HACT_CNT(_X_)                        ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_VPN_HTOTAL_CNT(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_VPN_TIMING_1 */
#define BITS_CFG_VPN_HSYNC_CNT(_X_)                       ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_VPN_HBP_CNT(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_VPN_TIMING_2 */
#define BITS_CFG_VPN_VACT_CNT(_X_)                        ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_VPN_VTOTAL_CNT(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_VPN_TIMING_3 */
#define BITS_CFG_VPN_VSYNC_CNT(_X_)                       ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_VPN_VBP_CNT(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_VPN_WC_0 */
#define BITS_CFG_VPN_HBP_WC(_X_)                          ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_VPN_HSA_WC(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_VPN_WC_1 */
#define BITS_CFG_VPN_HFP_WC(_X_)                          ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_VPN_HACT_WC(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_VPN_WC_2 */
#define BITS_CFG_VPN_HEX_WC(_X_)                          ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_VPN_HLP_WC(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_VPN_SLOT_CNT_0 */
#define BITS_CFG_VPN_SLOT_SP_CNT(_X_)                     ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_VPN_SLOT_LP_CNT(_X_)                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_VPN_SLOT_CNT_1 */
#define BITS_CFG_VPN_SLOT_TXLP_CNT(_X_)                   ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_VPN_SLOT_TN_CNT(_X_)                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_VPN_SYNC_CODE */

/* bits definitions for register REG_DSIB_DSI_VPN_STATUS_0 */
#define BIT_CFG_VPN_RD_ERR                                ( BIT(31) )
#define BIT_CFG_VPN_LINE_MISS                             ( BIT(30) )
#define BIT_CFG_VPN_RD_2EARLY                             ( BIT(29) )
#define BIT_CFG_VPN_RD_UNDERRUN                           ( BIT(28) )
#define BIT_CFG_VPN_BF_FULL                               ( BIT(27) )
#define BIT_CFG_VPN_RD_DELAY_ERR                          ( BIT(26) )
#define BITS_CFG_VPN_STATUS_0(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )

/* bits definitions for register REG_DSIB_DSI_VPN_STATUS_1 */
#define BITS_CFG_VPN_WRDONE_RDDONE_CNT(_X_)               ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_VPN_WR2RD_CNT(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_VPN_STATUS_2 */
#define BITS_CFG_VPN_UNDERRUN_CNT(_X_)                    ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_VPN_RD_DATWR_CNT(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_VPN_STATUS_3 */
#define BITS_CFG_VPN_REQ_ARB_DLY_CNT(_X_)                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_VPN_REQ_PHY_DLY_CNT(_X_)                 ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_VPN_STATUS_4 */
#define BITS_CFG_VPN_FRM_CNT(_X_)                         (_X_)

/* bits definitions for register REG_DSIB_DSI_PHY_CTRL_0 */
#define BIT_CFG_RX_TRG_REG_DIS                            ( BIT(31) )
#define BIT_CFG_TX_LANE_0                                 ( BIT(30) )
#define BIT_CFG_FCLK_NOT                                  ( BIT(27) )
#define BITS_CFG_STOP_ST_CNT(_X_)                         ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_CFG_RX_DLY_CNT(_X_)                          ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_PHY_CTRL_1 */
#define BIT_CFG_VDD_ANA_VALID                             ( BIT(17) )
#define BIT_CFG_VDD_DVM_VALID                             ( BIT(16) )
#define BIT_CFG_ULPS_REQ_BYTE                             ( BIT(2) )
#define BIT_CFG_TX_ULPS_CLK_ESC                           ( BIT(1) )
#define BIT_CFG_CONT_CLK_HS                               ( BIT(0) )

/* bits definitions for register REG_DSIB_DSI_PHY_CTRL_2 */
#define BIT_CFG_CSR_HSTX_RX_EN                            ( BIT(14) )
#define BITS_CFG_CSR_LANE_MAP(_X_)                        ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BITS_CFG_CSR_LANE_RESC_EN(_X_)                    ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_CFG_CSR_LANE_EN(_X_)                         ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_CFG_CSR_LANE_TURN(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DSIB_DSI_PHY_CTRL_3 */
#define BIT_CFG_FORCECLK_HIZ_HS                           ( BIT(9) )
#define BIT_CFG_FORCECLK_HIZ_LP                           ( BIT(8) )
#define BITS_CFG_FORCE_HIZ_HS(_X_)                        ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_CFG_FORCE_HIZ_LP(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DSIB_DSI_PHY_STATUS_0 */
#define BITS_DPHY_RDY_HS_BYTE(_X_)                        ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_TX_REQ_HS_BYTE(_X_)                          ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_DPHY_LANE_RX_LINE_ERR653(_X_)                ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_DPHY_ERR_SYNC_ESC654(_X_)                    ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_DPHY_ERR_ESC655(_X_)                         ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_DPHY_ERR_CONT_LP0656(_X_)                    ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_DPHY_ERR_CONT_LP1657(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DSIB_DSI_PHY_STATUS_1 */
#define BIT_DPHY_ULP_STATE_BYTE                           ( BIT(31) )
#define BIT_DPHY_STOP_STATE_BYTE                          ( BIT(30) )
#define BIT_DPHY_CLK_ULPS_ACTIVE_N                        ( BIT(29) )
#define BIT_DPHY_RX_CLK_ULPS_N                            ( BIT(28) )
#define BITS_DPHY_LANE_DIR(_X_)                           ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_DPHY_ULPS_ACTIVE_N(_X_)                      ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_DPHY_LANE_RX_LINE_ERR670(_X_)                ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_DPHY_ERR_ESC671(_X_)                         ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_DPHY_ERR_SYNC_ESC672(_X_)                    ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_DPHY_ERR_CONT_LP0673(_X_)                    ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_DPHY_ERR_CONT_LP1674(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DSIB_DSI_PHY_LPRX_0 */
#define BITS_DPHY_LANE_RX_TRG3(_X_)                       ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_DPHY_LANE_RX_TRG2(_X_)                       ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_DPHY_LANE_RX_TRG1(_X_)                       ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_DPHY_LANE_RX_TRG0(_X_)                       ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_DPHY_LANE_RX_ULPS(_X_)                       ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_DPHY_LANE_RX_LPDT(_X_)                       ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_DPHY_LANE_RX_DVALID(_X_)                     ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_DPHY_LANE_RX_CLK(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DSIB_DSI_PHY_LPRX_1 */
#define BITS_DPHY_LANE_DOUT_RX(_X_)                       (_X_)

/* bits definitions for register REG_DSIB_DSI_PHY_LPTX_0 */
#define BITS_DPHY_TX_TRIGGER_ESC_L(_X_)                   ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_DPHY_TX_ULPS_ESC(_X_)                        ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_DPHY_TX_LPDT_ESC(_X_)                        ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_DPHY_TX_VALID_ESC(_X_)                       ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BITS_DPHY_TX_REQ_ESC(_X_)                         ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BITS_DPHY_LANE_RDY_ESC(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DSIB_DSI_PHY_LPTX_1 */
#define BITS_DPHY_TX_TRIGGER_ESC_H(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_DSIB_DSI_PHY_LPTX_2 */
#define BITS_DPHY_TX_DATA_ESC(_X_)                        (_X_)

/* bits definitions for register REG_DSIB_DSI_PHY_STATUS_2 */
#define BITS_CFG_TX_REQ_CNT_R(_X_)                        ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_TX_REQ_CNT(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_PHY_TIME_0 */
#define BITS_CFG_CSR_TIME_HS_EXIT(_X_)                    ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_CSR_TIME_HS_TRAIL(_X_)                   ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_CDG_CSR_TIME_HS_ZERO(_X_)                    ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_CFG_CSR_TIME_HS_PREP(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DSIB_DSI_PHY_TIME_1 */
#define BITS_CFG_CSR_TIME_TA_GET(_X_)                     ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_CSR_TIME_TA_GO(_X_)                      ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_CFG_CSR_TIME_WAKEUP(_X_)                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_DSIB_DSI_PHY_TIME_2 */
#define BITS_CFG_CSR_TIME_CK_EXIT(_X_)                    ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_CSR_TIME_CK_TRAIL(_X_)                   ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_CFG_CSR_TIME_CK_ZERO(_X_)                    ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_CFG_CSR_TIME_CK_LPX(_X_)                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DSIB_DSI_PHY_TIME_3 */
#define BITS_CFG_CSR_TIME_LPX(_X_)                        ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_CFG_CSR_TIME_REQRDY(_X_)                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DSIB_DSI_PHY_CODE_0 */
#define BITS_CFG_TRIG3_CODE(_X_)                          ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_TRIG2_CODE(_X_)                          ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_CFG_TRIG1_CODE(_X_)                          ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_CFG_TRIG0_CODE(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_DSIB_DSI_PHY_CODE_1 */
#define BITS_CFG_CSR_ULPS_CODE(_X_)                       ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_CSR_LPDT_CODE(_X_)                       ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )

/* bits definitions for register REG_DSIB_DSI_PHY_ANA_PWR_CTRL */
#define BIT_CFG_DPHY_ANA_RESETB                           ( BIT(8) )
#define BIT_CFG_DPHY_ANA_PU                               ( BIT(0) )

/* bits definitions for register REG_DSIB_DSI_PHY_ANA_CTRL0 */
#define BITS_CFG_DPHY_LPRX_VTTH(_X_)                      ( (_X_) << 29 & (BIT(29)|BIT(30)|BIT(31)) )
#define BITS_CFG_DPHY_LPRX_VTHL(_X_)                      ( (_X_) << 26 & (BIT(26)|BIT(27)|BIT(28)) )
#define BITS_CFG_DPHY_LPTX_RES(_X_)                       ( (_X_) << 24 & (BIT(24)|BIT(25)) )
#define BITS_CFG_DPHY_HSTX_RES(_X_)                       ( (_X_) << 21 & (BIT(21)|BIT(22)|BIT(23)) )
#define BIT_CFG_DPHY_HSTX_LP                              ( BIT(20) )
#define BITS_CFG_DPHY_ADJ_DLY_CK(_X_)                     ( (_X_) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_CFG_DPHY_EN_CH_CK                             ( BIT(16) )
#define BITS_CFG_DPHY_ADJ_DLY3(_X_)                       ( (_X_) << 13 & (BIT(13)|BIT(14)|BIT(15)) )
#define BIT_CFG_DPHY_EN_CH3                               ( BIT(12) )
#define BITS_CFG_DPHY_ADJ_DLY2(_X_)                       ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_CFG_DPHY_EN_CH2                               ( BIT(8) )
#define BITS_CFG_DPHY_ADJ_DLY1(_X_)                       ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_CFG_DPHY_EN_CH1                               ( BIT(4) )
#define BITS_CFG_DPHY_ADJ_DLY0(_X_)                       ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)) )
#define BIT_CFG_DPHY_EN_CH0                               ( BIT(0) )

/* bits definitions for register REG_DSIB_DSI_PHY_ANA_CTRL1 */
#define BIT_CFG_CLK_SEL                                   ( BIT(23) )
#define BIT_CFG_SWAP_PN_CH3                               ( BIT(20) )
#define BIT_CFG_SWAP_PN_CH2                               ( BIT(19) )
#define BIT_CFG_SWAP_PN_CHCK                              ( BIT(18) )
#define BIT_CFG_SWAP_PN_CH1                               ( BIT(17) )
#define BIT_CFG_SWAP_PN_CH0                               ( BIT(16) )
#define BIT_CFG_SET_TEST                                  ( BIT(15) )
#define BIT_DFG_SET_TEST_LP                               ( BIT(14) )
#define BITS_DFG_TEST_PATTERN(_X_)                        ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BIT_CFG_EN_CLK_DIV2                               ( BIT(11) )
#define BITS_CFG_DPHY_HSTX_VREF(_X_)                      ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)) )
#define BITS_CFG_DPHY_LPCDVTHH(_X_)                       ( (_X_) << 5 & (BIT(5)|BIT(6)|BIT(7)) )
#define BITS_CFG_DPHY_LPCDVTHL(_X_)                       ( (_X_) << 2 & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_CFG_DPHY_PULL_DN                              ( BIT(1) )
#define BIT_CFG_DPHY_PULL_DN_CH0                          ( BIT(0) )

#endif
