
/*{{{  includes */

#include <stdlib.h>
#include <assert.h>

#include <PT.h>
#include <PT-utils.h>

#include "path.h"
#include "sort.h"
#include "tree.h"
#include "area.h"
#include "focus.h"

/*}}}  */


/*{{{  PT_Symbol getParseTreeSort(PT_ParseTree parse_tree) */

PT_Symbol getParseTreeSort(PT_ParseTree parse_tree)
{
  return getTreeSort(PT_getParseTreeTree(parse_tree));
}

/*}}}  */
/*{{{  PT_Symbol getTreeSort(PT_Tree tree) */

PT_Symbol
getTreeSort(PT_Tree tree)
{
  if (PT_hasTreeSymbol(tree)) {
    return PT_getTreeSymbol(tree);
  }
  else if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    return PT_getProductionRhs(prod);
  }
  else if (PT_isTreeList(tree)) {
    return PT_getTreeIter(tree);
  }
  else {
    return PT_makeSymbolSort("invalid");
  }
}

/*}}}  */

/*{{{  PT_Tree getTreeAt(PT_Tree tree, SE_Steps steps) */

PT_Tree getTreeAt(PT_Tree tree, SE_Steps steps)
{
  int step;
  PT_Args args;

  if (SE_isStepsEmpty(steps)) {
    return tree;
  }

  while (!SE_isStepsEmpty(steps)) {
    step = SE_getStepsHead(steps);

    if (!PT_hasTreeArgs(tree)) {
      return NULL;
    }

    args  = PT_getTreeArgs(tree);
    tree  = PT_getArgsArgumentAt(args, step);
    steps = SE_getStepsTail(steps);
  }

  return tree;
}

/*}}}  */
/*{{{  PT_Tree setTreeAt(PT_Tree tree, PT_Tree sub_tree, SE_Steps steps) */

PT_Tree setTreeAt(PT_Tree tree, PT_Tree sub_tree, SE_Steps steps)
{
  PT_Tree arg;
  SE_Steps tail;
  int step;
  PT_Args args;

  if (SE_isStepsEmpty(steps)) {
    return sub_tree;
  }

  step = SE_getStepsHead(steps);
  tail = SE_getStepsTail(steps);
  args = PT_getTreeArgs(tree);
  arg  = PT_getArgsArgumentAt(args, step);
  sub_tree = setTreeAt(arg, sub_tree, tail);
  args = PT_setArgsArgumentAt(args, sub_tree, step);
  return PT_setTreeArgs(tree, args);
}

/*}}}  */
/*{{{  PT_Tree getParseTreeTreeAt(PT_ParseTree parse_tree, SE_Path path) */

PT_Tree getParseTreeTreeAt(PT_ParseTree parse_tree, SE_Path path)
{
  if (SE_hasPathSteps(path)) {
    SE_Steps steps = SE_getPathSteps(path);
    return getTreeAt(PT_getParseTreeTree(parse_tree), steps);
  }

  return NULL;
}

/*}}}  */

/*{{{  static char *concatStrings(const char *s, const char *t) */

static char *concatStrings(const char *s, const char *t)
{
  static char *buf = NULL;
  static int   buf_len = 0;

  int len_needed = strlen(s) + strlen(t) + 1;

  if (len_needed > buf_len) {
    buf = realloc(buf, len_needed);
    if (buf == NULL) {
      ATerror("out of memory in concatStrings (%d)\n", len_needed);
    }
    buf_len = len_needed;
  }

  sprintf(buf, "%s%s", s, t);

  return buf;
}

/*}}}  */
/*{{{  char *concatLeftLayout(char *l1, char *l2) */

char *concatLeftLayout(char *l1, char *l2)
{
  return concatStrings(l1, l2);
}

/*}}}  */
/*{{{  char *concatRightLayout(char *l1, char *l2) */

char *concatRightLayout(char *l1, char *l2)
{
  return concatStrings(l2, l1);
}

/*}}}  */

static char *leftLayout = NULL;
static char *rightLayout = NULL;

/*{{{  PT_Tree updateTreeTermSteps(PT_Tree tree, SE_Steps steps, PT_Tree sub_tree) */

