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
 * @file rtxMemory.h 
 * Memory management function and macro definitions.
 */
#ifndef __RTXMEMORY_H__
#define __RTXMEMORY_H__

#include "rtxsrc/rtxContext.h"

#define RT_MH_DONTKEEPFREE 0x1

#define OSRTMH_PROPID_DEFBLKSIZE   1
#define OSRTMH_PROPID_SETFLAGS     2
#define OSRTMH_PROPID_CLEARFLAGS   3

#define OSRTMH_PROPID_USER         10

#define OSRTXM_K_MEMBLKSIZ         (4*1024)

/**
 * @defgroup rtmem Memory Allocation Macros and Functions 
 *
 * Memory allocation functions and macros handle memory management for the
 * XBinder C run-time. Special algorithms are used for allocation and 
 * deallocation of memory to improve the run-time performance. @{
 */
/**
 * This macro allocates a single element of the given type.
 *
 * @param pctxt        - Pointer to a context block
 * @param type         - Data type of record to allocate
 */
#define OSRTALLOCTYPE(pctxt,type) \
(type*) rtxMemHeapAlloc (&(pctxt)->pMemHeap, sizeof(type))

/**
 * This macro allocates and zeros a single element of the given type.
 *
 * @param pctxt        - Pointer to a context block
 * @param type         - Data type of record to allocate
 */
#define OSRTALLOCTYPEZ(pctxt,type) \
(type*) rtxMemHeapAllocZ (&(pctxt)->pMemHeap, sizeof(type))

/*
 * Reallocate an array. This macro reallocates an array (either expands or
 * contracts) to hold the given number of elements. The number of elements is
 * specified in the <i>n</i> member variable of the pseqof argument.
 *
 * @param pctxt        - Pointer to a context block
 * @param pseqof       - Pointer to a generated SEQUENCE OF array structure.
 *                       The <i>n</i> member variable must be set to the number
 *                       of records to allocate.
 * @param type         - Data type of an array record
 */
#define OSRTREALLOCARRAY(pctxt,pseqof,type) do {\
if (sizeof(type)*(pseqof)->n < (pseqof)->n) return RTERR_NOMEM; \
if (((pseqof)->elem = (type*) rtxMemHeapRealloc \
(&(pctxt)->pMemHeap, (pseqof)->elem, sizeof(type)*(pseqof)->n)) == 0) \
return RTERR_NOMEM; \
} while (0)

/**
 * This macro returns the number of elements in an array.
 *
 * @param x            - Array varaible
 */
#define OSRTARRAYSIZE(x) (sizeof(x)/sizeof(x[0]))

#ifndef _NO_MALLOC
#define OSCRTMALLOC0(nbytes)       malloc(nbytes)
#define OSCRTFREE0(ptr)            free(ptr)
#else

#ifdef _NO_THREADS
extern EXTERNRTX OSCTXT g_ctxt;

#define OSCRTMALLOC0(nbytes)       rtxMemAlloc(&g_ctxt,(nbytes))
#define OSCRTFREE0(ptr)            rtxMemFreePtr(&g_ctxt,(ptr))
#else
#define OSCRTMALLOC0(nbytes)       (void*)0
#define OSCRTFREE0(ptr)            (void*)0

#endif /* _NO_THREADS */
#endif /* _NO_MALLOC */

#define OSCRTMALLOC rtxMemAlloc
#define OSCRTFREE   rtxMemFreePtr

struct OSRTDList;

