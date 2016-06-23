/*****************************************************************************/
/* Copyright (C) 1999-2006 OSS Nokalva, Inc.  All rights reserved            */
/*****************************************************************************/
/*****************************************************************************/
/* FILE: @(#)ossxltype.h	15.1  06/02/12                                        */
/*****************************************************************************/
/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC. AND                */
/* MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.                 */
/* THIS FILE MAY NOT BE DISTRIBUTED.                                         */
/*****************************************************************************/

#ifndef OSSXLTYPE_H
#define OSSXLTYPE_H
#include "ossxsd.h"


#ifdef DLL_LINKAGE

/* BER decoder function references */
#define OSSX_LEAN_TYPE_NOT_SUPPORTED_BER_DEC             NULL
#define OSSX_LEAN_INTEGER_BER_DEC                        NULL
#define OSSX_LEAN_NULL_BER_DEC                           NULL
#define OSSX_LEAN_ENUMERATED_BER_DEC                     NULL
#define OSSX_LEAN_REAL_BER_DEC                           NULL
#define OSSX_LEAN_BOOLEAN_BER_DEC                        NULL
#define OSSX_LEAN_SEQUENCE_BER_DEC                       NULL
#define OSSX_LEAN_CHOICE_BER_DEC                         NULL
#define OSSX_LEAN_LINKED_LIST_BER_DEC             NULL
#define OSSX_LEAN_UNBOUNDED_LIST_BER_DEC          NULL
#define OSSX_LEAN_UNBOUNDED_OCTET_STRING_BER_DEC         NULL
#define OSSX_LEAN_UNBOUNDED_CHARACTER_STRING_BER_DEC     NULL
#define OSSX_LEAN_UNSIGNED_INTEGER_BER_DEC               NULL
#define OSSX_LEAN_UNSIGNED_ENUMERATED_BER_DEC            NULL
#define OSSX_LEAN_DECIMAL_REAL_BER_DEC                   NULL
#define OSSX_LEAN_HUGE_INTEGER_BER_DEC                   NULL
#define OSSX_LEAN_ENCODED_OBJECT_IDENTIFIER_BER_DEC      NULL
#define OSSX_LEAN_ENCODED_RELATIVE_OID_BER_DEC           NULL
#define OSSX_LEAN_LONGLONG_INTEGER_BER_DEC               NULL
#define OSSX_LEAN_UNSIGNED_LONGLONG_INTEGER_BER_DEC      NULL
#define OSSX_LEAN_ANY_INTEGER_BER_DEC                    NULL
#define OSSX_LEAN_UNSIGNED_ANY_INTEGER_BER_DEC           NULL
#define OSSX_LEAN_DLINKED_PLUS_LIST_BER_DEC	    NULL

/* BER encoder function references */
#define OSSX_LEAN_TYPE_NOT_SUPPORTED_BER_ENC             NULL
#define OSSX_LEAN_INTEGER_BER_ENC                        NULL
#define OSSX_LEAN_NULL_BER_ENC                           NULL
#define OSSX_LEAN_ENUMERATED_BER_ENC                     NULL
#define OSSX_LEAN_REAL_BER_ENC                           NULL
#define OSSX_LEAN_BOOLEAN_BER_ENC                        NULL
#define OSSX_LEAN_SEQUENCE_BER_ENC                       NULL
#define OSSX_LEAN_CHOICE_BER_ENC                         NULL
#define OSSX_LEAN_LINKED_LIST_BER_ENC             NULL
#define OSSX_LEAN_UNBOUNDED_LIST_BER_ENC          NULL
#define OSSX_LEAN_UNBOUNDED_OCTET_STRING_BER_ENC         NULL
#define OSSX_LEAN_UNBOUNDED_CHARACTER_STRING_BER_ENC     NULL
#define OSSX_LEAN_UNSIGNED_INTEGER_BER_ENC               NULL
#define OSSX_LEAN_UNSIGNED_ENUMERATED_BER_ENC            NULL
#define OSSX_LEAN_DECIMAL_REAL_BER_ENC                   NULL
#define OSSX_LEAN_HUGE_INTEGER_BER_ENC                   NULL
#define OSSX_LEAN_ENCODED_OBJECT_IDENTIFIER_BER_ENC      NULL
#define OSSX_LEAN_ENCODED_RELATIVE_OID_BER_ENC           NULL
#define OSSX_LEAN_LONGLONG_INTEGER_BER_ENC               NULL
#define OSSX_LEAN_UNSIGNED_LONGLONG_INTEGER_BER_ENC      NULL
#define OSSX_LEAN_ANY_INTEGER_BER_ENC                    NULL
#define OSSX_LEAN_UNSIGNED_ANY_INTEGER_BER_ENC           NULL
#define OSSX_LEAN_DLINKED_PLUS_LIST_BER_ENC	    NULL

