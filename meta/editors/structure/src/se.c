
/*{{{   includes */

#include <stdlib.h>
#include <assert.h>

#include <atb-tool.h>
#include <PT-utils.h>

#include "se.tif.h"
#include "Editor.h"
#include "editor.h"
#include "focus.h"

/*}}}  */
/*{{{   globals */

static ATermTable editorTable = NULL;

/*}}}  */

/*{{{  static void putEditor(ATerm id, SE_Editor editor) */

static void putEditor(ATerm id, SE_Editor editor)
{
  ATtablePut(editorTable, id, SE_makeTermFromEditor(editor));
}

/*}}}  */
/*{{{  static SE_Editor getEditor(ATerm id) */

static SE_Editor getEditor(ATerm id)
{
  ATerm t = ATtableGet(editorTable, id);

  if (t == NULL) {
    return NULL;
  }

  return SE_makeEditorFromTerm(t);
}

/*}}}  */
/*{{{  static void removeEditor(ATerm id) */

static void removeEditor(ATerm id)
{
  ATtableRemove(editorTable, id);
}

/*}}}  */

/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */

/*{{{  ATerm new_editor_given_text(int cid, ATerm editorId, char *text) */

ATerm new_editor_given_text(int cid, ATerm editorId, char *text)
{
  SE_Editor editor = newEditorGivenText(text);

  putEditor(editorId, editor);

  return ATmake("snd-value(<term>)", SE_makeTermFromFocus(SE_getEditorFocus(editor)));
}

/*}}}  */
/*{{{  ATerm new_editor_given_tree(int cid, ATerm editorId, ATerm t) */

ATerm new_editor_given_tree(int cid, ATerm editorId, ATerm t)
{
  SE_Editor editor;
  PT_ParseTree parse_tree = PT_makeParseTreeFromTerm(t);

  assert(PT_isValidParseTree(parse_tree));

  editor = newEditorGivenTree(parse_tree, FOCUS_CLEAN);
  putEditor(editorId, editor);

  return ATmake("snd-value(<term>)", SE_makeTermFromFocus(SE_getEditorFocus(editor)));
}

/*}}}  */
/*{{{  void remove_tree(int cid, ATerm editorId) */

void remove_tree(int cid, ATerm editorId)
{
  removeEditor(editorId);
}

/*}}}  */

/*{{{  ATerm insert_chars(int cid, ATerm editorId, int location, char *text) */

ATerm insert_chars(int cid, ATerm editorId, int location, char *text)
{
  SE_Focus focus;
  SE_Editor editor;
 
  editor = getEditor(editorId);
  assert(editor);
  editor = insertChars(editor, location, strlen(text));

  putEditor(editorId, editor);

  focus = SE_getEditorFocus(editor);

  return ATmake("snd-value(<term>)", SE_makeTermFromFocus(focus));
}

/*}}}  */
/*{{{  ATerm delete_chars(int cid, ATerm editorId, int location, int count) */

ATerm delete_chars(int cid, ATerm editorId, int location, int count)
{
  SE_Focus focus;
  SE_Editor editor = getEditor(editorId);

  assert(editor);
  editor = deleteChars(editor, location, count);
  putEditor(editorId, editor);

  focus = SE_getEditorFocus(editor);

  return ATmake("snd-value(<term>)", SE_makeTermFromFocus(focus));
}

/*}}}  */

/*{{{  void replace_focus(int cid, ATerm editorId, ATerm f, ATerm t) */

void replace_focus(int cid, ATerm editorId, ATerm f, ATerm t)
{
  char *left_layout, *right_layout;
  SE_Editor editor;
  SE_Focus focus;
  PT_Tree tree;
  PT_ParseTree parse_tree;
  
  parse_tree = PT_makeParseTreeFromTerm(t);
  assert(PT_isValidParseTree(parse_tree));

  focus = SE_makeFocusFromTerm(f);
  assert(SE_isValidFocus(focus));

  tree         = PT_getParseTreeTree(parse_tree);
  left_layout  = PT_getParseTreeLayoutBeforeTree(parse_tree);
  right_layout = PT_getParseTreeLayoutAfterTree(parse_tree);

  editor = getEditor(editorId);
  if (editor) {
    editor = replaceEditorTreeAtFocus(editor, focus, tree, left_layout, right_layout);

    putEditor(editorId, editor);
  }
}

