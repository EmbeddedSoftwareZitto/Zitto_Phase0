/*
 * app_main.c
 *
 *  Created on: Jan 19, 2024
 *      Author: Pavithraa
 */

/* Common Header Files */
#include "common_header.h"

/* Application Header File */

/* Configuration Header File */
#include "can_app.h"
#include "gpio_app.h"
#include "bootsm.h"
//#include "task.h"
/* This header file */
#include "app_main.h"

/* Driver header */
#include "gpio.h"
#include "can.h"
//#include "nvic.h"

/* Private Definitions **/

/* Private Function Prototypes */
static U8 app_main_peripherals_init_pru8(void);
static U8 app_main_pre_os_periph_config_pru8(void);
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
U8 app_main_start_u8(void)
{
	U8 ret_val_u8 = 0;

	ret_val_u8 =  app_main_peripherals_init_pru8();
	ret_val_u8 += app_main_pre_os_periph_config_pru8();

	return (ret_val_u8);
}

/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
static U8 app_main_peripherals_init_pru8(void)
{
	U8 ret_val_u8 = 0;

	bootsm_boot_status_e = BOOTSM_SYS_APP_PERP_INIT;

	/* Pin Mux Initialization - Done based on the pins used in the schematics */
	ret_val_u8 = gpio_pin_mux_init_u8(); /* No core state change - because no fault case*/

	/* CAN Engine Initialization - CAN1 at 250Kbps and CAN Interrupt*/
	bootsm_init_state_e = BOOTSM_APPCORE_CAN_STATE;
	ret_val_u8 += can_app_init_u8();

	can_message_tst tx_message;
	tx_message.can_id_u32 = 0x18984010;
	tx_message.data_au8[0] = 'D';
	tx_message.data_au8[1] = 'O';
	tx_message.data_au8[2] = 'N';
	tx_message.data_au8[3] = 'E';
	tx_message.length_u8 = 4;

	ret_val_u8 += can_app_transmit_data_u8(&tx_message);

	bootsm_init_state_e = BOOTSM_APPCORE_STATE_ENDS;

	/* NVIC Initialization - Disable all the interrupts and set the appropriate priority */
	//nvic_init_v();

	return (ret_val_u8);
}
///**
//Name		 :
//Scope        :
//Description  :
//Input Data   :
//Return Value :
//**/
//U8 system_init_flt_update_u8()
//{
//	U8 ret_val_u8 = 0;
//	switch(bootsm_init_state_e)
//	{
//		case BOOTSM_APPCORE_CLOCK_STATE:
//		{
//			ret_val_u8 = gpio_pin_mux_init_u8();
//			ret_val_u8 += can_app_init_u8(CAN_APP_DISO_INST_0);
////			app_main_system_flt_status_u64 = 0;
////			app_main_system_flt_status_u64 |= ((U64)1 << FAULT_BIT_CLOCK_INIT);
//		}
//		break;
//		case BOOTSM_APPCORE_ADC_STATE:
//		{
//			//app_main_system_flt_status_u64 = 0;
//			//app_main_system_flt_status_u64 |= ((U64)1 << FAULT_BIT_ADC_INIT);
//		}
//		break;
//		case BOOTSM_APPCORE_I2C_STATE:
//		{
//			//app_main_system_flt_status_u64 = 0;
//			//app_main_system_flt_status_u64 |= ((U64)1 << FAULT_BIT_I2C_INIT);
//		}
//		break;
//		case BOOTSM_APPCORE_SPI_STATE:
//		{
//			app_main_system_flt_status_u64 = 0;
//			app_main_system_flt_status_u64 |= ((U64)1 << FAULT_BIT_SPI_INIT);
//		}
//		break;
//		case BOOTSM_APPCORE_TIM6_STATE:
//		{
//			app_main_system_flt_status_u64 = 0;
//			app_main_system_flt_status_u64 |= ((U64)1 << FAULT_BIT_TIMER6);
//		}
//		break;
//		case BOOTSM_APPCORE_TIM7_STATE:
//		{
//			app_main_system_flt_status_u64 = 0;
//			app_main_system_flt_status_u64 |= ((U64)1 << FAULT_BIT_TIMER7);
//		}
//		break;
//		case BOOTSM_APPCORE_TIM15_STATE:
//		{
//			app_main_system_flt_status_u64 = 0;
//			app_main_system_flt_status_u64 |= ((U64)1 << FAULT_BIT_TIMER15);
//		}
//		break;
//		case BOOTSM_CORE_STATE_ENDS:
//		{
//			app_main_system_flt_status_u64 &= ~((U64)0x1FFF);
//		}
//		break;
//		default:
//		{
//
//		}
//	}
//
//	if(bootsm_boot_status_e != BOOTSM_SYS_OS_RUNNING)
//	{
//		HAL_Delay(1000);
//	}
//	can_app_message_tst can_msg_tx_st;
//	can_msg_tx_st.can_id_u32 = 0x81DFADA;
//	can_msg_tx_st.length_u8 = 8;
//	can_msg_tx_st.data_au8[0] = (app_main_system_flt_status_u64);
//	can_msg_tx_st.data_au8[1] = (app_main_system_flt_status_u64 >> 8);
//	can_msg_tx_st.data_au8[2] = (app_main_system_flt_status_u64 >> 16);
//	can_msg_tx_st.data_au8[3] = (app_main_system_flt_status_u64 >> 24);
//	can_msg_tx_st.data_au8[4] = (app_main_system_flt_status_u64 >> 32);
//	can_msg_tx_st.data_au8[5] = (app_main_system_flt_status_u64 >> 40);
//	can_msg_tx_st.data_au8[6] = (app_main_system_flt_status_u64 >> 48);
//	can_msg_tx_st.data_au8[7] = (app_main_system_flt_status_u64 >> 56);
//	ret_val_u8  += can_app_transmit_data_u8(CAN_APP_DISO_INST_0, CAN_TX_MAILBOX0, CAN_TX_BLOCKING, &can_msg_tx_st);
//
//	return ret_val_u8;
//}
/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
static U8 app_main_pre_os_periph_config_pru8(void)
{
	U8 ret_val_u8 = 0;
	/* TODO: Enable this once boot state machine file is included */
	bootsm_boot_status_e = BOOTSM_SYS_APP_PREOS_CONFIGURATION;

#if 0	/* Disabled because power for all I2C sensors should be enabled from GUI */
	#if !TEST_COMM_HARD_CODE
	/** Powering all the sensor after core initialisation */
	app_main_sensor_on_v();
	#endif
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
U8 app_main_post_os_periph_config_u8(void)
{
	U8 ret_val_u8 = 0;

	bootsm_boot_status_e = BOOTSM_SYS_APP_POSTOS_CONFIGURATION;

	/***************************************************************************************************************************************/
	/* NVIC interrupts enabling */
	/***************************************************************************************************************************************/
	/* NVIC - PostOS Configuration */
	//nvic_enable_all_interrupts_v();
	return ret_val_u8;
}


/****************************************************************************************************************************************************
 * EOF
 ***************************************************************************************************************************************************/
