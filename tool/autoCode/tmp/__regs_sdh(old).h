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


#ifndef __H_REGS_SD1SD2SD3_HEADFILE_H__
#define __H_REGS_SD1SD2SD3_HEADFILE_H__ __FILE__

#define	REGS_SD1,SD2,SD3

/* registers definitions for SD1SD2SD3 */
#define REG_SD1_SD_SYS_ADDR_LOW                           ASR_ADDR(REGS_SD1_BASE, 0X00)/*System Address Low Register*/
#define REG_SD2_SD_SYS_ADDR_LOW                           ASR_ADDR(REGS_SD2_BASE, 0X00)/*System Address Low Register*/
#define REG_SD3_SD_SYS_ADDR_LOW                           ASR_ADDR(REGS_SD3_BASE, 0X00)/*System Address Low Register*/
#define REG_SD1_SD_SYS_ADDR_HIGH                          ASR_ADDR(REGS_SD1_BASE, 0X02)/*System Address High Register*/
#define REG_SD2_SD_SYS_ADDR_HIGH                          ASR_ADDR(REGS_SD2_BASE, 0X02)/*System Address High Register*/
#define REG_SD3_SD_SYS_ADDR_HIGH                          ASR_ADDR(REGS_SD3_BASE, 0X02)/*System Address High Register*/
#define REG_SD1_SD_BLOCK_SIZE                             ASR_ADDR(REGS_SD1_BASE, 0X04)/*Block Size Register*/
#define REG_SD2_SD_BLOCK_SIZE                             ASR_ADDR(REGS_SD2_BASE, 0X04)/*Block Size Register*/
#define REG_SD3_SD_BLOCK_SIZE                             ASR_ADDR(REGS_SD3_BASE, 0X04)/*Block Size Register*/
#define REG_SD1_SD_BLOCK_COUNT                            ASR_ADDR(REGS_SD1_BASE, 0X06)/*Block Count Register*/
#define REG_SD2_SD_BLOCK_COUNT                            ASR_ADDR(REGS_SD2_BASE, 0X06)/*Block Count Register*/
#define REG_SD3_SD_BLOCK_COUNT                            ASR_ADDR(REGS_SD3_BASE, 0X06)/*Block Count Register*/
#define REG_SD1_SD_ARG_LOW                                ASR_ADDR(REGS_SD1_BASE, 0X08)/*Argument Low Register*/
#define REG_SD2_SD_ARG_LOW                                ASR_ADDR(REGS_SD2_BASE, 0X08)/*Argument Low Register*/
#define REG_SD3_SD_ARG_LOW                                ASR_ADDR(REGS_SD3_BASE, 0X08)/*Argument Low Register*/
#define REG_SD1_SD_ARG_HIGH                               ASR_ADDR(REGS_SD1_BASE, 0X0A)/*Argument High Register*/
#define REG_SD2_SD_ARG_HIGH                               ASR_ADDR(REGS_SD2_BASE, 0X0A)/*Argument High Register*/
#define REG_SD3_SD_ARG_HIGH                               ASR_ADDR(REGS_SD3_BASE, 0X0A)/*Argument High Register*/
#define REG_SD1_SD_TRANSFER_MODE                          ASR_ADDR(REGS_SD1_BASE, 0X0C)/*Transfer Mode Register*/
#define REG_SD2_SD_TRANSFER_MODE                          ASR_ADDR(REGS_SD2_BASE, 0X0C)/*Transfer Mode Register*/
#define REG_SD3_SD_TRANSFER_MODE                          ASR_ADDR(REGS_SD3_BASE, 0X0C)/*Transfer Mode Register*/
#define REG_SD1_SD_CMD                                    ASR_ADDR(REGS_SD1_BASE, 0X0E)/*Command Register*/
#define REG_SD2_SD_CMD                                    ASR_ADDR(REGS_SD2_BASE, 0X0E)/*Command Register*/
#define REG_SD3_SD_CMD                                    ASR_ADDR(REGS_SD3_BASE, 0X0E)/*Command Register*/
#define REG_SD1_SD_RESP_0                                 ASR_ADDR(REGS_SD1_BASE, 0X10)/*Response Register 0*/
#define REG_SD2_SD_RESP_0                                 ASR_ADDR(REGS_SD2_BASE, 0X10)/*Response Register 0*/
#define REG_SD3_SD_RESP_0                                 ASR_ADDR(REGS_SD3_BASE, 0X10)/*Response Register 0*/
#define REG_SD1_SD_RESP_1                                 ASR_ADDR(REGS_SD1_BASE, 0X12)/*Response Register 1*/
#define REG_SD2_SD_RESP_1                                 ASR_ADDR(REGS_SD2_BASE, 0X12)/*Response Register 1*/
#define REG_SD3_SD_RESP_1                                 ASR_ADDR(REGS_SD3_BASE, 0X12)/*Response Register 1*/
#define REG_SD1_SD_RESP_2                                 ASR_ADDR(REGS_SD1_BASE, 0X14)/*Response Register 2*/
#define REG_SD2_SD_RESP_2                                 ASR_ADDR(REGS_SD2_BASE, 0X14)/*Response Register 2*/
#define REG_SD3_SD_RESP_2                                 ASR_ADDR(REGS_SD3_BASE, 0X14)/*Response Register 2*/
#define REG_SD1_SD_RESP_3                                 ASR_ADDR(REGS_SD1_BASE, 0X16)/*Response Register 3*/
#define REG_SD2_SD_RESP_3                                 ASR_ADDR(REGS_SD2_BASE, 0X16)/*Response Register 3*/
#define REG_SD3_SD_RESP_3                                 ASR_ADDR(REGS_SD3_BASE, 0X16)/*Response Register 3*/
#define REG_SD1_SD_RESP_4                                 ASR_ADDR(REGS_SD1_BASE, 0X18)/*Response Register 4*/
#define REG_SD2_SD_RESP_4                                 ASR_ADDR(REGS_SD2_BASE, 0X18)/*Response Register 4*/
#define REG_SD3_SD_RESP_4                                 ASR_ADDR(REGS_SD3_BASE, 0X18)/*Response Register 4*/
#define REG_SD1_SD_RESP_5                                 ASR_ADDR(REGS_SD1_BASE, 0X1A)/*Response Register 5*/
#define REG_SD2_SD_RESP_5                                 ASR_ADDR(REGS_SD2_BASE, 0X1A)/*Response Register 5*/
#define REG_SD3_SD_RESP_5                                 ASR_ADDR(REGS_SD3_BASE, 0X1A)/*Response Register 5*/
#define REG_SD1_SD_RESP_6                                 ASR_ADDR(REGS_SD1_BASE, 0X1C)/*Response Register 6*/
#define REG_SD2_SD_RESP_6                                 ASR_ADDR(REGS_SD2_BASE, 0X1C)/*Response Register 6*/
#define REG_SD3_SD_RESP_6                                 ASR_ADDR(REGS_SD3_BASE, 0X1C)/*Response Register 6*/
#define REG_SD1_SD_RESP_7                                 ASR_ADDR(REGS_SD1_BASE, 0X1E)/*Response Register 7*/
#define REG_SD2_SD_RESP_7                                 ASR_ADDR(REGS_SD2_BASE, 0X1E)/*Response Register 7*/
#define REG_SD3_SD_RESP_7                                 ASR_ADDR(REGS_SD3_BASE, 0X1E)/*Response Register 7*/
#define REG_SD1_SD_BUFFER_DATA_PORT_0                     ASR_ADDR(REGS_SD1_BASE, 0X20)/*Buffer Data Port 0 Register*/
#define REG_SD2_SD_BUFFER_DATA_PORT_0                     ASR_ADDR(REGS_SD2_BASE, 0X20)/*Buffer Data Port 0 Register*/
#define REG_SD3_SD_BUFFER_DATA_PORT_0                     ASR_ADDR(REGS_SD3_BASE, 0X20)/*Buffer Data Port 0 Register*/
#define REG_SD1_SD_BUFFER_DATA_PORT_1                     ASR_ADDR(REGS_SD1_BASE, 0X22)/*Buffer Data Port 1 Register*/
#define REG_SD2_SD_BUFFER_DATA_PORT_1                     ASR_ADDR(REGS_SD2_BASE, 0X22)/*Buffer Data Port 1 Register*/
#define REG_SD3_SD_BUFFER_DATA_PORT_1                     ASR_ADDR(REGS_SD3_BASE, 0X22)/*Buffer Data Port 1 Register*/
#define REG_SD1_SD_PRESENT_STATE_1                        ASR_ADDR(REGS_SD1_BASE, 0X24)/*Present State Register 1*/
#define REG_SD2_SD_PRESENT_STATE_1                        ASR_ADDR(REGS_SD2_BASE, 0X24)/*Present State Register 1*/
#define REG_SD3_SD_PRESENT_STATE_1                        ASR_ADDR(REGS_SD3_BASE, 0X24)/*Present State Register 1*/
#define REG_SD1_SD_PRESENT_STATE_2                        ASR_ADDR(REGS_SD1_BASE, 0X26)/*Present State Register 2*/
#define REG_SD2_SD_PRESENT_STATE_2                        ASR_ADDR(REGS_SD2_BASE, 0X26)/*Present State Register 2*/
#define REG_SD3_SD_PRESENT_STATE_2                        ASR_ADDR(REGS_SD3_BASE, 0X26)/*Present State Register 2*/
#define REG_SD1_SD_HOST_CTRL                              ASR_ADDR(REGS_SD1_BASE, 0X28)/*Host Control Register*/
#define REG_SD2_SD_HOST_CTRL                              ASR_ADDR(REGS_SD2_BASE, 0X28)/*Host Control Register*/
#define REG_SD3_SD_HOST_CTRL                              ASR_ADDR(REGS_SD3_BASE, 0X28)/*Host Control Register*/
#define REG_SD1_SD_BLOCK_GAP_CTRL                         ASR_ADDR(REGS_SD1_BASE, 0X2A)/*Block Gap Control Register*/
#define REG_SD2_SD_BLOCK_GAP_CTRL                         ASR_ADDR(REGS_SD2_BASE, 0X2A)/*Block Gap Control Register*/
#define REG_SD3_SD_BLOCK_GAP_CTRL                         ASR_ADDR(REGS_SD3_BASE, 0X2A)/*Block Gap Control Register*/
#define REG_SD1_SD_CLOCK_CTRL                             ASR_ADDR(REGS_SD1_BASE, 0X2C)/*Clock Control Register*/
#define REG_SD2_SD_CLOCK_CTRL                             ASR_ADDR(REGS_SD2_BASE, 0X2C)/*Clock Control Register*/
#define REG_SD3_SD_CLOCK_CTRL                             ASR_ADDR(REGS_SD3_BASE, 0X2C)/*Clock Control Register*/
#define REG_SD1_SD_TIMEOUT_CTRL_SW_RESET                  ASR_ADDR(REGS_SD1_BASE, 0X2E)/*Timeout Control/Software Reset Register*/
#define REG_SD2_SD_TIMEOUT_CTRL_SW_RESET                  ASR_ADDR(REGS_SD2_BASE, 0X2E)/*Timeout Control/Software Reset Register*/
#define REG_SD3_SD_TIMEOUT_CTRL_SW_RESET                  ASR_ADDR(REGS_SD3_BASE, 0X2E)/*Timeout Control/Software Reset Register*/
#define REG_SD1_SD_NORMAL_INT_STATUS                      ASR_ADDR(REGS_SD1_BASE, 0X30)/*Normal Interrupt Status Register*/
#define REG_SD2_SD_NORMAL_INT_STATUS                      ASR_ADDR(REGS_SD2_BASE, 0X30)/*Normal Interrupt Status Register*/
#define REG_SD3_SD_NORMAL_INT_STATUS                      ASR_ADDR(REGS_SD3_BASE, 0X30)/*Normal Interrupt Status Register*/
#define REG_SD1_SD_ERROR_INT_STATUS                       ASR_ADDR(REGS_SD1_BASE, 0X32)/*Error Interrupt Status Register*/
#define REG_SD2_SD_ERROR_INT_STATUS                       ASR_ADDR(REGS_SD2_BASE, 0X32)/*Error Interrupt Status Register*/
#define REG_SD3_SD_ERROR_INT_STATUS                       ASR_ADDR(REGS_SD3_BASE, 0X32)/*Error Interrupt Status Register*/
#define REG_SD1_SD_NORMAL_INT_STATUS_EN                   ASR_ADDR(REGS_SD1_BASE, 0X34)/*Normal Interrupt Status Enable Register*/
#define REG_SD2_SD_NORMAL_INT_STATUS_EN                   ASR_ADDR(REGS_SD2_BASE, 0X34)/*Normal Interrupt Status Enable Register*/
#define REG_SD3_SD_NORMAL_INT_STATUS_EN                   ASR_ADDR(REGS_SD3_BASE, 0X34)/*Normal Interrupt Status Enable Register*/
#define REG_SD1_SD_ERROR_INT_STATUS_EN                    ASR_ADDR(REGS_SD1_BASE, 0X36)/*Error Interrupt Status Enable Register*/
#define REG_SD2_SD_ERROR_INT_STATUS_EN                    ASR_ADDR(REGS_SD2_BASE, 0X36)/*Error Interrupt Status Enable Register*/
#define REG_SD3_SD_ERROR_INT_STATUS_EN                    ASR_ADDR(REGS_SD3_BASE, 0X36)/*Error Interrupt Status Enable Register*/
#define REG_SD1_SD_NORMAL_INT_STATUS_INT_EN               ASR_ADDR(REGS_SD1_BASE, 0X38)/*Normal Interrupt Status Interrupt Enable Register*/
#define REG_SD2_SD_NORMAL_INT_STATUS_INT_EN               ASR_ADDR(REGS_SD2_BASE, 0X38)/*Normal Interrupt Status Interrupt Enable Register*/
#define REG_SD3_SD_NORMAL_INT_STATUS_INT_EN               ASR_ADDR(REGS_SD3_BASE, 0X38)/*Normal Interrupt Status Interrupt Enable Register*/
#define REG_SD1_SD_ERROR_INT_STATUS_INT_EN                ASR_ADDR(REGS_SD1_BASE, 0X3A)/*Error Interrupt Status Interrupt Enable Register*/
#define REG_SD2_SD_ERROR_INT_STATUS_INT_EN                ASR_ADDR(REGS_SD2_BASE, 0X3A)/*Error Interrupt Status Interrupt Enable Register*/
#define REG_SD3_SD_ERROR_INT_STATUS_INT_EN                ASR_ADDR(REGS_SD3_BASE, 0X3A)/*Error Interrupt Status Interrupt Enable Register*/
#define REG_SD1_SD_AUTO_CMD12_ERROR_STATUS                ASR_ADDR(REGS_SD1_BASE, 0X3C)/*Auto CMD12 Error Status Register*/
#define REG_SD2_SD_AUTO_CMD12_ERROR_STATUS                ASR_ADDR(REGS_SD2_BASE, 0X3C)/*Auto CMD12 Error Status Register*/
#define REG_SD3_SD_AUTO_CMD12_ERROR_STATUS                ASR_ADDR(REGS_SD3_BASE, 0X3C)/*Auto CMD12 Error Status Register*/
#define REG_SD1_HOST_CTRL_2                               ASR_ADDR(REGS_SD1_BASE, 0X3E)/*Host Control 2 Register*/
#define REG_SD2_HOST_CTRL_2                               ASR_ADDR(REGS_SD2_BASE, 0X3E)/*Host Control 2 Register*/
#define REG_SD3_HOST_CTRL_2                               ASR_ADDR(REGS_SD3_BASE, 0X3E)/*Host Control 2 Register*/
#define REG_SD1_SD_CAPABILITIES_1                         ASR_ADDR(REGS_SD1_BASE, 0X40)/*Capabilities Register 1*/
#define REG_SD2_SD_CAPABILITIES_1                         ASR_ADDR(REGS_SD2_BASE, 0X40)/*Capabilities Register 1*/
#define REG_SD3_SD_CAPABILITIES_1                         ASR_ADDR(REGS_SD3_BASE, 0X40)/*Capabilities Register 1*/
#define REG_SD1_SD_CAPABILITIES_2                         ASR_ADDR(REGS_SD1_BASE, 0X42)/*Capabilities Register 2*/
#define REG_SD2_SD_CAPABILITIES_2                         ASR_ADDR(REGS_SD2_BASE, 0X42)/*Capabilities Register 2*/
#define REG_SD3_SD_CAPABILITIES_2                         ASR_ADDR(REGS_SD3_BASE, 0X42)/*Capabilities Register 2*/
#define REG_SD1_SD_CAPABILITIES_3                         ASR_ADDR(REGS_SD1_BASE, 0X44)/*Capabilities Register 3*/
#define REG_SD2_SD_CAPABILITIES_3                         ASR_ADDR(REGS_SD2_BASE, 0X44)/*Capabilities Register 3*/
#define REG_SD3_SD_CAPABILITIES_3                         ASR_ADDR(REGS_SD3_BASE, 0X44)/*Capabilities Register 3*/
#define REG_SD1_SD_CAPABILITIES_4                         ASR_ADDR(REGS_SD1_BASE, 0X46)/*Capabilities Register 4*/
#define REG_SD2_SD_CAPABILITIES_4                         ASR_ADDR(REGS_SD2_BASE, 0X46)/*Capabilities Register 4*/
#define REG_SD3_SD_CAPABILITIES_4                         ASR_ADDR(REGS_SD3_BASE, 0X46)/*Capabilities Register 4*/
#define REG_SD1_SD_MAX_CURRENT_1                          ASR_ADDR(REGS_SD1_BASE, 0X48)/*Maximum Current Register 1*/
#define REG_SD2_SD_MAX_CURRENT_1                          ASR_ADDR(REGS_SD2_BASE, 0X48)/*Maximum Current Register 1*/
#define REG_SD3_SD_MAX_CURRENT_1                          ASR_ADDR(REGS_SD3_BASE, 0X48)/*Maximum Current Register 1*/
#define REG_SD1_SD_MAX_CURRENT_2                          ASR_ADDR(REGS_SD1_BASE, 0X4A)/*Maximum Current Register 2*/
#define REG_SD2_SD_MAX_CURRENT_2                          ASR_ADDR(REGS_SD2_BASE, 0X4A)/*Maximum Current Register 2*/
#define REG_SD3_SD_MAX_CURRENT_2                          ASR_ADDR(REGS_SD3_BASE, 0X4A)/*Maximum Current Register 2*/
#define REG_SD1_SD_MAX_CURRENT_3                          ASR_ADDR(REGS_SD1_BASE, 0X4C)/*Maximum Current Register 3*/
#define REG_SD2_SD_MAX_CURRENT_3                          ASR_ADDR(REGS_SD2_BASE, 0X4C)/*Maximum Current Register 3*/
#define REG_SD3_SD_MAX_CURRENT_3                          ASR_ADDR(REGS_SD3_BASE, 0X4C)/*Maximum Current Register 3*/
#define REG_SD1_SD_MAX_CURRENT_4                          ASR_ADDR(REGS_SD1_BASE, 0X4E)/*Maximum Current Register 4*/
#define REG_SD2_SD_MAX_CURRENT_4                          ASR_ADDR(REGS_SD2_BASE, 0X4E)/*Maximum Current Register 4*/
#define REG_SD3_SD_MAX_CURRENT_4                          ASR_ADDR(REGS_SD3_BASE, 0X4E)/*Maximum Current Register 4*/
#define REG_SD1_SD_FORCE_EVENT_AUTO_CMD12_ERROR           ASR_ADDR(REGS_SD1_BASE, 0X50)/*Force Event Auto cmd12 Error Register*/
#define REG_SD2_SD_FORCE_EVENT_AUTO_CMD12_ERROR           ASR_ADDR(REGS_SD2_BASE, 0X50)/*Force Event Auto cmd12 Error Register*/
#define REG_SD3_SD_FORCE_EVENT_AUTO_CMD12_ERROR           ASR_ADDR(REGS_SD3_BASE, 0X50)/*Force Event Auto cmd12 Error Register*/
#define REG_SD1_SD_FORCE_EVENT_FOR_ERROR_STATUS           ASR_ADDR(REGS_SD1_BASE, 0X52)/*Force Event for Error Status Register*/
#define REG_SD2_SD_FORCE_EVENT_FOR_ERROR_STATUS           ASR_ADDR(REGS_SD2_BASE, 0X52)/*Force Event for Error Status Register*/
#define REG_SD3_SD_FORCE_EVENT_FOR_ERROR_STATUS           ASR_ADDR(REGS_SD3_BASE, 0X52)/*Force Event for Error Status Register*/
#define REG_SD1_SD_ADMA_ERROR_STATUS                      ASR_ADDR(REGS_SD1_BASE, 0X54)/*ADMA Error Status Register*/
#define REG_SD2_SD_ADMA_ERROR_STATUS                      ASR_ADDR(REGS_SD2_BASE, 0X54)/*ADMA Error Status Register*/
#define REG_SD3_SD_ADMA_ERROR_STATUS                      ASR_ADDR(REGS_SD3_BASE, 0X54)/*ADMA Error Status Register*/
#define REG_SD1_SD_ADMA_SYS_ADDR_1                        ASR_ADDR(REGS_SD1_BASE, 0X58)/*ADMA System Address Register 1*/
#define REG_SD2_SD_ADMA_SYS_ADDR_1                        ASR_ADDR(REGS_SD2_BASE, 0X58)/*ADMA System Address Register 1*/
#define REG_SD3_SD_ADMA_SYS_ADDR_1                        ASR_ADDR(REGS_SD3_BASE, 0X58)/*ADMA System Address Register 1*/
#define REG_SD1_SD_ADMA_SYS_ADDR_2                        ASR_ADDR(REGS_SD1_BASE, 0X5A)/*ADMA System Address Register 2*/
#define REG_SD2_SD_ADMA_SYS_ADDR_2                        ASR_ADDR(REGS_SD2_BASE, 0X5A)/*ADMA System Address Register 2*/
#define REG_SD3_SD_ADMA_SYS_ADDR_2                        ASR_ADDR(REGS_SD3_BASE, 0X5A)/*ADMA System Address Register 2*/
#define REG_SD1_SD_ADMA_SYS_ADDR_3                        ASR_ADDR(REGS_SD1_BASE, 0X5C)/*ADMA System Address Register 3*/
#define REG_SD2_SD_ADMA_SYS_ADDR_3                        ASR_ADDR(REGS_SD2_BASE, 0X5C)/*ADMA System Address Register 3*/
#define REG_SD3_SD_ADMA_SYS_ADDR_3                        ASR_ADDR(REGS_SD3_BASE, 0X5C)/*ADMA System Address Register 3*/
#define REG_SD1_SD_ADMA_SYS_ADDR_4                        ASR_ADDR(REGS_SD1_BASE, 0X5E)/*ADMA System Address Register 4*/
#define REG_SD2_SD_ADMA_SYS_ADDR_4                        ASR_ADDR(REGS_SD2_BASE, 0X5E)/*ADMA System Address Register 4*/
#define REG_SD3_SD_ADMA_SYS_ADDR_4                        ASR_ADDR(REGS_SD3_BASE, 0X5E)/*ADMA System Address Register 4*/
#define REG_SD1_PRESET_VALUE_FOR_INIT                     ASR_ADDR(REGS_SD1_BASE, 0X60)/*Preset Value Register for Initialization*/
#define REG_SD2_PRESET_VALUE_FOR_INIT                     ASR_ADDR(REGS_SD2_BASE, 0X60)/*Preset Value Register for Initialization*/
#define REG_SD3_PRESET_VALUE_FOR_INIT                     ASR_ADDR(REGS_SD3_BASE, 0X60)/*Preset Value Register for Initialization*/
#define REG_SD1_PRESET_VALUE_FOR_DS                       ASR_ADDR(REGS_SD1_BASE, 0X62)/*Preset Value Register for Default Speed*/
#define REG_SD2_PRESET_VALUE_FOR_DS                       ASR_ADDR(REGS_SD2_BASE, 0X62)/*Preset Value Register for Default Speed*/
#define REG_SD3_PRESET_VALUE_FOR_DS                       ASR_ADDR(REGS_SD3_BASE, 0X62)/*Preset Value Register for Default Speed*/
#define REG_SD1_PRESET_VALUE_FOR_HS                       ASR_ADDR(REGS_SD1_BASE, 0X64)/*Preset Value Register for High Speed*/
#define REG_SD2_PRESET_VALUE_FOR_HS                       ASR_ADDR(REGS_SD2_BASE, 0X64)/*Preset Value Register for High Speed*/
#define REG_SD3_PRESET_VALUE_FOR_HS                       ASR_ADDR(REGS_SD3_BASE, 0X64)/*Preset Value Register for High Speed*/
#define REG_SD1_PRESET_VALUE_FOR_SDR12                    ASR_ADDR(REGS_SD1_BASE, 0X66)/*Preset Value Register for SDR12*/
#define REG_SD2_PRESET_VALUE_FOR_SDR12                    ASR_ADDR(REGS_SD2_BASE, 0X66)/*Preset Value Register for SDR12*/
#define REG_SD3_PRESET_VALUE_FOR_SDR12                    ASR_ADDR(REGS_SD3_BASE, 0X66)/*Preset Value Register for SDR12*/
#define REG_SD1_PRESET_VALUE_FOR_SDR25                    ASR_ADDR(REGS_SD1_BASE, 0X68)/*Preset Value Register for SDR25*/
#define REG_SD2_PRESET_VALUE_FOR_SDR25                    ASR_ADDR(REGS_SD2_BASE, 0X68)/*Preset Value Register for SDR25*/
#define REG_SD3_PRESET_VALUE_FOR_SDR25                    ASR_ADDR(REGS_SD3_BASE, 0X68)/*Preset Value Register for SDR25*/
#define REG_SD1_PRESET_VALUE_FOR_SDR50                    ASR_ADDR(REGS_SD1_BASE, 0X6A)/*Preset Value Register for SDR50*/
#define REG_SD2_PRESET_VALUE_FOR_SDR50                    ASR_ADDR(REGS_SD2_BASE, 0X6A)/*Preset Value Register for SDR50*/
#define REG_SD3_PRESET_VALUE_FOR_SDR50                    ASR_ADDR(REGS_SD3_BASE, 0X6A)/*Preset Value Register for SDR50*/
#define REG_SD1_PRESET_VALUE_FOR_SDR104                   ASR_ADDR(REGS_SD1_BASE, 0X6C)/*Preset Value Register for SDR104*/
#define REG_SD2_PRESET_VALUE_FOR_SDR104                   ASR_ADDR(REGS_SD2_BASE, 0X6C)/*Preset Value Register for SDR104*/
#define REG_SD3_PRESET_VALUE_FOR_SDR104                   ASR_ADDR(REGS_SD3_BASE, 0X6C)/*Preset Value Register for SDR104*/
#define REG_SD1_PRESET_VALUE_FOR_DDR50                    ASR_ADDR(REGS_SD1_BASE, 0X6E)/*Preset Value Register for DDR50*/
#define REG_SD2_PRESET_VALUE_FOR_DDR50                    ASR_ADDR(REGS_SD2_BASE, 0X6E)/*Preset Value Register for DDR50*/
#define REG_SD3_PRESET_VALUE_FOR_DDR50                    ASR_ADDR(REGS_SD3_BASE, 0X6E)/*Preset Value Register for DDR50*/
#define REG_SD1_SHARED_BUS_CTRL                           ASR_ADDR(REGS_SD1_BASE, 0XE0)/*Shared Bus Control Register*/
#define REG_SD2_SHARED_BUS_CTRL                           ASR_ADDR(REGS_SD2_BASE, 0XE0)/*Shared Bus Control Register*/
#define REG_SD3_SHARED_BUS_CTRL                           ASR_ADDR(REGS_SD3_BASE, 0XE0)/*Shared Bus Control Register*/
#define REG_SD1_SD_SLOT_INT_STATUS                        ASR_ADDR(REGS_SD1_BASE, 0XFC)/*Slot Interrupt Status Register*/
#define REG_SD2_SD_SLOT_INT_STATUS                        ASR_ADDR(REGS_SD2_BASE, 0XFC)/*Slot Interrupt Status Register*/
#define REG_SD3_SD_SLOT_INT_STATUS                        ASR_ADDR(REGS_SD3_BASE, 0XFC)/*Slot Interrupt Status Register*/
#define REG_SD1_SD_HOST_CTRL_VER                          ASR_ADDR(REGS_SD1_BASE, 0XFE)/*Host Control Version Register*/
#define REG_SD2_SD_HOST_CTRL_VER                          ASR_ADDR(REGS_SD2_BASE, 0XFE)/*Host Control Version Register*/
#define REG_SD3_SD_HOST_CTRL_VER                          ASR_ADDR(REGS_SD3_BASE, 0XFE)/*Host Control Version Register*/
#define REG_SD1_SD_CFG_FIFO_PARAM                         ASR_ADDR(REGS_SD1_BASE, 0X100)/*SD Extra Parameters Register*/
#define REG_SD2_SD_CFG_FIFO_PARAM                         ASR_ADDR(REGS_SD2_BASE, 0X100)/*SD Extra Parameters Register*/
#define REG_SD3_SD_CFG_FIFO_PARAM                         ASR_ADDR(REGS_SD3_BASE, 0X100)/*SD Extra Parameters Register*/
#define REG_SD1_SD_FIFO_PARAM                             ASR_ADDR(REGS_SD1_BASE, 0X104)/*FIFO Parameters Register*/
#define REG_SD2_SD_FIFO_PARAM                             ASR_ADDR(REGS_SD2_BASE, 0X104)/*FIFO Parameters Register*/
#define REG_SD3_SD_FIFO_PARAM                             ASR_ADDR(REGS_SD3_BASE, 0X104)/*FIFO Parameters Register*/
#define REG_SD1_SD_SPI_MODE                               ASR_ADDR(REGS_SD1_BASE, 0X108)/*SPI Mode Register*/
#define REG_SD2_SD_SPI_MODE                               ASR_ADDR(REGS_SD2_BASE, 0X108)/*SPI Mode Register*/
#define REG_SD3_SD_SPI_MODE                               ASR_ADDR(REGS_SD3_BASE, 0X108)/*SPI Mode Register*/
#define REG_SD1_SD_CLOCK_AND_BURST_SIZE_SETUP             ASR_ADDR(REGS_SD1_BASE, 0X10A)/*Clock and Burst Size Setup Register*/
#define REG_SD2_SD_CLOCK_AND_BURST_SIZE_SETUP             ASR_ADDR(REGS_SD2_BASE, 0X10A)/*Clock and Burst Size Setup Register*/
#define REG_SD3_SD_CLOCK_AND_BURST_SIZE_SETUP             ASR_ADDR(REGS_SD3_BASE, 0X10A)/*Clock and Burst Size Setup Register*/
#define REG_SD1_SD_CE_ATA_1                               ASR_ADDR(REGS_SD1_BASE, 0X10C)/*CE-ATA Register 1*/
#define REG_SD2_SD_CE_ATA_1                               ASR_ADDR(REGS_SD2_BASE, 0X10C)/*CE-ATA Register 1*/
#define REG_SD3_SD_CE_ATA_1                               ASR_ADDR(REGS_SD3_BASE, 0X10C)/*CE-ATA Register 1*/
#define REG_SD1_SD_CE_ATA_2                               ASR_ADDR(REGS_SD1_BASE, 0X10E)/*CE-ATA Register 2*/
#define REG_SD2_SD_CE_ATA_2                               ASR_ADDR(REGS_SD2_BASE, 0X10E)/*CE-ATA Register 2*/
#define REG_SD3_SD_CE_ATA_2                               ASR_ADDR(REGS_SD3_BASE, 0X10E)/*CE-ATA Register 2*/
#define REG_SD1_SD_PAD_IO_SETUP                           ASR_ADDR(REGS_SD1_BASE, 0X110)/*PAD I/O Setup Register*/
#define REG_SD2_SD_PAD_IO_SETUP                           ASR_ADDR(REGS_SD2_BASE, 0X110)/*PAD I/O Setup Register*/
#define REG_SD3_SD_PAD_IO_SETUP                           ASR_ADDR(REGS_SD3_BASE, 0X110)/*PAD I/O Setup Register*/
#define REG_SD1_RX_CFG_REG                                ASR_ADDR(REGS_SD1_BASE, 0X114)/*RX Configuration Register*/
#define REG_SD2_RX_CFG_REG                                ASR_ADDR(REGS_SD2_BASE, 0X114)/*RX Configuration Register*/
#define REG_SD3_RX_CFG_REG                                ASR_ADDR(REGS_SD3_BASE, 0X114)/*RX Configuration Register*/
#define REG_SD1_TX_CFG_REG                                ASR_ADDR(REGS_SD1_BASE, 0X118)/*TX Configuration Register*/
#define REG_SD2_TX_CFG_REG                                ASR_ADDR(REGS_SD2_BASE, 0X118)/*TX Configuration Register*/
#define REG_SD3_TX_CFG_REG                                ASR_ADDR(REGS_SD3_BASE, 0X118)/*TX Configuration Register*/
#define REG_SD1_TUNING_CFG_REG                            ASR_ADDR(REGS_SD1_BASE, 0X11C)/*TUNING CONFIG Register*/
#define REG_SD2_TUNING_CFG_REG                            ASR_ADDR(REGS_SD2_BASE, 0X11C)/*TUNING CONFIG Register*/
#define REG_SD3_TUNING_CFG_REG                            ASR_ADDR(REGS_SD3_BASE, 0X11C)/*TUNING CONFIG Register*/
#define REG_SD1_TUNING_CFG2_REG                           ASR_ADDR(REGS_SD1_BASE, 0X140)/*TUNING Configuration2 Register*/
#define REG_SD2_TUNING_CFG2_REG                           ASR_ADDR(REGS_SD2_BASE, 0X140)/*TUNING Configuration2 Register*/
#define REG_SD3_TUNING_CFG2_REG                           ASR_ADDR(REGS_SD3_BASE, 0X140)/*TUNING Configuration2 Register*/
#define REG_SD1_TRS2RCV_TIMING_REG                        ASR_ADDR(REGS_SD1_BASE, 0X144)/*TRANSIMIT TO RECEIVE TIMING PARAM Regsiter*/
#define REG_SD2_TRS2RCV_TIMING_REG                        ASR_ADDR(REGS_SD2_BASE, 0X144)/*TRANSIMIT TO RECEIVE TIMING PARAM Regsiter*/
#define REG_SD3_TRS2RCV_TIMING_REG                        ASR_ADDR(REGS_SD3_BASE, 0X144)/*TRANSIMIT TO RECEIVE TIMING PARAM Regsiter*/



