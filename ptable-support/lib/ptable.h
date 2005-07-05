#ifndef _PTABLE_H
#define _PTABLE_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "ptable_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _PTBL_Production *PTBL_Production;
typedef struct _PTBL_CharRanges *PTBL_CharRanges;
typedef struct _PTBL_Version *PTBL_Version;
typedef struct _PTBL_ParseTable *PTBL_ParseTable;
typedef struct _PTBL_Labels *PTBL_Labels;
typedef struct _PTBL_Label *PTBL_Label;
typedef struct _PTBL_States *PTBL_States;
typedef struct _PTBL_State *PTBL_State;
typedef struct _PTBL_Gotos *PTBL_Gotos;
typedef struct _PTBL_Goto *PTBL_Goto;
typedef struct _PTBL_Actions *PTBL_Actions;
typedef struct _PTBL_Action *PTBL_Action;
typedef struct _PTBL_Choices *PTBL_Choices;
typedef struct _PTBL_Choice *PTBL_Choice;
typedef struct _PTBL_SpecialAttr *PTBL_SpecialAttr;
typedef struct _PTBL_LookAhead *PTBL_LookAhead;
typedef struct _PTBL_CharClass *PTBL_CharClass;
typedef struct _PTBL_LookAheads *PTBL_LookAheads;
typedef struct _PTBL_Priorities *PTBL_Priorities;
typedef struct _PTBL_Priority *PTBL_Priority;

/*}}}  */

void PTBL_initPtableApi(void);

/*{{{  protect functions */

void PTBL_protectProduction(PTBL_Production *arg);
void PTBL_protectCharRanges(PTBL_CharRanges *arg);
void PTBL_protectVersion(PTBL_Version *arg);
void PTBL_protectParseTable(PTBL_ParseTable *arg);
void PTBL_protectLabels(PTBL_Labels *arg);
void PTBL_protectLabel(PTBL_Label *arg);
void PTBL_protectStates(PTBL_States *arg);
void PTBL_protectState(PTBL_State *arg);
void PTBL_protectGotos(PTBL_Gotos *arg);
void PTBL_protectGoto(PTBL_Goto *arg);
void PTBL_protectActions(PTBL_Actions *arg);
void PTBL_protectAction(PTBL_Action *arg);
void PTBL_protectChoices(PTBL_Choices *arg);
void PTBL_protectChoice(PTBL_Choice *arg);
void PTBL_protectSpecialAttr(PTBL_SpecialAttr *arg);
void PTBL_protectLookAhead(PTBL_LookAhead *arg);
void PTBL_protectCharClass(PTBL_CharClass *arg);
void PTBL_protectLookAheads(PTBL_LookAheads *arg);
void PTBL_protectPriorities(PTBL_Priorities *arg);
void PTBL_protectPriority(PTBL_Priority *arg);

/*}}}  */
/*{{{  term conversion functions */

PTBL_Production PTBL_ProductionFromTerm(ATerm t);
ATerm PTBL_ProductionToTerm(PTBL_Production arg);
PTBL_CharRanges PTBL_CharRangesFromTerm(ATerm t);
ATerm PTBL_CharRangesToTerm(PTBL_CharRanges arg);
PTBL_Version PTBL_VersionFromTerm(ATerm t);
ATerm PTBL_VersionToTerm(PTBL_Version arg);
PTBL_ParseTable PTBL_ParseTableFromTerm(ATerm t);
ATerm PTBL_ParseTableToTerm(PTBL_ParseTable arg);
PTBL_Labels PTBL_LabelsFromTerm(ATerm t);
ATerm PTBL_LabelsToTerm(PTBL_Labels arg);
PTBL_Label PTBL_LabelFromTerm(ATerm t);
ATerm PTBL_LabelToTerm(PTBL_Label arg);
PTBL_States PTBL_StatesFromTerm(ATerm t);
ATerm PTBL_StatesToTerm(PTBL_States arg);
PTBL_State PTBL_StateFromTerm(ATerm t);
ATerm PTBL_StateToTerm(PTBL_State arg);
PTBL_Gotos PTBL_GotosFromTerm(ATerm t);
ATerm PTBL_GotosToTerm(PTBL_Gotos arg);
PTBL_Goto PTBL_GotoFromTerm(ATerm t);
ATerm PTBL_GotoToTerm(PTBL_Goto arg);
PTBL_Actions PTBL_ActionsFromTerm(ATerm t);
ATerm PTBL_ActionsToTerm(PTBL_Actions arg);
PTBL_Action PTBL_ActionFromTerm(ATerm t);
ATerm PTBL_ActionToTerm(PTBL_Action arg);
PTBL_Choices PTBL_ChoicesFromTerm(ATerm t);
ATerm PTBL_ChoicesToTerm(PTBL_Choices arg);
PTBL_Choice PTBL_ChoiceFromTerm(ATerm t);
ATerm PTBL_ChoiceToTerm(PTBL_Choice arg);
PTBL_SpecialAttr PTBL_SpecialAttrFromTerm(ATerm t);
ATerm PTBL_SpecialAttrToTerm(PTBL_SpecialAttr arg);
PTBL_LookAhead PTBL_LookAheadFromTerm(ATerm t);
ATerm PTBL_LookAheadToTerm(PTBL_LookAhead arg);
PTBL_CharClass PTBL_CharClassFromTerm(ATerm t);
ATerm PTBL_CharClassToTerm(PTBL_CharClass arg);
PTBL_LookAheads PTBL_LookAheadsFromTerm(ATerm t);
ATerm PTBL_LookAheadsToTerm(PTBL_LookAheads arg);
PTBL_Priorities PTBL_PrioritiesFromTerm(ATerm t);
ATerm PTBL_PrioritiesToTerm(PTBL_Priorities arg);
PTBL_Priority PTBL_PriorityFromTerm(ATerm t);
ATerm PTBL_PriorityToTerm(PTBL_Priority arg);

