#ifndef _PTABLE_H
#define _PTABLE_H

/*{{{  includes */

#include <aterm1.h>
#include "ptable_dict.h"

/*}}}  */

/*{{{  prologue */

#include <MEPT.h>

typedef PT_Production PTA_Production;
typedef PT_CharRanges PTA_CharRanges;

/*}}}  */
/*{{{  typedefs */

typedef struct _PTA_Version *PTA_Version;
typedef struct _PTA_ParseTable *PTA_ParseTable;
typedef struct _PTA_Labels *PTA_Labels;
typedef struct _PTA_Label *PTA_Label;
typedef struct _PTA_States *PTA_States;
typedef struct _PTA_State *PTA_State;
typedef struct _PTA_Gotos *PTA_Gotos;
typedef struct _PTA_Goto *PTA_Goto;
typedef struct _PTA_Actions *PTA_Actions;
typedef struct _PTA_Action *PTA_Action;
typedef struct _PTA_Choices *PTA_Choices;
typedef struct _PTA_Choice *PTA_Choice;
typedef struct _PTA_SpecialAttr *PTA_SpecialAttr;
typedef struct _PTA_LookAhead *PTA_LookAhead;
typedef struct _PTA_CharClass *PTA_CharClass;
typedef struct _PTA_LookAheads *PTA_LookAheads;
typedef struct _PTA_Priorities *PTA_Priorities;
typedef struct _PTA_Priority *PTA_Priority;

/*}}}  */

void PTA_initPtableApi(void);

/*{{{  term conversion functions */

