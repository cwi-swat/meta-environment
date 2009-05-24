include $(top_srcdir)/Makefile.top.meta

XSL_SOURCE_FILES = \
	html-customization.xsl.src \
	fo-customization.xsl.src \
        fo-complete-book-customization.xsl \
	common-customizations.xsl \
	pubdate.xsl \
	svnlog2html.xsl

GENERATED_XSL_FILES = html-customization.xsl fo-customization.xsl

ALL_XSL_FILES = ${XSL_SOURCE_FILES} ${GENERATED_XSL_FILES}

XML_SOURCE_FILES = olinkdb.xml.src

GENERATED_XML_FILES = olinkdb.xml

ALL_XML_FILES = ${XML_SOURCE_FILES} ${GENERATED_XML_FILES}

EXTRA_DIST +=  website.sh mk-complete-book.sh ${XSL_SOURCE_FILES} ${XML_SOURCE_FILES}

ACLOCAL_AMFLAGS = -I .

EXTRA_DOC = books

books:	Makefile ${ALL_XSL_FILES} ${ALL_XML_FILES}
	DOCBOOKXSLPREFIX=${DOCBOOK_XSL_PREFIX} \
	FOPPREFIX=${FOP_PREFIX} \
	${top_srcdir}/website.sh

complete-book:	Makefile ${ALL_XSL_FILES} ${ALL_XML_FILES}
	DOCBOOKXSLPREFIX=${DOCBOOK_XSL_PREFIX} \
	FOPPREFIX=${FOP_PREFIX} \
	${top_srcdir}/mk-complete-book.sh

%.xsl:	%.xsl.src Makefile
	sed "s@__PREFIX__@`pwd`@g; \
	     s@__DOCBOOKXSLPREFIX__@${DOCBOOK_XSL_PREFIX}@g;" \
	     < $< > $@

%.xml:	%.xml.src Makefile
	sed "s@__PREFIX__@`pwd`@g; \
	     s@__DOCBOOKXSLPREFIX__@${DOCBOOK_XSL_PREFIX}@g" \
	     < $< > $@

# convenience shortcut for creating pdf documentsp
%.pdf: %.xml Makefile
	(xsltproc  --xinclude --stringparam now "`date`" ./pubdate.xsl $< | \
          xsltproc  --output $*.fo \
                    --stringparam admon.graphics 1  \
                    --stringparam admon.textlabel 0  \
                    --xinclude --stringparam current.docid $* \
		                    ./fo-customization.xsl -)
	${FOP_PREFIX}/fop -fo $*.fo -pdf $@

