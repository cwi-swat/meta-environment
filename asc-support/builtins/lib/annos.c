#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <MEPT-utils.h>
#include <PTMEPT-utils.h>
#include <aterm2.h>
#include <string.h>

/* note that by using AsFix trees as keys the storing and retrieval
 * of ATerm annotations depends on whitespace!
 */

/*{{{  PT_Tree set_anno(ATerm builtin, PT_Tree input) */

PT_Tree set_anno(ATerm builtin, PT_Tree input)
{
  PT_Tree term = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  PT_Tree key = PT_getArgsArgumentAt(PT_getTreeArgs(input),8);
  PT_Tree value = PT_getArgsArgumentAt(PT_getTreeArgs(input),12);

  return PT_setTreeAnnotation(term,
			      PT_TreeToTerm(key),
			      PT_TreeToTerm(value));
}

/*}}}  */
/*{{{  PT_Tree get_anno(ATerm builtin, PT_Tree input) */

PT_Tree get_anno(ATerm builtin, PT_Tree input)
{
  PT_Tree term = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  PT_Tree key = PT_getArgsArgumentAt(PT_getTreeArgs(input),8);
  PT_Tree value = NULL;


  value = PT_TreeFromTerm(PT_getTreeAnnotation(term, (ATerm) key));

  if (value != NULL) {
    return value;
  }

  return input;
}

/*}}}  */

/*{{{  static ATermAppl unquoteAppl(ATermAppl appl)  */

static ATermAppl unquoteAppl(ATermAppl appl) 
{
  AFun fun = ATgetAFun(appl);
  int arity = ATgetArity(fun);
  char *name = ATgetName(fun);
  ATermList args = ATgetArguments(appl);
  fun = ATmakeAFun(name, arity, ATfalse);

  return ATmakeApplList(fun, args);
}

/*}}}  */

/*{{{  PT_Tree get_term_anno(ATerm builtin, PT_Tree input)  */

PT_Tree get_term_anno(ATerm builtin, PT_Tree input) 
{
  PT_Tree term = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  PT_Tree key = PT_getArgsArgumentAt(PT_getTreeArgs(input),8);
  PT_Tree value = NULL;
  ATerm label;
  ATerm anno;

  label = (ATerm) unquoteAppl((ATermAppl) ATparse(PT_yieldTree(key)));

  if (label == NULL) {
    return input;
  }

  anno = PT_getTreeAnnotation(term, label);

  if (anno != NULL) {
    value = (PT_Tree) PTPT_explodeATerm(anno);
  }

  if (value != NULL) {
    return value;
  }

  return input;
}

/*}}}  */
