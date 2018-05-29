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
#define REG_SD1_SDHC_VID_PID                              ASR_ADDR(REGS_SD1_BASE, 0X100)/*SD HOST CTRL Vendor ID/Project ID/version ID Register*/
#define REG_SD2_SDHC_VID_PID                              ASR_ADDR(REGS_SD2_BASE, 0X100)/*SD HOST CTRL Vendor ID/Project ID/version ID Register*/
#define REG_SD3_SDHC_VID_PID                              ASR_ADDR(REGS_SD3_BASE, 0X100)/*SD HOST CTRL Vendor ID/Project ID/version ID Register*/
#define REG_SD1_SDHC_OP_CTRL                              ASR_ADDR(REGS_SD1_BASE, 0X104)/*SDHC Opeartion Control register
(Clock and Burst Size Setup Register)*/
#define REG_SD2_SDHC_OP_CTRL                              ASR_ADDR(REGS_SD2_BASE, 0X104)/*SDHC Opeartion Control register
(Clock and Burst Size Setup Register)*/
#define REG_SD3_SDHC_OP_CTRL                              ASR_ADDR(REGS_SD3_BASE, 0X104)/*SDHC Opeartion Control register
(Clock and Burst Size Setup Register)*/
#define REG_SD1_SDHC_OP_EXT_REG                           ASR_ADDR(REGS_SD1_BASE, 0X108)/*SDHC Operation extend CTRL Register*/
#define REG_SD2_SDHC_OP_EXT_REG                           ASR_ADDR(REGS_SD2_BASE, 0X108)/*SDHC Operation extend CTRL Register*/
#define REG_SD3_SDHC_OP_EXT_REG                           ASR_ADDR(REGS_SD3_BASE, 0X108)/*SDHC Operation extend CTRL Register*/
#define REG_SD1_SDHC_LEGACY_CTRL_REG                      ASR_ADDR(REGS_SD1_BASE, 0X10C)/*SDHC LEGACY CTRL Parameters Register*/
#define REG_SD2_SDHC_LEGACY_CTRL_REG                      ASR_ADDR(REGS_SD2_BASE, 0X10C)/*SDHC LEGACY CTRL Parameters Register*/
#define REG_SD3_SDHC_LEGACY_CTRL_REG                      ASR_ADDR(REGS_SD3_BASE, 0X10C)/*SDHC LEGACY CTRL Parameters Register*/
#define REG_SD1_SDHC_LEGACY_CEATA_REG                     ASR_ADDR(REGS_SD1_BASE, 0X110)/*SDHC LEGACY CTRL for CEATA Device Register*/
#define REG_SD2_SDHC_LEGACY_CEATA_REG                     ASR_ADDR(REGS_SD2_BASE, 0X110)/*SDHC LEGACY CTRL for CEATA Device Register*/
#define REG_SD3_SDHC_LEGACY_CEATA_REG                     ASR_ADDR(REGS_SD3_BASE, 0X110)/*SDHC LEGACY CTRL for CEATA Device Register*/
#define REG_SD1_SDHC_MMC_CTRL_REG                         ASR_ADDR(REGS_SD1_BASE, 0X114)/*SDHC MMC DEVICE CTRL Registers*/
#define REG_SD2_SDHC_MMC_CTRL_REG                         ASR_ADDR(REGS_SD2_BASE, 0X114)/*SDHC MMC DEVICE CTRL Registers*/
#define REG_SD3_SDHC_MMC_CTRL_REG                         ASR_ADDR(REGS_SD3_BASE, 0X114)/*SDHC MMC DEVICE CTRL Registers*/
#define REG_SD1_SDHC_RX_CFG_REG                           ASR_ADDR(REGS_SD1_BASE, 0X118)/*SDHC RX Configuration Register*/
#define REG_SD2_SDHC_RX_CFG_REG                           ASR_ADDR(REGS_SD2_BASE, 0X118)/*SDHC RX Configuration Register*/
#define REG_SD3_SDHC_RX_CFG_REG                           ASR_ADDR(REGS_SD3_BASE, 0X118)/*SDHC RX Configuration Register*/
#define REG_SD1_SDHC_TX_CFG_REG                           ASR_ADDR(REGS_SD1_BASE, 0X11C)/*SDHC TX Configuration Register*/
#define REG_SD2_SDHC_TX_CFG_REG                           ASR_ADDR(REGS_SD2_BASE, 0X11C)/*SDHC TX Configuration Register*/
#define REG_SD3_SDHC_TX_CFG_REG                           ASR_ADDR(REGS_SD3_BASE, 0X11C)/*SDHC TX Configuration Register*/
#define REG_SD1_SDHC_HWTUNE_CFG_REG                       ASR_ADDR(REGS_SD1_BASE, 0X120)/*SDHC HW TUNING Configuration Register*/
#define REG_SD2_SDHC_HWTUNE_CFG_REG                       ASR_ADDR(REGS_SD2_BASE, 0X120)/*SDHC HW TUNING Configuration Register*/
#define REG_SD3_SDHC_HWTUNE_CFG_REG                       ASR_ADDR(REGS_SD3_BASE, 0X120)/*SDHC HW TUNING Configuration Register*/
#define REG_SD1_SDHC_HWTUNE_CFG2_REG                      ASR_ADDR(REGS_SD1_BASE, 0X124)/*SDHC HW TUNING Configuration2 Register*/
#define REG_SD2_SDHC_HWTUNE_CFG2_REG                      ASR_ADDR(REGS_SD2_BASE, 0X124)/*SDHC HW TUNING Configuration2 Register*/
#define REG_SD3_SDHC_HWTUNE_CFG2_REG                      ASR_ADDR(REGS_SD3_BASE, 0X124)/*SDHC HW TUNING Configuration2 Register*/
#define REG_SD1_SDHC_ROUNDTRIP_TIMING_REG                 ASR_ADDR(REGS_SD1_BASE, 0X128)/*SDHC ROUND TRIP(TRANSIMIT TO RECEIVE) TIMING PARAM Regsiter*/
#define REG_SD2_SDHC_ROUNDTRIP_TIMING_REG                 ASR_ADDR(REGS_SD2_BASE, 0X128)/*SDHC ROUND TRIP(TRANSIMIT TO RECEIVE) TIMING PARAM Regsiter*/
#define REG_SD3_SDHC_ROUNDTRIP_TIMING_REG                 ASR_ADDR(REGS_SD3_BASE, 0X128)/*SDHC ROUND TRIP(TRANSIMIT TO RECEIVE) TIMING PARAM Regsiter*/
#define REG_SD1_SDHC_GPIO_CFG_REG                         ASR_ADDR(REGS_SD1_BASE, 0X12C)/*SDHC GPIO CFG Register*/
#define REG_SD2_SDHC_GPIO_CFG_REG                         ASR_ADDR(REGS_SD2_BASE, 0X12C)/*SDHC GPIO CFG Register*/
#define REG_SD3_SDHC_GPIO_CFG_REG                         ASR_ADDR(REGS_SD3_BASE, 0X12C)/*SDHC GPIO CFG Register*/
#define REG_SD1_SDHC_DLINE_CTRL_REG                       ASR_ADDR(REGS_SD1_BASE, 0X130)/*SDHC DELAYLINE Control Register*/
#define REG_SD2_SDHC_DLINE_CTRL_REG                       ASR_ADDR(REGS_SD2_BASE, 0X130)/*SDHC DELAYLINE Control Register*/
#define REG_SD3_SDHC_DLINE_CTRL_REG                       ASR_ADDR(REGS_SD3_BASE, 0X130)/*SDHC DELAYLINE Control Register*/
#define REG_SD1_SDHC_DLINE_CFG_REG                        ASR_ADDR(REGS_SD1_BASE, 0X134)/*SDHC DELAYLINE CFG Register*/
#define REG_SD2_SDHC_DLINE_CFG_REG                        ASR_ADDR(REGS_SD2_BASE, 0X134)/*SDHC DELAYLINE CFG Register*/
#define REG_SD3_SDHC_DLINE_CFG_REG                        ASR_ADDR(REGS_SD3_BASE, 0X134)/*SDHC DELAYLINE CFG Register*/
#define REG_SD1_SDHC_PHY_CTRL_REG                         ASR_ADDR(REGS_SD1_BASE, 0X160)/*SDHC PHY Control Register*/
#define REG_SD2_SDHC_PHY_CTRL_REG                         ASR_ADDR(REGS_SD2_BASE, 0X160)/*SDHC PHY Control Register*/
#define REG_SD3_SDHC_PHY_CTRL_REG                         ASR_ADDR(REGS_SD3_BASE, 0X160)/*SDHC PHY Control Register*/
#define REG_SD1_SDHC_PHY_FUNC_REG                         ASR_ADDR(REGS_SD1_BASE, 0X164)/*SDHC PHY Function Configuration Register*/
#define REG_SD2_SDHC_PHY_FUNC_REG                         ASR_ADDR(REGS_SD2_BASE, 0X164)/*SDHC PHY Function Configuration Register*/
#define REG_SD3_SDHC_PHY_FUNC_REG                         ASR_ADDR(REGS_SD3_BASE, 0X164)/*SDHC PHY Function Configuration Register*/
#define REG_SD1_SDHC_PHY_DLLCFG_REG                       ASR_ADDR(REGS_SD1_BASE, 0X0168)/*SDHC PHY DLL Configuration Register*/
#define REG_SD2_SDHC_PHY_DLLCFG_REG                       ASR_ADDR(REGS_SD2_BASE, 0X0168)/*SDHC PHY DLL Configuration Register*/
#define REG_SD3_SDHC_PHY_DLLCFG_REG                       ASR_ADDR(REGS_SD3_BASE, 0X0168)/*SDHC PHY DLL Configuration Register*/
#define REG_SD1_SDHC_PHY_DLLCFG1_REG                      ASR_ADDR(REGS_SD1_BASE, 0X016C)/*SDHC PHY DLL Configuration1 Register*/
#define REG_SD2_SDHC_PHY_DLLCFG1_REG                      ASR_ADDR(REGS_SD2_BASE, 0X016C)/*SDHC PHY DLL Configuration1 Register*/
#define REG_SD3_SDHC_PHY_DLLCFG1_REG                      ASR_ADDR(REGS_SD3_BASE, 0X016C)/*SDHC PHY DLL Configuration1 Register*/
#define REG_SD1_SDHC_PHY_DLLSTS_REG                       ASR_ADDR(REGS_SD1_BASE, 0X0170)/*SDHC PHY DLL Status & reserved configuration Register*/
#define REG_SD2_SDHC_PHY_DLLSTS_REG                       ASR_ADDR(REGS_SD2_BASE, 0X0170)/*SDHC PHY DLL Status & reserved configuration Register*/
#define REG_SD3_SDHC_PHY_DLLSTS_REG                       ASR_ADDR(REGS_SD3_BASE, 0X0170)/*SDHC PHY DLL Status & reserved configuration Register*/
#define REG_SD1_SDHC_PHY_DLLSTS1_REG                      ASR_ADDR(REGS_SD1_BASE, 0X0174)/*SDHC PHY DLL Status1 Register*/
#define REG_SD2_SDHC_PHY_DLLSTS1_REG                      ASR_ADDR(REGS_SD2_BASE, 0X0174)/*SDHC PHY DLL Status1 Register*/
#define REG_SD3_SDHC_PHY_DLLSTS1_REG                      ASR_ADDR(REGS_SD3_BASE, 0X0174)/*SDHC PHY DLL Status1 Register*/
#define REG_SD1_SDHC_PHY_PADCFG_REG                       ASR_ADDR(REGS_SD1_BASE, 0X0178)/*SDHC PHY Pad Configration Register*/
#define REG_SD2_SDHC_PHY_PADCFG_REG                       ASR_ADDR(REGS_SD2_BASE, 0X0178)/*SDHC PHY Pad Configration Register*/
#define REG_SD3_SDHC_PHY_PADCFG_REG                       ASR_ADDR(REGS_SD3_BASE, 0X0178)/*SDHC PHY Pad Configration Register*/
#define REG_SD1_SDHC_PHY_PADCFG1_REG                      ASR_ADDR(REGS_SD1_BASE, 0X017C)/*SDHC PHY Pad Configration1 Register*/
#define REG_SD2_SDHC_PHY_PADCFG1_REG                      ASR_ADDR(REGS_SD2_BASE, 0X017C)/*SDHC PHY Pad Configration1 Register*/
#define REG_SD3_SDHC_PHY_PADCFG1_REG                      ASR_ADDR(REGS_SD3_BASE, 0X017C)/*SDHC PHY Pad Configration1 Register*/
#define REG_SD1_SDHC_PHY_LBCTRL_REG                       ASR_ADDR(REGS_SD1_BASE, 0X0180)/*SDHC PHY LoopBack Control Register*/
#define REG_SD2_SDHC_PHY_LBCTRL_REG                       ASR_ADDR(REGS_SD2_BASE, 0X0180)/*SDHC PHY LoopBack Control Register*/
#define REG_SD3_SDHC_PHY_LBCTRL_REG                       ASR_ADDR(REGS_SD3_BASE, 0X0180)/*SDHC PHY LoopBack Control Register*/
#define REG_SD1_SDHC_PHY_LBFUNC_REG                       ASR_ADDR(REGS_SD1_BASE, 0X0184)/*SDHC PHY LoopBack Function Configuration Register*/
#define REG_SD2_SDHC_PHY_LBFUNC_REG                       ASR_ADDR(REGS_SD2_BASE, 0X0184)/*SDHC PHY LoopBack Function Configuration Register*/
#define REG_SD3_SDHC_PHY_LBFUNC_REG                       ASR_ADDR(REGS_SD3_BASE, 0X0184)/*SDHC PHY LoopBack Function Configuration Register*/
#define REG_SD1_SDHC_PHY_LBCNT_REG                        ASR_ADDR(REGS_SD1_BASE, 0X0188)/*SDHC PHY LoopBack Comparison Count
Register*/
#define REG_SD2_SDHC_PHY_LBCNT_REG                        ASR_ADDR(REGS_SD2_BASE, 0X0188)/*SDHC PHY LoopBack Comparison Count
Register*/
#define REG_SD3_SDHC_PHY_LBCNT_REG                        ASR_ADDR(REGS_SD3_BASE, 0X0188)/*SDHC PHY LoopBack Comparison Count
Register*/
#define REG_SD1_SDHC_PHY_LBSTS_REG                        ASR_ADDR(REGS_SD1_BASE, 0X018C)/*SDHC PHY LoopBack Error Status Register*/
#define REG_SD2_SDHC_PHY_LBSTS_REG                        ASR_ADDR(REGS_SD2_BASE, 0X018C)/*SDHC PHY LoopBack Error Status Register*/
#define REG_SD3_SDHC_PHY_LBSTS_REG                        ASR_ADDR(REGS_SD3_BASE, 0X018C)/*SDHC PHY LoopBack Error Status Register*/
#define REG_SD1_SDHC_PHY_LBDATA_REG                       ASR_ADDR(REGS_SD1_BASE, 0X0190)/*SDHC PHY LoopBack DATA Pattern Configuration Register*/
#define REG_SD2_SDHC_PHY_LBDATA_REG                       ASR_ADDR(REGS_SD2_BASE, 0X0190)/*SDHC PHY LoopBack DATA Pattern Configuration Register*/
#define REG_SD3_SDHC_PHY_LBDATA_REG                       ASR_ADDR(REGS_SD3_BASE, 0X0190)/*SDHC PHY LoopBack DATA Pattern Configuration Register*/
#define REG_SD1_SDHC_PHY_LBDATA_REG                       ASR_ADDR(REGS_SD1_BASE, 0X194)/*SDHC PHY LoopBack DATA Pattern Configuration Register*/
#define REG_SD2_SDHC_PHY_LBDATA_REG                       ASR_ADDR(REGS_SD2_BASE, 0X194)/*SDHC PHY LoopBack DATA Pattern Configuration Register*/
#define REG_SD3_SDHC_PHY_LBDATA_REG                       ASR_ADDR(REGS_SD3_BASE, 0X194)/*SDHC PHY LoopBack DATA Pattern Configuration Register*/
#define REG_SD1_CQE_CQBDCTRL_REG                          ASR_ADDR(REGS_SD1_BASE, 0X01F4)/*SDHC Command Queue Debug Information Content Registers*/
#define REG_SD2_CQE_CQBDCTRL_REG                          ASR_ADDR(REGS_SD2_BASE, 0X01F4)/*SDHC Command Queue Debug Information Content Registers*/
#define REG_SD3_CQE_CQBDCTRL_REG                          ASR_ADDR(REGS_SD3_BASE, 0X01F4)/*SDHC Command Queue Debug Information Content Registers*/