/*}}}  */
/*{{{  list functions */

int PTBL_getLabelsLength (PTBL_Labels arg);
PTBL_Labels PTBL_reverseLabels(PTBL_Labels arg);
PTBL_Labels PTBL_appendLabels(PTBL_Labels arg, PTBL_Label elem);
PTBL_Labels PTBL_concatLabels(PTBL_Labels arg0, PTBL_Labels arg1);
PTBL_Labels PTBL_sliceLabels(PTBL_Labels arg, int start, int end);
PTBL_Label PTBL_getLabelsLabelAt(PTBL_Labels arg, int index);
PTBL_Labels PTBL_replaceLabelsLabelAt(PTBL_Labels arg, PTBL_Label elem, int index);
PTBL_Labels PTBL_makeLabels2(PTBL_Label elem1, PTBL_Label elem2);
PTBL_Labels PTBL_makeLabels3(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3);
PTBL_Labels PTBL_makeLabels4(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3, PTBL_Label elem4);
PTBL_Labels PTBL_makeLabels5(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3, PTBL_Label elem4, PTBL_Label elem5);
PTBL_Labels PTBL_makeLabels6(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3, PTBL_Label elem4, PTBL_Label elem5, PTBL_Label elem6);
int PTBL_getStatesLength (PTBL_States arg);
PTBL_States PTBL_reverseStates(PTBL_States arg);
PTBL_States PTBL_appendStates(PTBL_States arg, PTBL_State elem);
PTBL_States PTBL_concatStates(PTBL_States arg0, PTBL_States arg1);
PTBL_States PTBL_sliceStates(PTBL_States arg, int start, int end);
PTBL_State PTBL_getStatesStateAt(PTBL_States arg, int index);
PTBL_States PTBL_replaceStatesStateAt(PTBL_States arg, PTBL_State elem, int index);
PTBL_States PTBL_makeStates2(PTBL_State elem1, PTBL_State elem2);
PTBL_States PTBL_makeStates3(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3);
PTBL_States PTBL_makeStates4(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3, PTBL_State elem4);
PTBL_States PTBL_makeStates5(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3, PTBL_State elem4, PTBL_State elem5);
PTBL_States PTBL_makeStates6(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3, PTBL_State elem4, PTBL_State elem5, PTBL_State elem6);
int PTBL_getGotosLength (PTBL_Gotos arg);
PTBL_Gotos PTBL_reverseGotos(PTBL_Gotos arg);
PTBL_Gotos PTBL_appendGotos(PTBL_Gotos arg, PTBL_Goto elem);
PTBL_Gotos PTBL_concatGotos(PTBL_Gotos arg0, PTBL_Gotos arg1);
PTBL_Gotos PTBL_sliceGotos(PTBL_Gotos arg, int start, int end);
PTBL_Goto PTBL_getGotosGotoAt(PTBL_Gotos arg, int index);
PTBL_Gotos PTBL_replaceGotosGotoAt(PTBL_Gotos arg, PTBL_Goto elem, int index);
PTBL_Gotos PTBL_makeGotos2(PTBL_Goto elem1, PTBL_Goto elem2);
PTBL_Gotos PTBL_makeGotos3(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3);
PTBL_Gotos PTBL_makeGotos4(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3, PTBL_Goto elem4);
PTBL_Gotos PTBL_makeGotos5(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3, PTBL_Goto elem4, PTBL_Goto elem5);
PTBL_Gotos PTBL_makeGotos6(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3, PTBL_Goto elem4, PTBL_Goto elem5, PTBL_Goto elem6);
int PTBL_getActionsLength (PTBL_Actions arg);
PTBL_Actions PTBL_reverseActions(PTBL_Actions arg);
PTBL_Actions PTBL_appendActions(PTBL_Actions arg, PTBL_Action elem);
PTBL_Actions PTBL_concatActions(PTBL_Actions arg0, PTBL_Actions arg1);
PTBL_Actions PTBL_sliceActions(PTBL_Actions arg, int start, int end);
PTBL_Action PTBL_getActionsActionAt(PTBL_Actions arg, int index);
PTBL_Actions PTBL_replaceActionsActionAt(PTBL_Actions arg, PTBL_Action elem, int index);
PTBL_Actions PTBL_makeActions2(PTBL_Action elem1, PTBL_Action elem2);
PTBL_Actions PTBL_makeActions3(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3);
PTBL_Actions PTBL_makeActions4(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3, PTBL_Action elem4);
PTBL_Actions PTBL_makeActions5(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3, PTBL_Action elem4, PTBL_Action elem5);
PTBL_Actions PTBL_makeActions6(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3, PTBL_Action elem4, PTBL_Action elem5, PTBL_Action elem6);
int PTBL_getChoicesLength (PTBL_Choices arg);
PTBL_Choices PTBL_reverseChoices(PTBL_Choices arg);
PTBL_Choices PTBL_appendChoices(PTBL_Choices arg, PTBL_Choice elem);
PTBL_Choices PTBL_concatChoices(PTBL_Choices arg0, PTBL_Choices arg1);
PTBL_Choices PTBL_sliceChoices(PTBL_Choices arg, int start, int end);
PTBL_Choice PTBL_getChoicesChoiceAt(PTBL_Choices arg, int index);
PTBL_Choices PTBL_replaceChoicesChoiceAt(PTBL_Choices arg, PTBL_Choice elem, int index);
PTBL_Choices PTBL_makeChoices2(PTBL_Choice elem1, PTBL_Choice elem2);
PTBL_Choices PTBL_makeChoices3(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3);
PTBL_Choices PTBL_makeChoices4(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3, PTBL_Choice elem4);
PTBL_Choices PTBL_makeChoices5(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3, PTBL_Choice elem4, PTBL_Choice elem5);
PTBL_Choices PTBL_makeChoices6(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3, PTBL_Choice elem4, PTBL_Choice elem5, PTBL_Choice elem6);
int PTBL_getLookAheadsLength (PTBL_LookAheads arg);
PTBL_LookAheads PTBL_reverseLookAheads(PTBL_LookAheads arg);
PTBL_LookAheads PTBL_appendLookAheads(PTBL_LookAheads arg, PTBL_LookAhead elem);
PTBL_LookAheads PTBL_concatLookAheads(PTBL_LookAheads arg0, PTBL_LookAheads arg1);
PTBL_LookAheads PTBL_sliceLookAheads(PTBL_LookAheads arg, int start, int end);
PTBL_LookAhead PTBL_getLookAheadsLookAheadAt(PTBL_LookAheads arg, int index);
PTBL_LookAheads PTBL_replaceLookAheadsLookAheadAt(PTBL_LookAheads arg, PTBL_LookAhead elem, int index);
PTBL_LookAheads PTBL_makeLookAheads2(PTBL_LookAhead elem1, PTBL_LookAhead elem2);
PTBL_LookAheads PTBL_makeLookAheads3(PTBL_LookAhead elem1, PTBL_LookAhead elem2, PTBL_LookAhead elem3);
PTBL_LookAheads PTBL_makeLookAheads4(PTBL_LookAhead elem1, PTBL_LookAhead elem2, PTBL_LookAhead elem3, PTBL_LookAhead elem4);
PTBL_LookAheads PTBL_makeLookAheads5(PTBL_LookAhead elem1, PTBL_LookAhead elem2, PTBL_LookAhead elem3, PTBL_LookAhead elem4, PTBL_LookAhead elem5);
PTBL_LookAheads PTBL_makeLookAheads6(PTBL_LookAhead elem1, PTBL_LookAhead elem2, PTBL_LookAhead elem3, PTBL_LookAhead elem4, PTBL_LookAhead elem5, PTBL_LookAhead elem6);
int PTBL_getPrioritiesLength (PTBL_Priorities arg);
PTBL_Priorities PTBL_reversePriorities(PTBL_Priorities arg);
PTBL_Priorities PTBL_appendPriorities(PTBL_Priorities arg, PTBL_Priority elem);
PTBL_Priorities PTBL_concatPriorities(PTBL_Priorities arg0, PTBL_Priorities arg1);
PTBL_Priorities PTBL_slicePriorities(PTBL_Priorities arg, int start, int end);
PTBL_Priority PTBL_getPrioritiesPriorityAt(PTBL_Priorities arg, int index);
PTBL_Priorities PTBL_replacePrioritiesPriorityAt(PTBL_Priorities arg, PTBL_Priority elem, int index);
PTBL_Priorities PTBL_makePriorities2(PTBL_Priority elem1, PTBL_Priority elem2);
PTBL_Priorities PTBL_makePriorities3(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3);
PTBL_Priorities PTBL_makePriorities4(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3, PTBL_Priority elem4);
PTBL_Priorities PTBL_makePriorities5(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3, PTBL_Priority elem4, PTBL_Priority elem5);
PTBL_Priorities PTBL_makePriorities6(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3, PTBL_Priority elem4, PTBL_Priority elem5, PTBL_Priority elem6);

