#include "ksdf2table.h"
#include "characters.h"
#include "goto.h"
#include "follow.h"

extern ATermTable symbol_lookaheads_table;
extern ATermTable nr_spec_attr_pairs;

/*{{{  ATermList restrict(CC_Class charClass, ATermList restrictions,
                         ATermInt len, ATermInt prodnr, ATerm prod,
                         ATermList actionset) */

static ATermList restrict(CC_Class charClass1, ATermList restrictions,
			  ATermInt len, ATermInt prodnr,
			  ATermList actionset)
{
  ATerm reduce, restriction, cc, las;
  ATermList reducelist;
  ATermInt special_attr;
  CC_Class charClass2, newCharClass;
  int c;

  if (ATisEmpty(restrictions)) {
    special_attr = (ATermInt)ATtableGet(nr_spec_attr_pairs, (ATerm)prodnr);
    reduce = ATmake("reduce(<term>,<term>,<term>)", len, prodnr, special_attr);
    reducelist = ATmakeList1(reduce);
    for (c=0; c<CC_BITS; c++) {
      if (CC_containsChar(charClass1, c)) {
	actionset = action_insert(actionset, (ATerm)ATmakeInt(c), reducelist);
      }
    }
  }
  else {
    restriction = ATgetFirst(restrictions);
    restrictions = ATgetNext(restrictions);
    if(IS_CHARCLASS(restriction)) {
      charClass2 = CC_ClassFromTerm(restriction);
      newCharClass = CC_alloc();
      CC_copy(newCharClass, charClass1);
      CC_difference(newCharClass, charClass2);
      CC_free(charClass2);
      actionset = restrict(newCharClass, restrictions, len, prodnr, actionset);
      CC_free(newCharClass);
    }
    else if(ATmatch(restriction, "look(<term>,<term>)", &cc, &las)) {
      if (IS_CHARCLASS(cc)) {
        charClass2 = CC_ClassFromTerm(cc);
        special_attr = (ATermInt)ATtableGet(nr_spec_attr_pairs, (ATerm)prodnr);
        reduce = ATmake("reduce(<term>,<term>,<term>,<term>)",
                        len, prodnr, special_attr, las);
        reducelist = ATmakeList1(reduce);

	newCharClass = CC_alloc();
	CC_copy(newCharClass, charClass1);
        CC_intersection(newCharClass, charClass2);

	for (c=0; c<CC_BITS; c++) {
	  if (CC_containsChar(newCharClass, c)) {
	    actionset = action_insert(actionset, (ATerm)ATmakeInt(c), reducelist);
	  }
	}

	CC_copy(newCharClass, charClass1);
        CC_difference(newCharClass, charClass2);
	CC_free(charClass2);

        actionset = restrict(newCharClass, restrictions, len, prodnr, actionset);

	CC_free(newCharClass);
      }
    }
  }
  return actionset;
}

/*}}}  */
/*{{{  ATermList reductions(ATermList vertex, ATermList actionset) */

ATermList reductions(ATermList vertex, ATermList actionset)
{
  int len, iptr;
  ATerm item, prod, symbol;
  ATermInt prodnr, ptr;
  ATermList symbols, las;
  CC_Class charClass;

  while(!ATisEmpty(vertex)) {
    item = ATgetFirst(vertex);
    vertex = ATgetNext(vertex);

    if(IS_ITEM(item)) {
      prod = GET_ARG(item, 0);
      prodnr = GET_INT_ARG(item, 1);
      ptr = GET_INT_ARG(item, 2);
      if(IS_PROD(prod)) {
        symbols = GET_LIST_ARG(prod, 0);
        symbol = GET_ARG(prod, 1);
        len = ATgetLength(symbols);
        iptr = ATgetInt(ptr);
        if(iptr == len) {
          las = (ATermList)ATtableGet(symbol_lookaheads_table,symbol);
          if(!las) {
            las = ATempty;
          }

          charClass = follow_table[ATgetInt(prodnr)];
          if (charClass) {
            actionset = restrict(charClass, las, ATmakeInt(len), prodnr, actionset);
          }
        }
      }
    }
  }
  return actionset;
}

/*}}}  */
