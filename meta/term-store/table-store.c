#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "table-store.h"

#ifndef streq
#define streq(s1,s2) (strcmp(s1,s2) == 0)
#endif

#define NO_SUCH_TABLE    -1
#define MAX_NR_OF_TABLES 100

typedef struct _table_entry_struct {
  char *name;
  Table table;
} TableEntry;

static TableEntry* tableStore = NULL;

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

ATbool TS_tableExists(char *name)
{
  return (TS_findTable(name) != NO_SUCH_TABLE);
}

void TS_addTable(char *name)
{
  int i;
  
  if (!TS_tableExists(name)) {
    for (i = 0; i < MAX_NR_OF_TABLES; i++) {
      if (tableStore[i].name == NULL) {
        tableStore[i].name = strdup(name);
        tableStore[i].table = T_createTable();
        return;
      }
    }

    ATabort("addTable: table store exhausted.\n");
  }
  else {
    ATwarning("addTable: table %s already exists.\n", name);
  }
}  

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

void TS_clearTable(char *name)
{
  TS_removeTable(name);
  TS_addTable(name);
}

void TS_removeValueFromAllTables(ATerm key)
{
  int i;

  for(i = 0; i < MAX_NR_OF_TABLES; i++) {
    if (tableStore[i].name != NULL) {
      T_removeValue(tableStore[i].table, key);
    }
  }
}

void TS_putValue(char* name, ATerm key, ATermList value)
{
  Table table = TS_getTable(name);

  if (table != NULL) {
    T_putValue(table, key, value);
  }
}

ATermList TS_getValue(char* name, ATerm key)
{
  Table table = TS_getTable(name);

  if (table != NULL) {
    return T_getValue(table, key);
  }

  return NULL;
}

void TS_removeValue(char* name, ATerm key)
{
  Table table = TS_getTable(name);

  if (table != NULL) {
    return T_removeValue(table, key);
  }
}

ATbool    TS_containsKey(char* name, ATerm key)
{
  Table table = TS_getTable(name);

  if (table != NULL) {
    return T_containsKey(table, key);
  }

  return ATfalse;
}

ATermList TS_getAllKeys(char* name)
{
  Table table = TS_getTable(name);

  if (table != NULL) {
    return T_getAllKeys(table);
  }

  return ATempty;
}
