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

/*{{{  static SDF_Renamings makeRenamingsFromParameters(SDF_Symbols formals, */

static SDF_Renamings makeRenamingsFromParameters(SDF_Symbols formals,
						     SDF_Symbols actuals)
{
  SDF_OptLayout layout = SDF_makeLayoutEmpty();
  SDF_RenamingList renamingList;
  SDF_SymbolList formalList;
  SDF_SymbolList actualList;

  formalList = SDF_getSymbolsList(formals);
  actualList = SDF_getSymbolsList(actuals);

  renamingList = SDF_makeRenamingListEmpty();

  while (SDF_hasSymbolListHead(actualList) 
	 && SDF_hasSymbolListHead(formalList)) {
    SDF_Symbol formal = SDF_getSymbolListHead(formalList);
    SDF_Symbol actual = SDF_getSymbolListHead(actualList);
    SDF_Renaming renaming = SDF_makeRenamingSymbol(formal,layout,layout,actual);
    
    renamingList = SDF_makeRenamingListMany(renaming,layout,renamingList);

    if (SDF_hasSymbolListTail(actualList)) {
      actualList = SDF_getSymbolListTail(actualList);
    }
    else {
      break;
    }

    if (SDF_hasSymbolListTail(formalList)) {
      formalList = SDF_getSymbolListTail(formalList);
    }
    else {
      ATwarning("WARNING: less formal parameters than actual parameters!");
      break;
    }
  }

  return SDF_makeRenamingsRenamings(layout,renamingList,layout);
}

/*}}}  */
/*{{{  static SDF_Renamings makeRenamingsFromModuleNames(SDF_ModuleName formal, */

static SDF_Renamings makeRenamingsFromModuleNames(SDF_ModuleName formal,
						      SDF_ModuleName actual)
{
  SDF_Symbols actualParams = SDF_getModuleNameParams(actual);
  SDF_Symbols formalParams = SDF_getModuleNameParams(formal);
  
  return makeRenamingsFromParameters(formalParams, actualParams);
}

/*}}}  */

/*{{{  static SDF_Module getModuleByImport(SDF_Import import) */

static SDF_Module getModuleByImport(SDF_Import import)
{
  SDF_ModuleName name = SDF_getImportModuleName(import);
  SDF_ModuleId id   = SDF_getModuleNameModuleId(name);
  SDF_Start moduleStart = NULL;   
 
  id = SDF_removeModuleIdAnnotations(id);

  moduleStart = MT_getModule(moduleTable, id);

  assert(moduleStart != NULL && "incomplete specification not expected!");
  
  return SDF_getStartTopModule(moduleStart);
}

/*}}}  */
/*{{{  static SDF_Import makeRenamedImport(SDF_ModuleName moduleName, */

static SDF_Import makeRenamedImport(SDF_ModuleName moduleName,
				    SDF_Renamings renamings)
{
  SDF_ModuleId id = SDF_getModuleNameModuleId(moduleName);
  SDF_ModuleName name = SDF_makeModuleNameUnparameterized(id);
  SDF_OptLayout space = SDF_makeLayoutSpace();

  return SDF_makeImportRenamedModule(name, space, renamings);
}

/*}}}  */

/*{{{  static SDF_Symbol renameSymbol(SDF_Symbol from, Symbol into, */

static SDF_Symbol renameSymbol(SDF_Symbol from, SDF_Symbol into,
			       SDF_Symbol symbol)
{
  SDF_Symbol argSymbol;
  SDF_Symbol newArgSymbol;

  symbol = SDF_removeSymbolAnnotations(symbol);

  if (SDF_isEqualSymbol(symbol, from)) {
    return into;
  }
  if (SDF_hasSymbolSymbol(symbol)) {
    argSymbol = SDF_getSymbolSymbol(symbol);
    newArgSymbol = renameSymbol(argSymbol, from, into);
    symbol = SDF_setSymbolSymbol(symbol, newArgSymbol);
  }
  if (SDF_hasSymbolLeft(symbol)) {
    argSymbol = SDF_getSymbolLeft(symbol);
    newArgSymbol = renameSymbol(argSymbol, from, into);
    symbol = SDF_setSymbolLeft(symbol, newArgSymbol);
  }
  if (SDF_hasSymbolRight(symbol)) {
    argSymbol = SDF_getSymbolRight(symbol);
    newArgSymbol = renameSymbol(argSymbol, from, into);
    symbol = SDF_setSymbolRight(symbol, newArgSymbol);
  }

  return symbol;
}

/*}}}  */
/*{{{  static SDF_Symbol applyRenamingToSymbol(SDF_Renaming renaming, */

static SDF_Symbol applyRenamingToSymbol(SDF_Renaming renaming,
					SDF_Symbol symbol)
{
  SDF_Symbol from = SDF_getRenamingFrom(renaming);
  SDF_Symbol into = SDF_getRenamingTo(renaming);

  return renameSymbol(from, into, symbol);
}

/*}}}  */
/*{{{  static SDF_Renaming applyRenamingToRenaming(SDF_Renaming renaming, */

static SDF_Renaming applyRenamingToRenaming(SDF_Renaming renaming,
					    SDF_Renaming toBeRenamed)
{
  SDF_Symbol from = SDF_getRenamingFrom(toBeRenamed);
  SDF_Symbol into = SDF_getRenamingTo(toBeRenamed);

  from = applyRenamingToSymbol(renaming, from);
  toBeRenamed = SDF_setRenamingFrom(toBeRenamed, from);

  into = applyRenamingToSymbol(renaming, into);
  toBeRenamed = SDF_setRenamingTo(toBeRenamed, into);

  return toBeRenamed;
}