/* bits definitions for register REG_SD3_SD_SYS_ADDR_LOW */
#define BITS_DMA_ADDR_L(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_SYS_ADDR_HIGH */
#define BITS_DMA_ADDR_H(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_BLOCK_SIZE */
#define BITS_HOST_DMA_BDRY(_X_)                           ( (_X_) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BITS_SD1S_BLOCK_SIZE36(_X_)                       ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )

/* bits definitions for register REG_SD3_SD_BLOCK_COUNT */
#define BITS_BLOCK_COUNT(_X_)                             ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_ARG_LOW */
#define BITS_ARG_L(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_ARG_HIGH */
#define BITS_ARG_H(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_TRANSFER_MODE */
#define BIT_MULTI_BLK_SEL                                 ( BIT(5) )
#define BIT_TO_HOST_DIR                                   ( BIT(4) )
#define BITS_AUTO_CMD_EN(_X_)                             ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_BLK_CNT_EN                                    ( BIT(1) )
#define BIT_SD1S_DMA_EN69                                 ( BIT(0) )

/* bits definitions for register REG_SD3_SD_CMD */
#define BITS_CMD_INDEX(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BITS_SD1S_CMD_TYPE78(_X_)                         ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_DATA_PRESENT                                  ( BIT(5) )
#define BIT_CMD_INDEX_CHK_EN                              ( BIT(4) )
#define BIT_CMD_CRC_CHK_EN                                ( BIT(3) )
#define BITS_RESP_TYPE(_X_)                               ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SD3_SD_RESP_0 */
#define BITS_RESP0(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_RESP_1 */
#define BITS_RESP1(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_RESP_2 */
#define BITS_RESP2(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_RESP_3 */
#define BITS_RESP3(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_RESP_4 */
#define BITS_RESP4(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_RESP_5 */
#define BITS_RESP5(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_RESP_6 */
#define BITS_RESP6(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_RESP_7 */
#define BITS_RESP7(_X_)                                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_BUFFER_DATA_PORT_0 */
#define BITS_CPU_DATA0(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_BUFFER_DATA_PORT_1 */
#define BITS_CPU_DATA1(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_PRESENT_STATE_1 */
#define BIT_BUFFER_RD_EN                                  ( BIT(11) )
#define BIT_BUFFER_WR_EN                                  ( BIT(10) )
#define BIT_RX_ACTIVE                                     ( BIT(9) )
#define BIT_TX_ACTIVE                                     ( BIT(8) )
#define BIT_RETUNING_REQ                                  ( BIT(3) )
#define BIT__DAT_ACTIVE                                   ( BIT(2) )
#define BIT_CMD_INHIBIT_DAT                               ( BIT(1) )
#define BIT_CMD_INHIBIT_CMD                               ( BIT(0) )

