/*{{{  file header */

/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam,
                        The Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
/*
  $Id$  
 */

/*
 * The version of se is written by Mark van den Brand.
 */

/*}}}  */
/*{{{  includes */

#include <stdlib.h>
#include <assert.h>

#include "se.h"
#include "editor.h"
#include "path.h"
#include "sort.h"
#include "area.h"
#include "focus.h"
#include "tree.h"
#include "posinfo.h"

/*}}}  */

/*{{{  global variables */

#define POS_TREE 0
#define POS_CURFOCUS 1
#define POS_FOCUSES 2
#define POS_SYMBOLS 3

ATermTable editorInstances;

/*}}}  */

/*{{{  static ATerm newEditorInstanceGivenLength(ATerm atLength) */

static ATerm
newEditorInstanceGivenLength(ATerm atLength)
{
  ATerm focusList, startSymbols;

  int length = getLength(atLength);
  ATerm textTree, dummyTree, wsTree;
  ATerm path = newPath();
  ATerm sort = newSort("invalid");
  ATerm st = newStart(1);
  ATerm area = newArea(st, atLength);
  ATerm focus = newFocus(path, sort, area);

  focus = setDirty(focus);
  focusList = newFocusList(focus);

  wsTree = putTreeLength(ATparse("w(\"\")"), 0);
  dummyTree = putTreeLength(ATparse("w(\"\")"), length);
  textTree =
    ATmake
    ("term(l(\"term\"),w(\"\"),l(\"X\"),w(\"\"),id(\"X\"),<term>,<term>,<term>,no-abbreviations)",
     wsTree, dummyTree, wsTree);
  textTree = putTreeLength(textTree, length);

  startSymbols = (ATerm) ATempty;

  /* editor(TEXT, CURRENTFOCUS, DIRTYFOCUSES, STARTSYMBOLS) */
  return ATmake("editor(<term>,<term>,<term>,<term>)",
		textTree, focus, focusList, startSymbols);
}

/*}}}  */
/*{{{  static ATerm replaceTreeInEditor(ATerm editor, ATerm tree) */

static ATerm
replaceTreeInEditor(ATerm editor, ATerm tree)
{
  return (ATerm) ATsetArgument((ATermAppl) editor, tree, POS_TREE);
}

/*}}}  */
/*{{{  static ATerm replaceFocusesInEditor(ATerm editor, ATermList focuses) */

static ATerm
replaceFocusesInEditor(ATerm editor, ATermList focuses)
{
  return (ATerm) ATsetArgument((ATermAppl) editor, (ATerm) focuses,
			       POS_FOCUSES);
}

/*}}}  */
/*{{{  ATerm setCurrentFocus(ATerm editor, ATerm focus) */

ATerm
setCurrentFocus(ATerm editor, ATerm focus)
{
  return (ATerm) ATsetArgument((ATermAppl) editor, focus, POS_CURFOCUS);
}

/*}}}  */
/*{{{  ATerm getCurrentFocus(ATerm editor) */

ATerm
getCurrentFocus(ATerm editor)
{
  return ATgetArgument((ATermAppl) editor, POS_CURFOCUS);
}

/*}}}  */
/*{{{  static ATerm updateEditorWithInsertions(editor, loc, inslen) */

