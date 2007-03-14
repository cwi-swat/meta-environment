/* $Id$ */
#ifndef __PARSETABLEDATA_H__
#define __PARSETABLEDATA_H__

#include <SDFME.h>
#include <MEPT.h>
#include <aterm2.h>
#include <ptable.h>

#define MIN_PROD_NUM  257

#if 0
const int PGEN_REGULAR_ATTR = 0;
const int PGEN_REJECT_ATTR  = 1;    /*  Reject attribute  */
const int PGEN_EAGER_ATTR   = 2;    /*  Preferred reduce  */
const int PGEN_UNEAGER_ATTR = 4;    /*  Emergency-only reduction  */
#endif

void PGEN_initTableGen(); 
void PGEN_destroyTableGen();
void PGEN_initProductionTables(int maxProdNumber, int minProdNumber);
void PGEN_allocateSymbolTable(int index, int numberOfSymbols);
  
int  PGEN_getMaxProductionNumber();
void PGEN_setMaxProductionNumber(int value);

int  PGEN_getInitialStateNumber();
void PGEN_setInitialStateNumber(int stateNumber);

int  PGEN_getNumberOfStates();
void PGEN_setNumberOfStates(int value);
void PGEN_increaseNumberOfStates();

int  PGEN_getProductionNumberOfProduction(SDF_Production prod);
void PGEN_setProductionNumberOfProduction(int prodNumber, SDF_Production prod);

PT_Production PGEN_getProductionOfProductionNumber(int prodNumber);
void PGEN_setProductionOfProductionNumber(PT_Production prod, int prodNumber);

ATermList PGEN_getProductionNumbersOfRhsNonTerminal(PT_Symbol rhsNonTerminal);
void PGEN_addProductionNumberOfRhsNonTerminal(PT_Symbol rhsNonTerminal, int prodNumber);

PTBL_SpecialAttr PGEN_getAttributeOfProductionNumber(int prodNumber);
void PGEN_setAttributeOfProductionNumber(int attribute, int prodNumber);

PTBL_Restrictions PGEN_getLookaheadsOfSymbol(PT_Symbol symbol);
void PGEN_setLookaheadsOfSymbol(PTBL_Restrictions lookaheads, PT_Symbol symbol);

PT_Symbol PGEN_getLhsSymbolAtPositionXOfProductionNumber(int x, int prodNumber);
void PGEN_setLhsSymbolAtPositionXOfProductionNumber(PT_Symbol symbol, int x, int prodNumber);

int  PGEN_getStateNumberOfState(ATermList state);
void PGEN_setStateNumberOfState(int stateNumber, ATermList state);

ATermList  PGEN_getStateOfStateNumber(int stateNumber);
void PGEN_setStateOfStateNumber(ATermList state, int stateNumber);

PTBL_Gotos PGEN_getGotosOfState(ATermList state);
void PGEN_setGotosOfState(PTBL_Gotos gotos, ATermList state);

PTBL_Choices PGEN_getActionsOfState(ATermList state);
void PGEN_setActionsOfState(PTBL_Choices actions, ATermList state);

ATermList PGEN_addStateToParseTable(ATermList state);

PTBL_Priority PGEN_getPriority(int index);
long PGEN_getPriorityIndex(PTBL_Priority prio);
long PGEN_putPriority(PTBL_Priority entry, ATbool *isnew);

#endif /* __PARSETABLE-DATA_H__ */
