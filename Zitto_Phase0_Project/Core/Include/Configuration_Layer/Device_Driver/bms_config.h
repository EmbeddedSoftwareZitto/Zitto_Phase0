/*
 * bms_config.h
 *
 *  Created on: Jan 19, 2024
 *      Author: Pavithraa
 */
#ifndef CONFIGURATION_LAYER_DEVICE_DRIVER_API_BMS_CONFIG_H_
#define CONFIGURATION_LAYER_DEVICE_DRIVER_API_BMS_CONFIG_H_

/* Includes for definitions */
#include "common_header.h"
//#include "batt_param.h"

#define BMS_CONFIG_MIN_CELL_VTG_TH_MV				2850
#define BMS_CONFIG_MAX_CELL_VTG_TH_MV				4200				/* Max cell voltage threshold 					*/
#define BMS_CONFIG_DP_DSG_CELL_VTG_TH_MV			2750//2500				/* Cell deep discharge threshold 				*/
#define BMS_CONFIG_REL_MIN_CELL_VTG_TH_MV		    3300				/* Release threshold for minimum cell voltage	*/
#define BMS_CONFIG_REL_MAX_CELL_VTG_TH_MV		   	3900				/* Release threshold for maximum cell voltage 	*/
#define BMS_CONFIG_MIN_CELL_TEMP_TH_CC				0					/* Min cell temperature threshold 				*/
#define BMS_CONFIG_MAX_CELL_TEMP_TH_CC				6000				/* Max cell temperature threshold 				*/

/* Cell Parameters Monitor Structure */
typedef struct __attribute__((packed)) bms_config_nv_cell_cfg_tst_tag
{
	/* Voltage */
    U16 abs_min_cell_1mV_u16;          /* The minimum voltage for a cell */
    U16 abs_max_cell_1mV_u16;          /* The maximum voltage for a cell */
    U16 deep_dsg_cell_1mV_u16; 		   /* The minimum voltage for a cell to get into cell deep discharge */
    U16 release_max_cell_1mV_u16;      /* */
    U16 release_min_cell_1mV_u16;  	   /* */

    /* Temperature */
    S16 abs_min_cell_1cc_s16;          /* The minimum temperature for a cell */
    S16 abs_max_cell_1cc_s16;          /* The maximum temperature for a cell */
    S16 release_min_cell_1cc_s16;      /* */
    S16 release_max_cell_1cc_s16;      /* */
} bms_config_nv_cell_cfg_tst;

/* Pack Voltage Monitor structure */
typedef struct __attribute__((packed)) bms_config_nv_pv_mon_tst_tag        /* pv - Pack Voltage */
{
    U16 PV_lower_threshold_1cV_u16;
    U16 PV_upper_threshold_1cV_u16;
    U16 PV_release_upper_threshold_1cV_u16;
    U16 PV_release_lower_threshold_1cV_u16;
    U16 PV_delta_hvadc_pk_threshold_1cV_u16;
    U16 PV_delta_betw_hvadc_pk_fuse_threshold_1cV_u16;
    U16 PV_delta_betw_hvadc_pk_poscon_threshold_1cV_u16;


} bms_config_nv_pv_mon_tst;

/* Pack Current Monitor Structure */
typedef struct __attribute__((packed)) bms_config_nv_pi_mon_tst_tag			/* pi - Pack current */
{
	S32 max_chg_1mA_s32;
	S32 cont_dsg_1mA_s32;
	S32 max_dsg_1mA_s32;
	S32 max_scd_surge_1mA_s32;

	S16 idle_chg_1mA_s16;
	S16 idle_dsg_1mA_s16;

}bms_config_nv_pi_mon_tst;

/* Warning Parameter Structure */
typedef struct __attribute__((packed)) bms_config_nv_warn_mon_tst_tag
{
	/* Cell Voltage */
	U16 warn_min_cell_1mV_u16;
	U16 warn_max_cell_1mV_u16;
	U16 warn_deep_discharge_1mV_u16;

	/* Pack Voltage */
	U16 warn_pack_lower_threshold_1cV_u16;
	U16 warn_pack_upper_threshold_1cV_u16;

	/* Temperature */
	S16 warn_min_cell_1cc_s16;
	S16 warn_max_cell_1cc_s16;
	S16 warn_max_mosfet_1cc_s16;
	S16 warn_min_mosfet_1cc_s16;
	S16 warn_min_pack_1cc_s16;
	S16 warn_max_pack_1cc_s16;
	S16 warn_min_afe_temp_1cc_s16;
	S16 warn_max_afe_temp_1cc_s16;

	/* Current */
	S32 warn_max_chg_1mA_s32;
	S32 warn_max_dsg_1mA_s32;
	S32 warn_max_scd_surge_1mA_s32;

}bms_config_nv_warn_mon_tst;

/*  Public Variable Definitions */
extern bms_config_nv_cell_cfg_tst bms_config_nv_cell_cfg_gst;
extern bms_config_nv_pv_mon_tst   bms_config_nv_pv_cfg_gst;
extern bms_config_nv_pi_mon_tst   bms_config_nv_pi_cfg_gst;
extern bms_config_nv_warn_mon_tst bms_config_nv_warn_mon_gst;

/* Public Function Prototypes **/
extern void bms_config_non_volatile_param_init_v(void);
extern void bms_config_non_volatile_backup_reg_recovery_v(void);
#endif /* CONFIGURATION_LAYER_DEVICE_DRIVER_BMS_CONFIG_H_ */
