#include "SDF-utils.h"

/*{{{  collect_lex_prods(SDF_Grammar grammar, ATermList *lexProds) */

static void
collect_lex_prods(SDF_Grammar grammar, ATermList *lexProds)
{
  if (SDF_isGrammarLexicalSyntax(grammar)) {
    SDF_Productions grammarProds = SDF_getGrammarProductions(grammar);
    SDF_ProductionList prods = SDF_getProductionsList(grammarProds);

    while (!SDF_isProductionListEmpty(prods)) {
      SDF_Production prod = SDF_getProductionListHead(prods);

      if (SDF_isProductionProd(prod)) {
	*lexProds = ATinsert(*lexProds, SDF_makeTermFromProduction(prod));
      }

      if (SDF_isProductionListSingle(prods)) {
	break;
      }
      prods = SDF_getProductionListTail(prods);
    }
  }
}

/*}}}  */
/*{{{  SDFgetLexicalProductions(SDF_Module module) */

ATermList
SDFgetLexicalProductions(SDF_Module module)
{
  ATermList lexProds = ATempty;

  SDFforeachGrammarInModule(module,
			    (SDFGrammarFunc)collect_lex_prods,
			    &lexProds);

  return lexProds;
}

/*}}}  */
