/* $Id$ */

/** \file
 * \ingroup parseForest
 *
 * This file implements the transition from the internal SGLR parse forest 
 * representation (that uses tables to represent ambiguities) to the #PT_Tree 
 * representation, and the post-parse ambiguity filters. 
 *
 * There are seven separate filters:
 * \li cycle detection
 * \li direct preference
 * \li indirect preference  (heuristic)
 * \li preference counting  (heuristic)
 * \li injection counting   (heuristic)
 * \li priority
 * \li reject
 *
 * The order that these filters are performed in is important because different
 * combinations of filters can remove different trees. The 'strongest' filters 
 * should be done first, but this is currently not the case -- the priority
 * filter should be done first, but it is actually done last.
 *
 * The indirect preference, preference counting and injection counting 
 * filters are marked as heuristics because their behaviour is not easily 
 * predictable. Furthermore, they appear to have been implemented to 
 * disambiguate specific examples (maybe the Action Semantics language). 
 * As far as we can tell they are not generally applicable.
 */

#include <unistd.h>          
#include <string.h>   
#include <stdlib.h>
#include <assert.h>
#include <aterm2.h>
#include <rsrc-usage.h>
#include <MEPT-productions.h>
#include <MEPT-args.h>
#include <mainOptions.h>
#include <Error.h>
#include <Error-manager.h>

#include "posmap.h"
#include "mem-alloc.h"
#include "sglrInterface.h"
#include "marking.h"
#include "parserOptions.h"
#include "filterOptions.h"
#include "ambi-tables.h"
#include "filters.h"
#include "statusBar.h"
#include "levels.h"
#include "sglr-termstore.h"
#include "inputString-api.h"
#include "parserStatistics.h"
/** 
 * Contains all sub-trees that have been filtered. It is used to prevent
 * multiple filtering of the same sub-tree. The table is indexed on a given 
 * sub-tree's children and the start position of the string it derives.
 * \see memoization in filterRecursive()
 */
static ATermTable resolvedtable = NULL;
/** 
 * Contains the start position of the string that is derived by the sub-trees 
 * that have been filtered. It is used to retrieve the position information in 
 * the case that a sub-tree is not re-filtered. 
 * \see memoization in filterRecursive()
 */
static ATermTable postable = NULL;

static InputString inputString;

static ATermTable seenAmbiguities = NULL;

static ATermIndexedSet cyclicLevels = NULL;

static ATermTable nodeCountTable = NULL;
/** 
 * Counts the (non-nested) avoided productions in the given tree.
 * It counts the number of \c avoid productions encountered on a top down 
 * traversal from the given tree node. The traversal stops when a \c prefer or 
 * an \c avoid production is encountered. If an ambiguous node is encountered 
 * only one of its subtrees is traversed.
 *
 * Note that although a top down traversal is performed here, the filtering is
 * done from the bottom-up.
 *
 * \param t0 the tree to begin the traversal from 
 * 
 * \return the number of \c avoid productions in the given tree
 */
static size_t countAvoidsInTree(PT_Tree t0) {
  size_t avoids = 0;

  if (PT_isTreeAppl(t0)) {
    PT_Production prod = PT_getTreeProd(t0);
    PT_Args args = PT_getTreeArgs(t0);

    if (PT_isProductionAvoid(prod)) {
      return 1;
    }
    else if (PT_isProductionPrefer(prod)) {
      return 0;
    }

    for ( ; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
      avoids += countAvoidsInTree(PT_getArgsHead(args));
    }
  }
  else if (PT_isTreeAmb(t0)) {
    avoids += countAvoidsInTree(PT_getArgsHead(PT_getTreeArgs(t0)));
  }
  else if (PT_isTreeCycle(t0)) {
    return 0;
  }

  return avoids;
}

/** 
 * Counts the (non-nested) preferred productions in the given tree.
 * It counts the number of \c prefer productions encountered on a top down 
 * traversal from the given tree node. The traversal stops when a \c prefer or 
 * an \c avoid production is encountered. If an ambiguous node is encountered 
 * only one of its subtrees is traversed.
 *
 * Note that although a top down traversal is performed here, the filtering is
 * done from the bottom-up.
 *
 * \param t0 the tree to begin the travesal from
 * 
 * \return the number of \c prefer productions in the given tree
 */
static size_t countPrefersInTree(PT_Tree t0) {
  size_t prefers = 0;

  if (PT_isTreeAppl(t0)) {
    PT_Production prod = PT_getTreeProd(t0);
    PT_Args args = PT_getTreeArgs(t0);

    if (PT_isProductionAvoid(prod)) {
      return 0;
    }
    else if (PT_isProductionPrefer(prod)) {
      return 1;
    }

    for ( ; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
      prefers += countPrefersInTree(PT_getArgsHead(args));
    }
  }
  else if (PT_isTreeAmb(t0)) {
    prefers += countPrefersInTree(PT_getArgsHead(PT_getTreeArgs(t0)));
  }
  else if (PT_isTreeCycle(t0)) {
    return 0;
  }

  return prefers;
}

/**
 * Traverses past any injections in the given tree, apart for nodes that have 
 * preference attributes associated. The traversal is also stopped if an 
 * ambiguous or cyclic node is encountered.
 * 
 * \param pt the parse table 
 * \param t the parse tree node from which to traverse from
 * 
 * \return the parse tree node reached after traversing any injections
 */
static PT_Tree jumpOverInjectionsModuloPreferences(ParseTable *pt, PT_Tree t) {
  if (PT_isTreeAppl(t)) {
    PT_Production prod = PT_getTreeProd(t);
       
    if (PT_isProductionPrefer(prod) || PT_isProductionAvoid(prod)) {
      return t;
    }

    /*while (SGLR_PTBL_prodIsUserDefinedInjection(pt, prod)) {*/
    while (SGLR_PTBL_prodIsInjection(pt, prod)) {
      /* only one child */
      t = PT_getArgsHead(PT_getTreeArgs(t));
      prod = PT_getTreeProd(t);

      if (!PT_isTreeAppl(t) 
          || PT_isProductionPrefer(prod)
          || PT_isProductionAvoid(prod)) {
        return t;
      }
    }
  }
  
  return t;
}

/** 
 * Determines if the production given first should be preferred over the second.
 * 
 * \param prod1 the production of a tree.
 * \param prod2 the production of a tree.
 * 
 * \return \c true iff the first production should be preferred over the second;
 * \c false otherwise. 
 */
static ATbool isFirstPreferredToSecond(PT_Production prod1, PT_Production prod2) {
  ATbool prod1Avoid = PT_isProductionAvoid(prod1);
  ATbool prod2Avoid = PT_isProductionAvoid(prod2);
  ATbool prod1Prefer = PT_isProductionPrefer(prod1);
  ATbool prod2Prefer = PT_isProductionPrefer(prod2);

  /* this works best if a production is not both prefer and avoid,
   * which the grammar writer must take care of. Do not put an 
   * assert though, because such a user error should not crash the parser.
   */

  if (prod1Avoid && prod2Avoid) {
    return ATfalse;
  }
  else if (prod1Prefer && prod2Prefer) {
    return ATfalse;
  }
  else if (prod1Prefer || prod2Avoid) {
    return ATtrue;
  }

  return ATfalse;
}

