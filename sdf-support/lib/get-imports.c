#include "SDFME-utils.h"
#include "module-table.h"
#include <assert.h>
#include <aterm2.h>
#include <atb-tool.h>

static ModuleTable moduleTable = NULL;

/*{{{  ATerm SDF_getImportModuleNamePlain(SDF_Import import) */

ATerm SDF_getImportModuleNamePlain(SDF_Import import)
{
  SDF_ModuleName modname = SDF_getImportModuleName(import);
  return SDF_getModuleNamePlain(modname);
}

/*}}}  */
/*{{{  getImpsectionImports(SDF_ImpSection impsection) */

static ATermList
getImpsectionImports(SDF_ImpSection impsection)
{
  ATermList      modules     = ATempty;
  SDF_Imports    imports     = SDF_getImpSectionList(impsection);
  SDF_ImportList importslist = SDF_getImportsList(imports);

  while (!SDF_isImportListEmpty(importslist)) {
    SDF_Import import = SDF_getImportListHead(importslist);
    modules = ATinsert(modules, 
                       SDF_getImportModuleNamePlain(import));

    if (SDF_isImportListSingle(importslist)) {
      break;
    }
    importslist = SDF_getImportListTail(importslist);
  }

  return modules;
}

/*}}}  */
/*{{{  collect_imports(SDF_Grammar grammar, ATermList *imports) */

static void
collect_imports(SDF_Grammar grammar, ATermList *imports)
{
  if (SDF_hasGrammarImpSection(grammar)) {
    SDF_ImpSection impsection = SDF_getGrammarImpSection(grammar);
    *imports = ATconcat(*imports, getImpsectionImports(impsection));
  }
}

/*}}}  */

/*{{{  KLOON: getImpsectionImportsList(SDF_ImpSection impsection) */

static  SDF_ImportList
getImpsectionImportsList(SDF_ImpSection impsection)
{
    return SDF_getImportsList(SDF_getImpSectionList(impsection));
}

/*}}}  */
/*{{{ KLOON:  collect_imports_list(SDF_Grammar grammar, SDF_ImportList *imports) */

static void
collect_imports_list(SDF_Grammar grammar, SDF_ImportList *imports)
{
    if (SDF_hasGrammarImpSection(grammar)) {
          SDF_ImpSection impsection = SDF_getGrammarImpSection(grammar);
	      *imports = SDF_concatImportList(*imports, 
					                                          getImpsectionImportsList(impsection));
	        }
}

/*}}}  */
/*{{{  KLOON: SDF_ImportList SDF_getModuleImportsList(SDF_Module module) */

SDF_ImportList SDF_getModuleImportsList(SDF_Module module)
{
  SDF_ImpSectionList imps;
  SDF_Sections       sections;
  SDF_ImportList     imports = SDF_makeImportListEmpty();

  imps = SDF_getModuleList(module);
  while (!SDF_isImpSectionListEmpty(imps)) {
    SDF_ImpSection impsection = SDF_getImpSectionListHead(imps);
    imports = SDF_concatImportList(getImpsectionImportsList(impsection),
                                   imports);

    if (SDF_isImpSectionListSingle(imps)) {
      break;
    }
    imps = SDF_getImpSectionListTail(imps);
  }

  sections = SDF_getModuleSections(module);
  SDFforeachGrammarInSections(sections,
                              (SDFGrammarFunc)collect_imports_list,
                              &imports);

  return imports;
}

/*}}}  */

/*{{{  ATermList SDF_getImports(SDF_Module module) */

ATermList SDF_getImports(SDF_Module module)
{
  SDF_ImpSectionList imps;
  SDF_Sections       sections;
  ATermList          modules = ATempty;

  imps = SDF_getModuleList(module);
  while (!SDF_isImpSectionListEmpty(imps)) {
    SDF_ImpSection impsection = SDF_getImpSectionListHead(imps);
    modules = ATconcat(getImpsectionImports(impsection), modules);

    if (SDF_isImpSectionListSingle(imps)) {
      break;
    }
    imps = SDF_getImpSectionListTail(imps);
  }

  sections = SDF_getModuleSections(module);
  SDFforeachGrammarInSections(sections,
			      (SDFGrammarFunc)collect_imports,
			      &modules);

  return modules;
}

