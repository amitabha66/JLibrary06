/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#ifndef SM_INV_H
#define SM_INV_H

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
#include "CoreComponentTypes.h"
#include "Sm-common.h"

/**
 * Header file for ASN.1 module Sm-inv
 */
/**************************************************************/
/*                                                            */
/*  InvoiceHeaderType                                         */
/*                                                            */
/**************************************************************/

#define TV_InvoiceHeaderType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN InvoiceHeaderType {
   struct {
      unsigned currencyCodePresent : 1;
      unsigned languagePresent : 1;
      unsigned consigneePartyPresent : 1;
      unsigned despatchPartyPresent : 1;
      unsigned shipmentPresent : 1;
      unsigned lineItemCountValuePresent : 1;
   } m;
   CCT_DateTimeType issueDateTime;
   CCT_IdentifierType identifier;
   CCT_IdentifierType pOIdentifier;
   CCT_CodeType currencyCode;
   LanguageType language;
   PartyType buyerParty;
   PartyType sellerParty;
   PartyType consigneeParty;
   PartyType despatchParty;
   ShipmentType shipment;
   PaymentMeansType paymentMeans;
   CCT_NumericType lineItemCountValue;
} InvoiceHeaderType;

EXTERN int asn1E_InvoiceHeaderType (OSCTXT* pctxt,
   InvoiceHeaderType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_InvoiceHeaderType (OSCTXT* pctxt, InvoiceHeaderType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_InvoiceHeaderType (OSCTXT* pctxt, InvoiceHeaderType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_InvoiceHeaderType (OSCTXT* pctxt, InvoiceHeaderType* pvalue)
   ;

EXTERN int DOMTest_InvoiceHeaderType (OSCTXT* pctxt, InvoiceHeaderType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_InvoiceHeaderType (InvoiceHeaderType* pvalue);

/**************************************************************/
/*                                                            */
/*  InvoiceLineItemType                                       */
/*                                                            */
/**************************************************************/

#define TV_InvoiceLineItemType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN InvoiceLineItemType {
   struct {
      unsigned orderStatusPresent : 1;
      unsigned pricingVariationPresent : 1;
      unsigned itemTaxPresent : 1;
   } m;
   CCT_IdentifierType lineID;
   ItemType item;
   CCT_CodeType orderStatus;
   PricingType pricing;
   PricingVariationType pricingVariation;
   CCT_AmountType itemTax;
   CCT_AmountType totalAmount;
} InvoiceLineItemType;

EXTERN int asn1E_InvoiceLineItemType (OSCTXT* pctxt,
   InvoiceLineItemType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_InvoiceLineItemType (OSCTXT* pctxt, 
   InvoiceLineItemType *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_InvoiceLineItemType (OSCTXT* pctxt, 
   InvoiceLineItemType* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_InvoiceLineItemType (OSCTXT* pctxt, 
   InvoiceLineItemType* pvalue);

EXTERN int DOMTest_InvoiceLineItemType (OSCTXT* pctxt, InvoiceLineItemType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_InvoiceLineItemType (InvoiceLineItemType* pvalue);

/**************************************************************/
/*                                                            */
/*  InvoiceSummaryType                                        */
/*                                                            */
/**************************************************************/

#define TV_InvoiceSummaryType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN InvoiceSummaryType {
   struct {
      unsigned lineItemCountValuePresent : 1;
      unsigned totalTaxPresent : 1;
      unsigned packingSlipIdentifierPresent : 1;
      unsigned summaryNotePresent : 1;
   } m;
   CCT_NumericType lineItemCountValue;
   CCT_AmountType subtotalAmount;
   /* List of PricingVariationType */
   OSRTDList pricingVariation_list;
   TaxType totalTax;
   CCT_AmountType priceAmount;
   CCT_IdentifierType packingSlipIdentifier;
   NoteType summaryNote;
} InvoiceSummaryType;

EXTERN int asn1E_InvoiceSummaryType (OSCTXT* pctxt,
   InvoiceSummaryType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_InvoiceSummaryType (OSCTXT* pctxt, 
   InvoiceSummaryType *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_InvoiceSummaryType (OSCTXT* pctxt, 
   InvoiceSummaryType* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_InvoiceSummaryType (OSCTXT* pctxt, 
   InvoiceSummaryType* pvalue);

EXTERN int DOMTest_InvoiceSummaryType (OSCTXT* pctxt, InvoiceSummaryType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_InvoiceSummaryType (InvoiceSummaryType* pvalue);

/**************************************************************/
/*                                                            */
/*  InvoiceType                                               */
/*                                                            */
/**************************************************************/

#define TV_InvoiceType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN InvoiceType {
   InvoiceHeaderType header;
   /* List of InvoiceLineItemType */
   OSRTDList lineItem_list;
   InvoiceSummaryType summary;
} InvoiceType;

EXTERN int asn1E_InvoiceType (OSCTXT* pctxt,
   InvoiceType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_InvoiceType (OSCTXT* pctxt, InvoiceType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_InvoiceType (OSCTXT* pctxt, InvoiceType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_InvoiceType (OSCTXT* pctxt, InvoiceType* pvalue);

EXTERN int DOMTest_InvoiceType (OSCTXT* pctxt, InvoiceType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_InvoiceType (InvoiceType* pvalue);

/**************************************************************/
/*                                                            */
/*  Invoice                                                   */
/*                                                            */
/**************************************************************/

#define TV_Invoice	(TM_UNIV|TM_CONS|16)

typedef InvoiceType Invoice;

EXTERN int asn1E_Invoice (OSCTXT* pctxt,
   Invoice *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Invoice (OSCTXT* pctxt, Invoice *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc_Invoice (OSCTXT* pctxt, Invoice* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Invoice (OSCTXT* pctxt, Invoice* pvalue);

EXTERN int DOMTest_Invoice (OSCTXT* pctxt, Invoice* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Invoice (Invoice* pvalue);

/**
 * Global element functions.  These functions encode or decode complete
 * XML documents.  They are generated for XSD global elements and/or
 * ASN.1 type definitions that are either:
 *
 * 1) not referenced by any other types, or
 * 2) explicitly declared to be a PDU using the -pdu command line
 *    option, or
 * 3) explicitly declared to be a PDU using the <isPDU/> 
 *    configuration file element.
 */
EXTERN int XmlEnc_Invoice_PDU (OSCTXT* pctxt, Invoice* pvalue);

EXTERN int XmlDec_Invoice_PDU (OSCTXT* pctxt, Invoice* pvalue);

#ifdef __cplusplus
}
#endif

#endif
