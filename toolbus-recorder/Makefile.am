# $Id$

ACLOCAL_FLAGS = -I .

CLEANFILES = \
	${PACKAGE}-${VERSION}.pkg

EXTRA_DIST = package

SUBDIRS = 

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@
