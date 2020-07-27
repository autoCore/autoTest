#ifndef __CUS_DM_REGISTER_DEF_H__
#define __CUS_DM_REGISTER_DEF_H__

#define DM_DATA_MODE	1
#define DM_SMS_MODE		2


//#define DM_DEMO_CODE


/*  telecom dm configuration start */
#define TELECOM_DM_MODE_CONFIG		DM_DATA_MODE

#define KEY_REGVER	"8.0"
#define KEY_MODEL	"ASR-Crane"
#define KEY_SWVER	"r1_0_0"
#define KEY_ROM		"16M"
#define KEY_RAM		"16M"
#define KEY_OSVER	"Threadx1.0"
#define TELECOM_DM_SMS_CENTER "10659401"
#define TELECOM_DM_HTTP_CENTER "http://zzhc.vnet.cn"
//#define TELECOM_SMS_DM_SEND_NO_IMEI2
/* telecom dm configuration end */



/* cmcc dm configuration start */
//#define CMCC_DM_MODE_CONFIG		DM_DATA_MODE

#define KEY_sdkVersion		"1.0"
#define KEY_brand			""
#define KEY_model			""
#define KEY_firmwareVer		""
#define KEY_systemVer		""
#define KEY_cpu				""
#define KEY_rom				"16M"
#define KEY_ram				"16M"

// 16 bytes ase-key
#define KEY_aesKey			"1111111111111111";
#define KEY_httpsUrl		"https://b.fxltsbl.com"
// 1~20 bytes appkey
#define KEY_appKey			"user123456"
/* cmcc dm configuration end */




/* unicom dm configuration start */

//#define UNICOM_DM_MODE_CONFIG		DM_DATA_MODE

/* unicom dm configuration end */


struct dm_register_config {
	unsigned char telecom_dm_mode;
	unsigned char cmcc_dm_mode;
	unsigned char unicom_dm_mode;
	unsigned char demo_mode;
	unsigned short dm_nv_id;
};

struct telecom_dm_register_data {
	const char *REGVER;
	const char *MEID;
	const char *MODEL;
	const char *SWVER;
	const char *SIM1CDMAIMSI;
	const char *UETYPE;
	const char *SIM1ICCID;
	const char *SIM1LTEIMSI;
	const char *SIM2CDMAIMSI;
	const char *SIM2ICCID;
	const char *SIM2LTEIMSI;
	const char *MACID;
	const char *OSVER;
	const char *IMEI1;
	const char *IMEI2;
	const char *SIM1CELLID;
	const char *SIM2CELLID;
	const char *DATASIM;
	const char *ROM;
	const char *RAM;
	const char *SIM1VoLTESW;
	const char *SIM2VoLTESW;
	const char *ACCESSTYPE;
	const char *REGDATE;
	const char *MLPLVER;
	const char *MSPLVER;
	const char *MMEID;
	const char *SIM1TYPE;
	const char *SIM2TYPE;

	const char *SMS_DM_NO_IMEI2_FLAG;
	const char *SMS_DM_CENTER;
	const char *HTTP_DM_CENTER;
};


struct cmcc_dm_register_data {
	const char *sdkVersion;
	const char *imei1;
	const char *imei2;
	const char *meid;
	const char *deviceId;
	const char *brand;
	const char *model;
	const char *firmwareVer;
	const char *systemVer;
	const char *cpu;
	const char *rom;
	const char *ram;
	const char *type;
	const char *iccid1;
	const char *iccid2;
	const char *imsi1;
	const char *imsi2;
	const char *mac;
	const char *cellId;
	const char *lac;
	const char *channel;
	const char *dataCard;
	const char *masterStatus;
	const char *sendTime;
	const char *soltQuantity;
	const char *dataCard2;
	const char *soltService1;
	const char *soltService2;
	const char *soltNetWork1;
	const char *soltNetWork2;
	const char *lac2;
	const char *cellId2;

	const char *aesKey;
	const char *httpsUrl;
	const char *appKey;
};

#endif
