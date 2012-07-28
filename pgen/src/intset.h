#ifndef __INTSET_H
#define __INTSET_H

typedef unsigned long *IS_IntSet;

IS_IntSet IS_create(int max_int);
void IS_destroy(IS_IntSet set);
void IS_flush(IS_IntSet set, int max_int);
int  IS_add(IS_IntSet set, int i);
void IS_remove(IS_IntSet set, int i);
int  IS_contains(IS_IntSet set, int i);

#endif
