/*
 * can_app.c
 *
 *  Created on: Jan 19, 2024
 *      Author: Pavithraa
 */

/* Common Header Files */
#include "common_header.h"
/* Application Header File */
//#include "can_commtask.h"
//#include "system.h"

/* Configuration Header File */
//#include "operating_system.h"

/* This header file */
#include "can_app.h"

/* Driver header */
#include "can.h"
#include "memory.h"

/* Private Definitions **/

/* Private Function Prototypes */

/* Private Variable Definitions */

/*  Public Variable Definitions */
U8 can_app_rx_msg_index_gu8 = 0;

can_app_message_tst can_app_rx_msg_index_agst[CAN_APP_RX_BUFFER_LEN];
can_app_message_tst can_app_last_tx_msg_st;

can_app_message_tst can_app_rx_message_st;

/** @} */

/* Public Function Definitions */


/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
U8 can_app_init_u8()
{
	U8 ret_val_u8 = 0;

	if(can_init_u8())
	{
		/*CAN APP Init Error*/
		ret_val_u8 += 1;
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
U8 can_app_frame_and_tx_msg_u8(U32 base_id_aru32,U32 extd_id_aru32,U32 rtr_aru32,U32 ide_aru32,BOOL srr_arb,U8 dlc_bytes_aru8,U8 *data_arpu8)
{
	U8 can_tx_status_u8 = 0;
	can_app_message_tst can_msg_tx_st;

	can_msg_tx_st.can_id_u32 = (base_id_aru32 <<18) | extd_id_aru32;
	can_msg_tx_st.length_u8 = dlc_bytes_aru8;
	memory_copy_u8_array_v(can_msg_tx_st.data_au8, (void*) data_arpu8, can_msg_tx_st.length_u8);

	can_app_last_tx_msg_st.length_u8 = can_msg_tx_st.length_u8;
	can_app_last_tx_msg_st.can_id_u32 = can_msg_tx_st.can_id_u32;
	memory_copy_u8_array_v(can_app_last_tx_msg_st.data_au8, (void*)can_msg_tx_st.data_au8, can_msg_tx_st.length_u8);

	/*STATUS_TIMEOUT is used to avoid CAN transmission is getting stopped due to can wire gets disconnected*/
	if(can_app_transmit_data_u8(&can_msg_tx_st) != SUCCESS)
	{
		//app_main_system_flt_status_u64 |= ((U64)1 << FAULT_BIT_CAN_TX);
	}
	else
	{
		can_tx_status_u8 = 1;
	}

	return can_tx_status_u8;
}


/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
U8 can_app_transmit_data_u8(can_app_message_tst *msg_arpst)
{
	U8 ret_val_u8 = 0;

	ret_val_u8 = can_transmit_data_u8((can_message_tst*)msg_arpst);

	if(ret_val_u8)
	{
		ret_val_u8++;
		//app_main_system_flt_status_u64 |= ((U64)1 << FAULT_BIT_CAN_TX);
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
void can_app_0_rx_callback()
{
//	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
//
//	operating_system_can_comm_queue_tst os_can_rx_queue_st;
//	can_app_rx_msg_index_agst[can_app_rx_msg_index_gu8].length_u8 = can_app_rx_message_st.length_u8;
//	can_app_rx_msg_index_agst[can_app_rx_msg_index_gu8].can_id_u32 = can_app_rx_message_st.can_id_u32;
//	memory_copy_u8_array_v(can_app_rx_msg_index_agst[can_app_rx_msg_index_gu8].data_au8, can_app_rx_message_st.data_au8,
//			can_app_rx_message_st.length_u8);
//
//
//	if(COMMON_VAR_DEBUG_SM == can_commtask_identify_comm_type_u8(can_app_rx_msg_index_agst[can_app_rx_msg_index_gu8].can_id_u32))
//	{
//		if(can_app_rx_msg_index_agst[can_app_rx_msg_index_gu8].can_id_u32  == CLIENT_COMM_START_STOP_RES)
//		{
//			client_gui_u32 = 1;
//			debug_gui_u8 = 0;
//		}
//		if((can_app_rx_msg_index_agst[can_app_rx_msg_index_gu8].can_id_u32  == DBEUG_COMM_START_STOP_RES)
//			|| (can_app_rx_msg_index_agst[can_app_rx_msg_index_gu8].can_id_u32  == 0x888DAFA))
//		{
//			client_gui_u32 = 0;
//			debug_gui_u8 = 1;
//		}
//		if(client_gui_u32)
//		{
//			os_can_rx_queue_st.comm_event_e = OS_CAN_CLIENT_RX;
//		}
//		if(debug_gui_u8)
//		{
//			os_can_rx_queue_st.comm_event_e = OS_CAN_DEBUG_RX;
//		}
//	}
//	else if(COMMON_VAR_UNBOX_SM == can_commtask_identify_comm_type_u8(can_app_rx_msg_index_agst[can_app_rx_msg_index_gu8].can_id_u32))
//	{
//		os_can_rx_queue_st.comm_event_e = OS_CAN_UNBOX_RX;
//	}
//	else if(COMMON_VAR_CHARGER_SM == can_commtask_identify_comm_type_u8(can_app_rx_msg_index_agst[can_app_rx_msg_index_gu8].can_id_u32))
//	{
//		os_can_rx_queue_st.comm_event_e = OS_CAN_CHARGER_RX;
//	}
//	/* TODO: Split the below else condition for Charging & driving to send the queue with different event	 */
//	else
//	{
//		os_can_rx_queue_st.comm_event_e = OS_CAN_RX;
//	}
//	os_can_rx_queue_st.can_rx_msg_pv = &can_app_rx_msg_index_agst[can_app_rx_msg_index_gu8];
//
//	if (can_app_rx_msg_index_gu8 < (CAN_APP_RX_BUFFER_LEN-1)) /* Note: Don't remove -1 due to some memory illegal overwrite problem */
//	{
//		can_app_rx_msg_index_gu8++;
//	}
//	else
//	{
//		can_app_rx_msg_index_gu8 = 0;
//	}
//
//	xQueueSendFromISR(os_can_comm_queue_handler_ge, &os_can_rx_queue_st, &xHigherPriorityTaskWoken);
//	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

}

/**
Name		 :
Scope        :
Description  :
Input Data   :
Return Value :
**/
U8 can_app_deinit_u8()
{
	U8 ret_val_u8 = 0;

	ret_val_u8 = can_deinit_u8();

	return ret_val_u8;
}

/****************************************************************************************************************************************************
 * EOF
 ***************************************************************************************************************************************************/
