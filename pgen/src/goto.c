#include <assert.h>

#include "ksdf2table.h"
#include "predicted.h"
#include "statistics.h"
#include "goto.h"

#define MAX_GOTOS     32000

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
extern void reductions(ATermList vertex);

static ATerm goto_states[MAX_STATES] = { NULL };
static ATerm goto_classes[MAX_STATES] = { NULL };

static CC_Class  *action_classes[MAX_STATES] = { NULL };
static ATermList  action_actions[MAX_STATES] = { NULL };
static int nr_actions = 0;

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
/*{{{  void action_insert(CC_Class *cc, ATermList actions)  */

void action_insert(CC_Class *origcc, ATermList actions) 
{
  CC_Class intersection, cc;
  static CC_Class *diff = NULL;
  int i;

  /*ATwarning("action_insert: %t, %t\n", CC_ClassToTerm(cc), actions);*/

  CC_copy(origcc, &cc);

  if (diff == NULL) {
    diff = CC_alloc();
  }

  for (i=nr_actions-1; i>=0; i--) {
    if (CC_intersection(action_classes[i], &cc, &intersection)) {
      if (CC_difference(action_classes[i], &cc, diff)) {
	action_actions[nr_actions] = action_actions[i];
	action_classes[nr_actions] = diff;
	diff = CC_alloc();
	nr_actions++;
      }
      action_actions[i] = ATunion(action_actions[i], actions);
      CC_copy(&intersection, action_classes[i]);
      if (!CC_difference(&cc, action_classes[i], &cc)) {
	return;
      }
    }
  }

  action_classes[nr_actions] = CC_alloc();
  CC_copy(&cc, action_classes[nr_actions]);
  action_actions[nr_actions] = actions;
  nr_actions++;
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
  ATprotectArray(goto_states, MAX_STATES);
  ATprotectArray(goto_classes, MAX_STATES);
  ATprotectArray((ATerm *)action_actions, MAX_STATES);
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
/*{{{  ATermList shift_charclass(ATerm *items, ATerm *symbols, CC_Class *cc) */

ATermList shift_charclass(ATerm *items, ATerm *symbols, CC_Class *cc)
{
  int len, iptr;
  ATerm item;
  ATermInt prodnr, ptr;
  ATerm prod1, symbol3, newitem;
  ATerm symbol2;
  ATerm *cur;
  ATermList symbols1, newvertex = ATempty;
  CC_Class *symbol2_class;

  cur = symbols;
  while(1) {
    symbol2 = *cur;
    if (!symbol2) {
      break;
    }

    symbol2_class = CC_ClassFromTerm(symbol2);

    if (CC_isSubset(cc, symbol2_class)) {
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
/*{{{  ATermList gotos(ATermList vertex, ATermList prods, CC_Set *chars) */

ATermList gotos(ATermList vertex, ATermList prods, CC_Set *chars)
{
  ATerm label, newstate, gotoelem, item; 
  ATermList newvertex, l, gotoElems;

/* Build some arrays so that we don't have to loop over vertex every time,
   but instead walk through these arrays (which is significantly faster) */
  static ATerm *items = NULL;
  static ATerm *symbols = NULL;
  static int max_items = 0;
  int i, idx, nr_items;

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

    gotoelem = (ATerm)ATmakeAppl2(afun_goto, (ATerm)ATmakeList1(label), newstate);

    gotoElems = ATinsert(gotoElems, gotoelem);
  }

  /*ATwarning("traversing set: %t\n", CC_ClassToTerm(chars));*/
  for (idx=CC_getSetSize(chars)-1; idx>=0; idx--) {
    CC_Class *cc = CC_getFromSet(chars, idx);
    newvertex = shift_charclass(items, symbols, cc);
    newstate = update_states(newvertex);
    goto_states[idx] = newstate;
    goto_classes[idx] = CC_ClassToTerm(cc);
  }

  return gotoElems;
}

/*}}}  */
/*{{{  static ATermList shifts(CC_Set *chars)  */

static ATermList shifts(CC_Set *chars) 
{
  ATerm shift;
  ATermList accept, shiftlist;
  ATermList actionset = ATempty;
  int idx;

/*ATwarning("Number of gotos is %d: %t\n", ATgetLength(gotos), gotos);*/

  for (idx=CC_getSetSize(chars)-1; idx>=0; idx--) {
    CC_Class *cc = CC_getFromSet(chars, idx);

    if (CC_isEOF(cc)) {
      accept = ATmakeList1(ATparse("accept"));
      action_insert(cc, accept);  
    } else {
      shift = (ATerm)ATmakeAppl1(afun_shift, (ATerm)goto_states[idx]);
      shiftlist = ATmakeList1(shift);
      action_insert(cc, shiftlist);  
    }
  }

  return actionset;
}

/*}}}  */

/*{{{  void actions(ATermList kernel, ATermList vertex, CC_Set *chars, ATermList gotos)  */

void actions(ATermList kernel, ATermList vertex, CC_Set *chars, ATermList gotos) 
{
  ATermList actionset = ATempty;
  int idx;

  nr_actions = 0;

  actionset = shifts(chars);
/*
ATwarning("Action set is %t\n", actionset);
*/
  reductions(vertex);

/*
ATwarning("Action set after reductions is %t\n", actionset);
*/

  for (idx=CC_getSetSize(chars)-1; idx>=0; idx--) {
    gotos = ATinsert(gotos, (ATerm)ATmakeAppl2(afun_goto,
					       goto_classes[idx], goto_states[idx]));
  }

  for (idx=0; idx<nr_actions; idx++) {
    actionset = ATinsert(actionset,
			 (ATerm)ATmakeAppl2(afun_action,
					    CC_ClassToTerm(action_classes[idx]),
					    (ATerm)action_actions[idx]));
  }

  ATtablePut(state_gotos_pairs, (ATerm)kernel, (ATerm)gotos);
  ATtablePut(state_actions_pairs, (ATerm)kernel, (ATerm)actionset);

}

/*}}}  */
/*{{{  void vertex(int statenr) */

void vertex(int statenr)
{
  ATermList vertex, newvertex, gotoset;
  ATermList prods;
  CC_Set chars;

  vertex = (ATermList)ATtableGet(nr_state_pairs,(ATerm)ATmakeInt(statenr));
  if (vertex) {
    newvertex = closure(vertex);

    CC_initSet(&chars);
    outgoing(newvertex, &prods, &chars);
    /*
    fprintf(stderr, "\nchars = ");
    CC_writeSetToFile(stderr, &chars);
    */
    CC_partitionSet(&chars);

    gotoset = gotos(newvertex, prods, &chars);
    if (ATgetLength(gotoset) + CC_getSetSize(&chars)> max_gotos) {
      max_gotos = ATgetLength(gotoset) + CC_getSetSize(&chars);
    }

    actions(vertex, newvertex, &chars, gotoset);
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
