#! /bin/sh
#
# $Id$
#

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

getActuals() {
  arity=$1
  index=0

  if test ${arity} -ne 0; then
    printf ", "
  fi

  while test ${index} -lt ${arity}; do
    printf "NULL"
    index=`expr ${index} + 1`
    if test ${index} -lt ${arity}; then
      printf ", "
    fi
  done

}


cat  << END_CAT
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <MEPT-utils.h>
#include <aterm2.h>
#include <asc-support2-me.h>

/* DO NOT EDIT: This file is generated */

END_CAT

for b in ${BUILTIN_NAMES}; do 
name=`getName ${b}`
arity=`getArity ${b}`
forms=`getFormals ${arity} PT_Tree`
echo "PT_Tree  ASFE_${name}(PT_Symbol type ${forms});" | sed 's@-@_@g'
forms=`getFormals ${arity} ATerm`
echo "PT_Tree  ASC_${name}(ATerm type ${forms});" | sed 's@-@_@g'
echo
done

cat  << END_CAT
/* This code is not meant for execution, 
 * it is used to check if there is an implementation for every built-in
 */
int main(void)
{
  if (fprintf(stderr, "This program does nothing\n") == 0) {
END_CAT

for b in ${BUILTIN_NAMES}; do
name=`getName ${b}`
arity=`getArity ${b}`
acts=`getActuals ${arity} ATerm`
echo "    ASFE_${name}(NULL ${acts});" | sed 's@-@_@g'
echo "    ASC_${name}(NULL ${acts});" | sed 's@-@_@g'
echo
done

cat << END_CAT
  }

  return 0; 
}

END_CAT
