#include <assert.h>

#include "ksdf2table.h"
#include "characters.h"
#include "goto.h"
#include "follow.h"

extern ATermTable symbol_lookaheads_table;
extern ATermTable nr_spec_attr_pairs;

/*{{{  static void restrict(CC_Class *cc, restrictions, len, ATermInt prodnr) */

static void restrict(CC_Class *cc, ATermList restrictions,
		     ATermInt len, ATermInt prodnr)
{
  ATerm reduce, restriction, look_cc, las;
  ATermList reducelist;
  ATermInt special_attr;

  if (ATisEmpty(restrictions)) {
    special_attr = (ATermInt)ATtableGet(nr_spec_attr_pairs, (ATerm)prodnr);
    reduce = ATmake("reduce(<term>,<term>,<term>)", len, prodnr, special_attr);
    reducelist = ATmakeList1(reduce);
    action_insert(cc, reducelist);
  }
  else {
    restriction = ATgetFirst(restrictions);
    restrictions = ATgetNext(restrictions);
    if(IS_CHARCLASS(restriction)) {
      CC_Class result_cc, *restrict_cc = CC_ClassFromTerm(restriction);
      if (CC_difference(cc, restrict_cc, &result_cc)) {
	restrict(&result_cc, restrictions, len, prodnr);
      }
      CC_free(restrict_cc);
    }
    else if(ATmatch(restriction, "look(<term>,<term>)", &look_cc, &las)) {
      if (IS_CHARCLASS(look_cc)) {
        CC_Class intersection, *restrict_cc = CC_ClassFromTerm(look_cc);
        special_attr = (ATermInt)ATtableGet(nr_spec_attr_pairs, (ATerm)prodnr);
        reduce = ATmake("reduce(<term>,<term>,<term>,<term>)",
                        len, prodnr, special_attr, las);
        reducelist = ATmakeList1(reduce);

	if (CC_intersection(cc, restrict_cc, &intersection)) {
	  action_insert(&intersection, reducelist);
	}

	if (CC_difference(cc, restrict_cc, restrict_cc)) {
	  restrict(restrict_cc, restrictions, len, prodnr);
	}

	CC_free(restrict_cc);
      }
    }
  }
}

/*}}}  */
/*{{{  void reductions(ATermList vertex) */

void reductions(ATermList vertex)
{
  int len, iptr;
  ATerm item, prod, symbol;
  ATermInt prodnr, ptr;
  ATermList symbols, las;
  CC_Class *charClass;
  CC_Set set;

  CC_initSet(&set);
  while(!ATisEmpty(vertex)) {
    item = ATgetFirst(vertex);
    vertex = ATgetNext(vertex);

    assert(IS_ITEM(item));

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
          las = (ATermList)ATtableGet(symbol_lookaheads_table, symbol);
          if(!las) {
            las = ATempty;
          }

          charClass = follow_table[ATgetInt(prodnr)];
	  if (charClass) {
            restrict(charClass, las, ATmakeInt(len), prodnr);
          }
        }
      }
    }
  }
}

/*}}}  */
