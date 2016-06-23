/*****************************************************************************/
/* Copyright (C) 2002-2006 OSS Nokalva, Inc.  All rights reserved.           */
/*****************************************************************************/

/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.
 * AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.
 * THIS FILE MAY NOT BE DISTRIBUTED. */

/*****************************************************************************/
/* FILE: @(#)ossxcag.h	14.3  05/04/30                       */
/*****************************************************************************/

#ifndef OSSXCAG_H
#define OSSXCAG_H


#include "ossxixapi.h"


/*****************************************************************************/
/*  OSS CAGL API return codes                                                */
/*****************************************************************************/

    /*************************************************************************/
    /*  ossxCreateXsdControlTable() error codes                                  */
    /*************************************************************************/
#define XSD_COMPILER_DLL_NOT_LINKED 104 /* XSD compiler DLL was not linked */
#define XSD_COMPILING_FAILED        105 /* compiling of the input XSD
					  * notation failed */
#define OSSX_TOO_MANY_CMD_LINE_OPTIONS    106 /* number of input command line options
					  * exceeds OSS internal limit */
    /*************************************************************************/
    /*  One CAGL DLL-specific error codes                                    */
    /*************************************************************************/

#define OSSX_FAILED_TO_UNLOCK_DLL_8       116
#define OSSX_FAILED_TO_UNLOCK_DLL_7       117
#define OSSX_FAILED_TO_UNLOCK_DLL_6       118
#define OSSX_FAILED_TO_UNLOCK_DLL_5       119
#define OSSX_FAILED_TO_UNLOCK_DLL_4       120
#define OSSX_FAILED_TO_UNLOCK_DLL_3       121
#define OSSX_FAILED_TO_UNLOCK_DLL_2       122
#define OSSX_FAILED_TO_UNLOCK_DLL_1       123
#define OSSX_FAILED_TO_ACCESS_DLL_DATA    124
#define OSSX_INVALID_DLL_CALLER_2         125
#define OSSX_INVALID_DLL_CALLER_1         126

#define OSSX_ERROR_READING_SIGNATURE_FILE 127
#define OSSX_MISSING_FILE_NAME_IN_SIGNATURE_FILE_OPTION 128
#define OSSX_CAGL_DLL_IS_NOT_UNLOCKED 129

/*****************************************************************************/
/*  CAGL type definitions                                                    */
/*****************************************************************************/

#ifdef _WIN32
typedef struct ossxcagTbl {
    int (DLL_ENTRY_FPTR *_System ossxCreateXsdControlTablep)(struct ossxXsdCompilerEnv *,
						char *, char *, void **);
    void (DLL_ENTRY_FPTR *_System ossxDeleteXsdControlTablep)(
						struct ossxXsdCompilerEnv *, void *);
} OssxCagTbl;

/* The structure "ossxCagWinParm" is used to store DLL-related information. */
typedef struct ossxCagWinParm {
    OssxCagTbl  *ossxcagTbl;      /* Runtime compiler DLL function table */
    HINSTANCE   hOssxcagDLL;     /* Handle of runtime compiler DLL */
} OssxCagWinParm;

PUBLIC void DLL_ENTRY ossxLinkCAGL(struct ossxXsdCompilerEnv *aworld);
#endif /* _WIN32 */

typedef struct ossxXsdCompilerEnv {
    void	*ctlTbl;
    void	*(*mallocp)(size_t p);
    void	*(*reallocp)(void *p, size_t s);
    void	(*freep)(void *p);
    unsigned long parmFlags;
    unsigned int  isExternal:1;
    long	bufsAllocated;
    long	bufsFreed;
    void	*llink;		/* previous node on memory queue */
    void	*rlink;		/* next node on memory queue	 */
	/* used for storing DLL- & library NLMs-related parameters */
#ifdef _WIN32
    void	*bdata;
    OssxCagWinParm	wp;
#endif /* _WIN32 */
} OssxXsdCompilerEnv;

/*****************************************************************************/
/*  OSS CAGL API functions                                                   */
/*****************************************************************************/

#if defined(_WIN32)
/* Support for one CAGL DLL protection */
PUBLIC int DLL_ENTRY_FDEF ossxUnlockDLL(struct ossxXsdCompilerEnv *aworld,
					void *blobData);
#endif /* _WIN32 */

/* Support for XSD compiling at runtime */
PUBLIC struct ossxXsdCompilerEnv *DLL_ENTRY ossxGetXSDCompilerHandle(
				void *(*userMalloc)(size_t size),
				void  (*userFree)(void *buf),
				void *(*userRealloc)(void *buf, size_t size));
PUBLIC void DLL_ENTRY ossxDeleteXSDCompilerHandle(struct ossxXsdCompilerEnv *aworld);
PUBLIC int DLL_ENTRY  ossxCreateXsdControlTable(struct ossxXsdCompilerEnv *aworld,
				char *cmd_line, char *err_file,
				void **ctbl_hdl);
PUBLIC void DLL_ENTRY ossxDeleteXsdControlTable(struct ossxXsdCompilerEnv *aworld,
                                void *ctbl_hdl);
#endif /* OSSXCAG_H */
