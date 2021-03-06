/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#ifndef UBL_CODELIST_OPERATORCODE_1_0_H
#define UBL_CODELIST_OPERATORCODE_1_0_H

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
/*  OperatorCodeContentType                                   */
/*                                                            */
/**************************************************************/

#define TV_OperatorCodeContentType	(TM_UNIV|TM_PRIM|10)

typedef enum {
   divide = 0,
   multiply = 1
} OperatorCodeContentType_Root;

typedef OSUINT32 OperatorCodeContentType;

EXTERN int asn1E_OperatorCodeContentType (OSCTXT* pctxt,
   OperatorCodeContentType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_OperatorCodeContentType (OSCTXT* pctxt,
   OperatorCodeContentType *pvalue, ASN1TagType tagging, int length);

EXTERN const OSUTF8CHAR* OperatorCodeContentType_ToString (OSINT32 value);

EXTERN int OperatorCodeContentType_ToEnum
  (const OSUTF8CHAR* value, OperatorCodeContentType* pvalue);

/**************************************************************/
/*                                                            */
/*  OperatorCodeType                                          */
/*                                                            */
/**************************************************************/

#define TV_OperatorCodeType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN OperatorCodeType {
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
   OperatorCodeContentType base;
} OperatorCodeType;

EXTERN int asn1E_OperatorCodeType (OSCTXT* pctxt,
   OperatorCodeType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_OperatorCodeType (OSCTXT* pctxt,
   OperatorCodeType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_OperatorCodeType (OSCTXT* pctxt, OperatorCodeType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_OperatorCodeType (OperatorCodeType* pvalue);

#ifdef __cplusplus
}
#endif

#endif