#define PTA_makeVersionFromTerm(t) (PTA_VersionFromTerm(t))
PTA_Version PTA_VersionFromTerm(ATerm t);
#define PTA_makeTermFromVersion(t) (PTA_VersionToTerm(t))
ATerm PTA_VersionToTerm(PTA_Version arg);
#define PTA_makeParseTableFromTerm(t) (PTA_ParseTableFromTerm(t))
PTA_ParseTable PTA_ParseTableFromTerm(ATerm t);
#define PTA_makeTermFromParseTable(t) (PTA_ParseTableToTerm(t))
ATerm PTA_ParseTableToTerm(PTA_ParseTable arg);
#define PTA_makeLabelsFromTerm(t) (PTA_LabelsFromTerm(t))
PTA_Labels PTA_LabelsFromTerm(ATerm t);
#define PTA_makeTermFromLabels(t) (PTA_LabelsToTerm(t))
ATerm PTA_LabelsToTerm(PTA_Labels arg);
#define PTA_makeLabelFromTerm(t) (PTA_LabelFromTerm(t))
PTA_Label PTA_LabelFromTerm(ATerm t);
#define PTA_makeTermFromLabel(t) (PTA_LabelToTerm(t))
ATerm PTA_LabelToTerm(PTA_Label arg);
#define PTA_makeStatesFromTerm(t) (PTA_StatesFromTerm(t))
PTA_States PTA_StatesFromTerm(ATerm t);
#define PTA_makeTermFromStates(t) (PTA_StatesToTerm(t))
ATerm PTA_StatesToTerm(PTA_States arg);
#define PTA_makeStateFromTerm(t) (PTA_StateFromTerm(t))
PTA_State PTA_StateFromTerm(ATerm t);
#define PTA_makeTermFromState(t) (PTA_StateToTerm(t))
ATerm PTA_StateToTerm(PTA_State arg);
#define PTA_makeGotosFromTerm(t) (PTA_GotosFromTerm(t))
PTA_Gotos PTA_GotosFromTerm(ATerm t);
#define PTA_makeTermFromGotos(t) (PTA_GotosToTerm(t))
ATerm PTA_GotosToTerm(PTA_Gotos arg);
#define PTA_makeGotoFromTerm(t) (PTA_GotoFromTerm(t))
PTA_Goto PTA_GotoFromTerm(ATerm t);
#define PTA_makeTermFromGoto(t) (PTA_GotoToTerm(t))
ATerm PTA_GotoToTerm(PTA_Goto arg);
#define PTA_makeActionsFromTerm(t) (PTA_ActionsFromTerm(t))
PTA_Actions PTA_ActionsFromTerm(ATerm t);
#define PTA_makeTermFromActions(t) (PTA_ActionsToTerm(t))
ATerm PTA_ActionsToTerm(PTA_Actions arg);
#define PTA_makeActionFromTerm(t) (PTA_ActionFromTerm(t))
PTA_Action PTA_ActionFromTerm(ATerm t);
#define PTA_makeTermFromAction(t) (PTA_ActionToTerm(t))
ATerm PTA_ActionToTerm(PTA_Action arg);
#define PTA_makeChoicesFromTerm(t) (PTA_ChoicesFromTerm(t))
PTA_Choices PTA_ChoicesFromTerm(ATerm t);
#define PTA_makeTermFromChoices(t) (PTA_ChoicesToTerm(t))
ATerm PTA_ChoicesToTerm(PTA_Choices arg);
#define PTA_makeChoiceFromTerm(t) (PTA_ChoiceFromTerm(t))
PTA_Choice PTA_ChoiceFromTerm(ATerm t);
#define PTA_makeTermFromChoice(t) (PTA_ChoiceToTerm(t))
ATerm PTA_ChoiceToTerm(PTA_Choice arg);
#define PTA_makeSpecialAttrFromTerm(t) (PTA_SpecialAttrFromTerm(t))
PTA_SpecialAttr PTA_SpecialAttrFromTerm(ATerm t);
#define PTA_makeTermFromSpecialAttr(t) (PTA_SpecialAttrToTerm(t))
ATerm PTA_SpecialAttrToTerm(PTA_SpecialAttr arg);
#define PTA_makeLookAheadFromTerm(t) (PTA_LookAheadFromTerm(t))
PTA_LookAhead PTA_LookAheadFromTerm(ATerm t);
#define PTA_makeTermFromLookAhead(t) (PTA_LookAheadToTerm(t))
ATerm PTA_LookAheadToTerm(PTA_LookAhead arg);
#define PTA_makeCharClassFromTerm(t) (PTA_CharClassFromTerm(t))
PTA_CharClass PTA_CharClassFromTerm(ATerm t);
#define PTA_makeTermFromCharClass(t) (PTA_CharClassToTerm(t))
ATerm PTA_CharClassToTerm(PTA_CharClass arg);
#define PTA_makeLookAheadsFromTerm(t) (PTA_LookAheadsFromTerm(t))
PTA_LookAheads PTA_LookAheadsFromTerm(ATerm t);
#define PTA_makeTermFromLookAheads(t) (PTA_LookAheadsToTerm(t))
ATerm PTA_LookAheadsToTerm(PTA_LookAheads arg);
#define PTA_makePrioritiesFromTerm(t) (PTA_PrioritiesFromTerm(t))
PTA_Priorities PTA_PrioritiesFromTerm(ATerm t);
#define PTA_makeTermFromPriorities(t) (PTA_PrioritiesToTerm(t))
ATerm PTA_PrioritiesToTerm(PTA_Priorities arg);
#define PTA_makePriorityFromTerm(t) (PTA_PriorityFromTerm(t))
PTA_Priority PTA_PriorityFromTerm(ATerm t);
#define PTA_makeTermFromPriority(t) (PTA_PriorityToTerm(t))
ATerm PTA_PriorityToTerm(PTA_Priority arg);

/*}}}  */
/*{{{  constructors */

