/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#include "asn1intl.h"
#include "UBL-Invoice-1-0.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  TaxPointDateType                                          */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_TaxPointDateType (OSCTXT* pctxt,
   TaxPointDateType *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   /* encode base */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|0,
      xe_utf8str (pctxt, pvalue->base, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  TaxPointDate                                              */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_TaxPointDate (OSCTXT* pctxt,
   TaxPointDate *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_TaxPointDateType (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  LineItemCountNumericType                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_UBL_Invoice_1_0_LineItemCountNumericType (OSCTXT* pctxt,
   UBL_Invoice_1_0_LineItemCountNumericType *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   /* encode base */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|0,
      xe_real (pctxt, &pvalue->base, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  LineItemCountNumeric                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_UBL_Invoice_1_0_LineItemCountNumeric (OSCTXT* pctxt,
   UBL_Invoice_1_0_LineItemCountNumeric *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_UBL_Invoice_1_0_LineItemCountNumericType (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  DespatchDocumentReference                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_DespatchDocumentReference (OSCTXT* pctxt,
   DespatchDocumentReference *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DocumentReferenceType (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  _SeqOfDespatchDocumentReference                           */
/*                                                            */
/**************************************************************/

EXTERN int asn1E__SeqOfDespatchDocumentReference (OSCTXT* pctxt,
   _SeqOfDespatchDocumentReference *pvalue, ASN1TagType tagging)
{
   OSRTDListNode* pnode;
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   pnode = pvalue->tail;
   while (0 != pnode) {
      ll = asn1E_DespatchDocumentReference (pctxt, ((DespatchDocumentReference*)pnode->data), ASN1EXPL);
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;

      pnode = pnode->prev;
   }
   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  ReceiptDocumentReference                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_ReceiptDocumentReference (OSCTXT* pctxt,
   ReceiptDocumentReference *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DocumentReferenceType (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  _SeqOfReceiptDocumentReference                            */
/*                                                            */
/**************************************************************/

EXTERN int asn1E__SeqOfReceiptDocumentReference (OSCTXT* pctxt,
   _SeqOfReceiptDocumentReference *pvalue, ASN1TagType tagging)
{
   OSRTDListNode* pnode;
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   pnode = pvalue->tail;
   while (0 != pnode) {
      ll = asn1E_ReceiptDocumentReference (pctxt, ((ReceiptDocumentReference*)pnode->data), ASN1EXPL);
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;

      pnode = pnode->prev;
   }
   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  AdditionalDocumentReference                               */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_AdditionalDocumentReference (OSCTXT* pctxt,
   AdditionalDocumentReference *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DocumentReferenceType (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  _SeqOfAdditionalDocumentReference                         */
/*                                                            */
/**************************************************************/

EXTERN int asn1E__SeqOfAdditionalDocumentReference (OSCTXT* pctxt,
   _SeqOfAdditionalDocumentReference *pvalue, ASN1TagType tagging)
{
   OSRTDListNode* pnode;
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   pnode = pvalue->tail;
   while (0 != pnode) {
      ll = asn1E_AdditionalDocumentReference (pctxt, ((AdditionalDocumentReference*)pnode->data), ASN1EXPL);
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;

      pnode = pnode->prev;
   }
   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  InvoiceType_invoiceLine_list                              */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_InvoiceType_invoiceLine_list (OSCTXT* pctxt,
   InvoiceType_invoiceLine_list *pvalue, ASN1TagType tagging)
{
   OSRTDListNode* pnode;
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   pnode = pvalue->tail;
   while (0 != pnode) {
      ll = asn1E_InvoiceLine (pctxt, ((InvoiceLine*)pnode->data), ASN1EXPL);
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;

      pnode = pnode->prev;
   }
   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
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

   /* encode invoiceLine_list */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|24,
      asn1E_InvoiceType_invoiceLine_list (pctxt, &pvalue->invoiceLine_list, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode legalTotal */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|23,
      asn1E_LegalTotal (pctxt, &pvalue->legalTotal, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode taxTotal_list */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|22,
      asn1E__SeqOfTaxTotal (pctxt, &pvalue->taxTotal_list, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode exchangeRate */

   if (pvalue->m.exchangeRatePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|21,
         asn1E_ExchangeRate (pctxt, &pvalue->exchangeRate, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode allowanceCharge_list */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|20,
      asn1E__SeqOfAllowanceCharge (pctxt, &pvalue->allowanceCharge_list, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode paymentTerms_list */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|19,
      asn1E__SeqOfPaymentTerms (pctxt, &pvalue->paymentTerms_list, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode paymentMeans */

   if (pvalue->m.paymentMeansPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|18,
         asn1E_PaymentMeans (pctxt, &pvalue->paymentMeans, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode delivery_list */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|17,
      asn1E__SeqOfDelivery (pctxt, &pvalue->delivery_list, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode sellerParty */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|16,
      asn1E_SellerParty (pctxt, &pvalue->sellerParty, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode buyerParty */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|15,
      asn1E_BuyerParty (pctxt, &pvalue->buyerParty, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode additionalDocumentReference_list */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|14,
      asn1E__SeqOfAdditionalDocumentReference (pctxt, &pvalue->additionalDocumentReference_list, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode receiptDocumentReference_list */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|13,
      asn1E__SeqOfReceiptDocumentReference (pctxt, &pvalue->receiptDocumentReference_list, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode despatchDocumentReference_list */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|12,
      asn1E__SeqOfDespatchDocumentReference (pctxt, &pvalue->despatchDocumentReference_list, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode orderReference_list */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|11,
      asn1E__SeqOfOrderReference (pctxt, &pvalue->orderReference_list, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode lineItemCountNumeric */

   if (pvalue->m.lineItemCountNumericPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|10,
         asn1E_UBL_Invoice_1_0_LineItemCountNumeric (pctxt, &pvalue->lineItemCountNumeric, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode pricingCurrencyCode */

   if (pvalue->m.pricingCurrencyCodePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|9,
         asn1E_CurrencyCodeType (pctxt, &pvalue->pricingCurrencyCode, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode taxCurrencyCode */

   if (pvalue->m.taxCurrencyCodePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|8,
         asn1E_CurrencyCodeType (pctxt, &pvalue->taxCurrencyCode, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode invoiceCurrencyCode */

   if (pvalue->m.invoiceCurrencyCodePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|7,
         asn1E_CurrencyCodeType (pctxt, &pvalue->invoiceCurrencyCode, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode taxPointDate */

   if (pvalue->m.taxPointDatePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|6,
         asn1E_TaxPointDate (pctxt, &pvalue->taxPointDate, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode note */

   if (pvalue->m.notePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|5,
         asn1E_Note (pctxt, &pvalue->note, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode invoiceTypeCode */

   if (pvalue->m.invoiceTypeCodePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|4,
         asn1E_UBL_UnspecializedDatatypes_1_0_CodeType (pctxt, &pvalue->invoiceTypeCode, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode issueDate */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|3,
      asn1E_IssueDate (pctxt, &pvalue->issueDate, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode gUID */

   if (pvalue->m.gUIDPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|2,
         asn1E_UBL_UnspecializedDatatypes_1_0_IdentifierType (pctxt, &pvalue->gUID, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode copyIndicator */

   if (pvalue->m.copyIndicatorPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|1,
         asn1E_CopyIndicator (pctxt, &pvalue->copyIndicator, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode iD */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|0,
      asn1E_UBL_UnspecializedDatatypes_1_0_IdentifierType (pctxt, &pvalue->iD, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
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

