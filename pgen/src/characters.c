
/*{{{  includes */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <aterm2.h>

#include "characters.h"

/*}}}  */
/*{{{  defines */

#define CC_BLOCK_SIZE 1024

/*}}}  */
/*{{{  types */

struct CC_Node
{
  struct CC_Node *next;
};

/*}}}  */
/*{{{  variables */

static struct CC_Node *free_nodes = NULL;
static AFun afun_range	    = -1;
static AFun afun_char_class = -1;
static unsigned long last_mask = 0;

/*}}}  */

/*{{{  void CC_init() */

void CC_init()
{
  int last_bits;

  afun_range = ATmakeAFun("range", 2, ATfalse);
  ATprotectAFun(afun_range);
  afun_char_class = ATmakeAFun("char-class", 1, ATfalse);
  ATprotectAFun(afun_char_class);

  last_bits = CC_BITS-((CC_LONGS-1)*BITS_PER_LONG);
  last_mask = (1<<last_bits) - 1;
}

/*}}}  */

/*{{{  CC_Class CC_alloc() */

CC_Class CC_alloc()
{
  int i;
  CC_Class block;
  CC_Class c;
  struct CC_Node *node;

  if (free_nodes == NULL) {
    block = (CC_Class)calloc(CC_BLOCK_SIZE, sizeof(unsigned long)*CC_LONGS);
    if (block == NULL) {
      ATerror("error allocating charclass block\n");
    }

    for (i=CC_BLOCK_SIZE-1; i>=0; i--) {
      c = &block[CC_LONGS*i];
      node = (struct CC_Node *)c;
      node->next = free_nodes;
      free_nodes = node;
    }
  }

  c = (CC_Class)free_nodes;
  free_nodes = free_nodes->next;

  return c;
}

/*}}}  */

/*{{{  CC_Class CC_makeClassEmpty() */

CC_Class CC_makeClassEmpty()
{
  CC_Class c = CC_alloc();
  int i;

  for (i=0; i<CC_LONGS; i++) {
    c[i] = 0L;
  }

  return c;
}

/*}}}  */
/*{{{  CC_Class CC_makeClassAllChars() */

CC_Class CC_makeClassAllChars()
{
  CC_Class c = CC_alloc();
  int i;

  for (i=0; i<CC_LONGS; i++) {
    c[i] = -1L;
  }

  c[CC_LONGS-1] &= last_mask;

  return c;
}

/*}}}  */
/*{{{  void CC_free(CC_Class c) */

void CC_free(CC_Class c)
{
  struct CC_Node *node = (struct CC_Node *)c;
  node->next = free_nodes;
  free_nodes = node;
}

/*}}}  */

/*{{{  CC_Class CC_addChar(CC_Class cc, int c) */

CC_Class CC_addChar(CC_Class cc, int c)
{
  int index;
  unsigned long mask;
 
  assert(c >= 0 && c < CC_BITS);
  index = c/BITS_PER_LONG;
  mask  = 1 << (c % BITS_PER_LONG);
  
  cc[index] |= mask;

  return cc;
}

/*}}}  */
/*{{{  CC_Class CC_addRange(CC_Class cc, int start, int end) */

CC_Class CC_addRange(CC_Class cc, int start, int end)
{
  int c;

  assert(start >= 0 && start < CC_BITS && end >= start && end < CC_BITS);

  for (c=start; c<=end; c++) {
    int index = c/BITS_PER_LONG;
    int mask  = 1 << (c % BITS_PER_LONG);

    cc[index] |= mask;
  }


  return cc;
}

/*}}}  */
/*{{{  CC_Class CC_removeChar(CC_Class cc, int c) */

CC_Class CC_removeChar(CC_Class cc, int c)
{
  int index;
  unsigned long mask;

  assert(c >= 0 && c < CC_BITS);
  index = c/BITS_PER_LONG;
  mask  = ~(1 << (c % BITS_PER_LONG));
  
  cc[index] &= mask;

  return cc;
}

/*}}}  */

/*{{{  CC_Class CC_ClassFromInt(ATermInt i) */

CC_Class CC_ClassFromInt(ATermInt i)
{
  CC_Class c;

  c = CC_makeClassEmpty();

  CC_addChar(c, ATgetInt(i));

  return c;
}

/*}}}  */
/*{{{  CC_Class CC_ClassFromTerm(ATerm t) */

CC_Class CC_ClassFromTerm(ATerm t)
{
  CC_Class c;
  ATermList range_set;

  assert(afun_range >= 0);

  c = CC_makeClassEmpty();

  /*
  assert(ATgetType(t) == AT_LIST);
  range_set = (ATermList)t;
  */

  if (!ATmatch(t, "char-class(<term>)", &range_set)) {
    return c;
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
	  CC_addRange(c, ATgetInt(start), ATgetInt(end));
	}
	break;
      case AT_INT:
	/* Must be a single character */
	CC_addChar(c, ATgetInt((ATermInt)range_or_char));
	break;
    }
  }

  return c;
}

/*}}}  */
/*{{{  ATerm CC_ClassToTerm(CC_Class cc) */

