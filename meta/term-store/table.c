#include "table.h"

#define TABLE_SIZE 100
#define TABLE_RESIZE_QUOTIENT 75

/*{{{  Table T_createTable() */

Table T_createTable()
{
  return (Table)ATtableCreate(TABLE_SIZE, TABLE_RESIZE_QUOTIENT);
}

/*}}}  */
/*{{{  void T_destroyTable(Table table) */

void T_destroyTable(Table table)
{
  if (table != NULL) {
    ATtableDestroy((ATermTable)table);
  }
}

/*}}}  */
/*{{{  void T_putValue(Table table, ATerm key, ATermList value) */

void T_putValue(Table table, ATerm key, ATerm value)
{
  ATtablePut((ATermTable)table, key, (ATerm)value);
}

/*}}}  */
/*{{{  ATermList T_getValue(Table table, ATerm key) */

ATerm T_getValue(Table table, ATerm key)
{
  return ATtableGet((ATermTable)table, key);
}

/*}}}  */
/*{{{  void T_removeValue(Table table, ATerm key) */

void T_removeValue(Table table, ATerm key)
{
  ATtableRemove((ATermTable) table, key);
}

/*}}}  */
/*{{{  ATbool T_containsKey(Table table, ATerm key) */

ATbool T_containsKey(Table table, ATerm key)
{
  return (T_getValue(table, key) != NULL);
}

/*}}}  */
/*{{{  ATermList T_getAllKeys(Table table) */

ATermList T_getAllKeys(Table table)
{
  return ATtableKeys((ATermTable)table);
}

/*}}}  */
/*{{{  ATermList T_getAllValues(Table table) */

ATermList T_getAllValues(Table table)
{
  return ATtableValues((ATermTable)table);
}

/*}}}  */
ATermList T_getValues(Table table, ATermList keys)
{
  ATermList values = ATempty;

  for ( ;!ATisEmpty(keys); keys = ATgetNext(keys)) {
    ATerm key = ATgetFirst(keys);
    ATerm value = T_getValue(table, key);
    
    if (value != NULL) {
      values = ATinsert(values, value);
    }
  }

  return values;
}
/*{{{  ATermList T_getAllKeyValuePairs(Table table) */

ATermList T_getAllKeyValuePairs(Table table)
{
  ATermList keys = T_getAllKeys(table);
  ATermList pairs;

  for (pairs = ATempty; !ATisEmpty(keys); keys = ATgetNext(keys)) {
    ATerm key = ATgetFirst(keys);
    ATerm value = T_getValue(table, key);
    ATermList pair = ATmakeList2(key, value);

    pairs = ATinsert(pairs, (ATerm) pair);
  }

  return pairs;
}

/*}}}  */
