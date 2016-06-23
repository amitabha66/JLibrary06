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
 * @file rtxBuffer.h 
 * Common runtime functions for reading from or writing to the message 
 * buffer defined within the context structure.
 */
#ifndef _RTXBUFFER_H_
#define _RTXBUFFER_H_

#include "rtxsrc/rtxContext.h"

#ifdef __cplusplus
extern "C" {
#endif

EXTERNRTX OSINT32 rtxCheckBuffer (OSCTXT* pctxt, size_t nbytes);

EXTERNRTX OSINT32 rtxCopyAsciiText (OSCTXT* pctxt, const char* text);

EXTERNRTX OSINT32 rtxCopyUTF8Text (OSCTXT* pctxt, const OSUTF8CHAR* text);

EXTERNRTX OSINT32 rtxCopyUnicodeText (OSCTXT* pctxt, const OSUNICHAR* text);

EXTERNRTX int rtxWriteBytes 
(OSCTXT* pctxt, const OSOCTET* pdata, size_t nocts);

#ifdef __cplusplus
}
#endif

#endif
