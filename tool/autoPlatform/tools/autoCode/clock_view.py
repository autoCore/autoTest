import os
import sys
import xlrd
import string

import pygraphviz as pgv
from clock_parse_excel import parse_excel_clock_source
from clock_parse_excel import  parse_excel_clock_factor
from clock_parse_excel import parse_excel_clock_parent
from clock_parse_excel import curr_is_number_clk
from clock_parse_excel import get_clock_macro

debug = False
gen_apb_clock = True
gen_axi_clock = True
show_disable_node = True

active_color = "green"
inactive_color= "gray"
clock_array = []
domain_flags = ""
G = pgv.AGraph(strict=True, directed=True)

def graph_init():
    G = pgv.AGraph(strict=True, directed=True)
    G.graph_attr['label'] = "aquila clock view"
    #G.graph_attr['splines']='line'
    #G.graph_attr['splines']='ortho'
    #G.graph_attr['rankdir']='LR'
    G.graph_attr['outputorder']='in'
    G.graph_attr['ratio']='0.3'
    G.graph_attr['epsilon']='0.1'

    #G.node_attr['fixedsize']='true'
    G.node_attr['fontsize']='12'
    G.node_attr['style']='filled'
    G.node_attr['fixedsize']='true'
    G.node_attr['shape'] = 'box3d'

    G.edge_attr['color'] = 'blue'
    G.edge_attr['style']='setlinewidth(10)'
    G.edge_attr['dir'] = 'both'
    G.edge_attr['weight'] = '1.0'
#    G.edge_attr['arrowhead'] = 'vee'
    G.edge_attr['color'] = "blue"
    G.edge_attr['arrowtail'] = 'v'
    #G.edge_attr['arrowhead'] = 'none'
    G.edge_attr['arrowsize'] = '1'
    G.edge_attr['style'] = 'solid'
    G.edge_attr['len'] = '5.0'

    return G

def output_graph(G):
    G.write("first.dot")
    G.layout(prog='dot')
    G.draw('first.png')
    os.system('eog ./first.png')

def init_clock():
    pass

def clock_gate_is_active(infile, s, curr_row, curr_col):
    is_active = False
    curr_reg_struct = s.cell_value(curr_row, 2)
    clock_idx = s.cell_value(curr_row, curr_col)
    """
    src_reg = str(s.cell_value(curr_row, 2)).split('.')[1].split('=')[1][0:-1].strip(' ').split(',')[0]
    src_bit = str(s.cell_value(curr_row, 2)).split('.')[3].split('=')[1][0:-1].split(',')[0].strip()
    if ('0' != src_bit):
        src_bit = str(s.cell_value(curr_row, 2)).split('.')[3].split('=')[1][0:-1].split(',')[0].sactive_colorplit('(')[1]
        src_sel = " VALUE_(" + src_bit + ", 0x" + str(clock_idx) + "),"
    #print "src_bit = " + src_bit
    else:
        src_sel = " " + src_bit + ","
    if debug: print "src_sel = " + src_sel
    src_mask = str(s.cell_value(curr_row, 2)).split('.')[3].split('=')[1][0:-1]
    if debug: print "src_mask = " + src_mask
    """
    gate_reg = str(s.cell_value(curr_row, 2)).split('.')[4].split('=')[1][0:-1].strip(' ').split(',')[0]
    if debug: print "gate_reg = " + gate_reg
    if debug: print "gate_reg = " + gate_reg
    if gate_reg is '0':
        return False
    gate_val = str(s.cell_value(curr_row, 2)).split('.')[5].split('=')[1][0:-1]
    if debug: print "gate_val = " + gate_val
    gate_mask = str(s.cell_value(curr_row, 2)).split('.')[6].split('=')[1][0:-1]
    if debug: print "gate_mask = " + gate_mask
    """
    fact_reg = str(s.cell_value(curr_row, 2)).split('.')[7].split('=')[1][0:-1].strip(' ').split(',')[0]
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
    """
    infile.seek(0)
    while True:
        line = infile.readline()
        if line:
            line=line.strip()

            clock_reg_name = line.split(':')[0].strip()
            clock_reg_val = string.atoi(line.split(':')[1], 16)
            #print "==========" + clock_reg_name + str(len(clock_reg_name)) + '======'  + gate_reg + str(len(gate_reg))
            if clock_reg_name == gate_reg:
                if gate_val.find("BIT") != -1:
                    gate_sel_val = 1
                else:
                    gate_sel_val =  string.atoi(gate_val.split(',')[1][0:-1].split(')')[0], 16)

                gate_valid_bit = string.atoi(curr_reg_struct.split('.')[6].split('=')[1][0:-1].split(',')[0].strip().split('(')[1])
                gate_mask_val = string.atoi(curr_reg_struct.split('.')[6].split('=')[1][0:-1].split(',')[1].split(')')[0], 16)

                is_active = (clock_reg_val >> gate_valid_bit & gate_mask_val) == gate_sel_val

                #print "gate_val =" + str(gate_val) + "gate_mask" + str(gate_mask) + str(gate_mask_val) + str(gate_mask_val) + " gate_sel_val=" + str(gate_sel_val) + " gate_valid_bit = " + str(gate_valid_bit)
                print "==========" + clock_reg_name + '======'  + gate_reg
                break
        else:
            break

    print "========= " + str(s.cell_value(curr_row, 0)) + ", " + str(hex(clock_reg_val)) + " is_active = "+ str(is_active)
    return is_active

