#ifndef ITEM_H
#define ITEM_H

#include "parseTable-data.h"

#define NO_ITEM -1

typedef int Item;

Item IT_createItem(int prodnr);
Item IT_createItemDot(int prodnr, int dot);
Item IT_shiftDot(Item item);

ATerm IT_ItemToTerm(Item item);
Item  IT_ItemFromTerm(ATerm term);
ATbool IT_isValidItem(Item item);

/*
int  IT_getProdNr(Item item);
ATerm IT_getProd(Item item);
ATerm IT_getDotSymbol(Item item);
int IT_getDotPosition(Item item);
*/

#define IT_getProdNr(item) ((item) % PGEN_getMaxProductionNumber())
#define IT_getProd(item)   (PGEN_getProductionOfProductionNumber(IT_getProdNr(item)))
#define IT_getDotPosition(item) ((item)/PGEN_getMaxProductionNumber())

/* Return the symbol to the right of the dot in the given production. */
#define IT_getDotSymbol(item) \
    (PGEN_getLhsSymbolAtPositionXOfProductionNumber(IT_getDotPosition(item),IT_getProdNr(item)))

#endif /* ITEM_H */