/* PER decoder function references */
#define OSSX_LEAN_TYPE_NOT_SUPPORTED_PER_DEC             NULL
#define OSSX_LEAN_INTEGER_PER_DEC                        NULL
#define OSSX_LEAN_NULL_PER_DEC                           NULL
#define OSSX_LEAN_ENUMERATED_PER_DEC                     NULL
#define OSSX_LEAN_REAL_PER_DEC                           NULL
#define OSSX_LEAN_BOOLEAN_PER_DEC                        NULL
#define OSSX_LEAN_SEQUENCE_PER_DEC                       NULL
#define OSSX_LEAN_CHOICE_PER_DEC                         NULL
#define OSSX_LEAN_LINKED_LIST_PER_DEC             NULL
#define OSSX_LEAN_UNBOUNDED_LIST_PER_DEC          NULL
#define OSSX_LEAN_UNBOUNDED_OCTET_STRING_PER_DEC         NULL
#define OSSX_LEAN_UNBOUNDED_CHARACTER_STRING_PER_DEC     NULL
#define OSSX_LEAN_UNSIGNED_INTEGER_PER_DEC               NULL
#define OSSX_LEAN_UNSIGNED_ENUMERATED_PER_DEC            NULL
#define OSSX_LEAN_DECIMAL_REAL_PER_DEC                   NULL
#define OSSX_LEAN_HUGE_INTEGER_PER_DEC                   NULL
#define OSSX_LEAN_ENCODED_OBJECT_IDENTIFIER_PER_DEC      NULL
#define OSSX_LEAN_ENCODED_RELATIVE_OID_PER_DEC           NULL
#define OSSX_LEAN_LONGLONG_INTEGER_PER_DEC               NULL
#define OSSX_LEAN_UNSIGNED_LONGLONG_INTEGER_PER_DEC      NULL
#define OSSX_LEAN_ANY_INTEGER_PER_DEC                    NULL
#define OSSX_LEAN_UNSIGNED_ANY_INTEGER_PER_DEC           NULL
#define OSSX_LEAN_DLINKED_PLUS_LIST_PER_DEC	    NULL

/* PER encoder function references */
#define OSSX_LEAN_TYPE_NOT_SUPPORTED_PER_ENC             NULL
#define OSSX_LEAN_INTEGER_PER_ENC                        NULL
#define OSSX_LEAN_NULL_PER_ENC                           NULL
#define OSSX_LEAN_ENUMERATED_PER_ENC                     NULL
#define OSSX_LEAN_REAL_PER_ENC                           NULL
#define OSSX_LEAN_BOOLEAN_PER_ENC                        NULL
#define OSSX_LEAN_SEQUENCE_PER_ENC                       NULL
#define OSSX_LEAN_CHOICE_PER_ENC                         NULL
#define OSSX_LEAN_LINKED_LIST_PER_ENC             NULL
#define OSSX_LEAN_UNBOUNDED_LIST_PER_ENC          NULL
#define OSSX_LEAN_UNBOUNDED_OCTET_STRING_PER_ENC         NULL
#define OSSX_LEAN_UNBOUNDED_CHARACTER_STRING_PER_ENC     NULL
#define OSSX_LEAN_UNSIGNED_INTEGER_PER_ENC               NULL
#define OSSX_LEAN_UNSIGNED_ENUMERATED_PER_ENC            NULL
#define OSSX_LEAN_DECIMAL_REAL_PER_ENC                   NULL
#define OSSX_LEAN_HUGE_INTEGER_PER_ENC                   NULL
#define OSSX_LEAN_ENCODED_OBJECT_IDENTIFIER_PER_ENC      NULL
#define OSSX_LEAN_ENCODED_RELATIVE_OID_PER_ENC           NULL
#define OSSX_LEAN_LONGLONG_INTEGER_PER_ENC               NULL
#define OSSX_LEAN_UNSIGNED_LONGLONG_INTEGER_PER_ENC      NULL
#define OSSX_LEAN_ANY_INTEGER_PER_ENC                    NULL
#define OSSX_LEAN_UNSIGNED_ANY_INTEGER_PER_ENC           NULL
#define OSSX_LEAN_DLINKED_PLUS_LIST_PER_ENC	    NULL


/* XML decoder function references */
#define OSSX_LEAN_TYPE_NOT_SUPPORTED_XML_DEC             NULL
#define OSSX_LEAN_INTEGER_XML_DEC                        NULL
#define OSSX_LEAN_NULL_XML_DEC                           NULL
#define OSSX_LEAN_ENUMERATED_XML_DEC                     NULL
#define OSSX_LEAN_REAL_XML_DEC                           NULL
#define OSSX_LEAN_BOOLEAN_XML_DEC                        NULL
#define OSSX_LEAN_SEQUENCE_XML_DEC                       NULL
#define OSSX_LEAN_CHOICE_XML_DEC                         NULL
#define OSSX_LEAN_LINKED_LIST_XML_DEC             NULL
#define OSSX_LEAN_UNBOUNDED_LIST_XML_DEC          NULL
#define OSSX_LEAN_UNBOUNDED_OCTET_STRING_XML_DEC         NULL
#define OSSX_LEAN_UNBOUNDED_CHARACTER_STRING_XML_DEC     NULL
#define OSSX_LEAN_UNSIGNED_INTEGER_XML_DEC               NULL
#define OSSX_LEAN_UNSIGNED_ENUMERATED_XML_DEC            NULL
#define OSSX_LEAN_DECIMAL_REAL_XML_DEC                   NULL
#define OSSX_LEAN_HUGE_INTEGER_XML_DEC                   NULL
#define OSSX_LEAN_ENCODED_OBJECT_IDENTIFIER_XML_DEC      NULL
#define OSSX_LEAN_ENCODED_RELATIVE_OID_XML_DEC           NULL
#define OSSX_LEAN_LONGLONG_INTEGER_XML_DEC               NULL
#define OSSX_LEAN_UNSIGNED_LONGLONG_INTEGER_XML_DEC      NULL
#define OSSX_LEAN_ANY_INTEGER_XML_DEC                    NULL
#define OSSX_LEAN_UNSIGNED_ANY_INTEGER_XML_DEC           NULL
#define OSSX_LEAN_DLINKED_PLUS_LIST_XML_DEC	     NULL