def clock_source_is_active(infile, s, curr_row, curr_col):
    is_active = False
    curr_reg_struct = s.cell_value(curr_row, 2)
    clock_idx = s.cell_value(curr_row, curr_col)

    src_reg = str(s.cell_value(curr_row, 2)).split('.')[1].split('=')[1][0:-1].strip(' ').split(',')[0]
    if debug: print "src_reg = " + src_reg
    if src_reg is '0':
        return False

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
    """
    gate_reg = str(s.cell_value(curr_row, 2)).split('.')[4].split('=')[1][0:-1].strip(' ').split(',')[0]
    if debug: print "gate_reg = " + gate_reg
    gate_val = str(s.cell_value(curr_row, 2)).split('.')[5].split('=')[1][0:-1]
    if debug: print "gate_val = " + gate_val
    gate_mask = str(s.cell_value(curr_row, 2)).split('.')[6].split('=')[1][0:-1]
    if debug: print "gate_mask = " + gate_mask

    fact_reg = str(s.cell_value(curr_row, 2)).split('.')[7].split('=')[1][0:-1].strip(' ').split(',')[0]
    if debug: print "fact_reg = " + fact_reg
    mult = str(s.cell_value(curr_row, 2)).split('.')[8].split('=')[1][0:-1]
    if debug: print "mult = " + mult
    mult_mask = str(s.cell_value(curr_row, 2)).split('.')[9].split('=')[1][0:-1]
    if debug: print "mult_mask = " + mult_mask
    div = str(s.cell_value(curr_row, 2)).split('.')[10].split('=')[1][0:-1]
    if debug: print "div = " + div
    div_mask = str(s.cell_value(curr_row, 2)).split('.')[11].split('=')[1][0:-1]
    if debug: print "div_mask = " + div_mask
    clock_main
    fc_reg = str(s.cell_value(curr_row, 2)).split('.')[12].split('=')[1][0:-1]
    if debug: print "fc_reg = " + fc_reg
    fc_req = str(s.cell_value(curr_row, 2)).split('.')[13].split('=')[1][0:-1]
    if debug: print "fc_req = " + fc_req
    """
    infile.seek(0)
    while True:
        line = infile.readline()
        if line:
            line=line.strip()

            clock_reg_name = line.split(':')[0].strip()
            clock_reg_val = string.atoi(line.split(':')[1], 16)
            if clock_reg_name == src_reg:
                src_valid_bit = string.atoi(src_bit)
#                src_sel_val =  string.atoi(curr_reg_struct.split('.')[2].split('=')[1][0:-1].split(',')[0])
                src_mask_val = string.atoi(curr_reg_struct.split('.')[3].split('=')[1][0:-1].split(',')[1].split(')')[0], 16)

                is_active = (clock_reg_val >> src_valid_bit & src_mask_val) == float(clock_idx)

