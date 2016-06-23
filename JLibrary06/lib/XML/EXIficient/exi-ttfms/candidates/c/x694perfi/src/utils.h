/*****************************************************************************/
/* Copyright (C) 2006 OSS Nokalva, Inc.  All rights reserved.                */
/*****************************************************************************/
/*****************************************************************************
 * $Id: utils.h,v 1.2 2007/02/19 22:28:08 pthorpe Exp $
 *****************************************************************************/

#ifndef _Included_utils
#define _Included_utils

#include <jni.h>
#include <stdarg.h>
#include <sys/time.h>

// Params
#define RESULT "japex.resultValue"

#define SERIALIZING 1
#define PARSING     2
#define SIZING      3

// Helper macro to sense Java exceptions
#ifdef __cplusplus
#define HANDLE_EXCEPTION \
    if (env->ExceptionCheck()) { \
	cleanup(ctx); \
	return; \
    }
#else
#define HANDLE_EXCEPTION \
    if ((*env)->ExceptionCheck(env)) { \
	cleanup(ctx); \
	return; \
    }
#endif

typedef int (*TRANSACTION)(JNIEnv *env, void *context);

#ifdef __cplusplus
extern "C" {
#endif

void ThrowError(JNIEnv *env, const char *className, const char *mesageFormat, ...);
jobject userDataToObject(JNIEnv *env, void *userData, int size);
void* objectToUserData(JNIEnv *env, jobject object);
void setLongParam(JNIEnv *env, jobject this_, const char *name, long value);
long getLongParam(JNIEnv *env, jobject this_, const char *name);
void setDoubleParam(JNIEnv *env, jobject this_, const char *name, double value);
double getDoubleParam(JNIEnv *env, jobject this_, const char *name);
jboolean getBooleanParam(JNIEnv *env, jobject this_, const char *name);
int getActionID(JNIEnv *env, jobject this_);
jint runLoopDuration(JNIEnv *env, jdouble duration, TRANSACTION x, void *ctx);
void runLoopIterations(JNIEnv *env, jint iterations, TRANSACTION x, void *ctx);
jdouble timeMillis();
void postEncoding(JNIEnv *env, jobject this_, jbyte *data, jint length);

#ifdef __cplusplus
}
#endif
#endif
