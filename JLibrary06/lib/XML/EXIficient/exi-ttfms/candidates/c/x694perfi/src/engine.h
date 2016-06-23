/*****************************************************************************/
/* Copyright (C) 2006 OSS Nokalva, Inc.  All rights reserved.                */
/*****************************************************************************/
/*****************************************************************************
 * $Id: engine.h,v 1.2 2007/02/19 22:28:08 pthorpe Exp $
 *****************************************************************************/

#include <jni.h>

#ifndef _Included_engine
#define _Included_engine

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jobject JNICALL engine_initializeDriver
  (JNIEnv *, jobject, jobject, jint);

JNIEXPORT void JNICALL engine_prepare
  (JNIEnv *, jobject, jobject, jobject, jint);

JNIEXPORT void JNICALL engine_warmup
  (JNIEnv *, jobject, jobject, jobject, jint);

JNIEXPORT void JNICALL engine_run
  (JNIEnv *, jobject, jobject, jobject, jint);

JNIEXPORT void JNICALL engine_finish
  (JNIEnv *, jobject, jobject, jobject, jint);

JNIEXPORT void JNICALL engine_terminateDriver
  (JNIEnv *, jobject, jobject, jint);

JNIEXPORT jint JNICALL engine_runLoopDuration
  (JNIEnv *, jobject, jdouble, jobject, jint);

JNIEXPORT void JNICALL engine_runLoopIterations
  (JNIEnv *, jobject, jint, jobject, jint);

#ifdef __cplusplus
}
#endif
#endif
