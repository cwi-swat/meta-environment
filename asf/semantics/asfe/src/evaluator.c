/*
  $Id$
 */

#include "equations.h"
#include "asfe.tif.h"
#include "evaluator.h"
#include "reduction.h"
#include "errors.h"
#include "pre-post.h"
#include <asf-builtins.h>

#ifdef USE_TIDE
#include "debug.h"
#endif


/*{{{  defines */



/*}}}  */

/* global variables */
ASF_ASFTag tagCurrentRule = NULL;
ATbool aborted = ATfalse;
ATbool runVerbose = ATfalse;
ATbool useTide = ATfalse;

MemoTable memo_table = NULL;
unsigned rewrite_steps = 0;

/*{{{  ATerm evaluator(char *name, ATerm term) */

ATerm evaluator(char *name, PT_ParseTree parseTree, ASF_ASFConditionalEquationList eqs,
                ATbool debug, ATbool remove_layout, ATbool mark_new_layout,
		ATbool allow_ambs)
{
  ASF_OptLayout e = ASF_makeOptLayoutAbsent();
  PT_Tree result;
  PT_Tree tree;

  ATprotect((ATerm*)&tagCurrentRule);

  useTide = debug;

  eqs = RWprepareEquations(eqs, mark_new_layout);
  enter_equations(eqs);

  RWclearError();

  tree = PT_getParseTreeTree(parseTree);
  tree = RWprepareTerm(tree, allow_ambs);

  if (runVerbose) {
    ATwarning("rewriting...\n");
  }

  if (memo_table == NULL) { 
    memo_table = MemoTableCreate();
  }

  tagCurrentRule = ASF_makeASFTagNotEmpty(e,ASF_makeASFTagIdManyChars(ASF_makeCHARLISTString("*undefined*")),e);
  rewrite_steps = 0;
  initBuiltins();
  
  result = rewrite(tree);

  MemoTableDestroy(memo_table);
  memo_table = NULL;
  destroy_equation_table();

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