PTA_Version PTA_makeVersionDefault();
PTA_ParseTable PTA_makeParseTableParseTable(PTA_Version version, int initialState, PTA_Labels labels, PTA_States states, PTA_Priorities priorities);
PTA_Labels PTA_makeLabelsEmpty();
PTA_Labels PTA_makeLabelsList(PTA_Label head, PTA_Labels tail);
PTA_Label PTA_makeLabelDefault(PTA_Production production, int number);
PTA_States PTA_makeStatesEmpty();
PTA_States PTA_makeStatesList(PTA_State head, PTA_States tail);
PTA_State PTA_makeStateDefault(int number, PTA_Gotos gotos, PTA_Actions actions);
PTA_Gotos PTA_makeGotosEmpty();
PTA_Gotos PTA_makeGotosList(PTA_Goto head, PTA_Gotos tail);
PTA_Goto PTA_makeGotoDefault(PTA_CharRanges ranges, int stateNumber);
PTA_Actions PTA_makeActionsEmpty();
PTA_Actions PTA_makeActionsList(PTA_Action head, PTA_Actions tail);
PTA_Action PTA_makeActionDefault(PTA_CharRanges ranges, PTA_Choices choices);
PTA_Choices PTA_makeChoicesEmpty();
PTA_Choices PTA_makeChoicesList(PTA_Choice head, PTA_Choices tail);
PTA_Choice PTA_makeChoiceReduce(int length, int label, PTA_SpecialAttr specialAttr);
PTA_Choice PTA_makeChoiceLookaheadReduce(int length, int label, PTA_SpecialAttr specialAttr, PTA_LookAheads lookaheads);
PTA_Choice PTA_makeChoiceShift(int stateNumber);
PTA_Choice PTA_makeChoiceAccept();
PTA_SpecialAttr PTA_makeSpecialAttrNone();
PTA_SpecialAttr PTA_makeSpecialAttrReject();
PTA_SpecialAttr PTA_makeSpecialAttrPrefer();
PTA_SpecialAttr PTA_makeSpecialAttrAvoid();
PTA_LookAhead PTA_makeLookAheadDefault(PTA_CharClass charClass, PTA_LookAheads lookaheads);
PTA_CharClass PTA_makeCharClassDefault(PTA_CharRanges ranges);
PTA_LookAheads PTA_makeLookAheadsEmpty();
PTA_LookAheads PTA_makeLookAheadsList(PTA_LookAhead head, PTA_LookAheads tail);
PTA_Priorities PTA_makePrioritiesEmpty();
PTA_Priorities PTA_makePrioritiesList(PTA_Priority head, PTA_Priorities tail);
PTA_Priority PTA_makePriorityLeft(int label1, int label2);
PTA_Priority PTA_makePriorityRight(int label1, int label2);
PTA_Priority PTA_makePriorityNonAssoc(int label1, int label2);
PTA_Priority PTA_makePriorityGreater(int label1, int label2);

/*}}}  */
/*{{{  equality functions */

ATbool PTA_isEqualVersion(PTA_Version arg0, PTA_Version arg1);
ATbool PTA_isEqualParseTable(PTA_ParseTable arg0, PTA_ParseTable arg1);
ATbool PTA_isEqualLabels(PTA_Labels arg0, PTA_Labels arg1);
ATbool PTA_isEqualLabel(PTA_Label arg0, PTA_Label arg1);
ATbool PTA_isEqualStates(PTA_States arg0, PTA_States arg1);
ATbool PTA_isEqualState(PTA_State arg0, PTA_State arg1);
ATbool PTA_isEqualGotos(PTA_Gotos arg0, PTA_Gotos arg1);
ATbool PTA_isEqualGoto(PTA_Goto arg0, PTA_Goto arg1);
ATbool PTA_isEqualActions(PTA_Actions arg0, PTA_Actions arg1);
ATbool PTA_isEqualAction(PTA_Action arg0, PTA_Action arg1);
ATbool PTA_isEqualChoices(PTA_Choices arg0, PTA_Choices arg1);
ATbool PTA_isEqualChoice(PTA_Choice arg0, PTA_Choice arg1);
ATbool PTA_isEqualSpecialAttr(PTA_SpecialAttr arg0, PTA_SpecialAttr arg1);
ATbool PTA_isEqualLookAhead(PTA_LookAhead arg0, PTA_LookAhead arg1);
ATbool PTA_isEqualCharClass(PTA_CharClass arg0, PTA_CharClass arg1);
ATbool PTA_isEqualLookAheads(PTA_LookAheads arg0, PTA_LookAheads arg1);
ATbool PTA_isEqualPriorities(PTA_Priorities arg0, PTA_Priorities arg1);
ATbool PTA_isEqualPriority(PTA_Priority arg0, PTA_Priority arg1);

/*}}}  */
/*{{{  PTA_Version accessors */

ATbool PTA_isValidVersion(PTA_Version arg);
inline ATbool PTA_isVersionDefault(PTA_Version arg);

/*}}}  */
/*{{{  PTA_ParseTable accessors */

