
/*{{{  includes */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include <aterm2.h>

#include "item.h"
#include "ksdf2table.h"


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
  return (Item)ATmakeAppl2(it_afun_item, (ATerm)ATmakeInt(prodnr),
			   (ATerm)ATmakeInt(0));
}

/*}}}  */
/*{{{  Item IT_createItemDot(int prodnr, int dot) */

Item IT_createItemDot(int prodnr, int dot)
{
  return (Item)ATmakeAppl2(it_afun_item, (ATerm)ATmakeInt(prodnr),
			   (ATerm)ATmakeInt(dot));
}

/*}}}  */
/*{{{  Item IT_shiftDot(Item item) */

Item IT_shiftDot(Item item)
{
  ATerm prod = IT_getProd(item);
  ATermList symbols = (ATermList)ATgetArgument((ATermAppl)prod, 0);
  int dot = IT_getDotPosition(item);
  if (dot < ATgetLength(symbols)) {
    return (Item)ATmakeAppl2(it_afun_item, ATgetArgument((ATermAppl)item, 0),
			     (ATerm)ATmakeInt(dot+1));
  } else {
    return NULL;
  }
}

/*}}}  */
/*{{{  int  IT_getProdNr(Item item) */

int  IT_getProdNr(Item item)
{
  return ATgetInt((ATermInt)ATgetArgument((ATermAppl)item, 0));
}

/*}}}  */
/*{{{  ATerm IT_getProd(Item item) */

ATerm IT_getProd(Item item)
{
  return nr_prod_table[IT_getProdNr(item)];
}

/*}}}  */
/*{{{  ATerm IT_getDotSymbol(Item item) */

ATerm IT_getDotSymbol(Item item)
{
  ATermList symbols;
  ATerm prod;
  int dot = IT_getDotPosition(item);

  prod = IT_getProd(item);
  symbols = (ATermList)ATgetArgument(prod, 0);

  if (dot < ATgetLength(symbols)) {
    return ATelementAt(symbols, dot);
  } else {
    return empty_set;
  }
}

/*}}}  */
/*{{{  int IT_getDotPosition(Item item) */

int IT_getDotPosition(Item item)
{
  return ATgetInt((ATermInt)ATgetArgument((ATermAppl)item, 1));
}

/*}}}  */

/*{{{  ATerm IT_ItemToTerm(Item item) */

ATerm IT_ItemToTerm(Item item)
{
  return (ATerm)item;
}

/*}}}  */
/*{{{  Item  IT_ItemFromTerm(ATerm term) */

Item  IT_ItemFromTerm(ATerm term)
{
  return (Item)term;
}

/*}}}  */
/*{{{  ATbool IT_isValidItem(Item item) */

ATbool IT_isValidItem(Item item)
{
  return ATgetType((ATerm)item) == AT_APPL
    && ATgetAFun((ATermAppl)item) == it_afun_item;
}

/*}}}  */
