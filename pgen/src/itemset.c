
/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <aterm2.h>

#include "itemset.h"

/*}}}  */
/*{{{  defines */


#define INITIAL_TABLE_SIZE 16
#define MAGIC_K		   17
#define MAGIC_JUMP	   5
#define HASH(item)	   ((unsigned)(((unsigned int)item)*MAGIC_K))
#define THRESHOLD_PCT	   70


/*}}}  */
/*{{{  typedef struct ItemBucket */

typedef struct
{
  ATerm symbol;
  int   size;
  Item *items;
} ItemBucket;

/*}}}  */
/*{{{  struct _ItemSet */

struct _ItemSet
{
  int   size;
  int   count;
  Item *table;
  Item *list;
  ItemBucket **items_per_dotsym;
};

/*}}}  */

/*{{{  static void ITS_init(ItemSet set, int size) */

static void ITS_init(ItemSet set, int size)
{
  int i;

  set->count = 0;
  set->size = size;
  set->table = (Item *)malloc(size*sizeof(Item));
  if (set->table == NULL) {
    ATerror("ITS_init: out of memory (2).\n");
  }

  set->list = (Item *)malloc(size*sizeof(Item));
  if (set->list == NULL) {
    ATerror("ITS_init: out of memory (3).\n");
  }

  set->items_per_dotsym = (ItemBucket **)calloc(size, sizeof(ItemBucket *));
  if (set->items_per_dotsym == NULL) {
    ATerror("ITS_init: out of memory (4).\n");
  }

  for (i=0; i<set->size; i++) {
    set->table[i] = NO_ITEM;
    set->list[i]  = NO_ITEM;
    set->items_per_dotsym[i] = NULL;
  }
}

/*}}}  */
/*{{{  ItemSet ITS_create() */

ItemSet ITS_create()
{
  ItemSet set = malloc(sizeof(struct _ItemSet));
  if (set == NULL) {
    ATerror("ITS_create: out of memory.\n");
  }

  ITS_init(set, INITIAL_TABLE_SIZE);

  return set;
}

/*}}}  */

/*{{{  static void ITS_flush(ItemSet set) */

static void ITS_flush(ItemSet set)
{
  int i;

  assert(set->list);
  free(set->list);
  set->list = NULL;

  assert(set->table);
  free(set->table);
  set->table = NULL;

  for (i=0; i<set->size; i++) {
    ItemBucket *cur = set->items_per_dotsym[i];
    if (cur) {
      free(cur->items);
      free(cur);
    }
  }

  free(set->items_per_dotsym);
}

/*}}}  */
/*{{{  void ITS_destroy(ItemSet set) */

void ITS_destroy(ItemSet set)
{
  ITS_flush(set);
  free(set);
}

/*}}}  */

/*{{{  static void resize_table(ItemSet set) */

static void resize_table(ItemSet set)
{
  struct _ItemSet newset;
  ItemSetIterator iter;

  ITS_init(&newset, set->size*2);

  ITS_iterator(set, &iter);
  while (ITS_hasNext(&iter)) {
    ITS_add(&newset, ITS_next(&iter));
  }

  ITS_flush(set);
  set->size  = newset.size;
  set->table = newset.table;
  set->list  = newset.list;
  set->items_per_dotsym = newset.items_per_dotsym;
  assert(set->count == newset.count);
}

/*}}}  */

/*{{{  void ITS_add(ItemSet set, Item item) */

void ITS_add(ItemSet set, Item item)
{
  unsigned int hnr;
  ATerm dotsym;
  ItemBucket *bucket;
 
  assert(item != NO_ITEM);

  if (set->count >= (set->size * THRESHOLD_PCT)/100) {
    resize_table(set);
  }

  hnr = HASH(item) % set->size;
  while (set->table[hnr] != NO_ITEM && set->table[hnr] != item) {
    hnr = (hnr + MAGIC_JUMP) % set->size;
  }

  if (set->table[hnr] != item) {
    set->table[hnr] = item;
    set->list[set->count++] = item;
  }

  dotsym = IT_getDotSymbol(item);
  hnr = HASH(dotsym) % set->size;
  while (set->items_per_dotsym[hnr] != NULL
	 && set->items_per_dotsym[hnr]->symbol != dotsym) {
    hnr = (hnr + MAGIC_JUMP) % set->size;
  }

  if (set->items_per_dotsym[hnr] == NULL) {
    bucket = malloc(sizeof(ItemBucket));
    if (!bucket) {
      ATerror("out of memory in ITS_add\n");
    }
    bucket->symbol = dotsym;
    bucket->items = malloc(2*sizeof(Item));
    if (!bucket->items) {
      ATerror("out of memory in ITS_add 2\n");
    }
    bucket->items[0] = item;
    bucket->items[1] = NO_ITEM;
    bucket->size     = 1;
    set->items_per_dotsym[hnr] = bucket;
  } else {
    bucket = set->items_per_dotsym[hnr];
    bucket->items = (Item *)realloc(bucket->items, (bucket->size+2)*sizeof(Item));
    if (!bucket->items) {
      ATerror("out of memory in ITS_add 3\n");
    }
    bucket->items[bucket->size++] = item;
    bucket->items[bucket->size]   = NO_ITEM;
  }
}

/*}}}  */
/*{{{  ATbool  ITS_contains(ItemSet set, Item item) */

ATbool  ITS_contains(ItemSet set, Item item)
{
  unsigned int hnr;
 
  assert(item != NO_ITEM);

  hnr = HASH(item) % set->size;
  while (set->table[hnr] != NO_ITEM && set->table[hnr] != item) {
    hnr = (hnr + MAGIC_JUMP) % set->size;
  }

  return set->table[hnr] == item;
}

/*}}}  */
/*{{{  int ITS_size(ItemSet set) */

int ITS_size(ItemSet set)
{
  return set->count;
}

/*}}}  */

/*{{{  void ITS_iterator(ItemSet set, ItemSetIterator *iterator) */

void ITS_iterator(ItemSet set, ItemSetIterator *iterator)
{
  *iterator = &set->list[0];
}

/*}}}  */
/*{{{  void ITS_iteratorPerDotSym(ItemSet set, ATerm dotsym, ItemSetIterator *iterator) */

void ITS_iteratorPerDotSym(ItemSet set, ATerm dotsym, ItemSetIterator *iterator)
{
  unsigned int hnr;
  static Item empty[1] = { NO_ITEM };

  hnr = HASH(dotsym) % set->size;
  while (set->items_per_dotsym[hnr] != NULL
	 && set->items_per_dotsym[hnr]->symbol != dotsym) {
    hnr = (hnr + MAGIC_JUMP) % set->size;
  }

  if (set->items_per_dotsym[hnr] != NULL) {
    *iterator = &(set->items_per_dotsym[hnr]->items[0]);
  } else {
    *iterator = &empty[0];
  }
}

/*}}}  */

#if 0
/*{{{  Item ITS_next(ItemSetIterator iterator) */

Item ITS_next(ItemSetIterator *iterator)
{
  return *((*iterator)++);
}

/*}}}  */
/*{{{  ATbool ITS_hasNext(ItemSetIterator *iterator) */

ATbool ITS_hasNext(ItemSetIterator *iterator)
{
  return **iterator != NO_ITEM;
}

/*}}}  */
#endif