/* XML encoder function references */
#define OSSX_LEAN_TYPE_NOT_SUPPORTED_XML_ENC             NULL
#define OSSX_LEAN_INTEGER_XML_ENC                        NULL
#define OSSX_LEAN_NULL_XML_ENC                           NULL
#define OSSX_LEAN_ENUMERATED_XML_ENC                     NULL
#define OSSX_LEAN_REAL_XML_ENC                           NULL
#define OSSX_LEAN_BOOLEAN_XML_ENC                        NULL
#define OSSX_LEAN_SEQUENCE_XML_ENC                       NULL
#define OSSX_LEAN_CHOICE_XML_ENC                         NULL
#define OSSX_LEAN_LINKED_LIST_XML_ENC             NULL
#define OSSX_LEAN_UNBOUNDED_LIST_XML_ENC          NULL
#define OSSX_LEAN_UNBOUNDED_OCTET_STRING_XML_ENC         NULL
#define OSSX_LEAN_UNBOUNDED_CHARACTER_STRING_XML_ENC     NULL
#define OSSX_LEAN_UNSIGNED_INTEGER_XML_ENC               NULL
#define OSSX_LEAN_UNSIGNED_ENUMERATED_XML_ENC            NULL
#define OSSX_LEAN_DECIMAL_REAL_XML_ENC                   NULL
#define OSSX_LEAN_HUGE_INTEGER_XML_ENC                   NULL
#define OSSX_LEAN_ENCODED_OBJECT_IDENTIFIER_XML_ENC      NULL
#define OSSX_LEAN_ENCODED_RELATIVE_OID_XML_ENC           NULL
#define OSSX_LEAN_LONGLONG_INTEGER_XML_ENC               NULL
#define OSSX_LEAN_UNSIGNED_LONGLONG_INTEGER_XML_ENC      NULL
#define OSSX_LEAN_ANY_INTEGER_XML_ENC                    NULL
#define OSSX_LEAN_UNSIGNED_ANY_INTEGER_XML_ENC           NULL
#define OSSX_LEAN_DLINKED_PLUS_LIST_XML_ENC	     NULL

/* XML decoder i-kind function references */
#define OSSX_LEAN_NORMAL_INT_XML_DEC		NULL
#define OSSX_LEAN_NORMAL_ENUM_XML_DEC		NULL
#define OSSX_LEAN_NORMAL_UNBND_CHAR_XML_DEC		NULL
#define OSSX_LEAN_BASE64_UNBND_OCTET_XML_DEC	NULL
#define OSSX_LEAN_NORMAL_UNBND_OCTET_XML_DEC	NULL
#define OSSX_LEAN_ANYEL_NLLTRM_CHAR_XML_DEC		NULL
#define OSSX_LEAN_USEORDER_SEQ_XML_DEC		NULL
#define OSSX_LEAN_QNAME_SEQ_XML_DEC			NULL
#define OSSX_LEAN_NORMAL_SEQ_XML_DEC		NULL
#define OSSX_LEAN_ANYATTR_LINK_SOF_XML_DEC		NULL
#define OSSX_LEAN_NORMAL_LINK_SOF_XML_DEC		NULL
#define OSSX_LEAN_MODIFIED_REAL_XML_DEC		NULL
#define OSSX_LEAN_DECIMAL_CHAR_REAL_XML_DEC		NULL
#define OSSX_LEAN_NORMAL_LONGLONG_INT_XML_DEC	NULL
#define OSSX_LEAN_NORMAL_LONGLONG_ENUM_XML_DEC	NULL
#define OSSX_LEAN_NORMAL_ANY_INT_XML_DEC		NULL
#define OSSX_LEAN_NORMAL_ANY_ENUM_XML_DEC		NULL

#define OSSX_LEAN_CPY_VAL_XML_DEC			NULL

/* XML encoder i-kind function references */
#define OSSX_LEAN_NORMAL_INT_XML_ENC		NULL
#define OSSX_LEAN_NORMAL_ENUM_XML_ENC		NULL
#define OSSX_LEAN_NORMAL_UNBND_CHAR_XML_ENC		NULL
#define OSSX_LEAN_BASE64_UNBND_OCTET_XML_ENC	NULL
#define OSSX_LEAN_NORMAL_UNBND_OCTET_XML_ENC	NULL
#define OSSX_LEAN_ANYEL_NLLTRM_CHAR_XML_ENC		NULL
#define OSSX_LEAN_USEORDER_SEQ_XML_ENC		NULL
#define OSSX_LEAN_QNAME_SEQ_XML_ENC			NULL
#define OSSX_LEAN_NORMAL_SEQ_XML_ENC		NULL
#define OSSX_LEAN_ANYATTR_LINK_SOF_XML_ENC		NULL
#define OSSX_LEAN_NORMAL_LINK_SOF_XML_ENC		NULL
#define OSSX_LEAN_MODIFIED_REAL_XML_ENC		NULL
#define OSSX_LEAN_DECIMAL_CHAR_REAL_XML_ENC		NULL
#define OSSX_LEAN_NORMAL_LONGLONG_INT_XML_ENC	NULL
#define OSSX_LEAN_NORMAL_LONGLONG_ENUM_XML_ENC	NULL
#define OSSX_LEAN_NORMAL_ANY_INT_XML_ENC		NULL
#define OSSX_LEAN_NORMAL_ANY_ENUM_XML_ENC		NULL

#else