/* bits definitions for register REG_SD3_SD_SYS_ADDR_LOW */
#define BITS_SD1S_DMA_ADDR_L19(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_SD1S_DMA_ADDR_L20(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_SYS_ADDR_HIGH */
#define BITS_SD1S_DMA_ADDR_H27(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_SD1S_DMA_ADDR_L28(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_BLOCK_SIZE */
#define BITS_SD1S_HOST_DMA_BDRY36(_X_)                    ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BITS_SD1S_BLOCK_SIZE37(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )

/* bits definitions for register REG_SD3_SD_BLOCK_COUNT */
#define BITS_SD1S_BLOCK_COUNT44(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_ARG_LOW */
#define BITS_SD1S_ARG_L51(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_ARG_HIGH */
#define BITS_SD1S_ARG_H58(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_TRANSFER_MODE */
#define BIT_SD1S_MULTI_BLK_SEL66                          ( BIT(5) )
#define BIT_SD1S_TO_HOST_DIR67                            ( BIT(4) )
#define BITS_SD1S_AUTO_CMD_EN68(_X_)                      ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_SD1S_BLK_CNT_EN69                             ( BIT(1) )
#define BIT_SD1S_DMA_EN70                                 ( BIT(0) )

/* bits definitions for register REG_SD3_SD_CMD */
#define BITS_SD1S_CMD_INDEX78(_X_)                        ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BITS_SD1S_CMD_TYPE79(_X_)                         ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_SD1S_DATA_PRESENT80                           ( BIT(5) )
#define BIT_SD1S_CMD_INDEX_CHK_EN81                       ( BIT(4) )
#define BIT_SD1S_CMD_CRC_CHK_EN82                         ( BIT(3) )
#define BITS_SD1S_RESP_TYPE84(_X_)                        ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SD3_SD_RESP_0 */
#define BITS_SD1S_RESP091(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_RESP_1 */
#define BITS_SD1S_RESP198(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_RESP_2 */
#define BITS_SD1S_RESP2105(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_RESP_3 */
#define BITS_SD1S_RESP3112(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_RESP_4 */
#define BITS_SD1S_RESP4119(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_RESP_5 */
#define BITS_SD1S_RESP5126(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_RESP_6 */
#define BITS_SD1S_RESP6133(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_RESP_7 */
#define BITS_SD1S_RESP7140(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_BUFFER_DATA_PORT_0 */
#define BITS_SD1S_CPU_DATA0147(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_BUFFER_DATA_PORT_1 */
#define BITS_SD1S_CPU_DATA1154(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_PRESENT_STATE_1 */
#define BIT_SD1S_BUFFER_RD_EN162                          ( BIT(11) )
#define BIT_SD1S_BUFFER_WR_EN163                          ( BIT(10) )
#define BIT_SD1S_RX_ACTIVE164                             ( BIT(9) )
#define BIT_SD1S_TX_ACTIVE171                             ( BIT(8) )
#define BIT_SD1S_RETUNING_REQ179                          ( BIT(3) )
#define BIT_SD1S__DAT_ACTIVE180                           ( BIT(2) )
#define BIT_SD1S_CMD_INHIBIT_DAT181                       ( BIT(1) )
#define BIT_SD1S_CMD_INHIBIT_CMD182                       ( BIT(0) )

