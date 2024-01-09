/*
 *  memory.h
 *
 *  Created on: Jan 7, 2024
 *      Author: Pavithraa
 */
#ifndef INCLUDE_CORE_LAYER_MEMORY_H_
#define INCLUDE_CORE_LAYER_MEMORY_H_

/* Includes for definitions */
#include "common_header.h"

/* Public Function Prototypes **/
extern void memory_copy_u8_array_v(U8* destination_arg_pu8, U8* source_arg_pu8, U32 bytes_to_copy_arg_u32);
extern void memory_set_u8_array_v(U8* destination_arg_pu8, U8 value_arg_u8, U32 bytes_to_copy_arg_u32) ;
extern U8 memory_comp_u8(U8 *val1_arpu8, U8 *val2_arpu8, U32 bytes_to_compare_aru32);
#endif /* INCLUDE_CORE_LAYER_MEMORY_H_ */
