#include <assert.h>

#include <aterm2.h>

#include "ksdf2table.h"
#include "predicted.h"
#include "statistics.h"
#include "goto.h"
#include "item.h"
#include "priorities.h"

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
extern ATermList closure(ATermList items);
extern void reductions(ATermList vertex);

static ATerm goto_states[MAX_STATES] = { NULL };
static ATerm goto_classes[MAX_STATES] = { NULL };

static CC_Class  *action_classes[MAX_STATES] = { NULL };
static ATermList  action_actions[MAX_STATES] = { NULL };
static int nr_actions = 0;

/*{{{  ATermList insert_item(ATermList items, Item item) */

ATermList insert_item(ATermList items, Item item)
{
  ATerm it;

  assert(IT_isValidItem(item));

  it = IT_ItemToTerm(item);

  if (ATindexOf(items, it, 0) >= 0) {
    return items;
  }
  else {
    return ATinsert(items, it);
  }
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
  ATerm prodnr;
  ATermList itemset = ATempty, prods;
  Item item;

  prods = (ATermList)ATtableGet(rhs_prods_pairs,symbol);
  if (prods) {
    while(!ATisEmpty(prods)) {
      prodnr = ATgetFirst(prods);
      item = IT_createItem(ATgetInt((ATermInt)prodnr));
      itemset = ATinsert(itemset, IT_ItemToTerm(item));
      prods = ATgetNext(prods);
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

ATermList shift_prod(Item *items, ATerm *symbols, ATerm label)
{
  Item item, newitem;
  ATerm symbol;
  ATerm *cur;
  ATermList newvertex = ATempty;

  symbol = GET_ARG(nr_prod_table[ATgetInt((ATermInt)label)], 1);

  for (cur=symbols; *cur; cur++) {
    if (ATisEqual(symbol, *cur)) {
      int index = cur-symbols;
      item = items[index];
    	
      newitem = IT_shiftDot(item);
      if (newitem != NULL && !conflicts(item, label)) {
	newvertex = insert_item(newvertex,newitem);
      }
    }
  }

  return newvertex;
}

/*}}}  */
/*{{{  static ATermList shift_charclass(Item *items, ATerm *symbols, CC_Class *cc) */

static ATermList shift_charclass(Item *items, ATerm *symbols, CC_Class *cc)
{
  Item item, newitem;
  ATerm *cur;
  ATermList newvertex = ATempty;
  CC_Class *symbol_class;

  for (cur=symbols; *cur; cur++) {
    symbol_class = CC_ClassFromTerm(*cur);

    if (CC_isSubset(cc, symbol_class)) {
      int index = cur-symbols;
      item = items[index];
      newitem = IT_shiftDot(item);
      if (newitem != NULL) {
	newvertex = insert_item(newvertex, newitem);
      }
    }
    CC_free(symbol_class);
  }
  return newvertex;
}

/*}}}  */
/*{{{  ATermList gotos(ATermList vertex, ATermList prods, CC_Set *chars) */

ATermList gotos(ATermList vertex, ATermList prods, CC_Set *chars)
{
  ATerm label, newstate, gotoelem; 
  ATermList newvertex, l, gotoElems;
  Item item;

/* Build some arrays so that we don't have to loop over vertex every time,
   but instead walk through these arrays (which is significantly faster) */
  static Item *items = NULL;
  static ATerm *symbols = NULL;
  static int max_items = 0;
  int i, idx, nr_items;

  gotoElems = ATempty;
  nr_items = ATgetLength(vertex)+1;

  IF_STATISTICS(nr_of_items += nr_items);
  IF_STATISTICS(if (nr_items > max_nr_items) {max_nr_items = nr_items;});

  if (nr_items > max_items) {
    if (items) {
      ATunprotectArray((ATerm *)items);
      ATunprotectArray(symbols);
    }
    items = (Item *)realloc(items, sizeof(ATerm)*nr_items);
    symbols = (ATerm *)realloc(symbols, sizeof(ATerm)*nr_items);
    if (!items || !symbols) {
      ATerror("out of memory!\n");
    }
    memset(items, 0, sizeof(ATerm)*nr_items);
    ATprotectArray((ATerm *)items, nr_items);
    memset(symbols, 0, sizeof(ATerm)*nr_items);
    ATprotectArray(symbols, nr_items);
    max_items = nr_items;
  }

  l = vertex;
  nr_items--;
  for(i=0; i<nr_items; i++) {
    item = IT_ItemFromTerm(ATgetFirst(l));
    items[i] = item;
    symbols[i] = IT_getDotSymbol(item);
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
/*{{{  static void shifts(CC_Set *chars)  */

static void shifts(CC_Set *chars) 
{
  ATerm shift;
  ATermList accept, shiftlist;
  int idx;

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
}

/*}}}  */

/*{{{  void actions(ATermList kernel, ATermList vertex, CC_Set *chars, ATermList gotos)  */

void actions(ATermList kernel, ATermList vertex, CC_Set *chars, ATermList gotos) 
{
  ATermList actionset = ATempty;
  int idx;

  nr_actions = 0;

  shifts(chars);

  reductions(vertex);

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
