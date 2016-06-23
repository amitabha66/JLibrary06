/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Weblog.h"
#include "libxml/parser.h"
#include "rtxmlsrc/osrtxml.h"
#include "rtxsrc/rtxCommon.h"

int DOMTest_Weblog_entry (OSCTXT* pctxt, Weblog_entry* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("host"))) {
            if (0 != pXmlNode->children) {
               pvalue->host = pXmlNode->children->content;
            }
            else {
               pvalue->host = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("referer"))) {
            if (0 != pXmlNode->children) {
               pvalue->referer = pXmlNode->children->content;
            }
            else {
               pvalue->referer = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("userAgent"))) {
            if (0 != pXmlNode->children) {
               pvalue->userAgent = pXmlNode->children->content;
            }
            else {
               pvalue->userAgent = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("dateTime"))) {
            if (0 != pXmlNode->children) {
               pvalue->dateTime = pXmlNode->children->content;
            }
            else {
               pvalue->dateTime = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("reqID"))) {
            if (0 != pXmlNode->children) {
               pvalue->reqID = atoi ((const char*)pXmlNode->children->content);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("reqType"))) {
            if (0 != pXmlNode->children) {
               pvalue->reqType = pXmlNode->children->content;
            }
            else {
               pvalue->reqType = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("resource"))) {
            if (0 != pXmlNode->children) {
               pvalue->resource = pXmlNode->children->content;
            }
            else {
               pvalue->resource = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("protocol"))) {
            if (0 != pXmlNode->children) {
               pvalue->protocol = pXmlNode->children->content;
            }
            else {
               pvalue->protocol = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("statusCode"))) {
            if (0 != pXmlNode->children) {
               pvalue->statusCode = atoi ((const char*)pXmlNode->children->content);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("byteCount"))) {
            if (0 != pXmlNode->children) {
               pvalue->byteCount = pXmlNode->children->content;
            }
            else {
               pvalue->byteCount = (const OSUTF8CHAR*)"";
            }
         }
      }
   }

   return 0;
}

int DOMTest_Weblog (OSCTXT* pctxt, Weblog* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   Weblog_entry* pdata1;
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("entry"))) {
            pdata1 = rtxMemAllocType (pctxt, Weblog_entry);

            if (pdata1 == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_Weblog_entry (pdata1);
            DOMTest_Weblog_entry (pctxt, pdata1, pXmlNode, TRUE);
            if (0 != pdata1)
               rtxDListAppend (pctxt, pvalue, (void*)pdata1);
         }
      }
   }

   return 0;
}

