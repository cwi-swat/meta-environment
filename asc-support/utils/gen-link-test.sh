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

formals() {
  arity=$1
  type=$2

  for (( 0 ; ${arity} > 1 ; arity=`expr ${arity} - 1` )); do 
    printf "${type} arg${arity}, "
  done

  if [ $arity = 1 ]; then
    printf "${type} arg${arity}"
  fi
}

actuals() {
  arity=$1

  for (( 0 ; ${arity} > 1 ; arity=`expr ${arity} - 1` )); do 
    printf "NULL, "
  done

  if [ $arity = 1 ]; then
    printf "NULL"
  fi
}

cat  << END_OF_FILE 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <MEPT-utils.h>
#include <aterm2.h>
#include <asc-support2-me.h>

/* DO NOT EDIT: This file is generated */

`
for b in \${BUILTIN_NAMES}; do 
name=\`getName ${b}\`
arity=\`getArity ${b}\`
formals=\`formals ${arity} ATerm\`
echo "PT_Tree  ASFE_${name}(PT_Tree input);" | sed 's@-@_@g'
echo "PT_Tree  ASC_${name}(${formals});" | sed 's@-@_@g'
echo
done
`

/* This code is not meant for execution, 
 * it is used to test if there is an implementation for every built-in
 */
int main(void)
{
  if (fprintf(stderr, "This program does nothing\n") == 0) {
`
for b in \${BUILTIN_NAMES}; do
name=\`getName ${b}\`
arity=\`getArity ${b}\`
actuals=\`actuals ${arity} ATerm\`
echo "    ASFE_${name}(NULL);" | sed 's@-@_@g'
echo "    ASC_${name}(${actuals});" | sed 's@-@_@g'
echo
done
`
  }

  return 1; 
}

END_OF_FILE