/*}}}  */
/*{{{  constructors */

PTBL_Production PTBL_makeProductionExternal(ATerm prod);
PTBL_CharRanges PTBL_makeCharRangesExternal(ATerm ranges);
PTBL_Version PTBL_makeVersionDefault(void);
PTBL_ParseTable PTBL_makeParseTableParseTable(PTBL_Version version, int initialState, PTBL_Labels labels, PTBL_States states, PTBL_Priorities priorities);
PTBL_Labels PTBL_makeLabelsEmpty(void);
PTBL_Labels PTBL_makeLabelsSingle(PTBL_Label head);
PTBL_Labels PTBL_makeLabelsMany(PTBL_Label head, PTBL_Labels tail);
PTBL_Label PTBL_makeLabelDefault(PTBL_Production production, int number);
PTBL_States PTBL_makeStatesEmpty(void);
PTBL_States PTBL_makeStatesSingle(PTBL_State head);
PTBL_States PTBL_makeStatesMany(PTBL_State head, PTBL_States tail);
PTBL_State PTBL_makeStateDefault(int number, PTBL_Gotos gotos, PTBL_Actions actions);
PTBL_Gotos PTBL_makeGotosEmpty(void);
PTBL_Gotos PTBL_makeGotosSingle(PTBL_Goto head);
PTBL_Gotos PTBL_makeGotosMany(PTBL_Goto head, PTBL_Gotos tail);
PTBL_Goto PTBL_makeGotoDefault(PTBL_CharRanges ranges, int stateNumber);
PTBL_Actions PTBL_makeActionsEmpty(void);
PTBL_Actions PTBL_makeActionsSingle(PTBL_Action head);
PTBL_Actions PTBL_makeActionsMany(PTBL_Action head, PTBL_Actions tail);
PTBL_Action PTBL_makeActionDefault(PTBL_CharRanges ranges, PTBL_Choices choices);
PTBL_Choices PTBL_makeChoicesEmpty(void);
PTBL_Choices PTBL_makeChoicesSingle(PTBL_Choice head);
PTBL_Choices PTBL_makeChoicesMany(PTBL_Choice head, PTBL_Choices tail);
PTBL_Choice PTBL_makeChoiceReduce(int length, int label, PTBL_SpecialAttr specialAttr);
PTBL_Choice PTBL_makeChoiceLookaheadReduce(int length, int label, PTBL_SpecialAttr specialAttr, PTBL_LookAheads lookaheads);
PTBL_Choice PTBL_makeChoiceShift(int stateNumber);
PTBL_Choice PTBL_makeChoiceAccept(void);
PTBL_SpecialAttr PTBL_makeSpecialAttrNone(void);
PTBL_SpecialAttr PTBL_makeSpecialAttrReject(void);
PTBL_SpecialAttr PTBL_makeSpecialAttrPrefer(void);
PTBL_SpecialAttr PTBL_makeSpecialAttrAvoid(void);
PTBL_LookAhead PTBL_makeLookAheadDefault(PTBL_CharClass charClass, PTBL_LookAheads lookaheads);
PTBL_CharClass PTBL_makeCharClassDefault(PTBL_CharRanges ranges);
PTBL_LookAheads PTBL_makeLookAheadsEmpty(void);
PTBL_LookAheads PTBL_makeLookAheadsSingle(PTBL_LookAhead head);
PTBL_LookAheads PTBL_makeLookAheadsMany(PTBL_LookAhead head, PTBL_LookAheads tail);
PTBL_Priorities PTBL_makePrioritiesEmpty(void);
PTBL_Priorities PTBL_makePrioritiesSingle(PTBL_Priority head);
PTBL_Priorities PTBL_makePrioritiesMany(PTBL_Priority head, PTBL_Priorities tail);
PTBL_Priority PTBL_makePriorityLeft(int label1, int label2);
PTBL_Priority PTBL_makePriorityRight(int label1, int label2);
PTBL_Priority PTBL_makePriorityNonAssoc(int label1, int label2);
PTBL_Priority PTBL_makePriorityGreater(int label1, int label2);

