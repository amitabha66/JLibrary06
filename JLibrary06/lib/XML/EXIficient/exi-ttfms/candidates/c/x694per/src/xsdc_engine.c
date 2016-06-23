/*****************************************************************************/
/* Copyright (C) 2006 OSS Nokalva, Inc.  All rights reserved.                */
/*****************************************************************************/
/*****************************************************************************
 * $Id: xsdc_engine.c,v 1.7 2007/02/19 22:28:08 pthorpe Exp $
 *****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <ossxsd.h>
#include "engine.h"
#include "utils.h"
#include <ossxsd.h>

typedef struct _tag_OssXsdContext {
    // OSS runtime context
    struct ossxEnv env;
    // Indicates if ossxterm() should be called on cleanup
    int initialized:1;
    // Specifies action
    int action;
    // Binary encoding used for parsing
    int enc_length;
    void *encoded;
    // Value used for serialization
    int globElemNum;
    void *decoded;
    // Optional preallocated buffer for parsing
    void *preallocated;
    // Length of preallocated buffer
    int pre_length;
    // Handle of shared library containing precompiled schema
    void *h_ctl_tbl;
} OSS_XSDC_CONTEXT;

// Options
#define PER_ALIGNED 1
#define PREALLOCATE 2
#define VALIDATE    4
#define COMPRESS    8
#define GZIP	    16

#define GETHEADER "ossxGetHeader"

typedef void * (*GET_HEADER)(void);

/*
 * These functions are defined towards the bottom of this file
 */

// Executes PARSE transaction
static int parse(JNIEnv *env, void *context);
// Executes SERIALIZE transaction
static int serialize(JNIEnv *env, void *context);
// Selects appropriate transaction for benchmarking
static TRANSACTION define_transaction(JNIEnv *env, OSS_XSDC_CONTEXT *ctx);
// Cleanup routine
static void cleanup(OSS_XSDC_CONTEXT *ctx);
// Load shared library containing precompiled schema
static void *loadPrecompiledSchema(JNIEnv *env, jbyteArray path, OSS_XSDC_CONTEXT *ctx);
// Unload shared library containing precompiled schema
static void unloadPrecompiledSchema(OSS_XSDC_CONTEXT *ctx);
static const char* getParam(JNIEnv *env, jobject this, const char *name);

/*
 * Method:    engine_initializeDriver
 * Signature: (Ljava/lang/Object;)V
 *
 * Default value of context is null when this function is called.
 */
JNIEXPORT jobject JNICALL engine_initializeDriver
  (JNIEnv *env, jobject this_, jobject context, jint options) 
{
    /*
     * Create and initialize an instance of UserData. Use 
     * userDataToObject() to return it as a Java object.
     */
    OSS_XSDC_CONTEXT *ctx = NULL;
    jclass cls;
    jmethodID mid;
    
    cls = (*env)->GetObjectClass(env, this_);
    mid = (*env)->GetMethodID(
	env, 
	cls, 
	"initPrecompiledSchemas", 
	"()V");
    if (mid != NULL)
	(*env)->CallVoidMethod(env, this_, mid);
    if ((*env)->ExceptionCheck(env))
	return NULL;

    ctx = malloc(sizeof(OSS_XSDC_CONTEXT));

    if (ctx != NULL) {
	memset(ctx, 0, sizeof(OSS_XSDC_CONTEXT));
	context = userDataToObject(env, ctx, sizeof(OSS_XSDC_CONTEXT));
	if (context == NULL) {
	    free(ctx);
	    ThrowError(
		env,
		"java/lang/Error", 
		"The JVM is incompartible with the driver: it does not support the %s API", 
		"NewDirectByteBuffer()");
	} else
	    return context;
    } else
	ThrowError(
	    env, 
	    "java/lang/OutOfMemoryError", 
	    "Not enough memory to allocate context");

    return NULL;
}

