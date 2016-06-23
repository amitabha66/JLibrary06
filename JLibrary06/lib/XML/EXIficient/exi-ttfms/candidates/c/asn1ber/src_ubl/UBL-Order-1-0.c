/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#include "asn1intl.h"
#include "UBL-Order-1-0.h"
#include "rtxsrc/rtxCommon.h"

#include "rtxmlsrc/osrtxml.h"

const OSXMLNamespace g_UBL_Order_1_0_NSTable[] = {
   { "", "urn:oasis:names:specification:ubl:schema:xsd:Order-1.0" },
   { "ccts", "urn:oasis:names:specification:ubl:schema:xsd:CoreComponentParameters-1.0" },
   { "cbc", "urn:oasis:names:specification:ubl:schema:xsd:CommonBasicComponents-1.0" },
   { "cac", "urn:oasis:names:specification:ubl:schema:xsd:CommonAggregateComponents-1.0" },
   { "res", "urn:oasis:names:specification:ubl:schema:xsd:AcknowledgementResponseCode-1.0" },
   { "udt", "urn:oasis:names:specification:ubl:schema:xsd:UnspecializedDatatypes-1.0" },
   { "sdt", "urn:oasis:names:specification:ubl:schema:xsd:SpecializedDatatypes-1.0" },
   { "cur", "urn:oasis:names:specification:ubl:schema:xsd:CurrencyCode-1.0" }
} ;

/**************************************************************/
/*                                                            */
/*  EarliestDateType                                          */
/*                                                            */
/**************************************************************/

void asn1Init_EarliestDateType (EarliestDateType* pvalue)
{
   if (0 == pvalue) return;
   pvalue->base = 0;
}

/**************************************************************/
/*                                                            */
/*  EarliestDate                                              */
/*                                                            */
/**************************************************************/

