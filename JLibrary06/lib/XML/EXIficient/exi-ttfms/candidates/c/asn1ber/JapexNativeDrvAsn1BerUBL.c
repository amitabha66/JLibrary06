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

#include "UBL-DespatchAdvice-1-0.h"
#include "UBL-Invoice-1-0.h"
#include "UBL-Order-1-0.h"
#include "UBL-OrderCancellation-1-0.h"
#include "UBL-OrderChange-1-0.h"
#include "UBL-OrderResponse-1-0.h"
#include "UBL-OrderResponseSimple-1-0.h"
#include "UBL-ReceiptAdvice-1-0.h"

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

enum Mode {
   Compactness,
   Encode,
   Decode
} mode; 

void* message;
OSOCTET* buffer;

enum MessageType {
   DespatchAdviceMsg,
   InvoiceMsg,
   OrderMsg,
   OrderResponseMsg,
   OrderCancellationMsg,
   OrderChangeMsg,
   OrderResponseSimpleMsg,
   ReceiptAdviceMsg
} msgType; 

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
   const char* modeStr = getParam(env, testCase, "org.w3c.exi.ttf.measurementProperty");
   
   mode = Compactness;

   stat = rtInitContext (&ctxt);
   if (0 != stat) {
      printf ("context initialization failed\n");
      rtxErrPrint (&ctxt);
   }

   if (!(fp = fopen (inXmlFileName, "r"))) {
      printf ("ERROR: test XML file %s not found.\n", inXmlFileName);
      len = 0;
      return;
   }
   fclose (fp);

   if (strcmp (modeStr, "encode") == 0)
      mode = Encode;
   else if (strcmp (modeStr, "decode") == 0)
      mode = Decode;

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

   /* UBL */
   if (rtxUTF8StrEqual (pXmlNode->name, "DespatchAdvice")) {
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
      Invoice* pvalue = rtxMemAllocTypeZ (&ctxt, Invoice);
      message = pvalue;
      msgType = InvoiceMsg;

      asn1DOMTest_Invoice (&ctxt, pvalue, pXmlNode);
      rtxErrPrint (&ctxt);

      if (mode == Decode || mode == Compactness) {
         xe_setp (&ctxt, 0, 0);
         len = asn1E_Invoice (&ctxt, pvalue, ASN1EXPL);
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
   else { /* unknown */
      printf ("ERROR: XML document %s not supported\n", pXmlNode->name);
      mode = Compactness;
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
         case DespatchAdviceMsg:
            stat = asn1D_DespatchAdvice (&ctxt, (DespatchAdvice*)message, ASN1EXPL, 0);
         break;
         case InvoiceMsg:
            stat = asn1D_Invoice (&ctxt, (Invoice*)message, ASN1EXPL, 0);
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
         }
   }
   else if (mode == Encode) {
      xe_setp (&ctxt, 0, 0);
      switch (msgType) {
      case DespatchAdviceMsg:
         len = asn1E_DespatchAdvice (&ctxt, (DespatchAdvice*)message, ASN1EXPL);
         break;
      case InvoiceMsg:
         len = asn1E_Invoice (&ctxt, (Invoice*)message, ASN1EXPL);
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
   if (mode == Compactness)
      setLongParam(env, testCase, "japex.resultValue", len);

   xmlFreeDoc (pXmlDoc);
   xmlCleanupParser();
   rtFreeContext (&ctxt);
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
  (JNIEnv *env, jobject this, jlong duration, jobject userData) 
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
    endTime = startTime + duration;

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
