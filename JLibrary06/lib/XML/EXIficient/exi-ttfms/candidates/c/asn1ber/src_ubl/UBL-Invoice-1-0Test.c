/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#include "asn1intl.h"
#include "UBL-Invoice-1-0.h"
#include "UBL-UnspecializedDatatypes-1-0.h"
#include "UBL-CoreComponentTypes-1-0.h"
#include "UBL-CommonBasicComponents-1-0.h"
#include "UBL-SpecializedDatatypes-1-0.h"
#include "UBL-CodeList-CurrencyCode-1-0.h"
#include "UBL-CommonAggregateComponents-1-0.h"
#include "UBL-CodeList-CountryIdentificationCode-1-0.h"
#include "UBL-CodeList-LatitudeDirectionCode-1-0.h"
#include "UBL-CodeList-LongitudeDirectionCode-1-0.h"
#include "UBL-CodeList-ChipCode-1-0.h"
#include "UBL-CodeList-PaymentMeansCode-1-0.h"
#include "UBL-CodeList-AllowanceChargeReasonCode-1-0.h"
#include "UBL-CodeList-ChannelCode-1-0.h"
#include "UBL-CodeList-DocumentStatusCode-1-0.h"
#include "UBL-CodeList-LineStatusCode-1-0.h"
#include "UBL-CodeList-OperatorCode-1-0.h"
#include "UBL-CodeList-SubstitutionStatusCode-1-0.h"
#include "UBL-DespatchAdvice-1-0.h"
#include "libxml/parser.h"
#include "rtxmlsrc/osrtxml.h"
#include "rtxsrc/rtxCommon.h"

void asn1DOMTest_TaxPointDateType (OSCTXT* pctxt, TaxPointDateType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      pvalue->base = pXmlNode->children->content;
   }
}

void asn1DOMTest_TaxPointDate (OSCTXT* pctxt, TaxPointDate* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   asn1DOMTest_TaxPointDateType (pctxt, pvalue, pXmlNode, TRUE);
}

void asn1DOMTest_UBL_Invoice_1_0_LineItemCountNumericType (OSCTXT* pctxt, 
   UBL_Invoice_1_0_LineItemCountNumericType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      pvalue->base = atof (pXmlNode->children->content);
   }
}

void asn1DOMTest_UBL_Invoice_1_0_LineItemCountNumeric (OSCTXT* pctxt, 
   UBL_Invoice_1_0_LineItemCountNumeric* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   asn1DOMTest_UBL_Invoice_1_0_LineItemCountNumericType (pctxt, pvalue, pXmlNode, TRUE);
}

void asn1DOMTest_DespatchDocumentReference (OSCTXT* pctxt, 
   DespatchDocumentReference* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   asn1DOMTest_DocumentReferenceType (pctxt, pvalue, pXmlNode, TRUE);
}

void asn1DOMTest__SeqOfDespatchDocumentReference (OSCTXT* pctxt, 
   _SeqOfDespatchDocumentReference* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   DespatchDocumentReference* pdata = rtxMemAllocTypeZ (pctxt, DespatchDocumentReference);
   asn1DOMTest_DespatchDocumentReference (pctxt, pdata, pXmlNode, setChild);
   if (0 != pdata)
      rtxDListAppend (pctxt, pvalue, (void*)pdata);
}

void asn1DOMTest_ReceiptDocumentReference (OSCTXT* pctxt, 
   ReceiptDocumentReference* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   asn1DOMTest_DocumentReferenceType (pctxt, pvalue, pXmlNode, TRUE);
}

void asn1DOMTest__SeqOfReceiptDocumentReference (OSCTXT* pctxt, 
   _SeqOfReceiptDocumentReference* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   ReceiptDocumentReference* pdata = rtxMemAllocTypeZ (pctxt, ReceiptDocumentReference);
   asn1DOMTest_ReceiptDocumentReference (pctxt, pdata, pXmlNode, setChild);
   if (0 != pdata)
      rtxDListAppend (pctxt, pvalue, (void*)pdata);
}

void asn1DOMTest_AdditionalDocumentReference (OSCTXT* pctxt, 
   AdditionalDocumentReference* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   asn1DOMTest_DocumentReferenceType (pctxt, pvalue, pXmlNode, TRUE);
}

void asn1DOMTest__SeqOfAdditionalDocumentReference (OSCTXT* pctxt, 
   _SeqOfAdditionalDocumentReference* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   AdditionalDocumentReference* pdata = rtxMemAllocTypeZ (pctxt, AdditionalDocumentReference);
   asn1DOMTest_AdditionalDocumentReference (pctxt, pdata, pXmlNode, setChild);
   if (0 != pdata)
      rtxDListAppend (pctxt, pvalue, (void*)pdata);
}

