/*
 $Id$
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <aterm1.h>
#include "buffer.h"

buffer *CreateBuffer(size_t initialnmemb, size_t chunknmemb, size_t size)
{
  buffer *buf = NULL;

  buf = (buffer *) calloc(1, sizeof(buffer));
  if(!buf) {
    ATerror("error allocating growable buffer struct\n");
    return NULL;
  }

  buf->used = buf->size = 0;
  buf->chunk_nmemb = chunknmemb;
  buf->memb_size = size;

  buf->data = malloc(size * initialnmemb);
  if(!buf->data) {
    ATerror("error allocating growable buffer\n");
    return NULL;
  }
  buf->size = initialnmemb;

  return buf;
}

buffer *ResetBuffer(buffer *buf)
{
  buf->used = 0;
  return buf;
}

void DeleteBuffer(buffer *buf)
{
  if(buf) {
    if(buf->data) {
      free(buf->data);
    }
    free(buf);
  }
}

buffer *AddToBuffer(buffer *buf, void *data, size_t nmembs)
{
  size_t growth = 0;

  while(buf->used + nmembs > buf->size + growth) {
    growth += buf->chunk_nmemb;
  }
  if(growth) {
    buf->data = realloc(buf->data, buf->memb_size * (buf->size + growth));
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

buffer *AddCharToBuffer(buffer *buf, char c)
{
  char s[1];

  s[0] = c;
  return AddToBuffer(buf, s, 1);
}

buffer *AddStringToBuffer(buffer *buf, char *str)
{
  return AddToBuffer(buf, str, strlen(str));
}


void *GetBufferContent(buffer *buf)
{
  return buf->data;
}

size_t GetBufferUsed(buffer *buf)
{
  return buf->used;
}


