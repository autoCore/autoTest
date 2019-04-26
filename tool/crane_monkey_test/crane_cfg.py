#!/usr/bin/env python

SIMULATE_KEY_INPUT_INTERVAL = '0.5'
SPACES_CNT = 130
CHECK_INTERVAL = 3
RESET_SYSTEM_WAIT_TIME = 25
PMIC_WGD_TIMEOUT = 128

key_value_d = {
    '[':'F_LEFT',
    '^':'UP',
    ']':'F_RIGHT',
    '<':'LEFT',
    'M':'OK',
    '>':'RIGHT',
    'S':'CALL',
    'V':'DOWN',
    'P':'RING_OFF',
    '1':'1',
    '2':'2',
    '3':'3',
    '4':'4',
    '5':'5',
    '6':'6',
    '7':'7',
    '8':'8',
    '9':'9',
    '*':'*',
    '0':'0',
#    '#':'#',
    'U':'V_UP',
    'D':'V_DOWN',
}
alarm_key_value_d = {
    '[':'F_LEFT',
    '^':'UP',
    ']':'F_RIGHT',
    '<':'LEFT',
    'M':'OK',
    'M':'OK',
    'M':'OK',
    'M':'OK',
    'M':'OK',
    'M':'OK',
    '>':'RIGHT',
    'V':'DOWN',
}
contact_key_value_d = {
    '[':'F_LEFT',
    '^':'UP',
    ']':'F_RIGHT',
    '<':'LEFT',
    'M':'OK',
    '>':'RIGHT',
    'V':'DOWN',
    '1':'1',
    '2':'2',
    '3':'3',
    '4':'4',
    '5':'5',
    '6':'6',
    '7':'7',
    '8':'8',
    '9':'9',
    '0':'0',
}

#   [   ^   ]
#    <  M  >
#   S   V   P
#   1   2   3
#   4   5   6
#   7   8   9
#   *   0   #