/*}}}  */

/*{{{  static ATermList get_transitive_imports(ATermList todo) */

static SDF_ImportList get_transitive_imports(SDF_ImportList todo)
{
  SDF_ImportList result = SDF_makeImportListEmpty();

  /* The todo list contains imports with actual module parameters.
   * The result of this function will be a list of imports with the
   * parametrization represented as renamings.
   */

  assert(moduleTable != NULL && "module table not initialized");

  for (; !SDF_isImportListEmpty(todo); todo = SDF_getImportListTail(todo)) {
    SDF_Import     import;
    SDF_ModuleName name;
    SDF_ModuleId   id;
    SDF_Start      smodule;
    SDF_Module     module;
    SDF_Renamings  renamings;

    import = SDF_getImportListHead(todo);
    name = SDF_getImportModuleName(import);
    id   = SDF_removeModuleIdAnnotations(
			    SDF_getModuleNameModuleId(name));
    smodule = MT_getModule(moduleTable, id);
    if (smodule) {
      module = SDF_getStartTopModule(smodule);
    }
    else {
      module = NULL;
    }

    renamings = SDF_makeRenamingsRenamings(
                                 SDF_makeLayoutSpace(),
			         SDF_makeRenamingListEmpty(),
				 SDF_makeLayoutSpace());

    if (module != NULL &&
	!SDF_containsImportListImport(result, import)) {
      SDF_ImportList imports = SDF_getModuleImportsList(module);

      /* apply a renaming to the arguments of the import */
      if (SDF_isModuleNameParameterized(name)) {
	SDF_ModuleName formalName = SDF_getModuleModuleName(module);
	SDF_Symbols formals = SDF_getModuleNameParams(formalName);
	SDF_Symbols actuals = SDF_getModuleNameParams(name);

	renamings = SDF_makeRenamingsFromModuleNames(formalName, name);
	imports = SDF_replaceParametersInImportList(imports, formals, actuals);
      }

      todo = SDF_concatImportList(todo, imports);

      import = SDF_makeImportRenamedModule(
	         SDF_makeModuleNameUnparameterized(id), 
		 SDF_makeLayoutSpace(), renamings);

      result = SDF_concatImportList(result, 
				    SDF_makeImportListSingle(import));
    }

    if (!SDF_hasImportListTail(todo)) {
      break;
    }
  }

  return result;
}

/*}}}  */

/*{{{  static void initModuleTable(ATermList modules) */

static void initModuleTable(ATermList modules)
{
  /* initialize the hash table with all modules */
  for (;!ATisEmpty(modules); modules = ATgetNext(modules)) {
    ATerm atModule = ATBunpack(ATgetFirst(modules));
    SDF_Start smodule = SDF_StartFromTerm(atModule);
    SDF_Module module = SDF_getStartTopModule(smodule);
    SDF_ModuleId id = SDF_removeModuleIdAnnotations(
			SDF_getModuleNameModuleId(
	     	          SDF_getModuleModuleName(module)));
    MT_putModule(moduleTable, id, smodule);
  }
}

/*}}}  */

/*{{{  static ATermList do_get_transitive_imports(SDF_ModuleId moduleId) { */

static SDF_ImportList do_get_transitive_imports(SDF_ModuleId moduleId) 
{
  SDF_Import import = SDF_makeImportModule(
		      SDF_makeModuleNameUnparameterized(moduleId)); 

  assert(moduleTable != NULL);

  return get_transitive_imports(SDF_makeImportListSingle(import));
}

/*}}}  */

/*{{{  ATermList SDF_getTransitiveImports(ATermList modules, SDF_ModuleId moduleId) */

