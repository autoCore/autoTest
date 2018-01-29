width 18.

group 0x00000000++0x03
    line.long 0x00 "AIB_NAND_IO_REG,AIB NAND I/O Domain Control Register"
        bitfld.long 0x00 6.--7. " AIB_NAND_IO_DCS  ,controls the output driver pull up/down network driven strength by selecting proper number of nmos/pmos fingers to turned on" "0,1,10,11"

group 0x00000004++0x03
    line.long 0x00 "AIB_ANT_IO_REG,AIB ANT I/O Domain Control Register"
        bitfld.long 0x00 3. " SL28             ,this field is the io input schmitt trigger control.   0 = disable    1 = enable" "0,1"
        bitfld.long 0x00 2. "     V18EN29  ,1.8v enable to pad   0 = 3.0v   1 = 1.8v" "0,1"
        bitfld.long 0x00 0. "  SL31  ,this field control the io output slew rate." "0,1"

group 0x00000008++0x03
    line.long 0x00 "AIB_GPIO1_IO_REG,AIB GPIO 1 I/O Domain Control Register"
        bitfld.long 0x00 6.--7. " AIB_GPIO_IO_DCS  ,controls the output driver pull up/down network driven strength by selecting proper number of nmos/pmos fingers to turned on" "0,1,10,11"

group 0x0000000C++0x03
    line.long 0x00 "AIB_GPIO2_IO_REG,AIB GPIO 2 I/O Domain Control Register"
        bitfld.long 0x00 2. " V18EN47          ,1.8v enable to pad" "0,1"
        bitfld.long 0x00 0. "     PDB      ,vddiox_pbgen pad power down  0 = power down" "0,1"

group 0x00000014++0x03
    line.long 0x00 "AIB_GPIO4_IO_REG,AIB GPIO4 I/O Domain Control Register"
        bitfld.long 0x00 6.--7. " AIB_GPIO4_IO_DCS ,controls the output driver pull up/down network driven strength by selecting proper number of nmos/pmos fingers to turned on" "0,1,10,11"

group 0x00000018++0x03
    line.long 0x00 "AIB_MEM_IO_REG,AIB MEM I/O Domain Control Register"

group 0x0000001C++0x03
    line.long 0x00 "AIB_MMC1_IO_REG,AIB MMC 1 I/O Domain Control Register"
        bitfld.long 0x00 3. " SL72             ,this field is the io input schmitt trigger control.   0 = disable    1 = enable" "0,1"
        bitfld.long 0x00 2. "     V18EN73  ,1.8v enable to pad   0 = 3.0v   1 = 1.8v" "0,1"
        bitfld.long 0x00 0. "  SL75  ,this field control the io output slew rate." "0,1"

group 0x00000024++0x03
    line.long 0x00 "AIB_PMIC1_IO_REG,AIB PMIC 1 I/O Domain Control Register"
        bitfld.long 0x00 6.--7. " AIB_PMIC1_IO_DCS ,controls the output driver pull up/down network driven strength by selecting proper number of nmos/pmos fingers to turned on" "0,1,10,11"

group 0x00000028++0x03
    line.long 0x00 "AIB_PMIC2_IO_REG,AIB PMIC 2 I/O Domain Control Register"
        bitfld.long 0x00 6.--7. " AIB_PMIC2_IO_DCS ,controls the output driver pull up/down network driven strength by selecting proper number of nmos/pmos fingers to turned on" "0,1,10,11"

group 0x0000002C++0x03
    line.long 0x00 "AIB_USIM_IO_REG,AIB USIM I/O Domain Control Register"
        bitfld.long 0x00 3. " SL99             ,this field is the io input schmitt trigger control.   0 = disable    1 = enable" "0,1"
        bitfld.long 0x00 2. "     V18EN100 ,1.8v enable to pad   0 = 3.0v   1 = 1.8v" "0,1"
        bitfld.long 0x00 0. "  SL102 ,this field control the io output slew rate." "0,1"

group 0x00000030++0x03
    line.long 0x00 "AIB_GPIO3_IO_REG,AIB GPIO3 I/O Domain Control Register"
        bitfld.long 0x00 6.--7. " AIB_GPIO3_IO_DCS ,controls the output driver pull up/down network driven strength by selecting proper number of nmos/pmos fingers to turned on" "0,1,10,11"

group 0x00000400++0x03
    line.long 0x00 "AIB_AP_CFG_15_0,AIB AP config [15:0]"
        hexmask.long.word 0x00 0.--15. 1. " AIB_AP_CFG_15_0  ,aib ap_cfg override [15:0]"

group 0x00000404++0x03
    line.long 0x00 "AIB_AP_CFG_31_16,AIB AP config [31:16]"
        hexmask.long.word 0x00 0.--15. 1. " AIB_AP_CFG_31_16 ,aib ap_cfg override [31:16]"

group 0x00000408++0x03
    line.long 0x00 "AIB_AP_CFG_47_32,AIB AP config [47:32]"
        hexmask.long.word 0x00 0.--15. 1. " AIB_AP_CFG_47_32 ,aib ap_cfg override [47:32]"

group 0x0000040C++0x03
    line.long 0x00 "AIB_AP_CFG_63_48,AIB AP config [63:48]"
        hexmask.long.word 0x00 0.--15. 1. " AIB_AP_CFG_63_48 ,aib ap_cfg override [63:48]"

group 0x00000410++0x03
    line.long 0x00 "AIB_AP_CFG_79_64,AIB AP config [79:64]"
        hexmask.long.word 0x00 0.--15. 1. " AIB_AP_CFG_79_64 ,aib ap_cfg override [79:64]"

group 0x00000414++0x03
    line.long 0x00 "AIB_CP_CFG_15_0,AIB CP config [15:0]"
        hexmask.long.word 0x00 0.--15. 1. " AIB_CP_CFG_15_0  ,aib cp_cfg override [15:0]"

