/*

    PGEN - the SDF2 parse table generator.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
                        The Netherlands. 

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

ATermList *local_follow_table = NULL;
ATermList *follow_table2 = NULL;

ATermList *follow_table = NULL;
ATermList *dependencies = NULL;
ATermList *depend_closure = NULL;
ATermList *initial_follow_sets = NULL;

extern ATermTable first_table;
extern ATerm *nr_prod_table;
extern ATermTable priority_table;
extern ATermTable rhs_prods_pairs;

extern ATbool contains_epsilon(ATermList set);
extern ATermList remove_epsilon(ATermList set);
extern ATermList charrange_union(ATermList l1,ATermList l2);
extern ATbool pgen_cnf(ATermInt prodnr1, int iptr, int len, ATermInt prodnr2);

ATbool changed;

/*{{{  ATermList charclass_filtering(ATermList followset) */

/* This calculation should be performed once and not each time */
ATermList charclass_filtering(ATermList followset)
{
  ATerm felem;
  ATermList charrange, charrangelist = ATempty;

  while(!ATisEmpty(followset)) {
    felem = ATgetFirst(followset);
    followset = ATgetNext(followset);
   
    if(IS_CHARCLASS(felem)) {
      charrange = GET_LIST_ARG(felem, 0);
/*
      charrangelist = charrange_union(charrangelist, charrange);
*/
      charrangelist = charrange_union(charrange, charrangelist);
    }
  }
  return charrangelist;
}

/*}}}  */

/*{{{  void sons1(ATerm prod, ATerm item, ATermList labelset) */

ATermList followset_filtering(ATermList followset)
{
  ATerm felem;
  ATermList newfollowset = ATempty;

  while(!ATisEmpty(followset)) {
    felem = ATgetFirst(followset);
    followset = ATgetNext(followset);
   
    if(IS_CHARCLASS(felem))
      newfollowset = ATinsert(newfollowset, felem);
  }
  return newfollowset;
}

void sons1(ATerm prod1, ATermInt prodnr1, ATerm item, ATermList labelset)
{
  ATerm prod2, symbol1, symbol2;
  ATermInt ptr, prodnr2;
  ATermList symbols1, symbols2, orgset, newset;
  int iptr;

  if(IS_PROD(prod1)) {
    symbols1 = GET_LIST_ARG(prod1, 0);
    symbol1 = GET_ARG(prod1, 1);
    if(IS_ITEM(item)) {
      prod2 = GET_ARG(item, 0);
      prodnr2 = GET_INT_ARG(item, 1);  
      ptr = GET_INT_ARG(item, 2); 

      if(IS_PROD(prod2)) {
        symbols2 = GET_LIST_ARG(prod2, 0);
        symbol2 = GET_ARG(prod2, 1);
        iptr = ATgetInt(ptr);
        if(!pgen_cnf(prodnr2, iptr, ATgetLength(symbols2), prodnr1)) {
          orgset = local_follow_table[ATgetInt(prodnr1)];

          if(orgset) {
            newset = ATunion(orgset,labelset);
            if(!ATsetEqual(orgset,newset))
              changed = ATtrue;
            local_follow_table[ATgetInt(prodnr1)] = newset;
          }
          else {
            changed = ATtrue;
            local_follow_table[ATgetInt(prodnr1)] = labelset;
          }
        }
      }
    }
  }
}

/*}}}  */
/*{{{  void sons(ATerm item, ATermList labelset, ATermList prods) */

void sons(ATerm item, ATermList labelset, ATermList prods)
{
  ATerm prod, prodnr;

  while(!ATisEmpty(prods)) {
    prodnr = ATgetFirst(prods);
    prods = ATgetNext(prods);
    prod = nr_prod_table[ATgetInt((ATermInt)prodnr)];
    sons1(prod, (ATermInt)prodnr, item, labelset);
  }
}

/*}}}  */
/*{{{  ATermList calc_first(ATermList symbols, int prodnr) */

ATermList calc_first(ATermList symbols, int prodnr)
{
  ATermList set, lset, followset, newset = ATempty;
  ATerm symbol;

  followset = local_follow_table[prodnr];
  if(!followset)
    followset = ATempty;

  if(ATisEmpty(symbols))
    return followset;
  else {
    while(!ATisEmpty(symbols)) {
      symbol = ATgetFirst(symbols);
      symbols = ATgetNext(symbols);

      set = (ATermList)ATtableGet(first_table,symbol);
      if(contains_epsilon(set)) {
        lset = remove_epsilon(set);
        newset = ATunion(newset, lset);
      }
      else {
        return ATunion(newset, set);
      }
    }
    return ATunion(newset,followset);
  }
}