/*}}}  */
/*{{{  void set_multiple_focus(int cid, ATerm editorId, ATerm f) */

void set_multiple_focus(int cid, ATerm editorId, ATerm f)
{
  SE_Editor editor = getEditor(editorId);
  SE_FocusList foci;

  if (editor) {
    foci = SE_makeFocusListFromTerm(f);
    assert(SE_isValidFocusList(foci));

    editor = SE_setEditorDirtyFoci(editor, foci);

    putEditor(editorId, editor);
  }
}

/*}}}  */

/*{{{  ATerm move_focus(int cid, ATerm editorId, ATerm direction) */

ATerm move_focus(int cid, ATerm editorId, ATerm direction)
{
  SE_Editor editor = getEditor(editorId);
  SE_Editor new_editor;
  SE_Focus focus;
  SE_Move move;

  assert(editor);

  move = SE_makeMoveFromTerm(direction);
  assert(SE_isValidMove(move));

  new_editor = moveFocus(editor, move);

  putEditor(editorId, new_editor);

  focus = SE_getEditorFocus(new_editor);

  return ATmake("snd-value(<term>)", SE_makeTermFromFocus(focus));
}

/*}}}  */
/*{{{  ATerm set_focus(int cid, ATerm editorId, int location) */

ATerm set_focus(int cid, ATerm editorId, int location)
{
  SE_Focus focus;
  SE_Editor editor = getEditor(editorId);
  PT_ParseTree parse_tree;
  
  assert(editor);

  parse_tree = SE_getEditorParseTree(editor);

  focus = getFocusAt(parse_tree, location);

  editor = SE_setEditorFocus(editor, focus);

  putEditor(editorId, editor);

  return ATmake("snd-value(<term>)", SE_makeTermFromFocus(focus));
}

/*}}}  */

/*{{{  ATerm invalidate_tree(int cid, ATerm editorId) */

ATerm invalidate_tree(int cid, ATerm editorId)
{
  SE_Editor editor;
  int length;

  editor = getEditor(editorId);

  if (editor) {
    length = PT_getParseTreeLengthAnno(SE_getEditorParseTree(editor));
    editor = newEditorGivenLength(length);
    putEditor(editorId, editor);

    return ATmake("snd-value(focus(<term>))",
		  SE_makeTermFromFocus(SE_getEditorFocus(editor)));
  } else {
    return ATmake("snd-value(no-such-editor(<term>))", editorId);
  }
}

/*}}}  */
/*{{{  ATerm get_dirty_focuses(int cid, ATerm editorId) */

ATerm get_dirty_focuses(int cid, ATerm editorId)
{
  SE_Editor editor = getEditor(editorId);
  SE_FocusList foci;

  if (editor) {
    editor = joinFoci(editor);

    putEditor(editorId, editor);

    foci = SE_getEditorDirtyFoci(editor);

    return ATmake("snd-value(foci(<term>))", SE_makeTermFromFocusList(foci));
  } else {
    return ATmake("snd-value(no-such-editor(<term>))", editorId);
  }
}

/*}}}  */
/*{{{  ATerm get_parse_tree(int cid, ATerm editorId) */

ATerm get_parse_tree(int cid, ATerm editorId)
{
  SE_Editor editor = getEditor(editorId);
  PT_ParseTree parse_tree;

  assert(editor);
  
  parse_tree = SE_getEditorParseTree(editor);

  return ATmake("snd-value(<term>)", PT_makeTermFromParseTree(parse_tree));
}