/* BER decoder function references */
#define OSSX_LEAN_TYPE_NOT_SUPPORTED_BER_DEC         ossxBerDecTypeNotSupported
#define OSSX_LEAN_INTEGER_BER_DEC                    ossxBerDecIntegerEnumerated
#define OSSX_LEAN_NULL_BER_DEC                       ossxBerDecNull
#define OSSX_LEAN_ENUMERATED_BER_DEC                 ossxBerDecIntegerEnumerated
#define OSSX_LEAN_REAL_BER_DEC                       ossxBerDecReal
#define OSSX_LEAN_BOOLEAN_BER_DEC                    ossxBerDecBoolean
#define OSSX_LEAN_SEQUENCE_BER_DEC                   ossxBerDecSequence
#define OSSX_LEAN_CHOICE_BER_DEC                     ossxBerDecChoice
#define OSSX_LEAN_LINKED_LIST_BER_DEC         ossxBerDecLinkedUnboundedList
#define OSSX_LEAN_UNBOUNDED_LIST_BER_DEC      ossxBerDecLinkedUnboundedList
#define OSSX_LEAN_UNBOUNDED_OCTET_STRING_BER_DEC     ossxBerDecUnboundedOctetString
#define OSSX_LEAN_UNBOUNDED_CHARACTER_STRING_BER_DEC ossxBerDecUnboundedOctetString
#define OSSX_LEAN_UNSIGNED_INTEGER_BER_DEC           ossxBerDecUIntegerEnumerated
#define OSSX_LEAN_UNSIGNED_ENUMERATED_BER_DEC        ossxBerDecUIntegerEnumerated
#define OSSX_LEAN_DECIMAL_REAL_BER_DEC               ossxBerDecDecimalReal
#define OSSX_LEAN_HUGE_INTEGER_BER_DEC               ossxBerDecUnboundedOctetString
#define OSSX_LEAN_ENCODED_OBJECT_IDENTIFIER_BER_DEC  ossxBerDecUnboundedOctetString
#define OSSX_LEAN_ENCODED_RELATIVE_OID_BER_DEC       ossxBerDecUnboundedOctetString
#define OSSX_LEAN_LONGLONG_INTEGER_BER_DEC           ossxBerDecLLInteger
#define OSSX_LEAN_UNSIGNED_LONGLONG_INTEGER_BER_DEC  ossxBerDecULLInteger
#define OSSX_LEAN_ANY_INTEGER_BER_DEC                ossxBerDecAnyInteger
#define OSSX_LEAN_UNSIGNED_ANY_INTEGER_BER_DEC       ossxBerDecUAnyInteger
#define OSSX_LEAN_DLINKED_PLUS_LIST_BER_DEC	ossxBerDecDlinkedPlusList

extern void ossxBerDecTypeNotSupported(void);
extern void ossxBerDecNull(void);
extern void ossxBerDecDlinkedPlusList(void);
extern void ossxBerDecIntegerEnumerated(void);
extern void ossxBerDecUIntegerEnumerated(void);
extern void ossxBerDecBoolean(void);
extern void ossxBerDecUnboundedOctetString(void);
extern void ossxBerDecSequence(void);
extern void ossxBerDecChoice(void);
extern void ossxBerDecLinkedUnboundedList(void);
extern void ossxBerDecReal(void);
extern void ossxBerDecDecimalReal(void);
extern void ossxBerDecLLInteger(void);
extern void ossxBerDecULLInteger(void);
extern void ossxBerDecAnyInteger(void);
extern void ossxBerDecUAnyInteger(void);

/* BER encoder function references */
#define OSSX_LEAN_TYPE_NOT_SUPPORTED_BER_ENC         ossxBerEncTypeNotSupported
#define OSSX_LEAN_INTEGER_BER_ENC                    ossxBerEncIntegerEnumerated
#define OSSX_LEAN_NULL_BER_ENC                       ossxBerEncNull
#define OSSX_LEAN_ENUMERATED_BER_ENC                 ossxBerEncIntegerEnumerated
#define OSSX_LEAN_REAL_BER_ENC                       ossxBerEncReal
#define OSSX_LEAN_BOOLEAN_BER_ENC                    ossxBerEncBoolean
#define OSSX_LEAN_SEQUENCE_BER_ENC                   ossxBerEncSequence
#define OSSX_LEAN_CHOICE_BER_ENC                     ossxBerEncChoice
#define OSSX_LEAN_LINKED_LIST_BER_ENC         ossxBerEncLinkedList
#define OSSX_LEAN_UNBOUNDED_LIST_BER_ENC      ossxBerEncUnboundedList
#define OSSX_LEAN_UNBOUNDED_OCTET_STRING_BER_ENC     ossxBerEncUnboundedOctetString
#define OSSX_LEAN_UNBOUNDED_CHARACTER_STRING_BER_ENC ossxBerEncUnboundedOctetString
#define OSSX_LEAN_UNSIGNED_INTEGER_BER_ENC           ossxBerEncUIntegerEnumerated
#define OSSX_LEAN_UNSIGNED_ENUMERATED_BER_ENC        ossxBerEncUIntegerEnumerated
#define OSSX_LEAN_DECIMAL_REAL_BER_ENC               ossxBerEncDecimalReal
#define OSSX_LEAN_HUGE_INTEGER_BER_ENC               ossxBerEncHugeInteger
#define OSSX_LEAN_ENCODED_OBJECT_IDENTIFIER_BER_ENC  ossxBerEncObjectIdentifier
#define OSSX_LEAN_ENCODED_RELATIVE_OID_BER_ENC       ossxBerEncObjectIdentifier
#define OSSX_LEAN_LONGLONG_INTEGER_BER_ENC           ossxBerEncLLInteger
#define OSSX_LEAN_UNSIGNED_LONGLONG_INTEGER_BER_ENC  ossxBerEncULLInteger
#define OSSX_LEAN_ANY_INTEGER_BER_ENC                ossxBerEncAnyInteger
#define OSSX_LEAN_UNSIGNED_ANY_INTEGER_BER_ENC       ossxBerEncUAnyInteger
#define OSSX_LEAN_DLINKED_PLUS_LIST_BER_ENC	ossxBerEncLinkedList