/*}}}  */
/*{{{  ATermList follow(ATerm prod, ATermInt prodnr, int iptr) */

void follow(ATerm prod, ATermInt prodnr, int iptr)
{
  ATermList symbols, restsymbols, firstset, prods;
  ATerm symbol1, symbol2, newitem;
  int i, len;

  if(IS_PROD(prod)) {
    symbols = GET_LIST_ARG(prod, 0);
    symbol1 = GET_ARG(prod, 1);
    len = ATgetLength(symbols);

    for(i = iptr; i < ATgetLength(symbols); i++) {
      restsymbols = ATgetSlice(symbols,i+1,len);
      firstset = calc_first(restsymbols,ATgetInt(prodnr));
      symbol2 = ATelementAt(symbols,i);
      if(!symbol2)
        symbol2 = empty_set;
      newitem = (ATerm)ATmakeAppl4(afun_item,
                                   (ATerm)prod,
                                   (ATerm)prodnr,
                                   (ATerm)ATmakeInt(i),
                                   (ATerm)symbol2);
      prods = (ATermList)ATtableGet(rhs_prods_pairs,symbol2);
      if(prods) {
        sons(newitem,firstset,prods);
      }
    }
  }
}

/*}}}  */
/*{{{  void calc_follow_table2() */

/**
  * Calculation of the first set of the grammar
  **/

void calc_follow_table2()
{
  int ip, cnt = 0;
  ATermList charrange;
  ATerm prod;

  local_follow_table = (ATermList *)malloc(sizeof(ATerm)*MAX_PROD);
  follow_table2 = (ATermList *)malloc(sizeof(ATerm)*MAX_PROD);

  if(!local_follow_table || !follow_table2)
    ATerror("out of memory!\n");

  for(ip=MIN_PROD; ip<MAX_PROD; ip++) {
    local_follow_table[ip] = ATempty;
    follow_table2[ip] = ATempty;
  }

  ATprotectArray((ATerm *)local_follow_table+MIN_PROD, MAX_PROD-MIN_PROD);
  ATprotectArray((ATerm *)follow_table2+MIN_PROD, MAX_PROD-MIN_PROD);

  changed = ATtrue;
  while(changed) {
    cnt++;
    changed = ATfalse;
    for(ip=MIN_PROD;ip<MAX_PROD;ip++) {
      prod = nr_prod_table[ip];

      if(IS_PROD(prod))
        follow(prod, ATmakeInt(ip), 0);
    }
  }

  for(ip=MIN_PROD;ip<MAX_PROD;ip++) {
    ATermList followset;
    prod = nr_prod_table[ip];
    followset = local_follow_table[ip];
    if(followset) {

/*ATwarning("Follow set for %d is %t\n", ip, followset);*/

      charrange = charclass_filtering(followset);
      follow_table2[ip] = charrange;
/*
ATwarning("New follow set is %t\n", charrange);
*/
    }
  }
  ATwarning("Closure achieved in %i steps\n", cnt);
}

/*}}}  */


/*{{{  static ATermList init_dependency(int prod) */

/**
	* Initialize the dependency of a single production.
	*/

static ATermList init_dependency(int prodid)
{
	static ATerm *elems = NULL;
	static int max_elems = 0;

	ATerm prodnr, prod, dep;
	ATermList depends, symbols, orgdep;
	int idx, nr_elems;

	prodnr = (ATerm)ATmakeInt(prodid);
	prod = nr_prod_table[prodid];
	assert(prod);
	symbols = GET_LIST_ARG(prod, 0);

	nr_elems = ATgetLength(symbols);
	if(nr_elems > max_elems) {
		elems = (ATerm *)realloc(elems, sizeof(ATerm)*nr_elems);
		if(!elems)
			ATerror("out of memory!\n");
		max_elems = nr_elems;
	}

	idx = 0;
	while(!ATisEmpty(symbols)) {
		elems[idx++] = ATgetFirst(symbols);
		symbols = ATgetNext(symbols);
	}

	depends = ATempty;
	for(--idx; idx>=0; idx--) {
		ATerm elem = elems[idx];
		if(IS_CHARCLASS(elem))
			break;
		
		orgdep = (ATermList)ATtableGet(rhs_prods_pairs, elem);
		if(!orgdep)
			break; /* Declared sort with no RHS, this should not happen! */

		while(!ATisEmpty(orgdep)) {
			dep = ATgetFirst(orgdep);
			orgdep = ATgetNext(orgdep);
			if(!pgen_cnf((ATermInt)prodnr, idx, nr_elems, (ATermInt)dep))
				depends = ATaddElement(depends, dep);
		}
		
		if(!contains_epsilon((ATermList)ATtableGet(first_table, elem)))
			break;
	}

	/* Remove yourself if present */
	depends = ATremoveElement(depends, prodnr);

	/*ATwarning("dependencies for %d = %t\n", prodid, depends);*/

	return depends;
}

