#include "SDFME-utils.h"

/*{{{  collect_lex_prods(SDF_Grammar grammar, SDF_Productions *lexProds) */

static void
collect_lex_prods(SDF_Grammar grammar, SDF_ProductionList *lexProds)
{
  if (SDF_isGrammarLexicalSyntax(grammar)) {
    SDF_Productions grammarProds = SDF_getGrammarProductions(grammar);
    SDF_ProductionList prods = SDF_getProductionsList(grammarProds);

    *lexProds = SDF_concatProductionList(*lexProds,
					 SDF_makeLayoutSpace(),
					 prods);
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

/*{{{  collect_var_prods(SDF_Grammar grammar, SDF_Productions *varProds) */

static void
collect_var_prods(SDF_Grammar grammar, SDF_ProductionList *varProds)
{
  if (SDF_isGrammarVariables(grammar)) {
    SDF_Productions grammarProds = SDF_getGrammarProductions(grammar);
    SDF_ProductionList prods = SDF_getProductionsList(grammarProds);

    *varProds = SDF_concatProductionList(*varProds,
					 SDF_makeLayoutSpace(),
					 prods);
  }
}

/*}}}  */
/*{{{  SDF_getModuleVariableProductions(SDF_Module module) */

SDF_ProductionList 
SDF_getModuleVariableProductions(SDF_Module module)
{
  SDF_ProductionList varProds = SDF_makeProductionListEmpty();

  SDFforeachGrammarInModule(module,
			    (SDFGrammarFunc)collect_var_prods,
			    (void *)&varProds);

  return varProds;
}

/*}}}  */

/*{{{  collect_cf_prods(SDF_Grammar grammar, SDF_Productions *cfProds) */

static void
collect_cf_prods(SDF_Grammar grammar, SDF_ProductionList *cfProds)
{
  if (SDF_isGrammarContextFreeSyntax(grammar)) {
    SDF_Productions grammarProds = SDF_getGrammarProductions(grammar);
    SDF_ProductionList prods = SDF_getProductionsList(grammarProds);

    *cfProds = SDF_concatProductionList(*cfProds,
					SDF_makeLayoutSpace(),
					prods);
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

/*{{{  collect_all_prods(SDF_Grammar grammar, SDF_Productions *allProds) */

static void
collect_all_prods(SDF_Grammar grammar, SDF_ProductionList *allProds)
{
  if (SDF_hasGrammarProductions(grammar)) {
    SDF_Productions grammarProds = SDF_getGrammarProductions(grammar);
    SDF_ProductionList prods = SDF_getProductionsList(grammarProds);

    *allProds = SDF_concatProductionList(*allProds,
					 SDF_makeLayoutSpace(),
					 prods);
  }
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

/*{{{  collect_kernel_prods(SDF_Grammar grammar, SDF_Productions *prods) */

static void
collect_kernel_prods(SDF_Grammar grammar, SDF_ProductionList *prods)
{
  if (SDF_isGrammarSyntax(grammar)) {
    SDF_Productions grammarProds = SDF_getGrammarProductions(grammar);
    SDF_ProductionList lexProds = SDF_getProductionsList(grammarProds);

    *prods = SDF_concatProductionList(*prods,
				      SDF_makeLayoutSpace(),
				      lexProds);
  }
}

/*}}}  */
/*{{{  SDF_getGrammarKernelProductions(SDF_Grammar grammar) */

SDF_ProductionList
SDF_getGrammarKernelProductions(SDF_Grammar grammar)
{
  SDF_ProductionList prods = SDF_makeProductionListEmpty();

  SDFforeachGrammar(grammar,
		    (SDFGrammarFunc)collect_kernel_prods,
		    (void *)&prods);

  return prods;
}

/*}}}  */
