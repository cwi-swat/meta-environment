#include "SDFME-utils.h"

/*{{{  collect_sorts(SDF_Grammar grammar, SDF_SymbolList *sorts) */

static void
collect_sorts(SDF_Grammar grammar, SDF_SymbolList *sorts)
{
  
  if (SDF_isGrammarSorts(grammar)) {
    SDF_Symbols symbols = SDF_getGrammarSymbols(grammar);
    SDF_SymbolList symbolList = SDF_getSymbolsList(symbols);
    while (!SDF_isSymbolListEmpty(symbolList)) {
      SDF_Symbol symbol = SDF_getSymbolListHead(symbolList);

      if (SDF_isSymbolSort(symbol)) {
        if (SDF_isSymbolListEmpty(*sorts)) {
	  *sorts = SDF_makeSymbolListSingle(symbol);
        }
        else {
	  *sorts = SDF_makeSymbolListMany(symbol, 
                                          SDF_makeLayoutEmpty(),
                                          *sorts);
        }
      }

      if (SDF_isSymbolListSingle(symbolList)) {
	break;
      }
      symbolList = SDF_getSymbolListTail(symbolList);
    }
  }

}

/*}}}  */
/*{{{  SDF_getModuleSorts(SDF_Module module) */

SDF_SymbolList
SDF_getModuleSorts(SDF_Module module)
{
  SDF_SymbolList sorts = SDF_makeSymbolListEmpty();

  SDFforeachGrammarInModule(module,
			    (SDFGrammarFunc)collect_sorts,
			    (void *)&sorts);

  return sorts;
}

/*}}}  */
