#ifndef TABLE_STORE_H
#define TABLE_STORE_H

#include "table.h"
#include <Snapshot.h>

#define TS_STR_TYPE "str"
#define TS_TERM_TYPE   "term"

/* Table store operations */
void  TS_initTableStore();
void  TS_addTable(const char *name, const char* valueType);
void  TS_removeTable(const char *name);
Table TS_getTable(const char *name);
void  TS_clearTable(const char *name);
char* TS_getTableValueType(const char *name);

/* Table operations */
void      TS_putValue(const char* table, ATerm key, ATerm value);
ATerm     TS_getValue(const char* table, ATerm key);
ATbool    TS_removeValue(const char* table, ATerm key);
ATermList TS_removeValueFromAllTables(ATerm key);
ATbool    TS_containsKey(const char* table, ATerm key);
ATermList TS_getAllKeys(const char* table);
ATermList TS_getAllValues(const char* table);
ATermList TS_getValues(const char* table, ATermList keys);
ATermList TS_getAllKeyValuePairs(const char *table);
ATermList TS_getTableNames(void);
ATermList TS_filterKeys(const char* table, ATermList keys);
ATerm     TS_getSnapshot();
void      TS_loadSnapshot(ATerm snapshot);

#endif
