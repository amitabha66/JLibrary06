/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Urn-tva-metadata-2005.h"
#include "Urn-mpeg-mpeg7-schema-2001.h"
#include "libxml/parser.h"
#include "rtxmlsrc/osrtxml.h"
#include "rtxsrc/rtxCommon.h"

int DOMTest_CSAliasType (OSCTXT* pctxt, CSAliasType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("alias"))) {
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->alias = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->alias = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("href"))) {
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->href = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->href = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("id"))) {
            pvalue->m.idPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->id = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->id = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("fragmentId"))) {
            pvalue->m.fragmentIdPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->fragmentId = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->fragmentId = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("fragmentVersion"))) {
            pvalue->m.fragmentVersionPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->fragmentVersion = atoi ((const char*)((xmlNodePtr)pXmlAttr)->children->content);
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

int DOMTest_Urn_tva_metadata_2005_ClassificationSchemeType (OSCTXT* pctxt, 
   Urn_tva_metadata_2005_ClassificationSchemeType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("domain"))) {
            pvalue->m.domainPresent = 1;
            {
            const OSUTF8CHAR* pdata2 = 0;
            if (0 != pXmlNode->children) {
               pdata2 = pXmlNode->children->content;
            }
            else {
               pdata2 = (const OSUTF8CHAR*)"";
            }
            if (0 != pdata2)
               rtxDListAppend (pctxt, &pvalue->domain, (void*)pdata2);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("id"))) {
            pvalue->m.idPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->id = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->id = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("mediaTimeBase"))) {
            pvalue->m.mediaTimeBasePresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->mediaTimeBase = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->mediaTimeBase = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("mediaTimeUnit"))) {
            pvalue->m.mediaTimeUnitPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->mediaTimeUnit = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->mediaTimeUnit = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("timeBase"))) {
            pvalue->m.timeBasePresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->timeBase = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->timeBase = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("timeUnit"))) {
            pvalue->m.timeUnitPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->timeUnit = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->timeUnit = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("uri"))) {
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->uri = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->uri = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("fragmentId"))) {
            pvalue->m.fragmentIdPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->fragmentId = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->fragmentId = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("fragmentVersion"))) {
            pvalue->m.fragmentVersionPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->fragmentVersion = atoi ((const char*)((xmlNodePtr)pXmlAttr)->children->content);
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

int DOMTest_TermNameType (OSCTXT* pctxt, TermNameType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("lang"))) {
            pvalue->m.langPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->lang = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->lang = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("phoneticAlphabet"))) {
            pvalue->m.phoneticAlphabetPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               PhoneticAlphabetType_ToEnum (pctxt, ((xmlNodePtr)pXmlAttr)->children->content, &pvalue->phoneticAlphabet);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("phoneticTranscription"))) {
            pvalue->m.phoneticTranscriptionPresent = 1;
            {
            const OSUTF8CHAR* pdata2 = 0;
            if (0 != pXmlNode->children) {
               pdata2 = pXmlNode->children->content;
            }
            else {
               pdata2 = (const OSUTF8CHAR*)"";
            }
            if (0 != pdata2)
               rtxDListAppend (pctxt, &pvalue->phoneticTranscription, (void*)pdata2);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("preferred"))) {
            pvalue->m.preferredPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               OSUTF8CHAR* pcontent = ((xmlNodePtr)pXmlAttr)->children->content;
               rtxInitContextBuffer (pctxt, pcontent, rtxUTF8LenBytes(pcontent));
               rtXmlDecBool (pctxt, &pvalue->preferred);
            }
         }
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      pvalue->base = pXmlNode->children->content;
   }
   else {
      pvalue->base = (const OSUTF8CHAR*)"";
   }

   return 0;
}

int DOMTest_ControlledTermType (OSCTXT* pctxt, ControlledTermType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("href"))) {
            pvalue->href = rtxMemAllocType (pctxt, TermReferenceType);

            if (pvalue->href == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_TermReferenceType ((TermReferenceType*)pvalue->href);
            DOMTest_TermReferenceType (pctxt, (TermReferenceType*)pvalue->href, ((xmlNodePtr)pXmlAttr), FALSE);
         }
      }
   }
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Name"))) {
            pvalue->m.namePresent = 1;
            DOMTest_TermNameType (pctxt, &pvalue->name, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Definition"))) {
            pvalue->m.definitionPresent = 1;
            pvalue->definition = rtxMemAllocType (pctxt, TextualType);

            if (pvalue->definition == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_TextualType ((TextualType*)pvalue->definition);
            DOMTest_TextualType (pctxt, (TextualType*)pvalue->definition, pXmlNode, TRUE);
         }
      }
   }

   return 0;
}

