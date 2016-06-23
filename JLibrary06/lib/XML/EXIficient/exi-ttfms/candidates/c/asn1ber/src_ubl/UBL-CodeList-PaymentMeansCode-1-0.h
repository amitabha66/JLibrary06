/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#ifndef UBL_CODELIST_PAYMENTMEANSCODE_1_0_H
#define UBL_CODELIST_PAYMENTMEANSCODE_1_0_H

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
/*  PaymentMeansCodeContentType                               */
/*                                                            */
/**************************************************************/

#define TV_PaymentMeansCodeContentType	(TM_UNIV|TM_PRIM|10)

typedef enum {
   zZZ_1 = 0,
   int1_1 = 1,
   int2_1 = 2,
   int3_1 = 3,
   int4_1 = 4,
   int5_1 = 5,
   int6_1 = 6,
   int7_1 = 7,
   int8_1 = 8,
   int9_1 = 9,
   int10_1 = 10,
   int11_1 = 11,
   int12_1 = 12,
   int13_1 = 13,
   int14_1 = 14,
   int15_1 = 15,
   int16_1 = 16,
   int17_1 = 17,
   int18_1 = 18,
   int19_1 = 19,
   int20_1 = 20,
   int21_1 = 21,
   int22_1 = 22,
   int23_1 = 23,
   int24_1 = 24,
   int25_1 = 25,
   int26_1 = 26,
   int27_1 = 27,
   int28_1 = 28,
   int29_1 = 29,
   int30_1 = 30,
   int31_1 = 31,
   int32_1 = 32,
   int33_1 = 33,
   int34_1 = 34,
   int35_1 = 35,
   int36_1 = 36,
   int37_1 = 37,
   int38_1 = 38,
   int39_1 = 39,
   int40_1 = 40,
   int41_1 = 41,
   int42_1 = 42,
   int43_1 = 43,
   int44_1 = 44,
   int45_1 = 45,
   int46_1 = 46,
   int47_1 = 47,
   int48_1 = 48,
   int49_1 = 49,
   int50_1 = 50,
   int51_1 = 51,
   int52_1 = 52,
   int53_1 = 53,
   int60_1 = 60,
   int61_1 = 61,
   int62_1 = 62,
   int63_1 = 63,
   int64_1 = 64,
   int65_1 = 65,
   int66_1 = 66,
   int67_1 = 67,
   int70_1 = 70,
   int74_1 = 74,
   int75_1 = 75,
   int76_1 = 76,
   int77_1 = 77,
   int78_1 = 78,
   int91 = 91,
   int92 = 92,
   int93 = 93,
   int94 = 94,
   int95 = 95,
   int96 = 96,
   int97 = 97
} PaymentMeansCodeContentType_Root;

typedef OSUINT32 PaymentMeansCodeContentType;

EXTERN int asn1E_PaymentMeansCodeContentType (OSCTXT* pctxt,
   PaymentMeansCodeContentType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PaymentMeansCodeContentType (OSCTXT* pctxt,
   PaymentMeansCodeContentType *pvalue, ASN1TagType tagging, int length);

EXTERN const OSUTF8CHAR* PaymentMeansCodeContentType_ToString (OSINT32 value);

EXTERN int PaymentMeansCodeContentType_ToEnum
  (const OSUTF8CHAR* value, PaymentMeansCodeContentType* pvalue);

/**************************************************************/
/*                                                            */
/*  PaymentMeansCodeType                                      */
/*                                                            */
/**************************************************************/

#define TV_PaymentMeansCodeType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PaymentMeansCodeType {
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
   PaymentMeansCodeContentType base;
} PaymentMeansCodeType;

EXTERN int asn1E_PaymentMeansCodeType (OSCTXT* pctxt,
   PaymentMeansCodeType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PaymentMeansCodeType (OSCTXT* pctxt,
   PaymentMeansCodeType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_PaymentMeansCodeType (OSCTXT* pctxt, 
   PaymentMeansCodeType* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PaymentMeansCodeType (PaymentMeansCodeType* pvalue);

#ifdef __cplusplus
}
#endif

#endif
