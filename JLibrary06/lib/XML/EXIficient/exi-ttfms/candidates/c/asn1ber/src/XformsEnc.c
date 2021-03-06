/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Xforms.h"
#include "Odf.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  Bind                                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Bind (OSCTXT* pctxt,
   Bind pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Bind (OSCTXT* pctxt, Bind value, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Model                                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Model (OSCTXT* pctxt,
   Model *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;
   OSRTDListNode* pnode2;
   int ll2 = 0;

   /* encode element14_list */

   pnode2 = pvalue->element14_list.tail;
   while (0 != pnode2) {
      ll = asn1E_Odf_Element14 (pctxt, (Odf_Element14*)((Odf_Element14*)pnode2->data), ASN1EXPL);
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

int XmlEnc_Model (OSCTXT* pctxt, Model* pvalue, const OSUTF8CHAR* elemName, 
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
      "http://www.w3.org/2002/xforms"));

   /* encode element14_list */

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "http://www.w3.org/2002/xforms"));

   { OSRTDListNode* pnode = pvalue->element14_list.head;
   while (0 != pnode) {
      stat = XmlEnc_Odf_Element14 (pctxt, *((Odf_Element14*)pnode->data)
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

