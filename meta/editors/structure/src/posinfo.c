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
#include "path.h"
#include "posinfo.h"
#include "tree.h"

/*}}}  */

/*{{{  static ATerm adjustLengthInNode(ATerm tree, int newLength) */

static ATerm
adjustLengthInNode(ATerm tree, int newLength)
{
  int treeLength = getTreeLength(tree);

  treeLength = treeLength + newLength;
  return putTreeLength(tree, treeLength);
}

/*}}}  */
/*{{{  static ATermList annotateListWithPosInfo(ATermList list) */

static ATermList
annotateListWithPosInfo(ATermList list)
{
  ATerm elem, newElem;
  ATermList newList = ATempty;

  while (!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    newElem = annotateTreeWithPosInfo(elem);
    newList = ATinsert(newList, newElem);
  }
  return ATreverse(newList);
}

/*}}}  */
/*{{{  static int calcYieldLength(ATermList list) */

static int
calcYieldLength(ATermList list)
{
  int totalLength = 0;
  ATerm elem;

  while (!ATisEmpty(list)) {
    elem = ATgetFirst(list);
    list = ATgetNext(list);
    totalLength = totalLength + getTreeLength(elem);
  }
  return totalLength;
}

/*}}}  */
/*{{{  ATerm updatePosInfo(ATerm tree, ATerm path, int length) */

ATerm
updatePosInfo(ATerm tree, ATerm path, int length)
{
  ATerm newTree, newNode;
  ATerm subTree;

  subTree = getSubTree(tree, path);
  newNode = adjustLengthInNode(subTree, length);
  if (isRootPath(path)) {
    newTree = updateTerm(tree, path, newNode);
  }
  else {
    ATerm tmpTree;

    tmpTree = updatePosInfo(tree, goUp(path), length);
    newTree = updateTerm(tmpTree, path, newNode);
  }
  return newTree;
}

/*}}}  */
/*{{{  ATerm annotateTreeWithPosInfo(ATerm tree) */

ATerm
annotateTreeWithPosInfo(ATerm tree)
{
  char *txt;
  int totalLength;
  ATerm t0, t1, t2, t3, t4, t5, t6, t7, t8, newTree;

  if (asfix_is_term(tree)) {
    t0 = ATgetArgument(tree, 0);
    t1 = ATgetArgument(tree, 1);
    t2 = ATgetArgument(tree, 2);
    t3 = ATgetArgument(tree, 3);
    t4 = ATgetArgument(tree, 4);
    t5 = annotateTreeWithPosInfo(ATgetArgument(tree, 5));
    t6 = annotateTreeWithPosInfo(ATgetArgument(tree, 6));
    t7 = annotateTreeWithPosInfo(ATgetArgument(tree, 7));
    t8 = ATgetArgument(tree, 8);
    newTree =
      (ATerm) ATmakeAppl(symbol_term, t0, t1, t2, t3, t4, t5, t6, t7, t8);
    totalLength = getTreeLength(t5) + getTreeLength(t6) + getTreeLength(t7);
    return ATsetAnnotation(newTree, ATparse("length"),
			   ATmake("length(<int>)", totalLength));
  }
  else if (asfix_is_literal(tree) || asfix_is_sep(tree) ||
	   asfix_is_lex(tree) || asfix_is_var(tree)
	   || asfix_is_whitespace(tree)) {
    txt = ATgetName(ATgetAFun((ATermAppl) ATgetArgument(tree, 0)));

    return ATsetAnnotation(tree, ATparse("length"),
			   ATmake("length(<int>)", strlen(txt)));
  }
  else if (asfix_is_appl(tree) || asfix_is_list(tree)) {
    AFun fun = ATgetAFun(tree);

    t0 = ATgetArgument(tree, 0);
    t1 = ATgetArgument(tree, 1);
    t2 = (ATerm) annotateListWithPosInfo((ATermList) ATgetArgument(tree, 2));
    newTree = (ATerm) ATmakeAppl3(fun, t0, t1, t2);
    totalLength = calcYieldLength((ATermList) t2);
    return ATsetAnnotation(newTree, ATparse("length"),
			   ATmake("length(<int>)", totalLength));
  }
  return tree;
}

/*}}}  */

/*{{{  int getTreeLength(ATerm term) */

int
getTreeLength(ATerm term)
{
  int length;
  ATerm termLength = ATgetAnnotation(term, ATparse("length"));

  if (ATmatch(termLength, "length(<int>)", &length)) {
    return length;
  }
  else {
    return 0;
  }
}

/*}}}  */
/*{{{  ATerm putTreeLength(ATerm tree, int length) */

ATerm
putTreeLength(ATerm tree, int length)
{
  return ATsetAnnotation(tree, ATparse("length"),
			 ATmake("length(<int>)", length));
}

/*}}}  */
