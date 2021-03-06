/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Ns2.h"
#include "rtxsrc/rtxCommon.h"

#include "rtxmlsrc/osrtxml.h"

const OSXMLNamespace g_Ns2_NSTable[] = {
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
/*  Config_item_type                                          */
/*                                                            */
/**************************************************************/

static const OSEnumItem Config_item_type_ENUMTAB[] = {
   { OSUTF8("base64Binary"), 0, 12, 0 },
   { OSUTF8("boolean"), 1, 7, 1 },
   { OSUTF8("datetime"), 2, 8, 2 },
   { OSUTF8("double"), 3, 6, 3 },
   { OSUTF8("int"), 4, 3, 4 },
   { OSUTF8("long"), 5, 4, 5 },
   { OSUTF8("short"), 6, 5, 6 },
   { OSUTF8("string"), 7, 6, 7 }
} ;
#define Config_item_type_ENUMTABSIZE 8

const OSUTF8CHAR* Config_item_type_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Config_item_type_ENUMTABSIZE) {
      return Config_item_type_ENUMTAB
         [Config_item_type_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Config_item_type_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Config_item_type* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Config_item_type_ENUMTAB, 
      Config_item_type_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Config_item_type)Config_item_type_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  Config_item                                               */
/*                                                            */
/**************************************************************/

void asn1Init_Config_item (Config_item* pvalue)
{
   if (0 == pvalue) return;
   pvalue->name = 0;
}

/**************************************************************/
/*                                                            */
/*  Config_item_map_indexed                                   */
/*                                                            */
/**************************************************************/

void asn1Init_Config_item_map_indexed (Config_item_map_indexed* pvalue)
{
   if (0 == pvalue) return;
   pvalue->name = 0;
   rtxDListFastInit (&pvalue->config_item_map_entry_list);
}

/**************************************************************/
/*                                                            */
/*  Config_item_map_entry_element                             */
/*                                                            */
/**************************************************************/

void asn1Init_Config_item_map_entry_element (
   Config_item_map_entry_element* pvalue)
{
   if (0 == pvalue) return;
   pvalue->t = 0;
   memset (&pvalue->u, 0, sizeof(pvalue->u));
}

/**************************************************************/
/*                                                            */
/*  Config_item_map_entry                                     */
/*                                                            */
/**************************************************************/

void asn1Init_Config_item_map_entry (Config_item_map_entry* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->name = 0;
   rtxDListFastInit (&pvalue->choice_list);
}

/**************************************************************/
/*                                                            */
/*  Config_item_map_named                                     */
/*                                                            */
/**************************************************************/

void asn1Init_Config_item_map_named (Config_item_map_named* pvalue)
{
   if (0 == pvalue) return;
   pvalue->name = 0;
   rtxDListFastInit (&pvalue->config_item_map_entry_list);
}

/**************************************************************/
/*                                                            */
/*  Config_item_set_element                                   */
/*                                                            */
/**************************************************************/

void asn1Init_Config_item_set_element (Config_item_set_element* pvalue)
{
   if (0 == pvalue) return;
   pvalue->t = 0;
   memset (&pvalue->u, 0, sizeof(pvalue->u));
}

/**************************************************************/
/*                                                            */
/*  Config_item_set                                           */
/*                                                            */
/**************************************************************/

void asn1Init_Config_item_set (Config_item_set* pvalue)
{
   if (0 == pvalue) return;
   pvalue->name = 0;
   rtxDListFastInit (&pvalue->choice_list);
}

