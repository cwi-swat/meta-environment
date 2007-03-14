/*$Id$*/

/** \file
 * \ingroup gss
 *
 * This file implements functions for lists of GSS nodes. GSS node lists are
 * used by the parser to store the list of nodes in a level of a GSS. 
 * \see parser.c
 */

#include "gssNodeList.h"

/** 
 * Returns the first element of the given GSS node list.
 * 
 * \param list the list for which the first element is requested.
 * 
 * \return the first element of the list.
 */
/*GSSNode GSS_getNodeListHead(GSSNodeList list) {
  return (GSSNode)SGLR_UTIL_getHead(list);
}*/

/** 
 * Returns the list of GSS nodes after the first element of the given list.
 * 
 * \param list the list for which the tail is requested.
 * 
 * \return the tail of the list.
 */
/*GSSNodeList GSS_getNodeListTail(GSSNodeList list) {
  return (GSSNodeList)SGLR_UTIL_getTail(list);
}*/

/** 
 * Adds the given node to the front of the specified list.
 * 
 * \param element the GSS node to add to the list.
 * \param list the list to add the node to.
 * 
 * \return the list with the new node added to the front.
 */
GSSNodeList GSS_addNodeListElement(GSSNode element, GSSNodeList list) {
  return (GSSNodeList)SGLR_UTIL_addElement(element, list);
}

/** 
 * Deletes the entire list specified.
 * 
 * \param list the list to delete.
 */
void GSS_deleteNodeList(GSSNodeList list) {
  SGLR_UTIL_deleteList(list);
}

/** 
 * Searches for the given node in the specified node list. A linear search is
 * used.
 * 
 * \param element the node to search for.
 * \param list the list to search through.
 * 
 * \return the GSS node if it exists in the list; \c NULL otherwise.
 */
GSSNode GSS_findElementInNodeList(GSSNode element, GSSNodeList list) {
  return (GSSNode)SGLR_UTIL_linearSearch(element, list);
}

/** 
 * Searches for a node labelled by the given state number in the specified list.
 * A linear search is used.
 * 
 * \param stateNum the state number to search for.
 * \param list the list to search through.
 * 
 * \return the GSS node labelled by the given state number, if it exists in the list; \c NULL otherwise.
 */
GSSNode GSS_findStateInNodeList(int stateNum, GSSNodeList list) {
  for (; list; list = GSS_getNodeListTail(list)) {
    if (GSSNode_getStateNumber(GSS_getNodeListHead(list)) == stateNum){
      return GSS_getNodeListHead(list);
    }
  }
  return NULL;
}

/** 
 * Reverses the order of the nodes in the list.
 * 
 * \param list the list to reverse.
 * 
 * \return the reversed list.
 */
GSSNodeList GSS_reverseNodeList(GSSNodeList list) {
  return (GSSNodeList)SGLR_UTIL_reverseList(list);
}
