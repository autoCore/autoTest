#! /usr/bin/env python
from nvram_cfg import *
from nvram_util import *


class AlarmInfo(InfoObject):
    _fields_ = [('ONTIME', c_ubyte), ('before_alarm', c_ubyte), ('ACTIVATION', c_ubyte), ('REPEATS', c_ubyte),
                ('ALM_TIME_H', c_ubyte), ('ALM_TIME_MIN', c_ubyte), ('WEEKLY', c_ubyte), ('TYPE', c_ubyte),
                ('TONE_ID', c_ubyte), ('VOL', c_ubyte), ('SNOOZE_DUR', c_ubyte), ('SNOOZE_REP', c_ubyte),
                ('AUTO_POWERRUP', c_ubyte), ('REG_ALARM', c_ubyte), ('REMINDER_PREQUENCY', c_ubyte * 5),
                ('TYPE_REPEAT', c_ubyte), ('SNOOZE_MAX', c_ubyte), ('ALARM_NAME', c_ubyte * 36)]
