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
 * @file rtxPrintToStream.h
 */
#ifndef _RTXPRINTTOSTREAM_H_
#define _RTXPRINTTOSTREAM_H_

#include <stdio.h>
#include "rtxsrc/rtxContext.h"

#define OSRTINDENTSPACES        3       /* number of spaces for indent  */

#ifdef __cplusplus
extern "C" {
#endif

/* Run-time print utility functions */

/**
 * @defgroup prtToStrm Print Functions
 * @{
 *
 * These functions print typed data in a "name=value" format. The output 
 * is redirected to the print stream defined within the context or to a 
 * global print stream.  Print streams are set using the rtxSetPrintStream 
 * or rtxSetGlobalPrintStream function.
 */
/**
 * Prints a boolean value to a print stream.
 *
 * @param name         The name of the variable to print.
 * @param value        Boolean value to print.
 */
EXTERNRTX void rtxPrintToStreamBoolean 
   (OSCTXT* pctxt, const char* name, OSBOOL value);

/**
 * Prints a date value to a print stream.
 *
 * @param name         Name of the variable to print.
 * @param pvalue       Pointer to a structure that holds numeric 
 *                        DateTime value to print.
 */
EXTERNRTX void rtxPrintToStreamDate 
   (OSCTXT* pctxt, const char* name, const OSNumDateTime *pvalue);

/**
 * Prints a time value to a print stream.
 *
 * @param name         Name of the variable to print.
 * @param pvalue       Pointer to a structure that holds numeric 
 *                        DateTime value to print.
 */
EXTERNRTX void rtxPrintToStreamTime 
   (OSCTXT* pctxt, const char* name, const OSNumDateTime *pvalue);

/**
 * Prints a dateTime value to a print stream.
 *
 * @param name         Name of the variable to print.
 * @param pvalue       Pointer to a structure that holds numeric 
 *                        DateTime value to print.
 */
EXTERNRTX void rtxPrintToStreamDateTime 
   (OSCTXT* pctxt, const char* name, const OSNumDateTime *pvalue);

EXTERNRTX void rtxPrintToStreamGYear 
   (OSCTXT* pctxt, const char* name, const OSNumDateTime* pvalue);

EXTERNRTX void rtxPrintToStreamGYearMonth 
   (OSCTXT* pctxt, const char* name, const OSNumDateTime* pvalue);

EXTERNRTX void rtxPrintToStreamGMonth 
   (OSCTXT* pctxt, const char* name, const OSNumDateTime* pvalue);

EXTERNRTX void rtxPrintToStreamGMonthDay 
   (OSCTXT* pctxt, const char* name, const OSNumDateTime* pvalue);

EXTERNRTX void rtxPrintToStreamGDay 
   (OSCTXT* pctxt, const char* name, const OSNumDateTime* pvalue);

/**
 * Prints an integer value to a print stream.
 *
 * @param name         The name of the variable to print.
 * @param value        Integer value to print.
 */
EXTERNRTX void rtxPrintToStreamInteger 
   (OSCTXT* pctxt, const char* name, OSINT32 value);

/**
 * Prints a 64-bit integer value to a print stream.
 *
 * @param name         The name of the variable to print.
 * @param value        64-bit integer value to print.
 */
EXTERNRTX void rtxPrintToStreamInt64 
   (OSCTXT* pctxt, const char* name, OSINT64 value);

/**
 * Prints an unsigned integer value to a print stream.
 *
 * @param name         The name of the variable to print.
 * @param value        Unsigned integer value to print.
 */
EXTERNRTX void rtxPrintToStreamUnsigned 
   (OSCTXT* pctxt, const char* name, OSUINT32 value);

/**
 * Prints an unsigned 64-bit integer value to a print stream.
 *
 * @param name         The name of the variable to print.
 * @param value        Unsigned 64-bit integer value to print.
 */
EXTERNRTX void rtxPrintToStreamUInt64 
   (OSCTXT* pctxt, const char* name, OSUINT64 value);

/** 
 * This function prints the value of a binary string in hex format 
 * to standard output.  If the string is 32 bytes or less, it is printed
 * on a single line with a '0x' prefix.  If longer, a formatted hex dump 
 * showing both hex and ascii codes is done.
 *
 * @param name         The name of the variable to print.
 * @param numocts      The number of octets to be printed.
 * @param data         A pointer to the data to be printed.
 */
EXTERNRTX void rtxPrintToStreamHexStr 
   (OSCTXT* pctxt, const char* name, OSUINT32 numocts, const OSOCTET* data);

/** 
 * Prints an octet string value in hex binary format to a print stream.
 *
 * @param name         The name of the variable to print.
 * @param numocts      The number of octets to be printed.
 * @param data         A pointer to the data to be printed.
 */
EXTERNRTX void rtxPrintToStreamHexBinary 
   (OSCTXT* pctxt, const char* name, OSUINT32 numocts, const OSOCTET* data);

/** 
 * Prints an ASCII character string value to a print stream.
 *
 * @param name         The name of the variable to print.
 * @param cstring      A pointer to the character string to be printed.
 */
EXTERNRTX void rtxPrintToStreamCharStr 
   (OSCTXT* pctxt, const char* name, const char* cstring);

/** 
 * Prints a UTF-8 encoded character string value to a print stream.
 *
 * @param name         The name of the variable to print.
 * @param cstring      A pointer to the character string to be printed.
 */
EXTERNRTX void rtxPrintToStreamUTF8CharStr 
   (OSCTXT* pctxt, const char* name, const OSUTF8CHAR* cstring);

/**
 * This function prints a Unicode string to standard output.  Characters 
 * in the string that are within the normal Ascii range are printed as 
 * single characters.  Characters outside the Ascii range are printed 
 * as 4-byte hex codes (0xnnnn).
 *
 * @param name         The name of the variable to print.
 * @param str          Pointer to unicode sring to be printed.  String is 
 *                       an array of C unsigned short data variables.
 * @param nchars       Number of characters in the string.  If value is 
 *                       negative, string is assumed to be null-terminated
 *                       (i.e. ends with a 0x0000 character).
 */
EXTERNRTX void rtxPrintToStreamUnicodeCharStr 
   (OSCTXT* pctxt, const char* name, const OSUNICHAR* str, int nchars);

/**
 * Prints a REAL (float, double, decimal) value to a print stream.
 *
 * @param name         The name of the variable to print.
 * @param value        REAL value to print.
 */
EXTERNRTX void rtxPrintToStreamReal 
   (OSCTXT* pctxt, const char* name, OSREAL value);

/**
 * Prints a NULL value to a print stream.
 *
 * @param name         The name of the variable to print.
 */
EXTERNRTX void rtxPrintToStreamNull (OSCTXT* pctxt, const char* name);

/**
 * Prints a name-value pair to a print stream.
 *
 * @param name         The name of the variable to print.
 * @param value        A pointer to name-value pair structure to print.
 */
EXTERNRTX void rtxPrintToStreamNVP 
   (OSCTXT* pctxt, const char* name, const OSUTF8NVP* value);

/**
 * This function prints the contents of a text file to a print stream.
 *
 * @param filename     The name of the text file to print.
 * @return             Status of operation, 0 if success.
 */
EXTERNRTX int rtxPrintToStreamFile (OSCTXT* pctxt, const char* filename);

/**
 * This function prints indentation spaces to a print stream.
 */
EXTERNRTX void rtxPrintToStreamIndent (OSCTXT* pctxt);

/**
 * This function increments the current indentation level.
 */
EXTERNRTX void rtxPrintToStreamIncrIndent ();

/**
 * This function decrements the current indentation level.
 */
EXTERNRTX void rtxPrintToStreamDecrIndent ();

/**
 * This function closes a braced region by decreasing the indent level, 
 * printing indent spaces, and printing the closing brace.
 */
EXTERNRTX void rtxPrintToStreamCloseBrace (OSCTXT* pctxt);

/**
 * This function opens a braced region by printing indent spaces, 
 * printing the name and opening brace, and increasing the indent level.
 */
EXTERNRTX void rtxPrintToStreamOpenBrace (OSCTXT* pctxt, const char*);

/**
 * This function outputs a hexadecimal dump of the current buffer contents 
 * to a print stream.
 *
 * @param fp           A pointer to FILE structure. The file should be opened
 *                       for writing.
 * @param data         The pointer to a buffer to be displayed.
 * @param numocts      The number of octets to be displayed
 */
EXTERNRTX void rtxHexDumpToStream 
   (OSCTXT* pctxt, const OSOCTET* data, OSUINT32 numocts);

/**
 * This function outputs a hexadecimal dump of the current buffer to a 
 * print stream, but it may output the dump as an array of bytes, words, 
 * or double words.
 *
 * @param fp           A pointer to FILE structure. The file should be opened
 *                       for writing.
 * @param data         The pointer to a buffer to be displayed.
 * @param numocts      The number of octets to be displayed.
 * @param bytesPerUnit The number of bytes in one unit. May be 1 (byte), 2
 *                       (word), or 4 (double word).
 */
EXTERNRTX void rtxHexDumpToStreamEx 
   (OSCTXT* pctxt, const OSOCTET* data, OSUINT32 numocts, int bytesPerUnit);

/**
 * @} prtToStrm
 */
#ifdef __cplusplus
}
#endif

#endif
