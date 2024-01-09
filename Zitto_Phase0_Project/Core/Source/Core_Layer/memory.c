/*
 * memory.c
 *
 *  Created on: Jan 7, 2024
 *      Author: Pavithraa
 */

/* Common Header Files */
#include "memory.h"
#include "../../include/core_layer/common_header.h"

/* Driver header */

/* Private Function Prototypes */

/* Private Variable Definitions */

/*  Public Variable Definitions */

/* Public Function Definitions */
inline void memory_copy_u8_array_v(U8* destination_arg_pu8, U8* source_arg_pu8, U32 bytes_to_copy_arg_u32);
inline void memory_set_u8_array_v(U8* destination_arg_pu8, U8 value_arg_u8, U32 bytes_to_copy_arg_u32);
U8 memory_comp_u8(U8 *val1_arpu8, U8 *val2_arpu8, U32 bytes_to_compare_aru32);

/**

Name		 : memory_copy_u8_array_v
Scope        : Public (inline)
Description  : To copy the data buffer from source location to destination
Input Data   : destination_arg_pu8, source_arg_pu8, bytes_to_copy_arg_u32
Return Value : NULL

**/
inline void memory_copy_u8_array_v(U8* destination_arg_pu8, U8* source_arg_pu8, U32 bytes_to_copy_arg_u32)
{
	U32 index_u32 = 0;

	for(;index_u32 < bytes_to_copy_arg_u32; index_u32++)
	{
		destination_arg_pu8[index_u32] = source_arg_pu8[index_u32];
	}
}

/**
Name			: memory_set_u8_array_v
Scope           : Public (inline)
Description  	: To set the memory of the destination array with any user-defined byte
Input Data   	: destination_arg_pu8, value_arg_u8( User-defined value), bytes_to_copy_arg_u32
Return Value	: NULL
**/
inline void memory_set_u8_array_v(U8* destination_arg_pu8, U8 value_arg_u8, U32 bytes_to_copy_arg_u32)
{
	U32 index_u32 = 0;

	for(;index_u32 < bytes_to_copy_arg_u32; index_u32++)
	{
		destination_arg_pu8[index_u32] = value_arg_u8;
	}
}

/**
Name	     : memory_comp_u8
Scope        : Public
Description  : To compare two different data buffers
Input Data   : val1_arpu8, val2_arpu8, bytes_to_compare_aru32( bytes of both array undergo comparison)
Return Value : zero if equals , non-zero if failed.
**/
U8 memory_comp_u8(U8 *val1_arpu8, U8 *val2_arpu8, U32 bytes_to_compare_aru32)
{
	U32 index_u32 = 0;

	for(;index_u32 < bytes_to_compare_aru32; index_u32++)
	{
		if(val1_arpu8[index_u32] != val2_arpu8[index_u32])
		{
			return 1;			/* Failure due to compared values are not same */
		}
	}

	return 0;	/* compared values are same */
}
