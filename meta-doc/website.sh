#! /bin/sh

set -e

CATEGORIES="getting-started howto demos understanding courses project"
WEB="./doc/html"
DOCBOOKXSL="/ufs/sen1/software/installed/docbook-xsl-1.71.0/html/docbook.xsl"
# DOCBOOKXSL="/home/paulk/software/source/docbook-xsl-1.71.0/html/docbook.xsl"

mkdir -p ${WEB} || true


getTitle() {
  DOCBOOK=$1
  TITLE=`grep "<title>" $DOCBOOK | head -1 | cut -d '>' -f 2 | cut -d '<' -f 1`
  echo ${TITLE}
}

INDEX="${WEB}/index.html"
echo "<html><head><title>" > ${INDEX}
echo " Online Documentation of The Meta-Environment" >> ${INDEX}
echo "</title></head><body>" >> ${INDEX}

for cat in ${CATEGORIES}; do
  echo "<h1>`cat $cat/TITLE`</h1><ul>" >> ${INDEX}
  BOOKS=`ls $cat`
  mkdir -p ${WEB}/$cat || true
  for book in ${BOOKS}; do
    if [ -d $cat/$book ]; then
      if [ ! -d ${WEB}/$cat/$book ]; then
         mkdir ${WEB}/$cat/$book
      fi
      cp $cat/$book/*.{png,jpg,gif} ${WEB}/$cat/$book >& /dev/null || true
      if [ -f $cat/$book/$book.xml ]; then
	(xsltproc  --output ${WEB}/$cat/$book/$book.html ${DOCBOOKXSL} $cat/$book/$book.xml)	
	title=`getTitle $cat/$book/$book.xml`
	echo "<li><a href=\"./$cat/$book/$book.html\">${title} (html)</a></li>" >> ${INDEX}
      elif [ -f $cat/$book/$book.pdf ]; then
	  mkdir -p ${WEB}/$cat/$book
	  cp $cat/$book/$book.pdf ${WEB}/$cat/$book/$book.pdf
	  title=`cat $cat/$book/TITLE`
	  echo "<li><a href=\"./$cat/$book/$book.pdf\">${title} (pdf)</a></li>" >> ${INDEX}
      elif [ -f $cat/$book/$book.url ]; then
	  title=`cat $cat/$book/TITLE`
	  url=`cat $cat/$book/$book.url`
	  echo "<li><a href=\"${url}\">${title}</a></li>" >> ${INDEX}
      fi
    fi
  done
  echo "</ul>" >> ${INDEX}
done

echo "</body></html>" >> ${INDEX}
