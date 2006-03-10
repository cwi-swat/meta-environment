#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "EditorManager.h"
#include "editor-manager.tif.h"

#define INITIAL_TABLE_SIZE 100
#define TABLE_RESIZE_PERCENTAGE 75

char editor_manager_id[] = "$Id$";

static ATermTable sessions = NULL;
static ATermTable bindings = NULL;

static EM_Sid makeUniqueSessionId() {
  static int id = 0;

  return EM_makeSidDefault(id++);
}

static ATerm sndValue(ATerm result) {
  assert(result != NULL);

  return ATmake("snd-value(<term>)", result);
}

static EM_Session getSession(ATerm sid) {
  assert(sid != NULL);

  return EM_SessionFromTerm(ATtableGet(sessions, sid));
}

static void putSession(EM_Session session) {
  EM_Sid sid;

  assert(session != NULL);

  sid = EM_getSessionId(session);
  ATtablePut(sessions, EM_SidToTerm(sid), EM_SessionToTerm(session));
}

static EM_Session findSession(const char *path) {
  ATermList sessionList;

  assert(path != NULL);

  sessionList = ATtableValues(sessions);
  while (!ATisEmpty(sessionList)) {
    EM_Session session = EM_SessionFromTerm(ATgetFirst(sessionList));
    const char *peerPath = EM_getSessionPath(session);
    if (strcmp(peerPath, path) == 0) {
      return session;
    }
    sessionList = ATgetNext(sessionList);
  }

  return NULL;
}

static ATermList findSessions(ATerm moduleId) {
  ATermList result;
  ATermList bindingList;
  EM_ModuleId needle;

  assert(moduleId != NULL);

  result = ATempty;
  needle = EM_ModuleIdFromTerm(moduleId);
  bindingList = ATtableKeys(bindings);
  while (!ATisEmpty(bindingList)) {
    EM_Sid cur = EM_SidFromTerm(ATgetFirst(bindingList));
    EM_ModuleId peer = EM_ModuleIdFromTerm(ATtableGet(bindings,
						      EM_SidToTerm(cur)));
    if (EM_isEqualModuleId(peer, needle)) {
      result = ATinsert(result, EM_SidToTerm(cur));
    }
    bindingList = ATgetNext(bindingList);
  }

  return result;
}

static EM_ModuleId getModuleId(ATerm sid) {
  assert(sid != NULL);

  return EM_ModuleIdFromTerm(ATtableGet(bindings, sid));
}

static void putModuleId(ATerm sid, EM_ModuleId moduleId) {
  assert(sid != NULL);
  assert(moduleId != NULL);

  ATtablePut(bindings, sid, EM_ModuleIdToTerm(moduleId));
}

ATerm create_session(int cid, const char *path) {
  EM_Session session;

  assert(path != NULL);

  session = findSession(path);
  if (session == NULL) {
    EM_Sid sid = makeUniqueSessionId();
    EM_EditorTypeList list = EM_makeEditorTypeListEmpty();
    EM_SessionStatus status = EM_makeSessionStatusRunning();
    session = EM_makeSessionDefault(sid, path, status, 0, list);
    putSession(session);
  }

  return sndValue(ATmake("session(<term>)", EM_getSessionId(session)));
}

ATerm bind_session(int cid, ATerm sid, ATerm moduleId) {
  assert(sid != NULL);
  assert(moduleId != NULL);

  if (getSession(sid) == NULL) {
    return sndValue(ATmake("no-such-session"));
  }
  else {
    EM_ModuleId id = getModuleId(sid);
    EM_ModuleId module = EM_ModuleIdFromTerm(moduleId);
    if (id != NULL && EM_isEqualModuleId(module, id) != 0) {
      ATabort("editor-manager:bind_session: attempt to rebind %t (%t)\n",
	      sid, moduleId);
    }
    putModuleId(sid, module);

    return sndValue(ATmake("session-bound"));
  }
}

ATerm get_session_by_path(int cid, const char *path) {
  EM_Session session;
  EM_Sid sid;

  assert(path != NULL);

  session = findSession(path);
  if (session == NULL) {
    return sndValue(ATmake("no-such-session"));
  }

  sid = EM_getSessionId(session);
  return sndValue(ATmake("session(<term>)", EM_SidToTerm(sid)));
}

ATerm get_sessions_by_moduleid(int cid, ATerm moduleId) {
  ATermList sessions = findSessions(moduleId);
  return sndValue(ATmake("sessions(<term>)", sessions));
}

void delete_session(int cid, ATerm sid) {
  EM_Session session = getSession(sid);

  if (session != NULL) {
    int referenceCount = EM_getSessionReferenceCount(session);
    if (referenceCount == 0) {
      ATtableRemove(sessions, sid);
      ATtableRemove(bindings, sid);
    }
    else {
      putSession(EM_setSessionStatus(session, EM_makeSessionStatusZombie()));
    }
  }
  else {
    ATabort("delete_session: no such session: %t\n", sid);
  }
}

