/* $Id$ */

#include <assert.h>
#include <aterm2.h>
#include <MEPT.h>
#include <ptable.h>

#include "characters.h"
#include "predicted.h"
#include "goto.h"
#include "item.h"
#include "priorities.h"
#include "follow.h"
#include "parseTable-data.h"
#include "pgenOptions.h"
#include "parseTable-stats.h"
#include "atsets.h"

#define MAX_STATES 130000

static int goto_states[MAX_STATES] = { -1 };
static PT_CharRanges goto_classes[MAX_STATES] = { NULL };

static CC_Class    *action_classes[MAX_STATES] = { NULL };
static PTBL_Actions action_actions[MAX_STATES] = { NULL };
static int NR_ACTIONS = 0; /**< I think this is the number of actions added 
                             * during the creation of one state. */


ATermList initialize_items(PT_Symbol symbol) {
  ATerm prodnr;
  ATermList itemset = ATempty;
  ATermList prodNumbers;
  Item item;

  prodNumbers = PGEN_getProductionNumbersOfRhsNonTerminal(symbol);
  if (prodNumbers) {
    while(!ATisEmpty(prodNumbers)) {
      prodnr = ATgetFirst(prodNumbers);
      item = IT_createItem(ATgetInt((ATermInt)prodnr));
      itemset = ATinsert(itemset, IT_ItemToTerm(item));
      prodNumbers = ATgetNext(prodNumbers);
    }
  };
  return itemset;
}

int update_states(ATermList state) {
  int nr;
  ATermList orig;

  orig = PGEN_addStateToParseTable(state);
  nr = PGEN_getStateNumberOfState(orig);
 
  if (nr == -1) {
    nr = PGEN_getNumberOfStates();
    PGEN_setStateNumberOfState(nr, orig);
    PGEN_setStateOfStateNumber(orig, nr);
    PGEN_increaseNumberOfStates();
    assert(PGEN_getNumberOfStates() < MAX_STATES);
  }
  
  return nr;
}

/** 
 * For a given character class lookahead and a list of parse table actions, 
 * 
 * \param origcc 
 * \param actions 
 */
void action_insert(CC_Class *origcc, PTBL_Actions actions) {
  CC_Class intersection;
  CC_Class cc;
  static CC_Class *diff = NULL;
  int i;

  /*ATwarning("action_insert: %t, %t\n", CC_ClassToTerm(cc), actions);*/

  CC_copy(origcc, &cc);

  if (diff == NULL) {
    diff = CC_alloc();
  }

  /* For the actions that have already been added to this state, find the 
   * intersection of the actions' char classes and the lookahead's char class.
   * For the char classes that do not appear in the existing actions of this 
   * state */
  for (i=NR_ACTIONS-1; i>=0; i--) {
    if (CC_intersection(action_classes[i], &cc, &intersection)) {
      if (CC_difference(action_classes[i], &cc, diff)) {
        action_actions[NR_ACTIONS] = action_actions[i];
        action_classes[NR_ACTIONS] = diff;
        diff = CC_alloc();
        NR_ACTIONS++;
      }
      /* TODO: Write a wrapper function in a new file actionSets to make this 
       * type safe. */
      action_actions[i] = (PTBL_Actions)ATunion((ATermList)action_actions[i], 
          (ATermList)actions);
      CC_copy(&intersection, action_classes[i]);
      if (!CC_difference(&cc, action_classes[i], &cc)) {
        return;
      }
    }
  }

  action_classes[NR_ACTIONS] = CC_alloc();
  CC_copy(&cc, action_classes[NR_ACTIONS]);
  action_actions[NR_ACTIONS] = actions;
  NR_ACTIONS++;
}

/** 
 * For a given reduction (whose length and production number are passed in as 
 * arguments) add a <em>normal</em> reduce action to the parse table if: 
 * \li the production's non-terminal follow restrictions are empty.
 * \li the restriction only contains <b>one char-class</b> and the reduction's 
 * (single) lookahead symbol does not match the follow restriction.
 *
 * If the restriction contains a <b>list of char-classes</b> and the 
 * reduction's (single) lookahead symbol does not match the first char-class, 
 * then a <em>lookaheadReduce</em> action is added.
 *
 * \warning This code relies on the order of the follow restrictions. For any 
 * given non-terminal the single symbol restrictions must appear before the
 * multi symbol restrictions in the list.
 * 
 * \param lookahead follow set of production to be reduced.
 * \param restrictions the production's rhs symbol follow restrictions.
 * \param len the number of symbols to be reduced.
 * \param prodnr the production number to be reduced.
 */
