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
#include <assert.h>

extern ATerm empty_set;
extern int MAX_PROD;

extern ATermTable first_table;
extern ATerm *nr_prod_table;

/*{{{ ATbool contains_epsilon(ATermList set) */

ATbool contains_epsilon(ATermList set) 
{
  if(ATindexOf(set,empty_set,0) >= 0)
    return ATtrue;
  else
    return ATfalse;
}

/*}}} */
/*{{{ ATermList remove_epsilon(ATermList set) */

ATermList remove_epsilon(ATermList set) 
{
  return ATremoveElement(set,empty_set);
}

/*{{{ ATermList first(ATermList symbols, ATermList firstset) */

ATermList first(ATermList symbols, ATermList firstset)
{
  ATermList set, newset = ATempty;
  ATerm symbol;

  if(ATisEmpty(symbols)) {
    return firstset;
  }
  else {
    while(!ATisEmpty(symbols)) {
      symbol = ATgetFirst(symbols);
      symbols = ATgetNext(symbols);

      set = (ATermList)ATtableGet(first_table,symbol);
/*
if(ATisEqual(symbol,ATparse("cf(sort(\"StringLiteralList\"))"))) 
  ATwarning("Set is %t\n", set);
*/
      if(contains_epsilon(set))
        newset = ATunion(newset,remove_epsilon(set));
      else
        return ATunion(newset,set);
    }
    return ATunion(newset,firstset);
  }
}

/*}}} */
/*{{{ void calc_first_table() */

/**
  * Calculation of the first set of the grammar
  **/

void calc_first_table()
{
  int ip;
  ATermList symbols, firstset, tmpset;
  ATerm symbol;
  ATerm prod;
  ATbool changed = ATtrue;

  while(changed) {
    changed = ATfalse;
    for(ip=MIN_PROD;ip<MAX_PROD;ip++) {
      prod = nr_prod_table[ip];

      if(IS_PROD(prod)) {
        symbols = GET_LIST_ARG(prod,0);
        symbol  = GET_ARG(prod,1);
        tmpset = (ATermList)ATtableGet(first_table,symbol);
/*
if(ATisEqual(symbol,ATparse("cf(iter(sort(\"STRINGliteral\")))")) ||
   ATisEqual(symbol,ATparse("cf(sort(\"StringliteralList\"))"))) {
  ATwarning("Prod is %t\n", prod);
  ATwarning("Set is %t\n", tmpset);
}
*/
        if(tmpset) {
          firstset = first(symbols,ATmakeList1(empty_set));
          firstset = ATunion(tmpset,firstset);
/*
if(ATisEqual(symbol,ATparse("cf(iter(sort(\"STRINGliteral\")))")) ||
   ATisEqual(symbol,ATparse("cf(sort(\"StringliteralList\"))"))) {
  ATwarning("New set is %t\n", firstset);
}
*/
          if (!ATsetEqual(tmpset,firstset)) {
            ATtablePut(first_table,symbol,(ATerm)firstset);
            changed = ATtrue;
          }
        }
        else {
          firstset = first(symbols,ATmakeList1(empty_set));
          ATtablePut(first_table,symbol,(ATerm)firstset);
          changed = ATtrue;
        }
      }
    }
  }

/*
  for(ip=MIN_PROD;ip<MAX_PROD;ip++) {
    prod = nr_prod_table[ip];
    if(IS_PROD(prod)) {
      symbol  = GET_ARG(prod,1);
      firstset = (ATermList)ATtableGet(first_table,symbol);
      ATwarning("First set for %t is %t\n", symbol, firstset);
    }
  }
*/

}

/*}}} */
/*{{{ void init_first(ATerm prod) */

/**
 * Initialize the symbol table in order to be
 * able to perform the first calculation.
 **/

void init_first(ATerm prod)
{
  ATermList symbols;
  ATerm symbol, entry;

  if(IS_PROD(prod)) {
    symbols = GET_LIST_ARG(prod, 0);
    while(!ATisEmpty(symbols)) {
      symbol = ATgetFirst(symbols);
      symbols = ATgetNext(symbols);

      entry = ATtableGet(first_table,symbol);
      if(!entry) {
/*
ATwarning("Entry created for %t\n", symbol);
*/
         entry = (ATerm)ATmakeList1(symbol);
        ATtablePut(first_table,symbol,entry);
      }
    }
  }
}
/*}}} */