#                print "src_mask_val = " + str(src_mask_val) + " src_sel_val=" + str(src_sel_val) + " src_valid_bit = " + str(src_valid_bit)
#                print "====" + str(s.cell_value(curr_row, 0))  + " row = " + str(curr_row) + "==========" + clock_reg_name + '======'  + src_reg
#                print "==reg_val = " + str(hex(clock_reg_val)) + " is_ture = "+ str(is_active)
        else:
            break

    print "++++++++++++++++++++++++++++++reg_val = " + str(hex(clock_reg_val)) + " is_ture = "+ str(is_active)
    return is_active

def clock_main(fname_excel):
    G = graph_init()

    infile = open("./clock_reg.txt")
    workbook = xlrd.open_workbook(fname_excel)
    os.chdir(r"./tmp")

    for s in workbook.sheets():
        if s.name != "AP_CLOCK":
            continue

        nrow = s.nrows
        ncol = s.ncols - 2  #last line is note and signal
        curr_row = 0
        clock_source_ready = 0
        clock_source_dict = {}
        is_found = 0
        parent_string = ""

        while curr_row < nrow:
            curr_col = 3
            clock_max = 0;
            comp_clock = ["NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"]

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
                is_factor = parse_excel_clock_factor(s.row_values(curr_row))
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
                            if ("pll1_vco" in s.cell_value(curr_row, 0)):
                                G.add_node(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), style='filled', fillcolor=active_color, shape='box')
                                G.add_edge(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), str(parent_string).replace('.', '_'), shape='doubleoctagon', color=active_color)
                            else:
                                if ("pll1" in s.cell_value(curr_row, 0) or curr_is_number_clk(s, curr_row)):
                                    comp_clock[clock_idx] = "AQUILA_CLK(\"" + str(s.cell_value(curr_row, 0).lower()).replace('.','_') + "\", \"" + str(parent_string).replace('.', '_') + "\", " + flags_str + ", "  + clk_freq + "),"

                                    if (clock_gate_is_active(infile, s, curr_row, curr_col)):
                                        G.add_node(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), style='filled', fillcolor= active_color, shape='box')
                                        G.add_edge(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), str(parent_string).replace('.', '_'), shape='doubleoctagon', color=active_color)
                                    else:
                                        if show_disable_node: G.add_node(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), style='filled', fillcolor=inactive_color, shape='box')
                                        if show_disable_node: G.add_edge(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), str(parent_string).replace('.', '_'), shape='doubleoctagon', color=inactive_color)

                                if gen_axi_clock:
                                    if (clock_gate_is_active(infile, s, curr_row, curr_col)):
                                        G.add_node(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), style='filled', fillcolor=active_color, shape='box')
                                        G.add_edge(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), str(parent_string).replace('.', '_'), shape='doubleoctagon', color=active_color)
                                    else:
                                        if show_disable_node: G.add_node(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), style='filled', fillcolor=inactive_color, shape='box')
                                        if show_disable_node: G.add_edge(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), str(parent_string).replace('.', '_'), shape='doubleoctagon', color=inactive_color)

                            comp_clock[clock_idx] = "AQUILA_CLK(\"" + str(s.cell_value(curr_row, 0).lower()).replace('.','_') + "\", \"" + str(parent_string).replace('.', '_') + "\", " + flags_str + ", "  + clk_freq + "),"
                        elif ("CLK_APB_DOMAIN" in domain_flags):
                            if gen_apb_clock:
                                if (clock_gate_is_active(infile, s, curr_row, curr_col)):
                                    if gen_apb_clock: G.add_node(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), style='filled', fillcolor=active_color, shape='box')
                                    if clock_source_is_active(infile, s, curr_row, curr_col):
                                        G.add_edge(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), str(parent_string).replace('.', '_'), shape='doubleoctagon', color=active_color)
                                    else:
                                        if show_disable_node: G.add_edge(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), str(parent_string).replace('.', '_'), shape='doubleoctagon', color=inactive_color)
                                else:
                                    if show_disable_node:
                                        if gen_apb_clock: G.add_node(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), style='filled', fillcolor=inactive_color, shape='box')
                                    if show_disable_node: G.add_edge(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), str(parent_string).replace('.', '_'), shape='doubleoctagon', color=inactive_color)

                                comp_clock[clock_idx] = "AQUILA_CLK(\"" + str(s.cell_value(curr_row, 0).lower()).replace('.','_') + "_" + parent_string.replace('.', '_') + "\", \"" + str(parent_string).replace('.', '_') + "\", " + flags_str + ", "  + clk_freq + "),"
                        elif ("CLK_AXI_DOMAIN" in domain_flags):
                            if (clock_gate_is_active(infile, s, curr_row, curr_col)):
                                if gen_axi_clock: G.add_node(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), style='filled', fillcolor=active_color, shape='box')
                                if clock_source_is_active(infile, s, curr_row, curr_col):
                                    G.add_edge(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), str(parent_string).replace('.', '_'), shape='doubleoctagon', color=active_color)
                                else:
                                    if show_disable_node: G.add_edge(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), str(parent_string).replace('.', '_'), shape='doubleoctagon', color=inactive_color)
                            else:
                                if show_disable_node:
                                    if gen_axi_clock: G.add_node(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), style='filled', fillcolor=inactive_color, shape='box')
                                if show_disable_node: G.add_edge(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), str(parent_string).replace('.', '_'), shape='doubleoctagon', color=inactive_color)

                            comp_clock[clock_idx] = "AQUILA_CLK(\"" + str(s.cell_value(curr_row, 0).lower()).replace('.','_') + "_" + parent_string.replace('.', '_') + "\", \"" + str(parent_string).replace('.', '_') + "\", " + flags_str + ", "  + clk_freq + "),"
                            pass
                        else:
                            comp_clock[clock_idx] = "AQUILA_CLK(\"" + str(s.cell_value(curr_row, 0).lower()).replace('.','_') + "_" + parent_string.replace('.', '_') + "\", \"" + str(parent_string).replace('.', '_') + "\", " + flags_str + ", "  + clk_freq + "),"
                            if (clock_gate_is_active(infile, s, curr_row, curr_col)):
                                G.add_node(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), style='filled', fillcolor=active_color, shape='box')
                                if clock_source_is_active(infile, s, curr_row, curr_col):
                                    G.add_edge(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), str(parent_string).replace('.', '_'), shape='doubleoctagon', color=active_color)
                                else:
                                    if show_disable_node: G.add_edge(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), str(parent_string).replace('.', '_'), shape='doubleoctagon', color=inactive_color)
                            else:
                                if show_disable_node: G.add_node(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), style='filled', fillcolor=inactive_color, shape='box')
                                if show_disable_node: G.add_edge(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), str(parent_string).replace('.', '_'), shape='doubleoctagon', color=inactive_color)

                        #print str(comp_clock)
                    curr_col += 1

                if (is_found == 1):
                    if ("CLK_AXI_DOMAIN" in domain_flags):
                        if debug:print "#ifdef " + str(get_clock_macro(s.cell_value(curr_row, 0)))
                    if ("CLK_APB_DOMAIN" in domain_flags):
                        if debug:print "#ifdef " + str(s.cell_value(curr_row, 0).upper()) + "_CLOCK"
                    for i in range(0, clock_max + 1):
                        #print "i = " + str(i) + " max = " + str(clock_max)
                        if debug:print str(comp_clock[i])

                    if ("CLK_AXI_DOMAIN" in domain_flags or "CLK_APB_DOMAIN" in domain_flags):
                        if debug:print "#endif"
                else :
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
#                    if (clock_gate_is_active(infile, s, curr_row, curr_col)):
#                        G.add_node(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), style='filled', fillcolor='green', shape='tripleoctagon')
#                    else:
#                        G.add_node(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), style='filled', fillcolor='gray', shape='tripleoctagon')

                    G.add_node(str(s.cell_value(curr_row, 0).lower()).replace('.','_'), style='filled', fillcolor=active_color, shape='tripleoctagon')

                    if debug:print comp_str

            is_found = 0
            curr_row += 1
    output_graph(G)


if __name__ == "__main__":
    if (len(sys.argv) < 2):
        print "error: pls enter the correct command", + len(sys.argv)
        exit(-1)

    fname_excel = str(sys.argv[1])
    isExists = os.path.exists("./tmp")
    if not isExists:
        os.mkdir("./tmp")

    os.system('chmod +w tmp')

    clock_main(fname_excel)

    sys.exit(0)
