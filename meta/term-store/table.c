#include "table.h"

#define TABLE_SIZE 100
#define TABLE_RESIZE_QUOTIENT 75

Table T_createTable()
{
  return (Table)ATtableCreate(TABLE_SIZE, TABLE_RESIZE_QUOTIENT);
}

void T_destroyTable(Table table)
{
  if (table != NULL) {
    ATtableDestroy((ATermTable)table);
  }
}

void T_putValue(Table table, ATerm key, ATermList value)
{
  ATtablePut((ATermTable)table, key, (ATerm)value);
}

ATermList T_getValue(Table table, ATerm key)
{
  return (ATermList)ATtableGet((ATermTable)table, key);
}

void T_removeValue(Table table, ATerm key)
{
  ATtableRemove((ATermTable) table, key);
}

ATbool T_containsKey(Table table, ATerm key)
{
  return (T_getValue(table, key) != NULL);
}

ATermList T_getAllKeys(Table table)
{
  return ATtableKeys((ATermTable)table);
}
