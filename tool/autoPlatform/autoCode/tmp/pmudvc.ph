width 15.

group 0x00002000++0x03
    line.long 0x00 "DVCR,Dynamic Voltage Change Control Register"
        bitfld.long 0x00 1. " VC_EN                         ,voltage change enable in active mode  1 = voltage change is allowed in active mode  0 = voltage change is not allowed" "0,1"
        bitfld.long 0x00 0. "     DV_LPM_AVC_EN16    ,automatic voltage change enable in low power mode  0 = automatic voltage change is disabled for every component  1 = automatic voltage change is enabled." "0,1"

group 0x00002020++0x03
    line.long 0x00 "DVC_AP,<var Processor: Application MP>  Dynamic Voltage Change Register"
        bitfld.long 0x00 28.--31. " C2_VL3:0                      ,cluster2 voltage level in active mode  required voltage level by <var processor: application mp> in m0/m1* mode  this voltage level can be dynamically changed due to a frequency change." "0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111"
        bitfld.long 0x00 24.--27. "  PERI_VL3:0         ,peripheral voltage level in d0 active mode" "0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111"
        bitfld.long 0x00 16.--19. "  C1_VL3:0             ,cluster1 voltage level in active mode  required voltage level by <var processor: application mp> in m0/m1* mode  this voltage level can be dynamically changed due to a frequency change." "0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111"
        bitfld.long 0x00 15. "  DV_VC_REQ27      ,voltage change request in active mode  voltage change request for <var processor: application mp> in m0/m1* power mode  software can write 1 to this bit to trigger a voltage change request. hardware will automaticly clear this bit when dvc is done. writes of 0 to this bit are ignored." "0,1"
        textline "                         "
        bitfld.long 0x00 8.--11. "C0_VL3:0                      ,cluster0 voltage level in active mode  required voltage level by <var processor: application mp> in m0/m1* mode  this voltage level can be dynamically changed due to a frequency change." "0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111"
        bitfld.long 0x00 7. "  C2_LPM_AVC_EN      ,cluster2 automatic voltage change enable in low power mode  this field is used for the <var processor: application mp>  0 = automatic voltage change is disabled  1 =  automatic voltage change is enabled  when <var processor: application mp> enters into m2* mode,  hardware automatically triggers a voltage change request." "0,1"
        bitfld.long 0x00 6. "     C1_LPM_AVC_EN        ,cluster1 automatic voltage change enable in low power mode  this field is used for the <var processor: application mp>  0 = automatic voltage change is disabled  1 =  automatic voltage change is enabled  when <var processor: application mp> enters into m2* mode,  hardware automatically triggers a voltage change request." "0,1"
        bitfld.long 0x00 5. "     C0_LPM_AVC_EN    ,cluster0 automatic voltage change enable in low power mode  this field is used for the <var processor: application mp>  0 = automatic voltage change is disabled  1 =  automatic voltage change is enabled  when <var processor: application mp> enters into m2* mode,  hardware automatically triggers a voltage change request." "0,1"
        textline "                         "
        bitfld.long 0x00 0.--3. "DV_LPM_VL3:034                ,required voltage level by <var processor: application mp> in m2* low power mode" "0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111"

group 0x0000202C++0x03
    line.long 0x00 "DVC_APSUB,AP Subsystem Dynamic Voltage Change Register"
        bitfld.long 0x00 31. " UDR_AP_SLP_AVC_EN             ,automatic voltage change enable in udr ap_sleep mode(ap_d2 mode)  0 =  automatic voltage change is disabled  1 = automatic voltage change is enabled  when the ap subsystem enters into udr ap_sleep mode,  hardware automatically triggers a voltage change." "0,1"
        bitfld.long 0x00 24.--27. "     UDR_AP_SLP_VL      ,required voltage level in udr ap_sleep mode" "0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111"
        bitfld.long 0x00 23. "  NUDR_AP_SLP_AVC_EN   ,automatic voltage change enable in non-udr ap_sleep mode(ap_d1 mode)  0 =  automatic voltage change is disabled  1 = automatic voltage change is enabled  when the ap subsystem enters into non-udr ap_sleep mode,  hardware automatically triggers a voltage change." "0,1"
        bitfld.long 0x00 16.--19. "     NUDR_AP_SLP_VL   ,required voltage level in non-udr ap_sleep mode" "0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111"
        textline "                         "
        bitfld.long 0x00 15. "AP_IDLE_DDROFF_AVC_EN         ,automatic voltage change enable in ap_idle_ddroff mode(ap_d1pp mode)  0 = automatic voltage change is disabled  1 = automatic voltage change is enabled  when the ap subsystem enters into ap_idle_ddroff mode,  hardware automatically triggers a voltage change request." "0,1"
        bitfld.long 0x00 8.--11. "     AP_IDLE_DDROFF_VL  ,required voltage level in ap_idle_ddroff mode( (ap_idle with ddr in self-refresh mode)" "0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111"
        bitfld.long 0x00 7. "  AP_IDLE_DDRON_AVC_EN ,automatic voltage change enable in ap_idle_ddron mode(ap_d1p mode)  0 = automatic voltage change is disabled  1 = automatic voltage change is enabled  when the ap subsystem enters into ap_idle_ddron mode,  hardware automatically triggers a voltage change request." "0,1"
        bitfld.long 0x00 0.--3. "     AP_IDLE_DDRON_VL ,required voltage level in ap_idle_ddron mode (ap_idle with ddr on mode)" "0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111"

