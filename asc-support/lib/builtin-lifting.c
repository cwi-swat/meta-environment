#include <PTMEPT-utils.h>
#include "builtin-common.h"


/*{{{  PT_Tree ASFE_lift_to_tree(PT_Tree input) */

PT_Tree ASFE_lift_to_tree(PT_Symbol type, PT_Tree tree)
{
  return (PT_Tree) PTPT_liftTree(tree);
}

/*}}}  */
/*{{{  PT_Tree ASC_lift_to_tree(ATerm input) */

PT_Tree ASC_lift_to_tree(ATerm type, ATerm input)
{
  PT_Tree tree = muASFToTree(input);

  return (PT_Tree) PTPT_liftTree(tree);
}

/*}}}  */


/*{{{  PT_Tree ASFE_lower_from_tree(PT_Tree input) */

PT_Tree ASFE_lower_from_tree(PT_Symbol type, PT_Tree tree)
{
  return (PT_Tree) PTPT_lowerTree((PTPT_Tree) tree);
}

/*}}}  */
/*{{{  PT_Tree ASC_lower_from_tree(ATerm input) */

PT_Tree ASC_lower_from_tree(ATerm type, ATerm input)
{
  PT_Tree tree = muASFToTree(input);

  return (PT_Tree) PTPT_lowerTree((PTPT_Tree) tree);
}

/*}}}  */

/*{{{  PT_Tree ASFE_lift_to_term(PT_Tree input) */

PT_Tree ASFE_lift_to_term(PT_Symbol symbol, PT_Tree tree)
{
  return (PT_Tree) PTPT_liftATerm((ATerm) tree);
}

/*}}}  */
/*{{{  PT_Tree ASC_lift_to_term(ATerm input) */

PT_Tree ASC_lift_to_term(ATerm type, ATerm input)
{
  PT_Tree tree = muASFToTree(input);

  return (PT_Tree) PTPT_liftATerm((ATerm) tree);
}

/*}}}  */
