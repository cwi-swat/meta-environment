/* $Id$ */

#ifndef _MEM_ALLOC
#define _MEM_ALLOC

#ifdef HAVE_BOEHMGC
  #include <gc.h>
  #define SG_Calloc(m,n)  GC_calloc(m,n)
  #define SG_Malloc(n)    GC_malloc(n)
  #define SG_Realloc(o,s) GC_realloc(o,s)
#if 1
  #define SG_free(o)      GC_free(o)
#else
  #define SG_free(o)      ;
#endif
  #define free(n)    ;
#else
  #include <stdlib.h>
  #define SG_Calloc(m,n)  calloc(m,n)
  #define SG_Malloc(n)    malloc(n)
  #define SG_Realloc(o,s) realloc(o,s)
  #define SG_free(o)      free(o)
#endif

#endif
