#include <PTMEPT-utils.h>
#include "builtin-common.h"

/*{{{  PT_Tree ASFE_lift_to_tree(PT_Tree input) */

PT_Tree ASFE_lift_to_tree(PT_Tree input)
{
  PT_Tree tree = CO_getFunctionArgument(input,0);

  return (PT_Tree) PTPT_liftTree(tree);
}

/*}}}  */
/*{{{  PT_Tree ASC_lift_to_tree(ATerm input) */

PT_Tree ASC_lift_to_tree(ATerm input)
{
  PT_Tree tree = muASFToTree(input);

  return (PT_Tree) PTPT_liftTree(tree);
}

/*}}}  */

/*{{{  PT_Tree ASFE_lift_to_term(PT_Tree input) */

PT_Tree ASFE_lift_to_term(PT_Tree input)
{
  PT_Tree tree = CO_getFunctionArgument(input,0);

  return (PT_Tree) PTPT_liftATerm((ATerm) tree);
}

/*}}}  */
/*{{{  PT_Tree ASC_lift_to_term(ATerm input) */

PT_Tree ASC_lift_to_term(ATerm input)
{
  PT_Tree tree = muASFToTree(input);

  return (PT_Tree) PTPT_liftATerm((ATerm) tree);
}

/*}}}  */
