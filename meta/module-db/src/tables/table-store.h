#ifndef TABLE_STORE_H
#define TABLE_STORE_H

#include "table.h"
#include "term-conversion.h"

/* Table store operations */
void  TS_initTableStore();
void  TS_addTable(char *name);
void  TS_removeTable(char *name);
Table TS_getTable(char *name);
void  TS_clearTable(char *name);

/* Table operations */
void      TS_putValue(char* table, ATerm key, ATermList value);
ATermList TS_getValue(char* table, ATerm key);
void      TS_removeValue(char* table, ATerm key);
void      TS_removeValueFromAllTables(ATerm key);
ATbool    TS_containsKey(char* table, ATerm key);
ATermList TS_getAllKeys(char* table);

#endif
