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
  if [ -r $cat/ENTRIES ]; then
     BOOKS=`cat $cat/ENTRIES`
  else
     BOOKS=`ls $cat`
  fi
  mkdir -p ${WEB}/$cat || true
  for obook in ${BOOKS}; do
    if [ $obook == TITLE ]; then
       continue
    fi
    # obook is an "ordered book", i.e., a book name possibly prefixed with a number (e.g., 2-syntax-analysis)
    # to force the order of presentation on the webpage.
    # book refers to the book name proper, with the prefix removed.
    book=`echo $obook | sed "s@^[0-9]*-@@"`
    echo --- processing $book ---
    if [ -d $cat/$obook ]; then
      mkdir -p ${WEB}/$cat/$obook
      cp $cat/$obook/*.{png,jpg,gif} ${WEB}/$cat/$obook >& /dev/null || true
      if [ -f $cat/$obook/$book.xml ]; then
      # It contains a DocBook file, generate HTML and PDF
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
        echo "(<a href=\"./$cat/$obook/$book.html\">html</a>, "  >> ${INDEX}
	echo "<a href=\"./$cat/$obook/$book.pdf\">pdf</a>, " >> ${INDEX}
	echo "<a href=\"./$cat/$obook/$book.log.html\">changes</a>)" >> ${INDEX}
        echo "</li>" >> ${INDEX}

        cp ${STYLESHEET} ${WEB}/$cat/$obook/${STYLESHEET}
      elif [ -f $cat/$obook/$book.odp ]; then
      # It contains an OpenOffice ODP file
	  mkdir -p ${WEB}/$cat/$obook
	  cp $cat/$obook/$book.odp ${WEB}/$cat/$obook/$book.odp
	  cp $cat/$obook/$book.pdf ${WEB}/$cat/$obook/$book.pdf
	  title=`cat $cat/$obook/TITLE`
	  echo "<li>[Slides] ${title} (<a href=\"./$cat/$obook/$book.pdf\">pdf</a>, " >> ${INDEX}
          echo "<a href=\"./$cat/$obook/$book.odp\">odp</a>)</li>" >> ${INDEX}
      elif [ -f $cat/$obook/$book.pdf ]; then
      # It contains only a PDF file
	  mkdir -p ${WEB}/$cat/$obook
	  cp $cat/$obook/$book.pdf ${WEB}/$cat/$obook/$book.pdf
	  title=`cat $cat/$obook/TITLE`
	  echo "<li>${title} (<a href=\"./$cat/$obook/$book.pdf\">pdf</a>)</li>" >> ${INDEX}
      elif [ -f $cat/$obook/$book.swf ]; then
      # It contains a Flash presentation
          mkdir -p ${WEB}/$cat/$obook
          cp $cat/$obook/$book.swf ${WEB}/$cat/$obook/$book.swf
          cp $cat/$obook/$book.htm ${WEB}/$cat/$obook/$book.htm
          title=`cat $cat/$obook/TITLE`
          echo "<li>${title} (<a href=\"./$cat/$obook/$book.htm\">flash</a>)</li>" >> ${INDEX}
      elif [ -f $cat/$obook/$book.url ]; then
      # It contains an URL
	  title=`cat $cat/$obook/TITLE`
	  url=`cat $cat/$obook/$book.url`
	  echo "<li><a href=\"${url}\">${title}</a></li>" >> ${INDEX}
      fi
    fi
  done
  echo "</ul>" >> ${INDEX}
done

echo "</body></html>" >> ${INDEX}
