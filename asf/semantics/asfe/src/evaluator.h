/*
  $Id$
 */

#include <ASFME.h>
#include <MEPT.h>
#include <aterm2.h>
#include "memotable.h"

ATerm evaluator(const char *name, PT_ParseTree parseTree, ASF_ASFConditionalEquationList eqs, 
		ATbool debug, ATbool remove_layout, ATbool mark_new_layout,
		ATbool allow_ambs);

/* variables */
extern ATbool aborted;
extern ATbool runVerbose;
extern ATbool useTide;
extern ASF_ASFTag tagCurrentRule;
extern ASF_ASFTag innermostTag;
extern ASF_ASFTag testRunnerTag;
extern PT_Tree innermostSubject;
extern MemoTable memo_table;
extern unsigned int asfe_rewrite_steps;

#define MAX_DEPTH 2000