int DOMTest_ClassificationSchemeTableType (OSCTXT* pctxt, 
   ClassificationSchemeTableType* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("CSAlias"))) {
            { CSAliasType* pdata2;
            pdata2 = rtxMemAllocType (pctxt, CSAliasType);

            if (pdata2 == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_CSAliasType (pdata2);
            DOMTest_CSAliasType (pctxt, pdata2, pXmlNode, FALSE);
            if (0 != pdata2)
               rtxDListAppend (pctxt, &pvalue->cSAlias_list, (void*)pdata2);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("ClassificationScheme"))) {
            { ClassificationSchemeType* pdata2;
            pdata2 = rtxMemAllocType (pctxt, ClassificationSchemeType);

            if (pdata2 == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_ClassificationSchemeType ((ClassificationSchemeType*)pdata2);
            DOMTest_ClassificationSchemeType (pctxt, (ClassificationSchemeType*)pdata2, pXmlNode, FALSE);
            if (0 != pdata2)
               rtxDListAppend (pctxt, &pvalue->classificationScheme_list, (void*)pdata2);
            }
         }
      }
   }

   return 0;
}

int DOMTest_TVAAgentType_element_personNameIDRef (OSCTXT* pctxt, 
   TVAAgentType_element_personNameIDRef* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("ref"))) {
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->ref = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->ref = (const OSUTF8CHAR*)"";
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

int DOMTest_TVAAgentType_element_organizationNameIDRef (OSCTXT* pctxt, 
   TVAAgentType_element_organizationNameIDRef* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("ref"))) {
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->ref = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->ref = (const OSUTF8CHAR*)"";
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

int DOMTest_TVAAgentType_element (OSCTXT* pctxt, TVAAgentType_element* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PersonName"))) {
            pvalue->t = 1;
            pvalue->u.personName = rtxMemAllocType (pctxt, PersonNameType);

            if (pvalue->u.personName == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_PersonNameType ((PersonNameType*)pvalue->u.personName);
            DOMTest_PersonNameType (pctxt, (PersonNameType*)pvalue->u.personName, pXmlNode, TRUE);
            break;
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PersonNameIDRef"))) {
            pvalue->t = 2;
            pvalue->u.personNameIDRef
                = rtxMemAllocType (pctxt, TVAAgentType_element_personNameIDRef);

            if (pvalue->u.personNameIDRef == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_TVAAgentType_element_personNameIDRef (pvalue->u.personNameIDRef);
            DOMTest_TVAAgentType_element_personNameIDRef (pctxt, pvalue->u.personNameIDRef, pXmlNode, TRUE);
            break;
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("OrganizationName"))) {
            pvalue->t = 3;
            pvalue->u.organizationName = rtxMemAllocType (pctxt, TextualType);

            if (pvalue->u.organizationName == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_TextualType ((TextualType*)pvalue->u.organizationName);
            DOMTest_TextualType (pctxt, (TextualType*)pvalue->u.organizationName, pXmlNode, TRUE);
            break;
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("OrganizationNameIDRef"))) {
            pvalue->t = 4;
            pvalue->u.organizationNameIDRef
                = rtxMemAllocType (pctxt, TVAAgentType_element_organizationNameIDRef);

            if (pvalue->u.organizationNameIDRef == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_TVAAgentType_element_organizationNameIDRef (pvalue->u.organizationNameIDRef);
            DOMTest_TVAAgentType_element_organizationNameIDRef (pctxt, pvalue->u.organizationNameIDRef, pXmlNode, TRUE);
            break;
         }
         else {
            LOG_RTERR1 (pctxt, RTERR_INVOPT,
               rtxErrAddStrParm (pctxt, (const char*)pXmlNode->name));
         }
      }
   }

   return 0;
}

