#include "table.h"

#define TABLE_SIZE 100
#define TABLE_RESIZE_QUOTIENT 75

Table createTable()
{
  return (Table)ATtableCreate(TABLE_SIZE, TABLE_RESIZE_QUOTIENT);
}

void destroyTable(Table table)
{
  if (table != NULL) {
    ATtableDestroy((ATermTable)table);
  }
}

void putValue(Table table, ATerm key, ATermList value)
{
  ATtablePut((ATermTable)table, key, (ATerm)value);
}

ATermList getValue(Table table, ATerm key)
{
  return (ATermList)ATtableGet((ATermTable)table, key);
}

void removeValue(Table table, ATerm key)
{
  ATtableRemove((ATermTable) table, key);
}

ATermList getAllKeys(Table table)
{
  return ATtableKeys((ATermTable)table);
}