/*}}}  */
/*{{{  equality functions */

ATbool PTBL_isEqualProduction(PTBL_Production arg0, PTBL_Production arg1);
ATbool PTBL_isEqualCharRanges(PTBL_CharRanges arg0, PTBL_CharRanges arg1);
ATbool PTBL_isEqualVersion(PTBL_Version arg0, PTBL_Version arg1);
ATbool PTBL_isEqualParseTable(PTBL_ParseTable arg0, PTBL_ParseTable arg1);
ATbool PTBL_isEqualLabels(PTBL_Labels arg0, PTBL_Labels arg1);
ATbool PTBL_isEqualLabel(PTBL_Label arg0, PTBL_Label arg1);
ATbool PTBL_isEqualStates(PTBL_States arg0, PTBL_States arg1);
ATbool PTBL_isEqualState(PTBL_State arg0, PTBL_State arg1);
ATbool PTBL_isEqualGotos(PTBL_Gotos arg0, PTBL_Gotos arg1);
ATbool PTBL_isEqualGoto(PTBL_Goto arg0, PTBL_Goto arg1);
ATbool PTBL_isEqualActions(PTBL_Actions arg0, PTBL_Actions arg1);
ATbool PTBL_isEqualAction(PTBL_Action arg0, PTBL_Action arg1);
ATbool PTBL_isEqualChoices(PTBL_Choices arg0, PTBL_Choices arg1);
ATbool PTBL_isEqualChoice(PTBL_Choice arg0, PTBL_Choice arg1);
ATbool PTBL_isEqualSpecialAttr(PTBL_SpecialAttr arg0, PTBL_SpecialAttr arg1);
ATbool PTBL_isEqualLookAhead(PTBL_LookAhead arg0, PTBL_LookAhead arg1);
ATbool PTBL_isEqualCharClass(PTBL_CharClass arg0, PTBL_CharClass arg1);
ATbool PTBL_isEqualLookAheads(PTBL_LookAheads arg0, PTBL_LookAheads arg1);
ATbool PTBL_isEqualPriorities(PTBL_Priorities arg0, PTBL_Priorities arg1);
ATbool PTBL_isEqualPriority(PTBL_Priority arg0, PTBL_Priority arg1);

