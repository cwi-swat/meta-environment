/*
 $Id$
 */


#ifndef _BUFFER_H_
#define _BUFFER_H_


#include <ctype.h>

typedef struct _buffer {
  size_t  used;
  size_t  size;
  size_t  chunk_nmemb;
  size_t  memb_size;
  void    *data;
} buffer;


buffer* CreateBuffer(size_t initialnmemb, size_t chunknmemb, size_t size);
buffer* ResetBuffer(buffer *buf);
void    DeleteBuffer(buffer *buf);
buffer* AddToBuffer(buffer *buf, void *data, size_t nmembs);
buffer* AddCharToBuffer(buffer *buf, char c);
buffer* AddStringToBuffer(buffer *buf, char *str);
void*   GetBufferContent(buffer *buf);
size_t  GetBufferUsed(buffer *buf);

#endif _BUFFER_H_
