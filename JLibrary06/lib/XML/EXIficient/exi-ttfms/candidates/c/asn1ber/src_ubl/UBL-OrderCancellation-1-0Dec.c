/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0A, Date: 26-May-2006.
 */
#include "asn1intl.h"
#include "UBL-OrderCancellation-1-0.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  IssueDateTimeType                                         */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_IssueDateTimeType (OSCTXT* pctxt,
   IssueDateTimeType *pvalue, ASN1TagType tagging, int length)
{
   int stat = 0;
   int reqcnt = 0;
   ASN1CCB ccb;

   if (tagging == ASN1EXPL) {
      stat = xd_match1 (pctxt, 0x10, &length);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   /* decode SEQUENCE */

   ccb.len = length;
   ccb.ptr = OSRTBUFPTR(pctxt);
   ccb.seqx = 0;

   while (!XD_CHKEND (pctxt, &ccb)) {
      switch (ccb.seqx) {
      case 0:
         /* decode base */
         if (XD_PEEKTAG (pctxt, 0x80)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->base, ASN1IMPL, length);
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

/**************************************************************/
/*                                                            */
/*  IssueDateTime                                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_IssueDateTime (OSCTXT* pctxt,
   IssueDateTime *pvalue, ASN1TagType tagging, int length)
{
   int stat = 0;

   stat = asn1D_IssueDateTimeType (pctxt, 
      pvalue, tagging, length);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  CancellationNoteType                                      */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_CancellationNoteType (OSCTXT* pctxt,
   CancellationNoteType *pvalue, ASN1TagType tagging, int length)
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
         /* decode languageLocaleID */
         if (XD_PEEKTAG (pctxt, 0x80)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->languageLocaleID, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.languageLocaleIDPresent = TRUE;
            }
         }
         break;

      case 1:
         /* decode languageID */
         if (XD_PEEKTAG (pctxt, 0x81)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->languageID, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.languageIDPresent = TRUE;
            }
         }
         break;

      case 2:
         /* decode base */
         if (XD_PEEKTAG (pctxt, 0x82)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->base, ASN1IMPL, length);
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

/**************************************************************/
/*                                                            */
/*  CancellationNote                                          */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_CancellationNote (OSCTXT* pctxt,
   CancellationNote *pvalue, ASN1TagType tagging, int length)
{
   int stat = 0;

   stat = asn1D_CancellationNoteType (pctxt, 
      pvalue, tagging, length);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  ResponseRequiredIndicatorType                             */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_ResponseRequiredIndicatorType (OSCTXT* pctxt,
   ResponseRequiredIndicatorType *pvalue, ASN1TagType tagging, int length)
{
   int stat = 0;
   int reqcnt = 0;
   ASN1CCB ccb;

   if (tagging == ASN1EXPL) {
      stat = xd_match1 (pctxt, 0x10, &length);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   /* decode SEQUENCE */

   ccb.len = length;
   ccb.ptr = OSRTBUFPTR(pctxt);
   ccb.seqx = 0;

   while (!XD_CHKEND (pctxt, &ccb)) {
      switch (ccb.seqx) {
      case 0:
         /* decode base */
         if (XD_PEEKTAG (pctxt, 0x80)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_boolean (pctxt, &pvalue->base, ASN1IMPL, length);
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

/**************************************************************/
/*                                                            */
/*  ResponseRequiredIndicator                                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_ResponseRequiredIndicator (OSCTXT* pctxt,
   ResponseRequiredIndicator *pvalue, ASN1TagType tagging, int length)
{
   int stat = 0;

   stat = asn1D_ResponseRequiredIndicatorType (pctxt, 
      pvalue, tagging, length);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  AcceptedIndicatorType                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_AcceptedIndicatorType (OSCTXT* pctxt,
   AcceptedIndicatorType *pvalue, ASN1TagType tagging, int length)
{
   int stat = 0;
   int reqcnt = 0;
   ASN1CCB ccb;

   if (tagging == ASN1EXPL) {
      stat = xd_match1 (pctxt, 0x10, &length);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   /* decode SEQUENCE */

   ccb.len = length;
   ccb.ptr = OSRTBUFPTR(pctxt);
   ccb.seqx = 0;

   while (!XD_CHKEND (pctxt, &ccb)) {
      switch (ccb.seqx) {
      case 0:
         /* decode base */
         if (XD_PEEKTAG (pctxt, 0x80)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_boolean (pctxt, &pvalue->base, ASN1IMPL, length);
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

/**************************************************************/
/*                                                            */
/*  AcceptedIndicator                                         */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_AcceptedIndicator (OSCTXT* pctxt,
   AcceptedIndicator *pvalue, ASN1TagType tagging, int length)
{
   int stat = 0;

   stat = asn1D_AcceptedIndicatorType (pctxt, 
      pvalue, tagging, length);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  OrderCancellationType_orderReference_list                 */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_OrderCancellationType_orderReference_list (OSCTXT* pctxt,
   OrderCancellationType_orderReference_list *pvalue, ASN1TagType tagging, int length)
{
   int stat = 0;
   OrderReference* pdata;
   OSRTDListNode* pnode;
   ASN1CCB ccb;

   if (tagging == ASN1EXPL) {
      stat = xd_match1 (pctxt, 0x10, &length);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   /* decode SEQUENCE OF or SET OF */

   rtxDListInit (pvalue);

   ccb.len = length;
   ccb.ptr = OSRTBUFPTR(pctxt);

   while (!XD_CHKEND (pctxt, &ccb))
   {
      rtxDListAllocNodeAndData (pctxt, OrderReference, &pnode, &pdata);

      if (pnode == NULL)
         return LOG_RTERR (pctxt, RTERR_NOMEM);

      asn1Init_OrderReference (pdata);

      stat = asn1D_OrderReference (pctxt, 
         pdata, ASN1EXPL, length);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      rtxDListAppendNode (pvalue, pnode);
   }

   if (tagging == ASN1EXPL && ccb.len == ASN_K_INDEFLEN) {
      if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
      else return LOG_RTERR (pctxt, ASN_E_INVLEN);
   }
   return (stat);
}

/**************************************************************/
/*                                                            */
/*  OrderCancellationType                                     */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_OrderCancellationType (OSCTXT* pctxt,
   OrderCancellationType *pvalue, ASN1TagType tagging, int length)
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
         /* decode iD */
         if (XD_PEEKTAG (pctxt, 0x80)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_UBL_UnspecializedDatatypes_1_0_IdentifierType (pctxt, 
               &pvalue->iD, ASN1IMPL, length);
            if (stat == 0) {
               if (length == ASN_K_INDEFLEN) {
                  if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
                  else return LOG_RTERR (pctxt, ASN_E_INVLEN);
               }
            }
            else return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      case 1:
         /* decode copyIndicator */
         if (XD_PEEKTAG (pctxt, 0x81)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_CopyIndicator (pctxt, 
               &pvalue->copyIndicator, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.copyIndicatorPresent = TRUE;
               if (length == ASN_K_INDEFLEN) {
                  if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
                  else return LOG_RTERR (pctxt, ASN_E_INVLEN);
               }
            }
         }
         break;

      case 2:
         /* decode gUID */
         if (XD_PEEKTAG (pctxt, 0x82)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_UBL_UnspecializedDatatypes_1_0_IdentifierType (pctxt, 
               &pvalue->gUID, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.gUIDPresent = TRUE;
               if (length == ASN_K_INDEFLEN) {
                  if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
                  else return LOG_RTERR (pctxt, ASN_E_INVLEN);
               }
            }
         }
         break;

      case 3:
         /* decode issueDateTime */
         if (XD_PEEKTAG (pctxt, 0x83)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_IssueDateTime (pctxt, 
               &pvalue->issueDateTime, ASN1IMPL, length);
            if (stat == 0) {
               if (length == ASN_K_INDEFLEN) {
                  if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
                  else return LOG_RTERR (pctxt, ASN_E_INVLEN);
               }
            }
            else return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      case 4:
         /* decode documentStatusCode */
         if (XD_PEEKTAG (pctxt, 0x84)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_DocumentStatusCodeType (pctxt, 
               &pvalue->documentStatusCode, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.documentStatusCodePresent = TRUE;
               if (length == ASN_K_INDEFLEN) {
                  if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
                  else return LOG_RTERR (pctxt, ASN_E_INVLEN);
               }
            }
         }
         break;

      case 5:
         /* decode note */
         if (XD_PEEKTAG (pctxt, 0x85)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_Note (pctxt, 
               &pvalue->note, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.notePresent = TRUE;
               if (length == ASN_K_INDEFLEN) {
                  if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
                  else return LOG_RTERR (pctxt, ASN_E_INVLEN);
               }
            }
         }
         break;

      case 6:
         /* decode cancellationNote */
         if (XD_PEEKTAG (pctxt, 0x86)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_CancellationNote (pctxt, 
               &pvalue->cancellationNote, ASN1IMPL, length);
            if (stat == 0) {
               if (length == ASN_K_INDEFLEN) {
                  if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
                  else return LOG_RTERR (pctxt, ASN_E_INVLEN);
               }
            }
            else return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      case 7:
         /* decode responseRequiredIndicator */
         if (XD_PEEKTAG (pctxt, 0x87)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_ResponseRequiredIndicator (pctxt, 
               &pvalue->responseRequiredIndicator, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.responseRequiredIndicatorPresent = TRUE;
               if (length == ASN_K_INDEFLEN) {
                  if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
                  else return LOG_RTERR (pctxt, ASN_E_INVLEN);
               }
            }
         }
         break;

      case 8:
         /* decode acceptedIndicator */
         if (XD_PEEKTAG (pctxt, 0x88)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_AcceptedIndicator (pctxt, 
               &pvalue->acceptedIndicator, ASN1IMPL, length);
            if (stat == 0) {
               pvalue->m.acceptedIndicatorPresent = TRUE;
               if (length == ASN_K_INDEFLEN) {
                  if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
                  else return LOG_RTERR (pctxt, ASN_E_INVLEN);
               }
            }
         }
         break;

      case 9:
         /* decode orderReference_list */
         if (XD_PEEKTAG (pctxt, 0x89)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_OrderCancellationType_orderReference_list (pctxt, 
               &pvalue->orderReference_list, ASN1IMPL, length);
            if (stat == 0) {
               if (length == ASN_K_INDEFLEN) {
                  if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
                  else return LOG_RTERR (pctxt, ASN_E_INVLEN);
               }
            }
            else return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      case 10:
         /* decode buyerParty */
         if (XD_PEEKTAG (pctxt, 0x8a)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_BuyerParty (pctxt, 
               &pvalue->buyerParty, ASN1IMPL, length);
            if (stat == 0) {
               if (length == ASN_K_INDEFLEN) {
                  if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
                  else return LOG_RTERR (pctxt, ASN_E_INVLEN);
               }
            }
            else return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      case 11:
         /* decode sellerParty */
         if (XD_PEEKTAG (pctxt, 0x8b)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_SellerParty (pctxt, 
               &pvalue->sellerParty, ASN1IMPL, length);
            if (stat == 0) {
               if (length == ASN_K_INDEFLEN) {
                  if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
                  else return LOG_RTERR (pctxt, ASN_E_INVLEN);
               }
            }
            else return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      default:
         { ASN1TAG tag;
         int len;
         stat = xd_tag_len (pctxt, &tag, &len, 0);
         if (stat != 0) return LOG_RTERR (pctxt, stat);
         switch (tag) {
         case (TM_CTXT|TM_CONS|0):
         case (TM_CTXT|TM_CONS|1):
         case (TM_CTXT|TM_CONS|2):
         case (TM_CTXT|TM_CONS|3):
         case (TM_CTXT|TM_CONS|4):
         case (TM_CTXT|TM_CONS|5):
         case (TM_CTXT|TM_CONS|6):
         case (TM_CTXT|TM_CONS|7):
         case (TM_CTXT|TM_CONS|8):
         case (TM_CTXT|TM_CONS|9):
         case (TM_CTXT|TM_CONS|10):
         case (TM_CTXT|TM_CONS|11):
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

   if (reqcnt < 6) {
      return LOG_RTERR (pctxt, RTERR_SETMISRQ);
   }
   if (tagging == ASN1EXPL && ccb.len == ASN_K_INDEFLEN) {
      if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
      else return LOG_RTERR (pctxt, ASN_E_INVLEN);
   }
   return (stat);
}

/**************************************************************/
/*                                                            */
/*  OrderCancellation                                         */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_OrderCancellation (OSCTXT* pctxt,
   OrderCancellation *pvalue, ASN1TagType tagging, int length)
{
   int stat = 0;

   stat = asn1D_OrderCancellationType (pctxt, 
      pvalue, tagging, length);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   return (stat);
}

