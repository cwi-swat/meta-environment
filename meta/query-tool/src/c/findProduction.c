/* $Id$ */

#include <stdio.h>
#include <assert.h>

#include <PT2SDF.h>

#include "findProduction.h"

/*{{{  static ATbool symbolListsMatch(SDF_SymbolList s1, SDF_SymbolList s2) */

static ATbool symbolListsMatch(SDF_SymbolList s1, SDF_SymbolList s2)
{
  SDF_Symbol symbols1;
  SDF_Symbol symbols2;

  while (!SDF_isSymbolListEmpty(s1)) {
    if (SDF_isSymbolListEmpty(s2)) {
      return ATfalse;
    }
    symbols1 = SDF_getSymbolListHead(s1);
    symbols2 = SDF_getSymbolListHead(s2);
  }

  return ATfalse;
}

/*}}}  */
/*{{{  static ATbool productionsMatch(SDF_Production p1, SDF_Production p2) */

static ATbool productionsMatch(SDF_Production p1, SDF_Production p2)
{
  SDF_Symbol rhs1, rhs2;

  rhs1 = SDF_getProductionResult(p1);
  rhs2 = SDF_getProductionResult(p2);

  if (!SDF_isEqualSymbol(rhs1, rhs2)) {
    return ATfalse;
  }

  return symbolListsMatch(SDF_getSymbolsList(SDF_getProductionSymbols(p1)),
			  SDF_getSymbolsList(SDF_getProductionSymbols(p2)));
}

/*}}}  */
/*{{{  static ATbool findProductionInModule(SDF_Production needle, SDF_Module haystack) */

static ATbool findProductionInModule(SDF_Production needle, SDF_Module haystack)
{
  ATbool found = ATfalse;
  SDF_ProductionList productionList = SDF_getModuleProductions(haystack);

  while (!SDF_isProductionListEmpty(productionList) && !found) {
    SDF_Production suspect = SDF_getProductionListHead(productionList);

    found = productionsMatch(suspect, needle);

    if (SDF_hasProductionListTail(productionList)) {
      productionList = SDF_getProductionListTail(productionList);
    }
    else {
      break;
    }
  }

  return found;
}

/*}}}  */
/*{{{  ATbool queryProductionInModule(SDF_Module sdfModule, PT_ParseTree parseTree) */

ATbool queryProductionInModule(SDF_Module sdfModule, PT_ParseTree parseTree)
{
  PT_Tree ptTree;
  PT_Production ptProduction;
  SDF_Production sdfProduction;

  /* Useless when SDFME/PT are compiled with -DDISABLE_DYNAMIC_CHECKING */
  assert(SDF_isValidModule(sdfModule));
  assert(PT_isValidParseTree(parseTree));

  ptTree = PT_getParseTreeTree(parseTree);
  ptProduction = PT_getTreeProd(ptTree);

  sdfProduction = PTProductionToSDFProduction(ptProduction);
  assert(SDF_isValidProduction(sdfProduction));

  return findProductionInModule(sdfProduction, sdfModule);
}

/*}}}  */