static void filterReductions(CC_Class *lookahead, PTBL_Restrictions restrictions, int len, int prodnr) {
  PTBL_Action reduce;
  PTBL_Actions reducelist;
  PTBL_SpecialAttr special_attr;

  if (PTBL_isRestrictionsEmpty(restrictions)) {
    /* If there are no restrictions add a normal reduction for the lookahead. */
    special_attr = PGEN_getAttributeOfProductionNumber(prodnr);
    reduce = PTBL_makeActionReduce(len, prodnr, special_attr);
    reducelist = PTBL_makeActionsSingle(reduce);
    action_insert(lookahead, reducelist);
  }
  else {
    CC_Class *currentla = CC_alloc();
    CC_copy(lookahead, currentla);

    /* Go through all restrictions while there is still a valid lookahead... */
    while (!PTBL_isRestrictionsEmpty(restrictions) && !CC_isEmpty(currentla)) {
      CC_Class difference;
      PTBL_Restriction restriction = PTBL_getRestrictionsHead(restrictions);
      PTBL_CharClasses restrictionSymbols = PTBL_getRestrictionCharClasses(restriction);
      CC_Class *restrictionCC = CC_ClassFromTerm((ATerm)PTBL_getCharClassesHead(restrictionSymbols));

      if (PTBL_getCharClassesLength(restrictionSymbols) == 1) {
        /* If there is only one symbol in the restriction then for each 
         * lookahead that does not match the symbols in the restriction
         * add a normal reduction. */
        
        /* Calculate the difference between the parse table lookahead and the 
         * restriction.*/
        CC_difference(currentla, restrictionCC, &difference);
      }
      else {
        /* If there is more than one symbol in the restriction add normal 
         * reductions in the position where the lookahead differs from the 
         * first restriction symbol and add lookahead reduces in the 
         * position that the lookahead is the same. */
        CC_Class intersection;
        
        CC_difference(currentla, restrictionCC, &difference);
        
        if (CC_intersection(currentla, restrictionCC, &intersection)) {
          PTBL_Restrictions remainingRestrictions = PTBL_makeRestrictionsSingle(PTBL_makeRestrictionFollow(PTBL_getCharClassesTail(restrictionSymbols)));
        
          special_attr = PGEN_getAttributeOfProductionNumber(prodnr);
          reduce = PTBL_makeActionLookaheadReduce(len, prodnr, special_attr, remainingRestrictions);
          reducelist = PTBL_makeActionsSingle(reduce);
        
          action_insert(&intersection, reducelist);
          CC_clear(&intersection);
        }
      }

      /* Continue applying the next restrictions with the lookahead that
       * is not filtered yet.
       */
      CC_copy(&difference, currentla);
      restrictions = PTBL_getRestrictionsTail(restrictions); 
    }

    if (!CC_isEmpty(currentla)) {
      special_attr = PGEN_getAttributeOfProductionNumber(prodnr);
      reduce = PTBL_makeActionReduce(len, prodnr, special_attr);
      reducelist = PTBL_makeActionsSingle(reduce);
      action_insert(currentla, reducelist);
    }

    CC_free(currentla);
  }
}

/** 
 * Iterate over the items in a state and if an item is a reduction then get the 
 * reduction's lookahead and check that the follow restrictions allow the 
 * reduction. 
 *
 * \param state 
 */
static void reductions(ItemSet state) {
  int len, iptr, prodnr;
  PT_Production prod;
  PT_Symbol symbol;
  PT_Symbols symbols;
  PTBL_Restrictions followRestLookahead;
  CC_Class *lookahead;
  CC_Set set;
  ItemSetIterator iter;

  CC_initSet(&set);
  ITS_iterator(state, &iter);
  while (ITS_hasNext(&iter)) {
    Item item = ITS_next(&iter);

    assert(IT_isValidItem(item));

    prod = IT_getProd(item);
    prodnr = IT_getProdNr(item);
    iptr = IT_getDotPosition(item);

    symbols = PT_getProductionLhs(prod);
    symbol = PT_getProductionRhs(prod);
    len = PT_getSymbolsLength(symbols);

    /* If the item is a reduction. */
    if(iptr == len) {
      followRestLookahead = (PTBL_Restrictions)PGEN_getLookaheadsOfSymbol(symbol);
      if(!followRestLookahead) {
        followRestLookahead = PTBL_makeRestrictionsEmpty();
      }

      lookahead = PGEN_getFollowSet(prodnr);
      if (lookahead) { /** \todo: should this be an assert? */
        filterReductions(lookahead, followRestLookahead, len, prodnr);
      }
    }
  }
}

