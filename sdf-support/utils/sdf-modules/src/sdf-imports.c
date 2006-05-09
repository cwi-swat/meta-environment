#include "SDFME-utils.h"
#include "module-table.h"
#include <MEPT-utils.h>
#include <assert.h>
#include <aterm2.h>
#include <atb-tool.h>

static ModuleTable moduleTable = NULL;

/*{{{  static void initModuleTable(ATermList modules) */

static void initModuleTable(ATermList modules)
{
  /* initialize the hash table with all modules */
  for (;!ATisEmpty(modules); modules = ATgetNext(modules)) {
    ATerm atModule = ATgetFirst(modules);
    SDF_Start smodule = SDF_StartFromTerm(atModule);
    SDF_Module module = SDF_getStartTopModule(smodule);
    SDF_ModuleId id = SDF_removeModuleIdAnnotations(
			SDF_getModuleNameModuleId(
	     	          SDF_getModuleModuleName(module)));
    MT_putModule(moduleTable, id, smodule);
  }
}

/*}}}  */

/*{{{  ATerm SI_getImportModuleNamePlain(SDF_Import import) */

ATerm SI_getImportModuleNamePlain(SDF_Import import)
{
  SDF_ModuleName modname = SDF_getImportModuleName(import);
  return SDF_getModuleNamePlain(modname);
}

/*}}}  */

/*{{{  static ATermList getImpsectionImports(SDF_ImpSection impsection) */

static ATermList getImpsectionImports(SDF_ImpSection impsection)
{
  ATermList      modules     = ATempty;
  SDF_Imports    imports     = SDF_getImpSectionList(impsection);
  SDF_ImportList importslist = SDF_getImportsList(imports);

  while (!SDF_isImportListEmpty(importslist)) {
    SDF_Import import = SDF_getImportListHead(importslist);
    modules = ATinsert(modules, 
                       SI_getImportModuleNamePlain(import));

    if (SDF_isImportListSingle(importslist)) {
      break;
    }
    importslist = SDF_getImportListTail(importslist);
  }

  return modules;
}

/*}}}  */
/*{{{  static void collect_imports(SDF_Grammar grammar, ATermList *imports) */

static void collect_imports(SDF_Grammar grammar, ATermList *imports)
{
  if (SDF_hasGrammarImpSection(grammar)) {
    SDF_ImpSection impsection = SDF_getGrammarImpSection(grammar);
    *imports = ATconcat(*imports, getImpsectionImports(impsection));
  }
}

/*}}}  */
/*{{{  static SDF_ImportList getImpsectionImportsList(SDF_ImpSection impsection) */

static SDF_ImportList getImpsectionImportsList(SDF_ImpSection impsection)
{
  return SDF_getImportsList(SDF_getImpSectionList(impsection));
}

/*}}}  */
/*{{{  static void collect_imports_list(SDF_Grammar grammar, SDF_ImportList *imports) */

static void collect_imports_list(SDF_Grammar grammar, SDF_ImportList *imports)
{
  if (SDF_hasGrammarImpSection(grammar)) {
    SDF_ImpSection impsection = SDF_getGrammarImpSection(grammar);
    *imports = SDF_concatImportList(*imports, 
				    SDF_makeLayoutSpace(),
				    getImpsectionImportsList(impsection));
  }
}

/*}}}  */

/*{{{  SDF_ImportList SI_getModuleImportsList(SDF_Module module) */

