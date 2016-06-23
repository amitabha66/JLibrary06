/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Soap-1-1.h"
#include "XSD.h"
#include "libxml/parser.h"
#include "rtxmlsrc/osrtxml.h"
#include "rtxsrc/rtxCommon.h"

int DOMTest_EncodingStyle_1 (OSCTXT* pctxt, EncodingStyle_1* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   const OSUTF8CHAR* pdata1 = 0;
   if (0 != pXmlNode->children) {
      pdata1 = pXmlNode->children->content;
   }
   else {
      pdata1 = (const OSUTF8CHAR*)"";
   }
   if (0 != pdata1)
      rtxDListAppend (pctxt, pvalue, (void*)pdata1);

   return 0;
}

int DOMTest_EncodingStyle (OSCTXT* pctxt, EncodingStyle* pvalue, 
   xmlAttrPtr pXmlNode, OSBOOL setChild)
{
   DOMTest_EncodingStyle_1 (pctxt, pvalue, (xmlNodePtr)pXmlNode, TRUE);

   return 0;
}

int DOMTest_Header (OSCTXT* pctxt, Header* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("any"))) {
            {
            const OSUTF8CHAR* pdata2 = 0;
            if (0 != pXmlNode->children) {
               OSUTF8CHAR* anyAttr = (OSUTF8CHAR*) rtxMemAlloc 
                  (pctxt, rtxUTF8LenBytes (pXmlNode->name) + 
                  rtxUTF8LenBytes (pXmlNode->children->content) + 4);
               strcpy ((char*)anyAttr, (const char*)pXmlNode->name);
               strcat ((char*)anyAttr, "='");
               strcat ((char*)anyAttr, 
                  (const char*)pXmlNode->children->content);
               strcat ((char*)anyAttr, "'");
               pdata2 = anyAttr;
            }
            if (0 != pdata2)
               rtxDListAppend (pctxt, &pvalue->attr, (void*)pdata2);
            }
         }
      }
   }
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         { OSXSDAny* pdata2;
         pdata2 = rtxMemAllocTypeZ (pctxt, OSXSDAny);

         if (pdata2 == NULL)
            return LOG_RTERR (pctxt, RTERR_NOMEM);

         if (0 != pXmlNode->children) {
            pdata2->t = OSXSDAny_xmlText;
            pdata2->u.xmlText = pXmlNode->children->content;
         }
         if (0 != pdata2)
            rtxDListAppend (pctxt, &pvalue->elem_list, (void*)pdata2);
         }
      }
   }

   return 0;
}

int DOMTest_Body (OSCTXT* pctxt, Body* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("any"))) {
            {
            const OSUTF8CHAR* pdata2 = 0;
            if (0 != pXmlNode->children) {
               OSUTF8CHAR* anyAttr = (OSUTF8CHAR*) rtxMemAlloc 
                  (pctxt, rtxUTF8LenBytes (pXmlNode->name) + 
                  rtxUTF8LenBytes (pXmlNode->children->content) + 4);
               strcpy ((char*)anyAttr, (const char*)pXmlNode->name);
               strcat ((char*)anyAttr, "='");
               strcat ((char*)anyAttr, 
                  (const char*)pXmlNode->children->content);
               strcat ((char*)anyAttr, "'");
               pdata2 = anyAttr;
            }
            if (0 != pdata2)
               rtxDListAppend (pctxt, &pvalue->attr, (void*)pdata2);
            }
         }
      }
   }
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         { OSXSDAny* pdata2;
         pdata2 = rtxMemAllocTypeZ (pctxt, OSXSDAny);

         if (pdata2 == NULL)
            return LOG_RTERR (pctxt, RTERR_NOMEM);

         if (0 != pXmlNode->children) {
            pdata2->t = OSXSDAny_xmlText;
            pdata2->u.xmlText = pXmlNode->children->content;
         }
         if (0 != pdata2)
            rtxDListAppend (pctxt, &pvalue->elem_list, (void*)pdata2);
         }
      }
   }

   return 0;
}

