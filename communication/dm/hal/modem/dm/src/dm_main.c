#include "stdlib.h"

#include "plat_config_defs.h"
#include "plat_types.h"
#include "ui_os_api.h"
#include "ui_log_api.h"
#include "nvram.h"
#include "nw_api.h"

#include "cus_dm_register_def.h"
#include "dm_register.h"


static struct dm_register_config *cur_dm_config = NULL;

u16 get_dm_nv_id(void)
{
	ASSERT(cur_dm_config != NULL);
	return (u16)cur_dm_config->dm_nv_id;
}

u8 get_telecom_dm_mode(void)
{
	ASSERT(cur_dm_config != NULL);
	return cur_dm_config->telecom_dm_mode;
}

u8 get_cmcc_dm_mode(void)
{
	ASSERT(cur_dm_config != NULL);
	return cur_dm_config->cmcc_dm_mode;
}

u8 get_unicom_dm_mode(void)
{
	ASSERT(cur_dm_config != NULL);
	return cur_dm_config->unicom_dm_mode;
}

u8 get_dm_demo_mode(void)
{
	ASSERT(cur_dm_config != NULL);
	return cur_dm_config->demo_mode;
}

static int __get_sim_type(char *plmn)
{
	if (strcmp(plmn, "46000") == 0 || strcmp(plmn, "46002") == 0
	    || strcmp(plmn, "46004") == 0 || strcmp(plmn, "46007") == 0)
		return CHINA_MOBILE;
	else if (strcmp(plmn, "46001") == 0 || strcmp(plmn, "46006") == 0
		 || strcmp(plmn, "46009") == 0)
		return CHINA_UNICOM;
	else if (strcmp(plmn, "46003") == 0 || strcmp(plmn, "46005") == 0)
		return CHINA_TELECOM_CDMA;
	else if (strcmp(plmn, "46011") == 0)
		return CHINA_TELECOM_LTE;
	else
		return UNKNOW_SIM;
}

struct sim_info *get_current_sim_info(void)
{
	char plmn1[5] = { 0 };
	char plmn2[5] = { 0 };
	static int flag = 0;
	static struct sim_info cur_sim_info = {
		0, 0,
		UNKNOW_SIM, UNKNOW_SIM,
		ICCID_WITH_NO_SIM_INSTRTED, ICCID_WITH_NO_SIM_INSTRTED,
		IMSI_WITH_NO_SIM_INSTRTED, IMSI_WITH_NO_SIM_INSTRTED};

	if (0 == flag) {
		cur_sim_info.sim1_flag = IsSimExist(0);
		cur_sim_info.sim2_flag = IsSimExist(1);

		if (cur_sim_info.sim1_flag) {
			strncpy(plmn1, (const char *)CMID_NwGetImsi(CMID_SIM_0), 5);
			cur_sim_info.sim1_type = __get_sim_type(plmn1);
			cur_sim_info.iccid1 = (const char *)CMID_NwGetIccid(CMID_SIM_0);
			cur_sim_info.imsi1 = (const char *)CMID_NwGetImsi(CMID_SIM_0);
		}

		if (cur_sim_info.sim2_flag) {
			strncpy(plmn2, (const char *)CMID_NwGetImsi(CMID_SIM_1), 5);
			cur_sim_info.sim2_type = __get_sim_type(plmn2);
			cur_sim_info.iccid2 = (const char *)CMID_NwGetIccid(CMID_SIM_1);
			cur_sim_info.imsi2 = (const char *)CMID_NwGetImsi(CMID_SIM_1);
		}

		CTDM_LOG("[DM] current sim info:\n");
		CTDM_LOG("[DM] sim1:%d\n", cur_sim_info.sim1_flag);
		CTDM_LOG("[DM] sim2:%d\n", cur_sim_info.sim2_flag);
		CTDM_LOG("[DM] imsi1:%s\n", cur_sim_info.imsi1);
		CTDM_LOG("[DM] imsi2:%s\n", cur_sim_info.imsi2);
		CTDM_LOG("[DM] iccid1:%s\n", cur_sim_info.iccid1);
		CTDM_LOG("[DM] iccid2:%s\n", cur_sim_info.iccid2);

		flag = 1;
	}

	return &cur_sim_info;
}

struct dm_register_record *get_current_dm_record(void)
{
	int ret;
	s16 error = 0;
	static struct dm_register_record dm_nv_record;
	static int flag;

	if (0 == flag) {
		ret = ReadRecord(get_dm_nv_id(), 0, &dm_nv_record, sizeof(dm_nv_record), &error);
		if (ret < 0) {
				CTDM_LOG("[DM] read DM NV failed!\n", 1);
				return NULL;
		}

		CTDM_LOG("[DM] current dm nv record:\n");
		CTDM_LOG("[DM] nv imsi1:%s\n", dm_nv_record.IMSI1);
		CTDM_LOG("[DM] nv imsi2:%s\n", dm_nv_record.IMSI2);
		CTDM_LOG("[DM] nv iccid1:%s\n", dm_nv_record.UEICCID1);
		CTDM_LOG("[DM] nv iccid2:%s\n", dm_nv_record.UEICCID2);

		flag = 1;
	}

	return &dm_nv_record;
}

