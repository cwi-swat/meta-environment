#include "SDF-utils.h"

/*{{{  collect_sorts(SDF_Grammar grammar, ATermList *sorts) */

static void
collect_sorts(SDF_Grammar grammar, ATermList *sorts)
{
  if (SDF_isGrammarSorts(grammar)) {
    SDF_Symbols symbols = SDF_getGrammarSymbols(grammar);
    SDF_SymbolList symbolList = SDF_getSymbolsList(symbols);

    while (!SDF_isSymbolListEmpty(symbolList)) {
      SDF_Symbol symbol = SDF_getSymbolListHead(symbolList);

      if (SDF_isSymbolSort(symbol)) {
	*sorts = ATinsert(*sorts, SDF_makeTermFromSymbol(symbol));
      }

      if (SDF_isSymbolListSingle(symbolList)) {
	break;
      }
      symbolList = SDF_getSymbolListTail(symbolList);
    }
  }
}

/*}}}  */
/*{{{  SDFgetSorts(SDF_Module module) */

ATermList
SDFgetSorts(SDF_Module module)
{
  ATermList sorts = ATempty;

  SDFforeachGrammarInModule(module,
			    (SDFGrammarFunc)collect_sorts,
			    &sorts);

  return sorts;
}

/*}}}  */
