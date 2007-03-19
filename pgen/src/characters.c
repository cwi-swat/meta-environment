/* $Id$ */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <aterm2.h>

#include "characters.h"
#include "first.h"
#include "pgen-symbol.h"


#define CC_BLOCK_SIZE 1024
#define SET_BLOCK_SIZE  32

union CC_Node {
  CC_Class *cc;
  CC_Class **next;
};

static union CC_Node free_node = {NULL};
static unsigned long last_mask = 0;

static CC_Class **char_classes     = NULL;
static int        max_char_classes = 0;

void CC_init() {
  int last_bits;

  last_bits = CC_BITS-((CC_LONGS-1)*BITS_PER_LONG);
  last_mask = (1UL<<last_bits) - 1;

  max_char_classes = 512;
  char_classes = (CC_Class **)calloc(max_char_classes, sizeof(CC_Class *));
  if (!char_classes) {
    ATerror("out of memory in CC_init %d\n", max_char_classes);
  }
}

void CC_cleanup() {
  int i;

  for (i=0; i<max_char_classes; i++) {
    if (char_classes[i]) {
      CC_free(char_classes[i]);
    }
  }
  free(char_classes);
  char_classes = NULL;
  max_char_classes = 0;
}

CC_Class *CC_alloc() {
#ifdef DEBUG_ALLOC
  return (CC_Class *)calloc(1, sizeof(CC_Class));
#else
  int i;
  CC_Class *block;
  CC_Class *c;
  union CC_Node node;

  if (free_node.cc == NULL) {
    block = (CC_Class *)calloc(CC_BLOCK_SIZE, sizeof(CC_Class));
    if (block == NULL) {
      ATerror("error allocating charclass block\n");
    }

    for (i=CC_BLOCK_SIZE-1; i>=0; i--) {
      c = &block[i];
      node.cc = c;
      *(node.next) = free_node.cc;
      free_node.cc = node.cc;
    }
  }

  c = free_node.cc;
  free_node.cc = *(free_node.next);

  for (i=0; i<CC_LONGS; i++) {
    (*c)[i] = 0L;
  }

  return c;
#endif
}

void printCC_Class(CC_Class *c) {
  int i;
  ATwarning("CC_Class: ");
  for (i = 0; i < CC_LONGS; i++) {
    ATwarning("%d", (*c)[i]);
  }
  ATwarning("\n");
}

CC_Class *CC_makeClassEmpty() {
  return CC_alloc();
}

CC_Class *CC_makeClassAllChars() {
  CC_Class *c = CC_alloc();
  int i;

  for (i=0; i<CC_LONGS; i++) {
    (*c)[i] = -1L;
  }

  (*c)[CC_LONGS-1] &= last_mask;

  return c;
}

void CC_clear(CC_Class *cc) {
  int i;

  for (i=0; i<CC_LONGS; i++) {
    (*cc)[i] = 0L;
  }
}

void CC_free(CC_Class *cc) {
#ifdef DEBUG_ALLOC
  free(cc);
#else
  union CC_Node node;
  node.cc = cc;
  *(node.next) = free_node.cc;
  free_node = node;
#endif
}

void CC_addChar(CC_Class *cc, int c) {
  int index;
  unsigned long mask;
 
  assert(c >= 0 && c < CC_BITS);
  index = c/BITS_PER_LONG;
  mask  = 1UL << (c % BITS_PER_LONG);
  
  (*cc)[index] |= mask;
}

void CC_addRange(CC_Class *cc, int start, int end) {
  int c;

  assert(0 <= start && start <= end);

  if (start >= CC_BITS || end >= CC_BITS) {
    ATerror("Character range %d-%d outside Latin-1 set, bailing out!\n",
	    start, end);
  }

  for (c=start; c<=end; c++) {
    int index = c/BITS_PER_LONG;
    unsigned long mask  = 1UL << (c % BITS_PER_LONG);

    (*cc)[index] |= mask;
  }
}

void CC_removeChar(CC_Class *cc, int c) {
  int index;
  unsigned long mask;

  assert(c >= 0 && c < CC_BITS);
  index = c/BITS_PER_LONG;
  mask  = ~(1UL << (c % BITS_PER_LONG));
  
  (*cc)[index] &= mask;
}

CC_Class *CC_ClassFromInt(int i) {
  CC_Class *c;

  c = CC_makeClassEmpty();

  CC_addChar(c, i);

  return c;
}

CC_Class *CC_ClassFromPTSymbol(PT_Symbol t) {
  CC_Class *c;

  c = CC_makeClassEmpty();
  CC_addPTSymbolToClass(c, t);

  return c;
}

