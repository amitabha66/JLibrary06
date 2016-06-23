/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#include "asn1intl.h"
#include "UBL-CodeList-SubstitutionStatusCode-1-0.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  SubstitutionStatusCodeContentType                         */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_SubstitutionStatusCodeContentType (OSCTXT* pctxt,
   SubstitutionStatusCodeContentType *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if(*pvalue < 0 || *pvalue > 1)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_enum (pctxt, (OSINT32*)pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  SubstitutionStatusCodeType                                */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_SubstitutionStatusCodeType (OSCTXT* pctxt,
   SubstitutionStatusCodeType *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   /* encode base */

   if(pvalue->base < 0 || pvalue->base > 1)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|9,
      asn1E_SubstitutionStatusCodeContentType (pctxt, &pvalue->base, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode name */

   if (pvalue->m.namePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|8,
         xe_utf8str (pctxt, pvalue->name, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode languageID */

   if (pvalue->m.languageIDPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|7,
         xe_utf8str (pctxt, pvalue->languageID, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode codeListVersionID */

   if (pvalue->m.codeListVersionIDPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|6,
         xe_utf8str (pctxt, pvalue->codeListVersionID, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode codeListURI */

   if (pvalue->m.codeListURIPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|5,
         xe_utf8str (pctxt, pvalue->codeListURI, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode codeListSchemeURI */

   if (pvalue->m.codeListSchemeURIPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|4,
         xe_utf8str (pctxt, pvalue->codeListSchemeURI, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode codeListName */

   if (pvalue->m.codeListNamePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|3,
         xe_utf8str (pctxt, pvalue->codeListName, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode codeListID */

   if (pvalue->m.codeListIDPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|2,
         xe_utf8str (pctxt, pvalue->codeListID, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode codeListAgencyName */

   if (pvalue->m.codeListAgencyNamePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|1,
         xe_utf8str (pctxt, pvalue->codeListAgencyName, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode codeListAgencyID */

   if (pvalue->m.codeListAgencyIDPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|0,
         xe_utf8str (pctxt, pvalue->codeListAgencyID, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

