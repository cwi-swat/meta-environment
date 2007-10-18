#! /bin/sh

set -e

CATEGORIES="learning-about howto understanding courses project"
WEB="./doc/html"
# FOPPREFIX="/home/paulk/software/source/fop-0.93"
DOCBOOKXSLPREFIX="/home/paulk/software/source/docbook-xsl-1.71.0"
FOP="${FOPPREFIX}/fop"
DOCBOOKXSLHTML=${DOCBOOKXSLPREFIX}/html/docbook.xsl
DOCBOOKXSLFO=${DOCBOOKXSLPREFIX}/fo/docbook.xsl
STYLESHEET="meta-doc-style.css"

	(xsltproc  --xinclude \
                   --output book.fo \
                   fo-customization.xsl \
                   complete-book.xml)
        ${FOP} -r -fo book.fo -pdf book.pdf

 
