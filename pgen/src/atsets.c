#include <stdlib.h>
#include <assert.h>

#include "atsets.h"


#define MAGIC_K 1999

/**
 * Maybe these functions should be moved to the ATermLibrary.
 **/

/*{{{  ATermList ATunion(ATermList l1, ATermList l2) */

ATermList ATunion(ATermList l1, ATermList l2)
{
  static int max = 0;
  static ATerm *elems = NULL;

  int count, len1, len2, idx;
  ATermList result1, list;
  ATerm elem;

  if (ATisEqual(l1,l2)) 
    return l1;

  if (ATisEmpty(l1))
    return l2;

  if (ATisEmpty(l2))
    return l1;

  len1 = ATgetLength(l1);
  len2 = ATgetLength(l2);
  if (len1 > len2) {
    result1 = l2;
    l2 = l1;
    l1 = result1;
    count = len2;
    len2 = len1;
    len1 = count;
  }

  list = l2;
  while (!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    SET_MARK(elem->header);
  }

  count = len1;

  if (count > max) {
    max = count;
    elems = realloc(elems, sizeof(ATerm)*max);
    if(!elems)
      ATerror("out of memory!\n");
  }

  count = 0;
  list = l1;
  while (!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    if(!IS_MARKED(elem->header))
      elems[count++] = elem;
  }

  list = l2;
  while (!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    CLR_MARK(elem->header);
  }

  result1 = l2;
  for (idx=0; idx<count; idx++) {
    result1 = ATinsert(result1, elems[idx]);
  }

  return result1;
}

/*}}}  */
/*{{{  ATermList ATunionSetList(ATermList sets) */

ATermList ATunionSetList(ATermList sets)
{
  static int max = 0;
  static ATerm *elems = NULL;

  int idx, count;
  ATermList l, set;

  count = 0;
  for(l=sets; !ATisEmpty(l); l=ATgetNext(l)) {
    for(set = (ATermList)ATgetFirst(l); !ATisEmpty(set); 
	set=ATgetNext(set)) {
      ATerm el = ATgetFirst(set);
      if(!IS_MARKED(el->header)) {
	SET_MARK(el->header);
	count++;
      }
    }
  }

  if(count > max) {
    max = count;
    elems = realloc(elems, sizeof(ATerm)*max);
    if(!elems)
      ATerror("out of memory!\n");
  }

  count = 0;
  for(l=sets; !ATisEmpty(l); l=ATgetNext(l)) {
    for(set = (ATermList)ATgetFirst(l); !ATisEmpty(set); 
	set=ATgetNext(set)) {
      ATerm el = ATgetFirst(set);
      if(IS_MARKED(el->header)) {
	elems[count++] = el;
	CLR_MARK(el->header);
      }
    }
  }

  set = ATempty;
  for(idx=0; idx<count; idx++)
    set = ATinsert(set, elems[idx]);

  return set;
}

/*}}}  */
/*{{{  ATbool ATsetEqual(ATermList l1, ATermList l2) */

ATbool ATsetEqual(ATermList l1, ATermList l2)
{
  ATbool result = ATtrue;

  ATermList list;
  ATerm elem;

  if(ATisEqual(l1,l2)) 
    return ATtrue;

  if(ATgetLength(l1) != ATgetLength(l2))
    return ATfalse;

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    SET_MARK(elem->header);
  }

  list = l1;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    if(!IS_MARKED(elem->header)) {
      result = ATfalse;
      break;
    }
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    CLR_MARK(elem->header);
  }

  return result;
}

/*}}}  */
/*{{{  ATermList ATaddElement(ATermList l, ATerm elem) */

ATermList ATaddElement(ATermList l, ATerm elem)
{
  int idx;

  idx = ATindexOf(l,elem,0);
  if(idx < 0)
    l = ATinsert(l,elem);
  return l;
}

/*}}}  */

/*{{{  ATermSetOfSets *ATsosCreate(int size) */

/**
 * Create a 'Set of Sets'
 */