/*
 * Method:    engine_prepare
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL engine_prepare
  (JNIEnv *env, jobject this_, jobject testCase, jobject context, jint options) 
{
    int rc;
    // Initialize the runtime
    OSS_XSDC_CONTEXT *ctx = (OSS_XSDC_CONTEXT *)objectToUserData(env, context);
    struct ossxEnv *e = &ctx->env; 
    jclass cls;
    jmethodID mid;
    jbyteArray xml = NULL;
    jsize xml_length;
    jbyte *data;
    jboolean is_copy;
    int action;
    jbyteArray path = NULL;
    OssxBuf encoding;
    void *ctl_tbl;
    const char *cmode;

    memset(ctx, 0, sizeof(OSS_XSDC_CONTEXT));
    action = getActionID(env, this_);
    HANDLE_EXCEPTION;

    // Die if the options cannot be fulfilled
    cmode = getParam(env, this_, "org.w3c.exi.ttf.applicationClass");
    if (!strcmp(cmode, "neither") || !strcmp(cmode, "document")) {
	ThrowError(
	    env,
	    "java/lang/RuntimeException", 
	    "This engine cannot function without schema-level optimization");
	return;
    }

    cls = (*env)->GetObjectClass(env, this_);
    mid = (*env)->GetMethodID(
	env, 
	cls, 
	"getEncodedPrecompiledXMLSchemaPath", 
	"(Lcom/sun/japex/TestCase;)[B");
    if (mid != NULL)
	path = (*env)->CallObjectMethod(env, this_, mid, testCase);
    HANDLE_EXCEPTION;

    ctl_tbl = loadPrecompiledSchema(env, path, ctx);
    HANDLE_EXCEPTION;

    rc = ossxinit(e, ctl_tbl);
    if (rc) {
	ThrowError(
	    env,
	    "java/lang/RuntimeException", 
	    "Runtime initialization has failed. Error code = %d", 
	    rc);
	cleanup(ctx);
	return;
    }
    ctx->initialized = 1;
    ctx->action = action;

    // Configure the coder
    ossxSetEncodingMethod(e, OSSX_XML);
    ossxSetFlags(e, OSSX_NOCONSTRAIN | OSSX_NOTRAPPING);

    // Get XML document
    mid = (*env)->GetMethodID(env, cls, "getInputAsByteArray", 
	"()[B");
    if (mid != NULL)
	xml = (*env)->CallObjectMethod(env, this_, mid);
    HANDLE_EXCEPTION;

    if (xml == NULL || (xml_length = (*env)->GetArrayLength(env, xml)) == 0) {
	ThrowError(
	    env,
	    "java/lang/RuntimeException", 
	    "Length of test input data is zero");
	cleanup(ctx);
	return;
    }
    data = (*env)->GetByteArrayElements(env, xml, &is_copy);
    // Decode XML to C structure
    encoding.value = (unsigned char *)data;
    encoding.length = xml_length;
    rc = ossxDecode(e, &ctx->globElemNum, &encoding, &ctx->decoded);
    (*env)->ReleaseByteArrayElements(env, xml, data, JNI_ABORT);
    if (rc) {
	char *msg = ossxGetErrMsg(e);
	if (msg == NULL) msg = "N/A";
	ThrowError(
	    env,
	    "java/lang/RuntimeException", 
	    "Parsing of input XML has failed. Error: %d (%s)", rc, msg);
	cleanup(ctx);
	return;
    }
    // Select appropriate binary encoding style
    if ((options & COMPRESS)) {
        if ((options & PER_ALIGNED))
            ossxSetEncodingMethod(e, OSSX_PER_ALIGNED);
        else
            ossxSetEncodingMethod(e, OSSX_PER_UNALIGNED);
    }
    if (options & GZIP)
	ossxSetFlags(e, ossxGetFlags(e) | OSSX_USE_COMPRESSION);

    // Reencode to binary if parser is being benchmarked
    if (action == PARSING || action == SIZING) {
	// Preallocate decoder's buffer is requested
	if (action == PARSING && (options & PREALLOCATE)) {
	    int size = ossxGetDecodingLength(e);
	    size *= 2;
	    ctx->preallocated = malloc(size);
	    if (ctx->preallocated == NULL) {
		ThrowError(
		    env,
		    "java/lang/OutOfMemoryError", 
		    "Not enough memory to preallocate buffer for the decoder");
		cleanup(ctx);
		return;
	    }
	    ctx->pre_length = size;
	}
	encoding.length = 0;
	encoding.value = NULL;
	rc = ossxEncode(e, ctx->globElemNum, ctx->decoded, &encoding);
	ossxFreeGlobElem(e, ctx->globElemNum, ctx->decoded);
	ctx->decoded = NULL;
	if (rc) {
	    char *msg = ossxGetErrMsg(e);
	    if (msg == NULL) msg = "N/A";
	    ThrowError(
		env,
		"java/lang/RuntimeException", 
		"Reencoding of value has failed. Error: %d (%s)", rc, msg);
	    cleanup(ctx);
	    return;
	}
	ctx->enc_length = encoding.length;
	ctx->encoded = encoding.value;
	// Enable validation for parser if necessary
	if (action == PARSING && (options & VALIDATE))
	    ossxSetDecodingFlags(e, OSSX_NOTRAPPING);
    } else if (action == SERIALIZING) {
	encoding.length = 0;
	encoding.value = NULL;
	rc = ossxEncode(e, ctx->globElemNum, ctx->decoded, &encoding);
	if (rc) {
	    char *msg = ossxGetErrMsg(e);
	    if (msg == NULL) msg = "N/A";
	    ThrowError(
		env,
		"java/lang/RuntimeException", 
		"Reencoding of value has failed. Error: %d (%s)", rc, msg);
	    cleanup(ctx);
	    return;
	}
	ctx->enc_length = encoding.length;
	ctx->encoded = encoding.value;
	// Preallocate encoder's buffer if requested
	if ((options & PREALLOCATE)) {
	    ctx->pre_length = ctx->enc_length;
	    ctx->preallocated = ctx->encoded;
	}
    }
}

/*
 * Method:    engine_warmup
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL engine_warmup
  (JNIEnv *env, jobject this_, jobject testCase, jobject context, jint options) 
{
    // Do nothing
}

/*
 * Method:    engine_run
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL engine_run
  (JNIEnv *env, jobject this_, jobject testCase, jobject context, jint options) 
{
    OSS_XSDC_CONTEXT *ctx = (OSS_XSDC_CONTEXT *)objectToUserData(env, context);
    TRANSACTION x = define_transaction(env, ctx);

    (*x)(env, ctx);
}

/*
 * Method:    engine_finish
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL engine_finish
  (JNIEnv *env, jobject this_, jobject testCase, jobject context, jint options) 
{
    OSS_XSDC_CONTEXT *ctx = (OSS_XSDC_CONTEXT *)objectToUserData(env, context);

    if (ctx->action == SIZING || ctx->action == SERIALIZING) {
        postEncoding(env, this_, ctx->encoded, ctx->enc_length);
	HANDLE_EXCEPTION;
    }
    cleanup(ctx);
}   

/*
 * Method:    engine_terminateDriver
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL engine_terminateDriver
  (JNIEnv *env, jobject this_, jobject context, jint options) 
{
    /*
     * Free memory allocated for the context.
     */
    OSS_XSDC_CONTEXT *ctx = (OSS_XSDC_CONTEXT *)objectToUserData(env, context);
    if (ctx != NULL)
	free(ctx);
}

