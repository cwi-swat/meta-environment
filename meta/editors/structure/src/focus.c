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
 * The version of gse is written by Mark van den Brand.
 */

/*}}}  */
/*{{{  includes */

#include <stdlib.h>
#include <assert.h>

#include "se.h"
#include "area.h"
#include "editor.h"
#include "focus.h"
#include "path.h"
#include "sort.h"
#include "tree.h"
#include "posinfo.h"

/*}}}  */
/*{{{  defines */

#define POS_PATH 0
#define POS_SORT 1
#define POS_AREA 2

/*}}}  */
/*{{{  ATerm newFocus(ATerm path, ATerm sort, ATerm area) */

ATerm
newFocus(ATerm path, ATerm sort, ATerm area)
{
  return ATmake("focus(<term>,<term>,<term>)", path, sort, area);
}

/*}}}  */
/*{{{  ATerm makeEmptyFocus() */

ATerm
makeEmptyFocus()
{
  return ATparse("empty-focus");
}

/*}}}  */
/*{{{  ATbool isEmptyFocus(ATerm focus) */

ATbool
isEmptyFocus(ATerm focus)
{
  return ATisEqual(focus, makeEmptyFocus());
}

/*}}}  */
/*{{{  ATerm setDirty(ATerm focus) */

ATerm
setDirty(ATerm focus)
{
  return ATsetAnnotation(focus, ATparse("focusstatus"), ATparse("dirty"));
}

/*}}}  */
/*{{{  static ATbool isDirty(ATerm focus) */

static ATbool
isDirty(ATerm focus)
{
  return ATisEqual(ATgetAnnotation(focus, ATparse("focusstatus")),
		   ATparse("dirty"));
}

/*}}}  */
/*{{{  ATerm setClean(ATerm focus) */

ATerm
setClean(ATerm focus)
{
  return ATsetAnnotation(focus, ATparse("focusstatus"), ATparse("clean"));
}

/*}}}  */
/*{{{  ATerm newFocusList(ATerm focus) */

ATerm
newFocusList(ATerm focus)
{
  return (ATerm) ATmakeList1(focus);
}

/*}}}  */
/*{{{  ATerm setFocusPath(ATerm focus, ATerm newPath) */

ATerm
setFocusPath(ATerm focus, ATerm newPath)
{
  return (ATerm) ATsetArgument((ATermAppl) focus, newPath, POS_PATH);
}

/*}}}  */
/*{{{  ATerm getFocusPath(ATerm focus) */

ATerm
getFocusPath(ATerm focus)
{
  return ATgetArgument((ATermAppl) focus, POS_PATH);
}

/*}}}  */
/*{{{  ATerm setFocusSort(ATerm focus, ATerm newSort) */

ATerm
setFocusSort(ATerm focus, ATerm newSort)
{
  return (ATerm) ATsetArgument((ATermAppl) focus, newSort, POS_SORT);
}

/*}}}  */
/*{{{  ATerm getFocusSort(ATerm focus) */

ATerm
getFocusSort(ATerm focus)
{
  return ATgetArgument((ATermAppl) focus, POS_SORT);
}

/*}}}  */
/*{{{  ATerm setFocusArea(ATerm focus, ATerm newArea) */

ATerm
setFocusArea(ATerm focus, ATerm newArea)
{
  return (ATerm) ATsetArgument((ATermAppl) focus, newArea, POS_AREA);
}

/*}}}  */
/*{{{  ATerm getFocusArea(ATerm focus) */

ATerm
getFocusArea(ATerm focus)
{
  return ATgetArgument((ATermAppl) focus, POS_AREA);
}

/*}}}  */
/*{{{  ATerm createFocus(ATerm tree, ATerm path) */

ATerm
createFocus(ATerm tree, ATerm path)
{
  ATerm subTree, sort, area;

  subTree = getSubTree(tree, path);
  sort = getReadableSort(getTreeSort(subTree));
  area = createArea(tree, path);

  return ATmake("focus(<term>,<term>,<term>)", path, sort, area);
}

/*}}}  */
/*{{{  ATbool inFocusArea(ATerm focus, int loc) */

ATbool
inFocusArea(ATerm focus, int loc)
{
  return inArea(getFocusArea(focus), loc);
}

/*}}}  */
/*{{{  ATbool beforeFocusArea(ATerm focus, int loc) */

ATbool
beforeFocusArea(ATerm focus, int loc)
{
  ATerm area = getFocusArea(focus);

  return beforeArea(area, loc);
}

/*}}}  */
/*{{{  ATbool afterFocusArea(ATerm focus, int loc) */

