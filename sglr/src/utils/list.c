/*$Id$*/

/** \file 
 * \ingroup utils
 */

#include "list.h"
#include "memoryManagerGenerator.h"
#include <assert.h>


/* This is believed to be a reasonable size for the use of this implementation
 * in a GLR implementation. 
 */
static const int ALLOCATED_SIZE = (10*64);

GENERATE_MEMORY_MANAGER(List,_List,tail,ALLOCATED_SIZE)

List  SGLR_UTIL_addElement(void *element, List list)
{
  int isNew;
  List newList = mallocList(&isNew);

  if (newList != NULL) {
    newList->head = element;
    newList->tail = list;	
  }	
  
  return newList;
}

void SGLR_UTIL_deleteList(List list)
{
  if (list != NULL) {
    freeList(list);
  }
}



void *SGLR_UTIL_linearSearch(void *element, List list)
{
  void* st0;
  
  for (; list != NULL; list = list->tail) {
    st0 = list->head;
    if (element == st0) {
      return element;
    }
  }
  return NULL;
}

/* Used in debugging.
 */
List SGLR_UTIL_reverseList(List list) {
  List tmp = NULL;

  while(list != NULL) {
    tmp = SGLR_UTIL_addElement(SGLR_UTIL_getHead(list),tmp);
    list = SGLR_UTIL_getTail(list);
  }
  
  return tmp;
}
