/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#ifndef SM_COMMON_H
#define SM_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include "rtkey.h"
#include "rtbersrc/asn1ber.h"
#include "rtsrc/asn1type.h"
#include "rtxmlsrc/asn1xml.h"
#include "libxml/parser.h"
#include "CoreComponentTypes.h"

/**
 * Header file for ASN.1 module Sm-common
 */
/**************************************************************/
/*                                                            */
/*  StateType                                                 */
/*                                                            */
/**************************************************************/

#define TV_StateType	(TM_UNIV|TM_PRIM|10)

typedef enum {
   StateType_aK = 0,
   StateType_aL = 1,
   StateType_aR = 2,
   StateType_aZ = 3,
   StateType_cA = 4,
   StateType_cO = 5,
   StateType_cT = 6,
   StateType_dE = 7,
   StateType_fL = 8,
   StateType_gA = 9,
   StateType_hI = 10,
   StateType_iA = 11,
   StateType_iD = 12,
   StateType_iL = 13,
   StateType_iN = 14,
   StateType_kS = 15,
   StateType_kY = 16,
   StateType_lA = 17,
   StateType_mA = 18,
   StateType_mD = 19,
   StateType_mE = 20,
   StateType_mI = 21,
   StateType_mN = 22,
   StateType_mO = 23,
   StateType_mS = 24,
   StateType_mT = 25,
   StateType_nC = 26,
   StateType_nD = 27,
   StateType_nE = 28,
   StateType_nH = 29,
   StateType_nJ = 30,
   StateType_nM = 31,
   StateType_nV = 32,
   StateType_oH = 33,
   StateType_oK = 34,
   StateType_oR = 35,
   StateType_pA = 36,
   StateType_rI = 37,
   StateType_sC = 38,
   StateType_sD = 39,
   StateType_tN = 40,
   StateType_tX = 41,
   StateType_uT = 42,
   StateType_vA = 43,
   StateType_vT = 44,
   StateType_wA = 45,
   StateType_wI = 46,
   StateType_wV = 47,
   StateType_wY = 48
} StateType_Root;

typedef OSUINT32 StateType;

