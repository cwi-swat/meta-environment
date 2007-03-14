/*$Id$*/

/** \file 
 * \ingroup gss
 *
 * This file implements functions for lists of GSS edges. GSS edge lists are 
 * used by GSS nodes to store their out-edges. \see GSSNode
 */

#include "gssEdgeList.h"

/** 
 * Returns the first element of the given GSS edge list.
 * 
 * \param list the list for which the first element is requested.
 * 
 * \return the first element of the list.
 */
/*GSSEdge GSS_getEdgeListHead(GSSEdgeList list) {
  return (GSSEdge)SGLR_UTIL_getHead(list);
}*/

/** 
 * Returns the list of GSS edges after the first element.
 * 
 * \param list the list for which the tail is requested.
 * 
 * \return the tail of the list.
 */
/*GSSEdgeList GSS_getEdgeListTail(GSSEdgeList list) {
  return (GSSEdgeList)SGLR_UTIL_getTail(list);
}*/

/** 
 * Adds the given edge to the front of the specified list of edges.
 * 
 * \param element the edge to add to the list of edges.
 * \param list the edge list to add the new edge to.
 * 
 * \return the edge list with the new edge added to the front.
 */
GSSEdgeList GSS_addEdgeListElement(GSSEdge element, GSSEdgeList list) {
  return (GSSEdgeList)SGLR_UTIL_addElement(element, list);
}

/** 
 * Deletes the entire edge list specified.
 * 
 * \param list the list to delete.
 */
void GSS_deleteEdgeList(GSSEdgeList list) {
  SGLR_UTIL_deleteList(list);
}

/** 
 * Searches for the given edge in the specified edge list. A linear search is 
 * used.
 * 
 * \param element the edge to search for.
 * \param list the edge list to search.
 * 
 * \return the GSS edge if it exists in the list; \c NULL otherwise. 
 */
GSSEdge GSS_findElementInEdgeList(GSSEdge element, GSSEdgeList list) {
  return (GSSEdge)SGLR_UTIL_linearSearch(element, list);
}

/** 
 * Reverses the order of the edges in the list.
 * 
 * \param list the edge list to reverse.
 * 
 * \return the reversed edge list.
 */
GSSEdgeList GSS_reverseEdgeList(GSSEdgeList list) {
  return (GSSEdgeList)SGLR_UTIL_reverseList(list);
}