PT_Tree updateTreeTermSteps(PT_Tree tree, SE_Steps steps, PT_Tree sub_tree)
{
  PT_Args oldArgs, newArgs;
  PT_Tree oldArg, newArg;
  SE_Steps tail;
  int step;

  if (SE_isStepsEmpty(steps)) {
    return sub_tree;
  }

  step = SE_getStepsHead(steps);
  tail = SE_getStepsTail(steps);

  oldArgs = PT_getTreeArgs(tree);
  oldArg  = PT_getArgsArgumentAt(oldArgs, step);

  if (SE_isStepsEmpty(tail)) {
    newArg = sub_tree;
  }
  else {
    newArg = updateTreeTermSteps(oldArg, tail, sub_tree);
  }
  newArgs = PT_setArgsArgumentAt(oldArgs, newArg, step);

  if (leftLayout != NULL && step > 0) {
    char *layoutString;
    PT_Tree layout = PT_getArgsArgumentAt(oldArgs, step-1);
    assert(PT_isTreeLayout(layout));
    layoutString = PT_getTreeString(layout);
    layoutString = concatLeftLayout(layoutString, leftLayout);
    layout = PT_makeTreeLayout(layoutString);
    newArgs = PT_setArgsArgumentAt(newArgs, layout, step-1);
    leftLayout = NULL;
  }

  if (rightLayout != NULL && step < (PT_getArgsLength(oldArgs)-1)) {
    char *layoutString;
    PT_Tree layout = PT_getArgsArgumentAt(oldArgs, step-1);
    assert(PT_isTreeLayout(layout));
    layoutString = PT_getTreeString(layout);
    layoutString = concatRightLayout(layoutString, rightLayout);
    layout = PT_makeTreeLayout(layoutString);
    newArgs = PT_setArgsArgumentAt(newArgs, layout, step-1);
    rightLayout = NULL;
  } 

  return PT_setTreeArgs(tree, newArgs);
}

/*}}}  */

/*{{{  PT_ParseTree updateParseTree(parse_tree, path, tree,left_layout,right_layout) */

PT_ParseTree updateParseTree(PT_ParseTree parse_tree, SE_Path path,
			     PT_Tree tree, char *left_layout, char *right_layout)
{
  SE_Steps steps;
  PT_Tree new_tree;

  if (SE_isPathRoot(path)) {
    return PT_makeParseTreeTree(left_layout, tree, right_layout);
  }
  
  assert(SE_isPathTerm(path));

  steps = SE_getPathSteps(path);

  leftLayout = left_layout;
  rightLayout = right_layout;

  new_tree = updateTreeTermSteps(PT_getParseTreeTree(parse_tree), steps, tree);

  if (leftLayout != NULL) {
    char *localLeftLayout = PT_getParseTreeLayoutBeforeTree(parse_tree);
    char *newLeftLayout = concatLeftLayout(localLeftLayout, leftLayout);
    parse_tree = PT_setParseTreeLayoutBeforeTree(parse_tree, newLeftLayout);
  }

  if (rightLayout != NULL) {
    char *localRightLayout = PT_getParseTreeLayoutBeforeTree(parse_tree);
    char *newRightLayout = concatRightLayout(localRightLayout, rightLayout);
    parse_tree = PT_setParseTreeLayoutBeforeTree(parse_tree, newRightLayout);
  }

  return PT_setParseTreeTree(parse_tree, new_tree);
}

/*}}}  */
/*{{{  PT_Tree updateTreeTerm(PT_Tree tree, ATerm path, PT_Tree sub_tree) */

PT_Tree updateTreeTerm(PT_Tree tree, SE_Steps steps, PT_Tree sub_tree)
{
  leftLayout = NULL;
  rightLayout = NULL;
  return updateTreeTermSteps(tree, steps, sub_tree);
}

/*}}}  */

/*{{{  ATbool isBasicLeafNode(PT_Tree tree) */

ATbool isBasicLeafNode(PT_Tree tree)
{
  return !PT_isTreeAppl(tree) && !PT_isTreeList(tree)
    && !PT_isTreeVar(tree) && !PT_isTreeLexical(tree);
}

/*}}}  */

/*{{{  int calcTreeStart(PT_Tree tree, SE_Steps steps) */

int calcTreeStart(PT_Tree tree, SE_Steps steps)
{
  PT_Tree head;
  PT_Args args;
  int i, step, length;

  if (SE_isStepsEmpty(steps)) {
    return 0;
  }

  step = SE_getStepsHead(steps);
  length = 0;

  assert(PT_hasTreeArgs(tree));
  args = PT_getTreeArgs(tree);

  for (i=0; i<step; i++) {
    head = PT_getArgsHead(args);
    length += PT_getTreeLengthAnno(head);
    args = PT_getArgsTail(args);
  }
  head = PT_getArgsHead(args);

  return length + calcTreeStart(head, SE_getStepsTail(steps));
}

/*}}}  */
/*{{{  int calcParseTreeStart(PT_ParseTree parse_tree, SE_Path path) */

int calcParseTreeStart(PT_ParseTree parse_tree, SE_Path path)
{
  int start;
  PT_Tree tree;

  if (SE_isPathRoot(path) || SE_isPathLeftLayout(path)) {
    return 0;
  }

  start = strlen(PT_getParseTreeLayoutBeforeTree(parse_tree));

  tree = PT_getParseTreeTree(parse_tree);

  if (SE_isPathRightLayout(path)) {
    start += PT_getTreeLengthAnno(tree);
    assert(start == (PT_getParseTreeLengthAnno(parse_tree)
		     - strlen(PT_getParseTreeLayoutAfterTree(parse_tree))));
  } else {
    start += calcTreeStart(tree, SE_getPathSteps(path));
  }

  return start;
}

/*}}}  */

