#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <MEPT-utils.h>
#include <aterm2.h>

PT_Tree shell(ATerm builtin, PT_Tree input)
{
  PT_Tree cmd_arg = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  char *cmdline = PT_yieldTree(cmd_arg);
 
  cmdline[strlen(cmdline) - 1] = '\0';

  system(cmdline + 1);

  return input;
}


