#include "SDFME-utils.h"
#include "module-table.h"
#include <assert.h>

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

/*{{{  static SDF_ImportList get_transitive_imports(SDF_ImportList todo) */

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
    SDF_Module     module = MT_getModule(moduleTable, id);
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

/*{{{  SDF_ImportList SDF_getTransitiveImports(SDF_Definition definition,  */

ATermList SDF_getTransitiveImports(ATermList modules, 
	  			   SDF_ModuleId moduleId)
{
  SDF_Import import = SDF_makeImportModule(
		      SDF_makeModuleNameUnparameterized(moduleId)); 
  ATermList result;

  moduleTable = MT_createModuleTable();

  /* initialize the hash table with all modules */
  for (;!ATisEmpty(modules); modules = ATgetNext(modules)) {
    SDF_Module module = SDF_ModuleFromTerm(ATgetFirst(modules));
    SDF_ModuleId id = SDF_getModuleNameModuleId(
	     	        SDF_getModuleModuleName(module));
    MT_putModule(moduleTable, id, module);
  }

  result = get_transitive_imports(ATmakeList1(SDF_ImportToTerm(import)));

  MT_destroyModuleTable(moduleTable);
  moduleTable = NULL;

  return result;
}

/*}}}  */
