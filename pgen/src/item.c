
/*{{{  includes */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include <aterm2.h>

#include "item.h"

/*}}}  */

static AFun it_afun_item;

/*{{{  void IT_init() */

void IT_init()
{
  it_afun_item = ATmakeAFun("it-item", 2, ATfalse);
  ATprotectAFun(it_afun_item);
}

/*}}}  */

/*{{{  Item IT_createItem(int prodnr) */

Item IT_createItem(int prodnr)
{
  return IT_createItemDot(prodnr, 0);
}

/*}}}  */
/*{{{  Item IT_createItemDot(int prodnr, int dot) */

Item IT_createItemDot(int prodnr, int dot)
{
  return dot*MAX_PROD + prodnr;
}

/*}}}  */
/*{{{  Item IT_shiftDot(Item item) */

Item IT_shiftDot(Item item)
{
  ATerm prod = IT_getProd(item);
  ATermList symbols = (ATermList)ATgetArgument((ATermAppl)prod, 0);
  int dot = IT_getDotPosition(item);
  if (dot < ATgetLength(symbols)) {
    return item + MAX_PROD;
  } else {
    return NO_ITEM;
  }
}

/*}}}  */

/*{{{  ATerm IT_ItemToTerm(Item item) */

ATerm IT_ItemToTerm(Item item)
{
  return (ATerm)ATmakeInt(item);
}

/*}}}  */
/*{{{  Item  IT_ItemFromTerm(ATerm term) */

Item  IT_ItemFromTerm(ATerm term)
{
  assert(ATgetType(term) == AT_INT);

  return ATgetInt((ATermInt)term);
}

/*}}}  */
/*{{{  ATbool IT_isValidItem(Item item) */

ATbool IT_isValidItem(Item item)
{
  return item >= MIN_PROD;
/*
  if (item == NO_ITEM || (item >= 0 && item < MAX_PROD*(max_nr_lhs_members+1))) {
    return ATtrue;
  }
  else {
    ATwarning("illegal item: %d (%d,%d)\n", item, MAX_PROD, max_nr_lhs_members);
    return ATfalse;
  }
  */
}

/*}}}  */
