/* $Id$ */

/* An item is encoded as an integer. The number assigned to an item is 
 * calculated by multiplying the max production number with the dot position 
 * in the item and then adding the item's production number. */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <aterm2.h>
#include <MEPT.h>

#include "item.h"


Item IT_createItem(int prodnr) {
  return IT_createItemDot(prodnr, 0);
}

Item IT_createItemDot(int prodnr, int dot) {
  return dot*PGEN_getMaxProductionNumber() + prodnr;
}

Item IT_shiftDot(Item item) {
  PT_Production prod = IT_getProd(item);
  PT_Symbols symbols = PT_getProductionLhs(prod);
  int dot = IT_getDotPosition(item);
  if (dot < PT_getSymbolsLength(symbols)) {
    return item + PGEN_getMaxProductionNumber();
  } else {
    return NO_ITEM;
  }
}

ATerm IT_ItemToTerm(Item item) {
  return (ATerm)ATmakeInt(item);
}

Item  IT_ItemFromTerm(ATerm term) {
  assert(ATgetType(term) == AT_INT);

  return ATgetInt((ATermInt)term);
}

ATbool IT_isValidItem(Item item) {
  return item >= MIN_PROD_NUM;
}

