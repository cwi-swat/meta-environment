#include "common.h"


/*{{{  PT_Tree ASFE_asf_normalize(PT_Tree input) */

PT_Tree ASFE_asf_normalize(PT_Tree input)
{
  return rewrite(CO_getFunctionArgument(input,0));
}

/*}}}  */
/*{{{  PT_Tree ASC_asf_normalize(PT_Tree input) */

PT_Tree ASC_asf_normalize(ATerm input)
{
  return muASFToTree(input); /* normalization is implicit! */
}

/*}}}  */