EXTERN int asn1E_StateType (OSCTXT* pctxt,
   StateType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_StateType (OSCTXT* pctxt, StateType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_StateType (OSCTXT* pctxt, StateType value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_StateType (OSCTXT* pctxt, StateType* pvalue);

EXTERN const OSUTF8CHAR* StateType_ToString (OSINT32 value);

EXTERN int StateType_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, StateType* pvalue);

/**************************************************************/
/*                                                            */
/*  NoteType                                                  */
/*                                                            */
/**************************************************************/

#define TV_NoteType	(TM_UNIV|TM_CONS|16)

typedef CCT_TextType NoteType;

EXTERN int asn1E_NoteType (OSCTXT* pctxt,
   NoteType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_NoteType (OSCTXT* pctxt, NoteType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_NoteType (OSCTXT* pctxt, NoteType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_NoteType (OSCTXT* pctxt, NoteType* pvalue);

EXTERN int DOMTest_NoteType (OSCTXT* pctxt, NoteType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_NoteType (NoteType* pvalue);

/**************************************************************/
/*                                                            */
/*  QuoteType                                                 */
/*                                                            */
/**************************************************************/

#define TV_QuoteType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN QuoteType {
   CCT_IdentifierType identifier;
   CCT_DateTimeType issueDateTime;
} QuoteType;

EXTERN int asn1E_QuoteType (OSCTXT* pctxt,
   QuoteType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_QuoteType (OSCTXT* pctxt, QuoteType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_QuoteType (OSCTXT* pctxt, QuoteType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_QuoteType (OSCTXT* pctxt, QuoteType* pvalue);

EXTERN int DOMTest_QuoteType (OSCTXT* pctxt, QuoteType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_QuoteType (QuoteType* pvalue);

/**************************************************************/
/*                                                            */
/*  PeriodType                                                */
/*                                                            */
/**************************************************************/

#define TV_PeriodType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PeriodType {
   CCT_DateTimeType startDateTime;
   CCT_DateTimeType endDateTime;
} PeriodType;

EXTERN int asn1E_PeriodType (OSCTXT* pctxt,
   PeriodType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PeriodType (OSCTXT* pctxt, PeriodType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_PeriodType (OSCTXT* pctxt, PeriodType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PeriodType (OSCTXT* pctxt, PeriodType* pvalue);

EXTERN int DOMTest_PeriodType (OSCTXT* pctxt, PeriodType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PeriodType (PeriodType* pvalue);

/**************************************************************/
/*                                                            */
/*  ContractType                                              */
/*                                                            */
/**************************************************************/

#define TV_ContractType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN ContractType {
   CCT_IdentifierType identifier;
   PeriodType validityPeriod;
} ContractType;

EXTERN int asn1E_ContractType (OSCTXT* pctxt,
   ContractType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_ContractType (OSCTXT* pctxt, ContractType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_ContractType (OSCTXT* pctxt, ContractType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_ContractType (OSCTXT* pctxt, ContractType* pvalue);

EXTERN int DOMTest_ContractType (OSCTXT* pctxt, ContractType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_ContractType (ContractType* pvalue);

/**************************************************************/
/*                                                            */
/*  LanguageType                                              */
/*                                                            */
/**************************************************************/

#define TV_LanguageType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN LanguageType {
   CCT_CodeType identificationCode;
   CCT_TextType name;
} LanguageType;

EXTERN int asn1E_LanguageType (OSCTXT* pctxt,
   LanguageType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_LanguageType (OSCTXT* pctxt, LanguageType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_LanguageType (OSCTXT* pctxt, LanguageType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_LanguageType (OSCTXT* pctxt, LanguageType* pvalue);

EXTERN int DOMTest_LanguageType (OSCTXT* pctxt, LanguageType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_LanguageType (LanguageType* pvalue);

/**************************************************************/
/*                                                            */
/*  AddressType_sequence                                      */
/*                                                            */
/**************************************************************/

#define TV_AddressType_sequence	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN AddressType_sequence {
   struct {
      unsigned roomIDPresent : 1;
   } m;
   CCT_TextType street;
   CCT_IdentifierType houseID;
   CCT_IdentifierType roomID;
} AddressType_sequence;

EXTERN int asn1E_AddressType_sequence (OSCTXT* pctxt,
   AddressType_sequence *pvalue, ASN1TagType tagging);

EXTERN int asn1D_AddressType_sequence (OSCTXT* pctxt, 
   AddressType_sequence *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_AddressType_sequence (OSCTXT* pctxt, 
   AddressType_sequence* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_AddressType_sequence (OSCTXT* pctxt, 
   AddressType_sequence* pvalue);

EXTERN int DOMTest_AddressType_sequence (OSCTXT* pctxt, AddressType_sequence* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_AddressType_sequence (AddressType_sequence* pvalue);

/**************************************************************/
/*                                                            */
/*  AddressType_choice                                        */
/*                                                            */
/**************************************************************/

#define TV_AddressType_choice	(TM_UNIV|TM_CONS|0)

/* Choice tag constants */

#define T_AddressType_choice_postboxID  1
#define T_AddressType_choice_sequence   2

typedef struct EXTERN AddressType_choice {
   int t;
   union {
      /* t = 1 */
      CCT_IdentifierType *postboxID;
      /* t = 2 */
      AddressType_sequence *sequence;
   } u;
} AddressType_choice;

EXTERN int asn1E_AddressType_choice (OSCTXT* pctxt,
   AddressType_choice *pvalue, ASN1TagType tagging);

EXTERN int asn1D_AddressType_choice (OSCTXT* pctxt, 
   AddressType_choice *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_AddressType_choice (OSCTXT* pctxt, 
   AddressType_choice* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_AddressType_choice (OSCTXT* pctxt, 
   AddressType_choice* pvalue);

EXTERN int DOMTest_AddressType_choice (OSCTXT* pctxt, AddressType_choice* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_AddressType_choice (AddressType_choice* pvalue);

/**************************************************************/
/*                                                            */
/*  AddressType                                               */
/*                                                            */
/**************************************************************/

#define TV_AddressType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN AddressType {
   AddressType_choice choice;
   CCT_TextType cityName;
   CCT_IdentifierType postalZoneID;
   StateType stateName;
   CCT_CodeType countryIdentificationCode;
} AddressType;

EXTERN int asn1E_AddressType (OSCTXT* pctxt,
   AddressType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_AddressType (OSCTXT* pctxt, AddressType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_AddressType (OSCTXT* pctxt, AddressType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_AddressType (OSCTXT* pctxt, AddressType* pvalue);

EXTERN int DOMTest_AddressType (OSCTXT* pctxt, AddressType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_AddressType (AddressType* pvalue);

/**************************************************************/
/*                                                            */
/*  CommunicationType                                         */
/*                                                            */
/**************************************************************/

#define TV_CommunicationType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN CommunicationType {
   CCT_TextType value;
   CCT_IdentifierType channelID;
} CommunicationType;

EXTERN int asn1E_CommunicationType (OSCTXT* pctxt,
   CommunicationType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_CommunicationType (OSCTXT* pctxt, CommunicationType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_CommunicationType (OSCTXT* pctxt, CommunicationType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_CommunicationType (OSCTXT* pctxt, CommunicationType* pvalue)
   ;

EXTERN int DOMTest_CommunicationType (OSCTXT* pctxt, CommunicationType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_CommunicationType (CommunicationType* pvalue);

/**************************************************************/
/*                                                            */
/*  ContactType                                               */
/*                                                            */
/**************************************************************/

#define TV_ContactType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN ContactType {
   struct {
      unsigned namePresent : 1;
   } m;
   CCT_TextType name;
   /* List of CommunicationType */
   OSRTDList communication_list;
} ContactType;

EXTERN int asn1E_ContactType (OSCTXT* pctxt,
   ContactType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_ContactType (OSCTXT* pctxt, ContactType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_ContactType (OSCTXT* pctxt, ContactType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_ContactType (OSCTXT* pctxt, ContactType* pvalue);

EXTERN int DOMTest_ContactType (OSCTXT* pctxt, ContactType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_ContactType (ContactType* pvalue);

/**************************************************************/
/*                                                            */
/*  PartyType                                                 */
/*                                                            */
/**************************************************************/

#define TV_PartyType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PartyType {
   CCT_IdentifierType partyID;
   CCT_TextType name;
   AddressType address;
   ContactType contact;
} PartyType;

EXTERN int asn1E_PartyType (OSCTXT* pctxt,
   PartyType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PartyType (OSCTXT* pctxt, PartyType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_PartyType (OSCTXT* pctxt, PartyType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PartyType (OSCTXT* pctxt, PartyType* pvalue);

EXTERN int DOMTest_PartyType (OSCTXT* pctxt, PartyType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PartyType (PartyType* pvalue);

/**************************************************************/
/*                                                            */
/*  ShipmentType                                              */
/*                                                            */
/**************************************************************/

#define TV_ShipmentType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN ShipmentType {
   struct {
      unsigned shipDatePresent : 1;
      unsigned serviceLevelIDPresent : 1;
      unsigned instructionsPresent : 1;
   } m;
   CCT_DateTimeType shipDate;
   CCT_IdentifierType transportModeID;
   CCT_IdentifierType carrierID;
   CCT_IdentifierType serviceLevelID;
   CCT_TextType instructions;
} ShipmentType;

EXTERN int asn1E_ShipmentType (OSCTXT* pctxt,
   ShipmentType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_ShipmentType (OSCTXT* pctxt, ShipmentType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_ShipmentType (OSCTXT* pctxt, ShipmentType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_ShipmentType (OSCTXT* pctxt, ShipmentType* pvalue);

EXTERN int DOMTest_ShipmentType (OSCTXT* pctxt, ShipmentType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_ShipmentType (ShipmentType* pvalue);

/**************************************************************/
/*                                                            */
/*  FinancialInstitutionType                                  */
/*                                                            */
/**************************************************************/

#define TV_FinancialInstitutionType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN FinancialInstitutionType {
   CCT_IdentifierType identifier;
   CCT_TextType name;
   AddressType address;
} FinancialInstitutionType;

EXTERN int asn1E_FinancialInstitutionType (OSCTXT* pctxt,
   FinancialInstitutionType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_FinancialInstitutionType (OSCTXT* pctxt, 
   FinancialInstitutionType *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_FinancialInstitutionType (OSCTXT* pctxt, 
   FinancialInstitutionType* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_FinancialInstitutionType (OSCTXT* pctxt, 
   FinancialInstitutionType* pvalue);

EXTERN int DOMTest_FinancialInstitutionType (OSCTXT* pctxt, 
   FinancialInstitutionType* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_FinancialInstitutionType (FinancialInstitutionType* pvalue);

/**************************************************************/
/*                                                            */
/*  FinancialAccountType                                      */
/*                                                            */
/**************************************************************/

#define TV_FinancialAccountType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN FinancialAccountType {
   CCT_IdentifierType identifier;
   FinancialInstitutionType financialInstitution;
   CCT_IdentifierType typeID;
   CCT_TextType accountName;
} FinancialAccountType;

EXTERN int asn1E_FinancialAccountType (OSCTXT* pctxt,
   FinancialAccountType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_FinancialAccountType (OSCTXT* pctxt, 
   FinancialAccountType *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_FinancialAccountType (OSCTXT* pctxt, 
   FinancialAccountType* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_FinancialAccountType (OSCTXT* pctxt, 
   FinancialAccountType* pvalue);

EXTERN int DOMTest_FinancialAccountType (OSCTXT* pctxt, FinancialAccountType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_FinancialAccountType (FinancialAccountType* pvalue);

/**************************************************************/
/*                                                            */
/*  PaymentMeansType                                          */
/*                                                            */
/**************************************************************/

#define TV_PaymentMeansType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PaymentMeansType {
   struct {
      unsigned paymentDatePresent : 1;
      unsigned payerFinancialAccountPresent : 1;
      unsigned payeeFinancialAccountPresent : 1;
   } m;
   CCT_DateType paymentDate;
   FinancialAccountType payerFinancialAccount;
   FinancialAccountType payeeFinancialAccount;
} PaymentMeansType;

EXTERN int asn1E_PaymentMeansType (OSCTXT* pctxt,
   PaymentMeansType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PaymentMeansType (OSCTXT* pctxt, PaymentMeansType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_PaymentMeansType (OSCTXT* pctxt, PaymentMeansType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PaymentMeansType (OSCTXT* pctxt, PaymentMeansType* pvalue);

EXTERN int DOMTest_PaymentMeansType (OSCTXT* pctxt, PaymentMeansType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PaymentMeansType (PaymentMeansType* pvalue);

/**************************************************************/
/*                                                            */
/*  PricingVariationType                                      */
/*                                                            */
/**************************************************************/

#define TV_PricingVariationType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PricingVariationType {
   struct {
      unsigned serviceIDPresent : 1;
      unsigned servicePresent : 1;
      unsigned validityPeriodPresent : 1;
      unsigned ratePresent : 1;
      unsigned lumpSumAmountPresent : 1;
   } m;
   CCT_IdentifierType serviceID;
   CCT_TextType service;
   CCT_IdentifierType conditionID;
   PeriodType validityPeriod;
   CCT_NumericType rate;
   CCT_AmountType lumpSumAmount;
} PricingVariationType;

EXTERN int asn1E_PricingVariationType (OSCTXT* pctxt,
   PricingVariationType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PricingVariationType (OSCTXT* pctxt, 
   PricingVariationType *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_PricingVariationType (OSCTXT* pctxt, 
   PricingVariationType* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PricingVariationType (OSCTXT* pctxt, 
   PricingVariationType* pvalue);

EXTERN int DOMTest_PricingVariationType (OSCTXT* pctxt, PricingVariationType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PricingVariationType (PricingVariationType* pvalue);

/**************************************************************/
/*                                                            */
/*  PricingType                                               */
/*                                                            */
/**************************************************************/

#define TV_PricingType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PricingType {
   struct {
      unsigned netUnitPriceAmountPresent : 1;
   } m;
   CCT_AmountType grossUnitPriceAmount;
   CCT_AmountType netUnitPriceAmount;
} PricingType;

EXTERN int asn1E_PricingType (OSCTXT* pctxt,
   PricingType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PricingType (OSCTXT* pctxt, PricingType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_PricingType (OSCTXT* pctxt, PricingType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PricingType (OSCTXT* pctxt, PricingType* pvalue);

EXTERN int DOMTest_PricingType (OSCTXT* pctxt, PricingType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PricingType (PricingType* pvalue);

/**************************************************************/
/*                                                            */
/*  ItemType                                                  */
/*                                                            */
/**************************************************************/

#define TV_ItemType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN ItemType {
   struct {
      unsigned descriptionPresent : 1;
   } m;
   CCT_IdentifierType standardItemIdentifier;
   CCT_TextType description;
   CCT_QuantityType quantity;
} ItemType;

EXTERN int asn1E_ItemType (OSCTXT* pctxt,
   ItemType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_ItemType (OSCTXT* pctxt, ItemType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_ItemType (OSCTXT* pctxt, ItemType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_ItemType (OSCTXT* pctxt, ItemType* pvalue);

EXTERN int DOMTest_ItemType (OSCTXT* pctxt, ItemType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_ItemType (ItemType* pvalue);

/**************************************************************/
/*                                                            */
/*  TaxAmountType                                             */
/*                                                            */
/**************************************************************/

#define TV_TaxAmountType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN TaxAmountType {
   struct {
      unsigned taxableAmountPresent : 1;
   } m;
   CCT_AmountType taxableAmount;
   CCT_AmountType taxAmount;
} TaxAmountType;

EXTERN int asn1E_TaxAmountType (OSCTXT* pctxt,
   TaxAmountType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_TaxAmountType (OSCTXT* pctxt, TaxAmountType *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_TaxAmountType (OSCTXT* pctxt, TaxAmountType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_TaxAmountType (OSCTXT* pctxt, TaxAmountType* pvalue);

EXTERN int DOMTest_TaxAmountType (OSCTXT* pctxt, TaxAmountType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_TaxAmountType (TaxAmountType* pvalue);

/**************************************************************/
/*                                                            */
/*  TaxType                                                   */
/*                                                            */
/**************************************************************/

#define TV_TaxType	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN TaxType {
   CCT_CodeType typeCode;
   CCT_NumericType ratePercent;
   TaxAmountType taxAmount;
} TaxType;

EXTERN int asn1E_TaxType (OSCTXT* pctxt,
   TaxType *pvalue, ASN1TagType tagging);

EXTERN int asn1D_TaxType (OSCTXT* pctxt, TaxType *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc_TaxType (OSCTXT* pctxt, TaxType* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_TaxType (OSCTXT* pctxt, TaxType* pvalue);

EXTERN int DOMTest_TaxType (OSCTXT* pctxt, TaxType* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_TaxType (TaxType* pvalue);

/**
 * Global element functions.  These functions encode or decode complete
 * XML documents.  They are generated for XSD global elements and/or
 * ASN.1 type definitions that are either:
 *
 * 1) not referenced by any other types, or
 * 2) explicitly declared to be a PDU using the -pdu command line
 *    option, or
 * 3) explicitly declared to be a PDU using the <isPDU/> 
 *    configuration file element.
 */
EXTERN int XmlEnc_QuoteType_PDU (OSCTXT* pctxt, QuoteType* pvalue);

EXTERN int XmlDec_QuoteType_PDU (OSCTXT* pctxt, QuoteType* pvalue);

EXTERN int XmlEnc_ContractType_PDU (OSCTXT* pctxt, ContractType* pvalue);

EXTERN int XmlDec_ContractType_PDU (OSCTXT* pctxt, ContractType* pvalue);

#ifdef __cplusplus
}
#endif

#endif
