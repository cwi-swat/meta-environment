#ifndef _EDITORMANAGER_H
#define _EDITORMANAGER_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "EditorManager_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _EM_Sid *EM_Sid;
typedef struct _EM_EditorType *EM_EditorType;
typedef struct _EM_ModuleId *EM_ModuleId;
typedef struct _EM_SessionStatus *EM_SessionStatus;
typedef struct _EM_Session *EM_Session;
typedef struct _EM_EditorTypeList *EM_EditorTypeList;

/*}}}  */

void EM_initEditorManagerApi(void);

/*{{{  protect functions */

void EM_protectSid(EM_Sid *arg);
void EM_protectEditorType(EM_EditorType *arg);
void EM_protectModuleId(EM_ModuleId *arg);
void EM_protectSessionStatus(EM_SessionStatus *arg);
void EM_protectSession(EM_Session *arg);
void EM_protectEditorTypeList(EM_EditorTypeList *arg);

/*}}}  */
/*{{{  term conversion functions */

EM_Sid EM_SidFromTerm(ATerm t);
ATerm EM_SidToTerm(EM_Sid arg);
EM_EditorType EM_EditorTypeFromTerm(ATerm t);
ATerm EM_EditorTypeToTerm(EM_EditorType arg);
EM_ModuleId EM_ModuleIdFromTerm(ATerm t);
ATerm EM_ModuleIdToTerm(EM_ModuleId arg);
EM_SessionStatus EM_SessionStatusFromTerm(ATerm t);
ATerm EM_SessionStatusToTerm(EM_SessionStatus arg);
EM_Session EM_SessionFromTerm(ATerm t);
ATerm EM_SessionToTerm(EM_Session arg);
EM_EditorTypeList EM_EditorTypeListFromTerm(ATerm t);
ATerm EM_EditorTypeListToTerm(EM_EditorTypeList arg);

/*}}}  */
/*{{{  list functions */

int EM_getEditorTypeListLength (EM_EditorTypeList arg);
EM_EditorTypeList EM_reverseEditorTypeList(EM_EditorTypeList arg);
EM_EditorTypeList EM_appendEditorTypeList(EM_EditorTypeList arg, EM_EditorType elem);
EM_EditorTypeList EM_concatEditorTypeList(EM_EditorTypeList arg0, EM_EditorTypeList arg1);
EM_EditorTypeList EM_sliceEditorTypeList(EM_EditorTypeList arg, int start, int end);
EM_EditorType EM_getEditorTypeListEditorTypeAt(EM_EditorTypeList arg, int index);
EM_EditorTypeList EM_replaceEditorTypeListEditorTypeAt(EM_EditorTypeList arg, EM_EditorType elem, int index);
EM_EditorTypeList EM_makeEditorTypeList2(EM_EditorType elem1, EM_EditorType elem2);
EM_EditorTypeList EM_makeEditorTypeList3(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3);
EM_EditorTypeList EM_makeEditorTypeList4(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3, EM_EditorType elem4);
EM_EditorTypeList EM_makeEditorTypeList5(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3, EM_EditorType elem4, EM_EditorType elem5);
EM_EditorTypeList EM_makeEditorTypeList6(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3, EM_EditorType elem4, EM_EditorType elem5, EM_EditorType elem6);

/*}}}  */
/*{{{  constructors */

EM_Sid EM_makeSidDefault(int id);
EM_EditorType EM_makeEditorTypeDefault(const char* name);
EM_ModuleId EM_makeModuleIdDefault(const char* name);
EM_SessionStatus EM_makeSessionStatusRunning(void);
EM_SessionStatus EM_makeSessionStatusZombie(void);
EM_Session EM_makeSessionDefault(EM_Sid id, const char* path, EM_SessionStatus status, int referenceCount, EM_EditorTypeList list);
EM_EditorTypeList EM_makeEditorTypeListEmpty(void);
EM_EditorTypeList EM_makeEditorTypeListSingle(EM_EditorType head);
EM_EditorTypeList EM_makeEditorTypeListMany(EM_EditorType head, EM_EditorTypeList tail);

/*}}}  */
/*{{{  equality functions */

ATbool EM_isEqualSid(EM_Sid arg0, EM_Sid arg1);
ATbool EM_isEqualEditorType(EM_EditorType arg0, EM_EditorType arg1);
ATbool EM_isEqualModuleId(EM_ModuleId arg0, EM_ModuleId arg1);
ATbool EM_isEqualSessionStatus(EM_SessionStatus arg0, EM_SessionStatus arg1);
ATbool EM_isEqualSession(EM_Session arg0, EM_Session arg1);
ATbool EM_isEqualEditorTypeList(EM_EditorTypeList arg0, EM_EditorTypeList arg1);

