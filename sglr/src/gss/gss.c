/*$Id$*/

/** \file
 * \ingroup gss
 *
 * This file implements the construction and searching functions of the Graph 
 * Structured Stack (GSS) that are used during parsing by the 
 * \ref parser "SGLR" algorithm.
 */

#include <stdlib.h>
#include "gss.h"
#include "parserStatistics.h"
#include "gssGarbageCollector.h"

static ReductionPath findAllPathsRecursive(GSSNode st, int nrArgs, 
					   PT_Args sons, size_t length,
					   ReductionPath paths);

#define GC_CYCLE 200
static GSSNodeList oldLevels[GC_CYCLE];
static GSSNodeList currentLevel = NULL;
static int levelNumber = 0;

static int edgeVisitsPerReduction; /**< used for stat logging. */

static GSSNode acceptNode = NULL;

/** 
 * Adds the GSS start node to the current level.
 * 
 * \param s the GSS node labelled by the DFA start state
 *
 * \todo Remove function. 
 */
void GSS_createStartNode(GSSNode s) {
  currentLevel = GSS_addNodeListElement(s,currentLevel);
}

void GSS_setAcceptNode(GSSNode s) {
  acceptNode = s;
}

GSSNode GSS_getAcceptNode(void) {
  return acceptNode;
}

/** 
 * Searches for a GSS node, in the current level of the GSS, that is labelled 
 * with the specified state number.  
 * 
 * \param stateNum the state number to search for
 * 
 * \return the GSS node labelled by stateNum if it exists in the current level;
 *  \c NULL otherwise.
 */
GSSNode GSS_findNodeInCurrentLevel(int stateNum) {
  GSSNodeList tmp;
  GSSNode node;

  for (tmp = currentLevel; tmp != NULL; tmp = GSS_getNodeListTail(tmp)) {
    
    node = GSS_getNodeListHead(tmp);    
    if (GSSNode_getStateNumber(node) == stateNum){
      return node;
    }
  }
  return NULL;
}

#if SGLR_COLLECT_STATISTICS
static void countRejectedNodesInCurrentLevel(void) {
  GSSNodeList tmp;
  GSSNode node;

  for (tmp = currentLevel; tmp != NULL; tmp = GSS_getNodeListTail(tmp)) {
    node = GSS_getNodeListHead(tmp);
    GSSNode_rejectStatus(node);
  }
}
#else
static void countRejectedNodesInCurrentLevel(void) { ; }
#endif

/** 
 * Adds a new level to the GSS, garbage collects the old levels, and increments 
 * the number of levels in the GSS. 
 * It is used in the shifter() once the new level has been constructed. 
 * The current level should not be freed since the garbage collector uses the 
 * old levels to find any dead branches of the GSS.
 * 
 * \param list the list of GSS nodes to add to the current level
 */
void GSS_addNewLevel(GSSNodeList list) { 
  countRejectedNodesInCurrentLevel();
  oldLevels[levelNumber % GC_CYCLE] = currentLevel;

  if ((levelNumber % GC_CYCLE) == (GC_CYCLE-1)) {
    GC_gssBranches(oldLevels, GC_CYCLE, list, acceptNode);
  }

  currentLevel = list;
  levelNumber++;
}

/** 
 * Returns the list of GSS nodes in the current level.
 * 
 * \return the GSS node list in the current level
 */
GSSNodeList GSS_getCurrentLevel(void) {
  return currentLevel;
}

/** 
 * Removes all GSS nodes from the current level in the GSS.
 *
 * \todo I think this function is now redundant and should be removed.
 */
void GSS_clearCurrentLevel(void) {
  GSSNodeList tmp = currentLevel;

  while (currentLevel != NULL) {
    tmp = currentLevel;
    currentLevel = GSS_getNodeListTail(currentLevel);
    GSS_deleteNodeList(tmp);
  }
}

/** 
 * Adds a GSS node to the current level.
 * 
 * \param node the GSS node to be added
 */
void GSS_addToCurrentLevel(GSSNode node) {
  currentLevel = GSS_addNodeListElement(node, currentLevel);
}


/** 
 * Returns the GSS edge between the two specified GSS nodes.
 * 
 * \param source the source GSS node 
 * \param target the target GSS node
 * 
 * \return the edge between the source and target GSS nodes if it exists, 
 * or \c NULL otherwise
 */
GSSEdge GSS_findDirectEdge(GSSNode source, GSSNode target) {
  GSSEdgeList edges = NULL;

  for (edges = GSSNode_getEdgeList(source); edges; edges = GSS_getEdgeListTail(edges)) {
    SGLR_STATS_incrementCount(SGLR_STATS_gssEdgesSearched);
    if (GSSEdge_getTargetGSSNode(GSS_getEdgeListHead(edges)) == target) {
      return GSS_getEdgeListHead(edges);
    }
  }
  return NULL;
}

/**
 * Searches all paths of the specified length from the specified GSS node, 
 * collecting the tree nodes that label each edge that is traversed. The list 
 * containing the target GSS nodes and tree nodes of each traversal are 
 * returned as a #ReductionPath.
 * 
 * \param source the GSS node to begin the search from
 * \param reductionLength the length of the search path
 * 
 * \return the #ReductionPath traversed
 */
ReductionPath GSS_findAllPaths(GSSNode source, int reductionLength, int level) {
  ReductionPath result;

  edgeVisitsPerReduction = 0;
  result = findAllPathsRecursive(source, reductionLength, PT_makeArgsEmpty(), 0, NULL);

  SGLR_STATS_addEdgeVisitForReductionLength(reductionLength, edgeVisitsPerReduction);
  SGLR_STATS_addEdgeVisitsForLevel(level, edgeVisitsPerReduction);
  return result; 
}

