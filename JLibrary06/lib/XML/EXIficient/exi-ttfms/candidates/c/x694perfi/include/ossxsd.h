/*****************************************************************************/
/* Copyright (C) 1989-2006 OSS Nokalva, Inc.  All rights reserved.           */
/*****************************************************************************/

/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.
 * AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.
 * THIS FILE MAY NOT BE DISTRIBUTED. */

/*****************************************************************************/
/* FILE: @(#)ossxsd.hh	16.25  06/09/09                                      */
/*****************************************************************************/


/*****************************************************************************/
/*  NON-PUBLIC section: common includes etc.                                 */
/*****************************************************************************/


#if !defined(OSSXSD_H)


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <limits.h>
#include <setjmp.h>


/*****************************************************************************/
/*  PUBLIC section: platform-specific constants                              */
/*****************************************************************************/

#ifdef __BORLANDC__
#undef FLT_MAX
#undef DBL_MAX
#include <values.h>
#define FLT_MAX MAXFLOAT
#define DBL_MAX MAXDOUBLE
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif

#ifndef DBL_MAX
#ifdef  HUGE_VAL
#define DBL_MAX HUGE_VAL
#else
#ifdef  HUGE
#define DBL_MAX HUGE
#endif
#endif
#endif
#ifndef FLT_MAX
#define FLT_MAX DBL_MAX
#endif

#ifndef FLT_RADIX
#ifdef  u370
#define FLT_RADIX 16
#else
#define FLT_RADIX 2
#endif
#endif

#ifndef OSSX_NAN_PRESENT
#define OSSX_NAN_PRESENT
#define OSSX_NAN_DOUBLE "\x00\x00\x00\x00\x00\x00\xf8\xff"
#define OSSX_NAN_FLOAT "\x00\x00\xc0\xff"
#endif

#ifndef OSSX_MINUS_ZERO_PRESENT
#define OSSX_MINUS_ZERO_PRESENT
#define OSSX_MINUS_ZERO_DOUBLE "\x00\x00\x00\x00\x00\x00\x00\x80"
#define OSSX_MINUS_ZERO_FLOAT "\x00\x00\x00\x80"
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

/*****************************************************************************/
/*  PUBLIC section: type definitions used in the compiler-generated .h file  */
/*****************************************************************************/

#ifndef OSSX_INT16
#define OSSX_INT16 short
#endif

#define OSSX_UINT16 unsigned OSSX_INT16

#ifndef OSSX_INT32
#define OSSX_INT32 int
#endif

#define OSSX_UINT32 unsigned OSSX_INT32
typedef char ossxBoolean;

#if !defined(__cplusplus) && !defined(_union)
#define _union
#endif

#ifndef LONG_LONG
#define LONG_LONG long long
#define LLONG_FMT "%lld"
#endif

#ifndef ULONG_LONG
#define ULONG_LONG unsigned long long
#define ULLONG_FMT "%llu"
#endif

#ifndef LLONG_MIN
#define LLONG_MIN (-9223372036854775807LL-1LL)
#endif
#ifndef LLONG_MAX
#define LLONG_MAX (9223372036854775807LL)
#endif
#ifndef ULLONG_MAX
#define ULLONG_MAX (18446744073709551615ULL)
#endif

#ifndef OSSX_PTR_MAX
#define OSSX_PTR_MAX ((char*)UINT_MAX)
#endif

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#ifndef _NULLTYPE_
#define _NULLTYPE_
typedef char Nulltype;
#endif



/*****************************************************************************/
/*  PUBLIC section: type definitions supported by LEAN                       */
/*****************************************************************************/
#define OSSX_UINT16_MAX  65535
#define OSSX_UINT32_MAX  UINT_MAX
#define OSSX_INT32_MAX   2147483647
#define OSSX_INT32_MIN   (-2147483647 - 1)
#define OSSX_INT64       LONG_LONG
#define OSSX_UINT64      ULONG_LONG
#define OSSX_INT64_MAX   LLONG_MAX
#define OSSX_INT64_MIN   LLONG_MIN
#define OSSX_UINT64_MAX  ULLONG_MAX
#define OSSX_LENGTH_MAX  OSSX_UINT32_MAX
#define OSSX_FLOAT_MAX   DBL_MAX
#define OSSX_FLOAT_MIN   DBL_MIN
#define OSSX_FLOAT_PRINT_FORMAT OSSX_DBL_FMT

typedef OSSX_UINT32 OSSX_LENGTH;

typedef OSSX_INT32  OSSX_ENUM;

typedef OSSX_UINT32 OSSX_UENUM;

typedef double     ossxReal;
typedef struct ossxOctetString {
    OSSX_UINT32     length;
    unsigned char  *value;
} ossxOctetString;

typedef struct ossxCharString {
    OSSX_UINT32     length;
    char           *value;
} ossxCharString;
typedef struct ossxHugeInt {
    OSSX_UINT32     length;
    unsigned char  *value;
} ossxHugeInt;

typedef struct ossxObjectID {
    OSSX_UINT32     length;
    unsigned char  *value;
} ossxObjectID;
/*****************************************************************************/
/*  PUBLIC section: OSS encoding methods                                       */
/*****************************************************************************/

typedef enum  {
    OSSX_BER = 0,
    OSSX_PER_ALIGNED,
    OSSX_PER_UNALIGNED,
    OSSX_DER,
    OSSX_CER = 7,
    OSSX_XML
} ossxEncodingMethod;

/* Encoding mode for Self identified prefix */
typedef enum OssxPrefixingMode {
    OSSX_pmNone = 0,
    OSSX_pmID,
    OSSX_pmOID_or_QName,
    OSSX_pmROID_or_QName,
    OSSX_pmQName
} OssxPrefixingMode;


/*****************************************************************************/
/*  NON-PUBLIC section: data alignment section for platforms with multiple   */
/*  alignment options (OSS data structures should use the same setting as    */
/*  OSS runtime does)                                                        */
/*****************************************************************************/

#ifdef macintosh
#pragma options align=mac68k
#endif
#if defined(_MSC_VER) && (defined(WINCE) || defined(_WIN64))
#pragma pack(push, ossxPacking, 8)
#elif defined(_MSC_VER) && (defined(_WIN32) || defined(WIN32))
#pragma pack(push, ossxPacking, 4)
#elif defined(_MSC_VER) && (defined(_WINDOWS) || defined(_MSDOS))
#pragma pack(1)
#elif defined(__BORLANDC__) && defined(__MSDOS__)
#ifdef _BC31
#pragma option -a-
#else
#pragma option -a1
#endif /* _BC31 */
#elif defined(__BORLANDC__) && defined(__WIN32__)
#pragma option -a4
#elif defined(__IBMC__) && (defined(__WIN32__) || defined(__OS2__))
#pragma pack(4)
#elif defined(__WATCOMC__) && defined(__NT__)
#pragma pack(push, 4)
#elif defined(__WATCOMC__) && (defined(__WINDOWS__) || defined(__DOS__))
#pragma pack(push, 1)
#endif /* _MSC_VER && (WINCE || _WIN64) */

#if defined(macintosh) && defined(__CFM68K__)
#pragma import on
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/*  NON-PUBLIC section: DLL definitions (users may skip them)                */
/*****************************************************************************/

#ifdef DLL_LINKAGE
#undef DLL_LINKAGE
#endif /* DLL_LINKAGE */

#if defined(_WINDOWS) || defined(_WIN32) || defined(WIN32) || \
	defined(__WIN32__) || defined(__OS2__) || defined(NETWARE_DLL)

#if ((defined(_DLL) && !defined(ONE_DLL)) || defined(OS2_DLL) \
		|| defined(NETWARE_DLL)) && !defined(WIN32_DRIVER)
#define DLL_LINKAGE
#endif /* (_DLL || OS2_DLL || NETWARE_DLL) && !WIN32_DRIVER */


#include <stdarg.h>
#if !defined(__OS2__) && !defined(NETWARE_DLL) && !defined(WIN32_SIMPLE) \
		&& !defined(_NTSDK)
	/*
	 * Borland C++ does not allow windows.h #included
	 * within extern "C" {...}.
	 */
#if defined(__BORLANDC__)? !defined(__cplusplus): 1
#include <windows.h>
#endif /* __BORLANDC__? !__cplusplus: 1 */
#endif /* !__OS2__ && !NETWARE_DLL && !WIN32_SIMPLE */
#ifndef DLL_ENTRY
#if defined(_WIN32) || defined(WIN32) || defined(__WIN32__)
#ifdef __BORLANDC__
#define PUBLIC
#define DLL_ENTRY      __stdcall
#define DLL_ENTRY_FDEF __stdcall
#define DLL_ENTRY_FPTR __stdcall
#ifndef OSSX_EXPORT_DLL_DATA
#define OSSX_EXPORT_DLL_DATA  __declspec(dllexport)
#endif /* OSSX_EXPORT_DLL_DATA */
#ifdef __cplusplus
typedef void *         HINSTANCE;
typedef void *         HWND;
typedef int            BOOL;
typedef long           LONG;
#endif /* __cplusplus */
#elif defined(__IBMC__)
#define PUBLIC
#define DLL_ENTRY      WINAPI
#define DLL_ENTRY_FDEF WINAPI __export
#define DLL_ENTRY_FPTR WINAPI
#elif defined(__WATCOMC__)
#define PUBLIC
#define DLL_ENTRY      WINAPI __export
#define DLL_ENTRY_FDEF WINAPI __export
#define DLL_ENTRY_FPTR WINAPI __export
#ifndef OSSX_EXPORT_DLL_DATA
#define OSSX_EXPORT_DLL_DATA  __declspec(dllexport)
#endif /* OSSX_EXPORT_DLL_DATA */
#elif defined(_NTSDK)
typedef int            BOOL;
typedef void *         HWND;
typedef void *         HINSTANCE;
typedef long           LONG;
#define PUBLIC         __declspec(dllexport)
#define DLL_ENTRY
#define DLL_ENTRY_FDEF
#define DLL_ENTRY_FPTR
#ifndef OSSX_EXPORT_DLL_DATA
#define OSSX_EXPORT_DLL_DATA
#endif /* OSSX_EXPORT_DLL_DATA */
#else
#ifdef WIN32_SIMPLE
#include <ril.h>
typedef void *         HWND;
typedef void *         HINSTANCE;
typedef long           LONG;
#define WINAPI __stdcall
#undef PUBLIC
#endif /* WIN32_SIMPLE */
#if defined(__cplusplus) && defined(_DLL) && !defined(ONE_DLL)
#if !defined(OSS_BUILD)
#define PUBLIC         __declspec(dllimport)
#else
#define PUBLIC         __declspec(dllexport)
#endif
#else
#define PUBLIC
#endif /* __cplusplus && _DLL && !ONE_DLL */
#define DLL_ENTRY      WINAPI
#define DLL_ENTRY_FDEF WINAPI
#define DLL_ENTRY_FPTR WINAPI
#ifndef OSSX_EXPORT_DLL_DATA
#define OSSX_EXPORT_DLL_DATA __declspec(dllexport)
#endif /* OSSX_EXPORT_DLL_DATA */
#endif /* __BORLANDC__ */
#define _System
#elif defined(_WINDOWS)
#define PUBLIC
#undef OSSX_EXPORT_DLL_DATA
#define OSSX_EXPORT_DLL_DATA
#ifdef DPMI_DLL
#define DLL_ENTRY      FAR PASCAL __export
#define DLL_ENTRY_FDEF FAR PASCAL __export
#define DLL_ENTRY_FPTR FAR PASCAL __export
#else
#define DLL_ENTRY      far pascal _export
#define DLL_ENTRY_FDEF far pascal _export
#define DLL_ENTRY_FPTR far pascal _export
#endif /* DPMI_DLL */
#define _System
#elif defined(__OS2__)
#define PUBLIC
#define DLL_ENTRY      _System
#define DLL_ENTRY_FDEF _Export _System
#define DLL_ENTRY_FPTR
#include <os2def.h>
#define LONG long
#define DWORD unsigned long
#define HINSTANCE unsigned long
#ifndef OSSX_EXPORT_DLL_DATA
#define OSSX_EXPORT_DLL_DATA __declspec(dllexport)
#endif /* OSSX_EXPORT_DLL_DATA */
#elif defined(NETWARE_DLL)
#define PUBLIC
#define DLL_ENTRY
#define DLL_ENTRY_FDEF
#define DLL_ENTRY_FPTR
#ifndef OSSX_EXPORT_DLL_DATA
#define OSSX_EXPORT_DLL_DATA
#endif /* OSSX_EXPORT_DLL_DATA */
#define _Export
#undef _System
#define _System
#define LONG unsigned long
#define HWND int
#define DWORD LONG
#define BOOL char
#define HINSTANCE LONG
#endif /* _WIN32 || WIN32 || __WIN32__ */
#endif /* DLL_ENTRY */
#endif /* _WINDOWS ||_WIN32 || WIN32 || __WIN32__ || __OS2__ || NETWARE_DLL */

#if defined(_WINDOWS) || defined(_WIN32) || \
	defined(__OS2__) || defined(NETWARE_DLL)

typedef struct apiTbl ApiTbl;
/* The structure "ossxFunctionTables" is used to store DLL-related information. */
typedef struct ossxFunctionTables {
    BOOL	ossxEncoderDecoderType; /* SOED vs. TOED */
    void       *berTbl;         /* BER & DER DLL function table */
    void       *perTbl;         /* PER DLL function table */
    ApiTbl     *apiTbl;         /* Basic API DLL function table */
    void       *xmlTbl;         /* XML DLL function table */
    void       *fwsTbl;         /* FWS function table */
    void       *fiTbl;          /* FI  function table */
    void       *reserved[5];    /* Reserved for possible future use */
} OssxFunctionTables;
#elif !defined(DLL_ENTRY) /* _WINDOWS || _WIN32 || __OS2__ || NETWARE_DLL */

#include <stdarg.h>
#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#define DLL_ENTRY      WINAPI
#define DLL_ENTRY_FDEF WINAPI
#define DLL_ENTRY_FPTR WINAPI
#elif defined(__WATCOMC__) && defined(__DOS__)
#define DLL_ENTRY __cdecl
#define DLL_ENTRY_FDEF __cdecl
#define DLL_ENTRY_FPTR __cdecl
#define PUBLIC
#else
#define DLL_ENTRY
#define DLL_ENTRY_FDEF
#define DLL_ENTRY_FPTR
#define PUBLIC
#undef OSSX_EXPORT_DLL_DATA
#define OSSX_EXPORT_DLL_DATA
#endif /* _WIN32 || WIN32 */
#undef  _System
#define _System

#endif /* _WINDOWS || _WIN32 || __OS2__ || NETWARE_DLL */

/*****************************************************************************/
/*  PUBLIC section: auxiliary data structures used by OSS API functions      */
/*****************************************************************************/

#ifndef ERR_MSG_LENGTH 
#define ERR_MSG_LENGTH 512      /* length of error messages to be output */
#endif 


typedef struct {
    long           length;
    unsigned char *value;
} OssxBuf;

typedef struct {
    long           length;
    unsigned char *value; 
    long           byteOffset;
} OssxBufExtended;
/* Runtime support for encoded OBJECT IDENTIFIERs */
typedef struct {
    unsigned short length;
    unsigned char *value;
} OssxEncodedOID;

/* Runtime support for encoded RELATIVE-OID */
typedef OssxEncodedOID OssxEncodedRelOID;

/*
 * The structure is produced into the control table by XSD/FWS compiler in
 * WSDL mode and is available through the ossxGetTransportDefaults() API
 * function call.  It is mostly intended for transport layer designers.
 */
typedef struct OssxTransDflt {
    unsigned char *http_endpoint;
    struct {
	int	length; /* number of soap action strings */
	unsigned char	**value; /* one char* for each operation */
    } soapAction;
} OssxTransDflt;

/*
 * The structure keeps parameters of SOAP header element
 */
typedef struct OssxHeaderInfo {
    int msg_id;            /* message id for header message */
    int headerfault_count; /* count of headerfaults declared for header */
    int *headerfaults;     /* array of headerfault message ids declared for header */
} OssxHeaderInfo;

/*
 * The structure is produced into the control table by XSD/FWS compiler in
 * WSDL mode and is available through the ossxGetOperationInfo() API
 * function call.  It is mostly intended for transport layer designers.
 */
typedef struct OssxOperationInfo {
    int            in_msg_id;        /* message id for input message, 0 if empty and -1 if absent */
    int            in_header_count;  /* count of headers declared for input message */
    OssxHeaderInfo *in_headers;      /* array of headers declared for input message */
    int            out_msg_id;       /* message id for output message, 0 if empty and -1 if absent */
    int            out_header_count; /* count of headers declared for output message */
    OssxHeaderInfo *out_headers;     /* array of headers declared for output message */
    int            fault_count;      /* count of faults declared for operation */
    int            *faults;          /* array of fault message ids declared for operation */
} OssxOperationInfo;





/*****************************************************************************/
/*  PUBLIC section: ossxEnv structure (OSS environment variable). It is    */
/*  recommended to use accessor functions when working with ossxEnv.       */
/*****************************************************************************/


#ifndef ossxMemMgrVarLen
#ifdef OS400
#define ossxMemMgrVarLen 100
#define ossxEncDecVarLen 500    /* The size of the
				  encDecVar array shouldn't be less than
				  the sizeof(world->c) since the latter
				  structure overlays encDecVar.  The same
				  is true for the ossxMemMgrVar array since
				  it is overlaid by world->t */
#elif defined(WINDOWS_X64) || defined(_M_X64) /* Windows X64 */ \
  || defined(__vms) && (__INITIAL_POINTER_SIZE + 0) == 64  /* OpenVMS 64bit */
#define ossxMemMgrVarLen 64 + 8	/* 64 for the largest world->t in the socket
				 * memory manager plus a slack of 8 */
