/*
 * Copyright (C) 1995-2006 OSS Nokalva, Inc.  All rights reserved.
 *
 * FILE: @(#)ossxixapi.h	14.5  05/09/30
*/

/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC. AND
 * MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.
 * THIS FILE MAY NOT BE DISTRIBUTED. */

/*****************************************************************************/
/*                                                                           */
/*           Declare the types used in the Interpretive XSD API            */
/*                                                                           */
/*****************************************************************************/
#ifndef OSSXIXAPI_H
#define OSSXIXAPI_H

#include "ossxsd.h"

typedef void *OssxTypeHndl;		/* handle used in referencing types */
typedef void *OssxFieldHndl;

#define OSSX_INDEFLENGTH   -1       /* This value is returned by ossxEncodingLength()
                                * for OSSX_INDEFINITE length encoded values. */

#define OSSX_BADLENGTH     -2       /* This value is returned by ossxEncodingLength(),
                                * ossxEncodingIdentifierLength(), and
				* ossxEncodingHeaderLength() in the case of a
				* misencoded value or zero length encoding */

/* XSD builtin types sorted alphabetically and assigned an enumerator */

typedef enum XSDType { 
	xsdUnknownType = 0,
	xsdANY = 1,                            xsdOCTET_STRING = 19,
	xsdBIT_STRING = 2,                     xsdObjectDescriptor = 20,
	xsdBMPString = 3,                      xsdOpenType = 21,
	xsdBOOLEAN = 4,                        xsdPrintableString = 22,
	xsdCHARACTER_STRING = 5,               xsdREAL = 23,
	xsdCHOICE = 6,                         xsdSEQUENCE = 24,
	xsdEMBEDDED_PDV = 7,                   xsdSEQUENCE_OF = 25,
	xsdENUMERATED = 8,                     xsdSET = 26,
	xsdEXTERNAL = 9,                       xsdSET_OF = 27,
	xsdGeneralString = 10,                 xsdTeletexString = 28,
	xsdGeneralizedTime = 11,               xsdUTCTime = 29,
	xsdGraphicString = 12,                 xsdUniversalString = 30,
	xsdIA5String = 13,                     xsdVideotexString = 31,
	xsdINSTANCE_OF = 14,                   xsdVisibleString = 32,
	xsdINTEGER = 15,                       xsdUTF8String = 33,
	xsdNULL = 16,                          xsdRELATIVE_OID = 34,
	xsdNumericString = 17,                 xsdCLASS = 35,
	xsdOBJECT_IDENTIFIER = 18,             xsdArbitraryType = 36
} XSDType;


/* Types compatible codes */
typedef enum OssxTypesCompatibilityCodes {
    ossxCompatible = 0,                 /* Types are compatible */
    ossxDifferentTypes = 1,              /* Types are not identical */
    ossxDefaultsDifferent = 2,           /* Default values are not the same */
    ossxOnlyOneHasDefault = 3,           /* Only one type has a default value */
    ossxOneHasPointerOtherDoesnt = 4,    /* Only one type has a POINTER directive */
    ossxNumberOfComponentsDifferent = 5, /* Different number of components */
    ossxOneIsOptionalOtherIsnt = 6,      /* Only one type is OPTIONAL */
    ossxOneIsExtensibleOtherIsnt = 7,    /* Only one type is extensible */
    ossxDifferentNamedItems = 8,         /* Different component identifiers */
    ossxDifferentKinds = 9,              /* Different type representations */
    ossxComponentsHaveDifferentKinds = 10,/* Different component representations */
    ossxDifferentSubIdNumber = 11,       /* Different number of sub-identifiers in
                                      * an OBJECT IDENTIFIER with the OBJECTID
                                      * directive */
    ossxDifferentSubIdTypes = 12,        /* Different types of sub-identifiers in
                                      * an OBJECT IDENTIFIER with the OBJECTID
                                      * directive */
    ossxDifferentSize = 13,              /* Different size of INTEGER or REAL values */
    ossxType1IsPointerOfTypeRef2 = 14,   /* Two types reference the other
                                      * type but the first one has the
                                      * POINTER directive */
    ossxType2IsPointerOfTypeRef1 = 15,   /* Two types reference the other type
                                      * but the second one has the POINTER
                                      * directive */
    ossxDifferentSizeOfLengthField = 16, /* Different sizes of the length field in
                                      * type representations */
    ossxDifferentRulesInEncodedBy = 17,  /* Different encoding methods specified in
                                      * ENCODED BY of ContentsConstraint. */
    ossxDifferentContainedTypes = 18     /* Different contained types in
                                      * ContentsConstraint. */
} OssxTypesCompatibilityCodes;


