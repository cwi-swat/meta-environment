#ifndef ITEM_H
#define ITEM_H

typedef struct _Item *Item;

void IT_init();
Item IT_createItem(int prodnr);
Item IT_createItemDot(int prodnr, int dot);
Item IT_shiftDot(Item item);
int  IT_getProdNr(Item item);
ATerm IT_getProd(Item item);
ATerm IT_getDotSymbol(Item item);
int IT_getDotPosition(Item item);

ATerm IT_ItemToTerm(Item item);
Item  IT_ItemFromTerm(ATerm term);
ATbool IT_isValidItem(Item item);

#endif

