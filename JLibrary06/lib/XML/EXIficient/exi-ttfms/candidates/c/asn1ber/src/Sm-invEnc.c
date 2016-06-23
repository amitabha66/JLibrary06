/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Sm-inv.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  InvoiceHeaderType                                         */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_InvoiceHeaderType (OSCTXT* pctxt,
   InvoiceHeaderType *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   /* encode lineItemCountValue */

   if (pvalue->m.lineItemCountValuePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|11,
         asn1E_CCT_NumericType (pctxt, &pvalue->lineItemCountValue, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode paymentMeans */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|10,
      asn1E_PaymentMeansType (pctxt, &pvalue->paymentMeans, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode shipment */

   if (pvalue->m.shipmentPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|9,
         asn1E_ShipmentType (pctxt, &pvalue->shipment, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode despatchParty */

   if (pvalue->m.despatchPartyPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|8,
         asn1E_PartyType (pctxt, &pvalue->despatchParty, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode consigneeParty */

   if (pvalue->m.consigneePartyPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|7,
         asn1E_PartyType (pctxt, &pvalue->consigneeParty, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode sellerParty */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|6,
      asn1E_PartyType (pctxt, &pvalue->sellerParty, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode buyerParty */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|5,
      asn1E_PartyType (pctxt, &pvalue->buyerParty, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode language */

   if (pvalue->m.languagePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|4,
         asn1E_LanguageType (pctxt, &pvalue->language, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode currencyCode */

   if (pvalue->m.currencyCodePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|3,
         asn1E_CCT_CodeType (pctxt, &pvalue->currencyCode, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode pOIdentifier */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|2,
      asn1E_CCT_IdentifierType (pctxt, &pvalue->pOIdentifier, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode identifier */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|1,
      asn1E_CCT_IdentifierType (pctxt, &pvalue->identifier, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode issueDateTime */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|0,
      asn1E_CCT_DateTimeType (pctxt, &pvalue->issueDateTime, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

int XmlEnc_InvoiceHeaderType (OSCTXT* pctxt, InvoiceHeaderType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   if (0 != elemName) {
      stat = rtXmlEncStartElement (pctxt, elemName, nsPrefix, TRUE);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "http://www.sun.com/schema/spidermarkexpress/sm-inv"));

   /* encode issueDateTime */

   stat = XmlEnc_CCT_DateTimeType (pctxt, &pvalue->issueDateTime
      , OSUTF8("IssueDateTime"), 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   /* encode identifier */

   stat = XmlEnc_CCT_IdentifierType (pctxt, &pvalue->identifier
      , OSUTF8("Identifier"), 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   /* encode pOIdentifier */

   stat = XmlEnc_CCT_IdentifierType (pctxt, &pvalue->pOIdentifier
      , OSUTF8("POIdentifier"), 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   /* encode currencyCode */

   if (pvalue->m.currencyCodePresent) {
      stat = XmlEnc_CCT_CodeType (pctxt, &pvalue->currencyCode
         , OSUTF8("CurrencyCode"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   /* encode language */

   if (pvalue->m.languagePresent) {
      stat = XmlEnc_LanguageType (pctxt, &pvalue->language
         , OSUTF8("Language"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   /* encode buyerParty */

   stat = XmlEnc_PartyType (pctxt, &pvalue->buyerParty
      , OSUTF8("BuyerParty"), 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   /* encode sellerParty */

   stat = XmlEnc_PartyType (pctxt, &pvalue->sellerParty
      , OSUTF8("SellerParty"), 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   /* encode consigneeParty */

   if (pvalue->m.consigneePartyPresent) {
      stat = XmlEnc_PartyType (pctxt, &pvalue->consigneeParty
         , OSUTF8("ConsigneeParty"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   /* encode despatchParty */

   if (pvalue->m.despatchPartyPresent) {
      stat = XmlEnc_PartyType (pctxt, &pvalue->despatchParty
         , OSUTF8("DespatchParty"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   /* encode shipment */

   if (pvalue->m.shipmentPresent) {
      stat = XmlEnc_ShipmentType (pctxt, &pvalue->shipment
         , OSUTF8("Shipment"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   /* encode paymentMeans */

   stat = XmlEnc_PaymentMeansType (pctxt, &pvalue->paymentMeans
      , OSUTF8("PaymentMeans"), 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   /* encode lineItemCountValue */

   if (pvalue->m.lineItemCountValuePresent) {
      stat = XmlEnc_CCT_NumericType (pctxt, &pvalue->lineItemCountValue
         , OSUTF8("LineItemCountValue"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   nsPrefix = savedPrefix;
   }

   stat = rtXmlEncEndElement (pctxt, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  InvoiceLineItemType                                       */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_InvoiceLineItemType (OSCTXT* pctxt,
   InvoiceLineItemType *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   /* encode totalAmount */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|6,
      asn1E_CCT_AmountType (pctxt, &pvalue->totalAmount, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode itemTax */

   if (pvalue->m.itemTaxPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|5,
         asn1E_CCT_AmountType (pctxt, &pvalue->itemTax, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode pricingVariation */

   if (pvalue->m.pricingVariationPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|4,
         asn1E_PricingVariationType (pctxt, &pvalue->pricingVariation, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode pricing */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|3,
      asn1E_PricingType (pctxt, &pvalue->pricing, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode orderStatus */

   if (pvalue->m.orderStatusPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|2,
         asn1E_CCT_CodeType (pctxt, &pvalue->orderStatus, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode item */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|1,
      asn1E_ItemType (pctxt, &pvalue->item, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode lineID */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|0,
      asn1E_CCT_IdentifierType (pctxt, &pvalue->lineID, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

int XmlEnc_InvoiceLineItemType (OSCTXT* pctxt, InvoiceLineItemType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   if (0 != elemName) {
      stat = rtXmlEncStartElement (pctxt, elemName, nsPrefix, TRUE);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "http://www.sun.com/schema/spidermarkexpress/sm-inv"));

   /* encode lineID */

   stat = XmlEnc_CCT_IdentifierType (pctxt, &pvalue->lineID
      , OSUTF8("LineID"), 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   /* encode item */

   stat = XmlEnc_ItemType (pctxt, &pvalue->item, OSUTF8("Item"), 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   /* encode orderStatus */

   if (pvalue->m.orderStatusPresent) {
      stat = XmlEnc_CCT_CodeType (pctxt, &pvalue->orderStatus
         , OSUTF8("OrderStatus"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   /* encode pricing */

   stat = XmlEnc_PricingType (pctxt, &pvalue->pricing, OSUTF8("Pricing"), 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   /* encode pricingVariation */

   if (pvalue->m.pricingVariationPresent) {
      stat = XmlEnc_PricingVariationType (pctxt, &pvalue->pricingVariation
         , OSUTF8("PricingVariation"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   /* encode itemTax */

   if (pvalue->m.itemTaxPresent) {
      stat = XmlEnc_CCT_AmountType (pctxt, &pvalue->itemTax
         , OSUTF8("ItemTax"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   /* encode totalAmount */

   stat = XmlEnc_CCT_AmountType (pctxt, &pvalue->totalAmount
      , OSUTF8("TotalAmount"), 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   nsPrefix = savedPrefix;
   }

   stat = rtXmlEncEndElement (pctxt, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  InvoiceSummaryType                                        */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_InvoiceSummaryType (OSCTXT* pctxt,
   InvoiceSummaryType *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;
   OSRTDListNode* pnode2;
   int ll2 = 0;

   /* encode summaryNote */

   if (pvalue->m.summaryNotePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|6,
         asn1E_NoteType (pctxt, &pvalue->summaryNote, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode packingSlipIdentifier */

   if (pvalue->m.packingSlipIdentifierPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|5,
         asn1E_CCT_IdentifierType (pctxt, &pvalue->packingSlipIdentifier, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode priceAmount */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|4,
      asn1E_CCT_AmountType (pctxt, &pvalue->priceAmount, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode totalTax */

   if (pvalue->m.totalTaxPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|3,
         asn1E_TaxType (pctxt, &pvalue->totalTax, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode pricingVariation_list */

   pnode2 = pvalue->pricingVariation_list.tail;
   while (0 != pnode2) {
      ll = asn1E_PricingVariationType (pctxt, ((PricingVariationType*)pnode2->data), ASN1EXPL);
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll2 += ll;

      pnode2 = pnode2->prev;
   }
   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|2, ll2);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   else { ll1 += ll; ll2 = 0; }

   /* encode subtotalAmount */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|1,
      asn1E_CCT_AmountType (pctxt, &pvalue->subtotalAmount, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode lineItemCountValue */

   if (pvalue->m.lineItemCountValuePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|0,
         asn1E_CCT_NumericType (pctxt, &pvalue->lineItemCountValue, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

int XmlEnc_InvoiceSummaryType (OSCTXT* pctxt, InvoiceSummaryType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   if (0 != elemName) {
      stat = rtXmlEncStartElement (pctxt, elemName, nsPrefix, TRUE);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "http://www.sun.com/schema/spidermarkexpress/sm-inv"));

   /* encode lineItemCountValue */

   if (pvalue->m.lineItemCountValuePresent) {
      stat = XmlEnc_CCT_NumericType (pctxt, &pvalue->lineItemCountValue
         , OSUTF8("LineItemCountValue"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   /* encode subtotalAmount */

   stat = XmlEnc_CCT_AmountType (pctxt, &pvalue->subtotalAmount
      , OSUTF8("SubtotalAmount"), 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   /* encode pricingVariation_list */

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "http://www.sun.com/schema/spidermarkexpress/sm-inv"));

   { OSRTDListNode* pnode = pvalue->pricingVariation_list.head;
   while (0 != pnode) {
      stat = XmlEnc_PricingVariationType (pctxt, 
         ((PricingVariationType*)pnode->data), OSUTF8("PricingVariation"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      pnode = pnode->next;
   }}
   nsPrefix = savedPrefix;
   }

   /* encode totalTax */

   if (pvalue->m.totalTaxPresent) {
      stat = XmlEnc_TaxType (pctxt, &pvalue->totalTax, OSUTF8("TotalTax"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   /* encode priceAmount */

   stat = XmlEnc_CCT_AmountType (pctxt, &pvalue->priceAmount
      , OSUTF8("PriceAmount"), 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   /* encode packingSlipIdentifier */

   if (pvalue->m.packingSlipIdentifierPresent) {
      stat = XmlEnc_CCT_IdentifierType (pctxt, &pvalue->packingSlipIdentifier
         , OSUTF8("PackingSlipIdentifier"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   /* encode summaryNote */

   if (pvalue->m.summaryNotePresent) {
      stat = XmlEnc_NoteType (pctxt, &pvalue->summaryNote
         , OSUTF8("SummaryNote"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   nsPrefix = savedPrefix;
   }

   stat = rtXmlEncEndElement (pctxt, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  InvoiceType                                               */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_InvoiceType (OSCTXT* pctxt,
   InvoiceType *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;
   OSRTDListNode* pnode2;
   int ll2 = 0;

   /* encode summary */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|2,
      asn1E_InvoiceSummaryType (pctxt, &pvalue->summary, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode lineItem_list */

   if (!(pvalue->lineItem_list.count >= 1U)) {
      rtxErrAddStrParm (pctxt, "InvoiceType.lineItem_list.count");
      rtxErrAddIntParm (pctxt, (int)pvalue->lineItem_list.count);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   pnode2 = pvalue->lineItem_list.tail;
   while (0 != pnode2) {
      ll = asn1E_InvoiceLineItemType (pctxt, ((InvoiceLineItemType*)pnode2->data), ASN1EXPL);
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll2 += ll;

      pnode2 = pnode2->prev;
   }
   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|1, ll2);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   else { ll1 += ll; ll2 = 0; }

   /* encode header */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|0,
      asn1E_InvoiceHeaderType (pctxt, &pvalue->header, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

int XmlEnc_InvoiceType (OSCTXT* pctxt, InvoiceType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   if (0 != elemName) {
      stat = rtXmlEncStartElement (pctxt, elemName, nsPrefix, TRUE);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "http://www.sun.com/schema/spidermarkexpress/sm-inv"));

   /* encode header */

   stat = XmlEnc_InvoiceHeaderType (pctxt, &pvalue->header
      , OSUTF8("Header"), 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   /* encode lineItem_list */

   if (!(pvalue->lineItem_list.count >= 1U)) {
      rtxErrAddStrParm (pctxt, "InvoiceType.lineItem_list.count");
      rtxErrAddIntParm (pctxt, (int)pvalue->lineItem_list.count);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "http://www.sun.com/schema/spidermarkexpress/sm-inv"));

   { OSRTDListNode* pnode = pvalue->lineItem_list.head;
   while (0 != pnode) {
      stat = XmlEnc_InvoiceLineItemType (pctxt, 
         ((InvoiceLineItemType*)pnode->data), OSUTF8("LineItem"), 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      pnode = pnode->next;
   }}
   nsPrefix = savedPrefix;
   }

   /* encode summary */

   stat = XmlEnc_InvoiceSummaryType (pctxt, &pvalue->summary
      , OSUTF8("Summary"), 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   nsPrefix = savedPrefix;
   }

   stat = rtXmlEncEndElement (pctxt, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Invoice                                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Invoice (OSCTXT* pctxt,
   Invoice *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_InvoiceType (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Invoice (OSCTXT* pctxt, Invoice* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = XmlEnc_InvoiceType (pctxt, pvalue, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

int XmlEnc_Invoice_PDU (OSCTXT* pctxt, Invoice* pvalue)
{
   int stat;
   const OSUTF8CHAR* nsPrefix = 0;

   rtXmlNSSetNamespace (pctxt, OSUTF8("cct"), 
      OSUTF8("urn:oasis:names:tc:ubl:CommonLeafTypes:1.0:0.65"), FALSE);

   rtXmlNSSetNamespace (pctxt, OSUTF8("cmn"), 
      OSUTF8("http://www.sun.com/schema/spidermarkexpress/sm-common"), FALSE);

   rtXmlNSSetNamespace (pctxt, OSUTF8("jxb"), 
      OSUTF8("http://java.sun.com/xml/ns/jaxb"), FALSE);

   rtXmlNSSetNamespace (pctxt, 0, 
      OSUTF8("http://www.sun.com/schema/spidermarkexpress/sm-inv"), FALSE);

   nsPrefix = rtXmlNSGetPrefix (pctxt, 
      OSUTF8("http://www.sun.com/schema/spidermarkexpress/sm-inv"));

   stat = rtXmlEncStartDocument (pctxt);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   stat = rtXmlEncStartElement (pctxt, OSUTF8("invoice"), nsPrefix, FALSE);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   stat = rtXmlEncNSAttrs (pctxt);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   stat = rtXmlEncXSIAttrs (pctxt, FALSE);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   stat = XmlEnc_Invoice (pctxt, pvalue, 0, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   stat = rtXmlEncEndElement (pctxt, OSUTF8("invoice"), nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return stat;
}
