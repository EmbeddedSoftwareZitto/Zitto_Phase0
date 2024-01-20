/*
 * can_app.h
 *
 *  Created on: Jan 19, 2024
 *      Author: Pavithraa
 */
#ifndef CONFIGURATION_LAYER_DEVICE_DRIVER_CAN_APP_H_
#define CONFIGURATION_LAYER_DEVICE_DRIVER_CAN_APP_H_

/* Includes for definitions */
#include "common_header.h"
#include "can.h"

#include "gpio_app.h"
//#include "can_commtask.h"

/* Macro Definitions */
#define CAN_STB_ENABLE									gpio_app_set_digital_output_v(MCU_STB_CAN_PTA8, GPIO_DO_ON)
#define CAN_STB_DISABLE									gpio_app_set_digital_output_v(MCU_STB_CAN_PTA8, GPIO_DO_OFF)

#define CAN_RESERVED                 ((U32)(0))
#define CAN_DATA_PAGE                ((U32)(0))

#define CAN_APP_GET_ID(PRIO,PDU_F,PDU_S,SA)  	(U32)((PRIO<<26)|(CAN_APP_RESERVED<<25)|(CAN_APP_DATA_PAGE<<24)|(PDU_F<<16)|(PDU_S<<8)|(SA))
#define CAN_APP_GET_BITS(x,p,n)              	(U32)((~((~0)<<n))&(x>>(p-n+1)))
#define CAN_APP_BASE_ID(id)                  	(CAN_APP_GET_BITS(id,28,11))
#define CAN_APP_EXT_ID(id)                   	(CAN_APP_GET_BITS(id,17,18))
#define CAN_APP_GET_PF(ID)                   	(U8)(ID>>26)
#define CAN_APP_GET_PGN(ID)                  	(U8)(ID>>16)
#define CAN_APP_GET_SRC_DES_ID				 	()

#define CAN_APP_MAX_DATA_BYTES							7

#define CAN_APP_RESERVED                 		((U32)(0))
#define CAN_APP_DATA_PAGE                		((U32)(0))
#define CAN_APP_RTR                      		((BOOL)(0))
#define CAN_APP_IDE                      		((BOOL)(1))
#define CAN_APP_SRR                      		((BOOL)(1))

#define CAN_APP_RX_BUFFER_LEN    				16

#define CAN_APP_PWR_SW_ENABLE					//
#define CAN_APP_PWR_SW_DISABLE					//gpio_app_set_digital_output_v(, GPIO_DO_OFF)

typedef struct can_app_message_tst_tag
{
	U32 can_id_u32;
  U8  data_au8[8];
  U8  length_u8;
}can_app_message_tst;

typedef struct can_app_state_struct_tst_tag
{
  U8 can_set_time_en_u8;
}can_app_state_struct_tst;

//MAX_SM_CAN_APP = 2
//can_app_state_struct_tst can_comm_set_timer_gst[2];
/*  Public Variable Definitions */
extern U8 can_app_rx_msg_index_gu8;
extern can_app_message_tst can_app_rx_message_st;
extern can_app_message_tst can_app_last_tx_msg_st;

/* Public Function Prototypes **/
extern U8 can_app_init_u8();
extern U8 can_app_frame_and_tx_msg_u8(U32 base_id_aru32,U32 extd_id_aru32,U32 rtr_aru32,U32 ide_aru32,BOOL srr_arb,U8 dlc_bytes_aru8,U8 *data_arpu8);
extern U8 can_app_transmit_data_u8(can_app_message_tst *msg_arpst);
extern void can_app_0_rx_callback();
extern U8 can_app_deinit_u8();

#endif /* CONFIGURATION_LAYER_DEVICE_DRIVER_CAN_APP_H_ */
