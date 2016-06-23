/*
 * Copyright (c) 1997-2006 Objective Systems, Inc.
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

#ifndef _OSMACROS_H_
#define _OSMACROS_H_

/* Min/max tests */
#define OS_MAX(a,b) (((a)>(b))?(a):(b))
#define OS_MIN(a,b) (((a)<(b))?(a):(b))

/* Test if character is a hex character */
#define OS_ISHEXCHAR(c) \
((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))

/* Test if string variable (const char*) is empty */
#define OS_ISEMPTY(s) (s == 0 || *s == '\0')

/* Nibble-to-hex char conversion macros */
#define OS_HEXCHARTONIBBLE(ch,b) do { \
if (ch >= '0' && ch <= '9') b = (unsigned char)(ch - '0'); \
else if (ch >= 'a' && ch <= 'f') b = (unsigned char)((ch - 'a') + 10); \
else if (ch >= 'A' && ch <= 'F') b = (unsigned char)((ch - 'A') + 10); \
else b = 0xFF; } while(0)

#define OS_NIBBLETOHEXCHAR(b,ch) do { \
if (b >= 0 && b <= 9) ch = (char)(b + '0'); \
else if (b >= 0x0a && b <= 0x0f) ch = (char)((b - 10)+ 'a'); \
else ch = '?'; } while(0)

/* Generic list iteration macros */

#define ForAllIter(p,listIter,type) \
for(listIter.setFirst(),p=(type)listIter.getCurrentItem();!listIter.isDone();\
listIter.setNext(),p=(type)listIter.getCurrentItem())

#define ForAllIterRev(p,listIter,type) \
for(listIter.setLast(),p=(type)listIter.getCurrentItem();!listIter.isDone();\
listIter.setPrev(),p=(type)listIter.getCurrentItem())

/* snprintf macros */

#include <stdio.h>
#include <stdarg.h>

#if defined(_MSC_VER)
#  define os_snprintf _snprintf
#  define os_vsnprintf _vsnprintf
#elif defined(__HP_aCC)
/* at least aCC on HP-UX 11 expects format as non-const! */
#  define os_snprintf(str, size, ...) sprintf(str, __VA_ARGS__)
#  define os_vsnprintf(str, size, fmt, ...) \
      vsnprintf(str, size, (char *)fmt, __VA_ARGS__)
#elif defined(_NO_SNPRINTF_)
#  define os_snprintf(str, size, ...) sprintf(str, __VA_ARGS__)
#  define os_vsnprintf(str, size, fmt, ...) vsprintf(str, fmt, __VA_ARGS__)
#else
#  define os_snprintf snprintf
#  define os_vsnprintf vsnprintf
#endif

#endif

