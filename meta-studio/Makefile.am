# $Id$

ACLOCAL_FLAGS = -I .

CLEANFILES = \
	${PACKAGE}-${VERSION}.pkg

SUBDIRS = \
	lib \
	util \
	studio

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@