static HANDLE dm_task_handle = NULL;
static u8 remove_dm_task_time_id = INVALID_TIMER_ID;

static void remove_dm_task_timer_callback(void)
{
	if (remove_dm_task_time_id != INVALID_TIMER_ID) {
		UOS_KillFunctionTimer(remove_dm_task_time_id);
		remove_dm_task_time_id = INVALID_TIMER_ID;
	}

	if (dm_task_handle != NULL) {
		UOS_DeleteTask((TASK_HANDLE *)dm_task_handle);
		dm_task_handle = NULL;
	}
}

void send_dm_event(void *p)
{
	UI_EVENT dm_evt = {0, 0, 0, 0};
	ASSERT(dm_task_handle != NULL);

	dm_evt.nEventId = (u32)p;
	UOS_SendEvent(dm_task_handle, &dm_evt, UOS_WAIT_FOREVER, UOS_EVENT_PRI_NORMAL);
}

static void dm_task_entry(void *dm_handle)
{
	int ret;
	struct sim_info *cur_sim_info;
	UI_EVENT dm_evt;
	int flag = 0;

	// wait for system enter idle state
	UOS_SleepSeconds(30);

	cur_sim_info = get_current_sim_info();
	cur_dm_config = get_dm_configuration();

	if ((0 == cur_sim_info->sim1_flag) && (0 == cur_sim_info->sim2_flag)) {
		CTDM_LOG("[DM] no sim insert, exit DM module\n", 1);
		goto exit;
	}

	if (!get_current_dm_record()) {
			CTDM_LOG("[DM] read DM NV failed, exit DM module\n", 1);
			goto exit;
	}

#ifdef DM_VERSION_1
	CTDM_LOG("[DM] DM VERSION 1\n");
#else
#ifdef DM_VERSION_2
	CTDM_LOG("[DM] DM VERSION 2\n");
#endif
#endif

	CTDM_LOG("[DM] build time %s %s\n", __DATE__, __TIME__);

	ASSERT(cur_dm_config != NULL);

	CTDM_LOG("[DM] dm configuration: telecom:%d cmcc:%d unicom:%d nv_id:%d\n",
		cur_dm_config->telecom_dm_mode,
		cur_dm_config->cmcc_dm_mode,
		cur_dm_config->unicom_dm_mode,
		cur_dm_config->dm_nv_id);

	if (get_telecom_dm_mode()) {
		flag++;
		send_dm_event((void*)TELECOM_DM_REQUEST);
	}

	if (get_cmcc_dm_mode()) {
		flag++;
		send_dm_event((void*)CMCC_DM_REQUEST);
	}

	if (get_unicom_dm_mode()) {
		flag++;
		send_dm_event((void*)UNICOM_DM_REQUEST);
	}

	if (0 == flag) {
		CTDM_LOG("[DM] (config empty)exit DM module!\n");
		goto exit;
	}

	while (1) {
		UOS_WaitEvent(dm_task_handle, &dm_evt, OS_SUSPEND);

		ret = NO_REGISTER_REQUIRED;

		switch (dm_evt.nEventId) {
		case TELECOM_DM_REQUEST:
			if (cur_sim_info->sim1_type == CHINA_TELECOM_LTE || cur_sim_info->sim2_type == CHINA_TELECOM_LTE) {
				ret = do_telecom_dm();
			} else {
				CTDM_LOG("[DM] no TELECOM sim card insert!\n");
			}
			break;

		case CMCC_DM_REQUEST:
			if (cur_sim_info->sim1_type == CHINA_MOBILE || cur_sim_info->sim2_type == CHINA_MOBILE) {
				ret = do_cmcc_dm();
			} else {
				CTDM_LOG("[DM] no CMCC sim card insert!\n");
			}
			break;

		case UNICOM_DM_REQUEST:
			if (cur_sim_info->sim1_type == CHINA_UNICOM || cur_sim_info->sim2_type == CHINA_UNICOM) {
				ret = do_unicom_dm();
			} else {
				CTDM_LOG("[DM] no UNICOM sim card insert!\n");
			}
			break;

		default:
			break;
		}

		if (ret != REGISTER_FAILED)
			flag--;

		if (0 == flag)
			break;
	}

exit:

	CTDM_LOG("[DM] exit DM module!\n");

	return;

	remove_dm_task_time_id = UOS_get_FunctionTimer();
	UOS_StartFunctionTimer_single(
		remove_dm_task_time_id, 20, remove_dm_task_timer_callback, NULL, "rmDmTask");

	return;
}

#if 0
void delete_dm_task(void)
{
	if (dm_task_handle) {
		CTDM_LOG("[DM] remove dm task!\n");
		UOS_DeleteTask((TASK_HANDLE *)dm_task_handle);
		dm_task_handle = NULL;
	}
}
#endif

void dm_start(void)
{
	static int flag = 0;

	if (1 == flag) {
		return;
	}
	flag = 1;

	CTDM_LOG("[DM] create dm task!\n");

	dm_task_handle = UOS_CreateTask(
		dm_task_entry,
		NULL,
		TASK_MSGQ_SIZE_16,
		10240,
		210,
		"DMTask");

	ASSERT(dm_task_handle != NULL);
}
