#include <assert.h>

#include "ksdf2table.h"
#include "predicted.h"
#include "statistics.h"
#include "goto.h"

int nr_of_items;
int max_nr_items;

extern int nr_of_states;

extern ATermTable rhs_prods_pairs;
extern ATerm *nr_prod_table;
extern ATermTable nr_state_pairs;

extern ATermTable state_gotos_pairs;
extern ATermTable state_actions_pairs;
extern ATermTable item_memo_table;

int max_gotos;

extern ATerm initial_state;

extern ATerm update_states(ATermList vertex);
extern ATbool pgen_cnf(ATermInt prodnr1, int iptr, int len, ATermInt prodnr2);
extern ATermList ATaddElement(ATermList l, ATerm elem);
extern ATermList ATunion(ATermList l1, ATermList l2);
extern ATermList closure(ATermList items);
extern ATermList reductions(ATermList vertex, ATermList actionset);


#if 0
/*{{{  void insert_goto(ATermTable gotos, ATerm goto) */

void insert_goto(ATermTable gotos, ATerm goto1)
{
  ATerm goto2, newgoto;
  ATermInt nr1;
  CC_Class cc1, cc2, newCc;

  nr1   = GET_INT_ARG(goto1, 1);
  goto2 = ATtableGet(gotos, (ATerm)nr1);
  if (goto2) {
    cc1   = (CC_Class)GET_ARG(goto1, 0);
    cc2   = (CC_Class)GET_ARG(goto2, 0);
    newCc = CC_union(cc1, cc2);
    newgoto = (ATerm)ATmakeAppl2(afun_goto, (ATerm)newCc, (ATerm)nr1);
  }
  else {
    newgoto = goto1;
  }
  ATtablePut(gotos, (ATerm)nr1, newgoto);
}

/*}}}  */
#endif

/*{{{  ATermList insert_item(ATermList items, ATerm item) */

ATermList insert_item(ATermList items, ATerm item1)
{
  if (!IS_ITEM(item1))
     ATabort("expected item, got: %t\n", item1);

  if (ATindexOf(items,item1,0) >= 0)
    return items;
  else
    return ATinsert(items, item1);

  /*
  if (IS_ITEM(item1)) {
		int prodnr, ptr, ptr1;
		int prodnr1 = ATgetInt(GET_INT_ARG(item1, 1));
		ATerm item;

		if (ATisEmpty(items))
			return ATmakeList1(item1);

		item   = ATgetFirst(items);
		prodnr = ATgetInt(GET_INT_ARG(item, 1));

		if (prodnr > prodnr1)
			return ATinsert(items, item1);

		if (prodnr == prodnr1) {
			ptr1    = ATgetInt(GET_INT_ARG(item1, 2));
			ptr    = ATgetInt(GET_INT_ARG(item, 2));

			if (ptr > ptr1)
				return ATinsert(items, item1);
			if (ptr == ptr1)
				return items;
		}
			
		return ATinsert(insert_item(ATgetNext(items), item1), item);
	} else {
		return items;
	}
  */
}

/*}}}  */
/*{{{  ATermList action_insert(ATermList actions, CC_Class cc1, ATermList elems1) */

ATermList action_insert(ATermList actions, ATerm cc2, ATermList elems2) 
{
  ATerm action, newaction;
  ATerm cc1;
  ATermList newactions = ATempty, elems1;
  ATbool matched;

  if (ATisEmpty(actions)) {
    return ATmakeList1((ATerm)ATmakeAppl2(afun_action, cc2, (ATerm)elems2));
  }
  else {
    matched = ATfalse;
    while(!ATisEmpty(actions)) {
      action = ATgetFirst(actions);
      actions = ATgetNext(actions);
      assert(IS_ACTION(action));

      cc1 = GET_ARG(action, 0);
      elems1 = GET_LIST_ARG(action,1);

      if (ATisEqual(cc1, cc2)) {
	newaction = (ATerm)ATmakeAppl2(afun_action, cc1, 
				       (ATerm)ATunion(elems1, elems2));
	newactions = ATinsert(newactions, newaction);
	matched = ATtrue;
      } else {
	newactions = ATinsert(newactions, action);
      }
    }

    if (!matched) {
      newaction = (ATerm)ATmakeAppl2(afun_action, cc2, (ATerm)elems2);
      newactions = ATinsert(newactions, newaction);
    }

    return newactions;
  }
}

/*}}}  */
/*{{{  void initialize_items(ATerm symbol) */

ATermList initialize_items(ATerm symbol)
{
  ATerm prod, item;
  ATerm prodnr;
  ATermList itemset = ATempty, prods, symbols;

  prods = (ATermList)ATtableGet(rhs_prods_pairs,symbol);
  if (prods) {
    while(!ATisEmpty(prods)) {
      prodnr = ATgetFirst(prods);
      prods = ATgetNext(prods);
      prod = nr_prod_table[ATgetInt((ATermInt)prodnr)];
      symbols = (ATermList)GET_ARG(prod, 0);
      item = (ATerm)ATmakeAppl4(afun_item,
                                (ATerm)prod,
                                (ATerm)prodnr,
                                (ATerm)ATmakeInt(0),
                                (ATerm)ATelementAt(symbols,0));
      itemset = ATinsert(itemset,item);
    }
  };
  return itemset;
}

