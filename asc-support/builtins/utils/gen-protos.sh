#! /bin/sh
#
# $Id$
#
# This script generates an include file

BUILTIN_NAMES=$1

cat  << END_OF_FILE 
#ifndef BUILTINS_H
#define BUILTINS_H
#include <MEPT.h>

/* DO NOT EDIT. This file is generated */

void initBuiltins(void);
PT_Tree forwardBuiltin(ATerm builtin, PT_Tree input);

`
for b in \${BUILTIN_NAMES}; do 
  echo "PT_Tree ${b}(PT_Tree input);" | sed 's@-@_@g'
done
`

#endif
END_OF_FILE
