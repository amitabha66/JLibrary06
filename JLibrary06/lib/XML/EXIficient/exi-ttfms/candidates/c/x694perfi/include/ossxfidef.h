/*****************************************************************************/
/* Copyright (C) 2006- OSS Nokalva, Inc.  All rights reserved.           */
/*****************************************************************************/
/*****************************************************************************/
/* FILE: @(#)ossxfidef.h	1.14 06/09/11                               */
/*****************************************************************************/

#ifndef _OSSXFIDEF_H_
#define _OSSXFIDEF_H_

#include <ossxsd.h>

typedef struct {
    char 		*version;	/* NonIdentifyingStringOrIndex */
    char 		*encoding;	/* NonEmptyOctetString */
    OssxStandalone 	standalone;
} OssxXmlDecl;

typedef struct {
    char 		*entityName;
    char 		*sysid;
    char 		*pubid;
    char 		*notationName;
} OssxUnparsedEntityDecl;		/* C.10 */

typedef struct {
    char 		*sysid;
    char 		*pubid;
    char 		*notationName;
} OssxNotationDecl;			/* C.11 */

typedef struct {
    char 		*chars;		/* NonIdentifyingStringOrIndex */
    unsigned int  	length;
} OssxComment;				/* C.8 */

typedef struct {
    char 		*target;
    char 		*chars;		/* NonIdentifyingStringOrIndex */
    unsigned int 	length;
} OssxProcessingInstruction;		/* C.5 */

typedef struct {
    char 		*sysid;
    char 		*pubid; 
    int 	  	has_internal_subset;
} OssxStartDoctypeDecl;			/* C.9 */

typedef struct {
    char 		*prefix;
    char 		*uri;
} OssxStartPrefixMapping;

typedef struct {
    char		*uri;
    char		*localname;
} OssxXMLQName;				/* C.17 */

typedef struct _OssxAttributes {
    OssxXMLQName		name;
    char               		*value;	/* NonIdentifyingStringOrIndex */
    unsigned int 		length;
    struct _OssxAttributes	*next;
}  OssxAttributes;			/* C.4 */

typedef struct {
    OssxXMLQName 	name;
    OssxAttributes 	*attr;
} OssxStartElement;

typedef struct {
    char 		*chars;		/* NonIdentifyingStringOrIndex */
    unsigned int 	length;
} OssxCharacters;			/* C.7 */

typedef struct {
    char 		*entityName;
    char 		*sysid;
    char 		*pubid;
} OssxUnexpEntityRef;			/* C.6 */

typedef enum { 
    OSSX_StartDocument,
    OSSX_EndDocument,
    OSSX_XmlDecl, 		/* OssxXmlDecl */
    OSSX_StartDoctypeDecl,	/* OssxStartDoctypeDecl */
    OSSX_EndDoctypeDecl,
    OSSX_UnparsedEntityDecl,	/* OssxUnparsedEntityDecl */
    OSSX_NotationDecl,    	/* OssxNotationDecl */
    OSSX_StartElement,    	/* OssxStartElement */
    OSSX_EndElement,
    OSSX_Characters,    	/* OssxCharacters */
    OSSX_StartPrefixMapping,    /* OssxStartPrefixMapping */
    OSSX_EndPrefixMapping,
    OSSX_ProcessingInstruction, /* OssxProcessingInstruction */
    OSSX_Comment,    		/* OssxComment */
    OSSX_StartCDATA,
    OSSX_EndCDATA,
    OSSX_StartEntity,
    OSSX_EndEntity,
    OSSX_UnexpEntityRef    	/* OssxUnexpEntityRef */
} OssxEventKind;

typedef struct _OssxEvent {
    struct _OssxEvent	*next;
    OssxEventKind	kind;
    union {
    OssxXmlDecl			xml_Decl;
    OssxStartDoctypeDecl	start_DoctypeDecl;
    OssxUnparsedEntityDecl 	unparsed_EntityDecl;
    OssxNotationDecl     	notation_Decl;
    OssxStartElement		start_Element;
    OssxCharacters		characters;
    OssxStartPrefixMapping	start_PrefixMapping;
    OssxProcessingInstruction	processing_Instruction;
    OssxComment			comment;
    OssxUnexpEntityRef		unexp_EntityRef;
    } u;
} OssxEvent;

void ossxPrintEvents(OssxEnv *ctx, OssxEvent *item);
void ossxFreeEvents(OssxEnv *ctx, OssxEvent *item);
int ossxCreateEventsList(OssxEnv *ctx, OssxBuf *msg, OssxEvent **events);
int ossxEncodeEventsList(OssxEnv *ctx, OssxEvent *item, OssxBuf *msg);
int ossxCreateIndexes(OssxEnv *ctx, OssxEvent *item, OssxBuf *outbuf);

#endif /* _OSSXFIDEF_H_ */
