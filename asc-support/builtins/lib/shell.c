#include "common.h"

/*{{{  PT_Tree shell(ATerm builtin, PT_Tree input) */

PT_Tree shell(ATerm builtin, PT_Tree input)
{
  PT_Tree cmd_arg = CO_getFunctionArgument(input,0);
  char *cmdline = PT_yieldTree(cmd_arg);
 
  cmdline[strlen(cmdline) - 1] = '\0';

  system(cmdline + 1);

  return input;
}

/*}}}  */
