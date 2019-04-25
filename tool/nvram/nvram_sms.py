#! /usr/bin/env python
from nvram_cfg import *
from nvram_util import *


class SmsInfo(InfoObject):
    """docstring for SmsInfo"""
    _fields_ = [('vp', c_ubyte), ('pid', c_ubyte), ('dcs', c_ubyte), ('mti', c_ubyte),
                ('ssr', c_ubyte), ('bearer', c_ubyte), ('bSimChange', c_ubyte), ('bReserverd', c_ubyte),
                ('mr', c_ubyte), ('rp', c_ubyte), ('nNumber', c_ubyte*12), ('udhi', c_ubyte),
                ('rd', c_ubyte), ('vpf', c_ubyte), ('nSaveToSimFlag', c_ubyte), ('nIndex', c_ubyte), ('bDefault', c_uint)]
