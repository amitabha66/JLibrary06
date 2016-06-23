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
 * @file rtxPattern.h
 * Pattern matching functions.
 */
#ifndef _RTXPATTERN_H_
#define _RTXPATTERN_H_

#include "rtxsrc/rtxPattern.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup ccfPattern Pattern matching functions 
 * @{
 *
 * These functions handle pattern matching which is required to to process XML
 * schema pattern constraints.
 */
/**
 * This function compares the given string to the given pattern. It returns
 * true if match, false otherwise.
 *
 * @param pctxt        Pointer to context structure.
 * @param text         Text to be matched.
 * @param pattern      Regular expression.
 * @return             Boolean result.
 */
EXTERNRTX OSBOOL rtxMatchPattern (OSCTXT* pctxt, 
                                  const OSUTF8CHAR* text, 
                                  const OSUTF8CHAR* pattern);

EXTERNRTX OSBOOL rtxMatchPattern2 (OSCTXT* pctxt, 
                                   const OSUTF8CHAR* pattern);
/**
 * @} ccfPattern
 */

#ifdef __cplusplus
}
#endif

#endif