ATermSOS *ATsosCreate(int initial_size)
{
  int i;
  ATermSOS *sos;

  sos = (ATermSOS *)calloc(1, sizeof(ATermSOS));
  if(!sos)
    ATerror("out of memory.\n");

  sos->table = (ATermList *)malloc(initial_size*sizeof(ATermList));
  if(!sos->table)
    ATerror("out of memory.\n");

  for(i=0; i<initial_size; i++)
    sos->table[i] = ATempty;

  ATprotectArray((ATerm *)sos->table, initial_size);
  sos->size = initial_size;
  sos->nr_sets = 0;

  return sos;
}

/*}}}  */
/*{{{  void ATsosResize(ATermSOS *sos, int newsize) */

/**
 * Resize the underlying table of a 'SetOfSets'
 */

void ATsosResize(ATermSOS *sos, int newsize)
{
  int i, oldsize, oldcount;
  ATermList *newtable, *oldtable;

  oldcount = sos->nr_sets;
  oldsize  = sos->size;
  oldtable = sos->table;
  newtable = (ATermList *)malloc(newsize*sizeof(ATermList));
  if(!newtable)
    ATerror("out of memory.\n");

  for(i=0; i<newsize; i++)
    newtable[i] = ATempty;

  ATprotectArray((ATerm *)newtable, newsize);
  sos->table = newtable;
  sos->size  = newsize;
  sos->nr_sets = 0;

  for(i=0; i<oldsize; i++) {
    ATermList sets = oldtable[i];
    while(!ATisEmpty(sets)) {
      ATermList set = (ATermList)ATgetFirst(sets);
      sets = ATgetNext(sets);
      ATsosInsert(sos, set);
    }
  }
  assert(sos->nr_sets == oldcount);
  ATunprotectArray((ATerm *)oldtable);
  free(oldtable);
}

/*}}}  */
/*{{{  ATermList ATsosInsert(ATermSOS *sos, ATermList set) */

/**
 * Insert a new set in a set-of-sets
 */

ATermList ATsosInsert(ATermSOS *sos, ATermList set)
{
  unsigned int hnr = 0;
  ATermList list, bucket;

  for(list=set; !ATisEmpty(list); list=ATgetNext(list)) {
    ATerm elem = ATgetFirst(list);
    hnr ^= (unsigned int)elem;
  }

  hnr *= MAGIC_K;
  hnr %= sos->size;

  bucket = sos->table[hnr];
  for(list=bucket; !ATisEmpty(list); list=ATgetNext(list)) {
    ATermList old = (ATermList)ATgetFirst(list);
    if(ATsetEqual(old, set))
      return old; /* Set already present in table! */
  }

  /* Set not present in table */
  sos->table[hnr] = ATinsert(bucket, (ATerm)set);
  sos->nr_sets++;
  return set;
}

/*}}}  */
/*{{{  void ATsosDestroy(ATermSOS *sos) */

/**
 * Dextroy a set of sets
 */

void ATsosDestroy(ATermSOS *sos)
{
  ATunprotectArray((ATerm *)sos->table);
  free(sos->table);
  free(sos);
}

/*}}}  */

/*{{{  ATermList ATunion1(ATermList l1, ATermList l2) */

ATermList ATunion1(ATermList l1, ATermList l2)
{
  static int max = 0;
  static ATerm *elems = NULL;

  int count, len1, len2, idx;
  ATermList result1, list;
  ATerm elem;

  if(ATisEqual(l1,l2)) 
    return l1;

  if(ATisEmpty(l1))
    return l2;

  if(ATisEmpty(l2))
    return l1;

  len1 = ATgetLength(l1);
  len2 = ATgetLength(l2);
  if(len1 > len2) {
    result1 = l2;
    l2 = l1;
    l1 = result1;
    count = len2;
    len2 = len1;
    len1 = count;
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    SET_MARK(elem->header);
  }

  count = len1;

  if(count > max) {
    max = count;
    elems = realloc(elems, sizeof(ATerm)*max);
    if(!elems)
      ATerror("out of memory!\n");
  }

  count = 0;
  list = l1;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    if(!IS_MARKED(elem->header))
      elems[count++] = elem;
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    CLR_MARK(elem->header);
  }

  result1 = l2;
  for(idx=0; idx<count; idx++)
    result1 = ATinsert(result1, elems[idx]);

  return result1;
}

