#! /bin/sh
#
# $Id$
#
# This script generates an include file

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

  while [ ${arity} > 1 ]; do
    printf "${type} arg${arity}, "
    arity=`expr ${arity} - 1`
  done

  if [ $arity = 1 ]; then
    printf "${type} arg${arity}"
  fi
}

cat  << END_OF_FILE 
#ifndef BUILTINS_H
#define BUILTINS_H
#include <MEPT.h>

/* DO NOT EDIT. This file is generated */

void initBuiltins(void);
PT_Tree forwardBuiltin(ATerm builtin, PT_Tree input);

`
for b in \${BUILTIN_NAMES}; do 
  name=\`getName ${b}\`
  arity=\`getArity ${b}\`
  formals=\`formals ${arity} ATerm\`
  echo "PT_Tree ASFE_${name}(PT_Tree input);" | sed 's@-@_@g'
  echo "PT_Tree ASC_${name}(${formals});" | sed 's@-@_@g'
  echo
done
`

#endif
END_OF_FILE
