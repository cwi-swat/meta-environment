#include <MEPT-utils.h>

extern PT_Tree rewrite(PT_Tree term);

PT_Tree asf_normalize(ATerm builtin, PT_Tree input)
{
  PT_Args args = PT_getTreeArgs(input);
  PT_Tree term = PT_getArgsArgumentAt(args, 4);

  return rewrite(term);
}