#define ossxEncDecVarLen 356 + 8 /* 356 to hold the largest TOED world->c plus
				 * a slack of 8 */
#else
#define ossxMemMgrVarLen 48
#define ossxEncDecVarLen 192    /* The size of the
				  encDecVar array shouldn't be less than
				  the sizeof(world->c) since the latter
				  structure overlays encDecVar */
#endif /* OS400 */
#endif /* ossxMemMgrVarLen */

struct ossxEnv {
    /*
     * used for communicating with the memory manager and the tracing-routine
     */
				/* low-level memory allocator */
    void       *(DLL_ENTRY_FPTR *_System mallocp)(size_t p);
				/* memory re-allocator */
    void       *(DLL_ENTRY_FPTR *_System reallocp)(void *p, size_t s);
				/* low-level memory freer */
    void        (DLL_ENTRY_FPTR *_System freep)(void *p);
    size_t      xsdchop;       /* 0 means do not truncate strings; greater 
				 * value means truncate long output strings 
				 * (OCTET STRING, BIT STRING, Character String)
				 * to be "xsdchop" bytes long.  Read by
				 * encoder&decoder tracing 
				 */
    size_t      ossxblock;       /* if not 0, size of largest block
				 * to allocate */
    size_t      ossxprefx;       /* # bytes to leave before OSAK data buffer */

    FILE        *xsdout;       /* tracing output file */

    /* low-level tracing-output function; default is fprintf() */
    int         (DLL_ENTRY_FPTR *xsdprnt)(FILE *stream, const char *format,
			...);

	/*
	 * available for use by user application
	 */
    void        *userVar;

	/*
	 * used for storing DLL- & library NLMs-related parameters
	 */
#if defined(_WINDOWS) || defined(_WIN32) || \
	defined(__OS2__) || defined(NETWARE_DLL)
    OssxFunctionTables    ft;
#endif /* _WINDOWS || _DLL || __OS2__ || NETWARE_DLL */

	/*
	 * related to the new API; not for direct reference by user code
	 */
    void             *ctlTbl;
    int               api;
    int               encMethod;
    unsigned long     encodingFlags;
    unsigned long     decodingFlags;
    long              decodingLength;
    char              errMsg[ERR_MSG_LENGTH];

	/*
	 * reserved for use by the encoder/decoder
	 */
    double            reserved[4];

	/*
	 * reserved for use by the memory manager and the tracing-routine
	 */
    long int    memMgrVar[ossxMemMgrVarLen];

    long int encDecVar[ossxEncDecVarLen];
};


typedef struct ossxEnv OssxEnv;

/*****************************************************************************/
/*  PUBLIC section: memory manager DLL data structure                        */
/*****************************************************************************/

typedef enum {
    OSSX_DEFAULT_MEMMGR = 0, /* memory is malloc'ed for each pointer in
			     * data tree */
    OSSX_FILE_MEMMGR,        /* file memory manager with memory malloc'ed
			     * for each pointer in data tree */
    OSSX_SOCKET_MEMMGR,      /* TCP/IP socket and file memory manager with memory
			     * malloc'ed for each pointer in data tree */
    OSSX_FLAT_MEMMGR,        /* memory is malloc'ed in large blocks */
    OSSX_OSAK_MEMMGR,        /* OSAK-buffer memory manager */
    OSSX_USER_MEMMGR,        /* user memory manager */
    OSSX_RESVD_MEMMGR
} OssxMemMgrType;

typedef enum {
    OSSX_UNKNOWN_OBJECT = 0,
    OSSX_FILE,
    OSSX_SOCKET,
    OSSX_OSAK_BUFFER,
    OSSX_FSTREAM,
    OSSX_MEMORY
} OssxObjType;

#if defined(_WINDOWS) || defined(_WIN32) || defined(WIN32) || \
	defined(__WIN32__) || defined(__OS2__) || defined(NETWARE_DLL)
typedef struct ossxMemManagerTbl {
    int			 (DLL_ENTRY_FPTR *_System ossxMinitp)(void *);
    unsigned char	*(DLL_ENTRY_FPTR *_System ossxDopenInp)(void *,
						void **, unsigned long *);
    unsigned long	 (DLL_ENTRY_FPTR *_System ossxDclosInp)(void *,
						void **, size_t);
    unsigned char	*(DLL_ENTRY_FPTR *_System ossxDswapInp)(void *,
						void **, size_t *);
    void		 (DLL_ENTRY_FPTR *_System ossxDopenOutp)(void *, void *,
						unsigned long, unsigned long);
    unsigned long	 (DLL_ENTRY_FPTR *_System ossxDclosOutp)(void *, void **);
    void		*(DLL_ENTRY_FPTR *_System ossxDallcOutp)(void *, size_t,
								char root);
    void		 (DLL_ENTRY_FPTR *_System ossxOpenWorkp)(void *);
    void		 (DLL_ENTRY_FPTR *_System ossxPushHndlp)(void *, void *);
    unsigned char	*(DLL_ENTRY_FPTR *_System ossxPopHndlp)(void *,
							void **, size_t);
    void		 (DLL_ENTRY_FPTR *_System ossxClosWorkp)(void *);
    void		*(DLL_ENTRY_FPTR *_System ossxAllcWorkp)(void *, size_t);
    unsigned char	*(DLL_ENTRY_FPTR *_System ossxLockMemp)(void *, void *);
    void		 (DLL_ENTRY_FPTR *_System ossxUnlokMemp)(void *, void *,
								char);
    void		 (DLL_ENTRY_FPTR *_System ossxFreerp)(void *, void *);
    int			 (DLL_ENTRY_FPTR *_System _ossxFreeGlobElemp)(void *, int,
							void *, void *);
    void		 (DLL_ENTRY_FPTR *_System ossxDrcovObjp)(void *, int,
							void *, void *);
    unsigned char	*(DLL_ENTRY_FPTR *_System ossxEopenInp)(void *, void *,
								size_t);
    unsigned char	*(DLL_ENTRY_FPTR *_System ossxEswapInp)(void *, void *,
							void *, size_t);
    void		 (DLL_ENTRY_FPTR *_System ossxEclosInp)(void *, void *);
    unsigned char	*(DLL_ENTRY_FPTR *_System ossxEopenOutp)(void *, void **,
							size_t *, char);
    unsigned char	*(DLL_ENTRY_FPTR *_System ossxEswapOutp)(void *, void **,
							size_t, size_t *);
    unsigned long	 (DLL_ENTRY_FPTR *_System ossxEclosOutp)(void *, void **,
							size_t, char);
    void		 (DLL_ENTRY_FPTR *_System ossxErcovObjp)(void *);
    unsigned char	*(DLL_ENTRY_FPTR *_System asideSwapp)(void *,
						void **, size_t, size_t *);
    void		 (DLL_ENTRY_FPTR *_System _ossxFreeBUFp)(void *, void *);
    void		*(DLL_ENTRY_FPTR *_System _ossxMarkObjp)(void *,
								int, void *);
    void		*(DLL_ENTRY_FPTR *_System _ossxUnmarkObjp)(void *,
								void *);
    void		*(DLL_ENTRY_FPTR *_System _ossxGetObjp)(void *,
								void *);
    int			(DLL_ENTRY_FPTR *_System _ossxTestObjp)(void *,
								void *);
    void		(DLL_ENTRY_FPTR *_System _ossxFreeObjectStackp)(void *);
    void		(DLL_ENTRY_FPTR *_System ossxMtermp)(void *);
    void		(DLL_ENTRY_FPTR *_System _ossxSetTimeoutp)(void *, long);
    int			(DLL_ENTRY_FPTR *_System _ossxGetBufferp)(void *, void *);
    int			(DLL_ENTRY_FPTR *_System _ossxSetBufferp)(void *, void *);
    int			(DLL_ENTRY_FPTR *_System _ossxOpenDecoderInputFilep)(void *, char *);
    int			(DLL_ENTRY_FPTR *_System _ossxCloseDecoderInputFilep)(void *);
    int			(DLL_ENTRY_FPTR *_System _ossxOpenEncoderOutputFilep)(void *, char *);
    int			(DLL_ENTRY_FPTR *_System _ossxCloseEncoderOutputFilep)(void *);
    long		(DLL_ENTRY_FPTR *_System _ossxSetMinFileSizep)(void *, long);
    long		(DLL_ENTRY_FPTR *_System _ossxGetMinFileSizep)(void *);
    void		(DLL_ENTRY_FPTR *_System _ossxSetUserMallocFreeReallocp)(void *,
					void *(*)(struct ossxEnv *, size_t),
					void  (*)(struct ossxEnv *, void *),
					void *(*)(struct ossxEnv *, void *, size_t));
    void		(DLL_ENTRY_FPTR *_System _ossxGetUserMallocFreeReallocp)(void *,
					void *(**)(struct ossxEnv *, size_t),
					void  (**)(struct ossxEnv *, void *),
					void *(**)(struct ossxEnv *, void *, size_t));
    void		(DLL_ENTRY_FPTR *_System setOutBufPosp)(void *, size_t);
    void		*(DLL_ENTRY_FPTR *_System getOutBufPosp)(void *, size_t *);
    int			memMgrType;
} OssxMemManagerTbl;
#endif /* _WINDOWS ||_WIN32 || WIN32 || __WIN32__ || __OS2__ || NETWARE_DLL */
/*****************************************************************************/
/*  PUBLIC section: OSS decoder/encoder runtime flags                        */
/*****************************************************************************/

    /*************************************************************************/
    /*      GENERAL FLAGS                                                    */
    /*************************************************************************/

#define OSSX_DEBUGGlobElem           0x02 /* produce tracing output */
#define OSSX_BUFFER_PROVIDED    0x04 /* use caller-provided buffer */
#define OSSX_RESTRAIN           0x08 /* limit output buffer to user-specified size*/
#define OSSX_NOTRAPPING        0x200 /* do no signal trapping */
#define OSSX_NOCONSTRAIN       0x800 /* ignore calling constraint checker */
#define OSSX_IGNORE_DEFER_DECODING 0x400000 /* force runtime to automatically process
				* values with DeferDecoding directive applied */
#define OSSX_STRICT_ENCODING_DECODING_METHOD 0x20000000 /* force a strict checking
				 * of encoding data, e.g.:
				 * - zero length extension check
				 * - illegal fragmentation check */
#define OSSX_USE_COMPRESSION 0x40000000 /* (un)compress encoding */

    /*************************************************************************/
    /*      ENCODER-SPECIFIC FLAGS                                           */
    /*************************************************************************/

#define OSSX_DEFAULT_ALIGN           0 /* use most efficient align (back or front) */
#define OSSX_DEFINITE             0x10 /* force definite-length encoding */
#define OSSX_INDEFINITE           0x20 /* force indefinite-length encoding */
#define OSSX_DETERMINE_ENC_LENGTH 0x40 /* generate only total encoding length
				   * (for use in user memory managers) */
#define OSSX_FRONT_ALIGN          0x80 /* align output to front of output buffer */
#define OSSX_BACK_ALIGN          0x100 /* align output to back of output buffer */

#define OSSX_COMPACT_XML_ENCODING    0x2000000
#define OSSX_NO_XML_DECLARATION      0x4000000
#define OSSX_STRICT_PER_ENCODING_OF_DEFAULT_VALUES 0x8000000
#define OSSX_DONT_OPTIMIZE_XMLNS    0x80000000

    /*************************************************************************/
    /*      DECODER-SPECIFIC FLAGS                                           */
    /*************************************************************************/

#define OSSX_DEBUG_ERRORS    0x10    /* same as OSSX_DEBUGGlobElem */
#define OSSX_RELAXBER OSSX_RELAXED    /* use relaxed BER */
#define OSSX_RELAXPER OSSX_RELAXED    /* use relaxed PER */
#define OSSX_RELAXED    0x400    /* use relaxed decoding methods */
#define OSSX_OBJECT_HANDLE 0x1000    /* temporarily mark object of type with
				 * NOCOPY directive to not free it by
				 * ossxFreeGlobElem() (for use in user memory
				 * managers) */
#define OSSX_SMART_POINTER 0x200000   /* temporarily set to inform memory manager
				  * that it is supposed to treat input handle
				  * (or to return output handle) as smart
				  * pointer rather than plain memory address
				  * (for use in custom memory manager) */ 

    /*************************************************************************/
    /*      OTHER FLAGS                                                      */
    /*************************************************************************/

/*** reserved flags for internal use ***/
#define OSSX_RESERVED_FLAG2    0x4000
#define OSSX_RESERVED_FLAG1    0x8000
#define OSSX_FREE_ENCODED     0x10000/* when calling ossxFreeGlobElem() and using
				 * DeferDecoding and OBJHANDLE directives, free
				 * the field "encoded" of OssxOpenTypeExtended */
#define OSSX_RESERVED_FLAG3   0x20000


/*****************************************************************************/
/*  PUBLIC section: OSS API return codes                                     */
/*****************************************************************************/

    /*************************************************************************/
    /*      GENERAL RETURN CODES                                             */
    /*************************************************************************/

#define OSSX_MORE_BUF                    1 /* user-provided outbut buffer
				       * too small */
#define OSSX_GlobElem_RANGE                   3 /* global element specified out of range */
#define OSSX_BAD_ARG                     6 /* something weird was passed - probably
				       * a NULL pointer */
#define OSSX_BAD_VERSION                 7 /* versions of encoder/decoder and
				       * control-table do not match */
#define OSSX_OUT_MEMORY                  8 /* memory-allocation error */
#define OSSX_BAD_OBJID                  10 /* object identifier conflicts with
				       * X.680 */
#define OSSX_MEM_ERROR                  14 /* memory violation signal trapped */
#define OSSX_CONSTRAINT_VIOLATED        17 /* constraint violation error occured */
#define OSSX_FATAL_ERROR                18 /* *serious* error, could not free memory,
				       * &etc */
#define OSSX_ACCESS_SERIALIZATION_ERROR 19 /* error occured during access to
				       * global data in a multi-threaded
				       * environment */
#define OSSX_NULL_TBL                   20 /* attempt was made to pass a NULL
				       * control table pointer */
#define OSSX_BAD_ENCMETHOD               22 /* unknown encoding methods set in the
				       * ossxEnv structure */
#define OSSX_UNAVAIL_ENCMETHOD           23 /* the encoding methods requested are
				       * not implemented yet or were not
				       * linked because the encoder/decoder
				       * function pointers were not
				       * initialized by a call to ossxinit() */
#define OSSX_CANT_OPEN_TRACE_WINDOW     24 /* error when opening a trace window */
#define OSSX_UNIMPLEMENTED              25 /* unimplemented type or feature */
#define OSSX_CANT_OPEN_TRACE_FILE       27 /* error when opening a trace file */
#define OSSX_TRACE_FILE_ALREADY_OPEN    28 /* the trace file has been opened */
#define OSSX_TYPE_NOT_SUPPORTED         30 /* XSD type is not supported */
#define OSSX_REAL_DLL_NOT_LINKED        31 /* REAL DLL was not linked */
#define OSSX_REAL_CODE_NOT_LINKED       32 /* REAL code was not linked */
#define OSSX_OUT_OF_RANGE               33 /* parameter value range error */
#define OSSX_COPIER_DLL_NOT_LINKED      34 /* value copier DLL was not linked */
#define OSSX_CONSTRAINT_DLL_NOT_LINKED  35 /* constraint checker DLL was not
				       * linked */
#define OSSX_COMPARATOR_DLL_NOT_LINKED  36 /* value comparator DLL was not linked */
#define OSSX_COMPARATOR_CODE_NOT_LINKED 37 /* value comparator code was not linked */
#define OSSX_MEM_MGR_DLL_NOT_LINKED     38 /* memory manager DLL was not linked */
#define OSSX_TRACING_CODE_NOT_LINKED    39 /* tracing code not linked or
				       * initialized */
#define OSSX_API_DLL_NOT_LINKED         41 /* API DLL was not linked */
#define OSSX_BERDER_DLL_NOT_LINKED      42 /* BER/DER DLL was not linked */
#define OSSX_PER_DLL_NOT_LINKED         43 /* PER DLL was not linked */
#define OSSX_OPEN_TYPE_ERROR            44 /* error in automatic encoding/decoding/
                                       * copying an open type */
#define OSSX_MUTEX_NOT_CREATED          45 /* mutex was not created */
#define OSSX_CANT_CLOSE_TRACE_FILE      46 /* error when closing a trace file */
#define OSSX_CANT_SET_START_BUF         47 /* initial buffer to start decoding from
                                       * cannot be set */
#define OSSX_START_BUF_NOT_SET          48 /* initial buffer to start decoding from
                                       * is not set */

#define OSSX_ERROR_READING_FROM_DECODER_INPUT_FILE 54 /* error reading from decoder
						  * input file */
#define OSSX_DECODER_INPUT_FILE_ALREADY_OPEN       55 /* decoder input file is
						  * already opened */
#define OSSX_CANT_CLOSE_DECODER_INPUT_FILE         56 /* error when closing decoder
						  * input file */
#define OSSX_CANT_OPEN_DECODER_INPUT_FILE          57 /* error when opening decoder
						  * input file */
#define OSSX_ENCODER_OUTPUT_FILE_ALREADY_OPEN      58 /* encoder output file is
						  * already opened */
#define OSSX_CANT_CLOSE_ENCODER_OUTPUT_FILE        59 /* error when closing encoder
						  * output file */
#define OSSX_CANT_OPEN_ENCODER_OUTPUT_FILE         60 /* error when opening encoder
						  * output file */
#define OSSX_CANT_CLOSE_FROM_ASCII      61 /* error when closing iconv tables */
#define OSSX_CANT_CLOSE_TO_ASCII        62 /* error when closing iconv tables */
#define OSSX_ASCII_EBCDIC_CONV_ERROR    63 /* error in iconv call */
#define OSSX_CANT_OPEN_FROM_ASCII       64 /* error when opening iconv tables */
#define OSSX_CANT_OPEN_TO_ASCII         65 /* error when opening iconv tables */
#define OSSX_CANT_OPEN_INPUT_FILE       86 /* error while opening input file */
#define OSSX_PATTERN_CONSTRAINT_NOT_LINKED 101 /* Pattern constraint code was
					   * not linked */
