#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ptable.h"

/*{{{  typedefs */

typedef struct ATerm _PTA_Version;
typedef struct ATerm _PTA_ParseTable;
typedef struct ATerm _PTA_Labels;
typedef struct ATerm _PTA_Label;
typedef struct ATerm _PTA_States;
typedef struct ATerm _PTA_State;
typedef struct ATerm _PTA_Gotos;
typedef struct ATerm _PTA_Goto;
typedef struct ATerm _PTA_Actions;
typedef struct ATerm _PTA_Action;
typedef struct ATerm _PTA_Choices;
typedef struct ATerm _PTA_Choice;
typedef struct ATerm _PTA_SpecialAttr;
typedef struct ATerm _PTA_LookAhead;
typedef struct ATerm _PTA_CharClass;
typedef struct ATerm _PTA_LookAheads;
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

/*{{{  PTA_Version PTA_VersionFromTerm(ATerm t) */

PTA_Version PTA_VersionFromTerm(ATerm t)
{
  return (PTA_Version)t;
}

/*}}}  */
/*{{{  ATerm PTA_VersionToTerm(PTA_Version arg) */

ATerm PTA_VersionToTerm(PTA_Version arg)
{
  return (ATerm)arg;
}

/*}}}  */
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
/*{{{  PTA_Choices PTA_ChoicesFromTerm(ATerm t) */

PTA_Choices PTA_ChoicesFromTerm(ATerm t)
{
  return (PTA_Choices)t;
}

/*}}}  */
/*{{{  ATerm PTA_ChoicesToTerm(PTA_Choices arg) */