int DOMTest_Envelope (OSCTXT* pctxt, Envelope* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("encodingStyle"))) {
            pvalue->m.encodingStylePresent = 1;
            DOMTest_EncodingStyle (pctxt, &pvalue->encodingStyle, pXmlAttr, FALSE);
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("any"))) {
            {
            const OSUTF8CHAR* pdata2 = 0;
            if (0 != pXmlNode->children) {
               OSUTF8CHAR* anyAttr = (OSUTF8CHAR*) rtxMemAlloc 
                  (pctxt, rtxUTF8LenBytes (pXmlNode->name) + 
                  rtxUTF8LenBytes (pXmlNode->children->content) + 4);
               strcpy ((char*)anyAttr, (const char*)pXmlNode->name);
               strcat ((char*)anyAttr, "='");
               strcat ((char*)anyAttr, 
                  (const char*)pXmlNode->children->content);
               strcat ((char*)anyAttr, "'");
               pdata2 = anyAttr;
            }
            if (0 != pdata2)
               rtxDListAppend (pctxt, &pvalue->attr, (void*)pdata2);
            }
         }
      }
   }
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Header"))) {
            pvalue->m.headerPresent = 1;
            DOMTest_Header (pctxt, &pvalue->header, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Body"))) {
            DOMTest_Body (pctxt, &pvalue->body, pXmlNode, TRUE);
         }
         { OSXSDAny* pdata2;
         pdata2 = rtxMemAllocTypeZ (pctxt, OSXSDAny);

         if (pdata2 == NULL)
            return LOG_RTERR (pctxt, RTERR_NOMEM);

         if (0 != pXmlNode->children) {
            pdata2->t = OSXSDAny_xmlText;
            pdata2->u.xmlText = pXmlNode->children->content;
         }
         if (0 != pdata2)
            rtxDListAppend (pctxt, &pvalue->elem_list, (void*)pdata2);
         }
      }
   }

   return 0;
}

int DOMTest_Detail (OSCTXT* pctxt, Detail* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("any"))) {
            {
            const OSUTF8CHAR* pdata2 = 0;
            if (0 != pXmlNode->children) {
               OSUTF8CHAR* anyAttr = (OSUTF8CHAR*) rtxMemAlloc 
                  (pctxt, rtxUTF8LenBytes (pXmlNode->name) + 
                  rtxUTF8LenBytes (pXmlNode->children->content) + 4);
               strcpy ((char*)anyAttr, (const char*)pXmlNode->name);
               strcat ((char*)anyAttr, "='");
               strcat ((char*)anyAttr, 
                  (const char*)pXmlNode->children->content);
               strcat ((char*)anyAttr, "'");
               pdata2 = anyAttr;
            }
            if (0 != pdata2)
               rtxDListAppend (pctxt, &pvalue->attr, (void*)pdata2);
            }
         }
      }
   }
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         { OSXSDAny* pdata2;
         pdata2 = rtxMemAllocTypeZ (pctxt, OSXSDAny);

         if (pdata2 == NULL)
            return LOG_RTERR (pctxt, RTERR_NOMEM);

         if (0 != pXmlNode->children) {
            pdata2->t = OSXSDAny_xmlText;
            pdata2->u.xmlText = pXmlNode->children->content;
         }
         if (0 != pdata2)
            rtxDListAppend (pctxt, &pvalue->elem_list, (void*)pdata2);
         }
      }
   }

   return 0;
}

int DOMTest_Fault (OSCTXT* pctxt, Fault* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("faultcode"))) {
            DOMTest_XSD_QName (pctxt, &pvalue->faultcode, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("faultstring"))) {
            if (0 != pXmlNode->children) {
               pvalue->faultstring = pXmlNode->children->content;
            }
            else {
               pvalue->faultstring = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("faultactor"))) {
            pvalue->m.faultactorPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->faultactor = pXmlNode->children->content;
            }
            else {
               pvalue->faultactor = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("detail"))) {
            pvalue->m.detailPresent = 1;
            DOMTest_Detail (pctxt, &pvalue->detail, pXmlNode, TRUE);
         }
      }
   }

   return 0;
}
