/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#include "asn1intl.h"
#include "UBL-CoreComponentTypes-1-0.h"
#include "rtxsrc/rtxCommon.h"

#include "rtxmlsrc/osrtxml.h"

const OSXMLNamespace g_UBL_CoreComponentTypes_1_0_NSTable[] = {
   { "ccts", "urn:oasis:names:specification:ubl:schema:xsd:CoreComponentParameters-1.0" },
   { "", "urn:oasis:names:specification:ubl:schema:xsd:CoreComponentTypes-1.0" },
} ;

/**************************************************************/
/*                                                            */
/*  DateTimeType                                              */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  IndicatorType                                             */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  NumericType                                               */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  AmountType                                                */
/*                                                            */
/**************************************************************/

void asn1Init_AmountType (AmountType* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->amountCurrencyCodeListVersionID = 0;
   pvalue->amountCurrencyID = 0;
}

/**************************************************************/
/*                                                            */
/*  BinaryObjectType                                          */
/*                                                            */
/**************************************************************/

void asn1Init_BinaryObjectType (BinaryObjectType* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->uRI = 0;
   pvalue->characterSetCode = 0;
   pvalue->encodingCode = 0;
   pvalue->filename = 0;
   pvalue->format = 0;
   pvalue->mimeCode = 0;
   pvalue->base.numocts = 0;
   pvalue->base.data = 0;
}

/**************************************************************/
/*                                                            */
/*  CodeType                                                  */
/*                                                            */
/**************************************************************/

void asn1Init_CodeType (CodeType* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->codeListAgencyID = 0;
   pvalue->codeListAgencyName = 0;
   pvalue->codeListID = 0;
   pvalue->codeListName = 0;
   pvalue->codeListSchemeURI = 0;
   pvalue->codeListURI = 0;
   pvalue->codeListVersionID = 0;
   pvalue->languageID = 0;
   pvalue->name = 0;
   pvalue->base = 0;
}

/**************************************************************/
/*                                                            */
/*  IdentifierType                                            */
/*                                                            */
/**************************************************************/

void asn1Init_IdentifierType (IdentifierType* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->identificationSchemeAgencyID = 0;
   pvalue->identificationSchemeAgencyName = 0;
   pvalue->identificationSchemeDataURI = 0;
   pvalue->identificationSchemeID = 0;
   pvalue->identificationSchemeName = 0;
   pvalue->identificationSchemeURI = 0;
   pvalue->identificationSchemeVersionID = 0;
   pvalue->base = 0;
}

/**************************************************************/
/*                                                            */
/*  MeasureType                                               */
/*                                                            */
/**************************************************************/

void asn1Init_MeasureType (MeasureType* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->measureUnitCode = 0;
   pvalue->measureUnitCodeListVersionID = 0;
}

/**************************************************************/
/*                                                            */
/*  QuantityType                                              */
/*                                                            */
/**************************************************************/

void asn1Init_QuantityType (QuantityType* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->quantityUnitCode = 0;
   pvalue->quantityUnitCodeListAgencyID = 0;
   pvalue->quantityUnitCodeListAgencyName = 0;
   pvalue->quantityUnitCodeListID = 0;
}

/**************************************************************/
/*                                                            */
/*  TextType                                                  */
/*                                                            */
/**************************************************************/

void asn1Init_TextType (TextType* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->languageID = 0;
   pvalue->languageLocaleID = 0;
   pvalue->base = 0;
}