/*}}}  */
/*{{{  ATermList init() */

ATermList init() 
{
  return initialize_items(ATparse("sort(\"<Start>\")"));
}

/*}}}  */
/*{{{  ATermList shift_prod(ATermList itemset,ATerm label) */

ATermList shift_prod(ATerm *items, ATerm *symbols, ATerm label)
{
  int len, iptr;
  ATerm item;
  ATermInt prodnr, ptr;
  ATerm prod1, prod2 = NULL, symbol1, symbol2, symbol3, newitem;
  ATerm *cur;
  ATermList symbols1, newvertex = ATempty;

/*
ATwarning("Label = %t\n", label);
*/

  prod2 = nr_prod_table[ATgetInt((ATermInt)label)];
  symbol1  = GET_ARG(prod2, 1);

  cur = symbols;
  while(1) {
    symbol2 = *cur;
    if (!symbol2) {
      break;
    }
    if (ATisEqual(symbol1, symbol2)) {
      int index = cur-symbols;
      item = items[index];
      prod1   = GET_ARG(item, 0);
      prodnr  = GET_INT_ARG(item, 1);
      ptr     = GET_INT_ARG(item, 2);
    	
      symbols1 = GET_LIST_ARG(prod1, 0);
      len = ATgetLength(symbols1);
      iptr = ATgetInt(ptr);
      if (len > 0 && iptr < len) {
    	if (!pgen_cnf(prodnr,iptr,len,(ATermInt)label)) {
          ++iptr;
          symbol3 = ATelementAt(symbols1,iptr);
          if (!symbol3) {
            symbol3 = empty_set;
          }
          newitem = (ATerm)ATmakeAppl4(afun_item, prod1,
                                       (ATerm)prodnr,
                                       (ATerm)ATmakeInt(iptr),
                                       (ATerm)symbol3);
          newvertex = insert_item(newvertex,newitem);
        }
      }
    }
    cur++;
  }
/*
ATwarning("Newvertex = %t\n", newvertex);
*/
  return newvertex;
}

/*}}}  */
/*{{{  ATermList shift_character(ATerm *items, ATerm *symbols, int c) */

ATermList shift_character(ATerm *items, ATerm *symbols, int c)
{
  int len, iptr;
  ATerm item;
  ATermInt prodnr, ptr;
  ATerm prod1, symbol3, newitem;
  ATerm symbol2;
  ATerm *cur;
  ATermList symbols1, newvertex = ATempty;
  CC_Class symbol2_class;

  cur = symbols;
  while(1) {
    symbol2 = *cur;
    if (!symbol2) {
      break;
    }

    symbol2_class = CC_ClassFromTerm(symbol2);

    if (CC_containsChar(symbol2_class, c)) {
      int index = cur-symbols;
      item = items[index];
      prod1   = GET_ARG(item, 0);
      prodnr  = GET_INT_ARG(item, 1);
      ptr     = GET_INT_ARG(item, 2);
    
      symbols1 = GET_LIST_ARG(prod1, 0);
      len = ATgetLength(symbols1);
      iptr = ATgetInt(ptr);
      if (len > 0 && iptr < len) {
    	 ++iptr;
    	 symbol3 = ATelementAt(symbols1,iptr);
    	 if (!symbol3) {
    	   symbol3 = empty_set;
         }
    	 newitem = (ATerm)ATmakeAppl4(afun_item, prod1, (ATerm)prodnr, 
                                      (ATerm)ATmakeInt(iptr), symbol3);
    	 newvertex = insert_item(newvertex,newitem);
      }
    }
    CC_free(symbol2_class);
    cur++;
  }
  return newvertex;
}

/*}}}  */
/*{{{  void gotos(ATermList vertex, ATermList labelset) */

