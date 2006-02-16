#! /bin/sh

LIMIT=5

for ((a=1; a <= LIMIT ; a++))
do
  echo "module a$a" > a$a.sdf
  for ((b=1; b< LIMIT ; b++))
  do
    echo -n "imports " >> a$a.sdf
    echo "a$b" >> a$a.sdf
  done
done
