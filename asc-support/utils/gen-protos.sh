#! /bin/sh
#
# $Id$
#
# This script generates an include file

BUILTIN_NAMES=$*

getName() {
  echo $1 | sed 's/\([a-z\-]*\)_\([0-9]*\)/\1/'
}

getArity() {
  echo $1 | sed 's/\([a-z\-]*\)_\([0-9]*\)/\2/'
}

getFormals() {
  arity=$1
  type=$2
  index=0

  if test ${arity} -ne 0; then
    printf ", "
  fi

  while test ${index} -lt ${arity}; do
    printf "${type} arg${index}"
    index=`expr ${index} + 1`
    if test ${index} -lt ${arity}; then
      printf ", "
    fi
  done

}

cat  << END_CAT
#ifndef BUILTINS_H
#define BUILTINS_H
#include <MEPT.h>

/* DO NOT EDIT. This file is generated */

void initBuiltins(void);
PT_Tree forwardBuiltin(ATerm builtin, PT_Tree input);
END_CAT

for b in ${BUILTIN_NAMES}; do 
  name=`getName ${b}`
  arity=`getArity ${b}`
  formals=`getFormals ${arity} PT_Tree`
  echo "PT_Tree ASFE_${name}(PT_Symbol type ${formals});" | sed 's@-@_@g'
  formals=`getFormals ${arity} ATerm`
  echo "PT_Tree ASC_${name}(ATerm type ${formals});" | sed 's@-@_@g'
  echo
done

echo "#endif"
