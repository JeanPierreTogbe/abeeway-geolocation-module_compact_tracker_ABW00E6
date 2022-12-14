/*
 * \file handling.c
 *
 * \brief somes encoding and swaping functions
 *
 *  Created on: 13 oct. 2022
 *      Author: Jean-PierreTogbe
 *
 *  copyright (C) 2022, Abeeway (www.abeeway.com). All Rights Reserved.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <strnhex.h>

#include "encode_handling.h"
#include "srv_lmh.h"
#include "srv_ble_scan.h"
#include "srv_cli.h"


#define MINM( a, b ) ( ( ( a ) < ( b ) ) ? ( a ) : ( b ) )
#define MAXM( a, b ) ( ( ( a ) > ( b ) ) ? ( a ) : ( b ) )


static float _step_size(float lo, float hi, unsigned nbits, unsigned nresv)
{
	return 1.0 / ((((1 << nbits) - 1) - nresv) / (hi - lo));
}

uint32_t mt_value_encode(float value, float lo, float hi, unsigned nbits,unsigned nresv)
{
	//Ensure value is within lo..hi bounds.
	value = MINM(value, hi);
	value = MAXM(value, lo);
	//return value offset by half the reserved value (the other half is at the end).
	return (nresv / 2) + ((value - lo) / _step_size(lo, hi, nbits, nresv));
}

bool _set_ble_scan_filter(uint8_t * dest, const char *src)
{
    uint8_t temp[SRV_BLE_SCAN_FILTER_MAX_SIZE] = {0};
    int count = strnhex(temp, SRV_BLE_SCAN_FILTER_MAX_SIZE, src);
    if (count <= 0) {
        cli_printf("Filter should be a hex value of max %d bytes\n", SRV_BLE_SCAN_FILTER_MAX_SIZE);
        return false;
    }

   memcpy(dest, temp, SRV_BLE_SCAN_FILTER_MAX_SIZE);
    return true;
}

void baswap(uint8_t *dest, uint8_t *src, uint8_t len)
{
	uint8_t i;

	if (!dest || !src)
		return;

	for (i = 0; i < len; i++) {
		dest[i] = src[len - 1 - i];
	}
}


