/* memotable.h
 *
 * Data structure for memoization of terms and normal forms
 *
 * $Id$
 */
#ifndef _MEMOTABLE_H
#define _MEMOTABLE_H

#include <aterm2.h>
#include <MEPT.h>

typedef ATermTable MemoTable;

MemoTable MemoTableCreate(void);
MemoTable MemoTableClear(MemoTable table);
void      MemoTableDestroy(MemoTable table);
MemoTable MemoTableAdd(MemoTable table, PT_Tree term, PT_Tree normalform);
PT_Tree   MemoTableLookup(MemoTable table, PT_Tree term);

#endif