SDF_ImportList SI_getModuleImportsList(SDF_Module module)
{
  SDF_ImpSectionList imps;
  SDF_Sections       sections;
  SDF_ImportList     imports = SDF_makeImportListEmpty();

  imps = SDF_getModuleList(module);
  while (!SDF_isImpSectionListEmpty(imps)) {
    SDF_ImpSection impsection = SDF_getImpSectionListHead(imps);
    SDF_ImportList list = getImpsectionImportsList(impsection);

    imports = SDF_mergeImportList(list, imports);

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
/*{{{  ATermList SI_getImports(SDF_Module module) */

ATermList SI_getImports(SDF_Module module)
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
    
    renamingList = SDF_insertRenaming(renaming,renamingList);

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
  SDF_Symbols actualParams;
  SDF_Symbols formalParams;

  if (SDF_hasModuleNameParams(actual)) {
    actualParams = SDF_getModuleNameParams(actual);
  }
  else {
    actualParams = SDF_makeSymbolsDefault(SDF_makeSymbolListEmpty());
  }

  if (SDF_hasModuleNameParams(formal)) {
    formalParams = SDF_getModuleNameParams(formal);
  }
  else {
    formalParams = SDF_makeSymbolsDefault(SDF_makeSymbolListEmpty());
  }

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

  if (moduleStart != NULL) {
    return SDF_getStartTopModule(moduleStart);
  }
  else {
    return NULL;
  }
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

static SDF_Symbol renameSymbol(SDF_Symbol from, SDF_Symbol into, SDF_Symbol symbol);
/*{{{  static SDF_SymbolParameters renameSymbolParameters(SDF_Symbol from,  */

static SDF_SymbolParameters renameSymbolParameters(SDF_Symbol from, 
					 	   SDF_Symbol into,
                                                   SDF_SymbolParameters symbols)
{
  if (SDF_hasSymbolParametersHead(symbols)) {
    SDF_Symbol head = SDF_getSymbolParametersHead(symbols);
    SDF_Symbol newHead = renameSymbol(from, into, head);
    symbols = SDF_setSymbolParametersHead(symbols, newHead);
  }
  if (SDF_hasSymbolParametersTail(symbols)) {
    SDF_SymbolParameters tail = SDF_getSymbolParametersTail(symbols);
    SDF_SymbolParameters newTail = renameSymbolParameters(from, into, tail);
    symbols = SDF_setSymbolParametersTail(symbols, newTail);
  }
  return symbols;
}

/*}}}  */
/*{{{  static SDF_SymbolTail renameSymbolTail(SDF_Symbol from,  */

static SDF_SymbolTail renameSymbolTail(SDF_Symbol from, 
				       SDF_Symbol into,
                                       SDF_SymbolTail symbols)
{
  if (SDF_hasSymbolTailHead(symbols)) {
    SDF_Symbol head = SDF_getSymbolTailHead(symbols);
    SDF_Symbol newHead = renameSymbol(from, into, head);
    symbols = SDF_setSymbolTailHead(symbols, newHead);
  }
  if (SDF_hasSymbolTailTail(symbols)) {
    SDF_SymbolTail tail = SDF_getSymbolTailTail(symbols);
    SDF_SymbolTail newTail = renameSymbolTail(from, into, tail);
    symbols = SDF_setSymbolTailTail(symbols, newTail);
  }
  return symbols;
}

/*}}}  */

static SDF_SymbolRest renameSymbolRest(SDF_Symbol from,
				       SDF_Symbol into,
                                       SDF_SymbolRest symbols)
{
  if (SDF_hasSymbolRestHead(symbols)) {
    SDF_Symbol head = SDF_getSymbolRestHead(symbols);
    SDF_Symbol newHead = renameSymbol(from, into, head);
    symbols = SDF_setSymbolRestHead(symbols, newHead);
  }
  if (SDF_hasSymbolRestTail(symbols)) {
    SDF_SymbolRest tail = SDF_getSymbolRestTail(symbols);
    SDF_SymbolRest newTail = renameSymbolRest(from, into, tail);
    symbols = SDF_setSymbolRestTail(symbols, newTail);
  }
  return symbols;
}
/*{{{  static SDF_SymbolList renameSymbolList(SDF_Symbol from, */

static SDF_SymbolList renameSymbolList(SDF_Symbol from,
				       SDF_Symbol into,
                                       SDF_SymbolList symbols)
{
  if (SDF_hasSymbolListHead(symbols)) {
    SDF_Symbol head = SDF_getSymbolListHead(symbols);
    SDF_Symbol newHead = renameSymbol(from, into, head);
    symbols = SDF_setSymbolListHead(symbols, newHead);
  }
  if (SDF_hasSymbolListTail(symbols)) {
    SDF_SymbolList tail = SDF_getSymbolListTail(symbols);
    SDF_SymbolList newTail = renameSymbolList(from, into, tail);
    symbols = SDF_setSymbolListTail(symbols, newTail);
  }
  return symbols;
}

/*}}}  */
/*{{{  static SDF_Symbols renameSymbols(SDF_Symbol from,  */

static SDF_Symbols renameSymbols(SDF_Symbol from, 
				 SDF_Symbol into,
                                 SDF_Symbols symbols)
{
  SDF_SymbolList list = SDF_getSymbolsList(symbols);
  SDF_SymbolList newList = renameSymbolList(from, into, list);
  return SDF_setSymbolsList(symbols, newList);
}

/*}}}  */

/*{{{  static SDF_Symbol renameSymbol(SDF_Symbol from, Symbol into, */

static SDF_Symbol renameSymbol(SDF_Symbol from, SDF_Symbol into,
			       SDF_Symbol symbol)
{
  SDF_Symbol argSymbol;
  SDF_Symbol newArgSymbol;

  symbol = SDF_removeSymbolAnnotations(symbol);
  from = SDF_removeSymbolAnnotations(from);
  
  if (SDF_isEqualSymbol(symbol, from)) {
    return into;
  }
  if (SDF_hasSymbolSymbol(symbol)) {
    argSymbol = SDF_getSymbolSymbol(symbol);
    newArgSymbol = renameSymbol(from, into, argSymbol);
    symbol = SDF_setSymbolSymbol(symbol, newArgSymbol);
  }
  if (SDF_hasSymbolLeft(symbol)) {
    argSymbol = SDF_getSymbolLeft(symbol);
    newArgSymbol = renameSymbol(from, into, argSymbol);
    symbol = SDF_setSymbolLeft(symbol, newArgSymbol);
  }
  if (SDF_hasSymbolRight(symbol)) {
    argSymbol = SDF_getSymbolRight(symbol);
    newArgSymbol = renameSymbol(from, into, argSymbol);
    symbol = SDF_setSymbolRight(symbol, newArgSymbol);
  }
  if (SDF_hasSymbolSep(symbol)) {
    argSymbol = SDF_getSymbolSep(symbol);
    newArgSymbol = renameSymbol(from, into, argSymbol);
    symbol = SDF_setSymbolSep(symbol, newArgSymbol);
  }
  if (SDF_hasSymbolHead(symbol)) {
    argSymbol = SDF_getSymbolHead(symbol);
    newArgSymbol = renameSymbol(from, into, argSymbol);
    symbol = SDF_setSymbolHead(symbol, newArgSymbol);
  }
  if (SDF_hasSymbolRest(symbol)) {
    SDF_SymbolRest rest = SDF_getSymbolRest(symbol);
    SDF_SymbolRest result = renameSymbolRest(from, into, rest);
    symbol = SDF_setSymbolRest(symbol, result);  
  }
  if (SDF_hasSymbolTail(symbol)) {
    SDF_SymbolTail argSymbols = SDF_getSymbolTail(symbol);
    SDF_SymbolTail newArgSymbols = renameSymbolTail(from, into, argSymbols); 
    symbol = SDF_setSymbolTail(symbol, newArgSymbols);
  }
  if (SDF_hasSymbolArguments(symbol)) {
    SDF_Symbols argSymbols = SDF_getSymbolArguments(symbol);
    SDF_Symbols newArgSymbols = renameSymbols(from, into, argSymbols); 
    symbol = SDF_setSymbolArguments(symbol, newArgSymbols);
  }
  if (SDF_hasSymbolResults(symbol)) {
    argSymbol = SDF_getSymbolResults(symbol);
    newArgSymbol = renameSymbol(from, into, argSymbol);
    symbol = SDF_setSymbolResults(symbol, newArgSymbol);
  }
  if (SDF_hasSymbolParameters(symbol)) {
    SDF_SymbolParameters argSymbols = SDF_getSymbolParameters(symbol);
    SDF_SymbolParameters newArgSymbols = 
                           renameSymbolParameters(from, into, argSymbols);
    symbol = SDF_setSymbolParameters(symbol, newArgSymbols);
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
  SDF_Symbol result;

  result = renameSymbol(from, into, symbol);

  return result;
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
    SDF_Renaming renamed = applyRenamingToRenaming(renaming, toBeRenamed);

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
    SDF_Symbol new;

    new = applyRenamingToSymbol(renaming, symbol);
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
    renamings = applyRenamingToRenamings(renaming, renamings);
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
    
    if (SDF_hasRenamingListTail(list)) {
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

    result = SDF_insertImport(new, result);

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

/*{{{  static SDF_Renamings concatRenamings(SDF_Renamings r1, SDF_Renamings r2) */

static SDF_Renamings concatRenamings(SDF_Renamings r1, SDF_Renamings r2)
{
  SDF_RenamingList l1 = SDF_getRenamingsList(r1);
  SDF_RenamingList l2 = SDF_getRenamingsList(r2);
  SDF_OptLayout space = SDF_makeLayoutSpace();

  return SDF_makeRenamingsRenamings(space,
				    SDF_concatRenamingList(l1, space, l2),
				    space);
}

/*}}}  */

/*{{{  static SDF_Renamings appendUserRenamings(SDF_Import import, */

static SDF_Renamings appendUserRenamings(SDF_Import import,
					 SDF_Renamings renamings)
{
  if (SDF_hasImportRenamings(import)) {
    SDF_Renamings importRenamings = SDF_getImportRenamings(import);
    renamings = concatRenamings(renamings, importRenamings);
  }

  return renamings;
}

/*}}}  */

/*{{{  static SDF_ImportList inheritUserRenamings(SDF_Import import, */

static SDF_ImportList inheritUserRenamings(SDF_Import import,
					   SDF_ImportList imports)
{
  SDF_ImportList result = imports;
  
  if (SDF_hasImportRenamings(import)) {
    SDF_Renamings renamings = SDF_getImportRenamings(import);
    result = SDF_makeImportListEmpty();

    while (!SDF_isImportListEmpty(imports)) {
      SDF_Import head = SDF_getImportListHead(imports);

      if (SDF_hasImportRenamings(head)) {
	renamings = concatRenamings(renamings,
				    SDF_getImportRenamings(head));
	head = SDF_setImportRenamings(head, renamings);
      }
      else {
	SDF_ModuleName moduleName = SDF_getImportModuleName(head);
	SDF_OptLayout space = SDF_makeLayoutSpace();
	head = SDF_makeImportRenamedModule(moduleName, space, renamings);
      }

      result = SDF_insertImport(head, result);

      if (SDF_hasImportListTail(imports)) {
	imports = SDF_getImportListTail(imports);
      }
      else {
	break;
      }
    }
  }

  return result;
}

/*}}}  */

/*{{{  static ATermList get_transitive_imports(ATermList todo) */

static SDF_ImportList get_transitive_imports(SDF_ImportList todo)
{
  SDF_ImportList result = SDF_makeImportListEmpty();
  SDF_ImportList processed = SDF_makeImportListEmpty();

  /* The todo list contains imports with actual module parameters and
   * with the renamings associated to the import.
   * The result of this function will be a list of imports with the
   * parametrization represented as renamings with the user defined 
   * renamings appended.
   */

  assert(moduleTable != NULL && "module table not initialized");

  while (!SDF_isImportListEmpty(todo)) {
    SDF_Import     import, plainImport;

    import = SDF_removeImportAnnotations(SDF_getImportListHead(todo));
    plainImport = import;

    if (SDF_hasImportListTail(todo)) {
      todo = SDF_getImportListTail(todo);
    }
    else {
      todo = SDF_makeImportListEmpty();
    }

    if (!SDF_containsImportListImport(processed, import)) {
      SDF_Renamings renamings;
      SDF_ImportList imports;
      SDF_Module module = getModuleByImport(import);

      if (module != NULL) {
	SDF_ModuleName formalName = SDF_getModuleModuleName(module);
	SDF_ModuleName actualName = SDF_getImportModuleName(import);

	renamings = makeRenamingsFromModuleNames(formalName, actualName);
	renamings = appendUserRenamings(import, renamings);

	imports = SI_getModuleImportsList(module);
	imports = applyRenamingsToImports(renamings, imports);
	imports = inheritUserRenamings(import, imports);

	todo = SDF_mergeImportList(todo, imports);
	import = makeRenamedImport(actualName, renamings);

	if (!SDF_containsImportListImport(processed, plainImport)) { 
	  processed = SDF_insertImport(plainImport, processed);
	  result = SDF_insertImport(import, result);
	}
      }
    }
  }

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
/*{{{  static ATermList do_get_transitive_imports(SDF_ModuleId moduleId) { */

static SDF_ImportList do_get_transitive_imports(SDF_ModuleId moduleId) 
{
  SDF_Import import = SDF_makeImportModule(
		      SDF_makeModuleNameUnparameterized(moduleId)); 

  assert(moduleTable != NULL);

  return get_transitive_imports(SDF_makeImportListSingle(import));
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
    SDF_ModuleId module = SDF_ModuleIdFromTerm(ATBunpack(ATgetFirst(modules)));
    SDF_ImportList imports = do_get_transitive_imports(module);

    if (imports_contains_id(imports, moduleId)) {
      ATerm mid = ATmake("<str>", PT_yieldTree((PT_Tree) moduleId));
      dependingModules = ATinsert(dependingModules, mid);
    }
  }

  return dependingModules;
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
    SDF_Start module = MT_getModule(moduleTable, 
				    SDF_removeModuleIdAnnotations(importId));
    assert(module != NULL && "its a precondition to have this module stored"); 
    
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

/*{{{  ATermList SDF_getTransitiveImports(ATermList modules, SDF_ModuleId moduleId) */

SDF_ImportList SI_getTransitiveImports(ATermList modules, SDF_ModuleId moduleId)
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
/*{{{  ATermList SI_getDependingModuleIds(ATermList modules, SDF_ModuleId moduleId) */

ATermList SI_getDependingModuleIds(ATermList modules, SDF_ModuleId moduleId)
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
/*{{{  ATermList SI_getTransitiveImportedModules(ATermList modules,  */

ATermList SI_getTransitiveImportedModules(ATermList modules, 
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
