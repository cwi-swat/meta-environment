/*
  $Id$
 */

#include <aterm2.h>

#include <SDFME-utils.h>
#include <MEPT-utils.h>

#include "module-store.h"
#include "extension-store.h"
#include "term-conversion.h"
#include "module-operations.h"
#include "module-refactorings.h"

#define DEPTH_OF_EQUATIONS   4

SDF_ImportList MDB_getImports(ATerm moduleName)
{
  SDF_ImportList result = SDF_makeImportListEmpty();

  if (MS_existsModule(moduleName)) {
    SDF_Module module = SDF_getStartTopModule(
                          SDF_StartFromTerm(
                            MS_getSdfTree(moduleName)));
    printf("broken due to refactoring in sdf-support");
    result = SDF_getModuleImportsList(module);
  }
  else {
    ATwarning("getImports: Module %t not in database!\n", moduleName);
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
    ATwarning("getFormalParams: Module %t not in database!\n", moduleName);
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

ATerm MDB_getSdfDefinition(ATerm moduleName)
{
  if (MDB_completeSdfSpecification(moduleName, ATempty)) {
    ATermList imports = SO_getTransitiveImports(
                          SDF_makeImportListSingle(
                           SDF_makeImport(getString(moduleName))));
    SDF_SDF definition = getSyntaxDefinition(imports);
    return SDF_StartToTerm(SDF_makeStartSDF(SDF_makeOptLayoutAbsent(),
			   definition,
			   SDF_makeOptLayoutAbsent(),0));
  }
  else {
    return NULL;
  }
}

ATermList MDB_getModulesWithoutEqs(ATerm moduleName)
{
  ATermList missingModules = ATempty;

  if (MS_existsModule(moduleName)) {
    ATermList imports = SO_getTransitiveImports(
                          SDF_makeImportListSingle(
                            SDF_makeImport(getString(moduleName))));
    
    while (!ATisEmpty(imports)) {
      ATerm module = SDF_getModuleNamePlain(
		       SDF_getImportModuleName(
			 SDF_makeImportFromTerm(ATgetFirst(imports))));
      ATerm eqsText = MS_getAsfTextValue(module);
      ATerm eqsTree = MS_getAsfTree(module);

      /* If the text of equations are stored and the parse tree
       * is not available, the module is registered in order
       * to parse the equations.
       */
      if (eqsText != NULL && eqsTree == NULL)  {
	missingModules = ATinsert(missingModules, module);
      }
      imports = ATgetNext(imports);
    }
  }
  return missingModules;
}

void MDB_updateEqsTree(ATerm moduleName, ATerm eqsTree)
{
  char *path = MS_getModulePath(moduleName);

  if (path) {
    eqsTree = PT_makeTermFromParseTree(
		PT_addParseTreePosInfoToDepth(
		  path,
		  PT_makeParseTreeFromTerm(eqsTree),
		  DEPTH_OF_EQUATIONS));
  }
  else {
    ATwarning("Could not add pos info to equation tree for %t\n", moduleName);
  }

  MS_putAsfTree(moduleName, eqsTree);
}

ATerm MDB_getEqsTree(ATerm moduleName)
{
  if (MS_existsModule(moduleName)) {
    return MS_getAsfTree(moduleName);
  }
  else {
    return NULL;
  }
}

void MDB_invalidateModule(ATerm moduleName)
{
  MS_removeAsfTree(moduleName);
  MS_removeAsfParseTable(moduleName);
  MS_removeTermParseTable(moduleName);
}

void MDB_invalidateModules(ATermList modules)
{
  while (!ATisEmpty(modules)) {
    MDB_invalidateModule(ATgetFirst(modules));
    modules = ATgetNext(modules);
  }
}

ATermList MDB_getDependingModules(ATerm moduleName)
{
  ATerm module;
  ATermList imports;
  ATermList dependingModules = ATempty;
  ATermList modules = MS_getActiveModules();

  while (!ATisEmpty(modules)) {
    module = ATgetFirst(modules);

    imports = SO_getTransitiveImports(
		SDF_makeImportListSingle(
	          SDF_makeImport(getString(module))));

    if (ATindexOf(imports, moduleName, 0) >= 0) {
      dependingModules = ATinsert(dependingModules, module);
    }

    modules = ATgetNext(modules);
  }

  return dependingModules;
}

static void MDB_deleteModuleFromImportsInModule(ATerm moduleName, 
						ATerm importName)
{
  ATerm oldSdfTree = MS_getSdfTree(moduleName);
  SDF_Module oldSdfModule = SDF_getStartTopModule(
			      SDF_StartFromTerm(oldSdfTree));
  SDF_Module newSdfModule = SO_deleteModuleNameFromModule(
			      oldSdfModule, 
                              SDF_makeModuleId(getString(importName)));
  ATerm newSdfTree = SDF_StartToTerm(SDF_setStartTopModule(
		       SDF_StartFromTerm(oldSdfTree), newSdfModule));

  MS_putSdfTree(moduleName, newSdfTree);
}

void MDB_deleteModuleFromImportsInModules(ATermList modules, ATerm moduleName)
{
  ATerm module;

  while (!ATisEmpty(modules)) {
    module = ATgetFirst(modules);

    MDB_deleteModuleFromImportsInModule(module, moduleName);

    modules = ATgetNext(modules);
  }
}