/* bits definitions for register REG_SD3_SD_PRESENT_STATE_2 */
#define BIT_CMD_LEVEL                                     ( BIT(8) )
#define BITS_DAT_LEVEL190(_X_)                            ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_WRITE_PROT                                    ( BIT(3) )
#define BIT_CARD_DET                                      ( BIT(2) )
#define BIT_CARD_STABLE                                   ( BIT(1) )
#define BIT_CARD_INSERTED                                 ( BIT(0) )

/* bits definitions for register REG_SD3_SD_HOST_CTRL */
#define BITS_SD_BUS_VLT(_X_)                              ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_SD_BUS_POWER                                  ( BIT(8) )
#define BIT_CARD_DET_S                                    ( BIT(7) )
#define BIT_CARD_DET_L                                    ( BIT(6) )
#define BIT_EX_DATA_WIDTH                                 ( BIT(5) )
#define BITS_DMA_SEL(_X_)                                 ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BIT_HI_SPEED_EN                                   ( BIT(2) )
#define BIT_DATA_WIDTH                                    ( BIT(1) )
#define BIT_LED_CTRL                                      ( BIT(0) )

/* bits definitions for register REG_SD3_SD_BLOCK_GAP_CTRL */
#define BIT_W_REMOVAL                                     ( BIT(10) )
#define BIT_W_INSERTION                                   ( BIT(9) )
#define BIT_W_CARD_INT                                    ( BIT(8) )
#define BIT_INT_BLK_GAP                                   ( BIT(3) )
#define BIT_RD_WAIT_CTL                                   ( BIT(2) )
#define BIT_CONT_REQ                                      ( BIT(1) )
#define BIT_STOP_AT_BLOCK_GAP_REQ                         ( BIT(0) )

