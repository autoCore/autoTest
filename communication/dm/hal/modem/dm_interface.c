#include "cus_dm_register_def.h"

#include "app_target_defs.h"
#include "plat_types.h"
#include "fs_api.h"

#include "nvram_api.h"
#include "nvram_data_items.h"
#include "nvram_user_defs.h"




#ifdef TELECOM_DM_MODE_CONFIG
struct telecom_dm_register_data * init_telecom_dm_data(void)
{
	static int flag = 0;
	// init 32 element with ""
	static struct telecom_dm_register_data dm_data = {
		"", "", "", "", "", "", "", "",
		"", "", "", "", "", "", "", "",
		"", "", "", "", "", "", "", "",
		"", "", "", "", "", "", "", "",
	};

	if (1 == flag)
		return &dm_data;

	flag = 1;

#ifdef DM_DEMO_CODE

#if TELECOM_DM_MODE_CONFIG == DM_SMS_MODE
	dm_data.SMS_DM_CENTER = TELECOM_DM_SMS_CENTER;
	dm_data.MODEL	= "ZXJ-angelcare K199";
	dm_data.SWVER	= "AngelCare.K199.YUN.T3.20";
	dm_data.SMS_DM_NO_IMEI2_FLAG = "0";
#endif

#if TELECOM_DM_MODE_CONFIG == DM_DATA_MODE
	dm_data.REGVER	= "8.0";
	dm_data.MEID	= "362523432430497";
	dm_data.MODEL	= "ZXJ-angelcare K199";
	dm_data.SWVER	= "AngelCare.K199.YUN.T3.20";
	dm_data.OSVER	= "Android4.4.4";
	dm_data.UETYPE	= "1";
	dm_data.MACID	= "40:45:da:c5:2b:7b";
	dm_data.DATASIM 	= "1";
	dm_data.ROM = "16M";
	dm_data.RAM = "16M";
	dm_data.ACCESSTYPE	= "1";
	dm_data.REGDATE = "";

	dm_data.IMEI1	= "362523432430497";
	dm_data.SIM1CELLID	= "102091276";
	dm_data.SIM1CDMAIMSI	= "";
	dm_data.SIM1LTEIMSI = "460013414935109";
	dm_data.SIM1ICCID	= "89860118803508444251";
	dm_data.SIM1VoLTESW = "";
	dm_data.SIM1TYPE	= "";

	dm_data.IMEI2	= "362523432430505";
	dm_data.SIM2CELLID	= "124843264";
	dm_data.SIM2CDMAIMSI	= "";
	dm_data.SIM2LTEIMSI = "460110914390871";
	dm_data.SIM2ICCID	= "89860318747558971510";

	dm_data.SIM2VoLTESW = "" ;
	dm_data.SIM2TYPE	= "";
	dm_data.MLPLVER = "";
	dm_data.MSPLVER = "";
	dm_data.HTTP_DM_CENTER = TELECOM_DM_HTTP_CENTER;

#endif

#else

#if TELECOM_DM_MODE_CONFIG == DM_SMS_MODE
	dm_data.MODEL = KEY_MODEL;
	dm_data.SWVER = KEY_SWVER;
	dm_data.SMS_DM_CENTER = TELECOM_DM_SMS_CENTER;
#ifdef TELECOM_SMS_DM_SEND_NO_IMEI2
	dm_data.SMS_DM_NO_IMEI2_FLAG = "1";
#else
	dm_data.SMS_DM_NO_IMEI2_FLAG = "0";
#endif
#endif

#if TELECOM_DM_MODE_CONFIG == DM_DATA_MODE

	dm_data.REGVER = KEY_REGVER;
	dm_data.MODEL = KEY_MODEL;
	dm_data.SWVER = KEY_SWVER;
	dm_data.OSVER = KEY_OSVER;
	dm_data.ROM = KEY_ROM;
	dm_data.RAM = KEY_RAM;
	dm_data.HTTP_DM_CENTER = TELECOM_DM_HTTP_CENTER;

#endif

#endif
	return &dm_data;
}

