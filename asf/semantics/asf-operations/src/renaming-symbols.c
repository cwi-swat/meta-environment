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
/*{{{  ASF_CondEquationList renameSymbolsInEquations(ASF_CondEquationList asfTree,  */

ASF_CondEquationList renameSymbolsInEquations(ASF_CondEquationList asfTree, 
                                              SDF_Renamings renamings)
{
  /*SDF_RenamingList prodRenamingList = SDF_getRenamingsList(renamings);*/
  SDF_RenamingList symbolRenamingList = SDF_getRenamingsList(renamings);
  SDF_Renaming renaming;
  SDF_Symbol fromSymbol, toSymbol;

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