/* XSD tag classes */
typedef enum XSDTagClass {
	OSSX_UNIVERSAL, OSSX_APPLICATION, OSSX_CONTEXT_SPECIFIC,
	OSSX_PRIVATE, OSSX_NULLENCODING
} XSDTagClass;


typedef int IXAPI_ERRTYPE;     /* Datatype for IXAPI error codes */

/* IXAPI ERROR CODES */
#define IXAPI_NOERROR      0   /* No error occurred */
#define IXAPI_OUTMEMORY    1   /* No more memory can be allocated */
#define IXAPI_MEM_ERROR    2   /* Memory violation error occurred */
#define IXAPI_ACCESS_SERIALIZATION 3 /* Access serialization error occurred */
#define IXAPI_BADNULL      4   /* Not "NULL" value */
#define IXAPI_TOOBIG       5   /* Value exceeds size constraint */
#define IXAPI_BADREAL      6   /* Not a valid REAL value */
#define IXAPI_BADTIME      7   /* Not a valid UTCTime or GeneralizedTime */
#define IXAPI_BADOBJID     8   /* Not a valid OBJECT IDENTIFIER value */
#define IXAPI_BADANY       9   /* Bad ANY or OssxOpenType value */
#define IXAPI_BADNAME     10   /* Bad INTEGER or ENUMERATED name */
#define IXAPI_BADNMD      11   /* Bad BIT STRING NAMED NUMBER value */
#define IXAPI_NOTSUP      12   /* Type not supported */
#define IXAPI_BADNUM      13   /* Bad INTEGER or ENUMERATED number */
#define IXAPI_BADINDX     14   /* Bad component index into a structured type */
#define IXAPI_BADDEC      15   /* Bad decoded value, possibly NULL */
#define IXAPI_ENCFAL      16   /* Failure to encode value */
#define IXAPI_NLENC       17   /* Null encoding or length is 0 */
#define IXAPI_DECFAL      18   /* Decoding failed */
#define IXAPI_BADTGINDX   19   /* Bad tag number index into encoded value */
#define IXAPI_BADTYPE     20   /* Incorrect type handle for the function */
#define IXAPI_CPYFAIL     21   /* Copying a decoded value failed */
#define IXAPI_NOTCOMPATIBLE   22 /* Types are not compatible */
#define IXAPI_BADDISPLAYVALUE 23 /* Failure to parse a Global Element display value */
#define IXAPI_BADIDENTIFIER   24 /* Bad identifier in a parsing display value */
#define IXAPI_DUPLCOMPVALUE   25 /* Duplicate value for one component in a parsing value*/
#define IXAPI_ENCOPENTYPEORANYFAILED 26 /* Encoding failed for ANY or open type value*/
#define IXAPI_FREETPFAL   27   /* Failure to free decoded value */
#define IXAPI_BADCHOICE   28   /* Invalid value notation of CHOICE type */
#define IXAPI_BADHINT     29   /* Bad HUGE INTEGER value */
#define IXAPI_BADENCOID   30   /* Bad ENCODED OBJECT IDENTIFIER value */
#define IXAPI_BADOBJ      31   /* Object can not be marked */
#define IXAPI_UNKNOWNOBJ  32   /* Invalid object handle */
#define IXAPI_BADBIT      33   /* Bad bit string or hex string */
#define IXAPI_BADBOOLEAN  34   /* Not TRUE or FALSE value */
#define IXAPI_LENTOOLONG  35   /* Length of encoding too long */
#define IXAPI_NOEOC       36   /* EOC not found for indefinite length encoding */
#define IXAPI_BADEOC      37   /* EOC with non-zero second octet */
#define IXAPI_BADHEADER   38   /* Length of tag-length pair exceeds remaining
				* data length */
#define IXAPI_BADSTRUCTVALUE 39/* Value notation of SET or SEQUENCE or LIST or
				* LIST has no opening or closing brace */
#define IXAPI_BADCSTRINGLIST 40/* Bad CharacterStringList or control char value */
#define IXAPI_NOMANDATORY    41/* Not all values of mandatory components are
				* present in the value notation of SET or
				* SEQUENCE type */
#define IXAPI_ABSENT_IDENTIFIER 42 /* Identifier is missing in value notation
				* of SET or SEQUENCE type */
#define IXAPI_NOTYPEREF	     43/* Missing type reference name in ANY or opentype */
#define IXAPI_BADOBJVALUE    44/* Invalid display value of a marked object */
#define IXAPI_CANT_OPEN_FILE 45/* Input file cannot be opened */
#define IXAPI_ERROR_READING_FROM_FILE 46 /* Error reading from input file */
#define IXAPI_BADOFFSET   47   /* Invalid offset into input file */
#define IXAPI_BADSIZE     48   /* Invalid number of bytes to be read from input
                                * file */