/* bits definitions for register REG_SD3_SD_PRESENT_STATE_2 */
#define BIT_SD1S_CMD_LEVEL190                             ( BIT(8) )
#define BITS_SD1S_DAT_LEVEL191(_X_)                       ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_SD1S_WRITE_PROT192                            ( BIT(3) )
#define BIT_SD1S_CARD_DET193                              ( BIT(2) )
#define BIT_SD1S_CARD_STABLE194                           ( BIT(1) )
#define BIT_SD1S_CARD_INSERTED195                         ( BIT(0) )

/* bits definitions for register REG_SD3_SD_HOST_CTRL */
#define BITS_SD1S_SD_BUS_VLT203(_X_)                      ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_SD1S_SD_BUS_POWER204                          ( BIT(8) )
#define BIT_SD1S_CARD_DET_S206                            ( BIT(7) )
#define BIT_SD1S_CARD_DET_L207                            ( BIT(6) )
#define BIT_SD1S_EX_DATA_WIDTH208                         ( BIT(5) )
#define BITS_SD1S_DMA_SEL209(_X_)                         ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BIT_SD1S_HI_SPEED_EN210                           ( BIT(2) )
#define BIT_SD1S_DATA_WIDTH211                            ( BIT(1) )
#define BIT_SD1S_LED_CTRL212                              ( BIT(0) )

