/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#ifndef UBL_CORECOMPONENTPARAMETERS_1_0_H
#define UBL_CORECOMPONENTPARAMETERS_1_0_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include "rtkey.h"
#include "asn1ber.h"
#include "libxml/parser.h"

/**************************************************************/
/*                                                            */
/*  ComponentType                                             */
/*                                                            */
/**************************************************************/

#define TV_ComponentType	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* ComponentType;

EXTERN int asn1E_ComponentType (OSCTXT* pctxt,
   ComponentType pvalue, ASN1TagType tagging);

EXTERN int asn1D_ComponentType (OSCTXT* pctxt,
   ComponentType *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  DictionaryEntryName                                       */
/*                                                            */
/**************************************************************/

#define TV_DictionaryEntryName	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* DictionaryEntryName;

EXTERN int asn1E_DictionaryEntryName (OSCTXT* pctxt,
   DictionaryEntryName pvalue, ASN1TagType tagging);

EXTERN int asn1D_DictionaryEntryName (OSCTXT* pctxt,
   DictionaryEntryName *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  Version                                                   */
/*                                                            */
/**************************************************************/

#define TV_Version	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* Version;

EXTERN int asn1E_Version (OSCTXT* pctxt,
   Version pvalue, ASN1TagType tagging);

EXTERN int asn1D_Version (OSCTXT* pctxt,
   Version *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  Definition                                                */
/*                                                            */
/**************************************************************/

#define TV_Definition	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* Definition;

EXTERN int asn1E_Definition (OSCTXT* pctxt,
   Definition pvalue, ASN1TagType tagging);

EXTERN int asn1D_Definition (OSCTXT* pctxt,
   Definition *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  Cardinality                                               */
/*                                                            */
/**************************************************************/

#define TV_Cardinality	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* Cardinality;

EXTERN int asn1E_Cardinality (OSCTXT* pctxt,
   Cardinality pvalue, ASN1TagType tagging);

EXTERN int asn1D_Cardinality (OSCTXT* pctxt,
   Cardinality *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  ObjectClassQualifier                                      */
/*                                                            */
/**************************************************************/

#define TV_ObjectClassQualifier	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* ObjectClassQualifier;

EXTERN int asn1E_ObjectClassQualifier (OSCTXT* pctxt,
   ObjectClassQualifier pvalue, ASN1TagType tagging);

EXTERN int asn1D_ObjectClassQualifier (OSCTXT* pctxt,
   ObjectClassQualifier *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  ObjectClass                                               */
/*                                                            */
/**************************************************************/

#define TV_ObjectClass	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* ObjectClass;

EXTERN int asn1E_ObjectClass (OSCTXT* pctxt,
   ObjectClass pvalue, ASN1TagType tagging);

EXTERN int asn1D_ObjectClass (OSCTXT* pctxt,
   ObjectClass *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  PropertyTermQualifier                                     */
/*                                                            */
/**************************************************************/

#define TV_PropertyTermQualifier	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* PropertyTermQualifier;

EXTERN int asn1E_PropertyTermQualifier (OSCTXT* pctxt,
   PropertyTermQualifier pvalue, ASN1TagType tagging);

EXTERN int asn1D_PropertyTermQualifier (OSCTXT* pctxt,
   PropertyTermQualifier *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  PropertyTermPossessiveNoun                                */
/*                                                            */
/**************************************************************/

#define TV_PropertyTermPossessiveNoun	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* PropertyTermPossessiveNoun;

EXTERN int asn1E_PropertyTermPossessiveNoun (OSCTXT* pctxt,
   PropertyTermPossessiveNoun pvalue, ASN1TagType tagging);

EXTERN int asn1D_PropertyTermPossessiveNoun (OSCTXT* pctxt,
   PropertyTermPossessiveNoun *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  PropertyTermPrimaryNoun                                   */
/*                                                            */
/**************************************************************/

#define TV_PropertyTermPrimaryNoun	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* PropertyTermPrimaryNoun;

EXTERN int asn1E_PropertyTermPrimaryNoun (OSCTXT* pctxt,
   PropertyTermPrimaryNoun pvalue, ASN1TagType tagging);

EXTERN int asn1D_PropertyTermPrimaryNoun (OSCTXT* pctxt,
   PropertyTermPrimaryNoun *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  PropertyTerm                                              */
/*                                                            */
/**************************************************************/

#define TV_PropertyTerm	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* PropertyTerm;

EXTERN int asn1E_PropertyTerm (OSCTXT* pctxt,
   PropertyTerm pvalue, ASN1TagType tagging);

EXTERN int asn1D_PropertyTerm (OSCTXT* pctxt,
   PropertyTerm *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  RepresentationTerm                                        */
/*                                                            */
/**************************************************************/

#define TV_RepresentationTerm	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* RepresentationTerm;

EXTERN int asn1E_RepresentationTerm (OSCTXT* pctxt,
   RepresentationTerm pvalue, ASN1TagType tagging);

EXTERN int asn1D_RepresentationTerm (OSCTXT* pctxt,
   RepresentationTerm *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  DataTypeQualifier                                         */
/*                                                            */
/**************************************************************/

#define TV_DataTypeQualifier	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* DataTypeQualifier;

EXTERN int asn1E_DataTypeQualifier (OSCTXT* pctxt,
   DataTypeQualifier pvalue, ASN1TagType tagging);

EXTERN int asn1D_DataTypeQualifier (OSCTXT* pctxt,
   DataTypeQualifier *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  DataType                                                  */
/*                                                            */
/**************************************************************/

#define TV_DataType	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* DataType;

EXTERN int asn1E_DataType (OSCTXT* pctxt,
   DataType pvalue, ASN1TagType tagging);

EXTERN int asn1D_DataType (OSCTXT* pctxt,
   DataType *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  AssociatedObjectClassQualifier                            */
/*                                                            */
/**************************************************************/

#define TV_AssociatedObjectClassQualifier	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* AssociatedObjectClassQualifier;

EXTERN int asn1E_AssociatedObjectClassQualifier (OSCTXT* pctxt,
   AssociatedObjectClassQualifier pvalue, ASN1TagType tagging);

EXTERN int asn1D_AssociatedObjectClassQualifier (OSCTXT* pctxt,
   AssociatedObjectClassQualifier *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  AssociatedObjectClass                                     */
/*                                                            */
/**************************************************************/

#define TV_AssociatedObjectClass	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* AssociatedObjectClass;

EXTERN int asn1E_AssociatedObjectClass (OSCTXT* pctxt,
   AssociatedObjectClass pvalue, ASN1TagType tagging);

EXTERN int asn1D_AssociatedObjectClass (OSCTXT* pctxt,
   AssociatedObjectClass *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  AlternativeBusinessTerms                                  */
/*                                                            */
/**************************************************************/

#define TV_AlternativeBusinessTerms	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* AlternativeBusinessTerms;

EXTERN int asn1E_AlternativeBusinessTerms (OSCTXT* pctxt,
   AlternativeBusinessTerms pvalue, ASN1TagType tagging);

EXTERN int asn1D_AlternativeBusinessTerms (OSCTXT* pctxt,
   AlternativeBusinessTerms *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  Examples                                                  */
/*                                                            */
/**************************************************************/

#define TV_Examples	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* Examples;

EXTERN int asn1E_Examples (OSCTXT* pctxt,
   Examples pvalue, ASN1TagType tagging);

EXTERN int asn1D_Examples (OSCTXT* pctxt,
   Examples *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  ComponentType_1                                           */
/*                                                            */
/**************************************************************/

#define TV_ComponentType_1	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN ComponentType_1 {
   struct {
      unsigned versionPresent : 1;
      unsigned cardinalityPresent : 1;
      unsigned objectClassQualifierPresent : 1;
      unsigned objectClassPresent : 1;
      unsigned propertyTermQualifierPresent : 1;
      unsigned propertyTermPossessiveNounPresent : 1;
      unsigned propertyTermPrimaryNounPresent : 1;
      unsigned propertyTermPresent : 1;
      unsigned representationTermPresent : 1;
      unsigned dataTypeQualifierPresent : 1;
      unsigned dataTypePresent : 1;
      unsigned associatedObjectClassQualifierPresent : 1;
      unsigned associatedObjectClassPresent : 1;
      unsigned alternativeBusinessTermsPresent : 1;
      unsigned examplesPresent : 1;
   } m;
   ComponentType componentType;
   DictionaryEntryName dictionaryEntryName;
   Version version;
   Definition definition;
   Cardinality cardinality;
   ObjectClassQualifier objectClassQualifier;
   ObjectClass objectClass;
   PropertyTermQualifier propertyTermQualifier;
   PropertyTermPossessiveNoun propertyTermPossessiveNoun;
   PropertyTermPrimaryNoun propertyTermPrimaryNoun;
   PropertyTerm propertyTerm;
   RepresentationTerm representationTerm;
   DataTypeQualifier dataTypeQualifier;
   DataType dataType;
   AssociatedObjectClassQualifier associatedObjectClassQualifier;
   AssociatedObjectClass associatedObjectClass;
   AlternativeBusinessTerms alternativeBusinessTerms;
   Examples examples;
} ComponentType_1;

EXTERN int asn1E_ComponentType_1 (OSCTXT* pctxt,
   ComponentType_1 *pvalue, ASN1TagType tagging);

EXTERN int asn1D_ComponentType_1 (OSCTXT* pctxt,
   ComponentType_1 *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_ComponentType_1 (OSCTXT* pctxt, ComponentType_1* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_ComponentType_1 (ComponentType_1* pvalue);

/**************************************************************/
/*                                                            */
/*  Component                                                 */
/*                                                            */
/**************************************************************/

#define TV_Component	(TM_UNIV|TM_CONS|16)

typedef ComponentType_1 Component;

EXTERN int asn1E_Component (OSCTXT* pctxt,
   Component *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Component (OSCTXT* pctxt,
   Component *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_Component (OSCTXT* pctxt, Component* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Component (Component* pvalue);

/**************************************************************/
/*                                                            */
/*  IndustryClassification                                    */
/*                                                            */
/**************************************************************/

#define TV_IndustryClassification	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* IndustryClassification;

EXTERN int asn1E_IndustryClassification (OSCTXT* pctxt,
   IndustryClassification pvalue, ASN1TagType tagging);

EXTERN int asn1D_IndustryClassification (OSCTXT* pctxt,
   IndustryClassification *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  _SeqOfIndustryClassification                              */
/*                                                            */
/**************************************************************/

#define TV__SeqOfIndustryClassification	(TM_UNIV|TM_CONS|16)

/* List of IndustryClassification */
typedef OSRTDList _SeqOfIndustryClassification;

EXTERN int asn1E__SeqOfIndustryClassification (OSCTXT* pctxt,
   _SeqOfIndustryClassification *pvalue, ASN1TagType tagging);

EXTERN int asn1D__SeqOfIndustryClassification (OSCTXT* pctxt,
   _SeqOfIndustryClassification *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest__SeqOfIndustryClassification (OSCTXT* pctxt, 
   _SeqOfIndustryClassification* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init__SeqOfIndustryClassification (_SeqOfIndustryClassification* pvalue);

/**************************************************************/
/*                                                            */
/*  Geopolitical                                              */
/*                                                            */
/**************************************************************/

#define TV_Geopolitical	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* Geopolitical;

EXTERN int asn1E_Geopolitical (OSCTXT* pctxt,
   Geopolitical pvalue, ASN1TagType tagging);

EXTERN int asn1D_Geopolitical (OSCTXT* pctxt,
   Geopolitical *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  _SeqOfGeopolitical                                        */
/*                                                            */
/**************************************************************/

#define TV__SeqOfGeopolitical	(TM_UNIV|TM_CONS|16)

/* List of Geopolitical */
typedef OSRTDList _SeqOfGeopolitical;

EXTERN int asn1E__SeqOfGeopolitical (OSCTXT* pctxt,
   _SeqOfGeopolitical *pvalue, ASN1TagType tagging);

EXTERN int asn1D__SeqOfGeopolitical (OSCTXT* pctxt,
   _SeqOfGeopolitical *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest__SeqOfGeopolitical (OSCTXT* pctxt, 
   _SeqOfGeopolitical* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init__SeqOfGeopolitical (_SeqOfGeopolitical* pvalue);

/**************************************************************/
/*                                                            */
/*  BusinessProcess                                           */
/*                                                            */
/**************************************************************/

#define TV_BusinessProcess	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* BusinessProcess;

EXTERN int asn1E_BusinessProcess (OSCTXT* pctxt,
   BusinessProcess pvalue, ASN1TagType tagging);

EXTERN int asn1D_BusinessProcess (OSCTXT* pctxt,
   BusinessProcess *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  _SeqOfBusinessProcess                                     */
/*                                                            */
/**************************************************************/

#define TV__SeqOfBusinessProcess	(TM_UNIV|TM_CONS|16)

/* List of BusinessProcess */
typedef OSRTDList _SeqOfBusinessProcess;

EXTERN int asn1E__SeqOfBusinessProcess (OSCTXT* pctxt,
   _SeqOfBusinessProcess *pvalue, ASN1TagType tagging);

EXTERN int asn1D__SeqOfBusinessProcess (OSCTXT* pctxt,
   _SeqOfBusinessProcess *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest__SeqOfBusinessProcess (OSCTXT* pctxt, 
   _SeqOfBusinessProcess* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init__SeqOfBusinessProcess (_SeqOfBusinessProcess* pvalue);

/**************************************************************/
/*                                                            */
/*  OfficialConstraint                                        */
/*                                                            */
/**************************************************************/

#define TV_OfficialConstraint	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* OfficialConstraint;

EXTERN int asn1E_OfficialConstraint (OSCTXT* pctxt,
   OfficialConstraint pvalue, ASN1TagType tagging);

EXTERN int asn1D_OfficialConstraint (OSCTXT* pctxt,
   OfficialConstraint *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  _SeqOfOfficialConstraint                                  */
/*                                                            */
/**************************************************************/

#define TV__SeqOfOfficialConstraint	(TM_UNIV|TM_CONS|16)

/* List of OfficialConstraint */
typedef OSRTDList _SeqOfOfficialConstraint;

EXTERN int asn1E__SeqOfOfficialConstraint (OSCTXT* pctxt,
   _SeqOfOfficialConstraint *pvalue, ASN1TagType tagging);

EXTERN int asn1D__SeqOfOfficialConstraint (OSCTXT* pctxt,
   _SeqOfOfficialConstraint *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest__SeqOfOfficialConstraint (OSCTXT* pctxt, 
   _SeqOfOfficialConstraint* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init__SeqOfOfficialConstraint (_SeqOfOfficialConstraint* pvalue);

/**************************************************************/
/*                                                            */
/*  ProductClassification                                     */
/*                                                            */
/**************************************************************/

#define TV_ProductClassification	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* ProductClassification;

EXTERN int asn1E_ProductClassification (OSCTXT* pctxt,
   ProductClassification pvalue, ASN1TagType tagging);

EXTERN int asn1D_ProductClassification (OSCTXT* pctxt,
   ProductClassification *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  _SeqOfProductClassification                               */
/*                                                            */
/**************************************************************/

#define TV__SeqOfProductClassification	(TM_UNIV|TM_CONS|16)

/* List of ProductClassification */
typedef OSRTDList _SeqOfProductClassification;

EXTERN int asn1E__SeqOfProductClassification (OSCTXT* pctxt,
   _SeqOfProductClassification *pvalue, ASN1TagType tagging);

EXTERN int asn1D__SeqOfProductClassification (OSCTXT* pctxt,
   _SeqOfProductClassification *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest__SeqOfProductClassification (OSCTXT* pctxt, 
   _SeqOfProductClassification* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init__SeqOfProductClassification (_SeqOfProductClassification* pvalue);

/**************************************************************/
/*                                                            */
/*  BusinessProcessRole                                       */
/*                                                            */
/**************************************************************/

#define TV_BusinessProcessRole	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* BusinessProcessRole;

EXTERN int asn1E_BusinessProcessRole (OSCTXT* pctxt,
   BusinessProcessRole pvalue, ASN1TagType tagging);

EXTERN int asn1D_BusinessProcessRole (OSCTXT* pctxt,
   BusinessProcessRole *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  _SeqOfBusinessProcessRole                                 */
/*                                                            */
/**************************************************************/

#define TV__SeqOfBusinessProcessRole	(TM_UNIV|TM_CONS|16)

/* List of BusinessProcessRole */
typedef OSRTDList _SeqOfBusinessProcessRole;

EXTERN int asn1E__SeqOfBusinessProcessRole (OSCTXT* pctxt,
   _SeqOfBusinessProcessRole *pvalue, ASN1TagType tagging);

EXTERN int asn1D__SeqOfBusinessProcessRole (OSCTXT* pctxt,
   _SeqOfBusinessProcessRole *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest__SeqOfBusinessProcessRole (OSCTXT* pctxt, 
   _SeqOfBusinessProcessRole* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init__SeqOfBusinessProcessRole (_SeqOfBusinessProcessRole* pvalue);

/**************************************************************/
/*                                                            */
/*  SupportingRole                                            */
/*                                                            */
/**************************************************************/

#define TV_SupportingRole	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* SupportingRole;

EXTERN int asn1E_SupportingRole (OSCTXT* pctxt,
   SupportingRole pvalue, ASN1TagType tagging);

EXTERN int asn1D_SupportingRole (OSCTXT* pctxt,
   SupportingRole *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  _SeqOfSupportingRole                                      */
/*                                                            */
/**************************************************************/

#define TV__SeqOfSupportingRole	(TM_UNIV|TM_CONS|16)

/* List of SupportingRole */
typedef OSRTDList _SeqOfSupportingRole;

EXTERN int asn1E__SeqOfSupportingRole (OSCTXT* pctxt,
   _SeqOfSupportingRole *pvalue, ASN1TagType tagging);

EXTERN int asn1D__SeqOfSupportingRole (OSCTXT* pctxt,
   _SeqOfSupportingRole *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest__SeqOfSupportingRole (OSCTXT* pctxt, 
   _SeqOfSupportingRole* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init__SeqOfSupportingRole (_SeqOfSupportingRole* pvalue);

/**************************************************************/
/*                                                            */
/*  SystemCapability                                          */
/*                                                            */
/**************************************************************/

#define TV_SystemCapability	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* SystemCapability;

EXTERN int asn1E_SystemCapability (OSCTXT* pctxt,
   SystemCapability pvalue, ASN1TagType tagging);

EXTERN int asn1D_SystemCapability (OSCTXT* pctxt,
   SystemCapability *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  _SeqOfSystemCapability                                    */
/*                                                            */
/**************************************************************/

#define TV__SeqOfSystemCapability	(TM_UNIV|TM_CONS|16)

/* List of SystemCapability */
typedef OSRTDList _SeqOfSystemCapability;

EXTERN int asn1E__SeqOfSystemCapability (OSCTXT* pctxt,
   _SeqOfSystemCapability *pvalue, ASN1TagType tagging);

EXTERN int asn1D__SeqOfSystemCapability (OSCTXT* pctxt,
   _SeqOfSystemCapability *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest__SeqOfSystemCapability (OSCTXT* pctxt, 
   _SeqOfSystemCapability* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init__SeqOfSystemCapability (_SeqOfSystemCapability* pvalue);

/**************************************************************/
/*                                                            */
/*  ContextType                                               */
/*                                                            */
/**************************************************************/

#define TV_ContextType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN ContextType {
   _SeqOfIndustryClassification industryClassification_list;
   _SeqOfGeopolitical geopolitical_list;
   _SeqOfBusinessProcess businessProcess_list;
   _SeqOfOfficialConstraint officialConstraint_list;
   _SeqOfProductClassification productClassification_list;
   _SeqOfBusinessProcessRole businessProcessRole_list;
   _SeqOfSupportingRole supportingRole_list;
   _SeqOfSystemCapability systemCapability_list;
} ContextType;

EXTERN int asn1E_ContextType (OSCTXT* pctxt,
   ContextType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_ContextType (OSCTXT* pctxt,
   ContextType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_ContextType (OSCTXT* pctxt, ContextType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_ContextType (ContextType* pvalue);

/**************************************************************/
/*                                                            */
/*  Context                                                   */
/*                                                            */
/**************************************************************/

#define TV_Context	(TM_UNIV|TM_CONS|16)

typedef ContextType Context;

EXTERN int asn1E_Context (OSCTXT* pctxt,
   Context *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Context (OSCTXT* pctxt,
   Context *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_Context (OSCTXT* pctxt, Context* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Context (Context* pvalue);

/**************************************************************/
/*                                                            */
/*  _SeqOfContext                                             */
/*                                                            */
/**************************************************************/

#define TV__SeqOfContext	(TM_UNIV|TM_CONS|16)

/* List of Context */
typedef OSRTDList _SeqOfContext;

EXTERN int asn1E__SeqOfContext (OSCTXT* pctxt,
   _SeqOfContext *pvalue, ASN1TagType tagging);

EXTERN int asn1D__SeqOfContext (OSCTXT* pctxt,
   _SeqOfContext *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest__SeqOfContext (OSCTXT* pctxt, _SeqOfContext* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init__SeqOfContext (_SeqOfContext* pvalue);

/**************************************************************/
/*                                                            */
/*  ContextualizationType                                     */
/*                                                            */
/**************************************************************/

#define TV_ContextualizationType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN ContextualizationType {
   _SeqOfContext context_list;
} ContextualizationType;

EXTERN int asn1E_ContextualizationType (OSCTXT* pctxt,
   ContextualizationType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_ContextualizationType (OSCTXT* pctxt,
   ContextualizationType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_ContextualizationType (OSCTXT* pctxt, 
   ContextualizationType* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_ContextualizationType (ContextualizationType* pvalue);

/**************************************************************/
/*                                                            */
/*  Contextualization                                         */
/*                                                            */
/**************************************************************/

#define TV_Contextualization	(TM_UNIV|TM_CONS|16)

typedef ContextualizationType Contextualization;

EXTERN int asn1E_Contextualization (OSCTXT* pctxt,
   Contextualization *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Contextualization (OSCTXT* pctxt,
   Contextualization *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_Contextualization (OSCTXT* pctxt, Contextualization* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Contextualization (Contextualization* pvalue);

/**************************************************************/
/*                                                            */
/*  Name                                                      */
/*                                                            */
/**************************************************************/

#define TV_Name	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* Name;

EXTERN int asn1E_Name (OSCTXT* pctxt,
   Name pvalue, ASN1TagType tagging);

EXTERN int asn1D_Name (OSCTXT* pctxt,
   Name *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  CodeListID                                                */
/*                                                            */
/**************************************************************/

#define TV_CodeListID	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* CodeListID;

EXTERN int asn1E_CodeListID (OSCTXT* pctxt,
   CodeListID pvalue, ASN1TagType tagging);

EXTERN int asn1D_CodeListID (OSCTXT* pctxt,
   CodeListID *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  CodeListAgencyID                                          */
/*                                                            */
/**************************************************************/

#define TV_CodeListAgencyID	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* CodeListAgencyID;

EXTERN int asn1E_CodeListAgencyID (OSCTXT* pctxt,
   CodeListAgencyID pvalue, ASN1TagType tagging);

EXTERN int asn1D_CodeListAgencyID (OSCTXT* pctxt,
   CodeListAgencyID *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  CodeListAgencyName                                        */
/*                                                            */
/**************************************************************/

#define TV_CodeListAgencyName	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* CodeListAgencyName;

EXTERN int asn1E_CodeListAgencyName (OSCTXT* pctxt,
   CodeListAgencyName pvalue, ASN1TagType tagging);

EXTERN int asn1D_CodeListAgencyName (OSCTXT* pctxt,
   CodeListAgencyName *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  CodeListName                                              */
/*                                                            */
/**************************************************************/

#define TV_CodeListName	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* CodeListName;

EXTERN int asn1E_CodeListName (OSCTXT* pctxt,
   CodeListName pvalue, ASN1TagType tagging);

EXTERN int asn1D_CodeListName (OSCTXT* pctxt,
   CodeListName *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  CodeListVersionID                                         */
/*                                                            */
/**************************************************************/

#define TV_CodeListVersionID	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* CodeListVersionID;

EXTERN int asn1E_CodeListVersionID (OSCTXT* pctxt,
   CodeListVersionID pvalue, ASN1TagType tagging);

EXTERN int asn1D_CodeListVersionID (OSCTXT* pctxt,
   CodeListVersionID *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  CodeListURI                                               */
/*                                                            */
/**************************************************************/

#define TV_CodeListURI	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* CodeListURI;

EXTERN int asn1E_CodeListURI (OSCTXT* pctxt,
   CodeListURI pvalue, ASN1TagType tagging);

EXTERN int asn1D_CodeListURI (OSCTXT* pctxt,
   CodeListURI *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  CodeListSchemeURI                                         */
/*                                                            */
/**************************************************************/

#define TV_CodeListSchemeURI	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* CodeListSchemeURI;

EXTERN int asn1E_CodeListSchemeURI (OSCTXT* pctxt,
   CodeListSchemeURI pvalue, ASN1TagType tagging);

EXTERN int asn1D_CodeListSchemeURI (OSCTXT* pctxt,
   CodeListSchemeURI *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  LanguageID                                                */
/*                                                            */
/**************************************************************/

#define TV_LanguageID	(TM_UNIV|TM_PRIM|12)

typedef const OSUTF8CHAR* LanguageID;

EXTERN int asn1E_LanguageID (OSCTXT* pctxt,
   LanguageID pvalue, ASN1TagType tagging);

EXTERN int asn1D_LanguageID (OSCTXT* pctxt,
   LanguageID *pvalue, ASN1TagType tagging, int length);

/**************************************************************/
/*                                                            */
/*  InstanceType                                              */
/*                                                            */
/**************************************************************/

#define TV_InstanceType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN InstanceType {
   struct {
      unsigned namePresent : 1;
      unsigned codeListIDPresent : 1;
      unsigned codeListAgencyIDPresent : 1;
      unsigned codeListAgencyNamePresent : 1;
      unsigned codeListNamePresent : 1;
      unsigned codeListVersionIDPresent : 1;
      unsigned codeListURIPresent : 1;
      unsigned codeListSchemeURIPresent : 1;
      unsigned languageIDPresent : 1;
   } m;
   Name name;
   CodeListID codeListID;
   CodeListAgencyID codeListAgencyID;
   CodeListAgencyName codeListAgencyName;
   CodeListName codeListName;
   CodeListVersionID codeListVersionID;
   CodeListURI codeListURI;
   CodeListSchemeURI codeListSchemeURI;
   LanguageID languageID;
} InstanceType;

EXTERN int asn1E_InstanceType (OSCTXT* pctxt,
   InstanceType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_InstanceType (OSCTXT* pctxt,
   InstanceType *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_InstanceType (OSCTXT* pctxt, InstanceType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_InstanceType (InstanceType* pvalue);

/**************************************************************/
/*                                                            */
/*  Instance                                                  */
/*                                                            */
/**************************************************************/

#define TV_Instance	(TM_UNIV|TM_CONS|16)

typedef InstanceType Instance;

EXTERN int asn1E_Instance (OSCTXT* pctxt,
   Instance *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Instance (OSCTXT* pctxt,
   Instance *pvalue, ASN1TagType tagging, int length);

EXTERN void asn1DOMTest_Instance (OSCTXT* pctxt, Instance* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Instance (Instance* pvalue);

#ifdef __cplusplus
}
#endif

#endif
