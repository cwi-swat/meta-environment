/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include <aterm2.h>
#include <MEPT.h>
#include <MEPT-utils.h>

#include "path.h"
#include "sort.h"
#include "tree.h"
#include "area.h"
#include "focus.h"
#include "editor.h"

/*}}}  */

/*{{{  PT_ParseTree flattenParseTreeTreeAt(PT_ParseTree parse_tree, SE_Path path)  */

PT_ParseTree flattenParseTreeTreeAt(PT_ParseTree parse_tree, SE_Path path) 
{
  PT_Tree subtree, newsubtree;
  ATerm annos;
  char *str = NULL;

  subtree = getParseTreeTreeAt(parse_tree, path);
  
  if (subtree) { 
    annos = AT_getAnnotations(PT_makeTermFromTree(subtree));
     
    str = PT_yieldTree(subtree);
    assert(str);

    newsubtree = PT_makeTreeFlatLayout(str);

    newsubtree = PT_makeTreeFromTerm(
		   AT_setAnnotations(
		     PT_makeTermFromTree(newsubtree), annos));
      
    return setParseTreeTreeAt(parse_tree, newsubtree, path);  
  }

  return parse_tree;
}

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
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    return PT_getProductionRhs(prod);
  }
  else if (PT_isTreeChar(tree)) {
    int ch = PT_getTreeCharacter(tree);

    return PT_makeSymbolCharClass(PT_makeCharRangesList(
                                  PT_makeCharRangeCharacter(ch),
                                  PT_makeCharRangesEmpty()));
  }
  else if (PT_isTreeAmb(tree)) {
    return PT_makeSymbolSort(SORT_AMBIGUOUS);
  }
  else if (PT_isTreeFlatLayout(tree)) {
    return PT_makeSymbolSort(SORT_UNPARSED);
  }
  else {
    return PT_makeSymbolSort(SORT_UNKNOWN);
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

/*{{{  PT_ParseTree setParseTreeTreeAt(PT_ParseTree parse_tree, SE_Path path) */

PT_ParseTree setParseTreeTreeAt(PT_ParseTree parse_tree, PT_Tree tree, SE_Path path)
{
  if (SE_hasPathSteps(path)) {
    SE_Steps steps = SE_getPathSteps(path);
    return PT_setParseTreeTree(
             parse_tree,
             setTreeAt(PT_getParseTreeTree(parse_tree),tree, steps));
  }

  return NULL;
}

/*}}}  */

/*{{{  PT_Args concatLeftLayout(PT_Args l1, PT_Args l2) */

PT_Args concatLeftLayout(PT_Args l1, PT_Args l2)
{
  return PT_concatArgs(l1, l2);
}

/*}}}  */
/*{{{  PT_Args concatRightLayout(PT_Args l1, PT_Args l2) */

PT_Args concatRightLayout(PT_Args l1, PT_Args l2)
{
  return PT_concatArgs(l2, l1);
}

/*}}}  */

static PT_Args leftLayout = NULL;
static PT_Args rightLayout = NULL;

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
    PT_Args layoutString;
    PT_Tree layout = PT_getArgsArgumentAt(oldArgs, step-1);
    assert(PT_isTreeLayout(layout));
    layoutString = PT_getTreeArgs(layout);
    layoutString = concatLeftLayout(layoutString, leftLayout);
    layout = PT_setTreeArgs(layout, layoutString);
    newArgs = PT_setArgsArgumentAt(newArgs, layout, step-1);
    leftLayout = NULL;
  }

  if (rightLayout != NULL && step < (PT_getArgsLength(oldArgs)-1)) {
    PT_Args layoutString;
    PT_Tree layout = PT_getArgsArgumentAt(oldArgs, step+1);
    assert(PT_isTreeLayout(layout));
    layoutString = PT_getTreeArgs(layout);
    layoutString = concatRightLayout(layoutString, rightLayout);
    layout = PT_setTreeArgs(layout, layoutString);
    newArgs = PT_setArgsArgumentAt(newArgs, layout, step+1);
    rightLayout = NULL;
  } 

  return PT_setTreeArgs(tree, newArgs);
}

/*}}}  */

/*{{{  PT_ParseTree updateParseTree(parse_tree, path, tree,left_layout,right_layout) */

PT_ParseTree updateParseTree(PT_ParseTree parse_tree, SE_Path path,
			     PT_Tree tree, PT_Args leftLayoutArgs, 
                             PT_Args rightLayoutArgs)
{
  SE_Steps steps;
  PT_Tree new_tree;

  if (SE_isPathRoot(path)) {
    parse_tree = PT_setParseTreeLayoutBeforeTree(parse_tree, 
                   PT_makeTreeLayoutNonEmpty(leftLayoutArgs));
    parse_tree = PT_setParseTreeTree(parse_tree, tree);
    parse_tree = PT_setParseTreeLayoutAfterTree(parse_tree, 
                   PT_makeTreeLayoutNonEmpty(rightLayoutArgs));
    return parse_tree;
  }
  
  assert(SE_isPathTerm(path));

  steps = SE_getPathSteps(path);

  leftLayout = leftLayoutArgs;
  rightLayout = rightLayoutArgs;

  new_tree = updateTreeTermSteps(PT_getParseTreeTree(parse_tree), steps, tree);

  if (leftLayout != NULL) {
    PT_Args localLeftLayout = PT_getTreeArgs(
                                PT_getParseTreeLayoutBeforeTree(parse_tree));
    PT_Tree newLeftLayout = PT_makeTreeLayoutNonEmpty(
                              concatLeftLayout(localLeftLayout, leftLayout));
    parse_tree = PT_setParseTreeLayoutBeforeTree(parse_tree, newLeftLayout);
  }

  if (rightLayout != NULL) {
    PT_Args localRightLayout = PT_getTreeArgs(                                                                   PT_getParseTreeLayoutBeforeTree(parse_tree));
    PT_Tree newRightLayout = PT_makeTreeLayoutNonEmpty(                                                        concatRightLayout(localRightLayout, rightLayout));
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
  return !PT_isTreeAppl(tree) && 
         !PT_isTreeFlatLayout(tree);
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

  start = strlen(PT_yieldTree(PT_getParseTreeLayoutBeforeTree(parse_tree)));

  tree = PT_getParseTreeTree(parse_tree);

  if (SE_isPathRightLayout(path)) {
    start += PT_getTreeLengthAnno(tree);
    assert(start == (PT_getParseTreeLengthAnno(parse_tree)
		     - strlen(PT_yieldTree(
                                PT_getParseTreeLayoutAfterTree(parse_tree)))));
  } else {
    start += calcTreeStart(tree, SE_getPathSteps(path));
  }

  return start;
}

/*}}}  */
