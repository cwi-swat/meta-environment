#include "SDF-utils.h"

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
        newLexProds = SDF_makeProductionListMany(lexProd, "", newLexProds);
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