#define IXAPI_NONHEX      49   /* Input text file with encoding contains 
                                * non-hexadecimal characters */
#define IXAPI_INT_TOO_LONG 50  /* Interger value is out of range */
#define IXAPI_BAD_ABSREF 	51  /* Bad absolute reference format */
#define IXAPI_BAD_TYPEREF_NAME	52  /* Bad type reference name */
#define IXAPI_BAD_COMPID	53  /* Bad identifier in SEQUENCE, or CHOICE */
#define IXAPI_BAD_PARENT_TYPE	54  /* Bad type handle of parent type */
#define IXAPI_BAD_COMP_TYPE	55  /* Bad type handle of component */
#define IXAPI_BAD_COMP_VALUE	56  /* Bad component value, possibly NULL */
#define IXAPI_BADENCRELOID	57  /* Bad ENCODED Relative OID value */
#define IXAPI_NODEBUG           58  /* nodebug was specified */
#define IXAPI_BAD_INFO_OBJ_NAME     59  /* invalid input object name */
#define IXAPI_NO_TABLE_CONSTRAINT   60  /* field has not table constraint */
#define IXAPI_INFO_OBJECT_NOT_FOUND 61  /* info object was not found */
#define IXAPI_INFO_OBJSET_NOT_FOUND 62  /* info object set was not found */
#define IXAPI_INFO_OBJSET_NOT_EXTENSIBLE  63 /* info object set is not extensible */
#define IXAPI_BADARG                      64 /* bad argument, possibly a NULL value */
#define IXAPI_INFO_OBJ_NOT_SUPPORTED      65 /* control tables generated by the old
                                              * compiler without support for info
                                              * object classes, sets and objects */
#define IXAPI_CANT_REMOVE_ROOT_INFO_OBJ   66 /* only info objects that appear 
                                              * after extension marker caan be
                                              * removed */
#define IXAPI_CANT_COPY_INFO_OBJSET_TABLE 67 /* cannot create a copy of info 
                                              * object set table */
#define IXAPI_INFO_OBJ_UNIQUE_FIELD_NOT_FOUND 68 /* no UNIQUE field found */
#define IXAPI_INFO_OBJECT_ALREADY_EXISTS      69 /* object already exists */
#define IXAPI_CMPFAIL                         70 /* Comparing values failed */
#define IXAPI_IMPLEMENTATION_LIMIT_EXCEEDED   71 /* internal buffer exhausted */
#define IXAPI_ERROR_WRITING_TO_FILE           72 /* Error writing to output file */
#define IXAPI_BAD_ZERO_TAG                    73 /* "00" tag is detected */

#if defined(_MSC_VER) && (defined(WINCE) || defined(_WIN64))
#pragma pack(push, ossxPacking, 8)
#elif defined(_MSC_VER) && (defined(_WIN32) || defined(WIN32))
#pragma pack(push, ossxPacking, 4)
#elif defined(_MSC_VER) && (defined(_WINDOWS) || defined(_MSDOS))
#pragma pack(1)
#elif defined(__BORLANDC__) && defined(__MSDOS__)
#pragma option -a1
#elif defined(__BORLANDC__) && defined(__WIN32__)
#pragma option -a4
#elif defined(__IBMC__) && (defined(__WIN32__) || defined(__OS2__))
#pragma pack(4)
#elif defined(__WATCOMC__) && defined(__NT__)
#pragma pack(push, 4)
#elif defined(__WATCOMC__) && (defined(__WINDOWS__) || defined(__DOS__))
#pragma pack(push, 1)
#endif /* _MSC_VER && _WIN32 */

#ifdef macintosh
#pragma options align=mac68k
#endif


/* Structure for holding values of type INTEGER */
typedef struct OssxIntValue {
    enum {ossxSignedNumber, ossxUnsignedNumber} sign;
    union {
	LONG_LONG       signedInt;
	ULONG_LONG      unsignedInt;
    } value;
} OssxIntValue;


/* Structure for IXAPI initialization values */
typedef struct IXAPI_initializers {
           char         charInitializer;
           short        shortInitializer;
           int          intInitializer;
           long         longInitializer;
           LONG_LONG    llongInitializer;
           void       * pointerInitializer;
           char       * floatInitializer;
           char       * doubleInitializer;
} IXAPI_initializers;

/*
 * Type definition for a value reference structure.
 */
