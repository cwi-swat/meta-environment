/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <aterm2.h>

#include <MEPT-utils.h>
#include <Location.h>

#include "StructureEditor.h"

#include "structure-editor.tif.h"

/*}}}  */

/*{{{  variables */

static ATermTable editors = NULL;

/*}}}  */

/*{{{  static void assertParseTreeHasPosInfo(PT_ParseTree parseTree) */

static void assertParseTreeHasPosInfo(PT_ParseTree parseTree)
{
  PT_Tree tree = PT_getParseTreeTop(parseTree);
  if (PT_getTreeLocation(tree) == NULL) {
    ATerror("structure-editor.c: cannot edit parsetree without posinfo!\n");
  }
}

/*}}}  */

/*{{{  void create_editor(int cid, ATerm editorId, ATerm parseTreeTerm) */

void create_editor(int cid, ATerm editorId, ATerm parseTreeTerm)
{
  PT_ParseTree parseTree;
  SE_StructureEditor editor;

  parseTree = PT_ParseTreeFromTerm(ATBunpack(parseTreeTerm));
  assertParseTreeHasPosInfo(parseTree);

  editor = SE_makeStructureEditorUnedited(parseTree);
  ATtablePut(editors, editorId, SE_StructureEditorToTerm(editor));
}

/*}}}  */
/*{{{  void update_editor(int cid, ATerm editorId, ATerm parseTreeTerm) */

void update_editor(int cid, ATerm editorId, ATerm parseTreeTerm)
{
  SE_StructureEditor editor;

  editor = SE_StructureEditorFromTerm(ATtableGet(editors, editorId));
  if (editor != NULL) {
    PT_ParseTree parseTree = PT_ParseTreeFromTerm(ATBunpack(parseTreeTerm));
    assertParseTreeHasPosInfo(parseTree);
    editor = SE_setStructureEditorParseTree(editor, parseTree);
    ATtablePut(editors, editorId, SE_StructureEditorToTerm(editor));
  }
}

/*}}}  */
/*{{{  void delete_editor(int cid, ATerm editorId) */

void delete_editor(int cid, ATerm editorId)
{
  ATerm editor;

  editor = ATtableGet(editors, editorId);
  if (editor != NULL) {
    ATtableRemove(editors, editor);
  }
}

/*}}}  */
/*{{{  void set_cursor_at_offset(int cid, ATerm editorId, int offset) */

void set_cursor_at_offset(int cid, ATerm editorId, int offset)
{
  SE_StructureEditor editor;

  editor = SE_StructureEditorFromTerm(ATtableGet(editors, editorId));
  if (editor != NULL) {
    PT_ParseTree parseTree = SE_getStructureEditorParseTree(editor);
    PT_Tree tree = PT_getParseTreeTop(parseTree);
    PT_Tree cursor = PT_findTreeAtOffset(tree, offset);
    if (cursor == NULL) {
      cursor = tree;
    }
    editor = SE_makeStructureEditorDefault(parseTree, cursor);
    ATtablePut(editors, editorId, SE_StructureEditorToTerm(editor));
  }
  else {
    ATwarning("set_cursor_at_offset: no such editor: %t\n", editorId);
  }
}

/*}}}  */
/*{{{  ATerm get_focus_at_cursor(int cid, ATerm editorId) */

ATerm get_focus_at_cursor(int cid, ATerm editorId)
{
  SE_StructureEditor editor;

  editor = SE_StructureEditorFromTerm(ATtableGet(editors, editorId));
  if (editor != NULL) {
    if (SE_hasStructureEditorCursor(editor)) {
      SE_Tree cursor = SE_getStructureEditorCursor(editor);
      LOC_Location location = PT_getTreeLocation(cursor);
      LOC_Area area = LOC_getLocationArea(location);
      return ATmake("snd-value(focus(<term>))", area);
    }

    ATwarning("get_focus_at_cursor: no cursor yet in %t\n", editorId);
    return NULL;
  }

  ATwarning("get_focus_at_cursor: no such editor: %t\n", editorId);
  return NULL;
}

/*}}}  */
/*{{{  void move_cursor(int cid, ATerm editorId, ATerm direction) */

void move_cursor(int cid, ATerm editorId, ATerm direction)
{
}

/*}}}  */
/*{{{  void rec_terminate(int cid, ATerm message) */

void rec_terminate(int cid, ATerm message)
{
  ATwarning("structure-editor.c:rec_terminate: %t\n", message);
  exit(0);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  int cid;

  ATBinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  LOC_initLocationApi();
  SE_initStructureEditorApi();

  editors = ATtableCreate(100, 75);

  cid = ATBconnect(NULL, NULL, -1, structure_editor_handler);
  return ATBeventloop();
}

/*}}}  */
