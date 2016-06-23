/*
 * Copyright (c) 2003-2006 Objective Systems, Inc.
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
 * @file rtxEnum.h 
 * Common runtime types and functions for performing operations on 
 * enumerated data items.
 */
#ifndef _RTXENUM_H_
#define _RTXENUM_H_

#include "rtxsrc/rtxContext.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup rtxEnum Enumeration utility functions
 * @{
 * Enumeration utility function provide run-time functions for handling 
 * enumerations defined within a schema.
 */
typedef struct OSEnumItem {
   const OSUTF8CHAR* name;
   OSINT32           value;
   OSUINT16          namelen;
   OSUINT16          transidx;
} OSEnumItem;

typedef struct OSNumericEnumItem {
   OSINT32           start;
   OSINT32           end;
} OSNumericEnumItem;

/**
 * This function will return the numeric value for the given enumerated 
 * identifier string.
 *
 * @param strValue Enumerated identifier value
 * @param strValueSize Length of enumerated identifier
 * @param enumTable Table containing the defined enumeration
 * @param enumTableSize Number of rows in the table
 * @return Index to enumerated item if found; otherwise, negative 
 *   status code (RTERR_INVENUM).
 */
EXTERNRTX OSINT32 rtxLookupEnum
(const OSUTF8CHAR* strValue, size_t strValueSize, 
 const OSEnumItem enumTable[], OSUINT16 enumTableSize);

/**
 * Lookup enum by integer value.  Required for ASN.1 because enumerated 
 * values do not need to be sequential.
 *
 * @param value  Integer value of the enumerated item.
 * @param enumTable Table containing the defined enumeration
 * @param enumTableSize Number of rows in the table
 * @return Index to enumerated item if found; otherwiae, negative 
 *   status code (RTERR_INVENUM).
 */
OSINT32 rtxLookupEnumByValue 
(OSINT32 value, const OSEnumItem enumTable[], size_t enumTableSize);

/**
 * This function determines if the given numeric enumerated value is within 
 * the defined numeration set.
 *
 * @param ivalue Numeric enumerated value
 * @param enumTable Table containing the defined enumeration
 * @param enumTableSize Number of rows in the table
 * @return Zero (0) if item in table, RTERR_INVENUM if not
 */
EXTERNRTX int rtxTestNumericEnum 
(OSINT32 ivalue, const OSNumericEnumItem enumTable[], OSUINT16 enumTableSize);

/**
 * @} rtxEnum
 */
#ifdef __cplusplus
}
#endif

#endif
