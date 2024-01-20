/*
 * gpio.c
 *
 *  Created on: Jan 7, 2024
 *      Author: Pavithraa
 */


/* Common Header Files */

#include "main.h"

/* Application Header File */
//#include "bms_afe_task.h"

/* Configuration Header File */
//#include "operating_system.h"
/* This header file */
#include "gpio.h"

/* Driver header */
//#include "system.h"


/* Private Definitions **/

/* Private Function Prototypes */

/* Private Variable Definitions */

/* Public Variable Definitions */

/* Public Function Definitions */


/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
U8 gpio_pin_mux_init_u8(void)
{
	U8 ret_val_u8 = 0;

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	  /* GPIO Ports Clock Enable */
	  __HAL_RCC_GPIOE_CLK_ENABLE();
	  __HAL_RCC_GPIOC_CLK_ENABLE();
	  __HAL_RCC_GPIOF_CLK_ENABLE();
	  __HAL_RCC_GPIOA_CLK_ENABLE();
	  __HAL_RCC_GPIOD_CLK_ENABLE();
	  __HAL_RCC_GPIOB_CLK_ENABLE();

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(GPIOE, CS_I2C_SPI_Pin|LD4_Pin|LD3_Pin|LD5_Pin
	                          |LD7_Pin|LD9_Pin|LD10_Pin|LD8_Pin
	                          |LD6_Pin, GPIO_PIN_RESET);

	  /*Configure GPIO pins : DRDY_Pin MEMS_INT3_Pin MEMS_INT4_Pin MEMS_INT1_Pin
	                           MEMS_INT2_Pin */
	  GPIO_InitStruct.Pin = DRDY_Pin|MEMS_INT3_Pin|MEMS_INT4_Pin|MEMS_INT1_Pin
	                          |MEMS_INT2_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

	  /*Configure GPIO pins : CS_I2C_SPI_Pin LD4_Pin LD3_Pin LD5_Pin
	                           LD7_Pin LD9_Pin LD10_Pin LD8_Pin
	                           LD6_Pin */
	  GPIO_InitStruct.Pin = CS_I2C_SPI_Pin|LD4_Pin|LD3_Pin|LD5_Pin
	                          |LD7_Pin|LD9_Pin|LD10_Pin|LD8_Pin
	                          |LD6_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

	  /*Configure GPIO pin : B1_Pin */
	  GPIO_InitStruct.Pin = B1_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

	return(ret_val_u8);
}
/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
void gpio_set_direct_output_v(	const U16 pin_number_aru16, gpio_do_di_state_te state_are,	const gpio_do_map_dir_tst *gpio_io_map_dir_arpst)
{
	U16 i_u16 = pin_number_aru16;
	U16 port_u16;
	U32 pin_mask_u32;
	U16 pin_u16;
	port_u16 = gpio_io_map_dir_arpst[i_u16].gpio_port_reg_e;
	pin_u16 = gpio_io_map_dir_arpst[i_u16].gpio_pins_e;
	pin_mask_u32 = ((U32) COM_HDR_MASK_LO1_BIT << pin_u16);

	switch (port_u16)
	{
		/**********************************************************************************************************************/
		case GPIO_PORT_PTA:
		{
			if (GPIO_DO_ON == state_are)
				HAL_GPIO_WritePin(GPIOA, pin_mask_u32, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOA, pin_mask_u32, GPIO_PIN_RESET);
		}
		break;
		/**********************************************************************************************************************/
		case GPIO_PORT_PTB:
		{
			if (GPIO_DO_ON == state_are)
				HAL_GPIO_WritePin(GPIOB, pin_mask_u32, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOB, pin_mask_u32, GPIO_PIN_RESET);
		}
		break;
		/**********************************************************************************************************************/
		case GPIO_PORT_PTC:
		{
			if (GPIO_DO_ON == state_are)
				HAL_GPIO_WritePin(GPIOC, pin_mask_u32, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOC, pin_mask_u32, GPIO_PIN_RESET);
		}
		break;
		/**********************************************************************************************************************/
		case GPIO_PORT_PTD:
		{
			if (GPIO_DO_ON == state_are)
				HAL_GPIO_WritePin(GPIOD, pin_mask_u32, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOD, pin_mask_u32, GPIO_PIN_RESET);
		}
		break;
		/**********************************************************************************************************************/
		case GPIO_PORT_PTE:
		{
			if (GPIO_DO_ON == state_are)
				HAL_GPIO_WritePin(GPIOE, pin_mask_u32, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(GPIOE, pin_mask_u32, GPIO_PIN_RESET);
		}
		break;
		/**********************************************************************************************************************/
		default:
		{

		}
		break;
		/**********************************************************************************************************************/
	}
}


/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
void gpio_toggle_direct_output_v(const U16 pin_number_u16_aru16, const gpio_do_map_dir_tst *gpio_io_map_dir_arpst)
{
	U16 i_u16 = pin_number_u16_aru16;
	U16 port_u16;
	U32 pin_mask_u32;
	U16 pin_u16;
	port_u16 = gpio_io_map_dir_arpst[i_u16].gpio_port_reg_e;
	pin_u16 = gpio_io_map_dir_arpst[i_u16].gpio_pins_e;
	pin_mask_u32 = ((U32) COM_HDR_MASK_LO1_BIT << pin_u16);


	switch (port_u16)
	{
		/**********************************************************************************************************************/
		case GPIO_PORT_PTA:
		{
			HAL_GPIO_TogglePin(GPIOA, pin_mask_u32);
		}
		break;
		/**********************************************************************************************************************/
		case GPIO_PORT_PTB:
		{
			HAL_GPIO_TogglePin(GPIOB, pin_mask_u32);
		}
		break;
		/**********************************************************************************************************************/
		case GPIO_PORT_PTC:
		{
			HAL_GPIO_TogglePin(GPIOC, pin_mask_u32);
		}
		break;
		/**********************************************************************************************************************/
		case GPIO_PORT_PTD:
		{
			HAL_GPIO_TogglePin(GPIOD, pin_mask_u32);
		}
		break;
		/**********************************************************************************************************************/
		case GPIO_PORT_PTE:
		{
			HAL_GPIO_TogglePin(GPIOE, pin_mask_u32);
		}
		break;
		/**********************************************************************************************************************/
		default:
		{

		}
		break;
		/**********************************************************************************************************************/
	}
}

/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
void gpio_get_direct_input_v(const U16 pin_number_aru16, gpio_do_di_state_te *state_are, const gpio_do_map_dir_tst *gpio_io_map_dir_arpst)
{
	U16 i_u16 = pin_number_aru16;
		U16 port_u16;
		U16 pin_u16;
		BOOL pin_state_b;
		U32 pin_mask_u32;
		port_u16 = gpio_io_map_dir_arpst[i_u16].gpio_port_reg_e;
		pin_u16 = gpio_io_map_dir_arpst[i_u16].gpio_pins_e;
		pin_mask_u32 = ((U32) COM_HDR_MASK_LO1_BIT << pin_u16);

		switch (port_u16)
		{
		/**********************************************************************************************************************/
		case GPIO_PORT_PTA:
		{
			pin_state_b = HAL_GPIO_ReadPin(GPIOA, pin_mask_u32);
			if(pin_state_b  == 0 )
			{
				*state_are = GPIO_DO_OFF;
			}
			else
			{
				*state_are = GPIO_DO_ON;
			}

		}
		break;
		/**********************************************************************************************************************/
		case GPIO_PORT_PTB:
		{
			pin_state_b = HAL_GPIO_ReadPin(GPIOB, pin_mask_u32);
			if(pin_state_b  == 0 )
			{
				*state_are = GPIO_DO_OFF;
			}
			else
			{
				*state_are = GPIO_DO_ON;
			}
		}
		break;
		/**********************************************************************************************************************/
		case GPIO_PORT_PTC:
		{
			pin_state_b = HAL_GPIO_ReadPin(GPIOC, pin_mask_u32);
			if(pin_state_b  == 0 )
			{
				*state_are = GPIO_DO_OFF;
			}
			else
			{
				*state_are = GPIO_DO_ON;
			}
		}
		break;
		/**********************************************************************************************************************/
		case GPIO_PORT_PTD:
		{
			pin_state_b = HAL_GPIO_ReadPin(GPIOD, pin_mask_u32);
			if(pin_state_b  == 0 )
			{
				*state_are = GPIO_DO_OFF;
			}
			else
			{
				*state_are = GPIO_DO_ON;
			}
		}
		break;
		/**********************************************************************************************************************/
		case GPIO_PORT_PTE:
		{
			pin_state_b = HAL_GPIO_ReadPin(GPIOE, pin_mask_u32);
			if(pin_state_b  == 0 )
			{
				*state_are = GPIO_DO_OFF;
			}
			else
			{
				*state_are = GPIO_DO_ON;
			}
		}
		break;
		/**********************************************************************************************************************/
		default:
		{

		}
		break;
		/**********************************************************************************************************************/
		}
}

/****************************************************************************************************************************************************
* EOF
***************************************************************************************************************************************************/

