/*{{{  includes */

#include <stdlib.h>
#include <assert.h>

#include <MEPT-utils.h>

#include "area.h"
#include "editor.h"
#include "focus.h"
#include "path.h"
#include "sort.h"
#include "tree.h"

/*}}}  */
/*{{{  defines */

#define POS_PATH 0
#define POS_SORT 1
#define POS_AREA 2

/*}}}  */

/*{{{  static ATbool isSubFocus(SE_Focus f1, SE_Focus f2) */

static ATbool isSubFocus(SE_Focus child, SE_Focus parent)
{
  SE_Path childPath, parentPath;

  childPath = SE_getFocusPath(child);
  parentPath = SE_getFocusPath(parent);

  return SE_isEqualPath(childPath, parentPath) || isChildPath(childPath, parentPath);
}

/*}}}  */

/*{{{  SE_Focus createFocus(PT_ParseTree parse_tree, SE_Path path, int focus_status) */

SE_Focus createFocus(PT_ParseTree parse_tree, SE_Path path, int focus_status)
{
  int length;
  SE_Focus focus;

  if (SE_isPathRoot(path)) {
    length = PT_getParseTreeLengthAnno(parse_tree);
    SE_makeAreaDefault(0, length);
    focus = SE_makeFocusNotEmpty(path, SORT_TERM, 
				createArea(parse_tree, path), focus_status);
  }
  else {
    PT_Tree tree = PT_getParseTreeTree(parse_tree); 
    PT_Production prod;

    if (SE_hasPathSteps(path)) {
      tree = getTreeAt(tree, SE_getPathSteps(path));
    }
      
    prod = PT_getTreeProd(tree);
    length = PT_getTreeLengthAnno(tree);
    SE_makeAreaDefault(calcParseTreeStart(parse_tree, path), length);
    if (PT_isProductionVariable(prod)) {
      focus = SE_makeFocusNotEmpty(path, 
				   PT_yieldSymbolVisualVariables(
	 		             getTreeSort(tree)),
                                   createArea(parse_tree, path), 
				   focus_status);
    }
    else {
      focus = SE_makeFocusNotEmpty(path, 
				   PT_yieldSymbol(getTreeSort(tree)),
                                   createArea(parse_tree, path), 
				   focus_status);
    }
  }
  return focus;
}

/*}}}  */
/*{{{  SE_Focus createRootFocus(PT_ParseTree parse_tree, int focus_status) */

SE_Focus createRootFocus(PT_ParseTree parse_tree, int focus_status)
{
  return createFocus(parse_tree, SE_makePathRoot(), focus_status);
}

/*}}}  */

/*{{{  SE_Focus expandFocusToStartSymbol(SE_Editor editor, SE_Focus focus) */

SE_Focus expandFocusToStartSymbol(SE_Editor editor, SE_Focus focus)
{
  SE_Path path;
  SE_Steps steps;
  PT_ParseTree parse_tree;
  PT_Tree tree;
  int focus_status;

  focus_status = SE_getFocusUnparsed(focus);
  parse_tree = SE_getEditorParseTree(editor);
  path = SE_getFocusPath(focus);
  if (SE_isPathRoot(path)
      || SE_isPathLeftLayout(path) || SE_isPathRightLayout(path)) {
    return createRootFocus(parse_tree, focus_status);
  }

  steps = SE_getPathSteps(path);
  tree  = PT_getParseTreeTree(parse_tree);

  if (SE_isStepsEmpty(steps)) {
    PT_Tree sub_tree = getTreeAt(tree, steps); 
    if (PT_isTreeFlatLayout(sub_tree)) {
      return createFocus(parse_tree, SE_makePathTerm(steps), focus_status);
    }
  }
  while (!SE_isStepsEmpty(steps)) {
    PT_Tree sub_tree = getTreeAt(tree, steps); 
    if (PT_isTreeFlatLayout(sub_tree)) {
      return createFocus(parse_tree, SE_makePathTerm(steps), focus_status);
    }
    steps = stepUp(steps);
  }

  return createRootFocus(parse_tree, focus_status);
}

/*}}}  */

/*{{{  ATbool isFocusInUnparsedFoci(SE_Editor editor, SE_Focus focus) */

ATbool isFocusInUnparsedFoci(SE_Editor editor, SE_Focus focus)
{
  SE_FocusList unparsedFoci = SE_getEditorUnparsedFoci(editor);

  while (SE_hasFocusListHead(unparsedFoci)) {
    SE_Focus uf = SE_getFocusListHead(unparsedFoci);
    if (SE_isEqualFocus(focus, uf)) {
      return ATtrue;
    }
    unparsedFoci = SE_getFocusListTail(unparsedFoci);
  }

  return ATfalse;
}

