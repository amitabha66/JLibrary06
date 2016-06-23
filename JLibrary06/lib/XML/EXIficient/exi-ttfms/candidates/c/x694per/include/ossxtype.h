/***************************************************************************
 * Copyright (C) 1993-2006 OSS Nokalva, Inc.  All rights reserved.
 ***************************************************************************/
/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.
 * AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.
 * THIS FILE MAY NOT BE DISTRIBUTED. */
/*****************************************************************************/
/* FILE: @(#)ossxtype.hh	15.10 06/03/19                                         */
/*****************************************************************************/

#ifndef OSSXTYPE_H
#define OSSXTYPE_H
#include "ossxsd.h"
#include <stdarg.h>
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
#endif /* _MSC_VER && (WINCE || _WIN64) */
#if defined(macintosh) && defined(__CFM68K__)
#pragma import on
#endif
#ifdef __cplusplus
extern "C"
{
#endif
#define USE_ETYPE_INDICES    0x2 
extern void *DLL_ENTRY ossxGetHeader(void);
PUBLIC void DLL_ENTRY ossxInitRootContext(struct ossxEnv *, unsigned char *);
PUBLIC void DLL_ENTRY ossxInitRootContext1(struct ossxEnv *, unsigned char *);
#if defined(_WINDOWS) || defined(_DLL) || \
	defined(OS2_DLL) || defined(NETWARE_DLL)
PUBLIC void DLL_ENTRY ossxLinkAPI(struct ossxEnv *);
#endif /* _WINDOWS || _DLL || OS2_DLL || NETWARE_DLL */
PUBLIC void DLL_ENTRY ossxLinkBer(struct ossxEnv *);
PUBLIC void DLL_ENTRY ossxLinkDer(struct ossxEnv *);
PUBLIC void DLL_ENTRY ossxLinkPer(struct ossxEnv *);
PUBLIC unsigned long DLL_ENTRY ossxGetPresetDecFlags(struct ossxEnv *);
PUBLIC void DLL_ENTRY ossxSetPresetDecFlags(struct ossxEnv *, unsigned long);
PUBLIC void DLL_ENTRY ossxPrivateSetMoreFlags(struct ossxEnv *, int,
							unsigned char *);
PUBLIC void DLL_ENTRY ossxPrivateGetMoreFlags(struct ossxEnv *world, int *,
							unsigned char **);
PUBLIC void DLL_ENTRY _ossx_db_e_pre(struct ossxEnv *world,
	int _oss_Jw, void *_oss_HWW, unsigned int *_oss_qwW,
	char *_oss_wJJ, long _oss_QQW);
PUBLIC void DLL_ENTRY _ossx_db_e_post(struct ossxEnv *world,
	int _oss_qH, char *_oss_WJH, long _oss_QwW);
PUBLIC void DLL_ENTRY_FDEF _ossx_db_d_pre(struct ossxEnv *world,
	char *_oss_HQW, long _oss_HjJ, unsigned int *_oss_QqJ);
PUBLIC void DLL_ENTRY_FDEF _ossx_db_d_post(struct ossxEnv *world,
	int _oss_qH, int _oss_Jw, void **_oss_wHW);
typedef unsigned short Etag;
typedef struct efield *_oss_WQJ;
typedef struct etype *_oss_jw;
typedef struct eheader *Eheader;
struct etype {
    long            max_length;
    size_t          _oss_QW;
    size_t          _oss_WwJ;
    char           *_oss_W;
    size_t          _oss_QWJ;
    size_t          _oss_qjW;
    unsigned short int _oss_jJH;
    unsigned short int _oss_jqJ;
    unsigned short int _oss_WQW;
    unsigned short int _oss_wjW;
    int                _oss_JJ;	    
    unsigned short int _oss_Hj;
};
struct efield {
    size_t          _oss_JQJ;	
    unsigned short int _oss_wJ;	
    short int       _oss_WqJ;	
    unsigned short int _oss_WWJ;	
    unsigned char   _oss_jwJ;	
};
struct ConstraintEntry {
    char            _oss_qQH;
    char            _oss_HQH;
    void           *_oss_HW;
};
struct InnerSubtypeEntry {
    char		_oss_qQJ;
    unsigned char	_oss_Q;
    unsigned short	_oss_jJ;	     
    unsigned short	_oss_HW;  
};
typedef struct WideAlphabet {
    OSSX_UINT32  _oss_JQJ; 
    struct {
	short _oss_JwJ;   
	char  *_oss_HJ;   
    } _oss_QJJ;
    void *        _oss_JJH; 
} WideAlphabet;
typedef struct eda_table {
    unsigned int _oss_wH;
    unsigned char *_oss_Q;
} eda_table;
struct eheader {
#if defined(__WATCOMC__) && defined(__DOS__)
    void (*_oss_qj)(struct ossxEnv *); 
#else
    void (DLL_ENTRY_FPTR *_System _oss_qj)(struct ossxEnv *); 
#endif /* __WATCOMC__ && __DOS__ */
    long            _oss_HwJ;	
    unsigned short int _oss_wH;	
    unsigned short int _oss_Q;	
    unsigned short int _oss_WJJ,
                    _oss_JjW;	
    unsigned short *_oss_HHJ;	
    _oss_jw           etypes;	
    _oss_WQJ          _oss_qqJ;	
    void          **_oss_QWH;	
    unsigned short *_oss_QW;	
    struct ConstraintEntry *_oss_Hj;
    struct InnerSubtypeEntry *_oss_wwJ;	
    void           *_oss_wQW;	
    unsigned short int _oss_qwJ; 
};
PUBLIC void DLL_ENTRY ossxLinkConstraint(struct ossxEnv *);
PUBLIC void DLL_ENTRY ossxEDLinkPer(struct ossxEnv *world, void *eda_table);
PUBLIC void DLL_ENTRY ossxLinkSAX(struct ossxEnv *world, void *_xml_table, 
	void *_oss_JJJ);
PUBLIC void DLL_ENTRY ossxLinkSAXParser(struct ossxEnv *world);
PUBLIC void DLL_ENTRY ossxSetExtParms(struct ossxEnv *world, void  *arg);
PUBLIC void DLL_ENTRY ossxLinkConstraintSpartanAware8(struct ossxEnv *);
PUBLIC void DLL_ENTRY ossxLinkCmpValue(struct ossxEnv *);
PUBLIC void DLL_ENTRY ossxLinkCpyValue(struct ossxEnv *);
PUBLIC void DLL_ENTRY ossxLinkZlib(struct ossxEnv *);
PUBLIC void DLL_ENTRY ossxLinkBerReal(struct ossxEnv *);
PUBLIC void DLL_ENTRY ossxLinkConstraintReal(struct ossxEnv *);
PUBLIC void DLL_ENTRY ossxLinkPatternConstraint(struct ossxEnv *);
#ifdef OSSX_SOED_BER
PUBLIC void DLL_ENTRY ossxLinkCer(struct ossxEnv *);
#endif /* OSSX_SOED_BER */
#ifdef OSSX_SOED_PER
PUBLIC void DLL_ENTRY ossxLinkPerReal(struct ossxEnv *);
#endif /* OSSX_SOED_PER */
#if defined(OSSX_SOED_XML)
typedef struct {
    OSSX_UINT16 _oss_JJ;
    void *_oss_Hw;			
} _xml_search;
typedef struct {
    unsigned char *_oss_W;
    OSSX_UINT16 _oss_QJ;	    
} _xml_table_entry;
typedef struct {
    OSSX_UINT16 _oss_qq;
    _xml_table_entry *_oss_q;	
} _xml_binary_table;
typedef struct {
    unsigned char *_oss_qWW;
    OSSX_UINT16 _oss_JJW;		
    OSSX_UINT16 _oss_QJ;
} _xml_hash_table_entry;
typedef struct {
    _xml_hash_table_entry *_oss_q;
    OSSX_UINT32 _oss_wWJ;
    OSSX_UINT16 _oss_qq;
} _xml_hash_table;
#endif /* OSSX_SOED_XML || !SHIPPING */
typedef struct {
    OSSX_UINT32 _oss_Q;
    void *_oss_HWJ;		
    unsigned char *_oss_jWW;	
    OSSX_UINT16 _oss_QJH;		
    OSSX_UINT16 _oss_QqW;	
} _xml_tag_decoder;
typedef struct {
    OSSX_UINT32 _oss_Q;
    _xml_tag_decoder *_oss_QW;
    OSSX_UINT32 _oss_WWH;		
} _xml_decode_position;
#if defined(OSSX_SOED_XML)
typedef struct {
    unsigned char *_oss_j;
    OSSX_UINT16 _oss_QJ;
} _xml_uri_test;
typedef struct {
    _xml_search _oss_Hq;		
    _xml_uri_test *_oss_JwW;	
} _xml_qname_table;
typedef struct {
    unsigned char *_oss_j;
    OSSX_UINT16 _oss_JJ;
    OSSX_UINT16 _oss_QJ;		
} _xml_uri_table_entry;
typedef struct {
    OSSX_UINT32 _oss_qJ;		    
    _xml_uri_table_entry *_oss_q;    
    _xml_search *_oss_WqW;	    
} _xml_uri_table;
typedef struct {
    OSSX_UINT16 _oss_Q;
    unsigned char *_oss_j;
    unsigned char *_oss_QWW;
} _xml_namespace;
typedef struct {
    unsigned char *_oss_WjJ;	    
    unsigned char *_oss_QQH;    
    unsigned char *_oss_HqW;	    
    unsigned char *_oss_qWH;	    
    void *_oss_qJJ;	    
    void *_oss_wJW;	    
    OSSX_UINT16 _oss_wjJ;   
    OSSX_UINT16 _oss_jJJ;       
    OSSX_UINT16 *_oss_HJW;        
} _xml_extra_data;
typedef struct {
    OSSX_INT32 _oss_wW;	
    void ** _oss_JWW;	
} _xml_ext;
typedef struct {
    OSSX_UINT32 _oss_jjJ;
    OSSX_UINT32 _oss_qJH;
    unsigned char *_oss_W;	    
    OSSX_UINT16 _oss_wWH;		    
    void *_oss_wqW;		    
    _xml_extra_data *_oss_jWH;    
    _xml_ext _oss_QHJ;	    
} _xml_type;
typedef struct {
    void         *_oss_q;
    OSSX_UINT32    _oss_wW;
} _xml_extensions_list;
typedef struct {
    OSSX_UINT32             _oss_qqW;
    OSSX_UINT16             _oss_Jq;
    OSSX_UINT16             _oss_Wq;
    OSSX_INT32              _oss_JqW;
    _xml_type             *_oss_qHJ;
    OSSX_INT32              _oss_jqW;
    _xml_namespace        *_oss_WjW;
    _xml_search		  *_oss_JQH;
    _xml_decode_position   _oss_QJW;
    unsigned char	  *_oss_HJJ;
    OSSX_UINT16		   _oss_wwW;
    OSSX_UINT16		   _oss_qWJ;
    OSSX_UINT16             _oss_WQH;
    OSSX_INT32              _oss_JjJ;
    void                 **_oss_jJW;
    OSSX_INT32              _oss_jjW;
    _xml_extensions_list  *_oss_HJH;
} _xml_table;
typedef struct {
    OSSX_UINT16 _oss_JJ;
    OSSX_UINT16 _oss_qJ;	
    void *_oss_Hw;		
} _xml_enum_table;
typedef struct {
    _xml_enum_table _oss_JqJ;	
    _xml_search _oss_Wj;	
    OSSX_UINT32 _oss_WWW;         
} _xml_enum_data;
typedef struct {
    OSSX_INT32 _oss_HJ;		
    unsigned char *_oss_W;	
} _xml_enum_value;
typedef struct {
    LONG_LONG _oss_HJ;		
    unsigned char *_oss_W;	
} _xml_long_enum_value;
typedef struct {
    OSSX_UINT32 _oss_WwW;	    
    OSSX_UINT16 *_oss_wqJ;    
} _xml_union_data;
typedef struct {
    OSSX_UINT16 _oss_qJ;		
    OSSX_UINT16 _oss_qjJ;	
    OSSX_UINT32 _oss_WHJ;	
    OSSX_UINT32 *_oss_wJH;		
} _xml_order_data;
typedef struct {
    OSSX_UINT16 _oss_Q;
    _xml_search _oss_Hq;		
} _xml_wild_data;
typedef struct {
    _xml_tag_decoder *_oss_QH; 
    _xml_decode_position _oss_Wj;   
} _xml_set_data;
typedef struct {
    _xml_tag_decoder *_oss_QH; 
    _xml_decode_position *_oss_HHW; 
} _xml_sequence_data;
struct _XMLEncContext;
struct _XMLDecContext;
typedef void (*ossxXMLencodefp)(struct _XMLEncContext *);
typedef void (*ossxXMLencodeIfp)(struct _XMLEncContext *);
typedef void (*ossxXMLdecodefp)(struct _XMLDecContext *);
typedef void (*ossxXMLdecodeIfp)(struct _XMLDecContext *);
#if defined(DLL_LINKAGE)
extern ossxXMLencodefp *_ossx_getXMLencode_efp(void);
extern ossxXMLdecodefp *_ossx_getXMLdecode_efp(void);
extern ossxXMLencodeIfp *_ossx_getXMLencode_ifp(void);
extern ossxXMLdecodeIfp *_ossx_getXMLdecode_ifp(void);
#endif /* DLL_LINKAGE */
PUBLIC void DLL_ENTRY ossxLink_EXml (OssxEnv *, void *,
	unsigned short , int const * , ossxXMLencodefp *,
	unsigned short , int const * , ossxXMLencodeIfp *);
PUBLIC void DLL_ENTRY ossxLink_DXml (OssxEnv *, void *,
	unsigned short , int const * , ossxXMLdecodefp *,
	unsigned short , int const * , ossxXMLdecodeIfp *);
PUBLIC void DLL_ENTRY ossxLink_Xml (OssxEnv *, void *);
PUBLIC void DLL_ENTRY ossxLink_XmlReal(OssxEnv *);
#endif /* OSSX_SOED_XML || !SHIPPING */
#if defined(OSSX_SOED_XML)
extern void			_ossx_exml_int (struct _XMLEncContext * ctx);
#define _ossx_exml_uint		_ossx_exml_int
extern void			_ossx_exml_enum (struct _XMLEncContext * ctx);
#define _ossx_exml_uenum		_ossx_exml_enum
extern void			_ossx_exml_null (struct _XMLEncContext * ctx);
extern void			_ossx_exml_real (struct _XMLEncContext * ctx);
extern void			_ossx_exml_char_real (struct _XMLEncContext * ctx);
extern void			_ossx_exml_mixed_real (struct _XMLEncContext * ctx);
extern void			_ossx_exml_bool (struct _XMLEncContext * ctx);
extern void			_ossx_exml_seq (struct _XMLEncContext * ctx);
#define _ossx_exml_set		_ossx_exml_seq
#define _ossx_exml_embedded_pdv	_ossx_exml_seq
#define _ossx_exml_char_string	_ossx_exml_seq
extern void			_ossx_exml_choice (struct _XMLEncContext * ctx);
extern void			_ossx_exml_link_seqof (struct _XMLEncContext * ctx);
#define _ossx_exml_dlink_plus_seqof	_ossx_exml_link_seqof
extern void			_ossx_exml_unbnd_seqof (struct _XMLEncContext * ctx);
#define _ossx_exml_unbnd_setof	_ossx_exml_unbnd_seqof
#define _ossx_exml_array_seqof	_ossx_exml_unbnd_seqof
#define _ossx_exml_array_setof	_ossx_exml_unbnd_seqof
extern void			_ossx_exml_unbnd_octet (struct _XMLEncContext * ctx);
#define _ossx_exml_vary_octet	_ossx_exml_unbnd_octet
extern void                     _ossx_exml_unbnd_char (struct _XMLEncContext * ctx);
#define _ossx_exml_vary_char	_ossx_exml_unbnd_char
#define _ossx_exml_nlltrm_char	_ossx_exml_unbnd_char
extern void			_ossx_exml_pad_char (struct _XMLEncContext * ctx);
extern void			_ossx_exml_4byte_char (struct _XMLEncContext * ctx);
#define _ossx_exml_2byte_char	_ossx_exml_4byte_char
extern void			_ossx_exml_huge_int (struct _XMLEncContext * ctx);
extern void _ossx_exml_not_supported (struct _XMLEncContext * ctx);
#define _ossx_exml_defer		_ossx_exml_not_supported
#define _ossx_exml_defer_obj	_ossx_exml_not_supported
extern void    			_ossx_exml_anyattr_nlltrm_char(struct _XMLEncContext * ctx);
extern void  			_ossx_exml_normal_int(struct _XMLEncContext * ctx);
extern void 			_ossx_exml_normal_enum(struct _XMLEncContext * ctx);
extern void    			_ossx_exml_base64_unbnd_char(struct _XMLEncContext * ctx);
extern void    			_ossx_exml_normal_unbnd_char(struct _XMLEncContext * ctx);
extern void    			_ossx_exml_base64_unbnd_octet(struct _XMLEncContext * ctx);
extern void    			_ossx_exml_normal_unbnd_octet(struct _XMLEncContext * ctx);
#define _ossx_exml_base64_pad_char	_ossx_exml_base64_unbnd_char
#define	_ossx_exml_normal_pad_char	_ossx_exml_normal_unbnd_char
#define	_ossx_exml_base64_nlltrm_char	_ossx_exml_base64_unbnd_char
#define _ossx_exml_normal_nlltrm_char	_ossx_exml_normal_unbnd_char
extern void			_ossx_exml_anyel_nlltrm_char(struct _XMLEncContext * ctx);
extern void    			_ossx_exml_base64_4byte_char(struct _XMLEncContext * ctx);
extern void    			_ossx_exml_normal_4byte_char(struct _XMLEncContext * ctx);
#define _ossx_exml_useorder_seq		_ossx_exml_not_supported
extern void    			_ossx_exml_qname_seq(struct _XMLEncContext * ctx);
#define _ossx_exml_normal_seq		_ossx_exml_not_supported
#define _ossx_exml_anyattr_link_sof	_ossx_exml_anyattr_nlltrm_char
#define _ossx_exml_normal_link_sof	_ossx_exml_not_supported
#define _ossx_exml_base64_opentype	_ossx_exml_base64_unbnd_octet
#define _ossx_exml_normal_opentype	_ossx_exml_normal_unbnd_octet
extern void			_ossx_exml_normal_real(struct _XMLEncContext * ctx);
extern void			_ossx_exml_modified_real(struct _XMLEncContext * ctx);
extern void			_ossx_exml_normal_char_real(struct _XMLEncContext * ctx);
extern void			_ossx_exml_modified_char_real(struct _XMLEncContext * ctx);
extern void			_ossx_exml_decimal_char_real(struct _XMLEncContext * ctx);
extern void			_ossx_dxml_int (struct _XMLDecContext * ctx);
#define _ossx_dxml_uint		_ossx_dxml_int
#define _ossx_dxml_enum		_ossx_dxml_int
#define _ossx_dxml_uenum		_ossx_dxml_int
extern void			_ossx_dxml_unbnd_octet (struct _XMLDecContext * ctx);
#define _ossx_dxml_vary_octet	_ossx_dxml_unbnd_octet
extern void			_ossx_dxml_null (struct _XMLDecContext * ctx);
extern void			_ossx_dxml_real (struct _XMLDecContext * ctx);
extern void			_ossx_dxml_bool (struct _XMLDecContext * ctx);
extern void			_ossx_dxml_seq (struct _XMLDecContext * ctx);
extern void			_ossx_dxml_set (struct _XMLDecContext * ctx);
extern void			_ossx_dxml_choice (struct _XMLDecContext * ctx);
extern void			_ossx_dxml_link_seqof (struct _XMLDecContext * ctx);
#define _ossx_dxml_dlink_plus_seqof	_ossx_dxml_link_seqof
extern void			_ossx_dxml_unbnd_seqof (struct _XMLDecContext * ctx);
#define _ossx_dxml_unbnd_setof	_ossx_dxml_unbnd_seqof
#define _ossx_dxml_array_seqof	_ossx_dxml_unbnd_seqof
#define _ossx_dxml_array_setof	_ossx_dxml_unbnd_seqof
extern void			_ossx_dxml_unbnd_char (struct _XMLDecContext * ctx);
extern void			_ossx_dxml_4byte_char (struct _XMLDecContext * ctx);
#define _ossx_dxml_2byte_char	_ossx_dxml_4byte_char
extern void			_ossx_dxml_pad_char (struct _XMLDecContext * ctx);
extern void			_ossx_dxml_nlltrm_char (struct _XMLDecContext * ctx);
#define	_ossx_dxml_vary_char	_ossx_dxml_nlltrm_char
#define _ossx_dxml_embedded_pdv	_ossx_dxml_seq
#define _ossx_dxml_char_string	_ossx_dxml_seq
extern void			_ossx_dxml_char_real (struct _XMLDecContext * ctx);
extern void			_ossx_dxml_mixed_real (struct _XMLDecContext * ctx);
extern void			_ossx_dxml_huge_int (struct _XMLDecContext * ctx);
extern void			_ossx_dxml_not_supported (struct _XMLDecContext * ctx);
#define _ossx_dxml_defer		_ossx_dxml_not_supported
#define _ossx_dxml_defer_obj	_ossx_dxml_not_supported
extern void    			_ossx_dxml_anyattr_nlltrm_char(struct _XMLDecContext *ctx);
#define _ossx_dxml_normal_int	_ossx_dxml_not_supported
#define _ossx_dxml_normal_enum	_ossx_dxml_not_supported
extern void    			_ossx_dxml_base64_unbnd_char(struct _XMLDecContext * ctx);
extern void    			_ossx_dxml_normal_unbnd_char(struct _XMLDecContext * ctx);
extern void                     _ossx_dxml_base64_unbnd_octet(struct _XMLDecContext * ctx);
extern void                     _ossx_dxml_normal_unbnd_octet(struct _XMLDecContext * ctx);
extern void    			_ossx_dxml_base64_pad_char(struct _XMLDecContext * ctx);
extern void    			_ossx_dxml_normal_pad_char(struct _XMLDecContext * ctx);
extern void    			_ossx_dxml_base64_nlltrm_char(struct _XMLDecContext * ctx);
extern void			_ossx_dxml_anyel_nlltrm_char(struct _XMLDecContext *ctx);
extern void    			_ossx_dxml_normal_nlltrm_char(struct _XMLDecContext * ctx);
extern void    			_ossx_dxml_base64_4byte_char(struct _XMLDecContext * ctx);
extern void    			_ossx_dxml_normal_4byte_char(struct _XMLDecContext * ctx);
#define _ossx_dxml_useorder_seq	_ossx_dxml_set
extern void			_ossx_dxml_qname_seq(struct _XMLDecContext *ctx);
extern void			_ossx_dxml_normal_seq(struct _XMLDecContext *ctx);
#define _ossx_dxml_anyattr_link_sof _ossx_dxml_anyattr_nlltrm_char
extern void			_ossx_dxml_normal_link_sof(struct _XMLDecContext *ctx);
extern void			_ossx_dxml_normal_real(struct _XMLDecContext * ctx);
extern void			_ossx_dxml_modified_real(struct _XMLDecContext * ctx);
extern void			_ossx_dxml_normal_char_real(struct _XMLDecContext * ctx);
extern void			_ossx_dxml_modified_char_real(struct _XMLDecContext * ctx);
extern void			_ossx_dxml_decimal_char_real(struct _XMLDecContext * ctx);
extern ossxBoolean DLL_ENTRY ossxEXValidateAnyUri(unsigned char *string, long length);
#endif /* OSSX_SOED_XML && !LED_SOURCECODE_SHIPPING */
typedef struct {
    OssxEncodedRelOID *_oss_jHJ;
    int              _oss_HwW;
} _fws_roidmsgid;
typedef struct {
    int             _oss_HjW; 
    _fws_roidmsgid *_oss_QjW; 
    int        *_oss_jq; 
} _fws_roids;
typedef struct {
    unsigned char *_oss_j;  
    unsigned char *_oss_W;
} _fws_qname;
typedef struct {
    _xml_decode_position  _oss_JWH;
    _fws_qname           *_oss_jq; 
} _fws_qnames;
typedef struct {
    OSSX_UINT16        _oss_Jq;
    OSSX_UINT16        _oss_Wq;
    _fws_qnames        *_oss_HqJ;
    _fws_roids         *_oss_JHW;
    OssxTransDflt      *_oss_QjJ;
    OssxOperationInfo  *_oss_QHW;
} _fws_table;
PUBLIC void DLL_ENTRY ossxLink_SoapFast(struct ossxEnv *world, void *fws);
PUBLIC void DLL_ENTRY ossxLink_SoapXml(struct ossxEnv *world, void *fws);
PUBLIC void DLL_ENTRY ossxLink_Soap(struct ossxEnv *world, void *fws);
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
#endif /* !OSSXTYPE_H */
