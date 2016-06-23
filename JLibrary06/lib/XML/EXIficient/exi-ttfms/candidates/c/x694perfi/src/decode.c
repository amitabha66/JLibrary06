//*****************************************************************************/
/* Copyright (C) 2006- OSS Nokalva, Inc.  All rights reserved.           */
/*****************************************************************************/
/*****************************************************************************/
/* FILE: @(#)decode.c	1.11 06/09/13                               */
/*****************************************************************************/


#include "ossxfidef.h"


typedef struct _OssxUnv {
    OssxEnv	        *ctx;
    OssxEvent		*events;
    OssxEvent		*cur_evnt;
    struct {
	int	cdata		: 1;	
	int     standalone	: 1; 
	int     ext_dtd		: 1;
    } 			f; /* flags */
} OssxUnv;

/* ================ Fast Infoset event handling functions ================ */
static int _ossxError(void *user_data, int errorcode, const unsigned char *msg,
						OssxErrSeverity severity)
{
    OssxUnv 	*data = (OssxUnv *)user_data;
    char	*str;
    
    switch (severity) {
    case OssxWarning:
	str = "WARNING";
	break;
    case OssxError:
	str = "ERROR";
	break;
    case OssxFatal:
	str = "FATAL";
	break;
    default:
	str = "UNKNOWN";
	break;
    }
    ossxPrint(data->ctx, 
	"\n== ERROR\n  Code: %d, Severity: \"%s\",\n  Message: \"%s\"\n",
	errorcode, str, msg ? (char *)msg : "");
    return errorcode;
}

static int _ossxStartDocument(void *user_data)
{
    OssxUnv 	*data = (OssxUnv *)user_data;
    
    data->events = data->cur_evnt = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt->kind = OSSX_StartDocument;
    return 0;
}

static int _ossxEndDocument(void *user_data)
{
    OssxUnv 	*data = (OssxUnv *)user_data;
    
    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_EndDocument;

    return 0;
}

static void _ossxCopyXMLQName(OssxEnv *ctx, OssxXMLQName* qname, 
						const OssxXMLName *name)
{
    size_t	u_len, len;
    
    u_len = name->uri ? strlen((char *)name->uri) + 1 : 0;
    len = strlen((char *)name->localname) + 1;
    qname->localname = (char *)ossxGetMemory(ctx, len + u_len);
    memcpy(qname->localname, name->localname, len);
    if (u_len) {
	qname->uri = qname->localname + len;
	memcpy(qname->uri, name->uri, u_len);
    }
}

static void _ossxCopyOssxAttributes(OssxEnv *ctx, OssxAttributes **qattr, 
						const OssxXMLAttributes *attr)
{
    OssxAttributes	*at;
    
    *qattr = at = ossxGetInitializedMemory(ctx, sizeof(OssxAttributes));
    while (1) {
	_ossxCopyXMLQName(ctx, &at->name, &attr->name);
	if (attr->length) {
	    at->value = (char *)ossxGetMemory(ctx, attr->length);
	    memcpy(at->value, attr->value, attr->length);
	    at->length = attr->length;
	}
	attr = attr->next;
	if (!attr)
	    break;
	at->next = ossxGetInitializedMemory(ctx, sizeof(OssxAttributes));
	at = at->next;
    }
}

static int _ossxStartElement(void *user_data, const OssxXMLName *name,
	    const OssxXMLAttributes *attr)
{
    OssxUnv 		*data = (OssxUnv *)user_data;
    OssxStartElement 	*el;
    
    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_StartElement;
    el = &data->cur_evnt->u.start_Element;
    _ossxCopyXMLQName(data->ctx, &el->name, name);
    if (attr)
	_ossxCopyOssxAttributes(data->ctx, &el->attr, attr);
    return 0;
}

static int _ossxEndElement(void *user_data, const OssxXMLName *name)
{
    OssxUnv *data = (OssxUnv *)user_data;
    
    if (name)
	data = data;
    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_EndElement;
    return 0;
}

static int _ossxCharacters(void *user_data, const unsigned char *chars,
            unsigned int length)
{
    OssxUnv 	    *data = (OssxUnv *)user_data;
    OssxCharacters  *el;
      
    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_Characters;
    el = &data->cur_evnt->u.characters;
    if (length) {
	el->chars = (char *)ossxGetMemory(data->ctx, length);
	memcpy(el->chars, chars, length);
	el->length = length;
    }        
    return 0;
}

