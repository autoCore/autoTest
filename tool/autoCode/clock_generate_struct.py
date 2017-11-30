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

filename = str(sys.argv[1])
isExists = os.path.exists("./tmp")
if not isExists:
    os.mkdir("./tmp")

os.system('chmod +w tmp')

workbook = open(filename)
os.chdir(r"./tmp")

print "begin to parse"
while True:
    line = workbook.readline()
    if line:
        pass    # do something here
        elem_idx = 0
        line=line.strip()
        if "AQUILA_CLK_REG" in line:
            #print line
            line_start = line.find('(')
            line_end = line.rfind(')')

            line = line[line_start+1:line_end]

            split_elem = line.split(',')
            print split_elem
            print "=========================================="
            #print split_elem[2] + ',' +  split_elem[3]

            #print ".name = " + split_elem[elem_idx] + ','
            elem_idx += 1

            print ".src_reg = " + split_elem[elem_idx] + ','
            elem_idx += 1

            if ("VALUE" in str(split_elem[elem_idx]) or ("MASK" in str(split_elem[elem_idx]))) :
                #print ".src_sel = " + split_elem[elem_idx + 0] + ',' +  split_elem[elem_idx + 1] + ','
                print ".src_sel = " + '0,'
                elem_idx += 2
            else:
                #print ".src_sel = " + split_elem[elem_idx + 0] + ','
                print ".src_sel = " + '0,'
                elem_idx += 1

            if ("VALUE" in str(split_elem[elem_idx]) or ("MASK" in str(split_elem[elem_idx]))) :
                print ".src_mask = " + split_elem[elem_idx + 0] + ',' +  split_elem[elem_idx + 1] + ','
                #print ".src_mask = " + '0,'
                elem_idx += 2
            else:
                print ".src_mask = " + split_elem[elem_idx + 0] + ','
                #print ".src_mask = " + '0,'
                elem_idx += 1

            print ".gate_reg = " + split_elem[elem_idx] + ','
            elem_idx += 1

            if ("VALUE" in str(split_elem[elem_idx]) or ("MASK" in str(split_elem[elem_idx]))) :
                print ".gate_val = " + split_elem[elem_idx + 0] + ',' +  split_elem[elem_idx + 1] + ','
                elem_idx += 2
            else:
                print ".gate_val = " + split_elem[elem_idx + 0] + ','
                elem_idx += 1

            if ("VALUE" in str(split_elem[elem_idx]) or ("MASK" in str(split_elem[elem_idx]))) :
                print ".gate_mask = " + split_elem[elem_idx + 0] + ',' +  split_elem[elem_idx + 1] + ','
                elem_idx += 2
            else:
                print ".gate_mask = " + split_elem[elem_idx + 0] + ','
                elem_idx += 1

            print ".fact_reg = " + split_elem[elem_idx] + ','
            elem_idx += 1

            if ("VALUE" in str(split_elem[elem_idx]) or ("MASK" in str(split_elem[elem_idx]))) :
                print ".mult = " + split_elem[elem_idx + 0] + ',' +  split_elem[elem_idx + 1] + ','
                elem_idx += 2
            else:
                print ".mult = " + split_elem[elem_idx + 0] + ','
                elem_idx += 1

            if ("VALUE" in str(split_elem[elem_idx]) or ("MASK" in str(split_elem[elem_idx]))) :
                print ".fact_mult_mask = " + split_elem[elem_idx + 0] + ',' +  split_elem[elem_idx + 1] + ','
                elem_idx += 2
            else:
                print ".fact_mult_mask = " + split_elem[elem_idx + 0] + ','
                elem_idx += 1

            if ("VALUE" in str(split_elem[elem_idx]) or ("MASK" in str(split_elem[elem_idx]))) :
                print ".div = " + split_elem[elem_idx + 0] + ',' +  split_elem[elem_idx + 1] + ','
                elem_idx += 2
            else:
                print ".div = " + split_elem[elem_idx + 0] + ','
                elem_idx += 1

            if ("VALUE" in str(split_elem[elem_idx]) or ("MASK" in str(split_elem[elem_idx]))) :
                print ".fact_div_mask = " + split_elem[elem_idx + 0] + ',' +  split_elem[elem_idx + 1] + ','
                elem_idx += 2
            else:
                print ".fact_div_mask = " + split_elem[elem_idx + 0] + ','
                elem_idx += 0

            print ".fc_req = " + split_elem[elem_idx] + ','
            elem_idx += 1

            if ("VALUE" in str(split_elem[elem_idx]) or ("MASK" in str(split_elem[elem_idx]))) :
                print ".fc_req_bit = " + split_elem[elem_idx + 0] + ',' +  split_elem[elem_idx + 1] + ','
                elem_idx += 2
            else:
                print ".fc_req_bit = " + split_elem[elem_idx + 0] + ','
                elem_idx += 1
            print "========================================"
    else:
        break
workbook.close()
