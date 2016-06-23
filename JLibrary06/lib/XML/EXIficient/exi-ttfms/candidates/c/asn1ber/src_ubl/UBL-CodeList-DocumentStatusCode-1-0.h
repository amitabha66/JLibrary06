/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#ifndef UBL_CODELIST_DOCUMENTSTATUSCODE_1_0_H
#define UBL_CODELIST_DOCUMENTSTATUSCODE_1_0_H

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
/*  DocumentStatusCodeContentType                             */
/*                                                            */
/**************************************************************/

#define TV_DocumentStatusCodeContentType	(TM_UNIV|TM_PRIM|10)

typedef enum {
   cancelled = 0,
   disputed = 1,
   noStatus = 2,
   revised = 3
} DocumentStatusCodeContentType_Root;

typedef OSUINT32 DocumentStatusCodeContentType;

EXTERN int asn1E_DocumentStatusCodeContentType (OSCTXT* pctxt,
   DocumentStatusCodeContentType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_DocumentStatusCodeContentType (OSCTXT* pctxt,
   DocumentStatusCodeContentType *pvalue, ASN1TagType tagging, int length);

EXTERN const OSUTF8CHAR* DocumentStatusCodeContentType_ToString (OSINT32 value);

EXTERN int DocumentStatusCodeContentType_ToEnum
  (const OSUTF8CHAR* value, DocumentStatusCodeContentType* pvalue);

/**************************************************************/
/*                                                            */
/*  DocumentStatusCodeType                                    */
/*                                                            */
/**************************************************************/

#define TV_DocumentStatusCodeType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN DocumentStatusCodeType {
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
   DocumentStatusCodeContentType base;
} DocumentStatusCodeType;

EXTERN int asn1E_DocumentStatusCodeType (OSCTXT* pctxt,
   DocumentStatusCodeType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_DocumentStatusCodeType (OSCTXT* pctxt,
   DocumentStatusCodeType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_DocumentStatusCodeType (OSCTXT* pctxt, 
   DocumentStatusCodeType* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_DocumentStatusCodeType (DocumentStatusCodeType* pvalue);

#ifdef __cplusplus
}
#endif

#endif
