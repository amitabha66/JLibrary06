/**
 * Driver to measure libxml2 processing efficiency.
 *
 * Measures the time to parse XML (in memory) and invoke empty SAX handler 
 * callbacks.
 *
 * Developed for Linux or a similar UNIX platform.  Libxml2 is assumed to be 
 * installed in the /usr/include (header files) and /usr/lib (libraries) 
 * directories.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _MSC_VER
   #include <time.h>
#else
   #include <sys/time.h>
#endif

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlsave.h>
#include <com_sun_japex_jdsl_nativecode_JapexNativeDriver.h>

#define Byte z_Byte
#include "zlib.h"
#undef z_Byte

static int g_compressed = 0;

/*
 * These functions are defined towards the bottom of this file
 */
jobject userDataToObject(JNIEnv *env, void *userData, int size);
void* objectToUserData(JNIEnv *env, jobject object);
void setLongParam(JNIEnv *env, jobject this, const char *name, long value);
long getLongParam(JNIEnv *env, jobject this, const char *name);
const char* getParam(JNIEnv *env, jobject this, const char *name);

typedef enum {
   Compactness,
   Encode,
   Decode
} Mode; 

/*
 * Sample UserData struct
 */
struct UserData {
   xmlSAXHandlerPtr xmlSAXHandler;
   uLong  xmltextlen;
   char*  xmltext;
   Bytef* compressedData;
   uLong  compressedDataLen;
   Mode   mode;
   xmlDocPtr pXmlDoc;
};

/*
 * Note: A global instance of UserData is being maintained for now to avoid 
 * the overhead of having to fetch this from a Java object on each 
 * invocation of the run function.
 */
static struct UserData* g_UserData_ptr = 0;

/*
 * Function to read XML file into memory
 */
static int readXMLFile (const char* filePath, char** ppmsgbuf)
{
   FILE* fp = fopen (filePath, "rb");
   if (0 != fp) {
      long len;
      fseek (fp, 0L, SEEK_END);
      if ((len = ftell(fp)) != -1L) {
         char* msgbuf = (char*) malloc (len+1);
         if (msgbuf == NULL) {
            fclose (fp);
            return -1;
         }
         fseek (fp, 0L, SEEK_SET);

         fread (msgbuf, 1, len, fp);
         fclose (fp);

         msgbuf[len] = '\0';
         *ppmsgbuf = msgbuf;

         return 0;
      }
      else {
         fclose (fp);
      }
   }
   return -1;
}

/*
 * SAX callback functions.  These contain printf statements to verify 
 * operation. Once this is done, the internals should be commented (compile 
 * without -D_TRACE) to run actual tests.
 */
void startDocument (void* userData)
{
#ifdef _TRACE
   printf ("startDocument\n");
#endif
}

void endDocument (void* userData)
{
#ifdef _TRACE
   printf ("endDocument\n");
#endif
}

void startElement 
(void* userData, const xmlChar* name, const xmlChar** attrs)
{
#ifdef _TRACE
   printf ("startElement: name = %s\n", name);
#endif
}

void endElement 
(void* userData, const xmlChar* name)
{
#ifdef _TRACE
   printf ("endElement: name = %s\n", name);
#endif
}

void characters 
(void* userData, const xmlChar* ch, int len)
{
#ifdef _TRACE
   int i;
   printf ("characters: ch = '\n");
   for (i = 0; i < len; i++) {
      putchar (ch[i]);
   }
   printf ("'\n");
#endif
}

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
   struct UserData* ud;

   /*
    * Create and initialize an instance of UserData. Use 
    * userDataToObject() to return it as a Java object.
    */
   ud = (struct UserData*) malloc(sizeof(struct UserData));
   ud->xmltext = 0;

   ud->xmlSAXHandler = (xmlSAXHandlerPtr) malloc (sizeof(xmlSAXHandler));
   memset (ud->xmlSAXHandler, 0, sizeof(xmlSAXHandler));

   ud->xmlSAXHandler->startDocument = startDocument;
   ud->xmlSAXHandler->endDocument = endDocument;
   ud->xmlSAXHandler->startElement = startElement;
   ud->xmlSAXHandler->endElement = endElement;
   ud->xmlSAXHandler->characters = characters;

   g_UserData_ptr = ud;

   return userDataToObject(env, ud, sizeof(struct UserData));
}

