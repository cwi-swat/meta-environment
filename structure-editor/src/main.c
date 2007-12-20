/* $Id$ */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <aterm2.h>
#include <MEPT-utils.h>
#include <Location.h>

#include "StructureEditor.h"
#include "slice-tree.h"

#include "structure-editor.h"

#define SORT_AMBIGUOUS "<ambiguous>"
#define SORT_CYCLE "<cycle>"
#define SORT_UNKNOWN "<unknown>"

static ATermTable editors = NULL;

static SE_StructureEditor getEditor(ATerm editorId) {
  assert(editorId != NULL);

  return SE_StructureEditorFromTerm(ATtableGet(editors, editorId));
}

static void setEditor(ATerm editorId, SE_StructureEditor editor) {
  assert(editorId != NULL);
  assert(editor != NULL);

  ATtablePut(editors, editorId, SE_StructureEditorToTerm(editor));
}

static void assertParseTreeHasPosInfo(PT_ParseTree parseTree) {
  PT_Tree tree;

  assert(parseTree != NULL);
  assert(PT_isValidParseTree(parseTree));

  tree = PT_getParseTreeTop(parseTree);
  assert(tree != NULL);
  assert(PT_isValidTree(tree));

  if (PT_getTreeLocation(tree) == NULL) {
    ATerror("structure-editor.c: cannot edit parsetree without posinfo!\n");
  }
}

static SE_StructureEditor moveCursorUp(SE_StructureEditor editor) {
  PT_ParseTree parseTree;
  PT_Tree tree;

  assert(editor != NULL);

  parseTree = SE_getStructureEditorParseTree(editor);
  tree = PT_getParseTreeTop(parseTree);

  if (SE_hasStructureEditorCursor(editor)) {
    PT_Tree cursor = SE_getStructureEditorCursor(editor);
    if (!PT_isEqualTree(tree, cursor)) {
      PT_Tree parent = PT_findTreeParent(cursor, tree);
      editor = SE_setStructureEditorCursor(editor, parent);
    }
  }

  return editor;
}

static SE_StructureEditor moveCursorDown(SE_StructureEditor editor) {
  PT_ParseTree parseTree;
  PT_Tree tree;

  assert(editor != NULL);

  parseTree = SE_getStructureEditorParseTree(editor);
  tree = PT_getParseTreeTop(parseTree);
  if (SE_hasStructureEditorCursor(editor)) {
    PT_Tree cursor = SE_getStructureEditorCursor(editor);
    if (PT_hasTreeArgs(cursor)) {
      PT_Args children = PT_findArgsWithLocation(PT_getTreeArgs(cursor));
      if (!PT_isArgsEmpty(children)) {
	PT_Tree child = PT_getArgsHead(children);
	return SE_setStructureEditorCursor(editor, child);
      }
    }
  }

  return editor;
}

static SE_StructureEditor moveCursorLeft(SE_StructureEditor editor) {
  PT_ParseTree parseTree;
  PT_Tree tree;

  assert(editor != NULL);

  parseTree = SE_getStructureEditorParseTree(editor);
  tree = PT_getParseTreeTop(parseTree);

  if (SE_hasStructureEditorCursor(editor)) {
    PT_Tree cursor = SE_getStructureEditorCursor(editor);
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
  }

  return editor;
}

static SE_StructureEditor moveCursorRight(SE_StructureEditor editor) {
  PT_ParseTree parseTree;
  PT_Tree tree;
  PT_Args siblings;

  assert(editor != NULL);

  parseTree = SE_getStructureEditorParseTree(editor);
  tree = PT_getParseTreeTop(parseTree);

  if (SE_hasStructureEditorCursor(editor)) {
    PT_Tree cursor = SE_getStructureEditorCursor(editor);
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
  }

  return moveCursorUp(editor);
}

static PT_Symbol getTreeSort(PT_Tree tree) {
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    return PT_getProductionRhs(prod);
  }
  else if (PT_isTreeChar(tree)) {
    int ch = PT_getTreeCharacter(tree);

    return PT_makeSymbolCharClass(PT_makeCharRangesSingle(
                                  PT_makeCharRangeCharacter(ch)));
  }
  else if (PT_isTreeAmb(tree)) {
    return PT_makeSymbolSort(SORT_AMBIGUOUS);
  }
  else if (PT_isTreeCycle(tree)) {
    return PT_makeSymbolSort(SORT_CYCLE);
  }
  else {
    return PT_makeSymbolSort(SORT_UNKNOWN);
  }
}

static void create_structure_editor(ATerm editorId, ATerm parseTreeTerm) {
  PT_ParseTree parseTree;
  SE_StructureEditor editor;

  parseTree = PT_ParseTreeFromTerm(ATBunpack(parseTreeTerm));
  assertParseTreeHasPosInfo(parseTree);

  editor = SE_makeStructureEditorUnedited(parseTree);
  setEditor(editorId, editor);
}

void create_editor(int cid, ATerm editorId, ATerm parseTreeTerm) {
  create_structure_editor(editorId, parseTreeTerm);
}

void update_editor(int cid, ATerm editorId, ATerm parseTreeTerm) {
  create_structure_editor(editorId, parseTreeTerm);
}

void delete_editor(int cid, ATerm editorId) {
  ATerm editor;

  editor = ATtableGet(editors, editorId);
  if (editor != NULL) {
    ATtableRemove(editors, editor);
  }
}

