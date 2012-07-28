/* $Id$ */

#include <assert.h>
#include <aterm2.h>
#include <ptable.h>

#include "characters.h"
#include "item.h"
#include "itemset.h"
#include "goto.h"
#include "priorities.h"
#include "parseTable-data.h"

/* For all non-terminals which are to the right of the dot in |item|, add 
 * that non-terminal's items to the set of |items| if they do not already 
 * exist. Note that only items that do not cause a priority conflict are 
 * added to the predicted items. */
static ATermList predict(Item item, ATermList items) {
  int prodnr;
  PT_Symbol dotsymbol;
  ATermList prods;

  if (IT_isValidItem(item)) {
    dotsymbol = (PT_Symbol)IT_getDotSymbol(item);
    if (!PT_isSymbolEmpty(dotsymbol)) {
      prods = PGEN_getProductionNumbersOfRhsNonTerminal(dotsymbol);
      if (prods) {
        while (!ATisEmpty(prods)) {
          /*ATwarning("prods = %t\n", prods);*/
          prodnr = ATgetInt((ATermInt)ATgetFirst(prods));
          prods = ATgetNext(prods);
          if (!PGEN_isPriorityConflict(item, prodnr)) {
            Item newitem = IT_createItem(prodnr);
            items = ATinsert(items, IT_ItemToTerm(newitem));
          }
        }
      }
    }
  }

  return items;
}

/* Perform the epsilon closure on a set of |items| to construct a DFA state. 
 * The set of |items| passed in are the kernel items of the state and the item
 * set returned includes the kernel items.  
 * The item set |processed| contains the items that have been processed during 
 * the epsilon closure.*/ 
ItemSet closure(ATermList items) {
  ATerm it;
  Item item;
  ItemSet processed = ITS_create();

  while (!ATisEmpty(items)) {
    it = ATgetFirst(items);
    item = IT_ItemFromTerm(it);
    items = ATgetNext(items);
    if (!ITS_contains(processed, item)) {
      items = predict(item, items);
      ITS_add(processed, item);
    }
  }

  return processed;
}

/* Given an itemset find the productions or symbols that will label the edges 
 * leaving the state containing the given itemset. Specifically: 
 * - For items of the form (\cdot \alpha -> X) add that item's production 
 *   number to predprods.
 * - For items of the form (\alpha \cdot A \beta -> X) add A to predchars, 
 *   where can be a terminal or a non-terminal encoded as a char-class. */
void outgoing(ItemSet itemset, ATermList *predprods, CC_Set *predchars) {
  Item item;
  PT_Symbol symbol;
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

    symbol = (PT_Symbol)IT_getDotSymbol(item);
    
    if (PT_isSymbolCharClass(symbol)) {
      CC_addPTSymbolToClass(CC_addToSet(predchars), symbol);
    }
  }
}