extern void ossxBerEncTypeNotSupported(void);
extern void ossxBerEncIntegerEnumerated(void);
extern void ossxBerEncNull(void);
extern void ossxBerEncUnboundedList(void);
extern void ossxBerEncObjectIdentifier(void);
extern void ossxBerEncReal(void);
extern void ossxBerEncBoolean(void);
extern void ossxBerEncSequence(void);
extern void ossxBerEncChoice(void);
extern void ossxBerEncLinkedList(void);
extern void ossxBerEncUnboundedOctetString(void);
extern void ossxBerEncUIntegerEnumerated(void);
extern void ossxBerEncDecimalReal(void);
extern void ossxBerEncHugeInteger(void);
extern void ossxBerEncLLInteger(void);
extern void ossxBerEncULLInteger(void);
extern void ossxBerEncAnyInteger(void);
extern void ossxBerEncUAnyInteger(void);

/* PER decoder function references */
#define OSSX_LEAN_TYPE_NOT_SUPPORTED_PER_DEC         ossxPerDecTypeNotSupported
#define OSSX_LEAN_INTEGER_PER_DEC                    ossxPerDecInteger
#define OSSX_LEAN_NULL_PER_DEC                       ossxPerDecNull
#define OSSX_LEAN_ENUMERATED_PER_DEC                 ossxPerDecEnumerated
#define OSSX_LEAN_REAL_PER_DEC                       ossxPerDecReal
#define OSSX_LEAN_BOOLEAN_PER_DEC                    ossxPerDecBoolean
#define OSSX_LEAN_SEQUENCE_PER_DEC                   ossxPerDecSequence
#define OSSX_LEAN_CHOICE_PER_DEC                     ossxPerDecChoice
#define OSSX_LEAN_LINKED_LIST_PER_DEC         ossxPerDecList
#define OSSX_LEAN_UNBOUNDED_LIST_PER_DEC      ossxPerDecUnboundedList
#define OSSX_LEAN_UNBOUNDED_OCTET_STRING_PER_DEC     ossxPerDecOctetString
#define OSSX_LEAN_UNBOUNDED_CHARACTER_STRING_PER_DEC ossxPerDecPrintableString
#define OSSX_LEAN_UNSIGNED_INTEGER_PER_DEC           ossxPerDecInteger
#define OSSX_LEAN_UNSIGNED_ENUMERATED_PER_DEC        ossxPerDecEnumerated
#define OSSX_LEAN_DECIMAL_REAL_PER_DEC               ossxPerDecCharReal
#define OSSX_LEAN_HUGE_INTEGER_PER_DEC               ossxPerDecHugeInteger
#define OSSX_LEAN_ENCODED_OBJECT_IDENTIFIER_PER_DEC  ossxPerDecObjectIdentifier
#define OSSX_LEAN_ENCODED_RELATIVE_OID_PER_DEC       ossxPerDecObjectIdentifier
#define OSSX_LEAN_LONGLONG_INTEGER_PER_DEC           ossxPerDecLLInteger
#define OSSX_LEAN_UNSIGNED_LONGLONG_INTEGER_PER_DEC  ossxPerDecLLInteger
#define OSSX_LEAN_ANY_INTEGER_PER_DEC                ossxPerDecAnyInteger
#define OSSX_LEAN_UNSIGNED_ANY_INTEGER_PER_DEC       ossxPerDecAnyInteger
#define OSSX_LEAN_DLINKED_PLUS_LIST_PER_DEC	ossxPerDecDlinkedPlusList

extern void ossxPerDecTypeNotSupported(void);
extern void ossxPerDecInteger(void);
extern void ossxPerDecUnboundedList(void);
extern void ossxPerDecNull(void);
extern void ossxPerDecDlinkedPlusList(void);
extern void ossxPerDecObjectIdentifier(void);
extern void ossxPerDecEnumerated(void);
extern void ossxPerDecBoolean(void);
extern void ossxPerDecSequence(void);
extern void ossxPerDecChoice(void);
extern void ossxPerDecList(void);
extern void ossxPerDecOctetString(void);
extern void ossxPerDecPrintableString(void);
extern void ossxPerDecHugeInteger(void);
extern void ossxPerDecCharReal(void);
extern void ossxPerDecReal(void);
extern void ossxPerDecLLInteger(void);
extern void ossxPerDecAnyInteger(void);

