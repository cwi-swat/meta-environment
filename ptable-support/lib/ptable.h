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

typedef struct _PTA_ParseTable *PTA_ParseTable;
typedef struct _PTA_Labels *PTA_Labels;
typedef struct _PTA_Label *PTA_Label;
typedef struct _PTA_States *PTA_States;
typedef struct _PTA_State *PTA_State;
typedef struct _PTA_Gotos *PTA_Gotos;
typedef struct _PTA_Goto *PTA_Goto;
typedef struct _PTA_Actions *PTA_Actions;
typedef struct _PTA_Action *PTA_Action;
typedef struct _PTA_Alternatives *PTA_Alternatives;
typedef struct _PTA_Alternative *PTA_Alternative;
typedef struct _PTA_SpecialAttr *PTA_SpecialAttr;
typedef struct _PTA_Priorities *PTA_Priorities;
typedef struct _PTA_Priority *PTA_Priority;

/*}}}  */

void PTA_initPtableApi(void);

/*{{{  term conversion functions */

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
#define PTA_makeAlternativesFromTerm(t) (PTA_AlternativesFromTerm(t))
PTA_Alternatives PTA_AlternativesFromTerm(ATerm t);
#define PTA_makeTermFromAlternatives(t) (PTA_AlternativesToTerm(t))
ATerm PTA_AlternativesToTerm(PTA_Alternatives arg);
#define PTA_makeAlternativeFromTerm(t) (PTA_AlternativeFromTerm(t))
PTA_Alternative PTA_AlternativeFromTerm(ATerm t);
#define PTA_makeTermFromAlternative(t) (PTA_AlternativeToTerm(t))
ATerm PTA_AlternativeToTerm(PTA_Alternative arg);
#define PTA_makeSpecialAttrFromTerm(t) (PTA_SpecialAttrFromTerm(t))
PTA_SpecialAttr PTA_SpecialAttrFromTerm(ATerm t);
#define PTA_makeTermFromSpecialAttr(t) (PTA_SpecialAttrToTerm(t))
ATerm PTA_SpecialAttrToTerm(PTA_SpecialAttr arg);
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

PTA_ParseTable PTA_makeParseTableParseTable(ATerm version, ATerm initialState, PTA_Labels labels, PTA_States states, PTA_Priorities priorities);
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
PTA_Action PTA_makeActionDefault(PTA_CharRanges ranges, PTA_Alternatives alternatives);
PTA_Alternatives PTA_makeAlternativesEmpty();
PTA_Alternatives PTA_makeAlternativesList(PTA_Alternative head, PTA_Alternatives tail);
PTA_Alternative PTA_makeAlternativeReduce(int length, int label, PTA_SpecialAttr specialAttr);
PTA_Alternative PTA_makeAlternativeShift(int stateNumner);
PTA_Alternative PTA_makeAlternativeAccept();
PTA_SpecialAttr PTA_makeSpecialAttrNone();
PTA_SpecialAttr PTA_makeSpecialAttrReject();
PTA_SpecialAttr PTA_makeSpecialAttrPrefer();
PTA_SpecialAttr PTA_makeSpecialAttrAvoid();
PTA_Priorities PTA_makePrioritiesEmpty();
PTA_Priorities PTA_makePrioritiesList(PTA_Priority head, PTA_Priorities tail);
PTA_Priority PTA_makePriorityLeft(int label1, int label2);
PTA_Priority PTA_makePriorityRight(int label1, int label2);
PTA_Priority PTA_makePriorityGreater(int label1, int label2);

/*}}}  */
/*{{{  equality functions */