/*}}}  */
/*{{{  EM_Sid accessors */

ATbool EM_isValidSid(EM_Sid arg);
inline ATbool EM_isSidDefault(EM_Sid arg);
ATbool EM_hasSidId(EM_Sid arg);
int EM_getSidId(EM_Sid arg);
EM_Sid EM_setSidId(EM_Sid arg, int id);

/*}}}  */
/*{{{  EM_EditorType accessors */

ATbool EM_isValidEditorType(EM_EditorType arg);
inline ATbool EM_isEditorTypeDefault(EM_EditorType arg);
ATbool EM_hasEditorTypeName(EM_EditorType arg);
char* EM_getEditorTypeName(EM_EditorType arg);
EM_EditorType EM_setEditorTypeName(EM_EditorType arg, const char* name);

/*}}}  */
/*{{{  EM_ModuleId accessors */

ATbool EM_isValidModuleId(EM_ModuleId arg);
inline ATbool EM_isModuleIdDefault(EM_ModuleId arg);
ATbool EM_hasModuleIdName(EM_ModuleId arg);
char* EM_getModuleIdName(EM_ModuleId arg);
EM_ModuleId EM_setModuleIdName(EM_ModuleId arg, const char* name);

/*}}}  */
/*{{{  EM_SessionStatus accessors */

ATbool EM_isValidSessionStatus(EM_SessionStatus arg);
inline ATbool EM_isSessionStatusRunning(EM_SessionStatus arg);
inline ATbool EM_isSessionStatusZombie(EM_SessionStatus arg);

/*}}}  */
/*{{{  EM_Session accessors */

ATbool EM_isValidSession(EM_Session arg);
inline ATbool EM_isSessionDefault(EM_Session arg);
ATbool EM_hasSessionId(EM_Session arg);
EM_Sid EM_getSessionId(EM_Session arg);
EM_Session EM_setSessionId(EM_Session arg, EM_Sid id);
ATbool EM_hasSessionPath(EM_Session arg);
char* EM_getSessionPath(EM_Session arg);
EM_Session EM_setSessionPath(EM_Session arg, const char* path);
ATbool EM_hasSessionStatus(EM_Session arg);
EM_SessionStatus EM_getSessionStatus(EM_Session arg);
EM_Session EM_setSessionStatus(EM_Session arg, EM_SessionStatus status);
ATbool EM_hasSessionReferenceCount(EM_Session arg);
int EM_getSessionReferenceCount(EM_Session arg);
EM_Session EM_setSessionReferenceCount(EM_Session arg, int referenceCount);
ATbool EM_hasSessionList(EM_Session arg);
EM_EditorTypeList EM_getSessionList(EM_Session arg);
EM_Session EM_setSessionList(EM_Session arg, EM_EditorTypeList list);

/*}}}  */
/*{{{  EM_EditorTypeList accessors */

ATbool EM_isValidEditorTypeList(EM_EditorTypeList arg);
inline ATbool EM_isEditorTypeListEmpty(EM_EditorTypeList arg);
inline ATbool EM_isEditorTypeListSingle(EM_EditorTypeList arg);
inline ATbool EM_isEditorTypeListMany(EM_EditorTypeList arg);
ATbool EM_hasEditorTypeListHead(EM_EditorTypeList arg);
EM_EditorType EM_getEditorTypeListHead(EM_EditorTypeList arg);
EM_EditorTypeList EM_setEditorTypeListHead(EM_EditorTypeList arg, EM_EditorType head);
ATbool EM_hasEditorTypeListTail(EM_EditorTypeList arg);
EM_EditorTypeList EM_getEditorTypeListTail(EM_EditorTypeList arg);
EM_EditorTypeList EM_setEditorTypeListTail(EM_EditorTypeList arg, EM_EditorTypeList tail);

/*}}}  */
/*{{{  sort visitors */

EM_Sid EM_visitSid(EM_Sid arg, int (*acceptId)(int));
EM_EditorType EM_visitEditorType(EM_EditorType arg, char* (*acceptName)(char*));
EM_ModuleId EM_visitModuleId(EM_ModuleId arg, char* (*acceptName)(char*));
EM_SessionStatus EM_visitSessionStatus(EM_SessionStatus arg);
EM_Session EM_visitSession(EM_Session arg, EM_Sid (*acceptId)(EM_Sid), char* (*acceptPath)(char*), EM_SessionStatus (*acceptStatus)(EM_SessionStatus), int (*acceptReferenceCount)(int), EM_EditorTypeList (*acceptList)(EM_EditorTypeList));
EM_EditorTypeList EM_visitEditorTypeList(EM_EditorTypeList arg, EM_EditorType (*acceptHead)(EM_EditorType));

/*}}}  */

#endif /* _EDITORMANAGER_H */
