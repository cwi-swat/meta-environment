
#include "table-store.h"
#include "table.h"
#include <SDFME.h>

#define makeTextValue(text)  ((ATermList) ATmakeList1(makeString(text)))
#define getTextValue(value) ((ATerm) ATgetFirst(value))
#define makePathValue(text)  ((ATermList) ATmakeList1(makeString(text)))
#define getPathValue(value) ((ATerm) ATgetFirst(value))
#define makeTreeValue(tree)  ((ATermList) ATmakeList1((ATerm) tree))
#define getTreeValue(value) ((ATerm) ATgetFirst(value))
#define makeParseTableValue(table)  ((ATermList) ATmakeList1(table))
#define getParseTableValue(value) ((ATerm) ATgetFirst(value))


void MS_initModuleStore()
{
  TS_initTableStore();
  TS_addTable("active-modules");
  TS_addTable("module-paths");
  TS_addTable("sdf-tree");
  TS_addTable("sdf-text");
  TS_addTable("asf-tree");
  TS_addTable("asf-text");
  TS_addTable("asf-parse-table");
  TS_addTable("term-parse-table");
}

void MS_destroyModuleStore()
{
  TS_removeTable("active-modules");
  TS_removeTable("module-paths");
  TS_removeTable("sdf-tree");
  TS_removeTable("sdf-text");
  TS_removeTable("asf-tree");
  TS_removeTable("asf-text");
  TS_removeTable("asf-parse-table");
  TS_removeTable("term-parse-table");
}

void MS_clearModuleStore()
{
  MS_destroyModuleStore();
  MS_initModuleStore();
}

ATbool MS_existsModule(ATerm moduleName)
{
  return TS_containsKey("active-modules", moduleName);
}

void MS_putModuleName(ATerm moduleName)
{
  TS_putValue("active-modules",  moduleName, ATempty);
}

void MS_removeModuleName(ATerm moduleName)
{
  TS_removeValue("active-modules", moduleName);
}

ATermList MS_getActiveModules()
{
  return TS_getAllKeys("active-modules");
}

char* MS_getModulePath(ATerm moduleName)
{
  ATermList value = TS_getValue("module-paths", moduleName);

  if (value) {
    return getString(getPathValue(value));
  }
  return NULL;
}

void MS_putModulePath(ATerm moduleName, char *path)
{
  TS_putValue("module-paths", moduleName, makePathValue(path));
}

void MS_removeModulePath(ATerm moduleName)
{
  TS_removeValue("module-paths", moduleName);
}

ATerm MS_getSdfTree(ATerm moduleName)
{
  ATermList value = TS_getValue("sdf-tree", moduleName);

  if (value) {
    return getTreeValue(value);
  }
  return NULL;
}

void MS_putSdfTree(ATerm moduleName, ATerm moduleTree)
{
  TS_putValue("sdf-tree",  moduleName, 
	      makeTreeValue(moduleTree));
}

void MS_removeSdfTree(ATerm moduleName)
{
  TS_removeValue("sdf-tree", moduleName);
}

void MS_putSdfText(ATerm moduleName, char *text)
{
  TS_putValue("sdf-text",  moduleName, makeTextValue(text));
}

void MS_putAsfTree(ATerm moduleName, ATerm tree)
{
  TS_putValue("asf-tree",  moduleName, makeTreeValue(tree));
}

void MS_removeAsfTree(ATerm moduleName)
{
  TS_removeValue("asf-tree",  moduleName);
}

ATerm MS_getAsfTree(ATerm moduleName)
{
  ATermList value = TS_getValue("asf-tree", moduleName);

  if (value) {
    return getTreeValue(value);
  }
  return NULL;
}

void MS_putAsfText(ATerm moduleName, char *text)
{
  TS_putValue("asf-text",  moduleName, makeTextValue(text));
}

ATerm MS_getAsfTextValue(ATerm moduleName)
{
  return (ATerm)TS_getValue("asf-text", moduleName);
}

char* MS_getAsfTextText(ATerm moduleName)
{
  ATermList value = TS_getValue("asf-text", moduleName);
  if (value) {
    return getString(getTextValue(value));
  }
  return NULL;
}

void MS_putAsfParseTable(ATerm moduleName, ATerm table)
{
  TS_putValue("asf-parse-table", moduleName,
              makeParseTableValue(table)); 
}

void MS_removeAsfParseTable(ATerm moduleName)
{
  TS_removeValue("asf-parse-table",  moduleName);
}

void MS_putTermParseTable(ATerm moduleName, ATerm table)
{
  TS_putValue("term-parse-table", moduleName,
              makeParseTableValue(table)); 
}

void MS_removeTermParseTable(ATerm moduleName)
{
  TS_removeValue("term-parse-table",  moduleName);
}

ATerm MS_getAsfParseTable(ATerm moduleName)
{
  ATermList value = TS_getValue("asf-parse-table", moduleName);

  if (value) {
    return getParseTableValue(value);
  }
  return NULL;
}

ATerm MS_getTermParseTable(ATerm moduleName)
{
  ATermList value = TS_getValue("term-parse-table", moduleName);
  if (value) {
    return getParseTableValue(value);
  }
  return NULL;
}
