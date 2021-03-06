/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#include "asn1intl.h"
#include "UBL-CoreComponentParameters-1-0.h"
#include "libxml/parser.h"
#include "rtxmlsrc/osrtxml.h"
#include "rtxsrc/rtxCommon.h"

void asn1DOMTest_ComponentType_1 (OSCTXT* pctxt, ComponentType_1* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("ComponentType"))) {
            if (0 != pXmlNode->children) {
               pvalue->componentType = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("DictionaryEntryName"))) {
            if (0 != pXmlNode->children) {
               pvalue->dictionaryEntryName = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Version"))) {
            pvalue->m.versionPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->version = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Definition"))) {
            if (0 != pXmlNode->children) {
               pvalue->definition = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Cardinality"))) {
            pvalue->m.cardinalityPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->cardinality = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("ObjectClassQualifier"))) {
            pvalue->m.objectClassQualifierPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->objectClassQualifier = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("ObjectClass"))) {
            pvalue->m.objectClassPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->objectClass = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PropertyTermQualifier"))) {
            pvalue->m.propertyTermQualifierPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->propertyTermQualifier = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PropertyTermPossessiveNoun"))) {
            pvalue->m.propertyTermPossessiveNounPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->propertyTermPossessiveNoun = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PropertyTermPrimaryNoun"))) {
            pvalue->m.propertyTermPrimaryNounPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->propertyTermPrimaryNoun = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PropertyTerm"))) {
            pvalue->m.propertyTermPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->propertyTerm = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("RepresentationTerm"))) {
            pvalue->m.representationTermPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->representationTerm = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("DataTypeQualifier"))) {
            pvalue->m.dataTypeQualifierPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->dataTypeQualifier = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("DataType"))) {
            pvalue->m.dataTypePresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->dataType = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("AssociatedObjectClassQualifier"))) {
            pvalue->m.associatedObjectClassQualifierPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->associatedObjectClassQualifier = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("AssociatedObjectClass"))) {
            pvalue->m.associatedObjectClassPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->associatedObjectClass = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("AlternativeBusinessTerms"))) {
            pvalue->m.alternativeBusinessTermsPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->alternativeBusinessTerms = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Examples"))) {
            pvalue->m.examplesPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->examples = pXmlNode->children->content;
            }
         }
      }
   }
}

void asn1DOMTest_Component (OSCTXT* pctxt, Component* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   asn1DOMTest_ComponentType_1 (pctxt, pvalue, pXmlNode, TRUE);
}

void asn1DOMTest__SeqOfIndustryClassification (OSCTXT* pctxt, 
   _SeqOfIndustryClassification* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   IndustryClassification pdata = 0;
   if (0 != pXmlNode->children) {
      pdata = pXmlNode->children->content;
   }
   if (0 != pdata)
      rtxDListAppend (pctxt, pvalue, (void*)pdata);
}

void asn1DOMTest__SeqOfGeopolitical (OSCTXT* pctxt, 
   _SeqOfGeopolitical* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   Geopolitical pdata = 0;
   if (0 != pXmlNode->children) {
      pdata = pXmlNode->children->content;
   }
   if (0 != pdata)
      rtxDListAppend (pctxt, pvalue, (void*)pdata);
}

void asn1DOMTest__SeqOfBusinessProcess (OSCTXT* pctxt, 
   _SeqOfBusinessProcess* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   BusinessProcess pdata = 0;
   if (0 != pXmlNode->children) {
      pdata = pXmlNode->children->content;
   }
   if (0 != pdata)
      rtxDListAppend (pctxt, pvalue, (void*)pdata);
}

void asn1DOMTest__SeqOfOfficialConstraint (OSCTXT* pctxt, 
   _SeqOfOfficialConstraint* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   OfficialConstraint pdata = 0;
   if (0 != pXmlNode->children) {
      pdata = pXmlNode->children->content;
   }
   if (0 != pdata)
      rtxDListAppend (pctxt, pvalue, (void*)pdata);
}

void asn1DOMTest__SeqOfProductClassification (OSCTXT* pctxt, 
   _SeqOfProductClassification* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   ProductClassification pdata = 0;
   if (0 != pXmlNode->children) {
      pdata = pXmlNode->children->content;
   }
   if (0 != pdata)
      rtxDListAppend (pctxt, pvalue, (void*)pdata);
}

void asn1DOMTest__SeqOfBusinessProcessRole (OSCTXT* pctxt, 
   _SeqOfBusinessProcessRole* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   BusinessProcessRole pdata = 0;
   if (0 != pXmlNode->children) {
      pdata = pXmlNode->children->content;
   }
   if (0 != pdata)
      rtxDListAppend (pctxt, pvalue, (void*)pdata);
}

