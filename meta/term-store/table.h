#ifndef TABLE_H
#define TABLE_H

#include <aterm2.h>

typedef ATermTable Table;

Table     T_createTable();
void      T_destroyTable(Table table);

void      T_putValue(Table table, ATerm key, ATerm value);
ATerm     T_getValue(Table table, ATerm key);
void      T_removeValue(Table table, ATerm key);
ATbool    T_containsKey(Table table, ATerm key);
ATermList T_getAllKeys(Table table);
ATermList T_getAllValues(Table table);
ATermList T_getValues(Table table, ATermList keys);
ATermList T_getAllKeyValuePairs(Table table);
#endif