/*}}}  */
/*{{{  PTBL_Production accessors */

ATbool PTBL_isValidProduction(PTBL_Production arg);
inline ATbool PTBL_isProductionExternal(PTBL_Production arg);
ATbool PTBL_hasProductionProd(PTBL_Production arg);
ATerm PTBL_getProductionProd(PTBL_Production arg);
PTBL_Production PTBL_setProductionProd(PTBL_Production arg, ATerm prod);

/*}}}  */
/*{{{  PTBL_CharRanges accessors */

ATbool PTBL_isValidCharRanges(PTBL_CharRanges arg);
inline ATbool PTBL_isCharRangesExternal(PTBL_CharRanges arg);
ATbool PTBL_hasCharRangesRanges(PTBL_CharRanges arg);
ATerm PTBL_getCharRangesRanges(PTBL_CharRanges arg);
PTBL_CharRanges PTBL_setCharRangesRanges(PTBL_CharRanges arg, ATerm ranges);

/*}}}  */
/*{{{  PTBL_Version accessors */

ATbool PTBL_isValidVersion(PTBL_Version arg);
inline ATbool PTBL_isVersionDefault(PTBL_Version arg);

/*}}}  */
/*{{{  PTBL_ParseTable accessors */

ATbool PTBL_isValidParseTable(PTBL_ParseTable arg);
inline ATbool PTBL_isParseTableParseTable(PTBL_ParseTable arg);
ATbool PTBL_hasParseTableVersion(PTBL_ParseTable arg);
ATbool PTBL_hasParseTableInitialState(PTBL_ParseTable arg);
ATbool PTBL_hasParseTableLabels(PTBL_ParseTable arg);
ATbool PTBL_hasParseTableStates(PTBL_ParseTable arg);
ATbool PTBL_hasParseTablePriorities(PTBL_ParseTable arg);
PTBL_Version PTBL_getParseTableVersion(PTBL_ParseTable arg);
int PTBL_getParseTableInitialState(PTBL_ParseTable arg);
PTBL_Labels PTBL_getParseTableLabels(PTBL_ParseTable arg);
PTBL_States PTBL_getParseTableStates(PTBL_ParseTable arg);
PTBL_Priorities PTBL_getParseTablePriorities(PTBL_ParseTable arg);
PTBL_ParseTable PTBL_setParseTableVersion(PTBL_ParseTable arg, PTBL_Version version);
PTBL_ParseTable PTBL_setParseTableInitialState(PTBL_ParseTable arg, int initialState);
PTBL_ParseTable PTBL_setParseTableLabels(PTBL_ParseTable arg, PTBL_Labels labels);
PTBL_ParseTable PTBL_setParseTableStates(PTBL_ParseTable arg, PTBL_States states);
PTBL_ParseTable PTBL_setParseTablePriorities(PTBL_ParseTable arg, PTBL_Priorities priorities);

/*}}}  */
/*{{{  PTBL_Labels accessors */

ATbool PTBL_isValidLabels(PTBL_Labels arg);
inline ATbool PTBL_isLabelsEmpty(PTBL_Labels arg);
inline ATbool PTBL_isLabelsSingle(PTBL_Labels arg);
inline ATbool PTBL_isLabelsMany(PTBL_Labels arg);
ATbool PTBL_hasLabelsHead(PTBL_Labels arg);
ATbool PTBL_hasLabelsTail(PTBL_Labels arg);
PTBL_Label PTBL_getLabelsHead(PTBL_Labels arg);
PTBL_Labels PTBL_getLabelsTail(PTBL_Labels arg);
PTBL_Labels PTBL_setLabelsHead(PTBL_Labels arg, PTBL_Label head);
PTBL_Labels PTBL_setLabelsTail(PTBL_Labels arg, PTBL_Labels tail);

/*}}}  */
/*{{{  PTBL_Label accessors */

ATbool PTBL_isValidLabel(PTBL_Label arg);
inline ATbool PTBL_isLabelDefault(PTBL_Label arg);
ATbool PTBL_hasLabelProduction(PTBL_Label arg);
ATbool PTBL_hasLabelNumber(PTBL_Label arg);
PTBL_Production PTBL_getLabelProduction(PTBL_Label arg);
int PTBL_getLabelNumber(PTBL_Label arg);
PTBL_Label PTBL_setLabelProduction(PTBL_Label arg, PTBL_Production production);
PTBL_Label PTBL_setLabelNumber(PTBL_Label arg, int number);

/*}}}  */
/*{{{  PTBL_States accessors */

ATbool PTBL_isValidStates(PTBL_States arg);
inline ATbool PTBL_isStatesEmpty(PTBL_States arg);
inline ATbool PTBL_isStatesSingle(PTBL_States arg);
inline ATbool PTBL_isStatesMany(PTBL_States arg);
ATbool PTBL_hasStatesHead(PTBL_States arg);
ATbool PTBL_hasStatesTail(PTBL_States arg);
PTBL_State PTBL_getStatesHead(PTBL_States arg);
PTBL_States PTBL_getStatesTail(PTBL_States arg);
PTBL_States PTBL_setStatesHead(PTBL_States arg, PTBL_State head);
PTBL_States PTBL_setStatesTail(PTBL_States arg, PTBL_States tail);

