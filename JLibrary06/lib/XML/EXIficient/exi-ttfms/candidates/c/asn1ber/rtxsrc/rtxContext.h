/*
 * Copyright (c) 2003-2006 Objective Systems, Inc.
 *
 * This software is furnished under a license and may be used and copied
 * only in accordance with the terms of such license and with the
 * inclusion of the above copyright notice. This software or any other
 * copies thereof may not be provided or otherwise made available to any
 * other person. No title to and ownership of the software is hereby
 * transferred.
 *
 * The information in this software is subject to change without notice
 * and should not be construed as a commitment by Objective Systems, Inc.
 *
 * PROPRIETARY NOTICE
 *
 * This software is an unpublished work subject to a confidentiality agreement
 * and is protected by copyright and trade secret law.  Unauthorized copying,
 * redistribution or other use of this work is prohibited.
 *
 * The above notice of copyright on this source code product does not indicate
 * any actual or intended publication of such source code.
 *
 *****************************************************************************/
/** 
 * @file rtxContext.h
 * Common run-time context definitions.
 */
#ifndef _RTXCONTEXT_H_
#define _RTXCONTEXT_H_

#include "rtxsrc/rtxDList.h"

#define OSRTENCBUFSIZ 16*1024    /* dynamic encode buffer extent size     */

/**
 * @addtogroup rtCtxt
 * @{
 */
/* run-time error info structures */

#define OSRTERRSTKSIZ	8	/* error stack size			*/
#define OSRTMAXERRPRM	5	/* maximum error parameters		*/

/**
 * @struct OSRTErrLocn rtContext.h
 * Run-time error location structure
 *
 * This structure is a container structure that holds information on 
 * the location within a C source file where a run-time error occured.
 */
typedef struct {
   const OSUTF8CHAR* module;
   OSINT32	lineno;
} OSRTErrLocn;

/**
 * @struct OSRTErrInfo rtContext.h
 * Run-time error information structure
 *
 * This structure is a container structure that holds information on 
 * run-time errors.  The stack variable holds the trace stack information 
 * that shows where the error occurred in the source code.  The parms 
 * variable holds error parameters that are substituted into the message 
 * that is returned to the user.
 */
typedef struct {
   OSRTErrLocn  stack[OSRTERRSTKSIZ];
   OSINT16      status;
   OSUINT8      stkx;
   OSUINT8      parmcnt;
   OSUTF8CHAR*  parms[OSRTMAXERRPRM];
   OSUTF8CHAR*  elemName;
} OSRTErrInfo;

typedef struct {
   OSRTDList list;              /* list of errors */
   OSRTErrInfo reserved;        /* error info elem, used if nomem to alloc */
   OSRTDListNode reservedNode;  /* node placeholder for errInfo elem       */
} OSRTErrInfoList;

/**
 * @struct OSRTBuffer rtContext.h
 * Run-time message buffer structure
 *
 * This structure holds encoded message data.  For an encode operation, 
 * it is where the message being built is stored.  For decode, it 
 * holds a copy of the message that is being decoded.  
 */
typedef struct {
   OSOCTET*     data;           /* pointer to start of data buffer      */
   size_t       byteIndex;      /* byte index                           */
   size_t       size;           /* current buffer size                  */
   OSINT16      bitOffset;      /* current bit offset (8 - 1)           */
   OSBOOL       dynamic;        /* is buffer dynamic?                   */
   OSBOOL       aligned;        /* is buffer byte aligned?              */
} OSRTBuffer;

typedef OSUINT32 OSRTFLAGS;

/**
 * @struct OSRTBufSave rtContext.h
 * Structure to save the current message buffer state
 *
 * This structure is used to save the current state of the buffer.
 */
typedef struct {
   size_t      byteIndex;      /* byte index                           */
   OSINT16     bitOffset;      /* current bit offset (8 - 1)           */
   OSRTFLAGS   flags;          /* flag bits                            */
} OSRTBufSave;

/* OSRTCTXT flag mask values : bits 32 - 16 are for common flags, bits  */
/* 15 - 0 are reserved for application specific flags                   */

#define OSDIAG          0x80000000  /* diagnostic tracing enabled       */
#define OSTRACE         0x40000000  /* tracing enabled                  */
#define OSDISSTRM       0x20000000  /* disable stream encode/decode     */
#define OSSAVEBUF       0x10000000  /* do not free dynamic encode buffer */