/* bits definitions for register REG_SD3_SD_BLOCK_GAP_CTRL */
#define BIT_SD1S_W_REMOVAL220                             ( BIT(10) )
#define BIT_SD1S_W_INSERTION221                           ( BIT(9) )
#define BIT_SD1S_W_CARD_INT222                            ( BIT(8) )
#define BIT_SD1S_INT_BLK_GAP224                           ( BIT(3) )
#define BIT_SD1S_RD_WAIT_CTL225                           ( BIT(2) )
#define BIT_SD1S_CONT_REQ228                              ( BIT(1) )
#define BIT_SD1S_STOP_AT_BLOCK_GAP_REQ232                 ( BIT(0) )

/* bits definitions for register REG_SD3_SD_CLOCK_CTRL */
#define BITS_SD1S_SD_FREQ_SEL_LO239(_X_)                  ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_SD1S_SD_FREQ_SEL_HI240(_X_)                  ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_SD1S_CLK_GEN_SEL241                           ( BIT(5) )
#define BIT_SD1S_SD_CLK_EN243                             ( BIT(2) )
#define BIT_SD1S_INT_CLK_STABLE244                        ( BIT(1) )
#define BIT_SD1S_INT_CLK_EN245                            ( BIT(0) )

/* bits definitions for register REG_SD3_SD_TIMEOUT_CTRL_SW_RESET */
#define BIT_SD1S_SW_RST_DAT253                            ( BIT(10) )
#define BIT_SD1S_SW_RST_CMD254                            ( BIT(9) )
#define BIT_SD1S_SW_RST_ALL255                            ( BIT(8) )
#define BITS_SD1S_TIMEOUT_VALUE257(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_SD3_SD_NORMAL_INT_STATUS */
#define BIT_SD1S_ERR_INT268                               ( BIT(15) )
#define BIT_SD1S_RETUNING_INT270                          ( BIT(12) )
#define BIT_SD1S_INT_C271                                 ( BIT(11) )
#define BIT_SD1S_INT_B272                                 ( BIT(10) )
#define BIT_SD1S_INT_A273                                 ( BIT(9) )
#define BIT_SD1S_CARD_INT274                              ( BIT(8) )
#define BIT_SD1S_CARD_REM_INT275                          ( BIT(7) )
#define BIT_SD1S_CARD_INS_INT276                          ( BIT(6) )
#define BIT_SD1S_RX_RDY277                                ( BIT(5) )
#define BIT_SD1S_TX_RDY278                                ( BIT(4) )
#define BIT_SD1S_DMA_INT279                               ( BIT(3) )
#define BIT_SD1S_BLOCK_GAP_EVT280                         ( BIT(2) )
#define BIT_SD1S_XFER_COMPLETE281                         ( BIT(1) )
#define BIT_SD1S_CMD_COMPLETE287                          ( BIT(0) )

