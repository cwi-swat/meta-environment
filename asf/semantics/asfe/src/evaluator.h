/*
  $Id$
 */

#include <ASFME.h>
#include <MEPT.h>
#include <aterm2.h>

ATerm evaluator(char *name, PT_ParseTree parseTree, ASF_CondEquationList eqs, 
		ATbool debug, ATbool remove_layout, ATbool mark_new_layout,
		ATbool allow_ambs);

/* variables */
extern ATbool aborted;
extern ATbool runVerbose;
extern ATbool useTide;
extern ASF_Tag tagCurrentRule;

#define MAX_DEPTH 2000