ATerm get_parse_tree(int cid, ATerm editorId) {
  SE_StructureEditor editor = getEditor(editorId);

  if (editor != NULL) {
    SE_ParseTree parseTree = SE_getStructureEditorParseTree(editor);
    return ATmake("snd-value(parse-tree(<term>))", parseTree);
  }

  ATwarning("get_parse_tree: cannot get parse tree for: %t\n", editorId);
  return NULL;
}

void set_cursor_at_offset(int cid, ATerm editorId, int offset) {
  SE_StructureEditor editor;

  editor = getEditor(editorId);
  if (editor != NULL) {
    PT_ParseTree parseTree = SE_getStructureEditorParseTree(editor);
    PT_Tree tree = PT_getParseTreeTop(parseTree);
    PT_Tree cursor;

    cursor = PT_findTreeAtOffset(tree, offset);

    if (cursor == NULL) {
      cursor = tree;
    }

    editor = SE_makeStructureEditorDefault(parseTree, cursor);

    if (PT_isTreeLit(cursor)) {
      editor = moveCursorUp(editor);
    }
    while (PT_isTreeLexical(cursor)) {
      editor = moveCursorUp(editor);
      cursor = SE_getStructureEditorCursor(editor);
    }

    setEditor(editorId, editor);
  }
  else {
    ATwarning("set_cursor_at_offset: no such editor: %t\n", editorId);
  }
}

void set_cursor_at_line_column(int cid, ATerm editorId, int line, int col) {
  SE_StructureEditor editor;

  editor = getEditor(editorId);
  if (editor != NULL) {
    PT_ParseTree parseTree = SE_getStructureEditorParseTree(editor);
    PT_Tree tree = PT_getParseTreeTop(parseTree);
    PT_Tree cursor;

    cursor = PT_findTreeAtLineColumn(tree, line, col);

    if (cursor == NULL) {
      cursor = tree;
    }

    editor = SE_makeStructureEditorDefault(parseTree, cursor);

    if (PT_isTreeLit(cursor)) {
      editor = moveCursorUp(editor);
    }
    while (PT_isTreeLexical(cursor)) {
      editor = moveCursorUp(editor);
      cursor = SE_getStructureEditorCursor(editor);
    }

    setEditor(editorId, editor);
  }
  else {
    ATwarning("set_cursor_at_line_column: no such editor: %t\n", editorId);
  }
}

ATerm get_cursor(int cid, ATerm editorId) {
  SE_StructureEditor editor = getEditor(editorId);

  if (editor != NULL && SE_hasStructureEditorCursor(editor)) {
    SE_Tree cursor = SE_getStructureEditorCursor(editor);
    return ATmake("snd-value(cursor(<term>))", ATBpack((ATerm) cursor));
  }

  return ATparse("snd-value(no-cursor)");
}

ATerm get_focus_at_cursor(int cid, ATerm editorId) {
  SE_StructureEditor editor = getEditor(editorId);

  if (editor != NULL && SE_hasStructureEditorCursor(editor)) {
    SE_Tree cursor = SE_getStructureEditorCursor(editor);
    ERR_Location location = PT_getTreeLocation(cursor);
    ERR_Area area = ERR_getLocationArea(location);
    return ATmake("snd-value(focus(<term>))", area);
  }

  ATwarning("get_focus_at_cursor: cannot get focus for: %t\n", editorId);
  return NULL;
}

ATerm get_sort_at_cursor(int cid, ATerm editorId) {
  SE_StructureEditor editor = getEditor(editorId);

  if (editor != NULL && SE_hasStructureEditorCursor(editor)) {
    SE_Tree cursor = SE_getStructureEditorCursor(editor);
    char *sort = PT_yieldSymbol(getTreeSort(cursor));
    return ATmake("snd-value(sort(<str>))", sort);
  }

  return ATparse("snd-value(no-cursor)");
}

void move_cursor(int cid, ATerm editorId, ATerm move) {
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

ATerm get_tree_slices(int cid, ATerm editorId) {
  SE_StructureEditor editor;

  editor = getEditor(editorId);
  if (editor != NULL) {
    SE_ParseTree parseTree;
    ATermList slices;

    parseTree = SE_getStructureEditorParseTree(editor);
    
    /* This computation is the only one that needs pos-info on layout
     * and literals for now:
     */
    parseTree = PT_addParseTreePosInfoSome("dummy", parseTree, -1,
					   ATtrue, ATtrue);
    slices = TreeToSyntaxSlices(PT_getParseTreeTop(parseTree));

    return ATmake("snd-value(tree-slices(<term>))", (ATerm) slices);
  }

  return ATmake("snd-value(no-tree-slices)"); 
}

ATerm slice_tree(int cid, ATerm tree) 
{
  PT_ParseTree parseTree = PT_ParseTreeFromTerm(ATBunpack(tree));
  ATermList slices;

  parseTree = PT_addParseTreePosInfoSome("dummy", parseTree, -1,
					 ATtrue, ATtrue);
  slices = tokenizeTree(PT_getParseTreeTop(parseTree));

  return ATmake("snd-value(sliced-tree(<term>))", (ATerm) ATreverse(slices));
}

void rec_terminate(int cid, ATerm message) {
  exit(0);
}

int main(int argc, char *argv[]) {
  ATerm bottomOfStack;
  int cid;

  ATBinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  ERR_initErrorApi();
  SE_initStructureEditorApi();

  editors = ATtableCreate(100, 75);

  cid = ATBconnect(NULL, NULL, -1, structure_editor_handler);
  return ATBeventloop();
}