static ATerm
updateEditorWithInsertions(ATerm editor, int location, int insertionLength)
{
  ATerm newTree;
  ATerm editorTree = getTreeInEditor(editor);
  ATerm newFocus = getCurrentFocus(editor);
  ATermList dirtyFocuses = (ATermList) getFocuses(editor);
  int idx = ATindexOf(dirtyFocuses, newFocus, 0);
  ATerm locationPath = getPathInTree(editorTree, location);
  ATermList newDirtyFocuses = ATempty;
  ATerm curDirtyFocus, area;
  int start;

  if (idx != -1) {
    dirtyFocuses = ATremoveElementAt(dirtyFocuses, idx);
  }

  newFocus = updateFocus(editorTree, newFocus, location, insertionLength);
  newFocus = setDirty(newFocus);

  newTree = updatePosInfo(editorTree, locationPath, insertionLength);

  while (!ATisEmpty(dirtyFocuses)) {
    curDirtyFocus = ATgetFirst(dirtyFocuses);
    dirtyFocuses = ATgetNext(dirtyFocuses);
    area = getFocusArea(curDirtyFocus);
    start = getIntStartOfArea(area);
    if (start > location) {
      area = setIntStartOfArea(area, start + insertionLength);
      curDirtyFocus = setFocusArea(curDirtyFocus, area);
    }
    newDirtyFocuses = ATinsert(newDirtyFocuses, curDirtyFocus);
  }
  newDirtyFocuses = ATinsert(newDirtyFocuses, newFocus);

  editor = replaceTreeInEditor(editor, newTree);
  editor = setCurrentFocus(editor, newFocus);
  editor = replaceFocusesInEditor(editor, newDirtyFocuses);

  return editor;
}

/*}}}  */
/*{{{  static ATerm updateEditorWithDeletions(editor, location, cnt) */

static ATerm
updateEditorWithDeletions(ATerm editor, int location, int count)
{
  return updateEditorWithInsertions(editor, location, -count);
}

/*}}}  */
/*{{{  static ATerm moveFocusToTop(ATerm editor) */

static ATerm
moveFocusToTop(ATerm editor)
{
  ATerm editorTree = getTreeInEditor(editor);
  ATerm path = newPath();
  ATerm curFocus = createFocus(editorTree, path);

  return setCurrentFocus(editor, curFocus);
}

/*}}}  */
/*{{{  ATerm getFocusGivenLocation(editorTree, location) */

ATerm
getFocusGivenLocation(ATerm editorTree, int location)
{
  ATerm focus;
  ATerm path = getPathInTree(editorTree, location);
  ATerm subTree = getSubTree(editorTree, path);

  if (isBasicLeafNode(subTree)) {
    path = goUp(path);
  }

  focus = createFocus(editorTree, path);
  if (!ATgetAnnotation(focus, ATparse("focusstatus"))) {
    focus = setClean(focus);
  }
  return focus;
}

/*}}}  */
/*{{{  ATerm newEditorInstanceGivenText(char *text) */

ATerm
newEditorInstanceGivenText(char *text)
{
  ATerm length = newLength(strlen(text));

  return newEditorInstanceGivenLength(length);
}

/*}}}  */
/*{{{  ATerm setFocuses(ATerm editor, ATerm newFocusList) */

ATerm
setFocuses(ATerm editor, ATerm focusList)
{
  return (ATerm) ATsetArgument((ATermAppl) editor, focusList, POS_FOCUSES);
}

/*}}}  */
/*{{{  ATerm newEditorInstanceGivenTree(ATerm tree) */

ATerm
newEditorInstanceGivenTree(ATerm tree)
{
  ATerm length, newEditor, focus;

  length = newLength(0);
  newEditor = newEditorInstanceGivenLength(length);
  focus = getCurrentFocus(newEditor);
  newEditor = replaceFocusByTree(newEditor, focus, tree);
  newEditor = moveFocusToTop(newEditor);
  newEditor = setFocuses(newEditor, (ATerm) ATempty);
  return newEditor;
}

/*}}}  */
/*{{{  ATerm getTreeInEditor(ATerm editor) */

ATerm
getTreeInEditor(ATerm editor)
{
  return ATgetArgument((ATermAppl) editor, POS_TREE);
}

/*}}}  */
/*{{{  ATerm getFocuses(ATerm editor) */

ATerm
getFocuses(ATerm editor)
{
  return ATgetArgument((ATermAppl) editor, POS_FOCUSES);
}

/*}}}  */
/*{{{  ATerm getStartSymbols(ATerm editor) */

ATerm
getStartSymbols(ATerm editor)
{
  return ATgetArgument((ATermAppl) editor, POS_SYMBOLS);
}

/*}}}  */
/*{{{  ATerm putStartSymbols(ATerm editor, ATerm newStartSymbols) */

