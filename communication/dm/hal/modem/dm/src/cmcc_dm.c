#include "app_target_defs.h"
#include "plat_types.h"
#include "fs_api.h"
#include "nvram_api.h"
#include "nw_api.h"
#include "cus_dm_register_def.h"

#include "libhttpclient.h"
#include "httpclient_sys.h"

#include "dm_register.h"

#include "cJSON.h"
#include "aes.h"


#define CMCC_DATA_DM_LIMIT 3
#define CMCC_DATA_DM_INTERVAL 600

extern struct cmcc_dm_register_data *init_cmcc_dm_data(void);

extern unsigned int time(unsigned int *p);
static void __cmcc_package_post_data(cJSON * json)
{
	char sim1_flag = 0;
	char sim2_flag = 0;
	char time_string[32] = { 0 };
	unsigned long long time_stamp;
	char cellid1[32] = {0x0};
	char cellid2[32] = {0x0};
	char lac1[32] = {0x0};
	char lac2[32] = {0x0};
	static int flag = 0;

	struct cmcc_dm_register_data *data;
	data = init_cmcc_dm_data();
	ASSERT(data != NULL);

	if (get_dm_demo_mode())
		goto fill_data_directly;

	sim1_flag = IsSimExist(0);
	sim2_flag = IsSimExist(1);

	// get MEID
//	data->meid = CMID_NwGetMEID();
	data->meid = "";
	// fixme, no mac number
	data->deviceId = CMID_NwGetImei(CMID_SIM_0);

	// get DATASIM
	if (0 == CMID_GetDataSimCard()) {
		data->masterStatus = "0";
	}

	if (1 == CMID_GetDataSimCard()) {
		data->masterStatus = "1";
	}

	data->type = "1";
	data->soltQuantity = "2";
	// fixme
	data->channel = "4G";

	// get IMEI1
	data->imei1 = CMID_NwGetImei(CMID_SIM_0);
	// get IMEI1
	data->imei2 = CMID_NwGetImei(CMID_SIM_1);

	if (sim1_flag) {
		data->imsi1 = CMID_NwGetImsi(CMID_SIM_0);
		// get SIM1CELLID
		sprintf(cellid1, "%lu", CMID_NwGetCellid(CMID_SIM_0));
		data->cellId = cellid1;
		// get SIM1ICCID
		data->iccid1 = CMID_NwGetIccid(CMID_SIM_0);
		sprintf(lac1, "%lu", CMID_NwGetLac(CMID_SIM_0));
		data->lac = lac1;
		// fixme
		if (0 ==  CMID_GetDataSimCard()) {
			data->dataCard = "2";
		} else {
			data->dataCard = "0";
		}
		// fixme
		data->soltService1 = "5";
		// fixme
		data->soltNetWork1 = "13";
	} else {
		data->soltService1 = "1";
	}

	if (sim2_flag) {
		data->imsi2 = CMID_NwGetImsi(CMID_SIM_1);
		// get SIM1CELLID
		sprintf(cellid2, "%lu", CMID_NwGetCellid(CMID_SIM_1));
		data->cellId2 = cellid2;
		// get SIM1ICCID
		data->iccid2 = CMID_NwGetIccid(CMID_SIM_1);
		sprintf(lac2, "%lu", CMID_NwGetLac(CMID_SIM_1));
		data->lac2 = lac2;

		if (1 ==  CMID_GetDataSimCard()) {
			data->dataCard2 = "2";
		} else {
			data->dataCard2 = "0";
		}
		// fixme
		data->soltService2 = "5";
		data->soltNetWork2 = "13";
	} else {
		data->soltService2 = "1";
	}

fill_data_directly:

	time_stamp = time(NULL);
	time_stamp = time_stamp * 1000;
	sprintf(time_string, "%llu", time_stamp);
	data->sendTime = time_string;

	cJSON_AddItemToObject(json, "sdkVersion", cJSON_CreateString(data->sdkVersion));
	cJSON_AddItemToObject(json, "imei1", cJSON_CreateString(data->imei1));
	cJSON_AddItemToObject(json, "imei2", cJSON_CreateString(data->imei2));
	// set meid="" if do not support CDMA
	cJSON_AddItemToObject(json, "meid", cJSON_CreateString(data->meid));
	// do not support wifi
	cJSON_AddItemToObject(json, "deviceId", cJSON_CreateString(data->deviceId));
	cJSON_AddItemToObject(json, "brand", cJSON_CreateString(data->brand));
	cJSON_AddItemToObject(json, "model", cJSON_CreateString(data->model));
	cJSON_AddItemToObject(json, "firmwareVer", cJSON_CreateString(data->firmwareVer));
	cJSON_AddItemToObject(json, "systemVer", cJSON_CreateString(data->systemVer));
	cJSON_AddItemToObject(json, "cpu", cJSON_CreateString(data->systemVer));
	cJSON_AddItemToObject(json, "rom", cJSON_CreateString(data->rom));
	cJSON_AddItemToObject(json, "ram", cJSON_CreateString(data->ram));
	// phone DEVICE_TYPE_CELLPHONE
	cJSON_AddItemToObject(json, "type", cJSON_CreateString(data->type));
	cJSON_AddItemToObject(json, "iccid1", cJSON_CreateString(data->iccid1));
	cJSON_AddItemToObject(json, "iccid2", cJSON_CreateString(data->iccid2));
	cJSON_AddItemToObject(json, "imsi1", cJSON_CreateString(data->imsi1));
	cJSON_AddItemToObject(json, "imsi2", cJSON_CreateString(data->imsi2));
	cJSON_AddItemToObject(json, "mac", cJSON_CreateString(data->mac));
	cJSON_AddItemToObject(json, "cellId", cJSON_CreateString(data->cellId));
	// fixme
	cJSON_AddItemToObject(json, "channel", cJSON_CreateString(data->channel));
	// fixme
	cJSON_AddItemToObject(json, "dataCard", cJSON_CreateString(data->dataCard));
	// fixme
	cJSON_AddItemToObject(json, "masterStatus", cJSON_CreateString(data->masterStatus));
	// fixme
	cJSON_AddItemToObject(json, "sendTime", cJSON_CreateString(data->sendTime));
	cJSON_AddItemToObject(json, "soltQuantity", cJSON_CreateString(data->soltQuantity));

	cJSON_AddItemToObject(json, "dataCard2", cJSON_CreateString(data->dataCard2));
	cJSON_AddItemToObject(json, "soltService1", cJSON_CreateString(data->soltService1));
	cJSON_AddItemToObject(json, "soltService2", cJSON_CreateString(data->soltService2));
	cJSON_AddItemToObject(json, "soltQuantity", cJSON_CreateString(data->soltQuantity));
	cJSON_AddItemToObject(json, "soltNetwork1", cJSON_CreateString(data->soltNetWork1));
	cJSON_AddItemToObject(json, "soltNetwork2", cJSON_CreateString(data->soltNetWork2));
	cJSON_AddItemToObject(json, "lac2", cJSON_CreateString(data->lac2));
	cJSON_AddItemToObject(json, "cellId2", cJSON_CreateString(data->cellId2));

	if (1 == flag)
		return;

	flag = 1;

	CTDM_LOG("[DM] CMMC https register info	:\n");
	CTDM_LOG("[DM] sdkVersion :%s\n", data->sdkVersion);
	CTDM_LOG("[DM] imei1 :%s\n", data->imei1);
	CTDM_LOG("[DM] imei2 :%s\n", data->imei2);
	CTDM_LOG("[DM] meid :%s\n", data->meid);
	CTDM_LOG("[DM] deviceId :%s\n", data->deviceId);
	CTDM_LOG("[DM] brand :%s\n", data->brand);
	CTDM_LOG("[DM] model :%s\n", data->model);
	CTDM_LOG("[DM] firmwareVer :%s\n", data->firmwareVer);
	CTDM_LOG("[DM] systemVer :%s\n", data->systemVer);
	CTDM_LOG("[DM] cpu :%s\n", data->cpu);
	CTDM_LOG("[DM] rom :%s\n", data->rom);
	CTDM_LOG("[DM] ram :%s\n", data->ram);
	CTDM_LOG("[DM] type	:%s\n", data->type);
	CTDM_LOG("[DM] iccid1 :%s\n", data->iccid1);
	CTDM_LOG("[DM] iccid2 :%s\n", data->iccid2);
	CTDM_LOG("[DM] imsi1 :%s\n", data->imsi1);
	CTDM_LOG("[DM] imsi2 :%s\n", data->imsi2);
	CTDM_LOG("[DM] mac :%s\n", data->mac);
	CTDM_LOG("[DM] cellId :%s\n", data->cellId);
	CTDM_LOG("[DM] lac :%s\n", data->lac);
	CTDM_LOG("[DM] channel :%s\n", data->channel);
	CTDM_LOG("[DM] dataCard :%s\n", data->dataCard);
	CTDM_LOG("[DM] masterStatus :%s\n", data->masterStatus);
	CTDM_LOG("[DM] sendTime :%s\n", data->sendTime);
	CTDM_LOG("[DM] soltQuantity :%s\n", data->soltQuantity);
	CTDM_LOG("[DM] dataCard2 :%s\n", data->dataCard2);
	CTDM_LOG("[DM] soltService1 :%s\n", data->soltService1);
	CTDM_LOG("[DM] soltService2 :%s\n", data->soltService2);
	CTDM_LOG("[DM] soltNetWork1 :%s\n", data->soltNetWork1);
	CTDM_LOG("[DM] soltNetWork2 :%s\n", data->soltNetWork2);
	CTDM_LOG("[DM] lac2 :%s\n", data->lac2);
	CTDM_LOG("[DM] cellId2 :%s \n", data->cellId2);

	return;
}