SDF_ImportList SDF_getTransitiveImports(ATermList modules, SDF_ModuleId moduleId)
{
  SDF_ImportList result;

  moduleTable = MT_createModuleTable();
  initModuleTable(modules);
 
  result = do_get_transitive_imports(moduleId);

  MT_destroyModuleTable(moduleTable);
  moduleTable = NULL;

  return result;
}

/*}}}  */

/*{{{  static ATbool imports_contains_id(ATermList imports, SDF_ModuleId id) */

static ATbool imports_contains_id(SDF_ImportList imports, SDF_ModuleId id)
{
  while (!SDF_isImportListEmpty(imports))  {
    SDF_Import import = SDF_getImportListHead(imports);
    SDF_ModuleId importId = SDF_getModuleNameModuleId(
                               SDF_getImportModuleName(import));

    if (SDF_isEqualModuleId(id, importId)) {
      return ATtrue;
    }

    if (SDF_hasImportListTail(imports)) {
      imports = SDF_getImportListTail(imports);
    }
    else {
      break;
    }
  }

  return ATfalse;
}

/*}}}  */
/*{{{  static ATermList get_depending_module_ids(SDF_ModuleId moduleId) */

static ATermList get_depending_module_ids(SDF_ModuleId moduleId)
{
  ATermList modules;
  ATermList dependingModules = ATempty;
  assert(moduleTable != NULL);

  modules = MT_allModules(moduleTable);
  
  for (;!ATisEmpty(modules); modules = ATgetNext(modules)) {
    SDF_ModuleId module = SDF_ModuleIdFromTerm(ATgetFirst(modules));
    SDF_ImportList imports = do_get_transitive_imports(module);

    if (imports_contains_id(imports, moduleId)) {
      ATerm mid = ATmake("<str>", 
			 SDF_getCHARLISTString(SDF_getModuleIdChars(module)));
      dependingModules = ATinsert(dependingModules, mid);
    }
  }

  return dependingModules;
}

/*}}}  */

/*{{{  ATermList SDF_getDependingModuleIds(ATermList modules, SDF_ModuleId moduleId) */

ATermList SDF_getDependingModuleIds(ATermList modules, SDF_ModuleId moduleId)
{
  ATermList result;

  moduleTable = MT_createModuleTable();
  initModuleTable(modules);
 
  result = get_depending_module_ids(moduleId);

  MT_destroyModuleTable(moduleTable);
  moduleTable = NULL;

  return result;
}

/*}}}  */

/*{{{  static ATermList collect_imported_modules(SDF_ImportList imports) */

static ATermList collect_imported_modules(SDF_ImportList imports)
{
  ATermList result = ATempty;
 
  assert(moduleTable && "moduleTable not initialized");

  while (!SDF_isImportListEmpty(imports)) {
    SDF_Import import = SDF_getImportListHead(imports);
    SDF_ModuleName importName = SDF_getImportModuleName(import);
    SDF_ModuleId importId = SDF_getModuleNameModuleId(importName);
    SDF_Start module = MT_getModule(moduleTable, importId);

    result = ATinsert(result, SDF_StartToTerm(module));

    if (SDF_hasImportListTail(imports)) {
      imports = SDF_getImportListTail(imports);
    }
    else {
      break;
    }
  }

  return result;
}

/*}}}  */

/*{{{  ATermList SDF_getTransitiveImportedModules(ATermList modules,  */

ATermList SDF_getTransitiveImportedModules(ATermList modules, 
					   SDF_ModuleId moduleId)
{
  ATermList result = ATempty;
  SDF_ImportList imports;

  moduleTable = MT_createModuleTable();
  initModuleTable(modules);
 
  imports = do_get_transitive_imports(moduleId);
  result = collect_imported_modules(imports);

  MT_destroyModuleTable(moduleTable);
  moduleTable = NULL;

  return result;
}

/*}}}  */