#define OSSX_BAD_OBJIDNODE                 103 /* object identifier conflicts
					   * with X.680 */
#define OSSX_XML_DLL_NOT_LINKED           110 /* XML DLL was not linked or found */

    /*************************************************************************/
    /*      ENCODER-SPECIFIC RETURN CODES                                    */
    /*************************************************************************/

#define OSSX_GlobElem_ENCODED       0  /* Global Element successfully encoded */
#define OSSX_BAD_CHOICE        9  /* unknown selector for a choice */
#define OSSX_BAD_PTR          11  /* unexpected NULL pointer in input buffer */
#define OSSX_BAD_TIME         12  /* bad value in time type */
#define OSSX_INDEFINITE_NOT_SUPPORTED 13 /* BER indefinite-length encoding is not
				     * supported for Spartan or time-optimized
				     * encoder/decoder */
#define OSSX_BAD_TABLE         15 /* table was bad, but not NULL */
#define OSSX_TOO_LONG          16 /* type was longer than shown in SIZE constraint */
#define OSSX_NOCOPY_FRAGMENTED 102 /* NOCOPY directive is specified for an item
			       * which must be encoded in fragmented manner
			       * (usually for CER) */

    /*************************************************************************/
    /*      DECODER-SPECIFIC RETURN CODES                                    */
    /*************************************************************************/

#define OSSX_GlobElem_DECODED       0  /* Global Element successfully decoded */
#define OSSX_NEGATIVE_UINTEGER 2  /* the first bit of the encoding is encountered
                              * set to 1 while decoding an unsigned integer */
#define OSSX_MORE_INPUT        4  /* the Global Element is not fully decoded, but the end
			      * of the input buffer has been reached */
#define OSSX_DATA_ERROR        5  /* an error exists in the encoded data */
#define OSSX_GlobElem_MISMATCH      9  /* the Global Element tag that the user specified was diffe-
			      * rent from the tag found in the encoded data */
#define OSSX_LIMITED          10  /* implementation limit exceeded. eg:
			      * integer value too great */
#define OSSX_EOF_INPUT_FILE   85  /* EOF decoder input file, no Global Element was decoded */
#define OSSX_TIMEOUT_EXPIRED 130 /* unable to read due to an exceeded timeout */

    /*************************************************************************/
    /*      STANDALONE CONSTRAINT CHECKER RETURN CODES                       */
    /*************************************************************************/

#define OSSX_TYPE_CONSTRAINT                              66
#define OSSX_VALUE_NOT_AMONG_ENUMERATED_CONSTRAINT        67
#define OSSX_PRESENCE_CONSTRAINT                          70
#define OSSX_ABSENCE_CONSTRAINT                           71
#define OSSX_PERMITTED_ALPHABET_CONSTRAINT                72
#define OSSX_SIZE_CONSTRAINT_LIST                  73
#define OSSX_SIZE_CONSTRAINT_STRING                       74
#define OSSX_VALUE_RANGE_CONSTRAINT_REAL                  75
#define OSSX_VALUE_RANGE_CONSTRAINT_UNSIGNED_INTEGER      76
#define OSSX_VALUE_RANGE_CONSTRAINT_SIGNED_INTEGER        77
#define OSSX_SINGLE_VALUE_CONSTRAINT_COMPLEX_TYPE         78
#define OSSX_SINGLE_VALUE_CONSTRAINT_STRING               79
#define OSSX_SINGLE_VALUE_CONSTRAINT_REAL                 80
#define OSSX_SINGLE_VALUE_CONSTRAINT_UNSIGNED_INTEGER     81
#define OSSX_SINGLE_VALUE_CONSTRAINT_SIGNED_INTEGER       82
#define OSSX_PATTERN_CONSTRAINT                          100
    /*************************************************************************/
    /*      LEAN DECODER/ENCODER COMPATIBILITY RETURN CODES                  */
    /*************************************************************************/

#define OSSX_LEAN_BAD_VERSION                    87 /* versions of LEAN
			    * encoder/decoder and control-table do not match */
#define OSSX_LEAN_AUTOMATIC_ENCDEC_NOT_SUPPORTED 88 /* The AUTOMATIC_ENCDEC
			* directive is not supported for LEAN endoder/decoder */
#define OSSX_LEAN_RELAYSAFE_NOT_SUPPORTED        89 /* The relaySafe mode
			    * is not supported for LEAN endoder/decoder */
#define OSSX_LEAN_DER_ENCODER_NOT_SUPPORTED      90 /* The DER encoding methods
			    * are not supported for LEAN endoder/decoder */
#define OSSX_LEAN_REALTYPE_NOT_SUPPORTED         91 /* The REAL type
			    * is not supported for LEAN endoder/decoder */
#define OSSX_LEAN_REMOVE_NOT_SUPPORTED           92 /* The REMOVE directive
			    * is not supported for LEAN endoder/decoder */
#define OSSX_LEAN_NOCOPY_NOT_SUPPORTED           93 /* The NOCOPY directive
			    * is not supported for LEAN endoder/decoder */
#define OSSX_LEAN_DEFERDECODING_NOT_SUPPORTED    94 /* The DeferDecoding
			* directive is not supported for LEAN endoder/decoder */
#define OSSX_LEAN_USERHOOKS_NOT_SUPPORTED        95 /* The user hook directives
			    * are not supported for LEAN endoder/decoder */
#define OSSX_LEAN_TRUNCATE_SOF_NOT_SUPPORTED     96 /* The Truncate directive
			    * is not supported for LEAN decoder */
#define OSSX_LEAN_POINTER_NOT_SUPPORTED		97 /* The POINTER directive
			    * is not supported for LEAN encoder/decoder */
#define OSSX_LEAN_LONGLONG_NOT_SUPPORTED        107 /* The LONGLONG directive
			    * is not supported for LEAN encoder/decoder */
#define OSSX_LEAN_COMPRESSION_NOT_SUPPORTED     117 /* Compression
			    * is not supported by LEAN encoder/decoder */
    /*************************************************************************/
    /*      OTHER RETURN CODES                                               */
    /*************************************************************************/

#define OSSX_CANT_LOAD_DYNLIBRARY            97 /* unable to open dynamic library */
#define OSSX_CANT_UNLOAD_DYNLIBRARY          98 /* unable to close dynamic library */
#define OSSX_CONSTRUCTED_NESTING_LIMIT_EXCEEDED 108 /* nesting level of constructed
						* string encodings exceeds
						* the limit */
#define OSSX_ELEMENT_NESTING_LIMIT_EXCEEDED 109 /* nesting level of encoding of SET,
					    * LIST, LIST or
					    * CHOICE exceeded the limit */
#define OSSX_DEFAULT_PREFIX_NOT_ALLOWED     111
#define OSSX_UNKNOWN_NAMESPACE_URI          112
#define OSSX_INVALID_PREFIX                 113
#define OSSX_PREFIX_ALREADY_ASSIGNED        114
#define OSSX_COMPRESS_ERROR                 115
#define OSSX_NO_QNAME_DATA              116 /* the control table does not contain
                                            * QNAMEs and other XML information */

    /*************************************************************************/
    /*      FAST INFOSET API RETURN CODES                                    */
    /*************************************************************************/

#define OSSX_FI_HEX_ERROR		200 /* invalid format of hexadecimal
					     * string */
#define OSSX_FI_BASE64_ERROR	       	201 /* invalid format of Base64-encoded
					     * string */
#define OSSX_FI_SHORT_ERROR	       	202 /* a) invalid format of short 
					     *    integer value list
					     * b) length of encoding is not 
					     *    divisible by 2 */
#define OSSX_FI_INT_ERROR	       	203 /* a) invalid format of  
					     *    integer value list
					     * b) length of encoding is not 
					     *    divisible by 4 */
#define OSSX_FI_LONG_ERROR	       	204 /* a) invalid format of long 
					     *    integer value list
					     * b) length of encoding is not 
					     *    divisible by 8 */
#define OSSX_FI_BOOLEAN_ERROR	       	205 /* a) invalid format of boolean
					     *    value list
					     * b) invalid encoding of boolean(s) */
#define OSSX_FI_FLOAT_ERROR	       	206 /* a) invalid format of float
					     *    value list
					     * b) length of encoding is not
					     *    divisible by 4 */
#define OSSX_FI_DOUBLE_ERROR	       	207 /* a) invalid format of double
					     *    value list
					     * b) length of encoding is not
					     *    divisible by 8 */
#define OSSX_FI_UUID_ERROR	       	208 /* a) format of UUID (Universal
					     *    Unique Identifier) value list
					     * b) length of encoding is not
					     *    divisible by 8 */
#define OSSX_FI_UTF8_ERROR	       	209 /* invalid format of Utf-8 character */
#define OSSX_FI_INVALID_CATEGORY	       	210 /* invalid or inappropriate
					     * category of a vocabulary item */
#define OSSX_FI_VOCABULARY_FINALIZED    	211 /* vocabulary is finalized and
					     * cannot be changed */
#define OSSX_FI_VOCABULARY_CONSTANT     	212 /* vocabulary is constant and
					     * cannot be changed or deleted */
#define OSSX_FI_VOCABULARY_OVERFLOW	213 /* vocabulary category overflow;
					     * cannot add more items */
#define OSSX_FI_INVALID_INDEX		214 /* one of the string indices (for 
					     * prefix, uri or local name)
					     * exceeds number of items in
					     * corresponding vocabulary category */
#define OSSX_FI_BAD_RESTRICTED_ALPHABET	215 /* invalid restricted alphabet */
#define OSSX_FI_INVALID_CALL_ORDER	216 /* inadmissible order of operations
					     * while creation of the Fast Infoset
					     * document */
#define OSSX_FI_UNSUPP_EXT_ENTITY	217 /* unsupported kind of external
					     * entity */
#define OSSX_FI_EA_NOT_SUPPORTED		218 /* this encoding algorithm is not 
					     * supported by this version of
					     * Fast Infoset runtime */
#define OSSX_FI_JMPBUF_NOT_SET  		219 /* user-provided long jump buffer 
					     * for the Fast Infoset encoder is 
					     * not set by calling 
					     * the ossxFISetJmpBuf() API function */

/*****************************************************************************/
/*  PUBLIC section: OSS compatibility flags                                  */
/*****************************************************************************/


#define OSSX_MANTISSA_EXPONENT_REAL_FORMAT            0x100
#define OSSX_EXTENDED_RESTRICTED_KMC_STRING_AS_OCTETS 0x1000
#define OSSX_PER_NULLTERM_TIME_8BIT_CHARS	     0x2000
#define OSSX_ALLOW_MISPLACED_EXTENSION_FIELDS	     0x4000



/*****************************************************************************/
/*  PUBLIC section: variables and declarations provided for backward         */
/*  compatibility with previous versions (deprecated - new applications      */
/*  should not use them)                                                     */
/*****************************************************************************/
extern int ossxFreeOpenTypeEncoding;

#define OSSX_INITIALIZATION_SUCCESSFUL 0


#if defined(_WINDOWS) || defined(_WIN32) || defined(WIN32) || \
	defined(__WIN32__) || defined(__OS2__) || defined(NETWARE_DLL)
#endif /* _WINDOWS ||_WIN32 || WIN32 || __WIN32__ || __OS2__ || NETWARE_DLL */


/*****************************************************************************/
/*  PUBLIC section: OSS API FUNCTIONS                                        */
/*****************************************************************************/

    /*************************************************************************/
    /*      OBSOLETE FUNCTIONS                                               */
    /*************************************************************************/


PUBLIC void DLL_ENTRY _ossxFreeBUF(struct ossxEnv *world, void *data);
PUBLIC int  DLL_ENTRY _ossxFreeGlobElem(struct ossxEnv *world, int globElemnum, void *data,
				void *ctl_tbl);
    /*************************************************************************/
    /*      CORE-ESSENTIAL FUNCTIONS                                         */
    /*************************************************************************/

PUBLIC int DLL_ENTRY         ossxDecode(struct ossxEnv *world,
					int             *globElemnum,
					OssxBuf          *input,
					void           **output);
PUBLIC int DLL_ENTRY         ossxEncode(struct ossxEnv *world,
					int              globElemnum,
					void            *input,
					OssxBuf          *output);
PUBLIC void DLL_ENTRY        ossxFreeBuf(struct ossxEnv *world,
					void            *data);
PUBLIC int DLL_ENTRY         ossxFreeGlobElem(struct ossxEnv *world,
					int              globElemnum,
					void            *data);
PUBLIC int DLL_ENTRY         ossxinit(struct ossxEnv *world, void *ctl_tbl);
PUBLIC void DLL_ENTRY        ossxterm(struct ossxEnv *world);

#if defined(_WINDOWS) || defined(_WIN32) || defined(WIN32) || \
	defined(__WIN32__) || defined(__OS2__) || defined(NETWARE_DLL)
#define ossxwinit ossxWinit
PUBLIC extern int DLL_ENTRY  ossxWinit(struct ossxEnv *, void *, char *);
PUBLIC extern void DLL_ENTRY ossxWterm(struct ossxEnv *);
/* Mappings and definitions provided for compatibility for other platforms */
#elif !defined(__IBMC__)
#define ossxwinit(world, ctl_tbl, dll_name) ossxinit(world, ctl_tbl)
#define ossxWinit(world, ctl_tbl, dll_name) ossxinit(world, ctl_tbl)
#define ossxWterm(world) ossxterm(world)
#endif /* _WINDOWS ||_WIN32 || WIN32 || __WIN32__ || __OS2__ || NETWARE_DLL */

#if !(defined(__IBMC__) && (defined(__WIN32__) || defined(__OS2__))) && \
	!defined(DYNAMICLINKING_NOTSUPPORTED)
int                          ossxUinit(struct ossxEnv *world, void *ctl_tbl,
					char *ctl_dll);
void                         ossxUterm(struct ossxEnv *world);
#endif /* !(__IBMC__ ...) && !DYNAMICLINKING_NOTSUPPORTED && !TOED_LED */

    /*************************************************************************/
    /*      USEFUL NON-ESSENTIAL FUNCTIONS                                   */
    /*************************************************************************/
PUBLIC int DLL_ENTRY        ossxCloseTraceFile(struct ossxEnv *world);

PUBLIC unsigned long DLL_ENTRY ossxGetDecodingFlags(struct ossxEnv *world);
PUBLIC unsigned long DLL_ENTRY ossxGetEncodingFlags(struct ossxEnv *world);
PUBLIC int DLL_ENTRY        ossxGetEncodingMethod(struct ossxEnv *world);
PUBLIC char *DLL_ENTRY      ossxGetErrMsg(struct ossxEnv *world);
PUBLIC char *DLL_ENTRY ossxDescribeReturnCode(OssxEnv *in_world, int in_rc);
PUBLIC unsigned long DLL_ENTRY ossxGetFlags(struct ossxEnv *world);

PUBLIC int DLL_ENTRY        ossxOpenTraceFile(struct ossxEnv *world,
					char          *fileName);

#if defined(_WINDOWS) || defined(_WIN32) || defined(WIN32) || \
	defined(__WIN32__) || defined(__OS2__) || defined(NETWARE_DLL)
PUBLIC extern int DLL_ENTRY ossxOpenTraceWindow(struct ossxEnv *);
#endif /* _WINDOWS ||_WIN32 || WIN32 || __WIN32__ || __OS2__ || NETWARE_DLL */

extern int                  ossxPrint(struct ossxEnv *, const char *, ...);
PUBLIC void DLL_ENTRY       ossxPrintHex(struct ossxEnv *world,
					char          *encodedData,
					long           length);

PUBLIC int DLL_ENTRY        ossxSetDecodingFlags(struct ossxEnv *world,
					unsigned long flags);
PUBLIC int DLL_ENTRY	    ossxIdentifyElementByXMLName(struct ossxEnv *world,
					unsigned char *uri,
					unsigned char *name, int *globElem);
PUBLIC int DLL_ENTRY        ossxSetEncodingFlags(struct ossxEnv *world,
					unsigned long flags);
PUBLIC int DLL_ENTRY        ossxSetEncodingMethod(struct ossxEnv *world,
					ossxEncodingMethod rules);
PUBLIC int DLL_ENTRY        ossxSetFlags(struct ossxEnv *world,
					unsigned long flags);
extern int DLL_ENTRY        ossxTest(struct ossxEnv *world,
					int            globElemnum,
					void          *data);
    /*************************************************************************/
    /*      ADVANCED-USER FUNCTIONS                                          */
    /*************************************************************************/

PUBLIC int DLL_ENTRY        ossxCloseDecoderInputFile(struct ossxEnv *world);
PUBLIC int DLL_ENTRY        ossxCloseEncoderOutputFile(struct ossxEnv *world);
PUBLIC long DLL_ENTRY       ossxDetermineEncodingLength(struct ossxEnv *world,
							int        globElemnum,
							void      *data);
PUBLIC unsigned long DLL_ENTRY ossxDetermineBERMessageLength(
						    struct ossxEnv *world,
						    OssxBuf           *buf);

PUBLIC int DLL_ENTRY        ossxDetermineNumberOfPadBits(struct ossxEnv *);

PUBLIC int DLL_ENTRY 	    ossxSetEncoderPrefixMode(struct ossxEnv *world,
						    OssxPrefixingMode in_mode);
PUBLIC int DLL_ENTRY        ossxGetEncoderPrefixMode(struct ossxEnv *world, 
						    OssxPrefixingMode *out_mode);
PUBLIC int DLL_ENTRY        ossxGetDecoderPrefixMode(struct ossxEnv *world,
						    ossxBoolean *in_mode);
