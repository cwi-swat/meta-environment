/*
  $Id$
 */

#include <aterm2.h>

#include <SDFME-utils.h>

#include "module-store.h"
#include "extension-store.h"
#include "module-operations.h"

SDF_ImportList MDB_getImports(ATerm moduleName)
{
  SDF_ImportList result = SDF_makeImportListEmpty();

  if (MS_existsModule(moduleName)) {
    SDF_Module module = SDF_getStartTopModule(
                          SDF_StartFromTerm(
                            MS_getSdfTree(moduleName)));
    result = SDF_getModuleImportsList(module);
  }
  else {
    ATwarning("Module %t not in database!\n", moduleName);
  }
  return result;
}

ATermList MDB_getImportIds(ATerm moduleName)
{
  SDF_ImportList imports = MDB_getImports(moduleName);
  return SO_transformImportsToImportIds(imports);
  
}

SDF_Symbols MDB_getFormalParams(ATerm moduleName)
{
  SDF_Symbols result = SDF_makeSymbolsDefault(
                         SDF_makeSymbolListEmpty());

  if (MS_existsModule(moduleName)) {
    SDF_Module module = SDF_getStartTopModule(
                          SDF_StartFromTerm(
                            MS_getSdfTree(moduleName)));
    result = SDF_getModuleNameParams(SDF_getModuleModuleName(module));
  }
  else {
    ATwarning("Module %t not in database!\n", moduleName);
  }

  return result;
}

ATermList MDB_unavailableImportedModules(ATerm moduleName)
{
  ATermList imports = MDB_getImportIds(moduleName);
  ATermList unknowns = ATempty;

ATwarning("imports = %t\n", imports); 
  while (!ATisEmpty(imports)) {
    ATerm import = ATgetFirst(imports);

    if (!MS_existsModule(import)) {
      unknowns = ATinsert(unknowns, import);  
    }
    imports = ATgetNext(imports);
  }

  return unknowns;
}

ATerm MDB_retrieveImportGraph()
{
  ATermList activeModules = MS_getActiveModules();
  ATermList allModules = activeModules;
  ATermList result = ATempty;

  while (!ATisEmpty(allModules)) {
    ATerm moduleName = ATgetFirst(allModules);
    ATermList imports = MDB_getImportIds(moduleName);

    while (!ATisEmpty(imports)) {
      ATerm import = ATgetFirst(imports);
      ATerm pair = ATmake("[<term>,<term>]", moduleName, import);

      if (ATindexOf(result, pair, 0) < 0) {
        result = ATappend(result, pair);
      }

      imports = ATgetNext(imports);
    }
  
    allModules = ATgetNext(allModules);
  }

  return ATmake("import-graph([<list>],[<list>])", 
                activeModules,
                result);
}