typedef struct OssxValRef {
   char *name;            /* value reference name */
   void *address;         /* pointer to decoded value */
   unsigned short etype;  /* index into etype array */
} OssxValRef;


#if defined(_MSC_VER) && (defined(_WIN32) || defined(WIN32) || defined(WINCE) || defined(_WIN64))
#pragma pack(pop, ossxPacking)
#elif defined(_MSC_VER) && (defined(_WINDOWS) || defined(_MSDOS))
#pragma pack()
#elif defined(__BORLANDC__) && (defined(__WIN32__) || defined(__MSDOS__))
#pragma option -a.
#elif defined(__IBMC__) && (defined(__WIN32__) || defined(__OS2__))
#pragma pack()
#elif defined(__WATCOMC__) && (defined(__NT__) || defined(__WINDOWS__) || defined(__DOS__))
#pragma pack(pop)
#endif /* _MSC_VER && _WIN32 */

#ifdef macintosh
#pragma options align=reset
#endif


#if defined(macintosh) && defined(__CFM68K__)
#pragma import on
#endif

#ifdef __cplusplus
extern "C" {
#endif


/***************************************************/
/* Functions defined by the Interpretive XSD API */
/***************************************************/

extern int   DLL_ENTRY ossxDefaultIXAPI_ERR(OssxEnv *world, int err_code,
					char *parm, long num);
extern void *DLL_ENTRY ossxGetIxapiErrorHandlingFunction(OssxEnv *world);
extern void  DLL_ENTRY ossxSetIxapiErrorHandlingFunction(OssxEnv *world,
					int (DLL_ENTRY_FPTR *_System func)
					(OssxEnv *, int, char *, long));
extern void  DLL_ENTRY ossxSetInitializationValues(OssxEnv *world,
					IXAPI_initializers *initStruct);
extern void  DLL_ENTRY ossxTermIXAPI(OssxEnv *world);

extern unsigned short DLL_ENTRY ossxCtlTblVersionNumber(OssxEnv *world);
extern ossxBoolean  DLL_ENTRY ossxCtlTblUsableOnlyByPER(OssxEnv *world);
extern ossxBoolean  DLL_ENTRY ossxCtlTblUsableOnlyByBER(OssxEnv *world);
extern ossxBoolean  DLL_ENTRY ossxDebugWasSpecified(OssxEnv *world);
extern ossxBoolean  DLL_ENTRY ossxConstrainWasSpecified(OssxEnv *world);

extern int         DLL_ENTRY ossxNumberOfGlobElems(OssxEnv *world);
extern int	   DLL_ENTRY ossxNumberOfArtificialGlobElems(OssxEnv *world);
extern OssxTypeHndl    DLL_ENTRY ossxTypeHandleOfGlobElem(OssxEnv *world, int globElemNum);
extern OssxTypeHndl    DLL_ENTRY ossxGlobElemTypeHandleByName(OssxEnv *world, const char *name);
extern int         DLL_ENTRY ossxGlobElemNumberByType(OssxEnv *world, OssxTypeHndl type);
extern ossxBoolean  DLL_ENTRY ossxTypeIsConstrained(OssxEnv *world, OssxTypeHndl type);
extern int         DLL_ENTRY ossxXSDTypeId(OssxEnv *world, OssxTypeHndl type);
extern const char *DLL_ENTRY ossxBuiltinTypeName(OssxEnv *world, XSDType typeId);
extern const char *DLL_ENTRY ossxTypeReferenceName(OssxEnv *world, OssxTypeHndl type);
extern int         DLL_ENTRY ossxTypesCompatible(OssxEnv *world,
					OssxTypeHndl type1, OssxTypeHndl type2);

extern int         DLL_ENTRY ossxNumberOfNamedItems(OssxEnv *world, OssxTypeHndl type);
extern OssxTypeHndl    DLL_ENTRY ossxTypeHandleOfComponent(OssxEnv *world,
					OssxTypeHndl parent, unsigned int ix);
extern ossxBoolean  DLL_ENTRY ossxComponentIsOptional(OssxEnv *world,
					OssxTypeHndl type, unsigned int ix);
extern ossxBoolean  DLL_ENTRY ossxComponentHasDefaultValue(OssxEnv *world,
					OssxTypeHndl parentType, unsigned int ix);
extern void       *DLL_ENTRY ossxComponentDefaultValue(OssxEnv *world,
					OssxTypeHndl parentType, unsigned int ix);
extern ossxBoolean  DLL_ENTRY ossxComponentValueIsPresent(OssxEnv *world,
					OssxTypeHndl parentType, unsigned int ix,
					void *parentValue);
extern ossxBoolean  DLL_ENTRY ossxComponentIsInitializationValue(OssxEnv *world,
					OssxTypeHndl chldType, void *compAddress);
extern unsigned int DLL_ENTRY ossxItemIndexByName(OssxEnv *world,
					OssxTypeHndl type, const char *name);
extern const char *DLL_ENTRY ossxXSDItemName(OssxEnv *world, OssxTypeHndl type,
						unsigned int ix);
extern long        DLL_ENTRY ossxItemIntValue(OssxEnv *world, OssxTypeHndl type,
						unsigned int ix);

extern ossxBoolean  DLL_ENTRY ossxExtensionMarkerIsPresent(OssxEnv *world,
						OssxTypeHndl type);
extern int         DLL_ENTRY ossxNumberOfRootItems(OssxEnv *world, OssxTypeHndl type);
extern ossxBoolean  DLL_ENTRY ossxCompAppearsAfterExtensionMarker(OssxEnv *world,
						OssxTypeHndl type, unsigned int ix);
extern int         DLL_ENTRY ossxNumberOfTags(OssxEnv *world, OssxTypeHndl type);
extern int         DLL_ENTRY ossxXSDTagNumber(OssxEnv *world, OssxTypeHndl type,
						unsigned int ix);
extern int         DLL_ENTRY ossxXSDTagClass(OssxEnv *world, OssxTypeHndl type,
						unsigned int ix);

extern ossxBoolean  DLL_ENTRY ossxUpperBoundIsPresent(OssxEnv *world, OssxTypeHndl type);
extern ossxBoolean  DLL_ENTRY ossxLowerBoundIsPresent(OssxEnv *world, OssxTypeHndl type);
extern unsigned long DLL_ENTRY ossxLowerBoundOfSizeConstraint(OssxEnv *world,
							OssxTypeHndl type);
extern unsigned long DLL_ENTRY ossxUpperBoundOfSizeConstraint(OssxEnv *world,
							OssxTypeHndl type);

extern ossxBoolean DLL_ENTRY ossxMinValueOfInteger(OssxEnv *world, OssxTypeHndl type,
							OssxIntValue *val);
extern ossxBoolean DLL_ENTRY ossxMaxValueOfInteger(OssxEnv *world, OssxTypeHndl type,
							OssxIntValue *val);

extern unsigned long DLL_ENTRY ossxPermittedAlphabetLength(OssxEnv *world,
							OssxTypeHndl type);
extern const long   *DLL_ENTRY ossxPermittedAlphabetConstraint(OssxEnv *world,
							OssxTypeHndl type);

extern unsigned short DLL_ENTRY ossxGetNumberOfValueReferences(OssxEnv *world);
extern const char *DLL_ENTRY ossxGetNameOfValueReference(OssxEnv *world,
						unsigned short int compIndex);
extern const void *DLL_ENTRY ossxGetDecodedValueOfValueReference(OssxEnv *world,
						unsigned short int compIndex);
extern OssxTypeHndl    DLL_ENTRY ossxGetTypeHandleOfValueReference(OssxEnv *world,
						unsigned short int compIndex);

extern IXAPI_ERRTYPE DLL_ENTRY ossxDecodeValueNotationOfGlobElem( OssxEnv  *world,
				int globElemNum, OssxBuf *xsdValue, void **decValue);
extern IXAPI_ERRTYPE DLL_ENTRY ossxDecodeValueNotationOfType(OssxEnv *world,
				OssxTypeHndl type, OssxBuf *xsdValue, void **decValue);

extern char *DLL_ENTRY ossxGetValueNotationOfGlobElem(OssxEnv *world,
				int globElemNum, void *decodedValue);
extern char *DLL_ENTRY ossxGetValueNotationOfType(OssxEnv *world,
				OssxTypeHndl type, void *decodedValue);

extern IXAPI_ERRTYPE DLL_ENTRY ossxPutDecodedValueOfGlobElem(OssxEnv *world,
				int globElemNum, char *remainingBuf, void **globElemVal);
extern IXAPI_ERRTYPE DLL_ENTRY ossxPutSimpleTypeValue(OssxEnv *world,
				OssxTypeHndl type, char *userTypedvalue,
				void **decodedValue);
extern IXAPI_ERRTYPE DLL_ENTRY ossxPutStructTypeValue(OssxEnv *world,
				OssxTypeHndl parent, void *compValue,
				unsigned int compIndex, void **structToUpdate);
extern IXAPI_ERRTYPE DLL_ENTRY ossxPutStructTypeValueByComponentAbsRef(
				OssxEnv *world, OssxTypeHndl outerType,
				void *compValue, char *compAbsref, 
				void **outerStructToUpdate);
extern IXAPI_ERRTYPE DLL_ENTRY ossxDeleteComponent(OssxEnv *world,
				OssxTypeHndl parentType, unsigned int compIndex,
				void **parentValue);
extern IXAPI_ERRTYPE DLL_ENTRY ossxPutOpenTypeDecodedValue(OssxEnv *world,
				OssxTypeHndl type, int globElemNum, void *decodedValue,
				void **openValue);
extern IXAPI_ERRTYPE DLL_ENTRY ossxPutEncodedValue(OssxEnv *world,
				OssxTypeHndl type, OssxBuf encodedValue,
				void **decodedValue);

extern char *DLL_ENTRY ossxGetValueOfSimpleType(OssxEnv *world, OssxTypeHndl type,
				void *decodedValue);
extern void *DLL_ENTRY ossxUpdateValueOfSimpleType(OssxEnv *world,OssxTypeHndl type,
				char *userTypedValue, void *oldValue);
extern IXAPI_ERRTYPE DLL_ENTRY ossxGetDecodedValueOfComponent(OssxEnv *world,
				OssxTypeHndl parentType, void *parentDecodedValue,
				unsigned int compIndex, void **componentValue);
extern IXAPI_ERRTYPE DLL_ENTRY ossxGetComponentByAbsRef(OssxEnv *world, 
				char *compAbsref, void *parentValue,
				OssxTypeHndl *compType, void **compValue);
extern IXAPI_ERRTYPE DLL_ENTRY ossxPutComponentByAbsRef(OssxEnv *world, 
				char *compAbsref, void *parentValue,
				void *compValue);
extern IXAPI_ERRTYPE DLL_ENTRY ossxGetOpenTypeValue(OssxEnv *world,
				OssxTypeHndl type, void *openValue, int *globElemNum,
				void **decodedValue, OssxBuf *encodedValue);

extern IXAPI_ERRTYPE DLL_ENTRY ossxIxapiMarkObject(OssxEnv *world, OssxTypeHndl type,
				OssxObjType objectType, void *object);
extern OssxObjType    DLL_ENTRY ossxGetObjectType(OssxEnv *world,
				OssxTypeHndl type, void *object);
extern ossxBoolean    DLL_ENTRY ossxTypeIsExternalObject(OssxEnv *world,
				OssxTypeHndl type);
extern IXAPI_ERRTYPE DLL_ENTRY ossxSetTypeAsExternalObject(OssxEnv *world,
				OssxTypeHndl type, ossxBoolean marked);
extern IXAPI_ERRTYPE DLL_ENTRY ossxPutObjectValue(OssxEnv *world, OssxTypeHndl type,
				OssxBufExtended *objectValue, 
				OssxObjType objectType, void **decodedValue);
extern IXAPI_ERRTYPE DLL_ENTRY ossxGetObjectValue(OssxEnv *world, OssxTypeHndl type,
				void *decodedValue, OssxBufExtended *objValue);

extern ossxBoolean    DLL_ENTRY ossxValueIsValid(OssxEnv *world,
					OssxTypeHndl type, void *value);
extern unsigned long DLL_ENTRY ossxGetValueLength(OssxEnv *world,
					OssxTypeHndl type, void *value);
extern IXAPI_ERRTYPE DLL_ENTRY ossxCopyTypeValue(OssxEnv *world, OssxTypeHndl type,
					void *valueIn, void **valueOut);
extern IXAPI_ERRTYPE DLL_ENTRY ossxCmpTypeValue(OssxEnv *world, OssxTypeHndl type,
					void *value1, void *value2);

extern IXAPI_ERRTYPE DLL_ENTRY ossxValueEncode(OssxEnv *world, OssxTypeHndl type,
					void *value, OssxBuf *encodedValue);

extern IXAPI_ERRTYPE DLL_ENTRY ossxFreeDecodedValue(OssxEnv *world,
					OssxTypeHndl type, void *valPtr);
extern void DLL_ENTRY ossxFreeDisplayString(OssxEnv *world, char *dsplString);

extern ossxBoolean     DLL_ENTRY ossxEncodingIsConstructed(OssxEnv *world,
				unsigned char *curEnc, long bufLength);
extern unsigned char *DLL_ENTRY ossxGetNextBEREncoding(OssxEnv *world,
				unsigned char *curEnc, long *remBufLen);
extern unsigned char *DLL_ENTRY ossxGetNestedBEREncoding(OssxEnv *world,
				unsigned char *curEnc, long *remBufLen);
extern long           DLL_ENTRY ossxNumberOfEncodingTags(OssxEnv *world,
				unsigned char *curEnc, long bufLength);
extern XSDTagClass   DLL_ENTRY ossxEncodingXSDClass(OssxEnv *world, 
				unsigned char *curEnc, long bufLength, int ix);
extern long           DLL_ENTRY ossxEncodingXSDTag(OssxEnv *world,
				unsigned char *curEnc, long bufLength, int ix);
extern char          *DLL_ENTRY ossxEncodingXSDType(OssxEnv *world,
				unsigned char *curEnc, long bufLength);
extern int	      DLL_ENTRY ossxEncodingIdentifierLength(OssxEnv *world,
                                unsigned char *curEnc, long bufLength);
extern int	      DLL_ENTRY ossxEncodingHeaderLength(OssxEnv *world, 
				unsigned char *curEnc, long remBufLength);
extern long           DLL_ENTRY ossxEncodingLength(OssxEnv *world,
				unsigned char *curEnc, long bufLength);
extern char          *DLL_ENTRY ossxEncodingContents(OssxEnv *world,
				unsigned char *curEnc, long bufLength);

extern char  *DLL_ENTRY ossxConvertEncodingIntoDisplayHexFmt(OssxEnv *world,
				unsigned char *encodedBufin, long bufLength);
extern char  *DLL_ENTRY ossxConvertEncodingIntoDisplayBinFmt(OssxEnv *world,
				unsigned char *encodedBufin, long bufLength);
extern IXAPI_ERRTYPE DLL_ENTRY ossxConvertHexFmtToEncoding(OssxEnv *world,
				char *hexBufin, long bufLength, OssxBuf*encVal);
extern IXAPI_ERRTYPE DLL_ENTRY ossxConvertBinFmtToEncoding(OssxEnv *world,
				char *binBufin, long bufLength, OssxBuf *encVal);

extern IXAPI_ERRTYPE DLL_ENTRY ossxCreateUnencodedValueOfGlobElem(OssxEnv *world,
				int globElemNum, void **globElemValue);
extern IXAPI_ERRTYPE DLL_ENTRY ossxCreateUnencodedValueOfType(OssxEnv *world,
				OssxTypeHndl type, void **value);

/****************************************************/
/* Functions for syntaxes with EXTENDED XER support */
/****************************************************/
extern unsigned int DLL_ENTRY	ossxNumberOfNamespaces(OssxEnv *world);
extern char	   *DLL_ENTRY	ossxNamespaceURI(OssxEnv *world, unsigned int ix);
extern unsigned int DLL_ENTRY	ossxMainNamespaceIndex(OssxEnv *world);

/***************************************************************************
 * Functions to support user-allocated memory and to disable calls to      *
 * signal(), setjmp(), lomgjmp() and constraint checking in the IXAPI      *
 * functions.                                                              *
 ***************************************************************************/
extern IXAPI_ERRTYPE DLL_ENTRY	ossxPutStructTypeUserValue(OssxEnv *world,
				OssxTypeHndl parentType, void *userValue,
				unsigned int compIndex, void **structToUpdate);
extern IXAPI_ERRTYPE DLL_ENTRY	ossxUpdateStructTypeUserValue(OssxEnv *world,
				OssxTypeHndl parentType, void *userValue,
				unsigned int compIndex, void **structToUpdate);
extern IXAPI_ERRTYPE DLL_ENTRY	ossxFreeNonUserDecodedValue(OssxEnv *world,
					OssxTypeHndl type, void *valPtr);
extern void DLL_ENTRY		ossxRemoveUserValue(OssxEnv *world, void *valPtr);
extern void DLL_ENTRY		ossxRemoveUserValues(OssxEnv *world);
extern unsigned long DLL_ENTRY	ossxGetIXAPIFlags(OssxEnv *world);
extern int DLL_ENTRY		ossxSetIXAPIFlags(OssxEnv *world, 
				unsigned long flags);

/* Enumeration identifies internal C representations of XSD types.
 * Note that enumerators  should be in sync with etype kinds. */
typedef enum ixapiCtype {
   ossxIa_int         = 0,
   ossxIa_pad_bit     = 1,
   ossxIa_big_pad_bit = 2,
   ossxIa_unbnd_bit   = 3,
   ossxIa_vary_bit    = 4,
   ossxIa_null        = 5,
   ossxIa_enum        = 6,
   ossxIa_real        = 7,
   ossxIa_bool        = 8,
   ossxIa_any         = 10,
   ossxIa_set         = 11,
   ossxIa_seq         = 12,
   ossxIa_choice      = 13,
   ossxIa_setof       = 16,
   ossxIa_seqof       = 19,
   ossxIa_unbnd_octet = 20,
   ossxIa_vary_octet  = 21,
   ossxIa_pad_char    = 22,
   ossxIa_vary_char   = 23,
   ossxIa_nlltrm_char = 24,
   ossxIa_unbnd_char  = 25,
   ossxIa_array_objid = 26,
   ossxIa_unbnd_objid = 28,
   ossxIa_utc_time    = 29,
   ossxIa_gen_time    = 30,
   ossxIa_opentype    = 51, 
   ossxIa_2byte_char  = 53,
   ossxIa_4byte_char  = 54,
   ossxIa_uint        = 55,
   ossxIa_uenum       = 58,
   ossxIa_char_real   = 59,
   ossxIa_mixed_real  = 60,
   ossxIa_huge_int    = 62,
   ossxIa_encoded_objid  = 63,
   ossxIa_encoded_reloid = 74,
   ossxIa_unknown_ctype  = 84
} ixapiCtype;

extern int DLL_ENTRY        ossxCtypeId(OssxEnv *world, OssxTypeHndl type);
extern ossxBoolean DLL_ENTRY ossxTypeHasPointerDirective(OssxEnv *world,
							OssxTypeHndl type);
extern unsigned short DLL_ENTRY ossxCtypeLengthSize(OssxEnv *world,
							OssxTypeHndl type);


/***************************************************************************
 * Functions for printing XSD Global Elements, referenced types and XSD values    *
 ***************************************************************************/
extern void DLL_ENTRY ossxPrintGlobElems(OssxEnv *world);
extern void DLL_ENTRY ossxPrintRemainingReferencedTypes(OssxEnv *world);
extern void DLL_ENTRY ossxPrintXSDDescriptionOfGlobElem(OssxEnv *world,
					int globElemNum, ossxBoolean refTypes);
extern void DLL_ENTRY ossxPrintXSDDescriptionOfType(OssxEnv *world,
				OssxTypeHndl type, ossxBoolean refTypes);
extern void DLL_ENTRY ossxPrintDecodedValuesOfGlobElems(OssxEnv *world);
extern void DLL_ENTRY ossxPrintDecodedValueOfGlobElem(OssxEnv *world, int globElemNum,
				 void *decodedValue);
extern void DLL_ENTRY ossxPrintDecodedValueOfGlobElemByName(OssxEnv *world,
				OssxTypeHndl type, char *name, void *decodedValue);
extern void DLL_ENTRY ossxPrintDecodedValueOfType(OssxEnv *world,
				OssxTypeHndl type, void *decodedValue);


/* IXAPI flags used to control printing in different formats in the function
 * ossxPrintEncodingInTLV() */
#define OSSX_TLV_DECOMPOSED     0x01
#define OSSX_TLV_SYNTAX         0x02
#define OSSX_TLV_TEXT           0x04
#define OSSX_TLV_NOSHORT        0x08
#define OSSX_TLV_NOADDITION     0x10
#define OSSX_TLV_NOTITLES       0x20


/* IXAPI flags to control signal, setjmp, longjmp, IXAPI constraint checking
 * handling. */
#define IXAPI_NOSIGNAL     0x2000
#define IXAPI_NOSETJMP     0x4000
#define IXAPI_NOCONSTRAIN  0x8000
#define IXAPI_DONT_PRINT_REFERENCED_TYPES 0x20000

/* IXAPI flags used by ossxCreateUnencodedValueGlobElem/Type() to control unencoded 
 * values initialization. The IXAPI_NOCONSTRAIN flag can be used to suppress
 * using constraints applied to types during values inititialization. */
#define IXAPI_INIT_OPTIONALS   0x40000
#define IXAPI_NODEFAULT_VALUES 0x80000
#define IXAPI_NONAMED_ITEMS    0x100000


extern void DLL_ENTRY ossxPrintEncodingInTLV(OssxEnv *world,
				unsigned long flags, OssxBufExtended *inbuf);
extern void DLL_ENTRY ossxPrintEncodingInDecomposedTLV(OssxEnv *world,
				OssxBuf *encValue);
extern void DLL_ENTRY ossxPrintEncodingInSyntaxTLV(OssxEnv *world, OssxBuf *encValue);
extern void DLL_ENTRY ossxPrintEncodingInHexTLV(OssxEnv *world, OssxBuf *encValue);

#define ossxPrintBEREncoding      ossxPrintEncodingInDecomposedTLV
#define ossxPrintBEREncodingInTLV ossxPrintEncodingInSyntaxTLV


#ifdef __cplusplus
}
#endif /* __cplusplus */

#if defined(macintosh) && defined(__CFM68K__)
#pragma import reset
#endif


#endif /* #ifndef OSSXIXAPI_H */