/*}}}  */
/*{{{  static void init_dependencies() */

/**
	* Calculate dependencies (which prods followset depends on which prods followset)
	*/

static void init_dependencies()
{
  int i;

  dependencies = (ATermList *)calloc(MAX_PROD, sizeof(ATermList));
  if(!dependencies)
    ATerror("out of memory!\n");
  ATprotectArray((ATerm *)(dependencies+MIN_PROD), MAX_PROD-MIN_PROD);

  for(i=MIN_PROD; i<MAX_PROD; i++) {
  	dependencies[i] = init_dependency(i);
  }
}

/*}}}  */

/*{{{  static void closure_dependencies() */

/**
	* Calculate the closure of all the dependencies
	*/

static void closure_dependencies()
{
	int *queue;
	int prodid, start, end;
	ATbool *in_queue;
	ATermList depends, closure;

	/*{{{  Initialize depend_closure elements */

	depend_closure = (ATermList *)calloc(MAX_PROD, sizeof(ATermList));
	if(!depend_closure)
		ATerror("out of memory!\n");
	ATprotectArray((ATerm *)(depend_closure+MIN_PROD), MAX_PROD-MIN_PROD);

  for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
		depend_closure[prodid] = ATmakeList1((ATerm)ATmakeInt(prodid));
	}

	/*}}}  */
	/*{{{  Initialize queue and in_queue */

	queue = (int *)malloc(sizeof(int)*MAX_PROD);
	if(!queue)
		ATerror("out of memory!\n");

	start = 0;
	end   = 0;

	in_queue = (ATbool *)calloc(MAX_PROD, sizeof(int));
	if(!in_queue)
		ATerror("out of memory!\n");

	/*}}}  */
	/*{{{  Initially, put all prods in the queue */

  for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
  	queue[end++] = prodid;
  	in_queue[prodid] = ATtrue;
  }

  /*}}}  */
	
  while(start != end) {
  	prodid = queue[start];
  	in_queue[prodid] = ATfalse;
  	start = (start+1)%MAX_PROD;

  	depends = dependencies[prodid];
  	while(!ATisEmpty(depends)) {
  		int child = ATgetInt((ATermInt)ATgetFirst(depends));
  		depends = ATgetNext(depends);
			
  		closure = ATunion(depend_closure[child], depend_closure[prodid]);
  		if(ATgetLength(closure) > ATgetLength(depend_closure[child])) {
  			depend_closure[child] = closure;
  			if(!in_queue[child]) {
  				in_queue[child] = ATtrue;
  				queue[end] = child;
  				end = (end+1)%MAX_PROD;
  				assert(end != start);
  			}
  		}
  	}
  }
  free(queue);
  free(in_queue);   
}

/*}}}  */

/*{{{  ATermList calculate_first(ATermList symbols) */

ATermList calculate_first(ATermList symbols)
{
  ATermList set, lset, followset, newset = ATempty;
  ATerm symbol;

  followset = ATempty;

  if(ATisEmpty(symbols))
    return followset;
  else {
    while(!ATisEmpty(symbols)) {
      symbol = ATgetFirst(symbols);
      symbols = ATgetNext(symbols);

      set = (ATermList)ATtableGet(first_table,symbol);
      if(contains_epsilon(set)) {
        lset = remove_epsilon(set);
        newset = ATunion(newset, lset);
      }
      else {
        return ATunion(newset, set);
      }
    }
    return ATunion(newset,followset);
  }
}

/*}}}  */
/*{{{  static void init_follow_set(int prodid) */