void asn1DOMTest__SeqOfSupportingRole (OSCTXT* pctxt, 
   _SeqOfSupportingRole* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   SupportingRole pdata = 0;
   if (0 != pXmlNode->children) {
      pdata = pXmlNode->children->content;
   }
   if (0 != pdata)
      rtxDListAppend (pctxt, pvalue, (void*)pdata);
}

void asn1DOMTest__SeqOfSystemCapability (OSCTXT* pctxt, 
   _SeqOfSystemCapability* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   SystemCapability pdata = 0;
   if (0 != pXmlNode->children) {
      pdata = pXmlNode->children->content;
   }
   if (0 != pdata)
      rtxDListAppend (pctxt, pvalue, (void*)pdata);
}

void asn1DOMTest_ContextType (OSCTXT* pctxt, ContextType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("IndustryClassification"))) {
            asn1DOMTest__SeqOfIndustryClassification (pctxt, &pvalue->industryClassification_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Geopolitical"))) {
            asn1DOMTest__SeqOfGeopolitical (pctxt, &pvalue->geopolitical_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("BusinessProcess"))) {
            asn1DOMTest__SeqOfBusinessProcess (pctxt, &pvalue->businessProcess_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("OfficialConstraint"))) {
            asn1DOMTest__SeqOfOfficialConstraint (pctxt, &pvalue->officialConstraint_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("ProductClassification"))) {
            asn1DOMTest__SeqOfProductClassification (pctxt, &pvalue->productClassification_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("BusinessProcessRole"))) {
            asn1DOMTest__SeqOfBusinessProcessRole (pctxt, &pvalue->businessProcessRole_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("SupportingRole"))) {
            asn1DOMTest__SeqOfSupportingRole (pctxt, &pvalue->supportingRole_list, pXmlNode, TRUE);
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("SystemCapability"))) {
            asn1DOMTest__SeqOfSystemCapability (pctxt, &pvalue->systemCapability_list, pXmlNode, TRUE);
         }
      }
   }
}

void asn1DOMTest_Context (OSCTXT* pctxt, Context* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   asn1DOMTest_ContextType (pctxt, pvalue, pXmlNode, TRUE);
}

void asn1DOMTest__SeqOfContext (OSCTXT* pctxt, _SeqOfContext* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   Context* pdata = rtxMemAllocTypeZ (pctxt, Context);
   asn1DOMTest_Context (pctxt, pdata, pXmlNode, setChild);
   if (0 != pdata)
      rtxDListAppend (pctxt, pvalue, (void*)pdata);
}

void asn1DOMTest_ContextualizationType (OSCTXT* pctxt, 
   ContextualizationType* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild)
{
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Context"))) {
            asn1DOMTest__SeqOfContext (pctxt, &pvalue->context_list, pXmlNode, TRUE);
         }
      }
   }
}

void asn1DOMTest_Contextualization (OSCTXT* pctxt, Contextualization* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   asn1DOMTest_ContextualizationType (pctxt, pvalue, pXmlNode, TRUE);
}

void asn1DOMTest_InstanceType (OSCTXT* pctxt, InstanceType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   /* Populate elements */
   if (setChild)
      pXmlNode = pXmlNode->children;

   for ( ; 0 != pXmlNode; pXmlNode = pXmlNode->next) {
      if (pXmlNode->type == XML_ELEMENT_NODE) {
         if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Name"))) {
            pvalue->m.namePresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->name = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("CodeListID"))) {
            pvalue->m.codeListIDPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->codeListID = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("CodeListAgencyID"))) {
            pvalue->m.codeListAgencyIDPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->codeListAgencyID = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("CodeListAgencyName"))) {
            pvalue->m.codeListAgencyNamePresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->codeListAgencyName = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("CodeListName"))) {
            pvalue->m.codeListNamePresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->codeListName = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("CodeListVersionID"))) {
            pvalue->m.codeListVersionIDPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->codeListVersionID = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("CodeListURI"))) {
            pvalue->m.codeListURIPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->codeListURI = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("CodeListSchemeURI"))) {
            pvalue->m.codeListSchemeURIPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->codeListSchemeURI = pXmlNode->children->content;
            }
         }
         else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("LanguageID"))) {
            pvalue->m.languageIDPresent = 1;
            if (0 != pXmlNode->children) {
               pvalue->languageID = pXmlNode->children->content;
            }
         }
      }
   }
}

void asn1DOMTest_Instance (OSCTXT* pctxt, Instance* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild)
{
   asn1DOMTest_InstanceType (pctxt, pvalue, pXmlNode, TRUE);
}

