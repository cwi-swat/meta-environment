#include "builtin-common.h"
#include "Library.h"

/*{{{  static PT_Tree shell(PT_Tree cmd_arg) */

static CO_Boolean shell(PT_Tree cmd_arg)
{
  return system(PT_yieldTree(cmd_arg)) != 0 ?
    CO_makeBooleanConstant(CO_makeBoolConTrue()) :
    CO_makeBooleanConstant(CO_makeBoolConFalse());
}

/*}}}  */
/*{{{  PT_Tree ASFE_shell(PT_Tree input) */

PT_Tree ASFE_shell(PT_Symbol type, PT_Tree cmd_arg)
{
  return (PT_Tree) shell(cmd_arg);
}

/*}}}  */
/*{{{  PT_Tree ASC_shell(ATerm input) */

PT_Tree ASC_shell(ATerm input)
{
  PT_Tree cmd_arg = muASFToTree(input);

  return (PT_Tree) shell(cmd_arg);
}

/*}}}  */
