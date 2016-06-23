/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#ifndef NS2_H
#define NS2_H

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
 * Header file for ASN.1 module Ns2
 */
/**************************************************************/
/*                                                            */
/*  Config_item_type                                          */
/*                                                            */
/**************************************************************/

#define TV_Config_item_type	(TM_UNIV|TM_PRIM|10)

typedef enum {
   type_base64Binary = 0,
   type_boolean_ = 1,
   type_datetime = 2,
   type_double_ = 3,
   type_int_ = 4,
   type_long_ = 5,
   type_short_ = 6,
   type_string = 7
} Config_item_type_Root;

typedef OSUINT32 Config_item_type;

EXTERN int asn1E_Config_item_type (OSCTXT* pctxt,
   Config_item_type *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Config_item_type (OSCTXT* pctxt, Config_item_type *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_Config_item_type (OSCTXT* pctxt, Config_item_type value, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Config_item_type (OSCTXT* pctxt, Config_item_type* pvalue);

EXTERN const OSUTF8CHAR* Config_item_type_ToString (OSINT32 value);

EXTERN int Config_item_type_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Config_item_type* pvalue);

/**************************************************************/
/*                                                            */
/*  Config_item                                               */
/*                                                            */
/**************************************************************/

#define TV_Config_item	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Config_item {
   const OSUTF8CHAR* name;
   Config_item_type type;
} Config_item;

EXTERN int asn1E_Config_item (OSCTXT* pctxt,
   Config_item *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Config_item (OSCTXT* pctxt, Config_item *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_Config_item (OSCTXT* pctxt, Config_item* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Config_item (OSCTXT* pctxt, Config_item* pvalue);

EXTERN int DOMTest_Config_item (OSCTXT* pctxt, Config_item* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Config_item (Config_item* pvalue);

/**************************************************************/
/*                                                            */
/*  Config_item_map_indexed                                   */
/*                                                            */
/**************************************************************/

#define TV_Config_item_map_indexed	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Config_item_map_indexed {
   const OSUTF8CHAR* name;
   /* List of Config_item_map_entry */
   OSRTDList config_item_map_entry_list;
} Config_item_map_indexed;

EXTERN int asn1E_Config_item_map_indexed (OSCTXT* pctxt,
   Config_item_map_indexed *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Config_item_map_indexed (OSCTXT* pctxt, 
   Config_item_map_indexed *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Config_item_map_indexed (OSCTXT* pctxt, 
   Config_item_map_indexed* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Config_item_map_indexed (OSCTXT* pctxt, 
   Config_item_map_indexed* pvalue);

EXTERN int DOMTest_Config_item_map_indexed (OSCTXT* pctxt, 
   Config_item_map_indexed* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Config_item_map_indexed (Config_item_map_indexed* pvalue);

/**************************************************************/
/*                                                            */
/*  Config_item_map_entry_element                             */
/*                                                            */
/**************************************************************/

#define TV_Config_item_map_entry_element	(TM_UNIV|TM_CONS|0)

/* Choice tag constants */

#define T_Config_item_map_entry_element_config_item 1
#define T_Config_item_map_entry_element_config_item_set 2
#define T_Config_item_map_entry_element_config_item_map_named 3
#define T_Config_item_map_entry_element_config_item_map_indexed 4

typedef struct EXTERN Config_item_map_entry_element {
   int t;
   union {
      /* t = 1 */
      Config_item *config_item;
      /* t = 2 */
      struct Config_item_set *config_item_set;
      /* t = 3 */
      struct Config_item_map_named *config_item_map_named;
      /* t = 4 */
      Config_item_map_indexed *config_item_map_indexed;
   } u;
} Config_item_map_entry_element;

EXTERN int asn1E_Config_item_map_entry_element (OSCTXT* pctxt,
   Config_item_map_entry_element *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Config_item_map_entry_element (OSCTXT* pctxt, 
   Config_item_map_entry_element *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Config_item_map_entry_element (OSCTXT* pctxt, 
   Config_item_map_entry_element* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Config_item_map_entry_element (OSCTXT* pctxt, 
   Config_item_map_entry_element* pvalue);

EXTERN int DOMTest_Config_item_map_entry_element (OSCTXT* pctxt, 
   Config_item_map_entry_element* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Config_item_map_entry_element (
   Config_item_map_entry_element* pvalue);

/**************************************************************/
/*                                                            */
/*  Config_item_map_entry                                     */
/*                                                            */
/**************************************************************/

#define TV_Config_item_map_entry	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Config_item_map_entry {
   struct {
      unsigned namePresent : 1;
   } m;
   const OSUTF8CHAR* name;
   /* List of Config_item_map_entry_element */
   OSRTDList choice_list;
} Config_item_map_entry;

EXTERN int asn1E_Config_item_map_entry (OSCTXT* pctxt,
   Config_item_map_entry *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Config_item_map_entry (OSCTXT* pctxt, 
   Config_item_map_entry *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Config_item_map_entry (OSCTXT* pctxt, 
   Config_item_map_entry* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Config_item_map_entry (OSCTXT* pctxt, 
   Config_item_map_entry* pvalue);

EXTERN int DOMTest_Config_item_map_entry (OSCTXT* pctxt, 
   Config_item_map_entry* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Config_item_map_entry (Config_item_map_entry* pvalue);

/**************************************************************/
/*                                                            */
/*  Config_item_map_named                                     */
/*                                                            */
/**************************************************************/

#define TV_Config_item_map_named	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Config_item_map_named {
   const OSUTF8CHAR* name;
   /* List of Config_item_map_entry */
   OSRTDList config_item_map_entry_list;
} Config_item_map_named;

EXTERN int asn1E_Config_item_map_named (OSCTXT* pctxt,
   Config_item_map_named *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Config_item_map_named (OSCTXT* pctxt, 
   Config_item_map_named *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Config_item_map_named (OSCTXT* pctxt, 
   Config_item_map_named* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Config_item_map_named (OSCTXT* pctxt, 
   Config_item_map_named* pvalue);

EXTERN int DOMTest_Config_item_map_named (OSCTXT* pctxt, 
   Config_item_map_named* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Config_item_map_named (Config_item_map_named* pvalue);

/**************************************************************/
/*                                                            */
/*  Config_item_set_element                                   */
/*                                                            */
/**************************************************************/

#define TV_Config_item_set_element	(TM_UNIV|TM_CONS|0)

/* Choice tag constants */

#define T_Config_item_set_element_config_item 1
#define T_Config_item_set_element_config_item_set 2
#define T_Config_item_set_element_config_item_map_named 3
#define T_Config_item_set_element_config_item_map_indexed 4

typedef struct EXTERN Config_item_set_element {
   int t;
   union {
      /* t = 1 */
      Config_item *config_item;
      /* t = 2 */
      struct Config_item_set *config_item_set;
      /* t = 3 */
      Config_item_map_named *config_item_map_named;
      /* t = 4 */
      Config_item_map_indexed *config_item_map_indexed;
   } u;
} Config_item_set_element;

EXTERN int asn1E_Config_item_set_element (OSCTXT* pctxt,
   Config_item_set_element *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Config_item_set_element (OSCTXT* pctxt, 
   Config_item_set_element *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Config_item_set_element (OSCTXT* pctxt, 
   Config_item_set_element* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Config_item_set_element (OSCTXT* pctxt, 
   Config_item_set_element* pvalue);

EXTERN int DOMTest_Config_item_set_element (OSCTXT* pctxt, 
   Config_item_set_element* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Config_item_set_element (Config_item_set_element* pvalue);

/**************************************************************/
/*                                                            */
/*  Config_item_set                                           */
/*                                                            */
/**************************************************************/

#define TV_Config_item_set	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Config_item_set {
   const OSUTF8CHAR* name;
   /* List of Config_item_set_element */
   OSRTDList choice_list;
} Config_item_set;

EXTERN int asn1E_Config_item_set (OSCTXT* pctxt,
   Config_item_set *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Config_item_set (OSCTXT* pctxt, Config_item_set *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_Config_item_set (OSCTXT* pctxt, Config_item_set* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Config_item_set (OSCTXT* pctxt, Config_item_set* pvalue);

EXTERN int DOMTest_Config_item_set (OSCTXT* pctxt, Config_item_set* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Config_item_set (Config_item_set* pvalue);

#ifdef __cplusplus
}
#endif

#endif