/*}}}  */
/*{{{  ATerm get_focus_sort(int cid, char *nonterminal, ATerm f) */

ATerm get_focus_sort(int cid, char *nonterminal, ATerm f)
{
  char *sort;
  SE_Focus focus;
 
  focus = SE_makeFocusFromTerm(f);
  assert(SE_isValidFocus(focus));

  sort = SE_getFocusSort(focus);

  if (strcmp(sort, SORT_INVALID) != 0) {
    return ATmake("snd-value(<str>)", sort);
  }

  return ATmake("snd-value(<str>)", nonterminal);
}

/*}}}  */
/*{{{  ATerm calc_error_location(int cid, ATerm focus, ATerm error) */

ATerm calc_error_location(int cid, ATerm f, ATerm error)
{
  ATerm posTerm;
  SE_Focus focus;
  int start;
  int errorPos;

  focus = SE_makeFocusFromTerm(f);
  assert(SE_isValidFocus(focus));

  start = SE_getAreaStart(SE_getFocusArea(focus));
  posTerm = ATelementAt((ATermList) error, 3);

  errorPos = ATgetInt((ATermInt) ATgetArgument((ATermAppl) posTerm, 0));

  return ATmake("snd-value(<int>)", start + errorPos);
}

/*}}}  */
/*{{{  void register_symbols(int cid, ATerm editorId, ATerm startSymbols) */

void register_symbols(int cid, ATerm editorId, ATerm startSymbols)
{
  SE_Editor editor;
  SE_SymbolList start_symbols;

  ATermList old_list, new_list;
  old_list = (ATermList)startSymbols;
  new_list = ATempty;

  while (!ATisEmpty(old_list)) {
    ATermAppl start_symbol = (ATermAppl)ATgetFirst(old_list);
    ATerm symbol = ATgetArgument(start_symbol, 0);
    new_list = ATinsert(new_list, symbol);
    old_list = ATgetNext(old_list);
  }
  
  start_symbols = SE_makeSymbolListFromTerm((ATerm)new_list);
  editor = getEditor(editorId);

  if (editor) {
    editor = SE_setEditorStartSymbols(editor, start_symbols);

    putEditor(editorId, editor);
  }
}

/*}}}  */
/*{{{  ATerm get_modification_status(int cid, ATerm editorId) */

ATerm get_modification_status(int cid, ATerm editorId)
{
  SE_Editor editor = getEditor(editorId);
  SE_FocusList foci;
  char *status;
  

  if (editor) {
    foci = SE_getEditorDirtyFoci(editor);

    status = SE_isFocusListEmpty(foci) ? "unmodified" : "modified";
  
    return ATmake("snd-value(modification-status(<term>))", ATparse(status));
  }
  else {
    return ATmake("snd-value(modification-status(<term>))", 
                  ATparse("modified"));
  }
}

/*}}}  */

/*{{{  void usage(char *prg, ATbool is_err) */

void
usage(char *prg, ATbool is_err)
{
  ATwarning("usage: %s [aterm-options] [toolbus-options]\n", prg);
  ATwarning("use '%s -at-help' to get more options.\n", prg);
  ATwarning("This program can only be used as a ToolBus tool!\n");
  exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  void version(const char *msg) */

void
version(const char *msg)
{
  ATwarning("%s v%s\n", msg, VERSION);
  exit(1);
}

/*}}}  */
/*{{{  int main(int argc, char *argv[]) */

int
main(int argc, char *argv[])
{
  int i, cid;
  ATerm bottomOfStack;

  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-h") == 0) {
      usage(argv[0], ATfalse);
    }
    else if (strcmp(argv[i], "-V") == 0) {
      version(argv[0]);
    }
  }

  ATBinit(argc, argv, &bottomOfStack);

  ATsetChecking(ATtrue);

  PT_initPTApi();
  SE_initEditorApi();


  editorTable = ATtableCreate(100, 75);

  cid = ATBconnect(NULL, NULL, -1, se_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
