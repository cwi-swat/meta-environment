/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <aterm2.h>

#include "editor-manager.tif.h"

/*}}}  */
/*{{{  defines */

#define	POS_ID     0
#define	POS_NAME   1
#define	POS_MODULE 2


/*}}}  */
/*{{{  CVS-id */

char editor_manager_id[] = "$Id$";

/*}}}  */
/*{{{  variables */

static ATermList editors = NULL;

/*}}}  */

/*{{{  static ATerm getUniqueId() */

static ATerm getUniqueId()
{
  static int id = 0;

  return ATmake("eid(<int>)", id++);
}

/*}}}  */
/*{{{  static ATerm nameStringToTerm(const char *name) */

static ATerm nameStringToTerm(const char *name)
{
  assert(name);

  return ATmake("name(<str>)", name);
}

/*}}}  */
/*{{{  static ATerm moduleStringToTerm(const char *module) */

static ATerm moduleStringToTerm(const char *module)
{
  assert(module);

  return ATmake("module(<str>)", module);
}

/*}}}  */
/*{{{  static ATerm newEditor(ATerm id, ATerm name, ATerm module) */

static ATerm newEditor(ATerm id, ATerm name, ATerm module)
{
  assert(id && name);

  return ATmake("editor(<term>,<term>,<term>)", id, name, module);
}

/*}}}  */
/*{{{  static ATerm getEditorId(ATerm editor) */

static ATerm getEditorId(ATerm editor)
{
  assert(editor);

  return ATgetArgument((ATermAppl) editor, POS_ID);
}

/*}}}  */
/*{{{  static ATerm getEditorName(ATerm editor) */

static ATerm getEditorName(ATerm editor)
{
  assert(editor);

  return (ATerm) ATgetArgument((ATermAppl) editor, POS_NAME);
}

/*}}}  */
/*{{{  static ATerm getModule(ATerm editor) */

static ATerm getModule(ATerm editor)
{
  assert(editor);

  return (ATerm) ATgetArgument((ATermAppl) editor, POS_MODULE);
}

/*}}}  */
/*{{{  static ATerm getEditorByName(ATerm name) */

static ATerm getEditorByName(ATerm name)
{
  ATermList list;

  assert(name && editors);

  list = editors;

  while (!ATisEmpty(list)) {
    ATerm entry = ATgetFirst(list);
    ATerm curName = getEditorName(entry);

    if (ATisEqual(curName, name)) {
      return entry;
    }
    list = ATgetNext(list);
  }

  return NULL;
}

/*}}}  */
/*{{{  static ATerm getEditorById(ATerm id) */

static ATerm getEditorById(ATerm id)
{
  ATermList list;

  assert(editors);

  list = editors;

  while (!ATisEmpty(list)) {
    ATerm entry = ATgetFirst(list);
    ATerm curId = getEditorId(entry);

    if (ATisEqual(curId, id)) {
      return entry;
    }
    list = ATgetNext(list);
  }

  return NULL;
}

/*}}}  */
/*{{{  static ATermList getEditorsByModule(ATerm module) */

static ATermList getEditorsByModule(ATerm module)
{
  ATermList list;
  ATermList result;

  assert(editors);

  list   = editors;
  result = ATempty;

  while (!ATisEmpty(list)) {
    ATerm entry = ATgetFirst(list);
    if (ATisEqual(getModule(entry), module)) {
      result = ATinsert(result, getEditorId(entry));
    }
    list = ATgetNext(list);
  }

  return result;
}

/*}}}  */
/*{{{  static void addEditor(ATerm editor) */

static void addEditor(ATerm editor)
{
  assert(editor && editors);

  editors = ATinsert(editors, editor);
}

/*}}}  */
/*{{{  static void removeEditor(ATerm editor) */

static void removeEditor(ATerm editor)
{
  assert(editor && editors);

  editors = ATremoveElement(editors, editor);
}

/*}}}  */
/*{{{  static ATerm sndValue(ATerm result) */

static ATerm sndValue(ATerm result)
{
  assert(result);

  return ATmake("snd-value(<term>)", result);
}

/*}}}  */

/*{{{  ATerm get_editor_id(int conn, char *nameAsString, char *moduleAsString) */

ATerm get_editor_id(int conn, char *nameAsString, char *moduleAsString)
{
  ATerm editor;
  ATerm editorId;
  ATerm nameAsTerm;
  ATerm moduleAsTerm;

  assert(nameAsString);

  nameAsTerm = nameStringToTerm(nameAsString);
  editor = getEditorByName(nameAsTerm);

  if (editor != NULL) {
    editorId = getEditorId(editor);
    return sndValue(ATmake("existing-editor(<term>)", editorId));
  }

  editorId = getUniqueId();
  moduleAsTerm = moduleStringToTerm(moduleAsString);
  addEditor(newEditor(editorId, nameAsTerm, moduleAsTerm));

  return sndValue(ATmake("new-editor(<term>)", editorId));
}

/*}}}  */
ATerm get_editor_name(int conn, ATerm editorId)
{
  ATerm editor;
  ATerm nameTerm;
  char *name;

  editor = getEditorById(editorId);
  nameTerm = getEditorName(editor);
  ATmatch(nameTerm,"name(<str>)", &name);  

  return ATmake("snd-value(editor-name(<str>))", name);
}
/*{{{  void delete_editor(int conn, ATerm editorId) */

void delete_editor(int conn, ATerm editorId)
{
  ATerm editor;

  assert(editors && editorId);

  editor = getEditorById(editorId);

  if (editor == NULL) {
    ATwarning("editor-manager: no such editor: %t\n", editorId);
    return;
  }

  removeEditor(editor);
}

/*}}}  */
/*{{{  ATerm get_editors_by_module(int conn, char *moduleAsString) */

ATerm get_editors_by_module(int conn, char *moduleAsString)
{
  ATerm moduleAsTerm;
  ATermList editorsByModule;

  assert(moduleAsString);

  moduleAsTerm    = moduleStringToTerm(moduleAsString);
  editorsByModule = getEditorsByModule(moduleAsTerm);

  return sndValue(ATmake("editors-by-module([<list>])", editorsByModule));
}

/*}}}  */

/*{{{  rec_terminate(int conn, ATerm reason) */

void
rec_terminate(int conn, ATerm reason)
{
  exit(0);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int cid;
  ATerm bottomOfStack;

  ATBinit(argc, argv, &bottomOfStack);

  editors = ATempty;
  ATprotect((ATerm *) &editors);

  cid = ATBconnect(NULL, NULL, -1, editor_manager_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
