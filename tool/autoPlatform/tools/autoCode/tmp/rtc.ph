width 9.

group 0x00000000++0x03
    line.long 0x00 "RTC_CNR,RTC Counter Register"
        hexmask.long 0x00 0.--31. 1. " TC          ,time count"

group 0x00000004++0x03
    line.long 0x00 "RTC_AR,RTC Alarm Register"
        hexmask.long 0x00 0.--31. 1. " AT          ,alarm time"

group 0x00000008++0x03
    line.long 0x00 "RTC_SR,RTC Status Register"
        bitfld.long 0x00 3. " HZE         ,1-hz interrupt enable  0 = the 1-hz interrupt is not enabled  1 = the 1-hz interrupt is enabled" "0,1"
        bitfld.long 0x00 2. "         ALE   ,rtc alarm interrupt enable  0 = the rtc alarm interrupt is not enabled  1 = the rtc alarm interrupt is enabled  this interrupt must be cleared just prior to enabling it since it remembers past events (matches) even when not enabled." "0,1"
        bitfld.long 0x00 1. "     HZ      ,1-hz rising-edge detected  0 = no rising edge has been detected  1 = a rising edge has been detected and the <1-hz interrupt enable> field is set  writing 1 to this field clears the 1-hz level interrupt (rtc_hzclk and rtc_hzclk_int)." "0,1"
        bitfld.long 0x00 0. "     AL ,rtc alarm detected  0 = no alarm has been detected  1 = an alarm has been detected (rtc counter register matches rtc alarm register) and the <rtc alarm interrupt enable> field is set  writing 1s to this field clears the alarm level interrupt (rtc_slp_alarm)." "0,1"

group 0x0000000C++0x03
    line.long 0x00 "RTC_TR,RTC Trim Register"
        bitfld.long 0x00 31. " LCK         ,locking bit for the trim value" "0,1"
        hexmask.long.word 0x00 16.--25. 1. "         D9_D0 ,trim delete count  this value represents the number of 32 khz clocks to delete when clock trimming begins."
        hexmask.long.word 0x00 0.--15. 1. "  C150_C0 ,clock divider count  this value is the integer portion of the clock trim logic."

group 0x00000010++0x03
    line.long 0x00 "RTC_PR,RTC Control Register"
        bitfld.long 0x00 0. " SW_ALARM    ,controls the alarm signal  0 = is off (alarm negated)  1 = is on (alarm asserted)" "0,1"

group 0x00000014++0x03
    line.long 0x00 "RTC_BRn,RTC Backup Registers"
        hexmask.long 0x00 0.--31. 1. " RTCS_DATA77 ,backup data"