/*}}}  */
/*{{{  ATermList ATunion2(ATermList l1, ATermList l2) */

ATermList ATunion2(ATermList l1, ATermList l2)
{
  static int max = 0;
  static ATerm *elems = NULL;

  int count, len1, len2, idx;
  ATermList result1, list;
  ATerm elem;

  if(ATisEqual(l1,l2)) 
    return l1;

  if(ATisEmpty(l1))
    return l2;

  if(ATisEmpty(l2))
    return l1;

  len1 = ATgetLength(l1);
  len2 = ATgetLength(l2);
  if(len1 > len2) {
    result1 = l2;
    l2 = l1;
    l1 = result1;
    count = len2;
    len2 = len1;
    len1 = count;
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    SET_MARK(elem->header);
  }

  count = len1;

  if(count > max) {
    max = count;
    elems = realloc(elems, sizeof(ATerm)*max);
    if(!elems)
      ATerror("out of memory!\n");
  }

  count = 0;
  list = l1;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    if(!IS_MARKED(elem->header))
      elems[count++] = elem;
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    CLR_MARK(elem->header);
  }

  result1 = l2;
  for(idx=0; idx<count; idx++)
    result1 = ATinsert(result1, elems[idx]);

  return result1;
}

/*}}}  */
/*{{{  ATermList ATunion3(ATermList l1, ATermList l2) */

ATermList ATunion3(ATermList l1, ATermList l2)
{
  static int max = 0;
  static ATerm *elems = NULL;

  int count, len1, len2, idx;
  ATermList result1, list;
  ATerm elem;

  if(ATisEqual(l1,l2)) 
    return l1;

  if(ATisEmpty(l1))
    return l2;

  if(ATisEmpty(l2))
    return l1;

  len1 = ATgetLength(l1);
  len2 = ATgetLength(l2);
  if(len1 > len2) {
    result1 = l2;
    l2 = l1;
    l1 = result1;
    count = len2;
    len2 = len1;
    len1 = count;
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    SET_MARK(elem->header);
  }

  count = len1;

  if(count > max) {
    max = count;
    elems = realloc(elems, sizeof(ATerm)*max);
    if(!elems)
      ATerror("out of memory!\n");
  }

  count = 0;
  list = l1;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    if(!IS_MARKED(elem->header))
      elems[count++] = elem;
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    CLR_MARK(elem->header);
  }

  result1 = l2;
  for(idx=0; idx<count; idx++)
    result1 = ATinsert(result1, elems[idx]);

  return result1;
}

/*}}}  */
/*{{{  ATermList ATunion4(ATermList l1, ATermList l2) */

ATermList ATunion4(ATermList l1, ATermList l2)
{
  static int max = 0;
  static ATerm *elems = NULL;

  int count, len1, len2, idx;
  ATermList result1, list;
  ATerm elem;

  if(ATisEqual(l1,l2)) 
    return l1;

  if(ATisEmpty(l1))
    return l2;

  if(ATisEmpty(l2))
    return l1;

  len1 = ATgetLength(l1);
  len2 = ATgetLength(l2);
  if(len1 > len2) {
    result1 = l2;
    l2 = l1;
    l1 = result1;
    count = len2;
    len2 = len1;
    len1 = count;
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    SET_MARK(elem->header);
  }

  count = len1;

  if(count > max) {
    max = count;
    elems = realloc(elems, sizeof(ATerm)*max);
    if(!elems)
      ATerror("out of memory!\n");
  }

  count = 0;
  list = l1;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    if(!IS_MARKED(elem->header))
      elems[count++] = elem;
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    CLR_MARK(elem->header);
  }

  result1 = l2;
  for(idx=0; idx<count; idx++)
    result1 = ATinsert(result1, elems[idx]);

  return result1;
}

