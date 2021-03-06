/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Xlink.h"
#include "rtxsrc/rtxCommon.h"

#include "rtxmlsrc/osrtxml.h"

const OSXMLNamespace g_Xlink_NSTable[] = {
   { OSUTF8("xlink"), OSUTF8("http://www.w3.org/1999/xlink") },
   { OSUTF8(""), OSUTF8("") }
} ;

/**************************************************************/
/*                                                            */
/*  Href                                                      */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Type                                                      */
/*                                                            */
/**************************************************************/

static const OSEnumItem Xlink_Type_ENUMTAB[] = {
   { OSUTF8("simple"), 0, 6, 0 }
} ;
#define Xlink_Type_ENUMTABSIZE 1

const OSUTF8CHAR* Xlink_Type_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Xlink_Type_ENUMTABSIZE) {
      return Xlink_Type_ENUMTAB[Xlink_Type_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Xlink_Type_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Xlink_Type* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Xlink_Type_ENUMTAB, 
      Xlink_Type_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Xlink_Type)Xlink_Type_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