/** 
 * Determines if the first tree given should be preferred over the second, 
 * ignoring any injections that do not contain preference attributes.
 * 
 * \param pt the parse table
 * \param t0 the first parse tree
 * \param t1 the second parse tree
 * 
 * \return \c true iff the first tree should be preferred over the second; 
 * \c false otherwise.
 */
static ATbool findPreferredTree(ParseTable *pt, PT_Tree t0, PT_Tree t1) {
  PT_Production prod0 = PT_getTreeProd(t0);
  PT_Production prod1 = PT_getTreeProd(t1);
  PT_Tree newt0, newt1;

  if (isFirstPreferredToSecond(prod0, prod1)) {
    return ATtrue;
  }

  newt0 = jumpOverInjectionsModuloPreferences(pt, t0);
  newt1 = jumpOverInjectionsModuloPreferences(pt, t1);

  if (PT_isTreeAppl(newt0) && PT_isTreeAppl(newt1)) {
    PT_Production newprod0 = PT_getTreeProd(newt0);
    PT_Production newprod1 = PT_getTreeProd(newt1);
    return isFirstPreferredToSecond(newprod0, newprod1);
  }

  return ATfalse;
}

/** 
 * Determines which of the given trees should be preferred, ignoring any 
 * injections that do not contain preference attributes. Only non-ambiguous 
 * trees can be preferred.
 * 
 * \param pt the parse table.
 * \param t0 the first parse tree.
 * \param t1 the secong parse tree.
 * 
 * \return one of the given trees that should be preferred, or \c NULL if it 
 * cannot be determined which tree to prefer.
 */
static PT_Tree directPreferenceFilter(ParseTable *pt, PT_Tree t0, PT_Tree t1) {
  /*ATwarning("directFilter:\n%t\n\n%t\n\n",t0,t1);*/

  if (findPreferredTree(pt, t0, t1)) {
    if (PARSER_getDebugFlag == ATtrue) {
      /*PT_Production p0 = PT_getTreeProd(t0);
      PT_Production p1 = PT_getTreeProd(t1);
      ATfprintf(LOG_log(), "prefer/avoid result: %t > %t\n", p0, p1);*/
    }
    SGLR_STATS_incrementCount(SGLR_STATS_treesDirectPreferenceFiltered);
    return t0;
  }
  if (findPreferredTree(pt, t1, t0)) {
    if (PARSER_getDebugFlag == ATtrue) { 
      /*PT_Production p0 = PT_getTreeProd(t0);
      PT_Production p1 = PT_getTreeProd(t1);
      ATfprintf(LOG_log(), "prefer/avoid result: %t < %t\n", p0, p1);*/
    }
    SGLR_STATS_incrementCount(SGLR_STATS_treesPreferred);
    return t1;
  }

  return (PT_Tree) NULL;
}

/** 
 * Counts the number of instances that two child nodes, in the same position, 
 * from the given list of child nodes are different. The comparison of nodes is
 * done by an equality check on the ATerm pointers of the nodes. This means that
 * the nodes may have the same label, but their trees can be different.
 *
 * \pre The two lists of children given must have the same labels (their parent
 * nodes must use the same production).
 * 
 * \param args0 the children of a parse tree node
 * \param args1 the children of a parse tree node
 * 
 * \return the number instances that two child nodes, in the same position, are
 * different 
 */
static int countDistinctArguments(PT_Args args0, PT_Args args1) {
  int diffs = 0;

  /* Both args are children of the same production. */
  assert(PT_getArgsLength(args0) == PT_getArgsLength(args1));

  while (!PT_isArgsEmpty(args0)) {
    if (!PT_isEqualTree(PT_getArgsHead(args0), PT_getArgsHead(args1))) {
      diffs++;
    }

    args0 =  PT_getArgsTail(args0);
    args1 =  PT_getArgsTail(args1);
  }
  
  return diffs;
}

/** 
 * Special filter that determines which of the given trees should be preferred, 
 * ignoring any injection chains that do not contain preference attributes. 
 * If the root nodes of the given trees are labelled by the same production, and
 * only one of their children are different, then this filter continues its 
 * traversal down that particular child. It appears that this is a filter for
 * a specific ambiguity in a specific language (probably Action Semantics). It
 * doesn't work in general. It is attempting to deal with the case that a 
 * preference attribute appears below, but not directly below, an ambiguity 
 * cluster. The code was commented as attempting to "see whether the ambiguity 
 * node can be pushed down the tree".
 * 
 * \param pt the parse table
 * \param t0 the first parse tree
 * \param t1 the second parse tree
 * 
 * \return one of the given trees that should be preferred, or \c NULL if it
 * cannot be determined which tree to prefer
 */
static PT_Tree indirectPreferenceFilter(ParseTable *pt, PT_Tree t0, PT_Tree t1) {
  PT_Production p0;
  PT_Production p1;

  /*ATwarning("indirectFilter:\n%t\n\n%t\n\n",t0,t1);*/
  
  if (!PT_isTreeAppl(t0) ||
      !PT_isTreeAppl(t1)) {
    return (PT_Tree) NULL;
  }

  p0 = PT_getTreeProd(t0);
  p1 = PT_getTreeProd(t1);

  if (!PT_isEqualProduction(p0,p1)) {
    return directPreferenceFilter(pt, t0, t1);
  }
  else {
    PT_Args args0 = PT_getTreeArgs(t0);
    PT_Args args1 = PT_getTreeArgs(t1);
    int diffs = countDistinctArguments(args0, args1);
   
    /* We find out whether or not there is exactly one argument
     * that is different for each two trees, then we locate this
     * exact child by looping all children until we've found it.
     * When we find it, we apply this function recursively. We
     * do this recursion to traverse a unique path that is differnt
     * between the two trees. When we can't find that path anymore,
     * we apply the normal direct preference filter at that point.
     */

    /* NOTE: this filter sounds logical (since we find only one different
     * child what can it do wrong?) but... there are several issues with it.
     * Firsly, it is incomprehensible to the user. Secondly, I can't see
     * why only one argument of a tree can be different without the 
     * ambiguity cluster being lower. It must have something to do
     * with follow restrictions. On the other hand, when there is just
     * one tree to compare (in case of a chain rule), then it makes more
     * sense. The problem with this filter is then that it works for
     * more trees than just the ones with chain rules.
     */
    if (diffs == 1) {
      while (!PT_isArgsEmpty(args0)) {
        PT_Tree arg0 = PT_getArgsHead(args0);
        PT_Tree arg1 = PT_getArgsHead(args1);

        /* This code only gets executed once. */
        if (!PT_isEqualTree(arg0, arg1)) {
          PT_Tree max = indirectPreferenceFilter(pt, arg0, arg1);
          if (max) {
            if (PT_isEqualTree(max, arg0)) {
              SGLR_STATS_incrementCount(SGLR_STATS_treesIndirectPreferenceFiltered);
              return t0;
            }
            else {
              SGLR_STATS_incrementCount(SGLR_STATS_treesIndirectPreferenceFiltered);
              return t1;
            }
          }
          else {
            return (PT_Tree) NULL;
          }
        }

        args1 = PT_getArgsTail(args1);
        args0 = PT_getArgsTail(args0);
      }
    }
  }

  return (PT_Tree) NULL;
}

