#include "ksdf2table.h"
#include "statistics.h"
#include <assert.h>

int nr_of_items;
int max_nr_items;

extern int nr_of_states;

extern ATermTable rhs_prods_pairs;
extern ATerm *nr_prod_table;
extern ATermTable nr_state_pairs;

extern ATermTable state_gotos_pairs;
extern ATermTable state_actions_pairs;
extern ATermTable item_memo_table;

extern ATerm initial_state;

extern ATerm update_states(ATermList vertex);
extern ATbool pgen_cnf(ATermInt prodnr1, int iptr, int len, ATermInt prodnr2);
extern ATermList ATaddElement(ATermList l, ATerm elem);
extern ATermList ATunion(ATermList l1, ATermList l2);
extern ATerm charclass_difference(ATerm cc1, ATerm cc2);
extern ATerm charclass_union(ATerm cc1, ATerm cc2);
extern ATerm charclass_intersection(ATerm cc1, ATerm cc2);
extern ATbool charclass_subset(ATerm cc1, ATerm cc2);
extern ATbool is_empty_charclass(ATerm cc);
extern ATermList closure(ATermList items);
extern ATermList outgoing(ATermList itemset);
extern ATermList reductions(ATermList vertex, ATermList actionset);


#if 0
/*{{{  ATermList insert_goto(ATermList gotos, ATerm goto) */
ATermList insert_goto(ATermList gotos, ATerm goto1)
{
  ATermList newgotoset = ATempty;
  ATerm newcc, cc1, cc2, goto2, newgoto;
  ATermInt nr1, nr2;
  ATbool inserted = ATfalse;

  if(IS_GOTO(goto1)) {
    cc1 = GET_ARG(goto1,0);
    nr1 = GET_INT_ARG(goto1,1);
    while(!ATisEmpty(gotos) && !inserted) {
      goto2 = ATgetFirst(gotos);
      gotos = ATgetNext(gotos);
      if(IS_GOTO(goto2)) {
        cc2 = GET_ARG(goto2,0);
        nr2 = GET_INT_ARG(goto2,1);
        if(nr1 == nr2) {
          newcc = charclass_union(cc1, cc2);
          newgoto = (ATerm)ATmakeAppl2(afun_goto, (ATerm)newcc, (ATerm)nr1);
          newgotoset = ATinsert(newgotoset, newgoto);
          newgotoset = ATconcat(ATreverse(newgotoset),gotos);
          inserted = ATtrue;
        }
        else
          newgotoset = ATinsert(newgotoset, goto2);
      }
    }
    if(!inserted) {
      newgotoset = ATinsert(newgotoset, goto1);
      newgotoset = ATreverse(newgotoset);
    }
  }
  return newgotoset;
}
/*}}}  */
#endif

/*{{{  void insert_goto(ATermTable gotos, ATerm goto) */

void insert_goto(ATermTable gotos, ATerm goto1)
{
  ATerm goto2, newgoto, cc2, cc1, newcc;
  ATermInt nr1;

  nr1   = GET_INT_ARG(goto1, 1);
  goto2 = ATtableGet(gotos, (ATerm)nr1);
  if(goto2) {
    cc1   = GET_ARG(goto1, 0);
    cc2   = GET_ARG(goto2, 0);
    newcc = charclass_union(cc1, cc2);
    newgoto = (ATerm)ATmakeAppl2(afun_goto, (ATerm)newcc, (ATerm)nr1);
  } else {
    newgoto = goto1;
  }
  ATtablePut(gotos, (ATerm)nr1, newgoto);
}

/*}}}  */
/*{{{  ATermList insert_item(ATermList items, ATerm item) */