ATermList gotos(ATermList vertex, ATermList prods, CC_Class chars)
{
  ATerm label, newstate, gotoelem, item; 
  ATermList newvertex, l, gotoElems;

/* Build some arrays so that we don't have to loop over vertex every time,
   but instead walk through these arrays (which is significantly faster) */
  static ATerm *items = NULL;
  static ATerm *symbols = NULL;
  static int max_items = 0;
  int i, c, nr_items;

  gotoElems = ATempty;
  nr_items = ATgetLength(vertex)+1;

  IF_STATISTICS(nr_of_items += nr_items);
  IF_STATISTICS(if (nr_items > max_nr_items) {max_nr_items = nr_items;});

  if (nr_items > max_items) {
    if (items) {
      ATunprotectArray(items);
      ATunprotectArray(symbols);
    }
    items = (ATerm *)realloc(items, sizeof(ATerm)*nr_items);
    symbols = (ATerm *)realloc(symbols, sizeof(ATerm)*nr_items);
    if (!items || !symbols) {
      ATerror("out of memory!\n");
    }
    memset(items, 0, sizeof(ATerm)*nr_items);
    ATprotectArray(items, nr_items);
    memset(symbols, 0, sizeof(ATerm)*nr_items);
    ATprotectArray(symbols, nr_items);
    max_items = nr_items;
  }

  l = vertex;
  nr_items--;
  for(i=0; i<nr_items; i++) {
    item = ATgetFirst(l);
    items[i] = item;
    symbols[i] = GET_ARG(item, 3);
    l = ATgetNext(l);
  }
  /* Add sentinel, we stop when NULL is reached */
  items[i] = NULL;
  symbols[i] = NULL;
	
  while(!ATisEmpty(prods)) {
    label = ATgetFirst(prods);
    prods = ATgetNext(prods);

    assert(ATgetType(label) == AT_INT);
    newvertex = shift_prod(items, symbols, label);
    newstate = update_states(newvertex);

    gotoelem = (ATerm)ATmakeAppl2(afun_goto, label, newstate);

    gotoElems = ATinsert(gotoElems, gotoelem);
  }

  /*ATwarning("traversing set: %t\n", CC_ClassToTerm(chars));*/
  for (c=0; c<CC_BITS; c++) {
    if (CC_containsChar(chars, c)) {
      /*ATwarning("%d in set.\n", c);*/
      newvertex = shift_character(items, symbols, c);
      newstate = update_states(newvertex);
      gotoelem = (ATerm)ATmakeAppl2(afun_goto, (ATerm)ATmakeInt(c), newstate);
      gotoElems = ATinsert(gotoElems, gotoelem);
    }
  }

  return gotoElems;
}

/*}}}  */
/*{{{  static ATermList shifts(ATermList gotos) */

static ATermList shifts(ATermList gotos) 
{
  ATerm gotoelem, state, shift;
  ATermList accept, shiftlist;
  ATermList actionset = ATempty;
  ATerm prodnr;
  int prodid;

/*ATwarning("Number of gotos is %d: %t\n", ATgetLength(gotos), gotos);*/

  while(!ATisEmpty(gotos)) {
    gotoelem = ATgetFirst(gotos);
    gotos = ATgetNext(gotos);

    assert(IS_GOTO(gotoelem));
    state = GET_ARG(gotoelem,1);
    prodnr = GET_ARG(gotoelem, 0);
    assert(ATgetType(prodnr) == AT_INT);
    prodid = ATgetInt((ATermInt)prodnr);

    if (prodid == CC_EOF) {
      accept = ATmakeList1(ATparse("accept"));
      actionset = action_insert(actionset, prodnr, accept);  
    } else if (prodid < CC_EOF) {
      shift = (ATerm)ATmakeAppl1(afun_shift, (ATerm)state);
      shiftlist = ATmakeList1(shift);
      actionset = action_insert(actionset, prodnr, shiftlist);  
    }
  }

  return actionset;
}

/*}}}  */

/*{{{  void actions(ATermList kernel, ATermList vertex, ATermList gotos) */

void actions(ATermList kernel, ATermList vertex, ATermList gotos) 
{
  ATermList actionset = ATempty;

  actionset = shifts(gotos);
/*
ATwarning("Action set is %t\n", actionset);
*/
  actionset = reductions(vertex,actionset);

/*
ATwarning("Action set after reductions is %t\n", actionset);
*/

  ATtablePut(state_gotos_pairs, (ATerm)kernel, (ATerm)gotos);
  ATtablePut(state_actions_pairs, (ATerm)kernel, (ATerm)actionset);

}

/*}}}  */
/*{{{  void vertex(int statenr) */

void vertex(int statenr)
{
  ATermList vertex, newvertex, gotoset;
  ATermList prods;
  CC_Class chars;

  vertex = (ATermList)ATtableGet(nr_state_pairs,(ATerm)ATmakeInt(statenr));
  if (vertex) {
    newvertex = closure(vertex);

    chars = CC_makeClassEmpty();
    outgoing(newvertex, &prods, chars);

    gotoset = gotos(newvertex, prods, chars);
    if (ATgetLength(gotoset) > max_gotos) {
      max_gotos = ATgetLength(gotoset);
    }

    actions(vertex, newvertex, gotoset);
  }
}

/*}}}  */
/*{{{  void goto_graph(int statenr) */

void goto_graph(int statenr)
{
  while(statenr <= nr_of_states) {
    vertex(statenr);
    statenr++;
  }
}

/*}}}  */
/*{{{  void calc_goto_graph() */

void calc_goto_graph()
{
  initial_state = update_states(init());
  goto_graph(ATgetInt((ATermInt)initial_state));
}

/*}}}  */
