/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#ifndef UBL_SPECIALIZEDDATATYPES_1_0_H
#define UBL_SPECIALIZEDDATATYPES_1_0_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include "rtkey.h"
#include "asn1ber.h"
#include "libxml/parser.h"
#include "UBL-UnspecializedDatatypes-1-0.h"
#include "UBL-CodeList-CurrencyCode-1-0.h"

/**************************************************************/
/*                                                            */
/*  UBLAmountType                                             */
/*                                                            */
/**************************************************************/

#define TV_UBLAmountType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN UBLAmountType {
   struct {
      unsigned amountCurrencyCodeListVersionIDPresent : 1;
   } m;
   const OSUTF8CHAR* amountCurrencyCodeListVersionID;
   CurrencyCodeContentType amountCurrencyID;
   OSREAL base;
} UBLAmountType;

EXTERN int asn1E_UBLAmountType (OSCTXT* pctxt,
   UBLAmountType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_UBLAmountType (OSCTXT* pctxt,
   UBLAmountType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_UBLAmountType (OSCTXT* pctxt, UBLAmountType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_UBLAmountType (UBLAmountType* pvalue);

#ifdef __cplusplus
}
#endif

#endif