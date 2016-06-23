/*****************************************************************************/
/* Copyright (C) 2006- OSS Nokalva, Inc.  All rights reserved.           */
/*****************************************************************************/
/*****************************************************************************/
/* FILE: @(#)freeevns.c	1.1 06/09/11                               */
/*****************************************************************************/


#include "ossxfidef.h"


void ossxFreeEvents(OssxEnv *ctx, OssxEvent *item)
{
    OssxEvent		*next;

    while (item) {
	next = item->next;

	switch(item->kind) {
        case OSSX_StartDocument:
        break;
	case OSSX_EndDocument:
        break;
	case OSSX_XmlDecl: {		/* OssxXmlDecl */
	    OssxXmlDecl		*el = &item->u.xml_Decl;
	    
	    if (el->version)
		ossxFreeMemory(ctx, el->version);
	    if (el->encoding)
		ossxFreeMemory(ctx, el->encoding);
	}
    	break;
	case OSSX_StartDoctypeDecl: {	/* OssxStartDoctypeDecl */
	    OssxStartDoctypeDecl	*el = &item->u.start_DoctypeDecl;

	    if (el->sysid)
		ossxFreeMemory(ctx, el->sysid);
	    if (el->pubid)
		ossxFreeMemory(ctx, el->pubid);
	}
        break;
	case OSSX_EndDoctypeDecl:
        break;
        case OSSX_UnparsedEntityDecl: {	/* OssxUnparsedEntityDecl */
	    OssxUnparsedEntityDecl	*el = &item->u.unparsed_EntityDecl;

	    if (el->entityName)
		ossxFreeMemory(ctx, el->entityName);
	    if (el->sysid)
		ossxFreeMemory(ctx, el->sysid);
	    if (el->pubid)
		ossxFreeMemory(ctx, el->pubid);
	    if (el->notationName)
		ossxFreeMemory(ctx, el->notationName);
	}	    
        break;
        case OSSX_NotationDecl: {   	/* OssxNotationDecl */
	    OssxNotationDecl	*el = &item->u.notation_Decl;
	    
	    if (el->sysid)
		ossxFreeMemory(ctx, el->sysid);
	    if (el->pubid)
		ossxFreeMemory(ctx, el->pubid);
	    if (el->notationName)
		ossxFreeMemory(ctx, el->notationName);
	}	    
        break;
	case OSSX_StartElement: {    	/* OssxStartElement */
	    OssxStartElement	*el = &item->u.start_Element;
	    OssxAttributes      *nxt, *at = el->attr;

	    while (at) {
		nxt = at->next;
		if (at->name.localname)
		    ossxFreeMemory(ctx, at->name.localname);
		if (at->length)
		    ossxFreeMemory(ctx, at->value);
		ossxFreeMemory(ctx, at);
		at = nxt;
	    }

	    if (el->name.localname)
		ossxFreeMemory(ctx, el->name.localname);
	}
        break;
        case OSSX_EndElement:
        break;
	case OSSX_Characters: {   	/* OssxCharacters */
	    OssxCharacters	*el = &item->u.characters;

	    if (el->length)
		ossxFreeMemory(ctx, el->chars);
	}
        break;
        case OSSX_StartPrefixMapping: {	/* OssxStartPrefixMapping */
	    OssxStartPrefixMapping	*el = &item->u.start_PrefixMapping;

	    if (el->uri)
		ossxFreeMemory(ctx, el->uri);
	}
        break;
	case OSSX_EndPrefixMapping:
        break;
        case OSSX_ProcessingInstruction: { /* OssxProcessingInstruction */
    	    OssxProcessingInstruction	*el = &item->u.processing_Instruction;
    	    
	    if (el->length)
		ossxFreeMemory(ctx, el->chars);
	    else if (el->target)
		ossxFreeMemory(ctx, el->target);
	}
        break;
	case OSSX_Comment: {   		/* OssxComment */
	    OssxComment		*el = &item->u.comment;

	    if (el->length)
		ossxFreeMemory(ctx, el->chars);
	}
        break;
        case OSSX_StartCDATA:
        break;
	case OSSX_EndCDATA:
        break;
        case OSSX_StartEntity:
        break;
	case OSSX_EndEntity:
        break;
        case OSSX_UnexpEntityRef: {   	/* OssxUnexpEntityRef */
	    OssxUnexpEntityRef	*el = &item->u.unexp_EntityRef;
	    
	    if (el->entityName)
		ossxFreeMemory(ctx, el->entityName);
	    if (el->sysid)
		ossxFreeMemory(ctx, el->sysid);
	    if (el->pubid)
		ossxFreeMemory(ctx, el->pubid);
	}
        break;
        }
	ossxFreeMemory(ctx, item);
	item = next;
    }
}
