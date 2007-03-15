#ifndef _PTABLE_H
#define _PTABLE_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "ptable_dict.h"

typedef struct _PTBL_Production *PTBL_Production;
typedef struct _PTBL_CharClass *PTBL_CharClass;
typedef struct _PTBL_CharRanges *PTBL_CharRanges;
typedef struct _PTBL_Version *PTBL_Version;
typedef struct _PTBL_ParseTable *PTBL_ParseTable;
typedef struct _PTBL_Labels *PTBL_Labels;
typedef struct _PTBL_Label *PTBL_Label;
typedef struct _PTBL_States *PTBL_States;
typedef struct _PTBL_State *PTBL_State;
typedef struct _PTBL_Gotos *PTBL_Gotos;
typedef struct _PTBL_Goto *PTBL_Goto;
typedef struct _PTBL_Choices *PTBL_Choices;
typedef struct _PTBL_Choice *PTBL_Choice;
typedef struct _PTBL_Actions *PTBL_Actions;
typedef struct _PTBL_Action *PTBL_Action;
typedef struct _PTBL_SpecialAttr *PTBL_SpecialAttr;
typedef struct _PTBL_Restrictions *PTBL_Restrictions;
typedef struct _PTBL_Restriction *PTBL_Restriction;
typedef struct _PTBL_CharClasses *PTBL_CharClasses;
typedef struct _PTBL_Priorities *PTBL_Priorities;
typedef struct _PTBL_Priority *PTBL_Priority;

#ifdef FAST_API
#define PTBL_initPtableApi() (init_ptable_dict())
#else
void _PTBL_initPtableApi(void);
#define PTBL_initPtableApi() (_PTBL_initPtableApi())
#endif

