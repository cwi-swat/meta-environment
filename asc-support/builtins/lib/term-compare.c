#include <Library.h>
#include "common.h"



PT_Tree term_compare_less(PT_Tree input)
{
  PT_Tree left = CO_getFunctionArgument(input,0);
  PT_Tree right = CO_getFunctionArgument(input,1);

  if (((int) left) < ((int) right)) {
   return (PT_Tree) CO_makeBooleanConstant(CO_makeBoolConTrue());
  }
  else {
   return (PT_Tree) CO_makeBooleanConstant(CO_makeBoolConFalse());
  } 
}