CC_Class *CC_ClassFromTerm(ATerm t) {
  CC_Class *c;

  c = CC_makeClassEmpty();
  CC_addATermClass(c, t);

  return c;
}

CC_Class *CC_ClassFromTermList(ATermList l) {
  CC_Class *c;

  c = CC_makeClassEmpty();

  while (!ATisEmpty(l)) {
    CC_addATermClass(c, ATgetFirst(l));
    l = ATgetNext(l);
  }

  return c;
}

ATerm CC_ClassToTerm(CC_Class *cc) {
  ATermList range_set = ATempty;
  ATerm elem;
  int i, start, end;

  for (i=CC_BITS-1; i>=0; i--) {
    while (i % BITS_PER_LONG == (BITS_PER_LONG -1) && cc[i/BITS_PER_LONG] == 0) {
      i -= BITS_PER_LONG;
      if (i == -1) {
        return (ATerm)range_set;
      }
    }

    if (CC_containsChar(cc, i)) {
      end   = i;
      start = end-1;

      while (start>=0 && CC_containsChar(cc, start)) {
        start--;
      }

      if (start < (end-1)) {
        /* Add a range */
        elem = (ATerm)PT_makeCharRangeRange(start+1,end);
      } else {
        elem = (ATerm)PT_makeCharRangeCharacter(end);
      }

      range_set = ATinsert(range_set, elem);

      i = start;
    }
  }

  return (ATerm)range_set;
}


/*CC_Class *CC_ClassFromTermList(PT_CharRanges l) {
  CC_Class *c;

  c = CC_makeClassEmpty();

  while (!PT_isCharRangesEmpty(l)) {
    CC_addATermClass(c, PT_getCharRangesHead(l));
    l = PT_getCharRangesTail(l);
  }

  return c;
}
*/

PT_CharRanges CC_ClassToPTCharRanges(CC_Class *cc) {
  PT_CharRanges range_set = PT_makeCharRangesEmpty();
  PT_CharRange elem;
  int i, start, end;

  /* TODO: Ensure API is initialised. */

  for (i=CC_BITS-1; i>=0; i--) {
    while (i % 32 == 31 && cc[i/32] == 0) {
      i -= 32;
      if (i == -1) {
        return range_set;
      }
    }

    if (CC_containsChar(cc, i)) {
      end   = i;
      start = end-1;

      while (start>=0 && CC_containsChar(cc, start)) {
        start--;
      }

      if (start < (end-1)) {
        /* Add a range */
        elem = PT_makeCharRangeRange(start+1,end);
      } else {
        elem = PT_makeCharRangeCharacter(end);
      }

      range_set = PT_makeCharRangesMany(elem, range_set);

      i = start;
    }
  }

  return range_set;
}

/* Add a PT_CharRange to a character class. */
void CC_addPTSymbolToClass(CC_Class *cc, PT_Symbol t) {
  PT_CharRanges range_set;
  int start;
  
  /* TODO: Ensure API is initialised. */
  if (PT_isSymbolEmpty(t)) {
    CC_addChar(cc, CC_EPSILON);
    return;
  }

  if (!PT_isSymbolCharClass(t)) {
    return;
  }

  range_set = PT_getSymbolRanges(t);
  
  while (!PT_isCharRangesEmpty(range_set)) {
    PT_CharRange range_or_char = PT_getCharRangesHead(range_set);
    range_set = PT_getCharRangesTail(range_set);

    start = PT_getCharRangeStart(range_or_char);
    if (PT_isCharRangeRange(range_or_char)) {
	  int end = PT_getCharRangeEnd(range_or_char);
      CC_addRange(cc, start, end);
	}
    else {
      CC_addChar(cc, start);
    }
  }
}

void CC_addATermClass(CC_Class *cc, ATerm t) {
  ATermList range_set;

/*  assert(afun_range >= 0);*/

  if (ATisEqual(t, (ATerm)NULL)) {
    CC_addChar(cc, CC_EPSILON);
    return;
  }

  if (!ATmatch(t, "char-class(<term>)", &range_set)) {
    return;
  }

  while (!ATisEmpty(range_set)) {
    ATerm range_or_char = ATgetFirst(range_set);
    range_set = ATgetNext(range_set);

    switch (ATgetType(range_or_char)) {
      case AT_APPL:
        /* Must be a range */
        {
          ATermAppl appl = (ATermAppl)range_or_char;
          ATermInt start = (ATermInt)ATgetArgument(appl, 0);
          ATermInt end   = (ATermInt)ATgetArgument(appl, 1);
          CC_addRange(cc, ATgetInt(start), ATgetInt(end));
        }

        break;
      case AT_INT:
        /* Must be a single character */
        CC_addChar(cc, ATgetInt((ATermInt)range_or_char));
        break;
    }
  }
}


