/*****************************************************************************/
/* Copyright (C) 2006- OSS Nokalva, Inc.  All rights reserved.           */
/*****************************************************************************/
/*****************************************************************************/
/* FILE: @(#)encode.c	1.5 06/09/11                               */
/*****************************************************************************/


#include "ossxfidef.h"


int	ossxEncodeEventsList(OssxEnv *ctx, OssxEvent *item, OssxBuf *outbuf)
{
    int			cdata = 0;
    int			retcode = 0;
    int			add_to_table = (ossxFIGetFlags(ctx) &
				OSSX_FI_ADD_STRINGS_TO_VOCABULARY) != 0;
    
    while (item) {
	switch(item->kind) {
        case OSSX_StartDocument:
    	retcode = ossxFIStartDocument(ctx, outbuf);
        break;
	case OSSX_EndDocument:
	    retcode = ossxFIEndDocument(ctx);
        break;
	case OSSX_XmlDecl: {
	    OssxXmlDecl		*xml_decl = &item->u.xml_Decl;

	    retcode = ossxFIXMLDecl(ctx, xml_decl->version, 0, /* don't add */
			    xml_decl->encoding, xml_decl->standalone);
    	    break;
	}
	case OSSX_StartDoctypeDecl: {
	    OssxStartDoctypeDecl *dtd = &item->u.start_DoctypeDecl;

	    retcode =  ossxFIStartDoctypeDecl(ctx, dtd->sysid, dtd->pubid);
	    break;
	}
	case OSSX_EndDoctypeDecl:
	    retcode = ossxFIEndDoctypeDecl(ctx);
        break;
        case OSSX_UnparsedEntityDecl: {
	    OssxUnparsedEntityDecl *ued = &item->u.unparsed_EntityDecl;

	    retcode = ossxFIUnparsedEntityDecl(ctx, ued->entityName,
			ued->sysid, ued->pubid,
			ued->notationName);
    	    break;
        }
        case OSSX_NotationDecl: {
    	    OssxNotationDecl	*nd = &item->u.notation_Decl;

	    retcode = ossxFINotationDecl(ctx, nd->notationName,
						nd->sysid, nd->pubid);
    	    break;
    	}
	case OSSX_StartElement: {
    	    OssxStartElement	*el = &item->u.start_Element;

	    retcode = ossxFIStartElement(ctx, el->name.uri, el->name.localname);

	    if (!retcode) {
		OssxAttributes	*attr = el->attr;

		while (attr) {
		    retcode = ossxFIAddAttribute(ctx, attr->name.uri,
                    		attr->name.localname, attr->value,
                                attr->length, add_to_table, OSSX_ENC_UTF8);
                    attr = attr->next;
		}
	    }
    	    break;
    	}
        case OSSX_EndElement:
	    retcode = ossxFIEndElement(ctx, NULL, NULL);
        break;
	case OSSX_Characters: {
    	    OssxCharacters	*chrs = &item->u.characters;

	    retcode = ossxFICharacters(ctx, chrs->chars, chrs->length, add_to_table,
	                            cdata ? OSSX_ALG_CDATA : OSSX_ENC_UTF8);
    	    break;
    	}
        case OSSX_StartPrefixMapping: {
    	    OssxStartPrefixMapping *pm = &item->u.start_PrefixMapping;

	    retcode = ossxFIStartPrefixMapping(ctx, pm->prefix, pm->uri);
    	    break;
    	}
	case OSSX_EndPrefixMapping:
        break;
        case OSSX_ProcessingInstruction: {
    	    OssxProcessingInstruction *pi = &item->u.processing_Instruction;

	    retcode = ossxFIProcessingInstruction(ctx, pi->target,
			    pi->chars, pi->length, add_to_table, OSSX_ENC_UTF8);
    	    break;
    	}
        case OSSX_StartCDATA:
    	    cdata = 1;
        break;
	case OSSX_EndCDATA:
	    cdata = 0;
        break;
	case OSSX_Comment: {
    	    OssxComment		*comm = &item->u.comment;

	    retcode = ossxFIComment(ctx, comm->chars, comm->length,
						add_to_table, OSSX_ENC_UTF8);
    	    break;
    	}
        case OSSX_UnexpEntityRef: {
    	    OssxUnexpEntityRef	*ueref = &item->u.unexp_EntityRef;

	    retcode = ossxFIUnexpandedEntityRef(ctx, ueref->entityName,
						ueref->sysid, ueref->pubid);
    	    break;
    	}
    	default:
        case OSSX_StartEntity:
        break;
	case OSSX_EndEntity:
        break;
        } /* switch */
        if (retcode)
    	    break;
	item = item->next;
    }
    return retcode;
}