/*}}}  */

/*{{{  SE_Focus updateFocus(SE_Focus focus, int location, int length) */

SE_Focus updateFocus(SE_Focus focus, int location, int length)
{
  SE_Area area = SE_getFocusArea(focus);

  /* Let's find out if insertions outside current focus are possible
   * See editor.c:updateEditor()
   */
  assert(inArea(SE_getFocusArea(focus), location));

  area = SE_setAreaLength(area, SE_getAreaLength(area) + length);

  return SE_setFocusArea(focus, area);
}

/*}}}  */
/*{{{  SE_Focus adaptFocusLength(SE_Focus focus, int length) */

SE_Focus adaptFocusLength(SE_Focus focus, int length)
{
  SE_Area area = SE_getFocusArea(focus);

  area = SE_setAreaLength(area, SE_getAreaLength(area) + length);

  return SE_setFocusArea(focus, area);
}

/*}}}  */

/*{{{  SE_Editor joinFoci(SE_Editor editor) */

SE_Editor joinFoci(SE_Editor editor)
{
  SE_FocusList todo, done;
  SE_Focus curFocus;
  int focusStatus = FOCUS_PARSED;

  curFocus = SE_getEditorFocus(editor);

  if (SE_getFocusUnparsed(curFocus) == FOCUS_UNPARSED) {
    return editor;
  }

  done = SE_makeFocusListEmpty();
  todo = SE_getEditorUnparsedFoci(editor);

  while (!SE_isFocusListEmpty(todo)) {
    SE_Focus focus = SE_getFocusListHead(todo);
    if (!isSubFocus(focus, curFocus)) {
      done = SE_makeFocusListMulti(focus, done);
    }
    else {
      focusStatus = FOCUS_UNPARSED;
    }
    todo = SE_getFocusListTail(todo);
  }

  if (focusStatus == FOCUS_UNPARSED) {
    curFocus = expandFocusToStartSymbol(editor, curFocus);
    curFocus = SE_setFocusUnparsed(curFocus, FOCUS_UNPARSED);
    done = SE_makeFocusListMulti(curFocus, done);
  }

  return SE_setEditorUnparsedFoci(editor, done);
}

/*}}}  */
/*{{{  SE_Editor joinUnparsedFoci(SE_Editor editor) */

SE_Editor joinUnparsedFoci(SE_Editor editor)
{
  SE_FocusList result_foci;
  SE_FocusList dirty_foci;
  SE_Focus focus;

  focus = SE_getEditorFocus(editor);
  //assert(SE_getFocusUnparsed(focus) == FOCUS_UNPARSED);

  /* Check whether the current focus is a subfocus
   * of one of the dirty focuses. If so,
   * replace the current focus with the dirty focus.
   */
  dirty_foci = SE_getEditorUnparsedFoci(editor);
  while (!SE_isFocusListEmpty(dirty_foci)) {
    SE_Focus head = SE_getFocusListHead(dirty_foci);
    if (isSubFocus(focus, head)) {
      return SE_setEditorFocus(editor, head);
    }
    dirty_foci = SE_getFocusListTail(dirty_foci);
  }

  /* Check whether the current focus is a superfocus
   * of one or more of the dirty focuses, if so,
   * replace all these focuses by the current focus.
   */
  result_foci = SE_makeFocusListEmpty();
  dirty_foci = SE_getEditorUnparsedFoci(editor);
  while (!SE_isFocusListEmpty(dirty_foci)) {
    SE_Focus head = SE_getFocusListHead(dirty_foci);
    if (!isSubFocus(head, focus)) {
      result_foci = SE_makeFocusListMulti(head, result_foci);
    }
    dirty_foci = SE_getFocusListTail(dirty_foci);
  }
  result_foci = SE_makeFocusListMulti(focus, result_foci);

  return SE_setEditorUnparsedFoci(editor, result_foci);
}

/*}}}  */

/*{{{  SE_FocusList removeFocus(SE_FocusList foci, SE_Focus focus) */

SE_FocusList removeFocus(SE_FocusList foci, SE_Focus focus)
{
  ATermList focuslist = (ATermList) SE_makeTermFromFocusList(foci);

  focuslist = ATremoveElement(focuslist, SE_makeTermFromFocus(focus));

  return SE_makeFocusListFromTerm((ATerm)focuslist);
}

/*}}}  */

/*{{{  ATbool SE isFocusRoot(SE_Focus focus) */

ATbool SE_isFocusRoot(SE_Focus focus)
{
  return SE_isPathRoot(SE_getFocusPath(focus));
}

/*}}}  */


