/*{{{   includes */

#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include <atb-tool.h>
#include <MEPT-utils.h>

#include "se.tif.h"
#include "EditorData.h"
#include "editor.h"
#include "focus.h"
#include "tree.h"

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

  return ATmake("snd-value(initial-focus(<term>))",
		SE_makeTermFromFocus(SE_getEditorFocus(editor)));
}

/*}}}  */
/*{{{  ATerm new_editor_given_tree(int cid, ATerm editorId, ATerm t) */

ATerm new_editor_given_tree(int cid, ATerm editorId, ATerm t)
{
  SE_Editor editor;
  PT_ParseTree parse_tree = PT_makeParseTreeFromTerm(ATBunpack(t));

  assert(PT_isValidParseTree(parse_tree));

  editor = newEditorGivenTree(parse_tree, SORT_TERM, FOCUS_PARSED);

  if (editor == NULL) {
    return ATmake("snd-value(no-such-editor)");
  }

  putEditor(editorId, editor);

  return ATmake("snd-value(initial-focus(<term>))",
		SE_makeTermFromFocus(SE_getEditorFocus(editor)));
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
  
  if (editor == NULL) {
    return ATmake("snd-value(no-such-editor)");
  }

  editor = insertChars(editor, location, strlen(text));

  putEditor(editorId, editor);

  focus = SE_getEditorFocus(editor);

  return ATmake("snd-value(focus(<term>))", SE_makeTermFromFocus(focus));
}

/*}}}  */
/*{{{  ATerm delete_chars(int cid, ATerm editorId, int location, int count) */

ATerm delete_chars(int cid, ATerm editorId, int location, int count)
{
  SE_Focus focus;
  SE_Editor editor = getEditor(editorId);

  if (editor == NULL) {
    return ATmake("snd-value(no-such-editor)");
  }

  editor = deleteChars(editor, location, count);
  putEditor(editorId, editor);

  focus = SE_getEditorFocus(editor);

  return ATmake("snd-value(focus(<term>))", SE_makeTermFromFocus(focus));
}

/*}}}  */

/*{{{  void replace_focus(int cid, ATerm editorId, ATerm f, ATerm t) */

void replace_focus(int cid, ATerm editorId, ATerm f, ATerm t)
{
  PT_Tree left_layout, right_layout;
  SE_Editor editor;
  SE_Focus focus;
  PT_Tree tree;
  PT_ParseTree parse_tree;
  
  parse_tree = PT_makeParseTreeFromTerm(ATBunpack(t));
  assert(PT_isValidParseTree(parse_tree));

  focus = SE_makeFocusFromTerm(f);
  assert(SE_isValidFocus(focus));

  tree = PT_getParseTreeTree(parse_tree);
  if (PT_isTreeAmb(tree)) {
    left_layout = PT_makeTreeLayoutEmpty();
    right_layout = PT_makeTreeLayoutEmpty();
  }
  else {
    left_layout = PT_getParseTreeLayoutBeforeTree(parse_tree);
    right_layout = PT_getParseTreeLayoutAfterTree(parse_tree);
  }

  editor = getEditor(editorId);
  if (editor != NULL) {
    editor = replaceEditorTreeAtFocus(editor, focus, tree, 
                                      PT_getTreeArgs(left_layout),
				      PT_getTreeArgs(right_layout));
    putEditor(editorId, editor);
  }
}

/*}}}  */
/*{{{  ATerm move_focus_to_root(int cid, ATerm editorId) */

ATerm move_focus_to_root(int cid, ATerm editorId)
{
  SE_Editor editor = getEditor(editorId);
  SE_Editor new_editor;
  SE_Focus focus = SE_makeFocusEmpty();

  if (editor != NULL) {
    new_editor = moveFocusToTop(editor);
    putEditor(editorId, new_editor);
    focus = SE_getEditorFocus(new_editor);
  }

  return ATmake("snd-value(focus(<term>))", SE_makeTermFromFocus(focus));
}

/*}}}  */
/*{{{  ATerm move_focus(int cid, ATerm editorId, ATerm direction) */