/*}}}  */
/*{{{  ATermList ATunion5(ATermList l1, ATermList l2) */

ATermList ATunion5(ATermList l1, ATermList l2)
{
  static int max = 0;
  static ATerm *elems = NULL;

  int count, len1, len2, idx;
  ATermList result1, list;
  ATerm elem;

  if(ATisEqual(l1,l2)) 
    return l1;

  if(ATisEmpty(l1))
    return l2;

  if(ATisEmpty(l2))
    return l1;

  len1 = ATgetLength(l1);
  len2 = ATgetLength(l2);
  if(len1 > len2) {
    result1 = l2;
    l2 = l1;
    l1 = result1;
    count = len2;
    len2 = len1;
    len1 = count;
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    SET_MARK(elem->header);
  }

  count = len1;

  if(count > max) {
    max = count;
    elems = realloc(elems, sizeof(ATerm)*max);
    if(!elems)
      ATerror("out of memory!\n");
  }

  count = 0;
  list = l1;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    if(!IS_MARKED(elem->header))
      elems[count++] = elem;
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    CLR_MARK(elem->header);
  }

  result1 = l2;
  for(idx=0; idx<count; idx++)
    result1 = ATinsert(result1, elems[idx]);

  return result1;
}

/*}}}  */
/*{{{  ATermList ATunion6(ATermList l1, ATermList l2) */

ATermList ATunion6(ATermList l1, ATermList l2)
{
  static int max = 0;
  static ATerm *elems = NULL;

  int count, len1, len2, idx;
  ATermList result1, list;
  ATerm elem;

  if(ATisEqual(l1,l2)) 
    return l1;

  if(ATisEmpty(l1))
    return l2;

  if(ATisEmpty(l2))
    return l1;

  len1 = ATgetLength(l1);
  len2 = ATgetLength(l2);
  if(len1 > len2) {
    result1 = l2;
    l2 = l1;
    l1 = result1;
    count = len2;
    len2 = len1;
    len1 = count;
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    SET_MARK(elem->header);
  }

  count = len1;

  if(count > max) {
    max = count;
    elems = realloc(elems, sizeof(ATerm)*max);
    if(!elems)
      ATerror("out of memory!\n");
  }

  count = 0;
  list = l1;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    if(!IS_MARKED(elem->header))
      elems[count++] = elem;
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    CLR_MARK(elem->header);
  }

  result1 = l2;
  for(idx=0; idx<count; idx++)
    result1 = ATinsert(result1, elems[idx]);

  return result1;
}

/*}}}  */
/*{{{  ATermList ATunion7(ATermList l1, ATermList l2) */

ATermList ATunion7(ATermList l1, ATermList l2)
{
  static int max = 0;
  static ATerm *elems = NULL;

  int count, len1, len2, idx;
  ATermList result1, list;
  ATerm elem;

  if(ATisEqual(l1,l2)) 
    return l1;

  if(ATisEmpty(l1))
    return l2;

  if(ATisEmpty(l2))
    return l1;

  len1 = ATgetLength(l1);
  len2 = ATgetLength(l2);
  if(len1 > len2) {
    result1 = l2;
    l2 = l1;
    l1 = result1;
    count = len2;
    len2 = len1;
    len1 = count;
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    SET_MARK(elem->header);
  }

  count = len1;

  if(count > max) {
    max = count;
    elems = realloc(elems, sizeof(ATerm)*max);
    if(!elems)
      ATerror("out of memory!\n");
  }

  count = 0;
  list = l1;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    if(!IS_MARKED(elem->header))
      elems[count++] = elem;
  }

  list = l2;
  while(!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    CLR_MARK(elem->header);
  }

  result1 = l2;
  for(idx=0; idx<count; idx++)
    result1 = ATinsert(result1, elems[idx]);

  return result1;
}

/*}}}  */
