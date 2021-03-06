/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#ifndef UBL_ORDERRESPONSESIMPLE_1_0_H
#define UBL_ORDERRESPONSESIMPLE_1_0_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include "rtkey.h"
#include "asn1ber.h"
#include "libxml/parser.h"
#include "UBL-UnspecializedDatatypes-1-0.h"
#include "UBL-CommonBasicComponents-1-0.h"
#include "UBL-CodeList-DocumentStatusCode-1-0.h"
#include "UBL-CommonAggregateComponents-1-0.h"

/**************************************************************/
/*                                                            */
/*  AcceptedIndicatorType                                     */
/*                                                            */
/**************************************************************/

#define TV_UBL_OrderResponseSimple_1_0_AcceptedIndicatorType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN UBL_OrderResponseSimple_1_0_AcceptedIndicatorType {
   OSBOOL base;
} UBL_OrderResponseSimple_1_0_AcceptedIndicatorType;

EXTERN int asn1E_UBL_OrderResponseSimple_1_0_AcceptedIndicatorType (OSCTXT* pctxt,
   UBL_OrderResponseSimple_1_0_AcceptedIndicatorType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_UBL_OrderResponseSimple_1_0_AcceptedIndicatorType (OSCTXT* pctxt,
   UBL_OrderResponseSimple_1_0_AcceptedIndicatorType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_UBL_OrderResponseSimple_1_0_AcceptedIndicatorType (OSCTXT* pctxt, 
   UBL_OrderResponseSimple_1_0_AcceptedIndicatorType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_UBL_OrderResponseSimple_1_0_AcceptedIndicatorType (UBL_OrderResponseSimple_1_0_AcceptedIndicatorType* pvalue);

/**************************************************************/
/*                                                            */
/*  AcceptedIndicator                                         */
/*                                                            */
/**************************************************************/

#define TV_UBL_OrderResponseSimple_1_0_AcceptedIndicator	(TM_UNIV|TM_CONS|16)

typedef UBL_OrderResponseSimple_1_0_AcceptedIndicatorType UBL_OrderResponseSimple_1_0_AcceptedIndicator;

EXTERN int asn1E_UBL_OrderResponseSimple_1_0_AcceptedIndicator (OSCTXT* pctxt,
   UBL_OrderResponseSimple_1_0_AcceptedIndicator *pvalue, ASN1TagType tagging);

EXTERN int asn1D_UBL_OrderResponseSimple_1_0_AcceptedIndicator (OSCTXT* pctxt,
   UBL_OrderResponseSimple_1_0_AcceptedIndicator *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_UBL_OrderResponseSimple_1_0_AcceptedIndicator (OSCTXT* pctxt, 
   UBL_OrderResponseSimple_1_0_AcceptedIndicator* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_UBL_OrderResponseSimple_1_0_AcceptedIndicator (UBL_OrderResponseSimple_1_0_AcceptedIndicator* pvalue);

/**************************************************************/
/*                                                            */
/*  RejectionNoteType                                         */
/*                                                            */
/**************************************************************/

#define TV_RejectionNoteType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN RejectionNoteType {
   struct {
      unsigned languageLocaleIDPresent : 1;
      unsigned languageIDPresent : 1;
   } m;
   const OSUTF8CHAR* languageLocaleID;
   const OSUTF8CHAR* languageID;
   const OSUTF8CHAR* base;
} RejectionNoteType;

EXTERN int asn1E_RejectionNoteType (OSCTXT* pctxt,
   RejectionNoteType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_RejectionNoteType (OSCTXT* pctxt,
   RejectionNoteType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_RejectionNoteType (OSCTXT* pctxt, RejectionNoteType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_RejectionNoteType (RejectionNoteType* pvalue);

/**************************************************************/
/*                                                            */
/*  RejectionNote                                             */
/*                                                            */
/**************************************************************/

#define TV_RejectionNote	(TM_UNIV|TM_CONS|16)

typedef RejectionNoteType RejectionNote;

EXTERN int asn1E_RejectionNote (OSCTXT* pctxt,
   RejectionNote *pvalue, ASN1TagType tagging);

EXTERN int asn1D_RejectionNote (OSCTXT* pctxt,
   RejectionNote *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_RejectionNote (OSCTXT* pctxt, RejectionNote* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_RejectionNote (RejectionNote* pvalue);

/**************************************************************/
/*                                                            */
/*  OrderResponseSimpleType                                   */
/*                                                            */
/**************************************************************/

#define TV_OrderResponseSimpleType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN OrderResponseSimpleType {
   struct {
      unsigned copyIndicatorPresent : 1;
      unsigned gUIDPresent : 1;
      unsigned documentStatusCodePresent : 1;
      unsigned notePresent : 1;
      unsigned rejectionNotePresent : 1;
   } m;
   UBL_UnspecializedDatatypes_1_0_IdentifierType iD;
   CopyIndicator copyIndicator;
   UBL_UnspecializedDatatypes_1_0_IdentifierType gUID;
   IssueDate issueDate;
   DocumentStatusCodeType documentStatusCode;
   Note note;
   UBL_OrderResponseSimple_1_0_AcceptedIndicator acceptedIndicator;
   RejectionNote rejectionNote;
   OrderReference orderReference;
   BuyerParty buyerParty;
   SellerParty sellerParty;
} OrderResponseSimpleType;

EXTERN int asn1E_OrderResponseSimpleType (OSCTXT* pctxt,
   OrderResponseSimpleType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_OrderResponseSimpleType (OSCTXT* pctxt,
   OrderResponseSimpleType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_OrderResponseSimpleType (OSCTXT* pctxt, 
   OrderResponseSimpleType* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_OrderResponseSimpleType (OrderResponseSimpleType* pvalue);

/**************************************************************/
/*                                                            */
/*  OrderResponseSimple                                       */
/*                                                            */
/**************************************************************/

#define TV_OrderResponseSimple	(TM_UNIV|TM_CONS|16)

typedef OrderResponseSimpleType OrderResponseSimple;

EXTERN int asn1E_OrderResponseSimple (OSCTXT* pctxt,
   OrderResponseSimple *pvalue, ASN1TagType tagging);

EXTERN int asn1D_OrderResponseSimple (OSCTXT* pctxt,
   OrderResponseSimple *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_OrderResponseSimple (OSCTXT* pctxt, 
   OrderResponseSimple* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_OrderResponseSimple (OrderResponseSimple* pvalue);

#ifdef __cplusplus
}
#endif

#endif
