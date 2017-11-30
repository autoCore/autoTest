#!/usr/bin/env python

import sys,os
import random
import copy

lp_event = {
	"LP_AXI_EVENT":0,
	"LP_CLST_EVENT":1,
	"LP_DFC_AP_EVENT":2,
	"LP_DFC_CP_EVENT":3,
	"LP_DVC_AP_EVENT":4,
	"LP_DVC_CP_EVENT":5,
	"LP_C2_EVENT":6,
	"LP_M2_EVENT":7,
	"LP_CP_EVENT":8,
	"LP_DEEPSLEEP_EVENT":9,
	"LP_NORMAL_EVENT":10,
	"LP_RANDOM_EVENT":11,
	"LP_RANDOM_PARAM_ONLY":12,
	"LP_RANDOM_FUNC_ONLY":13,
	"LP_PARAM_MAX":14,
	"level_no_effective":20,
}

class ModuleTest:
    def __init__(self,module_name):
        self.module_name = module_name
        self.cases = []

    def addCase(self,case_obj):
        self.cases.append(case_obj)

    def getCases(self):
        return self.cases

class Case:
    def __init__(self):
        self.case_name = ''
        self.case_cmd = ''
        self.case_timeout = ''
        self.case_desc = ''

    def createCase(self,*arg):
        pass

class lp_axi_param:
    def __init__(self):
        self.name = 'LP_AXI_EVENT'
        self.type = lp_event['LP_AXI_EVENT']
        self.case_timeout = 1000
        self.param_range = {249000000:"aclk_249m",312000000:"aclk_312m"}
        self.param = self.param_range.items()[0]

    def get_random_event(self):
        self.param = random.choice(self.param_range.items())

    def gen_cmds(self):
        return ' '.join([str(self.type), str(self.param[0]), str(self.param[1])])

class lp_clst_param:
    def __init__(self):
        self.type = lp_event['LP_CLST_EVENT']
        self.name = 'LP_CLST_EVENT'
        self.case_timeout = 1000
        self.param_range = {624000000:"big_ca53_pll1_div4",
                            832000000:"big_ca53_pll1_div3",
                            1248000000:"big_ca53_pll1_div2",
                            1600000000:"big_ca53_pll4_div1",
                            624000000:"artemis_pll1_div4",
                            832000000:"artemis_pll1_div3",
                            1248000000:"artemis_pll1_div2",
                            2100000000:"artemis_pll3_div1"}
        self.param = self.param_range.items()[0]

    def get_random_event(self):
        self.param = random.choice(self.param_range.items())

    def gen_cmds(self):
        return ' '.join([str(self.type), str(self.param[0]), str(self.param[1])])

class lp_dfc_param:
    def __init__(self):
        self.type = lp_event['LP_DFC_AP_EVENT']
        self.name = 'LP_DFC_AP_EVENT'
        self.case_timeout = 1000
        self.param_range = range(8) + [20]
        self.apcfl = lp_event['level_no_effective']
        self.cpc0cfl = lp_event['level_no_effective']
        self.cpc2cfl = lp_event['level_no_effective']
        self.cpd2cfl = lp_event['level_no_effective']
        self.dpc0cfl = lp_event['level_no_effective']
        self.dpc2cfl = lp_event['level_no_effective']

    def get_random_event(self):
        self.apcfl = random.choice(self.param_range)
        self.cpc0cfl = random.choice(self.param_range)
        self.cpc2cfl = random.choice(self.param_range)
        self.cpd2cfl = random.choice(self.param_range)
        self.dpc0cfl = random.choice(self.param_range)
        self.dpc2cfl = random.choice(self.param_range)

    def gen_cmds(self):
        return ' '.join([str(self.type), str(self.apcfl), str(self.cpc0cfl), str(self.cpc2cfl),
            str(self.cpd2cfl), str(self.dpc0cfl), str(self.dpc2cfl)])

class lp_dvc_param:
    def __init__(self):
        self.name = 'LP_DVC_AP_EVENT'
        self.type = lp_event['LP_DVC_AP_EVENT']
        self.case_timeout = 1000
        self.param_range = range(8) + [20]

	self.apc0cfl = lp_event['level_no_effective']
	self.apm2cfl = lp_event['level_no_effective']
	self.apd1pcfl= lp_event['level_no_effective']
	self.apd1cfl = lp_event['level_no_effective']
	self.apd2cfl = lp_event['level_no_effective']
	self.cpc0cfl = lp_event['level_no_effective']
	self.cpc2cfl = lp_event['level_no_effective']
	self.cpd2cfl = lp_event['level_no_effective']
	self.dpc0cfl = lp_event['level_no_effective']
	self.dpc2cfl = lp_event['level_no_effective']

    def get_random_event(self):
       	self.apc0cfl = random.choice(self.param_range)
	self.apm2cfl = random.choice(self.param_range)
	self.apd1pcfl= random.choice(self.param_range)
	self.apd1cfl = random.choice(self.param_range)
	self.apd2cfl = random.choice(self.param_range)
	self.cpc0cfl = random.choice(self.param_range)
	self.cpc2cfl = random.choice(self.param_range)
	self.cpd2cfl = random.choice(self.param_range)
	self.dpc0cfl = random.choice(self.param_range)
	self.dpc2cfl = random.choice(self.param_range)

    def gen_cmds(self):
        return ' '.join([str(self.type), str(self.apc0cfl), str(self.apm2cfl), str(self.apd1pcfl),
            str(self.apd1cfl), str(self.apd2cfl), str(self.cpc0cfl), str(self.cpc2cfl),
            str(self.cpd2cfl), str(self.dpc0cfl), str(self.dpc2cfl)])