/* --------------------- DO NOT EDIT BELOW THIS LINE ------------------- */

/*
 * Method:    engine_runLoopDuration
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL engine_runLoopDuration
  (JNIEnv *env, jobject this_, jdouble duration, jobject context, jint options) 
{
    OSS_XSDC_CONTEXT *ctx = (OSS_XSDC_CONTEXT *)objectToUserData(env, context);
    TRANSACTION x = define_transaction(env, ctx);

    return runLoopDuration(env, duration, x, ctx);
}

/*
 * Method:    engine_runLoopIterations
 * Signature: (I)V
 */
JNIEXPORT void JNICALL engine_runLoopIterations
  (JNIEnv *env, jobject this_, jint iterations, jobject context, jint options) 
{
    OSS_XSDC_CONTEXT *ctx = (OSS_XSDC_CONTEXT *)objectToUserData(env, context);
    TRANSACTION x = define_transaction(env, ctx);

    runLoopIterations(env, iterations, x, ctx);
}

int parse(JNIEnv *env, void *context)
{
    OSS_XSDC_CONTEXT *ctx = (OSS_XSDC_CONTEXT *)context;
    OssxBuf encoding = {ctx->enc_length, ctx->encoded};
    int rc;
    int globElemNum = ctx->globElemNum;
    void *decoded = NULL;
    struct ossxEnv *e = &ctx->env; 

    if (ctx->preallocated) {
	ossxSetDecodingLength(e, ctx->pre_length);
	decoded = ctx->preallocated;
    }

    rc = ossxDecode(e, &globElemNum, &encoding, &decoded);
    if (rc) {
	char *msg = ossxGetErrMsg(e);
	if (msg == NULL) msg = "N/A";
	ThrowError(
	    env,
	    "java/lang/RuntimeException", 
	    "Parsing has failed. Error: %d (%s)", rc, msg);
    } else if (ctx->preallocated == NULL)
	ossxFreeGlobElem(e, globElemNum, decoded);

    return rc;
}