void asn1DOMTest_InvoiceType_invoiceLine_list (OSCTXT* pctxt, 
   InvoiceType_invoiceLine_list* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   InvoiceLine* pdata = rtxMemAllocTypeZ (pctxt, InvoiceLine);
   asn1DOMTest_InvoiceLine (pctxt, pdata, pXmlNode, setChild);
   if (0 != pdata)
      rtxDListAppend (pctxt, pvalue, (void*)pdata);
}

void asn1DOMTest_InvoiceType (OSCTXT* pctxt, InvoiceType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("ID"))) {
            asn1DOMTest_UBL_UnspecializedDatatypes_1_0_IdentifierType (pctxt, &pvalue->iD, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("CopyIndicator"))) {
            pvalue->m.copyIndicatorPresent = 1;
            asn1DOMTest_CopyIndicator (pctxt, &pvalue->copyIndicator, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("GUID"))) {
            pvalue->m.gUIDPresent = 1;
            asn1DOMTest_UBL_UnspecializedDatatypes_1_0_IdentifierType (pctxt, &pvalue->gUID, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("IssueDate"))) {
            asn1DOMTest_IssueDate (pctxt, &pvalue->issueDate, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("InvoiceTypeCode"))) {
            pvalue->m.invoiceTypeCodePresent = 1;
            asn1DOMTest_UBL_UnspecializedDatatypes_1_0_CodeType (pctxt, &pvalue->invoiceTypeCode, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Note"))) {
            pvalue->m.notePresent = 1;
            asn1DOMTest_Note (pctxt, &pvalue->note, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("TaxPointDate"))) {
            pvalue->m.taxPointDatePresent = 1;
            asn1DOMTest_TaxPointDate (pctxt, &pvalue->taxPointDate, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("InvoiceCurrencyCode"))) {
            pvalue->m.invoiceCurrencyCodePresent = 1;
            asn1DOMTest_CurrencyCodeType (pctxt, &pvalue->invoiceCurrencyCode, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("TaxCurrencyCode"))) {
            pvalue->m.taxCurrencyCodePresent = 1;
            asn1DOMTest_CurrencyCodeType (pctxt, &pvalue->taxCurrencyCode, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PricingCurrencyCode"))) {
            pvalue->m.pricingCurrencyCodePresent = 1;
            asn1DOMTest_CurrencyCodeType (pctxt, &pvalue->pricingCurrencyCode, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("LineItemCountNumeric"))) {
            pvalue->m.lineItemCountNumericPresent = 1;
            asn1DOMTest_UBL_Invoice_1_0_LineItemCountNumeric (pctxt, &pvalue->lineItemCountNumeric, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("OrderReference"))) {
            asn1DOMTest__SeqOfOrderReference (pctxt, &pvalue->orderReference_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("DespatchDocumentReference"))) {
            asn1DOMTest__SeqOfDespatchDocumentReference (pctxt, &pvalue->despatchDocumentReference_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("ReceiptDocumentReference"))) {
            asn1DOMTest__SeqOfReceiptDocumentReference (pctxt, &pvalue->receiptDocumentReference_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("AdditionalDocumentReference"))) {
            asn1DOMTest__SeqOfAdditionalDocumentReference (pctxt, &pvalue->additionalDocumentReference_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("BuyerParty"))) {
            asn1DOMTest_BuyerParty (pctxt, &pvalue->buyerParty, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("SellerParty"))) {
            asn1DOMTest_SellerParty (pctxt, &pvalue->sellerParty, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Delivery"))) {
            asn1DOMTest__SeqOfDelivery (pctxt, &pvalue->delivery_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PaymentMeans"))) {
            pvalue->m.paymentMeansPresent = 1;
            asn1DOMTest_PaymentMeans (pctxt, &pvalue->paymentMeans, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PaymentTerms"))) {
            asn1DOMTest__SeqOfPaymentTerms (pctxt, &pvalue->paymentTerms_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("AllowanceCharge"))) {
            asn1DOMTest__SeqOfAllowanceCharge (pctxt, &pvalue->allowanceCharge_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("ExchangeRate"))) {
            pvalue->m.exchangeRatePresent = 1;
            asn1DOMTest_ExchangeRate (pctxt, &pvalue->exchangeRate, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("TaxTotal"))) {
            asn1DOMTest__SeqOfTaxTotal (pctxt, &pvalue->taxTotal_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("LegalTotal"))) {
            asn1DOMTest_LegalTotal (pctxt, &pvalue->legalTotal, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("InvoiceLine"))) {
            asn1DOMTest_InvoiceType_invoiceLine_list (pctxt, &pvalue->invoiceLine_list, pXmlNode, TRUE);
         }
      }
   }
}

void asn1DOMTest_Invoice (OSCTXT* pctxt, Invoice* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   asn1DOMTest_InvoiceType (pctxt, pvalue, pXmlNode, TRUE);
}

