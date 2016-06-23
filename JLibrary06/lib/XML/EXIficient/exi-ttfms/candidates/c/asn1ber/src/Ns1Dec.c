/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Ns1.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  Country                                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_Ns1_Country (OSCTXT* pctxt, Ns1_Country *pvalue, 
   ASN1TagType tagging, int length)
{
   int stat = 0;

   stat = xd_utf8str (pctxt, pvalue, tagging, length);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

int XmlDec_Ns1_Country (OSCTXT* pctxt, Ns1_Country* pvalue)
{
   int stat = 0;

   stat = rtXmlpDecDynUTF8Str (pctxt, pvalue);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Language                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_Ns1_Language (OSCTXT* pctxt, Ns1_Language *pvalue, 
   ASN1TagType tagging, int length)
{
   int stat = 0;

   stat = xd_utf8str (pctxt, pvalue, tagging, length);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

int XmlDec_Ns1_Language (OSCTXT* pctxt, Ns1_Language* pvalue)
{
   int stat = 0;

   stat = rtXmlpDecDynUTF8Str (pctxt, pvalue);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Max_height                                                */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_Ns1_Max_height (OSCTXT* pctxt, Ns1_Max_height *pvalue, 
   ASN1TagType tagging, int length)
{
   int stat = 0;
   ASN1TAG ctag;
   ASN1CCB ccb;

   /* decode CHOICE */

   stat = xd_tag_len (pctxt, &ctag, &length, XM_ADVANCE);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   ccb.len = length;
   ccb.ptr = OSRTBUFPTR(pctxt);

   switch (ctag)
   {
      case (TM_CTXT|TM_PRIM|0):
      case (TM_CTXT|TM_CONS|0):
         stat = xd_utf8str (pctxt, &pvalue->u.alt, ASN1IMPL, length);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         pvalue->t = 1;
         ccb.len = 0;
         break;

      case (TM_CTXT|TM_PRIM|1):
      case (TM_CTXT|TM_CONS|1):
         stat = xd_utf8str (pctxt, &pvalue->u.alt_1, ASN1IMPL, length);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         pvalue->t = 2;
         ccb.len = 0;
         break;

      default:
         xu_addTagErrParm (pctxt, ctag);
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   if (ccb.len == ASN_K_INDEFLEN) {
      if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
      else return LOG_RTERR (pctxt, ASN_E_INVLEN);
   }

   return (stat);
}

int XmlDec_Ns1_Max_height (OSCTXT* pctxt, Ns1_Max_height* pvalue)
{
   int stat = 0;

   { const OSUTF8CHAR* pdata1;

   stat = rtXmlpDecDynUTF8Str (pctxt, &pdata1);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   pvalue->t = 0;
   if (pvalue->t == 0) {
      pvalue->u.alt = pdata1;
      pvalue->t = 1;
   }
   if (pvalue->t == 0) {
      pvalue->u.alt_1 = pdata1;
      pvalue->t = 2;
   }
   }

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Max_width                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_Ns1_Max_width (OSCTXT* pctxt, Ns1_Max_width *pvalue, 
   ASN1TagType tagging, int length)
{
   int stat = 0;
   ASN1TAG ctag;
   ASN1CCB ccb;

   /* decode CHOICE */

   stat = xd_tag_len (pctxt, &ctag, &length, XM_ADVANCE);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   ccb.len = length;
   ccb.ptr = OSRTBUFPTR(pctxt);

   switch (ctag)
   {
      case (TM_CTXT|TM_PRIM|0):
      case (TM_CTXT|TM_CONS|0):
         stat = xd_utf8str (pctxt, &pvalue->u.alt, ASN1IMPL, length);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         pvalue->t = 1;
         ccb.len = 0;
         break;

      case (TM_CTXT|TM_PRIM|1):
      case (TM_CTXT|TM_CONS|1):
         stat = xd_utf8str (pctxt, &pvalue->u.alt_1, ASN1IMPL, length);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         pvalue->t = 2;
         ccb.len = 0;
         break;

      default:
         xu_addTagErrParm (pctxt, ctag);
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   if (ccb.len == ASN_K_INDEFLEN) {
      if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
      else return LOG_RTERR (pctxt, ASN_E_INVLEN);
   }

   return (stat);
}

int XmlDec_Ns1_Max_width (OSCTXT* pctxt, Ns1_Max_width* pvalue)
{
   int stat = 0;

   { const OSUTF8CHAR* pdata1;

   stat = rtXmlpDecDynUTF8Str (pctxt, &pdata1);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   pvalue->t = 0;
   if (pvalue->t == 0) {
      pvalue->u.alt = pdata1;
      pvalue->t = 1;
   }
   if (pvalue->t == 0) {
      pvalue->u.alt_1 = pdata1;
      pvalue->t = 2;
   }
   }

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Min_height                                                */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_Ns1_Min_height (OSCTXT* pctxt, Ns1_Min_height *pvalue, 
   ASN1TagType tagging, int length)
{
   int stat = 0;
   ASN1TAG ctag;
   ASN1CCB ccb;

   /* decode CHOICE */

   stat = xd_tag_len (pctxt, &ctag, &length, XM_ADVANCE);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   ccb.len = length;
   ccb.ptr = OSRTBUFPTR(pctxt);

   switch (ctag)
   {
      case (TM_CTXT|TM_PRIM|0):
      case (TM_CTXT|TM_CONS|0):
         stat = xd_utf8str (pctxt, &pvalue->u.alt, ASN1IMPL, length);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         pvalue->t = 1;
         ccb.len = 0;
         break;

      case (TM_CTXT|TM_PRIM|1):
      case (TM_CTXT|TM_CONS|1):
         stat = xd_utf8str (pctxt, &pvalue->u.alt_1, ASN1IMPL, length);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         pvalue->t = 2;
         ccb.len = 0;
         break;

      default:
         xu_addTagErrParm (pctxt, ctag);
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   if (ccb.len == ASN_K_INDEFLEN) {
      if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
      else return LOG_RTERR (pctxt, ASN_E_INVLEN);
   }

   return (stat);
}

int XmlDec_Ns1_Min_height (OSCTXT* pctxt, Ns1_Min_height* pvalue)
{
   int stat = 0;

   { const OSUTF8CHAR* pdata1;

   stat = rtXmlpDecDynUTF8Str (pctxt, &pdata1);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   pvalue->t = 0;
   if (pvalue->t == 0) {
      pvalue->u.alt = pdata1;
      pvalue->t = 1;
   }
   if (pvalue->t == 0) {
      pvalue->u.alt_1 = pdata1;
      pvalue->t = 2;
   }
   }

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Min_width                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_Ns1_Min_width (OSCTXT* pctxt, Ns1_Min_width *pvalue, 
   ASN1TagType tagging, int length)
{
   int stat = 0;
   ASN1TAG ctag;
   ASN1CCB ccb;

   /* decode CHOICE */

   stat = xd_tag_len (pctxt, &ctag, &length, XM_ADVANCE);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   ccb.len = length;
   ccb.ptr = OSRTBUFPTR(pctxt);

   switch (ctag)
   {
      case (TM_CTXT|TM_PRIM|0):
      case (TM_CTXT|TM_CONS|0):
         stat = xd_utf8str (pctxt, &pvalue->u.alt, ASN1IMPL, length);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         pvalue->t = 1;
         ccb.len = 0;
         break;

      case (TM_CTXT|TM_PRIM|1):
      case (TM_CTXT|TM_CONS|1):
         stat = xd_utf8str (pctxt, &pvalue->u.alt_1, ASN1IMPL, length);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         pvalue->t = 2;
         ccb.len = 0;
         break;

      default:
         xu_addTagErrParm (pctxt, ctag);
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }

   if (ccb.len == ASN_K_INDEFLEN) {
      if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
      else return LOG_RTERR (pctxt, ASN_E_INVLEN);
   }

   return (stat);
}

int XmlDec_Ns1_Min_width (OSCTXT* pctxt, Ns1_Min_width* pvalue)
{
   int stat = 0;

   { const OSUTF8CHAR* pdata1;

   stat = rtXmlpDecDynUTF8Str (pctxt, &pdata1);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   pvalue->t = 0;
   if (pvalue->t == 0) {
      pvalue->u.alt = pdata1;
      pvalue->t = 1;
   }
   if (pvalue->t == 0) {
      pvalue->u.alt_1 = pdata1;
      pvalue->t = 2;
   }
   }

   return (stat);
}
