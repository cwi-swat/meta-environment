#ifndef TABLE_H
#define TABLE_H

#include <aterm2.h>

typedef ATermTable Table;

Table createTable();
void destroyTable(Table table);

void      putValue(Table table, ATerm key, ATermList value);
ATermList getValue(Table table, ATerm key);
void      removeValue(Table table, ATerm key);
ATbool    containsKey(Table table, ATerm key);
ATermList getAllKeys(Table table);

#endif