/**
 * Count the number of \c prefers and \c avoids in both trees given and make a 
 * comparison between the two. This filter is needed because it can happen that 
 * one tree contains \c avoids and the other tree contains \c prefers.
 * This causes the MultiSets of both trees to become symmetric.
 * 
 * \param pt the parse table.
 * \param t0 the first parse tree to compare.
 * \param t1 the second parse tree to compare.
 * 
 * \return the first tree if the number of prefers is greater or equal to the 
 * number of prefers in the second tree, and the number of avoids is less than
 * or equal to the number of avoids; otherwise the second tree; or \c NULL if
 * it cannot be determined which tree to prefer.
 */
static PT_Tree preferenceCountFilter(ParseTable *pt, PT_Tree t0, PT_Tree t1) {
  PT_Tree max = NULL;
  PT_Production p0;
  PT_Production p1;
  int pT0, pT1, aT0, aT1;

  assert(PT_isTreeAppl(t0) && PT_isTreeAppl(t1));

  p0 = PT_getTreeProd(t0);
  p1 = PT_getTreeProd(t1);

  if (MAIN_getStatsFlag) {
    SGLR_STATS_incrementCount(SGLR_STATS_preferenceCountCalls);
  }

  if (SGLR_PTBL_hasPrefers(pt) || SGLR_PTBL_hasAvoids(pt)) {
    pT0 = countPrefersInTree(t0);
    pT1 = countPrefersInTree(t1);
    aT0 = countAvoidsInTree(t0);
    aT1 = countAvoidsInTree(t1);

    if (((pT0 > pT1) && (aT0 <= aT1)) ||
        ((pT0 == pT1) && (aT0 < aT1))) { 
      if (PARSER_getDebugFlag == ATtrue) {
        /*ATfprintf(LOG_log(), "prefer/avoid result: %t > %t\n", p0, p1);*/
      }
      max = t0;
    }
  
    if (((pT1 > pT0) && (aT1 <= aT0)) ||
        ((pT1 == pT0) && (aT1 < aT0))) {
      if (max != NULL) {
        if (PARSER_getDebugFlag == ATtrue) {
          /*ATfprintf(LOG_log(), "Warning! symmetric prefer/avoid relation (%t > %t) && (%t < %t)\n", p0, p1, p0, p1);*/
        }
        max = NULL;
      }
      else { 
        if (PARSER_getDebugFlag == ATtrue) {
          /*ATfprintf(LOG_log(), "prefer/avoid result: %t < %t\n", p0, p1);*/
        }
        max = t1;
      }
    }
  }

  if (max) {
    if (MAIN_getStatsFlag) {
      SGLR_STATS_incrementCount(SGLR_STATS_treesPreferenceCountFiltered);
    }
  }

  return max;
}

static size_t countAllInjectionsInTree(ParseTable *pt, PT_Tree t) {
  if (PT_isTreeAppl(t)) {
    size_t injections = 0;
    PT_Production prod = PT_getTreeProd(t);
    PT_Args kids = PT_getTreeArgs(t);

    for ( ; !PT_isArgsEmpty(kids); kids = PT_getArgsTail(kids)) {
      size_t kidsinj = countAllInjectionsInTree(pt, PT_getArgsHead(kids));

      if (kidsinj != -1) {
        injections += kidsinj;
      }
      else {
        return -1;
      }
    }

    if (SGLR_PTBL_prodIsInjection(pt, prod)) {
      injections++;
    }

    return injections;
  }
  else if (PT_isTreeAmb(t)) {
      /* Either we have a singleton or
       * the injection count of all elements in the cluster are
       * equal due to earlier filtering, so we just take the first.
       */
      return countAllInjectionsInTree(pt, PT_getArgsHead(PT_getTreeArgs(t)));
  }
  else if (PT_isTreeCycle(t)) {
      /* injection counting is meaningless for trees that have
       * cycles, so return -1, and let the caller handle this case
       */
      return -1;
  }

  return 0;
}

static PT_Tree fullInjectionCountFilter(ParseTable *pt, PT_Tree t0, PT_Tree t1) {
  size_t in0 = countAllInjectionsInTree(pt, t0);
  size_t in1 = countAllInjectionsInTree(pt, t1);
  
  SGLR_STATS_incrementCount(SGLR_STATS_injectionCountCalls);

  if (in0 == -1 || in1 == -1) {
    /* one of them had a cycle, abort */
    return (PT_Tree) NULL;
  }
  
  if (in0 > in1) {
    if (PARSER_getDebugFlag) {
      /*ATfprintf(LOG_log(), "More injections: (%d > %d)\n", in0, in1);*/
    }
      SGLR_STATS_incrementCount(SGLR_STATS_treesInjectionCountFiltered);
      return t1;
  } else if (in0 < in1) {
    if (PARSER_getDebugFlag) {
      /*ATfprintf(LOG_log(), "Fewer injections: (%d < %d)\n", in0, in1);*/
    }
      SGLR_STATS_incrementCount(SGLR_STATS_treesInjectionCountFiltered);
      return t0;
  }

  return (PT_Tree) NULL;
}

/**
 * Applies the direct or indirect preference filter, followed by the preference 
 * count filter, and then the injection count filter. If one of the filters 
 * succeeds then it is not necessary to perform any of the other filters as one
 * tree has been selected. 
 *
 * Note that only one of the (in)direct preference filters is ever 
 * performed. If both are selected then only the direct preference filter is 
 * done.
 *
 * \todo The performance of this function can probably be improved. It attempts
 * to filter one sub-tree from an ambiguity cluster against all other sub-trees
 * (children, or branches). Clearly there is a lot of redundant traversals 
 * being done here. Some Kind of memoisation will probably make a big difference
 * to the performance.
 * 
 * \param pt the parse table for disambiguating information
 * \param t0 the parse tree to filter
 * \param t1 the parse tree to filter
 * 
 * \return the preferred tree of the two, or \c NULL if there is no
 *         filter that succeeds
 */
static PT_Tree applyFilters(ParseTable *pt, PT_Tree t0, PT_Tree t1) {
  PT_Tree max = NULL;

  if (PT_isEqualTree(t0, t1)) {
    return t0;
  }

  if (SGLR_PTBL_hasPreferences(pt)) {
    if (FLT_getDirectPreferenceFlag()) {
      max = directPreferenceFilter(pt, t0, t1);
      if (max) {
        return max;
      }  
    }
    /* An experiment to see whether the ambiguity node can
     * be pushed down the tree. This will only be done
     * if only one argument of the node differs.
     */
    else if (FLT_getIndirectPreferenceFlag()) {
      max = indirectPreferenceFilter(pt, t0, t1);
      if (max) {
        return max;
      }
    }
  }

  if (SGLR_PTBL_hasPreferences(pt)) {
    if (FLT_getPreferenceCountFlag()) {
      max = preferenceCountFilter(pt, t0, t1);
      if (max) {
        return max;
      }
    }
  }

  if (FLT_getInjectionCountFlag()) {
    max = fullInjectionCountFilter(pt, t0, t1);
    if (max) {
      return max;
    }
  }

  return max;
}


