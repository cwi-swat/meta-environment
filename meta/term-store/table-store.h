#ifndef TABLE_STORE_H
#define TABLE_STORE_H

#include "table.h"

#define TS_STR_TYPE "str"
#define TS_TERM_TYPE   "term"

/* Table store operations */
void  TS_initTableStore();
void  TS_addTable(char *name, char* valueType);
void  TS_removeTable(char *name);
Table TS_getTable(char *name);
void  TS_clearTable(char *name);
char* TS_getTableValueType(char *name);

/* Table operations */
void      TS_putValue(char* table, ATerm key, ATerm value);
ATerm     TS_getValue(char* table, ATerm key);
void      TS_removeValue(char* table, ATerm key);
void      TS_removeValueFromAllTables(ATerm key);
ATbool    TS_containsKey(char* table, ATerm key);
ATermList TS_getAllKeys(char* table);
ATermList TS_getAllValues(char* table);
ATermList TS_filterKeys(char* table, ATermList keys);

#endif
