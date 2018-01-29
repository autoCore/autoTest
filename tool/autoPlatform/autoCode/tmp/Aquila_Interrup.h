#define INT_M1_RTC_HZCLK_INT_NDR                  5//rtc 1-Hz interrupt
#define INT_M1_RTC_SLP_ALARM_NDR                  6//rtc alarm interrupt
#define INT_M1_TIMER_1_IRQ                        7//AP Timer0 int1
#define INT_M1_TIMER_2_IRQ                        8//AP Timer0 int2
#define INT_M1_TIMER_3_IRQ                        9//AP Timer0 int3
#define INT_M1_TIMER1_1_IRQ                       10//AP Timer1 int1
#define INT_M1_TIMER1_2_IRQ                       11//AP Timer1 int2
#define INT_M1_TIMER1_3_IRQ                       12//AP Timer1 int3
#define INT_M1_NEW_TIMER_1_IRQ                    13//AP New Timer int1
#define INT_M1_NEW_TIMER_2_IRQ                    14//AP New Timer int1
#define INT_M1_NEW_TIMER_3_IRQ                    15//AP New Timer int3
#define INT_M1_NDR_TIMER_1_IRQ                    16//System PMU Timer int1
#define INT_M1_NDR_TIMER_2_IRQ                    17//System PMU Timer int2
#define INT_M1_NDR_TIMER_3_IRQ                    18//System PMU Timer int3
#define INT_M1_WDT_IRQ                            19//System PMU Timer Watchdog int
#define INT_M1_I2C0_INT                           20
#define INT_M1_I2C1_INT                           21
#define INT_M1_I2C2_INT                           22
#define INT_M1_I2C3_INT                           23
#define INT_M1_I2C4_INT                           24
#define INT_M1_I2C5_INT                           25
#define INT_M1_I2C6_INT                           26
#define INT_M1_I2C7_INT                           27
#define INT_M1_I2C8_INT                           28
#define INT_M1_IPC2PMU_946_WAKEUP                 29//ORed m1_ipc_946_926_int0/1/2/3
#define INT_M1_IPC_ADSP2AP_INT_COMB               30//ORed m1_ipc_adsp2ap_int0/1/2/3
#define INT_M1_RIPC0_INT0                         31//ORed ripc0/1/2/3_int0
#define INT_M1_FFUART1_INT                        32
#define INT_M1_FFUART2_INT                        33
#define INT_M1_UART_INT                           34
#define INT_M1_SSP_INT_REQ                        35
#define INT_M1_SSP2_INT_REQ                       36
#define INT_M1_GPIO_INT_AP                        37//Non-Sec
#define INT_M1_GPIO_INT_AP_SEC                    38
#define INT_M1_GPIO_EDGE_DET_WAKEUP               39//ORed all the pad_gpio_edge_det
#define INT_TSEN_INT                              40//Temperature Sensor
#define INT_M1_ONEWIRE_INT                        41
#define INT_M1_KP_INT                             42
#define INT_M1_PMIC_INT_EDGE_DETECTED             43//this interrupt comes from PAD
#define INT_M1_PM_XSC_WAKEUP_INT_MUX              44//m1_pm_xsc_wakeup_int | dvc_int
#define INT_M1_SEC_RTC_HZCLK_INT_NDR              45//secure rtc 1-Hz interrupt
#define INT_M1_SEC_RTC_SLP_ALARM_NDR              46//secure rtc alarm interrupt
#define INT_M1_AUXADC_INT                         47//AUXADC interrupt from Tsensor
#define INT_DMA_INT_AP_NON_SEC                    56//dma non-sec int to ap
#define INT_DMA_INT_AP_SEC                        57//dma sec int to ap
#define INT_VPU_IRQ                               58
#define INT_GPU_IRQGPU                            59
#define INT_GPU_IRQJOB                            60
#define INT_GPU_IRQEVENT                          61
#define INT_GPU_IRQMMU                            62
#define INT_ISP_IRQ                               63
#define INT_ISP_MMU_IRQ                           64
#define INT_IPE_IRQ                               65
#define INT_IPE2_IRQ                              66
#define INT_IPE3_IRQ                              67
#define INT_SC2_JPEG_IRQ                          68
#define INT_AFBC_DMA_IRQ                          69
#define INT_AFBC_IRQ                              70
#define INT_CEVAXM4_IRQ                           71
#define INT_CEVAXM4_AP_IRQ                        72
#define INT_CEVAXM4_MMU_IRQ                       73
#define INT_CEVAXM4_AFBC_IRQ                      74
#define INT_LCD_DE_IRQ                            75
#define INT_LCD_SE_IRQ                            76
#define INT_LCD_MMU_COMB_IRPT_S                   77//LCD MMU Secure
#define INT_LCD_MMU_COMB_IRPT_NS                  78//LCD MMU Non-Secure
#define INT_DSI_IRQ_A                             79
#define INT_DSI_IRQ_B                             80
#define INT_AUD_WAKEUP_SOC                        81
#define INT_TL421_GVI                             82
#define INT_MMC1_INT                              83
#define INT_MMC2_INT                              84
#define INT_MMC3_INT                              85
#define INT_SDH2ICU_WAKEUP_INT1                   86
#define INT_SDH2ICU_WAKEUP_INT2                   87
#define INT_SDH2ICU_WAKEUP_INT3                   88
#define INT_USB_INT                               89
#define INT_USB_VBUS_ID_WAKEUP                    90
#define INT_AEU_INT                               91//It's just GEU
#define INT_FABRIC0_TIMEOUT                       92
#define INT_DDR_ARM_INT                           93//CPU Cluster AXIERRORIRQ related
#define INT_WTM_HST_INT_OUT                       94
#define INT_WTM_SP_INT_OUT                        95
#define INT_PMU_IRQ2                              96//AP Freq Change int
#define INT_TZC400_INT                            97
