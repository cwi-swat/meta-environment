#include <PTMEPT-utils.h>
#include "common.h"

/* note that by using AsFix trees as keys the storing and retrieval
 * of ATerm annotations depends on whitespace!
 */

/*{{{  PT_Tree set_anno(PT_Tree input) */

PT_Tree set_anno(PT_Tree input)
{
  PT_Tree term = CO_getFunctionArgument(input,0);
  PT_Tree key = CO_getFunctionArgument(input,1);
  PT_Tree value = CO_getFunctionArgument(input,3);

  return PT_setTreeAnnotation(term,
			      PT_TreeToTerm(key),
			      PT_TreeToTerm(value));
}

/*}}}  */
/*{{{  PT_Tree get_anno(PT_Tree input) */

PT_Tree get_anno(PT_Tree input)
{
  PT_Tree term = CO_getFunctionArgument(input,0);
  PT_Tree key = CO_getFunctionArgument(input,1);
  PT_Tree value = NULL;


  value = PT_TreeFromTerm(PT_getTreeAnnotation(term, (ATerm) key));

  if (value != NULL) {
    return value;
  }

  return input;
}

/*}}}  */

/*{{{  PT_Tree get_term_anno(PT_Tree input)  */

PT_Tree get_term_anno(PT_Tree input) 
{
  PT_Tree term = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  PT_Tree key = PT_getArgsArgumentAt(PT_getTreeArgs(input),8);
  PT_Tree value = NULL;
  ATerm label;
  ATerm anno;

  label = CO_unquoteAppl(ATparse(PT_yieldTree(key)));

  if (label == NULL) {
    return input;
  }

  anno = PT_getTreeAnnotation(term, label);

  if (anno != NULL) {
    value = (PT_Tree) PTPT_liftATerm(anno);
  }

  if (value != NULL) {
    return value;
  }

  return input;
}

/*}}}  */
