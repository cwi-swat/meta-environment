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

#include <stdio.h>
#include  <aterm1.h>

#include "sg_growbuf.h"
#include  "mem-alloc.h"

sg_growbuf *SG_Create_GrowBuf(size_t initialnmemb, size_t chunknmemb, size_t size)
{
  sg_growbuf *buf = NULL;

  buf = (sg_growbuf *) SG_Calloc(1, sizeof(sg_growbuf));
  if(!buf) {
    ATerror("error allocating growable buffer struct\n");
    return NULL;
  }

  buf->used = buf->size = 0;
  buf->chunk_nmemb = chunknmemb;
  buf->memb_size = size;

  buf->data = SG_Malloc(size, initialnmemb);
  if(!buf->data) {
    ATerror("error allocating growable buffer\n");
    return NULL;
  }
  buf->size = initialnmemb;

  return buf;
}

sg_growbuf *SG_Reset_GrowBuf(sg_growbuf *buf)
{
  buf->used = 0;
  return buf;
}

sg_growbuf *SG_AddToGrowBuf(sg_growbuf *buf, void *data, size_t nmembs)
{
  size_t growth = 0;

  while(buf->used + nmembs > buf->size + growth) {
    growth += buf->chunk_nmemb;
  }
  if(growth) {
    buf->data = SG_Realloc(buf->data, buf->memb_size, buf->size + growth);
    if(!buf->data) {
      ATerror("error adding to growable buffer\n");
      return NULL;
    }
    buf->size += growth;
  }
  memcpy((char *) buf->data + (buf->used * buf->memb_size), data,
         nmembs * buf->memb_size);
  buf->used += nmembs;
  return buf;
}

sg_growbuf *SG_AddStringToGrowBuf(sg_growbuf *buf, char *str)
{
  return SG_AddToGrowBuf(buf, str, strlen(str));
}

void *SG_GetGrowBufContent(sg_growbuf *buf)
{
  return buf->data;
}

size_t SG_GetGrowBufUsed(sg_growbuf *buf)
{
  return buf->used;
}

void SG_WriteGrowBuf(FILE *fd, sg_growbuf *buf)
{
  fwrite(buf->data, buf->memb_size, buf->used, fd);
}
