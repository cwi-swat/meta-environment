/*

    SGLR - the Scannerless Generalized LR parser.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam,
                        The Netherlands.
                                                                                    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
/*
 $Id$
 */   

#include <stdlib.h>
#include <assert.h>

#include "multisets.h"

/*{{{  MultiSetTable MultiSetTableCreate(int max_size) */

MultiSetTable MultiSetTableCreate(int max_size)
{
  MultiSetTable table;

  table = (MultiSetTable)calloc(1, sizeof(struct _MultiSetTable));
  if (!table) {
    ATerror("out of memory in MultiSetTableCreate\n");
  }

  table->max_size = max_size;
  table->sets     = (MultiSet *)calloc(max_size, sizeof(MultiSet));
  if (!table->sets) {
    ATerror("out of memory in MultiSetTableCreate\n");
  }

  table->table = ATindexedSetCreate(max_size, 80);

  return table;
}

/*}}}  */
/*{{{  void MultiSetTableDestroy(MultiSetTable table) */

void MultiSetTableDestroy(MultiSetTable table)
{
  int i;

  ATindexedSetDestroy(table->table);

  for (i=0; i<table->max_size; i++) {
    if (table->sets[i]) {
      MultiSetDestroy(table->sets[i]);
    }
  }
  free(table->sets);
  free(table);
}

/*}}}  */
/*{{{  void MultiSetTablePut(MultiSetTable table, ATerm tree, MultiSet set) */

void MultiSetTablePut(MultiSetTable table, ATerm tree, MultiSet set)
{
  ATbool isnew;
  long index;
  
  index = ATindexedSetPut(table->table, tree, &isnew);
 
  assert(isnew);
  assert(!table->sets[index]);
  assert(index < table->max_size);

  table->sets[index] = set;
}

/*}}}  */
/*{{{  MultiSet MultiSetTableGet(MultiSetTable table, ATerm tree) */

MultiSet MultiSetTableGet(MultiSetTable table, ATerm tree)
{
  long index = ATindexedSetGetIndex(table->table, tree);

  if (index < 0) {
    return NULL;
  }

  return table->sets[index];
}

/*}}}  */

/*{{{  MultiSet MultiSetCreate(int size) */

MultiSet MultiSetCreate(int size)
{
  MultiSet set;

  set = (MultiSet)calloc(size+1, sizeof(int));
  if (!set) {
    ATerror("out of memory in MultiSetCreate\n");
  }

  set[0] = size;

  return set;
}

/*}}}  */

ATbool MultiSetEqual(MultiSet set1, MultiSet set2)
{
  int i;
  assert(set1 && set2);
  assert(set1[0] == set2[0]);

  for(i = set1[0]; i > 0; i--) {
    if(set1[i] != set2[i]) {
      return ATfalse;
    }
  }

  return ATtrue;  
}

int MultiSetGetSize(MultiSet set)
{
  return set[0];
}

/*{{{  void MultiSetDestroy(MultiSet set) */

void MultiSetDestroy(MultiSet set)
{
  free(set);
}

/*}}}  */
/*{{{  void MultiSetIncrease(MultiSet set, int index) */

void MultiSetIncrease(MultiSet set, int index)
{
  set[index+1]++;
}

/*}}}  */
/*{{{  void MultiSetMerge(MultiSet set1, MultiSet set2) */

void MultiSetMerge(MultiSet set1, MultiSet set2)
{
  int i;

  assert(set1[0] == set2[0]);

  for (i=set1[0]; i>0; i--) {
    set1[i] += set2[i];
  }
}

/*}}}  */
/*{{{  int MultiSetGetCount(MultiSet set, int index) */

int MultiSetGetCount(MultiSet set, int index)
{
  return set[index+1];
}

/*}}}  */

void MultiSetPrint(FILE *file, MultiSet set)
{
  int count, i;
  ATbool isfirst;

  fprintf(file, "{ ");

  isfirst = ATtrue;
  for (i=0; i<set[0]; i++) {
    count = MultiSetGetCount(set, i);
    if (count > 0) {
      if (isfirst) {
	isfirst = ATfalse;
      } else {
	fprintf(file, ", ");
      }
      fprintf(file, "%d:%d", i+257, count);
    }
  }
  fprintf(file, " }");
}

#ifdef TEST
#define MAX_NUMBER 100
#define MAX_PRIME  29

void storePrimes(MultiSet set, int n, int max_prime)
{
  int posprime, divider, m;
  ATbool isprime;

  for (posprime=2; posprime<=n; posprime++) {
    if ((n/posprime)*posprime == n) {
      /* Alright, posprime divides n, so make sure it is prime! */
      isprime = ATtrue;
      for (divider=2; divider<posprime; divider++) {
	if ((posprime/divider)*divider == posprime) {
	  isprime = ATfalse;
	  break;
	}
      }
      if (isprime) {
	m = n;
	while ((m/posprime)*posprime == m) {
	  MultiSetIncrease(set, posprime);
	  m /= posprime;
	}
      }
    }
  }
}

int main(int argc, char *argv[])
{
  ATerm tree[MAX_NUMBER];
  MultiSet s1, s2, s3, set[MAX_NUMBER];
  MultiSetTable table;
  int n, n1, n2, i;
  ATerm topOfStack;


  ATinit(argc, argv, &topOfStack);

  table = MultiSetTableCreate(MAX_NUMBER+1);
  for (n=1; n<MAX_NUMBER; n++) {
    tree[n] = ATmake("primes(<int>)", n);
    ATprotect(&tree[n]);
    set[n]  = MultiSetCreate(MAX_PRIME+1);
    MultiSetTablePut(table, tree[n], set[n]);
    storePrimes(set[n], n, MAX_PRIME);
    ATfprintf(stderr, "multiset %t = ", tree[n]);
    MultiSetPrint(stderr, set[n]);
    ATfprintf(stderr, "\n");
  }

  /* Check some numbers */
  for (n1=1; n1<MAX_NUMBER; n1++) {
    n2 = n1+1;

    if (n1*n2 <= MAX_NUMBER) {
      s1 = MultiSetTableGet(table, tree[n1]);
      assert(s1 == set[n1]);
      s2 = MultiSetTableGet(table, tree[n2]);
      assert(s2 == set[n2]);
      s3 = set[n1*n2];
      MultiSetMerge(s1, s2);
      for (i=1; i<MAX_PRIME; i++) {
	if (MultiSetGetCount(s1, i) != MultiSetGetCount(s3, i)) {
	  ATfprintf(stderr, "*warning*: multiset %t != multiset %t:\n", tree[n1], tree[n1*n2]);
	  MultiSetPrint(stderr, s1);
	  fprintf(stderr, "\n");
	  MultiSetPrint(stderr, s3);
	  fprintf(stderr, "\n\n");
	}
      }
    }
  }

  return 0;
}
#endif