/**
 * @struct OSRTCTXT rtContext.h
 * Run-time context structure
 *
 * This structure is a container structure that holds all working 
 * variables involved in encoding or decoding a message.
 */
typedef struct OSCTXT {          /* run-time context block               */
   void*         pMemHeap;       /* internal message memory heap         */
   OSRTBuffer    buffer;         /* data buffer                          */
   OSRTBufSave   savedInfo;      /* saved buffer info                    */
   OSRTErrInfoList errInfo;      /* run-time error info                  */
   OSUINT32      initCode;       /* code double word to indicate init    */
   OSRTFLAGS     flags;          /* flag bits                            */
   OSOCTET       level;          /* nesting level                        */
   OSOCTET       state;          /* encode/decode process state          */
   OSOCTET       spare[2];       /* word boundary padding                */
   struct OSRTSTREAM* pStream;   /* Stream                               */
   struct OSRTPrintStream *pPrintStrm; /* Print Stream                   */
   OSRTDList elemNameStack;      /* element name stack                   */
   const OSOCTET* key;           /* pointer to run-time key data         */
   size_t        keylen;         /* run-time key length                  */
   OSVoidPtr	 pXMLInfo;       /* XML specific info                    */
   OSVoidPtr	 pASN1Info;      /* ASN.1 specific info                  */
   OSVoidPtr     pUserData;      /* User defined data                    */
} OSCTXT;

#define OSRT_GET_FIRST_ERROR_INFO(pctxt) \
(((pctxt)->errInfo.list.head == 0) ? (OSRTErrInfo*)0 : \
(OSRTErrInfo*)((pctxt)->errInfo.list.head->data))

#define OSRT_GET_LAST_ERROR_INFO(pctxt) \
(((pctxt)->errInfo.list.tail == 0) ? (OSRTErrInfo*)0 : \
(OSRTErrInfo*)((pctxt)->errInfo.list.tail->data))

/*
 * OSRTFreeCtxtAppInfoPtr is a pointer to pctxt->pAppInfo free function,
 * The pctxt->pAppInfo (pXMLInfo and pASN1Info) should contain the pointer 
 * to a structure and its first member should be a pointer to an appInfo 
 * free function. 
 */
typedef int (*OSFreeCtxtAppInfoPtr)(OSCTXT* pctxt);

/*
 * OSRTResetCtxtAppInfoPtr is a pointer to pctxt->pAppInfo reset function,
 * The pctxt->pAppInfo (pXMLInfo and pASN1Info) should contain the pointer 
 * to a structure and its second member should be a pointer to appInfo reset 
 * function.
 */
typedef int (*OSResetCtxtAppInfoPtr)(OSCTXT* pctxt);

/**
 * @}
 */
#define OSRTISSTREAM(pctxt) \
((pctxt)->pStream != 0 && !((pctxt)->flags & OSDISSTRM))

#define OSRTBUFSAVE(pctxt) { \
(pctxt)->savedInfo.byteIndex = (pctxt)->buffer.byteIndex; \
(pctxt)->savedInfo.flags = (pctxt)->flags; }

