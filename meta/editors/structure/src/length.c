/*{{{  includes */

#include <stdlib.h>
#include <assert.h>

#include <MEPT-utils.h>

#include "path.h"
#include "length.h"
#include "tree.h"

/*}}}  */

/*{{{  static PT_Tree adjustLengthInNode(PT_Tree tree, int newLength) */

static PT_Tree adjustLengthInNode(PT_Tree tree, int newLength)
{
  int treeLength = PT_getTreeLengthAnno(tree);

  treeLength = treeLength + newLength;

  return PT_setTreeLengthAnno(tree, treeLength);
}

/*}}}  */
/*{{{  static PT_Tree updateTreeLengthInfo(PT_Tree tree, SE_Steps steps, int delta_length) */

static PT_Tree updateTreeLengthInfo(PT_Tree tree, SE_Steps steps, int delta_length)
{
  PT_Tree sub_tree, new_node, new_tree;

  sub_tree = getTreeAt(tree, steps);
  new_node = adjustLengthInNode(sub_tree, delta_length);

  if (SE_isStepsEmpty(steps)) {
    new_tree = updateTreeTerm(tree, steps, new_node);
  }
  else {
    PT_Tree tmp_tree;
    tmp_tree = updateTreeLengthInfo(tree, stepUp(steps), delta_length);
    new_tree = setTreeAt(tmp_tree, new_node, steps);
  }

  return new_tree;
}

/*}}}  */
/*{{{  PT_ParseTree updateParseTreeLengthInfo(parse_tree, path, delta_length) */

PT_ParseTree updateParseTreeLengthInfo(PT_ParseTree parse_tree, SE_Path path,
				       int delta_length)
{
  SE_Steps steps;
  PT_Tree tree;

  if (SE_isPathTree(path)) {
    steps = SE_getPathSteps(path);
    tree = PT_getParseTreeTree(parse_tree);
    tree = updateTreeLengthInfo(tree, steps, delta_length);
    parse_tree = PT_setParseTreeTree(parse_tree, tree);
  }

  parse_tree = PT_setParseTreeLengthAnno(parse_tree,
					 PT_getParseTreeLengthAnno(parse_tree)
					 + delta_length);

  return parse_tree;
}

/*}}}  */

