/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <MEPT-utils.h>

#include "editor.h"
#include "path.h"
#include "sort.h"
#include "area.h"
#include "focus.h"
#include "tree.h"
#include "length.h"

/*}}}  */

/*{{{  global variables */

#define POS_TREE 0
#define POS_CURFOCUS 1
#define POS_FOCUSES 2
#define POS_SYMBOLS 3
#define POS_MODIFIED 4

ATermTable editorInstances;

/*}}}  */

/*{{{  static SE_Focus createEditorFocus(SE_Editor editor, PT_ParseTree parse_tree, SE_Path path) */

static SE_Focus createEditorFocus(SE_Editor editor, PT_ParseTree parse_tree, SE_Path path)
{
  SE_Focus focus = createFocus(parse_tree, path, FOCUS_UNPARSED);

  if (isFocusInUnparsedFoci(editor, focus)) {
    return focus;
  }

  return SE_setFocusUnparsed(focus, FOCUS_PARSED);
}

/*}}}  */

/*{{{  static SE_Editor moveFocusUp(SE_Editor editor) */

static SE_Editor moveFocusUp(SE_Editor editor)
{
  SE_Focus focus = SE_getEditorFocus(editor);
  SE_Path path = SE_getFocusPath(focus);
  PT_ParseTree parse_tree = SE_getEditorParseTree(editor);

  if (SE_isPathRoot(path)) {
    return editor;
  }

  focus = createEditorFocus(editor, parse_tree, pathUp(path));

  return SE_setEditorFocus(editor, focus);
}

/*}}}  */
/*{{{  static SE_Editor moveFocusRight(SE_Editor editor) */

static SE_Editor moveFocusRight(SE_Editor editor)
{
  SE_Focus focus = SE_getEditorFocus(editor);
  SE_Path path = SE_getFocusPath(focus);
  PT_ParseTree parse_tree = SE_getEditorParseTree(editor);
  PT_Tree tree;

  path = pathRight(path);
  tree = getParseTreeTreeAt(parse_tree, path);
  if (tree == NULL) {
    return moveFocusUp(editor);
  }

  focus = createEditorFocus(editor, parse_tree, path);
  editor = SE_setEditorFocus(editor, focus);

  /* jump over keywords and layout */
  if (PT_isTreeLayout(tree) ||
      PT_isTreeLit(tree)) {
    return moveFocusRight(editor);
  }

  return editor;
}

/*}}}  */
/*{{{  static SE_Editor moveFocusDown(SE_Editor editor) */

static SE_Editor moveFocusDown(SE_Editor editor)
{
  SE_Focus focus = SE_getEditorFocus(editor);
  SE_Path path = SE_getFocusPath(focus);
  PT_ParseTree parse_tree = SE_getEditorParseTree(editor);
  PT_Tree tree;

  if (SE_getFocusUnparsed(focus) == FOCUS_UNPARSED) {
    return editor;
  }

  if (!SE_isPathTerm(path)) {
    /* Select the top-level term */
    path = SE_makePathTerm(SE_makeStepsEmpty());
    focus = createEditorFocus(editor, parse_tree, path);
    editor = SE_setEditorFocus(editor, focus);
    return editor;
  }

  tree = getParseTreeTreeAt(parse_tree, path);

  assert(tree);

  if (PT_isTreeAppl(tree)) {
    SE_Path new_path = pathDown(path);
    tree = getParseTreeTreeAt(parse_tree, new_path);
    if (tree) {
      focus = createEditorFocus(editor, parse_tree, new_path);
      editor = SE_setEditorFocus(editor, focus);
    
      /* jump over keywords and layout */
      if (PT_isTreeLayout(tree) ||
	PT_isTreeLit(tree)) {
	return moveFocusRight(editor);
      }
    }
  }

  return editor;
}

/*}}}  */
/*{{{  static SE_Editor moveFocusLeft(SE_Editor editor) */

static SE_Editor moveFocusLeft(SE_Editor editor)
{
  SE_Focus focus = SE_getEditorFocus(editor);
  SE_Path path = SE_getFocusPath(focus);
  PT_ParseTree parse_tree = SE_getEditorParseTree(editor);
  PT_Tree tree = getParseTreeTreeAt(parse_tree, path);

  if (tree) {
    SE_Path new_path = pathLeft(path);
    if (!SE_isEqualPath(path, new_path)) {
      tree = getParseTreeTreeAt(parse_tree, new_path);
      focus = createEditorFocus(editor, parse_tree, new_path);
      editor = SE_setEditorFocus(editor, focus);

       
     /* jump over keywords and layout */
     if ((PT_isTreeLayout(tree) || PT_isTreeLit(tree)) && 
         !isFocusInUnparsedFoci(editor, focus)) {
       return moveFocusLeft(editor);
     }

     return editor;
    }
  }

  return moveFocusUp(editor);
}

/*}}}  */
/*{{{  static SE_Editor applyMoveToFocus(SE_Editor editor, SE_Move move) */

