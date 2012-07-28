#include <asc-termstore.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define TERM_STORE_INITIAL_SIZE    (8*1024)

size_t term_store_begin; 
size_t term_store_end;   
size_t term_store_size;
ATerm* term_store = NULL;


/* This term_store is built to cope with a recursive function. Each
 * of its calls needs its own term_store, but we want to reuse allocated
 * memory. It works somewhat like a stack using getTermStore as a push and
 * resetTermStore as a pop. Term_store_end holds the top of the stack.
 */
void TS_create(void)
{
  term_store_size = TERM_STORE_INITIAL_SIZE;
  term_store_begin = -1;
  term_store_end = -1;

  term_store = (ATerm*) calloc(term_store_size, sizeof(ATerm));

  if (term_store == NULL) {
    ATerror("TS_create: unable to allocate memory for %d Trees",
	    term_store_size);
  }

  /*ATwarning("created term store of size: %d\n", term_store_size);*/
  ATprotectArray(term_store, term_store_size);
}

void TS_destroy(void)
{
  ATunprotectArray(term_store);

  free(term_store);
  term_store_size = 0;
  term_store = NULL;
}

size_t TS_push(size_t size)
{
  size_t old_begin;

  assert(size > 0);

  /*ATwarning("pushing %d\n", size);*/

  if (term_store_size <= size + term_store_end) {
    size_t old_size = term_store_size;
    ATunprotectArray((ATerm*) term_store);

    /* Allocate at least enough memory for the request, and then
     * some more to prevent this from happening too often.
     */
    term_store_size = size + term_store_end + 1 + TERM_STORE_INITIAL_SIZE;
    term_store = (ATerm *) realloc(term_store,
				     term_store_size * sizeof(ATerm));

    if (term_store == NULL) {
      ATerror("resizeTermStore: unable to allocate memory for %d PT_Trees",
	      term_store_size);
      return -1;
    }

    /* Make sure 0 is in the uninitialized part of the array */
    memset(term_store + old_size, 0, 
	   (term_store_size - old_size) * sizeof(ATerm));

    ATprotectArray((ATerm*) term_store, term_store_size);

    /*ATwarning("reallocated term_store at size: %d\n", term_store_size);*/
  }

  /* begin and end are both inclusive boundaries */
  old_begin        = term_store_begin;
  term_store_begin = term_store_end + 1;
  term_store_end   = term_store_begin + size - 1;

  /*ATwarning("term_store begin at: %d (was %d)\n", term_store_begin, old_begin);*/
  return old_begin;
}

void TS_pop(size_t index)
{
  /*ATwarning("term_store begin back to: %d (was %d)\n", index, term_store_begin);*/
  term_store_end = term_store_begin - 1;
  term_store_begin = index;
}

