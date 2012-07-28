#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ptable.h"

/**
 * Converts a string to an ATermList of integers (ASCII values). 
 * \param[in] str An ASCII string
 * \return An ATermList containing the ASCII values of #arg as ATermInts
 */
ATerm PTBL_stringToChars(const char *str) {
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

/**
 * Converts an ASCII char to an ATermInt. 
 * \param[in] ch an ASCII character
 * \return An ATerm representing the ASCII value of #arg
 */
ATerm PTBL_byteToChar(char ch) {
    return (ATerm) ATmakeInt(ch);
}

/**
 * Converts a list of integers (ASCII values) to a C string. 
 * \param[in] arg An ATermList with ATermInts, such as [32,32,10]
 * \return String containing the characters from #arg as characters
 */
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
typedef struct ATerm _PTBL_CharClass;
typedef struct ATerm _PTBL_CharRanges;
typedef struct ATerm _PTBL_Version;
typedef struct ATerm _PTBL_ParseTable;
typedef struct ATerm _PTBL_Labels;
typedef struct ATerm _PTBL_Label;
typedef struct ATerm _PTBL_States;
typedef struct ATerm _PTBL_State;
typedef struct ATerm _PTBL_Gotos;
typedef struct ATerm _PTBL_Goto;
typedef struct ATerm _PTBL_Choices;
typedef struct ATerm _PTBL_Choice;
typedef struct ATerm _PTBL_Actions;
typedef struct ATerm _PTBL_Action;
typedef struct ATerm _PTBL_SpecialAttr;
typedef struct ATerm _PTBL_Restrictions;
typedef struct ATerm _PTBL_Restriction;
typedef struct ATerm _PTBL_CharClasses;
typedef struct ATerm _PTBL_Priorities;
typedef struct ATerm _PTBL_Priority;


/**
 * Initializes the full API. Forgetting to call this function before using the API will lead to strange behaviour. ATinit() needs to be called before this function.
 */
void _PTBL_initPtableApi(void) {
  init_ptable_dict();

}

/**
 * Protect a PTBL_Production from the ATerm garbage collector. Every PTBL_Production that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_Production
 */
void _PTBL_protectProduction(PTBL_Production *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_Production from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_Production
 */
void _PTBL_unprotectProduction(PTBL_Production *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_CharClass from the ATerm garbage collector. Every PTBL_CharClass that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_CharClass
 */
void _PTBL_protectCharClass(PTBL_CharClass *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_CharClass from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_CharClass
 */
void _PTBL_unprotectCharClass(PTBL_CharClass *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_CharRanges from the ATerm garbage collector. Every PTBL_CharRanges that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_CharRanges
 */
void _PTBL_protectCharRanges(PTBL_CharRanges *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_CharRanges from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_CharRanges
 */
void _PTBL_unprotectCharRanges(PTBL_CharRanges *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_Version from the ATerm garbage collector. Every PTBL_Version that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_Version
 */
void _PTBL_protectVersion(PTBL_Version *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_Version from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_Version
 */
void _PTBL_unprotectVersion(PTBL_Version *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_ParseTable from the ATerm garbage collector. Every PTBL_ParseTable that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_ParseTable
 */
void _PTBL_protectParseTable(PTBL_ParseTable *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_ParseTable from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_ParseTable
 */
void _PTBL_unprotectParseTable(PTBL_ParseTable *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_Labels from the ATerm garbage collector. Every PTBL_Labels that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_Labels
 */
void _PTBL_protectLabels(PTBL_Labels *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_Labels from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_Labels
 */
void _PTBL_unprotectLabels(PTBL_Labels *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_Label from the ATerm garbage collector. Every PTBL_Label that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_Label
 */
void _PTBL_protectLabel(PTBL_Label *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_Label from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_Label
 */
void _PTBL_unprotectLabel(PTBL_Label *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_States from the ATerm garbage collector. Every PTBL_States that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_States
 */
void _PTBL_protectStates(PTBL_States *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_States from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_States
 */
void _PTBL_unprotectStates(PTBL_States *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_State from the ATerm garbage collector. Every PTBL_State that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_State
 */
void _PTBL_protectState(PTBL_State *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_State from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_State
 */
void _PTBL_unprotectState(PTBL_State *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_Gotos from the ATerm garbage collector. Every PTBL_Gotos that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_Gotos
 */
void _PTBL_protectGotos(PTBL_Gotos *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_Gotos from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_Gotos
 */
void _PTBL_unprotectGotos(PTBL_Gotos *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_Goto from the ATerm garbage collector. Every PTBL_Goto that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_Goto
 */
void _PTBL_protectGoto(PTBL_Goto *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_Goto from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_Goto
 */
void _PTBL_unprotectGoto(PTBL_Goto *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_Choices from the ATerm garbage collector. Every PTBL_Choices that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_Choices
 */
void _PTBL_protectChoices(PTBL_Choices *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_Choices from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_Choices
 */
void _PTBL_unprotectChoices(PTBL_Choices *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_Choice from the ATerm garbage collector. Every PTBL_Choice that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_Choice
 */
void _PTBL_protectChoice(PTBL_Choice *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_Choice from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_Choice
 */
void _PTBL_unprotectChoice(PTBL_Choice *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_Actions from the ATerm garbage collector. Every PTBL_Actions that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_Actions
 */
void _PTBL_protectActions(PTBL_Actions *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_Actions from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_Actions
 */
void _PTBL_unprotectActions(PTBL_Actions *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_Action from the ATerm garbage collector. Every PTBL_Action that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_Action
 */
void _PTBL_protectAction(PTBL_Action *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_Action from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_Action
 */
void _PTBL_unprotectAction(PTBL_Action *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_SpecialAttr from the ATerm garbage collector. Every PTBL_SpecialAttr that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_SpecialAttr
 */
void _PTBL_protectSpecialAttr(PTBL_SpecialAttr *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_SpecialAttr from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_SpecialAttr
 */
void _PTBL_unprotectSpecialAttr(PTBL_SpecialAttr *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_Restrictions from the ATerm garbage collector. Every PTBL_Restrictions that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_Restrictions
 */
void _PTBL_protectRestrictions(PTBL_Restrictions *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_Restrictions from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_Restrictions
 */
void _PTBL_unprotectRestrictions(PTBL_Restrictions *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_Restriction from the ATerm garbage collector. Every PTBL_Restriction that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_Restriction
 */
void _PTBL_protectRestriction(PTBL_Restriction *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_Restriction from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_Restriction
 */
void _PTBL_unprotectRestriction(PTBL_Restriction *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_CharClasses from the ATerm garbage collector. Every PTBL_CharClasses that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_CharClasses
 */
void _PTBL_protectCharClasses(PTBL_CharClasses *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_CharClasses from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_CharClasses
 */
void _PTBL_unprotectCharClasses(PTBL_CharClasses *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_Priorities from the ATerm garbage collector. Every PTBL_Priorities that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_Priorities
 */
void _PTBL_protectPriorities(PTBL_Priorities *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_Priorities from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_Priorities
 */
void _PTBL_unprotectPriorities(PTBL_Priorities *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a PTBL_Priority from the ATerm garbage collector. Every PTBL_Priority that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a PTBL_Priority
 */
void _PTBL_protectPriority(PTBL_Priority *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a PTBL_Priority from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a PTBL_Priority
 */
void _PTBL_unprotectPriority(PTBL_Priority *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Transforms an ATerm to a PTBL_Production. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_Production that was encoded by \arg
 */
PTBL_Production _PTBL_ProductionFromTerm(ATerm t) {
  return (PTBL_Production)t;
}

/**
 * Transforms a PTBL_Productionto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_Production to be converted
 * \return ATerm that represents the PTBL_Production
 */
ATerm _PTBL_ProductionToTerm(PTBL_Production arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_CharClass. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_CharClass that was encoded by \arg
 */
PTBL_CharClass _PTBL_CharClassFromTerm(ATerm t) {
  return (PTBL_CharClass)t;
}

/**
 * Transforms a PTBL_CharClassto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_CharClass to be converted
 * \return ATerm that represents the PTBL_CharClass
 */
ATerm _PTBL_CharClassToTerm(PTBL_CharClass arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_CharRanges. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_CharRanges that was encoded by \arg
 */
PTBL_CharRanges _PTBL_CharRangesFromTerm(ATerm t) {
  return (PTBL_CharRanges)t;
}

/**
 * Transforms a PTBL_CharRangesto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_CharRanges to be converted
 * \return ATerm that represents the PTBL_CharRanges
 */
ATerm _PTBL_CharRangesToTerm(PTBL_CharRanges arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_Version. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_Version that was encoded by \arg
 */
PTBL_Version _PTBL_VersionFromTerm(ATerm t) {
  return (PTBL_Version)t;
}

/**
 * Transforms a PTBL_Versionto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_Version to be converted
 * \return ATerm that represents the PTBL_Version
 */
ATerm _PTBL_VersionToTerm(PTBL_Version arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_ParseTable. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_ParseTable that was encoded by \arg
 */
PTBL_ParseTable _PTBL_ParseTableFromTerm(ATerm t) {
  return (PTBL_ParseTable)t;
}

/**
 * Transforms a PTBL_ParseTableto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_ParseTable to be converted
 * \return ATerm that represents the PTBL_ParseTable
 */
ATerm _PTBL_ParseTableToTerm(PTBL_ParseTable arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_Labels. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_Labels that was encoded by \arg
 */
PTBL_Labels _PTBL_LabelsFromTerm(ATerm t) {
  return (PTBL_Labels)t;
}

/**
 * Transforms a PTBL_Labelsto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_Labels to be converted
 * \return ATerm that represents the PTBL_Labels
 */
ATerm _PTBL_LabelsToTerm(PTBL_Labels arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_Label. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_Label that was encoded by \arg
 */
PTBL_Label _PTBL_LabelFromTerm(ATerm t) {
  return (PTBL_Label)t;
}

/**
 * Transforms a PTBL_Labelto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_Label to be converted
 * \return ATerm that represents the PTBL_Label
 */
ATerm _PTBL_LabelToTerm(PTBL_Label arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_States. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_States that was encoded by \arg
 */
PTBL_States _PTBL_StatesFromTerm(ATerm t) {
  return (PTBL_States)t;
}

/**
 * Transforms a PTBL_Statesto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_States to be converted
 * \return ATerm that represents the PTBL_States
 */
ATerm _PTBL_StatesToTerm(PTBL_States arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_State. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_State that was encoded by \arg
 */
PTBL_State _PTBL_StateFromTerm(ATerm t) {
  return (PTBL_State)t;
}

/**
 * Transforms a PTBL_Stateto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_State to be converted
 * \return ATerm that represents the PTBL_State
 */
ATerm _PTBL_StateToTerm(PTBL_State arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_Gotos. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_Gotos that was encoded by \arg
 */
PTBL_Gotos _PTBL_GotosFromTerm(ATerm t) {
  return (PTBL_Gotos)t;
}

/**
 * Transforms a PTBL_Gotosto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_Gotos to be converted
 * \return ATerm that represents the PTBL_Gotos
 */
ATerm _PTBL_GotosToTerm(PTBL_Gotos arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_Goto. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_Goto that was encoded by \arg
 */
PTBL_Goto _PTBL_GotoFromTerm(ATerm t) {
  return (PTBL_Goto)t;
}

/**
 * Transforms a PTBL_Gototo an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_Goto to be converted
 * \return ATerm that represents the PTBL_Goto
 */
ATerm _PTBL_GotoToTerm(PTBL_Goto arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_Choices. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_Choices that was encoded by \arg
 */
PTBL_Choices _PTBL_ChoicesFromTerm(ATerm t) {
  return (PTBL_Choices)t;
}

/**
 * Transforms a PTBL_Choicesto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_Choices to be converted
 * \return ATerm that represents the PTBL_Choices
 */
ATerm _PTBL_ChoicesToTerm(PTBL_Choices arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_Choice. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_Choice that was encoded by \arg
 */
PTBL_Choice _PTBL_ChoiceFromTerm(ATerm t) {
  return (PTBL_Choice)t;
}

/**
 * Transforms a PTBL_Choiceto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_Choice to be converted
 * \return ATerm that represents the PTBL_Choice
 */
ATerm _PTBL_ChoiceToTerm(PTBL_Choice arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_Actions. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_Actions that was encoded by \arg
 */
PTBL_Actions _PTBL_ActionsFromTerm(ATerm t) {
  return (PTBL_Actions)t;
}

/**
 * Transforms a PTBL_Actionsto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_Actions to be converted
 * \return ATerm that represents the PTBL_Actions
 */
ATerm _PTBL_ActionsToTerm(PTBL_Actions arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_Action. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_Action that was encoded by \arg
 */
PTBL_Action _PTBL_ActionFromTerm(ATerm t) {
  return (PTBL_Action)t;
}

/**
 * Transforms a PTBL_Actionto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_Action to be converted
 * \return ATerm that represents the PTBL_Action
 */
ATerm _PTBL_ActionToTerm(PTBL_Action arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_SpecialAttr. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_SpecialAttr that was encoded by \arg
 */
PTBL_SpecialAttr _PTBL_SpecialAttrFromTerm(ATerm t) {
  return (PTBL_SpecialAttr)t;
}

/**
 * Transforms a PTBL_SpecialAttrto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_SpecialAttr to be converted
 * \return ATerm that represents the PTBL_SpecialAttr
 */
ATerm _PTBL_SpecialAttrToTerm(PTBL_SpecialAttr arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_Restrictions. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_Restrictions that was encoded by \arg
 */
PTBL_Restrictions _PTBL_RestrictionsFromTerm(ATerm t) {
  return (PTBL_Restrictions)t;
}

/**
 * Transforms a PTBL_Restrictionsto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_Restrictions to be converted
 * \return ATerm that represents the PTBL_Restrictions
 */
ATerm _PTBL_RestrictionsToTerm(PTBL_Restrictions arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_Restriction. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_Restriction that was encoded by \arg
 */
PTBL_Restriction _PTBL_RestrictionFromTerm(ATerm t) {
  return (PTBL_Restriction)t;
}

/**
 * Transforms a PTBL_Restrictionto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_Restriction to be converted
 * \return ATerm that represents the PTBL_Restriction
 */
ATerm _PTBL_RestrictionToTerm(PTBL_Restriction arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_CharClasses. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_CharClasses that was encoded by \arg
 */
PTBL_CharClasses _PTBL_CharClassesFromTerm(ATerm t) {
  return (PTBL_CharClasses)t;
}

/**
 * Transforms a PTBL_CharClassesto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_CharClasses to be converted
 * \return ATerm that represents the PTBL_CharClasses
 */
ATerm _PTBL_CharClassesToTerm(PTBL_CharClasses arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_Priorities. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_Priorities that was encoded by \arg
 */
PTBL_Priorities _PTBL_PrioritiesFromTerm(ATerm t) {
  return (PTBL_Priorities)t;
}

/**
 * Transforms a PTBL_Prioritiesto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_Priorities to be converted
 * \return ATerm that represents the PTBL_Priorities
 */
ATerm _PTBL_PrioritiesToTerm(PTBL_Priorities arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a PTBL_Priority. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return PTBL_Priority that was encoded by \arg
 */
PTBL_Priority _PTBL_PriorityFromTerm(ATerm t) {
  return (PTBL_Priority)t;
}

/**
 * Transforms a PTBL_Priorityto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg PTBL_Priority to be converted
 * \return ATerm that represents the PTBL_Priority
 */
ATerm _PTBL_PriorityToTerm(PTBL_Priority arg) {
  return (ATerm)arg;
}

/**
 * Retrieve the length of a PTBL_Labels. 
 * \param[in] arg input PTBL_Labels
 * \return The number of elements in the PTBL_Labels
 */
int _PTBL_getLabelsLength(PTBL_Labels arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a PTBL_Labels. 
 * \param[in] arg PTBL_Labels to be reversed
 * \return a reversed #arg
 */
PTBL_Labels _PTBL_reverseLabels(PTBL_Labels arg) {
  return (PTBL_Labels) ATreverse((ATermList) arg);
}

/**
 * Append a PTBL_Label to the end of a PTBL_Labels. 
 * \param[in] arg PTBL_Labels to append the PTBL_Label to
 * \param[in] elem PTBL_Label to be appended
 * \return new PTBL_Labels with #elem appended
 */
PTBL_Labels _PTBL_appendLabels(PTBL_Labels arg, PTBL_Label elem) {
  return (PTBL_Labels) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two PTBL_Labelss. 
 * \param[in] arg0 first PTBL_Labels
 * \param[in] arg1 second PTBL_Labels
 * \return PTBL_Labels with the elements of #arg0 before the elements of #arg1
 */
PTBL_Labels _PTBL_concatLabels(PTBL_Labels arg0, PTBL_Labels arg1) {
  return (PTBL_Labels) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a PTBL_Labels. 
 * \param[in] arg PTBL_Labels to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new PTBL_Labels with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
PTBL_Labels _PTBL_sliceLabels(PTBL_Labels arg, int start, int end) {
  return (PTBL_Labels) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the PTBL_Label at #index from a PTBL_Labels. 
 * \param[in] arg PTBL_Labels to retrieve the PTBL_Label from
 * \param[in] index index to use to point in the PTBL_Labels
 * \return PTBL_Label at position #index in #arg
 */
PTBL_Label _PTBL_getLabelsLabelAt(PTBL_Labels arg, int index) {
 return (PTBL_Label)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the PTBL_Label at #index from a PTBL_Labels by a new one. 
 * \param[in] arg PTBL_Labels to retrieve the PTBL_Label from
 * \param[in] elem new PTBL_Label to replace another
 * \param[in] index index to use to point in the PTBL_Labels
 * \return A new PTBL_Labelswith #elem replaced in #arg at position #index
 */
PTBL_Labels _PTBL_replaceLabelsLabelAt(PTBL_Labels arg, PTBL_Label elem, int index) {
 return (PTBL_Labels) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a PTBL_Labels of 2 consecutive elements. 
 * \param[in] elem1 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem2 One PTBL_Label element of the new PTBL_Labels
 * \return A new PTBL_Labels consisting of 2 PTBL_Labels
 */
PTBL_Labels _PTBL_makeLabels2(PTBL_Label elem1, PTBL_Label elem2) {
  return (PTBL_Labels) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a PTBL_Labels of 3 consecutive elements. 
 * \param[in] elem1 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem2 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem3 One PTBL_Label element of the new PTBL_Labels
 * \return A new PTBL_Labels consisting of 3 PTBL_Labels
 */
PTBL_Labels _PTBL_makeLabels3(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3) {
  return (PTBL_Labels) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a PTBL_Labels of 4 consecutive elements. 
 * \param[in] elem1 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem2 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem3 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem4 One PTBL_Label element of the new PTBL_Labels
 * \return A new PTBL_Labels consisting of 4 PTBL_Labels
 */
PTBL_Labels _PTBL_makeLabels4(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3, PTBL_Label elem4) {
  return (PTBL_Labels) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a PTBL_Labels of 5 consecutive elements. 
 * \param[in] elem1 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem2 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem3 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem4 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem5 One PTBL_Label element of the new PTBL_Labels
 * \return A new PTBL_Labels consisting of 5 PTBL_Labels
 */
PTBL_Labels _PTBL_makeLabels5(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3, PTBL_Label elem4, PTBL_Label elem5) {
  return (PTBL_Labels) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a PTBL_Labels of 6 consecutive elements. 
 * \param[in] elem1 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem2 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem3 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem4 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem5 One PTBL_Label element of the new PTBL_Labels
 * \param[in] elem6 One PTBL_Label element of the new PTBL_Labels
 * \return A new PTBL_Labels consisting of 6 PTBL_Labels
 */
PTBL_Labels _PTBL_makeLabels6(PTBL_Label elem1, PTBL_Label elem2, PTBL_Label elem3, PTBL_Label elem4, PTBL_Label elem5, PTBL_Label elem6) {
  return (PTBL_Labels) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a PTBL_States. 
 * \param[in] arg input PTBL_States
 * \return The number of elements in the PTBL_States
 */
int _PTBL_getStatesLength(PTBL_States arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a PTBL_States. 
 * \param[in] arg PTBL_States to be reversed
 * \return a reversed #arg
 */
PTBL_States _PTBL_reverseStates(PTBL_States arg) {
  return (PTBL_States) ATreverse((ATermList) arg);
}

/**
 * Append a PTBL_State to the end of a PTBL_States. 
 * \param[in] arg PTBL_States to append the PTBL_State to
 * \param[in] elem PTBL_State to be appended
 * \return new PTBL_States with #elem appended
 */
PTBL_States _PTBL_appendStates(PTBL_States arg, PTBL_State elem) {
  return (PTBL_States) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two PTBL_Statess. 
 * \param[in] arg0 first PTBL_States
 * \param[in] arg1 second PTBL_States
 * \return PTBL_States with the elements of #arg0 before the elements of #arg1
 */
PTBL_States _PTBL_concatStates(PTBL_States arg0, PTBL_States arg1) {
  return (PTBL_States) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a PTBL_States. 
 * \param[in] arg PTBL_States to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new PTBL_States with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
PTBL_States _PTBL_sliceStates(PTBL_States arg, int start, int end) {
  return (PTBL_States) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the PTBL_State at #index from a PTBL_States. 
 * \param[in] arg PTBL_States to retrieve the PTBL_State from
 * \param[in] index index to use to point in the PTBL_States
 * \return PTBL_State at position #index in #arg
 */
PTBL_State _PTBL_getStatesStateAt(PTBL_States arg, int index) {
 return (PTBL_State)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the PTBL_State at #index from a PTBL_States by a new one. 
 * \param[in] arg PTBL_States to retrieve the PTBL_State from
 * \param[in] elem new PTBL_State to replace another
 * \param[in] index index to use to point in the PTBL_States
 * \return A new PTBL_Stateswith #elem replaced in #arg at position #index
 */
PTBL_States _PTBL_replaceStatesStateAt(PTBL_States arg, PTBL_State elem, int index) {
 return (PTBL_States) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a PTBL_States of 2 consecutive elements. 
 * \param[in] elem1 One PTBL_State element of the new PTBL_States
 * \param[in] elem2 One PTBL_State element of the new PTBL_States
 * \return A new PTBL_States consisting of 2 PTBL_States
 */
PTBL_States _PTBL_makeStates2(PTBL_State elem1, PTBL_State elem2) {
  return (PTBL_States) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a PTBL_States of 3 consecutive elements. 
 * \param[in] elem1 One PTBL_State element of the new PTBL_States
 * \param[in] elem2 One PTBL_State element of the new PTBL_States
 * \param[in] elem3 One PTBL_State element of the new PTBL_States
 * \return A new PTBL_States consisting of 3 PTBL_States
 */
PTBL_States _PTBL_makeStates3(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3) {
  return (PTBL_States) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a PTBL_States of 4 consecutive elements. 
 * \param[in] elem1 One PTBL_State element of the new PTBL_States
 * \param[in] elem2 One PTBL_State element of the new PTBL_States
 * \param[in] elem3 One PTBL_State element of the new PTBL_States
 * \param[in] elem4 One PTBL_State element of the new PTBL_States
 * \return A new PTBL_States consisting of 4 PTBL_States
 */
PTBL_States _PTBL_makeStates4(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3, PTBL_State elem4) {
  return (PTBL_States) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a PTBL_States of 5 consecutive elements. 
 * \param[in] elem1 One PTBL_State element of the new PTBL_States
 * \param[in] elem2 One PTBL_State element of the new PTBL_States
 * \param[in] elem3 One PTBL_State element of the new PTBL_States
 * \param[in] elem4 One PTBL_State element of the new PTBL_States
 * \param[in] elem5 One PTBL_State element of the new PTBL_States
 * \return A new PTBL_States consisting of 5 PTBL_States
 */
PTBL_States _PTBL_makeStates5(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3, PTBL_State elem4, PTBL_State elem5) {
  return (PTBL_States) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a PTBL_States of 6 consecutive elements. 
 * \param[in] elem1 One PTBL_State element of the new PTBL_States
 * \param[in] elem2 One PTBL_State element of the new PTBL_States
 * \param[in] elem3 One PTBL_State element of the new PTBL_States
 * \param[in] elem4 One PTBL_State element of the new PTBL_States
 * \param[in] elem5 One PTBL_State element of the new PTBL_States
 * \param[in] elem6 One PTBL_State element of the new PTBL_States
 * \return A new PTBL_States consisting of 6 PTBL_States
 */
PTBL_States _PTBL_makeStates6(PTBL_State elem1, PTBL_State elem2, PTBL_State elem3, PTBL_State elem4, PTBL_State elem5, PTBL_State elem6) {
  return (PTBL_States) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a PTBL_Gotos. 
 * \param[in] arg input PTBL_Gotos
 * \return The number of elements in the PTBL_Gotos
 */
int _PTBL_getGotosLength(PTBL_Gotos arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a PTBL_Gotos. 
 * \param[in] arg PTBL_Gotos to be reversed
 * \return a reversed #arg
 */
PTBL_Gotos _PTBL_reverseGotos(PTBL_Gotos arg) {
  return (PTBL_Gotos) ATreverse((ATermList) arg);
}

/**
 * Append a PTBL_Goto to the end of a PTBL_Gotos. 
 * \param[in] arg PTBL_Gotos to append the PTBL_Goto to
 * \param[in] elem PTBL_Goto to be appended
 * \return new PTBL_Gotos with #elem appended
 */
PTBL_Gotos _PTBL_appendGotos(PTBL_Gotos arg, PTBL_Goto elem) {
  return (PTBL_Gotos) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two PTBL_Gotoss. 
 * \param[in] arg0 first PTBL_Gotos
 * \param[in] arg1 second PTBL_Gotos
 * \return PTBL_Gotos with the elements of #arg0 before the elements of #arg1
 */
PTBL_Gotos _PTBL_concatGotos(PTBL_Gotos arg0, PTBL_Gotos arg1) {
  return (PTBL_Gotos) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a PTBL_Gotos. 
 * \param[in] arg PTBL_Gotos to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new PTBL_Gotos with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
PTBL_Gotos _PTBL_sliceGotos(PTBL_Gotos arg, int start, int end) {
  return (PTBL_Gotos) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the PTBL_Goto at #index from a PTBL_Gotos. 
 * \param[in] arg PTBL_Gotos to retrieve the PTBL_Goto from
 * \param[in] index index to use to point in the PTBL_Gotos
 * \return PTBL_Goto at position #index in #arg
 */
PTBL_Goto _PTBL_getGotosGotoAt(PTBL_Gotos arg, int index) {
 return (PTBL_Goto)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the PTBL_Goto at #index from a PTBL_Gotos by a new one. 
 * \param[in] arg PTBL_Gotos to retrieve the PTBL_Goto from
 * \param[in] elem new PTBL_Goto to replace another
 * \param[in] index index to use to point in the PTBL_Gotos
 * \return A new PTBL_Gotoswith #elem replaced in #arg at position #index
 */
PTBL_Gotos _PTBL_replaceGotosGotoAt(PTBL_Gotos arg, PTBL_Goto elem, int index) {
 return (PTBL_Gotos) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a PTBL_Gotos of 2 consecutive elements. 
 * \param[in] elem1 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem2 One PTBL_Goto element of the new PTBL_Gotos
 * \return A new PTBL_Gotos consisting of 2 PTBL_Gotos
 */
PTBL_Gotos _PTBL_makeGotos2(PTBL_Goto elem1, PTBL_Goto elem2) {
  return (PTBL_Gotos) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a PTBL_Gotos of 3 consecutive elements. 
 * \param[in] elem1 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem2 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem3 One PTBL_Goto element of the new PTBL_Gotos
 * \return A new PTBL_Gotos consisting of 3 PTBL_Gotos
 */
PTBL_Gotos _PTBL_makeGotos3(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3) {
  return (PTBL_Gotos) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a PTBL_Gotos of 4 consecutive elements. 
 * \param[in] elem1 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem2 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem3 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem4 One PTBL_Goto element of the new PTBL_Gotos
 * \return A new PTBL_Gotos consisting of 4 PTBL_Gotos
 */
PTBL_Gotos _PTBL_makeGotos4(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3, PTBL_Goto elem4) {
  return (PTBL_Gotos) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a PTBL_Gotos of 5 consecutive elements. 
 * \param[in] elem1 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem2 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem3 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem4 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem5 One PTBL_Goto element of the new PTBL_Gotos
 * \return A new PTBL_Gotos consisting of 5 PTBL_Gotos
 */
PTBL_Gotos _PTBL_makeGotos5(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3, PTBL_Goto elem4, PTBL_Goto elem5) {
  return (PTBL_Gotos) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a PTBL_Gotos of 6 consecutive elements. 
 * \param[in] elem1 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem2 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem3 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem4 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem5 One PTBL_Goto element of the new PTBL_Gotos
 * \param[in] elem6 One PTBL_Goto element of the new PTBL_Gotos
 * \return A new PTBL_Gotos consisting of 6 PTBL_Gotos
 */
PTBL_Gotos _PTBL_makeGotos6(PTBL_Goto elem1, PTBL_Goto elem2, PTBL_Goto elem3, PTBL_Goto elem4, PTBL_Goto elem5, PTBL_Goto elem6) {
  return (PTBL_Gotos) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a PTBL_Choices. 
 * \param[in] arg input PTBL_Choices
 * \return The number of elements in the PTBL_Choices
 */
int _PTBL_getChoicesLength(PTBL_Choices arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a PTBL_Choices. 
 * \param[in] arg PTBL_Choices to be reversed
 * \return a reversed #arg
 */
PTBL_Choices _PTBL_reverseChoices(PTBL_Choices arg) {
  return (PTBL_Choices) ATreverse((ATermList) arg);
}

/**
 * Append a PTBL_Choice to the end of a PTBL_Choices. 
 * \param[in] arg PTBL_Choices to append the PTBL_Choice to
 * \param[in] elem PTBL_Choice to be appended
 * \return new PTBL_Choices with #elem appended
 */
PTBL_Choices _PTBL_appendChoices(PTBL_Choices arg, PTBL_Choice elem) {
  return (PTBL_Choices) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two PTBL_Choicess. 
 * \param[in] arg0 first PTBL_Choices
 * \param[in] arg1 second PTBL_Choices
 * \return PTBL_Choices with the elements of #arg0 before the elements of #arg1
 */
PTBL_Choices _PTBL_concatChoices(PTBL_Choices arg0, PTBL_Choices arg1) {
  return (PTBL_Choices) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a PTBL_Choices. 
 * \param[in] arg PTBL_Choices to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new PTBL_Choices with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
PTBL_Choices _PTBL_sliceChoices(PTBL_Choices arg, int start, int end) {
  return (PTBL_Choices) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the PTBL_Choice at #index from a PTBL_Choices. 
 * \param[in] arg PTBL_Choices to retrieve the PTBL_Choice from
 * \param[in] index index to use to point in the PTBL_Choices
 * \return PTBL_Choice at position #index in #arg
 */
PTBL_Choice _PTBL_getChoicesChoiceAt(PTBL_Choices arg, int index) {
 return (PTBL_Choice)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the PTBL_Choice at #index from a PTBL_Choices by a new one. 
 * \param[in] arg PTBL_Choices to retrieve the PTBL_Choice from
 * \param[in] elem new PTBL_Choice to replace another
 * \param[in] index index to use to point in the PTBL_Choices
 * \return A new PTBL_Choiceswith #elem replaced in #arg at position #index
 */
PTBL_Choices _PTBL_replaceChoicesChoiceAt(PTBL_Choices arg, PTBL_Choice elem, int index) {
 return (PTBL_Choices) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a PTBL_Choices of 2 consecutive elements. 
 * \param[in] elem1 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem2 One PTBL_Choice element of the new PTBL_Choices
 * \return A new PTBL_Choices consisting of 2 PTBL_Choices
 */
PTBL_Choices _PTBL_makeChoices2(PTBL_Choice elem1, PTBL_Choice elem2) {
  return (PTBL_Choices) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a PTBL_Choices of 3 consecutive elements. 
 * \param[in] elem1 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem2 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem3 One PTBL_Choice element of the new PTBL_Choices
 * \return A new PTBL_Choices consisting of 3 PTBL_Choices
 */
PTBL_Choices _PTBL_makeChoices3(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3) {
  return (PTBL_Choices) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a PTBL_Choices of 4 consecutive elements. 
 * \param[in] elem1 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem2 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem3 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem4 One PTBL_Choice element of the new PTBL_Choices
 * \return A new PTBL_Choices consisting of 4 PTBL_Choices
 */
PTBL_Choices _PTBL_makeChoices4(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3, PTBL_Choice elem4) {
  return (PTBL_Choices) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a PTBL_Choices of 5 consecutive elements. 
 * \param[in] elem1 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem2 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem3 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem4 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem5 One PTBL_Choice element of the new PTBL_Choices
 * \return A new PTBL_Choices consisting of 5 PTBL_Choices
 */
PTBL_Choices _PTBL_makeChoices5(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3, PTBL_Choice elem4, PTBL_Choice elem5) {
  return (PTBL_Choices) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a PTBL_Choices of 6 consecutive elements. 
 * \param[in] elem1 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem2 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem3 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem4 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem5 One PTBL_Choice element of the new PTBL_Choices
 * \param[in] elem6 One PTBL_Choice element of the new PTBL_Choices
 * \return A new PTBL_Choices consisting of 6 PTBL_Choices
 */
PTBL_Choices _PTBL_makeChoices6(PTBL_Choice elem1, PTBL_Choice elem2, PTBL_Choice elem3, PTBL_Choice elem4, PTBL_Choice elem5, PTBL_Choice elem6) {
  return (PTBL_Choices) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a PTBL_Actions. 
 * \param[in] arg input PTBL_Actions
 * \return The number of elements in the PTBL_Actions
 */
int _PTBL_getActionsLength(PTBL_Actions arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a PTBL_Actions. 
 * \param[in] arg PTBL_Actions to be reversed
 * \return a reversed #arg
 */
PTBL_Actions _PTBL_reverseActions(PTBL_Actions arg) {
  return (PTBL_Actions) ATreverse((ATermList) arg);
}

/**
 * Append a PTBL_Action to the end of a PTBL_Actions. 
 * \param[in] arg PTBL_Actions to append the PTBL_Action to
 * \param[in] elem PTBL_Action to be appended
 * \return new PTBL_Actions with #elem appended
 */
PTBL_Actions _PTBL_appendActions(PTBL_Actions arg, PTBL_Action elem) {
  return (PTBL_Actions) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two PTBL_Actionss. 
 * \param[in] arg0 first PTBL_Actions
 * \param[in] arg1 second PTBL_Actions
 * \return PTBL_Actions with the elements of #arg0 before the elements of #arg1
 */
PTBL_Actions _PTBL_concatActions(PTBL_Actions arg0, PTBL_Actions arg1) {
  return (PTBL_Actions) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a PTBL_Actions. 
 * \param[in] arg PTBL_Actions to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new PTBL_Actions with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
PTBL_Actions _PTBL_sliceActions(PTBL_Actions arg, int start, int end) {
  return (PTBL_Actions) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the PTBL_Action at #index from a PTBL_Actions. 
 * \param[in] arg PTBL_Actions to retrieve the PTBL_Action from
 * \param[in] index index to use to point in the PTBL_Actions
 * \return PTBL_Action at position #index in #arg
 */
PTBL_Action _PTBL_getActionsActionAt(PTBL_Actions arg, int index) {
 return (PTBL_Action)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the PTBL_Action at #index from a PTBL_Actions by a new one. 
 * \param[in] arg PTBL_Actions to retrieve the PTBL_Action from
 * \param[in] elem new PTBL_Action to replace another
 * \param[in] index index to use to point in the PTBL_Actions
 * \return A new PTBL_Actionswith #elem replaced in #arg at position #index
 */
PTBL_Actions _PTBL_replaceActionsActionAt(PTBL_Actions arg, PTBL_Action elem, int index) {
 return (PTBL_Actions) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a PTBL_Actions of 2 consecutive elements. 
 * \param[in] elem1 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem2 One PTBL_Action element of the new PTBL_Actions
 * \return A new PTBL_Actions consisting of 2 PTBL_Actions
 */
PTBL_Actions _PTBL_makeActions2(PTBL_Action elem1, PTBL_Action elem2) {
  return (PTBL_Actions) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a PTBL_Actions of 3 consecutive elements. 
 * \param[in] elem1 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem2 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem3 One PTBL_Action element of the new PTBL_Actions
 * \return A new PTBL_Actions consisting of 3 PTBL_Actions
 */
PTBL_Actions _PTBL_makeActions3(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3) {
  return (PTBL_Actions) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a PTBL_Actions of 4 consecutive elements. 
 * \param[in] elem1 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem2 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem3 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem4 One PTBL_Action element of the new PTBL_Actions
 * \return A new PTBL_Actions consisting of 4 PTBL_Actions
 */
PTBL_Actions _PTBL_makeActions4(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3, PTBL_Action elem4) {
  return (PTBL_Actions) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a PTBL_Actions of 5 consecutive elements. 
 * \param[in] elem1 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem2 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem3 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem4 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem5 One PTBL_Action element of the new PTBL_Actions
 * \return A new PTBL_Actions consisting of 5 PTBL_Actions
 */
PTBL_Actions _PTBL_makeActions5(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3, PTBL_Action elem4, PTBL_Action elem5) {
  return (PTBL_Actions) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a PTBL_Actions of 6 consecutive elements. 
 * \param[in] elem1 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem2 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem3 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem4 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem5 One PTBL_Action element of the new PTBL_Actions
 * \param[in] elem6 One PTBL_Action element of the new PTBL_Actions
 * \return A new PTBL_Actions consisting of 6 PTBL_Actions
 */
PTBL_Actions _PTBL_makeActions6(PTBL_Action elem1, PTBL_Action elem2, PTBL_Action elem3, PTBL_Action elem4, PTBL_Action elem5, PTBL_Action elem6) {
  return (PTBL_Actions) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a PTBL_Restrictions. 
 * \param[in] arg input PTBL_Restrictions
 * \return The number of elements in the PTBL_Restrictions
 */
int _PTBL_getRestrictionsLength(PTBL_Restrictions arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a PTBL_Restrictions. 
 * \param[in] arg PTBL_Restrictions to be reversed
 * \return a reversed #arg
 */
PTBL_Restrictions _PTBL_reverseRestrictions(PTBL_Restrictions arg) {
  return (PTBL_Restrictions) ATreverse((ATermList) arg);
}

/**
 * Append a PTBL_Restriction to the end of a PTBL_Restrictions. 
 * \param[in] arg PTBL_Restrictions to append the PTBL_Restriction to
 * \param[in] elem PTBL_Restriction to be appended
 * \return new PTBL_Restrictions with #elem appended
 */
PTBL_Restrictions _PTBL_appendRestrictions(PTBL_Restrictions arg, PTBL_Restriction elem) {
  return (PTBL_Restrictions) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two PTBL_Restrictionss. 
 * \param[in] arg0 first PTBL_Restrictions
 * \param[in] arg1 second PTBL_Restrictions
 * \return PTBL_Restrictions with the elements of #arg0 before the elements of #arg1
 */
PTBL_Restrictions _PTBL_concatRestrictions(PTBL_Restrictions arg0, PTBL_Restrictions arg1) {
  return (PTBL_Restrictions) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a PTBL_Restrictions. 
 * \param[in] arg PTBL_Restrictions to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new PTBL_Restrictions with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
PTBL_Restrictions _PTBL_sliceRestrictions(PTBL_Restrictions arg, int start, int end) {
  return (PTBL_Restrictions) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the PTBL_Restriction at #index from a PTBL_Restrictions. 
 * \param[in] arg PTBL_Restrictions to retrieve the PTBL_Restriction from
 * \param[in] index index to use to point in the PTBL_Restrictions
 * \return PTBL_Restriction at position #index in #arg
 */
PTBL_Restriction _PTBL_getRestrictionsRestrictionAt(PTBL_Restrictions arg, int index) {
 return (PTBL_Restriction)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the PTBL_Restriction at #index from a PTBL_Restrictions by a new one. 
 * \param[in] arg PTBL_Restrictions to retrieve the PTBL_Restriction from
 * \param[in] elem new PTBL_Restriction to replace another
 * \param[in] index index to use to point in the PTBL_Restrictions
 * \return A new PTBL_Restrictionswith #elem replaced in #arg at position #index
 */
PTBL_Restrictions _PTBL_replaceRestrictionsRestrictionAt(PTBL_Restrictions arg, PTBL_Restriction elem, int index) {
 return (PTBL_Restrictions) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a PTBL_Restrictions of 2 consecutive elements. 
 * \param[in] elem1 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem2 One PTBL_Restriction element of the new PTBL_Restrictions
 * \return A new PTBL_Restrictions consisting of 2 PTBL_Restrictions
 */
PTBL_Restrictions _PTBL_makeRestrictions2(PTBL_Restriction elem1, PTBL_Restriction elem2) {
  return (PTBL_Restrictions) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a PTBL_Restrictions of 3 consecutive elements. 
 * \param[in] elem1 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem2 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem3 One PTBL_Restriction element of the new PTBL_Restrictions
 * \return A new PTBL_Restrictions consisting of 3 PTBL_Restrictions
 */
PTBL_Restrictions _PTBL_makeRestrictions3(PTBL_Restriction elem1, PTBL_Restriction elem2, PTBL_Restriction elem3) {
  return (PTBL_Restrictions) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a PTBL_Restrictions of 4 consecutive elements. 
 * \param[in] elem1 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem2 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem3 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem4 One PTBL_Restriction element of the new PTBL_Restrictions
 * \return A new PTBL_Restrictions consisting of 4 PTBL_Restrictions
 */
PTBL_Restrictions _PTBL_makeRestrictions4(PTBL_Restriction elem1, PTBL_Restriction elem2, PTBL_Restriction elem3, PTBL_Restriction elem4) {
  return (PTBL_Restrictions) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a PTBL_Restrictions of 5 consecutive elements. 
 * \param[in] elem1 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem2 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem3 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem4 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem5 One PTBL_Restriction element of the new PTBL_Restrictions
 * \return A new PTBL_Restrictions consisting of 5 PTBL_Restrictions
 */
PTBL_Restrictions _PTBL_makeRestrictions5(PTBL_Restriction elem1, PTBL_Restriction elem2, PTBL_Restriction elem3, PTBL_Restriction elem4, PTBL_Restriction elem5) {
  return (PTBL_Restrictions) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a PTBL_Restrictions of 6 consecutive elements. 
 * \param[in] elem1 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem2 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem3 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem4 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem5 One PTBL_Restriction element of the new PTBL_Restrictions
 * \param[in] elem6 One PTBL_Restriction element of the new PTBL_Restrictions
 * \return A new PTBL_Restrictions consisting of 6 PTBL_Restrictions
 */
PTBL_Restrictions _PTBL_makeRestrictions6(PTBL_Restriction elem1, PTBL_Restriction elem2, PTBL_Restriction elem3, PTBL_Restriction elem4, PTBL_Restriction elem5, PTBL_Restriction elem6) {
  return (PTBL_Restrictions) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a PTBL_CharClasses. 
 * \param[in] arg input PTBL_CharClasses
 * \return The number of elements in the PTBL_CharClasses
 */
int _PTBL_getCharClassesLength(PTBL_CharClasses arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a PTBL_CharClasses. 
 * \param[in] arg PTBL_CharClasses to be reversed
 * \return a reversed #arg
 */
PTBL_CharClasses _PTBL_reverseCharClasses(PTBL_CharClasses arg) {
  return (PTBL_CharClasses) ATreverse((ATermList) arg);
}

/**
 * Append a PTBL_CharClass to the end of a PTBL_CharClasses. 
 * \param[in] arg PTBL_CharClasses to append the PTBL_CharClass to
 * \param[in] elem PTBL_CharClass to be appended
 * \return new PTBL_CharClasses with #elem appended
 */
PTBL_CharClasses _PTBL_appendCharClasses(PTBL_CharClasses arg, PTBL_CharClass elem) {
  return (PTBL_CharClasses) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two PTBL_CharClassess. 
 * \param[in] arg0 first PTBL_CharClasses
 * \param[in] arg1 second PTBL_CharClasses
 * \return PTBL_CharClasses with the elements of #arg0 before the elements of #arg1
 */
PTBL_CharClasses _PTBL_concatCharClasses(PTBL_CharClasses arg0, PTBL_CharClasses arg1) {
  return (PTBL_CharClasses) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a PTBL_CharClasses. 
 * \param[in] arg PTBL_CharClasses to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new PTBL_CharClasses with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
PTBL_CharClasses _PTBL_sliceCharClasses(PTBL_CharClasses arg, int start, int end) {
  return (PTBL_CharClasses) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the PTBL_CharClass at #index from a PTBL_CharClasses. 
 * \param[in] arg PTBL_CharClasses to retrieve the PTBL_CharClass from
 * \param[in] index index to use to point in the PTBL_CharClasses
 * \return PTBL_CharClass at position #index in #arg
 */
PTBL_CharClass _PTBL_getCharClassesCharClassAt(PTBL_CharClasses arg, int index) {
 return (PTBL_CharClass)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the PTBL_CharClass at #index from a PTBL_CharClasses by a new one. 
 * \param[in] arg PTBL_CharClasses to retrieve the PTBL_CharClass from
 * \param[in] elem new PTBL_CharClass to replace another
 * \param[in] index index to use to point in the PTBL_CharClasses
 * \return A new PTBL_CharClasseswith #elem replaced in #arg at position #index
 */
PTBL_CharClasses _PTBL_replaceCharClassesCharClassAt(PTBL_CharClasses arg, PTBL_CharClass elem, int index) {
 return (PTBL_CharClasses) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a PTBL_CharClasses of 2 consecutive elements. 
 * \param[in] elem1 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem2 One PTBL_CharClass element of the new PTBL_CharClasses
 * \return A new PTBL_CharClasses consisting of 2 PTBL_CharClasss
 */
PTBL_CharClasses _PTBL_makeCharClasses2(PTBL_CharClass elem1, PTBL_CharClass elem2) {
  return (PTBL_CharClasses) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a PTBL_CharClasses of 3 consecutive elements. 
 * \param[in] elem1 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem2 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem3 One PTBL_CharClass element of the new PTBL_CharClasses
 * \return A new PTBL_CharClasses consisting of 3 PTBL_CharClasss
 */
PTBL_CharClasses _PTBL_makeCharClasses3(PTBL_CharClass elem1, PTBL_CharClass elem2, PTBL_CharClass elem3) {
  return (PTBL_CharClasses) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a PTBL_CharClasses of 4 consecutive elements. 
 * \param[in] elem1 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem2 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem3 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem4 One PTBL_CharClass element of the new PTBL_CharClasses
 * \return A new PTBL_CharClasses consisting of 4 PTBL_CharClasss
 */
PTBL_CharClasses _PTBL_makeCharClasses4(PTBL_CharClass elem1, PTBL_CharClass elem2, PTBL_CharClass elem3, PTBL_CharClass elem4) {
  return (PTBL_CharClasses) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a PTBL_CharClasses of 5 consecutive elements. 
 * \param[in] elem1 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem2 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem3 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem4 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem5 One PTBL_CharClass element of the new PTBL_CharClasses
 * \return A new PTBL_CharClasses consisting of 5 PTBL_CharClasss
 */
PTBL_CharClasses _PTBL_makeCharClasses5(PTBL_CharClass elem1, PTBL_CharClass elem2, PTBL_CharClass elem3, PTBL_CharClass elem4, PTBL_CharClass elem5) {
  return (PTBL_CharClasses) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a PTBL_CharClasses of 6 consecutive elements. 
 * \param[in] elem1 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem2 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem3 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem4 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem5 One PTBL_CharClass element of the new PTBL_CharClasses
 * \param[in] elem6 One PTBL_CharClass element of the new PTBL_CharClasses
 * \return A new PTBL_CharClasses consisting of 6 PTBL_CharClasss
 */
PTBL_CharClasses _PTBL_makeCharClasses6(PTBL_CharClass elem1, PTBL_CharClass elem2, PTBL_CharClass elem3, PTBL_CharClass elem4, PTBL_CharClass elem5, PTBL_CharClass elem6) {
  return (PTBL_CharClasses) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a PTBL_Priorities. 
 * \param[in] arg input PTBL_Priorities
 * \return The number of elements in the PTBL_Priorities
 */
int _PTBL_getPrioritiesLength(PTBL_Priorities arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a PTBL_Priorities. 
 * \param[in] arg PTBL_Priorities to be reversed
 * \return a reversed #arg
 */
PTBL_Priorities _PTBL_reversePriorities(PTBL_Priorities arg) {
  return (PTBL_Priorities) ATreverse((ATermList) arg);
}

/**
 * Append a PTBL_Priority to the end of a PTBL_Priorities. 
 * \param[in] arg PTBL_Priorities to append the PTBL_Priority to
 * \param[in] elem PTBL_Priority to be appended
 * \return new PTBL_Priorities with #elem appended
 */
PTBL_Priorities _PTBL_appendPriorities(PTBL_Priorities arg, PTBL_Priority elem) {
  return (PTBL_Priorities) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two PTBL_Prioritiess. 
 * \param[in] arg0 first PTBL_Priorities
 * \param[in] arg1 second PTBL_Priorities
 * \return PTBL_Priorities with the elements of #arg0 before the elements of #arg1
 */
PTBL_Priorities _PTBL_concatPriorities(PTBL_Priorities arg0, PTBL_Priorities arg1) {
  return (PTBL_Priorities) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a PTBL_Priorities. 
 * \param[in] arg PTBL_Priorities to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new PTBL_Priorities with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
PTBL_Priorities _PTBL_slicePriorities(PTBL_Priorities arg, int start, int end) {
  return (PTBL_Priorities) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the PTBL_Priority at #index from a PTBL_Priorities. 
 * \param[in] arg PTBL_Priorities to retrieve the PTBL_Priority from
 * \param[in] index index to use to point in the PTBL_Priorities
 * \return PTBL_Priority at position #index in #arg
 */
PTBL_Priority _PTBL_getPrioritiesPriorityAt(PTBL_Priorities arg, int index) {
 return (PTBL_Priority)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the PTBL_Priority at #index from a PTBL_Priorities by a new one. 
 * \param[in] arg PTBL_Priorities to retrieve the PTBL_Priority from
 * \param[in] elem new PTBL_Priority to replace another
 * \param[in] index index to use to point in the PTBL_Priorities
 * \return A new PTBL_Prioritieswith #elem replaced in #arg at position #index
 */
PTBL_Priorities _PTBL_replacePrioritiesPriorityAt(PTBL_Priorities arg, PTBL_Priority elem, int index) {
 return (PTBL_Priorities) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a PTBL_Priorities of 2 consecutive elements. 
 * \param[in] elem1 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem2 One PTBL_Priority element of the new PTBL_Priorities
 * \return A new PTBL_Priorities consisting of 2 PTBL_Prioritys
 */
PTBL_Priorities _PTBL_makePriorities2(PTBL_Priority elem1, PTBL_Priority elem2) {
  return (PTBL_Priorities) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a PTBL_Priorities of 3 consecutive elements. 
 * \param[in] elem1 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem2 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem3 One PTBL_Priority element of the new PTBL_Priorities
 * \return A new PTBL_Priorities consisting of 3 PTBL_Prioritys
 */
PTBL_Priorities _PTBL_makePriorities3(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3) {
  return (PTBL_Priorities) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a PTBL_Priorities of 4 consecutive elements. 
 * \param[in] elem1 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem2 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem3 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem4 One PTBL_Priority element of the new PTBL_Priorities
 * \return A new PTBL_Priorities consisting of 4 PTBL_Prioritys
 */
PTBL_Priorities _PTBL_makePriorities4(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3, PTBL_Priority elem4) {
  return (PTBL_Priorities) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a PTBL_Priorities of 5 consecutive elements. 
 * \param[in] elem1 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem2 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem3 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem4 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem5 One PTBL_Priority element of the new PTBL_Priorities
 * \return A new PTBL_Priorities consisting of 5 PTBL_Prioritys
 */
PTBL_Priorities _PTBL_makePriorities5(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3, PTBL_Priority elem4, PTBL_Priority elem5) {
  return (PTBL_Priorities) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a PTBL_Priorities of 6 consecutive elements. 
 * \param[in] elem1 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem2 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem3 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem4 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem5 One PTBL_Priority element of the new PTBL_Priorities
 * \param[in] elem6 One PTBL_Priority element of the new PTBL_Priorities
 * \return A new PTBL_Priorities consisting of 6 PTBL_Prioritys
 */
PTBL_Priorities _PTBL_makePriorities6(PTBL_Priority elem1, PTBL_Priority elem2, PTBL_Priority elem3, PTBL_Priority elem4, PTBL_Priority elem5, PTBL_Priority elem6) {
  return (PTBL_Priorities) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Constructs a external of type PTBL_Production. Like all ATerm types, PTBL_Productions are maximally shared.
 * \param[in] prod a child of the new external
 * \return A pointer to a external, either newly constructed or shared
 */
PTBL_Production PTBL_makeProductionExternal(ATerm prod) {
  return (PTBL_Production)(ATerm) prod;
}
/**
 * Constructs a external of type PTBL_CharClass. Like all ATerm types, PTBL_CharClasss are maximally shared.
 * \param[in] charClass a child of the new external
 * \return A pointer to a external, either newly constructed or shared
 */
PTBL_CharClass PTBL_makeCharClassExternal(ATerm charClass) {
  return (PTBL_CharClass)(ATerm) charClass;
}
/**
 * Constructs a external of type PTBL_CharRanges. Like all ATerm types, PTBL_CharRangess are maximally shared.
 * \param[in] ranges a child of the new external
 * \return A pointer to a external, either newly constructed or shared
 */
PTBL_CharRanges PTBL_makeCharRangesExternal(ATerm ranges) {
  return (PTBL_CharRanges)(ATerm) ranges;
}
/**
 * Constructs a Default of type PTBL_Version. Like all ATerm types, PTBL_Versions are maximally shared.
 * \return A pointer to a Default, either newly constructed or shared
 */
PTBL_Version PTBL_makeVersionDefault(void) {
  return (PTBL_Version)(ATerm)ATmakeInt(6);
}
/**
 * Constructs a parse-table of type PTBL_ParseTable. Like all ATerm types, PTBL_ParseTables are maximally shared.
 * \param[in] version a child of the new parse-table
 * \param[in] initialState a child of the new parse-table
 * \param[in] labels a child of the new parse-table
 * \param[in] states a child of the new parse-table
 * \param[in] priorities a child of the new parse-table
 * \return A pointer to a parse-table, either newly constructed or shared
 */
PTBL_ParseTable PTBL_makeParseTableParseTable(PTBL_Version version, int initialState, PTBL_Labels labels, PTBL_States states, PTBL_Priorities priorities) {
  return (PTBL_ParseTable)(ATerm)ATmakeAppl5(PTBL_afun0, (ATerm) version, (ATerm) (ATerm) ATmakeInt(initialState), (ATerm) labels, (ATerm)ATmakeAppl1(PTBL_afun1, (ATerm) states), (ATerm)ATmakeAppl1(PTBL_afun2, (ATerm) priorities));
}
/**
 * Constructs a empty of type PTBL_Labels. Like all ATerm types, PTBL_Labelss are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
PTBL_Labels PTBL_makeLabelsEmpty(void) {
  return (PTBL_Labels)(ATerm)ATempty;
}
/**
 * Constructs a single of type PTBL_Labels. Like all ATerm types, PTBL_Labelss are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
PTBL_Labels PTBL_makeLabelsSingle(PTBL_Label head) {
  return (PTBL_Labels)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type PTBL_Labels. Like all ATerm types, PTBL_Labelss are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
PTBL_Labels PTBL_makeLabelsMany(PTBL_Label head, PTBL_Labels tail) {
  return (PTBL_Labels)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a Default of type PTBL_Label. Like all ATerm types, PTBL_Labels are maximally shared.
 * \param[in] production a child of the new Default
 * \param[in] number a child of the new Default
 * \return A pointer to a Default, either newly constructed or shared
 */
PTBL_Label PTBL_makeLabelDefault(PTBL_Production production, int number) {
  return (PTBL_Label)(ATerm)ATmakeAppl2(PTBL_afun3, (ATerm) production, (ATerm) (ATerm) ATmakeInt(number));
}
/**
 * Constructs a empty of type PTBL_States. Like all ATerm types, PTBL_Statess are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
PTBL_States PTBL_makeStatesEmpty(void) {
  return (PTBL_States)(ATerm)ATempty;
}
/**
 * Constructs a single of type PTBL_States. Like all ATerm types, PTBL_Statess are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
PTBL_States PTBL_makeStatesSingle(PTBL_State head) {
  return (PTBL_States)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type PTBL_States. Like all ATerm types, PTBL_Statess are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
PTBL_States PTBL_makeStatesMany(PTBL_State head, PTBL_States tail) {
  return (PTBL_States)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a Default of type PTBL_State. Like all ATerm types, PTBL_States are maximally shared.
 * \param[in] number a child of the new Default
 * \param[in] gotos a child of the new Default
 * \param[in] choices a child of the new Default
 * \return A pointer to a Default, either newly constructed or shared
 */
PTBL_State PTBL_makeStateDefault(int number, PTBL_Gotos gotos, PTBL_Choices choices) {
  return (PTBL_State)(ATerm)ATmakeAppl3(PTBL_afun4, (ATerm) (ATerm) ATmakeInt(number), (ATerm) gotos, (ATerm) choices);
}
/**
 * Constructs a empty of type PTBL_Gotos. Like all ATerm types, PTBL_Gotoss are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
PTBL_Gotos PTBL_makeGotosEmpty(void) {
  return (PTBL_Gotos)(ATerm)ATempty;
}
/**
 * Constructs a single of type PTBL_Gotos. Like all ATerm types, PTBL_Gotoss are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
PTBL_Gotos PTBL_makeGotosSingle(PTBL_Goto head) {
  return (PTBL_Gotos)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type PTBL_Gotos. Like all ATerm types, PTBL_Gotoss are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
PTBL_Gotos PTBL_makeGotosMany(PTBL_Goto head, PTBL_Gotos tail) {
  return (PTBL_Gotos)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a Default of type PTBL_Goto. Like all ATerm types, PTBL_Gotos are maximally shared.
 * \param[in] ranges a child of the new Default
 * \param[in] stateNumber a child of the new Default
 * \return A pointer to a Default, either newly constructed or shared
 */
PTBL_Goto PTBL_makeGotoDefault(PTBL_CharRanges ranges, int stateNumber) {
  return (PTBL_Goto)(ATerm)ATmakeAppl2(PTBL_afun5, (ATerm) ranges, (ATerm) (ATerm) ATmakeInt(stateNumber));
}
/**
 * Constructs a empty of type PTBL_Choices. Like all ATerm types, PTBL_Choicess are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
PTBL_Choices PTBL_makeChoicesEmpty(void) {
  return (PTBL_Choices)(ATerm)ATempty;
}
/**
 * Constructs a single of type PTBL_Choices. Like all ATerm types, PTBL_Choicess are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
PTBL_Choices PTBL_makeChoicesSingle(PTBL_Choice head) {
  return (PTBL_Choices)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type PTBL_Choices. Like all ATerm types, PTBL_Choicess are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
PTBL_Choices PTBL_makeChoicesMany(PTBL_Choice head, PTBL_Choices tail) {
  return (PTBL_Choices)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a Default of type PTBL_Choice. Like all ATerm types, PTBL_Choices are maximally shared.
 * \param[in] ranges a child of the new Default
 * \param[in] actions a child of the new Default
 * \return A pointer to a Default, either newly constructed or shared
 */
PTBL_Choice PTBL_makeChoiceDefault(PTBL_CharRanges ranges, PTBL_Actions actions) {
  return (PTBL_Choice)(ATerm)ATmakeAppl2(PTBL_afun6, (ATerm) ranges, (ATerm) actions);
}
/**
 * Constructs a empty of type PTBL_Actions. Like all ATerm types, PTBL_Actionss are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
PTBL_Actions PTBL_makeActionsEmpty(void) {
  return (PTBL_Actions)(ATerm)ATempty;
}
/**
 * Constructs a single of type PTBL_Actions. Like all ATerm types, PTBL_Actionss are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
PTBL_Actions PTBL_makeActionsSingle(PTBL_Action head) {
  return (PTBL_Actions)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type PTBL_Actions. Like all ATerm types, PTBL_Actionss are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
PTBL_Actions PTBL_makeActionsMany(PTBL_Action head, PTBL_Actions tail) {
  return (PTBL_Actions)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a reduce of type PTBL_Action. Like all ATerm types, PTBL_Actions are maximally shared.
 * \param[in] length a child of the new reduce
 * \param[in] label a child of the new reduce
 * \param[in] specialAttr a child of the new reduce
 * \return A pointer to a reduce, either newly constructed or shared
 */
PTBL_Action PTBL_makeActionReduce(int length, int label, PTBL_SpecialAttr specialAttr) {
  return (PTBL_Action)(ATerm)ATmakeAppl3(PTBL_afun7, (ATerm) (ATerm) ATmakeInt(length), (ATerm) (ATerm) ATmakeInt(label), (ATerm) specialAttr);
}
/**
 * Constructs a lookahead-reduce of type PTBL_Action. Like all ATerm types, PTBL_Actions are maximally shared.
 * \param[in] length a child of the new lookahead-reduce
 * \param[in] label a child of the new lookahead-reduce
 * \param[in] specialAttr a child of the new lookahead-reduce
 * \param[in] restrictions a child of the new lookahead-reduce
 * \return A pointer to a lookahead-reduce, either newly constructed or shared
 */
PTBL_Action PTBL_makeActionLookaheadReduce(int length, int label, PTBL_SpecialAttr specialAttr, PTBL_Restrictions restrictions) {
  return (PTBL_Action)(ATerm)ATmakeAppl4(PTBL_afun8, (ATerm) (ATerm) ATmakeInt(length), (ATerm) (ATerm) ATmakeInt(label), (ATerm) specialAttr, (ATerm) restrictions);
}
/**
 * Constructs a shift of type PTBL_Action. Like all ATerm types, PTBL_Actions are maximally shared.
 * \param[in] stateNumber a child of the new shift
 * \return A pointer to a shift, either newly constructed or shared
 */
PTBL_Action PTBL_makeActionShift(int stateNumber) {
  return (PTBL_Action)(ATerm)ATmakeAppl1(PTBL_afun9, (ATerm) (ATerm) ATmakeInt(stateNumber));
}
/**
 * Constructs a accept of type PTBL_Action. Like all ATerm types, PTBL_Actions are maximally shared.
 * \return A pointer to a accept, either newly constructed or shared
 */
PTBL_Action PTBL_makeActionAccept(void) {
  return (PTBL_Action)(ATerm)ATmakeAppl0(PTBL_afun10);
}
/**
 * Constructs a none of type PTBL_SpecialAttr. Like all ATerm types, PTBL_SpecialAttrs are maximally shared.
 * \return A pointer to a none, either newly constructed or shared
 */
PTBL_SpecialAttr PTBL_makeSpecialAttrNone(void) {
  return (PTBL_SpecialAttr)(ATerm)ATmakeInt(0);
}
/**
 * Constructs a reject of type PTBL_SpecialAttr. Like all ATerm types, PTBL_SpecialAttrs are maximally shared.
 * \return A pointer to a reject, either newly constructed or shared
 */
PTBL_SpecialAttr PTBL_makeSpecialAttrReject(void) {
  return (PTBL_SpecialAttr)(ATerm)ATmakeInt(1);
}
/**
 * Constructs a prefer of type PTBL_SpecialAttr. Like all ATerm types, PTBL_SpecialAttrs are maximally shared.
 * \return A pointer to a prefer, either newly constructed or shared
 */
PTBL_SpecialAttr PTBL_makeSpecialAttrPrefer(void) {
  return (PTBL_SpecialAttr)(ATerm)ATmakeInt(2);
}
/**
 * Constructs a avoid of type PTBL_SpecialAttr. Like all ATerm types, PTBL_SpecialAttrs are maximally shared.
 * \return A pointer to a avoid, either newly constructed or shared
 */
PTBL_SpecialAttr PTBL_makeSpecialAttrAvoid(void) {
  return (PTBL_SpecialAttr)(ATerm)ATmakeInt(4);
}
/**
 * Constructs a empty of type PTBL_Restrictions. Like all ATerm types, PTBL_Restrictionss are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
PTBL_Restrictions PTBL_makeRestrictionsEmpty(void) {
  return (PTBL_Restrictions)(ATerm)ATempty;
}
/**
 * Constructs a single of type PTBL_Restrictions. Like all ATerm types, PTBL_Restrictionss are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
PTBL_Restrictions PTBL_makeRestrictionsSingle(PTBL_Restriction head) {
  return (PTBL_Restrictions)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type PTBL_Restrictions. Like all ATerm types, PTBL_Restrictionss are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
PTBL_Restrictions PTBL_makeRestrictionsMany(PTBL_Restriction head, PTBL_Restrictions tail) {
  return (PTBL_Restrictions)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a follow of type PTBL_Restriction. Like all ATerm types, PTBL_Restrictions are maximally shared.
 * \param[in] charClasses a child of the new follow
 * \return A pointer to a follow, either newly constructed or shared
 */
PTBL_Restriction PTBL_makeRestrictionFollow(PTBL_CharClasses charClasses) {
  return (PTBL_Restriction)(ATerm)ATmakeAppl1(PTBL_afun11, (ATerm) charClasses);
}
/**
 * Constructs a empty of type PTBL_CharClasses. Like all ATerm types, PTBL_CharClassess are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
PTBL_CharClasses PTBL_makeCharClassesEmpty(void) {
  return (PTBL_CharClasses)(ATerm)ATempty;
}
/**
 * Constructs a single of type PTBL_CharClasses. Like all ATerm types, PTBL_CharClassess are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
PTBL_CharClasses PTBL_makeCharClassesSingle(PTBL_CharClass head) {
  return (PTBL_CharClasses)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type PTBL_CharClasses. Like all ATerm types, PTBL_CharClassess are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
PTBL_CharClasses PTBL_makeCharClassesMany(PTBL_CharClass head, PTBL_CharClasses tail) {
  return (PTBL_CharClasses)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a empty of type PTBL_Priorities. Like all ATerm types, PTBL_Prioritiess are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
PTBL_Priorities PTBL_makePrioritiesEmpty(void) {
  return (PTBL_Priorities)(ATerm)ATempty;
}
/**
 * Constructs a single of type PTBL_Priorities. Like all ATerm types, PTBL_Prioritiess are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
PTBL_Priorities PTBL_makePrioritiesSingle(PTBL_Priority head) {
  return (PTBL_Priorities)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type PTBL_Priorities. Like all ATerm types, PTBL_Prioritiess are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
PTBL_Priorities PTBL_makePrioritiesMany(PTBL_Priority head, PTBL_Priorities tail) {
  return (PTBL_Priorities)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a greater of type PTBL_Priority. Like all ATerm types, PTBL_Prioritys are maximally shared.
 * \param[in] label1 a child of the new greater
 * \param[in] label2 a child of the new greater
 * \return A pointer to a greater, either newly constructed or shared
 */
PTBL_Priority PTBL_makePriorityGreater(int label1, int label2) {
  return (PTBL_Priority)(ATerm)ATmakeAppl2(PTBL_afun12, (ATerm) (ATerm) ATmakeInt(label1), (ATerm) (ATerm) ATmakeInt(label2));
}
/**
 * Constructs a arg-greater of type PTBL_Priority. Like all ATerm types, PTBL_Prioritys are maximally shared.
 * \param[in] label1 a child of the new arg-greater
 * \param[in] argumentNumber a child of the new arg-greater
 * \param[in] label2 a child of the new arg-greater
 * \return A pointer to a arg-greater, either newly constructed or shared
 */
PTBL_Priority PTBL_makePriorityArgGreater(int label1, int argumentNumber, int label2) {
  return (PTBL_Priority)(ATerm)ATmakeAppl3(PTBL_afun13, (ATerm) (ATerm) ATmakeInt(label1), (ATerm) (ATerm) ATmakeInt(argumentNumber), (ATerm) (ATerm) ATmakeInt(label2));
}

/**
 * Tests equality of two PTBL_Productions. A constant time operation.
 * \param[in] arg0 first PTBL_Production to be compared
 * \param[in] arg1 second PTBL_Production to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualProduction(PTBL_Production arg0, PTBL_Production arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_CharClasss. A constant time operation.
 * \param[in] arg0 first PTBL_CharClass to be compared
 * \param[in] arg1 second PTBL_CharClass to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualCharClass(PTBL_CharClass arg0, PTBL_CharClass arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_CharRangess. A constant time operation.
 * \param[in] arg0 first PTBL_CharRanges to be compared
 * \param[in] arg1 second PTBL_CharRanges to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualCharRanges(PTBL_CharRanges arg0, PTBL_CharRanges arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_Versions. A constant time operation.
 * \param[in] arg0 first PTBL_Version to be compared
 * \param[in] arg1 second PTBL_Version to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualVersion(PTBL_Version arg0, PTBL_Version arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_ParseTables. A constant time operation.
 * \param[in] arg0 first PTBL_ParseTable to be compared
 * \param[in] arg1 second PTBL_ParseTable to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualParseTable(PTBL_ParseTable arg0, PTBL_ParseTable arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_Labelss. A constant time operation.
 * \param[in] arg0 first PTBL_Labels to be compared
 * \param[in] arg1 second PTBL_Labels to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualLabels(PTBL_Labels arg0, PTBL_Labels arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_Labels. A constant time operation.
 * \param[in] arg0 first PTBL_Label to be compared
 * \param[in] arg1 second PTBL_Label to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualLabel(PTBL_Label arg0, PTBL_Label arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_Statess. A constant time operation.
 * \param[in] arg0 first PTBL_States to be compared
 * \param[in] arg1 second PTBL_States to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualStates(PTBL_States arg0, PTBL_States arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_States. A constant time operation.
 * \param[in] arg0 first PTBL_State to be compared
 * \param[in] arg1 second PTBL_State to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualState(PTBL_State arg0, PTBL_State arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_Gotoss. A constant time operation.
 * \param[in] arg0 first PTBL_Gotos to be compared
 * \param[in] arg1 second PTBL_Gotos to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualGotos(PTBL_Gotos arg0, PTBL_Gotos arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_Gotos. A constant time operation.
 * \param[in] arg0 first PTBL_Goto to be compared
 * \param[in] arg1 second PTBL_Goto to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualGoto(PTBL_Goto arg0, PTBL_Goto arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_Choicess. A constant time operation.
 * \param[in] arg0 first PTBL_Choices to be compared
 * \param[in] arg1 second PTBL_Choices to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualChoices(PTBL_Choices arg0, PTBL_Choices arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_Choices. A constant time operation.
 * \param[in] arg0 first PTBL_Choice to be compared
 * \param[in] arg1 second PTBL_Choice to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualChoice(PTBL_Choice arg0, PTBL_Choice arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_Actionss. A constant time operation.
 * \param[in] arg0 first PTBL_Actions to be compared
 * \param[in] arg1 second PTBL_Actions to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualActions(PTBL_Actions arg0, PTBL_Actions arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_Actions. A constant time operation.
 * \param[in] arg0 first PTBL_Action to be compared
 * \param[in] arg1 second PTBL_Action to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualAction(PTBL_Action arg0, PTBL_Action arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_SpecialAttrs. A constant time operation.
 * \param[in] arg0 first PTBL_SpecialAttr to be compared
 * \param[in] arg1 second PTBL_SpecialAttr to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualSpecialAttr(PTBL_SpecialAttr arg0, PTBL_SpecialAttr arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_Restrictionss. A constant time operation.
 * \param[in] arg0 first PTBL_Restrictions to be compared
 * \param[in] arg1 second PTBL_Restrictions to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualRestrictions(PTBL_Restrictions arg0, PTBL_Restrictions arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_Restrictions. A constant time operation.
 * \param[in] arg0 first PTBL_Restriction to be compared
 * \param[in] arg1 second PTBL_Restriction to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualRestriction(PTBL_Restriction arg0, PTBL_Restriction arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_CharClassess. A constant time operation.
 * \param[in] arg0 first PTBL_CharClasses to be compared
 * \param[in] arg1 second PTBL_CharClasses to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualCharClasses(PTBL_CharClasses arg0, PTBL_CharClasses arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_Prioritiess. A constant time operation.
 * \param[in] arg0 first PTBL_Priorities to be compared
 * \param[in] arg1 second PTBL_Priorities to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualPriorities(PTBL_Priorities arg0, PTBL_Priorities arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two PTBL_Prioritys. A constant time operation.
 * \param[in] arg0 first PTBL_Priority to be compared
 * \param[in] arg1 second PTBL_Priority to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _PTBL_isEqualPriority(PTBL_Priority arg0, PTBL_Priority arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Assert whether a PTBL_Production is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_Production
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PTBL_isValidProduction(PTBL_Production arg) {
  if (PTBL_isProductionExternal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Production is a external by checking against the following ATerm pattern: <prod(term)>. Always returns ATtrue
 * \param[in] arg input PTBL_Production
 * \return ATtrue if #arg corresponds to the signature of a external, or ATfalse otherwise
 */
inline ATbool PTBL_isProductionExternal(PTBL_Production arg){
  if (arg != NULL) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Production has a prod. 
 * \param[in] arg input PTBL_Production
 * \return ATtrue if the PTBL_Production had a prod, or ATfalse otherwise
 */
ATbool PTBL_hasProductionProd(PTBL_Production arg) {
  if (PTBL_isProductionExternal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the prod ATerm of a PTBL_Production. Note that the precondition is that this PTBL_Production actually has a prod
 * \param[in] arg input PTBL_Production
 * \return the prod of #arg, if it exist or an undefined value if it does not
 */
ATerm PTBL_getProductionProd(PTBL_Production arg) {
  
    return (ATerm)arg;
}

/**
 * Set the prod of a PTBL_Production. The precondition being that this PTBL_Production actually has a prod
 * \param[in] arg input PTBL_Production
 * \param[in] prod new ATerm to set in #arg
 * \return A new PTBL_Production with prod at the right place, or a core dump if #arg did not have a prod
 */
PTBL_Production PTBL_setProductionProd(PTBL_Production arg, ATerm prod) {
  if (PTBL_isProductionExternal(arg)) {
    return (PTBL_Production)((ATerm) prod);
  }

  ATabort("Production has no Prod: %t\n", arg);
  return (PTBL_Production)NULL;
}

/**
 * Assert whether a PTBL_CharClass is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_CharClass
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PTBL_isValidCharClass(PTBL_CharClass arg) {
  if (PTBL_isCharClassExternal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_CharClass is a external by checking against the following ATerm pattern: <char-class(term)>. Always returns ATtrue
 * \param[in] arg input PTBL_CharClass
 * \return ATtrue if #arg corresponds to the signature of a external, or ATfalse otherwise
 */
inline ATbool PTBL_isCharClassExternal(PTBL_CharClass arg){
  if (arg != NULL) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_CharClass has a char-class. 
 * \param[in] arg input PTBL_CharClass
 * \return ATtrue if the PTBL_CharClass had a char-class, or ATfalse otherwise
 */
ATbool PTBL_hasCharClassCharClass(PTBL_CharClass arg) {
  if (PTBL_isCharClassExternal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the char-class ATerm of a PTBL_CharClass. Note that the precondition is that this PTBL_CharClass actually has a char-class
 * \param[in] arg input PTBL_CharClass
 * \return the char-class of #arg, if it exist or an undefined value if it does not
 */
ATerm PTBL_getCharClassCharClass(PTBL_CharClass arg) {
  
    return (ATerm)arg;
}

/**
 * Set the char-class of a PTBL_CharClass. The precondition being that this PTBL_CharClass actually has a char-class
 * \param[in] arg input PTBL_CharClass
 * \param[in] charClass new ATerm to set in #arg
 * \return A new PTBL_CharClass with charClass at the right place, or a core dump if #arg did not have a charClass
 */
PTBL_CharClass PTBL_setCharClassCharClass(PTBL_CharClass arg, ATerm charClass) {
  if (PTBL_isCharClassExternal(arg)) {
    return (PTBL_CharClass)((ATerm) charClass);
  }

  ATabort("CharClass has no CharClass: %t\n", arg);
  return (PTBL_CharClass)NULL;
}

/**
 * Assert whether a PTBL_CharRanges is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_CharRanges
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PTBL_isValidCharRanges(PTBL_CharRanges arg) {
  if (PTBL_isCharRangesExternal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_CharRanges is a external by checking against the following ATerm pattern: <ranges(term)>. Always returns ATtrue
 * \param[in] arg input PTBL_CharRanges
 * \return ATtrue if #arg corresponds to the signature of a external, or ATfalse otherwise
 */
inline ATbool PTBL_isCharRangesExternal(PTBL_CharRanges arg){
  if (arg != NULL) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_CharRanges has a ranges. 
 * \param[in] arg input PTBL_CharRanges
 * \return ATtrue if the PTBL_CharRanges had a ranges, or ATfalse otherwise
 */
ATbool PTBL_hasCharRangesRanges(PTBL_CharRanges arg) {
  if (PTBL_isCharRangesExternal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ranges ATerm of a PTBL_CharRanges. Note that the precondition is that this PTBL_CharRanges actually has a ranges
 * \param[in] arg input PTBL_CharRanges
 * \return the ranges of #arg, if it exist or an undefined value if it does not
 */
ATerm PTBL_getCharRangesRanges(PTBL_CharRanges arg) {
  
    return (ATerm)arg;
}

/**
 * Set the ranges of a PTBL_CharRanges. The precondition being that this PTBL_CharRanges actually has a ranges
 * \param[in] arg input PTBL_CharRanges
 * \param[in] ranges new ATerm to set in #arg
 * \return A new PTBL_CharRanges with ranges at the right place, or a core dump if #arg did not have a ranges
 */
PTBL_CharRanges PTBL_setCharRangesRanges(PTBL_CharRanges arg, ATerm ranges) {
  if (PTBL_isCharRangesExternal(arg)) {
    return (PTBL_CharRanges)((ATerm) ranges);
  }

  ATabort("CharRanges has no Ranges: %t\n", arg);
  return (PTBL_CharRanges)NULL;
}

/**
 * Assert whether a PTBL_Version is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_Version
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PTBL_isValidVersion(PTBL_Version arg) {
  if (PTBL_isVersionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Version is a Default by checking against the following ATerm pattern: 6. Always returns ATtrue
 * \param[in] arg input PTBL_Version
 * \return ATtrue if #arg corresponds to the signature of a Default, or ATfalse otherwise
 */
inline ATbool PTBL_isVersionDefault(PTBL_Version arg){
  if (ATgetInt((ATermInt)arg) == 6) {

    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_ParseTable is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_ParseTable
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PTBL_isValidParseTable(PTBL_ParseTable arg) {
  if (PTBL_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_ParseTable is a parse-table by checking against the following ATerm pattern: parse-table(<version(Version)>,<initial-state(int)>,<labels(Labels)>,states(<states(States)>),priorities(<priorities(Priorities)>)). Always returns ATtrue
 * \param[in] arg input PTBL_ParseTable
 * \return ATtrue if #arg corresponds to the signature of a parse-table, or ATfalse otherwise
 */
inline ATbool PTBL_isParseTableParseTable(PTBL_ParseTable arg){
  /* checking for: parse-table */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == PTBL_afun0) {
    ATerm arg_arg1 = ATgetArgument(arg, 1);
    if (ATgetType((ATerm)arg_arg1) == AT_INT) {
      ATerm arg_arg3 = ATgetArgument(arg, 3);
      /* checking for: states */
      if (ATgetType((ATerm)arg_arg3) == AT_APPL && ATgetAFun((ATermAppl)arg_arg3) == PTBL_afun1) {
        ATerm arg_arg4 = ATgetArgument(arg, 4);
        /* checking for: priorities */
        if (ATgetType((ATerm)arg_arg4) == AT_APPL && ATgetAFun((ATermAppl)arg_arg4) == PTBL_afun2) {
          return ATtrue;
        }
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_ParseTable has a version. 
 * \param[in] arg input PTBL_ParseTable
 * \return ATtrue if the PTBL_ParseTable had a version, or ATfalse otherwise
 */
ATbool PTBL_hasParseTableVersion(PTBL_ParseTable arg) {
  if (PTBL_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_ParseTable has a initial-state. 
 * \param[in] arg input PTBL_ParseTable
 * \return ATtrue if the PTBL_ParseTable had a initial-state, or ATfalse otherwise
 */
ATbool PTBL_hasParseTableInitialState(PTBL_ParseTable arg) {
  if (PTBL_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_ParseTable has a labels. 
 * \param[in] arg input PTBL_ParseTable
 * \return ATtrue if the PTBL_ParseTable had a labels, or ATfalse otherwise
 */
ATbool PTBL_hasParseTableLabels(PTBL_ParseTable arg) {
  if (PTBL_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_ParseTable has a states. 
 * \param[in] arg input PTBL_ParseTable
 * \return ATtrue if the PTBL_ParseTable had a states, or ATfalse otherwise
 */
ATbool PTBL_hasParseTableStates(PTBL_ParseTable arg) {
  if (PTBL_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_ParseTable has a priorities. 
 * \param[in] arg input PTBL_ParseTable
 * \return ATtrue if the PTBL_ParseTable had a priorities, or ATfalse otherwise
 */
ATbool PTBL_hasParseTablePriorities(PTBL_ParseTable arg) {
  if (PTBL_isParseTableParseTable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the version PTBL_Version of a PTBL_ParseTable. Note that the precondition is that this PTBL_ParseTable actually has a version
 * \param[in] arg input PTBL_ParseTable
 * \return the version of #arg, if it exist or an undefined value if it does not
 */
PTBL_Version PTBL_getParseTableVersion(PTBL_ParseTable arg) {
  
    return (PTBL_Version)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the initial-state int of a PTBL_ParseTable. Note that the precondition is that this PTBL_ParseTable actually has a initial-state
 * \param[in] arg input PTBL_ParseTable
 * \return the initial-state of #arg, if it exist or an undefined value if it does not
 */
int PTBL_getParseTableInitialState(PTBL_ParseTable arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the labels PTBL_Labels of a PTBL_ParseTable. Note that the precondition is that this PTBL_ParseTable actually has a labels
 * \param[in] arg input PTBL_ParseTable
 * \return the labels of #arg, if it exist or an undefined value if it does not
 */
PTBL_Labels PTBL_getParseTableLabels(PTBL_ParseTable arg) {
  
    return (PTBL_Labels)ATgetArgument((ATermAppl)arg, 2);
}

/**
 * Get the states PTBL_States of a PTBL_ParseTable. Note that the precondition is that this PTBL_ParseTable actually has a states
 * \param[in] arg input PTBL_ParseTable
 * \return the states of #arg, if it exist or an undefined value if it does not
 */
PTBL_States PTBL_getParseTableStates(PTBL_ParseTable arg) {
  
    return (PTBL_States)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 3), 0);
}

/**
 * Get the priorities PTBL_Priorities of a PTBL_ParseTable. Note that the precondition is that this PTBL_ParseTable actually has a priorities
 * \param[in] arg input PTBL_ParseTable
 * \return the priorities of #arg, if it exist or an undefined value if it does not
 */
PTBL_Priorities PTBL_getParseTablePriorities(PTBL_ParseTable arg) {
  
    return (PTBL_Priorities)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 4), 0);
}

/**
 * Set the version of a PTBL_ParseTable. The precondition being that this PTBL_ParseTable actually has a version
 * \param[in] arg input PTBL_ParseTable
 * \param[in] version new PTBL_Version to set in #arg
 * \return A new PTBL_ParseTable with version at the right place, or a core dump if #arg did not have a version
 */
PTBL_ParseTable PTBL_setParseTableVersion(PTBL_ParseTable arg, PTBL_Version version) {
  if (PTBL_isParseTableParseTable(arg)) {
    return (PTBL_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) version), 0);
  }

  ATabort("ParseTable has no Version: %t\n", arg);
  return (PTBL_ParseTable)NULL;
}

/**
 * Set the initial-state of a PTBL_ParseTable. The precondition being that this PTBL_ParseTable actually has a initial-state
 * \param[in] arg input PTBL_ParseTable
 * \param[in] initialState new int to set in #arg
 * \return A new PTBL_ParseTable with initialState at the right place, or a core dump if #arg did not have a initialState
 */
PTBL_ParseTable PTBL_setParseTableInitialState(PTBL_ParseTable arg, int initialState) {
  if (PTBL_isParseTableParseTable(arg)) {
    return (PTBL_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(initialState)), 1);
  }

  ATabort("ParseTable has no InitialState: %t\n", arg);
  return (PTBL_ParseTable)NULL;
}

/**
 * Set the labels of a PTBL_ParseTable. The precondition being that this PTBL_ParseTable actually has a labels
 * \param[in] arg input PTBL_ParseTable
 * \param[in] labels new PTBL_Labels to set in #arg
 * \return A new PTBL_ParseTable with labels at the right place, or a core dump if #arg did not have a labels
 */
PTBL_ParseTable PTBL_setParseTableLabels(PTBL_ParseTable arg, PTBL_Labels labels) {
  if (PTBL_isParseTableParseTable(arg)) {
    return (PTBL_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) labels), 2);
  }

  ATabort("ParseTable has no Labels: %t\n", arg);
  return (PTBL_ParseTable)NULL;
}

/**
 * Set the states of a PTBL_ParseTable. The precondition being that this PTBL_ParseTable actually has a states
 * \param[in] arg input PTBL_ParseTable
 * \param[in] states new PTBL_States to set in #arg
 * \return A new PTBL_ParseTable with states at the right place, or a core dump if #arg did not have a states
 */
PTBL_ParseTable PTBL_setParseTableStates(PTBL_ParseTable arg, PTBL_States states) {
  if (PTBL_isParseTableParseTable(arg)) {
    return (PTBL_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 3), (ATerm)((ATerm) states), 0), 3);
  }

  ATabort("ParseTable has no States: %t\n", arg);
  return (PTBL_ParseTable)NULL;
}

/**
 * Set the priorities of a PTBL_ParseTable. The precondition being that this PTBL_ParseTable actually has a priorities
 * \param[in] arg input PTBL_ParseTable
 * \param[in] priorities new PTBL_Priorities to set in #arg
 * \return A new PTBL_ParseTable with priorities at the right place, or a core dump if #arg did not have a priorities
 */
PTBL_ParseTable PTBL_setParseTablePriorities(PTBL_ParseTable arg, PTBL_Priorities priorities) {
  if (PTBL_isParseTableParseTable(arg)) {
    return (PTBL_ParseTable)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 4), (ATerm)((ATerm) priorities), 0), 4);
  }

  ATabort("ParseTable has no Priorities: %t\n", arg);
  return (PTBL_ParseTable)NULL;
}

/**
 * Assert whether a PTBL_Labels is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_Labels
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a PTBL_Labels is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the PTBL_Labels
 * \param[in] arg input PTBL_Labels
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool PTBL_isLabelsEmpty(PTBL_Labels arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Labels is a single by checking against the following ATerm pattern: [<head(Label)>]. May not be used to assert correctness of the PTBL_Labels
 * \param[in] arg input PTBL_Labels
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool PTBL_isLabelsSingle(PTBL_Labels arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Labels is a many by checking against the following ATerm pattern: [<head(Label)>,<[tail(Labels)]>]. May not be used to assert correctness of the PTBL_Labels
 * \param[in] arg input PTBL_Labels
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool PTBL_isLabelsMany(PTBL_Labels arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Labels has a head. 
 * \param[in] arg input PTBL_Labels
 * \return ATtrue if the PTBL_Labels had a head, or ATfalse otherwise
 */
ATbool PTBL_hasLabelsHead(PTBL_Labels arg) {
  if (PTBL_isLabelsSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isLabelsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Labels has a tail. 
 * \param[in] arg input PTBL_Labels
 * \return ATtrue if the PTBL_Labels had a tail, or ATfalse otherwise
 */
ATbool PTBL_hasLabelsTail(PTBL_Labels arg) {
  if (PTBL_isLabelsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head PTBL_Label of a PTBL_Labels. Note that the precondition is that this PTBL_Labels actually has a head
 * \param[in] arg input PTBL_Labels
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
PTBL_Label PTBL_getLabelsHead(PTBL_Labels arg) {
  if (PTBL_isLabelsSingle(arg)) {
    return (PTBL_Label)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_Label)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail PTBL_Labels of a PTBL_Labels. Note that the precondition is that this PTBL_Labels actually has a tail
 * \param[in] arg input PTBL_Labels
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
PTBL_Labels PTBL_getLabelsTail(PTBL_Labels arg) {
  
    return (PTBL_Labels)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a PTBL_Labels. The precondition being that this PTBL_Labels actually has a head
 * \param[in] arg input PTBL_Labels
 * \param[in] head new PTBL_Label to set in #arg
 * \return A new PTBL_Labels with head at the right place, or a core dump if #arg did not have a head
 */
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

/**
 * Set the tail of a PTBL_Labels. The precondition being that this PTBL_Labels actually has a tail
 * \param[in] arg input PTBL_Labels
 * \param[in] tail new PTBL_Labels to set in #arg
 * \return A new PTBL_Labels with tail at the right place, or a core dump if #arg did not have a tail
 */
PTBL_Labels PTBL_setLabelsTail(PTBL_Labels arg, PTBL_Labels tail) {
  if (PTBL_isLabelsMany(arg)) {
    return (PTBL_Labels)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Labels has no Tail: %t\n", arg);
  return (PTBL_Labels)NULL;
}

/**
 * Assert whether a PTBL_Label is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_Label
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PTBL_isValidLabel(PTBL_Label arg) {
  if (PTBL_isLabelDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Label is a Default by checking against the following ATerm pattern: label(<production(Production)>,<number(int)>). Always returns ATtrue
 * \param[in] arg input PTBL_Label
 * \return ATtrue if #arg corresponds to the signature of a Default, or ATfalse otherwise
 */
inline ATbool PTBL_isLabelDefault(PTBL_Label arg){
  /* checking for: label */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == PTBL_afun3) {
    ATerm arg_arg1 = ATgetArgument(arg, 1);
    if (ATgetType((ATerm)arg_arg1) == AT_INT) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Label has a production. 
 * \param[in] arg input PTBL_Label
 * \return ATtrue if the PTBL_Label had a production, or ATfalse otherwise
 */
ATbool PTBL_hasLabelProduction(PTBL_Label arg) {
  if (PTBL_isLabelDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Label has a number. 
 * \param[in] arg input PTBL_Label
 * \return ATtrue if the PTBL_Label had a number, or ATfalse otherwise
 */
ATbool PTBL_hasLabelNumber(PTBL_Label arg) {
  if (PTBL_isLabelDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the production PTBL_Production of a PTBL_Label. Note that the precondition is that this PTBL_Label actually has a production
 * \param[in] arg input PTBL_Label
 * \return the production of #arg, if it exist or an undefined value if it does not
 */
PTBL_Production PTBL_getLabelProduction(PTBL_Label arg) {
  
    return (PTBL_Production)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the number int of a PTBL_Label. Note that the precondition is that this PTBL_Label actually has a number
 * \param[in] arg input PTBL_Label
 * \return the number of #arg, if it exist or an undefined value if it does not
 */
int PTBL_getLabelNumber(PTBL_Label arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the production of a PTBL_Label. The precondition being that this PTBL_Label actually has a production
 * \param[in] arg input PTBL_Label
 * \param[in] production new PTBL_Production to set in #arg
 * \return A new PTBL_Label with production at the right place, or a core dump if #arg did not have a production
 */
PTBL_Label PTBL_setLabelProduction(PTBL_Label arg, PTBL_Production production) {
  if (PTBL_isLabelDefault(arg)) {
    return (PTBL_Label)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) production), 0);
  }

  ATabort("Label has no Production: %t\n", arg);
  return (PTBL_Label)NULL;
}

/**
 * Set the number of a PTBL_Label. The precondition being that this PTBL_Label actually has a number
 * \param[in] arg input PTBL_Label
 * \param[in] number new int to set in #arg
 * \return A new PTBL_Label with number at the right place, or a core dump if #arg did not have a number
 */
PTBL_Label PTBL_setLabelNumber(PTBL_Label arg, int number) {
  if (PTBL_isLabelDefault(arg)) {
    return (PTBL_Label)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(number)), 1);
  }

  ATabort("Label has no Number: %t\n", arg);
  return (PTBL_Label)NULL;
}

/**
 * Assert whether a PTBL_States is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_States
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a PTBL_States is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the PTBL_States
 * \param[in] arg input PTBL_States
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool PTBL_isStatesEmpty(PTBL_States arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_States is a single by checking against the following ATerm pattern: [<head(State)>]. May not be used to assert correctness of the PTBL_States
 * \param[in] arg input PTBL_States
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool PTBL_isStatesSingle(PTBL_States arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_States is a many by checking against the following ATerm pattern: [<head(State)>,<[tail(States)]>]. May not be used to assert correctness of the PTBL_States
 * \param[in] arg input PTBL_States
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool PTBL_isStatesMany(PTBL_States arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_States has a head. 
 * \param[in] arg input PTBL_States
 * \return ATtrue if the PTBL_States had a head, or ATfalse otherwise
 */
ATbool PTBL_hasStatesHead(PTBL_States arg) {
  if (PTBL_isStatesSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isStatesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_States has a tail. 
 * \param[in] arg input PTBL_States
 * \return ATtrue if the PTBL_States had a tail, or ATfalse otherwise
 */
ATbool PTBL_hasStatesTail(PTBL_States arg) {
  if (PTBL_isStatesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head PTBL_State of a PTBL_States. Note that the precondition is that this PTBL_States actually has a head
 * \param[in] arg input PTBL_States
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
PTBL_State PTBL_getStatesHead(PTBL_States arg) {
  if (PTBL_isStatesSingle(arg)) {
    return (PTBL_State)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_State)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail PTBL_States of a PTBL_States. Note that the precondition is that this PTBL_States actually has a tail
 * \param[in] arg input PTBL_States
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
PTBL_States PTBL_getStatesTail(PTBL_States arg) {
  
    return (PTBL_States)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a PTBL_States. The precondition being that this PTBL_States actually has a head
 * \param[in] arg input PTBL_States
 * \param[in] head new PTBL_State to set in #arg
 * \return A new PTBL_States with head at the right place, or a core dump if #arg did not have a head
 */
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

/**
 * Set the tail of a PTBL_States. The precondition being that this PTBL_States actually has a tail
 * \param[in] arg input PTBL_States
 * \param[in] tail new PTBL_States to set in #arg
 * \return A new PTBL_States with tail at the right place, or a core dump if #arg did not have a tail
 */
PTBL_States PTBL_setStatesTail(PTBL_States arg, PTBL_States tail) {
  if (PTBL_isStatesMany(arg)) {
    return (PTBL_States)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("States has no Tail: %t\n", arg);
  return (PTBL_States)NULL;
}

/**
 * Assert whether a PTBL_State is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_State
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PTBL_isValidState(PTBL_State arg) {
  if (PTBL_isStateDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_State is a Default by checking against the following ATerm pattern: state-rec(<number(int)>,<gotos(Gotos)>,<choices(Choices)>). Always returns ATtrue
 * \param[in] arg input PTBL_State
 * \return ATtrue if #arg corresponds to the signature of a Default, or ATfalse otherwise
 */
inline ATbool PTBL_isStateDefault(PTBL_State arg){
  /* checking for: state-rec */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == PTBL_afun4) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_INT) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_State has a number. 
 * \param[in] arg input PTBL_State
 * \return ATtrue if the PTBL_State had a number, or ATfalse otherwise
 */
ATbool PTBL_hasStateNumber(PTBL_State arg) {
  if (PTBL_isStateDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_State has a gotos. 
 * \param[in] arg input PTBL_State
 * \return ATtrue if the PTBL_State had a gotos, or ATfalse otherwise
 */
ATbool PTBL_hasStateGotos(PTBL_State arg) {
  if (PTBL_isStateDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_State has a choices. 
 * \param[in] arg input PTBL_State
 * \return ATtrue if the PTBL_State had a choices, or ATfalse otherwise
 */
ATbool PTBL_hasStateChoices(PTBL_State arg) {
  if (PTBL_isStateDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the number int of a PTBL_State. Note that the precondition is that this PTBL_State actually has a number
 * \param[in] arg input PTBL_State
 * \return the number of #arg, if it exist or an undefined value if it does not
 */
int PTBL_getStateNumber(PTBL_State arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Get the gotos PTBL_Gotos of a PTBL_State. Note that the precondition is that this PTBL_State actually has a gotos
 * \param[in] arg input PTBL_State
 * \return the gotos of #arg, if it exist or an undefined value if it does not
 */
PTBL_Gotos PTBL_getStateGotos(PTBL_State arg) {
  
    return (PTBL_Gotos)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Get the choices PTBL_Choices of a PTBL_State. Note that the precondition is that this PTBL_State actually has a choices
 * \param[in] arg input PTBL_State
 * \return the choices of #arg, if it exist or an undefined value if it does not
 */
PTBL_Choices PTBL_getStateChoices(PTBL_State arg) {
  
    return (PTBL_Choices)ATgetArgument((ATermAppl)arg, 2);
}

/**
 * Set the number of a PTBL_State. The precondition being that this PTBL_State actually has a number
 * \param[in] arg input PTBL_State
 * \param[in] number new int to set in #arg
 * \return A new PTBL_State with number at the right place, or a core dump if #arg did not have a number
 */
PTBL_State PTBL_setStateNumber(PTBL_State arg, int number) {
  if (PTBL_isStateDefault(arg)) {
    return (PTBL_State)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(number)), 0);
  }

  ATabort("State has no Number: %t\n", arg);
  return (PTBL_State)NULL;
}

/**
 * Set the gotos of a PTBL_State. The precondition being that this PTBL_State actually has a gotos
 * \param[in] arg input PTBL_State
 * \param[in] gotos new PTBL_Gotos to set in #arg
 * \return A new PTBL_State with gotos at the right place, or a core dump if #arg did not have a gotos
 */
PTBL_State PTBL_setStateGotos(PTBL_State arg, PTBL_Gotos gotos) {
  if (PTBL_isStateDefault(arg)) {
    return (PTBL_State)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) gotos), 1);
  }

  ATabort("State has no Gotos: %t\n", arg);
  return (PTBL_State)NULL;
}

/**
 * Set the choices of a PTBL_State. The precondition being that this PTBL_State actually has a choices
 * \param[in] arg input PTBL_State
 * \param[in] choices new PTBL_Choices to set in #arg
 * \return A new PTBL_State with choices at the right place, or a core dump if #arg did not have a choices
 */
PTBL_State PTBL_setStateChoices(PTBL_State arg, PTBL_Choices choices) {
  if (PTBL_isStateDefault(arg)) {
    return (PTBL_State)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) choices), 2);
  }

  ATabort("State has no Choices: %t\n", arg);
  return (PTBL_State)NULL;
}

/**
 * Assert whether a PTBL_Gotos is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_Gotos
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a PTBL_Gotos is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the PTBL_Gotos
 * \param[in] arg input PTBL_Gotos
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool PTBL_isGotosEmpty(PTBL_Gotos arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Gotos is a single by checking against the following ATerm pattern: [<head(Goto)>]. May not be used to assert correctness of the PTBL_Gotos
 * \param[in] arg input PTBL_Gotos
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool PTBL_isGotosSingle(PTBL_Gotos arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Gotos is a many by checking against the following ATerm pattern: [<head(Goto)>,<[tail(Gotos)]>]. May not be used to assert correctness of the PTBL_Gotos
 * \param[in] arg input PTBL_Gotos
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool PTBL_isGotosMany(PTBL_Gotos arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Gotos has a head. 
 * \param[in] arg input PTBL_Gotos
 * \return ATtrue if the PTBL_Gotos had a head, or ATfalse otherwise
 */
ATbool PTBL_hasGotosHead(PTBL_Gotos arg) {
  if (PTBL_isGotosSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isGotosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Gotos has a tail. 
 * \param[in] arg input PTBL_Gotos
 * \return ATtrue if the PTBL_Gotos had a tail, or ATfalse otherwise
 */
ATbool PTBL_hasGotosTail(PTBL_Gotos arg) {
  if (PTBL_isGotosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head PTBL_Goto of a PTBL_Gotos. Note that the precondition is that this PTBL_Gotos actually has a head
 * \param[in] arg input PTBL_Gotos
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
PTBL_Goto PTBL_getGotosHead(PTBL_Gotos arg) {
  if (PTBL_isGotosSingle(arg)) {
    return (PTBL_Goto)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_Goto)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail PTBL_Gotos of a PTBL_Gotos. Note that the precondition is that this PTBL_Gotos actually has a tail
 * \param[in] arg input PTBL_Gotos
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
PTBL_Gotos PTBL_getGotosTail(PTBL_Gotos arg) {
  
    return (PTBL_Gotos)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a PTBL_Gotos. The precondition being that this PTBL_Gotos actually has a head
 * \param[in] arg input PTBL_Gotos
 * \param[in] head new PTBL_Goto to set in #arg
 * \return A new PTBL_Gotos with head at the right place, or a core dump if #arg did not have a head
 */
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

/**
 * Set the tail of a PTBL_Gotos. The precondition being that this PTBL_Gotos actually has a tail
 * \param[in] arg input PTBL_Gotos
 * \param[in] tail new PTBL_Gotos to set in #arg
 * \return A new PTBL_Gotos with tail at the right place, or a core dump if #arg did not have a tail
 */
PTBL_Gotos PTBL_setGotosTail(PTBL_Gotos arg, PTBL_Gotos tail) {
  if (PTBL_isGotosMany(arg)) {
    return (PTBL_Gotos)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Gotos has no Tail: %t\n", arg);
  return (PTBL_Gotos)NULL;
}

/**
 * Assert whether a PTBL_Goto is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_Goto
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PTBL_isValidGoto(PTBL_Goto arg) {
  if (PTBL_isGotoDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Goto is a Default by checking against the following ATerm pattern: goto(<ranges(CharRanges)>,<state-number(int)>). Always returns ATtrue
 * \param[in] arg input PTBL_Goto
 * \return ATtrue if #arg corresponds to the signature of a Default, or ATfalse otherwise
 */
inline ATbool PTBL_isGotoDefault(PTBL_Goto arg){
  /* checking for: goto */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == PTBL_afun5) {
    ATerm arg_arg1 = ATgetArgument(arg, 1);
    if (ATgetType((ATerm)arg_arg1) == AT_INT) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Goto has a ranges. 
 * \param[in] arg input PTBL_Goto
 * \return ATtrue if the PTBL_Goto had a ranges, or ATfalse otherwise
 */
ATbool PTBL_hasGotoRanges(PTBL_Goto arg) {
  if (PTBL_isGotoDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Goto has a state-number. 
 * \param[in] arg input PTBL_Goto
 * \return ATtrue if the PTBL_Goto had a state-number, or ATfalse otherwise
 */
ATbool PTBL_hasGotoStateNumber(PTBL_Goto arg) {
  if (PTBL_isGotoDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ranges PTBL_CharRanges of a PTBL_Goto. Note that the precondition is that this PTBL_Goto actually has a ranges
 * \param[in] arg input PTBL_Goto
 * \return the ranges of #arg, if it exist or an undefined value if it does not
 */
PTBL_CharRanges PTBL_getGotoRanges(PTBL_Goto arg) {
  
    return (PTBL_CharRanges)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the state-number int of a PTBL_Goto. Note that the precondition is that this PTBL_Goto actually has a state-number
 * \param[in] arg input PTBL_Goto
 * \return the state-number of #arg, if it exist or an undefined value if it does not
 */
int PTBL_getGotoStateNumber(PTBL_Goto arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the ranges of a PTBL_Goto. The precondition being that this PTBL_Goto actually has a ranges
 * \param[in] arg input PTBL_Goto
 * \param[in] ranges new PTBL_CharRanges to set in #arg
 * \return A new PTBL_Goto with ranges at the right place, or a core dump if #arg did not have a ranges
 */
PTBL_Goto PTBL_setGotoRanges(PTBL_Goto arg, PTBL_CharRanges ranges) {
  if (PTBL_isGotoDefault(arg)) {
    return (PTBL_Goto)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) ranges), 0);
  }

  ATabort("Goto has no Ranges: %t\n", arg);
  return (PTBL_Goto)NULL;
}

/**
 * Set the state-number of a PTBL_Goto. The precondition being that this PTBL_Goto actually has a state-number
 * \param[in] arg input PTBL_Goto
 * \param[in] stateNumber new int to set in #arg
 * \return A new PTBL_Goto with stateNumber at the right place, or a core dump if #arg did not have a stateNumber
 */
PTBL_Goto PTBL_setGotoStateNumber(PTBL_Goto arg, int stateNumber) {
  if (PTBL_isGotoDefault(arg)) {
    return (PTBL_Goto)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(stateNumber)), 1);
  }

  ATabort("Goto has no StateNumber: %t\n", arg);
  return (PTBL_Goto)NULL;
}

/**
 * Assert whether a PTBL_Choices is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_Choices
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a PTBL_Choices is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the PTBL_Choices
 * \param[in] arg input PTBL_Choices
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool PTBL_isChoicesEmpty(PTBL_Choices arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Choices is a single by checking against the following ATerm pattern: [<head(Choice)>]. May not be used to assert correctness of the PTBL_Choices
 * \param[in] arg input PTBL_Choices
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool PTBL_isChoicesSingle(PTBL_Choices arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Choices is a many by checking against the following ATerm pattern: [<head(Choice)>,<[tail(Choices)]>]. May not be used to assert correctness of the PTBL_Choices
 * \param[in] arg input PTBL_Choices
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool PTBL_isChoicesMany(PTBL_Choices arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Choices has a head. 
 * \param[in] arg input PTBL_Choices
 * \return ATtrue if the PTBL_Choices had a head, or ATfalse otherwise
 */
ATbool PTBL_hasChoicesHead(PTBL_Choices arg) {
  if (PTBL_isChoicesSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isChoicesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Choices has a tail. 
 * \param[in] arg input PTBL_Choices
 * \return ATtrue if the PTBL_Choices had a tail, or ATfalse otherwise
 */
ATbool PTBL_hasChoicesTail(PTBL_Choices arg) {
  if (PTBL_isChoicesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head PTBL_Choice of a PTBL_Choices. Note that the precondition is that this PTBL_Choices actually has a head
 * \param[in] arg input PTBL_Choices
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
PTBL_Choice PTBL_getChoicesHead(PTBL_Choices arg) {
  if (PTBL_isChoicesSingle(arg)) {
    return (PTBL_Choice)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_Choice)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail PTBL_Choices of a PTBL_Choices. Note that the precondition is that this PTBL_Choices actually has a tail
 * \param[in] arg input PTBL_Choices
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
PTBL_Choices PTBL_getChoicesTail(PTBL_Choices arg) {
  
    return (PTBL_Choices)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a PTBL_Choices. The precondition being that this PTBL_Choices actually has a head
 * \param[in] arg input PTBL_Choices
 * \param[in] head new PTBL_Choice to set in #arg
 * \return A new PTBL_Choices with head at the right place, or a core dump if #arg did not have a head
 */
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

/**
 * Set the tail of a PTBL_Choices. The precondition being that this PTBL_Choices actually has a tail
 * \param[in] arg input PTBL_Choices
 * \param[in] tail new PTBL_Choices to set in #arg
 * \return A new PTBL_Choices with tail at the right place, or a core dump if #arg did not have a tail
 */
PTBL_Choices PTBL_setChoicesTail(PTBL_Choices arg, PTBL_Choices tail) {
  if (PTBL_isChoicesMany(arg)) {
    return (PTBL_Choices)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Choices has no Tail: %t\n", arg);
  return (PTBL_Choices)NULL;
}

/**
 * Assert whether a PTBL_Choice is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_Choice
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PTBL_isValidChoice(PTBL_Choice arg) {
  if (PTBL_isChoiceDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Choice is a Default by checking against the following ATerm pattern: action(<ranges(CharRanges)>,<actions(Actions)>). Always returns ATtrue
 * \param[in] arg input PTBL_Choice
 * \return ATtrue if #arg corresponds to the signature of a Default, or ATfalse otherwise
 */
inline ATbool PTBL_isChoiceDefault(PTBL_Choice arg){
  /* checking for: action */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == PTBL_afun6) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Choice has a ranges. 
 * \param[in] arg input PTBL_Choice
 * \return ATtrue if the PTBL_Choice had a ranges, or ATfalse otherwise
 */
ATbool PTBL_hasChoiceRanges(PTBL_Choice arg) {
  if (PTBL_isChoiceDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Choice has a actions. 
 * \param[in] arg input PTBL_Choice
 * \return ATtrue if the PTBL_Choice had a actions, or ATfalse otherwise
 */
ATbool PTBL_hasChoiceActions(PTBL_Choice arg) {
  if (PTBL_isChoiceDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ranges PTBL_CharRanges of a PTBL_Choice. Note that the precondition is that this PTBL_Choice actually has a ranges
 * \param[in] arg input PTBL_Choice
 * \return the ranges of #arg, if it exist or an undefined value if it does not
 */
PTBL_CharRanges PTBL_getChoiceRanges(PTBL_Choice arg) {
  
    return (PTBL_CharRanges)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the actions PTBL_Actions of a PTBL_Choice. Note that the precondition is that this PTBL_Choice actually has a actions
 * \param[in] arg input PTBL_Choice
 * \return the actions of #arg, if it exist or an undefined value if it does not
 */
PTBL_Actions PTBL_getChoiceActions(PTBL_Choice arg) {
  
    return (PTBL_Actions)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Set the ranges of a PTBL_Choice. The precondition being that this PTBL_Choice actually has a ranges
 * \param[in] arg input PTBL_Choice
 * \param[in] ranges new PTBL_CharRanges to set in #arg
 * \return A new PTBL_Choice with ranges at the right place, or a core dump if #arg did not have a ranges
 */
PTBL_Choice PTBL_setChoiceRanges(PTBL_Choice arg, PTBL_CharRanges ranges) {
  if (PTBL_isChoiceDefault(arg)) {
    return (PTBL_Choice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) ranges), 0);
  }

  ATabort("Choice has no Ranges: %t\n", arg);
  return (PTBL_Choice)NULL;
}

/**
 * Set the actions of a PTBL_Choice. The precondition being that this PTBL_Choice actually has a actions
 * \param[in] arg input PTBL_Choice
 * \param[in] actions new PTBL_Actions to set in #arg
 * \return A new PTBL_Choice with actions at the right place, or a core dump if #arg did not have a actions
 */
PTBL_Choice PTBL_setChoiceActions(PTBL_Choice arg, PTBL_Actions actions) {
  if (PTBL_isChoiceDefault(arg)) {
    return (PTBL_Choice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) actions), 1);
  }

  ATabort("Choice has no Actions: %t\n", arg);
  return (PTBL_Choice)NULL;
}

/**
 * Assert whether a PTBL_Actions is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_Actions
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a PTBL_Actions is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the PTBL_Actions
 * \param[in] arg input PTBL_Actions
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool PTBL_isActionsEmpty(PTBL_Actions arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Actions is a single by checking against the following ATerm pattern: [<head(Action)>]. May not be used to assert correctness of the PTBL_Actions
 * \param[in] arg input PTBL_Actions
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool PTBL_isActionsSingle(PTBL_Actions arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Actions is a many by checking against the following ATerm pattern: [<head(Action)>,<[tail(Actions)]>]. May not be used to assert correctness of the PTBL_Actions
 * \param[in] arg input PTBL_Actions
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool PTBL_isActionsMany(PTBL_Actions arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Actions has a head. 
 * \param[in] arg input PTBL_Actions
 * \return ATtrue if the PTBL_Actions had a head, or ATfalse otherwise
 */
ATbool PTBL_hasActionsHead(PTBL_Actions arg) {
  if (PTBL_isActionsSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isActionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Actions has a tail. 
 * \param[in] arg input PTBL_Actions
 * \return ATtrue if the PTBL_Actions had a tail, or ATfalse otherwise
 */
ATbool PTBL_hasActionsTail(PTBL_Actions arg) {
  if (PTBL_isActionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head PTBL_Action of a PTBL_Actions. Note that the precondition is that this PTBL_Actions actually has a head
 * \param[in] arg input PTBL_Actions
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
PTBL_Action PTBL_getActionsHead(PTBL_Actions arg) {
  if (PTBL_isActionsSingle(arg)) {
    return (PTBL_Action)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_Action)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail PTBL_Actions of a PTBL_Actions. Note that the precondition is that this PTBL_Actions actually has a tail
 * \param[in] arg input PTBL_Actions
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
PTBL_Actions PTBL_getActionsTail(PTBL_Actions arg) {
  
    return (PTBL_Actions)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a PTBL_Actions. The precondition being that this PTBL_Actions actually has a head
 * \param[in] arg input PTBL_Actions
 * \param[in] head new PTBL_Action to set in #arg
 * \return A new PTBL_Actions with head at the right place, or a core dump if #arg did not have a head
 */
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

/**
 * Set the tail of a PTBL_Actions. The precondition being that this PTBL_Actions actually has a tail
 * \param[in] arg input PTBL_Actions
 * \param[in] tail new PTBL_Actions to set in #arg
 * \return A new PTBL_Actions with tail at the right place, or a core dump if #arg did not have a tail
 */
PTBL_Actions PTBL_setActionsTail(PTBL_Actions arg, PTBL_Actions tail) {
  if (PTBL_isActionsMany(arg)) {
    return (PTBL_Actions)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Actions has no Tail: %t\n", arg);
  return (PTBL_Actions)NULL;
}

/**
 * Assert whether a PTBL_Action is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_Action
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PTBL_isValidAction(PTBL_Action arg) {
  if (PTBL_isActionReduce(arg)) {
    return ATtrue;
  }
  else if (PTBL_isActionLookaheadReduce(arg)) {
    return ATtrue;
  }
  else if (PTBL_isActionShift(arg)) {
    return ATtrue;
  }
  else if (PTBL_isActionAccept(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Action is a reduce by checking against the following ATerm pattern: reduce(<length(int)>,<label(int)>,<special-attr(SpecialAttr)>). May not be used to assert correctness of the PTBL_Action
 * \param[in] arg input PTBL_Action
 * \return ATtrue if #arg corresponds to the signature of a reduce, or ATfalse otherwise
 */
inline ATbool PTBL_isActionReduce(PTBL_Action arg){
  /* checking for: reduce */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == PTBL_afun7) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_INT) {
      ATerm arg_arg1 = ATgetArgument(arg, 1);
      if (ATgetType((ATerm)arg_arg1) == AT_INT) {
        return ATtrue;
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Action is a lookahead-reduce by checking against the following ATerm pattern: reduce(<length(int)>,<label(int)>,<special-attr(SpecialAttr)>,<restrictions(Restrictions)>). May not be used to assert correctness of the PTBL_Action
 * \param[in] arg input PTBL_Action
 * \return ATtrue if #arg corresponds to the signature of a lookahead-reduce, or ATfalse otherwise
 */
inline ATbool PTBL_isActionLookaheadReduce(PTBL_Action arg){
  /* checking for: reduce */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == PTBL_afun8) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_INT) {
      ATerm arg_arg1 = ATgetArgument(arg, 1);
      if (ATgetType((ATerm)arg_arg1) == AT_INT) {
        return ATtrue;
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Action is a shift by checking against the following ATerm pattern: shift(<state-number(int)>). May not be used to assert correctness of the PTBL_Action
 * \param[in] arg input PTBL_Action
 * \return ATtrue if #arg corresponds to the signature of a shift, or ATfalse otherwise
 */
inline ATbool PTBL_isActionShift(PTBL_Action arg){
  /* checking for: shift */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == PTBL_afun9) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_INT) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Action is a accept by checking against the following ATerm pattern: accept. May not be used to assert correctness of the PTBL_Action
 * \param[in] arg input PTBL_Action
 * \return ATtrue if #arg corresponds to the signature of a accept, or ATfalse otherwise
 */
inline ATbool PTBL_isActionAccept(PTBL_Action arg){
  /* checking for: accept */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == PTBL_afun10) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Action has a length. 
 * \param[in] arg input PTBL_Action
 * \return ATtrue if the PTBL_Action had a length, or ATfalse otherwise
 */
ATbool PTBL_hasActionLength(PTBL_Action arg) {
  if (PTBL_isActionReduce(arg)) {
    return ATtrue;
  }
  else if (PTBL_isActionLookaheadReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Action has a label. 
 * \param[in] arg input PTBL_Action
 * \return ATtrue if the PTBL_Action had a label, or ATfalse otherwise
 */
ATbool PTBL_hasActionLabel(PTBL_Action arg) {
  if (PTBL_isActionReduce(arg)) {
    return ATtrue;
  }
  else if (PTBL_isActionLookaheadReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Action has a special-attr. 
 * \param[in] arg input PTBL_Action
 * \return ATtrue if the PTBL_Action had a special-attr, or ATfalse otherwise
 */
ATbool PTBL_hasActionSpecialAttr(PTBL_Action arg) {
  if (PTBL_isActionReduce(arg)) {
    return ATtrue;
  }
  else if (PTBL_isActionLookaheadReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Action has a restrictions. 
 * \param[in] arg input PTBL_Action
 * \return ATtrue if the PTBL_Action had a restrictions, or ATfalse otherwise
 */
ATbool PTBL_hasActionRestrictions(PTBL_Action arg) {
  if (PTBL_isActionLookaheadReduce(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Action has a state-number. 
 * \param[in] arg input PTBL_Action
 * \return ATtrue if the PTBL_Action had a state-number, or ATfalse otherwise
 */
ATbool PTBL_hasActionStateNumber(PTBL_Action arg) {
  if (PTBL_isActionShift(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the length int of a PTBL_Action. Note that the precondition is that this PTBL_Action actually has a length
 * \param[in] arg input PTBL_Action
 * \return the length of #arg, if it exist or an undefined value if it does not
 */
int PTBL_getActionLength(PTBL_Action arg) {
  if (PTBL_isActionReduce(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Get the label int of a PTBL_Action. Note that the precondition is that this PTBL_Action actually has a label
 * \param[in] arg input PTBL_Action
 * \return the label of #arg, if it exist or an undefined value if it does not
 */
int PTBL_getActionLabel(PTBL_Action arg) {
  if (PTBL_isActionReduce(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the special-attr PTBL_SpecialAttr of a PTBL_Action. Note that the precondition is that this PTBL_Action actually has a special-attr
 * \param[in] arg input PTBL_Action
 * \return the special-attr of #arg, if it exist or an undefined value if it does not
 */
PTBL_SpecialAttr PTBL_getActionSpecialAttr(PTBL_Action arg) {
  if (PTBL_isActionReduce(arg)) {
    return (PTBL_SpecialAttr)ATgetArgument((ATermAppl)arg, 2);
  }
  else 
    return (PTBL_SpecialAttr)ATgetArgument((ATermAppl)arg, 2);
}

/**
 * Get the restrictions PTBL_Restrictions of a PTBL_Action. Note that the precondition is that this PTBL_Action actually has a restrictions
 * \param[in] arg input PTBL_Action
 * \return the restrictions of #arg, if it exist or an undefined value if it does not
 */
PTBL_Restrictions PTBL_getActionRestrictions(PTBL_Action arg) {
  
    return (PTBL_Restrictions)ATgetArgument((ATermAppl)arg, 3);
}

/**
 * Get the state-number int of a PTBL_Action. Note that the precondition is that this PTBL_Action actually has a state-number
 * \param[in] arg input PTBL_Action
 * \return the state-number of #arg, if it exist or an undefined value if it does not
 */
int PTBL_getActionStateNumber(PTBL_Action arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Set the length of a PTBL_Action. The precondition being that this PTBL_Action actually has a length
 * \param[in] arg input PTBL_Action
 * \param[in] length new int to set in #arg
 * \return A new PTBL_Action with length at the right place, or a core dump if #arg did not have a length
 */
PTBL_Action PTBL_setActionLength(PTBL_Action arg, int length) {
  if (PTBL_isActionReduce(arg)) {
    return (PTBL_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(length)), 0);
  }
  else if (PTBL_isActionLookaheadReduce(arg)) {
    return (PTBL_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(length)), 0);
  }

  ATabort("Action has no Length: %t\n", arg);
  return (PTBL_Action)NULL;
}

/**
 * Set the label of a PTBL_Action. The precondition being that this PTBL_Action actually has a label
 * \param[in] arg input PTBL_Action
 * \param[in] label new int to set in #arg
 * \return A new PTBL_Action with label at the right place, or a core dump if #arg did not have a label
 */
PTBL_Action PTBL_setActionLabel(PTBL_Action arg, int label) {
  if (PTBL_isActionReduce(arg)) {
    return (PTBL_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(label)), 1);
  }
  else if (PTBL_isActionLookaheadReduce(arg)) {
    return (PTBL_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(label)), 1);
  }

  ATabort("Action has no Label: %t\n", arg);
  return (PTBL_Action)NULL;
}

/**
 * Set the special-attr of a PTBL_Action. The precondition being that this PTBL_Action actually has a special-attr
 * \param[in] arg input PTBL_Action
 * \param[in] specialAttr new PTBL_SpecialAttr to set in #arg
 * \return A new PTBL_Action with specialAttr at the right place, or a core dump if #arg did not have a specialAttr
 */
PTBL_Action PTBL_setActionSpecialAttr(PTBL_Action arg, PTBL_SpecialAttr specialAttr) {
  if (PTBL_isActionReduce(arg)) {
    return (PTBL_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) specialAttr), 2);
  }
  else if (PTBL_isActionLookaheadReduce(arg)) {
    return (PTBL_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) specialAttr), 2);
  }

  ATabort("Action has no SpecialAttr: %t\n", arg);
  return (PTBL_Action)NULL;
}

/**
 * Set the restrictions of a PTBL_Action. The precondition being that this PTBL_Action actually has a restrictions
 * \param[in] arg input PTBL_Action
 * \param[in] restrictions new PTBL_Restrictions to set in #arg
 * \return A new PTBL_Action with restrictions at the right place, or a core dump if #arg did not have a restrictions
 */
PTBL_Action PTBL_setActionRestrictions(PTBL_Action arg, PTBL_Restrictions restrictions) {
  if (PTBL_isActionLookaheadReduce(arg)) {
    return (PTBL_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) restrictions), 3);
  }

  ATabort("Action has no Restrictions: %t\n", arg);
  return (PTBL_Action)NULL;
}

/**
 * Set the state-number of a PTBL_Action. The precondition being that this PTBL_Action actually has a state-number
 * \param[in] arg input PTBL_Action
 * \param[in] stateNumber new int to set in #arg
 * \return A new PTBL_Action with stateNumber at the right place, or a core dump if #arg did not have a stateNumber
 */
PTBL_Action PTBL_setActionStateNumber(PTBL_Action arg, int stateNumber) {
  if (PTBL_isActionShift(arg)) {
    return (PTBL_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(stateNumber)), 0);
  }

  ATabort("Action has no StateNumber: %t\n", arg);
  return (PTBL_Action)NULL;
}

/**
 * Assert whether a PTBL_SpecialAttr is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_SpecialAttr
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a PTBL_SpecialAttr is a none by checking against the following ATerm pattern: 0. May not be used to assert correctness of the PTBL_SpecialAttr
 * \param[in] arg input PTBL_SpecialAttr
 * \return ATtrue if #arg corresponds to the signature of a none, or ATfalse otherwise
 */
inline ATbool PTBL_isSpecialAttrNone(PTBL_SpecialAttr arg){
  if (ATgetInt((ATermInt)arg) == 0) {

    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_SpecialAttr is a reject by checking against the following ATerm pattern: 1. May not be used to assert correctness of the PTBL_SpecialAttr
 * \param[in] arg input PTBL_SpecialAttr
 * \return ATtrue if #arg corresponds to the signature of a reject, or ATfalse otherwise
 */
inline ATbool PTBL_isSpecialAttrReject(PTBL_SpecialAttr arg){
  if (ATgetInt((ATermInt)arg) == 1) {

    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_SpecialAttr is a prefer by checking against the following ATerm pattern: 2. May not be used to assert correctness of the PTBL_SpecialAttr
 * \param[in] arg input PTBL_SpecialAttr
 * \return ATtrue if #arg corresponds to the signature of a prefer, or ATfalse otherwise
 */
inline ATbool PTBL_isSpecialAttrPrefer(PTBL_SpecialAttr arg){
  if (ATgetInt((ATermInt)arg) == 2) {

    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_SpecialAttr is a avoid by checking against the following ATerm pattern: 4. May not be used to assert correctness of the PTBL_SpecialAttr
 * \param[in] arg input PTBL_SpecialAttr
 * \return ATtrue if #arg corresponds to the signature of a avoid, or ATfalse otherwise
 */
inline ATbool PTBL_isSpecialAttrAvoid(PTBL_SpecialAttr arg){
  if (ATgetInt((ATermInt)arg) == 4) {

    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Restrictions is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_Restrictions
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PTBL_isValidRestrictions(PTBL_Restrictions arg) {
  if (PTBL_isRestrictionsEmpty(arg)) {
    return ATtrue;
  }
  else if (PTBL_isRestrictionsSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isRestrictionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Restrictions is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the PTBL_Restrictions
 * \param[in] arg input PTBL_Restrictions
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool PTBL_isRestrictionsEmpty(PTBL_Restrictions arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Restrictions is a single by checking against the following ATerm pattern: [<head(Restriction)>]. May not be used to assert correctness of the PTBL_Restrictions
 * \param[in] arg input PTBL_Restrictions
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool PTBL_isRestrictionsSingle(PTBL_Restrictions arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Restrictions is a many by checking against the following ATerm pattern: [<head(Restriction)>,<[tail(Restrictions)]>]. May not be used to assert correctness of the PTBL_Restrictions
 * \param[in] arg input PTBL_Restrictions
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool PTBL_isRestrictionsMany(PTBL_Restrictions arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Restrictions has a head. 
 * \param[in] arg input PTBL_Restrictions
 * \return ATtrue if the PTBL_Restrictions had a head, or ATfalse otherwise
 */
ATbool PTBL_hasRestrictionsHead(PTBL_Restrictions arg) {
  if (PTBL_isRestrictionsSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isRestrictionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Restrictions has a tail. 
 * \param[in] arg input PTBL_Restrictions
 * \return ATtrue if the PTBL_Restrictions had a tail, or ATfalse otherwise
 */
ATbool PTBL_hasRestrictionsTail(PTBL_Restrictions arg) {
  if (PTBL_isRestrictionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head PTBL_Restriction of a PTBL_Restrictions. Note that the precondition is that this PTBL_Restrictions actually has a head
 * \param[in] arg input PTBL_Restrictions
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
PTBL_Restriction PTBL_getRestrictionsHead(PTBL_Restrictions arg) {
  if (PTBL_isRestrictionsSingle(arg)) {
    return (PTBL_Restriction)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_Restriction)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail PTBL_Restrictions of a PTBL_Restrictions. Note that the precondition is that this PTBL_Restrictions actually has a tail
 * \param[in] arg input PTBL_Restrictions
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
PTBL_Restrictions PTBL_getRestrictionsTail(PTBL_Restrictions arg) {
  
    return (PTBL_Restrictions)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a PTBL_Restrictions. The precondition being that this PTBL_Restrictions actually has a head
 * \param[in] arg input PTBL_Restrictions
 * \param[in] head new PTBL_Restriction to set in #arg
 * \return A new PTBL_Restrictions with head at the right place, or a core dump if #arg did not have a head
 */
PTBL_Restrictions PTBL_setRestrictionsHead(PTBL_Restrictions arg, PTBL_Restriction head) {
  if (PTBL_isRestrictionsSingle(arg)) {
    return (PTBL_Restrictions)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTBL_isRestrictionsMany(arg)) {
    return (PTBL_Restrictions)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Restrictions has no Head: %t\n", arg);
  return (PTBL_Restrictions)NULL;
}

/**
 * Set the tail of a PTBL_Restrictions. The precondition being that this PTBL_Restrictions actually has a tail
 * \param[in] arg input PTBL_Restrictions
 * \param[in] tail new PTBL_Restrictions to set in #arg
 * \return A new PTBL_Restrictions with tail at the right place, or a core dump if #arg did not have a tail
 */
PTBL_Restrictions PTBL_setRestrictionsTail(PTBL_Restrictions arg, PTBL_Restrictions tail) {
  if (PTBL_isRestrictionsMany(arg)) {
    return (PTBL_Restrictions)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Restrictions has no Tail: %t\n", arg);
  return (PTBL_Restrictions)NULL;
}

/**
 * Assert whether a PTBL_Restriction is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_Restriction
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PTBL_isValidRestriction(PTBL_Restriction arg) {
  if (PTBL_isRestrictionFollow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Restriction is a follow by checking against the following ATerm pattern: follow-restriction(<char-classes(CharClasses)>). Always returns ATtrue
 * \param[in] arg input PTBL_Restriction
 * \return ATtrue if #arg corresponds to the signature of a follow, or ATfalse otherwise
 */
inline ATbool PTBL_isRestrictionFollow(PTBL_Restriction arg){
  /* checking for: follow-restriction */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == PTBL_afun11) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Restriction has a char-classes. 
 * \param[in] arg input PTBL_Restriction
 * \return ATtrue if the PTBL_Restriction had a char-classes, or ATfalse otherwise
 */
ATbool PTBL_hasRestrictionCharClasses(PTBL_Restriction arg) {
  if (PTBL_isRestrictionFollow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the char-classes PTBL_CharClasses of a PTBL_Restriction. Note that the precondition is that this PTBL_Restriction actually has a char-classes
 * \param[in] arg input PTBL_Restriction
 * \return the char-classes of #arg, if it exist or an undefined value if it does not
 */
PTBL_CharClasses PTBL_getRestrictionCharClasses(PTBL_Restriction arg) {
  
    return (PTBL_CharClasses)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Set the char-classes of a PTBL_Restriction. The precondition being that this PTBL_Restriction actually has a char-classes
 * \param[in] arg input PTBL_Restriction
 * \param[in] charClasses new PTBL_CharClasses to set in #arg
 * \return A new PTBL_Restriction with charClasses at the right place, or a core dump if #arg did not have a charClasses
 */
PTBL_Restriction PTBL_setRestrictionCharClasses(PTBL_Restriction arg, PTBL_CharClasses charClasses) {
  if (PTBL_isRestrictionFollow(arg)) {
    return (PTBL_Restriction)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) charClasses), 0);
  }

  ATabort("Restriction has no CharClasses: %t\n", arg);
  return (PTBL_Restriction)NULL;
}

/**
 * Assert whether a PTBL_CharClasses is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_CharClasses
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PTBL_isValidCharClasses(PTBL_CharClasses arg) {
  if (PTBL_isCharClassesEmpty(arg)) {
    return ATtrue;
  }
  else if (PTBL_isCharClassesSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isCharClassesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_CharClasses is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the PTBL_CharClasses
 * \param[in] arg input PTBL_CharClasses
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool PTBL_isCharClassesEmpty(PTBL_CharClasses arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_CharClasses is a single by checking against the following ATerm pattern: [<head(CharClass)>]. May not be used to assert correctness of the PTBL_CharClasses
 * \param[in] arg input PTBL_CharClasses
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool PTBL_isCharClassesSingle(PTBL_CharClasses arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_CharClasses is a many by checking against the following ATerm pattern: [<head(CharClass)>,<[tail(CharClasses)]>]. May not be used to assert correctness of the PTBL_CharClasses
 * \param[in] arg input PTBL_CharClasses
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool PTBL_isCharClassesMany(PTBL_CharClasses arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_CharClasses has a head. 
 * \param[in] arg input PTBL_CharClasses
 * \return ATtrue if the PTBL_CharClasses had a head, or ATfalse otherwise
 */
ATbool PTBL_hasCharClassesHead(PTBL_CharClasses arg) {
  if (PTBL_isCharClassesSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isCharClassesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_CharClasses has a tail. 
 * \param[in] arg input PTBL_CharClasses
 * \return ATtrue if the PTBL_CharClasses had a tail, or ATfalse otherwise
 */
ATbool PTBL_hasCharClassesTail(PTBL_CharClasses arg) {
  if (PTBL_isCharClassesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head PTBL_CharClass of a PTBL_CharClasses. Note that the precondition is that this PTBL_CharClasses actually has a head
 * \param[in] arg input PTBL_CharClasses
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
PTBL_CharClass PTBL_getCharClassesHead(PTBL_CharClasses arg) {
  if (PTBL_isCharClassesSingle(arg)) {
    return (PTBL_CharClass)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_CharClass)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail PTBL_CharClasses of a PTBL_CharClasses. Note that the precondition is that this PTBL_CharClasses actually has a tail
 * \param[in] arg input PTBL_CharClasses
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
PTBL_CharClasses PTBL_getCharClassesTail(PTBL_CharClasses arg) {
  
    return (PTBL_CharClasses)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a PTBL_CharClasses. The precondition being that this PTBL_CharClasses actually has a head
 * \param[in] arg input PTBL_CharClasses
 * \param[in] head new PTBL_CharClass to set in #arg
 * \return A new PTBL_CharClasses with head at the right place, or a core dump if #arg did not have a head
 */
PTBL_CharClasses PTBL_setCharClassesHead(PTBL_CharClasses arg, PTBL_CharClass head) {
  if (PTBL_isCharClassesSingle(arg)) {
    return (PTBL_CharClasses)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTBL_isCharClassesMany(arg)) {
    return (PTBL_CharClasses)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("CharClasses has no Head: %t\n", arg);
  return (PTBL_CharClasses)NULL;
}

/**
 * Set the tail of a PTBL_CharClasses. The precondition being that this PTBL_CharClasses actually has a tail
 * \param[in] arg input PTBL_CharClasses
 * \param[in] tail new PTBL_CharClasses to set in #arg
 * \return A new PTBL_CharClasses with tail at the right place, or a core dump if #arg did not have a tail
 */
PTBL_CharClasses PTBL_setCharClassesTail(PTBL_CharClasses arg, PTBL_CharClasses tail) {
  if (PTBL_isCharClassesMany(arg)) {
    return (PTBL_CharClasses)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("CharClasses has no Tail: %t\n", arg);
  return (PTBL_CharClasses)NULL;
}

/**
 * Assert whether a PTBL_Priorities is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_Priorities
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a PTBL_Priorities is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the PTBL_Priorities
 * \param[in] arg input PTBL_Priorities
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool PTBL_isPrioritiesEmpty(PTBL_Priorities arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Priorities is a single by checking against the following ATerm pattern: [<head(Priority)>]. May not be used to assert correctness of the PTBL_Priorities
 * \param[in] arg input PTBL_Priorities
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool PTBL_isPrioritiesSingle(PTBL_Priorities arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Priorities is a many by checking against the following ATerm pattern: [<head(Priority)>,<[tail(Priorities)]>]. May not be used to assert correctness of the PTBL_Priorities
 * \param[in] arg input PTBL_Priorities
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool PTBL_isPrioritiesMany(PTBL_Priorities arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Priorities has a head. 
 * \param[in] arg input PTBL_Priorities
 * \return ATtrue if the PTBL_Priorities had a head, or ATfalse otherwise
 */
ATbool PTBL_hasPrioritiesHead(PTBL_Priorities arg) {
  if (PTBL_isPrioritiesSingle(arg)) {
    return ATtrue;
  }
  else if (PTBL_isPrioritiesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Priorities has a tail. 
 * \param[in] arg input PTBL_Priorities
 * \return ATtrue if the PTBL_Priorities had a tail, or ATfalse otherwise
 */
ATbool PTBL_hasPrioritiesTail(PTBL_Priorities arg) {
  if (PTBL_isPrioritiesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head PTBL_Priority of a PTBL_Priorities. Note that the precondition is that this PTBL_Priorities actually has a head
 * \param[in] arg input PTBL_Priorities
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
PTBL_Priority PTBL_getPrioritiesHead(PTBL_Priorities arg) {
  if (PTBL_isPrioritiesSingle(arg)) {
    return (PTBL_Priority)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTBL_Priority)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail PTBL_Priorities of a PTBL_Priorities. Note that the precondition is that this PTBL_Priorities actually has a tail
 * \param[in] arg input PTBL_Priorities
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
PTBL_Priorities PTBL_getPrioritiesTail(PTBL_Priorities arg) {
  
    return (PTBL_Priorities)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a PTBL_Priorities. The precondition being that this PTBL_Priorities actually has a head
 * \param[in] arg input PTBL_Priorities
 * \param[in] head new PTBL_Priority to set in #arg
 * \return A new PTBL_Priorities with head at the right place, or a core dump if #arg did not have a head
 */
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

/**
 * Set the tail of a PTBL_Priorities. The precondition being that this PTBL_Priorities actually has a tail
 * \param[in] arg input PTBL_Priorities
 * \param[in] tail new PTBL_Priorities to set in #arg
 * \return A new PTBL_Priorities with tail at the right place, or a core dump if #arg did not have a tail
 */
PTBL_Priorities PTBL_setPrioritiesTail(PTBL_Priorities arg, PTBL_Priorities tail) {
  if (PTBL_isPrioritiesMany(arg)) {
    return (PTBL_Priorities)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Priorities has no Tail: %t\n", arg);
  return (PTBL_Priorities)NULL;
}

/**
 * Assert whether a PTBL_Priority is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input PTBL_Priority
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool PTBL_isValidPriority(PTBL_Priority arg) {
  if (PTBL_isPriorityGreater(arg)) {
    return ATtrue;
  }
  else if (PTBL_isPriorityArgGreater(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Priority is a greater by checking against the following ATerm pattern: gtr-prio(<label1(int)>,<label2(int)>). May not be used to assert correctness of the PTBL_Priority
 * \param[in] arg input PTBL_Priority
 * \return ATtrue if #arg corresponds to the signature of a greater, or ATfalse otherwise
 */
inline ATbool PTBL_isPriorityGreater(PTBL_Priority arg){
  /* checking for: gtr-prio */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == PTBL_afun12) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_INT) {
      ATerm arg_arg1 = ATgetArgument(arg, 1);
      if (ATgetType((ATerm)arg_arg1) == AT_INT) {
        return ATtrue;
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Priority is a arg-greater by checking against the following ATerm pattern: arg-gtr-prio(<label1(int)>,<argument-number(int)>,<label2(int)>). May not be used to assert correctness of the PTBL_Priority
 * \param[in] arg input PTBL_Priority
 * \return ATtrue if #arg corresponds to the signature of a arg-greater, or ATfalse otherwise
 */
inline ATbool PTBL_isPriorityArgGreater(PTBL_Priority arg){
  /* checking for: arg-gtr-prio */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == PTBL_afun13) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_INT) {
      ATerm arg_arg1 = ATgetArgument(arg, 1);
      if (ATgetType((ATerm)arg_arg1) == AT_INT) {
        ATerm arg_arg2 = ATgetArgument(arg, 2);
        if (ATgetType((ATerm)arg_arg2) == AT_INT) {
          return ATtrue;
        }
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Priority has a label1. 
 * \param[in] arg input PTBL_Priority
 * \return ATtrue if the PTBL_Priority had a label1, or ATfalse otherwise
 */
ATbool PTBL_hasPriorityLabel1(PTBL_Priority arg) {
  if (PTBL_isPriorityGreater(arg)) {
    return ATtrue;
  }
  else if (PTBL_isPriorityArgGreater(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Priority has a label2. 
 * \param[in] arg input PTBL_Priority
 * \return ATtrue if the PTBL_Priority had a label2, or ATfalse otherwise
 */
ATbool PTBL_hasPriorityLabel2(PTBL_Priority arg) {
  if (PTBL_isPriorityGreater(arg)) {
    return ATtrue;
  }
  else if (PTBL_isPriorityArgGreater(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a PTBL_Priority has a argument-number. 
 * \param[in] arg input PTBL_Priority
 * \return ATtrue if the PTBL_Priority had a argument-number, or ATfalse otherwise
 */
ATbool PTBL_hasPriorityArgumentNumber(PTBL_Priority arg) {
  if (PTBL_isPriorityArgGreater(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the label1 int of a PTBL_Priority. Note that the precondition is that this PTBL_Priority actually has a label1
 * \param[in] arg input PTBL_Priority
 * \return the label1 of #arg, if it exist or an undefined value if it does not
 */
int PTBL_getPriorityLabel1(PTBL_Priority arg) {
  if (PTBL_isPriorityGreater(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Get the label2 int of a PTBL_Priority. Note that the precondition is that this PTBL_Priority actually has a label2
 * \param[in] arg input PTBL_Priority
 * \return the label2 of #arg, if it exist or an undefined value if it does not
 */
int PTBL_getPriorityLabel2(PTBL_Priority arg) {
  if (PTBL_isPriorityGreater(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/**
 * Get the argument-number int of a PTBL_Priority. Note that the precondition is that this PTBL_Priority actually has a argument-number
 * \param[in] arg input PTBL_Priority
 * \return the argument-number of #arg, if it exist or an undefined value if it does not
 */
int PTBL_getPriorityArgumentNumber(PTBL_Priority arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the label1 of a PTBL_Priority. The precondition being that this PTBL_Priority actually has a label1
 * \param[in] arg input PTBL_Priority
 * \param[in] label1 new int to set in #arg
 * \return A new PTBL_Priority with label1 at the right place, or a core dump if #arg did not have a label1
 */
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

/**
 * Set the label2 of a PTBL_Priority. The precondition being that this PTBL_Priority actually has a label2
 * \param[in] arg input PTBL_Priority
 * \param[in] label2 new int to set in #arg
 * \return A new PTBL_Priority with label2 at the right place, or a core dump if #arg did not have a label2
 */
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

/**
 * Set the argument-number of a PTBL_Priority. The precondition being that this PTBL_Priority actually has a argument-number
 * \param[in] arg input PTBL_Priority
 * \param[in] argumentNumber new int to set in #arg
 * \return A new PTBL_Priority with argumentNumber at the right place, or a core dump if #arg did not have a argumentNumber
 */
PTBL_Priority PTBL_setPriorityArgumentNumber(PTBL_Priority arg, int argumentNumber) {
  if (PTBL_isPriorityArgGreater(arg)) {
    return (PTBL_Priority)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(argumentNumber)), 1);
  }

  ATabort("Priority has no ArgumentNumber: %t\n", arg);
  return (PTBL_Priority)NULL;
}

/**
 * Apply functions to the children of a PTBL_Production. 
 * \return A new PTBL_Production with new children where the argument functions might have applied
 */
PTBL_Production PTBL_visitProduction(PTBL_Production arg, ATerm (*acceptProd)(ATerm)) {
  if (PTBL_isProductionExternal(arg)) {
    return PTBL_makeProductionExternal(
        acceptProd ? acceptProd(PTBL_getProductionProd(arg)) : PTBL_getProductionProd(arg));
  }
  ATabort("not a Production: %t\n", arg);
  return (PTBL_Production)NULL;
}
/**
 * Apply functions to the children of a PTBL_CharClass. 
 * \return A new PTBL_CharClass with new children where the argument functions might have applied
 */
PTBL_CharClass PTBL_visitCharClass(PTBL_CharClass arg, ATerm (*acceptCharClass)(ATerm)) {
  if (PTBL_isCharClassExternal(arg)) {
    return PTBL_makeCharClassExternal(
        acceptCharClass ? acceptCharClass(PTBL_getCharClassCharClass(arg)) : PTBL_getCharClassCharClass(arg));
  }
  ATabort("not a CharClass: %t\n", arg);
  return (PTBL_CharClass)NULL;
}
/**
 * Apply functions to the children of a PTBL_CharRanges. 
 * \return A new PTBL_CharRanges with new children where the argument functions might have applied
 */
PTBL_CharRanges PTBL_visitCharRanges(PTBL_CharRanges arg, ATerm (*acceptRanges)(ATerm)) {
  if (PTBL_isCharRangesExternal(arg)) {
    return PTBL_makeCharRangesExternal(
        acceptRanges ? acceptRanges(PTBL_getCharRangesRanges(arg)) : PTBL_getCharRangesRanges(arg));
  }
  ATabort("not a CharRanges: %t\n", arg);
  return (PTBL_CharRanges)NULL;
}
/**
 * Apply functions to the children of a PTBL_Version. 
 * \return A new PTBL_Version with new children where the argument functions might have applied
 */
PTBL_Version PTBL_visitVersion(PTBL_Version arg) {
  if (PTBL_isVersionDefault(arg)) {
    return PTBL_makeVersionDefault();
  }
  ATabort("not a Version: %t\n", arg);
  return (PTBL_Version)NULL;
}
/**
 * Apply functions to the children of a PTBL_ParseTable. 
 * \return A new PTBL_ParseTable with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a PTBL_Labels. 
 * \return A new PTBL_Labels with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a PTBL_Label. 
 * \return A new PTBL_Label with new children where the argument functions might have applied
 */
PTBL_Label PTBL_visitLabel(PTBL_Label arg, PTBL_Production (*acceptProduction)(PTBL_Production), int (*acceptNumber)(int)) {
  if (PTBL_isLabelDefault(arg)) {
    return PTBL_makeLabelDefault(
        acceptProduction ? acceptProduction(PTBL_getLabelProduction(arg)) : PTBL_getLabelProduction(arg),
        acceptNumber ? acceptNumber(PTBL_getLabelNumber(arg)) : PTBL_getLabelNumber(arg));
  }
  ATabort("not a Label: %t\n", arg);
  return (PTBL_Label)NULL;
}
/**
 * Apply functions to the children of a PTBL_States. 
 * \return A new PTBL_States with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a PTBL_State. 
 * \return A new PTBL_State with new children where the argument functions might have applied
 */
PTBL_State PTBL_visitState(PTBL_State arg, int (*acceptNumber)(int), PTBL_Gotos (*acceptGotos)(PTBL_Gotos), PTBL_Choices (*acceptChoices)(PTBL_Choices)) {
  if (PTBL_isStateDefault(arg)) {
    return PTBL_makeStateDefault(
        acceptNumber ? acceptNumber(PTBL_getStateNumber(arg)) : PTBL_getStateNumber(arg),
        acceptGotos ? acceptGotos(PTBL_getStateGotos(arg)) : PTBL_getStateGotos(arg),
        acceptChoices ? acceptChoices(PTBL_getStateChoices(arg)) : PTBL_getStateChoices(arg));
  }
  ATabort("not a State: %t\n", arg);
  return (PTBL_State)NULL;
}
/**
 * Apply functions to the children of a PTBL_Gotos. 
 * \return A new PTBL_Gotos with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a PTBL_Goto. 
 * \return A new PTBL_Goto with new children where the argument functions might have applied
 */
PTBL_Goto PTBL_visitGoto(PTBL_Goto arg, PTBL_CharRanges (*acceptRanges)(PTBL_CharRanges), int (*acceptStateNumber)(int)) {
  if (PTBL_isGotoDefault(arg)) {
    return PTBL_makeGotoDefault(
        acceptRanges ? acceptRanges(PTBL_getGotoRanges(arg)) : PTBL_getGotoRanges(arg),
        acceptStateNumber ? acceptStateNumber(PTBL_getGotoStateNumber(arg)) : PTBL_getGotoStateNumber(arg));
  }
  ATabort("not a Goto: %t\n", arg);
  return (PTBL_Goto)NULL;
}
/**
 * Apply functions to the children of a PTBL_Choices. 
 * \return A new PTBL_Choices with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a PTBL_Choice. 
 * \return A new PTBL_Choice with new children where the argument functions might have applied
 */
PTBL_Choice PTBL_visitChoice(PTBL_Choice arg, PTBL_CharRanges (*acceptRanges)(PTBL_CharRanges), PTBL_Actions (*acceptActions)(PTBL_Actions)) {
  if (PTBL_isChoiceDefault(arg)) {
    return PTBL_makeChoiceDefault(
        acceptRanges ? acceptRanges(PTBL_getChoiceRanges(arg)) : PTBL_getChoiceRanges(arg),
        acceptActions ? acceptActions(PTBL_getChoiceActions(arg)) : PTBL_getChoiceActions(arg));
  }
  ATabort("not a Choice: %t\n", arg);
  return (PTBL_Choice)NULL;
}
/**
 * Apply functions to the children of a PTBL_Actions. 
 * \return A new PTBL_Actions with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a PTBL_Action. 
 * \return A new PTBL_Action with new children where the argument functions might have applied
 */
PTBL_Action PTBL_visitAction(PTBL_Action arg, int (*acceptLength)(int), int (*acceptLabel)(int), PTBL_SpecialAttr (*acceptSpecialAttr)(PTBL_SpecialAttr), PTBL_Restrictions (*acceptRestrictions)(PTBL_Restrictions), int (*acceptStateNumber)(int)) {
  if (PTBL_isActionReduce(arg)) {
    return PTBL_makeActionReduce(
        acceptLength ? acceptLength(PTBL_getActionLength(arg)) : PTBL_getActionLength(arg),
        acceptLabel ? acceptLabel(PTBL_getActionLabel(arg)) : PTBL_getActionLabel(arg),
        acceptSpecialAttr ? acceptSpecialAttr(PTBL_getActionSpecialAttr(arg)) : PTBL_getActionSpecialAttr(arg));
  }
  if (PTBL_isActionLookaheadReduce(arg)) {
    return PTBL_makeActionLookaheadReduce(
        acceptLength ? acceptLength(PTBL_getActionLength(arg)) : PTBL_getActionLength(arg),
        acceptLabel ? acceptLabel(PTBL_getActionLabel(arg)) : PTBL_getActionLabel(arg),
        acceptSpecialAttr ? acceptSpecialAttr(PTBL_getActionSpecialAttr(arg)) : PTBL_getActionSpecialAttr(arg),
        acceptRestrictions ? acceptRestrictions(PTBL_getActionRestrictions(arg)) : PTBL_getActionRestrictions(arg));
  }
  if (PTBL_isActionShift(arg)) {
    return PTBL_makeActionShift(
        acceptStateNumber ? acceptStateNumber(PTBL_getActionStateNumber(arg)) : PTBL_getActionStateNumber(arg));
  }
  if (PTBL_isActionAccept(arg)) {
    return PTBL_makeActionAccept();
  }
  ATabort("not a Action: %t\n", arg);
  return (PTBL_Action)NULL;
}
/**
 * Apply functions to the children of a PTBL_SpecialAttr. 
 * \return A new PTBL_SpecialAttr with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a PTBL_Restrictions. 
 * \return A new PTBL_Restrictions with new children where the argument functions might have applied
 */
PTBL_Restrictions PTBL_visitRestrictions(PTBL_Restrictions arg, PTBL_Restriction (*acceptHead)(PTBL_Restriction)) {
  if (PTBL_isRestrictionsEmpty(arg)) {
    return PTBL_makeRestrictionsEmpty();
  }
  if (PTBL_isRestrictionsSingle(arg)) {
    return PTBL_makeRestrictionsSingle(
        acceptHead ? acceptHead(PTBL_getRestrictionsHead(arg)) : PTBL_getRestrictionsHead(arg));
  }
  if (PTBL_isRestrictionsMany(arg)) {
    return PTBL_makeRestrictionsMany(
        acceptHead ? acceptHead(PTBL_getRestrictionsHead(arg)) : PTBL_getRestrictionsHead(arg),
        PTBL_visitRestrictions(PTBL_getRestrictionsTail(arg), acceptHead));
  }
  ATabort("not a Restrictions: %t\n", arg);
  return (PTBL_Restrictions)NULL;
}
/**
 * Apply functions to the children of a PTBL_Restriction. 
 * \return A new PTBL_Restriction with new children where the argument functions might have applied
 */
PTBL_Restriction PTBL_visitRestriction(PTBL_Restriction arg, PTBL_CharClasses (*acceptCharClasses)(PTBL_CharClasses)) {
  if (PTBL_isRestrictionFollow(arg)) {
    return PTBL_makeRestrictionFollow(
        acceptCharClasses ? acceptCharClasses(PTBL_getRestrictionCharClasses(arg)) : PTBL_getRestrictionCharClasses(arg));
  }
  ATabort("not a Restriction: %t\n", arg);
  return (PTBL_Restriction)NULL;
}
/**
 * Apply functions to the children of a PTBL_CharClasses. 
 * \return A new PTBL_CharClasses with new children where the argument functions might have applied
 */
PTBL_CharClasses PTBL_visitCharClasses(PTBL_CharClasses arg, PTBL_CharClass (*acceptHead)(PTBL_CharClass)) {
  if (PTBL_isCharClassesEmpty(arg)) {
    return PTBL_makeCharClassesEmpty();
  }
  if (PTBL_isCharClassesSingle(arg)) {
    return PTBL_makeCharClassesSingle(
        acceptHead ? acceptHead(PTBL_getCharClassesHead(arg)) : PTBL_getCharClassesHead(arg));
  }
  if (PTBL_isCharClassesMany(arg)) {
    return PTBL_makeCharClassesMany(
        acceptHead ? acceptHead(PTBL_getCharClassesHead(arg)) : PTBL_getCharClassesHead(arg),
        PTBL_visitCharClasses(PTBL_getCharClassesTail(arg), acceptHead));
  }
  ATabort("not a CharClasses: %t\n", arg);
  return (PTBL_CharClasses)NULL;
}
/**
 * Apply functions to the children of a PTBL_Priorities. 
 * \return A new PTBL_Priorities with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a PTBL_Priority. 
 * \return A new PTBL_Priority with new children where the argument functions might have applied
 */
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

