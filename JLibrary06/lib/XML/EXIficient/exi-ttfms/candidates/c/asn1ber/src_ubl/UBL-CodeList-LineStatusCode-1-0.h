/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#ifndef UBL_CODELIST_LINESTATUSCODE_1_0_H
#define UBL_CODELIST_LINESTATUSCODE_1_0_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include "rtkey.h"
#include "asn1ber.h"
#include "libxml/parser.h"

/**************************************************************/
/*                                                            */
/*  LineStatusCodeContentType                                 */
/*                                                            */
/**************************************************************/

#define TV_LineStatusCodeContentType	(TM_UNIV|TM_PRIM|10)

typedef enum {
   added = 0,
   cancelled_1 = 1,
   disputed_1 = 2,
   noStatus_1 = 3,
   revised_1 = 4
} LineStatusCodeContentType_Root;

typedef OSUINT32 LineStatusCodeContentType;

EXTERN int asn1E_LineStatusCodeContentType (OSCTXT* pctxt,
   LineStatusCodeContentType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_LineStatusCodeContentType (OSCTXT* pctxt,
   LineStatusCodeContentType *pvalue, ASN1TagType tagging, int length);

EXTERN const OSUTF8CHAR* LineStatusCodeContentType_ToString (OSINT32 value);

EXTERN int LineStatusCodeContentType_ToEnum
  (const OSUTF8CHAR* value, LineStatusCodeContentType* pvalue);

/**************************************************************/
/*                                                            */
/*  LineStatusCodeType                                        */
/*                                                            */
/**************************************************************/

#define TV_LineStatusCodeType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN LineStatusCodeType {
   struct {
      unsigned codeListAgencyIDPresent : 1;
      unsigned codeListAgencyNamePresent : 1;
      unsigned codeListIDPresent : 1;
      unsigned codeListNamePresent : 1;
      unsigned codeListSchemeURIPresent : 1;
      unsigned codeListURIPresent : 1;
      unsigned codeListVersionIDPresent : 1;
      unsigned languageIDPresent : 1;
      unsigned namePresent : 1;
   } m;
   const OSUTF8CHAR* codeListAgencyID;
   const OSUTF8CHAR* codeListAgencyName;
   const OSUTF8CHAR* codeListID;
   const OSUTF8CHAR* codeListName;
   const OSUTF8CHAR* codeListSchemeURI;
   const OSUTF8CHAR* codeListURI;
   const OSUTF8CHAR* codeListVersionID;
   const OSUTF8CHAR* languageID;
   const OSUTF8CHAR* name;
   LineStatusCodeContentType base;
} LineStatusCodeType;

EXTERN int asn1E_LineStatusCodeType (OSCTXT* pctxt,
   LineStatusCodeType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_LineStatusCodeType (OSCTXT* pctxt,
   LineStatusCodeType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_LineStatusCodeType (OSCTXT* pctxt, 
   LineStatusCodeType* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_LineStatusCodeType (LineStatusCodeType* pvalue);

#ifdef __cplusplus
}
#endif

#endif