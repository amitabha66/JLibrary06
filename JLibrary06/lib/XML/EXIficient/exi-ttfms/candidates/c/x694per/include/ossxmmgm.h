/*****************************************************************************/
/* Copyright (C) 1991-2006 OSS Nokalva, Inc.  All rights reserved.           */
/*****************************************************************************/

/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.
 * AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.
 * THIS FILE MAY NOT BE DISTRIBUTED. */

/*************************************************************************/
/* FILE: @(#)ossxmmgm.h	14.3  05/06/29       */
/*************************************************************************/

#ifndef OSSXMMGM_H
#define OSSXMMGM_H

#include "ossxsd.h"

enum ossxErrcode {
    ossxMoreInput,          /* input is exhausted and more was requested;
			   context indicates number of bytes requested */
			/* decode returns OSSX_MORE_INPUT (not a negative
			   error code) */
    ossxMoreOutput,         /* requests for output exceed restraint
			   or space provided by user buffer;
			   context indicates bytes allocated so far
			   plus amount requested */
			/* decode returns OSSX_MORE_BUF */
    ossxZeroBytesRequested, /* memory request for zero bytes.
			   This should not happen; report error to OSS;
			   context ignored */
			/* decode returns OSSX_FATAL_ERROR */
    ossxSizeTooBig,         /* request to allocate more than 'ossxblock' bytes;
			   context indicates number of bytes requested;
			   This should not happen; report error to OSS */
			/* decode returns OSSX_FATAL_ERROR */
    ossxOutOfMemory,        /* memory allocation failure; context indicates
			   number of bytes requested */
			/* decode returns OSSX_OUT_MEMORY */
    ossxInvalidObject,      /* unrecognized memory object passed in argument
			   to function; context 0 means object not recognized,
			   1 means control information within object is flawed */
			/* decode returns OSSX_FATAL_ERROR */
    ossxMemmgrUndefinedErr, /* error OSS has not anticipated; e.g., I/O Error;
			   ossxHandlerr prints context.
			   (I cannot print context as a hex value
			   with the current error message code <---) */
			/* decode returns OSSX_FATAL_ERROR */
    ossxDecoderInputEOF,	/* decoder input file EOF detected while
			   initializing decoder input stream --> no data
			   to proceed.
			   decode returns OSSX_EOF_INPUT_FILE */
    ossxInputFileOpen,	/* decoder/encoder cann't open input file */
    ossxCompressInit,	/* an error was occured while accessing compressor stuff */
    ossxCompressError,	/* an error was occured while compressing output or unpacking *
			 * input data, context is a compressor own error code */
    ossxBadEncoding		/* decoder input is bad or corrupted */
};

extern void     ossxHandlerr(struct ossxEnv *, enum ossxErrcode err, void * context);
extern int      DLL_ENTRY ossxDglobElemWalk(struct ossxEnv *, int, void *, void *,
			void (DLL_ENTRY_FPTR *_System freer)(struct ossxEnv *, void *));
void  DLL_ENTRY ossxFreer(struct ossxEnv *, void *);


unsigned char  *DLL_ENTRY ossxDopenIn(struct ossxEnv *, void **p_hdl, unsigned long *inlen);
unsigned long   DLL_ENTRY ossxDclosIn(struct ossxEnv *, void **p_hdl, size_t bytes_decoded);
unsigned char  *DLL_ENTRY ossxDswapIn(struct ossxEnv *, void **p_hdl, size_t *inlen);
void            DLL_ENTRY ossxDopenOut(struct ossxEnv *, void *hdl, unsigned long length,
                        unsigned long limit);
