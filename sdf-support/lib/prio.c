#include "SDFME-utils.h"

/*{{{  collect_prios(SDF_Grammar grammar, SDF_PriorityList *prios) */

static void
collect_prios(SDF_Grammar grammar, SDF_PriorityList *prios)
{
  if (SDF_isGrammarPriorities(grammar)) {
    SDF_Priorities grammarPrios = SDF_getGrammarPriorities(grammar);
    SDF_PriorityList kernelPrios = SDF_getPrioritiesList(grammarPrios);
    SDF_OptLayout e = SDF_makeLayoutSpace();

    *prios = SDF_concatPriorityList(*prios, e, e, kernelPrios);
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
