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