PUBLIC int DLL_ENTRY        ossxSetDecoderPrefixMode(struct ossxEnv *world,
						    ossxBoolean in_mode);
PUBLIC int DLL_ENTRY        ossxSkipPrefixBytes(struct ossxEnv *world, 
						    OssxBuf *input, 
						    OssxBuf *out_prefix,
						    int *globElemnum);
PUBLIC int DLL_ENTRY        ossxGetBuffer(struct ossxEnv *world,
					    OssxBufExtended *buf);

PUBLIC long DLL_ENTRY       ossxGetBytesReadByDecoder(struct ossxEnv *world);
PUBLIC long DLL_ENTRY       ossxGetDecodingLength(struct ossxEnv *world);
PUBLIC long DLL_ENTRY       ossxGetMinFileSize(struct ossxEnv *world);
PUBLIC void *DLL_ENTRY      ossxGetObj(struct ossxEnv *world, void *objHndl);

PUBLIC void DLL_ENTRY       ossxGetUserMallocFreeRealloc(struct ossxEnv *world,
		void *(**ossxUserMalloc)(struct ossxEnv *world, size_t size),
		void  (**ossxUserFree)(struct ossxEnv *world, void *buf),
		void *(**ossxUserRealloc)(struct ossxEnv *world, void *buf,
					    size_t size));
#if defined(_WINDOWS) || defined(_WIN32) || defined(WIN32) || \
	defined(__WIN32__) || defined(__OS2__) || defined(NETWARE_DLL)
PUBLIC extern HINSTANCE DLL_ENTRY ossxLoadMemoryManager(struct ossxEnv *,
							int, char *);
#endif /* _WINDOWS ||_WIN32 || WIN32 || __WIN32__ || __OS2__ || NETWARE_DLL */

PUBLIC void *DLL_ENTRY      ossxMarkObj(struct ossxEnv *world,
					    OssxObjType objType, void *object);
PUBLIC int DLL_ENTRY        ossxOpenDecoderInputFile(struct ossxEnv *world,
					    char *fname);
PUBLIC int DLL_ENTRY        ossxOpenEncoderOutputFile(struct ossxEnv *world,
					    char *fname);
PUBLIC int DLL_ENTRY        ossxSetBuffer(struct ossxEnv *world,
					    OssxBufExtended *buf);
PUBLIC int DLL_ENTRY        ossxSetDecodingLength(struct ossxEnv *world,
						    long bufferLength);
PUBLIC long DLL_ENTRY       ossxSetMinFileSize(struct ossxEnv *world,
					    long minsize);
PUBLIC void DLL_ENTRY       ossxSetTimeout(struct ossxEnv *world,
					    long timeout);

PUBLIC void DLL_ENTRY       ossxSetUserMallocFreeRealloc(struct ossxEnv *world,
		void *(*ossxUserMalloc)(struct ossxEnv *world, size_t size),
		void  (*ossxUserFree)(struct ossxEnv *world, void *buf),
		void *(*ossxUserRealloc)(struct ossxEnv *world, void *buf,
					size_t size));
PUBLIC int DLL_ENTRY        ossxSkipPadBytes(struct ossxEnv *world,
					OssxBuf *input, unsigned char pad_byte);
PUBLIC OssxObjType DLL_ENTRY ossxTestObj(struct ossxEnv *world, void *objHndl);
PUBLIC void *DLL_ENTRY      ossxUnmarkObj(struct ossxEnv *world,
					    void *objHndl);
    /*************************************************************************/
    /*      SPECIALIZED-TASK FUNCTIONS                                       */
    /*************************************************************************/




PUBLIC int  DLL_ENTRY       ossxValidate(struct ossxEnv *world,
				int          globElemnum,
				void        *data);

PUBLIC extern int DLL_ENTRY ossxCmpValue (struct ossxEnv *world, int globElemnum,
				void *originalData,void *copiedData);
PUBLIC extern int DLL_ENTRY ossxCpyValue (struct ossxEnv *world, int globElemnum,
				void *source, void **destination);
PUBLIC int DLL_ENTRY        ossxDupEnv(struct ossxEnv *org_world, 
				struct ossxEnv *dup_world);

PUBLIC void DLL_ENTRY       ossxFreeMemory(struct ossxEnv *g, void *p);


PUBLIC int DLL_ENTRY        ossxGetConstructedNestingLimit(
				struct ossxEnv *world);

PUBLIC void *DLL_ENTRY      ossxGetMemory(struct ossxEnv *g, size_t size);
PUBLIC void * DLL_ENTRY     ossxGetInitializedMemory(struct ossxEnv *g,
				size_t size);
PUBLIC int DLL_ENTRY        ossxGetEnvSize(void);


PUBLIC int DLL_ENTRY        ossxGetElementNestingLimit(struct ossxEnv *world);


PUBLIC void DLL_ENTRY       ossxGetUserPrint(struct ossxEnv *world,
				FILE **stream,
				int (DLL_ENTRY_FPTR **ossxUserPrint)(
				    struct ossxEnv *world, const char *format,
				    ...));
PUBLIC void DLL_ENTRY       ossxGetUserVprint(struct ossxEnv *world,
				FILE **stream,
				int (DLL_ENTRY_FPTR **ossxUserVprint)(
				    struct ossxEnv *world, const char *fmt,
				    va_list ap));
PUBLIC int DLL_ENTRY        ossxInitSync(void);


PUBLIC int DLL_ENTRY        ossxSetConstructedNestingLimit(
				struct ossxEnv *world, int limit);

PUBLIC int DLL_ENTRY        ossxSetElementNestingLimit(struct ossxEnv *world,
				int limit);


PUBLIC void DLL_ENTRY       ossxSetUserPrint(struct ossxEnv *world,
				FILE *stream,
				int (DLL_ENTRY_FPTR *ossxUserPrint)(
				    struct ossxEnv *world, const char *format,
				    ...));
PUBLIC int DLL_ENTRY        ossxSetUserStack(struct ossxEnv *world,
				OssxBuf *buf);

PUBLIC void DLL_ENTRY       ossxSetUserVprint(struct ossxEnv *world,
				FILE *stream,
				int (DLL_ENTRY_FPTR *ossxUserVprint)(
				    struct ossxEnv *world, const char *fmt,
				    va_list ap));

PUBLIC void DLL_ENTRY       ossxTermSync(void);

PUBLIC int DLL_ENTRY        ossxValidateXMLInstance(OssxEnv *world,
				int globElemNum, OssxBuf *input);
    /*************************************************************************/
    /*      XML-RELATED FUNCTIONS                                            */
    /*************************************************************************/

#define OSSX_UTC_DIFF_Z       INT_MAX
#define OSSX_UTC_DIFF_ABSENT (INT_MAX - 1)

PUBLIC int DLL_ENTRY        ossxBinary2XML(struct ossxEnv *world,
				int               globElemnum,
				ossxEncodingMethod  r_from,
				OssxBuf           *b_from, 
				OssxBuf           *b_xml);
PUBLIC int DLL_ENTRY        ossxDateTimeToInts (struct ossxEnv *world,
				char *dateTimeString, int *year,
				unsigned int *month, unsigned int *day,
				unsigned int *hours, unsigned int *minutes,
				unsigned int *seconds, char **fraction,
				unsigned int *precision,
				int *local_utc_mindiff);
PUBLIC int DLL_ENTRY        ossxDateToInts(struct ossxEnv *world,
				char *dateString, int *year,
				unsigned int *month,
				unsigned int *day, int *local_utc_mindiff);
PUBLIC int DLL_ENTRY        ossxDurationToInts (struct ossxEnv *world,
				char *durationString,
				ossxBoolean *negative,
				unsigned int *year, unsigned int *months,
				unsigned int *days, unsigned int *hours,
				unsigned int *minutes, unsigned int *seconds,
				char **fraction, unsigned int *precision);
PUBLIC int DLL_ENTRY        ossxGDayToInts(struct ossxEnv *world,
				char *gDayString, unsigned int *day,
				int *local_utc_mindiff);
PUBLIC int DLL_ENTRY        ossxGMonthDayToInts(struct ossxEnv *world,
				char *gMonthDayString, unsigned int *month,
				unsigned int *day, int *local_utc_mindiff);
PUBLIC int DLL_ENTRY        ossxGMonthToInts(struct ossxEnv *world,
				char *gMonthString, unsigned int *month,
				int *local_utc_mindiff);
PUBLIC int DLL_ENTRY        ossxGYearMonthToInts (struct ossxEnv *world,
				char *gYearMonthString, int *year,
				unsigned int *month, int *local_utc_mindiff);
PUBLIC int DLL_ENTRY        ossxGYearToInts(struct ossxEnv *world,
				char *gYearString, int *year,
				int *local_utc_mindiff);
PUBLIC int DLL_ENTRY        ossxGetNamespacePrefix(struct ossxEnv *world,
				char *ns, char **prefix);


PUBLIC int DLL_ENTRY        ossxIntsToDate(struct ossxEnv *world, int year,
				unsigned int month, unsigned int day,
				int local_utc_mindiff, char **dateString);
PUBLIC int DLL_ENTRY        ossxIntsToDateTime(struct ossxEnv *world, int year,
				unsigned int month, unsigned int day,
				unsigned int hours, unsigned int minutes,
				unsigned int seconds, char *fraction,
				unsigned int precision, int local_utc_mindiff,
				char ** dateTimeString);
PUBLIC int DLL_ENTRY        ossxIntsToDuration(struct ossxEnv *world,
				ossxBoolean negative, unsigned int year,
				unsigned int months, unsigned int days,
				unsigned int hours, unsigned int minutes,
				unsigned int seconds, char *fraction,
				unsigned int precision, char ** durationString);
PUBLIC int DLL_ENTRY        ossxIntsToGDay(struct ossxEnv *world,
				unsigned int day, int local_utc_mindiff,
				char **gDayString);
PUBLIC int DLL_ENTRY        ossxIntsToGMonth(struct ossxEnv *world,
				unsigned int month, int local_utc_mindiff,
				char **gMonthString);
PUBLIC int DLL_ENTRY        ossxIntsToGMonthDay(struct ossxEnv *world,
				unsigned int month, unsigned int day,
				int local_utc_mindiff, char **gMonthDayString);
PUBLIC int DLL_ENTRY        ossxIntsToGYear(struct ossxEnv *world,
				int year, int local_utc_mindiff,
				char **gYearString);
PUBLIC int DLL_ENTRY        ossxIntsToGYearMonth(struct ossxEnv *world,
				int year, unsigned int month,
				int local_utc_mindiff, char **gYearMonthString);
PUBLIC int DLL_ENTRY        ossxIntsToTime(struct ossxEnv *world,
				unsigned int hours, unsigned int minutes,
				unsigned int seconds, char *fraction,
				unsigned int precision, int local_utc_mindiff,
				char **timeString);
PUBLIC void DLL_ENTRY       ossxPrintXML(struct ossxEnv *world,
				char             *encodedData,
				long              length,
				ossxBoolean        pretty_print);
PUBLIC int DLL_ENTRY        ossxSetNamespacePrefix(struct ossxEnv *world,
				char *ns, char *prefix);
/* Valid DTD kinds */
#define OSSX_XDTD_NONE       0 /* use to disable DTD generation */
#define OSSX_XDTD_SYSTEM     1
#define OSSX_XDTD_PUBLIC     2



PUBLIC int DLL_ENTRY        ossxSetXmlStylesheet(struct ossxEnv *world,
				char *name);
PUBLIC int DLL_ENTRY        ossxTimeToInts(struct ossxEnv *world,
				char *timeString,
				unsigned int *hours, unsigned int *minutes,
				unsigned int *seconds, char **fraction,
				unsigned int *precision,
				int *local_utc_mindiff);
PUBLIC int DLL_ENTRY        ossxXML2Binary(struct ossxEnv *world,
				int               globElemnum,
				ossxEncodingMethod  r_to,
				OssxBuf           *b_xml,
				OssxBuf           *b_to);

    /*************************************************************************/
    /*      ENCODING COMPRESSION ROUTINES                                    */
    /*************************************************************************/

typedef int (DLL_ENTRY_FPTR *_System ossxCompFcnPtr)(struct ossxEnv *world,
              			unsigned char *outbuf, unsigned long *outlen,
            			unsigned char *inbuf, unsigned long inlen,
				void *data);
typedef unsigned long (DLL_ENTRY_FPTR *_System ossxCompEstFcnPtr)(
				unsigned char *inbuf,
				unsigned long inlen, void *info);
PUBLIC int DLL_ENTRY        ossxGetCompressDecompressFunctions(
				struct ossxEnv *world,
				ossxCompFcnPtr *ossxCompressFp,
				ossxCompFcnPtr *ossxUnCompressFp);
PUBLIC int DLL_ENTRY        ossxGetCompressDecompressInfo(
				struct ossxEnv *world, void **info);
PUBLIC int DLL_ENTRY        ossxGetCompSizeEstimator(struct ossxEnv *world,
				ossxCompEstFcnPtr *ossxCompEstFp);
PUBLIC int DLL_ENTRY        ossxSetCompressDecompressFunctions(
				struct ossxEnv *world,
				ossxCompFcnPtr ossxCompressFp,
				ossxCompFcnPtr ossxUnCompressFp);
PUBLIC int DLL_ENTRY        ossxSetCompressDecompressInfo(
				struct ossxEnv *world, void *info);
PUBLIC int DLL_ENTRY        ossxSetCompSizeEstimator(struct ossxEnv *world,
				ossxCompEstFcnPtr ossxCompEstFp);

PUBLIC int DLL_ENTRY        ossxCompress(OssxEnv *world, OssxBuf *input,
				OssxBuf *output, long prefix_len);
PUBLIC int DLL_ENTRY        ossxUnCompress(OssxEnv *world, OssxBuf *input,
				OssxBuf *output, ossxBoolean prefix);
    /*************************************************************************/
    /*      DEBUG FLAGS FUNCTIONS                                            */
    /*************************************************************************/

/* Debug flags controlled by ossxSetDebugFlags() and ossxGetDebugFlags() */
#define OSSX_PRINT_DECODING_DETAILS	0x01
#define OSSX_PRINT_ENCODING_DETAILS	0x02
#define OSSX_PRINT_DECODER_OUTPUT	0x04
#define OSSX_PRINT_DECODER_INPUT	0x08
#define OSSX_PRINT_ENCODER_OUTPUT	0x10
#define OSSX_PRINT_ENCODER_INPUT	0x20
#define OSSX_PRINT_ERROR_MESSAGES	0x40
#define OSSX_PRINT_HEX_WITH_ASCII	0x80


#define OSSX_DEBUG_DATA_RESERVED1	0x8000

/*
 * The following defines diagnostic levels by combining the above debug flags
 * into five commonly used groups.
 */

#define OSSX_DEBUG_LEVEL_0  0

#define OSSX_DEBUG_LEVEL_1       OSSX_PRINT_ERROR_MESSAGES

#define OSSX_DEBUG_LEVEL_2       (OSSX_PRINT_ERROR_MESSAGES | \
				 OSSX_PRINT_ENCODER_INPUT  | \
				 OSSX_PRINT_DECODER_OUTPUT)

#define OSSX_DEBUG_LEVEL_3       (OSSX_PRINT_ERROR_MESSAGES | \
				 OSSX_PRINT_ENCODER_INPUT  | \
				 OSSX_PRINT_DECODER_INPUT  | \
				 OSSX_PRINT_ENCODER_OUTPUT | \
				 OSSX_PRINT_DECODER_OUTPUT | \
				 OSSX_PRINT_HEX_WITH_ASCII)

#define OSSX_DEBUG_LEVEL_4       (OSSX_PRINT_ERROR_MESSAGES   | \
				 OSSX_PRINT_ENCODER_INPUT    | \
				 OSSX_PRINT_DECODER_INPUT    | \
				 OSSX_PRINT_ENCODER_OUTPUT   | \
				 OSSX_PRINT_DECODER_OUTPUT   | \
				 OSSX_PRINT_HEX_WITH_ASCII   | \
				 OSSX_PRINT_DECODING_DETAILS | \
				 OSSX_PRINT_ENCODING_DETAILS)

PUBLIC unsigned long DLL_ENTRY ossxGetDebugFlags(struct ossxEnv *world);
PUBLIC int DLL_ENTRY           ossxSetDebugFlags(struct ossxEnv *world,
						unsigned long flags);

    /*************************************************************************/
    /*      MEMORY HANDLES FUNCTIONS                                         */
    /*      (OSS API providing optimized dynamic memory management)          */
    /*************************************************************************/

typedef struct ossxMemoryHandle OssxMemoryHandle;

PUBLIC int DLL_ENTRY         ossxCleanMemoryHandle(struct ossxEnv *world,
						    OssxMemoryHandle *hdl);
PUBLIC OssxMemoryHandle *DLL_ENTRY ossxCreateMemoryHandle(struct ossxEnv *world,
						    size_t chunkLength);
PUBLIC int DLL_ENTRY         ossxDeleteMemoryHandle(struct ossxEnv *world,
						    OssxMemoryHandle *hdl);
PUBLIC OssxMemoryHandle *DLL_ENTRY ossxGetActiveMemoryHandle(
						    struct ossxEnv *world);
typedef struct ossxMemoryHandleStat {
    unsigned int	nodes;			/* number of memory 'pages' */
    size_t		system_allocated;	/* total amount of memory in
						 * all memory pages */
    struct {
	size_t		used_internally;	/* total amount of memory used
						 * by the memory manager */
	size_t		user_allocated;		/* total amount of used memory 
						 * in all memory pages */
	size_t		user_free;		/* total amount of available 
						 * memory */
    } detail;
} OssxMemoryHandleStat;

/* Flag settings for ossxGetMemoryHandleStat() function */

