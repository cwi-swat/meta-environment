/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <MEPT-utils.h>

#include "path.h"
#include "length.h"

/*}}}  */

/*{{{  SE_Steps stepUp(SE_Steps steps) */

SE_Steps stepUp(SE_Steps steps)
{
  ATermList steplist = (ATermList)SE_makeTermFromSteps(steps);

  return SE_makeStepsFromTerm((ATerm)ATgetPrefix(steplist));
}

/*}}}  */

/*{{{  static SE_Steps stepRight(SE_Steps steps) */

static SE_Steps stepRight(SE_Steps steps)
{
  ATermList steplist = (ATermList)SE_makeTermFromSteps(steps);
  ATermList prefix = ATgetPrefix(steplist);
  int step = ATgetInt((ATermInt)ATgetLast(steplist));

  return SE_makeStepsFromTerm((ATerm)ATappend(prefix, (ATerm)ATmakeInt(step + 1)));
}

/*}}}  */
/*{{{  static int getLastStep(SE_Steps steps) */

static int getLastStep(SE_Steps steps)
{
  ATermList list = (ATermList)SE_makeTermFromSteps(steps);

  return ATgetInt((ATermInt)ATgetLast(list));
}

/*}}}  */
/*{{{  static SE_Steps replaceLastStep(SE_Steps steps, int step) */

static SE_Steps replaceLastStep(SE_Steps steps, int step)
{
  ATermList list = (ATermList)SE_makeTermFromSteps(steps);

  list = ATreplace(list, (ATerm)ATmakeInt(step), ATgetLength(list)-1);

  return SE_makeStepsFromTerm((ATerm)list);
}

/*}}}  */
/*{{{  static SE_Steps appendStep(SE_Steps steps, int step) */

static SE_Steps appendStep(SE_Steps steps, int step)
{
  ATermList list = (ATermList)SE_makeTermFromSteps(steps);

  list = ATappend(list, (ATerm)ATmakeInt(step));

  return SE_makeStepsFromTerm((ATerm)list);
}

/*}}}  */

/*{{{  SE_Path pathUp(SE_Path path) */

SE_Path pathUp(SE_Path path)
{
  if (SE_hasPathSteps(path)) {
    SE_Steps steps = SE_getPathSteps(path);
    if (SE_isStepsMulti(steps)) {
      return SE_makePathTerm(stepUp(steps));
    }
  }

  return SE_makePathRoot();
}

/*}}}  */
/*{{{  SE_Path pathDown(SE_Path path) */

SE_Path pathDown(SE_Path path)
{
  SE_Steps steps = SE_getPathSteps(path);

  steps = appendStep(steps, 0);

  return SE_makePathTerm(steps);
}

/*}}}  */
/*{{{  SE_Path pathLeft(SE_Path path) */

SE_Path pathLeft(SE_Path path)
{
  int last_step;
  SE_Steps steps;

  if (SE_isPathRoot(path) || SE_isPathLeftLayout(path)) {
    return path;
  }

  if (SE_isPathRightLayout(path)) {
    return SE_makePathTerm(SE_makeStepsEmpty());
  }

  steps = SE_getPathSteps(path);

  if (SE_isStepsEmpty(steps)) {
    return path;
  }

  last_step = getLastStep(steps);

  if (last_step <= 0) {
    return path;
  }

  steps = replaceLastStep(steps, last_step-1);
  
  return SE_makePathTerm(steps);
}

/*}}}  */
/*{{{  SE_Path pathRight(SE_Path path) */

SE_Path pathRight(SE_Path path)
{
  if (SE_isPathLeftLayout(path)) {
    return SE_makePathTerm(SE_makeStepsEmpty());
  }
  else if (SE_isPathTerm(path)) {
    SE_Steps steps = SE_getPathSteps(path);

    if (!SE_isStepsEmpty(steps)) {
      return SE_makePathTerm(stepRight(steps));
    }
  }

  return path;
}

/*}}}  */

/*{{{  static SE_Steps getStepsInTree(PT_Tree tree, int location, int length) */

static SE_Steps getStepsInTree(PT_Tree tree, int location, int length)
{
  SE_Steps steps = SE_makeStepsEmpty();

  if (PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    int nr_args = PT_getArgsLength(args);
    int step;
    for (step = 0; step < nr_args; step++) {
      PT_Tree arg = PT_getArgsArgumentAt(args, step);
      int arg_len = PT_getTreeLengthAnno(arg);

      if (location <= arg_len) {
	if (location + length > arg_len
            ||
            PT_isTreeFlatLexical(arg)
            ||
            PT_isTreeLayout(arg)) {
	  return steps;
	}

	steps = SE_makeStepsMulti(step,getStepsInTree(arg, location, length));
	break;
      }
      location -= arg_len;
    }
  }

  return steps;
}

/*}}}  */
/*{{{  SE_Path getPathInParseTree(PT_ParseTree parse_tree, int location, int length) */

SE_Path getPathInParseTree(PT_ParseTree parse_tree, int location, int length)
{
  PT_Tree tree;
  SE_Path path;
  char *leftLayout;
  int treeLength, leftLayoutLength;

  assert(length >= 0);


  leftLayout = PT_yieldTree(PT_getParseTreeLayoutBeforeTree(parse_tree));
  leftLayoutLength = strlen(leftLayout);

  if (location <= leftLayoutLength) {
    path = SE_makePathRoot();
  }
  else {
    location -= leftLayoutLength;
    tree = PT_getParseTreeTree(parse_tree);
    treeLength = PT_getTreeLengthAnno(tree);

    if (location + length > treeLength) {
      path = SE_makePathRoot();
    }
    else {
      SE_Steps steps = getStepsInTree(tree, location, length);
      path = SE_makePathTerm(steps);
    }
  }

  return path;
}

/*}}}  */

/*{{{  static ATbool isChildSteps(SE_Steps child, SE_Steps parent) */

static ATbool isChildSteps(SE_Steps child, SE_Steps parent)
{
  /* Child may be shorter than parent */
  if (SE_isStepsEmpty(child) && !SE_isStepsEmpty(parent)) {
    return ATfalse;
  }

  /* Child may be longer than parent */
  if (SE_isStepsEmpty(parent)) {
    return ATtrue;
  }

  /* Head of parent and child may differ -=> disjoint paths */
  if (SE_getStepsHead(child) != SE_getStepsHead(parent)) {
    return ATfalse;
  }

  /* No decision possible yet, continue with tail of paths */
  return isChildSteps(SE_getStepsTail(child), SE_getStepsTail(parent));
}

/*}}}  */
/*{{{  ATbool isChildPath(SE_Path child, SE_Path parent) */

ATbool isChildPath(SE_Path child, SE_Path parent)
{
  if (SE_isPathRoot(parent) || SE_isEqualPath(child, parent)) {
    return ATtrue;
  }
  if (SE_hasPathSteps(child)) {
    return isChildSteps(SE_getPathSteps(child), SE_getPathSteps(parent));
  }
  return ATfalse;
}

/*}}}  */
