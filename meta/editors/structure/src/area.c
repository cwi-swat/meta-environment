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
#include "area.h"
#include "path.h"
#include "tree.h"
#include "posinfo.h"

ATerm
newLength(int length)
{
  return ATmake("length(<int>)", length);
}

int
getLength(ATerm atLength)
{
  int length;

  if (ATmatch(atLength, "length(<int>)", &length)) {
    return length;
  }
  else {
    ATerror("Illegal length\n");
    return -1;
  }
}

ATerm
newStart(int start)
{
  return ATmake("start(<int>)", start);
}

ATerm
newArea(ATerm start, ATerm length)
{
  return ATmake("area(<term>,<term>)", start, length);
}

ATerm
getLengthOfArea(ATerm area)
{
  ATerm atLength;

  if (ATmatch(area, "area(<term>,<term>)", NULL, &atLength)) {
    return atLength;
  }
  else {
    ATerror("Illegal area\n");
    return NULL;
  }
}

int
getIntLengthOfArea(ATerm area)
{
  int length;
  ATerm atLength = getLengthOfArea(area);

  if (ATmatch(atLength, "length(<int>)", &length)) {
    return length;
  }
  else {
    ATerror("Illegal length\n");
    return -1;
  }
}

static ATerm
setLengthOfArea(ATerm area, ATerm newLength)
{
  ATerm atStart;
  ATerm atLength;

  if (ATmatch(area, "area(<term>,<term>)", &atStart, &atLength)) {
    return ATmake("area(<term>,<term>)", atStart, newLength);
  }
  else {
    ATerror("Illegal area\n");
    return area;
  }
}

ATerm
setIntLengthOfArea(ATerm area, int newLength)
{
  ATerm atLength = ATmake("length(<int>)", newLength);

  return setLengthOfArea(area, atLength);
}

static ATerm
getStartOfArea(ATerm area)
{
  ATerm atStart;

  if (ATmatch(area, "area(<term>,<term>)", &atStart, NULL)) {
    return atStart;
  }
  else {
    ATerror("Illegal area\n");
    return NULL;
  }
}

int
getIntStartOfArea(ATerm area)
{
  int start;
  ATerm atStart = getStartOfArea(area);

  if (ATmatch(atStart, "start(<int>)", &start)) {
    return start;
  }
  else {
    ATerror("Illegal start\n");
    return -1;
  }
}

static ATerm
setStartOfArea(ATerm area, ATerm newStart)
{
  ATerm atStart;
  ATerm atLength;

  if (ATmatch(area, "area(<term>,<term>)", &atStart, &atLength)) {
    return ATmake("area(<term>,<term>)", newStart, atLength);
  }
  else {
    ATerror("Illegal area\n");
    return area;
  }
}

ATerm
setIntStartOfArea(ATerm area, int newStart)
{
  ATerm atStart = ATmake("start(<int>)", newStart);

  return setStartOfArea(area, atStart);
}

static int
areaStartRecursive(ATermList steps, ATerm tree)
{
  ATerm arg;
  ATermList args;
  int step, i, length;

  if (ATisEmpty(steps)) {
    return 0;
  }

  assert(asfix_is_appl(tree) || asfix_is_list(tree));

  step = ATgetInt((ATermInt) ATgetFirst(steps));
  args = (ATermList) ATgetArgument((ATermAppl) tree, 2);
  length = 0;
  for (i = 0; i < step; i++) {
    length += getTreeLength(ATelementAt(args, i));
  }
  arg = ATelementAt(args, step);
  return length + areaStartRecursive(ATgetNext(steps), arg);
}

static int
areaStart(ATerm tree, ATerm path)
{
  ATerm leftWs, subTree;
  ATermList steps;
  int leftWsLength;

  assert(asfix_is_term(tree));

  if (isRootPath(path)) {
    return 0;
  }

  leftWs = ATgetArgument(tree, 5);
  leftWsLength = getTreeLength(leftWs);

  steps = getSteps(path);
  steps = ATgetNext(steps);

  subTree = ATgetArgument((ATermAppl) tree, 6);
  return leftWsLength + areaStartRecursive(steps, subTree);
}

ATerm
createArea(ATerm tree, ATerm path)
{
  ATerm subTree = getSubTree(tree, path);
  int subTreeLength = getTreeLength(subTree);
  ATerm atLength = newLength(subTreeLength);

  int start = areaStart(tree, path) + 1;
  ATerm atStart = newStart(start);

  return newArea(atStart, atLength);
}

ATbool
inArea(ATerm area, int loc)
{
  int start = getIntStartOfArea(area);
  int length = getIntLengthOfArea(area);

  return ((start <= loc) && (loc <= (start + length)));
}

ATbool
afterArea(ATerm area, int loc)
{
  int start = getIntStartOfArea(area);
  int length = getIntLengthOfArea(area);

  return (start + length < loc);
}

ATbool
beforeArea(ATerm area, int loc)
{
  int start = getIntStartOfArea(area);

  return (loc < start);
}