/*}}}  */
/*{{{  PTBL_State accessors */

ATbool PTBL_isValidState(PTBL_State arg);
inline ATbool PTBL_isStateDefault(PTBL_State arg);
ATbool PTBL_hasStateNumber(PTBL_State arg);
ATbool PTBL_hasStateGotos(PTBL_State arg);
ATbool PTBL_hasStateActions(PTBL_State arg);
int PTBL_getStateNumber(PTBL_State arg);
PTBL_Gotos PTBL_getStateGotos(PTBL_State arg);
PTBL_Actions PTBL_getStateActions(PTBL_State arg);
PTBL_State PTBL_setStateNumber(PTBL_State arg, int number);
PTBL_State PTBL_setStateGotos(PTBL_State arg, PTBL_Gotos gotos);
PTBL_State PTBL_setStateActions(PTBL_State arg, PTBL_Actions actions);

/*}}}  */
/*{{{  PTBL_Gotos accessors */

ATbool PTBL_isValidGotos(PTBL_Gotos arg);
inline ATbool PTBL_isGotosEmpty(PTBL_Gotos arg);
inline ATbool PTBL_isGotosSingle(PTBL_Gotos arg);
inline ATbool PTBL_isGotosMany(PTBL_Gotos arg);
ATbool PTBL_hasGotosHead(PTBL_Gotos arg);
ATbool PTBL_hasGotosTail(PTBL_Gotos arg);
PTBL_Goto PTBL_getGotosHead(PTBL_Gotos arg);
PTBL_Gotos PTBL_getGotosTail(PTBL_Gotos arg);
PTBL_Gotos PTBL_setGotosHead(PTBL_Gotos arg, PTBL_Goto head);
PTBL_Gotos PTBL_setGotosTail(PTBL_Gotos arg, PTBL_Gotos tail);

/*}}}  */
/*{{{  PTBL_Goto accessors */

ATbool PTBL_isValidGoto(PTBL_Goto arg);
inline ATbool PTBL_isGotoDefault(PTBL_Goto arg);
ATbool PTBL_hasGotoRanges(PTBL_Goto arg);
ATbool PTBL_hasGotoStateNumber(PTBL_Goto arg);
PTBL_CharRanges PTBL_getGotoRanges(PTBL_Goto arg);
int PTBL_getGotoStateNumber(PTBL_Goto arg);
PTBL_Goto PTBL_setGotoRanges(PTBL_Goto arg, PTBL_CharRanges ranges);
PTBL_Goto PTBL_setGotoStateNumber(PTBL_Goto arg, int stateNumber);

/*}}}  */
/*{{{  PTBL_Actions accessors */

ATbool PTBL_isValidActions(PTBL_Actions arg);
inline ATbool PTBL_isActionsEmpty(PTBL_Actions arg);
inline ATbool PTBL_isActionsSingle(PTBL_Actions arg);
inline ATbool PTBL_isActionsMany(PTBL_Actions arg);
ATbool PTBL_hasActionsHead(PTBL_Actions arg);
ATbool PTBL_hasActionsTail(PTBL_Actions arg);
PTBL_Action PTBL_getActionsHead(PTBL_Actions arg);
PTBL_Actions PTBL_getActionsTail(PTBL_Actions arg);
PTBL_Actions PTBL_setActionsHead(PTBL_Actions arg, PTBL_Action head);
PTBL_Actions PTBL_setActionsTail(PTBL_Actions arg, PTBL_Actions tail);

/*}}}  */
/*{{{  PTBL_Action accessors */

ATbool PTBL_isValidAction(PTBL_Action arg);
inline ATbool PTBL_isActionDefault(PTBL_Action arg);
ATbool PTBL_hasActionRanges(PTBL_Action arg);
ATbool PTBL_hasActionChoices(PTBL_Action arg);
PTBL_CharRanges PTBL_getActionRanges(PTBL_Action arg);
PTBL_Choices PTBL_getActionChoices(PTBL_Action arg);
PTBL_Action PTBL_setActionRanges(PTBL_Action arg, PTBL_CharRanges ranges);
PTBL_Action PTBL_setActionChoices(PTBL_Action arg, PTBL_Choices choices);

/*}}}  */
/*{{{  PTBL_Choices accessors */

ATbool PTBL_isValidChoices(PTBL_Choices arg);
inline ATbool PTBL_isChoicesEmpty(PTBL_Choices arg);
inline ATbool PTBL_isChoicesSingle(PTBL_Choices arg);
inline ATbool PTBL_isChoicesMany(PTBL_Choices arg);
ATbool PTBL_hasChoicesHead(PTBL_Choices arg);
ATbool PTBL_hasChoicesTail(PTBL_Choices arg);
PTBL_Choice PTBL_getChoicesHead(PTBL_Choices arg);
PTBL_Choices PTBL_getChoicesTail(PTBL_Choices arg);
PTBL_Choices PTBL_setChoicesHead(PTBL_Choices arg, PTBL_Choice head);
PTBL_Choices PTBL_setChoicesTail(PTBL_Choices arg, PTBL_Choices tail);