ATbool PTA_isValidParseTable(PTA_ParseTable arg);
inline ATbool PTA_isParseTableParseTable(PTA_ParseTable arg);
ATbool PTA_hasParseTableVersion(PTA_ParseTable arg);
PTA_Version PTA_getParseTableVersion(PTA_ParseTable arg);
PTA_ParseTable PTA_setParseTableVersion(PTA_ParseTable arg, PTA_Version version);
ATbool PTA_hasParseTableInitialState(PTA_ParseTable arg);
int PTA_getParseTableInitialState(PTA_ParseTable arg);
PTA_ParseTable PTA_setParseTableInitialState(PTA_ParseTable arg, int initialState);
ATbool PTA_hasParseTableLabels(PTA_ParseTable arg);
PTA_Labels PTA_getParseTableLabels(PTA_ParseTable arg);
PTA_ParseTable PTA_setParseTableLabels(PTA_ParseTable arg, PTA_Labels labels);
ATbool PTA_hasParseTableStates(PTA_ParseTable arg);
PTA_States PTA_getParseTableStates(PTA_ParseTable arg);
PTA_ParseTable PTA_setParseTableStates(PTA_ParseTable arg, PTA_States states);
ATbool PTA_hasParseTablePriorities(PTA_ParseTable arg);
PTA_Priorities PTA_getParseTablePriorities(PTA_ParseTable arg);
PTA_ParseTable PTA_setParseTablePriorities(PTA_ParseTable arg, PTA_Priorities priorities);

/*}}}  */
/*{{{  PTA_Labels accessors */

ATbool PTA_isValidLabels(PTA_Labels arg);
inline ATbool PTA_isLabelsEmpty(PTA_Labels arg);
inline ATbool PTA_isLabelsList(PTA_Labels arg);
ATbool PTA_hasLabelsHead(PTA_Labels arg);
PTA_Label PTA_getLabelsHead(PTA_Labels arg);
PTA_Labels PTA_setLabelsHead(PTA_Labels arg, PTA_Label head);
ATbool PTA_hasLabelsTail(PTA_Labels arg);
PTA_Labels PTA_getLabelsTail(PTA_Labels arg);
PTA_Labels PTA_setLabelsTail(PTA_Labels arg, PTA_Labels tail);

/*}}}  */
/*{{{  PTA_Label accessors */

ATbool PTA_isValidLabel(PTA_Label arg);
inline ATbool PTA_isLabelDefault(PTA_Label arg);
ATbool PTA_hasLabelProduction(PTA_Label arg);
PTA_Production PTA_getLabelProduction(PTA_Label arg);
PTA_Label PTA_setLabelProduction(PTA_Label arg, PTA_Production production);
ATbool PTA_hasLabelNumber(PTA_Label arg);
int PTA_getLabelNumber(PTA_Label arg);
PTA_Label PTA_setLabelNumber(PTA_Label arg, int number);

/*}}}  */
/*{{{  PTA_States accessors */

ATbool PTA_isValidStates(PTA_States arg);
inline ATbool PTA_isStatesEmpty(PTA_States arg);
inline ATbool PTA_isStatesList(PTA_States arg);
ATbool PTA_hasStatesHead(PTA_States arg);
PTA_State PTA_getStatesHead(PTA_States arg);
PTA_States PTA_setStatesHead(PTA_States arg, PTA_State head);
ATbool PTA_hasStatesTail(PTA_States arg);
PTA_States PTA_getStatesTail(PTA_States arg);
PTA_States PTA_setStatesTail(PTA_States arg, PTA_States tail);

/*}}}  */
/*{{{  PTA_State accessors */

ATbool PTA_isValidState(PTA_State arg);
inline ATbool PTA_isStateDefault(PTA_State arg);
ATbool PTA_hasStateNumber(PTA_State arg);
int PTA_getStateNumber(PTA_State arg);
PTA_State PTA_setStateNumber(PTA_State arg, int number);
ATbool PTA_hasStateGotos(PTA_State arg);
PTA_Gotos PTA_getStateGotos(PTA_State arg);
PTA_State PTA_setStateGotos(PTA_State arg, PTA_Gotos gotos);
ATbool PTA_hasStateActions(PTA_State arg);
PTA_Actions PTA_getStateActions(PTA_State arg);
PTA_State PTA_setStateActions(PTA_State arg, PTA_Actions actions);

/*}}}  */
/*{{{  PTA_Gotos accessors */

