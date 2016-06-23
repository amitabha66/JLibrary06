/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#ifndef HEPREP_H
#define HEPREP_H

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
 * Header file for ASN.1 module HepRep
 */
/**************************************************************/
/*                                                            */
/*  Point                                                     */
/*                                                            */
/**************************************************************/

#define TV_Point	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Point {
   OSREAL x;
   OSREAL y;
   OSREAL z;
} Point;

EXTERN int asn1E_Point (OSCTXT* pctxt,
   Point *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Point (OSCTXT* pctxt, Point *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc_Point (OSCTXT* pctxt, Point* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Point (OSCTXT* pctxt, Point* pvalue);

EXTERN int DOMTest_Point (OSCTXT* pctxt, Point* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Point (Point* pvalue);

/**************************************************************/
/*                                                            */
/*  Primitive                                                 */
/*                                                            */
/**************************************************************/

#define TV_Primitive	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Primitive {
   /* List of Point */
   OSRTDList point_list;
} Primitive;

EXTERN int asn1E_Primitive (OSCTXT* pctxt,
   Primitive *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Primitive (OSCTXT* pctxt, Primitive *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_Primitive (OSCTXT* pctxt, Primitive* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Primitive (OSCTXT* pctxt, Primitive* pvalue);

EXTERN int DOMTest_Primitive (OSCTXT* pctxt, Primitive* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Primitive (Primitive* pvalue);

/**************************************************************/
/*                                                            */
/*  Type_element                                              */
/*                                                            */
/**************************************************************/

#define TV_Type_element	(TM_UNIV|TM_CONS|0)

/* Choice tag constants */

#define T_Type_element_instance         1
#define T_Type_element_type             2
#define T_Type_element_primitive        3
#define T_Type_element_point            4

typedef struct EXTERN Type_element {
   int t;
   union {
      /* t = 1 */
      struct Instance *instance;
      /* t = 2 */
      struct Type *type;
      /* t = 3 */
      Primitive *primitive;
      /* t = 4 */
      Point *point;
   } u;
} Type_element;

EXTERN int asn1E_Type_element (OSCTXT* pctxt,
   Type_element *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Type_element (OSCTXT* pctxt, Type_element *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_Type_element (OSCTXT* pctxt, Type_element* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Type_element (OSCTXT* pctxt, Type_element* pvalue);

EXTERN int DOMTest_Type_element (OSCTXT* pctxt, Type_element* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Type_element (Type_element* pvalue);

/**************************************************************/
/*                                                            */
/*  _SeqOfType_element                                        */
/*                                                            */
/**************************************************************/

#define TV__SeqOfType_element	(TM_UNIV|TM_CONS|16)

/* List of Type_element */
typedef OSRTDList _SeqOfType_element;

EXTERN int asn1E__SeqOfType_element (OSCTXT* pctxt,
   _SeqOfType_element *pvalue, ASN1TagType tagging);

EXTERN int asn1D__SeqOfType_element (OSCTXT* pctxt, 
   _SeqOfType_element *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc__SeqOfType_element (OSCTXT* pctxt, 
   _SeqOfType_element* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec__SeqOfType_element (OSCTXT* pctxt, 
   _SeqOfType_element* pvalue);

EXTERN int DOMTest__SeqOfType_element (OSCTXT* pctxt, _SeqOfType_element* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init__SeqOfType_element (_SeqOfType_element* pvalue);

/**************************************************************/
/*                                                            */
/*  Type                                                      */
/*                                                            */
/**************************************************************/

#define TV_Type	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Type {
   struct {
      unsigned versionPresent : 1;
   } m;
   const OSUTF8CHAR* name;
   const OSUTF8CHAR* version;
   _SeqOfType_element choice_list;
} Type;

EXTERN int asn1E_Type (OSCTXT* pctxt,
   Type *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Type (OSCTXT* pctxt, Type *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc_Type (OSCTXT* pctxt, Type* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Type (OSCTXT* pctxt, Type* pvalue);

EXTERN int DOMTest_Type (OSCTXT* pctxt, Type* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Type (Type* pvalue);

/**************************************************************/
/*                                                            */
/*  Instance_element                                          */
/*                                                            */
/**************************************************************/

#define TV_Instance_element	(TM_UNIV|TM_CONS|0)

/* Choice tag constants */

#define T_Instance_element_type         1
#define T_Instance_element_primitive    2
#define T_Instance_element_point        3

typedef struct EXTERN Instance_element {
   int t;
   union {
      /* t = 1 */
      Type *type;
      /* t = 2 */
      Primitive *primitive;
      /* t = 3 */
      Point *point;
   } u;
} Instance_element;

EXTERN int asn1E_Instance_element (OSCTXT* pctxt,
   Instance_element *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Instance_element (OSCTXT* pctxt, Instance_element *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_Instance_element (OSCTXT* pctxt, Instance_element* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Instance_element (OSCTXT* pctxt, Instance_element* pvalue);

EXTERN int DOMTest_Instance_element (OSCTXT* pctxt, Instance_element* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Instance_element (Instance_element* pvalue);

/**************************************************************/
/*                                                            */
/*  _SeqOfInstance_element                                    */
/*                                                            */
/**************************************************************/

#define TV__SeqOfInstance_element	(TM_UNIV|TM_CONS|16)

/* List of Instance_element */
typedef OSRTDList _SeqOfInstance_element;

EXTERN int asn1E__SeqOfInstance_element (OSCTXT* pctxt,
   _SeqOfInstance_element *pvalue, ASN1TagType tagging);

EXTERN int asn1D__SeqOfInstance_element (OSCTXT* pctxt, 
   _SeqOfInstance_element *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc__SeqOfInstance_element (OSCTXT* pctxt, 
   _SeqOfInstance_element* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec__SeqOfInstance_element (OSCTXT* pctxt, 
   _SeqOfInstance_element* pvalue);

EXTERN int DOMTest__SeqOfInstance_element (OSCTXT* pctxt, 
   _SeqOfInstance_element* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init__SeqOfInstance_element (_SeqOfInstance_element* pvalue);

/**************************************************************/
/*                                                            */
/*  Instance                                                  */
/*                                                            */
/**************************************************************/

#define TV_Instance	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Instance {
   _SeqOfInstance_element choice_list;
} Instance;

EXTERN int asn1E_Instance (OSCTXT* pctxt,
   Instance *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Instance (OSCTXT* pctxt, Instance *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_Instance (OSCTXT* pctxt, Instance* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Instance (OSCTXT* pctxt, Instance* pvalue);

EXTERN int DOMTest_Instance (OSCTXT* pctxt, Instance* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Instance (Instance* pvalue);

/**************************************************************/
/*                                                            */
/*  Attribute_derivations_type_element                        */
/*                                                            */
/**************************************************************/

#define TV_Attribute_derivations_type_element	(TM_UNIV|TM_CONS|0)

/* Choice tag constants */

#define T_Attribute_derivations_type_element_instance 1
#define T_Attribute_derivations_type_element_type 2
#define T_Attribute_derivations_type_element_primitive 3
#define T_Attribute_derivations_type_element_point 4

typedef struct EXTERN Attribute_derivations_type_element {
   int t;
   union {
      /* t = 1 */
      Instance *instance;
      /* t = 2 */
      Type *type;
      /* t = 3 */
      Primitive *primitive;
      /* t = 4 */
      Point *point;
   } u;
} Attribute_derivations_type_element;

EXTERN int asn1E_Attribute_derivations_type_element (OSCTXT* pctxt,
   Attribute_derivations_type_element *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Attribute_derivations_type_element (OSCTXT* pctxt, 
   Attribute_derivations_type_element *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Attribute_derivations_type_element (OSCTXT* pctxt, 
   Attribute_derivations_type_element* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Attribute_derivations_type_element (OSCTXT* pctxt, 
   Attribute_derivations_type_element* pvalue);

EXTERN int DOMTest_Attribute_derivations_type_element (OSCTXT* pctxt, 
   Attribute_derivations_type_element* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Attribute_derivations_type_element (
   Attribute_derivations_type_element* pvalue);

/**************************************************************/
/*                                                            */
/*  _SeqOfAttribute_derivations_type_element                  */
/*                                                            */
/**************************************************************/

#define TV__SeqOfAttribute_derivations_type_element	(TM_UNIV|TM_CONS|16)

/* List of Attribute_derivations_type_element */
typedef OSRTDList _SeqOfAttribute_derivations_type_element;

EXTERN int asn1E__SeqOfAttribute_derivations_type_element (OSCTXT* pctxt,
   _SeqOfAttribute_derivations_type_element *pvalue, ASN1TagType tagging);

EXTERN int asn1D__SeqOfAttribute_derivations_type_element (OSCTXT* pctxt, 
   _SeqOfAttribute_derivations_type_element *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc__SeqOfAttribute_derivations_type_element (OSCTXT* pctxt, 
   _SeqOfAttribute_derivations_type_element* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec__SeqOfAttribute_derivations_type_element (OSCTXT* pctxt, 
   _SeqOfAttribute_derivations_type_element* pvalue);

EXTERN int DOMTest__SeqOfAttribute_derivations_type_element (OSCTXT* pctxt, 
   _SeqOfAttribute_derivations_type_element* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init__SeqOfAttribute_derivations_type_element (
   _SeqOfAttribute_derivations_type_element* pvalue);

/**************************************************************/
/*                                                            */
/*  Attribute_derivations_type                                */
/*                                                            */
/**************************************************************/

#define TV_Attribute_derivations_type	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Attribute_derivations_type {
   struct {
      unsigned versionPresent : 1;
   } m;
   const OSUTF8CHAR* name;
   const OSUTF8CHAR* version;
   _SeqOfAttribute_derivations_type_element choice_list;
} Attribute_derivations_type;

EXTERN int asn1E_Attribute_derivations_type (OSCTXT* pctxt,
   Attribute_derivations_type *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Attribute_derivations_type (OSCTXT* pctxt, 
   Attribute_derivations_type *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Attribute_derivations_type (OSCTXT* pctxt, 
   Attribute_derivations_type* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Attribute_derivations_type (OSCTXT* pctxt, 
   Attribute_derivations_type* pvalue);

EXTERN int DOMTest_Attribute_derivations_type (OSCTXT* pctxt, 
   Attribute_derivations_type* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Attribute_derivations_type (Attribute_derivations_type* pvalue);

/**************************************************************/
/*                                                            */
/*  Attribute_derivations_instance_element                    */
/*                                                            */
/**************************************************************/

#define TV_Attribute_derivations_instance_element	(TM_UNIV|TM_CONS|0)

/* Choice tag constants */

#define T_Attribute_derivations_instance_element_type 1
#define T_Attribute_derivations_instance_element_primitive 2
#define T_Attribute_derivations_instance_element_point 3

typedef struct EXTERN Attribute_derivations_instance_element {
   int t;
   union {
      /* t = 1 */
      Type *type;
      /* t = 2 */
      Primitive *primitive;
      /* t = 3 */
      Point *point;
   } u;
} Attribute_derivations_instance_element;

EXTERN int asn1E_Attribute_derivations_instance_element (OSCTXT* pctxt,
   Attribute_derivations_instance_element *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Attribute_derivations_instance_element (OSCTXT* pctxt, 
   Attribute_derivations_instance_element *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc_Attribute_derivations_instance_element (OSCTXT* pctxt, 
   Attribute_derivations_instance_element* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Attribute_derivations_instance_element (OSCTXT* pctxt, 
   Attribute_derivations_instance_element* pvalue);

EXTERN int DOMTest_Attribute_derivations_instance_element (OSCTXT* pctxt, 
   Attribute_derivations_instance_element* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Attribute_derivations_instance_element (
   Attribute_derivations_instance_element* pvalue);

/**************************************************************/
/*                                                            */
/*  _SeqOfAttribute_derivations_instance_element              */
/*                                                            */
/**************************************************************/

#define TV__SeqOfAttribute_derivations_instance_element	(TM_UNIV|TM_CONS|16)

/* List of Attribute_derivations_instance_element */
typedef OSRTDList _SeqOfAttribute_derivations_instance_element;

EXTERN int asn1E__SeqOfAttribute_derivations_instance_element (OSCTXT* pctxt,
   _SeqOfAttribute_derivations_instance_element *pvalue, ASN1TagType tagging);

EXTERN int asn1D__SeqOfAttribute_derivations_instance_element (OSCTXT* pctxt, 
   _SeqOfAttribute_derivations_instance_element *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc__SeqOfAttribute_derivations_instance_element (OSCTXT* pctxt, 
   _SeqOfAttribute_derivations_instance_element* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec__SeqOfAttribute_derivations_instance_element (OSCTXT* pctxt, 
   _SeqOfAttribute_derivations_instance_element* pvalue);

EXTERN int DOMTest__SeqOfAttribute_derivations_instance_element (OSCTXT* pctxt, 
   _SeqOfAttribute_derivations_instance_element* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init__SeqOfAttribute_derivations_instance_element (
   _SeqOfAttribute_derivations_instance_element* pvalue);

/**************************************************************/
/*                                                            */
/*  Attribute_derivations_instance                            */
/*                                                            */
/**************************************************************/

#define TV_Attribute_derivations_instance	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Attribute_derivations_instance {
   _SeqOfAttribute_derivations_instance_element choice_list;
} Attribute_derivations_instance;

EXTERN int asn1E_Attribute_derivations_instance (OSCTXT* pctxt,
   Attribute_derivations_instance *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Attribute_derivations_instance (OSCTXT* pctxt, 
   Attribute_derivations_instance *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Attribute_derivations_instance (OSCTXT* pctxt, 
   Attribute_derivations_instance* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Attribute_derivations_instance (OSCTXT* pctxt, 
   Attribute_derivations_instance* pvalue);

EXTERN int DOMTest_Attribute_derivations_instance (OSCTXT* pctxt, 
   Attribute_derivations_instance* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Attribute_derivations_instance (
   Attribute_derivations_instance* pvalue);

/**************************************************************/
/*                                                            */
/*  Attribute_derivations_primitive                           */
/*                                                            */
/**************************************************************/

#define TV_Attribute_derivations_primitive	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Attribute_derivations_primitive {
   /* List of Point */
   OSRTDList point_list;
} Attribute_derivations_primitive;

EXTERN int asn1E_Attribute_derivations_primitive (OSCTXT* pctxt,
   Attribute_derivations_primitive *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Attribute_derivations_primitive (OSCTXT* pctxt, 
   Attribute_derivations_primitive *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Attribute_derivations_primitive (OSCTXT* pctxt, 
   Attribute_derivations_primitive* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Attribute_derivations_primitive (OSCTXT* pctxt, 
   Attribute_derivations_primitive* pvalue);

EXTERN int DOMTest_Attribute_derivations_primitive (OSCTXT* pctxt, 
   Attribute_derivations_primitive* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Attribute_derivations_primitive (
   Attribute_derivations_primitive* pvalue);

/**************************************************************/
/*                                                            */
/*  Attribute_derivations_point                               */
/*                                                            */
/**************************************************************/

#define TV_Attribute_derivations_point	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Attribute_derivations_point {
   OSREAL x;
   OSREAL y;
   OSREAL z;
} Attribute_derivations_point;

EXTERN int asn1E_Attribute_derivations_point (OSCTXT* pctxt,
   Attribute_derivations_point *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Attribute_derivations_point (OSCTXT* pctxt, 
   Attribute_derivations_point *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Attribute_derivations_point (OSCTXT* pctxt, 
   Attribute_derivations_point* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Attribute_derivations_point (OSCTXT* pctxt, 
   Attribute_derivations_point* pvalue);

EXTERN int DOMTest_Attribute_derivations_point (OSCTXT* pctxt, 
   Attribute_derivations_point* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Attribute_derivations_point (Attribute_derivations_point* pvalue);

/**************************************************************/
/*                                                            */
/*  Attribute_derivations_heprep                              */
/*                                                            */
/**************************************************************/

#define TV_Attribute_derivations_heprep	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Attribute_derivations_heprep {
   /* List of Type */
   OSRTDList type_list;
} Attribute_derivations_heprep;

EXTERN int asn1E_Attribute_derivations_heprep (OSCTXT* pctxt,
   Attribute_derivations_heprep *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Attribute_derivations_heprep (OSCTXT* pctxt, 
   Attribute_derivations_heprep *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Attribute_derivations_heprep (OSCTXT* pctxt, 
   Attribute_derivations_heprep* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Attribute_derivations_heprep (OSCTXT* pctxt, 
   Attribute_derivations_heprep* pvalue);

EXTERN int DOMTest_Attribute_derivations_heprep (OSCTXT* pctxt, 
   Attribute_derivations_heprep* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Attribute_derivations_heprep (
   Attribute_derivations_heprep* pvalue);

/**************************************************************/
/*                                                            */
/*  Attribute_derivations                                     */
/*                                                            */
/**************************************************************/

#define TV_Attribute_derivations	(TM_UNIV|TM_CONS|0)

/* Choice tag constants */

#define T_Attribute_derivations_type    1
#define T_Attribute_derivations_instance 2
#define T_Attribute_derivations_primitive 3
#define T_Attribute_derivations_point   4
#define T_Attribute_derivations_heprep  5

typedef struct EXTERN Attribute_derivations {
   int t;
   union {
      /* t = 1 */
      Attribute_derivations_type *type;
      /* t = 2 */
      Attribute_derivations_instance *instance;
      /* t = 3 */
      Attribute_derivations_primitive *primitive;
      /* t = 4 */
      Attribute_derivations_point *point;
      /* t = 5 */
      Attribute_derivations_heprep *heprep;
   } u;
} Attribute_derivations;

EXTERN int asn1E_Attribute_derivations (OSCTXT* pctxt,
   Attribute_derivations *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Attribute_derivations (OSCTXT* pctxt, 
   Attribute_derivations *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Attribute_derivations (OSCTXT* pctxt, 
   Attribute_derivations* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Attribute_derivations (OSCTXT* pctxt, 
   Attribute_derivations* pvalue);

EXTERN int DOMTest_Attribute_derivations (OSCTXT* pctxt, 
   Attribute_derivations* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Attribute_derivations (Attribute_derivations* pvalue);

/**************************************************************/
/*                                                            */
/*  Attribute                                                 */
/*                                                            */
/**************************************************************/

#define TV_Attribute	(TM_UNIV|TM_CONS|0)

typedef Attribute_derivations Attribute;

EXTERN int asn1E_Attribute (OSCTXT* pctxt,
   Attribute *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Attribute (OSCTXT* pctxt, Attribute *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_Attribute (OSCTXT* pctxt, Attribute* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Attribute (OSCTXT* pctxt, Attribute* pvalue);

EXTERN int DOMTest_Attribute (OSCTXT* pctxt, Attribute* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Attribute (Attribute* pvalue);

/**************************************************************/
/*                                                            */
/*  Heprep                                                    */
/*                                                            */
/**************************************************************/

#define TV_Heprep	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Heprep {
   /* List of Type */
   OSRTDList type_list;
} Heprep;

EXTERN int asn1E_Heprep (OSCTXT* pctxt,
   Heprep *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Heprep (OSCTXT* pctxt, Heprep *pvalue, ASN1TagType tagging, 
   int length);

EXTERN int XmlEnc_Heprep (OSCTXT* pctxt, Heprep* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Heprep (OSCTXT* pctxt, Heprep* pvalue);

EXTERN int DOMTest_Heprep (OSCTXT* pctxt, Heprep* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Heprep (Heprep* pvalue);

/**************************************************************/
/*                                                            */
/*  Attribute_1_element_attdef                                */
/*                                                            */
/**************************************************************/

#define TV_Attribute_1_element_attdef	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Attribute_1_element_attdef {
   struct {
      unsigned descPresent : 1;
      unsigned extraPresent : 1;
   } m;
   const OSUTF8CHAR* desc;
   const OSUTF8CHAR* extra;
   const OSUTF8CHAR* name;
   const OSUTF8CHAR* type;
} Attribute_1_element_attdef;

EXTERN int asn1E_Attribute_1_element_attdef (OSCTXT* pctxt,
   Attribute_1_element_attdef *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Attribute_1_element_attdef (OSCTXT* pctxt, 
   Attribute_1_element_attdef *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Attribute_1_element_attdef (OSCTXT* pctxt, 
   Attribute_1_element_attdef* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Attribute_1_element_attdef (OSCTXT* pctxt, 
   Attribute_1_element_attdef* pvalue);

EXTERN int DOMTest_Attribute_1_element_attdef (OSCTXT* pctxt, 
   Attribute_1_element_attdef* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Attribute_1_element_attdef (Attribute_1_element_attdef* pvalue);

/**************************************************************/
/*                                                            */
/*  Attribute_1_element_attvalue                              */
/*                                                            */
/**************************************************************/

#define TV_Attribute_1_element_attvalue	(TM_UNIV|TM_CONS|16)

typedef struct EXTERN Attribute_1_element_attvalue {
   struct {
      unsigned showLabelPresent : 1;
   } m;
   const OSUTF8CHAR* name;
   const OSUTF8CHAR* showLabel;
   const OSUTF8CHAR* value;
} Attribute_1_element_attvalue;

EXTERN int asn1E_Attribute_1_element_attvalue (OSCTXT* pctxt,
   Attribute_1_element_attvalue *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Attribute_1_element_attvalue (OSCTXT* pctxt, 
   Attribute_1_element_attvalue *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Attribute_1_element_attvalue (OSCTXT* pctxt, 
   Attribute_1_element_attvalue* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Attribute_1_element_attvalue (OSCTXT* pctxt, 
   Attribute_1_element_attvalue* pvalue);

EXTERN int DOMTest_Attribute_1_element_attvalue (OSCTXT* pctxt, 
   Attribute_1_element_attvalue* pvalue, xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Attribute_1_element_attvalue (
   Attribute_1_element_attvalue* pvalue);

/**************************************************************/
/*                                                            */
/*  Attribute_1_element                                       */
/*                                                            */
/**************************************************************/

#define TV_Attribute_1_element	(TM_UNIV|TM_CONS|0)

/* Choice tag constants */

#define T_Attribute_1_element_attdef    1
#define T_Attribute_1_element_attvalue  2

typedef struct EXTERN Attribute_1_element {
   int t;
   union {
      /* t = 1 */
      Attribute_1_element_attdef *attdef;
      /* t = 2 */
      Attribute_1_element_attvalue *attvalue;
   } u;
} Attribute_1_element;

EXTERN int asn1E_Attribute_1_element (OSCTXT* pctxt,
   Attribute_1_element *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Attribute_1_element (OSCTXT* pctxt, 
   Attribute_1_element *pvalue, ASN1TagType tagging, int length);

EXTERN int XmlEnc_Attribute_1_element (OSCTXT* pctxt, 
   Attribute_1_element* pvalue, const OSUTF8CHAR* elemName, 
   const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Attribute_1_element (OSCTXT* pctxt, 
   Attribute_1_element* pvalue);

EXTERN int DOMTest_Attribute_1_element (OSCTXT* pctxt, Attribute_1_element* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Attribute_1_element (Attribute_1_element* pvalue);

/**************************************************************/
/*                                                            */
/*  Attribute_1                                               */
/*                                                            */
/**************************************************************/

#define TV_Attribute_1	(TM_UNIV|TM_CONS|16)

/* List of Attribute_1_element */
typedef OSRTDList Attribute_1;

EXTERN int asn1E_Attribute_1 (OSCTXT* pctxt,
   Attribute_1 *pvalue, ASN1TagType tagging);

EXTERN int asn1D_Attribute_1 (OSCTXT* pctxt, Attribute_1 *pvalue, 
   ASN1TagType tagging, int length);

EXTERN int XmlEnc_Attribute_1 (OSCTXT* pctxt, Attribute_1* pvalue, 
   const OSUTF8CHAR* elemName, const OSUTF8CHAR* nsPrefix);

EXTERN int XmlDec_Attribute_1 (OSCTXT* pctxt, Attribute_1* pvalue);

EXTERN int DOMTest_Attribute_1 (OSCTXT* pctxt, Attribute_1* pvalue, 
   xmlNodePtr pXmlNode, OSBOOL setChild);

EXTERN void asn1Init_Attribute_1 (Attribute_1* pvalue);

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
EXTERN int XmlEnc_Attribute_PDU (OSCTXT* pctxt, Attribute* pvalue);

EXTERN int XmlDec_Attribute_PDU (OSCTXT* pctxt, Attribute* pvalue);

EXTERN int XmlEnc_Heprep_PDU (OSCTXT* pctxt, Heprep* pvalue);

EXTERN int XmlDec_Heprep_PDU (OSCTXT* pctxt, Heprep* pvalue);

EXTERN int XmlEnc_Attribute_1_PDU (OSCTXT* pctxt, Attribute_1* pvalue);

EXTERN int XmlDec_Attribute_1_PDU (OSCTXT* pctxt, Attribute_1* pvalue);

#ifdef __cplusplus
}
#endif

#endif