/* bits definitions for register REG_SD3_SD_CLOCK_CTRL */
#define BITS_SD_FREQ_SEL_LO(_X_)                          ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_SD_FREQ_SEL_HI(_X_)                          ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BIT_CLK_GEN_SEL                                   ( BIT(5) )
#define BIT_SD_CLK_EN                                     ( BIT(2) )
#define BIT_INT_CLK_STABLE                                ( BIT(1) )
#define BIT_INT_CLK_EN                                    ( BIT(0) )

/* bits definitions for register REG_SD3_SD_TIMEOUT_CTRL_SW_RESET */
#define BIT_SW_RST_DAT                                    ( BIT(10) )
#define BIT_SW_RST_CMD                                    ( BIT(9) )
#define BIT_SW_RST_ALL                                    ( BIT(8) )
#define BITS_TIMEOUT_VALUE(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_SD3_SD_NORMAL_INT_STATUS */
#define BIT_ERR_INT                                       ( BIT(15) )
#define BIT_CQ_INT                                        ( BIT(14) )
#define BIT_RETUNING_INT                                  ( BIT(12) )
#define BIT_INT_C                                         ( BIT(11) )
#define BIT_INT_B                                         ( BIT(10) )
#define BIT_INT_A                                         ( BIT(9) )
#define BIT_CARD_INT                                      ( BIT(8) )
#define BIT_CARD_REM_INT                                  ( BIT(7) )
#define BIT_CARD_INS_INT                                  ( BIT(6) )
#define BIT_RX_RDY                                        ( BIT(5) )
#define BIT_TX_RDY                                        ( BIT(4) )
#define BIT_DMA_INT                                       ( BIT(3) )
#define BIT_BLOCK_GAP_EVT                                 ( BIT(2) )
#define BIT_XFER_COMPLETE                                 ( BIT(1) )
#define BIT_CMD_COMPLETE                                  ( BIT(0) )

/* bits definitions for register REG_SD3_SD_ERROR_INT_STATUS */
#define BIT_CRC_STATUS_ERR                                ( BIT(15) )
#define BIT_CPL_TIMEOUT_ERR                               ( BIT(14) )
#define BIT_AXI_RESP_ERR                                  ( BIT(13) )
#define BIT_SPI_ERR                                       ( BIT(12) )
#define BIT_ADMA_ERR                                      ( BIT(9) )
#define BIT_AUTO_CMD12_ERR                                ( BIT(8) )
#define BIT_CUR_LIMIT_ERR                                 ( BIT(7) )
#define BIT_RD_DATA_END_BIT_ERR                           ( BIT(6) )
#define BIT_RD_DATA_CRC_ERR                               ( BIT(5) )
#define BIT_DATA_TIMEOUT_ERR                              ( BIT(4) )
#define BIT_CMD_INDEX_ERR                                 ( BIT(3) )
#define BIT_CMD_END_BIT_ERR                               ( BIT(2) )
#define BIT_CMD_CRC_ERR                                   ( BIT(1) )
#define BIT_CMD_TIMEOUT_ERR                               ( BIT(0) )

/* bits definitions for register REG_SD3_SD_NORMAL_INT_STATUS_EN */
#define BIT_CQ_STATUS_EN                                  ( BIT(14) )
#define BIT_RETUNE_INT_EN                                 ( BIT(12) )
#define BIT_INT_C_INT_EN                                  ( BIT(11) )
#define BIT_INT_B_INT_EN                                  ( BIT(10) )
#define BIT_INT_A_INT_EN                                  ( BIT(9) )
#define BIT_CARD_INT_EN                                   ( BIT(8) )
#define BIT_CARD_REM_EN                                   ( BIT(7) )
#define BIT_CARD_INS_EN                                   ( BIT(6) )
#define BIT_RD_RDY_EN                                     ( BIT(5) )
#define BIT_TX_RDY_EN                                     ( BIT(4) )
#define BIT_DMA_INT_EN                                    ( BIT(3) )
#define BIT_BLOCK_GAP_EVT_EN                              ( BIT(2) )
#define BIT_XFER_COMPLETE_EN                              ( BIT(1) )
#define BIT_CMD_COMPLETE_EN                               ( BIT(0) )

