#include <PTMEPT-utils.h>
#include <MEPT-utils.h>
#include "builtin-common.h"


/*{{{  static PT_Tree implode_tree(PT_Tree tree)  */

static PT_Tree implode_tree(PT_Tree tree) 
{
  PT_ParseTree pt = PT_makeValidParseTreeFromTree(tree);
  return (PT_Tree)PTPT_liftATerm(PT_implodeParseTree(pt,
						     ATtrue,
						     ATtrue,
						     ATtrue,
						     ATtrue,
						     ATtrue,
						     ATtrue,
						     ATfalse,
						     ATtrue,
						     ATtrue,
						     ATtrue,
						     ATtrue));
}

/*}}}  */
/*{{{  PT_Tree ASFE_implode(PT_Tree input) */

PT_Tree ASFE_implode(PT_Symbol type, PT_Tree tree)
{
  return implode_tree(tree);
}

/*}}}  */
/*{{{  PT_Tree ASC_implode(ATerm input) */

PT_Tree ASC_implode(ATerm type, ATerm input)
{
  PT_Tree tree = muASFToTree(input);

  return implode_tree(tree);
}
/*}}}  */