#define OSSX_MH_BRIEF			0 /* do not fill stat.detail     */
#define OSSX_MH_DETAIL			1 /* fill stat.detail            */
#define OSSX_MH_DETAIL_TRACE_HANDLE	2 /* + tracing for the handle    */
#define OSSX_MH_DETAIL_TRACE_BLOCKS	3 /* + tracing for each block    */
#define OSSX_MH_DETAIL_TRACE_FRAGMENTS	4 /* + tracing for each fragment *
					   *   allocated within a block  */

#define OSSX_MH_NO_PTR_IN_TRACE	0x20	  /* don't print pointer values  *
					   * that change from run to run */

PUBLIC int DLL_ENTRY         ossxGetMemoryHandleStat(struct ossxEnv *world,
						    OssxMemoryHandle *hdl,
						    OssxMemoryHandleStat *stat,
						    unsigned int flags);

PUBLIC int DLL_ENTRY         ossxSetActiveMemoryHandle(struct ossxEnv *world,
						    OssxMemoryHandle *hdl);
    /*************************************************************************/
    /*      HELPER MACROS FUNCTIONS                                          */
    /*************************************************************************/


#define OSSX_STR(value_) \
	ossx__CharStr_copy(world, value_)

#define OSSX_USTR(value_) \
	(unsigned char *)ossx__CharStr_copy(world, (char *)value_)

PUBLIC void *DLL_ENTRY      ossx__BmpString_copy(struct ossxEnv *world,
				    unsigned short *value, unsigned int length);
PUBLIC ossxBoolean *DLL_ENTRY ossx__Bool_copy(struct ossxEnv *world,
				    ossxBoolean value);
PUBLIC char *DLL_ENTRY      ossx__CharStr_copy(struct ossxEnv *world,
				    char *value);
PUBLIC char *DLL_ENTRY      ossx__CharStr_new(struct ossxEnv *world,
				    unsigned int length);
PUBLIC char *DLL_ENTRY      ossx__Char_copy(struct ossxEnv *world, char value);
PUBLIC double *DLL_ENTRY    ossx__Double_copy(struct ossxEnv *world,
				    double value);
PUBLIC float *DLL_ENTRY     ossx__Float_copy(struct ossxEnv *world,
				    float value);
PUBLIC int *DLL_ENTRY       ossx__Int_copy(struct ossxEnv *world, int value);
PUBLIC LONG_LONG *DLL_ENTRY ossx__LongLong_copy(struct ossxEnv *world,
				    LONG_LONG value);
PUBLIC long *DLL_ENTRY      ossx__Long_copy(struct ossxEnv *world, long value);
PUBLIC void *DLL_ENTRY      ossx__Ptr_copy(struct ossxEnv *world, void *ptr);
PUBLIC short *DLL_ENTRY     ossx__Short_copy(struct ossxEnv *world,
				    short value);
PUBLIC unsigned char *DLL_ENTRY  ossx__UChar_copy(struct ossxEnv *world,
				    unsigned char value);
PUBLIC unsigned int *DLL_ENTRY   ossx__UInt_copy(struct ossxEnv *world,
				    unsigned int value);
PUBLIC ULONG_LONG *DLL_ENTRY     ossx__ULongLong_copy(struct ossxEnv *world,
				    ULONG_LONG value);
PUBLIC unsigned long *DLL_ENTRY  ossx__ULong_copy(struct ossxEnv *world,
				    unsigned long value);
PUBLIC unsigned short *DLL_ENTRY ossx__UShort_copy(struct ossxEnv *world,
				    unsigned short value);
PUBLIC void *DLL_ENTRY      ossx__UnbBitStr_copy(struct ossxEnv *world,
				    unsigned char *value, unsigned int length);
PUBLIC void *DLL_ENTRY      ossx__UnbCharString_copy(struct ossxEnv *world,
				    char *value, unsigned int length);
PUBLIC void *DLL_ENTRY      ossx__UnbCharString_copy_nullterm(
				    struct ossxEnv *world, char *value);
PUBLIC void *DLL_ENTRY      ossx__UnbList_copy(struct ossxEnv *world,
				    void *value, unsigned int length,
				    size_t item_sz);
PUBLIC void *DLL_ENTRY      ossx__UnbList_new(struct ossxEnv *world,
				    unsigned int length, size_t item_sz,
				    ossxBoolean do_memset);
PUBLIC void *DLL_ENTRY      ossx__UnivString_copy(struct ossxEnv *world,
				    int *value, unsigned int length);

    /*************************************************************************/
    /*      OTHER FUNCTIONS                                                  */
    /*************************************************************************/

#define OSSX_PLUS_INFINITY   "PLUS_INFINITY"
#define OSSX_MINUS_INFINITY  "MINUS_INFINITY"
#define OSSX_NOT_A_NUMBER    "NOT_A_NUMBER"


typedef unsigned char * (DLL_ENTRY_FPTR *_System OssxSafeMallocp)
					(struct ossxEnv *world, OssxBuf *buf);

PUBLIC void DLL_ENTRY       ossxFreeObjectStack(struct ossxEnv *world);


PUBLIC int DLL_ENTRY        ossxParseEnvironment(void);
PUBLIC void DLL_ENTRY       ossxSetPaddingBits(struct ossxEnv *,
				    unsigned char);

PUBLIC int DLL_ENTRY        ossxSetTestFlags(char *);

#if defined(__vms) && (__INITIAL_POINTER_SIZE + 0) == 64
#pragma pointer_size 32
#endif
PUBLIC int DLL_ENTRY        ossxSetTestFlagsEx(int, char *[]);
#if defined(__vms) && (__INITIAL_POINTER_SIZE + 0) == 64
#pragma pointer_size 64
#endif
extern int DLL_ENTRY        ossxTestConcatenatedEncodings(struct ossxEnv *world,
					    int            globElemnum,
					    OssxBuf        *encoded_message);
extern int DLL_ENTRY        ossxTestEncoding(struct ossxEnv *world,
					    int            globElemnum,
					    OssxBuf        *encodedData);
extern int DLL_ENTRY        ossxTestMultipleEncodings(struct ossxEnv *world,
				    int            globElemnum,
				    OssxBuf        *encoded_messages,
				    int            number_of_encoded_messages);
#if defined(_WINDOWS) || defined(_WIN32) || defined(WIN32) || \
	defined(__WIN32__) || defined(__OS2__) || defined(NETWARE_DLL)
PUBLIC extern int DLL_ENTRY ossxVprintWin(struct ossxEnv *, const char *,
					    va_list ap);
#endif /* _WINDOWS ||_WIN32 || WIN32 || __WIN32__ || __OS2__ || NETWARE_DLL */


/*****************************************************************************/
/*  NON-PUBLIC section: apiTbl DLL definition                                */
/*****************************************************************************/

#if defined(_WINDOWS) || defined(_WIN32) || defined(WIN32) || \
	defined(__WIN32__) || defined(__OS2__) || defined(NETWARE_DLL)
#if defined(__alpha)
#define ossxArg LONG_LONG
#elif defined(WINDOWS_ITANIUM_64BIT)
#define ossxArg void *
#else
#define ossxArg int
#endif /* __alpha */
#endif /* _WINDOWS ||_WIN32 || WIN32 || __WIN32__ || __OS2__ || NETWARE_DLL */

#if defined(_WINDOWS) || defined(_WIN32) || \
	defined(__OS2__) || defined(NETWARE_DLL)

struct _string_data;

