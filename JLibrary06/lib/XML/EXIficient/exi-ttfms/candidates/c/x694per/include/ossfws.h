/*****************************************************************************/
/* Copyright (C) 2005-2006 OSS Nokalva, Inc.  All rights reserved.           */
/*****************************************************************************/

/*****************************************************************************/
/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC. AND                */
/* MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.                 */
/* THIS FILE MAY NOT BE DISTRIBUTED.                                         */
/*****************************************************************************/

/*************************************************************************/
/* FILE: @(#)ossfws.h	15.11  06/03/09                                   */
/*************************************************************************/

#ifndef OSSFWS_H
#define OSSFWS_H

#include "ossxsd.h" /* core functions and structures are defined there */

/*****************************************************************************/
/*  PUBLIC section: Fast Web Services - specific error codes returned by API */
/*  functions and distinct OSSX_UNKNOWN_MSG message identifier               */
/*****************************************************************************/

#define OSSX_UNKNOWN_MSG		0

/* FWS error return code */
    /* This function (ossxRelayCurrentEncoding() or similar) should not
     * be called outside of a SOAP decoder callback function, but it was */
#define OSSX_FWS_OUTSIDE_CALLBACK	2000
    /* This function (ossxAddHeaderBlock() or similar) should not
     * be called inside of a SOAP decoder callback function, but it was */
#define OSSX_FWS_INSIDE_CALLBACK	2001
    /* When decoding a SOAP message, user attempted to relay 
     * the same fragment of encoding multiple times */
#define OSSX_FWS_STORED			2002
    /* User has called the ossxIdentifyMessage() function, and the message 
     * is recognized as the special 'NotUnderstood' header block message   */
#define OSSX_FWS_NOTUNDERSTOOD		2003
    /* User is trying to access the application-specific
     * part of a SOAP message but it is absent           */
#define OSSX_FWS_NOT_ENCODED_VALUE	2004
    /* There is no 'inner context' for given Web Service control table */
#define OSSX_FWS_SERVICE_NOT_FOUND	2005
    /* SOAP Body is unexpectedly absent */
#define OSSX_SOAP_BODY_ABSENT		2006
    /* The added context contains a RELATIVE-OID value, which is 
     * already present in the existing list of the inner contexts */
#define OSSX_FWS_CONFLICT_ROID		2007
    /* The added context contains a QName value, which is 
     * already present in the existing list of the inner contexts */
#define OSSX_FWS_CONFLICT_QNAME		2008
    /* The compared values are not equal */
#define OSSX_FWS_VALUES_NOT_EQUAL	2009
    /* General transport related error */
#define OSSX_TRANSPORT_ERROR 		2010
    /* Message ID of request message is incorrect */
#define OSSX_NOT_REQUEST		2011

/*****************************************************************************/
/*  NON-PUBLIC section: data alignment section for platforms with multiple   */
/*  alignment options (OSS data structures should use the same setting as    */
/*  OSS runtime does)                                                        */
/*****************************************************************************/

#ifdef macintosh
#pragma options align=mac68k
#endif
#if defined(_MSC_VER) && (defined(WINCE) || defined(_WIN64))
#pragma pack(push, ossxPacking, 8)
#elif defined(_MSC_VER) && (defined(_WIN32) || defined(WIN32))
#pragma pack(push, ossxPacking, 4)
#elif defined(_MSC_VER) && (defined(_WINDOWS) || defined(_MSDOS))
#pragma pack(1)
#elif defined(__BORLANDC__) && defined(__MSDOS__)
#ifdef _BC31
#pragma option -a-
#else
#pragma option -a1
#endif /* _BC31 */
#elif defined(__BORLANDC__) && defined(__WIN32__)
#pragma option -a4
#elif defined(__IBMC__) && (defined(__WIN32__) || defined(__OS2__))
#pragma pack(4)
#elif defined(__WATCOMC__) && defined(__NT__)
#pragma pack(push, 4)
#elif defined(__WATCOMC__) && (defined(__WINDOWS__) || defined(__DOS__))
#pragma pack(push, 1)
#endif /* _MSC_VER && WINDOWS_ITANIUM_64BIT */

#if defined(macintosh) && defined(__CFM68K__)
#pragma import on
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/*  PUBLIC section: utility type definitions and enumerations                */
/*****************************************************************************/

typedef OssxEncodedRelOID OssxRelativeOID;

typedef unsigned char *OssxString;

typedef unsigned char *OssxAnyURI;

typedef char *OssxLanguage;

typedef struct OssxQName {
    OssxAnyURI      uri;  /* NULL for not present */
    OssxString      name;
} OssxQName;

/* Fast Web Service specific definitions */

typedef enum {
    OSSX_mtXML,
    OSSX_mtFastSoap,
    OSSX_mtFastInfoset
} OssxMIMEType;

typedef struct {
    OssxMIMEType   type;
    OssxBuf        data;
} OssxMessage;

typedef enum { OSSX_SOAP_v11 = 0, OSSX_SOAP_v12 } OssxSoapVersion;

typedef enum {
    OSSX_DynamicTree = 0,
    OSSX_DynamicBuf,
    OSSX_Static
} OssxMemoryMode;

/*****************************************************************************/
/*  PUBLIC section: SOAP Envelope                                            */
/*                                                                           */
/* The following definitions represent parsed SOAP message.                  */
/* In many cases these structures should not be of much interest             */
/* because they are hidden by generic OSS API and by generated               */
/* service-specific functions, but it is also possible to manually           */
/* construct and process Envelopes.                                          */
/*                                                                           */
/* The structures reflect ASN.1 definitions from X.892, Annex A.             */
/* Note that these definitions are not strictly in sync with W3C SOAP        */
/* message structure (for instance, Fault is not a part of Body in           */
/* ASN.1; fault code is flattened and not recursive etc.). Please            */
/* refer to X.892 for more details.                                          */
/*****************************************************************************/

typedef struct OssxHeader {
    struct OssxHeaderNode *head;
    struct OssxHeaderNode *tail;
    unsigned int    count;
} OssxHeader;

typedef struct OssxHeaderNode {
    struct OssxHeaderNode *next;
    struct OssxHeaderNode *prev;
    struct OssxHeaderBlock *value;
} OssxHeaderNode;

