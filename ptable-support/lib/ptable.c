#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ptable.h"

ATerm PTBL_stringToChars(const char *str) {
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

ATerm PTBL_byteToChar(char ch) {
    return (ATerm) ATmakeInt(ch);
}

char *PTBL_charsToString(ATerm arg) {
  ATermList list = (ATermList) arg;
  int len = ATgetLength(list);
  int i;
  char *str;

  str = (char *) malloc(len+1);
  if (str == NULL) {
      return NULL;
  }

  for (i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    str[i] = (char) ATgetInt((ATermInt) ATgetFirst(list));
  }
  str[i] = '\0';

  return str;
}

char PTBL_charToByte(ATerm arg) {
    return (char) ATgetInt((ATermInt) arg);
}


typedef struct ATerm _PTBL_Production;
typedef struct ATerm _PTBL_CharRanges;
typedef struct ATerm _PTBL_Version;
typedef struct ATerm _PTBL_ParseTable;
typedef struct ATerm _PTBL_Labels;
typedef struct ATerm _PTBL_Label;
typedef struct ATerm _PTBL_States;
typedef struct ATerm _PTBL_State;
typedef struct ATerm _PTBL_Gotos;
typedef struct ATerm _PTBL_Goto;
typedef struct ATerm _PTBL_Actions;
typedef struct ATerm _PTBL_Action;
typedef struct ATerm _PTBL_Choices;
typedef struct ATerm _PTBL_Choice;
typedef struct ATerm _PTBL_SpecialAttr;
typedef struct ATerm _PTBL_LookAheads;
typedef struct ATerm _PTBL_LookAhead;
typedef struct ATerm _PTBL_CharClass;
typedef struct ATerm _PTBL_Priorities;
typedef struct ATerm _PTBL_Priority;

void PTBL_initPtableApi(void) {
  init_ptable_dict();
}

void PTBL_protectProduction(PTBL_Production *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectProduction(PTBL_Production *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectCharRanges(PTBL_CharRanges *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectCharRanges(PTBL_CharRanges *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectVersion(PTBL_Version *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectVersion(PTBL_Version *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectParseTable(PTBL_ParseTable *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectParseTable(PTBL_ParseTable *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectLabels(PTBL_Labels *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectLabels(PTBL_Labels *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectLabel(PTBL_Label *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectLabel(PTBL_Label *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectStates(PTBL_States *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectStates(PTBL_States *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectState(PTBL_State *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectState(PTBL_State *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectGotos(PTBL_Gotos *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectGotos(PTBL_Gotos *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectGoto(PTBL_Goto *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectGoto(PTBL_Goto *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectActions(PTBL_Actions *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectActions(PTBL_Actions *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectAction(PTBL_Action *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectAction(PTBL_Action *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectChoices(PTBL_Choices *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectChoices(PTBL_Choices *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectChoice(PTBL_Choice *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectChoice(PTBL_Choice *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectSpecialAttr(PTBL_SpecialAttr *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectSpecialAttr(PTBL_SpecialAttr *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectLookAheads(PTBL_LookAheads *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectLookAheads(PTBL_LookAheads *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectLookAhead(PTBL_LookAhead *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectLookAhead(PTBL_LookAhead *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectCharClass(PTBL_CharClass *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectCharClass(PTBL_CharClass *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectPriorities(PTBL_Priorities *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectPriorities(PTBL_Priorities *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void PTBL_protectPriority(PTBL_Priority *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void PTBL_unprotectPriority(PTBL_Priority *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

PTBL_Production PTBL_ProductionFromTerm(ATerm t) {
  return (PTBL_Production)t;
}

ATerm PTBL_ProductionToTerm(PTBL_Production arg) {
  return (ATerm)arg;
}

PTBL_CharRanges PTBL_CharRangesFromTerm(ATerm t) {
  return (PTBL_CharRanges)t;
}

ATerm PTBL_CharRangesToTerm(PTBL_CharRanges arg) {
  return (ATerm)arg;
}

PTBL_Version PTBL_VersionFromTerm(ATerm t) {
  return (PTBL_Version)t;
}

ATerm PTBL_VersionToTerm(PTBL_Version arg) {
  return (ATerm)arg;
}

PTBL_ParseTable PTBL_ParseTableFromTerm(ATerm t) {
  return (PTBL_ParseTable)t;
}

ATerm PTBL_ParseTableToTerm(PTBL_ParseTable arg) {
  return (ATerm)arg;
}

PTBL_Labels PTBL_LabelsFromTerm(ATerm t) {
  return (PTBL_Labels)t;
}

ATerm PTBL_LabelsToTerm(PTBL_Labels arg) {
  return (ATerm)arg;
}

PTBL_Label PTBL_LabelFromTerm(ATerm t) {
  return (PTBL_Label)t;
}

ATerm PTBL_LabelToTerm(PTBL_Label arg) {
  return (ATerm)arg;
}

PTBL_States PTBL_StatesFromTerm(ATerm t) {
  return (PTBL_States)t;
}

ATerm PTBL_StatesToTerm(PTBL_States arg) {
  return (ATerm)arg;
}

PTBL_State PTBL_StateFromTerm(ATerm t) {
  return (PTBL_State)t;
}

ATerm PTBL_StateToTerm(PTBL_State arg) {
  return (ATerm)arg;
}

PTBL_Gotos PTBL_GotosFromTerm(ATerm t) {
  return (PTBL_Gotos)t;
}

ATerm PTBL_GotosToTerm(PTBL_Gotos arg) {
  return (ATerm)arg;
}

PTBL_Goto PTBL_GotoFromTerm(ATerm t) {
  return (PTBL_Goto)t;
}

ATerm PTBL_GotoToTerm(PTBL_Goto arg) {
  return (ATerm)arg;
}

PTBL_Actions PTBL_ActionsFromTerm(ATerm t) {
  return (PTBL_Actions)t;
}

ATerm PTBL_ActionsToTerm(PTBL_Actions arg) {
  return (ATerm)arg;
}

PTBL_Action PTBL_ActionFromTerm(ATerm t) {
  return (PTBL_Action)t;
}

ATerm PTBL_ActionToTerm(PTBL_Action arg) {
  return (ATerm)arg;
}

PTBL_Choices PTBL_ChoicesFromTerm(ATerm t) {
  return (PTBL_Choices)t;
}

ATerm PTBL_ChoicesToTerm(PTBL_Choices arg) {
  return (ATerm)arg;
}

PTBL_Choice PTBL_ChoiceFromTerm(ATerm t) {
  return (PTBL_Choice)t;
}

ATerm PTBL_ChoiceToTerm(PTBL_Choice arg) {
  return (ATerm)arg;
}

PTBL_SpecialAttr PTBL_SpecialAttrFromTerm(ATerm t) {
  return (PTBL_SpecialAttr)t;
}

ATerm PTBL_SpecialAttrToTerm(PTBL_SpecialAttr arg) {
  return (ATerm)arg;
}

PTBL_LookAheads PTBL_LookAheadsFromTerm(ATerm t) {
  return (PTBL_LookAheads)t;
}

ATerm PTBL_LookAheadsToTerm(PTBL_LookAheads arg) {
  return (ATerm)arg;
}

PTBL_LookAhead PTBL_LookAheadFromTerm(ATerm t) {
  return (PTBL_LookAhead)t;
}

ATerm PTBL_LookAheadToTerm(PTBL_LookAhead arg) {
  return (ATerm)arg;
}

PTBL_CharClass PTBL_CharClassFromTerm(ATerm t) {
  return (PTBL_CharClass)t;
}

ATerm PTBL_CharClassToTerm(PTBL_CharClass arg) {
  return (ATerm)arg;
}

PTBL_Priorities PTBL_PrioritiesFromTerm(ATerm t) {
  return (PTBL_Priorities)t;
}

ATerm PTBL_PrioritiesToTerm(PTBL_Priorities arg) {
  return (ATerm)arg;
}

PTBL_Priority PTBL_PriorityFromTerm(ATerm t) {
  return (PTBL_Priority)t;
}

ATerm PTBL_PriorityToTerm(PTBL_Priority arg) {
  return (ATerm)arg;
}

int PTBL_getLabelsLength (PTBL_Labels arg) {
  return ATgetLength((ATermList) arg);
}

PTBL_Labels PTBL_reverseLabels(PTBL_Labels arg) {
  return (PTBL_Labels) ATreverse((ATermList) arg);
}

PTBL_Labels PTBL_appendLabels(PTBL_Labels arg, PTBL_Label elem) {
  return (PTBL_Labels) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

PTBL_Labels PTBL_concatLabels(PTBL_Labels arg0, PTBL_Labels arg1) {
  return (PTBL_Labels) ATconcat((ATermList) arg0, (ATermList) arg1);
}

PTBL_Labels PTBL_sliceLabels(PTBL_Labels arg, int start, int end) {
  return (PTBL_Labels) ATgetSlice((ATermList) arg, start, end);
}

PTBL_Label PTBL_getLabelsLabelAt(PTBL_Labels arg, int index) {
 return (PTBL_Label)ATelementAt((ATermList) arg,index);
}

PTBL_Labels PTBL_replaceLabelsLabelAt(PTBL_Labels arg, PTBL_Label elem, int index) {
 return (PTBL_Labels) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

PTBL_Labels PTBL_makeLabels2(PTBL_Label elem1, PTBL_Label elem2) {
  return (PTBL_Labels) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}

PTBL_Labels PTBL_makeLabels3(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3) {
  return (PTBL_Labels) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}

PTBL_Labels PTBL_makeLabels4(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3, PTBL_Label elem4) {
  return (PTBL_Labels) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}

PTBL_Labels PTBL_makeLabels5(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3, PTBL_Label elem4, PTBL_Label elem5) {
  return (PTBL_Labels) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}

PTBL_Labels PTBL_makeLabels6(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3, PTBL_Label elem4, PTBL_Label elem5, PTBL_Label elem6) {
  return (PTBL_Labels) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

int PTBL_getStatesLength (PTBL_States arg) {
  return ATgetLength((ATermList) arg);
}

PTBL_States PTBL_reverseStates(PTBL_States arg) {
  return (PTBL_States) ATreverse((ATermList) arg);
}

PTBL_States PTBL_appendStates(PTBL_States arg, PTBL_State elem) {
  return (PTBL_States) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

PTBL_States PTBL_concatStates(PTBL_States arg0, PTBL_States arg1) {
  return (PTBL_States) ATconcat((ATermList) arg0, (ATermList) arg1);
}

PTBL_States PTBL_sliceStates(PTBL_States arg, int start, int end) {
  return (PTBL_States) ATgetSlice((ATermList) arg, start, end);
}

PTBL_State PTBL_getStatesStateAt(PTBL_States arg, int index) {
 return (PTBL_State)ATelementAt((ATermList) arg,index);
}

PTBL_States PTBL_replaceStatesStateAt(PTBL_States arg, PTBL_State elem, int index) {
 return (PTBL_States) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

PTBL_States PTBL_makeStates2(PTBL_State elem1, PTBL_State elem2) {
  return (PTBL_States) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}

PTBL_States PTBL_makeStates3(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3) {
  return (PTBL_States) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}

PTBL_States PTBL_makeStates4(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3, PTBL_State elem4) {
  return (PTBL_States) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}

PTBL_States PTBL_makeStates5(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3, PTBL_State elem4, PTBL_State elem5) {
  return (PTBL_States) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}

PTBL_States PTBL_makeStates6(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3, PTBL_State elem4, PTBL_State elem5, PTBL_State elem6) {
  return (PTBL_States) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

int PTBL_getGotosLength (PTBL_Gotos arg) {
  return ATgetLength((ATermList) arg);
}

PTBL_Gotos PTBL_reverseGotos(PTBL_Gotos arg) {
  return (PTBL_Gotos) ATreverse((ATermList) arg);
}

PTBL_Gotos PTBL_appendGotos(PTBL_Gotos arg, PTBL_Goto elem) {
  return (PTBL_Gotos) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

PTBL_Gotos PTBL_concatGotos(PTBL_Gotos arg0, PTBL_Gotos arg1) {
  return (PTBL_Gotos) ATconcat((ATermList) arg0, (ATermList) arg1);
}

PTBL_Gotos PTBL_sliceGotos(PTBL_Gotos arg, int start, int end) {
  return (PTBL_Gotos) ATgetSlice((ATermList) arg, start, end);
}

PTBL_Goto PTBL_getGotosGotoAt(PTBL_Gotos arg, int index) {
 return (PTBL_Goto)ATelementAt((ATermList) arg,index);
}

PTBL_Gotos PTBL_replaceGotosGotoAt(PTBL_Gotos arg, PTBL_Goto elem, int index) {
 return (PTBL_Gotos) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

PTBL_Gotos PTBL_makeGotos2(PTBL_Goto elem1, PTBL_Goto elem2) {
  return (PTBL_Gotos) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}

PTBL_Gotos PTBL_makeGotos3(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3) {
  return (PTBL_Gotos) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}

PTBL_Gotos PTBL_makeGotos4(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3, PTBL_Goto elem4) {
  return (PTBL_Gotos) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}

PTBL_Gotos PTBL_makeGotos5(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3, PTBL_Goto elem4, PTBL_Goto elem5) {
  return (PTBL_Gotos) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}

PTBL_Gotos PTBL_makeGotos6(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3, PTBL_Goto elem4, PTBL_Goto elem5, PTBL_Goto elem6) {
  return (PTBL_Gotos) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

int PTBL_getActionsLength (PTBL_Actions arg) {
  return ATgetLength((ATermList) arg);
}

PTBL_Actions PTBL_reverseActions(PTBL_Actions arg) {
  return (PTBL_Actions) ATreverse((ATermList) arg);
}

PTBL_Actions PTBL_appendActions(PTBL_Actions arg, PTBL_Action elem) {
  return (PTBL_Actions) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

PTBL_Actions PTBL_concatActions(PTBL_Actions arg0, PTBL_Actions arg1) {
  return (PTBL_Actions) ATconcat((ATermList) arg0, (ATermList) arg1);
}

PTBL_Actions PTBL_sliceActions(PTBL_Actions arg, int start, int end) {
  return (PTBL_Actions) ATgetSlice((ATermList) arg, start, end);
}

PTBL_Action PTBL_getActionsActionAt(PTBL_Actions arg, int index) {
 return (PTBL_Action)ATelementAt((ATermList) arg,index);
}

PTBL_Actions PTBL_replaceActionsActionAt(PTBL_Actions arg, PTBL_Action elem, int index) {
 return (PTBL_Actions) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

PTBL_Actions PTBL_makeActions2(PTBL_Action elem1, PTBL_Action elem2) {
  return (PTBL_Actions) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}

PTBL_Actions PTBL_makeActions3(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3) {
  return (PTBL_Actions) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}

PTBL_Actions PTBL_makeActions4(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3, PTBL_Action elem4) {
  return (PTBL_Actions) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}

PTBL_Actions PTBL_makeActions5(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3, PTBL_Action elem4, PTBL_Action elem5) {
  return (PTBL_Actions) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}

PTBL_Actions PTBL_makeActions6(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3, PTBL_Action elem4, PTBL_Action elem5, PTBL_Action elem6) {
  return (PTBL_Actions) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

int PTBL_getChoicesLength (PTBL_Choices arg) {
  return ATgetLength((ATermList) arg);
}

PTBL_Choices PTBL_reverseChoices(PTBL_Choices arg) {
  return (PTBL_Choices) ATreverse((ATermList) arg);
}

PTBL_Choices PTBL_appendChoices(PTBL_Choices arg, PTBL_Choice elem) {
  return (PTBL_Choices) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

PTBL_Choices PTBL_concatChoices(PTBL_Choices arg0, PTBL_Choices arg1) {
  return (PTBL_Choices) ATconcat((ATermList) arg0, (ATermList) arg1);
}

PTBL_Choices PTBL_sliceChoices(PTBL_Choices arg, int start, int end) {
  return (PTBL_Choices) ATgetSlice((ATermList) arg, start, end);
}

PTBL_Choice PTBL_getChoicesChoiceAt(PTBL_Choices arg, int index) {
 return (PTBL_Choice)ATelementAt((ATermList) arg,index);
}

PTBL_Choices PTBL_replaceChoicesChoiceAt(PTBL_Choices arg, PTBL_Choice elem, int index) {
 return (PTBL_Choices) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

PTBL_Choices PTBL_makeChoices2(PTBL_Choice elem1, PTBL_Choice elem2) {
  return (PTBL_Choices) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}

PTBL_Choices PTBL_makeChoices3(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3) {
  return (PTBL_Choices) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}

PTBL_Choices PTBL_makeChoices4(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3, PTBL_Choice elem4) {
  return (PTBL_Choices) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}

PTBL_Choices PTBL_makeChoices5(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3, PTBL_Choice elem4, PTBL_Choice elem5) {
  return (PTBL_Choices) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}

PTBL_Choices PTBL_makeChoices6(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3, PTBL_Choice elem4, PTBL_Choice elem5, PTBL_Choice elem6) {
  return (PTBL_Choices) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

int PTBL_getLookAheadsLength (PTBL_LookAheads arg) {
  return ATgetLength((ATermList) arg);
}

PTBL_LookAheads PTBL_reverseLookAheads(PTBL_LookAheads arg) {
  return (PTBL_LookAheads) ATreverse((ATermList) arg);
}

PTBL_LookAheads PTBL_appendLookAheads(PTBL_LookAheads arg, PTBL_LookAhead elem) {
  return (PTBL_LookAheads) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

PTBL_LookAheads PTBL_concatLookAheads(PTBL_LookAheads arg0, PTBL_LookAheads arg1) {
  return (PTBL_LookAheads) ATconcat((ATermList) arg0, (ATermList) arg1);
}

PTBL_LookAheads PTBL_sliceLookAheads(PTBL_LookAheads arg, int start, int end) {
  return (PTBL_LookAheads) ATgetSlice((ATermList) arg, start, end);
}

PTBL_LookAhead PTBL_getLookAheadsLookAheadAt(PTBL_LookAheads arg, int index) {
 return (PTBL_LookAhead)ATelementAt((ATermList) arg,index);
}

PTBL_LookAheads PTBL_replaceLookAheadsLookAheadAt(PTBL_LookAheads arg, PTBL_LookAhead elem, int index) {
 return (PTBL_LookAheads) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

PTBL_LookAheads PTBL_makeLookAheads2(PTBL_LookAhead elem1, PTBL_LookAhead elem2) {
  return (PTBL_LookAheads) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}

PTBL_LookAheads PTBL_makeLookAheads3(PTBL_LookAhead elem1, PTBL_LookAhead elem2, PTBL_LookAhead elem3) {
  return (PTBL_LookAheads) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}

PTBL_LookAheads PTBL_makeLookAheads4(PTBL_LookAhead elem1, PTBL_LookAhead elem2, PTBL_LookAhead elem3, PTBL_LookAhead elem4) {
  return (PTBL_LookAheads) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}

PTBL_LookAheads PTBL_makeLookAheads5(PTBL_LookAhead elem1, PTBL_LookAhead elem2, PTBL_LookAhead elem3, PTBL_LookAhead elem4, PTBL_LookAhead elem5) {
  return (PTBL_LookAheads) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}

PTBL_LookAheads PTBL_makeLookAheads6(PTBL_LookAhead elem1, PTBL_LookAhead elem2, PTBL_LookAhead elem3, PTBL_LookAhead elem4, PTBL_LookAhead elem5, PTBL_LookAhead elem6) {
  return (PTBL_LookAheads) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

int PTBL_getPrioritiesLength (PTBL_Priorities arg) {
  return ATgetLength((ATermList) arg);
}

PTBL_Priorities PTBL_reversePriorities(PTBL_Priorities arg) {
  return (PTBL_Priorities) ATreverse((ATermList) arg);
}

PTBL_Priorities PTBL_appendPriorities(PTBL_Priorities arg, PTBL_Priority elem) {
  return (PTBL_Priorities) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

PTBL_Priorities PTBL_concatPriorities(PTBL_Priorities arg0, PTBL_Priorities arg1) {
  return (PTBL_Priorities) ATconcat((ATermList) arg0, (ATermList) arg1);
}

PTBL_Priorities PTBL_slicePriorities(PTBL_Priorities arg, int start, int end) {
  return (PTBL_Priorities) ATgetSlice((ATermList) arg, start, end);
}

PTBL_Priority PTBL_getPrioritiesPriorityAt(PTBL_Priorities arg, int index) {
 return (PTBL_Priority)ATelementAt((ATermList) arg,index);
}

PTBL_Priorities PTBL_replacePrioritiesPriorityAt(PTBL_Priorities arg, PTBL_Priority elem, int index) {
 return (PTBL_Priorities) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

PTBL_Priorities PTBL_makePriorities2(PTBL_Priority elem1, PTBL_Priority elem2) {
  return (PTBL_Priorities) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}

PTBL_Priorities PTBL_makePriorities3(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3) {
  return (PTBL_Priorities) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}

PTBL_Priorities PTBL_makePriorities4(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3, PTBL_Priority elem4) {
  return (PTBL_Priorities) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}

PTBL_Priorities PTBL_makePriorities5(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3, PTBL_Priority elem4, PTBL_Priority elem5) {
  return (PTBL_Priorities) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}

PTBL_Priorities PTBL_makePriorities6(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3, PTBL_Priority elem4, PTBL_Priority elem5, PTBL_Priority elem6) {
  return (PTBL_Priorities) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

PTBL_Production PTBL_makeProductionExternal(ATerm prod) {
  return (PTBL_Production)(ATerm) prod;
}
PTBL_CharRanges PTBL_makeCharRangesExternal(ATerm ranges) {
  return (PTBL_CharRanges)(ATerm) ranges;
}
PTBL_Version PTBL_makeVersionDefault(void) {
  return (PTBL_Version)(ATerm)ATmakeInt(6);
}
PTBL_ParseTable PTBL_makeParseTableParseTable(PTBL_Version version, int initialState, PTBL_Labels labels, PTBL_States states, PTBL_Priorities priorities) {
  return (PTBL_ParseTable)(ATerm)ATmakeAppl5(PTBL_afun0, (ATerm) version, (ATerm) (ATerm) ATmakeInt(initialState), (ATerm) labels, (ATerm)ATmakeAppl1(PTBL_afun1, (ATerm) states), (ATerm)ATmakeAppl1(PTBL_afun2, (ATerm) priorities));
}
PTBL_Labels PTBL_makeLabelsEmpty(void) {
  return (PTBL_Labels)(ATerm)ATempty;
}
PTBL_Labels PTBL_makeLabelsSingle(PTBL_Label head) {
  return (PTBL_Labels)(ATerm)ATmakeList1((ATerm) head);
}
PTBL_Labels PTBL_makeLabelsMany(PTBL_Label head, PTBL_Labels tail) {
  return (PTBL_Labels)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
PTBL_Label PTBL_makeLabelDefault(PTBL_Production production, int number) {
  return (PTBL_Label)(ATerm)ATmakeAppl2(PTBL_afun3, (ATerm) production, (ATerm) (ATerm) ATmakeInt(number));
}
PTBL_States PTBL_makeStatesEmpty(void) {
  return (PTBL_States)(ATerm)ATempty;
}
PTBL_States PTBL_makeStatesSingle(PTBL_State head) {
  return (PTBL_States)(ATerm)ATmakeList1((ATerm) head);
}
PTBL_States PTBL_makeStatesMany(PTBL_State head, PTBL_States tail) {
  return (PTBL_States)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
PTBL_State PTBL_makeStateDefault(int number, PTBL_Gotos gotos, PTBL_Actions actions) {
  return (PTBL_State)(ATerm)ATmakeAppl3(PTBL_afun4, (ATerm) (ATerm) ATmakeInt(number), (ATerm) gotos, (ATerm) actions);
}
PTBL_Gotos PTBL_makeGotosEmpty(void) {
  return (PTBL_Gotos)(ATerm)ATempty;
}
PTBL_Gotos PTBL_makeGotosSingle(PTBL_Goto head) {
  return (PTBL_Gotos)(ATerm)ATmakeList1((ATerm) head);
}
PTBL_Gotos PTBL_makeGotosMany(PTBL_Goto head, PTBL_Gotos tail) {
  return (PTBL_Gotos)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
PTBL_Goto PTBL_makeGotoDefault(PTBL_CharRanges ranges, int stateNumber) {
  return (PTBL_Goto)(ATerm)ATmakeAppl2(PTBL_afun5, (ATerm) ranges, (ATerm) (ATerm) ATmakeInt(stateNumber));
}
PTBL_Actions PTBL_makeActionsEmpty(void) {
  return (PTBL_Actions)(ATerm)ATempty;
}
PTBL_Actions PTBL_makeActionsSingle(PTBL_Action head) {
  return (PTBL_Actions)(ATerm)ATmakeList1((ATerm) head);
}
PTBL_Actions PTBL_makeActionsMany(PTBL_Action head, PTBL_Actions tail) {
  return (PTBL_Actions)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
PTBL_Action PTBL_makeActionDefault(PTBL_CharRanges ranges, PTBL_Choices choices) {
  return (PTBL_Action)(ATerm)ATmakeAppl2(PTBL_afun6, (ATerm) ranges, (ATerm) choices);
}
PTBL_Choices PTBL_makeChoicesEmpty(void) {
  return (PTBL_Choices)(ATerm)ATempty;
}
PTBL_Choices PTBL_makeChoicesSingle(PTBL_Choice head) {
  return (PTBL_Choices)(ATerm)ATmakeList1((ATerm) head);
}
PTBL_Choices PTBL_makeChoicesMany(PTBL_Choice head, PTBL_Choices tail) {
  return (PTBL_Choices)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
PTBL_Choice PTBL_makeChoiceReduce(int length, int label, PTBL_SpecialAttr specialAttr) {
  return (PTBL_Choice)(ATerm)ATmakeAppl3(PTBL_afun7, (ATerm) (ATerm) ATmakeInt(length), (ATerm) (ATerm) ATmakeInt(label), (ATerm) specialAttr);
}
PTBL_Choice PTBL_makeChoiceLookaheadReduce(int length, int label, PTBL_SpecialAttr specialAttr, PTBL_LookAheads lookaheads) {
  return (PTBL_Choice)(ATerm)ATmakeAppl4(PTBL_afun8, (ATerm) (ATerm) ATmakeInt(length), (ATerm) (ATerm) ATmakeInt(label), (ATerm) specialAttr, (ATerm) lookaheads);
}
PTBL_Choice PTBL_makeChoiceShift(int stateNumber) {
  return (PTBL_Choice)(ATerm)ATmakeAppl1(PTBL_afun9, (ATerm) (ATerm) ATmakeInt(stateNumber));
}
PTBL_Choice PTBL_makeChoiceAccept(void) {
  return (PTBL_Choice)(ATerm)ATmakeAppl0(PTBL_afun10);
}
PTBL_SpecialAttr PTBL_makeSpecialAttrNone(void) {
  return (PTBL_SpecialAttr)(ATerm)ATmakeInt(0);
}
PTBL_SpecialAttr PTBL_makeSpecialAttrReject(void) {
  return (PTBL_SpecialAttr)(ATerm)ATmakeInt(1);
}
PTBL_SpecialAttr PTBL_makeSpecialAttrPrefer(void) {
  return (PTBL_SpecialAttr)(ATerm)ATmakeInt(2);
}
PTBL_SpecialAttr PTBL_makeSpecialAttrAvoid(void) {
  return (PTBL_SpecialAttr)(ATerm)ATmakeInt(4);
}
PTBL_LookAheads PTBL_makeLookAheadsEmpty(void) {
  return (PTBL_LookAheads)(ATerm)ATempty;
}
PTBL_LookAheads PTBL_makeLookAheadsSingle(PTBL_LookAhead head) {
  return (PTBL_LookAheads)(ATerm)ATmakeList1((ATerm) head);
}
PTBL_LookAheads PTBL_makeLookAheadsMany(PTBL_LookAhead head, PTBL_LookAheads tail) {
  return (PTBL_LookAheads)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
PTBL_LookAhead PTBL_makeLookAheadDefault(PTBL_CharClass charClass, PTBL_LookAheads lookaheads) {
  return (PTBL_LookAhead)(ATerm)ATmakeAppl2(PTBL_afun11, (ATerm) charClass, (ATerm) lookaheads);
}
PTBL_CharClass PTBL_makeCharClassDefault(PTBL_CharRanges ranges) {
  return (PTBL_CharClass)(ATerm)ATmakeAppl1(PTBL_afun12, (ATerm) ranges);
}
PTBL_Priorities PTBL_makePrioritiesEmpty(void) {
  return (PTBL_Priorities)(ATerm)ATempty;
}
PTBL_Priorities PTBL_makePrioritiesSingle(PTBL_Priority head) {
  return (PTBL_Priorities)(ATerm)ATmakeList1((ATerm) head);
}
PTBL_Priorities PTBL_makePrioritiesMany(PTBL_Priority head, PTBL_Priorities tail) {
  return (PTBL_Priorities)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
PTBL_Priority PTBL_makePriorityGreater(int label1, int label2) {
  return (PTBL_Priority)(ATerm)ATmakeAppl2(PTBL_afun13, (ATerm) (ATerm) ATmakeInt(label1), (ATerm) (ATerm) ATmakeInt(label2));
}
PTBL_Priority PTBL_makePriorityArgGreater(int label1, int argumentNumber, int label2) {
  return (PTBL_Priority)(ATerm)ATmakeAppl3(PTBL_afun14, (ATerm) (ATerm) ATmakeInt(label1), (ATerm) (ATerm) ATmakeInt(argumentNumber), (ATerm) (ATerm) ATmakeInt(label2));
}

ATbool PTBL_isEqualProduction(PTBL_Production arg0, PTBL_Production arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualCharRanges(PTBL_CharRanges arg0, PTBL_CharRanges arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualVersion(PTBL_Version arg0, PTBL_Version arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualParseTable(PTBL_ParseTable arg0, PTBL_ParseTable arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualLabels(PTBL_Labels arg0, PTBL_Labels arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualLabel(PTBL_Label arg0, PTBL_Label arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualStates(PTBL_States arg0, PTBL_States arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualState(PTBL_State arg0, PTBL_State arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualGotos(PTBL_Gotos arg0, PTBL_Gotos arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualGoto(PTBL_Goto arg0, PTBL_Goto arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualActions(PTBL_Actions arg0, PTBL_Actions arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualAction(PTBL_Action arg0, PTBL_Action arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualChoices(PTBL_Choices arg0, PTBL_Choices arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualChoice(PTBL_Choice arg0, PTBL_Choice arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualSpecialAttr(PTBL_SpecialAttr arg0, PTBL_SpecialAttr arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualLookAheads(PTBL_LookAheads arg0, PTBL_LookAheads arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualLookAhead(PTBL_LookAhead arg0, PTBL_LookAhead arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualCharClass(PTBL_CharClass arg0, PTBL_CharClass arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualPriorities(PTBL_Priorities arg0, PTBL_Priorities arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isEqualPriority(PTBL_Priority arg0, PTBL_Priority arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTBL_isValidProduction(PTBL_Production arg) {
  if (PTBL_isProductionExternal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isProductionExternal(PTBL_Production arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternProductionExternal, NULL));
#endif
  return ATtrue;
}

ATbool PTBL_hasProductionProd(PTBL_Production arg) {
  if (PTBL_isProductionExternal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATerm PTBL_getProductionProd(PTBL_Production arg) {
  
    return (ATerm)arg;
}

PTBL_Production PTBL_setProductionProd(PTBL_Production arg, ATerm prod) {
  if (PTBL_isProductionExternal(arg)) {
    return (PTBL_Production)((ATerm) prod);
  }

  ATabort("Production has no Prod: %t\n", arg);
  return (PTBL_Production)NULL;
}

ATbool PTBL_isValidCharRanges(PTBL_CharRanges arg) {
  if (PTBL_isCharRangesExternal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isCharRangesExternal(PTBL_CharRanges arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternCharRangesExternal, NULL));
#endif
  return ATtrue;
}

ATbool PTBL_hasCharRangesRanges(PTBL_CharRanges arg) {
  if (PTBL_isCharRangesExternal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATerm PTBL_getCharRangesRanges(PTBL_CharRanges arg) {
  
    return (ATerm)arg;
}

PTBL_CharRanges PTBL_setCharRangesRanges(PTBL_CharRanges arg, ATerm ranges) {
  if (PTBL_isCharRangesExternal(arg)) {
    return (PTBL_CharRanges)((ATerm) ranges);
  }

  ATabort("CharRanges has no Ranges: %t\n", arg);
  return (PTBL_CharRanges)NULL;
}

ATbool PTBL_isValidVersion(PTBL_Version arg) {
  if (PTBL_isVersionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isVersionDefault(PTBL_Version arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternVersionDefault));
#endif
  return ATtrue;
}

ATbool PTBL_isValidParseTable(PTBL_ParseTable arg) {
  if (PTBL_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isParseTableParseTable(PTBL_ParseTable arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternParseTableParseTable, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

ATbool PTBL_hasParseTableVersion(PTBL_ParseTable arg) {
  if (PTBL_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasParseTableInitialState(PTBL_ParseTable arg) {
  if (PTBL_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasParseTableLabels(PTBL_ParseTable arg) {
  if (PTBL_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasParseTableStates(PTBL_ParseTable arg) {
  if (PTBL_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasParseTablePriorities(PTBL_ParseTable arg) {
  if (PTBL_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

PTBL_Version PTBL_getParseTableVersion(PTBL_ParseTable arg) {
  
    return (PTBL_Version)ATgetArgument((ATermAppl)arg, 0);
}

int PTBL_getParseTableInitialState(PTBL_ParseTable arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

PTBL_Labels PTBL_getParseTableLabels(PTBL_ParseTable arg) {
  
    return (PTBL_Labels)ATgetArgument((ATermAppl)arg, 2);
}

PTBL_States PTBL_getParseTableStates(PTBL_ParseTable arg) {
  
    return (PTBL_States)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 3), 0);
}

PTBL_Priorities PTBL_getParseTablePriorities(PTBL_ParseTable arg) {
  
    return (PTBL_Priorities)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 4), 0);
}

PTBL_ParseTable PTBL_setParseTableVersion(PTBL_ParseTable arg, PTBL_Version version) {
  if (PTBL_isParseTableParseTable(arg)) {
    return (PTBL_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) version), 0);
  }

  ATabort("ParseTable has no Version: %t\n", arg);
  return (PTBL_ParseTable)NULL;
}

PTBL_ParseTable PTBL_setParseTableInitialState(PTBL_ParseTable arg, int initialState) {
  if (PTBL_isParseTableParseTable(arg)) {
    return (PTBL_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(initialState)), 1);
  }

  ATabort("ParseTable has no InitialState: %t\n", arg);
  return (PTBL_ParseTable)NULL;
}

PTBL_ParseTable PTBL_setParseTableLabels(PTBL_ParseTable arg, PTBL_Labels labels) {
  if (PTBL_isParseTableParseTable(arg)) {
    return (PTBL_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) labels), 2);
  }

  ATabort("ParseTable has no Labels: %t\n", arg);
  return (PTBL_ParseTable)NULL;
}

PTBL_ParseTable PTBL_setParseTableStates(PTBL_ParseTable arg, PTBL_States states) {
  if (PTBL_isParseTableParseTable(arg)) {
    return (PTBL_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 3), (ATerm)((ATerm) states), 0), 3);
  }

  ATabort("ParseTable has no States: %t\n", arg);
  return (PTBL_ParseTable)NULL;
}

PTBL_ParseTable PTBL_setParseTablePriorities(PTBL_ParseTable arg, PTBL_Priorities priorities) {
  if (PTBL_isParseTableParseTable(arg)) {
    return (PTBL_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 4), (ATerm)((ATerm) priorities), 0), 4);
  }

  ATabort("ParseTable has no Priorities: %t\n", arg);
  return (PTBL_ParseTable)NULL;
}

ATbool PTBL_isValidLabels(PTBL_Labels arg) {
  if (PTBL_isLabelsEmpty(arg)) {
    return ATtrue;
  }
  else if (PTBL_isLabelsSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isLabelsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isLabelsEmpty(PTBL_Labels arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternLabelsEmpty));
#endif
  return ATtrue;
}

inline ATbool PTBL_isLabelsSingle(PTBL_Labels arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternLabelsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool PTBL_isLabelsMany(PTBL_Labels arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternLabelsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool PTBL_hasLabelsHead(PTBL_Labels arg) {
  if (PTBL_isLabelsSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isLabelsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasLabelsTail(PTBL_Labels arg) {
  if (PTBL_isLabelsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

PTBL_Label PTBL_getLabelsHead(PTBL_Labels arg) {
  if (PTBL_isLabelsSingle(arg)) {
    return (PTBL_Label)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_Label)ATgetFirst((ATermList)arg);
}

PTBL_Labels PTBL_getLabelsTail(PTBL_Labels arg) {
  
    return (PTBL_Labels)ATgetNext((ATermList)arg);
}

PTBL_Labels PTBL_setLabelsHead(PTBL_Labels arg, PTBL_Label head) {
  if (PTBL_isLabelsSingle(arg)) {
    return (PTBL_Labels)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTBL_isLabelsMany(arg)) {
    return (PTBL_Labels)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Labels has no Head: %t\n", arg);
  return (PTBL_Labels)NULL;
}

PTBL_Labels PTBL_setLabelsTail(PTBL_Labels arg, PTBL_Labels tail) {
  if (PTBL_isLabelsMany(arg)) {
    return (PTBL_Labels)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Labels has no Tail: %t\n", arg);
  return (PTBL_Labels)NULL;
}

ATbool PTBL_isValidLabel(PTBL_Label arg) {
  if (PTBL_isLabelDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isLabelDefault(PTBL_Label arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternLabelDefault, NULL, NULL));
#endif
  return ATtrue;
}

ATbool PTBL_hasLabelProduction(PTBL_Label arg) {
  if (PTBL_isLabelDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasLabelNumber(PTBL_Label arg) {
  if (PTBL_isLabelDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

PTBL_Production PTBL_getLabelProduction(PTBL_Label arg) {
  
    return (PTBL_Production)ATgetArgument((ATermAppl)arg, 0);
}

int PTBL_getLabelNumber(PTBL_Label arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

PTBL_Label PTBL_setLabelProduction(PTBL_Label arg, PTBL_Production production) {
  if (PTBL_isLabelDefault(arg)) {
    return (PTBL_Label)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) production), 0);
  }

  ATabort("Label has no Production: %t\n", arg);
  return (PTBL_Label)NULL;
}

PTBL_Label PTBL_setLabelNumber(PTBL_Label arg, int number) {
  if (PTBL_isLabelDefault(arg)) {
    return (PTBL_Label)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(number)), 1);
  }

  ATabort("Label has no Number: %t\n", arg);
  return (PTBL_Label)NULL;
}

ATbool PTBL_isValidStates(PTBL_States arg) {
  if (PTBL_isStatesEmpty(arg)) {
    return ATtrue;
  }
  else if (PTBL_isStatesSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isStatesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isStatesEmpty(PTBL_States arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternStatesEmpty));
#endif
  return ATtrue;
}

inline ATbool PTBL_isStatesSingle(PTBL_States arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternStatesSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool PTBL_isStatesMany(PTBL_States arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternStatesMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool PTBL_hasStatesHead(PTBL_States arg) {
  if (PTBL_isStatesSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isStatesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasStatesTail(PTBL_States arg) {
  if (PTBL_isStatesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

PTBL_State PTBL_getStatesHead(PTBL_States arg) {
  if (PTBL_isStatesSingle(arg)) {
    return (PTBL_State)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_State)ATgetFirst((ATermList)arg);
}

PTBL_States PTBL_getStatesTail(PTBL_States arg) {
  
    return (PTBL_States)ATgetNext((ATermList)arg);
}

PTBL_States PTBL_setStatesHead(PTBL_States arg, PTBL_State head) {
  if (PTBL_isStatesSingle(arg)) {
    return (PTBL_States)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTBL_isStatesMany(arg)) {
    return (PTBL_States)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("States has no Head: %t\n", arg);
  return (PTBL_States)NULL;
}

PTBL_States PTBL_setStatesTail(PTBL_States arg, PTBL_States tail) {
  if (PTBL_isStatesMany(arg)) {
    return (PTBL_States)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("States has no Tail: %t\n", arg);
  return (PTBL_States)NULL;
}

ATbool PTBL_isValidState(PTBL_State arg) {
  if (PTBL_isStateDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isStateDefault(PTBL_State arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternStateDefault, NULL, NULL, NULL));
#endif
  return ATtrue;
}

ATbool PTBL_hasStateNumber(PTBL_State arg) {
  if (PTBL_isStateDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasStateGotos(PTBL_State arg) {
  if (PTBL_isStateDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasStateActions(PTBL_State arg) {
  if (PTBL_isStateDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

int PTBL_getStateNumber(PTBL_State arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

PTBL_Gotos PTBL_getStateGotos(PTBL_State arg) {
  
    return (PTBL_Gotos)ATgetArgument((ATermAppl)arg, 1);
}

PTBL_Actions PTBL_getStateActions(PTBL_State arg) {
  
    return (PTBL_Actions)ATgetArgument((ATermAppl)arg, 2);
}

PTBL_State PTBL_setStateNumber(PTBL_State arg, int number) {
  if (PTBL_isStateDefault(arg)) {
    return (PTBL_State)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(number)), 0);
  }

  ATabort("State has no Number: %t\n", arg);
  return (PTBL_State)NULL;
}

PTBL_State PTBL_setStateGotos(PTBL_State arg, PTBL_Gotos gotos) {
  if (PTBL_isStateDefault(arg)) {
    return (PTBL_State)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) gotos), 1);
  }

  ATabort("State has no Gotos: %t\n", arg);
  return (PTBL_State)NULL;
}

PTBL_State PTBL_setStateActions(PTBL_State arg, PTBL_Actions actions) {
  if (PTBL_isStateDefault(arg)) {
    return (PTBL_State)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) actions), 2);
  }

  ATabort("State has no Actions: %t\n", arg);
  return (PTBL_State)NULL;
}

ATbool PTBL_isValidGotos(PTBL_Gotos arg) {
  if (PTBL_isGotosEmpty(arg)) {
    return ATtrue;
  }
  else if (PTBL_isGotosSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isGotosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isGotosEmpty(PTBL_Gotos arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternGotosEmpty));
#endif
  return ATtrue;
}

inline ATbool PTBL_isGotosSingle(PTBL_Gotos arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternGotosSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool PTBL_isGotosMany(PTBL_Gotos arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternGotosMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool PTBL_hasGotosHead(PTBL_Gotos arg) {
  if (PTBL_isGotosSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isGotosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasGotosTail(PTBL_Gotos arg) {
  if (PTBL_isGotosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

PTBL_Goto PTBL_getGotosHead(PTBL_Gotos arg) {
  if (PTBL_isGotosSingle(arg)) {
    return (PTBL_Goto)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_Goto)ATgetFirst((ATermList)arg);
}

PTBL_Gotos PTBL_getGotosTail(PTBL_Gotos arg) {
  
    return (PTBL_Gotos)ATgetNext((ATermList)arg);
}

PTBL_Gotos PTBL_setGotosHead(PTBL_Gotos arg, PTBL_Goto head) {
  if (PTBL_isGotosSingle(arg)) {
    return (PTBL_Gotos)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTBL_isGotosMany(arg)) {
    return (PTBL_Gotos)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Gotos has no Head: %t\n", arg);
  return (PTBL_Gotos)NULL;
}

PTBL_Gotos PTBL_setGotosTail(PTBL_Gotos arg, PTBL_Gotos tail) {
  if (PTBL_isGotosMany(arg)) {
    return (PTBL_Gotos)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Gotos has no Tail: %t\n", arg);
  return (PTBL_Gotos)NULL;
}

ATbool PTBL_isValidGoto(PTBL_Goto arg) {
  if (PTBL_isGotoDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isGotoDefault(PTBL_Goto arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternGotoDefault, NULL, NULL));
#endif
  return ATtrue;
}

ATbool PTBL_hasGotoRanges(PTBL_Goto arg) {
  if (PTBL_isGotoDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasGotoStateNumber(PTBL_Goto arg) {
  if (PTBL_isGotoDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

PTBL_CharRanges PTBL_getGotoRanges(PTBL_Goto arg) {
  
    return (PTBL_CharRanges)ATgetArgument((ATermAppl)arg, 0);
}

int PTBL_getGotoStateNumber(PTBL_Goto arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

PTBL_Goto PTBL_setGotoRanges(PTBL_Goto arg, PTBL_CharRanges ranges) {
  if (PTBL_isGotoDefault(arg)) {
    return (PTBL_Goto)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) ranges), 0);
  }

  ATabort("Goto has no Ranges: %t\n", arg);
  return (PTBL_Goto)NULL;
}

PTBL_Goto PTBL_setGotoStateNumber(PTBL_Goto arg, int stateNumber) {
  if (PTBL_isGotoDefault(arg)) {
    return (PTBL_Goto)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(stateNumber)), 1);
  }

  ATabort("Goto has no StateNumber: %t\n", arg);
  return (PTBL_Goto)NULL;
}

ATbool PTBL_isValidActions(PTBL_Actions arg) {
  if (PTBL_isActionsEmpty(arg)) {
    return ATtrue;
  }
  else if (PTBL_isActionsSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isActionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isActionsEmpty(PTBL_Actions arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternActionsEmpty));
#endif
  return ATtrue;
}

inline ATbool PTBL_isActionsSingle(PTBL_Actions arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternActionsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool PTBL_isActionsMany(PTBL_Actions arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternActionsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool PTBL_hasActionsHead(PTBL_Actions arg) {
  if (PTBL_isActionsSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isActionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasActionsTail(PTBL_Actions arg) {
  if (PTBL_isActionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

PTBL_Action PTBL_getActionsHead(PTBL_Actions arg) {
  if (PTBL_isActionsSingle(arg)) {
    return (PTBL_Action)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_Action)ATgetFirst((ATermList)arg);
}

PTBL_Actions PTBL_getActionsTail(PTBL_Actions arg) {
  
    return (PTBL_Actions)ATgetNext((ATermList)arg);
}

PTBL_Actions PTBL_setActionsHead(PTBL_Actions arg, PTBL_Action head) {
  if (PTBL_isActionsSingle(arg)) {
    return (PTBL_Actions)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTBL_isActionsMany(arg)) {
    return (PTBL_Actions)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Actions has no Head: %t\n", arg);
  return (PTBL_Actions)NULL;
}

PTBL_Actions PTBL_setActionsTail(PTBL_Actions arg, PTBL_Actions tail) {
  if (PTBL_isActionsMany(arg)) {
    return (PTBL_Actions)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Actions has no Tail: %t\n", arg);
  return (PTBL_Actions)NULL;
}

ATbool PTBL_isValidAction(PTBL_Action arg) {
  if (PTBL_isActionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isActionDefault(PTBL_Action arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternActionDefault, NULL, NULL));
#endif
  return ATtrue;
}

ATbool PTBL_hasActionRanges(PTBL_Action arg) {
  if (PTBL_isActionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasActionChoices(PTBL_Action arg) {
  if (PTBL_isActionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

PTBL_CharRanges PTBL_getActionRanges(PTBL_Action arg) {
  
    return (PTBL_CharRanges)ATgetArgument((ATermAppl)arg, 0);
}

PTBL_Choices PTBL_getActionChoices(PTBL_Action arg) {
  
    return (PTBL_Choices)ATgetArgument((ATermAppl)arg, 1);
}

PTBL_Action PTBL_setActionRanges(PTBL_Action arg, PTBL_CharRanges ranges) {
  if (PTBL_isActionDefault(arg)) {
    return (PTBL_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) ranges), 0);
  }

  ATabort("Action has no Ranges: %t\n", arg);
  return (PTBL_Action)NULL;
}

PTBL_Action PTBL_setActionChoices(PTBL_Action arg, PTBL_Choices choices) {
  if (PTBL_isActionDefault(arg)) {
    return (PTBL_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) choices), 1);
  }

  ATabort("Action has no Choices: %t\n", arg);
  return (PTBL_Action)NULL;
}

ATbool PTBL_isValidChoices(PTBL_Choices arg) {
  if (PTBL_isChoicesEmpty(arg)) {
    return ATtrue;
  }
  else if (PTBL_isChoicesSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isChoicesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isChoicesEmpty(PTBL_Choices arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternChoicesEmpty));
#endif
  return ATtrue;
}

inline ATbool PTBL_isChoicesSingle(PTBL_Choices arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternChoicesSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool PTBL_isChoicesMany(PTBL_Choices arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternChoicesMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool PTBL_hasChoicesHead(PTBL_Choices arg) {
  if (PTBL_isChoicesSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isChoicesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasChoicesTail(PTBL_Choices arg) {
  if (PTBL_isChoicesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

PTBL_Choice PTBL_getChoicesHead(PTBL_Choices arg) {
  if (PTBL_isChoicesSingle(arg)) {
    return (PTBL_Choice)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_Choice)ATgetFirst((ATermList)arg);
}

PTBL_Choices PTBL_getChoicesTail(PTBL_Choices arg) {
  
    return (PTBL_Choices)ATgetNext((ATermList)arg);
}

PTBL_Choices PTBL_setChoicesHead(PTBL_Choices arg, PTBL_Choice head) {
  if (PTBL_isChoicesSingle(arg)) {
    return (PTBL_Choices)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTBL_isChoicesMany(arg)) {
    return (PTBL_Choices)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Choices has no Head: %t\n", arg);
  return (PTBL_Choices)NULL;
}

PTBL_Choices PTBL_setChoicesTail(PTBL_Choices arg, PTBL_Choices tail) {
  if (PTBL_isChoicesMany(arg)) {
    return (PTBL_Choices)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Choices has no Tail: %t\n", arg);
  return (PTBL_Choices)NULL;
}

ATbool PTBL_isValidChoice(PTBL_Choice arg) {
  if (PTBL_isChoiceReduce(arg)) {
    return ATtrue;
  }
  else if (PTBL_isChoiceLookaheadReduce(arg)) {
    return ATtrue;
  }
  else if (PTBL_isChoiceShift(arg)) {
    return ATtrue;
  }
  else if (PTBL_isChoiceAccept(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isChoiceReduce(PTBL_Choice arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternChoiceReduce, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool PTBL_isChoiceLookaheadReduce(PTBL_Choice arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternChoiceLookaheadReduce, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool PTBL_isChoiceShift(PTBL_Choice arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternChoiceShift, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool PTBL_isChoiceAccept(PTBL_Choice arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternChoiceAccept);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool PTBL_hasChoiceLength(PTBL_Choice arg) {
  if (PTBL_isChoiceReduce(arg)) {
    return ATtrue;
  }
  else if (PTBL_isChoiceLookaheadReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasChoiceLabel(PTBL_Choice arg) {
  if (PTBL_isChoiceReduce(arg)) {
    return ATtrue;
  }
  else if (PTBL_isChoiceLookaheadReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasChoiceSpecialAttr(PTBL_Choice arg) {
  if (PTBL_isChoiceReduce(arg)) {
    return ATtrue;
  }
  else if (PTBL_isChoiceLookaheadReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasChoiceLookaheads(PTBL_Choice arg) {
  if (PTBL_isChoiceLookaheadReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasChoiceStateNumber(PTBL_Choice arg) {
  if (PTBL_isChoiceShift(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

int PTBL_getChoiceLength(PTBL_Choice arg) {
  if (PTBL_isChoiceReduce(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

int PTBL_getChoiceLabel(PTBL_Choice arg) {
  if (PTBL_isChoiceReduce(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

PTBL_SpecialAttr PTBL_getChoiceSpecialAttr(PTBL_Choice arg) {
  if (PTBL_isChoiceReduce(arg)) {
    return (PTBL_SpecialAttr)ATgetArgument((ATermAppl)arg, 2);
  }
  else 
    return (PTBL_SpecialAttr)ATgetArgument((ATermAppl)arg, 2);
}

PTBL_LookAheads PTBL_getChoiceLookaheads(PTBL_Choice arg) {
  
    return (PTBL_LookAheads)ATgetArgument((ATermAppl)arg, 3);
}

int PTBL_getChoiceStateNumber(PTBL_Choice arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

PTBL_Choice PTBL_setChoiceLength(PTBL_Choice arg, int length) {
  if (PTBL_isChoiceReduce(arg)) {
    return (PTBL_Choice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(length)), 0);
  }
  else if (PTBL_isChoiceLookaheadReduce(arg)) {
    return (PTBL_Choice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(length)), 0);
  }

  ATabort("Choice has no Length: %t\n", arg);
  return (PTBL_Choice)NULL;
}

PTBL_Choice PTBL_setChoiceLabel(PTBL_Choice arg, int label) {
  if (PTBL_isChoiceReduce(arg)) {
    return (PTBL_Choice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(label)), 1);
  }
  else if (PTBL_isChoiceLookaheadReduce(arg)) {
    return (PTBL_Choice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(label)), 1);
  }

  ATabort("Choice has no Label: %t\n", arg);
  return (PTBL_Choice)NULL;
}

PTBL_Choice PTBL_setChoiceSpecialAttr(PTBL_Choice arg, PTBL_SpecialAttr specialAttr) {
  if (PTBL_isChoiceReduce(arg)) {
    return (PTBL_Choice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) specialAttr), 2);
  }
  else if (PTBL_isChoiceLookaheadReduce(arg)) {
    return (PTBL_Choice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) specialAttr), 2);
  }

  ATabort("Choice has no SpecialAttr: %t\n", arg);
  return (PTBL_Choice)NULL;
}

PTBL_Choice PTBL_setChoiceLookaheads(PTBL_Choice arg, PTBL_LookAheads lookaheads) {
  if (PTBL_isChoiceLookaheadReduce(arg)) {
    return (PTBL_Choice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) lookaheads), 3);
  }

  ATabort("Choice has no Lookaheads: %t\n", arg);
  return (PTBL_Choice)NULL;
}

PTBL_Choice PTBL_setChoiceStateNumber(PTBL_Choice arg, int stateNumber) {
  if (PTBL_isChoiceShift(arg)) {
    return (PTBL_Choice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(stateNumber)), 0);
  }

  ATabort("Choice has no StateNumber: %t\n", arg);
  return (PTBL_Choice)NULL;
}

ATbool PTBL_isValidSpecialAttr(PTBL_SpecialAttr arg) {
  if (PTBL_isSpecialAttrNone(arg)) {
    return ATtrue;
  }
  else if (PTBL_isSpecialAttrReject(arg)) {
    return ATtrue;
  }
  else if (PTBL_isSpecialAttrPrefer(arg)) {
    return ATtrue;
  }
  else if (PTBL_isSpecialAttrAvoid(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isSpecialAttrNone(PTBL_SpecialAttr arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternSpecialAttrNone);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool PTBL_isSpecialAttrReject(PTBL_SpecialAttr arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternSpecialAttrReject);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool PTBL_isSpecialAttrPrefer(PTBL_SpecialAttr arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternSpecialAttrPrefer);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool PTBL_isSpecialAttrAvoid(PTBL_SpecialAttr arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternSpecialAttrAvoid);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool PTBL_isValidLookAheads(PTBL_LookAheads arg) {
  if (PTBL_isLookAheadsEmpty(arg)) {
    return ATtrue;
  }
  else if (PTBL_isLookAheadsSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isLookAheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isLookAheadsEmpty(PTBL_LookAheads arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternLookAheadsEmpty));
#endif
  return ATtrue;
}

inline ATbool PTBL_isLookAheadsSingle(PTBL_LookAheads arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternLookAheadsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool PTBL_isLookAheadsMany(PTBL_LookAheads arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternLookAheadsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool PTBL_hasLookAheadsHead(PTBL_LookAheads arg) {
  if (PTBL_isLookAheadsSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isLookAheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasLookAheadsTail(PTBL_LookAheads arg) {
  if (PTBL_isLookAheadsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

PTBL_LookAhead PTBL_getLookAheadsHead(PTBL_LookAheads arg) {
  if (PTBL_isLookAheadsSingle(arg)) {
    return (PTBL_LookAhead)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_LookAhead)ATgetFirst((ATermList)arg);
}

PTBL_LookAheads PTBL_getLookAheadsTail(PTBL_LookAheads arg) {
  
    return (PTBL_LookAheads)ATgetNext((ATermList)arg);
}

PTBL_LookAheads PTBL_setLookAheadsHead(PTBL_LookAheads arg, PTBL_LookAhead head) {
  if (PTBL_isLookAheadsSingle(arg)) {
    return (PTBL_LookAheads)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTBL_isLookAheadsMany(arg)) {
    return (PTBL_LookAheads)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LookAheads has no Head: %t\n", arg);
  return (PTBL_LookAheads)NULL;
}

PTBL_LookAheads PTBL_setLookAheadsTail(PTBL_LookAheads arg, PTBL_LookAheads tail) {
  if (PTBL_isLookAheadsMany(arg)) {
    return (PTBL_LookAheads)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LookAheads has no Tail: %t\n", arg);
  return (PTBL_LookAheads)NULL;
}

ATbool PTBL_isValidLookAhead(PTBL_LookAhead arg) {
  if (PTBL_isLookAheadDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isLookAheadDefault(PTBL_LookAhead arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternLookAheadDefault, NULL, NULL));
#endif
  return ATtrue;
}

ATbool PTBL_hasLookAheadCharClass(PTBL_LookAhead arg) {
  if (PTBL_isLookAheadDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasLookAheadLookaheads(PTBL_LookAhead arg) {
  if (PTBL_isLookAheadDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

PTBL_CharClass PTBL_getLookAheadCharClass(PTBL_LookAhead arg) {
  
    return (PTBL_CharClass)ATgetArgument((ATermAppl)arg, 0);
}

PTBL_LookAheads PTBL_getLookAheadLookaheads(PTBL_LookAhead arg) {
  
    return (PTBL_LookAheads)ATgetArgument((ATermAppl)arg, 1);
}

PTBL_LookAhead PTBL_setLookAheadCharClass(PTBL_LookAhead arg, PTBL_CharClass charClass) {
  if (PTBL_isLookAheadDefault(arg)) {
    return (PTBL_LookAhead)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) charClass), 0);
  }

  ATabort("LookAhead has no CharClass: %t\n", arg);
  return (PTBL_LookAhead)NULL;
}

PTBL_LookAhead PTBL_setLookAheadLookaheads(PTBL_LookAhead arg, PTBL_LookAheads lookaheads) {
  if (PTBL_isLookAheadDefault(arg)) {
    return (PTBL_LookAhead)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) lookaheads), 1);
  }

  ATabort("LookAhead has no Lookaheads: %t\n", arg);
  return (PTBL_LookAhead)NULL;
}

ATbool PTBL_isValidCharClass(PTBL_CharClass arg) {
  if (PTBL_isCharClassDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isCharClassDefault(PTBL_CharClass arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternCharClassDefault, NULL));
#endif
  return ATtrue;
}

ATbool PTBL_hasCharClassRanges(PTBL_CharClass arg) {
  if (PTBL_isCharClassDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

PTBL_CharRanges PTBL_getCharClassRanges(PTBL_CharClass arg) {
  
    return (PTBL_CharRanges)ATgetArgument((ATermAppl)arg, 0);
}

PTBL_CharClass PTBL_setCharClassRanges(PTBL_CharClass arg, PTBL_CharRanges ranges) {
  if (PTBL_isCharClassDefault(arg)) {
    return (PTBL_CharClass)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) ranges), 0);
  }

  ATabort("CharClass has no Ranges: %t\n", arg);
  return (PTBL_CharClass)NULL;
}

ATbool PTBL_isValidPriorities(PTBL_Priorities arg) {
  if (PTBL_isPrioritiesEmpty(arg)) {
    return ATtrue;
  }
  else if (PTBL_isPrioritiesSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isPrioritiesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isPrioritiesEmpty(PTBL_Priorities arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTBL_patternPrioritiesEmpty));
#endif
  return ATtrue;
}

inline ATbool PTBL_isPrioritiesSingle(PTBL_Priorities arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternPrioritiesSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool PTBL_isPrioritiesMany(PTBL_Priorities arg) {
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternPrioritiesMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool PTBL_hasPrioritiesHead(PTBL_Priorities arg) {
  if (PTBL_isPrioritiesSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isPrioritiesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasPrioritiesTail(PTBL_Priorities arg) {
  if (PTBL_isPrioritiesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

PTBL_Priority PTBL_getPrioritiesHead(PTBL_Priorities arg) {
  if (PTBL_isPrioritiesSingle(arg)) {
    return (PTBL_Priority)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_Priority)ATgetFirst((ATermList)arg);
}

PTBL_Priorities PTBL_getPrioritiesTail(PTBL_Priorities arg) {
  
    return (PTBL_Priorities)ATgetNext((ATermList)arg);
}

PTBL_Priorities PTBL_setPrioritiesHead(PTBL_Priorities arg, PTBL_Priority head) {
  if (PTBL_isPrioritiesSingle(arg)) {
    return (PTBL_Priorities)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTBL_isPrioritiesMany(arg)) {
    return (PTBL_Priorities)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Priorities has no Head: %t\n", arg);
  return (PTBL_Priorities)NULL;
}

PTBL_Priorities PTBL_setPrioritiesTail(PTBL_Priorities arg, PTBL_Priorities tail) {
  if (PTBL_isPrioritiesMany(arg)) {
    return (PTBL_Priorities)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Priorities has no Tail: %t\n", arg);
  return (PTBL_Priorities)NULL;
}

ATbool PTBL_isValidPriority(PTBL_Priority arg) {
  if (PTBL_isPriorityGreater(arg)) {
    return ATtrue;
  }
  else if (PTBL_isPriorityArgGreater(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool PTBL_isPriorityGreater(PTBL_Priority arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternPriorityGreater, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool PTBL_isPriorityArgGreater(PTBL_Priority arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTBL_patternPriorityArgGreater, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool PTBL_hasPriorityLabel1(PTBL_Priority arg) {
  if (PTBL_isPriorityGreater(arg)) {
    return ATtrue;
  }
  else if (PTBL_isPriorityArgGreater(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasPriorityLabel2(PTBL_Priority arg) {
  if (PTBL_isPriorityGreater(arg)) {
    return ATtrue;
  }
  else if (PTBL_isPriorityArgGreater(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool PTBL_hasPriorityArgumentNumber(PTBL_Priority arg) {
  if (PTBL_isPriorityArgGreater(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

int PTBL_getPriorityLabel1(PTBL_Priority arg) {
  if (PTBL_isPriorityGreater(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

int PTBL_getPriorityLabel2(PTBL_Priority arg) {
  if (PTBL_isPriorityGreater(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

int PTBL_getPriorityArgumentNumber(PTBL_Priority arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

PTBL_Priority PTBL_setPriorityLabel1(PTBL_Priority arg, int label1) {
  if (PTBL_isPriorityGreater(arg)) {
    return (PTBL_Priority)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(label1)), 0);
  }
  else if (PTBL_isPriorityArgGreater(arg)) {
    return (PTBL_Priority)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(label1)), 0);
  }

  ATabort("Priority has no Label1: %t\n", arg);
  return (PTBL_Priority)NULL;
}

PTBL_Priority PTBL_setPriorityLabel2(PTBL_Priority arg, int label2) {
  if (PTBL_isPriorityGreater(arg)) {
    return (PTBL_Priority)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(label2)), 1);
  }
  else if (PTBL_isPriorityArgGreater(arg)) {
    return (PTBL_Priority)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(label2)), 2);
  }

  ATabort("Priority has no Label2: %t\n", arg);
  return (PTBL_Priority)NULL;
}

PTBL_Priority PTBL_setPriorityArgumentNumber(PTBL_Priority arg, int argumentNumber) {
  if (PTBL_isPriorityArgGreater(arg)) {
    return (PTBL_Priority)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(argumentNumber)), 1);
  }

  ATabort("Priority has no ArgumentNumber: %t\n", arg);
  return (PTBL_Priority)NULL;
}

PTBL_Production PTBL_visitProduction(PTBL_Production arg, ATerm (*acceptProd)(ATerm)) {
  if (PTBL_isProductionExternal(arg)) {
    return PTBL_makeProductionExternal(
        acceptProd ? acceptProd(PTBL_getProductionProd(arg)) : PTBL_getProductionProd(arg));
  }
  ATabort("not a Production: %t\n", arg);
  return (PTBL_Production)NULL;
}
PTBL_CharRanges PTBL_visitCharRanges(PTBL_CharRanges arg, ATerm (*acceptRanges)(ATerm)) {
  if (PTBL_isCharRangesExternal(arg)) {
    return PTBL_makeCharRangesExternal(
        acceptRanges ? acceptRanges(PTBL_getCharRangesRanges(arg)) : PTBL_getCharRangesRanges(arg));
  }
  ATabort("not a CharRanges: %t\n", arg);
  return (PTBL_CharRanges)NULL;
}
PTBL_Version PTBL_visitVersion(PTBL_Version arg) {
  if (PTBL_isVersionDefault(arg)) {
    return PTBL_makeVersionDefault();
  }
  ATabort("not a Version: %t\n", arg);
  return (PTBL_Version)NULL;
}
PTBL_ParseTable PTBL_visitParseTable(PTBL_ParseTable arg, PTBL_Version (*acceptVersion)(PTBL_Version), int (*acceptInitialState)(int), PTBL_Labels (*acceptLabels)(PTBL_Labels), PTBL_States (*acceptStates)(PTBL_States), PTBL_Priorities (*acceptPriorities)(PTBL_Priorities)) {
  if (PTBL_isParseTableParseTable(arg)) {
    return PTBL_makeParseTableParseTable(
        acceptVersion ? acceptVersion(PTBL_getParseTableVersion(arg)) : PTBL_getParseTableVersion(arg),
        acceptInitialState ? acceptInitialState(PTBL_getParseTableInitialState(arg)) : PTBL_getParseTableInitialState(arg),
        acceptLabels ? acceptLabels(PTBL_getParseTableLabels(arg)) : PTBL_getParseTableLabels(arg),
        acceptStates ? acceptStates(PTBL_getParseTableStates(arg)) : PTBL_getParseTableStates(arg),
        acceptPriorities ? acceptPriorities(PTBL_getParseTablePriorities(arg)) : PTBL_getParseTablePriorities(arg));
  }
  ATabort("not a ParseTable: %t\n", arg);
  return (PTBL_ParseTable)NULL;
}
PTBL_Labels PTBL_visitLabels(PTBL_Labels arg, PTBL_Label (*acceptHead)(PTBL_Label)) {
  if (PTBL_isLabelsEmpty(arg)) {
    return PTBL_makeLabelsEmpty();
  }
  if (PTBL_isLabelsSingle(arg)) {
    return PTBL_makeLabelsSingle(
        acceptHead ? acceptHead(PTBL_getLabelsHead(arg)) : PTBL_getLabelsHead(arg));
  }
  if (PTBL_isLabelsMany(arg)) {
    return PTBL_makeLabelsMany(
        acceptHead ? acceptHead(PTBL_getLabelsHead(arg)) : PTBL_getLabelsHead(arg),
        PTBL_visitLabels(PTBL_getLabelsTail(arg), acceptHead));
  }
  ATabort("not a Labels: %t\n", arg);
  return (PTBL_Labels)NULL;
}
PTBL_Label PTBL_visitLabel(PTBL_Label arg, PTBL_Production (*acceptProduction)(PTBL_Production), int (*acceptNumber)(int)) {
  if (PTBL_isLabelDefault(arg)) {
    return PTBL_makeLabelDefault(
        acceptProduction ? acceptProduction(PTBL_getLabelProduction(arg)) : PTBL_getLabelProduction(arg),
        acceptNumber ? acceptNumber(PTBL_getLabelNumber(arg)) : PTBL_getLabelNumber(arg));
  }
  ATabort("not a Label: %t\n", arg);
  return (PTBL_Label)NULL;
}
PTBL_States PTBL_visitStates(PTBL_States arg, PTBL_State (*acceptHead)(PTBL_State)) {
  if (PTBL_isStatesEmpty(arg)) {
    return PTBL_makeStatesEmpty();
  }
  if (PTBL_isStatesSingle(arg)) {
    return PTBL_makeStatesSingle(
        acceptHead ? acceptHead(PTBL_getStatesHead(arg)) : PTBL_getStatesHead(arg));
  }
  if (PTBL_isStatesMany(arg)) {
    return PTBL_makeStatesMany(
        acceptHead ? acceptHead(PTBL_getStatesHead(arg)) : PTBL_getStatesHead(arg),
        PTBL_visitStates(PTBL_getStatesTail(arg), acceptHead));
  }
  ATabort("not a States: %t\n", arg);
  return (PTBL_States)NULL;
}
PTBL_State PTBL_visitState(PTBL_State arg, int (*acceptNumber)(int), PTBL_Gotos (*acceptGotos)(PTBL_Gotos), PTBL_Actions (*acceptActions)(PTBL_Actions)) {
  if (PTBL_isStateDefault(arg)) {
    return PTBL_makeStateDefault(
        acceptNumber ? acceptNumber(PTBL_getStateNumber(arg)) : PTBL_getStateNumber(arg),
        acceptGotos ? acceptGotos(PTBL_getStateGotos(arg)) : PTBL_getStateGotos(arg),
        acceptActions ? acceptActions(PTBL_getStateActions(arg)) : PTBL_getStateActions(arg));
  }
  ATabort("not a State: %t\n", arg);
  return (PTBL_State)NULL;
}
PTBL_Gotos PTBL_visitGotos(PTBL_Gotos arg, PTBL_Goto (*acceptHead)(PTBL_Goto)) {
  if (PTBL_isGotosEmpty(arg)) {
    return PTBL_makeGotosEmpty();
  }
  if (PTBL_isGotosSingle(arg)) {
    return PTBL_makeGotosSingle(
        acceptHead ? acceptHead(PTBL_getGotosHead(arg)) : PTBL_getGotosHead(arg));
  }
  if (PTBL_isGotosMany(arg)) {
    return PTBL_makeGotosMany(
        acceptHead ? acceptHead(PTBL_getGotosHead(arg)) : PTBL_getGotosHead(arg),
        PTBL_visitGotos(PTBL_getGotosTail(arg), acceptHead));
  }
  ATabort("not a Gotos: %t\n", arg);
  return (PTBL_Gotos)NULL;
}
PTBL_Goto PTBL_visitGoto(PTBL_Goto arg, PTBL_CharRanges (*acceptRanges)(PTBL_CharRanges), int (*acceptStateNumber)(int)) {
  if (PTBL_isGotoDefault(arg)) {
    return PTBL_makeGotoDefault(
        acceptRanges ? acceptRanges(PTBL_getGotoRanges(arg)) : PTBL_getGotoRanges(arg),
        acceptStateNumber ? acceptStateNumber(PTBL_getGotoStateNumber(arg)) : PTBL_getGotoStateNumber(arg));
  }
  ATabort("not a Goto: %t\n", arg);
  return (PTBL_Goto)NULL;
}
PTBL_Actions PTBL_visitActions(PTBL_Actions arg, PTBL_Action (*acceptHead)(PTBL_Action)) {
  if (PTBL_isActionsEmpty(arg)) {
    return PTBL_makeActionsEmpty();
  }
  if (PTBL_isActionsSingle(arg)) {
    return PTBL_makeActionsSingle(
        acceptHead ? acceptHead(PTBL_getActionsHead(arg)) : PTBL_getActionsHead(arg));
  }
  if (PTBL_isActionsMany(arg)) {
    return PTBL_makeActionsMany(
        acceptHead ? acceptHead(PTBL_getActionsHead(arg)) : PTBL_getActionsHead(arg),
        PTBL_visitActions(PTBL_getActionsTail(arg), acceptHead));
  }
  ATabort("not a Actions: %t\n", arg);
  return (PTBL_Actions)NULL;
}
PTBL_Action PTBL_visitAction(PTBL_Action arg, PTBL_CharRanges (*acceptRanges)(PTBL_CharRanges), PTBL_Choices (*acceptChoices)(PTBL_Choices)) {
  if (PTBL_isActionDefault(arg)) {
    return PTBL_makeActionDefault(
        acceptRanges ? acceptRanges(PTBL_getActionRanges(arg)) : PTBL_getActionRanges(arg),
        acceptChoices ? acceptChoices(PTBL_getActionChoices(arg)) : PTBL_getActionChoices(arg));
  }
  ATabort("not a Action: %t\n", arg);
  return (PTBL_Action)NULL;
}
PTBL_Choices PTBL_visitChoices(PTBL_Choices arg, PTBL_Choice (*acceptHead)(PTBL_Choice)) {
  if (PTBL_isChoicesEmpty(arg)) {
    return PTBL_makeChoicesEmpty();
  }
  if (PTBL_isChoicesSingle(arg)) {
    return PTBL_makeChoicesSingle(
        acceptHead ? acceptHead(PTBL_getChoicesHead(arg)) : PTBL_getChoicesHead(arg));
  }
  if (PTBL_isChoicesMany(arg)) {
    return PTBL_makeChoicesMany(
        acceptHead ? acceptHead(PTBL_getChoicesHead(arg)) : PTBL_getChoicesHead(arg),
        PTBL_visitChoices(PTBL_getChoicesTail(arg), acceptHead));
  }
  ATabort("not a Choices: %t\n", arg);
  return (PTBL_Choices)NULL;
}
PTBL_Choice PTBL_visitChoice(PTBL_Choice arg, int (*acceptLength)(int), int (*acceptLabel)(int), PTBL_SpecialAttr (*acceptSpecialAttr)(PTBL_SpecialAttr), PTBL_LookAheads (*acceptLookaheads)(PTBL_LookAheads), int (*acceptStateNumber)(int)) {
  if (PTBL_isChoiceReduce(arg)) {
    return PTBL_makeChoiceReduce(
        acceptLength ? acceptLength(PTBL_getChoiceLength(arg)) : PTBL_getChoiceLength(arg),
        acceptLabel ? acceptLabel(PTBL_getChoiceLabel(arg)) : PTBL_getChoiceLabel(arg),
        acceptSpecialAttr ? acceptSpecialAttr(PTBL_getChoiceSpecialAttr(arg)) : PTBL_getChoiceSpecialAttr(arg));
  }
  if (PTBL_isChoiceLookaheadReduce(arg)) {
    return PTBL_makeChoiceLookaheadReduce(
        acceptLength ? acceptLength(PTBL_getChoiceLength(arg)) : PTBL_getChoiceLength(arg),
        acceptLabel ? acceptLabel(PTBL_getChoiceLabel(arg)) : PTBL_getChoiceLabel(arg),
        acceptSpecialAttr ? acceptSpecialAttr(PTBL_getChoiceSpecialAttr(arg)) : PTBL_getChoiceSpecialAttr(arg),
        acceptLookaheads ? acceptLookaheads(PTBL_getChoiceLookaheads(arg)) : PTBL_getChoiceLookaheads(arg));
  }
  if (PTBL_isChoiceShift(arg)) {
    return PTBL_makeChoiceShift(
        acceptStateNumber ? acceptStateNumber(PTBL_getChoiceStateNumber(arg)) : PTBL_getChoiceStateNumber(arg));
  }
  if (PTBL_isChoiceAccept(arg)) {
    return PTBL_makeChoiceAccept();
  }
  ATabort("not a Choice: %t\n", arg);
  return (PTBL_Choice)NULL;
}
PTBL_SpecialAttr PTBL_visitSpecialAttr(PTBL_SpecialAttr arg) {
  if (PTBL_isSpecialAttrNone(arg)) {
    return PTBL_makeSpecialAttrNone();
  }
  if (PTBL_isSpecialAttrReject(arg)) {
    return PTBL_makeSpecialAttrReject();
  }
  if (PTBL_isSpecialAttrPrefer(arg)) {
    return PTBL_makeSpecialAttrPrefer();
  }
  if (PTBL_isSpecialAttrAvoid(arg)) {
    return PTBL_makeSpecialAttrAvoid();
  }
  ATabort("not a SpecialAttr: %t\n", arg);
  return (PTBL_SpecialAttr)NULL;
}
PTBL_LookAheads PTBL_visitLookAheads(PTBL_LookAheads arg, PTBL_LookAhead (*acceptHead)(PTBL_LookAhead)) {
  if (PTBL_isLookAheadsEmpty(arg)) {
    return PTBL_makeLookAheadsEmpty();
  }
  if (PTBL_isLookAheadsSingle(arg)) {
    return PTBL_makeLookAheadsSingle(
        acceptHead ? acceptHead(PTBL_getLookAheadsHead(arg)) : PTBL_getLookAheadsHead(arg));
  }
  if (PTBL_isLookAheadsMany(arg)) {
    return PTBL_makeLookAheadsMany(
        acceptHead ? acceptHead(PTBL_getLookAheadsHead(arg)) : PTBL_getLookAheadsHead(arg),
        PTBL_visitLookAheads(PTBL_getLookAheadsTail(arg), acceptHead));
  }
  ATabort("not a LookAheads: %t\n", arg);
  return (PTBL_LookAheads)NULL;
}
PTBL_LookAhead PTBL_visitLookAhead(PTBL_LookAhead arg, PTBL_CharClass (*acceptCharClass)(PTBL_CharClass), PTBL_LookAheads (*acceptLookaheads)(PTBL_LookAheads)) {
  if (PTBL_isLookAheadDefault(arg)) {
    return PTBL_makeLookAheadDefault(
        acceptCharClass ? acceptCharClass(PTBL_getLookAheadCharClass(arg)) : PTBL_getLookAheadCharClass(arg),
        acceptLookaheads ? acceptLookaheads(PTBL_getLookAheadLookaheads(arg)) : PTBL_getLookAheadLookaheads(arg));
  }
  ATabort("not a LookAhead: %t\n", arg);
  return (PTBL_LookAhead)NULL;
}
PTBL_CharClass PTBL_visitCharClass(PTBL_CharClass arg, PTBL_CharRanges (*acceptRanges)(PTBL_CharRanges)) {
  if (PTBL_isCharClassDefault(arg)) {
    return PTBL_makeCharClassDefault(
        acceptRanges ? acceptRanges(PTBL_getCharClassRanges(arg)) : PTBL_getCharClassRanges(arg));
  }
  ATabort("not a CharClass: %t\n", arg);
  return (PTBL_CharClass)NULL;
}
PTBL_Priorities PTBL_visitPriorities(PTBL_Priorities arg, PTBL_Priority (*acceptHead)(PTBL_Priority)) {
  if (PTBL_isPrioritiesEmpty(arg)) {
    return PTBL_makePrioritiesEmpty();
  }
  if (PTBL_isPrioritiesSingle(arg)) {
    return PTBL_makePrioritiesSingle(
        acceptHead ? acceptHead(PTBL_getPrioritiesHead(arg)) : PTBL_getPrioritiesHead(arg));
  }
  if (PTBL_isPrioritiesMany(arg)) {
    return PTBL_makePrioritiesMany(
        acceptHead ? acceptHead(PTBL_getPrioritiesHead(arg)) : PTBL_getPrioritiesHead(arg),
        PTBL_visitPriorities(PTBL_getPrioritiesTail(arg), acceptHead));
  }
  ATabort("not a Priorities: %t\n", arg);
  return (PTBL_Priorities)NULL;
}
PTBL_Priority PTBL_visitPriority(PTBL_Priority arg, int (*acceptLabel1)(int), int (*acceptLabel2)(int), int (*acceptArgumentNumber)(int)) {
  if (PTBL_isPriorityGreater(arg)) {
    return PTBL_makePriorityGreater(
        acceptLabel1 ? acceptLabel1(PTBL_getPriorityLabel1(arg)) : PTBL_getPriorityLabel1(arg),
        acceptLabel2 ? acceptLabel2(PTBL_getPriorityLabel2(arg)) : PTBL_getPriorityLabel2(arg));
  }
  if (PTBL_isPriorityArgGreater(arg)) {
    return PTBL_makePriorityArgGreater(
        acceptLabel1 ? acceptLabel1(PTBL_getPriorityLabel1(arg)) : PTBL_getPriorityLabel1(arg),
        acceptArgumentNumber ? acceptArgumentNumber(PTBL_getPriorityArgumentNumber(arg)) : PTBL_getPriorityArgumentNumber(arg),
        acceptLabel2 ? acceptLabel2(PTBL_getPriorityLabel2(arg)) : PTBL_getPriorityLabel2(arg));
  }
  ATabort("not a Priority: %t\n", arg);
  return (PTBL_Priority)NULL;
}

