/*****************************************************************************/
/* Copyright (C) 2006 OSS Nokalva, Inc.  All rights reserved.                */
/*****************************************************************************/
/*****************************************************************************
 * $Id: utils.c,v 1.2 2007/02/19 22:28:08 pthorpe Exp $
 *****************************************************************************/

#include <utils.h>

#define MAX_MSG_SIZE 1024

void ThrowError(JNIEnv *env, const char *className, const char *mesageFormat, ...)
{
    char msg[MAX_MSG_SIZE];
    jclass exceptionClass;

    va_list ap;
    va_start(ap, mesageFormat);
    vsnprintf(msg, MAX_MSG_SIZE-1, mesageFormat, ap);
    va_end(ap);
    exceptionClass = (*env)->FindClass(env, className);
    if (exceptionClass != NULL) {
	/*
	    Clear any pending exception before throwing the new one
	 */ 
	if ((*env)->ExceptionCheck(env))
	    (*env)->ExceptionClear(env);
	(*env)->ThrowNew(env, exceptionClass, msg);
    }
}

/* ---- THE FOLLOWING METHODS ARE TO ACCESS DRIVER PARAMS ----- */

void setLongParam(JNIEnv *env, jobject this_, const char *name, long value) 
{
    jclass cls;
    jmethodID mid;

    cls = (*env)->GetObjectClass(env, this_);
    mid = (*env)->GetMethodID(env, cls, "setLongParam", "(Ljava/lang/String;J)V");
    if (mid == NULL)
	return;
    (*env)->CallVoidMethod(env, this_, mid, (*env)->NewStringUTF(env, name), value);
}

long getLongParam(JNIEnv *env, jobject this_, const char *name) 
{
    jclass cls;
    jmethodID mid;

    cls = (*env)->GetObjectClass(env, this_);
    mid = (*env)->GetMethodID(env, cls, "getLongParam", "(Ljava/lang/String;)J");
    if (mid == NULL)
	return -1;
    else
	return (*env)->CallLongMethod(env, this_, mid, (*env)->NewStringUTF(env, name));
}

void setDoubleParam(JNIEnv *env, jobject this_, const char *name, double value) 
{
    jclass cls;
    jmethodID mid;

    cls = (*env)->GetObjectClass(env, this_);
    mid = (*env)->GetMethodID(env, cls, "setDoubleParam", "(Ljava/lang/String;D)V");
    if (mid == NULL)
	return;
    (*env)->CallVoidMethod(env, this_, mid, (*env)->NewStringUTF(env, name), value);
}

double getDoubleParam(JNIEnv *env, jobject this_, const char *name) 
{
    jclass cls;
    jmethodID mid;

    cls = (*env)->GetObjectClass(env, this_);
    mid = (*env)->GetMethodID(env, cls, "getDoubleParam", "(Ljava/lang/String;)D");
    if (mid == NULL)
	return 0.0;
    else
	return (*env)->CallDoubleMethod(env, this_, mid, (*env)->NewStringUTF(env, name));
}

jboolean getBooleanParam(JNIEnv *env, jobject this_, const char *name) 
{
    jclass cls;
    jmethodID mid;

    cls = (*env)->GetObjectClass(env, this_);
    mid = (*env)->GetMethodID(env, cls, "getBooleanParam", "(Ljava/lang/String;)Z");
    if (mid == NULL)
	return JNI_FALSE;
    else
	return (*env)->CallBooleanMethod(env, this_, mid, (*env)->NewStringUTF(env, name));
}

int getActionID(JNIEnv *env, jobject this_)
{
    jclass cls;
    jmethodID mid;
    
    cls = (*env)->GetObjectClass(env, this_);
    mid = (*env)->GetMethodID(env, cls, "getActionID", "()I");
    if (mid == NULL)
	return -1;
    else
	return (*env)->CallIntMethod(env, this_, mid);
}

/* ------- UTILITY METHODS TO CONVERT DIRECT BUFFERS INTO OBJECTS ------ */

jobject userDataToObject(JNIEnv *env, void *userData, int size) {
    return (*env)->NewDirectByteBuffer(env, userData, size);
}

void* objectToUserData(JNIEnv *env, jobject object) {
    return (*env)->GetDirectBufferAddress(env, object);
}

jdouble timeMillis()
{
    struct timeval t;
    gettimeofday(&t, 0);
    return (jdouble)(t.tv_sec * 1000 + t.tv_usec / 1000.0);
}

jint runLoopDuration(JNIEnv *env, jdouble duration, TRANSACTION x, void *ctx)
{
    jdouble startTime, currentTime, endTime;
    jint iterations;

    startTime = timeMillis();
    endTime = startTime + duration;

    currentTime = 0;
    iterations = 0;
    do {
	// Executor returns non-zero when an exception is pending
        if ((*x)(env, ctx))
	    break;
        iterations++;
        currentTime = timeMillis();
    } while (endTime >= currentTime);

    return iterations;
}

void runLoopIterations(JNIEnv *env, jint iterations, TRANSACTION x, void *ctx)
{
    int i;
    for (i = 0; i < iterations; i++) {
	// Executor returns non-zero when an exception is pending
        if ((*x)(env, ctx))
	    break;
    }
}

void postEncoding(JNIEnv *env, jobject this_, jbyte *data, jsize length)
{
    jclass cls;
    jmethodID mid;

    // Wrap the data into the byte[]
    jbyteArray data_ = (*env)->NewByteArray(env, length);
    (*env)->SetByteArrayRegion(env, data_, 0, length, data);

    cls = (*env)->GetObjectClass(env, this_);
    mid = (*env)->GetMethodID(
	env, 
	cls, 
	"transcodeTestCase",
        "([B)V"); 

    if (mid != NULL)
	(*env)->CallVoidMethod(env, this_, mid, data_);
}