/* bits definitions for register REG_SD3_SD_ERROR_INT_STATUS_EN */
#define BIT_CRC_STATUS_ERR_EN                             ( BIT(15) )
#define BIT_CPL_TIMEOUT_ERR_EN                            ( BIT(14) )
#define BIT_AXI_RESP_ERR_EN                               ( BIT(13) )
#define BIT_SPI_ERR_EN                                    ( BIT(12) )
#define BIT_TUNING_ERR_EN                                 ( BIT(10) )
#define BIT_ADMA_ERR_EN                                   ( BIT(9) )
#define BIT_AUTO_CMD12_ERR_EN                             ( BIT(8) )
#define BIT_CUR_LIM_ERR_EN                                ( BIT(7) )
#define BIT_RD_DATA_END_BIT_ERR_EN                        ( BIT(6) )
#define BIT_RD_DATA_CRC_ERR_EN                            ( BIT(5) )
#define BIT_DATA_TIMEOUT_ERR_EN                           ( BIT(4) )
#define BIT_CMD_INDEX_ERR_EN                              ( BIT(3) )
#define BIT_CMD_END_BIT_ERR_EN                            ( BIT(2) )
#define BIT_CMD_CRC_ERR_EN                                ( BIT(1) )
#define BIT_CMD_TIMEOUT_ERR_EN                            ( BIT(0) )

/* bits definitions for register REG_SD3_SD_NORMAL_INT_STATUS_INT_EN */
#define BIT_CQ_SIGNAL_ENABLE                              ( BIT(14) )
#define BIT_RETUNE_INT_INT_EN                             ( BIT(12) )
#define BIT_INT_C_INT_INT_EN                              ( BIT(11) )
#define BIT_INT_B_INT_INT_EN                              ( BIT(10) )
#define BIT_INT_A_INT_INT_EN                              ( BIT(9) )
#define BIT_CARD_INT_INT_EN                               ( BIT(8) )
#define BIT_CARD_REM_INT_EN                               ( BIT(7) )
#define BIT_CARD_INS_INT_EN                               ( BIT(6) )
#define BIT_RX_RDY_INT_EN                                 ( BIT(5) )
#define BIT_TX_RDY_INT_EN                                 ( BIT(4) )
#define BIT_DMA_INT_INT_EN                                ( BIT(3) )
#define BIT_BLOCK_GAP_EVT_INT_EN                          ( BIT(2) )
#define BIT_XFER_COMPLETE_INT_EN                          ( BIT(1) )
#define BIT_CMD_COMPLETE_INT_EN                           ( BIT(0) )

/* bits definitions for register REG_SD3_SD_ERROR_INT_STATUS_INT_EN */
#define BIT_CRC_STATUS_ERR_INT_EN                         ( BIT(15) )
#define BIT_CPL_TIMEOUT_ERR_INT_EN                        ( BIT(14) )
#define BIT_AXI_RESP_ERR_INT_EN                           ( BIT(13) )
#define BIT_SPI_ERR_INT_EN                                ( BIT(12) )
#define BIT_TUNE_ERR_INT_EN                               ( BIT(10) )
#define BIT_ADMA_ERR_INT_EN                               ( BIT(9) )
#define BIT_AUTO_CMD12_ERR_INT_EN                         ( BIT(8) )
#define BIT_CUR_LIM_ERR_INT_EN                            ( BIT(7) )
#define BIT_RD_DATA_END_BIT_ERR_INT_EN                    ( BIT(6) )
#define BIT_RD_DATA_CRC_ERR_INT_EN                        ( BIT(5) )
#define BIT_DATA_TIMEOUT_ERR_INT_EN                       ( BIT(4) )
#define BIT_CMD_INDEX_ERR_INT_EN                          ( BIT(3) )
#define BIT_CMD_END_BIT_ERR_INT_EN                        ( BIT(2) )
#define BIT_CMD_CRC_ERR_INT_EN                            ( BIT(1) )
#define BIT_CMD_TIMEOUT_ERR_INT_EN                        ( BIT(0) )

/* bits definitions for register REG_SD3_SD_AUTO_CMD12_ERROR_STATUS */
#define BIT_CMD_NOT_ISSUED                                ( BIT(7) )
#define BIT_AUTO_CMD_INDEX_ERR                            ( BIT(4) )
#define BIT_AUTO_CMD_END_BIT_ERR                          ( BIT(3) )
#define BIT_AUTO_CMD_CRC_ERR                              ( BIT(2) )
#define BIT_AUTO_CMD_TIMEOUT_ERR                          ( BIT(1) )
#define BIT_AUTO_CMD12_NOT_EXE                            ( BIT(0) )

/* bits definitions for register REG_SD3_HOST_CTRL_2 */
#define BIT_PRE_VAL_EN                                    ( BIT(15) )
#define BIT_ASYNC_INT_EN                                  ( BIT(14) )
#define BIT_SAMPLING_CLK_SEL                              ( BIT(7) )
#define BIT_EXE_TUNING                                    ( BIT(6) )
#define BITS_DRV_STRENGTH_SEL(_X_)                        ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BIT_SDH_V18_EN                                    ( BIT(3) )
#define BITS_UHS_MODE_SEL(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_SD3_SD_CAPABILITIES_1 */
#define BITS_BASE_FREQ(_X_)                               ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_TIMEOUT_UNIT                                  ( BIT(7) )
#define BITS_TIMEOUT_FREQ(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for register REG_SD3_SD_CAPABILITIES_2 */
#define BITS_CFG_SLOT_TYPE(_X_)                           ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_ASYNC_INT_SUPPORT                             ( BIT(13) )
#define BIT_SYS_BUS_64_SUPPORT                            ( BIT(12) )
#define BIT_VLG_18_SUPPORT                                ( BIT(10) )
#define BIT_VLG_30_SUPPORT                                ( BIT(9) )
#define BIT_VLG_33_SUPPORT                                ( BIT(8) )
#define BIT_SUS_RES_SUPPORT                               ( BIT(7) )
#define BIT_SDMA_SUPPORT                                  ( BIT(6) )
#define BIT_HI_SPEED_SUPPORT                              ( BIT(5) )
#define BIT_ADMA1_SUPPORT                                 ( BIT(4) )
#define BIT_ADMA2_SUPPORT                                 ( BIT(3) )
#define BIT_EX_DATA_WIDTH_SUPPORT                         ( BIT(2) )
#define BITS_MAX_BLK_LEN(_X_)                             ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SD3_SD_CAPABILITIES_3 */
#define BITS_RETUNE_MODES(_X_)                            ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_SDR50_TUNE                                    ( BIT(13) )
#define BITS_TMR_RETUNE(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DRV_TYPE_D                                    ( BIT(6) )
#define BIT_DRV_TYPE_C                                    ( BIT(5) )
#define BIT_DRV_TYPE_A                                    ( BIT(4) )
#define BIT_DDR50_SUPPORT                                 ( BIT(2) )
#define BIT_SDR104_SUPPORT                                ( BIT(1) )
#define BIT_SDR50_SUPPORT                                 ( BIT(0) )

