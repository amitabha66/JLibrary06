/*****************************************************************************/
/* Copyright (C) 2006 OSS Nokalva, Inc.  All rights reserved.                */
/*****************************************************************************/
/*****************************************************************************
 * $Id: jni_stub.c,v 1.2 2007/02/19 22:28:08 pthorpe Exp $
 *****************************************************************************/

#include "jni_stub.h"
#include "engine.h"

#ifndef OPTIONS
#define OPTIONS 0
#endif

/*
 * Method:    initializeDriver
 * Signature: (Ljava/lang/Object;)V
 *
 * Default value of userData is null when this function is called.
 */
JNIEXPORT jobject JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, initializeDriver)
  (JNIEnv *env, jobject this_, jobject context) 
{
    return engine_initializeDriver(env, this_, context, OPTIONS);
}

/*
 * Method:    prepare
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, prepare)
  (JNIEnv *env, jobject this_, jobject testCase, jobject context) 
{
    engine_prepare(env, this_, testCase, context, OPTIONS);
}

/*
 * Method:    warmup
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, warmup)
  (JNIEnv *env, jobject this_, jobject testCase, jobject context) 
{
    engine_warmup(env, this_, testCase, context, OPTIONS);
}

/*
 * Method:    run
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, run)
  (JNIEnv *env, jobject this_, jobject testCase, jobject context) 
{
    engine_run(env, this_, testCase, context, OPTIONS);
}

/*
 * Method:    finish
 * Signature: (Lcom/sun/japex/TestCase;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, finish)
  (JNIEnv *env, jobject this_, jobject testCase, jobject context) 
{
    engine_finish(env, this_, testCase, context, OPTIONS);
}   

/*
 * Method:    terminateDriver
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, terminateDriver)
  (JNIEnv *env, jobject this_, jobject context) 
{
    engine_terminateDriver(env, this_, context, OPTIONS);
}

/* --------------------- DO NOT EDIT BELOW THIS LINE ------------------- */

/*
 * Method:    runLoopDuration
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, runLoopDuration)
  (JNIEnv *env, jobject this_, jdouble duration, jobject context) 
{
    return engine_runLoopDuration(env, this_, duration, context, OPTIONS);
}

/*
 * Class:     japexjni_NativeDriver
 * Method:    runLoopIterations
 * Signature: (I)V
 */
JNIEXPORT void JNICALL JNINAME(PACKAGE_ID, DRIVER_ID, runLoopIterations)
  (JNIEnv *env, jobject this_, jint iterations, jobject context) 
{
    engine_runLoopIterations(env, this_, iterations, context, OPTIONS);
}
