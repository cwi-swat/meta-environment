#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "EditorManager.h"

/**
 * Converts a string to an ATermList of integers (ASCII values). 
 * \param[in] str An ASCII string
 * \return An ATermList containing the ASCII values of #arg as ATermInts
 */
ATerm EM_stringToChars(const char *str) {
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
ATerm EM_byteToChar(char ch) {
    return (ATerm) ATmakeInt(ch);
}

/**
 * Converts a list of integers (ASCII values) to a C string. 
 * \param[in] arg An ATermList with ATermInts, such as [32,32,10]
 * \return String containing the characters from #arg as characters
 */
char *EM_charsToString(ATerm arg) {
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

char EM_charToByte(ATerm arg) {
    return (char) ATgetInt((ATermInt) arg);
}


typedef struct ATerm _EM_Sid;
typedef struct ATerm _EM_EditorType;
typedef struct ATerm _EM_ModuleId;
typedef struct ATerm _EM_SessionStatus;
typedef struct ATerm _EM_Session;
typedef struct ATerm _EM_EditorTypeList;


/**
 * Initializes the full API. Forgetting to call this function before using the API will lead to strange behaviour. ATinit() needs to be called before this function.
 */
void _EM_initEditorManagerApi(void) {
  init_EditorManager_dict();

}

/**
 * Protect a EM_Sid from the ATerm garbage collector. Every EM_Sid that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a EM_Sid
 */
void _EM_protectSid(EM_Sid *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a EM_Sid from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a EM_Sid
 */
void _EM_unprotectSid(EM_Sid *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a EM_EditorType from the ATerm garbage collector. Every EM_EditorType that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a EM_EditorType
 */
void _EM_protectEditorType(EM_EditorType *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a EM_EditorType from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a EM_EditorType
 */
void _EM_unprotectEditorType(EM_EditorType *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a EM_ModuleId from the ATerm garbage collector. Every EM_ModuleId that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a EM_ModuleId
 */
void _EM_protectModuleId(EM_ModuleId *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a EM_ModuleId from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a EM_ModuleId
 */
void _EM_unprotectModuleId(EM_ModuleId *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a EM_SessionStatus from the ATerm garbage collector. Every EM_SessionStatus that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a EM_SessionStatus
 */
void _EM_protectSessionStatus(EM_SessionStatus *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a EM_SessionStatus from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a EM_SessionStatus
 */
void _EM_unprotectSessionStatus(EM_SessionStatus *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a EM_Session from the ATerm garbage collector. Every EM_Session that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a EM_Session
 */
void _EM_protectSession(EM_Session *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a EM_Session from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a EM_Session
 */
void _EM_unprotectSession(EM_Session *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a EM_EditorTypeList from the ATerm garbage collector. Every EM_EditorTypeList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a EM_EditorTypeList
 */
void _EM_protectEditorTypeList(EM_EditorTypeList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a EM_EditorTypeList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a EM_EditorTypeList
 */
void _EM_unprotectEditorTypeList(EM_EditorTypeList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Transforms an ATerm to a EM_Sid. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return EM_Sid that was encoded by \arg
 */
EM_Sid _EM_SidFromTerm(ATerm t) {
  return (EM_Sid)t;
}

/**
 * Transforms a EM_Sidto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg EM_Sid to be converted
 * \return ATerm that represents the EM_Sid
 */
ATerm _EM_SidToTerm(EM_Sid arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a EM_EditorType. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return EM_EditorType that was encoded by \arg
 */
EM_EditorType _EM_EditorTypeFromTerm(ATerm t) {
  return (EM_EditorType)t;
}

/**
 * Transforms a EM_EditorTypeto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg EM_EditorType to be converted
 * \return ATerm that represents the EM_EditorType
 */
ATerm _EM_EditorTypeToTerm(EM_EditorType arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a EM_ModuleId. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return EM_ModuleId that was encoded by \arg
 */
EM_ModuleId _EM_ModuleIdFromTerm(ATerm t) {
  return (EM_ModuleId)t;
}

/**
 * Transforms a EM_ModuleIdto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg EM_ModuleId to be converted
 * \return ATerm that represents the EM_ModuleId
 */
ATerm _EM_ModuleIdToTerm(EM_ModuleId arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a EM_SessionStatus. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return EM_SessionStatus that was encoded by \arg
 */
EM_SessionStatus _EM_SessionStatusFromTerm(ATerm t) {
  return (EM_SessionStatus)t;
}

/**
 * Transforms a EM_SessionStatusto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg EM_SessionStatus to be converted
 * \return ATerm that represents the EM_SessionStatus
 */
ATerm _EM_SessionStatusToTerm(EM_SessionStatus arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a EM_Session. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return EM_Session that was encoded by \arg
 */
EM_Session _EM_SessionFromTerm(ATerm t) {
  return (EM_Session)t;
}

/**
 * Transforms a EM_Sessionto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg EM_Session to be converted
 * \return ATerm that represents the EM_Session
 */
ATerm _EM_SessionToTerm(EM_Session arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a EM_EditorTypeList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return EM_EditorTypeList that was encoded by \arg
 */
EM_EditorTypeList _EM_EditorTypeListFromTerm(ATerm t) {
  return (EM_EditorTypeList)t;
}

/**
 * Transforms a EM_EditorTypeListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg EM_EditorTypeList to be converted
 * \return ATerm that represents the EM_EditorTypeList
 */
ATerm _EM_EditorTypeListToTerm(EM_EditorTypeList arg) {
  return (ATerm)arg;
}

/**
 * Retrieve the length of a EM_EditorTypeList. 
 * \param[in] arg input EM_EditorTypeList
 * \return The number of elements in the EM_EditorTypeList
 */
int _EM_getEditorTypeListLength(EM_EditorTypeList arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a EM_EditorTypeList. 
 * \param[in] arg EM_EditorTypeList to be reversed
 * \return a reversed #arg
 */
EM_EditorTypeList _EM_reverseEditorTypeList(EM_EditorTypeList arg) {
  return (EM_EditorTypeList) ATreverse((ATermList) arg);
}

/**
 * Append a EM_EditorType to the end of a EM_EditorTypeList. 
 * \param[in] arg EM_EditorTypeList to append the EM_EditorType to
 * \param[in] elem EM_EditorType to be appended
 * \return new EM_EditorTypeList with #elem appended
 */
EM_EditorTypeList _EM_appendEditorTypeList(EM_EditorTypeList arg, EM_EditorType elem) {
  return (EM_EditorTypeList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two EM_EditorTypeLists. 
 * \param[in] arg0 first EM_EditorTypeList
 * \param[in] arg1 second EM_EditorTypeList
 * \return EM_EditorTypeList with the elements of #arg0 before the elements of #arg1
 */
EM_EditorTypeList _EM_concatEditorTypeList(EM_EditorTypeList arg0, EM_EditorTypeList arg1) {
  return (EM_EditorTypeList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a EM_EditorTypeList. 
 * \param[in] arg EM_EditorTypeList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new EM_EditorTypeList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
EM_EditorTypeList _EM_sliceEditorTypeList(EM_EditorTypeList arg, int start, int end) {
  return (EM_EditorTypeList) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the EM_EditorType at #index from a EM_EditorTypeList. 
 * \param[in] arg EM_EditorTypeList to retrieve the EM_EditorType from
 * \param[in] index index to use to point in the EM_EditorTypeList
 * \return EM_EditorType at position #index in #arg
 */
EM_EditorType _EM_getEditorTypeListEditorTypeAt(EM_EditorTypeList arg, int index) {
 return (EM_EditorType)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the EM_EditorType at #index from a EM_EditorTypeList by a new one. 
 * \param[in] arg EM_EditorTypeList to retrieve the EM_EditorType from
 * \param[in] elem new EM_EditorType to replace another
 * \param[in] index index to use to point in the EM_EditorTypeList
 * \return A new EM_EditorTypeListwith #elem replaced in #arg at position #index
 */
EM_EditorTypeList _EM_replaceEditorTypeListEditorTypeAt(EM_EditorTypeList arg, EM_EditorType elem, int index) {
 return (EM_EditorTypeList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a EM_EditorTypeList of 2 consecutive elements. 
 * \param[in] elem1 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem2 One EM_EditorType element of the new EM_EditorTypeList
 * \return A new EM_EditorTypeList consisting of 2 EM_EditorTypes
 */
EM_EditorTypeList _EM_makeEditorTypeList2(EM_EditorType elem1, EM_EditorType elem2) {
  return (EM_EditorTypeList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a EM_EditorTypeList of 3 consecutive elements. 
 * \param[in] elem1 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem2 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem3 One EM_EditorType element of the new EM_EditorTypeList
 * \return A new EM_EditorTypeList consisting of 3 EM_EditorTypes
 */
EM_EditorTypeList _EM_makeEditorTypeList3(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3) {
  return (EM_EditorTypeList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a EM_EditorTypeList of 4 consecutive elements. 
 * \param[in] elem1 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem2 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem3 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem4 One EM_EditorType element of the new EM_EditorTypeList
 * \return A new EM_EditorTypeList consisting of 4 EM_EditorTypes
 */
EM_EditorTypeList _EM_makeEditorTypeList4(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3, EM_EditorType elem4) {
  return (EM_EditorTypeList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a EM_EditorTypeList of 5 consecutive elements. 
 * \param[in] elem1 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem2 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem3 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem4 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem5 One EM_EditorType element of the new EM_EditorTypeList
 * \return A new EM_EditorTypeList consisting of 5 EM_EditorTypes
 */
EM_EditorTypeList _EM_makeEditorTypeList5(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3, EM_EditorType elem4, EM_EditorType elem5) {
  return (EM_EditorTypeList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a EM_EditorTypeList of 6 consecutive elements. 
 * \param[in] elem1 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem2 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem3 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem4 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem5 One EM_EditorType element of the new EM_EditorTypeList
 * \param[in] elem6 One EM_EditorType element of the new EM_EditorTypeList
 * \return A new EM_EditorTypeList consisting of 6 EM_EditorTypes
 */
EM_EditorTypeList _EM_makeEditorTypeList6(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3, EM_EditorType elem4, EM_EditorType elem5, EM_EditorType elem6) {
  return (EM_EditorTypeList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Constructs a session-id of type EM_Sid. Like all ATerm types, EM_Sids are maximally shared.
 * \param[in] id a child of the new session-id
 * \return A pointer to a session-id, either newly constructed or shared
 */
EM_Sid EM_makeSidSessionId(int id) {
  return (EM_Sid)(ATerm)ATmakeAppl1(EM_afun0, (ATerm) (ATerm) ATmakeInt(id));
}
/**
 * Constructs a Default of type EM_EditorType. Like all ATerm types, EM_EditorTypes are maximally shared.
 * \param[in] name a child of the new Default
 * \return A pointer to a Default, either newly constructed or shared
 */
EM_EditorType EM_makeEditorTypeDefault(const char* name) {
  return (EM_EditorType)(ATerm)ATmakeAppl1(EM_afun1, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}
/**
 * Constructs a module-id of type EM_ModuleId. Like all ATerm types, EM_ModuleIds are maximally shared.
 * \param[in] id a child of the new module-id
 * \return A pointer to a module-id, either newly constructed or shared
 */
EM_ModuleId EM_makeModuleIdModuleId(int id) {
  return (EM_ModuleId)(ATerm)ATmakeAppl1(EM_afun2, (ATerm) (ATerm) ATmakeInt(id));
}
/**
 * Constructs a running of type EM_SessionStatus. Like all ATerm types, EM_SessionStatuss are maximally shared.
 * \return A pointer to a running, either newly constructed or shared
 */
EM_SessionStatus EM_makeSessionStatusRunning(void) {
  return (EM_SessionStatus)(ATerm)ATmakeAppl0(EM_afun3);
}
/**
 * Constructs a zombie of type EM_SessionStatus. Like all ATerm types, EM_SessionStatuss are maximally shared.
 * \return A pointer to a zombie, either newly constructed or shared
 */
EM_SessionStatus EM_makeSessionStatusZombie(void) {
  return (EM_SessionStatus)(ATerm)ATmakeAppl0(EM_afun4);
}
/**
 * Constructs a Default of type EM_Session. Like all ATerm types, EM_Sessions are maximally shared.
 * \param[in] id a child of the new Default
 * \param[in] path a child of the new Default
 * \param[in] status a child of the new Default
 * \param[in] referenceCount a child of the new Default
 * \param[in] list a child of the new Default
 * \return A pointer to a Default, either newly constructed or shared
 */
EM_Session EM_makeSessionDefault(EM_Sid id, const char* path, EM_SessionStatus status, int referenceCount, EM_EditorTypeList list) {
  return (EM_Session)(ATerm)ATmakeAppl5(EM_afun5, (ATerm) id, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)), (ATerm) status, (ATerm) (ATerm) ATmakeInt(referenceCount), (ATerm) list);
}
/**
 * Constructs a empty of type EM_EditorTypeList. Like all ATerm types, EM_EditorTypeLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
EM_EditorTypeList EM_makeEditorTypeListEmpty(void) {
  return (EM_EditorTypeList)(ATerm)ATempty;
}
/**
 * Constructs a single of type EM_EditorTypeList. Like all ATerm types, EM_EditorTypeLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
EM_EditorTypeList EM_makeEditorTypeListSingle(EM_EditorType head) {
  return (EM_EditorTypeList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type EM_EditorTypeList. Like all ATerm types, EM_EditorTypeLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
EM_EditorTypeList EM_makeEditorTypeListMany(EM_EditorType head, EM_EditorTypeList tail) {
  return (EM_EditorTypeList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/**
 * Tests equality of two EM_Sids. A constant time operation.
 * \param[in] arg0 first EM_Sid to be compared
 * \param[in] arg1 second EM_Sid to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _EM_isEqualSid(EM_Sid arg0, EM_Sid arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two EM_EditorTypes. A constant time operation.
 * \param[in] arg0 first EM_EditorType to be compared
 * \param[in] arg1 second EM_EditorType to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _EM_isEqualEditorType(EM_EditorType arg0, EM_EditorType arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two EM_ModuleIds. A constant time operation.
 * \param[in] arg0 first EM_ModuleId to be compared
 * \param[in] arg1 second EM_ModuleId to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _EM_isEqualModuleId(EM_ModuleId arg0, EM_ModuleId arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two EM_SessionStatuss. A constant time operation.
 * \param[in] arg0 first EM_SessionStatus to be compared
 * \param[in] arg1 second EM_SessionStatus to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _EM_isEqualSessionStatus(EM_SessionStatus arg0, EM_SessionStatus arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two EM_Sessions. A constant time operation.
 * \param[in] arg0 first EM_Session to be compared
 * \param[in] arg1 second EM_Session to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _EM_isEqualSession(EM_Session arg0, EM_Session arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two EM_EditorTypeLists. A constant time operation.
 * \param[in] arg0 first EM_EditorTypeList to be compared
 * \param[in] arg1 second EM_EditorTypeList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _EM_isEqualEditorTypeList(EM_EditorTypeList arg0, EM_EditorTypeList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Assert whether a EM_Sid is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input EM_Sid
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool EM_isValidSid(EM_Sid arg) {
  if (EM_isSidSessionId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_Sid is a session-id by checking against the following ATerm pattern: session-id(<"id"(int)>). Always returns ATtrue
 * \param[in] arg input EM_Sid
 * \return ATtrue if #arg corresponds to the signature of a session-id, or ATfalse otherwise
 */
inline ATbool EM_isSidSessionId(EM_Sid arg){
  /* checking for: session-id */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == EM_afun0) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_INT) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a EM_Sid has a id. 
 * \param[in] arg input EM_Sid
 * \return ATtrue if the EM_Sid had a id, or ATfalse otherwise
 */
ATbool EM_hasSidId(EM_Sid arg) {
  if (EM_isSidSessionId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the id int of a EM_Sid. Note that the precondition is that this EM_Sid actually has a id
 * \param[in] arg input EM_Sid
 * \return the id of #arg, if it exist or an undefined value if it does not
 */
int EM_getSidId(EM_Sid arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Set the id of a EM_Sid. The precondition being that this EM_Sid actually has a id
 * \param[in] arg input EM_Sid
 * \param[in] id new int to set in #arg
 * \return A new EM_Sid with id at the right place, or a core dump if #arg did not have a id
 */
EM_Sid EM_setSidId(EM_Sid arg, int id) {
  if (EM_isSidSessionId(arg)) {
    return (EM_Sid)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(id)), 0);
  }

  ATabort("Sid has no Id: %t\n", arg);
  return (EM_Sid)NULL;
}

/**
 * Assert whether a EM_EditorType is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input EM_EditorType
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool EM_isValidEditorType(EM_EditorType arg) {
  if (EM_isEditorTypeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_EditorType is a Default by checking against the following ATerm pattern: Default(<"name"(str)>). Always returns ATtrue
 * \param[in] arg input EM_EditorType
 * \return ATtrue if #arg corresponds to the signature of a Default, or ATfalse otherwise
 */
inline ATbool EM_isEditorTypeDefault(EM_EditorType arg){
  /* checking for: Default */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == EM_afun1) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a EM_EditorType has a name. 
 * \param[in] arg input EM_EditorType
 * \return ATtrue if the EM_EditorType had a name, or ATfalse otherwise
 */
ATbool EM_hasEditorTypeName(EM_EditorType arg) {
  if (EM_isEditorTypeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the name char* of a EM_EditorType. Note that the precondition is that this EM_EditorType actually has a name
 * \param[in] arg input EM_EditorType
 * \return the name of #arg, if it exist or an undefined value if it does not
 */
char* EM_getEditorTypeName(EM_EditorType arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Set the name of a EM_EditorType. The precondition being that this EM_EditorType actually has a name
 * \param[in] arg input EM_EditorType
 * \param[in] name new const char* to set in #arg
 * \return A new EM_EditorType with name at the right place, or a core dump if #arg did not have a name
 */
EM_EditorType EM_setEditorTypeName(EM_EditorType arg, const char* name) {
  if (EM_isEditorTypeDefault(arg)) {
    return (EM_EditorType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("EditorType has no Name: %t\n", arg);
  return (EM_EditorType)NULL;
}

/**
 * Assert whether a EM_ModuleId is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input EM_ModuleId
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool EM_isValidModuleId(EM_ModuleId arg) {
  if (EM_isModuleIdModuleId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_ModuleId is a module-id by checking against the following ATerm pattern: module-id(<"id"(int)>). Always returns ATtrue
 * \param[in] arg input EM_ModuleId
 * \return ATtrue if #arg corresponds to the signature of a module-id, or ATfalse otherwise
 */
inline ATbool EM_isModuleIdModuleId(EM_ModuleId arg){
  /* checking for: module-id */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == EM_afun2) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_INT) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a EM_ModuleId has a id. 
 * \param[in] arg input EM_ModuleId
 * \return ATtrue if the EM_ModuleId had a id, or ATfalse otherwise
 */
ATbool EM_hasModuleIdId(EM_ModuleId arg) {
  if (EM_isModuleIdModuleId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the id int of a EM_ModuleId. Note that the precondition is that this EM_ModuleId actually has a id
 * \param[in] arg input EM_ModuleId
 * \return the id of #arg, if it exist or an undefined value if it does not
 */
int EM_getModuleIdId(EM_ModuleId arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Set the id of a EM_ModuleId. The precondition being that this EM_ModuleId actually has a id
 * \param[in] arg input EM_ModuleId
 * \param[in] id new int to set in #arg
 * \return A new EM_ModuleId with id at the right place, or a core dump if #arg did not have a id
 */
EM_ModuleId EM_setModuleIdId(EM_ModuleId arg, int id) {
  if (EM_isModuleIdModuleId(arg)) {
    return (EM_ModuleId)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(id)), 0);
  }

  ATabort("ModuleId has no Id: %t\n", arg);
  return (EM_ModuleId)NULL;
}

/**
 * Assert whether a EM_SessionStatus is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input EM_SessionStatus
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool EM_isValidSessionStatus(EM_SessionStatus arg) {
  if (EM_isSessionStatusRunning(arg)) {
    return ATtrue;
  }
  else if (EM_isSessionStatusZombie(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_SessionStatus is a running by checking against the following ATerm pattern: running. May not be used to assert correctness of the EM_SessionStatus
 * \param[in] arg input EM_SessionStatus
 * \return ATtrue if #arg corresponds to the signature of a running, or ATfalse otherwise
 */
inline ATbool EM_isSessionStatusRunning(EM_SessionStatus arg){
  /* checking for: running */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == EM_afun3) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_SessionStatus is a zombie by checking against the following ATerm pattern: zombie. May not be used to assert correctness of the EM_SessionStatus
 * \param[in] arg input EM_SessionStatus
 * \return ATtrue if #arg corresponds to the signature of a zombie, or ATfalse otherwise
 */
inline ATbool EM_isSessionStatusZombie(EM_SessionStatus arg){
  /* checking for: zombie */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == EM_afun4) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_Session is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input EM_Session
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool EM_isValidSession(EM_Session arg) {
  if (EM_isSessionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_Session is a Default by checking against the following ATerm pattern: Default(<"id"("Sid")>,<"path"(str)>,<"status"("SessionStatus")>,<"reference-count"(int)>,<"list"("EditorType-list")>). Always returns ATtrue
 * \param[in] arg input EM_Session
 * \return ATtrue if #arg corresponds to the signature of a Default, or ATfalse otherwise
 */
inline ATbool EM_isSessionDefault(EM_Session arg){
  /* checking for: Default */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == EM_afun5) {
    ATerm arg_arg1 = ATgetArgument(arg, 1);
    if (ATgetType((ATerm)arg_arg1) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg1)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg1)) == ATtrue) {
      ATerm arg_arg3 = ATgetArgument(arg, 3);
      if (ATgetType((ATerm)arg_arg3) == AT_INT) {
        return ATtrue;
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a EM_Session has a id. 
 * \param[in] arg input EM_Session
 * \return ATtrue if the EM_Session had a id, or ATfalse otherwise
 */
ATbool EM_hasSessionId(EM_Session arg) {
  if (EM_isSessionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_Session has a path. 
 * \param[in] arg input EM_Session
 * \return ATtrue if the EM_Session had a path, or ATfalse otherwise
 */
ATbool EM_hasSessionPath(EM_Session arg) {
  if (EM_isSessionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_Session has a status. 
 * \param[in] arg input EM_Session
 * \return ATtrue if the EM_Session had a status, or ATfalse otherwise
 */
ATbool EM_hasSessionStatus(EM_Session arg) {
  if (EM_isSessionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_Session has a reference-count. 
 * \param[in] arg input EM_Session
 * \return ATtrue if the EM_Session had a reference-count, or ATfalse otherwise
 */
ATbool EM_hasSessionReferenceCount(EM_Session arg) {
  if (EM_isSessionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_Session has a list. 
 * \param[in] arg input EM_Session
 * \return ATtrue if the EM_Session had a list, or ATfalse otherwise
 */
ATbool EM_hasSessionList(EM_Session arg) {
  if (EM_isSessionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the id EM_Sid of a EM_Session. Note that the precondition is that this EM_Session actually has a id
 * \param[in] arg input EM_Session
 * \return the id of #arg, if it exist or an undefined value if it does not
 */
EM_Sid EM_getSessionId(EM_Session arg) {
  
    return (EM_Sid)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the path char* of a EM_Session. Note that the precondition is that this EM_Session actually has a path
 * \param[in] arg input EM_Session
 * \return the path of #arg, if it exist or an undefined value if it does not
 */
char* EM_getSessionPath(EM_Session arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/**
 * Get the status EM_SessionStatus of a EM_Session. Note that the precondition is that this EM_Session actually has a status
 * \param[in] arg input EM_Session
 * \return the status of #arg, if it exist or an undefined value if it does not
 */
EM_SessionStatus EM_getSessionStatus(EM_Session arg) {
  
    return (EM_SessionStatus)ATgetArgument((ATermAppl)arg, 2);
}

/**
 * Get the reference-count int of a EM_Session. Note that the precondition is that this EM_Session actually has a reference-count
 * \param[in] arg input EM_Session
 * \return the reference-count of #arg, if it exist or an undefined value if it does not
 */
int EM_getSessionReferenceCount(EM_Session arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 3));
}

/**
 * Get the list EM_EditorTypeList of a EM_Session. Note that the precondition is that this EM_Session actually has a list
 * \param[in] arg input EM_Session
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
EM_EditorTypeList EM_getSessionList(EM_Session arg) {
  
    return (EM_EditorTypeList)ATgetArgument((ATermAppl)arg, 4);
}

/**
 * Set the id of a EM_Session. The precondition being that this EM_Session actually has a id
 * \param[in] arg input EM_Session
 * \param[in] id new EM_Sid to set in #arg
 * \return A new EM_Session with id at the right place, or a core dump if #arg did not have a id
 */
EM_Session EM_setSessionId(EM_Session arg, EM_Sid id) {
  if (EM_isSessionDefault(arg)) {
    return (EM_Session)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) id), 0);
  }

  ATabort("Session has no Id: %t\n", arg);
  return (EM_Session)NULL;
}

/**
 * Set the path of a EM_Session. The precondition being that this EM_Session actually has a path
 * \param[in] arg input EM_Session
 * \param[in] path new const char* to set in #arg
 * \return A new EM_Session with path at the right place, or a core dump if #arg did not have a path
 */
EM_Session EM_setSessionPath(EM_Session arg, const char* path) {
  if (EM_isSessionDefault(arg)) {
    return (EM_Session)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 1);
  }

  ATabort("Session has no Path: %t\n", arg);
  return (EM_Session)NULL;
}

/**
 * Set the status of a EM_Session. The precondition being that this EM_Session actually has a status
 * \param[in] arg input EM_Session
 * \param[in] status new EM_SessionStatus to set in #arg
 * \return A new EM_Session with status at the right place, or a core dump if #arg did not have a status
 */
EM_Session EM_setSessionStatus(EM_Session arg, EM_SessionStatus status) {
  if (EM_isSessionDefault(arg)) {
    return (EM_Session)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) status), 2);
  }

  ATabort("Session has no Status: %t\n", arg);
  return (EM_Session)NULL;
}

/**
 * Set the reference-count of a EM_Session. The precondition being that this EM_Session actually has a reference-count
 * \param[in] arg input EM_Session
 * \param[in] referenceCount new int to set in #arg
 * \return A new EM_Session with referenceCount at the right place, or a core dump if #arg did not have a referenceCount
 */
EM_Session EM_setSessionReferenceCount(EM_Session arg, int referenceCount) {
  if (EM_isSessionDefault(arg)) {
    return (EM_Session)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(referenceCount)), 3);
  }

  ATabort("Session has no ReferenceCount: %t\n", arg);
  return (EM_Session)NULL;
}

/**
 * Set the list of a EM_Session. The precondition being that this EM_Session actually has a list
 * \param[in] arg input EM_Session
 * \param[in] list new EM_EditorTypeList to set in #arg
 * \return A new EM_Session with list at the right place, or a core dump if #arg did not have a list
 */
EM_Session EM_setSessionList(EM_Session arg, EM_EditorTypeList list) {
  if (EM_isSessionDefault(arg)) {
    return (EM_Session)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 4);
  }

  ATabort("Session has no List: %t\n", arg);
  return (EM_Session)NULL;
}

/**
 * Assert whether a EM_EditorTypeList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input EM_EditorTypeList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool EM_isValidEditorTypeList(EM_EditorTypeList arg) {
  if (EM_isEditorTypeListEmpty(arg)) {
    return ATtrue;
  }
  else if (EM_isEditorTypeListSingle(arg)) {
    return ATtrue;
  }
  else if (EM_isEditorTypeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_EditorTypeList is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the EM_EditorTypeList
 * \param[in] arg input EM_EditorTypeList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool EM_isEditorTypeListEmpty(EM_EditorTypeList arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_EditorTypeList is a single by checking against the following ATerm pattern: [<head(EditorType)>]. May not be used to assert correctness of the EM_EditorTypeList
 * \param[in] arg input EM_EditorTypeList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool EM_isEditorTypeListSingle(EM_EditorTypeList arg){
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
 * Assert whether a EM_EditorTypeList is a many by checking against the following ATerm pattern: [<head(EditorType)>,<[tail(EditorType-list)]>]. May not be used to assert correctness of the EM_EditorTypeList
 * \param[in] arg input EM_EditorTypeList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool EM_isEditorTypeListMany(EM_EditorTypeList arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_EditorTypeList has a head. 
 * \param[in] arg input EM_EditorTypeList
 * \return ATtrue if the EM_EditorTypeList had a head, or ATfalse otherwise
 */
ATbool EM_hasEditorTypeListHead(EM_EditorTypeList arg) {
  if (EM_isEditorTypeListSingle(arg)) {
    return ATtrue;
  }
  else if (EM_isEditorTypeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EM_EditorTypeList has a tail. 
 * \param[in] arg input EM_EditorTypeList
 * \return ATtrue if the EM_EditorTypeList had a tail, or ATfalse otherwise
 */
ATbool EM_hasEditorTypeListTail(EM_EditorTypeList arg) {
  if (EM_isEditorTypeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head EM_EditorType of a EM_EditorTypeList. Note that the precondition is that this EM_EditorTypeList actually has a head
 * \param[in] arg input EM_EditorTypeList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
EM_EditorType EM_getEditorTypeListHead(EM_EditorTypeList arg) {
  if (EM_isEditorTypeListSingle(arg)) {
    return (EM_EditorType)ATgetFirst((ATermList)arg);
  }
  else 
    return (EM_EditorType)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail EM_EditorTypeList of a EM_EditorTypeList. Note that the precondition is that this EM_EditorTypeList actually has a tail
 * \param[in] arg input EM_EditorTypeList
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
EM_EditorTypeList EM_getEditorTypeListTail(EM_EditorTypeList arg) {
  
    return (EM_EditorTypeList)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a EM_EditorTypeList. The precondition being that this EM_EditorTypeList actually has a head
 * \param[in] arg input EM_EditorTypeList
 * \param[in] head new EM_EditorType to set in #arg
 * \return A new EM_EditorTypeList with head at the right place, or a core dump if #arg did not have a head
 */
EM_EditorTypeList EM_setEditorTypeListHead(EM_EditorTypeList arg, EM_EditorType head) {
  if (EM_isEditorTypeListSingle(arg)) {
    return (EM_EditorTypeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (EM_isEditorTypeListMany(arg)) {
    return (EM_EditorTypeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("EditorTypeList has no Head: %t\n", arg);
  return (EM_EditorTypeList)NULL;
}

/**
 * Set the tail of a EM_EditorTypeList. The precondition being that this EM_EditorTypeList actually has a tail
 * \param[in] arg input EM_EditorTypeList
 * \param[in] tail new EM_EditorTypeList to set in #arg
 * \return A new EM_EditorTypeList with tail at the right place, or a core dump if #arg did not have a tail
 */
EM_EditorTypeList EM_setEditorTypeListTail(EM_EditorTypeList arg, EM_EditorTypeList tail) {
  if (EM_isEditorTypeListMany(arg)) {
    return (EM_EditorTypeList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("EditorTypeList has no Tail: %t\n", arg);
  return (EM_EditorTypeList)NULL;
}

/**
 * Apply functions to the children of a EM_Sid. 
 * \return A new EM_Sid with new children where the argument functions might have applied
 */
EM_Sid EM_visitSid(EM_Sid arg, int (*acceptId)(int)) {
  if (EM_isSidSessionId(arg)) {
    return EM_makeSidSessionId(
        acceptId ? acceptId(EM_getSidId(arg)) : EM_getSidId(arg));
  }
  ATabort("not a Sid: %t\n", arg);
  return (EM_Sid)NULL;
}
/**
 * Apply functions to the children of a EM_EditorType. 
 * \return A new EM_EditorType with new children where the argument functions might have applied
 */
EM_EditorType EM_visitEditorType(EM_EditorType arg, char* (*acceptName)(char*)) {
  if (EM_isEditorTypeDefault(arg)) {
    return EM_makeEditorTypeDefault(
        acceptName ? acceptName(EM_getEditorTypeName(arg)) : EM_getEditorTypeName(arg));
  }
  ATabort("not a EditorType: %t\n", arg);
  return (EM_EditorType)NULL;
}
/**
 * Apply functions to the children of a EM_ModuleId. 
 * \return A new EM_ModuleId with new children where the argument functions might have applied
 */
EM_ModuleId EM_visitModuleId(EM_ModuleId arg, int (*acceptId)(int)) {
  if (EM_isModuleIdModuleId(arg)) {
    return EM_makeModuleIdModuleId(
        acceptId ? acceptId(EM_getModuleIdId(arg)) : EM_getModuleIdId(arg));
  }
  ATabort("not a ModuleId: %t\n", arg);
  return (EM_ModuleId)NULL;
}
/**
 * Apply functions to the children of a EM_SessionStatus. 
 * \return A new EM_SessionStatus with new children where the argument functions might have applied
 */
EM_SessionStatus EM_visitSessionStatus(EM_SessionStatus arg) {
  if (EM_isSessionStatusRunning(arg)) {
    return EM_makeSessionStatusRunning();
  }
  if (EM_isSessionStatusZombie(arg)) {
    return EM_makeSessionStatusZombie();
  }
  ATabort("not a SessionStatus: %t\n", arg);
  return (EM_SessionStatus)NULL;
}
/**
 * Apply functions to the children of a EM_Session. 
 * \return A new EM_Session with new children where the argument functions might have applied
 */
EM_Session EM_visitSession(EM_Session arg, EM_Sid (*acceptId)(EM_Sid), char* (*acceptPath)(char*), EM_SessionStatus (*acceptStatus)(EM_SessionStatus), int (*acceptReferenceCount)(int), EM_EditorTypeList (*acceptList)(EM_EditorTypeList)) {
  if (EM_isSessionDefault(arg)) {
    return EM_makeSessionDefault(
        acceptId ? acceptId(EM_getSessionId(arg)) : EM_getSessionId(arg),
        acceptPath ? acceptPath(EM_getSessionPath(arg)) : EM_getSessionPath(arg),
        acceptStatus ? acceptStatus(EM_getSessionStatus(arg)) : EM_getSessionStatus(arg),
        acceptReferenceCount ? acceptReferenceCount(EM_getSessionReferenceCount(arg)) : EM_getSessionReferenceCount(arg),
        acceptList ? acceptList(EM_getSessionList(arg)) : EM_getSessionList(arg));
  }
  ATabort("not a Session: %t\n", arg);
  return (EM_Session)NULL;
}
/**
 * Apply functions to the children of a EM_EditorTypeList. 
 * \return A new EM_EditorTypeList with new children where the argument functions might have applied
 */
EM_EditorTypeList EM_visitEditorTypeList(EM_EditorTypeList arg, EM_EditorType (*acceptHead)(EM_EditorType)) {
  if (EM_isEditorTypeListEmpty(arg)) {
    return EM_makeEditorTypeListEmpty();
  }
  if (EM_isEditorTypeListSingle(arg)) {
    return EM_makeEditorTypeListSingle(
        acceptHead ? acceptHead(EM_getEditorTypeListHead(arg)) : EM_getEditorTypeListHead(arg));
  }
  if (EM_isEditorTypeListMany(arg)) {
    return EM_makeEditorTypeListMany(
        acceptHead ? acceptHead(EM_getEditorTypeListHead(arg)) : EM_getEditorTypeListHead(arg),
        EM_visitEditorTypeList(EM_getEditorTypeListTail(arg), acceptHead));
  }
  ATabort("not a EditorTypeList: %t\n", arg);
  return (EM_EditorTypeList)NULL;
}