static SE_Editor applyMoveToFocus(SE_Editor editor, SE_Move move)
{
  if (SE_isMoveUp(move)) {
    return moveFocusUp(editor);
  }
  else if (SE_isMoveDown(move)) {
    return moveFocusDown(editor);
  }
  else if (SE_isMoveLeft(move)) {
    return moveFocusLeft(editor);
  }
  else if (SE_isMoveRight(move)) {
    return moveFocusRight(editor);
  }

  /* not reached */
  abort();
}

/*}}}  */

/*{{{  static SE_Editor updateEditor(SE_Editor editor, int loc, int delta_chars) */

static SE_Editor updateEditor(SE_Editor editor, int location, int delta_chars)
{
  PT_ParseTree parse_tree = SE_getEditorParseTree(editor);
  PT_ParseTree new_tree;
  SE_Focus focus = SE_getEditorFocus(editor);
  SE_Focus new_focus;
  SE_FocusList dirty_foci = SE_getEditorUnparsedFoci(editor);
  SE_FocusList new_foci = SE_makeFocusListEmpty();
  SE_Path path = SE_getFocusPath(focus);

  new_tree = flattenParseTreeTreeAt(parse_tree,path);
  new_tree = updateParseTreeLengthInfo(new_tree, path, delta_chars);
  editor  = SE_setEditorParseTree(editor, new_tree);

  dirty_foci = removeFocus(dirty_foci, focus);

  new_focus = updateFocus(focus, location, delta_chars);
  new_focus = SE_setFocusUnparsed(new_focus, FOCUS_UNPARSED);
  new_focus = SE_setFocusSort(new_focus, SORT_UNPARSED);

  /* Move foci that are to the right of the insertion point */
  while (!SE_isFocusListEmpty(dirty_foci)) {
    SE_Focus cur_focus = SE_getFocusListHead(dirty_foci);
    SE_Area area = SE_getFocusArea(cur_focus);
    int start = SE_getAreaStart(area);
    if (start > location) {
      area = SE_setAreaStart(area, start + delta_chars);
      cur_focus = SE_setFocusArea(cur_focus, area);
    }
    new_foci = SE_makeFocusListMulti(cur_focus, new_foci);
    dirty_foci = SE_getFocusListTail(dirty_foci);
  }
  new_foci = SE_makeFocusListMulti(new_focus, new_foci);

  editor = SE_setEditorFocus(editor, new_focus);
  editor = SE_setEditorUnparsedFoci(editor, new_foci);

  editor = SE_setEditorModified(editor, EDITOR_MODIFIED);

  return editor;
}

/*}}}  */
/*{{{  static SE_Editor moveFocusToStartSymbol(SE_Editor editor, int location) */

static SE_Editor moveFocusToStartSymbol(SE_Editor editor, int location, int length)
{
  PT_ParseTree parse_tree = SE_getEditorParseTree(editor);
  SE_Path path;
  SE_Focus focus;

  if (length < 0) {
    path = getPathInParseTree(parse_tree, location + length, -length);
  } 
  else {
    path = getPathInParseTree(parse_tree, location, 0);
  }

  if (!SE_isPathTerm(path)) {
    path = SE_makePathRoot();
  }

  focus = createEditorFocus(editor, parse_tree, path);

  focus = expandFocusToStartSymbol(editor, focus);
  editor = SE_setEditorFocus(editor, focus);
  editor = joinUnparsedFoci(editor);
  return editor;
}

/*}}}  */

/*{{{  SE_Editor insertChars(SE_Editor editor, int location, int nr_chars) */

SE_Editor insertChars(SE_Editor editor, int location, int nr_chars)
{

  editor = moveFocusToStartSymbol(editor, location, nr_chars);
  editor = updateEditor(editor, location, nr_chars);

  return editor;
}

/*}}}  */
/*{{{  SE_Editor deleteChars(SE_Editor editor, int location, int nr_chars) */

SE_Editor deleteChars(SE_Editor editor, int location, int nr_chars)
{
  assert(location > 0);

  return insertChars(editor, location, -nr_chars);
}

/*}}}  */
/*{{{  SE_Editor moveFocusToTop(SE_Editor editor) */

SE_Editor moveFocusToTop(SE_Editor editor)
{
  PT_ParseTree parse_tree = SE_getEditorParseTree(editor);
  int focus_status = SE_getFocusUnparsed(SE_getEditorFocus(editor));
  SE_Focus root_focus = createRootFocus(parse_tree, focus_status);

  return SE_setEditorFocus(editor, root_focus);
}

/*}}}  */
/*{{{  SE_Editor moveFocus(SE_Editor editor, SE_Move move) */

SE_Editor moveFocus(SE_Editor editor, SE_Move move)
{
  SE_Focus focus = SE_getEditorFocus(editor);

  if (SE_isFocusEmpty(focus)) {
    return moveFocusToTop(editor);
  }
  else {
    return applyMoveToFocus(editor, move);
  }
}