typedef struct OssxEnvelope {
    OssxMemoryMode	mmode;
    OssxHeader          header;
    struct {
        unsigned int  choice;
#           define      OssxEnvelope_body_chosen 1
#           define      OssxEnvelope_fault_chosen 2
        union {
            struct OssxBody     *body;  /* to choose, set choice to
                                         * OssxEnvelope_body_chosen */
            struct OssxFault    *fault; /* to choose, set choice to
                                         * OssxEnvelope_fault_chosen */
        } u;
    } body_or_fault;
} OssxEnvelope;

typedef struct OssxIdentifier {
    unsigned int  choice;
#       define      OssxIdentifier_roid_chosen 1
#       define      OssxIdentifier_qName_chosen 2
    union {
        OssxRelativeOID roid;  /* to choose, set choice to
                                * OssxIdentifier_roid_chosen */
        OssxQName       qName; /* to choose, set choice to
                                * OssxIdentifier_qName_chosen */
    } u;
} OssxIdentifier;

typedef struct OssxContent {
    unsigned int  choice;
#       define      OssxContent_encoded_value_chosen 1
#       define      OssxContent_fast_infoset_document_chosen 2
    union {
        struct encoded {
            OssxString   	schema_identifier; /* 16 bytes; NULL for not present */
            OssxIdentifier      id;
            struct OssxContentEncoding {
                OssxMessage    encoded;
		OssxMemoryMode mmode;
                void           *decoded;
	        int            msg_id;
            } encoding;
        } encoded_value;  /* to choose, set choice to
                           * OssxContent_encoded_value_chosen */
        struct octet_string {
            unsigned int    length;
            unsigned char   *value;
        } fast_infoset_document;  /* to choose, set choice to
                                   * OssxContent_fast_infoset_document_chosen */
    } u;
} OssxContent;

typedef struct OssxHeaderBlock {
    unsigned char   bit_mask;
#       define      OssxHeaderBlock_mustUnderstand_present 0x80
#       define      OssxHeaderBlock_relay_present 0x40
#       define      OssxHeaderBlock_role_present 0x20
    ossxBoolean     mustUnderstand;  /* optional; set in bit_mask
                                      * OssxHeaderBlock_mustUnderstand_present
                                      * if present */
    ossxBoolean     relay;  /* optional; set in bit_mask
                             * OssxHeaderBlock_relay_present if present */
    OssxAnyURI      role;
         /* OssxHeaderBlock_role_present not set in bit_mask implies value is
          * "http://www.w3.org/2003/05/soap-envelope/role/ultimateReceiver"
          * for SOAP 1.2 and is an 'ultimate receiver' actor for SOAP 1.1
          * (for SOAP 1.1, 'role' is NULL in this case after decoding) */
    OssxContent     content;
} OssxHeaderBlock;

typedef struct OssxBody {
    unsigned char   bit_mask;
#       define      OssxBody_content_present 0x80
    OssxContent     content;  /* optional; set in bit_mask
                               * OssxBodycontent_present if present */
} OssxBody;

typedef enum {
    OSSX_versionMismatch = 0,
    OSSX_mustUnderstand = 1,
    OSSX_dataEncodingUnknown = 2,
    OSSX_sender = 3,
    OSSX_receiver = 4
} OssxCodeValue;

typedef struct OssxCode {
    OssxCodeValue           value;
    struct OssxSubcode {
        struct OssxSubcodeNode *head;
        struct OssxSubcodeNode *tail;
        unsigned int    count;
    } subcodes;
} OssxCode;

typedef struct OssxSubcodeNode {
    struct OssxSubcodeNode *next;
    struct OssxSubcodeNode *prev;
    OssxQName               value;
} OssxSubcodeNode;

typedef struct OssxFault {
    unsigned char   bit_mask;
#       define      OssxFault_detail_present 0x80
    OssxCode        code;
    struct OssxReason {
        struct OssxReasonNode *head;
        struct OssxReasonNode *tail;
        unsigned int    count;
    } reason;
    OssxAnyURI           node;  /* optional; NULL for not present */
    OssxAnyURI           role;  /* optional; NULL for not present */
    OssxContent         detail; /* optional; set in bit_mask
                                 * OssxFault_detail_present if present */
} OssxFault;

typedef struct OssxText {
    OssxLanguage    lang;
    OssxString	    text;
} OssxText;

typedef struct OssxReasonNode {
    struct OssxReasonNode *next;
    struct OssxReasonNode *prev;
    OssxText               value;
} OssxReasonNode;

typedef OssxQName OssxNotUnderstood;

/*****************************************************************************/
/*  PUBLIC section: transport layer support			             */
/*****************************************************************************/

/* Transport layer definitions and OSS transport implementations */

/*****************************************************************************/
/*  PUBLIC section: auxiliary transport layer definitions                    */
/*****************************************************************************/

typedef struct OssxServerSettings {
    OSSX_UINT32 flags;
#define    OSSX_FREE_REQUEST_DATA	0x0001
    /*
     * Server sets this flag if it's safe to free the 'value' pointer
     * of the request message in server processing function. In this case
     * application should set request->data.value to NULL.
     * so
     */
#define    OSSX_CONST_RESPONSE_DATA	0x0002
    /*
     * Application sets this flag to indicate that response data was NOT
     * allocated dynamically and should not be freed by the server
     */
#define	   OSSX_FAULT_RESPONSE		0x0004
    /*
     * This flag is set by server body and/or event functions to
     * indicate that the response to be sent is a fault (the server 
     * should then use HTTP 500 return code to wrap it). 
     */
#define	   OSSX_ONE_WAY			0x0008
    /*
     * This flag is set by server body and/or event functions
     * to indicate that given operation is one-way and server should not 
     * send the HTTP message body (even in case of errors). 
     */
    int		operation_id;	/* operation ID calculated by server from
				 * SOAPAction HTTP attribute if it was 
				 * possible and requested by user
				 */
    void	*server_data;	/* pointer passed by user as the last
				 * parameter to ossxStartServer()
				 */
    OssxEnv	*inner_ctx;	/* identifies the service called if a
				 * server supports multiple services;
				 * NULL if service was not found
				 */
    OSSX_UINT32 client_ip;	/* IP address of connected client, 
				 * in network order */
} OssxServerSettings;

