#include "SDF-utils.h"

static void
collect_prios(SDF_Grammar grammar, SDF_PriorityList *prios)
{
  if (SDF_isGrammarSyntax(grammar)) {
    SDF_Priorities grammarPrios = SDF_getGrammarPriorities(grammar);
    SDF_PriorityList kernelPrios = SDF_getPrioritiesList(grammarPrios);

    *prios = SDF_concatPriorityList(*prios, kernelPrios);
  }
}

/*}}}  */
/*{{{  SDF_getModulePriorities(SDF_Module module) */

SDF_PriorityList 
SDF_getGrammarKernelPriorities(SDF_Grammar grammar)
{
  SDF_PriorityList prios = SDF_makePriorityListEmpty();

  SDFforeachGrammar(grammar,
		    (SDFGrammarFunc)collect_prios,
		    (void *)&prios);

  return prios;
}

/*}}}  */
