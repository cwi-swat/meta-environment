/* $Id$ */

/**
 * \file
 *
 * IntSets are an efficient implementation of integer sets. They represent an 
 * integer by setting the appropriate bit in an array. Each element in that 
 * array represents the number of bits in an unsigned long. Therefore, on a 
 * 32-bit machine, each element in the IntSet represents 32 production 
 * numbers. To check if a production number is in an IntSet we find the correct
 * element in the array by dividing the production number by 32. Then by 
 * modding the production number by 32 we find the bit for that production.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intset.h"

#define BITS_PER_LONG (sizeof(unsigned long)*8)
#define NR_LONGS(max) ((((max)-1)/BITS_PER_LONG)+1)

IS_IntSet IS_create(int max_int) {
  IS_IntSet set;

  set = calloc(NR_LONGS(max_int), sizeof(unsigned long));
  if (set == NULL) {
    fprintf(stderr, "out of memory in IS_create(%d)\n", max_int);
    exit(1);
  }

  return set;
}

void IS_destroy(IS_IntSet set) {
  free(set);
}

void IS_flush(IS_IntSet set, int max_int) {
  memset(set, 0, NR_LONGS(max_int)*sizeof(unsigned long));
}

int IS_add(IS_IntSet set, int i) {
  int index;
  unsigned long mask;

  index = i/BITS_PER_LONG;
  mask  = 1UL << (i % BITS_PER_LONG);

  if (set[index] & mask) {
    return 0;
  }

  set[index] |= mask;
  return 1;
}

void IS_remove(IS_IntSet set, int i) {
  int index;
  unsigned long mask;

  index = i/BITS_PER_LONG;
  mask  = 1UL << (i % BITS_PER_LONG);

  set[index] &= ~mask;
}

int  IS_contains(IS_IntSet set, int i) {
  int index;
  unsigned long mask;

  index = i/BITS_PER_LONG;
  mask  = 1UL << (i % BITS_PER_LONG);

  return (set[index] & mask) == 0 ? 0 : 1;
}


