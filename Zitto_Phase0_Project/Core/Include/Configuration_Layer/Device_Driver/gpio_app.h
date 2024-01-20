/*
 * gpio_app.c
 *
 *  Created on: Jan 19, 2024
 *      Author: Pavithraa
 */
#ifndef CONFIGURATION_LAYER_DEVICE_DRIVER_API_GPIO_APP_H_
#define CONFIGURATION_LAYER_DEVICE_DRIVER_API_GPIO_APP_H_

/* Includes for definitions */
#include "common_header.h"

#include "gpio.h"

typedef enum  gpio_app_do_pins_te_tag
{
//	MCU_ALL_EN_PSW_PTA1			, /* CAN  switch 3V3 And Flash Power Switch  */
//	MCU_WP_FM_PTA3				,
//	MCU_RESET_FM_PTA4			,
//	MCU_STB_CAN_PTA8			, /* CAN  switch 5V enable/disable */
//
//
//	MCU_CS_FM_PTB0				, /* NSS SPI - Flash*/
//	MCU_STB_CAN_PTB1			,
//	MCU_RST_SHUT_AFE_PTB4		,
//	MCU_DFETOFF_AFE_PTB5		,
//
	GPIO_MAX_NUM_DO
}gpio_app_do_pins_te;

typedef enum gpio_app_di_pins_te_tag
{
//	AFE_ALERT_MCU_PTA0				,
	
	DI_GPIO_MAX_NUM_DI
}gpio_app_di_pins_te;

/* Public Variable Definitions */

/* Public Function Prototypes **/
extern U8 gpio_app_io_init_u8(void);
extern void gpio_app_set_digital_output_v(const U16 pin_number_u16, gpio_do_di_state_te state_e);
extern void gpio_app_toggle_direct_output_v(const U16 pin_number_u16);
extern void gpio_app_read_update_digital_inputs_v(const U16 pin_number_u16, gpio_do_di_state_te *state_e);

#endif /* CONFIGURATION_LAYER_DEVICE_DRIVER_GPIO_APP_H_ */
