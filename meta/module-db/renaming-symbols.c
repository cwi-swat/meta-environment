#include "module-db.h"

static
PT_Tree renameInTree(PT_Tree tree,
                     PT_Symbol formalParam,
                     PT_Symbol actualParam);
static
PT_Symbol renameInSymbol(PT_Symbol symbol,
                         PT_Symbol formalParam,
                         PT_Symbol actualParam);

static
PT_Symbols renameInSymbols(PT_Symbols symbols,
                           PT_Symbol formalParam,
                           PT_Symbol actualParam)
{
  if (PT_isSymbolsEmpty(symbols)) {
    return symbols;
  }
  else {
    PT_Symbol head = PT_getSymbolsHead(symbols);
    PT_Symbols tail = PT_getSymbolsTail(symbols);
   
    PT_Symbol newHead = renameInSymbol(head, formalParam, actualParam);
    PT_Symbols newTail = renameInSymbols(tail, formalParam, actualParam);
    return PT_setSymbolsHead(PT_setSymbolsTail(symbols, newTail), newHead);
  }
}

static 
PT_Symbol renameInSymbol(PT_Symbol symbol,
                         PT_Symbol formalParam,
                         PT_Symbol actualParam)
{
  if (PT_isEqualSymbol(symbol, formalParam)) {
/*
ATwarning("symbol = %t, formalParam = %t, actualParam = %t\n", 
          symbol, formalParam, actualParam);
*/
    return actualParam;
  }
  if (PT_hasSymbolSymbols(symbol)) {
    PT_Symbols args = PT_getSymbolSymbols(symbol);

    PT_Symbols newArgs = renameInSymbols(args, formalParam, actualParam);
 
    symbol = PT_setSymbolSymbols(symbol, newArgs);
  }
  if (PT_hasSymbolSymbol(symbol)) {
    PT_Symbol arg = PT_getSymbolSymbol(symbol);

    PT_Symbol newArg = renameInSymbol(arg, formalParam, actualParam);
 
    symbol = PT_setSymbolSymbol(symbol, newArg);
  }
  if (PT_hasSymbolLhs(symbol)) {
    PT_Symbol arg = PT_getSymbolLhs(symbol);

    PT_Symbol newArg = renameInSymbol(arg, formalParam, actualParam);
 
    symbol = PT_setSymbolLhs(symbol, newArg);
  }
  if (PT_hasSymbolRhs(symbol)) {
    PT_Symbol arg = PT_getSymbolRhs(symbol);

    PT_Symbol newArg = renameInSymbol(arg, formalParam, actualParam);
 
    symbol = PT_setSymbolRhs(symbol, newArg);
  }
  if (PT_hasSymbolSeparator(symbol)) {
    PT_Symbol arg = PT_getSymbolSeparator(symbol);

    PT_Symbol newArg = renameInSymbol(arg, formalParam, actualParam);
 
    symbol = PT_setSymbolSeparator(symbol, newArg);
  }
  return symbol;
}

static
PT_Args renameInArgs(PT_Args trees,
                     PT_Symbol formalParam,
                     PT_Symbol actualParam)
{
  if (PT_isArgsEmpty(trees)) {
    return trees;
  }
  else {
    PT_Tree head = PT_getArgsHead(trees);
    PT_Args tail = PT_getArgsTail(trees);
   
    PT_Tree newHead = renameInTree(head, formalParam, actualParam);
    PT_Args newTail = renameInArgs(tail, formalParam, actualParam);
    return PT_setArgsHead(PT_setArgsTail(trees, newTail), newHead);
  }
}

static
PT_Production renameInProduction(PT_Production prod,
                                 PT_Symbol formalParam,
                                 PT_Symbol actualParam)
{
  if (PT_isProductionDefault(prod)) {
    PT_Symbols lhs = PT_getProductionLhs(prod);
    PT_Symbol  rhs = PT_getProductionRhs(prod);
  
    PT_Symbols newLhs = renameInSymbols(lhs, formalParam, actualParam);
    PT_Symbol newRhs = renameInSymbol(rhs, formalParam, actualParam);

    return PT_setProductionRhs(PT_setProductionLhs(prod, newLhs), newRhs);
  }
  else {
    PT_Symbol  rhs = PT_getProductionRhs(prod);

    PT_Symbol newRhs = renameInSymbol(rhs, formalParam, actualParam);

    return PT_setProductionRhs(prod, newRhs);
  }
}

static
PT_Tree renameInTree(PT_Tree tree,
                     PT_Symbol formalParam,
                     PT_Symbol actualParam)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Args       args = PT_getTreeArgs(tree);
  
    PT_Production newProd = renameInProduction(prod, formalParam, actualParam);
    PT_Args       newArgs = renameInArgs(args, formalParam, actualParam);
  
    return PT_setTreeArgs(PT_setTreeProd(tree, newProd), newArgs);
  }
  else if (PT_isTreeLit(tree)) {
    if (PT_isSymbolLit(formalParam)) {
      char *localStr = PT_getTreeString(tree);
      char *formalStr = PT_getSymbolString(formalParam);

      if (strcmp(localStr, formalStr) == 0) {
        return PT_setTreeString(tree, PT_getSymbolString(actualParam));
      }
    }
    return tree;
  }
  else {
    return tree;
  }
}

