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

static int lengthOfArgs(PT_Args args);

static int
lengthOfTree(PT_Tree tree)
{
  if (PT_isTreeChar(tree)) {
    return 1;
  }

  if (PT_isTreeList(tree) || PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    return lengthOfArgs(args);
  }

  if (PT_isTreeLit(tree)) {
    char *str = PT_getTreeString(tree);
    return strlen(str);
  }
  
  ATerror("lengthOfTree: unknown term %t\n", tree);
  return 0;
}

static int
lengthOfArgs(PT_Args args)
{
  int length = 0;

  if (PT_isArgsEmpty(args)) {
    return 0;
  }

  while (PT_hasArgsHead(args)) {
    PT_Tree tree = PT_getArgsHead(args);
    args = PT_getArgsTail(args);

    length = length + lengthOfTree(tree);
  }

  return length;
}

static int yieldArgsRecursive(PT_Args args, int idx, char *buf, int bufSize);

static int
yieldTreeRecursive(PT_Tree tree, int idx, char *buf, int bufSize)
{
  assert(idx <= bufSize);

  if (PT_isTreeChar(tree)) {
    buf[idx++] = PT_getTreeCharacter(tree);
  }
  else if (PT_isTreeList(tree) || PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    idx = yieldArgsRecursive(args, idx, buf, bufSize);
  }
  else if (PT_isTreeLit(tree)) {
    int i, len;
    char *lit = PT_getTreeString(tree);
    len = strlen(lit);

    for (i = 0; i < len; i++) {
      buf[idx++] = lit[i];
    }
  }
  else {
    ATerror("yieldTreeRecursive: unknown term %t\n", tree);
  }

  return idx;
}

static int
yieldArgsRecursive(PT_Args args, int idx, char *buf, int bufSize)
{
  while (PT_hasArgsHead(args)) {
    PT_Tree tree = PT_getArgsHead(args);
    args = PT_getArgsTail(args);
   
    idx = yieldTreeRecursive(tree, idx, buf, bufSize);
  }

  return idx;
}

char *PT_yieldTree(PT_Tree tree)
{
  static char *buffer = NULL;
  static int   bufferSize = 0;
  int          idx = 0;
  int          len;

  len = lengthOfTree(tree)+1;

  if (len > bufferSize) {
    buffer = (char *)realloc(buffer, len*sizeof(char));
    bufferSize = len;
  }

  idx = yieldTreeRecursive(tree, 0, buffer, len);

  buffer[idx++] = '\0';
  assert(idx == len);

  return buffer;
}

char *PT_yieldParseTree(PT_ParseTree tree)
{
  if (PT_isParseTreeTree(tree)) {
    return PT_yieldTree(PT_getParseTreeTree(tree));
  }

  ATerror("PT_yieldParseTree: not a parsetree: %t\n", tree);
  return NULL;
}
