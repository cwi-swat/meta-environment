/*

    MEPT -- The Meta-Environment Parse Tree library

    Copyright (C) 2001  Stichting Mathematisch Centrum, Amsterdam,
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

    $Id$
*/

#include <stdlib.h>
#include <string.h>
#include <assert.h> 

#include "MEPT-utils.h"

#define AMB_CLUSTER_START "\n<<<<<<<<<<\n"
#define AMB_CLUSTER_SEP   "\n==========\n"
#define AMB_CLUSTER_END   "\n>>>>>>>>>>\n"

/*{{{  local function declarations */

static int lengthOfArgs(PT_Args args, ATbool visualAmbs);
static int yieldArgsRecursive(PT_Args args, ATbool visualAmbs, int idx, 
			      char *buf, int bufSize);
static int yieldAmbsRecursive(PT_Args args, ATbool visualAmbs, int idx, 
			      char *buf, int bufSize);


/*}}}  */

/*{{{  lengthOfTree(PT_Tree tree, ATbool visualAmbs) */

static int
lengthOfTree(PT_Tree tree, ATbool visualAmbs)
{
  int length = 0;

  if (PT_isTreeChar(tree)) {
    length = 1;
  }
  else if (PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    length = lengthOfArgs(args, visualAmbs);
  }
  else if (PT_isTreeLit(tree) || PT_isTreeFlatLayout(tree)) {
    char *str = PT_getTreeString(tree);
    length = strlen(str);
  }
  else if (PT_isTreeAmb(tree)) {
    PT_Args args = PT_getTreeArgs(tree);

    if (visualAmbs) {
      length += strlen(AMB_CLUSTER_START);
      length += ((PT_getArgsLength(args) - 1) * strlen(AMB_CLUSTER_SEP));
      length += strlen(AMB_CLUSTER_END);
      length += lengthOfArgs(args,visualAmbs);
    }
    else {
      PT_Tree firstChild = PT_getArgsHead(args);
      length = lengthOfTree(firstChild, visualAmbs);
    }
  }
  else { 
    ATerror("lengthOfTree: unknown term %t\n", tree);
  }

  return length;
}

/*}}}  */
/*{{{  lengthOfArgs(PT_Args args, ATbool visualAmbs) */

static int
lengthOfArgs(PT_Args args, ATbool visualAmbs)
{
  int length = 0;

  if (PT_isArgsEmpty(args)) {
    return 0;
  }

  while (PT_hasArgsHead(args)) {
    PT_Tree tree = PT_getArgsHead(args);
    args = PT_getArgsTail(args);

    length = length + lengthOfTree(tree, visualAmbs);
  }

  return length;
}

/*}}}  */
/*{{{  yieldTreeRecursive(PT_Tree tree, ATbool visualAmbs, int idx, char *buf, int bufSize) */

static int
yieldTreeRecursive(PT_Tree tree, ATbool visualAmbs, int idx, char *buf, int bufSize)
{
  assert(idx <= bufSize);

  if (PT_isTreeChar(tree)) {
    buf[idx++] = PT_getTreeCharacter(tree);
  }
  else if (PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    idx = yieldArgsRecursive(args, visualAmbs, idx, buf, bufSize);
  }
  else if (PT_isTreeLit(tree) || PT_isTreeFlatLayout(tree)) {
    int i, len;
    char *lit = PT_getTreeString(tree);
    len = strlen(lit);

    for (i = 0; i < len; i++) {
      buf[idx++] = lit[i];
    }
  }
  else if (PT_isTreeAmb(tree)) {
    PT_Args args = PT_getTreeArgs(tree);

    if (visualAmbs) {
      strcpy(buf+idx,AMB_CLUSTER_START);
      idx += strlen(AMB_CLUSTER_START);
      idx = yieldAmbsRecursive(args,visualAmbs,idx,buf,bufSize);
      strcpy(buf+idx,AMB_CLUSTER_END);
      idx += strlen(AMB_CLUSTER_END);
    }
    else {
      PT_Tree firstTree = PT_getArgsHead(args);
      idx = yieldTreeRecursive(firstTree, visualAmbs, idx,buf,bufSize);
    }
  }
  else {
    ATerror("yieldTreeRecursive: unknown term %t\n", tree);
  }

  return idx;
}

/*}}}  */
/*{{{  yieldArgsRecursive(PT_Args args, ATbool visualAmbs, int idx, char *buf,  */

static int
yieldArgsRecursive(PT_Args args, ATbool visualAmbs, int idx, char *buf, 
		   int bufSize)
{
  while (PT_hasArgsHead(args)) {
    PT_Tree tree = PT_getArgsHead(args);
    args = PT_getArgsTail(args);
   
    idx = yieldTreeRecursive(tree, visualAmbs, idx, buf, bufSize);
  }

  return idx;
}

/*}}}  */
/*{{{  yieldAmbsRecursive(PT_Args args, ATbool visualAmbs, int idx, char *buf,  */

static int yieldAmbsRecursive(PT_Args args, ATbool visualAmbs, int idx, 
			      char *buf, int bufSize)
{
  while (PT_hasArgsHead(args)) {
    PT_Tree tree = PT_getArgsHead(args);
    args = PT_getArgsTail(args);
   
    idx = yieldTreeRecursive(tree, visualAmbs, idx, buf, bufSize);

    if (PT_hasArgsHead(args)) {
      strcpy(buf+idx,AMB_CLUSTER_SEP);
      idx += strlen(AMB_CLUSTER_SEP);
    }
  }

  return idx;
}

/*}}}  */

/*{{{  char *PT_yieldArgs(PT_Args args) */

char *PT_yieldArgs(PT_Args args)
{
  return PT_yieldTree(
           PT_makeTreeAppl(
             PT_makeProductionList(
               PT_makeSymbolSort("")), args));  
}

/*}}}  */
/*{{{  char *PT_yieldTree(PT_Tree tree)  */

char *PT_yieldTree(PT_Tree tree) 
{
  return PT_yieldTreeVisualAmbs(tree, ATfalse);
}

/*}}}  */
/*{{{  char *PT_yieldParseTree(PT_ParseTree tree) */

char *PT_yieldParseTree(PT_ParseTree tree)
{
  return PT_yieldParseTreeVisualAmbs(tree,ATfalse);
}

/*}}}  */
/*{{{  char *PT_yieldTreeVisualAmbs(PT_Tree tree, ATbool visualAmbs) */

char *PT_yieldTreeVisualAmbs(PT_Tree tree, ATbool visualAmbs)
{
  static char *buffer = NULL;
  static int   bufferSize = 0;
  int          idx = 0;
  int          len;

  len = lengthOfTree(tree, visualAmbs)+1;

  if (len > bufferSize) {
    buffer = (char *)realloc(buffer, len*sizeof(char));
    bufferSize = len;
  }

  idx = yieldTreeRecursive(tree, visualAmbs, 0, buffer, len);

  buffer[idx++] = '\0';
  assert(idx == len);

  return buffer;
}

/*}}}  */
/*{{{  char *PT_yieldParseTreeVisualAmbs(PT_ParseTree tree, ATbool visualAmbs) */

char *PT_yieldParseTreeVisualAmbs(PT_ParseTree tree, ATbool visualAmbs)
{
  if (PT_isParseTreeTree(tree)) {
    return PT_yieldTreeVisualAmbs(PT_getParseTreeTop(tree), visualAmbs);
  }

  ATerror("PT_yieldParseTreeWithVisualAmbs: not a parsetree: %t\n", tree);
  return NULL;
}

/*}}}  */