/*****************************************************************************/
/*  PUBLIC section: generic transport layer definitions (client and server). */
/*                                                                           */
/*  Client and server transports implement interfaces of OssxClientTransport */
/*  and OssxServerTransport, respectively.  Transport API is open so it's    */
/*  possible to implement custom transport layer to support non-standard.    */
/*  SOAP binding or system API.                                              */
/*****************************************************************************/

/*
 * Function pointers implementing server-side transport functionality
 */
typedef int (*serv_tr_init_ptr)(OssxEnv *in_ctx, void ** out_tctx);
typedef int (*serv_tr_term_ptr)(OssxEnv *in_ctx, void *in_tctx);
typedef int (*serv_tr_copy_ptr)(OssxEnv *in_ctx, void *in_tctx, 
				    void **out_tctx_copy);
typedef int (*serv_tr_start_ptr)(OssxEnv *in_ctx, void *in_tctx, 
				    void *server_data);
typedef int (*serv_tr_stop_ptr)(OssxEnv *in_ctx, void *in_tctx);
typedef int (*serv_tr_set_prop_ptr)(OssxEnv *in_ctx, void *in_tctx,
				    OssxServerSettings *in_ss, int in_kind, 
				    void *in_name, void *in_value);
typedef int (*serv_tr_get_prop_ptr)(OssxEnv *in_ctx, void *in_tctx,
				    OssxServerSettings *in_ss, int in_kind, 
				    void *in_name, void **out_value);

/*
 * Server transport interface structure
 */
typedef struct OssxServerTransport {
    serv_tr_init_ptr init;
    serv_tr_term_ptr term;
    serv_tr_copy_ptr copy;    /* called from ossxDupSoapContext() */
    serv_tr_start_ptr start;
    serv_tr_stop_ptr stop;
    serv_tr_set_prop_ptr set_prop;
    serv_tr_get_prop_ptr get_prop;
} OssxServerTransport;

/*
 * Function pointers implementing client-side transport functionality
 */
typedef int (*cl_tr_init_ptr)(OssxEnv *in_ctx, void ** out_tctx);
typedef int (*cl_tr_term_ptr)(OssxEnv *in_ctx, void *in_tctx);
typedef int (*cl_tr_copy_ptr)(OssxEnv *in_ctx, void *in_tctx, void **out_tctx_copy);
typedef int (*cl_tr_connect_ptr)(OssxEnv *in_ctx, void *in_tctx, void **connection);
/* it's safe to call "connect" before each send; it will report
* "already connected" if it is not needed, but will return an existing
* connection pointer anyway */
typedef int (*cl_tr_disconnect_ptr)(OssxEnv *in_ctx, void *in_tctx, void *connection);
/* disconnection automatically takes place after receiving data if
* keep-alive property is turned off */
typedef int (*cl_tr_send_ptr)(OssxEnv *in_ctx, void *in_tctx, void **connection,
				 OssxMessage *in_request, char *in_action);
typedef int (*cl_tr_receive_ptr)(OssxEnv *in_ctx, void *in_tctx, void **connection,
				 OssxMessage *out_response);
typedef int (*cl_tr_set_prop_ptr)(OssxEnv *in_ctx, void *in_tctx, void *connection,
				  int in_kind, void *in_name, void *in_value);
typedef int (*cl_tr_get_prop_ptr)(OssxEnv *in_ctx, void *in_tctx, void *connection,
				  int in_kind, void *in_name, void **out_value);

/*
 * Client transport interface structure
 */
typedef struct OssxClientTransport {
    cl_tr_init_ptr	init;
    cl_tr_term_ptr	term;
    cl_tr_copy_ptr	copy;    /* called from ossxDupSoapContext() */
    cl_tr_connect_ptr	connect;
    cl_tr_disconnect_ptr disconnect;
    cl_tr_send_ptr	send;
    cl_tr_receive_ptr	receive;
    cl_tr_set_prop_ptr	set_prop;
    cl_tr_get_prop_ptr	get_prop;
} OssxClientTransport;

/*
 * Combination of client and server transports to be passed to the functions
 * like ossxInitSoap()
 */
typedef struct OssxTransportData {
    OssxClientTransport *client;
    OssxServerTransport *server;
} OssxTransportData;

/*****************************************************************************/
/*  PUBLIC section: transport-specific error codes                           */
/*****************************************************************************/

/* TCP level */
    /* Error occured while attempting read/write operation on socket */
#define OSSX_HTTP_ERR_SOCKET_ERROR		3001
    /* Unable to resolve host name to IP address */
#define OSSX_HTTP_ERR_ADDRESS_RESOLUTION	3002
    /* Host is not listening for incoming connections */
#define OSSX_HTTP_ERR_UNABLE_TO_CONNECT		3003
    /* Connection was closed on the other side */
#define OSSX_HTTP_ERR_CONNECTION_CLOSED		3004
    /* Socket receive operation timed out */
#define OSSX_HTTP_ERR_READ_TIMEOUT		3005
    /* Socket operation attempted on invalid socket */
#define OSSX_HTTP_ERR_INVALID_SOCKET		3006

/* HTTP level */
    /* Invalid HTTP request method. Not "POST" */
#define OSSX_HTTP_ERR_INVALID_METHOD		3021
    /* HTTP response header was expected but something else was received */
#define OSSX_HTTP_ERR_INVALID_RESPONSE		3022
    /* HTTP request header was expected but something else was received */
#define OSSX_HTTP_ERR_INVALID_REQUEST		3023
    /* Invalid SOAP message type */
#define OSSX_HTTP_ERR_INVALID_TYPE		3024
    /* Missing Content-Length in HTTP header */
#define OSSX_HTTP_ERR_UNKNOWN_SIZE		3025
    /* HTTP header entry line is too long */
#define OSSX_HTTP_ERR_LINE_TOO_LONG		3026
    /* HTTP message payload size exceeds allowed upper limit */ 
#define OSSX_HTTP_ERR_INVALID_SIZE		3027
    /* Some garbage received instead of HTTP header */
