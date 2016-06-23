/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Ns6.h"
#include "Xlink.h"
#include "libxml/parser.h"
#include "rtxmlsrc/osrtxml.h"
#include "rtxsrc/rtxCommon.h"

int DOMTest_Ns6_Event_listener (OSCTXT* pctxt, Ns6_Event_listener* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("actuate"))) {
            pvalue->m.actuatePresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               Ns6_Event_listener_actuate_ToEnum (pctxt, ((xmlNodePtr)pXmlAttr)->children->content, &pvalue->actuate);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("href"))) {
            pvalue->m.hrefPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->href = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->href = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("type"))) {
            pvalue->m.typePresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               Xlink_Type_ToEnum (pctxt, ((xmlNodePtr)pXmlAttr)->children->content, &pvalue->type);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("event-name"))) {
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->event_name = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->event_name = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("language"))) {
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->language = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->language = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("macro-name"))) {
            pvalue->m.macro_namePresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->macro_name = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->macro_name = (const OSUTF8CHAR*)"";
            }
         }
      }
   }
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
      }
   }

   return 0;
}