/* PER encoder function references */
#define OSSX_LEAN_TYPE_NOT_SUPPORTED_PER_ENC         ossxPerEncTypeNotSupported
#define OSSX_LEAN_INTEGER_PER_ENC                    ossxPerEncInteger
#define OSSX_LEAN_NULL_PER_ENC                       ossxPerEncNull
#define OSSX_LEAN_ENUMERATED_PER_ENC                 ossxPerEncEnumerated
#define OSSX_LEAN_REAL_PER_ENC                       ossxPerEncReal
#define OSSX_LEAN_BOOLEAN_PER_ENC                    ossxPerEncBoolean
#define OSSX_LEAN_SEQUENCE_PER_ENC                   ossxPerEncSequence
#define OSSX_LEAN_CHOICE_PER_ENC                     ossxPerEncChoice
#define OSSX_LEAN_LINKED_LIST_PER_ENC         ossxPerEncList
#define OSSX_LEAN_UNBOUNDED_LIST_PER_ENC      ossxPerEncUnboundedList
#define OSSX_LEAN_UNBOUNDED_OCTET_STRING_PER_ENC     ossxPerEncOctetString
#define OSSX_LEAN_UNBOUNDED_CHARACTER_STRING_PER_ENC ossxPerEncPrintableString
#define OSSX_LEAN_UNSIGNED_INTEGER_PER_ENC           ossxPerEncInteger
#define OSSX_LEAN_UNSIGNED_ENUMERATED_PER_ENC        ossxPerEncEnumerated
#define OSSX_LEAN_DECIMAL_REAL_PER_ENC               ossxPerEncCharReal
#define OSSX_LEAN_HUGE_INTEGER_PER_ENC               ossxPerEncHugeInteger
#define OSSX_LEAN_ENCODED_OBJECT_IDENTIFIER_PER_ENC  ossxPerEncObjectIdentifier
#define OSSX_LEAN_ENCODED_RELATIVE_OID_PER_ENC       ossxPerEncObjectIdentifier
#define OSSX_LEAN_LONGLONG_INTEGER_PER_ENC           ossxPerEncLLInteger
#define OSSX_LEAN_UNSIGNED_LONGLONG_INTEGER_PER_ENC  ossxPerEncLLInteger
#define OSSX_LEAN_ANY_INTEGER_PER_ENC                ossxPerEncAnyInteger
#define OSSX_LEAN_UNSIGNED_ANY_INTEGER_PER_ENC       ossxPerEncAnyInteger
#define OSSX_LEAN_DLINKED_PLUS_LIST_PER_ENC	ossxPerEncList

extern void ossxPerEncInteger(void);
extern void ossxPerEncUnboundedList(void);
extern void ossxPerEncNull(void);
extern void ossxPerEncObjectIdentifier(void);
extern void ossxPerEncEnumerated(void);
extern void ossxPerEncBoolean(void);
extern void ossxPerEncSequence(void);
extern void ossxPerEncChoice(void);
extern void ossxPerEncList(void);
extern void ossxPerEncOctetString(void);
extern void ossxPerEncPrintableString(void);
extern void ossxPerEncHugeInteger(void);
extern void ossxPerEncReal(void);
extern void ossxPerEncCharReal(void);
extern void ossxPerEncTypeNotSupported(void);
extern void ossxPerEncLLInteger(void);
extern void ossxPerEncAnyInteger(void);


/* XML decoder function references */
#define OSSX_LEAN_TYPE_NOT_SUPPORTED_XML_DEC         ossxXMlDecTypeNotSupported
#define OSSX_LEAN_INTEGER_XML_DEC                    ossxXMlDecInteger
#define OSSX_LEAN_NULL_XML_DEC                       ossxXMlDecNull
#define OSSX_LEAN_ENUMERATED_XML_DEC                 ossxXMlDecInteger
#define OSSX_LEAN_REAL_XML_DEC                       ossxXMlDecReal
#define OSSX_LEAN_BOOLEAN_XML_DEC                    ossxXMlDecBoolean
#define OSSX_LEAN_SEQUENCE_XML_DEC                   ossxXMlDecSequence
#define OSSX_LEAN_CHOICE_XML_DEC                     ossxXMlDecChoice
#define OSSX_LEAN_LINKED_LIST_XML_DEC         ossxXMlDecLinkedUnboundedList
#define OSSX_LEAN_UNBOUNDED_LIST_XML_DEC      ossxXMlDecLinkedUnboundedList
#define OSSX_LEAN_UNBOUNDED_OCTET_STRING_XML_DEC     ossxXMlDecUnboundedOctetString
#define OSSX_LEAN_UNBOUNDED_CHARACTER_STRING_XML_DEC ossxXMlDecUnboundedCharString
#define OSSX_LEAN_UNSIGNED_INTEGER_XML_DEC           ossxXMlDecInteger
#define OSSX_LEAN_UNSIGNED_ENUMERATED_XML_DEC        ossxXMlDecInteger
#define OSSX_LEAN_DECIMAL_REAL_XML_DEC               ossxXMlDecCharReal
#define OSSX_LEAN_HUGE_INTEGER_XML_DEC               ossxXMlDecHugeInteger
#define OSSX_LEAN_ENCODED_OBJECT_IDENTIFIER_XML_DEC  ossxXMlDecEncodedObjid
#define OSSX_LEAN_ENCODED_RELATIVE_OID_XML_DEC       ossxXMlDecEncodedObjid
#define OSSX_LEAN_LONGLONG_INTEGER_XML_DEC           ossxXMlDecLLInteger
#define OSSX_LEAN_UNSIGNED_LONGLONG_INTEGER_XML_DEC  ossxXMlDecLLInteger
#define OSSX_LEAN_ANY_INTEGER_XML_DEC                ossxXMlDecAnyInteger
#define OSSX_LEAN_UNSIGNED_ANY_INTEGER_XML_DEC       ossxXMlDecAnyInteger
#define OSSX_LEAN_DLINKED_PLUS_LIST_XML_DEC	 ossxXMlDecDlinkedPlusList

