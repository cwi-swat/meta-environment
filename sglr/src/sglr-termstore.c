#include <sglr-termstore.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define TERM_STORE_INITIAL_SIZE    (8*1024)

size_t sglr_term_store_begin; 
size_t sglr_term_store_end;   
size_t sglr_term_store_size;
ATerm* sglr_term_store = NULL;


/* This sglr_term_store is built to cope with a recursive function. Each
 * of its calls needs its own sglr_term_store, but we want to reuse allocated
 * memory. It works somewhat like a stack using getTermStore as a push and
 * resetTermStore as a pop. Term_store_end holds the top of the stack.
 */
void SGLR_TS_create(void)
{
  sglr_term_store_size = TERM_STORE_INITIAL_SIZE;
  sglr_term_store_begin = -1;
  sglr_term_store_end = -1;

  sglr_term_store = (ATerm*) calloc(sglr_term_store_size, sizeof(ATerm));

  if (sglr_term_store == NULL) {
    ATerror("SGLR_TS_: unable to allocate memory for %d Trees",
	    sglr_term_store_size);
  }

  /*ATwarning("created term store of size: %d\n", sglr_term_store_size);*/
  ATprotectArray(sglr_term_store, sglr_term_store_size);
}

void SGLR_TS_destroy(void)
{
  ATunprotectArray(sglr_term_store);

  free(sglr_term_store);
  sglr_term_store_size = 0;
  sglr_term_store = NULL;
}

size_t SGLR_TS_push(size_t size)
{
  size_t old_begin;

  assert(size > 0);

  /*ATwarning("pushing %d\n", size);*/

  if (sglr_term_store_size <= size + sglr_term_store_end) {
    size_t old_size = sglr_term_store_size;
    ATunprotectArray((ATerm*) sglr_term_store);

    /* Allocate at least enough memory for the request, and then
     * some more to prevent this from happening too often.
     */
    sglr_term_store_size = size + sglr_term_store_end + 1 + TERM_STORE_INITIAL_SIZE;
    sglr_term_store = (ATerm *) realloc(sglr_term_store,
				     sglr_term_store_size * sizeof(ATerm));

    if (sglr_term_store == NULL) {
      ATerror("resizeTermStore: unable to allocate memory for %d PT_Trees",
	      sglr_term_store_size);
      return -1;
    }

    /* Make sure 0 is in the uninitialized part of the array */
    memset(sglr_term_store + old_size, 0, 
	   (sglr_term_store_size - old_size) * sizeof(ATerm));

    ATprotectArray((ATerm*) sglr_term_store, sglr_term_store_size);

    /*ATwarning("reallocated sglr_term_store at size: %d\n", sglr_term_store_size);*/
  }

  /* begin and end are both inclusive boundaries */
  old_begin        = sglr_term_store_begin;
  sglr_term_store_begin = sglr_term_store_end + 1;
  sglr_term_store_end   = sglr_term_store_begin + size - 1;

  /*ATwarning("sglr_term_store begin at: %d (was %d)\n", sglr_term_store_begin, old_begin);*/
  return old_begin;
}

void SGLR_TS_pop(size_t index)
{
  /*ATwarning("sglr_term_store begin back to: %d (was %d)\n", index, sglr_term_store_begin);*/
  sglr_term_store_end = sglr_term_store_begin - 1;
  sglr_term_store_begin = index;
}