static void shifts(CC_Set *chars) {
  PTBL_Action shift;
  PTBL_Actions shiftlist;
  PTBL_Action accept;
  int idx;

  for (idx=CC_getSetSize(chars)-1; idx>=0; idx--) {
    CC_Class *cc = CC_getFromSet(chars, idx);

    if (CC_isEOF(cc)) {
      accept = PTBL_makeActionAccept();
      action_insert(cc, PTBL_makeActionsSingle(accept));  
    } else {
      shift = PTBL_makeActionShift(goto_states[idx]);
      shiftlist = PTBL_makeActionsSingle(shift);
      action_insert(cc, shiftlist);  
    }
  }
}

/** 
 * Create a new state by moving the dot past the production number's RHS symbol
 * for the items given in the item set. 
 * 
 * \param items 
 * \param prodNumber 
 * 
 * \return 
 */
ATermList shift_prod(ItemSet items, int prodNumber) {
  Item item, newitem;
  PT_Symbol symbol;
  ATermList newvertex = ATempty;
  ItemSetIterator iter;
  PT_Production prod = PGEN_getProductionOfProductionNumber(prodNumber);
    
  symbol = PT_getProductionRhs(prod);

  ITS_iteratorPerDotSym(items, symbol, &iter);
  while (ITS_hasNext(&iter)) {
    item = ITS_next(&iter);
    assert(PT_isEqualSymbol(symbol, IT_getDotSymbol(item)));
    newitem = IT_shiftDot(item);
    if (newitem != NO_ITEM && !PGEN_isPriorityConflict(item, prodNumber)) {
      newvertex = ATinsert(newvertex, IT_ItemToTerm(newitem));
    }
  }

  return newvertex;
}

/** 
 * Create a new state by moving the dot past the terminal symbols defined in 
 * the given character class for the items given in the item set. 
 * 
 * \param items 
 * \param cc 
 * 
 * \return 
 */
static ATermList shift_charclass(ItemSet items, CC_Class *cc) {
  Item newitem, item;
  PT_Symbol symbol;
  ATermList newvertex = ATempty;
  CC_Class *symbol_class;
  ItemSetIterator iter;

  ITS_iterator(items, &iter);

  while ((item = ITS_next(&iter)) != NO_ITEM) {
    symbol = (PT_Symbol)IT_getDotSymbol(item);
    if (PT_isSymbolCharClass(symbol)) {
      symbol_class = CC_getCharClass(symbol);

      if (CC_isSubset(cc, symbol_class)) {
        newitem = IT_shiftDot(item);
        newvertex = ATinsert(newvertex, IT_ItemToTerm(newitem));
      }
    }
  }
  return newvertex;
}

/** 
 * For a state and a list of productions and symbols that can label the out 
 * edges of the state, create the new states and edges. This means that the 
 * goto actions are added to the parse table. 
 * 
 * \param kernelState 
 * \param closedItems 
 * \param prods 
 * \param chars 
 */
