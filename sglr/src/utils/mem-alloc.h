/* $Id$ */

/** \file
 * \ingroup utils
 */

#ifndef _MEM_ALLOC_H_
#define _MEM_ALLOC_H_

#include <stdlib.h>
#define SG_calloc(m,n)    calloc(m,n)
#define SG_malloc(m,n)    malloc((m)*(n))
#define SG_realloc(o,m,n) realloc(o,(m)*(n))
#define free(o)        free(o)

#endif  /* _MEM_ALLOC_H_ */
