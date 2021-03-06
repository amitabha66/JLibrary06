/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Datastore.h"
#include "rtxsrc/rtxCommon.h"

#include "rtxmlsrc/osrtxml.h"

const OSXMLNamespace g_Datastore_NSTable[] = {
   { OSUTF8(""), OSUTF8("http://www.sun.com/xml/datastore") }
} ;

/**************************************************************/
/*                                                            */
/*  DataType                                                  */
/*                                                            */
/**************************************************************/

void asn1Init_DataType (DataType* pvalue)
{
   if (0 == pvalue) return;
   memset (&pvalue->m, 0, sizeof (pvalue->m));
   pvalue->stringT = 0;
   pvalue->binaryT.numocts = 0;
   pvalue->binaryT.data = 0;
}

/**************************************************************/
/*                                                            */
/*  DataStoreType                                             */
/*                                                            */
/**************************************************************/

void asn1Init_DataStoreType (DataStoreType* pvalue)
{
   if (0 == pvalue) return;
   rtxDListFastInit (pvalue);
}

/**************************************************************/
/*                                                            */
/*  DataStore                                                 */
/*                                                            */
/**************************************************************/

void asn1Init_DataStore (DataStore* pvalue)
{
   if (0 == pvalue) return;
   asn1Init_DataStoreType (pvalue);
}