ATbool
afterFocusArea(ATerm focus, int loc)
{
  ATerm area = getFocusArea(focus);

  return afterArea(area, loc);
}

/*}}}  */
/*{{{  static ATbool isSubFocus(ATerm focusOne, ATerm focusTwo) */

static ATbool
isSubFocus(ATerm focusOne, ATerm focusTwo)
{
  ATerm pathOne = getFocusPath(focusOne);
  ATerm pathTwo = getFocusPath(focusTwo);

  if (ATisEqual(pathOne, pathTwo)) {
    return ATtrue;
  }
  else {
    return isChildPath(pathOne, pathTwo);
  }
}

/*}}}  */
/*{{{  ATerm expandFocusToStartSymbol(ATerm editor, ATerm focus) */

ATerm
expandFocusToStartSymbol(ATerm editor, ATerm focus)
{
  ATermList startSymbols;
  ATerm editorTree, path, newPath, sort;
  ATerm subTree, readableSort, newArea;

  startSymbols = (ATermList) getStartSymbols(editor);
  editorTree = getTreeInEditor(editor);

  path = getFocusPath(focus);
  newPath = path;
  sort = getFocusSort(focus);
  readableSort = getReadableSort(sort);

  while (!isStartSymbol(readableSort, startSymbols) && !isRootPath(newPath)) {
    newPath = goUp(newPath);
    subTree = getSubTree(editorTree, newPath);
    sort = getTreeSort(subTree);
    readableSort = getReadableSort(sort);
  }

  if (!ATisEqual(path, newPath)) {
    newArea = createArea(editorTree, newPath);
    focus = newFocus(newPath, sort, newArea);
  }
  return focus;
}

/*}}}  */
/*{{{  ATerm joinFocuses(ATerm editor) */

ATerm
joinFocuses(ATerm editor)
{
  ATerm dirtyFocus;
  ATermList dirtyFocusList = ATempty;
  ATbool isCurFocusClean = ATtrue;
  ATermList dirtyFocuses;
  ATerm curFocus;

  curFocus = getCurrentFocus(editor);

  if (isDirty(curFocus)) {
    return editor;
  }
  else {
    dirtyFocuses = (ATermList) getFocuses(editor);
    while (!ATisEmpty(dirtyFocuses)) {
      dirtyFocus = ATgetFirst(dirtyFocuses);
      if (!isSubFocus(dirtyFocus, curFocus)) {
	dirtyFocusList = ATinsert(dirtyFocusList, dirtyFocus);
      }
      else {
	isCurFocusClean = ATfalse;
      }
      dirtyFocuses = ATgetNext(dirtyFocuses);
    }
    if (!isCurFocusClean) {
      curFocus = expandFocusToStartSymbol(editor, curFocus);
      curFocus = setDirty(curFocus);
      dirtyFocusList = ATinsert(dirtyFocusList, curFocus);
    }
    return setFocuses(editor, (ATerm) dirtyFocusList);
  }
}

/*}}}  */
/*{{{  ATerm joinDirtyFocuses(ATerm editor) */

ATerm
joinDirtyFocuses(ATerm editor)
{
  ATerm dirtyFocus;
  ATermList dirtyFocusList = ATempty;
  ATermList dirtyFocuses;
  ATerm curFocus;

  curFocus = getCurrentFocus(editor);
  assert(isDirty(curFocus));

/* Check whether the current focus is a subfocus
 * of one of the dirty focuses. If so,
 * replace the current focus with the dirty focus.
 */
  dirtyFocuses = (ATermList) getFocuses(editor);
  while (!ATisEmpty(dirtyFocuses)) {
    dirtyFocus = ATgetFirst(dirtyFocuses);
    if (isSubFocus(curFocus, dirtyFocus)) {
      return setCurrentFocus(editor, dirtyFocus);
    }
    dirtyFocuses = ATgetNext(dirtyFocuses);
  }

/* Check whether the current focus is a superfocus
 * of one or more of the dirty focuses, if so,
 * replace all these focuses by the current focus.
 */
  dirtyFocuses = (ATermList) getFocuses(editor);
  while (!ATisEmpty(dirtyFocuses)) {
    dirtyFocus = ATgetFirst(dirtyFocuses);
    if (!isSubFocus(dirtyFocus, curFocus)) {
      dirtyFocusList = ATinsert(dirtyFocusList, dirtyFocus);
    }
    dirtyFocuses = ATgetNext(dirtyFocuses);
  }
  dirtyFocusList = ATinsert(dirtyFocusList, curFocus);

  return setFocuses(editor, (ATerm) dirtyFocusList);
}

