#! /bin/sh

set -e 

for i in __SRCDIR__/in/__GRAMMAR__.[0-9].in; do
  base=`basename $i .in`
  tested=${base}.tested
  __FILTER__ __GRAMMAR_FLAGS__ -i $i | __IMPLODE__ -o ${tested}
  __ATDIFF__ __SRCDIR__/out/${base}.out ${tested}
done
