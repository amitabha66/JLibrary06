/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Ns2.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  Config_item_type                                          */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Config_item_type (OSCTXT* pctxt,
   Config_item_type *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if(*pvalue < 0 || *pvalue > 7)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_enum (pctxt, (OSINT32*)pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Config_item_type (OSCTXT* pctxt, Config_item_type value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt,
      Config_item_type_ToString (value), elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Config_item                                               */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Config_item (OSCTXT* pctxt,
   Config_item *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   /* encode type */

   if(pvalue->type < 0 || pvalue->type > 7)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|1,
      asn1E_Config_item_type (pctxt, &pvalue->type, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   /* encode name */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|0,
      xe_utf8str (pctxt, pvalue->name, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

int XmlEnc_Config_item (OSCTXT* pctxt, Config_item* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   if (0 != elemName) {
      stat = rtXmlEncStartElement (pctxt, elemName, nsPrefix, FALSE);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   /* add attributes */

   OSRTSAFEMEMCPY (pctxt, OSUTF8(" ns2:name=\""), 11);

   stat = rtXmlEncUTF8Str (pctxt, pvalue->name, 0, 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   OSRTSAFEPUTCHAR (pctxt, '\"');

   OSRTSAFEMEMCPY (pctxt, OSUTF8(" ns2:type=\""), 11);

   if(pvalue->type < 0 || pvalue->type > 7)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   stat = XmlEnc_Config_item_type (pctxt, pvalue->type, 0, 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   OSRTSAFEPUTCHAR (pctxt, '"');

   OSRTSAFEPUTCHAR (pctxt, '>');
   pctxt->flags &= ~OSTERMSTART;
   pctxt->state = OSXMLSTART;

   stat = rtXmlEncEndElement (pctxt, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Config_item_map_indexed                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Config_item_map_indexed (OSCTXT* pctxt,
   Config_item_map_indexed *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;
   OSRTDListNode* pnode2;
   int ll2 = 0;

   /* encode config_item_map_entry_list */

   pnode2 = pvalue->config_item_map_entry_list.tail;
   while (0 != pnode2) {
      ll = asn1E_Config_item_map_entry (pctxt, (Config_item_map_entry*)((Config_item_map_entry*)pnode2->data), ASN1EXPL);
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll2 += ll;

      pnode2 = pnode2->prev;
   }
   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|1, ll2);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   else { ll1 += ll; ll2 = 0; }

   /* encode name */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|0,
      xe_utf8str (pctxt, pvalue->name, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

int XmlEnc_Config_item_map_indexed (OSCTXT* pctxt, 
   Config_item_map_indexed* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   if (0 != elemName) {
      stat = rtXmlEncStartElement (pctxt, elemName, nsPrefix, FALSE);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   /* add attributes */

   OSRTSAFEMEMCPY (pctxt, OSUTF8(" ns2:name=\""), 11);

   stat = rtXmlEncUTF8Str (pctxt, pvalue->name, 0, 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   OSRTSAFEPUTCHAR (pctxt, '\"');

   OSRTSAFEPUTCHAR (pctxt, '>');
   pctxt->flags &= ~OSTERMSTART;
   pctxt->state = OSXMLSTART;

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "urn:oasis:names:tc:opendocument:xmlns:config:1.0"));

   /* encode config_item_map_entry_list */

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "urn:oasis:names:tc:opendocument:xmlns:config:1.0"));

   { OSRTDListNode* pnode = pvalue->config_item_map_entry_list.head;
   while (0 != pnode) {
      stat = XmlEnc_Config_item_map_entry (pctxt, 
         ((Config_item_map_entry*)pnode->data)
         , OSUTF8("config-item-map-entry"), nsPrefix);
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

/**************************************************************/
/*                                                            */
/*  Config_item_map_entry_element                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Config_item_map_entry_element (OSCTXT* pctxt,
   Config_item_map_entry_element *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   ll0 = 0;
   switch (pvalue->t)
   {
      case 1:
         ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|0,
            asn1E_Config_item (pctxt, pvalue->u.config_item, ASN1IMPL));
         if (ll < 0) return LOG_RTERR (pctxt, ll);
         ll1 += ll;
         break;

      case 2:
         ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|1,
            asn1E_Config_item_set (pctxt, (Config_item_set*)pvalue->u.config_item_set, ASN1IMPL));
         if (ll < 0) return LOG_RTERR (pctxt, ll);
         ll1 += ll;
         break;

      case 3:
         ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|2,
            asn1E_Config_item_map_named (pctxt, (Config_item_map_named*)pvalue->u.config_item_map_named, ASN1IMPL));
         if (ll < 0) return LOG_RTERR (pctxt, ll);
         ll1 += ll;
         break;

      case 4:
         ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|3,
            asn1E_Config_item_map_indexed (pctxt, pvalue->u.config_item_map_indexed, ASN1IMPL));
         if (ll < 0) return LOG_RTERR (pctxt, ll);
         ll1 += ll;
         break;

      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }
   ll0 += ll1;

   return (ll0);
}

int XmlEnc_Config_item_map_entry_element (OSCTXT* pctxt, 
   Config_item_map_entry_element* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   if (0 != elemName) {
      stat = rtXmlEncStartElement (pctxt, elemName, nsPrefix, TRUE);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "urn:oasis:names:tc:opendocument:xmlns:config:1.0"));

   switch (pvalue->t)
   {
      case 1:
         /* encode config_item */

         stat = XmlEnc_Config_item (pctxt, pvalue->u.config_item
            , OSUTF8("config-item"), nsPrefix);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         break;

      case 2:
         /* encode config_item_set */

         stat = XmlEnc_Config_item_set (pctxt, pvalue->u.config_item_set
            , OSUTF8("config-item-set"), nsPrefix);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         break;

      case 3:
         /* encode config_item_map_named */

         stat = XmlEnc_Config_item_map_named (pctxt, pvalue->
            u.config_item_map_named
            , OSUTF8("config-item-map-named"), nsPrefix);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         break;

      case 4:
         /* encode config_item_map_indexed */

         stat = XmlEnc_Config_item_map_indexed (pctxt, pvalue->
            u.config_item_map_indexed
            , OSUTF8("config-item-map-indexed"), nsPrefix);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         break;

      default: {
         char buf[40];
         os_snprintf (buf, 40, "%d", pvalue->t);
         return LOG_RTERRNEW1 (pctxt, RTERR_INVOPT, 
            rtxErrAddStrParm (pctxt, buf));
      }
   }
   nsPrefix = savedPrefix;
   }

   stat = rtXmlEncEndElement (pctxt, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Config_item_map_entry                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Config_item_map_entry (OSCTXT* pctxt,
   Config_item_map_entry *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;
   OSRTDListNode* pnode2;
   int ll2 = 0;

   /* encode choice_list */

   pnode2 = pvalue->choice_list.tail;
   while (0 != pnode2) {
      ll = asn1E_Config_item_map_entry_element (pctxt, ((Config_item_map_entry_element*)pnode2->data), ASN1EXPL);
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll2 += ll;

      pnode2 = pnode2->prev;
   }
   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|1, ll2);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   else { ll1 += ll; ll2 = 0; }

   /* encode name */

   if (pvalue->m.namePresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|0,
         xe_utf8str (pctxt, pvalue->name, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

int XmlEnc_Config_item_map_entry (OSCTXT* pctxt, 
   Config_item_map_entry* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   if (0 != elemName) {
      stat = rtXmlEncStartElement (pctxt, elemName, nsPrefix, FALSE);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   /* add attributes */

   if (pvalue->m.namePresent) {
      OSRTSAFEMEMCPY (pctxt, OSUTF8(" ns2:name=\""), 11);

      stat = rtXmlEncUTF8Str (pctxt, pvalue->name, 0, 0);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      OSRTSAFEPUTCHAR (pctxt, '\"');
   }

   OSRTSAFEPUTCHAR (pctxt, '>');
   pctxt->flags &= ~OSTERMSTART;
   pctxt->state = OSXMLSTART;

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "urn:oasis:names:tc:opendocument:xmlns:config:1.0"));

   /* encode choice_list */

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "urn:oasis:names:tc:opendocument:xmlns:config:1.0"));

   { OSRTDListNode* pnode = pvalue->choice_list.head;
   while (0 != pnode) {
      stat = XmlEnc_Config_item_map_entry_element (pctxt, 
         ((Config_item_map_entry_element*)pnode->data), 0, nsPrefix);
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

/**************************************************************/
/*                                                            */
/*  Config_item_map_named                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Config_item_map_named (OSCTXT* pctxt,
   Config_item_map_named *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;
   OSRTDListNode* pnode2;
   int ll2 = 0;

   /* encode config_item_map_entry_list */

   pnode2 = pvalue->config_item_map_entry_list.tail;
   while (0 != pnode2) {
      ll = asn1E_Config_item_map_entry (pctxt, ((Config_item_map_entry*)pnode2->data), ASN1EXPL);
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll2 += ll;

      pnode2 = pnode2->prev;
   }
   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|1, ll2);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   else { ll1 += ll; ll2 = 0; }

   /* encode name */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|0,
      xe_utf8str (pctxt, pvalue->name, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

int XmlEnc_Config_item_map_named (OSCTXT* pctxt, 
   Config_item_map_named* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   if (0 != elemName) {
      stat = rtXmlEncStartElement (pctxt, elemName, nsPrefix, FALSE);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   /* add attributes */

   OSRTSAFEMEMCPY (pctxt, OSUTF8(" ns2:name=\""), 11);

   stat = rtXmlEncUTF8Str (pctxt, pvalue->name, 0, 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   OSRTSAFEPUTCHAR (pctxt, '\"');

   OSRTSAFEPUTCHAR (pctxt, '>');
   pctxt->flags &= ~OSTERMSTART;
   pctxt->state = OSXMLSTART;

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "urn:oasis:names:tc:opendocument:xmlns:config:1.0"));

   /* encode config_item_map_entry_list */

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "urn:oasis:names:tc:opendocument:xmlns:config:1.0"));

   { OSRTDListNode* pnode = pvalue->config_item_map_entry_list.head;
   while (0 != pnode) {
      stat = XmlEnc_Config_item_map_entry (pctxt, 
         ((Config_item_map_entry*)pnode->data)
         , OSUTF8("config-item-map-entry"), nsPrefix);
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

/**************************************************************/
/*                                                            */
/*  Config_item_set_element                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Config_item_set_element (OSCTXT* pctxt,
   Config_item_set_element *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   ll0 = 0;
   switch (pvalue->t)
   {
      case 1:
         ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|0,
            asn1E_Config_item (pctxt, pvalue->u.config_item, ASN1IMPL));
         if (ll < 0) return LOG_RTERR (pctxt, ll);
         ll1 += ll;
         break;

      case 2:
         ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|1,
            asn1E_Config_item_set (pctxt, (Config_item_set*)pvalue->u.config_item_set, ASN1IMPL));
         if (ll < 0) return LOG_RTERR (pctxt, ll);
         ll1 += ll;
         break;

      case 3:
         ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|2,
            asn1E_Config_item_map_named (pctxt, pvalue->u.config_item_map_named, ASN1IMPL));
         if (ll < 0) return LOG_RTERR (pctxt, ll);
         ll1 += ll;
         break;

      case 4:
         ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|3,
            asn1E_Config_item_map_indexed (pctxt, pvalue->u.config_item_map_indexed, ASN1IMPL));
         if (ll < 0) return LOG_RTERR (pctxt, ll);
         ll1 += ll;
         break;

      default:
         return LOG_RTERR (pctxt, RTERR_INVOPT);
   }
   ll0 += ll1;

   return (ll0);
}

int XmlEnc_Config_item_set_element (OSCTXT* pctxt, 
   Config_item_set_element* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   if (0 != elemName) {
      stat = rtXmlEncStartElement (pctxt, elemName, nsPrefix, TRUE);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "urn:oasis:names:tc:opendocument:xmlns:config:1.0"));

   switch (pvalue->t)
   {
      case 1:
         /* encode config_item */

         stat = XmlEnc_Config_item (pctxt, pvalue->u.config_item
            , OSUTF8("config-item"), nsPrefix);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         break;

      case 2:
         /* encode config_item_set */

         stat = XmlEnc_Config_item_set (pctxt, pvalue->u.config_item_set
            , OSUTF8("config-item-set"), nsPrefix);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         break;

      case 3:
         /* encode config_item_map_named */

         stat = XmlEnc_Config_item_map_named (pctxt, pvalue->
            u.config_item_map_named
            , OSUTF8("config-item-map-named"), nsPrefix);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         break;

      case 4:
         /* encode config_item_map_indexed */

         stat = XmlEnc_Config_item_map_indexed (pctxt, pvalue->
            u.config_item_map_indexed
            , OSUTF8("config-item-map-indexed"), nsPrefix);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         break;

      default: {
         char buf[40];
         os_snprintf (buf, 40, "%d", pvalue->t);
         return LOG_RTERRNEW1 (pctxt, RTERR_INVOPT, 
            rtxErrAddStrParm (pctxt, buf));
      }
   }
   nsPrefix = savedPrefix;
   }

   stat = rtXmlEncEndElement (pctxt, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Config_item_set                                           */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Config_item_set (OSCTXT* pctxt,
   Config_item_set *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;
   OSRTDListNode* pnode2;
   int ll2 = 0;

   /* encode choice_list */

   pnode2 = pvalue->choice_list.tail;
   while (0 != pnode2) {
      ll = asn1E_Config_item_set_element (pctxt, ((Config_item_set_element*)pnode2->data), ASN1EXPL);
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll2 += ll;

      pnode2 = pnode2->prev;
   }
   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|1, ll2);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   else { ll1 += ll; ll2 = 0; }

   /* encode name */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|0,
      xe_utf8str (pctxt, pvalue->name, ASN1IMPL));
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll1 += ll;

   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

int XmlEnc_Config_item_set (OSCTXT* pctxt, Config_item_set* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   if (0 != elemName) {
      stat = rtXmlEncStartElement (pctxt, elemName, nsPrefix, FALSE);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   /* add attributes */

   OSRTSAFEMEMCPY (pctxt, OSUTF8(" ns2:name=\""), 11);

   stat = rtXmlEncUTF8Str (pctxt, pvalue->name, 0, 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   OSRTSAFEPUTCHAR (pctxt, '\"');

   OSRTSAFEPUTCHAR (pctxt, '>');
   pctxt->flags &= ~OSTERMSTART;
   pctxt->state = OSXMLSTART;

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "urn:oasis:names:tc:opendocument:xmlns:config:1.0"));

   /* encode choice_list */

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "urn:oasis:names:tc:opendocument:xmlns:config:1.0"));

   { OSRTDListNode* pnode = pvalue->choice_list.head;
   while (0 != pnode) {
      stat = XmlEnc_Config_item_set_element (pctxt, 
         ((Config_item_set_element*)pnode->data), 0, nsPrefix);
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
