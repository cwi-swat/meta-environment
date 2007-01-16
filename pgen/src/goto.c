#include <assert.h>

#include <aterm2.h>

#include "ksdf2table.h"
#include "predicted.h"
#include "statistics.h"
#include "goto.h"
#include "item.h"
#include "priorities.h"
#include "follow.h"

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

extern ATermTable symbol_lookaheads_table;
extern ATermTable nr_spec_attr_pairs;

int max_gotos;

extern ATerm initial_state;

extern ATerm update_states(ATermList vertex);

static ATerm goto_states[MAX_STATES] = { NULL };
static ATerm goto_classes[MAX_STATES] = { NULL };

static CC_Class  *action_classes[MAX_STATES] = { NULL };
static ATermList  action_actions[MAX_STATES] = { NULL };
static int nr_actions = 0;

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
/*{{{  static void reductions(ItemSet vertex) */

static void reductions(ItemSet vertex)
{
  int len, iptr, prodnr;
  ATerm prod, symbol;
  ATermList symbols, las;
  CC_Class *charClass;
  CC_Set set;
  ItemSetIterator iter;

  CC_initSet(&set);
  ITS_iterator(vertex, &iter);
  while (ITS_hasNext(&iter)) {
    Item item = ITS_next(&iter);

    assert(IT_isValidItem(item));

    prod = IT_getProd(item);
    prodnr = IT_getProdNr(item);
    iptr = IT_getDotPosition(item);

    symbols = GET_LIST_ARG(prod, 0);
    symbol = GET_ARG(prod, 1);
    len = ATgetLength(symbols);

    if(iptr == len) {
      las = (ATermList)ATtableGet(symbol_lookaheads_table, symbol);
      if(!las) {
	las = ATempty;
      }

      charClass = follow_table[prodnr];
      if (charClass) {
	restrict(charClass, las, ATmakeInt(len), ATmakeInt(prodnr));
      }
    }
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
      action_actions[i] = ATunion2(action_actions[i], actions);
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
/*{{{  static void init_goto() */

static void init_goto()
{
  ATprotectArray(goto_states, MAX_STATES);
  ATprotectArray(goto_classes, MAX_STATES);
  ATprotectArray((ATerm *)(void *)action_actions, MAX_STATES);
}

/*}}}  */

/*{{{  static void free_goto() */

static void free_goto()
{
  ATunprotectArray((ATerm *)(void *)action_actions);
  memset(action_actions, 0, MAX_STATES*sizeof(ATerm));
  ATunprotectArray(goto_classes);
  memset(goto_classes, 0, MAX_STATES*sizeof(ATerm));
  ATunprotectArray(goto_states);
  memset(goto_states, 0, MAX_STATES*sizeof(ATerm));

}
/*}}}  */

/*{{{  static ATermList init()  */

static ATermList init() 
{
  return initialize_items(ATparse("sort(\"<Start>\")"));
}

/*}}}  */
/*{{{  ATermList shift_prod(ItemSet items, ATerm label) */

ATermList shift_prod(ItemSet items, ATerm label)
{
  Item item, newitem;
  ATerm symbol;
  ATermList newvertex = ATempty;
  ItemSetIterator iter;

  symbol = GET_ARG(nr_prod_table[ATgetInt((ATermInt)label)], 1);

  ITS_iteratorPerDotSym(items, symbol, &iter);
  while (ITS_hasNext(&iter)) {
    item = ITS_next(&iter);
    assert(ATisEqual(symbol, IT_getDotSymbol(item)));
    newitem = IT_shiftDot(item);
    if (newitem != NO_ITEM && !conflicts(item, label)) {
      newvertex = ATinsert(newvertex, IT_ItemToTerm(newitem));
    }
  }

  return newvertex;
}

/*}}}  */
/*{{{  static ATermList shift_charclass(ItemSet items, CC_Class *cc) */

static ATermList shift_charclass(ItemSet items, CC_Class *cc)
{
  Item newitem, item;
  ATerm symbol;
  ATermList newvertex = ATempty;
  CC_Class *symbol_class;
  ItemSetIterator iter;

  ITS_iterator(items, &iter);

  while ((item = ITS_next(&iter)) != NO_ITEM) {
    symbol = IT_getDotSymbol(item);
    if (IS_CHARCLASS(symbol)) {
      symbol_class = CC_getCharClass(symbol);

      if (CC_isSubset(cc, symbol_class)) {
	newitem = IT_shiftDot(item);
	newvertex = ATinsert(newvertex, IT_ItemToTerm(newitem));
      }
    }
  }
  return newvertex;
}

/*}}}  */
/*{{{  ATermList gotos(ItemSet vertex, ATermList prods, CC_Set *chars) */

ATermList gotos(ItemSet vertex, ATermList prods, CC_Set *chars)
{
  ATerm label, newstate, gotoelem; 
  ATermList newvertex, gotoElems;
  int idx;

  gotoElems = ATempty;

  IF_PGEN_STATISTICS(nr_of_items += ITS_size(vertex));
  IF_PGEN_STATISTICS(if (ITS_size(vertex) > max_nr_items)
		{max_nr_items = ITS_size(vertex);});

  while(!ATisEmpty(prods)) {
    label = ATgetFirst(prods);
    prods = ATgetNext(prods);

    assert(ATgetType(label) == AT_INT);
    newvertex = shift_prod(vertex, label);
    newstate = update_states(newvertex);

    gotoelem = (ATerm)ATmakeAppl2(afun_goto, (ATerm)ATmakeList1(label), newstate);

    gotoElems = ATinsert(gotoElems, gotoelem);
  }

  /*ATwarning("traversing set: %t\n", CC_ClassToTerm(chars));*/
  for (idx=CC_getSetSize(chars)-1; idx>=0; idx--) {
    CC_Class *cc = CC_getFromSet(chars, idx);
    newvertex = shift_charclass(vertex, cc);
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

/*{{{  void actions(ATermList kernel, ItemSet vertex, CC_Set *chars, ATermList gotos)  */

void actions(ATermList kernel, ItemSet vertex, CC_Set *chars, ATermList gotos) 
{
  ATermList actionset = ATempty;
  int idx;

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

  for (idx=0; idx<nr_actions; idx++) {
    if (action_classes[idx] != NULL) {
      CC_free(action_classes[idx]);
      action_classes[idx] = NULL;
    }
  }

  nr_actions = 0;
}

/*}}}  */
/*{{{  void vertex(int statenr) */

void vertex(int statenr)
{
  ATermList vertex_kernel;
  ItemSet vertex_closure;
  ATermList gotoset;
  ATermList prods;
  CC_Set chars;

  vertex_kernel = (ATermList)ATtableGet(nr_state_pairs, (ATerm)ATmakeInt(statenr));
  if (vertex_kernel) {
    vertex_closure = ITS_create();
    closure(vertex_kernel, vertex_closure);
    /*ATwarning("closure = %t\n", vertex_closure);*/

    CC_initSet(&chars);
    outgoing(vertex_closure, &prods, &chars);
    /*
    fprintf(stderr, "\nchars = ");
    CC_writeSetToFile(stderr, &chars);
    */
    CC_partitionSet(&chars);

    gotoset = gotos(vertex_closure, prods, &chars);
    if (ATgetLength(gotoset) + CC_getSetSize(&chars) > max_gotos) {
      max_gotos = ATgetLength(gotoset) + CC_getSetSize(&chars);
    }

    actions(vertex_kernel, vertex_closure, &chars, gotoset);
    ITS_destroy(vertex_closure);
    CC_flushSet(&chars);
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
  init_goto();

  initial_state = update_states(init());
  goto_graph(ATgetInt((ATermInt)initial_state));
  
  free_goto();
}

/*}}}  */