/*}}}  */

/*{{{  SE_Editor newEditorGivenTree(PT_ParseTree parse_tree, ATbool is_dirty) */

SE_Editor newEditorGivenTree(PT_ParseTree parse_tree, 
                             char *sort_name, ATbool is_dirty)
{
  int       length;
  SE_Editor editor;
  SE_Focus  focus;
  SE_Area   area;
  SE_FocusList dirty_foci;
  SE_SymbolList start_symbols;

  parse_tree = PT_annotateParseTreeWithLength(parse_tree);

  length = PT_getParseTreeLengthAnno(parse_tree);
  area = SE_makeAreaDefault(1, length);

  focus = SE_makeFocusNotEmpty(SE_makePathRoot(), sort_name, area, is_dirty);

  dirty_foci = SE_makeFocusListEmpty();
  if (is_dirty) {
    dirty_foci = SE_makeFocusListMulti(focus, dirty_foci);
  }

  start_symbols = SE_makeSymbolListEmpty();

  editor = SE_makeEditorDefault(parse_tree, 
                                focus, 
                                dirty_foci, 
                                EDITOR_UNMODIFIED, 
                                start_symbols);

  return editor;
}

/*}}}  */
/*{{{  SE_Editor newEditorGivenText(char *text) */

SE_Editor newEditorGivenText(char *text)
{
  PT_Tree tree = PT_makeTreeLit(text);
  PT_Symbol sort = PT_makeSymbolCf(PT_makeSymbolSort(SORT_UNPARSED));
  PT_Symbols symbols = PT_makeSymbolsList(PT_makeOptLayoutSymbol(),
                        PT_makeSymbolsList(sort,
                        PT_makeSymbolsList(PT_makeOptLayoutSymbol(),
					   PT_makeSymbolsEmpty())));
  PT_ParseTree parse_tree = PT_makeParseTreeTree(symbols, 
                              PT_makeTreeLayoutEmpty(),
                              tree,
                              PT_makeTreeLayoutEmpty(), 0);

  return newEditorGivenTree(parse_tree, SORT_UNPARSED, FOCUS_UNPARSED);
}

/*}}}  */
/*{{{  SE_Editor newEditorGivenLength(int length) */

SE_Editor newEditorGivenLength(int length)
{
  SE_Editor editor;
  char *dummy_buffer;

  dummy_buffer = (char *) malloc(length + 1);
  memset(dummy_buffer, ' ', length);
  dummy_buffer[length] = '\0';

  editor = newEditorGivenText(dummy_buffer);
  free(dummy_buffer);

  return editor;
}

/*}}}  */

/*{{{  SE_Focus getFocusAt(PT_ParseTree parse_tree, int location) */

SE_Focus getFocusAt(SE_Editor editor, PT_ParseTree parse_tree, int location)
{
  SE_Focus focus;
  SE_Path path = getPathInParseTree(parse_tree, location, 0);

  if (SE_isPathTerm(path)) {
    PT_Tree tree = PT_getParseTreeTree(parse_tree);
    SE_Steps steps = SE_getPathSteps(path);
    PT_Tree sub_tree = getTreeAt(tree, steps);

    if (isBasicLeafNode(sub_tree)) {
      steps = stepUp(steps);
    }
    path = SE_makePathTerm(steps);
  }

  focus = createEditorFocus(editor, parse_tree, path);

  return focus;
}

/*}}}  */
/*{{{  ATerm replaceEditorTreeAtFocus(editor, focus, tree, left_layout,right_layout)*/

SE_Editor replaceEditorTreeAtFocus(SE_Editor editor, SE_Focus focus, 
                                   PT_Tree tree,
				   PT_Args left_layout, PT_Args right_layout)
{
  PT_ParseTree parse_tree = SE_getEditorParseTree(editor);
  PT_ParseTree new_tree;
  SE_FocusList foci = SE_getEditorUnparsedFoci(editor);
  SE_FocusList new_foci;
  SE_Path path;

  new_foci = removeFocus(foci, focus);
  path = SE_getFocusPath(focus);
  new_tree = updateParseTree(parse_tree, path, tree, left_layout, right_layout);
  new_tree = PT_annotateParseTreeWithLength(new_tree);

  if (SE_isEqualFocus(SE_getEditorFocus(editor), focus)) {
    focus = SE_setFocusUnparsed(focus, 0);
    editor = SE_setEditorFocus(editor, focus);
  }

  editor = SE_setEditorParseTree(editor, new_tree);
  editor = SE_setEditorUnparsedFoci(editor, new_foci);

  return editor;
}

/*}}}  */
/*{{{  static PT_Tree getFocussedTree(SE_Editor editor) */

PT_Tree getFocussedTree(SE_Editor editor, SE_Focus focus)
{
  SE_Path path = SE_getFocusPath(focus);
  PT_ParseTree parse_tree = SE_getEditorParseTree(editor);
  return getParseTreeTreeAt(parse_tree, path);
}

/*}}}  */