extern void ossxXMlDecTypeNotSupported(void);
extern void ossxXMlDecNull(void);
extern void ossxXMlDecDlinkedPlusList(void);
extern void ossxXMlDecEncodedObjid(void);
extern void ossxXMlDecSeq(void);
extern void ossxXMlDecInteger(void);
extern void ossxXMlDecBoolean(void);
extern void ossxXMlDecUnboundedOctetString(void);
extern void ossxXMlDecHugeInteger(void);
extern void ossxXMlDecUnboundedCharString(void);
extern void ossxXMlDecSequence(void);
extern void ossxXMlDecChoice(void);
extern void ossxXMlDecLinkedUnboundedList(void);
extern void ossxXMlDecReal(void);
extern void ossxXMlDecCharReal(void);
extern void ossxXMlDecLLInteger(void);
extern void ossxXMlDecAnyInteger(void);

/* XML encoder function references */
#define OSSX_LEAN_TYPE_NOT_SUPPORTED_XML_ENC         ossxXMlEncTypeNotSupported
#define OSSX_LEAN_INTEGER_XML_ENC                    ossxXMlEncInteger
#define OSSX_LEAN_NULL_XML_ENC                       ossxXMlEncNull
#define OSSX_LEAN_ENUMERATED_XML_ENC                 ossxXMlEncEnumerated
#define OSSX_LEAN_REAL_XML_ENC                       ossxXMlEncReal
#define OSSX_LEAN_BOOLEAN_XML_ENC                    ossxXMlEncNormalEnum
#define OSSX_LEAN_SEQUENCE_XML_ENC                   ossxXMlEncSequence
#define OSSX_LEAN_CHOICE_XML_ENC                     ossxXMlEncChoice
#define OSSX_LEAN_LINKED_LIST_XML_ENC         ossxXMlEncLinkedList
#define OSSX_LEAN_UNBOUNDED_LIST_XML_ENC      ossxXMlEncUnboundedList
#define OSSX_LEAN_UNBOUNDED_OCTET_STRING_XML_ENC     ossxXMlEncUnboundedOctetString
#define OSSX_LEAN_UNBOUNDED_CHARACTER_STRING_XML_ENC ossxXMlEncUnboundedCharString
#define OSSX_LEAN_UNSIGNED_INTEGER_XML_ENC           ossxXMlEncInteger
#define OSSX_LEAN_UNSIGNED_ENUMERATED_XML_ENC        ossxXMlEncEnumerated
#define OSSX_LEAN_DECIMAL_REAL_XML_ENC               ossxXMlEncDecimalReal
#define OSSX_LEAN_HUGE_INTEGER_XML_ENC               ossxXMlEncHugeInteger
#define OSSX_LEAN_ENCODED_OBJECT_IDENTIFIER_XML_ENC  ossxXMlEncObjectIdentifier
#define OSSX_LEAN_ENCODED_RELATIVE_OID_XML_ENC       ossxXMlEncObjectIdentifier
#define OSSX_LEAN_LONGLONG_INTEGER_XML_ENC           ossxXMlEncInteger
#define OSSX_LEAN_UNSIGNED_LONGLONG_INTEGER_XML_ENC  ossxXMlEncInteger
#define OSSX_LEAN_ANY_INTEGER_XML_ENC                ossxXMlEncInteger
#define OSSX_LEAN_UNSIGNED_ANY_INTEGER_XML_ENC       ossxXMlEncInteger
#define OSSX_LEAN_DLINKED_PLUS_LIST_XML_ENC	 ossxXMlEncLinkedList

extern void ossxXMlEncTypeNotSupported(void);
extern void ossxXMlEncInteger(void);
extern void ossxXMlEncEnumerated(void);
extern void ossxXMlEncNull(void);
extern void ossxXMlEncUnboundedList(void);
extern void ossxXMlEncObjectIdentifier(void);
extern void ossxXMlEncReal(void);
extern void ossxXMlEncSequence(void);
extern void ossxXMlEncChoice(void);
extern void ossxXMlEncLinkedList(void);
extern void ossxXMlEncUnboundedOctetString(void);
extern void ossxXMlEncUnboundedCharString(void);
extern void ossxXMlEncDecimalReal(void);
extern void ossxXMlEncHugeInteger(void);
extern void ossxXMlEncAnyInteger(void);


/* XML decoder i-kind function references */
#define OSSX_LEAN_NORMAL_INT_XML_DEC		ossxXMlDecTypeNotSupported
#define OSSX_LEAN_NORMAL_ENUM_XML_DEC		ossxXMlDecTypeNotSupported
#define OSSX_LEAN_NORMAL_UNBND_CHAR_XML_DEC		ossxXMlDecNormalUnbndChar
#define OSSX_LEAN_BASE64_UNBND_OCTET_XML_DEC	ossxXMlDecBase64UnbndOctetString
#define OSSX_LEAN_NORMAL_UNBND_OCTET_XML_DEC	ossxXMlDecNormalUnbndOctetString
#define OSSX_LEAN_ANYEL_NLLTRM_CHAR_XML_DEC		ossxXMlDecAnyElementCharString
#define OSSX_LEAN_USEORDER_SEQ_XML_DEC		ossxXMlDecSeq
#define OSSX_LEAN_QNAME_SEQ_XML_DEC			ossxXMlDecQnameSequence
#define OSSX_LEAN_NORMAL_SEQ_XML_DEC		ossxXMlDecNormalSequence
#define OSSX_LEAN_ANYATTR_LINK_SOF_XML_DEC		ossxXMlDecAnyAttrUnbndCharString
#define OSSX_LEAN_NORMAL_LINK_SOF_XML_DEC		ossxXMlDecTypeNotSupported
#define OSSX_LEAN_MODIFIED_REAL_XML_DEC		ossxXMlDecTypeNotSupported
#define OSSX_LEAN_DECIMAL_CHAR_REAL_XML_DEC		ossxXMlDecTypeNotSupported
#define OSSX_LEAN_NORMAL_LONGLONG_INT_XML_DEC	ossxXMlDecTypeNotSupported
#define OSSX_LEAN_NORMAL_LONGLONG_ENUM_XML_DEC	ossxXMlDecTypeNotSupported
#define OSSX_LEAN_NORMAL_ANY_INT_XML_DEC		ossxXMlDecTypeNotSupported
#define OSSX_LEAN_NORMAL_ANY_ENUM_XML_DEC		ossxXMlDecTypeNotSupported