/*}}}  */
/*{{{  PTBL_Choice accessors */

ATbool PTBL_isValidChoice(PTBL_Choice arg);
inline ATbool PTBL_isChoiceReduce(PTBL_Choice arg);
inline ATbool PTBL_isChoiceLookaheadReduce(PTBL_Choice arg);
inline ATbool PTBL_isChoiceShift(PTBL_Choice arg);
inline ATbool PTBL_isChoiceAccept(PTBL_Choice arg);
ATbool PTBL_hasChoiceLength(PTBL_Choice arg);
ATbool PTBL_hasChoiceLabel(PTBL_Choice arg);
ATbool PTBL_hasChoiceSpecialAttr(PTBL_Choice arg);
ATbool PTBL_hasChoiceLookaheads(PTBL_Choice arg);
ATbool PTBL_hasChoiceStateNumber(PTBL_Choice arg);
int PTBL_getChoiceLength(PTBL_Choice arg);
int PTBL_getChoiceLabel(PTBL_Choice arg);
PTBL_SpecialAttr PTBL_getChoiceSpecialAttr(PTBL_Choice arg);
PTBL_LookAheads PTBL_getChoiceLookaheads(PTBL_Choice arg);
int PTBL_getChoiceStateNumber(PTBL_Choice arg);
PTBL_Choice PTBL_setChoiceLength(PTBL_Choice arg, int length);
PTBL_Choice PTBL_setChoiceLabel(PTBL_Choice arg, int label);
PTBL_Choice PTBL_setChoiceSpecialAttr(PTBL_Choice arg, PTBL_SpecialAttr specialAttr);
PTBL_Choice PTBL_setChoiceLookaheads(PTBL_Choice arg, PTBL_LookAheads lookaheads);
PTBL_Choice PTBL_setChoiceStateNumber(PTBL_Choice arg, int stateNumber);

/*}}}  */
/*{{{  PTBL_SpecialAttr accessors */

ATbool PTBL_isValidSpecialAttr(PTBL_SpecialAttr arg);
inline ATbool PTBL_isSpecialAttrNone(PTBL_SpecialAttr arg);
inline ATbool PTBL_isSpecialAttrReject(PTBL_SpecialAttr arg);
inline ATbool PTBL_isSpecialAttrPrefer(PTBL_SpecialAttr arg);
inline ATbool PTBL_isSpecialAttrAvoid(PTBL_SpecialAttr arg);

/*}}}  */
/*{{{  PTBL_LookAhead accessors */

ATbool PTBL_isValidLookAhead(PTBL_LookAhead arg);
inline ATbool PTBL_isLookAheadDefault(PTBL_LookAhead arg);
ATbool PTBL_hasLookAheadCharClass(PTBL_LookAhead arg);
ATbool PTBL_hasLookAheadLookaheads(PTBL_LookAhead arg);
PTBL_CharClass PTBL_getLookAheadCharClass(PTBL_LookAhead arg);
PTBL_LookAheads PTBL_getLookAheadLookaheads(PTBL_LookAhead arg);
PTBL_LookAhead PTBL_setLookAheadCharClass(PTBL_LookAhead arg, PTBL_CharClass charClass);
PTBL_LookAhead PTBL_setLookAheadLookaheads(PTBL_LookAhead arg, PTBL_LookAheads lookaheads);

/*}}}  */
/*{{{  PTBL_CharClass accessors */

ATbool PTBL_isValidCharClass(PTBL_CharClass arg);
inline ATbool PTBL_isCharClassDefault(PTBL_CharClass arg);
ATbool PTBL_hasCharClassRanges(PTBL_CharClass arg);
PTBL_CharRanges PTBL_getCharClassRanges(PTBL_CharClass arg);
PTBL_CharClass PTBL_setCharClassRanges(PTBL_CharClass arg, PTBL_CharRanges ranges);

/*}}}  */
/*{{{  PTBL_LookAheads accessors */

ATbool PTBL_isValidLookAheads(PTBL_LookAheads arg);
inline ATbool PTBL_isLookAheadsEmpty(PTBL_LookAheads arg);
inline ATbool PTBL_isLookAheadsSingle(PTBL_LookAheads arg);
inline ATbool PTBL_isLookAheadsMany(PTBL_LookAheads arg);
ATbool PTBL_hasLookAheadsHead(PTBL_LookAheads arg);
ATbool PTBL_hasLookAheadsTail(PTBL_LookAheads arg);
PTBL_LookAhead PTBL_getLookAheadsHead(PTBL_LookAheads arg);
PTBL_LookAheads PTBL_getLookAheadsTail(PTBL_LookAheads arg);
PTBL_LookAheads PTBL_setLookAheadsHead(PTBL_LookAheads arg, PTBL_LookAhead head);
PTBL_LookAheads PTBL_setLookAheadsTail(PTBL_LookAheads arg, PTBL_LookAheads tail);

/*}}}  */
/*{{{  PTBL_Priorities accessors */