ATerm move_focus(int cid, ATerm editorId, ATerm direction)
{
  SE_Editor editor = getEditor(editorId);
  SE_Editor new_editor;
  SE_Focus focus;
  SE_Move move;

  if (editor == NULL) {
    return ATmake("snd-value(no-such-editor)");
  }

  move = SE_makeMoveFromTerm(direction);
  assert(SE_isValidMove(move));

  new_editor = moveFocus(editor, move);

  putEditor(editorId, new_editor);

  focus = SE_getEditorFocus(new_editor);

  return ATmake("snd-value(focus(<term>))", SE_makeTermFromFocus(focus));
}

/*}}}  */
/*{{{  ATerm set_focus(int cid, ATerm editorId, int location) */

ATerm set_focus(int cid, ATerm editorId, int location)
{
  SE_Focus focus = SE_makeFocusEmpty();
  SE_Editor editor = getEditor(editorId);
  PT_ParseTree parse_tree;
  
  if(editor != NULL) {
    parse_tree = SE_getEditorParseTree(editor);
    focus = getFocusAt(editor, parse_tree, location);
    editor = SE_setEditorFocus(editor, focus);
    putEditor(editorId, editor);
  }

  return ATmake("snd-value(focus(<term>))", SE_makeTermFromFocus(focus));
}

/*}}}  */
/*{{{  ATerm get_focus_at_posinfo(int cid, ATerm editorId, ATerm posInfo) */

ATerm get_focus_at_posinfo(int cid, ATerm editorId, ATerm posInfo)
{
  SE_Focus focus = SE_makeFocusEmpty();
  SE_Editor editor = getEditor(editorId);
  PT_ParseTree parse_tree;
  
  if (editor != NULL) {
    parse_tree = SE_getEditorParseTree(editor);
    focus = getFocusAtPosInfo(editor, parse_tree, posInfo);
    editor = SE_setEditorFocus(editor, focus);
    putEditor(editorId, editor);
  }

  return ATmake("snd-value(focus(<term>))", SE_makeTermFromFocus(focus));
}

/*}}}  */

/*{{{  ATerm invalidate_tree(int cid, ATerm editorId) */

ATerm invalidate_tree(int cid, ATerm editorId)
{
  SE_Editor editor;
  SE_Focus  focus = SE_makeFocusEmpty();
  int length;

  editor = getEditor(editorId);

  if (editor) {
    length = PT_getParseTreeLengthAnno(SE_getEditorParseTree(editor));
    editor = newEditorGivenLength(length);
    putEditor(editorId, editor);
    focus = SE_getEditorFocus(editor);

  } 

  return ATmake("snd-value(focus(<term>))", SE_makeTermFromFocus(focus));
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

    foci = SE_getEditorUnparsedFoci(editor);
  } else {
    foci = SE_makeFocusListEmpty();
  }

  return ATmake("snd-value(foci(<term>))", SE_makeTermFromFocusList(foci));
}

/*}}}  */
/*{{{  ATerm get_parse_tree(int cid, ATerm editorId) */

ATerm get_parse_tree(int cid, ATerm editorId)
{
  SE_Editor editor = getEditor(editorId);
  PT_ParseTree parse_tree;

  if (editor == NULL) {
    return ATmake("snd-value(no-such-editor)");
  }
  
  parse_tree = SE_getEditorParseTree(editor);

  return ATmake("snd-value(parse-tree(<term>))",
		ATBpack(PT_makeTermFromParseTree(parse_tree)));
}

/*}}}  */
/*{{{  ATerm get_focussed_tree(int cid, ATerm editorId) */

ATerm get_focussed_tree(int cid, ATerm editorId)
{
  SE_Editor editor = getEditor(editorId);
  SE_Focus focus;

  if (editor == NULL) {
    return ATmake("snd-value(no-parse-tree)");
  }

  focus = SE_getEditorFocus(editor); 

  if (SE_isFocusNotEmpty(focus)) {
    if (strcmp(SE_getFocusSort(focus), SORT_UNPARSED) != 0) {
      PT_Tree tree;
      PT_ParseTree parse_tree;

      if (!SE_isFocusRoot(focus)) {
	tree = getFocussedTree(editor, focus);
	parse_tree = PT_makeValidParseTreeFromTree(tree);
      }
      else {
	parse_tree = SE_getEditorParseTree(editor);
      }

      return ATmake("snd-value(parse-tree(<term>))", 
                    PT_makeTermFromParseTree(parse_tree));
    }
  }

  return ATmake("snd-value(no-parse-tree)");
}

