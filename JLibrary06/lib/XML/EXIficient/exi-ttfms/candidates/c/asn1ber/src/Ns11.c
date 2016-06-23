/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Ns11.h"
#include "rtxsrc/rtxCommon.h"

#include "rtxmlsrc/osrtxml.h"

const OSXMLNamespace g_Ns11_NSTable[] = {
   { OSUTF8("ns1"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:xsl-fo-compatible:1.0") },
   { OSUTF8("ns2"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:config:1.0") },
   { OSUTF8("ns3"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:drawing:1.0") },
   { OSUTF8("xlink"), OSUTF8("http://www.w3.org/1999/xlink") },
   { OSUTF8("ns4"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:form:1.0") },
   { OSUTF8("ns5"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:chart:1.0") },
   { OSUTF8("ns6"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:script:1.0") },
   { OSUTF8("ns7"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:dr3d:1.0") },
   { OSUTF8("ns8"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:style:1.0") },
   { OSUTF8("ns9"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:animation:1.0") },
   { OSUTF8("ns10"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:presentation:1.0") },
   { OSUTF8("ns11"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:smil-compatible:1.0") },
   { OSUTF8("xforms"), OSUTF8("http://www.w3.org/2002/xforms") },
   { OSUTF8("ns12"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:svg-compatible:1.0") },
   { OSUTF8("ns13"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:office:1.0") },
   { OSUTF8("ns14"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:datastyle:1.0") },
   { OSUTF8("ns15"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:table:1.0") },
   { OSUTF8("mathml"), OSUTF8("http://www.w3.org/1998/Math/MathML") },
   { OSUTF8("ns17"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:text:1.0") },
   { OSUTF8("ns16"), OSUTF8("urn:oasis:names:tc:opendocument:xmlns:meta:1.0") },
   { OSUTF8("elements"), OSUTF8("http://purl.org/dc/elements/1.1/") },
   { OSUTF8(""), OSUTF8("") }
} ;

/**************************************************************/
/*                                                            */
/*  Accumulate                                                */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns11_Accumulate_ENUMTAB[] = {
   { OSUTF8("none"), 0, 4, 0 },
   { OSUTF8("sum"), 1, 3, 1 }
} ;
#define Ns11_Accumulate_ENUMTABSIZE 2

const OSUTF8CHAR* Ns11_Accumulate_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns11_Accumulate_ENUMTABSIZE) {
      return Ns11_Accumulate_ENUMTAB
         [Ns11_Accumulate_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns11_Accumulate_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns11_Accumulate* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns11_Accumulate_ENUMTAB, 
      Ns11_Accumulate_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns11_Accumulate)Ns11_Accumulate_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  Additive                                                  */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns11_Additive_ENUMTAB[] = {
   { OSUTF8("replace"), 0, 7, 0 },
   { OSUTF8("sum"), 1, 3, 1 }
} ;
#define Ns11_Additive_ENUMTABSIZE 2

const OSUTF8CHAR* Ns11_Additive_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns11_Additive_ENUMTABSIZE) {
      return Ns11_Additive_ENUMTAB[Ns11_Additive_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns11_Additive_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns11_Additive* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns11_Additive_ENUMTAB, 
      Ns11_Additive_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns11_Additive)Ns11_Additive_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  AttributeName                                             */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  By                                                        */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  CalcMode                                                  */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns11_CalcMode_ENUMTAB[] = {
   { OSUTF8("discrete"), 0, 8, 0 },
   { OSUTF8("linear"), 1, 6, 1 },
   { OSUTF8("paced"), 2, 5, 2 },
   { OSUTF8("spline"), 3, 6, 3 }
} ;
#define Ns11_CalcMode_ENUMTABSIZE 4

const OSUTF8CHAR* Ns11_CalcMode_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns11_CalcMode_ENUMTABSIZE) {
      return Ns11_CalcMode_ENUMTAB[Ns11_CalcMode_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns11_CalcMode_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns11_CalcMode* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns11_CalcMode_ENUMTAB, 
      Ns11_CalcMode_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns11_CalcMode)Ns11_CalcMode_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  Fill                                                      */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns11_Fill_ENUMTAB[] = {
   { OSUTF8("auto"), 0, 4, 0 },
   { OSUTF8("default"), 1, 7, 1 },
   { OSUTF8("freeze"), 2, 6, 2 },
   { OSUTF8("hold"), 3, 4, 3 },
   { OSUTF8("remove"), 4, 6, 4 },
   { OSUTF8("transition"), 5, 10, 5 }
} ;
#define Ns11_Fill_ENUMTABSIZE 6

const OSUTF8CHAR* Ns11_Fill_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns11_Fill_ENUMTABSIZE) {
      return Ns11_Fill_ENUMTAB[Ns11_Fill_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns11_Fill_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns11_Fill* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns11_Fill_ENUMTAB, 
      Ns11_Fill_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns11_Fill)Ns11_Fill_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  From                                                      */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  KeySplines                                                */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  KeyTimes                                                  */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  RepeatCount                                               */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  RepeatDur                                                 */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  TargetElement                                             */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  To                                                        */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Values                                                    */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Direction                                                 */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns11_Direction_ENUMTAB[] = {
   { OSUTF8("forward"), 0, 7, 0 },
   { OSUTF8("reverse"), 1, 7, 1 }
} ;
#define Ns11_Direction_ENUMTABSIZE 2

const OSUTF8CHAR* Ns11_Direction_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns11_Direction_ENUMTABSIZE) {
      return Ns11_Direction_ENUMTAB
         [Ns11_Direction_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns11_Direction_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns11_Direction* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns11_Direction_ENUMTAB, 
      Ns11_Direction_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns11_Direction)Ns11_Direction_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  FadeColor                                                 */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns11_FadeColor_ENUMTAB[] = {
   { OSUTF8("forward"), 0, 7, 0 },
   { OSUTF8("reverse"), 1, 7, 1 }
} ;
#define Ns11_FadeColor_ENUMTABSIZE 2

const OSUTF8CHAR* Ns11_FadeColor_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns11_FadeColor_ENUMTABSIZE) {
      return Ns11_FadeColor_ENUMTAB
         [Ns11_FadeColor_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns11_FadeColor_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns11_FadeColor* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns11_FadeColor_ENUMTAB, 
      Ns11_FadeColor_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns11_FadeColor)Ns11_FadeColor_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  Mode                                                      */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns11_Mode_ENUMTAB[] = {
   { OSUTF8("in"), 0, 2, 0 },
   { OSUTF8("out"), 1, 3, 1 }
} ;
#define Ns11_Mode_ENUMTABSIZE 2

const OSUTF8CHAR* Ns11_Mode_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns11_Mode_ENUMTABSIZE) {
      return Ns11_Mode_ENUMTAB[Ns11_Mode_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns11_Mode_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns11_Mode* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns11_Mode_ENUMTAB, 
      Ns11_Mode_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns11_Mode)Ns11_Mode_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  Subtype                                                   */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Type                                                      */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Accelerate                                                */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  AutoReverse                                               */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns11_AutoReverse_ENUMTAB[] = {
   { OSUTF8("false"), 0, 5, 0 },
   { OSUTF8("true"), 1, 4, 1 }
} ;
#define Ns11_AutoReverse_ENUMTABSIZE 2

const OSUTF8CHAR* Ns11_AutoReverse_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns11_AutoReverse_ENUMTABSIZE) {
      return Ns11_AutoReverse_ENUMTAB
         [Ns11_AutoReverse_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns11_AutoReverse_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns11_AutoReverse* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns11_AutoReverse_ENUMTAB, 
      Ns11_AutoReverse_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns11_AutoReverse)Ns11_AutoReverse_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  Begin                                                     */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Decelerate                                                */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Dur                                                       */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  End                                                       */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Endsync                                                   */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns11_Endsync_ENUMTAB[] = {
   { OSUTF8("all"), 0, 3, 0 },
   { OSUTF8("first"), 1, 5, 1 },
   { OSUTF8("last"), 2, 4, 2 },
   { OSUTF8("media"), 3, 5, 3 }
} ;
#define Ns11_Endsync_ENUMTABSIZE 4

const OSUTF8CHAR* Ns11_Endsync_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns11_Endsync_ENUMTABSIZE) {
      return Ns11_Endsync_ENUMTAB[Ns11_Endsync_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns11_Endsync_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns11_Endsync* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns11_Endsync_ENUMTAB, 
      Ns11_Endsync_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns11_Endsync)Ns11_Endsync_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  FillDefault                                               */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns11_FillDefault_ENUMTAB[] = {
   { OSUTF8("auto"), 0, 4, 0 },
   { OSUTF8("freeze"), 1, 6, 1 },
   { OSUTF8("hold"), 2, 4, 2 },
   { OSUTF8("inherit"), 3, 7, 3 },
   { OSUTF8("remove"), 4, 6, 4 },
   { OSUTF8("transition"), 5, 10, 5 }
} ;
#define Ns11_FillDefault_ENUMTABSIZE 6

const OSUTF8CHAR* Ns11_FillDefault_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns11_FillDefault_ENUMTABSIZE) {
      return Ns11_FillDefault_ENUMTAB
         [Ns11_FillDefault_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns11_FillDefault_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns11_FillDefault* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns11_FillDefault_ENUMTAB, 
      Ns11_FillDefault_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns11_FillDefault)Ns11_FillDefault_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  Restart                                                   */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns11_Restart_ENUMTAB[] = {
   { OSUTF8("always"), 0, 6, 0 },
   { OSUTF8("default"), 1, 7, 1 },
   { OSUTF8("never"), 2, 5, 2 },
   { OSUTF8("whenNotActive"), 3, 13, 3 }
} ;
#define Ns11_Restart_ENUMTABSIZE 4

const OSUTF8CHAR* Ns11_Restart_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns11_Restart_ENUMTABSIZE) {
      return Ns11_Restart_ENUMTAB[Ns11_Restart_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns11_Restart_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns11_Restart* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns11_Restart_ENUMTAB, 
      Ns11_Restart_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns11_Restart)Ns11_Restart_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  RestartDefault                                            */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns11_RestartDefault_ENUMTAB[] = {
   { OSUTF8("always"), 0, 6, 0 },
   { OSUTF8("inherit"), 1, 7, 1 },
   { OSUTF8("never"), 2, 5, 2 },
   { OSUTF8("whenNotActive"), 3, 13, 3 }
} ;
#define Ns11_RestartDefault_ENUMTABSIZE 4

const OSUTF8CHAR* Ns11_RestartDefault_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns11_RestartDefault_ENUMTABSIZE) {
      return Ns11_RestartDefault_ENUMTAB
         [Ns11_RestartDefault_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns11_RestartDefault_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns11_RestartDefault* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns11_RestartDefault_ENUMTAB, 
      Ns11_RestartDefault_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns11_RestartDefault)Ns11_RestartDefault_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

