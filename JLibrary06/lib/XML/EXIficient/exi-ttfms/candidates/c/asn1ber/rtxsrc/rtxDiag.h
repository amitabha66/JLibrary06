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
 * @file rtxDiag.h 
 * Common runtime functions for diagnostic tracing and debugging.
 */
#ifndef _RTXDIAG_H_
#define _RTXDIAG_H_

#include <stdarg.h>
#include "rtxsrc/rtxContext.h"
#include "rtxsrc/rtxPrintToStream.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Diagnostic trace functions */
/**
 * @defgroup ccfDiag Diagnostic trace functions 
 * @{
 *
 * These functions add diagnostic tracing to the generated code to assist in
 * finding where a problem might occur. Calls to these macros and functions are
 * added when the \c -trace command-line argument is used. The diagnostic
 * message can be turned on and off at both C compile and run-time. To C
 * compile the diagnostics in, the _TRACE macro must be defined (-D_TRACE). To
 * turn the diagnostics on at run-time, the \c rtxSetDiag function must be
 * invoked with the \c value argument set to TRUE.
 */
#ifdef _TRACE
#define RTDIAG1(pctxt,msg)              rtxDiagPrint(pctxt,msg)
#define RTDIAG2(pctxt,msg,a)            rtxDiagPrint(pctxt,msg,a)
#define RTDIAG3(pctxt,msg,a,b)          rtxDiagPrint(pctxt,msg,a,b)
#define RTDIAG4(pctxt,msg,a,b,c)        rtxDiagPrint(pctxt,msg,a,b,c)
#define RTDIAG5(pctxt,msg,a,b,c,d)      rtxDiagPrint(pctxt,msg,a,b,c,d)
#define RTDIAGU(pctxt,ucstr)            rtxDiagPrintUCS(pctxt,ucstr)
#define RTHEXDUMP(buffer,numocts)       rtxDiagHexDump(buffer,numocts)
#define RTDIAGSTRM2(pctxt,msg)          rtxDiagStream(pctxt,msg)
#define RTDIAGSTRM3(pctxt,msg,a)        rtxDiagStream(pctxt,msg,a)
#define RTDIAGSTRM4(pctxt,msg,a,b)      rtxDiagStream(pctxt,msg,a,b)
#define RTDIAGSTRM5(pctxt,msg,a,b,c)    rtxDiagStream(pctxt,msg,a,b,c)
#define RTHEXDUMPSTRM(pctxt,buffer,numocts) \
rtxDiagStreamHexDump(pctxt,buffer,numocts)
#else
#define RTDIAG1(pctxt,msg)
#define RTDIAG2(pctxt,msg,a)
#define RTDIAG3(pctxt,msg,a,b)
#define RTDIAG4(pctxt,msg,a,b,c)
#define RTDIAG5(pctxt,msg,a,b,c,d)
#define RTDIAGU(pctxt,ucstr)
#define RTHEXDUMP(buffer,numocts)
#define RTDIAGSTRM2(pctxt,msg)
#define RTDIAGSTRM3(pctxt,msg,a)
#define RTDIAGSTRM4(pctxt,msg,a,b)
#define RTDIAGSTRM5(pctxt,msg,a,b,c)
#define RTHEXDUMPSTRM(pctxt,buffer,numocts)
#endif

/**
 * This function is used to determine if diagnostic tracing is currently
 * enabled for the specified context. It returns true if enabled, false
 * otherwise.
 *
 * @param pctxt        Pointer to context structure.
 * @return             Boolean result.
 */
EXTERNRTX OSBOOL rtxDiagEnabled (OSCTXT* pctxt);

/**
 * This function is used to turn diagnostic tracing on or off at run-time on 
 * a per-context basis. Code generated using ASN1C or XBinder or a similar 
 * code generator must use the -trace command line option to enable 
 * diagnostic messages.  The generated code must then be C compiled with 
 * _TRACE defined for the code to be present.
 *
 * @param pctxt        Pointer to context structure.
 * @param value        Boolean switch: TRUE turns tracing on, FALSE off.
 * @return             Prior setting of the diagnostic trace switch in the
 *                       context.
 */
EXTERNRTX OSBOOL rtxSetDiag (OSCTXT* pctxt, OSBOOL value);

/**
 * This function is used to turn diagnostic tracing on or off at run-time on 
 * a global basis. It is similar to rtxSetDiag except tracing is enabled 
 * within all contexts.
 *
 * @param value        Boolean switch: TRUE turns tracing on, FALSE off.
 * @return             Prior setting of the diagnostic trace switch in the
 *                       context.
 */
EXTERNRTX OSBOOL rtxSetGlobalDiag (OSBOOL value);

/**
 * This function is used to print a diagnostics message to \c stdout. Its
 * parameter specification is similar to that of the C runtime \c printf
 * method. The \c fmtspec argument may contain % style modifiers into which
 * variable arguments are substituted. This function is called in the generated
 * code vai the RTDIAG macros to allow diagnostic trace call to easily be
 * compiled out of the object code.
 *
 * @param pctxt        Pointer to context structure.
 * @param fmtspec      printf-like format string specification
 * @param             ... Variable list of parameters to be substituted into
 *                       the format string.
 */
EXTERNRTX void rtxDiagPrint (OSCTXT* pctxt, const char* fmtspec, ...);

/**
 * This function conditionally outputs diagnostic trace messages to an output 
 * stream defined within the context. A code generator embeds calls to this 
 * function into the generated source code when the -trace option is specified
 * on the command line (note: it may embed the macro version of these calls - 
 * RTDIAGSTREAMx - so that these calls can be compiled out of the final code.
 *
 * @param pctxt        Pointer to context structure.
 * @param fmtspec      A printf-like format specification string describing the
 *                       message to be printed (for example, "string %s, ivalue
 *                       %d\n").
 * @param ...          A variable list of arguments.
 */
EXTERNRTX void rtxDiagStream (OSCTXT* pctxt, const char* fmtspec, ...);

/**
 * This function is used to print a diagnostics hex dump of a section of
 * memory.
 *
 * @param pctxt        Pointer to context structure.
 * @param data         Start address of memory to dump.
 * @param numocts      Number of bytes to dump.
 */
EXTERNRTX void rtxDiagHexDump 
(OSCTXT* pctxt, const OSOCTET* data, OSUINT32 numocts);

/**
 * This function is used to print a diagnostics hex dump of a section of
 * memory to a print stream.
 *
 * @param pctxt        Pointer to context structure.
 * @param data         Start address of memory to dump.
 * @param numocts      Number of bytes to dump.
 */
EXTERNRTX void rtxDiagStreamHexDump 
(OSCTXT* pctxt, const OSOCTET* data, OSUINT32 numocts);

/**
 * @} ccfDiag
 */

#ifdef __cplusplus
}
#endif

#endif

