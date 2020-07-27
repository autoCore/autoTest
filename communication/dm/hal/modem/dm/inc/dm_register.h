#ifndef __DM_H__
#define __DM_H__

#if 1
#define CTDM_LOG(fmt, ...)  raw_uart_log(fmt, ##__VA_ARGS__)
#else
#define CTDM_LOG(fmt, ...)  fatal_printf(fmt, ##__VA_ARGS__)
#endif


#define DM_VERSION_1
//#define DM_VERSION_2
//#define DM_VERSION_3

#define ICCID_LEN 20
#define IMSI_LEN 15


struct dm_register_record {
	char UEICCID1[ICCID_LEN+1];
	char UEICCID2[ICCID_LEN+1];
	char IMSI1[IMSI_LEN + 1];
	char IMSI2[IMSI_LEN + 1];
};

struct sim_info {
	int sim1_flag;
	int sim2_flag;
	int sim1_type;
	int sim2_type;
	const char *iccid1;
	const char *iccid2;
	const char *imsi1;
	const char *imsi2;
};

#define ICCID_WITH_NO_SIM_INSTRTED	""
#define IMSI_WITH_NO_SIM_INSTRTED	""

enum {
	UNKNOW_SIM,
	CHINA_MOBILE,
	CHINA_UNICOM,
	CHINA_TELECOM_CDMA,
	CHINA_TELECOM_LTE,
};

enum dm_reister_ret{
	REGISTER_FAILED,
	REGISTER_OK,
	NO_REGISTER_REQUIRED,
	REGISTER_LIMITED_REACHED,
};

enum dm_event_type {
	NO_DM_REGQUEST = 0,
	TELECOM_DM_REQUEST,
	CMCC_DM_REQUEST,
	UNICOM_DM_REQUEST,
};

extern int IsSimExist(int nSimID);

int do_telecom_dm(void);
int do_cmcc_dm(void);
int do_unicom_dm(void);

extern struct dm_register_config *get_dm_configuration(void);
struct sim_info *get_current_sim_info(void);
struct dm_register_record *get_current_dm_record(void);
void send_dm_event(void *p);


// build for lib
U16 get_dm_nv_id(void);
u8 get_telecom_dm_mode(void);
u8 get_cmcc_dm_mode(void);
u8 get_unicom_dm_mode(void);
u8 get_dm_demo_mode(void);


#endif
