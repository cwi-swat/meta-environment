
#include "table-store.h"
#include "table.h"
#include <SDFME.h>

#define makeTextValue(text,path,timeStamp)  ((ATermList) ATmakeList3(makeString(text),makeString(path),(ATerm) ATmakeInt(timeStamp)))
#define getTextValuePath(value) ((ATerm) ATgetFirst(ATgetNext(value)))
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

void MS_putAsfTree(ATerm moduleName, SDF_Module moduleTree)
{
  TS_putValue("asf-tree",  moduleName, 
              makeTreeValue(moduleTree));
}

void MS_putAsfText(ATerm moduleName, char *text, char *path, int timeStamp)
{
  TS_putValue("asf-text",  moduleName,
              makeTextValue(text,path,timeStamp)); 
}

char* MS_getAsfTextPath(ATerm moduleName)
{
  ATerm value = getTextValuePath(
                  TS_getValue("asf-text", moduleName));
  return getString(value);
}

void MS_putAsfParseTable(ATerm moduleName, ATerm table, 
                         int timeStamp)
{
  TS_putValue("asf-parse-table", moduleName,
              makeParseTableValue(table,timeStamp)); 
}

void MS_putTermParseTable(ATerm moduleName, ATerm table, 
                         int timeStamp)
{
  TS_putValue("term-parse-table", moduleName,
              makeParseTableValue(table,timeStamp)); 
}