#define ALIGN_UP(x, align)      (((x) + (align) - 1) & ~((align) - 1))

extern int AesEcb(int mode, const unsigned char *key, const unsigned char input[16], unsigned char output[16]);

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

#define USER_PRIVATE_HEADER

static int __https_client_cmcc_register(void)
{
	int response_code;
	char *post_buf = NULL;
	char *aes_buf = NULL;
	unsigned int aes_buf_len;

	int base64_buf_len = 0;
	char *base64_buf = NULL;

	cJSON *json = NULL;

	struct http_client *client = NULL;
	struct http_client_list *header = NULL;

	int http_count = 0;
	int i;
	int ret = 0;

	char url_str[256];
	// fuc: 20 bytes, appkey: 32 bytes
	char request_options[64];

	struct cmcc_dm_register_data *data;

	data = init_cmcc_dm_data();
	ASSERT(data != NULL);

	CTDM_LOG("[DM] CMCC https register start\n");

	memset(url_str, 0x0, 256);
	memset(request_options, 0x0, 64);
	// create the request line
	strcpy(url_str, data->httpsUrl);
	url_str[strlen(url_str)] = '?';
	sprintf(request_options, "func=tsdk:postotherreg&appkey=%s", data->appKey);

	CTDM_LOG("[DM] https url1: %s\n", url_str);
	CTDM_LOG("[DM] request option %s\n", request_options);

	base64_buf_len = strlen(request_options) * 2;
	base64_buf = malloc(base64_buf_len);
	memset(base64_buf, 0x0, base64_buf_len);
	dm_base64_encode(request_options, strlen(request_options), base64_buf);
	strcpy(url_str + strlen(url_str), base64_buf);
	CTDM_LOG("[DM] https url2: %s\n", url_str);

	json = cJSON_CreateObject();
	__cmcc_package_post_data(json);
	post_buf = cJSON_Print(json);
	cJSON_Delete(json);

	aes_buf_len = strlen(post_buf);
	aes_buf_len = ALIGN_UP(aes_buf_len, 16);
	aes_buf = UI_MALLOC(aes_buf_len);
	if (!aes_buf) {
		ASSERT(0);
	}
	memset(aes_buf, 0x0, aes_buf_len);
	strcpy(aes_buf, post_buf);

	for (i = 0; i < strlen(post_buf); i += 16) {
		AesEcb(AES_ENCRYPT, data->aesKey, aes_buf + i, aes_buf + i);
	}

	client = http_client_init();

	while (1) {
		http_count++;
		if (http_count >= 5) {
			CTDM_LOG("[DM] time out=%d\n", http_count);
			break;
		}

		UOS_SleepSeconds(10);
#if 0
		http_client_setopt(client, HTTPCLIENT_OPT_URL, "http://zzhc.vnet.cn");
#else
		CTDM_LOG("[DM] HTTPS register url: %s\n", url_str);
		http_client_setopt(client, HTTPCLIENT_OPT_URL, url_str);
#endif
		http_client_setopt(client, HTTPCLIENT_OPT_HTTP1_0, 0);	/*"0" is HTTP 1.1, "1" is HTTP 1.0 */
		http_client_setopt(client, HTTPCLIENT_OPT_RESPONSECB, response_cb); /*response callback */
		http_client_setopt(client, HTTPCLIENT_OPT_METHOD, HTTPCLIENT_REQUEST_POST); /*set method,support GET/POST/PUT */
#if 0
		http_client_setopt(client, HTTPCLIENT_OPT_POSTDATA, base64_buf);	/*post data is http context */
		http_client_setopt(client, HTTPCLIENT_OPT_POSTLENGTH, strlen(base64_buf));	/*http context length */
#else
		http_client_setopt(client, HTTPCLIENT_OPT_POSTDATA, aes_buf);	/*post data is http context */
		http_client_setopt(client, HTTPCLIENT_OPT_POSTLENGTH, aes_buf_len);	/*http context length */
#endif
#ifdef USER_PRIVATE_HEADER
		header =http_client_list_append(header,"Content-Type=application/json;charset=utf-8\r\n");
#endif
		/*set http private header,our http stack already support Referer/Host/Authorization/User-Agent/Connection/cookie/Content-Length,
		   this header is other http header,ex: Content-Type..., we call it private header, */
		http_client_setopt(client, HTTPCLIENT_OPT_HTTPHEADER, header);

		http_client_getinfo(client, HTTPCLIENT_GETINFO_TCP_STATE, &response_code);

		CTDM_LOG("[DM] Get tcp state %d\n", response_code);

		if (response_code != HTTP_TCP_ESTABLISHED) {
			CTDM_LOG("[DM] https tcp not connecting\n");
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

		CTDM_LOG("[DM] response is	'HTTP OK'(%d)\n", response_code);
		if (response_code == 200) {
			CTDM_LOG("[DM] SUCCESS\n");
			CTDM_LOG("[DM] rs1:%s\n", response_data);
#if 0
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
#endif
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

//	raw_uart_log("zzinfo 1!\n");

	if (post_buf != NULL) {
		UI_FREE(post_buf);
		post_buf = NULL;
	}

//	raw_uart_log("zzinfo 2!\n");

	if (aes_buf != NULL) {
		UI_FREE(aes_buf);
		aes_buf = NULL;
	}

//	raw_uart_log("zzinfo 3!\n");

//	raw_uart_log("zzinfo 1 %x!\n", client);
	http_client_shutdown(client);	/*release http resources */
//	raw_uart_log("zzinfo 2!\n");

	CTDM_LOG("[DM] FINISH\n");

	return ret;

}

static int __https_cmcc_dm(void)
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
			CTDM_LOG("[DM] all sim are registered already, exit cmcc DM function!\n");
		}

#ifdef DM_VERSION_1
#else
		// fixme
		if (CMID_IsRoaming(CMID_SIM_0) || CMID_IsRoaming(CMID_SIM_1)) {
			register_flag = 0;
			CTDM_LOG("[DM] international romaing status, exit CMCC DM function!\n");
		}
#endif
		init_flag = 1;
	}

	if (0 == register_flag)
		return NO_REGISTER_REQUIRED;

	if (cnt > CMCC_DATA_DM_LIMIT)
		return REGISTER_LIMITED_REACHED;

	// register by wifi if wifi is enable
	data_sim_id = CMID_GetDataSimCard();
	if (0 == data_sim_id) {
		if (cur_sim_info->sim1_type != CHINA_MOBILE) {
			CTDM_LOG("[DM] (need wifi connection)exit CMCC DM fucntion\n");
			return NO_REGISTER_REQUIRED;
		}
	}

	if (1 == data_sim_id) {
		if (cur_sim_info->sim2_type != CHINA_MOBILE) {
			// do wifi DM fucntion
			CTDM_LOG("[DM] (need wifi connection)exit CMCC DM fucntion\n");
			return NO_REGISTER_REQUIRED;
		}
	}

	if (CMID_IsDataConnectOK()) {
		/*
		 * fixme, we need check the register info is valid
		 * 1. IMEI is not empty
		 * 2. IMSI and ICCID is valid
		 * 3. SIM card is useful
		 * 4. can get one cell-id at least
		 */
		CTDM_LOG("[DM] CMCC https register %d times!\n", cnt);
		if (__https_client_cmcc_register()) {
			CTDM_LOG("[DM] CMCC http register successful!\n");
			// update NV record
			strcpy(dm_nv_record->UEICCID1, cur_sim_info->iccid1);
			strcpy(dm_nv_record->UEICCID2, cur_sim_info->iccid2);

			if (WriteRecord(get_dm_nv_id(), 0, dm_nv_record, sizeof(*dm_nv_record), &error) != sizeof(*dm_nv_record)) {
				CTDM_LOG("[DM] CMCC https register write NV failed!\n", cnt);
				goto exit;
			}
			return REGISTER_OK;
		} else {
			CTDM_LOG("[DM] CMCC http register failed!\n");
		}
	} else {
		CTDM_LOG("[DM] data connection error, skipping ......!\n");
	}

exit:

	cnt++;
	return REGISTER_FAILED;
}

int do_cmcc_dm()
{
	int ret = NO_REGISTER_REQUIRED;
	u32 sleep_time;
	static u8 timer_id = INVALID_TIMER_ID;

	if (DM_DATA_MODE == get_cmcc_dm_mode()) {
		CTDM_LOG("[DM] cmcc https DM register\n");
		sleep_time = CMCC_DATA_DM_INTERVAL;
		ret = __https_cmcc_dm();
	}

	switch (ret) {
	case REGISTER_FAILED:
		if (timer_id == INVALID_TIMER_ID) {
			timer_id = UOS_get_FunctionTimer();
		}
		UOS_StartFunctionTimer_single(
			timer_id, MS_TO_TICKS(sleep_time * 1000), send_dm_event, (void*)CMCC_DM_REQUEST, "cmcc_dm");
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