ATerm get_path(int cid, ATerm sid) {
  EM_Session session;
  const char *path;

  session = getSession(sid);
  if (session == NULL) {
    return sndValue(ATmake("no-such-session"));
  }

  path = EM_getSessionPath(session);
  return sndValue(ATmake("path(<str>)", path));
}

ATerm get_moduleid(int cid, ATerm sid) {
  EM_Session session;
  EM_ModuleId moduleId;

  session = getSession(sid);
  if (session == NULL) {
    return sndValue(ATmake("no-such-session"));
  }

  moduleId = getModuleId(sid);
  if (moduleId == NULL) {
    return sndValue(ATmake("session-not-bound"));
  }
  else {
    return sndValue(ATmake("moduleid(<term>)", moduleId));
  }
}

void register_editor(int cid, ATerm sid, ATerm editorType) {
  EM_Session session;

  session = getSession(sid);
  if (session != NULL) {
    EM_EditorType type = EM_EditorTypeFromTerm(editorType);
    EM_EditorTypeList types = EM_getSessionList(session);
    while (!EM_isEditorTypeListEmpty(types)) {
      EM_EditorType cur = EM_getEditorTypeListHead(types);
      if (EM_isEqualEditorType(cur, type)) {
	ATabort("register_editor: type already registered: %t\n", editorType);
      }
      types = EM_getEditorTypeListTail(types);
    }
    types = EM_makeEditorTypeListMany(type, EM_getSessionList(session));
    putSession(EM_setSessionList(session, types));
  }
}

ATerm is_editor_registered(int cid, ATerm sid, ATerm editorType) {
  EM_Session session;

  session = getSession(sid);
  if (session != NULL) {
    EM_EditorType type = EM_EditorTypeFromTerm(editorType);
    EM_EditorTypeList types = EM_getSessionList(session);
    while (!EM_isEditorTypeListEmpty(types)) {
      EM_EditorType cur = EM_getEditorTypeListHead(types);
      if (EM_isEqualEditorType(cur, type)) {
	return sndValue(ATmake("editor-registered"));
      }
      types = EM_getEditorTypeListTail(types);
    }
    return sndValue(ATmake("editor-not-registered"));
  }
  return sndValue(ATmake("no-such-session"));
}

void unregister_editor(int cid, ATerm sid, ATerm editorType) {
  EM_Session session;

  session = getSession(sid);
  if (session != NULL) {
    EM_EditorType type = EM_EditorTypeFromTerm(editorType);
    EM_EditorTypeList types = EM_getSessionList(session);
    EM_EditorTypeList stripped = EM_makeEditorTypeListEmpty();
    while (!EM_isEditorTypeListEmpty(types)) {
      EM_EditorType cur = EM_getEditorTypeListHead(types);
      if (!EM_isEqualEditorType(cur, type)) {
	stripped = EM_makeEditorTypeListMany(cur, stripped);
      }
      types = EM_getEditorTypeListTail(types);
    }
    if (EM_isEqualEditorTypeList(stripped, EM_getSessionList(session))) {
      ATabort("unregister_editor: no such registered type: %t\n", editorType);
    }
    putSession(EM_setSessionList(session, stripped));
  }
}

ATerm request_transaction(int cid, ATerm sid) {
  EM_Session session = getSession(sid);

  if (session != NULL) {
    EM_SessionStatus status = EM_getSessionStatus(session);
    if (EM_isSessionStatusRunning(status)) {
      int referenceCount = EM_getSessionReferenceCount(session);
      assert(referenceCount >= 0);

      referenceCount++;
      session = EM_setSessionReferenceCount(session, referenceCount);
      putSession(session);
      return sndValue(ATparse("transaction-started"));
    }
  }

  return sndValue(ATparse("no-transaction"));
}

void end_transaction(int cid, ATerm sid) {
  EM_Session session = getSession(sid);

  if (session != NULL) {
    int referenceCount = EM_getSessionReferenceCount(session);
    assert(referenceCount > 0);

    referenceCount--;
    session = EM_setSessionReferenceCount(session, referenceCount);
    putSession(session);

    if (referenceCount == 0) {
      EM_SessionStatus status = EM_getSessionStatus(session);
      if (EM_isSessionStatusZombie(status)) {
	ATtableRemove(sessions, sid);
      }
    }
  }
  else {
    ATabort("editor-manager.c:end_transaction: no such session %t\n", sid);
  }
}

void rec_terminate(int cid, ATerm msg) {
  exit(0);
}

int main(int argc, char *argv[]) {
  ATerm bottomOfStack;
  int cid;

  ATBinit(argc, argv, &bottomOfStack);
  EM_initEditorManagerApi();

  sessions = ATtableCreate(INITIAL_TABLE_SIZE, TABLE_RESIZE_PERCENTAGE);
  bindings = ATtableCreate(INITIAL_TABLE_SIZE, TABLE_RESIZE_PERCENTAGE);

  cid = ATBconnect(NULL, NULL, -1, editor_manager_handler);

  return ATBeventloop();
}