/* bits definitions for register REG_SD3_SD_ERROR_INT_STATUS */
#define BIT_SD1S_CRC_STATUS_ERR294                        ( BIT(15) )
#define BIT_SD1S_CPL_TIMEOUT_ERR295                       ( BIT(14) )
#define BIT_SD1S_AXI_RESP_ERR296                          ( BIT(13) )
#define BIT_SD1S_SPI_ERR297                               ( BIT(12) )
#define BIT_SD1S_ADMA_ERR299                              ( BIT(9) )
#define BIT_SD1S_AUTO_CMD12_ERR300                        ( BIT(8) )
#define BIT_SD1S_CUR_LIMIT_ERR301                         ( BIT(7) )
#define BIT_SD1S_RD_DATA_END_BIT_ERR302                   ( BIT(6) )
#define BIT_SD1S_RD_DATA_CRC_ERR303                       ( BIT(5) )
#define BIT_SD1S_DATA_TIMEOUT_ERR304                      ( BIT(4) )
#define BIT_SD1S_CMD_INDEX_ERR308                         ( BIT(3) )
#define BIT_SD1S_CMD_END_BIT_ERR309                       ( BIT(2) )
#define BIT_SD1S_CMD_CRC_ERR310                           ( BIT(1) )
#define BIT_SD1S_CMD_TIMEOUT_ERR313                       ( BIT(0) )

