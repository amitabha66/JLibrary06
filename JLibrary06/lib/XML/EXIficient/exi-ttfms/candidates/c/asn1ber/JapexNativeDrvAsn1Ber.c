#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _MSC_VER
   #include <time.h>
#else
   #include <sys/time.h>
#endif

#include <com_sun_japex_jdsl_nativecode_JapexNativeDriver.h>

#include <libxml/parser.h>

#include "AVCL.h"
#include "Dahut-sighting.h"
#include "Datastore.h"
#include "FIXML-4-4.h"
#include "FpML-4-0.h"
#include "Gaml100.h"
#include "HepRep.h"
#include "MAGE-ML.h"
#include "Xmldsig.h"
#include "Sm-inv.h"
#include "Factbook.h"
#include "Periodic.h"
#include "Seis.h"
#include "Soap-1-1.h"
#include "Svg.h"
#include "Urn-GoogleSearch.h"
#include "Urn-oma-bcast-esg-2005.h"
#include "Urn-dvb-ipdc-esg-2005.h"
#include "Urn-mpeg-mpeg7-schema-2001.h"
#include "Urn-tva-metadata-2005.h"
#include "Weblog.h"
#include "XSD.h"
#include "rtxsrc/rtxStreamFile.h"

/* OpenOffice includes */
#include "Ns13.h"
#include "Ns10.h"
#include "Odf.h"
#include "Ns3.h"
#include "Ns15.h"
#include "Ns4.h"
#include "Xforms.h"
#include "Ns8.h"
#include "Ns14.h"
#include "Ns12.h"
#include "Ns7.h"
#include "Ns5.h"

#if 0
/* the following are no longer being used */
#include "Ants.h"
#endif

#ifdef UBL
#include "UBL-XSD.h"
#include "UBL-DespatchAdvice-1-0.h"
#include "UBL-Invoice-1-0.h"
#include "UBL-Order-1-0.h"
#include "UBL-OrderCancellation-1-0.h"
#include "UBL-OrderChange-1-0.h"
#include "UBL-OrderResponse-1-0.h"
#include "UBL-OrderResponseSimple-1-0.h"
#include "UBL-ReceiptAdvice-1-0.h"

#undef Invoice
#undef asn1E_Invoice
#undef asn1D_Invoice
#undef asn1DOMTest_Invoice

#endif

#define Byte z_Byte
#include "zlib.h"
#undef z_Byte

/*
 * These functions are defined towards the bottom of this file
 */
jobject userDataToObject(JNIEnv *env, void *userData, int size);
void* objectToUserData(JNIEnv *env, jobject object);
const char* getParam(JNIEnv *env, jobject this, const char *name);
void setLongParam(JNIEnv *env, jobject this, const char *name, long value);
long getLongParam(JNIEnv *env, jobject this, const char *name);


OSCTXT ctxt;
xmlDocPtr pXmlDoc;
int len;
int fileLen;
int compressedFileLen;

enum Mode {
   Compactness,
   Encode,
   Decode
} mode; 

enum CompactnessMode {
   Unknown, 
   Neither,
   Compression,
   Schema,
   SchemaCompression
} compactnessMode; 

void* message;
OSOCTET* buffer;

enum MessageType {
   ProjectMsg,
   AVCLMsg,
   BCASTMsg, 
   BCASTAccessFrag, 
   BCASTContentFrag, 
   BCASTInterFrag, 
   BCASTPreviewFrag, 
   BCASTPurchFrag, 
   BCASTSchedFrag, 
   BCASTServiceFrag, 
   CBMSAcquisitionFrag, 
   CBMSContentFrag, 
   CBMSSchedFrag, 
   CBMSServiceFrag,
   DahutMsg, 
   DatastoreMsg, 
   GoogleMsg, 
   FactbookMsg,
   FIXMLMsg, 
   FpMLMsg,
   GAMLMsg, 
   HepRepMsg, 
   InvoiceMsg,
   MAGEMLMsg, 
   OODocumentMsg, 
   PeriodicMsg,
   SeisMsg, 
   SOAPFaultMsg, 
   SVGMsg, 
   WeblogMsg,

   DespatchAdviceMsg,
   InvoiceUBLMsg,
   OrderMsg,
   OrderResponseMsg,
   OrderCancellationMsg,
   OrderChangeMsg,
   OrderResponseSimpleMsg,
   ReceiptAdviceMsg
} msgType; 

#define BCAST_NS     "urn:oma:bcast:esg:2005"
#define CBMS_NS      "urn:dvb:ipdc:esg:2005"
#define DATASTORE_NS "http://www.sun.com/xml/datastore"
#define SOAP_NS      "http://schemas.xmlsoap.org/soap/envelope/"

#define XMLNSEQUALS(uri) \
0 != pXmlNode->ns && 0 != pXmlNode->ns->href && \
rtxUTF8StrEqual (pXmlNode->ns->href, OSUTF8(uri))