#define OSSX_HTTP_ERR_INVALID_HTTP_HEADER	3028
    /* Error receiving HTTP trailing header */
#define OSSX_HTTP_ERR_TRAILING_HEADER		3029
    /* Requested functionality is not supported */
#define OSSX_HTTP_ERR_NOT_IMPLEMENTED		3030

/* Application level */
    /* HTTP server transport failed to locate service using  
     * HTTP request path and no default service was provided */
#define OSSX_HTTP_ERR_SERVICE_NOT_FOUND		3050
    /* Not allowed to invoke this function 
     * from current thread when server is running */ 
#define OSSX_HTTP_ERR_THREAD_SYNCH		3051

/*****************************************************************************/
/*  PUBLIC section: definitions used by various properties supported by      */
/*  OSS-specific transport layers                                            */
/*****************************************************************************/

/* Properties supported by both clients and servers */
#define OSSX_HTTP_FLAGS				1
#define OSSX_HTTP_HEADER			2
#define OSSX_HTTP_VERSION			3
#define OSSX_HTTP_READ_TIMEOUT			4
#define OSSX_HTTP_MAX_CONTENT_LENGTH		5

/* Properties supported by (most) servers */
#define OSSX_SERVER_BODY			1001
#define OSSX_HTTP_REQUEST_HEADER		1002
#define OSSX_HTTP_FAULT_ON_ERROR		1003
#define OSSX_HTTP_USE_SOAPACTION		1004
#define OSSX_SERVER_EVENT_FCN			1005

/* Properties supported by (most) clients */
#define OSSX_HTTP_RESPONSE_HEADER		2001
#define OSSX_HTTP_ENDPOINT			2002

/* Properties supported by standalone HTTP server */
#define OSSX_HTTPSRV_LOCAL_PORT			3001
#define OSSX_HTTPSRV_LOCAL_PATH			3002
#define OSSX_HTTPSRV_DEFAULT_SERVICE		3003
#define OSSX_HTTPSRV_MAX_BUFFER			3004


/*
 * Prototype of server body function (OSSX_SERVER_BODY property)
 */
typedef int (DLL_ENTRY_FPTR *OssxServerBodyFptr)(OssxEnv *, OssxServerSettings *, 
				  OssxMessage *, OssxMessage *);

/* Server event kinds */
typedef enum OssxServerEventCode {
    OSSX_seReady, 
    OSSX_seConnect, 
    OSSX_seError 
} OssxServerEventCode;

/* Server event function return codes */
#define OSSX_SERVER_CONTINUE		0
#define OSSX_SERVER_STOP_SESSION	1
#define OSSX_SERVER_STOP_SERVER		2

/*
 * Prototype of server event function (OSSX_SERVER_EVENT_FCN property)
 */
typedef int (DLL_ENTRY_FPTR *OssxServerEventFcn)(OssxEnv *, OssxServerSettings *,
				  OssxServerEventCode kind,
				  int retcode, OssxMessage *out);

/*
 * HTTP version for OSSX_HTTP_VERSION property (use 0 to set to default)
 */
typedef enum OssxHttpVersion {
    OSSX_http_1_0 = 10, OSSX_http_1_1 = 11
} OssxHttpVersion;

/*
 * HTTP message type (request or response) stored in OssxHttpMessageHeader
 */
typedef enum OssxHttpMessageType {
    OSSX_http_request, OSSX_http_response
} OssxHttpMessageType;

/*
 * HTTP header list (doubly linked list with pointers to head and tail)
 */
typedef struct OssxHttpHeaderEntry {
    struct OssxHttpHeaderEntry	*prev;
    struct OssxHttpHeaderEntry	*next;
    char			*key;
    char			*value;
} OssxHttpHeaderEntry;

typedef struct OssxHttpHeaderList {
    OssxHttpHeaderEntry	    *head;
    OssxHttpHeaderEntry	    *tail;
    int			    count;
} OssxHttpHeaderList;

/*
 * HTTP message header at whole (for request or response) returned by
 * OSSX_HTTP_REQUEST_HEADER and OSSX_HTTP_RESPONSE_HEADER properties.
 */
typedef struct OssxHttpMessageHeader {
    OssxHttpMessageType    message;      /* whether it's a request or response */
    OssxHttpHeaderList     header;       /* session-specific OSSX_HTTP_HEADER */
    OssxHttpVersion	   version;      /* session-specific OSSX_HTTP_VERSION */
    OSSX_UINT32		   flags;        /* session-specific OSSX_HTTP_FLAGS */
    int                    length;       /* Content-Length */
    OssxMIMEType	   type;         /* extracted from Content-Type
					  * (-1 if not identified) */
    char		   *host;        /* request only */
    char		   *path;        /* request only */
    char		   *action;      /* request only */
    char		   method[10];   /* request only */
    int                    status;       /* response only */
    char		   *statusStr;   /* response only */
    OSSX_UINT32		   reserved;
} OssxHttpMessageHeader;

/*
 * Flags supported by OSSX_HTTP_FLAGS property
 */
#define OSSX_HTTP_KEEP_ALIVE_FL			0x0001
/* client + server, HTTP 1.0 only */
#define OSSX_HTTP_CONNECTION_CLOSE_FL		0x0002
/* client + server, HTTP 1.1 only */

/*****************************************************************************/
/*  PUBLIC section: API functions to get transport layers                    */
/*****************************************************************************/

PUBLIC OssxServerTransport * DLL_ENTRY ossxHttpStandaloneServer(void);
PUBLIC OssxClientTransport * DLL_ENTRY ossxHttpStandaloneClient(void);

/*****************************************************************************/
/*  PUBLIC section: XSD/FWS API functions wrapping the server transport      */
/*****************************************************************************/

PUBLIC int DLL_ENTRY ossxSetServerProperty(OssxEnv *in_ctx, OssxServerSettings *in_ss, 
				 int in_kind, void *in_name, void *in_value);
PUBLIC int DLL_ENTRY ossxGetServerProperty(OssxEnv *in_ctx, OssxServerSettings *in_ss, 
				 int in_kind, void *in_name, void **out_value);
PUBLIC int DLL_ENTRY ossxSetServerTransport(OssxEnv *in_ctx, 
					    OssxServerTransport *in_server_transport);
