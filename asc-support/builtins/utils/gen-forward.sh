#! /bin/sh
#
# $Id$
#

BUILTIN_NAMES=$1

getName() {
  echo $1 | sed 's/\([a-z\-]*\)_\([0-9]*\)/\1/'
}

cat  << END_OF_FILE 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <MEPT-utils.h>
#include <aterm2.h>
#include "asf-builtins.h"
#include "Library.h"

/* DO NOT EDIT: This file is generated */

static ATbool initialized = ATfalse;

void initBuiltins(void)
{
  CO_initLibraryApi();
  PTPT_initPTMEPTApi();
  initialized = ATtrue;

  return;
}

/* Naive implementation: just do strcmp's until we find the correct
 * function. Idea: use asc-support or similar hashtable implementation.
 */
PT_Tree forwardBuiltin(ATerm builtin, PT_Tree input)
{
  AFun afun;
  char *name = NULL;
  PT_Tree result = input;

  assert(initialized && "builtins are not initialized");
  assert(ATgetType(builtin) == AT_APPL && "builtins should be ATermAppls");

  afun = ATgetAFun(builtin);
  name = ATgetName(afun);

`
for b in \${BUILTIN_NAMES}; do
  name=\`getName ${b}\`
  echo "  if (!strcmp(name, \\"${name}\\")) {" 
  echo "    result = ASFE_${name}(input);" | sed 's@-@_@g'
  echo "  }"
done
`

  return result; 
}
END_OF_FILE
