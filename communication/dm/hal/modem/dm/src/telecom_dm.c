#include "ui_os_api.h"
#include "app_target_defs.h"
#include "plat_types.h"
#include "nvram_api.h"
#include "nw_api.h"
#include "cus_dm_register_def.h"

#include "libhttpclient.h"
#include "httpclient_sys.h"
#include "cJSON.h"

#include "dm_register.h"


#define TELECOM_DATA_DM_LIMIT	10
// 60 minutes
#define TELECOM_DATA_DM_INTERVAL 3600
#define TELECOM_SMS_DM_LIMIT	3
// 10 minutes
#define TELECOM_SMS_DM_INTERVAL	600

#define MODEL_MAX_LEN 20
#define SWVER_MAX_LEN 40
#define IMSI_MAX_LEN 15
#define IMEI_MAX_LEN 15
#define XML_DATA_SIZE 136

#define DM_SMS_XML_FORMAT "<a1><b1>%.*s</b1><b2>%.*s</b2><b3>%.*s</b3><b4>%.*s</b4><b5>%.*s</b5></a1>"

#define DM_SMS_XML_FORMAT_NO_IMEI2 "<a1><b1>%.*s</b1><b2>%.*s</b2><b3>%.*s</b3><b4>%.*s</b4></a1>"


extern int myBlockSendSmsReq(char *number,  char *buf, int len, char  simId, int backgroud_mode);
extern struct telecom_dm_register_data *init_telecom_dm_data(void);

