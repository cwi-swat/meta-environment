#ifndef SGLR_TERMSTORE_H
#define SGLR_TERMSTORE_H

#include <aterm1.h>

/*
 * \file This file contains a small API for a data-structure for
 * temporarily holding references to ATerms. It works in a stack-like
 * fashion, such that recursive procedures may reuse the memory without
 * interference. Note that this API is optimized for speed, and therefore
 * uses macros and not function calls. This is essential.
 */


extern size_t sglr_term_store_begin; 
extern size_t sglr_term_store_end;   
extern size_t sglr_term_store_size;
extern ATerm* sglr_term_store;


/* Usage: SGLR_TERM_STORE_CHECK(i); SGLR_TERM_STORE[i] = myterm; */
#define SGLR_TERM_STORE (sglr_term_store+sglr_term_store_begin)
#define SGLR_TERM_STORE_CHECK(i) assert(sglr_term_store_begin + (i) <= sglr_term_store_end)

#define SGLR_TERM_STORE_FRAME(i,code) \
  { size_t old_index = SGLR_TS_push(i); \
    code \
    SGLR_TS_pop(old_index); \
  }

void SGLR_TS_create(void);
size_t SGLR_TS_push(size_t size);
void SGLR_TS_pop(size_t size);
void SGLR_TS_destroy(void);

#endif
