#include <MEPT-utils.h>
#include "builtin-common.h"
#include "Library.h"


/*{{{  static PT_Tree unparse(PT_Tree tree) */

static PT_Tree unparse(PT_Tree tree)
{
  return PT_makeTreeLexToCf(PT_makeSymbolSort("Bytes"), 
	  PT_makeTreeFlatLexicalFromString(PT_yieldTree(tree)));
}

/*}}}  */
/*{{{  PT_Tree ASFE_unparse(PT_Tree input) */

PT_Tree ASFE_unparse(PT_Tree input)
{
  PT_Tree tree = CO_getFunctionArgument(input,0);

  return unparse(tree);
}

/*}}}  */
/*{{{  PT_Tree ASC_unparse(ATerm input) */

PT_Tree ASC_unparse(ATerm input)
{
  PT_Tree tree = muASFToTree(input);

  return unparse(tree);
}

/*}}}  */

