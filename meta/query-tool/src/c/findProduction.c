/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <assert.h>

#include <PT2SDF.h>

#include "findProduction.h"

/*}}}  */

/*{{{  static ATbool symbolListsMatch(SDF_SymbolList s1, SDF_SymbolList s2) */

static ATbool symbolListsMatch(SDF_SymbolList s1, SDF_SymbolList s2)
{
  SDF_Symbol symbol1;
  SDF_Symbol symbol2;
  ATbool equalLists = ATtrue;

  while (!SDF_isSymbolListEmpty(s1) && equalLists) {
    if (SDF_isSymbolListEmpty(s2)) {
      equalLists = ATfalse;
    }
    symbol1 = SDF_getSymbolListHead(s1);
    symbol2 = SDF_getSymbolListHead(s2);

    if (SDF_isEqualSymbol(SDF_removeSymbolAnnotations(symbol1), symbol2)) {
      equalLists = ATtrue;
    }
/*
    else if (SDF_isSymbolLit(symbol1) &&
	     SDF_isSymbolLit(symbol2)) {
      equalLists = ATtrue;
    }
*/
    else {
      equalLists = ATfalse;
    }

    if (SDF_hasSymbolListTail(s1)) {
      s1 = SDF_getSymbolListTail(s1);
      if (SDF_hasSymbolListTail(s2)) {
        s2 = SDF_getSymbolListTail(s2);
      }
      else {
        equalLists = ATfalse;
      }
    }
    else {
      if (SDF_hasSymbolListTail(s2)) {
        equalLists = ATfalse;
      }
      break;
    }
  }

  return equalLists;
}

/*}}}  */
/*{{{  static ATbool productionsMatch(SDF_Production p1, SDF_Production p2) */

static ATbool productionsMatch(SDF_Production p1, SDF_Production p2)
{
  SDF_Symbol rhs1, rhs2;

  rhs1 = SDF_getProductionResult(p1);
  rhs2 = SDF_getProductionResult(p2);

  if (!SDF_isEqualSymbol(SDF_removeSymbolAnnotations(rhs1), rhs2)) {
    return ATfalse;
  }

  return symbolListsMatch(SDF_getSymbolsList(SDF_getProductionSymbols(p1)),
			  SDF_getSymbolsList(SDF_getProductionSymbols(p2)));
}

/*}}}  */
/*{{{  static ATerm findProductionInModule(SDF_Production needle, SDF_Module haystack) */

static ATerm findProductionInModule(SDF_Production needle, SDF_Module haystack)
{
  ATbool found = ATfalse;
  ATerm posInfo = NULL;
  SDF_ProductionList productionList = SDF_getModuleProductions(haystack);

  while (!SDF_isProductionListEmpty(productionList) && !found) {
    SDF_Production suspect = SDF_getProductionListHead(productionList);

    found = productionsMatch(suspect, needle);

    if (found) {
      posInfo = ATgetAnnotation(SDF_ProductionToTerm(suspect), 
                                ATmake("pos-info"));
    }

    if (SDF_hasProductionListTail(productionList)) {
      productionList = SDF_getProductionListTail(productionList);
    }
    else {
      break;
    }
  }

  return posInfo;
}

/*}}}  */
/*{{{  ATbool queryProductionInModule(SDF_Module sdfModule, PT_ParseTree parseTree) */

ATerm queryProductionInModule(SDF_Module sdfModule, PT_ParseTree parseTree)
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