/** 
 * Recursively traverses down the tree from the given node, ignoring injection 
 * chains, searching for a node with a priority conflict with the given 
 * production. If a priority conflict is found then the tree is filtered 
 * upwards, until the previous ambiguity cluster, or the root of the tree, if 
 * there is no ambiguity. Because ATerms are non-destructive, it is necessary 
 * to recreate all nodes as the recursion returns. The traversal of the 
 * injection chains is implemented directly in this function to make the 
 * re-creation of nodes easier. 
 *
 * \see priorityFilter()
 * 
 * \param pt the parse table
 * \param t the node to begin the traversal from
 * \param prod the production higher up the tree with the priority relation
 * \param argNumber the subtree traversed from the node containing the priority
 * relation higher up the tree 
 * 
 * \return the original tree if there were no priority conflicts, or a new 
 * filtered tree if there was. If the entire tree is filtered then \c NULL is
 * returned.
 */
static PT_Tree priorityFilterRecursive(ParseTable *pt, PT_Tree t, PT_Production prod, int argNumber) {
  
  PT_Tree injChild = t;

  if (PT_isTreeAppl(t)) {
    PT_Production tProd = PT_getTreeProd(t);

    /* Traverse any injection chains. Should this also check for a priority 
     * relation defined for #t? */
    if (SGLR_PTBL_prodIsUserDefinedInjection(pt, tProd)) {
      /* only one child */
      injChild = PT_getArgsHead(PT_getTreeArgs(t));

      PT_Tree newInjChild = priorityFilterRecursive(pt, injChild, prod, argNumber);
      if (newInjChild) {
        if (PT_isEqualTree(injChild, newInjChild)) {
          return t;
        }
        else {
          SGLR_STATS_incrementCount(SGLR_STATS_prodTreeNodesCreatedDuringFiltering);
          return PT_setTreeArgs(t, PT_makeArgsSingle(newInjChild));
        }
      }
      else {
        return (PT_Tree)NULL;
      }
    }
  }

  /* If the first node after the injection chain is an ambiguity cluster, then
   * continue searching for a priority conflict by traversing its children and 
   * any injection chains. */
  if (PT_isTreeAmb(injChild)) {
    PT_Args ambChildren = PT_getTreeArgs(injChild);
    PT_Args newAmbChildren = PT_makeArgsEmpty();
    ATbool ambChildrenEqual = ATtrue;
    
    for (; !PT_isArgsEmpty(ambChildren); ambChildren = PT_getArgsTail(ambChildren)) {
      PT_Tree ambChild = PT_getArgsHead(ambChildren);
      PT_Tree newAmbChild = priorityFilterRecursive(pt, ambChild, prod, argNumber);
      /* If ambChild is NULL then there is a priority conflict that has been 
       * filtered lower down the tree and hence this child branch should not be 
       * added to the ambiguity.*/
      if (newAmbChild) { 
        newAmbChildren = PT_makeArgsMany(newAmbChild, newAmbChildren);
        if (!PT_isEqualTree(ambChild, newAmbChild)) {
          ambChildrenEqual = ATfalse;
        }
      }
      else {
        ambChildrenEqual = ATfalse;
      }
    }
   
    if (!PT_isArgsEmpty(newAmbChildren)) {
      /* If the ambiguity only has one child left after filtering, then remove 
       * the cluster, and create a new link to the single child from the 
       * ambiguity cluster's parent. */
      if (PT_getArgsLength(newAmbChildren) == 1) { 
        return PT_getArgsHead(newAmbChildren);
      }
      else {
        if (ambChildrenEqual) {
          return injChild;
        }
        else {
        SGLR_STATS_incrementCount(SGLR_STATS_prodTreeNodesCreatedDuringFiltering);
        return PT_setTreeArgs(injChild, PT_reverseArgs(newAmbChildren));
        }
      }
    }
   /* If all the children of the ambiguity have been removed then remove the
    * ambiguity cluster as well. */ 
    else {
      SGLR_STATS_incrementCount(SGLR_STATS_ambiguityPriorityFiltered);
      return (PT_Tree)NULL;
    }
  }
  /* Otherwise, if the first node after the injection chain is not an ambiguity
   * node, then check if there is a priority conflict. */
  else {
    PT_Production injChildProd = PT_getTreeProd(injChild);
    if (!SGLR_PTBL_isPriorityGreater(pt, argNumber, prod, injChildProd)) {
      return injChild;
    }
    else {
      SGLR_STATS_incrementCount(SGLR_STATS_treesPriorityFiltered);
      return (PT_Tree)NULL;
    }
  }
}

/** 
 * Checks for unresolved priority conflicts.
 * If the given tree has an production with an associated priority relation and 
 * an ambiguity cluster as a child, it is checked to see if there is an 
 * unresolved conflict lower down the tree. These unresolved conflicts occur if 
 * there are injection chains (unit rules) between productions with a priority 
 * relation. If a priority conflict is found then the tree is filtered.
 *
 * Note that associativities are transformed to priorities with arguments 
 * before parse table construction by pgen. 
 * 
 * \see priorityFilterRecursive() 
 * 
 * \param pt the parse table
 * \param t  the parse tree node from which to begin the search for unresolved 
 * priority conflicts
 * 
 * \return the original tree if there were no priority conflicts, or a new 
 * filtered tree if there was. If the entire tree is filtered then \c NULL is
 * returned.
 */
static PT_Tree priorityFilter(ParseTable *pt, PT_Tree t) {
  PT_Args newChildren = PT_makeArgsEmpty();
  int argNumber = 0;
  int i = 0;

  if (PT_isTreeAppl(t)) {
    PT_Production prod = PT_getTreeProd(t);

    if (SGLR_PTBL_hasProductionPriority(pt, prod)) {
      PT_Args children = PT_getTreeArgs(t);

      if (PT_getArgsLength(children) == 0) {
        return t;
      }

      SGLR_TERM_STORE_FRAME(PT_getArgsLength(children),
      for (; !PT_isArgsEmpty(children); children = PT_getArgsTail(children), argNumber++) {
        PT_Tree child = PT_getArgsHead(children);

        child = priorityFilterRecursive(pt, child, prod, argNumber);
        /* if #child is NULL then a priority conflict was found and #t can be 
         * removed from the ambiguity node; otherwise #child needs to be 
         * added to the new children of #t. */
        if (child) {
          SGLR_TERM_STORE_CHECK(i);
          SGLR_TERM_STORE[i] = (ATerm)child; 
          i++;
        }
        else {
          return (PT_Tree)NULL;
        }
      }

      while(--i >= 0) {
        newChildren = PT_makeArgsMany((PT_Tree) SGLR_TERM_STORE[i],newChildren);
      }
      );

      if (PT_isEqualArgs(PT_getTreeArgs(t), newChildren)) {
        return t;
      }
      else {
        SGLR_STATS_incrementCount(SGLR_STATS_prodTreeNodesCreatedDuringFiltering);
        return PT_setTreeArgs(t, newChildren);
      }
    }
  }

  return t;
}

ATbool isStartInjection(PT_Production prod) {
  /** \warning This unapified ATerm level code MUST go */
  return ATmatch((ATerm) prod,
                 "prod([cf(opt(layout)),cf(sort(<str>)),cf(opt(layout))],"
                 "sort(\"<START>\"),no-attrs)",
                 NULL, NULL, NULL);
}

ATbool isStartInjectionATerm(PT_Production prod) {
  /** \warning This unapified ATerm level code MUST go */
  return ATmatch((ATerm) prod,
                 "prod([cf(opt(layout)),<term>,cf(opt(layout))],"
                 "sort(\"<START>\"),no-attrs)",
                 NULL, NULL, NULL);
}

