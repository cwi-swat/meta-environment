#ifndef ASC_TERMSTORE_H
#define ASC_TERMSTORE_H

#include <aterm1.h>

/*
 * \file This file contains a small API for a data-structure for
 * temporarily holding references to ATerms. It works in a stack-like
 * fashion, such that recursive procedures may reuse the memory without
 * interference. Note that this API is optimized for speed, and therefore
 * uses macros and not function calls. This is essential.
 */


extern size_t term_store_begin; 
extern size_t term_store_end;   
extern size_t term_store_size;
extern ATerm* term_store;


/* Usage: TERM_STORE_CHECK(i); TERM_STORE[i] = myterm; */
#define TERM_STORE (term_store+term_store_begin)
#define TERM_STORE_CHECK(i) assert(term_store_begin + (i) <= term_store_end)

#define TERM_STORE_FRAME(i,code) \
  { size_t old_index = TS_push(i); \
    code \
    TS_pop(old_index); \
  }

void TS_create(void);
size_t TS_push(size_t size);
void TS_pop(size_t size);
void TS_destroy(void);

#endif
