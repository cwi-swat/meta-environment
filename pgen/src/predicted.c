#include "ksdf2table.h"
#include "characters.h"

extern ATermTable rhs_prods_pairs;
extern ATerm *nr_prod_table;

extern ATermList ATaddElement(ATermList l, ATerm elem);
extern ATbool pgen_cnf(ATermInt prodnr1, int iptr, int len, ATermInt prodnr2);
extern ATermList insert_item(ATermList items, ATerm item1);

/*{{{  ATermList pred(ATerm item, ATermList items) */

static ATermList pred(ATerm item, ATermList items)
{
  int iptr, len;
  ATermInt prodnr1, prodnr2, ptr;
  ATerm prod1, prod2, symbol1, symbol2, symbol3, newitem;
  ATermList symbols, symbols2, prods;

  if (IS_ITEM(item)) {
    prod1   = GET_ARG(item, 0);
    prodnr1 = GET_INT_ARG(item, 1);
    ptr     = GET_INT_ARG(item, 2);

    if (IS_PROD(prod1)) {
      symbols = (ATermList)GET_ARG(prod1, 0);
      symbol1  = GET_ARG(prod1, 1);

      len = ATgetLength(symbols);
      iptr = ATgetInt(ptr);
      if (len > 0 && iptr < len) {
        symbol2 = GET_ARG(item, 3);
        prods = (ATermList)ATtableGet(rhs_prods_pairs,symbol2);
        if (prods) {
          while (!ATisEmpty(prods)) {
	    /*ATwarning("prods = %t\n", prods);*/
            prodnr2 = (ATermInt)ATgetFirst(prods);
            prods = ATgetNext(prods);
            if (!pgen_cnf(prodnr1,iptr,len,prodnr2)) {
              prod2 = nr_prod_table[ATgetInt(prodnr2)];
              symbols2 = (ATermList)GET_ARG(prod2, 0);
              symbol3 = (ATerm)ATelementAt(symbols2,0);
              if (!symbol3)
                symbol3 = empty_set;
              newitem = (ATerm)ATmakeAppl4(afun_item,
                                           (ATerm)prod2,
                                           (ATerm)prodnr2,
                                           (ATerm)ATmakeInt(0),
                                           symbol3);
              items = ATinsert(items,newitem); /* was ATaddElement */
            }
          }
        }
      }
    }
  }
  return items;
}

/*}}}  */
/*{{{  ATermList closure_pred(ATermList processed, ATermList items) */

static ATermList closure_pred(ATermList processed, ATermList items)
{
  int idx;
  ATerm item;

  while (!ATisEmpty(items)) {
    item = ATgetFirst(items);
    items = ATgetNext(items);
    idx = ATindexOf(processed, item, 0);
    if (idx < 0) {
      items = pred(item,items);
      processed = insert_item(processed,item);
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
/*{{{  void outgoing(ATermList itemset, ATermList *predprods, CC_Class predchars) */

void outgoing(ATermList itemset, ATermList *predprods, CC_Class predchars)
{
  int iptr, len;
  ATermList symbols;
  ATerm item, prod, symbol1, symbol2;
  ATermInt prodnr, ptr;

  *predprods = ATempty;
  while (!ATisEmpty(itemset)) {
    item = ATgetFirst(itemset);
    itemset = ATgetNext(itemset);
 
    if (IS_ITEM(item)) {
      /*ATwarning("item = %t\n", item);*/
      prod    = GET_ARG(item, 0);
      prodnr  = GET_INT_ARG(item, 1);
      ptr     = GET_INT_ARG(item, 2);

      iptr = ATgetInt(ptr);
      if (iptr == 0) {
        *predprods = ATaddElement(*predprods,(ATerm)prodnr);
      }
      if (IS_PROD(prod)) {
	/*ATwarning("prod = %t\n", prod);*/
	symbols = GET_LIST_ARG(prod, 0);
	symbol1 = GET_ARG(prod, 1);

        len = ATgetLength(symbols);
        iptr = ATgetInt(ptr);
        if (len > 0 && iptr < len) {
	  /*ATwarning("len=%d, iptr=%d\n", len, iptr);*/
          symbol2 = GET_ARG(item, 3);
          if (IS_CHARCLASS(symbol2)) {
	    /*ATwarning("char-class: %t\n", symbol2);*/
	    CC_addATermClass(predchars, symbol2);
          }
        }
      }
    }
  }
}

/*}}}  */
