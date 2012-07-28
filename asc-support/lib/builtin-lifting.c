#include <PTMEPT-utils.h>
#include "builtin-common.h"

static ATermTable BuiltinLowerCache = NULL;
static ATermTable BuiltinLiftCache = NULL;

/*{{{  static PT_Tree liftToTree(PT_Tree input)  */

static PT_Tree liftToTree(PT_Tree input) 
{
  if (BuiltinLowerCache == NULL) {
    BuiltinLowerCache = ATtableCreate(1024,75);
  }
  if (BuiltinLiftCache == NULL) {
    BuiltinLiftCache = ATtableCreate(1024,75);
  }

  return (PT_Tree) PTPT_liftTreeCache(input, 
				      BuiltinLiftCache, BuiltinLowerCache);
}

/*}}}  */

/*{{{  PT_Tree ASFE_lift_to_tree(PT_Tree input) */

PT_Tree ASFE_lift_to_tree(PT_Symbol type, PT_Tree tree)
{
  return liftToTree(tree);
}

/*}}}  */
/*{{{  PT_Tree ASC_lift_to_tree(ATerm input) */

PT_Tree ASC_lift_to_tree(ATerm type, ATerm input)
{
  PT_Tree tree = muASFToTree(input);

  return liftToTree(tree);
}

/*}}}  */

/*{{{  static PT_Tree lowerFromTree(PT_Tree input) */

static PT_Tree lowerFromTree(PT_Tree input)
{
  if (BuiltinLowerCache == NULL) {
    BuiltinLowerCache = ATtableCreate(1024,75);
  }
  return PTPT_lowerTreeCache((PTPT_Tree) input, BuiltinLowerCache);
}

/*}}}  */

/*{{{  PT_Tree ASFE_lower_from_tree(PT_Tree input) */

PT_Tree ASFE_lower_from_tree(PT_Symbol type, PT_Tree tree)
{
  return lowerFromTree(tree);
}

/*}}}  */
/*{{{  PT_Tree ASC_lower_from_tree(ATerm input) */

PT_Tree ASC_lower_from_tree(ATerm type, ATerm input)
{
  PT_Tree tree = muASFToTree(input);

  return lowerFromTree(tree);
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
