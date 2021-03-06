/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#ifndef DAHUT_SIGHTING_H
#define DAHUT_SIGHTING_H

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

/**
 * Header file for ASN.1 module Dahut-sighting
 */
/**************************************************************/
/*                                                            */
/*  Dahut_sighting                                            */
/*                                                            */
/**************************************************************/

#define TV_Dahut_sighting	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Dahut_sighting {
   struct {
      unsigned idPresent : 1;
      unsigned latPresent : 1;
      unsigned long_Present : 1;
   } m;
   const OSUTF8CHAR* id;
   OSREAL lat;
   OSREAL long_;
} Dahut_sighting;

EXTERN int asn1E_Dahut_sighting (OSCTXT* pctxt,
   Dahut_sighting *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Dahut_sighting (OSCTXT* pctxt, Dahut_sighting *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_Dahut_sighting (OSCTXT* pctxt, Dahut_sighting* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Dahut_sighting (OSCTXT* pctxt, Dahut_sighting* pvalue);

EXTERN int DOMTest_Dahut_sighting (OSCTXT* pctxt, Dahut_sighting* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Dahut_sighting (Dahut_sighting* pvalue);

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
EXTERN int XmlEnc_Dahut_sighting_PDU (OSCTXT* pctxt, Dahut_sighting* pvalue);

EXTERN int XmlDec_Dahut_sighting_PDU (OSCTXT* pctxt, Dahut_sighting* pvalue);

#ifdef __cplusplus
}
#endif

#endif
