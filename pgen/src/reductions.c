/*

    PGEN - the SDF2 parse table generator.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
#include "ksdf2table.h"

extern ATermList *follow_table;
extern ATermTable symbol_lookaheads_table;
extern ATermTable nr_spec_attr_pairs;

extern ATermList action_insert(ATermList actions, ATerm cc2, ATermList elems2);

 
/*{{{  ATermList restrict(ATermList charrange, ATermList restrictions,
                         ATermInt len, ATermInt prodnr, ATerm prod,
                         ATermList actionset) */

ATermList charrange_difference(ATermList crl1,ATermList crl2);
ATermList charrange_intersection(ATermList crl1,ATermList crl2);

ATermList restrict(ATermList charrange1, ATermList restrictions,
                   ATermInt len, ATermInt prodnr,
                   ATermList actionset)
{
  ATerm reduce, charclass, restriction, cc, las;
  ATermList reducelist, charrange2, newcharrange, newactionset;
  ATermInt special_attr;

/*
ATwarning("las are %t\n", restrictions);
ATwarning("charrange for %t is %t\n", prodnr, charrange1);
*/

  if(ATisEmpty(restrictions)) {
    special_attr = (ATermInt)ATtableGet(nr_spec_attr_pairs,(ATerm)prodnr);
    reduce = ATmake("reduce(<term>,<term>,<term>)",len,prodnr,special_attr);
    reducelist = ATmakeList1(reduce);
    charclass = (ATerm)ATmakeAppl1(afun_char_class, (ATerm)charrange1);
/*
ATwarning("action_insert(%t,%t,%t)\n", actionset, charclass, reducelist);
*/
    actionset = action_insert(actionset, charclass, reducelist);
    return actionset;
  }
  else {
    restriction = ATgetFirst(restrictions);
    restrictions = ATgetNext(restrictions);
    if(IS_CHARCLASS(restriction)) {
      charrange2 = GET_LIST_ARG(restriction,0);
      newcharrange = charrange_difference(charrange1, charrange2);
      return restrict(newcharrange,restrictions,len,prodnr,actionset);
    }
    else if(ATmatch(restriction, "look(<term>,<term>)", &cc, &las)) {
      if (IS_CHARCLASS(cc)) {
        charrange2 = GET_LIST_ARG(cc,0);   
        special_attr = (ATermInt)ATtableGet(nr_spec_attr_pairs,(ATerm)prodnr);
        reduce = ATmake("reduce(<term>,<term>,<term>,<term>)",
                        len,prodnr,special_attr,las);
        reducelist = ATmakeList1(reduce);
        newcharrange = charrange_intersection(charrange1, charrange2);
        charclass = (ATerm)ATmakeAppl1(afun_char_class, (ATerm)newcharrange);
/*
ATwarning("action_insert(%t,%t,%t)\n", actionset, charclass, reducelist);
*/

        newactionset = action_insert(actionset, charclass, reducelist);
        newcharrange = charrange_difference(charrange1, charrange2);
        return restrict(newcharrange,restrictions,len,prodnr,newactionset);
      }
      else
        return actionset;
    }
    else
      return actionset;
  }
}

/*}}}  */
/*{{{  ATermList reductions(ATermList vertex, ATermList actionset) */

ATermList reductions(ATermList vertex, ATermList actionset)
{
  int len, iptr;
  ATerm item, prod, symbol;
  ATermInt prodnr, ptr;
  ATermList symbols, charrange, las;

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
          if(!las)
            las = ATempty;
          charrange = follow_table[ATgetInt(prodnr)];
          if(charrange) {
/*
ATwarning("charrange for %t is %t\n", prodnr, charrange);
*/
            actionset = restrict(charrange,las,ATmakeInt(len),
                                 prodnr,actionset);
          }
        }
      }
    }
  }
  return actionset;
}

/*}}}  */