ATbool PTA_isEqualParseTable(PTA_ParseTable arg0, PTA_ParseTable arg1);
ATbool PTA_isEqualLabels(PTA_Labels arg0, PTA_Labels arg1);
ATbool PTA_isEqualLabel(PTA_Label arg0, PTA_Label arg1);
ATbool PTA_isEqualStates(PTA_States arg0, PTA_States arg1);
ATbool PTA_isEqualState(PTA_State arg0, PTA_State arg1);
ATbool PTA_isEqualGotos(PTA_Gotos arg0, PTA_Gotos arg1);
ATbool PTA_isEqualGoto(PTA_Goto arg0, PTA_Goto arg1);
ATbool PTA_isEqualActions(PTA_Actions arg0, PTA_Actions arg1);
ATbool PTA_isEqualAction(PTA_Action arg0, PTA_Action arg1);
ATbool PTA_isEqualAlternatives(PTA_Alternatives arg0, PTA_Alternatives arg1);
ATbool PTA_isEqualAlternative(PTA_Alternative arg0, PTA_Alternative arg1);
ATbool PTA_isEqualSpecialAttr(PTA_SpecialAttr arg0, PTA_SpecialAttr arg1);
ATbool PTA_isEqualPriorities(PTA_Priorities arg0, PTA_Priorities arg1);
ATbool PTA_isEqualPriority(PTA_Priority arg0, PTA_Priority arg1);

/*}}}  */
/*{{{  PTA_ParseTable accessors */

ATbool PTA_isValidParseTable(PTA_ParseTable arg);
inline ATbool PTA_isParseTableParseTable(PTA_ParseTable arg);
ATbool PTA_hasParseTableVersion(PTA_ParseTable arg);
ATerm PTA_getParseTableVersion(PTA_ParseTable arg);
PTA_ParseTable PTA_setParseTableVersion(PTA_ParseTable arg, ATerm version);
ATbool PTA_hasParseTableInitialState(PTA_ParseTable arg);
ATerm PTA_getParseTableInitialState(PTA_ParseTable arg);
PTA_ParseTable PTA_setParseTableInitialState(PTA_ParseTable arg, ATerm initialState);
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
ATbool PTA_hasActionAlternatives(PTA_Action arg);
PTA_Alternatives PTA_getActionAlternatives(PTA_Action arg);
PTA_Action PTA_setActionAlternatives(PTA_Action arg, PTA_Alternatives alternatives);

/*}}}  */
/*{{{  PTA_Alternatives accessors */

ATbool PTA_isValidAlternatives(PTA_Alternatives arg);
inline ATbool PTA_isAlternativesEmpty(PTA_Alternatives arg);
inline ATbool PTA_isAlternativesList(PTA_Alternatives arg);
ATbool PTA_hasAlternativesHead(PTA_Alternatives arg);
PTA_Alternative PTA_getAlternativesHead(PTA_Alternatives arg);
PTA_Alternatives PTA_setAlternativesHead(PTA_Alternatives arg, PTA_Alternative head);
ATbool PTA_hasAlternativesTail(PTA_Alternatives arg);
PTA_Alternatives PTA_getAlternativesTail(PTA_Alternatives arg);
PTA_Alternatives PTA_setAlternativesTail(PTA_Alternatives arg, PTA_Alternatives tail);

/*}}}  */
/*{{{  PTA_Alternative accessors */

ATbool PTA_isValidAlternative(PTA_Alternative arg);
inline ATbool PTA_isAlternativeReduce(PTA_Alternative arg);
inline ATbool PTA_isAlternativeShift(PTA_Alternative arg);
inline ATbool PTA_isAlternativeAccept(PTA_Alternative arg);
ATbool PTA_hasAlternativeLength(PTA_Alternative arg);
int PTA_getAlternativeLength(PTA_Alternative arg);
PTA_Alternative PTA_setAlternativeLength(PTA_Alternative arg, int length);
ATbool PTA_hasAlternativeLabel(PTA_Alternative arg);
int PTA_getAlternativeLabel(PTA_Alternative arg);
PTA_Alternative PTA_setAlternativeLabel(PTA_Alternative arg, int label);
ATbool PTA_hasAlternativeSpecialAttr(PTA_Alternative arg);
PTA_SpecialAttr PTA_getAlternativeSpecialAttr(PTA_Alternative arg);
PTA_Alternative PTA_setAlternativeSpecialAttr(PTA_Alternative arg, PTA_SpecialAttr specialAttr);
ATbool PTA_hasAlternativeStateNumner(PTA_Alternative arg);
int PTA_getAlternativeStateNumner(PTA_Alternative arg);
PTA_Alternative PTA_setAlternativeStateNumner(PTA_Alternative arg, int stateNumner);