/* bits definitions for register REG_SD3_SD_NORMAL_INT_STATUS_EN */
#define BIT_SD1S_RETUNE_INT_EN321                         ( BIT(12) )
#define BIT_SD1S_INT_C_INT_EN322                          ( BIT(11) )
#define BIT_SD1S_INT_B_INT_EN323                          ( BIT(10) )
#define BIT_SD1S_INT_A_INT_EN324                          ( BIT(9) )
#define BIT_SD1S_CARD_INT_EN325                           ( BIT(8) )
#define BIT_SD1S_CARD_REM_EN326                           ( BIT(7) )
#define BIT_SD1S_CARD_INS_EN327                           ( BIT(6) )
#define BIT_SD1S_RD_RDY_EN328                             ( BIT(5) )
#define BIT_SD1S_TX_RDY_EN329                             ( BIT(4) )
#define BIT_SD1S_DMA_INT_EN330                            ( BIT(3) )
#define BIT_SD1S_BLOCK_GAP_EVT_EN331                      ( BIT(2) )
#define BIT_SD1S_XFER_COMPLETE_EN332                      ( BIT(1) )
#define BIT_SD1S_CMD_COMPLETE_EN333                       ( BIT(0) )

/* bits definitions for register REG_SD3_SD_ERROR_INT_STATUS_EN */
#define BIT_SD1S_CRC_STATUS_ERR_EN340                     ( BIT(15) )
#define BIT_SD1S_CPL_TIMEOUT_ERR_EN341                    ( BIT(14) )
#define BIT_SD1S_AXI_RESP_ERR_EN342                       ( BIT(13) )
#define BIT_SD1S_SPI_ERR_EN343                            ( BIT(12) )
#define BIT_SD1S_TUNING_ERR_EN345                         ( BIT(10) )
#define BIT_SD1S_ADMA_ERR_EN346                           ( BIT(9) )
#define BIT_SD1S_AUTO_CMD12_ERR_EN347                     ( BIT(8) )
#define BIT_SD1S_CUR_LIM_ERR_EN348                        ( BIT(7) )
#define BIT_SD1S_RD_DATA_END_BIT_ERR_EN349                ( BIT(6) )
#define BIT_SD1S_RD_DATA_CRC_ERR_EN350                    ( BIT(5) )
#define BIT_SD1S_DATA_TIMEOUT_ERR_EN351                   ( BIT(4) )
#define BIT_SD1S_CMD_INDEX_ERR_EN352                      ( BIT(3) )
#define BIT_SD1S_CMD_END_BIT_ERR_EN353                    ( BIT(2) )
#define BIT_SD1S_CMD_CRC_ERR_EN354                        ( BIT(1) )
#define BIT_SD1S_CMD_TIMEOUT_ERR_EN355                    ( BIT(0) )

/* bits definitions for register REG_SD3_SD_NORMAL_INT_STATUS_INT_EN */
#define BIT_SD1S_RETUNE_INT_INT_EN363                     ( BIT(12) )
#define BIT_SD1S_INT_C_INT_INT_EN364                      ( BIT(11) )
#define BIT_SD1S_INT_B_INT_INT_EN365                      ( BIT(10) )
#define BIT_SD1S_INT_A_INT_INT_EN366                      ( BIT(9) )
#define BIT_SD1S_CARD_INT_INT_EN367                       ( BIT(8) )
#define BIT_SD1S_CARD_REM_INT_EN368                       ( BIT(7) )
#define BIT_SD1S_CARD_INS_INT_EN369                       ( BIT(6) )
#define BIT_SD1S_RX_RDY_INT_EN370                         ( BIT(5) )
#define BIT_SD1S_TX_RDY_INT_EN371                         ( BIT(4) )
#define BIT_SD1S_DMA_INT_INT_EN372                        ( BIT(3) )
#define BIT_SD1S_BLOCK_GAP_EVT_INT_EN373                  ( BIT(2) )
#define BIT_SD1S_XFER_COMPLETE_INT_EN374                  ( BIT(1) )
#define BIT_SD1S_CMD_COMPLETE_INT_EN375                   ( BIT(0) )

/* bits definitions for register REG_SD3_SD_ERROR_INT_STATUS_INT_EN */
#define BIT_SD1S_CRC_STATUS_ERR_INT_EN382                 ( BIT(15) )
#define BIT_SD1S_CPL_TIMEOUT_ERR_INT_EN383                ( BIT(14) )
#define BIT_SD1S_AXI_RESP_ERR_INT_EN384                   ( BIT(13) )
#define BIT_SD1S_SPI_ERR_INT_EN385                        ( BIT(12) )
#define BIT_SD1S_TUNE_ERR_INT_EN387                       ( BIT(10) )
#define BIT_SD1S_ADMA_ERR_INT_EN388                       ( BIT(9) )
#define BIT_SD1S_AUTO_CMD12_ERR_INT_EN389                 ( BIT(8) )
#define BIT_SD1S_CUR_LIM_ERR_INT_EN390                    ( BIT(7) )
#define BIT_SD1S_RD_DATA_END_BIT_ERR_INT_EN391            ( BIT(6) )
#define BIT_SD1S_RD_DATA_CRC_ERR_INT_EN392                ( BIT(5) )
#define BIT_SD1S_DATA_TIMEOUT_ERR_INT_EN393               ( BIT(4) )
#define BIT_SD1S_CMD_INDEX_ERR_INT_EN394                  ( BIT(3) )
#define BIT_SD1S_CMD_END_BIT_ERR_INT_EN395                ( BIT(2) )
#define BIT_SD1S_CMD_CRC_ERR_INT_EN396                    ( BIT(1) )
#define BIT_SD1S_CMD_TIMEOUT_ERR_INT_EN397                ( BIT(0) )

