#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <atb-tool.h>
#include <assert.h>

#include "table-store.h"

#ifndef streq
#define streq(s1,s2) (strcmp(s1,s2) == 0)
#endif

#define NO_SUCH_TABLE    -1
#define MAX_NR_OF_TABLES 100

typedef struct _table_entry_struct {
  char *name;
  char *valueType;
  Table table;
} TableEntry;

static TableEntry* tableStore = NULL;

/*{{{  void TS_initTableStore()  */

void TS_initTableStore() 
{
  if (tableStore == NULL) {
    tableStore = (TableEntry*) calloc(MAX_NR_OF_TABLES,
                                      sizeof(TableEntry));

    if (tableStore == NULL) {
      ATabort("initTableStore: out of memory\n");
    }
  }
}

/*}}}  */
/*{{{  static int TS_findTable(char *name) */

static int TS_findTable(char *name)
{
  int i;

  for (i = 0; i < MAX_NR_OF_TABLES; i++) {
    if (tableStore[i].name != NULL &&
        streq(tableStore[i].name, name)) {
      return i;
    }
  }

  return NO_SUCH_TABLE;
}

/*}}}  */
/*{{{  char* TS_getTableValueType(char *name) */

char* TS_getTableValueType(char *name)
{
  return tableStore[TS_findTable(name)].valueType;
}

/*}}}  */
/*{{{  ATbool TS_tableExists(char *name) */

ATbool TS_tableExists(char *name)
{
  return (TS_findTable(name) != NO_SUCH_TABLE);
}

/*}}}  */
/*{{{  void addTable(char *name, char* valueType) */

void addTable(char *name, char* valueType)
{
  int i;

  if (!TS_tableExists(name)) {
    for (i = 0; i < MAX_NR_OF_TABLES; i++) {
      if (tableStore[i].name == NULL) {
	tableStore[i].name = strdup(name);
	tableStore[i].valueType = strdup(valueType);
	tableStore[i].table = T_createTable();
	return;
      }
    }
  }
  else {
    if (!streq(tableStore[TS_findTable(name)].valueType,valueType)) {
      ATwarning("WARNING: Table %s already exists with different "
		"value type than %s\n", name, valueType);
    }

    return;
  }

  ATabort("addTable: table store exhausted.\n");
}  

/*}}}  */
/*{{{  void TS_addTable(char *name, char* valueType) */

void TS_addTable(char *name, char* valueType)
{
  if (!TS_tableExists(name)) {
    addTable(name, valueType);
  }
  else {
    ATwarning("addTable: table %s already exists.\n", name);
  }
}  

/*}}}  */
/*{{{  void TS_removeTable(char *name) */

void TS_removeTable(char *name)
{
  int i;

  i = TS_findTable(name);

  if (i != NO_SUCH_TABLE) {
    free(tableStore[i].name);
    tableStore[i].name = NULL;
    T_destroyTable(tableStore[i].table);
    tableStore[i].table = NULL;
  }
  else {
    ATwarning("removeTable: table %s does not exist.\n", name);
  }
}

/*}}}  */
/*{{{  Table TS_getTable(char *name) */

Table TS_getTable(char *name)
{
  int i;

  i = TS_findTable(name);

  if (i != NO_SUCH_TABLE) {
    return tableStore[i].table;
  }
  else {
    ATwarning("getTable: table %s does not exist.\n", name);
    return NULL;
  }
}

/*}}}  */
/*{{{  void TS_clearTable(char *name) */

void TS_clearTable(char *name)
{
  char *valueType = strdup(TS_getTableValueType(name));

  TS_removeTable(name);
  TS_addTable(name, valueType);

  free(valueType);
}

/*}}}  */
/*{{{  void TS_removeValueFromAllTables(ATerm key) */

void TS_removeValueFromAllTables(ATerm key)
{
  int i;

  for(i = 0; i < MAX_NR_OF_TABLES; i++) {
    if (tableStore[i].name != NULL) {
      T_removeValue(tableStore[i].table, key);
    }
  }
}

/*}}}  */
/*{{{  void TS_putValue(char* name, ATerm key, ATermList value) */

void TS_putValue(char* name, ATerm key, ATerm value)
{
  Table table = TS_getTable(name);

  if (table != NULL) {
    T_putValue(table, key, value);
  }
}

/*}}}  */
/*{{{  ATermList TS_getValue(char* name, ATerm key) */

ATerm TS_getValue(char* name, ATerm key)
{
  Table table = TS_getTable(name);

  if (table != NULL) {
    return T_getValue(table, key);
  }

  return NULL;
}

/*}}}  */
/*{{{  void TS_removeValue(char* name, ATerm key) */

void TS_removeValue(char* name, ATerm key)
{
  Table table = TS_getTable(name);

  if (table != NULL) {
    return T_removeValue(table, key);
  }
}

