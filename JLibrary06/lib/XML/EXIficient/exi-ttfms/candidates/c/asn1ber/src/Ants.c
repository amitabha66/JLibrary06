/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#include "asn1intl.h"
#include "Ants.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  Project_property_list_property                            */
/*                                                            */
/**************************************************************/

void asn1Init_Project_property_list_property (Project_property_list_property* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->file = 0;
   pvalue->name = 0;
   pvalue->value = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_property_list                                     */
/*                                                            */
/**************************************************************/

void asn1Init_Project_property_list (Project_property_list* pvalue)
{
   if (0 == pvalue) return;
   rtxDListFastInit (pvalue);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_copy_sequence_fileset_sequence_exclude (Project_target_list_target_sequence_choice_list_element_copy_sequence_fileset_sequence_exclude* pvalue)
{
   if (0 == pvalue) return;
   pvalue->name = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_copy_sequence_fileset_sequence_include_list_include (Project_target_list_target_sequence_choice_list_element_copy_sequence_fileset_sequence_include_list_include* pvalue)
{
   if (0 == pvalue) return;
   pvalue->name = 0;
}

/**************************************************************/
/*                                                            */
/*  _SeqOfProject_target_list_target_sequence_choice_list_el  */
/*                                                            */
/**************************************************************/

void asn1Init__SeqOfProject_target_list_target_sequence_choice_list_element_copy_sequence_fileset_sequence_include_list_include (_SeqOfProject_target_list_target_sequence_choice_list_element_copy_sequence_fileset_sequence_include_list_include* pvalue)
{
   if (0 == pvalue) return;
   rtxDListFastInit (pvalue);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_copy_sequence_fileset_sequence (Project_target_list_target_sequence_choice_list_element_copy_sequence_fileset_sequence* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   asn1Init_Project_target_list_target_sequence_choice_list_element_copy_sequence_fileset_sequence_exclude (&pvalue->exclude);
   asn1Init__SeqOfProject_target_list_target_sequence_choice_list_element_copy_sequence_fileset_sequence_include_list_include (&pvalue->include_list);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_copy_sequence_fileset (Project_target_list_target_sequence_choice_list_element_copy_sequence_fileset* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->dir = 0;
   pvalue->excludes = 0;
   pvalue->includes = 0;
   asn1Init_Project_target_list_target_sequence_choice_list_element_copy_sequence_fileset_sequence (&pvalue->sequence);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_copy_sequence (Project_target_list_target_sequence_choice_list_element_copy_sequence* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_Project_target_list_target_sequence_choice_list_element_copy_sequence_fileset (&pvalue->fileset);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_copy (Project_target_list_target_sequence_choice_list_element_copy* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->file = 0;
   pvalue->toDir = 0;
   pvalue->toFile = 0;
   pvalue->todir = 0;
   pvalue->tofile = 0;
   asn1Init_Project_target_list_target_sequence_choice_list_element_copy_sequence (&pvalue->sequence);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_style_sequence_include (Project_target_list_target_sequence_choice_list_element_style_sequence_include* pvalue)
{
   if (0 == pvalue) return;
   pvalue->name = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_style_sequence_exclude (Project_target_list_target_sequence_choice_list_element_style_sequence_exclude* pvalue)
{
   if (0 == pvalue) return;
   pvalue->name = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_style_sequence_param (Project_target_list_target_sequence_choice_list_element_style_sequence_param* pvalue)
{
   if (0 == pvalue) return;
   pvalue->expression = 0;
   pvalue->name = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_style_sequence (Project_target_list_target_sequence_choice_list_element_style_sequence* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   asn1Init_Project_target_list_target_sequence_choice_list_element_style_sequence_include (&pvalue->include);
   asn1Init_Project_target_list_target_sequence_choice_list_element_style_sequence_exclude (&pvalue->exclude);
   asn1Init_Project_target_list_target_sequence_choice_list_element_style_sequence_param (&pvalue->param);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_style (Project_target_list_target_sequence_choice_list_element_style* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->basedir = 0;
   pvalue->destdir = 0;
   pvalue->excludes = 0;
   pvalue->extension = 0;
   pvalue->in = 0;
   pvalue->includes = 0;
   pvalue->out = 0;
   pvalue->style = 0;
   asn1Init_Project_target_list_target_sequence_choice_list_element_style_sequence (&pvalue->sequence);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_mkdir (Project_target_list_target_sequence_choice_list_element_mkdir* pvalue)
{
   if (0 == pvalue) return;
   pvalue->dir = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_javac_sequence_classpath_pathelement (Project_target_list_target_sequence_choice_list_element_javac_sequence_classpath_pathelement* pvalue)
{
   if (0 == pvalue) return;
   pvalue->location = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_javac_sequence_classpath_fileset_include (Project_target_list_target_sequence_choice_list_element_javac_sequence_classpath_fileset_include* pvalue)
{
   if (0 == pvalue) return;
   pvalue->name = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_javac_sequence_classpath_fileset (Project_target_list_target_sequence_choice_list_element_javac_sequence_classpath_fileset* pvalue)
{
   if (0 == pvalue) return;
   pvalue->dir = 0;
   asn1Init_Project_target_list_target_sequence_choice_list_element_javac_sequence_classpath_fileset_include (&pvalue->include);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_javac_sequence_classpath (Project_target_list_target_sequence_choice_list_element_javac_sequence_classpath* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_Project_target_list_target_sequence_choice_list_element_javac_sequence_classpath_pathelement (&pvalue->pathelement);
   asn1Init_Project_target_list_target_sequence_choice_list_element_javac_sequence_classpath_fileset (&pvalue->fileset);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_javac_sequence (Project_target_list_target_sequence_choice_list_element_javac_sequence* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_Project_target_list_target_sequence_choice_list_element_javac_sequence_classpath (&pvalue->classpath);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_javac (Project_target_list_target_sequence_choice_list_element_javac* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->classpath = 0;
   pvalue->debug = 0;
   pvalue->destdir = 0;
   pvalue->srcdir = 0;
   asn1Init_Project_target_list_target_sequence_choice_list_element_javac_sequence (&pvalue->sequence);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_jar (Project_target_list_target_sequence_choice_list_element_jar* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->basedir = 0;
   pvalue->excludes = 0;
   pvalue->includes = 0;
   pvalue->jarfile = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_delete__sequence_fileset_include (Project_target_list_target_sequence_choice_list_element_delete__sequence_fileset_include* pvalue)
{
   if (0 == pvalue) return;
   pvalue->name = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_delete__sequence_fileset (Project_target_list_target_sequence_choice_list_element_delete__sequence_fileset* pvalue)
{
   if (0 == pvalue) return;
   pvalue->dir = 0;
   asn1Init_Project_target_list_target_sequence_choice_list_element_delete__sequence_fileset_include (&pvalue->include);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_delete__sequence (Project_target_list_target_sequence_choice_list_element_delete__sequence* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_Project_target_list_target_sequence_choice_list_element_delete__sequence_fileset (&pvalue->fileset);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_delete_ (Project_target_list_target_sequence_choice_list_element_delete_* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->dir = 0;
   asn1Init_Project_target_list_target_sequence_choice_list_element_delete__sequence (&pvalue->sequence);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_available (Project_target_list_target_sequence_choice_list_element_available* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->classname = 0;
   pvalue->classpath = 0;
   pvalue->file = 0;
   pvalue->property = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_ant (Project_target_list_target_sequence_choice_list_element_ant* pvalue)
{
   if (0 == pvalue) return;
   pvalue->dir = 0;
   pvalue->target = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_antcall_sequence_param_list_param (Project_target_list_target_sequence_choice_list_element_antcall_sequence_param_list_param* pvalue)
{
   if (0 == pvalue) return;
   pvalue->name = 0;
   pvalue->value = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_antcall_sequence_param_list (Project_target_list_target_sequence_choice_list_element_antcall_sequence_param_list* pvalue)
{
   if (0 == pvalue) return;
   rtxDListFastInit (pvalue);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_antcall_sequence (Project_target_list_target_sequence_choice_list_element_antcall_sequence* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_Project_target_list_target_sequence_choice_list_element_antcall_sequence_param_list (&pvalue->param_list);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_antcall (Project_target_list_target_sequence_choice_list_element_antcall* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->target = 0;
   asn1Init_Project_target_list_target_sequence_choice_list_element_antcall_sequence (&pvalue->sequence);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_move (Project_target_list_target_sequence_choice_list_element_move* pvalue)
{
   if (0 == pvalue) return;
   pvalue->file = 0;
   pvalue->tofile = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_fail (Project_target_list_target_sequence_choice_list_element_fail* pvalue)
{
   if (0 == pvalue) return;
   pvalue->message = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_javadoc_sequence_classpath_pathelement (Project_target_list_target_sequence_choice_list_element_javadoc_sequence_classpath_pathelement* pvalue)
{
   if (0 == pvalue) return;
   pvalue->location = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_javadoc_sequence_classpath_fileset_include (Project_target_list_target_sequence_choice_list_element_javadoc_sequence_classpath_fileset_include* pvalue)
{
   if (0 == pvalue) return;
   pvalue->name = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_javadoc_sequence_classpath_fileset (Project_target_list_target_sequence_choice_list_element_javadoc_sequence_classpath_fileset* pvalue)
{
   if (0 == pvalue) return;
   pvalue->dir = 0;
   asn1Init_Project_target_list_target_sequence_choice_list_element_javadoc_sequence_classpath_fileset_include (&pvalue->include);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_javadoc_sequence_classpath (Project_target_list_target_sequence_choice_list_element_javadoc_sequence_classpath* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_Project_target_list_target_sequence_choice_list_element_javadoc_sequence_classpath_pathelement (&pvalue->pathelement);
   asn1Init_Project_target_list_target_sequence_choice_list_element_javadoc_sequence_classpath_fileset (&pvalue->fileset);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_javadoc_sequence (Project_target_list_target_sequence_choice_list_element_javadoc_sequence* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_Project_target_list_target_sequence_choice_list_element_javadoc_sequence_classpath (&pvalue->classpath);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_javadoc (Project_target_list_target_sequence_choice_list_element_javadoc* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->bottom = 0;
   pvalue->classpath = 0;
   pvalue->destdir = 0;
   pvalue->doctitle = 0;
   pvalue->packagenames = 0;
   pvalue->sourcepath = 0;
   pvalue->windowtitle = 0;
   asn1Init_Project_target_list_target_sequence_choice_list_element_javadoc_sequence (&pvalue->sequence);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_native2ascii (Project_target_list_target_sequence_choice_list_element_native2ascii* pvalue)
{
   if (0 == pvalue) return;
   pvalue->dest = 0;
   pvalue->encoding = 0;
   pvalue->includes = 0;
   pvalue->src = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element_  */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element_echo (Project_target_list_target_sequence_choice_list_element_echo* pvalue)
{
   if (0 == pvalue) return;
   pvalue->message = 0;
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list_element   */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list_element (Project_target_list_target_sequence_choice_list_element* pvalue)
{
   if (0 == pvalue) return;
   pvalue->t = 0;
   memset (&pvalue->u, 0, sizeof(pvalue->u));
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence_choice_list           */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence_choice_list (Project_target_list_target_sequence_choice_list* pvalue)
{
   if (0 == pvalue) return;
   rtxDListFastInit (pvalue);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target_sequence                       */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target_sequence (Project_target_list_target_sequence* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_Project_target_list_target_sequence_choice_list (&pvalue->choice_list);
}

/**************************************************************/
/*                                                            */
/*  Project_target_list_target                                */
/*                                                            */
/**************************************************************/

void asn1Init_Project_target_list_target (Project_target_list_target* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->depends = 0;
   pvalue->if_ = 0;
   pvalue->name = 0;
   pvalue->unless = 0;
   asn1Init_Project_target_list_target_sequence (&pvalue->sequence);
}

/**************************************************************/
/*                                                            */
/*  _SeqOfProject_target_list_target                          */
/*                                                            */
/**************************************************************/

void asn1Init__SeqOfProject_target_list_target (_SeqOfProject_target_list_target* pvalue)
{
   if (0 == pvalue) return;
   rtxDListFastInit (pvalue);
}

/**************************************************************/
/*                                                            */
/*  Project                                                   */
/*                                                            */
/**************************************************************/

void asn1Init_Project (Project* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->basedir = 0;
   pvalue->default_ = 0;
   pvalue->name = 0;
   asn1Init_Project_property_list (&pvalue->property_list);
   asn1Init__SeqOfProject_target_list_target (&pvalue->target_list);
}

