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
#include "sort.h"
#include "tree.h"
#include "area.h"
#include "focus.h"

/*}}}  */

/*{{{  ATerm getTreeSort(ATerm tree) */

ATerm
getTreeSort(ATerm tree)
{
  ATerm t0;

  assert(ATgetType(tree) == AT_APPL);

  if (asfix_is_term(tree)) {
    return getTreeSort(ATgetArgument(tree, 6));
  }
  else if (asfix_is_lex(tree) || asfix_is_var(tree)) {
    return ATgetArgument(tree, 1);
  }
  else if (asfix_is_appl(tree)) {
    t0 = ATgetArgument(tree, 0);
    return ATgetArgument(t0, 6);
  }
  else if (asfix_is_list(tree)) {
    return ATgetArgument(tree, 0);
  }
  else {
    return newSort("invalid");
  }
}

/*}}}  */
/*{{{  ATerm getSubTree(ATerm tree, ATerm path) */

ATerm
getSubTree(ATerm tree, ATerm path)
{
  ATerm subTree;
  ATermList steps;
  int step;

  assert(asfix_is_term(tree));

  if (isRootPath(path)) {
    return tree;
  }

  steps = getSteps(path);
  step = ATgetInt((ATermInt) ATgetFirst(steps));
  steps = ATgetNext(steps);

  /* extract appl from term(..., ws, appl, ws) */
  subTree = ATgetArgument((ATermAppl) tree, step);

  while (!ATisEmpty(steps)) {
    step = ATgetInt((ATermInt) ATgetFirst(steps));
    steps = ATgetNext(steps);

    assert(ATgetType(subTree) == AT_APPL);

    if (isBasicLeafNode(subTree)) {
      return NULL;
    }

    /* Extract args from appl */
    subTree = ATgetArgument((ATermAppl) subTree, 2);

    /* Continue with arguments of appl-node */
    subTree = ATelementAt((ATermList) subTree, step);
  }

  return subTree;
}

/*}}}  */

static char *leftWs = NULL;
static char *rightWs = NULL;

/*{{{  ATerm concatLeftWs(ATerm ws) */

ATerm
concatLeftWs(ATerm ws)
{
  char *localLeftWs;
  char *newWs;
  ATerm atNewWs;

  if (ATmatch(ws, "w(<str>)", &localLeftWs)) {
    newWs = (char *) malloc(strlen(localLeftWs) + strlen(leftWs) + 1);
    sprintf(newWs, "%s%s", localLeftWs, leftWs);
    atNewWs = ATmake("w(<str>)", newWs);
    free(newWs);
    return atNewWs;
  }
  else {
    ATerror("Illegal whitespace construct %t\n", ws);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm concatRightWs(ATerm ws) */

ATerm
concatRightWs(ATerm ws)
{
  char *localRightWs;
  char *newWs;
  ATerm atNewWs;

  if (ATmatch(ws, "w(<str>)", &localRightWs)) {
    newWs = (char *) malloc(strlen(localRightWs) + strlen(rightWs) + 1);
    sprintf(newWs, "%s%s", rightWs, localRightWs);
    atNewWs = ATmake("w(<str>)", newWs);
    free(newWs);
    return atNewWs;
  }
  else {
    ATerror("Illegal whitespace construct %t\n", ws);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm updateTermRecursive(ATerm tree, ATerm path, ATerm newTree) */

ATerm
updateTermRecursive(ATerm tree, ATermList steps, ATerm subTree)
{
  ATermList oldArgs, newArgs;
  ATerm newTree, oldArg, newArg, posInfo;
  ATerm argLeftWs, argRightWs;
  int step;

  if (ATisEmpty(steps)) {
    return subTree;
  }

  posInfo = ATgetAnnotation(tree, ATparse("length"));
  step = ATgetInt((ATermInt) ATgetFirst(steps));

  oldArgs = (ATermList) ATgetArgument((ATermAppl) tree, 2);
  oldArg = ATelementAt((ATermList) oldArgs, step);

  if (ATgetLength(steps) == 1) {
    newArg = subTree;
  }
  else {
    newArg = updateTermRecursive(oldArg, ATgetNext(steps), subTree);
  }
  newArgs = ATreplace(oldArgs, newArg, step);

  if (leftWs != NULL && step > 0) {
    /* concat leftWs with leftWs in argumentlist */
    argLeftWs = ATelementAt((ATermList) oldArgs, step - 1);
    argLeftWs = concatLeftWs(argLeftWs);
    newArgs = ATreplace(newArgs, argLeftWs, step - 1);
    leftWs = NULL;
  }

  if (rightWs != NULL && step < ATgetLength(oldArgs) - 1) {
    /* concat rightWs with rightWs in argumentlist */
    argRightWs = ATelementAt((ATermList) oldArgs, step + 1);
    argRightWs = concatRightWs(argRightWs);
    newArgs = ATreplace(newArgs, argRightWs, step + 1);
    rightWs = NULL;
  }

  newTree = (ATerm) ATsetArgument((ATermAppl) tree, (ATerm) newArgs, 2);
  return ATsetAnnotation(newTree, ATparse("length"), posInfo);
}

/*}}}  */
/*{{{  ATerm updateTerm(ATerm tree, ATerm path, ATerm newTree) */

ATerm
updateTerm(ATerm tree, ATerm path, ATerm subTree)
{
  ATermList steps;
  ATerm oldArg, newArg, newTree, atLeftWs, atRightWs;
  ATerm treeLeftWs, treeRightWs, posInfo;

  assert(asfix_is_term(tree));

  if (isRootPath(path)) {
    assert(asfix_is_term(subTree));
    return subTree;
  }

  posInfo = ATgetAnnotation(tree, ATparse("length"));

  if (asfix_is_term(subTree)) {
    atLeftWs = (ATerm) ATgetArgument((ATermAppl) subTree, 5);
    if (ATmatch(atLeftWs, "w(<str>)", &leftWs) && strlen(leftWs) == 0) {
      leftWs = NULL;
    }

    atRightWs = (ATerm) ATgetArgument((ATermAppl) subTree, 7);
    if (ATmatch(atRightWs, "w(<str>)", &rightWs) && strlen(rightWs) == 0) {
      rightWs = NULL;
    }

    subTree = (ATerm) ATgetArgument((ATermAppl) subTree, 6);

  }

  steps = getSteps(path);
  oldArg = (ATerm) ATgetArgument((ATermAppl) tree, 6);
  newArg = updateTermRecursive(oldArg, ATgetNext(steps), subTree);

  if (leftWs != NULL) {
    treeLeftWs = ATgetArgument((ATermAppl) tree, 5);
    treeLeftWs = concatLeftWs(treeLeftWs);
    tree = (ATerm) ATsetArgument((ATermAppl) tree, treeLeftWs, 5);
    leftWs = NULL;
  }

  if (rightWs != NULL) {
    treeRightWs = ATgetArgument((ATermAppl) tree, 7);
    treeRightWs = concatRightWs(treeRightWs);
    tree = (ATerm) ATsetArgument((ATermAppl) tree, treeRightWs, 7);
    rightWs = NULL;
  }

  newTree = (ATerm) ATsetArgument((ATermAppl) tree, newArg, 6);
  return ATsetAnnotation(newTree, ATparse("length"), posInfo);
}

/*}}}  */
/*{{{  ATbool isBasicLeafNode(ATerm tree) */

ATbool
isBasicLeafNode(ATerm tree)
{
  return !(asfix_is_appl(tree) ||
	   asfix_is_list(tree) ||
	   asfix_is_term(tree) || asfix_is_var(tree) || asfix_is_lex(tree));
}

/*}}}  */
