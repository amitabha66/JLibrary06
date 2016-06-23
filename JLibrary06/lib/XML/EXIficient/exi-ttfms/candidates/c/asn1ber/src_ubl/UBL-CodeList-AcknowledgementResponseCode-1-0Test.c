/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#include "asn1intl.h"
#include "UBL-CodeList-AcknowledgementResponseCode-1-0.h"
#include "libxml/parser.h"
#include "rtxmlsrc/osrtxml.h"
#include "rtxsrc/rtxCommon.h"

void asn1DOMTest_AcknowledgementResponseCodeType (OSCTXT* pctxt, 
   AcknowledgementResponseCodeType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("codeListAgencyID"))) {
            pvalue->m.codeListAgencyIDPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->codeListAgencyID = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("codeListAgencyName"))) {
            pvalue->m.codeListAgencyNamePresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->codeListAgencyName = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("codeListID"))) {
            pvalue->m.codeListIDPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->codeListID = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("codeListName"))) {
            pvalue->m.codeListNamePresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->codeListName = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("codeListSchemeURI"))) {
            pvalue->m.codeListSchemeURIPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->codeListSchemeURI = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("codeListURI"))) {
            pvalue->m.codeListURIPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->codeListURI = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("codeListVersionID"))) {
            pvalue->m.codeListVersionIDPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->codeListVersionID = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("languageID"))) {
            pvalue->m.languageIDPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->languageID = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("name"))) {
            pvalue->m.namePresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->name = pXmlAttr->children->content;
            }
         }
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      AcknowledgementResponseCodeContentType_ToEnum (pXmlNode->children->content, &pvalue->base);
   }
}