/*}}}  */
/*{{{  ATerm updateFocus(ATerm tree, ATerm focus, int location, int length) */

ATerm
updateFocus(ATerm tree, ATerm focus, int location, int length)
{
  int areaLength;
  ATerm area, newArea;

  area = getFocusArea(focus);
  if (inFocusArea(focus, location)) {
    areaLength = getIntLengthOfArea(area);
    newArea = setIntLengthOfArea(area, areaLength + length);
    return setFocusArea(focus, newArea);
  }
  else {
    return focus;
  }
}

/*}}}  */
/*{{{  static ATerm moveFocusUp(ATerm editor) */

static ATerm
moveFocusUp(ATerm editor)
{
  ATerm curFocus = getCurrentFocus(editor), newFocus;
  ATerm path = getFocusPath(curFocus);
  ATerm tree = getTreeInEditor(editor);

  newFocus = createFocus(tree, goUp(path));
  return setCurrentFocus(editor, newFocus);
}

/*}}}  */
/*{{{  static ATerm moveFocusRight(ATerm editor) */

static ATerm
moveFocusRight(ATerm editor)
{
  ATerm curFocus = getCurrentFocus(editor), newFocus;
  ATerm path = getFocusPath(curFocus), newPath;
  ATerm tree = getTreeInEditor(editor), subTree;

  subTree = getSubTree(tree, path);
  if (subTree) {
    newPath = goRight(path);
		if(!ATisEqual(path, newPath)) {
			subTree = getSubTree(tree, newPath);
			if (subTree) {
				newFocus = createFocus(tree, newPath);
				editor = setCurrentFocus(editor, newFocus);
				if (asfix_is_appl(subTree) ||
						asfix_is_list(subTree) ||
						asfix_is_lex(subTree) || asfix_is_var(subTree)) {
					return editor;
				}
				return moveFocusRight(editor);
			}
		}
	}
  return moveFocusUp(editor);
}

/*}}}  */
/*{{{  static ATerm moveFocusDown(ATerm editor) */

static ATerm
moveFocusDown(ATerm editor)
{
  ATerm curFocus = getCurrentFocus(editor), newFocus;
  ATerm path = getFocusPath(curFocus), newPath;
  ATerm tree = getTreeInEditor(editor), subTree;

	subTree = getSubTree(tree, path);
	
	if (subTree) {
    if (asfix_is_appl(subTree) || asfix_is_list(subTree) || isRootPath(path)) {
      newPath = goDown(path);
      subTree = getSubTree(tree, newPath);
      newFocus = createFocus(tree, newPath);
      editor = setCurrentFocus(editor, newFocus);
      if (asfix_is_appl(subTree) ||
					asfix_is_list(subTree) ||
					asfix_is_lex(subTree) || asfix_is_var(subTree)) {
				return editor;
      }
      return moveFocusRight(editor);
    }
  } 

  return editor;
}

/*}}}  */
/*{{{  static ATerm moveFocusLeft(ATerm editor) */

static ATerm
moveFocusLeft(ATerm editor)
{
  ATerm curFocus = getCurrentFocus(editor), newFocus;
  ATerm path = getFocusPath(curFocus), newPath;
  ATerm tree = getTreeInEditor(editor), subTree;

  subTree = getSubTree(tree, path);
  if (subTree) {
    newPath = goLeft(path);
    if (!ATisEqual(path, newPath)) {
      subTree = getSubTree(tree, newPath);
      newFocus = createFocus(tree, newPath);
      editor = setCurrentFocus(editor, newFocus);
      if (asfix_is_appl(subTree) ||
					asfix_is_list(subTree) ||
					asfix_is_lex(subTree) || asfix_is_var(subTree)) {
				return editor;
      }
      return moveFocusLeft(editor);
    }
  }
  return moveFocusUp(editor);
}

/*}}}  */
/*{{{  ATerm applyMoveToFocus(ATerm editor, ATerm move) */

ATerm
applyMoveToFocus(ATerm editor, ATerm move)
{
  if (ATisEqual(move, ATparse(MOVE_UP))) {
    return moveFocusUp(editor);
  }
  else if (ATisEqual(move, ATparse(MOVE_DOWN))) {
    return moveFocusDown(editor);
  }
  else if (ATisEqual(move, ATparse(MOVE_RIGHT))) {
    return moveFocusRight(editor);
  }
  else if (ATisEqual(move, ATparse(MOVE_LEFT))) {
    return moveFocusLeft(editor);
  }
  else {
    ATerror("Illegal move action\n");
    return editor;
  }
}

/*}}}  */