#define XMLTAGEQUALS(tag) \
rtxUTF8StrEqual (pXmlNode->name, OSUTF8(#tag))

/*
 * Class:     com_sun_japex_jdsl_nativecode_JapexNativeDriver
 * Method:    initializeDriver
 * Signature: (Ljava/lang/Object;)V
 *
 * Default value of userData is null when this function is called.
 */
JNIEXPORT jobject JNICALL Java_com_sun_japex_jdsl_nativecode_JapexNativeDriver_initializeDriver
  (JNIEnv *env, jobject this, jobject userData) 
{
   return 0;
}

/*
 * Class:     com_sun_japex_jdsl_nativecode_JapexNativeDriver
 * Method:    prepare
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_sun_japex_jdsl_nativecode_JapexNativeDriver_prepare
  (JNIEnv *env, jobject this, jobject testCase, jobject userData) 
{
   int stat;
   FILE*        fp;
   xmlNodePtr pXmlNode;
   const char* inXmlFileName = getParam(env, testCase, "japex.inputFile");
   const char* modeStr = getParam(env, testCase, 
      "org.w3c.exi.ttf.measurementProperty");

   const char* compactionStr = getParam(env, this, 
      "org.w3c.exi.ttf.applicationClass");
   
   mode = Compactness;
   compactnessMode = Unknown;

   if (compactionStr) {
      if (strcmp (compactionStr, "neither") == 0)
         compactnessMode = Neither;
      else if (strcmp (compactionStr, "document") == 0)
         compactnessMode = Compression;
      else if (strcmp (compactionStr, "schema") == 0)
         compactnessMode = Schema;
      else if (strcmp (compactionStr, "both") == 0)
         compactnessMode = SchemaCompression;
   }

   if (compactnessMode == Unknown) {
      printf ("ERROR: compactness mode '%s' not recognized.\n", compactionStr);
      return;
   }

   stat = rtXmlInitContext (&ctxt);
   if (0 != stat) {
      printf ("context initialization failed\n");
      rtxErrPrint (&ctxt);
   }

   if (!(fp = fopen (inXmlFileName, "rb"))) {
      printf ("ERROR: test XML file %s not found.\n", inXmlFileName);
      len = 0;
      return;
   }
   RTDIAG2 (&ctxt, "XML filename is %s\n", inXmlFileName);

   fseek (fp, 0L, SEEK_END);
   fileLen = (int) ftell (fp);
   fseek (fp, 0L, SEEK_SET);
   
   if (fileLen < 0)
      fileLen = 0;
   
   if (compactnessMode == Compression) {
      Bytef* src = (Bytef*) malloc (fileLen);
      uLong dstLen = fileLen + fileLen/1000 + 12;
      Bytef* dst = (Bytef*) malloc (dstLen);
      int stat;

      fread (src, 1, fileLen, fp);
      stat = compress2(dst, &dstLen, src, fileLen, 9);

      if (stat != Z_OK)
         printf ("Comression fail: stat = %d\n", stat);
      
      compressedFileLen = (int) dstLen;

      free (src);
      free (dst);
   }

   fclose (fp);

   if (strcmp (modeStr, "encode") == 0)
      mode = Encode;
   else if (strcmp (modeStr, "decode") == 0)
      mode = Decode;
   else if (compactnessMode == Compression || 
	    compactnessMode == Neither) {
      return;
   }

   RTDIAG1 (&ctxt, "Parse XML file..\n");
   xmlInitParser();
   xmlThrDefKeepBlanksDefaultValue(0);
   xmlKeepBlanksDefault(0);
   xmlLineNumbersDefault(1);  /* set line numbers */

   pXmlDoc = xmlParseFile (inXmlFileName);

   if (0 == pXmlDoc) {
      printf ("Error parsing XML file %s\n", inXmlFileName);
      len = 0;
      return;
   }

   pXmlNode = xmlDocGetRootElement (pXmlDoc);

   RTDIAG2 (&ctxt, "XML doc root element is '%s'\n", pXmlNode->name);

   /* Open input file stream */

   stat = rtxStreamFileOpen (&ctxt, inXmlFileName, OSRTSTRMF_INPUT);
   if (stat != 0) {
      rtxErrPrint (&ctxt);
      return;
   }

   if (0 != pXmlNode->ns && 
       0 != pXmlNode->ns->href) {
     RTDIAG2 (&ctxt, "Namespace is %s\n", pXmlNode->ns->href);
   }

   RTDIAG1 (&ctxt, "Process document..\n");

   /* Ant */
#if 0
   if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("project"))) {
      Project* pvalue = rtxMemAllocTypeZ (&ctxt, Project);
      message = pvalue;
      msgType = ProjectMsg;

      asn1DOMTest_Project (&ctxt, pvalue, pXmlNode, TRUE);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_Project (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }
#endif
   /* AVCL */
   /* else */ if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("AVCL"))) {
      AVCL* pvalue = rtxMemAllocTypeZ (&ctxt, AVCL);
      message = pvalue;
      msgType = AVCLMsg;

      DOMTest_AVCL (&ctxt, pvalue, pXmlNode, TRUE);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_AVCL (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }

   /* BCAST */
   else if (XMLNSEQUALS (BCAST_NS)) {
      if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("ESGMainBCAST"))) {
         ESGMainBCAST* pvalue = rtxMemAllocTypeZ (&ctxt, ESGMainBCAST);
         message = pvalue;
         msgType = BCASTMsg;

         DOMTest_ESGMainBCAST (&ctxt, pvalue, pXmlNode, TRUE);
         rtxErrPrint (&ctxt);

         if (mode == Decode || mode == Compactness) {
            xe_setp (&ctxt, 0, 0);
            len = asn1E_ESGMainBCAST (&ctxt, pvalue, ASN1EXPL);
            buffer = xe_getp (&ctxt);
         }
      }
      else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Access"))) {
         AccessType* pvalue = rtxMemAllocTypeZ (&ctxt, AccessType);
         message = pvalue;
         msgType = BCASTAccessFrag;

         DOMTest_AccessType (&ctxt, pvalue, pXmlNode, TRUE);
         rtxErrPrint (&ctxt);

         if (mode == Decode || mode == Compactness) {
            xe_setp (&ctxt, 0, 0);
            len = asn1E_AccessType (&ctxt, pvalue, ASN1EXPL);
            buffer = xe_getp (&ctxt);
         }
      }
      else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Content"))) {
         ContentType* pvalue = rtxMemAllocTypeZ (&ctxt, ContentType);
         message = pvalue;
         msgType = BCASTContentFrag;

         DOMTest_ContentType (&ctxt, pvalue, pXmlNode, TRUE);
         rtxErrPrint (&ctxt);

         if (mode == Decode || mode == Compactness) {
            xe_setp (&ctxt, 0, 0);
            len = asn1E_ContentType (&ctxt, pvalue, ASN1EXPL);
            buffer = xe_getp (&ctxt);
         }
      }
      else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("InteractivityData"))) {
         InteractivityDataType* pvalue = rtxMemAllocTypeZ (&ctxt, InteractivityDataType);
         message = pvalue;
         msgType = BCASTInterFrag;

         DOMTest_InteractivityDataType (&ctxt, pvalue, pXmlNode, TRUE);
         rtxErrPrint (&ctxt);

         if (mode == Decode || mode == Compactness) {
            xe_setp (&ctxt, 0, 0);
            len = asn1E_InteractivityDataType (&ctxt, pvalue, ASN1EXPL);
            buffer = xe_getp (&ctxt);
         }
      }
      else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PreviewData"))) {
         PreviewDataType* pvalue = rtxMemAllocTypeZ (&ctxt, PreviewDataType);
         message = pvalue;
         msgType = BCASTPreviewFrag;

         DOMTest_PreviewDataType (&ctxt, pvalue, pXmlNode, TRUE);
         rtxErrPrint (&ctxt);

         if (mode == Decode || mode == Compactness) {
            xe_setp (&ctxt, 0, 0);
            len = asn1E_PreviewDataType (&ctxt, pvalue, ASN1EXPL);
            buffer = xe_getp (&ctxt);
         }
      }
      else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PurchaseItem"))) {
         PurchaseItemType* pvalue = rtxMemAllocTypeZ (&ctxt, PurchaseItemType);
         message = pvalue;
         msgType = BCASTPurchFrag;

         DOMTest_PurchaseItemType (&ctxt, pvalue, pXmlNode, TRUE);
         rtxErrPrint (&ctxt);

         if (mode == Decode || mode == Compactness) {
            xe_setp (&ctxt, 0, 0);
            len = asn1E_PurchaseItemType (&ctxt, pvalue, ASN1EXPL);
            buffer = xe_getp (&ctxt);
         }
      }
      else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Schedule"))) {
         ScheduleType* pvalue = rtxMemAllocTypeZ (&ctxt, ScheduleType);
         message = pvalue;
         msgType = BCASTSchedFrag;

         DOMTest_ScheduleType (&ctxt, pvalue, pXmlNode, TRUE);
         rtxErrPrint (&ctxt);

         if (mode == Decode || mode == Compactness) {
            xe_setp (&ctxt, 0, 0);
            len = asn1E_ScheduleType (&ctxt, pvalue, ASN1EXPL);
            buffer = xe_getp (&ctxt);
         }
      }
      else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Service"))) {
         ServiceType* pvalue = rtxMemAllocTypeZ (&ctxt, ServiceType);
         message = pvalue;
         msgType = BCASTSchedFrag;

         DOMTest_ServiceType (&ctxt, pvalue, pXmlNode, TRUE);
         rtxErrPrint (&ctxt);

         if (mode == Decode || mode == Compactness) {
            xe_setp (&ctxt, 0, 0);
            len = asn1E_ServiceType (&ctxt, pvalue, ASN1EXPL);
            buffer = xe_getp (&ctxt);
         }
      }
   }

   /* CBMS */
   else if (XMLNSEQUALS (CBMS_NS)) {
      if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Content"))) {
         CBMS_ContentType* pvalue = rtxMemAllocTypeZ (&ctxt, CBMS_ContentType);
         message = pvalue;
         msgType = CBMSContentFrag;

         DOMTest_CBMS_ContentType (&ctxt, pvalue, pXmlNode, TRUE);
         rtxErrPrint (&ctxt);

         if (mode == Decode || mode == Compactness) {
            xe_setp (&ctxt, 0, 0);
            len = asn1E_CBMS_ContentType (&ctxt, pvalue, ASN1EXPL);
            buffer = xe_getp (&ctxt);
         }
      }
      else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("ScheduleEvent"))) {
         CBMS_ScheduleEventType* pvalue = 
            rtxMemAllocTypeZ (&ctxt, CBMS_ScheduleEventType);
         message = pvalue;
         msgType = CBMSSchedFrag;

         DOMTest_CBMS_ScheduleEventType (&ctxt, pvalue, pXmlNode, TRUE);
         rtxErrPrint (&ctxt);

         if (mode == Decode || mode == Compactness) {
            xe_setp (&ctxt, 0, 0);
            len = asn1E_CBMS_ScheduleEventType (&ctxt, pvalue, ASN1EXPL);
            buffer = xe_getp (&ctxt);
         }
      }
      else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Acquisition"))) {
         CBMS_AcquisitionType* pvalue = 
            rtxMemAllocTypeZ (&ctxt, CBMS_AcquisitionType);
         message = pvalue;
         msgType = CBMSAcquisitionFrag;

         if (0 == rtXmlpMatchStartTag (&ctxt, OSUTF8("Acquisition"), 0)) {
            asn1Init_CBMS_AcquisitionType (pvalue);

            stat = XmlDec_CBMS_AcquisitionType (&ctxt, pvalue);

            rtXmlpMatchEndTag (&ctxt, -1);
         }

         rtxStreamClose (&ctxt);

         if (stat != 0) {
            printf ("decode CBMS Acquisition fragment failed\n");
            rtxErrPrint (&ctxt);
            len = 0;
         }
         else if (mode == Decode || mode == Compactness) {
            xe_setp (&ctxt, 0, 0);
            len = asn1E_CBMS_AcquisitionType (&ctxt, pvalue, ASN1EXPL);
            buffer = xe_getp (&ctxt);
         }
      }
      else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Service"))) {
         CBMS_ServiceType* pvalue = 
            rtxMemAllocTypeZ (&ctxt, CBMS_ServiceType);
         message = pvalue;
         msgType = CBMSServiceFrag;

         DOMTest_CBMS_ServiceType (&ctxt, pvalue, pXmlNode, TRUE);
         rtxErrPrint (&ctxt);

         if (mode == Decode || mode == Compactness) {
            xe_setp (&ctxt, 0, 0);
            len = asn1E_CBMS_ServiceType (&ctxt, pvalue, ASN1EXPL);
            buffer = xe_getp (&ctxt);
         }
      }
   }

   /* Dahut-sighting */
   else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("dahut-sighting"))) {
      Dahut_sighting* pvalue = rtxMemAllocTypeZ (&ctxt, Dahut_sighting);
      message = pvalue;
      msgType = DahutMsg;

      DOMTest_Dahut_sighting (&ctxt, pvalue, pXmlNode, TRUE);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_Dahut_sighting (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }

   /* Datastore */
   else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("dataStore"))) {
      DataStore* pvalue = rtxMemAllocTypeZ (&ctxt, DataStore);
      message = pvalue;
      msgType = DatastoreMsg;

      DOMTest_DataStore (&ctxt, pvalue, pXmlNode, TRUE);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_DataStore (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }

   /* FIXML */
   else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("FIXML"))) {
      FIXML_FIXML* pvalue = rtxMemAllocTypeZ (&ctxt, FIXML_FIXML);
      message = pvalue;
      msgType = FIXMLMsg;

      DOMTest_FIXML_FIXML (&ctxt, pvalue, pXmlNode, TRUE);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_FIXML_FIXML (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }

   /* FpML */
   else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("FpML"))) {
      FpML* pvalue = rtxMemAllocTypeZ (&ctxt, FpML);
      message = pvalue;
      msgType = FpMLMsg;

      DOMTest_FpML (&ctxt, pvalue, pXmlNode, TRUE);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_FpML (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }

   /* GAML */
   else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("GAML"))) {
      GAML* pvalue = rtxMemAllocTypeZ (&ctxt, GAML);
      message = pvalue;
      msgType = GAMLMsg;

      DOMTest_GAML (&ctxt, pvalue, pXmlNode, TRUE);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_GAML (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }

   /* HepRep */
   else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("heprep"))) {
      Heprep* pvalue = rtxMemAllocTypeZ (&ctxt, Heprep);
      message = pvalue;
      msgType = HepRepMsg;

      DOMTest_Heprep (&ctxt, pvalue, pXmlNode, TRUE);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_Heprep (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }

   /* MAGE-ML */
   else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("MAGE-ML"))) {
      MAGE_ML* pvalue = rtxMemAllocTypeZ (&ctxt, MAGE_ML);
      message = pvalue;
      msgType = MAGEMLMsg;

      DOMTest_MAGE_ML (&ctxt, pvalue, pXmlNode, TRUE);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_MAGE_ML (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }

   /* Open Office */
   else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("document"))) {
      Ns13_Document* pvalue = rtxMemAllocTypeZ (&ctxt, Ns13_Document);
      message = pvalue;
      msgType = OODocumentMsg;

      stat = XmlDec_Ns13_Document_PDU (&ctxt, pvalue);

      rtxStreamClose (&ctxt);

      if (stat != 0) {
         printf ("decode OpenOffice document failed\n");
         rtxErrPrint (&ctxt);
         return;
      }
      else if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_Ns13_Document (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }

   /* Seismic */
#if 1
   else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("seisdata"))) {
      Seisdata* pvalue = rtxMemAllocTypeZ (&ctxt, Seisdata);
      message = pvalue;
      msgType = SeisMsg;
      int stat = 0;

      if (0 == rtXmlpMatchStartTag (&ctxt, OSUTF8("seisdata"), 0)) {
	 asn1Init_Seisdata (pvalue);

	 stat = XmlDec_Seisdata (&ctxt, pvalue);

	 if (0 != stat) rtxErrPrint (&ctxt);
	 rtXmlpMatchEndTag (&ctxt, -1);
      }

      if (stat == 0 && (mode == Decode || mode == Compactness)) {
         stat = xe_setp (&ctxt, 0, 16596076);
         if (0 != stat) {
	   rtxErrPrint (&ctxt);
	   return;
	 }

         len = asn1E_Seisdata (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }
#endif
   /* SOAP */
   else if (XMLNSEQUALS (SOAP_NS)) {
      Envelope* pvalue = rtxMemAllocTypeZ (&ctxt, Envelope);
      message = pvalue;

      stat = XmlDec_Envelope_PDU (&ctxt, pvalue);

      rtxStreamClose (&ctxt);

      if (stat != 0) {
         printf ("decode of SOAP envelope failed\n");
         rtxErrPrint (&ctxt);
         return;
      }

      /* Decode body of message */

      if (pvalue->body.elem_list.count > 0) {
         OSXSDAny* pXSDAny = (OSXSDAny*)pvalue->body.elem_list.head->data;
         OSBOOL useBinary = FALSE;
         if (pXSDAny->t == OSXSDAny_xmlText) {
            OSOCTET* pbuf = (OSOCTET*)pXSDAny->u.xmlText;
            size_t buflen = rtxUTF8LenBytes (pXSDAny->u.xmlText);

            /* Create memory stream reader */
            stat = rtxStreamMemoryCreateReader (&ctxt, pbuf, buflen);
            if (stat != 0) {
               printf ("rtxStreamMemoryCreateReader failed\n");
               rtxErrPrint (&ctxt);
               rtxStreamClose (&ctxt);
               return;
            }

            if (0 == rtXmlpMatchStartTag (&ctxt, OSUTF8("Fault"), OSUTF8(SOAP_NS))) {
               Fault faultValue;
               asn1Init_Fault (&faultValue);
               stat = XmlDec_Fault (&ctxt, &faultValue);
               if (stat != 0) {
                  printf ("decode of SOAP fault failed\n");
                  rtxErrPrint (&ctxt);
                  rtxStreamClose (&ctxt);
                  return;
               }
               rtxStreamClose (&ctxt);

               /* Encode body in BER format */
               xe_setp (&ctxt, 0, 0); 

               len = asn1E_Fault (&ctxt, &faultValue, ASN1EXPL);
               if (len < 0) {
                  printf ("BER encode of SOAP fault failed\n");
                  rtxErrPrint (&ctxt);
                  return;
               }
               msgType = SOAPFaultMsg;
               useBinary = TRUE;
            }
            else {
               DoGoogleSearchResponse data;
               rtXmlpMarkLastEventActive (&ctxt);

               if (0 == rtXmlpMatchStartTag (&ctxt, OSUTF8("doGoogleSearchResponse"), 0)) {
                  /* Decode Google search data */
                  stat = XmlDec_DoGoogleSearchResponse (&ctxt, &data);
                  if (stat != 0) {
                     printf ("decode of search response failed\n");
                     rtxErrPrint (&ctxt);
                     rtxStreamClose (&ctxt);
                     return ;
                  }
                  rtXmlpMatchEndTag (&ctxt, -1);

                  rtxStreamClose (&ctxt);

                  /* Encode body in BER format */
                  xe_setp (&ctxt, 0, 0); 

                  len = asn1E_DoGoogleSearchResponse (&ctxt, &data, ASN1EXPL);
                  if (len < 0) {
                     printf ("BER encode of search response failed\n");
                     rtxErrPrint (&ctxt);
                     return ;
                  }
                  msgType = GoogleMsg;
                  useBinary = TRUE;
               }
            }
         }
         if (useBinary) {
            pXSDAny->t = OSXSDAny_binary;
            pXSDAny->u.binary = rtxMemAllocType (&ctxt, OSOpenType);
            pXSDAny->u.binary->numocts = len;
            pXSDAny->u.binary->data = xe_getp (&ctxt);
         }
      }

      /* Encode envelope + body in BER binary form */
      if (0 == len) {
         xe_setp (&ctxt, 0, 0); 
      }

      len = asn1E_Envelope (&ctxt, pvalue, ASN1EXPL);
      if (len < 0) {
         printf ("BER encode of SOAP envelope failed\n");
         rtxErrPrint (&ctxt);
         return ;
      }
   }

   /* SVG */
   else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("svg"))) {
      Svg* pvalue = rtxMemAllocTypeZ (&ctxt, Svg);
      message = pvalue;
      msgType = SVGMsg;
      int stat = 0;

      if (0 == rtXmlpMatchStartTag (&ctxt, OSUTF8("svg"), 0)) {
	 asn1Init_Svg (pvalue);
	 stat = XmlDec_Svg (&ctxt, pvalue);
	 if (0 != stat) rtxErrPrint (&ctxt);
	 rtXmlpMatchEndTag (&ctxt, -1);
      }

      if (stat == 0 && (mode == Decode || mode == Compactness)) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_Svg (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }

   /* Invoices */
   else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("invoice"))) {
      Invoice* pvalue = rtxMemAllocTypeZ (&ctxt, Invoice);
      message = pvalue;
      msgType = InvoiceMsg;

      DOMTest_Invoice (&ctxt, pvalue, pXmlNode, TRUE);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_Invoice (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }
   /* Factbook */
   else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("factbook"))) {
      Factbook* pvalue = rtxMemAllocTypeZ (&ctxt, Factbook);
      message = pvalue;
      msgType = FactbookMsg;

      DOMTest_Factbook (&ctxt, pvalue, pXmlNode, TRUE);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_Factbook (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }
   /* Periodic */
   else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("PERIODIC_TABLE"))) {
      PERIODIC_TABLE* pvalue = rtxMemAllocTypeZ (&ctxt, PERIODIC_TABLE);
      message = pvalue;
      msgType = PeriodicMsg;

      DOMTest_PERIODIC_TABLE (&ctxt, pvalue, pXmlNode, TRUE);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_PERIODIC_TABLE (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }
   /* Weblog */
   else if (rtxUTF8StrEqual (pXmlNode->name, OSUTF8("Weblog"))) {
      Weblog* pvalue = rtxMemAllocTypeZ (&ctxt, Weblog);
      message = pvalue;
      msgType = WeblogMsg;

      DOMTest_Weblog (&ctxt, pvalue, pXmlNode, TRUE);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_Weblog (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }
#ifdef UBL
   /* UBL */
   else if (rtxUTF8StrEqual (pXmlNode->name, "DespatchAdvice")) {
      DespatchAdvice* pvalue = rtxMemAllocTypeZ (&ctxt, DespatchAdvice);
      message = pvalue;
      msgType = DespatchAdviceMsg;

      asn1DOMTest_DespatchAdvice (&ctxt, pvalue, pXmlNode);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_DespatchAdvice (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }
   else if (rtxUTF8StrEqual (pXmlNode->name, "Invoice")) {
      InvoiceUBL* pvalue = rtxMemAllocTypeZ (&ctxt, InvoiceUBL);
      message = pvalue;
      msgType = InvoiceUBLMsg;

      asn1DOMTest_InvoiceUBL (&ctxt, pvalue, pXmlNode);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_InvoiceUBL (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }
   else if (rtxUTF8StrEqual (pXmlNode->name, "Order")) {
      Order* pvalue = rtxMemAllocTypeZ (&ctxt, Order);
      message = pvalue;
      msgType = OrderMsg;

      asn1DOMTest_Order (&ctxt, pvalue, pXmlNode);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_Order (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }
   else if (rtxUTF8StrEqual (pXmlNode->name, "OrderResponse")) {
      OrderResponse* pvalue = rtxMemAllocTypeZ (&ctxt, OrderResponse);
      message = pvalue;
      msgType = OrderResponseMsg;

      asn1DOMTest_OrderResponse (&ctxt, pvalue, pXmlNode);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_OrderResponse (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }
   else if (rtxUTF8StrEqual (pXmlNode->name, "OrderCancellation")) {
      OrderCancellation* pvalue = rtxMemAllocTypeZ (&ctxt, OrderCancellation);
      message = pvalue;
      msgType = OrderCancellationMsg;

      asn1DOMTest_OrderCancellation (&ctxt, pvalue, pXmlNode);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_OrderCancellation (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }
   else if (rtxUTF8StrEqual (pXmlNode->name, "OrderChange")) {
      OrderChange* pvalue = rtxMemAllocTypeZ (&ctxt, OrderChange);
      message = pvalue;
      msgType = OrderChangeMsg;

      asn1DOMTest_OrderChange (&ctxt, pvalue, pXmlNode);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_OrderChange (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }
   else if (rtxUTF8StrEqual (pXmlNode->name, "OrderResponseSimple")) {
      OrderResponseSimple* pvalue = 
         rtxMemAllocTypeZ (&ctxt, OrderResponseSimple);
      message = pvalue;
      msgType = OrderResponseSimpleMsg;

      asn1DOMTest_OrderResponseSimple (&ctxt, pvalue, pXmlNode);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_OrderResponseSimple (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }
   else if (rtxUTF8StrEqual (pXmlNode->name, "ReceiptAdvice")) {
      ReceiptAdvice* pvalue = rtxMemAllocTypeZ (&ctxt, ReceiptAdvice);
      message = pvalue;
      msgType = ReceiptAdviceMsg;

      asn1DOMTest_ReceiptAdvice (&ctxt, pvalue, pXmlNode);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_ReceiptAdvice (&ctxt, pvalue, ASN1EXPL);
         buffer = xe_getp (&ctxt);
      }
   }
#endif
   else { /* unknown */
      printf ("ERROR: XML document %s not supported\n", pXmlNode->name);
      mode = Compactness;
      len = 0;
   }

   if (len < 0) {
     rtxErrPrint (&ctxt);
     len = 0;
   }
}

/*
 * Class:     com_sun_japex_jdsl_nativecode_JapexNativeDriver
 * Method:    warmup
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_sun_japex_jdsl_nativecode_JapexNativeDriver_warmup
  (JNIEnv *env, jobject this, jobject testCase, jobject userData) 
{
}

/*
 * Class:     com_sun_japex_jdsl_nativecode_JapexNativeDriver
 * Method:    run
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_sun_japex_jdsl_nativecode_JapexNativeDriver_run
  (JNIEnv *env, jobject this, jobject testCase, jobject userData) 
{
   if (mode == Decode) {
      int stat = xd_setp (&ctxt, buffer, len, 0, 0);
   
      if (stat == RT_OK)
         switch (msgType) {
#if 0
         case ProjectMsg:
            stat = asn1D_Project (&ctxt, (Project*)message, ASN1EXPL, 0);
         break;
#endif
         case AVCLMsg:
            stat = asn1D_AVCL (&ctxt, (AVCL*)message, ASN1EXPL, 0);
         break;
         case BCASTMsg:
            stat = asn1D_ESGMainBCAST (&ctxt, (ESGMainBCAST*)message, ASN1EXPL, 0);
         break;
         case BCASTAccessFrag:
            stat = asn1D_AccessType (&ctxt, (AccessType*)message, ASN1EXPL, 0);
         break;
         case BCASTContentFrag:
            stat = asn1D_ContentType (&ctxt, (ContentType*)message, ASN1EXPL, 0);
         break;
         case BCASTInterFrag:
            stat = asn1D_InteractivityDataType (&ctxt, (InteractivityDataType*)message, ASN1EXPL, 0);
         break;
         case BCASTPreviewFrag:
            stat = asn1D_PreviewDataType (&ctxt, (PreviewDataType*)message, ASN1EXPL, 0);
         break;
         case BCASTPurchFrag:
            stat = asn1D_PurchaseItemType (&ctxt, (PurchaseItemType*)message, ASN1EXPL, 0);
         break;
         case BCASTSchedFrag:
            stat = asn1D_ScheduleType (&ctxt, (ScheduleType*)message, ASN1EXPL, 0);
         break;
         case BCASTServiceFrag:
            stat = asn1D_ServiceType (&ctxt, (ServiceType*)message, ASN1EXPL, 0);
         break;
         case CBMSAcquisitionFrag:
            stat = asn1D_CBMS_AcquisitionType (&ctxt, (CBMS_AcquisitionType*)message, ASN1EXPL, 0);
         break;
         case CBMSContentFrag:
            stat = asn1D_CBMS_ContentType (&ctxt, (CBMS_ContentType*)message, ASN1EXPL, 0);
         break;
         case CBMSSchedFrag:
            stat = asn1D_CBMS_ScheduleEventType (&ctxt, (CBMS_ScheduleEventType*)message, ASN1EXPL, 0);
         break;
         case CBMSServiceFrag:
            stat = asn1D_CBMS_ServiceType (&ctxt, (CBMS_ServiceType*)message, ASN1EXPL, 0);
	    break;
	 case DahutMsg:
	   stat = asn1D_Dahut_sighting (&ctxt, (Dahut_sighting*)message, ASN1EXPL, 0);
	   break;
	 case DatastoreMsg:
	   stat = asn1D_DataStore (&ctxt, (DataStore*)message, ASN1EXPL, 0);
	   break;
         case FIXMLMsg:
            stat = asn1D_FIXML_FIXML (&ctxt, (FIXML_FIXML*)message, ASN1EXPL, 0);
	    break;
         case FpMLMsg:
            stat = asn1D_FpML (&ctxt, (FpML*)message, ASN1EXPL, 0);
	    break;
         case GAMLMsg:
            stat = asn1D_GAML (&ctxt, (GAML*)message, ASN1EXPL, 0);
	    break;
         case GoogleMsg:
         case SOAPFaultMsg:
            stat = asn1D_Envelope (&ctxt, (Envelope*)message, ASN1EXPL, 0);
	    break;
         case MAGEMLMsg:
            stat = asn1D_MAGE_ML (&ctxt, (MAGE_ML*)message, ASN1EXPL, 0);
	    break;
         case HepRepMsg:
            stat = asn1D_Heprep (&ctxt, (Heprep*)message, ASN1EXPL, 0);
	    break;
         case OODocumentMsg:
            stat = asn1D_Ns13_Document (&ctxt, (Ns13_Document*)message, ASN1EXPL, 0);
            break;
         case SeisMsg:
            stat = asn1D_Seisdata (&ctxt, (Seisdata*)message, ASN1EXPL, 0);
	    break;
         case SVGMsg:
            stat = asn1D_Svg (&ctxt, (Svg*)message, ASN1EXPL, 0);
	    break;
         case InvoiceMsg:
            stat = asn1D_Invoice (&ctxt, (Invoice*)message, ASN1EXPL, 0);
	    break;
         case FactbookMsg:
            stat = asn1D_Factbook (&ctxt, (Factbook*)message, ASN1EXPL, 0);
	    break;
         case PeriodicMsg:
            stat = asn1D_PERIODIC_TABLE (&ctxt, (PERIODIC_TABLE*)message, ASN1EXPL, 0);
	    break;
         case WeblogMsg:
            stat = asn1D_Weblog (&ctxt, (Weblog*)message, ASN1EXPL, 0);
	    break;
#ifdef UBL
         case DespatchAdviceMsg:
            stat = asn1D_DespatchAdvice (&ctxt, (DespatchAdvice*)message, ASN1EXPL, 0);
	    break;
         case InvoiceUBLMsg:
            stat = asn1D_InvoiceUBL (&ctxt, (InvoiceUBL*)message, ASN1EXPL, 0);
         break;
         case OrderMsg:
            stat = asn1D_Order (&ctxt, (Order*)message, ASN1EXPL, 0);
         break;
         case OrderResponseMsg:
            stat = asn1D_OrderResponse (&ctxt, (OrderResponse*)message, ASN1EXPL, 0);
         break;
         case OrderCancellationMsg:
            stat = asn1D_OrderCancellation (&ctxt, (OrderCancellation*)message, ASN1EXPL, 0);
         break;
         case OrderChangeMsg:
            stat = asn1D_OrderChange (&ctxt, (OrderChange*)message, ASN1EXPL, 0);
         break;
         case OrderResponseSimpleMsg:
            stat = asn1D_OrderResponseSimple (&ctxt, (OrderResponseSimple*)message, ASN1EXPL, 0);
         break;
         case ReceiptAdviceMsg:
            stat = asn1D_ReceiptAdvice (&ctxt, (ReceiptAdvice*)message, ASN1EXPL, 0);
         break;
#endif
         }
   }
   else if (mode == Encode) {
      xe_setp (&ctxt, 0, 0);
   
      switch (msgType) {
#if 0
      case ProjectMsg:
         len = asn1E_Project (&ctxt, (Project*)message, ASN1EXPL);
         break;
#endif
      case FpMLMsg:
         len = asn1E_FpML (&ctxt, (FpML*)message, ASN1EXPL);
         break;
      case AVCLMsg:
         len = asn1E_AVCL (&ctxt, (AVCL*)message, ASN1EXPL);
         break;
      case BCASTMsg:
         len = asn1E_ESGMainBCAST (&ctxt, (ESGMainBCAST*)message, ASN1EXPL);
         break;
      case BCASTAccessFrag:
	len = asn1E_AccessType (&ctxt, (AccessType*)message, ASN1EXPL);
	break;
      case BCASTContentFrag:
	len = asn1E_ContentType (&ctxt, (ContentType*)message, ASN1EXPL);
	break;
      case BCASTInterFrag:
	len = asn1E_InteractivityDataType (&ctxt, (InteractivityDataType*)message, ASN1EXPL);
	break;
      case BCASTPreviewFrag:
	len = asn1E_PreviewDataType (&ctxt, (PreviewDataType*)message, ASN1EXPL);
	break;
      case BCASTPurchFrag:
	len = asn1E_PurchaseItemType (&ctxt, (PurchaseItemType*)message, ASN1EXPL);
	break;
      case BCASTSchedFrag:
	len = asn1E_ScheduleType (&ctxt, (ScheduleType*)message, ASN1EXPL);
	break;
      case BCASTServiceFrag:
	len = asn1E_ServiceType (&ctxt, (ServiceType*)message, ASN1EXPL);
	break;
      case CBMSAcquisitionFrag:
	len = asn1E_CBMS_AcquisitionType (&ctxt, (CBMS_AcquisitionType*)message, ASN1EXPL);
	break;
      case CBMSContentFrag:
	len = asn1E_CBMS_ContentType (&ctxt, (CBMS_ContentType*)message, ASN1EXPL);
	break;
      case CBMSSchedFrag:
	len = asn1E_CBMS_ScheduleEventType (&ctxt, (CBMS_ScheduleEventType*)message, ASN1EXPL);
	break;
      case CBMSServiceFrag:
	len = asn1E_CBMS_ServiceType (&ctxt, (CBMS_ServiceType*)message, ASN1EXPL);
	break;
      case DahutMsg:
	len = asn1E_Dahut_sighting (&ctxt, (Dahut_sighting*)message, ASN1EXPL);
	break;
      case DatastoreMsg:
	len = asn1E_DataStore (&ctxt, (DataStore*)message, ASN1EXPL);
	break;
      case FIXMLMsg:
	len = asn1E_FIXML_FIXML (&ctxt, (FIXML_FIXML*)message, ASN1EXPL);
	break;
      case GAMLMsg:
	len = asn1E_GAML (&ctxt, (GAML*)message, ASN1EXPL);
	break;
      case GoogleMsg:
      case SOAPFaultMsg:
         len = asn1E_Envelope (&ctxt, (Envelope*)message, ASN1EXPL);
         break;
      case MAGEMLMsg:
	len = asn1E_MAGE_ML (&ctxt, (MAGE_ML*)message, ASN1EXPL);
	break;
      case HepRepMsg:
	len = asn1E_Heprep (&ctxt, (Heprep*)message, ASN1EXPL);
	break;
      case OODocumentMsg:
         len = asn1E_Ns13_Document (&ctxt, (Ns13_Document*)message, ASN1EXPL);
         break;
      case SeisMsg:
	len = asn1E_Seisdata (&ctxt, (Seisdata*)message, ASN1EXPL);
	break;
      case SVGMsg:
	len = asn1E_Svg (&ctxt, (Svg*)message, ASN1EXPL);
	break;
      case InvoiceMsg:
	len = asn1E_Invoice (&ctxt, (Invoice*)message, ASN1EXPL);
	break;
      case FactbookMsg:
         len = asn1E_Factbook (&ctxt, (Factbook*)message, ASN1EXPL);
         break;
      case PeriodicMsg:
         len = asn1E_PERIODIC_TABLE (&ctxt, (PERIODIC_TABLE*)message, ASN1EXPL);
         break;
      case WeblogMsg:
         len = asn1E_Weblog (&ctxt, (Weblog*)message, ASN1EXPL);
         break;
#ifdef UBL
      case DespatchAdviceMsg:
         len = asn1E_DespatchAdvice (&ctxt, (DespatchAdvice*)message, ASN1EXPL);
         break;
      case InvoiceUBLMsg:
         len = asn1E_InvoiceUBL (&ctxt, (InvoiceUBL*)message, ASN1EXPL);
         break;
      case OrderMsg:
         len = asn1E_Order (&ctxt, (Order*)message, ASN1EXPL);
         break;
      case OrderResponseMsg:
         len = asn1E_OrderResponse (&ctxt, (OrderResponse*)message, ASN1EXPL);
         break;
      case OrderCancellationMsg:
         len = asn1E_OrderCancellation (&ctxt, (OrderCancellation*)message, ASN1EXPL);
         break;
      case OrderChangeMsg:
         len = asn1E_OrderChange (&ctxt, (OrderChange*)message, ASN1EXPL);
         break;
      case OrderResponseSimpleMsg:
         len = asn1E_OrderResponseSimple (&ctxt, (OrderResponseSimple*)message, ASN1EXPL);
         break;
      case ReceiptAdviceMsg:
         len = asn1E_ReceiptAdvice (&ctxt, (ReceiptAdvice*)message, ASN1EXPL);
         break;
#endif
      }

      xe_free (&ctxt);
   }
}

/*
 * Class:     com_sun_japex_jdsl_nativecode_JapexNativeDriver
 * Method:    finish
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_sun_japex_jdsl_nativecode_JapexNativeDriver_finish
  (JNIEnv *env, jobject this, jobject testCase, jobject userData) 
{
   OSBOOL throwEx = FALSE;
   if (mode == Compactness) {
      if (compactnessMode == Neither)
         len = fileLen;
      else if (compactnessMode == Compression)
         len = compressedFileLen;
      else if (compactnessMode == SchemaCompression) {
	if (len > 0) {
	  uLong dstLen = len + len/1000 + 12;
	  Bytef* dst = (Bytef*) malloc (dstLen);

	  int stat = compress2 (dst, &dstLen, buffer, len, 9);

	  if (stat != Z_OK) {
            printf ("Comression fail: stat = %d\n", stat);
            len = 0;
          }
          else
             len = (int) dstLen;

	  free (dst);
	}
	else len = 0;
      }

      if (len <= 0) { throwEx = TRUE; }
      else setLongParam(env, testCase, "japex.resultValue", len);
   }

   xmlFreeDoc (pXmlDoc);
   xmlCleanupParser();
   rtFreeContext (&ctxt);

   if (throwEx) {
      jclass newExcCls =
         (*env)->FindClass(env, "java/lang/RuntimeException");
      (*env)->ThrowNew(env, newExcCls, "Encoded data size is <= 0");
   }

}

/*
 * Class:     com_sun_japex_jdsl_nativecode_JapexNativeDriver
 * Method:    terminateDriver
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_sun_japex_jdsl_nativecode_JapexNativeDriver_terminateDriver
  (JNIEnv *env, jobject this, jobject userData) 
{
}

/* ---- THE FOLLOWING TWO METHODS SHOW HOW TO ACCESS DRIVER PARAMS ----- */

const char* getParam(JNIEnv *env, jobject this, const char *name)
{
    jclass cls;
    jmethodID mid;
    jstring value;

    cls = (*env)->GetObjectClass(env, this);
    mid = (*env)->GetMethodID(env, cls, "getParam", "(Ljava/lang/String;)Ljava/lang/String;");
    value = (jstring) (*env)->CallObjectMethod(env, this, mid, (*env)->NewStringUTF(env, name));
    return value == NULL ? (const char*) value : (*env)->GetStringUTFChars(env, value, NULL);
}

void setLongParam(JNIEnv *env, jobject this, const char *name, long value) 
{
    jclass cls;
    jmethodID mid;

    cls = (*env)->GetObjectClass(env, this);
    mid = (*env)->GetMethodID(env, cls, "setLongParam", "(Ljava/lang/String;J)V");
    (*env)->CallVoidMethod(env, this, mid, (*env)->NewStringUTF(env, name), (jlong)value);
}

long getLongParam(JNIEnv *env, jobject this, const char *name) 
{
    jclass cls;
    jmethodID mid;

    cls = (*env)->GetObjectClass(env, this);
    mid = (*env)->GetMethodID(env, cls, "getLongParam", "(Ljava/lang/String;)J");
    return (*env)->CallLongMethod(env, this, mid, (*env)->NewStringUTF(env, name));
}

/* ------- UTILITY METHODS TO CONVERT DIRECT BUFFERS INTO OBJECTS ------ */

jobject userDataToObject(JNIEnv *env, void *userData, int size) {
    return (*env)->NewDirectByteBuffer(env, userData, size);
}

void* objectToUserData(JNIEnv *env, jobject object) {
    return (*env)->GetDirectBufferAddress(env, object);
}

/* --------------------- DO NOT EDIT BELOW THIS LINE ------------------- */

jlong timeMillis() {
   #ifdef _MSC_VER
      clock_t t = clock();
      return t;
   #else
      struct timeval t;
      gettimeofday(&t, 0);
      return (jlong)(((long)t.tv_sec) * 1000L + ((long)t.tv_usec) / 1000L);
   #endif
}

/*
 * Class:     japexjni_NativeDriver
 * Method:    runLoopDuration
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_sun_japex_jdsl_nativecode_JapexNativeDriver_runLoopDuration
  (JNIEnv *env, jobject this, jdouble duration, jobject userData) 
{
    jclass cls;
    jfieldID fid;
    jobject _testCase;
    jlong startTime, endTime, currentTime;
    jint iterations;

    /* Get a reference to _testCase */
    cls = (*env)->GetObjectClass(env, this);
    fid = (*env)->GetFieldID(env, cls, "_testCase", "Lcom/sun/japex/TestCaseImpl;");
    _testCase = (*env)->GetObjectField(env, this, fid);
    
    startTime = timeMillis();
    endTime = startTime + (jlong)duration;

    currentTime = 0;
    iterations = 0;
    do {
        Java_com_sun_japex_jdsl_nativecode_JapexNativeDriver_run(env, this, _testCase, userData);
        iterations++;
        currentTime = timeMillis();
    } while (endTime >= currentTime);

    return iterations;
}

/*
 * Class:     japexjni_NativeDriver
 * Method:    runLoopIterations
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_sun_japex_jdsl_nativecode_JapexNativeDriver_runLoopIterations
  (JNIEnv *env, jobject this, jint iterations, jobject userData) 
{
    jclass cls;
    jfieldID fid;
    jobject _testCase;
    int i;

    /* Get a reference to _testCase */
    cls = (*env)->GetObjectClass(env, this);
    fid = (*env)->GetFieldID(env, cls, "_testCase", "Lcom/sun/japex/TestCaseImpl;");
    _testCase = (*env)->GetObjectField(env, this, fid);

    for (i = 0; i < iterations; i++) {
        Java_com_sun_japex_jdsl_nativecode_JapexNativeDriver_run(env, this, _testCase, userData);
    }
}
