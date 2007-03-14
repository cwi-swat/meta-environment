#include <MEPT.h>
#include <MEPT-tree.h>

/**
 * \file
 *
 * This file contains functionality for lists of trees
 */

/**
 * Removes all literal trees from a list of arguments
 * \param args list of arguments
 * \return a new list of arguments without any literals
 */
PT_Args PT_removeArgsLiterals(PT_Args args)
{
  /* This function removes any elements that are literal trees
   */
  PT_Args new = PT_makeArgsEmpty();

  for ( ; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
    PT_Tree arg = PT_getArgsHead(args);

    if (!PT_isTreeLit(arg)) {
      new = PT_makeArgsMany(arg, new);
    }
  }

  return PT_reverseArgs(new);
}

/** 
 * Removes the given tree from the given list of arguments.
 * 
 * \param args the arguments to remove the element from.
 * \param tree the tree to remove from the arguments.
 * 
 * \return the new list of arguments without the given tree.
 */
PT_Args PT_removeArgsTree(PT_Args args, PT_Tree tree) {
  return (PT_Args) ATremoveElement((ATermList) args, (ATerm) tree);
}

/** 
 * Returns the index of the given tree in the list of arguments given.
 * 
 * \param args the list of arguments to search through.
 * \param tree the tree to search for in the list of arguments.
 * 
 * \return the index of the first occurence of #tree in #args; or -1 if #tree 
 * is not in #args.
 */
int PT_indexOfTreeInArgs(PT_Args args, PT_Tree tree) {
  return ATindexOf((ATermList) args, (ATerm) tree, 0);
}