static int __sms_telecom_dm(void)
{
	int ret;
	static int cnt = 1;
	s16 error = 0;
	unsigned int size;
	unsigned char dm_sms_data[256];
	int register_cnt = 0;
	int update_nv_cnt = 0;
	struct sim_info *cur_sim_info = get_current_sim_info();
	struct dm_register_record *dm_nv_record = get_current_dm_record();
	struct telecom_dm_register_data *data;
	int with_no_imei2_flag = 0;

	if (cnt > TELECOM_SMS_DM_LIMIT)
		return REGISTER_LIMITED_REACHED;

	data = init_telecom_dm_data();
	ASSERT(data != NULL);

	// check need to send imei2
	if (0 == strcmp(data->SMS_DM_NO_IMEI2_FLAG, "1"))
		with_no_imei2_flag = 1;

	if (cur_sim_info->sim1_flag && cur_sim_info->sim1_type == CHINA_TELECOM_LTE) {
#ifdef DM_VERSION_1
#else
		if (!CMID_NwIsVolteRegistered(CMID_SIM_0)) {
			CTDM_LOG("[DM] sim1 is not registered in volte net, exit DM module!\n");
			return NO_REGISTER_REQUIRED;
		}
#endif
		if (strcmp(dm_nv_record->IMSI1, cur_sim_info->imsi1)) {
			CTDM_LOG("[DM] sim1 to be registered!\n");
			register_cnt++;
			memset(dm_sms_data, 0x0, 256);
			if (with_no_imei2_flag) {
				sprintf(dm_sms_data + 4, DM_SMS_XML_FORMAT_NO_IMEI2,
					MODEL_MAX_LEN, data->MODEL,
					IMEI_MAX_LEN, CMID_NwGetImei(CMID_SIM_0),
					IMSI_MAX_LEN, cur_sim_info->imsi1,
					SWVER_MAX_LEN, data->SWVER);
			} else {
				sprintf(dm_sms_data + 4, DM_SMS_XML_FORMAT,
					MODEL_MAX_LEN, data->MODEL,
					IMEI_MAX_LEN, CMID_NwGetImei(CMID_SIM_0),
					IMEI_MAX_LEN, CMID_NwGetImei(CMID_SIM_1),
					IMSI_MAX_LEN, cur_sim_info->imsi1,
					SWVER_MAX_LEN, data->SWVER);
			}
			size = strlen(dm_sms_data + 4);
//			ASSERT (size <= XML_DATA_SIZE);

			dm_sms_data[0] = 3;
			dm_sms_data[1] = 3;
			dm_sms_data[2] = size;
			dm_sms_data[3] = 0;
			size += 4;

			CTDM_LOG("[DM] sim1 register info:\n");
			CTDM_LOG("[DM] model:%s \n", data->MODEL);
			CTDM_LOG("[DM] imei1:%s \n", CMID_NwGetImei(CMID_SIM_0));
			if (0 == with_no_imei2_flag) {
				CTDM_LOG("[DM] imei2:%s \n", CMID_NwGetImei(CMID_SIM_1));
			}
			CTDM_LOG("[DM] imsi1:%s \n", cur_sim_info->imsi1);
			CTDM_LOG("[DM] swver:%s \n", data->SWVER);

			ret = myBlockSendSmsReq((char *)data->SMS_DM_CENTER, dm_sms_data, size, 0, 1);
			if (ret) {
				CTDM_LOG("[DM] sim1 registered successful!\n");
				// update the NV
				update_nv_cnt++;
				strcpy(dm_nv_record->IMSI1, cur_sim_info->imsi1);
				if (0 == cur_sim_info->sim2_flag &&
					0 == strcmp(dm_nv_record->IMSI2, cur_sim_info->imsi1)) {
					strcpy(dm_nv_record->IMSI2, IMSI_WITH_NO_SIM_INSTRTED);
				}
			} else {
				CTDM_LOG("[DM] sim1 registered failed!\n");
			}
		}
	}

	if (cur_sim_info->sim2_flag && cur_sim_info->sim2_type == CHINA_TELECOM_LTE) {
#ifdef DM_VERSION_1
#else
		if (!CMID_NwIsVolteRegistered(CMID_SIM_1)) {
			CTDM_LOG("[DM] sim2 is not registered in volte net, exit DM module!\n");
			return NO_REGISTER_REQUIRED;
		}
#endif

		if (strcmp(dm_nv_record->IMSI2, cur_sim_info->imsi2)) {
			CTDM_LOG("[DM] sim2 to be registered!\n");
			register_cnt++;
			memset(dm_sms_data, 0x0, 256);
			sprintf(dm_sms_data + 4, DM_SMS_XML_FORMAT,
				MODEL_MAX_LEN, data->MODEL,
				IMEI_MAX_LEN, CMID_NwGetImei(CMID_SIM_0),
				IMEI_MAX_LEN, CMID_NwGetImei(CMID_SIM_1),
				IMSI_MAX_LEN, cur_sim_info->imsi2,
				SWVER_MAX_LEN, data->SWVER);

			size = strlen(dm_sms_data + 4);
//			ASSERT (size <= XML_DATA_SIZE);

			dm_sms_data[0] = 3;
			dm_sms_data[1] = 3;
			dm_sms_data[2] = size;
			dm_sms_data[3] = 0;
			size += 4;

			CTDM_LOG("[DM] sim2 register info:\n");
			CTDM_LOG("[DM] model:%s \n", data->MODEL);
			CTDM_LOG("[DM] imei1:%s \n", CMID_NwGetImei(CMID_SIM_0));
			CTDM_LOG("[DM] imei2:%s \n", CMID_NwGetImei(CMID_SIM_1));
			CTDM_LOG("[DM] imsi2:%s \n", cur_sim_info->imsi2);
			CTDM_LOG("[DM] swver:%s \n", data->SWVER);

			ret = myBlockSendSmsReq((char *)data->SMS_DM_CENTER, dm_sms_data, size, 1, 1);
			if (ret) {
				CTDM_LOG("[DM] sim2 registered successful!\n");
				// update the NV
				update_nv_cnt++;
				strcpy(dm_nv_record->IMSI2, cur_sim_info->imsi2);
				if (0 == cur_sim_info->sim1_flag &&
					0 == strcmp(dm_nv_record->IMSI1, cur_sim_info->imsi2)) {
					strcpy(dm_nv_record->IMSI1, IMSI_WITH_NO_SIM_INSTRTED);
				}
			} else {
				CTDM_LOG("[DM] sim2 registered failed!\n");
			}
		}
	}

	if (update_nv_cnt) {
		if (WriteRecord(get_dm_nv_id(), 0, dm_nv_record, sizeof(*dm_nv_record), &error) != sizeof(*dm_nv_record)) {
			CTDM_LOG("[DM] telecom SMS register write NV failed!\n", cnt);
			goto exit;
		}
	}

	if (register_cnt) {
		CTDM_LOG("[DM] telecom SMS registeration %d times!\n", cnt);

		if (register_cnt == update_nv_cnt) {
			CTDM_LOG("[DM] all sims registered successful!\n");
			return REGISTER_OK;
		}
		CTDM_LOG("[DM] one sim registered failed at least!\n");
	} else {
		CTDM_LOG("[DM] no sim need to be registered!\n");
		return NO_REGISTER_REQUIRED;
	}

exit:
	cnt++;

	return REGISTER_FAILED;
}

