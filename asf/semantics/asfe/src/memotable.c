/* memotable.c
 *
 * Data structure for memoization of terms and normal forms
 *
 * $Id$
 */

#include "memotable.h"

/* Standard properties of the memo table */
#define MemoTableInitialSize 1000
#define MemoTableMaxLoadPercentage 70

MemoTable MemoTableCreate(void)
{
  ATermTable table =
    ATtableCreate(MemoTableInitialSize, MemoTableMaxLoadPercentage);

  return (MemoTable) table;
}

MemoTable MemoTableClear(MemoTable table)
{
  ATermTable t = (ATermTable) table;
  ATermList keys = ATtableKeys(t);

  for (; !ATisEmpty(keys); keys = ATgetNext(keys)) {
    ATtableRemove(t, ATgetFirst(keys));
  }

  return (MemoTable) t;
}

void
MemoTableDestroy(MemoTable table)
{
  ATtableDestroy((ATermTable) table);

  return;
}

MemoTable MemoTableAdd(MemoTable table, PT_Tree term, PT_Tree normalform)
{
  ATermTable t = (ATermTable) table;

  ATtablePut(t, (ATerm) term, (ATerm) normalform);

  return (MemoTable) t;
}

PT_Tree MemoTableLookup(MemoTable table, PT_Tree term)
{
  ATermTable t = (ATermTable) table;
  ATerm normalform = ATtableGet(t, (ATerm) term);

  return (PT_Tree) normalform;
}