static ReductionPath findAllPathsRecursive(GSSNode node, int reductionLength, PT_Args sons, size_t length, ReductionPath paths) {
  register GSSEdgeList edges = NULL;
  PT_Args newsons = NULL;

  if (node == NULL) {
    return paths;
  }

  if (reductionLength == 0) {
    paths = GSS_addReductionPath(node, sons, length, paths);
  }
  else if (reductionLength > 0) {
    for (edges = GSSNode_getEdgeList(node); edges; edges = GSS_getEdgeListTail(edges)) {
      GSSEdge edge = GSS_getEdgeListHead(edges);
      newsons = PT_makeArgsMany(GSSEdge_getTree(edge), sons);
      paths = findAllPathsRecursive(GSSEdge_getTargetGSSNode(edge), 
				    reductionLength - 1, newsons, 
				    length + GSSEdge_getNumberOfLeavesInTree(edge), 
				    paths);

      SGLR_STATS_incrementCount(SGLR_STATS_gssEdgesTraversed);
      edgeVisitsPerReduction++;
    }
  }
  return paths;
}


/** 
 * Searches for the specified edge in the GSS, on a path of the specified 
 * reduction length from the specified source GSS node.
 * 
 * \param source the GSS node to search from
 * \param reductionLength the length of the path to traverse
 * \param edge the edge to search for
 * 
 * \return \c true if the edge is found, or \c false otherwise
 */
static ATbool findEdge(GSSNode source, int reductionLength, GSSEdge edge) {
  register GSSEdgeList edges = NULL;
  GSSEdge searchEdge = NULL;

  if (reductionLength > 0) {
    
    for (edges = GSSNode_getEdgeList(source); edges; edges = GSS_getEdgeListTail(edges)) {
      
      SGLR_STATS_incrementCount(SGLR_STATS_gssLimitedEdgesSearched);
      searchEdge = GSS_getEdgeListHead(edges);
      
      if (edge == searchEdge || 
	  findEdge(GSSEdge_getTargetGSSNode(searchEdge), reductionLength-1, edge)) {
        return ATtrue;
      }
    }
  }
  return ATfalse;
}


/** 
 * Searches all paths in the GSS, with the specified length, from the specified
 * GSS node, looking for the specified edge if #linkSeen is \c true.
 * 
 * \param source the GSS node to search from
 * \param reductionLength the length of the path to traverse
 * \param edge the edge to search for
 * \param linkSeen 
 * \param sons 
 * \param numberOfLeavesInTree 
 * \param paths 
 * 
 * \return the #ReductionPath that contains the path through the GSS from the 
 * speciefied GSS node that traverses the specified GSS edge
 */
static ReductionPath findPaths(GSSNode source, int reductionLength, GSSEdge edge, ATbool linkSeen, PT_Args sons, size_t numberOfLeavesInTree, ReductionPath paths) {
  register GSSEdgeList edges = NULL;
  GSSEdge l1 = NULL;
  PT_Args newsons = NULL;

  if (!source) {
    return paths;
  }

  if (reductionLength == 0 && linkSeen) {
    paths = GSS_addReductionPath(source, sons, numberOfLeavesInTree, paths);
  }
  else if (reductionLength > 0) {
    for (edges = GSSNode_getEdgeList(source); edges; edges = GSS_getEdgeListTail(edges)) {
      l1 = GSS_getEdgeListHead(edges);
      newsons = PT_makeArgsMany(GSSEdge_getTree(l1), sons);
      paths = findPaths(GSSEdge_getTargetGSSNode(l1), reductionLength - 1, 
			edge, linkSeen || (edge == l1), newsons, 
			numberOfLeavesInTree + GSSEdge_getNumberOfLeavesInTree(l1),
			paths);
      SGLR_STATS_incrementCount(SGLR_STATS_gssLimitedEdgesTraversed);
      edgeVisitsPerReduction++;
    }
  }
  return paths;
}

/** 
 * Returns the #ReductionPath with the specified length, from the specified GSS
 * node that traverses the specified GSS edge. This function is the 
 * Farshi-style, brute force correction to Tomita's original GLR algorithm 
 * that fails to parse some hidden right recursive grammars.
 * 
 * \param source the GSS node to search from
 * \param reductionLength the length of the path to search
 * \param edge the GSS edge that the path must traverse
 * 
 * \return the #ReductionPath from the specified GSS node that traverses the 
 * specified GSS edge
 */
ReductionPath GSS_findLimitedPaths(GSSNode source, int reductionLength, GSSEdge edge, int level) {
  ReductionPath result = NULL;
  edgeVisitsPerReduction = 0;

  if (findEdge(source, reductionLength, edge)) {
    result = findPaths(source, reductionLength, edge, ATfalse, PT_makeArgsEmpty(), 0, NULL);
  }

  SGLR_STATS_addEdgeVisitForReductionLength(reductionLength, edgeVisitsPerReduction);
  SGLR_STATS_addEdgeVisitsForLevel(level, edgeVisitsPerReduction);
  return result;
}

void GSS_freeGSS(void) {
  oldLevels[(levelNumber % GC_CYCLE)] = currentLevel;
  GC_gssBranches(oldLevels, (levelNumber % GC_CYCLE)+1, NULL, acceptNode);

  if (acceptNode) {
    GC_gssBranch(acceptNode);
  }

  currentLevel = NULL;
  acceptNode = NULL;
  levelNumber = 0;
}
