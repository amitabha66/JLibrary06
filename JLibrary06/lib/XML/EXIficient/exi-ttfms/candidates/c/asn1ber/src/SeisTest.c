/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Seis.h"
#include "libxml/parser.h"
#include "rtxmlsrc/osrtxml.h"
#include "rtxsrc/rtxCommon.h"

int DOMTest_Headtype (OSCTXT* pctxt, Headtype* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("name"))) {
            if (0 != pXmlNode->children) {
               pvalue->name = pXmlNode->children->content;
            }
            else {
               pvalue->name = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("area"))) {
            if (0 != pXmlNode->children) {
               pvalue->area = pXmlNode->children->content;
            }
            else {
               pvalue->area = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("ntrace"))) {
            if (0 != pXmlNode->children) {
               pvalue->ntrace = atoi ((const char*)pXmlNode->children->content);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("nsamp"))) {
            if (0 != pXmlNode->children) {
               pvalue->nsamp = atoi ((const char*)pXmlNode->children->content);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("precision"))) {
            if (0 != pXmlNode->children) {
               pvalue->precision = atoi ((const char*)pXmlNode->children->content);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("zstart"))) {
            if (0 != pXmlNode->children) {
               rtxUTF8StrToDouble (pXmlNode->children->content, &pvalue->zstart);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("zinc"))) {
            if (0 != pXmlNode->children) {
               rtxUTF8StrToDouble (pXmlNode->children->content, &pvalue->zinc);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("num_xyzs_fields"))) {
            if (0 != pXmlNode->children) {
               pvalue->num_xyzs_fields = atoi ((const char*)pXmlNode->children->content);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("xyzs_field_names"))) {
            if (0 != pXmlNode->children) {
               pvalue->xyzs_field_names = pXmlNode->children->content;
            }
            else {
               pvalue->xyzs_field_names = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("xyzs_field_precisions"))) {
            if (0 != pXmlNode->children) {
               pvalue->xyzs_field_precisions = pXmlNode->children->content;
            }
            else {
               pvalue->xyzs_field_precisions = (const OSUTF8CHAR*)"";
            }
         }
      }
   }

   return 0;
}

int DOMTest_Xcrdtype (OSCTXT* pctxt, Xcrdtype* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   OSRTDList tmplist;
   OSREAL* pdata1 = rtxMemAllocTypeZ (pctxt, OSREAL);
   if (0 != pXmlNode->children) {
      rtxUTF8StrToDouble (pXmlNode->children->content, pdata1);
   }
   if (0 != pdata1)
      rtxDListAppend (pctxt, &tmplist, (void*)pdata1);

   /* Convert list to array */
   { OSUINT32 i = 0;
   OSRTDListNode* pnode = tmplist.head;

   pvalue->n = tmplist.count;
   pvalue->elem =
      rtxMemAllocArray (pctxt, tmplist.count, OSREAL);
   while (0 != pnode) {
      pdata1 = (OSREAL*)pnode->data;
      pvalue->elem[i++] = *pdata1;
      pnode = pnode->next;
   }}
   rtxDListFreeAll (pctxt, &tmplist);

   return 0;
}

int DOMTest_Seisdata (OSCTXT* pctxt, Seisdata* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("head"))) {
            DOMTest_Headtype (pctxt, &pvalue->head, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("xcrd"))) {
            DOMTest_Xcrdtype (pctxt, &pvalue->xcrd, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("ycrd"))) {
            DOMTest_Xcrdtype (pctxt, &pvalue->ycrd, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("zval"))) {
            DOMTest_Xcrdtype (pctxt, &pvalue->zval, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("cdp"))) {
            DOMTest_Xcrdtype (pctxt, &pvalue->cdp, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("data"))) {
            DOMTest_Xcrdtype (pctxt, &pvalue->data, pXmlNode, TRUE);
         }
      }
   }

   return 0;
}

