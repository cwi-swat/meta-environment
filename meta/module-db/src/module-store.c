
#include "table-store.h"
#include "table.h"
#include <SDFME.h>

#define makeTextValue(text,path,timeStamp)  ((ATermList) ATmakeList3(makeString(text),makeString(path),(ATerm) ATmakeInt(timeStamp)))
#define getTextValuePath(value) ((ATerm) ATgetFirst(ATgetNext(value)))
#define getTextValueText(value) ((ATerm) ATgetFirst(value))
#define makeTreeValue(tree)  ((ATermList) ATmakeList1((ATerm) tree))
#define getTreeValue(value) ((ATerm) ATgetFirst(value))
#define makeParseTableValue(table,timeStamp)  ((ATermList) ATmakeList2(table,(ATerm) ATmakeInt(timeStamp)))
#define getParseTableValueTable(value) ((ATerm) ATgetFirst(value))
#define getParseTableValueTimeStamp(value) ((ATerm) ATgetFirst(ATgetNext(value)))


void MS_initModuleStore()
{
  TS_initTableStore();
  TS_addTable("active-modules");
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

ATerm MS_getSdfTree(ATerm moduleName)
{
  return getTreeValue(TS_getValue("sdf-tree", moduleName));
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

void MS_putSdfText(ATerm moduleName, char *text, char *path, int timeStamp)
{
  TS_putValue("sdf-text",  moduleName, 
              makeTextValue(text,path,timeStamp));
}

char* MS_getSdfTextPath(ATerm moduleName)
{
  ATerm value = getTextValuePath(
                  TS_getValue("sdf-text", moduleName));
  return getString(value);
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

void MS_putAsfText(ATerm moduleName, char *text, char *path, int timeStamp)
{
  TS_putValue("asf-text",  moduleName,
              makeTextValue(text,path,timeStamp)); 
}

ATerm MS_getAsfTextValue(ATerm moduleName)
{
  return (ATerm)TS_getValue("asf-text", moduleName);
}

char* MS_getAsfTextPath(ATerm moduleName)
{
  ATermList value = TS_getValue("asf-text", moduleName);
  if (value) {
    return getString(getTextValuePath(value));
  }
  return NULL;
}

char* MS_getAsfTextText(ATerm moduleName)
{
  ATermList value = TS_getValue("asf-text", moduleName);
  if (value) {
    return getString(getTextValueText(value));
  }
  return NULL;
}

void MS_putAsfParseTable(ATerm moduleName, ATerm table, 
                         int timeStamp)
{
  TS_putValue("asf-parse-table", moduleName,
              makeParseTableValue(table,timeStamp)); 
}

void MS_removeAsfParseTable(ATerm moduleName)
{
  TS_removeValue("asf-parse-table",  moduleName);
}

void MS_putTermParseTable(ATerm moduleName, ATerm table, 
                         int timeStamp)
{
  TS_putValue("term-parse-table", moduleName,
              makeParseTableValue(table,timeStamp)); 
}

void MS_removeTermParseTable(ATerm moduleName)
{
  TS_removeValue("term-parse-table",  moduleName);
}

ATerm MS_getAsfParseTable(ATerm moduleName)
{
  ATermList value = TS_getValue("asf-parse-table", moduleName);

  if (value) {
    return getParseTableValueTable(value);
  }
  return NULL;
}

ATerm MS_getTermParseTable(ATerm moduleName)
{
  ATermList value = TS_getValue("term-parse-table", moduleName);
  if (value) {
    return getParseTableValueTable(value);
  }
  return NULL;
}
