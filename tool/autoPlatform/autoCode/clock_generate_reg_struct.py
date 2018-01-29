import os
import sys
import xlrd

from clock_parse_excel import parse_excel_clock_source
from clock_parse_excel import  parse_excel_clock_factor
from clock_parse_excel import parse_excel_clock_parent
from clock_parse_excel import curr_is_number_clk
from clock_parse_excel import get_clock_macro
debug = False

#sys.setdefaultencoding('utf8')

if (len(sys.argv) < 2):
    print "error: pls enter the correct command", + len(sys.argv)
    exit(-1)

fname_excel = str(sys.argv[1])
isExists = os.path.exists("./tmp")
if not isExists:
    os.mkdir("./tmp")

os.system('chmod +w tmp')

workbook = xlrd.open_workbook(fname_excel)
os.chdir(r"./tmp")

outputfile = open("./aquila_clock_reg.h", 'w+')
clock_array = []
comp_clock = ["NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"]
domain_flags = ""
for s in workbook.sheets():
    if s.name != "AP_CLOCK":
        continue

    nrow = s.nrows
    ncol = s.ncols - 2  #last line is note
    curr_row = 0
    clock_source_ready = 0
    clock_source_dict = {}
    is_found = 0
    parent_string = ""

    while curr_row < nrow:
        comp_clock = ["NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"]
        clock_max = 0;
        #prepare all of clock source.
        if ('clocks'  in str(s.cell_value(curr_row, 0))):
            clock_source_dict = parse_excel_clock_source(s.row_values(curr_row), ncol)
            curr_row += 1
            clock_source_ready = 1

        if (clock_source_ready == 0):
            curr_row += 1
            continue

        if ("XTL clock domain"  in str(s.cell_value(curr_row, 0))):
            domain_flags = "CLK_PLL_DOMAIN"
            print "/*XTL clock domain*/"
        elif ("PLL clock domain"  in str(s.cell_value(curr_row, 0))):
            domain_flags = "CLK_PLL_DOMAIN"
            print "/*PLL clock domain*/"
        elif ("AXI clock domain" in str(s.cell_value(curr_row, 0))):
            domain_flags = "CLK_AXI_DOMAIN"
            print "/*AXI clock domain*/"
        elif ("APB clock domain" in str(s.cell_value(curr_row, 0))):
            domain_flags = "CLK_APB_DOMAIN"
            print "/*apb clock domain*/"
        elif ("Fixed clock domain" in str(s.cell_value(curr_row, 0))):
            domain_flags = "CLK_PLL_DOMAIN"
            print "/*PLL clock domain*/"
        else:
            curr_col = 3
            is_factor = parse_excel_clock_factor(s.row_values(curr_row))

            #parse content of current row.
            while curr_col < ncol:
                tmp_string = str(s.cell_value(curr_row, curr_col))
                if len(tmp_string):
                    parent_string = parse_excel_clock_parent(s, curr_col).lower()
                    if ("CLK_PLL_DOMAIN" in domain_flags):
                        if "pll" in parent_string:
                            parent_string = parent_string.split('_')[0] + "vco"
                        else:
                            parent_string = "pll1_div4"

                    #print "parent = " + parent_string
                    clock_idx = s.cell_value(curr_row, curr_col)
                    clock_idx = int(clock_idx)

                    if (clock_idx > clock_max) :
                        clock_max = clock_idx

                    is_found = 1
                    if debug: print "===================================="
                    #print str(s.cell_value(curr_row, 2)).split(',')
                    src_reg = str(s.cell_value(curr_row, 2)).split('.')[1].split('=')[1][0:-1]
                    if debug: print "src_reg = " + src_reg

                    src_bit = str(s.cell_value(curr_row, 2)).split('.')[3].split('=')[1][0:-1].split(',')[0].strip()
                    if ('0' != src_bit):
                        src_bit = str(s.cell_value(curr_row, 2)).split('.')[3].split('=')[1][0:-1].split(',')[0].split('(')[1]
                        src_sel = " VALUE_(" + src_bit + ", 0x" + str(clock_idx) + "),"
                        #print "src_bit = " + src_bit
                    else:
                        src_sel = " " + src_bit + ","
                    if debug: print "src_sel = " + src_sel
                    src_mask = str(s.cell_value(curr_row, 2)).split('.')[3].split('=')[1][0:-1]
                    if debug: print "src_mask = " + src_mask

                    gate_reg = str(s.cell_value(curr_row, 2)).split('.')[4].split('=')[1][0:-1]
                    if debug: print "gate_reg = " + gate_reg
                    gate_val = str(s.cell_value(curr_row, 2)).split('.')[5].split('=')[1][0:-1]
                    if debug: print "gate_val = " + gate_val
                    gate_mask = str(s.cell_value(curr_row, 2)).split('.')[6].split('=')[1][0:-1]
                    if debug: print "gate_mask = " + gate_mask

                    fact_reg = str(s.cell_value(curr_row, 2)).split('.')[7].split('=')[1][0:-1]
                    if debug: print "fact_reg = " + fact_reg
                    mult = str(s.cell_value(curr_row, 2)).split('.')[8].split('=')[1][0:-1]
                    if debug: print "mult = " + mult
                    mult_mask = str(s.cell_value(curr_row, 2)).split('.')[9].split('=')[1][0:-1]
                    if debug: print "mult_mask = " + mult_mask
                    div = str(s.cell_value(curr_row, 2)).split('.')[10].split('=')[1][0:-1]
                    if debug: print "div = " + div
                    div_mask = str(s.cell_value(curr_row, 2)).split('.')[11].split('=')[1][0:-1]
                    if debug: print "div_mask = " + div_mask

                    fc_reg = str(s.cell_value(curr_row, 2)).split('.')[12].split('=')[1][0:-1]
                    if debug: print "fc_reg = " + fc_reg
                    fc_req = str(s.cell_value(curr_row, 2)).split('.')[13].split('=')[1][0:-1]
                    if debug: print "fc_req = " + fc_req

                    if debug: print "===================================="
                    #only parse clock of pll domain
                    if ("CLK_PLL_DOMAIN" in domain_flags and curr_is_number_clk(s, curr_row)):
                        flags_str = "CLK_IS_FIXED  |" + str(domain_flags)
                    else:
                        flags_str = "CLK_IS_NORMAL |" + str(domain_flags)

                    clk_freq = str(clock_source_dict[parse_excel_clock_parent(s, curr_col).lower()])
                    #print "freq = " + clk_freq + " str = " + parse_excel_clock_parent(s, curr_col).lower()
                    if (is_factor == True):
                        flags_str = flags_str[:15] +  " CLK_IS_FACTOR | " + flags_str[15:]

                    curr_name = str(s.cell_value(curr_row, 0).lower()).replace('.','_')
                    if ("CLK_PLL_DOMAIN" in domain_flags):
                        comp_clock[clock_idx] = "AQUILA_CLK_REG(\"" + curr_name + "\", " + src_reg + src_sel +  src_mask + gate_reg + gate_val + gate_mask + fact_reg + mult + mult_mask + div + div_mask + fc_reg + fc_req + "),"
                    else:
                        comp_clock[clock_idx] = "AQUILA_CLK_REG(\"" + curr_name + "_" + parent_string.replace('.', '_') + "\","  + src_reg + src_sel + src_mask + gate_reg + gate_val + gate_mask + fact_reg + mult + mult_mask + div + div_mask + fc_reg + fc_req  + "),"

                    #print str(comp_clock[clock_idx])
                curr_col += 1

            if (is_found == 1):
                if ("CLK_AXI_DOMAIN" in domain_flags):
                    print "#ifdef " + str(get_clock_macro(s.cell_value(curr_row, 0)))
                    outputfile.write("#ifdef " + str(get_clock_macro(s.cell_value(curr_row, 0))))
                    outputfile.write('\n')

                if ("CLK_APB_DOMAIN" in domain_flags):
                    print "#ifdef " + str(s.cell_value(curr_row, 0).upper()) + "_CLOCK"
                    outputfile.write("#ifdef " + str(s.cell_value(curr_row, 0).upper()) + "_CLOCK")
                    outputfile.write('\n')

                for i in range(0, clock_max + 1):
                    #print "i = " + str(i) + " max = " + str(clock_max)
                    print str(comp_clock[i])
                    outputfile.write(str(comp_clock[i]))
                    outputfile.write('\n')

                if ("CLK_AXI_DOMAIN" in domain_flags or "CLK_APB_DOMAIN" in domain_flags):
                    print "#endif"
                    outputfile.write("#endif")
                    outputfile.write('\n')
            else :
                flags_str = "CLK_IS_ROOT | " + str(domain_flags)
                if debug: print "===================================="
                #print str(s.cell_value(curr_row, 2)).split(',')
                src_reg = str(s.cell_value(curr_row, 2)).split('.')[1].split('=')[1][0:-1]
                if debug: print "src_reg = " + src_reg

                src_bit = str(s.cell_value(curr_row, 2)).split('.')[3].split('=')[1][0:-1].split(',')[0].strip()
                if ('0' != src_bit):
                    src_bit = str(s.cell_value(curr_row, 2)).split('.')[3].split('=')[1][0:-1].split(',')[0].split('(')[1]
                    src_sel = " VALUE_(" + src_bit + ", 0x" + str(clock_idx) + "),"
                    #print "src_bit = " + src_bit
                else:
                    src_sel = " " + src_bit + ","
                if debug: print "src_sel = " + src_sel
                src_mask = str(s.cell_value(curr_row, 2)).split('.')[3].split('=')[1][0:-1]
                if debug: print "src_mask = " + src_mask

                gate_reg = str(s.cell_value(curr_row, 2)).split('.')[4].split('=')[1][0:-1]
                if debug: print "gate_reg = " + gate_reg
                gate_val = str(s.cell_value(curr_row, 2)).split('.')[5].split('=')[1][0:-1]
                if debug: print "gate_val = " + gate_val
                gate_mask = str(s.cell_value(curr_row, 2)).split('.')[6].split('=')[1][0:-1]
                if debug: print "gate_mask = " + gate_mask

                fact_reg = str(s.cell_value(curr_row, 2)).split('.')[7].split('=')[1][0:-1]
                if debug: print "fact_reg = " + fact_reg
                mult = str(s.cell_value(curr_row, 2)).split('.')[8].split('=')[1][0:-1]
                if debug: print "mult = " + mult
                mult_mask = str(s.cell_value(curr_row, 2)).split('.')[9].split('=')[1][0:-1]
                if debug: print "mult_mask = " + mult_mask
                div = str(s.cell_value(curr_row, 2)).split('.')[10].split('=')[1][0:-1]
                if debug: print "div = " + div
                div_mask = str(s.cell_value(curr_row, 2)).split('.')[11].split('=')[1][0:-1]
                if debug: print "div_mask = " + div_mask

                fc_reg = str(s.cell_value(curr_row, 2)).split('.')[12].split('=')[1][0:-1]
                if debug: print "fc_reg = " + fc_reg
                fc_req = str(s.cell_value(curr_row, 2)).split('.')[13].split('=')[1][0:-1]
                if debug: print "fc_req = " + fc_req

                if debug: print "===================================="
                if (is_factor == True):
                    flags_str = flags_str[:14] +  " CLK_IS_FACTOR | " + flags_str[14:]
                try:
                    clk_freq = str(clock_source_dict[s.cell_value(curr_row, 0).lower()])
#                    print "name = " +  str(s.cell_value(curr_row, 0).lower()).replace('.','_')
                    comp_str = "AQUILA_CLK_REG(\"" + str(s.cell_value(curr_row, 0).lower()).replace('.','_')  + "\", " + src_reg + src_sel +  src_mask + gate_reg + gate_val + gate_mask + fact_reg + mult + mult_mask + div + div_mask + fc_reg + fc_req + "),"
                except KeyError:
                    clk_freq = "0"
                    comp_str = "AQUILA_CLK_REG(\"" + str(s.cell_value(curr_row, 0).lower()).replace('.','_')  + "\", " + src_reg + src_sel +  src_mask + gate_reg + gate_val + gate_mask + fact_reg + mult + mult_mask + div + div_mask + fc_reg + fc_req + "),"
                    is_found = 0

                print comp_str
                outputfile.write(comp_str)
                outputfile.write('\n')
        is_found = 0
        curr_row += 1

    #print clock_source_dict