class lp_c2_param:
    def __init__(self):
        self.type = lp_event['LP_C2_EVENT']
        self.name = 'LP_C2_EVENT'
        self.case_timeout = 1000
        self.param_range = {100:2, 200:2, 300:2, 400:2, 500:2}

        self.t_ms = 100
        self.wu_src = 2

    def get_random_event(self):
        self.t_ms, self.wu_src  = random.choice(self.param_range.items())

    def gen_cmds(self):
        return ' '.join([str(self.type), str(self.wu_src), str(self.t_ms)])

class lp_m2_param:
    def __init__(self):
        self.name = 'LP_M2_EVENT'
        self.type = lp_event['LP_M2_EVENT']
        self.case_timeout = 1000
        self.param_range = {100:2, 200:2, 300:2, 400:2, 500:2}

        self.t_ms = 100
        self.wu_src = 2

    def get_random_event(self):
        self.t_ms, self.wu_src  = random.choice(self.param_range.items())

    def gen_cmds(self):
        return ' '.join([str(self.type), str(self.wu_src), str(self.t_ms)])

class lp_cp_param:
    def __init__(self):
        self.type = lp_event['LP_CP_EVENT']
        self.name = 'LP_CP_EVENT'
        self.case_timeout = 1000
        self.slptype_range = range(15,20)
        self.param_range = {100:0, 200:0, 300:0, 400:0, 500:0}

        self.t_ms = 100
        self.wu_src = 0
        self.slptype = 15

    def get_random_event(self):
        self.slptype = random.choice(self.slptype_range)
        self.t_ms, self.wu_src = random.choice(self.param_range.items())

    def gen_cmds(self):
        return ' '.join([str(self.type), str(self.slptype), str(self.wu_src), str(self.t_ms)])

class lp_deepsleep_param:
    def __init__(self):
        self.type = lp_event['LP_DEEPSLEEP_EVENT']
        self.name = 'LP_DEEPSLEEP_EVENT'
        self.case_timeout = 1000
        self.param_range = {9:2, 11:2, 12:2}

        self.slptype = 9
        self.wu_src = 2

    def get_random_event(self):
        self.slptype, self.wusrc = random.choice(self.param_range.items())

    def gen_cmds(self):
        return ' '.join([str(self.type), str(self.slptype), str(self.wu_src)])

class lp_case_event(Case):
    def __init__(self):
#        super(lp_case_event, self).__init__()
        Case.__init__(self)
        self.axi_param = lp_axi_param()
        self.clst_param = lp_clst_param()
        self.dfc_param = lp_dfc_param()
        self.dvc_param = lp_dvc_param()
        self.c2_param = lp_c2_param()
        self.m2_param = lp_m2_param()
        self.cp_param = lp_cp_param()
        self.deepsleep_param = lp_deepsleep_param()

        self.param_list = [self.axi_param, self.clst_param, self.dfc_param, self.dvc_param,
                    self.c2_param, self.m2_param, self.cp_param, self.deepsleep_param]

    def createCase(self):
        pass

    def createCaseByRandom(self):
        self.tmp_param = random.choice(self.param_list)
        self.case_name = self.tmp_param.name
        self.tmp_param.get_random_event()
        self.case_cmd = 'lpm ' + self.tmp_param.gen_cmds()
        self.case_timeout = self.tmp_param.case_timeout
        self.case_desc = "lowpower_case_" + str(self.tmp_param.type)
        pass

def createLowpowerCase(lp_case):
    lp_event = lp_case_event()
    for i in range(10):
        lp_event.createCaseByRandom()
        lp_case.addCase(copy.deepcopy(lp_event))

if __name__ == "__main__":
    lp_case = ModuleTest("lowpower")
    createLowpowerCase(lp_case)

    for percase in lp_case.getCases():
        print ' '.join([percase.case_desc, str(percase.case_timeout)+'ms', percase.case_name, percase.case_cmd])
