/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#ifndef XLINK_H
#define XLINK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include "rtkey.h"
#include "rtbersrc/asn1ber.h"
#include "rtsrc/asn1type.h"
#include "rtxmlsrc/asn1xml.h"
#include "libxml/parser.h"

/**
 * Header file for ASN.1 module Xlink
 */
/**************************************************************/
/*                                                            */
/*  Href                                                      */
/*                                                            */
/**************************************************************/

#define TV_Xlink_Href	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* Xlink_Href;

EXTERN int asn1E_Xlink_Href (OSCTXT* pctxt,
   Xlink_Href pvalue, ASN1TagType tagging);

EXTERN int asn1D_Xlink_Href (OSCTXT* pctxt, Xlink_Href *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_Xlink_Href (OSCTXT* pctxt, Xlink_Href value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Xlink_Href (OSCTXT* pctxt, Xlink_Href* pvalue);

/**************************************************************/
/*                                                            */
/*  Type                                                      */
/*                                                            */
/**************************************************************/

#define TV_Xlink_Type	(TM_UNIV|TM_PRIM|10)

typedef enum {
   Type_simple = 0
} Xlink_Type_Root;

typedef OSUINT32 Xlink_Type;

EXTERN int asn1E_Xlink_Type (OSCTXT* pctxt,
   Xlink_Type *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Xlink_Type (OSCTXT* pctxt, Xlink_Type *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_Xlink_Type (OSCTXT* pctxt, Xlink_Type value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Xlink_Type (OSCTXT* pctxt, Xlink_Type* pvalue);

EXTERN const OSUTF8CHAR* Xlink_Type_ToString (OSINT32 value);

EXTERN int Xlink_Type_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Xlink_Type* pvalue);

#ifdef __cplusplus
}
#endif

#endif
