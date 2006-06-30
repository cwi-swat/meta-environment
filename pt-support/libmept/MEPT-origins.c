
#include <stdio.h>
#include <assert.h>
#include <MEPT-origins.h>
#include <MEPT-posinfo.h>

#define ORIGIN ATparse("origin")



PT_Tree PT_promotePosInfoToOrigin(PT_Tree tree)
{
  assert(tree != NULL);

  if (PT_hasTreeArgs(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    args = PT_visitArgs(args, PT_promotePosInfoToOrigin);
    tree = PT_setTreeArgs(tree, args);
  }

  if (PT_hasTreeLocation(tree)) {
    ATerm term;
    LOC_Location loc = PT_getTreeLocation(tree);
    tree = PT_removeTreeLocation(tree);
    term = PT_TreeToTerm(tree);
    term = ATsetAnnotation(term, ORIGIN, LOC_LocationToTerm(loc));
    tree = PT_TreeFromTerm(term);
  }

  return tree;
}


LOC_Location PT_getTreeOrigin(PT_Tree tree)
{
  ATerm term;
  ATerm origin;

  assert(tree != NULL);

  term = PT_TreeToTerm(tree);
  origin = ATgetAnnotation(term, ORIGIN);

  if (origin == NULL) {
    return NULL;
  }
  else {
    return LOC_LocationFromTerm(origin);
  }
}