/* bits definitions for register REG_SD3_SD_AUTO_CMD12_ERROR_STATUS */
#define BIT_SD1S_CMD_NOT_ISSUED405                        ( BIT(7) )
#define BIT_SD1S_AUTO_CMD_INDEX_ERR407                    ( BIT(4) )
#define BIT_SD1S_AUTO_CMD_END_BIT_ERR408                  ( BIT(3) )
#define BIT_SD1S_AUTO_CMD_CRC_ERR409                      ( BIT(2) )
#define BIT_SD1S_AUTO_CMD_TIMEOUT_ERR410                  ( BIT(1) )
#define BIT_SD1S_AUTO_CMD12_NOT_EXE411                    ( BIT(0) )

/* bits definitions for register REG_SD3_HOST_CTRL_2 */
#define BIT_SD1S_PRE_VAL_EN418                            ( BIT(15) )
#define BIT_SD1S_ASYNC_INT_EN419                          ( BIT(14) )
#define BIT_SD1S_SAMPLING_CLK_SEL421                      ( BIT(7) )
#define BIT_SD1S_EXE_TUNING422                            ( BIT(6) )
#define BITS_SD1S_DRV_STRENGTH_SEL423(_X_)                ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BIT_SD1S_SDH_V18_EN424                            ( BIT(3) )
#define BITS_SD1S_UHS_MODE_SEL425(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_SD3_SD_CAPABILITIES_1 */
#define BITS_SD1S_BASE_FREQ432(_X_)                       ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_SD1S_TIMEOUT_UNIT433                          ( BIT(7) )
#define BITS_SD1S_TIMEOUT_FREQ435(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_SD3_SD_CAPABILITIES_2 */
#define BITS_SD1S_CFG_SLOT_TYPE442(_X_)                   ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_SD1S_ASYNC_INT_SUPPORT443                     ( BIT(13) )
#define BIT_SD1S_SYS_BUS_64_SUPPORT444                    ( BIT(12) )
#define BIT_SD1S_VLG_18_SUPPORT446                        ( BIT(10) )
#define BIT_SD1S_VLG_30_SUPPORT447                        ( BIT(9) )
#define BIT_SD1S_VLG_33_SUPPORT448                        ( BIT(8) )
#define BIT_SD1S_SUS_RES_SUPPORT449                       ( BIT(7) )
#define BIT_SD1S_SDMA_SUPPORT450                          ( BIT(6) )
#define BIT_SD1S_HI_SPEED_SUPPORT451                      ( BIT(5) )
#define BIT_SD1S_ADMA1_SUPPORT452                         ( BIT(4) )
#define BIT_SD1S_ADMA2_SUPPORT453                         ( BIT(3) )
#define BIT_SD1S_EX_DATA_WIDTH_SUPPORT454                 ( BIT(2) )
#define BITS_SD1S_MAX_BLK_LEN455(_X_)                     ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SD3_SD_CAPABILITIES_3 */
#define BITS_SD1S_RETUNE_MODES462(_X_)                    ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_SD1S_SDR50_TUNE463                            ( BIT(13) )
#define BITS_SD1S_TMR_RETUNE465(_X_)                      ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_SD1S_DRV_TYPE_D467                            ( BIT(6) )
#define BIT_SD1S_DRV_TYPE_C468                            ( BIT(5) )
#define BIT_SD1S_DRV_TYPE_A469                            ( BIT(4) )
#define BIT_SD1S_DDR50_SUPPORT471                         ( BIT(2) )
#define BIT_SD1S_SDR104_SUPPORT472                        ( BIT(1) )
#define BIT_SD1S_SDR50_SUPPORT473                         ( BIT(0) )

/* bits definitions for register REG_SD3_SD_CAPABILITIES_4 */
#define BITS_SD1S_<CLK_MULTIPLIER>481(_X_)                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SD3_SD_MAX_CURRENT_1 */
#define BITS_SD1S_MAX_CUR_30488(_X_)                      ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_SD1S_MAX_CUR_33489(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SD3_SD_MAX_CURRENT_2 */
#define BITS_SD1S_MAX_CUR_18497(_X_)                      ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SD3_SD_MAX_CURRENT_3 */

/* bits definitions for register REG_SD3_SD_MAX_CURRENT_4 */

/* bits definitions for register REG_SD3_SD_FORCE_EVENT_AUTO_CMD12_ERROR */
#define BIT_SD1S_F_ACMD12_ISSUE_ERR519                    ( BIT(7) )
#define BIT_SD1S_F_ACMD_INDEX_ERR521                      ( BIT(4) )
#define BIT_SD1S_F__ACMD_EBIT_ERR522                      ( BIT(3) )
#define BIT_SD1S_F_ACMD_CRC_ERR523                        ( BIT(2) )
#define BIT_SD1S_F_ACMD_TO_ERR524                         ( BIT(1) )
#define BIT_SD1S_F_ACMD12_NEXE_ERR525                     ( BIT(0) )

/* bits definitions for register REG_SD3_SD_FORCE_EVENT_FOR_ERROR_STATUS */
#define BIT_SD1S_F_CRC_STATUS_ERR532                      ( BIT(15) )
#define BIT_SD1S_F_CPL_TIMEOUT_ERR533                     ( BIT(14) )
#define BIT_SD1S_F_AXI_RESP_ERR534                        ( BIT(13) )
#define BIT_SD1S_F_SPI_ERR535                             ( BIT(12) )
#define BIT_SD1S_F_ADMA_ERR537                            ( BIT(9) )
#define BIT_SD1S_F_ACMD12_ERR538                          ( BIT(8) )
#define BIT_SD1S_F_CURRENT_ERR539                         ( BIT(7) )
#define BIT_SD1S_F_DAT_END_BIT_ERR540                     ( BIT(6) )
#define BIT_SD1S_F_DAT_CRC_ERR541                         ( BIT(5) )
#define BIT_SD1S_F_DAT_TO_ERR542                          ( BIT(4) )
#define BIT_SD1S_F_CMD_INDEX_ERR543                       ( BIT(3) )
#define BIT_SD1S_F_CMD_END_BIT_ERR544                     ( BIT(2) )
#define BIT_SD1S_F_CMD_CRC_ERR545                         ( BIT(1) )
#define BIT_SD1S_F_CMD_TO_ERR546                          ( BIT(0) )