ATerm
putStartSymbols(ATerm editor, ATerm startSymbols)
{
  ATerm startSymbol, startSort;
  ATermList newSortSymbols = ATempty;
  char *sortName;

  while (!ATisEmpty((ATermList) startSymbols)) {
    startSymbol = ATgetFirst((ATermList) startSymbols);
    if (ATmatch(startSymbol, "startsymbol(<str>)", &sortName)) {
      startSort = ATmake("sort(<str>)", sortName);
      newSortSymbols = ATinsert(newSortSymbols, startSort);
    }
    startSymbols = (ATerm) ATgetNext((ATermList) startSymbols);
  }

  return (ATerm) ATsetArgument((ATermAppl) editor,
			       (ATerm) newSortSymbols, POS_SYMBOLS);
}

/*}}}  */
/*{{{  ATerm replaceFocusByTree(ATerm editor, ATerm focus, ATerm tree) */

ATerm
replaceFocusByTree(ATerm editor, ATerm focus, ATerm tree)
{
  ATermList focuses = (ATermList) getFocuses(editor);
  ATerm editorTree = getTreeInEditor(editor);
  ATerm path, newTree;
  int idx;

  idx = ATindexOf(focuses, focus, 0);
  if (idx == -1) {
    ATerror("Updating a non-existing focus: %t\n", focus);
    return editor;
  }
  else {
    path = getFocusPath(focus);
    newTree = updateTerm(editorTree, path, tree);
    newTree = annotateTreeWithPosInfo(newTree);
    editor = replaceTreeInEditor(editor, newTree);

    focuses = ATremoveElementAt(focuses, idx);
    editor = replaceFocusesInEditor(editor, focuses);

    return editor;
  }
}

/*}}}  */
/*{{{  static ATerm moveFocusToStartSymbol(ATerm editor, int location) */

static ATerm
moveFocusToStartSymbol(ATerm editor, int location)
{
  ATerm editorTree = getTreeInEditor(editor);
  ATerm locationPath = getPathInTree(editorTree, location);
  ATerm locationFocus = createFocus(editorTree, locationPath);

  locationFocus = expandFocusToStartSymbol(editor, locationFocus);
  editor = setCurrentFocus(editor, setDirty(locationFocus));
  editor = joinDirtyFocuses(editor);
  return editor;
}

/*}}}  */
/*{{{  ATerm makeTreeInvalidInEditor(ATerm editor) */

ATerm
makeTreeInvalidInEditor(ATerm editor)
{
  ATerm topFocus, area, length, newEditor;

  editor = moveFocusToTop(editor);
  topFocus = getCurrentFocus(editor);
  area = getFocusArea(topFocus);
  length = getLengthOfArea(area);
  newEditor = newEditorInstanceGivenLength(length);

  return newEditor;
}

/*}}}  */
/*{{{  ATerm insertCharsAtLocation(ATerm editor, int location, char *text) */

ATerm
insertCharsAtLocation(ATerm editor, int location, char *text)
{
  int textLength = strlen(text);

/* After makeFocusToStartSymbol, the first element in focuses
 * is the focus being edited.
 */
  editor = moveFocusToStartSymbol(editor, location);

  return updateEditorWithInsertions(editor, location, textLength);
}

/*}}}  */
/*{{{  ATerm deleteCharsAtLocation(ATerm editor, int location, int count) */

ATerm
deleteCharsAtLocation(ATerm editor, int location, int count)
{

  if (location > 0) {
    location--;
  }

  editor = moveFocusToStartSymbol(editor, location);
  return updateEditorWithDeletions(editor, location, count);

}

/*}}}  */
/*{{{  ATerm moveFocusInEditor(ATerm editor, ATerm move) */

ATerm
moveFocusInEditor(ATerm editor, ATerm move)
{
  ATerm focus = getCurrentFocus(editor);

  if (!isEmptyFocus(focus)) {
    return applyMoveToFocus(editor, move);
  }
  else {
    return moveFocusToTop(editor);
  }
}

/*}}}  */
