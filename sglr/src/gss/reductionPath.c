/*$Id$*/

/** \file
 * \ingroup gss
 * 
 * This file implements the constructor, destructor and accessor functions of
 * a #ReductionPath. A reduction path contains the information of a single 
 * traversal of the GSS during a reduction. A list of ReductionPaths is built 
 * up when a reduction is performed by the \ref doReductions() "parser". Each 
 * reduction path points to another reduction path for the same reduction.
 */

#include "reductionPath.h"
#include "mem-alloc.h"
#include "assert.h"

/** 
 * This struct is used to store the reduction paths of a particular reduction.
 */
struct _ReductionPath {
  GSSNode targetGSSNode;  /**< the target node of this reduction. */
  PT_Args treeNodes;      /**< the list of parse tree nodes collected during 
                              this reduction's traversal of the GSS. The list 
                              of nodes is in reverse order. */
  size_t    length;         /**< the length of the reduction. */
  struct _ReductionPath *nextPath; /**< points to this reductions next 
                                     reduction path. */
};

/* Prototype design pattern. We re-use pre-allocated objects when they are 
 * available. 
 */
static ReductionPath firstFreePath = NULL;

/** \todo Should we re-use the generic memory manager in utils? */

/** 
 * Creates a new reduction path for a reduction and adds it to the given 
 * reduction path (if it exists).
 * 
 * \param targetGSSNode the target node of the reduction.
 * \param treeNodes the list of parse tree nodes of the reduction.
 * \param length the length of the new reduction.
 * \param path the existing reduction path (\c NULL if no other path exists).
 * 
 * \return the new reduction path, that is linked to any existing reduction 
 * paths that were passed in.
 */
ReductionPath GSS_addReductionPath(GSSNode targetGSSNode, PT_Args treeNodes, 
				   size_t length, ReductionPath path) {
  ReductionPath newPath = NULL;

  if (firstFreePath != NULL) {
    newPath                = firstFreePath;
    firstFreePath          = firstFreePath->nextPath;
    newPath->targetGSSNode = targetGSSNode;
    newPath->treeNodes     = treeNodes;
    newPath->length        = length;
    newPath->nextPath      = path;
  } 
  else {
    newPath = malloc(sizeof(struct _ReductionPath));

    if(newPath == NULL) {
      ATerror("%s:%d Could not allocate %d bits of memory\n", __FILE__, 
	      __LINE__, sizeof(struct _ReductionPath));
    }
    
      newPath->targetGSSNode = targetGSSNode;
      newPath->treeNodes     = treeNodes;
      newPath->length        = length;
      newPath->nextPath      = path;
      PT_protectArgs(&(newPath->treeNodes));
  }

  return newPath;
}

/** 
 * Clears the given reduction path. \warning This function is not used and 
 * probably not correct.
 * 
 * \param path the reduction path to clear.
 */
void GSS_clearReductionPath(ReductionPath path) {
  if(path != NULL) {
    path->treeNodes = NULL;
    path->nextPath  = firstFreePath;
    firstFreePath   = path;
  }
}

/** 
 * Returns the given reduction path's target node.
 * 
 * \param path the reduction path for which the target node is requested.
 * 
 * \return the GSS node that is the target node of the reduction path.
 */
GSSNode GSS_getReductionPathTargetGSSNode(ReductionPath path) {
  return path->targetGSSNode;
}

/** 
 * Returns the given reduction path's parse tree nodes. 
 * \see ReductionPath::treeNodes
 * 
 * \param path the reduction path for which the parse tree nodes are requested.
 * 
 * \return the list of parse tree nodes of the reduction path.
 */
PT_Args GSS_getReductionPathTreeNodes(ReductionPath path) {
  return path->treeNodes;
}

/** 
 * Returns the given reduction path's reduction length.
 * 
 * \param path the reduction path for which the reduction length is requested.
 * 
 * \return the length of the reduction path.
 */
size_t GSS_getReductionPathLength(ReductionPath path) {
  return path->length;
}

/** 
 * Returns the next reduction path of the given reduction path.
 * 
 * \param path the reduction path for which the next path is requested.
 * 
 * \return the next reduction path.
 */
ReductionPath GSS_getNextReductionPath(ReductionPath path) {
  return path->nextPath;
}

void GSS_printReductionPath(ReductionPath path) {
  while (path) {
    ATwarning("target: %d\n", GSSNode_getStateNumber(path->targetGSSNode));
    ATwarning("length: %d\n", path->length);
    path = path->nextPath;
  }
}
