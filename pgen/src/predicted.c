#include <assert.h>

#include <aterm2.h>

#include "ksdf2table.h"
#include "characters.h"
#include "item.h"
#include "itemset.h"
#include "goto.h"
#include "priorities.h"

/*{{{  static ATermList pred(Item item, ATermList items) */

static ATermList predict(Item item, ATermList items)
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
/*{{{  void closure(ATermList items, ItemSet processed) */

void closure(ATermList items, ItemSet processed)
{
  ATerm it;
  Item item;

  while (!ATisEmpty(items)) {
    it = ATgetFirst(items);
    item = IT_ItemFromTerm(it);
    items = ATgetNext(items);
    if (!ITS_contains(processed, item)) {
      items = predict(item, items);
      ITS_add(processed, item);
    }
  }
}

/*}}}  */
/*{{{  void outgoing(ItemSet itemset, ATermList *predprods, CC_Set *predchars) */

void outgoing(ItemSet itemset, ATermList *predprods, CC_Set *predchars)
{
  Item item;
  ATerm symbol;
  ItemSetIterator iter;

  *predprods = ATempty;

  ITS_iterator(itemset, &iter);
  while (ITS_hasNext(&iter)) {
    item = ITS_next(&iter);
 
    if (IT_getDotPosition(item) == 0) {
      ATerm prod = (ATerm)ATmakeInt(IT_getProdNr(item));
      /*assert(ATindexOf(*predprods, prod, 0) == -1);*/
      *predprods = ATinsert(*predprods, prod);
    }

    symbol = IT_getDotSymbol(item);
    /*ATwarning("item = %t, symbol = %t (%d)\n", item, symbol, IS_CHARCLASS(symbol));*/
    if (IS_CHARCLASS(symbol)) {
      CC_addATermClass(CC_addToSet(predchars), symbol);
    }
  }
}

/*}}}  */
