/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Ns7.h"
#include "Ns12.h"
#include "Ns3.h"
#include "Ns10.h"
#include "Ns15.h"
#include "Odf.h"
#include "rtxsrc/rtxCommon.h"

#include "rtxmlsrc/osrtxml.h"

const OSXMLNamespace g_Ns7_NSTable[] = {
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
/*  Ambient_color                                             */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Distance                                                  */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Focal_length                                              */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Lighting_mode                                             */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns7_Lighting_mode_ENUMTAB[] = {
   { OSUTF8("false"), 0, 5, 0 },
   { OSUTF8("true"), 1, 4, 1 }
} ;
#define Ns7_Lighting_mode_ENUMTABSIZE 2

const OSUTF8CHAR* Ns7_Lighting_mode_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns7_Lighting_mode_ENUMTABSIZE) {
      return Ns7_Lighting_mode_ENUMTAB
         [Ns7_Lighting_mode_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns7_Lighting_mode_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns7_Lighting_mode* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns7_Lighting_mode_ENUMTAB, 
      Ns7_Lighting_mode_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns7_Lighting_mode)Ns7_Lighting_mode_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  Projection                                                */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns7_Projection_ENUMTAB[] = {
   { OSUTF8("parallel"), 0, 8, 0 },
   { OSUTF8("perspective"), 1, 11, 1 }
} ;
#define Ns7_Projection_ENUMTABSIZE 2

const OSUTF8CHAR* Ns7_Projection_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns7_Projection_ENUMTABSIZE) {
      return Ns7_Projection_ENUMTAB
         [Ns7_Projection_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns7_Projection_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns7_Projection* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns7_Projection_ENUMTAB, 
      Ns7_Projection_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns7_Projection)Ns7_Projection_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  Shade_mode                                                */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns7_Shade_mode_ENUMTAB[] = {
   { OSUTF8("draft"), 0, 5, 0 },
   { OSUTF8("flat"), 1, 4, 1 },
   { OSUTF8("gouraud"), 2, 7, 2 },
   { OSUTF8("phong"), 3, 5, 3 }
} ;
#define Ns7_Shade_mode_ENUMTABSIZE 4

const OSUTF8CHAR* Ns7_Shade_mode_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns7_Shade_mode_ENUMTABSIZE) {
      return Ns7_Shade_mode_ENUMTAB
         [Ns7_Shade_mode_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns7_Shade_mode_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns7_Shade_mode* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns7_Shade_mode_ENUMTAB, 
      Ns7_Shade_mode_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns7_Shade_mode)Ns7_Shade_mode_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  Shadow_slant                                              */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Transform                                                 */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Vpn                                                       */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Vrp                                                       */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Vup                                                       */
/*                                                            */
/**************************************************************/

/**************************************************************/
/*                                                            */
/*  Light_enabled                                             */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns7_Light_enabled_ENUMTAB[] = {
   { OSUTF8("false"), 0, 5, 0 },
   { OSUTF8("true"), 1, 4, 1 }
} ;
#define Ns7_Light_enabled_ENUMTABSIZE 2

const OSUTF8CHAR* Ns7_Light_enabled_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns7_Light_enabled_ENUMTABSIZE) {
      return Ns7_Light_enabled_ENUMTAB
         [Ns7_Light_enabled_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns7_Light_enabled_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns7_Light_enabled* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns7_Light_enabled_ENUMTAB, 
      Ns7_Light_enabled_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns7_Light_enabled)Ns7_Light_enabled_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  Light_specular                                            */
/*                                                            */
/**************************************************************/

static const OSEnumItem Ns7_Light_specular_ENUMTAB[] = {
   { OSUTF8("false"), 0, 5, 0 },
   { OSUTF8("true"), 1, 4, 1 }
} ;
#define Ns7_Light_specular_ENUMTABSIZE 2

const OSUTF8CHAR* Ns7_Light_specular_ToString (OSINT32 value)
{
   OSINT32 idx = value;

   if (idx >= 0 && idx < Ns7_Light_specular_ENUMTABSIZE) {
      return Ns7_Light_specular_ENUMTAB
         [Ns7_Light_specular_ENUMTAB[idx].transidx].name;
   }
   else
      return OSUTF8("_UNKNOWN_");
}

int Ns7_Light_specular_ToEnum (OSCTXT* pctxt,
   const OSUTF8CHAR* value, Ns7_Light_specular* pvalue)
{
   OSUINT32 valueLen = rtxUTF8LenBytes (value);
   OSINT32 idx = rtxLookupEnum (value, valueLen, Ns7_Light_specular_ENUMTAB, 
      Ns7_Light_specular_ENUMTABSIZE);

   if (idx >= 0) {
      *pvalue = (Ns7_Light_specular)Ns7_Light_specular_ENUMTAB[idx].value;
      return 0;
   }
   else {
      rtxErrAddStrParm (pctxt, (const char*)value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
}

/**************************************************************/
/*                                                            */
/*  Light                                                     */
/*                                                            */
/**************************************************************/

void asn1Init_Ns7_Light (Ns7_Light* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->diffuse_color = 0;
   pvalue->direction = 0;
}

/**************************************************************/
/*                                                            */
/*  Extrude                                                   */
/*                                                            */
/**************************************************************/

void asn1Init_Ns7_Extrude (Ns7_Extrude* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->transform = 0;
   asn1Init_Ns3_Class_names ((Ns3_Class_names*)&pvalue->class_names);
   pvalue->id = 0;
   pvalue->layer = 0;
   pvalue->style_name = 0;
   asn1Init_Ns3_Class_names ((Ns3_Class_names*)&pvalue->class_names_1);
   pvalue->style_name_1 = 0;
   pvalue->d = 0;
   asn1Init_ViewBox ((ViewBox*)&pvalue->viewBox);
}

/**************************************************************/
/*                                                            */
/*  Sphere                                                    */
/*                                                            */
/**************************************************************/

void asn1Init_Ns7_Sphere (Ns7_Sphere* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->center = 0;
   pvalue->size = 0;
   pvalue->transform = 0;
   asn1Init_Ns3_Class_names ((Ns3_Class_names*)&pvalue->class_names);
   pvalue->id = 0;
   pvalue->layer = 0;
   pvalue->style_name = 0;
   asn1Init_Ns3_Class_names ((Ns3_Class_names*)&pvalue->class_names_1);
   pvalue->style_name_1 = 0;
}

/**************************************************************/
/*                                                            */
/*  Rotate                                                    */
/*                                                            */
/**************************************************************/

void asn1Init_Ns7_Rotate (Ns7_Rotate* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->transform = 0;
   asn1Init_Ns3_Class_names ((Ns3_Class_names*)&pvalue->class_names);
   pvalue->id = 0;
   pvalue->layer = 0;
   pvalue->style_name = 0;
   asn1Init_Ns3_Class_names ((Ns3_Class_names*)&pvalue->class_names_1);
   pvalue->style_name_1 = 0;
   pvalue->d = 0;
   asn1Init_ViewBox ((ViewBox*)&pvalue->viewBox);
}

/**************************************************************/
/*                                                            */
/*  Cube                                                      */
/*                                                            */
/**************************************************************/

void asn1Init_Ns7_Cube (Ns7_Cube* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->max_edge = 0;
   pvalue->min_edge = 0;
   pvalue->transform = 0;
   asn1Init_Ns3_Class_names ((Ns3_Class_names*)&pvalue->class_names);
   pvalue->id = 0;
   pvalue->layer = 0;
   pvalue->style_name = 0;
   asn1Init_Ns3_Class_names ((Ns3_Class_names*)&pvalue->class_names_1);
   pvalue->style_name_1 = 0;
}

/**************************************************************/
/*                                                            */
/*  Scene_element                                             */
/*                                                            */
/**************************************************************/

void asn1Init_Ns7_Scene_element (Ns7_Scene_element* pvalue)
{
   if (0 == pvalue) return;
   pvalue->t = 0;
   memset (&pvalue->u, 0, sizeof(pvalue->u));
}

/**************************************************************/
/*                                                            */
/*  Scene                                                     */
/*                                                            */
/**************************************************************/

void asn1Init_Ns7_Scene (Ns7_Scene* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->ambient_color = 0;
   pvalue->distance = 0;
   pvalue->focal_length = 0;
   pvalue->transform = 0;
   pvalue->vpn = 0;
   pvalue->vrp = 0;
   pvalue->vup = 0;
   asn1Init_Ns3_Class_names ((Ns3_Class_names*)&pvalue->class_names);
   pvalue->id = 0;
   pvalue->layer = 0;
   pvalue->style_name = 0;
   asn1Init_Ns3_Class_names ((Ns3_Class_names*)&pvalue->class_names_1);
   pvalue->style_name_1 = 0;
   pvalue->height = 0;
   pvalue->width = 0;
   pvalue->x = 0;
   pvalue->y = 0;
   pvalue->end_cell_address = 0;
   pvalue->end_x = 0;
   pvalue->end_y = 0;
   rtxDListFastInit (&pvalue->light_list);
   rtxDListFastInit (&pvalue->choice_list);
}