/* bits definitions for register REG_SD3_SD_ADMA_ERROR_STATUS */
#define BIT_SD1S_ADMA_LEN_ERR554                          ( BIT(2) )
#define BITS_SD1S_ADMA_STATE557(_X_)                      ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SD3_SD_ADMA_SYS_ADDR_1 */
#define BITS_SD1S_ADMA_SYS_ADDR564(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_ADMA_SYS_ADDR_2 */
#define BITS_SD1S_ADMA_SYS_ADDR571(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_ADMA_SYS_ADDR_3 */
#define BITS_SD1S_ADMA_SYS_ADDR577(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_ADMA_SYS_ADDR_4 */
#define BITS_SD1S_ADMA_SYS_ADDR584(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_INIT */
#define BITS_SD1S_DRV_STRENGTH_VAL591(_X_)                ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_SD1S_CLKGEN_SEL_VAL593                        ( BIT(10) )
#define BITS_SD1S_SDCLK_FREQ_SEL_VAL594(_X_)              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_DS */
#define BITS_SD1S_DRV_STRENGTH_VAL601(_X_)                ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_SD1S_CLKGEN_SEL_VAL603                        ( BIT(10) )
#define BITS_SD1S_SDCLK_FREQ_SEL_VAL604(_X_)              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_HS */
#define BITS_SD1S_DRV_STRENGTH_VAL611(_X_)                ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_SD1S_CLKGEN_SEL_VAL613                        ( BIT(10) )
#define BITS_SD1S_SDCLK_FREQ_SEL_VAL614(_X_)              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_SDR12 */
#define BITS_SD1S_DRV_STRENGTH_VAL621(_X_)                ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_SD1S_CLKGEN_SEL_VAL623                        ( BIT(10) )
#define BITS_SD1S_SDCLK_FREQ_SEL_VAL624(_X_)              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_SDR25 */
#define BITS_SD1S_DRV_STRENGTH_VAL631(_X_)                ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_SD1S_CLKGEN_SEL_VAL633                        ( BIT(10) )
#define BITS_SD1S_SDCLK_FREQ_SEL_VAL634(_X_)              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_SDR50 */
#define BITS_SD1S_DRV_STRENGTH_VAL641(_X_)                ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_SD1S_CLKGEN_SEL_VAL643                        ( BIT(10) )
#define BITS_SD1S_SDCLK_FREQ_SEL_VAL644(_X_)              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_SDR104 */
#define BITS_SD1S_DRV_STRENGTH_VAL651(_X_)                ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_SD1S_CLKGEN_SEL_VAL653                        ( BIT(10) )
#define BITS_SD1S_SDCLK_FREQ_SEL_VAL654(_X_)              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_DDR50 */
#define BITS_SD1S_DRV_STRENGTH_VAL661(_X_)                ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_SD1S_CLKGEN_SEL_VAL663                        ( BIT(10) )
#define BITS_SD1S_SDCLK_FREQ_SEL_VAL664(_X_)              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_SHARED_BUS_CTRL */
#define BITS_SD1S_BEND_PWR_CTRL672(_X_)                   ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BITS_SD1S_INT_PIN_SEL674(_X_)                     ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BITS_SD1S_CLK_PIN_SEL676(_X_)                     ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BITS_SD1S_BUS_WIDTH_PRESET678(_X_)                ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_SD1S_NUM_INT_PINS680(_X_)                    ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_SD1S_NUM_CLK_PINS682(_X_)                    ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_SD3_SD_SLOT_INT_STATUS */
#define BIT_SD1S_SLOT_INT1690                             ( BIT(1) )
#define BIT_SD1S_SLOT_INT0691                             ( BIT(0) )

/* bits definitions for register REG_SD3_SD_HOST_CTRL_VER */
#define BITS_VENDOR_VER(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_SD1S_SD_VER699(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SD3_SD_CFG_FIFO_PARAM */
#define BITS_SD1S_GEN_PAD_CLK_CNT706(_X_)                 ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_SD1S_GEN_PAD_CLK_ON708                        ( BIT(6) )
#define BIT_SD1S_SQU_FULL_CHK709                          ( BIT(5) )
#define BIT_SD1S_SQU_EMPTY_CHK710                         ( BIT(4) )
#define BIT_SD1S_BOOT_ACK711                              ( BIT(3) )
#define BIT_SD1S_PIO_RDFC714                              ( BIT(0) )

/* bits definitions for register REG_SD3_SD_FIFO_PARAM */
#define BITS_SD1S_PRE_GATE_CLK_CNT722(_X_)                ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_SD1S_PDLVMC724                                ( BIT(14) )
#define BIT_SD1S_PDFVSSM725                               ( BIT(13) )
#define BIT_SD1S_FORCE_CLK_ON726                          ( BIT(12) )
#define BIT_SD1S_OVRRD_CLK_OEN727                         ( BIT(11) )
#define BIT_SD1S_CLK_GATE_ON729                           ( BIT(9) )
#define BIT_SD1S_CLK_GATE_CTL730                          ( BIT(8) )
#define BIT_SD1S_USE_DAT3732                              ( BIT(7) )
#define BIT_SD1S_PDWN733                                  ( BIT(6) )
#define BIT_SD1S_FIFO_CS734                               ( BIT(5) )
#define BIT_SD1S_FIFO_CLK735                              ( BIT(4) )
#define BITS_SD1S_WTC736(_X_)                             ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_SD1S_RTC737(_X_)                             ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SD3_SD_SPI_MODE */
#define BITS_SD1S_SPI_ERR_TOKEN745(_X_)                   ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_SD1S_SPI_EN747                                ( BIT(0) )

/* bits definitions for register REG_SD3_SD_CLOCK_AND_BURST_SIZE_SETUP */
#define BIT_SD1S_WR_OSTDG754                              ( BIT(15) )
#define BIT_SD1S_RD_OSTDG755                              ( BIT(14) )
#define BIT_SD1S_WR_ENDIAN757                             ( BIT(7) )
#define BIT_SD1S_RD_ENDIAN758                             ( BIT(6) )
#define BIT_SD1S_AXI_NON_POST_WR759                       ( BIT(5) )
#define BIT_SD1S_PRIORITY760                              ( BIT(4) )
#define BITS_SD1S_DMA_SIZE761(_X_)                        ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_SD1S_BRST_SIZE762(_X_)                       ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SD3_SD_CE_ATA_1 */
#define BITS_SD1S_CPL_TIMEOUT770(_X_)                     ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for register REG_SD3_SD_CE_ATA_2 */
#define BIT_SD1S_CHK_CPL777                               ( BIT(15) )
#define BIT_SD1S_SND_CPL778                               ( BIT(14) )
#define BIT_SD1S_CEATA_CARD779                            ( BIT(13) )
#define BIT_SD1S_MMC_CARD780                              ( BIT(12) )
#define BIT_SD1S_MMC_RESETN781                            ( BIT(11) )
#define BIT_SD1S_MMC_HS200782                             ( BIT(10) )
#define BIT_SD1S_CPL_COMPLETE784                          ( BIT(6) )
#define BIT_SD1S_CPL_COMPLETE_EN785                       ( BIT(5) )
#define BIT_SD1S_CPL_COMPLETE_INT_EN786                   ( BIT(4) )
#define BIT_SD1S_MISC_INT788                              ( BIT(2) )
#define BIT_SD1S_MISC_INT_EN789                           ( BIT(1) )
#define BIT_SD1S_MISC_INT_INT_EN790                       ( BIT(0) )

/* bits definitions for register REG_SD3_SD_PAD_IO_SETUP */
#define BITS_ECO_REG(_X_)                                 ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_SD1S_INAND_SEL800                             ( BIT(1) )
#define BIT_SD1S_ASYNC_IO_EN801                           ( BIT(0) )

/* bits definitions for register REG_SD3_RX_CFG_REG */
#define BITS_SD1S_TUNING_DLY_INC809(_X_)                  ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_SD1S_SDCLK_DELAY810(_X_)                     ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BITS_SD1S_SDCLK_SEL1812(_X_)                      ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_SD1S_SDCLK_SEL0813(_X_)                      ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SD3_TX_CFG_REG */
#define BIT_SD1S_TX_MUX_SEL820                            ( BIT(31) )
#define BIT_SD1S_TX_INT_CLK_SEL821                        ( BIT(30) )
#define BITS_SD1S_TX_HOLD_DELAY1823(_X_)                  ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BITS_SD1S_TX_HOLD_DELAY0825(_X_)                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_TUNING_CFG_REG */
#define BITS_SD1S_TUNING_SUCCESS_CNT833(_X_)              ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BITS_SD1S_TUNING_CLK_DLY834(_X_)                  ( (_X_) << 14 & (BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_SD1S_TUNING_WD_CNT835(_X_)                   ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BITS_SD1S_TUNING_TT_CNT836(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SD3_TUNING_CFG2_REG */
#define BITS_SD1S_TUNING_HW_START_CNT844(_X_)             ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BITS_SD1S_TUNING_HW_SDCLK_SEL0846(_X_)            ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SD3_TRS2RCV_TIMING_REG */
#define BITS_SD1S_WRDATA0_WAIT_CYCLES854(_X_)             ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_SD1S_CMD2RESP_WAIT_CYCLES856(_X_)            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_SD1S_TRS2RCV_PARAM_EN1858                     ( BIT(1) )
#define BIT_SD1S_TRS2RCV_PARAM_EN0859                     ( BIT(0) )

#endif
