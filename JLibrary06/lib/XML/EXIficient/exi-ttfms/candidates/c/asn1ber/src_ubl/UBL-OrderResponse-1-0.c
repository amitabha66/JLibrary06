/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#include "asn1intl.h"
#include "UBL-OrderResponse-1-0.h"
#include "rtxsrc/rtxCommon.h"

#include "rtxmlsrc/osrtxml.h"

const OSXMLNamespace g_UBL_OrderResponse_1_0_NSTable[] = {
   { "", "urn:oasis:names:specification:ubl:schema:xsd:OrderResponse-1.0" },
   { "ccts", "urn:oasis:names:specification:ubl:schema:xsd:CoreComponentParameters-1.0" },
   { "cbc", "urn:oasis:names:specification:ubl:schema:xsd:CommonBasicComponents-1.0" },
   { "cac", "urn:oasis:names:specification:ubl:schema:xsd:CommonAggregateComponents-1.0" },
   { "udt", "urn:oasis:names:specification:ubl:schema:xsd:UnspecializedDatatypes-1.0" },
   { "sdt", "urn:oasis:names:specification:ubl:schema:xsd:SpecializedDatatypes-1.0" },
   { "stat", "urn:oasis:names:specification:ubl:schema:xsd:DocumentStatusCode-1.0" },
   { "cur", "urn:oasis:names:specification:ubl:schema:xsd:CurrencyCode-1.0" }
} ;

/**************************************************************/
/*                                                            */
/*  EarliestDateType                                          */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_OrderResponse_1_0_EarliestDateType (UBL_OrderResponse_1_0_EarliestDateType* pvalue)
{
   if (0 == pvalue) return;
   pvalue->base = 0;
}

