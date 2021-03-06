/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#ifndef UBL_ORDERCHANGE_1_0_H
#define UBL_ORDERCHANGE_1_0_H

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
#include "UBL-CodeList-AcknowledgementResponseCode-1-0.h"
#include "UBL-CodeList-CurrencyCode-1-0.h"
#include "UBL-CommonAggregateComponents-1-0.h"
#include "UBL-DespatchAdvice-1-0.h"

/**************************************************************/
/*                                                            */
/*  EarliestDateType                                          */
/*                                                            */
/**************************************************************/

#define TV_UBL_OrderChange_1_0_EarliestDateType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN UBL_OrderChange_1_0_EarliestDateType {
   const OSUTF8CHAR* base;
} UBL_OrderChange_1_0_EarliestDateType;

EXTERN int asn1E_UBL_OrderChange_1_0_EarliestDateType (OSCTXT* pctxt,
   UBL_OrderChange_1_0_EarliestDateType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_UBL_OrderChange_1_0_EarliestDateType (OSCTXT* pctxt,
   UBL_OrderChange_1_0_EarliestDateType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_UBL_OrderChange_1_0_EarliestDateType (OSCTXT* pctxt, 
   UBL_OrderChange_1_0_EarliestDateType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_UBL_OrderChange_1_0_EarliestDateType (UBL_OrderChange_1_0_EarliestDateType* pvalue);

/**************************************************************/
/*                                                            */
/*  EarliestDate                                              */
/*                                                            */
/**************************************************************/

#define TV_UBL_OrderChange_1_0_EarliestDate	(TM_UNIV|TM_CONS|16)

typedef UBL_OrderChange_1_0_EarliestDateType UBL_OrderChange_1_0_EarliestDate;

EXTERN int asn1E_UBL_OrderChange_1_0_EarliestDate (OSCTXT* pctxt,
   UBL_OrderChange_1_0_EarliestDate *pvalue, ASN1TagType tagging);

EXTERN int asn1D_UBL_OrderChange_1_0_EarliestDate (OSCTXT* pctxt,
   UBL_OrderChange_1_0_EarliestDate *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_UBL_OrderChange_1_0_EarliestDate (OSCTXT* pctxt, 
   UBL_OrderChange_1_0_EarliestDate* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_UBL_OrderChange_1_0_EarliestDate (UBL_OrderChange_1_0_EarliestDate* pvalue);

/**************************************************************/
/*                                                            */
/*  ValidityDurationMeasureType                               */
/*                                                            */
/**************************************************************/

#define TV_UBL_OrderChange_1_0_ValidityDurationMeasureType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN UBL_OrderChange_1_0_ValidityDurationMeasureType {
   struct {
      unsigned measureUnitCodeListVersionIDPresent : 1;
   } m;
   const OSUTF8CHAR* measureUnitCode;
   const OSUTF8CHAR* measureUnitCodeListVersionID;
   OSREAL base;
} UBL_OrderChange_1_0_ValidityDurationMeasureType;

EXTERN int asn1E_UBL_OrderChange_1_0_ValidityDurationMeasureType (OSCTXT* pctxt,
   UBL_OrderChange_1_0_ValidityDurationMeasureType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_UBL_OrderChange_1_0_ValidityDurationMeasureType (OSCTXT* pctxt,
   UBL_OrderChange_1_0_ValidityDurationMeasureType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_UBL_OrderChange_1_0_ValidityDurationMeasureType (OSCTXT* pctxt, 
   UBL_OrderChange_1_0_ValidityDurationMeasureType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_UBL_OrderChange_1_0_ValidityDurationMeasureType (UBL_OrderChange_1_0_ValidityDurationMeasureType* pvalue);

/**************************************************************/
/*                                                            */
/*  ValidityDurationMeasure                                   */
/*                                                            */
/**************************************************************/

#define TV_UBL_OrderChange_1_0_ValidityDurationMeasure	(TM_UNIV|TM_CONS|16)

typedef UBL_OrderChange_1_0_ValidityDurationMeasureType UBL_OrderChange_1_0_ValidityDurationMeasure;

EXTERN int asn1E_UBL_OrderChange_1_0_ValidityDurationMeasure (OSCTXT* pctxt,
   UBL_OrderChange_1_0_ValidityDurationMeasure *pvalue, ASN1TagType tagging);

EXTERN int asn1D_UBL_OrderChange_1_0_ValidityDurationMeasure (OSCTXT* pctxt,
   UBL_OrderChange_1_0_ValidityDurationMeasure *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_UBL_OrderChange_1_0_ValidityDurationMeasure (OSCTXT* pctxt, 
   UBL_OrderChange_1_0_ValidityDurationMeasure* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_UBL_OrderChange_1_0_ValidityDurationMeasure (UBL_OrderChange_1_0_ValidityDurationMeasure* pvalue);

/**************************************************************/
/*                                                            */
/*  PackagesCountQuantityType                                 */
/*                                                            */
/**************************************************************/

#define TV_PackagesCountQuantityType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PackagesCountQuantityType {
   struct {
      unsigned quantityUnitCodeListAgencyIDPresent : 1;
      unsigned quantityUnitCodeListAgencyNamePresent : 1;
      unsigned quantityUnitCodeListIDPresent : 1;
   } m;
   const OSUTF8CHAR* quantityUnitCode;
   const OSUTF8CHAR* quantityUnitCodeListAgencyID;
   const OSUTF8CHAR* quantityUnitCodeListAgencyName;
   const OSUTF8CHAR* quantityUnitCodeListID;
   OSREAL base;
} PackagesCountQuantityType;

EXTERN int asn1E_PackagesCountQuantityType (OSCTXT* pctxt,
   PackagesCountQuantityType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PackagesCountQuantityType (OSCTXT* pctxt,
   PackagesCountQuantityType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_PackagesCountQuantityType (OSCTXT* pctxt, 
   PackagesCountQuantityType* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PackagesCountQuantityType (PackagesCountQuantityType* pvalue);

/**************************************************************/
/*                                                            */
/*  TotalPackagesCountQuantity                                */
/*                                                            */
/**************************************************************/

#define TV_TotalPackagesCountQuantity	(TM_UNIV|TM_CONS|16)

typedef PackagesCountQuantityType TotalPackagesCountQuantity;

EXTERN int asn1E_TotalPackagesCountQuantity (OSCTXT* pctxt,
   TotalPackagesCountQuantity *pvalue, ASN1TagType tagging);

EXTERN int asn1D_TotalPackagesCountQuantity (OSCTXT* pctxt,
   TotalPackagesCountQuantity *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_TotalPackagesCountQuantity (OSCTXT* pctxt, 
   TotalPackagesCountQuantity* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_TotalPackagesCountQuantity (TotalPackagesCountQuantity* pvalue);

/**************************************************************/
/*                                                            */
/*  LineItemCountNumericType                                  */
/*                                                            */
/**************************************************************/

#define TV_UBL_OrderChange_1_0_LineItemCountNumericType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN UBL_OrderChange_1_0_LineItemCountNumericType {
   OSREAL base;
} UBL_OrderChange_1_0_LineItemCountNumericType;

EXTERN int asn1E_UBL_OrderChange_1_0_LineItemCountNumericType (OSCTXT* pctxt,
   UBL_OrderChange_1_0_LineItemCountNumericType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_UBL_OrderChange_1_0_LineItemCountNumericType (OSCTXT* pctxt,
   UBL_OrderChange_1_0_LineItemCountNumericType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_UBL_OrderChange_1_0_LineItemCountNumericType (OSCTXT* pctxt, 
   UBL_OrderChange_1_0_LineItemCountNumericType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_UBL_OrderChange_1_0_LineItemCountNumericType (UBL_OrderChange_1_0_LineItemCountNumericType* pvalue);

/**************************************************************/
/*                                                            */
/*  LineItemCountNumeric                                      */
/*                                                            */
/**************************************************************/

#define TV_UBL_OrderChange_1_0_LineItemCountNumeric	(TM_UNIV|TM_CONS|16)

typedef UBL_OrderChange_1_0_LineItemCountNumericType UBL_OrderChange_1_0_LineItemCountNumeric;

EXTERN int asn1E_UBL_OrderChange_1_0_LineItemCountNumeric (OSCTXT* pctxt,
   UBL_OrderChange_1_0_LineItemCountNumeric *pvalue, ASN1TagType tagging);

EXTERN int asn1D_UBL_OrderChange_1_0_LineItemCountNumeric (OSCTXT* pctxt,
   UBL_OrderChange_1_0_LineItemCountNumeric *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_UBL_OrderChange_1_0_LineItemCountNumeric (OSCTXT* pctxt, 
   UBL_OrderChange_1_0_LineItemCountNumeric* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_UBL_OrderChange_1_0_LineItemCountNumeric (UBL_OrderChange_1_0_LineItemCountNumeric* pvalue);

/**************************************************************/
/*                                                            */
/*  ContractDocumentReference                                 */
/*                                                            */
/**************************************************************/

#define TV_UBL_OrderChange_1_0_ContractDocumentReference	(TM_UNIV|TM_CONS|16)

typedef DocumentReferenceType UBL_OrderChange_1_0_ContractDocumentReference;

EXTERN int asn1E_UBL_OrderChange_1_0_ContractDocumentReference (OSCTXT* pctxt,
   UBL_OrderChange_1_0_ContractDocumentReference *pvalue, ASN1TagType tagging);

EXTERN int asn1D_UBL_OrderChange_1_0_ContractDocumentReference (OSCTXT* pctxt,
   UBL_OrderChange_1_0_ContractDocumentReference *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_UBL_OrderChange_1_0_ContractDocumentReference (OSCTXT* pctxt, 
   UBL_OrderChange_1_0_ContractDocumentReference* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_UBL_OrderChange_1_0_ContractDocumentReference (UBL_OrderChange_1_0_ContractDocumentReference* pvalue);

/**************************************************************/
/*                                                            */
/*  QuoteDocumentReference                                    */
/*                                                            */
/**************************************************************/

#define TV_UBL_OrderChange_1_0_QuoteDocumentReference	(TM_UNIV|TM_CONS|16)

typedef DocumentReferenceType UBL_OrderChange_1_0_QuoteDocumentReference;

EXTERN int asn1E_UBL_OrderChange_1_0_QuoteDocumentReference (OSCTXT* pctxt,
   UBL_OrderChange_1_0_QuoteDocumentReference *pvalue, ASN1TagType tagging);

EXTERN int asn1D_UBL_OrderChange_1_0_QuoteDocumentReference (OSCTXT* pctxt,
   UBL_OrderChange_1_0_QuoteDocumentReference *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_UBL_OrderChange_1_0_QuoteDocumentReference (OSCTXT* pctxt, 
   UBL_OrderChange_1_0_QuoteDocumentReference* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_UBL_OrderChange_1_0_QuoteDocumentReference (UBL_OrderChange_1_0_QuoteDocumentReference* pvalue);

/**************************************************************/
/*                                                            */
/*  OriginatorParty                                           */
/*                                                            */
/**************************************************************/

#define TV_UBL_OrderChange_1_0_OriginatorParty	(TM_UNIV|TM_CONS|16)

typedef PartyType UBL_OrderChange_1_0_OriginatorParty;

EXTERN int asn1E_UBL_OrderChange_1_0_OriginatorParty (OSCTXT* pctxt,
   UBL_OrderChange_1_0_OriginatorParty *pvalue, ASN1TagType tagging);

EXTERN int asn1D_UBL_OrderChange_1_0_OriginatorParty (OSCTXT* pctxt,
   UBL_OrderChange_1_0_OriginatorParty *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_UBL_OrderChange_1_0_OriginatorParty (OSCTXT* pctxt, 
   UBL_OrderChange_1_0_OriginatorParty* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_UBL_OrderChange_1_0_OriginatorParty (UBL_OrderChange_1_0_OriginatorParty* pvalue);

/**************************************************************/
/*                                                            */
/*  FreightForwarderParty                                     */
/*                                                            */
/**************************************************************/

#define TV_UBL_OrderChange_1_0_FreightForwarderParty	(TM_UNIV|TM_CONS|16)

typedef PartyType UBL_OrderChange_1_0_FreightForwarderParty;

EXTERN int asn1E_UBL_OrderChange_1_0_FreightForwarderParty (OSCTXT* pctxt,
   UBL_OrderChange_1_0_FreightForwarderParty *pvalue, ASN1TagType tagging);

EXTERN int asn1D_UBL_OrderChange_1_0_FreightForwarderParty (OSCTXT* pctxt,
   UBL_OrderChange_1_0_FreightForwarderParty *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_UBL_OrderChange_1_0_FreightForwarderParty (OSCTXT* pctxt, 
   UBL_OrderChange_1_0_FreightForwarderParty* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_UBL_OrderChange_1_0_FreightForwarderParty (UBL_OrderChange_1_0_FreightForwarderParty* pvalue);

/**************************************************************/
/*                                                            */
/*  DestinationCountry                                        */
/*                                                            */
/**************************************************************/

#define TV_UBL_OrderChange_1_0_DestinationCountry	(TM_UNIV|TM_CONS|16)

typedef CountryType UBL_OrderChange_1_0_DestinationCountry;

EXTERN int asn1E_UBL_OrderChange_1_0_DestinationCountry (OSCTXT* pctxt,
   UBL_OrderChange_1_0_DestinationCountry *pvalue, ASN1TagType tagging);

EXTERN int asn1D_UBL_OrderChange_1_0_DestinationCountry (OSCTXT* pctxt,
   UBL_OrderChange_1_0_DestinationCountry *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_UBL_OrderChange_1_0_DestinationCountry (OSCTXT* pctxt, 
   UBL_OrderChange_1_0_DestinationCountry* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_UBL_OrderChange_1_0_DestinationCountry (UBL_OrderChange_1_0_DestinationCountry* pvalue);

/**************************************************************/
/*                                                            */
/*  OrderChangeType_orderLine_list                            */
/*                                                            */
/**************************************************************/

#define TV_OrderChangeType_orderLine_list	(TM_UNIV|TM_CONS|16)

/* List of OrderLine */
typedef OSRTDList OrderChangeType_orderLine_list;

EXTERN int asn1E_OrderChangeType_orderLine_list (OSCTXT* pctxt,
   OrderChangeType_orderLine_list *pvalue, ASN1TagType tagging);

EXTERN int asn1D_OrderChangeType_orderLine_list (OSCTXT* pctxt,
   OrderChangeType_orderLine_list *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_OrderChangeType_orderLine_list (OSCTXT* pctxt, 
   OrderChangeType_orderLine_list* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_OrderChangeType_orderLine_list (OrderChangeType_orderLine_list* pvalue);

/**************************************************************/
/*                                                            */
/*  OrderChangeType                                           */
/*                                                            */
/**************************************************************/

#define TV_OrderChangeType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN OrderChangeType {
   struct {
      unsigned buyersIDPresent : 1;
      unsigned sellersIDPresent : 1;
      unsigned copyIndicatorPresent : 1;
      unsigned gUIDPresent : 1;
      unsigned documentStatusCodePresent : 1;
      unsigned notePresent : 1;
      unsigned acknowledgementResponseCodePresent : 1;
      unsigned transactionCurrencyCodePresent : 1;
      unsigned pricingCurrencyCodePresent : 1;
      unsigned earliestDatePresent : 1;
      unsigned expiryDatePresent : 1;
      unsigned validityDurationMeasurePresent : 1;
      unsigned taxTotalAmountPresent : 1;
      unsigned lineExtensionTotalAmountPresent : 1;
      unsigned totalPackagesCountQuantityPresent : 1;
      unsigned grossWeightMeasurePresent : 1;
      unsigned netWeightMeasurePresent : 1;
      unsigned netNetWeightMeasurePresent : 1;
      unsigned grossVolumeMeasurePresent : 1;
      unsigned netVolumeMeasurePresent : 1;
      unsigned lineItemCountNumericPresent : 1;
      unsigned contractDocumentReferencePresent : 1;
      unsigned quoteDocumentReferencePresent : 1;
      unsigned originatorPartyPresent : 1;
      unsigned freightForwarderPartyPresent : 1;
      unsigned deliveryTermsPresent : 1;
      unsigned salesConditionsPresent : 1;
      unsigned destinationCountryPresent : 1;
      unsigned paymentMeansPresent : 1;
   } m;
   UBL_UnspecializedDatatypes_1_0_IdentifierType buyersID;
   UBL_UnspecializedDatatypes_1_0_IdentifierType sellersID;
   CopyIndicator copyIndicator;
   UBL_UnspecializedDatatypes_1_0_IdentifierType gUID;
   IssueDate issueDate;
   DocumentStatusCodeType documentStatusCode;
   UBL_UnspecializedDatatypes_1_0_IdentifierType sequenceNumberID;
   Note note;
   AcknowledgementResponseCodeType acknowledgementResponseCode;
   CurrencyCodeType transactionCurrencyCode;
   CurrencyCodeType pricingCurrencyCode;
   UBL_OrderChange_1_0_EarliestDate earliestDate;
   ExpiryDate expiryDate;
   UBL_OrderChange_1_0_ValidityDurationMeasure validityDurationMeasure;
   TaxTotalAmount taxTotalAmount;
   LineExtensionTotalAmount lineExtensionTotalAmount;
   TotalPackagesCountQuantity totalPackagesCountQuantity;
   GrossWeightMeasure grossWeightMeasure;
   NetWeightMeasure netWeightMeasure;
   NetNetWeightMeasure netNetWeightMeasure;
   GrossVolumeMeasure grossVolumeMeasure;
   NetVolumeMeasure netVolumeMeasure;
   UBL_OrderChange_1_0_LineItemCountNumeric lineItemCountNumeric;
   _SeqOfOrderReference orderReference_list;
   UBL_OrderChange_1_0_ContractDocumentReference contractDocumentReference;
   UBL_OrderChange_1_0_QuoteDocumentReference quoteDocumentReference;
   BuyerParty buyerParty;
   SellerParty sellerParty;
   UBL_OrderChange_1_0_OriginatorParty originatorParty;
   UBL_OrderChange_1_0_FreightForwarderParty freightForwarderParty;
   _SeqOfDelivery delivery_list;
   DeliveryTerms deliveryTerms;
   _SeqOfAllowanceCharge allowanceCharge_list;
   SalesConditions salesConditions;
   UBL_OrderChange_1_0_DestinationCountry destinationCountry;
   OrderChangeType_orderLine_list orderLine_list;
   PaymentMeans paymentMeans;
} OrderChangeType;

EXTERN int asn1E_OrderChangeType (OSCTXT* pctxt,
   OrderChangeType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_OrderChangeType (OSCTXT* pctxt,
   OrderChangeType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_OrderChangeType (OSCTXT* pctxt, OrderChangeType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_OrderChangeType (OrderChangeType* pvalue);

/**************************************************************/
/*                                                            */
/*  OrderChange                                               */
/*                                                            */
/**************************************************************/

#define TV_OrderChange	(TM_UNIV|TM_CONS|16)

typedef OrderChangeType OrderChange;

EXTERN int asn1E_OrderChange (OSCTXT* pctxt,
   OrderChange *pvalue, ASN1TagType tagging);

EXTERN int asn1D_OrderChange (OSCTXT* pctxt,
   OrderChange *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_OrderChange (OSCTXT* pctxt, OrderChange* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_OrderChange (OrderChange* pvalue);

/**************************************************************/
/*                                                            */
/*  PackagesCountQuantity                                     */
/*                                                            */
/**************************************************************/

#define TV_PackagesCountQuantity	(TM_UNIV|TM_CONS|16)

typedef PackagesCountQuantityType PackagesCountQuantity;

EXTERN int asn1E_PackagesCountQuantity (OSCTXT* pctxt,
   PackagesCountQuantity *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PackagesCountQuantity (OSCTXT* pctxt,
   PackagesCountQuantity *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_PackagesCountQuantity (OSCTXT* pctxt, 
   PackagesCountQuantity* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PackagesCountQuantity (PackagesCountQuantity* pvalue);

#ifdef __cplusplus
}
#endif

#endif
