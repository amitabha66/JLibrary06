/*****************************************************************************/
/* Copyright (C) 2006 OSS Nokalva, Inc.  All rights reserved.                */
/*****************************************************************************/
/*****************************************************************************
 * $Id: jni_stub.h,v 1.2 2007/02/19 22:28:08 pthorpe Exp $
 *****************************************************************************/

#include <jni.h>

#ifndef _Included_jni_stub
#define _Included_jni_stub

#ifndef DRIVER_ID
#error You must define DRIVER_ID at the C-compiler command-line
#endif

#define JAVANAME2CNAME(package, clazz, method) \
    Java_##package##_##clazz##_##method
    
#define JNINAME(package, clazz, method) JAVANAME2CNAME(package, clazz, method)

#define PACKAGE_ID org_w3c_exi_ttf_candidate_x694per

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Method:    initializeDriver
 * Signature: (Ljava/lang/Object;)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, initializeDriver)
  (JNIEnv *, jobject, jobject);

/*
 * Method:    prepare
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, prepare)
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Method:    warmup
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, warmup)
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Method:    run
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, run)
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Method:    finish
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, finish)
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Method:    terminateDriver
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, terminateDriver)
  (JNIEnv *, jobject, jobject);

/*
 * Method:    runLoopDuration
 * Signature: (JLjava/lang/Object;)I
 */
JNIEXPORT jint JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, runLoopDuration)
  (JNIEnv *, jobject, jdouble, jobject);

/*
 * Method:    runLoopIterations
 * Signature: (ILjava/lang/Object;)V
 */
JNIEXPORT void JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, runLoopIterations)
  (JNIEnv *, jobject, jint, jobject);

#ifdef __cplusplus
}
#endif
#endif
