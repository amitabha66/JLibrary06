/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "MathML.h"
#include "Odf.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  Math                                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Math (OSCTXT* pctxt,
   Math *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;
   OSRTDListNode* pnode2;
   int ll2 = 0;

   /* encode element446_list */

   pnode2 = pvalue->element446_list.tail;
   while (0 != pnode2) {
      ll = asn1E_Odf_Element446 (pctxt, (Odf_Element446*)((Odf_Element446*)pnode2->data), ASN1EXPL);
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll2 += ll;

      pnode2 = pnode2->prev;
   }
   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|1, ll2);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   else { ll1 += ll; ll2 = 0; }

   /* encode attr */

   pnode2 = pvalue->attr.tail;
   while (0 != pnode2) {
      ll = xe_utf8str (pctxt, ((const OSUTF8CHAR*)pnode2->data), ASN1EXPL);
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll2 += ll;

      pnode2 = pnode2->prev;
   }
   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|0, ll2);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   else { ll1 += ll; ll2 = 0; }

   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

int XmlEnc_Math (OSCTXT* pctxt, Math* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   if (0 != elemName) {
      stat = rtXmlEncStartElement (pctxt, elemName, nsPrefix, FALSE);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   /* add attributes */
   { OSRTDListNode* pnode = pvalue->attr.head;
   size_t len;
   while (0 != pnode) {
      len = rtxUTF8LenBytes (pnode->data);

      stat = rtxCheckBuffer (pctxt, len + 1);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      OSRTPUTCHAR (pctxt, ' ');
      OSRTMEMCPY (pctxt, pnode->data, len);

      pnode = pnode->next;
   }}

   OSRTSAFEPUTCHAR (pctxt, '>');
   pctxt->flags &= ~OSTERMSTART;
   pctxt->state = OSXMLSTART;

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "http://www.w3.org/1998/Math/MathML"));

   /* encode element446_list */

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "http://www.w3.org/1998/Math/MathML"));

   { OSRTDListNode* pnode = pvalue->element446_list.head;
   while (0 != pnode) {
      stat = XmlEnc_Odf_Element446 (pctxt, *((Odf_Element446*)pnode->data)
         , 0, nsPrefix);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      pnode = pnode->next;
   }}
   nsPrefix = savedPrefix;
   }

   nsPrefix = savedPrefix;
   }

   stat = rtXmlEncEndElement (pctxt, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

