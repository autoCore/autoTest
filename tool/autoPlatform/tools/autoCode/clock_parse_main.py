import os
import sys
import xlrd

from clock_parse_excel import parse_excel_clock_source
from clock_parse_excel import  parse_excel_clock_factor
from clock_parse_excel import parse_excel_clock_parent
from clock_parse_excel import curr_is_number_clk
from clock_parse_excel import get_clock_macro
debug = True

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

outputfile = open("./aquila_clock_module.h", 'w+')

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
#            print "is_fact ======" + str(is_factor)

            #parse content of current row.
            while curr_col < ncol:
                tmp_string = str(s.cell_value(curr_row, curr_col))
                if len(tmp_string):
                    parent_string = parse_excel_clock_parent(s, curr_col).lower()

                    #print "parent = " + parent_string
                    clock_idx = s.cell_value(curr_row, curr_col)
                    clock_idx = int(clock_idx)

                    if (clock_idx > clock_max) :
                        clock_max = clock_idx

                    is_found = 1
                    #only parse clock of pll domain
                    if ("CLK_PLL_DOMAIN" in domain_flags and curr_is_number_clk(s, curr_row)):
                        flags_str = "CLK_IS_FIXED  |" + str(domain_flags)
                    else:
                        flags_str = "CLK_IS_NORMAL |" + str(domain_flags)

                    clk_freq = str(clock_source_dict[parse_excel_clock_parent(s, curr_col).lower()])
                    if ("CLK_PLL_DOMAIN" in domain_flags):
                        if (s.cell_value(curr_row, 0).find('_') != -1):
                            if ("pll" in s.cell_value(curr_row, 0)):
                                clk_freq = str(clock_source_dict[s.cell_value(curr_row, 0).lower()])
                            else:
                                clk_freq = str(clock_source_dict[s.cell_value(curr_row, 0).split('_')[1].lower()])
                        else:
                            try:
                                clk_freq = str(clock_source_dict[s.cell_value(curr_row, 0).lower()])
                            except KeyError:
                                print "---------------------------------------------------"
                                print clock_source_dict
                                print clock_source_dict[s.cell_value(curr_row, 0).lower()]
                                print s.cell_value(curr_row, 0).lower()
                                print "---------------------------------------------------"

                    #print "freq = " + clk_freq + " str = " + parse_excel_clock_parent(s, curr_col).lower()
                    if (is_factor == True):
                        flags_str = flags_str[:15] +  " CLK_IS_FACTOR | " + flags_str[15:]

                    if ("CLK_PLL_DOMAIN" in domain_flags):
                        comp_clock[clock_idx] = "AQUILA_CLK(\"" + str(s.cell_value(curr_row, 0).lower()).replace('.','_') + "\", \"" + str(parent_string).replace('.', '_') + "\", " + flags_str + ", "  + clk_freq + "),"
                    else:
                        comp_clock[clock_idx] = "AQUILA_CLK(\"" + str(s.cell_value(curr_row, 0).lower()).replace('.','_') + "_" + parent_string.replace('.', '_') + "\", \"" + str(parent_string).replace('.', '_') + "\", " + flags_str + ", "  + clk_freq + "),"

                    #print str(comp_clock)
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
                    if comp_clock[i] != "NULL":
                        print str(comp_clock[i])
                        outputfile.write(comp_clock[i])
                        outputfile.write('\n')

                if ("CLK_AXI_DOMAIN" in domain_flags or "CLK_APB_DOMAIN" in domain_flags):
                    print "#endif"
                    outputfile.write("#endif")
                    outputfile.write('\n')
            else :
                if ("CLK_APB_DOMAIN" in domain_flags):
                    print "#ifdef " + str(get_clock_macro(s.cell_value(curr_row, 0)))
                    outputfile.write("#ifdef " + str(s.cell_value(curr_row, 0).upper()) + "_CLOCK")
                    outputfile.write('\n')

                flags_str = "CLK_IS_ROOT | " + str(domain_flags)
                if (is_factor == True):
                    flags_str = flags_str[:14] +  " CLK_IS_FACTOR | " + flags_str[14:]
                try:
                    clk_freq = str(clock_source_dict[s.cell_value(curr_row, 0).lower()])
#                    print "name = " +  str(s.cell_value(curr_row, 0).lower()).replace('.','_')
                    comp_str = "AQUILA_CLK(\"" + str(s.cell_value(curr_row, 0).lower()).replace('.','_')  + "\", \"" + "NULL" + "\", " + flags_str+ ", "  + clk_freq + "),"
                except KeyError:
                    clk_freq = "0"
                    comp_str = "AQUILA_CLK(\"" + str(s.cell_value(curr_row, 0).lower()).replace('.','_')  + "\", \"" + "NULL" + "\", " + flags_str+ ", "  + clk_freq + "),"
                    is_found = 0

                print comp_str
                outputfile.write(comp_str)
                outputfile.write('\n')

                if ("CLK_AXI_DOMAIN" in domain_flags or "CLK_APB_DOMAIN" in domain_flags):
                    print "#endif"
                    outputfile.write("#endif")
                    outputfile.write('\n')
        is_found = 0
        curr_row += 1

    #print clock_source_dict

