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

/* DO NOT EDIT: This file is generated */

`
for b in \${BUILTIN_NAMES}; do 
echo "PT_Tree  ${b}(ATerm tree, PT_Tree input);" | sed 's@-@_@g'
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
echo "    ${b}(NULL, NULL);" | sed 's@-@_@g'
done
`
  }

  return 1; 
}
END_OF_FILE