static ATbool isOfSort(PT_Tree t, const char* sort, ATbool sortIsATerm) {
  PT_Production prod = PT_getTreeProd(t);

  if (sortIsATerm) {
    if (isStartInjectionATerm(prod)) {
      PT_Symbol sym = PT_getSymbolsSymbolAt(PT_getProductionLhs(prod), 1);
      return !strcmp(ATwriteToString(PT_SymbolToTerm(sym)), sort);
    }
  } else {
    if (isStartInjection(prod)) {
      PT_Symbol sym = PT_getSymbolsSymbolAt(PT_getProductionLhs(prod), 1);

      assert(PT_isSymbolCf(sym));
      sym = PT_getSymbolSymbol(sym);
      assert(PT_isSymbolSort(sym));

      return !strcmp(PT_getSymbolString(sym), sort);
    }
  }

  return ATfalse;
}


/** 
 * For the given tree it checks to see the root node is labelled with the 
 * specified sort.
 * 
 * \param pt the parse table
 * \param t  the parse tree to check the root node label from
 * \param sort the non-terminal to compare against the parse tree node label
 * 
 * \return \c NULL if the given tree does not have a top node labelled with the 
 *         specified non-terminal; or a tree with the top node labelled by the
 *         specified non-terminal; or a tree whose top node is ambiguous and
 *         whose children are all labelled by the specified non-terminal. 
 */
static PT_Tree filterOnTopSort(ParseTable *pt, PT_Tree t, const char *sort, ATbool sortIsATerm) {
  PT_Args allambs;
  PT_Args newambs = PT_makeArgsEmpty();
  ATerm  index;

  index = SG_AmbiTablesGetIndex(t, 0);
  allambs = SG_AmbiTablesGetClusterOnIndex(index);

  if (!PT_isArgsEmpty(allambs)) {
    /* We have at least one tree in the ambiguity cluster
     * and for all trees in this cluster we have to check
     * whether it has the sort that was expected.
     * If all trees are removed a "NULL" tree is returned.
     */
    for (; !PT_isArgsEmpty(allambs); allambs = PT_getArgsTail(allambs)) {
      PT_Tree amb = PT_getArgsHead(allambs);
      if (isOfSort(amb, sort, sortIsATerm)) {
        newambs = PT_makeArgsMany(amb, newambs);
      }
    }

    SG_AmbiTablesUpdateCluster(index, newambs);

    if (PT_isArgsEmpty(newambs)) {
      return (PT_Tree) NULL;
    }
    else {
      return t;
    }
  }
  else {
    /* We have only one tree and for this tree we have to check
     * whether it has the sort that was expected.
     * If this tree is removed a "NULL" tree is returned.
     */
    if (isOfSort(t, sort, sortIsATerm)) {
        return t;
    }
  }

  return (PT_Tree) NULL;
}



/** 
 * Filter the given tree against all the other trees in the given ambiguity 
 * cluster. The filters are applied in a very specific order.
 * 
 * \param pt   the parse table needed to retrieve disambiguation information
 * \param ambs the other alternatives in the cluster
 * \param t    the tree to compare
 * 
 * \return a smaller list of alternative trees if any filter is successfully 
 * applied
 */
static PT_Args filterOneAlternativeAgainstEachSibling(ParseTable *pt, PT_Args ambs, PT_Tree t) {
  PT_Args new = PT_makeArgsEmpty();
  ATbool tFilteredOut = ATfalse;

  if (PT_isArgsEmpty(ambs)) {
    return PT_makeArgsSingle(t);
  }

  /* Filter the given tree against all children in the given ambiguity 
   * cluster. */
  for (;!PT_isArgsEmpty(ambs); ambs = PT_getArgsTail(ambs)) {
    PT_Tree amb = PT_getArgsHead(ambs);
    PT_Tree max;

    max = applyFilters(pt, t, amb);

    if(max == NULL) {
       /* no filter was successful */
       new = PT_makeArgsMany(amb, new);
    } else if (PT_isEqualTree(max, amb)) { 
      /* #amb successfully filtered #t out */ 
      tFilteredOut = ATtrue;
      new = PT_makeArgsMany(amb, new);
    }
    /* otherwise #t successfully filtered #amb out */
  }
  
  if (!tFilteredOut) {
    new = PT_makeArgsMany(t, new);
  }
   
  return new;
}

static ATbool isTreeRejected(ParseTable *pt, PT_Tree t) {
  assert(PT_isTreeAppl(t) && "Only PT_TreeAppl nodes can be rejected!");

  if (FLT_getRejectFlag() && SGLR_PTBL_hasRejects(pt) && PT_isProductionReject(PT_getTreeProd(t))) {
    return ATtrue;
  }

  return ATfalse;
}

static PT_Tree filterRecursive(ParseTable *pt, PT_Tree t, size_t *pos,
                 ATbool inAmbs, ATbool cycle, int level);

/** 
 * Checks if any of the nodes in the ambiguity cluster have rejects. 
 * If the production that labels a direct child of an ambiguity node is 
 * rejected then the entire ambiguity cluster is rejected. This is
 * done because the reject productions essentially prevent a non-terminal
 * from deriving a string, or a set of strings.
 * 
 * \param pt 
 * \param ambiguousChildren 
 * \param pos 
 * \param cycle 
 * \param level 
 * 
 * \return 
 */
static ATbool isAmbiguityRejected(ParseTable *pt, PT_Args ambiguousChildren, size_t *pos, ATbool cycle, int level) {

  if (FLT_getRejectFlag() && SGLR_PTBL_hasRejects(pt)) {
    
    while (!PT_isArgsEmpty(ambiguousChildren)) {
      PT_Tree amb = PT_getArgsHead(ambiguousChildren);

      if (PT_isProductionReject(PT_getTreeProd(amb))) {
        /* continue filtering despite encountering a reject to ensure the 
         * position information is correct */
        filterRecursive(pt, amb, pos, ATtrue, cycle, level+1);
        return ATtrue;
      }

      ambiguousChildren = PT_getArgsTail(ambiguousChildren); 
    }
  }

  return ATfalse;
}

/** 
 * Performs a depth first traversal of each node in the ambiguity cluster 
 * applying the necessary filters, finally constructing the new ambiguity 
 * node.
 * 
 * \param pt 
 * \param ambiguousSubTrees 
 * \param pos 
 * \param cycle 
 * \param level 
 * 
 * \return 
 */
static PT_Args filterAmbiguousTreesRecursive(ParseTable *pt, PT_Args ambTrees, size_t *pos, ATbool cycle, int level) {
  PT_Tree ambTree;
  PT_Args newAmbTrees = PT_makeArgsEmpty();
  int saved_pos = *pos;
  int new_pos = saved_pos;

  while (!PT_isArgsEmpty(ambTrees)) {
    ambTree = PT_getArgsHead(ambTrees);
    *pos = saved_pos;
    ambTree = filterRecursive(pt, ambTree, pos, ATtrue, cycle, level+1);

    if (*pos != saved_pos) {
      new_pos = *pos;
    }
    
    if (ambTree) {
      newAmbTrees = PT_makeArgsMany(ambTree, newAmbTrees);
    }
    ambTrees = PT_getArgsTail(ambTrees);
  }
  
  *pos = new_pos;
  return newAmbTrees;
}

