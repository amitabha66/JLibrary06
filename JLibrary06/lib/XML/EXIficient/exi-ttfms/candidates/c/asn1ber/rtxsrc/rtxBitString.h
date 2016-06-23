/*
 * Copyright (C) 2003-2005 by Objective Systems, Inc.
 *
 * This software is furnished under a license and may be used and copied
 * only in accordance with the terms of such license and with the
 * inclusion of the above copyright notice. This software or any other
 * copies thereof may not be provided or otherwise made available to any
 * other person. No title to and ownership of the software is hereby
 * transferred.
 *
 * The information in this software is subject to change without notice
 * and should not be construed as a commitment by Objective Systems, Inc.
 *
 * PROPRIETARY NOTICE
 *
 * This software is an unpublished work subject to a confidentiality agreement
 * and is protected by copyright and trade secret law.  Unauthorized copying,
 * redistribution or other use of this work is prohibited.
 *
 * The above notice of copyright on this source code product does not indicate
 * any actual or intended publication of such source code.
 *
 *****************************************************************************/
/** 
 * @file rtxBitString.h - Contains utility functions for setting, clearing, 
 * and testing bits at any position in an arbitrarily sized array of bytes.
 */
#ifndef _RTXBITSTRING_H_
#define _RTXBITSTRING_H_

#include "rtxsrc/rtxContext.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup bitstrhelpers Bit String Functions 
 * @{
 *
 * Bit string functions allow bits to be set, cleared, or tested in 
 * arbitrarily sized byte arrays.
 */
typedef struct OSBitMapItem {
   const OSUTF8CHAR* name;
   OSUINT16          bitno;
   OSUINT16          namelen;
} OSBitMapItem;

/**
 * This function sets the specified bit in the bit string.
 *
 * @param pBits        Pointer to octets of bit string.
 * @param numbits      Number of bits in the bit string.
 * @param bitIndex     Index of bit to be set. The bit with index 0 is a most
 *                       significant bit in the octet with index 0.
 * @return             If successful, returns the previous state of bit. If bit
 *                       was set the return value is positive, if bit was not
 *                       set the return value is zero. Otherwise, return value
 *                       is an error code:
 *                       - RTERR_OUTOFBND = bitIndex is out of bounds
 */
EXTERNRTX int rtxSetBit (OSOCTET* pBits, OSUINT32 numbits, OSUINT32 bitIndex);

/**
 * This function clears the specified bit in the bit string.
 *
 * @param pBits        Pointer to octets of bit string.
 * @param numbits      Number of bits in the bit string.
 * @param bitIndex     Index of bit to be cleared. The bit with index 0 is a
 *                       most significant bit in the octet with index 0.
 * @return             If successful, returns the previous state of bit. If bit
 *                       was set the return value is positive, if bit was not
 *                       set the return value is zero. Otherwise, return value
 *                       is an error code:
 *                       - RTERR_OUTOFBND = bitIndex is out of bounds
 */
EXTERNRTX int rtxClearBit 
(OSOCTET* pBits, OSUINT32 numbits, OSUINT32 bitIndex);

/**
 * This function tests the specified bit in the bit string.
 *
 * @param pBits        Pointer to octets of bit string.
 * @param numbits      Number of bits in the bit string.
 * @param bitIndex     Index of bit to be tested. The bit with index 0 is a
 *                       most significant bit in the octet with index 0.
 * @return             True if bit set or false if not set or array index is
 *                       beyond range of number of bits in the string.
 */
EXTERNRTX OSBOOL rtxTestBit 
(const OSOCTET* pBits, OSUINT32 numbits, OSUINT32 bitIndex);

/** 
 * This function converts the given null-terminated UTF-8 string
 * to named bit items.  The token-to-bit mappings are defined by 
 * a bit map table that is passed into the function.  It is assumed 
 * the string contains a space-separated list of named bit token 
 * values. 
 *
 * @param pctxt        Context structure
 * @param utf8str      Null-terminated UTF-8 string to convert
 * @param pBitMap      Bit map defining bit to otken mappings
 * @param pvalue       Pointer to byte array to receive result.
 * @param pnbits       Pointer to integer to received number of bits.
 * @param bufsize      Size of byte array to received decoded bits.
 * @return             Status: 0 = OK, negative value = error
 */
EXTERNRTX int rtxUTF8StrToNamedBits (OSCTXT* pctxt, const OSUTF8CHAR* utf8str, 
   const OSBitMapItem* pBitMap, OSOCTET* pvalue, OSUINT32* pnbits, 
   OSUINT32 bufsize);

/**
 * @}bitstrhelpers
 */
#ifdef __cplusplus
}
#endif

#endif