int DOMTest_TVAAgentType (OSCTXT* pctxt, TVAAgentType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   TVAAgentType_element* pdata1 = rtxMemAllocTypeZ (pctxt, TVAAgentType_element);
   DOMTest_TVAAgentType_element (pctxt, pdata1, pXmlNode, setChild);
   if (0 != pdata1)
      rtxDListAppend (pctxt, pvalue, (void*)pdata1);

   return 0;
}

int DOMTest_CreditsItemType_element_personNameIDRef (OSCTXT* pctxt, 
   CreditsItemType_element_personNameIDRef* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("ref"))) {
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->ref = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->ref = (const OSUTF8CHAR*)"";
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

int DOMTest_CreditsItemType_element_organizationNameIDRef (OSCTXT* pctxt, 
   CreditsItemType_element_organizationNameIDRef* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("ref"))) {
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->ref = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->ref = (const OSUTF8CHAR*)"";
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

int DOMTest_CreditsItemType_element (OSCTXT* pctxt, 
   CreditsItemType_element* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PersonName"))) {
            pvalue->t = 1;
            pvalue->u.personName = rtxMemAllocType (pctxt, PersonNameType);

            if (pvalue->u.personName == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_PersonNameType ((PersonNameType*)pvalue->u.personName);
            DOMTest_PersonNameType (pctxt, (PersonNameType*)pvalue->u.personName, pXmlNode, TRUE);
            break;
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PersonNameIDRef"))) {
            pvalue->t = 2;
            pvalue->u.personNameIDRef
                = rtxMemAllocType (pctxt, CreditsItemType_element_personNameIDRef);

            if (pvalue->u.personNameIDRef == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_CreditsItemType_element_personNameIDRef (pvalue->u.personNameIDRef);
            DOMTest_CreditsItemType_element_personNameIDRef (pctxt, pvalue->u.personNameIDRef, pXmlNode, TRUE);
            break;
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("OrganizationName"))) {
            pvalue->t = 3;
            pvalue->u.organizationName = rtxMemAllocType (pctxt, TextualType);

            if (pvalue->u.organizationName == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_TextualType ((TextualType*)pvalue->u.organizationName);
            DOMTest_TextualType (pctxt, (TextualType*)pvalue->u.organizationName, pXmlNode, TRUE);
            break;
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("OrganizationNameIDRef"))) {
            pvalue->t = 4;
            pvalue->u.organizationNameIDRef
                = rtxMemAllocType (pctxt, CreditsItemType_element_organizationNameIDRef);

            if (pvalue->u.organizationNameIDRef == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_CreditsItemType_element_organizationNameIDRef (pvalue->u.organizationNameIDRef);
            DOMTest_CreditsItemType_element_organizationNameIDRef (pctxt, pvalue->u.organizationNameIDRef, pXmlNode, TRUE);
            break;
         }
         else {
            LOG_RTERR1 (pctxt, RTERR_INVOPT,
               rtxErrAddStrParm (pctxt, (const char*)pXmlNode->name));
         }
      }
   }

   return 0;
}

int DOMTest_CreditsItemType (OSCTXT* pctxt, CreditsItemType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("role"))) {
            pvalue->role = rtxMemAllocType (pctxt, TermReferenceType);

            if (pvalue->role == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_TermReferenceType ((TermReferenceType*)pvalue->role);
            DOMTest_TermReferenceType (pctxt, (TermReferenceType*)pvalue->role, ((xmlNodePtr)pXmlAttr), FALSE);
         }
      }
   }
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PersonName")) ||
         rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PersonNameIDRef")) ||
         rtxUTF8StrEqual (pXmlNode->name, OSUTF8("OrganizationName")) ||
         rtxUTF8StrEqual (pXmlNode->name, OSUTF8("OrganizationNameIDRef"))) {
            { CreditsItemType_element* pdata2;
            pdata2 = rtxMemAllocType (pctxt, CreditsItemType_element);

            if (pdata2 == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_CreditsItemType_element (pdata2);
            DOMTest_CreditsItemType_element (pctxt, pdata2, pXmlNode, FALSE);
            if (0 != pdata2)
               rtxDListAppend (pctxt, &pvalue->choice_list, (void*)pdata2);
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Character"))) {
            { PersonNameType* pdata2;
            pdata2 = rtxMemAllocType (pctxt, PersonNameType);

            if (pdata2 == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_PersonNameType ((PersonNameType*)pdata2);
            DOMTest_PersonNameType (pctxt, (PersonNameType*)pdata2, pXmlNode, FALSE);
            if (0 != pdata2)
               rtxDListAppend (pctxt, &pvalue->character_list, (void*)pdata2);
            }
         }
      }
   }

   return 0;
}