#ifdef __cplusplus
extern "C" {
#endif

/* Alias for __cdecl modifier; if __cdecl keyword is not supported, 
 * redefine it as empty macro. */

#if !defined(OSCDECL)
#if defined(_MSC_VER) || defined(__BORLANDC__)
#define OSCDECL __cdecl
#else
#define OSCDECL
#endif
#endif /* OSCDECL */

/* Pointers to C Run-Time memory allocation functions *
 * (See rtxMemSetAllocFuncs)                           */

typedef void *(OSCDECL *OSMallocFunc ) (size_t size);
typedef void *(OSCDECL *OSReallocFunc) (void *ptr, size_t size);
typedef void  (OSCDECL *OSFreeFunc   ) (void *ptr);

EXTERNRTX void  rtxMemHeapAddRef (void** ppvMemHeap);
EXTERNRTX void* rtxMemHeapAlloc (void** ppvMemHeap, size_t nbytes);
EXTERNRTX void* rtxMemHeapAllocZ (void** ppvMemHeap, size_t nbytes);
EXTERNRTX int   rtxMemHeapCheckPtr (void** ppvMemHeap, void* mem_p);
EXTERNRTX int   rtxMemHeapCreate (void** ppvMemHeap);
EXTERNRTX void  rtxMemHeapFreeAll (void** ppvMemHeap);
EXTERNRTX void  rtxMemHeapFreePtr (void** ppvMemHeap, void* mem_p);
EXTERNRTX void* rtxMemHeapMarkSaved (void** ppvMemHeap, 
                                     const void* mem_p, 
                                     OSBOOL saved);
EXTERNRTX void* rtxMemHeapRealloc (void** ppvMemHeap, 
                                   void* mem_p, size_t nbytes_);
EXTERNRTX void  rtxMemHeapRelease (void** ppvMemHeap);
EXTERNRTX void  rtxMemHeapReset (void** ppvMemHeap);
EXTERNRTX void  rtxMemHeapSetProperty (void** ppvMemHeap, 
                                       OSUINT32 propId, void* pProp);



EXTERNRTX void* rtxMemNewArray (size_t nbytes);
EXTERNRTX void* rtxMemNewArrayZ (size_t nbytes);
EXTERNRTX void rtxMemDeleteArray (void* mem_p);

/**
 * This function sets the pointers to standard allocation functions. These
 * functions are used to allocate/reallocate/free memory blocks. By
 * default, standard C functions - 'malloc', 'realloc' and 'free' - are used.
 * But if some platforms do not support these functions (or some other reasons
 * exist) they can be overloaded. The functions being overloaded should have
 * the same prototypes as the standard functions.
 *
 * @param malloc_func Pointer to the memory allocation function ('malloc' by
 *    default).
 * @param realloc_func Pointer to the memory reallocation function ('realloc'
 *    by default).
 * @param free_func Pointer to the memory deallocation function ('free' by
 *    default).
 */
EXTERNRTX void rtxMemSetAllocFuncs (OSMallocFunc malloc_func,
                                    OSReallocFunc realloc_func,
                                    OSFreeFunc free_func);

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

/**
 * This function sets the minimum size and the granularity of memory blocks
 * for newly created memory heaps.  
 *
 * @param blkSize      The minimum size and the granularity of
 *                       memory blocks.
 */
EXTERNRTX void rtxMemSetDefBlkSize (OSUINT32 blkSize);

/**
 * This function returns the actual granularity of memory blocks.
 *
 * @return             The currently used minimum size and the granularity of
 *                       memory blocks.
 */
EXTERNRTX OSUINT32 rtxMemGetDefBlkSize ();

/**
 * This helper function determines if an arbitrarily sized block of 
 * memory is set to zero.
 *
 * @param pmem          Pointer to memory block to check
 * @param memsiz        Size of the memory block
 * @return              Boolean result: true if memory is all zero
 */
EXTERNRTX OSBOOL rtxMemIsZero (const void* pmem, size_t memsiz);

#ifdef _STATIC_HEAP
EXTERNRTX void rtxMemSetStaticBuf (void* memHeapBuf, OSUINT32 blkSize);
#endif

/*
 * Allocate memory.  This macro allocates the given number of bytes.  It is 
 * similar to the C \c malloc run-time function.
 * 
 * @param pctxt - Pointer to a context block
 * @param nbytes - Number of bytes of memory to allocate
 * @return - Void pointer to allocated memory or NULL if insufficient memory 
 *   was available to fulfill the request.
 */
#define rtxIntlMemAlloc(pctxt,nbytes) \
rtxMemHeapAlloc(&(pctxt)->pMemHeap,nbytes)

/*
 * Allocate and zero memory.  This macro allocates the given number of bytes
 * and then initializes the memory block to zero.
 * 
 * @param pctxt - Pointer to a context block
 * @param nbytes - Number of bytes of memory to allocate
 * @return - Void pointer to allocated memory or NULL if insufficient memory 
 *   was available to fulfill the request.
 */
#define rtxIntlMemAllocZ(pctxt,nbytes) \
rtxMemHeapAllocZ(&(pctxt)->pMemHeap,nbytes)

/*
 * Reallocate memory.  This macro reallocates a memory block (either 
 * expands or contracts) to the given number of bytes.  It is 
 * similar to the C \c realloc run-time function.
 * 
 * @param pctxt - Pointer to a context block
 * @param mem_p - Pointer to memory block to reallocate.  This must have been 
 *   allocated using the rtxMemAlloc macro or the rtxMemHeapAlloc function.
 * @param nbytes - Number of bytes of memory to which the block is to be 
 *   resized.
 * @return - Void pointer to allocated memory or NULL if insufficient memory 
 *   was available to fulfill the request.  This may be the same as the pmem 
 *   pointer that was passed in if the block did not need to be relocated.
 */
#define rtxIntlMemRealloc(pctxt,mem_p,nbytes) \
rtxMemHeapRealloc(&(pctxt)->pMemHeap, (void*)mem_p, nbytes)

/*
 * Free memory pointer.  This macro frees memory at the given pointer.  
 * The memory must have been allocated using the rtxMemAlloc (or similar) 
 * macros or the rtxMem memory allocation macros.  This macro is 
 * similar to the C \c free function.
 * 
 * @param pctxt - Pointer to a context block
 * @param mem_p - Pointer to memory block to free.  This must have 
 *   been allocated using the rtxMemAlloc or rtxMemAlloc macro or the 
 *   rtxMemHeapAlloc function.
 */
#define rtxIntlMemFreePtr(pctxt,mem_p) \
if (rtxMemHeapCheckPtr (&(pctxt)->pMemHeap, (void*)mem_p)) \
rtxMemHeapFreePtr(&(pctxt)->pMemHeap, (void*)mem_p)

/*
 * Free memory associated with a context.  This macro frees all memory 
 * held within a context.  This is all memory allocated using the 
 * rtxMemAlloc (and similar macros) and the rtxMem memory allocation 
 * functions using the given context variable.
 * 
 * @param pctxt - Pointer to a context block
 */
#define rtxIntlMemFree(pctxt) \
rtxMemHeapFreeAll(&(pctxt)->pMemHeap)

/*
 * Reset memory associated with a context.  This macro resets all memory 
 * held within a context.  This is all memory allocated using the rtxMemAlloc 
 * (and similar macros) and the rtxMem memory allocation functions using the 
 * given context variable.
 *
 * <p>The difference between this and the OSMEMFREE macro is that the 
 * memory blocks held within the context are not actually freed.  Internal 
 * pointers are reset so the existing blocks can be reused.  This can 
 * provide a performace improvement for repetitive tasks such as decoding 
 * messages in a loop.
 * 
 * @param pctxt - Pointer to a context block
 */
#define rtxIntlMemReset(pctxt) \
rtxMemHeapReset(&(pctxt)->pMemHeap)

/**
 * Allocate type.  This macro allocates memory to hold a variable of the 
 * given type.
 * 
 * @param pctxt - Pointer to a context block
 * @param ctype - Name of C typedef 
 * @return - Pointer to allocated memory or NULL if insufficient memory 
 *   was available to fulfill the request.
 */
#define rtxIntlMemAllocType(pctxt,ctype) \
(ctype*)rtxMemHeapAlloc(&(pctxt)->pMemHeap,sizeof(ctype))

/**
 * Allocate type and zero memory.  This macro allocates memory to hold a 
 * variable of the given type and initializes the allocated memory to zero.
 * 
 * @param pctxt - Pointer to a context block
 * @param ctype - Name of C typedef 
 * @return - Pointer to allocated memory or NULL if insufficient memory 
 *   was available to fulfill the request.
 */
#define rtxIntlMemAllocTypeZ(pctxt,ctype) \
(ctype*)rtxMemHeapAllocZ(&(pctxt)->pMemHeap,sizeof(ctype))

/*
 * Free memory pointer.  This macro frees memory at the given pointer.  
 * The memory must have been allocated using the rtxMemAlloc (or similar) 
 * macros or the rtxMem memory allocation macros.  This macro is 
 * similar to the C \c free function.
 * 
 * @param pctxt - Pointer to a context block
 * @param mem_p - Pointer to memory block to free.  This must have 
 *   been allocated using the rtxMemAlloc or rtxMemAlloc macro or the 
 *   rtxMemHeapAlloc function.
 */
#define rtxIntlMemFreeType(pctxt,mem_p) \
rtxMemHeapFreePtr(&(pctxt)->pMemHeap, (void*)mem_p)

/**
 * Allocate a dynamic array. This macro allocates a dynamic array of 
 * records of the given type. The pointer to the allocated array is 
 * returned to the caller.
 *
 * @param pctxt        - Pointer to a context block
 * @param n            - Number of records to allocate
 * @param type         - Data type of an array record
 */
#define rtxIntlMemAllocArray(pctxt,n,type) \
(type*)rtxMemHeapAlloc (&(pctxt)->pMemHeap, sizeof(type)*n)

#define rtxIntlMemAllocArrayZ(pctxt,n,type) \
(type*)rtxMemHeapAllocZ (&(pctxt)->pMemHeap, sizeof(type)*n)

/*
 * Free memory pointer.  This macro frees memory at the given pointer.  
 * The memory must have been allocated using the rtxMemAlloc (or similar) 
 * macros or the rtxMem memory allocation macros.  This macro is 
 * similar to the C \c free function.
 * 
 * @param pctxt - Pointer to a context block
 * @param mem_p - Pointer to memory block to free.  This must have 
 *   been allocated using the rtxMemAlloc or rtxMemAlloc macro or the 
 *   rtxMemHeapAlloc function.
 */
#define rtxIntlMemFreeArray(pctxt,mem_p) \
rtxMemHeapFreePtr(&(pctxt)->pMemHeap, (void*)mem_p)

/*
 * Reallocate memory.  This macro reallocates a memory block (either 
 * expands or contracts) to the given number of bytes.  It is 
 * similar to the C \c realloc run-time function.
 * 
 * @param pctxt - Pointer to a context block
 * @param mem_p - Pointer to memory block to reallocate.  This must have been 
 *   allocated using the rtxMemAlloc macro or the rtxMemHeapAlloc function.
 * @param nbytes - Number of bytes of memory to which the block is to be 
 *   resized.
 * @return - Void pointer to allocated memory or NULL if insufficient memory 
 *   was available to fulfill the request.  This may be the same as the pmem 
 *   pointer that was passed in if the block did not need to be relocated.
 */
#define rtxIntlMemReallocArray(pctxt,mem_p,n,type) \
(type*)rtxMemHeapRealloc(&(pctxt)->pMemHeap, (void*)mem_p, sizeof(type)*n)

#if 0 /*def CPP*/
/*
extern void* operator new (size_t sz, );
extern void operator delete (void* ptr);
extern void* operator new[] (size_t sz);
extern void operator delete[] (void* ptr);
extern void* renew (void* ptr, size_t newsz);
extern void* operator new (size_t sz, int);
extern void* operator new[] (size_t sz, int);*/

#define rtxMemAlloc(pctxt,nbytes) OSRT::new char[nbytes]
#define rtxMemAllocZ(pctxt,nbytes) OSRT::new (0) char[nbytes]
#define rtxMemRealloc(pctxt,mem_p,nbytes) (void*)0
#define rtxMemFreePtr(pctxt,mem_p) OSRT::delete [] mem_p

#define rtxMemAllocType(pctxt,ctype) OSRT::new ctype
#define rtxMemAllocTypeZ(pctxt,ctype) OSRT::new (0) ctype
#define rtxMemFreeType(pctxt,mem_p) OSRT::delete mem_p
#define rtxMemAllocArray(pctxt,n,type) OSRT::new type[n]
#define rtxMemAllocArrayZ(pctxt,n,type) OSRT::new (0) type[n]
#define rtxMemFreeArray(pctxt,mem_p) OSRT::delete [] mem_p
#define rtxMemReallocArray(pctxt,mem,n,type) OSRT::renew (mem,n*sizeof(type))


#define rtxMemFree(pctxt) 1
#define rtxMemReset(pctxt) 1
#else

EXTERNRTX void* rtxMemAlloc (OSCTXT* pctxt, size_t nbytes);
EXTERNRTX void* rtxMemAllocZ (OSCTXT* pctxt, size_t nbytes);
EXTERNRTX void  rtxMemFreePtr (OSCTXT* pctxt, void* mem_p);
EXTERNRTX void* rtxMemRealloc (OSCTXT* pctxt, void* mem_p, size_t nbytes);
EXTERNRTX void  rtxMemReset (OSCTXT* pctxt);

//#define rtxMemAlloc(pctxt,nbytes) rtxIntlMemAlloc(pctxt,nbytes)
//#define rtxMemAllocZ(pctxt,nbytes) rtxIntlMemAllocZ(pctxt,nbytes)
//#define rtxMemRealloc(pctxt,mem_p,nbytes) rtxIntlMemRealloc(pctxt,mem_p,nbytes)
//#define rtxMemFreePtr(pctxt,mem_p) rtxIntlMemFreeType(pctxt,mem_p)
//#define rtxMemReset(pctxt) rtxIntlMemReset(pctxt)

#define rtxMemAllocType(pctxt,ctype) (ctype*)rtxMemAlloc(pctxt,sizeof(ctype))
#define rtxMemAllocTypeZ(pctxt,ctype) (ctype*)rtxMemAllocZ(pctxt,sizeof(ctype))
#define rtxMemFreeType(pctxt,mem_p) rtxMemFreePtr(pctxt,mem_p)
#define rtxMemAllocArray(pctxt,n,type) (type*)rtxMemAlloc(pctxt,n*sizeof(type))
#define rtxMemAllocArrayZ(pctxt,n,type) (type*)rtxMemAllocZ(pctxt,n*sizeof(type))
#define rtxMemFreeArray(pctxt,mem_p) rtxMemFreePtr(pctxt,mem_p)
#define rtxMemReallocArray(pctxt,mem,n,type) (type*)rtxMemRealloc(pctxt,mem,n*sizeof(type))
#define rtxMemFree(pctxt) rtxMemFreePtr(pctxt)

#endif

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /*__RTXMEMORY_H__*/
