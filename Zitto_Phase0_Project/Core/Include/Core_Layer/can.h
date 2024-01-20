/*
 * can.h
 *
 *  Created on: Jan 7, 2024
 *      Author: Pavithraa
 */
#ifndef INCLUDE_CORE_LAYER_CAN_H_
#define INCLUDE_CORE_LAYER_CAN_H_

#include "main.h"

extern CAN_HandleTypeDef hcan;

/* Type definition */

#define CAN_IDE CAN_ID_EXT

typedef struct can_message_tst_tag
{
	U32 can_id_u32;
	U8  data_au8[8];
	U8  length_u8;
}can_message_tst;


/* Public Function Prototypes **/
extern U8 can_init_u8();
extern U8 can_transmit_data_u8(can_message_tst *msg_arpst);
extern U8 can_deinit_u8();

#endif

