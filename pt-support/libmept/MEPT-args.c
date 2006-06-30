#include <MEPT.h>
#include <MEPT-tree.h>

PT_Args PT_removeArgsLiterals(PT_Args args)
{
  /* This function removes any elements that are literal trees
   */
  PT_Args new = PT_makeArgsEmpty();

  for ( ; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
    PT_Tree arg = PT_getArgsHead(args);

    if (!PT_isTreeLit(arg)) {
      new = PT_makeArgsMany(arg, new);
    }
  }

  return PT_reverseArgs(new);
}

