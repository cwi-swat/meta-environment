
#include "table-store.h"
#include "table.h"
#include <SDFME.h>

#define makeString(s) ((ATerm) ATmakeAppl0(ATmakeAFun(s,0,ATtrue)))
#define makeKey(s) (makeString(s))
#define makeTextValue(text,path,timeStamp)  ((ATermList) ATmakeList3(makeString(text),makeString(path),(ATerm) ATmakeInt(timeStamp)))
#define makeTreeValue(tree)  ((ATermList) ATmakeList1((ATerm) tree))

void MS_initModuleStore()
{
  TS_initTableStore();
  TS_addTable("active-modules");
  TS_addTable("transitive-imports");
  TS_addTable("sdf-tree");
  TS_addTable("sdf-text");
  TS_addTable("asf-tree");
  TS_addTable("asf-text");
  TS_addTable("asf-table");
  TS_addTable("term-table");
}

void MS_destroyModuleStore()
{
  TS_removeTable("active-modules");
  TS_removeTable("transitive-imports");
  TS_removeTable("sdf-tree");
  TS_removeTable("sdf-text");
  TS_removeTable("asf-tree");
  TS_removeTable("asf-text");
  TS_removeTable("asf-table");
  TS_removeTable("term-table");
}

void MS_clearModuleStore()
{
  MS_destroyModuleStore();
  MS_initModuleStore();
}

void MS_clearTransitiveImports()
{
  TS_clearTable("transitive-imports");
}

ATbool MS_moduleExists(char *moduleName)
{
  return TS_containsKey("active-modules",makeKey(moduleName));
}

ATermList MS_getTransitiveImports(char *moduleName) 
{
  return TS_getValue("transitive-imports",makeKey(moduleName));
}

SDF_Module MS_getSdfTree(char *moduleName)
{
  return (SDF_Module) TS_getValue("sdf-tree", makeKey(moduleName));
}

void MS_putSdfTree(char *moduleName, SDF_Module moduleTree)
{
  TS_putValue("sdf-tree", makeKey(moduleName), 
	      makeTreeValue(SDF_ModuleToTerm(moduleTree)));
}

void MS_addSdfText(char *moduleName, char *text, char *path, int timeStamp)
{
  TS_putValue("sdf-tree", moduleName, makeTextValue(text,path,timeStamp));
}

void MS_addAsfTree(char *moduleName, SDF_Module moduleTree)
{
  TS_putValue("sdf-tree", makeKey(moduleName), makeTreeValue(moduleTree));
}

void MS_addAsfText(char *moduleName, char *text, char *path, int timeStamp)
{
  TS_putValue("asf-text", makeKey(moduleName),makeTextValue(text,path,timeStamp)); 
}