PUBLIC int DLL_ENTRY ossxServerStart(OssxEnv *in_ctx, void *server_data);
PUBLIC int DLL_ENTRY ossxServerStop(OssxEnv *in_ctx);

/*****************************************************************************/
/*  PUBLIC section: XSD/FWS API functions wrapping the client transport      */
/*****************************************************************************/

PUBLIC int DLL_ENTRY ossxSetClientProperty(OssxEnv *in_ctx, void *connection, 
					    int in_kind, void *in_name,
					    void *in_value);
PUBLIC int DLL_ENTRY ossxGetClientProperty(OssxEnv *in_ctx, void *connection, 
					    int in_kind, void *in_name,
					    void **out_value);
PUBLIC int DLL_ENTRY ossxSetClientTransport(OssxEnv *in_ctx, 
					    OssxClientTransport *in_client_transport);
PUBLIC int DLL_ENTRY ossxClientConnect(OssxEnv *in_ctx, void **connection);
PUBLIC int DLL_ENTRY ossxClientDisconnect(OssxEnv *in_ctx, void *connection);
PUBLIC int DLL_ENTRY ossxClientSend(OssxEnv *in_ctx, void **connection, 
				    OssxMessage *in_request, char *in_action);
PUBLIC int DLL_ENTRY ossxClientReceive(OssxEnv *in_ctx, void **connection, 
					    OssxMessage *out_response);
PUBLIC int DLL_ENTRY ossxClientExecute(OssxEnv *in_ctx, void **connection, 
					    OssxEnv *in_inner_ctx, int in_op_id,
					    OssxMessage *in_request, 
					    OssxMessage *out_response);

/*****************************************************************************/
/*  PUBLIC section: helper functions to work with SOAP Envelope              */
/*                                                                           */
/* The below functions may be used to create and process the Envelope        */
/* C structure and the structures within it.                                 */
/*****************************************************************************/

/* Message part constructors */
PUBLIC OssxEnvelope * DLL_ENTRY ossxNewEnvelope(OssxEnv *in_ctx);
PUBLIC OssxHeaderBlock * DLL_ENTRY ossxNewHeaderBlock(OssxEnv *in_ctx);
PUBLIC OssxBody * DLL_ENTRY ossxNewBody(OssxEnv *in_ctx);
PUBLIC OssxFault * DLL_ENTRY ossxNewFault(OssxEnv *in_ctx, OssxCodeValue in_code);

/* Copy constructors */
PUBLIC int DLL_ENTRY ossxCopyEnvelope(OssxEnv *in_ctx, OssxEnvelope *in_env, OssxEnvelope **out_copy);
PUBLIC int DLL_ENTRY ossxCopyHeaderBlock(OssxEnv *in_ctx, OssxHeaderBlock *in_block, OssxHeaderBlock **out_copy);
PUBLIC int DLL_ENTRY ossxCopyHeaderBlocks(OssxEnv *in_ctx, OssxHeader *in_header, OssxHeader *inout_where);
PUBLIC int DLL_ENTRY ossxCopyBody(OssxEnv *in_ctx, OssxBody *in_body, OssxBody **out_copy);
PUBLIC int DLL_ENTRY ossxCopyFault(OssxEnv *in_ctx, OssxFault *in_fault, OssxFault **out_copy);

/* Destructors */
PUBLIC int DLL_ENTRY ossxFreeEnvelope(OssxEnv *in_ctx, OssxEnvelope *inout_env);
PUBLIC int DLL_ENTRY ossxFreeHeaderBlock(OssxEnv *in_ctx, OssxHeaderBlock *inout_block);
PUBLIC int DLL_ENTRY ossxFreeHeaderBlocks(OssxEnv *in_ctx, OssxHeader *inout_header);
PUBLIC int DLL_ENTRY ossxFreeBody(OssxEnv *in_ctx, OssxBody *inout_body);
PUBLIC int DLL_ENTRY ossxFreeFault(OssxEnv *in_ctx, OssxFault *inout_fault);

/* Functions to compare resources */
PUBLIC int DLL_ENTRY ossxCmpEnvelope(OssxEnv *in_ctx, OssxEnvelope *in_env1, OssxEnvelope *in_env2);
PUBLIC int DLL_ENTRY ossxCmpHeaderBlock(OssxEnv *in_ctx, OssxHeaderBlock *in_block1, OssxHeaderBlock *in_block2);
PUBLIC int DLL_ENTRY ossxCmpHeaderBlocks(OssxEnv *in_ctx, OssxHeader *in_header1, OssxHeader *in_header2);
PUBLIC int DLL_ENTRY ossxCmpBody(OssxEnv *in_ctx, OssxBody *in_body1, OssxBody *in_body2);
PUBLIC int DLL_ENTRY ossxCmpFault(OssxEnv *in_ctx, OssxFault *in_fault1, OssxFault *in_fault2);

/* Generic API to work with application content */
PUBLIC int DLL_ENTRY ossxSetContentData(OssxEnv *in_ctx, OssxContent *inout_content, 
			OssxEnv *in_inner_ctx, int in_msg_id, void *in_data);
PUBLIC int DLL_ENTRY ossxGetContentData(OssxEnv *in_ctx, OssxContent *inout_content, 
			OssxEnv **out_inner_ctx, int *out_msg_id, void **out_data);
PUBLIC int DLL_ENTRY ossxFreeContentData(OssxEnv *in_ctx, OssxContent *inout_content);
PUBLIC int DLL_ENTRY ossxGetContentEncoding(OssxEnv *in_ctx, 
			OssxContent *in_content, struct OssxContentEncoding **out_cenc);
					   										      
/* Envelope-level API */
PUBLIC int DLL_ENTRY ossxSetBody(OssxEnv *in_ctx, OssxEnvelope *inout_env, OssxBody *in_body);
PUBLIC int DLL_ENTRY ossxSetFault(OssxEnv *in_ctx, OssxEnvelope *inout_env, OssxFault *in_fault);
PUBLIC int DLL_ENTRY ossxBodyOrFaultChoice(OssxEnv *in_ctx, OssxEnvelope *in_env);
    /* returns env ? env->body_or_fault.choice : 0 */
