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
 * @file rtXmlNamespace.h
 * XML namespace handling structures and function definitions.
 */
#ifndef _RTXMLNAMESPACE_H_
#define _RTXMLNAMESPACE_H_

#include "rtxmlsrc/osrtxml.h"

typedef struct OSXMLNamespace {
   const OSUTF8CHAR* prefix;
   const OSUTF8CHAR* uri;
} OSXMLNamespace;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This function adds a namespace to the context namespace list.  
 *
 * @param pctxt         Pointer to OSCTXT structure
 * @param prefix        Namespace prefix to be added
 * @param uri           Namespace URI to be added
 * @return              Pointer to namespace structure or NULL if not added.
 */
EXTERNXML OSXMLNamespace* rtXmlNSAddNamespace 
(OSCTXT* pctxt, const OSUTF8CHAR* prefix, const OSUTF8CHAR* uri);

/**
 * This function gets the namespace prefix assigned to the given URI.
 *
 * @param pctxt         Pointer to OSCTXT structure
 * @param uri           Namespace URI to be searched for
 * @return              Pointer to namespace prefix string
 */
EXTERNXML const OSUTF8CHAR* rtXmlNSGetPrefix 
(OSCTXT* pctxt, const OSUTF8CHAR* uri);

/**
 * This function looks up a namespace in the context namespace list using 
 * URI as the key value.
 *
 * @param pctxt         Pointer to OSCTXT structure
 * @param uri           Namespace URI to be found.
 * @return              Pointer to namespace structure or NULL if not found.
 */
EXTERNXML OSXMLNamespace* rtXmlNSLookupURI 
(OSCTXT* pctxt, const OSUTF8CHAR* uri);

/**
 * This function looks up a namespace in the context namespace list using
 * the prefix as the key value.
 *
 * @param pctxt         Pointer to OSCTXT structure
 * @param prefix        Namespace Prefix to be found.
 * @return              Pointer to namespace structure or NULL if not found.
 */
EXTERNXML OSXMLNamespace* rtXmlNSLookupPrefix
(OSCTXT* pctxt, const OSUTF8CHAR* prefix);

/**
 * This function removes all namespaces from the context namespace list and 
 * frees the dynamic memory used to hold the names.
 *
 * @param pctxt         Pointer to OSCTXT structure
 */
EXTERNXML void rtXmlNSRemoveAll (OSCTXT* pctxt);

/**
 * This function sets a namespace in the context namespace list.  If the 
 * given namespace URI does not exist in the list, the namespace is added. 
 * If the URI is found, the action depends on the value of the override 
 * flag.  If true, the value of the namespace prefix will be changed to 
 * the given prefix.  If false, the existing namespace specification is 
 * not altered.
 *
 * @param pctxt         Pointer to OSCTXT structure
 * @param prefix        Namespace prefix
 * @param uri           Namespace URI
 * @param override      Should existing definition be changed?
 * @return              Pointer to namespace structure or NULL if not set.
 */
EXTERNXML OSXMLNamespace* rtXmlNSSetNamespace 
(OSCTXT* pctxt, const OSUTF8CHAR* prefix, const OSUTF8CHAR* uri, 
 OSBOOL override);

/**
 * This function returns the next unused prefix of the form "nsX" where X
 * is a number. The new namespace declaration is added to the context
 * namespace list
 *
 * @param pctxt         Pointer to OSCTXT structure
 * @param uri           Namespace URI
 * @return              New namespace prefix.
 */
EXTERNXML const OSUTF8CHAR* rtXmlNSNewPrefix (OSCTXT* pctxt, const OSUTF8CHAR* uri);

#ifdef __cplusplus
}
#endif

#endif