void asn1Init_EarliestDate (EarliestDate* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_EarliestDateType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  ValidityDurationMeasureType                               */
/*                                                            */
/**************************************************************/

void asn1Init_ValidityDurationMeasureType (ValidityDurationMeasureType* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->measureUnitCode = 0;
   pvalue->measureUnitCodeListVersionID = 0;
}

/**************************************************************/
/*                                                            */
/*  ValidityDurationMeasure                                   */
/*                                                            */
/**************************************************************/

void asn1Init_ValidityDurationMeasure (ValidityDurationMeasure* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_ValidityDurationMeasureType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  PackagesQuantityType                                      */
/*                                                            */
/**************************************************************/

void asn1Init_PackagesQuantityType (PackagesQuantityType* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->quantityUnitCode = 0;
   pvalue->quantityUnitCodeListAgencyID = 0;
   pvalue->quantityUnitCodeListAgencyName = 0;
   pvalue->quantityUnitCodeListID = 0;
}

/**************************************************************/
/*                                                            */
/*  TotalPackagesQuantity                                     */
/*                                                            */
/**************************************************************/

void asn1Init_TotalPackagesQuantity (TotalPackagesQuantity* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_PackagesQuantityType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  LineItemCountNumericType                                  */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_Order_1_0_LineItemCountNumericType (UBL_Order_1_0_LineItemCountNumericType* pvalue)
{
   if (0 == pvalue) return;
}

/**************************************************************/
/*                                                            */
/*  LineItemCountNumeric                                      */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_Order_1_0_LineItemCountNumeric (UBL_Order_1_0_LineItemCountNumeric* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_UBL_Order_1_0_LineItemCountNumericType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  ContractDocumentReference                                 */
/*                                                            */
/**************************************************************/

void asn1Init_ContractDocumentReference (ContractDocumentReference* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_DocumentReferenceType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  QuoteDocumentReference                                    */
/*                                                            */
/**************************************************************/

void asn1Init_QuoteDocumentReference (QuoteDocumentReference* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_DocumentReferenceType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  AdditionalDocumentReference                               */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_Order_1_0_AdditionalDocumentReference (UBL_Order_1_0_AdditionalDocumentReference* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_DocumentReferenceType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  _SeqOfUBL_Order_1_0_AdditionalDocumentReference           */
/*                                                            */
/**************************************************************/

void asn1Init__SeqOfUBL_Order_1_0_AdditionalDocumentReference (_SeqOfUBL_Order_1_0_AdditionalDocumentReference* pvalue)
{
   if (0 == pvalue) return;
   rtxDListFastInit (pvalue);
}

/**************************************************************/
/*                                                            */
/*  OriginatorParty                                           */
/*                                                            */
/**************************************************************/

void asn1Init_OriginatorParty (OriginatorParty* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_PartyType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  FreightForwarderParty                                     */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_Order_1_0_FreightForwarderParty (UBL_Order_1_0_FreightForwarderParty* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_PartyType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  DestinationCountry                                        */
/*                                                            */
/**************************************************************/

void asn1Init_DestinationCountry (DestinationCountry* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_CountryType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  OrderType_orderLine_list                                  */
/*                                                            */
/**************************************************************/

void asn1Init_OrderType_orderLine_list (OrderType_orderLine_list* pvalue)
{
   if (0 == pvalue) return;
   rtxDListFastInit (pvalue);
}

/**************************************************************/
/*                                                            */
/*  OrderType                                                 */
/*                                                            */
/**************************************************************/

void asn1Init_OrderType (OrderType* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   asn1Init_UBL_UnspecializedDatatypes_1_0_IdentifierType (&pvalue->buyersID);
   asn1Init_UBL_UnspecializedDatatypes_1_0_IdentifierType (&pvalue->sellersID);
   asn1Init_CopyIndicator (&pvalue->copyIndicator);
   asn1Init_UBL_UnspecializedDatatypes_1_0_IdentifierType (&pvalue->gUID);
   asn1Init_IssueDate (&pvalue->issueDate);
   asn1Init_Note (&pvalue->note);
   asn1Init_AcknowledgementResponseCodeType (&pvalue->acknowledgementResponseCode);
   asn1Init_CurrencyCodeType (&pvalue->transactionCurrencyCode);
   asn1Init_CurrencyCodeType (&pvalue->pricingCurrencyCode);
   asn1Init_EarliestDate (&pvalue->earliestDate);
   asn1Init_ExpiryDate (&pvalue->expiryDate);
   asn1Init_ValidityDurationMeasure (&pvalue->validityDurationMeasure);
   asn1Init_TaxTotalAmount (&pvalue->taxTotalAmount);
   asn1Init_LineExtensionTotalAmount (&pvalue->lineExtensionTotalAmount);
   asn1Init_TotalPackagesQuantity (&pvalue->totalPackagesQuantity);
   asn1Init_GrossWeightMeasure (&pvalue->grossWeightMeasure);
   asn1Init_NetWeightMeasure (&pvalue->netWeightMeasure);
   asn1Init_NetNetWeightMeasure (&pvalue->netNetWeightMeasure);
   asn1Init_GrossVolumeMeasure (&pvalue->grossVolumeMeasure);
   asn1Init_NetVolumeMeasure (&pvalue->netVolumeMeasure);
   asn1Init_UBL_Order_1_0_LineItemCountNumeric (&pvalue->lineItemCountNumeric);
   asn1Init_ContractDocumentReference (&pvalue->contractDocumentReference);
   asn1Init_QuoteDocumentReference (&pvalue->quoteDocumentReference);
   asn1Init__SeqOfUBL_Order_1_0_AdditionalDocumentReference (&pvalue->additionalDocumentReference_list);
   asn1Init_BuyerParty (&pvalue->buyerParty);
   asn1Init_SellerParty (&pvalue->sellerParty);
   asn1Init_OriginatorParty (&pvalue->originatorParty);
   asn1Init_UBL_Order_1_0_FreightForwarderParty (&pvalue->freightForwarderParty);
   asn1Init__SeqOfDelivery (&pvalue->delivery_list);
   asn1Init_DeliveryTerms (&pvalue->deliveryTerms);
   asn1Init__SeqOfAllowanceCharge (&pvalue->allowanceCharge_list);
   asn1Init_SalesConditions (&pvalue->salesConditions);
   asn1Init_DestinationCountry (&pvalue->destinationCountry);
   asn1Init_OrderType_orderLine_list (&pvalue->orderLine_list);
   asn1Init_PaymentMeans (&pvalue->paymentMeans);
}

/**************************************************************/
/*                                                            */
/*  Order                                                     */
/*                                                            */
/**************************************************************/

void asn1Init_Order (Order* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_OrderType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  PackagesQuantity                                          */
/*                                                            */
/**************************************************************/

void asn1Init_PackagesQuantity (PackagesQuantity* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_PackagesQuantityType (pvalue);
}
