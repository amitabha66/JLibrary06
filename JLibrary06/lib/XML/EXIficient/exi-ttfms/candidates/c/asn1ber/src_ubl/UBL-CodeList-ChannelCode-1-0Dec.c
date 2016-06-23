/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#include "asn1intl.h"
#include "UBL-CodeList-ChannelCode-1-0.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  ChannelCodeContentType                                    */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_ChannelCodeContentType (OSCTXT* pctxt,
   ChannelCodeContentType *pvalue, ASN1TagType tagging, int length)
{
   int stat = 0;

   stat = xd_enum (pctxt, (OSINT32*)pvalue, tagging, length);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   if(*pvalue < 0 || *pvalue > 39)
      return LOG_RTERR (pctxt, RTERR_INVENUM);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ChannelCodeType                                           */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_ChannelCodeType (OSCTXT* pctxt,
   ChannelCodeType *pvalue, ASN1TagType tagging, int length)
{
   int stat = 0;
   int reqcnt = 0;
   ASN1CCB ccb;

   if (tagging == ASN1EXPL) {
      stat = xd_match1 (pctxt, 0x10, &length);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   /* decode SEQUENCE */

   memset (&pvalue->m, 0, sizeof(pvalue->m));

   ccb.len = length;
   ccb.ptr = OSRTBUFPTR(pctxt);
   ccb.seqx = 0;

   while (!XD_CHKEND (pctxt, &ccb)) {
      switch (ccb.seqx) {
      case 0:
         /* decode codeListAgencyID */
         if (XD_PEEKTAG (pctxt, 0x80)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->codeListAgencyID, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.codeListAgencyIDPresent = TRUE;
            }
         }
         break;

      case 1:
         /* decode codeListAgencyName */
         if (XD_PEEKTAG (pctxt, 0x81)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->codeListAgencyName, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.codeListAgencyNamePresent = TRUE;
            }
         }
         break;

      case 2:
         /* decode codeListID */
         if (XD_PEEKTAG (pctxt, 0x82)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->codeListID, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.codeListIDPresent = TRUE;
            }
         }
         break;

      case 3:
         /* decode codeListName */
         if (XD_PEEKTAG (pctxt, 0x83)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->codeListName, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.codeListNamePresent = TRUE;
            }
         }
         break;

      case 4:
         /* decode codeListSchemeURI */
         if (XD_PEEKTAG (pctxt, 0x84)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->codeListSchemeURI, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.codeListSchemeURIPresent = TRUE;
            }
         }
         break;

      case 5:
         /* decode codeListURI */
         if (XD_PEEKTAG (pctxt, 0x85)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->codeListURI, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.codeListURIPresent = TRUE;
            }
         }
         break;

      case 6:
         /* decode codeListVersionID */
         if (XD_PEEKTAG (pctxt, 0x86)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->codeListVersionID, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.codeListVersionIDPresent = TRUE;
            }
         }
         break;

      case 7:
         /* decode languageID */
         if (XD_PEEKTAG (pctxt, 0x87)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->languageID, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.languageIDPresent = TRUE;
            }
         }
         break;

      case 8:
         /* decode name */
         if (XD_PEEKTAG (pctxt, 0x88)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->name, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.namePresent = TRUE;
            }
         }
         break;

      case 9:
         /* decode base */
         if (XD_PEEKTAG (pctxt, 0x89)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_ChannelCodeContentType (pctxt, 
               &pvalue->base, ASN1IMPL, length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      default:
         { ASN1TAG tag;
         int len;
         stat = xd_tag_len (pctxt, &tag, &len, 0);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         switch (tag) {
         case (TM_CTXT|TM_PRIM|0):
         case (TM_CTXT|TM_CONS|0):
         case (TM_CTXT|TM_PRIM|1):
         case (TM_CTXT|TM_CONS|1):
         case (TM_CTXT|TM_PRIM|2):
         case (TM_CTXT|TM_CONS|2):
         case (TM_CTXT|TM_PRIM|3):
         case (TM_CTXT|TM_CONS|3):
         case (TM_CTXT|TM_PRIM|4):
         case (TM_CTXT|TM_CONS|4):
         case (TM_CTXT|TM_PRIM|5):
         case (TM_CTXT|TM_CONS|5):
         case (TM_CTXT|TM_PRIM|6):
         case (TM_CTXT|TM_CONS|6):
         case (TM_CTXT|TM_PRIM|7):
         case (TM_CTXT|TM_CONS|7):
         case (TM_CTXT|TM_PRIM|8):
         case (TM_CTXT|TM_CONS|8):
         case (TM_CTXT|TM_PRIM|9):
            stat = RTERR_SEQORDER;
            break;
         default:
            stat = RTERR_SEQOVFLW;
            break;
         }}
      }

      if (stat != 0) return LOG_RTERR (pctxt, stat);
      else ccb.seqx++;
   }

   if (reqcnt < 1) {
      return LOG_RTERR (pctxt, RTERR_SETMISRQ);
   }
   if (tagging == ASN1EXPL && ccb.len == ASN_K_INDEFLEN) {
      if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
      else return LOG_RTERR (pctxt, ASN_E_INVLEN);
   }
   return (stat);
}
