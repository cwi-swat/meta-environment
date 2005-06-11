#include <Library.h>
#include "builtin-common.h"
#include <MEPT-utils.h>

/*{{{  static PT_Tree makeMeasureFromInt(int result) */

static PT_Tree makeBooleanFromInt(int result)
{
  if (result < 0 ) {
    return (PT_Tree) CO_makeBooleanConstant(CO_makeBoolConTrue());
  }
  else {
    return (PT_Tree) CO_makeBooleanConstant(CO_makeBoolConFalse());
  }
}

/*}}}  */

/*{{{  PT_Tree ASFE_term_compare(PT_Tree input) */

PT_Tree ASFE_term_less(PT_Symbol type, PT_Tree left, PT_Tree right)
{
  int result = PT_compareTree(left, right, ATfalse, ATtrue);

  return makeBooleanFromInt(result);
}

/*}}}  */
/*{{{  PT_Tree ASC_term_compare(ATerm left, ATerm right) */

PT_Tree ASC_term_less(ATerm type, ATerm left, ATerm right)
{
  return makeBooleanFromInt(ATcompare(left, right));
}

/*}}}  */
