/*$Id$*/

/** \file
 * \ingroup gss
 *
 * This file implements the constructor, destructor and accessor functions of 
 * GSS nodes.
 */

#include "gssNode-data.h"
#include "gssGarbageCollector.h"
#include "memoryManagerGenerator.h"
#include "assert.h"

/** 
 * This is the GSS node struct.
 */
struct _GSSNode {
  GSSEdgeList     edges;    /**< the list of edges leaving the node.*/
  int             state;    /**< the state number of the node. */
  short           refCount; /**< used by the garbage collector and should be 
                              called inEdgeCount. \see gssGarbageCollector.c*/
  short           isAlive;   /**< used only during garbage collection. */
  ATbool          isShift;   /**< set to \c true if the node is created as a 
                               result of a shift action. 
                               \todo is this field redundant? */
  struct _GSSNode *nextFree; /**< the next free GSS node. This field is required
                               by the memory manager generator. It is used to 
                               point to the next free element in the free list 
                               once the node is garbage collected.
                               \see GENERATE_MEMORY_MANAGER */
};

static const int NODE_MEM_CHUNK = (4*64);

GENERATE_MEMORY_MANAGER(GSSNode,_GSSNode,nextFree,NODE_MEM_CHUNK)
     

/** 
 * Creates a new node in the GSS labelled with the given state number. If the 
 * node is created as a result of a shift then #isShift should be set to 
 * \c true.
 * 
 * \param stateNum the nodes state number.
 * \param isShift set to \c true if the node is created as a result of a shift.
 * 
 * \return the newly created GSS node.
 */
GSSNode GSSNode_createNode(int stateNum, ATbool isShift) {
  int isNew;
  GSSNode node = mallocGSSNode(&isNew);

  if (node == NULL) {
    ATerror("%s:%d Could not allocate %d bits of memory\n", __FILE__, 
	    __LINE__, NODE_MEM_CHUNK);
  }

  node->state     = stateNum;
  node->edges     = NULL;
  node->refCount  = 0;
  node->isAlive   = 0;
  node->isShift   = isShift;
  node->nextFree  = NULL;
  
  return node;
}

/** 
 * Deletes the specified node from the GSS.
 * 
 * \param node the GSS node to delete.
 */
void GSSNode_deleteGSSNode(GSSNode node) {

  if (node == NULL) {
    ATwarning("NULL GSSNode not deleted!\n");
    return;
  }

  /* A node should only be deleted if it has already been garbage collected. */
  assert(node->refCount == -1);
  freeGSSNode(node);
  /** \todo Comment appropriatelly. */
  node->refCount = -1;
}

/** 
 * Adds a new edge between the two GSS node given, and labels it with the 
 * specified parse tree node. 
 * 
 * \param source the GSS node that is the source of the edge.
 * \param target the GSS node that is the target of the edge.
 * \param t the parse tree node to label the edge with.
 * \param tl the number of leaves the parse tree node has.
 * 
 * \return the newly created edge.
 */
GSSEdge GSSNode_addEdge(GSSNode source, GSSNode target, PT_Tree t, size_t tl) {
  GSSEdge edge = GSSEdge_createEdge(t, tl, target);
  
  source->edges = GSS_addEdgeListElement(edge, source->edges);
  //GSSNode_increaseRefCount(target);

  return edge;
}

/** 
 * Returns the specified GSS node's state number.
 * 
 * \param gssNode the GSS node for which the state number is requested.
 * 
 * \return the GSS node's state number.
 */
int GSSNode_getStateNumber(GSSNode gssNode) {
  return gssNode->state;
}

/** 
 * Returns the list of edges that leave the specified GSS node.
 * 
 * \param gssNode the GSS node for which the list of out edges is requested.
 * 
 * \return the GSS node's out-edge list.
 */
GSSEdgeList GSSNode_getEdgeList(GSSNode gssNode) {
  return gssNode->edges;
}

/** 
 * Increases the given GSS node's reference count.
 * 
 * \param gssNode the GSS node for which the reference count is to be increased.
 */
void GSSNode_increaseRefCount(GSSNode gssNode) {
  gssNode->refCount++;
}

/** 
 * Decreases the given GSS node's reference count.
 * 
 * \param gssNode the GSS node for which the reference count is to be decreased.
 */
void GSSNode_decreaseRefCount(GSSNode gssNode) {
  gssNode->refCount--;
}

/** 
 * Returns the reference count for the given GSS node. 
 * 
 * \param gssNode the GSS node for which the reference count is requested.
 * 
 * \return the GSS node's reference count.
 */
short GSSNode_getRefCount(GSSNode gssNode) {
  return gssNode->refCount;
}

/** 
 * Determines if the speciefies node was created as a result of a shift action.
 * 
 * \param gssNode the GSS node to be tested.
 * 
 * \return \c true if the was created as a result of a shift action; \c false 
 * otherwise.
 */
ATbool GSSNode_isShift(GSSNode gssNode) {
  return gssNode->isShift;
}

/** 
 * Determines if the specified node is rejected or not. A node is only 
 * considered to be rejected if all of its edges are rejected.
 * 
 * \param st the node to be tested.
 * 
 * \return \c true if the node is rejected; \c false otherwise.
 */
ATbool GSSNode_isRejected(GSSNode st) {
  GSSEdgeList edges = GSSNode_getEdgeList(st);

  if (edges == NULL) {
    return ATfalse;
  }

  for (; edges; edges = GSS_getEdgeListTail(edges)) {
    if (!GSSEdge_isRejected(GSS_getEdgeListHead(edges))) {
      /*  An edge is not rejected  */
      return ATfalse;
    }
  }
  /*  All edges are rejected  */
  return ATtrue;
}
