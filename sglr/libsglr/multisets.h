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
