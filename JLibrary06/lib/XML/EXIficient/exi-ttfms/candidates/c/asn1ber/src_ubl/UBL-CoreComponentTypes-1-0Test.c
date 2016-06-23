/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#include "asn1intl.h"
#include "UBL-CoreComponentTypes-1-0.h"
#include "libxml/parser.h"
#include "rtxmlsrc/osrtxml.h"
#include "rtxsrc/rtxCommon.h"

void asn1DOMTest_AmountType (OSCTXT* pctxt, AmountType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("amountCurrencyCodeListVersionID"))) {
            pvalue->m.amountCurrencyCodeListVersionIDPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->amountCurrencyCodeListVersionID = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("amountCurrencyID"))) {
            pvalue->m.amountCurrencyIDPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->amountCurrencyID = pXmlAttr->children->content;
            }
         }
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      pvalue->base = atof (pXmlNode->children->content);
   }
}

void asn1DOMTest_BinaryObjectType (OSCTXT* pctxt, BinaryObjectType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("URI"))) {
            pvalue->m.uRIPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->uRI = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("characterSetCode"))) {
            pvalue->m.characterSetCodePresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->characterSetCode = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("encodingCode"))) {
            pvalue->m.encodingCodePresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->encodingCode = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("filename"))) {
            pvalue->m.filenamePresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->filename = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("format"))) {
            pvalue->m.formatPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->format = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("mimeCode"))) {
            pvalue->m.mimeCodePresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->mimeCode = pXmlAttr->children->content;
            }
         }
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      OSUTF8CHAR* pcontent = pXmlNode->children->content;
      rtxInitContextBuffer (pctxt, pcontent, rtxUTF8LenBytes(pcontent));
      rtXmlDecDynBase64Str (pctxt, &pvalue->base);
   }
}

void asn1DOMTest_CodeType (OSCTXT* pctxt, CodeType* pvalue, 
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
      pvalue->base = pXmlNode->children->content;
   }
}

void asn1DOMTest_IdentifierType (OSCTXT* pctxt, IdentifierType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("identificationSchemeAgencyID"))) {
            pvalue->m.identificationSchemeAgencyIDPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->identificationSchemeAgencyID = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("identificationSchemeAgencyName"))) {
            pvalue->m.identificationSchemeAgencyNamePresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->identificationSchemeAgencyName = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("identificationSchemeDataURI"))) {
            pvalue->m.identificationSchemeDataURIPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->identificationSchemeDataURI = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("identificationSchemeID"))) {
            pvalue->m.identificationSchemeIDPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->identificationSchemeID = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("identificationSchemeName"))) {
            pvalue->m.identificationSchemeNamePresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->identificationSchemeName = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("identificationSchemeURI"))) {
            pvalue->m.identificationSchemeURIPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->identificationSchemeURI = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("identificationSchemeVersionID"))) {
            pvalue->m.identificationSchemeVersionIDPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->identificationSchemeVersionID = pXmlAttr->children->content;
            }
         }
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      pvalue->base = pXmlNode->children->content;
   }
}

void asn1DOMTest_MeasureType (OSCTXT* pctxt, MeasureType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("measureUnitCode"))) {
            pvalue->m.measureUnitCodePresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->measureUnitCode = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("measureUnitCodeListVersionID"))) {
            pvalue->m.measureUnitCodeListVersionIDPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->measureUnitCodeListVersionID = pXmlAttr->children->content;
            }
         }
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      pvalue->base = atof (pXmlNode->children->content);
   }
}

void asn1DOMTest_QuantityType (OSCTXT* pctxt, QuantityType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("quantityUnitCode"))) {
            pvalue->m.quantityUnitCodePresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->quantityUnitCode = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("quantityUnitCodeListAgencyID"))) {
            pvalue->m.quantityUnitCodeListAgencyIDPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->quantityUnitCodeListAgencyID = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("quantityUnitCodeListAgencyName"))) {
            pvalue->m.quantityUnitCodeListAgencyNamePresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->quantityUnitCodeListAgencyName = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("quantityUnitCodeListID"))) {
            pvalue->m.quantityUnitCodeListIDPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->quantityUnitCodeListID = pXmlAttr->children->content;
            }
         }
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      pvalue->base = atof (pXmlNode->children->content);
   }
}

void asn1DOMTest_TextType (OSCTXT* pctxt, TextType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("languageID"))) {
            pvalue->m.languageIDPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->languageID = pXmlAttr->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("languageLocaleID"))) {
            pvalue->m.languageLocaleIDPresent = 1;
            if (0 != pXmlAttr->children) {
               pvalue->languageLocaleID = pXmlAttr->children->content;
            }
         }
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      pvalue->base = pXmlNode->children->content;
   }
}

