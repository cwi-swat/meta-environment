#include <Library.h>
#include "builtin-common.h"
#include <MEPT-utils.h>

/*{{{  static PT_Tree makeMeasureFromInt(int result) */

static PT_Tree makeMeasureFromInt(int result)
{
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

/*}}}  */

/*{{{  PT_Tree ASFE_term_compare(PT_Tree input) */

PT_Tree ASFE_term_compare(PT_Tree input)
{
  PT_Tree left;
  PT_Tree right;
  int result;

  left = CO_getFunctionArgument(input,0);
  right = CO_getFunctionArgument(input,1);

  result = PT_compareTree(left, right);

  return makeMeasureFromInt(result);
}

/*}}}  */
/*{{{  PT_Tree ASC_term_compare(ATerm left, ATerm right) */

PT_Tree ASC_term_compare(ATerm left, ATerm right)
{
  return makeMeasureFromInt(ATcompare(left, right));
}

/*}}}  */
