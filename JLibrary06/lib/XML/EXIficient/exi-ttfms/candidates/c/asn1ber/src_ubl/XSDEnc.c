/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 21-Feb-2006.
 */
#include "asn1intl.h"
#include "XSD.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  XMLCompatibleString                                       */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_XMLCompatibleString (OSCTXT* pctxt,
   XMLCompatibleString *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, *pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  String                                                    */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_String (OSCTXT* pctxt,
   String *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_XMLCompatibleString (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  NormalizedString                                          */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_NormalizedString (OSCTXT* pctxt,
   NormalizedString *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_String (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  XMLStringWithNoCRLFHT                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_XMLStringWithNoCRLFHT (OSCTXT* pctxt,
   XMLStringWithNoCRLFHT *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, *pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  AnyURI                                                    */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_AnyURI (OSCTXT* pctxt,
   AnyURI *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_XMLStringWithNoCRLFHT (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Language                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_XSD_Language (OSCTXT* pctxt,
   XSD_Language *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_charstr (pctxt, *pvalue, tagging, TM_UNIV|TM_PRIM|26);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  DATE_TIME                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_DATE_TIME (OSCTXT* pctxt,
   DATE_TIME *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_charstr (pctxt, *pvalue, tagging, TM_UNIV|TM_PRIM|26);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  DateTime                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_XSD_DateTime (OSCTXT* pctxt,
   XSD_DateTime *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Date                                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_XSD_Date (OSCTXT* pctxt,
   XSD_Date *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Time                                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Time (OSCTXT* pctxt,
   Time *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  AnySimpleType                                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_AnySimpleType (OSCTXT* pctxt,
   AnySimpleType *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_XMLCompatibleString (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Base64Binary                                              */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Base64Binary (OSCTXT* pctxt,
   Base64Binary *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_octstr (pctxt, pvalue->data, pvalue->numocts, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Boolean                                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Boolean (OSCTXT* pctxt,
   Boolean *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_boolean (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Byte                                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Byte (OSCTXT* pctxt,
   Byte *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_int8 (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Decimal                                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Decimal (OSCTXT* pctxt,
   Decimal *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_real (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Double                                                    */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Double (OSCTXT* pctxt,
   Double *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_real (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  DURATION                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_DURATION (OSCTXT* pctxt,
   DURATION *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_charstr (pctxt, *pvalue, tagging, TM_UNIV|TM_PRIM|26);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Duration                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Duration (OSCTXT* pctxt,
   Duration *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DURATION (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Token                                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Token (OSCTXT* pctxt,
   Token *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_NormalizedString (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Name                                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_XSD_Name (OSCTXT* pctxt,
   XSD_Name *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_Token (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  NCName                                                    */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_NCName (OSCTXT* pctxt,
   NCName *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_XSD_Name (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  ENTITY                                                    */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_ENTITY (OSCTXT* pctxt,
   ENTITY *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_NCName (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Float                                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Float (OSCTXT* pctxt,
   Float *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_real (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  GDay                                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_GDay (OSCTXT* pctxt,
   GDay *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  GMonth                                                    */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_GMonth (OSCTXT* pctxt,
   GMonth *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  GMonthDay                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_GMonthDay (OSCTXT* pctxt,
   GMonthDay *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  GYear                                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_GYear (OSCTXT* pctxt,
   GYear *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  GYearMonth                                                */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_GYearMonth (OSCTXT* pctxt,
   GYearMonth *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  HexBinary                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_HexBinary (OSCTXT* pctxt,
   HexBinary *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_octstr (pctxt, pvalue->data, pvalue->numocts, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  ID                                                        */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_ID (OSCTXT* pctxt,
   ID *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_NCName (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  IDREF                                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_IDREF (OSCTXT* pctxt,
   IDREF *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_NCName (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Int                                                       */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Int (OSCTXT* pctxt,
   Int *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_integer (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Integer                                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Integer (OSCTXT* pctxt,
   Integer *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_integer (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Long                                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Long (OSCTXT* pctxt,
   Long *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_int64 (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  NegativeInteger                                           */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_NegativeInteger (OSCTXT* pctxt,
   NegativeInteger *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if (!(*pvalue <= -1)) {
      rtxErrAddStrParm (pctxt, "NegativeInteger");
      rtxErrAddIntParm (pctxt, (int)*pvalue);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   ll = xe_integer (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  NMTOKEN                                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_NMTOKEN (OSCTXT* pctxt,
   NMTOKEN *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_Token (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  NonNegativeInteger                                        */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_NonNegativeInteger (OSCTXT* pctxt,
   NonNegativeInteger *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if (!(*pvalue >= 0)) {
      rtxErrAddStrParm (pctxt, "NonNegativeInteger");
      rtxErrAddIntParm (pctxt, (int)*pvalue);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   ll = xe_unsigned (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  NonPositiveInteger                                        */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_NonPositiveInteger (OSCTXT* pctxt,
   NonPositiveInteger *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if (!(*pvalue <= 0)) {
      rtxErrAddStrParm (pctxt, "NonPositiveInteger");
      rtxErrAddIntParm (pctxt, (int)*pvalue);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   ll = xe_integer (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  QName                                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_QName (OSCTXT* pctxt,
   QName *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   /* encode name */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|1,
      asn1E_NCName (pctxt, &pvalue->name, ASN1IMPL));
   if (ll >= 0) ll1 += ll; else return LOG_RTERR (pctxt, ll);

   /* encode uri */

   if (pvalue->m.uriPresent) {
      ll = xe_tag_len (pctxt, TM_CTXT|TM_PRIM|0,
         asn1E_AnyURI (pctxt, &pvalue->uri, ASN1IMPL));
      if (ll >= 0) ll1 += ll; else return LOG_RTERR (pctxt, ll);
   }
   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  NOTATION                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_NOTATION (OSCTXT* pctxt,
   NOTATION *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_QName (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  PositiveInteger                                           */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_PositiveInteger (OSCTXT* pctxt,
   PositiveInteger *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if (!(*pvalue >= 1)) {
      rtxErrAddStrParm (pctxt, "PositiveInteger");
      rtxErrAddIntParm (pctxt, (int)*pvalue);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   ll = xe_unsigned (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Short                                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Short (OSCTXT* pctxt,
   Short *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_int16 (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  UnsignedByte                                              */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_UnsignedByte (OSCTXT* pctxt,
   UnsignedByte *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_uint8 (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  UnsignedInt                                               */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_UnsignedInt (OSCTXT* pctxt,
   UnsignedInt *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_unsigned (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  UnsignedLong                                              */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_UnsignedLong (OSCTXT* pctxt,
   UnsignedLong *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_uint64 (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  UnsignedShort                                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_UnsignedShort (OSCTXT* pctxt,
   UnsignedShort *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_uint16 (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  XMLStringWithNoWhitespace                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_XMLStringWithNoWhitespace (OSCTXT* pctxt,
   XMLStringWithNoWhitespace *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, *pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  DateOnly                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_DateOnly (OSCTXT* pctxt,
   DateOnly *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Day                                                       */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Day (OSCTXT* pctxt,
   Day *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Month                                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Month (OSCTXT* pctxt,
   Month *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  MonthDay                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_MonthDay (OSCTXT* pctxt,
   MonthDay *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  Year                                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Year (OSCTXT* pctxt,
   Year *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  YearMonth                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_YearMonth (OSCTXT* pctxt,
   YearMonth *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  TimeOnly                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_TimeOnly (OSCTXT* pctxt,
   TimeOnly *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = asn1E_DATE_TIME (pctxt, pvalue, tagging);
   if (ll >= 0) ll0 += ll; else return LOG_RTERR (pctxt, ll);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  _SeqOfString                                              */
/*                                                            */
/**************************************************************/

EXTERN int asn1E__SeqOfString (OSCTXT* pctxt,
   _SeqOfString *pvalue, ASN1TagType tagging)
{
   int xx1;
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   for (xx1 = (pvalue->n - 1); xx1 >= 0; xx1--)
   {
      ll = asn1E_String (pctxt, &pvalue->elem[xx1], ASN1EXPL);
      if (ll >= 0) ll1 += ll; else return LOG_RTERR (pctxt, ll);
   }
   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  AnyType                                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_AnyType (OSCTXT* pctxt,
   AnyType *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   /* encode elem_list */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|2,
      asn1E__SeqOfString (pctxt, &pvalue->elem_list, ASN1IMPL));
   if (ll >= 0) ll1 += ll; else return LOG_RTERR (pctxt, ll);

   /* encode attr */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|1,
      asn1E__SeqOfString (pctxt, &pvalue->attr, ASN1IMPL));
   if (ll >= 0) ll1 += ll; else return LOG_RTERR (pctxt, ll);

   /* encode embed_values */

   ll = xe_tag_len (pctxt, TM_CTXT|TM_CONS|0,
      asn1E__SeqOfString (pctxt, &pvalue->embed_values, ASN1IMPL));
   if (ll >= 0) ll1 += ll; else return LOG_RTERR (pctxt, ll);

   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  ENTITIES                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_ENTITIES (OSCTXT* pctxt,
   ENTITIES *pvalue, ASN1TagType tagging)
{
   int xx1;
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   if (!(pvalue->n >= 1)) {
      rtxErrAddStrParm (pctxt, "ENTITIES.n");
      rtxErrAddIntParm (pctxt, (int)pvalue->n);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   for (xx1 = (pvalue->n - 1); xx1 >= 0; xx1--)
   {
      ll = asn1E_ENTITY (pctxt, &pvalue->elem[xx1], ASN1EXPL);
      if (ll >= 0) ll1 += ll; else return LOG_RTERR (pctxt, ll);
   }
   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  IDREFS                                                    */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_IDREFS (OSCTXT* pctxt,
   IDREFS *pvalue, ASN1TagType tagging)
{
   int xx1;
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   if (!(pvalue->n >= 1)) {
      rtxErrAddStrParm (pctxt, "IDREFS.n");
      rtxErrAddIntParm (pctxt, (int)pvalue->n);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   for (xx1 = (pvalue->n - 1); xx1 >= 0; xx1--)
   {
      ll = asn1E_IDREF (pctxt, &pvalue->elem[xx1], ASN1EXPL);
      if (ll >= 0) ll1 += ll; else return LOG_RTERR (pctxt, ll);
   }
   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}

/**************************************************************/
/*                                                            */
/*  NMTOKENS                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_NMTOKENS (OSCTXT* pctxt,
   NMTOKENS *pvalue, ASN1TagType tagging)
{
   int xx1;
   int ll;
   int ll0 = 0;
   int ll1 = 0;

   if (!(pvalue->n >= 1)) {
      rtxErrAddStrParm (pctxt, "NMTOKENS.n");
      rtxErrAddIntParm (pctxt, (int)pvalue->n);
      return LOG_RTERR (pctxt, RTERR_CONSVIO);
   }

   for (xx1 = (pvalue->n - 1); xx1 >= 0; xx1--)
   {
      ll = asn1E_NMTOKEN (pctxt, &pvalue->elem[xx1], ASN1EXPL);
      if (ll >= 0) ll1 += ll; else return LOG_RTERR (pctxt, ll);
   }
   ll0 += ll1;

   if (tagging == ASN1EXPL)
      ll0 = xe_tag_len (pctxt, TM_UNIV|TM_CONS|16, ll0);

   return (ll0);
}
