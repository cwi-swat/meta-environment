#include <Library.h>
#include "common.h"
#include <aterm2.h>


PT_Tree term_compare_less(PT_Tree input)
{
  PT_Tree left = CO_getFunctionArgument(input,0);
  PT_Tree right = CO_getFunctionArgument(input,1);
  
  left = PT_removeTreeAllLayoutAndAnnotations(left);
  right = PT_removeTreeAllLayoutAndAnnotations(right);

  if (((int) left) < ((int) right)) {
   return (PT_Tree) CO_makeBooleanConstant(CO_makeBoolConTrue());
  }
  else {
   return (PT_Tree) CO_makeBooleanConstant(CO_makeBoolConFalse());
  } 
}
