/* $Id$ */

#ifndef ITEMSET_H
#define ITEMSET_H

#include <aterm1.h>
#include <MEPT.h>
#include "item.h"

typedef struct _ItemSet *ItemSet;
typedef Item *ItemSetIterator;

ItemSet ITS_create();
void    ITS_destroy(ItemSet set);
void    ITS_add(ItemSet set, Item item);
ATbool  ITS_contains(ItemSet set, Item item);
int     ITS_size(ItemSet set);

void ITS_iterator(ItemSet set, ItemSetIterator *iterator);
void ITS_iteratorPerDotSym(ItemSet set, PT_Symbol dotsym, ItemSetIterator *iterator);

/*
Item ITS_next(ItemSetIterator *iterator);
ATbool ITS_hasNext(ItemSetIterator *iterator);
*/

#define ITS_next(iter) (*((*(iter))++))
#define ITS_hasNext(iter) (**(iter) != NO_ITEM)

#endif
