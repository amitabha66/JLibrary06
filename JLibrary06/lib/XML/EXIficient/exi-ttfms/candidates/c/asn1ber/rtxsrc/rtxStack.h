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
 * @file rtxStack.h
 */
#ifndef _RTXSTACK_H_
#define _RTXSTACK_H_

#include "rtxsrc/rtxContext.h"

#define OS_K_MAXSTACKDEPTH  32      /* maximum stack depth    */

/**
 * @defgroup ccfStack Stack Utility Functions
 * 
 *@{
 */

/**
 * @struct _OSRTStack
 * This is the main stack structure.  It contains a nesting level 
 * and pointers to the data. 
 */
typedef struct _OSRTStack {
   int level;
   void* data[OS_K_MAXSTACKDEPTH];
} OSRTStack;

#ifdef __cplusplus
extern "C" {
#endif

/** 
 * This function creates a new stack structure. It allocates memory for the
 * structure and calls rtxStackInit to initialize the structure.
 *
 * @return             A pointer to an allocated stack structure.
 */
EXTERNRTX OSRTStack* rtxStackCreate (void);

/** 
 * This function creates a new stack structure. The pctxt will be used for
 * memory management.
 *
 * @param pctxt        A pointer to a context structure.
 * @return             A pointer to an allocated stack structure.
 */
EXTERNRTX OSRTStack* rtxStackCreateEx (OSCTXT* pctxt);

/** 
 * This function initializes a stack structure. It sets the number of elements
 * to zero and sets all internal pointer values to NULL.
 *
 * @param pStack       A pointer to a stack structure to be initialized.
 */
EXTERNRTX void  rtxStackInit (OSRTStack* pStack);

/** 
 * This function pops an item off the stack.
 *
 * @param pStack       The pointer to the stack structure from which the value
 *                       is to be popped. Pointer to the updated stack
 *                       structure.
 * @return             The pointer to the item popped from the stack
 */
EXTERNRTX void* rtxStackPop (OSRTStack* pStack);

/**
 * This function pushes an item onto the stack.
 *
 * @param pStack       A pointer to the structure onto which the data item is
 *                       to be pushed. The pointer updated to the stack
 *                       structure
 * @param pData        A pointer to the data item to be pushed on the stack.
 * @return             Completion status of operation:
 *                       - 0 (0) = success,
 *                       - negative return value is error.
 */
EXTERNRTX int   rtxStackPush (OSRTStack* pStack, void* pData);

/**
 * @}
 */
#ifdef __cplusplus
}
#endif

#endif
