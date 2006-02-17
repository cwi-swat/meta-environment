# $Id$

include ${top_srcdir}/make_rules

ACLOCAL_FLAGS = -I .

CLEANFILES = ${PACKAGE}-${VERSION}.pkg

SUBDIRS = lib src

EXTRA_DIST = reconf program-check.m4 make_rules package

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@


