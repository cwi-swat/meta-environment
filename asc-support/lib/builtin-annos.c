#include <PTMEPT-utils.h>
#include "builtin-common.h"

/* note that by using AsFix trees as keys the storing and retrieval
 * of ATerm annotations depends on whitespace!
 */

/*{{{  static PT_Tree set_anno(PT_Tree term, PT_Tree key, PT_Tree value) */

static PT_Tree set_anno(PT_Tree term, PT_Tree key, PT_Tree value)
{
  return PT_setTreeAnnotation(term,
			      PT_TreeToTerm(key),
			      PT_TreeToTerm(value));
}

/*}}}  */
/*{{{  PT_Tree ASFE_set_anno(PT_Tree input) */

PT_Tree ASFE_set_anno(PT_Tree input)
{
  PT_Tree term = CO_getFunctionArgument(input,0);
  PT_Tree key = CO_getFunctionArgument(input,1);
  PT_Tree value = CO_getFunctionArgument(input,2);

  return set_anno(term, key, value);
}

/*}}}  */
/*{{{  PT_Tree ASC_set_anno(ATerm aterm, ATerm akey, ATerm avalue) */

PT_Tree ASC_set_anno(ATerm aterm, ATerm akey, ATerm avalue)
{
  PT_Tree term = muASFToTree(aterm);
  PT_Tree key = muASFToTree(akey);
  PT_Tree value = muASFToTree(avalue);

  return set_anno(term, key, value);
}

/*}}}  */

/*{{{  static PT_Tree get_anno(PT_Tree term, PT_Tree value) */

static PT_Tree get_anno(PT_Tree term, PT_Tree key)
{
  return PT_TreeFromTerm(PT_getTreeAnnotation(term, (ATerm) key));
}

/*}}}  */
/*{{{  PT_Tree ASFE_get_anno(PT_Tree input) */

PT_Tree ASFE_get_anno(PT_Tree input)
{
  PT_Tree term = CO_getFunctionArgument(input,0);
  PT_Tree key = CO_getFunctionArgument(input,1);
  PT_Tree value = NULL;


  value = get_anno(term, key);

  if (value != NULL) {
    return value;
  }

  return input;
}

/*}}}  */
/*{{{  PT_Tree ASC_get_anno(PT_Tree aterm, PT_Tree akey) */

PT_Tree ASC_get_anno(ATerm aterm, ATerm akey)
{
  PT_Tree term = muASFToTree(aterm);
  PT_Tree key = muASFToTree(akey);
  PT_Tree value = NULL;


  value = get_anno(term, key);

  return PT_makeTreeLit("TODO: give a proper normal form");
}

/*}}}  */

/*{{{  PT_Tree get_term_anno(PT_Tree input)  */

static PT_Tree get_term_anno(PT_Tree term, PT_Tree key)
{
  ATerm label;
  ATerm anno;

  label = CO_unquoteAppl(ATparse(PT_yieldTree(key)));

  if (label == NULL) {
    return NULL;
  }

  anno = PT_getTreeAnnotation(term, label);

  if (anno != NULL) {
    return (PT_Tree) PTPT_liftATerm(anno);
  }

  return NULL;
}

/*}}}  */
/*{{{  PT_Tree ASFE_get_term_anno(PT_Tree input)  */

PT_Tree ASFE_get_term_anno(PT_Tree input) 
{
  PT_Tree term = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  PT_Tree key = PT_getArgsArgumentAt(PT_getTreeArgs(input),8);
  PT_Tree value = NULL;

  value = get_term_anno(term, key);

  if (value != NULL) {
    return value;
  }

  return input;
}

/*}}}  */
/*{{{  PT_Tree get_term_anno(PT_Tree input)  */

PT_Tree ASC_get_term_anno(ATerm aterm, ATerm akey)
{
  PT_Tree term = muASFToTree(aterm);
  PT_Tree key = muASFToTree(akey);
  PT_Tree value = NULL;
  
  value = get_term_anno(term, key);
  
  if (value != NULL) {
    return value;
  }

  return PT_makeTreeLit("TODO: return a proper normal form");
}

/*}}}  */
