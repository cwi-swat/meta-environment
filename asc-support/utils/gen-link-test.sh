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
  ar=$1
  ty=$2

  while [ ${ar} != 1 ]; do
    printf "${ty} arg${ar}, "
    ar=`expr ${ar} - 1`
  done

  if [ $ar = 1 ]; then
    printf "${ty} arg${ar}"
  fi
}

getActuals() {
  ar=$1

  while [ ${ar} != 1 ]; do
    printf "NULL, "
    ar=`expr ${ar} - 1`
  done

  if [ $ar = 1 ]; then
    printf "NULL"
  fi
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
forms=`getFormals ${arity} ATerm`
echo "PT_Tree  ASFE_${name}(PT_Tree input);" | sed 's@-@_@g'
echo "PT_Tree  ASC_${name}(${forms});" | sed 's@-@_@g'
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
echo "    ASFE_${name}(NULL);" | sed 's@-@_@g'
echo "    ASC_${name}(${acts});" | sed 's@-@_@g'
echo
done

cat << END_CAT
  }

  return 0; 
}

END_CAT
