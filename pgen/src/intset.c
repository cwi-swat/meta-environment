
/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>

#include "intset.h"

/*}}}  */
/*{{{  defines */

#define BITS_PER_LONG (sizeof(unsigned long)*8)
#define NR_LONGS(max) ((((max)-1)/BITS_PER_LONG)+1)

/*}}}  */

/*{{{  IS_IntSet IS_create(int max_int) */

IS_IntSet IS_create(int max_int)
{
  IS_IntSet set;

  set = calloc(NR_LONGS(max_int), sizeof(unsigned long));
  if (set == NULL) {
    fprintf(stderr, "out of memory in IS_create(%d)\n", max_int);
    exit(1);
  }

  return set;
}

/*}}}  */
/*{{{  void IS_destroy(IS_IntSet set) */

void IS_destroy(IS_IntSet set)
{
  free(set);
}

/*}}}  */
/*{{{  void IS_add(IS_IntSet set, int i) */

void IS_add(IS_IntSet set, int i)
{
  int index;
  unsigned long mask;

  index = i/BITS_PER_LONG;
  mask  = 1 << (i % BITS_PER_LONG);

  set[index] |= mask;
}

/*}}}  */
/*{{{  void IS_remove(IS_IntSet set, int i) */

void IS_remove(IS_IntSet set, int i)
{
  int index;
  unsigned long mask;

  index = i/BITS_PER_LONG;
  mask  = 1 << (i % BITS_PER_LONG);

  set[index] &= ~mask;
}

/*}}}  */
/*{{{  int  IS_contains(IS_IntSet set, int i) */

int  IS_contains(IS_IntSet set, int i)
{
  int index;
  unsigned long mask;

  index = i/BITS_PER_LONG;
  mask  = 1 << (i % BITS_PER_LONG);

  return (set[index] & mask) == 0 ? 0 : 1;
}

/*}}}  */