static void init_follow_set(int prodid)
{
  ATerm prodnr, prod, symbol;
  ATermList sets, symbols, follow, prods;
  int iptr, len;

  prodnr = (ATerm)ATmakeInt(prodid);
  prod = nr_prod_table[prodid];
  assert(prod);
  symbols = GET_LIST_ARG(prod, 0);

  iptr = 0;
  len  = ATgetLength(symbols);
  while(!ATisEmpty(symbols)) {
    symbol = ATgetFirst(symbols);
    symbols = ATgetNext(symbols);
    if(!IS_CHARCLASS(symbol)) {
      if(!ATisEmpty(symbols)) {
      	prods = (ATermList)ATtableGet(rhs_prods_pairs, symbol);
      	if(prods) {
          follow = calculate_first(symbols);
      	  while(!ATisEmpty(prods)) {
      	    prod = ATgetFirst(prods);
      	    prods = ATgetNext(prods);
      	    if(!pgen_cnf((ATermInt)prodnr, iptr, len, (ATermInt)prod)) {
      	      prodid = ATgetInt((ATermInt)prod);
      	      sets = initial_follow_sets[prodid];
      	      sets = ATinsert(sets, (ATerm)follow);
      	      initial_follow_sets[prodid] = sets;
      	    }
      	  }
      	}
      }
    }
    iptr++;
  }
}

/*}}}  */
/*{{{  static void init_follow_sets() */

/**
	* Initialize all the follow sets
	*/

static void init_follow_sets()
{
  int prodid;
  ATermList set;

  initial_follow_sets = (ATermList *)calloc(MAX_PROD, sizeof(ATermList));
  if(!initial_follow_sets)
    ATerror("out of memory!\n");
  ATprotectArray((ATerm *)(initial_follow_sets+MIN_PROD), MAX_PROD-MIN_PROD);

  for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
    initial_follow_sets[prodid] = ATempty;
  }

  for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
    init_follow_set(prodid);
  }

  for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
    set = initial_follow_sets[prodid];
    set = ATunionSetList(set);
    set = ATremoveElement(set, empty_set);
    initial_follow_sets[prodid] = set;
  }
}

/*}}}  */

/*{{{  static void union_follow_sets() */

/**
	* Union all follow sets found in the dependency closure
	*/

static void union_follow_sets()
{
	ATermList result, follows, deps;
	int prodid;

  follow_table = (ATermList *)malloc(MAX_PROD*sizeof(ATermList));
  if(!follow_table)
    ATerror("out of memory!\n");

	for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
		follow_table[prodid] = ATempty;
	}
	ATprotectArray((ATerm *)(follow_table+MIN_PROD), MAX_PROD-MIN_PROD);

	for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
		result = ATmakeList1((ATerm)initial_follow_sets[prodid]);
		deps = depend_closure[prodid];
		while(!ATisEmpty(deps)) {
			int depid = ATgetInt((ATermInt)ATgetFirst(deps));
			deps = ATgetNext(deps);
			follows = initial_follow_sets[depid];
			result = ATinsert(result, (ATerm)follows);
		}
		result = ATunionSetList(result);
		result = charclass_filtering(result);
		follow_table[prodid] = result;
	}
}

/*}}}  */

/*{{{  void calc_follow_table() */

void calc_follow_table()
{
/*
  int i;
*/

  init_dependencies();	

/*
	for(i=MIN_PROD; i<MAX_PROD; i++) {
		ATwarning("initial depends %d = %t\n", i, dependencies[i]);
	}
*/

  closure_dependencies();

/*
	for(i=MIN_PROD; i<MAX_PROD; i++) {
		ATwarning("depend closure %d = %t\n", i, depend_closure[i]);
	}
*/
	
  init_follow_sets();

/*
for(i=MIN_PROD; i<MAX_PROD; i++)
	ATwarning("initial follow set %d = %t\n", i, initial_follow_sets[i]);
*/

  union_follow_sets();

/*
	calc_follow_table2();
	for(i=MIN_PROD; i<MAX_PROD; i++) {
		ATwarning("table1[%d] = %t\n", i, follow_table[i]);
		ATwarning("table2[%d] = %t\n", i, follow_table2[i]);
	}
*/

  ATunprotectArray((ATerm *)(dependencies+MIN_PROD));
  free(dependencies);
}

/*}}}  */
