/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#include "asn1intl.h"
#include "UBL-CodeList-DocumentStatusCode-1-0.h"
#include "rtxsrc/rtxCommon.h"

#include "rtxmlsrc/osrtxml.h"

const OSXMLNamespace g_UBL_CodeList_DocumentStatusCode_1_0_NSTable[] = {
   { "", "urn:oasis:names:specification:ubl:schema:xsd:DocumentStatusCode-1.0" },
   { "ccts", "urn:oasis:names:specification:ubl:schema:xsd:CoreComponentParameters-1.0" }
} ;

/**************************************************************/
/*                                                            */
/*  DocumentStatusCodeContentType                             */
/*                                                            */
/**************************************************************/

static const OSEnumItem DocumentStatusCodeContentType_ENUMTAB[] = {
   { OSUTF8("Cancelled"), 0, 9, 0 },
   { OSUTF8("Disputed"), 1, 8, 1 },
   { OSUTF8("NoStatus"), 2, 8, 2 },
   { OSUTF8("Revised"), 3, 7, 3 }
} ;
#define DocumentStatusCodeContentType_ENUMTABSIZE 4

const OSUTF8CHAR* DocumentStatusCodeContentType_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < DocumentStatusCodeContentType_ENUMTABSIZE) {
      return DocumentStatusCodeContentType_ENUMTAB
         [DocumentStatusCodeContentType_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int DocumentStatusCodeContentType_ToEnum
  (const OSUTF8CHAR* value, DocumentStatusCodeContentType* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, 
      DocumentStatusCodeContentType_ENUMTAB, 
      DocumentStatusCodeContentType_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (DocumentStatusCodeContentType)
         DocumentStatusCodeContentType_ENUMTAB[idx].value;
      return 0;
   }
   else return RTERR_INVENUM;
}

/**************************************************************/
/*                                                            */
/*  DocumentStatusCodeType                                    */
/*                                                            */
/**************************************************************/

void asn1Init_DocumentStatusCodeType (DocumentStatusCodeType* pvalue)
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
}
