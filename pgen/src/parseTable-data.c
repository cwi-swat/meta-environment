/* $Id$*/

#include "atsets.h"
#include "characters.h"
#include "first.h"
#include "follow.h"
#include "parseTable-data.h"
#include "parseTable-stats.h"
#include "pgenOptions.h"
#include "pgen-symbol.h"

#include <SDFME-utils.h>
#include <SDF2PT.h>

static int max_prod_num;
static int nr_of_states;

/* Mapping between productions and numbers. */
static ATermTable prod_nr_pairs; /* TODO: Not used (I think) */

/* Mapping between production numbers and productions. */
static PT_Production *nr_prod_table;

/* Mapping between rhs non-terminals and production numbers. The table is
 * indexed on the rhs symbols of rules and contains ATermLists of the
 * production numbers whose rule has that rhs non-terminal. */
static ATermTable rhs_prods_pairs;

/* Mapping between production numbers & attributes. */
static ATermTable nr_spec_attr_pairs;

/* Mapping between non-terminals and lookahead (follow) sets. */
static ATermTable symbol_lookaheads_table;

/* 2D array indexed on production numbers which contains the lhs symbols of 
 * that production in an array. The array is terminated with the empty symbol.*/
static PT_Symbol **symbol_table;

/* Datastructures to store the generated parse table. */
static int initialStateNumber;

/* Mapping between kernel states and state numbers. */
static ATermTable state_nr_pairs;

/* Mapping between state numbers and kernel states. */
static ATermTable nr_state_pairs;

/* Mapping between kernel state and gotos. */
static ATermTable state_gotos_pairs;

/* Mapping between kernel state and actions (PTBL_Choices). */
static ATermTable state_actions_pairs;

/* The set of sets that contains all states in the parse table. Used to 
 * ensure no duplicate states are created. */
static ATermSOS state_sos;

static ATermIndexedSet priority_table;

void PGEN_initTableGen() {
  nr_of_states = 0;

  prod_nr_pairs = ATtableCreate(1024,75);
  nr_spec_attr_pairs = ATtableCreate(1024,75);
  symbol_lookaheads_table = ATtableCreate(1024,75);
  rhs_prods_pairs = ATtableCreate(1024,75);
  state_nr_pairs = ATtableCreate(1024,75);
  nr_state_pairs = ATtableCreate(1024,75);
  state_gotos_pairs = ATtableCreate(1024,75);
  state_actions_pairs = ATtableCreate(1024,75);
  state_sos = ATsosCreate(8501);
  priority_table = ATindexedSetCreate(1024,75);

  initSymbols();
  CC_init();
  init_first();
  
  if (PGEN_getStatsFlag) {
    PGEN_STATS_initialize();
  }
}

void PGEN_destroyTableGen() {
  int i;

  destroy_first();
  destroy_follow_table();
  CC_cleanup();
  destroySymbols();

  ATunprotectArray((ATerm *)nr_prod_table+MIN_PROD_NUM);
  free(nr_prod_table);

  for (i = 0; i < max_prod_num; i++) {
    if (symbol_table[i]) {
      free(symbol_table[i]);
    }
  }
  free(symbol_table);

  ATtableDestroy(prod_nr_pairs);
  ATtableDestroy(nr_spec_attr_pairs);
  ATtableDestroy(symbol_lookaheads_table);
  ATtableDestroy(rhs_prods_pairs);
  ATtableDestroy(state_nr_pairs);
  ATtableDestroy(nr_state_pairs);
  ATtableDestroy(state_gotos_pairs);
  ATtableDestroy(state_actions_pairs);
  ATsosDestroy(state_sos);
  ATindexedSetDestroy(priority_table);
}

void PGEN_initProductionTables(int maxProdNumber, int minProdNumber) {
  nr_prod_table = (PT_Production *)calloc(maxProdNumber, sizeof(ATerm));
  symbol_table  = (PT_Symbol **)calloc(maxProdNumber, sizeof(ATerm *));

  if (!nr_prod_table || !symbol_table) {
    ATerror("Cannot allocate memory for |nr_prod_table| or |symbol_table| during parse table generation.\n");
  }
 
  /* Why don't we protect symbol_table? Maybe because all symbols also occur in the productions */
  ATprotectArray((ATerm *)nr_prod_table+minProdNumber, maxProdNumber-minProdNumber);

}

void PGEN_allocateSymbolTable(int index, int numberOfSymbols) {
  symbol_table[index] = (PT_Symbol *)malloc(numberOfSymbols*sizeof(ATerm));
  
  if (symbol_table[index] == NULL) {
    ATerror("Cannot allocate space for %d lhs symbols in symbol_table during parse table generation.\n", numberOfSymbols);
  }

}

int PGEN_getMaxProductionNumber() {
  return max_prod_num;
}

void PGEN_setMaxProductionNumber(int value) {
  max_prod_num = value;
}

int PGEN_getInitialStateNumber() {
  return initialStateNumber;
}

void PGEN_setInitialStateNumber(int stateNumber) {
  initialStateNumber = stateNumber;
}

int PGEN_getNumberOfStates() {
  return nr_of_states;
}

void PGEN_setNumberOfStates(int value) {
  nr_of_states = value;
}

void PGEN_increaseNumberOfStates() {
  nr_of_states++;
}

/* If no production number has been assigned to the production then 0 is 
 * returned. */
