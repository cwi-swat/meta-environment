#include "builtin-common.h"
#include "Library.h"

/*{{{  static PT_Tree shell(PT_Tree cmd_arg) */

static CO_Boolean shell(PT_Tree cmd_arg)
{
  char *cmdline = PT_yieldTree(cmd_arg);
  int result;

  cmdline[strlen(cmdline) - 1] = '\0';

  result = system(cmdline + 1);

  return result != 0 ?
    CO_makeBooleanConstant(CO_makeBoolConTrue()) :
    CO_makeBooleanConstant(CO_makeBoolConFalse());
}

/*}}}  */
/*{{{  PT_Tree ASFE_shell(PT_Tree input) */

PT_Tree ASFE_shell(PT_Tree input)
{
  PT_Tree cmd_arg = CO_getFunctionArgument(input,0);

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
