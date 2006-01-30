# $Id$

ACLOCAL_FLAGS = -I .

include ${top_srcdir}/make_rules

EXTRA_DIST = make_rules package

CLEANFILES = \
	${PACKAGE}-${VERSION}.pkg

SUBDIRS = \
	src \
	in-output \
	term-store \
	tbscripts \
	editors

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@