int PGEN_getProductionNumberOfProduction(SDF_Production prod) {
  ATermInt anr = NULL;
  int nr = 0;
  ATerm newProd;

  SDF_Production stripProd = SDF_removeAttributes(prod);
  anr = (ATermInt)ATtableGet(prod_nr_pairs, SDF_ProductionToTerm(stripProd));

  if (!anr) {
    newProd = PT_ProductionToTerm(SDFProductionToPtProduction(prod));
    if (PGEN_getVerboseModeFlag) {
      ATwarning("No rule found for %t\n", newProd);
    }
    nr = 0;
  }
  else {
    nr = ATgetInt(anr);
  }
  return nr;
}

void PGEN_setProductionNumberOfProduction(int prodNumber, SDF_Production prod) {
  ATtablePut(prod_nr_pairs, SDF_ProductionToTerm(prod), (ATerm)ATmakeInt(prodNumber)); 
}

PT_Production PGEN_getProductionOfProductionNumber(int prodNumber) {
  return nr_prod_table[prodNumber];
}

void PGEN_setProductionOfProductionNumber(PT_Production prod, int prodNumber) {
  nr_prod_table[prodNumber] = prod;
}

ATermList PGEN_getProductionNumbersOfRhsNonTerminal(PT_Symbol rhsNonTerminal) {
  return (ATermList)ATtableGet(rhs_prods_pairs, (ATerm)rhsNonTerminal);
}

void PGEN_addProductionNumberOfRhsNonTerminal(PT_Symbol rhsNonTerminal, int prodNumber) {
  ATerm prodNum = (ATerm)ATmakeInt(prodNumber); 
  ATermList prodNumbers = (ATermList)ATtableGet(rhs_prods_pairs,(ATerm)rhsNonTerminal);
  
  if (prodNumbers) {
    prodNumbers = ATinsert(prodNumbers, prodNum);
  }
  else {
    prodNumbers = ATmakeList1(prodNum);
  }
  
  ATtablePut(rhs_prods_pairs,(ATerm)rhsNonTerminal,(ATerm)prodNumbers);
}

PTBL_SpecialAttr PGEN_getAttributeOfProductionNumber(int prodNumber) {
  return (PTBL_SpecialAttr)ATtableGet(nr_spec_attr_pairs, (ATerm)ATmakeInt(prodNumber)); 
}

void PGEN_setAttributeOfProductionNumber(int attribute, int prodNumber) {
  ATtablePut(nr_spec_attr_pairs, (ATerm)ATmakeInt(prodNumber), (ATerm)ATmakeInt(attribute));
}

PTBL_Restrictions PGEN_getLookaheadsOfSymbol(PT_Symbol symbol) {
  return (PTBL_Restrictions)ATtableGet(symbol_lookaheads_table, (ATerm)symbol);
}

void PGEN_setLookaheadsOfSymbol(PTBL_Restrictions lookaheads, PT_Symbol symbol) {
  ATtablePut(symbol_lookaheads_table, (ATerm)symbol, (ATerm)lookaheads);
}

PT_Symbol PGEN_getLhsSymbolAtPositionXOfProductionNumber(int x, int prodNumber) {
  return symbol_table[prodNumber][x];
}

void PGEN_setLhsSymbolAtPositionXOfProductionNumber(PT_Symbol symbol, int x, int prodNumber) {
  symbol_table[prodNumber][x] = symbol;
}

/* If the state has not yet been assigned a state number -1 is returned. */
int PGEN_getStateNumberOfState(ATermList state) {
  int retval = -1;
  ATermInt stateNumber = (ATermInt)ATtableGet(state_nr_pairs, (ATerm)state);
  
  if (stateNumber) {
    retval = ATgetInt(stateNumber);
  }
  
  return retval;
}

void PGEN_setStateNumberOfState(int stateNumber, ATermList state) {
  ATtablePut(state_nr_pairs, (ATerm)state, (ATerm)ATmakeInt(stateNumber));
}

ATermList PGEN_getStateOfStateNumber(int stateNumber) {
  return (ATermList)ATtableGet(nr_state_pairs, (ATerm)ATmakeInt(stateNumber));
}

void PGEN_setStateOfStateNumber(ATermList state, int stateNumber) {
  ATtablePut(nr_state_pairs, (ATerm)ATmakeInt(stateNumber), (ATerm)state);
}

PTBL_Gotos PGEN_getGotosOfState(ATermList state) {
  return (PTBL_Gotos)ATtableGet(state_gotos_pairs, (ATerm)state);
}

void PGEN_setGotosOfState(PTBL_Gotos gotos, ATermList state) {
  ATtablePut(state_gotos_pairs, (ATerm)state, (ATerm)gotos);
}

PTBL_Choices PGEN_getActionsOfState(ATermList state) {
  return (PTBL_Choices)ATtableGet(state_actions_pairs, (ATerm)state);
}

void PGEN_setActionsOfState(PTBL_Choices actions, ATermList state) {
  ATtablePut(state_actions_pairs, (ATerm)state, (ATerm)actions);
}

/* If the state already exists in the parse table it is not inserted to the set
 * of sets, but it is returned. */
ATermList PGEN_addStateToParseTable(ATermList state) {
  return ATsosInsert(state_sos, state);
}

PTBL_Priority PGEN_getPriority(int index) {
  return (PTBL_Priority)ATindexedSetGetElem(priority_table, index);
}

long PGEN_getPriorityIndex(PTBL_Priority prio) {
  long result = ATindexedSetGetIndex(priority_table, (ATerm)prio);
  return result;
}

long PGEN_putPriority(PTBL_Priority entry, ATbool *isnew) {
  return ATindexedSetPut(priority_table, (ATerm)entry, isnew);
}