PUBLIC OssxBody * DLL_ENTRY ossxGetBody(OssxEnv *in_ctx, OssxEnvelope *in_env);
    /* NULL for Envelopes with Faults and for errors */
PUBLIC OssxFault * DLL_ENTRY ossxGetFault(OssxEnv *in_ctx, OssxEnvelope *in_env);
    /* NULL for Envelopes with Bodies and errors */

/* Header-level list API */
PUBLIC int DLL_ENTRY ossxAppendHeaderBlock(OssxEnv *in_ctx, OssxHeader *inout_h, OssxHeaderBlock *in_block,
    OssxHeaderNode **out_node);
PUBLIC int DLL_ENTRY ossxPrependHeaderBlock(OssxEnv *in_ctx, OssxHeader *inout_h, OssxHeaderBlock *in_block,
    OssxHeaderNode **out_node);
PUBLIC int DLL_ENTRY ossxInsertHeaderBlock(OssxEnv *in_ctx, OssxHeader *inout_h, OssxHeaderNode *inout_prev,
    OssxHeaderBlock *in_block, OssxHeaderNode **out_node);
PUBLIC int DLL_ENTRY ossxUnlinkHeaderBlock(OssxEnv *in_ctx, OssxHeader *inout_h, OssxHeaderNode *inout_node,
    OssxHeaderBlock **out_block);
PUBLIC int DLL_ENTRY ossxNextHeaderNode(OssxEnv *in_ctx, OssxHeader *in_h, OssxHeaderNode **out_node);

/* Header block-level API */
PUBLIC int DLL_ENTRY ossxSetHeaderContent(OssxEnv *in_ctx, OssxHeaderBlock *inout_block,
			OssxEnv *in_inner_ctx, int in_msg_id, void *in_data);
PUBLIC int DLL_ENTRY ossxGetHeaderContent(OssxEnv *in_ctx, OssxHeaderBlock *inout_block,
			OssxEnv **out_inner_ctx,  int *out_msg_id, void **out_data);
PUBLIC int DLL_ENTRY ossxSetHeaderMustUnderstandAttr(OssxEnv *in_ctx, OssxHeaderBlock *inout_block, ossxBoolean in_v);
PUBLIC ossxBoolean DLL_ENTRY ossxGetHeaderMustUnderstandAttr(OssxEnv *in_ctx, OssxHeaderBlock *in_block);
    /* should not be called when !ossxIsMustUnderstandPresent */
PUBLIC ossxBoolean DLL_ENTRY ossxIsHeaderMustUnderstandAttrPresent(OssxEnv *in_ctx, OssxHeaderBlock *in_block);
PUBLIC int DLL_ENTRY ossxOmitHeaderMustUnderstandAttr(OssxEnv *in_ctx, OssxHeaderBlock *inout_block);

PUBLIC int DLL_ENTRY ossxSetHeaderRelayAttr(OssxEnv *in_ctx, OssxHeaderBlock *inout_block, ossxBoolean in_v);
PUBLIC ossxBoolean DLL_ENTRY ossxGetHeaderRelayAttr(OssxEnv *in_ctx, OssxHeaderBlock *in_block);
    /* should not be called when !ossxIsRelayPresent */
PUBLIC ossxBoolean DLL_ENTRY ossxIsHeaderRelayAttrPresent(OssxEnv *in_ctx, OssxHeaderBlock *in_block);
PUBLIC int DLL_ENTRY ossxOmitHeaderRelayAttr(OssxEnv *in_ctx, OssxHeaderBlock *inout_block);

PUBLIC int DLL_ENTRY ossxSetHeaderRoleAttr(OssxEnv *in_ctx, OssxHeaderBlock *inout_block, OssxAnyURI in_role, ossxBoolean in_copy);
    /* NULL == default */
PUBLIC int DLL_ENTRY ossxGetHeaderRoleAttr(OssxEnv *in_ctx, OssxHeaderBlock *in_block, OssxAnyURI *out_role, ossxBoolean in_copy);

PUBLIC OssxHeaderBlock * DLL_ENTRY ossxNewHeaderBlockForMessage(OssxEnv *in_ctx, OssxEnv *in_inner_ctx, 
				int in_msg_id, void *in_data);

/* Body-level API */
PUBLIC int DLL_ENTRY ossxSetBodyContent(OssxEnv *in_ctx, OssxBody *inout_body,
			OssxEnv *in_inner_ctx, int in_msg_id, void *in_data);
PUBLIC int DLL_ENTRY ossxGetBodyContent(OssxEnv *in_ctx, OssxBody *inout_body,
			OssxEnv **out_inner_ctx,  int *out_msg_id, void **out_data);
PUBLIC int DLL_ENTRY ossxOmitBodyContent(OssxEnv *in_ctx, OssxBody *inout_body);
PUBLIC ossxBoolean DLL_ENTRY ossxIsBodyContentPresent(OssxEnv *in_ctx, OssxBody *in_body);

/* Fault-level API */
PUBLIC int DLL_ENTRY ossxSetFaultDetail(OssxEnv *in_ctx, OssxFault *inout_fault,
				OssxEnv *in_inner_ctx, int in_msg_id, void *in_data);
PUBLIC int DLL_ENTRY ossxGetFaultDetail(OssxEnv *in_ctx, OssxFault *in_fault, 
				OssxEnv **out_inner_ctx,  int *out_msg_id, void **out_data);
PUBLIC int DLL_ENTRY ossxOmitFaultDetail(OssxEnv *in_ctx, OssxFault *inout_fault);
PUBLIC ossxBoolean DLL_ENTRY ossxIsFaultDetailPresent(OssxEnv *in_ctx, OssxFault *in_fault);

PUBLIC int DLL_ENTRY ossxSetFaultCodeValue(OssxEnv *in_ctx, OssxFault *inout_fault, OssxCodeValue in_value);
PUBLIC int DLL_ENTRY ossxGetFaultCodeValue(OssxEnv *in_ctx, OssxFault *in_fault, OssxCodeValue *out_value);

PUBLIC int DLL_ENTRY ossxAppendSubcode(OssxEnv *in_ctx, OssxFault *inout_fault, OssxAnyURI in_uri, OssxString in_name,
    OssxSubcodeNode **out_node);
