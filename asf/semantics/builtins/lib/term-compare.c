#include <Library.h>
#include "common.h"
#include <MEPT-utils.h>


PT_Tree term_compare(PT_Tree input)
{
  PT_Tree left;
  PT_Tree right;
  int result;

  left = CO_getFunctionArgument(input,0);
  right = CO_getFunctionArgument(input,1);

  result = PT_compareTree(left, right);

  if (result == 0) {
    return PT_TreeFromTerm(CO_MeasureToTerm(CO_makeMeasureEqual()));
  }
  else if (result < 0) {
    return PT_TreeFromTerm(CO_MeasureToTerm(CO_makeMeasureLess()));
  }
  else {
    return PT_TreeFromTerm(CO_MeasureToTerm(CO_makeMeasureGreater()));
  }
}
