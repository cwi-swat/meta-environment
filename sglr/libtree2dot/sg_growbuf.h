/*

    SGLR - the Scannerless Generalized LR parser.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
/*
 $Id$
 */


#include <ctype.h>

typedef struct _growbuf {
  size_t  used;
  size_t  size;
  size_t  chunk_nmemb;
  size_t  memb_size;
  void    *data;
} sg_growbuf;


sg_growbuf *SG_Create_GrowBuf(size_t initialnmemb, size_t chunknmemb, size_t size);
sg_growbuf *SG_Reset_GrowBuf(sg_growbuf *buf);
sg_growbuf *SG_AddToGrowBuf(sg_growbuf *buf, void *data, size_t nmembs);
sg_growbuf *SG_AddStringToGrowBuf(sg_growbuf *buf, char *str);
void *SG_GetGrowBufContent(sg_growbuf *buf);
size_t SG_GetGrowBufUsed(sg_growbuf *buf);
void SG_WriteGrowBuf(FILE *fd, sg_growbuf *buf);
