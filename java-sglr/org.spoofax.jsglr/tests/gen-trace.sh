#! /bin/sh

sglr -tvd -p grammars/$1.tbl -i data/$2
x=$(echo $2 | sed -r "s/(.*).(str|txt)/\1/")
grep Goto .sglr-log > sglr-trace-$x

