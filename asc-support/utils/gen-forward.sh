#! /bin/sh
#
# $Id$
#

BUILTIN_NAMES=$1

getName() {
  echo $1 | sed 's/\([a-z\-]*\)_\([0-9]*\)/\1/'
}

getArity() {
  echo $1 | sed 's/\([a-z\-]*\)_\([0-9]*\)/\2/'
}

getActuals() {
  arity=$1
  index=0

  if test ${arity} -ne 0; then
    printf ", "
  fi

  while test ${index} -lt ${arity}; do
    printf "arg${index}"
    index=`expr ${index} + 1`
    if test ${index} -lt ${arity}; then
      printf ", "
    fi
  done

}

cat  << END_OF_FILE 
/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <MEPT-utils.h>
#include <PTMEPT.h>
#include <aterm2.h>
#include "asc-builtins.h"
#include "Library.h"
#include "Error-utils.h"

/*}}} */

/* DO NOT EDIT: This file is generated */

static ATbool initialized = ATfalse;

void initBuiltins(void)
{
  CO_initLibraryApi();
  PTPT_initPTMEPTApi();
  PT_initAsFix2Api(); 
  initErrorApi();
  initialized = ATtrue;

  return;
}

static PT_Tree getBuiltinArgument(PT_Tree builtin, int i)
{
  /* "name" L "(" L <arg0> L "," L <arg1> L "," L <arg2> L  ... */
  /* |-----4------| |------4-----| |-----4------| |-------- ... */

  return PT_getArgsTreeAt(PT_getTreeArgs(builtin),4 + 4 * i);
}

/* Naive implementation: just do strcmp's until we find the correct
 * function. Idea: use asc-support or similar hashtable implementation.
 */
PT_Tree forwardBuiltin(ATerm builtin, PT_Tree input)
{
  PT_Tree result = NULL;
  PT_Symbol type = NULL;
  AFun afun;
  char *name = NULL;

  assert(initialized && "builtins are not initialized");
  assert(ATgetType(builtin) == AT_APPL && "builtins should be ATermAppls");

  afun = ATgetAFun(builtin);
  name = ATgetName(afun);
  type = PT_getProductionRhs(PT_getTreeProd(input));


`
for b in \${BUILTIN_NAMES}; do
  name=\`getName ${b}\`
  arity=\`getArity ${b}\`
  actuals=\`getActuals ${arity}\`
  index=0
  echo "  if (!strcmp(name, \\"${name}\\")) {"
  while test ${index} -lt ${arity}; do
    echo "    PT_Tree arg${index} = getBuiltinArgument(input, ${index});"
    index=\`expr ${index} + 1\`
  done
 
  echo "    result = ASFE_${name}(type ${actuals});" | sed 's@-@_@g'
  echo "  }"
done
`

  return result ? result : input; 
}
END_OF_FILE
