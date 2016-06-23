/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Ns16.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  Date_string                                               */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_Date_string (OSCTXT* pctxt, Date_string *pvalue, 
   ASN1TagType tagging, int length)
{
   int stat = 0;

   stat = xd_utf8str (pctxt, pvalue, tagging, length);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

int XmlDec_Date_string (OSCTXT* pctxt, Date_string* pvalue)
{
   int stat = 0;

   stat = rtXmlpDecDynUTF8Str (pctxt, pvalue);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

