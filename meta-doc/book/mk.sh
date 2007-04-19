
#! /bin/sh

set -e

CATEGORIES="learning-about howto understanding courses project"
WEB="./doc/html"
FOPPREFIX="/home/paulk/software/source/fop-0.93"
DOCBOOKXSLPREFIX="/home/paulk/software/source/docbook-xsl-1.71.0"
FOP="${FOPPREFIX}/fop"
DOCBOOKXSLHTML=${DOCBOOKXSLPREFIX}/html/docbook.xsl
DOCBOOKXSLFO=${DOCBOOKXSLPREFIX}/fo/docbook.xsl
STYLESHEET="meta-doc-style.css"

	(xsltproc  --xinclude \
                   --param xref.with.number.and.title 0 \
                   --stringparam section.autolabel 1 \
                   --stringparam section.autolabel.max.depth 3 \
                   --stringparam section.label.includes.component 1 \
                   --output book.fo \
                   --stringparam paper.type A4 \
                   ${DOCBOOKXSLFO} book.xml)
        ${FOP} -fo book.fo -pdf book.pdf

 
