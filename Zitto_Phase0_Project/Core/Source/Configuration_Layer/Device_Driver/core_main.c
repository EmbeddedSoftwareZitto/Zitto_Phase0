/*
 * core_main.c
 *
 *  Created on: Jan 19, 2024
 *      Author: Pavithraa
 */

/* Common Header Files */

/* Application Header File */

/* Configuration Header File */
#include "bootsm.h"

/* This header file */
#include "core_main.h"
#include "clock_pwr.h"
//#include "app_main.h"
/* Driver header */
/* #include "gt_wdg.h" */

/** @{
 * Private Definitions **/

/** @} */

/* Private Function Prototypes */
static U8 core_main_core_init_pru8(void);
static U8 core_main_core_peripherals_init_pru8(void);


/* Private Variable Definitions */

/*  Public Variable Definitions */

/* Public Function Definitions */


/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
U8 core_main_start_u8(void)
{
	U8 ret_val_u8 = 0;
	ret_val_u8 =  core_main_core_init_pru8();
	ret_val_u8 += core_main_core_peripherals_init_pru8();

	return (ret_val_u8);
}

/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
static U8 core_main_core_init_pru8(void)
{
	U8 ret_val_u8 = 0;

	/* System Core Init is happening */
	bootsm_boot_status_e = BOOTSM_SYS_CORE_INIT;

	/* Configure the system clock with required specifications */
	bootsm_init_state_e = BOOTSM_APPCORE_CLOCK_STATE;
	ret_val_u8 = clock_pwr_system_clock_config_u8();

#if 0
	if(ret_val_u8)
	{
		app_main_system_flt_status_u32 |= (app_main_system_flt_status_u32 << 9);
	}
#endif


	return (ret_val_u8);
}

/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
static U8 core_main_core_peripherals_init_pru8(void)
{
	U8 ret_val_u8 = 0;

	/* System Core Peripheral Init is happening */
	bootsm_boot_status_e = BOOTSM_SYS_CORE_PERL_INIT;

	/* TODO Configure the system RTC clock */
	/* ret_val_u8 += rtc_int_init_u8(); */

	/* TODO Configure the watch dog timer */
	/*  ret_val_u8 += wdg_init_u8(); */

	/* TODO Configure the backup SRAM */

	/* TODO Configure the System Boot */
	bootsm_boot_status_e = BOOTSM_SYS_STORE_RESTART_INFO;

	return (ret_val_u8);
}