/*
 * Class:     com_sun_japex_jdsl_nativecode_JapexNativeDriver
 * Method:    prepare
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_sun_japex_jdsl_nativecode_JapexNativeDriver_prepare
  (JNIEnv *env, jobject this, jobject testCase, jobject userData) 
{
   jclass exceptionClass;
   const char* testFile;
   struct UserData *ud = g_UserData_ptr;

   const char* modeStr = 
      getParam (env, testCase, "org.w3c.exi.ttf.measurementProperty");

   const char* compactionStr = 
      getParam (env, this, "org.w3c.exi.ttf.applicationClass");
   
   if (compactionStr) {
      if (strcmp (compactionStr, "neither") == 0)
         g_compressed = 0;
      else if (strcmp (compactionStr, "document") == 0)
         g_compressed = 1;
   }

   testFile = getParam (env, testCase, "japex.inputFile");
   
   if (strcmp (modeStr, "encode") == 0) {
      ud->mode = Encode;

      xmlInitParser();
      xmlThrDefKeepBlanksDefaultValue(0);
      xmlKeepBlanksDefault(0);
      xmlLineNumbersDefault(1);  /* set line numbers */

      ud->pXmlDoc = xmlParseFile (testFile);

      if (0 == ud->pXmlDoc) {
         printf ("ERROR: parse XML file %s to DOM tree.\n", testFile);
         return;
      }
   }
   else if (strcmp (modeStr, "decode") == 0) {
      ud->mode = Decode;

      if (readXMLFile (testFile, &ud->xmltext) != 0) {
         printf ("ERROR: test XML file %s not found.\n", testFile);
         return;
      }

      ud->xmltextlen = strlen (ud->xmltext);

      /* If document mode, compress buffer */
      if (g_compressed) {
         ud->compressedDataLen = ud->xmltextlen + ud->xmltextlen/1000 + 12;
         ud->compressedData = (Bytef*) malloc (ud->compressedDataLen);
         int stat;

         stat = compress2 (ud->compressedData, &ud->compressedDataLen, 
                           (Bytef*)ud->xmltext, ud->xmltextlen, 9);

         if (stat != Z_OK)
            printf ("Compression fail: stat = %d\n", stat);
      }
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
   struct UserData *ud = g_UserData_ptr;

   if (ud->xmltext == 0)
      return;

   if (ud->mode == Decode) {
      /* If compressed, uncompress here before parsing */
      if (g_compressed) {
         int stat = uncompress 
            ((Bytef*)ud->xmltext, &ud->xmltextlen, 
             ud->compressedData, ud->compressedDataLen);

         if (stat != Z_OK)
            printf ("Decompression fail: stat = %d\n", stat);
      }
      if (xmlSAXUserParseMemory (ud->xmlSAXHandler, 0, 
                                 ud->xmltext, ud->xmltextlen) < 0)
      {
         printf ("ERROR: parsing XML.\n");
         return;
      }
   }
   else if (ud->mode == Encode) {
      xmlChar* pmembuf = 0;
      int memlen;

      /* serialize DOM tree to in-memory XML document */
      xmlDocDumpFormatMemoryEnc (ud->pXmlDoc, &pmembuf, &memlen, "UTF-8", 1);

      /* if compressed, compress encoded data here */
      if (g_compressed) {
         uLong dstLen = memlen + memlen/1000 + 12;
         Bytef* dst = (Bytef*) malloc (dstLen);
         int stat;

         stat = compress2 (dst, &dstLen, (Bytef*)pmembuf, memlen, 9);

         if (stat != Z_OK)
            printf ("Comression fail: stat = %d\n", stat);
      
         free (dst);
      }

      /* free allocated memory */
      if (0 != pmembuf)
         xmlFree (pmembuf);
      else
         printf ("Document encode failed.\n");
   }
   else {
      printf ("Unknown mode = %d\n", ud->mode);
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
}

/*
 * Class:     com_sun_japex_jdsl_nativecode_JapexNativeDriver
 * Method:    terminateDriver
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_sun_japex_jdsl_nativecode_JapexNativeDriver_terminateDriver
  (JNIEnv *env, jobject this, jobject userData) 
{
    /*
     * Free memory allocated for the UserData instance.
     */
    struct UserData *ud = objectToUserData(env, userData);
    free(ud);
}

/* ---- THE FOLLOWING TWO METHODS SHOW HOW TO ACCESS DRIVER PARAMS ----- */

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

const char* getParam(JNIEnv *env, jobject this, const char *name)
{
    jclass cls;
    jmethodID mid;
    jstring value;

    cls = (*env)->GetObjectClass(env, this);
    mid = (*env)->GetMethodID(env, cls, "getParam", "(Ljava/lang/String;)Ljava/lang/String;");
    value = (jstring) (*env)->CallObjectMethod(env, this, mid, (*env)->NewStringUTF(env, name));
    return (*env)->GetStringUTFChars(env, value, NULL);
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
