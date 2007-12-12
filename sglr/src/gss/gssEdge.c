/*$Id$*/

/** \file 
 * \ingroup gss
 *
 * This file implements the construction, destruction and accessor functions 
 * of GSS edges.
 */

#include "gssEdge-api.h"
#include "gssGarbageCollector.h"
#include "memoryManagerGenerator.h"
#include "mainOptions.h"
#include "parserStatistics.h"
#include <assert.h>

/** 
 * This is the GSS Edge struct.
 */
struct _GSSEdge {
  GSSNode targetGSSNode;        /**< the GSS node that the edge points to.*/
  PT_Tree tree;                 /**< the parse tree node that labels the edge.*/
  size_t  numberOfLeavesOfTree; /**< the number of leaf nodes the parse tree 
                                   node has.*/
  ATbool  isRejected;           /**< the reject attribute assoiciated with an 
                                   edge.*/
  struct _GSSEdge *nextFree;    /**< the next free GSS edge. This field is 
                                  required by the memory manager generator. 
                                  It is used to point to the next free element 
                                  in the free list once the node is garbage 
                                  collected. 
                                  \see GENERATE_MEMORY_MANAGER */
}; 

static const int EDGE_MEM_CHUNK = (8*64);

GENERATE_MEMORY_MANAGER(GSSEdge, _GSSEdge, nextFree, EDGE_MEM_CHUNK)

/** 
 * Creates a new edge in the GSS, labelled with the specified parse tree node, 
 * to the specified GSS node.
 * 
 * \param t the parse tree node to label the edge with
 * \param numberOfLeavesInTree the number of leaf nodes that the parse tree 
 * node has
 * \param target the GSS node to point to
 * \param rejected ATtrue if the edge is rejected
 * 
 * \return the newly created edge
 */
GSSEdge GSSEdge_createEdge(PT_Tree t, size_t numberOfLeavesInTree, GSSNode target, ATbool rejected) {
  int isNew;
  GSSEdge edge = mallocGSSEdge(&isNew);
  assert((isNew == 0 || isNew == 1) && "memory allocation has gone wrong!");

  if (edge == NULL) {
    ATerror("%s:%d Could not allocate %d bits of memory\n", __FILE__, 
	    __LINE__, EDGE_MEM_CHUNK);
  }

  edge->tree = t;
  if (isNew == 1) {
    PT_protectTree(&(edge->tree));
  }
  edge->numberOfLeavesOfTree = numberOfLeavesInTree;
  edge->targetGSSNode = target;
  edge->isRejected = rejected;

  SGLR_STATS_incrementCountConditionally(SGLR_STATS_rejectedEdgesCreated,rejected);
  SGLR_STATS_incrementCount(SGLR_STATS_gssEdgesCreated);

  return edge;
}

/** 
 * Deletes the specified edge from the GSS. 
 * 
 * \param edge the GSS edge to delete
 */
void GSSEdge_deleteGSSEdge(GSSEdge edge) {
  if (edge == NULL) {
    ATwarning("NULL GSSEdge not deleted!\n");
    return;
  }
  freeGSSEdge(edge);
}

/** 
 * Sets the target GSS node of the specified edge.
 * 
 * \param edge the GSS edge to set the target for
 * \param target the GSS node to set
 */
void GSSEdge_setTargetGSSNode(GSSEdge edge, GSSNode target) {
  edge->targetGSSNode = target;
}

/** 
 * Sets parse tree node for the given GSS edge. In other words, it sets the 
 * label of the edge.
 * 
 * \param edge the edge to set the parse tree node for
 * \param t the parse tree node
 */
void GSSEdge_setTree(GSSEdge edge, PT_Tree t) {
  edge->tree = t;
}

/** 
 * Sets the number of leaf nodes that the parse tree node that labels the 
 * given edge has.
 * 
 * \param edge the edge to set the number of leaf nodes for
 * \param numberOfLeaves the number of leaf nodes
 */
void GSSEdge_setNumberOfLeavesInTree(GSSEdge edge, size_t numberOfLeaves) {
  edge->numberOfLeavesOfTree = numberOfLeaves;
}

/** Sets the specified edge as rejected. Edges can only ever become rejected; a
 * rejected edge cannot become non-rejected.
 * 
 * \param gssEdge the edge to set as rejected 
 */
void GSSEdge_setRejected(GSSEdge gssEdge) {
  /* Need to check if all edges are rejected and increment or decrement 
   * the number of rejected nodes. */
  SGLR_STATS_incrementCountConditionally(SGLR_STATS_existingEdgesRejected, gssEdge->isRejected == ATfalse);
  gssEdge->isRejected = ATtrue;	
}

/** 
 * Returns the target GSS node of the specified edge. 
 * 
 * \param edge the edge for which the target node is requested
 * 
 * \return the target GSS node of the edge
 */
GSSNode GSSEdge_getTargetGSSNode(GSSEdge edge) {
  return edge->targetGSSNode;
}

/** 
 * Returns the parse tree node that labels the given edge. These parse tree 
 * nodes are collected during a reduction and label the children of the parse 
 * tree node created for the reduction.
 * 
 * \param edge the edge for which the parse tree node is requested
 * 
 * \return the parse tree node of the edge
 */
PT_Tree GSSEdge_getTree(GSSEdge edge) {
  return edge->tree;
}

/** 
 * Returns the number of leaf nodes of the parse tree node that labels the 
 * given edge.
 * 
 * \param edge the edge for which the number of leaves are requested 
 * 
 * \return the number of leaf nodes of the parse tree that label the edge
 */
int GSSEdge_getNumberOfLeavesInTree(GSSEdge edge) {
  return edge->numberOfLeavesOfTree;
}

/** 
 * Determines if the specified edge is rejected. An edge is considered to be 
 * rejected if it was created by a reduction whose production rule has a reject 
 * attribute associated with it. 
 * 
 * \param edge the edge to be tested
 * 
 * \return \c ATtrue if the edge is rejected; \c ATfalse otherwise.
 */
ATbool GSSEdge_isRejected(GSSEdge edge) {
  return edge->isRejected;
}
