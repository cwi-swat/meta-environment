#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ptable.h"

/*{{{  typedefs */

typedef struct ATerm _PTA_ParseTable;
typedef struct ATerm _PTA_Labels;
typedef struct ATerm _PTA_Label;
typedef struct ATerm _PTA_States;
typedef struct ATerm _PTA_State;
typedef struct ATerm _PTA_Gotos;
typedef struct ATerm _PTA_Goto;
typedef struct ATerm _PTA_Actions;
typedef struct ATerm _PTA_Action;
typedef struct ATerm _PTA_Alternatives;
typedef struct ATerm _PTA_Alternative;
typedef struct ATerm _PTA_SpecialAttr;
typedef struct ATerm _PTA_Priorities;
typedef struct ATerm _PTA_Priority;

/*}}}  */

/*{{{  void PTA_initPtableApi(void) */

void PTA_initPtableApi(void)
{
  init_ptable_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  PTA_ParseTable PTA_ParseTableFromTerm(ATerm t) */

PTA_ParseTable PTA_ParseTableFromTerm(ATerm t)
{
  return (PTA_ParseTable)t;
}

/*}}}  */
/*{{{  ATerm PTA_ParseTableToTerm(PTA_ParseTable arg) */

ATerm PTA_ParseTableToTerm(PTA_ParseTable arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_Labels PTA_LabelsFromTerm(ATerm t) */

PTA_Labels PTA_LabelsFromTerm(ATerm t)
{
  return (PTA_Labels)t;
}

/*}}}  */
/*{{{  ATerm PTA_LabelsToTerm(PTA_Labels arg) */

ATerm PTA_LabelsToTerm(PTA_Labels arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_Label PTA_LabelFromTerm(ATerm t) */

PTA_Label PTA_LabelFromTerm(ATerm t)
{
  return (PTA_Label)t;
}

/*}}}  */
/*{{{  ATerm PTA_LabelToTerm(PTA_Label arg) */

ATerm PTA_LabelToTerm(PTA_Label arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_States PTA_StatesFromTerm(ATerm t) */

PTA_States PTA_StatesFromTerm(ATerm t)
{
  return (PTA_States)t;
}

/*}}}  */
/*{{{  ATerm PTA_StatesToTerm(PTA_States arg) */

ATerm PTA_StatesToTerm(PTA_States arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_State PTA_StateFromTerm(ATerm t) */

PTA_State PTA_StateFromTerm(ATerm t)
{
  return (PTA_State)t;
}

/*}}}  */
/*{{{  ATerm PTA_StateToTerm(PTA_State arg) */

ATerm PTA_StateToTerm(PTA_State arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_Gotos PTA_GotosFromTerm(ATerm t) */

PTA_Gotos PTA_GotosFromTerm(ATerm t)
{
  return (PTA_Gotos)t;
}

/*}}}  */
/*{{{  ATerm PTA_GotosToTerm(PTA_Gotos arg) */

ATerm PTA_GotosToTerm(PTA_Gotos arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_Goto PTA_GotoFromTerm(ATerm t) */

PTA_Goto PTA_GotoFromTerm(ATerm t)
{
  return (PTA_Goto)t;
}

/*}}}  */
/*{{{  ATerm PTA_GotoToTerm(PTA_Goto arg) */

ATerm PTA_GotoToTerm(PTA_Goto arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_Actions PTA_ActionsFromTerm(ATerm t) */

PTA_Actions PTA_ActionsFromTerm(ATerm t)
{
  return (PTA_Actions)t;
}

/*}}}  */
/*{{{  ATerm PTA_ActionsToTerm(PTA_Actions arg) */

ATerm PTA_ActionsToTerm(PTA_Actions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_Action PTA_ActionFromTerm(ATerm t) */

PTA_Action PTA_ActionFromTerm(ATerm t)
{
  return (PTA_Action)t;
}

/*}}}  */
/*{{{  ATerm PTA_ActionToTerm(PTA_Action arg) */

ATerm PTA_ActionToTerm(PTA_Action arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_Alternatives PTA_AlternativesFromTerm(ATerm t) */

PTA_Alternatives PTA_AlternativesFromTerm(ATerm t)
{
  return (PTA_Alternatives)t;
}

/*}}}  */
/*{{{  ATerm PTA_AlternativesToTerm(PTA_Alternatives arg) */

ATerm PTA_AlternativesToTerm(PTA_Alternatives arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_Alternative PTA_AlternativeFromTerm(ATerm t) */

PTA_Alternative PTA_AlternativeFromTerm(ATerm t)
{
  return (PTA_Alternative)t;
}

/*}}}  */
/*{{{  ATerm PTA_AlternativeToTerm(PTA_Alternative arg) */

ATerm PTA_AlternativeToTerm(PTA_Alternative arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_SpecialAttr PTA_SpecialAttrFromTerm(ATerm t) */

PTA_SpecialAttr PTA_SpecialAttrFromTerm(ATerm t)
{
  return (PTA_SpecialAttr)t;
}

/*}}}  */
/*{{{  ATerm PTA_SpecialAttrToTerm(PTA_SpecialAttr arg) */

ATerm PTA_SpecialAttrToTerm(PTA_SpecialAttr arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_Priorities PTA_PrioritiesFromTerm(ATerm t) */

PTA_Priorities PTA_PrioritiesFromTerm(ATerm t)
{
  return (PTA_Priorities)t;
}

/*}}}  */
/*{{{  ATerm PTA_PrioritiesToTerm(PTA_Priorities arg) */

ATerm PTA_PrioritiesToTerm(PTA_Priorities arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_Priority PTA_PriorityFromTerm(ATerm t) */

PTA_Priority PTA_PriorityFromTerm(ATerm t)
{
  return (PTA_Priority)t;
}

/*}}}  */
/*{{{  ATerm PTA_PriorityToTerm(PTA_Priority arg) */

ATerm PTA_PriorityToTerm(PTA_Priority arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  PTA_ParseTable PTA_makeParseTableParseTable(ATerm version, ATerm initialState, PTA_Labels labels, PTA_States states, PTA_Priorities priorities) */

PTA_ParseTable PTA_makeParseTableParseTable(ATerm version, ATerm initialState, PTA_Labels labels, PTA_States states, PTA_Priorities priorities)
{
  return (PTA_ParseTable)(ATerm)ATmakeAppl5(PTA_afun0, (ATerm)version, (ATerm)initialState, (ATerm)labels, (ATerm)ATmakeAppl1(PTA_afun1, (ATerm)states), (ATerm)ATmakeAppl1(PTA_afun2, (ATerm)priorities));
}

/*}}}  */
/*{{{  PTA_Labels PTA_makeLabelsEmpty() */

PTA_Labels PTA_makeLabelsEmpty()
{
  return (PTA_Labels)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTA_Labels PTA_makeLabelsList(PTA_Label head, PTA_Labels tail) */

PTA_Labels PTA_makeLabelsList(PTA_Label head, PTA_Labels tail)
{
  return (PTA_Labels)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  PTA_Label PTA_makeLabelDefault(PTA_Production production, int number) */

PTA_Label PTA_makeLabelDefault(PTA_Production production, int number)
{
  return (PTA_Label)(ATerm)ATmakeAppl2(PTA_afun3, (ATerm)production, (ATerm)ATmakeInt(number));
}

/*}}}  */
/*{{{  PTA_States PTA_makeStatesEmpty() */

PTA_States PTA_makeStatesEmpty()
{
  return (PTA_States)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTA_States PTA_makeStatesList(PTA_State head, PTA_States tail) */

PTA_States PTA_makeStatesList(PTA_State head, PTA_States tail)
{
  return (PTA_States)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  PTA_State PTA_makeStateDefault(int number, PTA_Gotos gotos, PTA_Actions actions) */

PTA_State PTA_makeStateDefault(int number, PTA_Gotos gotos, PTA_Actions actions)
{
  return (PTA_State)(ATerm)ATmakeAppl3(PTA_afun4, (ATerm)ATmakeInt(number), (ATerm)gotos, (ATerm)actions);
}

/*}}}  */
/*{{{  PTA_Gotos PTA_makeGotosEmpty() */

PTA_Gotos PTA_makeGotosEmpty()
{
  return (PTA_Gotos)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTA_Gotos PTA_makeGotosList(PTA_Goto head, PTA_Gotos tail) */

PTA_Gotos PTA_makeGotosList(PTA_Goto head, PTA_Gotos tail)
{
  return (PTA_Gotos)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  PTA_Goto PTA_makeGotoDefault(PTA_CharRanges ranges, int stateNumber) */

PTA_Goto PTA_makeGotoDefault(PTA_CharRanges ranges, int stateNumber)
{
  return (PTA_Goto)(ATerm)ATmakeAppl2(PTA_afun5, (ATerm)ranges, (ATerm)ATmakeInt(stateNumber));
}

/*}}}  */
/*{{{  PTA_Actions PTA_makeActionsEmpty() */

PTA_Actions PTA_makeActionsEmpty()
{
  return (PTA_Actions)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTA_Actions PTA_makeActionsList(PTA_Action head, PTA_Actions tail) */

PTA_Actions PTA_makeActionsList(PTA_Action head, PTA_Actions tail)
{
  return (PTA_Actions)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  PTA_Action PTA_makeActionDefault(PTA_CharRanges ranges, PTA_Alternatives alternatives) */

PTA_Action PTA_makeActionDefault(PTA_CharRanges ranges, PTA_Alternatives alternatives)
{
  return (PTA_Action)(ATerm)ATmakeAppl2(PTA_afun6, (ATerm)ranges, (ATerm)alternatives);
}

/*}}}  */
/*{{{  PTA_Alternatives PTA_makeAlternativesEmpty() */

PTA_Alternatives PTA_makeAlternativesEmpty()
{
  return (PTA_Alternatives)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTA_Alternatives PTA_makeAlternativesList(PTA_Alternative head, PTA_Alternatives tail) */

PTA_Alternatives PTA_makeAlternativesList(PTA_Alternative head, PTA_Alternatives tail)
{
  return (PTA_Alternatives)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  PTA_Alternative PTA_makeAlternativeReduce(int length, int label, PTA_SpecialAttr specialAttr) */

PTA_Alternative PTA_makeAlternativeReduce(int length, int label, PTA_SpecialAttr specialAttr)
{
  return (PTA_Alternative)(ATerm)ATmakeAppl3(PTA_afun7, (ATerm)ATmakeInt(length), (ATerm)ATmakeInt(label), (ATerm)specialAttr);
}

/*}}}  */
/*{{{  PTA_Alternative PTA_makeAlternativeShift(int stateNumner) */

PTA_Alternative PTA_makeAlternativeShift(int stateNumner)
{
  return (PTA_Alternative)(ATerm)ATmakeAppl1(PTA_afun8, (ATerm)ATmakeInt(stateNumner));
}

/*}}}  */
/*{{{  PTA_Alternative PTA_makeAlternativeAccept() */

PTA_Alternative PTA_makeAlternativeAccept()
{
  return (PTA_Alternative)(ATerm)ATmakeAppl0(PTA_afun9);
}

/*}}}  */
/*{{{  PTA_SpecialAttr PTA_makeSpecialAttrNone() */

PTA_SpecialAttr PTA_makeSpecialAttrNone()
{
  return (PTA_SpecialAttr)(ATerm)ATmakeInt(0);
}

/*}}}  */
/*{{{  PTA_SpecialAttr PTA_makeSpecialAttrReject() */

PTA_SpecialAttr PTA_makeSpecialAttrReject()
{
  return (PTA_SpecialAttr)(ATerm)ATmakeInt(1);
}

/*}}}  */
/*{{{  PTA_SpecialAttr PTA_makeSpecialAttrPrefer() */

PTA_SpecialAttr PTA_makeSpecialAttrPrefer()
{
  return (PTA_SpecialAttr)(ATerm)ATmakeInt(2);
}

/*}}}  */
/*{{{  PTA_SpecialAttr PTA_makeSpecialAttrAvoid() */

PTA_SpecialAttr PTA_makeSpecialAttrAvoid()
{
  return (PTA_SpecialAttr)(ATerm)ATmakeInt(4);
}

/*}}}  */
/*{{{  PTA_Priorities PTA_makePrioritiesEmpty() */

PTA_Priorities PTA_makePrioritiesEmpty()
{
  return (PTA_Priorities)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTA_Priorities PTA_makePrioritiesList(PTA_Priority head, PTA_Priorities tail) */

PTA_Priorities PTA_makePrioritiesList(PTA_Priority head, PTA_Priorities tail)
{
  return (PTA_Priorities)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  PTA_Priority PTA_makePriorityLeft(int label1, int label2) */

PTA_Priority PTA_makePriorityLeft(int label1, int label2)
{
  return (PTA_Priority)(ATerm)ATmakeAppl2(PTA_afun10, (ATerm)ATmakeInt(label1), (ATerm)ATmakeInt(label2));
}

/*}}}  */
/*{{{  PTA_Priority PTA_makePriorityRight(int label1, int label2) */

PTA_Priority PTA_makePriorityRight(int label1, int label2)
{
  return (PTA_Priority)(ATerm)ATmakeAppl2(PTA_afun11, (ATerm)ATmakeInt(label1), (ATerm)ATmakeInt(label2));
}

/*}}}  */
/*{{{  PTA_Priority PTA_makePriorityGreater(int label1, int label2) */

PTA_Priority PTA_makePriorityGreater(int label1, int label2)
{
  return (PTA_Priority)(ATerm)ATmakeAppl2(PTA_afun12, (ATerm)ATmakeInt(label1), (ATerm)ATmakeInt(label2));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool PTA_isEqualParseTable(PTA_ParseTable arg0, PTA_ParseTable arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualLabels(PTA_Labels arg0, PTA_Labels arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualLabel(PTA_Label arg0, PTA_Label arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualStates(PTA_States arg0, PTA_States arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualState(PTA_State arg0, PTA_State arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualGotos(PTA_Gotos arg0, PTA_Gotos arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualGoto(PTA_Goto arg0, PTA_Goto arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualActions(PTA_Actions arg0, PTA_Actions arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualAction(PTA_Action arg0, PTA_Action arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualAlternatives(PTA_Alternatives arg0, PTA_Alternatives arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualAlternative(PTA_Alternative arg0, PTA_Alternative arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualSpecialAttr(PTA_SpecialAttr arg0, PTA_SpecialAttr arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualPriorities(PTA_Priorities arg0, PTA_Priorities arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualPriority(PTA_Priority arg0, PTA_Priority arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  PTA_ParseTable accessors */

/*{{{  ATbool PTA_isValidParseTable(PTA_ParseTable arg) */

ATbool PTA_isValidParseTable(PTA_ParseTable arg)
{
  if (PTA_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isParseTableParseTable(PTA_ParseTable arg) */

inline ATbool PTA_isParseTableParseTable(PTA_ParseTable arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternParseTableParseTable, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasParseTableVersion(PTA_ParseTable arg) */

ATbool PTA_hasParseTableVersion(PTA_ParseTable arg)
{
  if (PTA_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm PTA_getParseTableVersion(PTA_ParseTable arg) */

ATerm PTA_getParseTableVersion(PTA_ParseTable arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PTA_ParseTable PTA_setParseTableVersion(PTA_ParseTable arg, ATerm version) */

PTA_ParseTable PTA_setParseTableVersion(PTA_ParseTable arg, ATerm version)
{
  if (PTA_isParseTableParseTable(arg)) {
    return (PTA_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)version, 0);
  }

  ATabort("ParseTable has no Version: %t\n", arg);
  return (PTA_ParseTable)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasParseTableInitialState(PTA_ParseTable arg) */

ATbool PTA_hasParseTableInitialState(PTA_ParseTable arg)
{
  if (PTA_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm PTA_getParseTableInitialState(PTA_ParseTable arg) */

ATerm PTA_getParseTableInitialState(PTA_ParseTable arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  PTA_ParseTable PTA_setParseTableInitialState(PTA_ParseTable arg, ATerm initialState) */

PTA_ParseTable PTA_setParseTableInitialState(PTA_ParseTable arg, ATerm initialState)
{
  if (PTA_isParseTableParseTable(arg)) {
    return (PTA_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)initialState, 1);
  }

  ATabort("ParseTable has no InitialState: %t\n", arg);
  return (PTA_ParseTable)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasParseTableLabels(PTA_ParseTable arg) */

ATbool PTA_hasParseTableLabels(PTA_ParseTable arg)
{
  if (PTA_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Labels PTA_getParseTableLabels(PTA_ParseTable arg) */

PTA_Labels PTA_getParseTableLabels(PTA_ParseTable arg)
{
  
    return (PTA_Labels)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  PTA_ParseTable PTA_setParseTableLabels(PTA_ParseTable arg, PTA_Labels labels) */

PTA_ParseTable PTA_setParseTableLabels(PTA_ParseTable arg, PTA_Labels labels)
{
  if (PTA_isParseTableParseTable(arg)) {
    return (PTA_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)labels, 2);
  }

  ATabort("ParseTable has no Labels: %t\n", arg);
  return (PTA_ParseTable)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasParseTableStates(PTA_ParseTable arg) */

ATbool PTA_hasParseTableStates(PTA_ParseTable arg)
{
  if (PTA_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_States PTA_getParseTableStates(PTA_ParseTable arg) */

PTA_States PTA_getParseTableStates(PTA_ParseTable arg)
{
  
    return (PTA_States)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 3), 0);
}

/*}}}  */
/*{{{  PTA_ParseTable PTA_setParseTableStates(PTA_ParseTable arg, PTA_States states) */

PTA_ParseTable PTA_setParseTableStates(PTA_ParseTable arg, PTA_States states)
{
  if (PTA_isParseTableParseTable(arg)) {
    return (PTA_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 3), (ATerm)states, 0), 3);
  }

  ATabort("ParseTable has no States: %t\n", arg);
  return (PTA_ParseTable)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasParseTablePriorities(PTA_ParseTable arg) */

ATbool PTA_hasParseTablePriorities(PTA_ParseTable arg)
{
  if (PTA_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Priorities PTA_getParseTablePriorities(PTA_ParseTable arg) */

PTA_Priorities PTA_getParseTablePriorities(PTA_ParseTable arg)
{
  
    return (PTA_Priorities)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 4), 0);
}

/*}}}  */
/*{{{  PTA_ParseTable PTA_setParseTablePriorities(PTA_ParseTable arg, PTA_Priorities priorities) */

PTA_ParseTable PTA_setParseTablePriorities(PTA_ParseTable arg, PTA_Priorities priorities)
{
  if (PTA_isParseTableParseTable(arg)) {
    return (PTA_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 4), (ATerm)priorities, 0), 4);
  }

  ATabort("ParseTable has no Priorities: %t\n", arg);
  return (PTA_ParseTable)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_Labels accessors */

/*{{{  ATbool PTA_isValidLabels(PTA_Labels arg) */

ATbool PTA_isValidLabels(PTA_Labels arg)
{
  if (PTA_isLabelsEmpty(arg)) {
    return ATtrue;
  }
  else if (PTA_isLabelsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isLabelsEmpty(PTA_Labels arg) */

inline ATbool PTA_isLabelsEmpty(PTA_Labels arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternLabelsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isLabelsList(PTA_Labels arg) */

inline ATbool PTA_isLabelsList(PTA_Labels arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternLabelsList, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasLabelsHead(PTA_Labels arg) */

ATbool PTA_hasLabelsHead(PTA_Labels arg)
{
  if (PTA_isLabelsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Label PTA_getLabelsHead(PTA_Labels arg) */

PTA_Label PTA_getLabelsHead(PTA_Labels arg)
{
  
    return (PTA_Label)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_Labels PTA_setLabelsHead(PTA_Labels arg, PTA_Label head) */

PTA_Labels PTA_setLabelsHead(PTA_Labels arg, PTA_Label head)
{
  if (PTA_isLabelsList(arg)) {
    return (PTA_Labels)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Labels has no Head: %t\n", arg);
  return (PTA_Labels)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasLabelsTail(PTA_Labels arg) */

ATbool PTA_hasLabelsTail(PTA_Labels arg)
{
  if (PTA_isLabelsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Labels PTA_getLabelsTail(PTA_Labels arg) */

PTA_Labels PTA_getLabelsTail(PTA_Labels arg)
{
  
    return (PTA_Labels)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_Labels PTA_setLabelsTail(PTA_Labels arg, PTA_Labels tail) */

PTA_Labels PTA_setLabelsTail(PTA_Labels arg, PTA_Labels tail)
{
  if (PTA_isLabelsList(arg)) {
    return (PTA_Labels)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Labels has no Tail: %t\n", arg);
  return (PTA_Labels)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_Label accessors */

/*{{{  ATbool PTA_isValidLabel(PTA_Label arg) */

ATbool PTA_isValidLabel(PTA_Label arg)
{
  if (PTA_isLabelDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isLabelDefault(PTA_Label arg) */

inline ATbool PTA_isLabelDefault(PTA_Label arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternLabelDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasLabelProduction(PTA_Label arg) */

ATbool PTA_hasLabelProduction(PTA_Label arg)
{
  if (PTA_isLabelDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Production PTA_getLabelProduction(PTA_Label arg) */

PTA_Production PTA_getLabelProduction(PTA_Label arg)
{
  
    return (PTA_Production)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PTA_Label PTA_setLabelProduction(PTA_Label arg, PTA_Production production) */

PTA_Label PTA_setLabelProduction(PTA_Label arg, PTA_Production production)
{
  if (PTA_isLabelDefault(arg)) {
    return (PTA_Label)ATsetArgument((ATermAppl)arg, (ATerm)production, 0);
  }

  ATabort("Label has no Production: %t\n", arg);
  return (PTA_Label)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasLabelNumber(PTA_Label arg) */

ATbool PTA_hasLabelNumber(PTA_Label arg)
{
  if (PTA_isLabelDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PTA_getLabelNumber(PTA_Label arg) */

int PTA_getLabelNumber(PTA_Label arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTA_Label PTA_setLabelNumber(PTA_Label arg, int number) */

PTA_Label PTA_setLabelNumber(PTA_Label arg, int number)
{
  if (PTA_isLabelDefault(arg)) {
    return (PTA_Label)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(number), 1);
  }

  ATabort("Label has no Number: %t\n", arg);
  return (PTA_Label)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_States accessors */

/*{{{  ATbool PTA_isValidStates(PTA_States arg) */

ATbool PTA_isValidStates(PTA_States arg)
{
  if (PTA_isStatesEmpty(arg)) {
    return ATtrue;
  }
  else if (PTA_isStatesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isStatesEmpty(PTA_States arg) */

inline ATbool PTA_isStatesEmpty(PTA_States arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternStatesEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isStatesList(PTA_States arg) */

inline ATbool PTA_isStatesList(PTA_States arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternStatesList, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasStatesHead(PTA_States arg) */

ATbool PTA_hasStatesHead(PTA_States arg)
{
  if (PTA_isStatesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_State PTA_getStatesHead(PTA_States arg) */

PTA_State PTA_getStatesHead(PTA_States arg)
{
  
    return (PTA_State)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_States PTA_setStatesHead(PTA_States arg, PTA_State head) */

PTA_States PTA_setStatesHead(PTA_States arg, PTA_State head)
{
  if (PTA_isStatesList(arg)) {
    return (PTA_States)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("States has no Head: %t\n", arg);
  return (PTA_States)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasStatesTail(PTA_States arg) */

ATbool PTA_hasStatesTail(PTA_States arg)
{
  if (PTA_isStatesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_States PTA_getStatesTail(PTA_States arg) */

PTA_States PTA_getStatesTail(PTA_States arg)
{
  
    return (PTA_States)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_States PTA_setStatesTail(PTA_States arg, PTA_States tail) */

PTA_States PTA_setStatesTail(PTA_States arg, PTA_States tail)
{
  if (PTA_isStatesList(arg)) {
    return (PTA_States)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("States has no Tail: %t\n", arg);
  return (PTA_States)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_State accessors */

/*{{{  ATbool PTA_isValidState(PTA_State arg) */

ATbool PTA_isValidState(PTA_State arg)
{
  if (PTA_isStateDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isStateDefault(PTA_State arg) */

inline ATbool PTA_isStateDefault(PTA_State arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternStateDefault, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasStateNumber(PTA_State arg) */

ATbool PTA_hasStateNumber(PTA_State arg)
{
  if (PTA_isStateDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PTA_getStateNumber(PTA_State arg) */

int PTA_getStateNumber(PTA_State arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  PTA_State PTA_setStateNumber(PTA_State arg, int number) */

PTA_State PTA_setStateNumber(PTA_State arg, int number)
{
  if (PTA_isStateDefault(arg)) {
    return (PTA_State)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(number), 0);
  }

  ATabort("State has no Number: %t\n", arg);
  return (PTA_State)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasStateGotos(PTA_State arg) */

ATbool PTA_hasStateGotos(PTA_State arg)
{
  if (PTA_isStateDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Gotos PTA_getStateGotos(PTA_State arg) */

PTA_Gotos PTA_getStateGotos(PTA_State arg)
{
  
    return (PTA_Gotos)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  PTA_State PTA_setStateGotos(PTA_State arg, PTA_Gotos gotos) */

PTA_State PTA_setStateGotos(PTA_State arg, PTA_Gotos gotos)
{
  if (PTA_isStateDefault(arg)) {
    return (PTA_State)ATsetArgument((ATermAppl)arg, (ATerm)gotos, 1);
  }

  ATabort("State has no Gotos: %t\n", arg);
  return (PTA_State)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasStateActions(PTA_State arg) */

ATbool PTA_hasStateActions(PTA_State arg)
{
  if (PTA_isStateDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Actions PTA_getStateActions(PTA_State arg) */

PTA_Actions PTA_getStateActions(PTA_State arg)
{
  
    return (PTA_Actions)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  PTA_State PTA_setStateActions(PTA_State arg, PTA_Actions actions) */

PTA_State PTA_setStateActions(PTA_State arg, PTA_Actions actions)
{
  if (PTA_isStateDefault(arg)) {
    return (PTA_State)ATsetArgument((ATermAppl)arg, (ATerm)actions, 2);
  }

  ATabort("State has no Actions: %t\n", arg);
  return (PTA_State)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_Gotos accessors */

/*{{{  ATbool PTA_isValidGotos(PTA_Gotos arg) */

ATbool PTA_isValidGotos(PTA_Gotos arg)
{
  if (PTA_isGotosEmpty(arg)) {
    return ATtrue;
  }
  else if (PTA_isGotosList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isGotosEmpty(PTA_Gotos arg) */

inline ATbool PTA_isGotosEmpty(PTA_Gotos arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternGotosEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isGotosList(PTA_Gotos arg) */

inline ATbool PTA_isGotosList(PTA_Gotos arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternGotosList, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasGotosHead(PTA_Gotos arg) */

ATbool PTA_hasGotosHead(PTA_Gotos arg)
{
  if (PTA_isGotosList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Goto PTA_getGotosHead(PTA_Gotos arg) */

PTA_Goto PTA_getGotosHead(PTA_Gotos arg)
{
  
    return (PTA_Goto)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_Gotos PTA_setGotosHead(PTA_Gotos arg, PTA_Goto head) */

PTA_Gotos PTA_setGotosHead(PTA_Gotos arg, PTA_Goto head)
{
  if (PTA_isGotosList(arg)) {
    return (PTA_Gotos)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Gotos has no Head: %t\n", arg);
  return (PTA_Gotos)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasGotosTail(PTA_Gotos arg) */

ATbool PTA_hasGotosTail(PTA_Gotos arg)
{
  if (PTA_isGotosList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Gotos PTA_getGotosTail(PTA_Gotos arg) */

PTA_Gotos PTA_getGotosTail(PTA_Gotos arg)
{
  
    return (PTA_Gotos)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_Gotos PTA_setGotosTail(PTA_Gotos arg, PTA_Gotos tail) */

PTA_Gotos PTA_setGotosTail(PTA_Gotos arg, PTA_Gotos tail)
{
  if (PTA_isGotosList(arg)) {
    return (PTA_Gotos)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Gotos has no Tail: %t\n", arg);
  return (PTA_Gotos)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_Goto accessors */

/*{{{  ATbool PTA_isValidGoto(PTA_Goto arg) */

ATbool PTA_isValidGoto(PTA_Goto arg)
{
  if (PTA_isGotoDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isGotoDefault(PTA_Goto arg) */

inline ATbool PTA_isGotoDefault(PTA_Goto arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternGotoDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasGotoRanges(PTA_Goto arg) */

ATbool PTA_hasGotoRanges(PTA_Goto arg)
{
  if (PTA_isGotoDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_CharRanges PTA_getGotoRanges(PTA_Goto arg) */

PTA_CharRanges PTA_getGotoRanges(PTA_Goto arg)
{
  
    return (PTA_CharRanges)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PTA_Goto PTA_setGotoRanges(PTA_Goto arg, PTA_CharRanges ranges) */

PTA_Goto PTA_setGotoRanges(PTA_Goto arg, PTA_CharRanges ranges)
{
  if (PTA_isGotoDefault(arg)) {
    return (PTA_Goto)ATsetArgument((ATermAppl)arg, (ATerm)ranges, 0);
  }

  ATabort("Goto has no Ranges: %t\n", arg);
  return (PTA_Goto)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasGotoStateNumber(PTA_Goto arg) */

ATbool PTA_hasGotoStateNumber(PTA_Goto arg)
{
  if (PTA_isGotoDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PTA_getGotoStateNumber(PTA_Goto arg) */

int PTA_getGotoStateNumber(PTA_Goto arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTA_Goto PTA_setGotoStateNumber(PTA_Goto arg, int stateNumber) */

PTA_Goto PTA_setGotoStateNumber(PTA_Goto arg, int stateNumber)
{
  if (PTA_isGotoDefault(arg)) {
    return (PTA_Goto)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(stateNumber), 1);
  }

  ATabort("Goto has no StateNumber: %t\n", arg);
  return (PTA_Goto)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_Actions accessors */

/*{{{  ATbool PTA_isValidActions(PTA_Actions arg) */

ATbool PTA_isValidActions(PTA_Actions arg)
{
  if (PTA_isActionsEmpty(arg)) {
    return ATtrue;
  }
  else if (PTA_isActionsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isActionsEmpty(PTA_Actions arg) */

inline ATbool PTA_isActionsEmpty(PTA_Actions arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternActionsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isActionsList(PTA_Actions arg) */

inline ATbool PTA_isActionsList(PTA_Actions arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternActionsList, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasActionsHead(PTA_Actions arg) */

ATbool PTA_hasActionsHead(PTA_Actions arg)
{
  if (PTA_isActionsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Action PTA_getActionsHead(PTA_Actions arg) */

PTA_Action PTA_getActionsHead(PTA_Actions arg)
{
  
    return (PTA_Action)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_Actions PTA_setActionsHead(PTA_Actions arg, PTA_Action head) */

PTA_Actions PTA_setActionsHead(PTA_Actions arg, PTA_Action head)
{
  if (PTA_isActionsList(arg)) {
    return (PTA_Actions)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Actions has no Head: %t\n", arg);
  return (PTA_Actions)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasActionsTail(PTA_Actions arg) */

ATbool PTA_hasActionsTail(PTA_Actions arg)
{
  if (PTA_isActionsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Actions PTA_getActionsTail(PTA_Actions arg) */

PTA_Actions PTA_getActionsTail(PTA_Actions arg)
{
  
    return (PTA_Actions)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_Actions PTA_setActionsTail(PTA_Actions arg, PTA_Actions tail) */

PTA_Actions PTA_setActionsTail(PTA_Actions arg, PTA_Actions tail)
{
  if (PTA_isActionsList(arg)) {
    return (PTA_Actions)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Actions has no Tail: %t\n", arg);
  return (PTA_Actions)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_Action accessors */

/*{{{  ATbool PTA_isValidAction(PTA_Action arg) */

ATbool PTA_isValidAction(PTA_Action arg)
{
  if (PTA_isActionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isActionDefault(PTA_Action arg) */

inline ATbool PTA_isActionDefault(PTA_Action arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternActionDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasActionRanges(PTA_Action arg) */

ATbool PTA_hasActionRanges(PTA_Action arg)
{
  if (PTA_isActionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_CharRanges PTA_getActionRanges(PTA_Action arg) */

PTA_CharRanges PTA_getActionRanges(PTA_Action arg)
{
  
    return (PTA_CharRanges)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PTA_Action PTA_setActionRanges(PTA_Action arg, PTA_CharRanges ranges) */

PTA_Action PTA_setActionRanges(PTA_Action arg, PTA_CharRanges ranges)
{
  if (PTA_isActionDefault(arg)) {
    return (PTA_Action)ATsetArgument((ATermAppl)arg, (ATerm)ranges, 0);
  }

  ATabort("Action has no Ranges: %t\n", arg);
  return (PTA_Action)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasActionAlternatives(PTA_Action arg) */

ATbool PTA_hasActionAlternatives(PTA_Action arg)
{
  if (PTA_isActionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Alternatives PTA_getActionAlternatives(PTA_Action arg) */

PTA_Alternatives PTA_getActionAlternatives(PTA_Action arg)
{
  
    return (PTA_Alternatives)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  PTA_Action PTA_setActionAlternatives(PTA_Action arg, PTA_Alternatives alternatives) */

PTA_Action PTA_setActionAlternatives(PTA_Action arg, PTA_Alternatives alternatives)
{
  if (PTA_isActionDefault(arg)) {
    return (PTA_Action)ATsetArgument((ATermAppl)arg, (ATerm)alternatives, 1);
  }

  ATabort("Action has no Alternatives: %t\n", arg);
  return (PTA_Action)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_Alternatives accessors */

/*{{{  ATbool PTA_isValidAlternatives(PTA_Alternatives arg) */

ATbool PTA_isValidAlternatives(PTA_Alternatives arg)
{
  if (PTA_isAlternativesEmpty(arg)) {
    return ATtrue;
  }
  else if (PTA_isAlternativesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isAlternativesEmpty(PTA_Alternatives arg) */

inline ATbool PTA_isAlternativesEmpty(PTA_Alternatives arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternAlternativesEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isAlternativesList(PTA_Alternatives arg) */

inline ATbool PTA_isAlternativesList(PTA_Alternatives arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternAlternativesList, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasAlternativesHead(PTA_Alternatives arg) */

ATbool PTA_hasAlternativesHead(PTA_Alternatives arg)
{
  if (PTA_isAlternativesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Alternative PTA_getAlternativesHead(PTA_Alternatives arg) */

PTA_Alternative PTA_getAlternativesHead(PTA_Alternatives arg)
{
  
    return (PTA_Alternative)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_Alternatives PTA_setAlternativesHead(PTA_Alternatives arg, PTA_Alternative head) */

PTA_Alternatives PTA_setAlternativesHead(PTA_Alternatives arg, PTA_Alternative head)
{
  if (PTA_isAlternativesList(arg)) {
    return (PTA_Alternatives)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Alternatives has no Head: %t\n", arg);
  return (PTA_Alternatives)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasAlternativesTail(PTA_Alternatives arg) */

ATbool PTA_hasAlternativesTail(PTA_Alternatives arg)
{
  if (PTA_isAlternativesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Alternatives PTA_getAlternativesTail(PTA_Alternatives arg) */

PTA_Alternatives PTA_getAlternativesTail(PTA_Alternatives arg)
{
  
    return (PTA_Alternatives)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_Alternatives PTA_setAlternativesTail(PTA_Alternatives arg, PTA_Alternatives tail) */

PTA_Alternatives PTA_setAlternativesTail(PTA_Alternatives arg, PTA_Alternatives tail)
{
  if (PTA_isAlternativesList(arg)) {
    return (PTA_Alternatives)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Alternatives has no Tail: %t\n", arg);
  return (PTA_Alternatives)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_Alternative accessors */

/*{{{  ATbool PTA_isValidAlternative(PTA_Alternative arg) */

ATbool PTA_isValidAlternative(PTA_Alternative arg)
{
  if (PTA_isAlternativeReduce(arg)) {
    return ATtrue;
  }
  else if (PTA_isAlternativeShift(arg)) {
    return ATtrue;
  }
  else if (PTA_isAlternativeAccept(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isAlternativeReduce(PTA_Alternative arg) */

inline ATbool PTA_isAlternativeReduce(PTA_Alternative arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(PTA_patternAlternativeReduce)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternAlternativeReduce, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isAlternativeShift(PTA_Alternative arg) */

inline ATbool PTA_isAlternativeShift(PTA_Alternative arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(PTA_patternAlternativeShift)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternAlternativeShift, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isAlternativeAccept(PTA_Alternative arg) */

inline ATbool PTA_isAlternativeAccept(PTA_Alternative arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(PTA_patternAlternativeAccept)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternAlternativeAccept));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasAlternativeLength(PTA_Alternative arg) */

ATbool PTA_hasAlternativeLength(PTA_Alternative arg)
{
  if (PTA_isAlternativeReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PTA_getAlternativeLength(PTA_Alternative arg) */

int PTA_getAlternativeLength(PTA_Alternative arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  PTA_Alternative PTA_setAlternativeLength(PTA_Alternative arg, int length) */

PTA_Alternative PTA_setAlternativeLength(PTA_Alternative arg, int length)
{
  if (PTA_isAlternativeReduce(arg)) {
    return (PTA_Alternative)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(length), 0);
  }

  ATabort("Alternative has no Length: %t\n", arg);
  return (PTA_Alternative)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasAlternativeLabel(PTA_Alternative arg) */

ATbool PTA_hasAlternativeLabel(PTA_Alternative arg)
{
  if (PTA_isAlternativeReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PTA_getAlternativeLabel(PTA_Alternative arg) */

int PTA_getAlternativeLabel(PTA_Alternative arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTA_Alternative PTA_setAlternativeLabel(PTA_Alternative arg, int label) */

PTA_Alternative PTA_setAlternativeLabel(PTA_Alternative arg, int label)
{
  if (PTA_isAlternativeReduce(arg)) {
    return (PTA_Alternative)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(label), 1);
  }

  ATabort("Alternative has no Label: %t\n", arg);
  return (PTA_Alternative)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasAlternativeSpecialAttr(PTA_Alternative arg) */

ATbool PTA_hasAlternativeSpecialAttr(PTA_Alternative arg)
{
  if (PTA_isAlternativeReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_SpecialAttr PTA_getAlternativeSpecialAttr(PTA_Alternative arg) */

PTA_SpecialAttr PTA_getAlternativeSpecialAttr(PTA_Alternative arg)
{
  
    return (PTA_SpecialAttr)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  PTA_Alternative PTA_setAlternativeSpecialAttr(PTA_Alternative arg, PTA_SpecialAttr specialAttr) */

PTA_Alternative PTA_setAlternativeSpecialAttr(PTA_Alternative arg, PTA_SpecialAttr specialAttr)
{
  if (PTA_isAlternativeReduce(arg)) {
    return (PTA_Alternative)ATsetArgument((ATermAppl)arg, (ATerm)specialAttr, 2);
  }

  ATabort("Alternative has no SpecialAttr: %t\n", arg);
  return (PTA_Alternative)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasAlternativeStateNumner(PTA_Alternative arg) */

ATbool PTA_hasAlternativeStateNumner(PTA_Alternative arg)
{
  if (PTA_isAlternativeShift(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PTA_getAlternativeStateNumner(PTA_Alternative arg) */

int PTA_getAlternativeStateNumner(PTA_Alternative arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  PTA_Alternative PTA_setAlternativeStateNumner(PTA_Alternative arg, int stateNumner) */

PTA_Alternative PTA_setAlternativeStateNumner(PTA_Alternative arg, int stateNumner)
{
  if (PTA_isAlternativeShift(arg)) {
    return (PTA_Alternative)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(stateNumner), 0);
  }

  ATabort("Alternative has no StateNumner: %t\n", arg);
  return (PTA_Alternative)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_SpecialAttr accessors */

/*{{{  ATbool PTA_isValidSpecialAttr(PTA_SpecialAttr arg) */

ATbool PTA_isValidSpecialAttr(PTA_SpecialAttr arg)
{
  if (PTA_isSpecialAttrNone(arg)) {
    return ATtrue;
  }
  else if (PTA_isSpecialAttrReject(arg)) {
    return ATtrue;
  }
  else if (PTA_isSpecialAttrPrefer(arg)) {
    return ATtrue;
  }
  else if (PTA_isSpecialAttrAvoid(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isSpecialAttrNone(PTA_SpecialAttr arg) */

inline ATbool PTA_isSpecialAttrNone(PTA_SpecialAttr arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTA_patternSpecialAttrNone);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTA_isSpecialAttrReject(PTA_SpecialAttr arg) */

inline ATbool PTA_isSpecialAttrReject(PTA_SpecialAttr arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTA_patternSpecialAttrReject);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTA_isSpecialAttrPrefer(PTA_SpecialAttr arg) */

inline ATbool PTA_isSpecialAttrPrefer(PTA_SpecialAttr arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTA_patternSpecialAttrPrefer);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTA_isSpecialAttrAvoid(PTA_SpecialAttr arg) */

inline ATbool PTA_isSpecialAttrAvoid(PTA_SpecialAttr arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTA_patternSpecialAttrAvoid);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  PTA_Priorities accessors */

/*{{{  ATbool PTA_isValidPriorities(PTA_Priorities arg) */

ATbool PTA_isValidPriorities(PTA_Priorities arg)
{
  if (PTA_isPrioritiesEmpty(arg)) {
    return ATtrue;
  }
  else if (PTA_isPrioritiesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isPrioritiesEmpty(PTA_Priorities arg) */

inline ATbool PTA_isPrioritiesEmpty(PTA_Priorities arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternPrioritiesEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isPrioritiesList(PTA_Priorities arg) */

inline ATbool PTA_isPrioritiesList(PTA_Priorities arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternPrioritiesList, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasPrioritiesHead(PTA_Priorities arg) */

ATbool PTA_hasPrioritiesHead(PTA_Priorities arg)
{
  if (PTA_isPrioritiesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Priority PTA_getPrioritiesHead(PTA_Priorities arg) */

PTA_Priority PTA_getPrioritiesHead(PTA_Priorities arg)
{
  
    return (PTA_Priority)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_Priorities PTA_setPrioritiesHead(PTA_Priorities arg, PTA_Priority head) */

PTA_Priorities PTA_setPrioritiesHead(PTA_Priorities arg, PTA_Priority head)
{
  if (PTA_isPrioritiesList(arg)) {
    return (PTA_Priorities)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Priorities has no Head: %t\n", arg);
  return (PTA_Priorities)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasPrioritiesTail(PTA_Priorities arg) */

ATbool PTA_hasPrioritiesTail(PTA_Priorities arg)
{
  if (PTA_isPrioritiesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Priorities PTA_getPrioritiesTail(PTA_Priorities arg) */

PTA_Priorities PTA_getPrioritiesTail(PTA_Priorities arg)
{
  
    return (PTA_Priorities)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_Priorities PTA_setPrioritiesTail(PTA_Priorities arg, PTA_Priorities tail) */

PTA_Priorities PTA_setPrioritiesTail(PTA_Priorities arg, PTA_Priorities tail)
{
  if (PTA_isPrioritiesList(arg)) {
    return (PTA_Priorities)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Priorities has no Tail: %t\n", arg);
  return (PTA_Priorities)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_Priority accessors */

/*{{{  ATbool PTA_isValidPriority(PTA_Priority arg) */

ATbool PTA_isValidPriority(PTA_Priority arg)
{
  if (PTA_isPriorityLeft(arg)) {
    return ATtrue;
  }
  else if (PTA_isPriorityRight(arg)) {
    return ATtrue;
  }
  else if (PTA_isPriorityGreater(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isPriorityLeft(PTA_Priority arg) */

inline ATbool PTA_isPriorityLeft(PTA_Priority arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(PTA_patternPriorityLeft)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternPriorityLeft, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isPriorityRight(PTA_Priority arg) */

inline ATbool PTA_isPriorityRight(PTA_Priority arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(PTA_patternPriorityRight)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternPriorityRight, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isPriorityGreater(PTA_Priority arg) */

inline ATbool PTA_isPriorityGreater(PTA_Priority arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(PTA_patternPriorityGreater)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternPriorityGreater, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasPriorityLabel1(PTA_Priority arg) */

ATbool PTA_hasPriorityLabel1(PTA_Priority arg)
{
  if (PTA_isPriorityLeft(arg)) {
    return ATtrue;
  }
  else if (PTA_isPriorityRight(arg)) {
    return ATtrue;
  }
  else if (PTA_isPriorityGreater(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PTA_getPriorityLabel1(PTA_Priority arg) */

int PTA_getPriorityLabel1(PTA_Priority arg)
{
  if (PTA_isPriorityLeft(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
  }
  else if (PTA_isPriorityRight(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
  }
  else 
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  PTA_Priority PTA_setPriorityLabel1(PTA_Priority arg, int label1) */

PTA_Priority PTA_setPriorityLabel1(PTA_Priority arg, int label1)
{
  if (PTA_isPriorityLeft(arg)) {
    return (PTA_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(label1), 0);
  }
  else if (PTA_isPriorityRight(arg)) {
    return (PTA_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(label1), 0);
  }
  else if (PTA_isPriorityGreater(arg)) {
    return (PTA_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(label1), 0);
  }

  ATabort("Priority has no Label1: %t\n", arg);
  return (PTA_Priority)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasPriorityLabel2(PTA_Priority arg) */

ATbool PTA_hasPriorityLabel2(PTA_Priority arg)
{
  if (PTA_isPriorityLeft(arg)) {
    return ATtrue;
  }
  else if (PTA_isPriorityRight(arg)) {
    return ATtrue;
  }
  else if (PTA_isPriorityGreater(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PTA_getPriorityLabel2(PTA_Priority arg) */

int PTA_getPriorityLabel2(PTA_Priority arg)
{
  if (PTA_isPriorityLeft(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PTA_isPriorityRight(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTA_Priority PTA_setPriorityLabel2(PTA_Priority arg, int label2) */

PTA_Priority PTA_setPriorityLabel2(PTA_Priority arg, int label2)
{
  if (PTA_isPriorityLeft(arg)) {
    return (PTA_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(label2), 1);
  }
  else if (PTA_isPriorityRight(arg)) {
    return (PTA_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(label2), 1);
  }
  else if (PTA_isPriorityGreater(arg)) {
    return (PTA_Priority)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(label2), 1);
  }

  ATabort("Priority has no Label2: %t\n", arg);
  return (PTA_Priority)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  PTA_ParseTable PTA_visitParseTable(PTA_ParseTable arg, ATerm (*acceptVersion)(ATerm), ATerm (*acceptInitialState)(ATerm), PTA_Labels (*acceptLabels)(PTA_Labels), PTA_States (*acceptStates)(PTA_States), PTA_Priorities (*acceptPriorities)(PTA_Priorities)) */

PTA_ParseTable PTA_visitParseTable(PTA_ParseTable arg, ATerm (*acceptVersion)(ATerm), ATerm (*acceptInitialState)(ATerm), PTA_Labels (*acceptLabels)(PTA_Labels), PTA_States (*acceptStates)(PTA_States), PTA_Priorities (*acceptPriorities)(PTA_Priorities))
{
  if (PTA_isParseTableParseTable(arg)) {
    return PTA_makeParseTableParseTable(
        acceptVersion ? acceptVersion(PTA_getParseTableVersion(arg)) : PTA_getParseTableVersion(arg),
        acceptInitialState ? acceptInitialState(PTA_getParseTableInitialState(arg)) : PTA_getParseTableInitialState(arg),
        acceptLabels ? acceptLabels(PTA_getParseTableLabels(arg)) : PTA_getParseTableLabels(arg),
        acceptStates ? acceptStates(PTA_getParseTableStates(arg)) : PTA_getParseTableStates(arg),
        acceptPriorities ? acceptPriorities(PTA_getParseTablePriorities(arg)) : PTA_getParseTablePriorities(arg));
  }
  ATabort("not a ParseTable: %t\n", arg);
  return (PTA_ParseTable)NULL;
}

/*}}}  */
/*{{{  PTA_Labels PTA_visitLabels(PTA_Labels arg, PTA_Label (*acceptHead)(PTA_Label)) */

PTA_Labels PTA_visitLabels(PTA_Labels arg, PTA_Label (*acceptHead)(PTA_Label))
{
  if (PTA_isLabelsEmpty(arg)) {
    return PTA_makeLabelsEmpty();
  }
  if (PTA_isLabelsList(arg)) {
    return PTA_makeLabelsList(
        acceptHead ? acceptHead(PTA_getLabelsHead(arg)) : PTA_getLabelsHead(arg),
        PTA_visitLabels(PTA_getLabelsTail(arg), acceptHead));
  }
  ATabort("not a Labels: %t\n", arg);
  return (PTA_Labels)NULL;
}

/*}}}  */
/*{{{  PTA_Label PTA_visitLabel(PTA_Label arg, PTA_Production (*acceptProduction)(PTA_Production), int (*acceptNumber)(int)) */

PTA_Label PTA_visitLabel(PTA_Label arg, PTA_Production (*acceptProduction)(PTA_Production), int (*acceptNumber)(int))
{
  if (PTA_isLabelDefault(arg)) {
    return PTA_makeLabelDefault(
        acceptProduction ? acceptProduction(PTA_getLabelProduction(arg)) : PTA_getLabelProduction(arg),
        acceptNumber ? acceptNumber(PTA_getLabelNumber(arg)) : PTA_getLabelNumber(arg));
  }
  ATabort("not a Label: %t\n", arg);
  return (PTA_Label)NULL;
}

/*}}}  */
/*{{{  PTA_States PTA_visitStates(PTA_States arg, PTA_State (*acceptHead)(PTA_State)) */

PTA_States PTA_visitStates(PTA_States arg, PTA_State (*acceptHead)(PTA_State))
{
  if (PTA_isStatesEmpty(arg)) {
    return PTA_makeStatesEmpty();
  }
  if (PTA_isStatesList(arg)) {
    return PTA_makeStatesList(
        acceptHead ? acceptHead(PTA_getStatesHead(arg)) : PTA_getStatesHead(arg),
        PTA_visitStates(PTA_getStatesTail(arg), acceptHead));
  }
  ATabort("not a States: %t\n", arg);
  return (PTA_States)NULL;
}

/*}}}  */
/*{{{  PTA_State PTA_visitState(PTA_State arg, int (*acceptNumber)(int), PTA_Gotos (*acceptGotos)(PTA_Gotos), PTA_Actions (*acceptActions)(PTA_Actions)) */

PTA_State PTA_visitState(PTA_State arg, int (*acceptNumber)(int), PTA_Gotos (*acceptGotos)(PTA_Gotos), PTA_Actions (*acceptActions)(PTA_Actions))
{
  if (PTA_isStateDefault(arg)) {
    return PTA_makeStateDefault(
        acceptNumber ? acceptNumber(PTA_getStateNumber(arg)) : PTA_getStateNumber(arg),
        acceptGotos ? acceptGotos(PTA_getStateGotos(arg)) : PTA_getStateGotos(arg),
        acceptActions ? acceptActions(PTA_getStateActions(arg)) : PTA_getStateActions(arg));
  }
  ATabort("not a State: %t\n", arg);
  return (PTA_State)NULL;
}

/*}}}  */
/*{{{  PTA_Gotos PTA_visitGotos(PTA_Gotos arg, PTA_Goto (*acceptHead)(PTA_Goto)) */

PTA_Gotos PTA_visitGotos(PTA_Gotos arg, PTA_Goto (*acceptHead)(PTA_Goto))
{
  if (PTA_isGotosEmpty(arg)) {
    return PTA_makeGotosEmpty();
  }
  if (PTA_isGotosList(arg)) {
    return PTA_makeGotosList(
        acceptHead ? acceptHead(PTA_getGotosHead(arg)) : PTA_getGotosHead(arg),
        PTA_visitGotos(PTA_getGotosTail(arg), acceptHead));
  }
  ATabort("not a Gotos: %t\n", arg);
  return (PTA_Gotos)NULL;
}

/*}}}  */
/*{{{  PTA_Goto PTA_visitGoto(PTA_Goto arg, PTA_CharRanges (*acceptRanges)(PTA_CharRanges), int (*acceptStateNumber)(int)) */

PTA_Goto PTA_visitGoto(PTA_Goto arg, PTA_CharRanges (*acceptRanges)(PTA_CharRanges), int (*acceptStateNumber)(int))
{
  if (PTA_isGotoDefault(arg)) {
    return PTA_makeGotoDefault(
        acceptRanges ? acceptRanges(PTA_getGotoRanges(arg)) : PTA_getGotoRanges(arg),
        acceptStateNumber ? acceptStateNumber(PTA_getGotoStateNumber(arg)) : PTA_getGotoStateNumber(arg));
  }
  ATabort("not a Goto: %t\n", arg);
  return (PTA_Goto)NULL;
}

/*}}}  */
/*{{{  PTA_Actions PTA_visitActions(PTA_Actions arg, PTA_Action (*acceptHead)(PTA_Action)) */

PTA_Actions PTA_visitActions(PTA_Actions arg, PTA_Action (*acceptHead)(PTA_Action))
{
  if (PTA_isActionsEmpty(arg)) {
    return PTA_makeActionsEmpty();
  }
  if (PTA_isActionsList(arg)) {
    return PTA_makeActionsList(
        acceptHead ? acceptHead(PTA_getActionsHead(arg)) : PTA_getActionsHead(arg),
        PTA_visitActions(PTA_getActionsTail(arg), acceptHead));
  }
  ATabort("not a Actions: %t\n", arg);
  return (PTA_Actions)NULL;
}

/*}}}  */
/*{{{  PTA_Action PTA_visitAction(PTA_Action arg, PTA_CharRanges (*acceptRanges)(PTA_CharRanges), PTA_Alternatives (*acceptAlternatives)(PTA_Alternatives)) */

PTA_Action PTA_visitAction(PTA_Action arg, PTA_CharRanges (*acceptRanges)(PTA_CharRanges), PTA_Alternatives (*acceptAlternatives)(PTA_Alternatives))
{
  if (PTA_isActionDefault(arg)) {
    return PTA_makeActionDefault(
        acceptRanges ? acceptRanges(PTA_getActionRanges(arg)) : PTA_getActionRanges(arg),
        acceptAlternatives ? acceptAlternatives(PTA_getActionAlternatives(arg)) : PTA_getActionAlternatives(arg));
  }
  ATabort("not a Action: %t\n", arg);
  return (PTA_Action)NULL;
}

/*}}}  */
/*{{{  PTA_Alternatives PTA_visitAlternatives(PTA_Alternatives arg, PTA_Alternative (*acceptHead)(PTA_Alternative)) */

PTA_Alternatives PTA_visitAlternatives(PTA_Alternatives arg, PTA_Alternative (*acceptHead)(PTA_Alternative))
{
  if (PTA_isAlternativesEmpty(arg)) {
    return PTA_makeAlternativesEmpty();
  }
  if (PTA_isAlternativesList(arg)) {
    return PTA_makeAlternativesList(
        acceptHead ? acceptHead(PTA_getAlternativesHead(arg)) : PTA_getAlternativesHead(arg),
        PTA_visitAlternatives(PTA_getAlternativesTail(arg), acceptHead));
  }
  ATabort("not a Alternatives: %t\n", arg);
  return (PTA_Alternatives)NULL;
}

/*}}}  */
/*{{{  PTA_Alternative PTA_visitAlternative(PTA_Alternative arg, int (*acceptLength)(int), int (*acceptLabel)(int), PTA_SpecialAttr (*acceptSpecialAttr)(PTA_SpecialAttr), int (*acceptStateNumner)(int)) */

PTA_Alternative PTA_visitAlternative(PTA_Alternative arg, int (*acceptLength)(int), int (*acceptLabel)(int), PTA_SpecialAttr (*acceptSpecialAttr)(PTA_SpecialAttr), int (*acceptStateNumner)(int))
{
  if (PTA_isAlternativeReduce(arg)) {
    return PTA_makeAlternativeReduce(
        acceptLength ? acceptLength(PTA_getAlternativeLength(arg)) : PTA_getAlternativeLength(arg),
        acceptLabel ? acceptLabel(PTA_getAlternativeLabel(arg)) : PTA_getAlternativeLabel(arg),
        acceptSpecialAttr ? acceptSpecialAttr(PTA_getAlternativeSpecialAttr(arg)) : PTA_getAlternativeSpecialAttr(arg));
  }
  if (PTA_isAlternativeShift(arg)) {
    return PTA_makeAlternativeShift(
        acceptStateNumner ? acceptStateNumner(PTA_getAlternativeStateNumner(arg)) : PTA_getAlternativeStateNumner(arg));
  }
  if (PTA_isAlternativeAccept(arg)) {
    return PTA_makeAlternativeAccept();
  }
  ATabort("not a Alternative: %t\n", arg);
  return (PTA_Alternative)NULL;
}

/*}}}  */
/*{{{  PTA_SpecialAttr PTA_visitSpecialAttr(PTA_SpecialAttr arg) */

PTA_SpecialAttr PTA_visitSpecialAttr(PTA_SpecialAttr arg)
{
  if (PTA_isSpecialAttrNone(arg)) {
    return PTA_makeSpecialAttrNone();
  }
  if (PTA_isSpecialAttrReject(arg)) {
    return PTA_makeSpecialAttrReject();
  }
  if (PTA_isSpecialAttrPrefer(arg)) {
    return PTA_makeSpecialAttrPrefer();
  }
  if (PTA_isSpecialAttrAvoid(arg)) {
    return PTA_makeSpecialAttrAvoid();
  }
  ATabort("not a SpecialAttr: %t\n", arg);
  return (PTA_SpecialAttr)NULL;
}

/*}}}  */
/*{{{  PTA_Priorities PTA_visitPriorities(PTA_Priorities arg, PTA_Priority (*acceptHead)(PTA_Priority)) */

PTA_Priorities PTA_visitPriorities(PTA_Priorities arg, PTA_Priority (*acceptHead)(PTA_Priority))
{
  if (PTA_isPrioritiesEmpty(arg)) {
    return PTA_makePrioritiesEmpty();
  }
  if (PTA_isPrioritiesList(arg)) {
    return PTA_makePrioritiesList(
        acceptHead ? acceptHead(PTA_getPrioritiesHead(arg)) : PTA_getPrioritiesHead(arg),
        PTA_visitPriorities(PTA_getPrioritiesTail(arg), acceptHead));
  }
  ATabort("not a Priorities: %t\n", arg);
  return (PTA_Priorities)NULL;
}

/*}}}  */
/*{{{  PTA_Priority PTA_visitPriority(PTA_Priority arg, int (*acceptLabel1)(int), int (*acceptLabel2)(int)) */

PTA_Priority PTA_visitPriority(PTA_Priority arg, int (*acceptLabel1)(int), int (*acceptLabel2)(int))
{
  if (PTA_isPriorityLeft(arg)) {
    return PTA_makePriorityLeft(
        acceptLabel1 ? acceptLabel1(PTA_getPriorityLabel1(arg)) : PTA_getPriorityLabel1(arg),
        acceptLabel2 ? acceptLabel2(PTA_getPriorityLabel2(arg)) : PTA_getPriorityLabel2(arg));
  }
  if (PTA_isPriorityRight(arg)) {
    return PTA_makePriorityRight(
        acceptLabel1 ? acceptLabel1(PTA_getPriorityLabel1(arg)) : PTA_getPriorityLabel1(arg),
        acceptLabel2 ? acceptLabel2(PTA_getPriorityLabel2(arg)) : PTA_getPriorityLabel2(arg));
  }
  if (PTA_isPriorityGreater(arg)) {
    return PTA_makePriorityGreater(
        acceptLabel1 ? acceptLabel1(PTA_getPriorityLabel1(arg)) : PTA_getPriorityLabel1(arg),
        acceptLabel2 ? acceptLabel2(PTA_getPriorityLabel2(arg)) : PTA_getPriorityLabel2(arg));
  }
  ATabort("not a Priority: %t\n", arg);
  return (PTA_Priority)NULL;
}

/*}}}  */

/*}}}  */