PUBLIC int DLL_ENTRY ossxPrependSubcode(OssxEnv *in_ctx, OssxFault *inout_fault, OssxAnyURI in_uri, OssxString in_name,
    OssxSubcodeNode **out_node);
PUBLIC int DLL_ENTRY ossxInsertSubcode(OssxEnv *in_ctx, OssxFault *inout_fault, OssxSubcodeNode *inout_prev,
    OssxAnyURI in_uri, OssxString in_name, OssxSubcodeNode **out_node);
PUBLIC int DLL_ENTRY ossxUnlinkSubcode(OssxEnv *in_ctx, OssxFault *inout_fault, OssxSubcodeNode *inout_node,
    OssxAnyURI *out_uri, OssxString *out_name);
PUBLIC int DLL_ENTRY ossxNextSubcode(OssxEnv *in_ctx, OssxFault *in_fault, OssxSubcodeNode **out_node);

PUBLIC int DLL_ENTRY ossxAppendReason(OssxEnv *in_ctx, OssxFault *inout_fault, OssxLanguage in_language,
    OssxString in_text, OssxReasonNode **out_node);
PUBLIC int DLL_ENTRY ossxPrependReason(OssxEnv *in_ctx, OssxFault *inout_fault, OssxLanguage in_language,
    OssxString in_text, OssxReasonNode **out_node);
PUBLIC int DLL_ENTRY ossxInsertReason(OssxEnv *in_ctx, OssxFault *inout_fault, OssxReasonNode *inout_prev,
    OssxLanguage in_language, OssxString in_text, OssxReasonNode **out_node);
PUBLIC int DLL_ENTRY ossxUnlinkReason(OssxEnv *in_ctx, OssxFault *inout_fault, OssxReasonNode *inout_node,
    OssxLanguage *out_language, OssxString *out_text);
PUBLIC int DLL_ENTRY ossxNextReason(OssxEnv *in_ctx, OssxFault *in_fault, OssxReasonNode **out_node);

PUBLIC int DLL_ENTRY ossxSetFaultNodeAttr(OssxEnv *in_ctx, OssxFault *inout_fault, OssxAnyURI in_node, ossxBoolean in_copy);
    /* NULL == default */
PUBLIC int DLL_ENTRY ossxGetFaultNodeAttr(OssxEnv *in_ctx, OssxFault *in_fault, OssxAnyURI *out_node, ossxBoolean in_copy);

PUBLIC int DLL_ENTRY ossxSetFaultRoleAttr(OssxEnv *in_ctx, OssxFault *inout_fault, OssxAnyURI in_role, ossxBoolean in_copy);
    /* NULL == default */
PUBLIC int DLL_ENTRY ossxGetFaultRoleAttr(OssxEnv *in_ctx, OssxFault *in_fault, OssxAnyURI *out_role, ossxBoolean in_copy);

PUBLIC int DLL_ENTRY ossxNewFaultForMessage(OssxEnv *in_ctx, 
				    OssxCodeValue code, char *lang, 
				    unsigned char *reason,
				    OssxEnv *in_inner_ctx, int in_msg_id, 
				    void *in_data,
				    OssxEnvelope **out_fault);

/*****************************************************************************/
/*  PUBLIC section: core Fast Web Services runtime functions                 */
/*****************************************************************************/

PUBLIC int DLL_ENTRY ossxSetSoapFlags(OssxEnv *in_ctx, OSSX_UINT32 in_flags);
PUBLIC OSSX_UINT32 DLL_ENTRY ossxGetSoapFlags(OssxEnv *in_ctx);

PUBLIC int DLL_ENTRY ossxSetSoapVersion(OssxEnv *in_ctx, OssxSoapVersion in_version);
PUBLIC OssxSoapVersion DLL_ENTRY ossxGetSoapVersion(OssxEnv *in_ctx);

PUBLIC OssxSoapVersion DLL_ENTRY ossxGetDecodedSoapVersion(OssxEnv *in_ctx);

PUBLIC int DLL_ENTRY ossxInitSoap(OssxEnv *in_ctx, void *in_ctl_tbl, 
			    OssxTransportData *in_transport, OssxEnv **out_inner_ctx);
PUBLIC int DLL_ENTRY ossxAddWebService(OssxEnv *in_ctx, void *in_ctl_tbl,
			    OssxEnv **out_inner_ctx);
PUBLIC void DLL_ENTRY ossxTermSoap(OssxEnv *in_ctx);
PUBLIC int DLL_ENTRY ossxDupSoapContext(OssxEnv *world, OssxEnv *dup_ctx);

PUBLIC int DLL_ENTRY ossxInitSoapDll(OssxEnv *in_ctx, void *in_ctrl_tbl, 
			    char *in_dllName, OssxTransportData *in_transport, OssxEnv **out_inner_ctx);
PUBLIC int DLL_ENTRY ossxAddWebServiceDll(OssxEnv *in_ctx, void *in_ctl_tbl, 
			    char *in_dllName, OssxEnv **out_inner_ctx);
PUBLIC void DLL_ENTRY ossxTermSoapDll(OssxEnv *in_ctx);

PUBLIC int DLL_ENTRY  ossxGetServiceContext(OssxEnv *in_ctx, void *in_ctl_tbl,
			    OssxEnv **out_inner_ctx);

/* Utility functions */
PUBLIC long DLL_ENTRY ossxDetermineSoapEncodingLength(OssxEnv *in_ctx,
			    OssxEnvelope *in_data, OssxMIMEType in_type);
PUBLIC int DLL_ENTRY ossxFastSoap2XML(OssxEnv *in_ctx,
			    OssxBuf *in_buf, OssxBuf *out_buf);
PUBLIC int DLL_ENTRY ossxXML2FastSoap(OssxEnv *in_ctx,
			    OssxBuf *in_buf, OssxBuf *out_buf);

/* SOAP Decoder specific flags */
#define OSSX_RELAY_HEADERS	0x00000001
#define OSSX_RELAY_BODY_FAULT	0x00000002

#define OSSX_RELAY_SOAP (OSSX_RELAY_HEADERS | OSSX_RELAY_BODY_FAULT)