/* bits definitions for register REG_SD3_SD_CAPABILITIES_4 */
#define BITS_<CLK_MULTIPLIER>(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SD3_SD_MAX_CURRENT_1 */
#define BITS_MAX_CUR_30(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_MAX_CUR_33(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SD3_SD_MAX_CURRENT_2 */
#define BITS_MAX_CUR_18(_X_)                              ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SD3_SD_MAX_CURRENT_3 */

/* bits definitions for register REG_SD3_SD_MAX_CURRENT_4 */

/* bits definitions for register REG_SD3_SD_FORCE_EVENT_AUTO_CMD12_ERROR */
#define BIT_F_ACMD12_ISSUE_ERR                            ( BIT(7) )
#define BIT_F_ACMD_INDEX_ERR                              ( BIT(4) )
#define BIT_F__ACMD_EBIT_ERR                              ( BIT(3) )
#define BIT_F_ACMD_CRC_ERR                                ( BIT(2) )
#define BIT_F_ACMD_TO_ERR                                 ( BIT(1) )
#define BIT_F_ACMD12_NEXE_ERR                             ( BIT(0) )

/* bits definitions for register REG_SD3_SD_FORCE_EVENT_FOR_ERROR_STATUS */
#define BIT_F_CRC_STATUS_ERR                              ( BIT(15) )
#define BIT_F_CPL_TIMEOUT_ERR                             ( BIT(14) )
#define BIT_F_AXI_RESP_ERR                                ( BIT(13) )
#define BIT_F_SPI_ERR                                     ( BIT(12) )
#define BIT_F_ADMA_ERR                                    ( BIT(9) )
#define BIT_F_ACMD12_ERR                                  ( BIT(8) )
#define BIT_F_CURRENT_ERR                                 ( BIT(7) )
#define BIT_F_DAT_END_BIT_ERR                             ( BIT(6) )
#define BIT_F_DAT_CRC_ERR                                 ( BIT(5) )
#define BIT_F_DAT_TO_ERR                                  ( BIT(4) )
#define BIT_F_CMD_INDEX_ERR                               ( BIT(3) )
#define BIT_F_CMD_END_BIT_ERR                             ( BIT(2) )
#define BIT_F_CMD_CRC_ERR                                 ( BIT(1) )
#define BIT_F_CMD_TO_ERR                                  ( BIT(0) )

/* bits definitions for register REG_SD3_SD_ADMA_ERROR_STATUS */
#define BIT_ADMA_LEN_ERR                                  ( BIT(2) )
#define BITS_ADMA_STATE(_X_)                              ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SD3_SD_ADMA_SYS_ADDR_1 */
#define BITS_ADMA_SYS_ADDR568(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_ADMA_SYS_ADDR_2 */
#define BITS_ADMA_SYS_ADDR575(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_ADMA_SYS_ADDR_3 */
#define BITS_ADMA_SYS_ADDR581(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SD_ADMA_SYS_ADDR_4 */
#define BITS_ADMA_SYS_ADDR588(_X_)                        ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_INIT */
#define BITS_DRV_STRENGTH_VAL595(_X_)                     ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_CLKGEN_SEL_VAL597                             ( BIT(10) )
#define BITS_SDCLK_FREQ_SEL_VAL598(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_DS */
#define BITS_DRV_STRENGTH_VAL605(_X_)                     ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_CLKGEN_SEL_VAL607                             ( BIT(10) )
#define BITS_SDCLK_FREQ_SEL_VAL608(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_HS */
#define BITS_DRV_STRENGTH_VAL615(_X_)                     ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_CLKGEN_SEL_VAL617                             ( BIT(10) )
#define BITS_SDCLK_FREQ_SEL_VAL618(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_SDR12 */
#define BITS_DRV_STRENGTH_VAL625(_X_)                     ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_CLKGEN_SEL_VAL627                             ( BIT(10) )
#define BITS_SDCLK_FREQ_SEL_VAL628(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_SDR25 */
#define BITS_DRV_STRENGTH_VAL635(_X_)                     ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_CLKGEN_SEL_VAL637                             ( BIT(10) )
#define BITS_SDCLK_FREQ_SEL_VAL638(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_SDR50 */
#define BITS_DRV_STRENGTH_VAL645(_X_)                     ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_CLKGEN_SEL_VAL647                             ( BIT(10) )
#define BITS_SDCLK_FREQ_SEL_VAL648(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_SDR104 */
#define BITS_DRV_STRENGTH_VAL655(_X_)                     ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_CLKGEN_SEL_VAL657                             ( BIT(10) )
#define BITS_SDCLK_FREQ_SEL_VAL658(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_PRESET_VALUE_FOR_DDR50 */
#define BITS_DRV_STRENGTH_VAL665(_X_)                     ( (_X_) << 14 & (BIT(14)|BIT(15)) )
#define BIT_CLKGEN_SEL_VAL667                             ( BIT(10) )
#define BITS_SDCLK_FREQ_SEL_VAL668(_X_)                   ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_SHARED_BUS_CTRL */
#define BITS_BEND_PWR_CTRL(_X_)                           ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BITS_INT_PIN_SEL(_X_)                             ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BITS_CLK_PIN_SEL(_X_)                             ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BITS_BUS_WIDTH_PRESET(_X_)                        ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BITS_NUM_INT_PINS(_X_)                            ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_NUM_CLK_PINS(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_SD3_SD_SLOT_INT_STATUS */
#define BIT_SLOT_INT1                                     ( BIT(1) )
#define BIT_SLOT_INT0                                     ( BIT(0) )