int DOMTest_CreditsListType (OSCTXT* pctxt, CreditsListType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   CreditsItemType* pdata1;
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("CreditsItem"))) {
            pdata1 = rtxMemAllocType (pctxt, CreditsItemType);

            if (pdata1 == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_CreditsItemType (pdata1);
            DOMTest_CreditsItemType (pctxt, pdata1, pXmlNode, TRUE);
            if (0 != pdata1)
               rtxDListAppend (pctxt, pvalue, (void*)pdata1);
         }
      }
   }

   return 0;
}

int DOMTest_FlagType (OSCTXT* pctxt, FlagType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("value"))) {
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               OSUTF8CHAR* pcontent = ((xmlNodePtr)pXmlAttr)->children->content;
               rtxInitContextBuffer (pctxt, pcontent, rtxUTF8LenBytes(pcontent));
               rtXmlDecBool (pctxt, &pvalue->value);
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

int DOMTest_ServiceInformationNameType (OSCTXT* pctxt, 
   ServiceInformationNameType* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("lang"))) {
            pvalue->m.langPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->lang = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->lang = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("phoneticAlphabet"))) {
            pvalue->m.phoneticAlphabetPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               PhoneticAlphabetType_ToEnum (pctxt, ((xmlNodePtr)pXmlAttr)->children->content, &pvalue->phoneticAlphabet);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("phoneticTranscription"))) {
            pvalue->m.phoneticTranscriptionPresent = 1;
            {
            const OSUTF8CHAR* pdata2 = 0;
            if (0 != pXmlNode->children) {
               pdata2 = pXmlNode->children->content;
            }
            else {
               pdata2 = (const OSUTF8CHAR*)"";
            }
            if (0 != pdata2)
               rtxDListAppend (pctxt, &pvalue->phoneticTranscription, (void*)pdata2);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("length"))) {
            pvalue->m.lengthPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               ServiceInformationNameLengthType_ToEnum (pctxt, ((xmlNodePtr)pXmlAttr)->children->content, &pvalue->length);
            }
         }
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      pvalue->base = pXmlNode->children->content;
   }
   else {
      pvalue->base = (const OSUTF8CHAR*)"";
   }

   return 0;
}

int DOMTest_SynopsisType (OSCTXT* pctxt, SynopsisType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("lang"))) {
            pvalue->m.langPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->lang = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->lang = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("phoneticAlphabet"))) {
            pvalue->m.phoneticAlphabetPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               PhoneticAlphabetType_ToEnum (pctxt, ((xmlNodePtr)pXmlAttr)->children->content, &pvalue->phoneticAlphabet);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("phoneticTranscription"))) {
            pvalue->m.phoneticTranscriptionPresent = 1;
            {
            const OSUTF8CHAR* pdata2 = 0;
            if (0 != pXmlNode->children) {
               pdata2 = pXmlNode->children->content;
            }
            else {
               pdata2 = (const OSUTF8CHAR*)"";
            }
            if (0 != pdata2)
               rtxDListAppend (pctxt, &pvalue->phoneticTranscription, (void*)pdata2);
            }
         }
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      pvalue->base = pXmlNode->children->content;
   }
   else {
      pvalue->base = (const OSUTF8CHAR*)"";
   }

   return 0;
}