void gotos(ATermList kernelState, ItemSet closedItems, ATermList prods, CC_Set *chars) {
  int prodNumber;
  ATerm gotoElem; 
  ATermList newState; 
  ATermList gotoElems = ATempty;
  PTBL_CharRanges charRanges;
  int idx;
  int newStateNumber;

  if (PGEN_getStatsFlag) {
    PGEN_STATS_increaseItems(ITS_size(closedItems));
  }   

  while(!ATisEmpty(prods)) {
    prodNumber = ATgetInt((ATermInt)ATgetFirst(prods));
    prods = ATgetNext(prods);
    newState = shift_prod(closedItems, prodNumber);
    newStateNumber = update_states(newState);

    charRanges = (PTBL_CharRanges)PT_makeCharRangesSingle(PT_makeCharRangeCharacter(prodNumber));
    gotoElem = (ATerm)PTBL_makeGotoDefault(charRanges, newStateNumber);
    gotoElems = ATinsert(gotoElems, gotoElem);
  }

  for (idx=CC_getSetSize(chars)-1; idx>=0; idx--) {
    CC_Class *cc = CC_getFromSet(chars, idx);
    newState = shift_charclass(closedItems, cc);
    newStateNumber = update_states(newState);
    goto_states[idx] = newStateNumber;
    goto_classes[idx] = CC_ClassToPTCharRanges(cc);

    gotoElem = (ATerm)PTBL_makeGotoDefault((PTBL_CharRanges)goto_classes[idx], goto_states[idx]);
    gotoElems = ATinsert(gotoElems, gotoElem);
  }

  PGEN_setGotosOfState((PTBL_Gotos)gotoElems, kernelState);
}

/** 
 * Given the kernelState and the closedItems (the set of items that can be 
 * reached by performing the epsilon closure on the kernel state), add the 
 * shift and reduce actions to the parse table. 
 * 
 * \param kernelState 
 * \param closedItems 
 * \param chars 
 */
void actions(ATermList kernelState, ItemSet closedItems, CC_Set *chars) {
  PTBL_Choices actionset = PTBL_makeChoicesEmpty();
  int idx;

  /* I think that the NR_ACTIONS gets modified here. */
  shifts(chars);
  reductions(closedItems);
  
  for (idx=0; idx<NR_ACTIONS; idx++) {
    PT_CharRanges charRanges = CC_ClassToPTCharRanges(action_classes[idx]);
    PTBL_Choice choice = PTBL_makeChoiceDefault((PTBL_CharRanges)charRanges,action_actions[idx]);
    actionset = PTBL_makeChoicesMany(choice, actionset);
  }

  PGEN_setActionsOfState(actionset, kernelState);

  for (idx=0; idx<NR_ACTIONS; idx++) {
    if (action_classes[idx] != NULL) {
      CC_free(action_classes[idx]);
      action_classes[idx] = NULL;
    }
  }

  NR_ACTIONS = 0;
}

/** 
 * A state is created by first constructing the set of kernel items, and then
 * a separate set of items that is the result of performing the epsilon 
 * closure on the kernel items. It is only necessary to store the kernel items
 * of the state since the non-kernel items result from the closure of the 
 * kernel items. This reduces the number of items that need to be compared to 
 * see if an item already exists in a state.
 *
 * A kernel state is a state that only contains items of the form 
 * \f$(\alpha \cdot \beta -> X)\f$ or if \f$X\f$ is the start symbol then 
 * \f$(\cdot \alpha -> X)\f$. 
 * 
 * \param statenr the state number.
 */
void createState(int statenr) {
  ATermList kernelState; /* A state containing only kernel items. */
  ItemSet closedItems;
  ATermList prods;
  CC_Set chars;

  kernelState = PGEN_getStateOfStateNumber(statenr);
  if (kernelState) {
    closedItems = closure(kernelState);

    CC_initSet(&chars);
    /* Find the productions and symbols that will label the outgoing edges of 
     * the closed state. */
    outgoing(closedItems, &prods, &chars);
    
    CC_partitionSet(&chars);
    
    gotos(kernelState, closedItems, prods, &chars);
    actions(kernelState, closedItems, &chars);
    
    ITS_destroy(closedItems);
    CC_flushSet(&chars);
  }
}

void createDFA() {
  int stateNumber;
  PT_Symbol startSymbol = (PT_Symbol)ATparse("sort(\"<Start>\")");
  
  ATprotectArray((ATerm *)(void *)goto_classes, MAX_STATES);
  ATprotectArray((ATerm *)(void *)action_actions, MAX_STATES);
  
  stateNumber = update_states(initialize_items(startSymbol));
  PGEN_setInitialStateNumber(stateNumber);

  while(stateNumber <= PGEN_getNumberOfStates()) {
    createState(stateNumber);
    stateNumber++;
  }
  
  ATunprotectArray((ATerm *)(void *)action_actions);
  memset(action_actions, 0, MAX_STATES*sizeof(ATerm));
  ATunprotectArray((ATerm *)(void *)goto_classes);
  memset(goto_classes, 0, MAX_STATES*sizeof(PT_CharRanges));
}

