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

/*{{{  static SE_StructureEditor getEditor(ATerm editorId) */

static SE_StructureEditor getEditor(ATerm editorId)
{
  assert(editorId != NULL);

  return SE_StructureEditorFromTerm(ATtableGet(editors, editorId));
}

/*}}}  */
/*{{{  static void setEditor(ATerm editorId, SE_StructureEditor editor) */

static void setEditor(ATerm editorId, SE_StructureEditor editor)
{
  assert(editorId != NULL);
  assert(editor != NULL);

  return ATtablePut(editors, editorId, SE_StructureEditorToTerm(editor));
}

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

/*{{{  static SE_StructureEditor moveCursorUp(SE_StructureEditor editor) */

static SE_StructureEditor moveCursorUp(SE_StructureEditor editor)
{
  PT_ParseTree parseTree;
  PT_Tree cursor;
  PT_Tree tree;

  assert(editor != NULL);

  parseTree = SE_getStructureEditorParseTree(editor);
  tree = PT_getParseTreeTop(parseTree);

  cursor = SE_getStructureEditorCursor(editor);
  if (!PT_isEqualTree(tree, cursor)) {
    PT_Tree parent = PT_findTreeParent(cursor, tree);
    editor = SE_setStructureEditorCursor(editor, parent);
  }

  return editor;
}

/*}}}  */
/*{{{  static SE_StructureEditor moveCursorDown(SE_StructureEditor editor) */

static SE_StructureEditor moveCursorDown(SE_StructureEditor editor)
{
  PT_ParseTree parseTree;
  PT_Tree cursor;
  PT_Tree tree;

  assert(editor != NULL);

  parseTree = SE_getStructureEditorParseTree(editor);
  tree = PT_getParseTreeTop(parseTree);
  cursor = SE_getStructureEditorCursor(editor);
  if (PT_hasTreeArgs(cursor)) {
    PT_Args children = PT_findArgsWithLocation(PT_getTreeArgs(cursor));
    if (!PT_isArgsEmpty(children)) {
      PT_Tree child = PT_getArgsHead(children);
      return SE_setStructureEditorCursor(editor, child);
    }
  }

  return editor;
}

/*}}}  */
/*{{{  static SE_StructureEditor moveCursorLeft(SE_StructureEditor editor) */

static SE_StructureEditor moveCursorLeft(SE_StructureEditor editor)
{
  PT_ParseTree parseTree;
  PT_Tree cursor;
  PT_Tree tree;

  assert(editor != NULL);

  parseTree = SE_getStructureEditorParseTree(editor);
  tree = PT_getParseTreeTop(parseTree);

  cursor = SE_getStructureEditorCursor(editor);
  if (!PT_isEqualTree(tree, cursor)) {
    PT_Tree parent = PT_findTreeParent(cursor, tree);
    PT_Args siblings = PT_findArgsWithLocation(PT_getTreeArgs(parent));
    PT_Tree prev = PT_getArgsHead(siblings);
    if (PT_isEqualTree(prev, cursor)) {
      return moveCursorUp(editor);
    }
    while (!PT_isArgsEmpty(siblings)) {
      PT_Tree sibling = PT_getArgsHead(siblings);
      if (PT_isEqualTree(sibling, cursor)) {
	return SE_setStructureEditorCursor(editor, prev);
      }
      prev = sibling;
      siblings = PT_findArgsWithLocation(PT_getArgsTail(siblings));
    }
  }

  return editor;
}

/*}}}  */
/*{{{  static SE_StructureEditor moveCursorRight(SE_StructureEditor editor) */

static SE_StructureEditor moveCursorRight(SE_StructureEditor editor)
{
  PT_ParseTree parseTree;
  PT_Tree cursor;
  PT_Tree tree;
  PT_Args siblings;

  assert(editor != NULL);

  parseTree = SE_getStructureEditorParseTree(editor);
  tree = PT_getParseTreeTop(parseTree);

  cursor = SE_getStructureEditorCursor(editor);
  if (!PT_isEqualTree(tree, cursor)) {
    PT_Tree parent = PT_findTreeParent(cursor, tree);
    siblings = PT_findArgsWithLocation(PT_getTreeArgs(parent));
    
    while (!PT_isArgsEmpty(siblings)) {
      PT_Tree sibling = PT_getArgsHead(siblings);
      siblings = PT_findArgsWithLocation(PT_getArgsTail(siblings));
      if (PT_isEqualTree(sibling, cursor) && !PT_isArgsEmpty(siblings)) {
	PT_Tree next = PT_getArgsHead(siblings);
	return SE_setStructureEditorCursor(editor, next);
      }
    }
  }

  return moveCursorUp(editor);
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

  editor = getEditor(editorId);
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

  editor = getEditor(editorId);
  if (editor != NULL) {
    PT_ParseTree parseTree = SE_getStructureEditorParseTree(editor);
    PT_Tree tree = PT_getParseTreeTop(parseTree);
    PT_Tree cursor = PT_findTreeAtOffset(tree, offset);
    if (cursor == NULL) {
      cursor = tree;
    }
    editor = SE_makeStructureEditorDefault(parseTree, cursor);
    setEditor(editorId, editor);
  }
  else {
    ATwarning("set_cursor_at_offset: no such editor: %t\n", editorId);
  }
}

/*}}}  */
/*{{{  ATerm get_focus_at_cursor(int cid, ATerm editorId) */

ATerm get_focus_at_cursor(int cid, ATerm editorId)
{
  SE_StructureEditor editor = getEditor(editorId);

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
/*{{{  void move_cursor(int cid, ATerm editorId, ATerm move) */

void move_cursor(int cid, ATerm editorId, ATerm move)
{
  SE_Direction direction = SE_DirectionFromTerm(move);
  SE_StructureEditor editor = getEditor(editorId);

  if (SE_isEqualDirection(direction, SE_makeDirectionUp())) {
    editor = moveCursorUp(editor);
  }
  else if (SE_isEqualDirection(direction, SE_makeDirectionDown())) {
    editor = moveCursorDown(editor);
  }
  else if (SE_isEqualDirection(direction, SE_makeDirectionLeft())) {
    editor = moveCursorLeft(editor);
  }
  else if (SE_isEqualDirection(direction, SE_makeDirectionRight())) {
    editor = moveCursorRight(editor);
  }
  else {
    ATwarning("move-up: %t\n", SE_makeDirectionUp());
    ATabort("move_cursor: illegal move: %t\n", direction);
  }

  setEditor(editorId, editor);
}

/*}}}  */
/*{{{  void rec_terminate(int cid, ATerm message) */

void rec_terminate(int cid, ATerm message)
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
  PT_initMEPTApi();
  LOC_initLocationApi();
  SE_initStructureEditorApi();

  editors = ATtableCreate(100, 75);

  cid = ATBconnect(NULL, NULL, -1, structure_editor_handler);
  return ATBeventloop();
}

/*}}}  */