group 0x00002030++0x03
    line.long 0x00 "DVC_CHIP,Chip Top Dynamic Voltage Change Register"
        bitfld.long 0x00 15. " UDR_SLP_AVC_EN                ,automatic voltage change enable in udr chip sleep mode(d2 mode) with vctcxo on  0 = automatic voltage change is disabled  1 = automatic voltage change is enabled  when udr chip sleep mode is entered,  hardware automatically triggers a voltage change request." "0,1"
        bitfld.long 0x00 8.--11. "     UDR_SLP_VL         ,required voltage level in udr chip sleep mode with vctcxo on" "0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111"
        bitfld.long 0x00 7. "  NUDR_SLP_AVC_EN      ,automatic voltage change enable in non-udr chip sleep mode(d1 mode) with vctcxo on  0 = automatic voltage change is disabled  1 = automatic voltage change is enabled  when non-udr chip sleep mode is entered,  hardware automatically triggers a voltage change request." "0,1"
        bitfld.long 0x00 0.--3. "     NUDR_SLP_VL      ,required voltage level in non-udr chip sleep mode with vctcxo on" "0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111"

group 0x00002040++0x03
    line.long 0x00 "DVC_STATUS,Dynamic Voltage Change Status Register"
        bitfld.long 0x00 24.--27. " DV_CAUSE73                    ,dvc cause  this field is the cause of the current ongoing dvc. it is only valid when the <dynamic voltage change status> field is 1.   0x1 = <var processor: application mp> software-triggered dvc   0x8 = hw-dfc triggered dvc <p>0x2=rsvd. <p>0x4=rsvd.   others = lpm entry/exit trigger dvc" "0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111"
        bitfld.long 0x00 16.--19. "  DV_TVL3:075        ,target voltage level of vcc_main" "0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111"
        bitfld.long 0x00 8.--11. "  DV_CVL3:077          ,current voltage level of vcc_main" "0,1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111"
        bitfld.long 0x00 0. "  DV_DVC_STATUS79  ,voltage change status  the voltage change may be triggered in active state or entering low power mode.  0 = there is no voltage change or a voltage change has finished  1 = voltage change is in progress" "0,1"

group 0x00002050++0x03
    line.long 0x00 "DVC_IMR, DVC Interrupt Mask Register"
        bitfld.long 0x00 0. " AP_VC_DONE_INTR_MASK          ,ap software triggered dvc done interrupt mask  1 = interrupt enabled  0 = interrupt disabled" "0,1"

group 0x00002054++0x03
    line.long 0x00 "DVC_ISR, DVC Interrupt Status Register"
        bitfld.long 0x00 0. " AP_VC_DONE_INTR_ISR           ,ap software triggered dvc done interrupt status   read 0 indicates no interrupt active. software write 0 to this bit to clear this interrupt  read 1 indicates interrupt is active. software write 1 has no effect to this bit's value" "0,1"

group 0x00002058++0x03
    line.long 0x00 "DVC_DEBUG, DVC Debug Register"
        bitfld.long 0x00 2. " TOP_REDUN_FUSE_LOAD_DONE_MASK ,top redundacy fuse load done check mask.   0x1=mask." "0,1"
        bitfld.long 0x00 1. "     CNT_DIS_FOR_VL_DWN ,enable/disable dvc stable timer counting when voltage change from high to low   0x0 = enabled   0x1 = disabled" "0,1"
        bitfld.long 0x00 0. "     M_DVC_CHECK_MASK     ,dvc check mask in main  state machine  0 = dvc status check is enabled  1 = dvc status check is masked" "0,1"