/*}}}  */
/*{{{  ATbool    TS_containsKey(char* name, ATerm key) */

ATbool    TS_containsKey(char* name, ATerm key)
{
  Table table = TS_getTable(name);

  if (table != NULL) {
    return T_containsKey(table, key);
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATermList TS_getAllKeys(char* name) */

ATermList TS_getAllKeys(char* name)
{
  Table table = TS_getTable(name);

  if (table != NULL) {
    return T_getAllKeys(table);
  }

  return ATempty;
}

/*}}}  */
/*{{{  ATermList TS_getAllValues(char* name) */

ATermList TS_getAllValues(char* name)
{
  Table table = TS_getTable(name);

  if (table != NULL) {
    return T_getAllValues(table);
  }

  return ATempty;
}

/*}}}  */
/*{{{  ATermList TS_getValues(char* name, ATermList keys) */

ATermList TS_getValues(char* name, ATermList keys)
{
  Table table = TS_getTable(name);

  if (table != NULL) {
    return T_getValues(table, keys);
  }

  return ATempty;
}

/*}}}  */
/*{{{  ATermList TS_getAllKeyValuePairs(char *table) */

ATermList TS_getAllKeyValuePairs(char *table)
{
  Table t = TS_getTable(table);

  if (table != NULL) {
    return T_getAllKeyValuePairs(t);
  }

  return ATempty;
}

/*}}}  */
/*{{{  ATermList TS_filterKeys(char *name, ATermList keysList) */

ATermList TS_filterKeys(char *table, ATermList keysList)
{
  ATerm key;
  ATermList unknownKeys = ATempty;
   
  while (!ATisEmpty(keysList)) {
    key = ATgetFirst(keysList);
	   
    if (!TS_containsKey(table,key)) {
      unknownKeys = ATinsert(unknownKeys, key);
    }

    keysList = ATgetNext(keysList);
  }
     
  return unknownKeys;
}

/*}}}  */

/*{{{  SS_Table getTableSnapshot(Table table) */

SS_Table getTableSnapshot(TableEntry table)
{
  ATermList pairs = T_getAllKeyValuePairs(table.table);
  SS_Rows rows = SS_makeRowsEmpty();
 
  for( ;!ATisEmpty(pairs); pairs = ATgetNext(pairs)) {
    ATerm pair = ATgetFirst(pairs);
    ATerm key = ATgetFirst((ATermList) pair);
    ATerm value = ATgetFirst(ATgetNext((ATermList) pair));
    SS_Row row = SS_makeRowDefault(key,value);
    rows = SS_makeRowsMany(row, rows);
  }

  return SS_makeTableDefault(table.name, table.valueType, rows); 
}

/*}}}  */
/*{{{  SS_Snapshot TS_getSnapshot() */

ATerm TS_getSnapshot()
{
  int i;
  SS_Tables tables = SS_makeTablesEmpty(); 

  for (i = 0; i < MAX_NR_OF_TABLES; i++) {
    if (tableStore[i].name != NULL) {
      SS_Table tableSnapshot = getTableSnapshot(tableStore[i]);

      if (tableSnapshot != NULL) {
	tables = SS_makeTablesMany(tableSnapshot, tables);
      }
    }
  }

  return SS_SnapshotToTerm(SS_makeSnapshotMain(tables));
}

/*}}}  */

/*{{{  void loadTable(SS_Table table) */

void loadTable(SS_Table table)
{
  char *name = SS_getTableName(table);
  char *valueType = SS_getTableValueType(table);
  SS_Rows rows = SS_getTableRows(table);

  if (TS_tableExists(name)) {
    addTable(name, valueType);

    for (; !SS_isRowsEmpty(rows); rows = SS_getRowsTail(rows)) {
      SS_Row row = SS_getRowsHead(rows);
      ATerm key = SS_getRowKey(row);
      ATerm value = SS_getRowValue(row);

      TS_putValue(name, key, value);
    }
  }
  else {
    ATwarning("Table %s does not exist, contents not loaded!\n", name);
  }
}

/*}}}  */
/*{{{  void loadTables(SS_Tables tables) */

void loadTables(SS_Tables tables)
{
  for (; !SS_isTablesEmpty(tables); tables = SS_getTablesTail(tables)) {
    SS_Table table = SS_getTablesHead(tables);
    loadTable(table);
  }
}

/*}}}  */
/*{{{  void TS_loadSnapshot(ATerm s) */

void TS_loadSnapshot(ATerm s)
{
  SS_Snapshot snapshot = SS_SnapshotFromTerm(ATBunpack(s));
  SS_Tables tables;

  if (!SS_isValidSnapshot(snapshot)) {
    ATwarning("TS_loadSnapshot: Invalid snapshot ignored\n");
    return;
  }

  tables = SS_getSnapshotTables(snapshot);

  loadTables(tables);
}

/*}}}  */
