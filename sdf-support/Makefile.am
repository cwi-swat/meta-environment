# $Id$

SUBDIRS = lib utils test

ACLOCAL_FLAGS = -I .

EXTRA_DIST = make_rules package

CLEANFILES = ${PACKAGE}-${VERSION}.pkg

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@


