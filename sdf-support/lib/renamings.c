#include <SDFME-utils.h>

/*{{{  SDF_Renamings SDF_makeRenamingsFromParameters(SDF_Symbols formals, */

SDF_Renamings SDF_makeRenamingsFromParameters(SDF_Symbols formals,
					      SDF_Symbols actuals)
{
  SDF_OptLayout layout = SDF_makeLayoutEmpty();
  SDF_RenamingList renamingList;
  SDF_SymbolList formalList;
  SDF_SymbolList actualList;

  formalList = SDF_getSymbolsList(formals);
  actualList = SDF_getSymbolsList(actuals);

  renamingList = SDF_makeRenamingListEmpty();

  while (SDF_hasSymbolListHead(actualList) &&
	 SDF_hasSymbolListHead(formalList)) {
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
/*{{{  SDF_Renamings SDF_makeRenamingsFromModuleNames(SDF_ModuleName formal, */

SDF_Renamings SDF_makeRenamingsFromModuleNames(SDF_ModuleName formal,
					       SDF_ModuleName actual)
{
  SDF_Symbols actualParams = SDF_getModuleNameParams(actual);
  SDF_Symbols formalParams = SDF_getModuleNameParams(formal);
  
  return SDF_makeRenamingsFromParameters(formalParams, actualParams);
}

/*}}}  */

/*{{{  static SDF_Symbol SDF_renameSymbol(SDF_Symbol symbol, SDF_Symbol formalParam, SDF_Symbol actualParam) */

static SDF_Symbol SDF_renameSymbol(SDF_Symbol symbol, SDF_Symbol formalParam, SDF_Symbol actualParam)
{
  SDF_Symbol argSymbol;
  SDF_Symbol newArgSymbol;

  symbol = SDF_removeSymbolAnnotations(symbol);

  if (SDF_isEqualSymbol(symbol, formalParam)) {
    return actualParam;
  }
  if (SDF_hasSymbolSymbol(symbol)) {
    argSymbol = SDF_getSymbolSymbol(symbol);
    newArgSymbol = SDF_renameSymbol(argSymbol, formalParam, actualParam);
    symbol = SDF_setSymbolSymbol(symbol, newArgSymbol);
  }
  if (SDF_hasSymbolLeft(symbol)) {
    argSymbol = SDF_getSymbolLeft(symbol);
    newArgSymbol = SDF_renameSymbol(argSymbol, formalParam, actualParam);
    symbol = SDF_setSymbolLeft(symbol, newArgSymbol);
  }
  if (SDF_hasSymbolRight(symbol)) {
    argSymbol = SDF_getSymbolRight(symbol);
    newArgSymbol = SDF_renameSymbol(argSymbol, formalParam, actualParam);
    symbol = SDF_setSymbolRight(symbol, newArgSymbol);
  }
  return symbol;
}

/*}}}  */
/*{{{  static SDF_RenamingList SDF_renameInRenamingList(SDF_RenamingList targets,  */

static SDF_RenamingList SDF_renameInRenamingList(SDF_RenamingList targets, 
                                                 SDF_Symbol formalParam, 
                                                 SDF_Symbol actualParam)
{
  if (SDF_hasRenamingListHead(targets)) {
    SDF_Renaming head = SDF_getRenamingListHead(targets);
    SDF_Symbol toTarget = SDF_getRenamingTo(head);
    SDF_Symbol newToTarget = SDF_renameSymbol(toTarget, 
                                              formalParam, 
                                              actualParam); 

    head = SDF_setRenamingTo(head, newToTarget);
    targets = SDF_setRenamingListHead(targets, head);
  }
  if (SDF_hasRenamingListTail(targets)) {
    SDF_RenamingList tail = SDF_getRenamingListTail(targets);
    SDF_RenamingList newTail = SDF_renameInRenamingList(tail, 
                                                        formalParam, 
                                                        actualParam);

    targets = SDF_setRenamingListTail(targets, newTail);
  }
  return targets;
}

/*}}}  */

/*{{{  SDF_Renamings SDF_renameRenamings(SDF_Renamings sources, SDF_Renamings targets) */

SDF_Renamings SDF_renameRenamings(SDF_Renamings sources, SDF_Renamings targets)
{
  SDF_RenamingList listSources = SDF_getRenamingsList(sources);
  SDF_RenamingList listTargets = SDF_getRenamingsList(targets);

  while (SDF_hasRenamingListHead(listSources)) {
    SDF_Renaming head = SDF_getRenamingListHead(listSources);

    SDF_Symbol fromSource = SDF_getRenamingFrom(head);
    SDF_Symbol toSource = SDF_getRenamingTo(head);

    fromSource = SDF_removeSymbolAnnotations(fromSource);
    toSource = SDF_removeSymbolAnnotations(toSource);
    listTargets = SDF_renameInRenamingList(listTargets, fromSource, toSource);

    if (SDF_hasRenamingListTail(listSources)) {
      listSources  = SDF_getRenamingListTail(listSources);     
    }
    else {
      break;
    }
  }

  return SDF_setRenamingsList(targets, listTargets);
}

/*}}}  */

/*{{{  static SDF_Symbol replaceParametersInParameter(SDF_Symbol localParam, */

static SDF_Symbol replaceParametersInParameter(SDF_Symbol localParam,
                                        SDF_Symbols formalParams,
                                        SDF_Symbols actualParams)
{
  SDF_Symbol formalParam, actualParam;
  SDF_SymbolList formalParamList = SDF_getSymbolsList(formalParams);
  SDF_SymbolList actualParamList = SDF_getSymbolsList(actualParams);
 
  while (SDF_hasSymbolListHead(formalParamList)) {
    formalParam = SDF_getSymbolListHead(formalParamList);
    if (SDF_hasSymbolListHead(actualParamList)) {
      actualParam = SDF_getSymbolListHead(actualParamList);
    }
    else {
      break;
    }
 
    if (SDF_isEqualSymbol(localParam, formalParam)) {
      return actualParam;
    }
 
    if (SDF_hasSymbolListTail(formalParamList)) {
      formalParamList = SDF_getSymbolListTail(formalParamList);
      if (SDF_hasSymbolListTail(actualParamList)) {
        actualParamList = SDF_getSymbolListTail(actualParamList);
      }
      else {
        break;
      }
    }
    else {
      break;
    }
  }
  return localParam;
}

/*}}}  */
/*{{{  static SDF_SymbolList replaceParametersInParameters(SDF_SymbolList localParamList, */

static SDF_SymbolList replaceParametersInParameters(SDF_SymbolList localParamList,
                                             SDF_Symbols formalParams,
                                             SDF_Symbols actualParams)
{
  SDF_Symbol localParam;
  SDF_SymbolList paramListTail;
 
  if (!SDF_isSymbolListEmpty(localParamList)) {
    localParam = SDF_getSymbolListHead(localParamList);
    localParam = replaceParametersInParameter(localParam,
                                              formalParams,
                                              actualParams);
    localParamList = SDF_setSymbolListHead(localParamList, localParam);
 
    if (SDF_hasSymbolListTail(localParamList)) {
      paramListTail = SDF_getSymbolListTail(localParamList);
      paramListTail = replaceParametersInParameters(paramListTail,
                                                    formalParams,
                                                    actualParams);
      localParamList = SDF_setSymbolListTail(localParamList, paramListTail);
    }
  }
  return localParamList;
}

/*}}}  */
/*{{{  static SDF_Import replaceParametersInImport(SDF_Import import, */

static SDF_Import replaceParametersInImport(SDF_Import import,
                                     SDF_Symbols formalParams,
                                     SDF_Symbols actualParams)
{
  SDF_ModuleName moduleName = SDF_getImportModuleName(import);
 
  if (SDF_isModuleNameParameterized(moduleName)) {
    SDF_Symbols localParams = SDF_getModuleNameParams(moduleName);
 
    if (SDF_isEqualSymbols(localParams, formalParams)) {
      moduleName = SDF_setModuleNameParams(moduleName, actualParams);
    }
    else {
      SDF_SymbolList localParamList = SDF_getSymbolsList(localParams);
      localParamList = replaceParametersInParameters(localParamList,
                                                     formalParams,
                                                     actualParams);
      localParams = SDF_setSymbolsList(localParams, localParamList);
      moduleName = SDF_setModuleNameParams(moduleName, localParams);
    }
    import = SDF_setImportModuleName(import, moduleName);
  }
  return import;
}

/*}}}  */
/*{{{  SDF_ImportList SDF_replaceParametersInImportList(SDF_ImportList importList, */

SDF_ImportList SDF_replaceParametersInImportList(SDF_ImportList importList,
                                             SDF_Symbols formalParams,
                                             SDF_Symbols actualParams)
{
  SDF_Import head, newHead;
  SDF_ImportList tail, newTail;
 
  if (SDF_hasImportListHead(importList)) {
    head = SDF_getImportListHead(importList);
 
    newHead = replaceParametersInImport(head, formalParams, actualParams);
    importList = SDF_setImportListHead(importList, newHead);
 
    if (SDF_hasImportListTail(importList)) {
      tail = SDF_getImportListTail(importList);
 
      newTail = SDF_replaceParametersInImportList(tail, formalParams, 
						  actualParams);
      importList = SDF_setImportListTail(importList, newTail);
    }
  }
  return importList;
}

/*}}}  */
/*{{{  SDF_ImportList SDF_renameParametersInImportList(SDF_ModuleName moduleName, */

SDF_ImportList SDF_renameParametersInImportList(SDF_ModuleName moduleName,
                                            SDF_Module sdfModule,
                                            SDF_ImportList importList)
{
  SDF_Symbols actualParams = SDF_getModuleNameParams(moduleName);
  SDF_Symbols formalParams = SDF_getModuleNameParams(
                               SDF_getModuleModuleName(sdfModule));
 
  return SDF_replaceParametersInImportList(importList, formalParams, actualParams);
}

/*}}}  */