#define OSSX_IDENTIFY_HEADERS	0x00000004
#define OSSX_IDENTIFY_BODY	0x00000008
#define OSSX_IDENTIFY_FAULT	0x00000010

#define OSSX_IDENTIFY_SOAP (OSSX_IDENTIFY_HEADERS | \
				OSSX_IDENTIFY_BODY | \
			        OSSX_IDENTIFY_FAULT)

/* SOAP runtime flags */
#define OSSX_AUTO_ENCDEC_BODY	 0x00000020
#define OSSX_AUTO_ENCDEC_HEADERS 0x00000040
#define OSSX_AUTO_ENCDEC_FAULT	 0x00000080

#define OSSX_AUTO_ENCDEC_SOAP (OSSX_AUTO_ENCDEC_HEADERS | \
				OSSX_AUTO_ENCDEC_BODY | \
				OSSX_AUTO_ENCDEC_FAULT)

#define OSSX_RELAX_SOAP		 0x00000100

/* SOAP Copy/Compare specific flags */
#define OSSX_SKIP_ENCODED_MSG 	0x00000200 
			/* when calling ossxCopyEnvelope()/ossxCmpEnvelope()
                         * and lower level copying/comparing API, don't
                         * copy/compare encoded user-defined messages */
#define OSSX_SKIP_DECODED_MSG 	0x00000400
			/* when calling ossxCopyEnvelope()/ossxCmpEnvelope()
                         * and lower level copying/comparing API, don't
                         * copy/compare decoded user-defined messages */

/* General-purpose flags */
#define OSSX_OWN_RPC_PARAM 	0x00000800
#define OSSX_FREE_PARAM         0x00001000

/* Additional SOAP Decoder specific flags */
#define OSSX_END_OF_HEADERS	0x00002000
#define OSSX_SKIP_HEADERS	0x00004000
#define OSSX_SKIP_BODY_FAULT	0x00008000
#define OSSX_SET_QNAME_ID       0x00010000

/* Encoding and decoding functions */

PUBLIC int DLL_ENTRY ossxEncodeSoapMessage(OssxEnv *in_ctx, 
			    OssxEnvelope *in_envelope, OssxMessage *out_msg);
PUBLIC int DLL_ENTRY ossxDecodeSoapMessage(OssxEnv *in_ctx, OssxMessage *in_msg, 
			    OssxMessage *out_msg, OssxEnvelope **out_envelope, 
			    void *inout_userData);

/* SOAP decoder-specific functions */
/* SOAP Decoder callbacks */

typedef int (*headerCallback)(OssxEnv *in_ctx, OssxEnv *in_inner_ctx,
        OssxHeaderBlock *inout_block, void *inout_userData);
typedef int (*bodyCallback)(OssxEnv *in_ctx, OssxEnv *in_inner_ctx,
        OssxBody *inout_body, void *inout_userData);
typedef int (*faultCallback)(OssxEnv *in_ctx, OssxEnv *in_inner_ctx,
        OssxFault *inout_fault, void *inout_userData);

PUBLIC int DLL_ENTRY ossxSetSOAPCallbacks(OssxEnv *in_ctx, headerCallback in_hc,
                                   bodyCallback in_bc,
                                   faultCallback in_fc);
PUBLIC int DLL_ENTRY ossxGetSOAPCallbacks(OssxEnv *in_ctx, headerCallback *out_hc,
                                   bodyCallback *out_bc,
                                   faultCallback *out_fc);

/* Functions to call from callbacks */

PUBLIC int DLL_ENTRY ossxIdentifyMessage(OssxEnv *in_ctx, OssxIdentifier *in_id, 
				     OssxEnv **inout_inner_ctx, int *out_msg_id);

PUBLIC int DLL_ENTRY ossxRelayHeaderBlock(OssxEnv *in_ctx, OssxHeaderBlock *in_block);
PUBLIC int DLL_ENTRY ossxRelayBody(OssxEnv *in_ctx, OssxBody *in_body);
PUBLIC int DLL_ENTRY ossxRelayFault(OssxEnv *in_ctx, OssxFault *in_fault);
PUBLIC int DLL_ENTRY ossxRelayCurrentEncoding(OssxEnv *in_ctx);

/* Helper functions */

PUBLIC int DLL_ENTRY ossxAddHeaderBlock(OssxEnv *in_ctx, OssxMessage *in_msg, 
				    OssxMessage *out_msg, OssxHeaderBlock *in_block);

/* These API functions are intended for transport layer development */
PUBLIC int DLL_ENTRY ossxGetOperationInfo(OssxEnv *in_ctx, OssxEnv *in_inner_ctx,
				    int in_op_id, OssxOperationInfo **out_op_info);
PUBLIC int DLL_ENTRY ossxGetSoapAction(OssxEnv *in_ctx, 
				    OssxEnv *in_inner_ctx, 
				    int in_op_id, 
				    char **out_action);
PUBLIC int DLL_ENTRY ossxSetErrMsg(OssxEnv *in_ctx, char *text);
PUBLIC int DLL_ENTRY ossxGetTransportDefaults(OssxEnv *in_ctx, 
				    OssxEnv *in_inner_ctx, 
				    OssxTransDflt **out_trans_dflt);

/*****************************************************************************/
/*  NON-PUBLIC section: data alignment section - revert to user-defined data */
/*  alignment                                                                */
/*****************************************************************************/

#ifdef __cplusplus
}
#endif

#if defined(macintosh) && defined(__CFM68K__)
#pragma import reset
#endif

#if defined(_MSC_VER) && (defined(_WIN32) || defined(WIN32) \
			|| defined(WINCE) || defined(_WIN64))
#pragma pack(pop, ossxPacking)
#elif defined(_MSC_VER) && (defined(_WINDOWS) || defined(_MSDOS))
#pragma pack()
#elif defined(__BORLANDC__) && (defined(__WIN32__) || defined(__MSDOS__))
#pragma option -a.
#elif defined(__IBMC__) && (defined(__WIN32__) || defined(__OS2__))
#pragma pack()
#elif defined(__WATCOMC__) && (defined(__NT__) || defined(__WINDOWS__) \
			|| defined(__DOS__))
#pragma pack(pop)
#endif /* _MSC_VER && _WIN32 */

#endif /* OSSFWS_H */