int DOMTest_GenreType (OSCTXT* pctxt, GenreType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("href"))) {
            pvalue->href = rtxMemAllocType (pctxt, TermReferenceType);

            if (pvalue->href == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_TermReferenceType ((TermReferenceType*)pvalue->href);
            DOMTest_TermReferenceType (pctxt, (TermReferenceType*)pvalue->href, ((xmlNodePtr)pXmlAttr), FALSE);
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("type"))) {
            pvalue->m.typePresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               GenreType_type_ToEnum (pctxt, ((xmlNodePtr)pXmlAttr)->children->content, &pvalue->type);
            }
         }
      }
   }
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Name"))) {
            pvalue->m.namePresent = 1;
            DOMTest_TermNameType (pctxt, &pvalue->name, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Definition"))) {
            pvalue->m.definitionPresent = 1;
            pvalue->definition = rtxMemAllocType (pctxt, TextualType);

            if (pvalue->definition == NULL)
               return LOG_RTERR (pctxt, RTERR_NOMEM);

            asn1Init_TextualType ((TextualType*)pvalue->definition);
            DOMTest_TextualType (pctxt, (TextualType*)pvalue->definition, pXmlNode, TRUE);
         }
      }
   }

   return 0;
}

int DOMTest_KeywordType (OSCTXT* pctxt, KeywordType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("lang"))) {
            pvalue->m.langPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->lang = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->lang = (const OSUTF8CHAR*)"";
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("phoneticAlphabet"))) {
            pvalue->m.phoneticAlphabetPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               PhoneticAlphabetType_ToEnum (pctxt, ((xmlNodePtr)pXmlAttr)->children->content, &pvalue->phoneticAlphabet);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("phoneticTranscription"))) {
            pvalue->m.phoneticTranscriptionPresent = 1;
            {
            const OSUTF8CHAR* pdata2 = 0;
            if (0 != pXmlNode->children) {
               pdata2 = pXmlNode->children->content;
            }
            else {
               pdata2 = (const OSUTF8CHAR*)"";
            }
            if (0 != pdata2)
               rtxDListAppend (pctxt, &pvalue->phoneticTranscription, (void*)pdata2);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("type"))) {
            pvalue->m.typePresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               KeywordType_type_ToEnum (pctxt, ((xmlNodePtr)pXmlAttr)->children->content, &pvalue->type);
            }
         }
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      pvalue->base = pXmlNode->children->content;
   }
   else {
      pvalue->base = (const OSUTF8CHAR*)"";
   }

   return 0;
}

int DOMTest_CaptionLanguageType (OSCTXT* pctxt, CaptionLanguageType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("closed"))) {
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               OSUTF8CHAR* pcontent = ((xmlNodePtr)pXmlAttr)->children->content;
               rtxInitContextBuffer (pctxt, pcontent, rtxUTF8LenBytes(pcontent));
               rtXmlDecBool (pctxt, &pvalue->closed);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("supplemental"))) {
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               OSUTF8CHAR* pcontent = ((xmlNodePtr)pXmlAttr)->children->content;
               rtxInitContextBuffer (pctxt, pcontent, rtxUTF8LenBytes(pcontent));
               rtXmlDecBool (pctxt, &pvalue->supplemental);
            }
         }
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      pvalue->base = pXmlNode->children->content;
   }
   else {
      pvalue->base = (const OSUTF8CHAR*)"";
   }

   return 0;
}

int DOMTest_SignLanguageType (OSCTXT* pctxt, SignLanguageType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("primary"))) {
            pvalue->m.primaryPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               OSUTF8CHAR* pcontent = ((xmlNodePtr)pXmlAttr)->children->content;
               rtxInitContextBuffer (pctxt, pcontent, rtxUTF8LenBytes(pcontent));
               rtXmlDecBool (pctxt, &pvalue->primary);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("translation"))) {
            pvalue->m.translationPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               OSUTF8CHAR* pcontent = ((xmlNodePtr)pXmlAttr)->children->content;
               rtxInitContextBuffer (pctxt, pcontent, rtxUTF8LenBytes(pcontent));
               rtXmlDecBool (pctxt, &pvalue->translation);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("type"))) {
            pvalue->m.typePresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->type = ((xmlNodePtr)pXmlAttr)->children->content;
            }
            else {
               pvalue->type = (const OSUTF8CHAR*)"";
            }
         }
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      pvalue->base = pXmlNode->children->content;
   }
   else {
      pvalue->base = (const OSUTF8CHAR*)"";
   }

   return 0;
}