ATbool CC_union(CC_Class *cc1, CC_Class *cc2, CC_Class *result) {
  int i;
  unsigned long mask = 0;

  for (i=0; i<CC_LONGS; i++) {
    mask |= ((*result)[i] = (*cc1)[i] | (*cc2)[i]);
  }

  return mask == 0 ? ATfalse : ATtrue;
}

ATbool CC_intersection(CC_Class *cc1, CC_Class *cc2, CC_Class *result) {
  int i;
  unsigned long mask = 0;

  for (i=0; i<CC_LONGS; i++) {
    mask |= ((*result)[i] = (*cc1)[i] & (*cc2)[i]);
  }

  return mask == 0 ? ATfalse : ATtrue;
}

ATbool CC_difference(CC_Class *set, CC_Class *to_remove, CC_Class *result) {
  int i;
  unsigned long mask = 0;

  for (i=0; i<CC_LONGS; i++) {
    mask |= ((*result)[i] = (*set)[i] & ~(*to_remove)[i]);
  }

  return mask == 0 ? ATfalse : ATtrue;
}

ATbool CC_copy(CC_Class *source, CC_Class *dest) {
  int i;
  unsigned long mask = 0;

  for (i=0; i<CC_LONGS; i++) {
    mask |= ((*dest)[i] = (*source)[i]);
  }

  return mask == 0 ? ATfalse : ATtrue;
}

ATbool CC_complement(CC_Class *cc, CC_Class *result) {
  int i;
  unsigned long mask = 0;

  for (i=0; i<CC_LONGS; i++) {
    mask |= ((*result)[i] = ~(*cc)[i]);
  }

  mask |= ((*result)[CC_LONGS-1] &= last_mask);

  return mask == 0 ? ATfalse : ATtrue;
}

ATbool CC_isEmpty(CC_Class *cc) {
  int i;

  for (i=0; i<CC_LONGS; i++) {
    if ((*cc)[i] != 0) {
      return ATfalse;
    }
  }

  return ATtrue;
}

ATbool CC_isEOF(CC_Class *cc) {
  ATbool result;

  if (!CC_containsChar(cc, CC_EOF)) {
    return ATfalse;
  }

  CC_removeChar(cc, CC_EOF);

  result = CC_isEmpty(cc);

  CC_addChar(cc, CC_EOF);

  return result;
}

ATbool CC_isSubset(CC_Class *needle, CC_Class *haystack) {
  int i;
  unsigned long mask, result;

  for (i=0; i<CC_LONGS; i++) {
    mask = ~(*haystack)[i];
    result = (*needle)[i] & mask;
    if (result) {
      return ATfalse;
    }
  }

  return ATtrue;
}

ATbool CC_isEqual(CC_Class *cc1, CC_Class *cc2) {
  int i;

  for (i=0; i<CC_LONGS-1; i++) {
    if ((*cc1)[i] != (*cc2)[i]) {
      return ATfalse;
    }
  }

  if (((*cc1)[CC_LONGS-1] & last_mask) != ((*cc2)[CC_LONGS-1] & last_mask)) {
    return ATfalse;
  }

  return ATtrue;
}

void CC_writeToFile(FILE *f, CC_Class *cc) {
  ATfprintf(f, "%t\n", CC_ClassToPTCharRanges(cc));
}

void CC_initSet(CC_Set *set) {
  set->max_size = 0;
  set->size = 0;
  set->classes = NULL;
}

void CC_initSetWithSize(CC_Set *set, int size) {
  set->max_size = size;
  set->size = size;
  set->classes = (CC_Class **)calloc(size, sizeof(CC_Class *));
}

void CC_flushSet(CC_Set *set) {
  if (set->classes) {
    CC_clearSet(set);

    free(set->classes);
  }

  set->classes = NULL;
  set->size = 0;
  set->max_size = 0;
}

void CC_clearSet(CC_Set *set) {
  int i;

  if (set->classes) {
    for (i=0; i<set->size; i++) {
      if (set->classes[i]) {
	CC_free(set->classes[i]);
	set->classes[i] = NULL;
      }
    }

    set->size = 0;
  }
}