static int __wifi_telecom_dm(void)
{
	CTDM_LOG("[DM] not support TELECOM wifi DM fucntion!\n");
	return 3;
}

static void __telecom_package_post_data(cJSON * json)
{
	char sim1_flag = 0;
	char sim2_flag = 0;
	t_rtc rtc_time;
	char time_string[32] = { 0 };
	char cellid1[32] = {0};
	char cellid2[32] = {0};
	char sim1_type[16] = {0};
	char sim2_type[16] = {0};
	int data_sim_id;
	static int flag = 0;
	struct telecom_dm_register_data *data;

	data = init_telecom_dm_data();
	ASSERT(data != NULL);

	if (get_dm_demo_mode())
		goto fill_data_directly;

	sim1_flag = IsSimExist(0);
	sim2_flag = IsSimExist(1);

	// get MEID
	data->MEID	= CMID_NwGetMEID();
	// get DATASIM
	data_sim_id = CMID_GetDataSimCard();
	switch (data_sim_id) {
	case 0:
		data->DATASIM = "1";
		break;
	case 1:
		data->DATASIM = "2";
		break;
	default:
		break;
	}

	data->UETYPE = "1";
	// filled when wifi is supported
	data->MACID = "";
	// ACCESSTYPE 1:mobile data; 2:wifi;
	data->ACCESSTYPE = "1";

	if (sim1_flag) {
		// get IMEI1
		data->IMEI1 = CMID_NwGetImei(CMID_SIM_0);

		// get SIM1CELLID
		sprintf(cellid1, "%lu", CMID_NwGetCellid(CMID_SIM_0));
		data->SIM1CELLID = cellid1;

#ifdef DM_VERSION_1
		data->SIM1VoLTESW = "1";
		// to be implemented
		data->SIM1TYPE = "1";
#else
		if (CMID_NwIsVolteEnabled(CMID_SIM_0)) {
			data->SIM1VoLTESW = "1";
		} else {
			data->SIM1VoLTESW = "2";
		}
		sprintf(sim1_type, "%s", CMID_GetSimType(CMID_SIM_0));
		data->SIM1TYPE = sim1_type;
#endif

		// get SIM1ICCID
		data->SIM1ICCID = CMID_NwGetIccid(CMID_SIM_0);
		data->SIM1CDMAIMSI = "";
		data->SIM1LTEIMSI = CMID_NwGetImsi(CMID_SIM_0);

	}

	if (sim2_flag) {
		// get IMEI1
		data->IMEI2 = CMID_NwGetImei(CMID_SIM_1);

		// get SIM1CELLID
		sprintf(cellid2, "%lu", CMID_NwGetCellid(CMID_SIM_1));
		data->SIM2CELLID = cellid2;

#ifdef DM_VERSION_1
		data->SIM2VoLTESW = "1";
		// to be implemented
		data->SIM2TYPE = "1";
#else
		if (CMID_NwIsVolteEnabled(CMID_SIM_1)) {
			data->SIM2VoLTESW = "1";
		} else {
			data->SIM2VoLTESW = "2";
		}

		sprintf(sim2_type, "%s", CMID_GetSimType(CMID_SIM_1));
		data->SIM2TYPE = sim2_type;
#endif

		// get SIM1ICCID
		data->SIM2ICCID = CMID_NwGetIccid(CMID_SIM_1);
		data->SIM2CDMAIMSI = "";
		data->SIM2LTEIMSI = CMID_NwGetImsi(CMID_SIM_1);
	}

fill_data_directly:

	PMIC_RTC_GetTime(&rtc_time, SYS_OFFSET);
	// YYYY-MM-DD HH: MM: SS
	sprintf(time_string, "%04d-%02d-%02d %02d:%02d:%02d",
		rtc_time.tm_year, rtc_time.tm_mon, rtc_time.tm_mday,
		rtc_time.tm_hour, rtc_time.tm_min, rtc_time.tm_sec);
	data->REGDATE = time_string;

	cJSON_AddItemToObject(json, "REGVER", cJSON_CreateString(data->REGVER));
	cJSON_AddItemToObject(json, "MEID", cJSON_CreateString(data->MEID));
	cJSON_AddItemToObject(json, "MODEL", cJSON_CreateString(data->MODEL));
	cJSON_AddItemToObject(json, "SWVER", cJSON_CreateString(data->SWVER));
	cJSON_AddItemToObject(json, "UETYPE", cJSON_CreateString(data->UETYPE));
	cJSON_AddItemToObject(json, "MACID", cJSON_CreateString(data->MACID));
	cJSON_AddItemToObject(json, "OSVER", cJSON_CreateString(data->OSVER));
	cJSON_AddItemToObject(json, "ROM", cJSON_CreateString(data->ROM));
	cJSON_AddItemToObject(json, "RAM", cJSON_CreateString(data->RAM));
	cJSON_AddItemToObject(json, "DATASIM", cJSON_CreateString(data->DATASIM));
	cJSON_AddItemToObject(json, "ACCESSTYPE", cJSON_CreateString(data->ACCESSTYPE));
	cJSON_AddItemToObject(json, "REGDATE", cJSON_CreateString(time_string));
	cJSON_AddItemToObject(json, "MLPLVER", cJSON_CreateString(data->MLPLVER));
	cJSON_AddItemToObject(json, "MSPLVER", cJSON_CreateString(data->MSPLVER));
	cJSON_AddItemToObject(json, "MMEID", cJSON_CreateString(data->MMEID));
	cJSON_AddItemToObject(json, "IMEI1", cJSON_CreateString(data->IMEI1));
	cJSON_AddItemToObject(json, "SIM1CELLID", cJSON_CreateString(data->SIM1CELLID));
	cJSON_AddItemToObject(json, "SIM1VoLTESW", cJSON_CreateString(data->SIM1VoLTESW));
	cJSON_AddItemToObject(json, "SIM1TYPE", cJSON_CreateString(data->SIM1TYPE));
	cJSON_AddItemToObject(json, "SIM1CDMAIMSI", cJSON_CreateString(data->SIM1CDMAIMSI));
	cJSON_AddItemToObject(json, "SIM1LTEIMSI", cJSON_CreateString(data->SIM1LTEIMSI));
	cJSON_AddItemToObject(json, "SIM1ICCID", cJSON_CreateString(data->SIM1ICCID));
	cJSON_AddItemToObject(json, "IMEI2", cJSON_CreateString(data->IMEI2));
	cJSON_AddItemToObject(json, "SIM2CELLID", cJSON_CreateString(data->SIM2CELLID));
	cJSON_AddItemToObject(json, "SIM2VoLTESW", cJSON_CreateString(data->SIM2VoLTESW));
	cJSON_AddItemToObject(json, "SIM2TYPE", cJSON_CreateString(data->SIM2TYPE));
	cJSON_AddItemToObject(json, "SIM2CDMAIMSI", cJSON_CreateString(data->SIM2CDMAIMSI));
	cJSON_AddItemToObject(json, "SIM2LTEIMSI", cJSON_CreateString(data->SIM2LTEIMSI));
	cJSON_AddItemToObject(json, "SIM2ICCID", cJSON_CreateString(data->SIM2ICCID));

	if (1 == flag)
		return;

	flag = 1;

	CTDM_LOG("[DM] TELECOM http register info:\n");
	CTDM_LOG("[DM] REGDATE: %s \n", data->REGDATE);
	CTDM_LOG("[DM] MEID: %s \n", data->MEID);
	CTDM_LOG("[DM] MODEL: %s \n", data->MODEL);
	CTDM_LOG("[DM] SWVER: %s \n", data->SWVER);
	CTDM_LOG("[DM] UETYPE: %s \n", data->UETYPE);
	CTDM_LOG("[DM] MACID: %s \n", data->MACID);
	CTDM_LOG("[DM] OSVER: %s \n", data->OSVER);
	CTDM_LOG("[DM] ROM: %s \n", data->ROM);
	CTDM_LOG("[DM] RAM: %s \n", data->RAM);
	CTDM_LOG("[DM] DATASIM: %s \n", data->DATASIM);
	CTDM_LOG("[DM] ACCESSTYPE: %s \n", data->ACCESSTYPE);
	CTDM_LOG("[DM] REGDATE: %s \n", time_string);
	CTDM_LOG("[DM] MLPLVER: %s \n", data->MLPLVER);
	CTDM_LOG("[DM] MSPLVER: %s \n", data->MSPLVER);
	CTDM_LOG("[DM] MMEID: %s \n", data->MMEID);

	CTDM_LOG("[DM] IMEI1: %s \n", data->IMEI1);
	CTDM_LOG("[DM] SIM1CELLID: %s \n", data->SIM1CELLID);
	CTDM_LOG("[DM] SIM1VoLTESW: %s \n", data->SIM1VoLTESW);
	CTDM_LOG("[DM] SIM1TYPE: %s \n", data->SIM1TYPE);
	CTDM_LOG("[DM] SIM1CDMAIMSI: %s \n", data->SIM1CDMAIMSI);
	CTDM_LOG("[DM] SIM1LTEIMSI: %s \n", data->SIM1LTEIMSI);
	CTDM_LOG("[DM] SIM1ICCID: %s \n", data->SIM1ICCID);

	CTDM_LOG("[DM] IMEI2: %s \n", data->IMEI2);
	CTDM_LOG("[DM] SIM2CELLID: %s \n", data->SIM2CELLID);
	CTDM_LOG("[DM] SIM2VoLTESW: %s \n", data->SIM2VoLTESW);
	CTDM_LOG("[DM] SIM2TYPE: %s \n", data->SIM2TYPE);
	CTDM_LOG("[DM] SIM2CDMAIMSI: %s \n", data->SIM2CDMAIMSI);
	CTDM_LOG("[DM] SIM2LTEIMSI: %s \n", data->SIM2LTEIMSI);
	CTDM_LOG("[DM] SIM2ICCID: %s \n", data->SIM2ICCID);

	return;
}

