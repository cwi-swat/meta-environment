#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <MEPT-utils.h>
#include <PTMEPT-utils.h>
#include <aterm2.h>

/* note that by using AsFix trees as keys the storing and retrieval
 * of ATerm annotations depends on whitespace!
 */

PT_Tree set_anno(ATerm builtin, PT_Tree input)
{
  PT_Tree term = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  PT_Tree key = PT_getArgsArgumentAt(PT_getTreeArgs(input),8);
  PT_Tree value = PT_getArgsArgumentAt(PT_getTreeArgs(input),12);

  return PT_setTreeAnnotation(term,
			      PT_TreeToTerm(key),
			      PT_TreeToTerm(value));
}

PT_Tree get_anno(ATerm builtin, PT_Tree input)
{
  PT_Tree term = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  PT_Tree key = PT_getArgsArgumentAt(PT_getTreeArgs(input),8);
  PT_Tree value = NULL;

  value = PT_TreeFromTerm(PT_getTreeAnnotation(term, PT_TreeToTerm(key)));

  if (value != NULL) {
    return value;
  }

  return input;
}

PT_Tree get_term_anno(ATerm builtin, PT_Tree input) 
{
  PT_Tree term = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  PT_Tree key = PT_getArgsArgumentAt(PT_getTreeArgs(input),8);
  PT_Tree value = NULL;

  value = (PT_Tree) PTPT_explodeATerm(
		     PT_getTreeAnnotation(term, PT_TreeToTerm(key)));

  if (value != NULL) {
    return value;
  }

  return input;

}
