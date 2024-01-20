/*
 * can.c
 *
 *  Created on: Jan 7, 2024
 *      Author: Pavithraa
 */

/* Common Header Files */
#include "common_header.h"

/* Application Header File */

/* Configuration Header File */
#include "can_app.h"
//#include "bootsm.h"

/* This header file */

/* Driver header */
//#include "system.h"
#include "can.h"

/* Private Definitions */
uint8_t can_rx_data_u8[8] = {0};
CAN_RxHeaderTypeDef can_rx_header_st[100];
CAN_RxHeaderTypeDef can_copy_rx_header_st[100];
uint8_t arrary_size_u8 = 0;

CAN_HandleTypeDef hcan;
/* Private Function Prototypes */

/* Public Variable Definitions */

/* Public Function Definitions */
void can_filter_init_v();
/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
U8 can_init_u8()
{
	/* 250Kbps configuration */
	U8 ret_val_u8 = 0;
	hcan.Instance = CAN;
	hcan.Init.Prescaler = 6;
	hcan.Init.Mode = CAN_MODE_NORMAL;
	hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
	hcan.Init.TimeSeg1 = CAN_BS1_13TQ;
	hcan.Init.TimeSeg2 = CAN_BS2_2TQ;
	hcan.Init.TimeTriggeredMode = DISABLE;
	hcan.Init.AutoBusOff = DISABLE;
	hcan.Init.AutoWakeUp = DISABLE;
	hcan.Init.AutoRetransmission = DISABLE;
	hcan.Init.ReceiveFifoLocked = DISABLE;
	hcan.Init.TransmitFifoPriority = DISABLE;
	if (HAL_CAN_Init(&hcan) != HAL_OK)
	{
		Error_Handler();/*CAN Init configuration Error */
	}
	/* Start the CAN module */
	HAL_CAN_Start(&hcan);
	/*Enable CAN interrupts*/
	if (HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
	{
	  Error_Handler(); /*CAN Interrupt Activation Error*/
	}
	HAL_NVIC_EnableIRQ(CAN_RX0_IRQn);
	/* CAN Filter configuration */
	can_filter_init_v();
	return(ret_val_u8);
}

/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/

void can_filter_init_v()
{
	CAN_FilterTypeDef sFilterConfig;

	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	sFilterConfig.FilterIdHigh = 0;
	sFilterConfig.FilterIdLow = 0;
	sFilterConfig.FilterMaskIdHigh = 0;
	sFilterConfig.FilterMaskIdLow = 0;
	sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
	sFilterConfig.FilterActivation = ENABLE;
	sFilterConfig.FilterBank = 0;

	if (HAL_CAN_ConfigFilter(&hcan, &sFilterConfig) != HAL_OK)
	{
		/* Filter configuration Error */
	}

}

/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
U8 can_transmit_data_u8(can_message_tst *msg_arpst)
{
	U8 ret_val_u8 = 0;

	/* Transmit the CAN message based on the required mode */
	CAN_TxHeaderTypeDef tx_header_st;
	U32 tx_mail_box_u32 = 0;

	tx_header_st.DLC = msg_arpst->length_u8;
	tx_header_st.IDE = CAN_IDE;
	if(CAN_IDE == CAN_ID_EXT)
	{
		tx_header_st.ExtId = msg_arpst->can_id_u32;
	}
	else if (CAN_IDE == CAN_ID_STD)
	{
		tx_header_st.StdId = msg_arpst->can_id_u32;
	}

	tx_header_st.RTR = CAN_RTR_DATA;

	if(HAL_CAN_AddTxMessage(&hcan, &tx_header_st, msg_arpst->data_au8, &tx_mail_box_u32) != HAL_OK)
	{
		ret_val_u8 ++;/* CAM Transmission Error */
	}

	if(HAL_CAN_IsTxMessagePending(&hcan,tx_mail_box_u32)!= HAL_OK)
	{
		ret_val_u8 ++; /* CAM Pending Error */
	}
	return ret_val_u8;
}
/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/

void USB_LP_CAN_RX0_IRQHandler(void)
{
	HAL_CAN_IRQHandler(&hcan);
	if(HAL_CAN_GetRxMessage(&hcan, CAN_RX_FIFO0, &can_rx_header_st[arrary_size_u8], can_rx_data_u8) == HAL_OK)
	{

	}
	else
	{

	}
	can_app_0_rx_callback();
}

/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
U8 can_deinit_u8()
{
	U8 ret_val_u8 = 0;
	if(HAL_CAN_DeInit(&hcan) != HAL_OK)
	{
		ret_val_u8 ++;/* CAN Deinit Error */
	}

	return ret_val_u8;
}

