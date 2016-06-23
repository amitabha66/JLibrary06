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

#ifndef _RTXEXTERNDEFS_H_
#define _RTXEXTERNDEFS_H_

/** 
 * @file rtExternDefs.h 
 * Common definitions of external function modifiers used to define the 
 * scope of functions used in DLL's (Windows only).
 */
#ifdef BUILDDLL
#define EXTERN __declspec(dllexport)
#elif defined (USEDLL)
#define EXTERN __declspec(dllimport)
#else
#define EXTERN
#endif /* BUILDDLL */

#ifdef BUILDRTXDLL
#define EXTERNRTX __declspec(dllexport)
#elif defined (USERTXDLL)
#define EXTERNRTX __declspec(dllimport)
#else
#define EXTERNRTX
#endif /* BUILDRTDLL */

#endif
