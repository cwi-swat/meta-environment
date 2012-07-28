#ifndef _EDITORMANAGER_H
#define _EDITORMANAGER_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "EditorManager_dict.h"

typedef struct _EM_Sid *EM_Sid;
typedef struct _EM_EditorType *EM_EditorType;
typedef struct _EM_ModuleId *EM_ModuleId;
typedef struct _EM_SessionStatus *EM_SessionStatus;
typedef struct _EM_Session *EM_Session;
typedef struct _EM_EditorTypeList *EM_EditorTypeList;

#ifdef FAST_API
#define EM_initEditorManagerApi() (init_EditorManager_dict())
#else
void _EM_initEditorManagerApi(void);
#define EM_initEditorManagerApi() (_EM_initEditorManagerApi())
#endif

#ifdef FAST_API
#define EM_protectSid(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _EM_protectSid(EM_Sid *arg);
#define EM_protectSid(arg) (_EM_protectSid(arg))
#endif
#ifdef FAST_API
#define EM_unprotectSid(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _EM_unprotectSid(EM_Sid *arg);
#define EM_unprotectSid(arg) (_EM_unprotectSid(arg))
#endif
#ifdef FAST_API
#define EM_protectEditorType(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _EM_protectEditorType(EM_EditorType *arg);
#define EM_protectEditorType(arg) (_EM_protectEditorType(arg))
#endif
#ifdef FAST_API
#define EM_unprotectEditorType(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _EM_unprotectEditorType(EM_EditorType *arg);
#define EM_unprotectEditorType(arg) (_EM_unprotectEditorType(arg))
#endif
#ifdef FAST_API
#define EM_protectModuleId(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _EM_protectModuleId(EM_ModuleId *arg);
#define EM_protectModuleId(arg) (_EM_protectModuleId(arg))
#endif
#ifdef FAST_API
#define EM_unprotectModuleId(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _EM_unprotectModuleId(EM_ModuleId *arg);
#define EM_unprotectModuleId(arg) (_EM_unprotectModuleId(arg))
#endif
#ifdef FAST_API
#define EM_protectSessionStatus(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _EM_protectSessionStatus(EM_SessionStatus *arg);
#define EM_protectSessionStatus(arg) (_EM_protectSessionStatus(arg))
#endif
#ifdef FAST_API
#define EM_unprotectSessionStatus(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _EM_unprotectSessionStatus(EM_SessionStatus *arg);
#define EM_unprotectSessionStatus(arg) (_EM_unprotectSessionStatus(arg))
#endif
#ifdef FAST_API
#define EM_protectSession(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _EM_protectSession(EM_Session *arg);
#define EM_protectSession(arg) (_EM_protectSession(arg))
#endif
#ifdef FAST_API
#define EM_unprotectSession(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _EM_unprotectSession(EM_Session *arg);
#define EM_unprotectSession(arg) (_EM_unprotectSession(arg))
#endif
#ifdef FAST_API
#define EM_protectEditorTypeList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _EM_protectEditorTypeList(EM_EditorTypeList *arg);
#define EM_protectEditorTypeList(arg) (_EM_protectEditorTypeList(arg))
#endif
#ifdef FAST_API
#define EM_unprotectEditorTypeList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _EM_unprotectEditorTypeList(EM_EditorTypeList *arg);
#define EM_unprotectEditorTypeList(arg) (_EM_unprotectEditorTypeList(arg))
#endif
#ifdef FAST_API
#define EM_SidFromTerm(t) ((EM_Sid)(t))
#else
EM_Sid _EM_SidFromTerm(ATerm t);
#define EM_SidFromTerm(t) (_EM_SidFromTerm(t))
#endif
#ifdef FAST_API
#define EM_SidToTerm(arg) ((ATerm)(arg))
#else
ATerm _EM_SidToTerm(EM_Sid arg);
#define EM_SidToTerm(arg) (_EM_SidToTerm(arg))
#endif
#ifdef FAST_API
#define EM_EditorTypeFromTerm(t) ((EM_EditorType)(t))
#else
EM_EditorType _EM_EditorTypeFromTerm(ATerm t);
#define EM_EditorTypeFromTerm(t) (_EM_EditorTypeFromTerm(t))
#endif
#ifdef FAST_API
#define EM_EditorTypeToTerm(arg) ((ATerm)(arg))
#else
ATerm _EM_EditorTypeToTerm(EM_EditorType arg);
#define EM_EditorTypeToTerm(arg) (_EM_EditorTypeToTerm(arg))
#endif
#ifdef FAST_API
#define EM_ModuleIdFromTerm(t) ((EM_ModuleId)(t))
#else
EM_ModuleId _EM_ModuleIdFromTerm(ATerm t);
#define EM_ModuleIdFromTerm(t) (_EM_ModuleIdFromTerm(t))
#endif
#ifdef FAST_API
#define EM_ModuleIdToTerm(arg) ((ATerm)(arg))
#else
ATerm _EM_ModuleIdToTerm(EM_ModuleId arg);
#define EM_ModuleIdToTerm(arg) (_EM_ModuleIdToTerm(arg))
#endif
#ifdef FAST_API
#define EM_SessionStatusFromTerm(t) ((EM_SessionStatus)(t))
#else
EM_SessionStatus _EM_SessionStatusFromTerm(ATerm t);
#define EM_SessionStatusFromTerm(t) (_EM_SessionStatusFromTerm(t))
#endif
#ifdef FAST_API
#define EM_SessionStatusToTerm(arg) ((ATerm)(arg))
#else
ATerm _EM_SessionStatusToTerm(EM_SessionStatus arg);
#define EM_SessionStatusToTerm(arg) (_EM_SessionStatusToTerm(arg))
#endif
#ifdef FAST_API
#define EM_SessionFromTerm(t) ((EM_Session)(t))
#else
EM_Session _EM_SessionFromTerm(ATerm t);
#define EM_SessionFromTerm(t) (_EM_SessionFromTerm(t))
#endif
#ifdef FAST_API
#define EM_SessionToTerm(arg) ((ATerm)(arg))
#else
ATerm _EM_SessionToTerm(EM_Session arg);
#define EM_SessionToTerm(arg) (_EM_SessionToTerm(arg))
#endif
#ifdef FAST_API
#define EM_EditorTypeListFromTerm(t) ((EM_EditorTypeList)(t))
#else
EM_EditorTypeList _EM_EditorTypeListFromTerm(ATerm t);
#define EM_EditorTypeListFromTerm(t) (_EM_EditorTypeListFromTerm(t))
#endif
#ifdef FAST_API
#define EM_EditorTypeListToTerm(arg) ((ATerm)(arg))
#else
ATerm _EM_EditorTypeListToTerm(EM_EditorTypeList arg);
#define EM_EditorTypeListToTerm(arg) (_EM_EditorTypeListToTerm(arg))
#endif
#ifdef FAST_API
#define EM_getEditorTypeListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _EM_getEditorTypeListLength(EM_EditorTypeList arg);
#define EM_getEditorTypeListLength(arg) (_EM_getEditorTypeListLength(arg))
#endif
#ifdef FAST_API
#define EM_reverseEditorTypeList(arg) ((EM_EditorTypeList) ATreverse((ATermList) (arg)))
#else
EM_EditorTypeList _EM_reverseEditorTypeList(EM_EditorTypeList arg);
#define EM_reverseEditorTypeList(arg) (_EM_reverseEditorTypeList(arg))
#endif
#ifdef FAST_API
#define EM_appendEditorTypeList(arg, elem) ((EM_EditorTypeList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
EM_EditorTypeList _EM_appendEditorTypeList(EM_EditorTypeList arg, EM_EditorType elem);
#define EM_appendEditorTypeList(arg, elem) (_EM_appendEditorTypeList(arg, elem))
#endif
#ifdef FAST_API
#define EM_concatEditorTypeList(arg0, arg1) ((EM_EditorTypeList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
EM_EditorTypeList _EM_concatEditorTypeList(EM_EditorTypeList arg0, EM_EditorTypeList arg1);
#define EM_concatEditorTypeList(arg0, arg1) (_EM_concatEditorTypeList(arg0, arg1))
#endif
#ifdef FAST_API
#define EM_sliceEditorTypeList(arg, start, end) ((EM_EditorTypeList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
EM_EditorTypeList _EM_sliceEditorTypeList(EM_EditorTypeList arg, int start, int end);
#define EM_sliceEditorTypeList(arg, start, end) (_EM_sliceEditorTypeList(arg, start, end))
#endif
#ifdef FAST_API
#define EM_getEditorTypeListEditorTypeAt(arg, index) ((EM_EditorType) (ATelementAt((ATermList) arg,index)))
#else
EM_EditorType _EM_getEditorTypeListEditorTypeAt(EM_EditorTypeList arg, int index);
#define EM_getEditorTypeListEditorTypeAt(arg, index) (_EM_getEditorTypeListEditorTypeAt(arg, index))
#endif
#ifdef FAST_API
#define EM_replaceEditorTypeListEditorTypeAt(arg, elem, index) ((EM_EditorTypeList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
EM_EditorTypeList _EM_replaceEditorTypeListEditorTypeAt(EM_EditorTypeList arg, EM_EditorType elem, int index);
#define EM_replaceEditorTypeListEditorTypeAt(arg, elem, index) (_EM_replaceEditorTypeListEditorTypeAt(arg, elem, index))
#endif
#ifdef FAST_API
#define EM_makeEditorTypeList2(elem1,  elem2) ((EM_EditorTypeList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
EM_EditorTypeList _EM_makeEditorTypeList2(EM_EditorType elem1, EM_EditorType elem2);
#define EM_makeEditorTypeList2(elem1,  elem2) (_EM_makeEditorTypeList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define EM_makeEditorTypeList3(elem1, elem2,  elem3) ((EM_EditorTypeList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
EM_EditorTypeList _EM_makeEditorTypeList3(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3);
#define EM_makeEditorTypeList3(elem1, elem2,  elem3) (_EM_makeEditorTypeList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define EM_makeEditorTypeList4(elem1, elem2, elem3,  elem4) ((EM_EditorTypeList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
EM_EditorTypeList _EM_makeEditorTypeList4(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3, EM_EditorType elem4);
#define EM_makeEditorTypeList4(elem1, elem2, elem3,  elem4) (_EM_makeEditorTypeList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define EM_makeEditorTypeList5(elem1, elem2, elem3, elem4,  elem5) ((EM_EditorTypeList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
EM_EditorTypeList _EM_makeEditorTypeList5(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3, EM_EditorType elem4, EM_EditorType elem5);
#define EM_makeEditorTypeList5(elem1, elem2, elem3, elem4,  elem5) (_EM_makeEditorTypeList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define EM_makeEditorTypeList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((EM_EditorTypeList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
EM_EditorTypeList _EM_makeEditorTypeList6(EM_EditorType elem1, EM_EditorType elem2, EM_EditorType elem3, EM_EditorType elem4, EM_EditorType elem5, EM_EditorType elem6);
#define EM_makeEditorTypeList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_EM_makeEditorTypeList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
EM_Sid EM_makeSidSessionId(int id);
EM_EditorType EM_makeEditorTypeDefault(const char* name);
EM_ModuleId EM_makeModuleIdModuleId(int id);
EM_SessionStatus EM_makeSessionStatusRunning(void);
EM_SessionStatus EM_makeSessionStatusZombie(void);
EM_Session EM_makeSessionDefault(EM_Sid id, const char* path, EM_SessionStatus status, int referenceCount, EM_EditorTypeList list);
EM_EditorTypeList EM_makeEditorTypeListEmpty(void);
EM_EditorTypeList EM_makeEditorTypeListSingle(EM_EditorType head);
EM_EditorTypeList EM_makeEditorTypeListMany(EM_EditorType head, EM_EditorTypeList tail);
#ifdef FAST_API
#define EM_isEqualSid(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _EM_isEqualSid(EM_Sid arg0, EM_Sid arg1);
#define EM_isEqualSid(arg0, arg1) (_EM_isEqualSid(arg0, arg1))
#endif
#ifdef FAST_API
#define EM_isEqualEditorType(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _EM_isEqualEditorType(EM_EditorType arg0, EM_EditorType arg1);
#define EM_isEqualEditorType(arg0, arg1) (_EM_isEqualEditorType(arg0, arg1))
#endif
#ifdef FAST_API
#define EM_isEqualModuleId(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _EM_isEqualModuleId(EM_ModuleId arg0, EM_ModuleId arg1);
#define EM_isEqualModuleId(arg0, arg1) (_EM_isEqualModuleId(arg0, arg1))
#endif
#ifdef FAST_API
#define EM_isEqualSessionStatus(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _EM_isEqualSessionStatus(EM_SessionStatus arg0, EM_SessionStatus arg1);
#define EM_isEqualSessionStatus(arg0, arg1) (_EM_isEqualSessionStatus(arg0, arg1))
#endif
#ifdef FAST_API
#define EM_isEqualSession(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _EM_isEqualSession(EM_Session arg0, EM_Session arg1);
#define EM_isEqualSession(arg0, arg1) (_EM_isEqualSession(arg0, arg1))
#endif
#ifdef FAST_API
#define EM_isEqualEditorTypeList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _EM_isEqualEditorTypeList(EM_EditorTypeList arg0, EM_EditorTypeList arg1);
#define EM_isEqualEditorTypeList(arg0, arg1) (_EM_isEqualEditorTypeList(arg0, arg1))
#endif
ATbool EM_isValidSid(EM_Sid arg);
inline ATbool EM_isSidSessionId(EM_Sid arg);
ATbool EM_hasSidId(EM_Sid arg);
int EM_getSidId(EM_Sid arg);
EM_Sid EM_setSidId(EM_Sid arg, int id);
ATbool EM_isValidEditorType(EM_EditorType arg);
inline ATbool EM_isEditorTypeDefault(EM_EditorType arg);
ATbool EM_hasEditorTypeName(EM_EditorType arg);
char* EM_getEditorTypeName(EM_EditorType arg);
EM_EditorType EM_setEditorTypeName(EM_EditorType arg, const char* name);
ATbool EM_isValidModuleId(EM_ModuleId arg);
inline ATbool EM_isModuleIdModuleId(EM_ModuleId arg);
ATbool EM_hasModuleIdId(EM_ModuleId arg);
int EM_getModuleIdId(EM_ModuleId arg);
EM_ModuleId EM_setModuleIdId(EM_ModuleId arg, int id);
ATbool EM_isValidSessionStatus(EM_SessionStatus arg);
inline ATbool EM_isSessionStatusRunning(EM_SessionStatus arg);
inline ATbool EM_isSessionStatusZombie(EM_SessionStatus arg);
ATbool EM_isValidSession(EM_Session arg);
inline ATbool EM_isSessionDefault(EM_Session arg);
ATbool EM_hasSessionId(EM_Session arg);
ATbool EM_hasSessionPath(EM_Session arg);
ATbool EM_hasSessionStatus(EM_Session arg);
ATbool EM_hasSessionReferenceCount(EM_Session arg);
ATbool EM_hasSessionList(EM_Session arg);
EM_Sid EM_getSessionId(EM_Session arg);
char* EM_getSessionPath(EM_Session arg);
EM_SessionStatus EM_getSessionStatus(EM_Session arg);
int EM_getSessionReferenceCount(EM_Session arg);
EM_EditorTypeList EM_getSessionList(EM_Session arg);
EM_Session EM_setSessionId(EM_Session arg, EM_Sid id);
EM_Session EM_setSessionPath(EM_Session arg, const char* path);
EM_Session EM_setSessionStatus(EM_Session arg, EM_SessionStatus status);
EM_Session EM_setSessionReferenceCount(EM_Session arg, int referenceCount);
EM_Session EM_setSessionList(EM_Session arg, EM_EditorTypeList list);
ATbool EM_isValidEditorTypeList(EM_EditorTypeList arg);
inline ATbool EM_isEditorTypeListEmpty(EM_EditorTypeList arg);
inline ATbool EM_isEditorTypeListSingle(EM_EditorTypeList arg);
inline ATbool EM_isEditorTypeListMany(EM_EditorTypeList arg);
ATbool EM_hasEditorTypeListHead(EM_EditorTypeList arg);
ATbool EM_hasEditorTypeListTail(EM_EditorTypeList arg);
EM_EditorType EM_getEditorTypeListHead(EM_EditorTypeList arg);
EM_EditorTypeList EM_getEditorTypeListTail(EM_EditorTypeList arg);
EM_EditorTypeList EM_setEditorTypeListHead(EM_EditorTypeList arg, EM_EditorType head);
EM_EditorTypeList EM_setEditorTypeListTail(EM_EditorTypeList arg, EM_EditorTypeList tail);
EM_Sid EM_visitSid(EM_Sid arg, int (*acceptId)(int));
EM_EditorType EM_visitEditorType(EM_EditorType arg, char* (*acceptName)(char*));
EM_ModuleId EM_visitModuleId(EM_ModuleId arg, int (*acceptId)(int));
EM_SessionStatus EM_visitSessionStatus(EM_SessionStatus arg);
EM_Session EM_visitSession(EM_Session arg, EM_Sid (*acceptId)(EM_Sid), char* (*acceptPath)(char*), EM_SessionStatus (*acceptStatus)(EM_SessionStatus), int (*acceptReferenceCount)(int), EM_EditorTypeList (*acceptList)(EM_EditorTypeList));
EM_EditorTypeList EM_visitEditorTypeList(EM_EditorTypeList arg, EM_EditorType (*acceptHead)(EM_EditorType));

#endif /* _EDITORMANAGER_H */
