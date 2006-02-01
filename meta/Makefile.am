# $Id$

ACLOCAL_FLAGS = -I .

EXTRA_DIST = package

CLEANFILES = \
	${PACKAGE}-${VERSION}.pkg

SUBDIRS = \
	src \
	tbscripts

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@
