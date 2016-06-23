/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Datastore.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  DataType                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_DataType (OSCTXT* pctxt,
   DataType *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   /* encode booleanT */

   if (pvalue->m.booleanTPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|3,
         xe_boolean (pctxt, &pvalue->booleanT, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode binaryT */

   if (pvalue->m.binaryTPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|2,
         xe_octstr (pctxt, pvalue->binaryT.data, pvalue->binaryT.numocts, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode integerT */

   if (pvalue->m.integerTPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|1,
         xe_integer (pctxt, &pvalue->integerT, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   /* encode stringT */

   if (pvalue->m.stringTPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|0,
         xe_utf8str (pctxt, pvalue->stringT, ASN1IMPL));
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;
   }
   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

int XmlEnc_DataType (OSCTXT* pctxt, DataType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   if (0 != elemName) {
      stat = rtXmlEncStartElement (pctxt, elemName, nsPrefix, TRUE);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "http://www.sun.com/xml/datastore"));

   /* encode stringT */

   if (pvalue->m.stringTPresent) {
      stat = rtXmlEncUTF8Str (pctxt, pvalue->stringT
         , OSUTF8("stringT"), nsPrefix);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   /* encode integerT */

   if (pvalue->m.integerTPresent) {
      stat = rtXmlEncInt (pctxt, pvalue->integerT, OSUTF8("integerT"), nsPrefix
         );
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   /* encode binaryT */

   if (pvalue->m.binaryTPresent) {
      stat = rtXmlEncBase64Binary
         (pctxt, pvalue->binaryT.numocts, pvalue->binaryT.data, 
            OSUTF8("binaryT"), nsPrefix);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }
   /* encode booleanT */

   if (pvalue->m.booleanTPresent) {
      stat = rtXmlEncBool (pctxt, pvalue->booleanT
         , OSUTF8("booleanT"), nsPrefix);
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
/*  DataStoreType                                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_DataStoreType (OSCTXT* pctxt,
   DataStoreType *pvalue, ASN1TagType tagging)
{
   OSRTDListNode* pnode1;
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   pnode1 = pvalue->tail;
   while (0 != pnode1) {
      ll = asn1E_DataType (pctxt, ((DataType*)pnode1->data), ASN1EXPL);
      if (ll < 0) return LOG_RTERR (pctxt, ll);
      ll1 += ll;

      pnode1 = pnode1->prev;
   }
   ll1 = xe_tag_len (pctxt, TM_CTXT|TM_CONS|0, ll1);
   if (ll1 < 0) return LOG_RTERR (pctxt, ll1);

   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

int XmlEnc_DataStoreType (OSCTXT* pctxt, DataStoreType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   if (elemName != 0) {
      stat = rtXmlEncStartElement (pctxt, elemName, nsPrefix, TRUE);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   { const OSUTF8CHAR* savedPrefix = nsPrefix;
   nsPrefix = rtXmlNSGetPrefix (pctxt, OSUTF8(
      "http://www.sun.com/xml/datastore"));

   { OSRTDListNode* pnode = pvalue->head;
   while (0 != pnode) {
      stat = XmlEnc_DataType (pctxt, ((DataType*)pnode->data)
         , OSUTF8("data"), nsPrefix);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
      pnode = pnode->next;
   }}
   nsPrefix = savedPrefix;
   }

   stat = rtXmlEncEndElement (pctxt, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  DataStore                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_DataStore (OSCTXT* pctxt,
   DataStore *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DataStoreType (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_DataStore (OSCTXT* pctxt, DataStore* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = XmlEnc_DataStoreType (pctxt, pvalue, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

int XmlEnc_DataStore_PDU (OSCTXT* pctxt, DataStore* pvalue)
{
   int stat;
   const OSUTF8CHAR* nsPrefix = 0;

   rtXmlNSSetNamespace (pctxt, 0, OSUTF8("http://www.sun.com/xml/datastore"), 
      FALSE);

   nsPrefix = rtXmlNSGetPrefix (pctxt, 
      OSUTF8("http://www.sun.com/xml/datastore"));

   stat = rtXmlEncStartDocument (pctxt);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   stat = rtXmlEncStartElement (pctxt, OSUTF8("dataStore"), nsPrefix, FALSE);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   stat = rtXmlEncNSAttrs (pctxt);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   stat = rtXmlEncXSIAttrs (pctxt, FALSE);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   stat = XmlEnc_DataStore (pctxt, pvalue, 0, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   stat = rtXmlEncEndElement (pctxt, OSUTF8("dataStore"), nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return stat;
}
