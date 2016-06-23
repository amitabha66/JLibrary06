/*****************************************************************************/
/* Copyright (C) 2006 OSS Nokalva, Inc.  All rights reserved.                */
/*****************************************************************************/
/*****************************************************************************
 * $Id: xsdcfi_engine.c,v 1.6 2007/02/19 22:28:08 pthorpe Exp $
 *****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <libgen.h>
#include <ossxfidef.h>
#include "engine.h"
#include "utils.h"

typedef struct _tag_OssXsdContext {
    // OSS runtime context
    OssxEnv env;
    OssxEnv env2;
    // OSS memory handles context
    OssxMemoryHandle *mem_hdl;
    OssxMemoryHandle *mem_hdl2;
    // Indicates if ossxterm() should be called on cleanup
    int schema_initialized;
    // Indicates if ossxTermFastInfoset() should be called on cleanup
    int fi_initialized;
    int fi2_initialized;
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
    // Handle of shared library
    void *dll;
    // Handle of control table
    void *ctl_tbl;
} OSS_XSDC_CONTEXT;

// Options
#define PER_ALIGNED 1
#define PREALLOCATE 2
#define VALIDATE    4
#define COMPRESS    8
#define GZIP	    16

#define CHUNK_LENGTH (1024 * 1024)

#define GETHEADER "ossxGetHeader"

typedef void * (*GET_HEADER)(void);
void DLL_ENTRY ossxLinkLeanMemoryManager(OssxEnv *);

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
static void loadPrecompiledSchema(JNIEnv *env, jbyteArray path, OSS_XSDC_CONTEXT *ctx);
// Load shared library containing FI framework
static void loadFIlib(JNIEnv *env, jbyteArray path, OSS_XSDC_CONTEXT *ctx);
// Unload shared library
static void unloadDLL(OSS_XSDC_CONTEXT *ctx);
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
		"The JVM is incompatible with the driver: it does not support the %s API", 
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

// FIXME: supply our own version of ossxDupEnv() instead of the problematic one in 2.2 release
int ossxDupEnv_exi(struct ossxEnv *org_world, struct ossxEnv *dup_world, const OssxFITable *in_ctl_tbl)
{
    int rc;

    if ((rc = ossxInitFastInfoset(dup_world, in_ctl_tbl)))
	return rc;
    ossxLinkLeanMemoryManager(dup_world);   // FIXME
    ossxFISetFlags(dup_world, ossxFIGetFlags(org_world));
    return rc;
}

static void initialize_fi(JNIEnv *env, jobject this_, jobject testCase, OSS_XSDC_CONTEXT *ctx, jint options)
{
    int rc;
    OssxEnv *fe = &ctx->env;
    jclass cls;
    jmethodID mid;
    jbyteArray xml = NULL;
    jsize xml_length;
    jbyte *data;
    jboolean is_copy;
    jbyteArray path = NULL;
    OssxBuf encoding, fiencoding;

    cls = (*env)->GetObjectClass(env, this_);
    mid = (*env)->GetMethodID(
	env, 
	cls, 
	"getEncodedPrecompiledXMLSchemaPath", 
	"(Lcom/sun/japex/TestCase;)[B");
    if (mid != NULL)
	path = (*env)->CallObjectMethod(env, this_, mid, testCase);
    HANDLE_EXCEPTION;

    loadFIlib(env, path, ctx);
    HANDLE_EXCEPTION;

    // Initialize FI environment
    rc = ossxInitFastInfoset(fe, ctx->ctl_tbl);
    if (rc) {
	ThrowError(
	    env,
	    "java/lang/RuntimeException", 
	    "Runtime initialization has failed. Error code = %d", 
	    rc);
	cleanup(ctx);
	return;
    }
    ossxLinkLeanMemoryManager(fe);   // FIXME
    ctx->fi_initialized = 1;

    // Configure the coder
    ossxFISetFlags(fe, OSSX_FI_NO_DECLARATION | OSSX_FI_ENCODER_STATE_OFF |
	OSSX_FI_ADD_STRINGS_TO_VOCABULARY | OSSX_FI_RELAXED |
	(options & GZIP ? OSSX_FI_COMPRESS_OUTPUT : 0));

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

    // Produce FI encoding first
    encoding.value = (unsigned char *)data;
    encoding.length = xml_length;
    fiencoding.value = NULL;
    fiencoding.length = 0;
    rc = ossxXML2FastInfoset(fe, &encoding, &fiencoding);
    (*env)->ReleaseByteArrayElements(env, xml, data, JNI_ABORT);
    if (rc) {
	char *msg = ossxGetErrMsg(fe);
	if (msg == NULL) msg = "N/A";
	ThrowError(
	    env,
	    "java/lang/RuntimeException", 
	    "Conversion of input XML into FI encoding has failed. Error: %d (%s)", rc, msg);
	cleanup(ctx);
	return;
    }
    if (options & GZIP)
	ossxFISetFlags(fe, ossxFIGetFlags(fe) | OSSX_FI_DECOMPRESS_INPUT);
    ctx->enc_length = fiencoding.length;
    ctx->encoded = fiencoding.value;
    if (ctx->action == SERIALIZING) {

	fe->userVar = fe;                // FIXME

	// Decode into internal format as well
	rc = ossxCreateEventsList(fe, &fiencoding, (OssxEvent **)&ctx->decoded);
	if (rc) {
	    char *msg = ossxGetErrMsg(fe);
	    if (msg == NULL) msg = "N/A";
	    ThrowError(
		env,
		"java/lang/RuntimeException", 
		"Parsing of input FI has failed. Error: %d (%s)", rc, msg);
	    cleanup(ctx);
	    return;
	}

	// Preallocate encoder's buffer
	if (options & PREALLOCATE) {
	    int size = 2 * fiencoding.length;
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

    }
    if (ctx->action == PARSING) {
	int rc;

	// Performance tuning: separate memory pools to decrease fragmenting
	if ((rc = ossxDupEnv_exi(fe, &ctx->env2, ctx->ctl_tbl))) {
	    ThrowError(
		env,
		"java/lang/RuntimeException", 
		"Runtime initialization has failed (ossxDupEnv): Error code = %d", rc);
	    cleanup(ctx);
	    return;
	}
	ctx->fi2_initialized = 1;
	if (!(ctx->mem_hdl2 = ossxCreateMemoryHandle(&ctx->env2, CHUNK_LENGTH))) {
	    /* could not allocate a handle */
	    ThrowError(
		env,
		"java/lang/RuntimeException", 
		"Runtime initialization has failed (MH1)");
	    cleanup(ctx);
	    return;
	}
	fe->userVar = &ctx->env2;        // FIXME
    }

    // Further work is conducted using memory handles
    if (!(ctx->mem_hdl = ossxCreateMemoryHandle(fe, CHUNK_LENGTH))) {
	/* could not allocate a handle */
	ThrowError(
	    env,
	    "java/lang/RuntimeException", 
	    "Runtime initialization has failed (MH2)");
	cleanup(ctx);
	return;
    }
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
    OssxEnv *xe = &ctx->env; 
    jclass cls;
    jmethodID mid;
    jbyteArray xml = NULL;
    jsize xml_length;
    jbyte *data;
    jboolean is_copy;
    int action;
    jbyteArray path = NULL;
    OssxBuf encoding;
    const char *cmode;

    memset(ctx, 0, sizeof(OSS_XSDC_CONTEXT));
    action = getActionID(env, this_);
    ctx->action = action;
    HANDLE_EXCEPTION;

    // Restrict to pure FI if requested
    cmode = getParam(env, this_, "org.w3c.exi.ttf.applicationClass");
    if (!strcmp(cmode, "neither") || !strcmp(cmode, "document")) {
	initialize_fi(env, this_, testCase, ctx, options);
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

    loadPrecompiledSchema(env, path, ctx);
    HANDLE_EXCEPTION;
    if (!ctx->dll) {
	printf("\nThe precompiled XML schema is not available. Switching to Fast Infoset.\n");
	fflush(stdout);
	initialize_fi(env, this_, testCase, ctx, options);
	return;
    }

    // Initialize XSD environment
    rc = ossxinit(xe, ctx->ctl_tbl);
    if (rc) {
	ThrowError(
	    env,
	    "java/lang/RuntimeException", 
	    "Runtime initialization has failed. Error code = %d", 
	    rc);
	cleanup(ctx);
	return;
    }
    ctx->schema_initialized = 1;

    // Configure the coder
    ossxSetEncodingMethod(xe, OSSX_XML);
    ossxSetFlags(xe, OSSX_NOCONSTRAIN | OSSX_NOTRAPPING);

    // Get XML document
    mid = (*env)->GetMethodID(env, cls, "getInputAsByteArray", 
	"()[B");
    if (mid != NULL)
	xml = (*env)->CallObjectMethod(env, this_, mid, testCase);
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
    rc = ossxDecode(xe, &ctx->globElemNum, &encoding, &ctx->decoded);
    (*env)->ReleaseByteArrayElements(env, xml, data, JNI_ABORT);
    if (rc) {
	char *msg = ossxGetErrMsg(xe);
	if (msg == NULL) msg = "N/A";
	printf("Warning: Parsing of input XML has failed. Error: %d (%s). "
	       "Switching to Fast Infoset engine for this value", rc, msg);
	fflush(stdout);
	cleanup(ctx);
	ctx->action = action;
	initialize_fi(env, this_, testCase, ctx, options);
	return;
    }
    // Select appropriate binary encoding style
    if ((options & COMPRESS)) {
	if ((options & PER_ALIGNED))
	    ossxSetEncodingMethod(xe, OSSX_PER_ALIGNED);
	else
	    ossxSetEncodingMethod(xe, OSSX_PER_UNALIGNED);
    }
    if (options & GZIP)
	ossxSetFlags(xe, ossxGetFlags(xe) | OSSX_USE_COMPRESSION);
    // Reencode to binary if parser is being benchmarked
    if (action == PARSING || action == SIZING) {
	// Preallocate decoder's buffer if requested
	if (action == PARSING && (options & PREALLOCATE)) {
	    int size = ossxGetDecodingLength(xe);
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
	rc = ossxEncode(xe, ctx->globElemNum, ctx->decoded, &encoding);
	ossxFreeGlobElem(xe, ctx->globElemNum, ctx->decoded);
	ctx->decoded = NULL;
	if (rc) {

	    // Well, shouldn't generally occur
	    char *msg = ossxGetErrMsg(xe);
	    if (msg == NULL) msg = "N/A";
	    printf("Warning: Reencoding into PER has failed. Error: %d (%s). "
		   "Switching to Fast Infoset engine for this value", rc, msg);
	    fflush(stdout);
	    cleanup(ctx);
	    ctx->action = action;
	    initialize_fi(env, this_, testCase, ctx, options);
	    return;
	}
	ctx->enc_length = encoding.length;
	ctx->encoded = encoding.value;
	// Enable validation for parser if necessary
	if (action == PARSING && (options & VALIDATE))
	    ossxSetDecodingFlags(xe, OSSX_NOTRAPPING);
    } else if (action == SERIALIZING) {
	encoding.length = 0;
	encoding.value = NULL;
	rc = ossxEncode(xe, ctx->globElemNum, ctx->decoded, &encoding);
	if (rc) {
	    char *msg = ossxGetErrMsg(xe);
	    if (msg == NULL) msg = "N/A";
	    printf("Warning: Reencoding into PER has failed. Error: %d (%s). "
		   "Switching to Fast Infoset engine for this value", rc, msg);
	    fflush(stdout);
	    cleanup(ctx);
	    ctx->action = action;
	    initialize_fi(env, this_, testCase, ctx, options);
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

    if (ctx->fi_initialized) {
	OssxEvent *decoded = NULL;
	OssxEnv *fe = &ctx->env; 

	rc = ossxCreateEventsList(fe, &encoding, &decoded);
	if (rc) {
	    char *msg = ossxGetErrMsg(fe);
	    if (msg == NULL) msg = "N/A";
	    ThrowError(
		env,
		"java/lang/RuntimeException", 
		"Parsing has failed. Error: %d (%s)", rc, msg);
	}
	ossxCleanMemoryHandle(fe, ctx->mem_hdl);
	ossxCleanMemoryHandle(&ctx->env2, ctx->mem_hdl2);

    } else {
	int globElemNum = ctx->globElemNum;
	void *decoded = NULL;
	struct ossxEnv *xe = &ctx->env; 

	if (ctx->preallocated) {
	    ossxSetDecodingLength(xe, ctx->pre_length);
	    decoded = ctx->preallocated;
	}

	rc = ossxDecode(xe, &globElemNum, &encoding, &decoded);
	if (rc) {
	    char *msg = ossxGetErrMsg(xe);
	    if (msg == NULL) msg = "N/A";
	    ThrowError(
		env,
		"java/lang/RuntimeException", 
		"Parsing has failed. Error: %d (%s)", rc, msg);
	} else if (ctx->preallocated == NULL)
	    ossxFreeGlobElem(xe, globElemNum, decoded);
    }

    return rc;
}

int serialize(JNIEnv *env, void *context)
{
    OSS_XSDC_CONTEXT *ctx = (OSS_XSDC_CONTEXT *)context;
    OssxBuf encoding;
    int rc;

    if (ctx->preallocated) {
	encoding.length = ctx->pre_length;
	encoding.value = ctx->preallocated;
    } else {
	encoding.length = 0;
	encoding.value = NULL;
    }

    if (ctx->fi_initialized) {
	OssxEvent *decoded = ctx->decoded;
	OssxEnv *fe = &ctx->env;
	jmp_buf errorBuf;

	rc = setjmp(errorBuf);
	if (rc) {
	    char *msg = ossxGetErrMsg(fe);
	    if (msg == NULL) msg = "N/A";
	    ThrowError(
		env,
		"java/lang/RuntimeException", 
		"Serialization has failed #0. Error: %d (%s)", rc, msg);
	    return rc;
	}
	ossxFISetJmpBuf(fe, &errorBuf);
	rc = ossxEncodeEventsList(fe, decoded, &encoding);
	if (rc) {
	    char *msg = ossxGetErrMsg(fe);
	    if (msg == NULL) msg = "N/A";
	    ThrowError(
		env,
		"java/lang/RuntimeException", 
		"Serialization has failed #1. Error: %d (%s)", rc, msg);
	}
	ossxCleanMemoryHandle(fe, ctx->mem_hdl);
    } else {
	int globElemNum = ctx->globElemNum;
	void *decoded = ctx->decoded;
	OssxEnv *xe = &ctx->env;

	rc = ossxEncode(xe, globElemNum, decoded, &encoding);
	if (rc) {
	    char *msg = ossxGetErrMsg(xe);
	    if (msg == NULL) msg = "N/A";
	    ThrowError(
		env,
		"java/lang/RuntimeException", 
		"Serialization has failed. Error: %d (%s)", rc, msg);
	} else if (ctx->preallocated == NULL)
	    ossxFreeBuf(xe, encoding.value);
    }

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
    struct ossxEnv *e2 = &ctx->env2; 
    
    if (ctx->mem_hdl)
        ossxDeleteMemoryHandle(e, ctx->mem_hdl);
    if (ctx->mem_hdl2)
        ossxDeleteMemoryHandle(e2, ctx->mem_hdl2);

    // Terminate runtime
    if (ctx->schema_initialized) {
	if (ctx->decoded != NULL)
	    ossxFreeGlobElem(e, ctx->globElemNum, ctx->decoded);
	if (ctx->encoded != NULL) {
	    ossxFreeBuf(e, ctx->encoded);
	    if (ctx->preallocated == ctx->encoded)
		ctx->preallocated = NULL;
	}
	ossxterm(e);
    }
    if (ctx->fi_initialized) {
	if (ctx->decoded)
	    ossxFreeEvents(e, ctx->decoded);
	if (ctx->encoded)
	    ossxFreeBuf(e, ctx->encoded);
	if (ctx->fi2_initialized)
	    ossxTermFastInfoset(e2);
        ossxTermFastInfoset(e);
    }
    if (ctx->preallocated != NULL)
	free(ctx->preallocated);
    
    unloadDLL(ctx);
    memset(ctx, 0, sizeof(OSS_XSDC_CONTEXT));
}

/////////////////////////////////////////////////////////////////////////////
// WARNING! Platform dependant code. Change as necessary to port to platform
// other than SunOS
/////////////////////////////////////////////////////////////////////////////

static void loadPrecompiledSchema(JNIEnv *env, jbyteArray path, OSS_XSDC_CONTEXT *ctx)
{
    GET_HEADER get_header;
    jboolean is_copy;
    jbyte *data;

    // Load shared library containing precompiled schema (may be missing)
    // Warning: do not use RTLD_GLOBAL as it might conflict with subsequent
    // OSS-based tests
    data = (*env)->GetByteArrayElements(env, path, &is_copy);
    ctx->dll = dlopen((char *)data, RTLD_LAZY /* | RTLD_GLOBAL */);
    (*env)->ReleaseByteArrayElements(env, path, data, JNI_ABORT);
    if (ctx->dll) {
	get_header = (GET_HEADER)dlsym(ctx->dll, GETHEADER);
	if (get_header == NULL) {
	    ThrowError(
		env,
		"java/lang/RuntimeException",
		"Shared library does not contain precompiled schema");
	    return;
	}
	ctx->ctl_tbl = (*get_header)();
	if (!ctx->ctl_tbl) {
	    ThrowError(
		env,
		"java/lang/RuntimeException",
		"Shared library contains NULL precompiled schema");
	    return;
	}
    }
}

static void loadFIlib(JNIEnv *env, jbyteArray path, OSS_XSDC_CONTEXT *ctx)
{
    jboolean is_copy;
    jbyte *data;
    char finame[256];

    // Load shared library containing FI framework (must be present)
    data = (*env)->GetByteArrayElements(env, path, &is_copy);
    strcpy(finame, dirname((char *)data));
    (*env)->ReleaseByteArrayElements(env, path, data, JNI_ABORT);
    strcat(finame, "/");
    strcat(finame, "libFI.so");
    ctx->dll = dlopen(finame, RTLD_LAZY /* | RTLD_GLOBAL */);
    if (!ctx->dll) {
        ThrowError(
            env,
            "java/lang/RuntimeException",
            "Error when loading libFI.so: %s", dlerror());
        return;
    }

    ctx->ctl_tbl = dlsym(ctx->dll, "OSSX_FI_CTL_TBL");
    if (!ctx->ctl_tbl) {
	ThrowError(
	    env,
	    "java/lang/RuntimeException",
	    "Shared library contains NULL FI control table");
	return;
    }
}

static void unloadDLL(OSS_XSDC_CONTEXT *ctx)
{
    if (ctx->dll) {
	dlclose(ctx->dll);
	ctx->dll = NULL;
    }
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