/* bits definitions for register REG_SD3_SD_HOST_CTRL_VER */
#define BITS_SD_VER(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SD3_SDHC_VID_PID */
#define BITS_VERSION_ID(_X_)                              ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_PROJECT_ID(_X_)                              ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_VENDOR_ID(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for register REG_SD3_SDHC_OP_CTRL */
#define BIT_WR_OSTDG                                      ( BIT(15) )
#define BIT_RD_OSTDG                                      ( BIT(14) )
#define BIT_WR_ENDIAN                                     ( BIT(7) )
#define BIT_RD_ENDIAN                                     ( BIT(6) )
#define BIT_AXI_NON_POST_WR                               ( BIT(5) )
#define BIT_PRIORITY                                      ( BIT(4) )
#define BITS_DMA_SIZE(_X_)                                ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_BRST_SIZE(_X_)                               ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SD3_SDHC_OP_EXT_REG */
#define BITS_ARM_EMA(_X_)                                 ( (_X_) << 28 & (BIT(28)|BIT(29)|BIT(30)) )
#define BITS_ARM_EMAW(_X_)                                ( (_X_) << 26 & (BIT(26)|BIT(27)) )
#define BIT_ARM_EMAS                                      ( BIT(25) )
#define BIT_ARM_RET1N                                     ( BIT(24) )
#define BITS_PRE_GATE_CLK_CNT(_X_)                        ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PDLVMC                                        ( BIT(14) )
#define BIT_PDFVSSM                                       ( BIT(13) )
#define BIT_FORCE_CLK_ON                                  ( BIT(12) )
#define BIT_OVRRD_CLK_OEN                                 ( BIT(11) )
#define BIT_CLK_OE_USE_POS                                ( BIT(10) )
#define BIT_CLK_GATE_ON                                   ( BIT(9) )
#define BIT_CLK_GATE_CTL                                  ( BIT(8) )
#define BIT_USE_DAT3                                      ( BIT(7) )
#define BIT_SD1S_PDWN751                                  ( BIT(6) )
#define BIT_FIFO_CS                                       ( BIT(5) )
#define BIT_FIFO_CLK                                      ( BIT(4) )
#define BITS_SD1S_WTC754(_X_)                             ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_SD1S_RTC755(_X_)                             ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SD3_SDHC_LEGACY_CTRL_REG */
#define BITS_GEN_PAD_CLK_CNT(_X_)                         ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_SPI_ERR_TOKEN(_X_)                           ( (_X_) << 9 & (BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_SPI_EN                                        ( BIT(8) )
#define BIT_GEN_PAD_CLK_ON                                ( BIT(6) )
#define BIT_SQU_FULL_CHK                                  ( BIT(5) )
#define BIT_SQU_EMPTY_CHK                                 ( BIT(4) )
#define BIT_BOOT_ACK                                      ( BIT(3) )
#define BIT_INAND_SEL                                     ( BIT(2) )
#define BIT_ASYNC_IO_EN                                   ( BIT(1) )
#define BIT_PIO_RDFC                                      ( BIT(0) )

/* bits definitions for register REG_SD3_SDHC_LEGACY_CEATA_REG */
#define BITS_CPL_TIMEOUT(_X_)                             ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_CHK_CPL                                       ( BIT(2) )
#define BIT_SND_CPL                                       ( BIT(1) )
#define BIT_CEATA_CARD                                    ( BIT(0) )

/* bits definitions for register REG_SD3_SDHC_MMC_CTRL_REG */
#define BITS_DAT_LEVEL793(_X_)                            ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_MMC_CARD                                      ( BIT(12) )
#define BIT_MMC_RESETN                                    ( BIT(11) )
#define BIT_MMC_HS200                                     ( BIT(10) )
#define BIT_MMC_HS400                                     ( BIT(9) )
#define BIT_ENHANCE_STROBE_EN                             ( BIT(8) )
#define BIT_CPL_COMPLETE                                  ( BIT(6) )
#define BIT_CPL_COMPLETE_EN                               ( BIT(5) )
#define BIT_CPL_COMPLETE_INT_EN                           ( BIT(4) )
#define BIT_MISC_INT                                      ( BIT(2) )
#define BIT_MISC_INT_EN                                   ( BIT(1) )
#define BIT_MISC_INT_INT_EN                               ( BIT(0) )

/* bits definitions for register REG_SD3_SDHC_RX_CFG_REG */
#define BITS_TUNING_DLY_INC(_X_)                          ( (_X_) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_SDCLK_DELAY(_X_)                             ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BITS_SDCLK_SEL1(_X_)                              ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_SDCLK_SEL0(_X_)                              ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SD3_SDHC_TX_CFG_REG */
#define BIT_TX_MUX_SEL                                    ( BIT(31) )
#define BIT_TX_INT_CLK_SEL                                ( BIT(30) )
#define BIT_TX_DLINE_SRC_SEL                              ( BIT(29) )
#define BITS_TX_HOLD_DELAY1(_X_)                          ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BITS_TX_HOLD_DELAY0(_X_)                          ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_SDHC_HWTUNE_CFG_REG */
#define BITS_TUNING_CLK_DLY(_X_)                          ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BITS_TUNING_WD_CNT(_X_)                           ( (_X_) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_TUNING_TT_CNT(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for register REG_SD3_SDHC_HWTUNE_CFG2_REG */
#define BITS_TUNING_HW_START_CNT(_X_)                     ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BITS_TUNING_SUCCESS_CNT(_X_)                      ( (_X_) << 6 & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_TUNING_HW_SDCLK_SEL1(_X_)                    ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BITS_TUNING_HW_SDCLK_SEL0(_X_)                    ( (_X_) & (BIT(0)|BIT(1)) )

/* bits definitions for register REG_SD3_SDHC_ROUNDTRIP_TIMING_REG */
#define BITS_DATA0BUSY_WAIT_CYCLES(_X_)                   ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_WRDATA0_WAIT_CYCLES(_X_)                     ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BITS_CMD2RESP_WAIT_CYCLES(_X_)                    ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_TRS2RCV_PARAM_EN2                             ( BIT(2) )
#define BIT_TRS2RCV_PARAM_EN1                             ( BIT(1) )
#define BIT_TRS2RCV_PARAM_EN0                             ( BIT(0) )

/* bits definitions for register REG_SD3_SDHC_GPIO_CFG_REG */
#define BITS_SDHC_GPO(_X_)                                ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_SDHC_GPI(_X_)                                ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SDHC_DLINE_CTRL_REG */
#define BITS_TX_DLINE_CODE(_X_)                           ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_RX_DLINE_CODE(_X_)                           ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_DLINE_PU                                      ( BIT(0) )

/* bits definitions for register REG_SD3_SDHC_DLINE_CFG_REG */
#define BIT_TX_DLINE_GAIN                                 ( BIT(24) )
#define BITS_TX_DLINE_REG(_X_)                            ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_RX_DLINE_GAIN                                 ( BIT(8) )
#define BITS_RX_DLINE_REG(_X_)                            ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SD3_SDHC_PHY_CTRL_REG */
#define BIT_HOST_LEGACY_MODE                              ( BIT(31) )
#define BITS_PHY_DCHNL_STATUS(_X_)                        ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_PHY_DCHNL_SW(_X_)                            ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PHY_DCHNL_SEL                                 ( BIT(2) )
#define BIT_PHY_PLL_LOCK                                  ( BIT(1) )
#define BIT_PHY_FUNC_EN                                   ( BIT(0) )