/*}}}  */
/*{{{  ATerm replace_focussed_tree(int cid, ATerm editorId, ATerm tree) */

ATerm replace_focussed_tree(int cid, ATerm editorId, ATerm t)
{
  SE_Editor editor = getEditor(editorId);
  SE_Focus focus;
  PT_ParseTree parse_tree;
  PT_Tree tree;
  PT_Args left_layout, right_layout;

  if (editor == NULL) {
    return ATmake("snd-value(focus(<term>))", SE_makeFocusEmpty());
  }

  focus = SE_getEditorFocus(editor);
  parse_tree = PT_makeParseTreeFromTerm(ATBunpack(t));
  tree =  PT_getParseTreeTree(parse_tree);

  if (SE_isFocusNotEmpty(focus)) {
    if (strcmp(SE_getFocusSort(focus), SORT_UNPARSED) != 0) {
      left_layout  = 
        PT_getTreeArgs(PT_getParseTreeLayoutBeforeTree(parse_tree));
      right_layout = 
        PT_getTreeArgs(PT_getParseTreeLayoutAfterTree(parse_tree));

      editor = replaceEditorTreeAtFocus(editor, focus, tree, 
                                        left_layout, right_layout);
      putEditor(editorId, editor);
    }
  }
  focus = SE_getEditorFocus(editor);

  return ATmake("snd-value(focus(<term>))", SE_makeTermFromFocus(focus));
}
      
/*}}}  */
/*{{{  ATerm get_focus_sort(int cid, ATerm editorId) */

ATerm get_focus_sort(int cid, ATerm editorId)
{
  char *sort;
  SE_Editor editor = getEditor(editorId);
  SE_Focus focus;


  if (editor != NULL) {
    focus = SE_getEditorFocus(editor); 

    if (SE_isFocusNotEmpty(focus)) {
      sort = SE_getFocusSort(focus);
      if (strcmp(sort, SORT_UNPARSED) != 0) {
	return ATmake("snd-value(focus-sort(<str>))", sort);
      }
    }
  }

  return ATmake("snd-value(no-focus)");
}

/*}}}  */
/*{{{  ATerm check_tree_sort(int cid, char *nonterminal, ATerm t) */
 
ATerm check_tree_sort(int cid, char *nonterminal, ATerm t)
{
  char *sort;
  PT_ParseTree parse_tree = PT_makeParseTreeFromTerm(ATBunpack(t));
  PT_Symbol symbol = getParseTreeSort(parse_tree);
 
  sort = PT_yieldSymbol(symbol);

  if (strcmp(sort, nonterminal) != 0) {
    return ATmake("snd-value(msg(wrong-sort(<str>)))", sort);
  }
  else {
    return ATmake("snd-value(msg(sort-ok))");
  }
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

  return ATmake("snd-value(error-position(<int>))", start + errorPos);
}

/*}}}  */
/*{{{  ATerm get_modification_status(int cid, ATerm editorId) */

ATerm get_modification_status(int cid, ATerm editorId)
{
  SE_Editor editor = getEditor(editorId);
  ATerm status = ATparse("modified");
  
  if (editor) {
    status = SE_getEditorModified(editor) ? status : ATparse("unmodified");
  }
  
  return ATmake("snd-value(modification-status(<term>))",status);
}

/*}}}  */
/*{{{  void modify(int cid, ATerm editorId) */

void modify(int cid, ATerm editorId)
{
  SE_Editor editor = getEditor(editorId);
  
  if (editor) {
    putEditor(editorId, SE_setEditorModified(editor, 1));
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

  PT_initMEPTApi();
  SE_initEditorDataApi();


  editorTable = ATtableCreate(100, 75);

  cid = ATBconnect(NULL, NULL, -1, se_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
