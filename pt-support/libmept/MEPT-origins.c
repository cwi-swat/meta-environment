
#include <stdio.h>
#include <assert.h>
#include <MEPT-origins.h>
#include <MEPT-posinfo.h>

#define ORIGIN ATparse("origin")

/**
 * \file
 * Deals with the origin annotation. If position information is kept
 * during transformation of a parse tree, the pos-info annotations correspond
 * to the PREVIOUS locations of nodes. Before re-annotating a tree with
 * new pos-info, we can store this information under the 'origin' annotation.
 * After this, each node effectively contains a mapping from the new location
 * to the old location, which can be used to visualize what happened during
 * a transformation.
 */

/**
 * Moves, recursively, all pos-info attribute information to origin information.
 * \param tree input tree
 * \return a new tree without pos-info information, and with origin information.
 */
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

/**
 * Returns the origin location of a tree.
 * \param tree input tree
 * \returns origin information encoded as a standard location.
 */
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