static int _ossxStartPrefixMapping(void *user_data, const unsigned char *prefix,
	    const unsigned char *uri)
{
    OssxUnv 	    	    *data = (OssxUnv *)user_data;
    OssxStartPrefixMapping  *el;
    size_t		    len, p_len;
          
    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_StartPrefixMapping;
    el = &data->cur_evnt->u.start_PrefixMapping;
    
    p_len = prefix ? strlen((char *)prefix) + 1 : 0;
    len = strlen((char *)uri) + 1;
    el->uri = (char *)ossxGetMemory(data->ctx, len + p_len);
    memcpy(el->uri, uri, len);
    if (p_len) {
	el->prefix = el->uri + len;
	memcpy(el->prefix, prefix, p_len);
    }
    return 0;
}

/*
static int _ossxEndPrefixMapping(void *user_data, const unsigned char *prefix)
{
    OssxUnv 	    *data = (OssxUnv *)user_data;
      
    if (prefix)
	data = data;      
    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_EndPrefixMapping;
    return 0;
}
*/

static int _ossxProcessingInstruction(void *user_data, const unsigned char *target,
	const unsigned char *chars, unsigned int length)
{
    OssxUnv 	    	      *data = (OssxUnv *)user_data;
    OssxProcessingInstruction *el;
    size_t		      len;
          
    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_ProcessingInstruction;
    el = &data->cur_evnt->u.processing_Instruction;
    len = target ? strlen((char *)target) + 1 : 0;

    if (length + len)
	el->target = el->chars = (char *)ossxGetMemory(data->ctx, length + len);
    if (length) {
	memcpy(el->chars, chars, length);
	el->target += length;
	el->length = length;
    } else
	el->chars = NULL;
    if (len)
	memcpy(el->target, target, len);
    else
	el->target = NULL;

    return 0;
}

static int _ossxComment(void *user_data, const unsigned char *chars, unsigned int length)
{
    OssxUnv     *data = (OssxUnv *)user_data;
    OssxComment *el;
      
    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_Comment;
    el = &data->cur_evnt->u.comment;
    if (length) {
	el->chars = (char *)ossxGetMemory(data->ctx, length);
	memcpy(el->chars, chars, length);
	el->length = length;
    }

    return 0;
}    

static int _ossxStartCDATA(void *user_data)
{
    OssxUnv 	    *data = (OssxUnv *)user_data;
      
    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_StartCDATA;
    data->f.cdata = 1;
    return 0;
}

static int _ossxEndCDATA(void *user_data)
{
    OssxUnv 	    *data = (OssxUnv *)user_data;
      
    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_EndCDATA;
    data->f.cdata = 0;
    return 0;
}

static int _ossxXmlDecl(void *user_data, const unsigned char *version,
			const unsigned char *encoding, OssxStandalone standalone)
{
    OssxUnv     *data = (OssxUnv *)user_data;
    OssxXmlDecl *el;
    size_t	len;
          
    if (!version || !(*version))
	/* Wrong XML declaration - version may not be absent */
	return 0;

    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_XmlDecl;
    el = &data->cur_evnt->u.xml_Decl;
    data->f.standalone = (standalone == OssxStYes) ? 1 : 0;

    el->standalone = standalone;
    if (version) {
	len = strlen((char *)version) + 1;
	el->version = (char *)ossxGetMemory(data->ctx, len);
	memcpy(el->version, version, len);
    }
    if (encoding) {
	len = strlen((char *)encoding) + 1;
	el->encoding = (char *)ossxGetMemory(data->ctx, len);
	memcpy(el->encoding, encoding, len);
    }
    
    return 0;
}
						    
static int _ossxStartDoctypeDecl(void *user_data, const unsigned char *name,
			const unsigned char *sysid, const unsigned char *pubid,
			int has_internal_subset)
{
    OssxUnv     	  *data = (OssxUnv *)user_data;
    OssxStartDoctypeDecl  *el;
    size_t      	  len;      

    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_StartDoctypeDecl;
    el = &data->cur_evnt->u.start_DoctypeDecl;
    if ((sysid || pubid) && !data->f.standalone)
	data->f.ext_dtd = 1;
    el->has_internal_subset = has_internal_subset;
    if (sysid) {
	len = strlen((char *)sysid) + 1;
	el->sysid = (char *)ossxGetMemory(data->ctx, len);
	memcpy(el->sysid, sysid, len);
    }
    if (pubid) {
	len = strlen((char *)pubid) + 1;
	el->pubid = (char *)ossxGetMemory(data->ctx, len);
	memcpy(el->pubid, pubid, len);
    }

    return 0;
}

static int _ossxEndDoctypeDecl(void *user_data, const unsigned char *name)
{
    OssxUnv     *data = (OssxUnv *)user_data;
      
    if (name)
	data = data;      
    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_EndDoctypeDecl;
    return 0;
}