/*}}}  */
/*{{{  PTA_SpecialAttr accessors */

ATbool PTA_isValidSpecialAttr(PTA_SpecialAttr arg);
inline ATbool PTA_isSpecialAttrNone(PTA_SpecialAttr arg);
inline ATbool PTA_isSpecialAttrReject(PTA_SpecialAttr arg);
inline ATbool PTA_isSpecialAttrPrefer(PTA_SpecialAttr arg);
inline ATbool PTA_isSpecialAttrAvoid(PTA_SpecialAttr arg);

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
inline ATbool PTA_isPriorityGreater(PTA_Priority arg);
ATbool PTA_hasPriorityLabel1(PTA_Priority arg);
int PTA_getPriorityLabel1(PTA_Priority arg);
PTA_Priority PTA_setPriorityLabel1(PTA_Priority arg, int label1);
ATbool PTA_hasPriorityLabel2(PTA_Priority arg);
int PTA_getPriorityLabel2(PTA_Priority arg);
PTA_Priority PTA_setPriorityLabel2(PTA_Priority arg, int label2);

/*}}}  */
/*{{{  sort visitors */

PTA_ParseTable PTA_visitParseTable(PTA_ParseTable arg, ATerm (*acceptVersion)(ATerm), ATerm (*acceptInitialState)(ATerm), PTA_Labels (*acceptLabels)(PTA_Labels), PTA_States (*acceptStates)(PTA_States), PTA_Priorities (*acceptPriorities)(PTA_Priorities));
PTA_Labels PTA_visitLabels(PTA_Labels arg, PTA_Label (*acceptHead)(PTA_Label));
PTA_Label PTA_visitLabel(PTA_Label arg, PTA_Production (*acceptProduction)(PTA_Production), int (*acceptNumber)(int));
PTA_States PTA_visitStates(PTA_States arg, PTA_State (*acceptHead)(PTA_State));
PTA_State PTA_visitState(PTA_State arg, int (*acceptNumber)(int), PTA_Gotos (*acceptGotos)(PTA_Gotos), PTA_Actions (*acceptActions)(PTA_Actions));
PTA_Gotos PTA_visitGotos(PTA_Gotos arg, PTA_Goto (*acceptHead)(PTA_Goto));
PTA_Goto PTA_visitGoto(PTA_Goto arg, PTA_CharRanges (*acceptRanges)(PTA_CharRanges), int (*acceptStateNumber)(int));
PTA_Actions PTA_visitActions(PTA_Actions arg, PTA_Action (*acceptHead)(PTA_Action));
PTA_Action PTA_visitAction(PTA_Action arg, PTA_CharRanges (*acceptRanges)(PTA_CharRanges), PTA_Alternatives (*acceptAlternatives)(PTA_Alternatives));
PTA_Alternatives PTA_visitAlternatives(PTA_Alternatives arg, PTA_Alternative (*acceptHead)(PTA_Alternative));
PTA_Alternative PTA_visitAlternative(PTA_Alternative arg, int (*acceptLength)(int), int (*acceptLabel)(int), PTA_SpecialAttr (*acceptSpecialAttr)(PTA_SpecialAttr), int (*acceptStateNumner)(int));
PTA_SpecialAttr PTA_visitSpecialAttr(PTA_SpecialAttr arg);
PTA_Priorities PTA_visitPriorities(PTA_Priorities arg, PTA_Priority (*acceptHead)(PTA_Priority));
PTA_Priority PTA_visitPriority(PTA_Priority arg, int (*acceptLabel1)(int), int (*acceptLabel2)(int));

/*}}}  */

#endif /* _PTABLE_H */