static
ASF_CondEquationList replaceParameterInEquations(ASF_CondEquationList eqsList,
                                                 PT_Symbol formalParam,
                                                 PT_Symbol actualParam)
{
  if (ASF_hasCondEquationListHead(eqsList)) {
    ASF_CondEquation eq = ASF_getCondEquationListHead(eqsList);
    ASF_CondEquation newEq = ASF_makeCondEquationFromTerm(
                               PT_makeTermFromTree(
                                 renameInTree(
                                   PT_makeTreeFromTerm(
                                     ASF_makeTermFromCondEquation(eq)), 
                                   formalParam, actualParam)));

    eqsList = ASF_setCondEquationListHead(eqsList, newEq);
  }
  if (ASF_hasCondEquationListTail(eqsList)) {
    ASF_CondEquationList tail = ASF_getCondEquationListTail(eqsList);
    ASF_CondEquationList newTail = replaceParameterInEquations(tail,
                                                               formalParam,
                                                               actualParam);

    eqsList = ASF_setCondEquationListTail(eqsList, newTail);
  }
  return eqsList;
}

static
ASF_CondEquationList replaceParametersInEquations(ASF_CondEquationList asfTree,
                                                  SDF_Symbols formalParams,
                                                  SDF_Symbols actualParams)
{
  SDF_SymbolList formalParamList = SDF_getSymbolsList(formalParams);
  SDF_SymbolList actualParamList = SDF_getSymbolsList(actualParams);
  SDF_Symbol formalParam, actualParam;

  while (SDF_hasSymbolListHead(formalParamList)) {
    formalParam = SDF_getSymbolListHead(formalParamList);
    if (SDF_hasSymbolListHead(actualParamList)) {
      actualParam = SDF_getSymbolListHead(actualParamList);
      asfTree = replaceParameterInEquations(asfTree, 
                  SDFsymbol2PtSymbol(formalParam),
                  SDFsymbol2PtSymbol(actualParam));
    }
    else {
      return asfTree;
    }

    if (SDF_hasSymbolListTail(formalParamList)) {
      formalParamList = SDF_getSymbolListTail(formalParamList);
      if (SDF_hasSymbolListTail(formalParamList)) {
        actualParamList = SDF_getSymbolListTail(actualParamList);
      }
      else {
        return asfTree;
      }
    }
    else {
      if (!SDF_hasSymbolListTail(formalParamList)) {
        break;
      }
      else {
        return asfTree;
      }
    }
  }
  return asfTree;
}

ASF_CondEquationList renameParametersInEquations(PT_Tree sdfTree, 
                                                 ASF_CondEquationList asfTree, 
                                                 SDF_Symbols actualParams)
{
  SDF_ModuleName moduleName;

  moduleName = SDF_getModuleModuleName(
                 SDF_makeModuleFromTerm(
                   PT_makeTermFromTree(sdfTree)));
  if (SDF_isModuleNameParameterized(moduleName)) {
    SDF_Symbols formalParams = SDF_getModuleNameParams(moduleName);
    return replaceParametersInEquations(asfTree, formalParams, actualParams);
  }
  else {
    return asfTree;
  }
}

ASF_CondEquationList renameSymbolsInEquations(ASF_CondEquationList asfTree, 
                                              SDF_Renamings renamings)
{
  SDF_RenamingList renamingList = SDF_getRenamingsList(renamings);
  SDF_Renaming renaming;
  SDF_Symbol fromSymbol, toSymbol;

  while (SDF_hasRenamingListHead(renamingList)) {
    renaming = SDF_getRenamingListHead(renamingList);
    if (SDF_isRenamingSymbol(renaming)) {
      fromSymbol = SDF_getRenamingFrom(renaming);
      toSymbol = SDF_getRenamingTo(renaming);

      asfTree = replaceParameterInEquations(asfTree, 
                  SDFsymbol2PtSymbol(fromSymbol),
                  SDFsymbol2PtSymbol(toSymbol));
    }
    else {
      ATwarning("Production renaming not yet supported!\n");
    }

    if (SDF_hasRenamingListTail(renamingList)) {
      renamingList = SDF_getRenamingListTail(renamingList);
    }
    else {
      break;
    }
  }
  return asfTree;
}

static 
SDF_Symbol replaceParametersInParameter(SDF_Symbol localParam,
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
/*
ATwarning("formalParam: %t\nactualParam: %t\nlocalParam: %t\n\n",
          formalParam, actualParam, localParam);
*/
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

static 
SDF_SymbolList replaceParametersInParameters(SDF_SymbolList localParamList,
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

static 
SDF_Import replaceParametersInImport(SDF_Import import,
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

static
SDF_ImportList replaceParametersInImportList(SDF_ImportList importList,
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

      newTail = replaceParametersInImportList(tail, formalParams, actualParams);
      importList = SDF_setImportListTail(importList, newTail);
    }
  }
  return importList;
}

SDF_ImportList renameParametersInImportList(SDF_ModuleName moduleName, 
                                            PT_Tree sdfTree,
                                            SDF_ImportList importList)
{
  SDF_Symbols actualParams = SDF_getModuleNameParams(moduleName);
  SDF_Symbols formalParams = SDF_getModuleNameParams(
                               SDF_getModuleModuleName(
                                 SDF_makeModuleFromTerm(
                                   PT_makeTermFromTree(sdfTree))));
  return replaceParametersInImportList(importList, formalParams, actualParams);
}