/** 
 * For every child node x of the newly created ambiguity node, call 
 * filterOneAlternativeAgainstEachSibling() with the ambiguity node minus x. 
 * The function checks if any of the filters that can be applied in this code 
 * are acitvated before continuing.
 * 
 * \param pt 
 * \param alternativeTrees 
 * 
 * \return 
 */
static PT_Args filterAmbiguousAlternatives(ParseTable *pt, PT_Args alternativeTrees) {
  PT_Args filteredAlternativeTrees = alternativeTrees;
  
  if (FLT_getDirectPreferenceFlag() || FLT_getIndirectPreferenceFlag() ||
      FLT_getPreferenceCountFlag() || FLT_getInjectionCountFlag()) {
    if (PARSER_getDebugFlag) {
      /*ATfprintf(LOG_log(), "Ambiguity cluster: %d nodes originally.\n", 
          PT_getArgsLength(alternativeTrees));*/
    }

    if (PT_getArgsLength(alternativeTrees) > 1) {
      while (!PT_isArgsEmpty(alternativeTrees)) {
        PT_Tree current = PT_getArgsHead(alternativeTrees);

        PT_Args rest = PT_removeArgsTree(filteredAlternativeTrees, current);
        filteredAlternativeTrees = filterOneAlternativeAgainstEachSibling(pt, rest, current);

        alternativeTrees = PT_getArgsTail(alternativeTrees);
      }
    }       
  } 

  return filteredAlternativeTrees;
}

/** 
 *  A valid ambiguity node must have more than one child.
 * 
 * \param ambChildren 
 * 
 * \return 
 */
static PT_Tree createTreeNode(PT_Args ambChildren) {
  int len = PT_getArgsLength(ambChildren);

  if (len == 0) {
    return (PT_Tree) NULL;
  }
  else if (len == 1) {
    return PT_getArgsHead(ambChildren);
  }
  else {
    SGLR_STATS_incrementCount(SGLR_STATS_ambTreeNodesCreatedDuringFiltering);
    return PT_makeTreeAmb(ambChildren);
  }
}

/** 
 * Filters a list of tree arguments. 
 * This nifty piece of code prevents us from doing a reverse
 * of the resulting arguments after filtering. We use the C stack to
 * store the results and construct a list in the correct order on
 * the way back from the recursion.
 * 
 * \param pt    the parse table for filtering information
 * \param args  the arguments to filter
 * \param pos   the current offset in the parse forest
 * \param cycle  \c true if traversing a cycle; \c false otherwise.
 * \param level  the nesting level of ambiguity clusters
 * 
 * \return normally the same number of arguments, but different ones
 *         since one of their (grand)children could have been a filtered
 *         cluster. If one of the children dissappears, then all of them
 *         do, so \c NULL is returned.
 */
static PT_Args filterChildren(ParseTable *pt, PT_Args args, size_t *pos, ATbool cycle, int level) {
  if (!PT_isArgsEmpty(args)) {
    PT_Tree arg = PT_getArgsHead(args);
    PT_Args tail = PT_getArgsTail(args);
    PT_Tree newarg = filterRecursive(pt, arg, pos, ATfalse, cycle, level+1);
    PT_Args newtail = filterChildren(pt, tail, pos, cycle, level);
   
    if (newarg && newtail) {
      /* If an ambiguity below the current node of the tree is filtered out
       * through the call to filterRecursive then the resulting tree will 
       * be different, so we return the new children of the current tree. 
       * Likewise we must propagate any of the children that have been 
       * changed. */
      
      if (!PT_isEqualTree(newarg, arg) || !PT_isEqualArgs(newtail, tail)) { 
        return PT_makeArgsMany(newarg, newtail);
      } 
      else {
        return args;
      }
    }
    else {
      return (PT_Args) NULL;
    }
  }

  return PT_makeArgsEmpty();
}

/** 
 * Determines if the tree being traversed is a cycle.
 * 
 * \param clusterIndex 
 * 
 * \return \c true if the tree is cyclic; \c false otherwise.
 */
static ATbool detectCycle(ATerm clusterIndex) {
  if (clusterIndex && SG_getLevel(clusterIndex) != -1) {
    SGLR_STATS_incrementCount(SGLR_STATS_cyclesDetected);
    return ATtrue;
  }	    

  return ATfalse;
}

/** 
 * Creates a cyclic parse tree node. 
 *
 * \param inAmbs 
 * \param cycleLength 
 * 
 * \return a new cyclic node, or \c NULL if cycles should be filtered out of 
 * the tree.
 */
static PT_Tree createCycle(PT_Args ambs, int cycleLength) {
  SGLR_STATS_incrementCount(SGLR_STATS_cyclicTreeNodesCreated);
  if (!FLT_getRemoveCyclesFlag()) {
    PT_Tree first = PT_getArgsHead(ambs);
    PT_Production prod = PT_getTreeProd(first);
    PT_Symbol rhs = PT_getProductionRhs(prod);

    /* the second argument is the number of levels in the cyclic tree */
    return PT_makeTreeCycle(rhs, cycleLength);
  }
  else {
    /* filter cycles out of tree */
    return (PT_Tree) NULL;
  }
}

/** 
 * Returns the list of ambiguous trees if there is an ambiguity at the given 
 * position by finding the cluster for the given tree node.  
 * 
 * \param t 
 * \param pos the current position within the input string.
 * 
 * \return the \c PT_Args of ambiguous parse trees if there is an ambiguity; 
 * \c NULL otherwise.
 */
static PT_Args detectAmbiguity(PT_Tree t, const size_t *pos, ATbool inAmbs) {
  if (inAmbs == ATfalse && SG_InputAmbiMapIsSet(*pos) > 0) {
    PT_Args ambiguityCluster = SG_AmbiTablesGetCluster(t, *pos);

    if (ambiguityCluster && !PT_isArgsEmpty(ambiguityCluster)) {
      return ambiguityCluster;
    }
  }

  return (PT_Args)NULL;
}


/** 
 * 
 * 
 * \param pt 
 * \param ambiguousTrees 
 * \param pos 
 * \param cycle 
 * \param level 
 * 
 * \return 
 */
static PT_Tree filterAmbiguity(ParseTable *pt, PT_Args ambiguousTrees, size_t *pos, ATbool cycle, int level) {
  PT_Tree newTreeNode;

  if (FLT_getRejectFlag() && isAmbiguityRejected(pt, ambiguousTrees, pos, cycle, level)) {
    SGLR_STATS_incrementCount(SGLR_STATS_treesRejectFiltered);
    return (PT_Tree)NULL;
  }

  ambiguousTrees = filterAmbiguousTreesRecursive(pt, ambiguousTrees, pos, cycle, level);
  ambiguousTrees = filterAmbiguousAlternatives(pt, ambiguousTrees);
  
  newTreeNode = createTreeNode(ambiguousTrees); 

  if (PARSER_getDebugFlag) {
    /*ATfprintf(LOG_log(), "Ambiguity cluster contains %d node(s).\n", PT_getArgsLength(ambiguousTrees));*/
  }

  return newTreeNode;
}