ATerm PTA_ChoicesToTerm(PTA_Choices arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_Choice PTA_ChoiceFromTerm(ATerm t) */

PTA_Choice PTA_ChoiceFromTerm(ATerm t)
{
  return (PTA_Choice)t;
}

/*}}}  */
/*{{{  ATerm PTA_ChoiceToTerm(PTA_Choice arg) */

ATerm PTA_ChoiceToTerm(PTA_Choice arg)
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
/*{{{  PTA_LookAhead PTA_LookAheadFromTerm(ATerm t) */

PTA_LookAhead PTA_LookAheadFromTerm(ATerm t)
{
  return (PTA_LookAhead)t;
}

/*}}}  */
/*{{{  ATerm PTA_LookAheadToTerm(PTA_LookAhead arg) */

ATerm PTA_LookAheadToTerm(PTA_LookAhead arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_CharClass PTA_CharClassFromTerm(ATerm t) */

PTA_CharClass PTA_CharClassFromTerm(ATerm t)
{
  return (PTA_CharClass)t;
}

/*}}}  */
/*{{{  ATerm PTA_CharClassToTerm(PTA_CharClass arg) */

ATerm PTA_CharClassToTerm(PTA_CharClass arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTA_LookAheads PTA_LookAheadsFromTerm(ATerm t) */

PTA_LookAheads PTA_LookAheadsFromTerm(ATerm t)
{
  return (PTA_LookAheads)t;
}

/*}}}  */
/*{{{  ATerm PTA_LookAheadsToTerm(PTA_LookAheads arg) */

ATerm PTA_LookAheadsToTerm(PTA_LookAheads arg)
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

/*{{{  PTA_Version PTA_makeVersionDefault() */

PTA_Version PTA_makeVersionDefault()
{
  return (PTA_Version)(ATerm)ATmakeInt(4);
}

/*}}}  */
/*{{{  PTA_ParseTable PTA_makeParseTableParseTable(PTA_Version version, int initialState, PTA_Labels labels, PTA_States states, PTA_Priorities priorities) */

PTA_ParseTable PTA_makeParseTableParseTable(PTA_Version version, int initialState, PTA_Labels labels, PTA_States states, PTA_Priorities priorities)
{
  return (PTA_ParseTable)(ATerm)ATmakeAppl5(PTA_afun0, (ATerm)version, (ATerm)ATmakeInt(initialState), (ATerm)labels, (ATerm)ATmakeAppl1(PTA_afun1, (ATerm)states), (ATerm)ATmakeAppl1(PTA_afun2, (ATerm)priorities));
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
/*{{{  PTA_Action PTA_makeActionDefault(PTA_CharRanges ranges, PTA_Choices choices) */

PTA_Action PTA_makeActionDefault(PTA_CharRanges ranges, PTA_Choices choices)
{
  return (PTA_Action)(ATerm)ATmakeAppl2(PTA_afun6, (ATerm)ranges, (ATerm)choices);
}

/*}}}  */
/*{{{  PTA_Choices PTA_makeChoicesEmpty() */

PTA_Choices PTA_makeChoicesEmpty()
{
  return (PTA_Choices)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTA_Choices PTA_makeChoicesList(PTA_Choice head, PTA_Choices tail) */

PTA_Choices PTA_makeChoicesList(PTA_Choice head, PTA_Choices tail)
{
  return (PTA_Choices)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  PTA_Choice PTA_makeChoiceReduce(int length, int label, PTA_SpecialAttr specialAttr) */

PTA_Choice PTA_makeChoiceReduce(int length, int label, PTA_SpecialAttr specialAttr)
{
  return (PTA_Choice)(ATerm)ATmakeAppl3(PTA_afun7, (ATerm)ATmakeInt(length), (ATerm)ATmakeInt(label), (ATerm)specialAttr);
}

/*}}}  */
/*{{{  PTA_Choice PTA_makeChoiceLookaheadReduce(int length, int label, PTA_SpecialAttr specialAttr, PTA_LookAheads lookaheads) */

PTA_Choice PTA_makeChoiceLookaheadReduce(int length, int label, PTA_SpecialAttr specialAttr, PTA_LookAheads lookaheads)
{
  return (PTA_Choice)(ATerm)ATmakeAppl4(PTA_afun8, (ATerm)ATmakeInt(length), (ATerm)ATmakeInt(label), (ATerm)specialAttr, (ATerm)lookaheads);
}

/*}}}  */
/*{{{  PTA_Choice PTA_makeChoiceShift(int stateNumber) */

PTA_Choice PTA_makeChoiceShift(int stateNumber)
{
  return (PTA_Choice)(ATerm)ATmakeAppl1(PTA_afun9, (ATerm)ATmakeInt(stateNumber));
}

/*}}}  */
/*{{{  PTA_Choice PTA_makeChoiceAccept() */

PTA_Choice PTA_makeChoiceAccept()
{
  return (PTA_Choice)(ATerm)ATmakeAppl0(PTA_afun10);
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
/*{{{  PTA_LookAhead PTA_makeLookAheadDefault(PTA_CharClass charClass, PTA_LookAheads lookaheads) */

PTA_LookAhead PTA_makeLookAheadDefault(PTA_CharClass charClass, PTA_LookAheads lookaheads)
{
  return (PTA_LookAhead)(ATerm)ATmakeAppl2(PTA_afun11, (ATerm)charClass, (ATerm)lookaheads);
}

/*}}}  */
/*{{{  PTA_CharClass PTA_makeCharClassDefault(PTA_CharRanges ranges) */

PTA_CharClass PTA_makeCharClassDefault(PTA_CharRanges ranges)
{
  return (PTA_CharClass)(ATerm)ATmakeAppl1(PTA_afun12, (ATerm)ranges);
}

/*}}}  */
/*{{{  PTA_LookAheads PTA_makeLookAheadsEmpty() */

PTA_LookAheads PTA_makeLookAheadsEmpty()
{
  return (PTA_LookAheads)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTA_LookAheads PTA_makeLookAheadsList(PTA_LookAhead head, PTA_LookAheads tail) */

PTA_LookAheads PTA_makeLookAheadsList(PTA_LookAhead head, PTA_LookAheads tail)
{
  return (PTA_LookAheads)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
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
  return (PTA_Priority)(ATerm)ATmakeAppl2(PTA_afun13, (ATerm)ATmakeInt(label1), (ATerm)ATmakeInt(label2));
}

/*}}}  */
/*{{{  PTA_Priority PTA_makePriorityRight(int label1, int label2) */

PTA_Priority PTA_makePriorityRight(int label1, int label2)
{
  return (PTA_Priority)(ATerm)ATmakeAppl2(PTA_afun14, (ATerm)ATmakeInt(label1), (ATerm)ATmakeInt(label2));
}

/*}}}  */
/*{{{  PTA_Priority PTA_makePriorityNonAssoc(int label1, int label2) */

PTA_Priority PTA_makePriorityNonAssoc(int label1, int label2)
{
  return (PTA_Priority)(ATerm)ATmakeAppl2(PTA_afun15, (ATerm)ATmakeInt(label1), (ATerm)ATmakeInt(label2));
}

/*}}}  */
/*{{{  PTA_Priority PTA_makePriorityGreater(int label1, int label2) */

PTA_Priority PTA_makePriorityGreater(int label1, int label2)
{
  return (PTA_Priority)(ATerm)ATmakeAppl2(PTA_afun16, (ATerm)ATmakeInt(label1), (ATerm)ATmakeInt(label2));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool PTA_isEqualVersion(PTA_Version arg0, PTA_Version arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

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

ATbool PTA_isEqualChoices(PTA_Choices arg0, PTA_Choices arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualChoice(PTA_Choice arg0, PTA_Choice arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualSpecialAttr(PTA_SpecialAttr arg0, PTA_SpecialAttr arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualLookAhead(PTA_LookAhead arg0, PTA_LookAhead arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualCharClass(PTA_CharClass arg0, PTA_CharClass arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTA_isEqualLookAheads(PTA_LookAheads arg0, PTA_LookAheads arg1)
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
/*{{{  PTA_Version accessors */

/*{{{  ATbool PTA_isValidVersion(PTA_Version arg) */

ATbool PTA_isValidVersion(PTA_Version arg)
{
  if (PTA_isVersionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isVersionDefault(PTA_Version arg) */

inline ATbool PTA_isVersionDefault(PTA_Version arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternVersionDefault));
#endif
  return ATtrue;
}

/*}}}  */

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
/*{{{  PTA_Version PTA_getParseTableVersion(PTA_ParseTable arg) */

PTA_Version PTA_getParseTableVersion(PTA_ParseTable arg)
{
  
    return (PTA_Version)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PTA_ParseTable PTA_setParseTableVersion(PTA_ParseTable arg, PTA_Version version) */

PTA_ParseTable PTA_setParseTableVersion(PTA_ParseTable arg, PTA_Version version)
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
/*{{{  int PTA_getParseTableInitialState(PTA_ParseTable arg) */

int PTA_getParseTableInitialState(PTA_ParseTable arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTA_ParseTable PTA_setParseTableInitialState(PTA_ParseTable arg, int initialState) */

PTA_ParseTable PTA_setParseTableInitialState(PTA_ParseTable arg, int initialState)
{
  if (PTA_isParseTableParseTable(arg)) {
    return (PTA_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(initialState), 1);
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
/*{{{  ATbool PTA_hasActionChoices(PTA_Action arg) */

ATbool PTA_hasActionChoices(PTA_Action arg)
{
  if (PTA_isActionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Choices PTA_getActionChoices(PTA_Action arg) */

PTA_Choices PTA_getActionChoices(PTA_Action arg)
{
  
    return (PTA_Choices)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  PTA_Action PTA_setActionChoices(PTA_Action arg, PTA_Choices choices) */

PTA_Action PTA_setActionChoices(PTA_Action arg, PTA_Choices choices)
{
  if (PTA_isActionDefault(arg)) {
    return (PTA_Action)ATsetArgument((ATermAppl)arg, (ATerm)choices, 1);
  }

  ATabort("Action has no Choices: %t\n", arg);
  return (PTA_Action)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_Choices accessors */

/*{{{  ATbool PTA_isValidChoices(PTA_Choices arg) */

ATbool PTA_isValidChoices(PTA_Choices arg)
{
  if (PTA_isChoicesEmpty(arg)) {
    return ATtrue;
  }
  else if (PTA_isChoicesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isChoicesEmpty(PTA_Choices arg) */

inline ATbool PTA_isChoicesEmpty(PTA_Choices arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternChoicesEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isChoicesList(PTA_Choices arg) */

inline ATbool PTA_isChoicesList(PTA_Choices arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternChoicesList, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasChoicesHead(PTA_Choices arg) */

ATbool PTA_hasChoicesHead(PTA_Choices arg)
{
  if (PTA_isChoicesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Choice PTA_getChoicesHead(PTA_Choices arg) */

PTA_Choice PTA_getChoicesHead(PTA_Choices arg)
{
  
    return (PTA_Choice)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_Choices PTA_setChoicesHead(PTA_Choices arg, PTA_Choice head) */

PTA_Choices PTA_setChoicesHead(PTA_Choices arg, PTA_Choice head)
{
  if (PTA_isChoicesList(arg)) {
    return (PTA_Choices)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Choices has no Head: %t\n", arg);
  return (PTA_Choices)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasChoicesTail(PTA_Choices arg) */

ATbool PTA_hasChoicesTail(PTA_Choices arg)
{
  if (PTA_isChoicesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_Choices PTA_getChoicesTail(PTA_Choices arg) */

PTA_Choices PTA_getChoicesTail(PTA_Choices arg)
{
  
    return (PTA_Choices)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_Choices PTA_setChoicesTail(PTA_Choices arg, PTA_Choices tail) */

PTA_Choices PTA_setChoicesTail(PTA_Choices arg, PTA_Choices tail)
{
  if (PTA_isChoicesList(arg)) {
    return (PTA_Choices)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Choices has no Tail: %t\n", arg);
  return (PTA_Choices)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_Choice accessors */

/*{{{  ATbool PTA_isValidChoice(PTA_Choice arg) */

ATbool PTA_isValidChoice(PTA_Choice arg)
{
  if (PTA_isChoiceReduce(arg)) {
    return ATtrue;
  }
  else if (PTA_isChoiceLookaheadReduce(arg)) {
    return ATtrue;
  }
  else if (PTA_isChoiceShift(arg)) {
    return ATtrue;
  }
  else if (PTA_isChoiceAccept(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isChoiceReduce(PTA_Choice arg) */

inline ATbool PTA_isChoiceReduce(PTA_Choice arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(PTA_patternChoiceReduce)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternChoiceReduce, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isChoiceLookaheadReduce(PTA_Choice arg) */

inline ATbool PTA_isChoiceLookaheadReduce(PTA_Choice arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(PTA_patternChoiceLookaheadReduce)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternChoiceLookaheadReduce, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isChoiceShift(PTA_Choice arg) */

inline ATbool PTA_isChoiceShift(PTA_Choice arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(PTA_patternChoiceShift)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternChoiceShift, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isChoiceAccept(PTA_Choice arg) */

inline ATbool PTA_isChoiceAccept(PTA_Choice arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(PTA_patternChoiceAccept)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternChoiceAccept));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasChoiceLength(PTA_Choice arg) */

ATbool PTA_hasChoiceLength(PTA_Choice arg)
{
  if (PTA_isChoiceReduce(arg)) {
    return ATtrue;
  }
  else if (PTA_isChoiceLookaheadReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PTA_getChoiceLength(PTA_Choice arg) */

int PTA_getChoiceLength(PTA_Choice arg)
{
  if (PTA_isChoiceReduce(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
  }
  else 
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  PTA_Choice PTA_setChoiceLength(PTA_Choice arg, int length) */

PTA_Choice PTA_setChoiceLength(PTA_Choice arg, int length)
{
  if (PTA_isChoiceReduce(arg)) {
    return (PTA_Choice)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(length), 0);
  }
  else if (PTA_isChoiceLookaheadReduce(arg)) {
    return (PTA_Choice)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(length), 0);
  }

  ATabort("Choice has no Length: %t\n", arg);
  return (PTA_Choice)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasChoiceLabel(PTA_Choice arg) */

ATbool PTA_hasChoiceLabel(PTA_Choice arg)
{
  if (PTA_isChoiceReduce(arg)) {
    return ATtrue;
  }
  else if (PTA_isChoiceLookaheadReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PTA_getChoiceLabel(PTA_Choice arg) */

int PTA_getChoiceLabel(PTA_Choice arg)
{
  if (PTA_isChoiceReduce(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTA_Choice PTA_setChoiceLabel(PTA_Choice arg, int label) */

PTA_Choice PTA_setChoiceLabel(PTA_Choice arg, int label)
{
  if (PTA_isChoiceReduce(arg)) {
    return (PTA_Choice)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(label), 1);
  }
  else if (PTA_isChoiceLookaheadReduce(arg)) {
    return (PTA_Choice)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(label), 1);
  }

  ATabort("Choice has no Label: %t\n", arg);
  return (PTA_Choice)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasChoiceSpecialAttr(PTA_Choice arg) */

ATbool PTA_hasChoiceSpecialAttr(PTA_Choice arg)
{
  if (PTA_isChoiceReduce(arg)) {
    return ATtrue;
  }
  else if (PTA_isChoiceLookaheadReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_SpecialAttr PTA_getChoiceSpecialAttr(PTA_Choice arg) */

PTA_SpecialAttr PTA_getChoiceSpecialAttr(PTA_Choice arg)
{
  if (PTA_isChoiceReduce(arg)) {
    return (PTA_SpecialAttr)ATgetArgument((ATermAppl)arg, 2);
  }
  else 
    return (PTA_SpecialAttr)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  PTA_Choice PTA_setChoiceSpecialAttr(PTA_Choice arg, PTA_SpecialAttr specialAttr) */

PTA_Choice PTA_setChoiceSpecialAttr(PTA_Choice arg, PTA_SpecialAttr specialAttr)
{
  if (PTA_isChoiceReduce(arg)) {
    return (PTA_Choice)ATsetArgument((ATermAppl)arg, (ATerm)specialAttr, 2);
  }
  else if (PTA_isChoiceLookaheadReduce(arg)) {
    return (PTA_Choice)ATsetArgument((ATermAppl)arg, (ATerm)specialAttr, 2);
  }

  ATabort("Choice has no SpecialAttr: %t\n", arg);
  return (PTA_Choice)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasChoiceLookaheads(PTA_Choice arg) */

ATbool PTA_hasChoiceLookaheads(PTA_Choice arg)
{
  if (PTA_isChoiceLookaheadReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_LookAheads PTA_getChoiceLookaheads(PTA_Choice arg) */

PTA_LookAheads PTA_getChoiceLookaheads(PTA_Choice arg)
{
  
    return (PTA_LookAheads)ATgetArgument((ATermAppl)arg, 3);
}

/*}}}  */
/*{{{  PTA_Choice PTA_setChoiceLookaheads(PTA_Choice arg, PTA_LookAheads lookaheads) */

PTA_Choice PTA_setChoiceLookaheads(PTA_Choice arg, PTA_LookAheads lookaheads)
{
  if (PTA_isChoiceLookaheadReduce(arg)) {
    return (PTA_Choice)ATsetArgument((ATermAppl)arg, (ATerm)lookaheads, 3);
  }

  ATabort("Choice has no Lookaheads: %t\n", arg);
  return (PTA_Choice)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasChoiceStateNumber(PTA_Choice arg) */

ATbool PTA_hasChoiceStateNumber(PTA_Choice arg)
{
  if (PTA_isChoiceShift(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PTA_getChoiceStateNumber(PTA_Choice arg) */

int PTA_getChoiceStateNumber(PTA_Choice arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  PTA_Choice PTA_setChoiceStateNumber(PTA_Choice arg, int stateNumber) */

PTA_Choice PTA_setChoiceStateNumber(PTA_Choice arg, int stateNumber)
{
  if (PTA_isChoiceShift(arg)) {
    return (PTA_Choice)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(stateNumber), 0);
  }

  ATabort("Choice has no StateNumber: %t\n", arg);
  return (PTA_Choice)NULL;
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
/*{{{  PTA_LookAhead accessors */

/*{{{  ATbool PTA_isValidLookAhead(PTA_LookAhead arg) */

ATbool PTA_isValidLookAhead(PTA_LookAhead arg)
{
  if (PTA_isLookAheadDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isLookAheadDefault(PTA_LookAhead arg) */

inline ATbool PTA_isLookAheadDefault(PTA_LookAhead arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternLookAheadDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasLookAheadCharClass(PTA_LookAhead arg) */

ATbool PTA_hasLookAheadCharClass(PTA_LookAhead arg)
{
  if (PTA_isLookAheadDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_CharClass PTA_getLookAheadCharClass(PTA_LookAhead arg) */

PTA_CharClass PTA_getLookAheadCharClass(PTA_LookAhead arg)
{
  
    return (PTA_CharClass)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PTA_LookAhead PTA_setLookAheadCharClass(PTA_LookAhead arg, PTA_CharClass charClass) */

PTA_LookAhead PTA_setLookAheadCharClass(PTA_LookAhead arg, PTA_CharClass charClass)
{
  if (PTA_isLookAheadDefault(arg)) {
    return (PTA_LookAhead)ATsetArgument((ATermAppl)arg, (ATerm)charClass, 0);
  }

  ATabort("LookAhead has no CharClass: %t\n", arg);
  return (PTA_LookAhead)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasLookAheadLookaheads(PTA_LookAhead arg) */

ATbool PTA_hasLookAheadLookaheads(PTA_LookAhead arg)
{
  if (PTA_isLookAheadDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_LookAheads PTA_getLookAheadLookaheads(PTA_LookAhead arg) */

PTA_LookAheads PTA_getLookAheadLookaheads(PTA_LookAhead arg)
{
  
    return (PTA_LookAheads)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  PTA_LookAhead PTA_setLookAheadLookaheads(PTA_LookAhead arg, PTA_LookAheads lookaheads) */

PTA_LookAhead PTA_setLookAheadLookaheads(PTA_LookAhead arg, PTA_LookAheads lookaheads)
{
  if (PTA_isLookAheadDefault(arg)) {
    return (PTA_LookAhead)ATsetArgument((ATermAppl)arg, (ATerm)lookaheads, 1);
  }

  ATabort("LookAhead has no Lookaheads: %t\n", arg);
  return (PTA_LookAhead)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_CharClass accessors */

/*{{{  ATbool PTA_isValidCharClass(PTA_CharClass arg) */

ATbool PTA_isValidCharClass(PTA_CharClass arg)
{
  if (PTA_isCharClassDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isCharClassDefault(PTA_CharClass arg) */

inline ATbool PTA_isCharClassDefault(PTA_CharClass arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternCharClassDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasCharClassRanges(PTA_CharClass arg) */

ATbool PTA_hasCharClassRanges(PTA_CharClass arg)
{
  if (PTA_isCharClassDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_CharRanges PTA_getCharClassRanges(PTA_CharClass arg) */

PTA_CharRanges PTA_getCharClassRanges(PTA_CharClass arg)
{
  
    return (PTA_CharRanges)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PTA_CharClass PTA_setCharClassRanges(PTA_CharClass arg, PTA_CharRanges ranges) */

PTA_CharClass PTA_setCharClassRanges(PTA_CharClass arg, PTA_CharRanges ranges)
{
  if (PTA_isCharClassDefault(arg)) {
    return (PTA_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)ranges, 0);
  }

  ATabort("CharClass has no Ranges: %t\n", arg);
  return (PTA_CharClass)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTA_LookAheads accessors */

/*{{{  ATbool PTA_isValidLookAheads(PTA_LookAheads arg) */

ATbool PTA_isValidLookAheads(PTA_LookAheads arg)
{
  if (PTA_isLookAheadsEmpty(arg)) {
    return ATtrue;
  }
  else if (PTA_isLookAheadsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTA_isLookAheadsEmpty(PTA_LookAheads arg) */

inline ATbool PTA_isLookAheadsEmpty(PTA_LookAheads arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternLookAheadsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTA_isLookAheadsList(PTA_LookAheads arg) */

inline ATbool PTA_isLookAheadsList(PTA_LookAheads arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternLookAheadsList, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTA_hasLookAheadsHead(PTA_LookAheads arg) */

ATbool PTA_hasLookAheadsHead(PTA_LookAheads arg)
{
  if (PTA_isLookAheadsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_LookAhead PTA_getLookAheadsHead(PTA_LookAheads arg) */

PTA_LookAhead PTA_getLookAheadsHead(PTA_LookAheads arg)
{
  
    return (PTA_LookAhead)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_LookAheads PTA_setLookAheadsHead(PTA_LookAheads arg, PTA_LookAhead head) */

PTA_LookAheads PTA_setLookAheadsHead(PTA_LookAheads arg, PTA_LookAhead head)
{
  if (PTA_isLookAheadsList(arg)) {
    return (PTA_LookAheads)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("LookAheads has no Head: %t\n", arg);
  return (PTA_LookAheads)NULL;
}

/*}}}  */
/*{{{  ATbool PTA_hasLookAheadsTail(PTA_LookAheads arg) */

ATbool PTA_hasLookAheadsTail(PTA_LookAheads arg)
{
  if (PTA_isLookAheadsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTA_LookAheads PTA_getLookAheadsTail(PTA_LookAheads arg) */

PTA_LookAheads PTA_getLookAheadsTail(PTA_LookAheads arg)
{
  
    return (PTA_LookAheads)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  PTA_LookAheads PTA_setLookAheadsTail(PTA_LookAheads arg, PTA_LookAheads tail) */

PTA_LookAheads PTA_setLookAheadsTail(PTA_LookAheads arg, PTA_LookAheads tail)
{
  if (PTA_isLookAheadsList(arg)) {
    return (PTA_LookAheads)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("LookAheads has no Tail: %t\n", arg);
  return (PTA_LookAheads)NULL;
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
  else if (PTA_isPriorityNonAssoc(arg)) {
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
/*{{{  inline ATbool PTA_isPriorityNonAssoc(PTA_Priority arg) */

inline ATbool PTA_isPriorityNonAssoc(PTA_Priority arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(PTA_patternPriorityNonAssoc)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTA_patternPriorityNonAssoc, NULL, NULL));
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
  else if (PTA_isPriorityNonAssoc(arg)) {
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
  else if (PTA_isPriorityNonAssoc(arg)) {
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
  else if (PTA_isPriorityNonAssoc(arg)) {
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
  else if (PTA_isPriorityNonAssoc(arg)) {
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
  else if (PTA_isPriorityNonAssoc(arg)) {
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
  else if (PTA_isPriorityNonAssoc(arg)) {
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

/*{{{  PTA_Version PTA_visitVersion(PTA_Version arg) */

PTA_Version PTA_visitVersion(PTA_Version arg)
{
  if (PTA_isVersionDefault(arg)) {
    return PTA_makeVersionDefault();
  }
  ATabort("not a Version: %t\n", arg);
  return (PTA_Version)NULL;
}

/*}}}  */
/*{{{  PTA_ParseTable PTA_visitParseTable(PTA_ParseTable arg, PTA_Version (*acceptVersion)(PTA_Version), int (*acceptInitialState)(int), PTA_Labels (*acceptLabels)(PTA_Labels), PTA_States (*acceptStates)(PTA_States), PTA_Priorities (*acceptPriorities)(PTA_Priorities)) */

PTA_ParseTable PTA_visitParseTable(PTA_ParseTable arg, PTA_Version (*acceptVersion)(PTA_Version), int (*acceptInitialState)(int), PTA_Labels (*acceptLabels)(PTA_Labels), PTA_States (*acceptStates)(PTA_States), PTA_Priorities (*acceptPriorities)(PTA_Priorities))
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
/*{{{  PTA_Action PTA_visitAction(PTA_Action arg, PTA_CharRanges (*acceptRanges)(PTA_CharRanges), PTA_Choices (*acceptChoices)(PTA_Choices)) */

PTA_Action PTA_visitAction(PTA_Action arg, PTA_CharRanges (*acceptRanges)(PTA_CharRanges), PTA_Choices (*acceptChoices)(PTA_Choices))
{
  if (PTA_isActionDefault(arg)) {
    return PTA_makeActionDefault(
        acceptRanges ? acceptRanges(PTA_getActionRanges(arg)) : PTA_getActionRanges(arg),
        acceptChoices ? acceptChoices(PTA_getActionChoices(arg)) : PTA_getActionChoices(arg));
  }
  ATabort("not a Action: %t\n", arg);
  return (PTA_Action)NULL;
}

/*}}}  */
/*{{{  PTA_Choices PTA_visitChoices(PTA_Choices arg, PTA_Choice (*acceptHead)(PTA_Choice)) */

PTA_Choices PTA_visitChoices(PTA_Choices arg, PTA_Choice (*acceptHead)(PTA_Choice))
{
  if (PTA_isChoicesEmpty(arg)) {
    return PTA_makeChoicesEmpty();
  }
  if (PTA_isChoicesList(arg)) {
    return PTA_makeChoicesList(
        acceptHead ? acceptHead(PTA_getChoicesHead(arg)) : PTA_getChoicesHead(arg),
        PTA_visitChoices(PTA_getChoicesTail(arg), acceptHead));
  }
  ATabort("not a Choices: %t\n", arg);
  return (PTA_Choices)NULL;
}

/*}}}  */
/*{{{  PTA_Choice PTA_visitChoice(PTA_Choice arg, int (*acceptLength)(int), int (*acceptLabel)(int), PTA_SpecialAttr (*acceptSpecialAttr)(PTA_SpecialAttr), PTA_LookAheads (*acceptLookaheads)(PTA_LookAheads), int (*acceptStateNumber)(int)) */

PTA_Choice PTA_visitChoice(PTA_Choice arg, int (*acceptLength)(int), int (*acceptLabel)(int), PTA_SpecialAttr (*acceptSpecialAttr)(PTA_SpecialAttr), PTA_LookAheads (*acceptLookaheads)(PTA_LookAheads), int (*acceptStateNumber)(int))
{
  if (PTA_isChoiceReduce(arg)) {
    return PTA_makeChoiceReduce(
        acceptLength ? acceptLength(PTA_getChoiceLength(arg)) : PTA_getChoiceLength(arg),
        acceptLabel ? acceptLabel(PTA_getChoiceLabel(arg)) : PTA_getChoiceLabel(arg),
        acceptSpecialAttr ? acceptSpecialAttr(PTA_getChoiceSpecialAttr(arg)) : PTA_getChoiceSpecialAttr(arg));
  }
  if (PTA_isChoiceLookaheadReduce(arg)) {
    return PTA_makeChoiceLookaheadReduce(
        acceptLength ? acceptLength(PTA_getChoiceLength(arg)) : PTA_getChoiceLength(arg),
        acceptLabel ? acceptLabel(PTA_getChoiceLabel(arg)) : PTA_getChoiceLabel(arg),
        acceptSpecialAttr ? acceptSpecialAttr(PTA_getChoiceSpecialAttr(arg)) : PTA_getChoiceSpecialAttr(arg),
        acceptLookaheads ? acceptLookaheads(PTA_getChoiceLookaheads(arg)) : PTA_getChoiceLookaheads(arg));
  }
  if (PTA_isChoiceShift(arg)) {
    return PTA_makeChoiceShift(
        acceptStateNumber ? acceptStateNumber(PTA_getChoiceStateNumber(arg)) : PTA_getChoiceStateNumber(arg));
  }
  if (PTA_isChoiceAccept(arg)) {
    return PTA_makeChoiceAccept();
  }
  ATabort("not a Choice: %t\n", arg);
  return (PTA_Choice)NULL;
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
/*{{{  PTA_LookAhead PTA_visitLookAhead(PTA_LookAhead arg, PTA_CharClass (*acceptCharClass)(PTA_CharClass), PTA_LookAheads (*acceptLookaheads)(PTA_LookAheads)) */

PTA_LookAhead PTA_visitLookAhead(PTA_LookAhead arg, PTA_CharClass (*acceptCharClass)(PTA_CharClass), PTA_LookAheads (*acceptLookaheads)(PTA_LookAheads))
{
  if (PTA_isLookAheadDefault(arg)) {
    return PTA_makeLookAheadDefault(
        acceptCharClass ? acceptCharClass(PTA_getLookAheadCharClass(arg)) : PTA_getLookAheadCharClass(arg),
        acceptLookaheads ? acceptLookaheads(PTA_getLookAheadLookaheads(arg)) : PTA_getLookAheadLookaheads(arg));
  }
  ATabort("not a LookAhead: %t\n", arg);
  return (PTA_LookAhead)NULL;
}

/*}}}  */
/*{{{  PTA_CharClass PTA_visitCharClass(PTA_CharClass arg, PTA_CharRanges (*acceptRanges)(PTA_CharRanges)) */

PTA_CharClass PTA_visitCharClass(PTA_CharClass arg, PTA_CharRanges (*acceptRanges)(PTA_CharRanges))
{
  if (PTA_isCharClassDefault(arg)) {
    return PTA_makeCharClassDefault(
        acceptRanges ? acceptRanges(PTA_getCharClassRanges(arg)) : PTA_getCharClassRanges(arg));
  }
  ATabort("not a CharClass: %t\n", arg);
  return (PTA_CharClass)NULL;
}

/*}}}  */
/*{{{  PTA_LookAheads PTA_visitLookAheads(PTA_LookAheads arg, PTA_LookAhead (*acceptHead)(PTA_LookAhead)) */

PTA_LookAheads PTA_visitLookAheads(PTA_LookAheads arg, PTA_LookAhead (*acceptHead)(PTA_LookAhead))
{
  if (PTA_isLookAheadsEmpty(arg)) {
    return PTA_makeLookAheadsEmpty();
  }
  if (PTA_isLookAheadsList(arg)) {
    return PTA_makeLookAheadsList(
        acceptHead ? acceptHead(PTA_getLookAheadsHead(arg)) : PTA_getLookAheadsHead(arg),
        PTA_visitLookAheads(PTA_getLookAheadsTail(arg), acceptHead));
  }
  ATabort("not a LookAheads: %t\n", arg);
  return (PTA_LookAheads)NULL;
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
  if (PTA_isPriorityNonAssoc(arg)) {
    return PTA_makePriorityNonAssoc(
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
