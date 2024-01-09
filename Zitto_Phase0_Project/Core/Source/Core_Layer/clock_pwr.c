/*
 * clock_pwr.c
 *
 *  Created on: Jan 7, 2024
 *      Author: Pavithraa
 */



/* Common Header Files */
#include "common_header.h"

/* Application Header File */
/* This header file */
#include "clock_pwr.h"

/* Driver header */
//#include "system.h"

/* Private Definitions */

/* Private Function Prototypes */

/* Private Variable Definitions */

/* Public Variable Definitions */

/* Public Function Definitions */
U8 clock_pwr_system_clock_config_u8(void);

/**
Name		 : clock_pwr_system_clock_config_u8
Scope        : Public
Description  : To configure system - clock power
Input Data   : NULL
Return Value : zero if success, non-zero if failed.

**/
U8 clock_pwr_system_clock_config_u8(void)
{
	U8 ret_val_u8 = 0;
	SystemClock_Config();

	return ret_val_u8;
}

