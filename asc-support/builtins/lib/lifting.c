#include <PTMEPT-utils.h>
#include "common.h"

/*{{{  PT_Tree lift-to-tree(PT_Tree input) */

PT_Tree lift_to_tree(PT_Tree input)
{
  PT_Tree tree = CO_getFunctionArgument(input,0);

  return (PT_Tree) PTPT_liftTree(tree);
}

/*}}}  */
/*{{{  PT_Tree lift-to-tree(PT_Tree input) */

PT_Tree lift_to_term(PT_Tree input)
{
  PT_Tree tree = CO_getFunctionArgument(input,0);

  return (PT_Tree) PTPT_liftATerm((ATerm) tree);
}

/*}}}  */