ATermList insert_item(ATermList items, ATerm item1)
{
  if(!IS_ITEM(item1))
     ATabort("expected item, got: %t\n", item1);

  if(ATindexOf(items,item1,0) >= 0)
    return items;
  else
    return ATinsert(items, item1);

  /*
  if(IS_ITEM(item1)) {
		int prodnr, ptr, ptr1;
		int prodnr1 = ATgetInt(GET_INT_ARG(item1, 1));
		ATerm item;

		if(ATisEmpty(items))
			return ATmakeList1(item1);

		item   = ATgetFirst(items);
		prodnr = ATgetInt(GET_INT_ARG(item, 1));

		if(prodnr > prodnr1)
			return ATinsert(items, item1);

		if(prodnr == prodnr1) {
			ptr1    = ATgetInt(GET_INT_ARG(item1, 2));
			ptr    = ATgetInt(GET_INT_ARG(item, 2));

			if(ptr > ptr1)
				return ATinsert(items, item1);
			if(ptr == ptr1)
				return items;
		}
			
		return ATinsert(insert_item(ATgetNext(items), item1), item);
	} else {
		return items;
	}
  */
}

/*}}}  */
/*{{{  ATermList action_insert(ATermList actions, ATerm cc1, ATermList elems1) */

ATermList action_insert(ATermList actions, ATerm cc2, ATermList elems2) 
{
  ATerm action, newaction, cc1, cc3, cc4;
  ATermList newactions = ATempty, newactions2 = ATempty, elems1;
  ATbool matched;

  if(ATisEmpty(actions))
    return ATmakeList1((ATerm)ATmakeAppl2(afun_action, 
                                          (ATerm)cc2, (ATerm)elems2));
  else {
    matched = ATfalse;
    while(!ATisEmpty(actions)) {
      action = ATgetFirst(actions);
      actions = ATgetNext(actions);
      if(IS_ACTION(action)) {
        cc1 = GET_ARG(action,0);
        elems1 = GET_LIST_ARG(action,1);

        cc3 = charclass_intersection(cc1,cc2);
        if(is_empty_charclass(cc3)) {
          newactions = ATinsert(newactions, action);
/*
ATwarning("newactions is %t\n", newactions);
*/
        }
        else {
          newactions2 = ATempty;
          cc4 = charclass_difference(cc2,cc3);
          if(!is_empty_charclass(cc4)) {
            newactions2 = action_insert(actions, cc4, elems2);
            actions = ATempty;
          }
          newaction = (ATerm)ATmakeAppl2(afun_action, (ATerm)cc3, 
                                         (ATerm)ATunion(elems1,elems2));
          newactions2 = ATinsert(newactions2,newaction);
          cc4 = charclass_difference(cc1,cc3);
          if(!is_empty_charclass(cc4)) {
            newaction = (ATerm)ATmakeAppl2(afun_action, 
                                           (ATerm)cc4, (ATerm)elems1);
            newactions2 = ATinsert(newactions2,newaction);
          }
          newactions = ATunion(newactions,newactions2);
/*
ATwarning("New actions = %t\n", newactions);
*/
          matched = ATtrue;
        }
      }
    }
    if(!matched)
      newactions = ATinsert(newactions,
                            (ATerm)ATmakeAppl2(afun_action, 
                                               (ATerm)cc2, (ATerm)elems2));
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
  if(prods) {
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
/*{{{  ATermList shift_charclass(ATerm *items, ATerm *symbols, ATerm label) */

ATermList shift_charclass(ATerm *items, ATerm *symbols, ATerm label)
{
  int len, iptr;
  ATerm item;
  ATermInt prodnr, ptr;
  ATerm prod1, symbol2, symbol3, newitem;
	ATerm *cur;
  ATermList symbols1, newvertex = ATempty;

	cur = symbols;
	while(1) {
		symbol2 = *cur;
		if(!symbol2)
			break;
		if(charclass_subset(label, symbol2)) {
			int index = cur-symbols;
			item = items[index];
			prod1   = GET_ARG(item, 0);
			prodnr  = GET_INT_ARG(item, 1);
			ptr     = GET_INT_ARG(item, 2);
		
			symbols1 = GET_LIST_ARG(prod1, 0);
			len = ATgetLength(symbols1);
			iptr = ATgetInt(ptr);
			if(len > 0 && iptr < len) {
				++iptr;
				symbol3 = ATelementAt(symbols1,iptr);
				if(!symbol3)
					symbol3 = empty_set;
				newitem = (ATerm)ATmakeAppl4(afun_item, prod1, 
																		 (ATerm)prodnr, 
																		 (ATerm)ATmakeInt(iptr),
																		 (ATerm)symbol3);
				newvertex = insert_item(newvertex,newitem);
			}
		}
		cur++;
  }
  return newvertex;
}

/*}}}  */
/*{{{  void gotos(ATermList vertex, ATermList labelset) */

ATermList gotos(ATermList vertex, ATermList labelset)
{
  ATerm label, newstate, gotoelem, cc, item;
  ATermList newvertex, l, gotoElems;
  ATermTable gotoset = ATtableCreate(100,75);

/* Build some arrays so that we don't have to loop over vertex every time,
   but instead walk through these arrays (which is significantly faster) */
  static ATerm *items = NULL;
  static ATerm *symbols = NULL;
  static int max_items = 0;
  int i, nr_items;

  nr_items = ATgetLength(vertex)+1;

  IF_STATISTICS(nr_of_items += nr_items);
  IF_STATISTICS(if (nr_items > max_nr_items) {max_nr_items = nr_items;});

	if(nr_items > max_items) {
		items = (ATerm *)realloc(items, sizeof(ATerm)*nr_items);
		symbols = (ATerm *)realloc(symbols, sizeof(ATerm)*nr_items);
		if(!items || !symbols)
			ATerror("out of memory!\n");
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
	
  while(!ATisEmpty(labelset)) {
    label = ATgetFirst(labelset);
    labelset = ATgetNext(labelset);

    if(ATgetType(label) == AT_INT)
	newvertex = shift_prod(items, symbols, label);
    else
	newvertex = shift_charclass(items, symbols, label);

/*
ATwarning("New vertex for %t is %t\n", label, newvertex);
*/

    newstate = update_states(newvertex);

    if(ATgetType(label) == AT_INT) {
      cc = (ATerm)ATmakeAppl1(afun_char_class,(ATerm)ATmakeList1(label));
      gotoelem = (ATerm)ATmakeAppl2(afun_goto, (ATerm)cc, (ATerm)newstate);
    }
    else
      gotoelem = (ATerm)ATmakeAppl2(afun_goto, (ATerm)label, (ATerm)newstate);

/*
ATwarning("gotoelem is %t\n", gotoelem);
*/

    insert_goto(gotoset, gotoelem);
  }
  gotoElems = ATtableValues(gotoset);
  ATtableDestroy(gotoset);
  return gotoElems;
}

/*}}}  */
/*{{{  static ATermList shifts(ATermList gotos) */

static ATermList shifts(ATermList gotos) 
{
  ATerm gotoelem, state, cc, newcc, range, shift;
  ATermList accept, shiftlist;
  ATermList actionset = ATempty;

/*
ATwarning("Number of gotos is %d\n", ATgetLength(gotos));
*/

  while(!ATisEmpty(gotos)) {
    gotoelem = ATgetFirst(gotos);
    gotos = ATgetNext(gotos);

    if(IS_GOTO(gotoelem)) {
      cc = GET_ARG(gotoelem,0);
      state = GET_ARG(gotoelem,1);
      if(IS_CHARCLASS(cc)) {
        range = GET_ARG(cc,0);
        if(ATisEqual(range,eof_token)) {
          accept = ATmakeList1(ATparse("accept"));
          actionset = action_insert(actionset, cc, accept);  
        }
        else {
          newcc = charclass_intersection(all_chars,cc);
          if(!is_empty_charclass(newcc)) {
            shift = (ATerm)ATmakeAppl1(afun_shift, (ATerm)state);
            shiftlist = ATmakeList1(shift);
            actionset = action_insert(actionset, newcc, shiftlist);  
          }
        }
      }
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
  ATermList vertex, newvertex, labelset, gotoset;

  vertex = (ATermList)ATtableGet(nr_state_pairs,(ATerm)ATmakeInt(statenr));
  if(vertex) {

/*
ATwarning("Processing state %d\n", statenr);
ATwarning("Vertex is %t\n", vertex);
*/


    newvertex = closure(vertex);

/*
ATwarning("New vertex calculated\n");
*/

    labelset = outgoing(newvertex);

/*
ATwarning("Labelset calculated %t\n", labelset);
*/

    gotoset = gotos(newvertex,labelset);

/*
ATwarning("Gotoset = %t\n", gotoset);
*/

    actions(vertex, newvertex, gotoset);

/*
ATwarning("Actions are calculated\n");
*/

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
