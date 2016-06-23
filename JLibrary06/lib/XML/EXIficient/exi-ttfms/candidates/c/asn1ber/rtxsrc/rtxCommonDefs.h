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
#ifndef _RTXCOMMONDEFS_H_
#define _RTXCOMMONDEFS_H_

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <time.h>

/* Constants */

#define OSRTAGENT       "OSYSRTX"
#define OSRTVERSION     "0.5.0"
#define OSRTMEMBUFSEG   1024    /* memory buffer extent size            */

/* Macros */

#define OSRTMAX(a,b)        (((a)>(b))?(a):(b))
#define OSRTMIN(a,b)        (((a)<(b))?(a):(b))

#define OSRTBUFCUR(pctxt)   (pctxt)->buffer.data[(pctxt)->buffer.byteIndex]
#define OSRTBUFPTR(pctxt)   &(pctxt)->buffer.data[(pctxt)->buffer.byteIndex]
#define OSRTBUFFER(pctxt)   (pctxt)->buffer.data
#define OSRTBUFSIZE(pctxt)  (pctxt)->buffer.size

#define OSRTPUTCHAR(pctxt,ch) \
(pctxt)->buffer.data[(pctxt)->buffer.byteIndex++]=(OSOCTET)ch;

#define OSRTPUTCHARREV(pctxt,ch) \
(pctxt)->buffer.data[--(pctxt)->buffer.byteIndex]=(OSOCTET)ch;

#define OSRTZTERM(pctxt) \
(pctxt)->buffer.data[(pctxt)->buffer.byteIndex]=(OSOCTET)0;

#define OSRTSAFEZTERM(pctxt) \
do { \
if (rtxCheckBuffer (pctxt, 1) == 0) \
(pctxt)->buffer.data[(pctxt)->buffer.byteIndex]=(OSOCTET)0; \
else return LOG_RTERRNEW (pctxt, RTERR_BUFOVFLW); \
} while (0)

#define OSRTSAFEPUTCHAR(pctxt,ch) \
do { \
if (rtxCheckBuffer (pctxt, 1) == 0) \
(pctxt)->buffer.data[(pctxt)->buffer.byteIndex++]=(OSOCTET)ch; \
else return LOG_RTERRNEW (pctxt, RTERR_BUFOVFLW); \
} while (0)

#define OSRTSAFEPUTCHAR1(pctxt,ch,stat) \
do { \
if (rtxCheckBuffer (pctxt, 1) == 0) {\
(pctxt)->buffer.data[(pctxt)->buffer.byteIndex++]=(OSOCTET)ch; \
stat = 0; }\
else stat = LOG_RTERRNEW (pctxt, RTERR_BUFOVFLW); \
} while (0)

#define OSRTSAFEPUTCHAR2(pctxt,ch,prealloc) \
do { \
if (rtxCheckBuffer (pctxt, ((prealloc > 1)?prealloc:1)) == 0) \
(pctxt)->buffer.data[(pctxt)->buffer.byteIndex++]=(OSOCTET)ch; \
else return LOG_RTERRNEW (pctxt, RTERR_BUFOVFLW); \
} while (0)

#define OSRTMEMCPY(pctxt,bdata,len) \
do { \
memcpy (&(pctxt)->buffer.data[(pctxt)->buffer.byteIndex], bdata, len); \
(pctxt)->buffer.byteIndex += len; \
} while (0)

#define OSRTMEMCPYREV(pctxt,bdata,len) \
do { \
(pctxt)->buffer.byteIndex -= len; \
memcpy (&(pctxt)->buffer.data[(pctxt)->buffer.byteIndex], bdata, len); \
} while (0)

#define OSRTSAFEMEMCPY(pctxt,bdata,len) \
do { \
if (rtxCheckBuffer (pctxt, len) == 0) { \
memcpy (&(pctxt)->buffer.data[(pctxt)->buffer.byteIndex], bdata, len); \
(pctxt)->buffer.byteIndex += len; } \
else return LOG_RTERRNEW (pctxt, RTERR_BUFOVFLW); \
} while (0)

#define OSRTSAFEMEMCPY1(pctxt,bdata,len,stat) \
do { \
if (rtxCheckBuffer (pctxt, len) == 0) { \
memcpy (&(pctxt)->buffer.data[(pctxt)->buffer.byteIndex], bdata, len); \
(pctxt)->buffer.byteIndex += len; \
stat = 0; }\
else stat = RTERR_BUFOVFLW; \
} while (0)

#define OSRTCHKUTF8LEN(str,lower,upper,stat) \
do { size_t nchars = rtxUTF8Len (str); \
stat = (nchars >= lower && nchars <= upper) ? 0 : RTERR_CONSVIO; } while(0)

#define OSRTGETBUFUTF8LEN(pctxt) \
rtxCalcUTF8Len (OSRTBUFPTR (pctxt), OSRTBUFSIZE (pctxt))

#define OSRTCHKBUFUTF8LEN(pctxt,lower,upper,stat) \
do { size_t nchars = OSRTGETBUFUTF8LEN (pctxt); \
stat = (nchars >= lower && nchars <= upper) ? 0 : RTERR_CONSVIO; } while(0)

#define HEXCHARTONIBBLE(ch,b) do { \
if (ch >= '0' && ch <= '9') b = (unsigned char)(ch - '0'); \
else if (ch >= 'a' && ch <= 'f') b = (unsigned char)((ch - 'a') + 10); \
else if (ch >= 'A' && ch <= 'F') b = (unsigned char)((ch - 'A') + 10); \
else b = 0xFF; } while(0)

#define NIBBLETOHEXCHAR(b,ch) do { \
if (b >= 0 && b <= 9) ch = (char)(b + '0'); \
else if (b >= 0x0a && b <= 0x0f) ch = (char)((b - 10)+ 'a'); \
else ch = '?'; } while(0)

#define NIBBLETOUCHEXCHAR(b,ch) do { \
if (b >= 0 && b <= 9) ch = (char)(b + '0'); \
else if (b >= 0x0a && b <= 0x0f) ch = (char)((b - 10)+ 'A'); \
else ch = '?'; } while(0)

#define OSRTSAFECONSTCAST(towhere,ptr) ((towhere)((size_t)ptr))

#define OS_WHITESPACE_COLLAPSE 0
#define OS_WHITESPACE_PRESERVE 1
#define OS_WHITESPACE_REPLACE  2

#define OS_ISNULLPTR(ptr) (((const void*)0) == ptr)

#endif /* _RTXCOMMONDEFS_H_ */