/** 
 * If the given tree node is a direct (the first?) child of an ambiguous 
 * node (#inAmbs == true), then #ambiguousTrees will not be empty because the 
 * same node is used to index into the ambiTable ie., if this is a real 
 * ambiguity (ie., we are not already traversing its children) then 
 * traverse over the ambiguous children and apply all necessary 
 * filters.  
 * 
 * Note the memoization: all newly created ambiguity nodes are added to a 
 * table that is indexed on its children and the start position of the 
 * sub-string they derive. Before filtering (and maybe creation)
 * of a new ambiguity node in filterAmbiguity(), the table is 
 * searched for any existing nodes that have the same children and derive the 
 * same sub-string at the same starting position. This avoids filtering the 
 * same tree more than once. The position information is included when 
 * indexing into the table to prevent overzealous sharing.
 * 
 * \param pt the parse table
 * \param ambiguousTrees
 * \param pos the current offset in the forest
 * \param cycle \c true if traversing a cycle; \c false otherwise.
 * \param clusterIndex 
 * \param level the nesting level of ambiguity clusters
 * 
 * \return 
 */
static PT_Tree filterAmbiguityWithMemoization(ParseTable *pt, PT_Args ambiguousTrees, size_t *pos, ATbool cycle, ATerm clusterIndex, int level) {
  ATerm key = SG_CreateAmbiArgsKey(ambiguousTrees, *pos);
  PT_Tree newTreeNode = (PT_Tree)ATtableGet(resolvedtable, key);

  if ((ATindexedSetGetIndex(cyclicLevels, (ATerm) ATmakeInt(*pos)) != -1) || !newTreeNode) {
    SG_setLevel(clusterIndex, level);
    newTreeNode = filterAmbiguity(pt, ambiguousTrees, pos, cycle, level);
    SG_unsetLevel(clusterIndex);
  
    if (newTreeNode) {
      ATtablePut(resolvedtable, key, (ATerm) newTreeNode);
      ATtablePut(postable, key, (ATerm)ATmakeInt(*pos));
    }
    else {
      return (PT_Tree) NULL;
    }
  }
  else {
    *pos = ATgetInt((ATermInt)ATtableGet(postable, key));
  }

  return newTreeNode;
}

/** 
 * Either the given tree node is a direct child of an ambiguous node, in
 * which case we have already started filtering the ambiguity's children
 * so we can continue normally; or the given tree node is not ambiguous.
 * 
 * \param pt the parse table
 * \param t 
 * \param pos the current offset in the forest 
 * \param cycle \c true if traversing a cycle; \c false otherwise.
 * \param level the nesting level of ambiguity clusters
 * 
 * \return 
 */
static PT_Tree filterTree(ParseTable *pt, PT_Tree t, size_t *pos, ATbool cycle, int level) {
  PT_Args args = PT_getTreeArgs(t);
  PT_Args newargs = filterChildren(pt, args, pos, cycle, level);

  if ((FLT_getRejectFlag() && isTreeRejected(pt, t)) || !newargs) {
    SGLR_STATS_incrementCount(SGLR_STATS_treesRejectFiltered);
    return (PT_Tree) NULL;
  }

  SGLR_STATS_incrementCount(SGLR_STATS_prodTreeNodesCreatedDuringFiltering);
  return PT_setTreeArgs(t, newargs);
}

/** 
 * Recursively applies all filters to all tree nodes, including the ones
 * in ambiguity clusters, in a bottom-up fashion.
 *
 * #inAmbs is needed here because the first child of an ambiguity node is
 * used to index into the ambiguity table. This same child is then the 
 * first of the children of the ambiguity node to be traversed (if #inAmbs is 
 * ignored then the filtering will not terminate).  
 * 
 * \see FLT_filter().
 * 
 * \param pt    the parse table for filtering information
 * \param t     the tree to filter (either a normal tree or a cluster)
 * \param pos   the current offset in the forest
 * \param inAmbs \c true if #t is a direct child of an ambiguity node; 
 * \c false otherwise.
 * \param cycle  \c true if traversing a cycle; \c false otherwise.
 * \param level  the nesting level of ambiguity clusters
 * 
 * \return An ambiguity node with the filtered children in it, if it was a 
 *         cluster; or a modified tree, if one of the grandchildren was a 
 *         cluster; or NULL, if one of the grandchildren was filtered 
 *         completely.
 */
static PT_Tree filterRecursive(ParseTable *pt, PT_Tree t, size_t *pos, ATbool inAmbs, ATbool cycle, int level) {
  /*assert(!PT_isTreeAmb(t) && "we expect to deal with the amb tables here");*/

  if (PT_isTreeAppl(t)) {
    PT_Args ambiguity = detectAmbiguity(t, pos, inAmbs);
      
    if (ambiguity) {
      ATerm clusterIndex = SG_AmbiTablesGetIndex(t, *pos);
      if (detectCycle(clusterIndex)) {
        ATindexedSetPut(cyclicLevels, (ATerm) ATmakeInt(*pos), NULL);
        return createCycle(ambiguity, level-SG_getLevel(clusterIndex));
      }

      t = filterAmbiguityWithMemoization(pt, ambiguity, pos, cycle, 
					 clusterIndex, level);
    }
    else {
      t = filterTree(pt, t, pos, cycle, level);
    }
  }
  else {
    assert(PT_isTreeChar(t) && "we only expect appls and chars here");
    *pos = *pos + 1;
    if (PARSER_getVerboseFlag) {
      SG_printStatusBar("sglr: filtering", *pos, IS_getLength(inputString));
    }
  }

  if (FLT_getPriorityFlag() && t != NULL) {
    return priorityFilter(pt, t);
  }
  else {
    return t;
  }
}

static void countNodesInTree(PT_Tree t, int *leaves, int *prodNodes, int *ambNodes) {
  PT_Args args = NULL;
  int newLeaves = 0;
  int newProdNodes = 0;
  int newAmbNodes = 0;
  AFun countAFun = ATmakeAFun("count", 3, ATfalse);
  ATermAppl nodeCountEntry = NULL;

  if (PT_isTreeAmb(t)) {
    int ambLeaves = 0;
    int ambProdNodes = 0;
    int ambAmbNodes = 0;

    SGLR_STATS_incrementCount(SGLR_STATS_ambNodesInFilteredTree);
    args = PT_getTreeArgs(t);
    nodeCountEntry = (ATermAppl)ATtableGet(nodeCountTable, (ATerm)t);

    if (nodeCountEntry == NULL) {
      for (;args && !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
        newLeaves = 0;
        newProdNodes = 0;
        newAmbNodes = 0;
        countNodesInTree(PT_getArgsHead(args), &newLeaves, &newProdNodes, &newAmbNodes);
        ambLeaves += newLeaves;
        ambProdNodes += newProdNodes;
        ambAmbNodes += newAmbNodes;
      }

      (*leaves) += ambLeaves;
      (*prodNodes) += ambProdNodes;
      (*ambNodes) += ambAmbNodes;

      ATtablePut(nodeCountTable, (ATerm)t, (ATerm)ATmakeAppl3(countAFun, (ATerm)ATmakeInt(ambLeaves), (ATerm)ATmakeInt(ambProdNodes), (ATerm)ATmakeInt(ambAmbNodes)));
      (*ambNodes)++;
    }
    /*else {
        (*leaves) += ATgetInt((ATermInt)ATgetArgument(nodeCountEntry, 0));
        (*prodNodes) += ATgetInt((ATermInt)ATgetArgument(nodeCountEntry, 1));
        (*ambNodes) += ATgetInt((ATermInt)ATgetArgument(nodeCountEntry, 2));
      }

      (*ambNodes)++;*/
  }

  else if (PT_isTreeChar(t)) {
    SGLR_STATS_incrementCount(SGLR_STATS_symbolNodesInFilteredTree);
    (*leaves)++;
  }

  else if (PT_isTreeAppl(t)) {
    SGLR_STATS_incrementCount(SGLR_STATS_prodNodesInFilteredTree);
    args = PT_getTreeArgs(t);

    for (;args && !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
      newLeaves = 0;
      newProdNodes = 0;
      newAmbNodes = 0;
      countNodesInTree(PT_getArgsHead(args), &newLeaves, &newProdNodes, &newAmbNodes);
      (*leaves) += newLeaves;
      (*prodNodes) += newProdNodes;
      (*ambNodes) += newAmbNodes;
    }

    (*prodNodes)++;
  }

  else if (PT_isTreeCycle(t)) {
    SGLR_STATS_incrementCount(SGLR_STATS_cyclicNodesInFilteredTree);
    assert("Can't deal with cycles yet!");
  }
  else {
    assert("Illegal tree node type!");
  }
}

