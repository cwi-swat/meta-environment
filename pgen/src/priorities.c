/* $Id$ */ 

#include "priorities.h"
#include <aterm2.h>
#include <ptable.h>

/* Check if the prodNumber has a priority conflict with the production of the 
 * item. */
ATbool PGEN_isPriorityConflict(Item item, int prodNumber) {
  int itemProdNumber = IT_getProdNr(item);
  int iptr = IT_getDotPosition(item);
  PTBL_Priority priorel = PTBL_makePriorityGreater(itemProdNumber, prodNumber);
  ATbool result;

  if (PGEN_getPriorityIndex(priorel) >= 0) {
    result = ATtrue;
  }
  else {
    priorel = PTBL_makePriorityArgGreater(itemProdNumber, iptr, prodNumber);
    if (PGEN_getPriorityIndex(priorel) >= 0) {
      result = ATtrue;
    }
    else {
      result = ATfalse;
    }
  }

  return result;
}