int DOMTest_BitRateType (OSCTXT* pctxt, BitRateType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Populate attributes */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("average"))) {
            pvalue->m.averagePresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->average = atoi ((const char*)((xmlNodePtr)pXmlAttr)->children->content);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("maximum"))) {
            pvalue->m.maximumPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->maximum = atoi ((const char*)((xmlNodePtr)pXmlAttr)->children->content);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("minimum"))) {
            pvalue->m.minimumPresent = 1;
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               pvalue->minimum = atoi ((const char*)((xmlNodePtr)pXmlAttr)->children->content);
            }
         }
         else if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("variable"))) {
            if (0 != ((xmlNodePtr)pXmlAttr)->children) {
               OSUTF8CHAR* pcontent = ((xmlNodePtr)pXmlAttr)->children->content;
               rtxInitContextBuffer (pctxt, pcontent, rtxUTF8LenBytes(pcontent));
               rtXmlDecBool (pctxt, &pvalue->variable);
            }
         }
      }
   }
   /* Populate elements */
   if (0 != pXmlNode->children) {
      pvalue->base = atoi ((const char*)pXmlNode->children->content);
   }

   return 0;
}

int DOMTest_TVAAgentType_derivations (OSCTXT* pctxt, 
   TVAAgentType_derivations* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   const OSUTF8CHAR* xsiType = 0;
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Find xsi:type attribute */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("type"))) {
            xmlChar* pPrefix;
            xsiType = xmlSplitQName2 (pXmlAttr->children->content, &pPrefix);
         }
      }
   }

   /* Call derived function based on type name */
   if (0 == xsiType) {
      xsiType = OSUTF8("TVAAgentType");
   }
   if (rtxUTF8StrEqual (xsiType, OSUTF8("TVAAgentType")))
   {
      pvalue->t = 1;
      pvalue->u.tVAAgentType = rtxMemAllocType (pctxt, TVAAgentType);

      if (pvalue->u.tVAAgentType == NULL)
         return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_TVAAgentType (pvalue->u.tVAAgentType);
      DOMTest_TVAAgentType (pctxt, pvalue->u.tVAAgentType, pXmlNode, TRUE);
   }
   else if (rtxUTF8StrEqual (xsiType, OSUTF8("CreditsItemType")))
   {
      pvalue->t = 2;
      pvalue->u.creditsItemType = rtxMemAllocType (pctxt, CreditsItemType);

      if (pvalue->u.creditsItemType == NULL)
         return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_CreditsItemType (pvalue->u.creditsItemType);
      DOMTest_CreditsItemType (pctxt, pvalue->u.creditsItemType, pXmlNode, TRUE);
   }
   else {
      printf ("unknown xsi type\n");
   }

   return 0;
}

int DOMTest_ControlledTermType_derivations (OSCTXT* pctxt, 
   ControlledTermType_derivations* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   const OSUTF8CHAR* xsiType = 0;
   xmlAttrPtr pXmlAttr = pXmlNode->properties;

   /* Find xsi:type attribute */
   for ( ; 0 != pXmlAttr; pXmlAttr = pXmlAttr->next) {
      if (pXmlAttr->type == XML_ATTRIBUTE_NODE) {
         if (rtxUTF8StrEqual (pXmlAttr->name, OSUTF8("type"))) {
            xmlChar* pPrefix;
            xsiType = xmlSplitQName2 (pXmlAttr->children->content, &pPrefix);
         }
      }
   }

   /* Call derived function based on type name */
   if (0 == xsiType) {
      xsiType = OSUTF8("ControlledTermType");
   }
   if (rtxUTF8StrEqual (xsiType, OSUTF8("ControlledTermType")))
   {
      pvalue->t = 1;
      pvalue->u.controlledTermType
          = rtxMemAllocType (pctxt, ControlledTermType);

      if (pvalue->u.controlledTermType == NULL)
         return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_ControlledTermType (pvalue->u.controlledTermType);
      DOMTest_ControlledTermType (pctxt, pvalue->u.controlledTermType, pXmlNode, TRUE);
   }
   else if (rtxUTF8StrEqual (xsiType, OSUTF8("GenreType")))
   {
      pvalue->t = 2;
      pvalue->u.genreType = rtxMemAllocType (pctxt, GenreType);

      if (pvalue->u.genreType == NULL)
         return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_GenreType (pvalue->u.genreType);
      DOMTest_GenreType (pctxt, pvalue->u.genreType, pXmlNode, TRUE);
   }
   else {
      printf ("unknown xsi type\n");
   }

   return 0;
}
