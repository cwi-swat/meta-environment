#include "SDFME-utils.h"
#include "module-table.h"
#include <assert.h>
#include <aterm2.h>

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

static ATermList get_transitive_imports(ATermList todo)
{
  ATermList result = ATempty;

  /* The todo list contains imports with actual module parameters.
   * The result of this function will be a list of imports with the
   * parametrization represented as renamings.
   */

  assert(moduleTable != NULL && "module table not initialized");

  for (; !ATisEmpty(todo); todo = ATgetNext(todo)) {
    SDF_Import     import = SDF_ImportFromTerm(ATgetFirst(todo));
    SDF_ModuleName name = SDF_getImportModuleName(import);
    SDF_ModuleId   id   = SDF_getModuleNameModuleId(name);
    SDF_Start      smodule = MT_getModule(moduleTable, id);
    SDF_Module     module = SDF_getStartTopModule(smodule);
    SDF_Renamings  renamings = SDF_makeRenamingsRenamings(
                                 SDF_makeLayoutSpace(),
			         SDF_makeRenamingListEmpty(),
				 SDF_makeLayoutSpace());

    if (module != NULL &&
	ATindexOf(result, SDF_ImportToTerm(import), 0) < 0) {
      ATermList imports = SDF_getImports(module);

      /* apply a renaming to the arguments of the import */
      if (SDF_isModuleNameParameterized(name)) {
	SDF_ModuleName formalName = SDF_getModuleModuleName(module);
	SDF_Symbols formals = SDF_getModuleNameParams(formalName);
	SDF_Symbols actuals = SDF_getModuleNameParams(name);

	renamings = SDF_makeRenamingsFromModuleNames(formalName, name);
	imports = SDF_replaceParametersInImportList(imports, formals, actuals);
      }

      todo = ATconcat(todo, imports);

      import = SDF_makeImportRenamedModule(
	         SDF_makeModuleNameUnparameterized(id), 
		 SDF_makeLayoutSpace(), renamings);

      result = ATinsert(result, SDF_ImportToTerm(import));
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
    SDF_Start smodule = SDF_StartFromTerm(ATgetFirst(modules));
    SDF_Module module = SDF_getStartTopModule(smodule);
    SDF_ModuleId id = SDF_getModuleNameModuleId(
	     	        SDF_getModuleModuleName(module));
    MT_putModule(moduleTable, id, smodule);
  }
}

/*}}}  */

/*{{{  static ATermList do_get_transitive_imports(SDF_ModuleId moduleId) { */

static ATermList do_get_transitive_imports(SDF_ModuleId moduleId) 
{
  SDF_Import import = SDF_makeImportModule(
		      SDF_makeModuleNameUnparameterized(moduleId)); 

  assert(moduleTable != NULL);

  return get_transitive_imports(ATmakeList1(SDF_ImportToTerm(import)));
}

/*}}}  */

/*{{{  ATermList SDF_getTransitiveImports(ATermList modules, SDF_ModuleId moduleId) */

ATermList SDF_getTransitiveImports(ATermList modules, SDF_ModuleId moduleId)
{
  ATermList result;

  moduleTable = MT_createModuleTable();
  initModuleTable(modules);
 
  result = do_get_transitive_imports(moduleId);

  MT_destroyModuleTable(moduleTable);
  moduleTable = NULL;

  return result;
}

/*}}}  */

/*{{{  static ATbool imports_contains_id(ATermList imports, SDF_ModuleId id) */

static ATbool imports_contains_id(ATermList imports, SDF_ModuleId id)
{
  for(; !ATisEmpty(imports); imports = ATgetNext(imports)) {
    SDF_Import import = SDF_ImportFromTerm(ATgetFirst(imports));
    SDF_ModuleId importId = SDF_getModuleNameModuleId(
                               SDF_getImportModuleName(import));

    if (SDF_isEqualModuleId(id, importId)) {
      return ATtrue;
    }
  }

  return ATfalse;
}

/*}}}  */
/*{{{  static ATermList get_depending_module_ids(SDF_ModuleId moduleId) */

static ATermList get_depending_module_ids(SDF_ModuleId moduleId)
{
  ATermList modules;
  assert(moduleTable != NULL);

  modules = MT_allModules(moduleTable);
  
  for (;!ATisEmpty(modules); modules = ATgetNext(modules)) {
    SDF_ModuleId module = SDF_ModuleIdFromTerm(ATgetFirst(modules));
    ATermList imports = do_get_transitive_imports(module);

    if (imports_contains_id(imports, moduleId)) {
      ATerm mid = ATmake("<str>", 
			 SDF_getCHARLISTString(SDF_getModuleIdChars(module)));
      modules = ATinsert(modules, mid);
    }
  }

  return modules;
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