/* bits definitions for register REG_SD3_SDHC_PHY_FUNC_REG */
#define BIT_RX_USE_STROBE                                 ( BIT(18) )
#define BIT_RX_USE_DLYLINE                                ( BIT(17) )
#define BIT_TX_USE_INVERT                                 ( BIT(16) )
#define BIT_HS200_USE_RFIFO                               ( BIT(15) )
#define BIT_RX_DIS_CKSTOP                                 ( BIT(14) )
#define BIT_PHY_TDI_SEL                                   ( BIT(13) )
#define BIT_TX_CKOUT_REVERSE                              ( BIT(12) )
#define BIT_TX_DDR_REVERSE                                ( BIT(11) )
#define BIT_RX_DDR_BKEN                                   ( BIT(10) )
#define BIT_RFIFO_BYPASS                                  ( BIT(9) )
#define BIT_CMD_USE_EVEN                                  ( BIT(8) )
#define BIT_PHY_TEST_EN                                   ( BIT(7) )
#define BITS_PHY_MODE_STATUS(_X_)                         ( (_X_) << 4 & (BIT(4)|BIT(5)|BIT(6)) )
#define BITS_PHY_MODE_SW(_X_)                             ( (_X_) << 1 & (BIT(1)|BIT(2)|BIT(3)) )
#define BIT_PHY_MODE_SWEN                                 ( BIT(0) )

/* bits definitions for register REG_SD3_SDHC_PHY_DLLCFG_REG */
#define BIT_DLL_ENABLE                                    ( BIT(31) )
#define BIT_DLL_DELAY_SRC                                 ( BIT(30) )
#define BIT_DLL_REFRESH_SW                                ( BIT(29) )
#define BIT_DLL_REFRESH_SWEN                              ( BIT(28) )
#define BIT_DLL_REFRESH_ENABLE                            ( BIT(27) )
#define BITS_DLL_STEP_CTRL(_X_)                           ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BITS_DLL_DELAY_CTRL(_X_)                          ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_DLL_VREG_CTRL(_X_)                           ( (_X_) << 6 & (BIT(6)|BIT(7)) )
#define BITS_DLL_FULLDLY_RANGE(_X_)                       ( (_X_) << 4 & (BIT(4)|BIT(5)) )
#define BITS_DLL_PREDLY_NUM(_X_)                          ( (_X_) << 2 & (BIT(2)|BIT(3)) )
#define BIT_DLL_BYPASS_ENABLE                             ( BIT(1) )
#define BIT_DLL_REFRESH_METHOD                            ( BIT(0) )

/* bits definitions for register REG_SD3_SDHC_PHY_DLLCFG1_REG */
#define BITS_DLL_REG3_CTRL(_X_)                           ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_DLL_REG2_CTRL(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SD3_SDHC_PHY_DLLSTS_REG */
#define BITS_PHY_WORK_MODE(_X_)                           ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_DLL_REFRESH_STATE                             ( BIT(1) )
#define BIT_DLL_LOCK_STATE                                ( BIT(0) )

/* bits definitions for register REG_SD3_SDHC_PHY_DLLSTS1_REG */
#define BITS_DLL_MASTER_DELAY(_X_)                        ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BITS_DLL_SLAVE_DELAY(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SD3_SDHC_PHY_PADCFG_REG */
#define BITS_CLK_PU(_X_)                                  ( (_X_) << 20 & (BIT(20)|BIT(21)) )
#define BITS_DS_PU(_X_)                                   ( (_X_) << 18 & (BIT(18)|BIT(19)) )
#define BITS_CMD_PU(_X_)                                  ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_CLK_PD(_X_)                                  ( (_X_) << 12 & (BIT(12)|BIT(13)) )
#define BITS_DS_PD(_X_)                                   ( (_X_) << 10 & (BIT(10)|BIT(11)) )
#define BITS_CMD_PD(_X_)                                  ( (_X_) << 8 & (BIT(8)|BIT(9)) )
#define BITS_SLEW_RATE(_X_)                               ( (_X_) << 3 & (BIT(3)|BIT(4)) )
#define BITS_DRIVE_SEL(_X_)                               ( (_X_) & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for register REG_SD3_SDHC_PHY_PADCFG1_REG */
#define BITS_DQX_PU(_X_)                                  ( (_X_) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BITS_DQX_PD(_X_)                                  ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SDHC_PHY_LBCTRL_REG */
#define BIT_CLEAR_LB_ERR_STATUS                           ( BIT(31) )
#define BIT_START_STUCK0_DET_CLK                          ( BIT(2) )
#define BIT_START_STUCK1_DET_CLK                          ( BIT(1) )
#define BIT_LB_TEST_TRIGGER                               ( BIT(0) )

/* bits definitions for register REG_SD3_SDHC_PHY_LBFUNC_REG */
#define BITS_LB_DS_CNT(_X_)                               ( (_X_) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BITS_LB_FILTER_CNT(_X_)                           ( (_X_) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_LB_CMD_MASK                                   ( BIT(16) )
#define BITS_LB_DQ_MASK(_X_)                              ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_LB_INVERT_CLK                                 ( BIT(3) )
#define BIT_CLK_PASSTH_DS                                 ( BIT(2) )
#define BIT_LB_PATTERN_SEL                                ( BIT(1) )
#define BIT_LB_MODE_EN                                    ( BIT(0) )

/* bits definitions for register REG_SD3_SDHC_PHY_LBCNT_REG */
#define BITS_LB_COMP_CNT(_X_)                             (_X_)

/* bits definitions for register REG_SD3_SDHC_PHY_LBSTS_REG */
#define BIT_LB_CLK_STUCK0_ERR                             ( BIT(21) )
#define BIT_LB_CLK_STUCK1_ERR                             ( BIT(20) )
#define BIT_LB_CMD_EVEN_ERR                               ( BIT(17) )
#define BIT_LB_CMD_ODD_ERR                                ( BIT(16) )
#define BITS_LB_DQ_EVEN_ERR(_X_)                          ( (_X_) << 8 & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BITS_LB_DQ_ODD_ERR(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for register REG_SD3_SDHC_PHY_LBDATA_REG */
#define BIT_LB_PATTERN_RST                                ( BIT(31) )
#define BIT_LB_PATTERN_WRITE                              ( BIT(30) )
#define BITS_LB_CMD_PATTERN(_X_)                          ( (_X_) << 16 & (BIT(16)|BIT(17)) )
#define BITS_LB_DATA_PATTERN(_X_)                         ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )

/* bits definitions for register REG_SD3_SDHC_PHY_LBDATA_REG */
#define BIT_CQE_FSM_RST                                   ( BIT(31) )
#define BITS_CQE_DEBUG_SEL(_X_)                           ( (_X_) & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for register REG_SD3_CQE_CQBDCTRL_REG */
#define BITS_CQE_DEBUG_INFO(_X_)                          (_X_)

#endif
