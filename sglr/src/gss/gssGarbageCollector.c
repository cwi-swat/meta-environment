/* $Id$ */

/** \file
 * \ingroup gss
 *
 * This file implements the garbage collector used by the \ref parser to 
 * deallocate GSS nodes and edges.
 *
 * When a GLR-style parser that uses a GSS performs a shift from a level 
 * \f$ i\f$, a new set of GSS nodes is created in level \f$ i+1\f$. The nodes 
 * in level \f$j \leq i\f$ that do not have a path from a node in level 
 * \f$ i+1\f$ can be removed from the GSS. This is achieved by using the 
 * standard <em> mark and sweep</em> garbage collection algorithm.
 *
 * The following two papers discuss a reference counting approach to garbage 
 * collection which may be interesting to imlepement and compare to the 
 * current approach. 
 *
 * \code
 * @inproceedings{bacon01,
 * author =    {Bacon, David F. and Rajan, V. T.},
 * title =     {Concurrent Cycle Collection in Reference Counted Systems},
 * booktitle = {ECOOP '01: Proceedings of the 15th European Conference on Object-Oriented Programming},
 * year =      {2001},
 * isbn =      {3-540-42206-4},
 * pages =     {207--235},
 * publisher = {Springer-Verlag},
 * address =   {London, UK},
 * }
 *
 * @inproceedings{levanoni01,
 * author =    {Levanoni, Yossi and Petrank, Erez},
 * title =     {An on-the-fly reference counting garbage collector for Java},
 * booktitle = {OOPSLA '01: Proceedings of the 16th ACM SIGPLAN conference on Object oriented programming, systems, languages, and applications},
 * year =      {2001},
 * isbn =      {1-58113-335-9},
 * pages =     {367--380},
 * location =  {Tampa Bay, FL, USA},
 * doi =       {http://doi.acm.org/10.1145/504282.504309},
 * publisher = {ACM Press},
 * address =   {New York, NY, USA},
 * }
 * \endcode
 */

#include <assert.h>

#include "gss.h"
#include "gssGarbageCollector.h"
#include "gssNodeList.h"
#include "gssEdgeList.h"

/**
 * Performs the mark phase of the GSS garbage collector. It traverses all GSS 
 * nodes from the specified node and increments counters of visited nodes.
 * 
 * \param node the GSS node to begin the traversal from.
 */
static void markGSSNode(GSSNode node) {
  if(node != NULL) {
    if (GSSNode_getRefCount(node) == 0) {
      register GSSEdgeList edgeList;
      GSSNode_increaseRefCount(node);

      for(edgeList = GSSNode_getEdgeList(node); edgeList; edgeList = GSS_getEdgeListTail(edgeList)) {
        markGSSNode(GSSEdge_getTargetGSSNode(GSS_getEdgeListHead(edgeList)));
      }
    }
  }
}

/** 
 * Performs the un-marking of GSS nodes in the GSS. It traverses all GSS nodes 
 * from the given node and decrements their reference count, until it is 0.
 * 
 * \param node the GSS node to begin the traversal from.
 */
static void unmarkGSSNode(GSSNode node) {
  if(node != NULL) {
    if (GSSNode_getRefCount(node) == 1) {
      register GSSEdgeList edgeList;

      GSSNode_decreaseRefCount(node);
      for(edgeList = GSSNode_getEdgeList(node); edgeList; edgeList = GSS_getEdgeListTail(edgeList)) {
        unmarkGSSNode(GSSEdge_getTargetGSSNode(GSS_getEdgeListHead(edgeList)));
      }
    } 
    else {
      assert(GSSNode_getRefCount(node) == 0);
    }
  }
}

/** 
 * Performs the mark phase of the GSS garbage collector for a list of GSS nodes.
 * \see markGSSNode()
 * 
 * \param list the list of GSS nodes to begin the traversal from.
 */
static void markGSSNodeList(GSSNodeList list) {
  for(; list; list = GSS_getNodeListTail(list)) {
    markGSSNode(GSS_getNodeListHead(list));
  }
}

/** 
 * Performs the un-marking of GSS nodes in the GSS for a list of GSS nodes.
 * 
 * \param list the list of GSS nodes to begin the traversal from.
 */
static void unmarkGSSNodeList(GSSNodeList list) {
  while(list != NULL) {
    unmarkGSSNode(GSS_getNodeListHead(list));
    list = GSS_getNodeListTail(list);
  }
}

/** 
 * Performs the sweep phase of the GSS garbage collector for a list of GSS 
 * nodes.
 * 
 * \param list the list of GSS nodes to begin the travesal from.
 */
static void sweepGSSNodeList(GSSNodeList list) {
  while(list != NULL) {
    GSSNodeList tmp = list;

    GC_gssBranch(GSS_getNodeListHead(list));
    list = GSS_getNodeListTail(list);

    GSS_deleteNodeList(tmp);
  }
}

/**
 * Performs the sweep phase of the GSS garbae collector. It traverses all GSS
 * nodes that have a reference count of 0 from the given node and decrements
 * each node's reference count to -1. When it reaches a node that has a 
 * reference count higher than 0, it stops the traversal and recursively 
 * returns to the nodes previously visited and deletes them. 
 * 
 * \param node the GSS node to begin the traversal from.
 */
void GC_gssBranch(GSSNode node) {
  if(node != NULL) {
    if(GSSNode_getRefCount(node) == 0) {
      register GSSEdgeList edgeList, tmpEdgeList;

      /* It is assumed that collected nodes have their refcount set to -1, and 
       * that nobody reuses collected nodes until the collector has finished.
       */
      GSSNode_decreaseRefCount(node);
      for(edgeList = GSSNode_getEdgeList(node); edgeList;) {
        GSSEdge edge = GSS_getEdgeListHead(edgeList);
        GC_gssBranch(GSSEdge_getTargetGSSNode(edge));

        tmpEdgeList = edgeList;
        edgeList = GSS_getEdgeListTail(edgeList);        
        GSSEdge_deleteGSSEdge(edge);
        GSS_deleteEdgeList(tmpEdgeList);
      }
      GSSNode_deleteGSSNode(node); 
    }
  }
}


/** 
 * Performs the sweep phase of the GSS garbage collector from a list of GSS 
 * nodes, but excludes the specified accepting state and the list of new GSS 
 * nodes. The accepting GSS node is passed in here because we don't want to 
 * remove it.
 * 
 * \param old the GSS node list to begin the sweep from.
 * \param nr_old the number of nodes in the old list.
 * \param new the list of GSS nodes not to perform the sweep phase on.
 * \param accept the GSS node not to perform the sweep phase on.
 * 
 * \return 
 */
GSSNodeList GC_gssBranches(GSSNodeList *old, int nr_old, GSSNodeList new, GSSNode accept) {
  int i;

  /*  Count references: mark...  */
  if(accept != NULL) {
    markGSSNode(accept);
  }
  if(new != NULL) {
    markGSSNodeList(new);
  }
  
  /*  Remove unreferenced items: sweep... */
  for (i=0; i<nr_old; i++) {
    sweepGSSNodeList(old[i]);
  }

  if (accept != NULL) {
    unmarkGSSNode(accept);
  }

  if (new != NULL) {
    unmarkGSSNodeList(new);
  }

  return new;
}
