
#include "table-store.h"
#include "table.h"

void initModuleStore()
{
  initTableStore();
  addTable("active-modules");
  addTable("imports-transitive");
  addTable("sdf-tree");
  addTable("sdf-text");
  addTable("asf-tree");
  addTable("asf-text");
  addTable("asf-table");
  addTable("term-table");
}

void destroyModuleStore()
{
  removeTable("active-modules");
  removeTable("transitive-imports");
  removeTable("sdf-tree");
  removeTable("sdf-text");
  removeTable("asf-tree");
  removeTable("asf-text");
  removeTable("asf-table");
  removeTable("term-table");
}

void clearModuleStore()
{
  destroyModuleStore();
  initModuleStore();
}

void clearTransitiveImports()
{
  clearTable("transitive-imports");
}

static ATerm makeKeyFromModuleName(char *moduleName)
{
  return ATmake("<str>", moduleName);
}

ATbool moduleExists(char *moduleName)
{
  return containsKey(getTable("active-modules"),
                     makeKeyFromModuleName(moduleName));
}

ATermList getTransitiveImports(char *moduleName) 
{
  return getValue(getTable("transitive-imports"),
                  makeKeyFromModuleName(moduleName));
}

SDF_Module getSdfTree(char *moduleName)
{
  return getValue(getTable("sdf-tree"),
                  makeKeyFromModuleName(moduleName));
}

void storeValueInTable(char *moduleName, char *tableName, ATermList value)
{
  ATermList value = ATmakeList1(SDF_ModuleToTerm(moduleTree));
  putValue(getTable("sdf-tree"), moduleName, value);
}

void addSdfText(char *moduleName, char *text, char *path, int timeStamp)
{
  ATermList value = ATmakeList3(text, path, timeStamp);
  putValue(getTable("sdf-tree"), moduleName, value);
}

void addAsfTree(char *moduleName, SDF_Module moduleTree)
{
  ATermList value = ATmakeList1(SDF_ModuleToTerm(moduleTree));
  putValue(getTable("sdf-tree"), moduleName, value);
}

