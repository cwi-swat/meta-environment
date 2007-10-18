#! /bin/sh

# Web site generator for Meta-Environment documentation.

# WARNING: the structure of the generated html directories should
# be compatible with the structure described in olinkdb.xml,
# otherwise incorrect cross-references will be generated between
# documents.


set -e

# CATEGORIES="learning-about howto understanding courses project"
CATEGORIES="learning-about"
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

getPubdate() {
  DOCBOOK=$1
  svn info ${DOCBOOK} | grep "Last Changed Date" | sed 's/^.*: //'
}

INDEX="${WEB}/index.html"
echo "<html><head><title>" > ${INDEX}
echo " Online Documentation of The Meta-Environment" >> ${INDEX}
echo "</title></head><body>" >> ${INDEX}

# Copy all logos to the website

mkdir -p ${WEB}/logos
cp logos/*.{png,gif} ${WEB}/logos


mkdir -p ${WEB}/images
mkdir -p ${WEB}/images/callouts
cp images/callouts/*.png $WEB/images/callouts

# Convert all books in all categories

for cat in ${CATEGORIES}; do
  cat $cat/TITLE  >> ${INDEX}
  echo "<ul>" >> ${INDEX}
  BOOKS=`ls $cat`
  mkdir -p ${WEB}/$cat || true
  for book in ${BOOKS}; do
    echo --- processing $book ---
    if [ -d $cat/$book ]; then
      mkdir -p ${WEB}/$cat/$book
      cp $cat/$book/*.{png,jpg,gif} ${WEB}/$cat/$book >& /dev/null || true
      if [ -f $cat/$book/$book.xml ]; then
	pubdate=`getPubdate ${cat}/${book}/${book}.xml`
	svn log --xml ${cat}/${book}/${book}.xml  | \
	xsltproc  --output ${WEB}/$cat/$book/$book.log.html ./svnlog2html.xsl -
	(xsltproc --xinclude --stringparam now "${pubdate}"  ./pubdate.xsl $cat/$book/$book.xml | \
	 xsltproc  --output ${WEB}/$cat/$book/$book.html \
		   --xinclude \
                   --stringparam current.docid $book \
                   ./html-customization.xsl  -)
	(xsltproc  --xinclude --stringparam now "${pubdate}" ./pubdate.xsl $cat/$book/$book.xml | \
	 xsltproc  --output ${WEB}/$cat/$book/$book.fo \
                   --xinclude \
                   --stringparam current.docid $book \
                   ./fo-customization.xsl -)
        ${FOP} -fo ${WEB}/$cat/$book/$book.fo -pdf ${WEB}/$cat/$book/$book.pdf
        rm ${WEB}/$cat/$book/$book.fo
        
	title=`getTitle $cat/$book/$book.xml`

	echo "<li> ${title}" >> ${INDEX}
        echo "(<a href=\"./$cat/$book/$book.html\">html</a>,"  >> ${INDEX}
	echo "<a href=\"./$cat/$book/$book.pdf\">pdf</a>" >> ${INDEX}
	echo ",<a href=\"./$cat/$book/$book.log.html\">changes</a>)" >> ${INDEX}
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