typedef struct apiTbl {
    int (DLL_ENTRY_FPTR *_System ossxSetEncodingMethodp)(void *, int);
    int (DLL_ENTRY_FPTR *_System ossxGetEncodingMethodp)(void *);
    int (DLL_ENTRY_FPTR *_System ossxSetRuntimeVersionp)(void *, int);
    int (DLL_ENTRY_FPTR *_System ossxGetRuntimeVersionp)(void *);
    int (DLL_ENTRY_FPTR *_System ossxSetCompatibilityFlagsp)(void *, unsigned long);
    unsigned long (DLL_ENTRY_FPTR *_System ossxGetCompatibilityFlagsp)(void *);
    int (DLL_ENTRY_FPTR *_System encodep)(void *, int, void *, char **,
					long *, void *, unsigned, char *);
    int (DLL_ENTRY_FPTR *_System decodep)(void *, int *, char **, long *,
				void **, long *, void *, unsigned, char *);
    int (DLL_ENTRY_FPTR *_System ossxDispatchEncodep)(void *, int, void *, char **,
					long *, void *, unsigned, char *);
    int (DLL_ENTRY_FPTR *_System ossxDispatchDecodep)(void *, int *, char **, long *,
				void **, long *, void *, unsigned, char *);
    int (DLL_ENTRY_FPTR *_System ossxSetDecodingLengthp)(void *, long);
    long (DLL_ENTRY_FPTR *_System ossxGetDecodingLengthp)(void *);
    int (DLL_ENTRY_FPTR *_System ossxSetEncodingFlagsp)(void *, unsigned long);
    unsigned long (DLL_ENTRY_FPTR *_System ossxGetEncodingFlagsp)(void *);
    int (DLL_ENTRY_FPTR *_System ossxSetFlagsp)(void *, unsigned long);
    unsigned long (DLL_ENTRY_FPTR *_System ossxGetFlagsp)(void *);
    int (DLL_ENTRY_FPTR *_System ossxSetDecodingFlagsp)(void *, unsigned long);
    unsigned long (DLL_ENTRY_FPTR *_System ossxGetDecodingFlagsp)(void *);
    char *(DLL_ENTRY_FPTR *_System ossxGetErrMsgp)(void *world);
    void (DLL_ENTRY_FPTR *_System ossxPrintHexp)(void *, char *, long);
    int (DLL_ENTRY_FPTR *_System ossxEncodep)(void *, int, void *, void *);
    int (DLL_ENTRY_FPTR *_System ossxDecodep)(void *, int *, void *, void **);
    int (DLL_ENTRY_FPTR *_System ossxPrintGlobElemp)(void *, int, void *);
    int (DLL_ENTRY_FPTR *_System ossxFreeGlobElemp)(void *, int, void *);
    void (DLL_ENTRY_FPTR *_System ossxFreeBufp)(void *, void *);
    int  (DLL_ENTRY_FPTR *ossxPrintWinp)(void *, const char *,
				ossxArg, ossxArg, ossxArg, ossxArg, ossxArg,
					ossxArg, ossxArg, ossxArg, ossxArg, ossxArg);
    int  (DLL_ENTRY_FPTR *ossxVprintWinp)(void *, const char *, va_list);
    int  (DLL_ENTRY_FPTR *_System ossxReadLinep)(void *, HWND, FILE *,
						char *, void *, LONG);
    void (DLL_ENTRY_FPTR *_System ossxFreeListp)(void *);
    void (DLL_ENTRY_FPTR *_System ossxSaveTraceInfop)(void *, HWND, char *);
    void (DLL_ENTRY_FPTR *_System ossxtracep)(void *, void *p, size_t);
    int  (DLL_ENTRY_FPTR *_System ossxOpenTraceWindowp)(void *);
    int  (DLL_ENTRY_FPTR *_System ossxOpenTraceFilep)(void *, char *);
    int  (DLL_ENTRY_FPTR *_System ossxCloseTraceFilep)(void *);
    long (DLL_ENTRY_FPTR *_System ossxDetermineEncodingLengthp)(void *,
								int, void *);
    long (DLL_ENTRY_FPTR *_System ossxDetermineBERMessageLengthp)(void *, void *);
    int  (DLL_ENTRY_FPTR *_System ossxCallerIsDecoderp)(void *);
    void *(DLL_ENTRY_FPTR *_System ossxMarkObjp)(void *, int, void *);
    void *(DLL_ENTRY_FPTR *_System ossxUnmarkObjp)(void *, void *);
    void *(DLL_ENTRY_FPTR *_System ossxGetObjp)(void *, void *);
    int  (DLL_ENTRY_FPTR *_System ossxTestObjp)(void *, void *);
    void (DLL_ENTRY_FPTR *_System ossxFreeObjectStackp)(void *);
    void (DLL_ENTRY_FPTR *_System ossxSetTimeoutp)(void *, long);
    int  (DLL_ENTRY_FPTR *_System ossxGetBufferp)(void *, void *);
    int  (DLL_ENTRY_FPTR *_System ossxSetTemporaryBufferp)(void *, void *);
    int  (DLL_ENTRY_FPTR *_System ossxSetFormatterBufferSizep)(void *, unsigned long);
    unsigned long (DLL_ENTRY_FPTR *_System ossxGetFormatterBufferSizep)(void *);
    int  (DLL_ENTRY_FPTR *_System ossxSetBufferp)(void *, void *);
    int  (DLL_ENTRY_FPTR *_System ossxOpenDecoderInputFilep)(void *, char *);
    int  (DLL_ENTRY_FPTR *_System ossxCloseDecoderInputFilep)(void *);
    int  (DLL_ENTRY_FPTR *_System ossxOpenEncoderOutputFilep)(void *, char *);
    int  (DLL_ENTRY_FPTR *_System ossxCloseEncoderOutputFilep)(void *);
    long (DLL_ENTRY_FPTR *_System ossxSetMinFileSizep)(void *, long);
    long (DLL_ENTRY_FPTR *_System ossxGetMinFileSizep)(void *);
    void (DLL_ENTRY_FPTR *_System ossxSetUserMallocFreeReallocp)(void *,
					void *(*)(void *, size_t),
					void  (*)(void *, void *),
					void *(*)(void *, void *, size_t));
    void (DLL_ENTRY_FPTR *_System ossxGetUserMallocFreeReallocp)(void *,
					void *(**)(void *, size_t),
					void  (**)(void *, void *),
					void *(**)(void *, void *, size_t));
    void (DLL_ENTRY_FPTR *_System ossxSetUserPrintp)(void *, FILE *,
			int (DLL_ENTRY_FPTR *)(void *, const char *, ...));
    void (DLL_ENTRY_FPTR *_System ossxGetUserPrintp)(void *, FILE **,
			int (DLL_ENTRY_FPTR **)(void *, const char *, ...));
    void (DLL_ENTRY_FPTR *_System ossxSetUserVprintp)(void *, FILE *,
			int (DLL_ENTRY_FPTR *)(void *, const char *, va_list));
    void (DLL_ENTRY_FPTR *_System ossxGetUserVprintp)(void *, FILE **,
			int (DLL_ENTRY_FPTR **)(void *, const char *, va_list));
    void (DLL_ENTRY_FPTR *_System ossxSetUserFieldCpyCmpp)(void *,
					int (*)(void *, void *, void *),
					int (*)(void *, void *, void *));
    void (DLL_ENTRY_FPTR *_System ossxGetUserFieldCpyCmpp)(void *,
					int (**)(void *, void *, void *),
					int (**)(void *, void *, void *));
    long (DLL_ENTRY_FPTR *_System ossxGetBytesReadByDecoderp)(void *);
    void *(DLL_ENTRY_FPTR *_System ossxGetDefaultValuep)(void *, unsigned int);
    char *(DLL_ENTRY_FPTR *_System ossxGetGlobElemNamep)(void *, unsigned short);
    int (DLL_ENTRY_FPTR *_System ossxGeneralizedTimeToIntsp)(void *, char *,
		unsigned int *, unsigned int *,	unsigned int *,
		unsigned int *, unsigned int *,	unsigned int *,
		unsigned int *, unsigned short *, int *);
    int (DLL_ENTRY_FPTR *_System ossxUTCTimeToIntsp)(void *, char *,
		unsigned int *, unsigned int *,	unsigned int *,
		unsigned int *, unsigned int *,	unsigned int *, int *);
    int (DLL_ENTRY_FPTR *_System ossxIntsToGeneralizedTimep)(void *,
		unsigned int, unsigned int, unsigned int,
		unsigned int, unsigned int, unsigned int,
		unsigned int, unsigned short, int, char *);
    int (DLL_ENTRY_FPTR *_System ossxIntsToUTCTimep)(void *,
		unsigned int, unsigned int, unsigned int,
		unsigned int, unsigned int, unsigned int, int, char *);
    void (DLL_ENTRY_FPTR *_System ossxPrintOctetAsIPAddressp)(void *, char *);
    void (DLL_ENTRY_FPTR *_System ossxPrintOctetAsASCIIp)(void *, char *);
    void (DLL_ENTRY_FPTR *_System ossxFreeScopeStackp)(void *);
    void (DLL_ENTRY_FPTR *_System ossxFreeEncodedTypesListp)(void *, unsigned char );
    int  (DLL_ENTRY_FPTR *_System ossxDetermineNumberOfPadBitsp)(void *);
    int  (DLL_ENTRY_FPTR *_System ossxFindGlobElemNumberOfOpenTypep)(void *, void *);
    void (DLL_ENTRY_FPTR *_System ossxNewScopeInfop)(void *, void *);
    void (DLL_ENTRY_FPTR *_System ossxEndScopeInfop)(void *, void *);
    void (DLL_ENTRY_FPTR *_System ossxNewReferencedp)(void *,
		unsigned short, void *, void *, size_t);
    void *(DLL_ENTRY_FPTR *_System ossxNewReferencingp)(void *, void *,
		void *, size_t);
    void (DLL_ENTRY_FPTR *_System ossxFreeReferencingp)(void *, void *);
    void (DLL_ENTRY_FPTR *_System ossxDecodeRestOfOpenTypep)(void *);
    void (DLL_ENTRY_FPTR *_System ossxStoreErrorInfop)(void *);
    char (DLL_ENTRY_FPTR *_System ossxCmpObjectsp)(unsigned char *,
			unsigned char *, void *, void *, char);
    int (DLL_ENTRY_FPTR *_System ossxIsSetFlagp)(char *, short int);
    void *(DLL_ENTRY_FPTR *_System ossxGetUserFunctionp)(void *, char *,
			short int);
    char *(DLL_ENTRY_FPTR *_System name_ofp)(char *);
    int (DLL_ENTRY_FPTR *ossxGetPrintIndentp)(struct ossxEnv *world);
    void (DLL_ENTRY_FPTR *ossxSetPrintIndentp)(struct ossxEnv *world, int indent_level);
    int (DLL_ENTRY_FPTR *_System ossxGeneralizedTimeToShortsp)(void *, char *,
		unsigned short *, unsigned short *, unsigned short *,
		unsigned short *, unsigned short *, unsigned short *,
		unsigned int   *, unsigned short *, int *);
    int (DLL_ENTRY_FPTR *_System ossxUTCTimeToShortsp)(void *, char *,
		unsigned short *, unsigned short *, unsigned short *,
		unsigned short *, unsigned short *, unsigned short *, int *);
    void (DLL_ENTRY_FPTR *_System ossxSetPaddingBitsp)(void *, unsigned char);
    void (DLL_ENTRY_FPTR *_System ossxSetPresetDecFlagsp)(void *, unsigned long);
    unsigned long (DLL_ENTRY_FPTR *_System ossxGetPresetDecFlagsp)(void *);
    int (DLL_ENTRY_FPTR *_System ossxDecodeRestOfContainingp)(void *);
    int (DLL_ENTRY_FPTR *_System ossxSetXmlStylesheetp)(void *, char *);
    int (DLL_ENTRY_FPTR *_System ossxSetXmlDTDp)(void *, char *, char *, short);
    void (DLL_ENTRY_FPTR *_System ossxMinitp)(void *);
    void *(DLL_ENTRY_FPTR *_System _ossx_dec_getmemp)(void *, long);
    void *(DLL_ENTRY_FPTR *_System _ossx_dec_getfixmemp)(void *, unsigned int);
    void *(DLL_ENTRY_FPTR *_System _ossx_enc_getmemp)(void *);
    void *(DLL_ENTRY_FPTR *_System _ossx_enc_popp)(void *);
    void (DLL_ENTRY_FPTR *_System _ossx_enc_pushp)(void *, void *);
    void (DLL_ENTRY_FPTR *_System _ossx_releaseMemp)(void *, void *);
    void (DLL_ENTRY_FPTR *_System _ossx_freeMemp)(void *, 
	void (*)(void *, void *));
    void (DLL_ENTRY_FPTR *_System _ossx_freeGlobalsp)(void *, ossxBoolean);
    void (DLL_ENTRY_FPTR *_System _ossx_enc_llerrorp) (struct ossxEnv *g,
    	enum _err_index, LONG_LONG);
    void (DLL_ENTRY_FPTR *_System _ossx_freetempMemp)(void *);
    void (DLL_ENTRY_FPTR *_System _ossx_set_outmem_dp)(void *, long,
							long *, char **);
    void (DLL_ENTRY_FPTR *_System _ossx_set_outmem_pp)(void *, long *, char **);
    void (DLL_ENTRY_FPTR *_System _ossx_set_outmem_pbp)(void *, long *, char **, unsigned);
    void (DLL_ENTRY_FPTR *_System _ossx_beginBlockp)(void *, long, char **, long *);
    void (DLL_ENTRY_FPTR *_System _ossx_nextItemp)(void *, long *);
    void (DLL_ENTRY_FPTR *_System _ossx_endBlockp)(void *, char **, long *, unsigned char);
    void (DLL_ENTRY_FPTR *_System _ossx_chk_enump)(void *, long, void *);
    void (DLL_ENTRY_FPTR *_System _ossx_chk_uenump)(void *, unsigned long, void *);
    void (DLL_ENTRY_FPTR *_System _ossx_prt_binp)(void *, char *, unsigned char *, long, char *);
    void (DLL_ENTRY_FPTR *_System _ossx_prt_bitp)(void *, void *, unsigned long);
    void (DLL_ENTRY_FPTR *_System _ossx_prt_charp)(void *, char *, unsigned long);
    void (DLL_ENTRY_FPTR *_System _ossx_prt_crealp)(void *, char *);
    void (DLL_ENTRY_FPTR *_System _ossx_prt_gentimep)(void *, void *);
    void (DLL_ENTRY_FPTR *_System _ossx_prt_hexp)(void *, char *, unsigned char *, long, char *);
    void (DLL_ENTRY_FPTR *_System _ossx_prt_ncharp)(void *, char *);
    void (DLL_ENTRY_FPTR *_System _ossx_prt_octp)(void *, void *, unsigned long);
    void (DLL_ENTRY_FPTR *_System _ossx_prt_opentypep)(void *, void *);
    void (DLL_ENTRY_FPTR *_System _ossx_prt_pbitp)(void *, void *, unsigned long, unsigned long);
    void (DLL_ENTRY_FPTR *_System _ossx_prt_realp)(void *, double);
    void (DLL_ENTRY_FPTR *_System _ossx_prt_utctimep)(void *, void *);
    void (DLL_ENTRY_FPTR *_System _ossx_indentp)(void *, int);
    void (DLL_ENTRY_FPTR *_System _ossx_prt_mbcharp)(void *, unsigned char *, long, unsigned short);
    void (DLL_ENTRY_FPTR *_System _ossx_prt_enump)(void *, ULONG_LONG, struct _string_data const *, int);
    void *(DLL_ENTRY_FPTR *_System _ossx_dec_getmem_internalp)(void *, long);
    void *(DLL_ENTRY_FPTR *_System _ossx_getdispmemp)(void *, long);
    void *(DLL_ENTRY_FPTR *_System _ossx_dec_gettempmemp)(void *, long);
    void (DLL_ENTRY_FPTR *_System _ossx_dec_freetempmemp)(void *, void *);
    char *(DLL_ENTRY_FPTR *_System _ossx_getdisp_binp)(void *, char *, unsigned char *, long, char *);
    char *(DLL_ENTRY_FPTR *_System _ossx_getdisp_bitp)(void *, void *, unsigned long);
    char *(DLL_ENTRY_FPTR *_System _ossx_getdisp_charp)(void *, char *, unsigned long);
    char *(DLL_ENTRY_FPTR *_System _ossx_getdisp_crealp)(void *, char *);
    char *(DLL_ENTRY_FPTR *_System _ossx_getdisp_gentimep)(void *, void *);
    char *(DLL_ENTRY_FPTR *_System _ossx_getdisp_hexp)(void *, char *, unsigned char *, long, char *);
    char *(DLL_ENTRY_FPTR *_System _ossx_getdisp_ncharp)(void *, char *);
    char *(DLL_ENTRY_FPTR *_System _ossx_getdisp_octp)(void *, void *, unsigned long);


    char *(DLL_ENTRY_FPTR *_System _ossx_getdisp_pbitp)(void *, void *, unsigned long, unsigned long);
    char *(DLL_ENTRY_FPTR *_System _ossx_getdisp_realp)(void *, double);
    char *(DLL_ENTRY_FPTR *_System _ossx_getdisp_utctimep)(void *, void *);
    char *(DLL_ENTRY_FPTR *_System _ossx_getdisp_mbcharp)(void *, unsigned char *, long, unsigned short);
    char *(DLL_ENTRY_FPTR *_System _ossx_getdisp_intp)(void *, LONG_LONG);
    char *(DLL_ENTRY_FPTR *_System _ossx_getdisp_uintp)(void *, ULONG_LONG);
    void  (DLL_ENTRY_FPTR *_System _ossx_free_dispp)(void *, void *);
    int   (DLL_ENTRY_FPTR *_System _ossx_init_oset_tablep)(void *, const void * ,
							 unsigned int , const void * , unsigned int, void *);
    char (DLL_ENTRY_FPTR *_System _ossxCmpPrimitiveValuep)(void *, void *, void *,
							long, long, int);
    int   (DLL_ENTRY_FPTR *_System _ossx_cmp_valuep)(void *, int, void *, void *);
    int   (DLL_ENTRY_FPTR *_System _ossx_cmp_membitsp)(unsigned char *, unsigned char *, long);
    int   (DLL_ENTRY_FPTR *_System _ossx_cmp_arrbitsp)(unsigned char *, unsigned char *, long, long);
    int   (DLL_ENTRY_FPTR *_System _ossx_cmp_unbnd_octetp)(void *, void *, short, long);
    int   (DLL_ENTRY_FPTR *_System _ossx_cmp_huge_intp)(void *, void *, short, int);
    int   (DLL_ENTRY_FPTR *_System _ossx_cmp_link_objp)(void *, void *, long);
    int   (DLL_ENTRY_FPTR *_System _ossx_cmp_dlink_objp)(void **, void **, long);
    int   (DLL_ENTRY_FPTR *_System _ossx_cmp_open_typep)(void *, void *, void*);
    void   (DLL_ENTRY_FPTR *_System _ossx_init_xapi_entryp)(void *, const void *);
    int   (DLL_ENTRY_FPTR *_System _ossx_cpy_valuep)(void *, int , void *, void **);
    void **(DLL_ENTRY_FPTR *_System _ossx_cpy_link_objp)(void *, void **, void **, long);
    void **(DLL_ENTRY_FPTR *_System _ossx_cpy_dlink_objp)(void *, void **, void **, long);
    void * (DLL_ENTRY_FPTR *_System _ossx_cpy_unbnd_octetp)(void *, void *, void *, short, long);
    char * (DLL_ENTRY_FPTR *_System _ossx_cpy_char_realp)(void *, char *);
    void (DLL_ENTRY_FPTR *_System _ossx_cpy_open_typep)(void); /* not used */
    void *(DLL_ENTRY_FPTR *_System _ossx_dec_realloctempmemp)(void *, void *, long, long);
    void (DLL_ENTRY_FPTR *_System _ossx_dec_freep)(void *, void *);
    void (DLL_ENTRY_FPTR *_System _ossx_freedispmemp)(void *, void *);
    void * (DLL_ENTRY_FPTR *_System _ossx_cpy_unbnd_octet_iap)(void *, void *, void *, short, long, unsigned int);
    int   (DLL_ENTRY_FPTR *_System _ossx_cmp_unbnd_octet_iap)(void *, void *, short, long, unsigned int);
    int   (DLL_ENTRY_FPTR *_System _ossx_cmp_huge_int_iap)(void *, void *, short, int, unsigned int);
    char (DLL_ENTRY_FPTR *_System _ossx_not_dfltp)(void *, void *, void *, long,
						  long, int);
    ossxBoolean (DLL_ENTRY_FPTR *_System _ossx_not_dflt_iap) (void *, void *, void *, long,
						unsigned int, long, int);
    void (DLL_ENTRY_FPTR *_System _ossxSetOutMemQueuep)(void *, long *, char **, unsigned);
    void (DLL_ENTRY_FPTR *_System _ossxFreeEncMemoryp)(void *);
    void *(DLL_ENTRY_FPTR *_System _ossx_epop_globalp)(void *);
    void (DLL_ENTRY_FPTR *_System _ossx_enc_errorp) (void *, int, long);
    struct ossxEnv *(DLL_ENTRY_FPTR *_System _ossx_push_globalp)      (void *);
    void (DLL_ENTRY_FPTR *_System _ossx_chk_pacp)  (void *, char *, unsigned long, const void *);
    void (DLL_ENTRY_FPTR *_System _ossx_chk_pac2p) (void *, unsigned short *, unsigned long, const void *);
    void (DLL_ENTRY_FPTR *_System _ossx_chk_pac4p) (void *, OSSX_INT32 *, unsigned long, const void *);
    int (DLL_ENTRY_FPTR *_System ossxGetConstructedNestingLimitp)(void *);
    int (DLL_ENTRY_FPTR *_System ossxSetConstructedNestingLimitp)(void *, int);
    int (DLL_ENTRY_FPTR *_System ossxGetElementNestingLimitp)(void *);
    int (DLL_ENTRY_FPTR *_System ossxSetElementNestingLimitp)(void *, int);
    int  api;
    void **(DLL_ENTRY_FPTR *_System _ossx_load_enc_stackp)(void *, OSSX_UINT32 *);
    void (DLL_ENTRY_FPTR *_System _ossx_save_enc_stackp)(void *, OSSX_UINT32);
    void **(DLL_ENTRY_FPTR *_System _ossx_increment_enc_stackp)(void *);
    void **(DLL_ENTRY_FPTR *_System _ossx_decrement_enc_stackp)(void *);
    void (DLL_ENTRY_FPTR *_System _ossx_free_crealp)(void *, char *);
    int (DLL_ENTRY_FPTR *_System ossxBinary2XMLp)(void *, int,
		    				 ossxEncodingMethod, void *,
						 void *);
    int (DLL_ENTRY_FPTR *_System ossxXML2Binaryp)(void *, int,
		    				 ossxEncodingMethod, void *,
						 void *);
    void (DLL_ENTRY_FPTR *_System ossxPrintXMLp)(void *, char *, long,
						ossxBoolean);
    int (DLL_ENTRY_FPTR *_System ossxIntsToDurationp)
	 (void *, ossxBoolean, unsigned int, unsigned int, unsigned int,
	  unsigned int, unsigned int, unsigned int, char *, unsigned int,
	  char **);
    int (DLL_ENTRY_FPTR *_System ossxDurationToIntsp)
	 (void *, char *, ossxBoolean *, unsigned int *, unsigned int *,
	  unsigned int *, unsigned int *, unsigned int *, unsigned int *,
	  char **, unsigned int *);
    int (DLL_ENTRY_FPTR *_System ossxIntsToDateTimep)
	 (void *, int,	unsigned int, unsigned int, unsigned int, unsigned int,
	  unsigned int, char *, unsigned int, int, char **);
    int (DLL_ENTRY_FPTR *_System ossxDateTimeToIntsp)
	 (void *, char *, int *, unsigned int *, unsigned int *,
	  unsigned int *, unsigned int *, unsigned int *, char **,
	  unsigned int *, int *);
    int (DLL_ENTRY_FPTR *_System ossxIntsToTimep)
	 (void *, unsigned int, unsigned int, unsigned int, char *,
	  unsigned int, int, char **);
    int (DLL_ENTRY_FPTR *_System ossxTimeToIntsp)
	 (void *, char *, unsigned int *, unsigned int *, unsigned int *,
	  char **, unsigned int *, int *);
    int (DLL_ENTRY_FPTR *_System ossxIntsToDatep)
	 (void *, int, unsigned int, unsigned int, int, char **);
    int (DLL_ENTRY_FPTR *_System ossxDateToIntsp)
	 (void *, char *, int *, unsigned int *, unsigned int *, int *);
    int (DLL_ENTRY_FPTR *_System ossxIntsToGYearMonthp)
	 (void *, int, unsigned int, int, char **);
    int (DLL_ENTRY_FPTR *_System ossxGYearMonthToIntsp)
	 (void *, char *, int *, unsigned int *, int *);
    int (DLL_ENTRY_FPTR *_System ossxIntsToGYearp)(void *, int, int, char **);
    int (DLL_ENTRY_FPTR *_System ossxGYearToIntsp)
	 (void *, char *, int *, int *);
    int (DLL_ENTRY_FPTR *_System ossxIntsToGMonthDayp)
	 (void *, unsigned int, unsigned int, int, char **);
    int (DLL_ENTRY_FPTR *_System ossxGMonthDayToIntsp)
	 (void *, char *, unsigned int *, unsigned int *, int *);
    int (DLL_ENTRY_FPTR *_System ossxIntsToGDayp)
	 (void *, unsigned int, int, char **);
    int (DLL_ENTRY_FPTR *_System ossxGDayToIntsp)
	 (void *, char *, unsigned int *, int *);
    int (DLL_ENTRY_FPTR *_System ossxIntsToGMonthp)
	 (void *, unsigned int, int, char **);
    int (DLL_ENTRY_FPTR *_System ossxGMonthToIntsp)
	 (void *, char *, unsigned int *, int *);
    ossxBoolean (DLL_ENTRY_FPTR *_System ossx_is_float_special_valuep)(void *, int, int);
    char *(DLL_ENTRY_FPTR *_System ossx_get_float_special_kind_stringp)(int, ossxBoolean);
    ossxBoolean (DLL_ENTRY_FPTR *_System ossx_set_float_special_valuep)(void *, int, int);
    int (DLL_ENTRY_FPTR *_System ossxValidateXMLInstancep)(void *, int, void *);
    int (DLL_ENTRY_FPTR *_System ossxSetNamespacePrefixp)(void *, char *, char *);
    int (DLL_ENTRY_FPTR *_System ossxGetNamespacePrefixp)(void *, char *, char **);
    int (DLL_ENTRY_FPTR *_System ossxGetExtensionAddition)(void *, void *, unsigned int, void *);
    int (DLL_ENTRY_FPTR *_System ossxSetXMLEncodingMethodp)(void *,
							    ossxEncodingMethod);
    int (DLL_ENTRY_FPTR *_System ossxGetXMLEncodingMethodp)(void *);
    int (DLL_ENTRY_FPTR *_System compare_char_realp)(void *, char *, char *);
    int (DLL_ENTRY_FPTR *_System ossxSetCompressDecompressFunctionsp)(void *, void *, void *);
    int (DLL_ENTRY_FPTR *_System ossxGetCompressDecompressFunctionsp)(void *, void *, void *);
    int (DLL_ENTRY_FPTR *_System ossxSetCompressDecompressInfop)(void *, void *);
    int (DLL_ENTRY_FPTR *_System ossxGetCompressDecompressInfop)(void *, void **);
    int (DLL_ENTRY_FPTR *_System ossxSetCompSizeEstimatorp)(void *, void *);
    int (DLL_ENTRY_FPTR *_System ossxGetCompSizeEstimatorp)(void *, void *);
    void (DLL_ENTRY_FPTR *_System _ossx_ex_parse_creal_X693p)(char *, void *);
    void (DLL_ENTRY_FPTR *_System _ossx_ex_compose_creal_X693p)(void *, char *);
    void (DLL_ENTRY_FPTR *_System _ossx_toed_errorp)(void *, int, void *);
    void (DLL_ENTRY_FPTR *_System _ossx_toed_api_errorp)(void *, int, long);
    int (DLL_ENTRY_FPTR *_System ossxSkipPadBytesp)(void *, void *, unsigned char);
    int (DLL_ENTRY_FPTR *_System ossx_get_float_special_value_kindp)(void *, int);
    void (DLL_ENTRY_FPTR *_System _ossx_check_nullterm_timep)(void *, void *, short );
    int (DLL_ENTRY_FPTR *_System ossxSetDebugFlagsp)(void *, unsigned long);
    int (DLL_ENTRY_FPTR *_System ossxGetDebugFlagsp)(void *);
    void (DLL_ENTRY_FPTR *_System _ossx_db_e_prep)(void *, int, void *, unsigned int *, char *, long);
    void (DLL_ENTRY_FPTR *_System _ossx_db_e_postp)(void *, int, char *, long);   
    void (DLL_ENTRY_FPTR *_System _ossx_db_d_prep)(void *, char *, long, unsigned int *);
    void (DLL_ENTRY_FPTR *_System _ossx_db_d_postp)(void *, int, int, void **);
    /* For TOED_LED, this pointer is reserved for possible future use */
    void *(DLL_ENTRY_FPTR *_System _ossx_cpy_dlink_plusp)(void *, void *, void *, long);
    /* This ones are common for all runtimes */
    void *(DLL_ENTRY_FPTR *_System ossxGetMemoryp)(void *, size_t);
    void *(DLL_ENTRY_FPTR *_System ossxGetInitializedMemoryp)(void *, size_t);
    void  (DLL_ENTRY_FPTR *_System ossxFreeMemoryp)(void *, void *);
    void * (DLL_ENTRY_FPTR *_System ossxCreateMemoryHandlep)(void *, size_t);
    int (DLL_ENTRY_FPTR *_System ossxCleanMemoryHandlep)(void *, void *);
    int (DLL_ENTRY_FPTR *_System ossxDeleteMemoryHandlep)(void *, void *);
    int (DLL_ENTRY_FPTR *_System ossxSetActiveMemoryHandlep)(void *, void *);
    void * (DLL_ENTRY_FPTR *_System ossxGetActiveMemoryHandlep)(void *);
    int (DLL_ENTRY_FPTR *_System ossxGetMemoryHandleStatp)(void *, void *, void *, unsigned int);
    char *(DLL_ENTRY_FPTR *_System ossx__Char_copyp)(void *, char);
    unsigned char *(DLL_ENTRY_FPTR *_System ossx__UChar_copyp)(void *, unsigned char);
    short *(DLL_ENTRY_FPTR *_System ossx__Short_copyp)(void *, short);
    unsigned short *(DLL_ENTRY_FPTR *_System ossx__UShort_copyp)(void *, unsigned short);
    int *(DLL_ENTRY_FPTR *_System ossx__Int_copyp)(void *, int);
    unsigned int *(DLL_ENTRY_FPTR *_System ossx__UInt_copyp)(void *, unsigned int);
    long *(DLL_ENTRY_FPTR *_System ossx__Long_copyp)(void *, long);
    unsigned long *(DLL_ENTRY_FPTR *_System ossx__ULong_copyp)(void *, unsigned long);
    LONG_LONG *(DLL_ENTRY_FPTR *_System ossx__LongLong_copyp)(void *, LONG_LONG);
    ULONG_LONG *(DLL_ENTRY_FPTR *_System ossx__ULongLong_copyp)(void *, ULONG_LONG);
    float *(DLL_ENTRY_FPTR *_System ossx__Float_copyp)(void *, float);
    double *(DLL_ENTRY_FPTR *_System ossx__Double_copyp)(void *, double);
    ossxBoolean *(DLL_ENTRY_FPTR *_System ossx__Bool_copyp)(void *, ossxBoolean);
    void *(DLL_ENTRY_FPTR *_System ossx__Ptr_copyp)(void *, void *);
    char *(DLL_ENTRY_FPTR *_System ossx__CharStr_newp)(void *, unsigned int);
    char *(DLL_ENTRY_FPTR *_System ossx__CharStr_copyp)(void *, char *);
    void *(DLL_ENTRY_FPTR *_System ossx__BmpString_copyp)(void *, unsigned short *, unsigned int);
    void *(DLL_ENTRY_FPTR *_System ossx__UnivString_copyp)(void *, int *, unsigned int);
    void *(DLL_ENTRY_FPTR *_System ossx__UnbCharString_copyp)(void *, char *, unsigned int);
    void *(DLL_ENTRY_FPTR *_System ossx__UnbCharString_copy_nulltermp)(void *, char *);
    void *(DLL_ENTRY_FPTR *_System ossx__UnbBitStr_copyp)(void *, unsigned char *, unsigned int);
    void *(DLL_ENTRY_FPTR *_System ossx__UnbList_newp)(void *, unsigned int, size_t, ossxBoolean);
    void *(DLL_ENTRY_FPTR *_System ossx__UnbList_copyp)(void *, void *, unsigned int, size_t);
    unsigned char (DLL_ENTRY_FPTR *_System charIsPermittedp)(const OSSX_UINT32 *pat, OSSX_UINT32 character);
    char *(DLL_ENTRY_FPTR *_System ossxDescribeReturnCodep)(struct ossxEnv *world, int rc);
    int (DLL_ENTRY_FPTR *_System ossxSetEncoderPrefixModep)(
	    struct ossxEnv *world, int in_mode);
    int (DLL_ENTRY_FPTR *_System ossxGetEncoderPrefixModep)(
	    struct ossxEnv *world, void *out_mode);
    int (DLL_ENTRY_FPTR *_System ossxGetDecoderPrefixModep)(
	    struct ossxEnv *world, ossxBoolean *in_mode);
    int (DLL_ENTRY_FPTR *_System ossxSetDecoderPrefixModep)(
	    struct ossxEnv *world, ossxBoolean in_mode);
    int (DLL_ENTRY_FPTR *_System ossxSkipPrefixBytesp)(
	    struct ossxEnv *world, OssxBuf *input, OssxBuf *out_prefix, int *globElemnum);
    int (DLL_ENTRY_FPTR *_System ossxCompressp)(struct ossxEnv *world,
	    OssxBuf *input, OssxBuf *output, long prefix_len);
    int (DLL_ENTRY_FPTR *_System ossxUnCompressp)(struct ossxEnv *world,
	    OssxBuf *input, OssxBuf *output, ossxBoolean prefix);
    int (DLL_ENTRY_FPTR *_System ossxIdentifyGlobElemByXMLNamep)(struct ossxEnv *world,
				    unsigned char *uri, unsigned char *name, int *globElem);
} ApiTbl;
#endif /* _WINDOWS || _WIN32 || __OS2__ || NETWARE_DLL */

    /*************************************************************************/
    /*      NON-PUBLIC section: helper macros functions via DLL apiTbl       */
    /*************************************************************************/
