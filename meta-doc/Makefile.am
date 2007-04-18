include $(top_srcdir)/Makefile.top.meta

EXTRA_DIST +=  website.sh

ACLOCAL_AMFLAGS = -I .

EXTRA_DOC = books

books: dummy
	DOCBOOKXSLPREFIX=${DOCBOOK_XSL_PREFIX} \
	FOPPREFIX=${FOP_PREFIX} \
	${top_srcdir}/website.sh

dummy:
