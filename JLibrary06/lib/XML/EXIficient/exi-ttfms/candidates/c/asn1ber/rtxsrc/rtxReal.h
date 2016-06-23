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
 * @file rtxReal.h 
 * Common runtime functions for working with floating-point numbers.
 */
#ifndef _RTXREAL_H_
#define _RTXREAL_H_

#include "rtxsrc/osSysTypes.h"
#include "rtxsrc/rtxExternDefs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup rtxReal Floating-point number utility functions
 * @{
 * Floating-point utility function provide run-time functions for handling 
 * floating-point number types defined within a schema.
 */
/* These need to be documented.. */

EXTERNRTX OSREAL rtxGetMinusInfinity ();
EXTERNRTX OSREAL rtxGetMinusZero ();
EXTERNRTX OSREAL rtxGetNaN ();
EXTERNRTX OSREAL rtxGetPlusInfinity ();
EXTERNRTX OSBOOL rtxIsMinusInfinity (OSREAL value);
EXTERNRTX OSBOOL rtxIsMinusZero (OSREAL value);
EXTERNRTX OSBOOL rtxIsNaN (OSREAL value);
EXTERNRTX OSBOOL rtxIsPlusInfinity (OSREAL value);

/**
 * @} rtxReal
 */

#ifdef __cplusplus
}
#endif

#endif
