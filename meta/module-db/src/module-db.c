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

static ATbool MDB_completeSdfSpecification(ATerm moduleName, 
                                           ATermList processed)
{
  if (ATindexOf(processed, moduleName, 0) < 0) {
    if (MS_existsModule(moduleName) && 
        MS_getSdfTree(moduleName) != NULL) {
      ATermList imports = MDB_getImportIds(moduleName);
      ATbool complete = ATtrue;

      processed = ATinsert(processed, moduleName);
      while (!ATisEmpty(imports) && complete) {
        ATerm importedModule = ATgetFirst(imports);
        complete = MDB_completeSdfSpecification(importedModule, 
                                                processed);
        imports = ATgetNext(imports);     
      }
      return complete;
    }
    else {
      return ATfalse;
    }
  }
  else {
    return ATtrue;
  }     
}

static SDF_SDF getSyntaxDefinition(ATermList modules)
{
  SDF_ModuleList sdfModules = SDF_makeModuleListEmpty();
  SDF_Definition sdfDefinition;  

  if (ATisEmpty(modules)) {
    sdfModules = SDF_makeModuleListEmpty();
  }
  else {
    while (!ATisEmpty(modules)) {
      ATerm moduleName = SDF_getModuleNamePlain(
                           SDF_getImportModuleName(
                             SDF_makeImportFromTerm(
                               ATgetFirst(modules))));
      ATerm module = MS_getSdfTree(moduleName);
      SDF_Module sdfModule = SDF_getStartTopModule(
                               SDF_StartFromTerm(module));

      if (SDF_isModuleListEmpty(sdfModules)) {
        sdfModules = SDF_makeModuleListSingle(sdfModule);
      }
      else {
         sdfModules = SDF_makeModuleListMany(sdfModule,
                                             SDF_makeLayoutEmpty(),
                                             sdfModules);
      }
      modules = ATgetNext(modules);
    }
  }
  sdfDefinition = SDF_makeDefinitionDefault(sdfModules);
  return SDF_makeSDFDefinition(SDF_makeLayoutEmpty(), 
                               sdfDefinition);
}

MDB_getSdfDefinition(ATerm moduleName)
{
  ATermList imports;

  if (MDB_completeSdfSpecification(moduleName, ATempty)) {
    ATermList imports = SO_getTransitiveImports(
                          SDF_makeImportListSingle(
                           SDFmakeImport(moduleName)));
  }
}
