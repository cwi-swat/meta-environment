#include <SDFME-utils.h>

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

SDF_Renamings SDF_makeRenamingsFromModuleNames(SDF_ModuleName formal,
					       SDF_ModuleName actual)
{
  SDF_Symbols actualParams = SDF_getModuleNameParams(actual);
  SDF_Symbols formalParams = SDF_getModuleNameParams(formal);
  
  return SDF_makeRenamingsFromParameters(formalParams, actualParams);
}

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