ATbool PTBL_isValidPriorities(PTBL_Priorities arg);
inline ATbool PTBL_isPrioritiesEmpty(PTBL_Priorities arg);
inline ATbool PTBL_isPrioritiesSingle(PTBL_Priorities arg);
inline ATbool PTBL_isPrioritiesMany(PTBL_Priorities arg);
ATbool PTBL_hasPrioritiesHead(PTBL_Priorities arg);
ATbool PTBL_hasPrioritiesTail(PTBL_Priorities arg);
PTBL_Priority PTBL_getPrioritiesHead(PTBL_Priorities arg);
PTBL_Priorities PTBL_getPrioritiesTail(PTBL_Priorities arg);
PTBL_Priorities PTBL_setPrioritiesHead(PTBL_Priorities arg, PTBL_Priority head);
PTBL_Priorities PTBL_setPrioritiesTail(PTBL_Priorities arg, PTBL_Priorities tail);

/*}}}  */
/*{{{  PTBL_Priority accessors */

ATbool PTBL_isValidPriority(PTBL_Priority arg);
inline ATbool PTBL_isPriorityLeft(PTBL_Priority arg);
inline ATbool PTBL_isPriorityRight(PTBL_Priority arg);
inline ATbool PTBL_isPriorityNonAssoc(PTBL_Priority arg);
inline ATbool PTBL_isPriorityGreater(PTBL_Priority arg);
ATbool PTBL_hasPriorityLabel1(PTBL_Priority arg);
ATbool PTBL_hasPriorityLabel2(PTBL_Priority arg);
int PTBL_getPriorityLabel1(PTBL_Priority arg);
int PTBL_getPriorityLabel2(PTBL_Priority arg);
PTBL_Priority PTBL_setPriorityLabel1(PTBL_Priority arg, int label1);
PTBL_Priority PTBL_setPriorityLabel2(PTBL_Priority arg, int label2);

/*}}}  */
/*{{{  sort visitors */

PTBL_Production PTBL_visitProduction(PTBL_Production arg, ATerm (*acceptProd)(ATerm));
PTBL_CharRanges PTBL_visitCharRanges(PTBL_CharRanges arg, ATerm (*acceptRanges)(ATerm));
PTBL_Version PTBL_visitVersion(PTBL_Version arg);
PTBL_ParseTable PTBL_visitParseTable(PTBL_ParseTable arg, PTBL_Version (*acceptVersion)(PTBL_Version), int (*acceptInitialState)(int), PTBL_Labels (*acceptLabels)(PTBL_Labels), PTBL_States (*acceptStates)(PTBL_States), PTBL_Priorities (*acceptPriorities)(PTBL_Priorities));
PTBL_Labels PTBL_visitLabels(PTBL_Labels arg, PTBL_Label (*acceptHead)(PTBL_Label));
PTBL_Label PTBL_visitLabel(PTBL_Label arg, PTBL_Production (*acceptProduction)(PTBL_Production), int (*acceptNumber)(int));
PTBL_States PTBL_visitStates(PTBL_States arg, PTBL_State (*acceptHead)(PTBL_State));
PTBL_State PTBL_visitState(PTBL_State arg, int (*acceptNumber)(int), PTBL_Gotos (*acceptGotos)(PTBL_Gotos), PTBL_Actions (*acceptActions)(PTBL_Actions));
PTBL_Gotos PTBL_visitGotos(PTBL_Gotos arg, PTBL_Goto (*acceptHead)(PTBL_Goto));
PTBL_Goto PTBL_visitGoto(PTBL_Goto arg, PTBL_CharRanges (*acceptRanges)(PTBL_CharRanges), int (*acceptStateNumber)(int));
PTBL_Actions PTBL_visitActions(PTBL_Actions arg, PTBL_Action (*acceptHead)(PTBL_Action));
PTBL_Action PTBL_visitAction(PTBL_Action arg, PTBL_CharRanges (*acceptRanges)(PTBL_CharRanges), PTBL_Choices (*acceptChoices)(PTBL_Choices));
PTBL_Choices PTBL_visitChoices(PTBL_Choices arg, PTBL_Choice (*acceptHead)(PTBL_Choice));
PTBL_Choice PTBL_visitChoice(PTBL_Choice arg, int (*acceptLength)(int), int (*acceptLabel)(int), PTBL_SpecialAttr (*acceptSpecialAttr)(PTBL_SpecialAttr), PTBL_LookAheads (*acceptLookaheads)(PTBL_LookAheads), int (*acceptStateNumber)(int));
PTBL_SpecialAttr PTBL_visitSpecialAttr(PTBL_SpecialAttr arg);
PTBL_LookAhead PTBL_visitLookAhead(PTBL_LookAhead arg, PTBL_CharClass (*acceptCharClass)(PTBL_CharClass), PTBL_LookAheads (*acceptLookaheads)(PTBL_LookAheads));
PTBL_CharClass PTBL_visitCharClass(PTBL_CharClass arg, PTBL_CharRanges (*acceptRanges)(PTBL_CharRanges));
PTBL_LookAheads PTBL_visitLookAheads(PTBL_LookAheads arg, PTBL_LookAhead (*acceptHead)(PTBL_LookAhead));
PTBL_Priorities PTBL_visitPriorities(PTBL_Priorities arg, PTBL_Priority (*acceptHead)(PTBL_Priority));
PTBL_Priority PTBL_visitPriority(PTBL_Priority arg, int (*acceptLabel1)(int), int (*acceptLabel2)(int));

/*}}}  */

#endif /* _PTABLE_H */
