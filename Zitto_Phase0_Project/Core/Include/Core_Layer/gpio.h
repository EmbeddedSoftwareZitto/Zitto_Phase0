/*
 * gpio.h
 *
 *  Created on: Jan 7, 2024
 *      Author: Pavithraa
 */

#ifndef INCLUDE_CORE_LAYER_GPIO_H_
#define INCLUDE_CORE_LAYER_GPIO_H_


/* Includes for definitions */
#include "common_header.h"

/* IO registers */
typedef enum gpio_port_te_tag
{
    GPIO_PORT_PTA = 0,
	GPIO_PORT_PTB,
	GPIO_PORT_PTC,
	GPIO_PORT_PTD,
	GPIO_PORT_PTE,

    GPIO_MAX_NUM_PORTS     /* always leave this at the end */
}gpio_port_te;

typedef enum gpio_pins_te_tag
{
    GPIO_PINS_0 = 0,
	GPIO_PINS_1,
	GPIO_PINS_2,
	GPIO_PINS_3,
	GPIO_PINS_4,
	GPIO_PINS_5,
	GPIO_PINS_6,
	GPIO_PINS_7,
	GPIO_PINS_8,
	GPIO_PINS_9,
	GPIO_PINS_10,
	GPIO_PINS_11,
	GPIO_PINS_12,
	GPIO_PINS_13,
	GPIO_PINS_14,
	GPIO_PINS_15,
	GPIO_PINS_16,
	GPIO_PINS_17,

    GPIO_MAX_NUM_PINS     /* always leave this at the end */
}gpio_pins_te;

typedef enum  gpio_do_state_te_tag
{
   GPIO_DO_INIT = 0,
   GPIO_DO_ON,
   GPIO_DO_OFF,
   GPIO_DO_FAULT,
   GPIO_DO_MAX_STATE
}gpio_do_di_state_te;

typedef enum  gpio_di_state_te_tag
{
   GPIO_DI_INIT = 0,
   GPIO_DI_ON,
   GPIO_DI_OFF,

   GPIO_DI_MAX_STATE
}gpio_di_state_te;

typedef struct gpio_do_map_dir_tst_tag
{
	gpio_port_te gpio_port_reg_e;
	gpio_pins_te gpio_pins_e;
	gpio_do_di_state_te gpio_default_state_e;

}gpio_do_map_dir_tst;

typedef struct gpio_di_int_tst_tag
{
	gpio_port_te gpio_port_reg_e;
	gpio_pins_te gpio_pins_e;
	//port_interrupt_config_t gpio_int_state_e;
}gpio_di_int_tst_tag;
/* Public Variable Definitions */

/* Public Function Prototypes **/
extern U8 gpio_pin_mux_init_u8(void);
extern void gpio_digital_output_init_v(gpio_do_map_dir_tst gpio_io_map_dir_arst);
extern void gpio_digital_interrupt_init_v(gpio_port_te port_state);
extern void gpio_set_direct_output_v(const U16 pin_number_aru16,gpio_do_di_state_te state_are,const gpio_do_map_dir_tst *gpio_io_map_dir_arpst);
extern void gpio_toggle_direct_output_v(const U16 pin_number_aru16,const gpio_do_map_dir_tst *gpio_io_map_dir_arpst);
extern void gpio_get_direct_input_v(const U16 pin_number_aru16, gpio_do_di_state_te *state_are,const gpio_do_map_dir_tst *gpio_io_map_dir_arpst);


#endif /* INCLUDE_CORE_LAYER_GPIO_H_ */
