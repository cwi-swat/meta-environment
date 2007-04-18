#! /bin/sh

set -e

CATEGORIES="learning-about howto understanding courses project"
WEB="./doc/html"
FOP="${FOPPREFIX}/fop"
DOCBOOKXSLHTML=${DOCBOOKXSLPREFIX}/html/docbook.xsl
DOCBOOKXSLFO=${DOCBOOKXSLPREFIX}/fo/docbook.xsl
STYLESHEET="meta-doc-style.css"

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

# Copy all logos to the website

mkdir -p ${WEB}/logos
cp logos/*.{png,gif} ${WEB}/logos

# Convert all books in all categories

for cat in ${CATEGORIES}; do
  cat $cat/TITLE  >> ${INDEX}
  echo "<ul>" >> ${INDEX}
  BOOKS=`ls $cat`
  mkdir -p ${WEB}/$cat || true
  for book in ${BOOKS}; do
    if [ -d $cat/$book ]; then
      mkdir -p ${WEB}/$cat/$book
      cp $cat/$book/*.{png,jpg,gif} ${WEB}/$cat/$book >& /dev/null || true
      if [ -f $cat/$book/$book.xml ]; then
	(xsltproc  --stringparam html.stylesheet ${STYLESHEET} \
                   --output ${WEB}/$cat/$book/$book.html \
                   ${DOCBOOKXSLHTML} $cat/$book/$book.xml)
	(xsltproc  --output ${WEB}/$cat/$book/$book.fo \
                   --stringparam paper.type A4 \
                   ${DOCBOOKXSLFO} $cat/$book/$book.xml)
        ${FOP} -fo ${WEB}/$cat/$book/$book.fo -pdf ${WEB}/$cat/$book/$book.pdf
        rm ${WEB}/$cat/$book/$book.fo
        
	title=`getTitle $cat/$book/$book.xml`

	echo "<li> ${title}" >> ${INDEX}
        echo "(<a href=\"./$cat/$book/$book.html\">html</a>,"  >> ${INDEX}
	echo "<a href=\"./$cat/$book/$book.pdf\">pdf</a>)" >> ${INDEX}
        echo "</li>" >> ${INDEX}

        cp ${STYLESHEET} ${WEB}/$cat/$book/${STYLESHEET}
      elif [ -f $cat/$book/$book.pdf ]; then
	  mkdir -p ${WEB}/$cat/$book
	  cp $cat/$book/$book.pdf ${WEB}/$cat/$book/$book.pdf
	  title=`cat $cat/$book/TITLE`
	  echo "<li>${title} (<a href=\"./$cat/$book/$book.pdf\">pdf</a>)</li>" >> ${INDEX}
      elif [ -f $cat/$book/$book.swf ]; then
          mkdir -p ${WEB}/$cat/$book
          cp $cat/$book/$book.swf ${WEB}/$cat/$book/$book.swf
          cp $cat/$book/$book.htm ${WEB}/$cat/$book/$book.htm
          title=`cat $cat/$book/TITLE`
          echo "<li>${title} (<a href=\"./$cat/$book/$book.htm\">flash</a>)</li>" >> ${INDEX}
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