/*}}}  */
/*{{{  static SDF_Renamings applyRenamingToRenamings(SDF_Renaming renaming, */

static SDF_Renamings applyRenamingToRenamings(SDF_Renaming renaming,
					      SDF_Renamings toBeRenameds)
{
  SDF_OptLayout empty = SDF_makeLayoutEmpty();
  SDF_RenamingList list = SDF_getRenamingsList(toBeRenameds);
  SDF_RenamingList result = SDF_makeRenamingListEmpty();

  while (!SDF_isRenamingListEmpty(list)) {
    SDF_Renaming toBeRenamed = SDF_getRenamingListHead(list);
    SDF_Renaming renamed = applyRenamingToRenaming(renaming,
						   toBeRenamed);

    result = SDF_insertRenaming(renamed, result);

    if (SDF_hasRenamingListTail(list)) {
      list = SDF_getRenamingListTail(list);
    }
    else {
      break;
    }
  }

  return SDF_makeRenamingsRenamings(empty,
				    SDF_reverseRenamingList(result),
				    empty);
}

/*}}}  */
/*{{{  static SDF_Symbols applyRenamingToSymbols(SDF_Renaming renaming, */

static SDF_Symbols applyRenamingToSymbols(SDF_Renaming renaming,
					  SDF_Symbols symbols)
{
  SDF_SymbolList list = SDF_getSymbolsList(symbols);
  SDF_SymbolList result = SDF_makeSymbolListEmpty();

  while (!SDF_isSymbolListEmpty(list)) {
    SDF_Symbol symbol = SDF_getSymbolListHead(list);
    SDF_Symbol new = applyRenamingToSymbol(renaming, symbol);

    result = SDF_insertSymbol(new, result);

    if (SDF_hasSymbolListTail(list)) {
      list = SDF_getSymbolListTail(list);
    }
    else {
      break;
    }
  }

  return SDF_makeSymbolsDefault(SDF_reverseSymbolList(result));
}

/*}}}  */
/*{{{  static SDF_Import applyRenamingToImport(SDF_Renaming renaming, */

static SDF_Import applyRenamingToImport(SDF_Renaming renaming,
					SDF_Import import)
{
  SDF_ModuleName name = SDF_getImportModuleName(import);

  if (SDF_hasImportRenamings(import)) {
    SDF_Renamings renamings = SDF_getImportRenamings(import);
    renamings = applyRenamingToRenamings(renaming, renamings); /*moetnog*/
    import = SDF_setImportRenamings(import, renamings);
  }

  if (SDF_hasModuleNameParams(name)) {
    SDF_Symbols params = SDF_getModuleNameParams(name);
    params = applyRenamingToSymbols(renaming, params);
    name = SDF_setModuleNameParams(name, params);
    import = SDF_setImportModuleName(import, name);
  }

  return import;
}

/*}}}  */
/*{{{  static SDF_Import applyRenamingsToImport(SDF_Renamings renamings,  */

static SDF_Import applyRenamingsToImport(SDF_Renamings renamings, 
					 SDF_Import import)
{
  SDF_RenamingList list = SDF_getRenamingsList(renamings);
  SDF_Import result = import;

  while (!SDF_isRenamingListEmpty(list)) {
    SDF_Renaming renaming = SDF_getRenamingListHead(list);
    
    result = applyRenamingToImport(renaming, result);

    if (!SDF_hasRenamingListTail(list)) {
      list = SDF_getRenamingListTail(list);
    }
    else {
      break;
    }
  }

  return result;
}

/*}}}  */
/*{{{  static SDF_ImportList applyRenamingsToImports(SDF_Renamings list,  */

static SDF_ImportList applyRenamingsToImports(SDF_Renamings renamings, 
					      SDF_ImportList imports)
{
  SDF_ImportList result = SDF_makeImportListEmpty();

  while (!SDF_isImportListEmpty(imports)) {
    SDF_Import import = SDF_getImportListHead(imports);
    SDF_Import new = applyRenamingsToImport(renamings, import);

    result = SDF_concatImportList(result, SDF_makeImportListSingle(new));

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

/*{{{  static ATermList get_transitive_imports(ATermList todo) */

static SDF_ImportList get_transitive_imports(SDF_ImportList todo)
{
  SDF_ImportList result = SDF_makeImportListEmpty();

  /* The todo list contains imports with actual module parameters.
   * The result of this function will be a list of imports with the
   * parametrization represented as renamings.
   */

  assert(moduleTable != NULL && "module table not initialized");

  while (!SDF_isImportListEmpty(todo)) {
    SDF_Import     import;

    import = SDF_getImportListHead(todo);

    if (!SDF_containsImportListImport(result, import)) {
      SDF_Renamings renamings;
      SDF_ImportList imports;

      SDF_Module module = getModuleByImport(import);
      SDF_ModuleName formalName = SDF_getModuleModuleName(module);
      SDF_ModuleName actualName = SDF_getImportModuleName(import);
      renamings = makeRenamingsFromModuleNames(formalName, actualName);

      imports = SDF_getModuleImportsList(module);
      todo = SDF_concatImportList(todo, applyRenamingsToImports(renamings,
								imports));

      import = makeRenamedImport(actualName, renamings);
      result = SDF_concatImportList(result,SDF_makeImportListSingle(import));
    }

    if (SDF_hasImportListTail(todo)) {
      todo = SDF_getImportListTail(todo);
    }
    else {
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