#define OSRTBUFRESTORE(pctxt) { \
(pctxt)->buffer.byteIndex = (pctxt)->savedInfo.byteIndex; \
(pctxt)->flags = (pctxt)->savedInfo.flags; }

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup rtxCtxt Context Management Functions 
 * @{
 *
 * Context initialization functions handle the allocation, initialization, and
 * destruction of context variables (variables of type OSCTXT). These variables
 * hold all of the working data used during the process of encoding or decoding
 * a message. The context provides thread safe operation by isolating what
 * would otherwise be global variables within this structure. The context
 * variable is passed from function to function as a message is encoded or
 * decoded and maintains state information on the encoding or decoding process.
 */
/**
 * This function initializes an OSCTXT block. It sets all key working
 * parameters to their correct initial state values. It is required that this
 * function be invoked before using a context variable.
 *
 * @param pctxt        Pointer to the context structure variable to be
 *                       initialized.
 * @return             Completion status of operation:
 *                       - 0 = success,
 *                       - negative return value is error.
 */
EXTERNRTX int rtxInitContext (OSCTXT* pctxt);

/**
 * This function assigns a message buffer to a context block. The block 
 * should have been previously initialized by rtxInitContext.
 *
 * @param pctxt        The pointer to the context structure variable to be
 *                       initialized.
 * @param bufaddr      For encoding, the address of a memory buffer to receive
 *                       the encoded message. If this address is NULL (0),
 *                       encoding to a dynamic buffer will be done. For
 *                       decoding, the address of a buffer that contains the
 *                       message data to be decoded.
 * @param bufsiz       The size of the memory buffer. For encoding, this
 *                       argument may be set to zero to indicate a dynamic
 *                       memory buffer should be used.
 * @return             Completion status of operation:
 *                       - 0 = success,
 *                       - negative return value is error.
 */
EXTERNRTX int rtxInitContextBuffer (OSCTXT* pctxt, 
                                    OSOCTET* bufaddr, 
                                    size_t bufsiz);

/**
 * This function frees all dynamic memory associated with a context. This
 * includes all memory allocated using the rtxMem functions using the given
 * context parameter.
 *
 * @param pctxt        - A pointer to a context structure.


 */
EXTERNRTX void rtxFreeContext (OSCTXT* pctxt);

/*
 * This function creates a copy of a context structure. The copy is a "shallow
 * copy" (i.e. new copies of dynamic memory blocks held within the context are
 * not made, only the pointers are transferred to the new context structure).
 * This function is mainly for use from within compiler-generated code.
 *
 * @param pdest        - Context structure to which data is to be copied.
 * @param psrc         - Context structure from which data is to be copied.
 */
EXTERNRTX void rtxCopyContext (OSCTXT* pdest, OSCTXT* psrc);

/**
 * This function is used to set a processing flag within the context structure.
 *
 * @param pctxt        - A pointer to a context structure.
 * @param mask         - Mask containing bit(s) to be set.
 */
EXTERNRTX void rtxCtxtSetFlag (OSCTXT* pctxt, OSUINT32 mask);

/**
 * This function is used to clear a processing flag within the context
 * structure.
 *
 * @param pctxt        - A pointer to a context structure.
 * @param mask         - Mask containing bit(s) to be cleared.
 */
EXTERNRTX void rtxCtxtClearFlag (OSCTXT* pctxt, OSUINT32 mask);

/**
 * This macro tests if the given bit flag is set in the context.
 *
 * @param pctxt        - A pointer to a context structure.
 * @param mask         - Bit flag to be tested
 */
#define rtxCtxtTestFlag(pctxt,mask) ((pctxt->flags & ~mask) != 0)

EXTERNRTX int  rtxPreInitContext (OSCTXT* pctxt);
EXTERNRTX void rtxResetContext (OSCTXT* pctxt);



EXTERNRTX void rtxMemFreeOpenSeqExt 
(OSCTXT* pctxt, struct OSRTDList *pElemList);

/*
 * This function sets flags to a heap. May be used to control the heap's
 * behavior.
 *
 * @param pctxt        Pointer to a memory block structure that contains the
 *                       list of dynamic memory block maintained by these
 *                       functions.
 * @param flags        The flags.
 */
EXTERNRTX void  rtxMemHeapSetFlags (OSCTXT* pctxt, OSUINT32 flags);

/*
 * This function clears memory heap flags.
 *
 * @param pctxt        Pointer to a memory block structure that contains the
 *                       list of dynamic memory block maintained by these
 *                       functions.
 * @param flags        The flags
 */
EXTERNRTX void  rtxMemHeapClearFlags (OSCTXT* pctxt, OSUINT32 flags);

/*
 * This function sets the minimum size and the granularity of memory blocks
 * in memory heap for the context.  
 *
 * @param pctxt        Pointer to a context block.
 * @param blkSize      The currently used minimum size and the granularity of
 *                       memory blocks.
 */
EXTERNRTX void  rtxMemHeapSetDefBlkSize (OSCTXT* pctxt, OSUINT32 blkSize);

/*
 * This function returns the actual granularity of memory blocks in the context.
 *
 * @param pctxt        Pointer to a context block.
 */
EXTERNRTX OSUINT32 rtxMemHeapGetDefBlkSize (OSCTXT* pctxt);


#ifdef __cplusplus
}
#endif

#endif