ATbool PTA_isValidGotos(PTA_Gotos arg);
inline ATbool PTA_isGotosEmpty(PTA_Gotos arg);
inline ATbool PTA_isGotosList(PTA_Gotos arg);
ATbool PTA_hasGotosHead(PTA_Gotos arg);
PTA_Goto PTA_getGotosHead(PTA_Gotos arg);
PTA_Gotos PTA_setGotosHead(PTA_Gotos arg, PTA_Goto head);
ATbool PTA_hasGotosTail(PTA_Gotos arg);
PTA_Gotos PTA_getGotosTail(PTA_Gotos arg);
PTA_Gotos PTA_setGotosTail(PTA_Gotos arg, PTA_Gotos tail);

/*}}}  */
/*{{{  PTA_Goto accessors */

ATbool PTA_isValidGoto(PTA_Goto arg);
inline ATbool PTA_isGotoDefault(PTA_Goto arg);
ATbool PTA_hasGotoRanges(PTA_Goto arg);
PTA_CharRanges PTA_getGotoRanges(PTA_Goto arg);
PTA_Goto PTA_setGotoRanges(PTA_Goto arg, PTA_CharRanges ranges);
ATbool PTA_hasGotoStateNumber(PTA_Goto arg);
int PTA_getGotoStateNumber(PTA_Goto arg);
PTA_Goto PTA_setGotoStateNumber(PTA_Goto arg, int stateNumber);

/*}}}  */
/*{{{  PTA_Actions accessors */

ATbool PTA_isValidActions(PTA_Actions arg);
inline ATbool PTA_isActionsEmpty(PTA_Actions arg);
inline ATbool PTA_isActionsList(PTA_Actions arg);
ATbool PTA_hasActionsHead(PTA_Actions arg);
PTA_Action PTA_getActionsHead(PTA_Actions arg);
PTA_Actions PTA_setActionsHead(PTA_Actions arg, PTA_Action head);
ATbool PTA_hasActionsTail(PTA_Actions arg);
PTA_Actions PTA_getActionsTail(PTA_Actions arg);
PTA_Actions PTA_setActionsTail(PTA_Actions arg, PTA_Actions tail);

/*}}}  */
/*{{{  PTA_Action accessors */

ATbool PTA_isValidAction(PTA_Action arg);
inline ATbool PTA_isActionDefault(PTA_Action arg);
ATbool PTA_hasActionRanges(PTA_Action arg);
PTA_CharRanges PTA_getActionRanges(PTA_Action arg);
PTA_Action PTA_setActionRanges(PTA_Action arg, PTA_CharRanges ranges);
ATbool PTA_hasActionChoices(PTA_Action arg);
PTA_Choices PTA_getActionChoices(PTA_Action arg);
PTA_Action PTA_setActionChoices(PTA_Action arg, PTA_Choices choices);

/*}}}  */
/*{{{  PTA_Choices accessors */

ATbool PTA_isValidChoices(PTA_Choices arg);
inline ATbool PTA_isChoicesEmpty(PTA_Choices arg);
inline ATbool PTA_isChoicesList(PTA_Choices arg);
ATbool PTA_hasChoicesHead(PTA_Choices arg);
PTA_Choice PTA_getChoicesHead(PTA_Choices arg);
PTA_Choices PTA_setChoicesHead(PTA_Choices arg, PTA_Choice head);
ATbool PTA_hasChoicesTail(PTA_Choices arg);
PTA_Choices PTA_getChoicesTail(PTA_Choices arg);
PTA_Choices PTA_setChoicesTail(PTA_Choices arg, PTA_Choices tail);

/*}}}  */
/*{{{  PTA_Choice accessors */

