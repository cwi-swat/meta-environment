/*
 $Id$
 */   

#ifndef MULTISETS_H
#define MULTISETS_H

#include <aterm2.h>

typedef int *MultiSet;
  
typedef struct _MultiSetTable
{
  int max_size;
  ATermIndexedSet table;
  MultiSet *sets;
} *MultiSetTable;

MultiSetTable MultiSetTableCreate(int max_size);
void MultiSetTableDestroy(MultiSetTable table);
void MultiSetTablePut(MultiSetTable table, ATerm tree, MultiSet set);
MultiSet MultiSetTableGet(MultiSetTable table, ATerm tree);

MultiSet MultiSetCreate(int size);
void MultiSetDestroy(MultiSet set);
void MultiSetIncrease(MultiSet set, int index);
void MultiSetMerge(MultiSet set1, MultiSet set2);
int MultiSetGetCount(MultiSet set, int index);
void MultiSetPrint(FILE *file, MultiSet set);
ATbool MultiSetEqual(MultiSet set1, MultiSet set2);
int MultiSetGetSize(MultiSet set);

#endif
