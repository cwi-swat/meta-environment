/* $Id$ */

#include <stdio.h>
#include <assert.h>

#include <PT2SDF.h>

#include "findSortDefinition.h"

/*{{{  static ATbool symbolInModule(SDF_Module sdfModule, SDF_Symbol sdfSymbol) */

static ATbool symbolInModule(SDF_Module sdfModule, SDF_Symbol sdfSymbol)
{
  ATbool found = ATfalse;
  SDF_ProductionList sdfProductions = SDF_getModuleProductions(sdfModule);

  while (!SDF_isProductionListEmpty(sdfProductions) && !found) {
    SDF_Production sdfProduction = SDF_getProductionListHead(sdfProductions);

    SDF_Symbol rhs = SDF_getProductionResult(sdfProduction);

    found = SDF_isEqualSymbol(rhs, sdfSymbol);

    if (found) {
      ATwarning("rhs = %t\n", rhs);
    }

    if (SDF_hasProductionListTail(sdfProductions)) {
      sdfProductions = SDF_getProductionListTail(sdfProductions);
    }
    else {
      break;
    }
  }
  return found;
}

/*}}}  */
/*{{{  ATbool querySortInModule(SDF_Module sdfModule, PT_ParseTree parseTree) */

ATbool querySortInModule(SDF_Module sdfModule, PT_ParseTree parseTree)
{
  PT_Tree tree;
  PT_Production prod;
  PT_Symbol rhs;
  SDF_Symbol sdfSymbol;

  /* Useless when SDFME/PT are compiled with -DDISABLE_DYNAMIC_CHECKING */
  assert(SDF_isValidModule(sdfModule));
  assert(PT_isValidParseTree(parseTree));

  tree = PT_getParseTreeTree(parseTree);
  prod = PT_getTreeProd(tree);
  rhs = PT_getProductionRhs(prod);

  sdfSymbol = PTSymbolToSDFSymbol(rhs);
  assert(SDF_isValidSymbol(sdfSymbol));
  
  return symbolInModule(sdfModule, sdfSymbol);
}

/*}}}  */
