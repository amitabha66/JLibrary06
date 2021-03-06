/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Urn-GoogleSearch.h"
#include "Soap-1-1.h"
#include "XSD.h"
#include "libxml/parser.h"
#include "rtxmlsrc/osrtxml.h"
#include "rtxsrc/rtxCommon.h"

int DOMTest_DirectoryCategory (OSCTXT* pctxt, DirectoryCategory* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   pvalue->_order.n = 0;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("fullViewableName"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 0;
            if (0 != pXmlNode->children) {
               pvalue->fullViewableName = pXmlNode->children->content;
            }
            else {
               pvalue->fullViewableName = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("specialEncoding"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 1;
            if (0 != pXmlNode->children) {
               pvalue->specialEncoding = pXmlNode->children->content;
            }
            else {
               pvalue->specialEncoding = (const OSUTF8CHAR*)"";
            }
         }
      }
   }

   return 0;
}

int DOMTest_ResultElement (OSCTXT* pctxt, ResultElement* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   pvalue->_order.n = 0;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("summary"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 0;
            if (0 != pXmlNode->children) {
               pvalue->summary = pXmlNode->children->content;
            }
            else {
               pvalue->summary = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("URL"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 1;
            if (0 != pXmlNode->children) {
               pvalue->uRL = pXmlNode->children->content;
            }
            else {
               pvalue->uRL = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("snippet"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 2;
            if (0 != pXmlNode->children) {
               pvalue->snippet = pXmlNode->children->content;
            }
            else {
               pvalue->snippet = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("title"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 3;
            if (0 != pXmlNode->children) {
               pvalue->title = pXmlNode->children->content;
            }
            else {
               pvalue->title = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("cachedSize"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 4;
            if (0 != pXmlNode->children) {
               pvalue->cachedSize = pXmlNode->children->content;
            }
            else {
               pvalue->cachedSize = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("relatedInformationPresent"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 5;
            if (0 != pXmlNode->children) {
               OSUTF8CHAR* pcontent = pXmlNode->children->content;
               rtxInitContextBuffer (pctxt, pcontent, rtxUTF8LenBytes(pcontent));
               rtXmlDecBool (pctxt, &pvalue->relatedInformationPresent);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("hostName"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 6;
            if (0 != pXmlNode->children) {
               pvalue->hostName = pXmlNode->children->content;
            }
            else {
               pvalue->hostName = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("directoryCategory"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 7;
            DOMTest_DirectoryCategory (pctxt, &pvalue->directoryCategory, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("directoryTitle"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 8;
            if (0 != pXmlNode->children) {
               pvalue->directoryTitle = pXmlNode->children->content;
            }
            else {
               pvalue->directoryTitle = (const OSUTF8CHAR*)"";
            }
         }
      }
   }

   return 0;
}

int DOMTest_ResultElementArray (OSCTXT* pctxt, ResultElementArray* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   ResultElement* pdata1;
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("item"))) {
            pdata1 = rtxMemAllocType (pctxt, ResultElement);

            if (pdata1 == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_ResultElement (pdata1);
            DOMTest_ResultElement (pctxt, pdata1, pXmlNode, TRUE);
            if (0 != pdata1)
               rtxDListAppend (pctxt, pvalue, (void*)pdata1);
         }
      }
   }

   return 0;
}

int DOMTest_DirectoryCategoryArray (OSCTXT* pctxt, 
   DirectoryCategoryArray* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   DirectoryCategory* pdata1;
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("item"))) {
            pdata1 = rtxMemAllocType (pctxt, DirectoryCategory);

            if (pdata1 == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_DirectoryCategory (pdata1);
            DOMTest_DirectoryCategory (pctxt, pdata1, pXmlNode, TRUE);
            if (0 != pdata1)
               rtxDListAppend (pctxt, pvalue, (void*)pdata1);
         }
      }
   }

   return 0;
}

int DOMTest_GoogleSearchResult (OSCTXT* pctxt, GoogleSearchResult* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   pvalue->_order.n = 0;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("documentFiltering"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 0;
            if (0 != pXmlNode->children) {
               OSUTF8CHAR* pcontent = pXmlNode->children->content;
               rtxInitContextBuffer (pctxt, pcontent, rtxUTF8LenBytes(pcontent));
               rtXmlDecBool (pctxt, &pvalue->documentFiltering);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("searchComments"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 1;
            if (0 != pXmlNode->children) {
               pvalue->searchComments = pXmlNode->children->content;
            }
            else {
               pvalue->searchComments = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("estimatedTotalResultsCount"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 2;
            if (0 != pXmlNode->children) {
               pvalue->estimatedTotalResultsCount = atoi ((const char*)pXmlNode->children->content);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("estimateIsExact"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 3;
            if (0 != pXmlNode->children) {
               OSUTF8CHAR* pcontent = pXmlNode->children->content;
               rtxInitContextBuffer (pctxt, pcontent, rtxUTF8LenBytes(pcontent));
               rtXmlDecBool (pctxt, &pvalue->estimateIsExact);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("resultElements"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 4;
            DOMTest_ResultElementArray (pctxt, &pvalue->resultElements, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("searchQuery"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 5;
            if (0 != pXmlNode->children) {
               pvalue->searchQuery = pXmlNode->children->content;
            }
            else {
               pvalue->searchQuery = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("startIndex"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 6;
            if (0 != pXmlNode->children) {
               pvalue->startIndex = atoi ((const char*)pXmlNode->children->content);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("endIndex"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 7;
            if (0 != pXmlNode->children) {
               pvalue->endIndex = atoi ((const char*)pXmlNode->children->content);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("searchTips"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 8;
            if (0 != pXmlNode->children) {
               pvalue->searchTips = pXmlNode->children->content;
            }
            else {
               pvalue->searchTips = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("directoryCategories"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 9;
            DOMTest_DirectoryCategoryArray (pctxt, &pvalue->directoryCategories, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("searchTime"))) {
            pvalue->_order.elem[pvalue->_order.n++] = 10;
            if (0 != pXmlNode->children) {
               rtxUTF8StrToDouble (pXmlNode->children->content, &pvalue->searchTime);
            }
         }
      }
   }

   return 0;
}

int DOMTest_DoGoogleSearchResponse (OSCTXT* pctxt, 
   DoGoogleSearchResponse* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("encodingStyle"))) {
            pvalue->m.encodingStylePresent = 1;
            DOMTest_EncodingStyle (pctxt, &pvalue->encodingStyle, pXmlAttr, FALSE);
         }
      }
   }
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("return"))) {
            DOMTest_GoogleSearchResult (pctxt, &pvalue->return_, pXmlNode, TRUE);
         }
      }
   }

   return 0;
}

