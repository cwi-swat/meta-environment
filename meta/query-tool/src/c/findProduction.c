/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <assert.h>

#include <PT2SDF.h>

#include "findProduction.h"

/*}}}  */
/*{{{  types */

typedef ATbool (*predicate)(SDF_Production, SDF_Production);

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
/*{{{  static ATbool lexicalProductionsMatch(SDF_Production p1, SDF_Production p2) */

static ATbool lexicalProductionsMatch(SDF_Production p1, SDF_Production p2)
{
  SDF_Symbol rhs1, rhs2;

  rhs1 = SDF_getProductionResult(p1);
  rhs2 = SDF_getProductionResult(p2);

  if (SDF_isEqualSymbol(SDF_removeSymbolAnnotations(rhs1), rhs2)) {
    return ATtrue;
  }
  else {
    return ATfalse;
  }
}

/*}}}  */

/*{{{ static SDF_Production findProductionInModule(needle, haystack, predicate) */

static SDF_Production findProductionInModule(SDF_Production needle, SDF_Module haystack, predicate pred)
{
  SDF_ProductionList productionList = SDF_getModuleProductions(haystack);

  while (!SDF_isProductionListEmpty(productionList)) {
    SDF_Production suspect = SDF_getProductionListHead(productionList);

    if (pred(suspect, needle)) {
      return suspect;
    }

    if (SDF_hasProductionListTail(productionList)) {
      productionList = SDF_getProductionListTail(productionList);
    }
    else {
      break;
    }
  }

  return NULL;
}

/*}}}  */

/*{{{  ATbool queryProductionInModule(SDF_Module sdfModule, PT_ParseTree parseTree) */

ATerm queryProductionInModule(SDF_Module sdfModule, PT_ParseTree parseTree)
{
  PT_Tree ptTree;
  PT_Production ptProduction;
  SDF_Production sdfProduction;
  SDF_Production found = NULL;
  ATerm pos = NULL;
  predicate pred;

  /* Useless when SDFME/PT are compiled with -DDISABLE_DYNAMIC_CHECKING */
  assert(SDF_isValidModule(sdfModule));
  assert(PT_isValidParseTree(parseTree));

  ptTree = PT_getParseTreeTree(parseTree);
  ptProduction = PT_getTreeProd(ptTree);

  if (PT_isProductionDefault(ptProduction)) {
    sdfProduction = PTProductionToSDFProduction(ptProduction);
    assert(SDF_isValidProduction(sdfProduction));

    if (PT_isLexicalInjectionProd(ptProduction)) {
      pred = lexicalProductionsMatch;
    }
    else {
      pred = productionsMatch;
    }
    found = findProductionInModule(sdfProduction, sdfModule, pred);
  }

  if (found != NULL) {
    pos = ATgetAnnotation(SDF_ProductionToTerm(found), ATmake("pos-info"));
  }

  return pos;
}

/*}}}  */
