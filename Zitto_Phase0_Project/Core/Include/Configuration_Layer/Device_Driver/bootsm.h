/*
 * bootsm.h
 *
 *  Created on: Jan 19, 2024
 *      Author: Pavithraa
 */
#ifndef CONFIGURATION_LAYER_DEVICE_DRIVER_API_BOOTSM_H_
#define CONFIGURATION_LAYER_DEVICE_DRIVER_API_BOOTSM_H_

/* Includes for definitions */

typedef enum bootsm_boot_state_te_tag
{
	BOOTSM_SYS_SHUTDOWN = 0x01,
	BOOTSM_SYS_START,
	BOOTSM_SYS_CORE_INIT,
	BOOTSM_SYS_CORE_PERL_INIT,
	BOOTSM_SYS_STORE_RESTART_INFO,
	BOOTSM_SYS_APP_PERP_INIT,
	BOOTSM_SYS_APP_PREOS_CONFIGURATION,
	BOOTSM_SYS_OS_INIT,
	BOOTSM_SYS_OS_START_KERNEL,
	BOOTSM_SYS_OS_STARTER_ENGINE_RUNNING,
	BOOTSM_SYS_APP_POSTOS_CONFIGURATION,
	BOOTSM_SYS_OS_RUNNING,
	BOOTSM_SYS_OS_SAFE_MODE,
	BOOTSM_SYS_OS_SUSPENDED,
	BOOTSM_SYS_ENTER_LOW_POWER,
	BOOTSM_SYS_LOW_POWER_RUN,
	BOOTSM_SYS_NORMAL_SLEEP_START,
	BOOTSM_SYS_NORMAL_SLEEP_RESUME,
	BOOTSM_SYS_ENTER_DEEP_SLEEP,

	BOOTSM_SYS_OS_ERROR,
	BOOTSM_SYS_CORE_INIT_ERROR,
	BOOTSM_SYS_CORE_PERL_INIT_ERROR,
	BOOTSM_SYS_STORE_RESTART_INFO_WARNING,
	BOOTSM_SYS_APP_PERP_INIT_ERROR,
	BOOTSM_SYS_APP_CONFIGURATION_ERROR,
	BOOTSM_SYS_APP_PREOS_INIT_ERROR,
	BOOTSM_SYS_OS_INIT_ERROR,
	BOOTSM_SYS_OS_SCHEDULER_START_ERROR,
	BOOTSM_SYS_OS_STARTER_ENGINE_RUN_ERROR,
	BOOTSM_SYS_OS_APP_POSTOS_INT,
}bootsm_boot_state_te;


typedef enum bootsm_init_state_te_tag
{
	/* Bootloader states*/
	BOOTSM_CORE_CLOCK_STATE,
	BOOTSM_CORE_CAN_STATE,
	BOOTSM_CORE_SPI_STATE,
	BOOTSM_CORE_STATE_ENDS,

	/* APP states*/
	BOOTSM_APPCORE_CLOCK_STATE,
	BOOTSM_APPCORE_CAN_STATE,
	BOOTSM_APPCORE_ADC_STATE,
	BOOTSM_APPCORE_I2C_STATE,
	BOOTSM_APPCORE_SPI_STATE,
	BOOTSM_APPCORE_TIM6_STATE,
	BOOTSM_APPCORE_TIM7_STATE,
	BOOTSM_APPCORE_TIM15_STATE,
	BOOTSM_APPCORE_STATE_ENDS,

}bootsm_init_state_te;

extern bootsm_boot_state_te bootsm_boot_status_e;
extern bootsm_init_state_te bootsm_init_state_e;

/* Public Function Prototypes **/

#endif /* CONFIGURATION_LAYER_DEVICE_DRIVER_BOOTSM_H_ */
