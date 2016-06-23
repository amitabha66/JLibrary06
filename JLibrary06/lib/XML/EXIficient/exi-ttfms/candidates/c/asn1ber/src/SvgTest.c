/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Svg.h"
#include "libxml/parser.h"
#include "rtxmlsrc/osrtxml.h"
#include "rtxsrc/rtxCommon.h"

int DOMTest_Svg (OSCTXT* pctxt, Svg* pvalue, 
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
