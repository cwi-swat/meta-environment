/*
  $Id$
 */

#include "equations.h"
#include "asfe.tif.h"
#include "evaluator.h"
#include "reduction.h"
#include "errors.h"
#include "pre-post.h"
#ifdef USE_TIDE
#include "debug.h"
#endif


/*{{{  defines */



/*}}}  */

/* global variables */
ASF_Tag tagCurrentRule = NULL;
ATbool aborted = ATfalse;
ATbool runVerbose = ATfalse;
ATbool useTide = ATfalse;

/*{{{  ATerm evaluator(char *name, ATerm term) */

ATerm evaluator(char *name, PT_ParseTree parseTree, ASF_CondEquationList eqs,
                ATbool debug, ATbool remove_layout, ATbool mark_new_layout,
		ATbool allow_ambs)
{
  PT_Tree result;
  PT_Tree tree;

  ATprotect((ATerm*)&tagCurrentRule);

  eqs = RWprepareEquations(eqs, mark_new_layout);
  enter_equations(name, eqs);
  select_equations(name);

  useTide = debug;
  RWclearError();

  tree = PT_getParseTreeTree(parseTree);
  tree = RWprepareTerm(tree, allow_ambs);

  select_equations(name);

  if (runVerbose) {
    ATwarning("rewriting...\n");
  }

  result = rewrite(tree);

  result = RWrestoreTerm(result, remove_layout);
  parseTree = PT_setParseTreeTree(parseTree, result);

  if (remove_layout) { /* compatible with asc-support */
    parseTree = PT_setParseTreeLayoutBeforeTree(parseTree,
						PT_makeTreeLayoutEmpty());
    parseTree = PT_setParseTreeLayoutAfterTree(parseTree,
					       PT_makeTreeLayoutEmpty());
  }

  return PT_makeTermFromParseTree(parseTree);
}

/*}}}  */
