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
/* $Id$ */

#ifndef _MEM_ALLOC_H_
#define _MEM_ALLOC_H_ 1

#ifdef HAVE_BOEHMGC
#include <gc.h>
#define SG_Calloc(m,n)    GC_malloc((m)*(n))
#define SG_Malloc(m,n)    GC_malloc((m)*(n))
#define SG_Realloc(o,m,n) GC_realloc(o,(m)*(n))
#define SG_Free(o)        GC_free(o)
#define free(n)           ;
#else
#include <stdlib.h>
#define SG_Calloc(m,n)    calloc(m,n)
#define SG_Malloc(m,n)    malloc((m)*(n))
#define SG_Realloc(o,m,n) realloc(o,(m)*(n))
#define SG_Free(o)        free(o)
#endif

#endif  /* _MEM_ALLOC_H_ */
