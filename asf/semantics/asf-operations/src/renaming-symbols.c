#include <string.h> 
#include <MEPT-utils.h>
#include <SDFME-utils.h>
#include <ASFME-utils.h>

#include "renaming-symbols.h"

/*{{{  ASF_CondEquationList replaceParameterInEquations(ASF_CondEquationList eqsList, */

static
ASF_CondEquationList replaceParameterInEquations(ASF_CondEquationList eqsList,
                                                 PT_Symbol formalParam,
                                                 PT_Symbol actualParam)
{
  if (ASF_hasCondEquationListHead(eqsList)) {
    ASF_CondEquation eq = ASF_getCondEquationListHead(eqsList);
    ASF_CondEquation newEq = ASF_makeCondEquationFromTerm(
                               PT_makeTermFromTree(
                                 PT_renameInTree(
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

/*}}}  */
/*{{{  ASF_CondEquationList replaceParametersInEquations(ASF_CondEquationList asfTree, */

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
                  SDFSymbolToPtSymbol(formalParam),
                  SDFSymbolToPtSymbol(actualParam));
    }
    else {
      return asfTree;
    }

    if (SDF_hasSymbolListTail(formalParamList)) {
      formalParamList = SDF_getSymbolListTail(formalParamList);
      if (SDF_hasSymbolListTail(actualParamList)) {
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

/*}}}  */
/*{{{  ASF_CondEquationList renameParametersInEquations(PT_Tree sdfTree,  */

ASF_CondEquationList renameParametersInEquations(SDF_ModuleName moduleName,
                                                 ASF_CondEquationList asfTree, 
                                                 SDF_Symbols actualParams)
{
  if (SDF_isModuleNameParameterized(moduleName)) {
    SDF_Symbols formalParams = SDF_getModuleNameParams(moduleName);

    return replaceParametersInEquations(asfTree, formalParams, actualParams);
  }
  else {
    return asfTree;
  }
}

/*}}}  */
/*{{{  ASF_CondEquationList renameSymbolsInEquations(ASF_CondEquationList asfTree,  */

ASF_CondEquationList renameSymbolsInEquations(ASF_CondEquationList asfTree, 
                                              SDF_Renamings renamings)
{
  /*SDF_RenamingList prodRenamingList = SDF_getRenamingsList(renamings);*/
  SDF_RenamingList symbolRenamingList = SDF_getRenamingsList(renamings);
  SDF_Renaming renaming;
  SDF_Symbol fromSymbol, toSymbol;
  /*SDF_Production fromProd, toProd;*/

/*
  while (SDF_hasRenamingListHead(prodRenamingList)) {
    renaming = SDF_getRenamingListHead(prodRenamingList);
    if (SDF_isRenamingProduction(renaming)) {
      fromProd = SDF_getRenamingFromProd(renaming);
      toProd = SDF_getRenamingToProd(renaming);

      asfTree = replaceProductionInEquations(asfTree, 
                  SDFProductionToPtProduction(fromProd),
                  SDFProductionToPtProduction(toProd));
    }

    if (SDF_hasRenamingListTail(prodRenamingList)) {
      prodRenamingList = SDF_getRenamingListTail(prodRenamingList);
    }
    else {
      break;
    }
  }
*/
  while (SDF_hasRenamingListHead(symbolRenamingList)) {
    renaming = SDF_getRenamingListHead(symbolRenamingList);
    if (SDF_isRenamingSymbol(renaming)) {
      fromSymbol = SDF_getRenamingFrom(renaming);
      toSymbol = SDF_getRenamingTo(renaming);

      asfTree = replaceParameterInEquations(asfTree, 
                  SDFSymbolToPtSymbol(fromSymbol),
                  SDFSymbolToPtSymbol(toSymbol));
    }

    if (SDF_hasRenamingListTail(symbolRenamingList)) {
      symbolRenamingList = SDF_getRenamingListTail(symbolRenamingList);
    }
    else {
      break;
    }
  }
  return asfTree;
}

/*}}}  */