static char *response_data = NULL;
static int response_len = 0;
/*
data: the data is received http context data
len: the length of http context data
num: the http response header "Content-Length" value
cbdata: user private data
*/
static void response_cb(char *data, int len, int num, void *cbdata)
{
	char *temp;
	char *private_data = (char *)cbdata;

	CTDM_LOG("[DM]Get private_data %s", private_data);

	CTDM_LOG("[DM]Get data %d", len);

	temp = UI_MALLOC(response_len + len);
	if (!temp) {

		CTDM_LOG("[DM]Malloc failed...");
		return;
	}
	memset(temp, 0, response_len + len);
	if (response_data) {
		memcpy(temp, response_data, response_len);
		UI_FREE(response_data);
	}
	memcpy(&temp[response_len], data, len);
	response_data = temp;
	response_len += len;
}

/*
 * return:
 * 0: registered failed
 * 1: registered successful
 */
static int __http_client_telecom_register(void)
{
	int response_code;
	char *post_buf = NULL;
	int base64_buf_len = 0;
	char *base64_buf = NULL;
	cJSON *json = NULL;
	int http_count = 0;
	int i;
	int ret = 0;

	struct http_client *client = NULL;
	struct http_client_list *header = NULL;
	struct telecom_dm_register_data *data;

	data = init_telecom_dm_data();
	ASSERT(data != NULL);

	CTDM_LOG("[DM] http start\n");

	json = cJSON_CreateObject();
	__telecom_package_post_data(json);
	post_buf = cJSON_Print(json);
	cJSON_Delete(json);

	base64_buf_len = strlen(post_buf) * 2;
	base64_buf = UI_MALLOC(base64_buf_len);
	memset(base64_buf, 0x0, base64_buf_len);
	dm_base64_encode(post_buf, strlen(post_buf), base64_buf);

	client = http_client_init();

	while (1) {
		http_count++;
		if (http_count >= 5) {
			CTDM_LOG("[DM] time out=%d\n", http_count);
			break;
		}

		UOS_SleepSeconds(10);
		CTDM_LOG("[DM] HTTP register url: %s\n", data->HTTP_DM_CENTER);
//		http_client_setopt(client, HTTPCLIENT_OPT_URL, "http://zzhc.vnet.cn");
		http_client_setopt(client, HTTPCLIENT_OPT_URL, data->HTTP_DM_CENTER);
		http_client_setopt(client, HTTPCLIENT_OPT_HTTP1_0, 0);	/*"0" is HTTP 1.1, "1" is HTTP 1.0 */
		http_client_setopt(client, HTTPCLIENT_OPT_RESPONSECB, response_cb);	/*response callback */
		http_client_setopt(client, HTTPCLIENT_OPT_METHOD, HTTPCLIENT_REQUEST_POST);	/*set method,support GET/POST/PUT */
		http_client_setopt(client, HTTPCLIENT_OPT_POSTDATA, base64_buf);	/*post data is http context */
		http_client_setopt(client, HTTPCLIENT_OPT_POSTLENGTH, strlen(base64_buf));	/*http context length */
#ifdef USER_PRIVATE_HEADER
		header =http_client_list_append(header,"Content-Type=application/encrypted-json\r\n");
#endif
		/*set http private header,our http stack already support Referer/Host/Authorization/User-Agent/Connection/cookie/Content-Length,
		   this header is other http header,ex: Content-Type..., we call it private header, */
		http_client_setopt(client, HTTPCLIENT_OPT_HTTPHEADER, header);

		http_client_getinfo(client, HTTPCLIENT_GETINFO_TCP_STATE, &response_code);

		CTDM_LOG("[DM] Get tcp state %d\n", response_code);

		if (response_code != HTTP_TCP_ESTABLISHED) {
			CTDM_LOG("[DM] http tcp not connecting\n");
			http_client_shutdown(client);	/*release http resources */
			client = http_client_init();
			continue;
		}

		response_code = http_client_perform(client);	/*execute http send and recv */
		if (response_code != HTTP_CLIENT_OK) {
			CTDM_LOG("[DM] http perform have some wrong[%d]\n",response_code);
			http_client_shutdown(client);	/*release http resources */
			client = http_client_init();
			continue;
		}

		http_client_getinfo(client, HTTPCLIENT_GETINFO_RESPONSE_CODE, &response_code);

		CTDM_LOG("[DM] response is  'HTTP OK'(%d)\n", response_code);
		if (response_code == 200) {
			CTDM_LOG("[DM] SUCCESS\n");
			CTDM_LOG("[DM] rs1:%s\n", response_data);

			/* successful registered response string:
			 * {"resultCode": "0","resultDesc": "Success"}
			 *
			 */
			for (i = 0; i < strlen(response_data); i++) {
				if (response_data[i] == 'S' || response_data[i] == 's') {
					if (0 == strncmp(response_data + i, "Success", strlen("Success")))
						ret = 1;
					if (0 == strncmp(response_data + i, "success", strlen("success")))
						ret = 1;
				}
			}

			if (ret) {
				CTDM_LOG("[DM] http registered successful!\n");
			} else {
				CTDM_LOG("[DM] http registered failed!\n");
			}

			if (response_data)
				UI_FREE(response_data);
			response_data = NULL;
			response_len = 0;

			break;
		}

		CTDM_LOG("[DM] Get total data %d\n", response_len);
		CTDM_LOG("[DM]rs2:%s\n", response_data);
		if (response_data)
			UI_FREE(response_data);
		response_data = NULL;
		response_len = 0;

#ifdef USER_PRIVATE_HEADER
		// Free private HTTP header
		if (header) {
			http_client_list_destroy(header);
			header = NULL;
		}
#endif
		break;
	}

	if (post_buf != NULL) {
		UI_FREE(post_buf);
		post_buf = NULL;
	}

	http_client_shutdown(client);	/*release http resources */
	CTDM_LOG("[DM] http register finish!\n");

	return ret;
}

