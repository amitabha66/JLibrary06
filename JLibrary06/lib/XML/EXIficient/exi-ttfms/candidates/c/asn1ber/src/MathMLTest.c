/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "MathML.h"
#include "Odf.h"
#include "Ns8.h"
#include "Ns12.h"
#include "Xlink.h"
#include "Ns3.h"
#include "Ns13.h"
#include "Ns6.h"
#include "Ns10.h"
#include "Ns7.h"
#include "Ns15.h"
#include "Elements.h"
#include "Ns16.h"
#include "Ns4.h"
#include "Xforms.h"
#include "Ns2.h"
#include "Ns14.h"
#include "Ns5.h"
#include "Ns1.h"
#include "Ns9.h"
#include "Ns11.h"
#include "libxml/parser.h"
#include "rtxmlsrc/osrtxml.h"
#include "rtxsrc/rtxCommon.h"

int DOMTest_Math (OSCTXT* pctxt, Math* pvalue, 
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
         { Odf_Element446* pdata2;
         pdata2 = rtxMemAllocTypeZ (pctxt, Odf_Element446);

         if (pdata2 == NULL)
            return LOG_RTERR (pctxt, RTERR_NOMEM);

         if (0 != pXmlNode->children) {
            pdata2->t = OSXSDAny_xmlText;
            pdata2->u.xmlText = pXmlNode->children->content;
         }
         if (0 != pdata2)
            rtxDListAppend (pctxt, &pvalue->element446_list, (void*)pdata2);
         }
      }
   }

   return 0;
}