group 0x0000205C++0x03
    line.long 0x00 "DVC_EXTRA_STR,DVC Extra Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " DVC_EXTRA_STR                 ,extra stable time needed for dvc except voltage ramp up time in vctcxo cycles."

group 0x00002060++0x03
    line.long 0x00 "VL01STR,Voltage Level 0 to Level 1 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL56_ST121                    ,voltage level 0 to level 1 stable time  this field determines the wait time for a voltage change from level 0 to level 1 in vctcxo cycles."

group 0x00002064++0x03
    line.long 0x00 "VL12STR,Voltage Level 1 to Level 2 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL56_ST130                    ,voltage level 1 to level 2 stable time  this field determines the wait time for a voltage change from level 1 to level 2 in vctcxo cycles."

group 0x00002068++0x03
    line.long 0x00 "VL23STR,Voltage Level 2 to Level 3 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL56_ST138                    ,voltage level 2 to level 3 stable time  this field determines the wait time for a voltage change from level 2 to level 3 in vctcxo cycles."

group 0x0000206C++0x03
    line.long 0x00 "VL34STR,Voltage Level 3 to Level 4 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL56_ST147                    ,voltage level 3 to level 4 stable time  this field determines the wait time for a voltage change from level 3 to level 4 in vctcxo cycles."

group 0x00002070++0x03
    line.long 0x00 "VL45STR,Voltage Level 4 to Level  5 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL78_ST155                    ,voltage level 4 to level 5 stable time  this field determines the wait time for a voltage change from level 4 to level 5 in vctcxo cycles."

group 0x00002074++0x03
    line.long 0x00 "VL56STR,Voltage Level 5 to Level  6 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL78_ST163                    ,voltage level 5 to level 6 stable time  this field determines the wait time for a voltage change from level 5 to level 6 in vctcxo cycles."

group 0x00002078++0x03
    line.long 0x00 "VL67STR,Voltage Level 6 to Level  7 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL78_ST171                    ,voltage level 6 to level 7 stable time  this field determines the wait time for a voltage change from level 6 to level 7 in vctcxo cycles."

group 0x0000207C++0x03
    line.long 0x00 "VL78STR,Voltage Level 7 to Level  8 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL78_ST179                    ,voltage level 7 to level 8 stable time  this field determines the wait time for a voltage change from level 7 to level 8 in vctcxo cycles."

group 0x00002080++0x03
    line.long 0x00 "VL89STR,Voltage Level 8 to Level 9 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL89_ST                       ,voltage level 8 to level 9 stable time  this field determines the wait time for a voltage change from level 8 to level 9 in vctcxo cycles."

group 0x00002084++0x03
    line.long 0x00 "VL910STR,Voltage Level 9 to Level  10 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL910_ST                      ,voltage level 9 to level 10 stable time  this field determines the wait time for a voltage change from level 9 to level 10 in vctcxo cycles."

group 0x00002088++0x03
    line.long 0x00 "VL1011STR,Voltage Level 10 to Level 11 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL1011_ST                     ,voltage level 10 to level 11 stable time  this field determines the wait time for a voltage change from level 10 to level 11 in vctcxo cycles."

group 0x0000208C++0x03
    line.long 0x00 "VL1112STR,Voltage Level 11 to Level  12 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL1112_ST                     ,voltage level 11 to level 12 stable time  this field determines the wait time for a voltage change from level 11 to level 12 in vctcxo cycles."

group 0x00002090++0x03
    line.long 0x00 "VL1213STR,Voltage Level 12 to Level  13 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL1213_ST                     ,voltage level 12 to level 13 stable time  this field determines the wait time for a voltage change from level 12 to level 13 in vctcxo cycles."

group 0x00002094++0x03
    line.long 0x00 "VL1314STR,Voltage Level 13 to Level  14 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL1314_ST                     ,voltage level 13 to level 14 stable time  this field determines the wait time for a voltage change from level 13 to level 14 in vctcxo cycles."

group 0x00002098++0x03
    line.long 0x00 "VL1415STR,Voltage Level 14 to Level  15 Stable Time Register"
        hexmask.long.word 0x00 0.--15. 1. " VL1415_ST                     ,voltage level 14 to level 15 stable time  this field determines the wait time for a voltage change from level 14 to level 15 in vctcxo cycles."

