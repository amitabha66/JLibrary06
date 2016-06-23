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
/**
 * @file rtXmlErrCodes.h
 * List of numeric status codes that can be returned by ASN1C run-time 
 * functions and generated code.
 */
#ifndef _RTXMLERRCODES_H_
#define _RTXMLERRCODES_H_

#include "rtxsrc/rtxErrCodes.h"

/**
 * @defgroup xmlErrCodes Run-time error status codes.
 * This is a list of status codes that can be returned by the ASN1C 
 * run-time functions and generated code.  In many cases, additional 
 * information and parameters for the different errors are stored in 
 * the context structure at the time the error in raised.  This 
 * additional information can be output using the \c rtxErrPrint or 
 * \c rtxErrLogUsingCB run-time functions.
 * @{
 */
#define XML_OK_EOB      0x7fffffff      /* end of block                 */
#define XML_OK_FRAG     XML_OK_EOB      /* for backward compatibility   */

/**
 * Error base.  XML specific errors start at this base number to 
 * distinguish them from common and other error types.
 */
#define XML_E_BASE      -200

/**
 * General error
 */
#define XML_E_GENERR  (XML_E_BASE)

/**
 * Invalid symbol is detected.
 */
#define XML_E_INVSYMBOL    (XML_E_BASE-1)

/**
 * Start-end XML tags mismatch. Fatal error.
 */
#define XML_E_TAGMISMATCH    (XML_E_BASE-2)

/**
 * Duplicate attribute found.
 */
#define XML_E_DUPLATTR   (XML_E_BASE-3)

/**
 * Bad character reference found.
 */
#define XML_E_BADCHARREF  (XML_E_BASE-4)

/**
 * Invalid mode.
 */
#define XML_E_INVMODE  (XML_E_BASE-5)

/**
 * Unexpected end of file (document).
 */
#define XML_E_UNEXPEOF  (XML_E_BASE-6)

/**
 * Current tag is not matched to specified one. Informational code.
 */
#define XML_E_NOMATCH    (XML_E_BASE-7)

/**
 * Missing required element. This status code is returned by the decoder 
 * when the decoder knows exactly which element is absent.
 */
#define XML_E_ELEMMISRQ (XML_E_BASE-8)

/**
 * Missing required elements.  This status code is returned by the decoder 
 * when the number of elements decoded for a given content model group is 
 * less then the required number of elements as specified in the schema.
 */
#define XML_E_ELEMSMISRQ (XML_E_BASE-9)

/**
 * minOccurs is not reached.
 */
#define XML_E_TOOFEWELEMS (XML_E_BASE-10)

/**
 * Unexpected start tag.
 */
#define XML_E_UNEXPSTARTTAG (XML_E_BASE-11)

/**
 * Unexpected end tag.
 */
#define XML_E_UNEXPENDTAG (XML_E_BASE-12)

/**
 * @} xmlErrCodes
 */
#endif