#else

struct telecom_dm_register_data *init_telecom_dm_data(void)
{
	return NULL;
}

#endif

#ifdef CMCC_DM_MODE_CONFIG
struct cmcc_dm_register_data *init_cmcc_dm_data(void)
{
	static int flag = 0;
	// init 35 element with ""
	static struct cmcc_dm_register_data dm_data = {
		"", "", "", "", "", "", "", "",
		"", "", "", "", "", "", "", "",
		"", "", "", "", "", "", "", "",
		"", "", "", "", "", "", "",	"",
		"", "", "",
	};

	if (1 == flag)
		return &dm_data;

	flag = 1;

#ifdef DM_DEMO_CODE

#if CMCC_DM_MODE_CONFIG == DM_DATA_MODE
	dm_data.sdkVersion = "";
	dm_data.imei1 = "";
	dm_data.imei2 = "";
	dm_data.meid = "";
	dm_data.deviceId = "";
	dm_data.brand = "";
	dm_data.model = "";
	dm_data.firmwareVer = "";
	dm_data.systemVer = "";
	dm_data.cpu = "";
	dm_data.rom = "";
	dm_data.ram = "";
	dm_data.type = "";
	dm_data.iccid1 = "";
	dm_data.iccid2 = "";
	dm_data.imsi1 = "";
	dm_data.imsi2 = "";
	dm_data.mac = "";
	dm_data.cellId = "";
	dm_data.lac = "";
	dm_data.channel = "";
	dm_data.dataCard = "";
	dm_data.masterStatus = "";
	dm_data.sendTime = "";
	dm_data.soltQuantity = "";
	dm_data.dataCard2 = "";
	dm_data.soltService1 = "";
	dm_data.soltService2 = "";
	dm_data.soltNetWork1 = "";
	dm_data.soltNetWork2 = "";
	dm_data.lac2 = "";
	dm_data.cellId2 = "";

	dm_data.aesKey = "1111111111111111";
	dm_data.httpsUrl = "https://b.fxltsbl.com";
	dm_data.appKey = "aaaa12345";
#endif

#else

#if CMCC_DM_MODE_CONFIG == DM_DATA_MODE
	dm_data.sdkVersion = KEY_sdkVersion;
	dm_data.brand = KEY_brand;
	dm_data.model = KEY_model;
	dm_data.firmwareVer = KEY_firmwareVer;
	dm_data.systemVer = KEY_systemVer;
	dm_data.cpu = KEY_cpu;
	dm_data.ram = KEY_ram;
	dm_data.rom = KEY_rom;

	dm_data.aesKey = KEY_aesKey;
	dm_data.httpsUrl = KEY_httpsUrl;
	dm_data.appKey = KEY_appKey;
#endif
#endif

	return &dm_data;
}

#else

struct cmcc_dm_register_data *init_cmcc_dm_data(void)
{
	return NULL;
}

#endif

struct dm_register_config *get_dm_configuration(void)
{
	static struct dm_register_config dm_config = {0};
	static int flag = 0;

	if (0 == flag) {
#ifdef TELECOM_DM_MODE_CONFIG
		dm_config.telecom_dm_mode = TELECOM_DM_MODE_CONFIG;
#endif

#ifdef CMCC_DM_MODE_CONFIG
		dm_config.cmcc_dm_mode = CMCC_DM_MODE_CONFIG;
#endif

#ifdef  UNICOM_DM_MODE_CONFIG
		dm_config.unicom_dm_mode = UNICOM_DM_MODE_CONFIG;
#endif

#ifdef DM_DEMO_CODE
		dm_config.demo_mode = 1;
#endif
		dm_config.dm_nv_id = NVRAM_DM_REGISTER_STATUS;
		raw_uart_log("[DM] dm nv id: %d\n", NVRAM_DM_REGISTER_STATUS);
		flag = 1;
	}

	return &dm_config;
}