int serialize(JNIEnv *env, void *context)
{
    OSS_XSDC_CONTEXT *ctx = (OSS_XSDC_CONTEXT *)context;
    OssxBuf encoding = {0, NULL};
    int rc;
    int globElemNum = ctx->globElemNum;
    void *decoded = ctx->decoded;
    struct ossxEnv *e = &ctx->env;
    
    if (ctx->preallocated) {
	encoding.length = ctx->pre_length;
	encoding.value = ctx->preallocated;
    }

    rc = ossxEncode(e, globElemNum, decoded, &encoding);
    if (rc) {
	char *msg = ossxGetErrMsg(e);
	if (msg == NULL) msg = "N/A";
	ThrowError(
	    env,
	    "java/lang/RuntimeException", 
	    "Serialization has failed. Error: %d (%s)", rc, msg);
    } else if (ctx->preallocated == NULL)
	ossxFreeBuf(e, encoding.value);

    return rc;
}

int nop(JNIEnv *env, void *context)
{
    return 0;
}

TRANSACTION define_transaction(JNIEnv *env, OSS_XSDC_CONTEXT *ctx)
{
    if (ctx->action == PARSING)
	return parse;
    else if (ctx->action == SERIALIZING)
	return serialize;
    else
	return nop;
}

void cleanup(OSS_XSDC_CONTEXT *ctx)
{
    struct ossxEnv *e = &ctx->env; 
    // Free encoded/decoded data
    if (ctx->decoded != NULL)
	ossxFreeGlobElem(e, ctx->globElemNum, ctx->decoded);
    if (ctx->encoded != NULL) {
	ossxFreeBuf(e, ctx->encoded);
        if (ctx->preallocated == ctx->encoded)
            ctx->preallocated = NULL;
    }
    // Free preallocated buffer
    if (ctx->preallocated != NULL)
	free(ctx->preallocated);
    // Terminate runtime
    if (ctx->initialized)
	ossxterm(e);
    if (ctx->h_ctl_tbl != NULL)
	unloadPrecompiledSchema(ctx);
    memset(ctx, 0, sizeof(OSS_XSDC_CONTEXT));
}

/////////////////////////////////////////////////////////////////////////////
// WARNING! Platform dependant code. Change as necessary to port to platform
// other than SunOS
/////////////////////////////////////////////////////////////////////////////

static void *loadPrecompiledSchema(JNIEnv *env, jbyteArray path, OSS_XSDC_CONTEXT *ctx)
{
    void *h_ctl_tbl;
    GET_HEADER get_header;
    jboolean is_copy;
    jbyte *data;

    // Load shared library containing precompiled schema
    // Warning: do not use RTLD_GLOBAL as it might conflict with subsequent
    // OSS-based tests
    data = (*env)->GetByteArrayElements(env, path, &is_copy);
    h_ctl_tbl = (void *)dlopen((char *)data, RTLD_LAZY /* | RTLD_GLOBAL */);
    (*env)->ReleaseByteArrayElements(env, path, data, JNI_ABORT);
    if (h_ctl_tbl == NULL) {
	ThrowError(
	    env,
	    "java/lang/RuntimeException", 
	    "Error when loading precompiled schema: %s", dlerror());
	return NULL;
    }
    ctx->h_ctl_tbl = h_ctl_tbl;
    get_header = (GET_HEADER)dlsym(h_ctl_tbl, GETHEADER);
    if (get_header == NULL) {
	ThrowError(
	    env,
	    "java/lang/RuntimeException", 
	    "Shared library does not contain precompiled schema");
	return NULL;
    }
    h_ctl_tbl = (*get_header)();
    if (h_ctl_tbl == NULL) {
	ThrowError(
	    env,
	    "java/lang/RuntimeException", 
	    "Shared library contains NULL precompiled schema");
    }
    return h_ctl_tbl;
}

static void unloadPrecompiledSchema(OSS_XSDC_CONTEXT *ctx)
{
    if (ctx->h_ctl_tbl != NULL)
	dlclose(ctx->h_ctl_tbl);
}


static const char* getParam(JNIEnv *env, jobject this, const char *name)
{
    jclass cls;
    jmethodID mid;
    jstring value;

    cls = (*env)->GetObjectClass(env, this);
    mid = (*env)->GetMethodID(env, cls, "getParam", "(Ljava/lang/String;)Ljava/lang/String;");
    value = (jstring) (*env)->CallObjectMethod(env, this, mid, (*env)->NewStringUTF(env, name));
    return (*env)->GetStringUTFChars(env, value, NULL);
}