ATerm CC_ClassToTerm(CC_Class cc)
{
  ATermList range_set = ATempty;
  ATerm elem;
  int i, start, end;

  assert(afun_range >= 0);

  for (i=CC_BITS-1; i>=0; i--) {
    if (CC_containsChar(cc, i)) {
      end   = i;
      start = end-1;

      while (start>=0 && CC_containsChar(cc, start)) {
	start--;
      }

      if (start < (end-1)) {
	/* Add a range */
	elem = (ATerm)ATmakeAppl2(afun_range, (ATerm)ATmakeInt(start+1),
				  (ATerm)ATmakeInt(end));
      } else {
	elem = (ATerm)ATmakeInt(end);
      }

      range_set = ATinsert(range_set, elem);

      i = start;
    }
  }

  return (ATerm)range_set;
  /*return (ATerm)ATmakeAppl1(afun_char_class, (ATerm)range_set);*/
}

/*}}}  */

/*{{{  void CC_addATermClass(CC_Class cc, ATerm t) */

void CC_addATermClass(CC_Class cc, ATerm t)
{
  CC_Class temp;

  temp = CC_ClassFromTerm(t);
  CC_union(cc, temp);
  CC_free(temp);
}

/*}}}  */

/*{{{  CC_Class CC_union(CC_Class cc1, CC_Class cc2) */

CC_Class CC_union(CC_Class cc1, CC_Class cc2)
{
  int i;

  for (i=0; i<CC_LONGS; i++) {
    cc1[i] |= cc2[i];
  }

  return cc1;
}

/*}}}  */
/*{{{  CC_Class CC_intersection(CC_Class cc1, CC_Class cc2) */

CC_Class CC_intersection(CC_Class cc1, CC_Class cc2)
{
  int i;

  for (i=0; i<CC_LONGS; i++) {
    cc1[i] &= cc2[i];
  }

  return cc1;
}

/*}}}  */
/*{{{  CC_Class CC_difference(CC_Class cc1, CC_Class cc2) */

CC_Class CC_difference(CC_Class set, CC_Class to_remove)
{
  int i;

  for (i=0; i<CC_LONGS; i++) {
    set[i] &= ~to_remove[i];
  }

  return set;
}

/*}}}  */
/*{{{  void CC_copy(CC_Class dest, CC_Class source) */

void CC_copy(CC_Class dest, CC_Class source)
{
  int i;

  for (i=0; i<CC_LONGS; i++) {
    dest[i] = source[i];
  }
}

/*}}}  */
/*{{{  CC_Class CC_complement(CC_Class cc) */

CC_Class CC_complement(CC_Class cc)
{
  int i;

  for (i=0; i<CC_LONGS; i++) {
    cc[i] = ~cc[i];
  }

  cc[CC_LONGS-1] &= last_mask;

  return cc;
}

/*}}}  */

/*{{{  ATbool CC_containsChar(CC_Class cc, int c) */

ATbool CC_containsChar(CC_Class cc, int c)
{
  int index;
  unsigned long mask;
 
  assert(c >= 0 && c < CC_BITS);
  index = c/BITS_PER_LONG;
  mask  = 1 << (c % BITS_PER_LONG);
  
  return (cc[index] & mask) == 0 ? ATfalse : ATtrue;
}

/*}}}  */
/*{{{  ATbool CC_isEmpty(CC_Class cc) */

ATbool CC_isEmpty(CC_Class cc)
{
  int i;

  for (i=0; i<CC_LONGS; i++) {
    if (cc[i] != 0) {
      return ATfalse;
    }
  }

  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CC_isEOF(CC_Class cc) */

ATbool CC_isEOF(CC_Class cc)
{
  ATbool result;

  if (!CC_containsChar(cc, CC_EOF)) {
    return ATfalse;
  }

  CC_removeChar(cc, CC_EOF);

  result = CC_isEmpty(cc);

  CC_addChar(cc, CC_EOF);

  return result;
}

/*}}}  */
/*{{{  ATbool CC_isSubset(CC_Class needle, CC_Class haystack) */

ATbool CC_isSubset(CC_Class needle, CC_Class haystack)
{
  int i;
  unsigned long mask, result;

  for (i=0; i<CC_LONGS; i++) {
    mask = ~haystack[i];
    result = needle[i] & mask;
    if (result) {
      return ATfalse;
    }
  }

  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CC_isEqual(CC_Class cc1, CC_Class cc2) */

ATbool CC_isEqual(CC_Class cc1, CC_Class cc2)
{
  int i;

  for (i=0; i<CC_LONGS-1; i++) {
    if (cc1[i] != cc2[i]) {
      return ATfalse;
    }
  }

  if ((cc1[CC_LONGS-1] & last_mask) != (cc2[CC_LONGS-1] & last_mask)) {
    return ATfalse;
  }

  return ATtrue;
}

/*}}}  */

/*{{{  void CC_writeToFile(FILE *f, CC_Class cc) */

void CC_writeToFile(FILE *f, CC_Class cc)
{
  ATfprintf(f, "%t\n", CC_ClassToTerm(cc));
}

/*}}}  */