CC_Class *CC_addToSet(CC_Set *set) {
  CC_Class *result;

  if (set->size >= set->max_size) {
    int old_size = set->max_size;
    set->max_size += SET_BLOCK_SIZE;
    set->classes = (CC_Class **)realloc(set->classes,
					set->max_size*sizeof(CC_Class *));
    if (!set->classes) {
      fprintf(stderr, "out of memory in CC_addToSet (%d)\n", set->max_size);
    }
    memset(&set->classes[old_size], 0, SET_BLOCK_SIZE*sizeof(CC_Class *));
  }

  result = CC_alloc();
  set->classes[set->size++] = result;

  return result;
}

CC_Class *CC_getFromSet(CC_Set *set, int elem) {
  assert(elem >= 0 && elem < set->size);
  return set->classes[elem];
}

void CC_copySet(CC_Set *source, CC_Set *dest) {
  int i;

  CC_flushSet(dest);
  for (i=0; i<source->size; i++) {
    CC_Class *from = CC_getFromSet(source, i);
    CC_Class *to = CC_addToSet(dest);
    CC_copy(from, to);
  }
}

void CC_addBoundaries(CC_Class *elems, CC_Class *bounds) {
  int i;
  ATbool cur = ATfalse, contains;

  for (i=0; i<CC_BITS; i++) {
    contains = CC_containsChar(elems, i);
    if (contains != cur) {
      CC_addChar(bounds, i);
    }
    cur = contains;
  }
}

void CC_partitionSet(CC_Set *set) {
  CC_Set result;
  CC_Class cur, *peer, *next, intersection, difference;
  int i, j;

  /*
  ATwarning("partition of ");
  CC_writeSetToFile(stderr, set);
  */

  CC_initSet(&result);
  for (i=0; i<set->size; i++) {
    CC_copy(CC_getFromSet(set, i), &cur);
    for (j=result.size-1; j>=0; j--) {
      peer = CC_getFromSet(&result, j);
      if (CC_intersection(&cur, peer, &intersection)) {
	if (CC_difference(peer, &intersection, &difference)) {
	  next = CC_addToSet(&result);
	  CC_copy(&difference, next);
	}
	CC_copy(&intersection, peer);
	if (!CC_difference(&cur, &intersection, &cur)) {
	  break;
	}
      }
    }

    if (!CC_isEmpty(&cur)) {
      next = CC_addToSet(&result);
      CC_copy(&cur, next);
    }
  }

  CC_copySet(&result, set);
  CC_flushSet(&result);
}

/* This function can be called with result == set! */
void CC_SetIntersection(CC_Set *set, CC_Class *cc, CC_Set *result) {
  int i;
  CC_Class *next;

  result->size = 0;

  next = CC_addToSet(result);
  for (i=0; i<set->size; i++) {
    if (CC_intersection(CC_getFromSet(set, i), cc, next)) {
      next = CC_addToSet(result);
    }
  }

  /* Remove empty trailer */
  result->size--;
  CC_free(result->classes[result->size]);
  result->classes[result->size] = NULL;
}

/* This function can be called with result == set! */
void CC_SetDifference(CC_Set *set, CC_Class *cc, CC_Set *result) {
  int i, size;
  CC_Class *next;

  size = set->size;
  result->size = 0;

  next = CC_addToSet(result);
  for (i=0; i<size; i++) {
    if (CC_difference(CC_getFromSet(set, i), cc, next)) {
      next = CC_addToSet(result);
    }
  }

  /* Remove empty trailer */
  result->size--;
  CC_free(result->classes[result->size]);
  result->classes[result->size] = NULL;
}

int CC_getSetSize(CC_Set *set) {
  return set->size;
}

void CC_writeSetToFile(FILE *f, CC_Set *set) {
  int i;

  fputc('{', f);
  for (i=0; i<set->size; i++) {
    if (i != 0) {
      fputc(',', f);
    }
    CC_writeToFile(f, CC_getFromSet(set, i));
  }
  fputc('}', f);
}

CC_Class *CC_getCharClass(PT_Symbol symbol) {
  long index;
  int old_size;

  index = internSymbol(symbol);
  if (index >= max_char_classes) {
    old_size = max_char_classes;
    max_char_classes *= 2;
    char_classes = (CC_Class **)realloc(char_classes,
					max_char_classes*sizeof(CC_Class *));
    if (!char_classes) {
      ATerror("out of memory in get_charclass %d\n", max_char_classes);
    }
    memset(&char_classes[old_size], 0, old_size*sizeof(CC_Class *));
  }

  if (char_classes[index] == NULL) {
    char_classes[index] = CC_ClassFromPTSymbol(symbol);
  }

  return char_classes[index];
}