/**************************************************************/
/*                                                            */
/*  EarliestDate                                              */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_OrderResponse_1_0_EarliestDate (UBL_OrderResponse_1_0_EarliestDate* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_UBL_OrderResponse_1_0_EarliestDateType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  ValidityDurationMeasureType                               */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_OrderResponse_1_0_ValidityDurationMeasureType (UBL_OrderResponse_1_0_ValidityDurationMeasureType* pvalue)
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

void asn1Init_UBL_OrderResponse_1_0_ValidityDurationMeasure (UBL_OrderResponse_1_0_ValidityDurationMeasure* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_UBL_OrderResponse_1_0_ValidityDurationMeasureType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  PackagesCountQuantityType                                 */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_OrderResponse_1_0_PackagesCountQuantityType (UBL_OrderResponse_1_0_PackagesCountQuantityType* pvalue)
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
/*  TotalPackagesCountQuantity                                */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_OrderResponse_1_0_TotalPackagesCountQuantity (UBL_OrderResponse_1_0_TotalPackagesCountQuantity* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_UBL_OrderResponse_1_0_PackagesCountQuantityType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  LineItemCountNumericType                                  */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_OrderResponse_1_0_LineItemCountNumericType (UBL_OrderResponse_1_0_LineItemCountNumericType* pvalue)
{
   if (0 == pvalue) return;
}

/**************************************************************/
/*                                                            */
/*  LineItemCountNumeric                                      */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_OrderResponse_1_0_LineItemCountNumeric (UBL_OrderResponse_1_0_LineItemCountNumeric* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_UBL_OrderResponse_1_0_LineItemCountNumericType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  OrderResponseType_orderReference_list                     */
/*                                                            */
/**************************************************************/

void asn1Init_OrderResponseType_orderReference_list (OrderResponseType_orderReference_list* pvalue)
{
   if (0 == pvalue) return;
   rtxDListFastInit (pvalue);
}

/**************************************************************/
/*                                                            */
/*  OriginatorParty                                           */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_OrderResponse_1_0_OriginatorParty (UBL_OrderResponse_1_0_OriginatorParty* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_PartyType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  FreightForwarderParty                                     */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_OrderResponse_1_0_FreightForwarderParty (UBL_OrderResponse_1_0_FreightForwarderParty* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_PartyType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  DestinationCountry                                        */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_OrderResponse_1_0_DestinationCountry (UBL_OrderResponse_1_0_DestinationCountry* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_CountryType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  RespondedOrderLine                                        */
/*                                                            */
/**************************************************************/

void asn1Init_RespondedOrderLine (RespondedOrderLine* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_OrderLineType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  OrderResponseType_respondedOrderLine_list                 */
/*                                                            */
/**************************************************************/

void asn1Init_OrderResponseType_respondedOrderLine_list (OrderResponseType_respondedOrderLine_list* pvalue)
{
   if (0 == pvalue) return;
   rtxDListFastInit (pvalue);
}

/**************************************************************/
/*                                                            */
/*  OrderResponseType                                         */
/*                                                            */
/**************************************************************/

void asn1Init_OrderResponseType (OrderResponseType* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   asn1Init_UBL_UnspecializedDatatypes_1_0_IdentifierType (&pvalue->buyersID);
   asn1Init_UBL_UnspecializedDatatypes_1_0_IdentifierType (&pvalue->sellersID);
   asn1Init_CopyIndicator (&pvalue->copyIndicator);
   asn1Init_UBL_UnspecializedDatatypes_1_0_IdentifierType (&pvalue->gUID);
   asn1Init_IssueDate (&pvalue->issueDate);
   asn1Init_DocumentStatusCodeType (&pvalue->documentStatusCode);
   asn1Init_Note (&pvalue->note);
   asn1Init_CurrencyCodeType (&pvalue->transactionCurrencyCode);
   asn1Init_CurrencyCodeType (&pvalue->pricingCurrencyCode);
   asn1Init_UBL_OrderResponse_1_0_EarliestDate (&pvalue->earliestDate);
   asn1Init_ExpiryDate (&pvalue->expiryDate);
   asn1Init_UBL_OrderResponse_1_0_ValidityDurationMeasure (&pvalue->validityDurationMeasure);
   asn1Init_TaxTotalAmount (&pvalue->taxTotalAmount);
   asn1Init_LineExtensionTotalAmount (&pvalue->lineExtensionTotalAmount);
   asn1Init_UBL_OrderResponse_1_0_TotalPackagesCountQuantity (&pvalue->totalPackagesCountQuantity);
   asn1Init_GrossWeightMeasure (&pvalue->grossWeightMeasure);
   asn1Init_NetWeightMeasure (&pvalue->netWeightMeasure);
   asn1Init_NetNetWeightMeasure (&pvalue->netNetWeightMeasure);
   asn1Init_GrossVolumeMeasure (&pvalue->grossVolumeMeasure);
   asn1Init_NetVolumeMeasure (&pvalue->netVolumeMeasure);
   asn1Init_UBL_OrderResponse_1_0_LineItemCountNumeric (&pvalue->lineItemCountNumeric);
   asn1Init_OrderResponseType_orderReference_list (&pvalue->orderReference_list);
   asn1Init_BuyerParty (&pvalue->buyerParty);
   asn1Init_SellerParty (&pvalue->sellerParty);
   asn1Init_UBL_OrderResponse_1_0_OriginatorParty (&pvalue->originatorParty);
   asn1Init_UBL_OrderResponse_1_0_FreightForwarderParty (&pvalue->freightForwarderParty);
   asn1Init__SeqOfDelivery (&pvalue->delivery_list);
   asn1Init_DeliveryTerms (&pvalue->deliveryTerms);
   asn1Init__SeqOfAllowanceCharge (&pvalue->allowanceCharge_list);
   asn1Init_SalesConditions (&pvalue->salesConditions);
   asn1Init_UBL_OrderResponse_1_0_DestinationCountry (&pvalue->destinationCountry);
   asn1Init_OrderResponseType_respondedOrderLine_list (&pvalue->respondedOrderLine_list);
   asn1Init_PaymentMeans (&pvalue->paymentMeans);
}

/**************************************************************/
/*                                                            */
/*  OrderResponse                                             */
/*                                                            */
/**************************************************************/

void asn1Init_OrderResponse (OrderResponse* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_OrderResponseType (pvalue);
}

/**************************************************************/
/*                                                            */
/*  PackagesCountQuantity                                     */
/*                                                            */
/**************************************************************/

void asn1Init_UBL_OrderResponse_1_0_PackagesCountQuantity (UBL_OrderResponse_1_0_PackagesCountQuantity* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_UBL_OrderResponse_1_0_PackagesCountQuantityType (pvalue);
}

