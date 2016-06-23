/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Ns11.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  Accumulate                                                */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_Accumulate (OSCTXT* pctxt,
   Ns11_Accumulate *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if(*pvalue < 0 || *pvalue > 1)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_enum (pctxt, (OSINT32*)pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_Accumulate (OSCTXT* pctxt, Ns11_Accumulate value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt,
      Ns11_Accumulate_ToString (value), elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Additive                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_Additive (OSCTXT* pctxt,
   Ns11_Additive *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if(*pvalue < 0 || *pvalue > 1)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_enum (pctxt, (OSINT32*)pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_Additive (OSCTXT* pctxt, Ns11_Additive value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt,
      Ns11_Additive_ToString (value), elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  AttributeName                                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_AttributeName (OSCTXT* pctxt,
   Ns11_AttributeName pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_AttributeName (OSCTXT* pctxt, Ns11_AttributeName value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  By                                                        */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_By (OSCTXT* pctxt,
   Ns11_By pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_By (OSCTXT* pctxt, Ns11_By value, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  CalcMode                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_CalcMode (OSCTXT* pctxt,
   Ns11_CalcMode *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if(*pvalue < 0 || *pvalue > 3)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_enum (pctxt, (OSINT32*)pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_CalcMode (OSCTXT* pctxt, Ns11_CalcMode value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt,
      Ns11_CalcMode_ToString (value), elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Fill                                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_Fill (OSCTXT* pctxt,
   Ns11_Fill *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if(*pvalue < 0 || *pvalue > 5)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_enum (pctxt, (OSINT32*)pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_Fill (OSCTXT* pctxt, Ns11_Fill value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt,
      Ns11_Fill_ToString (value), elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  From                                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_From (OSCTXT* pctxt,
   Ns11_From pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_From (OSCTXT* pctxt, Ns11_From value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  KeySplines                                                */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_KeySplines (OSCTXT* pctxt,
   Ns11_KeySplines pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_KeySplines (OSCTXT* pctxt, Ns11_KeySplines value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  KeyTimes                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_KeyTimes (OSCTXT* pctxt,
   Ns11_KeyTimes pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_KeyTimes (OSCTXT* pctxt, Ns11_KeyTimes value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  RepeatCount                                               */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_RepeatCount (OSCTXT* pctxt,
   Ns11_RepeatCount *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_unsigned (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_RepeatCount (OSCTXT* pctxt, Ns11_RepeatCount value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUInt (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  RepeatDur                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_RepeatDur (OSCTXT* pctxt,
   Ns11_RepeatDur pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_RepeatDur (OSCTXT* pctxt, Ns11_RepeatDur value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  TargetElement                                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_TargetElement (OSCTXT* pctxt,
   Ns11_TargetElement pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_TargetElement (OSCTXT* pctxt, Ns11_TargetElement value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  To                                                        */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_To (OSCTXT* pctxt,
   Ns11_To pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_To (OSCTXT* pctxt, Ns11_To value, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Values                                                    */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_Values (OSCTXT* pctxt,
   Ns11_Values pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_Values (OSCTXT* pctxt, Ns11_Values value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Direction                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_Direction (OSCTXT* pctxt,
   Ns11_Direction *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if(*pvalue < 0 || *pvalue > 1)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_enum (pctxt, (OSINT32*)pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_Direction (OSCTXT* pctxt, Ns11_Direction value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt,
      Ns11_Direction_ToString (value), elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  FadeColor                                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_FadeColor (OSCTXT* pctxt,
   Ns11_FadeColor *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if(*pvalue < 0 || *pvalue > 1)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_enum (pctxt, (OSINT32*)pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_FadeColor (OSCTXT* pctxt, Ns11_FadeColor value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt,
      Ns11_FadeColor_ToString (value), elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Mode                                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_Mode (OSCTXT* pctxt,
   Ns11_Mode *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if(*pvalue < 0 || *pvalue > 1)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_enum (pctxt, (OSINT32*)pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_Mode (OSCTXT* pctxt, Ns11_Mode value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt,
      Ns11_Mode_ToString (value), elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Subtype                                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_Subtype (OSCTXT* pctxt,
   Ns11_Subtype pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_Subtype (OSCTXT* pctxt, Ns11_Subtype value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Type                                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_Type (OSCTXT* pctxt,
   Ns11_Type pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_Type (OSCTXT* pctxt, Ns11_Type value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Accelerate                                                */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_Accelerate (OSCTXT* pctxt,
   Ns11_Accelerate *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_real (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_Accelerate (OSCTXT* pctxt, Ns11_Accelerate value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncDouble (pctxt, value, elemName, nsPrefix, 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  AutoReverse                                               */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_AutoReverse (OSCTXT* pctxt,
   Ns11_AutoReverse *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if(*pvalue < 0 || *pvalue > 1)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_enum (pctxt, (OSINT32*)pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_AutoReverse (OSCTXT* pctxt, Ns11_AutoReverse value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt,
      Ns11_AutoReverse_ToString (value), elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Begin                                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_Begin (OSCTXT* pctxt,
   Ns11_Begin pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_Begin (OSCTXT* pctxt, Ns11_Begin value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Decelerate                                                */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_Decelerate (OSCTXT* pctxt,
   Ns11_Decelerate *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_real (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_Decelerate (OSCTXT* pctxt, Ns11_Decelerate value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncDouble (pctxt, value, elemName, nsPrefix, 0);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Dur                                                       */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_Dur (OSCTXT* pctxt,
   Ns11_Dur pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_Dur (OSCTXT* pctxt, Ns11_Dur value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  End                                                       */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_End (OSCTXT* pctxt,
   Ns11_End pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   ll = xe_utf8str (pctxt, pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_End (OSCTXT* pctxt, Ns11_End value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt, value, elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Endsync                                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_Endsync (OSCTXT* pctxt,
   Ns11_Endsync *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if(*pvalue < 0 || *pvalue > 3)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_enum (pctxt, (OSINT32*)pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_Endsync (OSCTXT* pctxt, Ns11_Endsync value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt,
      Ns11_Endsync_ToString (value), elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  FillDefault                                               */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_FillDefault (OSCTXT* pctxt,
   Ns11_FillDefault *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if(*pvalue < 0 || *pvalue > 5)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_enum (pctxt, (OSINT32*)pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_FillDefault (OSCTXT* pctxt, Ns11_FillDefault value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt,
      Ns11_FillDefault_ToString (value), elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Restart                                                   */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_Restart (OSCTXT* pctxt,
   Ns11_Restart *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if(*pvalue < 0 || *pvalue > 3)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_enum (pctxt, (OSINT32*)pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_Restart (OSCTXT* pctxt, Ns11_Restart value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt,
      Ns11_Restart_ToString (value), elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  RestartDefault                                            */
/*                                                            */
/**************************************************************/

EXTERN int asn1E_Ns11_RestartDefault (OSCTXT* pctxt,
   Ns11_RestartDefault *pvalue, ASN1TagType tagging)
{
   int ll;
   int ll0 = 0;

   if(*pvalue < 0 || *pvalue > 3)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   ll = xe_enum (pctxt, (OSINT32*)pvalue, tagging);
   if (ll < 0) return LOG_RTERR (pctxt, ll);
   ll0 += ll;

   return (ll0);
}

int XmlEnc_Ns11_RestartDefault (OSCTXT* pctxt, Ns11_RestartDefault value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix)
{
   int stat = 0;

   stat = rtXmlEncUTF8Str (pctxt,
      Ns11_RestartDefault_ToString (value), elemName, nsPrefix);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

