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


#include <stdlib.h>
#include <assert.h>

#include "se.h"
#include "path.h"
#include "posinfo.h"

#define POS_ELEMENTS 0

ATerm
newPath()
{
  return ATmake("path(<list>)", ATempty);
}

ATermList
getSteps(ATerm path)
{
  ATermList steps = ATempty;

  ATmatch(path, "path(<list>)", &steps);
  return steps;
}

ATbool
isRootPath(ATerm path)
{
  return ATisEqual(path, newPath());
}

ATerm
makeLeftWsPath()
{
  return ATmake("path(<list>)", ATmakeList1((ATerm) ATmakeInt(5)));
}

ATerm
makeAsFixTermPath()
{
  return ATmake("path(<list>)", ATmakeList1((ATerm) ATmakeInt(6)));
}

ATerm
makeRightWsPath()
{
  return ATmake("path(<list>)", ATmakeList1((ATerm) ATmakeInt(7)));
}

ATerm
goRight(ATerm path)
{
  ATermList steps;
  ATerm lastStep;
  int argNumber, idx;

  if (isRootPath(path)) {
    return path;
  } else if (ATisEqual(path, makeRightWsPath())) {
		return newPath();
	}
  else {
    steps = getSteps(path);
    idx = ATgetLength(steps) - 1;
    lastStep = ATgetLast(steps);

    argNumber = ATgetInt((ATermInt) lastStep) + 1;
    lastStep = (ATerm) ATmakeInt(argNumber);

    steps = ATreplace(steps, lastStep, idx);
    return ATmake("path(<list>)", steps);
  }
}

ATerm
goLeft(ATerm path)
{
  ATermList steps;
  ATerm lastStep;
  int argNumber, idx;

  if (isRootPath(path)) {
    return path;
  } else if (ATisEqual(path, makeLeftWsPath())) {
		return newPath();
	}
  else {
    steps = getSteps(path);

    idx = ATgetLength(steps) - 1;
    lastStep = ATgetLast(steps);

    argNumber = ATgetInt((ATermInt) lastStep);
    if (argNumber > 0) {
      argNumber--;
      lastStep = (ATerm) ATmakeInt(argNumber);

      steps = ATreplace(steps, lastStep, idx);
      return ATmake("path(<list>)", steps);
    }
    else {
      return path;
    }
  }
}

ATerm
goDown(ATerm path)
{
  ATermList steps;
  ATerm newStep;

	if(isRootPath(path)) {
		return makeAsFixTermPath();
	}

  steps = getSteps(path);
  newStep = (ATerm) ATmakeInt(0);

  steps = ATappend(steps, newStep);
  return ATmake("path(<list>)", steps);
}

ATerm
goUp(ATerm path)
{
  ATermList steps;

  if (isRootPath(path)) {
    return path;
  }
  else {
    steps = getSteps(path);
    steps = ATgetPrefix(steps);
    return ATmake("path(<list>)", steps);
  }
}

static ATerm
getPathToLastNode(ATerm tree, ATerm path)
{
  int nrOfArgs, i;
  ATerm arg = NULL;
  ATermList args;

  if (asfix_is_appl(tree) || asfix_is_list(tree)) {
    path = goDown(path);
    args = (ATermList) ATgetArgument((ATermAppl) tree, 2);
    nrOfArgs = ATgetLength(args) - 1;
    for (i = 0; i < nrOfArgs; i++) {
      path = goRight(path);
    }
    arg = ATelementAt(args, nrOfArgs);
    return getPathToLastNode(arg, path);
  }
  else {
    return path;
  }
}

ATerm
getPathInTreeRecursive(ATerm tree, int location, ATerm path)
{
  int argLength, i;
  ATerm arg = NULL;
  ATermList args;

  if (asfix_is_appl(tree) || asfix_is_list(tree)) {
    path = goDown(path);
    args = (ATermList) ATgetArgument((ATermAppl) tree, 2);
    for (i = 0; i < ATgetLength(args); i++) {
      arg = ATelementAt(args, i);
      argLength = getTreeLength(arg);
      if (location <= argLength) {
	break;
      }
      path = goRight(path);
      location -= argLength;
    }
    return getPathInTreeRecursive(arg, location, path);
  }
  else {
    return path;
  }
}

ATerm
getPathInTree(ATerm tree, int location)
{
  int termLength, leftWsLength;
  ATerm subTree, leftWs, path;

  assert(asfix_is_term(tree));

  leftWs = ATgetArgument(tree, 5);
  leftWsLength = getTreeLength(leftWs);
  if (location > leftWsLength) {
    location -= leftWsLength;
    subTree = ATgetArgument(tree, 6);
    termLength = getTreeLength(subTree);
    if (location > termLength) {
      /* You have clicked beyond end of term */
      path = makeRightWsPath();
    }
    else {
      path = getPathInTreeRecursive(subTree, location, makeAsFixTermPath());
    }
  }
  else {
    path = makeLeftWsPath();
  }
  return path;
}

static ATbool
isChildPathRecursive(ATermList child, ATermList parent)
{
  /* Child may be shorter than parent */
  if (ATisEmpty(child) && !ATisEmpty(parent)) {
    return ATfalse;
  }

  /* Child may be longer than parent */
  if (ATisEmpty(parent)) {
    return ATtrue;
  }

  /* Head of parent and child may differ -=> disjoint paths */
  if (!ATisEqual(ATgetFirst(child), ATgetFirst(parent))) {
    return ATfalse;
  }

  /* No decision possible yet, continue with tail of paths */
  return isChildPathRecursive(ATgetNext(child), ATgetNext(parent));
}

/* Is <child> a child (a longer path) of <parent>?
 * E.g., path(0,1,4,1,0) is a child of path(0,1,4,1).
 * This is a strict function: <P> is not a child of <P>
 */
ATbool
isChildPath(ATerm child, ATerm parent)
{
  ATermList childPath = (ATermList) ATgetArguments((ATermAppl) child);
  ATermList parentPath = (ATermList) ATgetArguments((ATermAppl) parent);

  return isChildPathRecursive(childPath, parentPath);
}