#ifdef DLL_LINKAGE 
#ifndef IN_HLPFUNC_C
#define ossx__Char_copy(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__Char_copyp)(world, value) : NULL)
#define ossx__UChar_copy(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__UChar_copyp)(world, value) : NULL)
#define ossx__Short_copy(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__Short_copyp)(world, value) : NULL)
#define ossx__UShort_copy(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__UShort_copyp) \
			(world, value) : NULL)
#define ossx__Int_copy(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__Int_copyp)(world, value) : NULL)
#define ossx__UInt_copy(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__UInt_copyp)(world, value) : NULL)
#define ossx__Long_copy(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__Long_copyp)(world, value) : NULL)
#define ossx__ULong_copy(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__ULong_copyp)(world, value) : NULL)
#define ossx__LongLong_copy(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__LongLong_copyp) \
			(world, value) : NULL)
#define ossx__ULongLong_copy(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__ULongLong_copyp) \
			(world, value) : NULL)
#define ossx__Float_copy(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__Float_copyp)(world, value) : NULL)
#define ossx__Double_copy(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__Double_copyp) \
			(world, value) : NULL)
#define ossx__Bool_copy(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__Bool_copyp)(world, value) : NULL)
#define ossx__Ptr_copy(world, ptr) \
	((world) ? (*(world)->ft.apiTbl->ossx__Ptr_copyp)(world, ptr) : NULL)
#define ossx__CharStr_new(world, length) \
	((world) ? (*(world)->ft.apiTbl->ossx__CharStr_newp) \
			(world, length) : NULL)
#define ossx__CharStr_copy(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__CharStr_copyp) \
			(world, value) : NULL)
#define ossx__BmpString_copy(world, value, length) \
	((world) ? (*(world)->ft.apiTbl->ossx__BmpString_copyp) \
			(world, value, length) : NULL)
#define ossx__UnivString_copy(world, value, length) \
	((world) ? (*(world)->ft.apiTbl->ossx__UnivString_copyp) \
			(world, value, length) : NULL)
#define ossx__UnbCharString_copy(world, value, length) \
	((world) ? (*(world)->ft.apiTbl->ossx__UnbCharString_copyp) \
			(world, value, length) : NULL)
#define ossx__UnbCharString_copy_nullterm(world, value) \
	((world) ? (*(world)->ft.apiTbl->ossx__UnbCharString_copy_nulltermp) \
			(world, value) : NULL)
#define ossx__UnbBitStr_copy(world, value, length) \
	((world) ? (*(world)->ft.apiTbl->ossx__UnbBitStr_copyp) \
			(world, value, length) : NULL)
#define ossx__UnbList_new(world, length, item_sz, do_memset) \
	((world) ? (*(world)->ft.apiTbl->ossx__UnbList_newp) \
			(world, length, item_sz, do_memset) : NULL)
#define ossx__UnbList_copy(world, value, length, item_sz) \
	((world) ? (*(world)->ft.apiTbl->ossx__UnbList_copyp) \
			(world, value, length, item_sz) : NULL)
#endif /* !IN_HLPFUNC_C */
#endif /* DLL_LINKAGE */




#if !defined(OSSXSD_H)
/*****************************************************************************/
/*  PUBLIC section: C SAX (Simple API for XML) interface definitions         */
/*****************************************************************************/
/* SAX flags */

#define OSSX_SAX_NO_NAMESPACES 1
#define OSSX_SAX_NULLTERM_DATA 2
/* Error severity enumeration passed to the error() callbacks */

typedef enum { OssxWarning, OssxError, OssxFatal } OssxErrSeverity;

/* SAX structures used by the callback functions */

typedef struct {
    unsigned char *uri;
    unsigned char *localname;
    unsigned char *qname;
} OssxXMLName;

typedef struct _OssxXMLAttributes {
    OssxXMLName name;
    unsigned char *value;
    unsigned int length;
    struct _OssxXMLAttributes *next;
} OssxXMLAttributes;

typedef enum { OssxStAbsent, OssxStYes, OssxStNo } OssxStandalone;

/* SAX event table - unused events may be left NULL */

typedef struct {
    unsigned int version;
    int (*error)(void *user_data, int errorcode, const unsigned char *msg,
	    OssxErrSeverity severity);
/* Document */
    int (*startDocument)(void *user_data);
    int (*endDocument)(void *user_data);
/* XML declaration */
    int (*xmlDecl)(void *data, const unsigned char *version, 
			const unsigned char *encoding,
			OssxStandalone standalone);
/* DTD */
    int (*startDoctypeDecl)(void *data, const unsigned char *name,
			const unsigned char *sysid,
			const unsigned char *pubid, int has_internal_subset);
    int (*endDoctypeDecl)(void *data, const unsigned char *name);
    int (*unparsedEntityDecl)(void *data, const unsigned char *entityName, 
			const unsigned char *sysid, const unsigned char *pubid,
			const unsigned char *notationName);
    int (*notationDecl)(void *data, const unsigned char *notationName, 
			const unsigned char *sysid, const unsigned char *pubid);
/* Content */
    int (*startElement)(void *user_data, const OssxXMLName *name,
			const OssxXMLAttributes *attr);
    int (*endElement)(void *user_data, const OssxXMLName *name);
    int (*characters)(void *user_data, const unsigned char *chars, 
			unsigned int length);
    int (*startPrefixMapping)(void *user_data, const unsigned char *prefix,
			const unsigned char *uri);
    int (*endPrefixMapping)(void *user_data, const unsigned char *prefix);
    int (*processingInstruction)(void *user_data, const unsigned char *target,
			const unsigned char *chars, unsigned int length);
    int (*comment)(void *user_data, const unsigned char *chars,
			unsigned int length);
    int (*startCDATA)(void *user_data);
    int (*endCDATA)(void *user_data);
    int (*startEntity)(void *user_data, const unsigned char *name);
    int (*endEntity)(void *user_data, const unsigned char *name);
    int (*unexpEntityRef)(void *data, const unsigned char *entityName, 
			const unsigned char *sysid, const unsigned char *pubid);
} OssxSAXEventTable;

PUBLIC int DLL_ENTRY ossxSAXParseXML(OssxEnv *in_ctx, OssxBuf *in_msg, 
			void *in_data, OssxSAXEventTable *in_handler);
/*****************************************************************************/
/*  PUBLIC section: Fast Infoset interface definitions                       */
/*****************************************************************************/

typedef struct OssxFITable {
    int version;   /* 0 for now */
    int flags;		
#define OSSX_FI_TBL_STANDALONE 0x0001
#if defined(__WATCOMC__) && defined(__DOS__)
    void (*local_init)(OssxEnv *);
#else
    void (DLL_ENTRY_FPTR *_System local_init)(OssxEnv *);
#endif /* __WATCOMC__ && __DOS__ */
    void *reserved;
} OssxFITable;

extern const OssxFITable OSSX_FI_CTL_TBL;

/* =============== FI General-purpose structures and functions ============= */

/*
 * Use the OSSX_FI_CTL_TBL structure generated by ossxfic utility
 * as the second argument of ossxInitFastInfoset() function.
 */
PUBLIC int DLL_ENTRY ossxInitFastInfoset(OssxEnv *in_ctx,
			const OssxFITable *in_ctl_tbl);
PUBLIC int DLL_ENTRY ossxTermFastInfoset(OssxEnv *in_ctx);

/* Fast Infoset runtime flags (flags 0x01-0x80 are reserved) */
#define OSSX_FI_RELAXED				0x00000100
#define OSSX_FI_STRICT				0x00000200
#define OSSX_FI_TRAPPING				0x00000400
#define OSSX_FI_NO_NAMESPACES			0x00000800
#define OSSX_FI_NO_DECLARATION			0x00001000
#define OSSX_FI_DEBUG_ERRORS                  	0x00002000
#define OSSX_FI_CACHE_TEMPLATE_ENCODING		0x00004000
#define OSSX_FI_UPDATE_INPUT_ADDR   	 	0x00008000
#define OSSX_FI_FORMAT_XML			0x00010000
#define OSSX_FI_ADD_STRINGS_TO_VOCABULARY	0x00020000
#define OSSX_FI_COMPRESS_OUTPUT			0x00040000
#define OSSX_FI_DECOMPRESS_INPUT   		0x00080000
#define OSSX_FI_TRACING				0x00100000
#define OSSX_FI_ENCODER_STATE_OFF		0x00200000
#define OSSX_FI_ENCODE_STR_WITHOUT_LOOKUP	0x00400000

PUBLIC int DLL_ENTRY ossxFISetFlags(OssxEnv *in_ctx, OSSX_UINT32 in_flags);
PUBLIC OSSX_UINT32 DLL_ENTRY ossxFIGetFlags(OssxEnv *in_ctx);

/* ===================== Fast Infoset Vocabulary API ======================= */

typedef struct OssxVocabulary OssxVocabulary;

typedef enum OssxVocabularyKind {
    OSSX_vkUniversal, OSSX_vkEncode, OSSX_vkDecode
} OssxVocabularyKind;

PUBLIC int DLL_ENTRY ossxFIVocabularyNew(OssxEnv *in_ctx,
			OssxVocabularyKind in_kind, OssxVocabulary **out_voc);
PUBLIC int DLL_ENTRY ossxFIGetEncoderVocabulary(OssxEnv *in_ctx, 
			OssxVocabularyKind in_kind, OssxVocabulary **out_voc);
PUBLIC int DLL_ENTRY ossxFIGetDecoderVocabulary(OssxEnv *in_ctx, 
			OssxVocabularyKind in_kind, OssxVocabulary **out_voc);
PUBLIC int DLL_ENTRY ossxFISetVocabulary(OssxEnv *in_ctx, char *in_uri,
			OssxVocabulary *in_voc);
PUBLIC int DLL_ENTRY ossxFIGetVocabulary(OssxEnv *in_ctx, char **out_uri,
			OssxVocabulary **out_voc);
PUBLIC int DLL_ENTRY ossxFIVocabularyCopy(OssxEnv *in_ctx, 
			OssxVocabulary *in_voc, OssxVocabulary **out_voc);
PUBLIC int DLL_ENTRY ossxFIVocabularyFinalize(OssxEnv *in_ctx, 
			OssxVocabulary *in_voc);
PUBLIC int DLL_ENTRY ossxFIVocabularyDelete(OssxEnv *in_ctx, 
			OssxVocabulary *in_voc);
PUBLIC int DLL_ENTRY ossxFIVocabularyMerge(OssxEnv *in_ctx, 
			OssxVocabulary *in_to, 
			OssxVocabulary *in_from);
PUBLIC int DLL_ENTRY ossxFIVocabularyAddString(OssxEnv *in_ctx, 
			OssxVocabulary *in_voc, 
			char *in_str, unsigned int in_length, 
			OSSX_UINT32 in_category, OSSX_UINT32 *out_idx);
PUBLIC int DLL_ENTRY ossxXML2Vocabulary(OssxEnv *in_ctx,
	    		OssxVocabularyKind in_kind, OssxBuf *in_xml,
			OSSX_UINT32 in_category_mask, OssxVocabulary **out_voc);
/*
 * Categories for ossxFIVocabularyAddString() and
 *                ossxFIInitVocAddString()
 */
