#include "sdf.h"
#include <SDFME-utils.h>
#include <MEPT-utils.h>


SDF_ProductionList getModuleListProductions(SDF_ModuleList list)
{
  SDF_ProductionList allProds = SDF_makeProductionListEmpty();

  for(;SDF_hasModuleListHead(list); list = SDF_getModuleListTail(list)) {
    SDF_Module module = SDF_getModuleListHead(list);
    SDF_ProductionList modProds = SDF_getModuleProductions(module);
    allProds = SDF_concatProductionList(modProds, allProds); 

    if (!SDF_hasModuleListTail(list)) {
      break;
    }
  }

  return allProds;
}

SDF_ModuleName makeModuleNameFromString(const char* str)
{
  return SDF_makeModuleNameUnparameterized(
           SDF_makeModuleIdLexToCf(
            (SDF_Lexical) PT_makeTreeFlatLexicalFromString(str)));
}
