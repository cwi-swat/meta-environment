# $Id$

include ${top_srcdir}/make_rules

ACLOCAL_FLAGS = -I .

CLEANFILES = ${PACKAGE}-${VERSION}.pkg

SUBDIRS = grammar sdf-checker src test removevarsyntax

EXTRA_DIST = reconf program-check.m4 make_rules package

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@