ATbool PTA_isValidChoice(PTA_Choice arg);
inline ATbool PTA_isChoiceReduce(PTA_Choice arg);
inline ATbool PTA_isChoiceLookaheadReduce(PTA_Choice arg);
inline ATbool PTA_isChoiceShift(PTA_Choice arg);
inline ATbool PTA_isChoiceAccept(PTA_Choice arg);
ATbool PTA_hasChoiceLength(PTA_Choice arg);
int PTA_getChoiceLength(PTA_Choice arg);
PTA_Choice PTA_setChoiceLength(PTA_Choice arg, int length);
ATbool PTA_hasChoiceLabel(PTA_Choice arg);
int PTA_getChoiceLabel(PTA_Choice arg);
PTA_Choice PTA_setChoiceLabel(PTA_Choice arg, int label);
ATbool PTA_hasChoiceSpecialAttr(PTA_Choice arg);
PTA_SpecialAttr PTA_getChoiceSpecialAttr(PTA_Choice arg);
PTA_Choice PTA_setChoiceSpecialAttr(PTA_Choice arg, PTA_SpecialAttr specialAttr);
ATbool PTA_hasChoiceLookaheads(PTA_Choice arg);
PTA_LookAheads PTA_getChoiceLookaheads(PTA_Choice arg);
PTA_Choice PTA_setChoiceLookaheads(PTA_Choice arg, PTA_LookAheads lookaheads);
ATbool PTA_hasChoiceStateNumber(PTA_Choice arg);
int PTA_getChoiceStateNumber(PTA_Choice arg);
PTA_Choice PTA_setChoiceStateNumber(PTA_Choice arg, int stateNumber);

/*}}}  */
/*{{{  PTA_SpecialAttr accessors */

ATbool PTA_isValidSpecialAttr(PTA_SpecialAttr arg);
inline ATbool PTA_isSpecialAttrNone(PTA_SpecialAttr arg);
inline ATbool PTA_isSpecialAttrReject(PTA_SpecialAttr arg);
inline ATbool PTA_isSpecialAttrPrefer(PTA_SpecialAttr arg);
inline ATbool PTA_isSpecialAttrAvoid(PTA_SpecialAttr arg);

/*}}}  */
/*{{{  PTA_LookAhead accessors */

ATbool PTA_isValidLookAhead(PTA_LookAhead arg);
inline ATbool PTA_isLookAheadDefault(PTA_LookAhead arg);
ATbool PTA_hasLookAheadCharClass(PTA_LookAhead arg);
PTA_CharClass PTA_getLookAheadCharClass(PTA_LookAhead arg);
PTA_LookAhead PTA_setLookAheadCharClass(PTA_LookAhead arg, PTA_CharClass charClass);
ATbool PTA_hasLookAheadLookaheads(PTA_LookAhead arg);
PTA_LookAheads PTA_getLookAheadLookaheads(PTA_LookAhead arg);
PTA_LookAhead PTA_setLookAheadLookaheads(PTA_LookAhead arg, PTA_LookAheads lookaheads);

/*}}}  */
/*{{{  PTA_CharClass accessors */

ATbool PTA_isValidCharClass(PTA_CharClass arg);
inline ATbool PTA_isCharClassDefault(PTA_CharClass arg);
ATbool PTA_hasCharClassRanges(PTA_CharClass arg);
PTA_CharRanges PTA_getCharClassRanges(PTA_CharClass arg);
PTA_CharClass PTA_setCharClassRanges(PTA_CharClass arg, PTA_CharRanges ranges);

/*}}}  */
/*{{{  PTA_LookAheads accessors */

ATbool PTA_isValidLookAheads(PTA_LookAheads arg);
inline ATbool PTA_isLookAheadsEmpty(PTA_LookAheads arg);
inline ATbool PTA_isLookAheadsList(PTA_LookAheads arg);
ATbool PTA_hasLookAheadsHead(PTA_LookAheads arg);
PTA_LookAhead PTA_getLookAheadsHead(PTA_LookAheads arg);
PTA_LookAheads PTA_setLookAheadsHead(PTA_LookAheads arg, PTA_LookAhead head);
ATbool PTA_hasLookAheadsTail(PTA_LookAheads arg);
PTA_LookAheads PTA_getLookAheadsTail(PTA_LookAheads arg);
PTA_LookAheads PTA_setLookAheadsTail(PTA_LookAheads arg, PTA_LookAheads tail);

/*}}}  */
/*{{{  PTA_Priorities accessors */

ATbool PTA_isValidPriorities(PTA_Priorities arg);
inline ATbool PTA_isPrioritiesEmpty(PTA_Priorities arg);
inline ATbool PTA_isPrioritiesList(PTA_Priorities arg);
ATbool PTA_hasPrioritiesHead(PTA_Priorities arg);
PTA_Priority PTA_getPrioritiesHead(PTA_Priorities arg);
PTA_Priorities PTA_setPrioritiesHead(PTA_Priorities arg, PTA_Priority head);
ATbool PTA_hasPrioritiesTail(PTA_Priorities arg);
PTA_Priorities PTA_getPrioritiesTail(PTA_Priorities arg);
PTA_Priorities PTA_setPrioritiesTail(PTA_Priorities arg, PTA_Priorities tail);