static int _ossxUnparsedEntityDecl(void *user_data, const unsigned char *entityName,
			const unsigned char *sysid, const unsigned char *pubid,
			const unsigned char *notationName)
{
    OssxUnv     	    *data = (OssxUnv *)user_data;
    OssxUnparsedEntityDecl  *el;
    size_t		    len;
          
    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_UnparsedEntityDecl;
    el = &data->cur_evnt->u.unparsed_EntityDecl;
    if (entityName) {
	len = strlen((char *)entityName) + 1;
	el->entityName = (char *)ossxGetMemory(data->ctx, len);
	memcpy(el->entityName, entityName, len);
    }
    if (sysid) {
	len = strlen((char *)sysid) + 1;
	el->sysid = (char *)ossxGetMemory(data->ctx, len);
	memcpy(el->sysid, sysid, len);
    }
    if (pubid) {
	len = strlen((char *)pubid) + 1;
	el->pubid = (char *)ossxGetMemory(data->ctx, len);
	memcpy(el->pubid, pubid, len);
    }
    if (notationName) {
	len = strlen((char *)notationName) + 1;
	el->notationName = (char *)ossxGetMemory(data->ctx, len);
	memcpy(el->notationName, notationName, len);
    }

    return 0;
}

static int _ossxNotationDecl(void *user_data, const unsigned char *notationName,
			const unsigned char *sysid, const unsigned char *pubid)
{
    OssxUnv           *data = (OssxUnv *)user_data;
    OssxNotationDecl  *el;
    size_t	      len;
          
    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_NotationDecl;
    el = &data->cur_evnt->u.notation_Decl;
    if (sysid) {
	len = strlen((char *)sysid) + 1;
	el->sysid = (char *)ossxGetMemory(data->ctx, len);
	memcpy(el->sysid, sysid, len);
    }
    if (pubid) {
	len = strlen((char *)pubid) + 1;
	el->pubid = (char *)ossxGetMemory(data->ctx, len);
	memcpy(el->pubid, pubid, len);
    }
    if (notationName) {
	len = strlen((char *)notationName) + 1;
	el->notationName = (char *)ossxGetMemory(data->ctx, len);
	memcpy(el->notationName, notationName, len);
    }
    return 0;
}

static int _ossxUnexpEntityRef(void *user_data, const unsigned char *entityName, 
			const unsigned char *sysid, const unsigned char *pubid)
{
    OssxUnv     	*data = (OssxUnv *)user_data;
    OssxUnexpEntityRef  *el;
    size_t		len;
          
    data->cur_evnt->next = ossxGetInitializedMemory(data->ctx,
					    sizeof(OssxEvent));
    data->cur_evnt = data->cur_evnt->next;
    data->cur_evnt->kind = OSSX_UnexpEntityRef;
    el = &data->cur_evnt->u.unexp_EntityRef;
    if (entityName) {
	len = strlen((char *)entityName) + 1;
	el->entityName = (char *)ossxGetMemory(data->ctx, len);
	memcpy(el->entityName, entityName, len);
    }
    if (sysid) {
	len = strlen((char *)sysid) + 1;
	el->sysid = (char *)ossxGetMemory(data->ctx, len);
	memcpy(el->sysid, sysid, len);
    }
    if (pubid) {
	len = strlen((char *)pubid) + 1;
	el->pubid = (char *)ossxGetMemory(data->ctx, len);
	memcpy(el->pubid, pubid, len);
    }

    return data->f.ext_dtd ? 0 : OSSX_FI_UNSUPP_EXT_ENTITY;
}

/* FI decoder events table */
static OssxSAXEventTable oss_FI_table = {
    0,
    &_ossxError,
    &_ossxStartDocument,
    &_ossxEndDocument,
    &_ossxXmlDecl,
    &_ossxStartDoctypeDecl,
    &_ossxEndDoctypeDecl,
    &_ossxUnparsedEntityDecl,
    &_ossxNotationDecl,
    &_ossxStartElement,
    &_ossxEndElement,
    &_ossxCharacters,
    &_ossxStartPrefixMapping,
    NULL, /* &_ossxEndPrefixMapping, */
    &_ossxProcessingInstruction,
    &_ossxComment,
    &_ossxStartCDATA,
    &_ossxEndCDATA,
    NULL,
    NULL,
    &_ossxUnexpEntityRef
};

int ossxCreateEventsList(OssxEnv *ctx, OssxBuf *msg, OssxEvent **events)
{
    /* Variables */
    OssxUnv         tenv;		/* User-defined callback data */
    int		    err;

    /*
     * Prepare application-specific variable passed to callback functions.
     */
    memset(&tenv, 0, sizeof(tenv));
    tenv.ctx = (OssxEnv *)ctx->userVar;

    /*
     * Call Fast Infoset decoder and handle FI events.
     */

    err = ossxDecodeFastInfoset(ctx, msg, (void *)&tenv, &oss_FI_table);

    if (err) {
	ossxFreeEvents(ctx, tenv.events);
	tenv.events = NULL;
    }
    *events = tenv.events;

    return err;
}
