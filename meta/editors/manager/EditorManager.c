#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "EditorManager.h"

/*{{{  conversion functions */

ATerm EM_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

char *EM_charsToString(ATerm arg)
{
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


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _EM_Sid;
typedef struct ATerm _EM_EditorType;
typedef struct ATerm _EM_SessionStatus;
typedef struct ATerm _EM_Session;
typedef struct ATerm _EM_EditorTypeList;

/*}}}  */

/*{{{  void EM_initEditorManagerApi(void) */

void EM_initEditorManagerApi(void)
{
  init_EditorManager_dict();
}

/*}}}  */

/*{{{  protect functions */

void EM_protectSid(EM_Sid *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void EM_protectEditorType(EM_EditorType *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void EM_protectSessionStatus(EM_SessionStatus *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void EM_protectSession(EM_Session *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void EM_protectEditorTypeList(EM_EditorTypeList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  EM_Sid EM_SidFromTerm(ATerm t) */

EM_Sid EM_SidFromTerm(ATerm t)
{
  return (EM_Sid)t;
}

/*}}}  */
/*{{{  ATerm EM_SidToTerm(EM_Sid arg) */

ATerm EM_SidToTerm(EM_Sid arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  EM_EditorType EM_EditorTypeFromTerm(ATerm t) */

EM_EditorType EM_EditorTypeFromTerm(ATerm t)
{
  return (EM_EditorType)t;
}

/*}}}  */
/*{{{  ATerm EM_EditorTypeToTerm(EM_EditorType arg) */

ATerm EM_EditorTypeToTerm(EM_EditorType arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  EM_SessionStatus EM_SessionStatusFromTerm(ATerm t) */

EM_SessionStatus EM_SessionStatusFromTerm(ATerm t)
{
  return (EM_SessionStatus)t;
}

/*}}}  */
/*{{{  ATerm EM_SessionStatusToTerm(EM_SessionStatus arg) */

ATerm EM_SessionStatusToTerm(EM_SessionStatus arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  EM_Session EM_SessionFromTerm(ATerm t) */

EM_Session EM_SessionFromTerm(ATerm t)
{
  return (EM_Session)t;
}

/*}}}  */
/*{{{  ATerm EM_SessionToTerm(EM_Session arg) */

ATerm EM_SessionToTerm(EM_Session arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  EM_EditorTypeList EM_EditorTypeListFromTerm(ATerm t) */

EM_EditorTypeList EM_EditorTypeListFromTerm(ATerm t)
{
  return (EM_EditorTypeList)t;
}

/*}}}  */
/*{{{  ATerm EM_EditorTypeListToTerm(EM_EditorTypeList arg) */

ATerm EM_EditorTypeListToTerm(EM_EditorTypeList arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int EM_getEditorTypeListLength (EM_EditorTypeList arg) {
  return ATgetLength((ATermList) arg);
}
EM_EditorTypeList EM_reverseEditorTypeList(EM_EditorTypeList arg) {
  return (EM_EditorTypeList) ATreverse((ATermList) arg);
}
EM_EditorTypeList EM_appendEditorTypeList(EM_EditorTypeList arg, EM_EditorType elem) {
  return (EM_EditorTypeList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
EM_EditorTypeList EM_concatEditorTypeList(EM_EditorTypeList arg0, EM_EditorTypeList arg1) {
  return (EM_EditorTypeList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
EM_EditorTypeList EM_sliceEditorTypeList(EM_EditorTypeList arg, int start, int end) {
  return (EM_EditorTypeList) ATgetSlice((ATermList) arg, start, end);
}
EM_EditorType EM_getEditorTypeListEditorTypeAt(EM_EditorTypeList arg, int index) {
 return (EM_EditorType)ATelementAt((ATermList) arg,index);
}
EM_EditorTypeList EM_replaceEditorTypeListEditorTypeAt(EM_EditorTypeList arg, EM_EditorType elem, int index) {
 return (EM_EditorTypeList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
EM_EditorTypeList EM_makeEditorTypeList2(EM_EditorType elem1, EM_EditorType elem2) {
  return (EM_EditorTypeList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
EM_EditorTypeList EM_makeEditorTypeList3(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3) {
  return (EM_EditorTypeList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
EM_EditorTypeList EM_makeEditorTypeList4(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3, EM_EditorType elem4) {
  return (EM_EditorTypeList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
EM_EditorTypeList EM_makeEditorTypeList5(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3, EM_EditorType elem4, EM_EditorType elem5) {
  return (EM_EditorTypeList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
EM_EditorTypeList EM_makeEditorTypeList6(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3, EM_EditorType elem4, EM_EditorType elem5, EM_EditorType elem6) {
  return (EM_EditorTypeList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  EM_Sid EM_makeSidDefault(int id) */

EM_Sid EM_makeSidDefault(int id)
{
  return (EM_Sid)(ATerm)ATmakeAppl1(EM_afun0, (ATerm) (ATerm) ATmakeInt(id));
}

/*}}}  */
/*{{{  EM_EditorType EM_makeEditorTypeDefault(const char* name) */

EM_EditorType EM_makeEditorTypeDefault(const char* name)
{
  return (EM_EditorType)(ATerm)ATmakeAppl1(EM_afun0, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}

/*}}}  */
/*{{{  EM_SessionStatus EM_makeSessionStatusRunning(void) */

EM_SessionStatus EM_makeSessionStatusRunning(void)
{
  return (EM_SessionStatus)(ATerm)ATmakeAppl0(EM_afun1);
}

/*}}}  */
/*{{{  EM_SessionStatus EM_makeSessionStatusZombie(void) */

EM_SessionStatus EM_makeSessionStatusZombie(void)
{
  return (EM_SessionStatus)(ATerm)ATmakeAppl0(EM_afun2);
}

/*}}}  */
/*{{{  EM_Session EM_makeSessionDefault(EM_Sid id, const char* filename, const char* modulename, EM_SessionStatus status, int referenceCount, EM_EditorTypeList list) */

EM_Session EM_makeSessionDefault(EM_Sid id, const char* filename, const char* modulename, EM_SessionStatus status, int referenceCount, EM_EditorTypeList list)
{
  return (EM_Session)(ATerm)ATmakeAppl6(EM_afun3, (ATerm) id, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(modulename, 0, ATtrue)), (ATerm) status, (ATerm) (ATerm) ATmakeInt(referenceCount), (ATerm) list);
}

/*}}}  */
/*{{{  EM_EditorTypeList EM_makeEditorTypeListEmpty(void) */

EM_EditorTypeList EM_makeEditorTypeListEmpty(void)
{
  return (EM_EditorTypeList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  EM_EditorTypeList EM_makeEditorTypeListSingle(EM_EditorType head) */

EM_EditorTypeList EM_makeEditorTypeListSingle(EM_EditorType head)
{
  return (EM_EditorTypeList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  EM_EditorTypeList EM_makeEditorTypeListMany(EM_EditorType head, EM_EditorTypeList tail) */

EM_EditorTypeList EM_makeEditorTypeListMany(EM_EditorType head, EM_EditorTypeList tail)
{
  return (EM_EditorTypeList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool EM_isEqualSid(EM_Sid arg0, EM_Sid arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool EM_isEqualEditorType(EM_EditorType arg0, EM_EditorType arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool EM_isEqualSessionStatus(EM_SessionStatus arg0, EM_SessionStatus arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool EM_isEqualSession(EM_Session arg0, EM_Session arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool EM_isEqualEditorTypeList(EM_EditorTypeList arg0, EM_EditorTypeList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  EM_Sid accessors */

/*{{{  ATbool EM_isValidSid(EM_Sid arg) */

ATbool EM_isValidSid(EM_Sid arg)
{
  if (EM_isSidDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool EM_isSidDefault(EM_Sid arg) */

inline ATbool EM_isSidDefault(EM_Sid arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, EM_patternSidDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool EM_hasSidId(EM_Sid arg) */

ATbool EM_hasSidId(EM_Sid arg)
{
  if (EM_isSidDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int EM_getSidId(EM_Sid arg) */

int EM_getSidId(EM_Sid arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  EM_Sid EM_setSidId(EM_Sid arg, int id) */

EM_Sid EM_setSidId(EM_Sid arg, int id)
{
  if (EM_isSidDefault(arg)) {
    return (EM_Sid)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(id)), 0);
  }

  ATabort("Sid has no Id: %t\n", arg);
  return (EM_Sid)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  EM_EditorType accessors */

/*{{{  ATbool EM_isValidEditorType(EM_EditorType arg) */

ATbool EM_isValidEditorType(EM_EditorType arg)
{
  if (EM_isEditorTypeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool EM_isEditorTypeDefault(EM_EditorType arg) */

inline ATbool EM_isEditorTypeDefault(EM_EditorType arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, EM_patternEditorTypeDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool EM_hasEditorTypeName(EM_EditorType arg) */

ATbool EM_hasEditorTypeName(EM_EditorType arg)
{
  if (EM_isEditorTypeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* EM_getEditorTypeName(EM_EditorType arg) */

char* EM_getEditorTypeName(EM_EditorType arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  EM_EditorType EM_setEditorTypeName(EM_EditorType arg, const char* name) */

EM_EditorType EM_setEditorTypeName(EM_EditorType arg, const char* name)
{
  if (EM_isEditorTypeDefault(arg)) {
    return (EM_EditorType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("EditorType has no Name: %t\n", arg);
  return (EM_EditorType)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  EM_SessionStatus accessors */

/*{{{  ATbool EM_isValidSessionStatus(EM_SessionStatus arg) */

ATbool EM_isValidSessionStatus(EM_SessionStatus arg)
{
  if (EM_isSessionStatusRunning(arg)) {
    return ATtrue;
  }
  else if (EM_isSessionStatusZombie(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool EM_isSessionStatusRunning(EM_SessionStatus arg) */

inline ATbool EM_isSessionStatusRunning(EM_SessionStatus arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, EM_patternSessionStatusRunning);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool EM_isSessionStatusZombie(EM_SessionStatus arg) */

inline ATbool EM_isSessionStatusZombie(EM_SessionStatus arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, EM_patternSessionStatusZombie);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  EM_Session accessors */

/*{{{  ATbool EM_isValidSession(EM_Session arg) */

ATbool EM_isValidSession(EM_Session arg)
{
  if (EM_isSessionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool EM_isSessionDefault(EM_Session arg) */

inline ATbool EM_isSessionDefault(EM_Session arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, EM_patternSessionDefault, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool EM_hasSessionId(EM_Session arg) */

ATbool EM_hasSessionId(EM_Session arg)
{
  if (EM_isSessionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  EM_Sid EM_getSessionId(EM_Session arg) */

EM_Sid EM_getSessionId(EM_Session arg)
{
  
    return (EM_Sid)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  EM_Session EM_setSessionId(EM_Session arg, EM_Sid id) */

EM_Session EM_setSessionId(EM_Session arg, EM_Sid id)
{
  if (EM_isSessionDefault(arg)) {
    return (EM_Session)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) id), 0);
  }

  ATabort("Session has no Id: %t\n", arg);
  return (EM_Session)NULL;
}

/*}}}  */
/*{{{  ATbool EM_hasSessionFilename(EM_Session arg) */

ATbool EM_hasSessionFilename(EM_Session arg)
{
  if (EM_isSessionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* EM_getSessionFilename(EM_Session arg) */

char* EM_getSessionFilename(EM_Session arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  EM_Session EM_setSessionFilename(EM_Session arg, const char* filename) */

EM_Session EM_setSessionFilename(EM_Session arg, const char* filename)
{
  if (EM_isSessionDefault(arg)) {
    return (EM_Session)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue))), 1);
  }

  ATabort("Session has no Filename: %t\n", arg);
  return (EM_Session)NULL;
}

/*}}}  */
/*{{{  ATbool EM_hasSessionModulename(EM_Session arg) */

ATbool EM_hasSessionModulename(EM_Session arg)
{
  if (EM_isSessionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* EM_getSessionModulename(EM_Session arg) */

char* EM_getSessionModulename(EM_Session arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 2)));
}

/*}}}  */
/*{{{  EM_Session EM_setSessionModulename(EM_Session arg, const char* modulename) */

EM_Session EM_setSessionModulename(EM_Session arg, const char* modulename)
{
  if (EM_isSessionDefault(arg)) {
    return (EM_Session)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(modulename, 0, ATtrue))), 2);
  }

  ATabort("Session has no Modulename: %t\n", arg);
  return (EM_Session)NULL;
}

/*}}}  */
/*{{{  ATbool EM_hasSessionStatus(EM_Session arg) */

ATbool EM_hasSessionStatus(EM_Session arg)
{
  if (EM_isSessionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  EM_SessionStatus EM_getSessionStatus(EM_Session arg) */

EM_SessionStatus EM_getSessionStatus(EM_Session arg)
{
  
    return (EM_SessionStatus)ATgetArgument((ATermAppl)arg, 3);
}

/*}}}  */
/*{{{  EM_Session EM_setSessionStatus(EM_Session arg, EM_SessionStatus status) */

EM_Session EM_setSessionStatus(EM_Session arg, EM_SessionStatus status)
{
  if (EM_isSessionDefault(arg)) {
    return (EM_Session)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) status), 3);
  }

  ATabort("Session has no Status: %t\n", arg);
  return (EM_Session)NULL;
}

/*}}}  */
/*{{{  ATbool EM_hasSessionReferenceCount(EM_Session arg) */

ATbool EM_hasSessionReferenceCount(EM_Session arg)
{
  if (EM_isSessionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int EM_getSessionReferenceCount(EM_Session arg) */

int EM_getSessionReferenceCount(EM_Session arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 4));
}

/*}}}  */
/*{{{  EM_Session EM_setSessionReferenceCount(EM_Session arg, int referenceCount) */

EM_Session EM_setSessionReferenceCount(EM_Session arg, int referenceCount)
{
  if (EM_isSessionDefault(arg)) {
    return (EM_Session)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(referenceCount)), 4);
  }

  ATabort("Session has no ReferenceCount: %t\n", arg);
  return (EM_Session)NULL;
}

/*}}}  */
/*{{{  ATbool EM_hasSessionList(EM_Session arg) */

ATbool EM_hasSessionList(EM_Session arg)
{
  if (EM_isSessionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  EM_EditorTypeList EM_getSessionList(EM_Session arg) */

EM_EditorTypeList EM_getSessionList(EM_Session arg)
{
  
    return (EM_EditorTypeList)ATgetArgument((ATermAppl)arg, 5);
}

/*}}}  */
/*{{{  EM_Session EM_setSessionList(EM_Session arg, EM_EditorTypeList list) */

EM_Session EM_setSessionList(EM_Session arg, EM_EditorTypeList list)
{
  if (EM_isSessionDefault(arg)) {
    return (EM_Session)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 5);
  }

  ATabort("Session has no List: %t\n", arg);
  return (EM_Session)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  EM_EditorTypeList accessors */

/*{{{  ATbool EM_isValidEditorTypeList(EM_EditorTypeList arg) */

ATbool EM_isValidEditorTypeList(EM_EditorTypeList arg)
{
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

/*}}}  */
/*{{{  inline ATbool EM_isEditorTypeListEmpty(EM_EditorTypeList arg) */

inline ATbool EM_isEditorTypeListEmpty(EM_EditorTypeList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, EM_patternEditorTypeListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool EM_isEditorTypeListSingle(EM_EditorTypeList arg) */

inline ATbool EM_isEditorTypeListSingle(EM_EditorTypeList arg)
{
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
      last_result = ATmatchTerm((ATerm)arg, EM_patternEditorTypeListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool EM_isEditorTypeListMany(EM_EditorTypeList arg) */

inline ATbool EM_isEditorTypeListMany(EM_EditorTypeList arg)
{
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
      last_result = ATmatchTerm((ATerm)arg, EM_patternEditorTypeListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool EM_hasEditorTypeListHead(EM_EditorTypeList arg) */

ATbool EM_hasEditorTypeListHead(EM_EditorTypeList arg)
{
  if (EM_isEditorTypeListSingle(arg)) {
    return ATtrue;
  }
  else if (EM_isEditorTypeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  EM_EditorType EM_getEditorTypeListHead(EM_EditorTypeList arg) */

EM_EditorType EM_getEditorTypeListHead(EM_EditorTypeList arg)
{
  if (EM_isEditorTypeListSingle(arg)) {
    return (EM_EditorType)ATgetFirst((ATermList)arg);
  }
  else 
    return (EM_EditorType)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  EM_EditorTypeList EM_setEditorTypeListHead(EM_EditorTypeList arg, EM_EditorType head) */

EM_EditorTypeList EM_setEditorTypeListHead(EM_EditorTypeList arg, EM_EditorType head)
{
  if (EM_isEditorTypeListSingle(arg)) {
    return (EM_EditorTypeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (EM_isEditorTypeListMany(arg)) {
    return (EM_EditorTypeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("EditorTypeList has no Head: %t\n", arg);
  return (EM_EditorTypeList)NULL;
}

/*}}}  */
/*{{{  ATbool EM_hasEditorTypeListTail(EM_EditorTypeList arg) */

ATbool EM_hasEditorTypeListTail(EM_EditorTypeList arg)
{
  if (EM_isEditorTypeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  EM_EditorTypeList EM_getEditorTypeListTail(EM_EditorTypeList arg) */

EM_EditorTypeList EM_getEditorTypeListTail(EM_EditorTypeList arg)
{
  
    return (EM_EditorTypeList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  EM_EditorTypeList EM_setEditorTypeListTail(EM_EditorTypeList arg, EM_EditorTypeList tail) */

EM_EditorTypeList EM_setEditorTypeListTail(EM_EditorTypeList arg, EM_EditorTypeList tail)
{
  if (EM_isEditorTypeListMany(arg)) {
    return (EM_EditorTypeList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("EditorTypeList has no Tail: %t\n", arg);
  return (EM_EditorTypeList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  EM_Sid EM_visitSid(EM_Sid arg, int (*acceptId)(int)) */

EM_Sid EM_visitSid(EM_Sid arg, int (*acceptId)(int))
{
  if (EM_isSidDefault(arg)) {
    return EM_makeSidDefault(
        acceptId ? acceptId(EM_getSidId(arg)) : EM_getSidId(arg));
  }
  ATabort("not a Sid: %t\n", arg);
  return (EM_Sid)NULL;
}

/*}}}  */
/*{{{  EM_EditorType EM_visitEditorType(EM_EditorType arg, char* (*acceptName)(char*)) */

EM_EditorType EM_visitEditorType(EM_EditorType arg, char* (*acceptName)(char*))
{
  if (EM_isEditorTypeDefault(arg)) {
    return EM_makeEditorTypeDefault(
        acceptName ? acceptName(EM_getEditorTypeName(arg)) : EM_getEditorTypeName(arg));
  }
  ATabort("not a EditorType: %t\n", arg);
  return (EM_EditorType)NULL;
}

/*}}}  */
/*{{{  EM_SessionStatus EM_visitSessionStatus(EM_SessionStatus arg) */

EM_SessionStatus EM_visitSessionStatus(EM_SessionStatus arg)
{
  if (EM_isSessionStatusRunning(arg)) {
    return EM_makeSessionStatusRunning();
  }
  if (EM_isSessionStatusZombie(arg)) {
    return EM_makeSessionStatusZombie();
  }
  ATabort("not a SessionStatus: %t\n", arg);
  return (EM_SessionStatus)NULL;
}

/*}}}  */
/*{{{  EM_Session EM_visitSession(EM_Session arg, EM_Sid (*acceptId)(EM_Sid), char* (*acceptFilename)(char*), char* (*acceptModulename)(char*), EM_SessionStatus (*acceptStatus)(EM_SessionStatus), int (*acceptReferenceCount)(int), EM_EditorTypeList (*acceptList)(EM_EditorTypeList)) */

EM_Session EM_visitSession(EM_Session arg, EM_Sid (*acceptId)(EM_Sid), char* (*acceptFilename)(char*), char* (*acceptModulename)(char*), EM_SessionStatus (*acceptStatus)(EM_SessionStatus), int (*acceptReferenceCount)(int), EM_EditorTypeList (*acceptList)(EM_EditorTypeList))
{
  if (EM_isSessionDefault(arg)) {
    return EM_makeSessionDefault(
        acceptId ? acceptId(EM_getSessionId(arg)) : EM_getSessionId(arg),
        acceptFilename ? acceptFilename(EM_getSessionFilename(arg)) : EM_getSessionFilename(arg),
        acceptModulename ? acceptModulename(EM_getSessionModulename(arg)) : EM_getSessionModulename(arg),
        acceptStatus ? acceptStatus(EM_getSessionStatus(arg)) : EM_getSessionStatus(arg),
        acceptReferenceCount ? acceptReferenceCount(EM_getSessionReferenceCount(arg)) : EM_getSessionReferenceCount(arg),
        acceptList ? acceptList(EM_getSessionList(arg)) : EM_getSessionList(arg));
  }
  ATabort("not a Session: %t\n", arg);
  return (EM_Session)NULL;
}

/*}}}  */
/*{{{  EM_EditorTypeList EM_visitEditorTypeList(EM_EditorTypeList arg, EM_EditorType (*acceptHead)(EM_EditorType)) */

EM_EditorTypeList EM_visitEditorTypeList(EM_EditorTypeList arg, EM_EditorType (*acceptHead)(EM_EditorType))
{
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

/*}}}  */

/*}}}  */
