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

void initTableStore() 
{
  if (tableStore == NULL) {
    tableStore = (TableEntry*) calloc(MAX_NR_OF_TABLES,
                                      sizeof(TableEntry));

    if (tableStore == NULL) {
      ATabort("initTableStore: out of memory\n");
    }
  }
}

static int findTable(char *name)
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

ATbool tableExists(char *name)
{
  return (findTable(name) != NO_SUCH_TABLE);
}

void addTable(char *name)
{
  int i;
  
  if (!tableExists(name)) {
    for (i = 0; i < MAX_NR_OF_TABLES; i++) {
      if (tableStore[i].name == NULL) {
        tableStore[i].name = strdup(name);
        tableStore[i].table = createTable();
        return;
      }
    }

    ATabort("addTable: table store exhausted.\n");
  }
  else {
    ATwarning("addTable: table %s already exists.\n", name);
  }
}  

void removeTable(char *name)
{
  int i;

  i = findTable(name);

  if (i != NO_SUCH_TABLE) {
    free(tableStore[i].name);
    tableStore[i].name = NULL;
    destroyTable(tableStore[i].table);
    tableStore[i].table = NULL;
  }
  else {
    ATwarning("removeTable: table %s does not exist.\n", name);
  }
}

Table getTable(char *name)
{
  int i;

  i = findTable(name);

  if (i != NO_SUCH_TABLE) {
    return tableStore[i].table;
  }
  else {
    ATwarning("getTable: table %s does not exist.\n", name);
    return NULL;
  }
}

void clearTable(char *name)
{
  removeTable(name);
  addTable(name);
}

void removeFromAllTables(ATerm key)
{
  int i;

  for(i = 0; i < MAX_NR_OF_TABLES; i++) {
    if (tableStore[i].name != NULL) {
      removeValue(tableStore[i].table, key);
    }
  }
}    
