#include "SDFME-utils.h"

/*{{{  collect_lex_prods(SDF_Grammar grammar, SDF_Productions *lexProds) */

static void
collect_lex_prods(SDF_Grammar grammar, SDF_ProductionList *lexProds)
{
  if (SDF_isGrammarLexicalSyntax(grammar)) {
    SDF_Productions grammarProds = SDF_getGrammarProductions(grammar);
    SDF_ProductionList prods = SDF_getProductionsList(grammarProds);

    *lexProds = SDF_concatProductionList(*lexProds, prods);
  }
}

/*}}}  */
/*{{{  collect_all_prods(SDF_Grammar grammar, SDF_Productions *allProds) */

static void
collect_all_prods(SDF_Grammar grammar, SDF_ProductionList *allProds)
{
  if (SDF_hasGrammarProductions(grammar)) {
    SDF_Productions grammarProds = SDF_getGrammarProductions(grammar);
    SDF_ProductionList prods = SDF_getProductionsList(grammarProds);

    *allProds = SDF_concatProductionList(*allProds, prods);
  }
}

/*}}}  */

/*{{{  SDF_getModuleLexicalProductions(SDF_Module module) */

SDF_ProductionList 
SDF_getModuleLexicalProductions(SDF_Module module)
{
  SDF_ProductionList lexProds = SDF_makeProductionListEmpty();

  SDFforeachGrammarInModule(module,
			    (SDFGrammarFunc)collect_lex_prods,
			    (void *)&lexProds);

  return lexProds;
}

/*}}}  */

/*{{{  SDF_getModuleProductions(SDF_Module module) */

SDF_ProductionList 
SDF_getModuleProductions(SDF_Module module)
{
  SDF_ProductionList prods = SDF_makeProductionListEmpty();

  SDFforeachGrammarInModule(module,
			    (SDFGrammarFunc)collect_all_prods,
			    (void *)&prods);

  return prods;
}

/*}}}  */
/*{{{  SDF_getModuleLexicalProductionsGivenSymbol(SDF_Symbol symbol,
                                                  SDF_Module module) */

SDF_ProductionList
SDF_getModuleLexicalProductionsGivenSymbol(SDF_Symbol symbol,
                                           SDF_Module module)
{
  SDF_ProductionList lexProds = SDF_getModuleLexicalProductions(module);
  SDF_ProductionList newLexProds = SDF_makeProductionListEmpty();

  while (SDF_hasProductionListHead(lexProds)) {
    SDF_Production lexProd = SDF_getProductionListHead(lexProds);

    SDF_Symbol rhsSymbol = SDF_getProductionResult(lexProd);

    if (SDF_isEqualSymbol(symbol, rhsSymbol)) {
      if (SDF_isProductionListEmpty(newLexProds)) {
        newLexProds = SDF_makeProductionListSingle(lexProd);
      }
      else {
        newLexProds = SDF_makeProductionListMany(lexProd, 
                                                 SDF_makeLayoutEmpty(), 
                                                 newLexProds);
      }
    }
    if (SDF_isProductionListSingle(lexProds)) {
      break;
    }
    lexProds = SDF_getProductionListTail(lexProds);
  }
  return newLexProds;
}

/*}}}  */
/*{{{  collect_cf_prods(SDF_Grammar grammar, SDF_Productions *cfProds) */

static void
collect_cf_prods(SDF_Grammar grammar, SDF_ProductionList *cfProds)
{
  if (SDF_isGrammarContextFreeSyntax(grammar)) {
    SDF_Productions grammarProds = SDF_getGrammarProductions(grammar);
    SDF_ProductionList prods = SDF_getProductionsList(grammarProds);

    *cfProds = SDF_concatProductionList(*cfProds, prods);
  }
}

/*}}}  */
/*{{{  SDF_getModuleContextFreeProductions(SDF_Module module) */

SDF_ProductionList 
SDF_getModuleContextFreeProductions(SDF_Module module)
{
  SDF_ProductionList cfProds = SDF_makeProductionListEmpty();

  SDFforeachGrammarInModule(module,
			    (SDFGrammarFunc)collect_cf_prods,
			    (void *)&cfProds);

  return cfProds;
}

/*}}}  */
/*{{{  collect_prods(SDF_Grammar grammar, SDF_Productions *prods) */

static void
collect_prods(SDF_Grammar grammar, SDF_ProductionList *prods)
{
  if (SDF_isGrammarSyntax(grammar)) {
    SDF_Productions grammarProds = SDF_getGrammarProductions(grammar);
    SDF_ProductionList lexProds = SDF_getProductionsList(grammarProds);

    *prods = SDF_concatProductionList(*prods, lexProds);
  }
}

/*}}}  */
/*{{{  SDF_getModuleProductions(SDF_Module module) */

SDF_ProductionList 
SDF_getGrammarKernelProductions(SDF_Grammar grammar)
{
  SDF_ProductionList prods = SDF_makeProductionListEmpty();

  SDFforeachGrammar(grammar,
		    (SDFGrammarFunc)collect_prods,
		    (void *)&prods);

  return prods;
}

/*}}}  */

