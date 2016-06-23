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

#ifndef _RTXUTIL_H_
#define _RTXUTIL_H_

#include "rtxsrc/rtxExternDefs.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Utility functions */

EXTERNRTX OSUINT32 rtxGetIdentByteCount (OSUINT32 ident);

EXTERNRTX OSUINT32 rtxGetIdent64ByteCount (OSUINT64 ident);

EXTERNRTX OSUINT32 rtxIntByteCount (OSINT32 val);

EXTERNRTX OSUINT32 rtxOctetBitLen (OSOCTET w);

#ifdef __cplusplus
}
#endif

#endif
