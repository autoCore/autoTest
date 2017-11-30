
def get_clock_macro(s):
    if s.lower().find("artemis") != -1:
        return "CORE_CLOCK"
    elif s.lower().find("ca53") != -1:
        return "CORE_CLOCK"
    elif s.lower().find("cci_clk") != -1:
        return "CCI_CLOCK"
    elif s.lower().find("ddr1x") != -1:
        return "DDR_CLOCK"
    elif s.lower().find("dp650 aclk") != -1:
        return  "LCD_ACLK"
    elif s.lower().find("isp aclk") != -1:
        return  "ISP_ACLK"
    elif s.lower().find("aclk") != -1:
        return "AXI_CLOCK"
    elif s.lower().find("dbgclk") != -1:
        return "DBG_CLOCK"
    elif s.lower().find("traceclk") != -1:
        return "TRACE_CLOCK"
    elif s.lower().find("gpu") != -1:
        return "GPU_CLOCK"
    elif s.lower().find("vpu") != -1:
        return "VPU_CLOCK"
    elif s.lower().find("isp wbclk") != -1:
        return  "ISP_WBCLK"
    elif s.lower().find("isp fclk") != -1:
        return  "ISP_FCLK"
    elif s.lower().find("jpeg") != -1:
        return  "JPEG_CLOCK"
    elif s.lower().find("vsp") != -1:
        return  "VSP_CLOCK"
    elif s.lower().find("ciclk(ccic)") != -1:
        return  "CCIC_CLOCK"
    elif s.lower().find("_phy_clk") != -1:
        return  "CSI_PHY_CLOCK"
    elif s.lower().find("csi clk") != -1:
        return  "CSI_CLOCK"
    elif s.lower().find("mclk(dp650)") != -1:
        return  "LCD_MCLK"
    elif s.lower().find("pxclk(dp650)") != -1:
        return  "LCD_PXCLK"
    elif s.lower().find("dsi bit clk") != -1:
        return  "LCD_BITCLK"
    elif s.lower().find("esc clk") != -1:
        return  "LCD_ESCCLK"
    elif s.lower().find("audio clk") != -1:
        return  "AUDIO_CLOCK"
    elif s.lower().find("audio_apb") != -1:
        return  "AUDIO_APB_CLOCK"
    elif s.lower().find("audio_axi") != -1:
        return  "AUDIO_AXI_CLOCK"
    elif s.lower().find("audio ssp") != -1:
        return  "AUDIO_SSP_CLOCK"
    elif s.lower().find("sd0 clk") != -1:
        return  "SD0_CLOCK"
    elif s.lower().find("sd1 clk") != -1:
        return  "SD1_CLOCK"
    elif s.lower().find("sd2 clk") != -1:
        return  "SD2_CLOCK"
    elif s.lower().find("cam0_mclk") != -1:
        return  "CAM0_MCLK"
    elif s.lower().find("cam1_mclk") != -1:
        return  "CAM1_MCLK"
    elif s.lower().find("cam2_mclk") != -1:
        return  "CAM2_MCLK"
    elif s.lower().find("2kafbc_fncclk") != -1:
        return  "2KAFBC_FNCCLK"
    elif s.lower().find("sc2_ahbclk") != -1:
        return  "SC2_AHBCLK"
    elif s.lower().find("gpio_clock") != -1:
        return  "GPIO_CLOCK"
    elif s.lower().find("ipc_clock") != -1:
        return  "IPC_CLOCK"
    elif s.lower().find("aib_clock") != -1:
        return  "AIB_CLOCK"
    elif s.lower().find("sw_jtag_clock") != -1:
        return  "SW_JTAG_CLOCK"
    elif s.lower().find("onewire_clock") != -1:
        return  "ONEWIRE_CLOCK"
    elif s.lower().find("tsen_clock") != -1:
        return  "TSEN_CLOCK"
    else:
        return

def get_clock_freq(s):
    if s.lower().find('m') != -1:
        return int(float(s.lower().split('m')[0]) * 1000000)
    elif s.lower().find('k') != -1:
        return int(float(s.lower().split('k')[0]) * 1000)
    else:
        return
        #print str(s)
        #return int(float(s[0]))

def parse_excel_clock_source(s, ncol):

    curr_col = 3
    tmp_dict = {}
    while curr_col < ncol:
        #print s[curr_col]
        clock_source = s[curr_col].lower().split('(')

        if len(clock_source) == 1:
            clock_source = s[curr_col].lower().split('_')
            if len(clock_source) == 1:
                clock_freq = get_clock_freq(clock_source[0])
            else:
                clock_freq = get_clock_freq(clock_source[1])
        else:
            clock_freq = get_clock_freq(clock_source[1].split(')')[0])

        tmp_dict.setdefault(clock_source[0], clock_freq)
        #print str(clock_source[0]) + " " + str(clock_freq)

        curr_col += 1

#    print tmp_dict
    return tmp_dict

def parse_excel_clock_factor(s):
    if s[2].find("fact_reg:,") != -1:
        return False
    else:
        return True

def parse_excel_clock_parent(s, ncol):
    return s.cell_value(2, ncol).split('(')[0]

def curr_is_number_clk(s, nrow):
    sub_str = s.cell_value(nrow, 0).lower()

    if (sub_str.find('m') != -1 or sub_str.find('k') != -1):
        if (sub_str.find('_') != -1):
            sub_str = sub_str.split('_')[1]
            #print "find abnomal string, sub_str = " + sub_str + " raw = " + s.cell_value(nrow, 0).lower()

    if sub_str.find('m') != -1:
        tmp_str = sub_str.split('m')[0]
    elif sub_str.find('k') != -1:
        tmp_str = sub_str.split('k')[0]
    else:
        tmp_str = sub_str[0]

    try:
        float(tmp_str)
        return True
    except ValueError:
        return False