#define OSSX_VOC_STR_PREFIX			0x00000001
#define OSSX_VOC_STR_NAMESPACE_NAME		0x00000002
#define OSSX_VOC_STR_LOCAL_NAME			0x00000004
#define OSSX_VOC_STR_OTHER_NCNAME		0x00000008
#define OSSX_VOC_STR_OTHER_URI			0x00000010
   
/*
 * Categories for ossxFIVocabularyAddString() and
 *                ossxFIInitVocAddEncodedString()
 */
#define OSSX_VOC_STR_ATTRVALUE			0x00000020
#define OSSX_VOC_STR_CONTENT_CHARACTER_CHUNK	0x00000040
#define OSSX_VOC_STR_OTHERSTR			0x00000080

PUBLIC int DLL_ENTRY ossxFIVocabularyAddName(OssxEnv *in_ctx, 
			OssxVocabulary *in_voc, char *in_prefix, char *in_uri,
			char *in_local, OSSX_UINT32 in_category, OSSX_UINT32 *out_idx);

/* Categories for ossxFIVocabularyAddName() */
#define OSSX_VOC_NAME_ELEMENT			0x00000100
#define OSSX_VOC_NAME_ATTRIBUTE			0x00000200

/* Enumeration of all categories for ossxXML2Vocabulary() and
 *                                   ossxXML2DocumentTemplate()
 */
#define OSSX_VOC_ALL				0xFFFFFFFF

PUBLIC int DLL_ENTRY ossxFIVocabularyAddNameByIdx(OssxEnv *in_ctx, 
			OssxVocabulary *in_voc,
			char *in_prefix, OSSX_UINT32 *inout_prefix_idx, 
			char *in_uri, OSSX_UINT32 *inout_uri_idx,
			char *in_local, OSSX_UINT32 *inout_local_idx,
			OSSX_UINT32 in_category, OSSX_UINT32 *out_idx);
PUBLIC int DLL_ENTRY ossxFIVocabularyAddAlphabet(OssxEnv *in_ctx, 
			OssxVocabulary *in_voc, char *in_str,
			OSSX_UINT32 *out_idx);

/* Encoding algorithm function pointer */
typedef int (*OssxEAFcn)(OssxEnv *in_ctx, OssxBuf *in_src, OssxBuf *out_dst);

PUBLIC int DLL_ENTRY ossxFIVocabularyAddAlgorithm(OssxEnv *in_ctx, 
			OssxVocabulary *in_voc,
			OssxEAFcn in_eaEnc, OssxEAFcn in_eaDec,
			OSSX_UINT32 *out_idx);

/* ======================== Document Template API ========================== */

typedef struct OssxDocumentTemplate OssxDocumentTemplate;

PUBLIC int DLL_ENTRY ossxFIGetEncoderDocumentTemplate(OssxEnv *in_ctx, 
			OssxDocumentTemplate **out_template);
PUBLIC int DLL_ENTRY ossxFIGetDecoderDocumentTemplate(OssxEnv *in_ctx, 
			OssxDocumentTemplate **out_template);
PUBLIC int DLL_ENTRY ossxFIGetDocumentTemplateProperties(OssxEnv *in_ctx,
			OssxDocumentTemplate *in_dt, char **out_ext_voc_uri, 
			OssxVocabulary **out_ext_voc_ref);
PUBLIC int DLL_ENTRY ossxFISetDocumentTemplate(OssxEnv *in_ctx,
			OssxDocumentTemplate *in_template);
PUBLIC int DLL_ENTRY ossxFIGetDocumentTemplate (OssxEnv *in_ctx,
			OssxDocumentTemplate **out_template);
PUBLIC int DLL_ENTRY ossxFIDocumentTemplateDelete(OssxEnv *in_ctx, 
			OssxDocumentTemplate *in_dt, 
			ossxBoolean in_free_vocabulary);
PUBLIC int DLL_ENTRY ossxFIDocumentTemplateCopy(OssxEnv *in_ctx, 
			OssxDocumentTemplate *in_dt,
			ossxBoolean in_copy_vocabulary,
			OssxDocumentTemplate **out_dt);
PUBLIC int DLL_ENTRY ossxXML2DocumentTemplate(OssxEnv *in_ctx,
	    		OssxBuf *in_xml, OSSX_UINT32 in_category_mask,
			OssxDocumentTemplate **out_template);
						
/* =================== Fast Infoset Encoder-side functions ================= */

/* 
 * The encoder is represented by series of functions adding pieces of encoded
 * data to the output memory. User should install the long jump buffer for
 * error handling by calling ossxFISetJmpBuf(), start the new FI document by
 * ossxFIStartDocument, add XML components and finally call ossxFIEndDocument().
 */

/*
 * Utility functions
 */
PUBLIC OssxErrSeverity DLL_ENTRY ossxFIGetLastErrorSeverity(OssxEnv *in_ctx);

PUBLIC int DLL_ENTRY ossxFISetJmpBuf(OssxEnv *in_ctx, jmp_buf *in_buf);
PUBLIC int DLL_ENTRY ossxFIGetJmpBuf(OssxEnv *in_ctx, jmp_buf **out_buf);

/*
 * The encoder callback is repeatably called by the encoder whenever a new
 * portion of encoded data of at least in_maxbuf size is ready or the encoder
 * is about to dump data to the file or socket. It may be used for analyzing
 * the encoding in real time.
 */
typedef void (*OssxFIEncoderCallback)(OssxEnv *, OssxBuf *);

PUBLIC int DLL_ENTRY ossxFISetEncoderCallback(OssxEnv *in_ctx, 
			OssxFIEncoderCallback in_callback, int in_maxbuf);
/*
 * Calling ossxFIError when encoding the document causes the long jump in
 * accordance with the user provided jump buffer.
 */
PUBLIC int DLL_ENTRY ossxFIError(OssxEnv *in_ctx, int in_errorcode, char *in_msg);

/*
 * Core Fast Infoset encoder functions
 */
PUBLIC int DLL_ENTRY ossxFIStartDocument(OssxEnv *in_ctx, OssxBuf *out_enc);
PUBLIC int DLL_ENTRY ossxFIEndDocument(OssxEnv *in_ctx);

/*
 * The below functions with signatures starting with ossxFIInitVoc...()
 * populate the 'initial-vocabulary' component of a document being created.
 */
PUBLIC int DLL_ENTRY ossxFIInitVocAddString(OssxEnv *in_ctx, 
			char *in_str, OSSX_UINT32 in_category, OSSX_UINT32 *out_index);
PUBLIC int DLL_ENTRY ossxFIInitVocAddEncodedString(OssxEnv *in_ctx, 
			char *in_str, unsigned int in_length,
			OSSX_UINT32 in_category, OSSX_UINT32 in_format, 
			OSSX_UINT32 *out_index);

/*
 * Encoding formats (covering all known values of the "encoding-format"
 * CHOICE type). It is also possible to specify custom encoding format
 * identifiers returned by functions like ossxFIVocabularyAddAlphabet().
 */
#define OSSX_ALG(x)			(x)
#define OSSX_ALPH(x)			((x) + 256)
#define OSSX_ENC(x)			((x) + 512)

#define OSSX_ALG_HEXADECIMAL		OSSX_ALG(1)
#define OSSX_ALG_BASE64			OSSX_ALG(2)
#define OSSX_ALG_SHORT			OSSX_ALG(3)
#define OSSX_ALG_INT			OSSX_ALG(4)
#define OSSX_ALG_LONG			OSSX_ALG(5)
#define OSSX_ALG_BOOLEAN   		OSSX_ALG(6)
#define OSSX_ALG_FLOAT			OSSX_ALG(7)
#define OSSX_ALG_DOUBLE			OSSX_ALG(8)
#define OSSX_ALG_UUID			OSSX_ALG(9)
#define OSSX_ALG_CDATA			OSSX_ALG(10)

#define OSSX_ALPH_NUMERIC		OSSX_ALPH(1)
#define OSSX_ALPH_DATETIME		OSSX_ALPH(2)

#define OSSX_ENC_UTF8			OSSX_ENC(1)
#define OSSX_ENC_UTF16			OSSX_ENC(2)

PUBLIC int DLL_ENTRY ossxFIInitVocAddName(OssxEnv *in_ctx, 
			char *in_prefix, char *in_uri, char *in_local, 
			OSSX_UINT32 in_category, OSSX_UINT32 *out_index);
PUBLIC int DLL_ENTRY ossxFIInitVocAddNameByIdx(OssxEnv *in_ctx, 
			char *in_prefix, OSSX_UINT32 *inout_prefix_idx,
			char *in_uri, OSSX_UINT32 *inout_uri_idx,
			char *in_local, OSSX_UINT32 *inout_local_idx,
			OSSX_UINT32 in_category, OSSX_UINT32 *out_idx);
PUBLIC int DLL_ENTRY ossxFIInitVocAddAlphabet(OssxEnv *in_ctx, 
			char *in_str, OSSX_UINT32 *out_index);
PUBLIC int DLL_ENTRY ossxFIInitVocAddAlgorithm(OssxEnv *in_ctx, 
			OssxEAFcn in_eaEnc, OssxEAFcn in_eaDec,
			char *in_uri, OSSX_UINT32 *out_index);

/*
 * Core Fast Infoset encoder functions - continuation
 */
PUBLIC int DLL_ENTRY ossxFIXMLDecl(OssxEnv *in_ctx,
			char *in_version, ossxBoolean in_add_version_to_table,
			char *in_encoding, OssxStandalone in_standalone);
PUBLIC int DLL_ENTRY ossxFIStartDoctypeDecl(OssxEnv *in_ctx, char *in_sysid,
			char *in_pubid);
PUBLIC int DLL_ENTRY ossxFINotationDecl(OssxEnv *in_ctx, char *in_name,
			char *in_sysid, char *in_pubid);
PUBLIC int DLL_ENTRY ossxFIUnparsedEntityDecl(OssxEnv *in_ctx, char *in_name,
			char *in_sysid, char *in_pubid,
			char *in_notationName);
PUBLIC int DLL_ENTRY ossxFIEndDoctypeDecl(OssxEnv *in_ctx);

PUBLIC int DLL_ENTRY ossxFIStartPrefixMapping(OssxEnv *in_ctx, char *in_prefix, 
			char *in_uri);
PUBLIC int DLL_ENTRY ossxFIStartElement(OssxEnv *in_ctx, char *in_uri, 
			char *in_local);
PUBLIC int DLL_ENTRY ossxFIEndElement(OssxEnv *in_ctx, char *in_uri, 
			char *in_local);
PUBLIC int DLL_ENTRY ossxFIAddAttribute(OssxEnv *in_ctx, char *in_uri,
			char *in_local, char *in_value, 
			unsigned int in_value_length,
			ossxBoolean in_add, OSSX_UINT32 in_format);
PUBLIC int DLL_ENTRY ossxFICharacters(OssxEnv *in_ctx, 
			char *in_chars, unsigned int in_ch_length,
			ossxBoolean in_ch_add, OSSX_UINT32 in_ch_format);
PUBLIC int DLL_ENTRY ossxFIProcessingInstruction(OssxEnv *in_ctx, char *in_target, 
			char *in_chars, unsigned int in_ch_length,
			ossxBoolean in_ch_add, OSSX_UINT32 in_ch_format);
PUBLIC int DLL_ENTRY ossxFIComment(OssxEnv *in_ctx, 
			char *in_chars, unsigned int in_ch_length,
			ossxBoolean in_ch_add, OSSX_UINT32 in_ch_format);
PUBLIC int DLL_ENTRY ossxFIUnexpandedEntityRef(OssxEnv *in_ctx, char *in_name, 
			char *in_sysid, char *in_pubid);

/*
 * Fast Infoset encoder optimized functions similar to the previous ones
 */

PUBLIC int DLL_ENTRY ossxFIStartPrefixMappingByIdx(OssxEnv *in_ctx,
			char *in_prefix, OSSX_UINT32 *inout_prefix_idx,
			char *in_uri, OSSX_UINT32 *inout_uri_idx);

PUBLIC int DLL_ENTRY ossxFIStartElementByIdx(OssxEnv *in_ctx,
			char *in_prefix, OSSX_UINT32 *inout_prefix_idx,
			char *in_uri, OSSX_UINT32 *inout_uri_idx,
			char *in_local, OSSX_UINT32 *inout_local_idx,
			OSSX_UINT32 *out_name_idx);

PUBLIC int DLL_ENTRY ossxFIStartElementByNameIdx(OssxEnv *in_ctx,
			OSSX_UINT32 in_name_idx);

PUBLIC int DLL_ENTRY ossxFIEndElementByNameIdx(OssxEnv *in_ctx,
			OSSX_UINT32 in_name_idx);

PUBLIC int DLL_ENTRY ossxFIAddAttributeByIdx(OssxEnv *in_ctx,
			char *in_prefix, OSSX_UINT32 *inout_prefix_idx,
			char *in_uri, OSSX_UINT32 *inout_uri_idx,
			char *in_local, OSSX_UINT32 *inout_local_idx, 
			OSSX_UINT32 *out_name_idx,
			char *in_value, unsigned int in_value_length,
			ossxBoolean in_add, OSSX_UINT32 in_format);

PUBLIC int DLL_ENTRY ossxFIAddAttributeByNameIdx(OssxEnv *in_ctx,
			OSSX_UINT32 in_name_idx,
			char *in_value, unsigned int in_value_length,
			ossxBoolean in_add, OSSX_UINT32 in_format);

/* ================= Fast Infoset Decoder-side functions =================== */

/* 
 * The decoder is a single function working as SAX parser. In contrast to XML
 * SAX parsers, the Fast Infoset decoding works with the binary optimized
 * Fast Infoset encoding, not with the textual XML data.
 */

/*
 * Utility API
 */

/* Vocabulary resolver function pointer */
typedef int (*OssxVocabularyResolver)(OssxEnv *in_ctx, char *in_uri,
			OssxVocabulary **out_voc);

/* Encoding algorithm resolver function pointer */
typedef int (*OssxEAResolver)(OssxEnv *in_ctx, char *in_uri,
			OssxEAFcn *out_eaEnc, OssxEAFcn *out_eaDec);

/*
 * The below interface registers the user-provided resolvers for vocabulary
 * and encoding algorithm references that may be carried by the encoded Fast
 * Infoset document. It is called by the FI decoder in presence of such
 * references.
 */
PUBLIC int DLL_ENTRY ossxFISetResolvers(OssxEnv *in_ctx, 
			OssxVocabularyResolver in_extVocRes,
			OssxEAResolver in_eaRes);
PUBLIC int DLL_ENTRY ossxFIGetResolvers(OssxEnv *in_ctx, 
			OssxVocabularyResolver *out_extVocRes,
			OssxEAResolver *out_eaRes);

/*
 * Core Fast Infoset Decoder API
 */
PUBLIC int DLL_ENTRY ossxDecodeFastInfoset(OssxEnv *in_ctx, 
			OssxBuf *in_msg, void *in_data,
			OssxSAXEventTable *in_handler);

/* ======================== Fast Infoset to XML converter ================== */

/*
 * Conversion from Fast Infoset to XML is performed by calling the
 * Fast Infoset decoder with the specially constructed event function
 * table. The callback functions create XML output and sent it to the
 * out_buf which may be a marked object such as a file or socket.
 */
PUBLIC int DLL_ENTRY ossxFastInfoset2XML(OssxEnv *in_ctx, OssxBuf *in_buf, 
			OssxBuf *out_buf);

/* ======================= XML to Fast Infoset converters ================== */

/*
 * Conversion from XML to Fast Infoset is performed by calling the
 * built-in SAX XML parser with the specially constructed event function
 * table. The callback functions create Fast Infoset document by calling
 * the FI encoder API functions and sent it to the out_buf which may be a
 * marked object such as a file or socket.
 *
 * Please refer to the Expat sample program to see the example of converting
 * XML to Fast Infoset using the third party XML SAX parser.
 */
PUBLIC int DLL_ENTRY ossxXML2FastInfoset(OssxEnv *in_ctx, 
			OssxBuf *in_buf, OssxBuf *out_buf);
/*****************************************************************************/
#endif /* OSSXSD_H */

/*****************************************************************************/
/*  NON-PUBLIC section: data alignment section - revert to user-defined data */
/*  alignment                                                                */
/*****************************************************************************/

#ifdef __cplusplus
}
#endif

#if defined(macintosh) && defined(__CFM68K__)
#pragma import reset
#endif

#if defined(_MSC_VER) && (defined(_WIN32) || defined(WIN32) \
			|| defined(WINCE) || defined(_WIN64))
#pragma pack(pop, ossxPacking)
#elif defined(_MSC_VER) && (defined(_WINDOWS) || defined(_MSDOS))
#pragma pack()
#elif defined(__BORLANDC__) && (defined(__WIN32__) || defined(__MSDOS__))
#pragma option -a.
#elif defined(__IBMC__) && (defined(__WIN32__) || defined(__OS2__))
#pragma pack()
#elif defined(__WATCOMC__) && (defined(__NT__) || defined(__WINDOWS__) \
			|| defined(__DOS__))
#pragma pack(pop)
#endif /* _MSC_VER && _WIN32 */

/*****************************************************************************/
/*  PUBLIC section: type definition used in osak memory manager              */
/*****************************************************************************/
#ifndef _OSAK_BUFFER_
#define _OSAK_BUFFER_

typedef struct osak_buffer {
    struct osak_buffer *next;          /* next element in list */
    unsigned char      *buffer_ptr;    /* start of actual buffer */
    unsigned long int   buffer_length; /* size of actual buffer */
    unsigned char      *data_ptr;      /* start of user data */
    unsigned long int   data_length;   /* length of user data */
    unsigned long int   reserved [4];
} osak_buffer;

#endif /* !_OSAK_BUFFER_ */

#define OSSXSD_H
#endif /* !OSSXSD_H ... */

