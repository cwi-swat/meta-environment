/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "EditorManager.h"
#include "editor-manager.tif.h"

/*}}}  */
/*{{{  defines */

#define INITIAL_TABLE_SIZE 100
#define TABLE_RESIZE_PERCENTAGE 75

/*}}}  */
/*{{{  variables */

static ATermTable sessions = NULL;
char editor_manager_id[] = "$Id$";

/*}}}  */

/*{{{  static EM_Sid makeUniqueSessionId() */

static EM_Sid makeUniqueSessionId()
{
  static int id = 0;

  return EM_makeSidDefault(id++);
}

/*}}}  */
/*{{{  static ATerm sndValue(ATerm result) */

static ATerm sndValue(ATerm result)
{
  assert(result);

  return ATmake("snd-value(<term>)", result);
}

/*}}}  */

/*{{{  static EM_Session getSession(ATerm sid) */

static EM_Session getSession(ATerm sid)
{
  assert(sid != NULL);

  return EM_SessionFromTerm(ATtableGet(sessions, sid));
}

/*}}}  */
/*{{{  static void putSession(ATerm sid, EM_Session session) */

static void putSession(EM_Session session)
{
  EM_Sid sid;

  assert(session != NULL);

  sid = EM_getSessionId(session);
  ATtablePut(sessions, EM_SidToTerm(sid), EM_SessionToTerm(session));
}

/*}}}  */
/*{{{  static EM_Session findSession(const char *filename, const char *modulename) */

static EM_Session findSession(const char *filename, const char *modulename)
{
  ATermList sessionList;

  assert(filename != NULL);
  assert(modulename != NULL);

  sessionList = ATtableValues(sessions);
  while (!ATisEmpty(sessionList)) {
    EM_Session session = EM_SessionFromTerm(ATgetFirst(sessionList));
    const char *peerFilename = EM_getSessionFilename(session);
    const char *peerModulename = EM_getSessionModulename(session);
    if (strcmp(peerFilename, filename) == 0
	&& strcmp(peerModulename, modulename) == 0)
    {
      return session;
    }
    sessionList = ATgetNext(sessionList);
  }

  return NULL;
}

/*}}}  */

/*{{{  ATerm get_session(int cid, const char *filename, const char *modulename) */

ATerm get_session(int cid, const char *filename, const char *modulename)
{
  EM_Session session;
  EM_Sid sid;

  assert(filename != NULL);
  assert(modulename != NULL);

  session = findSession(filename, modulename);
  if (session == NULL) {
    session = EM_makeSessionDefault(makeUniqueSessionId(),
				    filename,
				    modulename,
				    EM_makeEditorTypeListEmpty());
    putSession(session);
  }

  sid = EM_getSessionId(session);

  return sndValue(ATmake("session(<term>)", EM_SidToTerm(sid)));
}

/*}}}  */
/*{{{  ATerm get_filename(int cid, ATerm sid) */

ATerm get_filename(int cid, ATerm sid)
{
  EM_Session session;
  const char *filename;

  assert(sid != NULL);

  session = getSession(sid);
  if (session == NULL) {
    return sndValue(ATmake("no-such-session"));
  }

  filename = EM_getSessionFilename(session);
  return sndValue(ATmake("filename(<str>)", filename));
}

/*}}}  */
/*{{{  ATerm get_modulename(int cid, ATerm sid) */

ATerm get_modulename(int cid, ATerm sid)
{
  EM_Session session;
  const char *modulename;

  assert(sid != NULL);

  session = getSession(sid);
  if (session == NULL) {
    return sndValue(ATmake("no-such-session"));
  }

  modulename = EM_getSessionModulename(session);
  return sndValue(ATmake("modulename(<str>)", modulename));
}

/*}}}  */
/*{{{  void register_editor(int cid, ATerm sid, ATerm editorType) */

void register_editor(int cid, ATerm sid, ATerm editorType)
{
  EM_Session session;

  assert(sid != NULL);

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
    types = EM_makeEditorTypeListMany(type, types);
    putSession(EM_setSessionList(session, types));
  }
}

/*}}}  */
/*{{{  ATerm is_editor_registered(int cid, ATerm sid, ATerm editorType) */

ATerm is_editor_registered(int cid, ATerm sid, ATerm editorType)
{
  EM_Session session;

  assert(sid != NULL);

  session = getSession(sid);
  if (session != NULL) {
    EM_EditorType type = EM_EditorTypeFromTerm(editorType);
    EM_EditorTypeList types = EM_getSessionList(session);
    while (!EM_isEditorTypeListEmpty(types)) {
      EM_EditorType cur = EM_getEditorTypeListHead(types);
      if (EM_isEqualEditorType(cur, type)) {
	return sndValue(ATmake("editor-registered"));
      }
    }
    return sndValue(ATmake("editor-not-registered"));
  }
  return sndValue(ATmake("no-such-session"));
}

/*}}}  */
/*{{{  void unregister_editor(int cid, ATerm sid, ATerm editorType) */

void unregister_editor(int cid, ATerm sid, ATerm editorType)
{
  EM_Session session;

  assert(sid != NULL);

  session = getSession(sid);
  if (session != NULL) {
    EM_EditorType type = EM_EditorTypeFromTerm(editorType);
    EM_EditorTypeList types = EM_getSessionList(session);
    EM_EditorTypeList stripped = EM_makeEditorTypeListEmpty();
    while (!EM_isEditorTypeListEmpty(types)) {
      EM_EditorType cur = EM_getEditorTypeListHead(types);
      if (!EM_isEqualEditorType(cur, type)) {
	stripped = EM_makeEditorTypeListMany(type, stripped);
      }
      types = EM_getEditorTypeListTail(types);
    }
    if (EM_isEqualEditorTypeList(stripped, EM_getSessionList(session))) {
      ATabort("unregister_editor: no such registered type: %t\n", editorType);
    }
    putSession(EM_setSessionList(session, stripped));
  }
}

/*}}}  */
/*{{{  ATerm get_session_ids(int cid, const char *modulename) */

ATerm get_session_ids(int cid, const char *modulename)
{
  ATermList result;
  ATermList sessionList;

  assert(modulename != NULL);

  result = ATempty;
  sessionList = ATtableValues(sessions);
  while (!ATisEmpty(sessionList)) {
    EM_Session session = EM_SessionFromTerm(ATgetFirst(sessionList));
    const char *peerModulename = EM_getSessionModulename(session);
    if (strcmp(peerModulename, modulename) == 0) {
      EM_Sid sid = EM_getSessionId(session);
      result = ATinsert(result, EM_SidToTerm(sid));
    }
  }

  return sndValue(ATmake("session-ids(<list>)", result));
}

/*}}}  */
/*{{{  void delete_session(int cid, ATerm sid) */

void delete_session(int cid, ATerm sid)
{
  EM_Session session;

  assert(sid != NULL);

  session = getSession(sid);
  if (session == NULL) {
    ATabort("delete_session: no such session: %t\n", sid);
  }

  ATtableRemove(sessions, sid);
}

/*}}}  */
/*{{{  void rec_terminate(int cid, ATerm msg) */

void rec_terminate(int cid, ATerm msg)
{
  exit(0);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  int cid;

  ATBinit(argc, argv, &bottomOfStack);

  sessions = ATtableCreate(INITIAL_TABLE_SIZE, TABLE_RESIZE_PERCENTAGE);

  cid = ATBconnect(NULL, NULL, -1, editor_manager_handler);

  return ATBeventloop();
}

/*}}}  */
