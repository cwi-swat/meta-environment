#ifndef ITEM_H
#define ITEM_H

#include "ksdf2table.h"

#define NO_ITEM -1

typedef int Item;

void IT_init();
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

#define IT_getProdNr(item)    ((item) % MAX_PROD)
#define IT_getProd(item)      (nr_prod_table[IT_getProdNr(item)])
#define IT_getDotPosition(item) ((item)/MAX_PROD)
#define IT_getDotSymbol(item) \
    (symbol_table[IT_getProdNr(item)][IT_getDotPosition(item)])

#endif

