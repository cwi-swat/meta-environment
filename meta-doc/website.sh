#! /bin/sh

set -x
set -e

CATEGORIES="demos howto courses project understanding"
WEB="./doc/html"

mkdir -p ${WEB} || true


getTitle() {
  DOCBOOK=$1
  TITLE=`grep "<title>" $DOCBOOK | head -1 | cut -d '>' -f 2 | cut -d '<' -f 1`
  echo ${TITLE}
}

for i in ${CATEGORIES}; do
  BOOKS=`ls $i`
  INDEX="${WEB}/$i/index.html"
  mkdir -p ${WEB}/$i || true
  echo "<html><body><ul>" > ${INDEX}
  for b in ${BOOKS}; do
    if [ -d $i/$b ]; then
      if [ -f $i/$b/$b.xml ]; then
	(docbook2html --output ${WEB}/$i/$b --nochunks $i/$b/$b.xml)	
	title=`getTitle $i/$b/$b.xml`
	echo "<li><a href=\"$i/$b/$b.html\">${title}</a></li>" >> ${INDEX}
      fi
    fi
  done
  echo "</ul></body></html>" >> ${INDEX}
done

