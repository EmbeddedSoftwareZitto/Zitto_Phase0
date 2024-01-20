/*
 * gpio_app.c
 *
 *  Created on: Jan 7, 2024
 *      Author: Pavithraa
 */

/* Common Header Files */

/* Application Header File */

/* This header file */
#include "gpio_app.h"

/* Driver header */
#include "gpio.h"
#include "app_main.h"
/* Private Definitions **/

/* Private Function Prototypes */

/* Private Variable Definitions */

/*  Public Variable Definitions */

const gpio_do_map_dir_tst gpio_app_gpio_do_map_dir_gast[GPIO_MAX_NUM_DO]=
{
		/** GPIO_PORT    GPIO_PINS     DEFAULT_STATE **/
//		{ GPIO_PORT_PTA, GPIO_PINS_1,  GPIO_DO_OFF },   //0
//		{ GPIO_PORT_PTA, GPIO_PINS_3,  GPIO_DO_OFF },   //1
//		{ GPIO_PORT_PTA, GPIO_PINS_4,  GPIO_DO_OFF },  //2
//		{ GPIO_PORT_PTA, GPIO_PINS_8,  GPIO_DO_OFF },  //2

//		{ GPIO_PORT_PTB, GPIO_PINS_0,  GPIO_DO_OFF },
//		{ GPIO_PORT_PTB, GPIO_PINS_1,  GPIO_DO_OFF },
//		{ GPIO_PORT_PTB, GPIO_PINS_4,  GPIO_DO_OFF },
//		{ GPIO_PORT_PTB, GPIO_PINS_5,  GPIO_DO_OFF },

};

const gpio_do_map_dir_tst gpio_app_gpio_di_map_dir_gast[DI_GPIO_MAX_NUM_DI]=
{
//		{ GPIO_PORT_PTB, GPIO_PINS_5, GPIO_DO_OFF }

};

/** @} */

/* Public Function Definitions */
/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
void gpio_app_set_digital_output_v(const U16 pin_number_u16, gpio_do_di_state_te state_e)
{
	gpio_set_direct_output_v(pin_number_u16, state_e, gpio_app_gpio_do_map_dir_gast);
}

/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
void gpio_app_toggle_direct_output_v(const U16 pin_number_u16)
{
	gpio_toggle_direct_output_v(pin_number_u16, gpio_app_gpio_do_map_dir_gast);
}

/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
void gpio_app_read_update_digital_inputs_v(const U16 pin_number_u16, gpio_do_di_state_te *state_e)
{
	//TODO Read_Update_Digital_Inputs
	gpio_get_direct_input_v(pin_number_u16, state_e, gpio_app_gpio_di_map_dir_gast);
}


/****************************************************************************************************************************************************
 * EOF
 ***************************************************************************************************************************************************/
