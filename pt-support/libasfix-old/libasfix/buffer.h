/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
    The Netherlands. 

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
