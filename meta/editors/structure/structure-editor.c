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
/*{{{  static LOC_Area getAreaAtOffset(PT_Tree tree, int offset) */

static LOC_Area getAreaAtOffset(PT_Tree tree, int offset)
{
  LOC_Location location;

  assert(tree != NULL);
  assert(offset >= 0);

  location = PT_findLocationAtOffset(tree, offset);
  if (location != NULL) {
    return LOC_getLocationArea(location);
  }

  return NULL;
}

/*}}}  */

/*{{{  void create_editor(int cid, ATerm editorId, ATerm parseTreeTerm) */

void create_editor(int cid, ATerm editorId, ATerm parseTreeTerm)
{
  PT_ParseTree parseTree;
  SE_StructureEditor editor;

  parseTree = PT_ParseTreeFromTerm(parseTreeTerm);
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
    PT_ParseTree parseTree = PT_ParseTreeFromTerm(parseTreeTerm);
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
    editor = SE_setStructureEditorCursor(editor, offset);
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
      int cursor = SE_getStructureEditorCursor(editor);
      PT_ParseTree parseTree = SE_getStructureEditorParseTree(editor);
      PT_Tree tree = PT_getParseTreeTop(parseTree);
      LOC_Area area = getAreaAtOffset(tree, cursor);
      return ATmake("snd-value(focus(<term>))", area);
    }

    ATwarning("get_focus_at_cursor: no cursor yet in %t\n", editorId);
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

  ATBinit(argc, argv, &bottomOfStack);

  editors = ATtableCreate(100, 75);

  return 0;
}

/*}}}  */