#ifdef FAST_API
#define PTBL_protectProduction(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectProduction(PTBL_Production *arg);
#define PTBL_protectProduction(arg) (_PTBL_protectProduction(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectProduction(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectProduction(PTBL_Production *arg);
#define PTBL_unprotectProduction(arg) (_PTBL_unprotectProduction(arg))
#endif
#ifdef FAST_API
#define PTBL_protectCharClass(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectCharClass(PTBL_CharClass *arg);
#define PTBL_protectCharClass(arg) (_PTBL_protectCharClass(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectCharClass(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectCharClass(PTBL_CharClass *arg);
#define PTBL_unprotectCharClass(arg) (_PTBL_unprotectCharClass(arg))
#endif
#ifdef FAST_API
#define PTBL_protectCharRanges(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectCharRanges(PTBL_CharRanges *arg);
#define PTBL_protectCharRanges(arg) (_PTBL_protectCharRanges(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectCharRanges(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectCharRanges(PTBL_CharRanges *arg);
#define PTBL_unprotectCharRanges(arg) (_PTBL_unprotectCharRanges(arg))
#endif
#ifdef FAST_API
#define PTBL_protectVersion(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectVersion(PTBL_Version *arg);
#define PTBL_protectVersion(arg) (_PTBL_protectVersion(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectVersion(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectVersion(PTBL_Version *arg);
#define PTBL_unprotectVersion(arg) (_PTBL_unprotectVersion(arg))
#endif
#ifdef FAST_API
#define PTBL_protectParseTable(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectParseTable(PTBL_ParseTable *arg);
#define PTBL_protectParseTable(arg) (_PTBL_protectParseTable(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectParseTable(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectParseTable(PTBL_ParseTable *arg);
#define PTBL_unprotectParseTable(arg) (_PTBL_unprotectParseTable(arg))
#endif
#ifdef FAST_API
#define PTBL_protectLabels(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectLabels(PTBL_Labels *arg);
#define PTBL_protectLabels(arg) (_PTBL_protectLabels(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectLabels(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectLabels(PTBL_Labels *arg);
#define PTBL_unprotectLabels(arg) (_PTBL_unprotectLabels(arg))
#endif
#ifdef FAST_API
#define PTBL_protectLabel(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectLabel(PTBL_Label *arg);
#define PTBL_protectLabel(arg) (_PTBL_protectLabel(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectLabel(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectLabel(PTBL_Label *arg);
#define PTBL_unprotectLabel(arg) (_PTBL_unprotectLabel(arg))
#endif
#ifdef FAST_API
#define PTBL_protectStates(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectStates(PTBL_States *arg);
#define PTBL_protectStates(arg) (_PTBL_protectStates(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectStates(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectStates(PTBL_States *arg);
#define PTBL_unprotectStates(arg) (_PTBL_unprotectStates(arg))
#endif
#ifdef FAST_API
#define PTBL_protectState(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectState(PTBL_State *arg);
#define PTBL_protectState(arg) (_PTBL_protectState(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectState(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectState(PTBL_State *arg);
#define PTBL_unprotectState(arg) (_PTBL_unprotectState(arg))
#endif
#ifdef FAST_API
#define PTBL_protectGotos(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectGotos(PTBL_Gotos *arg);
#define PTBL_protectGotos(arg) (_PTBL_protectGotos(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectGotos(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectGotos(PTBL_Gotos *arg);
#define PTBL_unprotectGotos(arg) (_PTBL_unprotectGotos(arg))
#endif
#ifdef FAST_API
#define PTBL_protectGoto(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectGoto(PTBL_Goto *arg);
#define PTBL_protectGoto(arg) (_PTBL_protectGoto(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectGoto(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectGoto(PTBL_Goto *arg);
#define PTBL_unprotectGoto(arg) (_PTBL_unprotectGoto(arg))
#endif
#ifdef FAST_API
#define PTBL_protectChoices(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectChoices(PTBL_Choices *arg);
#define PTBL_protectChoices(arg) (_PTBL_protectChoices(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectChoices(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectChoices(PTBL_Choices *arg);
#define PTBL_unprotectChoices(arg) (_PTBL_unprotectChoices(arg))
#endif
#ifdef FAST_API
#define PTBL_protectChoice(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectChoice(PTBL_Choice *arg);
#define PTBL_protectChoice(arg) (_PTBL_protectChoice(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectChoice(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectChoice(PTBL_Choice *arg);
#define PTBL_unprotectChoice(arg) (_PTBL_unprotectChoice(arg))
#endif
#ifdef FAST_API
#define PTBL_protectActions(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectActions(PTBL_Actions *arg);
#define PTBL_protectActions(arg) (_PTBL_protectActions(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectActions(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectActions(PTBL_Actions *arg);
#define PTBL_unprotectActions(arg) (_PTBL_unprotectActions(arg))
#endif
#ifdef FAST_API
#define PTBL_protectAction(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectAction(PTBL_Action *arg);
#define PTBL_protectAction(arg) (_PTBL_protectAction(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectAction(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectAction(PTBL_Action *arg);
#define PTBL_unprotectAction(arg) (_PTBL_unprotectAction(arg))
#endif
#ifdef FAST_API
#define PTBL_protectSpecialAttr(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectSpecialAttr(PTBL_SpecialAttr *arg);
#define PTBL_protectSpecialAttr(arg) (_PTBL_protectSpecialAttr(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectSpecialAttr(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectSpecialAttr(PTBL_SpecialAttr *arg);
#define PTBL_unprotectSpecialAttr(arg) (_PTBL_unprotectSpecialAttr(arg))
#endif
#ifdef FAST_API
#define PTBL_protectRestrictions(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectRestrictions(PTBL_Restrictions *arg);
#define PTBL_protectRestrictions(arg) (_PTBL_protectRestrictions(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectRestrictions(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectRestrictions(PTBL_Restrictions *arg);
#define PTBL_unprotectRestrictions(arg) (_PTBL_unprotectRestrictions(arg))
#endif
#ifdef FAST_API
#define PTBL_protectRestriction(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectRestriction(PTBL_Restriction *arg);
#define PTBL_protectRestriction(arg) (_PTBL_protectRestriction(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectRestriction(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectRestriction(PTBL_Restriction *arg);
#define PTBL_unprotectRestriction(arg) (_PTBL_unprotectRestriction(arg))
#endif
#ifdef FAST_API
#define PTBL_protectCharClasses(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectCharClasses(PTBL_CharClasses *arg);
#define PTBL_protectCharClasses(arg) (_PTBL_protectCharClasses(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectCharClasses(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectCharClasses(PTBL_CharClasses *arg);
#define PTBL_unprotectCharClasses(arg) (_PTBL_unprotectCharClasses(arg))
#endif
#ifdef FAST_API
#define PTBL_protectPriorities(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectPriorities(PTBL_Priorities *arg);
#define PTBL_protectPriorities(arg) (_PTBL_protectPriorities(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectPriorities(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectPriorities(PTBL_Priorities *arg);
#define PTBL_unprotectPriorities(arg) (_PTBL_unprotectPriorities(arg))
#endif
#ifdef FAST_API
#define PTBL_protectPriority(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_protectPriority(PTBL_Priority *arg);
#define PTBL_protectPriority(arg) (_PTBL_protectPriority(arg))
#endif
#ifdef FAST_API
#define PTBL_unprotectPriority(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PTBL_unprotectPriority(PTBL_Priority *arg);
#define PTBL_unprotectPriority(arg) (_PTBL_unprotectPriority(arg))
#endif
#ifdef FAST_API
#define PTBL_ProductionFromTerm(t) ((PTBL_Production)(t))
#else
PTBL_Production _PTBL_ProductionFromTerm(ATerm t);
#define PTBL_ProductionFromTerm(t) (_PTBL_ProductionFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_ProductionToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_ProductionToTerm(PTBL_Production arg);
#define PTBL_ProductionToTerm(arg) (_PTBL_ProductionToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_CharClassFromTerm(t) ((PTBL_CharClass)(t))
#else
PTBL_CharClass _PTBL_CharClassFromTerm(ATerm t);
#define PTBL_CharClassFromTerm(t) (_PTBL_CharClassFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_CharClassToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_CharClassToTerm(PTBL_CharClass arg);
#define PTBL_CharClassToTerm(arg) (_PTBL_CharClassToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_CharRangesFromTerm(t) ((PTBL_CharRanges)(t))
#else
PTBL_CharRanges _PTBL_CharRangesFromTerm(ATerm t);
#define PTBL_CharRangesFromTerm(t) (_PTBL_CharRangesFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_CharRangesToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_CharRangesToTerm(PTBL_CharRanges arg);
#define PTBL_CharRangesToTerm(arg) (_PTBL_CharRangesToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_VersionFromTerm(t) ((PTBL_Version)(t))
#else
PTBL_Version _PTBL_VersionFromTerm(ATerm t);
#define PTBL_VersionFromTerm(t) (_PTBL_VersionFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_VersionToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_VersionToTerm(PTBL_Version arg);
#define PTBL_VersionToTerm(arg) (_PTBL_VersionToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_ParseTableFromTerm(t) ((PTBL_ParseTable)(t))
#else
PTBL_ParseTable _PTBL_ParseTableFromTerm(ATerm t);
#define PTBL_ParseTableFromTerm(t) (_PTBL_ParseTableFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_ParseTableToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_ParseTableToTerm(PTBL_ParseTable arg);
#define PTBL_ParseTableToTerm(arg) (_PTBL_ParseTableToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_LabelsFromTerm(t) ((PTBL_Labels)(t))
#else
PTBL_Labels _PTBL_LabelsFromTerm(ATerm t);
#define PTBL_LabelsFromTerm(t) (_PTBL_LabelsFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_LabelsToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_LabelsToTerm(PTBL_Labels arg);
#define PTBL_LabelsToTerm(arg) (_PTBL_LabelsToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_LabelFromTerm(t) ((PTBL_Label)(t))
#else
PTBL_Label _PTBL_LabelFromTerm(ATerm t);
#define PTBL_LabelFromTerm(t) (_PTBL_LabelFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_LabelToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_LabelToTerm(PTBL_Label arg);
#define PTBL_LabelToTerm(arg) (_PTBL_LabelToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_StatesFromTerm(t) ((PTBL_States)(t))
#else
PTBL_States _PTBL_StatesFromTerm(ATerm t);
#define PTBL_StatesFromTerm(t) (_PTBL_StatesFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_StatesToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_StatesToTerm(PTBL_States arg);
#define PTBL_StatesToTerm(arg) (_PTBL_StatesToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_StateFromTerm(t) ((PTBL_State)(t))
#else
PTBL_State _PTBL_StateFromTerm(ATerm t);
#define PTBL_StateFromTerm(t) (_PTBL_StateFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_StateToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_StateToTerm(PTBL_State arg);
#define PTBL_StateToTerm(arg) (_PTBL_StateToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_GotosFromTerm(t) ((PTBL_Gotos)(t))
#else
PTBL_Gotos _PTBL_GotosFromTerm(ATerm t);
#define PTBL_GotosFromTerm(t) (_PTBL_GotosFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_GotosToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_GotosToTerm(PTBL_Gotos arg);
#define PTBL_GotosToTerm(arg) (_PTBL_GotosToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_GotoFromTerm(t) ((PTBL_Goto)(t))
#else
PTBL_Goto _PTBL_GotoFromTerm(ATerm t);
#define PTBL_GotoFromTerm(t) (_PTBL_GotoFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_GotoToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_GotoToTerm(PTBL_Goto arg);
#define PTBL_GotoToTerm(arg) (_PTBL_GotoToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_ChoicesFromTerm(t) ((PTBL_Choices)(t))
#else
PTBL_Choices _PTBL_ChoicesFromTerm(ATerm t);
#define PTBL_ChoicesFromTerm(t) (_PTBL_ChoicesFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_ChoicesToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_ChoicesToTerm(PTBL_Choices arg);
#define PTBL_ChoicesToTerm(arg) (_PTBL_ChoicesToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_ChoiceFromTerm(t) ((PTBL_Choice)(t))
#else
PTBL_Choice _PTBL_ChoiceFromTerm(ATerm t);
#define PTBL_ChoiceFromTerm(t) (_PTBL_ChoiceFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_ChoiceToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_ChoiceToTerm(PTBL_Choice arg);
#define PTBL_ChoiceToTerm(arg) (_PTBL_ChoiceToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_ActionsFromTerm(t) ((PTBL_Actions)(t))
#else
PTBL_Actions _PTBL_ActionsFromTerm(ATerm t);
#define PTBL_ActionsFromTerm(t) (_PTBL_ActionsFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_ActionsToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_ActionsToTerm(PTBL_Actions arg);
#define PTBL_ActionsToTerm(arg) (_PTBL_ActionsToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_ActionFromTerm(t) ((PTBL_Action)(t))
#else
PTBL_Action _PTBL_ActionFromTerm(ATerm t);
#define PTBL_ActionFromTerm(t) (_PTBL_ActionFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_ActionToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_ActionToTerm(PTBL_Action arg);
#define PTBL_ActionToTerm(arg) (_PTBL_ActionToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_SpecialAttrFromTerm(t) ((PTBL_SpecialAttr)(t))
#else
PTBL_SpecialAttr _PTBL_SpecialAttrFromTerm(ATerm t);
#define PTBL_SpecialAttrFromTerm(t) (_PTBL_SpecialAttrFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_SpecialAttrToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_SpecialAttrToTerm(PTBL_SpecialAttr arg);
#define PTBL_SpecialAttrToTerm(arg) (_PTBL_SpecialAttrToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_RestrictionsFromTerm(t) ((PTBL_Restrictions)(t))
#else
PTBL_Restrictions _PTBL_RestrictionsFromTerm(ATerm t);
#define PTBL_RestrictionsFromTerm(t) (_PTBL_RestrictionsFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_RestrictionsToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_RestrictionsToTerm(PTBL_Restrictions arg);
#define PTBL_RestrictionsToTerm(arg) (_PTBL_RestrictionsToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_RestrictionFromTerm(t) ((PTBL_Restriction)(t))
#else
PTBL_Restriction _PTBL_RestrictionFromTerm(ATerm t);
#define PTBL_RestrictionFromTerm(t) (_PTBL_RestrictionFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_RestrictionToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_RestrictionToTerm(PTBL_Restriction arg);
#define PTBL_RestrictionToTerm(arg) (_PTBL_RestrictionToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_CharClassesFromTerm(t) ((PTBL_CharClasses)(t))
#else
PTBL_CharClasses _PTBL_CharClassesFromTerm(ATerm t);
#define PTBL_CharClassesFromTerm(t) (_PTBL_CharClassesFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_CharClassesToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_CharClassesToTerm(PTBL_CharClasses arg);
#define PTBL_CharClassesToTerm(arg) (_PTBL_CharClassesToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_PrioritiesFromTerm(t) ((PTBL_Priorities)(t))
#else
PTBL_Priorities _PTBL_PrioritiesFromTerm(ATerm t);
#define PTBL_PrioritiesFromTerm(t) (_PTBL_PrioritiesFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_PrioritiesToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_PrioritiesToTerm(PTBL_Priorities arg);
#define PTBL_PrioritiesToTerm(arg) (_PTBL_PrioritiesToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_PriorityFromTerm(t) ((PTBL_Priority)(t))
#else
PTBL_Priority _PTBL_PriorityFromTerm(ATerm t);
#define PTBL_PriorityFromTerm(t) (_PTBL_PriorityFromTerm(t))
#endif
#ifdef FAST_API
#define PTBL_PriorityToTerm(arg) ((ATerm)(arg))
#else
ATerm _PTBL_PriorityToTerm(PTBL_Priority arg);
#define PTBL_PriorityToTerm(arg) (_PTBL_PriorityToTerm(arg))
#endif
#ifdef FAST_API
#define PTBL_getLabelsLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PTBL_getLabelsLength(PTBL_Labels arg);
#define PTBL_getLabelsLength(arg) (_PTBL_getLabelsLength(arg))
#endif
#ifdef FAST_API
#define PTBL_reverseLabels(arg) ((PTBL_Labels) ATreverse((ATermList) (arg)))
#else
PTBL_Labels _PTBL_reverseLabels(PTBL_Labels arg);
#define PTBL_reverseLabels(arg) (_PTBL_reverseLabels(arg))
#endif
#ifdef FAST_API
#define PTBL_appendLabels(arg, elem) ((PTBL_Labels) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PTBL_Labels _PTBL_appendLabels(PTBL_Labels arg, PTBL_Label elem);
#define PTBL_appendLabels(arg, elem) (_PTBL_appendLabels(arg, elem))
#endif
#ifdef FAST_API
#define PTBL_concatLabels(arg0, arg1) ((PTBL_Labels) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PTBL_Labels _PTBL_concatLabels(PTBL_Labels arg0, PTBL_Labels arg1);
#define PTBL_concatLabels(arg0, arg1) (_PTBL_concatLabels(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_sliceLabels(arg, start, end) ((PTBL_Labels) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PTBL_Labels _PTBL_sliceLabels(PTBL_Labels arg, int start, int end);
#define PTBL_sliceLabels(arg, start, end) (_PTBL_sliceLabels(arg, start, end))
#endif
#ifdef FAST_API
#define PTBL_getLabelsLabelAt(arg, index) ((PTBL_Label) (ATelementAt((ATermList) arg,index)))
#else
PTBL_Label _PTBL_getLabelsLabelAt(PTBL_Labels arg, int index);
#define PTBL_getLabelsLabelAt(arg, index) (_PTBL_getLabelsLabelAt(arg, index))
#endif
#ifdef FAST_API
#define PTBL_replaceLabelsLabelAt(arg, elem, index) ((PTBL_Labels) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PTBL_Labels _PTBL_replaceLabelsLabelAt(PTBL_Labels arg, PTBL_Label elem, int index);
#define PTBL_replaceLabelsLabelAt(arg, elem, index) (_PTBL_replaceLabelsLabelAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PTBL_makeLabels2(elem1,  elem2) ((PTBL_Labels) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PTBL_Labels _PTBL_makeLabels2(PTBL_Label elem1, PTBL_Label elem2);
#define PTBL_makeLabels2(elem1,  elem2) (_PTBL_makeLabels2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PTBL_makeLabels3(elem1, elem2,  elem3) ((PTBL_Labels) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PTBL_Labels _PTBL_makeLabels3(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3);
#define PTBL_makeLabels3(elem1, elem2,  elem3) (_PTBL_makeLabels3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PTBL_makeLabels4(elem1, elem2, elem3,  elem4) ((PTBL_Labels) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PTBL_Labels _PTBL_makeLabels4(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3, PTBL_Label elem4);
#define PTBL_makeLabels4(elem1, elem2, elem3,  elem4) (_PTBL_makeLabels4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PTBL_makeLabels5(elem1, elem2, elem3, elem4,  elem5) ((PTBL_Labels) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PTBL_Labels _PTBL_makeLabels5(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3, PTBL_Label elem4, PTBL_Label elem5);
#define PTBL_makeLabels5(elem1, elem2, elem3, elem4,  elem5) (_PTBL_makeLabels5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PTBL_makeLabels6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PTBL_Labels) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PTBL_Labels _PTBL_makeLabels6(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3, PTBL_Label elem4, PTBL_Label elem5, PTBL_Label elem6);
#define PTBL_makeLabels6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PTBL_makeLabels6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define PTBL_getStatesLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PTBL_getStatesLength(PTBL_States arg);
#define PTBL_getStatesLength(arg) (_PTBL_getStatesLength(arg))
#endif
#ifdef FAST_API
#define PTBL_reverseStates(arg) ((PTBL_States) ATreverse((ATermList) (arg)))
#else
PTBL_States _PTBL_reverseStates(PTBL_States arg);
#define PTBL_reverseStates(arg) (_PTBL_reverseStates(arg))
#endif
#ifdef FAST_API
#define PTBL_appendStates(arg, elem) ((PTBL_States) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PTBL_States _PTBL_appendStates(PTBL_States arg, PTBL_State elem);
#define PTBL_appendStates(arg, elem) (_PTBL_appendStates(arg, elem))
#endif
#ifdef FAST_API
#define PTBL_concatStates(arg0, arg1) ((PTBL_States) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PTBL_States _PTBL_concatStates(PTBL_States arg0, PTBL_States arg1);
#define PTBL_concatStates(arg0, arg1) (_PTBL_concatStates(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_sliceStates(arg, start, end) ((PTBL_States) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PTBL_States _PTBL_sliceStates(PTBL_States arg, int start, int end);
#define PTBL_sliceStates(arg, start, end) (_PTBL_sliceStates(arg, start, end))
#endif
#ifdef FAST_API
#define PTBL_getStatesStateAt(arg, index) ((PTBL_State) (ATelementAt((ATermList) arg,index)))
#else
PTBL_State _PTBL_getStatesStateAt(PTBL_States arg, int index);
#define PTBL_getStatesStateAt(arg, index) (_PTBL_getStatesStateAt(arg, index))
#endif
#ifdef FAST_API
#define PTBL_replaceStatesStateAt(arg, elem, index) ((PTBL_States) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PTBL_States _PTBL_replaceStatesStateAt(PTBL_States arg, PTBL_State elem, int index);
#define PTBL_replaceStatesStateAt(arg, elem, index) (_PTBL_replaceStatesStateAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PTBL_makeStates2(elem1,  elem2) ((PTBL_States) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PTBL_States _PTBL_makeStates2(PTBL_State elem1, PTBL_State elem2);
#define PTBL_makeStates2(elem1,  elem2) (_PTBL_makeStates2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PTBL_makeStates3(elem1, elem2,  elem3) ((PTBL_States) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PTBL_States _PTBL_makeStates3(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3);
#define PTBL_makeStates3(elem1, elem2,  elem3) (_PTBL_makeStates3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PTBL_makeStates4(elem1, elem2, elem3,  elem4) ((PTBL_States) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PTBL_States _PTBL_makeStates4(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3, PTBL_State elem4);
#define PTBL_makeStates4(elem1, elem2, elem3,  elem4) (_PTBL_makeStates4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PTBL_makeStates5(elem1, elem2, elem3, elem4,  elem5) ((PTBL_States) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PTBL_States _PTBL_makeStates5(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3, PTBL_State elem4, PTBL_State elem5);
#define PTBL_makeStates5(elem1, elem2, elem3, elem4,  elem5) (_PTBL_makeStates5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PTBL_makeStates6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PTBL_States) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PTBL_States _PTBL_makeStates6(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3, PTBL_State elem4, PTBL_State elem5, PTBL_State elem6);
#define PTBL_makeStates6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PTBL_makeStates6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define PTBL_getGotosLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PTBL_getGotosLength(PTBL_Gotos arg);
#define PTBL_getGotosLength(arg) (_PTBL_getGotosLength(arg))
#endif
#ifdef FAST_API
#define PTBL_reverseGotos(arg) ((PTBL_Gotos) ATreverse((ATermList) (arg)))
#else
PTBL_Gotos _PTBL_reverseGotos(PTBL_Gotos arg);
#define PTBL_reverseGotos(arg) (_PTBL_reverseGotos(arg))
#endif
#ifdef FAST_API
#define PTBL_appendGotos(arg, elem) ((PTBL_Gotos) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PTBL_Gotos _PTBL_appendGotos(PTBL_Gotos arg, PTBL_Goto elem);
#define PTBL_appendGotos(arg, elem) (_PTBL_appendGotos(arg, elem))
#endif
#ifdef FAST_API
#define PTBL_concatGotos(arg0, arg1) ((PTBL_Gotos) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PTBL_Gotos _PTBL_concatGotos(PTBL_Gotos arg0, PTBL_Gotos arg1);
#define PTBL_concatGotos(arg0, arg1) (_PTBL_concatGotos(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_sliceGotos(arg, start, end) ((PTBL_Gotos) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PTBL_Gotos _PTBL_sliceGotos(PTBL_Gotos arg, int start, int end);
#define PTBL_sliceGotos(arg, start, end) (_PTBL_sliceGotos(arg, start, end))
#endif
#ifdef FAST_API
#define PTBL_getGotosGotoAt(arg, index) ((PTBL_Goto) (ATelementAt((ATermList) arg,index)))
#else
PTBL_Goto _PTBL_getGotosGotoAt(PTBL_Gotos arg, int index);
#define PTBL_getGotosGotoAt(arg, index) (_PTBL_getGotosGotoAt(arg, index))
#endif
#ifdef FAST_API
#define PTBL_replaceGotosGotoAt(arg, elem, index) ((PTBL_Gotos) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PTBL_Gotos _PTBL_replaceGotosGotoAt(PTBL_Gotos arg, PTBL_Goto elem, int index);
#define PTBL_replaceGotosGotoAt(arg, elem, index) (_PTBL_replaceGotosGotoAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PTBL_makeGotos2(elem1,  elem2) ((PTBL_Gotos) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PTBL_Gotos _PTBL_makeGotos2(PTBL_Goto elem1, PTBL_Goto elem2);
#define PTBL_makeGotos2(elem1,  elem2) (_PTBL_makeGotos2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PTBL_makeGotos3(elem1, elem2,  elem3) ((PTBL_Gotos) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PTBL_Gotos _PTBL_makeGotos3(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3);
#define PTBL_makeGotos3(elem1, elem2,  elem3) (_PTBL_makeGotos3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PTBL_makeGotos4(elem1, elem2, elem3,  elem4) ((PTBL_Gotos) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PTBL_Gotos _PTBL_makeGotos4(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3, PTBL_Goto elem4);
#define PTBL_makeGotos4(elem1, elem2, elem3,  elem4) (_PTBL_makeGotos4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PTBL_makeGotos5(elem1, elem2, elem3, elem4,  elem5) ((PTBL_Gotos) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PTBL_Gotos _PTBL_makeGotos5(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3, PTBL_Goto elem4, PTBL_Goto elem5);
#define PTBL_makeGotos5(elem1, elem2, elem3, elem4,  elem5) (_PTBL_makeGotos5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PTBL_makeGotos6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PTBL_Gotos) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PTBL_Gotos _PTBL_makeGotos6(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3, PTBL_Goto elem4, PTBL_Goto elem5, PTBL_Goto elem6);
#define PTBL_makeGotos6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PTBL_makeGotos6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define PTBL_getChoicesLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PTBL_getChoicesLength(PTBL_Choices arg);
#define PTBL_getChoicesLength(arg) (_PTBL_getChoicesLength(arg))
#endif
#ifdef FAST_API
#define PTBL_reverseChoices(arg) ((PTBL_Choices) ATreverse((ATermList) (arg)))
#else
PTBL_Choices _PTBL_reverseChoices(PTBL_Choices arg);
#define PTBL_reverseChoices(arg) (_PTBL_reverseChoices(arg))
#endif
#ifdef FAST_API
#define PTBL_appendChoices(arg, elem) ((PTBL_Choices) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PTBL_Choices _PTBL_appendChoices(PTBL_Choices arg, PTBL_Choice elem);
#define PTBL_appendChoices(arg, elem) (_PTBL_appendChoices(arg, elem))
#endif
#ifdef FAST_API
#define PTBL_concatChoices(arg0, arg1) ((PTBL_Choices) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PTBL_Choices _PTBL_concatChoices(PTBL_Choices arg0, PTBL_Choices arg1);
#define PTBL_concatChoices(arg0, arg1) (_PTBL_concatChoices(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_sliceChoices(arg, start, end) ((PTBL_Choices) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PTBL_Choices _PTBL_sliceChoices(PTBL_Choices arg, int start, int end);
#define PTBL_sliceChoices(arg, start, end) (_PTBL_sliceChoices(arg, start, end))
#endif
#ifdef FAST_API
#define PTBL_getChoicesChoiceAt(arg, index) ((PTBL_Choice) (ATelementAt((ATermList) arg,index)))
#else
PTBL_Choice _PTBL_getChoicesChoiceAt(PTBL_Choices arg, int index);
#define PTBL_getChoicesChoiceAt(arg, index) (_PTBL_getChoicesChoiceAt(arg, index))
#endif
#ifdef FAST_API
#define PTBL_replaceChoicesChoiceAt(arg, elem, index) ((PTBL_Choices) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PTBL_Choices _PTBL_replaceChoicesChoiceAt(PTBL_Choices arg, PTBL_Choice elem, int index);
#define PTBL_replaceChoicesChoiceAt(arg, elem, index) (_PTBL_replaceChoicesChoiceAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PTBL_makeChoices2(elem1,  elem2) ((PTBL_Choices) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PTBL_Choices _PTBL_makeChoices2(PTBL_Choice elem1, PTBL_Choice elem2);
#define PTBL_makeChoices2(elem1,  elem2) (_PTBL_makeChoices2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PTBL_makeChoices3(elem1, elem2,  elem3) ((PTBL_Choices) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PTBL_Choices _PTBL_makeChoices3(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3);
#define PTBL_makeChoices3(elem1, elem2,  elem3) (_PTBL_makeChoices3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PTBL_makeChoices4(elem1, elem2, elem3,  elem4) ((PTBL_Choices) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PTBL_Choices _PTBL_makeChoices4(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3, PTBL_Choice elem4);
#define PTBL_makeChoices4(elem1, elem2, elem3,  elem4) (_PTBL_makeChoices4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PTBL_makeChoices5(elem1, elem2, elem3, elem4,  elem5) ((PTBL_Choices) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PTBL_Choices _PTBL_makeChoices5(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3, PTBL_Choice elem4, PTBL_Choice elem5);
#define PTBL_makeChoices5(elem1, elem2, elem3, elem4,  elem5) (_PTBL_makeChoices5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PTBL_makeChoices6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PTBL_Choices) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PTBL_Choices _PTBL_makeChoices6(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3, PTBL_Choice elem4, PTBL_Choice elem5, PTBL_Choice elem6);
#define PTBL_makeChoices6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PTBL_makeChoices6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define PTBL_getActionsLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PTBL_getActionsLength(PTBL_Actions arg);
#define PTBL_getActionsLength(arg) (_PTBL_getActionsLength(arg))
#endif
#ifdef FAST_API
#define PTBL_reverseActions(arg) ((PTBL_Actions) ATreverse((ATermList) (arg)))
#else
PTBL_Actions _PTBL_reverseActions(PTBL_Actions arg);
#define PTBL_reverseActions(arg) (_PTBL_reverseActions(arg))
#endif
#ifdef FAST_API
#define PTBL_appendActions(arg, elem) ((PTBL_Actions) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PTBL_Actions _PTBL_appendActions(PTBL_Actions arg, PTBL_Action elem);
#define PTBL_appendActions(arg, elem) (_PTBL_appendActions(arg, elem))
#endif
#ifdef FAST_API
#define PTBL_concatActions(arg0, arg1) ((PTBL_Actions) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PTBL_Actions _PTBL_concatActions(PTBL_Actions arg0, PTBL_Actions arg1);
#define PTBL_concatActions(arg0, arg1) (_PTBL_concatActions(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_sliceActions(arg, start, end) ((PTBL_Actions) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PTBL_Actions _PTBL_sliceActions(PTBL_Actions arg, int start, int end);
#define PTBL_sliceActions(arg, start, end) (_PTBL_sliceActions(arg, start, end))
#endif
#ifdef FAST_API
#define PTBL_getActionsActionAt(arg, index) ((PTBL_Action) (ATelementAt((ATermList) arg,index)))
#else
PTBL_Action _PTBL_getActionsActionAt(PTBL_Actions arg, int index);
#define PTBL_getActionsActionAt(arg, index) (_PTBL_getActionsActionAt(arg, index))
#endif
#ifdef FAST_API
#define PTBL_replaceActionsActionAt(arg, elem, index) ((PTBL_Actions) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PTBL_Actions _PTBL_replaceActionsActionAt(PTBL_Actions arg, PTBL_Action elem, int index);
#define PTBL_replaceActionsActionAt(arg, elem, index) (_PTBL_replaceActionsActionAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PTBL_makeActions2(elem1,  elem2) ((PTBL_Actions) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PTBL_Actions _PTBL_makeActions2(PTBL_Action elem1, PTBL_Action elem2);
#define PTBL_makeActions2(elem1,  elem2) (_PTBL_makeActions2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PTBL_makeActions3(elem1, elem2,  elem3) ((PTBL_Actions) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PTBL_Actions _PTBL_makeActions3(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3);
#define PTBL_makeActions3(elem1, elem2,  elem3) (_PTBL_makeActions3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PTBL_makeActions4(elem1, elem2, elem3,  elem4) ((PTBL_Actions) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PTBL_Actions _PTBL_makeActions4(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3, PTBL_Action elem4);
#define PTBL_makeActions4(elem1, elem2, elem3,  elem4) (_PTBL_makeActions4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PTBL_makeActions5(elem1, elem2, elem3, elem4,  elem5) ((PTBL_Actions) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PTBL_Actions _PTBL_makeActions5(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3, PTBL_Action elem4, PTBL_Action elem5);
#define PTBL_makeActions5(elem1, elem2, elem3, elem4,  elem5) (_PTBL_makeActions5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PTBL_makeActions6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PTBL_Actions) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PTBL_Actions _PTBL_makeActions6(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3, PTBL_Action elem4, PTBL_Action elem5, PTBL_Action elem6);
#define PTBL_makeActions6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PTBL_makeActions6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define PTBL_getRestrictionsLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PTBL_getRestrictionsLength(PTBL_Restrictions arg);
#define PTBL_getRestrictionsLength(arg) (_PTBL_getRestrictionsLength(arg))
#endif
#ifdef FAST_API
#define PTBL_reverseRestrictions(arg) ((PTBL_Restrictions) ATreverse((ATermList) (arg)))
#else
PTBL_Restrictions _PTBL_reverseRestrictions(PTBL_Restrictions arg);
#define PTBL_reverseRestrictions(arg) (_PTBL_reverseRestrictions(arg))
#endif
#ifdef FAST_API
#define PTBL_appendRestrictions(arg, elem) ((PTBL_Restrictions) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PTBL_Restrictions _PTBL_appendRestrictions(PTBL_Restrictions arg, PTBL_Restriction elem);
#define PTBL_appendRestrictions(arg, elem) (_PTBL_appendRestrictions(arg, elem))
#endif
#ifdef FAST_API
#define PTBL_concatRestrictions(arg0, arg1) ((PTBL_Restrictions) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PTBL_Restrictions _PTBL_concatRestrictions(PTBL_Restrictions arg0, PTBL_Restrictions arg1);
#define PTBL_concatRestrictions(arg0, arg1) (_PTBL_concatRestrictions(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_sliceRestrictions(arg, start, end) ((PTBL_Restrictions) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PTBL_Restrictions _PTBL_sliceRestrictions(PTBL_Restrictions arg, int start, int end);
#define PTBL_sliceRestrictions(arg, start, end) (_PTBL_sliceRestrictions(arg, start, end))
#endif
#ifdef FAST_API
#define PTBL_getRestrictionsRestrictionAt(arg, index) ((PTBL_Restriction) (ATelementAt((ATermList) arg,index)))
#else
PTBL_Restriction _PTBL_getRestrictionsRestrictionAt(PTBL_Restrictions arg, int index);
#define PTBL_getRestrictionsRestrictionAt(arg, index) (_PTBL_getRestrictionsRestrictionAt(arg, index))
#endif
#ifdef FAST_API
#define PTBL_replaceRestrictionsRestrictionAt(arg, elem, index) ((PTBL_Restrictions) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PTBL_Restrictions _PTBL_replaceRestrictionsRestrictionAt(PTBL_Restrictions arg, PTBL_Restriction elem, int index);
#define PTBL_replaceRestrictionsRestrictionAt(arg, elem, index) (_PTBL_replaceRestrictionsRestrictionAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PTBL_makeRestrictions2(elem1,  elem2) ((PTBL_Restrictions) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PTBL_Restrictions _PTBL_makeRestrictions2(PTBL_Restriction elem1, PTBL_Restriction elem2);
#define PTBL_makeRestrictions2(elem1,  elem2) (_PTBL_makeRestrictions2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PTBL_makeRestrictions3(elem1, elem2,  elem3) ((PTBL_Restrictions) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PTBL_Restrictions _PTBL_makeRestrictions3(PTBL_Restriction elem1, PTBL_Restriction elem2, PTBL_Restriction elem3);
#define PTBL_makeRestrictions3(elem1, elem2,  elem3) (_PTBL_makeRestrictions3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PTBL_makeRestrictions4(elem1, elem2, elem3,  elem4) ((PTBL_Restrictions) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PTBL_Restrictions _PTBL_makeRestrictions4(PTBL_Restriction elem1, PTBL_Restriction elem2, PTBL_Restriction elem3, PTBL_Restriction elem4);
#define PTBL_makeRestrictions4(elem1, elem2, elem3,  elem4) (_PTBL_makeRestrictions4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PTBL_makeRestrictions5(elem1, elem2, elem3, elem4,  elem5) ((PTBL_Restrictions) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PTBL_Restrictions _PTBL_makeRestrictions5(PTBL_Restriction elem1, PTBL_Restriction elem2, PTBL_Restriction elem3, PTBL_Restriction elem4, PTBL_Restriction elem5);
#define PTBL_makeRestrictions5(elem1, elem2, elem3, elem4,  elem5) (_PTBL_makeRestrictions5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PTBL_makeRestrictions6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PTBL_Restrictions) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PTBL_Restrictions _PTBL_makeRestrictions6(PTBL_Restriction elem1, PTBL_Restriction elem2, PTBL_Restriction elem3, PTBL_Restriction elem4, PTBL_Restriction elem5, PTBL_Restriction elem6);
#define PTBL_makeRestrictions6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PTBL_makeRestrictions6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define PTBL_getCharClassesLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PTBL_getCharClassesLength(PTBL_CharClasses arg);
#define PTBL_getCharClassesLength(arg) (_PTBL_getCharClassesLength(arg))
#endif
#ifdef FAST_API
#define PTBL_reverseCharClasses(arg) ((PTBL_CharClasses) ATreverse((ATermList) (arg)))
#else
PTBL_CharClasses _PTBL_reverseCharClasses(PTBL_CharClasses arg);
#define PTBL_reverseCharClasses(arg) (_PTBL_reverseCharClasses(arg))
#endif
#ifdef FAST_API
#define PTBL_appendCharClasses(arg, elem) ((PTBL_CharClasses) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PTBL_CharClasses _PTBL_appendCharClasses(PTBL_CharClasses arg, PTBL_CharClass elem);
#define PTBL_appendCharClasses(arg, elem) (_PTBL_appendCharClasses(arg, elem))
#endif
#ifdef FAST_API
#define PTBL_concatCharClasses(arg0, arg1) ((PTBL_CharClasses) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PTBL_CharClasses _PTBL_concatCharClasses(PTBL_CharClasses arg0, PTBL_CharClasses arg1);
#define PTBL_concatCharClasses(arg0, arg1) (_PTBL_concatCharClasses(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_sliceCharClasses(arg, start, end) ((PTBL_CharClasses) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PTBL_CharClasses _PTBL_sliceCharClasses(PTBL_CharClasses arg, int start, int end);
#define PTBL_sliceCharClasses(arg, start, end) (_PTBL_sliceCharClasses(arg, start, end))
#endif
#ifdef FAST_API
#define PTBL_getCharClassesCharClassAt(arg, index) ((PTBL_CharClass) (ATelementAt((ATermList) arg,index)))
#else
PTBL_CharClass _PTBL_getCharClassesCharClassAt(PTBL_CharClasses arg, int index);
#define PTBL_getCharClassesCharClassAt(arg, index) (_PTBL_getCharClassesCharClassAt(arg, index))
#endif
#ifdef FAST_API
#define PTBL_replaceCharClassesCharClassAt(arg, elem, index) ((PTBL_CharClasses) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PTBL_CharClasses _PTBL_replaceCharClassesCharClassAt(PTBL_CharClasses arg, PTBL_CharClass elem, int index);
#define PTBL_replaceCharClassesCharClassAt(arg, elem, index) (_PTBL_replaceCharClassesCharClassAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PTBL_makeCharClasses2(elem1,  elem2) ((PTBL_CharClasses) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PTBL_CharClasses _PTBL_makeCharClasses2(PTBL_CharClass elem1, PTBL_CharClass elem2);
#define PTBL_makeCharClasses2(elem1,  elem2) (_PTBL_makeCharClasses2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PTBL_makeCharClasses3(elem1, elem2,  elem3) ((PTBL_CharClasses) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PTBL_CharClasses _PTBL_makeCharClasses3(PTBL_CharClass elem1, PTBL_CharClass elem2, PTBL_CharClass elem3);
#define PTBL_makeCharClasses3(elem1, elem2,  elem3) (_PTBL_makeCharClasses3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PTBL_makeCharClasses4(elem1, elem2, elem3,  elem4) ((PTBL_CharClasses) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PTBL_CharClasses _PTBL_makeCharClasses4(PTBL_CharClass elem1, PTBL_CharClass elem2, PTBL_CharClass elem3, PTBL_CharClass elem4);
#define PTBL_makeCharClasses4(elem1, elem2, elem3,  elem4) (_PTBL_makeCharClasses4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PTBL_makeCharClasses5(elem1, elem2, elem3, elem4,  elem5) ((PTBL_CharClasses) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PTBL_CharClasses _PTBL_makeCharClasses5(PTBL_CharClass elem1, PTBL_CharClass elem2, PTBL_CharClass elem3, PTBL_CharClass elem4, PTBL_CharClass elem5);
#define PTBL_makeCharClasses5(elem1, elem2, elem3, elem4,  elem5) (_PTBL_makeCharClasses5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PTBL_makeCharClasses6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PTBL_CharClasses) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PTBL_CharClasses _PTBL_makeCharClasses6(PTBL_CharClass elem1, PTBL_CharClass elem2, PTBL_CharClass elem3, PTBL_CharClass elem4, PTBL_CharClass elem5, PTBL_CharClass elem6);
#define PTBL_makeCharClasses6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PTBL_makeCharClasses6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define PTBL_getPrioritiesLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PTBL_getPrioritiesLength(PTBL_Priorities arg);
#define PTBL_getPrioritiesLength(arg) (_PTBL_getPrioritiesLength(arg))
#endif
#ifdef FAST_API
#define PTBL_reversePriorities(arg) ((PTBL_Priorities) ATreverse((ATermList) (arg)))
#else
PTBL_Priorities _PTBL_reversePriorities(PTBL_Priorities arg);
#define PTBL_reversePriorities(arg) (_PTBL_reversePriorities(arg))
#endif
#ifdef FAST_API
#define PTBL_appendPriorities(arg, elem) ((PTBL_Priorities) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PTBL_Priorities _PTBL_appendPriorities(PTBL_Priorities arg, PTBL_Priority elem);
#define PTBL_appendPriorities(arg, elem) (_PTBL_appendPriorities(arg, elem))
#endif
#ifdef FAST_API
#define PTBL_concatPriorities(arg0, arg1) ((PTBL_Priorities) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PTBL_Priorities _PTBL_concatPriorities(PTBL_Priorities arg0, PTBL_Priorities arg1);
#define PTBL_concatPriorities(arg0, arg1) (_PTBL_concatPriorities(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_slicePriorities(arg, start, end) ((PTBL_Priorities) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PTBL_Priorities _PTBL_slicePriorities(PTBL_Priorities arg, int start, int end);
#define PTBL_slicePriorities(arg, start, end) (_PTBL_slicePriorities(arg, start, end))
#endif
#ifdef FAST_API
#define PTBL_getPrioritiesPriorityAt(arg, index) ((PTBL_Priority) (ATelementAt((ATermList) arg,index)))
#else
PTBL_Priority _PTBL_getPrioritiesPriorityAt(PTBL_Priorities arg, int index);
#define PTBL_getPrioritiesPriorityAt(arg, index) (_PTBL_getPrioritiesPriorityAt(arg, index))
#endif
#ifdef FAST_API
#define PTBL_replacePrioritiesPriorityAt(arg, elem, index) ((PTBL_Priorities) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PTBL_Priorities _PTBL_replacePrioritiesPriorityAt(PTBL_Priorities arg, PTBL_Priority elem, int index);
#define PTBL_replacePrioritiesPriorityAt(arg, elem, index) (_PTBL_replacePrioritiesPriorityAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PTBL_makePriorities2(elem1,  elem2) ((PTBL_Priorities) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PTBL_Priorities _PTBL_makePriorities2(PTBL_Priority elem1, PTBL_Priority elem2);
#define PTBL_makePriorities2(elem1,  elem2) (_PTBL_makePriorities2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PTBL_makePriorities3(elem1, elem2,  elem3) ((PTBL_Priorities) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PTBL_Priorities _PTBL_makePriorities3(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3);
#define PTBL_makePriorities3(elem1, elem2,  elem3) (_PTBL_makePriorities3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PTBL_makePriorities4(elem1, elem2, elem3,  elem4) ((PTBL_Priorities) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PTBL_Priorities _PTBL_makePriorities4(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3, PTBL_Priority elem4);
#define PTBL_makePriorities4(elem1, elem2, elem3,  elem4) (_PTBL_makePriorities4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PTBL_makePriorities5(elem1, elem2, elem3, elem4,  elem5) ((PTBL_Priorities) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PTBL_Priorities _PTBL_makePriorities5(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3, PTBL_Priority elem4, PTBL_Priority elem5);
#define PTBL_makePriorities5(elem1, elem2, elem3, elem4,  elem5) (_PTBL_makePriorities5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PTBL_makePriorities6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PTBL_Priorities) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PTBL_Priorities _PTBL_makePriorities6(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3, PTBL_Priority elem4, PTBL_Priority elem5, PTBL_Priority elem6);
#define PTBL_makePriorities6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PTBL_makePriorities6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
PTBL_Production PTBL_makeProductionExternal(ATerm prod);
PTBL_CharClass PTBL_makeCharClassExternal(ATerm charClass);
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
PTBL_State PTBL_makeStateDefault(int number, PTBL_Gotos gotos, PTBL_Choices choices);
PTBL_Gotos PTBL_makeGotosEmpty(void);
PTBL_Gotos PTBL_makeGotosSingle(PTBL_Goto head);
PTBL_Gotos PTBL_makeGotosMany(PTBL_Goto head, PTBL_Gotos tail);
PTBL_Goto PTBL_makeGotoDefault(PTBL_CharRanges ranges, int stateNumber);
PTBL_Choices PTBL_makeChoicesEmpty(void);
PTBL_Choices PTBL_makeChoicesSingle(PTBL_Choice head);
PTBL_Choices PTBL_makeChoicesMany(PTBL_Choice head, PTBL_Choices tail);
PTBL_Choice PTBL_makeChoiceDefault(PTBL_CharRanges ranges, PTBL_Actions actions);
PTBL_Actions PTBL_makeActionsEmpty(void);
PTBL_Actions PTBL_makeActionsSingle(PTBL_Action head);
PTBL_Actions PTBL_makeActionsMany(PTBL_Action head, PTBL_Actions tail);
PTBL_Action PTBL_makeActionReduce(int length, int label, PTBL_SpecialAttr specialAttr);
PTBL_Action PTBL_makeActionLookaheadReduce(int length, int label, PTBL_SpecialAttr specialAttr, PTBL_Restrictions restrictions);
PTBL_Action PTBL_makeActionShift(int stateNumber);
PTBL_Action PTBL_makeActionAccept(void);
PTBL_SpecialAttr PTBL_makeSpecialAttrNone(void);
PTBL_SpecialAttr PTBL_makeSpecialAttrReject(void);
PTBL_SpecialAttr PTBL_makeSpecialAttrPrefer(void);
PTBL_SpecialAttr PTBL_makeSpecialAttrAvoid(void);
PTBL_Restrictions PTBL_makeRestrictionsEmpty(void);
PTBL_Restrictions PTBL_makeRestrictionsSingle(PTBL_Restriction head);
PTBL_Restrictions PTBL_makeRestrictionsMany(PTBL_Restriction head, PTBL_Restrictions tail);
PTBL_Restriction PTBL_makeRestrictionFollow(PTBL_CharClasses charClasses);
PTBL_CharClasses PTBL_makeCharClassesEmpty(void);
PTBL_CharClasses PTBL_makeCharClassesSingle(PTBL_CharClass head);
PTBL_CharClasses PTBL_makeCharClassesMany(PTBL_CharClass head, PTBL_CharClasses tail);
PTBL_Priorities PTBL_makePrioritiesEmpty(void);
PTBL_Priorities PTBL_makePrioritiesSingle(PTBL_Priority head);
PTBL_Priorities PTBL_makePrioritiesMany(PTBL_Priority head, PTBL_Priorities tail);
PTBL_Priority PTBL_makePriorityGreater(int label1, int label2);
PTBL_Priority PTBL_makePriorityArgGreater(int label1, int argumentNumber, int label2);
#ifdef FAST_API
#define PTBL_isEqualProduction(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualProduction(PTBL_Production arg0, PTBL_Production arg1);
#define PTBL_isEqualProduction(arg0, arg1) (_PTBL_isEqualProduction(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualCharClass(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualCharClass(PTBL_CharClass arg0, PTBL_CharClass arg1);
#define PTBL_isEqualCharClass(arg0, arg1) (_PTBL_isEqualCharClass(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualCharRanges(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualCharRanges(PTBL_CharRanges arg0, PTBL_CharRanges arg1);
#define PTBL_isEqualCharRanges(arg0, arg1) (_PTBL_isEqualCharRanges(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualVersion(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualVersion(PTBL_Version arg0, PTBL_Version arg1);
#define PTBL_isEqualVersion(arg0, arg1) (_PTBL_isEqualVersion(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualParseTable(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualParseTable(PTBL_ParseTable arg0, PTBL_ParseTable arg1);
#define PTBL_isEqualParseTable(arg0, arg1) (_PTBL_isEqualParseTable(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualLabels(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualLabels(PTBL_Labels arg0, PTBL_Labels arg1);
#define PTBL_isEqualLabels(arg0, arg1) (_PTBL_isEqualLabels(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualLabel(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualLabel(PTBL_Label arg0, PTBL_Label arg1);
#define PTBL_isEqualLabel(arg0, arg1) (_PTBL_isEqualLabel(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualStates(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualStates(PTBL_States arg0, PTBL_States arg1);
#define PTBL_isEqualStates(arg0, arg1) (_PTBL_isEqualStates(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualState(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualState(PTBL_State arg0, PTBL_State arg1);
#define PTBL_isEqualState(arg0, arg1) (_PTBL_isEqualState(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualGotos(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualGotos(PTBL_Gotos arg0, PTBL_Gotos arg1);
#define PTBL_isEqualGotos(arg0, arg1) (_PTBL_isEqualGotos(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualGoto(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualGoto(PTBL_Goto arg0, PTBL_Goto arg1);
#define PTBL_isEqualGoto(arg0, arg1) (_PTBL_isEqualGoto(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualChoices(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualChoices(PTBL_Choices arg0, PTBL_Choices arg1);
#define PTBL_isEqualChoices(arg0, arg1) (_PTBL_isEqualChoices(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualChoice(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualChoice(PTBL_Choice arg0, PTBL_Choice arg1);
#define PTBL_isEqualChoice(arg0, arg1) (_PTBL_isEqualChoice(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualActions(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualActions(PTBL_Actions arg0, PTBL_Actions arg1);
#define PTBL_isEqualActions(arg0, arg1) (_PTBL_isEqualActions(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualAction(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualAction(PTBL_Action arg0, PTBL_Action arg1);
#define PTBL_isEqualAction(arg0, arg1) (_PTBL_isEqualAction(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualSpecialAttr(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualSpecialAttr(PTBL_SpecialAttr arg0, PTBL_SpecialAttr arg1);
#define PTBL_isEqualSpecialAttr(arg0, arg1) (_PTBL_isEqualSpecialAttr(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualRestrictions(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualRestrictions(PTBL_Restrictions arg0, PTBL_Restrictions arg1);
#define PTBL_isEqualRestrictions(arg0, arg1) (_PTBL_isEqualRestrictions(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualRestriction(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualRestriction(PTBL_Restriction arg0, PTBL_Restriction arg1);
#define PTBL_isEqualRestriction(arg0, arg1) (_PTBL_isEqualRestriction(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualCharClasses(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualCharClasses(PTBL_CharClasses arg0, PTBL_CharClasses arg1);
#define PTBL_isEqualCharClasses(arg0, arg1) (_PTBL_isEqualCharClasses(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualPriorities(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualPriorities(PTBL_Priorities arg0, PTBL_Priorities arg1);
#define PTBL_isEqualPriorities(arg0, arg1) (_PTBL_isEqualPriorities(arg0, arg1))
#endif
#ifdef FAST_API
#define PTBL_isEqualPriority(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PTBL_isEqualPriority(PTBL_Priority arg0, PTBL_Priority arg1);
#define PTBL_isEqualPriority(arg0, arg1) (_PTBL_isEqualPriority(arg0, arg1))
#endif
ATbool PTBL_isValidProduction(PTBL_Production arg);
inline ATbool PTBL_isProductionExternal(PTBL_Production arg);
ATbool PTBL_hasProductionProd(PTBL_Production arg);
ATerm PTBL_getProductionProd(PTBL_Production arg);
PTBL_Production PTBL_setProductionProd(PTBL_Production arg, ATerm prod);
ATbool PTBL_isValidCharClass(PTBL_CharClass arg);
inline ATbool PTBL_isCharClassExternal(PTBL_CharClass arg);
ATbool PTBL_hasCharClassCharClass(PTBL_CharClass arg);
ATerm PTBL_getCharClassCharClass(PTBL_CharClass arg);
PTBL_CharClass PTBL_setCharClassCharClass(PTBL_CharClass arg, ATerm charClass);
ATbool PTBL_isValidCharRanges(PTBL_CharRanges arg);
inline ATbool PTBL_isCharRangesExternal(PTBL_CharRanges arg);
ATbool PTBL_hasCharRangesRanges(PTBL_CharRanges arg);
ATerm PTBL_getCharRangesRanges(PTBL_CharRanges arg);
PTBL_CharRanges PTBL_setCharRangesRanges(PTBL_CharRanges arg, ATerm ranges);
ATbool PTBL_isValidVersion(PTBL_Version arg);
inline ATbool PTBL_isVersionDefault(PTBL_Version arg);
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
ATbool PTBL_isValidLabel(PTBL_Label arg);
inline ATbool PTBL_isLabelDefault(PTBL_Label arg);
ATbool PTBL_hasLabelProduction(PTBL_Label arg);
ATbool PTBL_hasLabelNumber(PTBL_Label arg);
PTBL_Production PTBL_getLabelProduction(PTBL_Label arg);
int PTBL_getLabelNumber(PTBL_Label arg);
PTBL_Label PTBL_setLabelProduction(PTBL_Label arg, PTBL_Production production);
PTBL_Label PTBL_setLabelNumber(PTBL_Label arg, int number);
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
ATbool PTBL_isValidState(PTBL_State arg);
inline ATbool PTBL_isStateDefault(PTBL_State arg);
ATbool PTBL_hasStateNumber(PTBL_State arg);
ATbool PTBL_hasStateGotos(PTBL_State arg);
ATbool PTBL_hasStateChoices(PTBL_State arg);
int PTBL_getStateNumber(PTBL_State arg);
PTBL_Gotos PTBL_getStateGotos(PTBL_State arg);
PTBL_Choices PTBL_getStateChoices(PTBL_State arg);
PTBL_State PTBL_setStateNumber(PTBL_State arg, int number);
PTBL_State PTBL_setStateGotos(PTBL_State arg, PTBL_Gotos gotos);
PTBL_State PTBL_setStateChoices(PTBL_State arg, PTBL_Choices choices);
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
ATbool PTBL_isValidGoto(PTBL_Goto arg);
inline ATbool PTBL_isGotoDefault(PTBL_Goto arg);
ATbool PTBL_hasGotoRanges(PTBL_Goto arg);
ATbool PTBL_hasGotoStateNumber(PTBL_Goto arg);
PTBL_CharRanges PTBL_getGotoRanges(PTBL_Goto arg);
int PTBL_getGotoStateNumber(PTBL_Goto arg);
PTBL_Goto PTBL_setGotoRanges(PTBL_Goto arg, PTBL_CharRanges ranges);
PTBL_Goto PTBL_setGotoStateNumber(PTBL_Goto arg, int stateNumber);
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
ATbool PTBL_isValidChoice(PTBL_Choice arg);
inline ATbool PTBL_isChoiceDefault(PTBL_Choice arg);
ATbool PTBL_hasChoiceRanges(PTBL_Choice arg);
ATbool PTBL_hasChoiceActions(PTBL_Choice arg);
PTBL_CharRanges PTBL_getChoiceRanges(PTBL_Choice arg);
PTBL_Actions PTBL_getChoiceActions(PTBL_Choice arg);
PTBL_Choice PTBL_setChoiceRanges(PTBL_Choice arg, PTBL_CharRanges ranges);
PTBL_Choice PTBL_setChoiceActions(PTBL_Choice arg, PTBL_Actions actions);
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
ATbool PTBL_isValidAction(PTBL_Action arg);
inline ATbool PTBL_isActionReduce(PTBL_Action arg);
inline ATbool PTBL_isActionLookaheadReduce(PTBL_Action arg);
inline ATbool PTBL_isActionShift(PTBL_Action arg);
inline ATbool PTBL_isActionAccept(PTBL_Action arg);
ATbool PTBL_hasActionLength(PTBL_Action arg);
ATbool PTBL_hasActionLabel(PTBL_Action arg);
ATbool PTBL_hasActionSpecialAttr(PTBL_Action arg);
ATbool PTBL_hasActionRestrictions(PTBL_Action arg);
ATbool PTBL_hasActionStateNumber(PTBL_Action arg);
int PTBL_getActionLength(PTBL_Action arg);
int PTBL_getActionLabel(PTBL_Action arg);
PTBL_SpecialAttr PTBL_getActionSpecialAttr(PTBL_Action arg);
PTBL_Restrictions PTBL_getActionRestrictions(PTBL_Action arg);
int PTBL_getActionStateNumber(PTBL_Action arg);
PTBL_Action PTBL_setActionLength(PTBL_Action arg, int length);
PTBL_Action PTBL_setActionLabel(PTBL_Action arg, int label);
PTBL_Action PTBL_setActionSpecialAttr(PTBL_Action arg, PTBL_SpecialAttr specialAttr);
PTBL_Action PTBL_setActionRestrictions(PTBL_Action arg, PTBL_Restrictions restrictions);
PTBL_Action PTBL_setActionStateNumber(PTBL_Action arg, int stateNumber);
ATbool PTBL_isValidSpecialAttr(PTBL_SpecialAttr arg);
inline ATbool PTBL_isSpecialAttrNone(PTBL_SpecialAttr arg);
inline ATbool PTBL_isSpecialAttrReject(PTBL_SpecialAttr arg);
inline ATbool PTBL_isSpecialAttrPrefer(PTBL_SpecialAttr arg);
inline ATbool PTBL_isSpecialAttrAvoid(PTBL_SpecialAttr arg);
ATbool PTBL_isValidRestrictions(PTBL_Restrictions arg);
inline ATbool PTBL_isRestrictionsEmpty(PTBL_Restrictions arg);
inline ATbool PTBL_isRestrictionsSingle(PTBL_Restrictions arg);
inline ATbool PTBL_isRestrictionsMany(PTBL_Restrictions arg);
ATbool PTBL_hasRestrictionsHead(PTBL_Restrictions arg);
ATbool PTBL_hasRestrictionsTail(PTBL_Restrictions arg);
PTBL_Restriction PTBL_getRestrictionsHead(PTBL_Restrictions arg);
PTBL_Restrictions PTBL_getRestrictionsTail(PTBL_Restrictions arg);
PTBL_Restrictions PTBL_setRestrictionsHead(PTBL_Restrictions arg, PTBL_Restriction head);
PTBL_Restrictions PTBL_setRestrictionsTail(PTBL_Restrictions arg, PTBL_Restrictions tail);
ATbool PTBL_isValidRestriction(PTBL_Restriction arg);
inline ATbool PTBL_isRestrictionFollow(PTBL_Restriction arg);
ATbool PTBL_hasRestrictionCharClasses(PTBL_Restriction arg);
PTBL_CharClasses PTBL_getRestrictionCharClasses(PTBL_Restriction arg);
PTBL_Restriction PTBL_setRestrictionCharClasses(PTBL_Restriction arg, PTBL_CharClasses charClasses);
ATbool PTBL_isValidCharClasses(PTBL_CharClasses arg);
inline ATbool PTBL_isCharClassesEmpty(PTBL_CharClasses arg);
inline ATbool PTBL_isCharClassesSingle(PTBL_CharClasses arg);
inline ATbool PTBL_isCharClassesMany(PTBL_CharClasses arg);
ATbool PTBL_hasCharClassesHead(PTBL_CharClasses arg);
ATbool PTBL_hasCharClassesTail(PTBL_CharClasses arg);
PTBL_CharClass PTBL_getCharClassesHead(PTBL_CharClasses arg);
PTBL_CharClasses PTBL_getCharClassesTail(PTBL_CharClasses arg);
PTBL_CharClasses PTBL_setCharClassesHead(PTBL_CharClasses arg, PTBL_CharClass head);
PTBL_CharClasses PTBL_setCharClassesTail(PTBL_CharClasses arg, PTBL_CharClasses tail);
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
ATbool PTBL_isValidPriority(PTBL_Priority arg);
inline ATbool PTBL_isPriorityGreater(PTBL_Priority arg);
inline ATbool PTBL_isPriorityArgGreater(PTBL_Priority arg);
ATbool PTBL_hasPriorityLabel1(PTBL_Priority arg);
ATbool PTBL_hasPriorityLabel2(PTBL_Priority arg);
ATbool PTBL_hasPriorityArgumentNumber(PTBL_Priority arg);
int PTBL_getPriorityLabel1(PTBL_Priority arg);
int PTBL_getPriorityLabel2(PTBL_Priority arg);
int PTBL_getPriorityArgumentNumber(PTBL_Priority arg);
PTBL_Priority PTBL_setPriorityLabel1(PTBL_Priority arg, int label1);
PTBL_Priority PTBL_setPriorityLabel2(PTBL_Priority arg, int label2);
PTBL_Priority PTBL_setPriorityArgumentNumber(PTBL_Priority arg, int argumentNumber);
PTBL_Production PTBL_visitProduction(PTBL_Production arg, ATerm (*acceptProd)(ATerm));
PTBL_CharClass PTBL_visitCharClass(PTBL_CharClass arg, ATerm (*acceptCharClass)(ATerm));
PTBL_CharRanges PTBL_visitCharRanges(PTBL_CharRanges arg, ATerm (*acceptRanges)(ATerm));
PTBL_Version PTBL_visitVersion(PTBL_Version arg);
PTBL_ParseTable PTBL_visitParseTable(PTBL_ParseTable arg, PTBL_Version (*acceptVersion)(PTBL_Version), int (*acceptInitialState)(int), PTBL_Labels (*acceptLabels)(PTBL_Labels), PTBL_States (*acceptStates)(PTBL_States), PTBL_Priorities (*acceptPriorities)(PTBL_Priorities));
PTBL_Labels PTBL_visitLabels(PTBL_Labels arg, PTBL_Label (*acceptHead)(PTBL_Label));
PTBL_Label PTBL_visitLabel(PTBL_Label arg, PTBL_Production (*acceptProduction)(PTBL_Production), int (*acceptNumber)(int));
PTBL_States PTBL_visitStates(PTBL_States arg, PTBL_State (*acceptHead)(PTBL_State));
PTBL_State PTBL_visitState(PTBL_State arg, int (*acceptNumber)(int), PTBL_Gotos (*acceptGotos)(PTBL_Gotos), PTBL_Choices (*acceptChoices)(PTBL_Choices));
PTBL_Gotos PTBL_visitGotos(PTBL_Gotos arg, PTBL_Goto (*acceptHead)(PTBL_Goto));
PTBL_Goto PTBL_visitGoto(PTBL_Goto arg, PTBL_CharRanges (*acceptRanges)(PTBL_CharRanges), int (*acceptStateNumber)(int));
PTBL_Choices PTBL_visitChoices(PTBL_Choices arg, PTBL_Choice (*acceptHead)(PTBL_Choice));
PTBL_Choice PTBL_visitChoice(PTBL_Choice arg, PTBL_CharRanges (*acceptRanges)(PTBL_CharRanges), PTBL_Actions (*acceptActions)(PTBL_Actions));
PTBL_Actions PTBL_visitActions(PTBL_Actions arg, PTBL_Action (*acceptHead)(PTBL_Action));
PTBL_Action PTBL_visitAction(PTBL_Action arg, int (*acceptLength)(int), int (*acceptLabel)(int), PTBL_SpecialAttr (*acceptSpecialAttr)(PTBL_SpecialAttr), PTBL_Restrictions (*acceptRestrictions)(PTBL_Restrictions), int (*acceptStateNumber)(int));
PTBL_SpecialAttr PTBL_visitSpecialAttr(PTBL_SpecialAttr arg);
PTBL_Restrictions PTBL_visitRestrictions(PTBL_Restrictions arg, PTBL_Restriction (*acceptHead)(PTBL_Restriction));
PTBL_Restriction PTBL_visitRestriction(PTBL_Restriction arg, PTBL_CharClasses (*acceptCharClasses)(PTBL_CharClasses));
PTBL_CharClasses PTBL_visitCharClasses(PTBL_CharClasses arg, PTBL_CharClass (*acceptHead)(PTBL_CharClass));
PTBL_Priorities PTBL_visitPriorities(PTBL_Priorities arg, PTBL_Priority (*acceptHead)(PTBL_Priority));
PTBL_Priority PTBL_visitPriority(PTBL_Priority arg, int (*acceptLabel1)(int), int (*acceptLabel2)(int), int (*acceptArgumentNumber)(int));

#endif /* _PTABLE_H */
