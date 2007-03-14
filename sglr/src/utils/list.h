/*$Id$*/

/** \file
 * \ingroup utils
 */

#ifndef _LIST_H_
#define _LIST_H_

typedef struct _List {
  struct _List *tail;
  void         *head;
} *List;

List  SGLR_UTIL_addElement(void *element, List list);
void  SGLR_UTIL_deleteList(List list);
#define SGLR_UTIL_getHead(list) (list->head)
#define  SGLR_UTIL_getTail(list) (list->tail)
void *SGLR_UTIL_linearSearch(void *element, List list);
List  SGLR_UTIL_reverseList(List list);

#endif //_LIST_H_
