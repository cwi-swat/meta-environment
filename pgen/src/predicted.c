#include "ksdf2table.h"
#include "characters.h"
#include "item.h"
#include "goto.h"
#include "priorities.h"

#include <aterm2.h>

/*{{{  static ATermList pred(Item item, ATermList items) */

static ATermList pred(Item item, ATermList items)
{
  ATerm prodnr;
  ATerm dotsymbol;
  ATermList prods;

  if (IT_isValidItem(item)) {
    dotsymbol = IT_getDotSymbol(item);
    if (!ATisEqual(dotsymbol, empty_set)) {
      prods = (ATermList)ATtableGet(rhs_prods_pairs, dotsymbol);
      if (prods) {
	while (!ATisEmpty(prods)) {
	  /*ATwarning("prods = %t\n", prods);*/
	  prodnr = ATgetFirst(prods);
	  prods = ATgetNext(prods);
	  if (!conflicts(item, prodnr)) {
	    Item newitem = IT_createItem(ATgetInt((ATermInt)prodnr));
	    items = ATinsert(items, IT_ItemToTerm(newitem));
	  }
	}
      }
    }
  }

  return items;
}

/*}}}  */
/*{{{  static ATermList closure_pred(ATermList processed, ATermList items) */

static ATermList closure_pred(ATermList processed, ATermList items)
{
  int idx;
  ATerm it;

  while (!ATisEmpty(items)) {
    it = ATgetFirst(items);
    items = ATgetNext(items);
    idx = ATindexOf(processed, it, 0);
    if (idx < 0) {
      Item item = IT_ItemFromTerm(it);
      items = pred(item, items);
      processed = insert_item(processed, item);
    }
  }
  return processed;
}

/*}}}  */
/*{{{  ATermList closure() */

ATermList closure(ATermList items)
{
  return closure_pred(ATempty,items);
}

/*}}}  */
/*{{{  void outgoing(ATermList itemset, ATermList *predprods, CC_Set *predchars) */

void outgoing(ATermList itemset, ATermList *predprods, CC_Set *predchars)
{
  Item item;
  ATerm symbol;

  /*ATwarning("itemset = %t\n", itemset);*/
  *predprods = ATempty;
  while (!ATisEmpty(itemset)) {
    item = IT_ItemFromTerm(ATgetFirst(itemset));
    itemset = ATgetNext(itemset);
 
    if (IT_getDotPosition(item) == 0) {
      *predprods = ATaddElement(*predprods,(ATerm)ATmakeInt(IT_getProdNr(item)));
    }

    symbol = IT_getDotSymbol(item);
    /*ATwarning("item = %t, symbol = %t (%d)\n", item, symbol, IS_CHARCLASS(symbol));*/
    if (IS_CHARCLASS(symbol)) {
      CC_addATermClass(CC_addToSet(predchars), symbol);
    }
  }
}

/*}}}  */
