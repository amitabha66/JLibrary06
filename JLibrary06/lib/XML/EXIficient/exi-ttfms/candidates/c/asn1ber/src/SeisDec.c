/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).  Version: 6.0B, Date: 18-Oct-2006.
 */
#include "Seis.h"
#include "rtxsrc/rtxCommon.h"

/**************************************************************/
/*                                                            */
/*  Headtype                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_Headtype (OSCTXT* pctxt, Headtype *pvalue, 
   ASN1TagType tagging, int length)
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
         /* decode name */
         if (XD_PEEKTAG (pctxt, 0x80)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->name, ASN1IMPL, length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      case 1:
         /* decode area */
         if (XD_PEEKTAG (pctxt, 0x81)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->area, ASN1IMPL, length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      case 2:
         /* decode ntrace */
         if (XD_PEEKTAG (pctxt, 0x82)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_integer (pctxt, &pvalue->ntrace, ASN1IMPL, length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      case 3:
         /* decode nsamp */
         if (XD_PEEKTAG (pctxt, 0x83)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_int16 (pctxt, &pvalue->nsamp, ASN1IMPL, length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      case 4:
         /* decode precision */
         if (XD_PEEKTAG (pctxt, 0x84)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_int8 (pctxt, &pvalue->precision, ASN1IMPL, length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      case 5:
         /* decode zstart */
         if (XD_PEEKTAG (pctxt, 0x85)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_real (pctxt, &pvalue->zstart, ASN1IMPL, length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      case 6:
         /* decode zinc */
         if (XD_PEEKTAG (pctxt, 0x86)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_real (pctxt, &pvalue->zinc, ASN1IMPL, length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      case 7:
         /* decode num_xyzs_fields */
         if (XD_PEEKTAG (pctxt, 0x87)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_int8 (pctxt, &pvalue->num_xyzs_fields, ASN1IMPL, length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      case 8:
         /* decode xyzs_field_names */
         if (XD_PEEKTAG (pctxt, 0x88)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->xyzs_field_names, ASN1IMPL, length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            reqcnt++;
         }
         break;

      case 9:
         /* decode xyzs_field_precisions */
         if (XD_PEEKTAG (pctxt, 0x89)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = xd_utf8str (pctxt, &pvalue->xyzs_field_precisions, ASN1IMPL, length);
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
         case (TM_CTXT|TM_PRIM|3):
         case (TM_CTXT|TM_PRIM|4):
         case (TM_CTXT|TM_PRIM|5):
         case (TM_CTXT|TM_PRIM|6):
         case (TM_CTXT|TM_PRIM|7):
         case (TM_CTXT|TM_PRIM|8):
         case (TM_CTXT|TM_CONS|8):
         case (TM_CTXT|TM_PRIM|9):
         case (TM_CTXT|TM_CONS|9):
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

   if (reqcnt < 10) {
      return LOG_RTERR (pctxt, RTERR_SETMISRQ);
   }
   if (tagging == ASN1EXPL && ccb.len == ASN_K_INDEFLEN) {
      if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
      else return LOG_RTERR (pctxt, ASN_E_INVLEN);
   }
   return (stat);
}

int XmlDec_Headtype (OSCTXT* pctxt, Headtype* pvalue)
{
   int stat = 0;

   { int elemID;

   static const OSXMLElemIDRec elemtab[] = {
      {{{OSUTF8("name"), 4}, 0}, 0 },
      {{{OSUTF8("area"), 4}, 0}, 1 },
      {{{OSUTF8("ntrace"), 6}, 0}, 2 },
      {{{OSUTF8("nsamp"), 5}, 0}, 3 },
      {{{OSUTF8("precision"), 9}, 0}, 4 },
      {{{OSUTF8("zstart"), 6}, 0}, 5 },
      {{{OSUTF8("zinc"), 4}, 0}, 6 },
      {{{OSUTF8("num_xyzs_fields"), 15}, 0}, 7 },
      {{{OSUTF8("xyzs_field_names"), 16}, 0}, 8 },
      {{{OSUTF8("xyzs_field_precisions"), 21}, 0}, 9 }
   } ;
   static const struct {
      int row;
      int num;
      int anyCase;
   } groupDesc[] = { {0, 1, -1}, {1, 1, -1}, {2, 1, -1}, {3, 1, -1}, {4, 1, -1}
      , {5, 1, -1}, {6, 1, -1}, {7, 1, -1}, {8, 1, -1}, {9, 1, -1}, {10, 0, -1}
      };

   int group = 0;
   int i;
   for (i = 0; i < 10; i++) {
      int fromrow = groupDesc[group].row;
      int rows = groupDesc[group].num;
      int anyCase = groupDesc[group].anyCase;

      elemID = rtXmlpGetNextElemID (pctxt, 
         elemtab + fromrow, rows, -1, FALSE);
      if (elemID == RTERR_UNEXPELEM && anyCase >= 0 && i == anyCase)
         elemID = anyCase;
      else if (elemID < 0) return LOG_RTERR (pctxt, elemID);
      else if (elemID == XML_OK_EOB) break;
      else if (elemID == elemtab[fromrow + rows - 1].id) group++;

      switch (elemID) {
      case 0: { /* name */
         stat = rtXmlpDecDynUTF8Str (pctxt, &pvalue->name);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      case 1: { /* area */
         stat = rtXmlpDecDynUTF8Str (pctxt, &pvalue->area);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      case 2: { /* ntrace */
         stat = rtXmlpDecInt (pctxt, &pvalue->ntrace);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      case 3: { /* nsamp */
         stat = rtXmlpDecInt16 (pctxt, &pvalue->nsamp);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      case 4: { /* precision */
         stat = rtXmlpDecInt8 (pctxt, &pvalue->precision);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      case 5: { /* zstart */
         stat = rtXmlpDecDouble (pctxt, &pvalue->zstart, -1, -1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      case 6: { /* zinc */
         stat = rtXmlpDecDouble (pctxt, &pvalue->zinc, -1, -1);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      case 7: { /* num_xyzs_fields */
         stat = rtXmlpDecInt8 (pctxt, &pvalue->num_xyzs_fields);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      case 8: { /* xyzs_field_names */
         stat = rtXmlpDecDynUTF8Str (pctxt, &pvalue->xyzs_field_names);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      case 9: { /* xyzs_field_precisions */
         stat = rtXmlpDecDynUTF8Str (pctxt, &pvalue->xyzs_field_precisions);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      }
      i = elemID;
   }
   }

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Xcrdtype                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_Xcrdtype (OSCTXT* pctxt, Xcrdtype *pvalue, 
   ASN1TagType tagging, int length)
{
   int stat = 0;
   int count;
   int xx1;
   ASN1CCB ccb;

   if (tagging == ASN1EXPL) {
      stat = xd_match1 (pctxt, 0x10, &length);
      if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   /* decode SEQUENCE OF or SET OF */

   stat = xd_count (pctxt, length, &count);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   pvalue->n = count;
   ALLOC_ASN1ARRAY (pctxt, pvalue, OSREAL);

   xx1 = 0;
   ccb.len = length;
   ccb.ptr = OSRTBUFPTR(pctxt);

   while (!XD_CHKEND (pctxt, &ccb))
   {
      stat = xd_real (pctxt, &pvalue->elem[xx1], ASN1EXPL, length);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      xx1++;
   }
   pvalue->n = xx1;

   if (tagging == ASN1EXPL && ccb.len == ASN_K_INDEFLEN) {
      if (XD_MATCHEOC (pctxt)) XD_BUMPIDX (pctxt, 2);
      else return LOG_RTERR (pctxt, ASN_E_INVLEN);
   }
   return (stat);
}

int XmlDec_Xcrdtype (OSCTXT* pctxt, Xcrdtype* pvalue)
{
   int stat = 0;

   { OSRTDListBuf tmpbuf;
   rtxDListBufInit (&tmpbuf, DLISTBUF_SEG, (void**)&(pvalue->
      elem), sizeof(OSREAL));
   rtXmlpCountListItems (pctxt, &tmpbuf.firstSegSz);

   pvalue->elem = 0;
   rtXmlpSetListMode (pctxt);

   while (rtXmlpListHasItem(pctxt)) {
      if (tmpbuf.n >= tmpbuf.nMax) {
         stat = rtxDListBufExpand (pctxt, &tmpbuf);
         if (stat != 0) break;
      }

      stat = rtXmlpDecDouble (pctxt, &pvalue->elem[tmpbuf.n], -1, -1);
      if (stat != 0) return LOG_RTERR (pctxt, stat);

      tmpbuf.n++;
      tmpbuf.nAll++;
   }

   if (stat == 0)
      stat = rtxDListBufToArray (pctxt, &tmpbuf);

   pvalue->n = tmpbuf.nAll;

   if (stat != 0) return LOG_RTERR (pctxt, stat);
   }

   return (stat);
}

/**************************************************************/
/*                                                            */
/*  Seisdata                                                  */
/*                                                            */
/**************************************************************/

EXTERN int asn1D_Seisdata (OSCTXT* pctxt, Seisdata *pvalue, 
   ASN1TagType tagging, int length)
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
         /* decode head */
         if (XD_PEEKTAG (pctxt, 0x80)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_Headtype (pctxt, 
               &pvalue->head, ASN1IMPL, length);
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
         /* decode xcrd */
         if (XD_PEEKTAG (pctxt, 0x81)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_Xcrdtype (pctxt, 
               &pvalue->xcrd, ASN1IMPL, length);
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

      case 2:
         /* decode ycrd */
         if (XD_PEEKTAG (pctxt, 0x82)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_Xcrdtype (pctxt, 
               &pvalue->ycrd, ASN1IMPL, length);
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

      case 3:
         /* decode zval */
         if (XD_PEEKTAG (pctxt, 0x83)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_Xcrdtype (pctxt, 
               &pvalue->zval, ASN1IMPL, length);
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
         /* decode cdp */
         if (XD_PEEKTAG (pctxt, 0x84)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_Xcrdtype (pctxt, 
               &pvalue->cdp, ASN1IMPL, length);
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

      case 5:
         /* decode data */
         if (XD_PEEKTAG (pctxt, 0x85)) {
            stat = xd_Tag1AndLen (pctxt, &length);
            if (stat != 0) return LOG_RTERR (pctxt, stat);

            stat = asn1D_Xcrdtype (pctxt, 
               &pvalue->data, ASN1IMPL, length);
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

int XmlDec_Seisdata (OSCTXT* pctxt, Seisdata* pvalue)
{
   int stat = 0;

   { int elemID;

   static const OSXMLElemIDRec elemtab[] = {
      {{{OSUTF8("head"), 4}, 0}, 0 },
      {{{OSUTF8("xcrd"), 4}, 0}, 1 },
      {{{OSUTF8("ycrd"), 4}, 0}, 2 },
      {{{OSUTF8("zval"), 4}, 0}, 3 },
      {{{OSUTF8("cdp"), 3}, 0}, 4 },
      {{{OSUTF8("data"), 4}, 0}, 5 }
   } ;
   static const struct {
      int row;
      int num;
      int anyCase;
   } groupDesc[] = { {0, 1, -1}, {1, 1, -1}, {2, 1, -1}, {3, 1, -1}, {4, 1, -1}
      , {5, 1, -1}, {6, 0, -1}};

   int group = 0;
   int i;
   for (i = 0; i < 6; i++) {
      int fromrow = groupDesc[group].row;
      int rows = groupDesc[group].num;
      int anyCase = groupDesc[group].anyCase;

      elemID = rtXmlpGetNextElemID (pctxt, 
         elemtab + fromrow, rows, -1, FALSE);
      if (elemID == RTERR_UNEXPELEM && anyCase >= 0 && i == anyCase)
         elemID = anyCase;
      else if (elemID < 0) return LOG_RTERR (pctxt, elemID);
      else if (elemID == XML_OK_EOB) break;
      else if (elemID == elemtab[fromrow + rows - 1].id) group++;

      switch (elemID) {
      case 0: { /* head */
         stat = XmlDec_Headtype (pctxt, &pvalue->head);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      case 1: { /* xcrd */
         stat = XmlDec_Xcrdtype (pctxt, &pvalue->xcrd);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      case 2: { /* ycrd */
         stat = XmlDec_Xcrdtype (pctxt, &pvalue->ycrd);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      case 3: { /* zval */
         stat = XmlDec_Xcrdtype (pctxt, &pvalue->zval);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      case 4: { /* cdp */
         stat = XmlDec_Xcrdtype (pctxt, &pvalue->cdp);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      case 5: { /* data */
         stat = XmlDec_Xcrdtype (pctxt, &pvalue->data);
         if (stat != 0) return LOG_RTERR (pctxt, stat);

         stat = rtXmlpMatchEndTag (pctxt, -1);
         if (stat < 0) return LOG_RTERR (pctxt, stat);

         break;
      }
      }
      i = elemID;
   }
   }

   return (stat);
}

int XmlDec_Seisdata_PDU (OSCTXT* pctxt, Seisdata* pvalue)
{
   int stat;

   rtXmlpCreateReader (pctxt);

   asn1Init_Seisdata (pvalue);

   stat = rtXmlpMatchStartTag (pctxt, OSUTF8("seisdata"), 0);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   stat = XmlDec_Seisdata (pctxt, pvalue);
   if (stat != 0) return LOG_RTERR (pctxt, stat);

   stat = rtXmlpMatchEndTag (pctxt, -1);
   if (stat < 0) return LOG_RTERR (pctxt, stat);

   return stat;
}
