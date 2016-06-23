/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#ifndef PERIODIC_H
#define PERIODIC_H

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
 * Header file for ASN.1 module Periodic
 */
/**************************************************************/
/*                                                            */
/*  PERIODIC_TABLE_aTOM_element_bOILING_POINT                 */
/*                                                            */
/**************************************************************/

#define TV_PERIODIC_TABLE_aTOM_element_bOILING_POINT	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PERIODIC_TABLE_aTOM_element_bOILING_POINT {
   const OSUTF8CHAR* uNITS;
   OSREAL base;
} PERIODIC_TABLE_aTOM_element_bOILING_POINT;

EXTERN int asn1E_PERIODIC_TABLE_aTOM_element_bOILING_POINT (OSCTXT* pctxt,
   PERIODIC_TABLE_aTOM_element_bOILING_POINT *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PERIODIC_TABLE_aTOM_element_bOILING_POINT (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_bOILING_POINT *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc_PERIODIC_TABLE_aTOM_element_bOILING_POINT (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_bOILING_POINT* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PERIODIC_TABLE_aTOM_element_bOILING_POINT (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_bOILING_POINT* pvalue);

EXTERN int DOMTest_PERIODIC_TABLE_aTOM_element_bOILING_POINT (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_bOILING_POINT* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PERIODIC_TABLE_aTOM_element_bOILING_POINT (
   PERIODIC_TABLE_aTOM_element_bOILING_POINT* pvalue);

/**************************************************************/
/*                                                            */
/*  PERIODIC_TABLE_aTOM_element_mELTING_POINT                 */
/*                                                            */
/**************************************************************/

#define TV_PERIODIC_TABLE_aTOM_element_mELTING_POINT	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PERIODIC_TABLE_aTOM_element_mELTING_POINT {
   const OSUTF8CHAR* uNITS;
   OSREAL base;
} PERIODIC_TABLE_aTOM_element_mELTING_POINT;

EXTERN int asn1E_PERIODIC_TABLE_aTOM_element_mELTING_POINT (OSCTXT* pctxt,
   PERIODIC_TABLE_aTOM_element_mELTING_POINT *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PERIODIC_TABLE_aTOM_element_mELTING_POINT (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_mELTING_POINT *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc_PERIODIC_TABLE_aTOM_element_mELTING_POINT (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_mELTING_POINT* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PERIODIC_TABLE_aTOM_element_mELTING_POINT (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_mELTING_POINT* pvalue);

EXTERN int DOMTest_PERIODIC_TABLE_aTOM_element_mELTING_POINT (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_mELTING_POINT* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PERIODIC_TABLE_aTOM_element_mELTING_POINT (
   PERIODIC_TABLE_aTOM_element_mELTING_POINT* pvalue);

/**************************************************************/
/*                                                            */
/*  PERIODIC_TABLE_aTOM_element_dENSITY                       */
/*                                                            */
/**************************************************************/

#define TV_PERIODIC_TABLE_aTOM_element_dENSITY	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PERIODIC_TABLE_aTOM_element_dENSITY {
   const OSUTF8CHAR* uNITS;
   OSREAL base;
} PERIODIC_TABLE_aTOM_element_dENSITY;

EXTERN int asn1E_PERIODIC_TABLE_aTOM_element_dENSITY (OSCTXT* pctxt,
   PERIODIC_TABLE_aTOM_element_dENSITY *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PERIODIC_TABLE_aTOM_element_dENSITY (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_dENSITY *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc_PERIODIC_TABLE_aTOM_element_dENSITY (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_dENSITY* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PERIODIC_TABLE_aTOM_element_dENSITY (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_dENSITY* pvalue);

EXTERN int DOMTest_PERIODIC_TABLE_aTOM_element_dENSITY (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_dENSITY* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PERIODIC_TABLE_aTOM_element_dENSITY (
   PERIODIC_TABLE_aTOM_element_dENSITY* pvalue);

/**************************************************************/
/*                                                            */
/*  PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS               */
/*                                                            */
/**************************************************************/

#define TV_PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS {
   const OSUTF8CHAR* uNITS;
   OSREAL base;
} PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS;

EXTERN int asn1E_PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS (OSCTXT* pctxt,
   PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc_PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS* pvalue);

EXTERN int DOMTest_PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS (
   PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS* pvalue);

/**************************************************************/
/*                                                            */
/*  PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS                 */
/*                                                            */
/**************************************************************/

#define TV_PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS {
   const OSUTF8CHAR* uNITS;
   OSREAL base;
} PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS;

EXTERN int asn1E_PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS (OSCTXT* pctxt,
   PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc_PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS* pvalue);

EXTERN int DOMTest_PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS (
   PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS* pvalue);

/**************************************************************/
/*                                                            */
/*  PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION          */
/*                                                            */
/**************************************************************/

#define TV_PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION {
   const OSUTF8CHAR* uNITS;
   OSREAL base;
} PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION;

EXTERN int asn1E_PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION (OSCTXT* pctxt,
   PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION (
   OSCTXT* pctxt, PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION 
   (OSCTXT* pctxt, PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION 
   (OSCTXT* pctxt, PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION* pvalue);

EXTERN int DOMTest_PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION (
   PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION* pvalue);

/**************************************************************/
/*                                                            */
/*  PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME                 */
/*                                                            */
/**************************************************************/

#define TV_PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME {
   const OSUTF8CHAR* uNITS;
   OSREAL base;
} PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME;

EXTERN int asn1E_PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME (OSCTXT* pctxt,
   PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc_PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME* pvalue);

EXTERN int DOMTest_PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME (
   PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME* pvalue);

/**************************************************************/
/*                                                            */
/*  PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION                */
/*                                                            */
/**************************************************************/

#define TV_PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION {
   const OSUTF8CHAR* uNITS;
   OSREAL base;
} PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION;

EXTERN int asn1E_PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION (OSCTXT* pctxt,
   PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc_PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION* pvalue);

EXTERN int DOMTest_PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION (
   PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION* pvalue);

/**************************************************************/
/*                                                            */
/*  PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY        */
/*                                                            */
/**************************************************************/

#define TV_PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY {
   const OSUTF8CHAR* uNITS;
   OSREAL base;
} PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY;

EXTERN int asn1E_PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY (OSCTXT* pctxt,
   PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY (
   OSCTXT* pctxt, PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY 
   (OSCTXT* pctxt, PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY 
   (OSCTXT* pctxt, PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY* pvalue)
   ;

EXTERN int DOMTest_PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY (
   PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY* pvalue);

/**************************************************************/
/*                                                            */
/*  PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY          */
/*                                                            */
/**************************************************************/

#define TV_PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY {
   const OSUTF8CHAR* uNITS;
   OSREAL base;
} PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY;

EXTERN int asn1E_PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY (OSCTXT* pctxt,
   PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY (
   OSCTXT* pctxt, PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY 
   (OSCTXT* pctxt, PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY 
   (OSCTXT* pctxt, PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY* pvalue);

EXTERN int DOMTest_PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY (
   PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY* pvalue);

/**************************************************************/
/*                                                            */
/*  PERIODIC_TABLE_aTOM_element                               */
/*                                                            */
/**************************************************************/

#define TV_PERIODIC_TABLE_aTOM_element	(TM_UNIV|TM_CONS|0)

/* Choice tag constants */

#define T_PERIODIC_TABLE_aTOM_element_nAME 1
#define T_PERIODIC_TABLE_aTOM_element_aTOMIC_WEIGHT 2
#define T_PERIODIC_TABLE_aTOM_element_aTOMIC_NUMBER 3
#define T_PERIODIC_TABLE_aTOM_element_oXIDATION_STATES 4
#define T_PERIODIC_TABLE_aTOM_element_bOILING_POINT 5
#define T_PERIODIC_TABLE_aTOM_element_mELTING_POINT 6
#define T_PERIODIC_TABLE_aTOM_element_sYMBOL 7
#define T_PERIODIC_TABLE_aTOM_element_dENSITY 8
#define T_PERIODIC_TABLE_aTOM_element_eLECTRON_CONFIGURATION 9
#define T_PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS 10
#define T_PERIODIC_TABLE_aTOM_element_eLECTRONEGATIVITY 11
#define T_PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS 12
#define T_PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION 13
#define T_PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME 14
#define T_PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION 15
#define T_PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY 16
#define T_PERIODIC_TABLE_aTOM_element_iONIZATION_POTENTIAL 17
#define T_PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY 18

typedef struct EXTERN PERIODIC_TABLE_aTOM_element {
   int t;
   union {
      /* t = 1 */
      const OSUTF8CHAR* nAME;
      /* t = 2 */
      OSREAL aTOMIC_WEIGHT;
      /* t = 3 */
      OSUINT8 aTOMIC_NUMBER;
      /* t = 4 */
      const OSUTF8CHAR* oXIDATION_STATES;
      /* t = 5 */
      PERIODIC_TABLE_aTOM_element_bOILING_POINT *bOILING_POINT;
      /* t = 6 */
      PERIODIC_TABLE_aTOM_element_mELTING_POINT *mELTING_POINT;
      /* t = 7 */
      const OSUTF8CHAR* sYMBOL;
      /* t = 8 */
      PERIODIC_TABLE_aTOM_element_dENSITY *dENSITY;
      /* t = 9 */
      const OSUTF8CHAR* eLECTRON_CONFIGURATION;
      /* t = 10 */
      PERIODIC_TABLE_aTOM_element_cOVALENT_RADIUS *cOVALENT_RADIUS;
      /* t = 11 */
      OSREAL eLECTRONEGATIVITY;
      /* t = 12 */
      PERIODIC_TABLE_aTOM_element_aTOMIC_RADIUS *aTOMIC_RADIUS;
      /* t = 13 */
      PERIODIC_TABLE_aTOM_element_hEAT_OF_VAPORIZATION *hEAT_OF_VAPORIZATION;
      /* t = 14 */
      PERIODIC_TABLE_aTOM_element_aTOMIC_VOLUME *aTOMIC_VOLUME;
      /* t = 15 */
      PERIODIC_TABLE_aTOM_element_hEAT_OF_FUSION *hEAT_OF_FUSION;
      /* t = 16 */
      PERIODIC_TABLE_aTOM_element_sPECIFIC_HEAT_CAPACITY *sPECIFIC_HEAT_CAPACITY;
      /* t = 17 */
      OSREAL iONIZATION_POTENTIAL;
      /* t = 18 */
      PERIODIC_TABLE_aTOM_element_tHERMAL_CONDUCTIVITY *tHERMAL_CONDUCTIVITY;
   } u;
} PERIODIC_TABLE_aTOM_element;

EXTERN int asn1E_PERIODIC_TABLE_aTOM_element (OSCTXT* pctxt,
   PERIODIC_TABLE_aTOM_element *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PERIODIC_TABLE_aTOM_element (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_PERIODIC_TABLE_aTOM_element (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PERIODIC_TABLE_aTOM_element (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element* pvalue);

EXTERN int DOMTest_PERIODIC_TABLE_aTOM_element (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM_element* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PERIODIC_TABLE_aTOM_element (PERIODIC_TABLE_aTOM_element* pvalue);

/**************************************************************/
/*                                                            */
/*  PERIODIC_TABLE_aTOM                                       */
/*                                                            */
/**************************************************************/

#define TV_PERIODIC_TABLE_aTOM	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN PERIODIC_TABLE_aTOM {
   struct {
      unsigned sTATEPresent : 1;
   } m;
   const OSUTF8CHAR* sTATE;
   /* List of PERIODIC_TABLE_aTOM_element */
   OSRTDList choice_list;
} PERIODIC_TABLE_aTOM;

EXTERN int asn1E_PERIODIC_TABLE_aTOM (OSCTXT* pctxt,
   PERIODIC_TABLE_aTOM *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PERIODIC_TABLE_aTOM (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_PERIODIC_TABLE_aTOM (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PERIODIC_TABLE_aTOM (OSCTXT* pctxt, 
   PERIODIC_TABLE_aTOM* pvalue);

EXTERN int DOMTest_PERIODIC_TABLE_aTOM (OSCTXT* pctxt, PERIODIC_TABLE_aTOM* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PERIODIC_TABLE_aTOM (PERIODIC_TABLE_aTOM* pvalue);

/**************************************************************/
/*                                                            */
/*  PERIODIC_TABLE                                            */
/*                                                            */
/**************************************************************/

#define TV_PERIODIC_TABLE	(TM_UNIV|TM_CONS|16)

/* List of PERIODIC_TABLE_aTOM */
typedef OSRTDList PERIODIC_TABLE;

EXTERN int asn1E_PERIODIC_TABLE (OSCTXT* pctxt,
   PERIODIC_TABLE *pvalue, ASN1TagType tagging);

EXTERN int asn1D_PERIODIC_TABLE (OSCTXT* pctxt, PERIODIC_TABLE *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_PERIODIC_TABLE (OSCTXT* pctxt, PERIODIC_TABLE* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_PERIODIC_TABLE (OSCTXT* pctxt, PERIODIC_TABLE* pvalue);

EXTERN int DOMTest_PERIODIC_TABLE (OSCTXT* pctxt, PERIODIC_TABLE* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_PERIODIC_TABLE (PERIODIC_TABLE* pvalue);

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
EXTERN int XmlEnc_PERIODIC_TABLE_PDU (OSCTXT* pctxt, PERIODIC_TABLE* pvalue);

EXTERN int XmlDec_PERIODIC_TABLE_PDU (OSCTXT* pctxt, PERIODIC_TABLE* pvalue);

#ifdef __cplusplus
}
#endif

#endif