/* return:
 * 0: register failed
 * 1: register successful
 * 2: no need to register
 * 3: register times reached the limit
 */
static int __http_telecom_dm(void)
{
	static int cnt = 1;
	static int init_flag = 0;
	static int register_flag = 0;
	s16 error = 0;
	int data_sim_id;

	struct sim_info *cur_sim_info = get_current_sim_info();
	struct dm_register_record *dm_nv_record = get_current_dm_record();

	if (0 == init_flag) {
		if (cur_sim_info->sim1_flag) {
			if (strcmp(dm_nv_record->UEICCID1, cur_sim_info->iccid1)) {
				CTDM_LOG("[DM] sim1 to be registered!\n");
				register_flag++;
			}
		}

		if (cur_sim_info->sim2_flag) {
			if (strcmp(dm_nv_record->UEICCID2, cur_sim_info->iccid2)) {
				CTDM_LOG("[DM] sim2 to be registered!\n");
				register_flag++;
			}
		}

		if (0 == register_flag) {
			CTDM_LOG("[DM] all sims are registered already, exit telecom DM function!\n");
		}
#ifdef DM_VERSION_1
#else
		// fixme
		if (CMID_IsRoaming(CMID_SIM_0) || CMID_IsRoaming(CMID_SIM_1)) {
			register_flag = 0;
			CTDM_LOG("[DM] international romaing status, exit telecom DM function!\n");
		}
#endif
		init_flag = 1;
	}

	if (0 == register_flag)
		return NO_REGISTER_REQUIRED;

	if (cnt > TELECOM_DATA_DM_LIMIT)
		return REGISTER_LIMITED_REACHED;

	data_sim_id = CMID_GetDataSimCard();
	if (0 == data_sim_id) {
		if (cur_sim_info->sim1_type != CHINA_TELECOM_LTE) {
			// do wifi DM fucntion
			// __wifi_telecom_dm();
			CTDM_LOG("[DM] (do wifi DM)exit TELECOM DM fucntion\n");
			return NO_REGISTER_REQUIRED;
		}
	}

	if (1 == data_sim_id) {
		if (cur_sim_info->sim2_type != CHINA_TELECOM_LTE) {
			// do wifi DM fucntion
			// __wifi_telecom_dm();
			CTDM_LOG("[DM] (do wifi DM)exit TELECOM DM fucntion\n");
			return NO_REGISTER_REQUIRED;
		}
	}

	if (!CMID_IsDataConnectOK()) {
		CTDM_LOG("[DM] data connection error, skipping ......!\n");
		goto exit;
	}

	CTDM_LOG("[DM] TELECOM http register %d times!\n", cnt);
	if (__http_client_telecom_register()) {
		CTDM_LOG("[DM] TELECOM http register successful!\n");
		// update NV record when registered successful
		strcpy(dm_nv_record->UEICCID1, cur_sim_info->iccid1);
		strcpy(dm_nv_record->UEICCID2, cur_sim_info->iccid2);

		if (WriteRecord(get_dm_nv_id(), 0, dm_nv_record, sizeof(*dm_nv_record), &error) != sizeof(*dm_nv_record)) {
			CTDM_LOG("[DM] TELECOM http register write NV failed!\n", cnt);
			goto exit;
		}
		return REGISTER_OK;
	} else {
		CTDM_LOG("[DM] TELECOM http register failed!\n");
	}

exit:
	cnt++;
	return REGISTER_FAILED;
}

