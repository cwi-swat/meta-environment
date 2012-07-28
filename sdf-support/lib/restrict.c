#include "SDFME-utils.h"

/*{{{  static void collect_restricts(SDF_Grammar grammar, SDF_RestrictionList *restricts) */

static void collect_restricts(SDF_Grammar grammar, SDF_RestrictionList *restricts)
{
  if (SDF_isGrammarRestrictions(grammar)) {
    SDF_Restrictions grammarPrios = SDF_getGrammarRestrictions(grammar);
    SDF_RestrictionList kernelPrios = SDF_getRestrictionsList(grammarPrios);

    *restricts = SDF_concatRestrictionList(*restricts,
					   SDF_makeLayoutSpace(),
					   kernelPrios);
  }
}

/*}}}  */

/*{{{  SDF_getModuleRestrictions(SDF_Module module) */

SDF_RestrictionList 
SDF_getGrammarKernelRestrictions(SDF_Grammar grammar)
{
  SDF_RestrictionList restricts = SDF_makeRestrictionListEmpty();

  SDFforeachGrammar(grammar,
		    (SDFGrammarFunc)collect_restricts,
		    (void *)&restricts);

  return restricts;
}

/*}}}  */