unsigned long   DLL_ENTRY ossxDclosOut(struct ossxEnv *, void **p_hdl);
void           *DLL_ENTRY ossxDallcOut(struct ossxEnv *, size_t size, char root);
void 		DLL_ENTRY setOutBufPos(struct ossxEnv *world, size_t size);
void           *DLL_ENTRY getOutBufPos(struct ossxEnv *world, size_t *size);
void            DLL_ENTRY ossxOpenWork(struct ossxEnv *);
void            DLL_ENTRY ossxClosWork(struct ossxEnv *);
void           *DLL_ENTRY ossxAllcWork(struct ossxEnv *, size_t size);
unsigned char  *DLL_ENTRY ossxLockMem(struct ossxEnv *, void *hdl);
void            DLL_ENTRY ossxUnlokMem(struct ossxEnv *, void *hdl, char free);
void            DLL_ENTRY ossxPushHndl(struct ossxEnv *, void *);
unsigned char  *DLL_ENTRY ossxPopHndl(struct ossxEnv *, void **handl, size_t length);
void            DLL_ENTRY ossxDrcovObj(struct ossxEnv *, int globElem_num, void * hdl, void *ctl_tbl);

unsigned char  *DLL_ENTRY ossxEopenIn(struct ossxEnv *, void *lock, size_t length);	/* Clear encoder input-memory resources */
unsigned char  *DLL_ENTRY ossxEswapIn(struct ossxEnv *, void *unlock, void *lock, size_t length);	/* Swap new data into input memory */
void            DLL_ENTRY ossxEclosIn(struct ossxEnv *, void * unlock); /* Free encoder input-memory resources */

unsigned char  *DLL_ENTRY ossxEopenOut(struct ossxEnv *, void **object, size_t *outlen, char queue);   /* Clear encoder output-memory resources */
unsigned char  *DLL_ENTRY ossxEswapOut(struct ossxEnv *, void **object, size_t used, size_t *outlen);  /* Dispose of output data and get memory */
unsigned long   DLL_ENTRY ossxEclosOut(struct ossxEnv *, void **object, size_t used, char low);        /* Free encoder output-memory resources */
void            DLL_ENTRY ossxErcovObj(struct ossxEnv *);	/* Free all encoder memory resources */
unsigned char   DLL_ENTRY ossxEgetByte(struct ossxEnv *world, void *inn, unsigned long offset);
extern int      DLL_ENTRY ossxMinit(struct ossxEnv *world);
extern void     DLL_ENTRY ossxMterm(struct ossxEnv *world);
void *DLL_ENTRY _ossxMarkObj(struct ossxEnv *world, OssxObjType objType, void *object);
void *DLL_ENTRY _ossxUnmarkObj(struct ossxEnv *world, void *objHndl);
void *DLL_ENTRY _ossxGetObj(struct ossxEnv *world, void *objHndl);
OssxObjType DLL_ENTRY _ossxTestObj(struct ossxEnv *world, void *objHndl);
void  DLL_ENTRY _ossxFreeObjectStack(struct ossxEnv *world);
void  DLL_ENTRY _ossxSetTimeout(struct ossxEnv *world, long timeout);
int   DLL_ENTRY _ossxGetBuffer(struct ossxEnv *world, OssxBufExtended *buf);
int   DLL_ENTRY _ossxSetBuffer(struct ossxEnv *world, OssxBufExtended *buf);
int   DLL_ENTRY _ossxOpenDecoderInputFile(struct ossxEnv *world, char *fname);
int   DLL_ENTRY _ossxCloseDecoderInputFile(struct ossxEnv *world);
int   DLL_ENTRY _ossxOpenEncoderOutputFile(struct ossxEnv *world, char *fname);
int   DLL_ENTRY _ossxCloseEncoderOutputFile(struct ossxEnv *world);
void  DLL_ENTRY _ossxSetUserMallocFreeRealloc(struct ossxEnv *world,
		void *(*ossxUserMalloc)(struct ossxEnv *world, size_t size),
		void  (*ossxUserFree)(struct ossxEnv *world, void *buf),
		void *(*ossxUserRealloc)(struct ossxEnv *world, void *buf, size_t size));
void  DLL_ENTRY _ossxGetUserMallocFreeRealloc(struct ossxEnv *world,
		void *(**ossxUserMalloc)(struct ossxEnv *world, size_t size),
		void  (**ossxUserFree)(struct ossxEnv *world, void *buf),
		void *(**ossxUserRealloc)(struct ossxEnv *world, void *buf, size_t size));

#endif /* !OSSXMMGM_H */
