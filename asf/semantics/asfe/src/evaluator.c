/* $Id$ */

#include "equations.h"
#include "asfe.tif.h"
#include "evaluator.h"
#include "reduction.h"
#include "errors.h"
#include <asc-builtins.h>
#include "debug.h"
#include <ASFME-utils.h>


/*{{{  defines */



/*}}}  */

/* global variables */
ASF_ASFTag tagCurrentRule = NULL;
PT_Tree innermostSubject = NULL;
ASF_ASFTag innermostTag = NULL;
ASF_ASFTag testRunnerTag = NULL;
ATbool aborted = ATfalse;
ATbool runVerbose = ATfalse;
ATbool useTide = ATfalse;

MemoTable memo_table = NULL;
unsigned asfe_rewrite_steps = 0;

/*{{{  ATerm evaluator(char *name, PT_ParseTree parseTree, ASF_ASFConditionalEquationList eqs, */

ATerm evaluator(const char *name, PT_ParseTree parseTree, ASF_ASFConditionalEquationList eqs,
                ATbool debug, ATbool remove_layout, ATbool mark_new_layout,
		ATbool allow_ambs)
{
  ASF_OptLayout e = ASF_makeOptLayoutAbsent();
  PT_Tree result;
  PT_Tree tree;

  ASF_protectASFTag(&tagCurrentRule);
  PT_protectTree(&innermostSubject);
  ASF_protectASFTag(&innermostTag);

  useTide = debug;

  enter_equations(eqs);

  RWclearErrors();

  tree = PT_getParseTreeTree(parseTree);

  if (runVerbose) {
    ATwarning("rewriting...\n");
  }

  if (memo_table == NULL) { 
    memo_table = MemoTableCreate();
  }

  tagCurrentRule = ASF_makeASFTagNotEmpty(e,
				  ASF_makeTagId("*undefined*"),e);
  innermostTag = ASF_makeASFTagNotEmpty(e,
				ASF_makeTagId("*innermost*"),e);
  innermostSubject = PT_makeTreeLit("*subject*");

  asfe_rewrite_steps = 0;
  initBuiltins();
  
  result = rewrite(tree);

  MemoTableDestroy(memo_table);
  memo_table = NULL;
  destroy_equation_table();

  parseTree = PT_setParseTreeTree(parseTree, result);

  if (remove_layout) {
    parseTree = PT_replaceParseTreeLayout(parseTree, 
					  (PT_Tree) ASF_makeLayoutSpace());
  }

  return PT_ParseTreeToTerm(parseTree);
}

/*}}}  */