int do_telecom_dm()
{
	int ret = NO_REGISTER_REQUIRED;
	u32 sleep_time;
	static u8 timer_id = INVALID_TIMER_ID;

	if (DM_DATA_MODE == get_telecom_dm_mode()) {
		CTDM_LOG("[DM] telecom http DM register\n");
		sleep_time = TELECOM_DATA_DM_INTERVAL;
		ret = __http_telecom_dm();
	}

	if (DM_SMS_MODE == get_telecom_dm_mode()) {
		CTDM_LOG("[DM] telecom SMS DM register\n");
		sleep_time = TELECOM_SMS_DM_INTERVAL;
		ret = __sms_telecom_dm();
	}

	switch (ret) {
	case REGISTER_FAILED:
		if (timer_id == INVALID_TIMER_ID) {
			timer_id = UOS_get_FunctionTimer();
		}
		UOS_StartFunctionTimer_single(
			timer_id, MS_TO_TICKS(sleep_time * 1000), send_dm_event, (void*)TELECOM_DM_REQUEST, "telecom_dm");
		break;

	case REGISTER_OK:
	case NO_REGISTER_REQUIRED:
	case REGISTER_LIMITED_REACHED:
		if (timer_id != INVALID_TIMER_ID) {
			UOS_KillFunctionTimer(timer_id);
			timer_id = INVALID_TIMER_ID;
		}
		break;

	default:
		break;
	}

	return ret;
}
