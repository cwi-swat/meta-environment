#! /bin/sh
#
# $Id$
#

BUILTIN_NAMES=$1

cat  << END_OF_FILE 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <MEPT-utils.h>
#include <aterm2.h>
#include "asf-builtins.h"

/* DO NOT EDIT: This file is generated */

static ATbool initialized = ATfalse;

void initBuiltins(void)
{
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
  echo "  if (!strcmp(name, \"${b}\")) {" 
  echo "    result = ${b}(builtin, input);" 
  echo "  }"
done
`

  if (result == NULL) {
    ATwarning("WARNING: builtin %s failed to return a valid term\n", name);
    return input;
  }

  return result; 
}
END_OF_FILE
