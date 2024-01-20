/*
 * bms_config.c
 *
 *  Created on: Jan 19, 2024
 *      Author: Pavithraa
 */


/* Common Header Files */
#include "common_header.h"

/* Application Header File */

/* This header file */
#include "bms_config.h"

/* Driver header */
/* Private Definitions **/

/* Private Function Prototypes */

/* Private Variable Definitions */

/* Public Variable Definitions */
bms_config_nv_cell_cfg_tst bms_config_nv_cell_cfg_gst;
bms_config_nv_pv_mon_tst   bms_config_nv_pv_cfg_gst;
bms_config_nv_pi_mon_tst   bms_config_nv_pi_cfg_gst;
bms_config_nv_warn_mon_tst bms_config_nv_warn_mon_gst;

/* Public Function Definitions */


/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
void bms_config_non_volatile_param_init_v(void)
{
	/* Cell Voltage Level Configuration */
	/* Voltage */
	bms_config_nv_cell_cfg_gst.abs_min_cell_1mV_u16 				= BMS_CONFIG_MIN_CELL_VTG_TH_MV;     /* The minimum voltage for a cell */ /*Checked F48*/
	bms_config_nv_cell_cfg_gst.abs_max_cell_1mV_u16 				= BMS_CONFIG_MAX_CELL_VTG_TH_MV;     /* The maximum voltage for a cell */ /*Checked F48*/
	bms_config_nv_cell_cfg_gst.deep_dsg_cell_1mV_u16 		    	= BMS_CONFIG_DP_DSG_CELL_VTG_TH_MV;  /* The minimum voltage for a cell to get into cell deep discharge */ /*Checked F48*/
	bms_config_nv_cell_cfg_gst.release_max_cell_1mV_u16 			= BMS_CONFIG_REL_MAX_CELL_VTG_TH_MV;  /*Checked F48*/
	bms_config_nv_cell_cfg_gst.release_min_cell_1mV_u16 			= BMS_CONFIG_REL_MIN_CELL_VTG_TH_MV;  /*Checked F48*/

//	bms_config_nv_cell_cfg_gst.cell_open_low_threshold_u16          = 2000; /*Checked F48*/
//
//	bms_config_nv_cell_cfg_gst.cell_open_upper_threshold_u16        = 4200; /*Checked F48*/


	bms_config_nv_warn_mon_gst.warn_max_cell_1mV_u16        		= bms_config_nv_cell_cfg_gst.abs_max_cell_1mV_u16 - 10; //4240 /*Checked F48*/
	bms_config_nv_warn_mon_gst.warn_min_cell_1mV_u16		 		= bms_config_nv_cell_cfg_gst.abs_min_cell_1mV_u16 + 200; // 2950 /*Checked F48*/
	bms_config_nv_warn_mon_gst.warn_deep_discharge_1mV_u16			= bms_config_nv_cell_cfg_gst.deep_dsg_cell_1mV_u16 + 200; /*Checked F48*/


	/* Cell Temperature */
	bms_config_nv_cell_cfg_gst.abs_min_cell_1cc_s16 				= BMS_CONFIG_MIN_CELL_TEMP_TH_CC; 	/* The minimum temperature for a cell */ /*Checked F48*/
	bms_config_nv_cell_cfg_gst.abs_max_cell_1cc_s16 				= BMS_CONFIG_MAX_CELL_TEMP_TH_CC; 	/* The maximum temperature for a cell */ /*Checked F48*/
	bms_config_nv_cell_cfg_gst.release_min_cell_1cc_s16 			= 500; 	/*Checked F48*/
	bms_config_nv_cell_cfg_gst.release_max_cell_1cc_s16 			= 5500; 	/*Checked F48*/

//	bms_config_nv_cell_cfg_gst.temp_open_thershold      			= -2000; /*-20C*/ /*Checked F48*/
	/* Remember to update BATT_PARAM_CELL_ID_MAX */

	/* Mosfet temperature */

//	bms_config_nv_cell_cfg_gst.abs_max_mosfet_1cc_s16				= 9500; 	/* Max. MOSFET temperature (E.g)7500 = 75 deg */
//	bms_config_nv_cell_cfg_gst.abs_min_mosfet_1cc_s16				= 0;		/* Max. MOSFET temperature (E.g)0000 = 0 deg */
//	bms_config_nv_cell_cfg_gst.release_max_mosfet_1cc_s16    		= 7000;		/* Release MOSFET temperature (E.g)5000 = 50 deg */
//	bms_config_nv_cell_cfg_gst.release_min_mosfet_1cc_s16    		= 500;		/* Release MOSFET temperature (E.g)1000 = 10 deg */

	/* Pack temperature */
//	bms_config_nv_cell_cfg_gst.abs_max_pack_1cc_s16					= 9000;		/* Max. Pack temperature 60 deg */ /*Checked F48*/
//	bms_config_nv_cell_cfg_gst.abs_min_pack_1cc_s16					= 0;		/* Min. Pack temperature 10 deg */ /*Checked F48*/
//	bms_config_nv_cell_cfg_gst.release_max_pack_1cc_s16    			= 7000; 		/* Release Max Pack temperature  50 deg */ /*Checked F48*/
//	bms_config_nv_cell_cfg_gst.release_min_pack_1cc_s16    			= 500;		/* Release Min Pack temperature  15 deg */ /*Checked F48*/
//
//	/* afe die temperature*/
//	bms_config_nv_cell_cfg_gst.abs_max_afe_dieT_1cc_s16             =  8500; /*Checked F48*/
//	bms_config_nv_cell_cfg_gst.abs_min_afe_dieT_1cc_s16             =  0;   /*Checked F48*/
//	bms_config_nv_cell_cfg_gst.release_min_afe_dieT_1cc_s16         =  bms_config_nv_cell_cfg_gst.abs_min_afe_dieT_1cc_s16 + 500; /*Checked F48*/ //5C
//	bms_config_nv_cell_cfg_gst.release_max_afe_dieT_1cc_s16         =  bms_config_nv_cell_cfg_gst.abs_max_afe_dieT_1cc_s16 - 1000; /*Checked F48*/ //75C
//
//	bms_config_nv_cell_cfg_gst.ntc_beta_val_u16						= 3435; //TODO

	bms_config_nv_warn_mon_gst.warn_max_cell_1cc_s16				= bms_config_nv_cell_cfg_gst.abs_max_cell_1cc_s16 - 500; //55C /*Checked F48*/
	bms_config_nv_warn_mon_gst.warn_min_cell_1cc_s16				= bms_config_nv_cell_cfg_gst.abs_min_cell_1cc_s16 + 500; //10C /*Checked F48*/
//	bms_config_nv_warn_mon_gst.warn_max_mosfet_1cc_s16 				= bms_config_nv_cell_cfg_gst.abs_max_mosfet_1cc_s16 - 2500; /*Checked F48*/
//	bms_config_nv_warn_mon_gst.warn_max_pack_1cc_s16                = bms_config_nv_cell_cfg_gst.abs_max_pack_1cc_s16  -500; //55C /*Checked F48*/
//	bms_config_nv_warn_mon_gst.warn_min_pack_1cc_s16                = bms_config_nv_cell_cfg_gst.abs_min_pack_1cc_s16 +500; //15C /*Checked F48*/
//	bms_config_nv_warn_mon_gst.warn_max_afe_temp_1cc_s16            = bms_config_nv_cell_cfg_gst.abs_max_afe_dieT_1cc_s16 -1000; //75C /*Checked F48*/
//	bms_config_nv_warn_mon_gst.warn_min_afe_temp_1cc_s16            = bms_config_nv_cell_cfg_gst.abs_min_afe_dieT_1cc_s16 + 1000; //10C /*Checked F48*/

//	bms_config_nv_cell_cfg_gst.series_cell_capacity_1cAHr_u16		= 145;		/* 2.6AHr = 260 cAHr - 2 in parallel */

	/* Cell Balancing */
//	bms_config_nv_cell_cfg_gst.bal_err_enable_flag_b				= COM_HDR_FALSE; /*Checked F48*/	/* To enable or disable the protection based on bal err */
//	bms_config_nv_cell_cfg_gst.max_bal_err_1cPC_u16					= 1000;		/*Checked F48*/ /* 5 % maximum possible balancing error */
//	bms_config_nv_cell_cfg_gst.release_bal_err_1cPC_u16				= 20;		/*Checked F48*/ /* 0.2% maximum balancing error allowable */

/*************************************************************************************************************************/
	/* Pack Voltage Level Configuration */

	/* */
	bms_config_nv_pv_cfg_gst.PV_lower_threshold_1cV_u16 			= 4000; /*Approx Checked F48*/
	bms_config_nv_pv_cfg_gst.PV_upper_threshold_1cV_u16 			= 5650; /*Approx Checked F48*/
	bms_config_nv_pv_cfg_gst.PV_release_lower_threshold_1cV_u16  	= 4900; /*Approx Checked F48*/
	bms_config_nv_pv_cfg_gst.PV_release_upper_threshold_1cV_u16  	= 5450; /*Approx Checked F48*/

	bms_config_nv_warn_mon_gst.warn_pack_lower_threshold_1cV_u16 	= bms_config_nv_pv_cfg_gst.PV_lower_threshold_1cV_u16  + 100; /*Approx Checked F48*/
	bms_config_nv_warn_mon_gst.warn_pack_upper_threshold_1cV_u16    = bms_config_nv_pv_cfg_gst.PV_upper_threshold_1cV_u16  - 30; /*Approx Checked F48*/

	bms_config_nv_pv_cfg_gst.PV_delta_hvadc_pk_threshold_1cV_u16 = 80; /*300mV*/	/*Checked F48*/	//TODO check the milli volt diff
	bms_config_nv_pv_cfg_gst.PV_delta_betw_hvadc_pk_fuse_threshold_1cV_u16 = 30;
	bms_config_nv_pv_cfg_gst.PV_delta_betw_hvadc_pk_poscon_threshold_1cV_u16 = 40;

/*************************************************************************************************************************/
	/* Pack Current Configuration */

	bms_config_nv_pi_cfg_gst.max_chg_1mA_s32						=  12000; /*TODO: Changed Approx*/ /*Checked F48*/
	bms_config_nv_pi_cfg_gst.cont_dsg_1mA_s32						= -25000;
	bms_config_nv_pi_cfg_gst.max_dsg_1mA_s32						= -40000;//-28000; /*TODO: Changed Approx*/ /*Checked F48*/
	bms_config_nv_pi_cfg_gst.max_scd_surge_1mA_s32				    = -66 * 1000; //50/*TODO: Changed Approx*/ /*Checked F48*/
	bms_config_nv_pi_cfg_gst.idle_chg_1mA_s16						=  80; /*mA; Checked F48*/
	bms_config_nv_pi_cfg_gst.idle_dsg_1mA_s16						= -80; /*mA; Checked F48*/

	bms_config_nv_warn_mon_gst.warn_max_chg_1mA_s32					= bms_config_nv_pi_cfg_gst.max_chg_1mA_s32 - 1000; /*Checked F48*/
	bms_config_nv_warn_mon_gst.warn_max_dsg_1mA_s32					= bms_config_nv_pi_cfg_gst.max_dsg_1mA_s32 + 1000; /*Checked F48*/
	bms_config_nv_warn_mon_gst.warn_max_scd_surge_1mA_s32			= bms_config_nv_pi_cfg_gst.max_scd_surge_1mA_s32 + 1000;//-49 * 1000; /*Checked F48*/

/***************************************************************************************************************************/




}

/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
void bms_config_non_volatile_backup_reg_recovery_v(void)
{

}


/***********************************************************************************************************************************************************************************
 * EOF
 **********************************************************************************************************************************************************************************/
