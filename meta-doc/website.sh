#! /bin/sh

# Web site generator for Meta-Environment documentation.

# WARNING: the structure of the generated html directories should
# be compatible with the structure described in olinkdb.xml,
# otherwise incorrect cross-references will be generated between
# documents.


set -e

# CATEGORIES="learning-about howto understanding courses project"
CATEGORIES="getting-started syntax  extraction-transformation formatting analysis meta-environment technology software-development project"
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
  for obook in ${BOOKS}; do
    if [ $obook == TITLE ]; then
       continue
    fi
    book=`echo $obook | sed "s@^[0-9]*-@@"`
    echo --- processing $book ---
    if [ -d $cat/$obook ]; then
      mkdir -p ${WEB}/$cat/$obook
      cp $cat/$obook/*.{png,jpg,gif} ${WEB}/$cat/$obook >& /dev/null || true
      if [ -f $cat/$obook/$book.xml ]; then
	pubdate=`getPubdate ${cat}/${obook}/${book}.xml`
	svn log --xml ${cat}/${obook}/${book}.xml  | \
        xsltproc  --output ${WEB}/$cat/$obook/$book.log.html ./svnlog2html.xsl -
	(xsltproc --xinclude --stringparam now "${pubdate}"  ./pubdate.xsl $cat/$obook/$book.xml | \
	 xsltproc  --output ${WEB}/$cat/$obook/$book.html \
		   --xinclude \
                   --stringparam current.docid $book \
                   ./html-customization.xsl  -)
	(xsltproc  --xinclude --stringparam now "${pubdate}" ./pubdate.xsl $cat/$obook/$book.xml | \
	 xsltproc  --output ${WEB}/$cat/$obook/$book.fo \
                   --xinclude \
                   --stringparam current.docid $book \
                   ./fo-customization.xsl -)
        ${FOP} -fo ${WEB}/$cat/$obook/$book.fo -pdf ${WEB}/$cat/$obook/$book.pdf
        rm ${WEB}/$cat/$obook/$book.fo
        
	title=`getTitle $cat/$obook/$book.xml`

	echo "<li> ${title}" >> ${INDEX}
        echo "(<a href=\"./$cat/$obook/$book.html\">html</a>,"  >> ${INDEX}
	echo "<a href=\"./$cat/$obook/$book.pdf\">pdf</a>" >> ${INDEX}
	echo ",<a href=\"./$cat/$obook/$book.log.html\">changes</a>)" >> ${INDEX}
        echo "</li>" >> ${INDEX}

        cp ${STYLESHEET} ${WEB}/$cat/$obook/${STYLESHEET}
      elif [ -f $cat/$obook/$book.pdf ]; then
	  mkdir -p ${WEB}/$cat/$obook
	  cp $cat/$obook/$book.pdf ${WEB}/$cat/$obook/$book.pdf
	  title=`cat $cat/$obook/TITLE`
	  echo "<li>${title} (<a href=\"./$cat/$obook/$book.pdf\">pdf</a>)</li>" >> ${INDEX}
      elif [ -f $cat/$obook/$book.swf ]; then
          mkdir -p ${WEB}/$cat/$obook
          cp $cat/$obook/$book.swf ${WEB}/$cat/$book/$book.swf
          cp $cat/$obook/$book.htm ${WEB}/$cat/$book/$book.htm
          title=`cat $cat/$obook/TITLE`
          echo "<li>${title} (<a href=\"./$cat/$obook/$book.htm\">flash</a>)</li>" >> ${INDEX}
      elif [ -f $cat/$obook/$book.url ]; then
	  title=`cat $cat/$obook/TITLE`
	  url=`cat $cat/$obook/$book.url`
	  echo "<li><a href=\"${url}\">${title}</a></li>" >> ${INDEX}
      fi
    fi
  done
  echo "</ul>" >> ${INDEX}
done

echo "</body></html>" >> ${INDEX}