/*}}}  */
/*{{{  PTA_Priority accessors */

ATbool PTA_isValidPriority(PTA_Priority arg);
inline ATbool PTA_isPriorityLeft(PTA_Priority arg);
inline ATbool PTA_isPriorityRight(PTA_Priority arg);
inline ATbool PTA_isPriorityNonAssoc(PTA_Priority arg);
inline ATbool PTA_isPriorityGreater(PTA_Priority arg);
ATbool PTA_hasPriorityLabel1(PTA_Priority arg);
int PTA_getPriorityLabel1(PTA_Priority arg);
PTA_Priority PTA_setPriorityLabel1(PTA_Priority arg, int label1);
ATbool PTA_hasPriorityLabel2(PTA_Priority arg);
int PTA_getPriorityLabel2(PTA_Priority arg);
PTA_Priority PTA_setPriorityLabel2(PTA_Priority arg, int label2);

/*}}}  */
/*{{{  sort visitors */

PTA_Version PTA_visitVersion(PTA_Version arg);
PTA_ParseTable PTA_visitParseTable(PTA_ParseTable arg, PTA_Version (*acceptVersion)(PTA_Version), int (*acceptInitialState)(int), PTA_Labels (*acceptLabels)(PTA_Labels), PTA_States (*acceptStates)(PTA_States), PTA_Priorities (*acceptPriorities)(PTA_Priorities));
PTA_Labels PTA_visitLabels(PTA_Labels arg, PTA_Label (*acceptHead)(PTA_Label));
PTA_Label PTA_visitLabel(PTA_Label arg, PTA_Production (*acceptProduction)(PTA_Production), int (*acceptNumber)(int));
PTA_States PTA_visitStates(PTA_States arg, PTA_State (*acceptHead)(PTA_State));
PTA_State PTA_visitState(PTA_State arg, int (*acceptNumber)(int), PTA_Gotos (*acceptGotos)(PTA_Gotos), PTA_Actions (*acceptActions)(PTA_Actions));
PTA_Gotos PTA_visitGotos(PTA_Gotos arg, PTA_Goto (*acceptHead)(PTA_Goto));
PTA_Goto PTA_visitGoto(PTA_Goto arg, PTA_CharRanges (*acceptRanges)(PTA_CharRanges), int (*acceptStateNumber)(int));
PTA_Actions PTA_visitActions(PTA_Actions arg, PTA_Action (*acceptHead)(PTA_Action));
PTA_Action PTA_visitAction(PTA_Action arg, PTA_CharRanges (*acceptRanges)(PTA_CharRanges), PTA_Choices (*acceptChoices)(PTA_Choices));
PTA_Choices PTA_visitChoices(PTA_Choices arg, PTA_Choice (*acceptHead)(PTA_Choice));
PTA_Choice PTA_visitChoice(PTA_Choice arg, int (*acceptLength)(int), int (*acceptLabel)(int), PTA_SpecialAttr (*acceptSpecialAttr)(PTA_SpecialAttr), PTA_LookAheads (*acceptLookaheads)(PTA_LookAheads), int (*acceptStateNumber)(int));
PTA_SpecialAttr PTA_visitSpecialAttr(PTA_SpecialAttr arg);
PTA_LookAhead PTA_visitLookAhead(PTA_LookAhead arg, PTA_CharClass (*acceptCharClass)(PTA_CharClass), PTA_LookAheads (*acceptLookaheads)(PTA_LookAheads));
PTA_CharClass PTA_visitCharClass(PTA_CharClass arg, PTA_CharRanges (*acceptRanges)(PTA_CharRanges));
PTA_LookAheads PTA_visitLookAheads(PTA_LookAheads arg, PTA_LookAhead (*acceptHead)(PTA_LookAhead));
PTA_Priorities PTA_visitPriorities(PTA_Priorities arg, PTA_Priority (*acceptHead)(PTA_Priority));
PTA_Priority PTA_visitPriority(PTA_Priority arg, int (*acceptLabel1)(int), int (*acceptLabel2)(int));

/*}}}  */

#endif /* _PTABLE_H */
