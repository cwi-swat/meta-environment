# $Id$

ACLOCAL_FLAGS = -I .

CLEANFILES = \
	${PACKAGE}-${VERSION}.pkg

EXTRA_DIST = package

SUBDIRS = \
	src \
	tbscripts \
	config

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@
