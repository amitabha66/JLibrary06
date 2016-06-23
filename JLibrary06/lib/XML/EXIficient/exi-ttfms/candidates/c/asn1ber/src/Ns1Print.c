/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 17-Oct-2006.
 */
#include "Ns1.h"
#include "rtsrc/rtPrint.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  Country                                                   */
/*                                                            */
/**************************************************************/

void asn1Print_Country
   (const char* name, Country pvalue)
{
   rtPrintIndent ();
   rtxPrintUTF8CharStr (name, pvalue);
}

/**************************************************************/
/*                                                            */
/*  Language                                                  */
/*                                                            */
/**************************************************************/

void asn1Print_Ns1_Language
   (const char* name, Ns1_Language pvalue)
{
   rtPrintIndent ();
   rtxPrintUTF8CharStr (name, pvalue);
}

/**************************************************************/
/*                                                            */
/*  Max_height                                                */
/*                                                            */
/**************************************************************/

void asn1Print_Max_height
   (const char* name, Max_height* pvalue)
{
   rtPrintOpenBrace (name);

   switch (pvalue->t) {
      case 1: {
         rtPrintIndent ();
         rtxPrintUTF8CharStr ("alt", pvalue->u.alt);
         break;
      }
      case 2: {
         rtPrintIndent ();
         rtxPrintUTF8CharStr ("alt_1", pvalue->u.alt_1);
         break;
      }
      default:;
   }

   rtPrintCloseBrace ();
}

/**************************************************************/
/*                                                            */
/*  Max_width                                                 */
/*                                                            */
/**************************************************************/

void asn1Print_Max_width
   (const char* name, Max_width* pvalue)
{
   rtPrintOpenBrace (name);

   switch (pvalue->t) {
      case 1: {
         rtPrintIndent ();
         rtxPrintUTF8CharStr ("alt", pvalue->u.alt);
         break;
      }
      case 2: {
         rtPrintIndent ();
         rtxPrintUTF8CharStr ("alt_1", pvalue->u.alt_1);
         break;
      }
      default:;
   }

   rtPrintCloseBrace ();
}

/**************************************************************/
/*                                                            */
/*  Min_height                                                */
/*                                                            */
/**************************************************************/

void asn1Print_Min_height
   (const char* name, Min_height* pvalue)
{
   rtPrintOpenBrace (name);

   switch (pvalue->t) {
      case 1: {
         rtPrintIndent ();
         rtxPrintUTF8CharStr ("alt", pvalue->u.alt);
         break;
      }
      case 2: {
         rtPrintIndent ();
         rtxPrintUTF8CharStr ("alt_1", pvalue->u.alt_1);
         break;
      }
      default:;
   }

   rtPrintCloseBrace ();
}

/**************************************************************/
/*                                                            */
/*  Min_width                                                 */
/*                                                            */
/**************************************************************/

void asn1Print_Min_width
   (const char* name, Min_width* pvalue)
{
   rtPrintOpenBrace (name);

   switch (pvalue->t) {
      case 1: {
         rtPrintIndent ();
         rtxPrintUTF8CharStr ("alt", pvalue->u.alt);
         break;
      }
      case 2: {
         rtPrintIndent ();
         rtxPrintUTF8CharStr ("alt_1", pvalue->u.alt_1);
         break;
      }
      default:;
   }

   rtPrintCloseBrace ();
}