/** 
* Counts the number of ambiguities in the (maximally shared) tree given. 
* Note the memoization. Without it, this search becomes too expensive. 
* 
* \param t the root node to begin counting from.
* \param ambs the number of ambiguities counted.
* 
* \return the number of ambiguities found in the maximally shared 
* representation of the given tree.
*/
static int countAmbiguitiesInTree(PT_Tree t, int ambs) {
  if (PT_isTreeAppl(t) || PT_isTreeAmb(t)) {
    PT_Tree seenAmbiguity = NULL;
    PT_Args args = PT_getTreeArgs(t);

    if (PT_isTreeAmb(t)) {
      seenAmbiguity = (PT_Tree)ATtableGet(seenAmbiguities, (ATerm) t);
      if (!seenAmbiguity) {
        ATtablePut(seenAmbiguities, (ATerm) t, (ATerm) t);
        ambs++;
      }
    }   

    for (; !PT_isArgsEmpty(args) && !seenAmbiguity; args = PT_getArgsTail(args)) {
      ambs = countAmbiguitiesInTree(PT_getArgsHead(args), ambs);
    }
  }


  return ambs; 
}

/** 
* Counts the number of ambiguities in the (maximally shared) tree given. 
* Note the memoization. Without it, this search becomes too expensive. 
* 
* \param t the root node to begin counting from.
* \param ambs the number of ambiguities counted.
* 
* \return the number of ambiguities found in the given tree, taken position
* information into account.
*/
static int countPosIndependentAmbsInTree(PT_Tree t, int ambs, int *pos) {
  if (PT_isTreeAppl(t) || PT_isTreeAmb(t)) {
    PT_Tree seenAmbiguity = NULL;
    PT_Args args = PT_getTreeArgs(t);

    if (PT_isTreeAmb(t)) {
      ATerm key = (ATerm) ATmakeList2((ATerm) t, (ATerm) ATmakeInt(*pos));
      seenAmbiguity = (PT_Tree)ATtableGet(seenAmbiguities, key);
      if (!seenAmbiguity) {
        ATtablePut(seenAmbiguities, key, (ATerm) t);
        ambs++;
      }
    }   

    for (; !PT_isArgsEmpty(args) && !seenAmbiguity; args = PT_getArgsTail(args)) {
      PT_Tree arg = PT_getArgsHead(args);
      if (PT_isTreeChar(arg)) {
	(*pos)++;
      }
      ambs = countPosIndependentAmbsInTree(arg, ambs, pos);
    }
  }


  return ambs; 
}

/** 
 * Recursively applies all filters to all tree nodes, including the ones
 * in ambiguity clusters, in a bottom-up fashion. This function also marks
 * the transition from ambiguity clusters stored in a hashtable to the
 * use of the #PT_Tree ambiguity constructor. Cyclic derivations are also
 * detected on the fly and translated to #PT_Tree cycle constructors.
 *
 * This function initializes a number of cashing and memoization structures,
 * while the helper function filterRecursive() implements the recursion.
 *  
 * \todo filters can also return errors -- take care of this in the interface 
 * of FLT_filter.
 *
 * \param pt the parse table used for filtering information
 * \param t  the parse forest to filter
 * 
 * \return a filtered forest, with ambiguity nodes instead of references
 *         to ambiguity clusters, and cycle nodes instead of actual cycles.
 */
PT_ParseTree FLT_filter(ParseTable *pt, PT_Tree t, InputString input) {
   PT_Tree newT;
   size_t pos = 0;
   int numberOfAmbiguitiesInTree = 0;

   inputString = input;

   resolvedtable = ATtableCreate(2048, 75);
   postable = ATtableCreate(2048, 75);
   seenAmbiguities = ATtableCreate(2048, 75);
   cyclicLevels = ATindexedSetCreate(2048, 75);

   if (FLT_getSelectTopNonterminalFlag()) {
     const char *topNonterminal = FLT_getTopNonterminal();

     t = filterOnTopSort(pt, t, topNonterminal, FLT_getTopNonterminalIsATermFlag()); 

     if (t == NULL) {
       char *errorDesc = "Entire parse tree removed during filtering because the tree's root node is not labelled by the given sort name";
       ERR_Subject subject = ERR_makeSubjectSubject(FLT_getTopNonterminal());
       ERR_managerStoreError(errorDesc, ERR_makeSubjectListSingle(subject));
       return (PT_ParseTree) NULL;
     }
   }

   SG_initLevels();
   newT = filterRecursive(pt, t, &pos, ATfalse, ATfalse, 0);
   SG_cleanupLevels();

   if (PARSER_getVerboseFlag) {
     /* print 100% bar, the rest was solved by caching ambclusters */
     SG_printStatusBar("sglr: filtering", pos, IS_getLength(inputString));
     SG_printDotAndNewLine();
   }
  
   if (newT) {
     if (MAIN_getCountPosIndependentAmbsFlag()) {
       int pos = 0;
       numberOfAmbiguitiesInTree = countPosIndependentAmbsInTree(newT,0,&pos);
     } else {
       numberOfAmbiguitiesInTree = countAmbiguitiesInTree(newT,0);
     }

     if (MAIN_getStatsFlag) {
       int leaves = 0;
       int prodNodes = 0;
       int ambNodes = 0;

       nodeCountTable = ATtableCreate(2048, 75);
       countNodesInTree(newT, &leaves, &prodNodes, &ambNodes);
       ATtableDestroy(nodeCountTable);

       SGLR_STATS_setCount(SGLR_STATS_symbolNodesInFilteredTree, leaves);
       SGLR_STATS_setCount(SGLR_STATS_prodNodesInFilteredTree, prodNodes);
       SGLR_STATS_setCount(SGLR_STATS_ambNodesInFilteredTree, ambNodes);
     }
   }

   ATtableDestroy(resolvedtable);
   ATtableDestroy(postable);
   ATtableDestroy(seenAmbiguities);
   ATindexedSetDestroy(cyclicLevels);

   if (!newT) {
     char *errorDesc = "Entire parse tree removed during filtering";
     ERR_Subject subject = ERR_makeSubjectSubject(IS_getPath(input));
     ERR_managerStoreError(errorDesc, ERR_makeSubjectListSingle(subject));
     return (PT_ParseTree) NULL;
   }
       
   return PT_makeParseTreeTop(newT, numberOfAmbiguitiesInTree); 
}