/* ossxLeanCopyValue - is used for USE-UNION & DEFAULT-FOR-EMPTY *
 * generate instead of OSSX_LEAN_NORMAL_PAD_CHAR_XML_DEC            */
#define OSSX_LEAN_CPY_VAL_XML_DEC			ossxLeanCopyValue


extern void ossxXMlDecNormalUnbndChar(void);
extern void ossxXMlDecAnyElementCharString(void);
extern void ossxXMlDecNormalSequence(void);
extern void ossxXMlDecQnameSequence(void);
extern void ossxXMlDecAnyAttrUnbndCharString(void);
extern void ossxXMlDecNormalUnbndOctetString(void);
extern void ossxXMlDecBase64UnbndOctetString(void);
extern void ossxLeanCopyValue(void);

/* XML encoder i-kind function references */
#define OSSX_LEAN_NORMAL_INT_XML_ENC		ossxXMlEncNormalInteger
#define OSSX_LEAN_NORMAL_ENUM_XML_ENC		ossxXMlEncNormalEnum
#define OSSX_LEAN_NORMAL_UNBND_CHAR_XML_ENC		ossxXMlEncNormalUnbndChar
#define OSSX_LEAN_BASE64_UNBND_OCTET_XML_ENC	ossxXMlEncBase64UnbndOctet
#define OSSX_LEAN_NORMAL_UNBND_OCTET_XML_ENC	ossxXMlEncNormalUnbndOctet
#define OSSX_LEAN_ANYEL_NLLTRM_CHAR_XML_ENC		ossxXMlEncAnyelUnbndChar
#define OSSX_LEAN_USEORDER_SEQ_XML_ENC		ossxXMlEncTypeNotSupported
#define OSSX_LEAN_QNAME_SEQ_XML_ENC			ossxXMlEncQNnameSeq
#define OSSX_LEAN_NORMAL_SEQ_XML_ENC		ossxXMlEncTypeNotSupported
#define OSSX_LEAN_ANYATTR_LINK_SOF_XML_ENC		ossxXMlEncAnyattrUnbndChar
#define OSSX_LEAN_NORMAL_LINK_SOF_XML_ENC		ossxXMlEncTypeNotSupported
#define OSSX_LEAN_MODIFIED_REAL_XML_ENC		ossxXMlEncTypeNotSupported
#define OSSX_LEAN_DECIMAL_CHAR_REAL_XML_ENC		ossxXMlEncTypeNotSupported
#define OSSX_LEAN_NORMAL_LONGLONG_INT_XML_ENC	ossxXMlEncAnyInteger
#define OSSX_LEAN_NORMAL_LONGLONG_ENUM_XML_ENC	ossxXMlEncAnyEnum
#define OSSX_LEAN_NORMAL_ANY_INT_XML_ENC		ossxXMlEncAnyInteger
#define OSSX_LEAN_NORMAL_ANY_ENUM_XML_ENC		ossxXMlEncAnyEnum

extern void ossxXMlEncNormalInteger(void);
extern void ossxXMlEncAnyInteger(void);
extern void ossxXMlEncNormalEnum(void);
extern void ossxXMlEncAnyEnum(void);
extern void ossxXMlEncNormalUnbndChar(void);
extern void ossxXMlEncNormalUnbndOctet(void);
extern void ossxXMlEncBase64UnbndOctet(void);
extern void ossxXMlEncAnyelUnbndChar(void);
extern void ossxXMlEncQNnameSeq(void);
extern void ossxXMlEncAnyattrUnbndChar(void);

#endif /* DLL_LINKAGE */

/*******************************************************
 * Declarations of link routines that are needed       *
 * to link the given encoding methods or rules specified *
 * on the compiler command line. Function calls        *
 * are generated by the compiler to _ossxinit_...()     *
 * in the control table.  These functions are not      *
 * meant to be referenced in user code.                *
 *******************************************************/
PUBLIC void DLL_ENTRY ossxLinkBerDec(OssxEnv *, int, const void **);
PUBLIC void DLL_ENTRY ossxLinkBerEnc(OssxEnv *, int, const void **);
PUBLIC void DLL_ENTRY ossxLinkPerDec(OssxEnv *, int, const void **);
PUBLIC void DLL_ENTRY ossxLinkPerEnc(OssxEnv *, int, const void **);
PUBLIC void DLL_ENTRY ossxLinkLeanMemoryManager(OssxEnv *);
PUBLIC void DLL_ENTRY ossxCheckFeaturesUsed(OssxEnv *, int,
							const unsigned char *);
PUBLIC void DLL_ENTRY ossxLinkXmlDec(OssxEnv *, void *, int, const void **,
							const void **);

PUBLIC void DLL_ENTRY ossxLinkXmlEnc(OssxEnv *, void *, int, const void **,
							const void **);
#define ossxLinkLeanMemoryManager() ossxLinkLeanMemoryManager(world)

#endif /* OSSXLTYPE_H */
